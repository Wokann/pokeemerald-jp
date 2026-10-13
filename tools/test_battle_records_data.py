"""Complete native battle-record resources, JP windows, texts and unchanged code."""

import hashlib
from pathlib import Path
import re
import tempfile
import unittest

from test_slot_machine_data import ROOT, fresh_object, run


CODE_START, CODE_END = 0x0813BFB8, 0x0813CA30
DATA_START, DATA_END = 0x08592EE0, 0x0859381C
CODE_SHA256 = 'a118fc536b67f7bf54f77ea3f15feb1516f9455d51b96aee996cea1e6401e111'
DATA_SHA256 = '393381df333d1339e2f19d756d78176bb3c07380851e09f325452d23ca9e8309'
FUNCTIONS = (
    ('ClearLinkBattleRecord', 0x30), ('ClearLinkBattleRecords', 0x34),
    ('GetLinkBattleRecordTotalBattles', 0x10), ('FindLinkBattleRecord', 0x34),
    ('SortLinkBattleRecords', 0x7C), ('UpdateLinkBattleRecord', 0x64),
    ('UpdateLinkBattleGameStats', 0x3C), ('UpdateLinkBattleRecords', 0x88),
    ('ClearPlayerLinkBattleRecords', 0x1C), ('IncTrainerCardWins', 0x28),
    ('IncTrainerCardLosses', 0x28), ('UpdateTrainerCardWinsLosses', 0x3C),
    ('UpdatePlayerLinkBattleRecords', 0x54), ('PrintLinkBattleWinsLossesDraws', 0x84),
    ('PrintLinkBattleRecord', 0x12C), ('ShowLinkBattleRecords', 0xCC),
    ('RemoveRecordsWindow', 0x1C), ('Task_TrainerHillWaitForPaletteFade', 0x30),
    ('Task_CloseTrainerHillRecordsOnButton', 0x40), ('Task_BeginPaletteFade', 0x38),
    ('Task_ExitTrainerHillRecords', 0x44), ('RemoveTrainerHillRecordsWindow', 0x2C),
    ('ClearVramOamPlttRegs', 0x138), ('ClearTasksAndGraphicalStructs', 0x1C),
    ('ResetBgCoordinates', 0x58), ('SetDispcntReg', 0x10),
    ('LoadTrainerHillRecordsWindowGfx', 0x48), ('VblankCB_TrainerHillRecords', 0x14),
    ('MainCB2_TrainerHillRecords', 0x18), ('ShowTrainerHillRecords', 0x18),
    ('CB2_ShowTrainerHillRecords', 0x138),
)
OBSOLETE = (
    'src/data/battle_records.c', 'src/data/battle_records.h',
    'src/data/text/region_texts32.c', 'src/data/text/region_texts32.h',
    'data/battle_records/jp/trainer_hill_records_bg_templates.bin',
    'data/battle_records/jp/trainer_hill_records_window_templates.bin',
    'data/battle_records/jp/link_battle_records_window_template.bin',
    'graphics/trainer_hill/records_window_tiles.4bpp',
    'graphics/trainer_hill/records_window_palette.gbapal',
    'graphics/trainer_hill/records_window_tilemap.tilemap',
)


