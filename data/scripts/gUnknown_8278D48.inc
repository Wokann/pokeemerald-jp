	nop 
	.byte 0xE9
	waitstate 
	copyvar 0x98, 0x3C0
	.byte 0xE9
	showobject_at 0x80D, 0x505
	.byte 0xF9
	.byte 0xFF
	.byte 0xF9
	.byte 0xFF
	callstd_if 0x0, 0x0
	nop 
	nop 
	nop 
	goto 0x61031E04
	mossdeepgym2 
	gotostd_if 0x8, 0x5
	goto 0x4FFF0000
	returnram 
	.incbin "baserom_jp.gba", 0x278d6f, 0x10
	.incbin "baserom_jp.gba", 0x278d7f, 0x2
	.string "{SE_BIKE_BELL}{MUS_DUMMY}{MUS_DUMMY}の{SE_M_REVERSAL}F{DARK_GRAY}töカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_I}{MUS_DUMMY}{DARK_GRAY}töカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_I}{SE_ICE_CRACK}{DARK_GRAY}töカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_I}{SE_DOWNPOUR_STOP}{DARK_GRAY}töカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_I}{SE_M_BUBBLE3}{DARK_GRAY}töカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_I}{SE_M_MIST}{DARK_GRAY}töカ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_I}{SE_M_LOCK_ON}{RED}ゃた{LIGHT_GREEN}$"
	.incbin "baserom_jp.gba", 0x278dd2, 0x1
	.incbin "baserom_jp.gba", 0x278dd3, 0xd
	.incbin "baserom_jp.gba", 0x278de0, 0x2
	.incbin "baserom_jp.gba", 0x278de2, 0x4f
