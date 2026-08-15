.include "sound/MPlayDef.s"
	.section .rodata
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

gUnknown_85C96F8: @ 0x85C96F8
	.incbin "baserom_jp.gba", 0x5c96f8, 0x30

	.globl gUnknown_85C9728
gUnknown_85C9728: @ 0x85C9728
	.incbin "baserom_jp.gba", 0x5c9728, 0x10

	.globl gUnknown_85C9738
gUnknown_85C9738: @ 0x85C9738
	.string "{B_COPY_VAR_1}へ\n"
	.string "もどります$"
	.globl gUnknown_85C9742
gUnknown_85C9742: @ 0x85C9742
	.string "　ど　う　ぐ　　$モンスターボール$　わざマシン　　$　き　の　み　　$たいせつなもの　$"
	.globl gUnknown_85C976F
