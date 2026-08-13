	nop
	waitmoncry
	waitstate
	gotostd_if 0x3, 0xC
	returnram
	gotostd 0x3
	waitbuttonpress
	.byte 0xF6
	.incbin "baserom_jp.gba", 0x280D49, 0x5A
