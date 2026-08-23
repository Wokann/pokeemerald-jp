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

UNDEFINED_RE = re.compile(r"^\s*U\s+(\S+)\s*$")
ADDRESS_SUFFIX_RE = re.compile(r"_([0-9A-Fa-f]{6,8})$")


class VerificationError(ValueError):
    """A generated source range cannot be proven byte-exact."""


def _run(command: list[str], *, cwd: Path, description: str) -> subprocess.CompletedProcess:
    result = subprocess.run(command, cwd=cwd, capture_output=True, text=True, check=False)
    if result.returncode:
        detail = (result.stderr or result.stdout).strip()
        raise VerificationError(f"{description} failed: {detail}")
    return result


def _preprocess(source: Path, output: Path) -> None:
    result = _run(
        [str(PREPROC), str(source), str(ROOT / "charmap.txt")],
        cwd=ROOT,
        description="preproc",
    )
    output.write_text(result.stdout, encoding="utf-8")


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


def _external_label_addresses() -> dict[str, int]:
    return {name: address for address, name in emitter.event_script_labels().items()}


def _resolve_address(symbol: str, known: dict[str, int]) -> int | None:
    if symbol in known:
        return known[symbol]
    match = ADDRESS_SUFFIX_RE.search(symbol)
    if not match:
        return None
    value = int(match.group(1), 16)
    return value if value >= ROM_BASE else ROM_BASE + value


def _wrapper(source_path: Path, aliases: dict[str, int]) -> str:
    lines = [
        '.include "asm/macros.inc"',
        '.include "asm/macros/event.inc"',
        '.include "constants/constants.inc"',
        '.include "constants/map_scripts.inc"',
        '.include "constants/specials_constants.inc"',
    ]
    for name, address in sorted(aliases.items()):
        lines.append(f".set {name}, 0x{address:08X}")
    lines.extend((
        '.section script_data, "aw", %progbits',
        f'.include "{source_path}"',
        "",
    ))
    return "\n".join(lines)


def assemble_candidate(source: str, origin: int) -> bytes:
    """Return the temporary script_data bytes after resolving external labels."""
    for tool in (PREPROC, AS, NM, LD, OBJCOPY):
        if not tool.is_file():
            raise VerificationError(f"missing host tool: {tool}")
    known = _external_label_addresses()
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

        wrapper.write_text(_wrapper(map_source, {}), encoding="utf-8")
        _preprocess(wrapper, preprocessed)
        _assemble(preprocessed, object_path)
        unresolved = _undefined_symbols(object_path)
        aliases: dict[str, int] = {}
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

        wrapper.write_text(_wrapper(map_source, aliases), encoding="utf-8")
        _preprocess(wrapper, preprocessed)
        _assemble(preprocessed, object_path)
        remaining = _undefined_symbols(object_path)
        if remaining:
            raise VerificationError(
                "unresolved symbol(s) remain after aliasing: " + ", ".join(sorted(remaining))
            )
        linker_script.write_text(
            "SECTIONS\n{\n"
            f"  . = 0x{origin:08X};\n"
            "  script_data : { *(script_data) }\n"
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
        return binary.read_bytes()


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
    parser.add_argument("map_name", nargs="?", default="PetalburgCity")
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
    source = verify_map(args.map_name)
    if args.output is not None:
        args.output.parent.mkdir(parents=True, exist_ok=True)
        args.output.write_text(source, encoding="utf-8")
        print(f"wrote {args.output}")


if __name__ == "__main__":
    main()
