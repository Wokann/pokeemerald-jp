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

	.section .rodata.data_b_after_link_error_text_data
	.incbin "baserom_jp.gba", 0x2bff7c, 0x144

	.section .rodata.data_b_after_wireless_ascii_tables

	.section .rodata.data_b_after_wireless_status_indicator_anims

	.globl sWirelessStatusIndicatorSpriteSheet
sWirelessStatusIndicatorSpriteSheet: @ 0x82C0330
	.4byte 0x082BFF9C
	.hword 0x0380, 0xD431

	.globl sWirelessStatusIndicatorSpritePalette
sWirelessStatusIndicatorSpritePalette: @ 0x82C0338
	.incbin "graphics/battle_anims/sWirelessStatusIndicatorSpritePalette.bin"

	.globl sWirelessStatusIndicatorSpriteTemplate
sWirelessStatusIndicatorSpriteTemplate: @ 0x82C0340
	.hword 0xD431, 0xD432
	.4byte sWirelessStatusIndicatorOamData, sWirelessStatusIndicatorAnims
	.4byte 0, gDummySpriteAffineAnimTable, 0x08007141

	.section .rodata.data_b_after_link_rfu_2_core_tables


	.section .rodata.data_b_tail
gUnknown_82E383A: @ 0x82E383A
	.incbin "baserom_jp.gba", 0x2e383a, 0x2
