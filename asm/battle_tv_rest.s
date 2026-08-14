.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start TryPutLinkBattleTvShowOnAir
TryPutLinkBattleTvShowOnAir: @ 0x0817E2A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r2, #0
	str r2, [sp, #8]
	ldr r3, _0817E428
	str r3, [sp, #0xc]
	movs r4, #0
	str r4, [sp, #0x10]
	movs r7, #0
	str r7, [sp, #0x14]
	mov r8, r0
	ldr r0, _0817E42C
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0xb3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0817E2D6
	b _0817E51C
_0817E2D6:
	movs r2, #0xd2
	lsls r2, r2, #1
	adds r2, r2, r1
	mov sl, r2
	movs r6, #0
_0817E2E0:
	movs r0, #0x64
	adds r4, r6, #0
	muls r4, r0, r4
	ldr r0, _0817E430
	adds r0, r4, r0
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	cmp r0, #0
	beq _0817E300
	mov r0, r8
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_0817E300:
	ldr r5, _0817E434
	adds r0, r4, r5
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	cmp r0, #0
	beq _0817E316
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
_0817E316:
	adds r6, #1
	cmp r6, #5
	ble _0817E2E0
	ldr r0, _0817E438
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0817E32A
	b _0817E51C
_0817E32A:
	cmp r8, r7
	beq _0817E330
	b _0817E51C
_0817E330:
	movs r6, #0
	lsls r3, r6, #1
	str r3, [sp, #0x18]
	movs r4, #0x64
	mov r8, r4
_0817E33A:
	mov r1, r8
	muls r1, r6, r1
	ldr r0, _0817E430
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r6, #1
	mov sb, r0
	cmp r7, #0
	beq _0817E39A
	adds r0, r4, #0
	movs r1, #0x2d
	movs r2, #0
	bl GetMonData3
	cmp r0, #0
	bne _0817E39A
	movs r4, #0
	lsls r0, r6, #3
	mov r2, sl
	adds r1, r0, r2
	movs r3, #3
_0817E370:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldrh r4, [r1]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _0817E370
	ldr r1, [sp, #8]
	lsls r0, r1, #0x10
	lsls r1, r4, #0x10
	cmp r0, r1
	bge _0817E39A
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x10]
	lsrs r1, r1, #0x10
	str r1, [sp, #8]
	str r7, [sp]
_0817E39A:
	mov r0, r8
	muls r0, r6, r0
	ldr r2, _0817E434
	adds r4, r0, r2
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r3, [sp, #8]
	lsls r3, r3, #0x10
	str r3, [sp, #0x1c]
	cmp r7, #0
	beq _0817E44C
	adds r0, r4, #0
	movs r1, #0x2d
	movs r2, #0
	bl GetMonData3
	cmp r0, #0
	bne _0817E44C
	movs r4, #0
	ldr r0, [sp, #0xc]
	lsls r2, r0, #0x10
	movs r3, #1
	lsls r1, r3, #1
	adds r1, #1
	lsls r1, r1, #4
	lsls r0, r6, #3
	adds r0, r0, r1
	mov r3, sl
	adds r1, r0, r3
	movs r3, #3
_0817E3E0:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	ldrh r4, [r1]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r1, #2
	subs r3, #1
	cmp r3, #0
	bge _0817E3E0
	asrs r1, r2, #0x10
	lsls r5, r4, #0x10
	asrs r0, r5, #0x10
	cmp r1, r0
	bne _0817E43C
	mov r0, r8
	muls r0, r6, r0
	ldr r1, _0817E434
	adds r0, r0, r1
	movs r1, #0x19
	movs r2, #0
	bl GetMonData3
	adds r4, r0, #0
	ldr r2, [sp, #0x14]
	mov r0, r8
	muls r0, r2, r0
	ldr r3, _0817E434
	adds r0, r0, r3
	movs r1, #0x19
	movs r2, #0
	bl GetMonData3
	cmp r4, r0
	bls _0817E44C
	b _0817E440
	.align 2, 0
_0817E428: .4byte 0x00007FFF
_0817E42C: .4byte 0x02024140
_0817E430: .4byte 0x02024190
_0817E434: .4byte 0x020243E8
_0817E438: .4byte 0x02022C90
_0817E43C:
	cmp r1, r0
	ble _0817E44C
_0817E440:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x14]
	lsrs r5, r5, #0x10
	str r5, [sp, #0xc]
	str r7, [sp, #4]
_0817E44C:
	mov r6, sb
	cmp r6, #5
	bgt _0817E454
	b _0817E33A
_0817E454:
	movs r4, #0
	movs r6, #0
	movs r3, #0
	ldr r5, _0817E4C0
	ldr r7, [sp, #0x10]
	lsls r0, r7, #3
	mov r1, sl
	adds r2, r0, r1
_0817E464:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r7, #0
	ldrsh r1, [r2, r7]
	cmp r0, r1
	bge _0817E474
	ldrh r4, [r2]
	adds r6, r3, #0
_0817E474:
	adds r2, #2
	adds r3, #1
	cmp r3, #3
	ble _0817E464
	movs r0, #0x64
	ldr r1, [sp, #0x10]
	muls r0, r1, r0
	adds r0, r0, r5
	adds r1, r6, #0
	adds r1, #0xd
	movs r2, #0
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r2, [sp, #0x1c]
	cmp r2, #0
	beq _0817E51C
	cmp r4, #0
	beq _0817E51C
	ldr r0, _0817E4C4
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0817E508
	ldr r3, [sp, #0x10]
	cmp r3, #2
	bhi _0817E4CC
	ldr r0, _0817E4C8
	adds r0, #0x25
	ldrb r0, [r0]
	bl GetLinkTrainerFlankId
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0817E4DC
	b _0817E51C
	.align 2, 0
_0817E4C0: .4byte 0x02024190
_0817E4C4: .4byte 0x02022C90
_0817E4C8: .4byte 0x02024118
_0817E4CC:
	ldr r0, _0817E504
	adds r0, #0x25
	ldrb r0, [r0]
	bl GetLinkTrainerFlankId
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0817E51C
_0817E4DC:
	movs r3, #0
	ldr r7, [sp, #0x14]
	cmp r7, #2
	bls _0817E4E6
	movs r3, #1
_0817E4E6:
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0817E504
	adds r1, #0x25
	ldrb r1, [r1]
	bl sub_0806EA10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r4, #0
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl PutBattleUpdateOnTheAir
	b _0817E51C
	.align 2, 0
_0817E504: .4byte 0x02024118
_0817E508:
	ldr r0, _0817E52C
	adds r0, #0x25
	ldrb r1, [r0]
	movs r0, #1
	eors r0, r1
	adds r1, r4, #0
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl PutBattleUpdateOnTheAir
_0817E51C:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817E52C: .4byte 0x02024118
	thumb_func_end TryPutLinkBattleTvShowOnAir
