"""The entire Cry Screen family rebuilds from editable native-matching sources."""
import hashlib
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x08000000
START, END = 0x0859770C, 0x08598854
OBJECTS = (
    ('sCryMeterNeedle_Pal', 0x0859770C, 32),
    ('sCryMeterNeedle_Gfx', 0x0859772C, 2048),
    ('sCryMeter_Tilemap', 0x08597F2C, 160),
    ('sCryMeter_Pal', 0x08597FCC, 32),
    ('sCryMeter_Gfx', 0x08597FEC, 824),
    ('sWaveformOffsets', 0x08598324, 1152),
    ('sCryScreenBg_Pal', 0x085987A4, 32),
    ('sCryScreenBg_Gfx', 0x085987C4, 32),
    ('sWaveformTileDataNybbleMasks', 0x085987E4, 2),
    ('sWaveformColor', 0x085987E6, 32),
    ('sSpriteAnim_CryMeterNeedle', 0x08598808, 8),
    ('sSpriteAnimTable_CryMeterNeedle', 0x08598810, 4),
    ('sOamData_CryMeterNeedle', 0x08598814, 8),
    ('sCryMeterNeedleSpriteTemplate', 0x0859881C, 24),
    ('sCryMeterNeedleSpriteSheets', 0x08598834, 16),
    ('sCryMeterNeedleSpritePalettes', 0x08598844, 16),
)


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result


def resources():
    source = (ROOT / 'src/pokedex_cry_screen.c').read_text()
    return re.findall(r'^static const (u\d+) (?:ALIGNED\(4\) )?(s\w+)\[\] '
                      r'POKEDEX_CRY_SCREEN_DATA = INCGFX_U\d+\("([^"]+)", "([^"]+)"\);', source, re.M)


