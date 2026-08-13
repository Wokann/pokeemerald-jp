	nop 
	.byte 0xF8
	waitstate 
	nop 
	.byte 0xF7
	waitstate 
	gotostd_if 0x3, 0x2A
	setworldmapflag 0x9719
	nop 
	showcoinsbox 0x1D, 0x97
	nop 
	showcoinsbox 0xA, 0x3
	takecoins 0x1591
	gotostd 0x2
	call 0xFFC0FFC0
	setworldmapflag 0x0
	nop 
	end 
	.string "みつキ{MUS_RG_FUCHSIA}{SE_PC_OFF}{MUS_DUMMY}{MUS_DUMMY}{TRANSPARENT}{RED}{MUS_RG_POKE_CENTER}みつキ{BLUE}{LIGHT_GRAY}{SE_PC_OFF}{MUS_DUMMY}{SE_RG_SS_ANNE_HORN}{TRANSPARENT}{RED}{MUS_RG_POKE_CENTER}みつキ{BLUE}{RED}{SE_PC_OFF}{MUS_DUMMY}{MUS_RG_PALLET}{TRANSPARENT}{RED}{MUS_RG_POKE_CENTER}みつキ{BLUE}{RED}{SE_PC_OFF}{MUS_DUMMY}{TRANSPARENT}{SE_PC_OFF}{RED}り{LIGHT_GRAY}♂ダな{MUS_RG_FUCHSIA}{RED}F$"
	.incbin "baserom_jp.gba", 0x282cf7, 0x57
