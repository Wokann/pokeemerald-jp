@ DewfordTown_Gym scripts (JP map g3 m3 @ 0x081F2D87)

DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_EventScript_001F2D8D
	.byte 0

DewfordTown_Gym_EventScript_001F2D8D::
	call DewfordTown_Gym_EventScript_001F2D93
	end

DewfordTown_Gym_EventScript_001F2D93::
	checktrainerflag 0x10A
	goto_if 0x1, DewfordTown_Gym_EventScript_001F2DED
	call DewfordTown_Gym_EventScript_001F2EB3
	copyvar 0x8001, 0x8000
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, DewfordTown_Gym_EventScript_001F2E09
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, DewfordTown_Gym_EventScript_001F2E05
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, DewfordTown_Gym_EventScript_001F2E01
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, DewfordTown_Gym_EventScript_001F2DFD
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, DewfordTown_Gym_EventScript_001F2DF9
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, DewfordTown_Gym_EventScript_001F2DF5
	goto DewfordTown_Gym_EventScript_001F2DF1

DewfordTown_Gym_EventScript_001F2DED::
	setflashradius 0x0
	return

DewfordTown_Gym_EventScript_001F2DF1::
	setflashradius 0x1
	return

DewfordTown_Gym_EventScript_001F2DF5::
	setflashradius 0x2
	return

DewfordTown_Gym_EventScript_001F2DF9::
	setflashradius 0x3
	return

DewfordTown_Gym_EventScript_001F2DFD::
	setflashradius 0x4
	return

DewfordTown_Gym_EventScript_001F2E01::
	setflashradius 0x5
	return

DewfordTown_Gym_EventScript_001F2E05::
	setflashradius 0x6
	return

DewfordTown_Gym_EventScript_001F2E09::
	setflashradius 0x7
	return

	.incbin "baserom_jp.gba", 0x1f2e0d, 0xa6
DewfordTown_Gym_EventScript_001F2EB3::
	setvar 0x8000, 0x0
	checktrainerflag 0xB3
	goto_if 0x0, DewfordTown_Gym_EventScript_001F2EC6
	addvar 0x8000, 0x1

DewfordTown_Gym_EventScript_001F2EC6::
	checktrainerflag 0x1A9
	goto_if 0x0, DewfordTown_Gym_EventScript_001F2ED4
	addvar 0x8000, 0x1

DewfordTown_Gym_EventScript_001F2ED4::
	checktrainerflag 0x1AA
	goto_if 0x0, DewfordTown_Gym_EventScript_001F2EE2
	addvar 0x8000, 0x1

DewfordTown_Gym_EventScript_001F2EE2::
	checktrainerflag 0x23C
	goto_if 0x0, DewfordTown_Gym_EventScript_001F2EF0
	addvar 0x8000, 0x1

DewfordTown_Gym_EventScript_001F2EF0::
	checktrainerflag 0x23E
	goto_if 0x0, DewfordTown_Gym_EventScript_001F2EFE
	addvar 0x8000, 0x1

DewfordTown_Gym_EventScript_001F2EFE::
	checktrainerflag 0x23D
	goto_if 0x0, DewfordTown_Gym_EventScript_001F2F0C
	addvar 0x8000, 0x1

DewfordTown_Gym_EventScript_001F2F0C::
	return

	.incbin "baserom_jp.gba", 0x1f2f0d, 0x1c1
DewfordTown_Gym_EventScript_001F30CE::
	lock
	faceplayer
	checkflag 0x4F1
	goto_if 0x1, DewfordTown_Gym_EventScript_001F30E3
	loadword 0x0, 0x081F3121
	callstd 0x4
	release
	end

DewfordTown_Gym_EventScript_001F30E3::
	loadword 0x0, 0x081F31ED
	callstd 0x4
	release
	end

DewfordTown_Gym_EventScript_001F30ED::
	lockall
	checkflag 0x868
	goto_if 0x1, DewfordTown_Gym_EventScript_001F310D
	goto DewfordTown_Gym_EventScript_001F3117
	end

DewfordTown_Gym_EventScript_001F30FD::
	lockall
	checkflag 0x868
	goto_if 0x1, DewfordTown_Gym_EventScript_001F310D
	goto DewfordTown_Gym_EventScript_001F3117
	end

DewfordTown_Gym_EventScript_001F310D::
	loadword 0x0, 0x081F361A
	callstd 0x4
	releaseall
	end

DewfordTown_Gym_EventScript_001F3117::
	loadword 0x0, 0x081F360D
	callstd 0x4
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1f3121, 0x11a6
