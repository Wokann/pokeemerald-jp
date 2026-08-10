#!/usr/bin/env python3
"""Compile a C file and print the asm tail around a function."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import convert_c


def main():
    func = sys.argv[1]
    c_file = sys.argv[2]
    asm_text, obj = convert_c.compile_c(c_file, "/tmp/cf")
    lines = asm_text.splitlines()
    start = None
    for i, line in enumerate(lines):
        if line.startswith(func + ":"):
            start = i
            break
    if start is None:
        print("function not found")
        return
    end = len(lines)
    for i in range(start, len(lines)):
        if lines[i].startswith(".Lfe") or lines[i].startswith(".size"):
            end = i + 1
            break
    print("\n".join(lines[start:end]))


if __name__ == "__main__":
    main()
