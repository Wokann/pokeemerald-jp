#!/usr/bin/env python3
"""Find the first differing byte between two ROMs in a range."""

import sys


def main():
    start = int(sys.argv[1], 16)
    end = int(sys.argv[2], 16)
    with open("baserom_jp.gba", "rb") as f:
        a = f.read()
    with open("pokeemerald_jp.gba", "rb") as f:
        b = f.read()
    sa, sb = start - 0x08000000, end - 0x08000000
    diffs = []
    for i in range(sa, min(sb, len(a), len(b))):
        if a[i] != b[i]:
            diffs.append((start + i - sa, a[i], b[i]))
            if len(diffs) >= 20:
                break
    print(f"first diffs in {start:#x}..{end:#x}:")
    for addr, va, vb in diffs:
        print(f"  {addr:#08x}: base={va:#04x} new={vb:#04x}")
    if not diffs:
        print("  none")
    # Also show raw bytes side by side for a small window.
    print("\nraw bytes:")
    for addr in range(start, min(end, start + 0x40), 8):
        sa = addr - 0x08000000
        chunk_a = a[sa:sa + 8]
        chunk_b = b[sa:sa + 8]
        print(f"  {addr:#08x}: base={chunk_a.hex(' ')}  new={chunk_b.hex(' ')}")


if __name__ == "__main__":
    main()
