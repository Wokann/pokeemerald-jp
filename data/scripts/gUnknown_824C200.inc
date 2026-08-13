	faceplayer 
	bufferleadmonspeciesname 0x63
	dotrainerbattle 
	moveobjectoffscreen 0x69FF
	waitmoncry 
	multichoice 0x79, 0x77, 0x7E, 0x58
	.byte 0xFF
	dotrainerbattle 
	waitmoncry 
	messageautoscroll 0x587E77AE
	.byte 0xFF
	lock 
	waitmovement_at 0xAE9B, 0x777E
	showobject_at 0x6FFF, 0x5D60
	waitmoncry 
	showcontestwinner 0x7E
	showobject_at 0x12FF, 0x30C
	gettime 
	.byte 0xFF
	goto_if 0x50, 0xFF0B260A
	return 
	.incbin "baserom_jp.gba", 0x24c232, 0x249
