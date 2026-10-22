"""Adjacent routes preserve native scenes, callbacks and reward failure paths."""
import copy
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
OWNERS = [('Route110', 160, 4868, 43), ('Route111', 112, 3391, 30),
          ('Route112', 23, 711, 8), ('Route113', 32, 801, 6), ('Route114', 35, 912, 6)]
MAPS = [row[0] for row in OWNERS]


def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())


def lines(name, entry):
    return review.statements(blocks(name)[name + '_' + entry])


class Route110FamilyTests(unittest.TestCase):
    def family(self):
        batches = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        matches = [batch for batch in batches if set(batch['maps']) & set(MAPS)]
        self.assertEqual(len(matches), 1, 'one cohesive family, not partial approvals')
        self.assertEqual(matches[0]['maps'], MAPS)
        return matches[0]

    def test_new_comparisons_and_trainer_flag_forms_keep_typed_targets(self):
        for source, size in [('goto_if_lt VAR_TEMP_0, 19, Target', 11),
                             ('goto_if_gt VAR_TEMP_1, 107, Target', 11),
                             ('goto_if_defeated TRAINER_VICTOR, Target', 9),
                             ('goto_if_not_defeated TRAINER_VICKY, Target', 9),
                             ('cleartrainerflag TRAINER_VICTOR', 3),
                             ('setorcopyvar VAR_0x8004, VAR_RESULT', 5),
                             ('setorcopyvar VAR_0x8004, 1', 5)]:
            p = profile.profile_block(ROOT, 'Owner::\n' + source + '\nend', {},
                                      version=4, address=0x081EA28C)
            self.assertEqual(p.size, size + 1)
            self.assertEqual(p.targets, {'Target': 'script'} if 'Target' in source else {})
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source + '\nend', {})
        for source in ('goto_if_lt VAR_TEMP_0, 19', 'goto_if_gt VAR_TEMP_1, 107, 0x08123456',
                       'goto_if_defeated VAR_0x8000, Target', 'goto_if_not_defeated TRAINER_VICKY',
                       'cleartrainerflag VAR_0x8000', 'cleartrainerflag TRAINER_VICTOR, 1',
                       'setorcopyvar VAR_0x8004', 'setorcopyvar VAR_0x8004, 1, 2'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source + '\nend', {},
                                      version=4, address=0x081EA28C)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_added_forms_use_real_assembler_expansion(self):
        native_forms.StoryProfileTests().check_native_forms([
            'goto_if_lt VAR_TEMP_0, 19, Target', 'goto_if_gt VAR_TEMP_1, 107, Target',
            'goto_if_defeated TRAINER_VICTOR, Target', 'goto_if_not_defeated TRAINER_VICKY, Target',
            'cleartrainerflag TRAINER_VICTOR', 'lock_anim', 'walk_in_place_left',
            'walk_in_place_up', 'rock_smash_break', 'setorcopyvar VAR_0x8004, VAR_RESULT',
            'setorcopyvar VAR_0x8004, 1'], version=4)

    def test_secret_base_and_weather_payloads_are_not_script_pointers(self):
        base = dict(type='secret_base', secret_base_id='SECRET_BASE_TREE3_1')
        weather = dict(type='weather', weather='COORD_EVENT_WEATHER_VOLCANIC_ASH')
        self.assertEqual(review.story_event_target(base, 'bg_events', version=4),
                         'SecretBase_EventScript_CheckEntrance')
        self.assertIsNone(review.story_event_target(weather, 'coord_events', version=4))
        for event, field in [(base, 'bg_events'), (weather, 'coord_events')]:
            with self.assertRaises(ValueError):
                review.story_event_target(event, field)
            with self.assertRaises(ValueError):
                review.story_event_target(dict(event, script='Injected'), field, version=4)
        for event, field in [(dict(base, secret_base_id='0x10'), 'bg_events'),
                             (dict(weather, weather='WEATHER_VOLCANIC_ASH'), 'coord_events'),
                             (dict(weather, var='VAR_TEMP_0'), 'coord_events'),
                             (dict(type='unknown'), 'bg_events'), (dict(type='unknown'), 'coord_events')]:
            with self.assertRaises(ValueError):
                review.story_event_target(event, field, version=4)

    def test_sandstorm_has_two_explicit_fallthroughs_and_keeps_2000(self):
        source = blocks('Route111')
        for owner, target in [('CheckSetSandstorm', 'SetSandstorm'),
                              ('SetSandstorm', 'EndCheckSetSandstorm')]:
            name, following = ('Route111_EventScript_' + n for n in (owner, target))
            p = profile.profile_block(ROOT, source[name], {}, version=4, address=0x081EA28C)
            self.assertEqual((p.fallthrough, p.targets[following]), (following, 'script'))
        self.assertIn('goto_if_gt VAR_TEMP_0, 2000, Route111_EventScript_EndCheckSetSandstorm',
                      review.statements(source['Route111_EventScript_CheckSetSandstorm']))
        self.assertEqual(review.statements(source['Route111_EventScript_SetSandstorm']),
                         ['setweather WEATHER_SANDSTORM'])

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_shared_text_stops_before_the_declared_sibling_include(self):
        dep = dict(path='data/scripts/secret_base.inc', kind='string',
                   entry='SecretBase_Text_DiscoveredSmallEntrance',
                   end_before_includes=['data/text/secret_base_trainers.inc'])
        self.assertEqual(review.shared_include_entry(ROOT, dep), 'SecretBase_Text_Trainer0Intro')
        text = review.shared_script_blocks(ROOT, dep)[dep['entry']]
        self.assertEqual(review.text_kind(text), 'string')
        self.assertEqual(review.encoded_text(ROOT, text, 'string')[-1], 255)
        for boundaries in (['data/text/berries.inc'], ['data/text/secret_base_trainers.inc'] * 2):
            with self.assertRaises(ValueError):
                review.shared_script_blocks(ROOT, dict(dep, end_before_includes=boundaries))

    def test_winstrates_keep_four_battles_and_reset_only_first_three_flags(self):
        sequence = lines('Route111', 'EventScript_BattleWinstrates')
        battles = [line for line in sequence if line.startswith('trainerbattle_no_intro ')]
        self.assertEqual(battles, [f'trainerbattle_no_intro TRAINER_{name.upper()}, Route111_Text_{name}Defeat'
                                  for name in ('Victor', 'Victoria', 'Vivi', 'Vicky')])
        self.assertFalse(any(line.startswith(('giveitem ', 'special Heal')) for line in sequence))
        reset = lines('Route111', 'EventScript_SetWinstratesNotDefeated')
        self.assertEqual([line for line in reset if line.startswith('cleartrainerflag ')],
                         ['cleartrainerflag TRAINER_' + name for name in ('VICTOR', 'VICTORIA', 'VIVI')])
        self.assertIn('goto_if_not_defeated TRAINER_VICKY, Route111_EventScript_SetWinstratesNotDefeated',
                      lines('Route111', 'OnTransition'))

    def test_cycling_gates_score_and_record_boolean_are_not_conflated(self):
        self.assertEqual(lines('Route110', 'EventScript_BeginCylcingRoadChallenge'),
                         ['special Special_BeginCyclingRoadChallenge', 'setvar VAR_CYCLING_CHALLENGE_STATE, 2', 'return'])
        sign = lines('Route110', 'EventScript_CyclingRoadResultsSign')
        self.assertEqual(sign[1:3], ['specialvar VAR_RESULT, GetRecordedCyclingRoadResults',
                         'goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet'])
        self.assertIn('goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike',
                      lines('Route110', 'EventScript_ChallengeGuy'))
        reactions = lines('Route110', 'EventScript_CyclingChallengeResults')
        cases = [line for line in reactions if line.startswith('case ')]
        self.assertEqual([int(line.split(',')[0][5:]) for line in cases], list(range(10, -1, -1)))
        self.assertEqual(lines('Route110', 'EventScript_EndChallenge'),
                         ['setvar VAR_CYCLING_CHALLENGE_STATE, 3', 'savebgm MUS_DUMMY', 'fadedefaultbgm', 'return'])

    def test_itemfinder_and_birch_registration_keep_actual_scene_order(self):
        self.assertEqual(lines('Route110', 'EventScript_GiveItemfinder'), ['giveitem ITEM_ITEMFINDER', 'return'])
        scene = lines('Route110', 'EventScript_BirchScene')
        self.assertLess(scene.index('waitfanfare'), scene.index('setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL'))
        self.assertLess(scene.index('removeobject LOCALID_ROUTE110_BIRCH'), scene.index('setvar VAR_REGISTER_BIRCH_STATE, 2'))
        for i in range(1, 4):
            self.assertIn(f'call_if_eq VAR_0x8008, {i}, Route110_EventScript_RivalExit{i}',
                          lines('Route110', 'EventScript_RivalExit'))

    def test_daily_berries_and_roar_do_not_advance_flags_when_bag_is_full(self):
        for name, entry, flag in [('Route111', 'Girl', 'FLAG_DAILY_ROUTE_111_RECEIVED_BERRY'),
                                  ('Route114', 'Man', 'FLAG_DAILY_ROUTE_114_RECEIVED_BERRY'),
                                  ('Route114', 'RoarGentleman', 'FLAG_RECEIVED_TM_ROAR')]:
            sequence = lines(name, 'EventScript_' + entry)
            self.assertLess(sequence.index('goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull'),
                            sequence.index('setflag ' + flag))
        berry = lines('Route114', 'EventScript_Man')
        start = berry.index('random NUM_ROUTE_114_MAN_BERRIES')
        self.assertEqual(berry[start:start + 4], ['random NUM_ROUTE_114_MAN_BERRIES',
            'addvar VAR_RESULT, NUM_ROUTE_114_MAN_BERRIES_SKIPPED', 'addvar VAR_RESULT, FIRST_BERRY_INDEX',
            'giveitem VAR_RESULT'])

    def test_ash_weather_and_per_step_callback_are_separate_interfaces(self):
        self.assertEqual(lines('Route113', 'OnResume'), ['setstepcallback STEP_CB_ASH', 'end'])
        weather = lines('Route113', 'EventScript_CheckSetAshWeather')
        self.assertEqual(weather[1:3], ['goto_if_lt VAR_TEMP_0, 19, Route113_EventScript_DontSetAshWeather',
                                      'goto_if_gt VAR_TEMP_0, 84, Route113_EventScript_DontSetAshWeather'])
        metadata = json.loads((ROOT / 'data/maps/Route113/map.json').read_text())
        self.assertEqual(len(metadata['coord_events']), 19)
        self.assertTrue(all(event['type'] == 'weather' for event in metadata['coord_events']))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_five_owners_and_93_local_strings_have_exact_native_boundaries(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, count, size, texts in OWNERS:
            source = blocks(name)
            start = next(iter(symbols[name + '_MapScripts']))
            parts = profile.profile_owner(ROOT, ''.join(source.values()), version=4, address=start)
            self.assertEqual((len(parts), sum(p.size for p in parts.values())), (count, size))
            self.assertEqual(sum(p.kind == 'string' for p in parts.values()), texts)
            labels = list(parts)
            for i, label in enumerate(labels):
                begin = next(iter(symbols[label]))
                following = labels[i + 1] if i + 1 < len(labels) else f'Route{int(name[5:]) + 1}_MapScripts'
                end = next(iter(symbols[following]))
                self.assertEqual(parts[label].size, end - begin, label)
                if parts[label].kind == 'string':
                    self.assertEqual(review.encoded_text(ROOT, source[label], 'string'),
                                     rom[begin - 0x08000000:end - 0x08000000], label)
        pointer = next(iter(symbols['sPerStepCallbacks'])) + 4  # STEP_CB_ASH = 1
        target = struct.unpack_from('<I', rom, pointer - 0x08000000)[0]
        self.assertEqual(target & ~1, next(iter(symbols['AshGrassPerStepCallback'])) & ~1)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_89_battle_frames_and_alternate_layout_are_recorded_and_current(self):
        batch = self.family()
        self.assertEqual(len(batch['trainer_battles']), 89)
        self.assertEqual(batch['dynamic_layouts'], ['LAYOUT_ROUTE111_NO_MIRAGE_TOWER'])
        result = review._review_batch(ROOT, batch, set(MAPS), {})
        self.assertEqual(result['status'], 'current', result)

    def test_tagged_event_dispatch_context_and_shared_root_are_required(self):
        batch = self.family()
        for path in ('src/secret_base.c', 'src/coord_event_weather.c'):
            altered = dict(batch, sources=[s for s in batch['sources'] if s['path'] != path])
            with self.assertRaisesRegex(ValueError, 'missing_story_event_dispatch_context'):
                review.component_contracts(ROOT, altered, MAPS)
        altered = dict(batch, shared_dependencies=[d for d in batch['shared_dependencies']
                                                   if d['entry'] != 'SecretBase_EventScript_CheckEntrance'])
        with self.assertRaisesRegex(ValueError, 'missing_shared_call_evidence:SecretBase_EventScript_CheckEntrance'):
            review.component_contracts(ROOT, altered, MAPS)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_a_named_but_nonadjacent_local_fallthrough_is_rejected(self):
        batch, native, errors = self.family(), {}, []
        review._native_batch(ROOT, batch, MAPS, errors, native, 0)
        self.assertEqual(errors, [])
        altered = dict(native, symbols=copy.deepcopy(native['symbols']))
        label = 'Route111_EventScript_SetSandstorm'
        altered['symbols'][label] = {value + 1 for value in altered['symbols'][label]}
        errors = []
        review._native_batch(ROOT, batch, MAPS, errors, altered, 0)
        self.assertIn('native_script_fallthrough_mismatch:Route111_EventScript_CheckSetSandstorm', errors)
        altered = dict(native, symbols=copy.deepcopy(native['symbols']))
        label = 'SecretBase_Text_Trainer0Intro'  # Local ELF label need not be in the linker map.
        altered['symbols'][label] = {value + 1 for value in altered['symbols'][label]}
        errors = []
        review._native_batch(ROOT, batch, MAPS, errors, altered, 0)
        self.assertIn('native_shared_include_boundary_mismatch:SecretBase_Text_DiscoveredSmallEntrance', errors)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_every_distinct_full_family_form_matches_real_native_expansion(self):
        batch = self.family()
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in batch['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT, dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(forms), 1121)
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)


if __name__ == '__main__':
    unittest.main()
