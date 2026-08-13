#!/usr/bin/env python3
"""Decode raw ROM bytes at a given address and print decoded script text.

Usage:
    python3 tools/decode_file_incbin.py 0x1dddf3 0x903
    python3 tools/decode_file_incbin.py gUnknown_81DDDF3
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
import decompile_scripts as d

def main():
    if len(sys.argv) >= 3 and sys.argv[1].startswith("0x"):
        rel = int(sys.argv[1], 16)
        size = int(sys.argv[2], 16)
        label = f"0x{rel:X}"
    else:
        label = sys.argv[1]
        inc = d.SCRIPTS_DIR / f"{label}.inc"
        text = inc.read_text(encoding="utf-8")
        m = re.search(r'\.incbin\s+"[^"]+",\s*0x([0-9A-Fa-f]+),\s*0x([0-9A-Fa-f]+)', text)
        if not m:
            sys.exit("not a single-incbin file")
        rel = int(m.group(1), 16)
        size = int(m.group(2), 16)
    raw = d.BIN.read_bytes()[rel - 0x1DABAC: rel - 0x1DABAC + size]
    opcode_table = d.build_opcode_table()
    by_name = {const: op for const, op in opcode_table.items()}
    formats, formats_by_name = d.build_macro_formats(by_name)
    specials = d.build_specials_map()
    dec = d.decode_chunk(raw, formats, specials)
    ok = d.encode_lines(dec, formats_by_name, specials) == raw
    print(f"# {label}: 0x{rel:X} size 0x{size:X} roundtrip={'OK' if ok else 'FAIL'}")
    print(dec)

if __name__ == "__main__":
    main()
