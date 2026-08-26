@ LittlerootTown_ProfessorBirchsLab scripts (JP map g1 m4 @ 0x081F122C)

LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	.byte 0

LittlerootTown_ProfessorBirchsLab_OnTransition:: @ 0x081F123C
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x6, LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x3, LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter:: @ 0x081F1268
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 0x5, 0xA
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter:: @ 0x081F1284
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout

LittlerootTown_ProfessorBirchsLab_EventScript_SetJohtoStarterLayout:: @ 0x081F128E
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout:: @ 0x081F1292
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype LOCALID_BIRCHS_LAB_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LOCALID_BIRCHS_LAB_RIVAL, 0x5, 0xA
	end

LittlerootTown_ProfessorBirchsLab_OnWarp:: @ 0x081F12A1
	map_script_2 VAR_BIRCH_LAB_STATE, 0x2, LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x2, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x3, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x6, LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x5, LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_SetPlayerPosForReceiveStarter:: @ 0x081F12DB
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForDexUpgrade:: @ 0x081F12E0
	turnobject LOCALID_PLAYER, DIR_NORTH
	addobject LOCALID_BIRCHS_LAB_BIRCH
	addobject LOCALID_BIRCHS_LAB_RIVAL
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_NORTH
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 0x5, 0x5
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 0x6, 0x4
	turnobject LOCALID_BIRCHS_LAB_AIDE, DIR_EAST
	setobjectxy LOCALID_BIRCHS_LAB_AIDE, 0xA, 0xA
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AddRivalObject:: @ 0x081F130C
	addobject LOCALID_BIRCHS_LAB_RIVAL
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SetObjectPosForJohtoStarters:: @ 0x081F1310
	addobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	addobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	addobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	addobject LOCALID_BIRCHS_LAB_RIVAL
	turnobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL, 0x8, 0x4
	turnobject LOCALID_BIRCHS_LAB_TOTODILE_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_TOTODILE_BALL, 0x9, 0x4
	turnobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_CHIKORITA_BALL, 0xA, 0x4
	turnobject LOCALID_BIRCHS_LAB_BIRCH, DIR_SOUTH
	setobjectxy LOCALID_BIRCHS_LAB_BIRCH, 0x6, 0x4
	turnobject LOCALID_BIRCHS_LAB_RIVAL, DIR_EAST
	setobjectxy LOCALID_BIRCHS_LAB_RIVAL, 0x5, 0x5
	end

LittlerootTown_ProfessorBirchsLab_OnFrame:: @ 0x081F1354
	map_script_2 VAR_BIRCH_LAB_STATE, 0x2, LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent
	map_script_2 VAR_BIRCH_LAB_STATE, 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x1, LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex
	map_script_2 VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x4, LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_GiveStarterEvent:: @ 0x081F1376
	lockall
	bufferleadmonspeciesname STR_VAR_1
	message LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter:: @ 0x081F13A2
	setvar VAR_0x8004, 0x0
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GoSeeRival:: @ 0x081F13B2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival:: @ 0x081F13D1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou, MSGBOX_DEFAULT
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_BIRCH_LAB_STATE, 0x3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival:: @ 0x081F13E3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_AgreeToSeeRival
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DeclineSeeingRival
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedexEvent:: @ 0x081F1402
	lockall
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_UpgradeToNationalDex:: @ 0x081F141B
	lockall
	delay 0x1E
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes
	waitmovement 0
	delay 0x14
	playse SE_CLICK
	delay 0xA
	playse SE_CLICK
	delay 0xA
	playse SE_CLICK
	delay 0xA
	playse SE_CLICK
	delay 0x14
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment
	playse SE_PC_ON
	waitse
	delay 0x14
	applymovement LOCALID_BIRCHS_LAB_BIRCH, LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex
	waitmovement 0
	applymovement LOCALID_BIRCHS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x2
	setvar VAR_SCOTT_BF_CALL_STEP_COUNTER, 0x0
	setflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayUpgradeComment:: @ 0x081F14CD
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanUpgradeComment:: @ 0x081F14D7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe, MSGBOX_DEFAULT
	closemessage
	return

