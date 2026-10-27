"""Finite Sootopolis source/native regressions, not gameplay certification."""
from pathlib import Path
import copy
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
    return review.label_blocks((ROOT/f'data/maps/SootopolisCity_{suffix}/scripts.inc').read_text())

def lines(suffix,label):
    return review.statements(blocks(suffix)['SootopolisCity_'+suffix+'_'+label])

def family_names():
    source=(ROOT/'data/event_scripts.s').read_text()
    first=source.index('\t.include "data/maps/SootopolisCity_Gym_1F/scripts.inc"')
    last=source.index('\t.include "data/maps/EverGrandeCity_SidneysRoom/scripts.inc"',first)
    names=re.findall(r'\.include "data/maps/(\w+)/scripts.inc"',source[first:last])
    if len(names)!=15 or any(not n.startswith('SootopolisCity_') for n in names):
        raise AssertionError('changed Sootopolis physical family')
    return names

class SootopolisCommandTests(unittest.TestCase):
    def test_family_local_text_deduplication_requires_a_real_typed_definition(self):
        references={'UpstairsDraw':'string','SharedText':'string'}
        self.assertEqual(review._external_message_dependencies(references,{'UpstairsDraw'},
                         {'UpstairsDraw':'string'}),{'SharedText':'string'})
        self.assertEqual(review._external_message_dependencies(references,{'UpstairsDraw'},
                         {'UpstairsDraw':'string'}, {'UpstairsDraw'}), references)
        for kinds in ({},{'UpstairsDraw':'script'},{'UpstairsDraw':'braille'}):
            with self.subTest(kinds=kinds),self.assertRaises(ValueError):
                review._external_message_dependencies(references,{'UpstairsDraw'},kinds)
        self.assertEqual(review._external_message_dependencies(references,set(),{}),references)

    def test_hole_warp_has_only_a_map_pair_not_coordinates(self):
        self.assertEqual(parse('warphole MAP_SOOTOPOLIS_CITY_GYM_B1F').size,3)
        for body in ('warphole','warphole 0','warphole NULL',
                     'warphole MAP_SOOTOPOLIS_CITY_GYM_B1F, 3, 1'):
            with self.subTest(body=body),self.assertRaises(ValueError):
                parse(body)

    def test_visiting_trainer_selector_uses_the_real_special_wait(self):
        part=parse('frontier_checkvisittrainer')
        wait=profile.special_waits(ROOT)['CallFrontierUtilFunc']
        self.assertEqual((part.size,part.specials),(8+wait,{'CallFrontierUtilFunc':wait}))
        with self.assertRaises(ValueError):
            parse('frontier_checkvisittrainer 0')

    def test_greeting_is_a_causally_produced_ram_buffer(self):
        part=parse('special CopyEReaderTrainerGreeting\nmsgbox gStringVar4, MSGBOX_DEFAULT\nend')
        self.assertEqual(part.runtime_texts,{'gStringVar4':'CopyEReaderTrainerGreeting'})
        self.assertNotIn('gStringVar4',part.texts)
        self.assertEqual(part.specials['CopyEReaderTrainerGreeting'],0)
        for body in ('msgbox gStringVar4, MSGBOX_DEFAULT',
                     'special HealPlayerParty\nmsgbox gStringVar4, MSGBOX_DEFAULT',
                     'special CopyEReaderTrainerGreeting\nlockall\nmsgbox gStringVar4, MSGBOX_DEFAULT'):
            with self.subTest(body=body),self.assertRaises(ValueError):
                parse(body)

    def test_new_forms_do_not_silently_expand_legacy_review_profiles(self):
        for body in ('warphole MAP_SOOTOPOLIS_CITY_GYM_B1F','frontier_checkvisittrainer',
                     'special CopyEReaderTrainerGreeting\nmsgbox gStringVar4, MSGBOX_DEFAULT'):
            with self.subTest(body=body),self.assertRaises(ValueError):
                parse(body,version=3)

    @unittest.skipUnless((ROOT/'tools/preproc/preproc').is_file(),'requires native tools')
    def test_new_forms_match_real_cpp_preproc_assembler_sizes(self):
        native_forms.StoryProfileTests().check_native_forms([
            'warphole MAP_SOOTOPOLIS_CITY_GYM_B1F','frontier_checkvisittrainer',
            'special CopyEReaderTrainerGreeting','msgbox gStringVar4, MSGBOX_DEFAULT'],version=4)

