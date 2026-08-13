	copyvar 0xC5, 0xC0
	.byte 0xF4
	waitstate 
	end 
	.string "フtカ{MUS_RG_FUCHSIA}{LIGHT_RED}{SE_PC_ON}ü$"
	.string "{SE_FAINT}{MUS_DUMMY}{MUS_DUMMY}{RED}{MUS_RG_PHOTO}フtカ{MUS_RG_FUCHSIA}{LIGHT_RED}{SE_PC_ON}ü$"
	.string "{SE_FAINT}{MUS_DUMMY}{MUS_DUMMY}{RED}{MUS_RG_PHOTO}フtカ{MUS_RG_FUCHSIA}{LIGHT_RED}{SE_PC_ON}ü$"
	.incbin "baserom_jp.gba", 0x27dda8, 0x8
