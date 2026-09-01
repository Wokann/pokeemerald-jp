#!/usr/bin/env python3
"""Assemble generated map-script candidates and compare their exact ROM slices.

This is a read-only gate for ``jp_emit_maps.py``.  It does not overwrite a
tracked ``data/maps/<Map>/scripts.inc`` file.  External script/text labels are
resolved to their known ROM addresses only for the temporary object, allowing
the emitted map-owned bytes to be compared byte-for-byte with baserom_jp.gba.
"""

from __future__ import annotations

import argparse
import re
import shutil
import subprocess
import tempfile
from functools import lru_cache
from pathlib import Path

import jp_emit_maps as emitter


ROOT = Path(__file__).resolve().parents[1]
ROM_BASE = 0x08000000
PREPROC = ROOT / "tools" / "preproc" / "preproc"
AS = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-as"
NM = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-nm"
LD = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-ld"
OBJCOPY = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-objcopy"
CPP = "cpp"

UNDEFINED_RE = re.compile(r"^\s*U\s+(\S+)\s*$")
ADDRESS_SUFFIX_RE = re.compile(r"_([0-9A-Fa-f]{6,8})$")


class VerificationError(ValueError):
    """A generated source range cannot be proven byte-exact."""


def _run(
    command: list[str],
    *,
    cwd: Path,
    description: str,
    input_text: str | None = None,
) -> subprocess.CompletedProcess:
    result = subprocess.run(
        command,
        cwd=cwd,
        input=input_text,
        capture_output=True,
        text=True,
        check=False,
    )
    if result.returncode:
        detail = (result.stderr or result.stdout).strip()
        raise VerificationError(f"{description} failed: {detail}")
    return result


def _preprocess(source: Path, output: Path) -> None:
    expanded = _run(
        [str(PREPROC), str(source), str(ROOT / "charmap.txt")],
        cwd=ROOT,
        description="preproc",
    )
    cpp = _run(
        [
            CPP,
            "-iquote",
            "include",
            "-Wno-trigraphs",
            "-I",
            "tools/agbcc/include",
            "-I",
            "tools/agbcc",
            "-nostdinc",
            "-undef",
            "-std=gnu89",
            "-",
        ],
        cwd=ROOT,
        description="C preprocessor",
        input_text=expanded.stdout,
    )
    encoded = _run(
        [str(PREPROC), "-ie", str(source), str(ROOT / "charmap.txt")],
        cwd=ROOT,
        description="post-cpp preproc",
        input_text=cpp.stdout,
    )
    output.write_text(encoded.stdout, encoding="utf-8")


def _assemble(source: Path, object_path: Path) -> None:
    _run(
        [str(AS), "-mcpu=arm7tdmi", "-o", str(object_path), str(source)],
        cwd=ROOT,
        description="assembler",
    )


def _undefined_symbols(object_path: Path) -> set[str]:
    result = _run([str(NM), "-u", str(object_path)], cwd=ROOT, description="nm")
    names = set()
    for line in result.stdout.splitlines():
        match = UNDEFINED_RE.match(line)
        if match:
            names.add(match.group(1))
    return names


def _tm_hm_item_aliases() -> dict[str, int]:
    """Return the semantic TM/HM item aliases used by map-script sources."""
    item_values = {}
    item_header = ROOT / "include" / "constants" / "items.h"
    for match in re.finditer(
        r"^#define\s+(ITEM_(?:TM|HM)\d\d)\s+(\d+)\s*$",
        item_header.read_text(encoding="utf-8"),
        re.MULTILINE,
    ):
        item_values[match.group(1)] = int(match.group(2))

    aliases = {}
    names_header = (ROOT / "include" / "constants" / "tms_hms.h").read_text(
        encoding="utf-8"
    )
    for kind, count in (("TM", 50), ("HM", 8)):
        block = re.search(
            rf"#define FOREACH_{kind}\(F\) \\\n(?P<body>.*?)(?=\n\n#define|\n\n#endif)",
            names_header,
            re.DOTALL,
        )
        if block is None:
            raise VerificationError(f"missing FOREACH_{kind} in tms_hms.h")
        names = re.findall(r"F\((\w+)\)", block.group("body"))
        if len(names) != count:
            raise VerificationError(
                f"FOREACH_{kind} has {len(names)} entries, expected {count}"
            )
        for index, name in enumerate(names, 1):
            aliases[f"ITEM_{kind}_{name}"] = item_values[f"ITEM_{kind}{index:02d}"]
    return aliases


