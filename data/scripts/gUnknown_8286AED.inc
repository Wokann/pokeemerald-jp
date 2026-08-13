	nop 
	setholewarp 0x2702, 0x58, 0x572E, 0x208
	goto 0x30001
	nop 
	nop 
	gotostd_if 0x0, 0x0
	nop 
	goto 0xC0008C19
	setmysteryeventstatus 0x3B
	gotopostbattlescript 
	delay 0x508
	setworldmapflag 0x2741
	nop 
	playse 0xE27
	waitmessage 
	gotopostbattlescript 
	delay 0x508
	end 
	.incbin "baserom_jp.gba", 0x286b19, 0x117
