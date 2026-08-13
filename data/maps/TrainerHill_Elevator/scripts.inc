@ TrainerHill_Elevator scripts (JP map g26 m88 @ 0x0823C35E)

TrainerHill_Elevator_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TrainerHill_Elevator_MapScriptTable_0023C364
	.byte 0

TrainerHill_Elevator_MapScriptTable_0023C364::
	map_script_2 0x4004, 0x0, TrainerHill_Elevator_EventScript_0023C384
	.2byte 0

TrainerHill_Elevator_EventScript_0023C36E::
	end

TrainerHill_Elevator_EventScript_0023C36F::
	applymovement 0xFF, 0x0823C3FA
	waitmovement 0x0
	releaseall
	warp 0x1A41, 0xFF, 0xF, 0x5
	waitstate
	end

TrainerHill_Elevator_EventScript_0023C384::
	applymovement 0xFF, 0x0823C3F3
	waitmovement 0x0
	applymovement 0x1, 0x0823C3FD
	waitmovement 0x0
	lockall
	loadword 0x0, gJPText_0023BF72
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, TrainerHill_Elevator_EventScript_0023C36F
	releaseall
	applymovement 0x1, 0x0823C3FF
	waitmovement 0x0
	applymovement 0xFF, 0x0823C3EE
	waitmovement 0x0
	call TrainerHill_Elevator_EventScript_0023C3E8
	delay 0x19
	applymovement 0xFF, 0x0823C3F6
	waitmovement 0x0
	warp 0x1A3C, 0xFF, 0x11, 0x8
	waitstate
	end

	.incbin "baserom_jp.gba", 0x23c3dd, 0xb
TrainerHill_Elevator_EventScript_0023C3E8::
	waitse
	special ShakeScreenInElevator
	waitstate
	return

	.incbin "baserom_jp.gba", 0x23c3ee, 0x15
