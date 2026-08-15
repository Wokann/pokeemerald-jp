#!/usr/bin/env python3
"""Iteratively fix undefined gJPText_ symbols:
extract them from linker errors, locate the .string via charmap byte
match, insert labels, rebuild, repeat until clean."""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_match_labels as jml


def undefined_symbols(log_text):
    addrs = set()
    for m in re.finditer(r'undefined reference to `(gJPText_[0-9A-Fa-f]+)', log_text):
        addrs.add(0x08000000 + int(m.group(1)[len('gJPText_'):], 16))
    return sorted(addrs)


def main():
    for it in range(12):
        r = subprocess.run(['make'], cwd=ROOT, capture_output=True, text=True)
        missing = undefined_symbols(r.stdout + r.stderr)
        if not missing:
            print('BUILD OK on iteration', it)
            print((r.stdout + r.stderr)[-400:])
            return 0
        print('iter %d: %d undefined' % (it, len(missing)))
        jml.process_addrs(missing)
    print('still failing after iterations')
    return 1


if __name__ == '__main__':
    sys.exit(main())
