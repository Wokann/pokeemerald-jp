@ IslandCave scripts (JP map g24 m67 @ 0x0821B76F)

IslandCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, IslandCave_EventScript_0021B77F
	map_script MAP_SCRIPT_ON_LOAD, IslandCave_EventScript_0021B79D
	map_script MAP_SCRIPT_ON_TRANSITION, IslandCave_EventScript_0021B7DE
	.byte 0

IslandCave_EventScript_0021B77F::
	checkflag 0x8C1
	call_if 0x1, IslandCave_EventScript_0021B789
	end

IslandCave_EventScript_0021B789::
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x7
	goto_if 0x5, 0x08244178
	removeobject 0x800F
	return

IslandCave_EventScript_0021B79D::
	checkflag 0x8B1
	call_if 0x0, IslandCave_EventScript_0021B7A7
	end

IslandCave_EventScript_0021B7A7::
	setmetatile 0x7, 0x13, 0x229, 0x1
	setmetatile 0x8, 0x13, 0x229, 0x1
	setmetatile 0x9, 0x13, 0x229, 0x1
	setmetatile 0x7, 0x14, 0x235, 0x1
	setmetatile 0x8, 0x14, 0x235, 0x1
	setmetatile 0x9, 0x14, 0x235, 0x1
	return

IslandCave_EventScript_0021B7DE::
	setflag 0x8B5
	call IslandCave_EventScript_0021B88A
	checkflag 0x1BC
	call_if 0x0, IslandCave_EventScript_0021B7F0
	end

IslandCave_EventScript_0021B7F0::
	clearflag 0x3A8
	return

IslandCave_EventScript_OpenRegiEntrance:: @ 0x0821B7F4
	.incbin "baserom_jp.gba", 0x21b7f4, 0x40
IslandCave_EventScript_0021B834::
	lockall
	checkflag 0x3
	call_if 0x1, IslandCave_EventScript_0021B88A
	checkflag 0x8B1
	goto_if 0x1, IslandCave_EventScript_0021B858
	braillemessage 0x0826377A
	setflag 0x2
	special ShouldDoBrailleRegicePuzzle
	goto IslandCave_EventScript_0021B886
	end

IslandCave_EventScript_0021B858::
	loadword 0x0, 0x08243CDA
	callstd 0x4
	releaseall
	end

IslandCave_EventScript_0021B862::
	lockall
	checkflag 0x3
	call_if 0x1, IslandCave_EventScript_0021B88A
	braillemessage 0x0826377A
	checkflag 0x8B1
	goto_if 0x1, IslandCave_EventScript_0021B886
	setflag 0x2
	special ShouldDoBrailleRegicePuzzle
	goto IslandCave_EventScript_0021B886
	end

IslandCave_EventScript_0021B886::
	waitbuttonpress
	mossdeepgym4
	releaseall
	end

IslandCave_EventScript_0021B88A::
	setvar 0x403B, 0x0
	setvar 0x403C, 0x0
	setvar 0x403D, 0x0
	clearflag 0x3
	return

IslandCave_EventScript_0021B89D::
	lock
	faceplayer
	waitse
	playmoncry 0x192, 0x2
	delay 0x28
	waitdooranim
	setwildbattle 0x192, 0x28, 0x0
	setflag 0x8C1
	special StartRegiBattle
	clearflag 0x8C1
	specialvar 0x800D, GetBattleOutcome
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, IslandCave_EventScript_0021B8E4
	compare_var_to_value 0x800D, 0x4
	goto_if 0x1, IslandCave_EventScript_0021B8ED
	compare_var_to_value 0x800D, 0x5
	goto_if 0x1, IslandCave_EventScript_0021B8ED
	setflag 0x1BC
	release
	end

IslandCave_EventScript_0021B8E4::
	setflag 0x1BC
	goto 0x08244197
	end

IslandCave_EventScript_0021B8ED::
	setvar 0x8004, 0x192
	goto 0x082441A0
	end

