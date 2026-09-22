.include "sound/MPlayDef.s"
	.section .rodata.mid37_before_secret_base_registry
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"

	.globl gUnknown_8566E69
gUnknown_8566E69: @ 0x8566E69
	.incbin "baserom_jp.gba", 0x566e69, 0x148f

	.globl gUnknown_85682F8
gUnknown_85682F8: @ 0x85682F8
	.incbin "baserom_jp.gba", 0x5682f8, 0x438

	.globl gUnknown_8568730
gUnknown_8568730: @ 0x8568730
	.incbin "baserom_jp.gba", 0x568730, 0x348

	.section .rodata.mid37_after_secret_base_registry

	.include "data/tv/text_groups.inc"

	.include "data/contest/contest_results.inc"
