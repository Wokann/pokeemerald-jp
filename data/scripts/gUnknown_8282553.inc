	nop 
	.byte 0xE8
	waitstate 
	nop 
	.byte 0xEC
	waitstate 
	end 
	.string "ザüカ{BLUE}ェ{DARK_GRAY}{SE_FAINT}V$"
	.string "の{SE_M_HEAL_BELL}ぜ{RED}ぬの{SE_M_HEAL_BELL}ぜ{RED}ぬの{SE_M_HEAL_BELL}ぜ{MUS_RG_SURF}ピöカ{BLUE}ォ{DARK_GRAY}{SE_M_RAZOR_WIND2}n$"
	.string "の{SE_M_ATTRACT}{PH_KIT_HELD}ピöカ{BLUE}ォ{SE_PC_LOGIN}$"
	.string "b$"
	.string "{DARK_GRAY}ピöカ{BLUE}ォ{DARK_GRAY}{SE_M_CUT}Ö$"
	.string "{DARK_GRAY}ピöカ{BLUE}ォ{DARK_GRAY}{MUS_ENCOUNTER_INTENSE}f$"
	.string "{DARK_GRAY}ピöカ{BLUE}ォ{DARK_GRAY}ィ$"
	.string "v$"
	.string "{DARK_GRAY}ピöカ{BLUE}ォ{DARK_GRAY}ィ\n"
	.string "m$"
	.incbin "baserom_jp.gba", 0x2825bb, 0x1
