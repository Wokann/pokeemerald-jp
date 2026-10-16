#!/usr/bin/env python3
"""The remaining source-backed animation assets form one reproducible family."""
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
MACROS = (
    'BATTLE_ANIM_SANDSTORM_RESOURCES', 'BATTLE_ANIM_METAL_SOUND_RESOURCES',
    'BATTLE_ANIM_ICE_RESOURCES', 'BATTLE_ANIM_ORB_AND_POWDER_RESOURCES',
    'BATTLE_ANIM_SPLASH_THROUGH_PROTECT_RESOURCES', 'BATTLE_ANIM_MUDDY_WATER_RESOURCES',
    'BATTLE_ANIM_GHOST_AND_SOLARBEAM_RESOURCES', 'BATTLE_ANIM_COSMIC_AND_SLAM_HIT_2_RESOURCES',
    'BATTLE_ANIM_FOG_THROUGH_CROSS_IMPACT_RESOURCES', 'BATTLE_ANIM_SURF_AND_WHITE_SHADOW_RESOURCES',
    'SMOKESCREEN_IMPACT_GRAPHICS', 'BATTLE_ANIM_POST_CONTEST_GFX',
    'BATTLE_ANIM_MASK_AND_BG_GFX', 'BATTLE_ANIM_STAT_CHANGE_GFX',
    'BATTLE_ANIM_SHOCK_AND_FEATHER_RESOURCES',
)
COMPOSITES = {
    'graphics/battle_anims/sprites/' + name + '.4bpp': [
        'graphics/battle_anims/sprites/' + name + '_' + str(i) + '.png'
        for i in range(count)
    ] for name, count in (('ice_crystals', 5), ('mud_sand', 2), ('flower', 2), ('spark', 2))
}


def resources():
    source = (ROOT / 'src/graphics.c').read_text()
    blocks = [source.split('#define ' + macro + ' ', 1)[1].split('#undef ' + macro, 1)[0]
              for macro in MACROS]
    return re.findall(r'const u32 (\w+)\[\] = INCGFX_U32\("(graphics/battle_anims/[^"]+)", "([^"]+)"(?:, "([^"]+)")?\);', '\n'.join(blocks))


