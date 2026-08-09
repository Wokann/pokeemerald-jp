#!/usr/bin/env python3
"""Split raw .incbin chunks at the addresses referenced by in-region
pointer tables, giving every referenced address a named label, and
convert those pointer tables into symbolic .4byte lists.

This makes the structure of the script-data region visible: the pointer
table targets become labelled script/data boundaries inside the formerly
opaque raw chunks.

Usage:
    python3 tools/split_script_region.py
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ASM_FILE = ROOT / "data" / "event_scripts.s"
BIN_FILE = ROOT / "build" / "data" / "event_scripts.bin"

REGION_START = 0x1DABAC
REGION_END = 0x28D2F8
REGION_BASE = 0x08000000

LABEL_RE = re.compile(r"^([A-Za-z_][A-Za-z0-9_]*):\s*@\s*0x([0-9A-Fa-f]+)\s*$")
INCINBIN_RE = re.compile(
    r'^(\s*\.incbin\s+"[^"]+",\s*0x[0-9A-Fa-f]+,\s*0x[0-9A-Fa-f]+\s*)$'
)
SYM_RE = re.compile(r"^gUnknown_([0-9A-Fa-f]+) = \.;")


def in_region(addr):
    return REGION_BASE + REGION_START <= addr < REGION_BASE + REGION_END


def ram_symbols():
    names = set()
    for path in (ROOT / "sym_ewram_jp.txt", ROOT / "sym_iwram_jp.txt"):
        for line in path.read_text(encoding="utf-8").splitlines():
            m = SYM_RE.match(line)
            if m:
                names.add(f"gUnknown_{m.group(1).upper()}")
    return names


def main():
    if not BIN_FILE.is_file():
        sys.exit(f"missing {BIN_FILE}; run make first")
    data = BIN_FILE.read_bytes()
    lines = ASM_FILE.read_text(encoding="utf-8").splitlines(keepends=True)
    ram_syms = ram_symbols()

    # First pass: collect chunks (label, addr, size) and the pointer-table
    # chunks (with their target addresses).
    chunks = []  # (line_index_of_label, label, addr, size, incbin_line_index)
    current = None
    table_targets = []  # (incbin_line_index, [targets...])
    for i, line in enumerate(lines):
        lm = LABEL_RE.match(line.rstrip("\r\n"))
        if lm:
            current = [i, lm.group(1), int(lm.group(2), 16), None, None]
            continue
        m = INCINBIN_RE.match(line)
        if m and current is not None:
            _, label, addr, size, _ = current
            # incbin rel offset is not needed; size matters.
            size_str = re.search(r",\s*0x([0-9A-Fa-f]+)\s*$", line.rstrip("\r\n"))
            size = int(size_str.group(1), 16)
            current[3] = size
            current[4] = i
            chunks.append(tuple(current))
            current = None

    # Classify pointer-table chunks and collect in-region targets.
    split_at = set()
    for _, label, addr, size, inc_i in chunks:
        if size % 4 != 0 or size < 4:
            continue
        raw = data[(addr & 0xFFFFFF) - REGION_START : (addr & 0xFFFFFF) - REGION_START + size]
        words = [int.from_bytes(raw[j : j + 4], "little") for j in range(0, size, 4)]
        if all(in_region(w) for w in words):
            for w in words:
                split_at.add(w)

    existing = {addr for _, _, addr, _, _ in chunks}
    split_at -= existing
    split_at = sorted(split_at)
    print(f"{len(split_at)} in-region targets to label")

    # Second pass: rewrite lines, splitting chunks and converting tables.
    out = []
    chunk_index = 0
    for i, line in enumerate(lines):
        if chunk_index < len(chunks) and i == chunks[chunk_index][4]:
            _, label, addr, size, _ = chunks[chunk_index]
            raw = data[(addr & 0xFFFFFF) - REGION_START : (addr & 0xFFFFFF) - REGION_START + size]
            words = [int.from_bytes(raw[j : j + 4], "little") for j in range(0, size, 4)]
            if all(in_region(w) for w in words):
                # Convert to a symbolic pointer list.
                for j, w in enumerate(words):
                    out.append(f"\t.4byte {target_name(w)}                  @ {j:03d}\n")
                chunk_index += 1
                continue
            if (
                all(0x02000000 <= w < 0x04000000 and w % 2 == 0 for w in words)
                and all(f"gUnknown_{w:X}" in ram_syms for w in words)
            ):
                # EWRAM/IWRAM pointer table: reference linker symbols.
                for j, w in enumerate(words):
                    out.append(f"\t.4byte {ram_target_name(w)}              @ {j:03d}\n")
                chunk_index += 1
                continue
            # Raw data: split at in-region target addresses.
            pieces = [addr]
            pieces += [t for t in split_at if addr < t < addr + size]
            pieces.append(addr + size)
            for k in range(len(pieces) - 1):
                piece_addr = pieces[k]
                piece_size = pieces[k + 1] - piece_addr
                rel = (piece_addr & 0xFFFFFF) - REGION_START
                if k > 0:
                    out.append(f"gUnknown_{piece_addr:07X}: @ 0x{piece_addr:07X}\n")
                out.append(f'\t.incbin "{BIN_FILE.relative_to(ROOT).as_posix()}", 0x{rel:x}, 0x{piece_size:x}\n')
            chunk_index += 1
            continue
        out.append(line)

    if chunk_index != len(chunks):
        sys.exit(f"processed {chunk_index}/{len(chunks)} chunks")
    ASM_FILE.write_text("".join(out), encoding="utf-8")
    print(f"wrote {ASM_FILE}")


def target_name(addr):
    return f"gUnknown_{addr:07X}"


def ram_target_name(addr):
    return f"gUnknown_{addr:X}"


if __name__ == "__main__":
    main()
