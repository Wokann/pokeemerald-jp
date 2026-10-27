"""Native virtual-audience shape checks for the ordered Contest Hall review."""
from pathlib import Path
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier

ROOT = Path(__file__).resolve().parents[1]
BASE = 'createvobject OBJ_EVENT_GFX_NINJA_BOY, 20, 3, 2'


class VirtualAudienceProfileTests(unittest.TestCase):
    def parse(self, statement, version=4):
        return profile.profile_block(ROOT, 'Owner::\n' + statement + '\nreturn', {},
                                     version=version, address=0x0821D62A)

    def test_default_and_explicit_fields_have_the_same_nine_byte_shape(self):
        for suffix in ('', ', 3', ', 3, DIR_SOUTH'):
            with self.subTest(suffix=suffix):
                result = self.parse(BASE + suffix)
                self.assertEqual((result.kind, result.size), ('script', 10))
                self.assertFalse(result.targets or result.texts or result.specials)

    def test_coordinates_may_use_the_variables_read_by_the_native_handler(self):
        result = self.parse('createvobject OBJ_EVENT_GFX_SCIENTIST_1, 255, VAR_TEMP_1, 65535, 255, DIR_WEST')
        self.assertEqual(result.size, 10)

    def test_invalid_widths_counts_direction_and_expressions_are_rejected(self):
        invalid = (BASE + ', 3, DIR_SOUTH, 0', BASE.rsplit(',', 1)[0],
                   'createvobject UnknownGfx, 20, 3, 2',
                   BASE.replace(', 20,', ', 256,'), BASE.replace(', 20,', ', -1,'),
                   BASE.replace(', 3,', ', 65536,'), BASE + ', 256',
                   BASE + ', 3, UNKNOWN_DIRECTION', BASE + ', 3, DIR_SOUTH + 1',
                   BASE.replace(', 3,', ', (3+1),'))
        for text in invalid:
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text)

    def test_legacy_v3_stays_closed_to_virtual_objects(self):
        with self.assertRaises(ValueError):
            self.parse(BASE, version=3)

    def test_greater_than_call_has_real_compare_width_and_a_script_edge(self):
        result = self.parse('call_if_gt VAR_TEMP_0, 0, Target')
        self.assertEqual(result.size, 12)
        self.assertEqual(result.targets, {'Target': 'script'})
        for text in ('call_if_gt VAR_TEMP_0, 0, NULL', 'call_if_gt VAR_TEMP_0, Target',
                     'call_if_gt 1, 0, Target'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text)

    def test_contest_wait_commands_turns_and_heart_are_strictly_typed(self):
        for op in ('startcontest', 'showcontestresults'):
            self.assertEqual(self.parse(op).size, 2)
            with self.assertRaises(ValueError):
                self.parse(op + ' 0')
            with self.assertRaises(ValueError):
                self.parse(op, version=3)
        self.assertEqual(self.parse('turnvobject 255, DIR_NORTH').size, 4)
        for text in ('turnvobject 256, DIR_NORTH', 'turnvobject -1, DIR_NORTH',
                     'turnvobject 1', 'turnvobject 1, BAD_DIRECTION'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text)
        result = profile.profile_block(ROOT, 'Movement::\nemote_heart\nstep_end', {},
                                       version=4, address=0x0821D62A)
        self.assertEqual((result.kind, result.size), ('movement', 2))
        with self.assertRaises(ValueError):
            profile.profile_block(ROOT, 'Movement::\nemote_heart\nstep_end', {},
                                  version=3, address=0x0821D62A)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_real_macro_defaults_and_explicit_fields_have_measured_sizes(self):
        native_forms.StoryProfileTests().check_native_forms(
            [BASE, BASE + ', 3', BASE + ', 3, DIR_SOUTH'], version=4)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_remaining_contest_forms_match_the_actual_macros(self):
        native_forms.StoryProfileTests().check_native_forms(
            ['call_if_gt VAR_TEMP_0, 0, Target', 'startcontest', 'showcontestresults',
             'turnvobject 1, DIR_WEST', 'emote_heart'], version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_actual_audience_turn_sequence_and_heart_match_rom(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        blocks = review.label_blocks((ROOT / 'data/scripts/contest_hall.inc').read_text())
        label = 'ContestHall_EventScript_VObjectAudienceLookAround'
        rows = review.statements(blocks[label])
        self.assertEqual(sum(row.startswith('turnvobject ') for row in rows), 62)
        for label, size in ((label, 199), ('ContestHall_Movement_Heart', 2)):
            with self.subTest(label=label):
                at = next(iter(symbols[label]))
                result = profile.profile_block(ROOT, blocks[label], {}, version=4, address=at)
                self.assertEqual(result.size, size)
                self.assertEqual(verifier.assemble_candidate(blocks[label], at),
                                 rom[at - 0x08000000:at - 0x08000000 + size])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_five_audience_blocks_match_native_labels_and_rom(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        blocks = review.label_blocks((ROOT / 'data/maps/ContestHall/scripts.inc').read_text())
        for rank, count in (('Normal', 2), ('Super', 10), ('Hyper', 19), ('Master', 27), ('Wireless', 21)):
            with self.subTest(rank=rank):
                label = 'ContestHall_EventScript_Create' + rank + 'ContestAudience'
                body = blocks[label]
                at = next(iter(symbols[label]))
                result = profile.profile_block(ROOT, body, {}, version=4, address=at)
                self.assertEqual(result.size, count * 9 + 1)
                rows = review.statements(body)
                self.assertEqual(sum(row.startswith('createvobject ') for row in rows), count)
                self.assertEqual(rows[-1], 'return')
                self.assertEqual(verifier.assemble_candidate(body, at),
                                 rom[at - 0x08000000:at - 0x08000000 + result.size])


if __name__ == '__main__':
    unittest.main()
