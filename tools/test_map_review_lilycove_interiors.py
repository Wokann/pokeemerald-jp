"""Bounded Lilycove command forms; passing these does not approve a map."""
from pathlib import Path
import json
import re
import struct
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

def parse(source, version=4):
    return profile.profile_block(ROOT,'Entry::\n'+source,version=version,address=0x08000000)

def blocks(path):
    return review.label_blocks((ROOT/path).read_text())

def script(map_suffix, label_suffix):
    name = 'LilycoveCity_' + map_suffix
    return review.statements(blocks(f'data/maps/{name}/scripts.inc')[name+'_'+label_suffix])

def shared(label):
    return review.statements(blocks('data/scripts/lilycove_lady.inc')[
        'LilycoveCity_PokemonCenter_1F_EventScript_'+label])

def c_function(path, name):
    source = (ROOT/path).read_text()
    match = re.search(r'(?ms)^[^\n;{}]*\b'+re.escape(name)+r'\([^;{}]*\)\n\{(.*?)^\}',source)
    if not match:
        raise AssertionError('missing bounded function '+name)
    return match[1]

def family_names():
    source = (ROOT/'data/event_scripts.s').read_text()
    first = source.index('\t.include "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.inc"')
    last = source.index('\t.include "data/maps/MossdeepCity_Gym/scripts.inc"',first)
    names = re.findall(r'\.include "data/maps/(\w+)/scripts.inc"',source[first:last])
    if len(names)!=23 or any(not name.startswith('LilycoveCity_') for name in names):
        raise AssertionError('changed physical Lilycove family')
    return names

