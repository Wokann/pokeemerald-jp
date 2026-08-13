	nop 
	loadbyte 0x27, 0x0
	fadescreen 0x27
	gotostd_if 0x3, 0xC
	returnram 
	.string "{BLUE}の{SE_M_BONEMERANG}{PH_KIT_HELD}ヤをキ{MUS_RG_FUCHSIA}{LIGHT_RED}b$"
	.string "s$"
	.incbin "baserom_jp.gba", 0x27fe23, 0x31
