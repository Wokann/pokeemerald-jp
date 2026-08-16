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

.globl gUnknown_85CA6A4
gUnknown_85CA6A4: @ 0x85CA6A4
	.string "{B_COPY_VAR_3}{B_COPY_VAR_1}/{B_COPY_VAR_2}$グッズを　おく$グッズを　もどす$グッズを　すてる$"
	.globl gUnknown_85CA6C6
gUnknown_85CA6C6: @ 0x85CA6C6
	.string "{COLOR 161}{SHADOW 161}$えらんだ　グッズを　へやに　おきます！$えらんだ　グッズを　パソコンに　もどします！$いらなくなった　グッズを　すてます！$"
	.globl gUnknown_85CA70B
gUnknown_85CA70B: @ 0x85CA70B
	.string "グッズは　ありません！{PAUSE_UNTIL_PRESS}$つくえ$いす$はちうえ$おきもの$マット$ポスター$ぬいぐるみ$クッション$"
	.globl gUnknown_85CA73F
