"""Adjacent route scenes keep real reward, egg and scripted-wild contracts."""
import copy
import json
from pathlib import Path
import re
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
OWNERS = [('Route115', 26, 689, 3), ('Route116', 70, 2414, 18),
          ('Route117', 38, 966, 6), ('Route118', 45, 1276, 9), ('Route119', 89, 2943, 18)]
MAPS = [row[0] for row in OWNERS]


def blocks(path):
    return review.label_blocks((ROOT / path).read_text())


def lines(name, entry):
    return review.statements(blocks(f'data/maps/{name}/scripts.inc')[name + '_' + entry])


class Route115FamilyTests(unittest.TestCase):
    def family(self):
        batches = json.loads((ROOT / review.MANIFEST_PATH).read_text())['batches']
        matches = [batch for batch in batches if set(batch['maps']) & set(MAPS)]
        self.assertEqual(len(matches), 1, 'one cohesive adjacent family')
        self.assertEqual(matches[0]['maps'], MAPS)
        return matches[0]

    def test_wild_battle_forms_measure_default_item_and_explicit_item(self):
        for source, size in [('setwildbattle SPECIES_KECLEON, 30', 6),
                             ('setwildbattle SPECIES_KECLEON, 0x1E, ITEM_NONE', 6),
                             ('setwildbattle SPECIES_KECLEON, 30, ITEM_ORAN_BERRY', 6),
                             ('dowildbattle', 1)]:
            p = profile.profile_block(ROOT, 'Owner::\n' + source + '\nend', {},
                                      version=4, address=0x081ECC00)
            self.assertEqual((p.size, p.kind), (size + 1, 'script'))
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source + '\nend', {})
        for source in ('setwildbattle SPECIES_KECLEON', 'setwildbattle 352, 30',
                       'setwildbattle SPECIES_KECLEON, VAR_RESULT', 'setwildbattle SPECIES_KECLEON, 256',
                       'setwildbattle SPECIES_KECLEON, 30, VAR_RESULT',
                       'setwildbattle SPECIES_KECLEON, 30, ITEM_NONE, 0', 'dowildbattle 1'):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Owner::\n' + source + '\nend', {},
                                      version=4, address=0x081ECC00)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_wild_forms_and_fly_alias_use_real_assembler(self):
        native_forms.StoryProfileTests().check_native_forms([
            'setwildbattle SPECIES_KECLEON, 30', 'setwildbattle SPECIES_KECLEON, 30, ITEM_NONE',
            'setwildbattle SPECIES_KECLEON, 30, ITEM_ORAN_BERRY', 'dowildbattle',
            'giveitem ITEM_HM02', 'giveitem ITEM_HM_FLY'], version=4)

    def test_repeat_ball_met_flag_and_received_flag_have_different_failure_semantics(self):
        sequence = lines('Route116', 'EventScript_GiveRepeatBall')
        self.assertLess(sequence.index('setflag FLAG_MET_DEVON_EMPLOYEE'), sequence.index('giveitem ITEM_REPEAT_BALL'))
        guard = sequence.index('goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall')
        self.assertLess(guard, sequence.index('removeobject VAR_LAST_TALKED'))
        self.assertLess(guard, sequence.index('setflag FLAG_RECEIVED_REPEAT_BALL'))
        failed = lines('Route116', 'EventScript_NoRoomForRepeatBall')
        self.assertFalse(any(line.startswith(('setflag ', 'removeobject ')) for line in failed))

    def test_jerry_and_karen_registration_is_deferred_without_match_call(self):
        for trainer in ('Jerry', 'Karen'):
            for suffix in ('AfterBattle', ''):
                # Both immediate post-battle and later conversation gates are real.
                self.assertIn('goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_Register' + trainer + suffix,
                              lines('Route116', 'EventScript_TryRegister' + trainer + suffix))
            self.assertIn('specialvar VAR_RESULT, IsTrainerRegistered',
                          lines('Route116', 'EventScript_' + trainer))

    def test_daycare_pending_egg_movement_has_a_real_fallthrough(self):
        source = blocks('data/maps/Route117/scripts.inc')
        entry = 'Route117_EventScript_TryMoveDayCareMan'
        p = profile.profile_block(ROOT, source[entry], {}, version=4, address=0x081EC430)
        self.assertEqual(p.fallthrough, 'Route117_EventScript_StopMoveDayCareMan')
        self.assertEqual(review.statements(source[entry]), [
            'goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_StopMoveDayCareMan',
            'setobjectxyperm LOCALID_DAYCARE_MAN, 47, 6'])
        self.assertEqual(review.statements(source[p.fallthrough]), ['return'])

    def test_daycare_full_party_does_not_clear_pending_egg(self):
        source = blocks('data/scripts/day_care.inc')
        accept = review.statements(source['Route117_EventScript_DaycareAcceptEgg'])
        self.assertIn('goto_if_ne VAR_RESULT, PARTY_SIZE, Route117_EventScript_DaycareReceiveEgg', accept)
        self.assertFalse(any('clearflag' in line or 'GiveEgg' in line for line in accept))
        receive = review.statements(source['Route117_EventScript_DaycareReceiveEgg'])
        self.assertLess(receive.index('special GiveEggFromDaycare'), receive.index('clearflag FLAG_PENDING_DAYCARE_EGG'))
        reject = review.statements(source['Route117_EventScript_DaycareEggWaiting'])
        self.assertEqual(sum('goto_if_eq VAR_RESULT, YES, Route117_EventScript_DaycareAcceptEgg' == s for s in reject), 2)
        self.assertLess(reject.index('clearflag FLAG_PENDING_DAYCARE_EGG'), reject.index('special RejectEggFromDayCare'))

    def test_good_rod_and_fly_are_key_item_gifts_not_generic_bag_full_templates(self):
        rod = lines('Route118', 'EventScript_ReceiveGoodRod')
        self.assertLess(rod.index('giveitem ITEM_GOOD_ROD'), rod.index('setflag FLAG_RECEIVED_GOOD_ROD'))
        self.assertFalse(any('ShowBagIsFull' in line for line in rod))
        self.assertEqual(lines('Route119', 'EventScript_GiveFlyHM'),
                         ['giveitem ITEM_HM_FLY', 'setflag FLAG_RECEIVED_HM_FLY', 'return'])

    def test_steven_three_lanes_keep_parallel_exit_and_one_story_state(self):
        for lane in range(3):
            exit_lines = lines('Route118', 'EventScript_StevenExit' + str(lane))
            self.assertEqual(exit_lines[-2:], ['waitmovement 0', 'return'])
            self.assertEqual(sum(line.startswith('applymovement ') for line in exit_lines), 2)
        scene = lines('Route118', 'EventScript_StevenTrigger')
        self.assertLess(scene.index('setvar VAR_ROUTE118_STATE, 1'), scene.index('removeobject LOCALID_ROUTE118_STEVEN'))

    def test_kecleon_caught_callback_and_shared_postbattle_are_complementary(self):
        self.assertIn('call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_TryRemoveKecleon',
                      lines('Route119', 'OnResume'))
        self.assertEqual(lines('Route119', 'EventScript_TryRemoveKecleon'), [
            'specialvar VAR_RESULT, GetBattleOutcome',
            'goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn',
            'removeobject VAR_LAST_TALKED', 'return'])
        sequence = review.statements(blocks('data/scripts/kecleon.inc')['EventScript_BattleKecleon'])
        before = sequence.index('setflag FLAG_SYS_CTRL_OBJ_DELETE')
        battle = sequence.index('dowildbattle')
        after = sequence.index('clearflag FLAG_SYS_CTRL_OBJ_DELETE')
        self.assertLess(before, battle)
        self.assertLess(battle, after)
        self.assertEqual([line for line in sequence if line.startswith('goto_if_eq ')], [
            'goto_if_eq VAR_RESULT, ' + result + ', EventScript_RemoveKecleon'
            for result in ('B_OUTCOME_WON', 'B_OUTCOME_RAN', 'B_OUTCOME_PLAYER_TELEPORTED')])

    def test_rival_two_lanes_finish_before_scott_and_institute_workers_move_once(self):
        workers = lines('Route119', 'EventScript_MoveInstituteWorkersDownstairs')
        self.assertEqual(workers[-2:], ['setvar VAR_WEATHER_INSTITUTE_STATE, 2', 'return'])
        scene = lines('Route119', 'EventScript_RivalExitScottArrive')
        self.assertLess(scene.index('setvar VAR_ROUTE119_STATE, 1'), scene.index('addobject LOCALID_ROUTE119_SCOTT'))
        self.assertLess(scene.index('addvar VAR_SCOTT_STATE, 1'), scene.index('removeobject LOCALID_ROUTE119_SCOTT'))

    def test_weather_and_glasses_use_the_actual_return_and_warp_context(self):
        source = (ROOT / 'src/field_specials.c').read_text()
        glasses = re.search(r'bool8 FoundBlackGlasses\(void\)\s*\{([^{}]+)\}', source)
        weather = re.search(r'void SetRoute119Weather\(void\)\s*\{([^{}]+)\}', source)
        self.assertIsNotNone(glasses)
        self.assertEqual(glasses[1].strip(), 'return FlagGet(FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES);')
        self.assertIsNotNone(weather)
        self.assertIn('IsMapTypeOutdoors((u8)GetLastUsedWarpMapType()) != TRUE', weather[1])
        self.assertIn('SetSavedWeather(WEATHER_ROUTE119_CYCLE)', weather[1])
        contract = profile.special_waits(ROOT)
        self.assertEqual([contract[name] for name in ('FoundBlackGlasses', 'GetBattleOutcome', 'SetRoute119Weather')], [0, 0, 0])

    def test_route119_preserves_its_jp_weather_coordinates_instead_of_copying_us(self):
        metadata = json.loads((ROOT / 'data/maps/Route119/map.json').read_text())
        self.assertEqual(len(metadata['coord_events']), 25)
        weather = {(e['x'], e['y'], e['elevation'], e['weather'])
                   for e in metadata['coord_events'] if e['type'] == 'weather'}
        cycle = 'COORD_EVENT_WEATHER_ROUTE119_CYCLE'
        self.assertEqual(len(weather), 23)
        self.assertTrue({(28, 13, 0, cycle), (33, 13, 3, cycle),
                         (34, 10, 3, 'COORD_EVENT_WEATHER_SUNNY')} <= weather)
        self.assertNotIn((34, 13, 3, cycle), weather)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_all_five_owners_and_54_local_strings_keep_native_boundaries(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        for name, count, size, texts in OWNERS:
            source = blocks(f'data/maps/{name}/scripts.inc')
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
    def test_all_81_battle_frames_and_the_explicit_family_are_current(self):
        batch = self.family()
        self.assertEqual(len(batch['trainer_battles']), 81)
        self.assertEqual(batch['dynamic_layouts'], [])
        result = review._review_batch(ROOT, batch, set(MAPS), {})
        self.assertEqual(result['status'], 'current', result)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native JP artifacts')
    def test_a_named_but_nonadjacent_daycare_return_is_rejected(self):
        batch, native, errors = self.family(), {}, []
        review._native_batch(ROOT, batch, MAPS, errors, native, 0)
        self.assertEqual(errors, [])
        altered = dict(native, symbols=copy.deepcopy(native['symbols']))
        label = 'Route117_EventScript_StopMoveDayCareMan'
        altered['symbols'][label] = {value + 1 for value in altered['symbols'][label]}
        errors = []
        review._native_batch(ROOT, batch, MAPS, errors, altered, 0)
        self.assertIn('native_script_fallthrough_mismatch:Route117_EventScript_TryMoveDayCareMan', errors)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_every_distinct_full_family_form_uses_actual_macro_expansion(self):
        batch = self.family()
        sources = [(ROOT / f'data/maps/{name}/scripts.inc').read_text() for name in MAPS]
        for dep in batch['shared_dependencies']:
            selected = review.shared_script_blocks(ROOT, dep)
            sources.extend(selected[label] for label in dep['labels'])
        forms = {line for source in sources for block in review.label_blocks(source).values()
                 if review.text_kind(block) is None for line in review.statements(block)}
        self.assertEqual(len(forms), 1025)
        native_forms.StoryProfileTests().check_native_forms(sorted(forms), version=4)


if __name__ == '__main__':
    unittest.main()
