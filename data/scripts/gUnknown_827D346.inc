	gotostd_if 0x1, 0x3
	hideobject_at 0x15F5, 0x805
	nop 
	call 0xA9580218
	addobject 0x208
	end 
	.string "{SE_PC_OFF}{SE_PC_ON}の{SE_M_SWAGGER}F{RED}{MUS_RG_POKE_TOWER}ク8オ{MUS_RG_FUCHSIA}{DARK_GRAY}{SE_PC_OFF}{SE_PC_ON}の{SE_M_SWAGGER}F{LIGHT_RED}{SE_PIKE_CURTAIN_CLOSE}{SE_RG_DEOXYS_MOVE}{DARK_GRAY}ミんキ{MUS_RG_FUCHSIA}{SE_POKENAV_CALL}{TRANSPARENT}{SE_PC_OFF}{SE_USE_ITEM}$"
	.incbin "baserom_jp.gba", 0x27d384, 0x1
	.string "{SE_FAINT}$"
	.incbin "baserom_jp.gba", 0x27d388, 0x1
	.incbin "baserom_jp.gba", 0x27d389, 0x7
