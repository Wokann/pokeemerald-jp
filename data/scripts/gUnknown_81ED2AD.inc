	lockall 
	pokenavcall 0x81ED5EB
	waitmessage 
	clearflag 0x8A
	addvar 0x40D1, 0x1
	releaseall 
	end 
	.incbin "baserom_jp.gba", 0x1ed2be, 0x2efe
