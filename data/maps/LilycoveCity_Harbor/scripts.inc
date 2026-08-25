@ LilycoveCity_Harbor scripts (JP map g13 m10 @ 0x082094D4)

LilycoveCity_Harbor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_Harbor_OnTransition
	.byte 0

LilycoveCity_Harbor_OnTransition:: @ 0x082094DA
	setescapewarp MAP_LILYCOVE_CITY, 0xC, 0x21
	end

LilycoveCity_Harbor_EventScript_FerryAttendant:: @ 0x082094E3
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_FerryUnavailable
	call LilycoveCity_Harbor_EventScript_GetEonTicketState
	call LilycoveCity_Harbor_EventScript_GetAuroraTicketState
	call LilycoveCity_Harbor_EventScript_GetOldSeaMapState
	call LilycoveCity_Harbor_EventScript_GetMysticTicketState
	call LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket
	call LilycoveCity_Harbor_EventScript_GetHasTicketsState
	goto_if_eq VAR_TEMP_C, 0x2, LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime
	goto_if_eq VAR_TEMP_B, 0x1, LilycoveCity_Harbor_EventScript_EonTicketFirstTime
	goto_if_eq VAR_TEMP_B, 0x2, LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime
	goto_if_eq VAR_TEMP_B, 0x4, LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime
	goto_if_eq VAR_TEMP_B, 0x8, LilycoveCity_Harbor_EventScript_MysticTicketFirstTime
	goto_if_ne VAR_TEMP_B, 0x0, LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime
	goto LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets
	end

LilycoveCity_Harbor_EventScript_NoFirstTimeEventTickets:: @ 0x08209554
	goto_if_eq VAR_TEMP_A, 0x0, LilycoveCity_Harbor_EventScript_NoEventTickets
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect:: @ 0x08209573
	setvar VAR_0x8004, 0x0
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
	special GetLilycoveSSTidalSelection
	switch VAR_RESULT
	case 0, LilycoveCity_Harbor_EventScript_GoToSlateport
	case 1, LilycoveCity_Harbor_EventScript_GoToBattleFrontier
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIsland
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRock
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIsland
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIsland
	case 6, LilycoveCity_Harbor_EventScript_ExitSailSelect
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitSailSelect
	end

LilycoveCity_Harbor_EventScript_GoToSouthernIsland:: @ 0x082095DD
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 0xD, 0x16
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToNavelRock:: @ 0x082095ED
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_NAVEL_ROCK_HARBOR, 0x8, 0x4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToBirthIsland:: @ 0x082095FD
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BIRTH_ISLAND_HARBOR, 0x8, 0x4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToFarawayIsland:: @ 0x0820960D
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 0xD, 0x26
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToSlateport:: @ 0x0820961D
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 0x1, 0xA
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToBattleFrontier:: @ 0x08209645
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 0x13, 0x43
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GetEonTicketState:: @ 0x08209668
	setvar VAR_TEMP_E, 0x0
	goto_if_unset FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setvar VAR_TEMP_E, 0x1
	goto_if_set FLAG_SHOWN_EON_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_E, 0x2
	return

LilycoveCity_Harbor_EventScript_GetAuroraTicketState:: @ 0x0820969A
	setvar VAR_TEMP_D, 0x0
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setvar VAR_TEMP_D, 0x1
	goto_if_set FLAG_SHOWN_AURORA_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_D, 0x2
	return

LilycoveCity_Harbor_EventScript_GetOldSeaMapState:: @ 0x082096CC
	setvar VAR_TEMP_C, 0x0
	goto_if_unset FLAG_ENABLE_SHIP_FARAWAY_ISLAND, Common_EventScript_NopReturn
	checkitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 0x1
	goto_if_set FLAG_SHOWN_OLD_SEA_MAP, Common_EventScript_NopReturn
	setvar VAR_TEMP_C, 0x2
	return

LilycoveCity_Harbor_EventScript_GetMysticTicketState:: @ 0x082096FE
	setvar VAR_TEMP_9, 0x0
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, Common_EventScript_NopReturn
	checkitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setvar VAR_TEMP_9, 0x1
	goto_if_set FLAG_SHOWN_MYSTIC_TICKET, Common_EventScript_NopReturn
	setvar VAR_TEMP_9, 0x2
	return

LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket:: @ 0x08209730
	setvar VAR_TEMP_B, 0x0
	call_if_eq VAR_TEMP_E, 0x2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket
	call_if_eq VAR_TEMP_D, 0x2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket
	call_if_eq VAR_TEMP_C, 0x2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap
	call_if_eq VAR_TEMP_9, 0x2, LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingEonTicket:: @ 0x08209762
	addvar VAR_TEMP_B, 0x1
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingAuroraTicket:: @ 0x08209768
	addvar VAR_TEMP_B, 0x2
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingOldSeaMap:: @ 0x0820976E
	addvar VAR_TEMP_B, 0x4
	return

LilycoveCity_Harbor_EventScript_SetFirstTimeShowingMysticTicket:: @ 0x08209774
	addvar VAR_TEMP_B, 0x8
	return

LilycoveCity_Harbor_EventScript_GetHasTicketsState:: @ 0x0820977A
	setvar VAR_TEMP_A, 0x0
	call_if_eq VAR_TEMP_E, 0x1, LilycoveCity_Harbor_EventScript_SetHasEonTicket
	call_if_eq VAR_TEMP_D, 0x1, LilycoveCity_Harbor_EventScript_SetHasAuroraTicket
	call_if_eq VAR_TEMP_C, 0x1, LilycoveCity_Harbor_EventScript_SetHasOldSeaMap
	call_if_eq VAR_TEMP_9, 0x1, LilycoveCity_Harbor_EventScript_SetHasMysticTicket
	return

LilycoveCity_Harbor_EventScript_SetHasEonTicket:: @ 0x082097AC
	addvar VAR_TEMP_A, 0x1
	return

LilycoveCity_Harbor_EventScript_SetHasAuroraTicket:: @ 0x082097B2
	addvar VAR_TEMP_A, 0x2
	return

LilycoveCity_Harbor_EventScript_SetHasOldSeaMap:: @ 0x082097B8
	addvar VAR_TEMP_A, 0x4
	return

LilycoveCity_Harbor_EventScript_SetHasMysticTicket:: @ 0x082097BE
	addvar VAR_TEMP_A, 0x8
	return

LilycoveCity_Harbor_EventScript_EonTicketFirstTime:: @ 0x082097C4
	setflag FLAG_SHOWN_EON_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_ShowEonTicket, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime:: @ 0x082097E3
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 0xD, 0x16
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_AuroraTicketFirstTime:: @ 0x082097F4
	setflag FLAG_SHOWN_AURORA_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime:: @ 0x08209813
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_BIRTH_ISLAND_HARBOR, 0x8, 0x4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_OldSeaMapFirstTime:: @ 0x08209824
	setflag FLAG_SHOWN_OLD_SEA_MAP
	msgbox EventTicket_Text_ShowOldSeaMap, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OldSeaMapTooFar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast
	addobject LOCALID_LILYCOVE_HARBOR_BRINEY
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast
	msgbox EventTicket_Text_BrineyHoldOnASecond, MSGBOX_DEFAULT
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast
	msgbox EventTicket_Text_BrineyLetsSail, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast
	setvar VAR_0x8004, LOCALID_LILYCOVE_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 0xD, 0x26
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime:: @ 0x082098E0
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 0xD, 0x26
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_MysticTicketFirstTime:: @ 0x082098F1
	setflag FLAG_SHOWN_MYSTIC_TICKET
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	msgbox EventTicket_Text_OddTicketGetOnBoard, MSGBOX_DEFAULT
	goto LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
	end

LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime:: @ 0x08209910
	closemessage
	call LilycoveCity_Harbor_EventScript_BoardFerryWithSailor
	warp MAP_NAVEL_ROCK_HARBOR, 0x8, 0x4
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_MultipleEventTicketsFirstTime:: @ 0x08209921
	msgbox EventTicket_Text_ThatPass, MSGBOX_DEFAULT
	closemessage
	call LilycoveCity_Harbor_EventScript_GetEventTicketSailor
	message EventTicket_Text_OddTicketsWhereTo
	waitmessage
	setvar VAR_0x8004, 0x1
	special ScriptMenu_CreateLilycoveSSTidalMultichoice
	special GetLilycoveSSTidalSelection
	switch VAR_RESULT
	case 2, LilycoveCity_Harbor_EventScript_GoToSouthernIslandFirstTime
	case 3, LilycoveCity_Harbor_EventScript_GoToNavelRockFirstTime
	case 4, LilycoveCity_Harbor_EventScript_GoToBirthIslandFirstTime
	case 5, LilycoveCity_Harbor_EventScript_GoToFarawayIslandFirstTime
	case 6, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
	case MULTI_B_PRESSED, LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect
	release
	end

LilycoveCity_Harbor_EventScript_ExitFirstTimeTicketSailSelect:: @ 0x0820998A
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 0x1E
	removeobject LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR
	delay 0x1E
	applymovement LOCALID_LILYCOVE_HARBOR_ATTENDANT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	showobject_at LOCALID_LILYCOVE_HARBOR_ATTENDANT, MAP_LILYCOVE_CITY_HARBOR
	delay 0x1E
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_GetEventTicketSailor:: @ 0x082099C2
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 0x1E
	hideobject_at VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	delay 0x3C
	addobject LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR
	delay 0x1E
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_FacePlayer
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithSailor:: @ 0x082099E8
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 0x1E
	removeobject LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
	delay 0x1E
	hideobject_at LOCALID_PLAYER, 0x0
	setvar VAR_0x8004, LOCALID_LILYCOVE_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

LilycoveCity_Harbor_EventScript_FerryUnavailable:: @ 0x08209A21
	msgbox LilycoveCity_Harbor_Text_FerryUnavailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_NoEventTickets:: @ 0x08209A2B
	msgbox LilycoveCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	message LilycoveCity_Harbor_Text_FlashTicketWhereTo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

LilycoveCity_Harbor_EventScript_NoTicket:: @ 0x08209A3F
	msgbox LilycoveCity_Harbor_Text_NoTicket, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_GoToSlateportUnused:: @ 0x08209A49
	msgbox LilycoveCity_Harbor_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_LILYCOVE
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_SS_TIDAL_CORRIDOR, 0x1, 0xA
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_GoToBattleFrontierUnused:: @ 0x08209A71
	msgbox LilycoveCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 0x13, 0x43
	waitstate
	release
	end

LilycoveCity_Harbor_EventScript_FerryDestinationChangeMind:: @ 0x08209A94
	message LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo
	waitmessage
	goto LilycoveCity_Harbor_EventScript_FerryRegularLocationSelect
	end

LilycoveCity_Harbor_EventScript_BoardFerry:: @ 0x08209AA0
	msgbox LilycoveCity_Harbor_Text_PleaseBoard, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 0x1E
	hideobject_at VAR_LAST_TALKED, MAP_LILYCOVE_CITY_HARBOR
	call_if_eq VAR_FACING, DIR_NORTH, LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth
	call_if_eq VAR_FACING, DIR_EAST, LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast
	delay 0x1E
	hideobject_at LOCALID_PLAYER, 0x0
	setvar VAR_0x8004, LOCALID_LILYCOVE_HARBOR_SS_TIDAL
	call Common_EventScript_FerryDepart
	return

LilycoveCity_Harbor_EventScript_PlayerBoardFerryEast:: @ 0x08209AE4
	applymovement LOCALID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryEast
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_PlayerBoardFerryNorth:: @ 0x08209AEF
	applymovement LOCALID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_ExitSailSelect:: @ 0x08209AFA
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_Movement_PlayerBoardFerryEast:
	walk_right
	walk_in_place_faster_up
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardFerryNorth:
	walk_up
	step_end

LilycoveCity_Harbor_Movement_UnusedBoardFerry:
	walk_up
	step_end

LilycoveCity_Harbor_EventScript_Sailor:: @ 0x08209B0B
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_Harbor_EventScript_SailorFerryAvailable
	msgbox LilycoveCity_Harbor_Text_SailorFerryUnavailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_SailorFerryAvailable:: @ 0x08209B20
	msgbox LilycoveCity_Harbor_Text_SailorFerryAvailable, MSGBOX_DEFAULT
	release
	end

LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayNorth:: @ 0x08209B2A
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_MoveSailorOutOfWayEast:: @ 0x08209B35
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorOutOfWayEast
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_SailorOutOfWayNorth:
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_Harbor_Movement_SailorOutOfWayEast:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LilycoveCity_Harbor_EventScript_BrineyFaceSailorNorth:: @ 0x08209B49
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFaceSailorEast:: @ 0x08209B54
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFacePlayerNorth:: @ 0x08209B5F
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BrineyFacePlayerEast:: @ 0x08209B6A
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorNorth:: @ 0x08209B75
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
	applymovement LOCALID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth
	waitmovement 0
	return

LilycoveCity_Harbor_EventScript_BoardFerryWithBrineyAndSailorEast:: @ 0x08209B8E
	applymovement LOCALID_LILYCOVE_HARBOR_BRINEY, LilycoveCity_Harbor_Movement_BrineyBoardFerry
	applymovement LOCALID_PLAYER, LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast
	applymovement LOCALID_LILYCOVE_HARBOR_FERRY_SAILOR, LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast
	waitmovement 0
	return

LilycoveCity_Harbor_Movement_BrineyBoardFerry:
	walk_in_place_faster_up
	delay_8
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyNorth:
	delay_16
	walk_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_SailorBoardWithBrineyNorth:
	delay_16
	delay_16
	delay_16
	walk_right
	walk_in_place_faster_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_PlayerBoardWithBrineyEast:
	delay_16
	walk_right
	walk_in_place_faster_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Movement_SailorBoardWithBrineyEast:
	delay_16
	delay_16
	delay_16
	walk_up
	delay_16
	set_invisible
	step_end

LilycoveCity_Harbor_Text_FerryUnavailable: @ 0x08209BC5
	.string "えっ？　ふね　ですか？\p"
	.string "もうしわけ　ございません　げんざい\n"
	.string "れんらくせんは　ないんです⋯⋯$"

LilycoveCity_Harbor_Text_MayISeeYourTicket: @ 0x08209BF3
	.string "れんらくせんを　ごりよう　ですね！\n"
	.string "チケットは　おもち　でしょうか？$"

LilycoveCity_Harbor_Text_NoTicket: @ 0x08209C16
	.string "{PLAYER}は\n"
	.string "チケットを　もっていない！\p"
	.string "⋯⋯もうしわけ　ありません！\p"
	.string "ふねに　のれるのは\n"
	.string "チケットの　ある　かた　だけです$"

LilycoveCity_Harbor_Text_FlashTicketWhereTo: @ 0x08209C52
	.string "{PLAYER}は\n"
	.string "ふねのチケットを　みせた！\p"
	.string "はい！　けっこう　です！\p"
	.string "いきさきは　どちら　でしょう？$"

LilycoveCity_Harbor_Text_SailAnotherTime: @ 0x08209C81
	.string "また　ごりよう　ください！$"

LilycoveCity_Harbor_Text_SlateportItIs: @ 0x08209C8F
	.string "カイナシティ　ですね！$"

LilycoveCity_Harbor_Text_BattleFrontierItIs: @ 0x08209C9B
	.string "バトルフロンティア　ですね！$"

LilycoveCity_Harbor_Text_PleaseBoard: @ 0x08209CAA
	.string "れんらくせんに　のって　おまちください$"

LilycoveCity_Harbor_Text_WhereWouldYouLikeToGo: @ 0x08209CBE
	.string "いきさきは　どちら　でしょう？$"

LilycoveCity_Harbor_Text_SailorFerryUnavailable: @ 0x08209CCE
	.string "れんらくせんが　かんせい　しないと\n"
	.string "ふなのり　というものは　ヒマだぜ⋯⋯\p"
	.string "カイナの　ぞうせんじょの　れんちゅう\n"
	.string "しゃかりきに　がんばって　くれよな$"

LilycoveCity_Harbor_Text_SailorFerryAvailable: @ 0x08209D18
	.string "やっと　れんらくせん　タイドリップごうが\n"
	.string "うんこう　するように　なったんだ！\p"
	.string "カイナの　ぞうせんじょの　みんな\n"
	.string "たいへん　だったろうな\l"
	.string "これからは　おれが　いそがしくなるぞ！$"
