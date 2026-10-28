	.section .rodata

	@ Untyped JP word following the two identified GCC lookup tables.
	.incbin "baserom_jp.gba", 0x90f158, 0x4
