	nop 
	setworldmapflag 0x28
	playse 0x327
	hidecoinsbox 0xBA, 0x15
	gotostd 0x5
	nop 
	call 0x6E710308
	writebytetoaddr 0x8, 0x781050A
	gotostd 0x0
	nop 
	nop 
	returnram 
	.string "{TRANSPARENT}$"
	.string "ァ{RED}{DYNAMIC_COLOR5}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{DYNAMIC_COLOR5}$"
	.string "ぅり{BLUE}{LIGHT_GRAY}ムホち{BLUE}{DYNAMIC_COLOR1}{LIGHT_RED}ゥ{LIGHT_GREEN}{SE_PC_OFF}{SE_NOT_EFFECTIVE}{MUS_DUMMY}$"
	.incbin "baserom_jp.gba", 0x2831f6, 0x17
