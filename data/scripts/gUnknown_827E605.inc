	nop 
	.byte 0x56
	waitstate 
	nop 
	setvaddress 0x10000C27
	end 
	mossdeepgym2 
	compare_var_to_value 0x857, 0x301
	delay 0x0
	nop 
	setvaddress 0x190A0427
	gotoram 
	nop 
	showcoinsbox 0xE, 0xA0
	.byte 0xE5
	waitstate 
	gotostd 0x5
	.byte 0x04
	setworldmapflag 0x80D
