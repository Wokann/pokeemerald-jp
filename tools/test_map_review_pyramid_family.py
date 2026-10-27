"""Pyramid selector widths, split light loop and native generated-object contracts."""
from pathlib import Path
import re
import struct
import unittest
import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
MAPS = ['BattleFrontier_BattlePyramid' + part for part in ('Lobby', 'Floor', 'Top')]
FLOOR = MAPS[1]


class PyramidFamilyProfileTests(unittest.TestCase):
    def parse(self, text, *, owner='Owner', waits=None, version=4):
        return profile.profile_block(ROOT, owner + '::\n' + text, waits,
                                     version=version, address=0x0822BCDD)

    def test_observed_pyramid_selectors_respect_real_special_waits(self):
        forms = [('pyramid_' + name, 8) for name in
                 ('init', 'setprize', 'seedfloor', 'settrainers', 'clearhelditems', 'setfloorpal')]
        forms += [('pyramid_get PYRAMID_DATA_' + data, 13) for data in
                  ('WIN_STREAK', 'WIN_STREAK_50', 'WIN_STREAK_OPEN',
                   'WIN_STREAK_ACTIVE_50', 'WIN_STREAK_ACTIVE_OPEN')]
        forms += [('pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255', 18),
                  ('pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE', 18),
                  ('pyramid_save CHALLENGE_STATUS_SAVING', 13), ('pyramid_save 0', 13)]
        for text, size in forms:
            for wait in (0, 1):
                result = self.parse(text + '\nreturn', waits={'CallBattlePyramidFunction': wait})
                self.assertEqual(result.size, size + wait + 1, text)
                self.assertEqual(result.specials, {'CallBattlePyramidFunction': wait})
        self.assertEqual(profile.special_waits(ROOT)['CallBattlePyramidFunction'], 0)
        for text in ('pyramid_get PYRAMID_DATA_UNKNOWN', 'pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE',
                     'pyramid_set PYRAMID_DATA_TRAINER_FLAGS', 'pyramid_set PYRAMID_DATA_WIN_STREAK, VAR_RESULT',
                     'pyramid_save CHALLENGE_STATUS_OTHER', 'pyramid_init 0', 'pyramid_giveprize'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_only_three_observed_set_radius_forms_are_supported(self):
        for radius in (0, 32, 200):
            self.assertEqual(self.parse(f'pyramid_updatelight {radius}, PYRAMID_LIGHT_SET_RADIUS\nreturn').size, 19)
        for text in ('pyramid_updatelight 4, PYRAMID_LIGHT_INCR_RADIUS',
                     'pyramid_updatelight 201, PYRAMID_LIGHT_SET_RADIUS',
                     'pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS, SE_SAVE',
                     'pyramid_updatelight 32', 'pyramid_updatelight VAR_RESULT, PYRAMID_LIGHT_SET_RADIUS'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_pyramid_results_uses_only_its_observed_default_mode(self):
        result = self.parse('frontier_results FRONTIER_FACILITY_PYRAMID\nreturn')
        self.assertEqual(result.size, 14)
        self.assertEqual(self.parse('frontier_isbattletype BATTLE_TYPE_TRAINER\nreturn').size, 14)
        for text in ('frontier_results FRONTIER_FACILITY_PYRAMID, 0xFF',
                     'frontier_results FRONTIER_FACILITY_PYRAMID, FRONTIER_MODE_SINGLES',
                     'frontier_isbattletype BATTLE_TYPE_WILD', 'frontier_isbattletype 8'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_light_update_setup_preserves_the_real_cross_label_loop(self):
        blocks = review.label_blocks((ROOT / f'data/maps/{FLOOR}/scripts.inc').read_text())
        label = FLOOR + '_EventScript_UpdateLight'
        lines = review.statements(blocks[label])
        self.assertEqual(lines, ['lockall', 'setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT',
                                'setvar VAR_0x8005, 4', 'setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS',
                                'setvar VAR_0x8007, SE_SAVE', 'setvar VAR_RESULT, 0'])
        result = profile.profile_block(ROOT, blocks[label], version=4, address=0x0822BCDD)
        self.assertEqual((result.size, result.fallthrough), (26, label + 'Loop'))
        self.assertIn('goto_if_ne VAR_RESULT, 2, ' + label + 'Loop', review.statements(blocks[label + 'Loop']))

    def test_new_pyramid_forms_do_not_broaden_legacy_review(self):
        for text in ('pyramid_init', 'pyramid_get PYRAMID_DATA_WIN_STREAK',
                     'pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255',
                     'pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS',
                     'frontier_results FRONTIER_FACILITY_PYRAMID', 'frontier_isbattletype BATTLE_TYPE_TRAINER'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn', version=3)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_observed_pyramid_macros_match_native_expansion(self):
        samples = {line for name in MAPS
                   for body in review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text()).values()
                   for line in review.statements(body)
                   if line.startswith(('pyramid_', 'frontier_results', 'frontier_isbattletype'))}
        self.assertEqual(len(samples), 26)
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_all_eighteen_pyramid_fallthroughs_are_actual_rom_adjacencies(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        count = 0
        for name in MAPS:
            for label, body in review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text()).items():
                if label not in profile.FALLTHROUGHS:
                    continue
                at = next(iter(symbols[label]))
                result = profile.profile_block(ROOT, body, version=4, address=at)
                self.assertEqual(symbols[result.fallthrough], {at + result.size})
                self.assertEqual(verifier.assemble_candidate(body, at),
                                 rom[at - 0x08000000:at - 0x08000000 + result.size])
                count += 1
        # Seventeen new edges plus the previously reviewed FindItemBall tail.
        self.assertEqual(count, 18)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_all_eighteen_actual_pyramid_dispatch_targets_match_native_table(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        targets = ['InitPyramidChallenge', 'GetBattlePyramidData', 'SetBattlePyramidData',
                   'sub_081A8EB4', 'SetBattlePyramidRewardItem', 'GiveBattlePyramidRewardItem',
                   'SeedPyramidFloor', 'SetPickupItem', 'HidePyramidItem', 'InitPyramidFacilityTrainers',
                   'ShowPostBattleHintText', 'UpdatePyramidWinStreak', 'GetInBattlePyramid',
                   'UpdatePyramidLightRadius', 'ClearPyramidPartyHeldItems', 'SetPyramidFloorPalette',
                   'sub_081A95A0', 'RestorePyramidPlayerParty']
        expected = struct.pack('<18I', *(next(iter(symbols[name])) | 1 for name in targets))
        at = next(iter(symbols['gUnknown_85DF718'])) - 0x08000000
        self.assertEqual(rom[at:at + 72], expected)
        source = (ROOT / 'src/battle_pyramid.c').read_text().split('const u8 gUnknown_85DF718[] = {', 1)[1].split('};', 1)[0]
        self.assertEqual(bytes(int(value, 16) for value in re.findall(r'0x([0-9a-fA-F]{2})', source)), expected)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_generated_object_loader_points_to_actual_trainer_and_item_scripts(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        at = next(iter(symbols['LoadBattlePyramidFloorEventObjectScripts'])) & ~1
        code = rom[at - 0x08000000:at - 0x08000000 + 0x44]
        for target in ('BattlePyramid_TrainerBattle', 'BattlePyramid_FindItemBall'):
            self.assertIn(struct.pack('<I', next(iter(symbols[target]))), code)
        gfx = review._literal_define(ROOT, 'include/constants/event_objects.h', 'OBJ_EVENT_GFX_ITEM_BALL')
        self.assertIn(struct.pack('<H', 0x2800 | gfx), code)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_lobby_reuses_real_dome_warp_callback_and_keeps_unused_local_copy(self):
        name = MAPS[0]
        blocks = review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())
        label = name + '_MapScripts'
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        at = next(iter(symbols[label]))
        result = profile.profile_block(ROOT, blocks[label], version=4, address=at)
        self.assertIn('BattleFrontier_BattleDomeLobby_OnWarp', result.targets)
        self.assertNotIn(name + '_OnWarp', result.targets)
        self.assertIn(name + '_OnWarp', blocks)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(verifier.assemble_candidate(blocks[label], at),
                         rom[at - 0x08000000:at - 0x08000000 + result.size])


if __name__ == '__main__':
    unittest.main()
