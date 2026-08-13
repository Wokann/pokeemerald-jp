#!/usr/bin/env python3
"""Remove duplicate gJPText_ label definitions from data/scripts/*.inc."""

import re
from pathlib import Path

ROOT = Path('/home/kenny/pokeemerald-jp')


def dedup(path):
    lines = path.read_text(encoding='utf-8').splitlines(keepends=True)
    seen = set()
    new_lines = []
    i = 0
    removed = 0
    while i < len(lines):
        s = lines[i].strip()
        m = re.match(r'^\.globl\s+(gJPText_[0-9A-Fa-f]+)$', s)
        if m and m.group(1) in seen:
            # remove .globl and the following label line if present
            removed += 1
            i += 1
            if i < len(lines) and lines[i].strip().startswith('gJPText_'):
                removed += 1
                i += 1
            continue
        if m:
            seen.add(m.group(1))
        new_lines.append(lines[i])
        i += 1
    if removed:
        path.write_text(''.join(new_lines), encoding='utf-8')
    return removed


def main():
    total = 0
    for p in sorted((ROOT / 'data' / 'scripts').glob('gUnknown_*.inc')):
        n = dedup(p)
        if n:
            print('%s: removed %d lines' % (p.name, n))
            total += n
    print('total removed:', total)


if __name__ == '__main__':
    main()
