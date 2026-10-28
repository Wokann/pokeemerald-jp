"""Fail-closed typed script/movement analysis for reviewed story-map forms.

This does not approve a map. It measures explicitly supported source forms
and distinguishes scripts, map tables, movements and encoded JP text. Review
records, real macro expansion tests and native byte checks remain mandatory.
"""
from dataclasses import dataclass, field
from pathlib import Path
import re
import subprocess
try:
    from map_semantic_review import _literal_define, encoded_text, label_blocks, statements, text_kind
except ModuleNotFoundError:
    from tools.map_semantic_review import _literal_define, encoded_text, label_blocks, statements, text_kind

NAME = re.compile(r'[A-Za-z_]\w*\Z')
ATOM = re.compile(r'(?:[A-Za-z_]\w*|0x[0-9A-Fa-f]+|-?\d+)\Z')
GAME_CORNER_PRICES = {'TM_DOUBLE_TEAM_COINS': 1500, 'TM_PSYCHIC_COINS': 3500,
    'TM_FLAMETHROWER_COINS': 4000, 'TM_THUNDERBOLT_COINS': 4000, 'TM_ICE_BEAM_COINS': 4000,
    'DOLL_COINS': 1000, 'COINS_PRICE_50': 1000, 'COINS_PRICE_500': 10000}
COIN_CAPACITY_EXPRESSIONS = {'(MAX_COINS + 1 - 50)', '(MAX_COINS + 1 - 500)'}
FRONTIER_BET_AMOUNTS = (5, 10, 15)
GLASS_WORKSHOP_PRICES = {'BLUE_FLUTE_PRICE': 250, 'YELLOW_FLUTE_PRICE': 500,
    'RED_FLUTE_PRICE': 500, 'WHITE_FLUTE_PRICE': 1000, 'BLACK_FLUTE_PRICE': 1000,
    'PRETTY_CHAIR_PRICE': 6000, 'PRETTY_DESK_PRICE': 8000}
GLASS_WORKSHOP_PURCHASES = dict(zip(
    ('BlueFlute', 'YellowFlute', 'RedFlute', 'WhiteFlute', 'BlackFlute', 'PrettyChair', 'PrettyDesk'),
    GLASS_WORKSHOP_PRICES))
FAN_CLUB_NONFAN_EXPRESSION = '(NUM_TRAINER_FAN_CLUB_MEMBERS - 1)'
CONTEST_PAINTING_SELECTORS = frozenset(['CONTEST_WINNER_ARTIST']
    + [f'CONTEST_WINNER_HALL_{i}' for i in range(1, 7)]
    + ['CONTEST_WINNER_MUSEUM_' + category for category in ('COOL', 'BEAUTY', 'CUTE', 'SMART', 'TOUGH')])
MAP_TYPES = {name: ('condition_table' if name in ('MAP_SCRIPT_ON_FRAME_TABLE',
    'MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE') else 'script') for name in (
    'MAP_SCRIPT_ON_LOAD', 'MAP_SCRIPT_ON_FRAME_TABLE', 'MAP_SCRIPT_ON_TRANSITION',
    'MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE', 'MAP_SCRIPT_ON_RESUME', 'MAP_SCRIPT_ON_DIVE_WARP',
    'MAP_SCRIPT_ON_RETURN_TO_FIELD')}
MOVEMENTS = frozenset(('walk_up', 'walk_down', 'walk_left', 'walk_right',
    'walk_in_place_faster_up', 'walk_in_place_faster_down', 'walk_in_place_faster_left',
    'walk_in_place_faster_right', 'face_original_direction', 'face_player', 'set_invisible',
    'delay_8', 'delay_16', 'step_end', 'emote_exclamation_mark', 'emote_question_mark'))
STANDARD = {'MSGBOX_NPC': (2, 'Std_MsgboxNPC'), 'MSGBOX_SIGN': (3, 'Std_MsgboxSign'),
            'MSGBOX_DEFAULT': (4, 'Std_MsgboxDefault')}
STANDARD_V4 = STANDARD | {'MSGBOX_YESNO': (5, 'Std_MsgboxYesNo'),
                          'MSGBOX_AUTOCLOSE': (6, 'Std_MsgboxAutoclose'),
                          'MSGBOX_GETPOINTS': (9, 'Std_MsgboxGetPoints')}
MOVEMENTS_V4 = MOVEMENTS | {'lock_facing_direction', 'unlock_facing_direction',
                           'face_up', 'face_down', 'face_left', 'face_right', 'delay_4', 'reveal_trainer',
                           'walk_in_place_down', 'walk_faster_right', 'walk_fast_right', 'walk_fast_up',
                           'set_visible', 'walk_faster_up', 'walk_in_place_slow_left',
                           'walk_in_place_slow_right', 'walk_slow_left', 'walk_slow_diag_northeast',
                           'walk_slow_diag_southwest', 'walk_left_affine', 'init_affine_anim',
                           'clear_affine_anim', 'levitate', 'destroy_extra_task',
                           'walk_fast_left', 'jump_right', 'jump_in_place_right',
                           'disable_jump_landing_ground_effect', 'walk_faster_left', 'walk_fast_down',
                           'walk_in_place_fast_left', 'walk_in_place_fast_right', 'walk_in_place_fast_up', 'jump_2_down', 'cut_tree',
                           'walk_faster_down', 'lock_anim', 'walk_in_place_left', 'walk_in_place_up',
                           'rock_smash_break', 'walk_in_place_right', 'walk_slow_up', 'nurse_joy_bow',
                           'jump_in_place_down', 'jump_in_place_left', 'jump_up', 'walk_slow_right',
                           'walk_slow_down', 'slide_up', 'walk_down_start_affine',
                           'walk_down_affine', 'emote_heart', 'face_away_player', 'slide_down',
                           'jump_2_left', 'enable_jump_landing_ground_effect', 'delay_2',
                           'jump_in_place_up', 'disable_anim', 'ride_water_current_up'}
FIXED = {'lock': (1, 0), 'lockall': (1, 0), 'release': (1, 0), 'releaseall': (1, 0),
    'end': (1, 0), 'return': (1, 0), 'faceplayer': (1, 0), 'closemessage': (1, 0),
    'waitmessage': (1, 0), 'waitbuttonpress': (1, 0), 'waitstate': (1, 0),
    'fadedefaultbgm': (1, 0), 'waitdooranim': (1, 0), 'setflag': (3, 1), 'clearflag': (3, 1),
    'setvar': (5, 2), 'delay': (3, 1), 'savebgm': (3, 1), 'playbgm': (4, 2),
    'playse': (3, 1), 'opendoor': (5, 2), 'closedoor': (5, 2), 'hideobjectat': (5, 2),
    'setobjectxy': (7, 3), 'setobjectxyperm': (7, 3), 'warp': (8, 3),
    'waitse': (1, 0), 'waitfanfare': (1, 0), 'copyvar': (5, 2),
    'checkitemspace': (5, 2), 'checkitemtype': (3, 1), 'bufferitemname': (4, 2),
    'bufferstdstring': (4, 2), 'playfanfare': (3, 1), 'switch': (5, 1)}
FIXED_V4 = {op: form for op, form in FIXED.items() if op != 'checkitemspace'} | {
                   'setobjectmovementtype': (4, 2), 'getplayerxy': (5, 2),
                   'bufferleadmonspeciesname': (2, 1), 'addvar': (5, 2), 'yesnobox': (3, 2),
                   'copyobjectxytoperm': (3, 1), 'checkplayergender': (1, 0),
                   'playmoncry': (5, 2), 'waitmoncry': (1, 0),
                   'setmetatile': (9, 4), 'dotimebasedevents': (1, 0), 'random': (3, 1),
                   'setfieldeffectargument': (4, 2), 'dofieldeffect': (3, 1), 'waitfieldeffect': (3, 1),
                   'setweather': (3, 1), 'doweather': (1, 0), 'fadenewbgm': (3, 1),
                   'fadescreenspeed': (3, 2), 'turnobject': (4, 2),
                   'showplayer': (5, 0), 'hideplayer': (5, 0),
                   'multichoice': (5, 4), 'multichoicedefault': (6, 5),
                   'setobjectsubpriority': (6, 3), 'resetobjectsubpriority': (5, 2),
                   'showobjectat': (5, 2), 'incrementgamestat': (2, 1),
                   'getpartysize': (1, 0), 'giveegg': (3, 1), 'fadescreen': (2, 1),
                   'selectapproachingtrainer': (1, 0), 'lockfortrainer': (1, 0),
                   'buffertrainerclassname': (4, 2), 'buffertrainername': (4, 2),
                   'buffernumberstring': (4, 2), 'checkpartymove': (3, 1),
                   'bufferpartymonnick': (4, 2), 'buffermovename': (4, 2),
                   'fadescreenswapbuffers': (2, 1), 'setorcopyvar': (5, 2), 'dowildbattle': (1, 0),
                   'choosecontestmon': (1, 0), 'contestlinktransfer': (1, 0), 'nop1': (1, 0),
                   'turnrotatingtileobjects': (4, 0), 'freerotatingtilepuzzle': (1, 0),
                   'closebraillemessage': (1, 0), 'startcontest': (1, 0),
                   'showcontestresults': (1, 0)}

