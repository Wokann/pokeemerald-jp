"""Whole-module guards for the JP Mauville Old Man read-only data."""

import hashlib
from pathlib import Path
import re
import struct
import subprocess
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / 'pokeemerald'
START = 0x0857AC08
END = 0x0857AEB4
SECTION = '.rodata.mauville_old_man_data'
REGION_SHA256 = 'b08579fa2749bbd1bb1b9c6f6df557519ecf6a5c49b5349ba72845775e1bf701'
LEGACY = ('gUnknown_857AC08', 'gUnknown_857AC54', 'gUnknown_857AC6C',
          'gUnknown_857AE9C', 'gUnknown_857AEAC')
DATA_OBJECTS = {
    'sDefaultBardSongLyrics': (0x0857AC08, 12),
    'sGiddyAdjectives': (0x0857AC14, 32),
    'sGiddyQuestions': (0x0857AC34, 32),
    'sGiddyEasyChatGroups': (0x0857AC54, 24),
    'sStorytellerStories': (0x0857AC6C, 576),
    'sNumStories': (0x0857AEAC, 4),
    'sUnused': (0x0857AEB0, 4),
}


def initializer(source, name):
    return re.search(r'\b' + name + r'\[[^]]*\][^=]*=\s*(\{.*?\n\});',
                     source, re.S).group(1)


def symbols(path):
    output = subprocess.check_output(['arm-none-eabi-nm', '-n', str(path)], text=True)
    return {fields[2]: int(fields[0], 16) for line in output.splitlines()
            if len(fields := line.split()) == 3}


class MauvilleOldManDataTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.source = (ROOT / 'src/mauville_old_man.c').read_text()

    def test_complete_owner_is_in_the_us_c_module_with_one_linker_input(self):
        mid = (ROOT / 'data/data_b2d_mid61.s').read_text()
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        for name in LEGACY:
            self.assertNotIn(name, self.source)
            self.assertNotIn(name, mid)
        self.assertNotIn('between_mon_markings_and_mail_data', linker)
        self.assertEqual(linker.count('src/mauville_old_man.o(' + SECTION + ')'), 1)
        self.assertNotIn('.incbin', self.source)
        self.assertNotIn('gUnknown_857AC', mid)
        # Mail and all later owners remain outside this conversion.
        self.assertIn('src/mail.o(.rodata.mail_data)', linker)
        self.assertIn('gUnknown_857B10C:', mid)
        for name in DATA_OBJECTS:
            self.assertRegex(self.source, r'static const [^;=\n]*\b' + name + r'\b')

    @unittest.skipUnless((US / 'src/mauville_old_man.c').exists(), 'US reference checkout required')
    def test_all_story_and_giddy_text_labels_match_the_us_owner(self):
        reference = (US / 'src/mauville_old_man.c').read_text()
        for name in ('sGiddyAdjectives', 'sGiddyQuestions', 'sStorytellerStories'):
            self.assertEqual(initializer(self.source, name), initializer(reference, name))
        rows = re.findall(r'\{\s*(\w+),\s*(\d+),\s*(\w+),\s*(\w+),\s*(\w+)\s*\}',
                          initializer(self.source, 'sStorytellerStories'))
        self.assertEqual(len(rows), 36)
        self.assertEqual(sum(int(row[1]) == 2 for row in rows), 1)
        self.assertEqual(rows[0][:2], ('50', '1'))
        self.assertEqual(rows[-1][0], 'GAME_STAT_ENTERED_HOT_SPRINGS')
        declarations = (ROOT / 'include/event_scripts.h').read_text()
        for row in rows:
            for label in row[2:]:
                self.assertIn('extern const u8 ' + label + '[];', declarations)

    def test_jp_song_and_group_ids_preserve_regional_values(self):
        self.assertEqual(re.findall(r'EC_(?:WORD_\w+|MOVE2\(\w+\))',
                                    initializer(self.source, 'sDefaultBardSongLyrics')),
                         ['EC_WORD_YET', 'EC_WORD_DIET', 'EC_WORD_SISTER', 'EC_WORD_SHAKY',
                          'EC_MOVE2(SPLASH)', 'EC_MOVE2(STRUGGLE)'])
        self.assertEqual(re.findall(r'EC_GROUP_\w+',
                                    initializer(self.source, 'sGiddyEasyChatGroups')),
                         ['EC_GROUP_POKEMON', 'EC_GROUP_LIFESTYLE', 'EC_GROUP_HOBBIES',
                          'EC_GROUP_MOVE_1', 'EC_GROUP_MOVE_2', 'EC_GROUP_POKEMON_NATIONAL'])
        self.assertIn('_08120614: .4byte sDefaultBardSongLyrics', self.source)
        self.assertIn('_08120A94: .4byte sGiddyEasyChatGroups', self.source)
        self.assertIn('_0812128C: .4byte sNumStories', self.source)
        self.assertIn('_08121290: .4byte sStorytellerStories', self.source)

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').exists() and (ROOT / 'pokeemerald_jp.elf').exists(),
                         'JP ROM and linked ELF required')
    def test_independent_agbcc_object_reconstructs_every_byte_and_data_boundary(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        expected = rom[START - 0x08000000:END - 0x08000000]
        self.assertEqual(len(expected), 684)
        self.assertEqual(hashlib.sha256(expected).hexdigest(), REGION_SHA256)
        self.assertEqual(struct.unpack_from('<6H', expected), (0x201E, 0x1A1A, 0x0A0F, 0x201A, 0x2696, 0x26A5))
        self.assertEqual(struct.unpack_from('<6I', expected, 0x4C), (0, 12, 13, 18, 19, 21))
        self.assertEqual(struct.unpack_from('<II', expected, 0x2A4), (36, 8))
        with tempfile.TemporaryDirectory(prefix='mauville-data-') as directory:
            temporary = Path(directory)
            cpp = subprocess.run(['cpp', '-iquote', 'include', '-Wno-trigraphs',
                                  '-I', 'tools/agbcc/include', '-I', 'tools/agbcc',
                                  '-nostdinc', '-undef', '-std=gnu89', '-P', '-x', 'c',
                                  'src/mauville_old_man.c'], cwd=ROOT, text=True,
                                 capture_output=True, check=True).stdout
            assembly = subprocess.run(['tools/agbcc/bin/agbcc', '-mthumb-interwork',
                                       '-O2', '-fhex-asm', '-o', '-', '-'], cwd=ROOT,
                                      input=cpp, text=True, capture_output=True, check=True).stdout
            assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
            obj = temporary / 'candidate.o'
            subprocess.run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi',
                            '-o', str(obj), '-'], cwd=ROOT, input=assembly, text=True,
                           capture_output=True, check=True)
            obj_symbols = symbols(obj)
            for name, (address, _) in DATA_OBJECTS.items():
                self.assertEqual(obj_symbols[name], address - START)
            undefined = subprocess.check_output(['arm-none-eabi-nm', '-u', str(obj)], text=True)
            linked_symbols = symbols(ROOT / 'pokeemerald_jp.elf')
            definitions = []
            for line in undefined.splitlines():
                name = line.split()[-1]
                self.assertIn(name, linked_symbols)
                definitions.append('--defsym=' + name + '=' + hex(linked_symbols[name]))
            script = temporary / 'candidate.ld'
            script.write_text('SECTIONS { .rodata ' + hex(START) + ': { *(' + SECTION + ') } '
                              '/DISCARD/ : { *(.text) *(.data) *(.bss) *(.comment) '
                              '*(.note*) *(.ARM.attributes) } }\n')
            elf = temporary / 'candidate.elf'
            subprocess.run(['tools/binutils/bin/arm-none-eabi-ld', '-T', str(script),
                            '-o', str(elf), *definitions, str(obj)], cwd=ROOT,
                           text=True, capture_output=True, check=True)
            binary = temporary / 'candidate.bin'
            subprocess.run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary',
                            '--only-section=.rodata', str(elf), str(binary)],
                           cwd=ROOT, capture_output=True, check=True)
            self.assertEqual(binary.read_bytes(), expected)
            sizes = subprocess.check_output(['arm-none-eabi-nm', '-S', str(elf)], text=True)
            size_by_name = {fields[3]: int(fields[1], 16) for line in sizes.splitlines()
                            if len(fields := line.split()) == 4}
            actual_symbols = symbols(elf)
            for name, (address, size) in DATA_OBJECTS.items():
                self.assertEqual(actual_symbols[name], address)
                self.assertEqual(size_by_name[name], size)


if __name__ == '__main__':
    unittest.main()
