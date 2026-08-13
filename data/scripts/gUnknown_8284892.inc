	nop 
	compare_addr_to_value 0x841B28, 0xC0
	setdynamicwarp 0x200, 0x19, 0xE4, 0x400
	nop 
	gotostd_if 0x3, 0x29
	call 0x6EB50300
	writebytetoaddr 0x8, 0x1050A
	nop 
	nop 
	nop 
	nop 
	call 0x3000000
	.byte 0xD1
	bufferpartymonnick 0x11, 0x208
	nop 
	compare_var_to_value 0x107, 0x9300
	checkpcitem 0x828, 0x1614
	setvar 0xB103, 0x117E
	gotostd 0x5
	call 0x600
	nop 
	nop 
	.byte 0xFF
	.byte 0xFF
	call 0x6E710300
	writebytetoaddr 0x8, 0x1050A
	nop 
	nop 
	call 0x400
	nop 
	addvar 0x1402, 0x56E4
	gotostd 0xC2
	call_if 0xE0, 0x10FF
	nop 
	goto_if 0x0, 0x30002
	setworldmapflag 0x200
	copylocal 0xE4, 0x56
	gotostd 0xC2
	call_if 0xF8, 0x400012FF
	nop 
	return 
	.string "{MUS_RG_PALLET}{MUS_RG_PALLET}{SE_RG_SS_ANNE_HORN}{MUS_RG_PALLET}とpカ{BLUE}リ{LIGHT_GREEN}t$"
	.string "{SE_SLIDING_DOOR}{SE_LOW_HEALTH}{SE_SELECT}{SE_USE_ITEM}{SE_PC_LOGIN}{SE_USE_ITEM}{DARK_GRAY}とpカ{BLUE}リ{LIGHT_GREEN}d$"
	.string "{SE_SUPER_EFFECTIVE}{SE_M_CUT}{SE_PC_ON}{SE_USE_ITEM}{SE_PC_LOGIN}{SE_USE_ITEM}{SE_PC_ON}{DARK_GRAY}わpカ{BLUE}H{LIGHT_GREEN}l$"
	.incbin "baserom_jp.gba", 0x28494c, 0x15
	.string "{SE_SLIDING_DOOR}{SE_NOTE_E}{SE_PC_OFF}{SE_PC_LOGIN}{SE_PC_LOGIN}{SE_USE_ITEM}{DARK_GRAY}わpカ{BLUE}リ{LIGHT_GREEN}t$"
	.string "{SE_SLIDING_DOOR}{SE_LOW_HEALTH}{SE_SELECT}{SE_USE_ITEM}{SE_PC_LOGIN}{SE_USE_ITEM}{DARK_GRAY}わpカ{BLUE}リ{LIGHT_GREEN}d$"
	.string "{SE_SUPER_EFFECTIVE}{SE_M_CUT}{SE_PC_ON}{SE_USE_ITEM}{SE_PC_LOGIN}{SE_USE_ITEM}{SE_PC_ON}{DARK_GRAY}でpカ{BLUE}H{LIGHT_GREEN}l$"
	.incbin "baserom_jp.gba", 0x2849a2, 0x15
	.string "{SE_SLIDING_DOOR}{SE_NOTE_E}{SE_PC_OFF}{SE_PC_LOGIN}{SE_PC_LOGIN}{SE_USE_ITEM}{DARK_GRAY}でpカ{BLUE}リ{LIGHT_GREEN}t$"
	.string "{SE_SLIDING_DOOR}{SE_LOW_HEALTH}{SE_SELECT}{SE_USE_ITEM}{SE_PC_LOGIN}{SE_USE_ITEM}{DARK_GRAY}でpカ{BLUE}リ{LIGHT_GREEN}d$"
	.incbin "baserom_jp.gba", 0x2849e1, 0x17
	.string "{SE_FAINT}{MUS_DUMMY}{SE_WIN_OPEN}{SE_USE_ITEM}{SE_PC_LOGIN}{SE_USE_ITEM}{DARK_GRAY}とpカ{BLUE}H{LIGHT_GREEN}:$"
	.incbin "baserom_jp.gba", 0x284a0d, 0x17
	.string "{SE_FAINT}{MUS_DUMMY}{SE_WIN_OPEN}{SE_USE_ITEM}{SE_PC_LOGIN}{SE_USE_ITEM}{DARK_GRAY}わpカ{BLUE}H{LIGHT_GREEN}:$"
	.incbin "baserom_jp.gba", 0x284a39, 0x17
	.string "{SE_FAINT}{MUS_DUMMY}{SE_WIN_OPEN}{SE_USE_ITEM}{SE_PC_LOGIN}{SE_USE_ITEM}{DARK_GRAY}でpカ{BLUE}H{LIGHT_GREEN}:$"
	.string "{SE_NOT_EFFECTIVE}{SE_M_LEER}{SE_SELECT}{SE_PC_LOGIN}{SE_PC_OFF}{SE_USE_ITEM}{LIGHT_RED}の{SE_M_GUST2}ぜ{DYNAMIC_COLOR2}{LIGHT_GRAY}{SE_PC_ON}なに{LIGHT_GRAY}♂ホち{BLUE}{DYNAMIC_COLOR1}{SE_RG_POKE_JUMP_SUCCESS}{MUS_DUMMY}{TRANSPARENT}{SE_PC_ON}{MUS_DUMMY}{MUS_DUMMY}た{LIGHT_GREEN}$"
	.incbin "baserom_jp.gba", 0x284a90, 0x1
	.string "ぬ{BLUE}とぬに{LIGHT_GRAY}“ンち{BLUE}{LIGHT_RED}{SE_PC_ON}{SE_RG_CARD_FLIPPING}{MUS_DUMMY}{TRANSPARENT}$"
	.incbin "baserom_jp.gba", 0x284aa4, 0x1
	.incbin "baserom_jp.gba", 0x284aa5, 0x5
