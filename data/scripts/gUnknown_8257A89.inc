	lockall
	loadword 0x0, 0x8257E82
	callstd 0x4
	special EggHatch
	releaseall
	end
	.incbin "baserom_jp.gba", 0x257A98, 0x3EA
	.globl gJPText_00257E82
gJPText_00257E82: @ 0x08257E82
	.string "おや⋯？$"

	.incbin "baserom_jp.gba", 0x257e87, 0x5b
