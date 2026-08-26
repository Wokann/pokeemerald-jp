@ LilycoveCity_ContestLobby scripts (JP map g13 m4 @ 0x082068D1)

LilycoveCity_ContestLobby_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_ContestLobby_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_ContestLobby_OnFrame
	.byte 0

LilycoveCity_ContestLobby_OnTransition:: @ 0x082068DC
	call LilycoveCity_ContestLobby_EventScript_TryShowContestReporter
	call LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster
	end

LilycoveCity_ContestLobby_EventScript_TryShowBlendMaster:: @ 0x082068E7
	getpokenewsactive POKENEWS_BLENDMASTER
	goto_if_eq VAR_RESULT, 0x1, LilycoveCity_ContestLobby_EventScript_ShowBlendMaster
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
	return

LilycoveCity_ContestLobby_EventScript_ShowBlendMaster:: @ 0x082068FC
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
	return

LilycoveCity_ContestLobby_OnFrame:: @ 0x08206903
	map_script_2 VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0x1, LilycoveCity_ContestLobby_EventScript_TryDoContestArtist
	map_script_2 VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0x2, LilycoveCity_ContestLobby_EventScript_TryDoLinkContestArtist
	.2byte 0

LilycoveCity_ContestLobby_EventScript_TryDoContestArtist:: @ 0x08206915
	goto_if_set FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR, LilycoveCity_ContestLobby_EventScript_ContestArtist
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0x0
	end

LilycoveCity_ContestLobby_EventScript_ContestArtist:: @ 0x08206924
	lockall
	addobject LOCALID_CONTEST_LOBBY_ARTIST
	applymovement LOCALID_CONTEST_LOBBY_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistApproachPlayer
	waitmovement LOCALID_CONTEST_LOBBY_ARTIST
	applymovement LOCALID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerFaceArtist
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint, MSGBOX_DEFAULT
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_ARTIST
	lockall
	msgbox LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum
	goto_if_eq VAR_RESULT, NO, LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePainting
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum:: @ 0x0820696A
	msgbox LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum, MSGBOX_DEFAULT
	closemessage
	special SaveMuseumContestPainting
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0x0
	specialvar VAR_RESULT, GiveMonArtistRibbon
	call_if_eq VAR_RESULT, 0x1, LilycoveCity_ContestLobby_EventScript_ReceivedArtistRibbon
	applymovement LOCALID_CONTEST_LOBBY_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistExit
	waitmovement 0
	removeobject LOCALID_CONTEST_LOBBY_ARTIST
	call LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons
	call LilycoveCity_ContestLobby_EventScript_SetPaintingFlag
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePainting:: @ 0x082069A4
	msgbox LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseum
	msgbox LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CONTEST_LOBBY_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistExit
	waitmovement 0
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0x0
	removeobject LOCALID_CONTEST_LOBBY_ARTIST
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ReceivedArtistRibbon:: @ 0x082069D4
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	special BufferContestWinnerMonName
	applymovement LOCALID_CONTEST_LOBBY_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistBeginToExit
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CONTEST_LOBBY_ARTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CONTEST_LOBBY_ARTIST, LilycoveCity_ContestLobby_Movement_ArtistReturnToPlayer
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_TakeMementoOfPainting, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LilycoveCity_ContestLobby_Text_ReceivedARibbon, MSGBOX_DEFAULT
	waitfanfare
	msgbox LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon, MSGBOX_DEFAULT
	msgbox LilycoveCity_ContestLobby_Text_OkaySeeYou, MSGBOX_DEFAULT
	closemessage
	return

LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons:: @ 0x08206A20
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 1, LilycoveCity_ContestLobby_EventScript_ShowPatron1
	case 2, LilycoveCity_ContestLobby_EventScript_ShowPatron2
	case 3, LilycoveCity_ContestLobby_EventScript_ShowPatron3
	case 4, LilycoveCity_ContestLobby_EventScript_ShowPatron4
	case 5, LilycoveCity_ContestLobby_EventScript_ShowTourists
	return

LilycoveCity_ContestLobby_EventScript_ShowPatron1:: @ 0x08206A62
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1
	return

LilycoveCity_ContestLobby_EventScript_ShowPatron2:: @ 0x08206A66
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2
	return

LilycoveCity_ContestLobby_EventScript_ShowPatron3:: @ 0x08206A6A
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3
	return

LilycoveCity_ContestLobby_EventScript_ShowPatron4:: @ 0x08206A6E
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4
	return

LilycoveCity_ContestLobby_EventScript_ShowTourists:: @ 0x08206A72
	clearflag FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS
	return

