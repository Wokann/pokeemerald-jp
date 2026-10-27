"""Real Pyramid parameter headers, item fallthrough and facility selector coverage."""
from pathlib import Path
import struct
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
PLACEHOLDER = 'BattleFacility_TrainerBattle_PlaceholderText'
BATTLE = f'trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, LOCALID_NONE, {PLACEHOLDER}, {PLACEHOLDER}'


class FacilityRoomProfileTests(unittest.TestCase):
    def parse(self, body, owner='Owner', version=4, waits=None):
        return profile.profile_block(ROOT, owner + '::\n' + body, waits,
                                     version=version, address=0x0821E965)

    def test_three_selectors_use_real_special_wait_binding_and_reject_operands(self):
        for op in ('pyramid_setitem', 'pyramid_hideitem', 'pyramid_showhint'):
            for wait in (0, 1):
                result = self.parse(op + '\nreturn', waits={'CallBattlePyramidFunction': wait})
                self.assertEqual(result.size, 9 + wait)
                self.assertEqual(result.specials, {'CallBattlePyramidFunction': wait})
            with self.assertRaises(ValueError):
                self.parse(op + ' 0\nreturn')
            with self.assertRaises(ValueError):
                self.parse(op + '\nreturn', version=3)

    def test_dynamic_finditem_call_tracks_exact_standard_table_slot(self):
        result = self.parse('callstd STD_FIND_ITEM\nreturn')
        self.assertEqual(result.size, 3)
        self.assertEqual(result.standard_scripts, {1: 'Std_FindItem'})
        self.assertEqual(result.targets, {'Std_FindItem': 'script'})
        for arg in ('1', 'STD_OBTAIN_ITEM', 'STD_FIND_ITEM, 0'):
            with self.subTest(arg=arg), self.assertRaises(ValueError):
                self.parse('callstd ' + arg + '\nreturn')

    def test_pyramid_frame_preserves_mode_and_inline_fourteen_byte_resume(self):
        result = self.parse(BATTLE + '\npyramid_showhint\nend')
        self.assertEqual(result.size, 23)
        battle, = result.trainer_battles
        self.assertEqual((battle['mode'], battle['trainer']), ('TRAINER_BATTLE_PYRAMID', 'TRAINER_PHILLIP'))
        self.assertEqual(int(battle['resume'], 16) - int(battle['address'], 16), 14)
        self.assertEqual((battle['intro_text'], battle['defeat_text']), (PLACEHOLDER, PLACEHOLDER))
        self.assertIn('EventScript_TryDoNormalTrainerBattle', result.targets)

    def test_pyramid_placeholders_are_not_generic_ordinary_trainer_arguments(self):
        for statement in (BATTLE.replace('TRAINER_PHILLIP', 'TRAINER_SIDNEY'),
                          BATTLE.replace('LOCALID_NONE', 'LOCALID_PLAYER'),
                          BATTLE.replace(PLACEHOLDER, 'OtherText', 1), BATTLE + ', OtherScript'):
            with self.subTest(statement=statement), self.assertRaises(ValueError):
                self.parse(statement + '\nend')
        with self.assertRaises(ValueError):
            self.parse(BATTLE)
        with self.assertRaises(ValueError):
            self.parse(BATTLE + '\nend', version=3)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_new_forms_match_the_actual_jp_macro_expansions(self):
        native_forms.StoryProfileTests().check_native_forms(
            ['pyramid_setitem', 'pyramid_hideitem', 'pyramid_showhint',
             'callstd STD_FIND_ITEM', BATTLE], version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_actual_item_adjacency_and_dynamic_battle_header_match_rom(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        blocks = review.label_blocks((ROOT / 'data/maps/BattleFrontier_BattlePyramidFloor/scripts.inc').read_text())
        for label, size in (('BattlePyramid_FindItemBall', 29),
                            ('BattlePyramid_FindItemBallEnd', 1), ('BattlePyramid_TrainerBattle', 27)):
            with self.subTest(label=label):
                at = next(iter(symbols[label]))
                result = profile.profile_block(ROOT, blocks[label], version=4, address=at)
                self.assertEqual(result.size, size)
                self.assertEqual(verifier.assemble_candidate(blocks[label], at),
                                 rom[at - 0x08000000:at - 0x08000000 + size])
                if label == 'BattlePyramid_FindItemBall':
                    self.assertEqual(result.fallthrough, 'BattlePyramid_FindItemBallEnd')
                    self.assertEqual(symbols[result.fallthrough], {at + size})
                elif label == 'BattlePyramid_TrainerBattle':
                    trainer = review._literal_define(ROOT, 'include/constants/opponents.h', 'TRAINER_PHILLIP')
                    self.assertEqual(rom[at - 0x08000000 + 1:at - 0x08000000 + 6],
                                     struct.pack('<BHH', 9, trainer, 0))


if __name__ == '__main__':
    unittest.main()
