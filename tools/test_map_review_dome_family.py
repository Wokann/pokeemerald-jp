"""Dome selectors, literal draw constants, context exits and native boundaries."""
from pathlib import Path
import re
import struct
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
ROOM = 'BattleFrontier_BattleDomeBattleRoom'
DRAW = '.set NO_DRAW, 0\n.set DRAW_TRAINER, 1\n.set DRAW_TUCKER, 2\n'
MAPS = ['BattleFrontier_BattleDome' + part for part in
        ('Lobby', 'Corridor', 'PreBattleRoom', 'BattleRoom')]


class DomeFamilyProfileTests(unittest.TestCase):
    def parse(self, body, *, owner='Owner', waits=None, version=4):
        return profile.profile_block(ROOT, owner + '::\n' + body, waits,
                                     version=version, address=0x08226D8C)

    def test_dome_selector_widths_follow_the_real_special_wait_metadata(self):
        zero = [name for name, (_, size, args) in profile.FACILITY_FORMS.items()
                if name.startswith('dome_') and not args]
        self.assertEqual(len(zero), 18)
        forms = [(name, 8) for name in zero]
        forms += [('dome_get DOME_DATA_' + data, 13) for data in
                  ('PREV_TOURNEY_TYPE', 'ATTEMPTED_CHALLENGE', 'HAS_WON_CHALLENGE', 'WIN_STREAK_ACTIVE')]
        forms += [('dome_resolvewinners DOME_PLAYER_' + status, 13) for status in
                  ('WON_MATCH', 'LOST_MATCH', 'RETIRED')]
        forms += [('dome_save ' + value, 13) for value in ('0', 'CHALLENGE_STATUS_SAVING', 'CHALLENGE_STATUS_PAUSED')]
        for text, size in forms:
            for wait in (0, 1):
                with self.subTest(text=text, wait=wait):
                    result = self.parse(text + '\nreturn', waits={'CallBattleDomeFunction': wait})
                    self.assertEqual(result.size, size + wait + 1)
                    self.assertEqual(result.specials, {'CallBattleDomeFunction': wait})
        self.assertEqual(profile.special_waits(ROOT)['CallBattleDomeFunction'], 0)

    def test_dome_set_omitted_sentinel_and_literal_writes_have_distinct_widths(self):
        for suffix, size in (('', 13), (', 0xFFFF', 13), (', 65535', 13),
                             (', 0', 18), (', FALSE', 18), (', TRUE', 18)):
            self.assertEqual(self.parse('dome_set DOME_DATA_SELECTED_MONS' + suffix + '\nreturn').size, size + 1)
        for text in ('dome_set DOME_DATA_UNKNOWN', 'dome_set DOME_DATA_SELECTED_MONS, VAR_RESULT',
                     'dome_set DOME_DATA_SELECTED_MONS, 65536', 'dome_set DOME_DATA_SELECTED_MONS, (1+1)',
                     'dome_set DOME_DATA_WIN_STREAK, 0, 1', 'dome_get DOME_DATA_OTHER',
                     'dome_save CHALLENGE_STATUS_OTHER', 'dome_resolvewinners DOME_PLAYER_OTHER',
                     'dome_init 0'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_only_the_two_observed_dome_result_modes_are_admitted(self):
        for mode in ('SINGLES', 'DOUBLES'):
            self.assertEqual(self.parse('frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_' + mode + '\nreturn').size, 19)
        for text in ('frontier_results FRONTIER_FACILITY_DOME',
                     'frontier_results FRONTIER_FACILITY_DOME, 0xFF',
                     'frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_MULTIS',
                     'frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_LINK_MULTIS',
                     'frontier_results FACILITY_LINK_CONTEST, FRONTIER_MODE_SINGLES'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_trainer_name_output_is_limited_to_two_actual_string_variables(self):
        for slot in ('1', '2'):
            result = self.parse('frontier_gettrainername STR_VAR_' + slot + '\nreturn')
            self.assertEqual(result.size, 14)
            self.assertEqual(result.specials, {'CallFrontierUtilFunc': 0})
        for operand in ('STR_VAR_3', 'STR_VAR_4', 'VAR_RESULT', '2'):
            with self.subTest(operand=operand), self.assertRaises(ValueError):
                self.parse('frontier_gettrainername ' + operand + '\nreturn')

    def test_exact_nonaddress_draw_prefix_has_zero_size_and_cannot_be_redefined(self):
        owner = ROOM + '_MapScripts::\n.byte 0\n'
        result = profile.profile_owner(ROOT, DRAW + owner, version=4, address=0x08226D8C)
        self.assertEqual(sum(p.size for p in result.values()), 1)
        for changed in (DRAW.replace('NO_DRAW, 0', 'NO_DRAW, 9'),
                        DRAW.replace('DRAW_TRAINER, 1', 'DRAW_TRAINER, 0x08226D8C'),
                        DRAW + '.set Extra, 0\n', '\n'.join(reversed(DRAW.splitlines())) + '\n'):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                profile.profile_owner(ROOT, changed + owner, version=4, address=0x08226D8C)
        with self.assertRaises(ValueError):
            profile.profile_owner(ROOT, DRAW + owner.replace(ROOM, 'UnreviewedRoom'), version=4, address=0x08226D8C)

    def test_round_return_warp_replaces_the_context_instead_of_winning_the_tourney(self):
        owner = ROOM + '_EventScript_DefeatedOpponent'
        tail = 'warp MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM, 5, 3\nwaitstate'
        result = self.parse(tail, owner=owner)
        self.assertEqual(result.context_warp, 'MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM')
        self.assertFalse(result.may_fall_through)
        self.assertIsNone(result.fallthrough)
        for changed in (tail.replace('5, 3', '5, 4'), tail.replace('waitstate', 'end')):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed, owner=owner)
        self.assertTrue(self.parse(tail).may_fall_through)

    def test_exact_player_entry_prefix_rejects_changed_steps_and_unknown_owners(self):
        owner = ROOM + '_Movement_PlayerEnter'
        target, steps = profile.MOVEMENT_PREFIXES[owner]
        result = self.parse('\n'.join(steps), owner=owner)
        self.assertEqual((result.size, result.fallthrough), (6, target))
        for changed in (steps[:-1], steps + ('walk_up',), ('set_invisible',) + steps[1:]):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse('\n'.join(changed), owner=owner)
        with self.assertRaises(ValueError):
            self.parse('\n'.join(steps), owner='UnreviewedMovement')

    def test_dome_extensions_do_not_broaden_the_legacy_profile(self):
        for body in ('dome_init', 'dome_set DOME_DATA_SELECTED_MONS',
                     'frontier_gettrainername STR_VAR_1',
                     'frontier_results FRONTIER_FACILITY_DOME, FRONTIER_MODE_SINGLES',
                     'jump_2_left\nstep_end', 'enable_jump_landing_ground_effect\nstep_end'):
            with self.subTest(body=body), self.assertRaises(ValueError):
                self.parse(body + '\nreturn' if 'step_end' not in body else body, version=3)
        with self.assertRaises(ValueError):
            profile.profile_owner(ROOT, DRAW + ROOM + '_MapScripts::\n.byte 0', version=3)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_observed_dome_macros_and_four_new_movement_commands_match_native_widths(self):
        samples = {line for name in MAPS
                   for body in review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text()).values()
                   for line in review.statements(body)
                   if line.startswith(('dome_', 'frontier_gettrainername', 'frontier_results'))}
        self.assertEqual(len(samples), 38)
        samples |= {'jump_2_left', 'enable_jump_landing_ground_effect', 'delay_2', 'jump_in_place_up',
                    'dome_set DOME_DATA_SELECTED_MONS, 0xFFFF'}
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4, source_prefix=DRAW)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_all_dome_script_and_movement_edges_are_exact_rom_adjacencies(self):
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
                    self.assertEqual(verifier.assemble_candidate(DRAW + body, at),
                                     rom[at - 0x08000000:at - 0x08000000 + result.size])
                count += 1
        self.assertEqual(count, 33)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_all_twenty_three_real_dome_dispatch_slots_match_source_and_rom(self):
        symbols, memory = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        source = (ROOT / 'src/battle_dome.c').read_text().split('static void (*const sBattleDomeFunctions[])(void) BATTLE_DOME_DATA =', 1)[1].split('};', 1)[0]
        entries = re.findall(r'\[(BATTLE_DOME_FUNC_\w+)\]\s*=\s*(\w+)', source)
        self.assertEqual(len(entries), 23)
        slots = {review._literal_define(ROOT, 'include/constants/battle_dome.h', key):
                 next(iter(symbols[value])) | 1 for key, value in entries}
        self.assertEqual(set(slots), set(range(23)))
        payload = struct.pack('<23I', *(slots[index] for index in range(23)))
        at = next(iter(symbols['sBattleDomeFunctions']))
        self.assertEqual(rom[at - 0x08000000:at - 0x08000000 + len(payload)], payload)
        self.assertTrue(any(base <= at and at + len(payload) <= base + len(data)
                            and data[at - base:at - base + len(payload)] == payload for base, data in memory))


if __name__ == '__main__':
    unittest.main()