LittlerootTown_ProfessorBirchsLab_Movement_BirchRetrievePokedexes:
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_BirchReturnPokedex:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_faster_down
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_ChooseJohtoStarter:: @ 0x081F14FD
	lockall
	applymovement LOCALID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x5
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForJohtoStarter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide:: @ 0x081F151F
	lock
	faceplayer
	goto_if_ge VAR_BIRCH_LAB_STATE, 0x3, LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork, MSGBOX_DEFAULT
	setflag FLAG_BIRCH_AIDE_MET
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideAlreadyMet:: @ 0x081F1542
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AideReceivedStarter:: @ 0x081F154C
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Cyndaquil:: @ 0x081F1556
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_CYNDAQUIL, 0xA, 0x3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Totodile:: @ 0x081F158A
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_TOTODILE, 0xA, 0x3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Chikorita:: @ 0x081F15BE
	release
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x6, LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	showmonpic SPECIES_CHIKORITA, 0xA, 0x3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_AlreadyChoseJohtoStarter:: @ 0x081F15F2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TakeYourTime:: @ 0x081F15FC
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveCyndaquil:: @ 0x081F1607
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
	givemon SPECIES_CYNDAQUIL, 0x5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToParty:: @ 0x081F163C
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendCyndaquilToPC:: @ 0x081F1667
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CYNDAQUIL_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CyndaquilTransferredToPC:: @ 0x081F168D
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedCyndaquil:: @ 0x081F1698
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveTotodile:: @ 0x081F16A8
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
	givemon SPECIES_TOTODILE, 0x5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToParty:: @ 0x081F16DD
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendTotodileToPC:: @ 0x081F1708
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_TOTODILE_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TotodileTransferredToPC:: @ 0x081F172E
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedTotodile:: @ 0x081F1739
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GiveChikorita:: @ 0x081F1749
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
	givemon SPECIES_CHIKORITA, 0x5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToParty:: @ 0x081F177E
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_SendChikoritaToPC:: @ 0x081F17A9
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter
	removeobject LOCALID_BIRCHS_LAB_CHIKORITA_BALL
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ChikoritaTransferredToPC:: @ 0x081F17CF
	call Common_EventScript_TransferredToPC
	goto LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedChikorita:: @ 0x081F17DA
	hidemonpic
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting, MSGBOX_DEFAULT
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x6
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivedJohtoStarter:: @ 0x081F17EA
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter
	waitmessage
	waitfanfare
	return

LittlerootTown_ProfessorBirchsLab_EventScript_Birch:: @ 0x081F17F5
	lock
	faceplayer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x5, LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x2, LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

LittlerootTown_ProfessorBirchsLab_EventScript_CanHaveAnyOneOfRarePokemon:: @ 0x081F1825
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GrassyPatchWaiting:: @ 0x081F182F
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister:: @ 0x081F1839
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x3, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x6, ProfBirch_EventScript_RatePokedexOrRegister
	goto_if_eq VAR_BIRCH_LAB_STATE, 0x5, LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome, MSGBOX_DEFAULT
	release
	end

