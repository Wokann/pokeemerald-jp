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

	.globl gUnknown_85C97B5
gUnknown_85C97B5: @ 0x85C97B5
	.string "{NO}{B_COPY_VAR_1}　{B_COPY_VAR_2}$"

	.globl gUnknown_85C97BD
gUnknown_85C97BD: @ 0x85C97BD
	.string "きのみのタグ$あかいポロック$あおいポロック$ももいろポロック$みどりのポロック$きいろのポロック$むらさきポロック$こんいろポロック$ちゃいろポロック$そらいろポロック$きみどりポロック$はいいろポロック$くろいポロック$しろいポロック$きんいろポロック$"
	.globl gText_HP3
	.set gText_HP3, gUnknown_85C97BD + 0x32A
	.globl gText_SpAtk3
	.set gText_SpAtk3, gUnknown_85C97BD + 0x330
	.globl gText_SpDef3
	.set gText_SpDef3, gUnknown_85C97BD + 0x335
	.globl gUnknown_85C983E
