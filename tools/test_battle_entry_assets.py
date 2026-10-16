#!/usr/bin/env python3
"""VS and the entire battle-environment family regenerate from editable assets."""
import re
import shlex
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GFX = ROOT / 'tools/gbagfx/gbagfx'
NM = shutil.which('arm-none-eabi-nm')
HEADER = 'src/data/graphics/battle_environment.h'


def owner():
    source = (ROOT / 'src/graphics.c').read_text()
    vs = source.split('#define BATTLE_VS_GRAPHICS ', 1)[1].split('#undef BATTLE_VS_GRAPHICS', 1)[0]
    return vs + (ROOT / HEADER).read_text()


def resources():
    return re.findall(r'const u32 (\w+)\[\] = INCGFX_U32\("([^"]+)", "([^"]+)"(?:, "([^"]+)")?\);', owner())


class BattleEntryAssetTests(unittest.TestCase):
    def test_complete_entry_family_is_source_backed(self):
        self.assertEqual(len(resources()), 69)
        self.assertEqual(len({p for n, p, e, f in resources()}), 68)
        self.assertNotIn('INCBIN_', owner())
        self.assertEqual(len(re.findall(r'const u32 gBattleEnvironment', (ROOT / HEADER).read_text())), 65)
        raw = (ROOT / 'data/data_rest2c.s').read_text()
        for name in ('gBattleVSFrame_Gfx:', 'gBattleVSFrame_Pal:', 'gBattleVSFrame_Tilemap:', 'gVsLettersGfx:'):
            self.assertNotIn(name, raw)
        self.assertNotIn('gBattleAnimSpriteGfx_GlowyRedOrb:', raw)

    def test_vs_frame_preserves_the_native_16_tile_crop(self):
        special = [(n, f) for n, p, e, f in resources() if f]
        self.assertEqual(special, [('gBattleVSFrame_Gfx', '-num_tiles 16 -Wnum_tiles')])
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('graphics/battle_transitions/vs_frame.png_num_tiles_16__Wnum_tiles.4bpp:', make)
        self.assertIn('$(GFX) $< $@ -num_tiles 16 -Wnum_tiles', make)

    def test_all_editable_sources_have_clean_and_generation_dependencies(self):
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('$(C_BUILDDIR)/graphics.o: ' + HEADER + ' $(JP_BATTLE_ENTRY_ASSETS)', make)
        clean = re.search(r'(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)', make).group(1)
        self.assertIn('$(JP_BATTLE_ENTRY_ASSETS) $(JP_BATTLE_ENTRY_INTERMEDIATES)', clean)
        for name, path, extension, flags in resources():
            self.assertTrue((ROOT / path).is_file(), path)
            output = path + (re.sub(r'[^A-Za-z0-9]', '_', flags) if flags else '') + extension
            self.assertIn(output, make)

    def test_linker_preserves_both_native_resource_owners(self):
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        self.assertNotIn('data/data_rest2c.o(.rodata);', linker)
        self.assertEqual(linker.count('src/graphics.o(.rodata.battle_vs_graphics)'), 1)
        self.assertEqual(linker.count('src/graphics.o(.rodata.battle_environment_graphics)'), 1)
        self.assertLess(linker.index('src/graphics.o(.rodata.battle_vs_graphics)'), linker.index('src/graphics.o(.rodata.battle_environment_graphics)'))
        self.assertLess(linker.index('src/graphics.o(.rodata.battle_environment_graphics)'), linker.index('src/graphics.o(.rodata.battle_frontier_graphics)'))
        sheet = (ROOT / 'data/data_b2.s').read_text().split('sVsLettersSpriteSheet: @', 1)[1].split('\n\n', 1)[0]
        self.assertIn('.4byte gVsLettersGfx', sheet)
        self.assertNotIn('.4byte 0x08D77BB0', sheet)

    @unittest.skipUnless(GFX.is_file() and NM and (ROOT / 'pokeemerald_jp.elf').is_file()
                         and (ROOT / 'baserom_jp.gba').is_file(), 'requires native JP artifacts and gbagfx')
    def test_all_69_resources_regenerate_the_complete_native_region(self):
        output = subprocess.check_output([NM, '-S', '--defined-only', str(ROOT / 'pokeemerald_jp.elf')], text=True)
        symbols = {name: (int(address, 16), int(size, 16)) for address, size, kind, name
                   in re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', output)}
        self.assertEqual(symbols['gBattleVSFrame_Gfx'], (0x8d77994, 232))
        self.assertEqual(symbols['gBattleEnvironmentTiles_TallGrass'][0], 0x8d77e0c)
        self.assertEqual(sum(symbols[n][1] for n, p, e, f in resources()), 46624)
        last, size = symbols['gBattleEnvironmentAnimTilemap_Rayquaza']
        self.assertEqual(last + size, 0x8d82fb4)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        temp_root = ROOT / '.tmp/agent-work/tests'
        temp_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='battle-entry-', dir=temp_root) as temp:
            for i, (name, path, extension, flags) in enumerate(resources()):
                source = ROOT / path
                target = Path(temp) / (str(i) + extension)
                if source.suffix == '.bin':
                    raw = source
                else:
                    raw = target.with_name(target.name.removesuffix('.lz'))
                    subprocess.run([str(GFX), str(source), str(raw), *shlex.split(flags)], check=True, capture_output=True)
                subprocess.run([str(GFX), str(raw), str(target)], check=True, capture_output=True)
                address, size = symbols[name]
                self.assertEqual(target.stat().st_size, size, name)
                self.assertEqual(target.read_bytes(), rom[address - 0x8000000:address - 0x8000000 + size], name)
