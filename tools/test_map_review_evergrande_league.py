"""Finite league state, localization and native-boundary regressions."""
from pathlib import Path
import json
import re
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

ROOT=Path(__file__).resolve().parents[1]

def parse(body,version=4):
    return profile.profile_block(ROOT,'Entry::\n'+body,version=version,address=0x08000000)

def blocks(suffix):
    return review.label_blocks((ROOT/f'data/maps/EverGrandeCity_{suffix}/scripts.inc').read_text())

def lines(suffix,label):
    return review.statements(blocks(suffix)['EverGrandeCity_'+suffix+'_'+label])

def family_names():
    source=(ROOT/'data/event_scripts.s').read_text()
    first=source.index('\t.include "data/maps/EverGrandeCity_SidneysRoom/scripts.inc"')
    last=source.index('\t.include "data/maps/Route104_MrBrineysHouse/scripts.inc"',first)
    names=re.findall(r'\.include "data/maps/(\w+)/scripts.inc"',source[first:last])
    if len(names)!=15 or any(not n.startswith('EverGrandeCity_') for n in names):
        raise AssertionError('changed league physical family')
    return names

class LeagueCommandTests(unittest.TestCase):
    def test_le_call_has_a_typed_script_target_and_eleven_bytes(self):
        part=parse('call_if_le VAR_TEMP_0, 8, Target\nend')
        self.assertEqual((part.kind,part.size,part.targets),('script',12,{'Target':'script'}))

    def test_le_call_rejects_missing_extra_reversed_and_null_arguments(self):
        for body in ('call_if_le','call_if_le LESS_THAN_OR_EQUAL, Target',
                     'call_if_le 8, VAR_TEMP_0, Target','call_if_le VAR_TEMP_0, 8, NULL',
                     'call_if_le VAR_TEMP_0, 8, Target, Extra'):
            with self.subTest(body=body),self.assertRaises(ValueError):
                parse(body)

    def test_le_call_does_not_expand_legacy_profiles(self):
        for version in (2,3):
            with self.subTest(version=version),self.assertRaises(ValueError):
                parse('call_if_le VAR_TEMP_0, 8, Target',version)

    @unittest.skipUnless((ROOT/'tools/preproc/preproc').is_file(),'requires native tools')
    def test_le_call_matches_real_macro_assembler_size(self):
        native_forms.StoryProfileTests().check_native_forms([
            'call_if_le VAR_TEMP_0, 8, Route104_EventScript_CheckBrineyLocation'],version=4)

