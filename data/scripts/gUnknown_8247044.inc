	lockall 
	.byte 0x16
	call 0x25000080
	.byte 0xC4
	nop 
	waitbuttonpress 
	.byte 0x25
	callstd 0x2
	releaseall 
	end 
