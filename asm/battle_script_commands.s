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


	.section .text.atkF4_battle_rest,"ax",%progbits



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
