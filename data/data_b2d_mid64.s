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
	.incbin "graphics/misc/sTrainerHillWindowTileset.bin"

	.globl sTrainerHillWindowPalette
sTrainerHillWindowPalette: @ 0x8592FA0
	.incbin "graphics/misc/sTrainerHillWindowPalette.bin"

	.globl sTrainerHillWindowTilemap
sTrainerHillWindowTilemap: @ 0x8592FC0
	.incbin "graphics/misc/sTrainerHillWindowTilemap.bin"

	.globl sTrainerHillRecordsBgTemplates
sTrainerHillRecordsBgTemplates: @ 0x85937C0
	.byte 0xF0, 0x01, 0x00, 0x00, 0xE7, 0x31, 0x00, 0x00

	.globl sTrainerHillRecordsWindowTemplates
sTrainerHillRecordsWindowTemplates: @ 0x85937C8
	.byte 0x00, 0x02, 0x01, 0x1B, 0x12, 0x0F, 0x14, 0x00
	.byte 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.globl sLinkBattleRecordsWindow
sLinkBattleRecordsWindow: @ 0x85937D8
	.incbin "graphics/text_window/sLinkBattleRecordsWindow.bin"
