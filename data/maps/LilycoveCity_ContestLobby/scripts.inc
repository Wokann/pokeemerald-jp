@ LilycoveCity_ContestLobby scripts (JP map g13 m4 @ 0x082068D1)

LilycoveCity_ContestLobby_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_ContestLobby_EventScript_002068DC
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_ContestLobby_MapScriptTable_00206903
	.byte 0

LilycoveCity_ContestLobby_EventScript_002068DC::
	call 0x08253F43
	call LilycoveCity_ContestLobby_EventScript_002068E7
	end

LilycoveCity_ContestLobby_EventScript_002068E7::
	getpricereduction 0x4
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002068FC
	clearflag 0x369
	setflag 0x340
	return

LilycoveCity_ContestLobby_EventScript_002068FC::
	setflag 0x369
	clearflag 0x340
	return

LilycoveCity_ContestLobby_MapScriptTable_00206903::
	map_script_2 0x4099, 0x1, LilycoveCity_ContestLobby_EventScript_00206915
	map_script_2 0x4099, 0x2, LilycoveCity_ContestLobby_EventScript_00206AE7
	.2byte 0

LilycoveCity_ContestLobby_EventScript_00206915::
	checkflag 0x307
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206924
	setvar 0x4099, 0x0
	end

LilycoveCity_ContestLobby_EventScript_00206924::
	lockall
	addobject 0x4
	applymovement 0x4, 0x08206AC7
	waitmovement 0x4
	applymovement 0xFF, 0x08206AD8
	waitmovement 0x0
	loadword 0x0, gJPText_00207435
	callstd 0x4
	lockall
	fadescreen 0x1
	showcontestwinner 0x0
	lockall
	loadword 0x0, gJPText_002074A1
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020696A
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002069A4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_0020696A::
	loadword 0x0, gJPText_00207519
	callstd 0x4
	closemessage
	special sub_080F916C
	setvar 0x4099, 0x0
	specialvar 0x800D, GiveMonArtistRibbon
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LilycoveCity_ContestLobby_EventScript_002069D4
	applymovement 0x4, 0x08206ACF
	waitmovement 0x0
	removeobject 0x4
	call LilycoveCity_ContestLobby_EventScript_00206A20
	call LilycoveCity_ContestLobby_EventScript_00206A76
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_002069A4::
	loadword 0x0, gJPText_002075D1
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020696A
	loadword 0x0, gJPText_0020760A
	callstd 0x4
	closemessage
	applymovement 0x4, 0x08206ACF
	waitmovement 0x0
	setvar 0x4099, 0x0
	removeobject 0x4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_002069D4::
	incrementgamestat 0x2A
	special sub_080F8C14
	applymovement 0x4, 0x08206ADA
	waitmovement 0x0
	playse 0x15
	applymovement 0x4, 0x0824361B
	waitmovement 0x0
	applymovement 0x4, 0x08206ADE
	waitmovement 0x0
	loadword 0x0, gJPText_0020757C
	callstd 0x4
	playfanfare 0x172
	loadword 0x0, gJPText_002075A5
	callstd 0x4
	waitfanfare
	loadword 0x0, gJPText_002075B4
	callstd 0x4
	loadword 0x0, gJPText_002075CA
	callstd 0x4
	closemessage
	return

LilycoveCity_ContestLobby_EventScript_00206A20::
	specialvar 0x8004, CountPlayerContestPaintings
	copyvar 0x8000, 0x8004
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206A62
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206A66
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206A6A
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206A6E
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206A72
	return

LilycoveCity_ContestLobby_EventScript_00206A62::
	clearflag 0x308
	return

LilycoveCity_ContestLobby_EventScript_00206A66::
	clearflag 0x309
	return

LilycoveCity_ContestLobby_EventScript_00206A6A::
	clearflag 0x30A
	return

LilycoveCity_ContestLobby_EventScript_00206A6E::
	clearflag 0x30B
	return

LilycoveCity_ContestLobby_EventScript_00206A72::
	clearflag 0x30C
	return

LilycoveCity_ContestLobby_EventScript_00206A76::
	copyvar 0x8000, 0x8011
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206AB3
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206AB7
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206ABB
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206ABF
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206AC3
	return

LilycoveCity_ContestLobby_EventScript_00206AB3::
	setflag 0xA0
	return

LilycoveCity_ContestLobby_EventScript_00206AB7::
	setflag 0xA1
	return

