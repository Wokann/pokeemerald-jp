	nop 
	animateflash 0x27
	gotostd_if 0x1, 0xC
	returnram 
	.string "{BLUE}の{SE_M_CUT}{PH_KIT_HELD}{TRANSPARENT}rカ{MUS_RG_FUCHSIA}{LIGHT_GRAY}{SE_ICE_STAIRS}l$"
	.incbin "baserom_jp.gba", 0x278d2d, 0x1b