def _compile_time_aliases() -> dict[str, int]:
    """Return non-ROM symbols needed before an isolated map can assemble.

    The production event-script object defines these through its shared
    preamble.  An isolated candidate has to know them on the first assembly
    pass too: macros such as ``setvar`` evaluate their operands in GAS
    conditionals before unresolved-symbol recovery can run.
    """
    aliases = {
        "STR_VAR_1": 0,
        "STR_VAR_2": 1,
        "STR_VAR_3": 2,
    }
    special_indices = {}
    for index, (name, waitstate) in emitter.sp.SPECIALS.items():
        special_indices[name] = (index, waitstate)
        aliases[f"SPECIAL_{name}"] = index
        aliases[f"SPECIAL_WAITSTATE_{name}"] = waitstate
    # Map owners may use a reviewed upstream spelling while the shared JP
    # special table deliberately retains an address-style name for legacy
    # callers. Mirror those production aliases in isolated verification.
    for semantic in emitter.MAP_VERIFIED_SEMANTIC_LABELS.values():
        for raw_name, alias_name in semantic.get("specials", {}).items():
            entry = special_indices.get(raw_name)
            if entry is None:
                continue
            index, waitstate = entry
            aliases.setdefault(f"SPECIAL_{alias_name}", index)
            aliases.setdefault(f"SPECIAL_WAITSTATE_{alias_name}", waitstate)
    aliases.update(_tm_hm_item_aliases())
    return aliases


@lru_cache(maxsize=None)
def _linked_elf_symbol_addresses(
    elf_path: Path | None = None,
) -> dict[str, frozenset[int]]:
    """Read exact local and global ROM symbols from the linked JP ELF.

    The textual linker map records global labels only, while text owners often
    deliberately keep their labels local.  ``nm`` on the final JP ELF exposes
    both kinds.  Keep all addresses until a caller asks for a specific name:
    unrelated local-label collisions must not invalidate an isolated map.
    """
    elf_path = elf_path or ROOT / "pokeemerald_jp.elf"
    if not elf_path.is_file() or not NM.is_file():
        return {}
    result = _run([str(NM), "-n", str(elf_path)], cwd=ROOT, description="linked nm")
    symbols: dict[str, set[int]] = {}
    for line in result.stdout.splitlines():
        match = re.match(
            r"^([0-9A-Fa-f]{8})\s+\S\s+([A-Za-z_][A-Za-z0-9_]*)$", line
        )
        if match is None:
            continue
        address, name = int(match.group(1), 16), match.group(2)
        if ROM_BASE <= address < 0x0A000000:
            symbols.setdefault(name, set()).add(address)
    return {name: frozenset(addresses) for name, addresses in symbols.items()}


