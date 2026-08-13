	nop 
	applymovement 0x27, 0x1103282D
	gotostd 0x10
	gotostd 0x5
	nop 
	call 0x4B550302
	killscript 
	.incbin "baserom_jp.gba", 0x27d8cf, 0x70
