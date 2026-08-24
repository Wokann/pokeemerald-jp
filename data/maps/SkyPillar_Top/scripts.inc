@ SkyPillar_Top scripts (JP map g24 m85 @ 0x0821BF28)

SkyPillar_Top_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SkyPillar_Top_EventScript_0021BF38
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_Top_EventScript_0021BF56
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SkyPillar_Top_MapScriptTable_0021BF83
	.byte 0

SkyPillar_Top_EventScript_0021BF38::
	checkflag 0x8C1
	call_if 0x1, SkyPillar_Top_EventScript_0021BF42
	end

SkyPillar_Top_EventScript_0021BF42::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x800F
	return

SkyPillar_Top_EventScript_0021BF56::
	compare_var_to_value 0x40CA, 0x2
	call_if 0x0, SkyPillar_Top_EventScript_0021BF6D
	compare_var_to_value 0x40CA, 0x2
	call_if 0x4, SkyPillar_Top_EventScript_0021BF75
	end

SkyPillar_Top_EventScript_0021BF6D::
	setmaplayoutindex 0x1B6
	setobjectmovementtype 0x1, 0x8
	return

SkyPillar_Top_EventScript_0021BF75::
	checkflag 0x1C0
	call_if 0x0, SkyPillar_Top_EventScript_0021BF7F
	return

SkyPillar_Top_EventScript_0021BF7F::
	clearflag 0x50
	return

SkyPillar_Top_MapScriptTable_0021BF83::
	map_script_2 0x40CA, 0x0, SkyPillar_Top_EventScript_0021BF8D
	.2byte 0

SkyPillar_Top_EventScript_0021BF8D::
	turnobject 0x1, 0x1
	end

SkyPillar_Top_EventScript_0021BF92::
	lockall
	waitse
	playmoncry 0x196, 0x2
	delay 0x28
	waitdooranim
	setwildbattle 0x196, 0x46, 0x0
	setflag 0x8C1
	special BattleSetup_StartLegendaryBattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SkyPillar_Top_EventScript_0021BFD8
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, SkyPillar_Top_EventScript_0021BFE1
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, SkyPillar_Top_EventScript_0021BFE1
	setflag 0x1C0
	releaseall
	end

SkyPillar_Top_EventScript_0021BFD8::
	setflag 0x1C0
	goto SkyPillar_Top_EventScript_0021BFEC
	end

SkyPillar_Top_EventScript_0021BFE1::
	setvar 0x8004, 0x196
	goto SkyPillar_Top_EventScript_0021BFF5
	end

SkyPillar_Top_EventScript_0021BFEC::
	fadescreenswapbuffers 0x1
	removeobject 0x800F
	fadescreenswapbuffers 0x0
	releaseall
	end

SkyPillar_Top_EventScript_0021BFF5::
	fadescreenswapbuffers 0x1
	removeobject 0x800F
	fadescreenswapbuffers 0x0
	bufferspeciesname 0x0, 0x8004
	loadword 0x0, 0x08243DF4
	callstd 0x4
	releaseall
	end

SkyPillar_Top_EventScript_0021C00A::
	lockall
	fadeoutbgm 0x1
	applymovement 0xFF, 0x08243635
	waitmovement 0x0
	special SpawnCameraObject
	applymovement 0x7F, 0x0821C0C8
	waitmovement 0x0
	special RemoveCameraObject
	applymovement 0x1, 0x0821C0AA
	waitmovement 0x0
	waitse
	playmoncry 0x196, 0x2
	setvar 0x8004, 0x1
	setvar 0x8005, 0x1
	setvar 0x8006, 0x8
	setvar 0x8007, 0x3
	special ShakeCamera
	waitstate
	waitse
	playmoncry 0x196, 0x2
	setvar 0x8004, 0x1
	setvar 0x8005, 0x2
	setvar 0x8006, 0x8
	setvar 0x8007, 0x5
	special ShakeCamera
	waitstate
	waitdooranim
	applymovement 0x1, 0x0821C0BB
	waitmovement 0x0
	removeobject 0x1
	loadword 0x0, 0x0821C0D0
	callstd 0x4
	closemessage
	delay 0x14
	fadeinbgm 0x1
	special SpawnCameraObject
	applymovement 0x7F, 0x0821C0CC
	waitmovement 0x0
	special RemoveCameraObject
	setvar 0x405E, 0x5
	setvar 0x40CA, 0x1
	setvar 0x40D7, 0x1
	releaseall
	end

	.incbin "baserom_jp.gba", 0x21c0aa, 0x49