class BattleAnimationRemainingAssetTests(unittest.TestCase):
    def test_complete_source_family_and_standard_non_graphical_tables(self):
        rows = resources()
        self.assertEqual(len(rows), 387)
        inputs = {p for n, p, e, f in rows if p not in COMPOSITES}
        inputs.update(p for parts in COMPOSITES.values() for p in parts)
        self.assertEqual(len(inputs), 255)
        for path in inputs:
            self.assertTrue((ROOT / path).is_file(), path)
        source = (ROOT / 'src/graphics.c').read_text()
        remaining = re.findall(r'INCBIN_U\d+\("(graphics/battle_anims/[^"]+)"\)', source)
        self.assertEqual(remaining, ['graphics/battle_anims/unused/unknown_' + str(i) + '.bin' for i in range(1, 4)])
        self.assertEqual([(ROOT / p).stat().st_size for p in remaining], [36, 36, 36])

    def test_generation_clean_composites_and_14_tile_crop(self):
        make = (ROOT / 'Makefile').read_text()
        self.assertIn('$(C_BUILDDIR)/graphics.o: $(JP_BATTLE_ANIM_REMAINING_ASSETS)', make)
        clean = re.search(r'(?m)^clean: clean-tools\n((?:\t[^\n]*\n)+)', make).group(1)
        self.assertIn('$(JP_BATTLE_ANIM_REMAINING_ASSETS) $(JP_BATTLE_ANIM_REMAINING_INTERMEDIATES)', clean)
        self.assertIsNone(re.search(r'(?m)^\+\tgraphics/', make))
        self.assertEqual([(n, f) for n, p, e, f in resources() if f],
                         [('UnusedLevelupAnimationGfx', '-num_tiles 14 -Wnum_tiles')])
        self.assertIn('$(GFX) $< $@ -num_tiles 14 -Wnum_tiles', make)
        for target, parts in COMPOSITES.items():
            rule = target + ': ' + ' '.join(p + '.4bpp' for p in parts) + ' Makefile\n\tcat $(filter %.4bpp,$^) >$@'
            self.assertIn(rule, make)
        for n, path, extension, flags in resources():
            output = path + (re.sub(r'[^A-Za-z0-9]', '_', flags) if flags else '') + extension
            self.assertIn(output, make)

    def test_new_native_slots_use_true_c_owners(self):
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        asm = (ROOT / 'data/data_rest2c.s').read_text()
        for section in ('battle_anim_orb_and_powder_resources', 'battle_anim_shock_and_feather_resources'):
            self.assertEqual(linker.count('src/graphics.o(.rodata.' + section + ')'), 1)
        for section in ('data_rest2c_after_contest_next_turn_resources', 'data_rest2c_after_decoration_icons'):
            self.assertNotIn('.rodata.' + section, asm)
            self.assertNotIn('.rodata.' + section, linker)
        self.assertIn('.rodata.data_rest2c_after_cable_car_bg_palette', asm)
        self.assertNotRegex(asm, r'(?m)^gBattleAnim\w+:')
        header = (ROOT / 'include/graphics.h').read_text()
        declared = set(re.findall(r'extern const u\d+ (\w+)\[\];', header))
        for name in ('gBattleAnimSpriteGfx_GlowyRedOrb', 'gBattleAnimSpritePal_GlowyRedOrb',
                     'gBattleAnimSpritePal_GlowyGreenOrb', 'gBattleAnimSpritePal_SleepPowder',
                     'gBattleAnimSpritePal_StunSpore', 'gBattleAnimSpritePal_Shock3',
                     'gBattleAnimSpriteGfx_Shock3', 'gBattleAnimSpritePal_WhiteFeather',
                     'gBattleAnimSpriteGfx_WhiteFeather', 'gBattleAnimSpritePal_Sparkle6',
                     'gBattleAnimSpriteGfx_Sparkle6'):
            self.assertTrue(name in declared, name)

    def test_old_aliases_and_generated_git_inputs_are_retired(self):
        linker = (ROOT / 'ld_script_jp.txt').read_text()
        consumers = '\n'.join((ROOT / path).read_text() for path in
                              ('src/battle_gfx_sfx_util.c', 'src/battle_anim_throw.c'))
        for suffix in ('CF60', 'CF84', 'D1C4', 'EAF4', 'EB40'):
            self.assertNotIn('gUnknown_8C2' + suffix, linker + consumers)
        for name in ('gSubstituteDollPal', 'gSubstituteDollFrontGfx', 'gSubstituteDollBackGfx',
                     'UnusedLevelupAnimationGfx', 'UnusedLevelupAnimationTilemap'):
            self.assertIn(name, consumers)
        if shutil.which('git') and (ROOT / '.git').exists():
            tracked = set(subprocess.check_output(['git', 'ls-files', '-z'], cwd=ROOT).decode().split('\0'))
            for n, path, extension, flags in resources():
                output = path + (re.sub(r'[^A-Za-z0-9]', '_', flags) if flags else '') + extension
                self.assertNotIn(output, tracked, output)

    @unittest.skipUnless(GFX.is_file() and NM and (ROOT / 'pokeemerald_jp.elf').is_file()
                         and (ROOT / 'baserom_jp.gba').is_file(), 'requires native JP artifacts and gbagfx')
    def test_all_387_objects_regenerate_native_bytes(self):
        output = subprocess.check_output([NM, '-S', '--defined-only', str(ROOT / 'pokeemerald_jp.elf')], text=True)
        symbols = {name: (int(address, 16), int(size, 16)) for address, size, kind, name
                   in re.findall(r'(?m)^([0-9a-f]+) ([0-9a-f]+) (\w) (\S+)$', output)}
        self.assertEqual(sum(symbols[n][1] for n, p, e, f in resources()), 115984)
        self.assertEqual(symbols['gBattleAnimSpriteGfx_GlowyRedOrb'][0], 0x8d8ea1c)
        self.assertEqual(symbols['gBattleAnimSpritePal_Shock3'][0], 0x8dba3f4)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        temp_root = ROOT / '.tmp/agent-work/tests'
        temp_root.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory(prefix='battle-animation-remaining-', dir=temp_root) as temp:
            for i, (name, path, extension, flags) in enumerate(resources()):
                target = Path(temp) / (str(i) + extension)
                if path in COMPOSITES:
                    parts = []
                    for j, component in enumerate(COMPOSITES[path]):
                        part = Path(temp) / (str(i) + '-' + str(j) + '.4bpp')
                        subprocess.run([str(GFX), str(ROOT / component), str(part)], check=True, capture_output=True)
                        parts.append(part.read_bytes())
                    raw = target.with_name(str(i) + '.4bpp')
                    raw.write_bytes(b''.join(parts))
                elif path.endswith('.bin'):
                    raw = ROOT / path
                else:
                    raw = target.with_name(target.name.removesuffix('.lz'))
                    subprocess.run([str(GFX), str(ROOT / path), str(raw), *shlex.split(flags)], check=True, capture_output=True)
                subprocess.run([str(GFX), str(raw), str(target)], check=True, capture_output=True)
                address, size = symbols[name]
                self.assertEqual(target.stat().st_size, size, name)
                self.assertEqual(target.read_bytes(), rom[address - 0x8000000:address - 0x8000000 + size], name)


if __name__ == '__main__':
    unittest.main()
