"""Complete Rustboro scenes retain typed gender, flag-call and movement forms."""
import json
from pathlib import Path
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


class RustboroStoryProfileTests(unittest.TestCase):
    def test_new_forms_are_explicitly_v4_and_keep_target_types(self):
        for line, size in (('copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE', 3),
                           ('checkplayergender', 1),
                           ('call_if_unset FLAG_MET_RIVAL_RUSTBORO, RivalMusic', 9)):
            result = profile.profile_block(ROOT, 'Owner::\n' + line + '\nend', {},
                                           version=4, address=0x081DE6F6)
            self.assertEqual(result.size, size + 1)
            self.assertEqual(result.targets, {'RivalMusic': 'script'} if line.startswith('call_if_') else {})
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + line + '\nend', {})

    def test_unmodeled_arguments_and_mixed_movement_still_fail_closed(self):
        for body in ('checkplayergender 0', 'copyobjectxytoperm', 'copyobjectxytoperm 1, 2',
                     'call_if_unset VAR_RESULT, RivalMusic',
                     'call_if_unset FLAG_MET_RIVAL_RUSTBORO, 0x08123456',
                     'walk_fast_right 2\nstep_end', 'walk_fast_up\nend',
                     'walk_faster_right\nstep_end\nstep_end\nstep_end'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + body, {}, version=4, address=0x081DE6F6)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_new_forms_match_actual_jp_macro_expansions(self):
        native_forms.StoryProfileTests().check_native_forms([
            'copyobjectxytoperm LOCALID_RUSTBORO_DEVON_EMPLOYEE', 'checkplayergender',
            'call_if_unset FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_PlayRivalMusic',
            'walk_in_place_down', 'walk_faster_right', 'walk_fast_right', 'walk_fast_up'], version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_every_local_label_and_all_six_battle_frames_are_native_bound(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        source = (ROOT / 'data/maps/RustboroCity/scripts.inc').read_text()
        profiles = profile.profile_owner(ROOT, source, version=4,
                                         address=next(iter(symbols['RustboroCity_MapScripts'])))
        names = list(profiles)
        self.assertEqual(len(names), 164)
        self.assertEqual(sum(p.size for p in profiles.values()), 5880)
        for i, name in enumerate(names):
            next_name = names[i + 1] if i + 1 < len(names) else 'FortreeCity_MapScripts'
            self.assertEqual(profiles[name].size,
                             next(iter(symbols[next_name])) - next(iter(symbols[name])), name)
        battles = [battle for p in profiles.values() for battle in p.trainer_battles]
        self.assertEqual({battle['trainer'] for battle in battles},
                         {'TRAINER_' + rival + '_RUSTBORO_' + starter
                          for rival in ('MAY', 'BRENDAN') for starter in ('TREECKO', 'TORCHIC', 'MUDKIP')})
        self.assertEqual(len(battles), 6)
        for battle in battles:
            self.assertEqual(int(battle['resume'], 16) - int(battle['address'], 16), 10)
            self.assertEqual(battle['defeat_text'], 'RustboroCity_Text_' +
                             ('May' if '_MAY_' in battle['trainer'] else 'Brendan') + 'Defeat')

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_complete_recorded_macro_closure_uses_native_expansion(self):
        manifest = json.loads((ROOT / 'tools/map_semantic_reviews.json').read_text())
        batches = [b for b in manifest['batches'] if 'RustboroCity' in b['maps']
                   and b['review_type'] == 'direct_map_v4']
        self.assertEqual(len(batches), 1, 'complete map must be explicitly reviewed')
        sources = [(ROOT / 'data/maps/RustboroCity/scripts.inc').read_text()]
        for dep in batches[0]['shared_dependencies']:
            blocks = review.label_blocks((ROOT / dep['path']).read_text())
            sources.extend(blocks[name] for name in dep['labels'])
        samples = {line for source in sources for block in review.label_blocks(source).values()
                   if review.text_kind(block) is None for line in review.statements(block)}
        native_forms.StoryProfileTests().check_native_forms(sorted(samples), version=4)


if __name__ == '__main__':
    unittest.main()
