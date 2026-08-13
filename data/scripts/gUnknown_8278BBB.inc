	nop 
	fadescreen 0x27
	nop 
	setrespawn 0xA27
	setworldmapflag 0xC0C
	gotostd 0x11
	.byte 0xD4
	showcontestresults 
	waitstate 
	gotostd 0x45
	startcontest 
	waitstate 
	gotostd 0x5
	callstd_if 0x1, 0xD
	gotostd 0x2
	warphole 0x2F57
	gotostd 0x82
	call 0xFFECFFEC
	setworldmapflag 0x200
	nop 
	end 
	.incbin "baserom_jp.gba", 0x278be4, 0xd2
