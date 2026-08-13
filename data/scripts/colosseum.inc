gUnknown_8247053: @ 0x8247053
	setvar 0x8005, 0x0
	special ColosseumPlayerSpotTriggered
	end 

gUnknown_824705D: @ 0x824705D
	setvar 0x8005, 0x1
	special ColosseumPlayerSpotTriggered
	end 

gUnknown_8247067: @ 0x8247067
	fadescreen 0x1
	special ChooseHalfPartyForBattle
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x82470D3
	setvar 0x8005, 0x0
	special ColosseumPlayerSpotTriggered
	end 

gUnknown_8247082: @ 0x8247082
	fadescreen 0x1
	special ChooseHalfPartyForBattle
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x82470D3
	setvar 0x8005, 0x1
	special ColosseumPlayerSpotTriggered
	end 

gUnknown_824709D: @ 0x824709D
	fadescreen 0x1
	special ChooseHalfPartyForBattle
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x82470D3
	setvar 0x8005, 0x2
	special ColosseumPlayerSpotTriggered
	end 

gUnknown_82470B8: @ 0x82470B8
	fadescreen 0x1
	special ChooseHalfPartyForBattle
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x82470D3
	setvar 0x8005, 0x3
	special ColosseumPlayerSpotTriggered
	end 
	end 

