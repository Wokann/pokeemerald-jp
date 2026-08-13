	nop 
	fadescreen 0x27
	nop 
	faceplayer 
	waitstate 
	nop 
	checkpcitem 0xA27, 0x2803
	setworldmapflag 0xC0C
	gotostd 0x3
	waitdooranim 
	addvar 0x811, 0x2
	goto 0xD5C0D03
	gotostd 0x2
	goto 0x10000
	compare_addr_to_local 0x100, 0x0
	end 
	.incbin "baserom_jp.gba", 0x27bd14, 0x17