class LeagueStoryTests(unittest.TestCase):
    def test_elite_states_advance_in_order_and_keep_distinct_defeat_flags(self):
        for state,person in enumerate(('Sidney','Phoebe','Glacia','Drake')):
            room=person+'sRoom'
            self.assertEqual(lines(room,'OnFrame')[0].split(',')[1].strip(),str(state))
            entry=lines(room,'EventScript_WalkInCloseDoor')
            self.assertIn('setvar VAR_ELITE_4_STATE, '+str(state+1),entry)
            self.assertEqual(entry[-2:],['releaseall','end'])
            defeated=lines(room,'EventScript_Defeated')
            self.assertIn('setflag FLAG_DEFEATED_ELITE_4_'+person.upper(),defeated)
            self.assertIn('call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles',defeated)

    def test_drake_intentionally_reuses_sidneys_warp_table(self):
        hooks=lines('DrakesRoom','MapScripts')
        self.assertIn('map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp',hooks)
        self.assertIn('EverGrandeCity_DrakesRoom_OnWarp',blocks('DrakesRoom'))
        defeated=lines('DrakesRoom','EventScript_Defeated')
        self.assertLess(defeated.index('setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE'),
                        defeated.index('special Script_TryGainNewFanFromCounter'))

    def test_all_five_halls_have_real_entry_tables_and_north_facing_scripts(self):
        for index in range(1,6):
            room='Hall'+str(index)
            self.assertEqual(len(blocks(room)),3)
            self.assertEqual(lines(room,'OnWarp')[-1],'.2byte 0')
            self.assertEqual(lines(room,'EventScript_TurnPlayerNorth'),
                             ['turnobject LOCALID_PLAYER, DIR_NORTH','end'])

    def test_guard_keeps_jp_timing_and_actual_badge_six_gate(self):
        body=lines('PokemonLeague_1F','EventScript_DoorGuard')
        self.assertIn('call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight',body)
        self.assertIn('call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft',body)
        self.assertIn('delay 0x4B',body)
        self.assertNotIn('delay 120',body)
        self.assertEqual([row for row in body if 'FLAG_BADGE' in row],
            ['goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges'])
        self.assertLess(body.index('copyobjectxytoperm LOCALID_LEAGUE_GUARD_2'),
                        body.index('setflag FLAG_ENTERED_ELITE_FOUR'))

    def test_mart_has_seven_items_and_executable_sentinel_tail(self):
        mart=[review.statements(block) for block in blocks('PokemonLeague_1F').values()
              if 'pokemartlistend' in review.statements(block)]
        self.assertEqual(mart,[['.2byte ITEM_ULTRA_BALL','.2byte ITEM_HYPER_POTION',
            '.2byte ITEM_MAX_POTION','.2byte ITEM_FULL_RESTORE','.2byte ITEM_FULL_HEAL',
            '.2byte ITEM_REVIVE','.2byte ITEM_MAX_REPEL','pokemartlistend']])
        macros=(ROOT/'asm/macros/event.inc').read_text()
        self.assertRegex(macros,r'\.macro pokemartlistend\s+\.2byte ITEM_NONE\s+release\s+end\s+\.endm')

    def test_champion_rival_and_birch_scene_finishes_at_the_hall_of_fame(self):
        defeated=lines('ChampionsRoom','EventScript_Defeated')
        self.assertIn('checkplayergender',defeated)
        scene=lines('ChampionsRoom','EventScript_BirchArrivesExitForHoF')
        self.assertIn('call ProfBirch_EventScript_RatePokedex',scene)
        all_lines=[row for block in blocks('ChampionsRoom').values() for row in review.statements(block)]
        self.assertIn('warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16',all_lines)
        self.assertIn('setflag FLAG_HIDE_PETALBURG_GYM_GREETER',all_lines)
        self.assertEqual(sum('trainerbattle_no_intro TRAINER_WALLACE' in row for row in all_lines),1)

    def test_game_clear_flags_reset_only_the_intended_elite_and_story_state(self):
        shared=review.label_blocks((ROOT/'data/scripts/hall_of_fame.inc').read_text())
        body=review.statements(shared['EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags'])
        self.assertEqual(body[:2],['special SetChampionSaveWarp','setflag FLAG_IS_CHAMPION'])
        self.assertIn('call_if_unset FLAG_RECEIVED_SS_TICKET, EverGrandeCity_HallOfFame_EventScript_ReadyReceiveSSTicketEvent',body)
        reset=review.label_blocks((ROOT/'data/event_scripts.s').read_text())
        self.assertEqual(review.statements(reset['EverGrandeCity_HallOfFame_EventScript_ResetEliteFour']),
            ['clearflag FLAG_DEFEATED_ELITE_4_'+name for name in ('SIDNEY','PHOEBE','GLACIA','DRAKE')]
            +['setvar VAR_ELITE_4_STATE, 0','return'])

    def test_hall_effect_wait_precedes_game_clear_and_gender_respawn(self):
        all_lines=[row for block in blocks('HallOfFame').values() for row in review.statements(block)]
        self.assertLess(all_lines.index('dofieldeffect FLDEFF_HALL_OF_FAME_RECORD'),
                        all_lines.index('waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD'))
        self.assertLess(all_lines.index('waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD'),
                        all_lines.index('call EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags'))
        self.assertEqual(profile.special_waits(ROOT)['GameClear'],1)
        for gender,house in (('Male','BRENDAN'),('Female','MAY')):
            body=lines('HallOfFame','EventScript_GameClear'+gender)
            self.assertEqual(body,['setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_'+house+'S_HOUSE_2F',
                                  'fadescreenspeed FADE_TO_BLACK, 24','special GameClear','releaseall','end'])

    def test_scott_visit_and_elite_entry_share_the_met_flag(self):
        body=lines('SidneysRoom','OnTransition')
        self.assertIn('setflag FLAG_MET_SCOTT_IN_EVERGRANDE',body)
        scott=lines('PokemonCenter_1F','EventScript_Scott')
        self.assertIn('addvar VAR_SCOTT_STATE, 1',scott)
        self.assertIn('setflag FLAG_MET_SCOTT_IN_EVERGRANDE',scott)
        self.assertIn('removeobject LOCALID_EVER_GRANDE_SCOTT',scott)

    def test_both_upstairs_centers_keep_shared_service_object_entries(self):
        for suffix in ('PokemonCenter_2F','PokemonLeague_2F'):
            hooks=lines(suffix,'MapScripts')
            self.assertEqual(len(hooks),5)
            meta=json.loads((ROOT/f'data/maps/EverGrandeCity_{suffix}/map.json').read_text())
            self.assertEqual([obj['script'] for obj in meta['object_events']],
                ['Common_EventScript_UnionRoomAttendant','Common_EventScript_WirelessClubAttendant',
                 'Common_EventScript_DirectCornerAttendant','CableClub_EventScript_MysteryGiftMan'])

    def test_hall_effect_and_game_clear_have_real_completion_interfaces(self):
        field=(ROOT/'src/field_effect.c').read_text()
        self.assertIn('FieldEffectActiveListRemove(FLDEFF_HALL_OF_FAME_RECORD);',field)
        code=(ROOT/'src/post_battle_event_funcs.c').read_text()
        self.assertIn('SetMainCallback2(CB2_DoHallOfFameScreen);',code)
        self.assertIn('SetContinueGameWarpToHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F);',code)
        self.assertIn('SetContinueGameWarpToHealLocation(HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F);',code)

@unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native artifacts')
class LeagueNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.symbols,_=review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        cls.rom=(ROOT/'baserom_jp.gba').read_bytes()

    def address(self,name):
        self.assertEqual(len(self.symbols[name]),1,name)
        return next(iter(self.symbols[name]))

    def test_all_fifteen_owners_and_162_labels_are_contiguous(self):
        names=family_names()
        self.assertEqual(self.address(names[0]+'_MapScripts'),0x082101E6)
        count=0
        for name,following in zip(names,names[1:]+['Route104_MrBrineysHouse']):
            at=self.address(name+'_MapScripts')
            for label,part in profile.profile_owner(ROOT,(ROOT/f'data/maps/{name}/scripts.inc').read_text(),version=4,address=at).items():
                self.assertEqual(self.address(label),at,label)
                self.assertFalse(part.may_fall_through and not part.fallthrough,label)
                at+=part.size
                count+=1
            self.assertEqual(at,self.address(following+'_MapScripts'))
        self.assertEqual((count,at),(162,0x082115F0))

    def test_all_33_texts_preserve_3038_jp_bytes(self):
        count=total=0
        for name in family_names():
            for label,block in review.label_blocks((ROOT/f'data/maps/{name}/scripts.inc').read_text()).items():
                if review.text_kind(block)!='string':
                    continue
                data=review.encoded_text(ROOT,block,'string')
                at=self.address(label)-0x08000000
                self.assertEqual(data,self.rom[at:at+len(data)],label)
                self.assertTrue(data.endswith(b'\xff'))
                count+=1
                total+=len(data)
        self.assertEqual((count,total),(33,3038))

    def test_default_layout_table_and_all_22_assets_match_native_rom(self):
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
        self.assertEqual((len(assets),sum(assets.values())),(22,4414))

    def test_native_drake_hook_targets_sidney_without_duplicate_owner(self):
        at=self.address('EverGrandeCity_DrakesRoom_MapScripts')-0x08000000
        owner=profile.profile_owner(ROOT,(ROOT/'data/maps/EverGrandeCity_DrakesRoom/scripts.inc').read_text(),version=4,address=at+0x08000000)
        size=owner['EverGrandeCity_DrakesRoom_MapScripts'].size
        self.assertIn(struct.pack('<I',self.address('EverGrandeCity_SidneysRoom_OnWarp')),self.rom[at:at+size])

    def test_native_game_clear_special_keeps_the_wait_opcode(self):
        entry='EverGrandeCity_HallOfFame_EventScript_GameClearMale'
        at=self.address(entry)-0x08000000
        # 3-byte respawn + 3-byte fade, then Special halfword, wait, releaseall, end.
        self.assertEqual(self.rom[at+6],0x25)
        self.assertEqual(self.rom[at+9:at+12],b'\x27\x6b\x02')
