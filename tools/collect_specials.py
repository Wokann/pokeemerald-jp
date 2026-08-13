#!/usr/bin/env python3
"""Collect special calls used by decoded script chunks, grouped by file."""
import re
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SCRIPTS = ROOT / "data" / "scripts"

per_file = {}
overall = Counter()
for path in sorted(SCRIPTS.glob("gUnknown_*.inc")):
    text = path.read_text(encoding="utf-8")
    if ".incbin" in text or ".string" in text or "gJPText" in text:
        continue
    specials = re.findall(r"^\s*special(?:var)?\s+([A-Za-z0-9_]+)", text, re.M)
    if specials:
        per_file[path.stem] = specials
        overall.update(specials)

print("files with specials:", len(per_file))
print("\n--- top specials overall ---")
for name, cnt in overall.most_common(80):
    print(f"{cnt:4d} {name}")

print("\n--- files and their specials ---")
for fname, sps in sorted(per_file.items()):
    print(fname, "->", ", ".join(dict.fromkeys(sps)))
