@ BattleFrontier_BattlePikeCorridor scripts (JP map g26 m35 @ 0x08233C01)

BattleFrontier_BattlePikeCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeCorridor_MapScriptTable_00233C0C
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeCorridor_MapScriptTable_00233C87
	.byte 0

BattleFrontier_BattlePikeCorridor_MapScriptTable_00233C0C::
	map_script_2 0x4000, 0x0, BattleFrontier_BattlePikeCorridor_EventScript_00233C16
	.2byte 0

BattleFrontier_BattlePikeCorridor_EventScript_00233C16::
	delay 0x10
	setvar 0x8004, 0x2
	setvar 0x8005, 0x2
	setvar 0x8006, 0x1
	special CallFrontierUtilFunc
	setvar 0x8004, 0x14
	special CallBattlePikeFunction
	setvar 0x8004, 0x18
	setvar 0x8005, 0x1
	special CallBattlePikeFunction
	applymovement 0xFF, 0x08233C9B
	applymovement 0x1, 0x08233CA2
	waitmovement 0x0
	lockall
	loadword 0x0, gJPText_00233CA7
	callstd 0x4
	closemessage
	releaseall
	applymovement 0xFF, 0x08233C9E
	waitmovement 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x63
	special CallFrontierUtilFunc
	call 0x08233520
	warpsilent 0x1A24, 0xFF, 0x6, 0xA
	waitstate
	end

BattleFrontier_BattlePikeCorridor_MapScriptTable_00233C87::
	map_script_2 0x4001, 0x0, BattleFrontier_BattlePikeCorridor_EventScript_00233C91
	.2byte 0

BattleFrontier_BattlePikeCorridor_EventScript_00233C91::
	setvar 0x4001, 0x1
	turnobject 0xFF, 0x2
	end

	.incbin "baserom_jp.gba", 0x233c9b, 0xc
	.globl gJPText_00233CA7
gJPText_00233CA7: @ 0x08233CA7
	.string "⋯⋯　バトルゲーム　スタートです！$"