LilycoveCity_ContestLobby_EventScript_00206ABB::
	setflag 0xA2
	return

LilycoveCity_ContestLobby_EventScript_00206ABF::
	setflag 0xA3
	return

LilycoveCity_ContestLobby_EventScript_00206AC3::
	setflag 0xA4
	return

	.incbin "baserom_jp.gba", 0x206ac7, 0x20
LilycoveCity_ContestLobby_EventScript_00206AE7::
	checkflag 0x307
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206AF6
	setvar 0x4099, 0x0
	end

LilycoveCity_ContestLobby_EventScript_00206AF6::
	lockall
	addobject 0xB
	applymovement 0xB, 0x08206BF3
	waitmovement 0xB
	applymovement 0xFF, 0x08206C05
	waitmovement 0x0
	loadword 0x0, gJPText_00207435
	callstd 0x4
	lockall
	fadescreen 0x1
	showcontestwinner 0x0
	loadword 0x0, gJPText_002074A1
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206B3A
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206B74
	end

LilycoveCity_ContestLobby_EventScript_00206B3A::
	loadword 0x0, gJPText_00207519
	callstd 0x4
	closemessage
	special sub_080F916C
	setvar 0x4099, 0x0
	specialvar 0x800D, GiveMonArtistRibbon
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, LilycoveCity_ContestLobby_EventScript_00206BA4
	applymovement 0xB, 0x08206BFC
	waitmovement 0x0
	removeobject 0xB
	call LilycoveCity_ContestLobby_EventScript_00206A20
	call LilycoveCity_ContestLobby_EventScript_00206A76
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_00206B74::
	loadword 0x0, gJPText_002075D1
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206B3A
	loadword 0x0, gJPText_0020760A
	callstd 0x4
	closemessage
	applymovement 0xB, 0x08206BFC
	waitmovement 0x0
	setvar 0x4099, 0x0
	removeobject 0xB
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_00206BA4::
	incrementgamestat 0x2A
	setflag 0x89B
	special sub_080F8C14
	applymovement 0xB, 0x08206C07
	waitmovement 0x0
	playse 0x15
	applymovement 0xB, 0x0824361B
	waitmovement 0x0
	applymovement 0xB, 0x08206C0B
	waitmovement 0x0
	loadword 0x0, gJPText_0020757C
	callstd 0x4
	playfanfare 0x172
	loadword 0x0, gJPText_002075A5
	callstd 0x4
	waitfanfare
	loadword 0x0, gJPText_002075B4
	callstd 0x4
	loadword 0x0, gJPText_002075CA
	callstd 0x4
	closemessage
	return

	.incbin "baserom_jp.gba", 0x206bf3, 0x21
LilycoveCity_ContestLobby_EventScript_00206C14::
	special sub_080F99E4
	specialvar 0x800D, sub_080F95B4
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206C8F
	call 0x08248AF4
	call LilycoveCity_ContestLobby_EventScript_00206D30
	special SetContestTrainerGfxIds
	call 0x0821DD5F
	call LilycoveCity_ContestLobby_EventScript_00206C45
	call LilycoveCity_ContestLobby_EventScript_00206CAF
	waitstate
	end

LilycoveCity_ContestLobby_EventScript_00206C45::
	copyvar 0x8000, 0x8010
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206C77
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206C7D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206C83
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206C89
	return

LilycoveCity_ContestLobby_EventScript_00206C77::
	setvar 0x4088, 0x1
	return

LilycoveCity_ContestLobby_EventScript_00206C7D::
	setvar 0x4088, 0x2
	return

LilycoveCity_ContestLobby_EventScript_00206C83::
	setvar 0x4088, 0x3
	return

LilycoveCity_ContestLobby_EventScript_00206C89::
	setvar 0x4088, 0x4
	return

LilycoveCity_ContestLobby_EventScript_00206C8F::
	setflag 0x307
	copyvar 0x4094, 0x1
	additem 0x10A, 0x1
	setvar 0x800B, 0x8
	setvar 0x8010, 0x3
	setvar 0x4099, 0x1
	setflag 0x89B
	end

LilycoveCity_ContestLobby_EventScript_00206CAF::
	setflag 0x155
	copyvar 0x8000, 0x8011
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206CEF
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206CFC
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206D09
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206D16
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206D23
	return

