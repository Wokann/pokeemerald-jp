#!/usr/bin/env python3
"""Generate data/tables/items.s: gItems, 377 entries x 40 bytes.

The layout was verified from the asm (ItemId_GetName indexes by itemId*40
from 0x0855CEE8; SanitizeItemId caps at 376) and from known item values
(MASTER_BALL itemId=1/price=0, HYPER_BALL itemId=2/price=1200).

Field layout (matching vanilla Emerald):
    u8  name[10], u16 itemId, u16 price, u8 holdEffect, u8 holdEffectParam,
    u32 description, u8 importance, u8 registrability, u8 pocket, u8 type,
    u32 fieldUseFunc, u8 battleUsage, u8 unknown[3], u32 battleUseFunc,
    u8 secondaryId, 3 bytes padding.

Usage:
    python3 tools/generate_items.py
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BIN = ROOT / "build" / "data" / "data.bin"
OUT = ROOT / "data" / "tables" / "items.s"

ADDR = 0x0855CEE8
STRIDE = 40
COUNT = 377
REGION_START = 0x29BDA4

LABEL_RE = re.compile(r"^\s*([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")

sys.path.insert(0, str(ROOT / "tools"))
from text_tool import Charmap  # noqa: E402


def build_label_map():
    labels = {}
    for path in sorted((ROOT / "asm").glob("*.s")):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = LABEL_RE.match(line)
            if m:
                labels.setdefault(int(m.group(2), 16), m.group(1))
    return labels


def ptr_repr(value, labels):
    if value == 0:
        return "0x00000000"
    label = labels.get(value & ~1)
    return label if label else f"0x{value:08X}"


def main():
    if not BIN.is_file():
        sys.exit(f"missing {BIN}; run make first")
    data = BIN.read_bytes()
    rel = ADDR - (0x08000000 + REGION_START)
    cm = Charmap()
    cm.load(ROOT / "charmap.txt")
    labels = build_label_map()

    out = [
        "\t.globl gItems",
        "\t.globl gUnknown_855CEE8",
        "gItems:",
        "gUnknown_855CEE8:",
    ]
    for i in range(COUNT):
        rec = data[rel + i * STRIDE : rel + (i + 1) * STRIDE]
        name_bytes = rec[0:10]
        name_enc = cm.decode(name_bytes)
        idx = name_bytes.find(0xFF)
        readable = cm.decode(name_bytes[:idx]) if idx != -1 else name_enc
        item_id = int.from_bytes(rec[10:12], "little")
        price = int.from_bytes(rec[12:14], "little")
        hold_effect = rec[14]
        hold_effect_param = rec[15]
        description = int.from_bytes(rec[16:20], "little")
        importance = rec[20]
        registrability = rec[21]
        pocket = rec[22]
        item_type = rec[23]
        field_use = int.from_bytes(rec[24:28], "little")
        battle_usage = rec[28]
        unknown = rec[29:32]
        battle_use = int.from_bytes(rec[32:36], "little")
        secondary_id = rec[36]
        padding = rec[37:40]

        if i < 6:
            print(f"item {i}: id={item_id} price={price} pocket={pocket} "
                  f"type={item_type} fieldUse={field_use:08X} "
                  f"battleUse={battle_use:08X} unknown={unknown.hex()}")
        if unknown != b"\x00\x00\x00":
            sys.exit(f"item {i}: non-zero unknown field {unknown.hex()}")

        out.append("")
        out.append(f"\t@ {i:03d} \"{readable}\"")
        out.append(f'\t.string "{name_enc}"')
        out.append(f"\t.2byte 0x{item_id:04X}  @ itemId")
        out.append(f"\t.2byte 0x{price:04X}  @ price")
        out.append(f"\t.byte 0x{hold_effect:02X}  @ holdEffect")
        out.append(f"\t.byte 0x{hold_effect_param:02X}  @ holdEffectParam")
        out.append(f"\t.4byte {ptr_repr(description, labels)}  @ description")
        out.append(f"\t.byte 0x{importance:02X}  @ importance")
        out.append(f"\t.byte 0x{registrability:02X}  @ registrability")
        out.append(f"\t.byte 0x{pocket:02X}  @ pocket")
        out.append(f"\t.byte 0x{item_type:02X}  @ type")
        out.append(f"\t.4byte {ptr_repr(field_use, labels)}  @ fieldUseFunc")
        out.append(f"\t.byte 0x{battle_usage:02X}  @ battleUsage")
        out.append("\t.byte 0x00, 0x00, 0x00  @ unknown")
        out.append(f"\t.4byte {ptr_repr(battle_use, labels)}  @ battleUseFunc")
        out.append(f"\t.byte 0x{secondary_id:02X}  @ secondaryId")
        if padding == b"\x00" * 3:
            out.append("\t.space 3  @ padding")
        else:
            out.append("\t.byte " + ", ".join(f"0x{b:02X}" for b in padding))

    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text("\n".join(out) + "\n", encoding="utf-8")
    print(f"wrote {OUT} ({COUNT} entries)")


if __name__ == "__main__":
    main()
