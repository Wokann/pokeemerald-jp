	writebytetoaddr 0x37, 0x920827B2
	drawbox 
	waitstate 
	gotostd 0x8
	nop 
	faceplayer 
	waitstate 
	nop 
	setflag 0x228
	.byte 0xF8
	dotimebasedevents 
	setobjectxy 0x108, 0x3, 0x0
	nop 
	givecoins 0x200
	.byte 0xF8
	dotimebasedevents 
	setobjectxy 0x108, 0x3, 0x100
	nop 
	givecoins 0x2200
	nop 
	call 0x550D0301
	writebytetoaddr 0x8, 0x102
	call 0xB2F60E06
	waitstate 
	gotostd 0xE
	.byte 0xF6
	drawbox 
	waitstate 
	gotostd 0xE
	.byte 0xF6
	drawbox 
	waitstate 
	gotostd 0xE
	.byte 0xF6
	drawbox 
	waitstate 
	gotostd 0xE
	.byte 0xF6
	drawbox 
	waitstate 
	gotostd 0x5
	callnative 0x3010400
	killscript 
	.incbin "baserom_jp.gba", 0x27b286, 0xc3
