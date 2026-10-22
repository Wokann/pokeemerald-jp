"""Keep the JP General tileset reproducible without borrowing US tile pixels."""
import hashlib
from pathlib import Path
import re
import subprocess
import tempfile
import unittest

try:
    from map_semantic_review import native_elf
except ModuleNotFoundError:
    from tools.map_semantic_review import native_elf

ROOT = Path(__file__).resolve().parents[1]
BASE, START, PALETTES, END = 0x08000000, 0x0830FD54, 0x08312028, 0x08312228
DIRECTORY = 'data/tilesets/primary/general/'
CALL = re.compile(r'INCGFX_(U16|U32)\("([^"]+)",\s*"([^"]+)"\)')


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result.stdout


def owner():
    source = (ROOT / 'src/graphics.c').read_text()
    return source[source.index('#define TILESET_GENERAL_DATA'):source.index('#undef TILESET_GENERAL_DATA')]


class GeneralTilesetTests(unittest.TestCase):
    def test_complete_source_family_retains_actual_owner_symbols_and_jp_order(self):
        source = owner()
        self.assertIn('section(".rodata.tileset_general_data"), aligned(1)', source)
        self.assertIn('const u32 gTilesetTiles_General[]', source)
        self.assertIn('const u16 gTilesetPalettes_General[][16]', source)
        self.assertLess(source.index('gTilesetTiles_General'), source.index('gTilesetPalettes_General'))
        calls = CALL.findall(source)
        self.assertEqual(calls, [('U32', DIRECTORY + 'tiles.png', '.4bpp.lz')] +
                         [('U16', DIRECTORY + 'palettes/%02d.pal' % i, '.gbapal') for i in range(16)])
        self.assertNotIn('INCBIN_', source)
        for width, path, extension in calls:
            self.assertTrue((ROOT / path).is_file(), path)
        self.assertFalse((ROOT / (DIRECTORY + 'tiles.4bpp.lz')).exists())
        for i in range(16):
            self.assertFalse((ROOT / (DIRECTORY + 'palettes/%02d.gbapal' % i)).exists())
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        self.assertEqual(linker.count('src/graphics.o(.rodata.tileset_general_data)'), 1)
        self.assertLess(linker.index('src/graphics.o(.rodata.tileset_general_data)'),
                        linker.index('src/tilesets.o(.rodata.tileset_graphics)'))
        header = (ROOT / 'src/data/tilesets/headers.h').read_text()
        self.assertIn('.tiles = gTilesetTiles_General', header)
        self.assertIn('.palettes = gTilesetPalettes_General', header)

    def test_all_sixteen_palettes_remain_readable_including_unused_zero_banks(self):
        for i in range(16):
            lines = (ROOT / (DIRECTORY + 'palettes/%02d.pal' % i)).read_text().splitlines()
            self.assertEqual(lines[:3], ['JASC-PAL', '0100', '16'])
            self.assertEqual(len(lines), 19)
            colors = [tuple(int(v) for v in line.split()) for line in lines[3:]]
            self.assertTrue(all(len(c) == 3 and all(0 <= v <= 255 for v in c) for c in colors))
            if i in (6, 8, 9, 10, 11, 12, 13, 14):
                self.assertEqual(colors, [(0, 0, 0)] * 16)

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').is_file(), 'requires JP baseline')
    def test_jp_pixels_and_all_palette_words_roundtrip_to_exact_native_span(self):
        parent = ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='general-assets-', dir=parent) as directory:
            temporary = Path(directory)
            raw, packed = temporary / 'tiles.4bpp', temporary / 'tiles.4bpp.lz'
            run(['tools/gbagfx/gbagfx', ROOT / (DIRECTORY + 'tiles.png'), raw])
            self.assertEqual(len(raw.read_bytes()), 512 * 32)
            self.assertEqual(hashlib.sha256(raw.read_bytes()).hexdigest(),
                             '65bf71651bdaffd0713be1e1e1cf69349e05391f90f74f5ec39474f6321c22af')
            # Tiles 329 and 330 differ from US; exact JP bytes are authoritative.
            run(['tools/gbagfx/gbagfx', raw, packed])
            self.assertEqual(packed.read_bytes(), rom[START - BASE:PALETTES - BASE])
            self.assertEqual(packed.stat().st_size, 8916)
            self.assertEqual(packed.read_bytes()[-3:], b'\0\0\0')
            palettes = []
            for i in range(16):
                output = temporary / ('%02d.gbapal' % i)
                run(['tools/gbagfx/gbagfx', ROOT / (DIRECTORY + 'palettes/%02d.pal' % i), output])
                self.assertEqual(output.stat().st_size, 32)
                palettes.append(output.read_bytes())
            self.assertEqual(b''.join(palettes), rom[PALETTES - BASE:END - BASE])
            self.assertEqual(hashlib.sha256(packed.read_bytes() + b''.join(palettes)).hexdigest(),
                             '60bc39506b98e12cf86664a50698cf7ba8d473402ced5c4b7c2e9cdafd76bc4b')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_actual_linked_symbols_and_native_bytes_are_unchanged(self):
        names, memory = native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        self.assertEqual(names['gTilesetTiles_General'], {START})
        self.assertEqual(names['gTilesetPalettes_General'], {PALETTES})
        self.assertEqual(names['gTilesetTiles_Petalburg'], {END})
        output = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', 'pokeemerald_jp.elf'], text=True)
        wanted = {'gTilesetTiles_General': (START, PALETTES - START),
                  'gTilesetPalettes_General': (PALETTES, END - PALETTES)}
        records = {name: (int(address, 16), int(size, 16)) for address, size, kind, name in
                   re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', output) if name in wanted}
        self.assertEqual(records, wanted)
        # The final ROM output also contains legacy writable AS inputs. Check
        # const ownership on the C input rather than inferring it from that D/R.
        objects = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only',
                       'build/pokeemerald-jp/src/graphics.o'], text=True)
        types = {name: kind for address, size, kind, name in
                 re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', objects) if name in wanted}
        self.assertEqual(types, {name: 'R' for name in wanted})
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        actual = [body[START - base:END - base] for base, body in memory if base <= START and END <= base + len(body)]
        self.assertEqual(actual, [rom[START - BASE:END - BASE]])

    @unittest.skipUnless((ROOT / 'build/pokeemerald-jp/src/graphics.d').is_file(), 'requires native dependency output')
    def test_graphics_scaninc_uses_matching_build_cache_and_preserves_jp_graph_profile(self):
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('JP_GRAPHICS_GFX_ROOT := $(OBJ_DIR)/incgfx/', make)
        self.assertIn('$(SCANINC) -M $@ -g $(JP_GRAPHICS_GFX_ROOT) -I include -I "" $<', make)
        self.assertIn('$(PREPROC) -i -g $(JP_GRAPHICS_GFX_ROOT) $< charmap.txt', make)
        closure = (ROOT / 'build/pokeemerald-jp/src/graphics.d').read_text()
        for width, path, extension in CALL.findall(owner()):
            self.assertIn(path, closure)
            self.assertIn('build/pokeemerald-jp/incgfx/' + path + extension, closure)
            self.assertFalse((ROOT / (path + extension)).exists())
        self.assertNotIn(DIRECTORY + 'tiles.4bpp.lz', closure)
        source = (ROOT / 'src/graphics.c').read_text()
        self.assertIn('INCGFX_U32("graphics/pokeblock/use_screen/graph.png", ".4bpp.lz", "-num_tiles 125")', source)
        self.assertIn('build/pokeemerald-jp/incgfx/graphics/pokeblock/use_screen/graph.png_num_tiles_125.4bpp.lz', closure)

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').is_file(), 'requires JP compiler and baseline')
    def test_empty_scaninc_cache_generates_and_compiles_the_complete_family(self):
        parent = ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='general-source-chain-', dir=parent) as directory:
            temporary = Path(directory)
            source, dependency, cache = temporary / 'general.c', temporary / 'general.d', temporary / 'cache'
            source.write_text('#include "global.h"\n' + owner())
            run(['tools/scaninc/scaninc', '-M', dependency, '-g', str(cache) + '/', '-I', 'include', '-I', '', source])
            make = temporary / 'test.mk'
            module = temporary / 'general.o'
            make.write_text('.DEFAULT_GOAL := all\nGFX := tools/gbagfx/gbagfx\nall: ' + str(module) + '\n' +
                            str(module) + ': ;\ninclude ' + str(dependency) + '\n%.lz: %\n\t$(GFX) $< $@\n')
            run(['make', '-f', make, '-j16'])
            for width, path, extension in CALL.findall(owner()):
                self.assertTrue((cache / (path + extension)).is_file(), path)
            cpp = run(['cpp', '-iquote', 'include', '-I', 'tools/agbcc/include', '-I', 'tools/agbcc',
                       '-Wno-trigraphs', '-nostdinc', '-undef', '-std=gnu89', '-P', '-x', 'c', source], text=True)
            pre = run(['tools/preproc/preproc', '-i', '-g', str(cache) + '/', source, 'charmap.txt'], input=cpp, text=True)
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm', '-o', '-', '-'], input=pre, text=True)
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', module, '-'], input=assembly, text=True)
            binary = temporary / 'general.bin'
            run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=.rodata.tileset_general_data', module, binary])
            rom = (ROOT / 'baserom_jp.gba').read_bytes()
            self.assertEqual(binary.read_bytes(), rom[START - BASE:END - BASE])


if __name__ == '__main__':
    unittest.main()
