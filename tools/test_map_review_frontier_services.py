"""Bounded service-map constants, actual waits and JP/native differences."""
from pathlib import Path
import re
import struct
import subprocess
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms

ROOT = Path(__file__).resolve().parents[1]
LOUNGE = 'BattleFrontier_Lounge3'
US_REF = '731ad5bfd6e6f265508d0efcca0ba42f9dcf5881'


class FrontierServiceProfileTests(unittest.TestCase):
    def parse(self, body, owner='UnreviewedOwner', version=4):
        return profile.profile_block(ROOT, owner + '::\n' + body,
                                     version=version, address=0x08235360)

    def declarations(self):
        return '.byte 0\n.set BET_AMOUNT_5,  5\n.set BET_AMOUNT_10, 10\n.set BET_AMOUNT_15, 15'

    def reward(self, value):
        return (f'buffernumberstring STR_VAR_1, (BET_AMOUNT_{value} * 2)\n'
                f'setvar VAR_0x8004, (BET_AMOUNT_{value} * 2)\nreturn')

    def native(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        return symbols, (ROOT / 'baserom_jp.gba').read_bytes()

    def test_scalar_declarations_are_exact_and_emit_only_map_terminator(self):
        result = self.parse(self.declarations(), LOUNGE + '_MapScripts')
        self.assertEqual((result.kind, result.size), ('map_table', 1))
        for body in (self.declarations().replace('_5,  5', '_5,  6'),
                     self.declarations() + '\n.set Extra, 0x08235360',
                     self.declarations().replace('.byte 0', '.byte 1')):
            with self.subTest(body=body), self.assertRaises(ValueError):
                self.parse(body, LOUNGE + '_MapScripts')
        with self.assertRaises(ValueError):
            self.parse(self.declarations())

    def test_reward_expressions_require_the_real_owner_register_and_amount(self):
        for value in (5, 10, 15):
            owner = LOUNGE + f'_EventScript_RewardBet{value}'
            body = self.reward(value)
            self.assertEqual(self.parse(body, owner).size, 10)
            for changed in (body.replace('* 2', '* 3'), body.replace('STR_VAR_1', 'STR_VAR_2'),
                            body.replace('VAR_0x8004', 'VAR_0x8005'),
                            body.replace(f'BET_AMOUNT_{value}', 'BET_AMOUNT_999')):
                with self.subTest(value=value, changed=changed), self.assertRaises(ValueError):
                    self.parse(changed, owner)
            with self.assertRaises(ValueError):
                self.parse(body)

    def test_new_forms_do_not_open_legacy_reviews_or_general_expressions(self):
        for owner, body in ((LOUNGE + '_MapScripts', self.declarations()),
                            (LOUNGE + '_EventScript_RewardBet5', self.reward(5))):
            with self.assertRaises(ValueError):
                self.parse(body, owner, version=3)
        for expression in ('(5 * 2)', '(BET_AMOUNT_5 + 5)', '(BET_AMOUNT_5*2)',
                           '(BET_AMOUNT_5 * 2 + 1)'):
            with self.subTest(expression=expression), self.assertRaises(ValueError):
                self.parse('setvar VAR_0x8004, ' + expression + '\nreturn',
                           LOUNGE + '_EventScript_RewardBet5')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_three_rewards_match_actual_rom_opcodes_values_and_lengths(self):
        symbols, rom = self.native()
        for value in (5, 10, 15):
            label = LOUNGE + f'_EventScript_RewardBet{value}'
            self.assertEqual(len(symbols[label]), 1)
            address = next(iter(symbols[label]))
            actual = rom[address - 0x08000000:address - 0x08000000 + 10]
            expected = b'\x83\x00' + struct.pack('<H', value * 2)
            expected += b'\x16\x04\x80' + struct.pack('<H', value * 2) + b'\x03'
            self.assertEqual(actual, expected, label)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_native_map_table_has_no_bytes_for_scalar_definitions(self):
        symbols, rom = self.native()
        start = next(iter(symbols[LOUNGE + '_MapScripts']))
        gambler = next(iter(symbols[LOUNGE + '_EventScript_Gambler']))
        self.assertEqual(gambler, start + 1)
        self.assertEqual(rom[start - 0x08000000:gambler - 0x08000000], b'\x00')

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_each_expression_and_declaration_matches_fresh_native_expansion(self):
        prefix = '\n'.join(self.declarations().splitlines()[1:])
        samples = set(prefix.splitlines())
        owners = {}
        for value in (5, 10, 15):
            for line in self.reward(value).splitlines()[:-1]:
                samples.add(line)
                owners[line] = LOUNGE + f'_EventScript_RewardBet{value}'
        native_forms.StoryProfileTests().check_native_forms(
            sorted(samples), version=4, source_prefix=prefix, source_owners=owners)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_party_selection_uses_actual_implicit_wait_without_duplication(self):
        self.assertEqual(profile.special_waits(ROOT)['ChoosePartyMon'], 1)
        self.assertEqual(self.parse('special ChoosePartyMon\nreturn').size, 5)
        symbols, rom = self.native()
        label = 'BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder'
        address = next(iter(symbols[label])) - 0x08000000
        self.assertEqual((rom[address], rom[address + 3]), (0x25, 0x27))
        self.assertNotEqual(rom[address + 4], 0x27)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_tutor_keeps_four_native_jp_redraw_state_omissions(self):
        path = 'data/maps/BattleFrontier_Lounge7/scripts.inc'
        jp = review.label_blocks((ROOT / path).read_text())
        us = review.label_blocks(subprocess.check_output(
            ['git', '--no-replace-objects', '-C', '/home/kenny/pokeemerald',
             'show', US_REF + ':' + path], text=True))
        symbols, rom = self.native()
        for suffix, value, prefix_size in (('ChooseLeftTutorMove', 0, 19),
                                            ('ChooseNewLeftTutorMove', 1, 16),
                                            ('ChooseRightTutorMove', 0, 19),
                                            ('ChooseNewRightTutorMove', 1, 16)):
            label = 'BattleFrontier_Lounge7_EventScript_' + suffix
            jp_lines = review.statements(jp[label])
            us_lines = review.statements(us[label])
            extra = f'setvar VAR_0x8006, {value}'
            self.assertIn(extra, us_lines)
            self.assertNotIn(extra, jp_lines)
            self.assertEqual(jp_lines, [line for line in us_lines if line != extra])
            offset = next(iter(symbols[label])) - 0x08000000 + prefix_size
            self.assertEqual(rom[offset], 0x25, label)


if __name__ == '__main__':
    unittest.main()
