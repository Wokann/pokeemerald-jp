	fadescreen 0x1
	special ChooseHalfPartyForBattle
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x82470D3
	setvar 0x8005, 0x3
	special ColosseumPlayerSpotTriggered
	end 
	.incbin "baserom_jp.gba", 0x2470d3, 0x1
