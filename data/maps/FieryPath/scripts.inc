@ FieryPath scripts (JP map g24 m14 @ 0x082160FF)

FieryPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_EventScript_00216105
	.byte 0

FieryPath_EventScript_00216105::
	checkflag 0x8AA
	call_if 0x0, FieryPath_EventScript_00216112
	setflag 0x8AA
	end

FieryPath_EventScript_00216112::
	setflag 0x2FE
	clearflag 0x2FF
	return
