	nop
	fadescreen 0x27
	nop
	setrespawn 0x327
	playslotmachine 0x1054
	gotostd 0x2
	nop
	return
	.byte 0xF5
	removeobject_at 0x810, 0x200
	end
	.byte 0x94
	setorcopyvar 0x857, 0x383
	setworldmapflag 0xA00
	nop
	nop
	nop
	return
	callstd 0x4D
	killscript
	gotostd 0x2
	.incbin "baserom_jp.gba", 0x27AF34, 0x58