LilycoveCity_ContestLobby_EventScript_00206CEF::
	setwarp 0x1925, 0xFF, 0x7, 0x5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_00206CFC::
	setwarp 0x1923, 0xFF, 0x7, 0x5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_00206D09::
	setwarp 0x1927, 0xFF, 0x7, 0x5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_00206D16::
	setwarp 0x1926, 0xFF, 0x7, 0x5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_00206D23::
	setwarp 0x1924, 0xFF, 0x7, 0x5
	special DoContestHallWarp
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_00206D30::
	lockall
	applymovement 0x1, 0x08206DB5
	waitmovement 0x0
	playse 0x47
	setmetatile 0xC, 0x2, 0x221, 0x1
	setmetatile 0xC, 0x3, 0x261, 0x1
	special DrawWholeMapView
	applymovement 0x1, 0x08206DB9
	waitmovement 0x0
	playse 0x47
	setmetatile 0xC, 0x2, 0x2D1, 0x1
	setmetatile 0xC, 0x3, 0x2D9, 0x1
	special DrawWholeMapView
	delay 0x14
	applymovement 0x1, 0x08206DC6
	waitmovement 0x0
	applymovement 0xFF, 0x08206DB2
	waitmovement 0x0
	loadword 0x0, 0x0824A10A
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08206DBD
	applymovement 0xFF, 0x08206DA8
	waitmovement 0x0
	releaseall
	return

	.incbin "baserom_jp.gba", 0x206da8, 0x20
LilycoveCity_ContestLobby_EventScript_00206DC8::
	loadword 0x0, 0x08207640
	callstd 0x2
	end

LilycoveCity_ContestLobby_EventScript_00206DD1::
	loadword 0x0, 0x08207692
	callstd 0x2
	end

LilycoveCity_ContestLobby_EventScript_00206DDA::
	loadword 0x0, 0x082076BA
	callstd 0x2
	end

LilycoveCity_ContestLobby_EventScript_00206DE3::
	loadword 0x0, 0x082076E6
	callstd 0x2
	end

LilycoveCity_ContestLobby_EventScript_00206DEC::
	loadword 0x0, 0x0820771C
	callstd 0x2
	end

LilycoveCity_ContestLobby_EventScript_00206DF5::
	loadword 0x0, 0x0820775B
	callstd 0x2
	end

LilycoveCity_ContestLobby_EventScript_00206DFE::
	lockall
	fadescreen 0x1
	showcontestwinner 0x1
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_00206E05::
	lockall
	fadescreen 0x1
	showcontestwinner 0x2
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_00206E0C::
	lockall
	fadescreen 0x1
	showcontestwinner 0x3
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_00206E13::
	lockall
	fadescreen 0x1
	showcontestwinner 0x4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_00206E1A::
	lockall
	fadescreen 0x1
	showcontestwinner 0x5
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_00206E21::
	lockall
	fadescreen 0x1
	showcontestwinner 0x6
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_00206E28::
	loadword 0x0, 0x082587AE
	callstd 0x2
	end

LilycoveCity_ContestLobby_EventScript_00206E31::
	loadword 0x0, 0x082587BA
	callstd 0x2
	end

LilycoveCity_ContestLobby_EventScript_00206E3A::
	lockall
	special ShowBerryBlenderRecordWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_00206E44::
	lockall
	setvar 0x8004, 0x7
	setvar 0x8005, 0x7
	special CallFrontierUtilFunc
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_00206E58::
	lock
	faceplayer
	loadword 0x0, 0x08274705
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_00206EB9
	end

LilycoveCity_ContestLobby_EventScript_00206E68::
	lock
	loadword 0x0, 0x0827495B
	callstd 0x4
	release
	end

LilycoveCity_ContestLobby_EventScript_00206E73::
	lock
	loadword 0x0, 0x08274961
	callstd 0x4
	release
	end

LilycoveCity_ContestLobby_EventScript_00206E7E::
	lock
	loadword 0x0, 0x08274966
	callstd 0x4
	release
	end

LilycoveCity_ContestLobby_EventScript_00206E89::
	lock
	faceplayer
	loadword 0x0, 0x0827496C
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_00206EB9
	end

LilycoveCity_ContestLobby_EventScript_00206E99::
	lock
	faceplayer
	loadword 0x0, 0x08274990
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_00206EB9
	end

LilycoveCity_ContestLobby_EventScript_00206EA9::
	lock
	faceplayer
	loadword 0x0, 0x082749E1
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_00206EB9
	end

