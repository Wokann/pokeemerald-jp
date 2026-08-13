	nop 
	setstepcallback 0x27
	gotostd_if 0x3, 0x2
	setweather 0x571D
	gotostd 0x82
	goto_if 0x14, 0x28000000
	nop 
	setworldmapflag 0x0
	nop 
	nop 
	nop 
	copyvar 0x7E, 0x4C0
	goto 0x571DA402
	gotostd 0x82
	goto_if 0x14, 0x28000000
	nop 
	setworldmapflag 0x1800
	nop 
	nop 
	nop 
	copyvar 0x7E, 0x4C0
	goto 0x571DA402
	gotostd 0x82
	goto_if 0x14, 0x28000000
	nop 
	setworldmapflag 0xE800
	.byte 0xFF
	nop 
	nop 
	copyvar 0x7E, 0x4C0
	loadword 0x3, 0x80D4B55
	goto 0x2000105
	nop 
	nop 
	nop 
	gotostd_if 0x0, 0x1
	nop 
	return 
	.string "オぱ{DYNAMIC_COLOR4}{BLUE}{LIGHT_RED}{LIGHT_RED}{SE_PC_OFF}{SE_PC_LOGIN}{MUS_DUMMY}{SE_LEDGE}{SE_USE_ITEM}{LIGHT_GRAY}オツち{MUS_RG_FUCHSIA}{GREEN}{SE_BANG}{SE_PC_LOGIN}{SE_PC_LOGIN}{MUS_DUMMY}{SE_NOT_EFFECTIVE}ほワ{DARK_GRAY}:へキ{BLUE}ェ{SE_SELECT}{TRANSPARENT}v$"
	.string "{MUS_DUMMY}{SE_BALL_OPEN}{SE_SAVE}の{SE_M_BUBBLE}ぜ{RED}{MUS_RG_VICTORY_TRAINER}:へキ{BLUE}ェ{LIGHT_RED}r$"
	.string "t$"
	.string "{MUS_DUMMY}{SE_BALL_OPEN}{SE_SAVE}の{SE_M_BUBBLE}ぜ{RED}{MUS_RG_VICTORY_TRAINER}:へキ{BLUE}ェ{LIGHT_RED}{SE_BALL_OPEN}q$"
	.string "{MUS_DUMMY}{SE_BALL_OPEN}{SE_TRUCK_STOP}の{SE_M_BUBBLE}ぜ{RED}{MUS_RG_VICTORY_TRAINER}:へキ{BLUE}ェ{LIGHT_RED}Ä$"
	.string "▶$"
	.string "{MUS_DUMMY}{SE_LEDGE}{SE_WARP_IN}の{SE_M_BUBBLE}ぜ{RED}{MUS_RG_VICTORY_TRAINER}:へキ{BLUE}ェ{LIGHT_RED}{SE_U}v$"
	.incbin "baserom_jp.gba", 0x27fd45, 0xe
