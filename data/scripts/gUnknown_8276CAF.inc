	lockall 
	setvar 0x8004, 0x7
	special CallTrainerHillFunction
	loadword 0x0, 0x823BEEC
	callstd 0x4
	releaseall 
	end 
	.string "{MUS_RG_CAUGHT}ぞ{SE_USE_ITEM}に{RED}ィ{SE_EXIT}ゆ{B_BUTTON}む{DYNAMIC_COLOR4}{MUS_B_TOWER_RS}{TRANSPARENT}{SE_RG_POKE_JUMP_FAILURE}gフら{MUS_RG_FUCHSIA}げはざ$"
	.string "{SE_EXIT}{SE_WIN_OPEN}{MUS_RG_VS_DEOXYS}に{RED}ィ{SE_NOT_EFFECTIVE}ゆ{B_BUTTON}に{RED}ィ{SE_SELECT}ゆ{B_BUTTON}に{WHITE}ぞ{SE_USE_ITEM}{DARK_GRAY}に{WHITE}{SE_NOTE_E}{TRANSPARENT}ぐはざ$"
	.incbin "baserom_jp.gba", 0x276d04, 0x8
