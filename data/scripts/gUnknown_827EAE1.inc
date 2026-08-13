	nop 
	messageautoscroll 0x27970027
	gotostd_if 0x1, 0xC
	returnram 
	.string "{BLUE}の{SE_M_BITE}{PH_KIT_HELD}トわキ{MUS_RG_FUCHSIA}{SE_WIN_OPEN}{TRANSPARENT}l$"
	.incbin "baserom_jp.gba", 0x27eafb, 0x44
