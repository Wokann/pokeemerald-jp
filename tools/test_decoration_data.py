"""Whole JP decoration owner: native inputs, typed tables and unchanged code."""

import hashlib
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import unittest

from jp_script_text import JapaneseScriptTextCodec


ROOT = Path(__file__).resolve().parents[1]
BASE = 0x08000000
CORE_START, CORE_END = 0x0857FE04, 0x08582308
ICONS_START, ICONS_END = 0x08DB7D48, 0x08DBA3F4
HEADERS = ('tiles', 'description', 'header', 'icon', 'tilemaps')
CORE_ASSETS = (
    ('decoration_menu.pal', 'decoration_menu.gbapal', 0x08581A94, 0x08581AB4),
    ('brendan.pal', 'brendan.gbapal', 0x085821EC, 0x0858220C),
    ('may.pal', 'may.gbapal', 0x0858220C, 0x0858222C),
    ('put_away_cursor.png', 'put_away_cursor.4bpp', 0x0858223C, 0x085822BC),
)


def run(args, **kwargs):
    try:
        return subprocess.run([str(value) for value in args], cwd=ROOT,
                              capture_output=True, check=True, **kwargs)
    except subprocess.CalledProcessError as error:
        raise AssertionError(f'{error.cmd}:\n{error.stderr}') from error


def icon_declarations():
    text = (ROOT / 'src/data/graphics/decorations.h').read_text()
    return re.findall(r'const u32 (\w+)\[\] = INCBIN_U32\("([^"]+)"\);', text)


def generate_assets(directory):
    outputs, symbols = {}, {}
    position = ICONS_START
    for symbol, path in icon_declarations():
        source = ROOT / Path(path.removesuffix('.lz')).with_suffix('.png')
        raw = directory / Path(path.removesuffix('.lz')).name
        packed = Path(str(raw) + '.lz')
        run(['tools/gbagfx/gbagfx', source, raw])
        run(['tools/gbagfx/gbagfx', raw, packed])
        size = packed.stat().st_size
        outputs[path] = (packed, position, position + size)
        symbols[symbol] = position
        position += size
    for source, output, start, end in CORE_ASSETS:
        target = directory / output
        run(['tools/gbagfx/gbagfx', ROOT / 'graphics/decorations' / source, target])
        outputs['graphics/decorations/' + output] = (target, start, end)
    return outputs, symbols


def compile_c(source, output, label):
    cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs',
               '-I', 'tools/agbcc/include', '-I', 'tools/agbcc', '-nostdinc',
               '-undef', '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True).stdout
    preprocessed = run(['tools/preproc/preproc', '-i', label, 'charmap.txt'],
                       input=cpp, text=True).stdout
    assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2',
                    '-fhex-asm', '-o', '-', '-'], input=preprocessed, text=True).stdout
    assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
    run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', output, '-'],
        input=assembly, text=True)


