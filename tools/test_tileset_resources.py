"""Rebuild every tileset resource, including unused and hidden native objects."""
import hashlib
from pathlib import Path
import re
import shlex
import subprocess
import tempfile
import unittest

try:
    from map_semantic_review import native_elf
except ModuleNotFoundError:
    from tools.map_semantic_review import native_elf

ROOT = Path(__file__).resolve().parents[1]
BASE, START, META, END = 0x08000000, 0x08312228, 0x0836E510, 0x083B7B24
GFX_HEADER = 'src/data/tilesets/graphics.h'
META_HEADER = 'src/data/tilesets/metatiles.h'
CALL = re.compile(r'INCGFX_(U16|U32)\("([^"]+)",\s*"([^"]+)"(?:,\s*"([^"]*)")?\)')
DIGESTS = (
    (START, META, 'e7b7e381c9eada3413dca03abf076258ed47cb2e3e15e48aa1a4883bf09d6afd'),
    (META, END, 'd19b0ce2f9757099ab877f05dd5a30ed11a82c931f0811b621dc39a38aebd3b5'),
    (END, END + 1808, 'a433cf4f18a1f7171eee896419fc9f720a985c0dfb0b82cf12a0fd23661a65aa'),
)


def run(args, **kwargs):
    result = subprocess.run([str(a) for a in args], cwd=ROOT, capture_output=True, **kwargs)
    if result.returncode:
        raise AssertionError(str(args) + '\n' + str(result.stderr))
    return result.stdout


def definitions(path):
    return re.findall(r'(?m)^const (u16|u32) (\w+)(\[\](?:\[16\])?) TILESET_(?:GRAPHICS|METATILES)_DATA\s*=\s*(.*?);',
                      (ROOT / path).read_text(), re.S)


