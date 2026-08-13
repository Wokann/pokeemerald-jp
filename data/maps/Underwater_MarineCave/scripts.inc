@ Underwater_MarineCave scripts (JP map g24 m101 @ 0x0821CFDD)

Underwater_MarineCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_MarineCave_EventScript_0021CFEC
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_MarineCave_EventScript_0021CFE8
	.byte 0

Underwater_MarineCave_EventScript_0021CFE8::
	setflag 0x8D9
	end

Underwater_MarineCave_EventScript_0021CFEC::
	setdivewarp 0x1866, 0xFF, 0xA, 0x11
	end

