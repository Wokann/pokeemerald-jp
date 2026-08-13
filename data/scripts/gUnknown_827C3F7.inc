	nop 
	.byte 0xE6
	waitstate 
	nop 
	.byte 0xE1
	waitstate 
	nop 
	message 0xECF80227
	addobject_at 0xB08, 0x200
	nop 
	dotimebasedevents 
	nop 
	copyvar 0xBA, 0x4C0
	goto_if 0x2, 0x856EE30
	returnram 
	.incbin "baserom_jp.gba", 0x27c417, 0x34
