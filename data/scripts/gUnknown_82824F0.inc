	nop 
	.byte 0xEA
	waitstate 
	end 
	.string "クんキ{MUS_RG_FUCHSIA}{LIGHT_RED}{SE_U}{SE_PC_OFF}{MUS_DUMMY}{SE_FAINT}{MUS_DUMMY}の{SE_M_PSYBEAM}F{LIGHT_RED}{RED}{DYNAMIC_COLOR1}の{SE_M_LEER}F{LIGHT_GRAY}べヘた{BLUE}{SE_SELECT}{RED}{MUS_RG_VERMILLION}ネüカ{SE_DOOR}{DARK_GRAY}:$"
	.incbin "baserom_jp.gba", 0x282521, 0x2
	.incbin "baserom_jp.gba", 0x282523, 0xb
	.incbin "baserom_jp.gba", 0x28252e, 0x25
