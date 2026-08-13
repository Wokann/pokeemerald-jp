#!/usr/bin/env python3
"""Assess decode quality of converted script files.

Flags files whose decoded instructions carry implausible pointer arguments
(addresses outside ROM/RAM) or an excessive share of raw .byte lines.
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
SCRIPTS = ROOT / "data" / "scripts"

CTRL_RE = re.compile(r"^\s*(goto|goto_if|call|call_if|gotostd|goto_if_set|"
                     r"goto_if_unset|goto_if_equal|goto_if_not_equal|"
                     r"callstd|callstd_if|msgbox|message|special|specialvar)\b")
ARG_RE = re.compile(r"0x([0-9A-Fa-f]{7,8})\b")

def plausible_addr(v):
    a = int(v, 16)
    return (0x08000000 <= a <= 0x09FFFFFF) or (0x02000000 <= a < 0x04000000)

def plausible_arg(v):
    a = int(v, 16)
    # Small immediates (flags, ids, coords) are fine; big non-ROM/RAM
    # words are a strong sign of data misdecoded as script.
    return a < 0x4000000 or 0x08000000 <= a <= 0x09FFFFFF

bad = []
ok = []
for path in sorted(SCRIPTS.glob("gUnknown_*.inc")):
    text = path.read_text(encoding="utf-8")
    if ".incbin" in text or ".string" in text or "gJPText" in text:
        continue
    lines = text.splitlines()
    total = len([l for l in lines if l.strip()])
    raw_bytes = len([l for l in lines if l.strip().startswith(".byte")])
    # collect control-flow arg addresses
    implaus = 0
    ctrl = 0
    bad_args = 0
    for l in lines:
        if CTRL_RE.match(l):
            ctrl += 1
            for m in ARG_RE.finditer(l):
                if not plausible_addr(m.group(1)):
                    implaus += 1
        for m in ARG_RE.finditer(l):
            if not plausible_arg(m.group(1)):
                bad_args += 1
    if total == 0:
        continue
    byte_ratio = raw_bytes / total
    if (byte_ratio > 0.5 or (ctrl == 0 and raw_bytes > 0) or implaus >= 1
            or bad_args >= 2):
        bad.append((path.stem, len(text), total, raw_bytes, ctrl, implaus, bad_args))
    else:
        ok.append((path.stem, len(text), total, raw_bytes, ctrl, implaus, bad_args))

print(f"ok: {len(ok)}, suspect: {len(bad)}")
print("\n--- suspect ---")
for name, size, total, raw, ctrl, imp, badargs in bad:
    print(f"{name}: {size}B lines={total} raw={raw} ctrl={ctrl} implaus={imp} badargs={badargs}")
