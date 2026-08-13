	return
	setflashradius 0x1732
	gotostd 0x5
	nop
	compare_var_to_value 0x100, 0x7000
	setobjectmovementtype 0x828, 0x21
	nop
	end
	nop
	.byte 0x95
	setobjectmovementtype 0x828, 0x21
	nop
	return
	nop
	.byte 0xE9
	setobjectmovementtype 0x828, 0x21
	nop
	.incbin "baserom_jp.gba", 0x28651D, 0x172
