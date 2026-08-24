@ PetalburgCity_Gym scripts (JP map g8 m1 @ 0x081F8520)

PetalburgCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_EventScript_001F8535
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_EventScript_001F85C4
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_MapScriptTable_001F8622
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_MapScriptTable_001F8631
	.byte 0

PetalburgCity_Gym_EventScript_001F8535::
	compare_var_to_value 0x4085, 0x6
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F854C
	compare_var_to_value 0x4085, 0x7
	call_if 0x4, PetalburgCity_Gym_EventScript_001F8596
	end

PetalburgCity_Gym_EventScript_001F854C::
	setvar 0x8005, 0x1
	call PetalburgCity_Gym_EventScript_001F91F5
	checktrainerflag 0x47
	call_if 0x1, PetalburgCity_Gym_EventScript_001F9216
	checktrainerflag 0x59
	call_if 0x1, PetalburgCity_Gym_EventScript_001F9237
	checktrainerflag 0x48
	call_if 0x1, PetalburgCity_Gym_EventScript_001F9258
	checktrainerflag 0x5A
	call_if 0x1, PetalburgCity_Gym_EventScript_001F9279
	checktrainerflag 0x49
	call_if 0x1, PetalburgCity_Gym_EventScript_001F929A
	checktrainerflag 0x5B
	call_if 0x1, PetalburgCity_Gym_EventScript_001F92BB
	checktrainerflag 0x4A
	call_if 0x1, PetalburgCity_Gym_EventScript_001F92DC
	end

PetalburgCity_Gym_EventScript_001F8596::
	setvar 0x8005, 0x1
	call PetalburgCity_Gym_EventScript_001F91F5
	call PetalburgCity_Gym_EventScript_001F9216
	call PetalburgCity_Gym_EventScript_001F9237
	call PetalburgCity_Gym_EventScript_001F9258
	call PetalburgCity_Gym_EventScript_001F9279
	call PetalburgCity_Gym_EventScript_001F929A
	call PetalburgCity_Gym_EventScript_001F92BB
	call PetalburgCity_Gym_EventScript_001F92DC
	return

PetalburgCity_Gym_EventScript_001F85C4::
	compare_var_to_value 0x4085, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F85E4
	compare_var_to_value 0x4085, 0x6
	call_if 0x0, PetalburgCity_Gym_EventScript_001F85EC
	checkflag 0x864
	call_if 0x1, PetalburgCity_Gym_EventScript_001F85F4
	end

PetalburgCity_Gym_EventScript_001F85E4::
	setobjectxyperm 0xA, 0x5, 0x6C
	return

PetalburgCity_Gym_EventScript_001F85EC::
	setobjectxyperm 0x1, 0x4, 0x6B
	return

PetalburgCity_Gym_EventScript_001F85F4::
	setorcopyvar 0x8015, 0x10D
	specialvar 0x800D, IsTrainerReadyForRematch
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F861C
	compare_var_to_value 0x4085, 0x8
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F861C
	setobjectxyperm 0x1, 0x4, 0x6B
	return

PetalburgCity_Gym_EventScript_001F861C::
	setvar 0x4085, 0x8
	end

PetalburgCity_Gym_MapScriptTable_001F8622::
	map_script_2 0x4085, 0x1, PetalburgCity_Gym_EventScript_001F862C
	.2byte 0

PetalburgCity_Gym_EventScript_001F862C::
	turnobject 0xFF, 0x2
	end

PetalburgCity_Gym_MapScriptTable_001F8631::
	map_script_2 0x4085, 0x1, PetalburgCity_Gym_EventScript_001F863B
	.2byte 0

