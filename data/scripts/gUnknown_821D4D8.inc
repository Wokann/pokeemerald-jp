	lockall 
	goto 0x821D490
	end 
	special GetCurSecretBaseRegistrationValidity
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x821D51E
	compare_var_to_value 0x800D, 0x2
	goto_if 0x1, 0x821D541
	special DeleteRegistry_Yes
	loadword 0x0, 0x82465E7
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x821D490
	loadword 0x0, 0x824664D
	callstd 0x3
	special ToggleCurSecretBaseRegistry
	special DoSecretBasePCTurnOffEffect
	releaseall 
	end 
	loadword 0x0, 0x82465FD
	callstd 0x5
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x821D490
	loadword 0x0, 0x8246658
	callstd 0x3
	special ToggleCurSecretBaseRegistry
	special DoSecretBasePCTurnOffEffect
	releaseall 
	end 
	loadword 0x0, 0x824661D
	callstd 0x3
	special DoSecretBasePCTurnOffEffect
	closemessage 
	releaseall 
	end 
	loadword 0x0, 0x8246688
	callstd 0x4
	goto 0x821D490
	end 
	special DoSecretBasePCTurnOffEffect
	closemessage 
	releaseall 
	end 
	special SetSecretBaseSecretsTvFlags_Poster
	end 
	special SetSecretBaseSecretsTvFlags_MiscFurnature
	end 
	special SetSecretBaseSecretsTvFlags_LargeDecorationSpot
	end 
	special SetSecretBaseSecretsTvFlags_SmallDecorationSpot
	end 
