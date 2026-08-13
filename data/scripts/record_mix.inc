gUnknown_82470FC: @ 0x82470FC
	setvar 0x8005, 0x0
	special RecordMixingPlayerSpotTriggered
	compare_var_to_value 0x4001, 0x0
	goto_if 0x5, 0x8247150
	end 

gUnknown_8247111: @ 0x8247111
	setvar 0x8005, 0x1
	special RecordMixingPlayerSpotTriggered
	compare_var_to_value 0x4001, 0x0
	goto_if 0x5, 0x8247150
	end 

gUnknown_8247126: @ 0x8247126
	setvar 0x8005, 0x2
	special RecordMixingPlayerSpotTriggered
	compare_var_to_value 0x4001, 0x0
	goto_if 0x5, 0x8247150
	end 

gUnknown_824713B: @ 0x824713B
	setvar 0x8005, 0x3
	special RecordMixingPlayerSpotTriggered
	compare_var_to_value 0x4001, 0x0
	goto_if 0x5, 0x8247150
	end 
	bufferitemname 0x1, 0x4001
	message 0x8247FB9
	waitmessage 
	waitbuttonpress 
	releaseall 
	end 

