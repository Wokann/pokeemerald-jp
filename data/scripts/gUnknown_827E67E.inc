	nop 
	vgoto 0x10000C27
	compare_local_to_addr 0xD0, 0x20FC000
	startcontest 
	compare_var_to_value 0x857, 0x303
	delay 0x0
	nop 
	vgoto 0x1040527
	killscript 
	.byte 0x08
