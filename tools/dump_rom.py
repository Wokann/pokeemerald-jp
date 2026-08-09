#!/usr/bin/env python3
import sys

addr = int(sys.argv[1], 16)
n = int(sys.argv[2], 16) if len(sys.argv) > 2 else 32
rom = open("baserom_jp.gba", "rb").read()
o = addr - 0x08000000
data = rom[o:o+n]
print("0x%08X:" % addr, data)
# printable ascii / shift-jis-ish side
print("ascii:", "".join(chr(b) if 0x20 <= b < 0x7f else "." for b in data))
