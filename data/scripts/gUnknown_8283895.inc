	nop 
	setvar 0x227, 0xF100
	addobject_at 0x8208, 0x214
	nop 
	nop 
	nop 
	call 0xF1000205
	addobject_at 0x8208, 0x214
	nop 
	nop 
	nop 
	call 0xF1000205
	addobject_at 0x8208, 0x214
	nop 
	nop 
	nop 
	call 0x4B550305
	killscript 
	.incbin "baserom_jp.gba", 0x2838c3, 0x68
