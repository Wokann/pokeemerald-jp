#!/usr/bin/env python3
"""Extract JP gToneData voice-data tails from baserom_jp.gba.

Each gToneData_* in data/data_b2c_mid8_tail.s has a 12-byte struct header
(type/key/pan + wav pointer + a/d/s/r) followed by an incbin holding the
voice/keysplit data up to the next label. The tails are extracted as
sound/tone_data/gToneData_<addr>_voice.bin and the incbin lines are rewritten
to reference them, keeping the ROM byte order unchanged.

Usage:
  python3 tools/extract_tone_data.py            # extract + rewrite .s
  python3 tools/extract_tone_data.py --check    # verify only
"""

import argparse
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_PATH = ROOT / "baserom_jp.gba"
S_PATH = ROOT / "data" / "data_b2c_mid8_tail.s"
OUT_DIR = ROOT / "sound" / "tone_data"

PAT_TONE = re.compile(r"^gToneData_([0-9A-Fa-f]+):\s*@\s*0x([0-9A-Fa-f]+)$")
PAT_INC = re.compile(
    r'\s*\.incbin\s+"baserom_jp\.gba",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)'
)
PAT_LABEL = re.compile(r"^(\w+):\s*@\s*0x([0-9A-Fa-f]+)$")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    rom = ROM_PATH.read_bytes()
    raw = S_PATH.read_bytes()
    crlf = b"\r\n" in raw
    lines = raw.decode("utf-8").split("\r\n" if crlf else "\n")

    # Build label address table for next-label boundary detection.
    labels = {}
    for line in lines:
        m = PAT_LABEL.match(line)
        if m:
            labels[int(m.group(2), 16)] = m.group(1)

    entries = []
    for i, line in enumerate(lines):
        m = PAT_TONE.match(line)
        if not m:
            continue
        addr = int(m.group(2), 16)
        struct_end = addr + 12
        nxt = min((a for a in labels if a > struct_end), default=None)
        if nxt is None:
            sys.exit(f"gToneData_{m.group(1)}: no next label")
        entries.append((m.group(1), addr, struct_end, nxt, i))

    problems = []
    new_lines = list(lines)
    for suffix, addr, struct_end, nxt, idx in entries:
        data = rom[struct_end - 0x08000000 : nxt - 0x08000000]
        out_path = OUT_DIR / f"gToneData_{suffix}_voice.bin"
        # Find the incbin line after the struct and verify it matches.
        inc_match = None
        inc_rel = 0
        for j in range(1, 8):
            im = PAT_INC.match(lines[idx + j])
            if im:
                inc_match = im
                inc_rel = j
                break
        if inc_match:
            off = int(inc_match.group(1), 16)
            size = int(inc_match.group(2), 16)
            if off != struct_end - 0x08000000 or off + size != nxt - 0x08000000:
                problems.append(
                    f"{suffix}: incbin 0x{off:X}+0x{size:X} != tail "
                    f"0x{struct_end - 0x08000000:X}..0x{nxt - 0x08000000:X}"
                )
                continue
            if not args.check:
                OUT_DIR.mkdir(parents=True, exist_ok=True)
                out_path.write_bytes(data)
                new_lines[idx + inc_rel] = (
                    f'\t.incbin "sound/tone_data/gToneData_{suffix}_voice.bin"'
                )
        elif not args.check:
            problems.append(f"{suffix}: no incbin after struct")

    if problems:
        print("PROBLEMS:")
        for p in problems[:20]:
            print("  ", p)
        sys.exit(1)

    if not args.check:
        S_PATH.write_bytes(("\r\n".join(new_lines) if crlf else "\n".join(new_lines)).encode("utf-8"))
    print(f"{'Check' if args.check else 'Extracted'}: {len(entries)} tone data tails "
          f"-> {OUT_DIR}")


if __name__ == "__main__":
    main()
