	addobject 0x6F91
	setobjectxy 0x5B1, 0x5, 0x1FD
	.byte 0xFD
	goto 0x599FFBAB
	drawboxtext 0x7E, 0x3E, 0x6, 0x2E
	copyvar 0x2600, 0xD03
	dotimebasedevents 
	.byte 0xFE
	compare_addr_to_addr 0x800130E, 0x619292A
	end 
	.string "？$"
	.string "{LIGHT_GRAY}ん{SE_M_SING}み{DYNAMIC_COLOR5}るほど\n"
	.string "ポケモン{SE_WARP_IN}つ{GREEN}ま{RED}{SE_SHIP}{DARK_GRAY}{MUS_RG_GAME_FREAK}の{GREEN}$"
