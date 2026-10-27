"""Bounded Mossdeep source/native regressions, not gameplay certification."""
from pathlib import Path
import copy
import json
import re
import struct
import unittest
try:
    import map_review_script_profile as profile
    import map_semantic_review as review
    import test_map_review_script_profile as native_tests
except ModuleNotFoundError:
    from tools import map_review_script_profile as profile
    from tools import map_semantic_review as review
    from tools import test_map_review_script_profile as native_tests

ROOT=Path(__file__).resolve().parents[1]
CALLBACK_OWNER='MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle'

def parse(body,owner='Entry',waits=None,version=4):
    return profile.profile_block(ROOT,owner+'::\n'+body,waits,version=version,address=0x08000000)

def blocks(suffix):
    return review.label_blocks((ROOT/f'data/maps/MossdeepCity_{suffix}/scripts.inc').read_text())

def script(suffix,label):
    return review.statements(blocks(suffix)['MossdeepCity_'+suffix+'_'+label])

def family_names():
    text=(ROOT/'data/event_scripts.s').read_text()
    start=text.index('\t.include "data/maps/MossdeepCity_Gym/scripts.inc"')
    end=text.index('\t.include "data/maps/SootopolisCity_Gym_1F/scripts.inc"',start)
    names=re.findall(r'\.include "data/maps/(\w+)/scripts.inc"',text[start:end])
    if len(names)!=13 or any(not name.startswith('MossdeepCity_') for name in names):
        raise AssertionError('changed physical Mossdeep family')
    return names

