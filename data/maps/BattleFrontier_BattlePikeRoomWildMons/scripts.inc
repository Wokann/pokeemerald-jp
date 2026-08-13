@ BattleFrontier_BattlePikeRoomWildMons scripts (JP map g26 m39 @ 0x082352D1)

BattleFrontier_BattlePikeRoomWildMons_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePikeRoomWildMons_EventScript_00235331
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeRoomWildMons_MapScriptTable_002352E1
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeRoomWildMons_MapScriptTable_0023531D
	.byte 0

BattleFrontier_BattlePikeRoomWildMons_MapScriptTable_002352E1::
	map_script_2 0x4000, 0x0, BattleFrontier_BattlePikeRoomWildMons_EventScript_002352F3
	map_script_2 0x4001, 0x1, BattleFrontier_BattlePikeRoomWildMons_EventScript_00235301
	.2byte 0

BattleFrontier_BattlePikeRoomWildMons_EventScript_002352F3::
	setvar 0x4000, 0x1
	setvar 0x8004, 0x6
	special CallBattlePikeFunction
	end

BattleFrontier_BattlePikeRoomWildMons_EventScript_00235301::
	setvar 0x8004, 0x2
	setvar 0x8005, 0x0
	setvar 0x8006, 0x4
	special CallFrontierUtilFunc
	warp 0x1A22, 0xFF, 0x5, 0x6
	waitstate
	end

BattleFrontier_BattlePikeRoomWildMons_MapScriptTable_0023531D::
	map_script_2 0x4004, 0x0, BattleFrontier_BattlePikeRoomWildMons_EventScript_00235327
	.2byte 0

BattleFrontier_BattlePikeRoomWildMons_EventScript_00235327::
	setvar 0x4004, 0x1
	turnobject 0xFF, 0x2
	end

BattleFrontier_BattlePikeRoomWildMons_EventScript_00235331::
	call 0x082746FA
	setvar 0x8004, 0x1
	setvar 0x8005, 0x5
	special CallFrontierUtilFunc
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, BattleFrontier_BattlePikeRoomWildMons_EventScript_0023535A
	compare_var_to_value 0x800D, 0x3
	goto_if 0x1, BattleFrontier_BattlePikeRoomWildMons_EventScript_0023535A
	end

BattleFrontier_BattlePikeRoomWildMons_EventScript_0023535A::
	setvar 0x4001, 0x1
	end

	.incbin "baserom_jp.gba", 0x235360, 0x4ecc