LilycoveCity_ContestLobby_EventScript_SetPaintingFlag:: @ 0x08206A76
	switch VAR_CONTEST_CATEGORY
	case 0, LilycoveCity_ContestLobby_EventScript_MadeCoolPainting
	case 1, LilycoveCity_ContestLobby_EventScript_MadeBeautyPainting
	case 2, LilycoveCity_ContestLobby_EventScript_MadeCutePainting
	case 3, LilycoveCity_ContestLobby_EventScript_MadeSmartPainting
	case 4, LilycoveCity_ContestLobby_EventScript_MadeToughPainting
	return

LilycoveCity_ContestLobby_EventScript_MadeCoolPainting:: @ 0x08206AB3
	setflag FLAG_COOL_PAINTING_MADE
	return

LilycoveCity_ContestLobby_EventScript_MadeBeautyPainting:: @ 0x08206AB7
	setflag FLAG_BEAUTY_PAINTING_MADE
	return

LilycoveCity_ContestLobby_EventScript_MadeCutePainting:: @ 0x08206ABB
	setflag FLAG_CUTE_PAINTING_MADE
	return

LilycoveCity_ContestLobby_EventScript_MadeSmartPainting:: @ 0x08206ABF
	setflag FLAG_SMART_PAINTING_MADE
	return

LilycoveCity_ContestLobby_EventScript_MadeToughPainting:: @ 0x08206AC3
	setflag FLAG_TOUGH_PAINTING_MADE
	return

LilycoveCity_ContestLobby_Movement_ArtistApproachPlayer:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LilycoveCity_ContestLobby_Movement_ArtistExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LilycoveCity_ContestLobby_Movement_PlayerFaceArtist:
	walk_in_place_faster_left
	step_end

LilycoveCity_ContestLobby_Movement_ArtistBeginToExit:
	walk_down
	walk_down
	walk_down
	step_end

LilycoveCity_ContestLobby_Movement_ArtistReturnToPlayer:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_right
	step_end

LilycoveCity_ContestLobby_EventScript_TryDoLinkContestArtist:: @ 0x08206AE7
	goto_if_set FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR, LilycoveCity_ContestLobby_EventScript_LinkContestArtist
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0x0
	end

LilycoveCity_ContestLobby_EventScript_LinkContestArtist:: @ 0x08206AF6
	lockall
	addobject LOCALID_CONTEST_LOBBY_LINK_ARTIST
	applymovement LOCALID_CONTEST_LOBBY_LINK_ARTIST, LilycoveCity_ContestLobby_Movement_LinkArtistApproachPlayer
	waitmovement LOCALID_CONTEST_LOBBY_LINK_ARTIST
	applymovement LOCALID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerFaceLinkArtist
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint, MSGBOX_DEFAULT
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_ARTIST
	msgbox LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink
	goto_if_eq VAR_RESULT, NO, LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePaintingLink
	end

LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink:: @ 0x08206B3A
	msgbox LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum, MSGBOX_DEFAULT
	closemessage
	special SaveMuseumContestPainting
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0x0
	specialvar VAR_RESULT, GiveMonArtistRibbon
	call_if_eq VAR_RESULT, 0x1, LilycoveCity_ContestLobby_EventScript_ReceivedLinkArtistRibbon
	applymovement LOCALID_CONTEST_LOBBY_LINK_ARTIST, LilycoveCity_ContestLobby_Movement_LinkArtistExit
	waitmovement 0
	removeobject LOCALID_CONTEST_LOBBY_LINK_ARTIST
	call LilycoveCity_ContestLobby_EventScript_UpdateMuseumPatrons
	call LilycoveCity_ContestLobby_EventScript_SetPaintingFlag
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ConfirmDontTakePaintingLink:: @ 0x08206B74
	msgbox LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_ContestLobby_EventScript_TakePaintingToMuseumLink
	msgbox LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CONTEST_LOBBY_LINK_ARTIST, LilycoveCity_ContestLobby_Movement_LinkArtistExit
	waitmovement 0
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0x0
	removeobject LOCALID_CONTEST_LOBBY_LINK_ARTIST
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ReceivedLinkArtistRibbon:: @ 0x08206BA4
	incrementgamestat GAME_STAT_RECEIVED_RIBBONS
	setflag FLAG_SYS_RIBBON_GET
	special BufferContestWinnerMonName
	applymovement LOCALID_CONTEST_LOBBY_LINK_ARTIST, LilycoveCity_ContestLobby_Movement_LinkArtistBeginExit
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_CONTEST_LOBBY_LINK_ARTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CONTEST_LOBBY_LINK_ARTIST, LilycoveCity_ContestLobby_Movement_LinkArtistReturnToPlayer
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_TakeMementoOfPainting, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LilycoveCity_ContestLobby_Text_ReceivedARibbon, MSGBOX_DEFAULT
	waitfanfare
	msgbox LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon, MSGBOX_DEFAULT
	msgbox LilycoveCity_ContestLobby_Text_OkaySeeYou, MSGBOX_DEFAULT
	closemessage
	return

