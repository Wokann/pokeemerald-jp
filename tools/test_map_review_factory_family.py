"""Factory sentinels, explicit rental waits, shared speech and native dispatch."""
from pathlib import Path
import re
import struct
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
MAPS = ['BattleFrontier_BattleFactory' + part for part in ('Lobby', 'PreBattleRoom', 'BattleRoom')]
ROOM = MAPS[2]
INTRO = ROOM + '_EventScript_BattleOpponent'


class FactoryFamilyProfileTests(unittest.TestCase):
    def parse(self, body, *, owner='Owner', waits=None, version=4):
        return profile.profile_block(ROOT, owner + '::\n' + body, waits,
                                     version=version, address=0x08230DBB)

    def test_observed_factory_selectors_follow_real_special_wait_widths(self):
        forms = [('factory_' + name, 8) for name in
                 ('init', 'rentmons', 'swapmons', 'setswapped', 'generateopponentmons',
                  'generaterentalmons', 'getopponentmontype', 'getopponentstyle')]
        forms += [('factory_get FACTORY_DATA_WIN_STREAK' + suffix, 13) for suffix in ('', '_SWAPS')]
        forms += [('factory_save ' + value, 13) for value in
                  ('0', 'CHALLENGE_STATUS_SAVING', 'CHALLENGE_STATUS_PAUSED')]
        for text, size in forms:
            for wait in (0, 1):
                result = self.parse(text + '\nreturn', waits={'CallBattleFactoryFunction': wait})
                self.assertEqual(result.size, size + wait + 1, text)
                self.assertEqual(result.specials, {'CallBattleFactoryFunction': wait})
        for text in ('factory_init 0', 'factory_get FACTORY_DATA_WIN_STREAK_ACTIVE',
                     'factory_get FACTORY_DATA_UNKNOWN', 'factory_save CHALLENGE_STATUS_OTHER',
                     'factory_rentmons 1', 'factory_swapmons 0'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_omitted_factory_value_preserves_register_and_literal_writes_have_correct_sizes(self):
        for suffix in ('', ', 0xFFFF', ', 65535'):
            self.assertEqual(self.parse('factory_set FACTORY_DATA_WIN_STREAK_SWAPS' + suffix + '\nreturn').size, 14)
        for suffix in (', 0', ', TRUE', ', FALSE', ', VAR_RESULT'):
            self.assertEqual(self.parse('factory_set FACTORY_DATA_WIN_STREAK' + suffix + '\nreturn').size, 19)
        for text in ('factory_set FACTORY_DATA_UNKNOWN', 'factory_set FACTORY_DATA_WIN_STREAK, VAR_0x8004',
                     'factory_set FACTORY_DATA_WIN_STREAK, 65536', 'factory_set FACTORY_DATA_WIN_STREAK, (1+1)',
                     'factory_set FACTORY_DATA_WIN_STREAK, 0, 1'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_results_use_only_two_explicit_factory_modes(self):
        for mode in ('SINGLES', 'DOUBLES'):
            self.assertEqual(self.parse('frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_' + mode + '\nreturn').size, 19)
        for suffix in ('', ', 0xFF', ', FRONTIER_MODE_MULTIS', ', FRONTIER_MODE_LINK_MULTIS'):
            with self.subTest(suffix=suffix), self.assertRaises(ValueError):
                self.parse('frontier_results FRONTIER_FACILITY_FACTORY' + suffix + '\nreturn')

    def test_factory_speech_uses_exact_palace_then_lock_sequence(self):
        body = 'palace_getopponentintro\nlockall\nmsgbox gStringVar4, MSGBOX_DEFAULT\nreturn'
        result = self.parse(body, owner=INTRO)
        self.assertEqual(result.runtime_texts, {'gStringVar4': 'palace_getopponentintro'})
        self.assertNotIn('gStringVar4', result.texts)
        for changed in (body.replace('lockall\n', ''), body.replace('lockall', 'delay 1'),
                        body.replace('palace_getopponentintro', 'factory_setopponentgfx'),
                        body.replace('MSGBOX_DEFAULT', 'MSGBOX_SIGN')):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed, owner=INTRO)
        with self.assertRaises(ValueError):
            self.parse(body, owner='UnreviewedOwner')

    def test_rental_and_swap_screens_keep_explicit_waits_with_nonwaiting_table(self):
        self.assertEqual(profile.special_waits(ROOT)['CallBattleFactoryFunction'], 0)
        blocks = review.label_blocks((ROOT / f'data/maps/{MAPS[1]}/scripts.inc').read_text())
        for entry, op in (('EnterRoom', 'factory_rentmons'), ('SwapMons', 'factory_swapmons')):
            lines = review.statements(blocks[MAPS[1] + '_EventScript_' + entry])
            index = lines.index(op)
            self.assertEqual(lines[index + 1], 'waitstate')
            self.assertEqual(self.parse(op + '\nwaitstate\nreturn').size, 10)

    def test_round_return_warp_cannot_fall_into_challenge_win(self):
        owner = ROOM + '_EventScript_IncrementBattleNum'
        tail = 'warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 8\nwaitstate'
        result = self.parse(tail, owner=owner)
        self.assertEqual(result.context_warp, 'MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM')
        self.assertFalse(result.may_fall_through)
        self.assertIsNone(result.fallthrough)
        for changed in (tail.replace('8, 8', '8, 9'), tail.replace('waitstate', 'end')):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed, owner=owner)
        self.assertTrue(self.parse(tail).may_fall_through)

    def test_factory_extensions_keep_legacy_profile_closed(self):
        for text in ('factory_init', 'factory_get FACTORY_DATA_WIN_STREAK',
                     'factory_save 0', 'factory_set FACTORY_DATA_WIN_STREAK_SWAPS',
                     'frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn', version=3)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_twenty_five_observed_forms_and_sentinel_alias_match_native_widths(self):
        samples = {line for name in MAPS
                   for body in review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text()).values()
                   for line in review.statements(body)
                   if line.startswith(('factory_', 'frontier_results'))}
        self.assertEqual(len(samples), 25)
        samples |= {'factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0xFFFF'}
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_all_twenty_eight_factory_fallthroughs_match_native_rom(self):
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
        self.assertEqual(count, 28)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_all_seventeen_dispatch_slots_match_source_rom_and_factory_object_owner(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        at = next(iter(symbols['gUnknown_85DD958'])) - 0x08000000
        payload = rom[at:at + 68]
        source = (ROOT / 'src/battle_factory.c').read_text().split('const u8 gUnknown_85DD958[] = {', 1)[1].split('};', 1)[0]
        self.assertEqual(bytes(int(v, 16) for v in re.findall(r'0x([0-9a-fA-F]{2})', source)), payload)
        targets = ('InitFactoryChallenge', 'GetBattleFactoryData', 'SetBattleFactoryData', 'sub_081A5ED4',
                   'sub_081A5F18', 'nullsub_123', 'SelectInitialRentalMons', 'sub_081A5F30',
                   'SetPerformedRentalSwap', 'SetRentalsToOpponentParty', 'SetPlayerAndOpponentParties',
                   'SetOpponentGfxVar', 'sub_081A5F48', 'sub_081A6584',
                   'GetOpponentMostCommonMonType', 'GetOpponentBattleStyle', 'RestorePlayerPartyHeldItems')
        owners = []
        for line in (ROOT / 'pokeemerald_jp.map').read_text().splitlines():
            match = re.match(r'^\s*(?:\S+\s+)?(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\S+\.o)\s*$', line)
            if match and (match[3] == 'src/battle_factory.o' or match[3].endswith('/src/battle_factory.o')):
                owners.append((int(match[1], 16), int(match[2], 16)))
        for ptr, target in zip(struct.unpack('<17I', payload), targets):
            self.assertTrue(ptr & 1)
            # SelectInitialRentalMons also names a local party-menu function.
            self.assertIn(ptr, {value | 1 for value in symbols[target]})
            self.assertTrue(any(start <= (ptr & ~1) < start + size for start, size in owners))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_actual_resume_and_speech_keep_jp_omission_and_native_bytes(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, label in ((ROOM, INTRO), (MAPS[1], MAPS[1] + '_EventScript_ResumeChallenge')):
            body = review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())[label]
            at = next(iter(symbols[label]))
            result = profile.profile_block(ROOT, body, version=4, address=at)
            self.assertEqual(verifier.assemble_candidate(body, at),
                             rom[at - 0x08000000:at - 0x08000000 + result.size])
            if name == MAPS[1]:
                self.assertNotIn('special CalculatePlayerPartyCount', review.statements(body))


if __name__ == '__main__':
    unittest.main()
