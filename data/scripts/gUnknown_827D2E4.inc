	nop 
	setptrbyte 0x27, 0x279A00
	fadescreen 0x27
	call 0xC030A00
	returnram 
	.string "{BLUE}{SE_PC_ON}{LIGHT_GRAY}だどた{MUS_RG_FUCHSIA}{LIGHT_RED}{SE_FAILURE}t$"
	.string "{TRANSPARENT}{MUS_RG_POKE_TOWER}{TRANSPARENT}{SE_M_CUT}{LIGHT_RED}の{SE_M_CUT}{PH_KIT_HELD}ねrカ{MUS_RG_FUCHSIA}{RED}{SE_ICE_STAIRS}l$"
	.incbin "baserom_jp.gba", 0x27d317, 0x2f
