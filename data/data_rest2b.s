.include "sound/MPlayDef.s"
.section .rodata.data_rest2b_before_battle_anim_a_base_graphics
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"
	.globl gBlankGfxCompressed
gBlankGfxCompressed: @ 0x8C02384
	.incbin "baserom_jp.gba", 0xc02384, 0xfc

	.section .rodata.data_rest2b_between_battle_anim_a_base_and_claw
	.incbin "baserom_jp.gba", 0xc06e2c, 0xaf0

	.section .rodata.data_rest2b_between_battle_anim_a_claw_and_burst
	.incbin "baserom_jp.gba", 0xc08238, 0x94

	.section .rodata.data_rest2b_after_battle_anim_a_burst_graphics
	.incbin "baserom_jp.gba", 0xc08f14, 0x4e4

	.section .rodata.data_rest2b_before_sparkle_graphics
	.incbin "baserom_jp.gba", 0xc09a30, 0x2c8

	.section .rodata.data_rest2b_after_sparkle_graphics
	.incbin "baserom_jp.gba", 0xc09fe0, 0x7bc4


	.section .rodata.data_rest2b_after_healthbox
	.incbin "baserom_jp.gba", 0xc12aa4, 0x2588
