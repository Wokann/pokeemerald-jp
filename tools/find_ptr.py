#!/usr/bin/env python3
import struct, sys

addr = int(sys.argv[1], 16)
rom = open("baserom_jp.gba", "rb").read()
pat = struct.pack("<I", addr)
hits = []
i = 0
while True:
    i = rom.find(pat, i)
    if i < 0:
        break
    hits.append(i)
    i += 1
if not hits:
    print("0x%08X not found in ROM" % addr)
else:
    for h in hits[:10]:
        ctx = [struct.unpack("<I", rom[j:j+4])[0] for j in range(max(0, h-12), h+16, 4)]
        print("found at 0x%08X: %s" % (0x08000000 + h, " ".join("0x%08X" % v for v in ctx)))