PetalburgCity_Gym_EventScript_001F863B::
	lockall
	loadword 0x0, PetalburgCity_Gym_Text_DadSoDidItWorkOut
	callstd 0x4
	loadword 0x0, PetalburgCity_Gym_Text_WallyThankYouBye
	callstd 0x4
	closemessage
	applymovement 0xFF, 0x0824362D
	applymovement 0xA, 0x081F8683
	waitmovement 0x0
	playse 0x9
	removeobject 0xA
	setflag 0x2D6
	delay 0x1E
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	loadword 0x0, PetalburgCity_Gym_Text_DadGoCollectBadges
	callstd 0x4
	setvar 0x4085, 0x2
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1f8683, 0x5
PetalburgCity_Gym_EventScript_001F8688::
	lock
	faceplayer
	copyvar 0x8000, 0x4085
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F89E1
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F89EB
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F89F5
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F89FF
	compare_var_to_value 0x8000, 0x6
	goto_if 0x1, 0x081F8AD2
	compare_var_to_value 0x8000, 0x7
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8A17
	compare_var_to_value 0x8000, 0x8
	goto_if 0x1, 0x081F8A4A
	loadword 0x0, PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon
	callstd 0x4
	closemessage
	copyvar 0x8000, 0x800C
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8717
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8722
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F872D
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8738
	end

PetalburgCity_Gym_EventScript_001F8717::
	setvar 0x8008, 0x0
	goto PetalburgCity_Gym_EventScript_001F8743
	end

PetalburgCity_Gym_EventScript_001F8722::
	setvar 0x8008, 0x1
	goto PetalburgCity_Gym_EventScript_001F8743
	end

PetalburgCity_Gym_EventScript_001F872D::
	setvar 0x8008, 0x2
	goto PetalburgCity_Gym_EventScript_001F8743
	end

PetalburgCity_Gym_EventScript_001F8738::
	setvar 0x8008, 0x3
	goto PetalburgCity_Gym_EventScript_001F8743
	end

PetalburgCity_Gym_EventScript_001F8743::
	addobject 0xA
	playse 0x8
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F88C8
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F88DA
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, PetalburgCity_Gym_EventScript_001F88F6
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, PetalburgCity_Gym_EventScript_001F88F6
	loadword 0x0, PetalburgCity_Gym_Text_WallyIdLikeAPokemon
	callstd 0x4
	loadword 0x0, PetalburgCity_Gym_Text_DadOhYoureWallyRight
	callstd 0x4
	loadword 0x0, PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon
	callstd 0x4
	loadword 0x0, PetalburgCity_Gym_Text_DadHmISee
	callstd 0x4
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F895E
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F8969
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, PetalburgCity_Gym_EventScript_001F897B
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, PetalburgCity_Gym_EventScript_001F898D
	loadword 0x0, PetalburgCity_Gym_Text_DadPlayerGoWithWally
	callstd 0x4
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F899F
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F89AA
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, PetalburgCity_Gym_EventScript_001F89B5
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, PetalburgCity_Gym_EventScript_001F89C0
	loadword 0x0, PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon
	callstd 0x4
	loadword 0x0, PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall
	callstd 0x4
	loadword 0x0, PetalburgCity_Gym_Text_WallyOhWowThankYou
	callstd 0x4
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F8A09
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F8A0A
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, PetalburgCity_Gym_EventScript_001F8A15
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, PetalburgCity_Gym_EventScript_001F8A16
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F89CB
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F89D6
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, PetalburgCity_Gym_EventScript_001F89CB
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, PetalburgCity_Gym_EventScript_001F89CB
	loadword 0x0, PetalburgCity_Gym_Text_WouldYouReallyComeWithMe
	callstd 0x4
	closemessage
	setflag 0x4001
	playbgm 0x1A4, 0x0
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F890F
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F8928
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, PetalburgCity_Gym_EventScript_001F893A
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, PetalburgCity_Gym_EventScript_001F894C
	removeobject 0xA
	setflag 0x2D8
	setvar 0x4085, 0x1
	setvar 0x4057, 0x2
	clearflag 0x2D6
	clearflag 0x362
	setflag 0x379
	special InitBirchState
	warp 0x0, 0xFF, 0xF, 0x8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_001F88C8::
	applymovement 0x1, 0x0824362D
	applymovement 0xA, 0x081F8D82
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F88DA::
	applymovement 0xA, 0x081F8D78
	waitmovement 0x0
	applymovement 0x1, 0x0824362B
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F88F6::
	applymovement 0x1, 0x0824362D
	applymovement 0xFF, 0x0824362D
	applymovement 0xA, 0x081F8D82
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F890F::
	applymovement 0x1, 0x0824362D
	applymovement 0xA, 0x081F8D99
	applymovement 0xFF, 0x081F8DA8
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F8928::
	applymovement 0xA, 0x081F8D89
	applymovement 0xFF, 0x081F8DA0
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F893A::
	applymovement 0xA, 0x081F8D99
	applymovement 0xFF, 0x081F8DB2
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F894C::
	applymovement 0xA, 0x081F8D91
	applymovement 0xFF, 0x081F8DBA
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F895E::
	applymovement 0x1, 0x08243629
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F8969::
	applymovement 0x1, 0x0824362D
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F897B::
	applymovement 0x1, 0x0824362B
	applymovement 0xFF, 0x08243627
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F898D::
	applymovement 0x1, 0x08243627
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F899F::
	applymovement 0x1, 0x0824362D
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F89AA::
	applymovement 0x1, 0x0824362B
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F89B5::
	applymovement 0x1, 0x0824362D
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F89C0::
	applymovement 0x1, 0x0824362D
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F89CB::
	applymovement 0xA, 0x08243621
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F89D6::
	applymovement 0xA, 0x0824362D
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F89E1::
	loadword 0x0, 0x081F97E8
	callstd 0x4
	release
	end

