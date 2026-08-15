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

	.globl gUnknown_8592ECC
gUnknown_8592ECC: @ 0x8592ECC
	.incbin "baserom_jp.gba", 0x592ecc, 0x4

	.globl gUnknown_8592ED0
gUnknown_8592ED0: @ 0x8592ED0
	.incbin "baserom_jp.gba", 0x592ed0, 0x8

	.globl gUnknown_8592ED8
gUnknown_8592ED8: @ 0x8592ED8
	.incbin "baserom_jp.gba", 0x592ed8, 0x8

	.globl sTrainerHillWindowTileset
sTrainerHillWindowTileset: @ 0x8592EE0
	.incbin "baserom_jp.gba", 0x592ee0, 0xc0

	.globl sTrainerHillWindowPalette
sTrainerHillWindowPalette: @ 0x8592FA0
	.incbin "baserom_jp.gba", 0x592fa0, 0x20

	.globl sTrainerHillWindowTilemap
sTrainerHillWindowTilemap: @ 0x8592FC0
	.incbin "baserom_jp.gba", 0x592fc0, 0x800

	.globl sTrainerHillRecordsBgTemplates
sTrainerHillRecordsBgTemplates: @ 0x85937C0
	.incbin "baserom_jp.gba", 0x5937c0, 0x8

	.globl sTrainerHillRecordsWindowTemplates
sTrainerHillRecordsWindowTemplates: @ 0x85937C8
	.incbin "baserom_jp.gba", 0x5937c8, 0x10

	.globl sLinkBattleRecordsWindow
sLinkBattleRecordsWindow: @ 0x85937D8
	.incbin "baserom_jp.gba", 0x5937d8, 0x8
