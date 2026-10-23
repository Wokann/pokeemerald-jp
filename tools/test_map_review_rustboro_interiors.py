"""Rustboro family: bounded menu encoding, story contracts and native owners."""
from pathlib import Path
import re
import subprocess
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
MAPS = ['RustboroCity_DevonCorp_1F', 'RustboroCity_DevonCorp_2F', 'RustboroCity_DevonCorp_3F',
        'RustboroCity_Gym', 'RustboroCity_PokemonSchool', 'RustboroCity_PokemonCenter_1F',
        'RustboroCity_PokemonCenter_2F', 'RustboroCity_Mart', 'RustboroCity_Flat1_1F',
        'RustboroCity_Flat1_2F', 'RustboroCity_House1', 'RustboroCity_CuttersHouse',
        'RustboroCity_House2', 'RustboroCity_Flat2_1F', 'RustboroCity_Flat2_2F',
        'RustboroCity_Flat2_3F', 'RustboroCity_House3']
SIZES = [(24,1017,10), (54,2048,17), (35,1692,15), (40,2389,25), (46,2201,19),
         (9,262,3), (4,39,0), (12,308,3), (5,92,2), (27,1112,14), (12,436,6),
         (7,409,3), (5,132,2), (5,79,2), (7,205,3), (5,98,2), (7,179,3)]

def blocks(index):
    return review.label_blocks((ROOT / f'data/maps/{MAPS[index]}/scripts.inc').read_text())

def lines(index, suffix):
    return review.statements(blocks(index)[MAPS[index] + '_' + suffix])

def parse(source, version=4):
    return profile.profile_block(ROOT, 'Entry::\n' + source, version=version, address=0x08000000)

class RustboroProfileTests(unittest.TestCase):
    def test_grid_requires_five_bounded_immediates_and_a_named_menu_in_v4(self):
        for source in ('multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE',
                       'multichoicegrid 0, 255, MULTI_STATUS_INFO, 1, TRUE'):
            self.assertEqual(parse(source).size, 6)
        for args in ('8, 1, MULTI_STATUS_INFO, 3', '8, 1, 13, 3, FALSE',
                     'VAR_RESULT, 1, MULTI_STATUS_INFO, 3, FALSE',
                     '256, 1, MULTI_STATUS_INFO, 3, FALSE', '-1, 1, MULTI_STATUS_INFO, 3, FALSE',
                     '8, 1, MULTI_STATUS_INFO, 0, FALSE', '8, 1, MULTI_STATUS_INFO, 256, FALSE',
                     '8, 1, MULTI_STATUS_INFO, 3, 2', '8, 1, MULTI_STATUS_INFO, FALSE, 3'):
            with self.subTest(args=args), self.assertRaises(ValueError):
                parse('multichoicegrid ' + args)
        with self.assertRaises(ValueError):
            parse('multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE', version=3)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_grid_size_matches_actual_native_expansion(self):
        native_tests.StoryProfileTests().check_native_forms([
            'multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE',
            'multichoicegrid 0, 255, MULTI_STATUS_INFO, 1, TRUE'], version=4)

