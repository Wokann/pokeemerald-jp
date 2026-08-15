#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Regenerate + verify all previously committed text regions (no lstrip)."""
import re
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

regions = [
    ("0x85A9D15", "0x85AB057", "data/data_b2d_rest.s"),
    ("0x82F4AB8", "0x82F4F2A", "data/data_b2d.s"),
    ("0x82F3A64", "0x82F3E80", "data/data_b2d.s"),
    ("0x82F4432", "0x82F4720", "data/data_b2d_mid2.s"),
    ("0x82F4F6A", "0x82F5196", "data/data_b2d_mid.s"),
    ("0x82F4738", "0x82F495E", "data/data_b2d_mid3.s"),
    ("0x82F3F98", "0x82F414E", "data/data_b2d_mid2.s"),
]

for i, (start, end, src) in enumerate(regions):
    tmp = f"vr{i}.h"
    subprocess.run(["python3", "tools/gen_region_texts.py", start, end, tmp], cwd=ROOT,
                   capture_output=True, text=True)
    out = subprocess.run(["python3", "tools/verify_region.py", "--src", src, "--header", tmp],
                         cwd=ROOT, capture_output=True, text=True)
    lines = out.stdout.strip().splitlines()
    print(f"region{i+1} {start}..{end}: {lines[0] if lines else 'NO OUTPUT'}")
    (ROOT / "src/data/text" / tmp).unlink(missing_ok=True)