LilycoveCity_ContestLobby_Movement_LinkArtistApproachPlayer:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LilycoveCity_ContestLobby_Movement_LinkArtistExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LilycoveCity_ContestLobby_Movement_PlayerFaceLinkArtist:
	walk_in_place_faster_right
	step_end

LilycoveCity_ContestLobby_Movement_LinkArtistBeginExit:
	walk_down
	walk_down
	walk_down
	step_end

LilycoveCity_ContestLobby_Movement_LinkArtistReturnToPlayer:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

LilycoveCity_ContestLobby_EventScript_ContestReceptionist:: @ 0x08206C14
	special ClearLinkContestFlags
	specialvar VAR_RESULT, IsContestDebugActive
	goto_if_eq VAR_RESULT, 0x1, LilycoveCity_ContestLobby_EventScript_SetDebug
	call LilycoveCity_ContestLobby_EventScript_SpeakToContestReceptionist
	call LilycoveCity_ContestLobby_EventScript_LeadToContestHall
	special SetContestTrainerGfxIds
	call LilycoveCity_ContestLobby_EventScript_SetPlayerGfx
	call LilycoveCity_ContestLobby_EventScript_SetContestType
	call LilycoveCity_ContestLobby_EventScript_WarpToContestHall
	waitstate
	end

LilycoveCity_ContestLobby_EventScript_SetContestType:: @ 0x08206C45
	switch VAR_CONTEST_RANK
	case 0, LilycoveCity_ContestLobby_EventScript_SetNormalContestType
	case 1, LilycoveCity_ContestLobby_EventScript_SetSuperContestType
	case 2, LilycoveCity_ContestLobby_EventScript_SetHyperContestType
	case 3, LilycoveCity_ContestLobby_EventScript_SetMasterContestType
	return

LilycoveCity_ContestLobby_EventScript_SetNormalContestType:: @ 0x08206C77
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_NORMAL
	return

LilycoveCity_ContestLobby_EventScript_SetSuperContestType:: @ 0x08206C7D
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_SUPER
	return

LilycoveCity_ContestLobby_EventScript_SetHyperContestType:: @ 0x08206C83
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_HYPER
	return

LilycoveCity_ContestLobby_EventScript_SetMasterContestType:: @ 0x08206C89
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_NPC_MASTER
	return

LilycoveCity_ContestLobby_EventScript_SetDebug:: @ 0x08206C8F
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 0x1, warn=FALSE
	additem 0x10A, 0x1
	setvar VAR_0x800B, 0x8
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0x1
	setflag FLAG_SYS_RIBBON_GET
	end

LilycoveCity_ContestLobby_EventScript_WarpToContestHall:: @ 0x08206CAF
	setflag FLAG_ENTERED_CONTEST
	switch VAR_CONTEST_CATEGORY
	case 0, LilycoveCity_ContestLobby_EventScript_WarpToCoolContestHall
	case 1, LilycoveCity_ContestLobby_EventScript_WarpToBeautyContestHall
	case 2, LilycoveCity_ContestLobby_EventScript_WarpToCuteContestHall
	case 3, LilycoveCity_ContestLobby_EventScript_WarpToSmartContestHall
	case 4, LilycoveCity_ContestLobby_EventScript_WarpToToughContestHall
	return

LilycoveCity_ContestLobby_EventScript_WarpToCoolContestHall:: @ 0x08206CEF
	setwarp MAP_CONTEST_HALL_COOL, 0x7, 0x5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_WarpToBeautyContestHall:: @ 0x08206CFC
	setwarp MAP_CONTEST_HALL_BEAUTY, 0x7, 0x5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_WarpToCuteContestHall:: @ 0x08206D09
	setwarp MAP_CONTEST_HALL_CUTE, 0x7, 0x5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_WarpToSmartContestHall:: @ 0x08206D16
	setwarp MAP_CONTEST_HALL_SMART, 0x7, 0x5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_WarpToToughContestHall:: @ 0x08206D23
	setwarp MAP_CONTEST_HALL_TOUGH, 0x7, 0x5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_LeadToContestHall:: @ 0x08206D30
	lockall
	applymovement LOCALID_CONTEST_LOBBY_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistApproachCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 0xC, 0x2, METATILE_Contest_WallShadow, TRUE
	setmetatile 0xC, 0x3, METATILE_Contest_FloorShadow, TRUE
	special DrawWholeMapView
	applymovement LOCALID_CONTEST_LOBBY_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistExitCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 0xC, 0x2, METATILE_Contest_CounterFlap_Top, TRUE
	setmetatile 0xC, 0x3, METATILE_Contest_CounterFlap_Bottom, TRUE
	special DrawWholeMapView
	delay 0x14
	applymovement LOCALID_CONTEST_LOBBY_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistFacePlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerApproachReceptionist
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_ComeThroughHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CONTEST_LOBBY_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_ReceptionistWalkToContestHall
	applymovement LOCALID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerWalkToContestHall
	waitmovement 0
	releaseall
	return

