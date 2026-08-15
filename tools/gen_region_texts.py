#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Generate C text defs for a contiguous text region in data_b2d.s."""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from decode_rom_text import decode

rom = (ROOT / "baserom_jp.gba").read_bytes()


def _all_data_lines():
    """Symbol table from git HEAD so truncated working-tree .s files do not
    hide addresses that were already split into region C files."""
    import glob
    import subprocess
    lines = []
    for f in sorted(glob.glob(str(ROOT / "data" / "data_b2d*.s"))):
        name = Path(f).name
        try:
            raw = subprocess.run(
                ["git", "show", f"HEAD:data/{name}"],
                capture_output=True,
                cwd=ROOT,
            ).stdout
            if not raw:
                raw = Path(f).read_bytes()
        except Exception:
            raw = Path(f).read_bytes()
        lines += raw.decode("utf-8", errors="replace").splitlines()
    return lines


lines = _all_data_lines()

addrs = {}
for l in lines:
    m = re.match(r'^\s*(\w+):\s*@\s*0x([0-9A-Fa-f]+)', l)
    if m:
        addrs[m.group(1)] = int(m.group(2), 16)

# symbol -> is_text (next line has .string)
is_text_sym = set()
for i, l in enumerate(lines):
    m = re.match(r'^\s*(\w+):\s*@\s*0x([0-9A-Fa-f]+)', l)
    if m and i + 1 < len(lines) and ".string" in lines[i + 1]:
        is_text_sym.add(m.group(1))


def fmt_multi(name, s):
    parts = re.split(r"(\\[npl])", s)
    buf = ""
    ls = []
    for p in parts:
        if re.fullmatch(r"\\[npl]", p):
            ls.append(buf + p)
            buf = ""
        else:
            buf += p
    if buf:
        ls.append(buf)
    if len(ls) == 1:
        return f'const u8 {name}[] = _("{ls[0]}");'
    out = [f'const u8 {name}[] = _(']
    for i, ln in enumerate(ls):
        if i < len(ls) - 1:
            out.append(f'    "{ln}"')
        else:
            out.append(f'    "{ln}");')
    return "\n".join(out)


def gen_region(start, end, out_name):
    """Generate defs for text symbols with addr in [start, end)."""
    syms = sorted((a, n) for n, a in addrs.items() if start <= a < end)
    syms = [(a, n) for a, n in syms if n in is_text_sym]
    out_lines = []
    used = set()
    for va, name in syms:
        nxt = min((a for n2, a in addrs.items() if n2 != name and a > va), default=None)
        if nxt is None:
            continue
        raw = rom[va - 0x8000000: nxt - 0x8000000]
        if not raw:
            continue
        txt = decode(raw)
        # Keep $-separated sub-messages in ONE string: the game reads them
        # as separate messages delimited by FF, and preproc appends the
        # final EOS byte.  Dropping the empty segments (from consecutive
        # "$" terminators) or splitting into _sub symbols changes bytes.
        if txt.endswith("$$$"):
            txt = txt[:-1]
        elif txt.endswith("$$"):
            txt = txt[:-1]
        elif txt.endswith("$"):
            txt = txt[:-1]
        out_lines.append(fmt_multi(name, txt))
        out_lines.append("")
    out = ROOT / "src/data/text" / out_name
    out.write_text("\n".join(out_lines), encoding="utf-8")
    print(f"written {out}; defs: {sum(1 for l in out_lines if l.startswith('ALIGNED(4)'))}")


if __name__ == "__main__":
    import argparse
    ap = argparse.ArgumentParser()
    ap.add_argument("start", type=lambda x: int(x, 16))
    ap.add_argument("end", type=lambda x: int(x, 16))
    ap.add_argument("out")
    a = ap.parse_args()
    gen_region(a.start, a.end, a.out)