# These source blocks deliberately continue into the next physical label.
# A native adjacency check is mandatory; a named target alone is not proof.
FALLTHROUGHS = {
    'TrainerHill_Entrance_EventScript_ExitChallenge': 'TrainerHill_Entrance_EventScript_ExitChallengeLost',
    'TrainerHill_Entrance_EventScript_ExitChallengeECard': 'TrainerHill_Entrance_EventScript_PlayerExitChallenge',
    'TrainerHill_Entrance_EventScript_PlayerExitChallenge': 'TrainerHill_Entrance_EventScript_EndExitChallenge',
    'TrainerHill_Entrance_EventScript_ThanksForPlaying': 'TrainerHill_Entrance_EventScript_AttendantEnd',
    'TrainerHill_Entrance_EventScript_AllFloorsUsed': 'TrainerHill_Entrance_EventScript_AskChallengeTrainers',
    'TrainerHill_Roof_EventScript_Owner': 'TrainerHill_Roof_EventScript_Arrived',
    'TrainerHill_Roof_EventScript_Arrived': 'TrainerHill_Roof_EventScript_GivePrize',
    'TrainerHill_Roof_EventScript_GivePrize': 'TrainerHill_Roof_EventScript_ReceivePrize',
    'TrainerHill_Roof_EventScript_CheckFinalTime': 'TrainerHill_Roof_EventScript_NewRecord',
    'BattlePyramid_FindItemBall': 'BattlePyramid_FindItemBallEnd',
    'SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles': 'SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs',
    'SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs': 'SootopolisCity_Gym_1F_EventScript_OpenFirstStairs',
    'SootopolisCity_Gym_1F_EventScript_OpenFirstStairs': 'SootopolisCity_Gym_1F_EventScript_StopCheckingStairs',
    'Route117_EventScript_TryMoveDayCareMan': 'Route117_EventScript_StopMoveDayCareMan',
    'Route111_EventScript_CheckSetSandstorm': 'Route111_EventScript_SetSandstorm',
    'Route111_EventScript_SetSandstorm': 'Route111_EventScript_EndCheckSetSandstorm',
    'ProfBirch_EventScript_RatePokedexOrRegister': 'ProfBirch_EventScript_AskRatePokedex',
    'MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales': 'MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales',
    'RustboroCity_Flat1_2F_EventScript_WaldasDad': 'RustboroCity_Flat1_2F_EventScript_GivePhrase',
    'EventScript_StartTrainerApproach': 'EventScript_TrainerApproach',
    'EventScript_DoTrainerBattle': 'EventScript_EndTrainerBattle',
    'BerryTree_EventScript_ChooseBerryToPlant': 'BerryTree_EventScript_CancelPlanting',
    'BerryTree_EventScript_CheckBerryFullyGrown': 'BerryTree_EventScript_PickBerry',
    'BerryTree_EventScript_WantToWater': 'BerryTree_EventScript_DontWater',
    'BerryTree_EventScript_ItemUseWailmerPail': 'BerryTree_EventScript_WaterBerry',
    'CableClub_EventScript_CheckTurnAttendant': 'CableClub_EventScript_DontTurnAttendant',
    'CableClub_EventScript_PlayerExitRecordCorner': 'CableClub_EventScript_ExitRecordCornerRet',
    'CableClub_EventScript_TryWonderCardScript': 'CableClub_EventScript_MysteryGiftThankYou',
    'DewfordTown_Gym_EventScript_BrightenRoom': 'DewfordTown_Gym_EventScript_NoLightChange',
    'DewfordTown_Gym_EventScript_CountTrainersDefeated': 'DewfordTown_Gym_EventScript_CheckJocelyn',
    'DewfordTown_Gym_EventScript_CheckJocelyn': 'DewfordTown_Gym_EventScript_CheckLaura',
    'DewfordTown_Gym_EventScript_CheckLaura': 'DewfordTown_Gym_EventScript_CheckBrenden',
    'DewfordTown_Gym_EventScript_CheckBrenden': 'DewfordTown_Gym_EventScript_CheckCristian',
    'DewfordTown_Gym_EventScript_CheckCristian': 'DewfordTown_Gym_EventScript_CheckLilith',
    'DewfordTown_Gym_EventScript_CheckLilith': 'DewfordTown_Gym_EventScript_StopCountingTrainers',
    'LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars': 'LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar',
    'LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar': 'LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar',
    'LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar': 'LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar',
    'LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar': 'LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars',
    'LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers': 'LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald',
    'LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald': 'LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle',
    'LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle': 'LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle',
    'LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle': 'LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers',
    'LavaridgeTown_Gym_B1F_EventScript_SetTrainerTempVars': 'LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar',
    'LavaridgeTown_Gym_B1F_EventScript_SetJaceTempVar': 'LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar',
    'LavaridgeTown_Gym_B1F_EventScript_SetJeffTempVar': 'LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar',
    'LavaridgeTown_Gym_B1F_EventScript_SetEliTempVar': 'LavaridgeTown_Gym_B1F_EventScript_EndSetTrainerTempVars',
    'LavaridgeTown_Gym_B1F_EventScript_CheckBuryTrainers': 'LavaridgeTown_Gym_B1F_EventScript_CheckBuryJace',
    'LavaridgeTown_Gym_B1F_EventScript_CheckBuryJace': 'LavaridgeTown_Gym_B1F_EventScript_CheckBuryJeff',
    'LavaridgeTown_Gym_B1F_EventScript_CheckBuryJeff': 'LavaridgeTown_Gym_B1F_EventScript_CheckBuryEli',
    'LavaridgeTown_Gym_B1F_EventScript_CheckBuryEli': 'LavaridgeTown_Gym_B1F_EventScript_EndCheckBuryTrainers',
    'FallarborTown_BattleTentLobby_EventScript_WonChallenge': 'FallarborTown_BattleTentLobby_EventScript_GivePrize',
    'FallarborTown_BattleTentLobby_EventScript_Attendant': 'FallarborTown_BattleTentLobby_EventScript_AskEnterChallenge',
    'FallarborTown_BattleTentLobby_EventScript_AskEnterChallenge': 'FallarborTown_BattleTentLobby_EventScript_TryEnterChallenge',
    'FallarborTown_BattleTentLobby_EventScript_TryEnterChallenge': 'FallarborTown_BattleTentLobby_EventScript_SaveBeforeChallenge',
    'FallarborTown_BattleTentLobby_EventScript_SaveBeforeChallenge': 'FallarborTown_BattleTentLobby_EventScript_EnterChallenge',
    'FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMons': 'FallarborTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50',
    'FallarborTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge': 'FallarborTown_BattleTentLobby_EventScript_CancelChallenge',
    'FallarborTown_BattleTentLobby_EventScript_CancelChallenge': 'FallarborTown_BattleTentLobby_EventScript_EndCancelChallenge',
    'FallarborTown_BattleTentBattleRoom_EventScript_EnterRoom': 'FallarborTown_BattleTentBattleRoom_EventScript_NextOpponentEnter',
    'FallarborTown_BattleTentBattleRoom_EventScript_NextOpponentEnter': 'FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost',
    # Physical adjacency, not a claim that the old context resumes after warp.
    'FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost': 'FallarborTown_BattleTentBattleRoom_EventScript_DefeatedOpponent',
    'FallarborTown_BattleTentBattleRoom_EventScript_DefeatedOpponent': 'FallarborTown_BattleTentBattleRoom_EventScript_IncrementBattleNum',
    'FallarborTown_BattleTentBattleRoom_EventScript_IncrementBattleNum': 'FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge',
    'FallarborTown_BattleTentBattleRoom_EventScript_AskContinueChallenge': 'FallarborTown_BattleTentBattleRoom_EventScript_AskPauseChallenge',
    'FallarborTown_BattleTentBattleRoom_EventScript_AskPauseChallenge': 'FallarborTown_BattleTentBattleRoom_EventScript_AskRetireChallenge',
    'FallarborTown_BattleTentBattleRoom_EventScript_AskRetireChallenge': 'FallarborTown_BattleTentBattleRoom_EventScript_ContinueChallenge',
    'FallarborTown_BattleTentBattleRoom_EventScript_UnreachableWaitstate': 'FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon',
    'FallarborTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon': 'FallarborTown_BattleTentBattleRoom_EventScript_ReadyFor2ndOpponent',
    'VerdanturfTown_BattleTentLobby_EventScript_WonChallenge': 'VerdanturfTown_BattleTentLobby_EventScript_GivePrize',
    'VerdanturfTown_BattleTentLobby_EventScript_Attendant': 'VerdanturfTown_BattleTentLobby_EventScript_AskEnterChallenge',
    'VerdanturfTown_BattleTentLobby_EventScript_AskEnterChallenge': 'VerdanturfTown_BattleTentLobby_EventScript_TryEnterChallenge',
    'VerdanturfTown_BattleTentLobby_EventScript_TryEnterChallenge': 'VerdanturfTown_BattleTentLobby_EventScript_SaveBeforeChallenge',
    'VerdanturfTown_BattleTentLobby_EventScript_SaveBeforeChallenge': 'VerdanturfTown_BattleTentLobby_EventScript_EnterChallenge',
    'VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMons': 'VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50',
    'VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge': 'VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge',
    'VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge': 'VerdanturfTown_BattleTentLobby_EventScript_EndCancelChallenge',
    'VerdanturfTown_BattleTentBattleRoom_EventScript_EnterRoom': 'VerdanturfTown_BattleTentBattleRoom_EventScript_NextOpponentEnter',
    'VerdanturfTown_BattleTentBattleRoom_EventScript_NextOpponentEnter': 'VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost',
    # Warp continuations describe physical bytes, not normal runtime resumption.
    'VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyLost': 'VerdanturfTown_BattleTentBattleRoom_EventScript_DefeatedOpponent',
    'VerdanturfTown_BattleTentBattleRoom_EventScript_DefeatedOpponent': 'VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge',
    'VerdanturfTown_BattleTentBattleRoom_EventScript_AskContinueChallenge': 'VerdanturfTown_BattleTentBattleRoom_EventScript_AskPauseChallenge',
    'VerdanturfTown_BattleTentBattleRoom_EventScript_AskPauseChallenge': 'VerdanturfTown_BattleTentBattleRoom_EventScript_AskRetireChallenge',
    'VerdanturfTown_BattleTentBattleRoom_EventScript_AskRetireChallenge': 'VerdanturfTown_BattleTentBattleRoom_EventScript_ContinueChallenge',
    'VerdanturfTown_BattleTentBattleRoom_EventScript_WarpToLobbyWon': 'VerdanturfTown_BattleTentBattleRoom_EventScript_PauseChallenge',
    'SlateportCity_BattleTentLobby_EventScript_WonChallenge': 'SlateportCity_BattleTentLobby_EventScript_GivePrize',
    'SlateportCity_BattleTentLobby_EventScript_LostChallenge': 'SlateportCity_BattleTentLobby_EventScript_EndGivePrize',
    'SlateportCity_BattleTentLobby_EventScript_Attendant': 'SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge',
    'SlateportCity_BattleTentLobby_EventScript_AskEnterChallenge': 'SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge',
    'SlateportCity_BattleTentLobby_EventScript_TryEnterChallenge': 'SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge',
    'SlateportCity_BattleTentLobby_EventScript_SaveBeforeChallenge': 'SlateportCity_BattleTentLobby_EventScript_EnterChallenge',
    'SlateportCity_BattleTentLobby_EventScript_LoadPartyCancelChallenge': 'SlateportCity_BattleTentLobby_EventScript_CancelChallenge',
    'SlateportCity_BattleTentCorridor_EventScript_SetUpObjects': 'SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth',
    'SlateportCity_BattleTentCorridor_EventScript_EnterCorridor': 'SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom',
    'SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle': 'SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent',
    'SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent': 'SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge',
    'SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge': 'SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge',
    'SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge': 'SlateportCity_BattleTentCorridor_EventScript_AskSwapMon',
    'SlateportCity_BattleTentCorridor_EventScript_AskSwapMon': 'SlateportCity_BattleTentCorridor_EventScript_SwapMons',
    'SlateportCity_BattleTentBattleRoom_EventScript_EnterRoom': 'SlateportCity_BattleTent_EventScript_WarpToLobbyLost',
    'LilycoveCity_PokemonCenter_1F_EventScript_MonEnjoyPokeblock': 'LilycoveCity_PokemonCenter_1F_EventScript_FinishFeedPokeblock',
    'LilycoveCity_PokemonCenter_1F_EventScript_MakeQuiz': 'LilycoveCity_PokemonCenter_1F_EventScript_PickPrize',
    'LilycoveCity_PokemonCenter_1F_EventScript_TakeQuiz': 'LilycoveCity_PokemonCenter_1F_EventScript_CheckQuizTakingState',
    'LilycoveCity_PokemonCenter_1F_EventScript_WriteQuiz': 'LilycoveCity_PokemonCenter_1F_EventScript_WriteQuizQuestion',
}

FALLTHROUGHS |= {'BattleFrontier_BattleTowerLobby_' + owner: 'BattleFrontier_BattleTowerLobby_' + target
    for owner, target in (
        ('OnTransition', 'EventScript_ShowApprentice'),
        ('EventScript_ShowApprentice', 'EventScript_EndShowOrHideApprentice'),
        ('EventScript_DefeatedMaiden', 'EventScript_GiveRibbons'),
        ('EventScript_GiveRibbons', 'EventScript_GiveBattlePoints'),
        ('EventScript_GiveBattlePoints', 'EventScript_LookForwardToChallenge'),
        ('EventScript_LostChallenge', 'EventScript_CancelWinStreak'),
        ('EventScript_CancelWinStreak', 'EventScript_LostThanksForPlaying'),
        ('EventScript_SinglesAttendant', 'EventScript_AskEnterSinglesChallenge'),
        ('EventScript_AskEnterSinglesChallenge', 'EventScript_TryEnterSinglesChallenge'),
        ('EventScript_TryEnterSinglesChallenge', 'EventScript_SaveBeforeSinglesChallenge'),
        ('EventScript_DoublesAttendant', 'EventScript_AskEnterDoublesChallenge'),
        ('EventScript_AskEnterDoublesChallenge', 'EventScript_TryEnterDoublesChallenge'),
        ('EventScript_TryEnterDoublesChallenge', 'EventScript_SaveBeforeDoublesChallenge'),
        ('EventScript_MultisAttendant', 'EventScript_AskEnterMultisChallenge'),
        ('EventScript_AskEnterMultisChallenge', 'EventScript_TryEnterMultisChallenge'),
        ('EventScript_TryEnterMultisChallenge', 'EventScript_SaveBeforeMultisChallenge'),
        ('EventScript_LinkMultisAttendant', 'EventScript_AskEnterLinkMultisChallenge'),
        ('EventScript_AskEnterLinkMultisChallenge', 'EventScript_TryEnterLinkMultisChallenge'),
        ('EventScript_TryEnterLinkMultisChallenge', 'EventScript_SaveBeforeLinkMultisChallenge'),
        ('EventScript_NotEnoughValidMons', 'EventScript_NotEnoughValidMonsLv50'),
        ('EventScript_LoadPartyCancelChallenge', 'EventScript_CancelChallenge'),
        ('EventScript_CancelChallenge', 'EventScript_EndCancelChallenge'),
        ('EventScript_EnterElevator', 'EventScript_WaitForLinkOpponentLoad'),
        ('EventScript_ShowYouToLinkMultiBattleRoom', 'EventScript_WalkToElevator'),
    )}
FALLTHROUGHS |= {'BattleFrontier_BattleTowerBattleRoom_EventScript_' + owner:
                'BattleFrontier_BattleTowerBattleRoom_EventScript_' + target
    for owner, target in (
        ('DefeatedOpponent', 'AskReadyForOpponent'),
        ('AskReadyForOpponent', 'AskReadyForOpponentNoRecord'),
        ('AskReadyForOpponentNoRecord', 'AskRecordBattle'),
        ('AskRecordBattle', 'RecordBattle'),
        ('AskPauseChallenge', 'AskRetireChallenge'),
        ('AskRetireChallenge', 'ContinueChallenge'),
        ('ReadyForOpponent', 'ReadyFor2ndOpponent'),
        ('MaidenUpNext', 'AskReadyForMaiden'),
        ('AskReadyForMaiden', 'AskReadyForMaidenNoRecord'),
        ('AskReadyForMaidenNoRecord', 'BattleAnabel'),
        ('BattleAnabel', 'BattleAnabelSilver'),
        ('AnabelGoldIntro', 'BattleAnabelGold'),
        ('DoTowerBattle', 'EndTowerBattle'),
    )}
FALLTHROUGHS |= {
    'BattleFrontier_BattleTowerBattleRoom_EventScript_OpponentEnter': 'BattleFrontier_BattleTower_EventScript_WarpToLobbyLost',
    'BattleFrontier_BattleTowerLobby_EventScript_AskSaveBattle': 'BattleFrontier_EventScript_SaveBattle',
    'BattleFrontier_EventScript_BattleSaveFailed': 'BattleFrontier_BattleTowerLobby_EventScript_EndSaveBattle',
    'BattleFrontier_BattleTowerCorridor_EventScript_WalkToFarDoor': 'BattleFrontier_BattleTowerCorridor_EventScript_WarpToBattleRoom',
    'BattleFrontier_BattleTowerLobby_EventScript_Apprentice': 'Apprentice_EventScript_AskQuestion',
    'Apprentice_EventScript_FirstMeeting': 'Apprentice_EventScript_WhichLvlMode',
    'Apprentice_EventScript_UseWhatHeldItem': 'Apprentice_EventScript_ChooseHoldItem',
    'Apprentice_EventScript_ConfirmHoldNothing': 'Apprentice_EventScript_HoldNothing',
}
FALLTHROUGHS |= {'BattleFrontier_BattleTowerMultiBattleRoom_EventScript_' + owner:
                'BattleFrontier_BattleTowerMultiBattleRoom_EventScript_' + target
    for owner, target in (
        ('DoOpponentIntrosLink', 'DoTowerBattle'),
        ('DoTowerBattle', 'WarpToLobbyLost'),
        ('RetorePartyMsgLink', 'RestoreParty'),
        ('RestoreParty', 'AskReadyForOpponents'),
        ('AskReadyForOpponents', 'AskReadyForOpponentsNoRecord'),
        ('AskReadyForOpponentsNoRecord', 'AskRecordBattle'),
        ('AskRecordBattle', 'RecordBattle'),
        ('AskPauseChallenge', 'AskRetireChallenge'),
        ('AskRetireChallenge', 'ContinueChallenge'),
        ('ReadyForNextOpponentSet', 'ReadyFor2ndOpponentSet'),
        ('ReadyForNextOpponentSetLink', 'ReadyFor2ndOpponentSetLink'),
    )}
FALLTHROUGHS |= {'BattleFrontier_BattleDome' + room + '_EventScript_' + owner:
                'BattleFrontier_BattleDome' + room + '_EventScript_' + target
    for room, owner, target in (
        ('Lobby', 'DefeatedAce', 'GiveBattlePoints'),
        ('Lobby', 'LostChallenge', 'AskRecordBattle'),
        ('Lobby', 'AskRecordBattle', 'RecordBattle'),
        ('Lobby', 'RecordBattle', 'EndChallenge'),
        ('Lobby', 'AttendantWelcome', 'AskTakeChallenge'),
        ('Lobby', 'AskTakeChallenge', 'TryEnterChallenge'),
        ('Lobby', 'TryEnterChallenge', 'SaveBeforeChallenge'),
        ('Lobby', 'SaveBeforeChallenge', 'EnterChallenge'),
        ('Lobby', 'NotEnoughValidMons', 'NotEnoughValidMonsLv50'),
        ('Lobby', 'LoadPartyCancelChallenge', 'CancelChallenge'),
        ('Lobby', 'CancelChallenge', 'EndCancelChallenge'),
        ('Corridor', 'WalkToBattleRoomLvOpen', 'WarpToPreBattleRoom'),
        ('PreBattleRoom', 'EnterRoom', 'AskReadyForNextRound'),
        ('PreBattleRoom', 'AskReadyForNextRound', 'AskReadyForNextRoundNoRecord'),
        ('PreBattleRoom', 'AskReadyForNextRoundNoRecord', 'AskRecordBattle'),
        ('PreBattleRoom', 'AskRecordBattle', 'RecordBattle'),
        ('PreBattleRoom', 'AskPauseChallenge', 'AskRetireChallenge'),
        ('PreBattleRoom', 'AskRetireChallenge', 'RetireChallenge'),
        ('BattleRoom', 'EnterRoom', 'PlayerEnter'),
        ('BattleRoom', 'PlayerEnterForTucker', 'AudienceReactToPlayer'),
        ('BattleRoom', 'AudienceReactToPlayer', 'BattleOpponent'),
        ('BattleRoom', 'BattleOpponent', 'Draw'),
        ('BattleRoom', 'Draw', 'LostToOpponent'),
        ('BattleRoom', 'LostToOpponent', 'LostTourney'),
        ('BattleRoom', 'LostTourney', 'WarpToLobbyLost'),
        ('BattleRoom', 'WonLvOpenTourney', 'CelebrateWin'),
        ('BattleRoom', 'AnnouncePlayerChampion', 'AnnouncePlayerChampionNoTucker'),
        ('BattleRoom', 'AnnounceTucker', 'AnnounceTuckerSilver'),
        ('BattleRoom', 'AnnounceTuckerGold', 'TuckerEnter'),
        ('BattleRoom', 'TuckerEnter', 'BattleTuckerSilver'),
        ('BattleRoom', 'TuckerGoldIntro', 'BattleTuckerGold'),
        ('BattleRoom', 'SetUpObjects', 'EndSetUpObjects'),
    )}
