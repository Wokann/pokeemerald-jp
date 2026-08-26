@ Underwater_SeafloorCavern scripts (JP map g24 m26 @ 0x0821834E)

Underwater_SeafloorCavern_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_SeafloorCavern_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_SeafloorCavern_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Underwater_SeafloorCavern_OnLoad
	.byte 0

Underwater_SeafloorCavern_OnTransition:: @ 0x0821835E
	setflag FLAG_LANDMARK_SEAFLOOR_CAVERN
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, Underwater_SeafloorCavern_EventScript_HideSubmarine
	end

Underwater_SeafloorCavern_EventScript_HideSubmarine:: @ 0x0821836B
	setflag FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE
	end

Underwater_SeafloorCavern_OnLoad:: @ 0x0821836F
	call_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, Underwater_SeafloorCavern_EventScript_SetSubmarineGoneMetatiles
	end

Underwater_SeafloorCavern_EventScript_SetSubmarineGoneMetatiles:: @ 0x08218379
	setmetatile 0x5, 0x3, METATILE_Underwater_RockWall, TRUE
	setmetatile 0x6, 0x3, METATILE_Underwater_RockWall, TRUE
	setmetatile 0x7, 0x3, METATILE_Underwater_RockWall, TRUE
	setmetatile 0x8, 0x3, METATILE_Underwater_RockWall, TRUE
	setmetatile 0x5, 0x4, METATILE_Underwater_FloorShadow, FALSE
	setmetatile 0x6, 0x4, METATILE_Underwater_FloorShadow, FALSE
	setmetatile 0x7, 0x4, METATILE_Underwater_FloorShadow, FALSE
	setmetatile 0x8, 0x4, METATILE_Underwater_FloorShadow, FALSE
	setmetatile 0x5, 0x5, METATILE_Underwater_FloorShadow, FALSE
	setmetatile 0x6, 0x5, METATILE_Underwater_FloorShadow, FALSE
	setmetatile 0x7, 0x5, METATILE_Underwater_FloorShadow, FALSE
	setmetatile 0x8, 0x5, METATILE_Underwater_FloorShadow, FALSE
	return

Underwater_SeafloorCavern_OnResume:: @ 0x082183E6
	setdivewarp MAP_SEAFLOOR_CAVERN_ENTRANCE, 10, 17
	end

Underwater_SeafloorCavern_EventScript_CheckStolenSub:: @ 0x082183EF
	msgbox Underwater_SeafloorCavern_Text_SubExplorer1, MSGBOX_SIGN
	end

Underwater_SeafloorCavern_Text_SubExplorer1: @ 0x082183F8
	.string "せんすいてい　には\n"
	.string "‘かいえん　1ごう’と　かかれている\p"
	.string "アクアだんが　カイナから\n"
	.string "うばって　いった　せんすいてい　だ！\p"
	.string "アクアだんは\n"
	.string "ここから　うえに　あがったみたいだ$"