class MossdeepCommandTests(unittest.TestCase):
    def test_double_no_music_flag_selects_mode_not_a_pointer(self):
        body='trainerbattle_double TRAINER_TATE_AND_LIZA_1, Intro, Defeat, NeedTwo, Won, NO_MUSIC\nend'
        part=parse(body)
        self.assertEqual(part.size,23)
        battle=part.trainer_battles[0]
        self.assertEqual((battle['mode'],battle['resume']),
            ('TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC','0x08000016'))
        self.assertEqual(part.texts,dict.fromkeys(('Intro','Defeat','NeedTwo'),'string'))
        self.assertIn('Won',part.targets)
        self.assertNotIn('NO_MUSIC',part.targets)
        for flag in ('TRUE','FALSE','0','Music'):
            with self.subTest(flag=flag),self.assertRaises(ValueError):
                parse(body.replace('NO_MUSIC',flag))

    def test_trainer_setup_does_not_create_a_battle_handoff(self):
        for mode in ('TRAINER_BATTLE_SET_TRAINER_A','TRAINER_BATTLE_SET_TRAINER_B'):
            body=f'trainerbattle {mode}, TRAINER_MAXIE_MOSSDEEP, LOCALID_NONE, Intro, Defeat\nend'
            part=parse(body)
            self.assertEqual((part.size,part.targets,part.trainer_battles),(15,{},[]))
            self.assertEqual(part.texts,{'Intro':'string','Defeat':'string'})
            for changed in (body.replace('LOCALID_NONE','LOCALID_PLAYER'),body.replace('Intro','NULL'),
                            body+'\nend',body.replace('\nend','\nrelease\nend')):
                with self.subTest(body=changed),self.assertRaises(ValueError):
                    parse(changed)

    def test_rotating_tiles_reject_unreviewed_selectors_and_arguments(self):
        self.assertEqual(parse('initrotatingtilepuzzle FALSE').size,3)
        for n in range(5):
            for number in (str(n),hex(n)):
                self.assertEqual(parse('moverotatingtileobjects '+number).size,6)
        for body in ('initrotatingtilepuzzle TRUE','initrotatingtilepuzzle 0',
                     'moverotatingtileobjects 5','moverotatingtileobjects VAR_RESULT',
                     'turnrotatingtileobjects 0','freerotatingtilepuzzle 0'):
            with self.subTest(body=body),self.assertRaises(ValueError):
                parse(body)

    def test_slow_down_is_a_movement_not_a_script_opcode(self):
        self.assertEqual((parse('walk_slow_down\nstep_end').kind,parse('walk_slow_down\nstep_end').size),
            ('movement',2))
        with self.assertRaises(ValueError):
            parse('walk_slow_down 2\nstep_end')

    def test_party_save_uses_the_actual_frontier_special_wait(self):
        wait=profile.special_waits(ROOT)['CallFrontierUtilFunc']
        self.assertEqual((parse('frontier_saveparty').size,parse('frontier_saveparty').specials),
            (8+wait,{'CallFrontierUtilFunc':wait}))
        with self.assertRaises(ValueError):
            parse('frontier_saveparty 1')

    def test_whiteout_exit_is_explicit_and_requires_its_real_wait(self):
        body='fadescreen FADE_TO_BLACK\nspecial SetCB2WhiteOut'
        part=parse(body,owner=CALLBACK_OWNER)
        self.assertEqual((part.context_callback,part.fallthrough,part.may_fall_through),
            ('SetCB2WhiteOut',None,False))
        self.assertIsNone(parse(body).context_callback)
        self.assertTrue(parse(body).may_fall_through)
        for changed in (body+'\nwaitstate',body.replace('FADE_TO_BLACK','FADE_FROM_BLACK')):
            with self.subTest(body=changed),self.assertRaises(ValueError):
                parse(changed,owner=CALLBACK_OWNER)
        with self.assertRaises(ValueError):
            parse(body,owner=CALLBACK_OWNER,waits={'SetCB2WhiteOut':0})

    def test_new_forms_remain_disabled_for_legacy_profiles(self):
        for body in ('initrotatingtilepuzzle FALSE','moverotatingtileobjects 0',
                     'turnrotatingtileobjects','freerotatingtilepuzzle','frontier_saveparty',
                     'warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30','walk_slow_down\nstep_end'):
            with self.subTest(body=body),self.assertRaises(ValueError):
                parse(body,version=3)

    @unittest.skipUnless((ROOT/'tools/preproc/preproc').is_file(),'requires native tools')
    def test_new_forms_match_real_preproc_cpp_assembler_lengths(self):
        samples=['initrotatingtilepuzzle FALSE','turnrotatingtileobjects','freerotatingtilepuzzle',
            'frontier_saveparty','warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30','walk_slow_down',
            'trainerbattle_double TRAINER_TATE_AND_LIZA_1, Intro, Defeat, NeedTwo, Won, NO_MUSIC',
            'trainerbattle TRAINER_BATTLE_SET_TRAINER_A, TRAINER_MAXIE_MOSSDEEP, LOCALID_NONE, Intro, Defeat',
            'trainerbattle TRAINER_BATTLE_SET_TRAINER_B, TRAINER_TABITHA_MOSSDEEP, LOCALID_NONE, Intro, Defeat']
        samples += ['moverotatingtileobjects '+str(n) for n in range(5)]
        native_tests.StoryProfileTests().check_native_forms(samples,version=4)

