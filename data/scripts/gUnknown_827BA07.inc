	nop 
	loadbytefromaddr 0x3010A27
	waitdooranim 
	.byte 0x56
	loadbyte 0x8, 0x2
	nop 
	end 
	setvaddress 0x820856F2
	nop 
	goto 0x8903010B
	waitmovement 0x810
	end 
	end 
	nop 
	nop 
	end 
	nop 
	compare_local_to_value 0xA7, 0x0
	showcoinsbox 0x26, 0x2
	.byte 0x08
