#!/usr/bin/env python3
"""Replace hardcoded 0x08xxxxxx data pointers in src/*.c inline asm with
label references, improving internal self-consistency.

Every exact match (address == a data/*.s label address) is rewritten as
`.4byte <label>`. Labels missing `.globl` get one added in their .s file.

Usage:
  python3 tools/link_hardcoded_addresses.py            # replace + rewrite
  python3 tools/link_hardcoded_addresses.py --check    # verify only
"""

import argparse
import glob
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]

PAT_LBL = re.compile(r"^(\w+):\s*@\s*0x([0-9A-Fa-f]{7,8})$")
PAT_GLOBL = re.compile(r"^\s*\.globl\s+(\w+)")
PAT_PTR = re.compile(r"(\.4byte\s+)0x(08[0-9A-Fa-f]{6})")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--check", action="store_true", help="verify only, no writes")
    args = ap.parse_args()

    labels = {}  # addr -> name
    globl = set()
    label_files = {}  # name -> path
    for f in sorted(glob.glob(str(ROOT / "data" / "*.s"))):
        lines = Path(f).read_text(encoding="utf-8", errors="replace").splitlines()
        for i, line in enumerate(lines):
            m = PAT_GLOBL.match(line)
            if m:
                globl.add(m.group(1))
            m = PAT_LBL.match(line)
            if m:
                addr = int(m.group(2), 16)
                labels.setdefault(addr, m.group(1))
                label_files.setdefault(m.group(1), (f, i))

    # Collect hardcoded addresses from src/*.c.
    src_files = sorted(glob.glob(str(ROOT / "src" / "*.c")))
    hard = []
    for f in src_files:
        for line in Path(f).read_text(encoding="utf-8", errors="replace").splitlines():
            m = PAT_PTR.search(line)
            if m:
                hard.append((int(m.group(2), 16), f))

    # Exact matches.
    exact = [(a, f) for a, f in hard if a in labels]
    print(f"hardcoded: {len(hard)}, exact label matches: {len(exact)}")

    # Add missing .globl (exact-match labels without .globl).
    need_globl = {}
    for a, _ in exact:
        name = labels[a]
        if name not in globl:
            need_globl.setdefault(name, label_files[name])
    print(f"labels needing .globl: {len(need_globl)}")

    if not args.check:
        # Add .globl lines.
        for name, (f, idx) in need_globl.items():
            lines = Path(f).read_text(encoding="utf-8", errors="replace").splitlines()
            indent = lines[idx][: len(lines[idx]) - len(lines[idx].lstrip())]
            lines.insert(idx, f"{indent}.globl {name}")
            Path(f).write_text("\n".join(lines) + "\n", encoding="utf-8")

        # Replace pointers in src files.
        exact_set = {(a, f) for a, f in exact}
        by_file = {}
        for a, f in exact_set:
            by_file.setdefault(f, []).append(a)
        for f, addrs in by_file.items():
            text = Path(f).read_text(encoding="utf-8", errors="replace")
            for a in addrs:
                text = text.replace(f".4byte 0x{a:08X}", f".4byte {labels[a]}")
            Path(f).write_text(text, encoding="utf-8")

    print(f"{'Check' if args.check else 'Replaced'}: {len(exact)} pointers "
          f"with label references")


if __name__ == "__main__":
    main()
