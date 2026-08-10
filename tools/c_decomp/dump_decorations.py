#!/usr/bin/env python3
"""Dump the JP ROM gDecorations table to infer the JP struct layout."""
import struct
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
rom = (ROOT / "baserom_jp.gba").read_bytes()
base = 0x580CD0
for i in range(6):
    d = rom[base + i * 0x1C : base + (i + 1) * 0x1C]
    if len(d) < 0x1C:
        break
    print(f"decor {i}: " + " ".join(f"{b:02X}" for b in d[:16]))
    print(f"  16..: " + " ".join(f"{b:02X}" for b in d[16:]))
    # candidate category byte positions
    for off in range(16):
        v = d[off]
        if v < 8:
            print(f"    byte at 0x{off:02X} = {v} (small, maybe category/shape/permission)")
