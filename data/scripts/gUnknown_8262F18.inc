	loadbytefromaddr 0x1A053C28
	nop 
	loadbytefromaddr 0x135006
	end 
	setflag 0x1506
	opendoor 0x3FE, 0x1620
	callnative 0x73599F00
	bufferleadmonspeciesname 0x1A
	nop 
	loadbyte 0x8, 0xB
	gettime 
	nop 
	end 
	setflag 0x2706
	.byte 0x15
	.byte 0xFF
