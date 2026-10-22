"""Rebuild the complete interleaved JP area-screen graphics/sprite family."""
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
BASE, START, MIDDLE, SUFFIX, GLOBAL, END = 0x08000000, 0x0859381C, 0x08593970, 0x085939A4, 0x08593A9C, 0x08593C80
OBJECTS = {
    'sAreaGlow_Pal': (START, 32), 'sAreaGlow_Gfx': (0x0859383C, 308),
    'sAreaMarkerSpriteSheet': (SUFFIX, 8), 'sAreaMarkerSpritePalette': (0x085939AC, 8),
    'sAreaMarkerOamData': (0x085939B4, 8), 'sAreaMarkerSpriteTemplate': (0x085939BC, 24),
    'sAreaMarkerPalette': (0x085939D4, 32), 'sAreaMarkerTiles': (0x085939F4, 128),
    'sAreaUnknownSpritePalette': (0x08593A74, 8), 'sAreaUnknownOamData': (0x08593A7C, 8),
    'sAreaUnknownSpriteTemplate': (0x08593A84, 24),
    'gPokedexAreaScreenAreaUnknown_Pal': (GLOBAL, 32), 'gPokedexAreaScreenAreaUnknown_Gfx': (0x08593ABC, 452),
}
MIDDLE_OBJECTS = {'sSpeciesHiddenFromAreaScreen': (MIDDLE, 2), 'sMovingRegionMapSections': (0x08593972, 6),
                  'sFeebasData': (0x08593978, 12), 'sLandmarkData': (0x08593984, 28),
                  'sPokedexAreaMapTemplate': (0x085939A0, 4)}
CALL = re.compile(r'INCGFX_(U8|U16|U32)\("([^"]+)", "([^"]+)"\)')


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result.stdout


def owners():
    module = (ROOT / 'src/pokedex_area_screen.c').read_text().split('bool8 DrawAreaGlow(void);')[0]
    graphics = (ROOT / 'src/graphics.c').read_text()
    graphics = graphics[graphics.index('#define POKEDEX_AREA_UNKNOWN_GRAPHICS'):graphics.index('#undef POKEDEX_AREA_UNKNOWN_GRAPHICS')]
    return module, graphics


