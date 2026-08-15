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

	.globl gUnknown_8566DF5
gUnknown_8566DF5: @ 0x8566DF5
	.incbin "baserom_jp.gba", 0x566df5, 0xb

	.globl gUnknown_8566E00
gUnknown_8566E00: @ 0x8566E00
	.incbin "baserom_jp.gba", 0x566e00, 0x40

	.globl gUnknown_8566E40
gUnknown_8566E40: @ 0x8566E40
	.incbin "baserom_jp.gba", 0x566e40, 0x18

	.globl gUnknown_8566E58
gUnknown_8566E58: @ 0x8566E58
	.incbin "baserom_jp.gba", 0x566e58, 0x5
