import re
from pathlib import Path

ROOT = Path('/home/kenny/pokeemerald-jp')

for fn in ('data/data_b.s', 'data/data.s'):
    lines = (ROOT / fn).read_text(encoding='utf-8').splitlines()
    labels = []
    for i, line in enumerate(lines):
        m = re.match(r'^gUnknown_([0-9A-Fa-f]+):\s*@\s*0x([0-9A-Fa-f]+)', line)
        if m:
            labels.append((int(m.group(2), 16), m.group(1), i))
    for addr in (0x084FD020, 0x0856ECE8, 0x082BF310, 0x085AD0A8):
        prev = None
        for a, name, i in labels:
            if a <= addr:
                prev = (a, name, i)
            if a > addr:
                break
        if prev:
            print('%s: %08X in %s (gUnknown_%s @ %08X, line %d)' % (
                fn, addr, fn, prev[1], prev[0], prev[2]))
