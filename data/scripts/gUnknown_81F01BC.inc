	lockall 
	checkplayergender 
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x81F01D5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x81F01FB
	end 
	setvar 0x8004, 0x1
	special DoLotteryCornerComputerEffect
	playse 0x4
	loadword 0x0, 0x8243B10
	callstd 0x4
	special BedroomPC
	releaseall 
	end 
