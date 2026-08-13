@ VerdanturfTown_BattleTentCorridor scripts (JP map g6 m1 @ 0x081F6B12)

VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_MapScriptTable_001F6B18
	.byte 0

VerdanturfTown_BattleTentCorridor_MapScriptTable_001F6B18::
	map_script_2 0x4000, 0x0, VerdanturfTown_BattleTentCorridor_EventScript_001F6B22
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_001F6B22::
	lockall
	setvar 0x4000, 0x1
	applymovement 0x1, 0x081F6B66
	applymovement 0xFF, 0x081F6B66
	waitmovement 0x0
	opendoor 0x2, 0x1
	waitmoncry
	applymovement 0x1, 0x081F6B6C
	applymovement 0xFF, 0x081F6B6B
	waitmovement 0x0
	closedoor 0x2, 0x1
	waitmoncry
	setvar 0x8006, 0x0
	warp 0x602, 0xFF, 0x6, 0x5
	waitstate
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1f6b66, 0x13f
