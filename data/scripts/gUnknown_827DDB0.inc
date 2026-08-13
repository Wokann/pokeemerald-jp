	gotostd_if 0x3, 0xE
	showobject_at 0x2862, 0x80C
	gotostd 0x8
	return 
	.string "オぱ{DYNAMIC_COLOR4}{MUS_RG_FUCHSIA}{SE_SELECT}{SE_RG_SS_ANNE_HORN}{MUS_DUMMY}{TRANSPARENT}{SE_LEDGE}{SE_USE_ITEM}{LIGHT_GRAY}オツち{MUS_RG_FUCHSIA}{MUS_RG_POKE_TOWER}{MUS_DUMMY}{MUS_RG_PALLET}{MUS_DUMMY}{TRANSPARENT}{SE_DOOR}$"
	.incbin "baserom_jp.gba", 0x27dddd, 0x20
	.incbin "baserom_jp.gba", 0x27ddfd, 0x2
	.incbin "baserom_jp.gba", 0x27ddff, 0x12
