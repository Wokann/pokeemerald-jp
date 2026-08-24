@ SlateportCity scripts (JP map g0 m1 @ 0x081DBFD3)

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_EventScript_001DBFDE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_MapScriptTable_001DC084
	.byte 0

SlateportCity_EventScript_001DBFDE::
	setvar 0x40AA, 0x0
	call SlateportCity_EventScript_001DBFFF
	compare_var_to_value 0x4058, 0x1
	call_if 0x1, SlateportCity_EventScript_001DC00B
	compare_var_to_value 0x40D2, 0x1
	call_if 0x1, SlateportCity_EventScript_001DC059
	end

SlateportCity_EventScript_001DBFFF::
	setflag 0x877
	setvar 0x4086, 0x0
	setflag 0x323
	return

SlateportCity_EventScript_001DC00B::
	setobjectxyperm 0xB, 0x1C, 0xD
	setobjectxyperm 0x7, 0x19, 0xD
	setobjectxyperm 0x3, 0x19, 0xE
	setobjectxyperm 0x6, 0x1B, 0x10
	setobjectxyperm 0x8, 0x1C, 0x10
	setobjectxyperm 0x1, 0x1D, 0x10
	setobjectxyperm 0x2, 0x1F, 0xE
	setobjectmovementtype 0xB, 0x8
	setobjectmovementtype 0x7, 0x12
	setobjectmovementtype 0x3, 0x10
	setobjectmovementtype 0x6, 0x7
	setobjectmovementtype 0x8, 0x7
	setobjectmovementtype 0x1, 0x7
	setobjectmovementtype 0x2, 0x9
	return

SlateportCity_EventScript_001DC059::
	setflag 0x4000
	getplayerxy 0x8004, 0x8005
	compare_var_to_value 0x8004, 0x1E
	goto_if 0x1, SlateportCity_EventScript_001DC078
	setobjectxyperm 0x23, 0x17, 0x1B
	setobjectmovementtype 0x23, 0xA
	return

SlateportCity_EventScript_001DC078::
	setobjectxyperm 0x23, 0x16, 0x1B
	setobjectmovementtype 0x23, 0xA
	return

SlateportCity_MapScriptTable_001DC084::
	map_script_2 0x40D2, 0x1, SlateportCity_EventScript_001DC08E
	.2byte 0

SlateportCity_EventScript_001DC08E::
	lockall
	addobject 0x23
	applymovement 0xFF, 0x081DC11A
	applymovement 0x23, 0x081DC11E
	waitmovement 0x0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement 0x23, 0x08243627
	waitmovement 0x0
	delay 0x3C
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement 0x23, 0x0824362B
	waitmovement 0x0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 0x1E
	playfanfare 0x1CC
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 0x1E
	setflag 0xD7
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement 0x23, 0x081DC126
	waitmovement 0x0
	removeobject 0x23
	setobjectxyperm 0x23, 0xA, 0xC
	setobjectmovementtype 0x23, 0x8
	clearflag 0x4000
	setvar 0x40D2, 0x2
	addvar 0x40D1, 0x1
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1dc11a, 0x15
SlateportCity_EventScript_001DC12F::
	lock
	faceplayer
	message 0x081DC9BE
	waitmessage
	pokemart 0x081DC148
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1dc146, 0x12
SlateportCity_EventScript_001DC158::
	lock
	faceplayer
	bufferleadmonspeciesname 0x0
	loadword 0x0, 0x081DC9DA
	callstd 0x4
	specialvar 0x800D, LeadMonHasEffortRibbon
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, SlateportCity_EventScript_001DC1AC
	specialvar 0x800D, Special_AreLeadMonEVsMaxedOut
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, SlateportCity_EventScript_001DC1A2
	loadword 0x0, 0x081DC9E7
	callstd 0x4
	playfanfare 0x172
	message 0x081DCA12
	waitfanfare
	loadword 0x0, 0x081DCA24
	callstd 0x4
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_001DC1A2::
	loadword 0x0, 0x081DCA3D
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC1AC::
	loadword 0x0, 0x081DCA67
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC1B6::
	lock
	faceplayer
	compare_var_to_value 0x4058, 0x1
	call_if 0x1, SlateportCity_EventScript_001DC1CD
	loadword 0x0, 0x081DCABE
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC1CD::
	loadword 0x0, 0x081DD13B
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC1D7::
	lock
	faceplayer
	compare_var_to_value 0x4058, 0x1
	call_if 0x1, SlateportCity_EventScript_001DC1EE
	loadword 0x0, 0x081DCAF7
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC1EE::
	loadword 0x0, 0x081DD082
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC1F8::
	lock
	faceplayer
	compare_var_to_value 0x4058, 0x1
	call_if 0x1, SlateportCity_EventScript_001DC218
	checkflag 0x60
	goto_if 0x1, SlateportCity_EventScript_001DC222
	loadword 0x0, 0x081DCB43
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC218::
	loadword 0x0, 0x081DD0C6
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC222::
	loadword 0x0, 0x081DCB73
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC22C::
	lock
	faceplayer
	compare_var_to_value 0x4058, 0x1
	call_if 0x1, SlateportCity_EventScript_001DC243
	loadword 0x0, 0x081DCBCA
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC243::
	loadword 0x0, 0x081DD106
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC24D::
	compare_var_to_value 0x4058, 0x1
	goto_if 0x1, SlateportCity_EventScript_001DC261
	loadword 0x0, 0x081DCC04
	callstd 0x2
	end

