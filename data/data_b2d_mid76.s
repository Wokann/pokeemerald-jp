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
	.globl gText_WontHaveEffect
	.set gText_WontHaveEffect, gUnknown_85C97BD + 0x33A
	.globl gText_PkmnLearnedMove3
	.set gText_PkmnLearnedMove3, gUnknown_85C97BD + 0x5AB
	.globl gText_PkmnCantLearnMove
	.set gText_PkmnCantLearnMove, gUnknown_85C97BD + 0x5BF
	.globl gText_PkmnNeedsToReplaceMove
	.set gText_PkmnNeedsToReplaceMove, gUnknown_85C97BD + 0x5E4
	.globl gText_StopLearningMove2
	.set gText_StopLearningMove2, gUnknown_85C97BD + 0x635
	.globl gText_MoveNotLearned
	.set gText_MoveNotLearned, gUnknown_85C97BD + 0x650
	.globl gText_WhichMoveToForget
	.set gText_WhichMoveToForget, gUnknown_85C97BD + 0x666
	.globl gText_12PoofForgotMove
	.set gText_12PoofForgotMove, gUnknown_85C97BD + 0x678
	.globl gText_PkmnAlreadyKnows
	.set gText_PkmnAlreadyKnows, gUnknown_85C97BD + 0x6BC
	.globl gText_PkmnElevatedToLvVar2
	.set gText_PkmnElevatedToLvVar2, gUnknown_85C97BD + 0x791
	.globl gText_RemoveMailBeforeItem
	.set gText_RemoveMailBeforeItem, gUnknown_85C97BD + 0x49F
	.globl gText_PkmnHoldingItemCantHoldMail
	.set gText_PkmnHoldingItemCantHoldMail, gUnknown_85C97BD + 0x54F
	.globl gText_MailTransferredFromMailbox
	.set gText_MailTransferredFromMailbox, gUnknown_85C97BD + 0x575
	.globl gText_CancelBattle
	.set gText_CancelBattle, gUnknown_85C97BD + 0xA5F
	.globl gText_ReturnToWaitingRoom
	.set gText_ReturnToWaitingRoom, gUnknown_85C97BD + 0xA6C
	.globl gText_CancelChallenge
	.set gText_CancelChallenge, gUnknown_85C97BD + 0xA7B
	.globl gUnknown_85C983E
