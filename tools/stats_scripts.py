#!/usr/bin/env python3
"""Classify data/scripts files: decoded, mixed (text+script), raw incbin."""
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SCRIPTS = ROOT / "data" / "scripts"

decoded = []
mixed = []
raw = []
for p in sorted(SCRIPTS.glob("gUnknown_*.inc")):
    t = p.read_text(encoding="utf-8", errors="replace")
    if ".incbin" in t:
        raw.append(p.name)
    elif ".string" in t or "gJPText" in t:
        mixed.append(p.name)
    else:
        decoded.append(p.name)

# feature files (non gUnknown)
feat = sorted(p.name for p in SCRIPTS.glob("*.inc") if not p.name.startswith("gUnknown_"))

print("decoded (script-only):", len(decoded))
print("mixed (script+text):  ", len(mixed))
print("raw incbin:           ", len(raw))
print("feature files:        ", len(feat), feat)
print()
print("--- decoded list ---")
for n in decoded:
    print(n)
