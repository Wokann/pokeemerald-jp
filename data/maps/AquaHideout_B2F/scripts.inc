@ AquaHideout_B2F scripts (JP map g24 m25 @ 0x08217F9F)

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_EventScript_00217FA5
	.byte 0

AquaHideout_B2F_EventScript_00217FA5::
	checkflag 0x70
	call_if 0x1, AquaHideout_B2F_EventScript_00217FAF
	end

AquaHideout_B2F_EventScript_00217FAF::
	setvar 0x4001, 0x1
	return

AquaHideout_B2F_EventScript_00217FB5::
	lockall
	setvar 0x8008, 0x1
	playse 0x15
	applymovement 0x8008, 0x0824361B
	waitmovement 0x0
	applymovement 0x8008, 0x08243621
	waitmovement 0x0
	setvar 0x4001, 0x1
	releaseall
	end
