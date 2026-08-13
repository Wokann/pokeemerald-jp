#!/usr/bin/env python3
"""Replace the leading raw .incbin of a chunk with split-decoded script.

Keeps any following .string/gJPText definitions and trailing incbin
lines untouched.  For a pure single-incbin file the decoded tail is
re-emitted as a new .incbin line.

Usage: python3 tools/split_convert.py gUnknown_826240A
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import decompile_scripts as d
import split_decode as sd

def main():
    label = sys.argv[1]
    inc = d.SCRIPTS_DIR / f"{label}.inc"
    lines = inc.read_text(encoding="utf-8").splitlines()
    idx = None
    m = None
    for i, l in enumerate(lines):
        m = re.search(r'\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)', l)
        if m:
            idx = i
            break
    if m is None or idx is None:
        sys.exit("no .incbin line found")
    rel = int(m.group(1), 16)
    size = int(m.group(2), 16)
    raw = d.BIN.read_bytes()[rel - 0x1DABAC: rel - 0x1DABAC + size]
    opcode_table = d.build_opcode_table()
    by_name = {const: op for const, op in opcode_table.items()}
    formats, formats_by_name = d.build_macro_formats(by_name)
    specials = d.build_specials_map()
    dec_lines, stop = sd.split(raw, formats, specials)
    if stop == 0:
        sys.exit("nothing decodable in first incbin")

    script_lines = [l.rstrip() for l in dec_lines]
    if stop < size:
        script_lines.append(
            f'\t.incbin "baserom_jp.gba", 0x{rel + stop:X}, 0x{size - stop:X}')

    out = []
    for i, l in enumerate(lines):
        if i == idx:
            out.extend(script_lines)
        else:
            out.append(l.rstrip())
    inc.write_text("\n".join(out) + "\n", encoding="utf-8")
    print(f"wrote {label}.inc: {stop:#x} decoded, tail {size - stop:#x} incbin, "
          f"{len(lines) - 1} other lines kept")

if __name__ == "__main__":
    main()
