	nop 
	waitmessage 
	waitstate 
	nop 
	message 0x53050327
	loadbyte 0x8, 0x2
	nop 
	copyvar 0xC1, 0x5C0
	end 
	.string "ざÖカ{MUS_RG_FUCHSIA}{TRANSPARENT}ふ{SE_M_SWAGGER}F{MUS_RG_SS_ANNE}{LIGHT_RED}{RED}{MUS_RG_NEW_GAME_INTRO}ミÖカ{BLUE}ェ{SE_RG_HELP_ERROR}{TRANSPARENT}x$"
	.string "p$"
	.string "の{SE_M_SWAGGER2}ぜ{RED}{MUS_RG_VICTORY_GYM_LEADER}ミÖカ{BLUE}ェ{SE_RG_HELP_ERROR}{TRANSPARENT}{SE_BANG}p$"
	.incbin "baserom_jp.gba", 0x27bdf4, 0x6
