	nop 
	doweather 
	waitstate 
	nop 
	playse 0xA27
	return 
	returnram 
	returnram 
	gotostd 0x2
	showobject_at 0x572E, 0x802
	goto 0x10001
	nop 
	nop 
	call 0x533ED00
	call 0xF5950E03
	waitstate 
	gotostd 0x5
	call 0x5F660E0F
	delay 0x508
	end 
	showobject_at 0x572E, 0x802
	goto 0x10001
	call 0xED000000
	playbgm 0xB05, 0x3
	killscript 
	.byte 0x08
