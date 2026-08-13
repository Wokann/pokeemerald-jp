@ BattleFrontier_BattleArenaCorridor scripts (JP map g26 m29 @ 0x08230081)

BattleFrontier_BattleArenaCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaCorridor_MapScriptTable_00230087
	.byte 0

BattleFrontier_BattleArenaCorridor_MapScriptTable_00230087::
	map_script_2 0x4000, 0x0, BattleFrontier_BattleArenaCorridor_EventScript_00230091
	.2byte 0

BattleFrontier_BattleArenaCorridor_EventScript_00230091::
	delay 0x10
	setvar 0x4000, 0x1
	applymovement 0x1, 0x082300F7
	applymovement 0xFF, 0x082300DF
	waitmovement 0x0
	applymovement 0x1, 0x0823010C
	waitmovement 0x0
	loadword 0x0, gJPText_00230111
	callstd 0x3
	applymovement 0x1, 0x0823010E
	waitmovement 0x0
	applymovement 0xFF, 0x082300F4
	waitmovement 0x0
	setvar 0x8006, 0x0
	warp 0x1A1E, 0xFF, 0x7, 0x5
	waitstate
	end

	.incbin "baserom_jp.gba", 0x2300df, 0x32
	.globl gJPText_00230111
gJPText_00230111: @ 0x08230111
	.string "このさきが　たいせんの　へやと　なりますぞ！\n"
	.string "どうぞ　おはいり　くだされ！$"

