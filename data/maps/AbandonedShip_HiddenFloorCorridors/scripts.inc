@ AbandonedShip_HiddenFloorCorridors scripts (JP map g24 m65 @ 0x0821B340)

AbandonedShip_HiddenFloorCorridors_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_HiddenFloorCorridors_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_HiddenFloorCorridors_OnLoad
	.byte 0

AbandonedShip_HiddenFloorCorridors_OnResume:: @ 0x0821B34B
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
	end

AbandonedShip_HiddenFloorCorridors_OnLoad:: @ 0x0821B354
	call_if_unset FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom1
	call_if_unset FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom2
	call_if_unset FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom4
	call_if_unset FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom6
	call_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1
	call_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2
	call_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4
	call_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6
	end

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1:: @ 0x0821B39D
	setmetatile 3, 8, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2:: @ 0x0821B3A7
	setmetatile 6, 8, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4:: @ 0x0821B3B1
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent_Unlocked, FALSE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6:: @ 0x0821B3BB
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent_Unlocked, FALSE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom1:: @ 0x0821B3C5
	setmetatile 3, 8, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom2:: @ 0x0821B3CF
	setmetatile 6, 8, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom4:: @ 0x0821B3D9
	setmetatile 3, 3, METATILE_InsideShip_DoorIndent_Locked, FALSE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_LockRoom6:: @ 0x0821B3E3
	setmetatile 9, 3, METATILE_InsideShip_DoorIndent_Locked, FALSE
	return

AbandonedShip_HiddenFloorCorridors_EventScript_Room1Door:: @ 0x0821B3ED
	lockall
	goto_if_set FLAG_USED_ROOM_1_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_1_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm1IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_1_KEY
	setflag FLAG_USED_ROOM_1_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom1
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Room2Door:: @ 0x0821B424
	lockall
	goto_if_set FLAG_USED_ROOM_2_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_2_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm2IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_2_KEY
	setflag FLAG_USED_ROOM_2_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom2
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Room4Door:: @ 0x0821B45B
	lockall
	goto_if_set FLAG_USED_ROOM_4_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_4_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm4IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_4_KEY
	setflag FLAG_USED_ROOM_4_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom4
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Room6Door:: @ 0x0821B492
	lockall
	goto_if_set FLAG_USED_ROOM_6_KEY, AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen
	checkitem ITEM_ROOM_6_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_HiddenFloorCorridors_EventScript_Rm6IsLocked
	msgbox AbandonedShip_HiddenFloorCorridors_Text_InsertedKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_ROOM_6_KEY
	setflag FLAG_USED_ROOM_6_KEY
	call AbandonedShip_HiddenFloorCorridors_EventScript_UnlockRoom6
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm1IsLocked:: @ 0x0821B4C9
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm1DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm2IsLocked:: @ 0x0821B4D3
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm2DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm4IsLocked:: @ 0x0821B4DD
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm4DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_Rm6IsLocked:: @ 0x0821B4E7
	msgbox AbandonedShip_HiddenFloorCorridors_Text_Rm6DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_EventScript_TheDoorIsOpen:: @ 0x0821B4F1
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorCorridors_Text_Rm1DoorIsLocked: @ 0x0821B4FB
	.string "カギが　かかっている\p"
	.string "とびらには　1ごうしつと　かかれている$"

AbandonedShip_HiddenFloorCorridors_Text_Rm2DoorIsLocked: @ 0x0821B51A
	.string "カギが　かかっている\p"
	.string "とびらには　2ごうしつと　かかれている$"

AbandonedShip_HiddenFloorCorridors_Text_Rm4DoorIsLocked: @ 0x0821B539
	.string "カギが　かかっている\p"
	.string "とびらには　4ごうしつと　かかれている$"

AbandonedShip_HiddenFloorCorridors_Text_Rm6DoorIsLocked: @ 0x0821B558
	.string "カギが　かかっている\p"
	.string "とびらには　6ごうしつと　かかれている$"

AbandonedShip_HiddenFloorCorridors_Text_InsertedKey: @ 0x0821B577
	.string "{PLAYER}は\n"
	.string "カギを　つかった！\p"
	.string "さしこんだ　カギは　ぬけなくなったが\n"
	.string "とびらは　ひらいた！$"