PetalburgCity_Gym_EventScript_001F89EB::
	loadword 0x0, 0x081F987A
	callstd 0x4
	release
	end

PetalburgCity_Gym_EventScript_001F89F5::
	loadword 0x0, 0x081F98EE
	callstd 0x4
	release
	end

PetalburgCity_Gym_EventScript_001F89FF::
	loadword 0x0, 0x081F98EE
	callstd 0x4
	release
	end

PetalburgCity_Gym_EventScript_001F8A09::
	return

PetalburgCity_Gym_EventScript_001F8A0A::
	applymovement 0x1, 0x0824362D
	waitmovement 0x0
	return

PetalburgCity_Gym_EventScript_001F8A15::
	return

PetalburgCity_Gym_EventScript_001F8A16::
	return

PetalburgCity_Gym_EventScript_001F8A17::
	call PetalburgCity_Gym_EventScript_001F8A65
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8AB4
	checkflag 0xA9
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8A43
	checkflag 0x864
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8DC4
	loadword 0x0, 0x081F9B88
	callstd 0x4
	release
	end

PetalburgCity_Gym_EventScript_001F8A43::
	call PetalburgCity_Gym_EventScript_001F8B69
	release
	end

	.incbin "baserom_jp.gba", 0x1f8a4a, 0x1b
PetalburgCity_Gym_EventScript_001F8A65::
	specialvar 0x800D, IsEnigmaBerryValid
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8AAE
	checkitem 0xAF, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8AAE
	checkpcitem 0xAF, 0x1
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8AAE
	compare_var_to_value 0x402D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8AAE
	loadword 0x0, 0x082637C2
	callstd 0x4
	setvar 0x800D, 0x1
	return

PetalburgCity_Gym_EventScript_001F8AAE::
	setvar 0x800D, 0x0
	return

PetalburgCity_Gym_EventScript_001F8AB4::
	setorcopyvar 0x8000, 0xAF
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430E0
	setvar 0x402D, 0x0
	release
	end

	.incbin "baserom_jp.gba", 0x1f8ad2, 0x97
PetalburgCity_Gym_EventScript_001F8B69::
	setorcopyvar 0x8000, 0x14A
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x082430EA
	setflag 0xA9
	loadword 0x0, 0x081F9A94
	callstd 0x4
	return

	.incbin "baserom_jp.gba", 0x1f8b8c, 0x238
PetalburgCity_Gym_EventScript_001F8DC4::
	loadword 0x0, 0x081F9BE0
	callstd 0x4
	release
	end

