"""Canonical JSON ownership and byte-exact JP heal-location generation."""

import hashlib
import json
from pathlib import Path
import re
import subprocess
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / 'pokeemerald'
DATA_START = 0x0857B10C
DATA_END = 0x0857B1BC
CODE_START = 0x08122C68
CODE_END = 0x08122CE8
DATA_SHA256 = 'd2ad1747fad52263d2dc66226ba1fa699538648da037b0e7b5f0c9b5e89ebc60'
CODE_SHA256 = 'cb475f1474f82ba3267c833f7cc0f079ffad18ef9a9290d3634649afe2e3d6f7'
JSON_PATH = 'src/data/heal_locations.json'
TEMPLATES = ('src/data/heal_locations.json.txt',
             'src/data/heal_locations.constants.json.txt')
GENERATED = ('src/data/heal_locations.h', 'include/constants/heal_locations.h')


def run(args, **kwargs):
    return subprocess.run(args, cwd=ROOT, capture_output=True, check=True, **kwargs)


class HealLocationGenerationTests(unittest.TestCase):
    @unittest.skipUnless((US / JSON_PATH).exists(), 'US reference checkout required')
    def test_complete_json_templates_and_three_functions_match_the_us_owner(self):
        for path in (JSON_PATH, *TEMPLATES, 'src/heal_location.c'):
            self.assertEqual((ROOT / path).read_text(), (US / path).read_text())
        records = json.loads((ROOT / JSON_PATH).read_text())['heal_locations']
        self.assertEqual(len(records), 22)
        self.assertEqual(len({row['id'] for row in records}), 22)
        self.assertEqual(records[0]['id'], 'HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F')
        self.assertEqual(records[-1]['id'], 'HEAL_LOCATION_BATTLE_FRONTIER_OUTSIDE_EAST')

    def test_real_table_no_longer_borrows_a_placeholder_from_the_ui_owner(self):
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        source = (ROOT / 'src/heal_location.c').read_text()
        mid = (ROOT / 'data/data_b2d_mid61.s').read_text()
        self.assertNotRegex(linker, r'(?m)^\s*sHealLocations\s*=')
        self.assertEqual(linker.count('src/heal_location.o(.rodata)'), 1)
        self.assertLess(linker.index('src/menu_helpers.o(.rodata.menu_helpers_swap_line_data)'),
                        linker.index('src/heal_location.o(.rodata)'))
        self.assertLess(linker.index('src/heal_location.o(.rodata)'),
                        linker.index('src/region_map.o(.rodata.region_map_data)'))
        self.assertNotIn('placeholder', source)
        self.assertNotIn('extern const struct HealLocation', source)
        self.assertNotIn('gUnknown_857B10C', mid)
        self.assertIn('gUnknown_857D884:', mid)
        self.assertIn('sRegionMapCursorPal[]', (ROOT / 'src/region_map.c').read_text())

    def test_build_generates_both_headers_and_cleans_them_not_the_json_sources(self):
        makefile = (ROOT / 'Makefile').read_text()
        self.assertIn('JP_GENERATED_HEAL_LOCATION_HEADERS := ' + ' '.join(GENERATED), makefile)
        self.assertIn('\trm -f $(JP_GENERATED_HEAL_LOCATION_HEADERS)', makefile)
        for path, template in zip(GENERATED, TEMPLATES):
            self.assertIn(path + ': ' + JSON_PATH + ' ' + template + ' | tools\n'
                          '\t$(JSONPROC) $^ $@', makefile)
            ignored = run(['git', 'check-ignore', '--no-index', path], text=True).stdout.strip()
            self.assertEqual(ignored, path)
            tracked = run(['git', 'ls-files', '--', path], text=True).stdout.strip()
            self.assertEqual(tracked, '')
        self.assertIn('$(C_BUILDDIR)/heal_location.o: $(JP_GENERATED_HEAL_LOCATION_HEADERS)', makefile)
        self.assertIn('$(OBJ_DIR)/data/event_scripts.d $(OBJ_DIR)/data/battle_scripts_1.d: '
                      'include/constants/heal_locations.h', makefile)
        self.assertIn('$(C_BUILDDIR)/post_battle_event_funcs.o: include/constants/heal_locations.h', makefile)

    @unittest.skipUnless((ROOT / 'tools/jsonproc/jsonproc').exists(), 'built JSON tool required')
    def test_fresh_headers_are_deterministic_and_have_22_non_placeholder_records(self):
        with tempfile.TemporaryDirectory(prefix='heal-json-') as directory:
            for template, name in zip(TEMPLATES, ('data.h', 'constants.h')):
                output = Path(directory) / name
                run(['tools/jsonproc/jsonproc', JSON_PATH, template, str(output)])
                first = output.read_bytes()
                run(['tools/jsonproc/jsonproc', JSON_PATH, template, str(output)])
                self.assertEqual(output.read_bytes(), first)
                if name == 'data.h':
                    self.assertEqual(len(re.findall(rb'\[HEAL_LOCATION_\w+ - 1\] =', first)), 22)
                    self.assertIn(b'sHealLocations[NUM_HEAL_LOCATIONS - 1]', first)
                else:
                    identifiers = re.findall(rb'^\s*(HEAL_LOCATION_\w+),$', first, re.M)
                    self.assertEqual(len(identifiers), 23)
                    self.assertEqual(identifiers[0], b'HEAL_LOCATION_NONE')

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').exists() and (ROOT / 'pokeemerald_jp.elf').exists(),
                         'JP ROM and linked ELF required')
    def test_from_json_without_existing_headers_full_data_and_code_are_byte_exact(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='heal-object-') as directory:
            temporary = Path(directory)
            data = temporary / 'data.h'
            constants = temporary / 'constants.h'
            for path, template in ((data, TEMPLATES[0]), (constants, TEMPLATES[1])):
                run(['tools/jsonproc/jsonproc', JSON_PATH, template, str(path)])
            source = (ROOT / 'src/heal_location.c').read_text()
            source = source.replace('"data/heal_locations.h"', '"' + str(data) + '"')
            source = source.replace('"constants/heal_locations.h"', '"' + str(constants) + '"')
            cpp = run(['cpp', '-iquote', 'include', '-Wno-trigraphs',
                       '-I', 'tools/agbcc/include', '-I', 'tools/agbcc',
                       '-nostdinc', '-undef', '-std=gnu89', '-P', '-x', 'c', '-'],
                      input=source, text=True).stdout
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2',
                            '-fhex-asm', '-o', '-', '-'], input=cpp, text=True).stdout
            assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
            obj = temporary / 'candidate.o'
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi',
                 '-o', str(obj), '-'], input=assembly, text=True)
            script = temporary / 'candidate.ld'
            script.write_text('SECTIONS { .text ' + hex(CODE_START) + ': { *(.text) } .rodata '
                              + hex(DATA_START) + ': { *(.rodata) } /DISCARD/ : '
                              '{ *(.data) *(.bss) *(.comment) *(.note*) *(.ARM.attributes) } }\n')
            elf = temporary / 'candidate.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', str(script), '-o', str(elf),
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), str(obj)])
            for name, start, end, digest in (('.rodata', DATA_START, DATA_END, DATA_SHA256),
                                            ('.text', CODE_START, CODE_END, CODE_SHA256)):
                binary = temporary / (name[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary',
                     '--only-section=' + name, str(elf), str(binary)])
                value = binary.read_bytes()
                self.assertEqual(value, rom[start - 0x08000000:end - 0x08000000])
                self.assertEqual(hashlib.sha256(value).hexdigest(), digest)
            listing = run(['arm-none-eabi-nm', '-S', str(obj)], text=True).stdout
            records = {fields[3]: (int(fields[0], 16), int(fields[1], 16))
                       for line in listing.splitlines() if len(fields := line.split()) == 4}
            self.assertEqual(records['sHealLocations'], (0, 176))
            self.assertEqual(records['GetHealLocationIndexByMap'], (0, 0x38))
            self.assertEqual(records['GetHealLocationByMap'], (0x38, 0x28))
            self.assertEqual(records['GetHealLocation'], (0x60, 0x20))


if __name__ == '__main__':
    unittest.main()
