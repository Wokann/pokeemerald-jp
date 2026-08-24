@ PacifidlogTown scripts (JP map g0 m15 @ 0x081E6381)

PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_EventScript_001E638C
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_EventScript_001E6390
	.byte 0

PacifidlogTown_EventScript_001E638C::
	setflag 0x875
	end

PacifidlogTown_EventScript_001E6390::
	setstepcallback 0x3
	end

PacifidlogTown_EventScript_001E6393::
	loadword 0x0, 0x081E63F7
	callstd 0x2
	end

PacifidlogTown_EventScript_001E639C::
	loadword 0x0, 0x081E63B7
	callstd 0x2
	end

PacifidlogTown_EventScript_001E63A5::
	loadword 0x0, 0x081E6429
	callstd 0x2
	end

PacifidlogTown_EventScript_001E63AE::
	loadword 0x0, 0x081E6499
	callstd 0x3
	end
