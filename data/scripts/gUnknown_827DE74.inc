	setptrbyte 0x82, 0x50827DE
	call 0x62640E01
	delay 0x808
	gotostd_if 0x2, 0x19
	vmessage 0x580EC000
	cleartrainerflag 0x828
	returnram 
	.string "{BLUE}{BLUE}の{SE_M_SUPERSONIC}F{LIGHT_GRAY}オツち{MUS_RG_FUCHSIA}{MUS_RG_POKE_TOWER}{MUS_DUMMY}{MUS_RG_PALLET}{MUS_DUMMY}{TRANSPARENT}{SE_DOOR}$"
	.incbin "baserom_jp.gba", 0x27dea6, 0xa
	.incbin "baserom_jp.gba", 0x27deb0, 0x2
	.incbin "baserom_jp.gba", 0x27deb2, 0xf
