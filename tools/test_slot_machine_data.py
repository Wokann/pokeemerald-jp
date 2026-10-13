"""Complete native SlotMachine ownership, ABI, assets and unchanged JP bytes."""

import hashlib
from pathlib import Path
import re
import subprocess
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[1]
HEADER = 'src/data/graphics/slot_machine.h'
CODE_START, CODE_END = 0x0812A4EC, 0x0812FDE0
DATA_START, DATA_END = 0x08582308, 0x085886AC
CODE_SHA256 = 'c6d47b2b3e75ad924829f809b9e193b41a80b7b6a9adc4010f61ca5b4d90b40a'
DATA_SHA256 = 'e427ae35f89409f31fa7f5489934ee8fe2cbf22a405375f3505b36713a349137'
RESOURCE_RE = re.compile(r'^SLOT_MACHINE_GRAPHICS\((\w+)\) const (u8|u16|u32) \w+\[\] = INCBIN_U(?:8|16|32)\("([^"]+)"\);$', re.M)
OTHER_GRAPHICS = {
    'gSlotMachineMenu_Pal': (0x0858544C, 160),
    'gSlotMachineMenu_Gfx': (0x08586F4C, 2976),
    'gSlotMachineMenu_Tilemap': (0x08587AEC, 1200),
    'gSlotMachineInfoBox_Tilemap': (0x08588154, 1200),
    'gSlotMachineDigitalDisplay_Gfx': (0x08585690, 1896),
}
PALETTES = (
    'gSlotMachineReelSymbols_Pal', 'gSlotMachineReelTimePikachu_Pal',
    'gSlotMachineReelTimeMisc_Pal', 'gSlotMachineReelTimeMachine_Pal',
    'gSlotMachineMisc_Pal', 'gSlotMachineReelTimeExplosion_Pal',
    'gSlotMachineDigitalDisplay_Pal',
)
OBSOLETE = (
    'src/data/slot_machine.c', 'src/data/slot_machine.h',
    'src/data/text/region_texts38.c', 'src/data/text/region_texts38.h',
    'src/data/text/region_texts62.c', 'src/data/text/region_texts62.h',
)


def run(args, **kwargs):
    try:
        return subprocess.run([str(value) for value in args], cwd=ROOT,
                              capture_output=True, check=True, **kwargs)
    except subprocess.CalledProcessError as error:
        raise AssertionError(f'{error.cmd}:\n{error.stderr}') from error


def fresh_object(source, output, name, function_sections=False):
    cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs',
               '-I', 'tools/agbcc/include', '-I', 'tools/agbcc', '-nostdinc',
               '-undef', '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True).stdout
    preprocessed = run(['tools/preproc/preproc', '-i', name, 'charmap.txt'],
                       input=cpp, text=True).stdout
    flags = ['-mthumb-interwork', '-O2', '-fhex-asm']
    if function_sections:
        flags.append('-ffunction-sections')
    assembly = run(['tools/agbcc/bin/agbcc', *flags, '-o', '-', '-'],
                   input=preprocessed, text=True).stdout
    assembly = re.sub(r'(?m)^(\.Lfe\d+:)', r'\t.align\t2, 0\n\1', assembly)
    run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', output, '-'],
        input=assembly, text=True)