SlateportCity_EventScript_001DC261::
	loadword 0x0, 0x081DD166
	callstd 0x3
	end

SlateportCity_EventScript_001DC26A::
	lock
	faceplayer
	compare_var_to_value 0x4058, 0x1
	call_if 0x1, SlateportCity_EventScript_001DC281
	loadword 0x0, 0x081DCC5B
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC281::
	loadword 0x0, 0x081DD185
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC28B::
	lock
	faceplayer
	checkflag 0x94
	goto_if 0x1, SlateportCity_EventScript_001DC2A0
	loadword 0x0, 0x081DCCE4
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC2A0::
	loadword 0x0, 0x081DCCF6
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC2AA::
	loadword 0x0, 0x081DD3F8
	callstd 0x3
	end

SlateportCity_EventScript_001DC2B3::
	lockall
	checkflag 0x864
	goto_if 0x1, SlateportCity_EventScript_001DC2DA
	checkflag 0x86D
	goto_if 0x1, SlateportCity_EventScript_001DC2D0
	loadword 0x0, 0x081DD41C
	callstd 0x4
	releaseall
	end

SlateportCity_EventScript_001DC2D0::
	loadword 0x0, 0x081DD44A
	callstd 0x4
	releaseall
	end

SlateportCity_EventScript_001DC2DA::
	loadword 0x0, 0x081DD487
	callstd 0x4
	releaseall
	end

SlateportCity_EventScript_001DC2E4::
	loadword 0x0, 0x081DD4CC
	callstd 0x3
	end

SlateportCity_EventScript_001DC2ED::
	loadword 0x0, 0x081DD4F1
	callstd 0x3
	end

SlateportCity_EventScript_001DC2F6::
	loadword 0x0, 0x081DD51D
	callstd 0x3
	end

SlateportCity_EventScript_001DC2FF::
	loadword 0x0, 0x081DD53C
	callstd 0x3
	end

SlateportCity_EventScript_001DC308::
	lockall
	checkflag 0x864
	goto_if 0x1, SlateportCity_EventScript_001DC31C
	loadword 0x0, 0x081DD55A
	callstd 0x4
	releaseall
	end

SlateportCity_EventScript_001DC31C::
	loadword 0x0, 0x081DD5A1
	callstd 0x4
	releaseall
	end

SlateportCity_EventScript_001DC326::
	loadword 0x0, 0x081DD5D6
	callstd 0x3
	end

SlateportCity_EventScript_001DC32F::
	lock
	faceplayer
	compare_var_to_value 0x4058, 0x1
	call_if 0x1, SlateportCity_EventScript_001DC346
	loadword 0x0, 0x081DCFCB
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC346::
	loadword 0x0, 0x081DCFCB
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC350::
	loadword 0x0, 0x081DCFF4
	callstd 0x2
	end

SlateportCity_EventScript_001DC359::
	loadword 0x0, 0x081DCF33
	callstd 0x2
	end

SlateportCity_EventScript_001DC362::
	loadword 0x0, 0x081DCF68
	callstd 0x2
	end

SlateportCity_EventScript_001DC36B::
	loadword 0x0, 0x081DCFAA
	callstd 0x2
	end

SlateportCity_EventScript_001DC374::
	loadword 0x0, 0x081DD037
	callstd 0x2
	end

SlateportCity_EventScript_001DC37D::
	lock
	faceplayer
	loadword 0x0, 0x081DCD3C
	callstd 0x4
	closemessage
	applymovement 0x5, 0x08243625
	waitmovement 0x0
	release
	end

SlateportCity_EventScript_001DC394::
	lock
	faceplayer
	loadword 0x0, 0x081DCD5B
	callstd 0x4
	closemessage
	applymovement 0x12, 0x08243625
	waitmovement 0x0
	release
	end

