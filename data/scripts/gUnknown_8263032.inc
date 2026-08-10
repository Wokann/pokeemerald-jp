	setrespawn 0x7359
	bufferleadmonspeciesname 0xA
	return 
	goto_if 0x2E, 0x462A0D00
	.byte 0xFE
	callnative 0x1001450
	loadbytefromaddr 0x2306291F
	nop 
	returnram 
	clearflag 0x215
	.byte 0x15
	.byte 0xFF
