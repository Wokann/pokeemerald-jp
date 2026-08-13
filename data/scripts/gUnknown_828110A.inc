	nop 
	gettime 
	waitstate 
	nop 
	compare_var_to_value 0x1927, 0x8D
	showcoinsbox 0x2, 0xE0
	.byte 0xE9
	addobject_at 0x8208, 0x614
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	nop 
	copylocal 0x0, 0x0
	nop 
	goto 0x3F00B119
	end 
	.incbin "baserom_jp.gba", 0x28112d, 0x43
