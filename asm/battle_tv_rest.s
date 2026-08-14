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

	thumb_func_start AddMovePoints
AddMovePoints: @ 0x0817E530
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov sb, r3
	ldr r0, _0817E58C
	ldr r0, [r0]
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r1, r1, r0
	mov r8, r1
	movs r2, #0x81
	lsls r2, r2, #2
	adds r7, r0, r2
	ldr r0, _0817E590
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _0817E594
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	mov r0, sl
	cmp r0, #0x1b
	bls _0817E580
	b _0817E918
_0817E580:
	lsls r0, r0, #2
	ldr r1, _0817E598
	adds r1, r0, r1
	ldr r1, [r1]
	mov ip, r0
	mov pc, r1
	.align 2, 0
_0817E58C: .4byte 0x02024140
_0817E590: .4byte 0x02023EAF
_0817E594: .4byte 0x02023EB0
_0817E598: .4byte 0x0817E59C
_0817E59C: @ jump table
	.4byte _0817E60C @ case 0
	.4byte _0817E60C @ case 1
	.4byte _0817E708 @ case 2
	.4byte _0817E648 @ case 3
	.4byte _0817E648 @ case 4
	.4byte _0817E648 @ case 5
	.4byte _0817E648 @ case 6
	.4byte _0817E648 @ case 7
	.4byte _0817E74C @ case 8
	.4byte _0817E74C @ case 9
	.4byte _0817E778 @ case 10
	.4byte _0817E79C @ case 11
	.4byte _0817E824 @ case 12
	.4byte _0817E88C @ case 13
	.4byte _0817E8D4 @ case 14
	.4byte _0817E74C @ case 15
	.4byte _0817E74C @ case 16
	.4byte _0817E72C @ case 17
	.4byte _0817E60C @ case 18
	.4byte _0817E6B6 @ case 19
	.4byte _0817E6F4 @ case 20
	.4byte _0817E74C @ case 21
	.4byte _0817E60C @ case 22
	.4byte _0817E60C @ case 23
	.4byte _0817E60C @ case 24
	.4byte _0817E60C @ case 25
	.4byte _0817E60C @ case 26
	.4byte _0817E60C @ case 27
_0817E60C:
	ldr r1, _0817E63C
	ldr r0, _0817E640
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r6
	lsls r1, r1, #1
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #4
	adds r1, r1, r0
	add r1, r8
	ldr r0, _0817E644
	add r0, ip
	ldr r2, [r0]
	lsls r0, r5, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	b _0817E916
	.align 2, 0
