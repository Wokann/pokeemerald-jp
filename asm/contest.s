.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_080DE114
sub_080DE114: @ 0x080DE114
	push {r4, lr}
	ldr r4, _080DE13C
	ldr r0, [r4]
	ldr r0, [r0, #0x18]
	movs r1, #0
	movs r2, #0x14
	bl memset
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5a
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DE136
	subs r0, #1
	strb r0, [r1]
_080DE136:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DE13C: .4byte 0x02039BD4
	thumb_func_end sub_080DE114

	thumb_func_start sub_080DE140
sub_080DE140: @ 0x080DE140
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r6, _080DE17C
	ldr r0, [r6]
	ldr r0, [r0, #0x18]
	strb r4, [r0, #5]
	ldr r5, _080DE180
	lsls r4, r4, #6
	adds r0, r4, r5
	ldrh r0, [r0]
	bl SanitizeSpecies
	ldr r2, [r6]
	ldr r1, [r2, #0x18]
	strh r0, [r1]
	ldr r1, [r2, #0x18]
	adds r0, r5, #0
	adds r0, #0x38
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [r1, #8]
	adds r5, #0x3c
	adds r4, r4, r5
	ldr r0, [r4]
	str r0, [r1, #0xc]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DE17C: .4byte 0x02039BD4
_080DE180: .4byte 0x02039AA0
	thumb_func_end sub_080DE140

	thumb_func_start sub_080DE184
sub_080DE184: @ 0x080DE184
	push {lr}
	ldr r0, _080DE1B0
	bl CreateInvisibleSpriteWithCallback
	ldr r1, _080DE1B4
	strb r0, [r1, #3]
	ldr r0, _080DE1B8
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080DE1BC
	adds r0, r0, r1
	bl InitSpriteAffineAnim
	bl sub_080DE1C0
	pop {r0}
	bx r0
	.align 2, 0
_080DE1B0: .4byte 0x08007141
_080DE1B4: .4byte 0x02023E88
_080DE1B8: .4byte 0x02023EB0
_080DE1BC: .4byte 0x020205AC
	thumb_func_end sub_080DE184

	thumb_func_start sub_080DE1C0
sub_080DE1C0: @ 0x080DE1C0
	push {r4, lr}
	ldr r0, _080DE204
	ldrb r0, [r0, #3]
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080DE208
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x26]
	movs r0, #3
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x20]
	movs r0, #3
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x22]
	adds r4, #0x3e
	ldrb r0, [r4]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DE204: .4byte 0x02023E88
_080DE208: .4byte 0x020205AC
	thumb_func_end sub_080DE1C0

	thumb_func_start SelectContestMoveBankTarget
SelectContestMoveBankTarget: @ 0x080DE20C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080DE22C
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r0, [r1, #6]
	cmp r0, #0x20
	bhi _080DE2C4
	lsls r0, r0, #2
	ldr r1, _080DE230
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DE22C: .4byte 0x082ED220
_080DE230: .4byte 0x080DE234
_080DE234: @ jump table
	.4byte _080DE2C4 @ case 0
	.4byte _080DE2C4 @ case 1
	.4byte _080DE2B8 @ case 2
	.4byte _080DE2C4 @ case 3
	.4byte _080DE2C4 @ case 4
	.4byte _080DE2C4 @ case 5
	.4byte _080DE2C4 @ case 6
	.4byte _080DE2C4 @ case 7
	.4byte _080DE2C4 @ case 8
	.4byte _080DE2C4 @ case 9
	.4byte _080DE2C4 @ case 10
	.4byte _080DE2C4 @ case 11
	.4byte _080DE2C4 @ case 12
	.4byte _080DE2C4 @ case 13
	.4byte _080DE2C4 @ case 14
	.4byte _080DE2C4 @ case 15
	.4byte _080DE2B8 @ case 16
	.4byte _080DE2C4 @ case 17
	.4byte _080DE2C4 @ case 18
	.4byte _080DE2C4 @ case 19
	.4byte _080DE2C4 @ case 20
	.4byte _080DE2C4 @ case 21
	.4byte _080DE2C4 @ case 22
	.4byte _080DE2C4 @ case 23
	.4byte _080DE2C4 @ case 24
	.4byte _080DE2C4 @ case 25
	.4byte _080DE2C4 @ case 26
	.4byte _080DE2C4 @ case 27
	.4byte _080DE2C4 @ case 28
	.4byte _080DE2C4 @ case 29
	.4byte _080DE2C4 @ case 30
	.4byte _080DE2C4 @ case 31
	.4byte _080DE2C4 @ case 32
_080DE2B8:
	ldr r1, _080DE2C0
	movs r0, #2
	b _080DE2C8
	.align 2, 0
_080DE2C0: .4byte 0x02023EB0
_080DE2C4:
	ldr r1, _080DE2D0
	movs r0, #3
_080DE2C8:
	strb r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080DE2D0: .4byte 0x02023EB0
	thumb_func_end SelectContestMoveBankTarget

	thumb_func_start Contest_PrintTextToBg0WindowStd
Contest_PrintTextToBg0WindowStd: @ 0x080DE2D4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	str r1, [sp]
	mov r0, sp
	movs r2, #0
	strb r4, [r0, #4]
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #5]
	mov r0, sp
	strb r2, [r0, #6]
	movs r1, #2
	strb r1, [r0, #7]
	strb r2, [r0, #8]
	strb r1, [r0, #9]
	strb r2, [r0, #0xa]
	strb r2, [r0, #0xb]
	mov r3, sp
	ldrb r2, [r3, #0xc]
	subs r1, #0x12
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r3, #0xc]
	mov r2, sp
	movs r0, #0xf0
	strb r0, [r2, #0xc]
	ldrb r0, [r2, #0xd]
	ands r1, r0
	strb r1, [r2, #0xd]
	mov r1, sp
	movs r0, #0x80
	strb r0, [r1, #0xd]
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl AddTextPrinter
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl PutWindowTilemap
	movs r0, #0
	bl Contest_SetBgCopyFlags
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end Contest_PrintTextToBg0WindowStd

	thumb_func_start Contest_StartTextPrinter
Contest_StartTextPrinter: @ 0x080DE338
	push {r4, r5, lr}
	sub sp, #0x10
	str r0, [sp]
	mov r2, sp
	movs r3, #0
	movs r0, #8
	strb r0, [r2, #4]
	mov r0, sp
	movs r5, #1
	strb r5, [r0, #5]
	strb r3, [r0, #6]
	movs r2, #2
	strb r2, [r0, #7]
	strb r3, [r0, #8]
	strb r2, [r0, #9]
	strb r3, [r0, #0xa]
	strb r3, [r0, #0xb]
	mov r4, sp
	ldrb r3, [r4, #0xc]
	subs r2, #0x12
	adds r0, r2, #0
	ands r0, r3
	strb r0, [r4, #0xc]
	mov r3, sp
	movs r0, #0x10
	strb r0, [r3, #0xc]
	ldrb r0, [r3, #0xd]
	ands r2, r0
	strb r2, [r3, #0xd]
	mov r2, sp
	movs r0, #0x80
	strb r0, [r2, #0xd]
	cmp r1, #0
	bne _080DE388
	mov r0, sp
	movs r1, #0
	movs r2, #0
	bl AddTextPrinter
	b _080DE3AC
_080DE388:
	ldr r0, _080DE398
	ldrb r1, [r0]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _080DE39C
	movs r1, #4
	b _080DE3A4
	.align 2, 0
_080DE398: .4byte 0x02039BCA
_080DE39C:
	bl GetPlayerTextSpeedDelay
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_080DE3A4:
	mov r0, sp
	movs r2, #0
	bl AddTextPrinter
_080DE3AC:
	movs r0, #8
	bl PutWindowTilemap
	movs r0, #0
	bl Contest_SetBgCopyFlags
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end Contest_StartTextPrinter

	thumb_func_start ContestBG_FillBoxWithIncrementingTile
ContestBG_FillBoxWithIncrementingTile: @ 0x080DE3C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	ldr r0, [sp, #0x28]
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	mov r7, r8
	lsls r7, r7, #0x18
	lsrs r7, r7, #0x18
	mov r8, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	str r0, [sp]
	str r4, [sp, #4]
	str r5, [sp, #8]
	lsls r6, r6, #0x10
	asrs r6, r6, #0x10
	str r6, [sp, #0xc]
	mov r0, r8
	bl WriteSequenceToBgTilemapBuffer
	mov r0, r8
	bl Contest_SetBgCopyFlags
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end ContestBG_FillBoxWithIncrementingTile

	thumb_func_start ContestBG_FillBoxWithTile
ContestBG_FillBoxWithTile: @ 0x080DE418
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r4, [sp, #0x20]
	ldr r5, [sp, #0x24]
	ldr r6, [sp, #0x28]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	str r4, [sp]
	str r5, [sp, #4]
	str r6, [sp, #8]
	movs r4, #0
	str r4, [sp, #0xc]
	bl ContestBG_FillBoxWithIncrementingTile
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end ContestBG_FillBoxWithTile

	thumb_func_start Contest_RunTextPrinters
Contest_RunTextPrinters: @ 0x080DE454
	push {lr}
	bl RunTextPrinters
	movs r0, #8
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	thumb_func_end Contest_RunTextPrinters

	thumb_func_start Contest_SetBgCopyFlags
Contest_SetBgCopyFlags: @ 0x080DE468
	ldr r2, _080DE478
	movs r1, #1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.align 2, 0
_080DE478: .4byte 0x02039BD8
	thumb_func_end Contest_SetBgCopyFlags

	thumb_func_start ResetContestLinkResults
ResetContestLinkResults: @ 0x080DE47C
	push {r4, r5, r6, lr}
	movs r0, #0
	ldr r6, _080DE4A8
	ldr r5, _080DE4AC
	movs r4, #0
_080DE486:
	adds r3, r0, #1
	lsls r1, r0, #3
	movs r2, #3
_080DE48C:
	ldr r0, [r6]
	adds r0, r0, r5
	adds r0, r0, r1
	strh r4, [r0]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _080DE48C
	adds r0, r3, #0
	cmp r0, #4
	ble _080DE486
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080DE4A8: .4byte 0x03005AF0
_080DE4AC: .4byte 0x00000624
	thumb_func_end ResetContestLinkResults

	thumb_func_start sub_080DE4B0
sub_080DE4B0: @ 0x080DE4B0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r5, #0
	ldr r1, _080DE500
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DE4EE
_080DE4E0:
	adds r5, #1
	cmp r5, #2
	bgt _080DE4EE
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DE4E0
_080DE4EE:
	ldr r0, [sp]
	cmp r0, #0xff
	bne _080DE508
	ldr r0, _080DE504
	ldrb r0, [r0]
	cmp r5, r0
	beq _080DE508
	movs r0, #0
	b _080DE698
	.align 2, 0
_080DE500: .4byte 0x02039BC0
_080DE504: .4byte 0x02039BC5
_080DE508:
	ldr r0, _080DE51C
	ldrh r0, [r0]
	cmp r0, #4
	bhi _080DE554
	lsls r0, r0, #2
	ldr r1, _080DE520
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DE51C: .4byte 0x02039BCC
_080DE520: .4byte 0x080DE524
_080DE524: @ jump table
	.4byte _080DE554 @ case 0
	.4byte _080DE538 @ case 1
	.4byte _080DE53E @ case 2
	.4byte _080DE544 @ case 3
	.4byte _080DE54A @ case 4
_080DE538:
	mov r0, r8
	adds r0, #3
	b _080DE54E
_080DE53E:
	mov r0, r8
	adds r0, #6
	b _080DE54E
_080DE544:
	mov r0, r8
	adds r0, #9
	b _080DE54E
_080DE54A:
	mov r0, r8
	adds r0, #0xc
_080DE54E:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_080DE554:
	ldr r1, [sp]
	cmp r1, #0xfe
	bne _080DE55C
	b _080DE658
_080DE55C:
	adds r0, r1, #0
	movs r1, #1
	bl sub_080DE6B0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r2, _080DE5E0
	mov sl, r2
	ldr r0, [r2]
	mov r3, sb
	lsls r7, r3, #5
	ldr r6, _080DE5E4
	adds r2, r0, r6
	adds r2, r2, r7
	ldr r4, _080DE5E8
	lsls r5, r5, #6
	adds r1, r4, #0
	adds r1, #0x38
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r2]
	adds r1, r0, r7
	adds r2, r5, r4
	ldrh r2, [r2]
	ldr r3, _080DE5EC
	adds r1, r1, r3
	strh r2, [r1]
	ldr r1, _080DE5F0
	adds r2, r0, r1
	adds r2, r2, r7
	adds r1, r4, #0
	adds r1, #0x3c
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r2]
	adds r6, r7, r6
	adds r0, r0, r6
	adds r0, #0xb
	adds r1, r4, #2
	adds r1, r5, r1
	bl StringCopy
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r6
	adds r0, #0x16
	adds r4, #0xd
	adds r5, r5, r4
	adds r1, r5, #0
	bl StringCopy
	ldr r0, _080DE5F4
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DE5FC
	mov r3, sl
	ldr r0, [r3]
	adds r0, r0, r7
	ldr r1, _080DE5F8
	adds r0, r0, r1
	movs r1, #4
	b _080DE60A
	.align 2, 0
_080DE5E0: .4byte 0x03005AEC
_080DE5E4: .4byte 0x00002E90
_080DE5E8: .4byte 0x02039AA0
_080DE5EC: .4byte 0x00002E98
_080DE5F0: .4byte 0x00002E94
_080DE5F4: .4byte 0x02039BCA
_080DE5F8: .4byte 0x00002EAE
_080DE5FC:
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r7
	ldr r1, _080DE628
	ldrh r1, [r1]
	ldr r3, _080DE62C
	adds r0, r0, r3
_080DE60A:
	strb r1, [r0]
	ldr r0, [sp]
	cmp r0, #0xff
	beq _080DE63C
	ldr r0, _080DE630
	ldr r0, [r0]
	mov r2, sb
	lsls r1, r2, #5
	adds r0, r0, r1
	ldr r1, _080DE634
	ldrh r1, [r1]
	ldr r3, _080DE638
	adds r0, r0, r3
	strb r1, [r0]
	b _080DE696
	.align 2, 0
_080DE628: .4byte 0x02039BCE
_080DE62C: .4byte 0x00002EAE
_080DE630: .4byte 0x03005AEC
_080DE634: .4byte 0x02039BCC
_080DE638: .4byte 0x00002E9A
_080DE63C:
	ldr r0, _080DE650
	ldr r0, [r0]
	mov r2, sb
	lsls r1, r2, #5
	adds r0, r0, r1
	ldr r3, _080DE654
	adds r0, r0, r3
	mov r1, r8
	strb r1, [r0]
	b _080DE696
	.align 2, 0
_080DE650: .4byte 0x03005AEC
_080DE654: .4byte 0x00002E9A
_080DE658:
	ldr r6, _080DE6A8
	ldr r4, _080DE6AC
	lsls r5, r5, #6
	adds r0, r4, #0
	adds r0, #0x38
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0x3c
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [r6, #4]
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r6, #8]
	adds r0, r6, #0
	adds r0, #0xb
	adds r1, r4, #2
	adds r1, r5, r1
	bl StringCopy
	adds r0, r6, #0
	adds r0, #0x16
	adds r4, #0xd
	adds r5, r5, r4
	adds r1, r5, #0
	bl StringCopy
	mov r2, r8
	strb r2, [r6, #0xa]
_080DE696:
	movs r0, #1
_080DE698:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DE6A8: .4byte 0x02039BDC
_080DE6AC: .4byte 0x02039AA0
	thumb_func_end sub_080DE4B0

	thumb_func_start sub_080DE6B0
sub_080DE6B0: @ 0x080DE6B0
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r0, #3
	bgt _080DE700
	cmp r0, #0
	blt _080DE700
	cmp r1, #0
	beq _080DE6EE
	movs r2, #5
	ldr r0, _080DE6F4
	mov ip, r0
	ldr r4, _080DE6F8
	ldr r3, _080DE6FC
_080DE6D0:
	mov r1, ip
	ldr r0, [r1]
	lsls r1, r2, #5
	adds r1, r1, r0
	adds r0, r1, r4
	adds r1, r1, r3
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6}
	stm r0!, {r5, r6}
	subs r2, #1
	cmp r2, #0
	bgt _080DE6D0
_080DE6EE:
	movs r0, #0
	b _080DE742
	.align 2, 0
_080DE6F4: .4byte 0x03005AEC
_080DE6F8: .4byte 0x00002E90
_080DE6FC: .4byte 0x00002E70
_080DE700:
	ldr r0, _080DE714
	ldrh r0, [r0]
	cmp r0, #4
	bhi _080DE740
	lsls r0, r0, #2
	ldr r1, _080DE718
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DE714: .4byte 0x02039BCC
_080DE718: .4byte 0x080DE71C
_080DE71C: @ jump table
	.4byte _080DE730 @ case 0
	.4byte _080DE734 @ case 1
	.4byte _080DE738 @ case 2
	.4byte _080DE73C @ case 3
	.4byte _080DE740 @ case 4
_080DE730:
	movs r0, #8
	b _080DE742
_080DE734:
	movs r0, #9
	b _080DE742
_080DE738:
	movs r0, #0xa
	b _080DE742
_080DE73C:
	movs r0, #0xb
	b _080DE742
_080DE740:
	movs r0, #0xc
_080DE742:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_080DE6B0

	thumb_func_start ClearContestWinnerPicsInContestHall
ClearContestWinnerPicsInContestHall: @ 0x080DE748
	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r0, _080DE77C
	mov ip, r0
	ldr r4, _080DE780
	ldr r3, _080DE784
_080DE754:
	mov r1, ip
	ldr r0, [r1]
	lsls r1, r2, #5
	adds r0, r0, r1
	adds r0, r0, r4
	adds r1, r3, #0
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6}
	stm r0!, {r5, r6}
	adds r3, #0x20
	adds r2, #1
	cmp r2, #7
	ble _080DE754
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DE77C: .4byte 0x03005AEC
_080DE780: .4byte 0x00002E90
_080DE784: .4byte 0x08560F28
	thumb_func_end ClearContestWinnerPicsInContestHall

	thumb_func_start sub_080DE788
sub_080DE788: @ 0x080DE788
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, _080DE8C0
	ldr r3, [r2]
	ldr r5, [r3, #0x10]
	ldrb r1, [r5, #1]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	adds r6, r2, #0
	cmp r0, #0
	bne _080DE7DA
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	ble _080DE7DA
	ldr r1, [r3, #4]
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0x15]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	bne _080DE7DA
	ldr r1, [r3, #0x1c]
	lsls r2, r4, #4
	adds r1, r2, r1
	ldrb r3, [r1, #0xc]
	movs r0, #1
	orrs r0, r3
	strb r0, [r1, #0xc]
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	adds r2, r2, r0
	ldrb r0, [r2, #0xe]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0xe]
_080DE7DA:
	ldr r3, [r6]
	ldr r1, [r3, #4]
	lsls r2, r4, #3
	subs r0, r2, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0xc]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	adds r7, r2, #0
	cmp r0, #0
	beq _080DE802
	ldr r0, [r3, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #2
	orrs r0, r2
	strb r0, [r1, #0xc]
_080DE802:
	ldr r3, [r6]
	ldr r2, [r3, #0x10]
	ldrb r1, [r2, #1]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080DE82E
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	beq _080DE82E
	movs r0, #2
	ldrsb r0, [r2, r0]
	cmp r0, #0x3c
	bne _080DE82E
	ldr r0, [r3, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #4
	orrs r0, r2
	strb r0, [r1, #0xc]
_080DE82E:
	ldr r3, [r6]
	ldr r1, [r3, #4]
	subs r0, r7, r4
	lsls r0, r0, #2
	adds r2, r0, r1
	ldrb r1, [r2, #0x15]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080DE856
	ldrb r0, [r2, #0x16]
	cmp r0, #0
	beq _080DE856
	ldr r0, [r3, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #8
	orrs r0, r2
	strb r0, [r1, #0xc]
_080DE856:
	movs r3, #0
	movs r5, #0
_080DE85A:
	cmp r3, r4
	beq _080DE888
	ldr r1, [r6]
	ldr r0, [r1, #4]
	adds r0, r5, r0
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _080DE888
	ldr r0, [r1, #0x1c]
	lsls r2, r4, #4
	adds r2, r2, r0
	ldrb r0, [r2, #0xc]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	lsls r2, r3, #4
	adds r2, r2, r0
	ldrb r0, [r2, #0xc]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #0xc]
_080DE888:
	adds r5, #0x1c
	adds r3, #1
	cmp r3, #3
	ble _080DE85A
	ldr r2, [r6]
	ldr r1, [r2, #4]
	subs r0, r7, r4
	lsls r5, r0, #2
	adds r1, r5, r1
	ldrb r3, [r1, #0xc]
	movs r0, #6
	ands r0, r3
	cmp r0, #0
	bne _080DE8AE
	ldrb r1, [r1, #0xb]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080DE8C4
_080DE8AE:
	ldr r0, [r2, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xc]
	movs r0, #0x20
	orrs r0, r2
	strb r0, [r1, #0xc]
	b _080DE8FE
	.align 2, 0
_080DE8C0: .4byte 0x02039BD4
_080DE8C4:
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	bne _080DE8FE
	ldr r2, [r2, #0x1c]
	lsls r3, r4, #4
	adds r2, r3, r2
	ldrb r0, [r2, #0xc]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0xc]
	ldr r0, [r6]
	ldr r1, [r0, #0x1c]
	adds r1, r3, r1
	ldrb r0, [r1, #0xe]
	movs r2, #1
	orrs r0, r2
	strb r0, [r1, #0xe]
	ldr r1, [r6]
	ldr r0, [r1, #0x1c]
	adds r3, r3, r0
	ldr r0, [r1]
	ldrb r0, [r0, #1]
	lsls r0, r0, #1
	adds r3, r3, r0
	ldr r0, [r1, #4]
	adds r0, r5, r0
	ldrh r0, [r0, #6]
	strh r0, [r3]
_080DE8FE:
	ldr r2, [r6]
	ldr r1, [r2, #4]
	subs r0, r7, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0x15]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _080DE922
	ldr r0, [r2, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xd]
	movs r0, #2
	orrs r0, r2
	strb r0, [r1, #0xd]
_080DE922:
	ldr r2, [r6]
	ldr r0, [r2]
	ldrb r0, [r0, #0x13]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #4
	bne _080DE952
	ldr r3, [r2, #0x10]
	ldrb r1, [r3, #1]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _080DE952
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	beq _080DE952
	ldr r0, [r2, #0x1c]
	lsls r1, r4, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xd]
	movs r0, #0x20
	orrs r0, r2
	strb r0, [r1, #0xd]
_080DE952:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_080DE788

	thumb_func_start sub_080DE958
sub_080DE958: @ 0x080DE958
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	movs r1, #0
	movs r0, #0
	str r0, [sp, #0x20]
	movs r4, #0
	ldr r6, _080DE998
	mov r2, sp
	adds r2, #0xc
	str r2, [sp, #0x28]
	mov r3, sp
	adds r3, #0x14
	str r3, [sp, #0x2c]
	mov r7, sp
	adds r7, #2
	str r7, [sp, #0x24]
	ldr r5, _080DE99C
	movs r2, #0
	movs r3, #0x80
	lsls r3, r3, #0x11
_080DE988:
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DE9A0
	lsrs r0, r2, #0x18
	str r0, [sp, #0x20]
	b _080DE9A6
	.align 2, 0
_080DE998: .4byte 0x02039BD4
_080DE99C: .4byte 0x02039BC0
_080DE9A0:
	cmp r0, #3
	bne _080DE9A6
	lsrs r1, r2, #0x18
_080DE9A6:
	adds r2, r2, r3
	adds r4, #1
	cmp r4, #3
	ble _080DE988
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r2, [r1, #0xd]
	movs r0, #1
	orrs r0, r2
	strb r0, [r1, #0xd]
	movs r4, #0
	ldr r1, [sp, #0x20]
	lsls r1, r1, #4
	str r1, [sp, #0x30]
	mov sb, r4
	mov sl, r4
_080DE9CA:
	ldr r2, [sp, #0x20]
	cmp r4, r2
	beq _080DE9F6
	ldr r1, _080DEB94
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	add r1, sl
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r2, r2, r0
	cmp r2, #0x32
	bgt _080DE9F6
	ldr r7, _080DEB98
	ldr r0, [r7]
	ldr r2, [r0, #0x1c]
	add r2, sb
	ldrb r0, [r2, #0xd]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DE9F6:
	ldr r1, _080DEB98
	ldr r0, [r1]
	ldr r0, [r0, #0x1c]
	mov r3, sb
	adds r2, r3, r0
	ldrb r1, [r2, #0xe]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080DEA12
	ldrb r0, [r2, #0xd]
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEA12:
	movs r5, #0
	ldr r2, _080DEB9C
	add r2, sl
	movs r6, #0
	ldrsh r1, [r2, r6]
	ldr r7, _080DEB9C
	movs r3, #0
	ldrsh r0, [r7, r3]
	cmp r1, r0
	blt _080DEA3E
	adds r3, r2, #0
	adds r2, r7, #0
_080DEA2A:
	adds r2, #2
	adds r5, #1
	cmp r5, #3
	bgt _080DEA3E
	movs r6, #0
	ldrsh r1, [r3, r6]
	movs r7, #0
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _080DEA2A
_080DEA3E:
	cmp r5, #4
	bne _080DEA5C
	ldr r1, _080DEBA0
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DEA5C
	ldr r2, _080DEB98
	ldr r0, [r2]
	ldr r2, [r0, #0x1c]
	add r2, sb
	ldrb r0, [r2, #0xd]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEA5C:
	movs r3, #0
	mov ip, r3
	mov r8, r3
	movs r5, #0
	ldr r0, _080DEB9C
	add r0, sl
	movs r7, #0
	ldrsh r6, [r0, r7]
	str r6, [sp, #0x34]
	ldr r2, _080DEB9C
	ldr r0, _080DEBA4
	mov r1, sl
	adds r6, r1, r0
	adds r3, r0, #0
_080DEA78:
	movs r7, #0
	ldrsh r0, [r2, r7]
	ldr r1, [sp, #0x34]
	cmp r1, r0
	ble _080DEA86
	movs r7, #1
	mov ip, r7
_080DEA86:
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	ble _080DEA96
	movs r0, #1
	mov r8, r0
_080DEA96:
	adds r2, #2
	adds r3, #2
	adds r5, #1
	cmp r5, #3
	ble _080DEA78
	mov r1, ip
	cmp r1, #0
	bne _080DEABC
	mov r2, r8
	cmp r2, #0
	bne _080DEABC
	ldr r3, _080DEB98
	ldr r0, [r3]
	ldr r2, [r0, #0x1c]
	add r2, sb
	ldrb r0, [r2, #0xd]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEABC:
	ldr r6, _080DEB98
	ldr r0, [r6]
	ldr r0, [r0, #0x1c]
	mov r7, sb
	adds r2, r7, r0
	ldrb r1, [r2, #0xe]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080DEAD8
	ldrb r0, [r2, #0xd]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #0xd]
_080DEAD8:
	movs r0, #0x10
	add sb, r0
	movs r1, #2
	add sl, r1
	adds r4, #1
	cmp r4, #3
	bgt _080DEAE8
	b _080DE9CA
_080DEAE8:
	movs r4, #0
	movs r5, #0
	movs r3, #0
	ldr r2, [sp, #0x28]
	mov r1, sp
_080DEAF2:
	strh r3, [r1]
	adds r0, r2, r4
	strb r5, [r0]
	adds r1, #2
	adds r4, #1
	cmp r4, #4
	ble _080DEAF2
	mov r1, sp
	ldr r0, _080DEBA8
	strh r0, [r1, #0xa]
	movs r0, #0
	ldr r2, [sp, #0x28]
	strb r0, [r2, #5]
	movs r4, #0
	ldr r0, _080DEB98
	ldr r0, [r0]
	mov r8, r0
	ldr r7, [sp, #0x30]
_080DEB16:
	mov r3, r8
	ldr r0, [r3, #0x1c]
	adds r0, r7, r0
	lsls r1, r4, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, #1
	mov ip, r4
	cmp r0, #0
	beq _080DEB58
	ldr r0, _080DEB98
	ldr r6, [r0]
	ldr r3, [sp, #0x28]
	mov r4, sp
	movs r5, #4
_080DEB34:
	ldr r0, [r6, #0x1c]
	adds r0, r7, r0
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	beq _080DEB48
	cmp r2, #0
	bne _080DEB4E
	strh r0, [r4]
_080DEB48:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_080DEB4E:
	adds r3, #1
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _080DEB34
_080DEB58:
	mov r4, ip
	cmp r4, #4
	ble _080DEB16
	mov r0, sp
	ldrh r0, [r0]
	ldr r6, [sp, #0x2c]
	strh r0, [r6]
	ldr r7, [sp, #0x28]
	ldrb r3, [r7]
	movs r6, #0
	movs r4, #1
	ldr r1, [sp, #0x24]
	ldrh r0, [r1]
	ldr r1, _080DEBA8
	cmp r0, r1
	beq _080DEBC8
	ldr r5, [sp, #0x2c]
	adds r7, r1, #0
	mov r2, sp
	adds r2, #2
_080DEB80:
	ldr r0, [sp, #0x28]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r3, r0
	bhs _080DEBAC
	ldrh r0, [r2]
	strh r0, [r5]
	ldrb r3, [r1]
	movs r6, #1
	b _080DEBBE
	.align 2, 0
_080DEB94: .4byte 0x02039BA8
_080DEB98: .4byte 0x02039BD4
_080DEB9C: .4byte 0x02039BA0
_080DEBA0: .4byte 0x02039BC0
_080DEBA4: .4byte 0x02039BB8
_080DEBA8: .4byte 0x0000FFFF
_080DEBAC:
	cmp r3, r0
	bne _080DEBBE
	lsls r0, r6, #1
	adds r0, r5, r0
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_080DEBBE:
	adds r2, #2
	adds r4, #1
	ldrh r0, [r2]
	cmp r0, r7
	bne _080DEB80
_080DEBC8:
	bl Random
	ldr r1, _080DEBFC
	ldr r1, [r1]
	ldr r4, [r1, #0x1c]
	ldr r1, [sp, #0x30]
	adds r4, r1, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl __modsi3
	lsls r0, r0, #1
	ldr r2, [sp, #0x2c]
	adds r0, r2, r0
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DEBFC: .4byte 0x02039BD4
	thumb_func_end sub_080DE958

	thumb_func_start sub_080DEC00
sub_080DEC00: @ 0x080DEC00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r2, _080DED34
	ldr r0, _080DED38
	ldrb r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080DEC1C
	b _080DEDCC
_080DEC1C:
	movs r1, #0
	movs r3, #0
	ldr r0, _080DED3C
	mov sb, r0
_080DEC24:
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DEC30
	lsls r0, r3, #0x18
	lsrs r1, r0, #0x18
_080DEC30:
	adds r3, #1
	cmp r3, #3
	ble _080DEC24
	movs r2, #0
	mov sl, r2
	movs r4, #0
	str r4, [sp, #4]
	movs r3, #0
	lsls r2, r1, #1
	lsls r1, r1, #4
	mov r8, r1
	ldr r1, _080DED40
	adds r0, r2, r1
	movs r7, #0
	ldrsh r6, [r0, r7]
	adds r5, r1, #0
	ldr r0, _080DED44
	adds r2, r2, r0
	adds r4, r0, #0
_080DEC56:
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r6, r0
	bge _080DEC68
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
_080DEC68:
	movs r7, #0
	ldrsh r1, [r2, r7]
	movs r7, #0
	ldrsh r0, [r4, r7]
	cmp r1, r0
	bge _080DEC7E
	ldr r0, [sp, #4]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
_080DEC7E:
	adds r5, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #3
	ble _080DEC56
	mov r1, sb
	ldr r0, [r1]
	ldr r0, [r0, #0x1c]
	add r0, r8
	ldrb r1, [r0, #0xc]
	movs r4, #0
	movs r2, #1
	movs r3, #7
_080DEC98:
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080DECA6
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080DECA6:
	lsrs r1, r1, #1
	subs r3, #1
	cmp r3, #0
	bge _080DEC98
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _080DED3C
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	add r0, r8
	ldrb r1, [r0, #0xc]
	movs r4, #0
	movs r2, #0
	movs r3, #0
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DECE2
	cmp r5, #0
	beq _080DECFC
_080DECDC:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_080DECE2:
	lsrs r1, r1, #1
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, #1
	cmp r3, #7
	bgt _080DECFC
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080DECE2
	cmp r5, r4
	bne _080DECDC
_080DECFC:
	movs r0, #0x80
	lsls r0, r0, #9
	lsls r0, r2
	lsrs r0, r0, #0x10
	mov sb, r0
	mov r1, sp
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080DED3C
	ldr r1, [r0]
	ldr r0, [r1, #0x1c]
	ldrb r4, [r0, #0xd]
	movs r5, #1
	movs r3, #1
	mov r6, sp
_080DED1A:
	ldr r0, [r1, #0x1c]
	lsls r2, r3, #4
	adds r0, r2, r0
	ldrb r0, [r0, #0xd]
	cmp r4, r0
	bhs _080DED48
	strb r3, [r6]
	ldr r0, [r1, #0x1c]
	adds r0, r2, r0
	ldrb r4, [r0, #0xd]
	movs r5, #1
	b _080DED58
	.align 2, 0
_080DED34: .4byte 0x02039BC0
_080DED38: .4byte 0x02039BC5
_080DED3C: .4byte 0x02039BD4
_080DED40: .4byte 0x02039BA0
_080DED44: .4byte 0x02039BB8
_080DED48:
	cmp r4, r0
	bne _080DED58
	mov r2, sp
	adds r0, r2, r5
	strb r3, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080DED58:
	adds r3, #1
	cmp r3, #3
	ble _080DED1A
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl __modsi3
	add r0, sp
	ldrb r7, [r0]
	movs r2, #0x80
	movs r3, #0
	ldr r5, _080DEDDC
	ldr r0, [r5]
	ldr r0, [r0, #0x1c]
	lsls r1, r7, #4
	adds r0, r1, r0
	ldrb r0, [r0, #0xd]
	ands r0, r2
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r0, sb
	lsls r6, r0, #0x18
	cmp r4, #0
	bne _080DEDA4
_080DED8E:
	lsrs r2, r2, #1
	adds r3, #1
	cmp r3, #7
	bgt _080DEDA4
	ldr r0, [r5]
	ldr r0, [r0, #0x1c]
	adds r0, r1, r0
	ldrb r4, [r0, #0xd]
	ands r4, r2
	cmp r4, #0
	beq _080DED8E
_080DEDA4:
	mov r0, sl
	bl ContestLiveUpdates_BeforeInterview_1
	ldr r0, [sp, #4]
	bl ContestLiveUpdates_BeforeInterview_2
	lsrs r0, r6, #0x18
	bl ContestLiveUpdates_BeforeInterview_3
	ldr r0, _080DEDDC
	ldr r0, [r0]
	ldr r0, [r0, #0x1c]
	add r0, r8
	ldrh r0, [r0, #0xa]
	bl ContestLiveUpdates_BeforeInterview_4
	adds r0, r4, #0
	adds r1, r7, #0
	bl ContestLiveUpdates_BeforeInterview_5
_080DEDCC:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DEDDC: .4byte 0x02039BD4
	thumb_func_end sub_080DEC00

	thumb_func_start ContestDebugToggleBitfields
ContestDebugToggleBitfields: @ 0x080DEDE0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r0, _080DEE00
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r4, r0, #0
	cmp r1, #0
	bne _080DEE08
	cmp r3, #0
	bne _080DEE04
	movs r0, #2
	b _080DEE0A
	.align 2, 0
_080DEE00: .4byte 0x02000000
_080DEE04:
	movs r0, #3
	b _080DEE0A
_080DEE08:
	movs r0, #0
_080DEE0A:
	strb r0, [r2]
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DEE22
	bl DrawContestantWindowText
	bl SwapMoveDescAndContestTilemaps
	b _080DEE26
_080DEE22:
	bl ContestDebugPrintBitStrings
_080DEE26:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end ContestDebugToggleBitfields

	thumb_func_start ContestDebugPrintBitStrings
ContestDebugPrintBitStrings: @ 0x080DEE2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	ldr r0, _080DEF28
	ldrb r0, [r0]
	cmp r0, #0
	bne _080DEE42
	b _080DEFD4
_080DEE42:
	ldr r0, _080DEF2C
	movs r1, #0xd0
	lsls r1, r1, #9
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080DEE58
	b _080DEFD4
_080DEE58:
	movs r7, #0
	add r2, sp, #0x14
	mov sl, r2
_080DEE5E:
	adds r0, r7, #0
	movs r1, #0
	bl FillWindowPixelBuffer
	adds r0, r7, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl FillWindowPixelBuffer
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080DEE5E
	ldr r0, _080DEF2C
	movs r4, #0xd0
	lsls r4, r4, #9
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #2
	bne _080DEF3C
	movs r7, #0
	mov sb, sl
_080DEE8E:
	mov r0, sp
	ldr r1, _080DEF30
	bl StringCopy
	adds r6, r0, #0
	ldr r0, _080DEF34
	adds r0, r7, r0
	ldrb r0, [r0]
	mov r1, sp
	bl Contest_PrintTextToBg0WindowStd
	ldr r0, _080DEF38
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	lsls r0, r7, #4
	adds r0, r0, r1
	ldrb r5, [r0, #0xc]
	movs r4, #7
	adds r0, r7, #1
	mov r8, r0
_080DEEB6:
	movs r1, #1
	ands r1, r5
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	adds r6, r0, #0
	lsrs r5, r5, #1
	lsls r0, r4, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, r2
	bgt _080DEEB6
	movs r4, #0
	ldr r6, _080DEF34
	mov r3, sl
_080DEEE2:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	adds r2, r3, r0
	mov r4, sp
	adds r1, r4, r0
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #4
	ble _080DEEE2
	mov r0, sb
	adds r1, r0, r5
	movs r0, #0xff
	strb r0, [r1]
	adds r4, r7, r6
	ldrb r0, [r4]
	mov r1, sb
	bl Contest_PrintTextToBg0WindowStd
	ldrb r0, [r4]
	adds r0, #4
	mov r2, sp
	adds r1, r2, r5
	bl Contest_PrintTextToBg0WindowStd
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080DEE8E
	b _080DEFD0
	.align 2, 0
_080DEF28: .4byte 0x02031F75
_080DEF2C: .4byte 0x02000000
_080DEF30: .4byte 0x085CC49D
_080DEF34: .4byte 0x02039BC6
_080DEF38: .4byte 0x02039BD4
_080DEF3C:
	movs r7, #0
	mov r0, sp
	adds r0, #2
	str r0, [sp, #0x28]
	mov sb, sl
_080DEF46:
	mov r0, sp
	ldr r1, _080DEFE4
	bl StringCopy
	ldr r0, _080DEFE8
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	lsls r0, r7, #4
	adds r0, r0, r1
	ldrb r5, [r0, #0xd]
	ldr r6, [sp, #0x28]
	movs r4, #7
	adds r1, r7, #1
	mov r8, r1
_080DEF62:
	movs r1, #1
	ands r1, r5
	adds r0, r6, #0
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	adds r6, r0, #0
	lsrs r5, r5, #1
	lsls r0, r4, #0x18
	movs r2, #0xff
	lsls r2, r2, #0x18
	adds r0, r0, r2
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _080DEF62
	movs r4, #0
	ldr r6, _080DEFEC
	mov r3, sl
_080DEF8E:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	adds r2, r3, r0
	mov r4, sp
	adds r1, r4, r0
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	asrs r5, r0, #0x18
	cmp r5, #4
	ble _080DEF8E
	mov r0, sb
	adds r1, r0, r5
	movs r0, #0xff
	strb r0, [r1]
	adds r4, r7, r6
	ldrb r0, [r4]
	mov r1, sb
	bl Contest_PrintTextToBg0WindowStd
	ldrb r0, [r4]
	adds r0, #4
	mov r2, sp
	adds r1, r2, r5
	bl Contest_PrintTextToBg0WindowStd
	mov r4, r8
	lsls r0, r4, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080DEF46
_080DEFD0:
	bl SwapMoveDescAndContestTilemaps
_080DEFD4:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DEFE4: .4byte 0x085CC4A0
_080DEFE8: .4byte 0x02039BD4
_080DEFEC: .4byte 0x02039BC6
	thumb_func_end ContestDebugPrintBitStrings