PetalburgCity_Gym_EventScript_001F8DCE::
	lockall
	compare_var_to_value 0x4085, 0x6
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x7
	setvar 0x8009, 0x55
	loadword 0x0, 0x081FA31E
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F8E03::
	closemessage
	delay 0x1E
	warpdoor 0x801, 0xFF, 0x8008, 0x8009
	waitstate
	releaseall
	end

PetalburgCity_Gym_EventScript_001F8E12::
	releaseall
	end

PetalburgCity_Gym_EventScript_001F8E14::
	loadword 0x0, 0x081FA300
	callstd 0x4
	releaseall
	end

PetalburgCity_Gym_EventScript_001F8E1E::
	lockall
	compare_var_to_value 0x4085, 0x6
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x1
	setvar 0x8009, 0x62
	loadword 0x0, 0x081FA360
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F8E53::
	lockall
	checktrainerflag 0x47
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x7
	setvar 0x8009, 0x2E
	loadword 0x0, 0x081FA385
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F8E86::
	lockall
	checktrainerflag 0x47
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x1
	setvar 0x8009, 0x3B
	loadword 0x0, 0x081FA3A9
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F8EB9::
	lockall
	checktrainerflag 0x59
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x7
	setvar 0x8009, 0x3B
	loadword 0x0, 0x081FA3A9
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F8EEC::
	lockall
	checktrainerflag 0x59
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x1
	setvar 0x8009, 0x48
	loadword 0x0, 0x081FA3CC
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F8F1F::
	lockall
	checktrainerflag 0x48
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x1
	setvar 0x8009, 0x14
	loadword 0x0, 0x081FA3F0
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F8F52::
	lockall
	checktrainerflag 0x5A
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x7
	setvar 0x8009, 0x14
	loadword 0x0, 0x081FA3F0
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F8F85::
	lockall
	checktrainerflag 0x5A
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x1
	setvar 0x8009, 0x21
	loadword 0x0, 0x081FA413
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F8FB8::
	lockall
	checktrainerflag 0x49
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x7
	setvar 0x8009, 0x21
	loadword 0x0, 0x081FA413
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F8FEB::
	lockall
	checktrainerflag 0x5B
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x1
	setvar 0x8009, 0x7
	loadword 0x0, 0x081FA437
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

PetalburgCity_Gym_EventScript_001F901E::
	lockall
	checktrainerflag 0x4A
	goto_if 0x0, PetalburgCity_Gym_EventScript_001F8E14
	setvar 0x8008, 0x7
	setvar 0x8009, 0x7
	loadword 0x0, 0x081FA437
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E03
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F8E12
	end

	.incbin "baserom_jp.gba", 0x1f9051, 0x1a4
PetalburgCity_Gym_EventScript_001F91F5::
	setvar 0x8004, 0x1
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93DD
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93E2
	call PetalburgCity_Gym_EventScript_001F92FD
	return

PetalburgCity_Gym_EventScript_001F9216::
	setvar 0x8004, 0x2
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93DD
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93E2
	call PetalburgCity_Gym_EventScript_001F9322
	return

PetalburgCity_Gym_EventScript_001F9237::
	setvar 0x8004, 0x3
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93DD
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93E2
	call PetalburgCity_Gym_EventScript_001F9347
	return

PetalburgCity_Gym_EventScript_001F9258::
	setvar 0x8004, 0x4
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93DD
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93E2
	call PetalburgCity_Gym_EventScript_001F936C
	return

PetalburgCity_Gym_EventScript_001F9279::
	setvar 0x8004, 0x5
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93DD
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93E2
	call PetalburgCity_Gym_EventScript_001F937F
	return

PetalburgCity_Gym_EventScript_001F929A::
	setvar 0x8004, 0x6
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93DD
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93E2
	call PetalburgCity_Gym_EventScript_001F93A4
	return

PetalburgCity_Gym_EventScript_001F92BB::
	setvar 0x8004, 0x7
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93DD
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93E2
	call PetalburgCity_Gym_EventScript_001F93B7
	return

PetalburgCity_Gym_EventScript_001F92DC::
	setvar 0x8004, 0x8
	compare_var_to_value 0x8005, 0x0
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93DD
	compare_var_to_value 0x8005, 0x1
	call_if 0x1, PetalburgCity_Gym_EventScript_001F93E2
	call PetalburgCity_Gym_EventScript_001F93CA
	return

