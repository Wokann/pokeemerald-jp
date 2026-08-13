@ BattleFrontier_BattlePikeRoomFinal scripts (JP map g26 m38 @ 0x08235259)

BattleFrontier_BattlePikeRoomFinal_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomFinal_MapScriptTable_00235264
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoomFinal_MapScriptTable_002352A5
	.byte 0

BattleFrontier_BattlePikeRoomFinal_MapScriptTable_00235264::
	map_script_2 0x4000, 0x0, BattleFrontier_BattlePikeRoomFinal_EventScript_0023526E
	.2byte 0

BattleFrontier_BattlePikeRoomFinal_EventScript_0023526E::
	delay 0x10
	applymovement 0x1, 0x082352A2
	waitmovement 0x0
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x3
	special CallFrontierUtilFunc
	lockall
	loadword 0x0, gJPText_002352B9
	callstd 0x4
	closemessage
	releaseall
	warp 0x1A22, 0xFF, 0x5, 0x6
	waitstate
	end

	.incbin "baserom_jp.gba", 0x2352a2, 0x3
BattleFrontier_BattlePikeRoomFinal_MapScriptTable_002352A5::
	map_script_2 0x4004, 0x0, BattleFrontier_BattlePikeRoomFinal_EventScript_002352AF
	.2byte 0

BattleFrontier_BattlePikeRoomFinal_EventScript_002352AF::
	setvar 0x4004, 0x1
	turnobject 0xFF, 0x2
	end

	.globl gJPText_002352B9
gJPText_002352B9: @ 0x082352B9
	.string "おめでとう　ございます⋯⋯\n"
	.string "さあ　こちらへ⋯⋯$"

