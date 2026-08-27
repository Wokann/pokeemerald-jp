@ Underwater_SealedChamber scripts (JP map g24 m70 @ 0x0821BA09)

Underwater_SealedChamber_MapScripts::
	map_script MAP_SCRIPT_ON_DIVE_WARP, Underwater_SealedChamber_OnDive
	.byte 0

Underwater_SealedChamber_OnDive: @ 0x0821BA0F
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_ne VAR_0x8004, 12, Underwater_SealedChamber_EventScript_SurfaceRoute134
	goto_if_ne VAR_0x8005, 44, Underwater_SealedChamber_EventScript_SurfaceRoute134
	goto Underwater_SealedChamber_EventScript_SurfaceSealedChamber

Underwater_SealedChamber_EventScript_SurfaceRoute134:: @ 0x0821BA2F
	setdivewarp MAP_ROUTE134, 60, 31
	end

Underwater_SealedChamber_EventScript_SurfaceSealedChamber:: @ 0x0821BA38
	setdivewarp MAP_SEALED_CHAMBER_OUTER_ROOM, 10, 19
	end

Underwater_SealedChamber_EventScript_Braille:: @ 0x0821BA41
	lockall
	braillemsgbox Underwater_SealedChamber_Braille_GoUpHere
	releaseall
	end
