	nop 
	takeitem 0xA27, 0x2800
	nop 
	returnram 
	gotostd 0x8
	return 
	cmdD9 
	choosecontestmon 
	copybyte 0x20208, 0x3000200
	.byte 0xE9
	showobject_at 0x80D, 0x505
	.byte 0xFB
	.byte 0xFF
	.byte 0xFB
	.byte 0xFF
	gotostd_if 0x0, 0x0
	nop 
	setworldmapflag 0xE00
	setobjectxy 0x27E4, 0x408, 0x314
	fadedefaultbgm 
	.byte 0x56
	killscript 
	gotostd 0x5
	end 
	setworldmapflag 0x200
	nop 
	goto 0x50D000B
	return 
	takecoins 0x158F
	gotostd 0x5
	nop 
	goto 0xD5DC0208
	faceplayer 
	gotostd 0x2
	return 
	subvar 0xF800, 0xFF
	nop 
	end 
	fadescreenswapbuffers 0xD5
	faceplayer 
	gotostd 0x2
	return 
	subvar 0x0, 0x200
	nop 
	end 
	fadescreenswapbuffers 0xD5
	faceplayer 
	gotostd 0x2
	return 
	subvar 0x800, 0x100
	nop 
	call 0xD5DC020F
	faceplayer 
	gotostd 0x2
	return 
	subvar 0xF800, 0xFF
	nop 
	end 
	fadescreenswapbuffers 0xD5
	faceplayer 
	gotostd 0x2
	return 
	subvar 0x0, 0x200
	nop 
	end 
	fadescreenswapbuffers 0xD5
	faceplayer 
	gotostd 0x2
	return 
	subvar 0x800, 0x100
	nop 
	.byte 0x0F
