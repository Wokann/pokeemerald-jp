	nop
	faceplayer
	waitstate
	gotostd_if 0x2, 0x28
	nop
	returnram
	returnram
	gotostd 0x19
	setrespawn 0xC000
	end
	checkplayergender
	resetobjectsubpriority 0x855, 0x205
	nop
	nop
	.byte 0xF6
	.byte 0xFF
	nop
	nop
	nop
	nop
	return
	nop
	.incbin "baserom_jp.gba", 0x27E892, 0x89
