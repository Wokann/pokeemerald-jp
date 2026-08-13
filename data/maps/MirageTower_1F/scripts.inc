@ MirageTower_1F scripts (JP map g24 m94 @ 0x0821CDC6)

MirageTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MirageTower_1F_EventScript_0021CDCC
	.byte 0

MirageTower_1F_EventScript_0021CDCC::
	setflag 0x8DC
	setflag 0x9D
	setflag 0x78
	end

