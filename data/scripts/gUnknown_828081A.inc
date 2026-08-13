	nop 
	setrespawn 0x27
	fadescreen 0x27
	gotostd_if 0x3, 0xC
	returnram 
	.string "{BLUE}の{SE_M_VITAL_THROW2}ぜ{SE_SLIDING_DOOR}ぜ{BLUE}り{BLUE}つ{WHITE}ユ{BLUE}り{BLUE}て！{BLUE}り{BLUE}{LIGHT_RED}{DYNAMIC_COLOR2}{LIGHT_GRAY}{DYNAMIC_COLOR4}{MUS_RG_FUCHSIA}ワはキ{BLUE}ャ{LIGHT_RED}:$"
	.incbin "baserom_jp.gba", 0x280848, 0x2
	.string "{SE_BANG}{SE_USE_ITEM}{SE_USE_ITEM}{DARK_GRAY}ざぁキ{BLUE}ォ{RED}:$"
	.string ":$"
	.incbin "baserom_jp.gba", 0x28085b, 0x6c
	.incbin "baserom_jp.gba", 0x2808c7, 0x1a
