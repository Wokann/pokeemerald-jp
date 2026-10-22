"""Route125-129 preserve ocean weather gates and the Route128 story scene."""
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
OWNERS = [('Route125', 15, 382, 0), ('Route126', 12, 275, 0),
          ('Route127', 14, 351, 0), ('Route128', 35, 1352, 8), ('Route129', 10, 219, 0)]
MAPS = [row[0] for row in OWNERS]


def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())


def lines(name, entry):
    return review.statements(blocks(name)[name + '_' + entry])


class Route125FamilyTests(unittest.TestCase):
    def family(self):
        batches = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        found = [batch for batch in batches if set(batch['maps']) & set(MAPS)]
        self.assertEqual(len(found), 1, 'one explicitly reviewed adjacent family')
        self.assertEqual(found[0]['maps'], MAPS)
        return found[0]

    def test_ge_call_is_a_typed_eleven_byte_comparison_and_call(self):
        source = 'call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Target'
        p = profile.profile_block(ROOT, 'Entry:\n' + source + '\nend', {},
                                  version=4, address=0x08240000)
        self.assertEqual((p.kind, p.size, p.targets), ('script', 12, {'Target': 'script'}))
        for statement in ('call_if_ge 4, VAR_SOOTOPOLIS_CITY_STATE, Target',
                          'call_if_ge GREATER_THAN_OR_EQUAL, Target',
                          'call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Target, Extra',
                          'call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, NULL'):
            with self.subTest(statement=statement), self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Entry:\n' + statement + '\nend', {},
                                      version=4, address=0x08240000)
        with self.assertRaises(ValueError):
            profile.profile_block(ROOT, 'Entry:\n' + source + '\nend', {})
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms([source], version=4)

    def test_slow_up_is_one_opcode_not_an_argument_accepting_script(self):
        p = profile.profile_block(ROOT, 'Move:\nwalk_slow_up\nstep_end', {},
                                  version=4, address=0x08240000)
        self.assertEqual((p.kind, p.size), ('movement', 2))
        for source in ('walk_slow_up 1\nstep_end', 'walk_slow_up\nend', 'walk_slow_up'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Move:\n' + source, {}, version=4, address=0x08240000)
        with self.assertRaises(ValueError):
            profile.profile_block(ROOT, 'Move:\nwalk_slow_up\nstep_end', {})
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms(['walk_slow_up'], version=4)

    def test_route129_weather_helper_is_called_only_after_the_story_gate(self):
        transition = lines('Route129', 'OnTransition')
        self.assertEqual(transition[1],
            'call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Route129_EventScript_CheckSetAbnormalWeather')
        self.assertEqual(lines('Route129', 'EventScript_CheckSetAbnormalWeather'),
            ['call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather', 'return'])
        self.assertTrue(transition[2].endswith('AbnormalWeather_StartKyogreWeather'))
        self.assertTrue(transition[3].endswith('AbnormalWeather_StartKyogreWeather'))

    def test_weather_start_placement_and_cleanup_keep_distinct_entry_phases(self):
        for name in ('Route125', 'Route127', 'Route129'):
            with self.subTest(name=name):
                load = lines(name, 'OnLoad')
                self.assertEqual(len(load), 3)
                self.assertTrue(all('PlaceTilesRoute' in line for line in load[:-1]))
                self.assertEqual(load[-1], 'end')
                self.assertEqual(lines(name, 'OnFrame'),
                    ['map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1',
                     '.2byte 0'])
                self.assertIn('call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup',
                              lines(name, 'OnTransition'))
        for name in ('Route125', 'Route126', 'Route127', 'Route128'):
            self.assertEqual(lines(name, 'OnTransition')[0],
                'call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather')

    def test_scene_runs_at_state_one_and_finishes_at_state_two(self):
        self.assertEqual(lines('Route128', 'OnFrame'),
            ['map_script_2 VAR_ROUTE128_STATE, 1, Route128_EventScript_KyogreAwakenedScene', '.2byte 0'])
        scene = lines('Route128', 'EventScript_KyogreAwakenedScene')
        self.assertEqual(scene[:2], ['lockall', 'delay 20'])
        self.assertEqual(scene[-4:], ['clearflag FLAG_HIDE_MAP_NAME_POPUP',
                                    'setvar VAR_ROUTE128_STATE, 2', 'releaseall', 'end'])

    def test_parallel_maxie_archie_and_player_movements_wait_before_dialogue(self):
        scene = lines('Route128', 'EventScript_KyogreAwakenedScene')
        start = scene.index('applymovement LOCALID_ROUTE128_ARCHIE, Route128_Movement_ArchieRunLeft')
        self.assertEqual(scene[start:start + 5], [
            'applymovement LOCALID_ROUTE128_ARCHIE, Route128_Movement_ArchieRunLeft',
            'applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft',
            'applymovement LOCALID_ROUTE128_MAXIE, Route128_Movement_MaxieWalkLeft', 'waitmovement 0',
            'msgbox Route128_Text_MaxieThisDefiesBelief, MSGBOX_DEFAULT'])
        start = scene.index('applymovement LOCALID_ROUTE128_MAXIE, Route128_Movement_MaxieExit')
        self.assertEqual(scene[start:start + 5], [
            'applymovement LOCALID_ROUTE128_MAXIE, Route128_Movement_MaxieExit',
            'applymovement LOCALID_ROUTE128_ARCHIE, Route128_Movement_ArchieExit', 'waitmovement 0',
            'removeobject LOCALID_ROUTE128_MAXIE', 'removeobject LOCALID_ROUTE128_ARCHIE'])

    def test_two_flight_effects_keep_distinct_actor_and_polling_order(self):
        scene = lines('Route128', 'EventScript_KyogreAwakenedScene')
        calls = [i for i, line in enumerate(scene) if line == 'dofieldeffect FLDEFF_NPCFLY_OUT']
        self.assertEqual(len(calls), 2)
        for index in calls:
            self.assertEqual(scene[index - 1], 'setfieldeffectargument 0, 1')
        self.assertEqual(scene[calls[0] + 1:calls[0] + 3],
                         ['waitfieldeffect FLDEFF_NPCFLY_OUT', 'addobject LOCALID_ROUTE128_STEVEN'])
        self.assertEqual(scene[calls[1] + 1:calls[1] + 4],
                         ['delay 15', 'removeobject LOCALID_ROUTE128_STEVEN', 'waitfieldeffect FLDEFF_NPCFLY_OUT'])
        start = scene.index('applymovement LOCALID_ROUTE128_STEVEN, Route128_Movement_StevenWalkUp')
        self.assertEqual(scene[start + 1:start + 3],
                         ['applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp', 'waitmovement 0'])

    def test_archie_backstep_keeps_facing_lock_and_unused_motion_bytes(self):
        self.assertEqual(lines('Route128', 'Movement_ArchieBackUp'),
                         ['lock_facing_direction', 'walk_slow_up', 'delay_16', 'unlock_facing_direction', 'step_end'])
        owner = blocks('Route128')
        self.assertIn('Route128_Movement_Unused1', owner)
        self.assertIn('Route128_Movement_Unused2', owner)
        movements = [block for label, block in owner.items() if label.startswith('Route128_Movement_')]
        self.assertEqual(len(movements), 12)
        for block in movements:
            self.assertEqual(profile.profile_block(ROOT, block, {}, version=4, address=0x08240000).kind, 'movement')

    def test_json_preserves_real_objects_and_surface_dive_interfaces(self):
        expected = [(10, 1, 0, 4), (9, 0, 0, 0), (11, 0, 0, 5), (10, 0, 0, 3), (5, 0, 0, 0)]
        for name, counts in zip(MAPS, expected):
            metadata = json.loads((ROOT / f'data/maps/{name}/map.json').read_text())
            self.assertEqual(tuple(len(metadata[field]) for field in
                ('object_events', 'warp_events', 'coord_events', 'bg_events')), counts)
            self.assertEqual(metadata['map_type'], 'MAP_TYPE_OCEAN_ROUTE')
            self.assertTrue(metadata['allow_cycling'] and metadata['allow_running'])
            self.assertFalse(metadata['allow_escaping'] or metadata['requires_flash'])
            self.assertTrue(any(c['direction'] == 'dive' for c in metadata['connections']))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_86_labels_and_eight_jp_strings_keep_exact_native_boundaries(self):
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

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_42_trainer_frames_and_entire_record_are_current(self):
        batch = self.family()
        self.assertEqual(len(batch['trainer_battles']), 42)
        self.assertEqual(batch['dynamic_layouts'], [])
        self.assertEqual(review._review_batch(ROOT, batch, set(MAPS), {})['status'], 'current')

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_ge_call_uses_immediate_u16_and_ge_condition_row(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        helper = next(iter(symbols['Route129_EventScript_CheckSetAbnormalWeather']))
        self.assertEqual(rom[0x1EF2E6:0x1EF2F1], bytes.fromhex('21 5e 40 04 00 07 04') + helper.to_bytes(4, 'little'))
        table = next(iter(symbols['sScriptConditionTable'])) - 0x08000000
        self.assertEqual(rom[table + 12:table + 15], b'\x00\x01\x01')

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_every_distinct_family_form_matches_real_native_expansion(self):
        batch = self.family()
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in batch['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT, dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertIn('call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Route129_EventScript_CheckSetAbnormalWeather', forms)
        self.assertIn('walk_slow_up', forms)
        self.assertEqual(len(forms), 582)
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)


if __name__ == '__main__':
    unittest.main()
