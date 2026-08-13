	nop 
	mossdeepgym2 
	waitstate 
	nop 
	fadescreen 0x27
	gotostd_if 0x1, 0x28
	setworldmapflag 0xC0C
	gotostd 0x19
	checkplayergender 
	nop 
	showcoinsbox 0x2, 0xBC
	.byte 0xF0
	addobject_at 0x208, 0x514
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	bufferitemname 0x4, 0x1905
	waitmoncry 
	nop 
	setdynamicwarp 0x23C, 0x2F, 0x857, 0x401
	nop 
	nop 
	nop 
	nop 
	setworldmapflag 0x200
	nop 
	end 
	.incbin "baserom_jp.gba", 0x279e78, 0x1c