EventScript_RegisterProfBirch:: @ 0x081F186D
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 0x1E
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 0x1E
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 0x2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex:: @ 0x081F1893
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex, MSGBOX_DEFAULT
	call LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCHS_LAB_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls
	setvar VAR_BIRCH_LAB_STATE, 0x5
	setflag FLAG_ADVENTURE_STARTED
	setvar VAR_OLDALE_TOWN_STATE, 0x1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 0x4
	setvar VAR_LITTLEROOT_TOWN_STATE, 0x3
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls:: @ 0x081F18ED
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 0x5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0x0
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanGivePokeBalls:: @ 0x081F191A
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 0x5
	call_if_eq VAR_RESULT, FALSE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0x1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_ReceivePokedex:: @ 0x081F1947
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 0x1
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PokemonAwait:: @ 0x081F195F
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait, MSGBOX_DEFAULT
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayNoRoomForPokeBalls:: @ 0x081F1969
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanNoRoomForPokeBalls:: @ 0x081F1972
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_Movement_RivalApproachPlayer:
	walk_down
	walk_in_place_faster_left
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_Machine:: @ 0x081F197E
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Rival:: @ 0x081F1987
	lock
	faceplayer
	goto_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x5, LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x6, LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier
	goto_if_ge VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0x2, LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhereShouldIGoNext:: @ 0x081F19C3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanWhereShouldIGoNext:: @ 0x081F19CC
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalFuturePlans:: @ 0x081F19D5
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayWhatNextImStayingHere:: @ 0x081F19EE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanPreferCollectingSlowly:: @ 0x081F19F7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalHaveYouGoneToBattleFrontier:: @ 0x081F1A00
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayHaveYouGoneToBattleFrontier:: @ 0x081F1A19
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanHaveYouGoneToBattleFrontier:: @ 0x081F1A22
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_RivalTakeBreakFromFieldwork:: @ 0x081F1A2B
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayTakeBreakFromFieldwork:: @ 0x081F1A44
	msgbox LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_BrendanTakeBreakFromFieldwork:: @ 0x081F1A4D
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_PC:: @ 0x081F1A56
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf:: @ 0x081F1A5F
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Book:: @ 0x081F1A68
	msgbox LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall:: @ 0x081F1A71
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
	waitmessage
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_Text_BirchAwayOnFieldwork: @ 0x081F1A7D
	.string "え？　オダマキはかせ？\p"
	.string "はかせ　なら　フィールドワークに\n"
	.string "でかけていて　いませんよ\p"
	.string "⋯⋯あ　フィールドワークって　いうのは\p"
	.string "じっさいに　のやまへ　でかけていって\n"
	.string "けんきゅうを　すること　ですね！\p"
	.string "はかせは　つくえのうえで　けんきゅうを\n"
	.string "するよりも　じっさいに　そとへ　とびだして\l"
	.string "たいけんする　タイプのひと　なんです！$"

LittlerootTown_ProfessorBirchsLab_Text_BirchIsntOneForDeskWork: @ 0x081F1B1D
	.string "はかせは　つくえのうえで　けんきゅうを\n"
	.string "するよりも　じっさいに　そとへ　とびだして\l"
	.string "たいけんする　タイプのひと　なんです！$"

LittlerootTown_ProfessorBirchsLab_Text_BirchEnjoysRivalsHelpToo: @ 0x081F1B5B
	.string "オダマキはかせは\n"
	.string "ポケモンが　どこに　すんでいるのか\l"
	.string "ぶんぷの　ちょうさを　なさっています\p"
	.string "{RIVAL}さんは　すきな　おとうさんの\n"
	.string "おてつだいを　なさって　いるのですよ$"

LittlerootTown_ProfessorBirchsLab_Text_LikeYouToHavePokemon: @ 0x081F1BAD
	.string "オダマキ“⋯⋯さて　{PLAYER}{KUN}！\p"
	.string "きみのことは　おとうさん　から\n"
	.string "いつも　きかされていたよ！\p"
	.string "きみは　まだ　じぶんの　ポケモンを\n"
	.string "もったことが　ないんだって？\p"
	.string "それにしては　さっきの　たたかいぶり\n"
	.string "なかなか　みごと　だったよ！\p"
	.string "やっぱり　きみには　おとうさんの\n"
	.string "ちが　ながれて　いるんだな！\p"
	.string "そうそう！　たすけてくれた　おれいに\n"
	.string "さっきの　ポケモンは　わたしから\l"
	.string "きみへの　プレゼントに　しよう！\p"
	.string "{PLAYER}は\n"
	.string "{STR_VAR_1}を　もらった！$"

LittlerootTown_ProfessorBirchsLab_Text_WhyNotGiveNicknameToMon: @ 0x081F1C81
	.string "オダマキ“せっかく　だから　{STR_VAR_1}に\n"
	.string "ニックネームを　つけてみては　どうだい？$"

