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

gUnknown_85C9299: @ 0x85C9299
	.string "▶$　$"
	.globl gUnknown_85C929D
gUnknown_85C929D: @ 0x85C929D
	.string "でんどういり　おめでとう！$みつけた　ポケモン　{B_COPY_VAR_1}！\n"
	.string "つかまえた　ポケモン　{B_COPY_VAR_2}！\p"
	.string "オダマキはかせの\n"
	.string "ポケモンずかん　ひょうか！\p"
	.string "オダマキ“どれどれ\p"
	.string "$ここまでの　レポートを　かきしるしています！\n"
	.string "でんげんを　きらないでください$"
	.globl gUnknown_85C9311
gUnknown_85C9311: @ 0x85C9311
	.incbin "baserom_jp.gba", 0x5c9311, 0x17

	.globl gUnknown_85C9328
gUnknown_85C9328: @ 0x85C9328
	.string "だい{B_COPY_VAR_1}かい　でんどういり！$"
	.globl gUnknown_85C9337
gUnknown_85C9337: @ 0x85C9337
	.string "リーグ　チャンピオン！　おめでとう！$$"
	.globl gUnknown_85C934B
gUnknown_85C934B: @ 0x85C934B
	.string "No,$"

	.globl gUnknown_85C934F
gUnknown_85C934F: @ 0x85C934F
	.string "Lv$IDNo,/$"

	.globl gUnknown_85C9359
