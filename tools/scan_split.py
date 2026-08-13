#!/usr/bin/env python3
"""Dry-run split_decode over every raw .incbin chunk, listing those with a
decodable script prefix."""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import decompile_scripts as d
import split_decode as sd

def main():
    if not d.BIN.is_file():
        sys.exit(f"missing {d.BIN}")
    data = d.BIN.read_bytes()
    opcode_table = d.build_opcode_table()
    by_name = {const: op for const, op in opcode_table.items()}
    formats, formats_by_name = d.build_macro_formats(by_name)
    specials = d.build_specials_map()

    rows = []
    for path in sorted((d.SCRIPTS_DIR).glob("gUnknown_*.inc")):
        text = path.read_text(encoding="utf-8")
        m = re.search(r'\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)', text)
        if not m:
            continue
        rel = int(m.group(1), 16)
        size = int(m.group(2), 16)
        raw = data[rel - 0x1DABAC: rel - 0x1DABAC + size]
        if len(raw) < size:
            continue
        lines, stop = sd.split(raw, formats, specials)
        if stop >= 4:  # at least a few real script bytes
            rows.append((path.stem, rel, size, stop, len(lines)))

    rows.sort(key=lambda r: -r[3])
    print(f"chunks with script prefix: {len(rows)}")
    print(f"{'label':<22} {'rom':<9} {'size':<7} {'decoded':<9} lines")
    for name, rel, size, stop, nl in rows:
        print(f"{name:<22} 0x{rel:X} 0x{size:X} 0x{stop:X} {nl}")

if __name__ == "__main__":
    main()
