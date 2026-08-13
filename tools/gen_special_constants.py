#!/usr/bin/env python3
"""Generate asm .equ constants for SPECIAL_<name> and
SPECIAL_WAITSTATE_<name> from data/specials.inc."""

import re
from pathlib import Path

ROOT = Path('/home/kenny/pokeemerald-jp')
out = []
idx = 0
for line in (ROOT / 'data' / 'specials.inc').read_text(
        encoding='utf-8').splitlines():
    m = re.match(r'\s*def_special\s+(\w+)(?:\s*,\s*(?:waitstate=)?(\d+))?', line)
    if m:
        name = m.group(1)
        ws = int(m.group(2) or 0)
        out.append('.equ SPECIAL_%s, %d' % (name, idx))
        out.append('.equ SPECIAL_WAITSTATE_%s, %d' % (name, ws))
        idx += 1
p = ROOT / 'constants' / 'specials_constants.inc'
p.write_text('\n'.join(out) + '\n', encoding='utf-8')
print('wrote', p, len(out), 'lines')
