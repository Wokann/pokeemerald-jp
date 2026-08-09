#!/usr/bin/env python3
"""Classify the .incbin chunks in data/event_scripts.s so they can be
converted into structured sources one by one.

For every chunk the script prints:
    index  label  ROM address  size  class  [entry count]

Classes:
    rom-ptr-table   all 4-byte words point into ROM code (.text)
    ram-ptr-table   all 4-byte words point into EWRAM/IWRAM
    mixed           words point to ROM and RAM
    raw-data        not a uniform pointer table

Usage:
    python3 tools/analyze_chunks.py
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ASM_FILE = ROOT / "data" / "event_scripts.s"
BIN_FILE = ROOT / "build" / "data" / "event_scripts.bin"

LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
INCINBIN_RE = re.compile(
    r'^\s*\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)\s*$'
)
LABEL_MAP_RE = re.compile(
    r"^\s*([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$"
)


def is_rom(w):
    return 0x08000000 <= w <= 0x09FFFFFF


def is_ewram(w):
    return 0x02000000 <= w <= 0x02FFFFFF


def is_iwram(w):
    return 0x03000000 <= w <= 0x03FFFFFF


def main():
    if not BIN_FILE.is_file():
        sys.exit(f"missing {BIN_FILE}; run make first")
    data = BIN_FILE.read_bytes()

    label_map = {}
    for path in sorted((ROOT / "asm").glob("*.s")):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = LABEL_MAP_RE.match(line)
            if m:
                label_map.setdefault(int(m.group(2), 16), m.group(1))

    chunks = []
    label = None
    for line in ASM_FILE.read_text(encoding="utf-8").splitlines():
        lm = LABEL_RE.match(line)
        if lm:
            label = lm.group(1)
            addr = int(lm.group(2), 16)
            continue
        m = INCINBIN_RE.match(line)
        if m:
            if label is None:
                sys.exit("incbin without preceding label")
            rel = int(m.group(1), 16)
            size = int(m.group(2), 16)
            chunks.append((label, addr, rel, size))
            label = None

    print(f"{'idx':>3} {'label':<24} {'addr':>9} {'size':>7} {'class':<16} entries  first targets")
    for i, (label, addr, rel, size) in enumerate(chunks):
        raw = data[rel : rel + size]
        if size % 4 == 0 and size >= 4:
            words = [int.from_bytes(raw[j : j + 4], "little") for j in range(0, size, 4)]
            n = len(words)
            rom = sum(1 for w in words if is_rom(w))
            ram = sum(1 for w in words if is_ewram(w) or is_iwram(w))
            if rom == n:
                kind = "rom-ptr-table"
            elif ram == n:
                kind = "ram-ptr-table"
            elif rom + ram == n:
                kind = "mixed"
            else:
                kind = "raw-data"
            targets = ""
            if kind in ("rom-ptr-table", "ram-ptr-table", "mixed"):
                shown = []
                for w in words[:8]:
                    t = label_map.get(w & ~1)
                    shown.append(t if t else f"0x{w:08X}")
                targets = " ".join(shown)
            print(f"{i:>3} {label:<24} 0x{addr:07X} 0x{size:05X} {kind:<16} {n:<6} {targets}")
        else:
            print(f"{i:>3} {label:<24} 0x{addr:07X} 0x{size:05X} {'raw-data':<16}")


if __name__ == "__main__":
    main()