FALLTHROUGHS |= {'BattleFrontier_BattlePalace' + room + '_EventScript_' + owner:
                'BattleFrontier_BattlePalace' + room + '_EventScript_' + target
    for room, owner, target in (
        ('Lobby', 'DefeatedMaven', 'GiveBattlePoints'),
        ('Lobby', 'SaveAfterChallenge', 'RecordMatch'),
        ('Lobby', 'RecordMatch', 'EndSaveAfterChallenge'),
        ('Lobby', 'Attendant', 'AskTakeChallenge'),
        ('Lobby', 'AskTakeChallenge', 'TryEnterChallenge'),
        ('Lobby', 'TryEnterChallenge', 'SaveBeforeChallenge'),
        ('Lobby', 'SaveBeforeChallenge', 'EnterChallenge'),
        ('Lobby', 'NotEnoughValidMons', 'NotEnoughValidMonsLv50'),
        ('Lobby', 'LoadPartyAndCancelChallenge', 'CancelChallenge'),
        ('Lobby', 'CancelChallenge', 'EndCancelChallenge'),
        ('Corridor', 'WalkToOpenBattleRoom', 'WarpToBattleRoom'),
        ('BattleRoom', 'BeginChallenge', 'NextOpponentEnter'),
        ('BattleRoom', 'NextOpponentEnter', 'WarpToLobbyLost'),
        ('BattleRoom', 'DefeatedOpponent', 'AskReadyForOpponent'),
        ('BattleRoom', 'AskReadyForOpponent', 'AskReadyForOpponentNoRecord'),
        ('BattleRoom', 'AskReadyForOpponentNoRecord', 'AskRecordBattle'),
        ('BattleRoom', 'AskRecordBattle', 'RecordBattle'),
        ('BattleRoom', 'AskPauseChallenge', 'AskRetireChallenge'),
        ('BattleRoom', 'AskRetireChallenge', 'ContinueChallenge'),
        ('BattleRoom', 'MavenUpNext', 'AskReadyForMaven'),
        ('BattleRoom', 'AskReadyForMaven', 'AskReadyForMavenNoRecord'),
        ('BattleRoom', 'AskReadyForMavenNoRecord', 'BattleSpenser'),
        ('BattleRoom', 'BattleSpenser', 'BattleSpenserSilver'),
        ('BattleRoom', 'IntroSpenserGold', 'BattleSpenserGold'),
    )}
FALLTHROUGHS |= {'BattleFrontier_BattlePyramid' + room + '_' + owner:
                'BattleFrontier_BattlePyramid' + room + '_' + target
    for room, owner, target in (
        ('Lobby', 'EventScript_DefeatedKing', 'EventScript_GiveBattlePoints'),
        ('Lobby', 'EventScript_Attendant', 'EventScript_AskTakeChallenge'),
        ('Lobby', 'EventScript_AskTakeChallenge', 'EventScript_TryEnterChallenge'),
        ('Lobby', 'EventScript_TryEnterChallenge', 'EventScript_SaveBeforeChallenge'),
        ('Lobby', 'EventScript_SaveBeforeChallenge', 'EventScript_EnterChallenge'),
        ('Lobby', 'EventScript_NotEnoughValidMons', 'EventScript_NotEnoughValidMonsLv50'),
        ('Lobby', 'EventScript_LoadPartyAndCancelChallenge', 'EventScript_CancelChallenge'),
        ('Lobby', 'EventScript_CancelChallenge', 'EventScript_EndCancelChallenge'),
        ('Lobby', 'EventScript_ReceiveNewBattleBag', 'EventScript_ReceiveBattleBag'),
        ('Floor', 'EventScript_UpdateLight', 'EventScript_UpdateLightLoop'),
        ('Floor', 'OnResume', 'EventScript_ResetParty'),
        ('', 'EventScript_WarpToLobbyLost', 'EventScript_WarpToLobby'),
        ('Top', 'EventScript_SetUpObjects', 'EventScript_EndSetUpObjects'),
        ('Top', 'OnResume', 'EventScript_CheckChallengeStatus'),
        ('Top', 'EventScript_Attendant', 'EventScript_WarpToLobbyWon'),
        ('Top', 'EventScript_BrandonHeardSilverSpeech', 'EventScript_BattleBrandonSilver'),
        ('Top', 'EventScript_BrandonHeardGoldSpeech', 'EventScript_BattleBrandonGold'),
    )}

FALLTHROUGHS |= {'BattleFrontier_BattleArena' + room + '_EventScript_' + owner:
                'BattleFrontier_BattleArena' + room + '_EventScript_' + target
    for room, owner, target in (
        ('Lobby', 'DefeatedTycoon', 'GiveBattlePoints'),
        ('Lobby', 'SaveAfterChallenge', 'RecordMatch'),
        ('Lobby', 'RecordMatch', 'EndSaveAfterChallenge'),
        ('Lobby', 'Attendant', 'AskTakeChallenge'),
        ('Lobby', 'AskTakeChallenge', 'TryEnterChallenge'),
        ('Lobby', 'TryEnterChallenge', 'SaveBeforeChallenge'),
        ('Lobby', 'SaveBeforeChallenge', 'EnterChallenge'),
        ('Lobby', 'NotEnoughValidMons', 'NotEnoughValidMonsLv50'),
        ('Lobby', 'LoadPartyAndCancelChallenge', 'CancelChallenge'),
        ('Lobby', 'CancelChallenge', 'EndCancelChallenge'),
        ('BattleRoom', 'AnnounceTrainers', 'DeclareOpponentWinner'),
        ('BattleRoom', 'DeclareOpponentWinner', 'WarpToLobbyLost'),
        ('BattleRoom', 'DefeatedOpponent', 'AskReadyForOpponent'),
        ('BattleRoom', 'AskReadyForOpponent', 'AskReadyForOpponentNoRecord'),
        ('BattleRoom', 'AskReadyForOpponentNoRecord', 'AskRecordBattle'),
        ('BattleRoom', 'AskRecordBattle', 'RecordBattle'),
        ('BattleRoom', 'AskPauseChallenge', 'AskRetireChallenge'),
        ('BattleRoom', 'AskRetireChallenge', 'ContinueChallenge'),
        ('BattleRoom', 'TycoonUpNext', 'AskReadyForTycoon'),
        ('BattleRoom', 'AskReadyForTycoon', 'AskReadyForTycoonNoRecord'),
        ('BattleRoom', 'AskReadyForTycoonNoRecord', 'BattleGreta'),
        ('BattleRoom', 'BattleGreta', 'BattleGretaSilver'),
        ('BattleRoom', 'IntroGretaGold', 'BattleGretaGold'),
    )}

FALLTHROUGHS |= {'BattleFrontier_BattleFactory' + room + '_EventScript_' + owner:
                'BattleFrontier_BattleFactory' + room + '_EventScript_' + target
    for room, owner, target in (
        ('Lobby', 'DefeatedFactoryHead', 'GiveBattlePoints'),
        ('Lobby', 'LostChallenge', 'AskRecordBattle'),
        ('Lobby', 'AskRecordBattle', 'RecordBattle'),
        ('Lobby', 'RecordBattle', 'EndRecordBattle'),
        ('Lobby', 'Attendant', 'AskTakeChallenge'),
        ('Lobby', 'AskTakeChallenge', 'TryEnterChallenge'),
        ('Lobby', 'TryEnterChallenge', 'SaveBeforeChallenge'),
        ('Lobby', 'SaveBeforeChallenge', 'EnterChallenge'),
        ('Lobby', 'LoadPartyAndCancelChallenge', 'CancelChallenge'),
        ('PreBattleRoom', 'SetUpObjects', 'TurnPlayerNorth'),
        ('PreBattleRoom', 'EnterRoom', 'EnterBattleRoom'),
        ('PreBattleRoom', 'AskReadyForOpponent', 'AskReadyForRegularOpponent'),
        ('PreBattleRoom', 'AskReadyForRegularOpponent', 'AskReadyForOpponentNoRecord'),
        ('PreBattleRoom', 'AskReadyForOpponentNoRecord', 'AskRecordBattle'),
        ('PreBattleRoom', 'AskRecordBattle', 'RecordBattle'),
        ('PreBattleRoom', 'AskPauseChallenge', 'AskRetireChallenge'),
        ('PreBattleRoom', 'AskRetireChallenge', 'AskSwapMon'),
        ('PreBattleRoom', 'AskSwapMon', 'SwapMons'),
        ('PreBattleRoom', 'AskReadyForHead', 'AskReadyForHeadNoRecord'),
        ('PreBattleRoom', 'AskReadyForHeadNoRecord', 'AskSwapBeforeHead'),
        ('PreBattleRoom', 'AskSwapBeforeHead', 'WalkToBattleRoomLv50'),
        ('BattleRoom', 'HideObjects', 'EndHideObjects'),
        ('BattleRoom', 'EnterRoom', 'BattleOpponent'),
        ('BattleRoom', 'BattleOpponent', 'WarpToLobbyLost'),
        ('BattleRoom', 'DefeatedOpponent', 'IncrementWinStreak'),
        ('BattleRoom', 'IncrementWinStreak', 'IncrementBattleNum'),
        ('BattleRoom', 'BattleNoland', 'BattleNolandSilver'),
        ('BattleRoom', 'IntroNolandGold', 'BattleNolandGold'),
    )}

FALLTHROUGHS |= {'BattleFrontier_BattlePike' + room + '_EventScript_' + owner:
                'BattleFrontier_BattlePike' + room + '_EventScript_' + target
    for room, owner, target in (
        ('Lobby', 'DefeatedQueen', 'GiveBattlePoints'),
        ('Lobby', 'Attendant', 'AskTakeChallenge'),
        ('Lobby', 'AskTakeChallenge', 'TryEnterChallenge'),
        ('Lobby', 'TryEnterChallenge', 'SaveBeforeChallenge'),
        ('Lobby', 'NotEnoughValidMons', 'NotEnoughValidMonsLv50'),
        ('Lobby', 'LoadPartyAndCancelChallenge', 'CancelChallenge'),
        ('Lobby', 'CancelChallenge', 'EndCancelChallenge'),
        ('RoomNormal', 'EnterSingleBattleRoom', 'WarpToLobbyLost'),
        ('RoomNormal', 'EnterBrainRoom', 'LucyEnter'),
        ('RoomNormal', 'LucyEnter', 'BattleLucySilver'),
        ('RoomNormal', 'IntroLucyGold', 'BattleLucyGold'),
        ('RoomNormal', 'NPC', 'NormalNPC'),
    )}
FALLTHROUGHS['BattleFrontier_BattlePikeRoom_OnResume'] = 'BattleFrontier_BattlePikeThreePathRoom_EventScript_EndOnResume'

# These exact movement prefixes deliberately share the next movement's
# terminator. Never insert a step_end or accept arbitrary unterminated paths.
MOVEMENT_PREFIXES = {
    'BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor':
        ('BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor', ('walk_up',)),
    'BattleFrontier_BattlePikeRoomNormal_Movement_MonMoveAside':
        ('BattleFrontier_BattlePikeRoomNormal_Movement_MonFaceRight', ('walk_left',)),
    'BattleFrontier_BattleArenaBattleRoom_Movement_PlayerEnter':
        ('BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForwardLong', ('walk_right', 'walk_right')),
    'BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForwardLong':
        ('BattleFrontier_BattleArenaBattleRoom_Movement_PlayerStepForward', ('walk_right',)),
    'BattleFrontier_BattleArenaBattleRoom_Movement_OpponentEnter':
        ('BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong', ('walk_left', 'walk_left')),
    'BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForwardLong':
        ('BattleFrontier_BattleArenaBattleRoom_Movement_OpponentStepForward', ('walk_left',)),
    'BattleFrontier_BattlePalaceCorridor_Movement_PlayerEnterBattleRoom':
        ('BattleFrontier_BattlePalaceCorridor_Movement_AttendantEnterBattleRoom', ('walk_up',)),
    'BattleFrontier_BattlePalaceBattleRoom_Movement_PlayerEnterRoom':
        ('BattleFrontier_BattlePalaceBattleRoom_Movement_FaceRight',
         ('set_visible', 'walk_up', 'walk_up', 'walk_up', 'walk_up')),
    'BattleFrontier_BattleDomeBattleRoom_Movement_PlayerEnter':
        ('BattleFrontier_BattleDomeBattleRoom_Movement_PlayerStepForward',
         ('set_visible', 'delay_16', 'walk_up', 'walk_up', 'walk_up', 'walk_right')),
    'FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor':
        ('FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor', ('walk_up',)),
    'VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor':
        ('VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor', ('walk_up',)),
    'BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToFarDoor':
        ('BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToFarDoor', ('walk_right',)),
    'BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToFarDoor':
        ('BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToDoor', ('walk_right', 'walk_right')),
    'BattleFrontier_BattleTowerCorridor_Movement_PlayerWalkToDoor':
        ('BattleFrontier_BattleTowerCorridor_Movement_AttendantWalkToDoor', ('walk_right',)),
    'Apprentice_Movement_LeaveNorth':
        ('Apprentice_Movement_Leave', ('walk_fast_right',)),
}

# This audited warp replaces the old script context before the following
# movement bytes. It is not a bytecode edge into that movement definition.
CONTEXT_WARP_EXITS = {
    'BattleFrontier_BattleFactoryBattleRoom_EventScript_IncrementBattleNum':
        ('MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM', 8, 8),
    'BattleFrontier_BattleArenaBattleRoom_EventScript_WarpToLobbyLost':
        ('MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY', 7, 8),
    'BattleFrontier_BattleArenaBattleRoom_EventScript_ReturnToLobbyWon':
        ('MAP_BATTLE_FRONTIER_BATTLE_ARENA_LOBBY', 7, 8),
    'BattleFrontier_BattleDomeBattleRoom_EventScript_DefeatedOpponent':
        ('MAP_BATTLE_FRONTIER_BATTLE_DOME_PRE_BATTLE_ROOM', 5, 3),
    'SlateportCity_BattleTentBattleRoom_EventScript_WarpToLobbyWon':
        ('MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY', 6, 6),
    'SlateportCity_BattleTent_EventScript_WarpToLobbyLost':
        ('MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY', 6, 6),
    'SlateportCity_BattleTentBattleRoom_EventScript_DefeatedOpponent':
        ('MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR', 2, 3),
}