LilycoveCity_ContestLobby_Movement_PlayerWalkToContestHall:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

LilycoveCity_ContestLobby_Movement_PlayerApproachReceptionist:
	walk_in_place_faster_left
	walk_left
	step_end

LilycoveCity_ContestLobby_Movement_ReceptionistApproachCounter:
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

LilycoveCity_ContestLobby_Movement_ReceptionistExitCounter:
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

LilycoveCity_ContestLobby_Movement_ReceptionistWalkToContestHall:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

LilycoveCity_ContestLobby_Movement_ReceptionistFacePlayer:
	walk_in_place_faster_right
	step_end

LilycoveCity_ContestLobby_EventScript_BlackBelt:: @ 0x08206DC8
	msgbox LilycoveCity_ContestLobby_Text_MasterRankHereICome, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Girl:: @ 0x08206DD1
	msgbox LilycoveCity_ContestLobby_Text_WholeVarietyOfPokemonHere, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Artist:: @ 0x08206DDA
	msgbox LilycoveCity_ContestLobby_Text_ContestFeastForEyes, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_FatMan:: @ 0x08206DE3
	msgbox LilycoveCity_ContestLobby_Text_ToughContestIsExtreme, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Fisherman:: @ 0x08206DEC
	msgbox LilycoveCity_ContestLobby_Text_LavishedCareOnMon, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_NinjaBoy:: @ 0x08206DF5
	msgbox LilycoveCity_ContestLobby_Text_MadePokeblocksWithFamily, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner1:: @ 0x08206DFE
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_1
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner2:: @ 0x08206E05
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_2
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner3:: @ 0x08206E0C
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_3
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner4:: @ 0x08206E13
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner5:: @ 0x08206E1A
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_5
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_ContestWinner6:: @ 0x08206E21
	lockall
	fadescreen FADE_TO_BLACK
	showcontestpainting CONTEST_WINNER_HALL_6
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_Blender3Boy:: @ 0x08206E28
	msgbox BerryBlender_Text_LetsGetBlendingAlready, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_Blender3Girl:: @ 0x08206E31
	msgbox BerryBlender_Text_WhatKindOfPokeblockWillIGet, MSGBOX_NPC
	end

LilycoveCity_ContestLobby_EventScript_BerryBlenderSpeedRecords:: @ 0x08206E3A
	lockall
	special ShowBerryBlenderRecordWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_LinkContestResults:: @ 0x08206E44
	lockall
	frontier_results FACILITY_LINK_CONTEST
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_BlendMaster:: @ 0x08206E58
	lock
	faceplayer
	msgbox BerryBlender_Text_BlendWithTheBlendMaster, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker1:: @ 0x08206E68
	lock
	msgbox BerryBlender_Text_WhoaAwesome, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker2:: @ 0x08206E73
	lock
	msgbox BerryBlender_Text_WickedlyFast, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker3:: @ 0x08206E7E
	lock
	msgbox BerryBlender_Text_WhatAnExpert, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker4:: @ 0x08206E89
	lock
	faceplayer
	msgbox BerryBlender_Text_MadeAmazingPokeblocksWithMaster, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker5:: @ 0x08206E99
	lock
	faceplayer
	msgbox BerryBlender_Text_QualitiesOfBlendMaster, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_BlendMasterOnlooker6:: @ 0x08206EA9
	lock
	faceplayer
	msgbox BerryBlender_Text_MasterWorksOnSkillsInMountains, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection
	end

LilycoveCity_ContestLobby_EventScript_FaceOriginalDirection:: @ 0x08206EB9
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestLobby_EventScript_LinkContestReceptionist:: @ 0x08206EC6
	special ClearLinkContestFlags
	lock
	faceplayer
	msgbox LilycoveCity_ContestLobby_Text_LinkContestReception, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
	end

LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest:: @ 0x08206ED9
	message LilycoveCity_ContestLobby_Text_EnterContest3
	waitmessage
	multichoice 0x0, 0x0, MULTI_ENTERINFO, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_TryEnterLinkContest
	case 1, LilycoveCity_ContestLobby_EventScript_LinkContestInfo
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_TryEnterLinkContest:: @ 0x08206F16
	msgbox LilycoveCity_ContestLobby_Text_ProgressWillBeSaved, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	message LilycoveCity_ContestLobby_Text_WhichContestMode
	waitmessage
	specialvar VAR_TEMP_D, IsWirelessAdapterConnected
	multichoice 0x0, 0x0, MULTI_LINK_CONTEST_MODE, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_EmeraldMode
	case 1, LilycoveCity_ContestLobby_EventScript_GlobalMode
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_EmeraldMode:: @ 0x08206F7B
	setvar VAR_TEMP_C, 0x0
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType
	end

