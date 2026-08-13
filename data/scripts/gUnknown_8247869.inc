	lockall 
	checkflag 0x861
	goto_if 0x0, 0x824701E
	specialvar 0x800D, IsWirelessAdapterConnected
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8247893
	fadescreen 0x1
	special sub_08019EE4
	waitstate 
	loadword 0x0, 0x8247FE3
	callstd 0x4
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x247893, 0x3e6
