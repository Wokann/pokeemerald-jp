	checkpartymove 0x39
	compare_var_to_value 0x800D, 0x6
	goto_if 0x1, 0x8242F62
	bufferpartymonnick 0x0, 0x800D
	setfieldeffectarg 0x0, 0x800D
	lockall 
	loadword 0x0, 0x8243C8B
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8242F61
	loadword 0x0, 0x8243CAE
	callstd 0x4
	dofieldeffect 0x9
	releaseall 
	end 

Common_EventScript_SetupRivalGfxId:: @ 0x08242F63
	checkplayergender 
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8242F7B
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8242F81
	end 
	setvar 0x4010, 0x69
	return 
	setvar 0x4010, 0x64
	return 

Common_EventScript_SetupRivalOnBikeGfxId:: @ 0x08242F87
	checkplayergender 
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8242F9F
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8242FA5
	end 

EventScript_SetupRivalOnBikeGfxIdFemale:: @ 0x08242F9F
	setvar 0x4013, 0x6A
	return 

EventScript_SetupRivalOnBikeGfxIdMale:: @ 0x08242FA5
	setvar 0x4013, 0x65
	return 
	checkplayergender 
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8242FC3
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8242FC9
	end 
	setvar 0x4010, 0x64
	return 
	setvar 0x4010, 0x69
	return 
	copyvar 0x8000, 0x8008
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x824302D
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x8243037
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, 0x824304A
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, 0x824305A
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, 0x8243073
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, 0x8243089
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, 0x824309C
	compare_var_to_value 0x8000, 0x8
	goto_if 0x1, 0x82430C1
	end 
	settrainerflag 0x140
	settrainerflag 0x141
	settrainerflag 0x23B
	return 
	settrainerflag 0xB3
	settrainerflag 0x1A9
	settrainerflag 0x1AA
	settrainerflag 0x23C
	settrainerflag 0x23E
	settrainerflag 0x23D
	return 
	settrainerflag 0xBF
	settrainerflag 0xC2
	settrainerflag 0x143
	settrainerflag 0x289
	settrainerflag 0x322
	return 
	settrainerflag 0xC9
	settrainerflag 0xCB
	settrainerflag 0xCD
	settrainerflag 0x288
	settrainerflag 0x28A
	settrainerflag 0xCC
	settrainerflag 0xCA
	settrainerflag 0x1F5
	return 
	settrainerflag 0x47
	settrainerflag 0x48
	settrainerflag 0x49
	settrainerflag 0x4A
	settrainerflag 0x59
	settrainerflag 0x5A
	settrainerflag 0x5B
	return 
	settrainerflag 0x191
	settrainerflag 0x28E
	settrainerflag 0x28F
	settrainerflag 0x194
	settrainerflag 0x192
	settrainerflag 0x323
	return 
	settrainerflag 0xE9
	settrainerflag 0xEA
	settrainerflag 0xEB
	settrainerflag 0xF4
	settrainerflag 0xF5
	settrainerflag 0xF6
	settrainerflag 0x23F
	settrainerflag 0x246
	settrainerflag 0x247
	settrainerflag 0x248
	settrainerflag 0x24F
	settrainerflag 0x249
	return 
	settrainerflag 0x265
	settrainerflag 0x266
	settrainerflag 0x76
	settrainerflag 0x80
	settrainerflag 0x81
	settrainerflag 0x82
	settrainerflag 0x83
	settrainerflag 0x12D
	settrainerflag 0x1F6
	settrainerflag 0x73
	return 

Common_EventScript_ShowBagIsFull:: @ 0x082430E0
	loadword 0x0, 0x8243977
	callstd 0x4
	release 
	end 
	loadword 0x0, 0x8243977
	callstd 0x4
	return 
	loadword 0x0, gText_NoRoomLeftForAnother
	callstd 0x4
	release 
	end 
	loadword 0x0, gText_NoRoomLeftForAnother
	callstd 0x4
	return 

Common_EventScript_SetAbnormalWeather:: @ 0x08243106
	setweather 0xF
	return 
	playfanfare 0x171
	waitfanfare 
	return 
	fadescreen 0x1
	playfanfare 0x170
	waitfanfare 
	special HealPlayerParty
	fadescreen 0x0
	return 
