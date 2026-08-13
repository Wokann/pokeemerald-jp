	nop 
	.byte 0xEB
	waitstate 
	nop 
	.byte 0xED
	waitstate 
	end 
	.string "Züカ{BLUE}ェ{SE_PC_LOGIN}{TRANSPARENT}t$"
	.string "の{SE_M_PSYBEAM2}ぜ{LIGHT_RED}の{SE_M_ATTRACT}{PH_KIT_HELD}3üカ{BLUE}ォ{SE_PC_LOGIN}$"
	.string "b$"
	.string "{DARK_GRAY}3üカ{BLUE}ォ{DARK_GRAY}{SE_M_CUT}Ö$"
	.string "{DARK_GRAY}3üカ{BLUE}ォ{DARK_GRAY}{MUS_ENCOUNTER_INTENSE}f$"
	.string "{DARK_GRAY}3üカ{BLUE}ォ{DARK_GRAY}ィ$"
	.string "v$"
	.incbin "baserom_jp.gba", 0x282602, 0x1
