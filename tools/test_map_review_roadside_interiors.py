"""Route-side service states and their real JP/native source ownership."""
from pathlib import Path
import json
import re
import struct
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review

ROOT=Path(__file__).resolve().parents[1]

def blocks(name):
    return review.label_blocks((ROOT/f'data/maps/{name}/scripts.inc').read_text())

def lines(name,label):
    return review.statements(blocks(name)[name+'_'+label])

def shared(label):
    return review.statements(review.label_blocks((ROOT/'data/scripts/day_care.inc').read_text())[label])

def family_names():
    source=(ROOT/'data/event_scripts.s').read_text()
    first=source.index('\t.include "data/maps/Route104_MrBrineysHouse/scripts.inc"')
    last=source.index('\t.include "data/maps/MeteorFalls_1F_1R/scripts.inc"',first)
    names=re.findall(r'\.include "data/maps/(\w+)/scripts.inc"',source[first:last])
    if len(names)!=12:
        raise AssertionError('changed route-side physical family')
    return names

class RoadsideStoryTests(unittest.TestCase):
    def test_briney_delivery_gate_preserves_intro_and_actual_departure_state(self):
        name='Route104_MrBrineysHouse'
        body=lines(name,'EventScript_Briney')
        self.assertIn('call_if_unset FLAG_MR_BRINEY_SAILING_INTRO, '+name+'_EventScript_SailingIntro',body)
        self.assertLess(body.index('goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, '+name+'_EventScript_SailBothDeliveries'),
                        body.index('goto_if_unset FLAG_DELIVERED_DEVON_GOODS, '+name+'_EventScript_SailDeliverPackage'))
        intro=lines(name,'EventScript_SailingIntro')
        self.assertEqual(intro[0],'setflag FLAG_MR_BRINEY_SAILING_INTRO')
        depart=lines(name,'EventScript_SailToDewford')
        self.assertIn('call EventScript_BackupMrBrineyLocation',depart)
        self.assertIn('setvar VAR_BOARD_BRINEY_BOAT_STATE, 1',depart)
        self.assertEqual(depart[-4:],['warp MAP_ROUTE104, 13, 51','waitstate','releaseall','end'])

    def test_flower_shop_requires_both_met_owner_and_badge_three_for_sales(self):
        name='Route104_PrettyPetalFlowerShop'
        transition=lines(name,'OnTransition')
        self.assertEqual(transition[1:3],[
            'goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, '+name+'_EventScript_MoveShopOwner',
            'goto_if_unset FLAG_BADGE03_GET, '+name+'_EventScript_MoveShopOwner'])
        self.assertEqual(transition[-2:],['setflag FLAG_TEMP_1','end'])
        mart=lines(name,'Pokemart_Plants')
        self.assertEqual(len(mart),7)
        self.assertTrue(all(row.startswith('.2byte DECOR_') for row in mart[:-1]))
        self.assertEqual(mart[-1],'pokemartlistend')

    def test_daily_berry_receipt_is_after_time_update_random_and_bag_success(self):
        name='Route104_PrettyPetalFlowerShop'
        body=lines(name,'EventScript_RandomBerryGirl')
        self.assertLess(body.index('dotimebasedevents'),body.index('random 8'))
        self.assertIn('addvar VAR_RESULT, FIRST_BERRY_INDEX',body)
        self.assertLess(body.index('goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull'),
                        body.index('setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY'))

    def test_macho_brace_and_dig_flags_require_successful_bag_addition(self):
        for name,entry,flag in (
            ('Route111_WinstrateFamilysHouse','Victoria','FLAG_RECEIVED_MACHO_BRACE'),
            ('Route114_FossilManiacsHouse','FossilManiacsBrother','FLAG_RECEIVED_TM_DIG')):
            body=lines(name,'EventScript_'+entry)
            self.assertLess(body.index('goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull'),
                            body.index('setflag '+flag))
        self.assertEqual(lines('Route111_WinstrateFamilysHouse','EventScript_FaceOriginalDirection'),
            ['closemessage','applywaitmovement VAR_0x8008, Common_Movement_FaceOriginalDirection','release','end'])

    def test_rest_stop_can_repeat_healing_without_falling_into_a_gift_path(self):
        name='Route111_OldLadysRestStop'
        body=lines(name,'EventScript_Rest')
        self.assertIn('call Common_EventScript_OutOfCenterPartyHeal',body)
        self.assertIn('goto_if_eq VAR_RESULT, YES, '+name+'_EventScript_Rest',body)
        self.assertEqual(lines(name,'EventScript_DeclineRest')[-2:],['release','end'])

    def test_paired_cable_stations_keep_opposite_directions_and_arrival_states(self):
        for name,direction,state in (('Route112_CableCarStation','FALSE',1),('MtChimney_CableCarStation','TRUE',2)):
            ride=lines(name,'EventScript_RideCableCar')
            self.assertIn('setvar VAR_0x8004, '+direction,ride)
            self.assertIn('setvar VAR_CABLE_CAR_STATION_STATE, '+str(state),ride)
            self.assertLess(ride.index('special CableCarWarp'),ride.index('special CableCar'))
            self.assertIn('incrementgamestat GAME_STAT_RODE_CABLE_CAR',ride)
            arrival=lines(name,'EventScript_ExitCableCar')
            self.assertIn('setvar VAR_CABLE_CAR_STATION_STATE, 0',arrival)
            self.assertEqual(arrival[-2:],['releaseall','end'])
        self.assertEqual(profile.special_waits(ROOT)['CableCar'],1)
        self.assertEqual(profile.special_waits(ROOT)['CableCarWarp'],0)

    def test_fossil_underpass_gate_uses_game_clear_and_only_then_moves_the_maniac(self):
        name='Route114_FossilManiacsTunnel'
        self.assertEqual(lines(name,'OnTransition')[0],
            'call_if_set FLAG_SYS_GAME_CLEAR, '+name+'_EventScript_MoveFossilManiac')
        self.assertEqual(lines(name,'OnLoad')[0],
            'call_if_unset FLAG_SYS_GAME_CLEAR, '+name+'_EventScript_CloseDesertUnderpass')
        self.assertEqual(lines(name,'EventScript_CloseDesertUnderpass'),[
            'setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE',
            'setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE','return'])
        self.assertIn('setvar VAR_FOSSIL_MANIAC_STATE, 2',lines(name,'EventScript_ManiacMentionCaveIn'))

    def test_lanette_pc_name_precedes_doll_capacity_and_notebook_returns(self):
        name='Route114_LanettesHouse'
        body=lines(name,'EventScript_Lanette')
        self.assertLess(body.index('setflag FLAG_SYS_PC_LANETTE'),body.index('givedecoration DECOR_LOTAD_DOLL'))
        self.assertLess(body.index('goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor'),
                        body.index('setflag FLAG_RECEIVED_DOLL_LANETTE'))
        page=lines(name,'EventScript_NotebookPage2')
        self.assertIn('call_if_eq VAR_RESULT, YES, '+name+'_EventScript_NotebookPage3',page)
        self.assertEqual(lines(name,'EventScript_NotebookPage3')[-1],'return')

    def test_tunnel_rest_house_dialogue_follows_the_real_opened_flag(self):
        name='Route116_TunnelersRestHouse'
        self.assertIn('goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, '+name+'_EventScript_TunnelOpened',
                      lines(name,'EventScript_Tunneler3'))
        self.assertEqual(lines(name,'EventScript_TunnelOpened')[-2:],['release','end'])

    def test_daycare_admission_handles_eggs_alive_counts_and_party_menu_cancel(self):
        prefix='Route117_PokemonDayCare_EventScript_'
        body=shared(prefix+'GiveMonToRaise')
        for statement in ('specialvar VAR_RESULT, CountPartyNonEggMons',
                          'specialvar VAR_RESULT, CountPartyAliveNonEggMons',
                          'goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, '+prefix+'ComeAgain',
                          'specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot'):
            self.assertIn(statement,body)
        self.assertLess(body.index('special ChooseSendDaycareMon'),body.index('special StoreSelectedPokemonInDaycare'))
        self.assertEqual(profile.special_waits(ROOT)['ChooseSendDaycareMon'],1)

    def test_daycare_retrieval_keeps_party_capacity_cost_and_deduction_order(self):
        prefix='Route117_PokemonDayCare_EventScript_'
        self.assertIn('goto_if_eq VAR_RESULT, PARTY_SIZE, '+prefix+'NoRoom',shared(prefix+'TryRetrieveMon'))
        self.assertEqual(shared(prefix+'CostPrompt')[0],'special GetDaycareCostAndPrepareString')
        self.assertEqual(shared(prefix+'CheckEnoughMoney')[0],
                         'specialvar VAR_RESULT, IsEnoughForCostInVar0x8005')
        retrieve=shared(prefix+'RetrieveMon')
        self.assertLess(retrieve.index('specialvar VAR_RESULT, TakePokemonFromDaycare'),
                        retrieve.index('special SubtractMoneyFromVar0x8005'))

    def test_safari_checks_case_and_capacity_before_charging_and_warping(self):
        name='Route121_SafariZoneEntrance'
        body=lines(name,'EventScript_TryEnterSafariZone')
        self.assertLess(body.index('checkitem ITEM_POKEBLOCK_CASE'),body.index('removemoney 500'))
        self.assertLess(body.index('call '+name+'_EventScript_CheckHasRoomForPokemon'),body.index('removemoney 500'))
        self.assertLess(body.index('checkmoney 500'),body.index('removemoney 500'))
        self.assertEqual(body[-6:],['special EnterSafariMode','setvar VAR_SAFARI_ZONE_STATE, 2',
            'clearflag FLAG_GOOD_LUCK_SAFARI_ZONE','warp MAP_SAFARI_ZONE_SOUTH, 32, 33','waitstate','end'])
        abort=lines(name,'EventScript_MovePlayerBackFromCounter')
        self.assertIn('hidemoneybox',abort)
        self.assertEqual(abort[-2:],['releaseall','end'])

@unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native artifacts')
class RoadsideNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.symbols,_=review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        cls.rom=(ROOT/'baserom_jp.gba').read_bytes()

    def address(self,name):
        self.assertEqual(len(self.symbols[name]),1,name)
        return next(iter(self.symbols[name]))

    def test_all_twelve_owners_and_155_labels_keep_physical_boundaries(self):
        names=family_names()
        self.assertEqual(self.address(names[0]+'_MapScripts'),0x082115F0)
        count=0
        for name,following in zip(names,names[1:]+['MeteorFalls_1F_1R']):
            at=self.address(name+'_MapScripts')
            for label,part in profile.profile_owner(ROOT,(ROOT/f'data/maps/{name}/scripts.inc').read_text(),version=4,address=at).items():
                self.assertEqual(self.address(label),at,label)
                self.assertFalse(part.may_fall_through and not part.fallthrough,label)
                at+=part.size
                count+=1
            self.assertEqual(at,self.address(following+'_MapScripts'))
        self.assertEqual((count,at),(155,0x08212B54))

    def test_all_44_local_texts_preserve_3350_jp_bytes(self):
        count=total=0
        for name in family_names():
            for label,block in blocks(name).items():
                if review.text_kind(block)!='string':
                    continue
                data=review.encoded_text(ROOT,block,'string')
                at=self.address(label)-0x08000000
                self.assertEqual(data,self.rom[at:at+len(data)],label)
                self.assertTrue(data.endswith(b'\xff'))
                count+=1
                total+=len(data)
        self.assertEqual((count,total),(44,3350))

    def test_all_22_central_layout_assets_and_default_indexes_match_rom(self):
        table=self.address('gMapLayouts')-0x08000000
        assets={}
        for name in family_names():
            row=review.default_layout_owner(ROOT,name,allow_shared=True)
            index=review._literal_define(ROOT,'include/constants/layouts.h',row['id'])
            self.assertEqual(struct.unpack_from('<I',self.rom,table+4*(index-1))[0],self.address(row['name']))
            for field,suffix in (('border_filepath','_Border'),('blockdata_filepath','_Blockdata')):
                data=(ROOT/row[field]).read_bytes()
                at=self.address(row['name']+suffix)-0x08000000
                self.assertEqual(data,self.rom[at:at+len(data)])
                assets[row[field]]=len(data)
        self.assertEqual((len(assets),sum(assets.values())),(22,3134))

    def test_daycare_object_calls_shared_woman_beyond_its_ten_byte_local_owner(self):
        name='Route117_PokemonDayCare'
        at=self.address(name+'_ObjectEvents')-0x08000000
        self.assertEqual(struct.unpack_from('<I',self.rom,at+16)[0],
                         self.address('Route117_PokemonDayCare_EventScript_DaycareWoman'))
        self.assertEqual(self.address('Route121_SafariZoneEntrance_MapScripts')-
                         self.address(name+'_MapScripts'),10)
