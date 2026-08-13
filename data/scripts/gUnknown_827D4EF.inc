	nop
	compare_local_to_value 0x28, 0x0
	setweather 0xA27
	return
	returnram
	returnram
	gotostd 0x3
	fadedefaultbgm
	playslotmachine 0x810
	.incbin "baserom_jp.gba", 0x27D4FF, 0x1E