LittlerootTown_ProfessorBirchsLab_Text_MightBeGoodIdeaToGoSeeRival: @ 0x081F1CA8
	.string "オダマキ“これから　さらに\n"
	.string "けいけんを　つんで　いけば\l"
	.string "いい　トレーナーに　なれそうだ！\p"
	.string "ちょうど　うちの　{RIVAL}も\n"
	.string "わたしを　てつだい　ながら\l"
	.string "ポケモンの　ちょうさを　しているんだ\p"
	.string "{PLAYER}{KUN}　いちど\n"
	.string "あいに　いったら　どうだろう？$"

LittlerootTown_ProfessorBirchsLab_Text_GetRivalToTeachYou: @ 0x081F1D1C
	.string "オダマキ“そうか！\n"
	.string "それは　{RIVAL}も　よろこぶぞ！\p"
	.string "トレーナーが　どんな　ものか\n"
	.string "おしえてもらうと　いいぞ！$"

LittlerootTown_ProfessorBirchsLab_Text_DontBeThatWay: @ 0x081F1D52
	.string "オダマキ“そんなこと　いわずに\n"
	.string "あいに　いったら　どうだろう？$"

LittlerootTown_ProfessorBirchsLab_Text_BirchRivalGoneHome: @ 0x081F1D72
	.string "オダマキ“{RIVAL}　だったら\n"
	.string "いえに　かえってるんじゃ　ないのか？\p"
	.string "それとも　また　どこかの　くさむらに\n"
	.string "もぐりこんで　いるのかも⋯⋯\p"
	.string "もしも　きみの　ポケモンが　キズついたら\n"
	.string "じぶんの　いえで　やすむと　いいぞ！$"

LittlerootTown_ProfessorBirchsLab_Text_HeardYouBeatRivalTakePokedex: @ 0x081F1DDC
	.string "オダマキ“おっ　{PLAYER}{KUN}！\p"
	.string "はじめてで　{RIVAL}に\n"
	.string "かつ　だなんて　すごいじゃないか！\p"
	.string "{RIVAL}は　かなり　まえから\n"
	.string "わたしの　けんきゅうを　てつだっていて\l"
	.string "トレーナーれきは　けっこう　ながいんだよ！\p"
	.string "うむ！　{PLAYER}{KUN}　にも\n"
	.string "けんきゅうの　ために　とりよせた\l"
	.string "この　ポケモンずかんを　あげよう！$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex: @ 0x081F1E6C
	.string "{PLAYER}は\n"
	.string "ポケモンずかんを　もらった！$"

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex: @ 0x081F1E7F
	.string "オダマキ“その　ポケモンずかんは\n"
	.string "きみが　であった　ポケモンを\p"
	.string "じどうてきに　きろく　していってくれる\n"
	.string "ハイテクな　どうぐ　なんだ！\p"
	.string "{RIVAL}も　その　ずかんを　もっていて\n"
	.string "あちこちに　あそびに　いくんだな\p"
	.string "で　めずらしい　ポケモンを　つかまえて\n"
	.string "ずかんに　きろく　できるとだね\p"
	.string "フィールドワークを　している　わたしを\n"
	.string "さがしだしては　みせて　くれるんだよ！$"

LittlerootTown_ProfessorBirchsLab_Text_CountlessPokemonAwait: @ 0x081F1F31
	.string "オダマキ“きみの　ゆくてには\n"
	.string "たくさんの　ポケモンが　まっているよ！\p"
	.string "あー　はやく　フィールドワークに\n"
	.string "いきたく　なってきたぞ！$"

