#!/usr/bin/env python3
"""Find the first byte differences between the built ROM and baserom."""
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
built = (ROOT / "pokeemerald_jp.gba").read_bytes()
base = (ROOT / "baserom_jp.gba").read_bytes()
n = min(len(built), len(base))
diffs = []
for i in range(n):
    if built[i] != base[i]:
        diffs.append((i, base[i], built[i]))
        if len(diffs) >= 20:
            break
if not diffs:
    print("identical")
else:
    for off, b, c in diffs:
        print(f"0x{off:08X} base={b:02X} built={c:02X}")
