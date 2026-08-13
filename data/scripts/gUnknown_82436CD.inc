	takeitem 0x190A, 0x9B00
	gotopostbattlescript 
	faceplayer 
	bufferleadmonspeciesname 0x16
	nop 
	setmysteryeventstatus 0x12
	setdivewarp 0x800, 0xC, 0xFE13, 0x312
	returnram 
	.incbin "baserom_jp.gba", 0x2436e2, 0x9fb
