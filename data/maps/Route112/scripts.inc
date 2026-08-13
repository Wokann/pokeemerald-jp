@ Route112 scripts (JP map g0 m27 @ 0x081EAE8C)

Route112_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route112_EventScript_001EAE92
	.byte 0

Route112_EventScript_001EAE92::
	clearflag 0x9D
	setvar 0x40BD, 0x0
	end

Route112_EventScript_001EAE9B::
	lockall
	delay 0x28
	applymovement 0x1, 0x0824362B
	waitmovement 0x0
	delay 0x14
	loadword 0x0, 0x081EB023
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243625
	waitmovement 0x0
	delay 0x28
	applymovement 0x6, 0x08243627
	waitmovement 0x0
	delay 0x14
	loadword 0x0, 0x081EB047
	callstd 0x4
	closemessage
	applymovement 0x6, 0x08243625
	waitmovement 0x0
	delay 0x28
	applymovement 0x1, 0x0824362B
	waitmovement 0x0
	delay 0x14
	loadword 0x0, 0x081EB06C
	callstd 0x4
	closemessage
	applymovement 0x1, 0x08243625
	waitmovement 0x0
	delay 0x28
	applymovement 0x6, 0x08243627
	waitmovement 0x0
	delay 0x14
	loadword 0x0, 0x081EB08B
	callstd 0x4
	closemessage
	applymovement 0x6, 0x08243625
	waitmovement 0x0
	releaseall
	end

Route112_EventScript_001EAF2A::
	loadword 0x0, 0x081EB0EC
	callstd 0x3
	end

Route112_EventScript_001EAF33::
	loadword 0x0, 0x081EB10D
	callstd 0x3
	end

Route112_EventScript_001EAF3C::
	loadword 0x0, 0x081EB13A
	callstd 0x3
	end

Route112_EventScript_001EAF45::
	loadword 0x0, 0x081EB0B0
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x1eaf4e, 0x205
