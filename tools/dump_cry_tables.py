#!/usr/bin/env python3
"""Dump the JP cry table layout from baserom_jp.gba.

JP PlayCryInternal uses 8 independent table base addresses:
  normal (reverse=0): 0x08625814, 0x08625E14, 0x08626414, 0x08626A14
  reverse (reverse=1): 0x08626A44, 0x08627044, 0x08627644, 0x08627C44

Each entry is a struct ToneData (12 bytes on GBA).
This script prints the tables' extent, entry counts, and a few sample entries
so the layout can be verified against the ROM.
"""

import struct
import sys


ROM_OFFSET_BASE = 0x08000000
ENTRY_SIZE = 12  # struct ToneData on GBA

BASES = [
    ("normal t0", 0x08625814),
    ("normal t1", 0x08625E14),
    ("normal t2", 0x08626414),
    ("normal t3", 0x08626A14),
    ("reverse t0", 0x08626A44),
    ("reverse t1", 0x08627044),
    ("reverse t2", 0x08627644),
    ("reverse t3", 0x08627C44),
]


def rom_offset(addr):
    return addr - ROM_OFFSET_BASE


def dump_region(data, start, count, label):
    off = rom_offset(start)
    print(f"\n{label} {start:#010x} (+{count} entries):")
    for i in range(count):
        e = struct.unpack_from("<6H", data, off + i * ENTRY_SIZE)
        print(f"  [{i:3d}] @ {start + i * ENTRY_SIZE:#010x}: {e}")


def main():
    rom_path = sys.argv[1] if len(sys.argv) > 1 else "baserom_jp.gba"
    with open(rom_path, "rb") as f:
        data = f.read()

    print(f"ROM: {rom_path} ({len(data)} bytes)")
    # Fanfare table dump: python3 dump_cry_tables.py rom fanfares
    if len(sys.argv) >= 3 and sys.argv[2] == "fanfares":
        start = 0x084FCFC8
        off = rom_offset(start)
        print(f"\nFanfare table @ {start:#010x} (u16 songNum, u16 duration):")
        for i in range(20):
            song, dur = struct.unpack_from("<HH", data, off + i * 4)
            print(f"  [{i:2d}] song={song:#06x} dur={dur}")
        return

    # Optional: dump a region as labeled entries: python3 dump_cry_tables.py rom start count
    if len(sys.argv) >= 4:
        start = int(sys.argv[2], 0)
        count = int(sys.argv[3], 0)
        dump_region(data, start, count, "Region dump")
        return

    # Print each base and the next few entries to spot the layout.
    for name, base in BASES:
        off = rom_offset(base)
        if off + ENTRY_SIZE * 4 > len(data):
            print(f"{name} @ {base:#010x}: beyond ROM")
            continue
        entries = []
        for i in range(4):
            e = struct.unpack_from("<6H", data, off + i * ENTRY_SIZE)
            entries.append(e)
        print(f"{name:11s} @ {base:#010x}  first4={entries}")

    # Try to determine whether the 8 tables are tightly packed (128 entries each).
    print("\nTable extent analysis (assuming 128 entries of 12 bytes = 0x600):")
    for i, (name, base) in enumerate(BASES):
        end = base + 128 * ENTRY_SIZE
        nxt = BASES[(i + 1) % len(BASES)][1]
        print(f"  {name:11s} {base:#010x} .. {end:#010x}  next_base={nxt:#010x}")


if __name__ == "__main__":
    main()