class LilycoveCommandProfileTests(unittest.TestCase):
    def test_only_the_observed_warning_suppressed_copy_form_is_supported(self):
        self.assertEqual(parse('copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE').size, 5)
        for source in ('copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 2, warn=FALSE',
                       'copyvar VAR_RESULT, 1, warn=FALSE',
                       'copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=TRUE',
                       'copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=0'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                parse(source)

    def test_exact_nonfan_comparison_does_not_enable_general_expression_evaluation(self):
        source = 'goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), Target'
        self.assertEqual((parse(source).size, parse(source).targets), (11, {'Target':'script'}))
        for changed in (source.replace('VAR_RESULT','VAR_0x8004'), source.replace(' - 1',' - 2'),
                        source.replace('goto_if_eq','goto_if_ge'), source.replace(' - 1',' + -1')):
            with self.subTest(source=changed), self.assertRaises(ValueError):
                parse(changed)

    def test_painting_selector_set_excludes_unused_hall_slots_and_raw_numbers(self):
        self.assertEqual(len(profile.CONTEST_PAINTING_SELECTORS), 12)
        for selector in profile.CONTEST_PAINTING_SELECTORS:
            self.assertEqual(parse('showcontestpainting '+selector).size, 2)
        for selector in ('0','255','CONTEST_WINNER_HALL_UNUSED_1','CONTEST_WINNER_HALL_7','VAR_RESULT','CONTEST_WINNER_UNKNOWN'):
            with self.subTest(selector=selector), self.assertRaises(ValueError):
                parse('showcontestpainting '+selector)

    def test_contest_selection_and_link_transfer_are_single_builtin_opcodes(self):
        for op in ('choosecontestmon','contestlinktransfer'):
            part = parse(op)
            self.assertEqual((part.size,part.specials,part.context_warp), (1,{},None))
            with self.assertRaises(ValueError):
                parse(op+' VAR_RESULT')

    def test_lady_mon_jump_is_a_terminated_five_action_movement(self):
        source = '\n'.join(['disable_jump_landing_ground_effect','jump_in_place_left']*2+['step_end'])
        part = parse(source)
        self.assertEqual((part.kind,part.size), ('movement',5))
        with self.assertRaises(ValueError):
            parse('jump_in_place_left 1\nstep_end')

    @unittest.skipUnless((ROOT/'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_blender_variable_context_uses_the_real_nonaddress_owner_alias(self):
        declaration = (ROOT/'data/scripts/berry_blender.inc').read_text().splitlines()[0]
        self.assertEqual(declaration,'.set NUM_OPPONENTS, VAR_0x8009')
        if (ROOT/'pokeemerald_jp.elf').is_file():
            symbols = subprocess.check_output([
                str(ROOT/'tools/binutils/bin/arm-none-eabi-nm'), '--defined-only',
                str(ROOT/'pokeemerald_jp.elf')], text=True)
            values = [int(value,16) for value in re.findall(
                r'^([0-9a-fA-F]+) [aA] NUM_OPPONENTS$', symbols, re.M)]
            self.assertEqual(values,[review._literal_define(ROOT,'include/constants/vars.h','VAR_0x8009')])
        native_tests.StoryProfileTests().check_native_forms([
            'setvar NUM_OPPONENTS, 1','copyvar VAR_0x8004, NUM_OPPONENTS'],
            version=4,source_prefix=declaration)

    def test_instant_message_tracks_a_real_static_text_not_runtime_buffer_or_null(self):
        label = 'LilycoveCity_ContestLobby_Text_Transmitting'
        part = parse('messageinstant '+label)
        self.assertEqual((part.size,part.texts), (5,{label:'string'}))
        for value in ('NULL','gStringVar4','0x08200000'):
            with self.subTest(value=value), self.assertRaises(ValueError):
                parse('messageinstant '+value)

    def test_results_default_uses_only_the_observed_facility_and_real_special_wait(self):
        part = parse('frontier_results FACILITY_LINK_CONTEST')
        wait = profile.special_waits(ROOT)['CallFrontierUtilFunc']
        self.assertEqual((part.size,part.specials), (13+wait,{'CallFrontierUtilFunc':wait}))
        for args in ('FACILITY_LINK_CONTEST, 0','FACILITY_LINK_CONTEST, 0xFF','FACILITY_TOWER','VAR_RESULT'):
            with self.subTest(args=args), self.assertRaises(ValueError):
                parse('frontier_results '+args)

    def test_decoration_two_retains_the_decoration_table_type(self):
        part = parse('pokemartdecoration2 Stock')
        self.assertEqual((part.size,part.targets), (5,{'Stock':'mart_decorations'}))
        with self.assertRaises(ValueError):
            parse('pokemartdecoration2 Stock, 1')

    def test_setting_dynamic_warp_does_not_replace_the_current_script_context(self):
        for floor in range(1,6):
            part = parse(f'setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_{floor}F, 0x2, 0x1')
            self.assertEqual((part.size,part.context_warp,part.may_fall_through), (8,None,True))
        for source in ('setdynamicwarp MAP_LILYCOVE_CITY, 1','setdynamicwarp Map, 2, 1',
                       'setdynamicwarp MAP_LILYCOVE_CITY, 65536, 1','setdynamicwarp MAP_LILYCOVE_CITY, -1, 1'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                parse(source)

    def test_new_forms_are_not_silently_enabled_for_legacy_review_versions(self):
        for source in ('choosecontestmon','contestlinktransfer','showcontestpainting CONTEST_WINNER_ARTIST',
                       'messageinstant Text','pokemartdecoration2 Stock','frontier_results FACILITY_LINK_CONTEST',
                       'copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE',
                       'goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), Target',
                       'setdynamicwarp MAP_LILYCOVE_CITY, 2, 1'):
            with self.subTest(source=source), self.assertRaises(ValueError):
                parse(source,version=3)

    @unittest.skipUnless((ROOT/'tools/preproc/preproc').is_file(), 'requires native tools')
    def test_all_new_observed_forms_match_real_preproc_cpp_assembler_lengths(self):
        samples = ['copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE',
                   'goto_if_eq VAR_RESULT, (NUM_TRAINER_FAN_CLUB_MEMBERS - 1), Target',
                   'choosecontestmon','contestlinktransfer','jump_in_place_left',
                   'messageinstant LilycoveCity_ContestLobby_Text_Transmitting',
                   'frontier_results FACILITY_LINK_CONTEST','pokemartdecoration2 Stock']
        samples += ['showcontestpainting '+name for name in sorted(profile.CONTEST_PAINTING_SELECTORS)]
        samples += [f'setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_{floor}F, 0x2, 0x1' for floor in range(1,6)]
        native_tests.StoryProfileTests().check_native_forms(samples,version=4)

class LilycoveStoryTests(unittest.TestCase):
    def test_motel_story_priority_and_tv_coordinate_trigger_are_distinct(self):
        body = script('CoveLilyMotel_1F','EventScript_MotelOwner')
        self.assertIn('FLAG_SYS_GAME_CLEAR',body[1])
        self.assertIn('FLAG_BADGE07_GET',body[2])
        trigger = json.loads((ROOT/'data/maps/LilycoveCity_CoveLilyMotel_1F/map.json').read_text())['coord_events']
        self.assertEqual([(e['x'],e['y'],e['elevation'],e['var'],e['var_value']) for e in trigger],
                         [(10,2,3,'VAR_TEMP_1','0')])
        push = script('CoveLilyMotel_1F','EventScript_BlockingTV')
        self.assertEqual(push[-2:],['release','end'])
        self.assertIn('waitmovement 0',push)

    def test_diploma_call_ends_instead_of_returning_and_scott_advances_once(self):
        body = script('CoveLilyMotel_2F','EventScript_GameDesigner')
        self.assertIn('call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma',body)
        diploma = script('CoveLilyMotel_2F','EventScript_ShowDiploma')
        self.assertEqual(diploma[-3:],['special Special_ShowDiploma','release','end'])
        self.assertNotIn('return',diploma)
        self.assertIn('specialvar VAR_RESULT, HasAllHoennMons',body)
        self.assertIn('addvar VAR_SCOTT_STATE, 1',script('CoveLilyMotel_2F','EventScript_Scott'))
        self.assertFalse(any(line.startswith('addvar ') for line in script('CoveLilyMotel_2F','EventScript_MetScott')))

    def test_museum_copy_is_not_a_setvar_and_decoration_flag_waits_for_success(self):
        self.assertIn('copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE',
                      script('LilycoveMuseum_2F','EventScript_ShowExhibitHall'))
        self.assertIn('copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 1, warn=FALSE',
                      script('ContestLobby','EventScript_SetDebug'))
        gift = script('LilycoveMuseum_2F','EventScript_GiveGlassOrnament')
        index = gift.index('givedecoration DECOR_GLASS_ORNAMENT')
        self.assertTrue(gift[index+1].startswith('goto_if_eq VAR_RESULT, FALSE,'))
        self.assertEqual(gift[index+2],'setflag FLAG_RECEIVED_GLASS_ORNAMENT')

    def test_painting_artist_selector_is_not_a_saved_winner_index(self):
        handler = c_function('src/scrcmd.c','ScrCmd_showcontestpainting')
        self.assertIn('if (a != 0)',handler)
        self.assertIn('SetContestWinnerForPainting(a);',handler)
        self.assertIn('ShowContestPainting();',handler)
        self.assertIn('ScriptContext_Stop();',handler)
        public_entry = c_function('src/contest_util.c','ShowContestPainting')
        self.assertIn('gMain.savedCallback = ExitContestPainting;',public_entry)
        self.assertIn('CB2_ReturnToFieldContinueScriptPlayMapMusic',
                      c_function('src/contest_util.c','ExitContestPainting'))

    def test_instant_message_draws_without_becoming_the_link_wait(self):
        handler = c_function('src/scrcmd.c','ScrCmd_messageinstant')
        self.assertIn('return FALSE;',handler)
        self.assertNotIn('ScriptContext_Stop',handler)
        self.assertIn('(const u8 *)text, 0, 2, 0, NULL',handler)
        for op in ('choosecontestmon','contestlinktransfer'):
            handler = c_function('src/scrcmd.c','ScrCmd_'+op)
            self.assertIn('ScriptContext_Stop();',handler)
            self.assertIn('return TRUE;',handler)
        labels = blocks('data/maps/LilycoveCity_ContestLobby/scripts.inc')
        self.assertEqual(sum('messageinstant LilycoveCity_ContestLobby_Text_Transmitting' in block
                             for block in labels.values()),2)

    def test_selection_cancel_is_in_8004_before_qualification_result(self):
        source = blocks('data/scripts/contest_hall.inc')
        body = review.statements(source['LilycoveCity_ContestLobby_EventScript_ChooseContestMon'])
        index = body.index('choosecontestmon')
        self.assertEqual(body[index+1:index+3],[
            'goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_ContestLobby_EventScript_CancelEnterContest',
            'special TryEnterContestMon'])

    def test_lady_reward_retry_and_custom_question_commit_are_separate(self):
        prize = shared('GivePrize')
        self.assertLess(prize.index('special SetQuizLadyState_Complete'),prize.index('giveitem VAR_0x8005'))
        self.assertIn('special SetQuizLadyState_GivePrize',shared('NoSpaceForQuizPrize'))
        self.assertEqual(shared('FinishMakingQuiz')[:3],[
            'special QuizLadyTakePrizeForCustomQuiz','special QuizLadyRecordCustomQuizData',
            'special QuizLadySetWaitingForChallenger'])
        self.assertIn('special Script_QuizLadyOpenBagMenu',shared('PickPrize'))
        self.assertIn('special QuizLadySetCustomQuestion',shared('WriteQuizQuestion'))

    def test_fan_threshold_counts_fans_not_nonfans_and_interview_preserves_slot(self):
        body = script('PokemonTrainerFanClub','EventScript_CheckSetUpTVShow')
        self.assertEqual(body[0],'setvar VAR_0x8005, NUM_TRAINER_FAN_CLUB_MEMBERS')
        self.assertEqual(sum('specialvar VAR_RESULT, IsFanClubMemberFanOfPlayer'==line for line in body),8)
        self.assertEqual(script('PokemonTrainerFanClub','EventScript_CountNotPlayersFan'),['subvar VAR_0x8005, 1','return'])
        self.assertIn('goto_if_ge VAR_0x8005, 5, LilycoveCity_PokemonTrainerFanClub_EventScript_TrySetUpTVShow',body)
        interview = script('PokemonTrainerFanClub','EventScript_Interview')
        self.assertIn('copyvar VAR_0x800A, VAR_0x8006',interview)
        self.assertIn('copyvar VAR_0x8005, VAR_0x800A',interview)

    def test_harbor_enable_item_and_first_show_states_are_not_interchangeable(self):
        body = script('Harbor','EventScript_FerryAttendant')
        self.assertIn('FLAG_SYS_GAME_CLEAR',body[2])
        first = next(line for line in body if line.startswith('goto_if_eq '))
        self.assertEqual(first,'goto_if_eq VAR_TEMP_C, 2, LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime')
        for suffix,item,flag in [('EonTicket','EON_TICKET','SOUTHERN_ISLAND'),
                                 ('AuroraTicket','AURORA_TICKET','BIRTH_ISLAND'),
                                 ('OldSeaMap','OLD_SEA_MAP','FARAWAY_ISLAND'),
                                 ('MysticTicket','MYSTIC_TICKET','NAVEL_ROCK')]:
            state = script('Harbor','EventScript_Get'+suffix+'State')
            self.assertIn('FLAG_ENABLE_SHIP_'+flag,state[1])
            self.assertEqual(state[2],'checkitem ITEM_'+item)
        menu = script('Harbor','EventScript_FerryRegularLocationSelect')
        self.assertTrue(any(line.startswith('case MULTI_B_PRESSED,') for line in menu))

    def test_move_deleter_rejects_cancel_egg_one_move_and_last_surf(self):
        body = script('MoveDeletersHouse','EventScript_ChooseMonAndMoveToForget')
        self.assertTrue(any(line.startswith('goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN,') for line in body))
        self.assertIn('special IsSelectedMonEgg',body)
        self.assertTrue(any(line.startswith('goto_if_eq VAR_RESULT, 1,') for line in body))
        self.assertTrue(any(line.startswith('goto_if_eq VAR_0x8005, MAX_MON_MOVES,') for line in body))
        forget = script('MoveDeletersHouse','EventScript_TryForgetMove')
        self.assertEqual(forget[0],'special IsLastMonThatKnowsSurf')
        self.assertLess(1,forget.index('special MoveDeleterForgetMove'))

    def test_rest_receipt_and_quadruplet_shared_random_choice(self):
        gift = script('House2','EventScript_FatMan')
        index = gift.index('giveitem ITEM_TM_REST')
        self.assertTrue(gift[index+1].startswith('goto_if_eq VAR_RESULT, FALSE,'))
        self.assertEqual(gift[index+2],'setflag FLAG_RECEIVED_TM_REST')
        self.assertEqual(script('House3','OnTransition'),['random 4','copyvar VAR_TEMP_1, VAR_RESULT','end'])
        selections = [script('House3',f'EventScript_GameBoyKid{i}')[2:] for i in range(1,5)]
        self.assertTrue(all(body==selections[0] for body in selections))

    def test_lottery_defers_prize_without_consuming_it_on_full_bag_retry(self):
        body = script('DepartmentStore_1F','EventScript_LotteryClerk')
        self.assertIn('VAR_POKELOT_PRIZE_ITEM',body[3])
        self.assertIn('FLAG_DAILY_PICKED_LOTO_TICKET',body[4])
        retry = script('DepartmentStore_1F','EventScript_GivePrizeFromEarlier')
        grant = retry.index('giveitem VAR_POKELOT_PRIZE_ITEM')
        clear = retry.index('setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE')
        self.assertTrue(retry[grant+1].startswith('goto_if_eq VAR_RESULT, FALSE,'))
        self.assertGreater(clear,grant+1)

    def test_four_decoration_shop2_stocks_differ_from_rooftop_shop1(self):
        for suffix,count in [('Dolls',12),('Cushions',9),('Posters',9),('Mats',10)]:
            stock = script('DepartmentStore_5F','Pokemart_'+suffix)
            self.assertEqual(sum(line.startswith('.2byte DECOR_') for line in stock),count)
            self.assertEqual(stock[-1],'pokemartlistend')
        five = (ROOT/'data/maps/LilycoveCity_DepartmentStore_5F/scripts.inc').read_text()
        self.assertEqual(five.count('\tpokemartdecoration2 '),4)
        self.assertIn('CreateDecorationShop2Menu(ptr);',c_function('src/scrcmd.c','ScrCmd_pokemartdecoration2'))
        roof = script('DepartmentStoreRooftop','EventScript_SaleWoman')
        self.assertIn('pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale',roof)

    def test_roof_weather_gate_and_paid_then_bonus_vending_paths(self):
        hooks = script('DepartmentStore_5F','OnWarp')
        self.assertEqual([line.split(', ')[1] for line in hooks[:-1]],['1','2','3'])
        body = script('DepartmentStoreRooftop','EventScript_TryBuyDrink')
        first_charge = next(i for i,line in enumerate(body) if '_RemoveMoneyFreshWater' in line)
        self.assertLess(body.index('checkitemspace VAR_TEMP_0'),first_charge)
        self.assertEqual(body.count('random 64'),2)
        self.assertEqual(body.count('checkitemspace VAR_TEMP_0'),3)
        self.assertEqual(body.count('additem VAR_TEMP_0'),3)
        self.assertEqual(script('DepartmentStoreRooftop','EventScript_ExitVendingMachine'),['hidemoneybox','releaseall','end'])

    def test_elevator_stores_coordinate_destination_before_same_floor_exit(self):
        suffixes=['1st','2nd','3rd','4th','5th']
        for i,suffix in enumerate(suffixes,1):
            body = script('DepartmentStoreElevator','EventScript_'+suffix+'Floor')
            self.assertEqual(body[1],f'setdynamicwarp MAP_LILYCOVE_CITY_DEPARTMENT_STORE_{i}F, 0x2, 0x1')
            self.assertTrue(body[2].startswith('goto_if_eq VAR_DEPT_STORE_FLOOR,'))
            self.assertEqual(body[3],'call LilycoveCity_DepartmentStoreElevator_EventScript_MoveElevator')
        self.assertEqual(script('DepartmentStoreElevator','EventScript_ExitFloorSelect'),
                         ['special CloseDeptStoreElevatorWindow','release','end'])

    def test_unused_mart_and_center_hooks_keep_shared_owners(self):
        self.assertEqual(script('UnusedMart','MapScripts'),['.byte 0'])
        metadata = json.loads((ROOT/'data/maps/LilycoveCity_UnusedMart/map.json').read_text())
        self.assertEqual(metadata['object_events'],[])
        self.assertEqual(len(metadata['warp_events']),2)
        self.assertEqual(sum(line.startswith('map_script ') for line in script('PokemonCenter_2F','MapScripts')),4)
        self.assertEqual(script('PokemonCenter_1F','OnTransition')[0],'setrespawn HEAL_LOCATION_LILYCOVE_CITY')

@unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(), 'requires native artifacts')
class LilycoveNativeTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.symbols,cls.memory = review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        cls.rom = (ROOT/'baserom_jp.gba').read_bytes()

    def address(self,label):
        self.assertEqual(len(self.symbols[label]),1,label)
        return next(iter(self.symbols[label]))

    def test_all_twenty_three_local_owners_are_contiguous_and_fully_profiled(self):
        count,size,texts = 0,0,0
        names = family_names()
        self.assertEqual(self.address(names[0]+'_MapScripts'),0x082054FC)
        self.assertEqual(self.address('MossdeepCity_Gym_MapScripts'),0x0820B369)
        for i,name in enumerate(names):
            start = self.address(name+'_MapScripts')
            following = names[i+1] if i+1<len(names) else 'MossdeepCity_Gym'
            parts = profile.profile_owner(ROOT,(ROOT/f'data/maps/{name}/scripts.inc').read_text(),version=4,address=start)
            length = sum(part.size for part in parts.values())
            self.assertEqual(start+length,self.address(following+'_MapScripts'))
            self.assertFalse(any(part.may_fall_through for part in parts.values()))
            count,size,texts = count+len(parts),size+length,texts+sum(part.kind=='string' for part in parts.values())
        self.assertEqual((count,size,texts),(748,24173,216))

    def test_all_four_lady_fallthrough_edges_require_native_adjacency(self):
        source = blocks('data/scripts/lilycove_lady.inc')
        for left,right in [('MonEnjoyPokeblock','FinishFeedPokeblock'),('MakeQuiz','PickPrize'),
                           ('TakeQuiz','CheckQuizTakingState'),('WriteQuiz','WriteQuizQuestion')]:
            prefix = 'LilycoveCity_PokemonCenter_1F_EventScript_'
            start = self.address(prefix+left)
            part = profile.profile_block(ROOT,source[prefix+left],version=4,address=start)
            self.assertTrue(part.may_fall_through)
            self.assertEqual(part.fallthrough,prefix+right)
            self.assertEqual(part.targets[prefix+right],'script')
            self.assertEqual(start+part.size,self.address(prefix+right))

    def test_department_store_wandering_npc_is_the_actual_jp_event_byte(self):
        name = 'LilycoveCity_DepartmentStore_1F'
        metadata = json.loads((ROOT/f'data/maps/{name}/map.json').read_text())
        npc = metadata['object_events'][4]
        self.assertEqual(npc['script'],name+'_EventScript_PokefanM')
        self.assertEqual(npc['movement_type'],'MOVEMENT_TYPE_WANDER_AROUND')
        value = review._literal_define(ROOT,'include/constants/event_object_movement.h',npc['movement_type'])
        base = self.address(name+'_ObjectEvents')-0x08000000
        self.assertEqual(self.rom[base+4*24+9],value)

    def test_all_local_texts_keep_exact_jp_boundaries_and_controls(self):
        count,size = 0,0
        for name in family_names():
            for label,block in blocks(f'data/maps/{name}/scripts.inc').items():
                if review.text_kind(block)!='string':
                    continue
                data = review.encoded_text(ROOT,block,'string')
                start = self.address(label)-0x08000000
                self.assertEqual(data,self.rom[start:start+len(data)],label)
                self.assertTrue(data.endswith(b'\xff'))
                count,size = count+1,size+len(data)
        self.assertEqual((count,size),(216,12402))

    def test_reviewed_interview_placeholder_names_change_no_bytes(self):
        count,uses = 0,0
        for path,prefix,slot in [('data/text/tv/contest_interview.inc','LilycoveCity_ContestLobby_',2),
                                 ('data/text/tv/trainer_fan_club.inc','LilycoveCity_PokemonTrainerFanClub_',1)]:
            for label,block in blocks(path).items():
                if not label.startswith(prefix) or '{STR_VAR_'+str(slot)+'}' not in block:
                    continue
                self.assertNotIn('B_COPY_VAR',block)
                data = review.encoded_text(ROOT,block,'string')
                old = block.replace('{STR_VAR_'+str(slot)+'}','{B_COPY_VAR_'+str(slot)+'}')
                self.assertEqual(data,review.encoded_text(ROOT,old,'string'))
                start = self.address(label)-0x08000000
                self.assertEqual(data,self.rom[start:start+len(data)])
                count,uses = count+1,uses+block.count('{STR_VAR_'+str(slot)+'}')
        self.assertEqual((count,uses),(10,12))
        table = self.address('gTVStringVarPtrs')-0x08000000
        # native_elf intentionally exposes ROM owners, not EWRAM buffers.
        symbols,_ = review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes(),include_ram=True)
        buffers = []
        for i in range(1,4):
            values = list(symbols['gStringVar'+str(i)])
            self.assertEqual(len(values),1)
            self.assertTrue(0x02000000<=values[0]<0x02040000)
            buffers.append(values[0])
        self.assertEqual(struct.unpack_from('<III',self.rom,table),
                         tuple(buffers))

    def test_all_layout_ids_and_shared_owners_point_to_the_real_resources(self):
        for name in family_names():
            row = review.default_layout_owner(ROOT,name,allow_shared=True)
            index = review._literal_define(ROOT,'include/constants/layouts.h',row['id'])
            start = self.address(name)-0x08000000
            target = self.address(row['name'])
            self.assertEqual(struct.unpack_from('<I',self.rom,start)[0],target)
            self.assertEqual(struct.unpack_from('<H',self.rom,start+18)[0],index)
            table = self.address('gMapLayouts')-0x08000000+4*(index-1)
            self.assertEqual(struct.unpack_from('<I',self.rom,table)[0],target)
            for field,suffix in [('border_filepath','_Border'),('blockdata_filepath','_Blockdata')]:
                data = (ROOT/row[field]).read_bytes()
                at = self.address(row['name']+suffix)-0x08000000
                self.assertEqual(data,self.rom[at:at+len(data)],row[field])

    def test_sale_stock_terminator_tail_is_not_two_more_merchandise_entries(self):
        label = 'LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale'
        start = self.address(label)-0x08000000
        self.assertEqual(self.rom[start+14*2:start+14*2+4],b'\0\0\x6c\x02')

if __name__=='__main__':
    unittest.main()
