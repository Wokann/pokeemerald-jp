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
	.globl gTrainerBackPicTable
gTrainerBackPicTable: @ 0x82D95DC
	.4byte gTrainerBackPic_Brendan
	.hword 0x2000
	.hword 0
	.4byte gTrainerBackPic_May
	.hword 0x2000
	.hword 1
	.4byte gTrainerBackPic_Red
	.hword 0x2800
	.hword 2
	.4byte gTrainerBackPic_Leaf
	.hword 0x2800
	.hword 3
	.4byte gTrainerBackPic_RubySapphireBrendan
	.hword 0x2000
	.hword 4
	.4byte gTrainerBackPic_RubySapphireMay
	.hword 0x2000
	.hword 5
	.4byte gTrainerBackPic_Wally
	.hword 0x2000
	.hword 6
	.4byte gTrainerBackPic_Steven
	.hword 0x2000
	.hword 7

	.globl gUnknown_82D961C
gUnknown_82D961C: @ 0x82D961C
	.incbin "baserom_jp.gba", 0x2d961c, 0x40