# The native white-out callback resets the global script context. The next
# physical label is not a continuation of the losing battle's old script.
CONTEXT_CALLBACK_EXITS = {
    'MossdeepCity_SpaceCenter_2F_EventScript_DoStevenMultiBattle': 'SetCB2WhiteOut',
}

# The wait is physically present after an unconditional jump, so it cannot
# continue into the following winner label. Admit only this measured tail.
UNREACHABLE_WAIT_TAILS = {
    'BattleFrontier_BattleArenaBattleRoom_EventScript_ContinueChallenge':
        'BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers',
}

# Selector macros measured against the current JP assembler. Handler identity
# and waitstate are taken from the real Special table, not a US table index.
FACILITY_FORMS = {
    **{name: ('CallTrainerHillFunction', 8, ()) for name in (
        'trainerhill_start', 'trainerhill_getownerstate', 'trainerhill_giveprize',
        'trainerhill_finaltime', 'trainerhill_resumetimer', 'trainerhill_lost',
        'trainerhill_getstatus', 'trainerhill_gettime', 'trainerhill_allfloorsused',
        'trainerhill_getusingereader', 'trainerhill_inchallenge', 'trainerhill_postbattletext',
        'trainerhill_settrainerflags', 'trainerhill_getsaved', 'trainerhill_setsaved',
        'trainerhill_clearsaved', 'trainerhill_getwon')},
    **{name: ('CallBattlePikeFunction', 8, ()) for name in (
        'pike_setnextroom', 'pike_isfinalroom', 'pike_setroomobjects', 'pike_getroomtype',
        'pike_inwildmonroom', 'pike_exitwildmonroom', 'pike_getstatus', 'pike_getstatusmon',
        'pike_healonetwomons', 'pike_getnpcmsg', 'pike_flashscreen', 'pike_sethintroom',
        'pike_gethintroomid', 'pike_gethint', 'pike_cleartrainerids', 'pike_getbrainstatus',
        'pike_prequeenheal', 'pike_ispartyfullhealth', 'pike_savehelditems', 'pike_resethelditems',
        'pike_init')},
    'pike_get': ('CallBattlePikeFunction', 13, (r'PIKE_DATA_(?:WIN_STREAK|TOTAL_STREAKS)',)),
    'pike_set': ('CallBattlePikeFunction', 18, (r'PIKE_DATA_(?:WIN_STREAK|TOTAL_STREAKS|WIN_STREAK_ACTIVE)', r'(?:0|TRUE|FALSE|VAR_RESULT)')),
    'pike_save': ('CallBattlePikeFunction', 13, (r'(?:0|CHALLENGE_STATUS_(?:SAVING|PAUSED))',)),
    'pike_nohealing': ('CallBattlePikeFunction', 13, (r'(?:TRUE|FALSE)',)),
    'pike_gettrainerintro': ('CallBattlePikeFunction', 13, (r'[01]',)),
    'factory_init': ('CallBattleFactoryFunction', 8, ()),
    'factory_save': ('CallBattleFactoryFunction', 13, (r'(?:0|CHALLENGE_STATUS_(?:SAVING|PAUSED))',)),
    'factory_get': ('CallBattleFactoryFunction', 13, (r'FACTORY_DATA_WIN_STREAK(?:_SWAPS)?',)),
    'factory_rentmons': ('CallBattleFactoryFunction', 8, ()),
    'factory_swapmons': ('CallBattleFactoryFunction', 8, ()),
    'factory_setswapped': ('CallBattleFactoryFunction', 8, ()),
    'factory_generateopponentmons': ('CallBattleFactoryFunction', 8, ()),
    'factory_generaterentalmons': ('CallBattleFactoryFunction', 8, ()),
    'factory_getopponentmontype': ('CallBattleFactoryFunction', 8, ()),
    'factory_getopponentstyle': ('CallBattleFactoryFunction', 8, ()),
    'arena_init': ('CallBattleArenaFunction', 8, ()),
    'arena_gettrainername': ('CallBattleArenaFunction', 8, ()),
    'arena_save': ('CallBattleArenaFunction', 13, (r'(?:0|CHALLENGE_STATUS_(?:SAVING|PAUSED))',)),
    'pyramid_init': ('CallBattlePyramidFunction', 8, ()),
    'pyramid_get': ('CallBattlePyramidFunction', 13, (r'PYRAMID_DATA_WIN_STREAK(?:_(?:50|OPEN)|_ACTIVE_(?:50|OPEN))?',)),
    'pyramid_set': ('CallBattlePyramidFunction', 18, (r'PYRAMID_DATA_(?:WIN_STREAK|WIN_STREAK_ACTIVE|TRAINER_FLAGS)', r'(?:0|255|TRUE|FALSE)')),
    'pyramid_save': ('CallBattlePyramidFunction', 13, (r'(?:0|CHALLENGE_STATUS_SAVING)',)),
    'pyramid_setprize': ('CallBattlePyramidFunction', 8, ()),
    'pyramid_seedfloor': ('CallBattlePyramidFunction', 8, ()),
    'pyramid_settrainers': ('CallBattlePyramidFunction', 8, ()),
    'pyramid_updatelight': ('CallBattlePyramidFunction', 18, (r'(?:0|32|200)', r'PYRAMID_LIGHT_SET_RADIUS')),
    'pyramid_clearhelditems': ('CallBattlePyramidFunction', 8, ()),
    'pyramid_setfloorpal': ('CallBattlePyramidFunction', 8, ()),
    'pyramid_setitem': ('CallBattlePyramidFunction', 8, ()),
    'pyramid_hideitem': ('CallBattlePyramidFunction', 8, ()),
    'pyramid_showhint': ('CallBattlePyramidFunction', 8, ()),
    'pyramid_resetparty': ('CallBattlePyramidFunction', 8, ()),
    'frontier_checkvisittrainer': ('CallFrontierUtilFunc', 8, ()),
    'frontier_saveparty': ('CallFrontierUtilFunc', 8, ()),
    'frontier_results': ('CallFrontierUtilFunc', 13, (r'FACILITY_LINK_CONTEST',)),
    'frontier_getstatus': ('CallFrontierUtilFunc', 8, ()),
    'frontier_settrainers': ('CallFrontierUtilFunc', 8, ()),
    'frontier_gettrainername': ('CallFrontierUtilFunc', 13, (r'STR_VAR_[12]',)),
    'frontier_isbattletype': ('CallFrontierUtilFunc', 13, (r'BATTLE_TYPE_TRAINER',)),
    'frontier_get': ('CallFrontierUtilFunc', 13, (r'FRONTIER_DATA_\w+',)),
    'frontier_checkineligible': ('CallFrontierUtilFunc', 8, ()),
    'frontier_setpartyorder': ('CallFrontierUtilFunc', 13, (r'(?:[1-6]|FRONTIER_PARTY_SIZE|FRONTIER_MULTI_PARTY_SIZE)',)),
    'frontier_reset': ('CallFrontierUtilFunc', 8, ()),
    'frontier_restorehelditems': ('CallFrontierUtilFunc', 8, ()),
    'frontier_resetsketch': ('CallFrontierUtilFunc', 8, ()),
    'tower_setopponent': ('CallBattleTowerFunc', 8, ()),
    'tower_init': ('CallBattleTowerFunc', 8, ()),
    'tower_setinterviewdata': ('CallBattleTowerFunc', 8, ()),
    'tower_setbattlewon': ('CallBattleTowerFunc', 8, ()),
    'tower_get': ('CallBattleTowerFunc', 13, (r'TOWER_DATA_(?:WIN_STREAK|WIN_STREAK_ACTIVE|LVL_MODE)',)),
    'tower_getopponentintro': ('CallBattleTowerFunc', 13, (r'[01]',)),
    'tower_loadpartners': ('CallBattleTowerFunc', 8, ()),
    'tower_setpartnergfx': ('CallBattleTowerFunc', 8, ()),
    'tower_dopartnermsg': ('CallBattleTowerFunc', 13, (r'PARTNER_MSGID_(?:INTRO|MON1|MON2_ASK|ACCEPT|REJECT)',)),
    'tower_giveribbons': ('CallBattleTowerFunc', 8, ()),
    'tower_save': ('CallBattleTowerFunc', 13, (r'(?:CHALLENGE_STATUS_(?:SAVING|PAUSED)|0)',)),
    'tower_loadlinkopponents': ('CallBattleTowerFunc', 8, ()),
    'tower_closelink': ('CallBattleTowerFunc', 8, ()),
    'dome_init': ('CallBattleDomeFunction', 8, ()),
    'dome_get': ('CallBattleDomeFunction', 13, (r'DOME_DATA_(?:PREV_TOURNEY_TYPE|ATTEMPTED_CHALLENGE|HAS_WON_CHALLENGE|WIN_STREAK_ACTIVE)',)),
    'dome_getroundtext': ('CallBattleDomeFunction', 8, ()),
    'dome_getopponentname': ('CallBattleDomeFunction', 8, ()),
    'dome_initopponentparty': ('CallBattleDomeFunction', 8, ()),
    'dome_showopponentinfo': ('CallBattleDomeFunction', 8, ()),
    'dome_showtourneytree': ('CallBattleDomeFunction', 8, ()),
    'dome_showprevtourneytree': ('CallBattleDomeFunction', 8, ()),
    'dome_setopponent': ('CallBattleDomeFunction', 8, ()),
    'dome_setopponentgfx': ('CallBattleDomeFunction', 8, ()),
    'dome_showstatictourneytree': ('CallBattleDomeFunction', 8, ()),
    'dome_resolvewinners': ('CallBattleDomeFunction', 13, (r'DOME_PLAYER_(?:WON_MATCH|LOST_MATCH|RETIRED)',)),
    'dome_save': ('CallBattleDomeFunction', 13, (r'(?:CHALLENGE_STATUS_(?:SAVING|PAUSED)|0)',)),
    'dome_settrainers': ('CallBattleDomeFunction', 8, ()),
    'dome_resetsketch': ('CallBattleDomeFunction', 8, ()),
    'dome_restorehelditems': ('CallBattleDomeFunction', 8, ()),
    'dome_reduceparty': ('CallBattleDomeFunction', 8, ()),
    'dome_compareseeds': ('CallBattleDomeFunction', 8, ()),
    'dome_getwinnersname': ('CallBattleDomeFunction', 8, ()),
    'dome_initresultstree': ('CallBattleDomeFunction', 8, ()),
    'dome_inittrainers': ('CallBattleDomeFunction', 8, ()),
    'palace_init': ('CallBattlePalaceFunction', 8, ()),
    'palace_get': ('CallBattlePalaceFunction', 13, (r'PALACE_DATA_PRIZE',)),
    'palace_set': ('CallBattlePalaceFunction', 18, (r'PALACE_DATA_(?:WIN_STREAK|WIN_STREAK_ACTIVE)', r'(?:0|TRUE|FALSE)')),
    'palace_getcomment': ('CallBattlePalaceFunction', 8, ()),
    'palace_getopponentintro': ('CallBattlePalaceFunction', 8, ()),
    'palace_incrementstreak': ('CallBattlePalaceFunction', 8, ()),
    'palace_save': ('CallBattlePalaceFunction', 13, (r'(?:0|CHALLENGE_STATUS_(?:SAVING|PAUSED))',)),
    'frontier_getsymbols': ('CallFrontierUtilFunc', 8, ()),
    'frontier_givesymbol': ('CallFrontierUtilFunc', 8, ()),
    'frontier_setbrainobj': ('CallFrontierUtilFunc', 8, ()),
    'frontier_incrementstreak': ('CallFrontierUtilFunc', 8, ()),
    'frontier_getbrainstatus': ('CallFrontierUtilFunc', 8, ()),
    'frontier_checkairshow': ('CallFrontierUtilFunc', 8, ()),
    'frontier_isbrain': ('CallFrontierUtilFunc', 8, ()),
    'frontier_givepoints': ('CallFrontierUtilFunc', 8, ()),
    'frontier_savebattle': ('CallFrontierUtilFunc', 8, ()),
    'apprentice_gavelvlmode': ('CallApprenticeFunction', 8, ()),
    'apprentice_setlvlmode': ('CallApprenticeFunction', 18, (r'VAR_RESULT',)),
    'apprentice_answeredquestion': ('CallApprenticeFunction', 8, ()),
    'apprentice_menu': ('CallApprenticeFunction', 14, (r'APPRENTICE_ASK_\w+',)),
    'apprentice_shufflespecies': ('CallApprenticeFunction', 8, ()),
    'apprentice_randomizequestions': ('CallApprenticeFunction', 8, ()),
    'apprentice_msg': ('CallApprenticeFunction', 19, (r'(?:TRUE|FALSE)', r'APPRENTICE_MSG_\w+')),
    'apprentice_reset': ('CallApprenticeFunction', 8, ()),
    'apprentice_shouldcheckgone': ('CallApprenticeFunction', 8, ()),
    'apprentice_getquestion': ('CallApprenticeFunction', 8, ()),
    'apprentice_getnumpartymons': ('CallApprenticeFunction', 8, ()),
    'apprentice_setpartymon': ('CallApprenticeFunction', 13, (r'VAR_RESULT',)),
    'apprentice_initquestion': ('CallApprenticeFunction', 13, (r'APPRENTICE_QUESTION_\w+',)),
    'apprentice_freequestion': ('CallApprenticeFunction', 8, ()),
    'apprentice_buff': ('CallApprenticeFunction', 18, (r'STR_VAR_[123]', r'(?:APPRENTICE_BUFF_\w+|VAR_0x8007)')),
    'apprentice_setmove': ('CallApprenticeFunction', 8, ()),
    'apprentice_setleadmon': ('CallApprenticeFunction', 13, (r'VAR_RESULT',)),
    'apprentice_openbag': ('CallApprenticeFunction', 9, ()),
    'apprentice_trysetitem': ('CallApprenticeFunction', 8, ()),
    'apprentice_save': ('CallApprenticeFunction', 8, ()),
    'apprentice_setgfx': ('CallApprenticeFunction', 8, ()),
    'apprentice_shouldleave': ('CallApprenticeFunction', 8, ()),
    'apprentice_shiftsaved': ('CallApprenticeFunction', 8, ()),
    'arena_get': ('CallBattleArenaFunction', 13, (r'ARENA_DATA_\w+',)),
    'arena_set': ('CallBattleArenaFunction', 18, (r'ARENA_DATA_\w+', r'(?:VAR_\w+|\d+|TRUE|FALSE)')),
    'fallarbortent_init': ('CallFallarborTentFunction', 8, ()),
    'fallarbortent_getprize': ('CallFallarborTentFunction', 8, ()),
    'fallarbortent_save': ('CallFallarborTentFunction', 13, (r'(?:CHALLENGE_STATUS_\w+|0)',)),
    'fallarbortent_setrandomprize': ('CallFallarborTentFunction', 8, ()),
    'fallarbortent_giveprize': ('CallFallarborTentFunction', 8, ()),
    'fallarbortent_getopponentname': ('CallFallarborTentFunction', 8, ()),
    'battletent_getopponentintro': ('CallVerdanturfTentFunction', 8, ()),
    'verdanturftent_init': ('CallVerdanturfTentFunction', 8, ()),
    'verdanturftent_getprize': ('CallVerdanturfTentFunction', 8, ()),
    'verdanturftent_save': ('CallVerdanturfTentFunction', 13, (r'(?:CHALLENGE_STATUS_\w+|0)',)),
    'verdanturftent_setrandomprize': ('CallVerdanturfTentFunction', 8, ()),
    'verdanturftent_giveprize': ('CallVerdanturfTentFunction', 8, ()),
    'slateporttent_init': ('CallSlateportTentFunction', 8, ()),
    'slateporttent_getprize': ('CallSlateportTentFunction', 8, ()),
    'slateporttent_save': ('CallSlateportTentFunction', 13, (r'(?:CHALLENGE_STATUS_\w+|0)',)),
    'slateporttent_setrandomprize': ('CallSlateportTentFunction', 8, ()),
    'slateporttent_giveprize': ('CallSlateportTentFunction', 8, ()),
    'slateporttent_rentmons': ('CallSlateportTentFunction', 8, ()),
    'slateporttent_swapmons': ('CallSlateportTentFunction', 8, ()),
    'slateporttent_generateopponentmons': ('CallSlateportTentFunction', 8, ()),
    'slateporttent_generaterentalmons': ('CallSlateportTentFunction', 8, ()),
    'factory_setopponentmons': ('CallBattleFactoryFunction', 8, ()),
    'factory_resethelditems': ('CallBattleFactoryFunction', 8, ()),
    'factory_setparties': ('CallBattleFactoryFunction', 13, (r'[01]',)),
    'factory_setopponentgfx': ('CallBattleFactoryFunction', 8, ()),
}

