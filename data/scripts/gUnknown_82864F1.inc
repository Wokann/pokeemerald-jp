	nop 
	.byte 0xF0
	waitstate 
	end 
	returnram 
	.byte 0xE2
	addobject_at 0x8208, 0x8
