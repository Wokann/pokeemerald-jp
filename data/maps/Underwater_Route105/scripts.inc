@ Underwater_Route105 scripts (JP map g0 m55 @ 0x081EF76D)

Underwater_Route105_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route105_OnResume
	.byte 0

Underwater_Route105_OnResume::
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end
