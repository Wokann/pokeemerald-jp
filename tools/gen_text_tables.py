#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Regenerate species_names.h / move_names.h as _("...") text form."""
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

# charmap forward (longest-match) and reverse
fwd = {}
for l in (ROOT / "charmap.txt").read_text(encoding="utf-8").splitlines():
    m = re.match(r"^'(.+?)'\s*=\s*([0-9A-Fa-f ]+)$", l)
    if m:
        try:
            fwd[m.group(1)] = bytes(int(x, 16) for x in m.group(2).split())
        except ValueError:
            pass

rev = {}
for ch, b in fwd.items():
    rev.setdefault(b, ch)


def decode_slot(slot):
    """Decode inner-code slot bytes back to text (stop at FF terminator)."""
    out = []
    i = 0
    while i < len(slot):
        if slot[i] == 0xFF:
            break
        for L in (2, 1):
            if slot[i:i + L] in rev:
                out.append(rev[slot[i:i + L]])
                i += L
                break
        else:
            out.append("?")
            i += 1
    return "".join(out)


def write_table(header_path, symbol, idx_list, rom_off, slot_size, name):
    rom = (ROOT / "baserom_jp.gba").read_bytes()
    lines = [f"const u8 {symbol}[][{name}_LENGTH + 1] = {{"]
    for i, key in enumerate(idx_list):
        slot = rom[rom_off + i * slot_size: rom_off + (i + 1) * slot_size]
        text = decode_slot(slot)
        lines.append(f"    [{key}] = _(\"{text}\"),")
    lines.append("};")
    header_path.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"written {header_path} ({len(idx_list)} entries)")


# species
us_species = ROOT.parent / "pokeemerald" / "src" / "data" / "text" / "species_names.h"
species_idx = re.findall(r'^\s*\[(SPECIES_\w+)\]', us_species.read_text(encoding="utf-8"), re.M)
write_table(ROOT / "src/data/text/species_names.h", "gSpeciesNames", species_idx, 0x2EA31C, 6, "POKEMON_NAME")

# moves
us_moves = ROOT.parent / "pokeemerald" / "src" / "data" / "text" / "move_names.h"
move_idx = re.findall(r'^\s*\[(MOVE_\w+)\]', us_moves.read_text(encoding="utf-8"), re.M)
write_table(ROOT / "src/data/text/move_names.h", "gMoveNames", move_idx, 0x2EACC4, 8, "MOVE_NAME")
