	nop 
	fadescreen 0x27
	nop 
	.byte 0xE7
	waitstate 
	gotostd_if 0x1, 0xC
	returnram 
	gotostd 0x3
	callstd 0x4D
	killscript 
	gotostd 0x2
	goto 0x30000
	nop 
	nop 
	returnram 
	nop 
	call 0xF7640200
	addobject_at 0x208, 0x300
	nop 
	nop 
	nop 
	end 
	nop 
	end 
	moveobjectoffscreen 0x56F7
	gotostd 0x2
	return 
	nop 
	nop 
	setworldmapflag 0x200
	nop 
	compare_local_to_value 0xA2, 0x0
	showcoinsbox 0xC, 0x4
	goto 0x572F3C02
	gotostd 0x3
	call 0x0
	setworldmapflag 0x200
	nop 
	return 
	callstd 0x4D
	killscript 
	gotostd 0x2
	goto 0x30001
	nop 
	nop 
	goto_if 0x0, 0x8D190001
	nop 
	.byte 0x3F
	goto 0x80D010B
