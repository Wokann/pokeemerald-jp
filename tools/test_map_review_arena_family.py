"""Arena selectors, shared Palace speech, exact exits and native boundaries."""
from pathlib import Path
import re
import struct
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
MAPS = ['BattleFrontier_BattleArena' + part for part in ('Lobby', 'Corridor', 'BattleRoom')]
ROOM = MAPS[2]
INTRO = ROOM + '_EventScript_AnnounceTrainers'


class ArenaFamilyProfileTests(unittest.TestCase):
    def parse(self, body, *, owner='Owner', waits=None, version=4):
        return profile.profile_block(ROOT, owner + '::\n' + body, waits,
                                     version=version, address=0x0822F1C9)

    def test_observed_arena_selectors_follow_actual_special_wait_metadata(self):
        forms = [('arena_init', 8), ('arena_gettrainername', 8)]
        forms += [('arena_save ' + value, 13) for value in
                  ('0', 'CHALLENGE_STATUS_SAVING', 'CHALLENGE_STATUS_PAUSED')]
        forms += [('arena_set ARENA_DATA_WIN_STREAK_ACTIVE, ' + value, 18)
                  for value in ('TRUE', 'FALSE')]
        forms.append(('arena_set ARENA_DATA_WIN_STREAK, 0', 18))
        for text, size in forms:
            for wait in (0, 1):
                with self.subTest(text=text, wait=wait):
                    result = self.parse(text + '\nreturn', waits={'CallBattleArenaFunction': wait})
                    self.assertEqual(result.size, size + wait + 1)
                    self.assertEqual(result.specials, {'CallBattleArenaFunction': wait})
        self.assertEqual(profile.special_waits(ROOT)['CallBattleArenaFunction'], 0)
        # Existing Battle Tent register-copy forms remain supported.
        self.assertEqual(self.parse('arena_get ARENA_DATA_WIN_STREAK\nreturn').size, 14)
        self.assertEqual(self.parse('arena_set ARENA_DATA_WIN_STREAK, VAR_RESULT\nreturn').size, 19)
        for text in ('arena_init 0', 'arena_gettrainername STR_VAR_1', 'arena_get ARENA_DATA_WIN_STREAK, 0',
                     'arena_set ARENA_DATA_PRIZE, TRUE', 'arena_set ARENA_DATA_WIN_STREAK, FALSE',
                     'arena_save CHALLENGE_STATUS_OTHER', 'arena_save 0, 0', 'arena_giveprize'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_arena_results_use_only_the_observed_default_mode(self):
        self.assertEqual(self.parse('frontier_results FRONTIER_FACILITY_ARENA\nreturn').size, 14)
        for mode in ('0xFF', 'FRONTIER_MODE_SINGLES', 'FRONTIER_MODE_DOUBLES'):
            with self.subTest(mode=mode), self.assertRaises(ValueError):
                self.parse('frontier_results FRONTIER_FACILITY_ARENA, ' + mode + '\nreturn')

    def test_arena_ram_message_requires_real_palace_producer_owner_and_mode(self):
        body = 'palace_getopponentintro\nmsgbox gStringVar4, MSGBOX_DEFAULT\nreturn'
        result = self.parse(body, owner=INTRO)
        self.assertEqual(result.runtime_texts, {'gStringVar4': 'palace_getopponentintro'})
        self.assertNotIn('gStringVar4', result.texts)
        for changed in (body.replace('palace_getopponentintro\n', ''),
                        body.replace('\nmsgbox', '\ndelay 1\nmsgbox'),
                        body.replace('MSGBOX_DEFAULT', 'MSGBOX_SIGN'),
                        body.replace('palace_getopponentintro', 'arena_gettrainername')):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed, owner=INTRO)
        with self.assertRaises(ValueError):
            self.parse(body, owner=ROOM + '_EventScript_Unreviewed')

    def test_both_lobby_warps_replace_the_old_script_context(self):
        tail = 'warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY, 7, 8\nwaitstate'
        for entry in ('WarpToLobbyLost', 'ReturnToLobbyWon'):
            owner = ROOM + '_EventScript_' + entry
            result = self.parse(tail, owner=owner)
            self.assertEqual(result.context_warp, 'MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY')
            self.assertFalse(result.may_fall_through)
            self.assertIsNone(result.fallthrough)
            for changed in (tail.replace('7, 8', '7, 9'), tail.replace('waitstate', 'end')):
                with self.subTest(entry=entry, changed=changed), self.assertRaises(ValueError):
                    self.parse(changed, owner=owner)
        self.assertTrue(self.parse(tail).may_fall_through)

    def test_unreachable_wait_after_continue_jump_does_not_award_a_win(self):
        owner = ROOM + '_EventScript_ContinueChallenge'
        tail = 'goto ' + INTRO + '\nwaitstate'
        result = self.parse(tail, owner=owner)
        self.assertFalse(result.may_fall_through)
        self.assertIsNone(result.fallthrough)
        self.assertIn(INTRO, result.targets)
        for changed in (tail.replace(INTRO, ROOM + '_EventScript_ReturnToLobbyWon'),
                        tail.replace('waitstate', 'delay 1')):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed, owner=owner)
        self.assertTrue(self.parse(tail).may_fall_through)

    def test_four_movement_prefixes_require_exact_steps_and_actual_owners(self):
        prefixes = {owner: value for owner, value in profile.MOVEMENT_PREFIXES.items()
                    if owner.startswith('BattleFrontier_BattleArena')}
        self.assertEqual(len(prefixes), 4)
        for owner, (target, steps) in prefixes.items():
            result = self.parse('\n'.join(steps), owner=owner)
            self.assertEqual((result.size, result.fallthrough), (len(steps), target))
            for changed in (steps + ('walk_up',), tuple(s.replace('walk_', 'walk_fast_') for s in steps)):
                with self.subTest(owner=owner, changed=changed), self.assertRaises(ValueError):
                    self.parse('\n'.join(changed), owner=owner)
            with self.assertRaises(ValueError):
                self.parse('\n'.join(steps), owner='UnreviewedMovement')

    def test_arena_extensions_leave_legacy_profiles_closed(self):
        for text in ('arena_init', 'arena_gettrainername', 'arena_save 0',
                     'arena_set ARENA_DATA_WIN_STREAK, 0', 'frontier_results FRONTIER_FACILITY_ARENA'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn', version=3)
        self.assertTrue(self.parse('goto ' + INTRO + '\nwaitstate',
                                  owner=ROOM + '_EventScript_ContinueChallenge', version=3).may_fall_through)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_nine_observed_arena_forms_match_native_macro_widths(self):
        samples = {line for name in MAPS
                   for body in review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text()).values()
                   for line in review.statements(body)
                   if line.startswith(('arena_', 'frontier_results'))}
        self.assertEqual(len(samples), 9)
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_twenty_three_script_and_four_movement_edges_match_native_rom(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        count = 0
        for name in MAPS:
            for label, body in review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text()).items():
                if label not in profile.FALLTHROUGHS and label not in profile.MOVEMENT_PREFIXES:
                    continue
                with self.subTest(label=label):
                    at = next(iter(symbols[label]))
                    result = profile.profile_block(ROOT, body, version=4, address=at)
                    self.assertEqual(symbols[result.fallthrough], {at + result.size})
                    self.assertEqual(verifier.assemble_candidate(body, at),
                                     rom[at - 0x08000000:at - 0x08000000 + result.size])
                count += 1
        self.assertEqual(count, 27)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_actual_arena_table_and_assembler_alias_match_all_seven_targets(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        targets = ('InitArenaChallenge', 'GetArenaData', 'SetArenaData', 'sub_081A56B4',
                   'SetArenaPrize', 'GiveArenaPrize', 'BufferArenaOpponentName')
        payload = struct.pack('<7I', *(next(iter(symbols[name])) | 1 for name in targets))
        self.assertEqual(symbols['sArenaFunctions'], symbols['gUnknown_85DD7BC'])
        at = next(iter(symbols['sArenaFunctions'])) - 0x08000000
        self.assertEqual((ROOT / 'baserom_jp.gba').read_bytes()[at:at + 28], payload)
        source = (ROOT / 'src/battle_arena.c').read_text().split('const u8 gUnknown_85DD7BC[] = {', 1)[1].split('};', 1)[0]
        self.assertEqual(bytes(int(v, 16) for v in re.findall(r'0x([0-9a-fA-F]{2})', source)), payload)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_intro_and_jp_battle_helper_keep_exact_rom_and_temp_two_omission(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        blocks = review.label_blocks((ROOT / f'data/maps/{ROOM}/scripts.inc').read_text())
        for label in (INTRO, ROOM + '_EventScript_DoArenaBattle'):
            at = next(iter(symbols[label]))
            result = profile.profile_block(ROOT, blocks[label], version=4, address=at)
            self.assertEqual(verifier.assemble_candidate(blocks[label], at),
                             rom[at - 0x08000000:at - 0x08000000 + result.size])
        self.assertNotIn('setvar VAR_TEMP_2, 0', review.statements(blocks[ROOM + '_EventScript_DoArenaBattle']))


if __name__ == '__main__':
    unittest.main()
