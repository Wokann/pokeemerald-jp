	nop
	setrespawn 0x27
	fadescreen 0x27
	end
	checkplayergender
	resetobjectsubpriority 0x855, 0x205
	nop
	nop
	copylocal 0x0, 0x0
	nop
	nop
	nop
	.incbin "baserom_jp.gba", 0x27B075, 0x48
