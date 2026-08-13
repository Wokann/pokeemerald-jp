	nop 
	fadescreen 0x27
	nop 
	setrespawn 0x27
	fadedefaultbgm 
	waitstate 
	gotostd_if 0x1, 0xC
	returnram 
	.incbin "baserom_jp.gba", 0x27e028, 0xbc
