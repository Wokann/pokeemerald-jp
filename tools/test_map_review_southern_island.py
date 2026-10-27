"""Actual Southern Island event-mon parameters and JP cry-wait encoding."""
from pathlib import Path
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]


class SouthernIslandProfileTests(unittest.TestCase):
    def parse(self, statement, version=4, waits=None):
        return profile.profile_block(ROOT, 'Entry::\n' + statement + '\nreturn', waits,
                                     version=version, address=0x08222765)

    def test_observed_species_and_default_item_keep_three_parameter_writes(self):
        for species in ('LATIAS', 'LATIOS'):
            for item in ('', ', ITEM_NONE', ', ITEM_SOUL_DEW'):
                result = self.parse('seteventmon SPECIES_' + species + ', 50' + item)
                self.assertEqual((result.size, result.specials), (19, {'CreateEnemyEventMon': 0}))
                self.assertFalse(result.texts or result.targets or result.trainer_battles)

    def test_unreviewed_arguments_and_legacy_version_stay_closed(self):
        statement = 'seteventmon SPECIES_LATIOS, 50, ITEM_SOUL_DEW'
        for changed in ('seteventmon SPECIES_LATIOS', statement + ', 0',
                        statement.replace('LATIOS', 'PIKACHU'), statement.replace('50', '49'),
                        statement.replace('50', '256'), statement.replace('ITEM_SOUL_DEW', 'VAR_RESULT')):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                self.parse(changed)
        with self.assertRaises(ValueError):
            self.parse(statement, version=3)

    def test_actual_special_wait_is_required_and_optional_metadata_changes_width(self):
        for wait in (0, 1):
            result = self.parse('seteventmon SPECIES_LATIAS, 50, ITEM_SOUL_DEW',
                                waits={'CreateEnemyEventMon': wait})
            self.assertEqual(result.size, 19 + wait)
        for waits in ({}, {'CreateEnemyEventMon': 2}):
            with self.assertRaises(ValueError):
                self.parse('seteventmon SPECIES_LATIOS, 50', waits=waits)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_defaults_and_both_wait_branches_match_real_macro_expansion(self):
        samples = ['seteventmon SPECIES_LATIAS, 50', 'seteventmon SPECIES_LATIOS, 50, ITEM_NONE',
                   'seteventmon SPECIES_LATIAS, 50, ITEM_SOUL_DEW', 'seteventmon SPECIES_LATIOS, 50, ITEM_SOUL_DEW']
        for wait in (0, 1):
            native_forms.StoryProfileTests().check_native_forms(samples,
                forced_waits={'CreateEnemyEventMon': wait}, version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires JP native artifacts')
    def test_two_actual_event_mon_blocks_match_rom_and_keep_real_special_binding(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        blocks = review.label_blocks((ROOT / 'data/maps/SouthernIsland_Interior/scripts.inc').read_text())
        for species in ('Latias', 'Latios'):
            label = 'SouthernIsland_Interior_EventScript_Set' + species + 'BattleVars'
            at = next(iter(symbols[label]))
            result = profile.profile_block(ROOT, blocks[label], version=4, address=at)
            self.assertEqual(result.size, 19)
            self.assertEqual(verifier.assemble_candidate(blocks[label], at),
                             rom[at - 0x08000000:at - 0x08000000 + 19])
            self.assertEqual(result.specials, {'CreateEnemyEventMon': 0})

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_jp_cry_wait_is_c5_and_door_animation_wait_is_ae(self):
        at = 0x08222765
        self.assertEqual(verifier.assemble_candidate('Entry::\nwaitmoncry', at), b'\xC5')
        self.assertEqual(verifier.assemble_candidate('Entry::\nwaitdooranim', at), b'\xAE')


if __name__ == '__main__':
    unittest.main()
