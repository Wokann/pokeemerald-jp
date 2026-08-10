#!/usr/bin/env python3
"""Check which functions in src/text.c still DIFF against the JP ROM."""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import convert_c

res = convert_c.verify_c_file(Path(__file__).resolve().parents[2] / "src" / "text.c")
for r in res:
    if not r["ok"]:
        print("DIFF", r["name"], hex(r.get("addr", 0)), r.get("error", ""))
print("matched", sum(1 for r in res if r["ok"]), "/", len(res))
