	faceplayer 
	.byte 0x52
	bufferleadmonspeciesname 0x37
	nop 
	end 
	.byte 0x50
	givedecoration 0x4402
	killscript 
	turnvobject 0xFE, 0x9
	end 
	compare_local_to_local 0x2E, 0x14
	nop 
	gotostd_if 0x3, 0x6
	gettime 
	nop 
	returnram 
	setptrbyte 0x0, 0x20B4108
	.byte 0xFF
