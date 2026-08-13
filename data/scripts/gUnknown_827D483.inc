	nop 
	.byte 0xEA
	waitstate 
	end 
	.string "クんキ{MUS_RG_FUCHSIA}{MUS_RG_SURF}{MUS_DUMMY}{MUS_DUMMY}{TRANSPARENT}{SE_FAINT}{MUS_DUMMY}{MUS_RG_SURF}ネüカ{SE_DOOR}{DARK_GRAY}:$"
	.incbin "baserom_jp.gba", 0x27d4a1, 0x2
	.incbin "baserom_jp.gba", 0x27d4a3, 0xb
	.incbin "baserom_jp.gba", 0x27d4ae, 0x41
