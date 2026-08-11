#!/usr/bin/env python3
"""List thumb_func_start names with addresses from an asm file."""

import re
import sys


def main():
    path = sys.argv[1]
    with open(path, encoding="utf-8", errors="replace") as f:
        lines = f.readlines()
    for i, line in enumerate(lines):
        m = re.match(r"\s*thumb_func_start\s+(\w+)", line)
        if m:
            name = m.group(1)
            addr = None
            for j in range(i + 1, min(i + 3, len(lines))):
                m2 = re.match(r"\s*(\w+): @ 0x([0-9A-F]+)", lines[j])
                if m2:
                    addr = int(m2.group(2), 16)
                    break
            print(f"{name:45s} 0x{addr:#x}" if addr else name)


if __name__ == "__main__":
    main()
