#!/usr/bin/env python3
"""The full intro header is editable, regenerable, and native-byte exact."""
import re
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
GFX=ROOT/'tools/gbagfx/gbagfx'
NM=shutil.which('arm-none-eabi-nm')
HEADER='src/data/graphics/intro_scene.h'


def resources():
    return re.findall(r'const u(?:16|32) (\w+)(?:\[[^\]]*\])+ = INCGFX_U(?:16|32)\("([^"]+)", "([^"]+)"\);',(ROOT/HEADER).read_text())


class IntroSceneAssetTests(unittest.TestCase):
    def test_complete_header_matches_the_single_native_owner(self):
        self.assertEqual(len(resources()),36)
        self.assertEqual(len({p for n,p,e in resources()}),30)
        source=(ROOT/'src/graphics.c').read_text()
        self.assertEqual(source.count('#include "data/graphics/intro_scene.h"'),1)
        linker=(ROOT/'ld_script_jp.txt').read_text()
        self.assertEqual(linker.count('src/graphics.o(.rodata.intro_scene_graphics)'),1)
        self.assertNotIn('data_rest2c_after_intro_scene_',linker)
        raw=(ROOT/'data/data_rest2c.s').read_text()
        self.assertNotIn('gUnknown_8D85CB4',raw)
        self.assertNotIn('gUnknown_8D8CF26',raw)
        self.assertNotIn('gBattleAnimSpriteGfx_GlowyRedOrb:',raw)
        self.assertIn('BATTLE_ANIM_ORB_AND_POWDER_RESOURCES const u32 gBattleAnimSpriteGfx_GlowyRedOrb[]',source)

    def test_background_palette_is_one_array_with_real_interior_references(self):
        self.assertIn('gIntro3Bg_Pal[16][16]',(ROOT/HEADER).read_text())
        intro=(ROOT/'src/intro.c').read_text()
        for offset in ('0x182','0x18C','0x1A2','0x1AC'):
            self.assertIn('.4byte gIntro3Bg_Pal + '+offset+'\\n',intro)
        for old in ('CB4','E36','E40','E56','E60'):
            self.assertNotIn('gUnknown_8D85'+old,intro)

    def test_cloud_tilemap_is_word_typed_and_flygon_pointers_are_real(self):
        self.assertIn('const u32 gIntroRayquazaClouds_Tilemap[]',(ROOT/HEADER).read_text())
        self.assertIn('extern const u32 gIntroRayquazaClouds_Tilemap[];',(ROOT/'include/graphics.h').read_text())
        table=(ROOT/'src/intro_credits_graphics.c').read_text()
        self.assertEqual(table.count('.data = gIntroFlygon_Pal,'),2)
        self.assertFalse((ROOT/'data/intro_credits_graphics.s').exists())
        self.assertNotRegex((ROOT/'ld_script_jp.txt').read_text(),r'(?m)^gUnknown_[0-9A-F]+ = gIntro\w+;')

    def test_generation_dependencies_cover_the_complete_header(self):
        make=(ROOT/'Makefile').read_text()
        self.assertIn('$(C_BUILDDIR)/graphics.o: '+HEADER+' $(JP_INTRO_SCENE_ASSETS)',make)
        clean=re.search(r'(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)',make).group(1)
        self.assertIn('$(JP_INTRO_SCENE_ASSETS) $(JP_INTRO_SCENE_INTERMEDIATES)',clean)
        for name,path,extension in resources():
            self.assertTrue((ROOT/path).is_file(),path)
            self.assertIn(path+extension,make)

    @unittest.skipUnless(GFX.is_file() and NM and (ROOT/'pokeemerald_jp.elf').is_file()
                         and (ROOT/'baserom_jp.gba').is_file(),'requires native JP artifacts and gbagfx')
    def test_all_36_resources_regenerate_native_bytes_and_boundaries(self):
        output=subprocess.check_output([NM,'-S','--defined-only',str(ROOT/'pokeemerald_jp.elf')],text=True)
        symbols={n:(int(a,16),int(s,16)) for a,s,k,n in re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$',output)}
        self.assertEqual(symbols['gIntroGameFreakTextFade_Pal'],(0x8d85c34,96))
        self.assertEqual(symbols['gIntroPlayer_Pal'],(0x8d85c94,32))
        self.assertEqual(symbols['gIntro3Bg_Pal'],(0x8d85cb4,512))
        self.assertEqual(symbols['gIntroRayquazaClouds_Tilemap'],(0x8d8ccac,636))
        self.assertEqual(sum(symbols[n][1] for n,p,e in resources()),30292)
        last,size=symbols['gIntroSparkle_Gfx']
        self.assertEqual(last+size,0x8d8d288)
        rom=(ROOT/'baserom_jp.gba').read_bytes()
        temp_root=ROOT/'.tmp/agent-work/tests'
        temp_root.mkdir(parents=True,exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='intro-assets-',dir=temp_root) as temp:
            for i,(name,path,extension) in enumerate(resources()):
                target=Path(temp)/(str(i)+extension)
                source=ROOT/path
                if source.suffix=='.bin':
                    raw=source
                else:
                    raw=target.with_name(target.name.removesuffix('.lz')) if extension.endswith('.lz') else target
                    subprocess.run([str(GFX),str(source),str(raw)],check=True,capture_output=True)
                if extension.endswith('.lz'):
                    subprocess.run([str(GFX),str(raw),str(target)],check=True,capture_output=True)
                else:
                    target=raw
                address,size=symbols[name]
                self.assertEqual(target.stat().st_size,size,name)
                self.assertEqual(target.read_bytes(),rom[address-0x8000000:address-0x8000000+size],name)


if __name__=='__main__':
    unittest.main()