class PokedexCryAssetsTests(unittest.TestCase):
    def test_editable_sources_replace_six_generated_inputs_not_the_unused_map(self):
        rows = resources()
        self.assertEqual(len(rows), 6)
        self.assertEqual({p for c, n, p, e in rows}, {'graphics/pokedex/' + n + '.png'
                         for n in ('cry_meter_needle', 'cry_meter', 'cry_screen_bg')})
        for c, n, path, extension in rows:
            self.assertTrue((ROOT / path).is_file(), path)
            retired = path.removesuffix('.png') + extension
            self.assertFalse((ROOT / retired).exists(), retired)
            self.assertNotIn('!' + retired + '\n', (ROOT / '.gitignore').read_text())
        self.assertEqual((ROOT / 'graphics/pokedex/cry_meter_map.bin').stat().st_size, 160)
        source = (ROOT / 'src/pokedex_cry_screen.c').read_text()
        self.assertEqual(source.count('INCBIN_U'), 1)
        self.assertIn('INCBIN_U16("graphics/pokedex/cry_meter_map.bin"); // Unused', source)
        self.assertNotIn('baserom_jp.gba', source)

    def test_build_dependencies_cleanup_and_existing_private_owner_are_closed(self):
        make = (ROOT / 'Makefile').read_text()
        ld = (ROOT / 'ld_script_jp.txt').read_text()
        self.assertIn('rm -f $(JP_CRY_SCREEN_ASSETS) $(JP_CRY_SCREEN_INTERMEDIATES)', make)
        self.assertIn('$(C_BUILDDIR)/pokedex_cry_screen.d: src/pokedex_cry_screen.c Makefile | tools', make)
        self.assertIn('-include $(C_BUILDDIR)/pokedex_cry_screen.d', make)
        self.assertIn('$(C_BUILDDIR)/pokedex_cry_screen.o: src/pokedex_cry_screen.c charmap.txt $(JP_CRY_SCREEN_ASSETS) graphics/pokedex/cry_meter_map.bin', make)
        self.assertNotIn('$(C_BUILDDIR)/pokedex_cry_screen.o: CC1', make)
        self.assertEqual(ld.count('src/pokedex_cry_screen.o(.rodata.pokedex_cry_screen_data);'), 1)
        self.assertEqual(ld.count('src/pokedex_cry_screen.o(.text);'), 1)
        self.assertLess(ld.index('src/roulette.o(.rodata.roulette_data);'), ld.index('src/pokedex_cry_screen.o(.rodata.pokedex_cry_screen_data);'))
        self.assertLess(ld.index('src/pokedex_cry_screen.o(.rodata.pokedex_cry_screen_data);'), ld.index('src/landmark.o(.rodata.landmark_data);'))
        for c, n, path, extension in resources():
            self.assertIn(path + extension, make)

    def test_waveform_rows_raw_sheet_and_sentinel_shapes_are_preserved(self):
        source = (ROOT / 'src/pokedex_cry_screen.c').read_text()
        block = source.split('sWaveformOffsets[][72] POKEDEX_CRY_SCREEN_DATA =', 1)[1].split('};', 1)[0]
        self.assertEqual(re.findall(r'WAVEFORM_OFFSET_ROW\((0x[0-9A-Fa-f]+)\)', block),
                         ['0x0000', '0x0000', '0x0001', '0x0001', '0x0002', '0x0002', '0x0003', '0x0003'])
        self.assertIn('u8 cryWaveformBuffer[16];', source)
        self.assertIn('static const u16 ALIGNED(4) sCryMeterNeedle_Pal[]', source)
        self.assertIn('static const struct SpriteSheet sCryMeterNeedleSpriteSheets[]', source)
        self.assertNotIn('CompressedSpriteSheet sCryMeterNeedle', source)
        for name in ('sCryMeterNeedleSpriteSheets', 'sCryMeterNeedleSpritePalettes'):
            block = source.split(name + '[] POKEDEX_CRY_SCREEN_DATA =', 1)[1].split('};', 1)[0]
            self.assertEqual(block.count('{}'), 1)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires JP native artifacts')
    def test_all_sixteen_objects_waveform_values_and_native_end_are_exact(self):
        text = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', ROOT / 'pokeemerald_jp.elf'], text=True).stdout
        named = {}
        for addr, size, kind, name in re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', text):
            named.setdefault(name, []).append((int(addr, 16), int(size, 16)))
        for name, address, size in OBJECTS:
            self.assertIn((address, size), named[name], name)
        self.assertIn((END, 9), named['LandmarkName_FlowerShop'])
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(hashlib.sha256(rom[START - BASE:END - BASE]).hexdigest(),
                         '52e8cf60420cb690ff5c246a9969a8ea71bdc3f7a0f9f3f8550a604cba5ca6aa')
        expected = [row // 2 + group * 0x400 + col * 4
                    for row in range(8) for group in range(9) for col in range(8)]
        self.assertEqual(list(struct.unpack_from('<576H', rom, 0x598324)), expected)
        self.assertEqual(rom[0x598806:0x598808], b'\0\0')
        self.assertEqual(rom[0x597F2C:0x597FCC], (ROOT / 'graphics/pokedex/cry_meter_map.bin').read_bytes())

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file() and (ROOT / 'baserom_jp.gba').is_file()
                         and (ROOT / 'tools/gbagfx/gbagfx').is_file(), 'requires JP native artifacts and gbagfx')
    def test_fresh_editable_sources_reproduce_the_complete_code_and_data_owner(self):
        temporary_root = ROOT / '.tmp/agent-work/tests'
        temporary_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='pokedex-cry-family-', dir=temporary_root) as directory:
            temporary = Path(directory)
            source = (ROOT / 'src/pokedex_cry_screen.c').read_text()
            for i, (ctype, name, path, extension) in enumerate(resources()):
                output = temporary / (str(i) + extension)
                raw = output.with_name(output.name.removesuffix('.lz'))
                run(['tools/gbagfx/gbagfx', ROOT / path, raw])
                if extension.endswith('.lz'):
                    run(['tools/gbagfx/gbagfx', raw, output])
                else:
                    output = raw
                before = 'INCGFX_U' + ctype[1:] + '("' + path + '", "' + extension + '")'
                self.assertEqual(source.count(before), 1)
                source = source.replace(before, 'INCBIN_U' + ctype[1:] + '("' + str(output) + '")')
            cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs',
                       '-I', 'tools/agbcc/include', '-I', 'tools/agbcc', '-nostdinc',
                       '-undef', '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True).stdout
            pre = run(['tools/preproc/preproc', '-i', 'src/pokedex_cry_screen.c', 'charmap.txt'], input=cpp, text=True).stdout
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm', '-o', '-', '-'], input=pre, text=True).stdout
            assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
            module = temporary / 'module.o'
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', module, '-'], input=assembly, text=True)
            script = temporary / 'module.ld'
            script.write_text('SECTIONS {\n.text 0x08145420 : { *module.o(.text) }\n'
                              '.data 0x0859770C : { *module.o(.rodata.pokedex_cry_screen_data) }\n'
                              '/DISCARD/ : { *(*) }\n}\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), module])
            rom = (ROOT / 'baserom_jp.gba').read_bytes()
            for name, start, end, digest in (
                ('.text', 0x08145420, 0x08145C20, '3d7d6803aa34d44883b98d262c588e4683bdc4be1a2b4603334eb3792cfc3348'),
                ('.data', START, END, '52e8cf60420cb690ff5c246a9969a8ea71bdc3f7a0f9f3f8550a604cba5ca6aa'),
            ):
                output = temporary / (name[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=' + name, elf, output])
                actual = output.read_bytes()
                self.assertEqual(actual, rom[start - BASE:end - BASE], name)
                self.assertEqual(hashlib.sha256(actual).hexdigest(), digest, name)


if __name__ == '__main__':
    unittest.main()
