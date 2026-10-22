"""The first routes retain native battle frames, shared branches and JP text."""
import copy
import json
from pathlib import Path
import unittest
from unittest.mock import patch
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_forms
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_forms

ROOT = Path(__file__).resolve().parents[1]
FORMS = [
    ('trainerbattle_single TRAINER_CALVIN_1, Intro, Defeat', 14, 'TRAINER_BATTLE_SINGLE'),
    ('trainerbattle_single TRAINER_CALVIN_1, Intro, Defeat, After', 18, 'TRAINER_BATTLE_CONTINUE_SCRIPT'),
    ('trainerbattle_double TRAINER_AMY_AND_LIV_1, Intro, Defeat, Cannot', 18, 'TRAINER_BATTLE_DOUBLE'),
    ('trainerbattle_double TRAINER_AMY_AND_LIV_1, Intro, Defeat, Cannot, After', 22,
     'TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE'),
    ('trainerbattle_rematch TRAINER_CALVIN_1, Intro, Defeat', 14, 'TRAINER_BATTLE_REMATCH'),
    ('trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Intro, Defeat, Cannot', 18,
     'TRAINER_BATTLE_REMATCH_DOUBLE'),
]


class FirstRouteProfileTests(unittest.TestCase):
    def test_battle_forms_keep_each_typed_pointer_and_both_returns(self):
        for source, size, mode in FORMS:
            with self.subTest(source=source):
                p = profile.profile_block(ROOT, 'Owner::\n' + source + '\nend', {},
                                          version=4, address=0x081E6830)
                self.assertEqual(p.size, size + 1)
                battle = p.trainer_battles[0]
                self.assertEqual((battle['mode'], battle['address'], battle['resume']),
                                 (mode, '0x081E6830', f'0x{0x081E6830 + size:08X}'))
                self.assertEqual(p.texts['Intro'], 'string')
                self.assertEqual(p.texts['Defeat'], 'string')
                if 'Cannot' in source:
                    self.assertEqual(p.texts['Cannot'], 'string')
                if 'After' in source:
                    self.assertEqual((battle['post_script'], p.targets['After']), ('After', 'script'))
                with self.assertRaises(ValueError):
                    profile.profile_block(ROOT, 'Owner::\n' + source + '\nend', {})
                with self.assertRaises(ValueError):
                    profile.profile_block(ROOT, 'Owner::\n' + source, {}, version=4, address=0x081E6830)
        for source in ('trainerbattle_single TRAINER_CALVIN_1, Intro, 0x08123456',
                       'trainerbattle_single TRAINER_CALVIN_1, Intro, NULL',
                       'trainerbattle_double TRAINER_AMY_AND_LIV_1, Intro, Defeat',
                       'trainerbattle_single TRAINER_CALVIN_1, Intro, Defeat, After, FALSE'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source + '\nend', {},
                                      version=4, address=0x081E6830)

    def test_registration_records_actual_special_wait_and_standard_slot(self):
        for wait in (0, 1):
            p = profile.profile_block(ROOT, 'Owner::\nregister_matchcall TRAINER_CALVIN_1',
                {'SetMatchCallRegisteredFlag': wait}, version=4, address=0x081E6830)
            self.assertEqual(p.size, 15 + wait)
            self.assertEqual(p.standard_scripts, {8: 'Std_RegisteredInMatchCall'})
            self.assertEqual(p.targets, {'Std_RegisteredInMatchCall': 'script'})
            self.assertEqual(p.specials, {'SetMatchCallRegisteredFlag': wait})
        for source, waits in [('register_matchcall VAR_0x8000', {'SetMatchCallRegisteredFlag': 0}),
                              ('register_matchcall TRAINER_CALVIN_1', {})]:
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source, waits, version=4, address=0x081E6830)

    def test_fallthrough_and_beaten_fallback_cannot_disappear_from_closure(self):
        cases = [('BerryTree_EventScript_ChooseBerryToPlant', 'call Plant',
                  'BerryTree_EventScript_CancelPlanting'),
                 ('ProfBirch_EventScript_RatePokedexOrRegister', 'faceplayer',
                  'ProfBirch_EventScript_AskRatePokedex'),
                 ('EventScript_DoTrainerBattle', 'dotrainerbattle', 'EventScript_EndTrainerBattle')]
        for owner, source, following in cases:
            p = profile.profile_block(ROOT, owner + '::\n' + source, {}, version=4, address=0x081E6830)
            self.assertEqual(p.fallthrough, following)
            self.assertEqual(p.targets[following], 'script')
        p = profile.profile_block(ROOT, 'Owner::\ngotobeatenscript', {}, version=4, address=0x081E6830)
        self.assertTrue(p.trainer_beaten_return)
        self.assertEqual(p.targets, {'EventScript_TryGetTrainerScript': 'script'})
        self.assertFalse(p.trainer_post_return)

    def test_two_consecutive_terminal_bytes_are_not_two_named_movements(self):
        p = profile.profile_block(ROOT, 'Move:\nwalk_up\nstep_end\nstep_end', {},
                                  version=4, address=0x081E65B6)
        self.assertEqual((p.kind, p.size), ('movement', 3))
        for source in ('step_end\nwalk_up\nstep_end', 'walk_up\nstep_end\nstep_end\nstep_end'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Move:\n' + source, {}, version=4, address=0x081E65B6)
        with self.assertRaises(ValueError):
            profile.profile_block(ROOT, 'Move:\nwalk_up\nstep_end\nstep_end', {})

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_new_forms_use_actual_assembler_and_wait_variants(self):
        samples = [s for s, _, _ in FORMS] + [
            'register_matchcall TRAINER_CALVIN_1', 'gotobeatenscript', 'selectapproachingtrainer',
            'lockfortrainer', 'buffertrainerclassname STR_VAR_1, VAR_0x8000',
            'buffertrainername STR_VAR_2, VAR_0x8000', 'buffernumberstring STR_VAR_2, VAR_0x8006',
            'bufferstring STR_VAR_2, Text', 'removeitem VAR_ITEM_ID', 'checkpartymove MOVE_CUT',
            'bufferpartymonnick STR_VAR_1, VAR_RESULT', 'buffermovename STR_VAR_2, MOVE_CUT',
            'msgbox Text, MSGBOX_AUTOCLOSE', 'walk_in_place_fast_left', 'walk_in_place_fast_right',
            'jump_2_down', 'cut_tree']
        native_forms.StoryProfileTests().check_native_forms(samples, version=4)
        native_forms.StoryProfileTests().check_native_forms(['register_matchcall TRAINER_CALVIN_1'],
            {'SetMatchCallRegisteredFlag': 1}, version=4)


@unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
class FirstRouteNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.native = {}
        batch = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches'][-1]
        review._review_batch(ROOT, batch, set(batch['maps']), cls.native)
        cls.battles, cls.parsed = [], []
        for name, following, count, size in [('Route101', 'Route102', 34, 878),
                                             ('Route102', 'Route103', 21, 565),
                                             ('Route103', 'Route104', 55, 1749)]:
            source = (ROOT / f'data/maps/{name}/scripts.inc').read_text()
            start = next(iter(cls.native['symbols'][name + '_MapScripts']))
            parts = profile.profile_owner(ROOT, source, version=4, address=start)
            assert (len(parts), sum(p.size for p in parts.values())) == (count, size)
            cls.parsed.append((name, 'scripts', name + '_MapScripts', start, size, ''))
            cls.battles += [b for p in parts.values() for b in p.trainer_battles]

    def test_all_23_actual_battle_frames_and_parameter_tables_are_exact(self):
        self.assertEqual(len(self.battles), 23)
        errors = []
        review._trainer_native(ROOT, {'trainer_battles': self.battles}, self.native, errors, self.parsed)
        self.assertEqual(errors, [])

    def test_wrong_explicit_callback_and_inline_resume_are_rejected(self):
        for field, value in [('post_script', 'Route103_MapScripts'), ('resume', '0x081E0000')]:
            rows = copy.deepcopy(self.battles)
            battle = next(b for b in rows if 'post_script' in b)
            battle[field] = value
            errors = []
            review._trainer_native(ROOT, {'trainer_battles': rows}, self.native, errors, self.parsed)
            self.assertTrue(any('trainer_' in error for error in errors), errors)

    def test_parameter_type_and_input_owner_are_native_not_guessed(self):
        table = 'sContinueScriptDoubleBattleParams'
        address = next(iter(self.native['symbols'][table]))
        altered = dict(self.native)
        image = bytearray(self.native['rom'])
        image[address - 0x08000000 + 7 * 8 + 4] = 5  # Drop the explicit callback load.
        altered['rom'] = bytes(image)
        errors = []
        review._trainer_parameter_tables(ROOT, altered, {table}, errors)
        self.assertIn('native_trainer_parameter_table_mismatch:' + table, errors)
        altered = dict(self.native, owners=[])
        errors = []
        review._trainer_parameter_tables(ROOT, altered, {table}, errors)
        self.assertIn('native_trainer_parameter_owner_mismatch:' + table, errors)

    def test_every_local_text_and_movement_keeps_its_physical_boundary(self):
        rom = self.native['rom']
        for name, following in [('Route101', 'Route102'), ('Route102', 'Route103'), ('Route103', 'Route104')]:
            blocks = review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())
            start = next(iter(self.native['symbols'][name + '_MapScripts']))
            parts = profile.profile_owner(ROOT, ''.join(blocks.values()), version=4, address=start)
            labels = list(parts)
            for i, label in enumerate(labels):
                begin = next(iter(self.native['symbols'][label]))
                end = next(iter(self.native['symbols'][labels[i + 1] if i + 1 < len(labels) else following + '_MapScripts']))
                self.assertEqual(parts[label].size, end - begin, label)
                if parts[label].kind == 'string':
                    self.assertEqual(review.encoded_text(ROOT, blocks[label], 'string'),
                                     rom[begin - 0x08000000:end - 0x08000000], label)

    def test_generator_preserves_both_extra_terminators_and_rejects_unproved_padding(self):
        try:
            import jp_emit_maps as emitter
        except ModuleNotFoundError:
            from tools import jp_emit_maps as emitter
        source = (ROOT / 'data/maps/Route101/scripts.inc').read_text()
        start = next(iter(self.native['symbols']['Route101_MapScripts']))
        parts = profile.profile_owner(ROOT, source, version=4, address=start)
        labels = {next(iter(self.native['symbols'][name])): name for name, p in parts.items()
                  if p.kind == 'movement'}
        rows = emitter.decode_map_movements('Route101', labels, 0x081E6824)
        for padding in (0x081E65B8, 0x081E65EA):
            owner, actions, end = next(row for row in rows.values() if row[2] == padding + 1)
            self.assertEqual(actions[-2:], ['step_end', 'step_end'])
            self.assertNotIn(padding, labels)
            image = bytearray(emitter.ROM)
            image[padding - 0x08000000] = 0
            with patch.object(emitter, 'ROM', bytes(image)), self.assertRaises(RuntimeError):
                emitter.decode_map_movements('Route101', labels, 0x081E6824)
        with patch.dict(emitter.MAP_MOVEMENT_TERMINATOR_PADDING, {'Route101': {0x081E6823}}):
            with self.assertRaisesRegex(RuntimeError, 'unaccounted'):
                emitter.decode_map_movements('Route101', labels, 0x081E6824)


if __name__ == '__main__':
    unittest.main()