LilycoveCity_ContestLobby_EventScript_GlobalMode:: @ 0x08206F86
	setvar VAR_TEMP_C, 0x1
	goto_if_eq VAR_TEMP_D, 0x1, LilycoveCity_ContestLobby_EventScript_CancelLinkNoWirelessGMode
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType
	end

LilycoveCity_ContestLobby_EventScript_ChooseLinkContestType:: @ 0x08206F9C
	message LilycoveCity_ContestLobby_Text_EnterWhichContest3
	waitmessage
	multichoice 0x0, 0x0, MULTI_CONTEST_TYPE, FALSE
	switch VAR_RESULT
	case CONTEST_CATEGORIES_COUNT, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

LilycoveCity_ContestLobby_EventScript_LinkContestInfo:: @ 0x08206FCD
	message LilycoveCity_ContestLobby_Text_WhichTopic2
	waitmessage
	multichoice 0x0, 0x0, MULTI_LINK_CONTEST_INFO, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_ExplainLinkContest
	case 1, LilycoveCity_ContestLobby_EventScript_ExplainEMode
	case 2, LilycoveCity_ContestLobby_EventScript_ExplainGMode
	case 3, LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_AskEnterLinkContest
	end

LilycoveCity_ContestLobby_EventScript_ExplainLinkContest:: @ 0x08207015
	msgbox LilycoveCity_ContestLobby_Text_ExplainLinkContest, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainEMode:: @ 0x08207023
	msgbox LilycoveCity_ContestLobby_Text_ExplainEMode, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
	end

LilycoveCity_ContestLobby_EventScript_ExplainGMode:: @ 0x08207031
	msgbox LilycoveCity_ContestLobby_Text_ExplainGMode, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_LinkContestInfo
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkContest:: @ 0x0820703F
	special CloseLink
	msgbox LilycoveCity_ContestLobby_Text_ParticipateAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon:: @ 0x0820704C
	msgbox LilycoveCity_ContestLobby_Text_EnterWhichPokemon3, MSGBOX_DEFAULT
	setvar VAR_CONTEST_RANK, CONTEST_RANK_NORMAL
	showcontestresults
	goto_if_eq VAR_0x8004, 0xFF, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	special TryEnterContestMon
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST, LilycoveCity_ContestLobby_EventScript_LinkCantEnterLowRank
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_EQUAL_RANK, LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest
	goto_if_eq VAR_RESULT, CAN_ENTER_CONTEST_HIGH_RANK, LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_EGG, LilycoveCity_ContestLobby_EventScript_LinkCantEnterEgg
	goto_if_eq VAR_RESULT, CANT_ENTER_CONTEST_FAINTED, LilycoveCity_ContestLobby_EventScript_LinkCantEnterFainted
	end

LilycoveCity_ContestLobby_EventScript_LinkCantEnterLowRank:: @ 0x082070A0
	msgbox LilycoveCity_ContestLobby_Text_MonNotQualifiedForRank, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

LilycoveCity_ContestLobby_EventScript_LinkCantEnterEgg:: @ 0x082070AE
	msgbox LilycoveCity_ContestLobby_Text_EggCannotTakePart2, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

LilycoveCity_ContestLobby_EventScript_LinkCantEnterFainted:: @ 0x082070BC
	msgbox LilycoveCity_ContestLobby_Text_MonInNoCondition2, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_ChooseLinkContestMon
	end

LilycoveCity_ContestLobby_EventScript_EnterMonForLinkContest:: @ 0x082070CA
	copyvar VAR_0x8008, VAR_0x8004
	goto LilycoveCity_ContestLobby_EventScript_TrySetUpLinkContest
	end

