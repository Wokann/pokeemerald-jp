	nop 
	setrespawn 0x27
	fadescreen 0x27
	gotostd_if 0x1, 0xC
	returnram 
	.string "{BLUE}の{SE_M_DOUBLE_TEAM}{PH_KIT_HELD}でひキ{BLUE}{LIGHT_GRAY}{SE_PC_OFF}{TRANSPARENT}l$"
	.incbin "baserom_jp.gba", 0x278cd0, 0xf
	.incbin "baserom_jp.gba", 0x278cdf, 0x1e