LilycoveCity_ContestLobby_EventScript_00206EB9::
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	release
	end

LilycoveCity_ContestLobby_EventScript_00206EC6::
	special sub_080F99E4
	lock
	faceplayer
	loadword 0x0, 0x0824A6FB
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_00206ED9
	end

LilycoveCity_ContestLobby_EventScript_00206ED9::
	message 0x0824A744
	waitmessage
	multichoice 0x0, 0x0, 0x2, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206F16
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206FCD
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	end

LilycoveCity_ContestLobby_EventScript_00206F16::
	loadword 0x0, 0x0824A50F
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	call 0x082423E9
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	message 0x0824AB68
	waitmessage
	specialvar 0x400D, IsWirelessAdapterConnected
	multichoice 0x0, 0x0, 0x55, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206F7B
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206F86
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	end

LilycoveCity_ContestLobby_EventScript_00206F7B::
	setvar 0x400C, 0x0
	goto LilycoveCity_ContestLobby_EventScript_00206F9C
	end

LilycoveCity_ContestLobby_EventScript_00206F86::
	setvar 0x400C, 0x1
	compare_var_to_value 0x400D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002071BC
	goto LilycoveCity_ContestLobby_EventScript_00206F9C
	end

LilycoveCity_ContestLobby_EventScript_00206F9C::
	message 0x0824A755
	waitmessage
	multichoice 0x0, 0x0, 0x4, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	copyvar 0x8011, 0x800D
	goto LilycoveCity_ContestLobby_EventScript_0020704C
	end

LilycoveCity_ContestLobby_EventScript_00206FCD::
	message 0x0824A734
	waitmessage
	multichoice 0x0, 0x0, 0x54, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00207015
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00207023
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00207031
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206ED9
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00206ED9
	end

LilycoveCity_ContestLobby_EventScript_00207015::
	loadword 0x0, 0x0824A86C
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_00206FCD
	end

LilycoveCity_ContestLobby_EventScript_00207023::
	loadword 0x0, 0x0824A9B5
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_00206FCD
	end

LilycoveCity_ContestLobby_EventScript_00207031::
	loadword 0x0, 0x0824AA8A
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_00206FCD
	end

LilycoveCity_ContestLobby_EventScript_0020703F::
	special CloseLink
	loadword 0x0, 0x0824A52D
	callstd 0x4
	release
	end

LilycoveCity_ContestLobby_EventScript_0020704C::
	loadword 0x0, 0x0824A7AE
	callstd 0x4
	setvar 0x8010, 0x0
	showcontestresults
	compare_var_to_value 0x8004, 0xFF
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	special sub_080F87C0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002070A0
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002070CA
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002070CA
	compare_var_to_value 0x800D, 0x3
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002070AE
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002070BC
	end

LilycoveCity_ContestLobby_EventScript_002070A0::
	loadword 0x0, 0x08249FDD
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_0020704C
	end

LilycoveCity_ContestLobby_EventScript_002070AE::
	loadword 0x0, 0x0824A790
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_0020704C
	end

LilycoveCity_ContestLobby_EventScript_002070BC::
	loadword 0x0, 0x0824A769
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_0020704C
	end

LilycoveCity_ContestLobby_EventScript_002070CA::
	copyvar 0x8008, 0x8004
	goto LilycoveCity_ContestLobby_EventScript_002070D5
	end

LilycoveCity_ContestLobby_EventScript_002070D5::
	compare_var_to_value 0x400D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020720B
	compare_var_to_value 0x400D, 0x2
	goto_if 0x4, LilycoveCity_ContestLobby_EventScript_0020703F
	message 0x0824A65D
	waitmessage
	copyvar 0x8004, 0x800D
	compare_var_to_value 0x400C, 0x0
	call_if 0x1, LilycoveCity_ContestLobby_EventScript_0020717B
	compare_var_to_value 0x400C, 0x1
	call_if 0x1, LilycoveCity_ContestLobby_EventScript_00207180
	compare_var_to_value 0x400C, 0x2
	goto_if 0x4, LilycoveCity_ContestLobby_EventScript_0020703F
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00207193
	compare_var_to_value 0x800D, 0x3
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00207193
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	compare_var_to_value 0x800D, 0x6
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002071AF
	compare_var_to_value 0x800D, 0xA
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002071A1
	cmdDB 0x0824A60C
	contestlinktransfer
	copyvar 0x8000, 0x8004
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002071D7
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00207185
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002071C9
	end

