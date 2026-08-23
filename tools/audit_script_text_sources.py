#!/usr/bin/env python3
"""Audit pure .string event-script includes against baserom_jp.gba.

The script intentionally audits only an include whose body is entirely
``.string`` directives.  Mixed script/data files need an address-aware parser
before they can be judged safely.  For every eligible include it checks the
actual ROM bytes at the owning label and separately reports controls whose
required argument was written outside the brace group (for example
``{PAUSE}そ`` instead of ``{PAUSE 0x0F}``).
"""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass
from pathlib import Path

from jp_script_text import (
    EXT_CTRL_SPECS,
    JapaneseScriptTextCodec,
    TextDecodeError,
    TextRoundTripError,
)


ROOT = Path(__file__).resolve().parents[1]
EVENT_SCRIPTS = ROOT / "data" / "event_scripts.s"
BASEROM = ROOT / "baserom_jp.gba"

LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
INCLUDE_RE = re.compile(r'^\s*\.include\s+"([^"]+)"\s*$')
STRING_RE = re.compile(r'^\s*\.string\s+"((?:[^"\\]|\\.)*)"\s*$')

CONTROLS_WITH_ARGS = {
    name for name, arg_count in EXT_CTRL_SPECS.values() if arg_count > 0
}
CONTROLS_WITH_ARGS.add("DYNAMIC")


@dataclass(frozen=True)
class IncludeRecord:
    path: Path
    label: str
    address: int


@dataclass(frozen=True)
class StringLine:
    line_number: int
    source: str


def event_script_includes() -> list[IncludeRecord]:
    """Return data/scripts includes and the ROM label immediately owning them."""
    records: list[IncludeRecord] = []
    label: tuple[str, int] | None = None
    for line in EVENT_SCRIPTS.read_text(encoding="utf-8").splitlines():
        match = LABEL_RE.match(line)
        if match:
            label = (match.group(1), int(match.group(2), 16))
            continue
        match = INCLUDE_RE.match(line)
        if not match or label is None:
            continue
        relpath = match.group(1)
        if relpath.startswith("data/scripts/"):
            records.append(IncludeRecord(ROOT / relpath, label[0], label[1]))
        # A label gives the start address for one include only.  Reusing it
        # for a later include would incorrectly compare a second owner against
        # the first owner's ROM slice.
        label = None
    return records


def pure_string_lines(path: Path) -> tuple[list[StringLine] | None, str | None]:
    """Return all source strings, or why the file is deliberately skipped."""
    strings: list[StringLine] = []
    for line_number, line in enumerate(path.read_text(encoding="utf-8").splitlines(), 1):
        stripped = line.strip()
        if not stripped or stripped.startswith("@"):  # assembly comment
            continue
        match = STRING_RE.match(line)
        if match is None:
            return None, f"non-string assembly at line {line_number}"
        strings.append(StringLine(line_number, match.group(1)))
    if not strings:
        return None, "no .string directives"
    return strings, None


def implicit_control_arguments(strings: list[StringLine]) -> list[tuple[int, str]]:
    """Find controls with a known required argument outside their braces."""
    findings: list[tuple[int, str]] = []
    for entry in strings:
        for match in re.finditer(r"\{([A-Za-z_][A-Za-z0-9_]*)\}", entry.source):
            if match.group(1) in CONTROLS_WITH_ARGS:
                findings.append((entry.line_number, match.group(1)))
    return findings


def inline_line_controls(strings: list[StringLine]) -> list[tuple[int, str]]:
    """Find line/page controls followed by more source in one .string line."""
    findings: list[tuple[int, str]] = []
    for entry in strings:
        for match in re.finditer(r"\\[nlp](?=.)", entry.source):
            findings.append((entry.line_number, match.group(0)))
    return findings


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--verbose", action="store_true", help="show every eligible include")
    parser.add_argument(
        "--strict-control-syntax",
        action="store_true",
        help="return non-zero if a required control argument is outside braces",
    )
    parser.add_argument(
        "--strict-layout",
        action="store_true",
        help="return non-zero if text follows \\n, \\p, or \\l in one .string directive",
    )
    args = parser.parse_args()

    if not BASEROM.is_file():
        raise SystemExit(f"missing matching Japanese baserom: {BASEROM}")
    codec = JapaneseScriptTextCodec()
    rom = BASEROM.read_bytes()

    records = event_script_includes()
    eligible = 0
    skipped: list[tuple[IncludeRecord, str]] = []
    byte_mismatches: list[tuple[IncludeRecord, bytes, bytes]] = []
    codec_errors: list[tuple[IncludeRecord, str]] = []
    implicit: list[tuple[IncludeRecord, int, str]] = []
    inline_controls: list[tuple[IncludeRecord, int, str]] = []

    for record in records:
        strings, reason = pure_string_lines(record.path)
        if strings is None:
            skipped.append((record, reason or "unknown reason"))
            continue
        eligible += 1
        try:
            encoded_parts = []
            for entry in strings:
                part = codec.preproc_bytes(entry.source)
                # Verify each directive independently.  preproc limits one
                # .string to 1024 bytes, whereas an include may validly hold
                # many adjacent strings.
                codec.verify(part)
                encoded_parts.append(part)
            encoded = b"".join(encoded_parts)
        except (TextDecodeError, TextRoundTripError) as exc:
            codec_errors.append((record, str(exc)))
            continue
        offset = record.address - 0x08000000
        expected = rom[offset : offset + len(encoded)]
        if expected != encoded:
            byte_mismatches.append((record, expected, encoded))
        for line_number, control in implicit_control_arguments(strings):
            implicit.append((record, line_number, control))
        for line_number, control in inline_line_controls(strings):
            inline_controls.append((record, line_number, control))
        if args.verbose:
            status = "OK" if expected == encoded else "MISMATCH"
            print(
                f"{status} {record.path.relative_to(ROOT)} "
                f"{record.label} @ 0x{record.address:08X} ({len(encoded)} bytes)"
            )

    print(f"event-script data/scripts includes: {len(records)}")
    print(f"pure-string includes audited:       {eligible}")
    print(f"byte-exact mismatches:              {len(byte_mismatches)}")
    print(f"codec/preproc errors:               {len(codec_errors)}")
    print(f"skipped mixed/non-string includes:  {len(skipped)}")
    print(f"implicit control arguments:         {len(implicit)}")
    print(f"inline line/page controls:          {len(inline_controls)}")

    for record, expected, actual in byte_mismatches[:20]:
        print(
            f"MISMATCH {record.path.relative_to(ROOT)} @ 0x{record.address:08X}: "
            f"ROM={expected.hex().upper()} source={actual.hex().upper()}"
        )
    for record, error in codec_errors[:20]:
        print(f"CODEC ERROR {record.path.relative_to(ROOT)}: {error}")
    for record, line_number, control in implicit[:40]:
        print(
            f"IMPLICIT ARG {record.path.relative_to(ROOT)}:{line_number}: "
            f"{control} must keep its argument inside the same braces"
        )
    if len(implicit) > 40:
        print(f"... {len(implicit) - 40} more implicit-control findings")

    for record, line_number, control in inline_controls[:40]:
        print(
            f"INLINE CONTROL {record.path.relative_to(ROOT)}:{line_number}: "
            f"split after {control} into the next .string directive"
        )
    if len(inline_controls) > 40:
        print(f"... {len(inline_controls) - 40} more inline-control findings")

    if (
        byte_mismatches
        or codec_errors
        or (args.strict_control_syntax and implicit)
        or (args.strict_layout and inline_controls)
    ):
        raise SystemExit(1)


if __name__ == "__main__":
    main()
