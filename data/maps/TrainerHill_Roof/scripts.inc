@ TrainerHill_Roof scripts (JP map g26 m65 @ 0x0823BFB6)

TrainerHill_Roof_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, 0x08276C52
	map_script MAP_SCRIPT_ON_FRAME_TABLE, 0x08276C9D
	.byte 0

TrainerHill_Roof_EventScript_0023BFC1::
	setvar 0x8004, 0xC
	special CallTrainerHillFunction
	lock
	faceplayer
	setvar 0x8004, 0x1
	special CallTrainerHillFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, TrainerHill_Roof_EventScript_0023BFF9
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, TrainerHill_Roof_EventScript_0023C001
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, TrainerHill_Roof_EventScript_0023C0B7

TrainerHill_Roof_EventScript_0023BFF9::
	loadword 0x0, 0x0823BD13
	callstd 0x4

TrainerHill_Roof_EventScript_0023C001::
	setvar 0x8004, 0x2
	special CallTrainerHillFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, TrainerHill_Roof_EventScript_0023C02F
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, TrainerHill_Roof_EventScript_0023C046
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, TrainerHill_Roof_EventScript_0023C063

TrainerHill_Roof_EventScript_0023C02F::
	loadword 0x0, 0x0823BDB3
	callstd 0x4
	playfanfare 0x16F
	message 0x0824393C
	waitfanfare
	waitmessage
	goto TrainerHill_Roof_EventScript_0023C063

TrainerHill_Roof_EventScript_0023C046::
	loadword 0x0, 0x0823BDB3
	callstd 0x4
	loadword 0x0, 0x08243947
	callstd 0x4
	loadword 0x0, 0x0823BDCF
	callstd 0x4
	goto TrainerHill_Roof_EventScript_0023C063

TrainerHill_Roof_EventScript_0023C063::
	setvar 0x8004, 0x3
	special CallTrainerHillFunction
	copyvar 0x8000, 0x800D
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, TrainerHill_Roof_EventScript_0023C091
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, TrainerHill_Roof_EventScript_0023C09F
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, TrainerHill_Roof_EventScript_0023C0AD

TrainerHill_Roof_EventScript_0023C091::
	loadword 0x0, 0x0823BDE9
	callstd 0x4
	goto TrainerHill_Roof_EventScript_0023C0AD
	end

TrainerHill_Roof_EventScript_0023C09F::
	loadword 0x0, 0x0823BE51
	callstd 0x4
	goto TrainerHill_Roof_EventScript_0023C0AD
	end

TrainerHill_Roof_EventScript_0023C0AD::
	loadword 0x0, 0x0823BE69
	callstd 0x4
	release
	end

TrainerHill_Roof_EventScript_0023C0B7::
	loadword 0x0, 0x0823BE69
	callstd 0x4
	release
	end

