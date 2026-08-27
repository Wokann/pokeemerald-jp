@ ShoalCave_LowTideStairsRoom scripts (JP map g24 m48 @ 0x0821A1C5)

ShoalCave_LowTideStairsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideStairsRoom_OnLoad
	.byte 0

ShoalCave_LowTideStairsRoom_OnLoad:: @ 0x0821A1CB
	call ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatiles
	end

ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatiles:: @ 0x0821A1D1
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_3, ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatilesEnd
	setmetatile 11, 11, METATILE_Cave_ShoalCave_DirtPile_Large, TRUE
	return

ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatilesEnd:: @ 0x0821A1E4
	return

ShoalCave_LowTideStairsRoom_EventScript_ShoalSalt3:: @ 0x0821A1E5
	lockall
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_3, ShoalCave_LowTideStairsRoom_EventScript_ReceivedShoalSalt
	giveitem ITEM_SHOAL_SALT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 11, 11, METATILE_Cave_ShoalCave_DirtPile_Small, FALSE
	special DrawWholeMapView
	setflag FLAG_RECEIVED_SHOAL_SALT_3
	releaseall
	end

ShoalCave_LowTideStairsRoom_EventScript_ReceivedShoalSalt:: @ 0x0821A217
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
	releaseall
	end
