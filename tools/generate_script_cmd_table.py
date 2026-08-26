#!/usr/bin/env python3
"""Generate data/script_cmd_table.inc from the Japanese ROM's script
command table, using pokeemerald's file format so the command handlers can
be referenced symbolically instead of embedded as raw ROM bytes.

The JP gScriptCmdTable (225 entries at 0x81DABAC) is a pointer table into
asm/scrcmd.s.  This script:

  1. builds an address -> label map from the asm files,
  2. reads the 225 table pointers from baserom_jp.gba,
  3. emits data/script_cmd_table.inc in pokeemerald's format, naming each
     entry after its handler and reusing pokeemerald's command constant
     names whenever the handler identity matches one of pokeemerald's
     commands.

Usage:
    python3 tools/generate_script_cmd_table.py [baserom.gba] [pokeemerald_cmd_table]
"""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BASEROM_DEFAULT = ROOT / "baserom_jp.gba"
POKEEMERALD_TABLE = ROOT.parent / "pokeemerald" / "data" / "script_cmd_table.inc"
OUT = ROOT / "data" / "script_cmd_table.inc"
ELF_DEFAULT = ROOT / "pokeemerald_jp.elf"
NM = ROOT / "tools" / "binutils" / "bin" / "arm-none-eabi-nm"

TABLE_OFFSET = 0x1DABAC
TABLE_SIZE = 0x384  # 225 entries x 4 bytes

LABEL_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
NM_RE = re.compile(r"^([0-9A-Fa-f]{8})\s+([Tt])\s+(\S+)$")
ENTRY_RE = re.compile(
    r"^\s*script_cmd_table_entry\s+(\S+)\s+(\S+)\s*@\s*0x([0-9A-Fa-f]+)"
)

JP_OPCODE_CONSTANT_OVERRIDES = {
    0x64: "SCR_OP_COPYOBJECTXYTOPERM",
    0x91: "SCR_OP_REMOVEMONEY",
    0xD3: "SCR_OP_MOVEROTATINGTILEOBJECTS",
    0xD4: "SCR_OP_TURNROTATINGTILEOBJECTS",
    0xD5: "SCR_OP_INITROTATINGTILEPUZZLE",
    0xD6: "SCR_OP_FREEROTATINGTILEPUZZLE",
    0xD7: "SCR_OP_WARPMOSSDEEPGYM",
    0xDA: "SCR_OP_CLOSEBRAILLEMESSAGE",
}


def build_label_map():
    labels = {}

    def add_label(addr, label, replace=False):
        if replace or addr not in labels:
            labels[addr] = label

    for path in sorted((ROOT / "asm").glob("*.s")):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = LABEL_RE.match(line)
            if m:
                addr = int(m.group(2), 16)
                add_label(addr, m.group(1))

    # Most command handlers are already C sources, so their current JP
    # addresses are available from the matching ELF rather than asm labels.
    # This tool is intentionally an after-build auditor/generator; do not emit
    # raw pointer literals when the symbol map is unavailable.
    if ELF_DEFAULT.is_file() and NM.is_file():
        output = subprocess.check_output([NM, "-n", ELF_DEFAULT], text=True)
        for line in output.splitlines():
            m = NM_RE.match(line)
            if m:
                add_label(int(m.group(1), 16), m.group(3), replace=True)
    return labels


def read_reference_table(path):
    entries = []
    if not path.is_file():
        print(f"note: pokeemerald reference table not found at {path}")
        return entries
    for line in path.read_text(encoding="utf-8").splitlines():
        m = ENTRY_RE.match(line)
        if m:
            entries.append((m.group(1), m.group(2)))
    return entries


def reference_by_handler(entries):
    by_handler = {}
    for const, handler in entries:
        by_handler[handler] = const
    return by_handler


def main():
    baserom = Path(sys.argv[1]) if len(sys.argv) > 1 else BASEROM_DEFAULT
    ref_path = Path(sys.argv[2]) if len(sys.argv) > 2 else POKEEMERALD_TABLE
    if not ELF_DEFAULT.is_file() or not NM.is_file():
        sys.exit(
            "missing JP ELF symbol map; run a complete build before regenerating "
            "data/script_cmd_table.inc"
        )
    rom = baserom.read_bytes()
    if TABLE_OFFSET + TABLE_SIZE > len(rom):
        sys.exit(f"table range out of ROM bounds ({len(rom)} bytes)")
    raw = rom[TABLE_OFFSET : TABLE_OFFSET + TABLE_SIZE]
    words = [int.from_bytes(raw[i : i + 4], "little") for i in range(0, TABLE_SIZE, 4)]
    if len(words) != 225:
        sys.exit(f"expected 225 table entries, got {len(words)}")

    labels = build_label_map()
    reference = read_reference_table(ref_path)
    const_by_handler = reference_by_handler(reference)

    lines = [
        "\t.ifndef SCRIPT_CMD_TABLE_ENTRY_MACRO",
        "\t.set SCRIPT_CMD_TABLE_ENTRY_MACRO, 1",
        "\t.macro script_cmd_table_entry constant:req, value:req",
        "\t.if ALLOCATE_SCRIPT_CMD_TABLE",
        "\t.4byte \\value",
        "\t.else",
        "\tenum \\constant",
        "\t.endif",
        "\t.endm",
        "\t.endif",
        "",
        "",
        "\tenum_start",
        "\t.if ALLOCATE_SCRIPT_CMD_TABLE",
        "\t.align 2",
        "gScriptCmdTable::",
        "\t.endif",
    ]

    missing = 0
    unified = 0
    used = set()
    for i, word in enumerate(words):
        if i == 0xD3:
            lines.extend(
                [
                    "\t@ These five retained JP handler names implement the canonical Emerald",
                    "\t@ rotating-tile / Mossdeep Gym commands named in script_commands.h.",
                ]
            )
        handler = labels.get(word & ~1)
        if handler is None:
            missing += 1
            continue
        const = JP_OPCODE_CONSTANT_OVERRIDES.get(
            i, const_by_handler.get(handler, f"SCR_OP_{i:02X}")
        )
        if const in used:
            # Several JP opcodes share a placeholder handler (e.g.
            # ScrCmd_nop1); the enum requires unique constant names.
            const = f"SCR_OP_{i:02X}"
        used.add(const)
        if const != f"SCR_OP_{i:02X}":
            unified += 1
        lines.append(f"\tscript_cmd_table_entry {const} {handler} @ 0x{i:02X}")

    # pokeemerald ends the table with a sentinel pointer to ScrCmd_nop;
    # the JP ROM has the same 4-byte sentinel at 0x81DAF30.
    if missing:
        sys.exit(f"unresolved JP script command handlers: {missing}")
    lines.extend(
        [
            "",
            "\t.if ALLOCATE_SCRIPT_CMD_TABLE",
            "gScriptCmdTableEnd::",
            "\t.4byte ScrCmd_nop",
            "\t.endif",
        ]
    )

    OUT.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"wrote {OUT} ({len(words)} entries, {missing} unresolved, "
          f"{unified} constants unified with pokeemerald names)")


if __name__ == "__main__":
    main()