def symbols():
    output = run(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only', ROOT / 'pokeemerald_jp.elf'], text=True)
    return {name: (int(address, 16), int(size, 16)) for address, size, kind, name in
            re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', output)}


class TilesetResourceTests(unittest.TestCase):
    def test_complete_family_uses_final_c_owners_and_all_1400_source_assets_exist(self):
        graphics, metadata = definitions(GFX_HEADER), definitions(META_HEADER)
        self.assertEqual(len(graphics), 156)
        self.assertEqual(len(metadata), 140)
        self.assertEqual(sum(dimensions == '[][16]' for ctype, name, dimensions, expression in graphics), 74)
        self.assertEqual(sum(ctype == 'u32' for ctype, name, dimensions, expression in graphics), 82)
        calls = CALL.findall((ROOT / GFX_HEADER).read_text())
        self.assertEqual(len(calls), 1266)
        source_paths = {path for width, path, extension, options in calls}
        bins = re.findall(r'INCBIN_U16\("([^"]+)"\)', (ROOT / META_HEADER).read_text())
        self.assertEqual(len(bins), len(set(bins)), 140)
        self.assertEqual(len(bins), 140)
        self.assertEqual(sum(p.endswith('.png') for p in source_paths), 76)
        self.assertEqual(sum(p.endswith('.pal') for p in source_paths), 1184)
        self.assertEqual(len(source_paths | set(bins)), 1400)
        for path in source_paths | set(bins):
            self.assertTrue((ROOT / path).is_file(), path)
        for name in ('data/tilesets.s', 'data/tilesets/graphics.inc', 'data/tilesets/metatiles.inc'):
            self.assertFalse((ROOT / name).exists())
        for path in (GFX_HEADER, META_HEADER):
            self.assertNotRegex((ROOT / path).read_text(), r'baserom_jp|\.set\b|\.incbin\b|asm\s*\(')

    def test_seventy_four_palette_tables_are_readable_sixteen_by_sixteen_colors(self):
        for ctype, name, dimensions, expression in definitions(GFX_HEADER):
            if dimensions != '[][16]':
                continue
            self.assertEqual(ctype, 'u16')
            calls = CALL.findall(expression)
            self.assertEqual(len(calls), 16, name)
            for i, (width, path, extension, options) in enumerate(calls):
                self.assertEqual(width, 'U16')
                self.assertEqual(extension, '.gbapal')
                self.assertEqual(Path(path).name, '%02d.pal' % i)
                lines = (ROOT / path).read_text().splitlines()
                self.assertEqual(lines[:3], ['JASC-PAL', '0100', '16'])
                self.assertEqual(len(lines), 19)
                self.assertTrue(all(len(line.split()) == 3 and all(0 <= int(v) <= 255 for v in line.split()) for line in lines[3:]))

    def test_all_seventy_metatile_pairs_have_matching_typed_record_counts(self):
        rows = definitions(META_HEADER)
        for tiles, attributes in zip(rows[::2], rows[1::2]):
            self.assertEqual(tiles[0], 'u16')
            self.assertEqual(attributes[0], 'u16')
            self.assertEqual(attributes[1], tiles[1].replace('gMetatiles_', 'gMetatileAttributes_', 1))
            tile_path = re.fullmatch(r'INCBIN_U16\("([^"]+)"\)', tiles[3])[1]
            attr_path = re.fullmatch(r'INCBIN_U16\("([^"]+)"\)', attributes[3])[1]
            tile_bytes = (ROOT / tile_path).stat().st_size
            attr_bytes = (ROOT / attr_path).stat().st_size
            self.assertEqual(tile_bytes % 16, 0)
            self.assertEqual(attr_bytes % 2, 0)
            self.assertEqual(tile_bytes // 16, attr_bytes // 2, tiles[1])

    def test_unused_compressed_and_hidden_objects_are_explicit_not_folded_into_other_arrays(self):
        rows = {name: expression for ctype, name, dimensions, expression in definitions(GFX_HEADER)}
        for suffix in ('BrownCave', 'Tree', 'Shrub', 'BlueCave', 'YellowCave', 'RedCave'):
            self.assertIn('".4bpp.lz", "-num_tiles 82 -Wnum_tiles"', rows['gTilesetTiles_SecretBase' + suffix + 'Compressed'])
            self.assertIn('".4bpp", "-num_tiles 83 -Wnum_tiles"', rows['gTilesetTiles_SecretBase' + suffix])
        self.assertIn('".4bpp", "-num_tiles 120 -Wnum_tiles"', rows['gTilesetTiles_UnknownCableClub'])
        self.assertIn('unknown_tiles.png', rows['gTilesetTiles_UnknownSecretBase'])
        self.assertIn('".4bpp"', rows['gTilesetTiles_CableClub'])
        self.assertNotIn('".4bpp.lz"', rows['gTilesetTiles_CableClub'])
        self.assertIn('-num_tiles 17 -Wnum_tiles', rows['gTilesetTiles_Unused1'])
        self.assertIn('-num_tiles 150 -Wnum_tiles', rows['gTilesetTiles_Unused2'])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_296_native_object_sizes_close_the_two_original_streams_without_gaps(self):
        named = symbols()
        halfword_only = 0
        for header, begin, end, alignment in ((GFX_HEADER, START, META, 4), (META_HEADER, META, END, 2)):
            cursor = begin
            for ctype, name, dimensions, expression in definitions(header):
                address, size = named[name]
                self.assertEqual(address, cursor, name)
                self.assertEqual(address % alignment, 0, name)
                self.assertGreater(size, 0)
                halfword_only += header == META_HEADER and address % 4 == 2
                cursor += size
            self.assertEqual(cursor, end)
        self.assertEqual(halfword_only, 76)
        self.assertEqual(named['gTilesetTiles_UnknownCableClub'], (0x08335FEC, 3840))
        self.assertEqual(named['gTilesetTiles_UnknownSecretBase'], (0x08356E68, 16384))
        self.assertEqual(named['gTilesetPalettes_SecretBase'], (0x0835AE68, 512))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_three_complete_native_spans_retain_their_original_bytes(self):
        named, memory = native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for begin, end, digest in DIGESTS:
            data = rom[begin - BASE:end - BASE]
            self.assertEqual(hashlib.sha256(data).hexdigest(), digest)
            actual = [body[begin - base:end - base] for base, body in memory if base <= begin and end <= base + len(body)]
            self.assertEqual(actual, [data])
        self.assertEqual(named['PetalburgCity_Layout_Border'], {END + 1808})

    @unittest.skipUnless((ROOT / 'build/pokeemerald-jp/src/tilesets.d').is_file(), 'requires native dependency output')
    def test_scaninc_closes_every_generated_input_and_keeps_all_conversion_cache_in_build(self):
        closure = (ROOT / 'build/pokeemerald-jp/src/tilesets.d').read_text()
        for width, path, extension, options in CALL.findall((ROOT / GFX_HEADER).read_text()):
            encoded = path + re.sub(r'[^A-Za-z0-9]', '_', options) + extension
            self.assertIn(path, closure)
            self.assertIn('build/pokeemerald-jp/incgfx/' + encoded, closure)
            self.assertFalse((ROOT / encoded).exists(), encoded)
        for path in re.findall(r'INCBIN_U16\("([^"]+)"\)', (ROOT / META_HEADER).read_text()):
            self.assertIn(path, closure)
        self.assertNotIn('data/tilesets/graphics.inc', closure)
        self.assertNotIn('data/tilesets/metatiles.inc', closure)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires JP compiler and native artifacts')
    def test_fresh_full_module_from_png_pal_and_structured_metadata_reproduces_all_679948_bytes(self):
        parent = ROOT / '.tmp/agent-work/tests'
        parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='tileset-resources-', dir=parent) as directory:
            temporary = Path(directory)
            graphics = (ROOT / GFX_HEADER).read_text()
            calls = list(CALL.finditer(graphics))
            self.assertEqual(len(calls), 1266)
            replacements = {}
            for i, call in enumerate(calls):
                width, path, extension, options = call.groups()
                output = temporary / (str(i) + extension)
                raw = output.with_name(output.name.removesuffix('.lz'))
                run(['tools/gbagfx/gbagfx', ROOT / path, raw, *shlex.split(options or '')])
                if extension.endswith('.lz'):
                    run(['tools/gbagfx/gbagfx', raw, output])
                else:
                    output = raw
                replacements[call[0]] = 'INCBIN_' + width + '("' + str(output) + '")'
            graphics = CALL.sub(lambda m: replacements[m[0]], graphics)
            source = (ROOT / 'src/tilesets.c').read_text().replace('#include "data/tilesets/graphics.h"', graphics)
            cpp = run(['cpp', '-iquote', 'include', '-iquote', 'src', '-Wno-trigraphs', '-I', 'tools/agbcc/include',
                       '-I', 'tools/agbcc', '-nostdinc', '-undef', '-std=gnu89', '-P', '-x', 'c', '-'], input=source, text=True)
            pre = run(['tools/preproc/preproc', '-i', 'src/tilesets.c', 'charmap.txt'], input=cpp, text=True)
            assembly = run(['tools/agbcc/bin/agbcc', '-mthumb-interwork', '-O2', '-fhex-asm', '-o', '-', '-'], input=pre, text=True)
            module = temporary / 'module.o'
            run(['tools/binutils/bin/arm-none-eabi-as', '-mcpu=arm7tdmi', '-o', module, '-'], input=assembly, text=True)
            script = temporary / 'module.ld'
            script.write_text('SECTIONS { .graphics 0x08312228 : { *module.o(.rodata.tileset_graphics) }\n'
                              '.metatiles 0x0836E510 : { *module.o(.rodata.tileset_metatiles) }\n'
                              '.headers 0x083B7B24 : { *module.o(.rodata.tileset_headers) } /DISCARD/ : { *(*) } }\n')
            elf = temporary / 'module.elf'
            run(['tools/binutils/bin/arm-none-eabi-ld', '-T', script, '-o', elf,
                 '--just-symbols=' + str(ROOT / 'pokeemerald_jp.elf'), module])
            rom = (ROOT / 'baserom_jp.gba').read_bytes()
            for section, (begin, end, digest) in zip(('.graphics', '.metatiles', '.headers'), DIGESTS):
                output = temporary / (section[1:] + '.bin')
                run(['tools/binutils/bin/arm-none-eabi-objcopy', '-O', 'binary', '--only-section=' + section, elf, output])
                self.assertEqual(output.read_bytes(), rom[begin - BASE:end - BASE], section)


if __name__ == '__main__':
    unittest.main()
