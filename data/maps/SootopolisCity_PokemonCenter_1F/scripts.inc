@ SootopolisCity_PokemonCenter_1F scripts (JP map g15 m2 @ 0x0820EFD5)

SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_EventScript_0020EFE0
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

SootopolisCity_PokemonCenter_1F_EventScript_0020EFE0::
	setrespawn 0xA
	end

SootopolisCity_PokemonCenter_1F_EventScript_0020EFE4::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_0020EFF2::
	lock
	faceplayer
	compare_var_to_value 0x40CA, 0x2
	goto_if 0x4, SootopolisCity_PokemonCenter_1F_EventScript_0020F012
	checkflag 0x81
	goto_if 0x0, SootopolisCity_PokemonCenter_1F_EventScript_0020F012
	loadword 0x0, 0x0820F0D5
	callstd 0x4
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_0020F012::
	loadword 0x0, 0x0820F046
	callstd 0x4
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_0020F01C::
	lock
	faceplayer
	compare_var_to_value 0x40CA, 0x2
	goto_if 0x4, SootopolisCity_PokemonCenter_1F_EventScript_0020F03C
	checkflag 0x81
	goto_if 0x0, SootopolisCity_PokemonCenter_1F_EventScript_0020F03C
	loadword 0x0, 0x0820F15E
	callstd 0x4
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_0020F03C::
	loadword 0x0, 0x0820F117
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x20f046, 0x14a
