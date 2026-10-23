"""Fortree family: native owners, distinct gift exits and cross-owner contracts."""
import json
from pathlib import Path
import re
import struct
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review

ROOT = Path(__file__).resolve().parents[1]
MAPS = ['FortreeCity_House1', 'FortreeCity_Gym', 'FortreeCity_PokemonCenter_1F',
        'FortreeCity_PokemonCenter_2F', 'FortreeCity_Mart', 'FortreeCity_House2',
        'FortreeCity_House3', 'FortreeCity_House4', 'FortreeCity_House5', 'FortreeCity_DecorationShop']
SIZES = [(14,468,7), (54,2239,33), (9,313,3), (4,39,0), (9,222,3),
         (12,565,7), (5,210,2), (14,417,6), (7,173,3), (9,268,2)]

def owner(path):
    return review.label_blocks((ROOT / path).read_text())

def lines(index, suffix):
    return review.statements(owner(f'data/maps/{MAPS[index]}/scripts.inc')[MAPS[index] + '_' + suffix])

def function(path, name):
    source = (ROOT / path).read_text()
    match = re.search(r'(?ms)^void ' + name + r'\(void\)\n\{(.*?)^\}', source)
    if not match:
        raise AssertionError('missing bounded void entry ' + name)
    return match[1]