LittlerootTown_ProfessorBirchsLab_Text_MayGotPokedexTooTakeThese: @ 0x081F1F72
	.string "ハルカ“{PLAYER}{KUN}も\n"
	.string "ポケモンずかん　もらったんだね！\p"
	.string "よかったね！　あたしと　いっしょだよ！\n"
	.string "じゃあ　あたしは　これを　あげる！$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCutePokemonWithPokeBalls: @ 0x081F1FB3
	.string "ハルカ“ポケモンが\n"
	.string "たくさん　いると　たのしいよ！\p"
	.string "あたし　いろんな　ポケモン　さがしたいから\n"
	.string "いろんな　ところを　さがすわ！\p"
	.string "そして　かわいい　ポケモンが　いたら\n"
	.string "モンスターボールで　つかまえちゃう！$"

LittlerootTown_ProfessorBirchsLab_Text_OhYourBagsFull: @ 0x081F2019
	.string "あら？　バッグ　いっぱいだよ$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhereShouldIGoNext: @ 0x081F2028
	.string "ハルカ“こんどは　どこまで\n"
	.string "ポケモンを　さがしに　いこうかな？$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanGotPokedexTooTakeThese: @ 0x081F2048
	.string "ユウキ“ふうん　{PLAYER}も\n"
	.string "ポケモンずかん　もらったのか\p"
	.string "じゃあ　オレは　これ　やるよ$"

LittlerootTown_ProfessorBirchsLab_Text_CatchCoolPokemonWithPokeBalls: @ 0x081F2072
	.string "ユウキ“ポケモンが\n"
	.string "たくさん　いると　たのしいからな\p"
	.string "オレ　いろんな　ポケモン　さがすため\n"
	.string "いろんな　ところに　いくんだ\p"
	.string "そして　かっこいい　ポケモンが　いたら\n"
	.string "モンスターボールで　つかまえるんだ$"

LittlerootTown_ProfessorBirchsLab_Text_HeyYourBagsFull: @ 0x081F20D5
	.string "おや？　バッグ　いっぱいだよ$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanWhereShouldIGoNext: @ 0x081F20E4
	.string "ユウキ“こんどは　どこに\n"
	.string "ポケモン　さがしに　いこうかな⋯⋯$"

LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine: @ 0x081F2103
	.string "なんか　すごそうな　マシンだ！\n"
	.string "はかせが　けんきゅうに　つかうのかな？$"

LittlerootTown_ProfessorBirchsLab_Text_PCUsedForResearch: @ 0x081F2127
	.string "けんきゅうに　つかわれている　パソコンだ！\n"
	.string "⋯⋯　さわるのは　やめておこう$"

LittlerootTown_ProfessorBirchsLab_Text_CrammedWithBooksOnPokemon: @ 0x081F214D
	.string "ポケモンに　ついて　かかれた\n"
	.string "ほんが　いっぱい　ある！$"

LittlerootTown_ProfessorBirchsLab_Text_BookTooHardToRead: @ 0x081F2169
	.string "むずかしそうな　ほんが　おいてある！$"

LittlerootTown_ProfessorBirchsLab_Text_OtherRegionsUpgradeToNational: @ 0x081F217C
	.string "オダマキ“⋯⋯さて\p"
	.string "{PLAYER}{KUN}と　{RIVAL}に　ポケモンの\n"
	.string "ちょうさを　おねがい　していた　わけだが\p"
	.string "きみたちの　どりょくの　おかげで\n"
	.string "いろんな　ことが　わかってきた！\p"
	.string "どうやら　ホウエンちほう　には\n"
	.string "それいがいの　ちほうの　ポケモンも\l"
	.string "せいそく　している　らしいんだ！\p"
	.string "それだけ　ホウエンちほうは\n"
	.string "ゆたかな　しぜんに　めぐまれている\l"
	.string "という　ことなんだろうな！\p"
	.string "というわけで　きみたちの　ずかんを\n"
	.string "ぜんこくばんに　バージョンアップ\l"
	.string "してあげようと　おもう！\p"
	.string "さあ　ずかんを　かしておくれ！$"

