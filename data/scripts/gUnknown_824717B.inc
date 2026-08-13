	loadword 0x0, 0x8247E87
	callstd 0x4
	closemessage 
	end 
	special sub_08097EFC
	loadword 0x0, 0x8247ECC
	callstd 0x4
	special sub_08097F24
	closemessage 
	end 
	special sub_08097EFC
	loadword 0x0, 0x8247EEA
	callstd 0x4
	special sub_08097F24
	closemessage 
	end 
	compare_var_to_value 0x4000, 0x0
	goto_if 0x5, 0x82471BF
	special sub_08097EFC
	message 0x8247FA2
	waitmessage 
	waitbuttonpress 
	special sub_08097F24
	closemessage 
	end 
	special sub_08097EFC
	message 0x8247F08
	waitmessage 
	waitbuttonpress 
	special sub_08097F24
	closemessage 
	end 
