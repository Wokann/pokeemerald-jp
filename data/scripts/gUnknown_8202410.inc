	lockall 
	pokenavcall 0x82029DC
	waitmessage 
	delay 0x1E
	playfanfare 0x1CC
	loadword 0x0, 0x8202AB0
	callstd 0x4
	waitfanfare 
	closemessage 
	delay 0x1E
	setflag 0x1D3
	clearflag 0x80
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x202432, 0xb650
