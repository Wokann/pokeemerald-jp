"""Actual native affine movement coverage for Marine and Terra cave review."""
from pathlib import Path
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms
import verify_generated_map_scripts as verifier


ROOT = Path(__file__).resolve().parents[1]
APPROACH = ('init_affine_anim\nwalk_down_start_affine\ndelay_16\ndelay_16\n'
            'walk_down_affine\ndelay_16\ndelay_16\nwalk_down_affine\nstep_end')


class LateDungeonAffineProfileTests(unittest.TestCase):
    def parse(self, body, version=4):
        return profile.profile_block(ROOT, 'Movement::\n' + body, {},
                                     version=version, address=0x0821D000)

    def test_real_approach_is_one_nine_byte_terminated_movement(self):
        result = self.parse(APPROACH)
        self.assertEqual((result.kind, result.size), ('movement', 9))
        self.assertFalse(result.targets or result.texts or result.specials)

    def test_affine_forms_reject_missing_end_mixed_scripts_or_operands(self):
        for text in ('walk_down_start_affine', 'walk_down_affine',
                     'walk_down_start_affine\nend', 'walk_down_affine 1\nstep_end',
                     'walk_down_start_affine\nsetvar VAR_TEMP_1, 0\nstep_end'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                self.parse(text)

    def test_legacy_v3_does_not_accept_the_new_affine_forms(self):
        for op in ('walk_down_start_affine', 'walk_down_affine'):
            with self.subTest(op=op), self.assertRaises(ValueError):
                self.parse(op + '\nstep_end', version=3)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_affine_actions_match_real_macro_assembler_sizes(self):
        native_forms.StoryProfileTests().check_native_forms(
            ['walk_down_start_affine', 'walk_down_affine'], version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_both_actual_approaches_preserve_native_symbols_and_rom_bytes(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, species, following in (
                ('MarineCave_End', 'Kyogre', 'TerraCave_Entrance'),
                ('TerraCave_End', 'Groudon', 'AlteringCave')):
            with self.subTest(map=name):
                blocks = review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())
                label = name + '_Movement_' + species + 'Approach'
                self.assertEqual(review.statements(blocks[label]), APPROACH.splitlines())
                at = next(iter(symbols[label]))
                result = profile.profile_block(ROOT, blocks[label], {}, version=4, address=at)
                self.assertEqual((result.kind, result.size), ('movement', 9))
                self.assertEqual(list(blocks)[-1], label)
                end = next(iter(symbols[following + '_MapScripts']))
                self.assertEqual(end - at, 9)
                actual = verifier.assemble_candidate(blocks[label], at)
                self.assertEqual(actual, rom[at - 0x08000000:end - 0x08000000])


if __name__ == '__main__':
    unittest.main()
