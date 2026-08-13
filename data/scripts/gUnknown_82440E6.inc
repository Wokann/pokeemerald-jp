	lockall 
	special TryFieldPoisonWhiteOut
	waitstate 
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8244103
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, 0x8244122
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x244103, 0x142