SlateportCity_EventScript_001DC3AB::
	lock
	faceplayer
	loadword 0x0, 0x081DCD8E
	callstd 0x4
	closemessage
	applymovement 0x13, 0x08243625
	waitmovement 0x0
	release
	end

SlateportCity_EventScript_001DC3C2::
	lock
	faceplayer
	loadword 0x0, 0x081DCDBF
	callstd 0x4
	closemessage
	applymovement 0x1A, 0x08243625
	waitmovement 0x0
	release
	end

SlateportCity_EventScript_001DC3D9::
	lock
	faceplayer
	loadword 0x0, 0x081DCDF2
	callstd 0x4
	closemessage
	applymovement 0x1B, 0x08243625
	waitmovement 0x0
	release
	end

SlateportCity_EventScript_001DC3F0::
	lock
	faceplayer
	loadword 0x0, 0x081DCE19
	callstd 0x4
	closemessage
	applymovement 0x1C, 0x08243625
	waitmovement 0x0
	release
	end

SlateportCity_EventScript_001DC407::
	lock
	faceplayer
	loadword 0x0, 0x081DCE2D
	callstd 0x4
	closemessage
	applymovement 0x1D, 0x08243625
	waitmovement 0x0
	release
	end

SlateportCity_EventScript_001DC41E::
	lock
	faceplayer
	loadword 0x0, 0x081DCE55
	callstd 0x4
	closemessage
	applymovement 0x1E, 0x08243625
	waitmovement 0x0
	release
	end

SlateportCity_EventScript_001DC435::
	lock
	faceplayer
	playse 0x15
	applymovement 0x1F, 0x0824361B
	waitmovement 0x0
	applymovement 0x1F, 0x0824361D
	waitmovement 0x0
	loadword 0x0, 0x081DCE75
	callstd 0x4
	closemessage
	applymovement 0x1F, 0x08243625
	waitmovement 0x0
	applymovement 0x1F, 0x081DC4BB
	waitmovement 0x0
	applymovement 0x1F, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x081DCE7F
	callstd 0x4
	closemessage
	applymovement 0x1F, 0x08243625
	waitmovement 0x0
	applymovement 0x1F, 0x081DC4BB
	waitmovement 0x0
	loadword 0x0, 0x081DCEA7
	callstd 0x4
	closemessage
	applymovement 0x1F, 0x08243621
	waitmovement 0x0
	applymovement 0x1F, 0x081DC4BB
	waitmovement 0x0
	applymovement 0x1F, 0x08243625
	waitmovement 0x0
	release
	end

	.incbin "baserom_jp.gba", 0x1dc4bb, 0x3
SlateportCity_EventScript_001DC4BE::
	loadword 0x0, 0x081DCECA
	callstd 0x3
	end

SlateportCity_EventScript_001DC4C7::
	lock
	faceplayer
	loadword 0x0, 0x081DCEF9
	callstd 0x4
	closemessage
	applymovement 0x21, 0x08243625
	waitmovement 0x0
	release
	end

