	nop
	faceplayer
	waitstate
	return
	playslotmachine 0x1051
	gotostd 0x2
	end
	nop
	nop
	.incbin "baserom_jp.gba", 0x27CD90, 0x12B