# Only explicitly measured forms are supported. The final NO_MUSIC argument
# selects a mode; it is not a pointer or an independently emitted field.
TRAINER_FORMS = {
    ('trainerbattle', 5): ('TRAINER_BATTLE_PYRAMID', 'EventScript_TryDoNormalTrainerBattle',
                         'sOrdinaryBattleParams'),
    ('trainerbattle_single', 3): ('TRAINER_BATTLE_SINGLE', 'EventScript_TryDoNormalTrainerBattle',
                                'sOrdinaryBattleParams'),
    ('trainerbattle_single', 4): ('TRAINER_BATTLE_CONTINUE_SCRIPT', 'EventScript_TryDoNormalTrainerBattle',
                                'sContinueScriptBattleParams'),
    ('trainerbattle_single', 5): ('TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC', 'EventScript_TryDoNormalTrainerBattle',
                                'sContinueScriptBattleParams'),
    ('trainerbattle', 6): ('TRAINER_BATTLE_CONTINUE_SCRIPT', 'EventScript_TryDoNormalTrainerBattle',
                         'sContinueScriptBattleParams'),
    ('trainerbattle_double', 4): ('TRAINER_BATTLE_DOUBLE', 'EventScript_TryDoDoubleTrainerBattle',
                                'sDoubleBattleParams'),
    ('trainerbattle_double', 5): ('TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE', 'EventScript_TryDoDoubleTrainerBattle',
                                'sContinueScriptDoubleBattleParams'),
    ('trainerbattle_double', 6): ('TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC', 'EventScript_TryDoDoubleTrainerBattle',
                                'sContinueScriptDoubleBattleParams'),
    ('trainerbattle_rematch', 3): ('TRAINER_BATTLE_REMATCH', 'EventScript_TryDoRematchBattle',
                                 'sOrdinaryBattleParams'),
    ('trainerbattle_rematch_double', 4): ('TRAINER_BATTLE_REMATCH_DOUBLE', 'EventScript_TryDoDoubleRematchBattle',
                                        'sDoubleBattleParams'),
}


@dataclass
class BlockProfile:
    size: int = 0
    kind: str = 'script'
    targets: dict[str, str] = field(default_factory=dict)
    texts: dict[str, str] = field(default_factory=dict)
    specials: dict[str, int] = field(default_factory=dict)
    runtime_scripts: set[str] = field(default_factory=set)
    runtime_texts: dict[str, str] = field(default_factory=dict)
    standard_scripts: dict[int, str] = field(default_factory=dict)
    layouts: set[str] = field(default_factory=set)
    trainer_battles: list[dict] = field(default_factory=list)
    trainer_run: bool = False
    trainer_post_return: bool = False
    trainer_beaten_return: bool = False
    fallthrough: str | None = None
    may_fall_through: bool = False
    context_warp: str | None = None
    context_callback: str | None = None


def special_waits(root: Path) -> dict[str, int]:
    result = {}
    for raw in (root / 'data/specials.inc').read_text().splitlines():
        line = raw.split('@', 1)[0].strip()
        if not re.match(r'def_special(?:\s|$)', line):
            continue
        match = re.fullmatch(r'def_special\s+([A-Za-z_]\w*)(?:,\s*waitstate=([01]))?', line)
        if not match:
            raise ValueError('invalid_special_profile:' + line)
        wait = int(match[2] or 0)
        if match[1] in result and result[match[1]] != wait:
            raise ValueError('conflicting_special_wait_profile:' + line)
        # The real table can repeat the same handler at different indices;
        # its single SPECIAL_WAITSTATE_<handler> contract must stay consistent.
        result[match[1]] = wait
    if not result:
        raise ValueError('missing_special_profile')
    return result


def _multi_intro_message(owner: str | None, lines: list[str], position: int, operation: str) -> bool:
    """Only the four native-checked Multi introductions retain this RAM producer.

    These precise delay/movement windows do not model general data flow or
    permit arbitrary commands between a producer and a message consumer.
    """
    prefix = 'BattleFrontier_BattleTowerMultiBattleRoom'
    expected = prefix + '_EventScript_' + ('OpponentsEnter' if operation == 'msgbox' else 'DoOpponentIntrosLink')
    if operation not in ('msgbox', 'messageautoscroll') or owner != expected:
        return False
    for index in (0, 1):
        window = ['tower_getopponentintro ' + str(index)]
        if index == 0:
            window.append('delay 15')
        window.append(f'applywaitmovement LOCALID_TOWER_MULTI_BATTLE_OPPONENT_{index + 1}, {prefix}_Movement_WalkInPlaceLeft')
        if position >= len(window) and lines[position - len(window):position] == window:
            return True
    return False


