#!/usr/bin/env python3
"""Sync JP funcmap names to pokeemerald's names using byte matching.

JP and US ROMs use different address spaces, so name alignment cannot be
done by address.  Instead each JP function's normalized machine code
(absolute-address literals and Thumb bl immediates masked) is hashed and
looked up in a table built from pokeemerald.sym symbols + the US ROM.
Only functions whose bytes match exactly are renamed, so JP-only
functions and JP variants keep their names.

Usage:
    python3 tools/sync_jp_names_by_bytes.py          # report
    python3 tools/sync_jp_names_by_bytes.py --apply  # rewrite funcmap_jp.txt
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
JP_MAP = ROOT / "funcmap_jp.txt"
EMERALD_SYM = ROOT.parent / "pokeemerald" / "pokeemerald.sym"
JP_ROM = (ROOT / "baserom_jp.gba").read_bytes()
US_ROM = (ROOT.parent / "pokeemerald" / "pokeemerald.gba").read_bytes()

MAP_RE = re.compile(r"^([0-9A-Fa-f]{8})\s+\S+\s+(\S+)\s*$")


def normalize(data):
    """Mask link-time data: Thumb bl immediates and absolute addresses."""
    b = bytearray(data)
    for i in range(0, len(b) - 3, 2):
        hw1 = b[i] | (b[i + 1] << 8)
        hw2 = b[i + 2] | (b[i + 3] << 8)
        if (hw1 & 0xF800) == 0xF000 and (hw2 & 0xF800) == 0xF800:
            b[i] = 0xF0
            b[i + 1] = 0x00
            b[i + 2] = 0xF8
            b[i + 3] = 0x00
    for i in range(0, len(b) - 3, 4):
        v = int.from_bytes(b[i : i + 4], "little")
        if 0x02000000 <= v < 0x04000000 or 0x08000000 <= v <= 0x09FFFFFF:
            b[i : i + 4] = b"\x00\x00\x00\x00"
    return bytes(b)


def load_jp_funcs():
    """JP funcmap rows -> (addr, name, size)."""
    rows = []
    for line in JP_MAP.read_text(encoding="utf-8").splitlines():
        m = MAP_RE.match(line)
        if m:
            rows.append((int(m.group(1), 16), m.group(2)))
    rows.sort()
    out = []
    for i, (addr, name) in enumerate(rows):
        nxt = rows[i + 1][0] if i + 1 < len(rows) else 0x09FFFFFF
        out.append((addr, name, nxt - addr))
    return out


def load_us_syms():
    """pokeemerald.sym -> {addr: (name, size)} for ROM code symbols."""
    syms = {}
    for line in EMERALD_SYM.read_text(encoding="utf-8").splitlines():
        m = re.match(r"^([0-9a-fA-F]{8})\s+[gl]\s+([0-9a-fA-F]+)\s+(\w+)\s*$", line)
        if m:
            addr = int(m.group(1), 16)
            size = int(m.group(2), 16)
            if 0x08000000 <= addr < 0x0A000000 and size > 0:
                syms[addr] = (m.group(3), size)
    return syms


def main():
    apply = "--apply" in sys.argv
    jp_funcs = load_jp_funcs()
    us_syms = load_us_syms()

    lookup = {}
    for addr, (name, size) in us_syms.items():
        if size > 0x2000:
            continue
        data = US_ROM[addr & 0xFFFFFF : (addr & 0xFFFFFF) + size]
        key = (size, normalize(data))
        lookup.setdefault(key, []).append((addr, name))

    renamed = []
    kept = 0
    for jp_addr, jp_name, size in jp_funcs:
        if size > 0x2000:
            kept += 1
            continue
        data = JP_ROM[jp_addr & 0xFFFFFF : (jp_addr & 0xFFFFFF) + size]
        key = (size, normalize(data))
        hits = lookup.get(key, [])
        names = {n for _, n in hits}
        if len(names) == 1 and jp_name not in names:
            new_name = next(iter(names))
            renamed.append((jp_addr, jp_name, new_name))
        else:
            kept += 1

    print(f"JP functions: {len(jp_funcs)}, byte-matched to US: {len(renamed)}, "
          f"kept: {kept}")
    if not apply:
        for addr, old, new in renamed[:20]:
            print(f"  0x{addr:08X} {old} -> {new}")
        if len(renamed) > 20:
            print(f"  ... and {len(renamed) - 20} more")
        return

    by_addr = {addr: new for addr, old, new in renamed}
    lines = []
    for line in JP_MAP.read_text(encoding="utf-8").splitlines():
        m = MAP_RE.match(line)
        if m:
            addr = int(m.group(1), 16)
            if addr in by_addr:
                lines.append(f"{m.group(1)} {m.group(2)} {by_addr[addr]}")
                continue
        lines.append(line)
    JP_MAP.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print("funcmap_jp.txt rewritten.")


if __name__ == "__main__":
    main()
