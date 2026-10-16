#!/usr/bin/env python3
"""Complete intro/credits C data ownership and editable resource regeneration."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
GFX = ROOT / 'tools/gbagfx/gbagfx'
NM = shutil.which('arm-none-eabi-nm')
SOURCE = 'src/intro_credits_graphics.c'


def resources():
    return re.findall(r'const u(?:16|32) (\w+)\[\]\s+INTRO_CREDITS_DATA\s*= INCGFX_U(?:16|32)\("([^"]+)", "([^"]+)"\);', (ROOT / SOURCE).read_text())


class IntroCreditsAssetTests(unittest.TestCase):
    def test_complete_data_owner_replaces_temporary_assembly(self):
        source = (ROOT / SOURCE).read_text()
        self.assertEqual(len(resources()), 32)
        self.assertEqual(len({p for n, p, e in resources()}), 23)
        self.assertEqual(len(re.findall(r'(?m)^(?:static )?const [^\n]+ INTRO_CREDITS_DATA\s*=', source)), 81)
        self.assertFalse((ROOT / 'data/intro_credits_graphics.s').exists())
        self.assertNotIn('data/intro_credits_graphics.o', (ROOT / 'Makefile').read_text())
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        self.assertNotIn('data/intro_credits_graphics.o', linker)
        self.assertEqual(linker.count('src/intro_credits_graphics.o(.rodata.intro_credits_graphics_data)'), 1)

    def test_all_mixed_oam_animation_and_pointer_objects_are_typed(self):
        source = (ROOT / SOURCE).read_text()
        for name in ('sOamData_Player', 'sAnim_Player', 'sAnims_Player', 'sOamData_Bicycle',
                     'sAnim_Bicycle', 'sAnims_Bicycle', 'sOamData_Flygon', 'sAnim_FlygonLeft',
                     'sAnim_FlygonRight', 'sAnims_Flygon'):
            self.assertIn(name, source)
        for name in ('sCloudsAnimCmds', 'sTreesAnimCmds', 'sPlayerSpriteData', 'sBicycleSpriteData', 'sFlygonSpriteData'):
            self.assertNotIn(name, source)
        self.assertIn('static const u16 sUnused[0xF0]', source)

    def test_editable_sources_and_preprocessor_dependencies_are_complete(self):
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('$(C_BUILDDIR)/intro_credits_graphics.o: ' + SOURCE + ' charmap.txt', make)
        self.assertIn('$(PREPROC) -i $< charmap.txt', make.split('$(C_BUILDDIR)/intro_credits_graphics.o:', 1)[1])
        clean = re.search(r'(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)', make).group(1)
        self.assertIn('$(JP_INTRO_CREDITS_ASSETS) $(JP_INTRO_CREDITS_INTERMEDIATES)', clean)
        for name, path, extension in resources():
            self.assertTrue((ROOT / path).is_file(), path)
            self.assertIn(path + extension, make)

    def test_sprite_sheet_sizes_do_not_redefine_compressed_payloads(self):
        source = (ROOT / SOURCE).read_text()
        sheet = re.search(r'sSpriteSheet_HouseSilhouette\[\].*?\n\};', source, re.S).group(0)
        self.assertIn('.size = 0x400', sheet)
        self.assertIn('.data = sHouseSilhouette_Gfx', sheet)
        for name in ('gSpritePalettes_IntroPlayerFlygon', 'gSpritePalettes_Credits'):
            palette = re.search(name + r'\[\].*?\n\};', source, re.S).group(0)
            self.assertEqual(palette.count('.data = '), 4)
            self.assertIn('{}', palette)

    @unittest.skipUnless(GFX.is_file() and NM and (ROOT / 'pokeemerald_jp.elf').is_file()
                         and (ROOT / 'baserom_jp.gba').is_file(), 'requires native JP artifacts and gbagfx')
    def test_all_assets_rebuild_native_bytes_with_native_abi_boundaries(self):
        output = subprocess.check_output([NM, '-S', '--defined-only', str(ROOT / 'pokeemerald_jp.elf')], text=True)
        symbols = {name: (int(address, 16), int(size, 16)) for address, size, kind, name
                   in re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', output)
                   if 0x85cdbb0 <= int(address, 16) < 0x85d289c}
        self.assertEqual(len(symbols), 81)
        self.assertEqual(symbols['sGrass_Pal'], (0x85cdbb0, 32))
        self.assertEqual(symbols['sSpriteMetadata_Clouds'][1], 9 * 8)
        self.assertEqual(symbols['sSpriteMetadata_Trees'][1], 12 * 8)
        self.assertEqual(symbols['sSpriteMetadata_HouseSilhouette'][1], 6 * 8)
        self.assertEqual(symbols['sUnused'][1], 480)
        self.assertEqual(symbols['gSpriteSheet_CreditsRivalMay'], (0x85d288c, 16))
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        temp_root = ROOT / '.tmp/agent-work/tests'
        temp_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='intro-credits-', dir=temp_root) as temp:
            for i, (name, path, extension) in enumerate(resources()):
                source = ROOT / path
                target = Path(temp) / (str(i) + extension)
                if source.suffix == '.bin':
                    raw = source
                else:
                    raw = target.with_name(target.name.removesuffix('.lz')) if extension.endswith('.lz') else target
                    subprocess.run([str(GFX), str(source), str(raw)], check=True, capture_output=True)
                if extension.endswith('.lz'):
                    subprocess.run([str(GFX), str(raw), str(target)], check=True, capture_output=True)
                else:
                    target = raw
                address, size = symbols[name]
                self.assertEqual(target.stat().st_size, size, name)
                self.assertEqual(target.read_bytes(), rom[address - 0x8000000:address - 0x8000000 + size], name)
