	nop 
	addelevmenuitem 0x27, 0x9700, 0xA27, 0x2801
	setworldmapflag 0xC0C
	gotostd 0x19
	random 0xC000
	end 
	.incbin "baserom_jp.gba", 0x2780fe, 0xa
	.incbin "baserom_jp.gba", 0x278108, 0x2
	.incbin "baserom_jp.gba", 0x27810a, 0x2
	.string "{SE_BANG}l$"
	.incbin "baserom_jp.gba", 0x278110, 0xd
	.string "{SE_DOOR}{SE_DOOR}{SE_BANG}d$"
	.incbin "baserom_jp.gba", 0x278125, 0xf
	.incbin "baserom_jp.gba", 0x278134, 0x2
	.incbin "baserom_jp.gba", 0x278136, 0x22
	.string "{MUS_DUMMY}{MUS_DUMMY}{SE_BANG}l$"
	.incbin "baserom_jp.gba", 0x278160, 0x51
