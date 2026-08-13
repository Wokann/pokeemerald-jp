	nop
	animateflash 0x27
	nop
	fadescreen 0x27
	gotostd_if 0x3, 0xC
	returnram
	gotostd 0x19
	dofieldeffect 0x3F00
	end
	mossdeepgym2
	.byte 0xF1
	addobject_at 0x208, 0x100
	nop
	end
	mossdeepgym2
	.byte 0xF1
	addobject_at 0x208, 0x101
	nop
	.incbin "baserom_jp.gba", 0x279D8E, 0x27
