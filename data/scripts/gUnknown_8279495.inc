	nop
	checkitemtype 0x27
	fadescreen 0x27
	gotostd_if 0x1, 0xC
	returnram
	gotostd 0x19
	showcontestresults
	nop
	showcoinsbox 0x2, 0xA0
	resetobjectsubpriority 0x855, 0x205
	nop
	nop
	copylocal 0x0, 0x3
	nop
	nop
	nop
	call 0x2010400
	givecoins 0x56E4
	gotostd 0x2
	end
	nop
	nop
	nop
	nop
	.incbin "baserom_jp.gba", 0x2794C2, 0x5B
