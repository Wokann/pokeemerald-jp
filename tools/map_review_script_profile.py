"""Fail-closed typed script/movement analysis for reviewed story-map forms.

This does not approve a map. It measures explicitly supported source forms
and distinguishes scripts, map tables, movements and encoded JP text. Review
records, real macro expansion tests and native byte checks remain mandatory.
"""
from dataclasses import dataclass, field
from pathlib import Path
import re
try:
    from map_semantic_review import encoded_text, label_blocks, statements, text_kind
except ModuleNotFoundError:
    from tools.map_semantic_review import encoded_text, label_blocks, statements, text_kind

NAME = re.compile(r'[A-Za-z_]\w*\Z')
ATOM = re.compile(r'(?:[A-Za-z_]\w*|0x[0-9A-Fa-f]+|-?\d+)\Z')
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
                          'MSGBOX_AUTOCLOSE': (6, 'Std_MsgboxAutoclose')}
MOVEMENTS_V4 = MOVEMENTS | {'lock_facing_direction', 'unlock_facing_direction',
                           'face_up', 'face_down', 'face_left', 'face_right', 'delay_4', 'reveal_trainer',
                           'walk_in_place_down', 'walk_faster_right', 'walk_fast_right', 'walk_fast_up',
                           'set_visible', 'walk_faster_up', 'walk_in_place_slow_left',
                           'walk_in_place_slow_right', 'walk_slow_left', 'walk_slow_diag_northeast',
                           'walk_slow_diag_southwest', 'walk_left_affine', 'init_affine_anim',
                           'clear_affine_anim', 'levitate', 'destroy_extra_task',
                           'walk_fast_left', 'jump_right', 'jump_in_place_right',
                           'disable_jump_landing_ground_effect', 'walk_faster_left', 'walk_fast_down',
                           'walk_in_place_fast_left', 'walk_in_place_fast_right', 'jump_2_down', 'cut_tree',
                           'walk_faster_down', 'lock_anim', 'walk_in_place_left', 'walk_in_place_up',
                           'rock_smash_break', 'walk_in_place_right', 'walk_slow_up', 'nurse_joy_bow',
                           'jump_in_place_down', 'jump_up', 'walk_slow_right'}
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
                   'fadescreenspeed': (3, 2), 'turnobject': (4, 2), 'hideplayer': (5, 0),
                   'multichoice': (5, 4), 'multichoicedefault': (6, 5),
                   'setobjectsubpriority': (6, 3), 'resetobjectsubpriority': (5, 2),
                   'showobjectat': (5, 2), 'incrementgamestat': (2, 1),
                   'getpartysize': (1, 0), 'giveegg': (3, 1), 'fadescreen': (2, 1),
                   'selectapproachingtrainer': (1, 0), 'lockfortrainer': (1, 0),
                   'buffertrainerclassname': (4, 2), 'buffertrainername': (4, 2),
                   'buffernumberstring': (4, 2), 'checkpartymove': (3, 1),
                   'bufferpartymonnick': (4, 2), 'buffermovename': (4, 2),
                   'fadescreenswapbuffers': (2, 1), 'setorcopyvar': (5, 2), 'dowildbattle': (1, 0),
                   'nop1': (1, 0)}

# These source blocks deliberately continue into the next physical label.
# A native adjacency check is mandatory; a named target alone is not proof.
FALLTHROUGHS = {
    'Route117_EventScript_TryMoveDayCareMan': 'Route117_EventScript_StopMoveDayCareMan',
    'Route111_EventScript_CheckSetSandstorm': 'Route111_EventScript_SetSandstorm',
    'Route111_EventScript_SetSandstorm': 'Route111_EventScript_EndCheckSetSandstorm',
    'ProfBirch_EventScript_RatePokedexOrRegister': 'ProfBirch_EventScript_AskRatePokedex',
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
}

# These one-byte movement prefixes deliberately share the next movement's
# terminator. Never insert a step_end or accept arbitrary unterminated paths.
MOVEMENT_PREFIXES = {
    'FallarborTown_BattleTentCorridor_Movement_PlayerEnterDoor':
        'FallarborTown_BattleTentCorridor_Movement_AttendantEnterDoor',
    'VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor':
        'VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor',
}

