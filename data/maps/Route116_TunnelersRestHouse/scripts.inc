@ Route116_TunnelersRestHouse scripts (JP map g21 m0 @ 0x08212820)

Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_EventScript_00212826
	.byte 0

Route116_TunnelersRestHouse_EventScript_00212826::
	setflag 0x8BA
	end

Route116_TunnelersRestHouse_EventScript_0021282A::
	loadword 0x0, 0x0821285B
	callstd 0x2
	end

Route116_TunnelersRestHouse_EventScript_00212833::
	loadword 0x0, 0x082128DD
	callstd 0x2
	end

Route116_TunnelersRestHouse_EventScript_0021283C::
	lock
	faceplayer
	checkflag 0xC7
	goto_if 0x1, Route116_TunnelersRestHouse_EventScript_00212851
	loadword 0x0, 0x0821295A
	callstd 0x4
	release
	end

Route116_TunnelersRestHouse_EventScript_00212851::
	loadword 0x0, 0x0821299F
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x21285b, 0x180
