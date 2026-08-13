	nop 
	.byte 0xE2
	waitstate 
	copyvar 0xD4, 0x2C0
	removeobject_at 0x56F5, 0x803
	end 
	.string "{MUS_DUMMY}{SE_BANG}{RED}{DYNAMIC_COLOR6}の{SE_M_CHARM}F{DARK_GRAY}エöカ{BLUE}{MUS_RG_POKE_CENTER}x$"
	.incbin "baserom_jp.gba", 0x286366, 0x14
