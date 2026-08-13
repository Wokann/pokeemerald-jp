	nop 
	gotostd 0x28
	nop 
	.byte 0xEA
	waitstate 
	return 
	.string "ぷlな{BLUE}{SE_RG_POKE_JUMP_SUCCESS}{MUS_DUMMY}の{SE_M_PSYBEAM2}F{LIGHT_RED}{LIGHT_GRAY}ムホち{BLUE}{LIGHT_RED}{SE_RG_POKE_JUMP_SUCCESS}{MUS_DUMMY}{MUS_DUMMY}{TRANSPARENT}{SE_FAINT}{MUS_DUMMY}{MUS_RG_SURF}ネüカ{SE_DOOR}{DARK_GRAY}:$"
	.incbin "baserom_jp.gba", 0x27b685, 0x2
	.incbin "baserom_jp.gba", 0x27b687, 0xb
	.incbin "baserom_jp.gba", 0x27b692, 0x2d
