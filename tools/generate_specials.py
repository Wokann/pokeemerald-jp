#!/usr/bin/env python3
"""Generate data/specials.inc from the Japanese ROM's special command
table, in pokeemerald's file format.

The JP gSpecials table (524 entries at 0x81DAF8C) is a pointer table into
asm/.  Handler names are taken from the asm labels; waitstate metadata is
reused from pokeemerald's data/specials.inc when the handler identity
matches.

Usage:
    python3 tools/generate_specials.py [baserom.gba] [pokeemerald_specials]
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BASEROM_DEFAULT = ROOT / "baserom_jp.gba"
POKEEMERALD_SPECIALS = ROOT.parent / "pokeemerald" / "data" / "specials.inc"
OUT = ROOT / "data" / "specials.inc"

TABLE_OFFSET = 0x1DAF8C
TABLE_SIZE = 0x830  # 524 entries x 4 bytes

LABEL_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
DEF_SPECIAL_RE = re.compile(
    r"^\s*def_special\s+([A-Za-z_][A-Za-z0-9_]*)(?:,\s*waitstate=(\d+))?"
)


def build_label_map():
    labels = {}
    for path in sorted((ROOT / "asm").glob("*.s")):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = LABEL_RE.match(line)
            if m:
                labels.setdefault(int(m.group(2), 16), m.group(1))
    return labels


def read_reference_specials(path):
    by_handler = {}
    if not path.is_file():
        print(f"note: pokeemerald specials not found at {path}")
        return by_handler
    for line in path.read_text(encoding="utf-8").splitlines():
        m = DEF_SPECIAL_RE.match(line)
        if m:
            handler = m.group(1)
            by_handler.setdefault(handler, int(m.group(2) or 0))
    return by_handler


def main():
    baserom = Path(sys.argv[1]) if len(sys.argv) > 1 else BASEROM_DEFAULT
    ref_path = Path(sys.argv[2]) if len(sys.argv) > 2 else POKEEMERALD_SPECIALS
    rom = baserom.read_bytes()
    if TABLE_OFFSET + TABLE_SIZE > len(rom):
        sys.exit(f"table range out of ROM bounds ({len(rom)} bytes)")
    raw = rom[TABLE_OFFSET : TABLE_OFFSET + TABLE_SIZE]
    words = [int.from_bytes(raw[i : i + 4], "little") for i in range(0, TABLE_SIZE, 4)]
    if len(words) != 524:
        sys.exit(f"expected 524 special entries, got {len(words)}")

    labels = build_label_map()
    waitstate_by_handler = read_reference_specials(ref_path)

    lines = [
        "\t.macro def_special ptr:req, waitstate=0",
        "\t.if ALLOCATE_SPECIAL_TABLE",
        "\t.global SPECIAL_\\ptr",
        "\t.set SPECIAL_\\ptr, __special__",
        "\t.4byte \\ptr",
        "\t.endif",
        "\t.set SPECIAL_WAITSTATE_\\ptr, \\waitstate",
        "\t.set __special__, __special__ + 1",
        "\t.endm",
        "",
        ".set __special__, 0",
        ".if ALLOCATE_SPECIAL_TABLE",
        "\t\t.align 2",
        "\t.globl gSpecials",
        "gSpecials:",
        ".endif",
    ]

    missing = 0
    for i, word in enumerate(words):
        handler = labels.get(word & ~1)
        if handler is None:
            missing += 1
            handler = f"0x{word:08X}"
        waitstate = waitstate_by_handler.get(handler, 0)
        suffix = f", waitstate={waitstate}" if waitstate else ""
        lines.append(f"\tdef_special {handler}{suffix}")

    OUT.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"wrote {OUT} ({len(words)} entries, {missing} unresolved)")


if __name__ == "__main__":
    main()
