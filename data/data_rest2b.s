.include "sound/MPlayDef.s"
.section .rodata.data_rest2b_before_battle_anim_initial_sprite_gfx
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

	.section .rodata.data_rest2b_after_battle_anim_initial_sprite_gfx
	.incbin "baserom_jp.gba", 0xc028b4, 0x6b44

	.globl gUnknown_8C093F8
gUnknown_8C093F8: @ 0x8C093F8
	.incbin "baserom_jp.gba", 0xc093f8, 0x87ac


	.section .rodata.data_rest2b_after_healthbox
	.incbin "baserom_jp.gba", 0xc12aa4, 0x2588
