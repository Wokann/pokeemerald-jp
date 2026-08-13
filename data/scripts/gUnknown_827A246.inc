	nop 
	.byte 0xE8
	waitstate 
	compare_local_to_value 0xD4, 0x0
	showcoinsbox 0xC, 0x3
	return 
	.incbin "baserom_jp.gba", 0x27a250, 0x1d
	.string "{LIGHT_RED}の{SE_M_ATTRACT}{PH_KIT_HELD}ピöカ{BLUE}ォ{DARK_GRAY}{SE_M_RAZOR_WIND2}l$"
	.string "{DARK_GRAY}ピöカ{BLUE}ォ{SE_PC_LOGIN}$"
	.string "d$"
	.string "{DARK_GRAY}ピöカ{BLUE}ォ{DARK_GRAY}{SE_M_CUT}:$"
	.string "{DARK_GRAY}ピöカ{BLUE}ォ{DARK_GRAY}{MUS_ENCOUNTER_INTENSE}f$"
	.string "{DARK_GRAY}ピöカ{BLUE}ォ{DARK_GRAY}ィ$"
	.string "v$"
	.string "{DARK_GRAY}ピöカ{BLUE}ォ{DARK_GRAY}ィ\n"
	.string "m$"
	.incbin "baserom_jp.gba", 0x27a2b4, 0x8b