LilycoveCity_ContestLobby_EventScript_TrySetUpLinkContest:: @ 0x082070D5
	goto_if_eq VAR_TEMP_D, 0x1, LilycoveCity_ContestLobby_EventScript_SetLinkGroupType
	goto_if_ge VAR_TEMP_D, 0x2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	message LilycoveCity_ContestLobby_Text_PleaseWaitBButtonCancel
	waitmessage
	copyvar VAR_0x8004, VAR_RESULT
	call_if_eq VAR_TEMP_C, 0x0, LilycoveCity_ContestLobby_EventScript_TryLinkEMode
	call_if_eq VAR_TEMP_C, 0x1, LilycoveCity_ContestLobby_EventScript_TryLinkGMode
	goto_if_ge VAR_TEMP_C, 0x2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices
	goto_if_eq VAR_RESULT, LINKUP_FAILED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, LilycoveCity_ContestLobby_EventScript_CancelLinkError
	goto_if_eq VAR_RESULT, LINKUP_FAILED_CONTEST_GMODE, LilycoveCity_ContestLobby_EventScript_CancelLinkModeDifference
	messageinstant LilycoveCity_ContestLobby_Text_Transmitting
	contestlinktransfer
	switch VAR_0x8004
	case 0, LilycoveCity_ContestLobby_EventScript_StartLinkContest
	case 1, LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentContest
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkTransmissionError
	end

LilycoveCity_ContestLobby_EventScript_TryLinkEMode:: @ 0x0820717B
	special TryContestEModeLinkup
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_TryLinkGMode:: @ 0x08207180
	special TryContestGModeLinkup
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentContest:: @ 0x08207185
	msgbox LilycoveCity_ContestLobby_Text_PlayersChoseDifferentContest, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkDifferentChoices:: @ 0x08207193
	msgbox LilycoveCity_ContestLobby_Text_PlayersMadeDifferentChoice, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkModeDifference:: @ 0x082071A1
	msgbox LilycoveCity_ContestLobby_Text_PlayerAt4PCounterUseGMode, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkError:: @ 0x082071AF
	special CloseLink
	msgbox Text_LinkErrorPleaseReset, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkNoWirelessGMode:: @ 0x082071BC
	special CloseLink
	msgbox LilycoveCity_ContestLobby_Text_NoWirelessAdapterInGMode, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_CancelLinkTransmissionError:: @ 0x082071C9
	msgbox LilycoveCity_ContestLobby_Text_TransmissionError, MSGBOX_DEFAULT
	goto LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_StartLinkContest:: @ 0x082071D7
	special GetContestPlayerId
	addvar VAR_0x8004, 0x1
	buffernumberstring STR_VAR_2, VAR_0x8004
	messageautoscroll LilycoveCity_ContestLobby_Text_YourMonIsEntryNumX
	waitmessage
	subvar VAR_0x8004, 0x1
	call LilycoveCity_ContestLobby_EventScript_LeadToLinkContestHall
	setvar VAR_CONTEST_HALL_STATE, 0x1
	special SetLinkContestPlayerGfx
	setvar VAR_CONTEST_TYPE, CONTEST_TYPE_LINK
	setvar VAR_CONTEST_RANK, CONTEST_RANK_MASTER
	call LilycoveCity_ContestLobby_EventScript_WarpToContestHall
	end

LilycoveCity_ContestLobby_EventScript_SetLinkGroupType:: @ 0x0820720B
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_COOL, LilycoveCity_ContestLobby_EventScript_SetLinkGroupCoolContest
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_BEAUTY, LilycoveCity_ContestLobby_EventScript_SetLinkGroupBeautyContest
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_CUTE, LilycoveCity_ContestLobby_EventScript_SetLinkGroupCuteContest
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_SMART, LilycoveCity_ContestLobby_EventScript_SetLinkGroupSmartContest
	call_if_eq VAR_CONTEST_CATEGORY, CONTEST_CATEGORY_TOUGH, LilycoveCity_ContestLobby_EventScript_SetLinkGroupToughContest
	goto LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
	end

LilycoveCity_ContestLobby_EventScript_SetLinkGroupCoolContest:: @ 0x08207248
	setvar VAR_0x8004, 0xF
	return

LilycoveCity_ContestLobby_EventScript_SetLinkGroupBeautyContest:: @ 0x0820724E
	setvar VAR_0x8004, 0x10
	return

LilycoveCity_ContestLobby_EventScript_SetLinkGroupCuteContest:: @ 0x08207254
	setvar VAR_0x8004, 0x11
	return

LilycoveCity_ContestLobby_EventScript_SetLinkGroupSmartContest:: @ 0x0820725A
	setvar VAR_0x8004, 0x12
	return

LilycoveCity_ContestLobby_EventScript_SetLinkGroupToughContest:: @ 0x08207260
	setvar VAR_0x8004, 0x13
	return

LilycoveCity_ContestLobby_EventScript_DecideLinkLeader:: @ 0x08207266
	message LilycoveCity_ContestLobby_Text_PleaseDecideLinkLeader
	waitmessage
	multichoice 0x10, 0x6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_TryJoinGroup
	case 1, LilycoveCity_ContestLobby_EventScript_TryLeadGroup
	case 2, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	case MULTI_B_PRESSED, LilycoveCity_ContestLobby_EventScript_CancelLinkContest
	end

