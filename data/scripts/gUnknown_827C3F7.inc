	nop 
	.byte 0xE6
	waitstate 
	nop 
	.byte 0xE1
	waitstate 
	nop 
	message 0xECF80227
	addobject_at 0xB08, 0x200
	nop 
	dotimebasedevents 
	nop 
	copyvar 0xBA, 0x4C0
	goto_if 0x2, 0x856EE30
	returnram 
	.string "{SE_USE_ITEM}{TRANSPARENT}{RED}{RED}ふ{SE_M_TAIL_WHIP}F{MUS_RG_RIVAL_EXIT}{LIGHT_RED}{RED}{MUS_RG_FUCHSIA}ミÖカ{BLUE}ェ{SE_RG_HELP_ERROR}{TRANSPARENT}x$"
	.string "p$"
	.string "の{SE_M_SWAGGER2}ぜ{LIGHT_RED}{RED}{MUS_RG_VICTORY_GYM_LEADER}ミÖカ{BLUE}ェ{SE_RG_HELP_ERROR}{TRANSPARENT}{SE_BANG}p$"
	.incbin "baserom_jp.gba", 0x27c446, 0x5
