	mossdeepgym2 
	setworldmapflag 0x210
	nop 
	gettime 
	specialvar 0x241, sub_080F9424
	checkflag 0x9004
	initclock 0x202, 0x1
	nop 
	nop 
	vmessage 0x26082890
	setworldmapflag 0xBF28
	givemoney 0x2260828, 0xBA
	.byte 0xCC
	givemoney 0xAB5F0828, 0x41
	.byte 0xFF
	givemoney 0x275F0828, 0xBF
	givemoney 0x1E20828, 0x3A
	givedecoration 0x613A
	setworldmapflag 0x151
	setworldmapflag 0x14C
	checkdecor 0x7301
	setworldmapflag 0x310
	nop 
	cleartrainerflag 0x4E01
	setworldmapflag 0x3A00
	waitmovement_at 0x2E01, 0x2C41
	end 
	.incbin "baserom_jp.gba", 0x2890f0, 0x51
