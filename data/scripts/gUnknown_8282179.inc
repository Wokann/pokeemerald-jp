	writebytetoaddr 0x82, 0xFF082821
	compare_var_to_value 0x828, 0xD700
	waitstate 
	nop 
	cmdD8 
	waitstate 
	gotostd_if 0x2, 0x3
	resetobjectsubpriority 0x112F, 0x805
	nop 
	goto 0xB4021404
	setflag 0x857
	end 
	.incbin "baserom_jp.gba", 0x28219a, 0x9f
