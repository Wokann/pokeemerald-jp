#!/usr/bin/env python3
"""Audit explicit text objects in the recursive EventScript include chain.

Only .string/.braille directives establish text, never script/movement names.
Addresses come from real label definitions and linked symbols/source anchors.
Uncovered or zero verified objects fail. Byte equality is not semantic review.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
import subprocess
import tempfile
from dataclasses import dataclass
from pathlib import Path

from jp_script_text import (
    EXT_CTRL_SPECS, JapaneseScriptTextCodec, TextDecodeError, TextRoundTripError,
    _extract_preproc_bytes,
)

ROOT = Path(__file__).resolve().parents[1]
ROM_BASE = 0x08000000
LABEL_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*):{1,2}\s*(?:@.*)?$")
ADDRESS_RE = re.compile(r"@\s*0x([0-9A-Fa-f]{7,8})\b")
INCLUDE_RE = re.compile(r'^\s*\.include\s+"([^"]+)"\s*(?:@.*)?$')
TEXT_RE = re.compile(r'^\s*\.(string|braille)\s+"((?:[^"\\]|\\.)*)"\s*(?:@.*)?$')
SYMBOL_RE = re.compile(r"^\s*(?:0x)?([0-9A-Fa-f]{8})\s+(?:[A-Za-z]\s+)?(\w+)\s*$")
CONDITION_RE = re.compile(r"^\s*(?:#if(?:def|ndef)?\b|\.if(?:def|ndef|eq|ne|gt|lt|ge|le)?\b)")
CONDITION_END_RE = re.compile(r"^\s*(?:#endif\b|\.endif\b)")
CONTROLS_WITH_ARGS = {name for name, argc in EXT_CTRL_SPECS.values() if argc}
CONTROLS_WITH_ARGS.add("DYNAMIC")


@dataclass(frozen=True)
class StringLine:
    line_number: int
    source: str
    path: str = ""
    kind: str = "string"


@dataclass(frozen=True)
class Label:
    name: str
    address: int | None
    path: str
    line: int


@dataclass(frozen=True)
class TextBlock:
    labels: tuple[Label, ...]
    strings: tuple[StringLine, ...]
    prelude: tuple[str, ...]
    conditional: bool


def implicit_control_arguments(strings: list[StringLine]) -> list[tuple[int, str]]:
    return [(entry.line_number, m.group(1)) for entry in strings
            for m in re.finditer(r"\{([A-Za-z_][A-Za-z0-9_]*)\}", entry.source)
            if m.group(1) in CONTROLS_WITH_ARGS]


def inline_line_controls(strings: list[StringLine]) -> list[tuple[int, str]]:
    # Braille is intentionally one directive with embedded row separators.
    return [(entry.line_number, "\\" + m.group(1)) for entry in strings
            if entry.kind == "string"
            for m in re.finditer(r"(?<!\\)(?:\\\\)*\\([nlp])(?=.)", entry.source)]


def elf_script_symbols(path: Path) -> dict[str, set[int]]:
    """Read local/global script_data definitions from the target's 32-bit LE ELF."""
    blob = path.read_bytes()
    if len(blob) < 52 or blob[:6] != b"\x7fELF\x01\x01":
        raise ValueError("expected a 32-bit little-endian ELF")
    h = struct.unpack_from("<16sHHIIIIIHHHHHH", blob)
    shoff, shsize, shnum, names_index = h[6], h[11], h[12], h[13]
    if shsize < 40 or not shnum or names_index >= shnum:
        raise ValueError("invalid ELF section table")

    def region(offset, size):
        if offset < 0 or size < 0 or offset + size > len(blob):
            raise ValueError("truncated ELF region")
        return blob[offset:offset + size]

    region(shoff, shsize * shnum)
    sections = [struct.unpack_from("<10I", blob, shoff + n * shsize) for n in range(shnum)]

    def section_bytes(s):
        return region(s[4], s[5])

    def name_at(table, offset):
        if offset >= len(table):
            raise ValueError("invalid ELF string offset")
        end = table.find(b"\0", offset)
        if end < 0:
            raise ValueError("unterminated ELF string")
        return table[offset:end].decode("utf-8")

    names = section_bytes(sections[names_index])
    script_indices = {i for i, s in enumerate(sections) if name_at(names, s[0]) == "script_data"}
    if not script_indices:
        raise ValueError("ELF has no script_data section")
    output: dict[str, set[int]] = {}
    for s in sections:
        if s[1] != 2:  # SHT_SYMTAB only
            continue
        if s[6] >= shnum or s[9] < 16 or s[5] % s[9]:
            raise ValueError("invalid ELF symbol table")
        table, strings = section_bytes(s), section_bytes(sections[s[6]])
        for offset in range(0, len(table), s[9]):
            name, address, _size, info, _other, index = struct.unpack_from("<IIIBBH", table, offset)
            if name and index in script_indices and (info & 0xF) not in (3, 4):
                output.setdefault(name_at(strings, name), set()).add(address)
    return output


