@ PetalburgCity scripts (JP map g0 m0 @ 0x081DB7E8)

gStdScripts_End:: @ 0x081DB7E8
PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_EventScript_001DB7F3
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_MapScriptTable_001DB838
	.byte 0

PetalburgCity_EventScript_001DB7F3::
	setflag 0x876
	compare_var_to_value 0x4057, 0x0
	call_if 0x1, PetalburgCity_EventScript_001DB823
	compare_var_to_value 0x4057, 0x2
	call_if 0x1, PetalburgCity_EventScript_001DB82B
	compare_var_to_value 0x4057, 0x4
	call_if 0x1, PetalburgCity_EventScript_001DB82B
	compare_var_to_value 0x4085, 0x8
	call_if 0x1, PetalburgCity_EventScript_001DB832
	end

PetalburgCity_EventScript_001DB823::
	setobjectxyperm 0x8, 0x5, 0xB
	return

PetalburgCity_EventScript_001DB82B::
	setflag 0x4000
	savebgm 0x1A4
	return

PetalburgCity_EventScript_001DB832::
	setvar 0x4085, 0x7
	return

PetalburgCity_MapScriptTable_001DB838::
	map_script_2 0x4057, 0x2, PetalburgCity_EventScript_001DB84A
	map_script_2 0x4057, 0x4, PetalburgCity_EventScript_001DB8AC
	.2byte 0

PetalburgCity_EventScript_001DB84A::
	lockall
	special SavePlayerParty
	special PutZigzagoonInPlayerParty
	applymovement 0x2, 0x081DB96D
	applymovement 0xFF, 0x081DB94C
	waitmovement 0x0
	loadword 0x0, gJPText_001E693C
	callstd 0x4
	special StartWallyTutorialBattle
	loadword 0x0, gJPText_001E6992
	callstd 0x4
	applymovement_at 0x2, 0x08243627, 0x0
	waitmovement_at 0x2, 0x0
	loadword 0x0, gJPText_001E69B0
	callstd 0x4
	closemessage
	clearflag 0x4000
	setvar 0x4057, 0x3
	fadedefaultbgm
	clearflag 0x4001
	special LoadPlayerParty
	setvar 0x4085, 0x1
	warp 0x801, 0xFF, 0x4, 0x6C
	waitstate
	releaseall
	end

PetalburgCity_EventScript_001DB8AC::
	lockall
	setflag 0x4000
	applymovement 0x5, 0x081DB937
	applymovement 0xFF, 0x081DB922
	waitmovement 0x0
	setvar 0x8004, 0x7
	setvar 0x8005, 0x5
	opendoor 0x8004, 0x8005
	waitmoncry
	applymovement 0x5, 0x081DB949
	applymovement 0xFF, 0x081DB934
	waitmovement 0x0
	setflag 0x33E
	hideobject_at 0xFF, 0x0
	closedoor 0x8004, 0x8005
	waitmoncry
	clearflag 0x4000
	fadedefaultbgm
	clearflag 0x4001
	warp 0x800, 0xFF, 0x2, 0x4
	waitstate
	releaseall
	end

PetalburgCity_EventScript_001DB902::
	lock
	faceplayer
	loadword 0x0, 0x081DBE37
	callstd 0x4
	closemessage
	applymovement 0x3, 0x08243625
	waitmovement 0x0
	release
	end

PetalburgCity_EventScript_001DB919::
	loadword 0x0, 0x081DBD53
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x1db922, 0x70
PetalburgCity_EventScript_001DB992::
	loadword 0x0, 0x081DBEDC
	callstd 0x3
	end

PetalburgCity_EventScript_001DB99B::
	loadword 0x0, 0x081DBF05
	callstd 0x3
	end

PetalburgCity_EventScript_001DB9A4::
	loadword 0x0, 0x081DBE8E
	callstd 0x2
	end

PetalburgCity_EventScript_001DB9AD::
	loadword 0x0, 0x081DBF22
	callstd 0x3
	end

PetalburgCity_EventScript_001DB9B6::
	lockall
	setvar 0x8008, 0x0
	goto PetalburgCity_EventScript_001DB9E6
	end

PetalburgCity_EventScript_001DB9C2::
	lockall
	setvar 0x8008, 0x1
	goto PetalburgCity_EventScript_001DB9E6
	end

PetalburgCity_EventScript_001DB9CE::
	lockall
	setvar 0x8008, 0x2
	goto PetalburgCity_EventScript_001DB9E6
	end

PetalburgCity_EventScript_001DB9DA::
	lockall
	setvar 0x8008, 0x3
	goto PetalburgCity_EventScript_001DB9E6
	end

PetalburgCity_EventScript_001DB9E6::
	applymovement 0x8, 0x08243621
	waitmovement 0x0
	playbgm 0x1A4, 0x0
	playse 0x15
	applymovement 0x8, 0x0824361B
	waitmovement 0x0
	applymovement 0x8, 0x0824361D
	waitmovement 0x0
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, PetalburgCity_EventScript_001DBA9B
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, PetalburgCity_EventScript_001DBAB0
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, PetalburgCity_EventScript_001DBABB
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, PetalburgCity_EventScript_001DBAD0
	loadword 0x0, 0x081DBD98
	callstd 0x4
	closemessage
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, PetalburgCity_EventScript_001DBAE5
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, PetalburgCity_EventScript_001DBAF7
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, PetalburgCity_EventScript_001DBB09
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, PetalburgCity_EventScript_001DBB1B
	loadword 0x0, 0x081DBDFD
	callstd 0x4
	applymovement 0x8, 0x0824362B
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	loadword 0x0, 0x081DBE11
	callstd 0x4
	closemessage
	applymovement 0x8, 0x081DBB74
	waitmovement 0x0
	fadedefaultbgm
	releaseall
	end

