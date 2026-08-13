	nop 
	setvar 0x28, 0x2797
	gotostd_if 0x1, 0x28
	setworldmapflag 0xC0C
	gotostd 0x19
	playslotmachine 0xC000
	end 
	.incbin "baserom_jp.gba", 0x2781c3, 0xa
	.incbin "baserom_jp.gba", 0x2781cd, 0x2
	.incbin "baserom_jp.gba", 0x2781cf, 0x2
	.string "{SE_BANG}l$"
	.incbin "baserom_jp.gba", 0x2781d5, 0xd
	.string "{SE_DOOR}{SE_DOOR}{SE_BANG}d$"
	.incbin "baserom_jp.gba", 0x2781ea, 0xf
	.incbin "baserom_jp.gba", 0x2781f9, 0x2
	.incbin "baserom_jp.gba", 0x2781fb, 0x22
	.string "{MUS_DUMMY}{MUS_DUMMY}{SE_BANG}l$"
	.incbin "baserom_jp.gba", 0x278225, 0x51
