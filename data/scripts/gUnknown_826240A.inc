	lockall 
	special GetPokeblockFeederInFront
	compare_var_to_value 0x800D, 0xFFFF
	goto_if 0x5, 0x8262449
	loadword 0x0, 0x82624B7
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x826242E
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x26242e, 0x8c5
