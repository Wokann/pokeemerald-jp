	nop 
	compare_addr_to_local 0xE8840227, 0x56
	gotostd 0x28
	nop 
	end 
	.string "ピtカ{BLUE}り{SE_RG_HELP_OPEN}{MUS_RG_PALLET}ピtカ{BLUE}り{MUS_RG_OAK_LAB}{MUS_RG_PALLET}ピtカ{BLUE}り{WHITE}{SE_PC_OFF}{DARK_GRAY}ピtカ{BLUE}り{WHITE}{SE_PC_ON}{RED}リた{LIGHT_GREEN}$"
	.incbin "baserom_jp.gba", 0x27a4a3, 0x1
	.incbin "baserom_jp.gba", 0x27a4a4, 0x2