def text_symbols(path: Path) -> dict[str, set[int]]:
    """Accept exact linker-map/nm address-name rows, not .set/assignment expressions."""
    output: dict[str, set[int]] = {}
    for line in path.read_text(encoding="utf-8").splitlines():
        m = SYMBOL_RE.fullmatch(line)
        if m:
            address = int(m.group(1), 16)
            if ROM_BASE <= address < 0x0A000000:
                output.setdefault(m.group(2), set()).add(address)
    return output


def discover_text(root: Path, entry: Path):
    """Flatten physical data includes; carry real labels into legacy child files."""
    blocks, findings, hashes = [], [], {}
    labels, strings, prelude = [], [], []
    conditional, depth = False, 0

    def flush():
        nonlocal labels, strings, prelude, conditional
        if strings:
            blocks.append(TextBlock(tuple(labels), tuple(strings), tuple(prelude), conditional))
        labels, strings, prelude, conditional = [], [], [], False

    def lines(path, stack):
        resolved = path.resolve()
        try:
            relative = resolved.relative_to(root).as_posix()
        except ValueError:
            findings.append({"path": str(path), "reason": "include escapes source root"})
            return
        if resolved in stack:
            findings.append({"path": relative, "reason": "recursive include cycle"})
            return
        try:
            content = resolved.read_bytes()
        except OSError as exc:
            findings.append({"path": relative, "reason": f"unreadable include: {exc.strerror}"})
            return
        hashes[relative] = hashlib.sha256(content).hexdigest()
        for number, text in enumerate(content.decode("utf-8").splitlines(), 1):
            include = INCLUDE_RE.fullmatch(text)
            if include:
                if include.group(1).startswith("data/"):
                    yield from lines(root / include.group(1), stack + (resolved,))
                continue
            yield relative, number, text

    for path, number, text in lines(entry, ()):
        stripped = text.strip()
        if not stripped or stripped.startswith("@"):
            continue
        if CONDITION_RE.match(text):
            depth += 1
            continue
        if CONDITION_END_RE.match(text):
            depth = max(0, depth - 1)
            continue
        label = LABEL_RE.fullmatch(text)
        if label:
            if strings or prelude:
                flush()
            annotation = ADDRESS_RE.search(text)
            labels.append(Label(label.group(1),
                                int(annotation.group(1), 16) if annotation else None,
                                path, number))
            continue
        directive = TEXT_RE.fullmatch(text)
        if directive:
            strings.append(StringLine(number, directive.group(2), path, directive.group(1)))
            conditional |= depth > 0
            continue
        if stripped.startswith((".globl ", ".global ", ".type ", ".size ", ".set ", ".equ ")):
            continue
        if strings:
            # Finish the explicit text run before padding/instructions. Do not
            # charge the next owner's bytes to the preceding text definition.
            # Any later text still needs its own label, so mixed/unanchored
            # bytes cannot silently disappear from the coverage denominator.
            flush()
        if stripped.startswith((".incbin", ".ascii", ".asciz", ".string", ".braille")):
            findings.append({"path": path, "line": number,
                             "reason": "unclassified raw/text directive", "source": stripped})
        prelude.append(stripped)
    flush()
    return blocks, findings, hashes


def resolve_address(labels, symbols):
    addresses = set()
    for label in labels:
        if label.address is not None:
            addresses.add(label.address)
        addresses.update(symbols.get(label.name, set()))
    if not addresses:
        raise ValueError("no linked symbol or source ROM address for text definition")
    if len(addresses) != 1:
        raise ValueError("conflicting/ambiguous definition addresses: " +
                         ", ".join(f"0x{x:08X}" for x in sorted(addresses)))
    return next(iter(addresses))


def braille_header(block):
    """brailleformat emits six explicit byte operands, in the listed order."""
    if not block.prelude:
        return b""
    if len(block.prelude) != 1 or not block.prelude[0].startswith("brailleformat "):
        raise ValueError("non-text bytes/instructions share the text label")
    if any(line.kind != "braille" for line in block.strings):
        raise ValueError("brailleformat cannot prefix ordinary .string text")
    operands = block.prelude[0].split(None, 1)[1].split("@", 1)[0].split(",")
    if len(operands) != 6 or any(not re.fullmatch(r"\s*(?:0x[0-9A-Fa-f]+|[0-9]+)\s*", x)
                                 for x in operands):
        raise ValueError("brailleformat needs six explicit byte operands")
    values = [int(x.strip(), 16 if x.strip().startswith("0x") else 10) for x in operands]
    if any(x > 255 for x in values):
        raise ValueError("brailleformat byte operand out of range")
    return bytes(values)


