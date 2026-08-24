@ Route119_WeatherInstitute_2F scripts (JP map g32 m1 @ 0x082414E5)

Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_EventScript_002414EB
	.byte 0

Route119_WeatherInstitute_2F_EventScript_002414EB::
	compare_var_to_value 0x40B3, 0x0
	call_if 0x1, Route119_WeatherInstitute_2F_EventScript_0024150B
	compare_var_to_value 0x40B3, 0x1
	call_if 0x1, Route119_WeatherInstitute_2F_EventScript_00241517
	checkflag 0x864
	call_if 0x1, Route119_WeatherInstitute_2F_EventScript_00241523
	end

Route119_WeatherInstitute_2F_EventScript_0024150B::
	setobjectxyperm 0x5, 0x1, 0x6
	setobjectmovementtype 0x5, 0xA
	return

Route119_WeatherInstitute_2F_EventScript_00241517::
	setobjectxyperm 0x5, 0x4, 0x6
	setobjectmovementtype 0x5, 0xA
	return

Route119_WeatherInstitute_2F_EventScript_00241523::
	setobjectxyperm 0x5, 0x2, 0x2
	setobjectmovementtype 0x5, 0x7
	return

	.incbin "baserom_jp.gba", 0x24152f, 0xe5
Route119_WeatherInstitute_2F_EventScript_00241614::
	loadword 0x0, 0x08241A04
	callstd 0x4
	setvar 0x4001, 0x181
	givemon 0x181, 0x19, 0xD1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route119_WeatherInstitute_2F_EventScript_0024164C
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route119_WeatherInstitute_2F_EventScript_00241674
	goto 0x0824423B
	end

Route119_WeatherInstitute_2F_EventScript_0024164C::
	call Route119_WeatherInstitute_2F_EventScript_002416A2
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route119_WeatherInstitute_2F_EventScript_002416B1
	call 0x082441B5
	call 0x08243460
	goto Route119_WeatherInstitute_2F_EventScript_002416B1
	end

Route119_WeatherInstitute_2F_EventScript_00241674::
	call Route119_WeatherInstitute_2F_EventScript_002416A2
	loadword 0x0, 0x08243EDB
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, Route119_WeatherInstitute_2F_EventScript_00241697
	call 0x082441C1
	goto Route119_WeatherInstitute_2F_EventScript_00241697
	end

Route119_WeatherInstitute_2F_EventScript_00241697::
	call 0x082441CA
	goto Route119_WeatherInstitute_2F_EventScript_002416B1
	end

Route119_WeatherInstitute_2F_EventScript_002416A2::
	playfanfare 0x172
	message 0x08241A56
	waitmessage
	waitfanfare
	bufferspeciesname 0x0, 0x181
	return

Route119_WeatherInstitute_2F_EventScript_002416B1::
	loadword 0x0, 0x08241A66
	callstd 0x4
	setflag 0x97
	release
	end

Route119_WeatherInstitute_2F_EventScript_002416BE::
	checkflag 0x864
	goto_if 0x1, Route119_WeatherInstitute_2F_EventScript_002416D1
	loadword 0x0, 0x08241AB4
	callstd 0x4
	release
	end

Route119_WeatherInstitute_2F_EventScript_002416D1::
	setvar 0x8004, 0x0
	checkflag 0x1BE
	call_if 0x1, Route119_WeatherInstitute_2F_EventScript_00241727
	checkflag 0x1BF
	call_if 0x1, Route119_WeatherInstitute_2F_EventScript_00241727
	compare_var_to_value 0x8004, 0x2
	goto_if 0x1, Route119_WeatherInstitute_2F_EventScript_0024172D
	checkflag 0x2
	call_if 0x0, Route119_WeatherInstitute_2F_EventScript_00241720
	specialvar 0x800D, GetUnusualWeatherMapNameAndType
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, Route119_WeatherInstitute_2F_EventScript_00241716
	loadword 0x0, 0x08241AF8
	callstd 0x4
	release
	end

Route119_WeatherInstitute_2F_EventScript_00241716::
	loadword 0x0, 0x08241B43
	callstd 0x4
	release
	end

Route119_WeatherInstitute_2F_EventScript_00241720::
	special CreateUnusualWeatherEvent
	setflag 0x2
	return

Route119_WeatherInstitute_2F_EventScript_00241727::
	addvar 0x8004, 0x1
	return

Route119_WeatherInstitute_2F_EventScript_0024172D::
	loadword 0x0, 0x08241B90
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x241737, 0x1b
Route119_WeatherInstitute_2F_EventScript_00241752::
	lock
	faceplayer
	checkflag 0x97
	goto_if 0x1, Route119_WeatherInstitute_2F_EventScript_002416BE
	goto Route119_WeatherInstitute_2F_EventScript_00241614
	end