def profile_block(root: Path, block: str, waits=None, *, version=3, address=None) -> BlockProfile:
    if version not in (3, 4):
        raise ValueError('unsupported_story_profile_version')
    if version == 4 and (type(address) is not int or not 0x08000000 <= address < 0x09000000):
        raise ValueError('missing_or_invalid_story_native_address')
    kind = text_kind(block)
    if kind:
        return BlockProfile(size=len(encoded_text(root, block, kind)), kind=kind)
    lines = statements(block)
    if not lines:
        raise ValueError('empty_profile_block')
    owner = re.search(r'(?m)^([A-Za-z_]\w*)::?', block)
    if (version == 4 and owner and owner[1] == 'BattleFrontier_BattleTowerLobby_EventScript_SaveBeforeLinkMultisChallenge'
            and any(line.startswith('#') for line in lines)):
        guarded = [('tower_save 0',), ('incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER',)]
        starts = [i for i, line in enumerate(lines) if line == '#ifndef BUGFIX']
        if (len(starts) != 2 or any(lines[i:i + 3] != ['#ifndef BUGFIX', body[0], '#endif']
                                   for i, body in zip(starts, guarded))
                or [i for i, line in enumerate(lines) if line.startswith('#')]
                != [starts[0], starts[0] + 2, starts[1], starts[1] + 2]):
            raise ValueError('unsupported_tower_link_save_conditional')
        # Evaluate only this exact existing pair of guards with the current
        # project configuration. The native proof independently selects the
        # same default build; enabling BUGFIX must not silently retain bytes.
        configured = subprocess.check_output(
            ['cpp', '-P', '-nostdinc', '-undef', '-include', str(root / 'include/config.h'), '-'],
            input='\n'.join(lines) + '\n', text=True)
        lines = statements(configured)
    elif (version == 4 and owner and owner[1] == 'TrainerHill_1F_EventScript_DummyOnWarp'
          and any(line.startswith('#') for line in lines)):
        if lines != ['setvar VAR_TEMP_3, 1', '#ifdef BUGFIX', 'end', '#endif']:
            raise ValueError('unsupported_trainer_hill_warp_conditional')
        configured = subprocess.check_output(
            ['cpp', '-P', '-nostdinc', '-undef', '-include', str(root / 'include/config.h'), '-'],
            input='\n'.join(lines) + '\n', text=True)
        lines = statements(configured)
    elif version == 4 and any(line.startswith('#') for line in lines):
        conditional = ['#ifdef UBFIX', 'setvar VAR_ICE_STEP_COUNT, 1', '#else',
                       'copyvar VAR_ICE_STEP_COUNT, 1, warn=FALSE', '#endif']
        starts = [i for i, line in enumerate(lines) if line == conditional[0]]
        directives = [i for i, line in enumerate(lines) if line.startswith('#')]
        if (len(starts) != 1 or lines[starts[0]:starts[0] + 5] != conditional
                or directives != [starts[0], starts[0] + 2, starts[0] + 4]):
            raise ValueError('unsupported_profile_conditional')
        # Only these exact branches share a five-byte, edge-free shape.
        # Keep surrounding calls and termination in the profile; actual
        # CPP/AS/native checks still select the configured source opcode.
        lines[starts[0]:starts[0] + 5] = ['copyvar VAR_ICE_STEP_COUNT, 1']
    if any(';' in line for line in lines):
        raise ValueError('unmodeled_statement_separator')
    if version == 4 and owner and owner[1] == 'MauvilleCity_GameCorner_MapScripts':
        expected = ['.byte 0'] + [f'.set {name}, {value}' for name, value in GAME_CORNER_PRICES.items()]
        if lines != expected:
            raise ValueError('changed_game_corner_price_definitions')
        # These US-style local prices emit no bytes, unlike address aliases.
        return BlockProfile(size=1, kind='map_table')
    if version == 4 and owner and owner[1] == 'BattleFrontier_Lounge3_MapScripts':
        expected = ['.byte 0'] + [f'.set BET_AMOUNT_{value}, {value}'
                                 for value in FRONTIER_BET_AMOUNTS]
        if [re.sub(r'\s+', ' ', line) for line in lines] != expected:
            raise ValueError('changed_frontier_bet_definitions')
        # These are the three original US-style scalar constants, not
        # address aliases. They add no bytes to the one-byte map table.
        return BlockProfile(size=1, kind='map_table')
    if version == 4 and owner and owner[1] == 'Route113_GlassWorkshop_MapScripts':
        expected = ['map_script MAP_SCRIPT_ON_TRANSITION, Route113_GlassWorkshop_OnTransition',
                    '.byte 0'] + [f'.set {name}, {value}' for name, value in GLASS_WORKSHOP_PRICES.items()]
        expected.append('.set LOWEST_ASH_PRICE, BLUE_FLUTE_PRICE')
        normalized = [re.sub(r'\s+', ' ', line) for line in lines]
        if normalized != expected:
            raise ValueError('changed_glass_workshop_price_definitions')
        # Seven scalar prices and their minimum alias emit zero bytes;
        # the actual transition pointer/table still occupies six bytes.
        return BlockProfile(size=6, kind='map_table',
                            targets={'Route113_GlassWorkshop_OnTransition': 'script'})
    operations = [line.split(None, 1)[0] for line in lines]
    movements = MOVEMENTS_V4 if version == 4 else MOVEMENTS
    fixed = FIXED_V4 if version == 4 else FIXED
    standard = STANDARD_V4 if version == 4 else STANDARD
    if version == 4 and 'pokemartlistend' in operations:
        if (operations[-1] != 'pokemartlistend' or operations.count('pokemartlistend') != 1
                or len(lines) < 2 or address % 4 or lines[-1] != 'pokemartlistend'):
            raise ValueError('invalid_shop_table_termination_or_alignment')
        entries = [re.fullmatch(r'\.2byte\s+((ITEM|DECOR)_\w+)', line) for line in lines[:-1]]
        if (not all(entries) or len({e[2] for e in entries}) != 1
                or any(e[1] in ('ITEM_NONE', 'DECOR_NONE') for e in entries)):
            raise ValueError('mixed_or_unmodeled_shop_table')
        return BlockProfile(size=2 * len(entries) + 4,
                            kind='mart_items' if entries[0][2] == 'ITEM' else 'mart_decorations')
    if any(op in movements for op in operations):
        ends = operations.count('step_end')
        owner = re.search(r'(?m)^([A-Za-z_]\w*)::?', block)
        prefix = (MOVEMENT_PREFIXES.get(owner[1]) if version == 4 and owner else None)
        if prefix and not ends:
            target, expected = prefix
            if lines != list(expected):
                raise ValueError('unsupported_movement_prefix')
            return BlockProfile(size=len(lines), kind='movement', targets={target: 'movement'},
                                fallthrough=target, may_fall_through=True)
        if (any(op not in movements for op in operations) or operations[-1] != 'step_end'
                or ends not in ((1, 2) if version == 4 else (1,))
                or operations[-ends:] != ['step_end'] * ends):
            raise ValueError('mixed_or_unterminated_movement')
        if any(len(line.split()) != 1 for line in lines):
            raise ValueError('unsupported_movement_arguments')
        return BlockProfile(size=len(lines), kind='movement')
    result = BlockProfile()
    if (version == 4 and owner
            and re.fullmatch(r'TrainerHill_[1-4]F_MapScripts', owner[1])):
        expected = ['map_script MAP_SCRIPT_ON_RESUME, TrainerHill_OnResume',
                    'map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, TrainerHill_OnWarp',
                    'map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_OnFrame', '.byte 0']
        if owner[1] in ('TrainerHill_3F_MapScripts', 'TrainerHill_4F_MapScripts'):
            expected.pop(1)
        if lines != expected:
            raise ValueError('changed_trainer_hill_floor_callbacks')
        # These floors receive trainers from C-generated object templates;
        # their JSON's empty object array is not the runtime object list.
        result.targets['TrainerHill_EventScript_TrainerBattle'] = 'script'
        result.runtime_scripts.add('trainer_hill_trainers')
    if lines == ['.byte 0']:
        return BlockProfile(size=1, kind='map_table')
    table_ops = set(operations) & {'map_script', 'map_script_2'}
    if table_ops:
        if len(table_ops) != 1:
            raise ValueError('mixed_map_table_formats')
        table_op = next(iter(table_ops))
        terminator = '.byte' if table_op == 'map_script' else '.2byte'
        if (set(operations) != {table_op, terminator} or operations[-1] != terminator
                or operations.count(terminator) != 1):
            raise ValueError('invalid_map_table_terminator')
        result.kind = 'map_table' if table_op == 'map_script' else 'condition_table'
    def target(value, expected):
        if not NAME.fullmatch(value):
            raise ValueError('nonsemantic_profile_target:' + value)
        if value in result.targets and result.targets[value] != expected:
            raise ValueError('incompatible_profile_target:' + value)
        result.targets[value] = expected
    for position, line in enumerate(lines):
        parts = line.split(None, 1)
        op = parts[0]
        args = [v.strip() for v in parts[1].split(',')] if len(parts) == 2 else []
        if (version == 4 and op == 'frontier_set'
                and args == ['FRONTIER_DATA_CHALLENGE_STATUS CHALLENGE_STATUS_LOST']):
            # The shared Pike retire script uses this US assembler spelling.
            args = ['FRONTIER_DATA_CHALLENGE_STATUS', 'CHALLENGE_STATUS_LOST']
        if any(not ATOM.fullmatch(arg) and not (version == 4 and (
               op == 'goto_if_ge' and index == 1 and arg in COIN_CAPACITY_EXPRESSIONS
               or index == 1 and owner and any(
                   owner[1] == f'BattleFrontier_Lounge3_EventScript_RewardBet{value}'
                   and arg == f'(BET_AMOUNT_{value} * 2)'
                   and (op == 'buffernumberstring' and args[0] == 'STR_VAR_1'
                        or op == 'setvar' and args[0] == 'VAR_0x8004')
                   for value in FRONTIER_BET_AMOUNTS)
               or op == 'setfieldeffectargument' and index == 1 and owner
               and owner[1] == 'BirthIsland_Exterior_EventScript_Deoxys'
               and (args[0], arg) in (('1', 'MAP_NUM(MAP_BIRTH_ISLAND_EXTERIOR)'),
                                      ('2', 'MAP_GROUP(MAP_BIRTH_ISLAND_EXTERIOR)'))
               or op == 'goto_if_eq' and index == 1 and args[0] == 'VAR_RESULT' and arg == FAN_CLUB_NONFAN_EXPRESSION
               or op == 'setberrytree' and index == 1 and owner
               and owner[1] == 'EventScript_ResetAllBerries'
               and re.fullmatch(r'ITEM_TO_BERRY\(ITEM_[A-Z0-9_]+_BERRY\)', arg)
               or op == 'copyvar' and index == 2 and arg == 'warn=FALSE')) for index, arg in enumerate(args)):
            raise ValueError('unsupported_profile_argument_expression:' + op)
        if version == 4 and op == 'copyvar' and len(args) == 3:
            if args != ['VAR_LILYCOVE_MUSEUM_2F_STATE', '1', 'warn=FALSE']:
                raise ValueError('unsupported_profile_warn_suppressed_copy')
            # Warning suppression emits nothing; preserve the JP COPYVAR opcode.
            size = 5
        elif op in fixed:
            size, count = fixed[op]
            if len(args) != count:
                raise ValueError('unsupported_profile_arguments:' + op)
            if op == 'warp' and not re.fullmatch(r'MAP_\w+', args[0]):
                raise ValueError('unsupported_profile_warp')
        elif (op in ('call', 'goto', 'call_if_eq', 'goto_if_eq', 'case')
              or version == 4 and op in ('goto_if_ge', 'goto_if_le', 'goto_if_ne', 'goto_if_lt',
                                         'goto_if_gt', 'call_if_ne', 'call_if_ge', 'call_if_lt', 'call_if_le', 'call_if_gt')):
            count = 2 if op == 'case' else 3 if '_if_' in op else 1
            if len(args) != count:
                raise ValueError('unsupported_profile_arguments:' + op)
            if count == 3 and not re.fullmatch(r'VAR_\w+', args[0]):
                raise ValueError('unsupported_profile_compare')
            if op in ('call_if_ge', 'call_if_lt', 'call_if_le', 'call_if_gt') and args[-1] == 'NULL':
                raise ValueError('unsupported_profile_null_call')
            size = 11 if count in (2, 3) else 5
            target(args[-1], 'script')
        elif version == 4 and op in ('goto_if_set', 'goto_if_unset', 'call_if_set', 'call_if_unset'):
            if len(args) != 2 or not re.fullmatch(r'FLAG_\w+', args[0]):
                raise ValueError('unsupported_profile_flag_branch')
            target(args[-1], 'script')
            size = 9
        elif version == 4 and op in ('goto_if_defeated', 'goto_if_not_defeated',
                                    'call_if_defeated', 'call_if_not_defeated'):
            if len(args) != 2 or not re.fullmatch(r'TRAINER_\w+', args[0]):
                raise ValueError('unsupported_profile_trainer_flag_branch')
            target(args[1], 'script')
            size = 9
        elif version == 4 and op in ('cleartrainerflag', 'settrainerflag'):
            if len(args) != 1 or not re.fullmatch(r'TRAINER_\w+', args[0]):
                raise ValueError('unsupported_profile_' + op)
            size = 3
        elif version == 4 and op == 'seteventmon':
            lati = (len(args) in (2, 3) and args[0] in ('SPECIES_LATIAS', 'SPECIES_LATIOS')
                    and args[1] == '50' and (len(args) == 2 or args[2] in ('ITEM_NONE', 'ITEM_SOUL_DEW')))
            mew = (owner and owner[1] == 'FarawayIsland_Interior_EventScript_Mew'
                   and args == ['SPECIES_MEW', '30'])
            deoxys = (owner and owner[1] == 'BirthIsland_Exterior_EventScript_Deoxys'
                      and args == ['SPECIES_DEOXYS', '30'])
            navel = (owner and (owner[1], args) in (
                ('NavelRock_Top_EventScript_HoOh', ['SPECIES_HO_OH', '70']),
                ('NavelRock_Bottom_EventScript_Lugia', ['SPECIES_LUGIA', '70'])))
            if not (lati or mew or deoxys or navel):
                raise ValueError('unsupported_profile_seteventmon')
            waits = special_waits(root) if waits is None else waits
            function = 'CreateEnemyEventMon'
            if waits.get(function) not in (0, 1):
                raise ValueError('missing_event_mon_special')
            result.specials[function] = waits[function]
            size = 18 + waits[function]
        elif version == 4 and op == 'setwildbattle':
            if (len(args) not in (2, 3) or not re.fullmatch(r'SPECIES_\w+', args[0])
                    or not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', args[1])
                    or not 0 <= int(args[1], 16 if args[1].lower().startswith('0x') else 10) <= 255
                    or len(args) == 3 and not re.fullmatch(r'ITEM_\w+', args[2])):
                raise ValueError('unsupported_profile_setwildbattle')
            size = 6
        elif version == 4 and op in ('setwarp', 'warpspinenter', 'setdynamicwarp', 'warpmossdeepgym'):
            if (len(args) != 3 or not re.fullmatch(r'MAP_\w+', args[0])
                    or any(not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', value)
                           or not 0 <= int(value, 16 if value.lower().startswith('0x') else 10) <= 65535
                           for value in args[1:])):
                raise ValueError('unsupported_profile_setwarp')
            size = 8
        elif version == 4 and op in ('fadeoutbgm', 'fadeinbgm'):
            if (len(args) != 1 or not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', args[0])
                    or not 0 <= int(args[0], 16 if args[0].lower().startswith('0x') else 10) <= 255):
                raise ValueError('unsupported_profile_bgm_fade')
            size = 2
        elif version == 4 and op == 'turnvobject':
            if (len(args) != 2
                    or not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', args[0])
                    or int(args[0], 16 if args[0].lower().startswith('0x') else 10) > 255
                    or args[1] not in ('DIR_SOUTH', 'DIR_NORTH', 'DIR_WEST', 'DIR_EAST')):
                raise ValueError('unsupported_profile_virtual_object_turn')
            size = 3
        elif version == 4 and op == 'createvobject':
            def literal_in_range(value, maximum):
                return (re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', value)
                        and 0 <= int(value, 16 if value.lower().startswith('0x') else 10) <= maximum)
            if (len(args) not in (4, 5, 6)
                    or not re.fullmatch(r'OBJ_EVENT_GFX_\w+', args[0])
                    or not literal_in_range(args[1], 255)
                    or any(not (re.fullmatch(r'VAR_\w+', value) or literal_in_range(value, 65535))
                           for value in args[2:4])
                    or len(args) >= 5 and not literal_in_range(args[4], 255)
                    or len(args) == 6 and args[5] not in ('DIR_SOUTH', 'DIR_NORTH', 'DIR_WEST', 'DIR_EAST')):
                raise ValueError('unsupported_profile_virtual_object')
            # Opcode, graphics/id bytes, two variable-or-literal halfwords,
            # then elevation/direction bytes (including the macro defaults).
            size = 9
        elif version == 4 and op == 'dofieldeffectsparkle':
            trick = (owner and owner[1] == 'Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle'
                     and args == ['VAR_0x8004', 'VAR_0x8005', 'VAR_0x8006'])
            if not trick and (len(args) != 3
                    or any(not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', value)
                           for value in args)):
                raise ValueError('unsupported_profile_sparkle')
            if not trick:
                values = [int(value, 16 if value.lower().startswith('0x') else 10) for value in args]
                if any(not 0 <= value <= 65535 for value in values[:2]) or not 0 <= values[2] <= 3:
                    raise ValueError('unsupported_profile_sparkle')
            # Three four-byte argument writes and one three-byte field effect.
            size = 15
        elif version == 4 and op == 'setholewarp':
            if len(args) != 1 or not re.fullmatch(r'MAP_\w+', args[0]):
                raise ValueError('unsupported_profile_setholewarp')
            size = 8
        elif version == 4 and op == 'warphole':
            if len(args) != 1 or not re.fullmatch(r'MAP_\w+', args[0]):
                raise ValueError('unsupported_profile_warphole')
            size = 3
        elif version == 4 and op == 'initrotatingtilepuzzle':
            trick = (owner and owner[1] in {'Route110_TrickHousePuzzle7_EventScript_' + color + 'Button'
                                          for color in ('Yellow', 'Blue', 'Green', 'Purple', 'Red')}
                     and args == ['TRUE'])
            if args != ['FALSE'] and not trick:
                raise ValueError('unsupported_profile_rotating_tile_initialization')
            size = 3
        elif version == 4 and op == 'warpteleport':
            if (not owner or owner[1] != 'Route110_TrickHousePuzzle7_EventScript_TeleportPad'
                    or args != ['MAP_ROUTE110_TRICK_HOUSE_PUZZLE7', '3', '19']):
                raise ValueError('unsupported_profile_teleport_warp')
            size = 8
        elif version == 4 and op == 'moverotatingtileobjects':
            if len(args) != 1 or not re.fullmatch(r'(?:0x[0-4]|[0-4])', args[0]):
                raise ValueError('unsupported_profile_rotating_tile_number')
            size = 6
        elif version == 4 and op == 'trywondercardscript':
            if args:
                raise ValueError('unsupported_profile_arguments:trywondercardscript')
            result.runtime_scripts.add('saved_wonder_card')
            size = 1
        elif version == 4 and (op in FACILITY_FORMS or op in ('frontier_set', 'tower_set', 'dome_set', 'factory_set')):
            if op in ('frontier_set', 'tower_set', 'dome_set', 'factory_set'):
                selector = {'frontier_set': r'FRONTIER_DATA_\w+',
                            'tower_set': r'TOWER_DATA_(?:WIN_STREAK|WIN_STREAK_ACTIVE|LVL_MODE)',
                            'dome_set': r'DOME_DATA_(?:WIN_STREAK|WIN_STREAK_ACTIVE|ATTEMPTED_CHALLENGE|HAS_WON_CHALLENGE|SELECTED_MONS)',
                            'factory_set': r'FACTORY_DATA_WIN_STREAK(?:_ACTIVE|_SWAPS)?'}[op]
                if (len(args) not in (1, 2) or not re.fullmatch(selector, args[0])
                        or len(args) == 2 and not re.fullmatch(r'(?:[A-Z][A-Z0-9_]*|0x[0-9A-Fa-f]+|\d+)', args[1])):
                    raise ValueError('unsupported_profile_facility_macro:' + op)
                if op == 'dome_set' and len(args) == 2 and args[1] not in ('0', 'TRUE', 'FALSE', '0xFFFF', '65535'):
                    raise ValueError('unsupported_profile_facility_macro:' + op)
                if (op == 'factory_set' and len(args) == 2
                        and args[1] not in ('0', 'TRUE', 'FALSE', 'VAR_RESULT', '0xFFFF', '65535')):
                    raise ValueError('unsupported_profile_facility_macro:' + op)
                omitted = len(args) == 1 or args[1].lower() in ('0xffff', '65535')
                function = {'frontier_set': 'CallFrontierUtilFunc', 'tower_set': 'CallBattleTowerFunc',
                            'dome_set': 'CallBattleDomeFunction', 'factory_set': 'CallBattleFactoryFunction'}[op]
                size = 13 if omitted else 18
            elif op == 'frontier_results':
                valid = (len(args) == 1 and args[0] in ('FACILITY_LINK_CONTEST', 'FRONTIER_FACILITY_TOWER', 'FRONTIER_FACILITY_PYRAMID', 'FRONTIER_FACILITY_ARENA', 'FRONTIER_FACILITY_PIKE')
                         or len(args) == 2 and args[0] == 'FRONTIER_FACILITY_TOWER'
                         and re.fullmatch(r'(?:FRONTIER_MODE_(?:SINGLES|DOUBLES|MULTIS|LINK_MULTIS)|0xFF|255)', args[1])
                         or len(args) == 2 and args[0] in ('FRONTIER_FACILITY_DOME', 'FRONTIER_FACILITY_PALACE', 'FRONTIER_FACILITY_FACTORY')
                         and args[1] in ('FRONTIER_MODE_SINGLES', 'FRONTIER_MODE_DOUBLES'))
                if not valid:
                    raise ValueError('unsupported_profile_facility_macro:' + op)
                function, size = 'CallFrontierUtilFunc', 13 if len(args) == 1 or args[1] in ('0xFF', '255') else 18
            else:
                function, size, patterns = FACILITY_FORMS[op]
                if len(args) != len(patterns) or any(not re.fullmatch(p, a) for p, a in zip(patterns, args)):
                    raise ValueError('unsupported_profile_facility_macro:' + op)
                if (op == 'arena_set' and args[1] in ('TRUE', 'FALSE')
                        and args[0] != 'ARENA_DATA_WIN_STREAK_ACTIVE'):
                    raise ValueError('unsupported_profile_facility_macro:' + op)
            waits = special_waits(root) if waits is None else waits
            if waits.get(function) not in (0, 1):
                raise ValueError('missing_facility_macro_special:' + function)
            if op in ('apprentice_menu', 'apprentice_msg', 'apprentice_openbag') and waits[function]:
                raise ValueError('duplicate_apprentice_macro_waitstate')
            result.specials[function] = waits[function]
            size += waits[function]
        elif version == 4 and op == 'erasebox':
            if (len(args) != 4 or any(not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', value)
                                     or not 0 <= int(value, 16 if value.lower().startswith('0x') else 10) <= 255
                                     for value in args)):
                raise ValueError('unsupported_profile_erasebox')
            size = 5
        elif version == 4 and op == 'multichoicegrid':
            if (len(args) != 5 or any(not a.isdecimal() or int(a) > 255 for a in args[:2])
                    or not re.fullmatch(r'MULTI_\w+', args[2])
                    or not args[3].isdecimal() or not 1 <= int(args[3]) <= 255
                    or args[4] not in ('FALSE', 'TRUE', '0', '1')):
                raise ValueError('unsupported_profile_multichoice_grid')
            size = 6
        elif version == 4 and op == 'setrespawn':
            if len(args) != 1 or not re.fullmatch(r'HEAL_LOCATION_\w+', args[0]):
                raise ValueError('unsupported_profile_setrespawn')
            size = 3
        elif version == 4 and op in ('setflashlevel', 'animateflash'):
            if (len(args) != 1 or not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', args[0])
                    or not 0 <= int(args[0], 16 if args[0].lower().startswith('0x') else 10) <= 8):
                raise ValueError('unsupported_profile_flash_level')
            size = 3 if op == 'setflashlevel' else 2
        elif version == 4 and op == 'givemon':
            if (len(args) not in (2, 3) or not re.fullmatch(r'SPECIES_\w+', args[0])
                    or not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', args[1])
                    or not 0 <= int(args[1], 16 if args[1].lower().startswith('0x') else 10) <= 255
                    or len(args) == 3 and not re.fullmatch(r'ITEM_\w+', args[2])):
                raise ValueError('unsupported_profile_givemon')
            size = 15
        elif version == 4 and op == 'subvar':
            glass_owner = owner[1].removeprefix('Route113_GlassWorkshop_EventScript_') if owner else ''
            glass_price = (owner and owner[1].startswith('Route113_GlassWorkshop_EventScript_')
                           and glass_owner in GLASS_WORKSHOP_PURCHASES
                           and args == ['VAR_ASH_GATHER_COUNT', GLASS_WORKSHOP_PURCHASES[glass_owner]])
            glass_difference = (owner and owner[1] in (
                'Route113_GlassWorkshop_EventScript_NotEnoughAsh',
                'Route113_GlassWorkshop_EventScript_NotEnoughAshForItem')
                and args == ['VAR_0x800A', 'VAR_ASH_GATHER_COUNT'])
            literal = (len(args) == 2 and re.fullmatch(r'VAR_\w+', args[0])
                       and re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', args[1])
                       and 0 <= int(args[1], 16 if args[1].lower().startswith('0x') else 10) <= 65535)
            if not (literal or glass_price or glass_difference):
                raise ValueError('unsupported_profile_subvar')
            size = 5
        elif version == 4 and op == 'showmonpic':
            if (len(args) != 3 or not re.fullmatch(r'SPECIES_\w+', args[0])
                    or any(not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', value)
                           or not 0 <= int(value, 16 if value.lower().startswith('0x') else 10) <= 255
                           for value in args[1:])):
                raise ValueError('unsupported_profile_showmonpic')
            size = 5
        elif version == 4 and op == 'hidemonpic':
            if args:
                raise ValueError('unsupported_profile_arguments:hidemonpic')
            size = 1
        elif version == 4 and op == 'showcontestpainting':
            if len(args) != 1 or args[0] not in CONTEST_PAINTING_SELECTORS:
                raise ValueError('unsupported_profile_contest_painting')
            size = 2
        elif version == 4 and op == 'bufferspeciesname':
            if (len(args) != 2 or not re.fullmatch(r'STR_VAR_[123]', args[0])
                    or not re.fullmatch(r'(?:SPECIES|VAR)_\w+', args[1])):
                raise ValueError('unsupported_profile_bufferspeciesname')
            size = 4
        elif version == 4 and op == 'bufferboxname':
            if (len(args) != 2 or not re.fullmatch(r'STR_VAR_[123]', args[0])
                    or not re.fullmatch(r'VAR_\w+', args[1])):
                raise ValueError('unsupported_profile_bufferboxname')
            size = 4
        elif version == 4 and op == 'trainerbattle_no_intro':
            if (len(args) != 2 or not re.fullmatch(r'TRAINER_\w+', args[0])
                    or not NAME.fullmatch(args[1]) or args[1] == 'NULL'):
                raise ValueError('unsupported_no_intro_trainer_battle')
            if position == len(lines) - 1:
                raise ValueError('missing_inline_trainer_battle_continuation')
            owner = re.search(r'(?m)^([A-Za-z_]\w*)::?', block)
            if owner is None:
                raise ValueError('missing_trainer_battle_owner')
            target('EventScript_DoNoIntroTrainerBattle', 'script')
            result.texts[args[1]] = 'string'
            result.trainer_battles.append(dict(owner=owner[1], trainer=args[0], defeat_text=args[1],
                address=f'0x{address + result.size:08X}', resume=f'0x{address + result.size + 10:08X}'))
            size = 10
        elif (version == 4 and op == 'trainerbattle' and args
              and args[0] in ('TRAINER_BATTLE_SET_TRAINER_A', 'TRAINER_BATTLE_SET_TRAINER_B')):
            if (len(args) != 5 or not re.fullmatch(r'TRAINER_\w+', args[1])
                    or args[2] != 'LOCALID_NONE'
                    or any(not NAME.fullmatch(value) or value == 'NULL' for value in args[3:])
                    or position != 0 or len(lines) != 2 or lines[-1] != 'end'):
                raise ValueError('unsupported_explicit_trainer_setup_form')
            # The real handler loads A/B parameters and returns NULL, not a
            # battle script or the next byte. Do not invent a battle frame.
            result.texts.update({value: 'string' for value in args[3:]})
            size = 14
        elif (version == 4 and op == 'trainerbattle' and args
              and args[0] in ('TRAINER_BATTLE_PYRAMID', 'TRAINER_BATTLE_HILL')):
            placeholder = 'BattleFacility_TrainerBattle_PlaceholderText'
            mode = args[0]
            if (args != [mode, 'TRAINER_PHILLIP', 'LOCALID_NONE', placeholder, placeholder]
                    or position == len(lines) - 1 or owner is None):
                raise ValueError('unsupported_facility_trainer_battle_form')
            if mode == 'TRAINER_BATTLE_HILL' and owner[1] != 'TrainerHill_EventScript_TrainerBattle':
                raise ValueError('unsupported_trainer_hill_battle_owner')
            target('EventScript_TryDoNormalTrainerBattle', 'script')
            target('EventScript_StartTrainerApproach', 'script')
            result.texts[placeholder] = 'string'
            size = 14
            result.trainer_battles.append(dict(owner=owner[1], mode=mode,
                trainer='TRAINER_PHILLIP', intro_text=placeholder, defeat_text=placeholder,
                address=f'0x{address + result.size:08X}', resume=f'0x{address + result.size + size:08X}'))
        elif version == 4 and op == 'trainerbattle':
            if (len(args) != 6 or args[0] != 'TRAINER_BATTLE_CONTINUE_SCRIPT'
                    or not re.fullmatch(r'TRAINER_\w+', args[1])
                    or not re.fullmatch(r'LOCALID_\w+', args[2]) or args[2] == 'LOCALID_NONE'
                    or any(not NAME.fullmatch(value) or value == 'NULL' for value in args[3:])):
                raise ValueError('unsupported_explicit_trainer_battle_form')
            if position == len(lines) - 1:
                raise ValueError('missing_inline_trainer_battle_continuation')
            owner = re.search(r'(?m)^([A-Za-z_]\w*)::?', block)
            if owner is None:
                raise ValueError('missing_trainer_battle_owner')
            mode, entry, _ = TRAINER_FORMS[(op, len(args))]
            target(entry, 'script')
            target('EventScript_StartTrainerApproach', 'script')
            target(args[5], 'script')
            result.texts.update({value: 'string' for value in args[3:5]})
            size = 18
            result.trainer_battles.append(dict(owner=owner[1], mode=mode, trainer=args[1],
                local_id=args[2], intro_text=args[3], defeat_text=args[4], post_script=args[5],
                address=f'0x{address + result.size:08X}', resume=f'0x{address + result.size + size:08X}'))
        elif version == 4 and op.startswith('trainerbattle_'):
            form = TRAINER_FORMS.get((op, len(args)))
            if ((op == 'trainerbattle_single' and len(args) == 5)
                    or (op == 'trainerbattle_double' and len(args) == 6)):
                if args[-1] != 'NO_MUSIC':
                    raise ValueError('unsupported_trainer_battle_music_flag')
                args = args[:-1]
            if (form is None or not re.fullmatch(r'TRAINER_\w+', args[0])
                    or any(not NAME.fullmatch(arg) or arg == 'NULL' for arg in args[1:])):
                raise ValueError('unsupported_trainer_battle_form')
            if position == len(lines) - 1:
                raise ValueError('missing_inline_trainer_battle_continuation')
            owner = re.search(r'(?m)^([A-Za-z_]\w*)::?', block)
            if owner is None:
                raise ValueError('missing_trainer_battle_owner')
            mode, entry, _ = form
            target(entry, 'script')
            target('EventScript_StartTrainerApproach', 'script')
            text_fields = ['intro_text', 'defeat_text']
            if op in ('trainerbattle_double', 'trainerbattle_rematch_double'):
                text_fields.append('cannot_battle_text')
            battle = dict(owner=owner[1], trainer=args[0], mode=mode)
            for key, value in zip(text_fields, args[1:]):
                battle[key] = value
                result.texts[value] = 'string'
            if len(args) > len(text_fields) + 1:
                battle['post_script'] = args[-1]
                target(args[-1], 'script')
            size = 6 + 4 * (len(args) - 1)
            battle.update(address=f'0x{address + result.size:08X}',
                          resume=f'0x{address + result.size + size:08X}')
            result.trainer_battles.append(battle)
        elif version == 4 and op in ('dotrainerbattle', 'gotopostbattlescript', 'gotobeatenscript'):
            if args:
                raise ValueError('unsupported_trainer_battle_primitive')
            result.trainer_run |= op == 'dotrainerbattle'
            result.trainer_post_return |= op == 'gotopostbattlescript'
            result.trainer_beaten_return |= op == 'gotobeatenscript'
            if op == 'gotobeatenscript':
                target('EventScript_TryGetTrainerScript', 'script')
            size = 1
        elif version == 4 and op == 'callstd':
            if args != ['STD_FIND_ITEM']:
                raise ValueError('unsupported_profile_standard_script_call')
            result.standard_scripts[1] = 'Std_FindItem'
            target('Std_FindItem', 'script')
            size = 2
        elif version == 4 and op == 'register_matchcall':
            if len(args) != 1 or not re.fullmatch(r'TRAINER_\w+', args[0]):
                raise ValueError('unsupported_match_call_registration')
            waits = special_waits(root) if waits is None else waits
            function = 'SetMatchCallRegisteredFlag'
            if waits.get(function) not in (0, 1):
                raise ValueError('missing_match_call_registration_special')
            result.specials[function] = waits[function]
            result.standard_scripts[8] = 'Std_RegisteredInMatchCall'
            target('Std_RegisteredInMatchCall', 'script')
            size = 15 + waits[function]
        elif version == 4 and op == 'pokenavcall':
            if len(args) != 1 or not NAME.fullmatch(args[0]) or args[0] == 'NULL':
                if not (owner and owner[1] == 'Std_MsgboxPokenav' and args == ['NULL']):
                    raise ValueError('unsupported_pokenav_call')
                # Like message NULL, this standard script reads ctx->data[0].
                # NULL is an indirect operand, never a literal text owner.
            else:
                result.texts[args[0]] = 'string'
            size = 5
        elif version == 4 and op == 'setberrytree':
            if (not owner or owner[1] != 'EventScript_ResetAllBerries' or len(args) != 3
                    or not re.fullmatch(r'BERRY_TREE_ROUTE_\w+', args[0])
                    or not re.fullmatch(r'ITEM_TO_BERRY\(ITEM_[A-Z0-9_]+_BERRY\)', args[1])
                    or args[2] != 'BERRY_STAGE_BERRIES'):
                raise ValueError('unsupported_profile_initial_berry_tree')
            tree = _literal_define(root, 'include/constants/berry.h', args[0])
            berry = _literal_define(root, 'include/constants/items.h', args[1][14:-1])
            first = _literal_define(root, 'include/constants/items.h', 'ITEM_CHERI_BERRY')
            last = _literal_define(root, 'include/constants/items.h', 'ITEM_ENIGMA_BERRY')
            if not 0 <= tree <= 255 or not first <= berry <= last:
                raise ValueError('unsupported_profile_initial_berry_tree')
            size = 4
        elif version == 4 and op in ('checkitem', 'checkpcitem'):
            if len(args) not in (1, 2) or not re.fullmatch(r'(?:ITEM|VAR)_\w+', args[0]):
                raise ValueError('unsupported_profile_' + op)
            if (op == 'checkpcitem' and len(args) == 2
                    and not re.fullmatch(r'(?:VAR_\w+|0[xX][0-9A-Fa-f]+|[0-9]+)', args[1])):
                raise ValueError('unsupported_profile_checkpcitem_quantity')
            size = 5
        elif version == 4 and op == 'checkitemspace':
            if (len(args) not in (1, 2) or len(args) == 1
                    and not re.fullmatch(r'(?:ITEM|VAR)_\w+', args[0])):
                raise ValueError('unsupported_profile_checkitemspace')
            # Preserve the existing two-operand ITEMID/AMOUNT macro form.
            size = 5
        elif version == 4 and op in ('checkmoney', 'removemoney'):
            price = (GAME_CORNER_PRICES[args[0]] if args and args[0] in ('COINS_PRICE_50', 'COINS_PRICE_500')
                     else int(args[0], 16 if args[0].startswith('0x') else 10)
                     if args and re.fullmatch(r'(?:0x[0-9A-Fa-f]+|[0-9]+)', args[0]) else None)
            if (len(args) not in (1, 2) or price is None or price > 0xFFFFFFFF
                    or len(args) == 2 and args[1] not in ('0', '1')):
                raise ValueError('unsupported_profile_money_command')
            size = 6
        elif version == 4 and op in ('showcoinsbox', 'hidecoinsbox', 'updatecoinsbox'):
            if len(args) != 2 or any(not a.isdecimal() or int(a) > 255 for a in args):
                raise ValueError('unsupported_profile_coin_window')
            size = 3
        elif version == 4 and op == 'getpokenewsactive':
            if len(args) != 1 or not re.fullmatch(r'POKENEWS_\w+', args[0]):
                raise ValueError('unsupported_profile_pokenews_kind')
            size = 3
        elif version == 4 and op == 'checkcoins':
            if len(args) != 1 or not re.fullmatch(r'VAR_\w+', args[0]):
                raise ValueError('unsupported_profile_coin_output')
            size = 3
        elif version == 4 and op in ('addcoins', 'removecoins', 'playslotmachine'):
            if (len(args) != 1 or not (re.fullmatch(r'VAR_\w+', args[0])
                    or args[0] in GAME_CORNER_PRICES
                    or re.fullmatch(r'(?:0x[0-9A-Fa-f]+|[0-9]+)', args[0])
                    and int(args[0], 16 if args[0].startswith('0x') else 10) <= 65535)):
                raise ValueError('unsupported_profile_coin_or_slot_operand')
            size = 3
        elif version == 4 and op in ('adddecoration', 'checkdecorspace', 'givedecoration', 'bufferdecorationname'):
            count = 2 if op == 'bufferdecorationname' else 1
            if (len(args) != count or not re.fullmatch(r'(?:(?:DECOR|VAR)_\w+|ITEMID)', args[-1])
                    or count == 2 and not re.fullmatch(r'STR_VAR_[123]', args[0])):
                raise ValueError('unsupported_profile_decoration_operand')
            size = 4 if count == 2 else 3
            if op == 'givedecoration':
                target('Std_ObtainDecoration', 'script')
                result.standard_scripts[7] = 'Std_ObtainDecoration'
                size = 7
        elif version == 4 and op == 'showmoneybox':
            if (len(args) not in (2, 3) or any(not a.isdecimal() or int(a) > 255 for a in args[:2])
                    or len(args) == 3 and args[2] not in ('0', '1')):
                raise ValueError('unsupported_profile_money_window')
            size = 4
        elif version == 4 and op in ('hidemoneybox', 'updatemoneybox'):
            if args and not (op == 'updatemoneybox' and args in (['0'], ['1'])):
                raise ValueError('unsupported_profile_money_window')
            size = 3 if op == 'hidemoneybox' else 4
        elif version == 4 and op == 'setstepcallback':
            if len(args) != 1 or not re.fullmatch(r'STEP_CB_\w+', args[0]):
                raise ValueError('unsupported_profile_step_callback')
            size = 2
        elif version == 4 and op in ('setdivewarp', 'setescapewarp', 'warpsilent', 'warpwhitefade', 'warpdoor'):
            if len(args) != 3 or not re.fullmatch(r'MAP_\w+', args[0]):
                raise ValueError('unsupported_profile_coordinate_warp')
            if (op == 'warpdoor' and any(not re.fullmatch(r'(?:VAR_\w+|0[xX][0-9A-Fa-f]+|[0-9]+)', a)
                                         for a in args[1:])):
                raise ValueError('unsupported_profile_warpdoor_coordinates')
            size = 8
        elif version == 4 and op == 'setmaplayoutindex':
            if len(args) != 1 or not re.fullmatch(r'LAYOUT_\w+', args[0]):
                raise ValueError('unsupported_profile_dynamic_layout')
            result.layouts.add(args[0])
            size = 3
        elif version == 4 and op in ('pokemart', 'pokemartdecoration', 'pokemartdecoration2'):
            if len(args) != 1:
                raise ValueError('unsupported_profile_shop')
            target(args[0], 'mart_items' if op == 'pokemart' else 'mart_decorations')
            size = 5
        elif version == 4 and op == '.align':
            if (args != ['2'] or table_ops or position != len(lines) - 1
                    or len(lines) < 2 or lines[-2] not in ('end', 'return')):
                raise ValueError('unsupported_profile_alignment')
            size = -(address + result.size) % 4
        elif op in ('applymovement', 'applywaitmovement'):
            if len(args) not in (2, 3) or (len(args) == 3 and not re.fullmatch(r'MAP_\w+', args[2])):
                raise ValueError('unsupported_profile_movement')
            size = (7 if len(args) == 2 else 9) + (3 if op == 'applywaitmovement' else 0)
            target(args[1], 'movement')
        elif op in ('waitmovement', 'addobject', 'removeobject'):
            allowed = (0, 1, 2) if op == 'waitmovement' else (1, 2)
            if len(args) not in allowed or (len(args) == 2 and not re.fullmatch(r'MAP_\w+', args[1])):
                raise ValueError('unsupported_profile_object')
            size = 5 if len(args) == 2 else 3
        elif op in ('special', 'specialvar', 'pyramid_getlocation'):
            if len(args) != {'special': 1, 'specialvar': 2, 'pyramid_getlocation': 0}[op]:
                raise ValueError('unsupported_profile_special')
            function = 'CallBattlePyramidFunction' if op == 'pyramid_getlocation' else args[-1]
            if not NAME.fullmatch(function):
                raise ValueError('unsupported_profile_special')
            waits = special_waits(root) if waits is None else waits
            if function not in waits:
                raise ValueError('unknown_profile_special:' + function)
            if waits[function] not in (0, 1):
                raise ValueError('invalid_profile_special_wait:' + function)
            result.specials[function] = waits[function]
            size = {'special': 3, 'specialvar': 5, 'pyramid_getlocation': 8}[op] + waits[function]
        elif op == 'finditem' or version == 4 and op == 'giveitem':
            if (len(args) not in (1, 2) or not re.fullmatch(
                    r'ITEM_\w+' if op == 'finditem' else r'(?:ITEM|VAR)_\w+', args[0])):
                raise ValueError('unsupported_profile_finditem')
            index, entry = (1, 'Std_FindItem') if op == 'finditem' else (0, 'Std_ObtainItem')
            target(entry, 'script')
            result.standard_scripts[index] = entry
            size = 12
        elif op == 'additem' or version == 4 and op == 'removeitem':
            if len(args) not in (1, 2):
                raise ValueError('unsupported_profile_additem')
            size = 5
        elif version == 4 and op == 'bufferstring':
            if (len(args) != 2 or not re.fullmatch(r'STR_VAR_[123]', args[0])
                    or not NAME.fullmatch(args[1]) or args[1] == 'NULL'):
                raise ValueError('unsupported_profile_bufferstring')
            result.texts[args[1]] = 'string'
            size = 6
        elif version == 4 and op in ('braillemessage', 'braillemsgbox'):
            if (len(args) != 1 or not NAME.fullmatch(args[0])
                    or args[0] in ('NULL', 'gStringVar4')):
                raise ValueError('unsupported_profile_braille_message')
            result.texts[args[0]] = 'braille'
            size = 5 if op == 'braillemessage' else 7
        elif op == 'msgbox':
            if len(args) != 2 or args[1] not in standard or not NAME.fullmatch(args[0]):
                raise ValueError('unsupported_profile_message')
            index, entry = standard[args[1]]
            target(entry, 'script')
            if args[0] == 'gStringVar4':
                produced = position > 0 and lines[position - 1] == 'battletent_getopponentintro'
                produced |= (position > 1 and lines[position - 2:position]
                             == ['battletent_getopponentintro', 'lockall'])
                ereader = position > 0 and lines[position - 1] == 'special CopyEReaderTrainerGreeting'
                tower = position > 0 and lines[position - 1] == 'tower_getopponentintro 0'
                tower |= _multi_intro_message(owner[1] if owner else None, lines, position, op)
                palace = (owner is not None and owner[1] in (
                              'BattleFrontier_BattlePalaceBattleRoom_EventScript_NextOpponentEnter',
                              'BattleFrontier_BattleArenaBattleRoom_EventScript_AnnounceTrainers')
                          and position > 0 and lines[position - 1] == 'palace_getopponentintro'
                          and args[1] == 'MSGBOX_DEFAULT')
                palace |= (owner is not None and owner[1] == 'BattleFrontier_BattleFactoryBattleRoom_EventScript_BattleOpponent'
                           and position > 1 and lines[position - 2:position] == ['palace_getopponentintro', 'lockall']
                           and args[1] == 'MSGBOX_DEFAULT')
                pike = None
                if owner is not None and position > 0 and args[1] == 'MSGBOX_DEFAULT':
                    prefix = 'BattleFrontier_BattlePikeRoomNormal_EventScript_'
                    if (owner[1] == prefix + 'NormalNPC' and lines[position - 1] == 'pike_getnpcmsg'):
                        pike = 'pike_getnpcmsg'
                    elif (owner[1] in (prefix + 'EnterSingleBattleRoom', prefix + 'EnterHardBattleRoom')
                          and lines[position - 1] == 'pike_gettrainerintro 0'
                          or owner[1] == prefix + 'EnterDoubleBattleRoom'
                          and lines[position - 1] in ('pike_gettrainerintro 0', 'pike_gettrainerintro 1')):
                        pike = 'pike_gettrainerintro'
                if version != 4 or not (produced or ereader or tower or palace or pike):
                    raise ValueError('unproven_runtime_message_producer')
                result.runtime_texts['gStringVar4'] = ('CopyEReaderTrainerGreeting' if ereader
                                                     else 'tower_getopponentintro' if tower
                                                     else 'palace_getopponentintro' if palace
                                                     else pike if pike
                                                     else 'battletent_getopponentintro')
            else:
                result.texts[args[0]] = 'string'
            result.standard_scripts[index] = entry
            size = 8
        elif version == 4 and op == 'messageautoscroll':
            if len(args) != 1 or not NAME.fullmatch(args[0]) or args[0] == 'NULL':
                raise ValueError('unsupported_profile_autoscroll_message')
            if args[0] == 'gStringVar4':
                if not _multi_intro_message(owner[1] if owner else None, lines, position, op):
                    raise ValueError('unproven_runtime_autoscroll_producer')
                result.runtime_texts['gStringVar4'] = 'tower_getopponentintro'
            else:
                result.texts[args[0]] = 'string'
            size = 5
        elif version == 4 and op == 'messageinstant':
            if len(args) != 1 or not NAME.fullmatch(args[0]) or args[0] in ('NULL', 'gStringVar4'):
                raise ValueError('unsupported_profile_instant_message')
            result.texts[args[0]] = 'string'
            size = 5
        elif op == 'message':
            if len(args) != 1 or not NAME.fullmatch(args[0]):
                raise ValueError('unsupported_profile_buffered_message')
            if args != ['NULL']:
                result.texts[args[0]] = 'string'
            size = 5
        elif op in ('map_script', 'map_script_2'):
            if len(args) != (2 if op == 'map_script' else 3):
                raise ValueError('unsupported_profile_map_table')
            if op == 'map_script' and args[0] not in MAP_TYPES:
                raise ValueError('unsupported_profile_map_table_type')
            target(args[-1], MAP_TYPES[args[0]] if op == 'map_script' else 'script')
            size = 5 if op == 'map_script' else 8
        elif op in ('.byte', '.2byte') and args == ['0'] and result.kind in ('map_table', 'condition_table'):
            size = 1 if op == '.byte' else 2
        else:
            raise ValueError('unsupported_story_review_statement:' + op)
        result.size += size
    owner = re.search(r'(?m)^([A-Za-z_]\w*)::?', block)
    tail = operations[-2] if operations[-1] == '.align' else operations[-1]
    result.may_fall_through = result.kind == 'script' and tail not in (
        'end', 'return', 'goto', 'gotopostbattlescript', 'gotobeatenscript')
    if version == 4 and owner and owner[1] in FALLTHROUGHS:
        result.fallthrough = FALLTHROUGHS[owner[1]]
        target(result.fallthrough, 'script')
    if version == 4 and owner and owner[1] == 'TrainerHill_1F_EventScript_DummyOnWarp':
        if lines not in (['setvar VAR_TEMP_3, 1'], ['setvar VAR_TEMP_3, 1', 'end']):
            raise ValueError('changed_trainer_hill_implicit_end_prefix')
        if tail != 'end':
            # Default JP bytes omit END. The first byte of the adjacent
            # condition table (VAR_TEMP_2's low byte, 0x02) acts as END.
            # Keep the target typed as a table; native checks bind that byte.
            result.fallthrough = 'TrainerHill_OnFrame'
            target(result.fallthrough, 'condition_table')
    if version == 4 and owner and owner[1] in CONTEXT_WARP_EXITS:
        destination, x, y = CONTEXT_WARP_EXITS[owner[1]]
        if lines[-2:] != [f'warp {destination}, {x}, {y}', 'waitstate']:
            raise ValueError('changed_context_replacing_warp')
        result.context_warp = destination
        result.may_fall_through = False
    if version == 4 and owner and owner[1] in CONTEXT_CALLBACK_EXITS:
        special = CONTEXT_CALLBACK_EXITS[owner[1]]
        if (lines[-2:] != ['fadescreen FADE_TO_BLACK', 'special ' + special]
                or result.specials.get(special) != 1):
            raise ValueError('changed_context_replacing_callback')
        result.context_callback = special
        result.may_fall_through = False
    if version == 4 and owner and owner[1] in UNREACHABLE_WAIT_TAILS:
        destination = UNREACHABLE_WAIT_TAILS[owner[1]]
        if lines[-2:] != ['goto ' + destination, 'waitstate']:
            raise ValueError('changed_unreachable_wait_tail')
        result.may_fall_through = False
    return result


