	nop 
	setptrbyte 0x27, 0x279A00
	fadescreen 0x27
	call 0xC030A00
	returnram 
	.incbin "baserom_jp.gba", 0x27d2f3, 0x53
