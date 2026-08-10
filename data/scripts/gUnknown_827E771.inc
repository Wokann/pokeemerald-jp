	nop 
	vcall_if 0x27, 0xC29030A
	returnram 
	gotostd 0x1C
	.byte 0xA8
	nop 
	setdynamicwarp 0x110A, 0xE, 0xE7D6, 0x827
	setmysteryeventstatus 0xD6
	.byte 0xE7
	waitstate 
	gotostd 0xE
	buffercontesttype 
	.byte 0xE7
	waitstate 
	gotostd 0xE
	buffercontesttype 
	.byte 0xE7
	waitstate 
	gotostd 0xE
	buffercontesttype 
	.byte 0xE7
	waitstate 
	gotostd 0xE
	buffercontesttype 
	.byte 0xE7
	waitstate 
	gotostd 0xE
	buffercontesttype 
	.byte 0xE7
	waitstate 
	gotostd 0x4
	braillemessage 0x3F00941C
	loadbytefromaddr 0x62550302
	writebytetoaddr 0x8, 0x40602
	end 
	nop 
	end 
	nop 
	nop 
	nop 
	returnram 
	nop 
	setorcopyvar 0x468, 0x30A
	addobject 0xD4B
	gotostd 0x2
	goto 0x20001
	nop 
	nop 
	loadword 0x0, 0xB050001
	return 
	killscript 
	gotostd 0x2
	delay 0x5718
	gotostd 0x2
	goto_if 0x0, 0x30FFE800
	nop 
	.byte 0xF0
	nop 
	setworldmapflag 0x0
	nop 
	.byte 0x04
	.byte 0x07
	.byte 0x0F
