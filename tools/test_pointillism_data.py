"""Whole Pointillism owner, US-style fields and unchanged JP module bytes."""

import hashlib
from pathlib import Path
import re
import subprocess
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[1]
US = ROOT.parent / 'pokeemerald'
HEADER = 'src/data/pointillism_points.h'
SECTION = '.rodata.image_processing_effects'
DATA_START, DATA_END = 0x0857D884, 0x0857FE04
CODE_START, CODE_END = 0x08124F14, 0x08126950
DATA_SHA256 = 'caf846e9b25ded0bcd379fabe82ffeeb61a2ebc0a108ea3201f8645d5d386c67'
CODE_SHA256 = 'c79f2911bf73aa8c4a3b70f629f80dace99b0e47da3111d97973b54070b6ba8e'
POINT_RE = re.compile(r'^\s*PT\(\s*(\d+),\s*(\d+),\s*(\d+),\s*(\d+),\s*(TRUE|FALSE)\),$', re.M)
RAM = {
    'gCanvasColumnStart': 0x03005EA0, 'gCanvasPixels': 0x03005EA4,
    'gCanvasRowEnd': 0x03005EA8, 'gCanvasHeight': 0x03005EAC,
    'gCanvasColumnEnd': 0x03005EB0, 'gCanvasRowStart': 0x03005EB4,
    'gCanvasMonPersonality': 0x03005EB8, 'gCanvasWidth': 0x03005EBC,
    'gCanvasPalette': 0x03005EC0, 'gCanvasPaletteStart': 0x03005EC4,
}


def run(args, **kwargs):
    try:
        return subprocess.run([str(value) for value in args], cwd=ROOT,
                              capture_output=True, check=True, **kwargs)
    except subprocess.CalledProcessError as error:
        raise AssertionError(f'{error.cmd}:\n{error.stderr}') from error


