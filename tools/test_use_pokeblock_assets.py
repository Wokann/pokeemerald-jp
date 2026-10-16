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
        self.assertEqual(ranges, [(0x5bfa6c, 0x40), (0x5c03c0, 8), (0x5c08c4, 0xd0)])
        self.assertNotIn('.set ', source)
        caller = (ROOT / 'src/use_pokeblock.c').read_text()
        old_names = ['85BE99E', '85BEBC0', '85BF880', '85BF8C0', '85BF9A0',
                     '85BFA4C', '85BFAAC', '85C0230', '85C0410', '85C0488']
        for name in old_names:
            self.assertNotIn('gUnknown_' + name, source + caller)

    def test_linked_owners_preserve_physical_order(self):
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        owners = [
            'src/battle_tower.o(.rodata.battle_tower_small_data)',
            'src/graphics.o(.rodata.use_pokeblock_updown_graphics)',
            'src/graphics.o(.rodata.use_pokeblock_condition_graphics)',
            'src/graphics.o(.rodata.unused_pokenav_menu_data)',
            'src/use_pokeblock.o(.rodata.use_pokeblock_mon_frame_pal)',
            'src/graphics.o(.rodata.unused_pokenav_mon_frame_palette)',
            'src/use_pokeblock.o(.rodata.use_pokeblock_mon_frame_gfx)',
            'src/graphics.o(.rodata.use_pokeblock_graph_palette)',
            'data/data_b2d_mid70.o(.rodata.data_b2d_mid70_after_use_pokeblock_graph_palette)',
            'src/graphics.o(.rodata.use_pokeblock_graph_graphics)',
            'data/data_b2d_mid70.o(.rodata.data_b2d_mid70_after_use_pokeblock_graph_graphics)',
            'src/graphics.o(.rodata.unused_pokenav_condition_frame)',
            'src/graphics.o(.rodata.use_pokeblock_nature_window)',
            'src/graphics.o(.rodata.unused_pokenav_graph_palette)',
            'src/use_pokeblock.o(.rodata.use_pokeblock_graph_data_tilemap)',
            'src/graphics.o(.rodata.unused_pokenav_outline_graphics)',
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

    def test_unused_pokenav_family_has_separate_typed_owners(self):
        header = (ROOT / 'src/data/graphics/unused_pokenav.h').read_text()
        self.assertEqual(len(re.findall(r'const u(?:16|32) gUnusedPokenav', header)), 19)
        self.assertNotIn('.set ', header)
        self.assertIn('gUnusedPokenavMenuHints_Tilemaps[8][2][12]', header)
        self.assertIn('gUnusedPokenavConditionFrame_Tilemap[4][9]', header)
        assets = ROOT / 'graphics/pokenav/unused'
        for name, dims in [('menu', (64, 128)), ('toolbar', (8, 40)),
                           ('backdrop', (8, 8)), ('outline', (64, 48))]:
            self.assertEqual(struct.unpack('>IIBB', (assets / (name + '.png')).read_bytes()[16:26]),
                             (*dims, 4, 3))
        for name, size in [('menu', 1536), ('toolbar', 1280), ('backdrop', 1360), ('outline', 2048)]:
            self.assertEqual((assets / (name + '.bin')).stat().st_size, size)
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('$(JP_UNUSED_POKENAV_ASSETS) $(JP_UNUSED_POKENAV_INTERMEDIATES)', make)
        self.assertIn('$(C_BUILDDIR)/graphics.o: src/data/graphics/unused_pokenav.h', make)

    @unittest.skipUnless((ROOT / 'baserom_jp.gba').is_file(), 'requires the local JP baserom')
    def test_unused_palettes_preserve_rgb_alpha_and_distinct_copies(self):
        header = (ROOT / 'src/data/graphics/unused_pokenav.h').read_text()
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, start in [('Menu', 0x5bed54), ('Toolbar', 0x5bf628),
                            ('Backdrop', 0x5bf798), ('MonFrame', 0x5bf8a0),
                            ('Graph', 0x5c0468), ('Outline', 0x5c052c)]:
            body = re.search(r'gUnusedPokenav' + name + r'_Pal\[16\][^=]*=\s*\{([^}]+)\}', header).group(1)
            entries = re.findall(r'RGB\((\d+), (\d+), (\d+)\)(\s*\| RGB_ALPHA)?', body)
            self.assertEqual(len(entries), 16)
            words = [int(r) | (int(g) << 5) | (int(b) << 10) | (0x8000 if alpha else 0)
                     for r, g, b, alpha in entries]
            self.assertEqual(struct.pack('<16H', *words), rom[start:start + 32], name)

    @unittest.skipUnless(GFX.is_file() and (ROOT / 'baserom_jp.gba').is_file(),
                         'requires the local JP baserom and built gbagfx')
    def test_unused_pokenav_editable_inputs_rebuild_all_eight_resources(self):
        assets = ROOT / 'graphics/pokenav/unused'
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        temp_root = ROOT / '.tmp/agent-work/tests'
        temp_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='unused-pokenav-', dir=temp_root) as temp:
            out = Path(temp)
            for name, start, size, crop, compressed in [
                ('menu', 0x5bed74, 1400, 127, True),
                ('toolbar', 0x5bf648, 160, None, False),
                ('backdrop', 0x5bf7b8, 32, None, False),
                ('outline', 0x5c054c, 528, 43, True),
            ]:
                target = out / (name + '.4bpp')
                flags = ['-num_tiles', str(crop)] if crop else []
                subprocess.run([str(GFX), str(assets / (name + '.png')), str(target), *flags],
                               check=True, capture_output=True)
                if compressed:
                    packed = out / (name + '.4bpp.lz')
                    subprocess.run([str(GFX), str(target), str(packed)], check=True, capture_output=True)
                    target = packed
                self.assertEqual(target.read_bytes(), rom[start:start + size], name)
            for name, start, size in [('menu', 0x5bf2ec, 336), ('toolbar', 0x5bf6e8, 176),
                                      ('backdrop', 0x5bf7d8, 168), ('outline', 0x5c075c, 360)]:
                target = out / (name + '.bin.lz')
                subprocess.run([str(GFX), str(assets / (name + '.bin')), str(target)],
                               check=True, capture_output=True)
                self.assertEqual(target.read_bytes(), rom[start:start + size], name)

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
