.include "sound/MPlayDef.s"
	.section .rodata.mid3_suffix
	.include "asm/macros.inc"
	.incbin "baserom_jp.gba", 0x5f28f8, 0x10bc


	.globl gMatchCallFlavorTexts
gMatchCallFlavorTexts: @ 0x85F39B4
	.incbin "baserom_jp.gba", 0x5f39b4, 0x4e0
