	nop 
	setstepcallback 0x27
	setmysteryeventstatus 0x43
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0x3
	addobject 0xD4B
	gotostd 0x5
	goto 0x30001
	nop 
	nop 
	loadword 0x0, 0x55030001
	cleartrainerflag 0x811
	end 
	.string "{GREEN}{SE_PC_ON}{SE_USE_ITEM}{SE_PC_LOGIN}{MUS_DUMMY}{SE_NOT_EFFECTIVE}ほワ{DARK_GRAY}Bへキ{BLUE}ェ{LIGHT_GRAY}{SE_ICE_CRACK}{SE_U}{SE_BANG}{DARK_GRAY}Bへキ{BLUE}ェ{LIGHT_GRAY}q$"
	.string "{SE_UNLOCK}{SE_BANG}{DARK_GRAY}Bへキ{BLUE}ェ{LIGHT_GRAY}{SE_LAVARIDGE_FALL_WARP}p$"
	.string "{SE_BANG}{DARK_GRAY}Bへキ{BLUE}ェ{LIGHT_GRAY}b$"
	.string "b$"
	.incbin "baserom_jp.gba", 0x27fbbe, 0x1e
	.string "Z$"
	.string "{SE_BANG}{DARK_GRAY}Bへキ{BLUE}ェ{LIGHT_GRAY}X$"
	.string "p$"
	.string "{SE_BANG}{DARK_GRAY}Bへキ{BLUE}ェ{LIGHT_GRAY}{SE_WARP_OUT}{SE_EXIT}{SE_BANG}の{SE_M_DIG}ぜ{RED}{MUS_RG_SURF}Bへキ{BLUE}ェ{LIGHT_GRAY}{SE_ICE_CRACK}{MUS_DUMMY}{SE_BANG}{DARK_GRAY}Bへキ{BLUE}ェ{LIGHT_GRAY}a$"
	.string "ä$"
	.string "{SE_BANG}{DARK_GRAY}Bへキ{BLUE}ェ{LIGHT_GRAY}{SE_FAINT}X$"
	.string "{SE_BANG}{DARK_GRAY}Bへキ{BLUE}ェ{LIGHT_GRAY}:$"
	.incbin "baserom_jp.gba", 0x27fc30, 0x29
