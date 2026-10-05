@ DesertUnderpass scripts (JP map g24 m98 @ 0x0821CF6B)

DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
	.byte 0

DesertUnderpass_OnTransition:: @ 0x0821CF71
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
	end

DesertUnderpass_EventScript_Fossil:: @ 0x0821CF75
	lock
	faceplayer
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
	release
	end

DesertUnderpass_EventScript_GiveClawFossil:: @ 0x0821CF8B
	giveitem ITEM_CLAW_FOSSIL
	removeobject LOCALID_UNDERPASS_FOSSIL
	release
	end

DesertUnderpass_EventScript_GiveRootFossil:: @ 0x0821CF9C
	giveitem ITEM_ROOT_FOSSIL
	removeobject LOCALID_UNDERPASS_FOSSIL
	release
	end

@ Unused
DesertUnderpass_Text_FoundRootFossil:: @ 0x0821CFAD
	.string "{PLAYER}は\n"
	.string "ねっこのカセキを　みつけた！$"

@ Unused
DesertUnderpass_Text_FoundClawFossil:: @ 0x0821CFC0
	.string "{PLAYER}は\n"
	.string "ツメのカセキを　みつけた！$"