LilycoveCity_ContestLobby_EventScript_0020717B::
	special TryContestEModeLinkup
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_00207180::
	special TryContestGModeLinkup
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_00207185::
	loadword 0x0, 0x0824A629
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_0020703F
	end

LilycoveCity_ContestLobby_EventScript_00207193::
	loadword 0x0, 0x0824A646
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_0020703F
	end

LilycoveCity_ContestLobby_EventScript_002071A1::
	loadword 0x0, 0x0824A801
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_0020703F
	end

LilycoveCity_ContestLobby_EventScript_002071AF::
	special CloseLink
	loadword 0x0, 0x08247D67
	callstd 0x4
	release
	end

LilycoveCity_ContestLobby_EventScript_002071BC::
	special CloseLink
	loadword 0x0, 0x0824AB11
	callstd 0x4
	release
	end

LilycoveCity_ContestLobby_EventScript_002071C9::
	loadword 0x0, 0x0824A619
	callstd 0x4
	goto LilycoveCity_ContestLobby_EventScript_0020703F
	end

LilycoveCity_ContestLobby_EventScript_002071D7::
	special sub_080F8D34
	addvar 0x8004, 0x1
	buffernumberstring 0x1, 0x8004
	messageautoscroll 0x0824A6AA
	waitmessage
	subvar 0x8004, 0x1
	call LilycoveCity_ContestLobby_EventScript_00207309
	setvar 0x4086, 0x1
	special sub_080F938C
	setvar 0x4088, 0x5
	setvar 0x8010, 0x3
	call LilycoveCity_ContestLobby_EventScript_00206CAF
	end

LilycoveCity_ContestLobby_EventScript_0020720B::
	compare_var_to_value 0x8011, 0x0
	call_if 0x1, LilycoveCity_ContestLobby_EventScript_00207248
	compare_var_to_value 0x8011, 0x1
	call_if 0x1, LilycoveCity_ContestLobby_EventScript_0020724E
	compare_var_to_value 0x8011, 0x2
	call_if 0x1, LilycoveCity_ContestLobby_EventScript_00207254
	compare_var_to_value 0x8011, 0x3
	call_if 0x1, LilycoveCity_ContestLobby_EventScript_0020725A
	compare_var_to_value 0x8011, 0x4
	call_if 0x1, LilycoveCity_ContestLobby_EventScript_00207260
	goto LilycoveCity_ContestLobby_EventScript_00207266
	end

LilycoveCity_ContestLobby_EventScript_00207248::
	setvar 0x8004, 0xF
	return

LilycoveCity_ContestLobby_EventScript_0020724E::
	setvar 0x8004, 0x10
	return

LilycoveCity_ContestLobby_EventScript_00207254::
	setvar 0x8004, 0x11
	return

LilycoveCity_ContestLobby_EventScript_0020725A::
	setvar 0x8004, 0x12
	return

LilycoveCity_ContestLobby_EventScript_00207260::
	setvar 0x8004, 0x13
	return

LilycoveCity_ContestLobby_EventScript_00207266::
	message 0x0824A7C2
	waitmessage
	multichoice 0x10, 0x6, 0x51, 0x0
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002072CB
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002072A3
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	compare_var_to_value 0x8000, 0x7F
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_0020703F
	end

LilycoveCity_ContestLobby_EventScript_002072A3::
	call LilycoveCity_ContestLobby_EventScript_002072F3
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002072FD
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00207266
	compare_var_to_value 0x800D, 0x8
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002072A3
	release
	end

LilycoveCity_ContestLobby_EventScript_002072CB::
	call LilycoveCity_ContestLobby_EventScript_002072F8
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002072FD
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_00207266
	compare_var_to_value 0x800D, 0x8
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002072CB
	release
	end

LilycoveCity_ContestLobby_EventScript_002072F3::
	special BerryBlenderLinkBecomeLeader
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_002072F8::
	special BerryBlenderLinkJoinGroup
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_002072FD::
	cmdDB 0x0824A60C
	contestlinktransfer
	goto LilycoveCity_ContestLobby_EventScript_002071D7
	end

