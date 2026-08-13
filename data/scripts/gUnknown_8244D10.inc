	special ShouldTryGetTrainerScript
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8244D20
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x244d20, 0x3
