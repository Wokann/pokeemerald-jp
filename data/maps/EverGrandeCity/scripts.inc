@ EverGrandeCity scripts (JP map g0 m8 @ 0x081E3979)

EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_EventScript_001E397F
	.byte 0

EverGrandeCity_EventScript_001E397F::
	checkflag 0x88A
	call_if 0x1, 0x08243106
	end

EverGrandeCity_EventScript_001E3989::
	loadword 0x0, 0x081E39AD
	callstd 0x3
	end

EverGrandeCity_EventScript_001E3992::
	loadword 0x0, 0x081E39D5
	callstd 0x3
	end

EverGrandeCity_EventScript_001E399B::
	loadword 0x0, 0x081E39BD
	callstd 0x3
	end

EverGrandeCity_EventScript_001E39A4::
	setflag 0x87E
	setvar 0x4001, 0x1
	end
