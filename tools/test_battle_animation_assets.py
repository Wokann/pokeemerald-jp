#!/usr/bin/env python3
"""The complete native animation/interface resource family rebuilds from source."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GFX = ROOT / 'tools/gbagfx/gbagfx'
NM = shutil.which('arm-none-eabi-nm')
COMPOSITES = {
    'graphics/battle_anims/sprites/ice_cube.4bpp': ['graphics/battle_anims/sprites/ice_cube_%d.png' % i for i in range(4)],
    'graphics/battle_interface/battle_bar.4bpp': ['graphics/battle_interface/' + n + '.png' for n in ('hpbar_anim_unused', 'numbers1', 'numbers2')],
    'graphics/unused/obi1.4bpp': ['graphics/unused/' + n + '.png' for n in ('old_bulbasaur', 'old_charizard')],
    'graphics/unused/obi2.4bpp': ['graphics/unused/' + n + '.png' for n in ('old_bulbasaur2', 'old_battle_interface_1', 'old_battle_interface_2', 'old_battle_interface_3')],
    'graphics/unused/obi_palpak1.gbapal': ['graphics/unused/old_pal%d.pal' % i for i in (1, 2, 3)],
    'graphics/unused/obi_palpak3.gbapal': ['graphics/unused/old_pal%d.pal' % i for i in (5, 6, 7)],
    'graphics/unused/redyellowgreen_frame.bin': ['graphics/unused/' + n + '_frame.bin' for n in ('red', 'yellow', 'green', 'blank')],
}


def owner_source():
    source = (ROOT / 'src/graphics.c').read_text()
    return source.split('#define BATTLE_ANIM_GRAPHICS ', 1)[1].split('#undef BATTLE_ANIM_GRAPHICS', 1)[0]


def resources():
    return re.findall(r'const u(?:8|16|32) (\w+)\[\]\s*=\s*INCGFX_U(?:8|16|32)\("([^"]+)",\s*"([^"]+)"(?:,\s*"([^"]*)")?\);', owner_source())


class BattleAnimationAssetTests(unittest.TestCase):
    def test_complete_native_family_has_one_real_c_owner(self):
        source = owner_source()
        self.assertEqual(len(re.findall(r'const u(?:8|16|32) ', source)), 271)
        self.assertEqual(len(resources()), 265)
        self.assertNotIn('.set ', source)
        self.assertFalse((ROOT / 'data/data_rest2b.s').exists())
        self.assertFalse((ROOT / 'tools/extract_battle_anim_graphics.py').exists())
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        self.assertEqual(linker.count('src/graphics.o(.rodata.battle_anim_graphics)'), 1)
        self.assertNotIn('data/data_rest2b.o(', linker)
        self.assertNotIn('data/data_rest2b.o', (ROOT / 'Makefile').read_text())

    def test_editable_inputs_include_every_composite_component(self):
        sources = {path for name, path, extension, flags in resources()}
        sources = (sources - COMPOSITES.keys()) | {p for parts in COMPOSITES.values() for p in parts}
        self.assertEqual(len(sources), 175)
        for path in sources:
            self.assertIn(Path(path).suffix, ('.png', '.pal', '.bin'))
            self.assertTrue((ROOT / path).is_file(), path)

    def test_native_healthbox_and_three_existing_unknown_inputs_remain(self):
        source = owner_source()
        self.assertIn('gHealthboxElementsGfxTable[][32] = INCBIN_U8(', source)
        self.assertIn('gBattleInterface_BallStatusBarPal[] = INCBIN_U16(', source)
        self.assertIn('gBattleInterface_BallDisplayPal[] = INCBIN_U16(', source)
        for i in (1, 2, 3):
            self.assertIn('gBattleAnimUnused_Unknown%d[] = INCBIN_U16(' % i, source)

    def test_generation_and_clean_rules_cover_the_complete_family(self):
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('$(C_BUILDDIR)/graphics.o: $(JP_BATTLE_ANIM_FAMILY_ASSETS)', make)
        clean = re.search(r'(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)', make).group(1)
        self.assertIn('$(JP_BATTLE_ANIM_FAMILY_ASSETS) $(JP_BATTLE_ANIM_FAMILY_INTERMEDIATES)', clean)
        rules = (ROOT / 'graphics_file_rules.mk').read_text()
        for composite in COMPOSITES:
            self.assertIn('\n' + composite + ': ', rules)
        for suffix in ('.4bpp', '.gbapal', '.bin'):
            self.assertIn('cat $(filter %' + suffix + ',$^) >$@', rules)

    @unittest.skipUnless(GFX.is_file() and NM and (ROOT / 'pokeemerald_jp.elf').is_file()
                         and (ROOT / 'baserom_jp.gba').is_file(), 'requires built JP artifacts and gbagfx')
    def test_all_265_compressed_resources_rebuild_to_the_native_rom(self):
        text = subprocess.check_output([NM, '-S', '--defined-only', str(ROOT / 'pokeemerald_jp.elf')], text=True)
        symbols = {name: (int(address, 16), int(size, 16))
                   for address, size, kind, name in re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', text)}
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(symbols['gBlankGfxCompressed'][0], 0x8c02384)
        last_address, last_size = symbols['gBattleAnimSpriteGfx_BlueFlames2']
        self.assertEqual(last_address + last_size, 0x8c1502c)
        temp_root = ROOT / '.tmp/agent-work/tests'
        temp_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='battle-anim-family-', dir=temp_root) as temp:
            out = Path(temp)
            cache = {}
            def convert(source, extension, flags=''):
                key = source, extension, flags
                if key in cache:
                    return cache[key]
                number = len(cache)
                cache[key] = out / (str(number) + extension)
                if source in COMPOSITES:
                    parts = []
                    for component in COMPOSITES[source]:
                        if component.endswith('.bin'):
                            parts.append((ROOT / component).read_bytes())
                        else:
                            suffix = '.4bpp' if component.endswith('.png') else '.gbapal'
                            parts.append(convert(component, suffix).read_bytes())
                    raw = out / ('composite-' + str(number) + Path(source).suffix)
                    raw.write_bytes(b''.join(parts))
                else:
                    raw = ROOT / source
                prefix = extension[:-3] if extension.endswith('.lz') else ''
                if prefix:
                    intermediate = convert(source, prefix, flags)
                    args = [str(intermediate), str(cache[key])]
                else:
                    args = [str(raw), str(cache[key]), *flags.split()]
                subprocess.run([str(GFX), *args], check=True, capture_output=True)
                return cache[key]
            for name, source, extension, flags in resources():
                with self.subTest(name=name):
                    result = convert(source, extension, flags).read_bytes()
                    address, size = symbols[name]
                    self.assertEqual(len(result), size)
                    self.assertEqual(result, rom[address - 0x8000000:address - 0x8000000 + size])


if __name__ == '__main__':
    unittest.main()
