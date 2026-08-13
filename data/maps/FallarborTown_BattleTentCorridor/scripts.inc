@ FallarborTown_BattleTentCorridor scripts (JP map g5 m2 @ 0x081F57D8)

FallarborTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_BattleTentCorridor_MapScriptTable_001F57DE
	.byte 0

FallarborTown_BattleTentCorridor_MapScriptTable_001F57DE::
	map_script_2 0x4000, 0x0, FallarborTown_BattleTentCorridor_EventScript_001F57E8
	.2byte 0

FallarborTown_BattleTentCorridor_EventScript_001F57E8::
	lockall
	setvar 0x4000, 0x1
	applymovement 0x1, 0x081F582C
	applymovement 0xFF, 0x081F582C
	waitmovement 0x0
	opendoor 0x2, 0x1
	waitmoncry
	applymovement 0x1, 0x081F5832
	applymovement 0xFF, 0x081F5831
	waitmovement 0x0
	closedoor 0x2, 0x1
	waitmoncry
	setvar 0x8006, 0x0
	warp 0x503, 0xFF, 0x4, 0x4
	waitstate
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1f582c, 0xee
