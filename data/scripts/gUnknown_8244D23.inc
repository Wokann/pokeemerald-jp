	.byte 0x25
	checkflag 0x1900
	nop 
	.byte 0x80
	call 0x80002180
	.byte 0xFF
	nop 
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
	.byte 0x26
	.byte 0x0D
	.byte 0x80
	playfanfare 0x2100
	.byte 0x0D
	.byte 0x80
	setworldmapflag 0x600
	setworldmapflag 0x4D9E
	gotonative 0x4F026708
	gotonative 0x6C6D6608
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
	.byte 0x25
	initclock 0x2700, 0xE21
	.byte 0x80
	nop 
	nop 
	goto_if 0x1, 0x8244DD9
	.byte 0x45
	setmysteryeventstatus 0x80
	setworldmapflag 0x400
	.byte 0xF2
	checkdecorspace 0x824
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
	.byte 0x85
	setworldmapflag 0x4F8D
	gotonative 0x1850308
	.byte 0x7F
	.byte 0x4F
	gotonative 0x1850308
	pokemartdecoration2 0x308244F
	.byte 0x83
	setworldmapflag 0x8006
	lock 
	faceplayer 
	loadword 0x0, 0x8244F92
	callstd 0x5
	compare_var_to_value 0x800D, 0x1
	goto_if 0x1, 0x8244E63
	compare_var_to_value 0x800D, 0x0
	goto_if 0x1, 0x8244E94
	.byte 0x25
	gettime 
	nop 
	compare_var_to_value 0x8004, 0x0
	goto_if 0x1, 0x8244E8B
	.byte 0x25
	.byte 0x5C
	setworldmapflag 0x2F25
	nop 
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
