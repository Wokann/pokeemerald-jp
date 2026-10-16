#!/usr/bin/env python3
"""The complete item graphics/table family is editable and native-byte exact."""
import re
import shutil
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GFX = ROOT / 'tools/gbagfx/gbagfx'
NM = shutil.which('arm-none-eabi-nm')
START, END = 0x08DAB300, 0x08DB7D48


def resources():
    source = (ROOT / 'src/data/graphics/items.h').read_text()
    return re.findall(r'^ITEM_ICONS_GRAPHICS const u32 (\w+)\[\] = INCGFX_U32\("([^"]+)", "([^"]+)"\);', source, re.M)


def entries():
    source = (ROOT / 'src/data/item_icon_table.h').read_text()
    return re.findall(r'^\s*\[(\w+)\] = \{(\w+), (\w+)\},', source, re.M)


class ItemIconAssetTests(unittest.TestCase):
    def test_whole_family_uses_source_formats_and_real_labels(self):
        rows = resources()
        self.assertEqual(len(rows), 471)
        self.assertEqual(len({n for n, p, e in rows}), 471)
        self.assertEqual(len({p for n, p, e in rows}), 471)
        table = entries()
        self.assertEqual(len(table), 378)
        self.assertEqual({n for n, p, e in rows}, {n for item, pic, pal in table for n in (pic, pal)})
        self.assertEqual(table[-1], ('ITEMS_COUNT', 'gItemIcon_ReturnToFieldArrow', 'gItemIconPalette_ReturnToFieldArrow'))
        for name, path, extension in rows:
            self.assertTrue((ROOT / path).is_file(), path)
            self.assertIn(extension, ('.4bpp.lz', '.gbapal.lz'))
        source = (ROOT / 'src/data/item_icon_table.h').read_text()
        self.assertNotRegex(source, r'0x08[0-9a-fA-F]{6}|\(const u32 \*\)')

    def test_shared_pictures_and_palettes_remain_shared(self):
        table = {item: (pic, pal) for item, pic, pal in entries()}
        self.assertEqual(table['ITEM_REPEAT_BALL'][1], table['ITEM_TIMER_BALL'][1])
        self.assertEqual(table['ITEM_LUXURY_BALL'][1], table['ITEM_PREMIER_BALL'][1])
        self.assertEqual(table['ITEM_BURN_HEAL'][0], table['ITEM_ICE_HEAL'][0])
        self.assertEqual(table['ITEM_TM01'][0], table['ITEM_TM50'][0])
        self.assertEqual(table['ITEM_HM01'][0], table['ITEM_HM08'][0])
        self.assertEqual(table['ITEM_RUBY'][0], table['ITEM_SAPPHIRE'][0])
        self.assertNotEqual(table['ITEM_RUBY'][1], table['ITEM_SAPPHIRE'][1])

    def test_build_chain_and_public_declarations_cover_every_resource(self):
        make = (ROOT / 'Makefile').read_text()
        header = (ROOT / 'include/graphics.h').read_text()
        source = (ROOT / 'src/graphics.c').read_text()
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        self.assertIn('#include "data/graphics/items.h"', source)
        self.assertIn('section(".rodata.item_icon_graphics"), aligned(4)', source)
        self.assertEqual(linker.count('src/graphics.o(.rodata.item_icon_graphics);'), 1)
        self.assertLess(linker.index('data/data_rest2c.o(.rodata.data_rest2c_after_chases_away)'), linker.index('src/graphics.o(.rodata.item_icon_graphics)'))
        self.assertLess(linker.index('src/graphics.o(.rodata.item_icon_graphics)'), linker.index('src/graphics.o(.rodata.decoration_icons)'))
        self.assertIn('rm -f $(JP_ITEM_ICON_ASSETS) $(JP_ITEM_ICON_INTERMEDIATES)', make)
        self.assertIn('$(C_BUILDDIR)/graphics.o: src/data/graphics/items.h $(JP_ITEM_ICON_ASSETS)', make)
        self.assertIn('$(C_BUILDDIR)/item_icon.o: src/data/item_icon_table.h include/graphics.h', make)
        self.assertIn('$(JP_ITEM_ICON_ASSETS): %.lz: % Makefile | tools', make)
        for name, path, extension in resources():
            self.assertEqual(header.count('extern const u32 ' + name + '[];'), 1, name)
            self.assertIn(path + extension, make)

    def test_aggregated_raw_owner_is_removed_without_absorbing_neighbors(self):
        source = (ROOT / 'data/data_rest2c.s').read_text()
        self.assertNotIn('gItemIcon_', source)
        self.assertNotRegex(source, r'0xdab300|0xdab378|0xdab38c|0xc9bc')
        self.assertIn('0xdab2fd, 0x3', source)
        self.assertIn('0xDBC236, 0x2', source)
        self.assertIn('0xDBDD61, 0x24229F', source)

    @unittest.skipUnless(GFX.is_file() and NM and (ROOT / 'pokeemerald_jp.elf').is_file()
                         and (ROOT / 'baserom_jp.gba').is_file(), 'requires native JP artifacts and gbagfx')
    def test_all_471_assets_and_756_table_pointers_match_native_bytes(self):
        output = subprocess.check_output([NM, '-S', '--defined-only', str(ROOT / 'pokeemerald_jp.elf')], text=True)
        symbols = {}
        for address, size, kind, name in re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', output):
            symbols.setdefault(name, []).append((int(address, 16), int(size, 16)))
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        temporary_root = ROOT / '.tmp/agent-work/tests'
        temporary_root.mkdir(parents=True, exist_ok=True)
        cursor = START
        with tempfile.TemporaryDirectory(prefix='item-icons-', dir=temporary_root) as temp:
            for i, (name, path, extension) in enumerate(resources()):
                self.assertEqual(len(symbols[name]), 1, name)
                address, size = symbols[name][0]
                self.assertEqual(address, cursor, name)
                raw = Path(temp) / (str(i) + extension.removesuffix('.lz'))
                packed = raw.with_name(raw.name + '.lz')
                subprocess.run([str(GFX), str(ROOT / path), str(raw)], check=True, capture_output=True)
                subprocess.run([str(GFX), str(raw), str(packed)], check=True, capture_output=True)
                self.assertEqual(len(packed.read_bytes()), size, name)
                self.assertEqual(packed.read_bytes(), rom[address - 0x08000000:address - 0x08000000 + size], name)
                cursor += size
        self.assertEqual(cursor, END)
        native_table = b''.join(struct.pack('<II', symbols[pic][0][0], symbols[pal][0][0])
                                for item, pic, pal in entries())
        self.assertEqual(len(symbols['gItemIconTable']), 1)
        address, size = symbols['gItemIconTable'][0]
        self.assertEqual(size, len(native_table))
        self.assertEqual(native_table, rom[address - 0x08000000:address - 0x08000000 + size])


if __name__ == '__main__':
    unittest.main()
