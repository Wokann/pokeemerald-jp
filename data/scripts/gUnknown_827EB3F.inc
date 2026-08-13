	nop 
	messageautoscroll 0x27970027
	gotostd_if 0x1, 0x14
	setworldmapflag 0xC17
	returnram 
	.string "{BLUE}の{SE_M_BITE}{PH_KIT_HELD}トわキ{MUS_RG_FUCHSIA}{GREEN}l$"
	.string "l$"
	.incbin "baserom_jp.gba", 0x27eb5c, 0x26
	.string "{MUS_DUMMY}{SE_USE_ITEM}{SE_USE_ITEM}{LIGHT_GRAY}ぅぼ{DYNAMIC_COLOR4}{BLUE}{LIGHT_RED}{SE_RG_POKE_JUMP_SUCCESS}{MUS_DUMMY}{TRANSPARENT}{SE_WALL_HIT}{SE_SELECT}{SE_PC_LOGIN}{LIGHT_RED}の{SE_M_BITE}{PH_KIT_HELD}トわキ{MUS_RG_FUCHSIA}{GREEN}{SE_FAILURE}l$"
	.incbin "baserom_jp.gba", 0x27eba9, 0x11
	.incbin "baserom_jp.gba", 0x27ebba, 0x35
