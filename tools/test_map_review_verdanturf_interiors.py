"""Verdanturf Tent, Wally state and seven friendship categories."""
import json
from pathlib import Path
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
MAPS = ['VerdanturfTown_BattleTentLobby', 'VerdanturfTown_BattleTentCorridor', 'VerdanturfTown_BattleTentBattleRoom',
        'VerdanturfTown_Mart', 'VerdanturfTown_PokemonCenter_1F', 'VerdanturfTown_PokemonCenter_2F',
        'VerdanturfTown_WandasHouse', 'VerdanturfTown_FriendshipRatersHouse', 'VerdanturfTown_House']
SIZES = [(52,1965,7), (10,403,4), (24,642,0), (9,250,3), (7,189,2), (4,39,0),
         (26,1105,12), (19,553,9), (5,171,2)]


def blocks(name):
    return review.label_blocks((ROOT/f'data/maps/{name}/scripts.inc').read_text())


def scene(name, suffix):
    return review.statements(blocks(name)[name+'_'+suffix])


class VerdanturfFormTests(unittest.TestCase):
    def test_new_selector_forms_use_the_actual_verdanturf_dispatcher(self):
        forms = {'verdanturftent_init':8, 'verdanturftent_getprize':8, 'verdanturftent_save 0':13,
                 'verdanturftent_save CHALLENGE_STATUS_SAVING':13,
                 'verdanturftent_save CHALLENGE_STATUS_PAUSED':13,
                 'verdanturftent_setrandomprize':8, 'verdanturftent_giveprize':8}
        for text,size in forms.items():
            for wait in (0,1):
                p = profile.profile_block(ROOT,'Entry::\n'+text,{'CallVerdanturfTentFunction':wait},
                                          version=4,address=0x081F6365)
                self.assertEqual((p.size,p.specials),(size+wait,{'CallVerdanturfTentFunction':wait}))
        if (ROOT/'tools/preproc/preproc').is_file():
            for waits in (None,{'CallVerdanturfTentFunction':1}):
                native_forms.StoryProfileTests().check_native_forms(sorted(forms),forced_waits=waits,version=4)

    def test_wrong_arguments_handlers_and_legacy_version_fail_closed(self):
        for text in ('verdanturftent_init 1','verdanturftent_save','verdanturftent_save VAR_RESULT',
                     'verdanturftent_save 0, 1','verdanturftent_getprize ITEM_NONE'):
            with self.subTest(text=text), self.assertRaises(ValueError):
                profile.profile_block(ROOT,'Entry::\n'+text,version=4,address=0x081F6365)
        for waits in ({},{'CallFallarborTentFunction':0},{'CallVerdanturfTentFunction':2}):
            with self.assertRaises(ValueError):
                profile.profile_block(ROOT,'Entry::\nverdanturftent_init',waits,version=4,address=0x081F6365)
        with self.assertRaises(ValueError):
            profile.profile_block(ROOT,'Entry::\nverdanturftent_init',version=3)


