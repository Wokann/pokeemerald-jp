#!/usr/bin/env python3
"""Dump bytes from the built ROM at an address to /tmp/built_<addr>.bin."""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
addr = int(sys.argv[1], 16)
size = int(sys.argv[2], 16)
rom = (ROOT / "pokeemerald_jp.gba").read_bytes()
off = addr & 0xFFFFFF
Path(f"/tmp/built_{addr:08X}.bin").write_bytes(rom[off : off + size])
print(f"dumped 0x{size:X} bytes at 0x{addr:08X}")
