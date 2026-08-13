	nop 
	addobject_at 0x27, 0xB627
	returnram 
	.incbin "baserom_jp.gba", 0x27e580, 0x3c
	.string "{MUS_DUMMY}{SE_USE_ITEM}{RED}{MUS_RG_SURF}{BLUE}めキ{MUS_RG_FUCHSIA}{RED}{SE_N}{SE_BANG}{MUS_DUMMY}{SE_USE_ITEM}{RED}{MUS_RG_SILPH}{BLUE}めキ{MUS_RG_FUCHSIA}{RED}{SE_LEDGE}Ä$"
	.incbin "baserom_jp.gba", 0x27e5de, 0x27
