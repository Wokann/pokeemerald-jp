@ SlateportCity_BattleTentBattleRoom scripts (JP map g9 m4 @ 0x081FBC59)

SlateportCity_BattleTentBattleRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_BattleTentBattleRoom_EventScript_001FBC69
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentBattleRoom_MapScriptTable_001FBC93
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentBattleRoom_MapScriptTable_001FBCAD
	.byte 0

SlateportCity_BattleTentBattleRoom_EventScript_001FBC69::
	call SlateportCity_BattleTentBattleRoom_EventScript_001FBC6F
	end

SlateportCity_BattleTentBattleRoom_EventScript_001FBC6F::
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, SlateportCity_BattleTentBattleRoom_EventScript_001FBC87
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, SlateportCity_BattleTentBattleRoom_EventScript_001FBC8D
	return

SlateportCity_BattleTentBattleRoom_EventScript_001FBC87::
	setvar 0x4011, 0x64
	return

SlateportCity_BattleTentBattleRoom_EventScript_001FBC8D::
	setvar 0x4011, 0x69
	return

SlateportCity_BattleTentBattleRoom_MapScriptTable_001FBC93::
	map_script_2 0x4001, 0x0, SlateportCity_BattleTentBattleRoom_EventScript_001FBC9D
	.2byte 0

SlateportCity_BattleTentBattleRoom_EventScript_001FBC9D::
	setvar 0x4001, 0x1
	hideobject_at 0xFF, 0x503
	hideobject_at 0x2, 0x904
	end

SlateportCity_BattleTentBattleRoom_MapScriptTable_001FBCAD::
	map_script_2 0x4000, 0x0, 0x081FBCB7
	.2byte 0

	.incbin "baserom_jp.gba", 0x1fbcb7, 0xd87
