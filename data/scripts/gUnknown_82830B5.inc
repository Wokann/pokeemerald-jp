	nop 
	.byte 0xFC
	waitstate 
	nop 
	playse 0x1927
	fadescreenspeed 0x0, 0xC0
	return 
	.incbin "baserom_jp.gba", 0x2830c0, 0x51
	.string "{SE_RG_DEOXYS_MOVE}{DARK_GRAY}みXコ{MUS_RG_FUCHSIA}{DARK_GRAY}t$"
	.incbin "baserom_jp.gba", 0x28311c, 0x2
	.incbin "baserom_jp.gba", 0x28311e, 0xd
	.string "{SE_RG_DEOXYS_MOVE}{DARK_GRAY}みXコ{MUS_RG_FUCHSIA}{DARK_GRAY}:$"
	.incbin "baserom_jp.gba", 0x283136, 0x2
	.incbin "baserom_jp.gba", 0x283138, 0xd
	.string "{SE_RG_DEOXYS_MOVE}{DYNAMIC_COLOR6}{DYNAMIC_COLOR5}{GREEN}ぅり{BLUE}て$"
	.string "ぃり{BLUE}{DYNAMIC_COLOR5}{GREEN}ぅり{BLUE}{DYNAMIC_COLOR5}{GREEN}ぅり{BLUE}て$"
	.incbin "baserom_jp.gba", 0x28315e, 0x3
