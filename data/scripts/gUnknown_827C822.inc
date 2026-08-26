	nop
	return
	delay 0x9700
	waitstate
	return
	.byte 0xE1
	cmdDB 0x2020815
	nop
	nop
	end
	nop
	compare_local_to_value 0xA7, 0x0
	showcoinsbox 0x18, 0x2
	return
	settrainerflag 0xA74
	gotostd 0x5
	goto 0x2BF0000
	returnram
	nop
	jp_raw_01_u16 0x200
	nop
	.incbin "baserom_jp.gba", 0x27C84A, 0x4D
