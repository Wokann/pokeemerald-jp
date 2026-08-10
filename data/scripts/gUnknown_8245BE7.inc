	lockall 
	dofieldeffect 0x1B
	waitstate 
	goto 0x8245BFC
	end 
	loadword 0x0, 0x82450B0
	callstd 0x4
	releaseall 
	end 
	loadword 0x0, 0x82450F1
	callstd 0x4
	goto 0x8245C0A
	end 
	closemessage 
	playse 0x9
	setvar 0x4097, 0x0
	setflag 0xAD
	special SetPlayerSecretBase
	special EnterSecretBase
	setvar 0x8004, 0x0
	setvar 0x8005, 0x0
	special InitSecretBaseDecorationSprites
	setvar 0x4089, 0x1
	waitstate 
	end 
	applymovement 0xFF, 0x8245C63
	waitmovement 0x0
	setvar 0x4097, 0x1
	loadword 0x0, 0x821D613
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8245C5A
	closemessage 
	playse 0x9
	special ClearAndLeaveSecretBase
	end 
	closemessage 
	setflag 0x60
	special EnterNewlyCreatedSecretBase
	end 
	callstd 0x9
	.byte 0xFE
