@ LavaridgeTown_Gym_B1F scripts (JP map g4 m2 @ 0x081F4DBA)

LavaridgeTown_Gym_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_B1F_EventScript_001F4DC0
	.byte 0

LavaridgeTown_Gym_B1F_EventScript_001F4DC0::
	call LavaridgeTown_Gym_B1F_EventScript_001F4DCB
	call LavaridgeTown_Gym_B1F_EventScript_001F4E18
	end

LavaridgeTown_Gym_B1F_EventScript_001F4DCB::
	setvar 0x4007, 0x0
	setvar 0x4008, 0x0
	setvar 0x4009, 0x0
	setvar 0x400A, 0x0
	checktrainerflag 0xCD
	goto_if 0x1, LavaridgeTown_Gym_B1F_EventScript_001F4DED
	setvar 0x4007, 0x1

LavaridgeTown_Gym_B1F_EventScript_001F4DED::
	checktrainerflag 0xCC
	goto_if 0x1, LavaridgeTown_Gym_B1F_EventScript_001F4DFB
	setvar 0x4008, 0x1

LavaridgeTown_Gym_B1F_EventScript_001F4DFB::
	checktrainerflag 0xCA
	goto_if 0x1, LavaridgeTown_Gym_B1F_EventScript_001F4E09
	setvar 0x4009, 0x1

LavaridgeTown_Gym_B1F_EventScript_001F4E09::
	checktrainerflag 0x1F5
	goto_if 0x1, LavaridgeTown_Gym_B1F_EventScript_001F4E17
	setvar 0x400A, 0x1

LavaridgeTown_Gym_B1F_EventScript_001F4E17::
	return

LavaridgeTown_Gym_B1F_EventScript_001F4E18::
	checktrainerflag 0xCD
	goto_if 0x1, LavaridgeTown_Gym_B1F_EventScript_001F4E25
	setobjectmovementtype 0x2, 0x3F

LavaridgeTown_Gym_B1F_EventScript_001F4E25::
	checktrainerflag 0xCC
	goto_if 0x1, LavaridgeTown_Gym_B1F_EventScript_001F4E32
	setobjectmovementtype 0x1, 0x3F

LavaridgeTown_Gym_B1F_EventScript_001F4E32::
	checktrainerflag 0xCA
	goto_if 0x1, LavaridgeTown_Gym_B1F_EventScript_001F4E3F
	setobjectmovementtype 0x3, 0x3F

LavaridgeTown_Gym_B1F_EventScript_001F4E3F::
	checktrainerflag 0x1F5
	goto_if 0x1, LavaridgeTown_Gym_B1F_EventScript_001F4E4C
	setobjectmovementtype 0x4, 0x3F

LavaridgeTown_Gym_B1F_EventScript_001F4E4C::
	return

	.incbin "baserom_jp.gba", 0x1f4e4d, 0x138