LilycoveCity_ContestLobby_EventScript_00207309::
	messageautoscroll 0x0824A6E8
	waitmessage
	delay 0x14
	closemessage
	applymovement 0x2, 0x0820739D
	waitmovement 0x0
	playse 0x47
	setmetatile 0x11, 0x2, 0x221, 0x1
	setmetatile 0x11, 0x3, 0x261, 0x1
	special DrawWholeMapView
	applymovement 0x2, 0x082073A1
	waitmovement 0x0
	playse 0x47
	setmetatile 0x11, 0x2, 0x2D1, 0x1
	setmetatile 0x11, 0x3, 0x2D9, 0x1
	special DrawWholeMapView
	delay 0x14
	applymovement 0x2, 0x082073AF
	waitmovement 0x0
	applymovement 0xFF, 0x0820739B
	waitmovement 0x0
	messageautoscroll 0x0824A10A
	waitmessage
	delay 0x14
	closemessage
	call 0x08249BC1
	applymovement 0x2, 0x082073A5
	applymovement 0xFF, 0x08207390
	waitmovement 0x0
	release
	return

	.incbin "baserom_jp.gba", 0x207390, 0x21
LilycoveCity_ContestLobby_EventScript_002073B1::
	lock
	faceplayer
	checkflag 0x5F
	goto_if 0x1, LilycoveCity_ContestLobby_EventScript_002073C6
	loadword 0x0, 0x082073D0
	callstd 0x4
	release
	end

LilycoveCity_ContestLobby_EventScript_002073C6::
	loadword 0x0, 0x082073F8
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x2073d0, 0x65
	.globl gJPText_00207435
gJPText_00207435: @ 0x08207435
	.string "ゆうしょう　おめでとう！\p"
	.string "さっそく　きねんに\n"
	.string "きみの　ポケモンの　えを\l"
	.string "かきあげたんだけど⋯⋯\p"
	.string "なんだか　きみの　ポケモンの　アピールが\n"
	.string "あまり　にも　すばらしくて\l"
	.string "いつもより　うまく　かけたんだ！\l"
	.string "ほらっ　これ！$"

	.globl gJPText_002074A1
gJPText_002074A1: @ 0x082074A1
	.string "どうかな？　じしんさく　なんだけど\n"
	.string "きにいったろ？\p"
	.string "これくらいの　でき　なら\n"
	.string "びじゅつかんに　かざられて　いても\l"
	.string "ふしぎじゃ　ないね！\p"
	.string "⋯⋯え　ほんとに　びじゅつかんで\n"
	.string "えを　さがして　いるって？\l"
	.string "じゃあ　これ　もっていって　みようかな？$"

	.globl gJPText_00207519
gJPText_00207519: @ 0x08207519
	.string "そ　そうか！\n"
	.string "じゃ　いますぐ　もっていって　みるよ\l"
	.string "タイトルも　つけて　おくからね！\p"
	.string "これが　きにいられて\n"
	.string "かざって　もらえて　いるか　どうか\l"
	.string "きみも　こんど　みに　いってね！\l"
	.string "じゃ　ありがとう！$"

	.globl gJPText_0020757C
gJPText_0020757C: @ 0x0820757C
	.string "⋯⋯あ　そうだ\p"
	.string "ポケモンを　かかせて　もらった　きねんに\n"
	.string "これを　うけとってよ！$"

	.globl gJPText_002075A5
gJPText_002075A5: @ 0x082075A5
	.string "{MUS_RG_VS_TRAINER}は　リボンを　もらった！$"

	.globl gJPText_002075B4
gJPText_002075B4: @ 0x082075B4
	.string "{MUS_RG_VS_TRAINER}は　リボンを\n"
	.string "{B_COPY_VAR_1}に　つけて　あげた！$"

	.globl gJPText_002075CA
gJPText_002075CA: @ 0x082075CA
	.string "それじゃね！$"

	.globl gJPText_002075D1
gJPText_002075D1: @ 0x082075D1
	.string "うーん⋯⋯　じゃあ　これは\n"
	.string "ぼくが　もってかえると　するか⋯⋯\p"
	.string "でも　やっぱり　もっていきたいな⋯⋯\n"
	.string "いいだろ？$"

	.globl gJPText_0020760A
gJPText_0020760A: @ 0x0820760A
	.string "そっか　しかたないね\n"
	.string "それじゃ　これは　ぼくの\l"
	.string "いえに　かざります\p"
	.string "つぎ　がんばると　するか⋯⋯\n"
	.string "じゃあな$"

	.incbin "baserom_jp.gba", 0x207640, 0xc0a