class SootopolisStoryTests(unittest.TestCase):
    def test_ice_thresholds_and_three_fallthroughs_are_explicit(self):
        self.assertEqual(lines('Gym_1F','OnTransition'),['setvar VAR_ICE_STEP_COUNT, 1','end'])
        table=lines('Gym_1F','OnFrame')
        self.assertEqual([int(row.split(',')[1]) for row in table[:-1]],[8,28,67,0])
        for a,b in zip(('CheckSetStairMetatiles','OpenFirstAndSecondStairs','OpenFirstStairs'),
                       ('OpenFirstAndSecondStairs','OpenFirstStairs','StopCheckingStairs')):
            owner='SootopolisCity_Gym_1F_EventScript_'+a
            self.assertEqual(profile.FALLTHROUGHS[owner],'SootopolisCity_Gym_1F_EventScript_'+b)
        for ordinal in ('First','Second','Third'):
            self.assertEqual(lines('Gym_1F','EventScript_Unlock'+ordinal+'Stairs')[0],
                'addvar VAR_ICE_STEP_COUNT, 1')

    def test_jp_fall_animation_uses_the_basement_hole_destination(self):
        body=lines('Gym_1F','EventScript_FallThroughIce')
        self.assertEqual(body[-3:],['warphole MAP_SOOTOPOLIS_CITY_GYM_B1F','waitstate','end'])
        self.assertEqual(body[1],'delay 20')
        self.assertIn('delay 60',body)
        self.assertEqual(lines('Gym_1F','Movement_FallThroughIce'),['set_invisible','step_end'])

    def test_juan_badge_and_city_flags_precede_initial_tm_return(self):
        body=lines('Gym_1F','EventScript_JuanDefeated')
        gift=body.index('call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse')
        for line in ('setflag FLAG_BADGE08_GET','setvar VAR_SOOTOPOLIS_CITY_STATE, 6',
                     'setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN','setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE'):
            self.assertLess(body.index(line),gift)
        self.assertGreater(body.index('setflag FLAG_ENABLE_JUAN_MATCH_CALL'),gift)
        self.assertEqual(lines('Gym_1F','EventScript_GiveWaterPulse')[-1],'return')
        self.assertIn('goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull',
                      lines('Gym_1F','EventScript_GiveWaterPulse2'))

    def test_first_juan_match_and_rematch_are_not_the_same_battle_mode(self):
        self.assertTrue(lines('Gym_1F','EventScript_Juan')[0].startswith('trainerbattle_single '))
        self.assertTrue(lines('Gym_1F','EventScript_Juan')[0].endswith(', NO_MUSIC'))
        self.assertTrue(lines('Gym_1F','EventScript_JuanRematch')[0].startswith('trainerbattle_rematch_double '))
        self.assertIn('goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge',
                      lines('Gym_1F','EventScript_Juan'))

    def test_center_and_mart_weather_dialogue_requires_both_story_conditions(self):
        for suffix,npcs in (('PokemonCenter_1F',('Gentleman','Woman')),('Mart',('FatMan','Gentleman'))):
            for npc in npcs:
                body=lines(suffix,'EventScript_'+npc)
                target='SootopolisCity_'+suffix+'_EventScript_'+npc+'NoLegendaries'
                self.assertEqual(body[2:4],[
                    'goto_if_ge VAR_SKY_PILLAR_STATE, 2, '+target,
                    'goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, '+target])

    def test_brick_break_receipt_flag_is_not_set_when_the_bag_is_full(self):
        body=lines('House1','EventScript_BrickBreakBlackBelt')
        self.assertLess(body.index('giveitem ITEM_TM_BRICK_BREAK'),body.index('setflag FLAG_RECEIVED_TM_BRICK_BREAK'))
        self.assertLess(body.index('goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull'),
                        body.index('setflag FLAG_RECEIVED_TM_BRICK_BREAK'))

    def test_declining_the_doll_ends_the_called_script_not_a_return(self):
        self.assertEqual(lines('House6','EventScript_DeclineWailmerDoll')[-2:],['release','end'])
        body=lines('House6','EventScript_Woman')
        self.assertIn('call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll',body)
        self.assertLess(body.index('goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll'),
                        body.index('setflag FLAG_RECEIVED_WAILMER_DOLL'))

    def test_size_record_buffers_and_unused_potion_text_are_not_reward_logic(self):
        source=(ROOT/'src/pokemon_size_record.c').read_text()
        self.assertIn('FormatMonSizeRecord(gStringVar3, size);',source)
        self.assertIn('FormatMonSizeRecord(gStringVar2, newSize);',source)
        self.assertIn('*sizeRecord = sizeParams;',source)
        for species in ('Seedot','Lotad'):
            body=lines('LotadAndSeedotHouse','EventScript_'+species+'Brother')
            self.assertLess(body.index('special Compare'+species+'Size'),
                body.index('goto_if_eq VAR_RESULT, COMPARE_SIZE_LARGER, SootopolisCity_LotadAndSeedotHouse_EventScript_Big'+species))
            reward=lines('LotadAndSeedotHouse','EventScript_Big'+species)
            self.assertIn('giveitem ITEM_ELIXIR',reward)
            text=blocks('LotadAndSeedotHouse')['SootopolisCity_LotadAndSeedotHouse_Text_Biggest'+species+'InHistory']
            self.assertIn('{STR_VAR_2}',text)
            self.assertIn('{STR_VAR_3}cm',text)
        for n in (1,2):
            self.assertIn('きずぐすり',blocks('LotadAndSeedotHouse')['SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion'+str(n)])

    def test_visiting_trainer_validation_and_layout_switch_are_separate_from_battle_state(self):
        self.assertEqual(lines('MysteryEventsHouse_1F','OnTransition')[0],'frontier_checkvisittrainer')
        body=lines('MysteryEventsHouse_1F','EventScript_SetTrainerVisitingLayout')
        self.assertIn('setvar VAR_TEMP_1, 1',body)
        self.assertIn('setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED',body)
        self.assertEqual(body[-1],'return')

    def test_save_cancellation_restores_party_before_the_basement_entry(self):
        body=lines('MysteryEventsHouse_1F','EventScript_TrainerVisiting')
        save=body.index('call Common_EventScript_SaveGame')
        self.assertEqual(body[save-1],'special LoadPlayerParty')
        self.assertEqual(body[save+2:save+4],['special SavePlayerParty','special ReducePlayerPartyToSelectedMons'])
        self.assertEqual(lines('MysteryEventsHouse_1F','EventScript_DeclineBattle')[0],'special LoadPlayerParty')

    def test_basement_restores_party_and_returns_each_outcome_to_the_upstairs_state(self):
        body=lines('MysteryEventsHouse_B1F','EventScript_BattleVisitingTrainer')
        self.assertEqual(body[2:4],['special CopyEReaderTrainerGreeting','msgbox gStringVar4, MSGBOX_DEFAULT'])
        self.assertIn('setvar VAR_0x8004, SPECIAL_BATTLE_EREADER',body)
        self.assertLess(body.index('special LoadPlayerParty'),body.index('warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F, 3, 1'))
        for outcome,value in (('Won',1),('Lost',2),('Tie',3)):
            self.assertEqual(lines('MysteryEventsHouse_B1F','EventScript_Battle'+outcome)[0],
                'setvar VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, '+str(value))

    def test_double_edge_tutor_sets_its_once_flag_only_after_party_menu_success(self):
        body=review.statements(review.label_blocks((ROOT/'data/scripts/move_tutors.inc').read_text())[
            'SootopolisCity_PokemonCenter_1F_EventScript_DoubleEdgeTutor'])
        self.assertLess(body.index('goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_DoubleEdgeDeclined'),
                        body.index('setflag FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE'))

@unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native artifacts')
class SootopolisNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.symbols,_=review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        cls.ram,_=review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes(),include_ram=True)
        cls.rom=(ROOT/'baserom_jp.gba').read_bytes()
        cls.owners=[]
        for line in (ROOT/'pokeemerald_jp.map').read_text().splitlines():
            m=re.match(r'^\s*(?:\S+\s+)?(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\S+\.o)\s*$',line)
            if m:
                cls.owners.append((int(m[1],16),int(m[2],16),m[3]))

    def address(self,name):
        self.assertEqual(len(self.symbols[name]),1,name)
        return next(iter(self.symbols[name]))

    def native(self):
        return dict(symbols=self.symbols,owners=self.owners,rom=self.rom,runtime_text_symbols=self.ram)

    def test_all_fifteen_owners_and_every_label_have_native_boundaries(self):
        names=family_names()
        self.assertEqual(self.address(names[0]+'_MapScripts'),0x0820E224)
        self.assertEqual(self.address('EverGrandeCity_SidneysRoom_MapScripts'),0x082101E6)
        count=0
        for name,following in zip(names,names[1:]+['EverGrandeCity_SidneysRoom']):
            at=self.address(name+'_MapScripts')
            for label,part in profile.profile_owner(ROOT,(ROOT/f'data/maps/{name}/scripts.inc').read_text(),version=4,address=at).items():
                self.assertEqual(self.address(label),at,label)
                self.assertFalse(part.may_fall_through and not part.fallthrough,label)
                at+=part.size
                count+=1
            self.assertEqual(at,self.address(following+'_MapScripts'))
        self.assertEqual(count,236)

    def test_all_106_texts_preserve_jp_bytes_and_eos(self):
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
        self.assertEqual((count,total),(106,5668))

    def test_greeting_producer_call_and_ram_destination_are_bound(self):
        errors=[]
        review._runtime_text_native(ROOT,parse('special CopyEReaderTrainerGreeting\nmsgbox gStringVar4, MSGBOX_DEFAULT'),self.native(),errors)
        self.assertEqual(errors,[])

    def test_changed_greeting_call_or_buffer_literal_is_rejected(self):
        part=parse('special CopyEReaderTrainerGreeting\nmsgbox gStringVar4, MSGBOX_DEFAULT')
        for symbol,size,error in (('CopyEReaderTrainerGreeting',0x1C,'native_runtime_text_greeting_call_mismatch'),
                                  ('FrontierSpeechToString',0x70,'native_runtime_text_speech_buffer_mismatch')):
            rom=bytearray(self.rom)
            at=self.address(symbol)-0x08000000
            rom[at:at+size]=bytes(size)
            errors=[]
            review._runtime_text_native(ROOT,part,self.native()|{'rom':bytes(rom)},errors)
            self.assertIn(error,errors)

    def test_dynamic_greeting_cannot_be_reclassified_as_a_rom_text(self):
        data=self.native()|{'runtime_text_symbols':copy.deepcopy(self.ram)}
        data['runtime_text_symbols']['gStringVar4']={0x0820E224}
        errors=[]
        review._runtime_text_native(ROOT,parse('special CopyEReaderTrainerGreeting\nmsgbox gStringVar4, MSGBOX_DEFAULT'),data,errors)
        self.assertIn('native_runtime_text_buffer_mismatch:gStringVar4',errors)

    def test_default_and_visiting_layouts_keep_central_asset_owners(self):
        table=self.address('gMapLayouts')-0x08000000
        layouts=[review.default_layout_owner(ROOT,n,allow_shared=True) for n in family_names()]
        dynamic=next(row for row in json.loads((ROOT/'data/layouts/layouts.json').read_text())['layouts']
            if row['id']=='LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED')
        for row in layouts+[dynamic]:
            index=review._literal_define(ROOT,'include/constants/layouts.h',row['id'])
            self.assertEqual(struct.unpack_from('<I',self.rom,table+4*(index-1))[0],self.address(row['name']))
            for field,suffix in (('border_filepath','_Border'),('blockdata_filepath','_Blockdata')):
                data=(ROOT/row[field]).read_bytes()
                at=self.address(row['name']+suffix)-0x08000000
                self.assertEqual(data,self.rom[at:at+len(data)])
