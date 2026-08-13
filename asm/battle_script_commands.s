.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified






	thumb_func_start atk7C_trymirrormove
atk7C_trymirrormove: @ 0x0804FD70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r2, _0804FE10
	ldr r0, _0804FE14
	mov sl, r0
	movs r1, #0
	add r0, sp, #4
_0804FD86:
	strh r1, [r0]
	subs r0, #2
	cmp r0, sp
	bge _0804FD86
	movs r1, #0
	mov r8, r1
	movs r5, #0
	ldrb r1, [r2]
	cmp r5, r1
	bge _0804FDDC
	ldr r0, _0804FE18
	ldrb r6, [r0]
	ldr r2, _0804FE1C
	mov sb, r2
	lsls r4, r6, #3
	mov r2, sp
	ldr r0, _0804FE14
	mov ip, r0
	adds r7, r1, #0
_0804FDAC:
	cmp r5, r6
	beq _0804FDD4
	mov r1, ip
	ldr r0, [r1]
	adds r0, r4, r0
	adds r1, r0, #0
	adds r1, #0xe0
	ldrb r3, [r1]
	adds r0, #0xe1
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r3, r0
	cmp r3, #0
	beq _0804FDD4
	cmp r3, sb
	beq _0804FDD4
	strh r3, [r2]
	adds r2, #2
	movs r0, #1
	add r8, r0
_0804FDD4:
	adds r4, #2
	adds r5, #1
	cmp r5, r7
	blt _0804FDAC
_0804FDDC:
	ldr r1, _0804FE18
	ldrb r0, [r1]
	mov r2, sl
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x98
	ldrb r3, [r1]
	adds r0, #0x99
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r3, r0
	cmp r3, #0
	beq _0804FE2C
	ldr r0, _0804FE1C
	cmp r3, r0
	beq _0804FE2C
	ldr r2, _0804FE20
	ldr r0, [r2]
	ldr r1, _0804FE24
	ands r0, r1
	str r0, [r2]
	ldr r4, _0804FE28
	strh r3, [r4]
	b _0804FE56
	.align 2, 0
_0804FE10: .4byte 0x02023D10
_0804FE14: .4byte 0x02024140
_0804FE18: .4byte 0x02023EAF
_0804FE1C: .4byte 0x0000FFFF
_0804FE20: .4byte 0x02023F24
_0804FE24: .4byte 0xFFFFFBFF
_0804FE28: .4byte 0x02023E8E
_0804FE2C:
	mov r0, r8
	cmp r0, #0
	beq _0804FE9C
	ldr r2, _0804FE80
	ldr r0, [r2]
	ldr r1, _0804FE84
	ands r0, r1
	str r0, [r2]
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, r8
	bl __modsi3
	adds r5, r0, #0
	ldr r4, _0804FE88
	lsls r0, r5, #1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
_0804FE56:
	ldrh r0, [r4]
	movs r1, #0
	bl GetMoveTarget
	ldr r1, _0804FE8C
	strb r0, [r1]
	ldr r5, _0804FE90
	ldr r3, _0804FE94
	ldr r2, _0804FE98
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r5]
	b _0804FEBA
	.align 2, 0
_0804FE80: .4byte 0x02023F24
_0804FE84: .4byte 0xFFFFFBFF
_0804FE88: .4byte 0x02023E8E
_0804FE8C: .4byte 0x02023EB0
_0804FE90: .4byte 0x02023EB8
_0804FE94: .4byte 0x08286C30
_0804FE98: .4byte 0x082ED220
_0804FE9C:
	ldr r2, _0804FECC
	ldr r0, _0804FED0
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r1, _0804FED4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0804FEBA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FECC: .4byte 0x02024020
_0804FED0: .4byte 0x02023EAF
_0804FED4: .4byte 0x02023EB8
	thumb_func_end atk7C_trymirrormove
	.section .text.atk7D_battle_rest,"ax",%progbits

	.syntax unified





































	.section .text.IsMoveUncopyableByMimic,"ax",%progbits

	.syntax unified

	thumb_func_start IsMoveUncopyableByMimic
IsMoveUncopyableByMimic: @ 0x08051EC8
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r3, #0
	ldr r0, _08051F08
	ldrh r1, [r0]
	ldr r4, _08051F0C
	adds r5, r0, #0
	cmp r1, r4
	beq _08051EF0
	cmp r1, r2
	beq _08051EF0
	adds r1, r5, #0
_08051EE2:
	adds r1, #2
	adds r3, #1
	ldrh r0, [r1]
	cmp r0, r4
	beq _08051EF0
	cmp r0, r2
	bne _08051EE2
_08051EF0:
	lsls r0, r3, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldr r0, _08051F0C
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08051F08: .4byte 0x082ECD64
_08051F0C: .4byte 0x0000FFFE
	thumb_func_end IsMoveUncopyableByMimic
	.section .text.atk9E_battle_rest,"ax",%progbits

	.syntax unified














	thumb_func_start IsTwoTurnsMove
IsTwoTurnsMove: @ 0x08052B58
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08052B88
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r0, [r1]
	cmp r0, #0x91
	beq _08052B82
	cmp r0, #0x27
	beq _08052B82
	cmp r0, #0x4b
	beq _08052B82
	cmp r0, #0x97
	beq _08052B82
	cmp r0, #0x9b
	beq _08052B82
	cmp r0, #0x1a
	bne _08052B8C
_08052B82:
	movs r0, #1
	b _08052B8E
	.align 2, 0
_08052B88: .4byte 0x082ED220
_08052B8C:
	movs r0, #0
_08052B8E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsTwoTurnsMove

	thumb_func_start IsInvalidForSleepTalkOrAssist
IsInvalidForSleepTalkOrAssist: @ 0x08052B94
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08052BB2
	cmp r1, #0xd6
	beq _08052BB2
	movs r0, #0x89
	lsls r0, r0, #1
	cmp r1, r0
	beq _08052BB2
	cmp r1, #0x77
	beq _08052BB2
	cmp r1, #0x76
	bne _08052BB6
_08052BB2:
	movs r0, #1
	b _08052BB8
_08052BB6:
	movs r0, #0
_08052BB8:
	pop {r1}
	bx r1
	thumb_func_end IsInvalidForSleepTalkOrAssist

	thumb_func_start AttacksThisTurn
AttacksThisTurn: @ 0x08052BBC
	push {lr}
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	ldr r1, _08052C14
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r1, #0
	cmp r0, #0x97
	bne _08052BE0
	ldr r0, _08052C18
	ldrh r1, [r0]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	bne _08052C20
_08052BE0:
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0x91
	beq _08052C02
	cmp r0, #0x27
	beq _08052C02
	cmp r0, #0x4b
	beq _08052C02
	cmp r0, #0x97
	beq _08052C02
	cmp r0, #0x9b
	beq _08052C02
	cmp r0, #0x1a
	bne _08052C20
_08052C02:
	ldr r0, _08052C1C
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ands r0, r1
	cmp r0, #0
	beq _08052C20
	movs r0, #1
	b _08052C22
	.align 2, 0
_08052C14: .4byte 0x082ED220
_08052C18: .4byte 0x02024070
_08052C1C: .4byte 0x02023F24
_08052C20:
	movs r0, #2
_08052C22:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end AttacksThisTurn
	.section .text.atkAA_battle_rest,"ax",%progbits

	.syntax unified




	.section .text.TrySetDestinyBondToHappen,"ax",%progbits

	.syntax unified

	thumb_func_start TrySetDestinyBondToHappen
TrySetDestinyBondToHappen: @ 0x08052D90
	push {r4, r5, lr}
	ldr r0, _08052DE0
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r4, _08052DE4
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r1, _08052DE8
	ldrb r2, [r4]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x12
	ands r0, r1
	cmp r0, #0
	beq _08052DDA
	cmp r5, r3
	beq _08052DDA
	ldr r2, _08052DEC
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r0, r1
	cmp r0, #0
	bne _08052DDA
	movs r0, #0x40
	orrs r1, r0
	str r1, [r2]
_08052DDA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052DE0: .4byte 0x02023EAF
_08052DE4: .4byte 0x02023EB0
_08052DE8: .4byte 0x02023D28
_08052DEC: .4byte 0x02023F24
	thumb_func_end TrySetDestinyBondToHappen
	.section .text.atkAC_battle_rest,"ax",%progbits

	.syntax unified

































	thumb_func_start atkCA_setforcedtarget
