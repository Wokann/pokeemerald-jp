#!/usr/bin/env python3
"""Split raw .incbin chunks in data/data.s at the addresses referenced by
a pointer table, labelling every referenced address, and convert the
table itself into a symbolic .4byte list.

Usage:
    python3 tools/split_rodata.py <table-label>
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DATA_S = ROOT / "data" / "data.s"
BIN = ROOT / "build" / "data" / "data.bin"

REGION_START = 0x29BDA4
RODATA_BASE = 0x08000000
RODATA_END_ADDR = 0x09000000

LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
INCINBIN_RE = re.compile(
    r'^(\s*\.incbin\s+"[^"]+",\s*0x[0-9A-Fa-f]+,\s*0x[0-9A-Fa-f]+\s*)$'
)


def main():
    if not BIN.is_file():
        sys.exit(f"missing {BIN}; run make first")
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    target = sys.argv[1]
    data = BIN.read_bytes()
    lines = DATA_S.read_text(encoding="utf-8").splitlines(keepends=True)

    chunks = []  # (label, addr, size, incbin_line_index)
    label = None
    for i, line in enumerate(lines):
        lm = LABEL_RE.match(line.rstrip("\r\n"))
        if lm:
            label = lm.group(1)
            addr = int(lm.group(2), 16)
            continue
        m = INCINBIN_RE.match(line)
        if m:
            if label is None:
                sys.exit("incbin without label")
            size = int(re.search(r",\s*0x([0-9A-Fa-f]+)\s*$", line.rstrip("\r\n")).group(1), 16)
            chunks.append((label, addr, size, i))
            label = None

    # Find the table chunk and read its targets.
    table = next((c for c in chunks if c[0] == target), None)
    if table is None:
        sys.exit(f"no chunk named {target}")
    _, table_addr, table_size, _ = table
    rel = table_addr - (RODATA_BASE + REGION_START)
    words = [
        int.from_bytes(data[rel + j : rel + j + 4], "little")
        for j in range(0, table_size, 4)
    ]
    if not all(RODATA_BASE <= w < RODATA_END_ADDR for w in words):
        sys.exit(f"{target}: not a rodata pointer table")
    targets = set(words)

    existing = {addr for _, addr, _, _ in chunks}
    split_at = sorted(t for t in targets if t not in existing)
    print(f"{len(split_at)} targets to label")

    # Rewrite: split chunks at targets and convert the table.
    out = []
    chunk_index = 0
    for i, line in enumerate(lines):
        if chunk_index < len(chunks) and i == chunks[chunk_index][3]:
            label, addr, size, _ = chunks[chunk_index]
            if label == target:
                for j, w in enumerate(words):
                    name = f"gUnknown_{w:07X}"
                    out.append(f"\t.4byte {name:<28} @ {j:03d}\n")
                chunk_index += 1
                continue
            pieces = [addr] + [t for t in split_at if addr < t < addr + size] + [addr + size]
            for k in range(len(pieces) - 1):
                piece_addr = pieces[k]
                piece_size = pieces[k + 1] - piece_addr
                rel = piece_addr - (RODATA_BASE + REGION_START)
                if k > 0:
                    out.append(f"gUnknown_{piece_addr:07X}: @ 0x{piece_addr:07X}\n")
                out.append(f'\t.incbin "{BIN.relative_to(ROOT).as_posix()}", 0x{rel:x}, 0x{piece_size:x}\n')
            chunk_index += 1
            continue
        out.append(line)

    if chunk_index != len(chunks):
        sys.exit(f"processed {chunk_index}/{len(chunks)} chunks")
    DATA_S.write_text("".join(out), encoding="utf-8")
    print(f"wrote {DATA_S}")


if __name__ == "__main__":
    main()