@lru_cache(maxsize=None)
def _linked_symbol_addresses(map_path: Path | None = None) -> dict[str, int]:
    """Read global ROM addresses from the locally linked JP symbol map.

    This is a fallback for environments where only the map is available. Do
    not infer addresses from spelling, text, or a US counterpart. Repeated
    identical entries are harmless, but a global symbol at two ROM addresses
    makes the candidate unverifiable.
    """
    map_path = map_path or ROOT / "pokeemerald_jp.map"
    if not map_path.is_file():
        return {}
    symbols: dict[str, int] = {}
    for line in map_path.read_text(encoding="utf-8", errors="replace").splitlines():
        match = re.match(
            r"^\s*0x(08[0-9A-Fa-f]{6})\s+([A-Za-z_][A-Za-z0-9_]*)\s*$", line
        )
        if match is None:
            continue
        address, name = int(match.group(1), 16), match.group(2)
        previous = symbols.get(name)
        if previous is not None and previous != address:
            raise VerificationError(
                f"linked symbol {name} has conflicting addresses "
                f"0x{previous:08X} and 0x{address:08X}"
            )
        symbols[name] = address
    return symbols


def _external_label_addresses() -> dict[str, int]:
    # One ROM address may deliberately retain both a legacy gJPText alias and
    # a reviewed semantic label.  The temporary verifier must know every
    # alias, not merely the primary display name used by map emission.
    labels = emitter.event_script_symbol_addresses()
    # These semantic opcode aliases are defined in data/event_scripts.s rather
    # than in the preprocessor headers included by this isolated map wrapper.
    # Keep the complete reviewed set available so a generated map can use the
    # same upstream macro spelling as the production event-script object.
    labels.update(_compile_time_aliases())
    return labels


def _resolve_address(symbol: str, known: dict[str, int]) -> int | None:
    if symbol in known:
        return known[symbol]
    # Consult the linked JP ELF only for a symbol the reviewed-source index
    # could not resolve. This preserves source aliases and admits text labels
    # whose physical owner intentionally kept them local.
    linked_elf = _linked_elf_symbol_addresses().get(symbol)
    if linked_elf:
        if len(linked_elf) != 1:
            addresses = ", ".join(f"0x{address:08X}" for address in sorted(linked_elf))
            raise VerificationError(
                f"linked ELF symbol {symbol} has conflicting addresses {addresses}"
            )
        return next(iter(linked_elf))
    # Fall back to the global-symbol map only when no linked ELF label exists.
    linked_map = _linked_symbol_addresses().get(symbol)
    if linked_map is not None:
        return linked_map
    match = ADDRESS_SUFFIX_RE.search(symbol)
    if not match:
        return None
    value = int(match.group(1), 16)
    return value if value >= ROM_BASE else ROM_BASE + value


def _wrapper(source_path: Path, aliases: dict[str, int], prefix: int = 0) -> str:
    event_script_source = ROOT / "data" / "event_scripts.s"
    cpp_headers = []
    for line in event_script_source.read_text(encoding="utf-8").splitlines():
        if line.startswith("#include "):
            cpp_headers.append(line)
        elif cpp_headers and line.strip():
            break
    if not cpp_headers:
        raise VerificationError(f"missing C constant includes in {event_script_source}")
    lines = cpp_headers + [
        '.include "asm/macros.inc"',
        '.include "asm/macros/event.inc"',
        '.include "constants/gba_constants.inc"',
        '.include "constants/global.inc"',
    ]
    for name, address in sorted(aliases.items()):
        lines.append(f".set {name}, 0x{address:08X}")
    lines.append('.section script_data, "aw", %progbits')
    if prefix:
        lines.append(f'.space {prefix}')
    lines.extend((f'.include "{source_path}"', ""))
    return "\n".join(lines)


