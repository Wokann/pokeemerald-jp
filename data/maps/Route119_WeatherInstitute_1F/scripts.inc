@ Route119_WeatherInstitute_1F scripts (JP map g32 m0 @ 0x082411E3)

Route119_WeatherInstitute_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_EventScript_002411E9
	.byte 0

Route119_WeatherInstitute_1F_EventScript_002411E9::
	compare_var_to_value 0x40B3, 0x0
	call_if 0x1, Route119_WeatherInstitute_1F_EventScript_002411F5
	end

Route119_WeatherInstitute_1F_EventScript_002411F5::
	setobjectxyperm 0x5, 0x0, 0x5
	setobjectmovementtype 0x5, 0xA
	return

Route119_WeatherInstitute_1F_EventScript_00241201::
	lock
	faceplayer
	special GetPlayerBigGuyGirlString
	compare_var_to_value 0x40B3, 0x0
	goto_if 0x1, Route119_WeatherInstitute_1F_EventScript_0024121B
	loadword 0x0, 0x082413A3
	callstd 0x4
	release
	end

Route119_WeatherInstitute_1F_EventScript_0024121B::
	loadword 0x0, 0x08241380
	callstd 0x4
	release
	end

Route119_WeatherInstitute_1F_EventScript_00241225::
	lock
	faceplayer
	checkflag 0x864
	goto_if 0x0, Route119_WeatherInstitute_1F_EventScript_00241262
	setvar 0x8004, 0x0
	checkflag 0x1BE
	call_if 0x1, Route119_WeatherInstitute_1F_EventScript_0024125C
	checkflag 0x1BF
	call_if 0x1, Route119_WeatherInstitute_1F_EventScript_0024125C
	compare_var_to_value 0x8004, 0x2
	goto_if 0x1, Route119_WeatherInstitute_1F_EventScript_00241262
	loadword 0x0, 0x0824142D
	callstd 0x4
	release
	end

Route119_WeatherInstitute_1F_EventScript_0024125C::
	addvar 0x8004, 0x1
	return

Route119_WeatherInstitute_1F_EventScript_00241262::
	loadword 0x0, 0x082413CC
	callstd 0x4
	release
	end

Route119_WeatherInstitute_1F_EventScript_0024126C::
	loadword 0x0, 0x08241490
	callstd 0x2
	end

Route119_WeatherInstitute_1F_EventScript_00241275::
	lockall
	loadword 0x0, 0x082414D3
	callstd 0x4
	closemessage
	call 0x0824310F
	releaseall
	end
