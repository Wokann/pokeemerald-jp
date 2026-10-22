"""Route120-124 retain shared text owners, bridge actors and empty-map data."""
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
OWNERS = [('Route120', 66, 2165, 12), ('Route121', 29, 764, 4),
          ('Route122', 1, 1, 0), ('Route123', 36, 969, 6), ('Route124', 19, 477, 1)]
MAPS = [row[0] for row in OWNERS]


def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())


def lines(name, entry):
    return review.statements(blocks(name)[name + '_' + entry])


class Route120FamilyTests(unittest.TestCase):
    def family(self):
        batches = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        found = [batch for batch in batches if set(batch['maps']) & set(MAPS)]
        self.assertEqual(len(found), 1, 'one explicitly reviewed adjacent family')
        self.assertEqual(found[0]['maps'], MAPS)
        return found[0]

    def test_normal_right_walk_in_place_is_one_native_movement_opcode(self):
        p = profile.profile_block(ROOT, 'Move:\nwalk_in_place_right\nstep_end', {},
                                  version=4, address=0x08240000)
        self.assertEqual((p.kind, p.size), ('movement', 2))
        for source in ('walk_in_place_right 1\nstep_end', 'walk_in_place_right\nend', 'walk_in_place_right'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Move:\n' + source, {}, version=4, address=0x08240000)
        with self.assertRaises(ValueError):
            profile.profile_block(ROOT, 'Move:\nwalk_in_place_right\nstep_end', {})
        if (ROOT / 'tools/preproc/preproc').is_file():
            native_forms.StoryProfileTests().check_native_forms(['walk_in_place_right'], version=4)

    def test_caught_bridge_kecleon_removes_both_body_and_shadow(self):
        bridge = lines('Route120', 'EventScript_RemoveBridgeKecleon')
        self.assertEqual(bridge, ['specialvar VAR_RESULT, GetBattleOutcome',
            'goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn',
            'removeobject LOCALID_BRIDGE_KECLEON', 'removeobject LOCALID_BRIDGE_KECLEON_SHADOW', 'return'])
        route = lines('Route120', 'EventScript_RemoveKecleonObject')
        self.assertEqual(route[:-1], ['call_if_eq VAR_0x8009, 0, Route120_EventScript_RemoveBridgeKecleon'] +
            [f'call_if_eq VAR_0x8009, {n}, Route120_EventScript_RemoveKecleon' for n in range(1, 6)])
        self.assertEqual(route[-1], 'return')

    def test_bridge_wild_battle_guard_and_non_caught_cleanup_are_complementary(self):
        scene = lines('Route120', 'EventScript_StevenBattleKecleon')
        self.assertIn('setwildbattle SPECIES_KECLEON, 30', scene)
        self.assertLess(scene.index('setvar VAR_0x8009, 0'), scene.index('setflag FLAG_SYS_CTRL_OBJ_DELETE'))
        self.assertLess(scene.index('setflag FLAG_SYS_CTRL_OBJ_DELETE'), scene.index('dowildbattle'))
        self.assertLess(scene.index('dowildbattle'), scene.index('clearflag FLAG_SYS_CTRL_OBJ_DELETE'))
        expected = ['goto_if_eq VAR_RESULT, ' + outcome + ', Route120_EventScript_RemoveBridgeKecleonPostBattle'
                    for outcome in ('B_OUTCOME_WON', 'B_OUTCOME_RAN', 'B_OUTCOME_PLAYER_TELEPORTED')]
        self.assertEqual([s for s in scene if s.startswith('goto_if_eq VAR_RESULT, B_OUTCOME_')], expected)
        post = lines('Route120', 'EventScript_RemoveBridgeKecleonPostBattle')
        self.assertEqual([s for s in post if s.startswith('removeobject ')],
                         ['removeobject LOCALID_BRIDGE_KECLEON', 'removeobject LOCALID_BRIDGE_KECLEON_SHADOW'])

    def test_scope_gift_keeps_flag_flight_wait_and_bridge_redraw_order(self):
        sequence = lines('Route120', 'EventScript_StevenGiveDeconScope')
        ordered = ['giveitem ITEM_DEVON_SCOPE', 'setflag FLAG_RECEIVED_DEVON_SCOPE',
            'setfieldeffectargument 0, 1', 'dofieldeffect FLDEFF_NPCFLY_OUT',
            'removeobject LOCALID_ROUTE120_STEVEN', 'waitfieldeffect FLDEFF_NPCFLY_OUT', 'special DrawWholeMapView']
        positions = [sequence.index(item) for item in ordered]
        self.assertEqual(positions, sorted(positions))
        self.assertEqual(sum(s.startswith('setmetatile ') for s in sequence), 4)
        self.assertEqual(sequence[-2:], ['release', 'end'])
        self.assertFalse(any('ShowBagIsFull' in s for s in sequence))

    def test_weather_keeps_actual_nested_coordinate_boundaries(self):
        main = lines('Route120', 'EventScript_SetWeather')
        self.assertEqual(main[1:4], ['goto_if_le VAR_TEMP_1, 14, Route120_EventScript_SetSunnyWeather',
            'goto_if_le VAR_TEMP_1, 60, Route120_EventScript_TrySetRainyWeather',
            'goto_if_ge VAR_TEMP_1, 61, Route120_EventScript_SetCloudyWeather'])
        self.assertEqual(lines('Route120', 'EventScript_TrySetRainyWeather'), [
            'goto_if_le VAR_TEMP_0, 7, Route120_EventScript_SetRainyWeather',
            'goto_if_le VAR_TEMP_0, 19, Route120_EventScript_SetSunnyWeather',
            'goto Route120_EventScript_SetRainyWeather', 'end'])

    def test_daily_berry_uses_id_digit_pairs_and_preserves_bag_full_retry(self):
        source = lines('Route120', 'EventScript_BerryBeauty')
        self.assertIn('specialvar VAR_RESULT, GetPlayerTrainerIdOnesDigit', source)
        cases = [s for s in source if s.startswith('case ')]
        self.assertEqual(cases, [f'case {digit}, Route120_EventScript_Give{name}Berry'
            for digit, name in [(0, 'Figy'), (5, 'Figy'), (1, 'Wiki'), (6, 'Wiki'),
                                (2, 'Mago'), (7, 'Mago'), (3, 'Aguav'), (8, 'Aguav'), (4, 'Iapapa'), (9, 'Iapapa')]])
        gift = lines('Route120', 'EventScript_GiveBerry')
        self.assertLess(gift.index('goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull'),
                        gift.index('setflag FLAG_DAILY_ROUTE_120_RECEIVED_BERRY'))

    def test_grass_type_and_item_success_both_gate_giga_drain_flag(self):
        sequence = lines('Route123', 'EventScript_GigaDrainGirl')
        ordered = ['special IsGrassTypeInParty', 'goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGrassMons',
            'giveitem ITEM_TM_GIGA_DRAIN', 'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull',
            'setflag FLAG_RECEIVED_TM_GIGA_DRAIN']
        self.assertEqual([sequence.index(s) for s in ordered], sorted(sequence.index(s) for s in ordered))
        self.assertEqual(lines('Route123', 'EventScript_NoGrassMons'), ['release', 'end'])

    def test_aqua_three_parallel_motions_finish_before_removal_and_story_update(self):
        sequence = lines('Route121', 'EventScript_AquaGruntsMoveOut')
        self.assertEqual(sum(s.startswith('applymovement ') for s in sequence), 3)
        self.assertLess(sequence.index('waitmovement 0'), sequence.index('removeobject LOCALID_ROUTE121_GRUNT_1'))
        self.assertLess(sequence.index('removeobject LOCALID_ROUTE121_GRUNT_3'), sequence.index('setvar VAR_ROUTE121_STATE, 1'))
        for actor in range(1, 4):
            self.assertEqual(lines('Route121', f'Movement_Grunt{actor}Exit'), ['walk_down'] * 8 + ['step_end'])

    def test_empty_route122_still_has_real_warp_header_and_connections(self):
        self.assertEqual(lines('Route122', 'MapScripts'), ['.byte 0'])
        metadata = json.loads((ROOT / 'data/maps/Route122/map.json').read_text())
        self.assertEqual([len(metadata[field]) for field in ('object_events', 'warp_events', 'coord_events', 'bg_events')], [0, 1, 0, 0])
        self.assertEqual(len(metadata['connections']), 2)
        for name in ('events.inc', 'header.inc', 'connections.inc'):
            self.assertTrue((ROOT / 'data/maps/Route122' / name).is_file())

    def test_surface_route124_keeps_both_right_connections_and_separate_dive_owner(self):
        connections = json.loads((ROOT / 'data/maps/Route124/map.json').read_text())['connections']
        self.assertEqual([(c['map'], c['offset']) for c in connections if c['direction'] == 'right'],
                         [('MAP_ROUTE125', 0), ('MAP_MOSSDEEP_CITY', 40)])
        self.assertIn(dict(map='MAP_UNDERWATER_ROUTE124', offset=0, direction='dive'), connections)
        self.assertEqual(lines('Route124', 'OnTransition'),
                         ['call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather', 'end'])

    def test_kecleon_shared_text_definitions_remain_in_their_physical_route120_owner(self):
        source = blocks('Route120')
        for name in ('SomethingUnseeable', 'WantToUseDevonScope', 'UseDevonScopeMonAttacked'):
            self.assertIn('Kecleon_Text_' + name, source)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_five_owners_and_23_strings_keep_exact_native_boundaries(self):
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
    def test_all_64_trainer_frames_and_empty_route122_warp_evidence_are_current(self):
        batch = self.family()
        self.assertEqual(len(batch['trainer_battles']), 64)
        local_shared = {(d['path'], d['entry']) for d in batch['text_dependencies']}
        self.assertTrue({('data/maps/Route120/scripts.inc', 'Kecleon_Text_' + name)
                         for name in ('SomethingUnseeable', 'WantToUseDevonScope', 'UseDevonScopeMonAttacked')} <= local_shared)
        events = [s for s in batch['native_spans'] if s['map'] == 'Route122' and s['role'] == 'events']
        self.assertEqual([(s['symbol'], s['size']) for s in events], [('Route122_MapWarps', 28)])
        self.assertEqual(review._review_batch(ROOT, batch, set(MAPS), {})['status'], 'current')

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_every_distinct_family_form_matches_real_native_expansion(self):
        batch = self.family()
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in batch['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT, dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(forms), 685)
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)


if __name__ == '__main__':
    unittest.main()