class MossdeepStoryTests(unittest.TestCase):
    def test_badge_and_space_center_flags_are_set_before_initial_tm_return(self):
        body=script('Gym','EventScript_TateAndLizaDefeated')
        gift=body.index('call MossdeepCity_Gym_EventScript_GiveCalmMind')
        for line in ('setflag FLAG_BADGE07_GET','setvar VAR_0x8008, 7',
                     'setvar VAR_MOSSDEEP_CITY_STATE, 1','setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1'):
            self.assertLess(body.index(line),gift)
        self.assertGreater(body.index('setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL'),gift)
        initial=script('Gym','EventScript_GiveCalmMind')
        retry=script('Gym','EventScript_GiveCalmMind2')
        self.assertEqual(initial[-1],'return')
        self.assertIn('goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull',initial)
        self.assertIn('goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull',retry)

    def test_five_colored_floor_scripts_use_both_upstream_macro_waits(self):
        for n,color in enumerate(('Yellow','Blue','Green','Purple','Red')):
            body=script('Gym','EventScript_'+color+'FloorSwitch')
            self.assertEqual(body[3:],[
                'initrotatingtilepuzzle FALSE','moverotatingtileobjects '+str(n),
                'turnrotatingtileobjects',
                'freerotatingtilepuzzle','end'])
        # Retained RS switches use four persistent flags, not the five colors.
        for n in range(1,5):
            self.assertIn('setflag FLAG_MOSSDEEP_GYM_SWITCH_'+str(n),script('Gym','EventScript_Switch'+str(n)))

    def test_nature_name_buffer_is_reused_only_after_the_species_message(self):
        body=script('House1','EventScript_BlackBelt')
        self.assertLess(body.index('bufferleadmonspeciesname STR_VAR_1'),
            body.index('msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT'))
        self.assertLess(body.index('msgbox MossdeepCity_House1_Text_HmmYourPokemon, MSGBOX_DEFAULT'),
            body.index('specialvar VAR_RESULT, GetPokeblockNameByMonNature'))
        self.assertIn('goto_if_eq VAR_RESULT, 0, MossdeepCity_House1_EventScript_NeutralNature',body)

    def test_wingull_delivery_flag_and_destination_visibility_are_distinct(self):
        body=script('House2','EventScript_Wingull')
        self.assertIn('setflag FLAG_WINGULL_DELIVERED_MAIL',body)
        self.assertIn('clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL',body)
        self.assertIn('removeobject LOCALID_MOSSDEEP_HOUSE_WINGULL',body)
        self.assertNotIn('clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL',body)

    def test_super_rod_is_once_only_and_decline_does_not_mark_receipt(self):
        body=script('House3','EventScript_SuperRodFisherman')
        self.assertLess(body.index('giveitem ITEM_SUPER_ROD'),body.index('setflag FLAG_RECEIVED_SUPER_ROD'))
        self.assertTrue(any(line.startswith('goto_if_eq VAR_RESULT, NO,') for line in body))
        self.assertFalse(any('FLAG_RECEIVED_SUPER_ROD' in line for line in script('House3','EventScript_DeclineSuperRod')))

    def test_beldum_has_party_pc_and_no_space_paths_before_ball_removal(self):
        give=script('StevensHouse','EventScript_GiveBeldum')
        self.assertIn('givemon SPECIES_BELDUM, 5',give)
        self.assertTrue(any(line.startswith('goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY,') for line in give))
        self.assertTrue(any(line.startswith('goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC,') for line in give))
        self.assertIn('goto Common_EventScript_NoMoreRoomForPokemon',give)
        self.assertFalse(any(line.startswith('removeobject ') or 'FLAG_RECEIVED_BELDUM' in line for line in give))
        self.assertIn('removeobject LOCALID_STEVENS_HOUSE_BALL',script('StevensHouse','EventScript_ReceivedBeldumFanfare'))
        self.assertIn('call Common_EventScript_NameReceivedBoxMon',script('StevensHouse','EventScript_SendBeldumPC'))

    def test_dive_receipt_sets_the_note_and_house_state_without_touching_beldum(self):
        body=script('StevensHouse','EventScript_StevenGivesDive')
        self.assertLess(body.index('giveitem ITEM_HM_DIVE'),body.index('setflag FLAG_RECEIVED_HM_DIVE'))
        self.assertIn('setflag FLAG_OMIT_DIVE_FROM_STEVEN_LETTER',body)
        self.assertIn('setvar VAR_STEVENS_HOUSE_STATE, 2',body)
        self.assertFalse(any('BELDUM' in line for line in body))

    def test_sun_stone_success_flag_follows_space_check_in_both_story_states(self):
        for suffix in ('SunStoneMan','SunStoneManMagma'):
            body=script('SpaceCenter_1F','EventScript_'+suffix)
            index=body.index('giveitem ITEM_SUN_STONE')
            self.assertEqual(body[index+1:index+3],[
                'goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull',
                'setflag FLAG_RECEIVED_SUN_STONE_MOSSDEEP'])

    def test_stair_guard_keeps_the_original_repeated_west_case(self):
        body=script('SpaceCenter_1F','EventScript_Grunt2')
        cases=[line for line in body if line.startswith('case ')]
        self.assertEqual(cases,[
            'case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsWest',
            'case DIR_WEST, MossdeepCity_SpaceCenter_1F_EventScript_MoveGruntFromStairsEast'])

    def test_three_grunts_are_sequential_no_intro_battles_not_the_steven_double(self):
        body=script('SpaceCenter_2F','EventScript_BattleThreeMagmaGrunts')
        fights=[line for line in body if line.startswith('trainerbattle_no_intro ')]
        self.assertEqual([line.split(',')[0] for line in fights],
            ['trainerbattle_no_intro TRAINER_GRUNT_SPACE_CENTER_'+str(n) for n in (5,6,7)])
        self.assertGreater(body.index('setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 2'),body.index(fights[-1]))

    def test_party_cancel_restores_party_and_battle_result_branches_before_whiteout(self):
        select=script('SpaceCenter_2F','EventScript_ChoosePartyForMultiBattle')
        self.assertEqual(select[-2:],[
            'special LoadPlayerParty','goto MossdeepCity_SpaceCenter_2F_EventScript_ReadyForBattlePrompt'])
        body=script('SpaceCenter_2F','EventScript_DoStevenMultiBattle')
        index=body.index('special DoSpecialTrainerBattle')
        self.assertEqual(body[index+1:index+4],['frontier_saveparty','special LoadPlayerParty','switch VAR_RESULT'])
        self.assertEqual(body[-3:],[
            'case 1, MossdeepCity_SpaceCenter_2F_EventScript_DefeatedMaxieTabitha',
            'fadescreen FADE_TO_BLACK','special SetCB2WhiteOut'])
        victory=script('SpaceCenter_2F','EventScript_DefeatedMaxieTabitha')
        self.assertEqual(victory[-2:],['fadescreen FADE_FROM_BLACK','end'])
        self.assertNotIn('releaseall',victory)

    def test_rival_call_uses_the_actual_label_not_a_linker_offset(self):
        self.assertNotRegex((ROOT/'ld_script_jp.txt').read_text(),
            r'(?m)^MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall\s*=')
        self.assertIn('MossdeepCity_SpaceCenter_2F_EventScript_RivalRayquazaCall',blocks('SpaceCenter_2F'))
        body=script('SpaceCenter_2F','EventScript_RivalRayquazaCall')
        self.assertEqual(body[-3:],['clearflag FLAG_DEFEATED_MAGMA_SPACE_CENTER','releaseall','end'])

@unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file() and (ROOT/'baserom_jp.gba').is_file(),
                     'requires current JP native artifacts')
class MossdeepNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.symbols,cls.memory=review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        cls.rom=(ROOT/'baserom_jp.gba').read_bytes()
        cls.owners=[]
        for line in (ROOT/'pokeemerald_jp.map').read_text().splitlines():
            row=re.match(r'^\s*(?:\S+\s+)?(0x[0-9a-fA-F]+)\s+(0x[0-9a-fA-F]+)\s+(\S+\.o)\s*$',line)
            if row:
                cls.owners.append((int(row[1],16),int(row[2],16),row[3].replace('\\','/')))

    def address(self,label):
        self.assertEqual(len(self.symbols[label]),1,label)
        return next(iter(self.symbols[label]))

    def native(self):
        return dict(symbols=self.symbols,owners=self.owners,rom=self.rom)

    def test_thirteen_physical_owners_are_contiguous_and_measure_every_label(self):
        names=family_names()
        self.assertEqual(self.address(names[0]+'_MapScripts'),0x0820B369)
        self.assertEqual(self.address('SootopolisCity_Gym_1F_MapScripts'),0x0820E224)
        count=0
        for name,following in zip(names,names[1:]+['SootopolisCity_Gym_1F']):
            at=self.address(name+'_MapScripts')
            profiles=profile.profile_owner(ROOT,(ROOT/f'data/maps/{name}/scripts.inc').read_text(),version=4,address=at)
            for label,part in profiles.items():
                self.assertEqual(self.address(label),at,label)
                self.assertFalse(part.may_fall_through and not part.fallthrough,label)
                at+=part.size
            self.assertEqual(at,self.address(following+'_MapScripts'))
            count+=len(profiles)
        self.assertEqual(count,343)

    def test_all_150_jp_texts_match_original_controls_and_native_boundaries(self):
        count=0
        for name in family_names():
            for label,block in review.label_blocks((ROOT/f'data/maps/{name}/scripts.inc').read_text()).items():
                if review.text_kind(block)!='string':
                    continue
                encoded=review.encoded_text(ROOT,block,'string')
                at=self.address(label)-0x08000000
                self.assertEqual(encoded,self.rom[at:at+len(encoded)],label)
                self.assertTrue(encoded.endswith(b'\xff'),label)
                count+=1
        self.assertEqual(count,150)

    def test_callback_has_native_setter_and_context_reset_not_a_fallthrough(self):
        errors=[]
        review._context_callback_native({'callback_exits':[{'entry':CALLBACK_OWNER,'special':'SetCB2WhiteOut'}]},
            self.native(),errors)
        self.assertEqual(errors,[])

    def test_changed_callback_literal_and_reset_call_are_rejected(self):
        batch={'callback_exits':[{'entry':CALLBACK_OWNER,'special':'SetCB2WhiteOut'}]}
        rom=bytearray(self.rom)
        at=(self.address('SetCB2WhiteOut')&~1)-0x08000000
        literal=struct.pack('<I',self.address('CB2_WhiteOut')|1)
        offset=rom.index(literal,at,at+0x14)
        rom[offset:offset+4]=bytes(4)
        data=self.native()|{'rom':bytes(rom)}
        errors=[]
        review._context_callback_native(batch,data,errors)
        self.assertIn('native_context_callback_setter_mismatch',errors)
        data=self.native()|{'symbols':copy.deepcopy(self.symbols)}
        data['symbols']['ScriptContext_Init']={self.address('ScriptContext_Init')+4}
        data['symbols'].pop('ScriptContext1_Init',None)
        errors=[]
        review._context_callback_native(batch,data,errors)
        self.assertIn('native_context_callback_missing_init_call',errors)

    def test_trainer_setup_headers_bind_the_actual_two_text_pointers(self):
        handlers=re.findall(r'(?m)^\s*script_cmd_table_entry\s+\w+\s+(\w+)\s*(?:@[^\n]*)?$',
            (ROOT/'data/script_cmd_table.inc').read_text())
        opcode=handlers.index('ScrCmd_trainerbattle')
        for suffix,mode,trainer,text in (
            ('Maxie',10,'TRAINER_MAXIE_MOSSDEEP','MossdeepCity_SpaceCenter_2F_Text_JustWantToExpandLand'),
            ('Tabitha',11,'TRAINER_TABITHA_MOSSDEEP','MossdeepCity_SpaceCenter_Text_TabithaDefeat')):
            at=self.address('MossdeepCity_SpaceCenter_2F_EventScript_'+suffix+'Trainer')-0x08000000
            trainer_id=review._literal_define(ROOT,'include/constants/opponents.h',trainer)
            expected=struct.pack('<BBHHII',opcode,mode,trainer_id,0,self.address(text),self.address(text))+b'\x02'
            self.assertEqual(self.rom[at:at+15],expected)

    def test_mart_sentinel_includes_its_executable_release_end_tail(self):
        at=self.address('MossdeepCity_Mart_Pokemart')
        self.assertEqual(at%4,0)
        part=profile.profile_block(ROOT,blocks('Mart')['MossdeepCity_Mart_Pokemart'],version=4,address=at)
        self.assertEqual((part.kind,part.size),('mart_items',22))
        offset=at-0x08000000
        self.assertEqual(self.rom[offset+18:offset+22],b'\0\0\x6c\x02')

    def test_layout_headers_and_assets_use_their_real_shared_owners(self):
        table=self.address('gMapLayouts')-0x08000000
        for name in family_names():
            layout=review.default_layout_owner(ROOT,name,allow_shared=True)
            index=review._literal_define(ROOT,'include/constants/layouts.h',layout['id'])
            header=self.address(name)-0x08000000
            self.assertEqual(struct.unpack_from('<I',self.rom,header)[0],self.address(layout['name']))
            self.assertEqual(struct.unpack_from('<H',self.rom,header+18)[0],index)
            self.assertEqual(struct.unpack_from('<I',self.rom,table+4*(index-1))[0],self.address(layout['name']))
            for field,suffix in (('border_filepath','_Border'),('blockdata_filepath','_Blockdata')):
                payload=(ROOT/layout[field]).read_bytes()
                at=self.address(layout['name']+suffix)-0x08000000
                self.assertEqual(payload,self.rom[at:at+len(payload)],name)
