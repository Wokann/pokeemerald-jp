import subprocess
from pathlib import Path

ROOT = Path('/home/kenny/pokeemerald-jp')
preproc = ROOT / 'tools' / 'preproc' / 'preproc'
as_ = ROOT / 'tools' / 'binutils' / 'bin' / 'arm-none-eabi-as'
objcopy = ROOT / 'tools' / 'binutils' / 'bin' / 'arm-none-eabi-objcopy'

r1 = subprocess.run([str(preproc), str(ROOT / 'data' / 'event_scripts.s'),
                     str(ROOT / 'charmap.txt')], capture_output=True)
print('preproc rc:', r1.returncode, 'out len:', len(r1.stdout))
Path('/tmp/es.s').write_bytes(r1.stdout)
r2 = subprocess.run([str(as_), '-mcpu=arm7tdmi', '-o', '/tmp/es.o', '/tmp/es.s'],
                    capture_output=True)
print('as rc:', r2.returncode, r2.stderr[:200])
if r2.returncode != 0:
    raise SystemExit
r3 = subprocess.run([str(objcopy), '-O', 'binary', '/tmp/es.o', '/tmp/es.bin'],
                    capture_output=True)
data = Path('/tmp/es.bin').read_bytes()
base = (ROOT / 'baserom_jp.gba').read_bytes()
print('es.bin len:', len(data))
seg = base[0x1DABAC:0x1DABAC + len(data)]
first = 0
while first < len(data) and data[first] == 0:
    first += 1
print('first nonzero at:', hex(first), 'value:', hex(data[first]))
if first > 0:
    print('  expected ROM start: 55 8c 09 08...')
    print('  es at first:', data[first:first + 8].hex())
diff = 0
for i in range(min(len(data) - first, len(seg))):
    if data[first + i] != seg[i]:
        diff += 1
        if diff <= 3:
            print('diff at +%X (virt %08X): built=%s rom=%s' % (
                i, i + 0x081DABAC, data[first+i:first+i+12].hex(), seg[i:i+12].hex()))
print('total diffs:', diff, 'of', len(data))
