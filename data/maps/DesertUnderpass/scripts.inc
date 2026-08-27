@ DesertUnderpass scripts (JP map g24 m98 @ 0x0821CF6B)

DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition::
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

DesertUnderpass_EventScript_Fossil::
	lock
	faceplayer
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
	release
	end

DesertUnderpass_EventScript_GiveClawFossil::
	giveitem ITEM_CLAW_FOSSIL
	removeobject LOCALID_UNDERPASS_FOSSIL
	release
	end

DesertUnderpass_EventScript_GiveRootFossil::
	giveitem ITEM_ROOT_FOSSIL
	removeobject LOCALID_UNDERPASS_FOSSIL
	release
	end

@ Unused
DesertUnderpass_Text_FoundRootFossil::
	.string "{PLAYER}は\n"
	.string "ねっこのカセキを　みつけた！$"

@ Unused
DesertUnderpass_Text_FoundClawFossil::
	.string "{PLAYER}は\n"
	.string "ツメのカセキを　みつけた！$"
