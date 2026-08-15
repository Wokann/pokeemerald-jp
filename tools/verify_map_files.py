#!/usr/bin/env python3
"""Verify each map scripts.inc encodes to the same bytes as the ROM
region it covers."""

import re
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path('/home/kenny/pokeemerald-jp')
sys.path.insert(0, str(ROOT / 'tools'))
import jp_emit_maps as em

rom = em.ROM
PREPROC = ROOT / 'tools' / 'preproc' / 'preproc'
AS = ROOT / 'tools' / 'binutils' / 'bin' / 'arm-none-eabi-as'
OBJCOPY = ROOT / 'tools' / 'binutils' / 'bin' / 'arm-none-eabi-objcopy'


def assemble(path):
    with tempfile.NamedTemporaryFile('w', suffix='.s', delete=False,
                                     encoding='utf-8') as f:
        f.write('.include "asm/macros.inc"\n')
        f.write('.include "asm/macros/event.inc"\n')
        f.write('.include "constants/constants.inc"\n')
        f.write('.include "constants/map_scripts.inc"\n')
        f.write('.include "constants/specials_constants.inc"\n')
        f.write('.section script_data, "aw", %progbits\n')
        f.write('.include "%s"\n' % path)
        name = f.name
    r1 = subprocess.run([str(PREPROC), name, str(ROOT / 'charmap.txt')],
                        capture_output=True)
    if r1.returncode != 0:
        return None
    out_s = name + '.out'
    Path(out_s).write_bytes(r1.stdout)
    r2 = subprocess.run([str(AS), '-mcpu=arm7tdmi', '-o', name + '.o', out_s],
                        capture_output=True)
    if r2.returncode != 0:
        return None
    r3 = subprocess.run([str(OBJCOPY), '-O', 'binary', name + '.o', name + '.bin'],
                        capture_output=True)
    Path(name).unlink(missing_ok=True)
    Path(out_s).unlink(missing_ok=True)
    Path(name + '.o').unlink(missing_ok=True)
    if r3.returncode != 0:
        return None
    return Path(name + '.bin').read_bytes()


def main():
    entries = em.map_entries()
    bad = 0
    for i, (ms, mname, gi, mi, ents, ev) in enumerate(entries):
        if mname != 'PetalburgCity':
            continue
        end = entries[i + 1][0] if i + 1 < len(entries) else 0x82423AF
        p = ROOT / 'data' / 'maps' / mname / 'scripts.inc'
        data = assemble(str(p))
        if data is None:
            print('ASSEMBLE FAIL:', mname)
            bad += 1
            continue
        romseg = rom[ms - 0x08000000: end - 0x08000000]
        print('PetalburgCity head:', data[:16].hex())
        print('rom head:', romseg[:16].hex())
        break
        if data != romseg:
            print('BYTE MISMATCH: %s (%08X-%08X) len %d vs %d' % (
                mname, ms, end, len(data), len(romseg)))
            for j in range(min(len(data), len(romseg))):
                if data[j] != romseg[j]:
                    print('  first diff at +0x%X: built=%s rom=%s' % (
                        j, data[j:j + 12].hex(), romseg[j:j + 12].hex()))
                    break
            if mname == 'PetalburgCity':
                print('  built head:', data[:32].hex())
                print('  rom   head:', romseg[:32].hex())
            bad += 1
        else:
            pass
    print('bad maps:', bad)


if __name__ == '__main__':
    main()
