	.include "asm/macros.inc"
	.include "asm/macros/battle_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

@ This JP-located owner mirrors pokeemerald data/battle_scripts_1.s.
@ Unconverted ranges remain visible here in physical ROM order.
	.align 2
	.globl gBattleScriptsForMoveEffects
gBattleScriptsForMoveEffects: @ 0x8286C30
	.incbin "baserom_jp.gba", 0x286c30, 0x388
