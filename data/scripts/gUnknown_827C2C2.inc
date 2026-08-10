	nop 
	return 
	delay 0xE103
	cmdDB 0x2020815
	nop 
	nop 
	return 
	nop 
	return 
	givepcitem 0x15DE, 0x208
	end 
	nop 
	nop 
	checkitemtype 0x1C00
	hidecoinsbox 0x0, 0xC0
	.byte 0x18
	return 
	.byte 0x08
