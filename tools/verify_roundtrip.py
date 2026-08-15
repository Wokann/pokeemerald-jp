#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Verify text-table round-trip against ROM slots."""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

fwd = {}
for l in (ROOT / "charmap.txt").read_text(encoding="utf-8").splitlines():
    m = re.match(r"^'(.+?)'\s*=\s*([0-9A-Fa-f ]+)$", l)
    if m:
        try:
            fwd[m.group(1)] = bytes(int(x, 16) for x in m.group(2).split())
        except ValueError:
            pass


def enc(s):
    out = bytearray()
    i = 0
    while i < len(s):
        for L in range(min(4, len(s) - i), 0, -1):
            if s[i:i + L] in fwd:
                out += fwd[s[i:i + L]]
                i += L
                break
        else:
            i += 1
    return bytes(out)


rom = (ROOT / "baserom_jp.gba").read_bytes()

specs = [
    # (file, rom_off, slot_size, pad_byte, entries)
    ("species_names.h", 0x2EA31C, 6, 0x00, "SPECIES"),
    ("move_names.h", 0x2EACC4, 8, 0xFF, "MOVE"),
    ("type_names.h", 0x2EBC88, 5, 0xFF, "TYPE"),
    ("trainer_class_names.h", 0x2E3564, 11, 0x00, "TRAINER_CLASS"),
]

# abilities.h has two tables: gAbilityNames (8B) and gAbilityDescriptionPointers (19B)
for fname, table, off, size, pad in [
    ("abilities.h", "gAbilityNames", 0x2EBDC4, 8, 0x00),
    ("abilities.h", "gAbilityDescriptionPointers", 0x2EC034, 19, 0x00),
]:
    text = (ROOT / "src/data/text" / fname).read_text(encoding="utf-8")
    idx = text.find(table)
    nxt = text.find("};", idx)
    seg = text[idx:nxt]
    entries = re.findall(r'^\s*\[\w+\] = _\("(.*)"\),', seg, re.M)
    ok = 0
    bad = []
    for i, s in enumerate(entries):
        slot = rom[off + i * size: off + (i + 1) * size]
        e = enc(s)
        exp = (e + bytes([0xFF]))[:size].ljust(size, bytes([pad]))
        if exp == slot:
            ok += 1
        else:
            bad.append((i, s, e.hex(" "), slot.hex(" ")))
    print(f"{fname} {table}: {ok}/{len(entries)} OK, {len(bad)} bad")
    for b in bad[:5]:
        print("  ", b)

# variable-length text table: comm_error_texts.h (contiguous, FF-terminated)
vtext = (ROOT / "src/data/text/comm_error_texts.h").read_text(encoding="utf-8")
ventries = re.findall(r'^const u8 (\w+)\[\] = _\("(.*)"\);', vtext, re.M)
vaddrs = [0x82BFE00, 0x82BFE50, 0x82BFE62, 0x82BFE8D, 0x82BFE9F]
print(f"comm_error_texts: {len(ventries)} entries")
ok = 0
for (name, s), va in zip(ventries, vaddrs):
    e = enc(s) + bytes([0xFF])
    slot = rom[va - 0x8000000: va - 0x8000000 + len(e)]
    if e == slot:
        ok += 1
    else:
        print(f"  BAD {name}: enc={e.hex(' ')[:40]} rom={slot.hex(' ')[:40]}")
print(f"  {ok}/{len(ventries)} OK")

for fname, off, size, pad, _ in specs:
    text = (ROOT / "src/data/text" / fname).read_text(encoding="utf-8")
    entries = re.findall(r'^\s*\[\w+\] = _\("(.*)"\),', text, re.M)
    if not entries:
        entries = re.findall(r'^\s*\[\w+\] = __\("(.*)"\),', text, re.M)
    ok = 0
    bad = []
    for i, s in enumerate(entries):
        slot = rom[off + i * size: off + (i + 1) * size]
        e = enc(s)
        # _(): preproc appends 0xFF then C pads; __(): exact bytes
        exp = (e + bytes([0xFF]))[:size].ljust(size, bytes([pad]))
        if exp == slot:
            ok += 1
        else:
            bad.append((i, s, e.hex(" "), slot.hex(" ")))
    print(f"{fname}: {ok}/{len(entries)} OK, {len(bad)} bad")
    for b in bad[:5]:
        print("  ", b)
