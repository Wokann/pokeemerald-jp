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