class PokedexAreaAssetTests(unittest.TestCase):
    def test_complete_resources_use_their_two_actual_us_owners_and_three_final_pngs(self):
        module, graphics = owners()
        calls = CALL.findall(module + graphics)
        self.assertEqual(len(calls), 6)
        self.assertEqual({p for width, p, extension in calls},
                         {'graphics/pokedex/area_glow.png', 'graphics/pokedex/area_marker.png', 'graphics/pokedex/area_unknown.png'})
        for width, path, extension in calls:
            self.assertTrue((ROOT / path).is_file(), path)
        for name in OBJECTS:
            if name.startswith('gPokedex'):
                self.assertRegex(graphics, r'const u(?:16|32) ' + name + r'\[\] = INCGFX_')
            else:
                self.assertRegex(module, r'static const (?:u\d+|struct \w+) ' + name + r'(?:\[\])? POKEDEX_AREA_SCREEN_GRAPHICS_')
        self.assertNotRegex(module + graphics, r'baserom|INCBIN_|\.set\b|\.incbin')
        self.assertFalse((ROOT / 'data/graphics/pokedex_area_screen.s').exists())
        self.assertNotIn('#include "data/pokedex_area_glow.h"', module)

    def test_link_order_preserves_existing_middle_tables_and_keeps_area_unknown_global(self):
        linker, make = (ROOT / 'ld_script_jp.txt').read_text(), (ROOT / 'Makefile').read_text()
        inputs = ('src/pokedex_area_screen.o(.rodata.pokedex_area_screen_graphics_prefix)',
                  'src/pokedex_area_screen.o(.rodata.pokedex_area_screen_data)',
                  'src/pokedex_area_screen.o(.rodata.pokedex_area_screen_graphics_suffix)',
                  'src/graphics.o(.rodata.pokedex_area_unknown_graphics)',
                  'src/evolution_scene.o(.rodata.evolution_scene_graphics)')
        self.assertEqual([linker.count(s) for s in inputs], [1] * 5)
        positions = [linker.index(s) for s in inputs]
        self.assertEqual(positions, sorted(positions))
        self.assertNotIn('data/graphics/pokedex_area_screen.o', linker + make)
        self.assertIn('$(SCANINC) -M $@ -g $(JP_GRAPHICS_GFX_ROOT) -I include -I "" $<', make)
        recipe = re.search(r'(?m)^\$\(C_BUILDDIR\)/pokedex_area_screen\.o:.*\n((?:\t[^\n]*\n)+)', make)[1]
        self.assertIn('$(PREPROC) -i -g $(JP_GRAPHICS_GFX_ROOT)', recipe)
        self.assertIn('/^\\.Lfe[0-9]+:/{print "\\t.align\\t2, 0"}', recipe)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_thirteen_resources_and_five_existing_tables_have_exact_addresses_and_sizes(self):
        wanted = {**OBJECTS, **MIDDLE_OBJECTS}
        output = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', 'pokeemerald_jp.elf'], text=True)
        rows = {name: (int(address, 16), int(size, 16)) for address, size, kind, name in
                re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', output) if name in wanted}
        self.assertEqual(rows, wanted)
        total = sum(size for address, size in OBJECTS.values())
        self.assertEqual(total, 1072)
        names, memory = native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        actual = [body[START - base:END - base] for base, body in memory if base <= START and END <= base + len(body)]
        self.assertEqual(hashlib.sha256(actual[0]).hexdigest(), '7a959132b1a0ea2822a28de2ae0f9d6babf6cd30ad0ee5209b0b5f5bce973004')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_sprite_records_use_real_pointers_native_tags_oam_and_thumb_callback(self):
        output = run(['tools/binutils/bin/arm-none-eabi-nm', '-n', '--defined-only', 'pokeemerald_jp.elf'], text=True)
        names = {name: int(address, 16) for address, kind, name in re.findall(r'(?m)^([0-9a-f]+) (\w) (\S+)$', output)}
        named, memory = native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        def data(name):
            address, size = OBJECTS[name]
            return next(body[address - base:address - base + size] for base, body in memory if base <= address < base + len(body))
        self.assertEqual(struct.unpack('<IHH', data('sAreaMarkerSpriteSheet')), (names['sAreaMarkerTiles'], 128, 2))
        for prefix, tag, palette in (('sAreaMarker', 2, 'sAreaMarkerPalette'), ('sAreaUnknown', 3, 'gPokedexAreaScreenAreaUnknown_Pal')):
            self.assertEqual(struct.unpack('<IHH', data(prefix + 'SpritePalette')), (names[palette], tag, 0))
            self.assertEqual(data(prefix + 'OamData'), bytes.fromhex('0000004000040000' if tag == 2 else '0000008000040000'))
            self.assertEqual(struct.unpack('<HHIIIII', data(prefix + 'SpriteTemplate')),
                             (tag, tag, names[prefix + 'OamData'], names['gDummySpriteAnimTable'], 0,
                              names['gDummySpriteAffineAnimTable'], names['SpriteCallbackDummy'] | 1))

    @unittest.skipUnless((ROOT / 'build/pokeemerald-jp/src/pokedex_area_screen.d').is_file(), 'requires generated dependencies')
    def test_scaninc_closes_every_png_conversion_under_the_shared_build_cache(self):
        for text, dependency in zip(owners(), ('pokedex_area_screen.d', 'graphics.d')):
            closure = (ROOT / 'build/pokeemerald-jp/src' / dependency).read_text()
            for width, path, extension in CALL.findall(text):
                self.assertIn(path, closure)
                self.assertIn('build/pokeemerald-jp/incgfx/' + path + extension, closure)
                self.assertFalse((ROOT / (path + extension)).exists())

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires JP compiler and baseline')
    def test_fresh_pngs_and_typed_records_rebuild_all_1124_bytes_without_old_asm(self):
        parent = ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='pokedex-area-assets-', dir=parent) as directory:
            temporary = Path(directory)
            module, graphics = owners()
            source = module + '\n' + graphics
            calls = list(CALL.finditer(source))
            self.assertEqual(len(calls), 6)
            replacements = {}
            for i, call in enumerate(calls):
                width, path, extension = call.groups()
                raw = temporary / (str(i) + extension.removesuffix('.lz'))
                run(['tools/gbagfx/gbagfx', ROOT / path, raw])
                packed = temporary / (str(i) + extension)
                if extension.endswith('.lz'):
                    run(['tools/gbagfx/gbagfx', raw, packed])
                    self.assertEqual(packed.read_bytes()[-2:], b'\0\0')
                else:
                    packed = raw
                replacements[call[0]] = 'INCBIN_' + width + '("' + str(packed) + '")'
            source = CALL.sub(lambda m: replacements[m[0]], source)
            cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs', '-I', 'tools/agbcc/include',
                       '-I', 'tools/agbcc', '-nostdinc', '-undef', '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True)
            pre = run(['tools/preproc/preproc', '-i', 'src/pokedex_area_screen.c', 'charmap.txt'], input=cpp, text=True)
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm', '-o', '-', '-'], input=pre, text=True)
            obj, elf = temporary / 'owner.o', temporary / 'owner.elf'
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', obj, '-'], input=assembly, text=True)
            script = temporary / 'owner.ld'
            sections = (('prefix', START, MIDDLE, 'pokedex_area_screen_graphics_prefix'),
                        ('middle', MIDDLE, SUFFIX, 'pokedex_area_screen_data'),
                        ('suffix', SUFFIX, GLOBAL, 'pokedex_area_screen_graphics_suffix'),
                        ('unknown', GLOBAL, END, 'pokedex_area_unknown_graphics'))
            script.write_text('SECTIONS {\n' + ''.join('.' + label + ' ' + hex(begin) + ' : { *(.rodata.' + section + ') }\n'
                                                       for label, begin, end, section in sections) + '/DISCARD/ : { *(*) } }\n')
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf, '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), obj])
            rom = (ROOT / 'baserom_jp.gba').read_bytes()
            for label, begin, end, section in sections:
                binary = temporary / (label + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=.' + label, elf, binary])
                self.assertEqual(binary.read_bytes(), rom[begin - BASE:end - BASE], label)


if __name__ == '__main__':
    unittest.main()
