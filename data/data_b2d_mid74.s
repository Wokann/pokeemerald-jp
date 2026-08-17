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

	.globl gUnknown_85C93BB
gUnknown_85C93BB: @ 0x85C93BB
	.string "けってい$おりる$"
	.globl gText_Cancel
gText_Cancel: @ 0x85C93C4
	.string "もどる$"

	.globl gText_Exit
gText_Exit: @ 0x85C93C8
	.string "やめる$みせる$"
	.globl gText_EmptyString2
gText_EmptyString2: @ 0x85C93D0
	.string "$キャンセル$もちもの$メール$あずかる$あずける$みる$"
	.globl gUnknown_85C93ED
gUnknown_85C93ED: @ 0x85C93ED
	.string "なし$かいじょ$"
	.globl gUnknown_85C93F5
gUnknown_85C93F5: @ 0x85C93F5
	.string "？？？$"

	.globl gText_FiveMarks
gText_FiveMarks: @ 0x85C93F9
	.string "？？？？？$"

	.globl gText_Slash
gText_Slash: @ 0x85C93FF
	.string "/$"

	.globl gUnknown_85C9401
gUnknown_85C9401: @ 0x85C9401
	.string "ー$"

	.globl gUnknown_85C9403
gUnknown_85C9403: @ 0x85C9403
	.string "ーー$"

	.globl gText_ThreeDashes
gText_ThreeDashes: @ 0x85C9406
	.string "ーーー$"

	.globl gText_MaleSymbol
gText_MaleSymbol: @ 0x85C940A
	.string "♂$"

	.globl gText_FemaleSymbol
gText_FemaleSymbol: @ 0x85C940C
	.string "♀$"

	.globl gText_LevelSymbol
gText_LevelSymbol: @ 0x85C940E
	.string "{LV_2}$"

	.globl gUnknown_85C9411
gUnknown_85C9411: @ 0x85C9411
	.string "{NO}${PLUS}${RIGHT_ARROW_2}$"

	.globl gUnknown_85C941A
gUnknown_85C941A: @ 0x85C941A
	.string "{ID}{NO}$"

	.globl gUnknown_85C941F
gUnknown_85C941F: @ 0x85C941F
	.string "　$"
	.globl gText_SelectorArrow2
gText_SelectorArrow2: @ 0x85C9421
	.string "▶$"

	.globl gUnknown_85C9423
gUnknown_85C9423: @ 0x85C9423
	.string "まえに　もどります！$"
	.globl gUnknown_85C942E
gUnknown_85C942E: @ 0x85C942E
	.string "なにを　しますか？$あげる$"
	.globl gUnknown_85C943C
