@ Route110_SeasideCyclingRoadNorthEntrance scripts (JP map g29 m12 @ 0x082406C2)

Route110_SeasideCyclingRoadNorthEntrance_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_SeasideCyclingRoadNorthEntrance_EventScript_002406C8
	.byte 0

Route110_SeasideCyclingRoadNorthEntrance_EventScript_002406C8::
	compare_var_to_value 0x40A9, 0x3
	call_if 0x1, Route110_SeasideCyclingRoadNorthEntrance_EventScript_002406DF
	compare_var_to_value 0x40A9, 0x2
	call_if 0x1, Route110_SeasideCyclingRoadNorthEntrance_EventScript_002406DF
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_002406DF::
	setvar 0x40A9, 0x1
	return

Route110_SeasideCyclingRoadNorthEntrance_EventScript_002406E5::
	lock
	faceplayer
	loadword 0x0, 0x08240744
	callstd 0x4
	release
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_002406F1::
	lockall
	specialvar 0x800D, GetPlayerAvatarBike
	compare_var_to_value 0x800D, 0x2
	call_if 0x1, Route110_SeasideCyclingRoadNorthEntrance_EventScript_00240717
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route110_SeasideCyclingRoadNorthEntrance_EventScript_0024071D
	setflag 0x88B
	setvar 0x4001, 0x1
	releaseall
	end

Route110_SeasideCyclingRoadNorthEntrance_EventScript_00240717::
	setvar 0x40A9, 0x1
	return

Route110_SeasideCyclingRoadNorthEntrance_EventScript_0024071D::
	loadword 0x0, 0x08240785
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x08240732
	waitmovement 0x0
	releaseall
	end

	.incbin "baserom_jp.gba", 0x240732, 0x2
Route110_SeasideCyclingRoadNorthEntrance_EventScript_00240734::
	lockall
	setvar 0x40A9, 0x0
	clearflag 0x88B
	setvar 0x4001, 0x0
	releaseall
	end
