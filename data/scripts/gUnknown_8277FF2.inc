	nop 
	dotimebasedevents 
	waitstate 
	gotostd_if 0x3, 0x2A
	setworldmapflag 0x6802
	writebytetoaddr 0x57, 0x40308
	nop 
	nop 
	nop 
	fadeinbgm 0x0
	nop 
	nop 
	copyvar 0x90, 0x4C0
	end 
	end 
	closemessage 
	writebytetoaddr 0x57, 0x40308
	nop 
	nop 
	nop 
	fadeinbgm 0x0
	call 0x901900
	showcoinsbox 0x4, 0x2
	end 
	closemessage 
	writebytetoaddr 0x57, 0x40308
	nop 
	nop 
	nop 
	fadeinbgm 0x0
	gotostd 0x0
	copyvar 0x90, 0x4C0
	end 
	end 
	closemessage 
	writebytetoaddr 0x57, 0x40308
	nop 
	nop 
	nop 
	fadeinbgm 0x0
	returnram 
	nop 
	copyvar 0x90, 0x4C0
	end 
	end 
	closemessage 
	writebytetoaddr 0x57, 0x40308
	nop 
	nop 
	nop 
	fadeinbgm 0x0
	loadbyte 0x0, 0x19
	givemoney 0x204C000, 0x2
	closemessage 
	writebytetoaddr 0x57, 0x40308
	nop 
	nop 
	nop 
	fadeinbgm 0x0
	copylocal 0x0, 0x19
	givemoney 0x204C000, 0x2
	closemessage 
	writebytetoaddr 0x57, 0x40308
	nop 
	nop 
	nop 
	fadeinbgm 0x0
	subvar 0x1900, 0x90
	showcoinsbox 0x5, 0x2
	checkplayergender 
	.byte 0xA9
	addobject 0x208
	goto 0x180000
	nop 
	nop 
	nop 
	nop 
	goto_if 0x0, 0x31030404
	checkpcitem 0x80D, 0x502
	setworldmapflag 0x500
	nop 
	nop 
	nop 
	gotostd 0x0
	setworldmapflag 0x300
	settrainerflag 0xA74
	gotostd 0x3
	goto 0x1F0001
	returnram 
	nop 
	setworldmapflag 0x100
	nop 
	copyvar 0x91, 0xE3F
	setrespawn 0x2812
	gotostd 0x4
	call_if 0x2, 0x855A988
	end 
	return 
	nop 
	nop 
	nop 
	nop 
	callstd 0x0
	goto 0x208030B
	closemessage 
	writebytetoaddr 0x57, 0x30308
	nop 
	nop 
	nop 
	waitfanfare 
	nop 
	.byte 0x04
	.byte 0x04
	.byte 0x0F
