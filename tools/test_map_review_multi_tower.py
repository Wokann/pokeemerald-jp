"""Bounded Multi Tower selectors, RAM introductions and physical script edges."""
from pathlib import Path
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
ROOM = 'BattleFrontier_BattleTowerMultiBattleRoom'
NORMAL = ROOM + '_EventScript_OpponentsEnter'
LINK = ROOM + '_EventScript_DoOpponentIntrosLink'


class MultiTowerProfileTests(unittest.TestCase):
    def parse(self, body, *, owner='Owner', waits=None, version=4):
        return profile.profile_block(ROOT, owner + '::\n' + body, waits,
                                     version=version, address=0x082229A1)

    def intro(self, index, operation):
        lines = ['tower_getopponentintro ' + str(index)]
        if index == 0:
            lines.append('delay 15')
        lines.append(f'applywaitmovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_{index + 1}, {ROOM}_Movement_WalkInPlaceLeft')
        lines.append('msgbox gStringVar4, MSGBOX_DEFAULT' if operation == 'msgbox'
                     else 'messageautoscroll gStringVar4')
        return '\n'.join(lines)

    def test_all_four_causal_message_windows_use_ram_without_a_rom_text_claim(self):
        for owner, operation in ((NORMAL, 'msgbox'), (LINK, 'messageautoscroll')):
            for index in (0, 1):
                with self.subTest(owner=owner, index=index):
                    result = self.parse(self.intro(index, operation) + '\nreturn', owner=owner)
                    self.assertEqual(result.runtime_texts, {'gStringVar4': 'tower_getopponentintro'})
                    self.assertNotIn('gStringVar4', result.texts)
                    self.assertIn(ROOM + '_Movement_WalkInPlaceLeft', result.targets)

    def test_changed_delay_movement_clobber_and_unreviewed_owner_are_rejected(self):
        for owner, operation in ((NORMAL, 'msgbox'), (LINK, 'messageautoscroll')):
            for index in (0, 1):
                original = self.intro(index, operation)
                changed = [original.replace('WalkInPlaceLeft', 'OtherMovement'),
                           original.replace(f'OPPONENT_{index + 1}', f'OPPONENT_{2 - index}'),
                           original.replace('\napplywaitmovement', '\nspecial HealPlayerParty\napplywaitmovement')]
                if index == 0:
                    changed += [original.replace('delay 15', 'delay 16'),
                                original.replace('delay 15\n', '')]
                else:
                    changed.append(original.replace('\napplywaitmovement', '\ndelay 15\napplywaitmovement'))
                for body in changed:
                    with self.subTest(owner=owner, body=body), self.assertRaises(ValueError):
                        self.parse(body + '\nreturn', owner=owner)
                with self.assertRaises(ValueError):
                    self.parse(original + '\nreturn', owner='UnreviewedOwner')

    def test_wrong_message_operation_cannot_borrow_the_other_owner_context(self):
        for owner, operation in ((NORMAL, 'messageautoscroll'), (LINK, 'msgbox')):
            for index in (0, 1):
                with self.subTest(owner=owner, index=index), self.assertRaises(ValueError):
                    self.parse(self.intro(index, operation) + '\nreturn', owner=owner)

    def test_autoscroll_and_second_opponent_require_a_producer_in_the_same_block(self):
        for owner, body in ((LINK, 'messageautoscroll gStringVar4'),
                            (LINK, 'tower_getopponentintro 1\nmessageautoscroll gStringVar4'),
                            ('Owner', 'tower_getopponentintro 1\nmsgbox gStringVar4, MSGBOX_DEFAULT')):
            with self.subTest(body=body), self.assertRaises(ValueError):
                self.parse(body + '\nreturn', owner=owner)

    def test_multi_selectors_include_only_observed_ids_and_real_table_waits(self):
        forms = [('tower_loadpartners', 'CallBattleTowerFunc', 8),
                 ('tower_setpartnergfx', 'CallBattleTowerFunc', 8),
                 ('pyramid_resetparty', 'CallBattlePyramidFunction', 8),
                 ('tower_getopponentintro 1', 'CallBattleTowerFunc', 13),
                 ('frontier_setpartyorder FRONTIER_MULTI_PARTY_SIZE', 'CallFrontierUtilFunc', 13)]
        forms += [('tower_dopartnermsg PARTNER_MSGID_' + name, 'CallBattleTowerFunc', 13)
                  for name in ('INTRO', 'MON1', 'MON2_ASK', 'ACCEPT', 'REJECT')]
        for text, handler, size in forms:
            for wait in (0, 1):
                with self.subTest(text=text, wait=wait):
                    result = self.parse(text + '\nreturn', waits={handler: wait})
                    self.assertEqual(result.size, size + wait + 1)
                    self.assertEqual(result.specials, {handler: wait})
        for text in ('tower_loadpartners 0', 'tower_setpartnergfx 1', 'pyramid_resetparty 0',
                     'tower_getopponentintro 2', 'tower_dopartnermsg PARTNER_MSGID_OTHER',
                     'tower_dopartnermsg 0', 'frontier_setpartyorder FRONTIER_OTHER_PARTY_SIZE'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn')

    def test_new_selectors_and_ram_windows_do_not_change_legacy_profile(self):
        for text in ('tower_loadpartners', 'tower_setpartnergfx', 'pyramid_resetparty',
                     'tower_getopponentintro 1', 'tower_dopartnermsg PARTNER_MSGID_INTRO',
                     'frontier_setpartyorder FRONTIER_MULTI_PARTY_SIZE',
                     self.intro(0, 'messageautoscroll')):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text + '\nreturn', owner=LINK, version=3)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_observed_multi_selector_forms_expand_to_predicted_bytes(self):
        paths = [ROOT / f'data/maps/{name}/scripts.inc' for name in
                 ('BattleFrontier_BattleTowerMultiPartnerRoom',
                  'BattleFrontier_BattleTowerMultiCorridor', ROOM)]
        samples = {line for path in paths for body in review.label_blocks(path.read_text()).values()
                   for line in review.statements(body)
                   if line.startswith(('tower_', 'frontier_', 'pyramid_'))}
        self.assertEqual(len(samples), 20)
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_real_intro_owners_reassemble_exactly_including_delays_and_waits(self):
        blocks = review.label_blocks((ROOT / f'data/maps/{ROOM}/scripts.inc').read_text())
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for label in (NORMAL, LINK):
            at = next(iter(symbols[label]))
            result = profile.profile_block(ROOT, blocks[label], version=4, address=at)
            self.assertEqual(result.runtime_texts, {'gStringVar4': 'tower_getopponentintro'})
            self.assertEqual(verifier.assemble_candidate(blocks[label], at),
                             rom[at - 0x08000000:at - 0x08000000 + result.size])
        movement = ROOM + '_Movement_WalkInPlaceLeft'
        self.assertEqual(review.statements(blocks[movement]), ['walk_in_place_left', 'step_end'])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_all_eleven_multi_fallthroughs_are_native_rom_adjacencies(self):
        blocks = review.label_blocks((ROOT / f'data/maps/{ROOM}/scripts.inc').read_text())
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        edges = {owner: target for owner, target in profile.FALLTHROUGHS.items()
                 if owner.startswith(ROOM + '_')}
        self.assertEqual(len(edges), 11)
        for owner, target in edges.items():
            with self.subTest(owner=owner):
                at = next(iter(symbols[owner]))
                result = profile.profile_block(ROOT, blocks[owner], version=4, address=at)
                self.assertEqual(result.fallthrough, target)
                self.assertEqual(symbols[target], {at + result.size})
                self.assertEqual(verifier.assemble_candidate(blocks[owner], at),
                                 rom[at - 0x08000000:at - 0x08000000 + result.size])


if __name__ == '__main__':
    unittest.main()
