import re
import subprocess
from pathlib import Path

ROOT = Path('/home/kenny/pokeemerald-jp')
nm = ROOT / 'tools' / 'binutils' / 'bin' / 'arm-none-eabi-nm'
r = subprocess.run([str(nm), '-n', str(ROOT / 'build' / 'pokeemerald-jp' / 'data' / 'event_scripts.o')],
                   capture_output=True, text=True)
syms = {}
for line in r.stdout.splitlines():
    parts = line.split()
    if len(parts) >= 3:
        syms[parts[2]] = int(parts[0], 16)

import sys
sys.path.insert(0, str(ROOT / 'tools'))
import jp_emit_maps as em

entries = em.map_entries()
for i, (ms, mname, gi, mi, ents, ev) in enumerate(entries):
    end = entries[i + 1][0] if i + 1 < len(entries) else 0x82423AF
    sym = syms.get(mname + '_MapScripts')
    if sym is None:
        continue
    expected = ms - 0x81DABAC
    if sym != expected:
        print('MISALIGN %s: .o offset %08X expected %08X (delta %+d)' % (
            mname, sym, expected, sym - expected))
        if i > 0:
            prev_name = entries[i - 1][1]
            prev_sym = syms.get(prev_name + '_MapScripts')
            print('  prev %s at %08X, region %08X-%08X (%d bytes)' % (
                prev_name, prev_sym, ms, end, end - ms))
        break
else:
    print('all aligned')
