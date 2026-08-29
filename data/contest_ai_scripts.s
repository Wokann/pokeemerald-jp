	.section script_data, "aw", %progbits
	.include "asm/macros.inc"

@ This JP-located owner mirrors pokeemerald data/contest_ai_scripts.s.
@ The table remains a byte-exact JP raw span pending script decoding.
	.align 2
	.globl gContestAI_ScriptsTable
gContestAI_ScriptsTable: @ 0x828C8D8
	.incbin "baserom_jp.gba", 0x28c8d8, 0x9dc
