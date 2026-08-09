	nop 
	call_if 0x28, 0x2280F00
	release 
	.byte 0xD6
	faceplayer 
	gotostd 0x82
	return 
	setworldmapflag 0x0
	nop 
	end 
	nop 
	end 
	release 
	.byte 0xD6
	faceplayer 
	gotostd 0x82
	return 
	setworldmapflag 0x100
	nop 
	end 
	nop 
	call 0xE7790320
	copybyte 0x1020308, 0x1C000200
	pokemart 0x20C3F00
	goto 0x55030404
	.byte 0x4B
	.byte 0x0D
	gotostd 0x2
	goto 0x20001
	nop 
	nop 
	goto_if 0x0, 0x9C020002
	.byte 0xD6
	faceplayer 
	gotostd 0x82
	return 
	setworldmapflag 0x800
	nop 
	return 
	nop 
	compare_local_to_value 0xC2, 0x0
	.byte 0x3F
	loadbyte 0x3, 0x8
