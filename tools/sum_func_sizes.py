#!/usr/bin/env python3
"""Sum the .text function sizes in a built object file."""

import re
import subprocess
import sys


def main():
    obj = sys.argv[1] if len(sys.argv) > 1 else "build/src/match_call.o"
    out = subprocess.run(
        ["tools/binutils/bin/arm-none-eabi-nm", "-S", obj],
        capture_output=True,
        text=True,
    ).stdout
    total = 0
    funcs = []
    for line in out.splitlines():
        m = re.match(r"([0-9a-f]+) ([0-9a-f]+) [tT] (\w+)", line)
        if m:
            size = int(m.group(2), 16)
            name = m.group(3)
            if size:
                funcs.append((name, size))
                total += size
    for name, size in funcs:
        print(f"{name:45s} 0x{size:x}")
    print(f"TOTAL 0x{total:x} ({total})")


if __name__ == "__main__":
    main()
