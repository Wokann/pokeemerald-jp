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
	.section .rodata.battle_interface_before_healthbox

	.globl gUnknown_82FC0FE
gUnknown_82FC0FE: @ 0x82FC0FE
	.incbin "baserom_jp.gba", 0x2fc0fe, 0x8de

	.globl gUnknown_82FC9DC
gUnknown_82FC9DC: @ 0x82FC9DC
	.incbin "baserom_jp.gba", 0x2fc9dc, 0x8

	.globl gUnknown_82FC9E4
gUnknown_82FC9E4: @ 0x82FC9E4
	.incbin "baserom_jp.gba", 0x2fc9e4, 0x8

	.globl gUnknown_82FC9EC
gUnknown_82FC9EC: @ 0x82FC9EC
	.incbin "baserom_jp.gba", 0x2fc9ec, 0x8

	.globl gUnknown_82FC9F4
gUnknown_82FC9F4: @ 0x82FC9F4
	.incbin "baserom_jp.gba", 0x2fc9f4, 0x50

	.globl gUnknown_82FCA44
gUnknown_82FCA44: @ 0x82FCA44
	.incbin "baserom_jp.gba", 0x2fca44, 0x18

	.globl gUnknown_82FCA5C
gUnknown_82FCA5C: @ 0x82FCA5C
	.incbin "baserom_jp.gba", 0x2fca5c, 0x8

	.globl gUnknown_82FCA64
gUnknown_82FCA64: @ 0x82FCA64
	.incbin "baserom_jp.gba", 0x2fca64, 0x10

	.globl gUnknown_82FCA74
gUnknown_82FCA74: @ 0x82FCA74
	.incbin "baserom_jp.gba", 0x2fca74, 0x8

	.globl gUnknown_82FCA7C
gUnknown_82FCA7C: @ 0x82FCA7C
	.incbin "baserom_jp.gba", 0x2fca7c, 0x4c

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

	.section .rodata.battle_interface_after_healthbar
	.incbin "baserom_jp.gba", 0x2fcc18, 0x6c

	.globl gUnknown_82FCC84
gUnknown_82FCC84: @ 0x82FCC84
	.incbin "baserom_jp.gba", 0x2fcc84, 0x38

	.globl gUnknown_82FCCBC
gUnknown_82FCCBC: @ 0x82FCCBC
	.incbin "baserom_jp.gba", 0x2fccbc, 0x8

	.globl gUnknown_82FCCC4
gUnknown_82FCCC4: @ 0x82FCCC4
	.incbin "baserom_jp.gba", 0x2fccc4, 0x68

	.globl gUnknown_82FCD2C
gUnknown_82FCD2C: @ 0x82FCD2C
	.incbin "baserom_jp.gba", 0x2fcd2c, 0x8

	.globl gUnknown_82FCD34
gUnknown_82FCD34: @ 0x82FCD34
	.incbin "baserom_jp.gba", 0x2fcd34, 0x8

	.globl gUnknown_82FCD3C
gUnknown_82FCD3C: @ 0x82FCD3C
	.incbin "baserom_jp.gba", 0x2fcd3c, 0x8

	.globl gUnknown_82FCD44
gUnknown_82FCD44: @ 0x82FCD44
	.incbin "baserom_jp.gba", 0x2fcd44, 0x18

	.globl gUnknown_82FCD5C
gUnknown_82FCD5C: @ 0x82FCD5C
	.incbin "baserom_jp.gba", 0x2fcd5c, 0x30

	.globl gUnknown_82FCD8C
gUnknown_82FCD8C: @ 0x82FCD8C
	.incbin "baserom_jp.gba", 0x2fcd8c, 0x30

	.globl gUnknown_82FCDBC
gUnknown_82FCDBC: @ 0x82FCDBC
	.byte 0xFC, 0x01, 0x01, 0xFC, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl gUnknown_82FCDDA
gUnknown_82FCDDA: @ 0x82FCDDA
	.byte 0xFC, 0x01, 0x01, 0xFC, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl gUnknown_82FCDEE
gUnknown_82FCDEE: @ 0x82FCDEE
	.byte 0xFC, 0x01, 0x01, 0xFC, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl gUnknown_82FCE02
gUnknown_82FCE02: @ 0x82FCE02
	.hword 0x6198, 0x0EF7, 0x4694, 0x72D1, 0x29DC

	.globl gUnknown_82FCE0C
gUnknown_82FCE0C: @ 0x82FCE0C
	.incbin "baserom_jp.gba", 0x2fce0c, 0x60

	.globl gUnknown_82FCE6C
gUnknown_82FCE6C: @ 0x82FCE6C
	.incbin "baserom_jp.gba", 0x2fce6c, 0x128

	.globl gUnknown_82FCF94
gUnknown_82FCF94: @ 0x82FCF94
	.incbin "baserom_jp.gba", 0x2fcf94, 0x138
