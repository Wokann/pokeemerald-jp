.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start CreateNPCTrainerParty
CreateNPCTrainerParty: @ 0x080382C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x10]
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0
	mov sb, r0
	movs r0, #0x80
	lsls r0, r0, #3
	cmp r3, r0
	bne _080382EA
	movs r0, #0
	b _08038696
_080382EA:
	ldr r4, _08038328
	ldr r0, [r4]
	ldr r1, _0803832C
	ands r0, r1
	lsls r3, r3, #5
	str r3, [sp, #0x20]
	cmp r0, #8
	beq _080382FC
	b _0803868E
_080382FC:
	cmp r2, #1
	bne _08038304
	bl ZeroEnemyPartyMons
_08038304:
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08038334
	ldr r0, _08038330
	ldr r1, [sp, #0x20]
	adds r2, r1, r0
	ldrb r1, [r2, #0x18]
	movs r3, #3
	str r3, [sp, #0x18]
	adds r4, r0, #0
	cmp r1, #3
	bhi _08038340
	adds r2, r1, #0
	str r2, [sp, #0x18]
	b _08038340
	.align 2, 0
_08038328: .4byte 0x02022C90
_0803832C: .4byte 0x043F0908
_08038330: .4byte 0x082E383C
_08038334:
	ldr r1, _0803835C
	ldr r2, [sp, #0x20]
	adds r0, r2, r1
	ldrb r0, [r0, #0x18]
	str r0, [sp, #0x18]
	adds r4, r1, #0
_08038340:
	movs r3, #0
	str r3, [sp, #0x14]
	ldr r0, [sp, #0x18]
	cmp r3, r0
	blt _0803834C
	b _0803867E
_0803834C:
	ldr r2, [sp, #0x20]
	adds r1, r2, r4
	ldrb r0, [r1, #0x12]
	cmp r0, #1
	bne _08038360
	movs r3, #0x80
	mov sl, r3
	b _08038372
	.align 2, 0
_0803835C: .4byte 0x082E383C
_08038360:
	ldrb r1, [r1, #2]
	movs r0, #0x80
	ands r0, r1
	movs r1, #0x88
	mov sl, r1
	cmp r0, #0
	beq _08038372
	movs r2, #0x78
	mov sl, r2
_08038372:
	movs r6, #0
	ldr r2, [sp, #0x20]
	adds r1, r4, #4
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r3, [sp, #0x14]
	adds r3, #1
	str r3, [sp, #0x1c]
	cmp r0, #0xff
	beq _0803839E
	adds r3, r1, #0
_08038388:
	adds r1, r2, #0
	adds r0, r6, r2
	adds r0, r0, r3
	ldrb r0, [r0]
	add sb, r0
	adds r6, #1
	adds r1, r6, r1
	adds r1, r1, r3
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _08038388
_0803839E:
	ldr r1, [sp, #0x20]
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #1
	beq _0803844C
	cmp r0, #1
	bgt _080383B2
	cmp r0, #0
	beq _080383C0
	b _08038670
_080383B2:
	cmp r0, #2
	bne _080383B8
	b _08038510
_080383B8:
	cmp r0, #3
	bne _080383BE
	b _080385A8
_080383BE:
	b _08038670
_080383C0:
	adds r0, r4, #0
	adds r0, #0x1c
	ldr r2, [sp, #0x20]
	adds r0, r2, r0
	ldr r4, [r0]
	movs r6, #0
	ldr r3, [sp, #0x14]
	lsls r2, r3, #3
	adds r0, r2, r4
	ldrh r1, [r0, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08038448
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r5, r2, #0
	cmp r0, #0xff
	beq _08038406
	adds r3, r1, #0
_080383E8:
	adds r0, r2, r4
	ldrh r0, [r0, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r3
	ldrb r0, [r0]
	add sb, r0
	adds r6, #1
	adds r1, r6, r1
	adds r1, r1, r3
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080383E8
_08038406:
	mov r2, sb
	lsls r0, r2, #8
	add sl, r0
	adds r4, r5, r4
	ldrh r1, [r4]
	lsls r0, r1, #5
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r3, [sp, #0x14]
	movs r1, #0x64
	adds r0, r3, #0
	muls r0, r1, r0
	ldr r2, [sp, #0x10]
	adds r0, r2, r0
	ldrh r1, [r4, #4]
	ldrb r2, [r4, #2]
	movs r3, #1
	str r3, [sp]
	mov r3, sl
	str r3, [sp, #4]
	movs r3, #2
	str r3, [sp, #8]
	movs r3, #0
	str r3, [sp, #0xc]
	adds r3, r6, #0
	bl CreateMon
	b _08038670
	.align 2, 0
_08038448: .4byte 0x082EA31C
_0803844C:
	adds r0, r4, #0
	adds r0, #0x1c
	ldr r1, [sp, #0x20]
	adds r0, r1, r0
	ldr r7, [r0]
	movs r6, #0
	ldr r3, [sp, #0x14]
	lsls r2, r3, #4
	adds r0, r2, r7
	ldrh r1, [r0, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _08038508
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r8, r2
	cmp r0, #0xff
	beq _08038492
	adds r3, r1, #0
_08038474:
	adds r0, r2, r7
	ldrh r0, [r0, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r3
	ldrb r0, [r0]
	add sb, r0
	adds r6, #1
	adds r1, r6, r1
	adds r1, r1, r3
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _08038474
_08038492:
	mov r2, sb
	lsls r0, r2, #8
	add sl, r0
	mov r3, r8
	adds r4, r3, r7
	ldrh r1, [r4]
	lsls r0, r1, #5
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, [sp, #0x14]
	movs r1, #0x64
	adds r5, r0, #0
	muls r5, r1, r5
	ldr r2, [sp, #0x10]
	adds r5, r2, r5
	ldrh r1, [r4, #4]
	ldrb r2, [r4, #2]
	movs r0, #1
	str r0, [sp]
	mov r3, sl
	str r3, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r3, r6, #0
	bl CreateMon
	movs r6, #0
	mov r0, r8
	adds r0, #6
	adds r4, r7, r0
_080384DC:
	adds r1, r6, #0
	adds r1, #0xd
	adds r0, r5, #0
	adds r2, r4, #0
	bl SetMonData
	adds r1, r6, #0
	adds r1, #0x11
	ldrh r0, [r4]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r0, _0803850C
	adds r2, r2, r0
	adds r0, r5, #0
	bl SetMonData
	adds r4, #2
	adds r6, #1
	cmp r6, #3
	ble _080384DC
	b _08038670
	.align 2, 0
_08038508: .4byte 0x082EA31C
_0803850C: .4byte 0x082ED224
_08038510:
	adds r0, r4, #0
	adds r0, #0x1c
	ldr r1, [sp, #0x20]
	adds r0, r1, r0
	ldr r4, [r0]
	movs r6, #0
	ldr r3, [sp, #0x14]
	lsls r2, r3, #3
	adds r0, r2, r4
	ldrh r1, [r0, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _080385A4
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r5, r2, #0
	cmp r0, #0xff
	beq _08038556
	adds r3, r1, #0
_08038538:
	adds r0, r2, r4
	ldrh r0, [r0, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r3
	ldrb r0, [r0]
	add sb, r0
	adds r6, #1
	adds r1, r6, r1
	adds r1, r1, r3
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _08038538
_08038556:
	mov r2, sb
	lsls r0, r2, #8
	add sl, r0
	adds r5, r5, r4
	ldrh r1, [r5]
	lsls r0, r1, #5
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r3, [sp, #0x14]
	movs r0, #0x64
	adds r4, r3, #0
	muls r4, r0, r4
	ldr r1, [sp, #0x10]
	adds r4, r1, r4
	ldrh r1, [r5, #4]
	ldrb r2, [r5, #2]
	movs r0, #1
	str r0, [sp]
	mov r3, sl
	str r3, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r3, r6, #0
	bl CreateMon
	adds r5, #6
	adds r0, r4, #0
	movs r1, #0xc
	adds r2, r5, #0
	bl SetMonData
	b _08038670
	.align 2, 0
_080385A4: .4byte 0x082EA31C
_080385A8:
	adds r0, r4, #0
	adds r0, #0x1c
	ldr r1, [sp, #0x20]
	adds r0, r1, r0
	ldr r7, [r0]
	movs r6, #0
	ldr r3, [sp, #0x14]
	lsls r2, r3, #4
	adds r0, r2, r7
	ldrh r1, [r0, #4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldr r1, _080386A8
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r8, r2
	cmp r0, #0xff
	beq _080385EE
	adds r3, r1, #0
_080385D0:
	adds r0, r2, r7
	ldrh r0, [r0, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r3
	ldrb r0, [r0]
	add sb, r0
	adds r6, #1
	adds r1, r6, r1
	adds r1, r1, r3
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _080385D0
_080385EE:
	mov r2, sb
	lsls r0, r2, #8
	add sl, r0
	mov r3, r8
	adds r5, r3, r7
	ldrh r1, [r5]
	lsls r0, r1, #5
	subs r0, r0, r1
	movs r1, #0xff
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, [sp, #0x14]
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	ldr r2, [sp, #0x10]
	adds r4, r2, r4
	ldrh r1, [r5, #4]
	ldrb r2, [r5, #2]
	movs r0, #1
	str r0, [sp]
	mov r3, sl
	str r3, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	movs r0, #0
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r3, r6, #0
	bl CreateMon
	adds r5, #6
	adds r0, r4, #0
	movs r1, #0xc
	adds r2, r5, #0
	bl SetMonData
	movs r6, #0
	adds r5, r4, #0
	mov r0, r8
	adds r0, #8
	adds r4, r7, r0
_08038646:
	adds r1, r6, #0
	adds r1, #0xd
	adds r0, r5, #0
	adds r2, r4, #0
	bl SetMonData
	adds r1, r6, #0
	adds r1, #0x11
	ldrh r0, [r4]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r0, _080386AC
	adds r2, r2, r0
	adds r0, r5, #0
	bl SetMonData
	adds r4, #2
	adds r6, #1
	cmp r6, #3
	ble _08038646
_08038670:
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x14]
	ldr r4, _080386B0
	ldr r1, [sp, #0x18]
	cmp r0, r1
	bge _0803867E
	b _0803834C
_0803867E:
	ldr r2, _080386B4
	ldr r0, _080386B0
	ldr r3, [sp, #0x20]
	adds r0, r3, r0
	ldrb r1, [r0, #0x12]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0803868E:
	ldr r0, _080386B0
	ldr r1, [sp, #0x20]
	adds r0, r1, r0
	ldrb r0, [r0, #0x18]
_08038696:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080386A8: .4byte 0x082EA31C
_080386AC: .4byte 0x082ED224
_080386B0: .4byte 0x082E383C
_080386B4: .4byte 0x02022C90
	thumb_func_end CreateNPCTrainerParty
