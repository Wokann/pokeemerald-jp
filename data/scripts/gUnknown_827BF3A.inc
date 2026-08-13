	nop 
	setmonmetlocation 0x27, 0xD3
	waitstate 
	nop 
	playse 0xC27
	nop 
	loadbyte 0x2, 0x58
	gettime 
	setobjectxy 0x208, 0x105, 0x100
	nop 
	nop 
	nop 
	loadbyte 0x0, 0x0
	nop 
	goto 0x56EAA002
	gotostd 0x2
	end 
	.string "{SE_M_HARDEN}{SE_BALL_BOUNCE_1}{LIGHT_GRAY}じモ{DYNAMIC_COLOR1}{BLUE}{LIGHT_GRAY}{SE_SELECT}{TRANSPARENT}{SE_FAINT}{SE_FAINT}{MUS_DUMMY}{SE_USE_ITEM}の{SE_M_MOONLIGHT}{TRANSPARENT}{RED}{MUS_RG_BERRY_PICK}Vvカ{BLUE}{MUS_RG_VS_MEWTWO}ä$"
	.string "{MUS_DUMMY}{RED}{MUS_RG_BERRY_PICK}Vvカ{BLUE}{MUS_RG_VS_MEWTWO}t$"
	.incbin "baserom_jp.gba", 0x27bf90, 0x3a
