@ MauvilleCity_Gym scripts (JP map g10 m0 @ 0x081FE9B4)

MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_EventScript_001FE9BA
	.byte 0

MauvilleCity_Gym_EventScript_001FE9BA::
	checkflag 0x4F2
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FEB2D
	copyvar 0x8000, 0x4093
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FEA00
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FEAF5
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FEB03
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FEB11
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FEB1F
	end

MauvilleCity_Gym_EventScript_001FEA00::
	checkflag 0x63
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FEA0A
	end

MauvilleCity_Gym_EventScript_001FEA0A::
	setmetatile 0x3, 0xB, 0x241, 0x1
	setmetatile 0x3, 0xC, 0x249, 0x1
	setmetatile 0x3, 0xD, 0x250, 0x1
	setmetatile 0x4, 0xA, 0x222, 0x0
	setmetatile 0x5, 0xA, 0x223, 0x0
	setmetatile 0x4, 0xB, 0x22A, 0x1
	setmetatile 0x5, 0xB, 0x22B, 0x1
	setmetatile 0x7, 0xA, 0x222, 0x0
	setmetatile 0x8, 0xA, 0x223, 0x0
	setmetatile 0x7, 0xB, 0x22A, 0x1
	setmetatile 0x8, 0xB, 0x22B, 0x1
	setmetatile 0x4, 0xD, 0x230, 0x0
	setmetatile 0x5, 0xD, 0x231, 0x0
	setmetatile 0x4, 0xE, 0x238, 0x0
	setmetatile 0x5, 0xE, 0x239, 0x0
	setmetatile 0x1, 0xA, 0x230, 0x0
	setmetatile 0x2, 0xA, 0x231, 0x0
	setmetatile 0x1, 0xB, 0x238, 0x0
	setmetatile 0x2, 0xB, 0x239, 0x0
	setmetatile 0x6, 0x8, 0x242, 0x1
	setmetatile 0x6, 0x9, 0x21A, 0x0
	setmetatile 0x6, 0xA, 0x251, 0x0
	setmetatile 0x4, 0x6, 0x230, 0x0
	setmetatile 0x5, 0x6, 0x231, 0x0
	setmetatile 0x4, 0x7, 0x238, 0x0
	setmetatile 0x5, 0x7, 0x239, 0x0
	end

MauvilleCity_Gym_EventScript_001FEAF5::
	setvar 0x8004, 0x0
	special MauvilleGymSpecial1
	goto MauvilleCity_Gym_EventScript_001FEA00
	end

MauvilleCity_Gym_EventScript_001FEB03::
	setvar 0x8004, 0x1
	special MauvilleGymSpecial1
	goto MauvilleCity_Gym_EventScript_001FEA00
	end

MauvilleCity_Gym_EventScript_001FEB11::
	setvar 0x8004, 0x2
	special MauvilleGymSpecial1
	goto MauvilleCity_Gym_EventScript_001FEA00
	end

MauvilleCity_Gym_EventScript_001FEB1F::
	setvar 0x8004, 0x3
	special MauvilleGymSpecial1
	goto MauvilleCity_Gym_EventScript_001FEA00
	end

MauvilleCity_Gym_EventScript_001FEB2D::
	special MauvilleGymSpecial3
	end

	.incbin "baserom_jp.gba", 0x1feb31, 0x10e
MauvilleCity_Gym_EventScript_001FEC3F::
	lockall
	checkflag 0x4F2
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FECF3
	compare_var_to_value 0x4093, 0x1
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FECF3
	setvar 0x4093, 0x1
	setvar 0x8004, 0x0
	goto MauvilleCity_Gym_EventScript_001FECD3
	end

MauvilleCity_Gym_EventScript_001FEC64::
	lockall
	checkflag 0x4F2
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FECF3
	compare_var_to_value 0x4093, 0x2
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FECF3
	setvar 0x4093, 0x2
	setvar 0x8004, 0x1
	goto MauvilleCity_Gym_EventScript_001FECD3
	end

MauvilleCity_Gym_EventScript_001FEC89::
	lockall
	checkflag 0x4F2
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FECF3
	compare_var_to_value 0x4093, 0x3
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FECF3
	setvar 0x4093, 0x3
	setvar 0x8004, 0x2
	goto MauvilleCity_Gym_EventScript_001FECD3
	end

MauvilleCity_Gym_EventScript_001FECAE::
	lockall
	checkflag 0x4F2
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FECF3
	compare_var_to_value 0x4093, 0x4
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FECF3
	setvar 0x4093, 0x4
	setvar 0x8004, 0x3
	goto MauvilleCity_Gym_EventScript_001FECD3
	end

MauvilleCity_Gym_EventScript_001FECD3::
	special MauvilleGymSpecial2
	special MauvilleGymSpecial1
	special DrawWholeMapView
	playse 0x2C
	checkflag 0x63
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FECFA
	checkflag 0x63
	goto_if 0x0, MauvilleCity_Gym_EventScript_001FECF5
	releaseall
	end

MauvilleCity_Gym_EventScript_001FECF3::
	releaseall
	end

MauvilleCity_Gym_EventScript_001FECF5::
	setflag 0x63
	releaseall
	end

MauvilleCity_Gym_EventScript_001FECFA::
	clearflag 0x63
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1fecff, 0x73
MauvilleCity_Gym_EventScript_001FED72::
	lock
	faceplayer
	checkflag 0x4F2
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FED87
	loadword 0x0, 0x081FEDC5
	callstd 0x4
	release
	end

MauvilleCity_Gym_EventScript_001FED87::
	loadword 0x0, 0x081FEE65
	callstd 0x4
	release
	end

MauvilleCity_Gym_EventScript_001FED91::
	lockall
	checkflag 0x869
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FEDB1
	goto MauvilleCity_Gym_EventScript_001FEDBB
	end

MauvilleCity_Gym_EventScript_001FEDA1::
	lockall
	checkflag 0x869
	goto_if 0x1, MauvilleCity_Gym_EventScript_001FEDB1
	goto MauvilleCity_Gym_EventScript_001FEDBB
	end

MauvilleCity_Gym_EventScript_001FEDB1::
	loadword 0x0, 0x081FF292
	callstd 0x4
	releaseall
	end

MauvilleCity_Gym_EventScript_001FEDBB::
	loadword 0x0, 0x081FF283
	callstd 0x4
	releaseall
	end

	.incbin "baserom_jp.gba", 0x1fedc5, 0x200f
