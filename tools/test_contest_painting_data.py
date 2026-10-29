"""Native ContestPainting ownership, JP layout, text controls and complete bytes."""

import hashlib
from pathlib import Path
import re
import shlex
import tempfile
import unittest

from test_slot_machine_data import ROOT, fresh_object, run


CODE_START, CODE_END = 0x0812FDE0, 0x08130920
DATA_START, DATA_END = 0x085886AC, 0x0858F64C
TEXT_START, TEXT_END = 0x0824C1F5, 0x0824C395
CODE_SHA256 = '0456a5b246ade1763b81ef1fd037fdaaefdf0ef9dd32d9c5ec611e2479aa584c'
DATA_SHA256 = '0ec26c7d575697e9e4839621db7828f8e12383257209834d94eb4b6b1bba93f3'
TEXT_SHA256 = '5d30c22bce4399ad0b2c3212c83463a2bd6788a7c2dcb74774405f6a20fd07c0'
RESOURCE_RE = re.compile(r'^static const u(?:16|32) (\w+)\[\] CONTEST_PAINTING_DATA = INCGFX_U(?:16|32)\("([^"]+)", "([^"]+)"(?:, "([^"]+)")?\);$', re.M)
FUNCTIONS = (
    ('SetContestWinnerForPainting', 0x44), ('CB2_ContestPainting', 0xC),
    ('CB2_HoldContestPainting', 0x14), ('CB2_QuitContestPainting', 0x4C),
    ('ShowContestPainting', 0x170), ('HoldContestPainting', 0xD0),
    ('InitContestPaintingWindow', 0x74), ('PrintContestPaintingCaption', 0x100),
    ('InitContestPaintingBg', 0x4C), ('InitContestPaintingVars', 0x48),
    ('UpdateContestPaintingMosaicEffect', 0x50), ('VBlankCB_ContestPainting', 0x18),
    ('InitContestMonPixels', 0x98), ('_InitContestMonPixels', 0xB0),
    ('LoadContestPaintingFrame', 0x258), ('InitPaintingMonOamData', 0x44),
    ('GetImageEffectForContestWinner', 0x6C), ('AllocPaintingResources', 0x28),
    ('DoContestPaintingImageProcessing', 0x124), ('CreateContestPaintingPicture', 0x44),
)
TEXT_NAMES = ('gContestHallPaintingCaption', 'gContestPaintingContest',
              'gContestRankNormal', 'gContestRankSuper', 'gContestRankHyper',
              'gContestRankMaster', 'gContestLink', 'gContestCoolness',
              'gContestBeauty', 'gContestCuteness', 'gContestSmartness', 'gContestToughness') + tuple(
                  'gContestPainting' + category + str(index)
                  for category in ('Cool', 'Beauty', 'Cute', 'Smart', 'Tough')
                  for index in (1, 2, 3))


