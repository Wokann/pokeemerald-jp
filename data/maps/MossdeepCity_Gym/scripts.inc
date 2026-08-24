@ MossdeepCity_Gym scripts (JP map g14 m0 @ 0x0820B369)

MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_EventScript_0020B36F
	.byte 0

MossdeepCity_Gym_EventScript_0020B36F::
	checkflag 0x64
	goto_if 0x1, MossdeepCity_Gym_EventScript_0020B3A6
	goto MossdeepCity_Gym_EventScript_0020B37E
	end

MossdeepCity_Gym_EventScript_0020B37E::
	checkflag 0x65
	goto_if 0x1, MossdeepCity_Gym_EventScript_0020B3BE
	goto MossdeepCity_Gym_EventScript_0020B38D
	end

MossdeepCity_Gym_EventScript_0020B38D::
	checkflag 0x66
	goto_if 0x1, MossdeepCity_Gym_EventScript_0020B3D6
	goto MossdeepCity_Gym_EventScript_0020B39C
	end

MossdeepCity_Gym_EventScript_0020B39C::
	checkflag 0x67
	goto_if 0x1, MossdeepCity_Gym_EventScript_0020B3EE
	end

MossdeepCity_Gym_EventScript_0020B3A6::
	setmetatile 0x5, 0x5, 0x204, 0x0
	setmetatile 0x2, 0x7, 0x239, 0x1
	goto MossdeepCity_Gym_EventScript_0020B37E
	end

MossdeepCity_Gym_EventScript_0020B3BE::
	setmetatile 0x8, 0xE, 0x204, 0x0
	setmetatile 0x8, 0xA, 0x239, 0x1
	goto MossdeepCity_Gym_EventScript_0020B38D
	end

MossdeepCity_Gym_EventScript_0020B3D6::
	setmetatile 0xF, 0x11, 0x20C, 0x0
	setmetatile 0x11, 0xF, 0x239, 0x1
	goto MossdeepCity_Gym_EventScript_0020B39C
	end

MossdeepCity_Gym_EventScript_0020B3EE::
	setmetatile 0x1, 0x17, 0x20D, 0x0
	setmetatile 0x5, 0x18, 0x239, 0x1
	end

	.incbin "baserom_jp.gba", 0x20b401, 0x379
MossdeepCity_Gym_EventScript_0020B77A::
	lock
	faceplayer
	checkflag 0x4F6
	goto_if 0x1, MossdeepCity_Gym_EventScript_0020B78F
	loadword 0x0, 0x0820B83E
	callstd 0x4
	release
	end

MossdeepCity_Gym_EventScript_0020B78F::
	loadword 0x0, 0x0820B8E9
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x20b799, 0x3
MossdeepCity_Gym_EventScript_0020B79C::
	lockall
	checkflag 0x86D
	goto_if 0x1, MossdeepCity_Gym_EventScript_0020B7BC
	goto MossdeepCity_Gym_EventScript_0020B7C6
	end

MossdeepCity_Gym_EventScript_0020B7AC::
	lockall
	checkflag 0x86D
	goto_if 0x1, MossdeepCity_Gym_EventScript_0020B7BC
	goto MossdeepCity_Gym_EventScript_0020B7C6
	end

MossdeepCity_Gym_EventScript_0020B7BC::
	loadword 0x0, 0x0820C162
	callstd 0x4
	releaseall
	end

MossdeepCity_Gym_EventScript_0020B7C6::
	loadword 0x0, 0x0820C153
	callstd 0x4
	releaseall
	end
