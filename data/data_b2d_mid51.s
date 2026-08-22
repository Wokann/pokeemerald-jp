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
	.section .rodata.battle_interface_before_egg_hatch

	.globl gUnknown_82FC0FE
gUnknown_82FC0FE: @ 0x82FC0FE
	.incbin "baserom_jp.gba", 0x2fc0fe, 0x8a6

	.section .rodata.battle_interface_before_healthbox

	.globl gUnknown_82FCAC8
gUnknown_82FCAC8: @ 0x82FCAC8
	.incbin "baserom_jp.gba", 0x2fcac8, 0x8

	.globl gUnknown_82FCAD0
gUnknown_82FCAD0: @ 0x82FCAD0
	.incbin "baserom_jp.gba", 0x2fcad0, 0x8

	.globl gUnknown_82FCAD8
gUnknown_82FCAD8: @ 0x82FCAD8
	.incbin "baserom_jp.gba", 0x2fcad8, 0x8

	.globl gUnknown_82FCAE0
gUnknown_82FCAE0: @ 0x82FCAE0
	.incbin "baserom_jp.gba", 0x2fcae0, 0x8

	.globl gUnknown_82FCAE8
gUnknown_82FCAE8: @ 0x82FCAE8
	.incbin "baserom_jp.gba", 0x2fcae8, 0x8

	.globl gUnknown_82FCAF0
gUnknown_82FCAF0: @ 0x82FCAF0
	.incbin "baserom_jp.gba", 0x2fcaf0, 0x8

	.globl gUnknown_82FCAF8
gUnknown_82FCAF8: @ 0x82FCAF8
	.incbin "baserom_jp.gba", 0x2fcaf8, 0x8

	.globl gUnknown_82FCB00
gUnknown_82FCB00: @ 0x82FCB00
	.incbin "baserom_jp.gba", 0x2fcb00, 0x20

	.globl gUnknown_82FCB20
gUnknown_82FCB20: @ 0x82FCB20
	.incbin "baserom_jp.gba", 0x2fcb20, 0x10

	.section .rodata.pokeball_static_suffix
	.incbin "baserom_jp.gba", 0x2fd0b4, 0x18
