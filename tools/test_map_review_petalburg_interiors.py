"""Petalburg door gates, battle rewards and Wally-house handoff contracts."""
import json
from pathlib import Path
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_tests
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_tests

ROOT = Path(__file__).resolve().parents[1]
MAPS = ['PetalburgCity_WallysHouse', 'PetalburgCity_Gym', 'PetalburgCity_House1', 'PetalburgCity_House2',
        'PetalburgCity_PokemonCenter_1F', 'PetalburgCity_PokemonCenter_2F', 'PetalburgCity_Mart']
SIZES = [(19, 1045, 8), (219, 8477, 72), (5, 227, 2), (5, 173, 2),
         (16, 501, 6), (4, 39, 0), (11, 319, 3)]


def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())


def scene(name, suffix):
    return review.statements(blocks(name)[name + '_' + suffix])


class PetalburgStoryTests(unittest.TestCase):
    def test_onload_reopens_only_defeated_rooms_before_the_badge(self):
        self.assertEqual(scene(MAPS[1], 'OnLoad'), [
            'goto_if_eq VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_OpenUnlockedDoors',
            'call_if_ge VAR_PETALBURG_GYM_STATE, 7, PetalburgCity_Gym_EventScript_UnlockAllDoors', 'end'])
        lines = scene(MAPS[1], 'EventScript_OpenUnlockedDoors')
        self.assertEqual(lines[:2], ['setvar VAR_0x8005, 1',
            'call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors'])
        trainers = [('RANDALL', 'Speed'), ('MARY', 'Accuracy'), ('PARKER', 'Confusion'),
                    ('ALEXIA', 'Defense'), ('GEORGE', 'Recovery'), ('JODY', 'Strength'), ('BERKE', 'OHKO')]
        self.assertEqual(lines[2:-1], [f'call_if_defeated TRAINER_{trainer}, '
            f'PetalburgCity_Gym_EventScript_Open{room}RoomDoors' for trainer, room in trainers])

    def test_eight_room_ids_choose_animated_or_load_only_door_handling(self):
        for index, room in enumerate(('GymEntrance', 'SpeedRoom', 'AccuracyRoom', 'ConfusionRoom',
                                      'DefenseRoom', 'RecoveryRoom', 'StrengthRoom', 'OHKORoom'), 1):
            lines = scene(MAPS[1], 'EventScript_Open' + room + 'Doors')
            self.assertEqual(lines[:3], [f'setvar VAR_0x8004, {index}',
                'call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors',
                'call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors'])
        waits = profile.special_waits(ROOT)
        self.assertEqual((waits['PetalburgGymSlideOpenRoomDoors'], waits['PetalburgGymUnlockRoomDoors']), (1, 0))

    def test_door_warp_uses_the_saved_coordinate_variables(self):
        lines = scene(MAPS[1], 'EventScript_EnterRoom')
        at = lines.index('warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009')
        self.assertEqual(lines[at + 1:], ['waitstate', 'releaseall', 'end'])
        for suffix, x, y in (('SpeedRoom', 7, 85), ('AccuracyRoom', 1, 98), ('ConfusionRoom', 7, 46),
                             ('LeftDefenseRoom', 1, 59), ('RightDefenseRoom', 7, 59), ('RecoveryRoom', 1, 72),
                             ('LeftStrengthRoom', 1, 20), ('RightStrengthRoom', 7, 20),
                             ('LeftOHKORoom', 1, 33), ('RightOHKORoom', 7, 33),
                             ('LeftGymLeadersRoom', 1, 7), ('RightGymLeadersRoom', 7, 7)):
            lines = scene(MAPS[1], 'EventScript_' + suffix + 'Door')
            at = lines.index(f'setvar VAR_0x8008, {x}')
            self.assertEqual(lines[at + 1], f'setvar VAR_0x8009, {y}')
            self.assertEqual(lines[-3:], [
                'goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom',
                'goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom', 'end'])

    def test_facade_failure_returns_without_marking_receipt(self):
        lines = scene(MAPS[1], 'EventScript_GiveFacade')
        self.assertEqual(lines[:3], ['giveitem ITEM_TM_FACADE',
            'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull', 'setflag FLAG_RECEIVED_TM_FACADE'])
        common = review.label_blocks((ROOT / 'data/event_scripts.s').read_text())
        self.assertEqual(review.statements(common['Common_EventScript_BagIsFull'])[-1], 'return')
        self.assertEqual(review.statements(common['Common_EventScript_ShowBagIsFull'])[-1], 'end')

    def test_enigma_gate_checks_bag_and_pc_before_consuming_availability(self):
        lines = scene(MAPS[1], 'EventScript_ShouldGiveEnigmaBerry')
        self.assertIn('checkitem ITEM_ENIGMA_BERRY', lines)
        self.assertIn('checkpcitem ITEM_ENIGMA_BERRY', lines)
        self.assertLess(lines.index('checkitem ITEM_ENIGMA_BERRY'), lines.index('checkpcitem ITEM_ENIGMA_BERRY'))
        self.assertTrue(any('VAR_ENIGMA_BERRY_AVAILABLE, 0,' in line for line in lines))
        give = scene(MAPS[1], 'EventScript_GiveEnigmaBerry')
        at = give.index('giveitem ITEM_ENIGMA_BERRY')
        self.assertEqual(give[at + 1], 'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull')
        self.assertGreater(give.index('setvar VAR_ENIGMA_BERRY_AVAILABLE, 0'), at + 1)

    def test_house_gift_keeps_the_original_unconditional_hm_receipt(self):
        for suffix in ('OnFrame', 'OnWarp'):
            self.assertIn('VAR_PETALBURG_CITY_STATE, 4,', '\n'.join(scene(MAPS[0], suffix)))
        lines = scene(MAPS[0], 'EventScript_GiveHMSurf')
        at = lines.index('giveitem ITEM_HM_SURF')
        self.assertEqual(lines[at + 1], 'setflag FLAG_RECEIVED_HM_SURF')
        self.assertIn('setvar VAR_PETALBURG_CITY_STATE, 5', lines)
        dad = scene(MAPS[0], 'EventScript_WallysDad')
        self.assertIn('FLAG_DEFEATED_WALLY_VICTORY_ROAD', dad[2])
        self.assertIn('FLAG_RECEIVED_HM_SURF', dad[3])

    def test_starter_type_dialogue_requires_the_selected_starter_in_party(self):
        lines = scene(MAPS[4], 'EventScript_Woman')
        at = lines.index('specialvar VAR_RESULT, IsStarterInParty')
        self.assertEqual(lines[at + 1], 'goto_if_eq VAR_RESULT, TRUE, '
                         'PetalburgCity_PokemonCenter_1F_EventScript_SayStarterTypeInfo')
        kinds = scene(MAPS[4], 'EventScript_SayStarterTypeInfo')
        self.assertEqual(kinds[:3], [f'call_if_eq VAR_STARTER_MON, {i}, '
            f'PetalburgCity_PokemonCenter_1F_EventScript_Say{species}Type'
            for i, species in enumerate(('Treecko', 'Torchic', 'Mudkip'))])

    def test_profile_man_is_a_real_center_event_root_not_a_local_duplicate(self):
        data = json.loads((ROOT / f'data/maps/{MAPS[4]}/map.json').read_text())
        self.assertEqual(data['object_events'][1]['script'], 'ProfileMan_EventScript_Man')
        shared = review.label_blocks((ROOT / 'data/scripts/profile_man.inc').read_text())
        for label in ('ProfileMan_EventScript_CreateProfile', 'ProfileMan_EventScript_CreateNewProfile'):
            lines = review.statements(shared[label])
            at = lines.index('call Common_ShowEasyChatScreen')
            self.assertEqual(lines[at - 1], 'setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE')
            self.assertTrue(any(line.startswith('goto_if_eq VAR_RESULT, 0,') for line in lines))
            self.assertTrue(any(line.startswith('goto_if_eq VAR_RESULT, 1,') for line in lines))


