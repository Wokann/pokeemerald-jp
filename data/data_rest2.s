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
	.globl gBattleTextboxTiles
gBattleTextboxTiles: @ 0x8C00000 (JP: LoadBattleTextboxAndBackground)
	.incbin "graphics/battle_textbox/gBattleTextboxTiles.bin"


	.globl gBattleTextboxPalette
gBattleTextboxPalette: @ 0x8C004EC
	.incbin "graphics/battle_textbox/gBattleTextboxPalette.bin"


	.globl gBattleTextboxTilemap
gBattleTextboxTilemap: @ 0x8C00530
	.incbin "baserom_jp.gba", 0xc00530, 0x228


	.globl gUnknown_8C02308
