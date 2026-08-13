	nop 
	checkpcitem 0x227, 0x2EBC
	setobjectxy 0x8208, 0x604, 0x100
	nop 
	loadword 0x0, 0xE8020001
	.byte 0x26
	setobjectxy 0x8208, 0x4, 0x100
	nop 
	nop 
	nop 
	nop 
	nop 
	copyvar 0x83, 0x43F
	goto_if 0x2, 0x85726E8
	bufferdecorationname 0x4, 0x13
	setworldmapflag 0xA00
	nop 
	nop 
	nop 
	copyvar 0x83, 0x43F
	goto_if 0x2, 0x85726E8
	bufferdecorationname 0x4, 0xFFE9
	end 
	.string "{TRANSPARENT}ü$"
	.string "{MUS_DUMMY}の{SE_M_ROCK_THROW}ぜ{LIGHT_GRAY}ぅぼ{DYNAMIC_COLOR4}{MUS_RG_FUCHSIA}{SE_RG_POKE_JUMP_SUCCESS}{MUS_DUMMY}{TRANSPARENT}{SE_SELECT}{SE_BANG}{SE_USE_ITEM}{RED}{MUS_RG_POKE_TOWER}tよキ{BLUE}ェ{RED}Ä$"
	.string "{SE_USE_ITEM}ü$"
	.incbin "baserom_jp.gba", 0x27a55a, 0x1d