PetalburgCity_Gym_EventScript_001F92FD::
	setmetatile 0x6, 0x55, 0x210, 0x0
	setmetatile 0x7, 0x55, 0x211, 0x0
	setmetatile 0x1, 0x62, 0x210, 0x0
	setmetatile 0x2, 0x62, 0x211, 0x0
	return

PetalburgCity_Gym_EventScript_001F9322::
	setmetatile 0x6, 0x2E, 0x210, 0x0
	setmetatile 0x7, 0x2E, 0x211, 0x0
	setmetatile 0x1, 0x3B, 0x210, 0x0
	setmetatile 0x2, 0x3B, 0x211, 0x0
	return

PetalburgCity_Gym_EventScript_001F9347::
	setmetatile 0x6, 0x3B, 0x210, 0x0
	setmetatile 0x7, 0x3B, 0x211, 0x0
	setmetatile 0x1, 0x48, 0x210, 0x0
	setmetatile 0x2, 0x48, 0x211, 0x0
	return

PetalburgCity_Gym_EventScript_001F936C::
	setmetatile 0x1, 0x14, 0x210, 0x0
	setmetatile 0x2, 0x14, 0x211, 0x0
	return

PetalburgCity_Gym_EventScript_001F937F::
	setmetatile 0x6, 0x14, 0x210, 0x0
	setmetatile 0x7, 0x14, 0x211, 0x0
	setmetatile 0x1, 0x21, 0x210, 0x0
	setmetatile 0x2, 0x21, 0x211, 0x0
	return

PetalburgCity_Gym_EventScript_001F93A4::
	setmetatile 0x6, 0x21, 0x210, 0x0
	setmetatile 0x7, 0x21, 0x211, 0x0
	return

PetalburgCity_Gym_EventScript_001F93B7::
	setmetatile 0x1, 0x7, 0x210, 0x0
	setmetatile 0x2, 0x7, 0x211, 0x0
	return

PetalburgCity_Gym_EventScript_001F93CA::
	setmetatile 0x6, 0x7, 0x210, 0x0
	setmetatile 0x7, 0x7, 0x211, 0x0
	return

PetalburgCity_Gym_EventScript_001F93DD::
	special PetalburgGymSpecial1
	waitstate
	return

PetalburgCity_Gym_EventScript_001F93E2::
	special PetalburgGymSpecial2
	return

PetalburgCity_Gym_EventScript_001F93E6::
	lock
	faceplayer
	checkflag 0x4F4
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F93FB
	loadword 0x0, 0x081F9C26
	callstd 0x4
	release
	end

PetalburgCity_Gym_EventScript_001F93FB::
	loadword 0x0, 0x081F9D34
	callstd 0x4
	release
	end

PetalburgCity_Gym_EventScript_001F9405::
	lockall
	checkflag 0x86B
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F9425
	goto PetalburgCity_Gym_EventScript_001F942F
	end

PetalburgCity_Gym_EventScript_001F9415::
	lockall
	checkflag 0x86B
	goto_if 0x1, PetalburgCity_Gym_EventScript_001F9425
	goto PetalburgCity_Gym_EventScript_001F942F
	end

PetalburgCity_Gym_EventScript_001F9425::
	loadword 0x0, 0x081FA489
	callstd 0x4
	releaseall
	end

PetalburgCity_Gym_EventScript_001F942F::
	loadword 0x0, 0x081FA47B
	callstd 0x4
	releaseall
	end

PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon:
	.string "パパ“ん？\p"
	.string "{PLAYER}じゃ　ないか！\n"
	.string "そうか　ひっこしが　おわったんだね\p"
	.string "それにしても\n"
	.string "よく　ここまで　ひとりで　これたな\p"
	.string "なるほど⋯⋯\n"
	.string "ポケモンと　いっしょ　なのか\p"
	.string "ふむ⋯⋯　じゃあ　{PLAYER}も\n"
	.string "わたしの　ように\l"
	.string "ポケモントレーナーに　なるのか\p"
	.string "それは　たのしみ　だな！$"

