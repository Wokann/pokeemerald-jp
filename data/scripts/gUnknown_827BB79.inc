	nop 
	loadbytefromaddr 0x28030A28
	setworldmapflag 0x100C
	nop 
	end 
	.string "Rbコ{BLUE}{MUS_CAVE_OF_ORIGIN}{SE_USE_ITEM}{RED}ちふ{SE_M_SKETCH}ぜた{RED}{RED}ぃ{RED}ねの{SE_M_SKETCH}ぜ{RED}{DYNAMIC_COLOR1}{LIGHT_GRAY}チヤ{DYNAMIC_COLOR1}{BLUE}{LIGHT_RED}{SE_RG_POKE_JUMP_SUCCESS}{TRANSPARENT}$"
	.incbin "baserom_jp.gba", 0x27bba8, 0x10
