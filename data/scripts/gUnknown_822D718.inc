	.byte 0x5C
	callstd 0xEE
	setworldmapflag 0x0
	addobject_at 0x22D7, 0x856
	.byte 0xD7
	compare_var_to_var 0x1608, 0x8004
	gotostd_if 0x0, 0x25
	.byte 0xF0
	nop 
	waitmessage 
	waitbuttonpress 
	closemessage 
	releaseall 
	end 
