	nop 
	setstepcallback 0x27
	setmysteryeventstatus 0x43
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0xE
	getpartysize 
	.byte 0xFC
	waitstate 
	gotostd 0x3
	addobject 0xD4B
	gotostd 0x5
	goto 0x30001
	nop 
	nop 
	loadword 0x0, 0x55030001
	cleartrainerflag 0x811
	end 
	.incbin "baserom_jp.gba", 0x27fb7f, 0xda
