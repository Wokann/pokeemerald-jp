	lockall 
	pokenavcall 0x81DE1A8
	waitmessage 
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, 0x81DE221
	callstd 0x4
	waitfanfare 
	closemessage 
	delay 0x1E
	setflag 0xD6
	clearflag 0x88
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x1dde15, 0x49e2