_0817E63C: .4byte 0x02023D12
_0817E640: .4byte 0x02023EAF
_0817E644: .4byte 0x085D3294
_0817E648:
	ldr r1, _0817E67C
	add r1, ip
	ldr r7, _0817E680
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r2, r0, #4
	ldr r4, _0817E684
	ldr r1, [r1]
	ldr r3, _0817E688
	ldrh r0, [r1]
	cmp r6, r0
	bne _0817E68C
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	add r0, r8
	ldrh r1, [r1, #2]
	ldrh r2, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	b _0817E918
	.align 2, 0
_0817E67C: .4byte 0x085D3294
_0817E680: .4byte 0x02023D12
_0817E684: .4byte 0x0000FFFF
_0817E688: .4byte 0x02023EAF
_0817E68C:
	adds r1, #4
	ldrh r0, [r1]
	cmp r0, r4
	bne _0817E696
	b _0817E918
_0817E696:
	cmp r6, r0
	bne _0817E68C
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	add r0, r8
	ldrh r1, [r1, #2]
	ldrh r5, [r0]
	adds r1, r1, r5
	strh r1, [r0]
	b _0817E918
_0817E6B6:
	movs r0, #1
	adds r1, r5, #0
	eors r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r0, #0x57
	ldrb r2, [r0]
	movs r1, #0x1f
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
	mov r0, sb
	lsls r1, r0, #1
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #4
	adds r1, r1, r0
	add r1, r8
	ldr r0, _0817E6F0
	add r0, ip
	ldr r2, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	b _0817E916
	.align 2, 0
_0817E6F0: .4byte 0x085D3294
_0817E6F4:
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r7, r0
	adds r0, #0x57
	ldrb r2, [r0]
	movs r1, #0x1f
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
_0817E708:
	mov r0, sb
	lsls r1, r0, #1
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #4
	adds r1, r1, r0
	add r1, r8
	ldr r0, _0817E728
	add r0, ip
	ldr r2, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	b _0817E916
	.align 2, 0
_0817E728: .4byte 0x085D3294
_0817E72C:
	lsls r1, r5, #2
	add r1, sb
	lsls r1, r1, #1
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #4
	adds r1, r1, r0
	add r1, r8
	ldr r0, _0817E748
	add r0, ip
	ldr r2, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	b _0817E910
	.align 2, 0
_0817E748: .4byte 0x085D3294
_0817E74C:
	lsls r2, r5, #2
	add r2, sb
	lsls r2, r2, #1
	movs r1, #1
	eors r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r2, r2, r0
	add r2, r8
	ldr r0, _0817E774
	add r0, ip
	ldr r1, [r0]
	lsls r0, r6, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	b _0817E918
	.align 2, 0
_0817E774: .4byte 0x085D3294
_0817E778:
	lsls r1, r5, #2
	add r1, sb
	lsls r1, r1, #1
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #4
	adds r1, r1, r0
	add r1, r8
	ldr r0, _0817E798
	add r0, ip
	ldr r0, [r0]
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	b _0817E916
	.align 2, 0
_0817E798: .4byte 0x085D3294
_0817E79C:
	lsls r0, r3, #4
	adds r2, r7, r0
	adds r0, r2, #0
	adds r0, #0x34
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	lsrs r1, r0, #0x1d
	adds r4, r2, #0
	adds r4, #0x3c
	ldrb r0, [r4]
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x1d
	cmn r1, r0
	bne _0817E7BA
	b _0817E918
_0817E7BA:
	cmp r6, #0xa
	beq _0817E7C0
	b _0817E918
_0817E7C0:
	cmp r1, #0
	beq _0817E7EC
	subs r1, #1
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x33
	ldrb r0, [r0]
	lsrs r0, r0, #6
	adds r1, r1, r0
	lsls r1, r1, #1
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r1, r1, r0
	add r1, r8
	ldr r0, _0817E820
	add r0, ip
	ldr r0, [r0]
	ldrh r0, [r0]
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
_0817E7EC:
	ldrb r0, [r4]
	lsls r0, r0, #0x1d
	lsrs r0, r0, #0x1d
	cmp r0, #0
	bne _0817E7F8
	b _0817E918
_0817E7F8:
	subs r1, r0, #1
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x3b
	ldrb r0, [r0]
	lsrs r0, r0, #6
	adds r1, r1, r0
	lsls r1, r1, #1
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r1, r1, r0
	add r1, r8
	ldr r0, _0817E820
	add r0, ip
	ldr r0, [r0]
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	b _0817E916
	.align 2, 0
_0817E820: .4byte 0x085D3294
_0817E824:
	lsls r1, r3, #4
	adds r1, r7, r1
	adds r0, r1, #0
	adds r0, #0x34
	ldrb r4, [r0]
	lsls r0, r4, #0x1a
	lsrs r2, r0, #0x1d
	adds r5, r1, #0
	adds r5, #0x3c
	ldrb r0, [r5]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1d
	cmn r2, r0
	beq _0817E918
	cmp r6, #0xd
	bne _0817E918
	cmp r2, #0
	beq _0817E86A
	subs r1, r2, #1
	lsls r1, r1, #2
	lsrs r0, r4, #6
	adds r1, r1, r0
	lsls r1, r1, #1
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r1, r1, r0
	add r1, r8
	ldr r0, _0817E888
	add r0, ip
	ldr r0, [r0]
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_0817E86A:
	ldrb r2, [r5]
	lsls r0, r2, #0x1a
	lsrs r0, r0, #0x1d
	cmp r0, #0
	beq _0817E918
	subs r1, r0, #1
	lsls r1, r1, #2
	lsrs r0, r2, #6
	adds r1, r1, r0
	lsls r1, r1, #1
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	b _0817E906
	.align 2, 0
_0817E888: .4byte 0x085D3294
_0817E88C:
	cmp r6, #8
	bhi _0817E918
	cmp r5, #0
	beq _0817E918
	lsls r0, r3, #1
	adds r3, r0, r3
	lsls r0, r3, #2
	adds r2, r7, r0
	adds r0, r2, #0
	adds r0, #0x50
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1d
	cmp r0, #0
	beq _0817E918
	subs r1, r0, #1
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x54
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1e
	adds r1, r1, r0
	lsls r1, r1, #1
	lsls r0, r3, #4
	adds r1, r1, r0
	add r1, r8
	ldr r0, _0817E8D0
	add r0, ip
	ldr r0, [r0]
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	b _0817E916
	.align 2, 0
_0817E8D0: .4byte 0x085D3294
_0817E8D4:
	cmp r6, #8
	bls _0817E918
	cmp r5, #0
	beq _0817E918
	lsls r0, r3, #1
	adds r3, r0, r3
	lsls r0, r3, #2
	adds r2, r7, r0
	adds r0, r2, #0
	adds r0, #0x50
	ldrh r0, [r0]
	lsls r0, r0, #0x17
	lsrs r0, r0, #0x1d
	cmp r0, #0
	beq _0817E918
	subs r1, r0, #1
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x54
	ldrb r0, [r0]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1e
	adds r1, r1, r0
	lsls r1, r1, #1
	lsls r0, r3, #4
_0817E906:
	adds r1, r1, r0
	add r1, r8
	ldr r0, _0817E928
	add r0, ip
	ldr r0, [r0]
_0817E910:
	ldrh r0, [r0]
	ldrh r5, [r1]
	adds r0, r0, r5
_0817E916:
	strh r0, [r1]
_0817E918:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817E928: .4byte 0x085D3294
	thumb_func_end AddMovePoints
