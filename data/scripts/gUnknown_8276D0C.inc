	.byte 0x5C
	returnram 
	.byte 0xEE
	setworldmapflag 0x0
	.byte 0x56
	.byte 0xD7
	compare_var_to_var 0x5608, 0x22D7
	gotostd 0x16
	call 0x25000B80
	.byte 0xF8
	setworldmapflag 0x6D66
	closemessage 
	end 
	setobjectxyperm 0x645D, 0x326, 0x7200
	checkplayergender 
	gotobeatenscript 
	waitmoncry 
	choosecontestmon 
	giveitem 0xAB0D, 0x6FE
	gettime 
	checkitemspace 0x2E, 0xD44
	.byte 0xFF
