@ MossdeepCity_SpaceCenter_2F scripts (JP map g14 m10 @ 0x0820D682)

MossdeepCity_SpaceCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_SpaceCenter_2F_EventScript_0020D68D
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_SpaceCenter_2F_MapScriptTable_0020D6DF
	.byte 0

MossdeepCity_SpaceCenter_2F_EventScript_0020D68D::
	compare_var_to_value 0x405D, 0x2
	call_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D6A4
	compare_var_to_value 0x409F, 0x2
	call_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D6C9
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D6A4::
	clearflag 0xCD
	setobjectxyperm 0x3, 0x5, 0x3
	setobjectmovementtype 0x3, 0xA
	setobjectxyperm 0x1, 0x3, 0x2
	setobjectmovementtype 0x1, 0xA
	setobjectxyperm 0x2, 0x1, 0x3
	setobjectmovementtype 0x2, 0xA
	return

MossdeepCity_SpaceCenter_2F_EventScript_0020D6C9::
	setobjectxyperm 0x5, 0xB, 0x2
	setobjectxyperm 0x7, 0xF, 0x2
	setobjectxyperm 0x6, 0xD, 0x4
	return

MossdeepCity_SpaceCenter_2F_MapScriptTable_0020D6DF::
	map_script_2 0x409F, 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D6E9
	.2byte 0

MossdeepCity_SpaceCenter_2F_EventScript_0020D6E9::
	playse 0x15
	applymovement 0xFF, 0x0824361B
	waitmovement 0x0
	applymovement 0xFF, 0x0824361D
	waitmovement 0x0
	loadword 0x0, gJPText_0020DBEC
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x0820D733
	loadword 0x0, gJPText_0020DC12
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x0820D731
	waitmovement 0x0
	warp 0xE09, 0xFF, 0xD, 0x1
	waitstate
	releaseall
	end

	.incbin "baserom_jp.gba", 0x20d731, 0x86
MossdeepCity_SpaceCenter_2F_EventScript_0020D7B7::
	lock
	faceplayer
	checkflag 0x864
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D7DE
	compare_var_to_value 0x405D, 0x2
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D7E8
	compare_var_to_value 0x405D, 0x2
	goto_if 0x0, MossdeepCity_SpaceCenter_2F_EventScript_0020D7DE
	goto MossdeepCity_SpaceCenter_2F_EventScript_0020D7E8
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D7DE::
	loadword 0x0, 0x0820DACB
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D7E8::
	loadword 0x0, 0x0820DB12
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D7F2::
	lock
	faceplayer
	checkflag 0x864
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D819
	compare_var_to_value 0x405D, 0x2
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D823
	compare_var_to_value 0x405D, 0x2
	goto_if 0x0, MossdeepCity_SpaceCenter_2F_EventScript_0020D819
	goto MossdeepCity_SpaceCenter_2F_EventScript_0020D823
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D819::
	loadword 0x0, 0x0820DB39
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D823::
	loadword 0x0, 0x0820DB7B
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D82D::
	lock
	faceplayer
	checkflag 0x864
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D854
	compare_var_to_value 0x405D, 0x2
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D85E
	compare_var_to_value 0x405D, 0x2
	goto_if 0x0, MossdeepCity_SpaceCenter_2F_EventScript_0020D854
	goto MossdeepCity_SpaceCenter_2F_EventScript_0020D85E
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D854::
	loadword 0x0, 0x0820DBB3
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D85E::
	loadword 0x0, 0x0820DBD3
	callstd 0x4
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D868::
	loadword 0x0, 0x0820DCB7
	callstd 0x2
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D871::
	loadword 0x0, 0x0820DCC6
	callstd 0x2
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D87A::
	loadword 0x0, 0x0820DCE5
	callstd 0x2
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D883::
	lock
	faceplayer
	loadword 0x0, 0x0820DCFF
	callstd 0x4
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D899::
	lockall
	loadword 0x0, 0x0820DD52
	callstd 0x4
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D8A4::
	lockall
	checkflag 0xCD
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D904
	setflag 0xCD
	loadword 0x0, 0x0820DD76
	callstd 0x4
	loadword 0x0, 0x0820DDA9
	callstd 0x4
	closemessage
	delay 0x1E
	playse 0xC
	copyvar 0x8000, 0x800C
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D8E4
	applymovement 0x4, 0x0820D8F0
	waitmovement 0x0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D8E4::
	applymovement 0x4, 0x0820D8F9
	waitmovement 0x0
	releaseall
	end

	.incbin "baserom_jp.gba", 0x20d8f0, 0x14
