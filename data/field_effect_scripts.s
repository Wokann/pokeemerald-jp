	.section script_data, "aw", %progbits
	.include "asm/macros.inc"

@ This JP-located owner mirrors pokeemerald data/field_effect_scripts.s.
@ Unconverted bytes remain in their verified physical ROM span.
	.align 2
	.globl gFieldEffectScriptPointers
gFieldEffectScriptPointers: @ 0x8289F5C
	.incbin "baserom_jp.gba", 0x289f5c, 0x334