SlateportCity_EventScript_001DC4DE::
	lock
	faceplayer
	message 0x0824390F
	waitmessage
	pokemartdecoration 0x081DC4F8
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1dc4f5, 0xd
SlateportCity_EventScript_001DC502::
	loadword 0x0, 0x08243B96
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC50C::
	lock
	faceplayer
	checkflag 0x60
	goto_if 0x0, SlateportCity_EventScript_001DC502
	message 0x0824390F
	waitmessage
	pokemartdecoration 0x081DC52C
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1dc52c, 0x20
SlateportCity_EventScript_001DC54C::
	lock
	faceplayer
	message 0x0824390F
	waitmessage
	pokemart 0x081DC564
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1dc563, 0x9
SlateportCity_EventScript_001DC56C::
	lockall
	loadword 0x0, 0x081DD1E8
	callstd 0x4
	loadword 0x0, 0x081DD20D
	callstd 0x4
	closemessage
	applymovement 0xA, 0x0824362B
	waitmovement 0x0
	delay 0xA
	applymovement 0x9, 0x0824362D
	waitmovement 0x0
	delay 0x19
	applymovement 0xB, 0x081DC6B0
	applymovement 0xFF, 0x081DC6BE
	applymovement 0xA, 0x081DC68D
	applymovement 0x9, 0x081DC69A
	waitmovement 0x0
	removeobject 0xA
	removeobject 0x9
	loadword 0x0, 0x081DD26B
	callstd 0x4
	applymovement 0xB, 0x08243629
	waitmovement 0x0
	loadword 0x0, 0x081DD29D
	callstd 0x4
	playbgm 0x1A3, 0x0
	loadword 0x0, 0x081DD316
	callstd 0x4
	applymovement 0x6, 0x08243627
	applymovement 0x1, 0x08243627
	applymovement 0x7, 0x081DC67D
	applymovement 0x3, 0x08243619
	applymovement 0x2, 0x081DC685
	waitmovement 0x0
	applymovement 0xB, 0x0824362D
	waitmovement 0x0
	loadword 0x0, 0x081DD395
	callstd 0x4
	playse 0x15
	applymovement 0xB, 0x0824361B
	waitmovement 0x0
	applymovement 0xB, 0x0824361D
	waitmovement 0x0
	applymovement 0xB, 0x08243629
	waitmovement 0x0
	loadword 0x0, 0x081DD3C8
	callstd 0x4
	loadword 0x0, 0x081DD3E6
	callstd 0x4
	closemessage
	applymovement 0xB, 0x081DC6AB
	applymovement 0xFF, 0x081DC6B8
	waitmovement 0x0
	removeobject 0xB
	clearflag 0x349
	clearflag 0x350
	clearflag 0x34D
	clearflag 0x34E
	setvar 0x4058, 0x2
	warp 0x909, 0xFF, 0xB, 0xE
	waitstate
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1dc67d, 0x4a
SlateportCity_EventScript_001DC6C7::
	loadword 0x0, 0x081DD1AB
	callstd 0x3
	end

SlateportCity_EventScript_001DC6D0::
	loadword 0x0, 0x081DD1C1
	callstd 0x3
	end

SlateportCity_EventScript_001DC6D9::
	loadword 0x0, 0x081DCA81
	callstd 0x2
	end

SlateportCity_EventScript_001DC6E2::
	lock
	faceplayer
	checkflag 0x151
	goto_if 0x1, SlateportCity_EventScript_001DC70E
	loadword 0x0, 0x081DD5F9
	callstd 0x4
	setorcopyvar 0x8000, 0x174
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	setflag 0x151
	loadword 0x0, 0x081DD69F
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC70E::
	setvar 0x8004, 0x1
	specialvar 0x800D, HasEnoughBerryPowder
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_EventScript_001DC734
	loadword 0x0, 0x081DD723
	callstd 0x4
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_001DC73E
	end

SlateportCity_EventScript_001DC734::
	loadword 0x0, 0x081DD69F
	callstd 0x4
	release
	end

SlateportCity_EventScript_001DC73E::
	message 0x081DD734
	waitmessage
	setvar 0x8004, 0x7
	special sub_0813A164
	waitstate
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, SlateportCity_EventScript_001DC7E2
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, SlateportCity_EventScript_001DC7F6
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, SlateportCity_EventScript_001DC80A
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, SlateportCity_EventScript_001DC81E
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, SlateportCity_EventScript_001DC832
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, SlateportCity_EventScript_001DC846
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, SlateportCity_EventScript_001DC85A
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, SlateportCity_EventScript_001DC86E
	compare_var_to_value 0x8000, 0x8
	goto_if 0x1, SlateportCity_EventScript_001DC882
	compare_var_to_value 0x8000, 0x9
	goto_if 0x1, SlateportCity_EventScript_001DC896
	compare_var_to_value 0x8000, 0xA
	goto_if 0x1, SlateportCity_EventScript_001DC8AA
	compare_var_to_value 0x8000, 0xB
	goto_if 0x1, SlateportCity_EventScript_001DC8BE
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, SlateportCity_EventScript_001DC8BE
	end

SlateportCity_EventScript_001DC7E2::
	bufferitemname 0x0, 0x1E
	setvar 0x8008, 0x1E
	setvar 0x8009, 0x32
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC7F6::
	bufferitemname 0x0, 0x1F
	setvar 0x8008, 0x1F
	setvar 0x8009, 0x50
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC80A::
	bufferitemname 0x0, 0x20
	setvar 0x8008, 0x20
	setvar 0x8009, 0x32
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC81E::
	bufferitemname 0x0, 0x21
	setvar 0x8008, 0x21
	setvar 0x8009, 0x12C
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC832::
	bufferitemname 0x0, 0x40
	setvar 0x8008, 0x40
	setvar 0x8009, 0x3E8
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC846::
	bufferitemname 0x0, 0x41
	setvar 0x8008, 0x41
	setvar 0x8009, 0x3E8
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC85A::
	bufferitemname 0x0, 0x42
	setvar 0x8008, 0x42
	setvar 0x8009, 0x3E8
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC86E::
	bufferitemname 0x0, 0x43
	setvar 0x8008, 0x43
	setvar 0x8009, 0x3E8
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC882::
	bufferitemname 0x0, 0x46
	setvar 0x8008, 0x46
	setvar 0x8009, 0x3E8
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC896::
	bufferitemname 0x0, 0x3F
	setvar 0x8008, 0x3F
	setvar 0x8009, 0x3E8
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC8AA::
	bufferitemname 0x0, 0x45
	setvar 0x8008, 0x45
	setvar 0x8009, 0xBB8
	goto SlateportCity_EventScript_001DC8CB
	end

