	nop 
	compare_var_to_var 0xA27, 0x2A03
	setworldmapflag 0xC
	loadbyte 0x4, 0x0
	copyvar 0xD0, 0x23F
	pokemartdecoration2 0x20856EA
	return 
	.string "t$"
	.string "t$"
	.incbin "baserom_jp.gba", 0x27aac5, 0xb
	.string "t$"
	.string "{SE_NOTE_F}{DARK_GRAY}ギvカ{MUS_RG_FUCHSIA}{LIGHT_GRAY}{SE_DOOR}t$"
	.string "{SE_PUDDLE}{DARK_GRAY}ギvカ{MUS_RG_FUCHSIA}{LIGHT_GRAY}{SE_CONTEST_PLACE}t$"
	.string "{SE_BALLOON_BLUE}{DARK_GRAY}ギvカ{MUS_RG_FUCHSIA}{LIGHT_GRAY}t$"
	.incbin "baserom_jp.gba", 0x27aaf7, 0x2
	.incbin "baserom_jp.gba", 0x27aaf9, 0xb
	.incbin "baserom_jp.gba", 0x27ab04, 0x2
	.incbin "baserom_jp.gba", 0x27ab06, 0xd
	.incbin "baserom_jp.gba", 0x27ab13, 0xd
	.string "{SE_SHOP}{DARK_GRAY}ギvカ{MUS_RG_FUCHSIA}{LIGHT_GRAY}t$"
	.incbin "baserom_jp.gba", 0x27ab2b, 0xd
	.string "{SE_DOOR}{SE_APPLAUSE}{DARK_GRAY}ギvカ{MUS_RG_FUCHSIA}{LIGHT_GRAY}{SE_DOOR}{SE_DOOR}{SE_POKENAV_ON}{DARK_GRAY}ギvカ{MUS_RG_FUCHSIA}{LIGHT_GRAY}{SE_CONTEST_PLACE}{SE_DOOR}{SE_BALL_TRAY_BALL}{DARK_GRAY}ギvカ{MUS_RG_FUCHSIA}{LIGHT_GRAY}t$"
	.incbin "baserom_jp.gba", 0x27ab5f, 0xd
	.incbin "baserom_jp.gba", 0x27ab6c, 0x5a
