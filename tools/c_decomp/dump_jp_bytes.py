#!/usr/bin/env python3
"""Dump JP ROM bytes at an address to /tmp/jp_<addr>.bin for objdump."""
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
addr = int(sys.argv[1], 16)
size = int(sys.argv[2], 16)
rom = (ROOT / "baserom_jp.gba").read_bytes()
Path(f"/tmp/jp_{addr:08X}.bin").write_bytes(rom[addr : addr + size])
print(f"dumped 0x{size:X} bytes at 0x{addr:08X}")
