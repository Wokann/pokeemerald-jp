"""Explicit buried-trainer IDs, cross-floor ownership and Lavaridge services."""
import copy
import json
from pathlib import Path
import struct
import tempfile
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
MAPS = ['LavaridgeTown_HerbShop', 'LavaridgeTown_Gym_1F', 'LavaridgeTown_Gym_B1F',
        'LavaridgeTown_House', 'LavaridgeTown_Mart', 'LavaridgeTown_PokemonCenter_1F',
        'LavaridgeTown_PokemonCenter_2F']
SIZES = [(10, 322, 4), (71, 2803, 39), (12, 147, 0), (5, 127, 2),
         (7, 185, 2), (9, 236, 3), (4, 39, 0)]


def blocks(path):
    return review.label_blocks((ROOT / path).read_text())


def scene(name, suffix):
    return review.statements(blocks(f'data/maps/{name}/scripts.inc')[name + '_' + suffix])


class ExplicitTrainerTests(unittest.TestCase):
    def parse(self, source, version=4):
        return profile.profile_block(ROOT, 'Entry::\n' + source, {}, version=version, address=0x081F4452)

    def test_raw_continue_frame_keeps_nonzero_id_without_an_extra_field(self):
        source = 'trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, Intro, Defeat, After'
        p = self.parse(source + '\nend')
        self.assertEqual(p.size, 19)
        self.assertEqual(p.texts, {'Intro': 'string', 'Defeat': 'string'})
        self.assertEqual(p.targets['After'], 'script')
        self.assertEqual(p.trainer_battles, [dict(owner='Entry', mode='TRAINER_BATTLE_CONTINUE_SCRIPT',
            trainer='TRAINER_COLE', local_id='LOCALID_COLE', intro_text='Intro', defeat_text='Defeat',
            post_script='After', address='0x081F4452', resume='0x081F4464')])
        with self.assertRaises(ValueError):
            self.parse(source + '\nend', version=3)
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms([source], version=4)

    def test_unreviewed_raw_modes_ids_pointers_and_missing_continuations_fail_closed(self):
        source = 'trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, Intro, Defeat, After'
        cases = [source.replace('LOCALID_COLE', value) + '\nend' for value in ('0', '2', 'LOCALID_NONE', 'VAR_RESULT')]
        cases += [source.replace('TRAINER_BATTLE_CONTINUE_SCRIPT', value) + '\nend'
                  for value in ('TRAINER_BATTLE_SINGLE', 'TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC', '2')]
        cases += [source, source.replace('Intro', '0x08123456') + '\nend',
                  source.replace('After', 'NULL') + '\nend', source + ', EXTRA\nend']
        for candidate in cases:
            with self.subTest(candidate=candidate), self.assertRaises(ValueError):
                self.parse(candidate)


class TrainerLocalIdSourceTests(unittest.TestCase):
    def setUp(self):
        temporary = ROOT / '.tmp/agent-work/tests'
        temporary.mkdir(parents=True, exist_ok=True)
        self.tmp = tempfile.TemporaryDirectory(dir=temporary)
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.paths = ['include/constants/event_objects.h', 'include/constants/map_event_ids.h',
                      'data/maps/First/map.json']
        self.put(self.paths[0], '#define LOCALID_NONE 0\n')
        self.put(self.paths[1], '#define LOCALID_TEST 2\n')
        self.metadata = dict(object_events=[dict(script='Other'), dict(local_id='LOCALID_TEST', script='Entry')])
        self.put(self.paths[2], json.dumps(self.metadata))
        self.sources = [dict(path=path, selector='file') for path in self.paths]
        self.frame = dict(owner='Entry', local_id='LOCALID_TEST')

    def put(self, path, text):
        target = self.root / path
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(text)

    def test_generated_define_json_position_and_entry_agree(self):
        self.assertEqual(review._trainer_local_id(self.root, self.frame, self.sources), 2)
        self.assertEqual(review._trainer_local_id(self.root, dict(owner='Entry'), self.sources), 0)

    def test_header_and_map_source_claims_are_both_required(self):
        for missing in self.paths[1:]:
            with self.subTest(missing=missing), self.assertRaises(ValueError):
                review._trainer_local_id(self.root, self.frame, [s for s in self.sources if s['path'] != missing])

    def test_zero_numeric_unknown_and_nonunique_defines_cannot_substitute_for_an_id(self):
        for value in ('LOCALID_NONE', '2', 2, 'LOCALID_UNKNOWN'):
            with self.subTest(value=value), self.assertRaises(ValueError):
                review._trainer_local_id(self.root, dict(self.frame, local_id=value), self.sources)
        for text in ('#define LOCALID_TEST 0\n', '#define LOCALID_TEST 256\n',
                     '#define LOCALID_TEST 2\n#define LOCALID_TEST 2\n'):
            self.put(self.paths[1], text)
            with self.subTest(text=text), self.assertRaises(ValueError):
                review._trainer_local_id(self.root, self.frame, self.sources)

    def test_correct_numeric_id_cannot_hide_wrong_object_order_or_script(self):
        for events in (list(reversed(self.metadata['object_events'])),
                       [dict(script='Other'), dict(local_id='LOCALID_TEST', script='Wrong')]):
            self.put(self.paths[2], json.dumps(dict(object_events=events)))
            with self.subTest(events=events), self.assertRaises(ValueError):
                review._trainer_local_id(self.root, self.frame, self.sources)

    def test_two_bound_map_owners_with_the_same_id_name_are_ambiguous(self):
        path = 'data/maps/Second/map.json'
        self.put(path, json.dumps(self.metadata))
        with self.assertRaises(ValueError):
            review._trainer_local_id(self.root, self.frame, self.sources + [dict(path=path, selector='file')])


