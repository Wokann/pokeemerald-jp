"""Mauville prices, currency/decorations and shared story contracts."""
from pathlib import Path
import re
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
MAPS = ['MauvilleCity_Gym','MauvilleCity_BikeShop','MauvilleCity_House1','MauvilleCity_GameCorner',
        'MauvilleCity_House2','MauvilleCity_PokemonCenter_1F','MauvilleCity_PokemonCenter_2F','MauvilleCity_Mart']
SIZES = [(65,2615,31),(49,2444,22),(6,368,3),(106,3443,33),(11,378,5),(10,251,3),(6,128,1),(7,225,2)]

def blocks(name):
    return review.label_blocks((ROOT / f'data/maps/{name}/scripts.inc').read_text())

def lines(name, suffix):
    return review.statements(blocks(name)[name + '_' + suffix])

def parse(source):
    return profile.profile_block(ROOT, 'Entry::\n' + source, version=4, address=0x08000000)

class MauvilleProfileTests(unittest.TestCase):
    def test_only_the_exact_owner_can_declare_the_eight_nonemitting_prices(self):
        block = blocks(MAPS[3])[MAPS[3] + '_MapScripts']
        self.assertEqual((profile.profile_block(ROOT, block, version=4, address=0x08000000).size), 1)
        expected = {'TM_DOUBLE_TEAM_COINS':1500,'TM_PSYCHIC_COINS':3500,'TM_FLAMETHROWER_COINS':4000,
                    'TM_THUNDERBOLT_COINS':4000,'TM_ICE_BEAM_COINS':4000,'DOLL_COINS':1000,
                    'COINS_PRICE_50':1000,'COINS_PRICE_500':10000}
        self.assertEqual(profile.GAME_CORNER_PRICES, expected)
        for changed in (block.replace('1500','1501'),block + '\n.set AddressAlias, 0x08123456',
                        block.replace(MAPS[3] + '_MapScripts','Other'),block.replace('.set DOLL_COINS, 1000','')):
            with self.subTest(changed=changed), self.assertRaises(ValueError):
                profile.profile_block(ROOT, changed, version=4, address=0x08000000)

    def test_coin_windows_consume_two_literal_bytes_even_when_ignored_by_c(self):
        for op in ('showcoinsbox','hidecoinsbox','updatecoinsbox'):
            self.assertEqual(parse(op + ' 1, 6').size, 3)
            for args in ('1','1, 256','-1, 0','VAR_RESULT, 0','1, 2, 3'):
                with self.subTest(op=op,args=args), self.assertRaises(ValueError):
                    parse(op + ' ' + args)

    def test_only_the_two_audited_capacity_expressions_are_accepted(self):
        for count in (50,500):
            source = f'goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - {count}), NoRoom'
            self.assertEqual(parse(source).targets, {'NoRoom':'script'})
        for source in ('goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 20), NoRoom',
                       'goto_if_eq VAR_TEMP_1, (MAX_COINS + 1 - 50), NoRoom',
                       'setvar VAR_TEMP_1, (MAX_COINS + 1 - 50)', 'goto_if_ge VAR_TEMP_1, 1+1, NoRoom'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                parse(source)

    def test_coin_and_slot_operands_are_bounded_and_outputs_are_variables(self):
        for source in ('checkcoins VAR_TEMP_2','addcoins 20','removecoins DOLL_COINS',
                       'playslotmachine VAR_RESULT','getpokenewsactive POKENEWS_GAME_CORNER'):
            self.assertEqual(parse(source).size, 3)
        for source in ('checkcoins 20','addcoins -1','addcoins 65536','playslotmachine Text',
                       'removecoins UnknownPrice','getpokenewsactive 2','checkmoney DOLL_COINS'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                parse(source)
        for source in ('checkmoney COINS_PRICE_50','removemoney COINS_PRICE_500'):
            self.assertEqual(parse(source).size, 6)

    def test_decoration_gift_uses_standard_seven_and_keeps_itemid_alias(self):
        p = parse('givedecoration DECOR_TREECKO_DOLL')
        self.assertEqual((p.size,p.targets,p.standard_scripts),
                         (7,{'Std_ObtainDecoration':'script'},{7:'Std_ObtainDecoration'}))
        self.assertEqual(parse('bufferdecorationname STR_VAR_2, ITEMID').size, 4)
        self.assertEqual(parse('adddecoration ITEMID').size, 3)
        for source in ('givedecoration ITEM_POTION','checkdecorspace 1',
                       'bufferdecorationname STR_VAR_4, DECOR_TREECKO_DOLL'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                parse(source)

    @unittest.skipUnless((ROOT / 'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_new_forms_match_actual_macro_expansion_with_real_price_definitions(self):
        header = review.statements(blocks(MAPS[3])[MAPS[3] + '_MapScripts'])
        prefix = '\n'.join(header[1:])
        samples = header[1:] + ['showcoinsbox 1, 6','hidecoinsbox 0, 5','updatecoinsbox 1, 1',
            'checkcoins VAR_TEMP_1','addcoins 20','removecoins DOLL_COINS',
            'removecoins TM_ICE_BEAM_COINS','checkmoney COINS_PRICE_50','removemoney COINS_PRICE_500',
            'goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 50), NoRoom',
            'goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - 500), NoRoom',
            'playslotmachine VAR_RESULT','getpokenewsactive POKENEWS_GAME_CORNER',
            'bufferdecorationname STR_VAR_1, DECOR_TREECKO_DOLL','bufferdecorationname STR_VAR_2, ITEMID',
            'checkdecorspace DECOR_TREECKO_DOLL','adddecoration ITEMID','givedecoration DECOR_TREECKO_DOLL']
        native_tests.StoryProfileTests().check_native_forms(samples, version=4, source_prefix=prefix)

class MauvilleStoryTests(unittest.TestCase):
    def test_coin_purchase_checks_capacity_and_funds_before_credit_and_charge(self):
        self.assertRegex((ROOT / 'include/constants/coins.h').read_text(), r'#define MAX_COINS\s+9999\b')
        for count in (50,500):
            body = lines(MAPS[3],f'EventScript_Buy{count}Coins')
            self.assertEqual(body[:3], ['checkcoins VAR_TEMP_1',
                f'goto_if_ge VAR_TEMP_1, (MAX_COINS + 1 - {count}), MauvilleCity_GameCorner_EventScript_NoRoomForCoins',
                f'checkmoney COINS_PRICE_{count}'])
            self.assertLess(body.index(f'addcoins {count}'),body.index(f'removemoney COINS_PRICE_{count}'))
            self.assertIn('VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NotEnoughMoney',body[3])

    def test_doll_and_tm_exchanges_check_space_before_removing_coins(self):
        for name in ('Treecko','Torchic','Mudkip'):
            body = lines(MAPS[3],'EventScript_Buy' + name + 'Doll')
            self.assertEqual(body[0],'checkcoins VAR_TEMP_2')
            self.assertLess(body.index('checkdecorspace DECOR_' + name.upper() + '_DOLL'),body.index('removecoins DOLL_COINS'))
        for name in ('DoubleTeam','Psychic','Flamethrower','Thunderbolt','IceBeam'):
            body = lines(MAPS[3],'EventScript_BuyTM' + name)
            self.assertTrue(body[2].startswith('checkitemspace ITEM_TM_'))
            self.assertTrue(body[3].endswith('MauvilleCity_GameCorner_EventScript_NoRoomForTM'))
            self.assertTrue(body[4].startswith('removecoins TM_'))
            self.assertTrue(body[5].startswith('additem ITEM_TM_'))

    def test_free_starter_doll_and_zero_balance_twenty_coin_gates_are_preserved(self):
        for name in ('Treecko','Torchic','Mudkip'):
            body = lines(MAPS[3],'EventScript_Give' + name + 'Doll')
            self.assertTrue(body[1].startswith('checkdecorspace '))
            self.assertTrue(body[2].endswith('MauvilleCity_GameCorner_EventScript_NoRoomForStarterDoll'))
            self.assertTrue(body[4].startswith('givedecoration '))
            self.assertEqual(body[5],'setflag FLAG_RECEIVED_STARTER_DOLL')
        body = lines(MAPS[3],'EventScript_TryGive20Coins')
        self.assertTrue(body[0].startswith('goto_if_set FLAG_RECEIVED_20_COINS,'))
        self.assertEqual(body[1],'checkcoins VAR_TEMP_1')
        self.assertIn('VAR_TEMP_1, 1,',body[2])
        self.assertEqual(body[3:5],['setflag FLAG_RECEIVED_20_COINS','addcoins 20'])

    def test_twelve_slot_wrappers_use_coin_case_and_builtin_waiting_command(self):
        for index in range(12):
            body = lines(MAPS[3],'EventScript_SlotMachine' + str(index))
            self.assertEqual(body[:2],['lockall','checkitem ITEM_COIN_CASE'])
            self.assertEqual(body[3:7],[f'setvar VAR_0x8004, {index}',
                'specialvar VAR_RESULT, GetSlotMachineId','playslotmachine VAR_RESULT','releaseall'])
            self.assertNotIn('waitstate',body)

    def test_bike_exchange_preserves_flag_and_no_invented_result_branch(self):
        self.assertEqual(lines(MAPS[1],'EventScript_YesFar')[0],'setflag FLAG_RECEIVED_BIKE')
        for old,new in (('Acro','Mach'),('Mach','Acro')):
            body = lines(MAPS[1],f'EventScript_Switch{old}For{new}')
            self.assertLess(body.index(f'removeitem ITEM_{old.upper()}_BIKE'),body.index(f'giveitem ITEM_{new.upper()}_BIKE'))
            self.assertFalse(any('VAR_RESULT' in line for line in body))
        self.assertIn('special SwapRegisteredBike',lines(MAPS[1],'EventScript_ComeBackToSwitchBikes'))

    def test_gym_floor_switches_keep_state_one_to_four_and_selector_zero_to_three(self):
        for switch in range(1,5):
            body = lines(MAPS[0],f'EventScript_Switch{switch}')
            self.assertTrue(body[1].startswith('goto_if_set FLAG_DEFEATED_MAUVILLE_GYM,'))
            self.assertIn(f'VAR_MAUVILLE_GYM_STATE, {switch},',body[2])
            self.assertEqual(body[3:5],[f'setvar VAR_MAUVILLE_GYM_STATE, {switch}',f'setvar VAR_0x8004, {switch-1}'])
        body = lines(MAPS[0],'EventScript_PressFloorSwitch')
        self.assertEqual(body[:3],['special MauvilleGymSetDefaultBarriers','special MauvilleGymPressSwitch','special DrawWholeMapView'])

    def test_shock_wave_bag_full_returns_without_ending_badge_registration(self):
        body = lines(MAPS[0],'EventScript_GiveShockWave')
        self.assertEqual(body[1],'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull')
        self.assertEqual(body[-1],'return')
        defeated = lines(MAPS[0],'EventScript_WattsonDefeated')
        self.assertLess(defeated.index('call MauvilleCity_Gym_EventScript_GiveShockWave'),
                        defeated.index('setflag FLAG_ENABLE_WATTSON_MATCH_CALL'))

    def test_hm_and_harbor_mail_handoffs_keep_original_unconditional_receipts(self):
        body = lines(MAPS[2],'EventScript_RockSmashDude')
        at = body.index('giveitem ITEM_HM_ROCK_SMASH')
        self.assertEqual(body[at+1:at+3],['setflag FLAG_RECEIVED_HM_ROCK_SMASH','setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY'])
        body = lines(MAPS[4],'EventScript_AcceptTrade')
        self.assertEqual(body[1:4],['removeitem ITEM_HARBOR_MAIL','giveitem ITEM_COIN_CASE','setflag FLAG_RECEIVED_COIN_CASE'])

    def test_giddy_yes_and_no_share_the_next_tale_and_trader_uses_distinct_outputs(self):
        shared = review.label_blocks((ROOT / 'data/scripts/mauville_man.inc').read_text())
        prefix = 'MauvilleCity_PokemonCenter_1F_EventScript_'
        body = review.statements(shared[prefix + 'GiddyTellTale'])
        self.assertEqual(body[:2],['special GenerateGiddyLine','special ShowFieldMessageStringVar4'])
        self.assertEqual([line.rsplit(', ',1)[-1] for line in body if line.startswith('goto_if_eq')],
                         [prefix + 'TryTellNewTale'] * 2)
        for suffix,var in (('PickDecorToReceive','VAR_0x8004'),('PickDecorToGive','VAR_0x8006')):
            body = review.statements(shared[prefix + suffix])
            self.assertTrue(any(line.startswith(f'goto_if_eq {var}, 0,') for line in body))
            self.assertTrue(any(line.startswith(f'goto_if_eq {var}, 0xFFFF,') for line in body))

    @unittest.skipUnless((ROOT / 'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
    def test_whole_owner_extents_seven_trainer_frames_and_shared_fallthrough(self):
        symbols,_ = review.native_elf((ROOT / 'pokeemerald_jp.elf').read_bytes())
        frames = []
        for index,(name,(labels,size,texts)) in enumerate(zip(MAPS,SIZES)):
            start = next(iter(symbols[name + '_MapScripts']))
            following = MAPS[index+1] if index+1<len(MAPS) else 'RustboroCity_DevonCorp_1F'
            self.assertEqual(next(iter(symbols[following + '_MapScripts'])) - start,size)
            parts = profile.profile_owner(ROOT,(ROOT / f'data/maps/{name}/scripts.inc').read_text(),version=4,address=start)
            self.assertEqual((len(parts),sum(p.size for p in parts.values()),sum(p.kind=='string' for p in parts.values())),(labels,size,texts))
            frames.extend(frame for part in parts.values() for frame in part.trainer_battles)
            self.assertFalse(any(p.may_fall_through and not p.fallthrough for p in parts.values()))
        self.assertEqual(len(frames),7)
        shared = review.label_blocks((ROOT / 'data/scripts/mauville_man.inc').read_text())
        label = 'MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales'
        start = next(iter(symbols[label]))
        p = profile.profile_block(ROOT,shared[label],version=4,address=start)
        self.assertEqual(p.fallthrough,'MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales')
        self.assertEqual(symbols[p.fallthrough],{start+p.size})

if __name__ == '__main__':
    unittest.main()
