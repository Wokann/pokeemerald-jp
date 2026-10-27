"""Measured Palace selectors, causal speech, exact edges and native dispatch."""
from pathlib import Path
import copy
import re
import struct
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
ROOM = 'BattleFrontier_BattlePalaceBattleRoom'
INTRO = ROOM + '_EventScript_NextOpponentEnter'
MAPS = ['BattleFrontier_BattlePalace' + part for part in ('Lobby', 'Corridor', 'BattleRoom')]


class PalaceFamilyProfileTests(unittest.TestCase):
    def parse(self, body, *, owner='Owner', waits=None, version=4):
        return profile.profile_block(ROOT, owner + '::\n' + body, waits,
                                     version=version, address=0x08229D56)

    def test_observed_palace_and_trainer_selectors_use_actual_special_wait_widths(self):
        forms = [('palace_' + name, 8) for name in
                 ('init', 'getcomment', 'getopponentintro', 'incrementstreak')]
        forms += [('palace_get PALACE_DATA_PRIZE', 13)]
        forms += [('palace_set PALACE_DATA_WIN_STREAK_ACTIVE, ' + value, 18)
                  for value in ('0', 'TRUE', 'FALSE')]
        forms += [('palace_save ' + value, 13) for value in
                  ('0', 'CHALLENGE_STATUS_SAVING', 'CHALLENGE_STATUS_PAUSED')]
        for text, size in forms:
            for wait in (0, 1):
                with self.subTest(text=text, wait=wait):
                    result = self.parse(text + '\nreturn', waits={'CallBattlePalaceFunction': wait})
                    self.assertEqual(result.size, size + wait + 1)
                    self.assertEqual(result.specials, {'CallBattlePalaceFunction': wait})
        self.assertEqual(self.parse('frontier_settrainers\nreturn').size, 9)
        self.assertEqual(profile.special_waits(ROOT)['CallBattlePalaceFunction'], 0)
        for text in ('palace_init 0', 'palace_get PALACE_DATA_OTHER',
                     'palace_set PALACE_DATA_WIN_STREAK_ACTIVE',
                     'palace_set PALACE_DATA_WIN_STREAK_ACTIVE, 0xFFFF',
                     'palace_set PALACE_DATA_WIN_STREAK_ACTIVE, VAR_RESULT',
                     'palace_save CHALLENGE_STATUS_OTHER', 'palace_setprize', 'palace_giveprize'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_palace_results_keep_only_the_two_explicit_observed_modes(self):
        for mode in ('SINGLES', 'DOUBLES'):
            self.assertEqual(self.parse('frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_' + mode + '\nreturn').size, 19)
        for text in ('frontier_results FRONTIER_FACILITY_PALACE',
                     'frontier_results FRONTIER_FACILITY_PALACE, 0xFF',
                     'frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_MULTIS',
                     'frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_LINK_MULTIS'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_palace_ram_message_requires_its_real_owner_producer_and_mode(self):
        body = 'palace_getopponentintro\nmsgbox gStringVar4, MSGBOX_DEFAULT\nreturn'
        result = self.parse(body, owner=INTRO)
        self.assertEqual(result.runtime_texts, {'gStringVar4': 'palace_getopponentintro'})
        self.assertNotIn('gStringVar4', result.texts)
        for changed in (body.replace('palace_getopponentintro\n', ''),
                        body.replace('\nmsgbox', '\ndelay 1\nmsgbox'),
                        body.replace('\nmsgbox', '\nspecial HealPlayerParty\nmsgbox'),
                        body.replace('MSGBOX_DEFAULT', 'MSGBOX_SIGN'),
                        'palace_getopponentintro\nmessageautoscroll gStringVar4\nreturn'):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed, owner=INTRO)
        with self.assertRaises(ValueError):
            self.parse(body, owner='UnreviewedOwner')

    def test_two_exact_movement_prefixes_reject_changed_lengths_and_directions(self):
        prefixes = {owner: value for owner, value in profile.MOVEMENT_PREFIXES.items()
                    if owner.startswith('BattleFrontier_BattlePalace')}
        self.assertEqual(len(prefixes), 2)
        for owner, (target, steps) in prefixes.items():
            result = self.parse('\n'.join(steps), owner=owner)
            self.assertEqual((result.size, result.fallthrough), (len(steps), target))
            for changed in (steps + ('walk_up',), tuple(s.replace('up', 'down') for s in steps)):
                with self.subTest(owner=owner, changed=changed), self.assertRaises(ValueError):
                    self.parse('\n'.join(changed), owner=owner)
            with self.assertRaises(ValueError):
                self.parse('\n'.join(steps), owner='UnreviewedMovement')

    def test_palace_extensions_leave_legacy_forms_closed(self):
        for text in ('palace_init', 'palace_get PALACE_DATA_PRIZE',
                     'palace_set PALACE_DATA_WIN_STREAK, 0', 'palace_getopponentintro',
                     'frontier_settrainers', 'frontier_results FRONTIER_FACILITY_PALACE, FRONTIER_MODE_SINGLES'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn', owner=INTRO, version=3)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_every_observed_palace_selector_matches_native_macro_expansion(self):
        samples = {line for name in MAPS
                   for body in review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text()).values()
                   for line in review.statements(body)
                   if line.startswith(('palace_', 'frontier_settrainers', 'frontier_results'))}
        self.assertEqual(len(samples), 14)
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_all_twenty_four_script_and_two_movement_edges_are_real_rom_adjacencies(self):
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
        self.assertEqual(count, 26)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_real_intro_and_jp_battle_helper_reassemble_without_a_temp_two_clear(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        blocks = review.label_blocks((ROOT / f'data/maps/{ROOM}/scripts.inc').read_text())
        for label in (INTRO, ROOM + '_EventScript_DoPalaceBattle'):
            at = next(iter(symbols[label]))
            result = profile.profile_block(ROOT, blocks[label], version=4, address=at)
            self.assertEqual(verifier.assemble_candidate(blocks[label], at),
                             rom[at - 0x08000000:at - 0x08000000 + result.size])
        self.assertNotIn('setvar VAR_TEMP_2, 0', review.statements(blocks[ROOM + '_EventScript_DoPalaceBattle']))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_all_ten_palace_dispatch_slots_match_actual_source_and_rom(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        source = (ROOT / 'src/battle_palace.c').read_text().split('static void (*const sBattlePalaceFunctions[])(void) BATTLE_PALACE_DATA =', 1)[1].split('};', 1)[0]
        entries = re.findall(r'\[(BATTLE_PALACE_FUNC_\w+)\]\s*=\s*(\w+)', source)
        self.assertEqual(len(entries), 10)
        slots = {review._literal_define(ROOT, 'include/constants/battle_palace.h', key):
                 next(iter(symbols[value])) | 1 for key, value in entries}
        self.assertEqual(set(slots), set(range(10)))
        payload = struct.pack('<10I', *(slots[index] for index in range(10)))
        at = next(iter(symbols['sBattlePalaceFunctions']))
        self.assertEqual(rom[at - 0x08000000:at - 0x08000000 + len(payload)], payload)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_palace_producer_buffer_and_dispatch_reject_forged_native_evidence(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        owners = []
        for line in (ROOT / 'pokeemerald_jp.map').read_text().splitlines():
            match = re.match(r'^\s*(?:\S+\s+)?(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\S+\.o)\s*$', line)
            if match:
                owners.append((int(match[1], 16), int(match[2], 16), match[3]))
        native = dict(symbols=symbols, owners=owners, rom=(ROOT / 'baserom_jp.gba').read_bytes())
        result = self.parse('palace_getopponentintro\nmsgbox gStringVar4, MSGBOX_DEFAULT\nreturn', owner=INTRO)
        errors = []
        review._runtime_text_native(ROOT, result, native, errors)
        self.assertEqual(errors, [])
        for symbol, offset, size, expected in (
                ('sBattlePalaceFunctions', 5 * 4, 4, 'native_runtime_text_palace_dispatch_mismatch'),
                ('BufferOpponentIntroSpeech', 0, 0x2C, 'native_runtime_text_greeting_call_mismatch')):
            wrong = copy.deepcopy(native)
            payload = bytearray(wrong['rom'])
            start = (next(iter(symbols[symbol])) & ~1) - 0x08000000 + offset
            payload[start:start + size] = bytes(size)
            wrong['rom'] = bytes(payload)
            errors = []
            review._runtime_text_native(ROOT, result, wrong, errors)
            self.assertIn(expected, errors)
        wrong = copy.deepcopy(native)
        wrong['runtime_text_symbols']['gStringVar4'] = {0x08229D56}
        errors = []
        review._runtime_text_native(ROOT, result, wrong, errors)
        self.assertIn('native_runtime_text_buffer_mismatch:gStringVar4', errors)


if __name__ == '__main__':
    unittest.main()
