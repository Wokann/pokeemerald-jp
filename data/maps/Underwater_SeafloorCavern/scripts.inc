@ Underwater_SeafloorCavern scripts (JP map g24 m26 @ 0x0821834E)

Underwater_SeafloorCavern_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_SeafloorCavern_EventScript_002183E6
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_SeafloorCavern_EventScript_0021835E
	map_script MAP_SCRIPT_ON_LOAD, Underwater_SeafloorCavern_EventScript_0021836F
	.byte 0

Underwater_SeafloorCavern_EventScript_0021835E::
	setflag 0x8A7
	checkflag 0x81
	goto_if 0x1, Underwater_SeafloorCavern_EventScript_0021836B
	end

Underwater_SeafloorCavern_EventScript_0021836B::
	setflag 0x3D4
	end

Underwater_SeafloorCavern_EventScript_0021836F::
	checkflag 0x81
	call_if 0x1, Underwater_SeafloorCavern_EventScript_00218379
	end

Underwater_SeafloorCavern_EventScript_00218379::
	setmetatile 0x5, 0x3, 0x21E, 0x1
	setmetatile 0x6, 0x3, 0x21E, 0x1
	setmetatile 0x7, 0x3, 0x21E, 0x1
	setmetatile 0x8, 0x3, 0x21E, 0x1
	setmetatile 0x5, 0x4, 0x228, 0x0
	setmetatile 0x6, 0x4, 0x228, 0x0
	setmetatile 0x7, 0x4, 0x228, 0x0
	setmetatile 0x8, 0x4, 0x228, 0x0
	setmetatile 0x5, 0x5, 0x228, 0x0
	setmetatile 0x6, 0x5, 0x228, 0x0
	setmetatile 0x7, 0x5, 0x228, 0x0
	setmetatile 0x8, 0x5, 0x228, 0x0
	return

Underwater_SeafloorCavern_EventScript_002183E6::
	setdivewarp 0x181B, 0xFF, 0xA, 0x11
	end

Underwater_SeafloorCavern_EventScript_002183EF::
	loadword 0x0, 0x082183F8
	callstd 0x3
	end