class VerdanturfStoryTests(unittest.TestCase):
    def test_palace_entry_and_jp_player_gfx_only(self):
        start = scene(MAPS[0],'EventScript_TryEnterChallenge')
        self.assertEqual(start[0],'setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE')
        self.assertIn('goto_if_eq VAR_0x8004, TRUE, VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMons',start)
        battle = scene(MAPS[2],'EventScript_NextOpponentEnter')
        at = battle.index('battletent_getopponentintro')
        self.assertEqual(battle[at+1],'msgbox gStringVar4, MSGBOX_DEFAULT')
        self.assertIn('call BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle',battle)
        for gender,graphics in (('Male','BRENDAN'),('Female','MAY')):
            self.assertEqual(scene(MAPS[2],'EventScript_SetPlayerGfx'+gender),[
                'setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_RIVAL_'+graphics+'_NORMAL','return'])

    def test_prize_and_attract_bag_full_paths_keep_pending_state(self):
        prize = scene(MAPS[0],'EventScript_GivePrize')
        at = prize.index('verdanturftent_giveprize')
        self.assertEqual(prize[at+1:at+3],['switch VAR_RESULT','case FALSE, VerdanturfTown_BattleTentLobby_EventScript_NoRoomForPrize'])
        failed = scene(MAPS[0],'EventScript_NoRoomForPrize')
        self.assertFalse(any('FRONTIER_DATA_CHALLENGE_STATUS' in line for line in failed))
        give = scene(MAPS[0],'EventScript_AttractGiver')
        at = give.index('giveitem ITEM_TM_ATTRACT')
        self.assertEqual(give[at+1],'goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull')
        self.assertGreater(give.index('setflag FLAG_RECEIVED_TM_ATTRACT'),at+1)

    def test_wally_house_story_priority_and_one_time_speech(self):
        wally = scene(MAPS[6],'EventScript_Wally')
        self.assertEqual(wally[2],'goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech')
        self.assertIn('setflag FLAG_WALLY_SPEECH',wally)
        uncle = scene(MAPS[6],'EventScript_WallysUncle')
        aunt = scene(MAPS[6],'EventScript_WallysAunt')
        self.assertIn('FLAG_DEFEATED_WALLY_VICTORY_ROAD',uncle[2])
        self.assertIn('FLAG_DEFEATED_LAVARIDGE_GYM',uncle[3])
        self.assertIn('FLAG_DEFEATED_WALLY_VICTORY_ROAD',aunt[2])
        self.assertIn('FLAG_DEFEATED_LAVARIDGE_GYM',aunt[3])
        self.assertIn('FLAG_RUSTURF_TUNNEL_OPENED',aunt[4])

    def test_friendship_uses_seven_categories_and_specialvar(self):
        lines = scene(MAPS[7],'EventScript_FriendshipRater')
        self.assertIn('specialvar VAR_RESULT, GetLeadMonFriendshipScore',lines)
        names = ['FRIENDSHIP_NONE','FRIENDSHIP_1_TO_49','FRIENDSHIP_50_TO_99','FRIENDSHIP_100_TO_149',
                 'FRIENDSHIP_150_TO_199','FRIENDSHIP_200_TO_254','FRIENDSHIP_MAX']
        suffixes = ['DetestsYou','VeryWary','NotUsedToYou','GettingUsedToYou','LikesYouQuiteALot','VeryHappy','AdoresYou']
        self.assertEqual([line for line in lines if line.startswith('case ')],
            ['case '+name+', '+MAPS[7]+'_EventScript_'+suffix for name,suffix in zip(names,suffixes)])
        self.assertEqual([review._literal_define(ROOT,'include/constants/pokemon.h',name) for name in names],list(range(7)))
        self.assertEqual(profile.special_waits(ROOT)['GetLeadMonFriendshipScore'],0)

    def test_fury_cutter_tutor_is_the_shared_event_root(self):
        data = json.loads((ROOT/f'data/maps/{MAPS[4]}/map.json').read_text())
        entry = MAPS[4]+'_EventScript_FuryCutterTutor'
        self.assertEqual(data['object_events'][3]['script'],entry)
        source = review.label_blocks((ROOT/'data/scripts/move_tutors.inc').read_text())
        tutor = review.statements(source[entry])
        self.assertIn('setvar VAR_0x8005, TUTOR_MOVE_FURY_CUTTER',tutor)
        at = tutor.index('call MoveTutor_EventScript_OpenPartyMenu')
        self.assertEqual(tutor[at+1:at+3],['goto_if_eq VAR_RESULT, 0, MoveTutor_EventScript_FuryCutterDeclined',
                                         'setflag FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER'])

    def test_mart_has_its_own_eleven_item_stock(self):
        stock = review.statements(blocks(MAPS[3])[MAPS[3]+'_Pokemart'])
        items = ['GREAT_BALL','NEST_BALL','SUPER_POTION','ANTIDOTE','PARALYZE_HEAL','AWAKENING',
                 'BURN_HEAL','ICE_HEAL','REPEL','X_SPECIAL','FLUFFY_TAIL']
        self.assertEqual(stock,['.2byte ITEM_'+item for item in items]+['pokemartlistend'])


class VerdanturfNativeTests(unittest.TestCase):
    def test_family_is_explicit_without_claiming_palace_map_completion(self):
        rows = json.loads((ROOT/review.MANIFEST_PATH).read_text())['batches']
        selected = [row for row in rows if row['id']=='VerdanturfInteriors_story_review_20261023']
        self.assertEqual(len(selected),1)
        batch = selected[0]
        self.assertEqual(batch['maps'],MAPS)
        self.assertIn('BattleFrontier_BattlePalaceBattleRoom_EventScript_DoPalaceBattle',
                      {d['entry'] for d in batch['shared_dependencies']})
        self.assertNotIn('BattleFrontier_BattlePalaceBattleRoom',batch['maps'])
        self.assertNotIn('gStringVar4',{d['entry'] for d in batch['text_dependencies']})

    @unittest.skipUnless((ROOT/'pokeemerald_jp.elf').is_file(),'requires native artifacts')
    def test_nine_owner_extents_and_sixteen_physical_edges_match_native(self):
        symbols,_ = review.native_elf((ROOT/'pokeemerald_jp.elf').read_bytes())
        def address(label):
            self.assertEqual(len(symbols[label]),1)
            return next(iter(symbols[label]))
        edges = 0
        for name,(labels,size,texts) in zip(MAPS,SIZES):
            p = profile.profile_owner(ROOT,(ROOT/f'data/maps/{name}/scripts.inc').read_text(),
                                      version=4,address=address(name+'_MapScripts'))
            self.assertEqual((len(p),sum(b.size for b in p.values()),sum(b.kind=='string' for b in p.values())),
                             (labels,size,texts))
            for label,part in p.items():
                if part.fallthrough:
                    self.assertEqual(address(label)+part.size,address(part.fallthrough),label)
                    edges += part.kind=='script'
        self.assertEqual(edges,16)
        self.assertEqual(address(MAPS[1]+'_Movement_AttendantEnterDoor')-
                         address(MAPS[1]+'_Movement_PlayerEnterDoor'),1)


if __name__=='__main__':
    unittest.main()
