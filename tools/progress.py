#!/usr/bin/env python3
"""Report decompilation progress for pokeemerald-jp.

Counts the number of functions already converted to C (function symbols
defined in build/src/*.o, excluding compiler noise and naked-asm jump
labels) against the total number of functions listed in funcmap_jp.txt
(unique addresses).

Usage: python3 tools/progress.py
"""
import glob
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
NM = str(ROOT / "tools/binutils/bin/arm-none-eabi-nm")


def count_c_functions():
    total = 0
    for obj in sorted(glob.glob(str(ROOT / "build/pokeemerald-jp/src/*.o"))):
        out = subprocess.run([NM, obj], capture_output=True, text=True).stdout
        for line in out.splitlines():
            parts = line.split()
            if len(parts) < 3 or parts[1] not in ("T", "t"):
                continue
            name = parts[2]
            if name == ".gcc2_compiled.":
                continue
            # Naked-asm jump labels such as _081D013C are not functions.
            if re.match(r"^_\d+[A-Fa-f0-9]*$", name):
                continue
            total += 1
    return total


def count_total_functions():
    addrs = set()
    for line in (ROOT / "funcmap_jp.txt").read_text(encoding="utf-8").splitlines():
        parts = line.split()
        if len(parts) >= 2 and len(parts[0]) == 8:
            try:
                addrs.add(int(parts[0], 16))
            except ValueError:
                pass
    return len(addrs)


def main():
    converted = count_c_functions()
    total = count_total_functions()
    pct = converted * 100.0 / total
    print(f"converted: {converted}")
    print(f"total:     {total}")
    print(f"progress:  {converted}/{total} = {pct:.2f}%")


if __name__ == "__main__":
    main()