def assemble_candidate(source: str, origin: int) -> bytes:
    """Return the temporary script_data bytes after resolving external labels."""
    for tool in (PREPROC, AS, NM, LD, OBJCOPY):
        if not tool.is_file():
            raise VerificationError(f"missing host tool: {tool}")
    if shutil.which(CPP) is None:
        raise VerificationError(f"missing host tool: {CPP}")
    known = _external_label_addresses()
    # Map tables can begin at an unaligned ROM address, while an emitted map
    # may later contain .align directives. Prefix the temporary section so
    # its local alignment arithmetic has the same modulo-16 origin as ROM,
    # then strip that synthetic prefix from the comparison bytes.
    prefix = origin & 0xF
    section_origin = origin - prefix
    with tempfile.TemporaryDirectory(prefix="jp-map-script-") as directory:
        tempdir = Path(directory)
        map_source = tempdir / "map_scripts.inc"
        map_source.write_text(source, encoding="utf-8")
        wrapper = tempdir / "wrapper.s"
        preprocessed = tempdir / "wrapper.pre.s"
        object_path = tempdir / "map.o"
        linker_script = tempdir / "map.ld"
        linked = tempdir / "map.elf"
        binary = tempdir / "map.bin"

        aliases = _compile_time_aliases()
        wrapper.write_text(_wrapper(map_source, aliases, prefix), encoding="utf-8")
        _preprocess(wrapper, preprocessed)
        _assemble(preprocessed, object_path)
        unresolved = _undefined_symbols(object_path)
        unknown: list[str] = []
        for symbol in unresolved:
            address = _resolve_address(symbol, known)
            if address is None:
                unknown.append(symbol)
            else:
                aliases[symbol] = address
        if unknown:
            raise VerificationError(
                "cannot infer ROM address for external symbol(s): " + ", ".join(sorted(unknown))
            )

        wrapper.write_text(_wrapper(map_source, aliases, prefix), encoding="utf-8")
        _preprocess(wrapper, preprocessed)
        _assemble(preprocessed, object_path)
        remaining = _undefined_symbols(object_path)
        if remaining:
            raise VerificationError(
                "unresolved symbol(s) remain after aliasing: " + ", ".join(sorted(remaining))
            )
        linker_script.write_text(
            "SECTIONS\n{\n"
            f"  script_data 0x{section_origin:08X} : {{ *(script_data) }}\n"
            "}\n",
            encoding="utf-8",
        )
        _run(
            [str(LD), "-T", str(linker_script), "-o", str(linked), str(object_path)],
            cwd=ROOT,
            description="linker",
        )
        _run(
            [str(OBJCOPY), "-O", "binary", "--only-section=script_data", str(linked), str(binary)],
            cwd=ROOT,
            description="objcopy",
        )
        result = binary.read_bytes()
        if result[:prefix] != b'\0' * prefix:
            raise VerificationError("temporary map prefix is not zero-filled")
        return result[prefix:]


@lru_cache(maxsize=1)
def shared_context():
    entries = tuple(emitter.map_entries(include_empty=True))
    labels = emitter.event_script_labels()
    map_starts = {entry[0] for entry in entries}
    nonmap = sorted(address for address in labels if address not in map_starts)
    last_map_end = next((address for address in nonmap if address > entries[-1][0]), 0x0828F000)
    global_text_ptrs = emitter.collect_all_text_ptrs(entries)
    text_label_map = {pointer: f"gJPText_{pointer & 0xFFFFFF:08X}" for pointer in global_text_ptrs}
    return entries, labels, last_map_end, global_text_ptrs, text_label_map


def region_end(entries, selected, last_map_end):
    start = entries[selected][0]
    next_index = selected + 1
    while next_index < len(entries) and entries[next_index][0] == start:
        next_index += 1
    return entries[next_index][0] if next_index < len(entries) else last_map_end


def map_context(map_name: str) -> tuple[int, int, str, int, int]:
    """Return (start, end, generated source, text count, raw segment count)."""
    entries, labels, last_map_end, global_text_ptrs, text_label_map = shared_context()
    selected = next((index for index, entry in enumerate(entries) if entry[1] == map_name), None)
    if selected is None:
        raise VerificationError(f"unknown map name: {map_name}")
    ms, mname, group, map_num, table_entries, events_addr = entries[selected]
    if selected > 0 and entries[selected - 1][0] == ms:
        raise VerificationError(
            f"{mname} shares map-script table 0x{ms:08X} with {entries[selected - 1][1]}; "
            "verify the first owner instead"
        )

    end = region_end(entries, selected, last_map_end)
    region_labels = {address: name for address, name in labels.items() if ms <= address < end}
    source, text_count, raw_count = emitter.emit_map(
        ms,
        mname,
        group,
        map_num,
        table_entries,
        end,
        global_text_ptrs,
        text_label_map,
        region_labels,
        set(),
        events_addr,
    )
    return ms, end, source, text_count, raw_count


