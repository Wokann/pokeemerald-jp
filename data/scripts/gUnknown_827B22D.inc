	writebytetoaddr 0x37, 0x920827B2
	drawbox 
	waitstate 
	gotostd 0x8
	nop 
	faceplayer 
	waitstate 
	nop 
	setflag 0x228
	.byte 0xF8
	dotimebasedevents 
	setobjectxy 0x108, 0x3, 0x0
	nop 
	givecoins 0x200
	.byte 0xF8
	dotimebasedevents 
	setobjectxy 0x108, 0x3, 0x100
	nop 
	givecoins 0x2200
	nop 
	call 0x550D0301
	writebytetoaddr 0x8, 0x102
	call 0xB2F60E06
	waitstate 
	gotostd 0xE
	.byte 0xF6
	drawbox 
	waitstate 
	gotostd 0xE
	.byte 0xF6
	drawbox 
	waitstate 
	gotostd 0xE
	.byte 0xF6
	drawbox 
	waitstate 
	gotostd 0xE
	.byte 0xF6
	drawbox 
	waitstate 
	gotostd 0x5
	callnative 0x3010400
	killscript 
	.incbin "baserom_jp.gba", 0x27b286, 0x4e
	.string "{MUS_DUMMY}{SE_USE_ITEM}{SE_PC_LOGIN}{LIGHT_GRAY}ぅぼ{DYNAMIC_COLOR4}{MUS_RG_FUCHSIA}{SE_RG_POKE_JUMP_SUCCESS}{TRANSPARENT}{SE_SELECT}{MUS_DUMMY}{SE_WIN_OPEN}{SE_USE_ITEM}の{SE_M_MEGA_KICK2}F{SE_BIKE_BELL}てょ”ら{MUS_RG_FUCHSIA}lをキ{MUS_RG_FUCHSIA}{SE_WIN_OPEN}{MUS_DUMMY}{TRANSPARENT}{SE_NOT_EFFECTIVE}{SE_PC_ON}:$"
	.string "{SE_SLIDING_DOOR}{DARK_GRAY}lをキ{MUS_RG_FUCHSIA}{SE_WIN_OPEN}{MUS_DUMMY}{TRANSPARENT}{SE_FAINT}{SE_PC_ON}ü$"
	.string "{SE_SLIDING_DOOR}{DARK_GRAY}lをキ{MUS_RG_FUCHSIA}{SE_WIN_OPEN}{SE_RG_SS_ANNE_HORN}{TRANSPARENT}{SE_SUPER_EFFECTIVE}{SE_PC_ON}z$"
	.string "{SE_SLIDING_DOOR}{DARK_GRAY}lをキ{MUS_RG_FUCHSIA}{SE_WIN_OPEN}{SE_RG_SS_ANNE_HORN}{TRANSPARENT}{SE_NOT_EFFECTIVE}{SE_PC_ON}:$"
	.incbin "baserom_jp.gba", 0x27b340, 0x9
