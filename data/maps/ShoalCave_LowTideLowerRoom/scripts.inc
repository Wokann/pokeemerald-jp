@ ShoalCave_LowTideLowerRoom scripts (JP map g24 m49 @ 0x0821A221)

ShoalCave_LowTideLowerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideLowerRoom_OnLoad
	.byte 0

ShoalCave_LowTideLowerRoom_OnLoad:: @ 0x0821A227
	call ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatiles
	end

ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatiles:: @ 0x0821A22D
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_4, ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatilesEnd
	setmetatile 18, 2, METATILE_Cave_ShoalCave_DirtPile_Large, TRUE
	return

ShoalCave_LowTideLowerRoom_EventScript_SetShoalItemMetatilesEnd:: @ 0x0821A240
	return

ShoalCave_LowTideLowerRoom_EventScript_ShoalSalt4:: @ 0x0821A241
	lockall
	goto_if_set FLAG_RECEIVED_SHOAL_SALT_4, ShoalCave_LowTideLowerRoom_EventScript_ReceivedShoalSalt
	giveitem ITEM_SHOAL_SALT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 18, 2, METATILE_Cave_ShoalCave_DirtPile_Small, FALSE
	special DrawWholeMapView
	setflag FLAG_RECEIVED_SHOAL_SALT_4
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_ReceivedShoalSalt:: @ 0x0821A273
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
	releaseall
	end

ShoalCave_LowTideLowerRoom_EventScript_BlackBelt:: @ 0x0821A27D
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FOCUS_BAND, ShoalCave_LowTideLowerRoom_EventScript_ReceivedFocusBand
	msgbox ShoalCave_LowTideLowerRoom_Text_CanOvercomeColdWithFocus, MSGBOX_DEFAULT
	giveitem ITEM_FOCUS_BAND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FOCUS_BAND
	release
	end

ShoalCave_LowTideLowerRoom_EventScript_ReceivedFocusBand:: @ 0x0821A2AC
	msgbox ShoalCave_LowTideLowerRoom_Text_EverythingStartsWithFocus, MSGBOX_DEFAULT
	release
	end

ShoalCave_LowTideLowerRoom_Text_CanOvercomeColdWithFocus: @ 0x0821A2B6
	.string "このあたりは　からだが　ひえきって\n"
	.string "しゅぎょう　するのも　ままならぬ⋯⋯\p"
	.string "だが　きあいが　あれば　だいじょうぶッ！\p"
	.string "おぬしも　この　きあいのハチマキで\n"
	.string "さむさに　たえてみせるのだッ！$"

ShoalCave_LowTideLowerRoom_Text_EverythingStartsWithFocus: @ 0x0821A312
	.string "なにごとも　きあい　なのだーッ！！$"
