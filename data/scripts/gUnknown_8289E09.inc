	gettime 
	.byte 0xD7
	.byte 0x3F
	end 
	end 
	nop 
	hidemonpic 
	setworldmapflag 0x2908
	setworldmapflag 0x3FD6
	end 
	end 
	setworldmapflag 0x9E25
	delay 0x1308
	.byte 0xB4
	.byte 0xBE
	faceplayer 
	gotostd 0x12
	.byte 0x40
	nop 
	playse 0x3FD7
	end 
	end 
	setworldmapflag 0xD72D
	.byte 0x3F
	end 
	end 
	loadbyte 0x3D, 0x2
	end 
	setworldmapflag 0x9E0F
	delay 0x2E08
	.byte 0xD6
	.byte 0x3F
	end 
	end 
	nop 
	gettime 
	.byte 0xD7
	.byte 0x3F
	end 
	end 
	nop 
	.byte 0x3E
