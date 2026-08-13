	nop
	setptrbyte 0x28, 0x128030A
	returnram
	returnram
	gotostd 0x3
	playfanfare 0xD4A
	gotostd 0x5
	.incbin "baserom_jp.gba", 0x283BA4, 0x8D
