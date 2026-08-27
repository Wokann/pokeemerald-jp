@ AbandonedShip_Deck scripts (JP map g24 m54 @ 0x0821A972)

AbandonedShip_Deck_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_Deck_OnTransition
	.byte 0

AbandonedShip_Deck_OnTransition:: @ 0x0821A978
	setflag FLAG_LANDMARK_ABANDONED_SHIP
	end
