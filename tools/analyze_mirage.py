#!/usr/bin/env python3
"""Show mirage_tower data symbol sizes and the asm function context for each."""

import re


def main():
    # Symbol sizes from data/data.s
    syms = {}
    with open("data/data.s", encoding="utf-8", errors="replace") as f:
        lines = f.readlines()
    for i, line in enumerate(lines):
        m = re.match(r"gUnknown_85E(7430|7D50|7E00|7F20|7F50|7F60|7FBC|7FD4|7FF0):", line)
        if m:
            addr = "0x085E" + m.group(1)
            size = None
            for j in range(i + 1, min(i + 4, len(lines))):
                m2 = re.match(r'\s*\.incbin[^,]+,\s*0x([0-9a-f]+),\s*0x([0-9a-f]+)', lines[j])
                if m2:
                    size = int(m2.group(2), 16)
                    break
                m3 = re.match(r'\s*\.string', lines[j])
                if m3:
                    size = "string"
                    break
            syms[addr] = size
    for k, v in syms.items():
        print(f"{k}  size={v}")

    # Function context for each reference in asm/mirage_tower.s
    print("\nReference context:")
    with open("asm/mirage_tower.s", encoding="utf-8", errors="replace") as f:
        alines = f.readlines()
    func = None
    for i, line in enumerate(alines):
        m = re.match(r"\s*thumb_func_start\s+(\w+)", line)
        if m:
            func = m.group(1)
        if "0x085E" in line and ".4byte" in line:
            addr = re.search(r"0x085E[0-9A-F]+", line).group(0)
            print(f"  line {i + 1}: {func}  -> {addr}")


if __name__ == "__main__":
    main()
