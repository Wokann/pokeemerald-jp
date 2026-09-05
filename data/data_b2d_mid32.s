.include "sound/MPlayDef.s"
	.section .rodata.data_b2d_mid32_evolution_scene_interleave, "a", %progbits
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.include "data/text/trade.inc"
	.incbin "baserom_jp.gba", 0x59543d, 0x38

	.section .rodata.data_b2d_mid32_post_evolution_scene_palette_tables, "a", %progbits
	@ Unassigned alignment bytes between the evolution palette index table
	@ and the next physical data owner.
	.incbin "baserom_jp.gba", 0x5957a5, 0x3

	.section .rodata.data_b2d_mid32_regis_suffix, "a", %progbits

	.section .rodata.data_b2d_mid32_legendary_suffix, "a", %progbits

	.section .rodata.data_b2d_mid32_frontier_suffix, "a", %progbits