class PetalburgProfileTests(unittest.TestCase):
    def test_new_forms_have_bounded_arguments_and_typed_call_targets(self):
        waits = profile.special_waits(ROOT)
        value = profile.profile_block(ROOT, 'Entry::\ncall_if_defeated TRAINER_RANDALL, Target\nend',
                                      waits, version=4, address=0x08000000)
        self.assertEqual((value.size, value.targets), (10, {'Target': 'script'}))
        for line in ('call_if_defeated VAR_RESULT, Target', 'call_if_not_defeated TRAINER_RANDALL, 0x08100000',
                     'checkpcitem ITEM_ENIGMA_BERRY, FALSE', 'checkpcitem ITEM_ENIGMA_BERRY, 1, 2',
                     'warpdoor 0, 1, 2', 'warpdoor MAP_PETALBURG_CITY_GYM, STR_VAR_1, 1',
                     'warpdoor MAP_PETALBURG_CITY_GYM, 1'):
            with self.subTest(line=line), self.assertRaises(ValueError):
                profile.profile_block(ROOT, 'Entry::\n' + line + '\nend', waits, version=4, address=0x08000000)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native build tools')
    def test_new_forms_match_actual_macro_expansions(self):
        native_tests.StoryProfileTests().check_native_forms([
            'call_if_defeated TRAINER_RANDALL, Target', 'call_if_not_defeated TRAINER_RANDALL, Target',
            'checkpcitem ITEM_ENIGMA_BERRY', 'checkpcitem VAR_0x8004, VAR_0x8005',
            'checkpcitem ITEM_ENIGMA_BERRY, 2',
            'warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009',
            'warpdoor MAP_PETALBURG_CITY_GYM, 1, 7'], version=4)

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_family_extent_and_all_nine_battle_frames_are_preserved(self):
        symbols, _ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        frames = []
        for name, (labels, size, texts) in zip(MAPS, SIZES):
            values = symbols[name + '_MapScripts']
            self.assertEqual(len(values), 1)
            parts = profile.profile_owner(ROOT, (ROOT / f'data/maps/{name}/scripts.inc').read_text(),
                                          version=4, address=next(iter(values)))
            self.assertEqual((len(parts), sum(p.size for p in parts.values()),
                              sum(p.kind == 'string' for p in parts.values())), (labels, size, texts))
            self.assertFalse(any(p.may_fall_through for p in parts.values()))
            frames.extend(battle for p in parts.values() for battle in p.trainer_battles)
        self.assertEqual(len(frames), 9)
        self.assertEqual(sum('post_script' in f for f in frames), 7)
        self.assertEqual(sum(f['trainer'] == 'TRAINER_NORMAN_1' for f in frames), 2)


if __name__ == '__main__':
    unittest.main()
