	nop 
	fadeoutbgm 0x27
	compare_local_to_value 0x78, 0x0
	showcoinsbox 0x1C, 0x2
	return 
	.string "べぷち{BLUE}{LIGHT_RED}{SE_PC_OFF}{MUS_DUMMY}{MUS_DUMMY}{TRANSPARENT}{MUS_RG_SURF}ク8オ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_WIN_OPEN}{SE_PC_ON}{MUS_RG_SS_ANNE}の{SE_M_RAZOR_WIND}{PH_KIT_HELD}ふをキ{BLUE}ェ{LIGHT_GRAY}ü$"
	.string "ü$"
	.string "{MUS_DUMMY}{DARK_GRAY}ふをキ{BLUE}ェ{LIGHT_GRAY}ü$"
	.incbin "baserom_jp.gba", 0x281ab5, 0xd
	.string "{SE_USE_ITEM}{SE_LEDGE}{SE_PC_OFF}{SE_USE_ITEM}{RED}{MUS_RG_FUCHSIA}ク8オ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_WIN_OPEN}{SE_PC_ON}{MUS_RG_SS_ANNE}の{SE_M_RAZOR_WIND}{PH_KIT_HELD}ふをキ{BLUE}ェ{LIGHT_GRAY}{SE_LEDGE}ü$"
	.incbin "baserom_jp.gba", 0x281ae8, 0x18
	.incbin "baserom_jp.gba", 0x281b00, 0xa