OWNER_PREFIXES_V4 = {
    'BattleFrontier_BattleDomeBattleRoom_MapScripts': [
        '.set NO_DRAW, 0', '.set DRAW_TRAINER, 1', '.set DRAW_TUCKER, 2'],
    'Std_ObtainItem': ['.set ITEMID, VAR_0x8000', '.set AMOUNT, VAR_0x8001'],
}


def profile_owner(root: Path, text: str, waits=None, *, version=3, address=None) -> dict[str, BlockProfile]:
    waits = special_waits(root) if waits is None else waits
    blocks = label_blocks(text)
    if not blocks:
        raise ValueError('missing_profile_labels')
    first = re.search(r'(?m)^' + re.escape(next(iter(blocks))) + r'::?', text)
    prefix = [re.sub(r'\s+', ' ', line) for line in statements(text[:first.start()])]
    if prefix and not (version == 4 and prefix == OWNER_PREFIXES_V4.get(next(iter(blocks)))):
        raise ValueError('unmodeled_owner_prefix')
    result = {}
    for name, block in blocks.items():
        result[name] = profile_block(root, block, waits, version=version, address=address)
        if address is not None:
            address += result[name].size
    expected_kinds = {}
    for profile in result.values():
        for name, expected in list(profile.targets.items()) + list(profile.texts.items()):
            if name in expected_kinds and expected_kinds[name] != expected:
                raise ValueError('incompatible_reference_kinds:' + name)
            expected_kinds[name] = expected
            if name in result and result[name].kind != expected:
                raise ValueError('incompatible_internal_target:' + name)
    return result