# This audited warp replaces the old script context before the following
# movement bytes. It is not a bytecode edge into that movement definition.
CONTEXT_WARP_EXITS = {
    'SlateportCity_BattleTentBattleRoom_EventScript_WarpToLobbyWon':
        ('MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY', 6, 6),
    'SlateportCity_BattleTent_EventScript_WarpToLobbyLost':
        ('MAP_SLATEPORT_CITY_BATTLE_TENT_LOBBY', 6, 6),
    'SlateportCity_BattleTentBattleRoom_EventScript_DefeatedOpponent':
        ('MAP_SLATEPORT_CITY_BATTLE_TENT_CORRIDOR', 2, 3),
}

# Selector macros measured against the current JP assembler. Handler identity
# and waitstate are taken from the real Special table, not a US table index.
FACILITY_FORMS = {
    'frontier_getstatus': ('CallFrontierUtilFunc', 8, ()),
    'frontier_get': ('CallFrontierUtilFunc', 13, (r'FRONTIER_DATA_\w+',)),
    'frontier_checkineligible': ('CallFrontierUtilFunc', 8, ()),
    'frontier_setpartyorder': ('CallFrontierUtilFunc', 13, (r'(?:[1-6]|FRONTIER_PARTY_SIZE)',)),
    'frontier_reset': ('CallFrontierUtilFunc', 8, ()),
    'frontier_restorehelditems': ('CallFrontierUtilFunc', 8, ()),
    'frontier_resetsketch': ('CallFrontierUtilFunc', 8, ()),
    'tower_setopponent': ('CallBattleTowerFunc', 8, ()),
    'arena_get': ('CallBattleArenaFunction', 13, (r'ARENA_DATA_\w+',)),
    'arena_set': ('CallBattleArenaFunction', 18, (r'ARENA_DATA_\w+', r'(?:VAR_\w+|\d+)')),
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

# Only explicitly measured forms are supported. A five-argument single is
# accepted only with NO_MUSIC; its flag is not a pointer or an emitted field.
TRAINER_FORMS = {
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
    if any(';' in line for line in lines):
        raise ValueError('unmodeled_statement_separator')
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
            if lines != ['walk_up']:
                raise ValueError('unsupported_movement_prefix')
            return BlockProfile(size=len(lines), kind='movement', targets={prefix: 'movement'},
                                fallthrough=prefix, may_fall_through=True)
        if (any(op not in movements for op in operations) or operations[-1] != 'step_end'
                or ends not in ((1, 2) if version == 4 else (1,))
                or operations[-ends:] != ['step_end'] * ends):
            raise ValueError('mixed_or_unterminated_movement')
        if any(len(line.split()) != 1 for line in lines):
            raise ValueError('unsupported_movement_arguments')
        return BlockProfile(size=len(lines), kind='movement')
    result = BlockProfile()
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
        if any(not ATOM.fullmatch(arg) for arg in args):
            raise ValueError('unsupported_profile_argument_expression:' + op)
        if op in fixed:
            size, count = fixed[op]
            if len(args) != count:
                raise ValueError('unsupported_profile_arguments:' + op)
            if op == 'warp' and not re.fullmatch(r'MAP_\w+', args[0]):
                raise ValueError('unsupported_profile_warp')
        elif (op in ('call', 'goto', 'call_if_eq', 'goto_if_eq', 'case')
              or version == 4 and op in ('goto_if_ge', 'goto_if_le', 'goto_if_ne', 'goto_if_lt',
                                         'goto_if_gt', 'call_if_ne', 'call_if_ge', 'call_if_lt')):
            count = 2 if op == 'case' else 3 if '_if_' in op else 1
            if len(args) != count:
                raise ValueError('unsupported_profile_arguments:' + op)
            if count == 3 and not re.fullmatch(r'VAR_\w+', args[0]):
                raise ValueError('unsupported_profile_compare')
            if op in ('call_if_ge', 'call_if_lt') and args[-1] == 'NULL':
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
        elif version == 4 and op == 'setwildbattle':
            if (len(args) not in (2, 3) or not re.fullmatch(r'SPECIES_\w+', args[0])
                    or not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', args[1])
                    or not 0 <= int(args[1], 16 if args[1].lower().startswith('0x') else 10) <= 255
                    or len(args) == 3 and not re.fullmatch(r'ITEM_\w+', args[2])):
                raise ValueError('unsupported_profile_setwildbattle')
            size = 6
        elif version == 4 and op in ('setwarp', 'warpspinenter'):
            if (len(args) != 3 or not re.fullmatch(r'MAP_\w+', args[0])
                    or any(not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', value)
                           or not 0 <= int(value, 16 if value.lower().startswith('0x') else 10) <= 65535
                           for value in args[1:])):
                raise ValueError('unsupported_profile_setwarp')
            size = 8
        elif version == 4 and op == 'trywondercardscript':
            if args:
                raise ValueError('unsupported_profile_arguments:trywondercardscript')
            result.runtime_scripts.add('saved_wonder_card')
            size = 1
        elif version == 4 and (op in FACILITY_FORMS or op == 'frontier_set'):
            if op == 'frontier_set':
                if (len(args) not in (1, 2) or not re.fullmatch(r'FRONTIER_DATA_\w+', args[0])
                        or len(args) == 2 and not re.fullmatch(r'(?:[A-Z][A-Z0-9_]*|0x[0-9A-Fa-f]+|\d+)', args[1])):
                    raise ValueError('unsupported_profile_facility_macro:' + op)
                omitted = len(args) == 1 or args[1].lower() in ('0xffff', '65535')
                function, size = 'CallFrontierUtilFunc', 13 if omitted else 18
            else:
                function, size, patterns = FACILITY_FORMS[op]
                if len(args) != len(patterns) or any(not re.fullmatch(p, a) for p, a in zip(patterns, args)):
                    raise ValueError('unsupported_profile_facility_macro:' + op)
            waits = special_waits(root) if waits is None else waits
            if waits.get(function) not in (0, 1):
                raise ValueError('missing_facility_macro_special:' + function)
            result.specials[function] = waits[function]
            size += waits[function]
        elif version == 4 and op == 'erasebox':
            if (len(args) != 4 or any(not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', value)
                                     or not 0 <= int(value, 16 if value.lower().startswith('0x') else 10) <= 255
                                     for value in args)):
                raise ValueError('unsupported_profile_erasebox')
            size = 5
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
            if (len(args) != 2 or not re.fullmatch(r'VAR_\w+', args[0])
                    or not re.fullmatch(r'(?:0[xX][0-9A-Fa-f]+|[0-9]+)', args[1])
                    or not 0 <= int(args[1], 16 if args[1].lower().startswith('0x') else 10) <= 65535):
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
            if op == 'trainerbattle_single' and len(args) == 5:
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
                raise ValueError('unsupported_pokenav_call')
            result.texts[args[0]] = 'string'
            size = 5
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
            if (len(args) not in (1, 2) or not re.fullmatch(r'(?:0x[0-9A-Fa-f]+|[0-9]+)', args[0])
                    or int(args[0], 16 if args[0].startswith('0x') else 10) > 0xFFFFFFFF
                    or len(args) == 2 and args[1] not in ('0', '1')):
                raise ValueError('unsupported_profile_money_command')
            size = 6
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
        elif version == 4 and op in ('pokemart', 'pokemartdecoration'):
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
        elif op == 'msgbox':
            if len(args) != 2 or args[1] not in standard or not NAME.fullmatch(args[0]):
                raise ValueError('unsupported_profile_message')
            index, entry = standard[args[1]]
            target(entry, 'script')
            if args[0] == 'gStringVar4':
                produced = position > 0 and lines[position - 1] == 'battletent_getopponentintro'
                produced |= (position > 1 and lines[position - 2:position]
                             == ['battletent_getopponentintro', 'lockall'])
                if version != 4 or not produced:
                    raise ValueError('unproven_runtime_message_producer')
                result.runtime_texts['gStringVar4'] = 'battletent_getopponentintro'
            else:
                result.texts[args[0]] = 'string'
            result.standard_scripts[index] = entry
            size = 8
        elif version == 4 and op == 'messageautoscroll':
            if len(args) != 1 or not NAME.fullmatch(args[0]) or args[0] == 'NULL':
                raise ValueError('unsupported_profile_autoscroll_message')
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
    if version == 4 and owner and owner[1] in CONTEXT_WARP_EXITS:
        destination, x, y = CONTEXT_WARP_EXITS[owner[1]]
        if lines[-2:] != [f'warp {destination}, {x}, {y}', 'waitstate']:
            raise ValueError('changed_context_replacing_warp')
        result.context_warp = destination
        result.may_fall_through = False
    return result


def profile_owner(root: Path, text: str, waits=None, *, version=3, address=None) -> dict[str, BlockProfile]:
    waits = special_waits(root) if waits is None else waits
    blocks = label_blocks(text)
    if not blocks:
        raise ValueError('missing_profile_labels')
    first = re.search(r'(?m)^' + re.escape(next(iter(blocks))) + r'::?', text)
    if statements(text[:first.start()]):
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
