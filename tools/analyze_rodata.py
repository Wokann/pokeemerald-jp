#!/usr/bin/env python3
"""Classify pointer tables in data/data.s (the .rodata region).

Every 4-byte-aligned incbin chunk is read as words and classified by what
the words point to:

    code-ptr     all words point into ROM code (.text)
    ram-ptr      all words point into EWRAM/IWRAM
    rodata-ptr   all words point into this .rodata region
    script-ptr   all words point into the script-data region
    mixed        pointers to several regions
    data         not a uniform pointer table

Usage:
    python3 tools/analyze_rodata.py [top N]
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DATA_S = ROOT / "data" / "data.s"
BIN = ROOT / "build" / "data" / "data.bin"

RODATA_START = 0x08000000 + 0x29BDA4
RODATA_END = 0x09000000
SCRIPT_START = 0x08000000 + 0x1DABAC
SCRIPT_END = 0x08000000 + 0x28D2F8
REGION_START = 0x29BDA4

LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
INCINBIN_RE = re.compile(
    r'^\s*\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)\s*$'
)


def classify(word):
    if 0x08000000 <= word <= 0x09FFFFFF:
        if SCRIPT_START <= word < SCRIPT_END:
            return "script"
        if RODATA_START <= word < RODATA_END:
            return "rodata"
        return "code"
    if 0x02000000 <= word < 0x03000000 or 0x03000000 <= word < 0x04000000:
        return "ram"
    return "other"


def main():
    if not BIN.is_file():
        sys.exit(f"missing {BIN}; run make first")
    data = BIN.read_bytes()

    label_map = {}
    chunks = []
    label = None
    for line in DATA_S.read_text(encoding="utf-8").splitlines():
        lm = LABEL_RE.match(line)
        if lm:
            label = lm.group(1)
            addr = int(lm.group(2), 16)
            label_map[addr] = label
            continue
        m = INCINBIN_RE.match(line)
        if m:
            if label is None:
                continue
            rel = int(m.group(1), 16)
            size = int(m.group(2), 16)
            chunks.append((label, addr, rel, size))
            label = None

    counts = {}
    tables = []
    for label, addr, rel, size in chunks:
        if size % 4 != 0 or size < 4:
            continue
        raw = data[rel : rel + size]
        words = [int.from_bytes(raw[j : j + 4], "little") for j in range(0, size, 4)]
        kinds = {classify(w) for w in words}
        if kinds == {"code"}:
            kind = "code-ptr"
        elif kinds == {"ram"}:
            kind = "ram-ptr"
        elif kinds == {"rodata"}:
            kind = "rodata-ptr"
        elif kinds == {"script"}:
            kind = "script-ptr"
        elif kinds <= {"code", "rodata", "script", "ram"}:
            kind = "mixed"
        else:
            kind = "data"
        counts[kind] = counts.get(kind, 0) + 1
        if kind != "data":
            targets = [label_map.get(w, f"0x{w:08X}") for w in words[:6]]
            tables.append((kind, label, addr, size, len(words), targets))

    print("class counts:", counts)
    print(f"{'kind':<11} {'label':<24} {'addr':>9} {'size':>7} {'n':>5}  first targets")
    for kind, label, addr, size, n, targets in sorted(tables, key=lambda t: -t[4]):
        shown = " ".join(targets[:5])
        print(f"{kind:<11} {label:<24} 0x{addr:07X} 0x{size:05X} {n:>5}  {shown}")


if __name__ == "__main__":
    main()