class DecorationDataTests(unittest.TestCase):
    def test_single_canonical_owner_and_protected_neighbor_boundaries(self):
        source = (ROOT / 'src/decoration.c').read_text()
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        self.assertFalse((ROOT / 'data/data_b2d_mid61.s').exists())
        mid = (ROOT / 'Makefile').read_text()
        rest = (ROOT / 'data/data_rest2c.s').read_text()
        for name in HEADERS:
            self.assertIn('#include "data/decoration/' + name + '.h"', source)
            self.assertNotIn('baserom_jp.gba', (ROOT / 'src/data/decoration' / (name + '.h')).read_text())
        for name in ('tiles', 'description', 'header'):
            self.assertFalse((ROOT / 'data/decoration' / (name + '.inc')).exists())
            self.assertNotIn('data/decoration/' + name + '.inc', mid)
        self.assertNotRegex(source, r'gUnknown_858[0-9A-Fa-f]+')
        self.assertNotIn('.set ', source)
        self.assertEqual(source.count('__attribute__((naked))'), 135)
        for section in ('src/decoration.o(.rodata.decoration_data);',
                        'src/graphics.o(.rodata.decoration_icons);',
                        'src/graphics.o(.rodata.slot_machine_gfx.gSlotMachineReelSymbol1Tiles);',
                        'src/graphics.o(.rodata.battle_anim_shock_and_feather_resources);'):
            self.assertEqual(linker.count(section), 1)
        self.assertLess(linker.index('src/graphics.o(.rodata.decoration_icons);'),
                        linker.index('src/graphics.o(.rodata.battle_anim_shock_and_feather_resources);'))
        self.assertLess(linker.index('src/graphics.o(.rodata.battle_anim_shock_and_feather_resources);'),
                        linker.index('src/graphics.o(.rodata.cable_car_bg_palette);'))
        self.assertIn('src/image_processing_effects.o(.rodata.image_processing_effects);', linker)
        self.assertLess(linker.index('src/image_processing_effects.o(.rodata.image_processing_effects);'),
                        linker.index('src/decoration.o(.rodata.decoration_data);'))
        self.assertLess(linker.index('src/decoration.o(.rodata.decoration_data);'),
                        linker.index('src/graphics.o(.rodata.slot_machine_gfx.gSlotMachineReelSymbol1Tiles);'))
        self.assertNotIn('.incbin "baserom_jp.gba", 0x57d884, 0x2580', mid)
        self.assertNotIn('.incbin "baserom_jp.gba", 0x582308, 0x20a0', mid)
        self.assertFalse((ROOT / 'data/slot_machine/jp').exists())
        self.assertIn('gItemIcon_QuestionMark:: @ 0x08DAB300', rest)
        self.assertIn('gItemIconPalette_QuestionMark:: @ 0x08DAB378', rest)
        self.assertIn('.incbin "baserom_jp.gba", 0xdab38c, 0xc9bc', rest)
        self.assertNotIn('gBattleAnimSpritePal_Shock3: @ 0x08DBA3F4', rest)
        self.assertIn('BATTLE_ANIM_SHOCK_AND_FEATHER_RESOURCES const u32 gBattleAnimSpritePal_Shock3[]',
                      (ROOT / 'src/graphics.c').read_text())
        self.assertIn('extern struct PlaceDecorationGraphicsDataBuffer gUnknown_2039E5C;', source)
        self.assertIn('extern struct OamData gUnknown_203A708;', source)
        self.assertIn('.upText_Y = 10,', source)
        self.assertIn('.fontId = FONT_NORMAL,', source)

    def test_build_chain_cleans_and_regenerates_all_88_outputs(self):
        makefile = (ROOT / 'Makefile').read_text()
        declarations = icon_declarations()
        self.assertEqual(len(declarations), 84)
        block = makefile.split('JP_DECORATION_ICON_ASSETS := ', 1)[1].split('JP_DECORATION_CORE_ASSETS :=', 1)[0]
        self.assertEqual(re.findall(r'graphics/decorations/[^\s\\]+', block), [path for _, path in declarations])
        self.assertIn('JP_DECORATION_ICON_INTERMEDIATES := $(JP_DECORATION_ICON_ASSETS:.lz=)', makefile)
        self.assertIn('\trm -f $(JP_DECORATION_ICON_ASSETS) $(JP_DECORATION_CORE_ASSETS) $(JP_DECORATION_ICON_INTERMEDIATES)', makefile)
        self.assertIn('$(C_BUILDDIR)/graphics.o: src/graphics.c src/data/graphics/decorations.h $(JP_DECORATION_ICON_ASSETS)', makefile)
        self.assertIn('$(C_BUILDDIR)/decoration.o: src/decoration.c charmap.txt $(JP_DECORATION_CORE_ASSETS)', makefile)
        block = makefile.split('$(C_BUILDDIR)/decoration.o:', 1)[1].split('\n\n', 1)[0]
        self.assertIn('$(PREPROC) -i $< charmap.txt', block)
        for name in HEADERS:
            self.assertIn('src/data/decoration/' + name + '.h', block)
        for name in ('tiles', 'description', 'header'):
            self.assertNotIn('data/decoration/' + name + '.inc', makefile)
        for source, output, _, _ in CORE_ASSETS:
            self.assertTrue((ROOT / 'graphics/decorations' / source).is_file())
            self.assertIn('graphics/decorations/' + output, makefile)

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').exists(), 'JP ROM required')
    def test_all_121_names_and_120_descriptions_preserve_jp_eos_padding_and_layout(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        codec = JapaneseScriptTextCodec()
        names = re.findall(r'\.name = __\("([^"]+)"\)', (ROOT / 'src/data/decoration/header.h').read_text())
        self.assertEqual(len(names), 121)
        decoration = (ROOT / 'include/decoration.h').read_text()
        self.assertIn('u8 name[11];', decoration)
        self.assertIn('u32 price;', decoration)
        pointers = []
        for index, name in enumerate(names):
            record = rom[0x580CD0 + index * 28:0x580CD0 + (index + 1) * 28]
            self.assertEqual(record[0], index)
            self.assertEqual(codec.preproc_bytes(name), record[1:12])
            self.assertTrue(name.endswith('$'))
            pointers.append(struct.unpack_from('<I', record, 20)[0])
        descriptions = re.findall(r'const u8 (DecorDesc_\w+)\[\] = _\((.*?)\);',
                                  (ROOT / 'src/data/decoration/description.h').read_text(), re.S)
        self.assertEqual(len(descriptions), 120)
        unique = sorted(set(pointers))
        self.assertEqual(len(unique), 120)
        for index, ((_, literals), start) in enumerate(zip(descriptions, unique)):
            end = unique[index + 1] if index + 1 < len(unique) else 0x08580CD0
            source = ''.join(re.findall(r'"((?:[^"\\]|\\.)*)"', literals))
            decoded = codec.verify_one(rom[start - BASE:end - BASE])
            self.assertEqual(decoded.consumed, end - start)
            self.assertEqual(source, decoded.source[:-1])

    @unittest.skipUnless((ROOT / 'tools/gbagfx/gbagfx').exists() and (ROOT / 'baserom_jp.gba').exists(),
                         'built graphics tool and JP ROM required')
    def test_every_native_icon_and_core_asset_reencodes_to_jp_bytes(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='decoration-native-') as directory:
            outputs, symbols = generate_assets(Path(directory))
            self.assertEqual(len(outputs), 88)
            self.assertEqual(len(symbols), 84)
            icons = b''
            for path, (binary, start, end) in outputs.items():
                actual = binary.read_bytes()
                self.assertEqual(actual, rom[start - BASE:end - BASE], path)
                if path.endswith('.lz'):
                    self.assertEqual(len(actual) % 4, 0, path)
                    icons += actual
            self.assertEqual(len(icons), ICONS_END - ICONS_START)
            self.assertEqual(hashlib.sha256(icons).hexdigest(), 'ef451e716318be34baaf0375bcd72453a440b03fe37f8a0be42de2ff49afbaf9')
            self.assertLess(symbols['gDecorIcon_RegiceDoll'], symbols['gDecorIcon_RegirockDoll'])
            self.assertLess(symbols['gDecorIcon_RegirockDoll'], symbols['gDecorIcon_RegisteelDoll'])

    @unittest.skipUnless((ROOT / 'tools/gbagfx/gbagfx').exists() and (ROOT / 'baserom_jp.gba').exists(),
                         'built graphics tool and JP ROM required')
    def test_all_242_icon_pointers_resolve_to_84_owned_156_null_and_two_shared_symbols(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='decoration-pointers-') as directory:
            _, symbols = generate_assets(Path(directory))
            symbols.update({'NULL': 0, 'gItemIcon_QuestionMark': 0x08DAB300,
                            'gItemIconPalette_QuestionMark': 0x08DAB378})
            rows = re.findall(r'\[DECOR_\w+\]\s*=\s*\{(\w+),\s*(\w+)\}',
                              (ROOT / 'src/data/decoration/icon.h').read_text())
            self.assertEqual(len(rows), 121)
            names = [name for row in rows for name in row]
            self.assertEqual(names.count('NULL'), 156)
            self.assertEqual(sum(name.startswith('gDecorIcon') for name in names), 84)
            self.assertEqual(names[:2], ['gItemIcon_QuestionMark', 'gItemIconPalette_QuestionMark'])
            actual = b''.join(struct.pack('<I', symbols[name]) for name in names)
            self.assertEqual(actual, rom[0x581ACC:0x581E94])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').exists(), 'linked JP ELF required')
    def test_fresh_native_assets_and_c_reproduce_the_entire_code_core_and_icon_sections(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='decoration-module-') as directory:
            temporary = Path(directory)
            outputs, _ = generate_assets(temporary)
            source = (ROOT / 'src/decoration.c').read_text()
            for name in HEADERS:
                header = temporary / (name + '.h')
                header.write_text((ROOT / 'src/data/decoration' / (name + '.h')).read_text())
                source = source.replace('"data/decoration/' + name + '.h"', '"' + str(header) + '"')
            icons = ('#include "global.h"\n#define DECORATION_ICONS_GRAPHICS '
                     '__attribute__((section(".rodata.decoration_icons"), aligned(4)))\n'
                     + (ROOT / 'src/data/graphics/decorations.h').read_text())
            for path, (binary, _, _) in outputs.items():
                source = source.replace('"' + path + '"', '"' + str(binary) + '"')
                icons = icons.replace('"' + path + '"', '"' + str(binary) + '"')
            core_object, icon_object, shared_object = [temporary / name for name in ('decoration.o', 'icons.o', 'rest.o')]
            compile_c(source, core_object, 'src/decoration.c')
            compile_c(icons, icon_object, 'src/graphics.c')
            shared = run(['tools/preproc/preproc', 'data/data_rest2c.s', 'charmap.txt'], text=True).stdout
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', shared_object, '-'], input=shared, text=True)
            script = temporary / 'module.ld'
            script.write_text('SECTIONS {\n'
                              '.text 0x08126950 : { *decoration.o(.text) }\n'
                              '.core 0x0857FE04 : { *decoration.o(.rodata.decoration_data) }\n'
                              '.shared 0x08DAB2FD : { *rest.o(.rodata.data_rest2c_after_chases_away) }\n'
                              '.icons 0x08DB7D48 : { *icons.o(.rodata.decoration_icons) }\n'
                              '/DISCARD/ : { *(*) }\n}\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), core_object, icon_object, shared_object])
            for name, start, end, digest in (
                ('.text', 0x08126950, 0x0812A4EC, '853cd8dabe635105a60bad72e5fde6ae26ad944cbc54bc3fd04c152f8d51e3ec'),
                ('.core', CORE_START, CORE_END, '2f6423e005047fb34fd42697e2e24130e042926ab75864d6bf3b0bb0f2b0d4d6'),
                ('.shared', 0x08DAB2FD, ICONS_START, '083afa0a8b0467d00e70575ab58585ef141df883262c3427e3a0c199ce5c77e1'),
                ('.icons', ICONS_START, ICONS_END, 'ef451e716318be34baaf0375bcd72453a440b03fe37f8a0be42de2ff49afbaf9'),
            ):
                binary = temporary / (name[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=' + name, elf, binary])
                actual = binary.read_bytes()
                self.assertEqual(actual, rom[start - BASE:end - BASE], name)
                self.assertEqual(hashlib.sha256(actual).hexdigest(), digest)


if __name__ == '__main__':
    unittest.main()
