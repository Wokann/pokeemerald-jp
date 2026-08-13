	lockall 
	setvar 0x4097, 0x1
	playse 0x9
	special IsCurSecretBaseOwnedByAnotherPlayer
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8245C8A
	clearflag 0xAD
	special EnterSecretBase
	setvar 0x4089, 0x0
	waitstate 
	end 
	.incbin "baserom_jp.gba", 0x245c8a, 0x131
