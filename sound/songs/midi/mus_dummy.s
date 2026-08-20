.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"

sSongHeader_0: @ 0x088683E0
	.byte 0x00, 0x00, 0x00, 0xA8  @ trackCount, blockCount, priority, reverb
	.4byte voicegroup_dummy  @ tone
