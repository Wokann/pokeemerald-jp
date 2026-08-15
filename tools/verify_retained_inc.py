import subprocess
from pathlib import Path

ROOT = Path('/home/kenny/pokeemerald-jp')
rom = (ROOT / 'baserom_jp.gba').read_bytes()
as_ = ROOT / 'tools' / 'binutils' / 'bin' / 'arm-none-eabi-as'

p = ROOT / 'data' / 'scripts' / 'gUnknown_824311B.inc'
tmp = Path('/tmp/verify_inc.s')
tmp.write_text(p.read_text(encoding='utf-8'), encoding='utf-8')
r = subprocess.run([str(as_), '-mcpu=arm7tdmi', '-o', '/tmp/verify_inc.o', str(tmp)],
                   capture_output=True)
print('as rc:', r.returncode, r.stderr[:200])
if r.returncode != 0:
    raise SystemExit
obj = subprocess.run([str(ROOT / 'tools' / 'binutils' / 'bin' / 'arm-none-eabi-objcopy'),
                      '-O', 'binary', '/tmp/verify_inc.o', '/tmp/verify_inc.bin'],
                     capture_output=True)
out = Path('/tmp/verify_inc.bin').read_bytes()
rom_off = 0x824311B - 0x08000000
rom_seg = rom[rom_off:rom_off + len(out)]
print('len:', len(out))
diff = 0
for i in range(min(len(out), len(rom_seg))):
    if out[i] != rom_seg[i]:
        diff += 1
        if diff <= 3:
            print('first diff at', i, 'out', out[i:i+8].hex(), 'rom', rom_seg[i:i+8].hex())
print('diff bytes:', diff, '/', len(out))
