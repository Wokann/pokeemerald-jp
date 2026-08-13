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