class FortreeStoryTests(unittest.TestCase):
    def test_first_aerial_ace_failure_returns_but_later_retry_terminates(self):
        first = lines(1, 'EventScript_GiveAerialAce')
        retry = lines(1, 'EventScript_GiveAerialAce2')
        self.assertEqual(first[1], 'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull')
        self.assertEqual(first[-1], 'return')
        self.assertEqual(retry[1], 'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull')
        self.assertEqual(retry[-2:], ['release', 'end'])
        defeated = lines(1, 'EventScript_WinonaDefeated')
        at = defeated.index('call FortreeCity_Gym_EventScript_GiveAerialAce')
        self.assertLess(at, defeated.index('setflag FLAG_ENABLE_WINONA_MATCH_CALL'))
        self.assertIn('setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0', defeated)
        self.assertIn('setflag FLAG_SCOTT_CALL_FORTREE_GYM', defeated)

    def test_badge_and_rematch_preserve_actual_trainer_flow(self):
        body = lines(1, 'EventScript_WinonaDefeated')
        self.assertIn('setflag FLAG_BADGE06_GET', body)
        self.assertIn('setflag FLAG_DEFEATED_FORTREE_GYM', body)
        self.assertIn('setvar VAR_0x8008, 6', body)
        self.assertTrue(lines(1, 'EventScript_WinonaRematch')[0].startswith('trainerbattle_rematch_double TRAINER_WINONA_1,'))
        self.assertEqual(lines(1, 'EventScript_Winona')[0].rsplit(', ',1)[-1], 'NO_MUSIC')

    def test_hidden_power_guesses_are_fixed_right_right_left_not_random(self):
        body = lines(5, 'EventScript_HiddenPowerGiver')
        self.assertEqual(body.count('multichoice 21, 8, MULTI_RIGHTLEFT, TRUE'), 3)
        self.assertEqual([line for line in body if line.startswith('case ')],
            ['case 1, FortreeCity_House2_EventScript_WrongGuess'] * 2 +
            ['case 0, FortreeCity_House2_EventScript_WrongGuess'])
        self.assertFalse(any(line.startswith(('random ', 'special ')) for line in body))

    def test_hidden_power_greeting_and_bag_failure_have_separate_receipts(self):
        body = lines(5, 'EventScript_HiddenPowerGiver')
        self.assertIn('call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting', body)
        self.assertIn('setflag FLAG_MET_HIDDEN_POWER_GIVER', lines(5, 'EventScript_Greeting'))
        at = body.index('giveitem ITEM_TM_HIDDEN_POWER')
        self.assertEqual(body[at+1:at+3], ['goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull',
                                          'setflag FLAG_RECEIVED_TM_HIDDEN_POWER'])
        self.assertRegex((ROOT / 'constants/global.inc').read_text(), r'(?m)^\s*\.set\s+FALSE,\s*0\s*$')

    def test_event_table_reaches_shared_sleep_tutor_and_flag_requires_teaching_success(self):
        metadata = json.loads((ROOT / 'data/maps/FortreeCity_House2/map.json').read_text())
        entry = 'FortreeCity_House2_EventScript_SleepTalkTutor'
        self.assertIn(entry, [e['script'] for e in metadata['object_events']])
        self.assertNotIn(entry, owner('data/maps/FortreeCity_House2/scripts.inc'))
        shared = owner('data/scripts/move_tutors.inc')
        body = review.statements(shared[entry])
        at = body.index('call MoveTutor_EventScript_OpenPartyMenu')
        self.assertEqual(body[at-1:at+3], ['setvar VAR_0x8005, TUTOR_MOVE_SLEEP_TALK',
            'call MoveTutor_EventScript_OpenPartyMenu',
            'goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_SleepTalkDeclined',
            'setflag FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK'])
        self.assertEqual(review.statements(shared['MoveTutor_EventScript_OpenPartyMenu']),
                         ['special ChooseMonForMoveTutor', 'lock', 'faceplayer', 'return'])
        self.assertFalse(any(line.startswith('setflag ') for line in review.statements(shared['MoveTutor_EventScript_SleepTalkDeclined'])))

    def test_trade_restores_selector_slot_and_requested_name_after_scene(self):
        body = lines(0, 'EventScript_Trader')
        self.assertIn('setvar VAR_0x8008, INGAME_TRADE_PLUSLE', body)
        for line in ('copyvar VAR_0x8009, VAR_RESULT', 'copyvar VAR_0x800A, VAR_0x8004',
                     'goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon'):
            self.assertIn(line, body)
        at = body.index('special CreateInGameTradePokemon')
        self.assertEqual(body[at-2:at+3], ['copyvar VAR_0x8004, VAR_0x8008',
            'copyvar VAR_0x8005, VAR_0x800A', 'special CreateInGameTradePokemon',
            'special DoInGameTradeScene', 'bufferspeciesname STR_VAR_1, VAR_0x8009'])
        self.assertGreater(body.index('setflag FLAG_FORTREE_NPC_TRADE_COMPLETED'), at+1)

    def test_wingull_dispatch_and_mental_herb_retry_keep_distinct_states(self):
        body = lines(7, 'EventScript_Boy')
        self.assertIn('FLAG_RECEIVED_MENTAL_HERB', body[1])
        self.assertIn('FLAG_WINGULL_DELIVERED_MAIL', body[2])
        self.assertIn('FLAG_WINGULL_SENT_ON_ERRAND', body[3])
        self.assertLess(body.index('setflag FLAG_WINGULL_SENT_ON_ERRAND'), body.index('removeobject LOCALID_FORTREE_HOUSE_WINGULL'))
        self.assertIn('clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL', body)
        returned = lines(7, 'EventScript_WingullReturned')
        at = returned.index('giveitem ITEM_MENTAL_HERB')
        self.assertEqual(returned[at+1:at+3], ['goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull',
                                               'setflag FLAG_RECEIVED_MENTAL_HERB'])

    def test_wingull_delivered_producer_remains_in_mossdeep_not_copied_to_fortree(self):
        fortree = (ROOT / 'data/maps/FortreeCity_House4/scripts.inc').read_text()
        self.assertNotIn('setflag FLAG_WINGULL_DELIVERED_MAIL', fortree)
        source = owner('data/maps/MossdeepCity_House2/scripts.inc')
        body = review.statements(source['MossdeepCity_House2_EventScript_Wingull'])
        self.assertIn('setflag FLAG_WINGULL_DELIVERED_MAIL', body)
        self.assertIn('clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL', body)
        for name, flag in (('FortreeCity_House4','FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL'),
                           ('MossdeepCity_House2','FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL')):
            metadata = json.loads((ROOT / f'data/maps/{name}/map.json').read_text())
            bird = [e for e in metadata['object_events'] if e['script']==name + '_EventScript_Wingull']
            self.assertEqual(len(bird), 1)
            self.assertEqual(bird[0]['flag'], flag)
        engine = (ROOT / 'src/event_object_movement.c').read_text()
        body = re.search(r'(?ms)^void RemoveObjectEventByLocalIdAndMap\([^\n]+\)\n\{(.*?)^\}', engine)
        self.assertIsNotNone(body)
        self.assertLess(body[1].index('FlagSet('), body[1].index('RemoveObjectEvent('))
        self.assertIn('setflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL',
                      (ROOT / 'data/scripts/new_game.inc').read_text())

    def test_two_decoration_stocks_are_not_ordinary_item_stocks(self):
        for suffix in ('Desks', 'Chairs'):
            stock = lines(9, 'PokemartDecor_' + suffix)
            self.assertEqual(sum(line.startswith('.2byte DECOR_') for line in stock), 8)
            self.assertFalse(any(line.startswith('.2byte ITEM_') for line in stock))
            self.assertEqual(stock[-1], 'pokemartlistend')
            self.assertIn('pokemartdecoration FortreeCity_DecorationShop_PokemartDecor_' + suffix,
                          lines(9, 'EventScript_Clerk' + suffix))
        stock = lines(4, 'Pokemart')
        self.assertEqual(sum(line.startswith('.2byte ITEM_') for line in stock), 10)
        self.assertEqual(stock[-1], 'pokemartlistend')

    def test_center_keeps_four_hooks_and_three_unused_rs_wrappers(self):
        hooks = lines(3, 'MapScripts')
        self.assertEqual(len([line for line in hooks if line.startswith('map_script ')]), 4)
        for suffix, target in (('Colosseum','Colosseum'), ('TradeCenter','TradeCenter'), ('RecordCorner','RecordCorner')):
            self.assertEqual(lines(3, 'EventScript_' + suffix), ['call CableClub_EventScript_' + target, 'end'])
        self.assertEqual(lines(2, 'OnTransition'), ['setrespawn HEAL_LOCATION_FORTREE_CITY', 'end'])

    def test_rotating_gate_orientation_reset_and_graphics_initialization_are_distinct(self):
        self.assertEqual(lines(1, 'OnTransition'), ['special RotatingGate_InitPuzzle', 'end'])
        self.assertEqual(lines(1, 'EventScript_InitRotatingGates'), ['special RotatingGate_InitPuzzleAndGraphics', 'end'])
        self.assertEqual(lines(1, 'OnWarp')[0],
            'map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates')
        reset = function('src/rotating_gate.c', 'RotatingGate_InitPuzzle')
        graphics = function('src/rotating_gate.c', 'RotatingGate_InitPuzzleAndGraphics')
        self.assertIn('RotatingGate_ResetAllGateOrientations();', reset)
        self.assertNotIn('RotatingGate_ResetAllGateOrientations', graphics)
        self.assertIn('RotatingGate_CreateGatesWithinViewport(0, 0);', graphics)

@unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
class FortreeNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.symbols, cls.memory = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        cls.rom = (ROOT / 'baserom_jp.gba').read_bytes()

    def address(self, label):
        self.assertEqual(len(self.symbols[label]), 1)
        return next(iter(self.symbols[label]))

    def test_all_ten_native_extents_and_eight_trainer_frames_have_no_hidden_fallthrough(self):
        frames = []
        for index, (name, expected) in enumerate(zip(MAPS, SIZES)):
            start = self.address(name + '_MapScripts')
            following = MAPS[index+1] if index+1<len(MAPS) else 'LilycoveCity_CoveLilyMotel_1F'
            self.assertEqual(self.address(following + '_MapScripts')-start, expected[1])
            parts = profile.profile_owner(ROOT, (ROOT / f'data/maps/{name}/scripts.inc').read_text(), version=4, address=start)
            self.assertEqual((len(parts),sum(p.size for p in parts.values()),sum(p.kind=='string' for p in parts.values())), expected)
            frames.extend(frame for part in parts.values() for frame in part.trainer_battles)
            self.assertFalse(any(part.may_fall_through for part in parts.values()))
        self.assertEqual(len(frames), 8)

    def test_jp_plusle_trade_uses_actual_row_one_requested_and_offered_fields(self):
        data = (ROOT / 'graphics/trade/jp/animation/830d114.bin').read_bytes()
        base = self.address('gUnknown_830D114')
        self.assertEqual(len(data), 4*0x3C)
        self.assertEqual(data, self.rom[base-0x08000000:base-0x08000000+len(data)])
        spans = [raw[base-at:base-at+len(data)] for at,raw in self.memory if at<=base and base+len(data)<=at+len(raw)]
        self.assertEqual(spans, [data])
        index = review._literal_define(ROOT, 'include/constants/trade.h', 'INGAME_TRADE_PLUSLE')
        self.assertEqual(index, 1)
        for offset, species in ((12,'PLUSLE'), (56,'VOLBEAT')):
            self.assertEqual(struct.unpack_from('<H',data,index*0x3C+offset)[0],
                review._literal_define(ROOT,'include/constants/species.h','SPECIES_' + species))

    def test_shared_house_and_center_layout_ids_match_native_headers_and_table(self):
        for index, target in ((2,'PokemonCenter_1F'), (3,'PokemonCenter_2F'), (4,'Mart'),
                              (6,'FortreeCity_House1'), (7,'FortreeCity_House2'), (8,'FortreeCity_House1')):
            metadata = json.loads((ROOT / f'data/maps/{MAPS[index]}/map.json').read_text())
            layout_id = review._literal_define(ROOT,'include/constants/layouts.h',metadata['layout'])
            header = self.address(MAPS[index])-0x08000000
            expected = self.address(target + '_Layout')
            self.assertEqual(struct.unpack_from('<I',self.rom,header)[0], expected)
            self.assertEqual(struct.unpack_from('<H',self.rom,header+18)[0], layout_id)
            table = self.address('gMapLayouts')-0x08000000+4*(layout_id-1)
            self.assertEqual(struct.unpack_from('<I',self.rom,table)[0], expected)

    def test_all_sixty_six_local_texts_round_trip_to_exact_jp_native_spans(self):
        count, size = 0, 0
        for name in MAPS:
            for label, block in owner(f'data/maps/{name}/scripts.inc').items():
                if review.text_kind(block) != 'string':
                    continue
                payload = review.encoded_text(ROOT,block,'string')
                start = self.address(label)-0x08000000
                self.assertEqual(payload,self.rom[start:start+len(payload)],label)
                self.assertTrue(payload.endswith(b'\xff'))
                count, size = count+1, size+len(payload)
        self.assertEqual((count,size), (66,3546))

    def test_stock_zero_sentinel_keeps_nonmerchandise_release_end_tail(self):
        for index, suffix, count in ((4,'Pokemart',10), (9,'PokemartDecor_Desks',8),
                                     (9,'PokemartDecor_Chairs',8)):
            label = MAPS[index] + '_' + suffix
            start = self.address(label)
            parts = profile.profile_owner(ROOT,(ROOT / f'data/maps/{MAPS[index]}/scripts.inc').read_text(),
                                          version=4,address=self.address(MAPS[index] + '_MapScripts'))
            self.assertEqual(parts[label].size, 2*count+4)
            at = start-0x08000000+2*count
            self.assertEqual(self.rom[at:at+4], b'\x00\x00\x6c\x02')

if __name__ == '__main__':
    unittest.main()
