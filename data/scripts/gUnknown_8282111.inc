	nop 
	.byte 0xCA
	waitstate 
	compare_local_to_value 0x9B, 0x0
	setdynamicwarp 0x604, 0x2, 0xE078, 0x856
	bufferstdstring 0x4, 0x0
	loadbyte 0x0, 0x0
	nop 
	end 
	.incbin "baserom_jp.gba", 0x282128, 0x2e
	.string "{SE_USE_ITEM}{SE_PC_LOGIN}{RED}{BLUE}{LIGHT_GRAY}オぱ{DYNAMIC_COLOR4}{MUS_RG_FUCHSIA}{SE_RG_POKE_JUMP_SUCCESS}{TRANSPARENT}{SE_PC_OFF}{MUS_DUMMY}{SE_WIN_OPEN}{SE_USE_ITEM}{RED}との{SE_M_BIND}ぜた{LIGHT_GREEN}$"
	.incbin "baserom_jp.gba", 0x282176, 0x1
	.incbin "baserom_jp.gba", 0x282177, 0x2
