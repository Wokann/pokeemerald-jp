#!/usr/bin/env python3
"""Dump and interpret the reset_rtc_screen data area from baserom_jp.gba."""

import struct
import sys


ROM = "baserom_jp.gba"
BASE = 0x08000000


def main():
    with open(ROM, "rb") as f:
        data = f.read()
    # Compare with the built ROM if present.
    try:
        with open("pokeemerald_jp.gba", "rb") as f:
            built = f.read()
    except FileNotFoundError:
        built = None
    if built is not None:
        start_cmp = 0x084E8A40
        n_cmp = 0x200
        a = data[start_cmp - BASE:start_cmp - BASE + n_cmp]
        b = built[start_cmp - BASE:start_cmp - BASE + n_cmp]
        diffs = [i for i in range(n_cmp) if a[i] != b[i]]
        print(f"data diffs 0x{start_cmp:#x}..0x{start_cmp + n_cmp:#x}: {len(diffs)} bytes")
        if diffs:
            for i in diffs[:32]:
                print(f"  {start_cmp + i:#08x}: base={a[i]:#04x} new={b[i]:#04x}")
            print("...")
    start = int(sys.argv[1], 16) if len(sys.argv) > 1 else 0x084E8A40
    n = int(sys.argv[2], 16) if len(sys.argv) > 2 else 0x130
    off = start - BASE
    blob = data[off:off + n]
    print(f"Dumping {start:#x} .. {start + n:#x}")
    # 12-byte rows (ResetRtcInputMap candidate)
    print("\n12-byte rows:")
    for i in range(0, len(blob) - 11, 12):
        row = blob[i:i + 12]
        u8 = row[0]
        u16s = struct.unpack_from("<HH", row, 2)
        print(f"  {start + i:#08x}: {row.hex(' ')}  idx={u8:#04x} min={u16s[0]:#06x} max={u16s[1]:#06x} l/r/u={row[6]:#04x}/{row[7]:#04x}/{row[8]:#04x}")

    # Candidate strings (shift-jis-ish) between 0x84E8A48 and 0x84E8B14
    print("\nRegion 0x84E8A48..0x84E8B14 raw:")
    off2 = 0x084E8A48 - BASE
    blob2 = data[off2:0x084E8B14 - BASE]
    for i in range(0, len(blob2), 16):
        chunk = blob2[i:i + 16]
        print(f"  {0x084E8A48 + i:#08x}: {chunk.hex(' ')}")

    # Full region 0x84E8A40 .. 0x84E8C40 (data + gfx + text start)
    print("\nFull region 0x84E8A40 .. 0x84E8C40:")
    off3 = 0x084E8A40 - BASE
    blob3 = data[off3:0x084E8C40 - BASE]
    for i in range(0, len(blob3), 16):
        chunk = blob3[i:i + 16]
        print(f"  {0x084E8A40 + i:#08x}: {chunk.hex(' ')}")


if __name__ == "__main__":
    main()
