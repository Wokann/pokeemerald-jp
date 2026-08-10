	nop 
	.byte 0xF0
	waitstate 
	end 
	returnram 
	.byte 0xE2
	.byte 0x56
	gotostd 0x82
	nop 
	.byte 0x08
