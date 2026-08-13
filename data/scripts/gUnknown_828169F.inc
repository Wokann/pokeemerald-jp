	nop 
	checkcoins 0x1927
	vmessage 0x580EC000
	cleartrainerflag 0x828
	compare_addr_to_value 0x8158B95, 0x7
	.byte 0xC8
	nop 
	showcoinsbox 0xFF, 0x3F
	nop 
	return 
	.incbin "baserom_jp.gba", 0x2816b8, 0x81
