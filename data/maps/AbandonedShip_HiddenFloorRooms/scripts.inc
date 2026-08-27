@ AbandonedShip_HiddenFloorRooms scripts (JP map g24 m66 @ 0x0821B5A3)

AbandonedShip_HiddenFloorRooms_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, AbandonedShip_HiddenFloorRooms_OnFrame
	.byte 0

AbandonedShip_HiddenFloorRooms_OnFrame:: @ 0x0821B5A9
	map_script_2 VAR_TEMP_1, 0, AbandonedShip_HiddenFloorRooms_EventScript_DoHiddenItemSparkle
	.2byte 0

AbandonedShip_HiddenFloorRooms_EventScript_DoHiddenItemSparkle:: @ 0x0821B5B3
	setvar VAR_TEMP_1, 1
	getplayerxy VAR_TEMP_2, VAR_TEMP_3
	setvar VAR_TEMP_4, 1
	call_if_eq VAR_TEMP_2, 21, AbandonedShip_HiddenFloorRooms_EventScript_InMiddleRoomColumn
	call_if_eq VAR_TEMP_2, 36, AbandonedShip_HiddenFloorRooms_EventScript_InRightRoomColumn
	call_if_eq VAR_TEMP_3, 2, AbandonedShip_HiddenFloorRooms_EventScript_InUpperRoomRow
	switch VAR_TEMP_4
	case 1, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm1
	case 2, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm2
	case 3, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm3
	case 4, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm4
	case 5, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm5
	case 6, AbandonedShip_HiddenFloorRooms_EventScript_EnterRm6
	end

AbandonedShip_HiddenFloorRooms_EventScript_InMiddleRoomColumn:: @ 0x0821B62B
	addvar VAR_TEMP_4, 1
	return

AbandonedShip_HiddenFloorRooms_EventScript_InRightRoomColumn:: @ 0x0821B631
	addvar VAR_TEMP_4, 2
	return

AbandonedShip_HiddenFloorRooms_EventScript_InUpperRoomRow:: @ 0x0821B637
	addvar VAR_TEMP_4, 3
	return

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm1:: @ 0x0821B63D
	delay 20
	dofieldeffectsparkle 10, 10, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom4Key
	call_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorRooms_EventScript_Rm4KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm2:: @ 0x0821B666
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm3:: @ 0x0821B667
	specialvar VAR_RESULT, FoundAbandonedShipRoom1Key
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_HiddenFloorRooms_EventScript_Rm3NoSparkle
	delay 20
	call_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorRooms_EventScript_Rm1KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_Rm3NoSparkle:: @ 0x0821B68C
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm4:: @ 0x0821B68D
	delay 20
	dofieldeffectsparkle 8, 5, 0
	dofieldeffectsparkle 11, 3, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom6Key
	call_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorRooms_EventScript_Rm6KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm5:: @ 0x0821B6C5
	delay 20
	dofieldeffectsparkle 16, 3, 0
	dofieldeffectsparkle 25, 2, 0
	dofieldeffectsparkle 24, 6, 0
	specialvar VAR_RESULT, FoundAbandonedShipRoom2Key
	call_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorRooms_EventScript_Rm2KeySparkle
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	end

AbandonedShip_HiddenFloorRooms_EventScript_EnterRm6:: @ 0x0821B70C
	end

AbandonedShip_HiddenFloorRooms_EventScript_Rm1KeySparkle:: @ 0x0821B70D
	dofieldeffectsparkle 42, 10, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm2KeySparkle:: @ 0x0821B71D
	dofieldeffectsparkle 20, 5, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm4KeySparkle:: @ 0x0821B72D
	dofieldeffectsparkle 1, 12, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Rm6KeySparkle:: @ 0x0821B73D
	dofieldeffectsparkle 1, 2, 0
	return

AbandonedShip_HiddenFloorRooms_EventScript_Trash:: @ 0x0821B74D
	lockall
	msgbox AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash: @ 0x0821B758
	.string "ひかっているだけの\n"
	.string "ただの　ゴミ　だった⋯⋯$"