MossdeepCity_SpaceCenter_2F_EventScript_0020D904::
	applymovement 0x800F, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x0820DE3B
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D936
	loadword 0x0, 0x0820DE73
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x0824362D
	waitmovement 0x0
	releaseall
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020D936::
	applymovement 0x800F, 0x0824362D
	waitmovement 0x0
	special SavePlayerParty
	fadescreen 0x1
	special ChooseHalfPartyForBattle
	compare_var_to_value 0x800D, 0x0
	goto_if 0x5, MossdeepCity_SpaceCenter_2F_EventScript_0020D95C
	special LoadPlayerParty
	goto MossdeepCity_SpaceCenter_2F_EventScript_0020D904

MossdeepCity_SpaceCenter_2F_EventScript_0020D95C::
	special ReducePlayerPartyToSelectedMons
	setvar 0x8004, 0x2
	setvar 0x8005, 0x4
	special CallFrontierUtilFunc
	setvar 0x8004, 0x8
	setvar 0x8005, 0x0
	special DoSpecialTrainerBattle
	setvar 0x8004, 0x6
	special CallFrontierUtilFunc
	special LoadPlayerParty
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020D99B
	fadescreen 0x1
	special SetCB2WhiteOut
	waitstate

MossdeepCity_SpaceCenter_2F_EventScript_0020D99B::
	loadword 0x0, 0x0820DEBB
	callstd 0x4
	closemessage
	delay 0x14
	applymovement 0x9, 0x08243627
	applymovement 0x8, 0x0824362D
	waitmovement 0x0
	delay 0x3C
	applymovement 0x9, 0x08243629
	applymovement 0x8, 0x0824362B
	waitmovement 0x0
	delay 0x14
	loadword 0x0, 0x0820DF75
	callstd 0x4
	closemessage
	setvar 0x405D, 0x3
	fadedefaultbgm
	fadescreen 0x1
	setvar 0x409F, 0x3
	setflag 0x2F4
	setflag 0x35E
	setflag 0x337
	removeobject 0x5
	removeobject 0x7
	removeobject 0x6
	removeobject 0x8
	removeobject 0x9
	setobjectxy 0x3, 0x5, 0x6
	turnobject 0x3, 0x1
	setobjectxy 0x2, 0xB, 0x8
	turnobject 0x2, 0x2
	setobjectxy 0x1, 0x6, 0x2
	turnobject 0x1, 0x2
	call MossdeepCity_SpaceCenter_2F_EventScript_0020DA5B
	fadescreen 0x0
	loadword 0x0, 0x0820DFB6
	callstd 0x4
	closemessage
	fadescreen 0x1
	setflag 0x75
	setflag 0x3C7
	removeobject 0x4
	setflag 0x2E1
	clearflag 0x3C7
	setvar 0x40C6, 0x1
	setflag 0x314
	removeobject 0x3
	setobjectxyperm 0x3, 0x5, 0x6
	setobjectmovementtype 0x3, 0x2
	addobject 0x3
	fadescreen 0x0
	end

MossdeepCity_SpaceCenter_2F_EventScript_0020DA5B::
	copyvar 0x8000, 0x800C
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020DA77
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, MossdeepCity_SpaceCenter_2F_EventScript_0020DA7C
	return

MossdeepCity_SpaceCenter_2F_EventScript_0020DA77::
	turnobject 0x4, 0x2
	return

MossdeepCity_SpaceCenter_2F_EventScript_0020DA7C::
	turnobject 0x4, 0x4
	return

	.incbin "baserom_jp.gba", 0x20da81, 0x16b
	.globl gJPText_0020DBEC
gJPText_0020DBEC: @ 0x0820DBEC
	.string "なんだ　おまえ！\p"
	.string "おれたち　3にんに　かこまれてるのに\n"
	.string "やろうってのか！？$"

	.globl gJPText_0020DC12
gJPText_0020DC12: @ 0x0820DC12
	.string "だよな！\n"
	.string "そのほうが　おりこうさん　だぜ！$"
