	setvar 0x8004, 0x7
	special CallBattlePyramidFunction
	callstd 0x1
	compare_var_to_value 0x8007, 0x0
	goto_if 0x1, 0x822D750
	setvar 0x8004, 0x8
	special CallBattlePyramidFunction
	end 
