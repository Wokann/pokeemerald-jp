"""Native size and rejection checks for the exact Regi/Sky Pillar audit forms."""
from pathlib import Path
import unittest

import map_review_script_profile as profile
import map_semantic_review as review
import test_map_review_script_profile as native_forms


ROOT = Path(__file__).resolve().parents[1]
ICE_CONDITIONAL = ('#ifdef UBFIX\nsetvar VAR_ICE_STEP_COUNT, 1\n#else\n'
                   'copyvar VAR_ICE_STEP_COUNT, 1, warn=FALSE\n#endif')
MAPS = ('IslandCave', 'AncientTomb', 'Underwater_Route134', 'Underwater_SealedChamber',
        'SealedChamber_OuterRoom', 'SealedChamber_InnerRoom', 'ScorchedSlab',
        'AquaHideout_UnusedRubyMap1', 'AquaHideout_UnusedRubyMap2',
        'AquaHideout_UnusedRubyMap3', 'SkyPillar_Entrance', 'SkyPillar_Outside',
        'SkyPillar_1F', 'SkyPillar_2F', 'SkyPillar_3F', 'SkyPillar_4F',
        'ShoalCave_LowTideIceRoom', 'SkyPillar_5F', 'SkyPillar_Top')


class RegiSkyProfileTests(unittest.TestCase):
    def parse(self, body, version=4):
        return profile.profile_block(ROOT, 'Entry::\n' + body, {},
                                     version=version, address=0x0821BEAB)

    def test_separate_braille_window_forms_preserve_text_kind_and_sizes(self):
        label = 'IslandCave_Braille_RunLapAroundWall'
        opened = self.parse('braillemessage ' + label)
        boxed = self.parse('braillemsgbox ' + label)
        self.assertEqual((opened.size, boxed.size), (5, 7))
        self.assertEqual(opened.texts, {label: 'braille'})
        self.assertEqual(boxed.texts, opened.texts)
        self.assertFalse(opened.targets or opened.specials)
        self.assertEqual(self.parse('closebraillemessage').size, 1)

    def test_braille_rejects_runtime_buffers_offsets_and_wrong_arity(self):
        for op in ('braillemessage', 'braillemsgbox'):
            for operand in ('', 'NULL', 'gStringVar4', '0x0826377A',
                            'IslandCave_Braille_RunLapAroundWall + 1', 'Text, 1'):
                with self.subTest(op=op, operand=operand), self.assertRaises(ValueError):
                    self.parse(op + ' ' + operand)
        with self.assertRaises(ValueError):
            self.parse('closebraillemessage 1')

    def test_music_fade_speed_is_one_literal_byte(self):
        for op in ('fadeoutbgm', 'fadeinbgm'):
            for speed in ('0', '1', '255', '0xFF'):
                with self.subTest(op=op, speed=speed):
                    result = self.parse(op + ' ' + speed)
                    self.assertEqual(result.size, 2)
                    self.assertFalse(result.targets or result.texts or result.specials)
            for speed in ('', '-1', '256', '0x100', 'VAR_0x8004', '1, 2'):
                with self.subTest(op=op, speed=speed), self.assertRaises(ValueError):
                    self.parse(op + ' ' + speed)

    def test_embedded_ice_conditional_keeps_prefix_edges_and_termination(self):
        body = ('call_if_lt VAR_SKY_PILLAR_STATE, 2, CleanFloor\n'
                + ICE_CONDITIONAL + '\nend')
        result = self.parse(body)
        self.assertEqual(result.size, 17)
        self.assertEqual(result.targets, {'CleanFloor': 'script'})
        self.assertFalse(result.texts or result.specials or result.may_fall_through)
        self.assertEqual(self.parse(ICE_CONDITIONAL + '\nend').size, 6)

    def test_ice_conditional_rejects_altered_partial_or_multiple_branches(self):
        changed = (ICE_CONDITIONAL.replace('UBFIX', 'BUGFIX'),
                   ICE_CONDITIONAL.replace('setvar VAR_ICE_STEP_COUNT, 1', 'setvar VAR_ICE_STEP_COUNT, 2'),
                   ICE_CONDITIONAL.replace('copyvar VAR_ICE_STEP_COUNT, 1', 'copyvar VAR_ICE_STEP_COUNT, 2'),
                   ICE_CONDITIONAL.replace('warn=FALSE', 'warn=TRUE'),
                   ICE_CONDITIONAL.replace('#else\n', ''),
                   ICE_CONDITIONAL.replace('#endif', ''),
                   ICE_CONDITIONAL + '\n' + ICE_CONDITIONAL,
                   '#define UNRELATED\n' + ICE_CONDITIONAL)
        for body in changed:
            with self.subTest(body=body), self.assertRaises(ValueError):
                self.parse(body + '\nend')

    def test_new_forms_leave_legacy_v3_rules_closed(self):
        for body in ('braillemessage IslandCave_Braille_RunLapAroundWall',
                     'closebraillemessage', 'fadeoutbgm 0', 'fadeinbgm 1',
                     ICE_CONDITIONAL + '\nend'):
            with self.subTest(body=body), self.assertRaises(ValueError):
                self.parse(body, version=3)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_window_and_music_forms_match_real_macro_assembly(self):
        native_forms.StoryProfileTests().check_native_forms([
            'braillemessage IslandCave_Braille_RunLapAroundWall',
            'closebraillemessage', 'fadeoutbgm 0', 'fadeoutbgm 1',
            'fadeinbgm 0', 'fadeinbgm 1'], version=4)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_embedded_conditional_matches_both_real_cpp_build_branches(self):
        body = ('call_if_lt VAR_SKY_PILLAR_STATE, 2, CleanFloor\n'
                + ICE_CONDITIONAL + '\nend')
        for prefix in ('#undef UBFIX\n', '#undef UBFIX\n#define UBFIX\n'):
            with self.subTest(prefix=prefix):
                native_forms.StoryProfileTests().check_native_forms(
                    [body], version=4, source_prefix=prefix)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_19_owners_close_the_actual_2436_byte_span(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        start = next(iter(symbols['IslandCave_MapScripts']))
        end = next(iter(symbols['MagmaHideout_1F_MapScripts']))
        self.assertEqual(end - start, 2436)
        at = start
        for name in MAPS:
            self.assertEqual(symbols[name + '_MapScripts'], {at}, name)
            parts = profile.profile_owner(ROOT,
                (ROOT / f'data/maps/{name}/scripts.inc').read_text(),
                version=4, address=at)
            for label, part in parts.items():
                self.assertEqual(symbols[label], {at}, label)
                at += part.size
        self.assertEqual(at, end)


if __name__ == '__main__':
    unittest.main()