class RustboroStoryTests(unittest.TestCase):
    def test_blackboard_five_topics_loop_and_exit_or_b_share_release(self):
        body = lines(4, 'EventScript_ChooseBlackboardTopic')
        self.assertEqual(body[2], 'multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE')
        for choice, name in enumerate(('Poison','Paralysis','Sleep','Burn','Freeze')):
            self.assertIn(f'case {choice}, {MAPS[4]}_EventScript_{name}', body)
            self.assertEqual(lines(4, 'EventScript_' + name)[1],
                             'goto ' + MAPS[4] + '_EventScript_ChooseBlackboardTopic')
        for choice in ('5', 'MULTI_B_PRESSED'):
            self.assertIn(f'case {choice}, {MAPS[4]}_EventScript_ExitTopicSelect', body)
        self.assertEqual(lines(4, 'EventScript_ExitTopicSelect'), ['releaseall', 'end'])
        self.assertNotIn('waitstate', body)

    def test_devon_stairs_require_returned_goods_not_only_recovered_goods(self):
        self.assertEqual(lines(0, 'OnTransition')[0],
            'call_if_unset FLAG_RETURNED_DEVON_GOODS, ' + MAPS[0] + '_EventScript_BlockStairs')
        self.assertEqual(lines(0, 'EventScript_BlockStairs')[:2], [
            'setobjectxyperm LOCALID_DEVON_CORP_STAIR_GUARD, 14, 2',
            'setobjectmovementtype LOCALID_DEVON_CORP_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN'])
        body = lines(0, 'EventScript_StairGuard')
        self.assertIn('FLAG_RETURNED_DEVON_GOODS', body[2])
        self.assertIn('FLAG_RECOVERED_DEVON_GOODS', body[3])

    def test_fossil_pending_readiness_and_selection_are_actual_state_transitions(self):
        for suffix in ('OnTransition', 'EventScript_TalkToPokemonScientist', 'EventScript_BallScientist',
                       'EventScript_PokenavScientist', 'EventScript_PokemonDreamsScientist'):
            self.assertIn('call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, ' + MAPS[1] + '_EventScript_SetFossilReady',
                          lines(1, suffix))
        self.assertEqual(lines(1, 'EventScript_SetFossilReady'), ['setvar VAR_FOSSIL_RESURRECTION_STATE, 2', 'return'])
        for fossil, selector in (('Root',1), ('Claw',2)):
            body = lines(1, 'EventScript_Give' + fossil + 'Fossil')
            self.assertEqual(body[2:5], ['removeitem ITEM_' + fossil.upper() + '_FOSSIL',
                'setvar VAR_FOSSIL_RESURRECTION_STATE, 1', f'setvar VAR_WHICH_FOSSIL_REVIVED, {selector}'])
        body = lines(1, 'EventScript_ChooseFossil')
        for choice, target in (('0','ChooseClawFossil'), ('1','ChooseRootFossil'),
                               ('2','CancelFossilSelect'), ('MULTI_B_PRESSED','CancelFossilSelect')):
            self.assertIn(f'case {choice}, {MAPS[1]}_EventScript_{target}', body)

    def test_fossil_party_pc_and_no_room_do_not_clear_pending_state_prematurely(self):
        for mon in ('Lileep', 'Anorith'):
            body = lines(1, 'EventScript_Receive' + mon)
            self.assertEqual(body[1], f'givemon SPECIES_{mon.upper()}, 20')
            self.assertIn('MON_GIVEN_TO_PARTY', body[2])
            self.assertIn('MON_GIVEN_TO_PC', body[3])
            self.assertEqual(body[4], 'goto Common_EventScript_NoMoreRoomForPokemon')
            self.assertFalse(any('setvar VAR_FOSSIL_RESURRECTION_STATE' in line for line in body))
            self.assertEqual(lines(1, 'EventScript_FinishReceiving' + mon)[:2],
                ['setvar VAR_FOSSIL_RESURRECTION_STATE, 0', 'setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON'])

    def test_president_handoff_sets_pokenav_flags_without_inventing_an_item_grant(self):
        body = lines(2, 'EventScript_MeetPresident')
        self.assertIn('giveitem ITEM_LETTER', body)
        self.assertEqual([line for line in body if line.startswith('giveitem')], ['giveitem ITEM_LETTER'])
        for line in ('setflag FLAG_SYS_POKENAV_GET', 'setflag FLAG_RECEIVED_POKENAV',
                     'setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT',
                     'call Common_EventScript_OutOfCenterPartyHeal', 'setvar VAR_DEVON_CORP_3F_STATE, 1',
                     'setvar VAR_RUSTBORO_CITY_STATE, 6'):
            self.assertIn(line, body)
        self.assertEqual(body.count('waitmovement 0'), 2)

    def test_exp_share_requires_letter_delivery_and_bag_space_before_receipt(self):
        self.assertIn('goto_if_set FLAG_DELIVERED_STEVEN_LETTER, ' + MAPS[2] + '_EventScript_GiveExpShare',
                      lines(2, 'EventScript_MrStone'))
        body = lines(2, 'EventScript_GiveExpShare')
        self.assertEqual(body[1:4], ['giveitem ITEM_EXP_SHARE',
            'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull', 'setflag FLAG_RECEIVED_EXP_SHARE'])

    def test_rock_tomb_is_a_tail_gift_and_badge_is_not_rolled_back_on_full_bag(self):
        body = lines(3, 'EventScript_RoxanneDefeated')
        self.assertIn('setflag FLAG_BADGE01_GET', body)
        self.assertIn('setvar VAR_RUSTBORO_CITY_STATE, 1', body)
        self.assertEqual(body[-2:], ['goto ' + MAPS[3] + '_EventScript_GiveRockTomb', 'end'])
        body = lines(3, 'EventScript_GiveRockTomb')
        self.assertEqual(body[:3], ['giveitem ITEM_TM_ROCK_TOMB',
            'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull', 'setflag FLAG_RECEIVED_TM_ROCK_TOMB'])
        self.assertEqual(body[-2:], ['release', 'end'])

    def test_quick_claw_preserves_false_zero_spelling_and_receipt_after_success(self):
        body = lines(4, 'EventScript_Teacher')
        at = body.index('giveitem ITEM_QUICK_CLAW')
        self.assertEqual(body[at+1], 'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull')
        self.assertLess(at+1, body.index('setflag FLAG_RECEIVED_QUICK_CLAW'))
        self.assertRegex((ROOT / 'constants/global.inc').read_text(), r'(?m)^\s*\.set\s+FALSE,\s*0\s*$')

    def test_scott_keeps_distinct_prebadge_and_postbadge_receipts(self):
        body = lines(4, 'EventScript_Scott')
        self.assertIn('FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE', body[2])
        self.assertIn('FLAG_MET_SCOTT_RUSTBORO', body[3])
        self.assertIn('FLAG_BADGE01_GET', body[4])
        self.assertEqual(body[6:8], ['addvar VAR_SCOTT_STATE, 1', 'setflag FLAG_MET_SCOTT_RUSTBORO'])
        self.assertEqual(lines(4, 'EventScript_MetScottAfterBadge')[:2],
            ['addvar VAR_SCOTT_STATE, 1', 'setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE'])

    def test_mart_expansion_adds_timer_repeat_balls_on_met_employee_flag(self):
        clerk = lines(7, 'EventScript_Clerk')
        self.assertIn('FLAG_MET_DEVON_EMPLOYEE', clerk[4])
        self.assertIn('FLAG_MET_DEVON_EMPLOYEE', clerk[5])
        basic = lines(7, 'Pokemart_Basic')
        expanded = lines(7, 'Pokemart_Expanded')
        self.assertEqual(sum(line.startswith('.2byte ITEM_') for line in basic), 10)
        self.assertEqual(sum(line.startswith('.2byte ITEM_') for line in expanded), 12)
        self.assertEqual([line for line in expanded if line not in ('.2byte ITEM_TIMER_BALL', '.2byte ITEM_REPEAT_BALL')], basic)
        self.assertEqual(basic[-1], 'pokemartlistend')

    def test_trade_preserves_selector_slot_and_requested_species_across_async_calls(self):
        body = lines(10, 'EventScript_Trader')
        for line in ('setvar VAR_0x8008, INGAME_TRADE_SEEDOT', 'copyvar VAR_0x8009, VAR_RESULT',
                     'copyvar VAR_0x800A, VAR_0x8004', 'copyvar VAR_0x800B, VAR_RESULT',
                     'goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, ' + MAPS[10] + '_EventScript_DeclineTrade',
                     'goto_if_ne VAR_RESULT, VAR_0x8009, ' + MAPS[10] + '_EventScript_NotRequestedMon'):
            self.assertIn(line, body)
        at = body.index('special CreateInGameTradePokemon')
        self.assertEqual(body[at-2:at+2], ['copyvar VAR_0x8004, VAR_0x8008',
            'copyvar VAR_0x8005, VAR_0x800A', 'special CreateInGameTradePokemon', 'special DoInGameTradeScene'])
        self.assertGreater(body.index('setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED'), at+1)

    def test_walda_classification_uses_8004_not_stale_result(self):
        body = lines(9, 'EventScript_GivePhrase')
        self.assertEqual(body[:4], ['special DoWaldaNamingScreen',
            'goto_if_eq VAR_0x8004, 1, ' + MAPS[9] + '_EventScript_CancelGivePhrase',
            'goto_if_eq VAR_0x8004, 2, ' + MAPS[9] + '_EventScript_CancelGiveFirstPhrase',
            'specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase'])
        self.assertEqual(lines(9, 'EventScript_WaldasDadFaceWalda'), ['turnobject LOCALID_WALDAS_DAD, DIR_EAST', 'return'])

    def test_hm_cut_is_unconditional_while_premier_ball_has_full_bag_retry(self):
        body = lines(11, 'EventScript_Cutter')
        at = body.index('giveitem ITEM_HM_CUT')
        self.assertEqual(body[at+1], 'setflag FLAG_RECEIVED_HM_CUT')
        self.assertFalse(any('VAR_RESULT' in line for line in body))
        body = lines(14, 'EventScript_NinjaBoy')
        at = body.index('giveitem ITEM_PREMIER_BALL')
        self.assertEqual(body[at+1:at+3], ['goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull',
                                          'setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO'])

    def test_president_text_uses_actual_player_and_kun_placeholders(self):
        local = blocks(2)
        self.assertIn('{PLAYER}', local[MAPS[2] + '_Text_ReceivedPokenav'])
        caution = local[MAPS[2] + '_Text_MrStoneGoWithCautionAndCare']
        self.assertIn('{PLAYER}{KUN}', caution)
        self.assertNotRegex(caution, r'\{(?:STRING|MUS_|B_PLAYER_)')

@unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
class RustboroNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.symbols, cls.memory = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())

    def address(self, label):
        self.assertEqual(len(self.symbols[label]), 1)
        return next(iter(self.symbols[label]))

    def payload(self, start, size):
        spans = [data[start-base:start-base+size] for base,data in self.memory
                 if base<=start and start+size<=base+len(data)]
        self.assertEqual(len(spans), 1)
        return spans[0]

    def test_all_seventeen_native_extents_five_trainers_and_walda_fallthrough(self):
        frames, fallthroughs = [], []
        for index, (name, expected) in enumerate(zip(MAPS, SIZES)):
            start = self.address(name + '_MapScripts')
            following = MAPS[index+1] if index+1<len(MAPS) else 'FortreeCity_House1'
            self.assertEqual(self.address(following + '_MapScripts') - start, expected[1])
            parts = profile.profile_owner(ROOT, (ROOT / f'data/maps/{name}/scripts.inc').read_text(),
                                          version=4, address=start)
            self.assertEqual((len(parts), sum(p.size for p in parts.values()), sum(p.kind=='string' for p in parts.values())), expected)
            for label, part in parts.items():
                frames.extend(part.trainer_battles)
                if part.may_fall_through:
                    self.assertTrue(part.fallthrough)
                    self.assertEqual(self.address(part.fallthrough), self.address(label)+part.size)
                    fallthroughs.append((label, part.fallthrough))
        self.assertEqual(len(frames), 5)
        self.assertEqual(fallthroughs, [(MAPS[9] + '_EventScript_WaldasDad', MAPS[9] + '_EventScript_GivePhrase')])

    def test_roxanne_registration_is_real_data_not_redundant_absolute_alias(self):
        label = MAPS[3] + '_EventScript_RegisterRoxanne'
        self.assertEqual(self.address(label), 0x08202410)
        self.assertEqual(len(re.findall(r'(?m)^' + label + r'::', (ROOT / f'data/maps/{MAPS[3]}/scripts.inc').read_text())), 1)
        self.assertNotRegex((ROOT / 'ld_script_jp.txt').read_text(), r'(?m)^\s*' + label + r'\s*=')
        output = subprocess.check_output([str(ROOT / 'tools/binutils/bin/arm-none-eabi-nm'),
                                          str(ROOT / 'pokeemerald_jp.elf')], text=True)
        self.assertRegex(output, r'(?m)^08202410 D ' + label + r'$')
        self.assertIn(label, (ROOT / 'src/field_control_avatar.c').read_text())
        body = lines(3, 'EventScript_RegisterRoxanne')
        self.assertIn('setflag FLAG_ENABLE_ROXANNE_MATCH_CALL', body)
        self.assertIn('clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL', body)

    def test_jp_first_trade_row_and_actual_getter_not_us_table_assumptions(self):
        table = (ROOT / 'graphics/trade/jp/animation/830d114.bin').read_bytes()
        base = self.address('gUnknown_830D114')
        self.assertEqual(len(table), 4*0x3C)
        self.assertEqual(self.payload(base, len(table)), table)
        rom = (ROOT / 'baserom_jp.gba').read_bytes()
        self.assertEqual(rom[base-0x08000000:base-0x08000000+len(table)], table)
        self.assertEqual(review._literal_define(ROOT, 'include/constants/trade.h', 'INGAME_TRADE_SEEDOT'), 0)
        for offset, species in ((12,'SEEDOT'), (56,'RALTS')):
            self.assertEqual(int.from_bytes(table[offset:offset+2], 'little'),
                review._literal_define(ROOT, 'include/constants/species.h', 'SPECIES_' + species))
        code = self.payload(self.address('GetInGameTradeSpeciesInfo') & ~1, 0x50)
        # Native stride (16*id-id)*4, requested+56, offered+12 and table pointer.
        for part in (bytes.fromhex('0401241aa400'), bytes.fromhex('228f'), bytes.fromhex('a289'), base.to_bytes(4,'little')):
            self.assertIn(part, code)

if __name__ == '__main__':
    unittest.main()
