	nop
	fadescreen 0x27
	nop
	setrespawn 0xA27
	end
	return
	resetweather
	bufferpartymonnick 0x11, 0x208
	nop
	compare_var_to_value 0x107, 0x7200
	.incbin "baserom_jp.gba", 0x27BB05, 0x74