SlateportCity_EventScript_001DC8BE::
	loadword 0x0, 0x081DD7BB
	callstd 0x4
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_001DC8CB::
	loadword 0x0, 0x081DD743
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_EventScript_001DC73E
	copyvar 0x8004, 0x8009
	specialvar 0x800D, HasEnoughBerryPowder
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_EventScript_001DC942
	setorcopyvar 0x8000, 0x8008
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_EventScript_001DC935
	copyvar 0x8004, 0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	loadword 0x0, 0x081DD769
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SlateportCity_EventScript_001DC73E
	loadword 0x0, 0x081DD7A5
	callstd 0x4
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_001DC935::
	loadword 0x0, 0x08243947
	callstd 0x4
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_001DC942::
	loadword 0x0, 0x081DD753
	callstd 0x4
	goto SlateportCity_EventScript_001DC73E
	end

SlateportCity_EventScript_001DC950::
	lockall
	applymovement 0xFF, 0x08243635
	waitmovement 0x0
	opendoor 0xA, 0xC
	waitmoncry
	addobject 0x23
	applymovement 0xFF, 0x081DC9A4
	applymovement 0x23, 0x081DC9AB
	waitmovement 0x0
	closedoor 0xA, 0xC
	waitmoncry
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement 0xFF, 0x081DC9A8
	applymovement 0x23, 0x081DC9AE
	waitmovement 0x0
	removeobject 0x23
	addvar 0x40D1, 0x1
	setvar 0x40D2, 0x3
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1dc9a4, 0x13
SlateportCity_EventScript_001DC9B7::
	lockall
	special sub_08022230
	waitstate
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1dc9be, 0xe37
SlateportCity_Text_YouDroveTeamAquaAway: @ 0x081DD7F5
	.string "エニシダ“⋯⋯あれ？\n"
	.string "きみとは　まえに　どこかで　あったよね\p"
	.string "じこしょうかい　したっけ？\n"
	.string "わたしは　エニシダ　って　いうんだ\p"
	.string "いま　ここから　アクアだんが\n"
	.string "にげだして　いったけど\l"
	.string "もしかして　きみが　やっつけたの　かい？$"

SlateportCity_Text_MaybeThisTrainer: @ 0x081DD864
	.string "エニシダ“うーむ　これは\n"
	.string "ひょっとして　ひょっとすると⋯⋯$"

SlateportCity_Text_LetsRegisterEachOther: @ 0x081DD882
	.string "エニシダ“⋯⋯よっし！\n"
	.string "きみとは　なかよく　なれそう　だから\l"
	.string "おたがい　ポケナビに\l"
	.string "なまえを　とうろく　しておこう！\p"
	.string "⋯⋯　⋯⋯　⋯⋯$"

SlateportCity_Text_RegisteredScott: @ 0x081DD8C6
	.string "エニシダ　という　ひとを\n"
	.string "ポケナビに　とうろく　した！$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou: @ 0x081DD8E2
	.string "エニシダ“ホントは　きみに\n"
	.string "くっついて　いきたい　ところ　だけど\l"
	.string "ほかのひとの　さいのうも　きになるし\p"
	.string "もうすこし　いろんな　まちを\n"
	.string "たずね　あるいて　みるよ！\p"
	.string "じゃあね　{PLAYER}{KUN}！$"

SlateportCity_Text_TakingBattleTentChallenge: @ 0x081DD93E
	.string "エニシダ“お　おおっと\n"
	.string "{PLAYER}{KUN}か！\p"
	.string "⋯⋯もしかして　{PLAYER}{KUN}\n"
	.string "バトルテントに　ちょうせん　するのかい？\p"
	.string "うん！　それは　いいことだな！\n"
	.string "ものすごく　いいことだ！\l"
	.string "バトルテントには　つよい　トレーナーが\l"
	.string "とっても　ふさわしい　からね\p"
	.string "じゃ　がんばってね！$"