LilycoveCity_ContestLobby_EventScript_TryLeadGroup:: @ 0x082072A3
	call LilycoveCity_ContestLobby_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided
	goto_if_eq VAR_RESULT, LINKUP_FAILED, LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, LilycoveCity_ContestLobby_EventScript_TryLeadGroup
	release
	end

LilycoveCity_ContestLobby_EventScript_TryJoinGroup:: @ 0x082072CB
	call LilycoveCity_ContestLobby_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided
	goto_if_eq VAR_RESULT, LINKUP_FAILED, LilycoveCity_ContestLobby_EventScript_DecideLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, LilycoveCity_ContestLobby_EventScript_TryJoinGroup
	release
	end

LilycoveCity_ContestLobby_EventScript_TryBecomeLinkLeader:: @ 0x082072F3
	special TryBecomeLinkLeader
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_TryJoinLinkGroup:: @ 0x082072F8
	special TryJoinLinkGroup
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_LinkLeaderDecided:: @ 0x082072FD
	messageinstant LilycoveCity_ContestLobby_Text_Transmitting
	contestlinktransfer
	goto LilycoveCity_ContestLobby_EventScript_StartLinkContest
	end

LilycoveCity_ContestLobby_EventScript_LeadToLinkContestHall:: @ 0x08207309
	messageautoscroll LilycoveCity_ContestLobby_Text_ContestBeginShortly
	waitmessage
	delay 0x14
	closemessage
	applymovement LOCALID_CONTEST_LOBBY_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistApproachCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 0x11, 0x2, METATILE_Contest_WallShadow, TRUE
	setmetatile 0x11, 0x3, METATILE_Contest_FloorShadow, TRUE
	special DrawWholeMapView
	applymovement LOCALID_CONTEST_LOBBY_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistExitCounter
	waitmovement 0
	playse SE_BRIDGE_WALK
	setmetatile 0x11, 0x2, METATILE_Contest_CounterFlap_Top, TRUE
	setmetatile 0x11, 0x3, METATILE_Contest_CounterFlap_Bottom, TRUE
	special DrawWholeMapView
	delay 0x14
	applymovement LOCALID_CONTEST_LOBBY_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistFacePlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerApproachLinkReceptionist
	waitmovement 0
	messageautoscroll LilycoveCity_ContestLobby_Text_ComeThroughHere
	waitmessage
	delay 0x14
	closemessage
	call LilycoveCity_ContestLobby_EventScript_DelayIfContestWithRSPlayer
	applymovement LOCALID_CONTEST_LOBBY_LINK_RECEPTIONIST, LilycoveCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall
	applymovement LOCALID_PLAYER, LilycoveCity_ContestLobby_Movement_PlayerWalkToLinkContestHall
	waitmovement 0
	release
	return

LilycoveCity_ContestLobby_Movement_PlayerWalkToLinkContestHall:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

LilycoveCity_ContestLobby_Movement_PlayerApproachLinkReceptionist:
	walk_right
	step_end

LilycoveCity_ContestLobby_Movement_LinkReceptionistApproachCounter:
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

LilycoveCity_ContestLobby_Movement_LinkReceptionistExitCounter:
	walk_down
	walk_down
	walk_in_place_faster_up
	step_end

LilycoveCity_ContestLobby_Movement_LinkReceptionistWalkToContestHall:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

LilycoveCity_ContestLobby_Movement_LinkReceptionistFacePlayer:
	walk_in_place_faster_left
	step_end

LilycoveCity_ContestLobby_EventScript_LittleGirl:: @ 0x082073B1
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKEBLOCK_CASE, LilycoveCity_ContestLobby_EventScript_LittleGirlHaveCase
	msgbox LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_LittleGirlHaveCase:: @ 0x082073C6
	msgbox LilycoveCity_ContestLobby_Text_MakePokeblocksDifferentBerries, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_Text_LadyGaveMePokeblockCase: @ 0x082073D0
	.string "うわーい！\p"
	.string "うけつけの　おねえちゃんから\n"
	.string "ポロック　いれる　ケース　もらった！$"

LilycoveCity_ContestLobby_Text_MakePokeblocksDifferentBerries: @ 0x082073F8
	.string "ポロック　つくって　いれて！\p"
	.string "でね　ポロック　つくる　ときは\n"
	.string "みんなが　ちがう　きのみで\l"
	.string "つくらないと　ダメ　なんだよ！$"

LilycoveCity_ContestLobby_Text_YourPokemonSpurredMeToPaint: @ 0x08207435
	.string "ゆうしょう　おめでとう！\p"
	.string "さっそく　きねんに\n"
	.string "きみの　ポケモンの　えを\l"
	.string "かきあげたんだけど⋯⋯\p"
	.string "なんだか　きみの　ポケモンの　アピールが\n"
	.string "あまり　にも　すばらしくて\l"
	.string "いつもより　うまく　かけたんだ！\l"
	.string "ほらっ　これ！$"

