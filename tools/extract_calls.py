#!/usr/bin/env python3
"""Extract the set of Thumb bl call targets inside each ROM function.

Used to match JP functions to their US counterparts by call graph when
their bytes differ (JP variants).  bl immediates are decoded from the
machine code; the returned targets are absolute ROM addresses.
"""

from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def bl_targets(data, base_addr):
    """Return the set of absolute targets of bl instructions in data."""
    targets = set()
    i = 0
    while i + 3 < len(data):
        hw1 = data[i] | (data[i + 1] << 8)
        hw2 = data[i + 2] | (data[i + 3] << 8)
        if (hw1 & 0xF800) == 0xF000 and (hw2 & 0xF800) == 0xF800:
            # First halfword carries the high 11 bits, second the low 11.
            raw = ((hw1 & 0x7FF) << 11) | (hw2 & 0x7FF)
            off = raw << 1
            if off & 0x400000:  # sign extend 23-bit signed offset
                off -= 0x800000
            pc = base_addr + i + 4
            targets.add((pc + off) & 0xFFFFFFFF)
            i += 4
        else:
            i += 2
    return targets


def function_slices(rom, addrs):
    """Yield (addr, name, data) for each function using next-addr sizes."""
    rows = sorted(addrs)
    out = []
    for i, (addr, name) in enumerate(rows):
        nxt = rows[i + 1][0] if i + 1 < len(rows) else 0x09FFFFFF
        size = nxt - addr
        data = rom[addr & 0xFFFFFF : (addr & 0xFFFFFF) + size]
        out.append((addr, name, data))
    return out


if __name__ == "__main__":
    # Smoke test: SaveSerializedGame in JP should call SavePlayerParty
    # and SaveEventObjects (0x08076794 and 0x08076824).
    jp = (ROOT / "baserom_jp.gba").read_bytes()
    funcs = []
    for line in (ROOT / "funcmap_jp.txt").read_text(encoding="utf-8").splitlines():
        import re
        m = re.match(r"^([0-9A-Fa-f]{8})\s+\S+\s+(\S+)\s*$", line)
        if m:
            funcs.append((int(m.group(1), 16), m.group(2)))
    for addr, name, data in function_slices(jp, funcs):
        if name in ("SaveSerializedGame", "LoadSerializedGame", "SavePlayerParty"):
            print(f"{name} @ 0x{addr:08X} calls: "
                  f"{[hex(t) for t in sorted(bl_targets(data, addr))]}")