LittlerootTown_ProfessorBirchsLab_Text_MayUpgradeSoCool: @ 0x081F226E
	.string "ハルカ“えへへー！\p"
	.string "あたしの　ずかんまで\n"
	.string "ぜんこくばんに　してもらえる　なんて\p"
	.string "{PLAYER}{KUN}が　たくさん　ポケモンを\n"
	.string "しらべてくれた　おかげだね！$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanYouCanThankMe: @ 0x081F22B6
	.string "ユウキ“オレ　はりきって　ホウエンじゅうの\n"
	.string "ポケモンのこと　しらべたからな\p"
	.string "{PLAYER}も　ずかんを　ぜんこくばんに\n"
	.string "してもらえて　ラッキーだったな！$"

LittlerootTown_ProfessorBirchsLab_Text_OkayAllDone: @ 0x081F22FE
	.string "オダマキ“ホイ　できたぞ！$"

LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational: @ 0x081F230C
	.string "{PLAYER}の　ポケモンずかんが\n"
	.string "ぜんこくばんに　バージョンアップ　した！$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting2: @ 0x081F232E
	.string "オダマキ“いいかい？\n"
	.string "チャンピオンに　なったから　といって\l"
	.string "ポケモンの　みちに　おわりは　ないんだ\p"
	.string "まだ　あしを　ふみいれていない　くさむらは\n"
	.string "いつまでも　きみを　まっているよ！$"

LittlerootTown_ProfessorBirchsLab_Text_MayTakeBreakFromFieldwork: @ 0x081F2388
	.string "ハルカ“さーて　フィールドワークは\n"
	.string "ちょっとだけ　おやすみして\p"
	.string "しばらくは　ここで\n"
	.string "はかせの　おてつだいでも　しよっかなー$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanTakeBreakFromFieldwork: @ 0x081F23C6
	.string "ユウキ“オレは　とりあえず\n"
	.string "フィールドワークは　おやすみだな！\p"
	.string "しばらくは　ここで\n"
	.string "はかせの　てつだいでも　してるよ！$"

LittlerootTown_ProfessorBirchsLab_Text_CompletedDexChoosePokemon: @ 0x081F2402
	.string "オダマキ“おお　{PLAYER}{KUN}！\n"
	.string "ちょっと　ずかんを　みせて　もらうよ\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯\p"
	.string "⋯⋯うむ　やはり　まちがいない！\n"
	.string "キミは　ほんとうに　ホウエンちほうの\l"
	.string "ずかんを　かんせい　させたんだな！\p"
	.string "いやー　たいしたもんだ！\p"
	.string "きみの　その　すばらしい　はたらきに\n"
	.string "かんしゃの　きもちを　こめて\l"
	.string "わたしから　プレゼントを　おくろう！\p"
	.string "それは⋯⋯\p"
	.string "ほかの　ちほうでしか　みつからない\n"
	.string "めずらしい　ポケモンだよ！\p"
	.string "3ひきの　なかから\n"
	.string "すきなものを　1ひきだけ　あげよう！$"

LittlerootTown_ProfessorBirchsLab_Text_CanHaveAnyOneOfRarePokemon: @ 0x081F24F0
	.string "オダマキ“ほかの　ちほうでしか\n"
	.string "みつからない　めずらしい　ポケモンだよ！\p"
	.string "3ひきの　なかから\n"
	.string "すきなものを　1ひきだけ　あげよう！$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeCyndaquil: @ 0x081F2532
	.string "オダマキ“ほのおの　ポケモン　ヒノアラシに\n"
	.string "めを　つけるとは　やはり　するどいな！\p"
	.string "じゃあ　ヒノアラシで　いいんだね？$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeTotodile: @ 0x081F256E
	.string "オダマキ“みずの　ポケモン　ワニノコか\n"
	.string "うーむ　いいものを　えらぶじゃないか！\p"
	.string "よし　ワニノコで　いいんだね？$"

LittlerootTown_ProfessorBirchsLab_Text_YoullTakeChikorita: @ 0x081F25A6
	.string "オダマキ“くさの　ポケモン　チコリータか\n"
	.string "さすがだ　わかってるなあ！\p"
	.string "ならば　チコリータで　けっていだね？$"

LittlerootTown_ProfessorBirchsLab_Text_TakeYourTimeAllInvaluable: @ 0x081F25DC
	.string "オダマキ“じっくり　かんがえて\n"
	.string "きめると　いいよ\l"
	.string "どれも　きちょうな　ポケモン　だからね$"

