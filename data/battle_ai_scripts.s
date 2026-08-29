	.section script_data, "aw", %progbits
	.include "asm/macros.inc"

@ This JP-located owner mirrors pokeemerald data/battle_ai_scripts.s.
@ The table remains a byte-exact JP raw span pending script decoding.
	.align 2
	.globl gBattleAI_ScriptsTable
gBattleAI_ScriptsTable: @ 0x828A480
	.incbin "baserom_jp.gba", 0x28a480, 0x2458
