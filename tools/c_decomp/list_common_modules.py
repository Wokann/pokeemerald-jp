#!/usr/bin/env python3
"""List asm modules whose base name exists as a pokeemerald src C file."""
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
us_src = ROOT.parent / "pokeemerald" / "src"
us_names = {p.stem for p in us_src.glob("*.c")}
common = sorted(p.stem for p in (ROOT / "asm").glob("*.s") if p.stem in us_names)
for name in common:
    jp_lines = len((ROOT / "asm" / f"{name}.s").read_text(encoding="utf-8").splitlines())
    us_lines = len((us_src / f"{name}.c").read_text(encoding="utf-8").splitlines())
    print(f"{name:42s} jp={jp_lines:5d} us={us_lines:5d}")
