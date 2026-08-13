	lockall
	dofieldeffect 0x2
	waitstate
	goto 0x825661D
	end
	applymovement 0x800F, 0x825662C
	waitmovement 0x0
	removeobject 0x800F
	releaseall
	end
	turnobject 0xFFE, 0x0
	releaseall
	waitmessage
	.byte 0x25
	gotostd 0x9
	.incbin "baserom_jp.gba", 0x256635, 0x91
