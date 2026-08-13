@ FallarborTown scripts (JP map g0 m13 @ 0x081E5E63)

FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_EventScript_001E5E69
	.byte 0

FallarborTown_EventScript_001E5E69::
	setflag 0x873
	setvar 0x4086, 0x0
	clearflag 0x10E
	end

FallarborTown_EventScript_001E5E75::
	lock
	faceplayer
	checkflag 0x8B
	goto_if 0x1, FallarborTown_EventScript_001E5E8A
	loadword 0x0, 0x081E5ED4
	callstd 0x4
	release
	end

FallarborTown_EventScript_001E5E8A::
	loadword 0x0, 0x081E5F09
	callstd 0x4
	release
	end

FallarborTown_EventScript_001E5E94::
	loadword 0x0, 0x081E5F4A
	callstd 0x2
	end

FallarborTown_EventScript_001E5E9D::
	loadword 0x0, 0x081E5F85
	callstd 0x2
	end

FallarborTown_EventScript_001E5EA6::
	lock
	faceplayer
	waitse
	playmoncry 0x15E, 0x0
	loadword 0x0, 0x081E5F7A
	callstd 0x4
	waitdooranim
	release
	end

FallarborTown_EventScript_001E5EB9::
	loadword 0x0, 0x081E5FF7
	callstd 0x3
	end

FallarborTown_EventScript_001E5EC2::
	loadword 0x0, 0x081E601B
	callstd 0x3
	end

FallarborTown_EventScript_001E5ECB::
	loadword 0x0, 0x081E603A
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x1e5ed4, 0x185