class SlotMachineDataTests(unittest.TestCase):
    def test_complete_canonical_owners_and_native_build_chain(self):
        source = (ROOT / 'src/slot_machine.c').read_text()
        header = (ROOT / HEADER).read_text()
        graphics = (ROOT / 'src/graphics.c').read_text()
        strings = (ROOT / 'src/strings.c').read_text()
        make = (ROOT / 'Makefile').read_text()
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        mid = (ROOT / 'data/data_b2d_mid61.s').read_text()
        for path in OBSOLETE:
            self.assertFalse((ROOT / path).exists(), path)
        self.assertIn('#include "data/graphics/slot_machine.h"', graphics)
        self.assertEqual(len(RESOURCE_RE.findall(header)), 46)
        self.assertNotIn('data/slot_machine/jp/', source + header + linker + make)
        self.assertNotIn('baserom_jp.gba', source + header)
        self.assertNotIn('gUnknown_858', source + header + linker)
        self.assertNotIn('region_texts38.o', linker)
        self.assertNotIn('region_texts62.o', linker)
        self.assertNotIn('src/data/slot_machine.o', linker + make)
        self.assertNotIn('data_b2d_mid61_after_decoration', linker + mid)
        self.assertNotIn('__attribute__((naked))', source)
        self.assertIn('static const struct SpriteTemplate sSpriteTemplate_ReelTimeSmoke', source)
        self.assertIn('static const struct Subsprite sSubsprites_DigitalDisplay_Unused1', source)
        self.assertIn('static const u16 *sSlotMachineMenu_Pal =', source)
        self.assertIn('(GFXTAG_NUM_0 << 16)', source)
        slot_text = strings[strings.index('#define STRINGS_SLOT_MACHINE'):]
        self.assertRegex(slot_text, r'const u8 gText_ReelTimeHelp\[\] = __\(\s*"BDタイム')
        self.assertIn('ビッグボーナスがでると　しゅうりょう$　");', strings)
        self.assertIn('$(PREPROC) -i $< charmap.txt', make[make.rfind('$(C_BUILDDIR)/slot_machine.o:'):])
        self.assertIn('rm -f $(JP_SLOT_MACHINE_ASSETS) $(JP_SLOT_MACHINE_INTERMEDIATES)', make)
        self.assertIn('graphics/slot_machine/reel_time_gfx.4bpp:', make)
        first = linker.index('src/graphics.o(.rodata.slot_machine_gfx.gSlotMachineReelSymbol1Tiles)')
        last = linker.index('src/strings.o(.rodata.strings_slot_machine)')
        self.assertLess(first, last)
        self.assertLess(last, linker.index('src/contest_painting.o(.rodata.contest_painting_data)'))
        self.assertNotIn('gMonMarkingsMenu_Pal:', mid)
        self.assertIn('src/graphics.o(.rodata.mon_markings_menu_graphics)', linker)
        self.assertIn('gMonMarkingsMenu_Pal[] = INCGFX_U16("graphics/interface/mon_markings_menu.png", ".gbapal")',
                      (ROOT / 'src/graphics.c').read_text())

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').exists(), 'JP ROM required')
    def test_every_native_graphic_round_trips_from_its_editable_source(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        cursor = DATA_START
        specs = RESOURCE_RE.findall((ROOT / HEADER).read_text())
        with tempfile.TemporaryDirectory(prefix='slot-machine-assets-') as directory:
            temporary = Path(directory)
            def encode(path, name):
                path = Path(path)
                if path.suffix == '.bin':
                    return (ROOT / path).read_bytes()
                compressed = path.suffix == '.lz'
                raw_path = Path(str(path)[:-3]) if compressed else path
                native = raw_path.with_suffix('.pal') if raw_path.suffix == '.gbapal' else raw_path.with_suffix('.png')
                if not (ROOT / native).exists():
                    native = raw_path.with_suffix('.png')
                self.assertTrue((ROOT / native).exists(), str(native))
                output = temporary / (name + raw_path.suffix)
                run(['tools/gbagfx/gbagfx', ROOT / native, output])
                if compressed:
                    packed = temporary / (name + '.4bpp.lz')
                    run(['tools/gbagfx/gbagfx', output, packed])
                    output = packed
                return output.read_bytes()
            for name, kind, path in specs:
                encoded = encode(path, name)
                if kind == 'u8':
                    start, size = cursor, len(encoded)
                    cursor += size
                elif name in PALETTES:
                    start, size = 0x0858536C + 32 * PALETTES.index(name), 32
                else:
                    start, size = OTHER_GRAPHICS[name]
                self.assertEqual(len(encoded), size, name)
                self.assertEqual(encoded, rom[start - 0x08000000:start - 0x08000000 + size], name)
            self.assertEqual(cursor, 0x085843A8)
            for part in ('reel_time_pikachu', 'reel_time_machine'):
                run(['tools/gbagfx/gbagfx', ROOT / ('graphics/slot_machine/' + part + '.png'),
                     temporary / (part + '.4bpp')])
            combined = temporary / 'reel_time_gfx.4bpp'
            combined.write_bytes((temporary / 'reel_time_pikachu.4bpp').read_bytes()
                                 + (temporary / 'reel_time_machine.4bpp').read_bytes())
            packed = temporary / 'reel_time_gfx.4bpp.lz'
            run(['tools/gbagfx/gbagfx', combined, packed])
            self.assertEqual(packed.read_bytes(), rom[0x585DF8:0x586F4C])
            for stem, offset in (('flashing_lights_inside', 0x585542),
                                 ('flashing_lights_middle', 0x585562),
                                 ('flashing_lights_outside', 0x585582),
                                 ('pokeball_shining_0', 0x5855B4),
                                 ('pokeball_shining_1', 0x5855D4),
                                 ('pokeball_shining_2', 0x5855F4)):
                self.assertEqual(encode('graphics/slot_machine/' + stem + '.gbapal', stem), rom[offset:offset + 32])
            self.assertEqual((ROOT / 'graphics/slot_machine/reel_time_window.bin').read_bytes(), rom[0x587F9C:0x588154])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').exists(), 'linked JP ELF required')
    def test_fresh_c_matches_all_254_functions_complete_data_and_real_abi_sizes(self):
        source = (ROOT / 'src/slot_machine.c').read_text()
        strings = (ROOT / 'src/strings.c').read_text()
        text = strings[strings.index('#define STRINGS_SLOT_MACHINE'):strings.index('#undef STRINGS_SLOT_MACHINE')]
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        code = '\n'.join(re.findall(r'(?m)^\s*src/slot_machine\.o\(\.text\.[^)]+\);', linker))
        start = linker.index('        src/graphics.o(.rodata.slot_machine_gfx.gSlotMachineReelSymbol1Tiles);')
        end = linker.index('        src/contest_painting.o(.rodata.contest_painting_data);', start)
        data = linker[start:end]
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='slot-machine-module-') as directory:
            temporary = Path(directory)
            objects = {name: temporary / (name + '.o') for name in ('slot_machine', 'graphics', 'strings')}
            fresh_object(source, objects['slot_machine'], 'src/slot_machine.c', True)
            fresh_object('#include "global.h"\n#include "data/graphics/slot_machine.h"\n', objects['graphics'], 'src/graphics.c')
            fresh_object('#include "global.h"\n' + text, objects['strings'], 'src/strings.c')
            definitions = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', objects['slot_machine']], text=True).stdout
            self.assertEqual(len(re.findall(r'(?m)^\w+ \w+ [Tt] ', definitions)), 254)
            for name, size in {'sSpriteTemplate_ReelTimeSmoke': 24, 'sSpriteTemplate_PikaPowerBolt': 24,
                               'sReelBackground_Tilemap': 4, 'sDigitalDisplay_SpriteCoords': 140,
                               'sAffineAnim_ReelTimeSmoke': 40, 'sAffineAnim_PikaPowerBolt': 80,
                               'sSubsprites_DigitalDisplay_Unused1': 16,
                               'sSubspriteTable_DigitalDisplay_Unused1': 8}.items():
                self.assertRegex(definitions, r'(?m)^\w+ ' + f'{size:08x}' + r' r ' + name + '$')
            for name in ('sSlotMachine', 'sMenuGfx', 'sImageTables_DigitalDisplay'):
                self.assertNotRegex(definitions, r'(?m)\b' + name + '$')
            def substitute(text):
                for name, obj in objects.items():
                    text = text.replace('src/' + name + '.o(', '"' + str(obj) + '"(')
                return text
            script = temporary / 'module.ld'
            script.write_text('SECTIONS { .slot_code ' + hex(CODE_START) + ': { ' + substitute(code)
                              + ' } .slot_data ' + hex(DATA_START) + ': { ' + substitute(data)
                              + ' } /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) '
                              + '*(.comment*) *(.note*) *(.ARM.attributes) } }\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), *objects.values()])
            for section, first, last, digest in (('.slot_code', CODE_START, CODE_END, CODE_SHA256),
                                                 ('.slot_data', DATA_START, DATA_END, DATA_SHA256)):
                output = temporary / (section[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=' + section, elf, output])
                actual = output.read_bytes()
                self.assertEqual(actual, rom[first - 0x08000000:last - 0x08000000], section)
                self.assertEqual(hashlib.sha256(actual).hexdigest(), digest)


if __name__ == '__main__':
    unittest.main()
