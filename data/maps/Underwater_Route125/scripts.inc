@ Underwater_Route125 scripts (JP map g0 m56 @ 0x081EF779)

Underwater_Route125_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route125_OnResume
	.byte 0

Underwater_Route125_OnResume:
	call AbnormalWeather_Underwater_SetupEscapeWarp
	end
