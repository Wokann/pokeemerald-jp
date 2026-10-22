"""Measured city scene forms do not guess field-effect argument widths."""
import json
from pathlib import Path
import struct
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_forms
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_forms

ROOT = Path(__file__).resolve().parents[1]
SAMPLES = {
    'setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE': 9,
    'dotimebasedevents': 1, 'random 10': 3, 'setfieldeffectargument 0, 1': 4,
    'dofieldeffect FLDEFF_NPCFLY_OUT': 3, 'waitfieldeffect FLDEFF_NPCFLY_OUT': 3,
    'setweather WEATHER_ABNORMAL': 3,
}


class CitySceneEffectTests(unittest.TestCase):
    def test_explicit_v4_widths_leave_old_profile_unchanged(self):
        for source, size in SAMPLES.items():
            p = profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E0171)
            self.assertEqual(p.size, size)
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, {})

    def test_unmodeled_parameters_still_fail_closed(self):
        for source in ('setmetatile 1, 2, 3', 'dotimebasedevents 1', 'random',
                       'setfieldeffectargument 0', 'setfieldeffectargument 0, 1, 2',
                       'dofieldeffect FLDEFF_NPCFLY_OUT, 0', 'waitfieldeffect',
                       'setweather WEATHER_ABNORMAL; end'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E0171)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_all_new_forms_use_real_jp_macro_expansion(self):
        native_forms.StoryProfileTests().check_native_forms(sorted(SAMPLES), version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_entire_lilycove_owner_and_six_inline_battle_frames(self):
        native, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        source = (ROOT / 'data/maps/LilycoveCity/scripts.inc').read_text()
        parts = profile.profile_owner(ROOT, source, version=4,
                                      address=next(iter(native['LilycoveCity_MapScripts'])))
        names = list(parts)
        self.assertEqual(len(names), 122)
        self.assertEqual(sum(p.size for p in parts.values()), 5108)
        for i, name in enumerate(names):
            next_name = names[i + 1] if i + 1 < len(names) else 'MossdeepCity_MapScripts'
            self.assertEqual(parts[name].size, next(iter(native[next_name])) - next(iter(native[name])), name)
        battles = [battle for part in parts.values() for battle in part.trainer_battles]
        self.assertEqual(len(battles), 6)
        self.assertEqual({battle['trainer'] for battle in battles},
                         {'TRAINER_' + rival + '_LILYCOVE_' + starter
                          for rival in ('MAY', 'BRENDAN') for starter in ('TREECKO', 'TORCHIC', 'MUDKIP')})
        for battle in battles:
            self.assertEqual(int(battle['resume'], 16) - int(battle['address'], 16), 10)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_fly_away_effect_30_has_the_real_native_dispatch_chain(self):
        native, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        def address(name):
            self.assertEqual(len(native[name]), 1, name)
            return next(iter(native[name]))
        def word(at):
            return struct.unpack_from('<I', rom, at - 0x08000000)[0]
        effect = address('gFieldEffectScript_NPCUseFly')
        self.assertEqual(word(address('gFieldEffectScriptPointers') + 30 * 4), effect)
        self.assertEqual(rom[effect - 0x08000000], 3)
        self.assertEqual(word(effect + 1) & ~1, address('FldEff_NPCFlyOut') & ~1)
        self.assertEqual(rom[effect - 0x08000000 + 5], 4)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_full_recorded_macro_closure_not_just_local_samples(self):
        batches = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())['batches']
        matches = [b for b in batches if 'LilycoveCity' in b['maps'] and b['review_type'] == 'direct_map_v4']
        self.assertEqual(len(matches), 1)
        sources = [(ROOT / 'data/maps/LilycoveCity/scripts.inc').read_text()]
        for dep in matches[0]['shared_dependencies']:
            blocks = review.label_blocks((ROOT / dep['path']).read_text())
            sources.extend(blocks[name] for name in dep['labels'])
        samples = {line for source in sources for block in review.label_blocks(source).values()
                   if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(samples), 240)
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)


if __name__ == '__main__':
    unittest.main()