class LavaridgeStoryTests(unittest.TestCase):
    def test_sixteen_floor_fallthroughs_are_explicit_and_buried_state_is_not_deleted(self):
        selected = {name: target for name, target in profile.FALLTHROUGHS.items() if name.startswith('LavaridgeTown_Gym_')}
        self.assertEqual(len(selected), 16)
        owners = blocks('data/maps/LavaridgeTown_Gym_1F/scripts.inc') | blocks('data/maps/LavaridgeTown_Gym_B1F/scripts.inc')
        for name, target in selected.items():
            p = profile.profile_block(ROOT, owners[name], {}, version=4, address=0x081F42C7)
            self.assertEqual(p.fallthrough, target)
            self.assertTrue(p.may_fall_through)
        for floor in (MAPS[1], MAPS[2]):
            transition = scene(floor, 'OnTransition')
            self.assertEqual(transition, [f'call {floor}_EventScript_SetTrainerTempVars',
                                          f'call {floor}_EventScript_CheckBuryTrainers', 'end'])

    def test_both_floors_keep_the_real_shared_callback_not_a_guessed_floor_variant(self):
        source = blocks('data/maps/LavaridgeTown_Gym_1F/scripts.inc')
        p = profile.profile_owner(ROOT, ''.join(source.values()), version=4, address=0x081F42C7)
        frames = [frame for part in p.values() for frame in part.trainer_battles if 'local_id' in frame]
        self.assertEqual(len(frames), 8)
        self.assertEqual({frame['post_script'] for frame in frames}, {'LavaridgeTown_Gym_EventScript_CheckTrainerScript'})
        callback = review.statements(source['LavaridgeTown_Gym_EventScript_CheckTrainerScript'])
        self.assertEqual(callback, ['call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars', 'release',
            'special ShouldTryGetTrainerScript', 'goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript', 'end'])

    def test_flannery_victory_keeps_story_flags_and_tm_success_gate(self):
        win = scene(MAPS[1], 'EventScript_FlanneryDefeated')
        for statement in ('setflag FLAG_WHITEOUT_TO_LAVARIDGE', 'setflag FLAG_DEFEATED_LAVARIDGE_GYM',
                          'setflag FLAG_BADGE04_GET', 'setvar VAR_0x8008, 4',
                          'call Common_EventScript_SetGymTrainers', 'setvar VAR_LAVARIDGE_TOWN_STATE, 1',
                          'setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY',
                          'setflag FLAG_ENABLE_FLANNERY_MATCH_CALL'):
            self.assertIn(statement, win)
        for suffix in ('EventScript_GiveOverheat', 'EventScript_GiveOverheat2'):
            give = scene(MAPS[1], suffix)
            self.assertEqual(give[0], 'giveitem ITEM_TM_OVERHEAT')
            self.assertTrue(give[1].startswith('goto_if_eq VAR_RESULT, FALSE, '))
            self.assertGreater(give.index('setflag FLAG_RECEIVED_TM_OVERHEAT'), 1)

    def test_mimic_event_object_calls_the_shared_one_time_tutor(self):
        metadata = json.loads((ROOT / 'data/maps/LavaridgeTown_House/map.json').read_text())
        self.assertEqual(metadata['object_events'][2]['script'], 'LavaridgeTown_House_EventScript_MimicTutor')
        source = blocks('data/scripts/move_tutors.inc')
        tutor = review.statements(source['LavaridgeTown_House_EventScript_MimicTutor'])
        at = tutor.index('call MoveTutor_EventScript_OpenPartyMenu')
        self.assertEqual(tutor[at + 1:at + 3], ['goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_MimicDeclined',
                                                'setflag FLAG_MOVE_TUTOR_TAUGHT_MIMIC'])
        self.assertIn('setvar VAR_0x8005, TUTOR_MOVE_MIMIC', tutor)
        self.assertEqual(review.statements(source['MoveTutor_EventScript_OpenPartyMenu']),
                         ['special ChooseMonForMoveTutor', 'lock', 'faceplayer', 'return'])

    def test_centre_has_its_own_hot_spring_warp_and_the_gym_has_fog(self):
        metadata = json.loads((ROOT / f'data/maps/{MAPS[5]}/map.json').read_text())
        self.assertEqual(metadata['layout'], 'LAYOUT_LAVARIDGE_TOWN_POKEMON_CENTER_1F')
        self.assertEqual(metadata['warp_events'][-1], dict(x=2, y=1, elevation=0,
            dest_map='MAP_LAVARIDGE_TOWN', dest_warp_id='5'))
        for name in MAPS[1:3]:
            data = json.loads((ROOT / f'data/maps/{name}/map.json').read_text())
            self.assertEqual(data['weather'], 'WEATHER_FOG_HORIZONTAL')
            self.assertEqual(data['battle_scene'], 'MAP_BATTLE_SCENE_GYM')


