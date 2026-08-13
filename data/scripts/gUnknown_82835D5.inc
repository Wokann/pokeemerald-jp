	nop 
	fadescreen 0x27
	nop 
	setrespawn 0x27
	dotimebasedevents 
	waitstate 
	gotostd_if 0x1, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x2835e2, 0x24
	.string "ァ{RED}ほの{SE_M_FIRE_PUNCH}{PH_KIT_HELD}ざぁキ{BLUE}ェ{SE_PC_ON}{MUS_DUMMY}{SE_RG_SS_ANNE_HORN}{MUS_DUMMY}{TRANSPARENT}{LIGHT_GRAY}オぱ{DYNAMIC_COLOR4}{MUS_RG_FUCHSIA}{SE_RG_POKE_JUMP_SUCCESS}{TRANSPARENT}{SE_PC_OFF}{MUS_DUMMY}{SE_SUPER_EFFECTIVE}{SE_USE_ITEM}{LIGHT_GRAY}ムホち{BLUE}{DYNAMIC_COLOR1}{LIGHT_RED}{SE_PC_ON}{SE_PC_LOGIN}{MUS_DUMMY}{MUS_DUMMY}$"
	.incbin "baserom_jp.gba", 0x28363d, 0x20