class ContestPaintingDataTests(unittest.TestCase):
    def test_complete_canonical_owner_and_regenerable_build_chain(self):
        source = (ROOT / 'src/contest_painting.c').read_text()
        make = (ROOT / 'Makefile').read_text()
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        self.assertFalse((ROOT / 'data/contest_painting.s').exists())
        self.assertNotIn('data/contest_painting.o', make + linker)
        self.assertNotIn('baserom_jp.gba', source)
        self.assertNotIn('__attribute__((naked))', source)
        self.assertNotIn('sContestPaintingFrame', source)
        self.assertEqual(len(RESOURCE_RE.findall(source)), 13)
        self.assertEqual(len(re.findall(r'(?m)^static const .*CONTEST_PAINTING_DATA =', source)), 20)
        self.assertEqual(linker.count('src/contest_painting.o(.rodata.contest_painting_data)'), 1)
        self.assertLess(linker.index('src/contest_painting.o(.rodata.contest_painting_data)'),
                        linker.index('src/battle_ai_script_commands.o(.rodata.battle_ai_tables)'))
        self.assertIn('.tilemapLeft = 5,', source)
        self.assertIn('.width = 20,', source)
        self.assertIn('static const struct OamData sContestPaintingMonOamData', source)
        self.assertIn('static const u16 sBgPalette[] CONTEST_PAINTING_DATA = {RGB_BLACK, RGB_BLACK};', source)
        self.assertNotIn('INCBIN_', source)
        self.assertNotIn('JP_CONTEST_PAINTING_ASSETS', make)
        self.assertNotIn('JP_CONTEST_PAINTING_INTERMEDIATES', make)
        self.assertIn('INCGFX_U32("graphics/picture_frame/lobby.png", ".4bpp.rl", "-num_tiles 86 -Wnum_tiles")', source)
        self.assertIn('$(PREPROC) -i -g $(JP_GRAPHICS_GFX_ROOT) $< charmap.txt',
                      make[make.rfind('$(C_BUILDDIR)/contest_painting.o:'):])
        self.assertIn('$(C_BUILDDIR)/contest_painting.d: src/contest_painting.c Makefile | tools', make)
        self.assertIn('$(SCANINC) -M $@ -g $(JP_GRAPHICS_GFX_ROOT)', make)
        self.assertIn('-include $(C_BUILDDIR)/contest_painting.d', make)
        for _, source_path, extension, options in RESOURCE_RE.findall(source):
            self.assertTrue((ROOT / source_path).is_file(), source_path)
            cache = ('$(JP_GRAPHICS_GFX_ROOT)' + source_path
                     + re.sub(r'[^a-zA-Z0-9]', '_', options) + extension)
            self.assertIn(cache + ': ', make)
            if extension == '.4bpp.rl':
                self.assertIn(cache + ': ' + cache[:-3] + ' $(GFX)', make)
                self.assertIn(cache[:-3] + ': ' + source_path + ' $(GFX)', make)
            self.assertEqual(run(['git', 'ls-files', '--error-unmatch', source_path], text=True).stdout.strip(),
                             source_path)

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').exists(), 'JP ROM required')
    def test_all_13_native_resources_regenerate_the_exact_rle_owner(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        cursor = DATA_START
        with tempfile.TemporaryDirectory(prefix='contest-painting-assets-') as directory:
            temporary = Path(directory)
            for symbol, source_path, extension, options in RESOURCE_RE.findall(
                    (ROOT / 'src/contest_painting.c').read_text()):
                source = ROOT / source_path
                if extension == '.gbapal':
                    output = temporary / (source.name + extension)
                    run(['tools/gbagfx/gbagfx', source, output])
                    self.assertEqual(output.stat().st_size, 512)
                else:
                    if extension == '.rl':
                        self.assertEqual(source.suffix, '.bin')
                        raw = source
                        self.assertEqual(raw.stat().st_size, 2048)
                    else:
                        self.assertEqual(extension, '.4bpp.rl')
                        self.assertEqual(source.suffix, '.png')
                        raw = temporary / (source.name + '.4bpp')
                        run(['tools/gbagfx/gbagfx', source, raw, *shlex.split(options)])
                        self.assertEqual(raw.stat().st_size,
                                         86 * 32 if source.stem == 'lobby' else 176 * 32)
                    output = temporary / (raw.name + '.rl')
                    run(['tools/gbagfx/gbagfx', raw, output])
                    self.assertEqual(output.read_bytes()[0], 0x30, symbol)
                actual = output.read_bytes()
                self.assertEqual(actual, rom[cursor - 0x08000000:cursor - 0x08000000 + len(actual)], symbol)
                cursor += len(actual)
            self.assertEqual(cursor, 0x0858F5D0)

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').exists(), 'JP ROM required')
    def test_27_caption_texts_use_contextual_placeholders_without_changing_jp_bytes(self):
        source = (ROOT / 'data/text/contest_painting.inc').read_text()
        names = re.findall(r'(?m)^(\w+)::?', source)
        self.assertEqual(names, list(TEXT_NAMES))
        self.assertNotIn('.incbin', source)
        self.assertNotIn('{B_COPY_VAR_', source)
        self.assertEqual(len(re.findall(r'\{STR_VAR_[123]\}', source)), 18)
        self.assertIn('{STR_VAR_1}', source)
        self.assertIn('{STR_VAR_2}', source)
        self.assertIn('{STR_VAR_3}', source)
        with tempfile.TemporaryDirectory(prefix='contest-painting-text-') as directory:
            temporary = Path(directory)
            obj = temporary / 'text.o'
            assembly = run(['tools/preproc/preproc', '-i', 'contest_painting.s', 'charmap.txt'],
                           input='.section .painting_text, "aw", %progbits\n' + source, text=True).stdout
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', obj, '-'], input=assembly, text=True)
            output = temporary / 'text.bin'
            run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=.painting_text', obj, output])
            actual = output.read_bytes()
            self.assertEqual(actual, (ROOT / 'baserom_jp.gba').read_bytes()[TEXT_START - 0x08000000:TEXT_END - 0x08000000])
            self.assertEqual(hashlib.sha256(actual).hexdigest(), TEXT_SHA256)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').exists(), 'linked JP ELF required')
    def test_fresh_c_preserves_all_20_functions_full_data_and_fixed_ram(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='contest-painting-module-') as directory:
            temporary = Path(directory)
            obj = temporary / 'contest_painting.o'
            fresh_object((ROOT / 'src/contest_painting.c').read_text(), obj, 'src/contest_painting.c')
            symbols = run(['tools/binutils/bin/arm-none-eabi-objdump', '-t', obj], text=True).stdout
            functions = re.findall(r'(?m)^([0-9a-f]+)\s+[lg]\s+F\s+\.text\s+([0-9a-f]+)\s+(\w+)$', symbols)
            self.assertEqual(len(functions), len(FUNCTIONS))
            expected = {}
            cursor = 0
            for name, size in FUNCTIONS:
                expected[name] = (cursor, size)
                cursor += size
            self.assertEqual({name: (int(offset, 16), int(size, 16)) for offset, size, name in functions}, expected)
            self.assertEqual(cursor, CODE_END - CODE_START)
            self.assertEqual(len(re.findall(r'(?m)^\w+\s+l\s+O\s+\.rodata\.contest_painting_data\s+', symbols)), 20)
            for name, size in {'sContestCategoryNames_Unused': 20, 'sContestRankNames': 20,
                               'sBgTemplates': 4, 'sWindowTemplate': 8, 'sMuseumCaptions': 60,
                               'sContestPaintingMonOamData': 8, 'sBgPalette': 4}.items():
                self.assertRegex(symbols, r'(?m)^\w+\s+l\s+O\s+\.rodata\.contest_painting_data\s+'
                                 + f'{size:08x}' + r'\s+' + name + '$')
            definitions = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', obj], text=True).stdout
            self.assertNotRegex(definitions, r'(?m)^\w+ \w+ [BbDd] ')
            script = temporary / 'module.ld'
            script.write_text('SECTIONS { .painting_code ' + hex(CODE_START) + ': { "' + str(obj) + '"(.text) } '
                              '.painting_data ' + hex(DATA_START) + ': { "' + str(obj) + '"(.rodata.contest_painting_data) } '
                              '/DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.comment*) *(.note*) *(.ARM.attributes) } }\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), obj])
            for section, first, end, digest in (('.painting_code', CODE_START, CODE_END, CODE_SHA256),
                                                ('.painting_data', DATA_START, DATA_END, DATA_SHA256)):
                output = temporary / (section[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=' + section, elf, output])
                actual = output.read_bytes()
                self.assertEqual(actual, rom[first - 0x08000000:end - 0x08000000], section)
                self.assertEqual(hashlib.sha256(actual).hexdigest(), digest)


if __name__ == '__main__':
    unittest.main()
