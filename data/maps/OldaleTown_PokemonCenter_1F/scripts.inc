@ OldaleTown_PokemonCenter_1F scripts (JP map g2 m2 @ 0x081F29A2)

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_EventScript_001F29AD
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

OldaleTown_PokemonCenter_1F_EventScript_001F29AD::
	setrespawn 0xE
	call 0x08242978
	end

OldaleTown_PokemonCenter_1F_EventScript_001F29B6::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_001F29C4::
	loadword 0x0, 0x081F29F5
	callstd 0x2
	end

OldaleTown_PokemonCenter_1F_EventScript_001F29CD::
	loadword 0x0, 0x081F2A31
	callstd 0x2
	end

OldaleTown_PokemonCenter_1F_EventScript_001F29D6::
	lock
	faceplayer
	checkflag 0x861
	goto_if 0x1, OldaleTown_PokemonCenter_1F_EventScript_001F29EB
	loadword 0x0, 0x081F2A73
	callstd 0x4
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_001F29EB::
	loadword 0x0, 0x081F2AA9
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x1f29f5, 0xef
