.include "sound/MPlayDef.s"
	.section .rodata.mid59_pre_page_swap_anim
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

.globl gUnknown_85658A0
gUnknown_85658A0: @ 0x85658A0
	.incbin "baserom_jp.gba", 0x5658a0, 0x21

	.globl gUnknown_85658C1
gUnknown_85658C1: @ 0x85658C1
	.incbin "baserom_jp.gba", 0x5658c1, 0x13b

	.globl gUnknown_85659FC
gUnknown_85659FC: @ 0x85659FC
	.incbin "baserom_jp.gba", 0x5659fc, 0x10

	.globl gUnknown_8565A0C
gUnknown_8565A0C: @ 0x8565A0C
	.incbin "baserom_jp.gba", 0x565a0c, 0x30

	.globl gUnknown_8565A3C
gUnknown_8565A3C: @ 0x8565A3C
	.incbin "baserom_jp.gba", 0x565a3c, 0x6

	.globl gUnknown_8565A42
gUnknown_8565A42: @ 0x8565A42
	.incbin "baserom_jp.gba", 0x565a42, 0x6

	.globl gUnknown_8565A48
gUnknown_8565A48: @ 0x8565A48
	.incbin "baserom_jp.gba", 0x565a48, 0x8

	.section .rodata.mid59_between_page_swap_anim_and_sprite

	.globl gUnknown_8565A60
gUnknown_8565A60: @ 0x8565A60
	.incbin "baserom_jp.gba", 0x565a60, 0x8

	.globl gUnknown_8565A68
gUnknown_8565A68: @ 0x8565A68
	.incbin "baserom_jp.gba", 0x565a68, 0x8

	.section .rodata.mid59_between_page_swap_anim_and_button_key_roles

	.section .rodata.mid59_between_page_swap_sprite_and_icon

	.section .rodata.mid59_between_input_and_draw_text

	.globl gUnknown_8565AC0
gUnknown_8565AC0: @ 0x8565AC0
	.incbin "baserom_jp.gba", 0x565ac0, 0xa

	.globl gUnknown_8565ACA
gUnknown_8565ACA: @ 0x8565ACA
	.incbin "baserom_jp.gba", 0x565aca, 0xa

	.globl gUnknown_8565AD4
gUnknown_8565AD4: @ 0x8565AD4
	.incbin "baserom_jp.gba", 0x565ad4, 0x8

	.globl gUnknown_8565ADC
gUnknown_8565ADC: @ 0x8565ADC
	.incbin "baserom_jp.gba", 0x565adc, 0x8

	.section .rodata.mid59_post_draw_gender

	.globl gUnknown_8565B00
gUnknown_8565B00: @ 0x8565B00
	.incbin "baserom_jp.gba", 0x565b00, 0x6

	.globl gUnknown_8565B06
gUnknown_8565B06: @ 0x8565B06
	.incbin "baserom_jp.gba", 0x565B06, 0xBB
	.globl gUnknown_8565BC1
gUnknown_8565BC1: @ 0x8565BC1
	.incbin "baserom_jp.gba", 0x565bc1, 0xba

	.globl gUnknown_8565C7B
gUnknown_8565C7B: @ 0x8565C7B
	.incbin "baserom_jp.gba", 0x565c7b, 0x5

	.section .rodata.mid59_post_sprite_resources

	.incbin "baserom_jp.gba", 0x565f90, 0x14

	.globl sSpriteTemplate_MoneyLabel
sSpriteTemplate_MoneyLabel: @ 0x8565FA4
	.hword 0x2722, 0x2722
	.4byte 0x08565F90, 0x08565FA0
	.4byte 0, gDummySpriteAffineAnimTable, 0x08007141

	.globl sSpriteSheet_MoneyLabel
sSpriteSheet_MoneyLabel: @ 0x8565FBC
	.4byte 0x08D9B428
	.hword 0x0100, 0x2722

	.globl sSpritePalette_MoneyLabel
sSpritePalette_MoneyLabel: @ 0x8565FC4
	.4byte 0x08D9B2C0
	.hword 0x2722, 0

	.globl gContestMoves
gContestMoves: @ 0x8565FCC
	.incbin "baserom_jp.gba", 0x565fcc, 0xb18

	.globl gContestEffects
gContestEffects: @ 0x8566AE4
	.incbin "baserom_jp.gba", 0x566ae4, 0xc0

	.globl gComboStarterLookupTable
gComboStarterLookupTable: @ 0x8566BA4
	.byte 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01
	.byte 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00

	.globl gUnknown_8566BE4
gUnknown_8566BE4: @ 0x8566BE4
	.incbin "baserom_jp.gba", 0x566be4, 0xc0
