@ LilycoveCity_DepartmentStore_5F scripts (JP map g13 m20 @ 0x0820AC4E)

LilycoveCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LilycoveCity_DepartmentStore_5F_MapScriptTable_0020AC54
	.byte 0

LilycoveCity_DepartmentStore_5F_MapScriptTable_0020AC54::
	map_script_2 0x405E, 0x1, LilycoveCity_DepartmentStore_5F_EventScript_0020AC6E
	map_script_2 0x405E, 0x2, LilycoveCity_DepartmentStore_5F_EventScript_0020AC6E
	map_script_2 0x405E, 0x3, LilycoveCity_DepartmentStore_5F_EventScript_0020AC6E
	.2byte 0

LilycoveCity_DepartmentStore_5F_EventScript_0020AC6E::
	setobjectxy 0x7, 0x10, 0x2
	turnobject 0x7, 0x2
	end

LilycoveCity_DepartmentStore_5F_EventScript_0020AC7A::
	lock
	faceplayer
	message 0x0824390F
	waitmessage
	pokemartdecoration2 0x0820AC94
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x20ac91, 0x1f
LilycoveCity_DepartmentStore_5F_EventScript_0020ACB0::
	lock
	faceplayer
	message 0x0824390F
	waitmessage
	pokemartdecoration2 0x0820ACC8
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x20acc7, 0x17
LilycoveCity_DepartmentStore_5F_EventScript_0020ACDE::
	lock
	faceplayer
	message 0x0824390F
	waitmessage
	pokemartdecoration2 0x0820ACF8
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x20acf5, 0x19
LilycoveCity_DepartmentStore_5F_EventScript_0020AD0E::
	lock
	faceplayer
	message 0x0824390F
	waitmessage
	pokemartdecoration2 0x0820AD28
	loadword 0x0, 0x08243920
	callstd 0x4
	release
	end

	.incbin "baserom_jp.gba", 0x20ad25, 0x1b
LilycoveCity_DepartmentStore_5F_EventScript_0020AD40::
	loadword 0x0, 0x0820AD99
	callstd 0x2
	end

LilycoveCity_DepartmentStore_5F_EventScript_0020AD49::
	lockall
	applymovement 0x7, 0x08243621
	waitmovement 0x0
	compare_var_to_value 0x405E, 0x0
	goto_if 0x1, LilycoveCity_DepartmentStore_5F_EventScript_0020AD70
	compare_var_to_value 0x405E, 0x4
	goto_if 0x4, LilycoveCity_DepartmentStore_5F_EventScript_0020AD70
	goto LilycoveCity_DepartmentStore_5F_EventScript_0020AD7B
	end

LilycoveCity_DepartmentStore_5F_EventScript_0020AD70::
	loadword 0x0, 0x0820ADFE
	callstd 0x4
	closemessage
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_0020AD7B::
	loadword 0x0, 0x0820AE30
	callstd 0x4
	closemessage
	applymovement 0x7, 0x08243629
	waitmovement 0x0
	releaseall
	end

LilycoveCity_DepartmentStore_5F_EventScript_0020AD90::
	loadword 0x0, 0x0820ADD5
	callstd 0x2
	end

	.incbin "baserom_jp.gba", 0x20ad99, 0xba
