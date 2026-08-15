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

	.globl gJPText_LinkIsIncorrect
gJPText_LinkIsIncorrect: @ 0x85CCF72
	.string "せつぞくが　まちがっています$"

	.globl gJPText_CardReadingHasBeenHalted
gJPText_CardReadingHasBeenHalted: @ 0x85CCF81
	.string "カードの　よみこみを\n"
	.string "ちゅうし　しました$カードeリーダー{PLUS}と\n"
	.string "つうしん　できません$"
	.globl gJPText_Connecting
