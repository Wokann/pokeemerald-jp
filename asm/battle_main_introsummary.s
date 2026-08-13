.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleIntroDrawPartySummaryScreens
BattleIntroDrawPartySummaryScreens: @ 0x0803ABC4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x30
	ldr r0, _0803AC1C
	ldr r0, [r0]
	cmp r0, #0
	beq _0803ABD6
	b _0803AD50
_0803ABD6:
	ldr r0, _0803AC20
	ldr r0, [r0]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	bne _0803ABE4
	b _0803ACF0
_0803ABE4:
	movs r7, #0
	add r0, sp, #4
	mov r8, r0
	mov r6, r8
	mov r5, sp
_0803ABEE:
	movs r0, #0x64
	adds r1, r7, #0
	muls r1, r0, r1
	ldr r0, _0803AC24
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	cmp r0, #0
	beq _0803AC14
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	movs r1, #0xce
	lsls r1, r1, #1
	cmp r0, r1
	bne _0803AC2C
_0803AC14:
	ldr r0, _0803AC28
	strh r0, [r5]
	movs r0, #0
	b _0803AC3E
	.align 2, 0
_0803AC1C: .4byte 0x02023D0C
_0803AC20: .4byte 0x02022C90
_0803AC24: .4byte 0x020243E8
_0803AC28: .4byte 0x0000FFFF
_0803AC2C:
	adds r0, r4, #0
	movs r1, #0x39
	bl GetMonData3
	strh r0, [r5]
	adds r0, r4, #0
	movs r1, #0x37
	bl GetMonData3
_0803AC3E:
	str r0, [r6]
	adds r6, #8
	adds r5, #8
	adds r7, #1
	cmp r7, #5
	ble _0803ABEE
	movs r0, #1
	bl GetBattlerAtPosition
	ldr r4, _0803AC98
	strb r0, [r4]
	movs r0, #0
	mov r1, sp
	movs r2, #0x80
	bl BtlController_EmitDrawPartyStatusSummary
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	movs r7, #0
	mov r6, r8
	mov r5, sp
_0803AC6A:
	movs r0, #0x64
	adds r1, r7, #0
	muls r1, r0, r1
	ldr r0, _0803AC9C
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	cmp r0, #0
	beq _0803AC90
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	movs r1, #0xce
	lsls r1, r1, #1
	cmp r0, r1
	bne _0803ACA4
_0803AC90:
	ldr r0, _0803ACA0
	strh r0, [r5]
	movs r0, #0
	b _0803ACB6
	.align 2, 0
_0803AC98: .4byte 0x02023D08
_0803AC9C: .4byte 0x02024190
_0803ACA0: .4byte 0x0000FFFF
_0803ACA4:
	adds r0, r4, #0
	movs r1, #0x39
	bl GetMonData3
	strh r0, [r5]
	adds r0, r4, #0
	movs r1, #0x37
	bl GetMonData3
_0803ACB6:
	str r0, [r6]
	adds r6, #8
	adds r5, #8
	adds r7, #1
	cmp r7, #5
	ble _0803AC6A
	movs r0, #0
	bl GetBattlerAtPosition
	ldr r4, _0803ACE4
	strb r0, [r4]
	movs r0, #0
	mov r1, sp
	movs r2, #0x80
	bl BtlController_EmitDrawPartyStatusSummary
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r1, _0803ACE8
	ldr r0, _0803ACEC
	b _0803AD4E
	.align 2, 0
_0803ACE4: .4byte 0x02023D08
_0803ACE8: .4byte 0x03005A64
_0803ACEC: .4byte 0x0803AD65
_0803ACF0:
	movs r7, #0
	add r6, sp, #4
	mov r5, sp
_0803ACF6:
	movs r0, #0x64
	adds r1, r7, #0
	muls r1, r0, r1
	ldr r0, _0803AD24
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	cmp r0, #0
	beq _0803AD1C
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	movs r1, #0xce
	lsls r1, r1, #1
	cmp r0, r1
	bne _0803AD2C
_0803AD1C:
	ldr r0, _0803AD28
	strh r0, [r5]
	movs r0, #0
	b _0803AD3E
	.align 2, 0
_0803AD24: .4byte 0x02024190
_0803AD28: .4byte 0x0000FFFF
_0803AD2C:
	adds r0, r4, #0
	movs r1, #0x39
	bl GetMonData3
	strh r0, [r5]
	adds r0, r4, #0
	movs r1, #0x37
	bl GetMonData3
_0803AD3E:
	str r0, [r6]
	adds r6, #8
	adds r5, #8
	adds r7, #1
	cmp r7, #5
	ble _0803ACF6
	ldr r1, _0803AD5C
	ldr r0, _0803AD60
_0803AD4E:
	str r0, [r1]
_0803AD50:
	add sp, #0x30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803AD5C: .4byte 0x03005A64
_0803AD60: .4byte 0x0803AD9D
	thumb_func_end BattleIntroDrawPartySummaryScreens
