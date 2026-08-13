	nop 
	setrespawn 0x27
	fadescreen 0x27
	gotostd_if 0x3, 0xC
	returnram 
	.string "{MUS_RG_FUCHSIA}ク8オ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_PC_ON}{SE_PC_ON}{RED}{MUS_RG_POKE_CENTER}トはキ{MUS_RG_FUCHSIA}{BLUE}:$"
	.incbin "baserom_jp.gba", 0x280716, 0x3c
