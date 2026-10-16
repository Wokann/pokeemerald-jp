#!/usr/bin/env python3
"""Native Frontier graphics and the complete GF/player palette boundary."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GFX = ROOT / 'tools/gbagfx/gbagfx'
NM = shutil.which('arm-none-eabi-nm')


def owner():
    source = (ROOT / 'src/graphics.c').read_text()
    return source.split('#define BATTLE_FRONTIER_GRAPHICS ', 1)[1].split('#undef INTRO_SCENE_2_PLAYER_PALETTE', 1)[0]


def resources():
    return re.findall(r'const u(?:16|32) (\w+)\[\](?:\[16\])? = INCGFX_U(?:16|32)\("([^"]+)", "([^"]+)"\);', owner())


class FrontierIntroAssetTests(unittest.TestCase):
    def test_complete_native_family_uses_real_c_owners(self):
        self.assertEqual(len(resources()), 25)
        self.assertEqual(len(re.findall(r'const u(?:16|32) ', owner())), 26)
        self.assertEqual(len({path for name, path, extension in resources()}), 23)
        self.assertIn('sUnused0[] = {0x13F, 0x119, 0x113, 0x10E}', owner())
        raw = (ROOT / 'data/data_rest2c.s').read_text()
        self.assertNotIn('gUnknown_8D85C74', raw)
        self.assertNotIn('data_rest2c_after_battle_environment_graphics', raw)
        self.assertIn('gUnknown_8D85CB4:', raw)

    def test_complete_gf_table_and_actual_player_palette_are_distinct(self):
        intro = (ROOT / 'src/intro.c').read_text()
        self.assertEqual(intro.count('.4byte gIntroGameFreakTextFade_Pal\\n'), 3)
        self.assertEqual(intro.count('.4byte gIntroGameFreakTextFade_Pal + 32\\n'), 3)
        self.assertEqual(intro.count('.4byte gIntroGameFreakTextFade_Pal + 64\\n'), 3)
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        self.assertNotIn('gUnknown_8D85C54 = gIntroPlayer_Pal', linker)
        self.assertEqual(linker.count('src/graphics.o(.rodata.intro_scene_1_text_fade_palette)'), 1)
        table = (ROOT / 'data/intro_credits_graphics.s').read_text()
        self.assertEqual(table.count('.4byte gIntroPlayer_Pal\n'), 2)

    def test_pp_interior_reference_and_jp_sprite_sheet_sizes_are_preserved(self):
        message = (ROOT / 'src/battle_message.c').read_text()
        self.assertIn('.4byte gPPTextPalette + 2\\n', message)
        arena = (ROOT / 'src/battle_arena.c').read_text()
        self.assertIn('{gBattleArenaJudgmentSymbolsGfx, 0x200, TAG_JUDGMENT_ICON}', arena)
        self.assertNotIn('gUnknown_85DD7AC', arena)
        self.assertNotIn('asm("sArenaJudgmentSymbolsPalette', arena)
        dome = (ROOT / 'src/battle_dome.c').read_text()
        sheet = re.search(r'sTourneyTreeButtonsSpriteSheet\[\].*?\n\};', dome, re.S).group(0)
        self.assertRegex(sheet, r'\.data = gDomeTourneyTreeButtons_Gfx,\s*\.size = 0x0400,\s*\.tag = TAG_BUTTONS')

    def test_generation_and_clean_cover_all_editable_resources(self):
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('$(C_BUILDDIR)/graphics.o: $(JP_FRONTIER_UI_ASSETS)', make)
        clean = re.search(r'(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)', make).group(1)
        self.assertIn('$(JP_FRONTIER_UI_ASSETS) $(JP_FRONTIER_UI_INTERMEDIATES)', clean)
        for name, path, extension in resources():
            self.assertTrue((ROOT / path).is_file(), path)
            self.assertIn(path + extension, make)

    @unittest.skipUnless(GFX.is_file() and NM and (ROOT / 'pokeemerald_jp.elf').is_file()
                         and (ROOT / 'baserom_jp.gba').is_file(), 'requires native JP artifacts and gbagfx')
    def test_all_generated_objects_match_the_native_rom(self):
        output = subprocess.check_output([NM, '-S', '--defined-only', str(ROOT / 'pokeemerald_jp.elf')], text=True)
        symbols = {name: (int(address, 16), int(size, 16)) for address, size, kind, name
                   in re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', output)}
        self.assertEqual(symbols['gDomeTourneyTree_Gfx'][0], 0x8d82fb4)
        self.assertEqual(symbols['gIntroGameFreakTextFade_Pal'], (0x8d85c34, 96))
        self.assertEqual(symbols['gIntroPlayer_Pal'], (0x8d85c94, 32))
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        temp_root = ROOT / '.tmp/agent-work/tests'
        temp_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='frontier-intro-', dir=temp_root) as temp:
            for i, (name, path, extension) in enumerate(resources()):
                source = ROOT / path
                target = Path(temp) / (str(i) + extension)
                if extension == '.lz':
                    input_path = source
                else:
                    input_path = target.with_name(target.name.removesuffix('.lz')) if extension.endswith('.lz') else target
                    subprocess.run([str(GFX), str(source), str(input_path)], check=True, capture_output=True)
                if extension.endswith('.lz'):
                    subprocess.run([str(GFX), str(input_path), str(target)], check=True, capture_output=True)
                address, size = symbols[name]
                self.assertEqual(target.stat().st_size, size, name)
                self.assertEqual(target.read_bytes(), rom[address - 0x8000000:address - 0x8000000 + size], name)
        self.assertEqual(rom[0xd856a4:0xd856ac], bytes.fromhex('3f01190113010e01'))


if __name__ == '__main__':
    unittest.main()
