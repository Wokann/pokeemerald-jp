@ Route121_SafariZoneEntrance scripts (JP map g23 m0 @ 0x082129E5)

Route121_SafariZoneEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route121_SafariZoneEntrance_MapScriptTable_002129EB
	.byte 0

Route121_SafariZoneEntrance_MapScriptTable_002129EB::
	map_script_2 0x40A4, 0x1, Route121_SafariZoneEntrance_EventScript_002129F5
	.2byte 0

Route121_SafariZoneEntrance_EventScript_002129F5::
	lockall
	applymovement 0xFF, 0x08212A07
	waitmovement 0x0
	setvar 0x40A4, 0x0
	releaseall
	end

	.incbin "baserom_jp.gba", 0x212a07, 0x9
Route121_SafariZoneEntrance_EventScript_00212A10::
	loadword 0x0, 0x082624E7
	callstd 0x2
	end

Route121_SafariZoneEntrance_EventScript_00212A19::
	lock
	faceplayer
	loadword 0x0, 0x0826257A
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route121_SafariZoneEntrance_EventScript_00212A38
	loadword 0x0, 0x0826259C
	callstd 0x4
	release
	end

Route121_SafariZoneEntrance_EventScript_00212A38::
	loadword 0x0, 0x082625B1
	callstd 0x4
	release
	end

Route121_SafariZoneEntrance_EventScript_00212A42::
	lockall
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	showmoneybox 0x0, 0x0, 0x0
	loadword 0x0, 0x08262621
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route121_SafariZoneEntrance_EventScript_00212A72
	loadword 0x0, 0x08262659
	callstd 0x4
	goto Route121_SafariZoneEntrance_EventScript_00212B30
	end

Route121_SafariZoneEntrance_EventScript_00212A72::
	checkitem 0x111, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route121_SafariZoneEntrance_EventScript_00212B14
	call Route121_SafariZoneEntrance_EventScript_00212AE9
	checkmoney 0x1F4, 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route121_SafariZoneEntrance_EventScript_00212B22
	playse 0x5F
	loadword 0x0, 0x0826267F
	callstd 0x4
	takemoney 0x1F4, 0x0
	updatemoneybox 0x0
	loadword 0x0, 0x08262691
	callstd 0x4
	playfanfare 0x172
	message 0x082626A2
	waitfanfare
	loadword 0x0, 0x082626BA
	callstd 0x4
	closemessage
	hidemoneybox
	applymovement 0xFF, 0x08212B42
	waitmovement 0x0
	special EnterSafariMode
	setvar 0x40A4, 0x2
	clearflag 0x5D
	warp 0x1A03, 0xFF, 0x20, 0x21
	waitstate
	end

Route121_SafariZoneEntrance_EventScript_00212AE9::
	getpartysize
	compare_var_to_value 0x800D, 0x6
	goto_if 0x5, Route121_SafariZoneEntrance_EventScript_00212B13
	specialvar 0x800D, ScriptCheckFreePokemonStorageSpace
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route121_SafariZoneEntrance_EventScript_00212B13
	loadword 0x0, 0x082626F6
	callstd 0x4
	goto Route121_SafariZoneEntrance_EventScript_00212B30
	end

Route121_SafariZoneEntrance_EventScript_00212B13::
	return

Route121_SafariZoneEntrance_EventScript_00212B14::
	loadword 0x0, 0x0826270E
	callstd 0x4
	goto Route121_SafariZoneEntrance_EventScript_00212B30
	end

Route121_SafariZoneEntrance_EventScript_00212B22::
	loadword 0x0, 0x08262672
	callstd 0x4
	goto Route121_SafariZoneEntrance_EventScript_00212B30
	end

Route121_SafariZoneEntrance_EventScript_00212B30::
	closemessage
	hidemoneybox
	applymovement 0xFF, 0x08212B40
	waitmovement 0x0
	releaseall
	end

	.incbin "baserom_jp.gba", 0x212b40, 0xb
Route121_SafariZoneEntrance_EventScript_00212B4B::
	loadword 0x0, 0x082629C5
	callstd 0x3
	end