PetalburgCity_EventScript_001DBA9B::
	applymovement 0x8, 0x081DBB31
	waitmovement 0x0
	applymovement 0xFF, 0x0824362D
	waitmovement 0x0
	return

PetalburgCity_EventScript_001DBAB0::
	applymovement 0x8, 0x081DBB36
	waitmovement 0x0
	return

PetalburgCity_EventScript_001DBABB::
	applymovement 0x8, 0x081DBB39
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	return

PetalburgCity_EventScript_001DBAD0::
	applymovement 0x8, 0x081DBB3E
	waitmovement 0x0
	applymovement 0xFF, 0x08243629
	waitmovement 0x0
	return

PetalburgCity_EventScript_001DBAE5::
	applymovement 0x8, 0x081DBB44
	applymovement 0xFF, 0x081DBB81
	waitmovement 0x0
	return

PetalburgCity_EventScript_001DBAF7::
	applymovement 0x8, 0x081DBB4F
	applymovement 0xFF, 0x081DBB8B
	waitmovement 0x0
	return

PetalburgCity_EventScript_001DBB09::
	applymovement 0x8, 0x081DBB5D
	applymovement 0xFF, 0x081DBB98
	waitmovement 0x0
	return

PetalburgCity_EventScript_001DBB1B::
	applymovement 0x8, 0x081DBB68
	applymovement 0xFF, 0x081DBBA2
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1dbb2d, 0x80
PetalburgCity_EventScript_001DBBAD::
	lockall
	addobject 0x9
	setvar 0x8008, 0x0
	setobjectxy 0x9, 0xD, 0xA
	goto PetalburgCity_EventScript_001DBC05
	end

PetalburgCity_EventScript_001DBBC3::
	lockall
	addobject 0x9
	setvar 0x8008, 0x1
	setobjectxy 0x9, 0xD, 0xB
	goto PetalburgCity_EventScript_001DBC05
	end

PetalburgCity_EventScript_001DBBD9::
	lockall
	addobject 0x9
	setvar 0x8008, 0x2
	setobjectxy 0x9, 0xD, 0xC
	goto PetalburgCity_EventScript_001DBC05
	end

PetalburgCity_EventScript_001DBBEF::
	lockall
	addobject 0x9
	setvar 0x8008, 0x3
	setobjectxy 0x9, 0xD, 0xD
	goto PetalburgCity_EventScript_001DBC05
	end

PetalburgCity_EventScript_001DBC05::
	applymovement 0x9, 0x081DBCF2
	waitmovement 0x0
	playse 0x15
	applymovement 0x9, 0x0824361B
	waitmovement 0x0
	applymovement 0x9, 0x0824361D
	waitmovement 0x0
	applymovement 0x9, 0x081DBCF7
	waitmovement 0x0
	applymovement 0xFF, 0x0824362B
	waitmovement 0x0
	setvar 0x40D1, 0x1
	loadword 0x0, 0x081DBF2C
	callstd 0x4
	closemessage
	applymovement 0x9, 0x0824362B
	waitmovement 0x0
	delay 0x1E
	loadword 0x0, 0x081DBF4C
	callstd 0x4
	closemessage
	applymovement 0x9, 0x08243627
	waitmovement 0x0
	delay 0x1E
	loadword 0x0, 0x081DBF97
	callstd 0x4
	closemessage
	compare_var_to_value 0x8008, 0x0
	call_if 0x1, PetalburgCity_EventScript_001DBCAA
	compare_var_to_value 0x8008, 0x1
	call_if 0x1, PetalburgCity_EventScript_001DBCBC
	compare_var_to_value 0x8008, 0x2
	call_if 0x1, PetalburgCity_EventScript_001DBCCE
	compare_var_to_value 0x8008, 0x3
	call_if 0x1, PetalburgCity_EventScript_001DBCE0
	setvar 0x40C9, 0x1
	removeobject 0x9
	releaseall
	end

PetalburgCity_EventScript_001DBCAA::
	applymovement 0xFF, 0x081DBD0A
	applymovement 0x9, 0x081DBCFC
	waitmovement 0x0
	return

PetalburgCity_EventScript_001DBCBC::
	applymovement 0xFF, 0x081DBD1E
	applymovement 0x9, 0x081DBD11
	waitmovement 0x0
	return

PetalburgCity_EventScript_001DBCCE::
	applymovement 0xFF, 0x081DBD31
	applymovement 0x9, 0x081DBD24
	waitmovement 0x0
	return

PetalburgCity_EventScript_001DBCE0::
	applymovement 0xFF, 0x081DBD44
	applymovement 0x9, 0x081DBD37
	waitmovement 0x0
	return

	.incbin "baserom_jp.gba", 0x1dbcf2, 0x58
PetalburgCity_EventScript_001DBD4A::
	loadword 0x0, 0x081DBD98
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x1dbd53, 0x280
