#!/usr/bin/env python3
"""Native JP use-screen asset ownership and byte-exact rebuild contract."""
import re
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ASSET_DIR = ROOT / 'graphics/pokeblock/use_screen'
GFX = ROOT / 'tools/gbagfx/gbagfx'


class UsePokeblockAssetTests(unittest.TestCase):
    def test_native_inputs_and_jp_geometry(self):
        for name, dims in [('updown', (32, 32)), ('condition', (64, 64)),
                           ('mon_frame', (56, 8)), ('graph', (128, 64))]:
            data = (ASSET_DIR / (name + '.png')).read_bytes()
            self.assertEqual(data[:8], b'\x89PNG\r\n\x1a\n')
            self.assertEqual(struct.unpack('>IIBB', data[16:26]), (*dims, 4, 3))
        for name in ['mon_frame', 'graph', 'graph_data']:
            self.assertEqual((ASSET_DIR / (name + '.bin')).stat().st_size, 32 * 20 * 2)
        self.assertEqual((ASSET_DIR / 'mon_frame_pal.bin').stat().st_size, 0x20)
        nature = (ASSET_DIR / 'nature.pal').read_text().splitlines()
        self.assertEqual(nature[:3], ['JASC-PAL', '0100', '44'])
        self.assertEqual(len(nature[3:]), 11 * 4)

    def test_only_confirmed_resources_leave_mid70(self):
        source = (ROOT / 'data/data_b2d_mid70.s').read_text()
        ranges = [(int(start, 0), int(size, 0)) for start, size in re.findall(
            r'\.incbin\s+"baserom_jp\.gba",\s*(0x[0-9a-f]+),\s*(0x[0-9a-f]+)', source)]
        self.assertEqual(ranges, [(0x5bbf1a, 2), (0x5be99e, 2),
                                 (0x5bed54, 0xb2c), (0x5bf8a0, 0x20),
                                 (0x5bfa6c, 0x40), (0x5c03c0, 0x50),
                                 (0x5c0468, 0x20), (0x5c052c, 0x468)])
        self.assertNotIn('.set ', source)
        caller = (ROOT / 'src/use_pokeblock.c').read_text()
        old_names = ['85BE99E', '85BEBC0', '85BF880', '85BF8C0', '85BF9A0',
                     '85BFA4C', '85BFAAC', '85C0230', '85C0410', '85C0488']
        for name in old_names:
            self.assertNotIn('gUnknown_' + name, source + caller)

    def test_linked_owners_preserve_physical_order(self):
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        owners = [
            'data/data_b2d_mid70.o(.rodata.data_b2d_mid70_after_battle_tower_small_data)',
            'src/graphics.o(.rodata.use_pokeblock_updown_graphics)',
            'src/graphics.o(.rodata.use_pokeblock_condition_graphics)',
            'data/data_b2d_mid70.o(.rodata.data_b2d_mid70_after_use_pokeblock_condition_graphics)',
            'src/use_pokeblock.o(.rodata.use_pokeblock_mon_frame_pal)',
            'data/data_b2d_mid70.o(.rodata.data_b2d_mid70_after_use_pokeblock_mon_frame_pal)',
            'src/use_pokeblock.o(.rodata.use_pokeblock_mon_frame_gfx)',
            'src/graphics.o(.rodata.use_pokeblock_graph_palette)',
            'data/data_b2d_mid70.o(.rodata.data_b2d_mid70_after_use_pokeblock_graph_palette)',
            'src/graphics.o(.rodata.use_pokeblock_graph_graphics)',
            'data/data_b2d_mid70.o(.rodata.data_b2d_mid70_after_use_pokeblock_graph_graphics)',
            'src/graphics.o(.rodata.use_pokeblock_nature_window)',
            'data/data_b2d_mid70.o(.rodata.data_b2d_mid70_after_use_pokeblock_nature_window)',
            'src/use_pokeblock.o(.rodata.use_pokeblock_graph_data_tilemap)',
            'data/data_b2d_mid70.o(.rodata.data_b2d_mid70_after_use_pokeblock_graph_data_tilemap)',
            'src/use_pokeblock.o(.rodata.use_pokeblock_static_data)',
        ]
        positions = []
        for owner in owners:
            self.assertEqual(linker.count(owner), 1)
            positions.append(linker.index(owner))
        self.assertEqual(positions, sorted(positions))

    def test_clean_and_generation_have_explicit_prerequisites(self):
        make = (ROOT / 'Makefile').read_text()
        clean = re.search(r'(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)', make).group(1)
        self.assertIn('$(JP_USE_POKEBLOCK_ASSETS)', clean)
        self.assertIn('$(JP_USE_POKEBLOCK_INTERMEDIATES)', clean)
        self.assertNotIn('graphics/pokeblock/use_screen/*.bin', clean)
        self.assertIn('$(C_BUILDDIR)/graphics.o: $(JP_USE_POKEBLOCK_ASSETS)', make)
        self.assertIn('$(C_BUILDDIR)/use_pokeblock.o: $(JP_USE_POKEBLOCK_ASSETS)', make)
        recipe = re.search(r'(?m)^\$\(C_BUILDDIR\)/use_pokeblock\.o: src/use_pokeblock\.c charmap\.txt\n((?:\t[^\n]*\n)+)', make)
        self.assertIsNotNone(recipe)
        self.assertIn('$(PREPROC) -i $< charmap.txt', recipe.group(1))
        rule = re.search(r'(?m)^graphics/pokeblock/use_screen/graph\.png\.4bpp:.*\n(\t[^\n]*)', make)
        self.assertIn('-num_tiles 125', rule.group(1))

    @unittest.skipUnless(GFX.is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires the local JP baserom and built gbagfx')
    def test_all_twelve_native_resources_rebuild_to_rom_bytes(self):
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        with tempfile.TemporaryDirectory(prefix='jp-use-pokeblock-') as temp:
            out = Path(temp)

            def convert(source, name, *options):
                destination = out / name
                subprocess.run([str(GFX), str(source), str(destination), *options],
                               check=True, capture_output=True)
                return destination

            def exact(path, start, size):
                self.assertEqual(path.read_bytes(), rom[start:start+size], path.name)

            for name, start, size, palette, compressed in [
                ('updown', 0x5be9c0, 0x200, 0x5be9a0, False),
                ('condition', 0x5bebc0, 0x174, 0x5bed34, True),
                ('mon_frame', 0x5bf8c0, 0xe0, None, False),
                ('graph', 0x5bfaac, 0x784, 0x5bfa4c, True),
            ]:
                source = ASSET_DIR / (name + '.png')
                options = ('-num_tiles', '125') if name == 'graph' else ()
                tiles = convert(source, name + '.4bpp', *options)
                if compressed:
                    tiles = convert(tiles, name + '.4bpp.lz')
                exact(tiles, start, size)
                if palette is not None:
                    exact(convert(source, name + '.gbapal'), palette, 0x20)
            for name, start, size in [('mon_frame', 0x5bf9a0, 0xac),
                                      ('graph', 0x5c0230, 0x190),
                                      ('graph_data', 0x5c0488, 0xa4)]:
                exact(convert(ASSET_DIR / (name + '.bin'), name + '.bin.lz'), start, size)
            exact(ASSET_DIR / 'mon_frame_pal.bin', 0x5bf880, 0x20)
            exact(convert(ASSET_DIR / 'nature.pal', 'nature.gbapal'), 0x5c0410, 0x58)


if __name__ == '__main__':
    unittest.main()
