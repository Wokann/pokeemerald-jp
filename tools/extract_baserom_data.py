#!/usr/bin/env python3
"""Extract .incbin chunks from data/*.s into repo-owned binary assets, so
the build no longer depends on baserom_jp.gba.

Each chunk in the .s files is introduced by a symbol whose comment records
its absolute ROM address, e.g.::

    gUnknown_81DABAC: @ 0x81DABAC
        .incbin "baserom_jp.gba", 0x1dabac, 0x384

The absolute offset is derived from that label, which makes the script
idempotent (it can be re-run safely even if the .incbin lines were already
rewritten).  Each source .s file maps to one contiguous .bin file covering
the full region it references; the .incbin lines are rewritten to read from
the extracted file with a relative offset, keeping every byte identical.

Usage:
    python3 tools/extract_baserom_data.py [baserom.gba]

The default baserom is baserom_jp.gba in the project root.
"""

import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
BASEROM_DEFAULT = ROOT / "baserom_jp.gba"

# source .s file -> output .bin file (paths relative to the repo root).
# The output files are generated artifacts under build/, which is ignored
# by git, so no ROM-derived binary data is ever committed.
SOURCES = {
    "data/event_scripts.s": "build/data/event_scripts.bin",
    "data/data.s": "build/data/data.bin",
    "data/data_rest.s": "build/data/data_rest.bin",
}

# Fixed start of each region in the ROM.  Kept constant so re-running the
# script is stable even when chunks at the region start are replaced by
# structured sources (and therefore no longer appear as .incbin lines).
REGION_START = {
    "data/event_scripts.s": 0x1DABAC,
    "data/data.s": 0x29BDA4,
    "data/data_rest.s": 0x89158E0,
}

# Fixed multiboot program chunks extracted from the JP ROM.  These are
# standalone GBA multiboot ROMs embedded in the main ROM (e-Reader driver
# and the berry-glitch-fix program); the JP ROM has no colosseum program,
# unlike the US build.
MB_CHUNKS = {
    "build/data/mb_ereader.gba": (0x0890F374, 0x30E0),
    "build/data/mb_berry_fix.gba": (0x08912454, 0x348C),
}

INCINBIN_RE = re.compile(
    r'^(\s*\.incbin\s+)"[^"]+",\s*(0x[0-9A-Fa-f]+)'
    r'(,\s*)(0x[0-9A-Fa-f]+)(\s*)$'
)
LABEL_RE = re.compile(r'^[A-Za-z_][A-Za-z0-9_]*:\s*@\s*0x([0-9A-Fa-f]+)\s*$')


def main():
    baserom = Path(sys.argv[1]) if len(sys.argv) > 1 else BASEROM_DEFAULT
    if not baserom.is_file():
        sys.exit(f"baserom not found: {baserom}")
    rom = baserom.read_bytes()

    for src_rel, bin_rel in SOURCES.items():
        src = ROOT / src_rel
        out = ROOT / bin_rel

        lines = src.read_text(encoding="utf-8").splitlines(keepends=True)
        chunks = []  # (offset, length) for every .incbin line
        label_addr = None
        for line in lines:
            lm = LABEL_RE.match(line.rstrip("\r\n"))
            if lm:
                label_addr = int(lm.group(1), 16) & 0xFFFFFF
                continue
            m = INCINBIN_RE.match(line)
            if m:
                if label_addr is None:
                    sys.exit(f"{src_rel}: .incbin without a preceding symbol label")
                listed_off = int(m.group(2), 16)
                # The label is authoritative; tolerate pre-rewritten files
                # whose listed offset is already relative.
                chunks.append((label_addr, int(m.group(4), 16)))

        if not chunks:
            print(f"{src_rel}: no .incbin lines, skipping")
            continue

        start = min(REGION_START[src_rel], min(off for off, _ in chunks))
        end = max(off + length for off, length in chunks)
        if end > len(rom):
            sys.exit(f"{src_rel}: region end 0x{end:x} exceeds ROM size 0x{len(rom):x}")

        # Gaps between consecutive chunks are still filled with ROM bytes so
        # the extracted file stays a faithful copy of the whole region.
        gaps = 0
        prev_end = start
        for off, length in sorted(chunks):
            if off > prev_end:
                gaps += off - prev_end
            prev_end = max(prev_end, off + length)

        out.parent.mkdir(parents=True, exist_ok=True)
        out.write_bytes(rom[start:end])

        chunks_iter = iter(chunks)

        def rewrite(m):
            off, length = next(chunks_iter)
            return (
                f"{m.group(1)}\"{bin_rel}\", 0x{off - start:x}"
                f"{m.group(3)}0x{length:x}{m.group(5)}"
            )

        new_lines = [INCINBIN_RE.sub(rewrite, line) for line in lines]
        src.write_text("".join(new_lines), encoding="utf-8")

        print(
            f"{src_rel}: {len(chunks)} chunks -> {bin_rel} "
            f"(0x{start:x}..0x{end:x}, {end - start} bytes, "
            f"{gaps} gap bytes filled)"
        )

    for bin_rel, (mb_addr, mb_size) in MB_CHUNKS.items():
        out = ROOT / bin_rel
        out.parent.mkdir(parents=True, exist_ok=True)
        off = mb_addr & 0xFFFFFF
        out.write_bytes(rom[off : off + mb_size])
        print(f"{bin_rel}: {mb_size} bytes from 0x{mb_addr:x}")

    print("done")


if __name__ == "__main__":
    main()
