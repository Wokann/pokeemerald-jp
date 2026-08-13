	nop 
	playmoncry 0x27, 0x2797
	gotostd_if 0x1, 0xC
	returnram 
	.string "{BLUE}の{SE_M_VICEGRIP}{PH_KIT_HELD}ワわキ{MUS_RG_FUCHSIA}{GREEN}l$"
	.incbin "baserom_jp.gba", 0x27ec07, 0x45
