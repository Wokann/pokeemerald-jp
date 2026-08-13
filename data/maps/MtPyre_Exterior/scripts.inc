@ MtPyre_Exterior scripts (JP map g24 m21 @ 0x08216B49)

MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_EventScript_00216B4F
	.byte 0

MtPyre_Exterior_EventScript_00216B4F::
	call MtPyre_Exterior_EventScript_00216B55
	end

MtPyre_Exterior_EventScript_00216B55::
	getplayerxy 0x4000, 0x4001
	compare_var_to_value 0x4001, 0xC
	goto_if 0x0, MtPyre_Exterior_EventScript_00216B66
	return

MtPyre_Exterior_EventScript_00216B66::
	setweather 0x6
	return

MtPyre_Exterior_EventScript_00216B6A::
	setweather 0x6
	resetweather
	end

MtPyre_Exterior_EventScript_00216B6F::
	setweather 0x2
	resetweather
	end

