@ MtPyre_Exterior scripts (JP map g24 m21 @ 0x08216B49)

MtPyre_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Exterior_OnTransition
	.byte 0

MtPyre_Exterior_OnTransition:: @ 0x08216B4F
	call MtPyre_Exterior_EventScript_CheckEnterFromSummit
	end

MtPyre_Exterior_EventScript_CheckEnterFromSummit:: @ 0x08216B55
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_lt VAR_TEMP_1, 0xC, MtPyre_Exterior_EventScript_EnterFromSummit
	return

MtPyre_Exterior_EventScript_EnterFromSummit:: @ 0x08216B66
	setweather WEATHER_FOG_HORIZONTAL
	return

MtPyre_Exterior_EventScript_FogTrigger:: @ 0x08216B6A
	setweather WEATHER_FOG_HORIZONTAL
	resetweather
	end

MtPyre_Exterior_EventScript_SunTrigger:: @ 0x08216B6F
	setweather WEATHER_SUNNY
	resetweather
	end
