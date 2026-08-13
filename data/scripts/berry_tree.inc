gUnknown_8244D23: @ 0x8244D23
	special EventObjectInteractionGetBerryTreeData
	copyvar 0x8000, 0x8004
	compare_var_to_value 0x8000, 0xFF
	goto_if 0x1, 0x8244D79
	compare_var_to_value 0x8000, 0x0
	goto_if 0x1, 0x8244D83
	compare_var_to_value 0x8000, 0x1
	goto_if 0x1, 0x8244DDB
	compare_var_to_value 0x8000, 0x2
	goto_if 0x1, 0x8244DE8
	compare_var_to_value 0x8000, 0x3
	goto_if 0x1, 0x8244DF5
	compare_var_to_value 0x8000, 0x4
	goto_if 0x1, 0x8244E02
	compare_var_to_value 0x8000, 0x5
	goto_if 0x1, 0x8244E3F
	end 
	lockall 
	message 0x8245069
	waitmessage 
	waitbuttonpress 
	releaseall 
	end 
	lock 
	faceplayer 
	specialvar 0x800D, PlayerHasBerries
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8244D9E
	message 0x8244F02
	waitmessage 
	waitbuttonpress 
	release 
	end 
	loadword 0x0, 0x8244F0D
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8244DBD
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8244DD9
	end 
	fadescreen 0x1
	closemessage 
	special Bag_ChooseBerry
	compare_var_to_value 0x800E, 0x0
	goto_if 0x1, 0x8244DD9
	takeitem 0x800E, 0x1
	call 0x8244EF2
	release 
	end 
	lockall 
	message 0x8244F3D
	waitmessage 
	waitbuttonpress 
	goto 0x8244EA8
	lockall 
	message 0x8244F4D
	waitmessage 
	waitbuttonpress 
	goto 0x8244EA8
	lockall 
	message 0x8244F5A
	waitmessage 
	waitbuttonpress 
	goto 0x8244EA8
	call 0x8244E14
	lockall 
	message 0x8244F6E
	waitmessage 
	waitbuttonpress 
	goto 0x8244EA8
	compare_var_to_value 0x8005, 0x0
	goto_if 0x1, 0x8244E38
	compare_var_to_value 0x8005, 0x4
	goto_if 0x1, 0x8244E31
	bufferstring 0x1, 0x8244F8D
	return 
	bufferstring 0x1, 0x8244F7F
	return 
	bufferstring 0x1, 0x8244F88
	return 
	buffernumberstring 0x1, 0x8006
	lock 
	faceplayer 
	loadword 0x0, 0x8244F92
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8244E63
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8244E94
	special EventObjectInteractionPickBerryTree
	compare_var_to_value 0x8004, 0x0
	goto_if 0x1, 0x8244E8B
	special sub_080EF838
	special EventObjectInteractionRemoveBerryTree
	message 0x8244FAF
	playfanfare 0x183
	waitmessage 
	waitfanfare 
	waitbuttonpress 
	message 0x8244FC2
	waitmessage 
	waitbuttonpress 
	release 
	end 
	message 0x8244FEF
	waitmessage 
	waitbuttonpress 
	release 
	end 
	message 0x8245011
	waitmessage 
	waitbuttonpress 
	release 
	end 

gUnknown_8244E9D: @ 0x8244E9D
	lockall 
	special EventObjectInteractionGetBerryTreeData
	call 0x8244EF2
	releaseall 
	end 
	checkitem 0x10C, 0x1
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8244ED6
	loadword 0x0, 0x8245027
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8244EDC
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8244ED6
	releaseall 
	end 

