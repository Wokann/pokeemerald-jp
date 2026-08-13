	nop
	setmaplayoutindex 0x27
	setstepcallback 0x27
	setmysteryeventstatus 0x9C
	.byte 0xFA
	waitstate
	gotostd 0xE
	dofieldeffect 0x27FA
	gotostd 0x5
	.incbin "baserom_jp.gba", 0x27FA93, 0x5E