def first_difference(actual: bytes, expected: bytes) -> int | None:
    for offset, (left, right) in enumerate(zip(actual, expected)):
        if left != right:
            return offset
    if len(actual) != len(expected):
        return min(len(actual), len(expected))
    return None


def verify_map(map_name: str, *, verbose: bool = True) -> str:
    start, end, source, text_count, raw_count = map_context(map_name)
    actual = assemble_candidate(source, start)
    expected = emitter.ROM[start - ROM_BASE : end - ROM_BASE]
    diff = first_difference(actual, expected)
    if diff is not None:
        raise VerificationError(
            f"{map_name} mismatch at +0x{diff:X} (0x{start + diff:08X}); "
            f"generated={actual[diff:diff + 16].hex()} rom={expected[diff:diff + 16].hex()} "
            f"lengths={len(actual):#x}/{len(expected):#x}"
        )
    if verbose:
        print(
            f"PASS {map_name}: 0x{start:08X}-0x{end:08X} "
            f"({len(actual):#x} bytes, text={text_count}, raw={raw_count})"
        )
    return source


def empty_owner_names(max_size: int | None) -> list[str]:
    entries, _labels, last_map_end, _text_ptrs, _text_labels = shared_context()
    names = []
    for index, (start, name, _group, _map_num, table_entries, _events) in enumerate(entries):
        if index and entries[index - 1][0] == start:
            continue
        if table_entries:
            continue
        end = region_end(entries, index, last_map_end)
        if max_size is not None and end - start > max_size:
            continue
        names.append(name)
    return names


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "map_names",
        nargs="*",
        help="one or more map owners to verify (defaults to PetalburgCity)",
    )
    parser.add_argument(
        "--all-empty",
        action="store_true",
        help="verify every first-owner map table that only contains the zero terminator",
    )
    parser.add_argument(
        "--max-size",
        type=lambda value: int(value, 0),
        help="with --all-empty, skip regions larger than this ROM-byte size",
    )
    parser.add_argument("--verbose", action="store_true", help="print every result in batch mode")
    parser.add_argument(
        "--output",
        type=Path,
        help="write the verified candidate to this non-tracked path",
    )
    args = parser.parse_args()
    if args.all_empty:
        if args.map_names:
            raise SystemExit("map names cannot be used with --all-empty")
        if args.output is not None:
            raise SystemExit("--output cannot be used with --all-empty")
        names = empty_owner_names(args.max_size)
        failures = []
        for name in names:
            try:
                verify_map(name, verbose=args.verbose)
            except VerificationError as error:
                failures.append((name, str(error)))
        print(f"empty map owners checked: {len(names)}")
        print(f"empty map owners passed: {len(names) - len(failures)}")
        print(f"empty map owners failed: {len(failures)}")
        for name, error in failures[:20]:
            print(f"FAIL {name}: {error}")
        if failures:
            raise SystemExit(1)
        return

    names = args.map_names or ["PetalburgCity"]
    if args.output is not None and len(names) != 1:
        raise SystemExit("--output can only be used with one map name")

    sources = []
    failures = []
    for name in names:
        try:
            sources.append((name, verify_map(name, verbose=True)))
        except VerificationError as error:
            failures.append((name, str(error)))
    if failures:
        for name, error in failures:
            print(f"FAIL {name}: {error}")
        raise SystemExit(1)

    if args.output is not None:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(sources[0][1], encoding="utf-8")
        print(f"wrote {args.output}")


if __name__ == "__main__":
    main()
