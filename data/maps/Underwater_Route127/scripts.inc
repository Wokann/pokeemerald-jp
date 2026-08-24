@ Underwater_Route127 scripts (JP map g0 m52 @ 0x081EF754)

Underwater_Route127_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route127_OnResume
	.byte 0

Underwater_Route127_OnResume::
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end
