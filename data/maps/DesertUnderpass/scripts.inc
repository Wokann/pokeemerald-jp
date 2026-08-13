@ DesertUnderpass scripts (JP map g24 m98 @ 0x0821CF6B)

DesertUnderpass_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_EventScript_0021CF71
	.byte 0

DesertUnderpass_EventScript_0021CF71::
	setflag 0x8DE
	end

DesertUnderpass_EventScript_0021CF75::
	lock
	faceplayer
	checkflag 0x14F
	goto_if 0x1, DesertUnderpass_EventScript_0021CF8B
	checkflag 0x150
	goto_if 0x1, DesertUnderpass_EventScript_0021CF9C
	release
	end

DesertUnderpass_EventScript_0021CF8B::
	setorcopyvar 0x8000, 0x11F
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	removeobject 0x1
	release
	end

DesertUnderpass_EventScript_0021CF9C::
	setorcopyvar 0x8000, 0x11E
	setorcopyvar 0x8001, 0x1
	callstd 0x0
	removeobject 0x1
	release
	end

	.incbin "baserom_jp.gba", 0x21cfad, 0x25