PetalburgCity_Gym_Text_WallyIdLikeAPokemon:
	.string "あの⋯⋯　ぼく⋯⋯\n"
	.string "ポケモンが　ほしいん　ですけど⋯⋯$"

PetalburgCity_Gym_Text_DadOhYoureWallyRight:
	.string "パパ“ん？　きみは⋯⋯　たしか\n"
	.string "ミツルくんと　いったよね$"

PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon:
	.string "ミツル“ぼく　きょうから　シダケタウンの\n"
	.string "しんせきの　うちに　いくんですけど\p"
	.string "ひとりじゃ　さみしいから　ポケモンを\n"
	.string "つれて　いこうかと　おもって⋯⋯\p"
	.string "でも　いままで　じぶんで　ポケモンを\n"
	.string "つかまえた　ことが　ないから\l"
	.string "どう　やったら　いいのか⋯⋯$"

PetalburgCity_Gym_Text_DadHmISee:
	.string "パパ“⋯⋯ふむ　なるほど$"

PetalburgCity_Gym_Text_DadPlayerGoWithWally:
	.string "パパ“{PLAYER}！　はなしは　きいたね\p"
	.string "ミツルくんが　ぶじに\n"
	.string "ポケモンを　つかまえられるか\l"
	.string "みまもって　あげるんだ$"

PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon:
	.string "ミツルくん\n"
	.string "わたしの　ポケモンを　かして　あげよう！\p"
	.string "ミツルは\n"
	.string "ジグザグマを　あずかった！$"

PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall:
	.string "ミツル“わあ⋯⋯\n"
	.string "ポケモンだぁ⋯⋯！\p"
	.string "パパ“うむ⋯⋯\n"
	.string "モンスターボールは　あげるから\l"
	.string "がんばって　みなさい！\p"
	.string "ミツルは\n"
	.string "モンスターボールを　もらった！$"

PetalburgCity_Gym_Text_WallyOhWowThankYou:
	.string "ミツル“おじさん　ありがとう！$"

PetalburgCity_Gym_Text_WouldYouReallyComeWithMe:
	.string "{PLAYER}さん⋯⋯\n"
	.string "ぼくと　いっしょに　きてくれますよね$"

PetalburgCity_Gym_Text_DadSoDidItWorkOut:
	.string "パパ“うまく　いったかい？$"

PetalburgCity_Gym_Text_WallyThankYouBye:
	.string "ミツル“おじさん\n"
	.string "おかりした　ポケモン　おかえし　します\p"
	.string "{PLAYER}さん　いっしょに　きてくれて\n"
	.string "どうも　ありがとう⋯⋯\p"
	.string "ポケモンを　つかまえることが　できたのは\n"
	.string "ふたりの　おかげです！\l"
	.string "つかまえた　ポケモン　たいせつに　しますね\p"
	.string "⋯⋯あ！　おかあさんが　まってるから\n"
	.string "ぼくは　もう　いかなきゃ！\p"
	.string "じゃあね　{PLAYER}さん！$"

PetalburgCity_Gym_Text_DadGoCollectBadges:
	.string "パパ“さて⋯⋯\p"
	.string "{PLAYER}！　ポケモントレーナー　として\n"
	.string "つよく　なりたいのなら\l"
	.string "わたしの　アドバイスを　ききなさい\p"
	.string "まずは　この　さきにある\n"
	.string "カナズミシティに　いくんだ\p"
	.string "そこで　ツツジ　という　ジムリーダーと\n"
	.string "たたかうと　いい！\p"
	.string "そうやって　かくちの　ポケモンジムで\n"
	.string "ジムリーダーを　たおして\l"
	.string "ジムバッジを　あつめて　いくんだ\p"
	.string "もちろん　わたしも　ジムリーダーだ\n"
	.string "いずれ　{PLAYER}と　しょうぶ　するだろう\p"
	.string "だが　それは　{PLAYER}が\n"
	.string "つよくなってからの　はなし　だよ$"
