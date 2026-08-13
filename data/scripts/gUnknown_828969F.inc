	gettime
	playbgm 0x241, 0x2
	nop
	checkitemtype 0x601
	killscript
	checkitemtype 0x201
	callstd 0x2E
	waitfanfare
	.incbin "baserom_jp.gba", 0x2896AF, 0x41