def validate_brailleformat(root):
    """Do not assume the selected tree's macro still emits six bytes in order."""
    path = root / "asm/macros/event.inc"
    source = path.read_text(encoding="utf-8")
    macro = re.search(r"^\s*\.macro\s+brailleformat([^\n]*)\n(.*?)^\s*\.endm\s*$",
                      source, re.M | re.S)
    if macro is None:
        raise ValueError("missing brailleformat emission contract")
    parameters = [value.strip() for value in macro.group(1).split(",")]
    if len(parameters) != 6 or any(not re.fullmatch(r"\w+:req", x) for x in parameters):
        raise ValueError("unverified brailleformat parameter contract")
    expected = [".byte \\" + parameter[:-4] for parameter in parameters]
    actual = [line.split("@", 1)[0].strip() for line in macro.group(2).splitlines()
              if line.split("@", 1)[0].strip()]
    if actual != expected:
        raise ValueError("unverified brailleformat byte-emission order")
    return hashlib.sha256(path.read_bytes()).hexdigest()


def source_encoder(root):
    """Use the selected target tree's actual preproc/charmap, not this tool's root."""
    preproc, charmap = root / "tools/preproc/preproc", root / "charmap.txt"
    cache = {}

    def encode(kind, source):
        key = kind, source
        if key not in cache:
            if not preproc.is_file():
                raise TextRoundTripError(f"missing matching preproc: {preproc}")
            with tempfile.TemporaryDirectory() as directory:
                path = Path(directory) / "text.s"
                path.write_text(f'\t.{kind} "{source}"\n', encoding="utf-8")
                result = subprocess.run([str(preproc), str(path), str(charmap)],
                                        capture_output=True, text=True, check=False)
            if result.returncode:
                raise TextRoundTripError("preproc rejected source: " + result.stderr.strip())
            cache[key] = _extract_preproc_bytes(result.stdout)
        return cache[key]
    return encode


