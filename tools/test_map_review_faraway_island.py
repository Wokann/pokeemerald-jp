"""Exact Mew event parameters, native script bytes and Cut's real C entry."""
from pathlib import Path
import re
import struct
import subprocess
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
MEW = 'FarawayIsland_Interior_EventScript_Mew'


class FarawayIslandProfileTests(unittest.TestCase):
    def parse(self, statement='seteventmon SPECIES_MEW, 30', *, owner=MEW, waits=None, version=4):
        return profile.profile_block(ROOT, owner + '::\n' + statement + '\nreturn', waits,
                                     version=version, address=0x0823B35C)

    def test_actual_mew_form_binds_the_real_event_mon_special_and_wait(self):
        self.assertEqual(profile.special_waits(ROOT)['CreateEnemyEventMon'], 0)
        self.assertEqual(profile.special_waits(ROOT)['BattleSetup_StartLegendaryBattle'], 1)
        for wait in (0, 1):
            result = self.parse(waits={'CreateEnemyEventMon': wait})
            self.assertEqual((result.size, result.specials), (19 + wait, {'CreateEnemyEventMon': wait}))

    def test_other_owners_levels_items_and_legacy_version_stay_closed(self):
        with self.assertRaises(ValueError):
            self.parse(owner='UnreviewedOwner')
        for statement in ('seteventmon SPECIES_MEW, 50', 'seteventmon SPECIES_MEW, 30, ITEM_NONE',
                          'seteventmon SPECIES_MEW, 30, ITEM_SOUL_DEW',
                          'seteventmon SPECIES_MEW, VAR_RESULT', 'seteventmon SPECIES_DEOXYS, 30'):
            with self.subTest(statement=statement), self.assertRaises(ValueError):
                self.parse(statement)
        with self.assertRaises(ValueError):
            self.parse(version=3)
        for waits in ({}, {'CreateEnemyEventMon': 2}):
            with self.assertRaises(ValueError):
                self.parse(waits=waits)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_real_macro_default_item_and_both_wait_branches_match_fresh_assembly(self):
        statement = 'seteventmon SPECIES_MEW, 30'
        for wait in (0, 1):
            native_forms.StoryProfileTests().check_native_forms(
                [statement], forced_waits={'CreateEnemyEventMon': wait}, version=4,
                source_owners={statement: MEW})

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_whole_mew_encounter_and_actual_cry_wait_match_native_jp(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        block = review.label_blocks((ROOT / 'data/maps/FarawayIsland_Interior/scripts.inc').read_text())[MEW]
        at = next(iter(symbols[MEW]))
        result = profile.profile_block(ROOT, block, version=4, address=at)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(verifier.assemble_candidate(block, at), rom[at - 0x08000000:at - 0x08000000 + result.size])
        self.assertEqual(result.specials['CreateEnemyEventMon'], 0)
        self.assertEqual(result.specials['BattleSetup_StartLegendaryBattle'], 1)
        self.assertEqual(verifier.assemble_candidate('Entry::\nwaitmoncry', at), b'\xC5')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_cut_cleanup_points_to_the_actual_local_hide_mew_script(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        label = 'FarawayIsland_Interior_EventScript_HideMewWhenGrassCut'
        self.assertEqual(len(symbols[label]), 1)
        pointer = next(iter(symbols[label]))
        nm = subprocess.check_output(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only',
                                      'pokeemerald_jp.elf'], cwd=ROOT, text=True)
        rows = re.findall(r'(?m)^([0-9a-f]+)\s+([0-9a-f]+)\s+[tT]\s+CutGrassSpriteCallbackEnd$', nm)
        self.assertEqual(len(rows), 1)
        address, size = (int(value, 16) for value in rows[0])
        offset = (address & ~1) - 0x08000000
        self.assertIn(struct.pack('<I', pointer), (ROOT / 'baserom_jp.gba').read_bytes()[offset:offset + size])


if __name__ == '__main__':
    unittest.main()
