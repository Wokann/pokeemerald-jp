#!/usr/bin/env python3
"""List raw chunks that are referenced by event_scripts.s and have a
decodable script prefix (from scan_split logic)."""
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

    ev = (ROOT / "data" / "event_scripts.s").read_text(encoding="utf-8")
    rows = []
    for path in sorted((d.SCRIPTS_DIR).glob("gUnknown_*.inc")):
        name = path.stem
        # referenced?
        if not re.search(rf'\.include\s+"data/scripts/{name}\.inc"', ev):
            continue
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
        if stop >= 4:
            rows.append((name, rel, size, stop, len(lines)))

    rows.sort(key=lambda r: -r[3])
    print(f"referenced raw chunks with script prefix: {len(rows)}")
    for name, rel, size, stop, nl in rows:
        pct = 100.0 * stop / size if size else 0
        print(f"{name:<22} 0x{rel:X} 0x{size:X} 0x{stop:X} {nl:4d} {pct:5.1f}%")

if __name__ == "__main__":
    main()
