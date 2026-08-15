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

	.globl gUnknown_85ABD18
gUnknown_85ABD18: @ 0x85ABD18
	.string "バトルトーナメント$1かい$2かい$じゅんけっしょう$けっしょう$　　　"

	.globl gUnknown_85ABD3C
gUnknown_85ABD3C: @ 0x85ABD3C
	.string "めCコくよCコくれCコくぉCコくきたいの　おおがた　しんじん！\p"
	.string "$ひがんの　はつ　ゆうしょう　なるか！？\p"
	.string "$もと　チャンピオン！\p"
	.string "$ぜんかい　チャンピオン！\p"
	.string "$むてきの　チャンピオン！\p$"
	.globl gUnknown_85ABD9A
