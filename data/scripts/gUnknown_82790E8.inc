	nop 
	hideobject_at 0x27, 0x9F27
	nop 
	fadescreen 0x27
	gotostd_if 0x1, 0xC
	returnram 
	.string "{BLUE}{DYNAMIC_COLOR5}{LIGHT_GRAY}ヂら{MUS_RG_FUCHSIA}ワはキ{BLUE}ュ{LIGHT_RED}{SE_FAINT}{SE_DOOR}{SE_BANG}{SE_USE_ITEM}{MUS_DUMMY}{DARK_GRAY}ざぁキ{BLUE}ャ{RED}{SE_FAINT}{MUS_DUMMY}{SE_USE_ITEM}{SE_USE_ITEM}の{SE_M_COMET_PUNCH}{PH_KIT_HELD}シひキ{BLUE}ォ{RED}{SE_FAINT}{SE_DOOR}{SE_M_RAZOR_WIND2}l$"
	.string "{DARK_GRAY}シひキ{BLUE}ォ{RED}{SE_FAINT}{SE_DOOR}{TRANSPARENT}$"
	.string "d$"
	.string "{DARK_GRAY}シひキ{BLUE}ォ{RED}{SE_FAINT}{SE_DOOR}{SE_M_CUT}:$"
	.string "{DARK_GRAY}シひキ{BLUE}ォ{RED}{SE_FAINT}{SE_DOOR}{MUS_ENCOUNTER_INTENSE}f$"
	.string "{DARK_GRAY}シひキ{BLUE}ォ{RED}{SE_FAINT}{SE_DOOR}ィ$"
	.string "v$"
	.string "{DARK_GRAY}シひキ{BLUE}ォ{RED}{SE_FAINT}{SE_DOOR}ィ\n"
	.string "m$"
	.string "{RED}{DYNAMIC_COLOR1}{DYNAMIC_COLOR5}{LIGHT_GRAY}ヂら{MUS_RG_FUCHSIA}ワはキ{BLUE}ュ{LIGHT_RED}:$"
	.incbin "baserom_jp.gba", 0x279189, 0x2
	.string "{SE_BANG}{SE_USE_ITEM}{MUS_DUMMY}{DARK_GRAY}ざぁキ{BLUE}ャ{RED}:$"
	.string ":$"
	.string "{SE_USE_ITEM}{SE_USE_ITEM}の{SE_M_VITAL_THROW2}{PH_KIT_HELD}シひキ{BLUE}ォ{RED}:$"
	.incbin "baserom_jp.gba", 0x2791ad, 0x2
	.string "{SE_M_RAZOR_WIND2}l$"
	.string "{DARK_GRAY}シひキ{BLUE}ォ{RED}:$"
	.incbin "baserom_jp.gba", 0x2791bc, 0x2
	.string "{TRANSPARENT}$"
	.string "d$"
	.string "{DARK_GRAY}シひキ{BLUE}ォ{RED}:$"
	.incbin "baserom_jp.gba", 0x2791cb, 0x2
	.string "{SE_M_CUT}:$"
	.string "{DARK_GRAY}シひキ{BLUE}ォ{RED}:$"
	.incbin "baserom_jp.gba", 0x2791da, 0x2
	.string "{MUS_ENCOUNTER_INTENSE}f$"
	.string "{DARK_GRAY}シひキ{BLUE}ォ{RED}:$"
	.incbin "baserom_jp.gba", 0x2791e9, 0x2
	.string "ィ$"
	.string "v$"
	.string "{DARK_GRAY}シひキ{BLUE}ォ{RED}:$"
	.incbin "baserom_jp.gba", 0x2791f8, 0x2
	.string "ィ\n"
	.string "m$"
	.incbin "baserom_jp.gba", 0x2791fe, 0x24
