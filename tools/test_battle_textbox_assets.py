"""Protect the complete JP textbox owner, source chain and fixed-address ABI."""
import hashlib
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import unittest
try:
    from map_semantic_review import native_elf
except ModuleNotFoundError:
    from tools.map_semantic_review import native_elf

ROOT = Path(__file__).resolve().parents[1]
BASE = 0x08000000
START, PAL, MAP, END = 0x08C00000, 0x08C004EC, 0x08C00530, 0x08C00758
DIRECTORY = 'graphics/battle_interface/'
SYMBOLS = {'gBattleTextboxTiles': (START, PAL - START), 'gBattleTextboxPalette': (PAL, MAP - PAL),
           'gBattleTextboxTilemap': (MAP, END - MAP)}


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result.stdout


def owner():
    source = (ROOT / 'src/graphics.c').read_text()
    return source[source.index('#define BATTLE_TEXTBOX_GRAPHICS'):source.index('#undef BATTLE_TEXTBOX_GRAPHICS')]


class BattleTextboxTests(unittest.TestCase):
    def test_whole_family_has_real_typed_definitions_in_us_graphics_owner(self):
        source = owner()
        self.assertIn('section(".rodata.battle_textbox"), aligned(4)', source)
        rows = re.findall(r'const u32 (\w+)\[\] = INCGFX_U32\("([^"]+)", "([^"]+)"\);', source)
        self.assertEqual(rows, [('gBattleTextboxTiles', DIRECTORY + 'textbox.png', '.4bpp.lz'),
                                ('gBattleTextboxPalette', DIRECTORY + 'textbox.gbapal', '.lz'),
                                ('gBattleTextboxTilemap', DIRECTORY + 'textbox_map.bin', '.lz')])
        self.assertNotRegex(source, r'INCBIN|baserom|\.set|asm\s*\(')
        for name in ('data/battle_textbox.s', 'graphics/battle_textbox/gBattleTextboxTiles.bin',
                     'graphics/battle_textbox/gBattleTextboxPalette.bin'):
            self.assertFalse((ROOT / name).exists())
        linker, make = (ROOT / 'ld_script_jp.txt').read_text(), (ROOT / 'Makefile').read_text()
        self.assertNotIn('data/battle_textbox.o', linker + make)
        self.assertEqual(linker.count('src/graphics.o(.rodata.battle_textbox)'), 1)
        self.assertLess(linker.index('src/graphics.o(.rodata.battle_textbox)'),
                        linker.index('src/graphics.o(.rodata.pokemon_circled_question_mark_graphics)'))

    def test_source_tilemap_is_2048_typed_entries_using_only_native_tiles_and_palette_banks(self):
        data = (ROOT / (DIRECTORY + 'textbox_map.bin')).read_bytes()
        self.assertEqual(len(data), 4096)
        self.assertEqual(hashlib.sha256(data).hexdigest(),
                         '70fe79456f6a52cbd26202d60e15fa55637d4e7a2bc77a31482238ece02974a5')
        entries = struct.unpack('<2048H', data)
        self.assertTrue(all((value & 0x3FF) < 256 for value in entries))
        self.assertEqual({value >> 12 for value in entries}, {0, 1})
        for i in range(2):
            lines = (ROOT / (DIRECTORY + 'textbox_%d.pal' % i)).read_text().splitlines()
            self.assertEqual(lines[:3], ['JASC-PAL', '0100', '16'])
            self.assertEqual(len(lines), 19)

    def test_make_palette_aggregate_has_two_pal_producers_and_clean_removes_only_generated_input(self):
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('JP_BATTLE_TEXTBOX_PALETTE := ' + DIRECTORY + 'textbox.gbapal', make)
        self.assertIn('0.pal.gbapal 1.pal.gbapal)', make)
        self.assertIn('$(JP_BATTLE_TEXTBOX_PALETTE): $(JP_BATTLE_TEXTBOX_PALETTE_BANKS) | tools\n\t@cat $^ >$@', make)
        self.assertIn('$(JP_GRAPHICS_GFX_ROOT)' + DIRECTORY + 'textbox_%.pal.gbapal: ' + DIRECTORY + 'textbox_%.pal | tools', make)
        clean = re.search(r'(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)', make)[1]
        self.assertIn('rm -f $(JP_BATTLE_TEXTBOX_PALETTE)', clean)
        self.assertNotIn(DIRECTORY + 'textbox.png', clean)
        self.assertNotIn(DIRECTORY + 'textbox_map.bin', clean)

    def test_five_existing_fixed_address_consumers_are_retained_as_jp_codegen_exceptions(self):
        expected = {'src/battle_bg.c': 2, 'src/egg_hatch.c': 1, 'src/trade.c': 2}
        for path, count in expected.items():
            source = (ROOT / path).read_text()
            self.assertEqual(len(re.findall(r'\(const u32 \*\)0x08C00000', source)), count, path)
        self.assertIn('movs/lsls', (ROOT / 'src/battle_bg.c').read_text())

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_linked_symbol_sizes_original_addresses_and_all_1880_bytes(self):
        names, memory = native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        for name, (address, size) in SYMBOLS.items():
            self.assertEqual(names[name], {address})
        output = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', 'pokeemerald_jp.elf'], text=True)
        records = {name: (int(address, 16), int(size, 16)) for address, size, kind, name in
                   re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', output) if name in SYMBOLS}
        self.assertEqual(records, SYMBOLS)
        self.assertEqual(names['gMonStillFrontPic_CircledQuestionMark'], {END})
        actual = [body[START - base:END - base] for base, body in memory if base <= START and END <= base + len(body)]
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(actual, [rom[START - BASE:END - BASE]])
        self.assertEqual(hashlib.sha256(actual[0]).hexdigest(),
                         'e00ad22c9d1dace501a3989429619eb45ba96b7252eb9974820584df7cb5d430')

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').is_file(), 'requires JP compiler and baseline')
    def test_fresh_png_two_pal_banks_and_structured_map_rebuild_the_complete_c_owner(self):
        parent = ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='battle-textbox-', dir=parent) as directory:
            temporary = Path(directory)
            tiles, palette, tilemap = temporary / 'tiles.4bpp', temporary / 'palette.gbapal', temporary / 'map.bin'
            run(['tools/gbagfx/gbagfx', ROOT / (DIRECTORY + 'textbox.png'), tiles])
            self.assertEqual(tiles.stat().st_size, 8192)
            self.assertEqual(hashlib.sha256(tiles.read_bytes()).hexdigest(),
                             '0b712921c5826b7e59d75357a7f0474945849e7f5e657cc4099c08e21f5e2a14')
            banks = []
            for i in range(2):
                output = temporary / ('%d.gbapal' % i)
                run(['tools/gbagfx/gbagfx', ROOT / (DIRECTORY + 'textbox_%d.pal' % i), output])
                self.assertEqual(output.stat().st_size, 32)
                banks.append(output.read_bytes())
            palette.write_bytes(b''.join(banks))
            tilemap.write_bytes((ROOT / (DIRECTORY + 'textbox_map.bin')).read_bytes())
            source = owner()
            for original, raw, extension, start, end in (
                    ('textbox.png', tiles, '.4bpp.lz', START, PAL),
                    ('textbox.gbapal', palette, '.lz', PAL, MAP),
                    ('textbox_map.bin', tilemap, '.lz', MAP, END)):
                packed = raw.with_name(raw.name + '.lz')
                run(['tools/gbagfx/gbagfx', raw, packed])
                expected = (ROOT / 'baserom_jp.gba').read_bytes()[start - BASE:end - BASE]
                self.assertEqual(packed.read_bytes(), expected)
                self.assertEqual(packed.read_bytes()[-1:], b'\0')
                source = source.replace('INCGFX_U32("' + DIRECTORY + original + '", "' + extension + '")',
                                        'INCBIN_U32("' + str(packed) + '")')
            self.assertNotIn('INCGFX_', source)
            cpp = run(['cpp', '-iquote', 'include', '-I', 'tools/agbcc/include', '-I', 'tools/agbcc',
                       '-Wno-trigraphs', '-nostdinc', '-undef', '-std=gnu89', '-P', '-x', 'c', '-'],
                      input='#include "global.h"\n' + source, text=True)
            pre = run(['tools/preproc/preproc', '-i', 'src/graphics.c', 'charmap.txt'], input=cpp, text=True)
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm', '-o', '-', '-'], input=pre, text=True)
            module, binary = temporary / 'textbox.o', temporary / 'textbox.bin'
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', module, '-'], input=assembly, text=True)
            run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=.rodata.battle_textbox', module, binary])
            self.assertEqual(binary.read_bytes(), (ROOT / 'baserom_jp.gba').read_bytes()[START - BASE:END - BASE])


if __name__ == '__main__':
    unittest.main()
