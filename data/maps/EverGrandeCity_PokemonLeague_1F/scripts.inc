@ EverGrandeCity_PokemonLeague_1F scripts (JP map g16 m10 @ 0x082110D4)

EverGrandeCity_PokemonLeague_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_EventScript_002110DF
	map_script MAP_SCRIPT_ON_RESUME, 0x0824790F
	.byte 0

EverGrandeCity_PokemonLeague_1F_EventScript_002110DF::
	setrespawn 0x14
	setflag 0x8B4
	checkflag 0x107
	call_if 0x0, EverGrandeCity_PokemonLeague_1F_EventScript_002110EF
	end

EverGrandeCity_PokemonLeague_1F_EventScript_002110EF::
	setobjectxyperm 0x3, 0x9, 0x2
	setobjectxyperm 0x4, 0xA, 0x2
	return

EverGrandeCity_PokemonLeague_1F_EventScript_002110FE::
	setvar 0x800B, 0x1
	call 0x082429B8
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_0021110C::
	lock
	faceplayer
	message 0x0824390F
	waitmessage
	pokemart 0x08211124
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x211123, 0x13
EverGrandeCity_PokemonLeague_1F_EventScript_00211136::
	lockall
	checkflag 0x107
	goto_if 0x1, EverGrandeCity_PokemonLeague_1F_EventScript_002111BB
	getplayerxy 0x4000, 0x4001
	compare_var_to_value 0x4000, 0xB
	call_if 0x4, EverGrandeCity_PokemonLeague_1F_EventScript_00211198
	compare_var_to_value 0x4000, 0x8
	call_if 0x3, EverGrandeCity_PokemonLeague_1F_EventScript_002111A3
	message 0x082111E8
	waitmessage
	delay 0x4B
	checkflag 0x86C
	goto_if 0x0, EverGrandeCity_PokemonLeague_1F_EventScript_002111AE
	closemessage
	applymovement 0x3, 0x082111E2
	applymovement 0x4, 0x082111E5
	waitmovement 0x0
	delay 0xA
	playfanfare 0x171
	message 0x08211267
	waitmessage
	waitfanfare
	closemessage
	moveobjectoffscreen 0x3
	moveobjectoffscreen 0x4
	setflag 0x107
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_00211198::
	applymovement 0xFF, 0x082111DA
	waitmovement 0x0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_002111A3::
	applymovement 0xFF, 0x082111DE
	waitmovement 0x0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_002111AE::
	playse 0x20
	loadword 0x0, 0x08211231
	callstd 0x4
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_002111BB::
	applymovement 0x800F, 0x08243621
	waitmovement 0x0
	loadword 0x0, 0x08211267
	callstd 0x4
	closemessage
	applymovement 0x800F, 0x08243625
	waitmovement 0x0
	releaseall
	end
