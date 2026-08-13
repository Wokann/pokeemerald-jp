@ InsideOfTruck scripts (JP map g25 m40 @ 0x0821DD83)

InsideOfTruck_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, InsideOfTruck_EventScript_0021DD8E
	map_script MAP_SCRIPT_ON_RESUME, InsideOfTruck_EventScript_0021DDAA
	.byte 0

InsideOfTruck_EventScript_0021DD8E::
	setmetatile 0x4, 0x1, 0x208, 0x0
	setmetatile 0x4, 0x2, 0x210, 0x0
	setmetatile 0x4, 0x3, 0x218, 0x0
	end

InsideOfTruck_EventScript_0021DDAA::
	setstepcallback 0x5
	end

InsideOfTruck_EventScript_0021DDAD::
	lockall
	setflag 0x4000
	checkplayergender
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, InsideOfTruck_EventScript_0021DDC9
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, InsideOfTruck_EventScript_0021DDEF
	end

InsideOfTruck_EventScript_0021DDC9::
	setrespawn 0x1
	setvar 0x4092, 0x1
	setflag 0x2F7
	setflag 0x2FA
	setflag 0x310
	setflag 0x2DF
	setflag 0x331
	setvar 0x408C, 0x1
	setdynamicwarp 0x9, 0xFF, 0x3, 0xA
	releaseall
	end

InsideOfTruck_EventScript_0021DDEF::
	setrespawn 0x2
	setvar 0x4092, 0x2
	setflag 0x2F6
	setflag 0x2F9
	setflag 0x311
	setflag 0x2E0
	setflag 0x332
	setvar 0x4082, 0x1
	setdynamicwarp 0x9, 0xFF, 0xC, 0xA
	releaseall
	end

InsideOfTruck_EventScript_0021DE15::
	loadword 0x0, 0x0821DE1E
	callstd 0x3
	end

	.incbin "baserom_jp.gba", 0x21de1e, 0x28
