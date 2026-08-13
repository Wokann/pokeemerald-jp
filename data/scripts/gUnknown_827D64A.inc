	compare_local_to_value 0x66, 0x0
	showcoinsbox 0x1C, 0x2
	return 
	.string "べぷち{BLUE}{LIGHT_RED}{SE_PC_OFF}{MUS_DUMMY}{MUS_DUMMY}{MUS_RG_PALLET}ミんキ{MUS_RG_FUCHSIA}{SE_POKENAV_CALL}{TRANSPARENT}{SE_DOOR}{SE_PC_LOGIN}$"
	.incbin "baserom_jp.gba", 0x27d66b, 0x1
	.string "{SE_SUPER_EFFECTIVE}$"
	.incbin "baserom_jp.gba", 0x27d66f, 0x1
	.incbin "baserom_jp.gba", 0x27d670, 0x4