LittlerootTown_ProfessorBirchsLab_Text_PickedFinePokemon: @ 0x081F2609
	.string "オダマキ“なるほど！\n"
	.string "いい　ポケモンを　えらんだね！$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedJohtoStarter: @ 0x081F2624
	.string "{PLAYER}は　オダマキはかせ　から\n"
	.string "{STR_VAR_1}を　もらった！$"

LittlerootTown_ProfessorBirchsLab_Text_NicknameJohtoStarter: @ 0x081F263D
	.string "もらった　{STR_VAR_1}に\n"
	.string "ニックネームを　つけますか？$"

LittlerootTown_ProfessorBirchsLab_Text_GrassyPatchWaiting: @ 0x081F2655
	.string "オダマキ“{PLAYER}{KUN}　いいかい？\n"
	.string "ホウエンの　ずかんが　かんせい　しても\l"
	.string "ポケモンの　みちに　おわりは　ないんだ\p"
	.string "まだ　あしを　ふみいれていない　くさむらは\n"
	.string "いつまでも　きみを　まっているよ！$"

LittlerootTown_ProfessorBirchsLab_Text_BetterLeaveOthersAlone: @ 0x081F26B5
	.string "やくそくの　1ひきは　もう　もらったから\n"
	.string "のこりには　さわらないで　おこう！$"

LittlerootTown_ProfessorBirchsLab_Text_DontHaveAnyRoomForPokemon: @ 0x081F26DC
	.string "おや？　それいじょう\n"
	.string "ポケモンを　もてない　みたいだな$"

LittlerootTown_ProfessorBirchsLab_Text_MayWhatNextImStayingHere: @ 0x081F26F8
	.string "ハルカ“{PLAYER}{KUN}は\n"
	.string "このあと⋯⋯　どうする　つもり？\p"
	.string "ポケモン　しょうぶの　みちを　きわめる？\p"
	.string "それとも　ぜんこく　ずかんの\n"
	.string "かんせいを　めざすの？\p"
	.string "あたしは　ここで\n"
	.string "はかせの　おてつだいを　つづけるわ$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanPreferCollectingSlowly: @ 0x081F275E
	.string "ユウキ“オレは　ポケモン　あつめるより\n"
	.string "これは！　と　おもった　1ひきを\l"
	.string "じっくり　そだてるのが　すきなのさ！$"

LittlerootTown_ProfessorBirchsLab_Text_MayHaveYouGoneToBattleFrontier: @ 0x081F2796
	.string "ハルカ“あっ　{PLAYER}{KUN}！\n"
	.string "バトルフロンティア　っていう　ところには\l"
	.string "もう　いってみた？$"

LittlerootTown_ProfessorBirchsLab_Text_BrendanHaveYouGoneToBattleFrontier: @ 0x081F27C2
	.string "ユウキ“やあ　{PLAYER}か！\n"
	.string "バトルフロンティア　って　ところには\l"
	.string "もう　いってみたか？$"

LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall: @ 0x081F27EC
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯　ピッ！\p"
	.string "エニシダ“やあやあ　{PLAYER}{KUN}！\n"
	.string "わたしだよ　エニシダだよ！\p"
	.string "いま　タイドリップごうに　のってるんだけど\n"
	.string "やっぱり　うみは　きもちが　いいねえー\p"
	.string "ところで⋯⋯\p"
	.string "きみを　しょうたい　したい　ばしょが\n"
	.string "あるんだけど　どうだい？\p"
	.string "もし　きょうみが　あるなら\n"
	.string "カイナか　ミナモの　ふねのりばから\l"
	.string "ふねに　のっておくれ！\p"
	.string "くわしいことは　あったときに　おしえよう\n"
	.string "じゃあな　まってるぞ！\p"
	.string "⋯⋯　⋯⋯　⋯⋯\n"
	.string "⋯⋯　⋯⋯　⋯⋯　ツー$"
