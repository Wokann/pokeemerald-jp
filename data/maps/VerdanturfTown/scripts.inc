@ VerdanturfTown scripts (JP map g0 m14 @ 0x081E6059)

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_EventScript_001E605F
	.byte 0

VerdanturfTown_EventScript_001E605F::
	setflag 0x874
	setvar 0x4086, 0x0
	end

VerdanturfTown_EventScript_001E6068::
	lock
	faceplayer
	checkflag 0xC7
	goto_if 0x1, VerdanturfTown_EventScript_001E6087
	loadword 0x0, 0x081E60F0
	callstd 0x4
	applymovement 0x2, 0x08243625
	waitmovement 0x0
	release
	end

VerdanturfTown_EventScript_001E6087::
	loadword 0x0, 0x081E616F
	callstd 0x4
	applymovement 0x2, 0x08243625
	waitmovement 0x0
	release
	end

VerdanturfTown_EventScript_001E609B::
	loadword 0x0, 0x081E619C
	callstd 0x2
	end

VerdanturfTown_EventScript_001E60A4::
	loadword 0x0, 0x081E61FD
	callstd 0x2
	end

VerdanturfTown_EventScript_001E60AD::
	lock
	faceplayer
	checkflag 0xC7
	goto_if 0x1, VerdanturfTown_EventScript_001E60C2
	loadword 0x0, 0x081E623D
	callstd 0x4
	release
	end

VerdanturfTown_EventScript_001E60C2::
	loadword 0x0, 0x081E62B6
	callstd 0x4
	release
	end

VerdanturfTown_EventScript_001E60CC::
	loadword 0x0, 0x081E6305
	callstd 0x3
	end

VerdanturfTown_EventScript_001E60D5::
	loadword 0x0, 0x081E6324
	callstd 0x3
	end

VerdanturfTown_EventScript_001E60DE::
	loadword 0x0, 0x081E632E
	callstd 0x3
	end

VerdanturfTown_EventScript_001E60E7::
	loadword 0x0, 0x081E6350
	callstd 0x3
	end
