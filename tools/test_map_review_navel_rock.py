"""Bounded Navel Rock encounters, actual macro waits and camera task links."""
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
ENCOUNTERS = [('NavelRock_Top', 'HoOh', 'SPECIES_HO_OH'),
              ('NavelRock_Bottom', 'Lugia', 'SPECIES_LUGIA')]


class NavelRockProfileTests(unittest.TestCase):
    def parse(self, owner, statement, waits=None, version=4):
        return profile.profile_block(ROOT, owner + '::\n' + statement + '\nreturn', waits,
                                     version=version, address=0x0823C0C1)

    def test_exact_two_seventy_level_encounters_use_actual_special_waits(self):
        self.assertEqual(profile.special_waits(ROOT)['CreateEnemyEventMon'], 0)
        self.assertEqual(profile.special_waits(ROOT)['BattleSetup_StartLegendaryBattle'], 1)
        for name, mon, species in ENCOUNTERS:
            owner = name + '_EventScript_' + mon
            for wait in (0, 1):
                result = self.parse(owner, 'seteventmon ' + species + ', 70', {'CreateEnemyEventMon': wait})
                self.assertEqual((result.size, result.specials), (19 + wait, {'CreateEnemyEventMon': wait}))

    def test_unreviewed_owners_species_levels_items_and_legacy_are_rejected(self):
        for name, mon, species in ENCOUNTERS:
            owner = name + '_EventScript_' + mon
            statement = 'seteventmon ' + species + ', 70'
            for body in (statement.replace(', 70', ', 30'), statement + ', ITEM_NONE',
                         statement + ', ITEM_SOUL_DEW', statement.replace(species, 'SPECIES_MEW'),
                         statement.replace(', 70', ', VAR_RESULT')):
                with self.subTest(owner=owner, body=body), self.assertRaises(ValueError):
                    self.parse(owner, body)
            with self.assertRaises(ValueError):
                self.parse('UnreviewedOwner', statement)
            with self.assertRaises(ValueError):
                self.parse(owner, statement, version=3)
            for waits in ({}, {'CreateEnemyEventMon': 2}):
                with self.assertRaises(ValueError):
                    self.parse(owner, statement, waits)
            other = ENCOUNTERS[1 if species == 'SPECIES_HO_OH' else 0][2]
            with self.assertRaises(ValueError):
                self.parse(owner, statement.replace(species, other))

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_actual_default_item_and_both_wait_branches_match_fresh_assembly(self):
        for name, mon, species in ENCOUNTERS:
            statement = 'seteventmon ' + species + ', 70'
            owner = name + '_EventScript_' + mon
            for wait in (0, 1):
                native_forms.StoryProfileTests().check_native_forms([statement],
                    forced_waits={'CreateEnemyEventMon': wait}, version=4,
                    source_owners={statement: owner})

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_whole_encounters_cry_wait_and_real_async_special_contracts(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        waits = profile.special_waits(ROOT)
        for name in ('SpawnCameraObject', 'RemoveCameraObject', 'LoopWingFlapSE', 'ShakeCamera'):
            self.assertEqual(waits[name], 0)
        for name, mon, species in ENCOUNTERS:
            label = name + '_EventScript_' + mon
            block = review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())[label]
            at = next(iter(symbols[label]))
            result = profile.profile_block(ROOT, block, version=4, address=at)
            self.assertEqual(verifier.assemble_candidate(block, at),
                             rom[at - 0x08000000:at - 0x08000000 + result.size])
            self.assertEqual(review.statements(block).count('waitmoncry'), 1)
            self.assertEqual(verifier.assemble_candidate('Entry::\nwaitmoncry', at), b'\xC5')
            self.assertEqual(result.specials['CreateEnemyEventMon'], 0)
            self.assertEqual(result.specials['BattleSetup_StartLegendaryBattle'], 1)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_actual_wing_and_shake_tasks_keep_native_callbacks_and_argument_literals(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes(), include_ram=True)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        nm = subprocess.check_output(['tools/binutils/bin/arm-none-eabi-nm', '-S', '--defined-only',
                                      'pokeemerald_jp.elf'], cwd=ROOT, text=True)
        for function, size, pointers in (
                ('LoopWingFlapSE', 0x18, ('Task_LoopWingFlapSE',)),
                ('Task_LoopWingFlapSE', 0x5C, ('gSpecialVar_0x8004', 'gSpecialVar_0x8005')),
                ('ShakeCamera', 0x5C, ('sub_0813962C', 'gSpecialVar_0x8004', 'gSpecialVar_0x8005',
                                     'gSpecialVar_0x8006', 'gSpecialVar_0x8007'))):
            rows = re.findall(r'(?m)^([0-9a-f]+)\s+([0-9a-f]+)\s+[tT]\s+' + function + '$', nm)
            self.assertEqual(len(rows), 1, function)
            at, length = (int(value, 16) for value in rows[0])
            self.assertEqual(length, size)
            payload = rom[(at & ~1) - 0x08000000:(at & ~1) - 0x08000000 + size]
            for target in pointers:
                values = symbols[target]
                self.assertEqual(len(values), 1, target)
                pointer = next(iter(values))
                if target in ('Task_LoopWingFlapSE', 'sub_0813962C'):
                    pointer |= 1
                self.assertIn(struct.pack('<I', pointer), payload, (function, target))


if __name__ == '__main__':
    unittest.main()