class PointillismDataTests(unittest.TestCase):
    def test_complete_table_has_one_canonical_owner_and_complete_build_dependencies(self):
        source = (ROOT / 'src/image_processing_effects.c').read_text()
        header = (ROOT / HEADER).read_text()
        self.assertFalse((ROOT / 'data/data_b2d_mid61.s').exists())
        mid = (ROOT / 'Makefile').read_text()
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        makefile = (ROOT / 'Makefile').read_text()
        owner = 'src/image_processing_effects.o(' + SECTION + ')'
        self.assertEqual(linker.count(owner), 1)
        self.assertLess(linker.index('src/region_map.o(.rodata.region_map_data)'), linker.index(owner))
        self.assertLess(linker.index(owner), linker.index('src/decoration.o(.rodata.decoration_data)'))
        self.assertNotIn('data_b2d_mid61_after_region_map', linker + mid)
        self.assertNotIn('gUnknown_857D884', source + header + linker + mid)
        self.assertNotIn('baserom_jp.gba', source + header)
        self.assertNotIn('.incbin "baserom_jp.gba", 0x57d884, 0x2580', mid)
        self.assertNotIn('.set ', source + header)
        self.assertIn('#include "data/pointillism_points.h"', source)
        self.assertIn('static const u8 sPointillismPoints[][3] IMAGE_PROCESSING_EFFECTS_DATA = {', header)
        self.assertIn('$(C_BUILDDIR)/image_processing_effects.o: src/image_processing_effects.c ' + HEADER, makefile)
        self.assertIn('src/easy_chat.o(.rodata.easy_chat_restricted_word_species_data)', linker)
        self.assertNotIn('gMonMarkingsMenu_Pal:', mid)
        self.assertIn('src/graphics.o(.rodata.mon_markings_menu_graphics)', linker)
        self.assertIn('gMonMarkingsMenu_Pal[] = INCGFX_U16("graphics/interface/mon_markings_menu.png", ".gbapal")',
                      (ROOT / 'src/graphics.c').read_text())
        self.assertNotIn('.incbin "baserom_jp.gba", 0x582308, 0x20a0', mid)
        self.assertIn('src/graphics.o(.rodata.slot_machine_gfx.gSlotMachineReelSymbol1Tiles)', linker)
        self.assertNotIn('__attribute__((naked))', source)
        self.assertEqual(len(re.findall(r'(?m)^(?:void|u16) \w+\([^;\n]*\)\n\{', source)), 38)
        for name in RAM:
            self.assertRegex(source, r'(?m)^extern (?:u8|u16) \*?' + name + ';$')

    @unittest.skipUnless((US / HEADER).exists(), 'US reference checkout required')
    def test_us_source_style_diff_is_only_the_necessary_jp_link_section_attribute(self):
        source = (ROOT / HEADER).read_text()
        self.assertEqual(source.count(' IMAGE_PROCESSING_EFFECTS_DATA'), 1)
        self.assertEqual(source.replace(' IMAGE_PROCESSING_EFFECTS_DATA', ''), (US / HEADER).read_text())

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').exists(), 'JP ROM required')
    def test_all_3200_records_and_every_packed_field_match_the_original_jp_rom(self):
        header = (ROOT / HEADER).read_text()
        rows = POINT_RE.findall(header)
        self.assertEqual(len(rows), 3200)
        self.assertEqual(header.count('    PT('), 3200)
        packed = bytearray()
        for x, y, delta, color, offset in rows:
            x, y, delta, color = map(int, (x, y, delta, color))
            self.assertTrue(0 <= x < 64 and 0 <= y < 64)
            self.assertTrue(0 <= delta < 8 and 0 <= color < 4)
            bits = delta << 3 | color << 1 | (offset == 'TRUE')
            self.assertEqual(((bits >> 0) & 1, (bits >> 1) & 3, (bits >> 3) & 7),
                             (offset == 'TRUE', color, delta))
            packed.extend((x, y, bits))
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(len(packed), DATA_END - DATA_START)
        self.assertEqual(bytes(packed), rom[DATA_START - 0x08000000:DATA_END - 0x08000000])
        self.assertEqual(hashlib.sha256(packed).hexdigest(), DATA_SHA256)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').exists(), 'linked JP ELF required')
    def test_fresh_c_reproduces_all_38_functions_full_table_and_fixed_iwram_slots(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='pointillism-module-') as directory:
            temporary = Path(directory)
            source = (ROOT / 'src/image_processing_effects.c').read_text()
            cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs',
                       '-I', 'tools/agbcc/include', '-I', 'tools/agbcc', '-nostdinc',
                       '-undef', '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True).stdout
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2',
                            '-fhex-asm', '-o', '-', '-'], input=cpp, text=True).stdout
            assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
            obj = temporary / 'module.o'
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', obj, '-'],
                input=assembly, text=True)
            definitions = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', obj], text=True).stdout
            self.assertEqual(len(re.findall(r'(?m)^\w+ \w+ [Tt] ', definitions)), 38)
            self.assertRegex(definitions, r'(?m)^\w+ 00002580 r sPointillismPoints$')
            for name in RAM:
                self.assertNotRegex(definitions, r'(?m)\b' + name + '$')
            script = temporary / 'module.ld'
            script.write_text('SECTIONS { .text ' + hex(CODE_START) + ': { *(.text) } .rodata '
                              + hex(DATA_START) + ': { *(' + SECTION + ') } /DISCARD/ : '
                              '{ *(.data) *(.bss) *(.comment) *(.note*) *(.ARM.attributes) } }\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), obj])
            for section, start, end, digest in (('.text', CODE_START, CODE_END, CODE_SHA256),
                                                ('.rodata', DATA_START, DATA_END, DATA_SHA256)):
                binary = temporary / (section[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary',
                     '--only-section=' + section, elf, binary])
                actual = binary.read_bytes()
                self.assertEqual(actual, rom[start - 0x08000000:end - 0x08000000], section)
                self.assertEqual(hashlib.sha256(actual).hexdigest(), digest)
            symbols = run(['tools/binutils/bin/arm-none-eabi-nm', '-g', '--defined-only', elf], text=True).stdout
            for name, address in RAM.items():
                self.assertRegex(symbols, r'(?m)^' + f'{address:08x}' + r' \w ' + name + '$')


if __name__ == '__main__':
    unittest.main()
