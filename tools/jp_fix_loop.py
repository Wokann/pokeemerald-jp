#!/usr/bin/env python3
"""Iterate: make -> collect undefined gJPText_ addrs -> locate .string lines
in retained blocks by walking byte offsets -> insert labels -> repeat."""

import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import jp_fix_block as fb


def undefined_addrs(log):
    return sorted({0x08000000 + int(m.group(1), 16)
                   for m in re.finditer(r'undefined reference to `gJPText_([0-9A-Fa-f]+)', log)})


def main():
    for it in range(20):
        # force rebuild of event_scripts.o (data/scripts/*.inc changed)
        obj = ROOT / 'build' / 'pokeemerald-jp' / 'data' / 'event_scripts.o'
        obj.unlink(missing_ok=True)
        r = subprocess.run(['make'], cwd=ROOT, capture_output=True, text=True)
        addrs = undefined_addrs(r.stdout + r.stderr)
        if r.returncode == 0 and not addrs:
            print('CLEAN after %d iterations' % it)
            return 0
        print('iter %d: rc=%d undefined=%d' % (it, r.returncode, len(addrs)))
        if addrs:
            print('  ', [hex(a) for a in addrs[:6]])
        fb.process(addrs)
    print('still failing')
    return 1


if __name__ == '__main__':
    sys.exit(main())
