"""Exact Birth Island effect arguments, event mon, waits and native bytes."""
from pathlib import Path
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
DEOXYS = 'BirthIsland_Exterior_EventScript_Deoxys'
FORMS = ('setfieldeffectargument 1, MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR)',
         'setfieldeffectargument 2, MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR)',
         'seteventmon SPECIES_DEOXYS, 30')


class BirthIslandProfileTests(unittest.TestCase):
    def parse(self, line, *, owner=DEOXYS, version=4):
        return profile.profile_block(ROOT, owner + '::\n' + line + '\nreturn',
                                     version=version, address=0x0823B5CE)

    def test_actual_effect_argument_pairs_and_deoxys_parameters_have_native_widths(self):
        for line, size in zip(FORMS, (5, 5, 19)):
            self.assertEqual(self.parse(line).size, size)
        self.assertEqual(self.parse(FORMS[2]).specials, {'CreateEnemyEventMon': 0})

    def test_changed_map_selector_owner_level_item_and_legacy_forms_stay_closed(self):
        bad = (FORMS[0].replace('argument 1', 'argument 2'),
               FORMS[1].replace('argument 2', 'argument 1'),
               FORMS[0].replace('EXTERIOR', 'HARBOR'),
               FORMS[1].replace('EXTERIOR', 'HARBOR'),
               FORMS[0] + ' + 1', FORMS[2].replace('30', '50'),
               FORMS[2] + ', ITEM_NONE', FORMS[2].replace('DEOXYS', 'MEW'))
        for line in bad:
            with self.subTest(line=line), self.assertRaises(ValueError):
                self.parse(line)
        for line in FORMS:
            with self.assertRaises(ValueError):
                self.parse(line, owner='UnreviewedOwner')
            with self.assertRaises(ValueError):
                self.parse(line, version=3)

    def test_rock_task_palette_and_legendary_use_actual_special_wait_contracts(self):
        waits = profile.special_waits(ROOT)
        self.assertEqual({name: waits[name] for name in
            ('DoDeoxysRockInteraction', 'SetDeoxysRockPalette',
             'BattleSetup_StartLegendaryBattle', 'CreateEnemyEventMon')},
            dict(DoDeoxysRockInteraction=1, SetDeoxysRockPalette=0,
                 BattleSetup_StartLegendaryBattle=1, CreateEnemyEventMon=0))
        self.assertEqual(self.parse('special DoDeoxysRockInteraction').size, 5)
        self.assertEqual(self.parse('special SetDeoxysRockPalette').size, 4)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_three_forms_match_fresh_native_expansion_with_both_event_mon_waits(self):
        for wait in (0, 1):
            native_forms.StoryProfileTests().check_native_forms(
                list(FORMS), forced_waits={'CreateEnemyEventMon': wait}, version=4,
                source_owners={line: DEOXYS for line in FORMS})

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_entire_deoxys_entry_matches_jp_rom_including_cry_effect_and_object(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        block = review.label_blocks((ROOT / 'data/maps/BirthIsland_Exterior/scripts.inc').read_text())[DEOXYS]
        at = next(iter(symbols[DEOXYS]))
        result = profile.profile_block(ROOT, block, version=4, address=at)
        expected = (ROOT / 'baserom_jp.gba').read_bytes()[at - 0x08000000:at - 0x08000000 + result.size]
        self.assertEqual(verifier.assemble_candidate(block, at), expected)
        self.assertEqual(result.specials['BattleSetup_StartLegendaryBattle'], 1)
        self.assertEqual(verifier.assemble_candidate('Entry::\nwaitmoncry', at), b'\xC5')


if __name__ == '__main__':
    unittest.main()