LilycoveCity_ContestLobby_Text_ShouldITakePaintingToMuseum: @ 0x082074A1
	.string "どうかな？　じしんさく　なんだけど\n"
	.string "きにいったろ？\p"
	.string "これくらいの　でき　なら\n"
	.string "びじゅつかんに　かざられて　いても\l"
	.string "ふしぎじゃ　ないね！\p"
	.string "⋯⋯え　ほんとに　びじゅつかんで\n"
	.string "えを　さがして　いるって？\l"
	.string "じゃあ　これ　もっていって　みようかな？$"

LilycoveCity_ContestLobby_Text_IllTakePaintingToMuseum: @ 0x08207519
	.string "そ　そうか！\n"
	.string "じゃ　いますぐ　もっていって　みるよ\l"
	.string "タイトルも　つけて　おくからね！\p"
	.string "これが　きにいられて\n"
	.string "かざって　もらえて　いるか　どうか\l"
	.string "きみも　こんど　みに　いってね！\l"
	.string "じゃ　ありがとう！$"

LilycoveCity_ContestLobby_Text_TakeMementoOfPainting: @ 0x0820757C
	.string "⋯⋯あ　そうだ\p"
	.string "ポケモンを　かかせて　もらった　きねんに\n"
	.string "これを　うけとってよ！$"

LilycoveCity_ContestLobby_Text_ReceivedARibbon: @ 0x082075A5
	.string "{PLAYER}は　リボンを　もらった！$"

LilycoveCity_ContestLobby_Text_PutTheRibbonOnMon: @ 0x082075B4
	.string "{PLAYER}は　リボンを\n"
	.string "{STR_VAR_1}に　つけて　あげた！$"

LilycoveCity_ContestLobby_Text_OkaySeeYou: @ 0x082075CA
	.string "それじゃね！$"

LilycoveCity_ContestLobby_Text_TakeHomeButIdLikeToTakeToMuseum: @ 0x082075D1
	.string "うーん⋯⋯　じゃあ　これは\n"
	.string "ぼくが　もってかえると　するか⋯⋯\p"
	.string "でも　やっぱり　もっていきたいな⋯⋯\n"
	.string "いいだろ？$"

LilycoveCity_ContestLobby_Text_FineThatsTheWayItIs: @ 0x0820760A
	.string "そっか　しかたないね\n"
	.string "それじゃ　これは　ぼくの\l"
	.string "いえに　かざります\p"
	.string "つぎ　がんばると　するか⋯⋯\n"
	.string "じゃあな$"

LilycoveCity_ContestLobby_Text_MasterRankHereICome: @ 0x08207640
	.string "いっ　いよいよ\n"
	.string "マスターランクに　でるぞ⋯⋯\p"
	.string "おれの　ポケモンちゃんが\n"
	.string "このよで　いちばん\l"
	.string "かわいいって　ことを\l"
	.string "しょうめいする　ときが　きたんだ⋯⋯\l"
	.string "うへへへへ$"

LilycoveCity_ContestLobby_Text_WholeVarietyOfPokemonHere: @ 0x08207692
	.string "ここに　くれば\n"
	.string "ポケモンを　たくさん　みられるから\l"
	.string "さんぽコースに　してるの！$"

LilycoveCity_ContestLobby_Text_ContestFeastForEyes: @ 0x082076BA
	.string "いやあ　コンテストかいじょうに　くると\n"
	.string "かきがいの　ある　ポケモンが\l"
	.string "いっぱい　だね！$"

LilycoveCity_ContestLobby_Text_ToughContestIsExtreme: @ 0x082076E6
	.string "たくましさコンテストって\n"
	.string "さいこう　だよな！\p"
	.string "ちからづよい　アピール⋯⋯\n"
	.string "ほとばしる　あせ⋯⋯　たまらん！$"

LilycoveCity_ContestLobby_Text_LavishedCareOnMon: @ 0x0820771C
	.string "まいにち　だいじに　だいじに\n"
	.string "そだてあげた　わしの　ポケモン\l"
	.string "コンディションは　カンペキ！\l"
	.string "きょうは　かつぞおおおおおうう！$"

LilycoveCity_ContestLobby_Text_MadePokeblocksWithFamily: @ 0x0820775B
	.string "ママと　パパと　おねえちゃんと\n"
	.string "4にんで　ポロックを　つくったら\l"
	.string "すごく　いいやつが　できたんだ！\p"
	.string "きっと　おおぜいで　つくれば　つくるほど\n"
	.string "なめらかで　いい　ポロックが　できるんだよ！$"
