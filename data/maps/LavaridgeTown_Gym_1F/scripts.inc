@ LavaridgeTown_Gym_1F scripts (JP map g4 m1 @ 0x081F42C7)

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_EventScript_001F42CD
	.byte 0

LavaridgeTown_Gym_1F_EventScript_001F42CD::
	call LavaridgeTown_Gym_1F_EventScript_001F42D8
	call LavaridgeTown_Gym_1F_EventScript_001F432A
	end

LavaridgeTown_Gym_1F_EventScript_001F42D8::
	setvar 0x400B, 0x0
	setvar 0x400C, 0x0
	setvar 0x400D, 0x0
	setvar 0x400E, 0x0
	setvar 0x400F, 0x0
	checktrainerflag 0xC9
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F42FF
	setvar 0x400B, 0x1

LavaridgeTown_Gym_1F_EventScript_001F42FF::
	checktrainerflag 0x288
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F430D
	setvar 0x400C, 0x1

LavaridgeTown_Gym_1F_EventScript_001F430D::
	checktrainerflag 0xCB
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F431B
	setvar 0x400D, 0x1

LavaridgeTown_Gym_1F_EventScript_001F431B::
	checktrainerflag 0x28A
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F4329
	setvar 0x400E, 0x1

LavaridgeTown_Gym_1F_EventScript_001F4329::
	return

LavaridgeTown_Gym_1F_EventScript_001F432A::
	checktrainerflag 0xC9
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F4337
	setobjectmovementtype 0x2, 0x3F

LavaridgeTown_Gym_1F_EventScript_001F4337::
	checktrainerflag 0x288
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F4344
	setobjectmovementtype 0x3, 0x3F

LavaridgeTown_Gym_1F_EventScript_001F4344::
	checktrainerflag 0xCB
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F4351
	setobjectmovementtype 0x4, 0x3F

LavaridgeTown_Gym_1F_EventScript_001F4351::
	checktrainerflag 0x28A
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F435E
	setobjectmovementtype 0x5, 0x3F

LavaridgeTown_Gym_1F_EventScript_001F435E::
	return

	.incbin "baserom_jp.gba", 0x1f435f, 0x1e0
LavaridgeTown_Gym_1F_EventScript_001F453F::
	lock
	faceplayer
	checkflag 0x4F3
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F4554
	loadword 0x0, 0x081F4592
	callstd 0x4
	release
	end

LavaridgeTown_Gym_1F_EventScript_001F4554::
	loadword 0x0, 0x081F4625
	callstd 0x4
	release
	end

LavaridgeTown_Gym_1F_EventScript_001F455E::
	lockall
	checkflag 0x86A
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F457E
	goto LavaridgeTown_Gym_1F_EventScript_001F4588
	end

LavaridgeTown_Gym_1F_EventScript_001F456E::
	lockall
	checkflag 0x86A
	goto_if 0x1, LavaridgeTown_Gym_1F_EventScript_001F457E
	goto LavaridgeTown_Gym_1F_EventScript_001F4588
	end

LavaridgeTown_Gym_1F_EventScript_001F457E::
	loadword 0x0, 0x081F4C02
	callstd 0x4
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_001F4588::
	loadword 0x0, 0x081F4BF4
	callstd 0x4
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1f4592, 0x828
