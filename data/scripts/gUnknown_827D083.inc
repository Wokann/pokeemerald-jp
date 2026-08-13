	nop 
	dowildbattle 
	waitstate 
	nop 
	fadeoutbgm 0x27
	nop 
	.byte 0xE0
	waitstate 
	gotostd_if 0x1, 0xC
	returnram 
	.string "{MUS_RG_FUCHSIA}ク8オ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_WIN_OPEN}{SE_PC_ON}{RED}{RED}{LIGHT_GRAY}オぱ{DYNAMIC_COLOR4}{MUS_RG_FUCHSIA}{SE_RG_POKE_JUMP_SUCCESS}{MUS_RG_PALLET}{MUS_DUMMY}{TRANSPARENT}{SE_SLIDING_DOOR}{SE_USE_ITEM}{DARK_GRAY}ふをキ{BLUE}ェ{LIGHT_GRAY}ü$"
	.string "ü$"
	.string "{MUS_DUMMY}{DARK_GRAY}ふをキ{BLUE}ェ{LIGHT_GRAY}ü$"
	.string "{SE_LEDGE}{MUS_DUMMY}の{SE_M_RAZOR_WIND}ぜ{RED}{MUS_RG_VICTORY_GYM_LEADER}ふをキ{BLUE}ェ{LIGHT_GRAY}{SE_LEDGE}ü$"
	.incbin "baserom_jp.gba", 0x27d0da, 0x18
