	.byte 0x20
	setworldmapflag 0x103
	returnram 
	fadescreenswapbuffers 0x94
	delay 0x2008
	setworldmapflag 0x203
	returnram 
	fadescreenswapbuffers 0x94
	delay 0x2008
	setworldmapflag 0x303
	returnram 
	fadescreenswapbuffers 0x94
	delay 0x2008
	setworldmapflag 0x403
	returnram 
	fadescreenswapbuffers 0x94
	delay 0x2008
	setworldmapflag 0x500
	returnram 
	checkpcitem 0x2895, 0x2E08
	playbgm 0x241, 0x2
	nop 
	checkitemtype 0x3E01
	nop 
	gettime 
	waitfanfare 
	.byte 0x41
	end 
	end 
	.byte 0x11
	playslotmachine 0xFA41
	.byte 0x94
	delay 0x1308
	gotostd 0xBA
	faceplayer 
	gotostd 0x12
	.byte 0x40
	nop 
	gettime 
	waitfanfare 
	.byte 0x41
	end 
	end 
	.byte 0x12
	playslotmachine 0xE41
	.byte 0x95
	delay 0x1308
	gotostd 0xBA
	faceplayer 
	gotostd 0x12
	.byte 0x40
	nop 
	gettime 
	waitfanfare 
	.byte 0x41
	end 
	end 
	setptrbyte 0x89, 0x28952241
	gotostd 0x13
	gotostd 0xBA
	faceplayer 
	gotostd 0x12
	.byte 0x40
	nop 
	gettime 
	waitfanfare 
	.byte 0x41
	end 
	end 
	copylocal 0x89, 0x41
	fadenewbgm 0x2895
	gotostd 0x13
	gotostd 0xBA
	faceplayer 
	gotostd 0x12
	.byte 0x40
	nop 
	gettime 
	waitfanfare 
	.byte 0x41
	end 
	end 
	copybyte 0x954A4189, 0x8130828
	vcall 0x4012085A
	nop 
	.byte 0x3C
