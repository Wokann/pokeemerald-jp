	nop 
	.byte 0xF3
	waitstate 
	nop 
	nop 
	delay 0x8103
	takemoney 0x2050815, 0xDF
	nop 
	setdynamicwarp 0x3, 0x29, 0x15AB, 0x208
	nop 
	return 
	.incbin "baserom_jp.gba", 0x283452, 0x1c
	.string "{SE_ESCALATOR}{SE_PC_ON}{DARK_GRAY}ミ8オ{MUS_RG_FUCHSIA}{LIGHT_GRAY}{SE_SELECT}{SE_PC_LOGIN}{SE_USE_ITEM}{RED}{MUS_RG_VICTORY_TRAINER}ミ8オ{MUS_RG_FUCHSIA}{LIGHT_GRAY}{SE_SELECT}{SE_PC_LOGIN}{SE_USE_ITEM}{SE_PC_ON}{LIGHT_GRAY}ぷダな{BLUE}{MUS_RG_SURF}{SE_M_FLATTER}F$"
	.incbin "baserom_jp.gba", 0x28349b, 0x9a
