@ FarawayIsland_Interior scripts (JP map g26 m57 @ 0x0823B3C8)

FarawayIsland_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FarawayIsland_Interior_EventScript_0023B422
	map_script MAP_SCRIPT_ON_TRANSITION, FarawayIsland_Interior_EventScript_0023B440
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FarawayIsland_Interior_MapScriptTable_0023B466
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, FarawayIsland_Interior_EventScript_0023B3DD
	.byte 0

FarawayIsland_Interior_EventScript_0023B3DD::
	checkflag 0x8C1
	call_if 0x1, FarawayIsland_Interior_EventScript_0023B3E7
	end

FarawayIsland_Interior_EventScript_0023B3E7::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, FarawayIsland_Interior_EventScript_0023B419
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, FarawayIsland_Interior_EventScript_0023B419
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, FarawayIsland_Interior_EventScript_0023B419
	compare_var_to_value 0x800D, 0xA
	goto_if 0x1, FarawayIsland_Interior_EventScript_0023B419
	return

FarawayIsland_Interior_EventScript_0023B419::
	setvar 0x8004, 0x1
	special SetMewAboveGrass
	return

FarawayIsland_Interior_EventScript_0023B422::
	checkflag 0x8C1
	call_if 0x1, FarawayIsland_Interior_EventScript_0023B42C
	end

FarawayIsland_Interior_EventScript_0023B42C::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x800F
	return

FarawayIsland_Interior_EventScript_0023B440::
	setvar 0x403A, 0x0
	setvar 0x4001, 0x1
	checkflag 0x1CA
	call_if 0x0, FarawayIsland_Interior_EventScript_0023B454
	end

FarawayIsland_Interior_EventScript_0023B454::
	checkflag 0x1C7
	goto_if 0x1, 0x08244178
	clearflag 0x2CE
	setvar 0x4001, 0x0
	return

FarawayIsland_Interior_MapScriptTable_0023B466::
	map_script_2 0x4001, 0x0, FarawayIsland_Interior_EventScript_0023B470
	.2byte 0

FarawayIsland_Interior_EventScript_0023B470::
	lockall
	playse 0x15
	applymovement 0x1, 0x0824361B
	waitmovement 0x0
	applymovement 0x1, 0x0824361D
	waitmovement 0x0
	applymovement 0x1, 0x0823B49C
	waitmovement 0x0
	moveobjectoffscreen 0x1
	setvar 0x4001, 0x1
	releaseall
	end

	.incbin "baserom_jp.gba", 0x23b49c, 0x24
FarawayIsland_Interior_EventScript_0023B4C0::
	lock
	faceplayer
	applymovement 0x1, 0x0823B4A2
	waitmovement 0x0
	setvar 0x8004, 0x0
	special SetMewAboveGrass
	message 0x08275F57
	waitse
	playmoncry 0x97, 0x2
	compare_var_to_value 0x800C, 0x2
	call_if 0x1, FarawayIsland_Interior_EventScript_0023B57D
	compare_var_to_value 0x800C, 0x1
	call_if 0x1, FarawayIsland_Interior_EventScript_0023B588
	compare_var_to_value 0x800C, 0x3
	call_if 0x1, FarawayIsland_Interior_EventScript_0023B593
	compare_var_to_value 0x800C, 0x4
	call_if 0x1, FarawayIsland_Interior_EventScript_0023B59E
	special DestroyMewEmergingGrassSprite
	delay 0x28
	waitdooranim
	setvar 0x8004, 0x97
	setvar 0x8005, 0x1E
	setvar 0x8006, 0x0
	special CreateObedientEnemyMon
	setflag 0x8C1
	special BattleSetup_StartLegendaryBattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, FarawayIsland_Interior_EventScript_0023B564
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, FarawayIsland_Interior_EventScript_0023B572
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, FarawayIsland_Interior_EventScript_0023B572
	compare_var_to_value 0x800D, 0xA
	goto_if 0x1, FarawayIsland_Interior_EventScript_0023B572
	setflag 0x1CA
	release
	end

FarawayIsland_Interior_EventScript_0023B564::
	setflag 0x1C7
	setvar 0x8004, 0x97
	goto 0x082441A0
	end

FarawayIsland_Interior_EventScript_0023B572::
	setvar 0x8004, 0x97
	goto 0x082441A0
	end

FarawayIsland_Interior_EventScript_0023B57D::
	applymovement 0x1, 0x0823B4A4
	waitmovement 0x0
	return

FarawayIsland_Interior_EventScript_0023B588::
	applymovement 0x1, 0x0823B4AB
	waitmovement 0x0
	return

FarawayIsland_Interior_EventScript_0023B593::
	applymovement 0x1, 0x0823B4B2
	waitmovement 0x0
	return

FarawayIsland_Interior_EventScript_0023B59E::
	applymovement 0x1, 0x0823B4B9
	waitmovement 0x0
	return

FarawayIsland_Interior_EventScript_HideMewWhenGrassCut:: @ 0x0823B5A9
	.incbin "baserom_jp.gba", 0x23b5a9, 0x25
