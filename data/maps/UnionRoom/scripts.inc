@ UnionRoom scripts (JP map g25 m60 @ 0x0821E966)

UnionRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, UnionRoom_EventScript_0021E971
	map_script MAP_SCRIPT_ON_TRANSITION, UnionRoom_EventScript_0021E9A5
	.byte 0

UnionRoom_EventScript_0021E971::
	setflag 0x2BF
	setflag 0x2C0
	setflag 0x2C1
	setflag 0x2C2
	setflag 0x2C3
	setflag 0x2C4
	setflag 0x2C5
	setflag 0x2C6
	removeobject 0x9
	removeobject 0x8
	removeobject 0x7
	removeobject 0x2
	removeobject 0x6
	removeobject 0x5
	removeobject 0x4
	removeobject 0x3
	special UnionRoomSpecial
	end

UnionRoom_EventScript_0021E9A5::
	end

UnionRoom_EventScript_0021E9A6::
	lock
	faceplayer
	setvar 0x800D, 0x1
	waitstate
	release
	end

UnionRoom_EventScript_0021E9B0::
	lock
	faceplayer
	setvar 0x800D, 0x2
	waitstate
	release
	end

UnionRoom_EventScript_0021E9BA::
	lock
	faceplayer
	setvar 0x800D, 0x3
	waitstate
	release
	end

UnionRoom_EventScript_0021E9C4::
	lock
	faceplayer
	setvar 0x800D, 0x4
	waitstate
	release
	end

UnionRoom_EventScript_0021E9CE::
	lock
	faceplayer
	setvar 0x800D, 0x5
	waitstate
	release
	end

UnionRoom_EventScript_0021E9D8::
	lock
	faceplayer
	setvar 0x800D, 0x6
	waitstate
	release
	end

UnionRoom_EventScript_0021E9E2::
	lock
	faceplayer
	setvar 0x800D, 0x7
	waitstate
	release
	end

UnionRoom_EventScript_0021E9EC::
	lock
	faceplayer
	setvar 0x800D, 0x8
	waitstate
	release
	end

UnionRoom_EventScript_0021E9F6::
	lock
	faceplayer
	setvar 0x800D, 0x9
	waitstate
	release
	end