def build_report(root, entry=None, *, symbols=None, encoder=None, codec=None,
                 elf_path=None, symbol_path=None):
    root = root.resolve()
    blocks, findings, hashes = discover_text(root, entry or root / "data/event_scripts.s")
    symbol_inputs = {}
    if symbols is None:
        symbols = {}
        inputs = [(elf_path or root / "pokeemerald_jp.elf", elf_script_symbols),
                  (symbol_path or root / "pokeemerald_jp.map", text_symbols)]
        for path, reader in inputs:
            if not path.is_file():
                if path in (elf_path, symbol_path):
                    findings.append({"path": str(path), "reason": "requested symbol input is missing"})
                continue
            try:
                for name, addresses in reader(path).items():
                    symbols.setdefault(name, set()).update(addresses)
                symbol_inputs[path.name] = hashlib.sha256(path.read_bytes()).hexdigest()
            except (ValueError, OSError, struct.error, UnicodeError) as exc:
                findings.append({"path": path.name, "reason": f"invalid symbol input: {exc}"})
    rom = (root / "baserom_jp.gba").read_bytes()
    encoder = encoder or source_encoder(root)
    codec = codec or JapaneseScriptTextCodec(root / "charmap.txt")
    objects, implicit, inline = [], [], []
    covered_blocks = 0
    braille_contract = None
    for block in blocks:
        first = block.strings[0]
        context = {"path": first.path, "line": first.line_number,
                   "label": block.labels[-1].name if block.labels else None}
        for line in block.strings:
            implicit.extend({**context, "path": line.path, "line": n, "control": c}
                            for n, c in implicit_control_arguments([line]))
            inline.extend({**context, "path": line.path, "line": n, "control": c}
                          for n, c in inline_line_controls([line]))
        try:
            if block.conditional:
                raise ValueError("text in an unselected conditional branch")
            if not block.labels:
                raise ValueError("text has no actual label definition")
            address = resolve_address(block.labels, symbols)
            prefix = braille_header(block)
            if prefix and braille_contract is None:
                braille_contract = validate_brailleformat(root)
            kinds = {line.kind for line in block.strings}
            if len(kinds) != 1:
                raise ValueError("mixed ordinary and braille directives")
            kind = next(iter(kinds))
            raw = b"".join(encoder(line.kind, line.source) for line in block.strings)
            parts, position = [], 0
            while position < len(raw):
                if kind == "string":
                    size = codec.decode_one(raw[position:]).consumed
                else:
                    eos = raw.find(b"\xFF", position)
                    if eos < 0:
                        raise ValueError("unterminated braille object")
                    if any(v > 0x3F and v != 0xFE for v in raw[position:eos]):
                        raise ValueError("unverified braille payload byte")
                    size = eos + 1 - position
                parts.append(raw[position:position + size])
                position += size
            if not parts:
                raise ValueError("text encoded no EOS-terminated objects")
            offset = address - ROM_BASE
            if offset < 0 or offset + len(prefix) + len(raw) > len(rom):
                raise ValueError("text span is outside the supplied ROM")
            for index, part in enumerate(parts, 1):
                encoded = (prefix if index == 1 else b"") + part
                expected = rom[offset:offset + len(encoded)]
                record = {**context, "object": index, "kind": kind,
                          "start": ROM_BASE + offset, "end": ROM_BASE + offset + len(encoded),
                          "size": len(encoded), "sha256": hashlib.sha256(encoded).hexdigest(),
                          "status": "byte_exact" if expected == encoded else "mismatch"}
                objects.append(record)
                if expected != encoded:
                    findings.append({**record, "reason": "ROM/source byte mismatch"})
                offset += len(encoded)
            covered_blocks += 1
        except (ValueError, TextDecodeError, TextRoundTripError, OSError) as exc:
            findings.append({**context, "reason": str(exc), "category": "uncovered_text"})
    verified = sum(x["status"] == "byte_exact" for x in objects)
    if not verified:
        findings.append({"reason": "zero verified text objects; this is not a passing audit",
                         "category": "zero_coverage"})
    return {
        "scope": "explicit recursive EventScript text byte/encoding coverage; not semantic review",
        "semantic_review": "not_recorded",
        "inputs": {"source_sha256": dict(sorted(hashes.items())),
                   "symbol_sha256": dict(sorted(symbol_inputs.items())),
                   "rom_sha256": hashlib.sha256(rom).hexdigest(),
                   "charmap_sha256": hashlib.sha256((root / "charmap.txt").read_bytes()).hexdigest(),
                   "preproc_sha256": (hashlib.sha256((root / "tools/preproc/preproc").read_bytes()).hexdigest()
                                      if (root / "tools/preproc/preproc").is_file() else None),
                   "brailleformat_source_sha256": braille_contract},
        "summary": {"source_files": len(hashes), "text_blocks": len(blocks),
                    "text_directives": sum(len(x.strings) for x in blocks),
                    "covered_blocks": covered_blocks, "verified_objects": verified,
                    "mismatched_objects": len(objects) - verified,
                    "uncovered_blocks": len(blocks) - covered_blocks,
                    "coverage_errors": len(findings), "implicit_control_arguments": len(implicit),
                    "inline_line_controls": len(inline)},
        "objects": objects, "findings": findings,
        "implicit_controls": implicit, "inline_controls": inline,
    }


def report_failed(report, strict_control_syntax=False, strict_layout=False):
    summary = report["summary"]
    return bool(summary["coverage_errors"] or not summary["verified_objects"]
                or (strict_control_syntax and summary["implicit_control_arguments"])
                or (strict_layout and summary["inline_line_controls"]))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT, help="target JP source/build tree")
    parser.add_argument("--elf", type=Path, help="linked JP ELF with local text symbols")
    parser.add_argument("--symbols", type=Path, help="exact nm/linker-map symbol rows")
    parser.add_argument("--json", action="store_true", help="complete deterministic report")
    parser.add_argument("--verbose", action="store_true", help="show every audited text object")
    parser.add_argument("--strict-control-syntax", action="store_true",
                        help="also fail controls with arguments outside braces")
    parser.add_argument("--strict-layout", action="store_true",
                        help="also fail text after inline line/page controls")
    args = parser.parse_args()
    try:
        report = build_report(args.root, elf_path=args.elf, symbol_path=args.symbols)
    except (OSError, ValueError, UnicodeError) as exc:
        parser.exit(2, f"audit_script_text_sources: {exc}\n")
    if args.json:
        print(json.dumps(report, ensure_ascii=False, indent=2, sort_keys=True))
    else:
        for key, value in report["summary"].items():
            print(f"{key}: {value}")
        print(report["scope"])
        if args.verbose:
            for x in report["objects"]:
                print(f"{x['status'].upper()} {x['path']}:{x['line']} {x['label']}#{x['object']} "
                      f"[0x{x['start']:08X},0x{x['end']:08X})")
        for x in report["findings"][:30]:
            print(f"ERROR {x.get('path', '')}:{x.get('line', '')}: {x['reason']}")
        for group in ("implicit_controls", "inline_controls"):
            for x in report[group][:20]:
                print(f"{group.upper()} {x['path']}:{x['line']}: {x['control']}")
    return int(report_failed(report, args.strict_control_syntax, args.strict_layout))


if __name__ == "__main__":
    raise SystemExit(main())
