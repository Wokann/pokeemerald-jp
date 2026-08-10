#!/usr/bin/env python3
"""Dump the JP ROM font info table at sFontInfos to see the font order."""
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
rom = (ROOT / "baserom_jp.gba").read_bytes()
base = 0x29CEA4  # sFontInfos
for i in range(12):
    d = rom[base + i * 12 : base + (i + 1) * 12]
    if len(d) < 12:
        break
    fn_ptr, mw, mh, ls, ln, bits1, bits2 = struct.unpack("<IBBBB2B", d[:10])
    unk = (bits1 >> 4) & 0xF
    fg = bits1 & 0xF
    bg = (bits2 >> 4) & 0xF
    sh = bits2 & 0xF
    print(
        f"font {i}: func=0x{fn_ptr:08X} maxW={mw} maxH={mh} spacing={ls} "
        f"line={ln} unk={unk} fg={fg} bg={bg} sh={sh}"
    )
