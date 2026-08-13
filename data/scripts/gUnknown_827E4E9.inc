	nop
	mossdeepgym3 0xA27
	end
	returnram
	gotostd 0x8
	setmysteryeventstatus 0x2
	.byte 0xE5
	waitstate
	gotostd 0x4
	.incbin "baserom_jp.gba", 0x27E4F7, 0x82
