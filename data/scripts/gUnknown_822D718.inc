	.byte 0x5C
	callstd 0xEE
	setworldmapflag 0x0
	.byte 0x56
	.byte 0xD7
	compare_var_to_var 0x5608, 0x22D7
	gotostd 0x16
	call 0x25000A80
	.byte 0xF0
	nop 
	waitmessage 
	waitbuttonpress 
	closemessage 
	releaseall 
	end 
