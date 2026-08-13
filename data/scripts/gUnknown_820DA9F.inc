	lockall 
	checkplayergender 
	compare_var_to_value 0x800D, 0x0
	call_if 0x1, 0x820DABD
	compare_var_to_value 0x800D, 0x1
	call_if 0x1, 0x820DAC4
	closemessage 
	clearflag 0x75
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x20dabd, 0xdd37
