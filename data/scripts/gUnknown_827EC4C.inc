	gotostd_if 0x1, 0x28
	setworldmapflag 0xC0C
	gotostd 0x0
	setfieldeffectarg 0x27, 0x5802
	gettime 
	setobjectxy 0x208, 0x105, 0x100
	nop 
	nop 
	nop 
	call_if 0x0, 0x1F050000
	.byte 0x95
	showcontestresults 
	copybyte 0xB70708, 0x3FFFC0
	call 0x400
	nop 
	gotostd_if 0x0, 0x2
	loadbyte 0x17, 0x57
	gotostd 0x2
	goto 0xC0014
	nop 
	nop 
	returnram 
	.string "{TRANSPARENT}{SE_BANG}{DARK_GRAY}たぬキ{MUS_RG_FUCHSIA}{LIGHT_RED}{SE_BANG}ä$"
	.string "{MUS_DUMMY}ä$"
	.string "{SE_BANG}{SE_RG_DEOXYS_MOVE}{DYNAMIC_COLOR5}ぷyら{BLUE}{DYNAMIC_COLOR5}ぷyら{BLUE}{DYNAMIC_COLOR5}ぷyら{MUS_RG_FUCHSIA}クんキ{MUS_RG_FUCHSIA}{LIGHT_RED}{SE_PC_ON}m$"
	.incbin "baserom_jp.gba", 0x27ecba, 0xaf
	.string "{MUS_DUMMY}ä$"
	.incbin "baserom_jp.gba", 0x27ed6d, 0x16
