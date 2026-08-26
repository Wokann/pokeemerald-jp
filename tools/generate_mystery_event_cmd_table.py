#!/usr/bin/env python3
"""Generate data/mystery_event_script_cmd_table.s from the Japanese ROM.

The JP table (17 entries at 0x828D2B4) mirrors pokeemerald's
gMysteryEventScriptCmdTable; handler names come from the JP function map
and are cross-checked against pokeemerald's version.

Usage:
    python3 tools/generate_mystery_event_cmd_table.py [baserom.gba] [pokeemerald_table]
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BASEROM_DEFAULT = ROOT / "baserom_jp.gba"
POKEEMERALD_TABLE = (
    ROOT.parent / "pokeemerald" / "data" / "mystery_event_script_cmd_table.s"
)
OUT = ROOT / "data" / "mystery_event_script_cmd_table.s"

TABLE_OFFSET = 0x28D2B4  # file offset of 0x0828D2B4
TABLE_SIZE = 0x44  # 17 entries x 4 bytes

LABEL_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
ENTRY_RE = re.compile(r"^\s*\.4byte\s+([A-Za-z_][A-Za-z0-9_]*)\s*@\s*0x([0-9A-Fa-f]+)")


def build_label_map():
    labels = {}
    for path in sorted((ROOT / "asm").glob("*.s")):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = LABEL_RE.match(line)
            if m:
                labels.setdefault(int(m.group(2), 16), m.group(1))
    for line in (ROOT / "funcmap_jp.txt").read_text(encoding="utf-8").splitlines():
        fields = line.split()
        if not fields or not re.fullmatch(r"[0-9A-Fa-f]{8}", fields[0]):
            continue
        if len(fields) >= 3 and fields[1].endswith((".s", ".c")):
            symbol = fields[2]
        elif len(fields) >= 2:
            symbol = fields[1]
        else:
            continue
        if re.fullmatch(r"[A-Za-z_][A-Za-z0-9_]*", symbol):
            labels.setdefault(int(fields[0], 16), symbol)
    return labels


def read_reference_entries(path):
    handlers = []
    if not path.is_file():
        print(f"note: pokeemerald mystery table not found at {path}")
        return handlers
    for line in path.read_text(encoding="utf-8").splitlines():
        m = ENTRY_RE.match(line)
        if m:
            handlers.append(m.group(1))
    return handlers


def main():
    baserom = Path(sys.argv[1]) if len(sys.argv) > 1 else BASEROM_DEFAULT
    ref_path = Path(sys.argv[2]) if len(sys.argv) > 2 else POKEEMERALD_TABLE
    rom = baserom.read_bytes()
    if TABLE_OFFSET + TABLE_SIZE > len(rom):
        sys.exit(f"table range out of ROM bounds ({len(rom)} bytes)")
    raw = rom[TABLE_OFFSET : TABLE_OFFSET + TABLE_SIZE]
    words = [int.from_bytes(raw[i : i + 4], "little") for i in range(0, TABLE_SIZE, 4)]
    if len(words) != 17:
        sys.exit(f"expected 17 mystery event entries, got {len(words)}")

    labels = build_label_map()
    reference = read_reference_entries(ref_path)

    lines = [
        '\t.section script_data, "aw", %progbits',
        "",
        "\t.align 2",
        "\t.globl gMysteryEventScriptCmdTable",
        "gMysteryEventScriptCmdTable:",
    ]
    matches = 0
    unresolved = []
    for i, word in enumerate(words):
        handler = labels.get(word & ~1)
        if handler is None:
            unresolved.append(f"0x{word:08X}")
            continue
        if i < len(reference) and reference[i] == handler:
            matches += 1
        lines.append(f"\t.4byte {handler:<28} @ 0x{i:02X}")
    lines.append("\t.globl gMysteryEventScriptCmdTableEnd")
    lines.append("gMysteryEventScriptCmdTableEnd:")

    if unresolved:
        sys.exit("unresolved JP mystery event handlers: " + ", ".join(unresolved))

    OUT.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"wrote {OUT} ({len(words)} entries, {matches}/{len(words)} match pokeemerald)")


if __name__ == "__main__":
    main()
