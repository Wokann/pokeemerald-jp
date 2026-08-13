	nop 
	dowildbattle 
	waitstate 
	nop 
	fadescreen 0x27
	nop 
	setrespawn 0x27
	.byte 0xE0
	waitstate 
	writebytetoaddr 0x33, 0xE00827C6
	bufferboxname 0x27, 0xA08
	setworldmapflag 0xC0C
	gotostd 0x2
	showobject_at 0x55A9, 0x802
	end 
	.incbin "baserom_jp.gba", 0x27c63f, 0x1a0