class BattleRecordsDataTests(unittest.TestCase):
    def test_complete_canonical_owners_and_regenerable_build_chain(self):
        source = (ROOT / 'src/battle_records.c').read_text()
        strings = (ROOT / 'src/strings.c').read_text()
        make = (ROOT / 'Makefile').read_text()
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        for path in OBSOLETE:
            self.assertFalse((ROOT / path).exists(), path)
        for old in ('src/data/battle_records.o', 'region_texts32.o', 'data/battle_records/jp/'):
            self.assertNotIn(old, source + strings + make + linker)
        self.assertNotIn('__attribute__((naked))', source)
        self.assertNotIn('Kept as naked asm', source)
        self.assertNotIn('baserom_jp.gba', source)
        self.assertIn('extern u8 gRecordsWindowId;', source)
        self.assertIn('extern u8 *sTilemapBuffer;', source)
        for name in ('sTrainerHillWindowTileset', 'sTrainerHillWindowPalette',
                     'sTrainerHillWindowTilemap', 'sTrainerHillRecordsBgTemplates',
                     'sTrainerHillRecordsWindowTemplates', 'sLinkBattleRecordsWindow'):
            self.assertRegex(source, r'static const [^;]+\b' + name + r'(?:\[\])? BATTLE_RECORDS_DATA =')
        self.assertIn('.width = 27,', source)
        self.assertIn('DUMMY_WIN_TEMPLATE', source)
        self.assertIn('sText_DashesNoPlayer[] BATTLE_RECORDS_TEXT = _("ーーーーー");', source)
        self.assertIn('sText_DashesNoScore[] BATTLE_RECORDS_TEXT = _("ーーーー");', source)
        block = strings[strings.index('#define STRINGS_BATTLE_RECORDS'):]
        self.assertEqual(len(re.findall(r'(?m)^STRINGS_BATTLE_RECORDS const u8 ', block)), 3)
        self.assertIn('_("{PLAYER}　の　たいせん　せいせき")', block)
        self.assertNotIn('MUS_RG_VS_TRAINER', block)
        self.assertNotIn('B_COPY_VAR_', block)
        for index in (1, 2, 3):
            self.assertIn('{STR_VAR_' + str(index) + '}', block)
        expected = ('src/battle_records.o(.rodata.battle_records_data)',
                    'src/strings.o(.rodata.strings_battle_records)',
                    'src/battle_records.o(.rodata.battle_records_text)',
                    'data/graphics/pokedex_area_screen.o(.rodata.pokedex_area_screen_graphics_prefix)')
        positions = []
        for owner in expected:
            self.assertEqual(linker.count(owner), 1)
            positions.append(linker.index(owner))
        self.assertEqual(positions, sorted(positions))
        self.assertIn('rm -f $(JP_BATTLE_RECORDS_ASSETS)', make)
        rule = make[make.rfind('$(C_BUILDDIR)/battle_records.o:'):]
        self.assertIn('$(PREPROC) -i $< charmap.txt', rule)
        self.assertIn('$(JP_BATTLE_RECORDS_ASSETS) graphics/trainer_hill/records_window.bin', rule)
        for extension in ('.4bpp', '.gbapal'):
            output = 'graphics/trainer_hill/records_window' + extension
            self.assertIn(output, make)
            self.assertTrue(run(['git', 'check-ignore', output], text=True).stdout.strip())

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').exists(), 'JP ROM required')
    def test_all_native_resources_regenerate_the_exact_jp_bytes(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='battle-records-assets-') as directory:
            temporary = Path(directory)
            for extension, start, size in (('.4bpp', DATA_START, 192), ('.gbapal', DATA_START + 192, 32)):
                output = temporary / ('records_window' + extension)
                run(['tools/gbagfx/gbagfx', ROOT / 'graphics/trainer_hill/records_window.png', output])
                self.assertEqual(len(output.read_bytes()), size)
                self.assertEqual(output.read_bytes(), rom[start - 0x08000000:start - 0x08000000 + size])
        tilemap = (ROOT / 'graphics/trainer_hill/records_window.bin').read_bytes()
        self.assertEqual(len(tilemap), 2048)
        self.assertEqual(tilemap, rom[0x592FC0:0x5937C0])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').exists(), 'linked JP ELF required')
    def test_fresh_native_c_preserves_all_31_functions_and_complete_owner(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='battle-records-module-') as directory:
            temporary = Path(directory)
            obj = temporary / 'battle_records.o'
            text_obj = temporary / 'strings.o'
            fresh_object((ROOT / 'src/battle_records.c').read_text(), obj, 'src/battle_records.c')
            fresh_object((ROOT / 'src/strings.c').read_text(), text_obj, 'src/strings.c')
            symbols = run(['tools/binutils/bin/arm-none-eabi-objdump', '-t', obj], text=True).stdout
            functions = re.findall(r'(?m)^([0-9a-f]+)\s+[lg]\s+F\s+\.text\s+([0-9a-f]+)\s+(\w+)$', symbols)
            expected = {}
            cursor = 0
            for name, size in FUNCTIONS:
                expected[name] = (cursor, size)
                cursor += size
            self.assertEqual({name: (int(offset, 16), int(size, 16)) for offset, size, name in functions}, expected)
            self.assertEqual(cursor, CODE_END - CODE_START)
            self.assertEqual(len(re.findall(r'(?m)^\w+\s+l\s+O\s+\.rodata\.battle_records_data\s+', symbols)), 6)
            self.assertEqual(len(re.findall(r'(?m)^\w+\s+l\s+O\s+\.rodata\.battle_records_text\s+', symbols)), 2)
            for name, size in {'sTrainerHillWindowTileset': 192, 'sTrainerHillWindowPalette': 32,
                               'sTrainerHillWindowTilemap': 2048, 'sTrainerHillRecordsBgTemplates': 8,
                               'sTrainerHillRecordsWindowTemplates': 16, 'sLinkBattleRecordsWindow': 8}.items():
                self.assertRegex(symbols, r'(?m)^\w+\s+l\s+O\s+\.rodata\.battle_records_data\s+'
                                 + f'{size:08x}' + r'\s+' + name + '$')
            for name, size in {'sText_DashesNoPlayer': 6, 'sText_DashesNoScore': 5}.items():
                self.assertRegex(symbols, r'(?m)^\w+\s+l\s+O\s+\.rodata\.battle_records_text\s+'
                                 + f'{size:08x}' + r'\s+' + name + '$')
            definitions = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', obj], text=True).stdout
            self.assertNotRegex(definitions, r'(?m)^\w+ \w+ [BbDd] ')
            script = temporary / 'module.ld'
            script.write_text('SECTIONS { .records_code ' + hex(CODE_START) + ': { "' + str(obj) + '"(.text) } '
                              '.records_data ' + hex(DATA_START) + ': { "' + str(obj) + '"(.rodata.battle_records_data) '
                              '"' + str(text_obj) + '"(.rodata.strings_battle_records) '
                              '"' + str(obj) + '"(.rodata.battle_records_text) } '
                              '/DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.comment*) *(.note*) *(.ARM.attributes) } }\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), obj, text_obj])
            for section, first, end, digest in (('.records_code', CODE_START, CODE_END, CODE_SHA256),
                                               ('.records_data', DATA_START, DATA_END, DATA_SHA256)):
                output = temporary / (section[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=' + section, elf, output])
                actual = output.read_bytes()
                self.assertEqual(actual, rom[first - 0x08000000:end - 0x08000000], section)
                self.assertEqual(hashlib.sha256(actual).hexdigest(), digest)


if __name__ == '__main__':
    unittest.main()