class LavaridgeNativeTests(unittest.TestCase):
    def family(self):
        found = [row for row in json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
                 if set(row['maps']) & set(MAPS)]
        self.assertEqual(len(found), 1)
        self.assertEqual(found[0]['maps'], MAPS)
        return found[0]

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_118_labels_and_50_texts_have_exact_physical_boundaries(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for i, (name, expected) in enumerate(zip(MAPS, SIZES)):
            source = blocks(f'data/maps/{name}/scripts.inc')
            parts = profile.profile_owner(ROOT, ''.join(source.values()), version=4,
                address=next(iter(symbols[name + '_MapScripts'])))
            self.assertEqual((len(parts), sum(p.size for p in parts.values()),
                              sum(p.kind == 'string' for p in parts.values())), expected)
            names = list(parts)
            for j, label in enumerate(names):
                following = names[j + 1] if j + 1 < len(names) else (
                    MAPS[i + 1] if i + 1 < len(MAPS) else 'FallarborTown_Mart') + '_MapScripts'
                start, end = next(iter(symbols[label])), next(iter(symbols[following]))
                self.assertEqual(parts[label].size, end - start, label)
                if parts[label].kind == 'string':
                    self.assertEqual(review.encoded_text(ROOT, source[label], 'string'),
                                     rom[start - 0x08000000:end - 0x08000000], label)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_eight_explicit_native_ids_match_real_json_objects(self):
        source = (ROOT / 'data/maps/LavaridgeTown_Gym_1F/scripts.inc').read_text()
        parts = profile.profile_owner(ROOT, source, version=4, address=0x081F42C7)
        frames = [frame for p in parts.values() for frame in p.trainer_battles if 'local_id' in frame]
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        claims = [dict(path=path, selector='file') for path in ('include/constants/map_event_ids.h',
            'data/maps/LavaridgeTown_Gym_1F/map.json', 'data/maps/LavaridgeTown_Gym_B1F/map.json')]
        self.assertEqual(len(frames), 8)
        for frame in frames:
            trainer = review._literal_define(ROOT, 'include/constants/opponents.h', frame['trainer'])
            local_id = review._trainer_local_id(ROOT, frame, claims)
            self.assertNotEqual(local_id, 0)
            expected = struct.pack('<BBHH', 0x5C, 2, trainer, local_id)
            expected += b''.join(struct.pack('<I', next(iter(symbols[frame[key]])))
                                 for key in ('intro_text', 'defeat_text', 'post_script'))
            at = int(frame['address'], 16) - 0x08000000
            self.assertEqual(rom[at:at + 18], expected, frame['owner'])

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_current_family_has_ten_unique_frames_and_cannot_omit_explicit_ids(self):
        batch = self.family()
        self.assertEqual(len(batch['trainer_battles']), 10)
        self.assertEqual(sum('local_id' in f for f in batch['trainer_battles']), 8)
        self.assertEqual(review._review_batch(ROOT, batch, set(MAPS), {})['status'], 'current')
        bad = copy.deepcopy(batch)
        for frame in bad['trainer_battles']:
            frame.pop('local_id', None)
        with self.assertRaisesRegex(ValueError, 'missing_or_changed_trainer_battle_contract'):
            review.component_contracts(ROOT, bad, MAPS)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_actual_macro_forms_use_real_native_expansion(self):
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in self.family()['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT, dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(sum(line.startswith('trainerbattle ') for line in forms), 8)
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)


if __name__ == '__main__':
    unittest.main()
