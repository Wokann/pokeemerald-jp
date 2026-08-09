#!/usr/bin/env python3
"""Feasibility check: how many JP functions are byte-identical to the US
decompilation after normalizing absolute addresses and bl targets.

The JP and US versions share the same engine; if a function's machine
code matches after masking pointers and branch immediates, its C source
from pokeemerald can be ported directly.

Usage:
    python3 tools/compare_functions.py
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
JP_ROM = ROOT / "baserom_jp.gba"
US_ROM = ROOT.parent / "pokeemerald" / "pokeemerald.gba"
US_MAP = ROOT.parent / "pokeemerald" / "pokeemerald.map"

FUNC_RE = re.compile(r"^\s*thumb_func_start\s+(\w+)\s*$")
LABEL_RE = re.compile(r"^(\w+):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
MAP_RE = re.compile(r"^\s*0x([0-9A-Fa-f]+)\s+(\S+)\s*$")


def jp_functions():
    funcs = {}
    for path in sorted((ROOT / "asm").glob("*.s")):
        current = None
        for line in path.read_text(encoding="utf-8").splitlines():
            m = FUNC_RE.match(line)
            if m:
                current = m.group(1)
                continue
            if current is not None:
                lm = LABEL_RE.match(line)
                if lm and lm.group(1) == current:
                    funcs[current] = int(lm.group(2), 16)
                    current = None
    return funcs


def us_addresses():
    by_name = {}
    addrs = []
    for line in US_MAP.read_text(encoding="utf-8", errors="replace").splitlines():
        m = MAP_RE.match(line)
        if m:
            addr = int(m.group(1), 16)
            by_name[m.group(2)] = addr
            addrs.append(addr)
    addrs.sort()
    return by_name, addrs


def normalize(data):
    b = bytearray(data)
    for i in range(0, len(b) - 3, 4):
        v = int.from_bytes(b[i : i + 4], "little")
        if 0x02000000 <= v < 0x04000000 or 0x08000000 <= v <= 0x09FFFFFF:
            b[i : i + 4] = b"\x00\x00\x00\x00"
    for i in range(0, len(b) - 3, 2):
        hw1 = b[i] | (b[i + 1] << 8)
        hw2 = b[i + 2] | (b[i + 3] << 8)
        if (hw1 & 0xF800) == 0xF000 and (hw2 & 0xF800) == 0xF800:
            b[i] = 0xF0
            b[i + 1] = 0x00
            b[i + 2] = 0xF8
            b[i + 3] = 0x00
    return bytes(b)


def main():
    jp = jp_functions()
    us, us_addrs = us_addresses()
    jp_rom = JP_ROM.read_bytes()
    us_rom = US_ROM.read_bytes()

    jp_sorted = sorted(jp.items(), key=lambda kv: kv[1])
    sizes = {}
    for i, (name, addr) in enumerate(jp_sorted):
        nxt = jp_sorted[i + 1][1] if i + 1 < len(jp_sorted) else addr + 4
        sizes[name] = nxt - addr

    matched = 0
    size_mismatch = 0
    missing_us = 0
    compared = 0
    missing_samples = []
    for name, addr in jp_sorted:
        us_addr = us.get(name)
        if us_addr is None:
            missing_us += 1
            if len(missing_samples) < 10:
                missing_samples.append(name)
            continue
        size = sizes[name]
        # US size from the next US symbol.
        idx = us_addrs.index(us_addr) if us_addr in us_addrs else -1
        us_size = us_addrs[idx + 1] - us_addr if idx != -1 and idx + 1 < len(us_addrs) else size
        compared += 1
        if size != us_size:
            size_mismatch += 1
            continue
        jp_bytes = jp_rom[addr & 0xFFFFFF : (addr & 0xFFFFFF) + size]
        us_bytes = us_rom[us_addr & 0xFFFFFF : (us_addr & 0xFFFFFF) + size]
        if normalize(jp_bytes) == normalize(us_bytes):
            matched += 1

    print(f"JP functions: {len(jp)}")
    print(f"compared (have US symbol + same size): {compared}")
    print(f"  byte-identical after normalization: {matched} "
          f"({matched / max(compared, 1):.1%})")
    print(f"  size mismatch: {size_mismatch}")
    print(f"  no US symbol in map: {missing_us}")
    if missing_samples:
        print(f"  sample missing names: {', '.join(missing_samples)}")


if __name__ == "__main__":
    main()