atkCA_setforcedtarget: @ 0x0805474C
	push {r4, r5, lr}
	ldr r4, _0805478C
	ldrb r0, [r4]
	bl GetBattlerSide
	ldr r5, _08054790
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r0, #1
	strb r0, [r1, #8]
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	ldrb r0, [r4]
	strb r0, [r1, #9]
	ldr r1, _08054794
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805478C: .4byte 0x02023EAF
_08054790: .4byte 0x02023F38
_08054794: .4byte 0x02023EB8
	thumb_func_end atkCA_setforcedtarget

	thumb_func_start atkCB_setcharge
atkCB_setcharge: @ 0x08054798
	push {r4, lr}
	ldr r0, _080547EC
	ldr r3, _080547F0
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r0, r2
	str r0, [r1]
	ldr r4, _080547F4
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r2, [r0, #0x12]
	movs r1, #0x10
	rsbs r1, r1, #0
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strb r1, [r0, #0x12]
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r2, [r0, #0x12]
	movs r1, #0xf
	ands r1, r2
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0, #0x12]
	ldr r1, _080547F8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080547EC: .4byte 0x02023F50
_080547F0: .4byte 0x02023EAF
_080547F4: .4byte 0x02023F60
_080547F8: .4byte 0x02023EB8
	thumb_func_end atkCB_setcharge

	thumb_func_start atkCC_callterrainattack
atkCC_callterrainattack: @ 0x080547FC
	push {r4, lr}
	ldr r2, _0805484C
	ldr r0, [r2]
	ldr r1, _08054850
	ands r0, r1
	str r0, [r2]
	ldr r4, _08054854
	ldr r1, _08054858
	ldr r0, _0805485C
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, #0
	bl GetMoveTarget
	ldr r1, _08054860
	strb r0, [r1]
	ldr r3, _08054864
	ldr r2, _08054868
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	bl BattleScriptPush
	ldr r1, _0805486C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805484C: .4byte 0x02023F24
_08054850: .4byte 0xFFFFFBFF
_08054854: .4byte 0x02023E8E
_08054858: .4byte 0x082ECD98
_0805485C: .4byte 0x02022C94
_08054860: .4byte 0x02023EB0
_08054864: .4byte 0x08286C30
_08054868: .4byte 0x082ED220
_0805486C: .4byte 0x02023EB8
	thumb_func_end atkCC_callterrainattack

	thumb_func_start atkCD_cureifburnedparalysedorpoisoned
atkCD_cureifburnedparalysedorpoisoned: @ 0x08054870
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r1, _080548BC
	ldr r3, _080548C0
	ldrb r0, [r3]
	movs r6, #0x58
	muls r0, r6, r0
	adds r5, r1, #0
	adds r5, #0x4c
	adds r2, r0, r5
	ldr r0, [r2]
	movs r1, #0xd8
	ands r0, r1
	cmp r0, #0
	beq _080548CC
	movs r0, #0
	str r0, [r2]
	ldr r1, _080548C4
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	ldr r4, _080548C8
	ldrb r0, [r3]
	strb r0, [r4]
	ldrb r0, [r4]
	muls r0, r6, r0
	adds r0, r0, r5
	str r0, [sp]
	movs r0, #0
	movs r1, #0x28
	movs r2, #0
	movs r3, #4
	bl BtlController_EmitSetMonData
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	b _080548E6
	.align 2, 0
_080548BC: .4byte 0x02023D28
_080548C0: .4byte 0x02023EAF
_080548C4: .4byte 0x02023EB8
_080548C8: .4byte 0x02023D08
_080548CC:
	ldr r3, _080548F0
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_080548E6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080548F0: .4byte 0x02023EB8
	thumb_func_end atkCD_cureifburnedparalysedorpoisoned

	thumb_func_start atkCE_settorment
atkCE_settorment: @ 0x080548F4
	push {lr}
	ldr r1, _0805492C
	ldr r0, _08054930
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r1, #0
	bge _08054938
	ldr r3, _08054934
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08054944
	.align 2, 0
_0805492C: .4byte 0x02023D28
_08054930: .4byte 0x02023EB0
_08054934: .4byte 0x02023EB8
_08054938:
	orrs r1, r2
	str r1, [r0]
	ldr r1, _08054948
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08054944:
	pop {r0}
	bx r0
	.align 2, 0
_08054948: .4byte 0x02023EB8
	thumb_func_end atkCE_settorment

	thumb_func_start atkCF_jumpifnodamage
atkCF_jumpifnodamage: @ 0x0805494C
	push {lr}
	ldr r2, _08054978
	ldr r0, _0805497C
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r0, r2, #4
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _0805496C
	adds r0, r2, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	beq _08054984
_0805496C:
	ldr r1, _08054980
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _0805499E
	.align 2, 0
_08054978: .4byte 0x02023FE0
_0805497C: .4byte 0x02023EAF
_08054980: .4byte 0x02023EB8
_08054984:
	ldr r3, _080549A4
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_0805499E:
	pop {r0}
	bx r0
	.align 2, 0
_080549A4: .4byte 0x02023EB8
	thumb_func_end atkCF_jumpifnodamage

	thumb_func_start atkD0_settaunt
atkD0_settaunt: @ 0x080549A8
	push {r4, lr}
	ldr r4, _080549EC
	ldr r3, _080549F0
	ldrb r0, [r3]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r2, r1, r4
	ldrb r1, [r2, #0x13]
	lsls r0, r1, #0x1c
	cmp r0, #0
	bne _080549F8
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x13]
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r2, [r0, #0x13]
	movs r1, #0xf
	ands r1, r2
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0, #0x13]
	ldr r1, _080549F4
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08054A12
	.align 2, 0
_080549EC: .4byte 0x02023F60
_080549F0: .4byte 0x02023EB0
_080549F4: .4byte 0x02023EB8
_080549F8:
	ldr r3, _08054A18
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08054A12:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054A18: .4byte 0x02023EB8
	thumb_func_end atkD0_settaunt

	thumb_func_start atkD1_trysethelpinghand
atkD1_trysethelpinghand: @ 0x08054A1C
	push {r4, lr}
	ldr r4, _08054A84
	ldrb r0, [r4]
	bl GetBattlerPosition
	movs r1, #2
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	ldr r3, _08054A88
	strb r0, [r3]
	ldr r0, _08054A8C
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08054AA0
	ldr r0, _08054A90
	ldrb r1, [r0]
	ldr r2, _08054A94
	ldrb r3, [r3]
	lsls r0, r3, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08054AA0
	ldr r1, _08054A98
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	cmp r0, #0
	blt _08054AA0
	lsls r0, r3, #4
	adds r2, r0, r1
	ldrb r1, [r2]
	lsls r0, r1, #0x1c
	cmp r0, #0
	blt _08054AA0
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08054A9C
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08054ABA
	.align 2, 0
_08054A84: .4byte 0x02023EAF
_08054A88: .4byte 0x02023EB0
_08054A8C: .4byte 0x02022C90
_08054A90: .4byte 0x02023EB4
_08054A94: .4byte 0x082FACB4
_08054A98: .4byte 0x02023FE0
_08054A9C: .4byte 0x02023EB8
_08054AA0:
	ldr r3, _08054AC0
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08054ABA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054AC0: .4byte 0x02023EB8
	thumb_func_end atkD1_trysethelpinghand

	thumb_func_start atkD2_tryswapitems
atkD2_tryswapitems: @ 0x08054AC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, _08054BC8
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ands r0, r1
	cmp r0, #0
	bne _08054BAA
	ldr r0, _08054BCC
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08054AF8
	ldr r0, [r4]
	ldr r1, _08054BD0
	ands r0, r1
	cmp r0, #0
	beq _08054BAA
_08054AF8:
	ldr r6, _08054BCC
	ldrb r0, [r6]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r7, _08054BD4
	ldrb r0, [r7]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _08054BC8
	ldr r0, [r0]
	ldr r1, _08054BD0
	ands r0, r1
	cmp r0, #0
	bne _08054B56
	ldr r0, _08054BD8
	adds r2, r0, #0
	adds r2, #0x29
	adds r0, r4, r2
	ldrb r1, [r0]
	ldr r4, _08054BDC
	ldr r3, _08054BE0
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08054BAA
	adds r0, r5, r2
	ldrb r1, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08054BAA
_08054B56:
	ldr r0, _08054BE4
	mov r8, r0
	ldr r1, _08054BCC
	ldrb r4, [r1]
	movs r5, #0x58
	adds r0, r4, #0
	muls r0, r5, r0
	add r0, r8
	mov sb, r0
	ldrh r3, [r0, #0x2e]
	adds r1, r3, #0
	cmp r1, #0
	bne _08054B7E
	ldr r0, _08054BD4
	ldrb r0, [r0]
	muls r0, r5, r0
	add r0, r8
	ldrh r0, [r0, #0x2e]
	cmp r0, #0
	beq _08054BAA
_08054B7E:
	cmp r1, #0xaf
	beq _08054BAA
	ldr r7, _08054BD4
	ldrb r0, [r7]
	muls r0, r5, r0
	mov r2, r8
	adds r1, r0, r2
	ldrh r2, [r1, #0x2e]
	cmp r2, #0xaf
	beq _08054BAA
	adds r0, r3, #0
	subs r0, #0x79
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _08054BAA
	adds r0, r2, #0
	subs r0, #0x79
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08054BEC
_08054BAA:
	ldr r3, _08054BE8
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08054D42
	.align 2, 0
_08054BC8: .4byte 0x02022C90
_08054BCC: .4byte 0x02023EAF
_08054BD0: .4byte 0x0A3F0902
_08054BD4: .4byte 0x02023EB0
_08054BD8: .4byte 0x02024074
_08054BDC: .4byte 0x082FACB4
_08054BE0: .4byte 0x02023D12
_08054BE4: .4byte 0x02023D28
_08054BE8: .4byte 0x02023EB8
_08054BEC:
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x3c
	bne _08054C20
	ldr r1, _08054C14
	ldr r0, _08054C18
	str r0, [r1]
	ldr r1, _08054C1C
	ldrb r0, [r7]
	muls r0, r5, r0
	add r0, r8
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	ldrb r1, [r1]
	bl RecordAbilityBattle
	b _08054D42
	.align 2, 0
_08054C14: .4byte 0x02023EB8
_08054C18: .4byte 0x08289BC7
_08054C1C: .4byte 0x02023EAE
_08054C20:
	ldr r3, _08054D0C
	mov sl, r3
	lsls r0, r4, #1
	adds r0, #0xd0
	ldr r1, [r3]
	adds r6, r1, r0
	mov r0, sb
	ldrh r0, [r0, #0x2e]
	mov sb, r0
	strh r2, [r6]
	ldr r1, _08054D10
	ldrb r0, [r1]
	muls r0, r5, r0
	add r0, r8
	movs r1, #0
	strh r1, [r0, #0x2e]
	ldrb r0, [r7]
	muls r0, r5, r0
	add r0, r8
	mov r2, sb
	strh r2, [r0, #0x2e]
	ldr r4, _08054D14
	ldr r3, _08054D10
	ldrb r0, [r3]
	strb r0, [r4]
	str r6, [sp]
	movs r0, #0
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl BtlController_EmitSetMonData
	ldr r1, _08054D10
	ldrb r0, [r1]
	bl MarkBattlerForControllerExec
	ldrb r0, [r7]
	strb r0, [r4]
	ldrb r0, [r7]
	muls r0, r5, r0
	mov r1, r8
	adds r1, #0x2e
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl BtlController_EmitSetMonData
	ldrb r0, [r7]
	bl MarkBattlerForControllerExec
	ldrb r0, [r7]
	mov r2, sl
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc8
	movs r3, #0
	strb r3, [r0]
	ldrb r0, [r7]
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc9
	strb r3, [r0]
	ldr r1, _08054D10
	ldrb r0, [r1]
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc8
	strb r3, [r0]
	ldr r2, _08054D10
	ldrb r0, [r2]
	mov r3, sl
	ldr r1, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc9
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08054D18
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	ldr r1, _08054D1C
	movs r3, #0xfd
	strb r3, [r1]
	movs r2, #0xa
	strb r2, [r1, #1]
	ldrh r0, [r6]
	strb r0, [r1, #2]
	ldrh r0, [r6]
	lsrs r0, r0, #8
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _08054D20
	strb r3, [r1]
	strb r2, [r1, #1]
	mov r2, sb
	strb r2, [r1, #2]
	mov r3, sb
	lsrs r0, r3, #8
	strb r0, [r1, #3]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1, #4]
	cmp r3, #0
	beq _08054D28
	ldrh r0, [r6]
	cmp r0, #0
	beq _08054D3C
	ldr r1, _08054D24
	movs r0, #2
	b _08054D40
	.align 2, 0
_08054D0C: .4byte 0x02024140
_08054D10: .4byte 0x02023EAF
_08054D14: .4byte 0x02023D08
_08054D18: .4byte 0x02023EB8
_08054D1C: .4byte 0x02022C0C
_08054D20: .4byte 0x02022C1C
_08054D24: .4byte 0x02023FD6
_08054D28:
	ldrh r0, [r6]
	cmp r0, #0
	beq _08054D3C
	ldr r0, _08054D38
	movs r1, #0
	strb r1, [r0, #5]
	b _08054D42
	.align 2, 0
_08054D38: .4byte 0x02023FD6
_08054D3C:
	ldr r1, _08054D54
	movs r0, #1
_08054D40:
	strb r0, [r1, #5]
_08054D42:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08054D54: .4byte 0x02023FD6
	thumb_func_end atkD2_tryswapitems

	thumb_func_start atkD3_trycopyability
atkD3_trycopyability: @ 0x08054D58
	push {r4, lr}
	ldr r3, _08054D98
	ldr r4, _08054D9C
	ldrb r0, [r4]
	movs r2, #0x58
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r1, [r0]
	adds r0, r1, #0
	cmp r0, #0
	beq _08054DAC
	cmp r0, #0x19
	beq _08054DAC
	ldr r0, _08054DA0
	ldrb r0, [r0]
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x20
	strb r1, [r0]
	ldr r1, _08054DA4
	ldrb r0, [r4]
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _08054DA8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08054DC6
	.align 2, 0
_08054D98: .4byte 0x02023D28
_08054D9C: .4byte 0x02023EB0
_08054DA0: .4byte 0x02023EAF
_08054DA4: .4byte 0x02023EAE
_08054DA8: .4byte 0x02023EB8
_08054DAC:
	ldr r3, _08054DCC
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08054DC6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054DCC: .4byte 0x02023EB8
	thumb_func_end atkD3_trycopyability

	thumb_func_start atkD4_trywish
atkD4_trywish: @ 0x08054DD0
	push {r4, r5, r6, r7, lr}
	ldr r7, _08054DE4
	ldr r2, [r7]
	ldrb r3, [r2, #1]
	cmp r3, #0
	beq _08054DE8
	cmp r3, #1
	beq _08054E20
	b _08054E9C
	.align 2, 0
_08054DE4: .4byte 0x02023EB8
_08054DE8:
	ldr r1, _08054E14
	ldr r4, _08054E18
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r5, [r4]
	adds r3, r0, r5
	ldrb r0, [r3]
	cmp r0, #0
	bne _08054E6C
	movs r0, #2
	strb r0, [r3]
	ldrb r0, [r4]
	adds r1, #0x24
	adds r1, r0, r1
	ldr r2, _08054E1C
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, #6
	b _08054E9A
	.align 2, 0
_08054E14: .4byte 0x02024074
_08054E18: .4byte 0x02023EAF
_08054E1C: .4byte 0x02023D12
_08054E20:
	ldr r1, _08054E84
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #4
	strb r0, [r1, #1]
	ldr r4, _08054E88
	ldrb r0, [r4]
	strb r0, [r1, #2]
	ldr r0, _08054E8C
	adds r0, #0x24
	ldrb r5, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _08054E90
	ldr r6, _08054E94
	ldrb r0, [r4]
	movs r5, #0x58
	muls r0, r5, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x2c]
	lsrs r0, r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _08054E58
	str r3, [r1]
_08054E58:
	ldr r0, [r1]
	rsbs r0, r0, #0
	str r0, [r1]
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r0, r6
	ldrh r1, [r0, #0x28]
	ldrh r0, [r0, #0x2c]
	cmp r1, r0
	bne _08054E98
_08054E6C:
	ldrb r1, [r2, #2]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #5]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r7]
	b _08054E9C
	.align 2, 0
_08054E84: .4byte 0x02022C0C
_08054E88: .4byte 0x02023EB0
_08054E8C: .4byte 0x02024074
_08054E90: .4byte 0x02023E94
_08054E94: .4byte 0x02023D28
_08054E98:
	adds r0, r2, #6
_08054E9A:
	str r0, [r7]
_08054E9C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end atkD4_trywish

	thumb_func_start atkD5_trysetroots
atkD5_trysetroots: @ 0x08054EA4
	push {lr}
	ldr r1, _08054EDC
	ldr r0, _08054EE0
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _08054EE8
	ldr r3, _08054EE4
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08054EF4
	.align 2, 0
_08054EDC: .4byte 0x02023F50
_08054EE0: .4byte 0x02023EAF
_08054EE4: .4byte 0x02023EB8
_08054EE8:
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08054EF8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08054EF4:
	pop {r0}
	bx r0
	.align 2, 0
_08054EF8: .4byte 0x02023EB8
	thumb_func_end atkD5_trysetroots

	thumb_func_start atkD6_doubledamagedealtifdamaged
atkD6_doubledamagedealtifdamaged: @ 0x08054EFC
	push {lr}
	ldr r3, _08054F48
	ldr r0, _08054F4C
	ldrb r0, [r0]
	lsls r2, r0, #4
	adds r0, r3, #4
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, #0
	beq _08054F1C
	adds r0, r2, r3
	ldr r1, _08054F50
	ldrb r0, [r0, #0xc]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08054F34
_08054F1C:
	adds r0, r3, #0
	adds r0, #8
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, #0
	beq _08054F3A
	adds r0, r2, r3
	ldr r1, _08054F50
	ldrb r0, [r0, #0xd]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08054F3A
_08054F34:
	ldr r1, _08054F54
	movs r0, #2
	strb r0, [r1, #0xe]
_08054F3A:
	ldr r1, _08054F58
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08054F48: .4byte 0x02023FE0
_08054F4C: .4byte 0x02023EAF
_08054F50: .4byte 0x02023EB0
_08054F54: .4byte 0x02024118
_08054F58: .4byte 0x02023EB8
	thumb_func_end atkD6_doubledamagedealtifdamaged

	thumb_func_start atkD7_setyawn
atkD7_setyawn: @ 0x08054F5C
	push {r4, lr}
	ldr r1, _08054FA0
	ldr r0, _08054FA4
	ldrb r3, [r0]
	lsls r0, r3, #2
	adds r4, r0, r1
	ldr r2, [r4]
	movs r0, #0xc0
	lsls r0, r0, #5
	ands r0, r2
	cmp r0, #0
	bne _08054F84
	ldr r1, _08054FA8
	movs r0, #0x58
	muls r0, r3, r0
	adds r1, #0x4c
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08054FB0
_08054F84:
	ldr r3, _08054FAC
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08054FC0
	.align 2, 0
_08054FA0: .4byte 0x02023F50
_08054FA4: .4byte 0x02023EB0
_08054FA8: .4byte 0x02023D28
_08054FAC: .4byte 0x02023EB8
_08054FB0:
	movs r0, #0x80
	lsls r0, r0, #5
	orrs r2, r0
	str r2, [r4]
	ldr r1, _08054FC8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08054FC0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054FC8: .4byte 0x02023EB8
	thumb_func_end atkD7_setyawn

	thumb_func_start atkD8_setdamagetohealthdifference
atkD8_setdamagetohealthdifference: @ 0x08054FCC
	push {lr}
	ldr r2, _08055008
	ldr r0, _0805500C
	ldrb r0, [r0]
	movs r1, #0x58
	muls r0, r1, r0
	adds r3, r0, r2
	ldr r0, _08055010
	ldrb r0, [r0]
	muls r0, r1, r0
	adds r1, r0, r2
	ldrh r0, [r3, #0x28]
	ldrh r2, [r1, #0x28]
	cmp r0, r2
	bhi _08055018
	ldr r3, _08055014
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805502A
	.align 2, 0
_08055008: .4byte 0x02023D28
_0805500C: .4byte 0x02023EB0
_08055010: .4byte 0x02023EAF
_08055014: .4byte 0x02023EB8
_08055018:
	ldr r2, _08055030
	ldrh r0, [r3, #0x28]
	ldrh r1, [r1, #0x28]
	subs r0, r0, r1
	str r0, [r2]
	ldr r1, _08055034
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805502A:
	pop {r0}
	bx r0
	.align 2, 0
_08055030: .4byte 0x02023E94
_08055034: .4byte 0x02023EB8
	thumb_func_end atkD8_setdamagetohealthdifference

	thumb_func_start atkD9_scaledamagebyhealthratio
atkD9_scaledamagebyhealthratio: @ 0x08055038
	push {r4, lr}
	ldr r4, _08055084
	ldrh r0, [r4]
	cmp r0, #0
	bne _08055074
	ldr r2, _08055088
	ldr r0, _0805508C
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r3, [r0, #1]
	ldr r2, _08055090
	ldr r0, _08055094
	ldrb r1, [r0]
	movs r0, #0x58
	muls r1, r0, r1
	adds r1, r1, r2
	ldrh r0, [r1, #0x28]
	muls r0, r3, r0
	ldrh r1, [r1, #0x2c]
	bl __divsi3
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08055074
	movs r0, #1
	strh r0, [r4]
_08055074:
	ldr r1, _08055098
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055084: .4byte 0x020240A4
_08055088: .4byte 0x082ED220
_0805508C: .4byte 0x02023E8E
_08055090: .4byte 0x02023D28
_08055094: .4byte 0x02023EAF
_08055098: .4byte 0x02023EB8
	thumb_func_end atkD9_scaledamagebyhealthratio

	thumb_func_start atkDA_tryswapabilities
atkDA_tryswapabilities: @ 0x0805509C
	push {r4, r5, r6, lr}
	ldr r5, _08055100
	ldr r0, _08055104
	ldrb r0, [r0]
	movs r4, #0x58
	muls r0, r4, r0
	adds r0, r0, r5
	adds r2, r0, #0
	adds r2, #0x20
	ldrb r1, [r2]
	cmp r1, #0
	bne _080550C4
	ldr r0, _08055108
	ldrb r0, [r0]
	muls r0, r4, r0
	adds r0, r0, r5
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _080550E4
_080550C4:
	cmp r1, #0x19
	beq _080550E4
	ldr r6, _08055108
	ldrb r0, [r6]
	muls r0, r4, r0
	adds r0, r0, r5
	adds r0, #0x20
	ldrb r3, [r0]
	cmp r3, #0x19
	beq _080550E4
	ldr r0, _0805510C
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _08055114
_080550E4:
	ldr r3, _08055110
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805512A
	.align 2, 0
_08055100: .4byte 0x02023D28
_08055104: .4byte 0x02023EAF
_08055108: .4byte 0x02023EB0
_0805510C: .4byte 0x02023F20
_08055110: .4byte 0x02023EB8
_08055114:
	ldrb r1, [r2]
	strb r3, [r2]
	ldrb r0, [r6]
	muls r0, r4, r0
	adds r0, r0, r5
	adds r0, #0x20
	strb r1, [r0]
	ldr r1, _08055130
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805512A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08055130: .4byte 0x02023EB8
	thumb_func_end atkDA_tryswapabilities

	thumb_func_start atkDB_tryimprison
atkDB_tryimprison: @ 0x08055134
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r1, _08055154
	ldr r4, _08055158
	ldrb r2, [r4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	ands r0, r1
	cmp r0, #0
	beq _08055184
	b _08055206
	.align 2, 0
_08055154: .4byte 0x02023F50
_08055158: .4byte 0x02023EAF
_0805515C:
	ldr r0, _0805517C
	mov r2, sb
	ldrb r1, [r2]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08055180
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _080551FE
	.align 2, 0
_0805517C: .4byte 0x02023F50
_08055180: .4byte 0x02023EB8
_08055184:
	adds r0, r2, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldrb r0, [r4]
	bl PressurePPLoseOnUsingImprison
	movs r6, #0
	b _080551F6
_0805519A:
	adds r0, r6, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r8, r0
	beq _080551F0
	movs r4, #0
	ldr r7, _0805522C
	mov sb, r7
	ldr r0, _08055230
	mov ip, r0
	mov r1, sb
	ldrb r0, [r1]
	mov r2, ip
	adds r2, #0xc
	movs r1, #0x58
	muls r0, r1, r0
	adds r3, r0, r2
	adds r5, r6, #0
	muls r5, r1, r5
_080551C4:
	movs r2, #0
	ldrh r1, [r3]
	mov r0, ip
	adds r0, #0xc
	adds r0, r5, r0
_080551CE:
	ldrh r7, [r0]
	cmp r1, r7
	bne _080551D8
	cmp r1, #0
	bne _080551E0
_080551D8:
	adds r0, #2
	adds r2, #1
	cmp r2, #3
	ble _080551CE
_080551E0:
	cmp r2, #4
	bne _080551EC
	adds r3, #2
	adds r4, #1
	cmp r4, #3
	ble _080551C4
_080551EC:
	cmp r4, #4
	bne _0805515C
_080551F0:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_080551F6:
	ldr r0, _08055234
	ldrb r0, [r0]
	cmp r6, r0
	blo _0805519A
_080551FE:
	ldr r0, _08055234
	ldrb r0, [r0]
	cmp r6, r0
	bne _08055220
_08055206:
	ldr r3, _08055238
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055220:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805522C: .4byte 0x02023EAF
_08055230: .4byte 0x02023D28
_08055234: .4byte 0x02023D10
_08055238: .4byte 0x02023EB8
	thumb_func_end atkDB_tryimprison

	thumb_func_start atkDC_trysetgrudge
atkDC_trysetgrudge: @ 0x0805523C
	push {lr}
	ldr r1, _08055274
	ldr r0, _08055278
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _08055280
	ldr r3, _0805527C
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805528C
	.align 2, 0
_08055274: .4byte 0x02023F50
_08055278: .4byte 0x02023EAF
_0805527C: .4byte 0x02023EB8
_08055280:
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08055290
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805528C:
	pop {r0}
	bx r0
	.align 2, 0
_08055290: .4byte 0x02023EB8
	thumb_func_end atkDC_trysetgrudge

	thumb_func_start atkDD_weightdamagecalculation
atkDD_weightdamagecalculation: @ 0x08055294
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r5, #0
	ldr r2, _080552F8
	ldrh r0, [r2]
	ldr r1, _080552FC
	cmp r0, r1
	beq _0805530C
	adds r6, r2, #0
	ldr r0, _08055300
	mov r8, r0
	adds r7, r1, #0
	adds r4, r6, #0
_080552B0:
	ldr r0, _08055304
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	add r0, r8
	ldrh r0, [r0]
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl GetPokedexHeightWeight
	ldrh r1, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bhi _080552DE
	adds r4, #4
	adds r5, #2
	ldrh r0, [r4]
	cmp r0, r7
	bne _080552B0
_080552DE:
	lsls r0, r5, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	ldr r0, _080552FC
	cmp r1, r0
	beq _0805530C
	ldr r0, _08055308
	adds r1, r5, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	strh r1, [r0]
	b _08055312
	.align 2, 0
_080552F8: .4byte 0x082ECDAC
_080552FC: .4byte 0x0000FFFF
_08055300: .4byte 0x02023D28
_08055304: .4byte 0x02023EB0
_08055308: .4byte 0x020240A4
_0805530C:
	ldr r1, _08055324
	movs r0, #0x78
	strh r0, [r1]
_08055312:
	ldr r1, _08055328
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08055324: .4byte 0x020240A4
_08055328: .4byte 0x02023EB8
	thumb_func_end atkDD_weightdamagecalculation

	thumb_func_start atkDE_assistattackselect
atkDE_assistattackselect: @ 0x0805532C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r0, #0
	mov sl, r0
	ldr r0, _0805544C
	ldr r0, [r0]
	adds r0, #0x18
	str r0, [sp, #4]
	ldr r0, _08055450
	ldrb r0, [r0]
	bl GetBattlerPosition
	movs r1, #1
	ands r1, r0
	ldr r0, _08055454
	str r0, [sp]
	cmp r1, #0
	beq _0805535C
	ldr r1, _08055458
	str r1, [sp]
_0805535C:
	movs r2, #0
_0805535E:
	ldr r1, _0805545C
	ldr r0, _08055450
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r1, r2, #1
	str r1, [sp, #8]
	ldrh r0, [r0]
	cmp r2, r0
	beq _08055404
	movs r0, #0x64
	adds r6, r2, #0
	muls r6, r0, r6
	ldr r0, [sp]
	adds r4, r0, r6
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	cmp r0, #0
	beq _08055404
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	movs r1, #0xce
	lsls r1, r1, #1
	cmp r0, r1
	beq _08055404
	movs r5, #0
	ldr r1, _08055460
	mov r8, r1
	mov sb, r6
	mov r1, sl
	lsls r0, r1, #1
	ldr r1, [sp, #4]
	adds r6, r0, r1
_080553A8:
	movs r7, #0
	adds r1, r5, #0
	adds r1, #0xd
	ldr r0, [sp]
	add r0, sb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl IsInvalidForSleepTalkOrAssist
	lsls r0, r0, #0x18
	adds r1, r5, #1
	cmp r0, #0
	bne _080553FE
	ldr r0, _08055464
	ldrh r2, [r0]
	adds r3, r0, #0
	cmp r2, r8
	beq _080553F2
	cmp r4, r2
	beq _080553E8
	ldr r5, _08055460
	adds r2, r3, #0
_080553DA:
	adds r2, #2
	adds r7, #1
	ldrh r0, [r2]
	cmp r0, r5
	beq _080553F2
	cmp r4, r0
	bne _080553DA
_080553E8:
	lsls r0, r7, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, r8
	bne _080553FE
_080553F2:
	cmp r4, #0
	beq _080553FE
	strh r4, [r6]
	adds r6, #2
	movs r0, #1
	add sl, r0
_080553FE:
	adds r5, r1, #0
	cmp r5, #3
	ble _080553A8
_08055404:
	ldr r2, [sp, #8]
	cmp r2, #5
	ble _0805535E
	mov r1, sl
	cmp r1, #0
	beq _0805547C
	ldr r2, _08055468
	ldr r0, [r2]
	ldr r1, _0805546C
	ands r0, r1
	str r0, [r2]
	ldr r4, _08055470
	bl Random
	movs r1, #0xff
	ands r1, r0
	mov r0, sl
	muls r0, r1, r0
	asrs r0, r0, #8
	lsls r0, r0, #1
	ldr r1, [sp, #4]
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, #0
	bl GetMoveTarget
	ldr r1, _08055474
	strb r0, [r1]
	ldr r1, _08055478
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08055496
	.align 2, 0
_0805544C: .4byte 0x02024140
_08055450: .4byte 0x02023EAF
_08055454: .4byte 0x02024190
_08055458: .4byte 0x020243E8
_0805545C: .4byte 0x02023D12
_08055460: .4byte 0x0000FFFF
_08055464: .4byte 0x082ECD64
_08055468: .4byte 0x02023F24
_0805546C: .4byte 0xFFFFFBFF
_08055470: .4byte 0x02023E92
_08055474: .4byte 0x02023EB0
_08055478: .4byte 0x02023EB8
_0805547C:
	ldr r3, _080554A8
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055496:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080554A8: .4byte 0x02023EB8
	thumb_func_end atkDE_assistattackselect

	thumb_func_start atkDF_trysetmagiccoat
atkDF_trysetmagiccoat: @ 0x080554AC
	push {lr}
	ldr r1, _080554F4
	ldr r3, _080554F8
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r2, _080554FC
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r0, _08055500
	ldrb r1, [r0]
	ldr r0, _08055504
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _0805550C
	ldr r3, _08055508
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08055524
	.align 2, 0
_080554F4: .4byte 0x02023EB0
_080554F8: .4byte 0x02023EAF
_080554FC: .4byte 0x02024020
_08055500: .4byte 0x02023D26
_08055504: .4byte 0x02023D10
_08055508: .4byte 0x02023EB8
_0805550C:
	ldr r0, _08055528
	ldrb r1, [r3]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r1]
	ldr r1, _0805552C
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08055524:
	pop {r0}
	bx r0
	.align 2, 0
_08055528: .4byte 0x02023FE0
_0805552C: .4byte 0x02023EB8
	thumb_func_end atkDF_trysetmagiccoat

	thumb_func_start atkE0_trysetsnatch
atkE0_trysetsnatch: @ 0x08055530
	push {lr}
	ldr r2, _08055574
	ldr r3, _08055578
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r0, _0805557C
	ldrb r1, [r0]
	ldr r0, _08055580
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _08055588
	ldr r3, _08055584
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805559E
	.align 2, 0
_08055574: .4byte 0x02024020
_08055578: .4byte 0x02023EAF
_0805557C: .4byte 0x02023D26
_08055580: .4byte 0x02023D10
_08055584: .4byte 0x02023EB8
_08055588:
	ldr r0, _080555A4
	ldrb r1, [r3]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldr r1, _080555A8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805559E:
	pop {r0}
	bx r0
	.align 2, 0
_080555A4: .4byte 0x02023FE0
_080555A8: .4byte 0x02023EB8
	thumb_func_end atkE0_trysetsnatch

	thumb_func_start atkE1_trygetintimidatetarget
atkE1_trygetintimidatetarget: @ 0x080555AC
	push {r4, r5, r6, lr}
	ldr r4, _08055650
	ldr r0, _08055654
	ldr r0, [r0]
	adds r0, #0xd8
	ldrb r0, [r0]
	strb r0, [r4, #0x17]
	ldrb r0, [r4, #0x17]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _08055658
	movs r0, #0xfd
	strb r0, [r2]
	movs r0, #9
	strb r0, [r2, #1]
	ldr r3, _0805565C
	ldrb r1, [r4, #0x17]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r2, #2]
	movs r0, #0xff
	strb r0, [r2, #3]
	ldr r2, _08055660
	ldr r1, _08055664
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08055632
	adds r4, r2, #0
	ldr r6, _08055668
_080555F2:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	beq _08055614
	ldr r0, _0805566C
	ldrb r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ands r1, r0
	ldr r2, _08055664
	cmp r1, #0
	beq _08055628
_08055614:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _08055664
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r1, #0
	ldrb r1, [r2]
	cmp r0, r1
	blo _080555F2
_08055628:
	ldr r0, _08055660
	ldrb r0, [r0]
	ldrb r2, [r2]
	cmp r0, r2
	blo _08055674
_08055632:
	ldr r3, _08055670
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805567C
	.align 2, 0
_08055650: .4byte 0x02024118
_08055654: .4byte 0x02024140
_08055658: .4byte 0x02022C0C
_0805565C: .4byte 0x02023D28
_08055660: .4byte 0x02023EB0
_08055664: .4byte 0x02023D10
_08055668: .4byte 0x082FACB4
_0805566C: .4byte 0x02023EB4
_08055670: .4byte 0x02023EB8
_08055674:
	ldr r1, _08055684
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805567C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08055684: .4byte 0x02023EB8
	thumb_func_end atkE1_trygetintimidatetarget

	thumb_func_start atkE2_switchoutabilities
atkE2_switchoutabilities: @ 0x08055688
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r5, _080556F0
	ldr r0, [r5]
	ldrb r0, [r0, #1]
	bl GetBattlerForBattleScript
	ldr r4, _080556F4
	strb r0, [r4]
	ldr r3, _080556F8
	ldrb r0, [r4]
	movs r6, #0x58
	adds r1, r0, #0
	muls r1, r6, r1
	adds r0, r1, r3
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _080556E2
	adds r3, #0x4c
	adds r1, r1, r3
	movs r0, #0
	str r0, [r1]
	ldr r2, _080556FC
	ldrb r1, [r4]
	ldr r0, _08055700
	ldr r0, [r0]
	adds r0, r1, r0
	adds r0, #0x58
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r2, [r0]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r0, r3
	str r0, [sp]
	movs r0, #0
	movs r1, #0x28
	movs r3, #4
	bl BtlController_EmitSetMonData
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_080556E2:
	ldr r0, [r5]
	adds r0, #2
	str r0, [r5]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080556F0: .4byte 0x02023EB8
_080556F4: .4byte 0x02023D08
_080556F8: .4byte 0x02023D28
_080556FC: .4byte 0x082FACB4
_08055700: .4byte 0x02024140
	thumb_func_end atkE2_switchoutabilities

	thumb_func_start atkE3_jumpifhasnohp
atkE3_jumpifhasnohp: @ 0x08055704
	push {r4, lr}
	ldr r4, _08055740
	ldr r0, [r4]
	ldrb r0, [r0, #1]
	bl GetBattlerForBattleScript
	ldr r1, _08055744
	strb r0, [r1]
	ldr r2, _08055748
	ldrb r1, [r1]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _0805574C
	ldr r2, [r4]
	ldrb r1, [r2, #2]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #5]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r4]
	b _08055752
	.align 2, 0
_08055740: .4byte 0x02023EB8
_08055744: .4byte 0x02023D08
_08055748: .4byte 0x02023D28
_0805574C:
	ldr r0, [r4]
	adds r0, #6
	str r0, [r4]
_08055752:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end atkE3_jumpifhasnohp

	thumb_func_start atkE4_getsecretpowereffect
atkE4_getsecretpowereffect: @ 0x08055758
	push {lr}
	ldr r0, _0805576C
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080557F4
	lsls r0, r0, #2
	ldr r1, _08055770
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805576C: .4byte 0x02022C94
_08055770: .4byte 0x08055774
_08055774: @ jump table
	.4byte _08055794 @ case 0
	.4byte _080557A0 @ case 1
	.4byte _080557AC @ case 2
	.4byte _080557B8 @ case 3
	.4byte _080557C4 @ case 4
	.4byte _080557D0 @ case 5
	.4byte _080557DC @ case 6
	.4byte _080557E8 @ case 7
_08055794:
	ldr r1, _0805579C
	movs r0, #2
	b _080557F8
	.align 2, 0
_0805579C: .4byte 0x02023FD6
_080557A0:
	ldr r1, _080557A8
	movs r0, #1
	b _080557F8
	.align 2, 0
_080557A8: .4byte 0x02023FD6
_080557AC:
	ldr r1, _080557B4
	movs r0, #0x1b
	b _080557F8
	.align 2, 0
_080557B4: .4byte 0x02023FD6
_080557B8:
	ldr r1, _080557C0
	movs r0, #0x17
	b _080557F8
	.align 2, 0
_080557C0: .4byte 0x02023FD6
_080557C4:
	ldr r1, _080557CC
	movs r0, #0x16
	b _080557F8
	.align 2, 0
_080557CC: .4byte 0x02023FD6
_080557D0:
	ldr r1, _080557D8
	movs r0, #0x18
	b _080557F8
	.align 2, 0
_080557D8: .4byte 0x02023FD6
_080557DC:
	ldr r1, _080557E4
	movs r0, #7
	b _080557F8
	.align 2, 0
_080557E4: .4byte 0x02023FD6
_080557E8:
	ldr r1, _080557F0
	movs r0, #8
	b _080557F8
	.align 2, 0
_080557F0: .4byte 0x02023FD6
_080557F4:
	ldr r1, _08055808
	movs r0, #5
_080557F8:
	strb r0, [r1, #3]
	ldr r1, _0805580C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08055808: .4byte 0x02023FD6
_0805580C: .4byte 0x02023EB8
	thumb_func_end atkE4_getsecretpowereffect

	thumb_func_start atkE5_pickup
atkE5_pickup: @ 0x08055810
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl InBattlePike
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08055828
	b _080559E8
_08055828:
	bl CurrentBattlePyramidLocation
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080558D4
	movs r6, #0
	mov r7, sp
	ldr r0, _08055874
	mov r8, r0
_0805583A:
	movs r0, #0x64
	adds r4, r6, #0
	muls r4, r0, r4
	ldr r0, _08055878
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #0xc
	bl GetMonData3
	strh r0, [r7]
	adds r0, r4, #0
	movs r1, #0x2e
	bl GetMonData3
	cmp r0, #0
	beq _0805587C
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0, #0x17]
	b _08055886
	.align 2, 0
_08055874: .4byte 0x082F0D54
_08055878: .4byte 0x02024190
_0805587C:
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0, #0x16]
_08055886:
	cmp r0, #0x35
	bne _080558C6
	cmp r5, #0
	beq _080558C6
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r5, r0
	beq _080558C6
	ldrh r0, [r7]
	cmp r0, #0
	bne _080558C6
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080558C6
	bl GetBattlePyramidPickupItemId
	strh r0, [r7]
	movs r0, #0x64
	muls r0, r6, r0
	ldr r1, _080558D0
	adds r0, r0, r1
	movs r1, #0xc
	mov r2, sp
	bl SetMonData
_080558C6:
	adds r6, #1
	cmp r6, #5
	ble _0805583A
	b _080559E8
	.align 2, 0
_080558D0: .4byte 0x02024190
_080558D4:
	movs r6, #0
	movs r1, #0x64
	mov r8, r1
	ldr r7, _08055918
	mov sl, sp
_080558DE:
	mov r4, r8
	muls r4, r6, r4
	adds r4, r4, r7
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #0xc
	bl GetMonData3
	mov r1, sl
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x2e
	bl GetMonData3
	cmp r0, #0
	beq _08055940
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	ldr r1, _0805591C
	adds r0, r0, r1
	ldrb r0, [r0, #0x17]
	b _0805594C
	.align 2, 0
_08055918: .4byte 0x02024190
_0805591C: .4byte 0x082F0D54
_08055920:
	mov r0, r8
	muls r0, r6, r0
	adds r0, r0, r7
	adds r2, r1, #0
	adds r2, #0x63
	subs r2, r2, r4
	lsls r2, r2, #1
	ldr r1, _0805593C
	adds r2, r2, r1
	movs r1, #0xc
	bl SetMonData
	b _080559E0
	.align 2, 0
_0805593C: .4byte 0x082ECDE8
_08055940:
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	ldr r1, _080559B0
	adds r0, r0, r1
	ldrb r0, [r0, #0x16]
_0805594C:
	adds r1, r6, #1
	mov sb, r1
	cmp r0, #0x35
	bne _080559E0
	cmp r5, #0
	beq _080559E0
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r5, r0
	beq _080559E0
	mov r1, sl
	ldrh r0, [r1]
	cmp r0, #0
	bne _080559E0
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080559E0
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, r8
	muls r0, r6, r0
	adds r0, r0, r7
	movs r1, #0x38
	bl GetMonData3
	subs r0, #1
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #9
	bls _080559AC
	movs r1, #9
_080559AC:
	movs r2, #0
	b _080559BE
	.align 2, 0
_080559B0: .4byte 0x082F0D54
_080559B4:
	adds r0, r4, #0
	subs r0, #0x62
	cmp r0, #1
	bls _08055920
	adds r2, #1
_080559BE:
	cmp r2, #8
	bgt _080559E0
	ldr r0, _08055A00
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, r4
	ble _080559B4
	mov r0, r8
	muls r0, r6, r0
	adds r0, r0, r7
	adds r2, r1, r2
	lsls r2, r2, #1
	ldr r1, _08055A04
	adds r2, r2, r1
	movs r1, #0xc
	bl SetMonData
_080559E0:
	mov r6, sb
	cmp r6, #5
	bgt _080559E8
	b _080558DE
_080559E8:
	ldr r1, _08055A08
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08055A00: .4byte 0x082ECDFE
_08055A04: .4byte 0x082ECDC4
_08055A08: .4byte 0x02023EB8
	thumb_func_end atkE5_pickup

	thumb_func_start atkE6_docastformchangeanimation
atkE6_docastformchangeanimation: @ 0x08055A0C
	push {r4, lr}
	ldr r4, _08055A60
	ldr r0, _08055A64
	ldrb r0, [r0, #0x17]
	strb r0, [r4]
	ldr r1, _08055A68
	ldrb r2, [r4]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x11
	ands r0, r1
	ldr r3, _08055A6C
	cmp r0, #0
	beq _08055A3C
	ldr r0, [r3]
	adds r0, #0x7f
	ldrb r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strb r1, [r0]
_08055A3C:
	ldr r0, [r3]
	adds r0, #0x7f
	ldrb r2, [r0]
	movs r0, #0
	movs r1, #0
	bl BtlController_EmitBattleAnimation
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r1, _08055A70
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055A60: .4byte 0x02023D08
_08055A64: .4byte 0x02024118
_08055A68: .4byte 0x02023D28
_08055A6C: .4byte 0x02024140
_08055A70: .4byte 0x02023EB8
	thumb_func_end atkE6_docastformchangeanimation

	thumb_func_start atkE7_trycastformdatachange
atkE7_trycastformdatachange: @ 0x08055A74
	push {r4, lr}
	ldr r1, _08055AA4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _08055AA8
	ldrb r0, [r0, #0x17]
	bl CastformDataTypeChange
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _08055A9E
	ldr r0, _08055AAC
	bl BattleScriptPushCursorAndCallback
	ldr r0, _08055AB0
	ldr r0, [r0]
	adds r0, #0x7f
	subs r1, r4, #1
	strb r1, [r0]
_08055A9E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055AA4: .4byte 0x02023EB8
_08055AA8: .4byte 0x02024118
_08055AAC: .4byte 0x08289A31
_08055AB0: .4byte 0x02024140
	thumb_func_end atkE7_trycastformdatachange

	thumb_func_start atkE8_settypebasedhalvers
atkE8_settypebasedhalvers: @ 0x08055AB4
	push {r4, lr}
	movs r4, #0
	ldr r2, _08055AF0
	ldr r0, _08055AF4
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0xc9
	bne _08055B04
	ldr r1, _08055AF8
	ldr r0, _08055AFC
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	bne _08055B28
	orrs r1, r3
	str r1, [r2]
	ldr r0, _08055B00
	strb r4, [r0, #5]
	b _08055B2C
	.align 2, 0
_08055AF0: .4byte 0x082ED220
_08055AF4: .4byte 0x02023E8E
_08055AF8: .4byte 0x02023F50
_08055AFC: .4byte 0x02023EAF
_08055B00: .4byte 0x02023FD6
_08055B04:
	ldr r1, _08055B38
	ldr r0, _08055B3C
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #0xa
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	bne _08055B28
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08055B40
	movs r0, #1
	strb r0, [r1, #5]
	movs r4, #1
_08055B28:
	cmp r4, #0
	beq _08055B48
_08055B2C:
	ldr r1, _08055B44
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08055B62
	.align 2, 0
_08055B38: .4byte 0x02023F50
_08055B3C: .4byte 0x02023EAF
_08055B40: .4byte 0x02023FD6
_08055B44: .4byte 0x02023EB8
_08055B48:
	ldr r3, _08055B68
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055B62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055B68: .4byte 0x02023EB8
	thumb_func_end atkE8_settypebasedhalvers

	thumb_func_start atkE9_setweatherballtype
atkE9_setweatherballtype: @ 0x08055B6C
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08055C0C
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0x4d
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08055C0C
	ldr r2, _08055BBC
	ldrb r0, [r2]
	cmp r0, #0
	beq _08055BAA
	ldr r1, _08055BC0
	movs r0, #2
	strb r0, [r1, #0xe]
_08055BAA:
	ldrh r1, [r2]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _08055BC8
	ldr r0, _08055BC4
	ldr r1, [r0]
	movs r0, #0x8b
	b _08055C0A
	.align 2, 0
_08055BBC: .4byte 0x02024070
_08055BC0: .4byte 0x02024118
_08055BC4: .4byte 0x02024140
_08055BC8:
	movs r0, #0x18
	ands r0, r1
	cmp r0, #0
	beq _08055BDC
	ldr r0, _08055BD8
	ldr r1, [r0]
	movs r0, #0x85
	b _08055C0A
	.align 2, 0
_08055BD8: .4byte 0x02024140
_08055BDC:
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	beq _08055BF0
	ldr r0, _08055BEC
	ldr r1, [r0]
	movs r0, #0x8a
	b _08055C0A
	.align 2, 0
_08055BEC: .4byte 0x02024140
_08055BF0:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08055C04
	ldr r0, _08055C00
	ldr r1, [r0]
	movs r0, #0x8f
	b _08055C0A
	.align 2, 0
_08055C00: .4byte 0x02024140
_08055C04:
	ldr r0, _08055C1C
	ldr r1, [r0]
	movs r0, #0x80
_08055C0A:
	strb r0, [r1, #0x13]
_08055C0C:
	ldr r1, _08055C20
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08055C1C: .4byte 0x02024140
_08055C20: .4byte 0x02023EB8
	thumb_func_end atkE9_setweatherballtype

	thumb_func_start atkEA_tryrecycleitem
atkEA_tryrecycleitem: @ 0x08055C24
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r7, _08055C8C
	ldr r0, _08055C90
	ldrb r0, [r0]
	strb r0, [r7]
	ldr r1, _08055C94
	ldrb r2, [r7]
	lsls r0, r2, #1
	adds r0, #0xb8
	ldr r1, [r1]
	adds r6, r1, r0
	ldrh r5, [r6]
	cmp r5, #0
	beq _08055CA4
	ldr r4, _08055C98
	movs r3, #0x58
	adds r0, r2, #0
	muls r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0, #0x2e]
	cmp r0, #0
	bne _08055CA4
	ldr r1, _08055C9C
	strh r5, [r1]
	strh r0, [r6]
	ldrb r0, [r7]
	muls r0, r3, r0
	adds r0, r0, r4
	ldrh r1, [r1]
	strh r1, [r0, #0x2e]
	ldrb r0, [r7]
	muls r0, r3, r0
	adds r1, r4, #0
	adds r1, #0x2e
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl BtlController_EmitSetMonData
	ldrb r0, [r7]
	bl MarkBattlerForControllerExec
	ldr r1, _08055CA0
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08055CBE
	.align 2, 0
_08055C8C: .4byte 0x02023D08
_08055C90: .4byte 0x02023EAF
_08055C94: .4byte 0x02024140
_08055C98: .4byte 0x02023D28
_08055C9C: .4byte 0x02023EAC
_08055CA0: .4byte 0x02023EB8
_08055CA4:
	ldr r3, _08055CC8
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055CBE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08055CC8: .4byte 0x02023EB8
	thumb_func_end atkEA_tryrecycleitem

	thumb_func_start atkEB_settypetoterrain
atkEB_settypetoterrain: @ 0x08055CCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08055D3C
	mov r8, r0
	ldr r7, _08055D40
	ldrb r0, [r7]
	movs r6, #0x58
	muls r0, r6, r0
	mov r1, r8
	adds r3, r0, r1
	movs r0, #0x21
	adds r0, r0, r3
	mov ip, r0
	ldr r5, _08055D44
	ldr r4, _08055D48
	ldrb r0, [r4]
	adds r0, r0, r5
	ldrb r2, [r0]
	mov r1, ip
	ldrb r0, [r1]
	adds r1, r2, #0
	cmp r0, r1
	beq _08055D54
	adds r0, r3, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, r1
	beq _08055D54
	mov r0, ip
	strb r2, [r0]
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r6, r1
	add r1, r8
	ldrb r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r1, #0x22
	strb r0, [r1]
	ldr r1, _08055D4C
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #3
	strb r0, [r1, #1]
	ldrb r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r1, _08055D50
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08055D6E
	.align 2, 0
_08055D3C: .4byte 0x02023D28
_08055D40: .4byte 0x02023EAF
_08055D44: .4byte 0x082ECE07
_08055D48: .4byte 0x02022C94
_08055D4C: .4byte 0x02022C0C
_08055D50: .4byte 0x02023EB8
_08055D54:
	ldr r3, _08055D78
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055D6E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08055D78: .4byte 0x02023EB8
	thumb_func_end atkEB_settypetoterrain

	thumb_func_start atkEC_pursuitrelated
atkEC_pursuitrelated: @ 0x08055D7C
	push {r4, r5, r6, lr}
	ldr r5, _08055DF0
	ldrb r0, [r5]
	bl GetBattlerPosition
	movs r1, #2
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	ldr r4, _08055DF4
	strb r0, [r4]
	ldr r0, _08055DF8
	ldr r0, [r0]
	movs r6, #1
	ands r0, r6
	cmp r0, #0
	beq _08055E1C
	ldr r0, _08055DFC
	ldrb r1, [r0]
	ldr r2, _08055E00
	ldrb r3, [r4]
	lsls r0, r3, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08055E1C
	ldr r0, _08055E04
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _08055E1C
	ldr r1, _08055E08
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	cmp r2, #0xe4
	bne _08055E1C
	ldr r0, _08055E0C
	adds r0, r3, r0
	movs r1, #0xb
	strb r1, [r0]
	ldr r0, _08055E10
	strh r2, [r0]
	ldr r1, _08055E14
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	ldr r0, _08055E18
	strb r6, [r0, #0x18]
	ldrb r1, [r5]
	adds r0, #0x20
	strb r1, [r0]
	ldrb r0, [r4]
	strb r0, [r5]
	b _08055E36
	.align 2, 0
_08055DF0: .4byte 0x02023EAF
_08055DF4: .4byte 0x02023D08
_08055DF8: .4byte 0x02022C90
_08055DFC: .4byte 0x02023EB4
_08055E00: .4byte 0x082FACB4
_08055E04: .4byte 0x02023EC0
_08055E08: .4byte 0x02023F18
_08055E0C: .4byte 0x02023D1E
_08055E10: .4byte 0x02023E8E
_08055E14: .4byte 0x02023EB8
_08055E18: .4byte 0x02024118
_08055E1C:
	ldr r3, _08055E3C
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055E36:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08055E3C: .4byte 0x02023EB8
	thumb_func_end atkEC_pursuitrelated

	thumb_func_start atkEF_snatchsetbattlers
atkEF_snatchsetbattlers: @ 0x08055E40
	push {r4, lr}
	ldr r1, _08055E64
	ldr r3, _08055E68
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r2, _08055E6C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r1, #0
	ldrb r1, [r2]
	cmp r0, r1
	bne _08055E74
	ldr r1, _08055E70
	ldrb r0, [r1, #0x17]
	strb r0, [r2]
	strb r0, [r3]
	b _08055E7A
	.align 2, 0
_08055E64: .4byte 0x02023EB2
_08055E68: .4byte 0x02023EAF
_08055E6C: .4byte 0x02023EB0
_08055E70: .4byte 0x02024118
_08055E74:
	ldr r1, _08055E8C
	ldrb r0, [r1, #0x17]
	strb r0, [r2]
_08055E7A:
	ldrb r0, [r4]
	strb r0, [r1, #0x17]
	ldr r1, _08055E90
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055E8C: .4byte 0x02024118
_08055E90: .4byte 0x02023EB8
	thumb_func_end atkEF_snatchsetbattlers

	thumb_func_start atkEE_removelightscreenreflect
atkEE_removelightscreenreflect: @ 0x08055E94
	push {r4, lr}
	ldr r0, _08055EDC
	ldrb r0, [r0]
	bl GetBattlerSide
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08055EE0
	lsls r3, r0, #1
	adds r0, r3, r0
	lsls r0, r0, #2
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	bne _08055EBC
	ldrb r1, [r4, #2]
	cmp r1, #0
	beq _08055EF4
_08055EBC:
	ldr r2, _08055EE4
	adds r2, r3, r2
	ldrh r1, [r2]
	ldr r0, _08055EE8
	ands r0, r1
	movs r3, #0
	ldr r1, _08055EEC
	ands r0, r1
	strh r0, [r2]
	strb r3, [r4]
	strb r3, [r4, #2]
	ldr r1, _08055EF0
	movs r0, #1
	strb r0, [r1, #0x18]
	strb r0, [r1, #0x19]
	b _08055EFA
	.align 2, 0
_08055EDC: .4byte 0x02023EAF
_08055EE0: .4byte 0x02023F38
_08055EE4: .4byte 0x02023F32
_08055EE8: .4byte 0x0000FFFE
_08055EEC: .4byte 0x0000FFFD
_08055EF0: .4byte 0x02024118
_08055EF4:
	ldr r0, _08055F08
	strb r1, [r0, #0x18]
	strb r1, [r0, #0x19]
_08055EFA:
	ldr r1, _08055F0C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055F08: .4byte 0x02024118
_08055F0C: .4byte 0x02023EB8
	thumb_func_end atkEE_removelightscreenreflect

	thumb_func_start atkEF_handleballthrow
atkEF_handleballthrow: @ 0x08055F10
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r0, _08055F50
	ldr r0, [r0]
	cmp r0, #0
	beq _08055F1E
	b _080562A6
_08055F1E:
	ldr r5, _08055F54
	ldr r0, _08055F58
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r6, _08055F5C
	movs r1, #1
	eors r0, r1
	strb r0, [r6]
	ldr r0, _08055F60
	ldr r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08055F6C
	movs r0, #0
	movs r1, #5
	bl BtlController_EmitBallThrowAnim
	ldrb r0, [r5]
	bl MarkBattlerForControllerExec
	ldr r1, _08055F64
	ldr r0, _08055F68
	b _080562A4
	.align 2, 0
_08055F50: .4byte 0x02023D0C
_08055F54: .4byte 0x02023D08
_08055F58: .4byte 0x02023EAF
_08055F5C: .4byte 0x02023EB0
_08055F60: .4byte 0x02022C90
_08055F64: .4byte 0x02023EB8
_08055F68: .4byte 0x0828A38A
_08055F6C:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _08055F94
	movs r0, #0
	movs r1, #4
	bl BtlController_EmitBallThrowAnim
	ldrb r0, [r5]
	bl MarkBattlerForControllerExec
	ldr r1, _08055F8C
	ldr r0, _08055F90
	b _080562A4
	.align 2, 0
_08055F8C: .4byte 0x02023EB8
_08055F90: .4byte 0x0828A352
_08055F94:
	ldr r0, _08055FB8
	ldrh r0, [r0]
	cmp r0, #5
	bne _08055FC0
	ldr r0, _08055FBC
	ldr r0, [r0]
	adds r0, #0x7c
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #8
	subs r0, r0, r1
	movs r1, #0x64
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08055FD8
	.align 2, 0
_08055FB8: .4byte 0x02023EAC
_08055FBC: .4byte 0x02024140
_08055FC0:
	ldr r3, _08055FF4
	ldr r2, _08055FF8
	ldrb r1, [r6]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r5, [r0, #8]
_08055FD8:
	ldr r2, _08055FFC
	ldrh r0, [r2]
	cmp r0, #5
	bhi _08055FE2
	b _080560D8
_08055FE2:
	subs r0, #6
	cmp r0, #6
	bls _08055FEA
	b _080560E2
_08055FEA:
	lsls r0, r0, #2
	ldr r1, _08056000
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08055FF4: .4byte 0x082F0D54
_08055FF8: .4byte 0x02023D28
_08055FFC: .4byte 0x02023EAC
_08056000: .4byte 0x08056004
_08056004: @ jump table
	.4byte _08056020 @ case 0
	.4byte _08056050 @ case 1
	.4byte _08056062 @ case 2
	.4byte _08056090 @ case 3
	.4byte _080560C0 @ case 4
	.4byte _08056082 @ case 5
	.4byte _08056082 @ case 6
_08056020:
	ldr r2, _08056048
	ldr r0, _0805604C
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	adds r1, r0, #0
	adds r1, #0x21
	ldrb r1, [r1]
	cmp r1, #0xb
	beq _080560B4
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _080560B4
	cmp r1, #6
	beq _080560B4
	cmp r0, #6
	beq _080560B4
	b _08056082
	.align 2, 0
_08056048: .4byte 0x02023D28
_0805604C: .4byte 0x02023EB0
_08056050:
	bl GetCurrentMapType
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0xa
	cmp r0, #5
	bne _080560E2
	movs r4, #0x23
	b _080560E2
_08056062:
	ldr r2, _08056088
	ldr r0, _0805608C
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0x2a
	ldrb r1, [r0]
	cmp r1, #0x27
	bhi _08056082
	movs r0, #0x28
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #9
	bhi _080560E2
_08056082:
	movs r4, #0xa
	b _080560E2
	.align 2, 0
_08056088: .4byte 0x02023D28
_0805608C: .4byte 0x02023EB0
_08056090:
	ldr r2, _080560B8
	ldr r0, _080560BC
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r0, [r0]
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	movs r4, #0xa
	cmp r0, #0
	beq _080560E2
_080560B4:
	movs r4, #0x1e
	b _080560E2
	.align 2, 0
_080560B8: .4byte 0x02023D28
_080560BC: .4byte 0x02023EB0
_080560C0:
	ldr r0, _080560D4
	ldrb r0, [r0, #0x13]
	adds r0, #0xa
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x28
	bls _080560E2
	movs r4, #0x28
	b _080560E2
	.align 2, 0
_080560D4: .4byte 0x03005A70
_080560D8:
	ldr r1, _0805614C
	ldrh r0, [r2]
	subs r0, #2
	adds r0, r0, r1
	ldrb r4, [r0]
_080560E2:
	adds r0, r5, #0
	muls r0, r4, r0
	movs r1, #0xa
	bl __divsi3
	ldr r5, _08056150
	ldr r1, _08056154
	ldrb r2, [r1]
	movs r1, #0x58
	adds r4, r2, #0
	muls r4, r1, r4
	adds r3, r4, r5
	ldrh r2, [r3, #0x2c]
	lsls r1, r2, #1
	adds r1, r1, r2
	ldrh r2, [r3, #0x28]
	lsls r2, r2, #1
	subs r2, r1, r2
	muls r0, r2, r0
	bl __divsi3
	adds r6, r0, #0
	adds r5, #0x4c
	adds r4, r4, r5
	ldr r4, [r4]
	movs r0, #0x27
	ands r0, r4
	cmp r0, #0
	beq _0805611E
	lsls r6, r6, #1
_0805611E:
	movs r0, #0xd8
	ands r4, r0
	cmp r4, #0
	beq _08056132
	lsls r0, r6, #4
	subs r0, r0, r6
	movs r1, #0xa
	bl __udivsi3
	adds r6, r0, #0
_08056132:
	ldr r1, _08056158
	ldrh r0, [r1]
	cmp r0, #5
	beq _08056174
	cmp r0, #1
	bne _08056160
	ldr r0, _0805615C
	ldrb r1, [r0, #5]
	movs r2, #2
	orrs r1, r2
	strb r1, [r0, #5]
	b _08056174
	.align 2, 0
_0805614C: .4byte 0x082ECE11
_08056150: .4byte 0x02023D28
_08056154: .4byte 0x02023EB0
_08056158: .4byte 0x02023EAC
_0805615C: .4byte 0x03005A70
_08056160:
	ldr r0, _080561B8
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #0xfe
	bhi _08056174
	adds r0, #1
	strb r0, [r1]
_08056174:
	cmp r6, #0xfe
	bls _080561D8
	movs r0, #0
	movs r1, #4
	bl BtlController_EmitBallThrowAnim
	ldr r0, _080561BC
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	ldr r1, _080561C0
	ldr r0, _080561C4
	str r0, [r1]
	ldr r1, _080561C8
	ldr r0, _080561CC
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _080561D0
	adds r0, r0, r1
	ldr r2, _080561D4
	movs r1, #0x26
	bl SetMonData
	bl CalculatePlayerPartyCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	beq _08056266
	b _08056290
	.align 2, 0
_080561B8: .4byte 0x03005A70
_080561BC: .4byte 0x02023D08
_080561C0: .4byte 0x02023EB8
_080561C4: .4byte 0x0828A30C
_080561C8: .4byte 0x02023D12
_080561CC: .4byte 0x02023EB0
_080561D0: .4byte 0x020243E8
_080561D4: .4byte 0x02023EAC
_080561D8:
	movs r0, #0xff
	lsls r0, r0, #0x10
	adds r1, r6, #0
	bl __udivsi3
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _08056200
	adds r1, r6, #0
	bl __udivsi3
	adds r6, r0, #0
	movs r4, #0
	b _0805620A
	.align 2, 0
_08056200: .4byte 0x000FFFF0
_08056204:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0805620A:
	cmp r4, #3
	bhi _0805621A
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	blo _08056204
_0805621A:
	ldr r5, _08056270
	ldrh r0, [r5]
	cmp r0, #1
	bne _08056224
	movs r4, #4
_08056224:
	movs r0, #0
	adds r1, r4, #0
	bl BtlController_EmitBallThrowAnim
	ldr r0, _08056274
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	cmp r4, #4
	bne _0805629C
	ldr r1, _08056278
	ldr r0, _0805627C
	str r0, [r1]
	ldr r1, _08056280
	ldr r0, _08056284
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _08056288
	adds r0, r0, r1
	movs r1, #0x26
	adds r2, r5, #0
	bl SetMonData
	bl CalculatePlayerPartyCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08056290
_08056266:
	ldr r1, _0805628C
	movs r0, #0
	strb r0, [r1, #5]
	b _080562A6
	.align 2, 0
_08056270: .4byte 0x02023EAC
_08056274: .4byte 0x02023D08
_08056278: .4byte 0x02023EB8
_0805627C: .4byte 0x0828A30C
_08056280: .4byte 0x02023D12
_08056284: .4byte 0x02023EB0
_08056288: .4byte 0x020243E8
_0805628C: .4byte 0x02023FD6
_08056290:
	ldr r1, _08056298
	movs r0, #1
	strb r0, [r1, #5]
	b _080562A6
	.align 2, 0
_08056298: .4byte 0x02023FD6
_0805629C:
	ldr r0, _080562AC
	strb r4, [r0, #5]
	ldr r1, _080562B0
	ldr r0, _080562B4
_080562A4:
	str r0, [r1]
_080562A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080562AC: .4byte 0x02023FD6
_080562B0: .4byte 0x02023EB8
_080562B4: .4byte 0x0828A35C
	thumb_func_end atkEF_handleballthrow

	thumb_func_start atkF0_givecaughtmon
atkF0_givecaughtmon: @ 0x080562B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08056328
	mov sb, r0
	ldr r5, _0805632C
	ldrb r0, [r5]
	movs r6, #1
	eors r0, r6
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r7, #0x64
	muls r0, r7, r0
	ldr r1, _08056330
	mov r8, r1
	add r0, r8
	bl GiveMonToPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080563A2
	bl sub_0813B254
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08056344
	ldr r0, _08056334
	strb r1, [r0, #5]
	ldr r4, _08056338
	ldr r0, _0805633C
	bl VarGet
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBoxNamePtr
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldrb r0, [r5]
	eors r0, r6
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	muls r0, r7, r0
	add r0, r8
	ldr r2, _08056340
	movs r1, #2
	bl GetMonData3
	b _0805638E
	.align 2, 0
_08056328: .4byte 0x02023D12
_0805632C: .4byte 0x02023EAF
_08056330: .4byte 0x020243E8
_08056334: .4byte 0x02023FD6
_08056338: .4byte 0x02021C40
_0805633C: .4byte 0x00004036
_08056340: .4byte 0x02021C54
_08056344:
	ldr r4, _08056434
	ldr r0, _08056438
	bl VarGet
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBoxNamePtr
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldrb r0, [r5]
	eors r0, r6
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	muls r0, r7, r0
	add r0, r8
	ldr r2, _0805643C
	movs r1, #2
	bl GetMonData3
	ldr r4, _08056440
	bl get_unknown_box_id
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBoxNamePtr
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldr r1, _08056444
	movs r0, #2
	strb r0, [r1, #5]
_0805638E:
	ldr r0, _08056448
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080563A2
	ldr r1, _08056444
	ldrb r0, [r1, #5]
	adds r0, #1
	strb r0, [r1, #5]
_080563A2:
	ldr r0, _0805644C
	mov sl, r0
	ldr r1, _08056450
	mov sb, r1
	ldrb r0, [r1]
	movs r4, #1
	eors r0, r4
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _08056454
	adds r0, r0, r6
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	ldr r5, _08056458
	strh r0, [r5, #0x28]
	mov r1, sb
	ldrb r0, [r1]
	eors r0, r4
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	adds r2, r5, #0
	adds r2, #0x2a
	movs r1, #2
	bl GetMonData3
	mov r1, sb
	ldrb r0, [r1]
	eors r4, r0
	lsls r4, r4, #1
	add r4, sl
	ldrh r0, [r4]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	movs r1, #0x26
	movs r2, #0
	bl GetMonData3
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	ldrb r2, [r5, #5]
	movs r1, #0x3d
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, #5]
	ldr r1, _0805645C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08056434: .4byte 0x02021C40
_08056438: .4byte 0x00004036
_0805643C: .4byte 0x02021C54
_08056440: .4byte 0x02021C68
_08056444: .4byte 0x02023FD6
_08056448: .4byte 0x000008AB
_0805644C: .4byte 0x02023D12
_08056450: .4byte 0x02023EAF
_08056454: .4byte 0x020243E8
_08056458: .4byte 0x03005A70
_0805645C: .4byte 0x02023EB8
	thumb_func_end atkF0_givecaughtmon

	thumb_func_start atkF1_trysetcaughtmondexflags
atkF1_trysetcaughtmondexflags: @ 0x08056460
	push {r4, r5, lr}
	ldr r4, _080564B0
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl GetMonData3
	adds r4, r0, #0
	adds r0, r5, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080564B8
	ldr r3, _080564B4
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _080564D2
	.align 2, 0
_080564B0: .4byte 0x020243E8
_080564B4: .4byte 0x02023EB8
_080564B8:
	adds r0, r5, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	adds r2, r4, #0
	bl HandleSetPokedexFlag
	ldr r1, _080564D8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_080564D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080564D8: .4byte 0x02023EB8
	thumb_func_end atkF1_trysetcaughtmondexflags

	thumb_func_start atkF2_displaydexinfo
atkF2_displaydexinfo: @ 0x080564DC
	push {r4, lr}
	sub sp, #4
	ldr r0, _08056504
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _08056508
	ldrb r0, [r0]
	cmp r0, #5
	bls _080564F8
	b _0805663C
_080564F8:
	lsls r0, r0, #2
	ldr r1, _0805650C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08056504: .4byte 0x020243E8
_08056508: .4byte 0x02023FD6
_0805650C: .4byte 0x08056510
_08056510: @ jump table
	.4byte _08056528 @ case 0
	.4byte _0805653A @ case 1
	.4byte _08056588 @ case 2
	.4byte _080565D8 @ case 3
	.4byte _080565F0 @ case 4
	.4byte _08056628 @ case 5
_08056528:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	b _08056616
_0805653A:
	ldr r0, _08056578
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08056548
	b _0805663C
_08056548:
	bl FreeAllWindowBuffers
	adds r0, r4, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0805657C
	ldr r1, _08056580
	ldrb r2, [r1]
	movs r1, #0x58
	muls r2, r1, r2
	adds r1, r3, #0
	adds r1, #0x54
	adds r1, r2, r1
	ldr r1, [r1]
	adds r3, #0x48
	adds r2, r2, r3
	ldr r2, [r2]
	bl CreateDexDisplayMonDataTask
	ldr r1, _08056584
	strb r0, [r1, #1]
	b _08056618
	.align 2, 0
_08056578: .4byte 0x02037C74
_0805657C: .4byte 0x02023D28
_08056580: .4byte 0x02023EB0
_08056584: .4byte 0x02023FD6
_08056588:
	ldr r0, _080565C0
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0805663C
	ldr r0, _080565C4
	ldr r1, [r0, #4]
	ldr r0, _080565C8
	cmp r1, r0
	bne _0805663C
	ldr r2, _080565CC
	ldr r4, _080565D0
	ldrb r1, [r4, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0805663C
	ldr r0, _080565D4
	bl SetVBlankCallback
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0805663C
	.align 2, 0
_080565C0: .4byte 0x02037C74
_080565C4: .4byte 0x03002360
_080565C8: .4byte 0x080380FD
_080565CC: .4byte 0x03005B60
_080565D0: .4byte 0x02023FD6
_080565D4: .4byte 0x080386DD
_080565D8:
	bl InitBattleBgsVideo
	bl LoadBattleTextboxAndBackground
	ldr r1, _080565EC
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	b _08056616
	.align 2, 0
_080565EC: .4byte 0x02022AD4
_080565F0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0805663C
	ldr r0, _08056620
	str r1, [sp]
	movs r1, #0
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	movs r0, #0
	bl ShowBg
	movs r0, #3
	bl ShowBg
_08056616:
	ldr r1, _08056624
_08056618:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0805663C
	.align 2, 0
_08056620: .4byte 0x0000FFFF
_08056624: .4byte 0x02023FD6
_08056628:
	ldr r0, _08056644
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0805663C
	ldr r1, _08056648
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805663C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08056644: .4byte 0x02037C74
_08056648: .4byte 0x02023EB8
	thumb_func_end atkF2_displaydexinfo

	thumb_func_start HandleBattleWindow
HandleBattleWindow: @ 0x0805664C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r4, [sp, #0x40]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x10]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x1c]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp, #0x14]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov sl, r4
	movs r1, #0
	add r0, sp, #0xc
	strh r1, [r0]
	ldr r6, [sp, #0x10]
	cmp r6, r3
	ble _08056686
	b _08056772
_08056686:
	mov r4, r8
	adds r0, r6, #1
	str r0, [sp, #0x18]
	ldr r2, [sp, #0x1c]
	cmp r4, r2
	bgt _08056768
	add r5, sp, #0xc
	lsls r7, r6, #0x18
	mov sb, r7
_08056698:
	ldr r0, [sp, #0x10]
	cmp r6, r0
	bne _080566C4
	cmp r4, r8
	bne _080566AC
	ldr r0, _080566A8
	b _0805670E
	.align 2, 0
_080566A8: .4byte 0x00001022
_080566AC:
	ldr r2, [sp, #0x1c]
	cmp r4, r2
	bne _080566BC
	ldr r0, _080566B8
	b _0805670E
	.align 2, 0
_080566B8: .4byte 0x00001024
_080566BC:
	ldr r0, _080566C0
	b _0805670E
	.align 2, 0
_080566C0: .4byte 0x00001023
_080566C4:
	ldr r7, [sp, #0x14]
	cmp r6, r7
	bne _080566F0
	cmp r4, r8
	bne _080566D8
	ldr r0, _080566D4
	b _0805670E
	.align 2, 0
_080566D4: .4byte 0x00001028
_080566D8:
	ldr r0, [sp, #0x1c]
	cmp r4, r0
	bne _080566E8
	ldr r0, _080566E4
	b _0805670E
	.align 2, 0
_080566E4: .4byte 0x0000102A
_080566E8:
	ldr r0, _080566EC
	b _0805670E
	.align 2, 0
_080566EC: .4byte 0x00001029
_080566F0:
	cmp r4, r8
	bne _080566FC
	ldr r0, _080566F8
	b _0805670E
	.align 2, 0
_080566F8: .4byte 0x00001025
_080566FC:
	ldr r2, [sp, #0x1c]
	cmp r4, r2
	bne _0805670C
	ldr r0, _08056708
	b _0805670E
	.align 2, 0
_08056708: .4byte 0x00001027
_0805670C:
	ldr r0, _08056744
_0805670E:
	strh r0, [r5]
	movs r1, #1
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _0805671E
	movs r0, #0
	strh r0, [r5]
_0805671E:
	movs r0, #0x80
	mov r7, sl
	ands r0, r7
	cmp r0, #0
	beq _08056748
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #0xc
	mov r7, sb
	lsrs r3, r7, #0x18
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _08056760
	.align 2, 0
_08056744: .4byte 0x00001026
_08056748:
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	add r1, sp, #0xc
	mov r7, sb
	lsrs r3, r7, #0x18
	bl CopyToBgTilemapBufferRect_ChangePalette
_08056760:
	adds r4, #1
	ldr r0, [sp, #0x1c]
	cmp r4, r0
	ble _08056698
_08056768:
	ldr r6, [sp, #0x18]
	ldr r2, [sp, #0x14]
	cmp r6, r2
	bgt _08056772
	b _08056686
_08056772:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end HandleBattleWindow

	thumb_func_start BattleCreateYesNoCursorAt
BattleCreateYesNoCursorAt: @ 0x08056784
	push {lr}
	sub sp, #0x10
	adds r3, r0, #0
	add r0, sp, #0xc
	movs r2, #1
	strh r2, [r0]
	movs r1, #2
	strh r1, [r0, #2]
	lsls r3, r3, #0x19
	movs r0, #0x90
	lsls r0, r0, #0x14
	adds r3, r3, r0
	lsrs r3, r3, #0x18
	str r2, [sp]
	str r1, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	add r1, sp, #0xc
	movs r2, #0x19
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	add sp, #0x10
	pop {r0}
	bx r0
	thumb_func_end BattleCreateYesNoCursorAt

	thumb_func_start BattleDestroyYesNoCursorAt
BattleDestroyYesNoCursorAt: @ 0x080567BC
	push {lr}
	sub sp, #0x10
	adds r3, r0, #0
	add r0, sp, #0xc
	ldr r1, _080567F8
	strh r1, [r0]
	strh r1, [r0, #2]
	lsls r3, r3, #0x19
	movs r0, #0x90
	lsls r0, r0, #0x14
	adds r3, r3, r0
	lsrs r3, r3, #0x18
	movs r0, #1
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	add r1, sp, #0xc
	movs r2, #0x19
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_080567F8: .4byte 0x00001016
	thumb_func_end BattleDestroyYesNoCursorAt

	thumb_func_start atkF3_trygivecaughtmonnick
atkF3_trygivecaughtmonnick: @ 0x080567FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _08056820
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #4
	bls _08056814
	b _08056A72
_08056814:
	lsls r0, r1, #2
	ldr r1, _08056824
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08056820: .4byte 0x02023FD6
_08056824: .4byte 0x08056828
_08056828: @ jump table
	.4byte _0805683C @ case 0
	.4byte _08056870 @ case 1
	.4byte _0805690C @ case 2
	.4byte _080569E4 @ case 3
	.4byte _08056A3C @ case 4
_0805683C:
	movs r4, #0
	str r4, [sp]
	movs r0, #0x18
	movs r1, #8
	movs r2, #0x1d
	movs r3, #0xd
	bl HandleBattleWindow
	ldr r0, _08056868
	movs r1, #0xc
	bl sub_0814FA04
	ldr r1, _0805686C
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	strb r4, [r1, #1]
	movs r0, #0
	bl BattleCreateYesNoCursorAt
	b _08056A72
	.align 2, 0
_08056868: .4byte 0x085ABBC9
_0805686C: .4byte 0x02023FD6
_08056870:
	ldr r0, _080568E8
	ldrh r1, [r0, #0x2e]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08056896
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08056896
	movs r0, #5
	bl PlaySE
	ldrb r0, [r4, #1]
	bl BattleDestroyYesNoCursorAt
	movs r0, #0
	strb r0, [r4, #1]
	bl BattleCreateYesNoCursorAt
_08056896:
	ldr r0, _080568E8
	ldrh r1, [r0, #0x2e]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080568BE
	ldr r4, _080568EC
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _080568BE
	movs r0, #5
	bl PlaySE
	ldrb r0, [r4, #1]
	bl BattleDestroyYesNoCursorAt
	movs r0, #1
	strb r0, [r4, #1]
	bl BattleCreateYesNoCursorAt
_080568BE:
	ldr r0, _080568E8
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080568F0
	movs r0, #5
	bl PlaySE
	ldr r1, _080568EC
	ldrb r0, [r1, #1]
	cmp r0, #0
	bne _08056902
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #3
	bl BeginFastPaletteFade
	b _08056A72
	.align 2, 0
_080568E8: .4byte 0x03002360
_080568EC: .4byte 0x02023FD6
_080568F0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080568FA
	b _08056A72
_080568FA:
	movs r0, #5
	bl PlaySE
	ldr r1, _08056908
_08056902:
	movs r0, #4
	strb r0, [r1]
	b _08056A72
	.align 2, 0
_08056908: .4byte 0x02023FD6
_0805690C:
	ldr r0, _080569C8
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805691A
	b _08056A72
_0805691A:
	ldr r7, _080569CC
	ldr r0, _080569D0
	mov sl, r0
	ldrb r0, [r0]
	movs r4, #1
	eors r0, r4
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0x64
	mov sb, r1
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _080569D4
	mov r8, r1
	add r0, r8
	ldr r1, _080569D8
	ldr r2, [r1]
	adds r2, #0x6d
	movs r1, #2
	bl GetMonData3
	bl FreeAllWindowBuffers
	mov r2, sl
	ldrb r0, [r2]
	eors r0, r4
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, r8
	movs r1, #0xb
	bl GetMonData3
	adds r6, r0, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r2, sl
	ldrb r0, [r2]
	eors r0, r4
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, r8
	bl GetMonGender
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	mov r2, sl
	ldrb r0, [r2]
	eors r4, r0
	lsls r4, r4, #1
	adds r4, r4, r7
	ldrh r0, [r4]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, r8
	movs r1, #0
	movs r2, #0
	bl GetMonData3
	ldr r2, _080569D8
	ldr r1, [r2]
	adds r1, #0x6d
	str r0, [sp]
	ldr r0, _080569DC
	str r0, [sp, #4]
	movs r0, #2
	adds r2, r6, #0
	adds r3, r5, #0
	bl DoNamingScreen
	ldr r1, _080569E0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08056A72
	.align 2, 0
_080569C8: .4byte 0x02037C74
_080569CC: .4byte 0x02023D12
_080569D0: .4byte 0x02023EAF
_080569D4: .4byte 0x020243E8
_080569D8: .4byte 0x02024140
_080569DC: .4byte 0x080380FD
_080569E0: .4byte 0x02023FD6
_080569E4:
	ldr r0, _08056A20
	ldr r1, [r0, #4]
	ldr r0, _08056A24
	cmp r1, r0
	bne _08056A72
	ldr r0, _08056A28
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08056A72
	ldr r2, _08056A2C
	ldr r0, _08056A30
	ldrb r1, [r0]
	movs r0, #1
	eors r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _08056A34
	adds r0, r0, r1
	ldr r1, _08056A38
	ldr r2, [r1]
	adds r2, #0x6d
	movs r1, #2
	bl SetMonData
	b _08056A58
	.align 2, 0
_08056A20: .4byte 0x03002360
_08056A24: .4byte 0x080380FD
_08056A28: .4byte 0x02037C74
_08056A2C: .4byte 0x02023D12
_08056A30: .4byte 0x02023EAF
_08056A34: .4byte 0x020243E8
_08056A38: .4byte 0x02024140
_08056A3C:
	bl CalculatePlayerPartyCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08056A58
	ldr r1, _08056A54
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08056A72
	.align 2, 0
_08056A54: .4byte 0x02023EB8
_08056A58:
	ldr r3, _08056A84
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08056A72:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08056A84: .4byte 0x02023EB8
	thumb_func_end atkF3_trygivecaughtmonnick

	thumb_func_start atkF4_subattackerhpbydmg
atkF4_subattackerhpbydmg: @ 0x08056A88
	ldr r2, _08056AA8
	ldr r0, _08056AAC
	ldrb r1, [r0]
	movs r0, #0x58
	muls r1, r0, r1
	adds r1, r1, r2
	ldr r0, _08056AB0
	ldr r2, [r0]
	ldrh r0, [r1, #0x28]
	subs r0, r0, r2
	strh r0, [r1, #0x28]
	ldr r1, _08056AB4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_08056AA8: .4byte 0x02023D28
_08056AAC: .4byte 0x02023EAF
_08056AB0: .4byte 0x02023E94
_08056AB4: .4byte 0x02023EB8
	thumb_func_end atkF4_subattackerhpbydmg

	thumb_func_start atkF5_removeattackerstatus1
atkF5_removeattackerstatus1: @ 0x08056AB8
	ldr r1, _08056AD4
	ldr r0, _08056AD8
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x4c
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	ldr r1, _08056ADC
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_08056AD4: .4byte 0x02023D28
_08056AD8: .4byte 0x02023EAF
_08056ADC: .4byte 0x02023EB8
	thumb_func_end atkF5_removeattackerstatus1

	thumb_func_start atkF6_finishaction
atkF6_finishaction: @ 0x08056AE0
	ldr r1, _08056AE8
	movs r0, #0xc
	strb r0, [r1]
	bx lr
	.align 2, 0
_08056AE8: .4byte 0x02023D27
	thumb_func_end atkF6_finishaction

	thumb_func_start atkF7_finishturn
atkF7_finishturn: @ 0x08056AEC
	ldr r1, _08056AFC
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _08056B00
	ldr r0, _08056B04
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	.align 2, 0
_08056AFC: .4byte 0x02023D27
_08056B00: .4byte 0x02023D26
_08056B04: .4byte 0x02023D10
	thumb_func_end atkF7_finishturn

	thumb_func_start atkF8_trainerslideout
atkF8_trainerslideout: @ 0x08056B08
	push {r4, r5, lr}
	ldr r5, _08056B30
	ldr r0, [r5]
	ldrb r0, [r0, #1]
	bl GetBattlerAtPosition
	ldr r4, _08056B34
	strb r0, [r4]
	movs r0, #0
	bl BtlController_EmitTrainerSlideBack
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r0, [r5]
	adds r0, #2
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08056B30: .4byte 0x02023EB8
_08056B34: .4byte 0x02023D08
	thumb_func_end atkF8_trainerslideout
