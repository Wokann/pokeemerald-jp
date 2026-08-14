.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_0811D088
sub_0811D088: @ 0x0811D088
	push {r4, lr}
	ldr r4, _0811D0A0
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, #1
	beq _0811D0BC
	cmp r0, #1
	bgt _0811D0A4
	cmp r0, #0
	beq _0811D0AA
	b _0811D0DC
	.align 2, 0
_0811D0A0: .4byte 0x02039DE8
_0811D0A4:
	cmp r0, #2
	beq _0811D0D4
	b _0811D0DC
_0811D0AA:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #4
	bl sub_0811E5C0
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0811D0BC:
	bl sub_0811E624
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D0DC
	bl sub_0811ED98
	ldr r0, _0811D0D8
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0811D0D4:
	movs r0, #0
	b _0811D0DE
	.align 2, 0
_0811D0D8: .4byte 0x02039DE8
_0811D0DC:
	movs r0, #1
_0811D0DE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0811D088

	thumb_func_start sub_0811D0E4
sub_0811D0E4: @ 0x0811D0E4
	push {lr}
	ldr r0, _0811D0FC
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #5
	bhi _0811D19C
	lsls r0, r0, #2
	ldr r1, _0811D100
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0811D0FC: .4byte 0x02039DE8
_0811D100: .4byte 0x0811D104
_0811D104: @ jump table
	.4byte _0811D11C @ case 0
	.4byte _0811D12A @ case 1
	.4byte _0811D13A @ case 2
	.4byte _0811D14C @ case 3
	.4byte _0811D16C @ case 4
	.4byte _0811D192 @ case 5
_0811D11C:
	bl sub_0811E814
	bl sub_0811EBF8
	bl sub_0811EDFC
	b _0811D15C
_0811D12A:
	bl sub_0811EC1C
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D19C
	bl sub_0811E1C8
	b _0811D15C
_0811D13A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D19C
	movs r0, #2
	bl sub_0811E1E0
	b _0811D15C
_0811D14C:
	bl sub_0811E2B8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D19C
	movs r0, #2
	bl sub_0811DEA0
_0811D15C:
	ldr r0, _0811D168
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D19C
	.align 2, 0
_0811D168: .4byte 0x02039DE8
_0811D16C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D19C
	bl sub_0811E9D0
	movs r0, #1
	bl sub_0811EE2C
	bl sub_0811ED98
	bl sub_0811EEE0
	ldr r0, _0811D198
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0811D192:
	movs r0, #0
	b _0811D19E
	.align 2, 0
_0811D198: .4byte 0x02039DE8
_0811D19C:
	movs r0, #1
_0811D19E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D0E4

	thumb_func_start sub_0811D1A4
sub_0811D1A4: @ 0x0811D1A4
	push {lr}
	ldr r0, _0811D1BC
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #5
	bhi _0811D248
	lsls r0, r0, #2
	ldr r1, _0811D1C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0811D1BC: .4byte 0x02039DE8
_0811D1C0: .4byte 0x0811D1C4
_0811D1C4: @ jump table
	.4byte _0811D1DC @ case 0
	.4byte _0811D1E2 @ case 1
	.4byte _0811D1F4 @ case 2
	.4byte _0811D206 @ case 3
	.4byte _0811D228 @ case 4
	.4byte _0811D240 @ case 5
_0811D1DC:
	bl sub_0811DBA8
	b _0811D216
_0811D1E2:
	bl sub_0811EACC
	bl sub_0811EDFC
	bl sub_0811EF44
	bl sub_0811E1C8
	b _0811D216
_0811D1F4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D248
	movs r0, #3
	bl sub_0811E1E0
	b _0811D216
_0811D206:
	bl sub_0811E2B8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D248
	movs r0, #0
	bl ShowBg
_0811D216:
	ldr r0, _0811D224
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D248
	.align 2, 0
_0811D224: .4byte 0x02039DE8
_0811D228:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D248
	bl sub_0811E7C0
	ldr r0, _0811D244
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0811D240:
	movs r0, #0
	b _0811D24A
	.align 2, 0
_0811D244: .4byte 0x02039DE8
_0811D248:
	movs r0, #1
_0811D24A:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D1A4

	thumb_func_start sub_0811D250
sub_0811D250: @ 0x0811D250
	push {lr}
	ldr r0, _0811D268
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #6
	bhi _0811D308
	lsls r0, r0, #2
	ldr r1, _0811D26C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0811D268: .4byte 0x02039DE8
_0811D26C: .4byte 0x0811D270
_0811D270: @ jump table
	.4byte _0811D28C @ case 0
	.4byte _0811D292 @ case 1
	.4byte _0811D2A4 @ case 2
	.4byte _0811D2B6 @ case 3
	.4byte _0811D2C8 @ case 4
	.4byte _0811D2E8 @ case 5
	.4byte _0811D300 @ case 6
_0811D28C:
	bl sub_0811DBA8
	b _0811D2D8
_0811D292:
	bl sub_0811EACC
	bl sub_0811EDFC
	bl sub_0811EF44
	bl sub_0811E1C8
	b _0811D2D8
_0811D2A4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D308
	movs r0, #3
	bl sub_0811E1E0
	b _0811D2D8
_0811D2B6:
	bl sub_0811E2B8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D308
	movs r0, #3
	bl sub_0811D9D8
	b _0811D2D8
_0811D2C8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D308
	movs r0, #0
	bl ShowBg
_0811D2D8:
	ldr r0, _0811D2E4
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D308
	.align 2, 0
_0811D2E4: .4byte 0x02039DE8
_0811D2E8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D308
	bl sub_0811E7C0
	ldr r0, _0811D304
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0811D300:
	movs r0, #0
	b _0811D30A
	.align 2, 0
_0811D304: .4byte 0x02039DE8
_0811D308:
	movs r0, #1
_0811D30A:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D250

	thumb_func_start sub_0811D310
sub_0811D310: @ 0x0811D310
	push {lr}
	ldr r0, _0811D328
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #4
	bhi _0811D3C4
	lsls r0, r0, #2
	ldr r1, _0811D32C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0811D328: .4byte 0x02039DE8
_0811D32C: .4byte 0x0811D330
_0811D330: @ jump table
	.4byte _0811D344 @ case 0
	.4byte _0811D356 @ case 1
	.4byte _0811D368 @ case 2
	.4byte _0811D378 @ case 3
	.4byte _0811D398 @ case 4
_0811D344:
	bl sub_0811EACC
	bl sub_0811EDFC
	bl sub_0811EF44
	bl sub_0811E1C8
	b _0811D386
_0811D356:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D3C4
	movs r0, #4
	bl sub_0811E1E0
	b _0811D386
_0811D368:
	bl sub_0811E2B8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D3C4
	bl sub_0811DEDC
	b _0811D386
_0811D378:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D3C4
	bl sub_0811EAF8
_0811D386:
	ldr r0, _0811D394
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D3C4
	.align 2, 0
_0811D394: .4byte 0x02039DE8
_0811D398:
	bl sub_0811EB64
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D3C4
	bl sub_0811E7D8
	movs r0, #0
	bl sub_0811EE2C
	bl sub_0811ED98
	ldr r0, _0811D3C0
	ldr r1, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r0, #0
	b _0811D3C6
	.align 2, 0
_0811D3C0: .4byte 0x02039DE8
_0811D3C4:
	movs r0, #1
_0811D3C6:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D310

	thumb_func_start sub_0811D3CC
sub_0811D3CC: @ 0x0811D3CC
	push {lr}
	bl sub_0811EA54
	movs r0, #0
	pop {r1}
	bx r1
	thumb_func_end sub_0811D3CC

	thumb_func_start sub_0811D3D8
sub_0811D3D8: @ 0x0811D3D8
	push {r4, lr}
	ldr r4, _0811D3F0
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, #1
	beq _0811D404
	cmp r0, #1
	bgt _0811D3F4
	cmp r0, #0
	beq _0811D3FE
	b _0811D442
	.align 2, 0
_0811D3F0: .4byte 0x02039DE8
_0811D3F4:
	cmp r0, #2
	beq _0811D420
	cmp r0, #3
	beq _0811D43E
	b _0811D442
_0811D3FE:
	bl sub_0811DFBC
	b _0811D416
_0811D404:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D442
	movs r0, #1
	movs r1, #4
	bl sub_0811E5C0
_0811D416:
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D442
_0811D420:
	bl sub_0811E624
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D442
	bl sub_0811EA54
	bl sub_0811ED98
	bl sub_0811EEE0
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0811D43E:
	movs r0, #0
	b _0811D444
_0811D442:
	movs r0, #1
_0811D444:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D3D8

	thumb_func_start sub_0811D44C
sub_0811D44C: @ 0x0811D44C
	push {r4, lr}
	ldr r4, _0811D464
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, #1
	beq _0811D478
	cmp r0, #1
	bgt _0811D468
	cmp r0, #0
	beq _0811D472
	b _0811D4B4
	.align 2, 0
_0811D464: .4byte 0x02039DE8
_0811D468:
	cmp r0, #2
	beq _0811D496
	cmp r0, #3
	beq _0811D4B0
	b _0811D4B4
_0811D472:
	bl sub_0811DFE0
	b _0811D48C
_0811D478:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D4B4
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #4
	bl sub_0811E5C0
_0811D48C:
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D4B4
_0811D496:
	bl sub_0811E624
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D4B4
	bl sub_0811ED98
	bl sub_0811EEE0
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0811D4B0:
	movs r0, #0
	b _0811D4B6
_0811D4B4:
	movs r0, #1
_0811D4B6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0811D44C

	thumb_func_start sub_0811D4BC
sub_0811D4BC: @ 0x0811D4BC
	push {r4, r5, lr}
	ldr r5, _0811D4D4
	ldr r0, [r5]
	ldrh r0, [r0]
	cmp r0, #1
	beq _0811D4E8
	cmp r0, #1
	bgt _0811D4D8
	cmp r0, #0
	beq _0811D4E2
	b _0811D53A
	.align 2, 0
_0811D4D4: .4byte 0x02039DE8
_0811D4D8:
	cmp r0, #2
	beq _0811D518
	cmp r0, #3
	beq _0811D536
	b _0811D53A
_0811D4E2:
	bl sub_0811E004
	b _0811D50E
_0811D4E8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D53A
	bl sub_0811C3E0
	adds r4, r0, #0
	bl sub_0811E65C
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	subs r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #8
	bl sub_0811E5C0
_0811D50E:
	ldr r1, [r5]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D53A
_0811D518:
	bl sub_0811E624
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D53A
	bl sub_0811EA54
	bl sub_0811ED98
	bl sub_0811EEE0
	ldr r1, [r5]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0811D536:
	movs r0, #0
	b _0811D53C
_0811D53A:
	movs r0, #1
_0811D53C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D4BC

	thumb_func_start sub_0811D544
sub_0811D544: @ 0x0811D544
	push {r4, r5, lr}
	ldr r5, _0811D55C
	ldr r0, [r5]
	ldrh r0, [r0]
	cmp r0, #1
	beq _0811D570
	cmp r0, #1
	bgt _0811D560
	cmp r0, #0
	beq _0811D56A
	b _0811D5BE
	.align 2, 0
_0811D55C: .4byte 0x02039DE8
_0811D560:
	cmp r0, #2
	beq _0811D5A0
	cmp r0, #3
	beq _0811D5BA
	b _0811D5BE
_0811D56A:
	bl sub_0811E048
	b _0811D596
_0811D570:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D5BE
	bl sub_0811C3E0
	adds r4, r0, #0
	bl sub_0811E65C
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	subs r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #8
	bl sub_0811E5C0
_0811D596:
	ldr r1, [r5]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D5BE
_0811D5A0:
	bl sub_0811E624
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811D5BE
	bl sub_0811ED98
	bl sub_0811EEE0
	ldr r1, [r5]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0811D5BA:
	movs r0, #0
	b _0811D5C0
_0811D5BE:
	movs r0, #1
_0811D5C0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D544

	thumb_func_start sub_0811D5C8
sub_0811D5C8: @ 0x0811D5C8
	push {r4, lr}
	ldr r4, _0811D5DC
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0811D5E0
	cmp r0, #1
	beq _0811D5F4
	b _0811D5FE
	.align 2, 0
_0811D5DC: .4byte 0x02039DE8
_0811D5E0:
	bl sub_0811E7A0
	movs r0, #4
	bl sub_0811D9D8
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D5FE
_0811D5F4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811D600
_0811D5FE:
	movs r0, #1
_0811D600:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D5C8

	thumb_func_start sub_0811D608
sub_0811D608: @ 0x0811D608
	push {r4, lr}
	ldr r4, _0811D61C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0811D620
	cmp r0, #1
	beq _0811D634
	b _0811D63E
	.align 2, 0
_0811D61C: .4byte 0x02039DE8
_0811D620:
	bl sub_0811E7A0
	movs r0, #5
	bl sub_0811D9D8
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D63E
_0811D634:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811D640
_0811D63E:
	movs r0, #1
_0811D640:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D608

	thumb_func_start sub_0811D648
sub_0811D648: @ 0x0811D648
	push {r4, lr}
	ldr r4, _0811D65C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0811D660
	cmp r0, #1
	beq _0811D674
	b _0811D67E
	.align 2, 0
_0811D65C: .4byte 0x02039DE8
_0811D660:
	bl sub_0811E7A0
	movs r0, #6
	bl sub_0811D9D8
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D67E
_0811D674:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811D680
_0811D67E:
	movs r0, #1
_0811D680:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D648

	thumb_func_start sub_0811D688
sub_0811D688: @ 0x0811D688
	push {r4, lr}
	ldr r4, _0811D69C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0811D6A0
	cmp r0, #1
	beq _0811D6B4
	b _0811D6BE
	.align 2, 0
_0811D69C: .4byte 0x02039DE8
_0811D6A0:
	bl sub_0811E7A0
	movs r0, #7
	bl sub_0811D9D8
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D6BE
_0811D6B4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811D6C0
_0811D6BE:
	movs r0, #1
_0811D6C0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D688

	thumb_func_start sub_0811D6C8
sub_0811D6C8: @ 0x0811D6C8
	push {r4, lr}
	ldr r4, _0811D6DC
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0811D6E0
	cmp r0, #1
	beq _0811D6F4
	b _0811D6FE
	.align 2, 0
_0811D6DC: .4byte 0x02039DE8
_0811D6E0:
	bl sub_0811E7A0
	movs r0, #8
	bl sub_0811D9D8
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D6FE
_0811D6F4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811D700
_0811D6FE:
	movs r0, #1
_0811D700:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D6C8

	thumb_func_start sub_0811D708
sub_0811D708: @ 0x0811D708
	push {r4, lr}
	ldr r4, _0811D71C
	ldr r0, [r4]
	ldrh r0, [r0]
	cmp r0, #0
	beq _0811D720
	cmp r0, #1
	beq _0811D734
	b _0811D73E
	.align 2, 0
_0811D71C: .4byte 0x02039DE8
_0811D720:
	bl sub_0811E7A0
	movs r0, #9
	bl sub_0811D9D8
	ldr r1, [r4]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0811D73E
_0811D734:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811D740
_0811D73E:
	movs r0, #1
_0811D740:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811D708

	thumb_func_start sub_0811D748
sub_0811D748: @ 0x0811D748
	push {r4, lr}
	ldr r4, _0811D7A4
	ldr r0, _0811D7A8
	bl Alloc
	adds r2, r0, #0
	str r2, [r4]
	cmp r2, #0
	beq _0811D7AC
	movs r1, #0
	strh r1, [r2]
	movs r3, #0xb6
	lsls r3, r3, #2
	adds r0, r2, r3
	str r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	str r1, [r0]
	adds r3, #4
	adds r0, r2, r3
	str r1, [r0]
	bl FooterHasFourOptions_
	ldr r1, [r4]
	strb r0, [r1, #0xa]
	movs r0, #1
	b _0811D7AE
	.align 2, 0
_0811D7A4: .4byte 0x02039DE8
_0811D7A8: .4byte 0x000012FC
_0811D7AC:
	movs r0, #0
_0811D7AE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0811D748

	thumb_func_start sub_0811D7B4
sub_0811D7B4: @ 0x0811D7B4
	push {lr}
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r1, #0xc1
	lsls r1, r1, #6
	movs r0, #0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_0811D7B4

	thumb_func_start sub_0811D814
sub_0811D814: @ 0x0811D814
	push {r4, lr}
	bl ResetPaletteFade
	ldr r0, _0811D868
	movs r1, #0
	movs r2, #0x20
	bl LoadPalette
	ldr r0, _0811D86C
	movs r1, #0x10
	movs r2, #0x20
	bl LoadPalette
	ldr r0, _0811D870
	movs r1, #0x40
	movs r2, #0x20
	bl LoadPalette
	ldr r0, _0811D874
	movs r1, #0xa0
	movs r2, #8
	bl LoadPalette
	ldr r4, _0811D878
	adds r0, r4, #0
	movs r1, #0xb0
	movs r2, #0xc
	bl LoadPalette
	adds r0, r4, #0
	movs r1, #0xf0
	movs r2, #0xc
	bl LoadPalette
	adds r0, r4, #0
	movs r1, #0x30
	movs r2, #0xc
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0811D868: .4byte 0x08573E64
_0811D86C: .4byte 0x0857423C
_0811D870: .4byte 0x0857425C
_0811D874: .4byte 0x08574344
_0811D878: .4byte 0x0857434C
	thumb_func_end sub_0811D814

	thumb_func_start sub_0811D87C
sub_0811D87C: @ 0x0811D87C
	push {r4, r5, lr}
	sub sp, #0x14
	bl GetTitleText
	adds r5, r0, #0
	cmp r5, #0
	beq _0811D8D8
	bl StringLength
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r4, #0x10
	subs r4, r4, r0
	lsrs r0, r4, #0x1f
	adds r4, r4, r0
	asrs r4, r4, #1
	lsls r4, r4, #0x13
	lsrs r4, r4, #0x10
	movs r0, #0
	movs r1, #0
	bl FillWindowPixelBuffer
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r1, #0
	str r1, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #3
	str r0, [sp, #0x10]
	movs r0, #0
	movs r1, #1
	adds r2, r5, #0
	adds r3, r4, #0
	bl sub_0811D920
	movs r0, #0
	bl PutWindowTilemap
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
_0811D8D8:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_0811D87C

	thumb_func_start sub_0811D8E0
sub_0811D8E0: @ 0x0811D8E0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r2, #0
	ldr r2, [sp, #0x1c]
	ldr r4, [sp, #0x20]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r2, r2, #0x18
	lsrs r0, r2, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	cmp r1, #1
	bne _0811D908
	adds r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0811D908:
	str r0, [sp]
	str r4, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r2, r6, #0
	bl AddTextPrinterParameterized
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_0811D8E0

	thumb_func_start sub_0811D920
sub_0811D920: @ 0x0811D920
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov sb, r2
	ldr r2, [sp, #0x2c]
	ldr r4, [sp, #0x30]
	ldr r5, [sp, #0x34]
	ldr r6, [sp, #0x38]
	ldr r7, [sp, #0x3c]
	mov r8, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	lsls r2, r2, #0x18
	lsrs r3, r2, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r1, #1
	bne _0811D966
	adds r0, r3, #2
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_0811D966:
	add r0, sp, #0xc
	strb r5, [r0]
	strb r6, [r0, #1]
	strb r2, [r0, #2]
	str r0, [sp]
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	mov r0, ip
	adds r2, r7, #0
	bl AddTextPrinterParameterized3
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_0811D920

	thumb_func_start sub_0811D990
sub_0811D990: @ 0x0811D990
	push {lr}
	sub sp, #0xc
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect
	movs r0, #1
	movs r1, #1
	movs r2, #0xe0
	bl LoadUserWindowBorderGfx
	movs r0, #1
	movs r1, #1
	movs r2, #0xe
	bl DrawTextBorderOuter
	movs r0, #0
	bl sub_0811D9D8
	movs r0, #1
	bl PutWindowTilemap
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	add sp, #0xc
	pop {r0}
	bx r0
	thumb_func_end sub_0811D990

	thumb_func_start sub_0811D9D8
sub_0811D9D8: @ 0x0811D9D8
	push {lr}
	sub sp, #0x14
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r0, #0
	str r0, [sp, #0x10]
	str r0, [sp, #0xc]
	cmp r1, #9
	bhi _0811DA90
	lsls r0, r1, #2
	ldr r1, _0811D9F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0811D9F4: .4byte 0x0811D9F8
_0811D9F8: @ jump table
	.4byte _0811DA20 @ case 0
	.4byte _0811DA3E @ case 1
	.4byte _0811DA2A @ case 2
	.4byte _0811DA34 @ case 3
	.4byte _0811DA48 @ case 4
	.4byte _0811DA54 @ case 5
	.4byte _0811DA60 @ case 6
	.4byte _0811DA70 @ case 7
	.4byte _0811DA7C @ case 8
	.4byte _0811DA88 @ case 9
_0811DA20:
	add r1, sp, #0x10
	add r0, sp, #0xc
	bl GetEasyChatInstructionsText
	b _0811DA90
_0811DA2A:
	add r1, sp, #0x10
	add r0, sp, #0xc
	bl sub_0811C344
	b _0811DA90
_0811DA34:
	add r1, sp, #0x10
	add r0, sp, #0xc
	bl GetEasyChatConfirmText
	b _0811DA90
_0811DA3E:
	add r1, sp, #0x10
	add r0, sp, #0xc
	bl GetEasyChatConfirmDeletionText
	b _0811DA90
_0811DA48:
	ldr r0, _0811DA50
	str r0, [sp, #0xc]
	b _0811DA90
	.align 2, 0
_0811DA50: .4byte 0x085CBCD0
_0811DA54:
	ldr r0, _0811DA5C
	str r0, [sp, #0xc]
	b _0811DA90
	.align 2, 0
_0811DA5C: .4byte 0x085CBCE0
_0811DA60:
	ldr r0, _0811DA68
	str r0, [sp, #0xc]
	ldr r0, _0811DA6C
	b _0811DA8E
	.align 2, 0
_0811DA68: .4byte 0x085CBB1B
_0811DA6C: .4byte 0x085CBB2F
_0811DA70:
	ldr r0, _0811DA78
	str r0, [sp, #0xc]
	b _0811DA90
	.align 2, 0
_0811DA78: .4byte 0x085CBCEF
_0811DA7C:
	ldr r0, _0811DA84
	str r0, [sp, #0xc]
	b _0811DA90
	.align 2, 0
_0811DA84: .4byte 0x085CBB4E
_0811DA88:
	ldr r0, _0811DADC
	str r0, [sp, #0xc]
	ldr r0, _0811DAE0
_0811DA8E:
	str r0, [sp, #0x10]
_0811DA90:
	movs r0, #1
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r2, [sp, #0xc]
	cmp r2, #0
	beq _0811DAB2
	movs r1, #0
	str r1, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #1
	movs r1, #1
	movs r3, #0
	bl sub_0811D8E0
_0811DAB2:
	ldr r2, [sp, #0x10]
	cmp r2, #0
	beq _0811DACE
	movs r0, #0x10
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #1
	movs r3, #0
	bl sub_0811D8E0
_0811DACE:
	movs r0, #1
	movs r1, #3
	bl CopyWindowToVram
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_0811DADC: .4byte 0x085CBC62
_0811DAE0: .4byte 0x085CBC6D
	thumb_func_end sub_0811D9D8

	thumb_func_start sub_0811DAE4
sub_0811DAE4: @ 0x0811DAE4
	push {lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0811DB0C
	movs r1, #1
	str r1, [sp]
	movs r1, #0xe
	str r1, [sp, #4]
	str r0, [sp, #8]
	adds r0, r2, #0
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl CreateYesNoMenuAtPos
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_0811DB0C: .4byte 0x085743AC
	thumb_func_end sub_0811DAE4

	thumb_func_start sub_0811DB10
sub_0811DB10: @ 0x0811DB10
	push {r4, r5, r6, lr}
	sub sp, #8
	bl GetEasyChatScreenFrameId
	lsls r0, r0, #0x18
	ldr r6, _0811DB8C
	ldr r4, [sp]
	ands r4, r6
	movs r1, #3
	orrs r4, r1
	str r4, [sp]
	ldr r1, _0811DB90
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r3, [r0]
	lsls r1, r3, #0x1b
	lsrs r1, r1, #0x13
	ldr r5, _0811DB94
	adds r2, r5, #0
	ands r2, r4
	orrs r2, r1
	lsrs r3, r3, #5
	lsls r3, r3, #0x10
	ldr r1, _0811DB98
	ands r2, r1
	orrs r2, r3
	str r2, [sp]
	ldrb r3, [r0, #1]
	lsls r3, r3, #0x18
	ldr r1, _0811DB9C
	ands r1, r2
	orrs r1, r3
	str r1, [sp]
	ldrb r1, [r0, #2]
	ldr r0, [sp, #4]
	ands r0, r6
	orrs r0, r1
	ands r0, r5
	movs r1, #0xb0
	lsls r1, r1, #4
	orrs r0, r1
	ldr r1, _0811DBA0
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl AddWindow
	ldr r1, _0811DBA4
	ldr r1, [r1]
	strh r0, [r1, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl PutWindowTilemap
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0811DB8C: .4byte 0xFFFFFF00
_0811DB90: .4byte 0x08574358
_0811DB94: .4byte 0xFFFF00FF
_0811DB98: .4byte 0xFF00FFFF
_0811DB9C: .4byte 0x00FFFFFF
_0811DBA0: .4byte 0x0000FFFF
_0811DBA4: .4byte 0x02039DE8
	thumb_func_end sub_0811DB10

	thumb_func_start sub_0811DBA8
sub_0811DBA8: @ 0x0811DBA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	bl GetEasyChatWordBuffer
	adds r6, r0, #0
	bl GetNumColumns
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	bl GetNumRows
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r4, _0811DBE0
	ldr r0, [r4]
	ldrb r0, [r0, #2]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	movs r5, #0
	b _0811DC86
	.align 2, 0
_0811DBE0: .4byte 0x02039DE8
_0811DBE4:
	ldr r1, _0811DC20
	ldr r0, [r1]
	adds r0, #0xb
	movs r1, #0
	movs r2, #0xc0
	bl StringFill
	ldr r1, _0811DC20
	ldr r0, [r1]
	adds r2, r0, #0
	adds r2, #0xd
	movs r4, #0
	lsls r7, r5, #0x1c
	adds r5, #1
	mov sb, r5
	cmp r4, r8
	bge _0811DC64
	ldr r0, _0811DC24
	mov sl, r0
_0811DC0A:
	ldrh r0, [r6]
	cmp r0, sl
	beq _0811DC28
	adds r1, r0, #0
	adds r0, r2, #0
	bl CopyEasyChatWord
	adds r2, r0, #0
	adds r5, r6, #2
	adds r4, #1
	b _0811DC58
	.align 2, 0
_0811DC20: .4byte 0x02039DE8
_0811DC24: .4byte 0x0000FFFF
_0811DC28:
	adds r0, r2, #0
	movs r1, #0
	movs r2, #4
	bl WriteColorChangeControlCode
	adds r2, r0, #0
	adds r5, r6, #2
	adds r4, #1
	movs r3, #0xf9
	movs r1, #9
	movs r0, #4
_0811DC3E:
	strb r3, [r2]
	adds r2, #1
	strb r1, [r2]
	adds r2, #1
	subs r0, #1
	cmp r0, #0
	bge _0811DC3E
	adds r0, r2, #0
	movs r1, #0
	movs r2, #2
	bl WriteColorChangeControlCode
	adds r2, r0, #0
_0811DC58:
	movs r0, #0
	strb r0, [r2]
	adds r2, #2
	adds r6, r5, #0
	cmp r4, r8
	blt _0811DC0A
_0811DC64:
	movs r0, #0xff
	strb r0, [r2]
	ldr r1, _0811DCA8
	ldr r2, [r1]
	ldrb r0, [r2, #2]
	adds r2, #0xb
	lsrs r1, r7, #0x18
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #0
	bl sub_0811D8E0
	mov r5, sb
_0811DC86:
	ldr r0, [sp, #0xc]
	cmp r5, r0
	blt _0811DBE4
	ldr r0, _0811DCA8
	ldr r0, [r0]
	ldrb r0, [r0, #2]
	movs r1, #3
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811DCA8: .4byte 0x02039DE8
	thumb_func_end sub_0811DBA8

	thumb_func_start sub_0811DCAC
sub_0811DCAC: @ 0x0811DCAC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov r8, r0
	bl GetEasyChatScreenFrameId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r0, #0
	str r0, [sp]
	ldr r2, _0811DDEC
	mov r0, sp
	mov r1, r8
	bl CpuFastSet
	ldr r0, _0811DDF0
	mov r1, sb
	lsls r3, r1, #2
	adds r3, r3, r0
	ldrb r0, [r3]
	lsls r2, r0, #0x18
	lsrs r1, r2, #0x1d
	subs r6, r1, #1
	lsls r0, r0, #0x1b
	lsrs r4, r0, #0x1b
	subs r5, r4, #1
	adds r0, r4, #0
	ldrb r1, [r3, #1]
	adds r7, r0, r1
	lsrs r2, r2, #0x1d
	ldrb r3, [r3, #2]
	adds r3, r2, r3
	lsls r0, r6, #5
	adds r0, r0, r5
	lsls r0, r0, #1
	add r0, r8
	ldr r2, _0811DDF4
	adds r1, r2, #0
	strh r1, [r0]
	adds r5, r4, #0
	cmp r5, r7
	bge _0811DD22
	ldr r4, _0811DDF8
	adds r2, r4, #0
	lsls r1, r5, #1
	lsls r0, r6, #6
	add r0, r8
	adds r1, r1, r0
	subs r5, r7, r5
_0811DD16:
	strh r2, [r1]
	adds r1, #2
	subs r5, #1
	cmp r5, #0
	bne _0811DD16
	adds r5, r7, #0
_0811DD22:
	lsls r0, r6, #5
	adds r0, r0, r5
	lsls r0, r0, #1
	add r0, r8
	ldr r2, _0811DDFC
	adds r1, r2, #0
	strh r1, [r0]
	adds r6, #1
	ldr r4, _0811DDF0
	mov sl, r4
	mov r0, sb
	lsls r0, r0, #2
	mov sb, r0
	cmp r6, r3
	bge _0811DD94
	add r0, sl
	ldrb r0, [r0]
	lsls r0, r0, #0x1b
	mov ip, r0
_0811DD48:
	mov r1, ip
	lsrs r0, r1, #0x1b
	subs r5, r0, #1
	lsls r1, r6, #5
	adds r1, r1, r5
	lsls r1, r1, #1
	add r1, r8
	ldr r4, _0811DE00
	adds r2, r4, #0
	strh r2, [r1]
	adds r5, r0, #0
	adds r4, r6, #1
	cmp r5, r7
	bge _0811DD80
	movs r0, #0x80
	lsls r0, r0, #5
	adds r2, r0, #0
	lsls r1, r5, #1
	lsls r0, r6, #6
	add r0, r8
	adds r1, r1, r0
	subs r5, r7, r5
_0811DD74:
	strh r2, [r1]
	adds r1, #2
	subs r5, #1
	cmp r5, #0
	bne _0811DD74
	adds r5, r7, #0
_0811DD80:
	lsls r0, r6, #5
	adds r0, r0, r5
	lsls r0, r0, #1
	add r0, r8
	ldr r2, _0811DE04
	adds r1, r2, #0
	strh r1, [r0]
	adds r6, r4, #0
	cmp r6, r3
	blt _0811DD48
_0811DD94:
	mov r0, sb
	add r0, sl
	ldrb r2, [r0]
	lsls r2, r2, #0x1b
	lsrs r2, r2, #0x1b
	subs r5, r2, #1
	lsls r3, r6, #5
	adds r0, r3, r5
	lsls r0, r0, #1
	add r0, r8
	ldr r4, _0811DE08
	adds r1, r4, #0
	strh r1, [r0]
	adds r5, r2, #0
	cmp r5, r7
	bge _0811DDCE
	ldr r0, _0811DE0C
	adds r2, r0, #0
	lsls r1, r5, #1
	lsls r0, r6, #6
	add r0, r8
	adds r0, r1, r0
	subs r5, r7, r5
_0811DDC2:
	strh r2, [r0]
	adds r0, #2
	subs r5, #1
	cmp r5, #0
	bne _0811DDC2
	adds r5, r7, #0
_0811DDCE:
	adds r0, r3, r5
	lsls r0, r0, #1
	add r0, r8
	ldr r2, _0811DE10
	adds r1, r2, #0
	strh r1, [r0]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811DDEC: .4byte 0x01000200
_0811DDF0: .4byte 0x08574358
_0811DDF4: .4byte 0x00001001
_0811DDF8: .4byte 0x00001002
_0811DDFC: .4byte 0x00001003
_0811DE00: .4byte 0x00001005
_0811DE04: .4byte 0x00001007
_0811DE08: .4byte 0x00001009
_0811DE0C: .4byte 0x0000100A
_0811DE10: .4byte 0x0000100B
	thumb_func_end sub_0811DCAC

	thumb_func_start sub_0811DE14
sub_0811DE14: @ 0x0811DE14
	push {r4, lr}
	sub sp, #8
	movs r0, #3
	bl GetBgTilemapBuffer
	adds r4, r0, #0
	bl GetEasyChatScreenFrameId
	lsls r0, r0, #0x18
	ldr r1, _0811DE3C
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r1, [r0, #3]
	cmp r1, #2
	beq _0811DE46
	cmp r1, #2
	bgt _0811DE40
	cmp r1, #1
	beq _0811DE54
	b _0811DE84
	.align 2, 0
_0811DE3C: .4byte 0x08574358
_0811DE40:
	cmp r1, #3
	beq _0811DE70
	b _0811DE84
_0811DE46:
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r4, r4, r0
	movs r0, #0x20
	str r0, [sp]
	str r1, [sp, #4]
	b _0811DE62
_0811DE54:
	movs r0, #0xc0
	lsls r0, r0, #3
	adds r4, r4, r0
	movs r0, #0x20
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
_0811DE62:
	movs r0, #3
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0xa
	bl CopyToBgTilemapBufferRect
	b _0811DE84
_0811DE70:
	movs r0, #0x20
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #3
	adds r1, r4, #0
	movs r2, #0
	movs r3, #9
	bl CopyToBgTilemapBufferRect
_0811DE84:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0811DE14

	thumb_func_start sub_0811DE8C
sub_0811DE8C: @ 0x0811DE8C
	push {lr}
	movs r0, #2
	bl PutWindowTilemap
	movs r0, #2
	bl CopyBgTilemapBufferToVram
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811DE8C

	thumb_func_start sub_0811DEA0
sub_0811DEA0: @ 0x0811DEA0
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0811E598
	movs r0, #2
	movs r1, #0x11
	bl FillWindowPixelBuffer
	cmp r4, #1
	beq _0811DEC4
	cmp r4, #1
	blo _0811DEBE
	cmp r4, #2
	beq _0811DECA
	b _0811DECE
_0811DEBE:
	bl sub_0811DEFC
	b _0811DECE
_0811DEC4:
	bl sub_0811DF70
	b _0811DECE
_0811DECA:
	bl sub_0811DFAC
_0811DECE:
	movs r0, #2
	movs r1, #2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0811DEA0

	thumb_func_start sub_0811DEDC
sub_0811DEDC: @ 0x0811DEDC
	push {lr}
	bl sub_0811C3B4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811DEF0
	movs r0, #0
	bl sub_0811DEA0
	b _0811DEF6
_0811DEF0:
	movs r0, #1
	bl sub_0811DEA0
_0811DEF6:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811DEDC

	thumb_func_start sub_0811DEFC
sub_0811DEFC: @ 0x0811DEFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	movs r6, #0
	movs r0, #0x60
	mov r8, r0
_0811DF0A:
	movs r5, #0
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r7, r0, #0x18
	movs r4, #0x80
	lsls r4, r4, #0x14
_0811DF16:
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	adds r6, #1
	bl sub_0811F914
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x16
	beq _0811DF54
	bl GetEasyChatWordGroupName
	adds r2, r0, #0
	lsrs r3, r4, #0x18
	str r7, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #1
	bl sub_0811D8E0
	movs r0, #0xe0
	lsls r0, r0, #0x16
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #2
	ble _0811DF16
	movs r1, #0x10
	add r8, r1
	b _0811DF0A
_0811DF54:
	bl sub_0811C3C0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl sub_0811E5C0
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811DEFC

	thumb_func_start sub_0811DF70
sub_0811DF70: @ 0x0811DF70
	push {r4, r5, r6, lr}
	sub sp, #0xc
	movs r5, #0
	movs r4, #0xc0
	lsls r4, r4, #0x17
	ldr r6, _0811DFA8
_0811DF7C:
	ldm r6!, {r2}
	lsrs r0, r4, #0x18
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #1
	movs r3, #8
	bl sub_0811D8E0
	movs r0, #0x80
	lsls r0, r0, #0x15
	adds r4, r4, r0
	adds r5, #1
	cmp r5, #3
	bls _0811DF7C
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0811DFA8: .4byte 0x085743BC
	thumb_func_end sub_0811DF70

	thumb_func_start sub_0811DFAC
sub_0811DFAC: @ 0x0811DFAC
	push {lr}
	movs r0, #0
	movs r1, #4
	bl sub_0811E07C
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811DFAC

	thumb_func_start sub_0811DFBC
sub_0811DFBC: @ 0x0811DFBC
	push {r4, lr}
	bl sub_0811C3E0
	adds r4, r0, #0
	adds r4, #3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl sub_0811E164
	adds r0, r4, #0
	movs r1, #1
	bl sub_0811E07C
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0811DFBC

	thumb_func_start sub_0811DFE0
sub_0811DFE0: @ 0x0811DFE0
	push {r4, lr}
	bl sub_0811C3E0
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #1
	bl sub_0811E164
	adds r0, r4, #0
	movs r1, #1
	bl sub_0811E07C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811DFE0

	thumb_func_start sub_0811E004
sub_0811E004: @ 0x0811E004
	push {r4, r5, lr}
	bl sub_0811C3E0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r5, r0, #0
	adds r0, r5, #4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_0811C3EC
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bls _0811E026
	adds r4, r0, #0
_0811E026:
	cmp r5, r4
	bhs _0811E040
	subs r4, r4, r5
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_0811E164
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_0811E07C
_0811E040:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811E004

	thumb_func_start sub_0811E048
sub_0811E048: @ 0x0811E048
	push {r4, r5, lr}
	bl sub_0811C3E0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl sub_0811E65C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r5, r0
	bhs _0811E074
	subs r4, r0, r5
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_0811E164
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_0811E07C
_0811E074:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811E048

	thumb_func_start sub_0811E07C
sub_0811E07C: @ 0x0811E07C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x14]
	lsls r1, r0, #1
	adds r7, r1, r0
	lsls r0, r0, #4
	adds r1, r0, #0
	adds r1, #0x60
	movs r0, #0xff
	ands r1, r0
	movs r0, #0
	b _0811E144
_0811E0A4:
	movs r2, #0x10
	adds r2, r2, r1
	mov sl, r2
	adds r0, #1
	str r0, [sp, #0x18]
	lsls r0, r1, #0x18
	lsrs r6, r0, #0x18
	movs r0, #0x80
	lsls r0, r0, #0x15
	mov r8, r0
	movs r2, #2
	mov sb, r2
_0811E0BC:
	lsls r0, r7, #0x10
	lsrs r0, r0, #0x10
	adds r7, #1
	bl sub_0811FAD0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _0811E104
	cmp r4, r0
	beq _0811E12E
	ldr r5, _0811E108
	ldr r0, [r5]
	adds r0, #0xcc
	adds r1, r4, #0
	movs r2, #0
	bl CopyEasyChatWordPadded
	adds r0, r4, #0
	bl sub_0811C820
	adds r1, r0, #0
	cmp r1, #0
	bne _0811E10C
	ldr r2, [r5]
	adds r2, #0xcc
	mov r0, r8
	lsrs r3, r0, #0x18
	str r6, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	movs r1, #1
	bl sub_0811D8E0
	b _0811E12E
	.align 2, 0
_0811E104: .4byte 0x0000FFFF
_0811E108: .4byte 0x02039DE8
_0811E10C:
	ldr r2, [r5]
	adds r2, #0xcc
	mov r0, r8
	lsrs r3, r0, #0x18
	str r6, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #5
	str r0, [sp, #0xc]
	movs r0, #3
	str r0, [sp, #0x10]
	movs r0, #2
	movs r1, #1
	bl sub_0811D920
_0811E12E:
	movs r2, #0x90
	lsls r2, r2, #0x17
	add r8, r2
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r2, sb
	cmp r2, #0
	bge _0811E0BC
	mov r1, sl
	ldr r0, [sp, #0x18]
_0811E144:
	ldr r2, [sp, #0x14]
	cmp r0, r2
	blt _0811E0A4
	movs r0, #2
	movs r1, #2
	bl CopyWindowToVram
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811E07C

	thumb_func_start sub_0811E164
sub_0811E164: @ 0x0811E164
	push {r4, r5, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r0, r0, #0x14
	adds r3, r0, #0
	adds r3, #0x60
	movs r0, #0xff
	ands r3, r0
	lsrs r0, r1, #0x14
	adds r1, r3, r0
	cmp r1, #0xff
	ble _0811E190
	ldr r0, _0811E18C
	adds r4, r1, r0
	movs r0, #0x80
	lsls r0, r0, #1
	subs r0, r0, r3
	b _0811E192
	.align 2, 0
_0811E18C: .4byte 0xFFFFFF00
_0811E190:
	movs r4, #0
_0811E192:
	movs r5, #0xe0
	str r5, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #0x11
	movs r2, #0
	bl FillWindowPixelRect
	cmp r4, #0
	beq _0811E1BE
	str r5, [sp]
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #0x11
	movs r2, #0
	movs r3, #0
	bl FillWindowPixelRect
_0811E1BE:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811E164

	thumb_func_start sub_0811E1C8
sub_0811E1C8: @ 0x0811E1C8
	push {lr}
	movs r0, #2
	movs r1, #0x11
	bl FillWindowPixelBuffer
	movs r0, #2
	movs r1, #2
	bl CopyWindowToVram
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811E1C8

	thumb_func_start sub_0811E1E0
sub_0811E1E0: @ 0x0811E1E0
	push {lr}
	ldr r1, _0811E1F4
	cmp r0, #6
	bhi _0811E29A
	lsls r0, r0, #2
	ldr r1, _0811E1F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0811E1F4: .4byte 0x02039DE8
_0811E1F8: .4byte 0x0811E1FC
_0811E1FC: @ jump table
	.4byte _0811E218 @ case 0
	.4byte _0811E22C @ case 1
	.4byte _0811E23C @ case 2
	.4byte _0811E250 @ case 3
	.4byte _0811E264 @ case 4
	.4byte _0811E278 @ case 5
	.4byte _0811E28C @ case 6
_0811E218:
	ldr r1, _0811E228
	ldr r2, [r1]
	movs r0, #0
	strb r0, [r2, #6]
	ldr r2, [r1]
	movs r0, #0xa
	b _0811E298
	.align 2, 0
_0811E228: .4byte 0x02039DE8
_0811E22C:
	ldr r1, _0811E238
	ldr r2, [r1]
	movs r3, #0
	movs r0, #9
	b _0811E258
	.align 2, 0
_0811E238: .4byte 0x02039DE8
_0811E23C:
	ldr r1, _0811E24C
	ldr r2, [r1]
	movs r0, #0xb
	strb r0, [r2, #6]
	ldr r2, [r1]
	movs r0, #0x11
	b _0811E298
	.align 2, 0
_0811E24C: .4byte 0x02039DE8
_0811E250:
	ldr r1, _0811E260
	ldr r2, [r1]
	movs r3, #0
	movs r0, #0x11
_0811E258:
	strb r0, [r2, #6]
	ldr r0, [r1]
	strb r3, [r0, #7]
	b _0811E29A
	.align 2, 0
_0811E260: .4byte 0x02039DE8
_0811E264:
	ldr r1, _0811E274
	ldr r2, [r1]
	movs r0, #0x11
	strb r0, [r2, #6]
	ldr r2, [r1]
	movs r0, #0xa
	b _0811E298
	.align 2, 0
_0811E274: .4byte 0x02039DE8
_0811E278:
	ldr r1, _0811E288
	ldr r2, [r1]
	movs r0, #0x12
	strb r0, [r2, #6]
	ldr r2, [r1]
	movs r0, #0x16
	b _0811E298
	.align 2, 0
_0811E288: .4byte 0x02039DE8
_0811E28C:
	ldr r1, _0811E2B4
	ldr r2, [r1]
	movs r0, #0x16
	strb r0, [r2, #6]
	ldr r2, [r1]
	movs r0, #0x12
_0811E298:
	strb r0, [r2, #7]
_0811E29A:
	ldr r1, [r1]
	ldrb r0, [r1, #6]
	movs r3, #1
	rsbs r3, r3, #0
	adds r2, r3, #0
	ldrb r3, [r1, #7]
	cmp r0, r3
	bhs _0811E2AC
	movs r2, #1
_0811E2AC:
	strb r2, [r1, #8]
	pop {r0}
	bx r0
	.align 2, 0
_0811E2B4: .4byte 0x02039DE8
	thumb_func_end sub_0811E1E0

	thumb_func_start sub_0811E2B8
sub_0811E2B8: @ 0x0811E2B8
	push {r4, lr}
	ldr r4, _0811E2E4
	ldr r1, [r4]
	ldrb r2, [r1, #6]
	ldrb r0, [r1, #7]
	cmp r2, r0
	beq _0811E2E8
	ldrb r0, [r1, #8]
	adds r0, r2, r0
	strb r0, [r1, #6]
	ldr r0, [r4]
	ldrb r0, [r0, #6]
	bl sub_0811E2F0
	ldr r0, [r4]
	ldrb r1, [r0, #6]
	ldrb r0, [r0, #7]
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	b _0811E2EA
	.align 2, 0
_0811E2E4: .4byte 0x02039DE8
_0811E2E8:
	movs r0, #0
_0811E2EA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0811E2B8

	thumb_func_start sub_0811E2F0
sub_0811E2F0: @ 0x0811E2F0
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0xa
	bl FillBgTilemapBufferRect_Palette0
	cmp r4, #0x16
	bls _0811E312
	b _0811E42E
_0811E312:
	lsls r0, r4, #2
	ldr r1, _0811E31C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0811E31C: .4byte 0x0811E320
_0811E320: @ jump table
	.4byte _0811E42E @ case 0
	.4byte _0811E37C @ case 1
	.4byte _0811E384 @ case 2
	.4byte _0811E38C @ case 3
	.4byte _0811E394 @ case 4
	.4byte _0811E39C @ case 5
	.4byte _0811E3A4 @ case 6
	.4byte _0811E414 @ case 7
	.4byte _0811E406 @ case 8
	.4byte _0811E3F8 @ case 9
	.4byte _0811E3EA @ case 10
	.4byte _0811E3B2 @ case 11
	.4byte _0811E3BA @ case 12
	.4byte _0811E3C2 @ case 13
	.4byte _0811E3CA @ case 14
	.4byte _0811E3D2 @ case 15
	.4byte _0811E3DA @ case 16
	.4byte _0811E3E2 @ case 17
	.4byte _0811E3EA @ case 18
	.4byte _0811E3F8 @ case 19
	.4byte _0811E406 @ case 20
	.4byte _0811E414 @ case 21
	.4byte _0811E422 @ case 22
_0811E37C:
	movs r0, #0xb
	movs r1, #0xe
	movs r2, #3
	b _0811E3AA
_0811E384:
	movs r0, #9
	movs r1, #0xe
	movs r2, #7
	b _0811E3AA
_0811E38C:
	movs r0, #7
	movs r1, #0xe
	movs r2, #0xb
	b _0811E3AA
_0811E394:
	movs r0, #5
	movs r1, #0xe
	movs r2, #0xf
	b _0811E3AA
_0811E39C:
	movs r0, #3
	movs r1, #0xe
	movs r2, #0x13
	b _0811E3AA
_0811E3A4:
	movs r0, #1
	movs r1, #0xe
	movs r2, #0x17
_0811E3AA:
	movs r3, #2
	bl sub_0811E43C
	b _0811E42E
_0811E3B2:
	movs r0, #1
	movs r1, #0xa
	movs r2, #0x18
	b _0811E3F0
_0811E3BA:
	movs r0, #1
	movs r1, #0xa
	movs r2, #0x19
	b _0811E3F0
_0811E3C2:
	movs r0, #1
	movs r1, #0xa
	movs r2, #0x1a
	b _0811E3F0
_0811E3CA:
	movs r0, #1
	movs r1, #0xa
	movs r2, #0x1b
	b _0811E3F0
_0811E3D2:
	movs r0, #1
	movs r1, #0xa
	movs r2, #0x1c
	b _0811E3F0
_0811E3DA:
	movs r0, #1
	movs r1, #0xa
	movs r2, #0x1d
	b _0811E3F0
_0811E3E2:
	movs r0, #0
	movs r1, #0xa
	movs r2, #0x1e
	b _0811E3F0
_0811E3EA:
	movs r0, #1
	movs r1, #0xa
	movs r2, #0x17
_0811E3F0:
	movs r3, #0xa
	bl sub_0811E43C
	b _0811E42E
_0811E3F8:
	movs r0, #1
	movs r1, #0xb
	movs r2, #0x17
	movs r3, #8
	bl sub_0811E43C
	b _0811E42E
_0811E406:
	movs r0, #1
	movs r1, #0xc
	movs r2, #0x17
	movs r3, #6
	bl sub_0811E43C
	b _0811E42E
_0811E414:
	movs r0, #1
	movs r1, #0xd
	movs r2, #0x17
	movs r3, #4
	bl sub_0811E43C
	b _0811E42E
_0811E422:
	movs r0, #1
	movs r1, #0xe
	movs r2, #0x17
	movs r3, #2
	bl sub_0811E43C
_0811E42E:
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0811E2F0

	thumb_func_start sub_0811E43C
sub_0811E43C: @ 0x0811E43C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r0
	adds r7, r1, #0
	mov sb, r2
	mov sl, r3
	ldr r0, _0811E574
	ldr r0, [r0]
	movs r1, #0xbf
	lsls r1, r1, #2
	adds r6, r0, r1
	mov r0, ip
	add r0, sb
	subs r5, r0, #1
	adds r0, r7, r3
	subs r0, #1
	mov r8, r0
	mov r2, ip
	adds r3, r7, #0
	lsls r0, r3, #5
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	ldr r4, _0811E578
	adds r1, r4, #0
	strh r1, [r0]
	adds r2, #1
	cmp r2, r5
	bge _0811E498
	ldr r0, _0811E57C
	adds r4, r0, #0
	lsls r1, r2, #1
	lsls r0, r3, #6
	adds r0, r0, r6
	adds r1, r1, r0
	subs r2, r5, r2
_0811E48C:
	strh r4, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bne _0811E48C
	adds r2, r5, #0
_0811E498:
	lsls r0, r3, #5
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	ldr r2, _0811E580
	adds r1, r2, #0
	strh r1, [r0]
	adds r3, #1
	mov r4, ip
	adds r4, #1
	adds r0, r7, #1
	str r0, [sp, #4]
	mov r1, sb
	subs r1, #2
	str r1, [sp]
	movs r2, #2
	rsbs r2, r2, #0
	add sl, r2
	cmp r3, r8
	bge _0811E508
	lsls r7, r4, #1
	mov sb, r7
_0811E4C4:
	lsls r0, r3, #5
	add r0, ip
	lsls r0, r0, #1
	adds r0, r0, r6
	ldr r2, _0811E584
	adds r1, r2, #0
	strh r1, [r0]
	adds r2, r4, #0
	adds r7, r3, #1
	cmp r4, r5
	bge _0811E4F4
	movs r0, #0x80
	lsls r0, r0, #7
	adds r1, r0, #0
	lsls r0, r3, #6
	adds r0, r0, r6
	add r0, sb
	subs r2, r5, r4
_0811E4E8:
	strh r1, [r0]
	adds r0, #2
	subs r2, #1
	cmp r2, #0
	bne _0811E4E8
	adds r2, r5, #0
_0811E4F4:
	lsls r0, r3, #5
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	ldr r2, _0811E588
	adds r1, r2, #0
	strh r1, [r0]
	adds r3, r7, #0
	cmp r3, r8
	blt _0811E4C4
_0811E508:
	lsls r0, r3, #5
	mov r7, ip
	adds r1, r0, r7
	lsls r1, r1, #1
	adds r1, r1, r6
	ldr r7, _0811E58C
	adds r2, r7, #0
	strh r2, [r1]
	adds r2, r4, #0
	mov ip, r0
	cmp r4, r5
	bge _0811E53A
	ldr r0, _0811E590
	adds r7, r0, #0
	lsls r1, r4, #1
	lsls r0, r3, #6
	adds r0, r0, r6
	adds r0, r1, r0
	subs r2, r5, r4
_0811E52E:
	strh r7, [r0]
	adds r0, #2
	subs r2, #1
	cmp r2, #0
	bne _0811E52E
	adds r2, r5, #0
_0811E53A:
	mov r1, ip
	adds r0, r1, r2
	lsls r0, r0, #1
	adds r0, r0, r6
	ldr r2, _0811E594
	adds r1, r2, #0
	strh r1, [r0]
	lsls r0, r4, #0x1b
	lsrs r0, r0, #0x18
	ldr r3, [sp, #4]
	lsls r1, r3, #0x1b
	lsrs r1, r1, #0x18
	ldr r4, [sp]
	lsls r2, r4, #0x1b
	lsrs r2, r2, #0x18
	mov r7, sl
	lsls r3, r7, #0x1b
	lsrs r3, r3, #0x18
	bl sub_0811E670
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811E574: .4byte 0x02039DE8
_0811E578: .4byte 0x00004001
_0811E57C: .4byte 0x00004002
_0811E580: .4byte 0x00004003
_0811E584: .4byte 0x00004005
_0811E588: .4byte 0x00004007
_0811E58C: .4byte 0x00004009
_0811E590: .4byte 0x0000400A
_0811E594: .4byte 0x0000400B
	thumb_func_end sub_0811E43C

	thumb_func_start sub_0811E598
sub_0811E598: @ 0x0811E598
	push {lr}
	movs r1, #0x80
	lsls r1, r1, #4
	movs r0, #2
	movs r2, #0
	bl ChangeBgY
	ldr r0, _0811E5B8
	ldr r0, [r0]
	ldr r1, _0811E5BC
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_0811E5B8: .4byte 0x02039DE8
_0811E5BC: .4byte 0x000002CE
	thumb_func_end sub_0811E598

	thumb_func_start sub_0811E5C0
sub_0811E5C0: @ 0x0811E5C0
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	movs r0, #2
	bl GetBgY
	adds r2, r0, #0
	ldr r0, _0811E60C
	ldr r3, [r0]
	ldr r0, _0811E610
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	lsls r4, r4, #0x14
	asrs r4, r4, #0x10
	lsls r0, r4, #8
	adds r2, r2, r0
	cmp r5, #0
	beq _0811E614
	movs r1, #0xb4
	lsls r1, r1, #2
	adds r0, r3, r1
	str r2, [r0]
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r3, r0
	lsls r0, r5, #8
	str r0, [r1]
	cmp r4, #0
	bge _0811E61E
	rsbs r0, r0, #0
	str r0, [r1]
	b _0811E61E
	.align 2, 0
_0811E60C: .4byte 0x02039DE8
_0811E610: .4byte 0x000002CE
_0811E614:
	movs r0, #2
	adds r1, r2, #0
	movs r2, #0
	bl ChangeBgY
_0811E61E:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_0811E5C0

	thumb_func_start sub_0811E624
sub_0811E624: @ 0x0811E624
	push {lr}
	movs r0, #2
	bl GetBgY
	ldr r1, _0811E650
	ldr r2, [r1]
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r1, r2, r3
	ldr r1, [r1]
	cmp r0, r1
	beq _0811E654
	movs r1, #0xb5
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	movs r0, #2
	movs r2, #1
	bl ChangeBgY
	movs r0, #1
	b _0811E656
	.align 2, 0
_0811E650: .4byte 0x02039DE8
_0811E654:
	movs r0, #0
_0811E656:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811E624

	thumb_func_start sub_0811E65C
sub_0811E65C: @ 0x0811E65C
	ldr r0, _0811E668
	ldr r0, [r0]
	ldr r1, _0811E66C
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_0811E668: .4byte 0x02039DE8
_0811E66C: .4byte 0x000002CE
	thumb_func_end sub_0811E65C

	thumb_func_start sub_0811E670
sub_0811E670: @ 0x0811E670
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r0, #8
	adds r0, r0, r2
	orrs r4, r0
	lsls r5, r1, #8
	adds r1, r1, r3
	orrs r5, r1
	movs r0, #0x40
	adds r1, r4, #0
	bl SetGpuReg
	movs r0, #0x44
	adds r1, r5, #0
	bl SetGpuReg
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_0811E670

	thumb_func_start sub_0811E6A4
sub_0811E6A4: @ 0x0811E6A4
	push {r4, r5, lr}
	ldr r0, _0811E6CC
	bl LoadSpriteSheets
	ldr r0, _0811E6D0
	bl LoadSpritePalettes
	movs r5, #0
	ldr r4, _0811E6D4
_0811E6B6:
	adds r0, r4, #0
	bl LoadCompressedSpriteSheet
	adds r4, #8
	adds r5, #1
	cmp r5, #3
	bls _0811E6B6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0811E6CC: .4byte 0x085743CC
_0811E6D0: .4byte 0x085743EC
_0811E6D4: .4byte 0x08574414
	thumb_func_end sub_0811E6A4

	thumb_func_start sub_0811E6D8
sub_0811E6D8: @ 0x0811E6D8
	push {lr}
	bl GetEasyChatScreenFrameId
	lsls r0, r0, #0x18
	ldr r1, _0811E724
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrb r2, [r0]
	lsls r1, r2, #0x1b
	lsrs r1, r1, #8
	lsrs r2, r2, #5
	adds r2, #1
	ldr r0, _0811E728
	movs r3, #0xc0
	lsls r3, r3, #0xc
	adds r1, r1, r3
	asrs r1, r1, #0x10
	lsls r2, r2, #3
	movs r3, #2
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0811E72C
	ldr r2, [r1]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r2, r2, r1
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0811E730
	adds r1, r1, r0
	str r1, [r2]
	movs r0, #1
	strh r0, [r1, #0x30]
	pop {r0}
	bx r0
	.align 2, 0
_0811E724: .4byte 0x08574358
_0811E728: .4byte 0x0857443C
_0811E72C: .4byte 0x02039DE8
_0811E730: .4byte 0x020205AC
	thumb_func_end sub_0811E6D8

	thumb_func_start sub_0811E734
sub_0811E734: @ 0x0811E734
	push {lr}
	adds r1, r0, #0
	movs r2, #0x30
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _0811E762
	ldrh r0, [r1, #0x2e]
	adds r0, #1
	strh r0, [r1, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0811E762
	movs r0, #0
	strh r0, [r1, #0x2e]
	ldrh r0, [r1, #0x24]
	adds r0, #1
	strh r0, [r1, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811E762
	ldr r0, _0811E768
	strh r0, [r1, #0x24]
_0811E762:
	pop {r0}
	bx r0
	.align 2, 0
_0811E768: .4byte 0x0000FFFA
	thumb_func_end sub_0811E734

	thumb_func_start sub_0811E76C
sub_0811E76C: @ 0x0811E76C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	ldr r2, _0811E79C
	ldr r2, [r2]
	movs r3, #0xb6
	lsls r3, r3, #2
	adds r2, r2, r3
	ldr r3, [r2]
	lsrs r0, r0, #0x15
	adds r0, #4
	movs r4, #0
	strh r0, [r3, #0x20]
	ldr r0, [r2]
	lsrs r1, r1, #0x15
	adds r1, #8
	strh r1, [r0, #0x22]
	ldr r0, [r2]
	strh r4, [r0, #0x24]
	ldr r0, [r2]
	strh r4, [r0, #0x2e]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0811E79C: .4byte 0x02039DE8
	thumb_func_end sub_0811E76C

	thumb_func_start sub_0811E7A0
sub_0811E7A0: @ 0x0811E7A0
	ldr r0, _0811E7BC
	ldr r1, [r0]
	movs r0, #0xb6
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #0
	strh r2, [r0, #0x2e]
	ldr r0, [r1]
	strh r2, [r0, #0x30]
	ldr r0, [r1]
	strh r2, [r0, #0x24]
	bx lr
	.align 2, 0
_0811E7BC: .4byte 0x02039DE8
	thumb_func_end sub_0811E7A0

	thumb_func_start sub_0811E7C0
sub_0811E7C0: @ 0x0811E7C0
	ldr r0, _0811E7D4
	ldr r0, [r0]
	movs r1, #0xb6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #0x30]
	bx lr
	.align 2, 0
_0811E7D4: .4byte 0x02039DE8
	thumb_func_end sub_0811E7C0

	thumb_func_start sub_0811E7D8
sub_0811E7D8: @ 0x0811E7D8
	push {lr}
	ldr r0, _0811E808
	movs r1, #0
	movs r2, #0
	movs r3, #3
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0811E80C
	ldr r2, [r1]
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r2, r2, r1
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0811E810
	adds r1, r1, r0
	str r1, [r2]
	bl sub_0811E838
	pop {r0}
	bx r0
	.align 2, 0
_0811E808: .4byte 0x0857448C
_0811E80C: .4byte 0x02039DE8
_0811E810: .4byte 0x020205AC
	thumb_func_end sub_0811E7D8

	thumb_func_start sub_0811E814
sub_0811E814: @ 0x0811E814
	push {r4, r5, lr}
	ldr r5, _0811E834
	ldr r0, [r5]
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	bl DestroySprite
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0
	str r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0811E834: .4byte 0x02039DE8
	thumb_func_end sub_0811E814

	thumb_func_start sub_0811E838
sub_0811E838: @ 0x0811E838
	push {r4, lr}
	sub sp, #4
	ldr r0, _0811E874
	ldr r0, [r0]
	movs r1, #0xb7
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0811E888
	mov r4, sp
	adds r4, #1
	mov r0, sp
	adds r1, r4, #0
	bl sub_0811C3A0
	bl sub_0811C3B4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811E878
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl sub_0811E890
	b _0811E888
	.align 2, 0
_0811E874: .4byte 0x02039DE8
_0811E878:
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r4, r1]
	bl sub_0811E904
_0811E888:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0811E838

	thumb_func_start sub_0811E890
sub_0811E890: @ 0x0811E890
	push {r4, r5, r6, r7, lr}
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r0, r0, #0x18
	asrs r6, r0, #0x18
	movs r0, #1
	rsbs r0, r0, #0
	cmp r6, r0
	beq _0811E8D4
	ldr r5, _0811E8D0
	ldr r0, [r5]
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0
	bl StartSpriteAnim
	ldr r1, [r5]
	adds r1, r1, r4
	ldr r2, [r1]
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #3
	adds r0, #0x28
	strh r0, [r2, #0x20]
	ldr r1, [r1]
	lsls r0, r7, #0x18
	asrs r0, r0, #0x14
	adds r0, #0x60
	b _0811E8F8
	.align 2, 0
_0811E8D0: .4byte 0x02039DE8
_0811E8D4:
	ldr r5, _0811E900
	ldr r0, [r5]
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #1
	bl StartSpriteAnim
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r2, [r0]
	movs r1, #0xd8
	strh r1, [r2, #0x20]
	ldr r1, [r0]
	lsls r0, r7, #0x18
	asrs r0, r0, #0x14
	adds r0, #0x70
_0811E8F8:
	strh r0, [r1, #0x22]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811E900: .4byte 0x02039DE8
	thumb_func_end sub_0811E890

	thumb_func_start sub_0811E904
sub_0811E904: @ 0x0811E904
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsrs r1, r0, #0x18
	mov r8, r1
	asrs r1, r0, #0x18
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _0811E99C
	lsls r7, r6, #0x18
	cmp r1, #0xa
	bne _0811E950
	asrs r0, r7, #0x18
	cmp r0, #1
	bne _0811E950
	ldr r5, _0811E94C
	ldr r0, [r5]
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #2
	bl StartSpriteAnim
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r2, [r0]
	movs r1, #0x7c
	strh r1, [r2, #0x20]
	ldr r1, [r0]
	movs r0, #0x70
	b _0811E9C0
	.align 2, 0
_0811E94C: .4byte 0x02039DE8
_0811E950:
	ldr r5, _0811E998
	ldr r0, [r5]
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #3
	bl StartSpriteAnim
	ldr r0, [r5]
	adds r6, r0, r4
	ldr r5, [r6]
	mov r0, r8
	lsls r4, r0, #0x18
	asrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #5
	bl __divsi3
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r4, r0
	lsls r0, r0, #3
	adds r0, #0x14
	strh r0, [r5, #0x20]
	ldr r1, [r6]
	asrs r0, r7, #0x14
	adds r0, #0x60
	strh r0, [r1, #0x22]
	cmp r4, #0xc
	ble _0811E9C2
	ldr r1, [r6]
	ldrh r0, [r1, #0x20]
	adds r0, #8
	strh r0, [r1, #0x20]
	b _0811E9C2
	.align 2, 0
_0811E998: .4byte 0x02039DE8
_0811E99C:
	ldr r5, _0811E9CC
	ldr r0, [r5]
	movs r4, #0xb7
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #1
	bl StartSpriteAnim
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r2, [r0]
	movs r1, #0xd8
	strh r1, [r2, #0x20]
	ldr r1, [r0]
	lsls r0, r6, #0x18
	asrs r0, r0, #0x14
	adds r0, #0x70
_0811E9C0:
	strh r0, [r1, #0x22]
_0811E9C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811E9CC: .4byte 0x02039DE8
	thumb_func_end sub_0811E904

	thumb_func_start sub_0811E9D0
sub_0811E9D0: @ 0x0811E9D0
	push {lr}
	ldr r0, _0811EA14
	movs r1, #0
	movs r2, #0
	movs r3, #4
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0811EA18
	ldr r2, [r1]
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r2, r2, r1
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0811EA1C
	adds r1, r1, r0
	str r1, [r2]
	ldr r0, _0811EA20
	str r0, [r1, #0x1c]
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	movs r2, #8
	orrs r0, r2
	strb r0, [r1, #5]
	bl sub_0811EA54
	pop {r0}
	bx r0
	.align 2, 0
_0811EA14: .4byte 0x0857443C
_0811EA18: .4byte 0x02039DE8
_0811EA1C: .4byte 0x020205AC
_0811EA20: .4byte 0x0811EA25
	thumb_func_end sub_0811E9D0

	thumb_func_start sub_0811EA24
sub_0811EA24: @ 0x0811EA24
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2e]
	adds r0, #1
	strh r0, [r1, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _0811EA4A
	movs r0, #0
	strh r0, [r1, #0x2e]
	ldrh r0, [r1, #0x24]
	adds r0, #1
	strh r0, [r1, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0811EA4A
	ldr r0, _0811EA50
	strh r0, [r1, #0x24]
_0811EA4A:
	pop {r0}
	bx r0
	.align 2, 0
_0811EA50: .4byte 0x0000FFFA
	thumb_func_end sub_0811EA24

	thumb_func_start sub_0811EA54
sub_0811EA54: @ 0x0811EA54
	push {r4, lr}
	sub sp, #4
	mov r4, sp
	adds r4, #1
	mov r0, sp
	adds r1, r4, #0
	bl sub_0811C3CC
	mov r0, sp
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #3
	adds r0, r0, r1
	adds r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r4, r1]
	lsls r1, r1, #0x19
	movs r2, #0xb0
	lsls r2, r2, #0x14
	adds r1, r1, r2
	lsrs r1, r1, #0x18
	bl sub_0811EA90
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811EA54

	thumb_func_start sub_0811EA90
sub_0811EA90: @ 0x0811EA90
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0811EAC8
	ldr r0, [r0]
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r3, r0, r1
	ldr r1, [r3]
	cmp r1, #0
	beq _0811EAC2
	lsls r0, r2, #3
	adds r0, #4
	movs r2, #0
	strh r0, [r1, #0x20]
	ldr r1, [r3]
	adds r0, r4, #1
	lsls r0, r0, #3
	strh r0, [r1, #0x22]
	ldr r0, [r3]
	strh r2, [r0, #0x24]
	ldr r0, [r3]
	strh r2, [r0, #0x2e]
_0811EAC2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0811EAC8: .4byte 0x02039DE8
	thumb_func_end sub_0811EA90

	thumb_func_start sub_0811EACC
sub_0811EACC: @ 0x0811EACC
	push {r4, lr}
	ldr r4, _0811EAF4
	ldr r0, [r4]
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0811EAEE
	bl DestroySprite
	ldr r0, [r4]
	movs r1, #0xb8
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
_0811EAEE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0811EAF4: .4byte 0x02039DE8
	thumb_func_end sub_0811EACC

	thumb_func_start sub_0811EAF8
sub_0811EAF8: @ 0x0811EAF8
	push {r4, r5, r6, lr}
	ldr r0, _0811EB50
	movs r1, #0xd0
	movs r2, #0x80
	movs r3, #6
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _0811EB54
	ldr r2, [r5]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r2, r2, r1
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _0811EB58
	adds r1, r1, r4
	str r1, [r2]
	movs r6, #0
	ldr r0, _0811EB5C
	strh r0, [r1, #0x24]
	ldr r0, _0811EB60
	movs r1, #0xd0
	movs r2, #0x50
	movs r3, #5
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, [r5]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r3, r2, r1
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	str r1, [r3]
	strb r6, [r2, #9]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0811EB50: .4byte 0x08574514
_0811EB54: .4byte 0x02039DE8
_0811EB58: .4byte 0x020205AC
_0811EB5C: .4byte 0x0000FFC0
_0811EB60: .4byte 0x085744F4
	thumb_func_end sub_0811EAF8

	thumb_func_start sub_0811EB64
sub_0811EB64: @ 0x0811EB64
	push {r4, lr}
	ldr r4, _0811EB78
	ldr r2, [r4]
	ldrb r3, [r2, #9]
	cmp r3, #0
	beq _0811EB7C
	cmp r3, #1
	beq _0811EBD4
	movs r0, #0
	b _0811EBF2
	.align 2, 0
_0811EB78: .4byte 0x02039DE8
_0811EB7C:
	movs r0, #0xb9
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r1, [r2]
	ldrh r0, [r1, #0x24]
	adds r0, #8
	strh r0, [r1, #0x24]
	ldr r2, [r2]
	movs r1, #0x24
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _0811EBF0
	strh r3, [r2, #0x24]
	bl sub_0811C3B4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811EBB2
	ldr r0, [r4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #1
	bl StartSpriteAnim
	b _0811EBC2
_0811EBB2:
	ldr r0, [r4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #2
	bl StartSpriteAnim
_0811EBC2:
	ldr r0, _0811EBD0
	ldr r1, [r0]
	ldrb r0, [r1, #9]
	adds r0, #1
	strb r0, [r1, #9]
	b _0811EBF0
	.align 2, 0
_0811EBD0: .4byte 0x02039DE8
_0811EBD4:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0811EBF0
	movs r0, #2
	strb r0, [r2, #9]
	movs r0, #0
	b _0811EBF2
_0811EBF0:
	movs r0, #1
_0811EBF2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0811EB64

	thumb_func_start sub_0811EBF8
sub_0811EBF8: @ 0x0811EBF8
	push {lr}
	ldr r2, _0811EC18
	ldr r1, [r2]
	movs r0, #0
	strb r0, [r1, #9]
	ldr r0, [r2]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #3
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.align 2, 0
_0811EC18: .4byte 0x02039DE8
	thumb_func_end sub_0811EBF8

	thumb_func_start sub_0811EC1C
sub_0811EC1C: @ 0x0811EC1C
	push {r4, r5, r6, lr}
	ldr r5, _0811EC30
	ldr r3, [r5]
	ldrb r0, [r3, #9]
	cmp r0, #0
	beq _0811EC34
	cmp r0, #1
	beq _0811EC4E
	movs r0, #0
	b _0811ECA0
	.align 2, 0
_0811EC30: .4byte 0x02039DE8
_0811EC34:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0811EC9E
	movs r0, #1
	strb r0, [r3, #9]
	b _0811EC9E
_0811EC4E:
	movs r0, #0xb9
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r1, [r2]
	ldrh r0, [r1, #0x24]
	subs r0, #8
	movs r6, #0
	strh r0, [r1, #0x24]
	ldr r0, [r2]
	movs r2, #0x24
	ldrsh r1, [r0, r2]
	movs r0, #0x40
	rsbs r0, r0, #0
	cmp r1, r0
	bgt _0811EC9E
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r3, r4
	ldr r0, [r0]
	bl DestroySprite
	ldr r0, [r5]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl DestroySprite
	ldr r1, [r5]
	adds r4, r1, r4
	str r6, [r4]
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r1, r2
	str r6, [r0]
	ldrb r0, [r1, #9]
	adds r0, #1
	strb r0, [r1, #9]
	movs r0, #0
	b _0811ECA0
_0811EC9E:
	movs r0, #1
_0811ECA0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811EC1C

	thumb_func_start sub_0811ECA8
sub_0811ECA8: @ 0x0811ECA8
	push {lr}
	ldr r0, _0811ECC0
	ldr r0, [r0]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #4
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.align 2, 0
_0811ECC0: .4byte 0x02039DE8
	thumb_func_end sub_0811ECA8

	thumb_func_start sub_0811ECC4
sub_0811ECC4: @ 0x0811ECC4
	push {lr}
	bl sub_0811C3B4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811ECE8
	ldr r0, _0811ECE4
	ldr r0, [r0]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #1
	bl StartSpriteAnim
	b _0811ECFA
	.align 2, 0
_0811ECE4: .4byte 0x02039DE8
_0811ECE8:
	ldr r0, _0811ED00
	ldr r0, [r0]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #2
	bl StartSpriteAnim
_0811ECFA:
	pop {r0}
	bx r0
	.align 2, 0
_0811ED00: .4byte 0x02039DE8
	thumb_func_end sub_0811ECC4

	thumb_func_start sub_0811ED04
sub_0811ED04: @ 0x0811ED04
	ldr r0, _0811ED1C
	ldr r0, [r0]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0x3f
	ldrb r1, [r0]
	lsrs r1, r1, #4
	movs r0, #1
	bics r0, r1
	bx lr
	.align 2, 0
_0811ED1C: .4byte 0x02039DE8
	thumb_func_end sub_0811ED04

	thumb_func_start sub_0811ED20
sub_0811ED20: @ 0x0811ED20
	push {r4, lr}
	ldr r4, _0811ED8C
	adds r0, r4, #0
	movs r1, #0x60
	movs r2, #0x50
	movs r3, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x40
	beq _0811ED4E
	ldr r0, _0811ED90
	ldr r2, [r0]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r2, r2, r0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0811ED94
	adds r0, r0, r1
	str r0, [r2]
_0811ED4E:
	adds r0, r4, #0
	movs r1, #0x60
	movs r2, #0x9c
	movs r3, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x40
	beq _0811ED82
	ldr r0, _0811ED90
	ldr r2, [r0]
	movs r0, #0xbc
	lsls r0, r0, #2
	adds r2, r2, r0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0811ED94
	adds r0, r0, r1
	str r0, [r2]
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	strb r1, [r0]
_0811ED82:
	bl sub_0811EDFC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0811ED8C: .4byte 0x0857456C
_0811ED90: .4byte 0x02039DE8
_0811ED94: .4byte 0x020205AC
	thumb_func_end sub_0811ED20

	thumb_func_start sub_0811ED98
sub_0811ED98: @ 0x0811ED98
	push {r4, r5, r6, lr}
	bl sub_0811C3FC
	ldr r6, _0811EDF8
	ldr r1, [r6]
	movs r2, #0xbb
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
	cmp r0, #0
	bne _0811EDB2
	movs r2, #1
_0811EDB2:
	adds r3, r1, #0
	adds r3, #0x3e
	movs r4, #1
	lsls r2, r2, #2
	ldrb r1, [r3]
	movs r5, #5
	rsbs r5, r5, #0
	adds r0, r5, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	bl sub_0811C430
	ldr r1, [r6]
	movs r2, #0xbc
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
	cmp r0, #0
	bne _0811EDDE
	movs r2, #1
_0811EDDE:
	adds r3, r1, #0
	adds r3, #0x3e
	adds r1, r4, #0
	ands r1, r2
	lsls r1, r1, #2
	ldrb r2, [r3]
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0811EDF8: .4byte 0x02039DE8
	thumb_func_end sub_0811ED98

	thumb_func_start sub_0811EDFC
sub_0811EDFC: @ 0x0811EDFC
	ldr r3, _0811EE28
	ldr r0, [r3]
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	movs r1, #0xbc
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r1, #0x3e
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	bx lr
	.align 2, 0
_0811EE28: .4byte 0x02039DE8
	thumb_func_end sub_0811EDFC

	thumb_func_start sub_0811EE2C
sub_0811EE2C: @ 0x0811EE2C
	push {lr}
	cmp r0, #0
	bne _0811EE48
	ldr r0, _0811EE44
	ldr r2, [r0]
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x60
	b _0811EE56
	.align 2, 0
_0811EE44: .4byte 0x02039DE8
_0811EE48:
	ldr r0, _0811EE68
	ldr r2, [r0]
	movs r1, #0xbb
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x78
_0811EE56:
	strh r1, [r0, #0x20]
	movs r3, #0xbc
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	strh r1, [r0, #0x20]
	pop {r0}
	bx r0
	.align 2, 0
_0811EE68: .4byte 0x02039DE8
	thumb_func_end sub_0811EE2C

	thumb_func_start sub_0811EE6C
sub_0811EE6C: @ 0x0811EE6C
	push {r4, lr}
	ldr r4, _0811EED4
	adds r0, r4, #0
	movs r1, #0xdc
	movs r2, #0x54
	movs r3, #1
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x40
	beq _0811EE9A
	ldr r0, _0811EED8
	ldr r2, [r0]
	movs r0, #0xbd
	lsls r0, r0, #2
	adds r2, r2, r0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0811EEDC
	adds r0, r0, r1
	str r0, [r2]
_0811EE9A:
	adds r0, r4, #0
	movs r1, #0xdc
	movs r2, #0x9c
	movs r3, #1
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x40
	beq _0811EECA
	ldr r0, _0811EED8
	ldr r2, [r0]
	movs r0, #0xbe
	lsls r0, r0, #2
	adds r2, r2, r0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0811EEDC
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #1
	bl StartSpriteAnim
_0811EECA:
	bl sub_0811EF44
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0811EED4: .4byte 0x08574554
_0811EED8: .4byte 0x02039DE8
_0811EEDC: .4byte 0x020205AC
	thumb_func_end sub_0811EE6C

	thumb_func_start sub_0811EEE0
sub_0811EEE0: @ 0x0811EEE0
	push {r4, r5, r6, lr}
	bl sub_0811C3FC
	ldr r6, _0811EF40
	ldr r1, [r6]
	movs r2, #0xbd
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
	cmp r0, #0
	bne _0811EEFA
	movs r2, #1
_0811EEFA:
	adds r3, r1, #0
	adds r3, #0x3e
	movs r4, #1
	lsls r2, r2, #2
	ldrb r1, [r3]
	movs r5, #5
	rsbs r5, r5, #0
	adds r0, r5, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r3]
	bl sub_0811C430
	ldr r1, [r6]
	movs r2, #0xbe
	lsls r2, r2, #2
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
	cmp r0, #0
	bne _0811EF26
	movs r2, #1
_0811EF26:
	adds r3, r1, #0
	adds r3, #0x3e
	adds r1, r4, #0
	ands r1, r2
	lsls r1, r1, #2
	ldrb r2, [r3]
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0811EF40: .4byte 0x02039DE8
	thumb_func_end sub_0811EEE0

	thumb_func_start sub_0811EF44
sub_0811EF44: @ 0x0811EF44
	ldr r3, _0811EF70
	ldr r0, [r3]
	movs r1, #0xbd
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	movs r1, #0xbe
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r1, #0x3e
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	bx lr
	.align 2, 0
_0811EF70: .4byte 0x02039DE8
	thumb_func_end sub_0811EF44

	thumb_func_start sub_0811EF74
sub_0811EF74: @ 0x0811EF74
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	bl GetDisplayedPersonType
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0811EF98
	cmp r0, #1
	bgt _0811EF8E
	cmp r0, #0
	beq _0811EF94
	b _0811F02E
_0811EF8E:
	cmp r0, #2
	beq _0811EF9C
	b _0811F02E
_0811EF94:
	movs r4, #0x43
	b _0811EF9E
_0811EF98:
	movs r4, #0x44
	b _0811EF9E
_0811EF9C:
	movs r4, #7
_0811EF9E:
	bl GetEasyChatScreenFrameId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _0811EFB0
	cmp r0, #5
	beq _0811EFB6
	b _0811F02E
_0811EFB0:
	movs r5, #0x4c
	movs r3, #0x28
	b _0811EFBA
_0811EFB6:
	movs r5, #0x30
	movs r3, #0x30
_0811EFBA:
	adds r0, r4, #0
	ldr r7, _0811F038
	adds r2, r5, #0
	adds r4, r3, #0
	movs r6, #0
	str r6, [sp]
	adds r1, r7, #0
	bl AddPseudoEventObject
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	beq _0811EFEE
	ldr r1, _0811F03C
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0, #5]
	movs r1, #2
	bl StartSpriteAnim
_0811EFEE:
	ldr r0, _0811F040
	ldr r0, [r0]
	ldrb r0, [r0, #8]
	movs r1, #0x69
	cmp r0, #0
	bne _0811EFFC
	movs r1, #0x64
_0811EFFC:
	adds r2, r5, #0
	subs r2, #0x18
	str r6, [sp]
	adds r0, r1, #0
	adds r1, r7, #0
	adds r3, r4, #0
	bl AddPseudoEventObject
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	beq _0811F02E
	ldr r1, _0811F03C
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0, #5]
	movs r1, #3
	bl StartSpriteAnim
_0811F02E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811F038: .4byte 0x08007141
_0811F03C: .4byte 0x020205AC
_0811F040: .4byte 0x03005AF0
	thumb_func_end sub_0811EF74

	thumb_func_start sub_0811F044
sub_0811F044: @ 0x0811F044
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #0x14
	beq _0811F06A
	cmp r0, #0x14
	bgt _0811F064
	cmp r0, #0x11
	blt _0811F082
	ldr r0, _0811F060
	bl FlagGet
	b _0811F07C
	.align 2, 0
_0811F060: .4byte 0x00000864
_0811F064:
	cmp r1, #0x15
	beq _0811F078
	b _0811F082
_0811F06A:
	ldr r0, _0811F074
	bl FlagGet
	b _0811F07C
	.align 2, 0
_0811F074: .4byte 0x00000866
_0811F078:
	bl sub_0811F5D8
_0811F07C:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811F084
_0811F082:
	movs r0, #1
_0811F084:
	pop {r1}
	bx r1
	thumb_func_end sub_0811F044

	thumb_func_start EasyChat_GetNumWordsInGroup
EasyChat_GetNumWordsInGroup: @ 0x0811F088
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r0, #0
	cmp r0, #0
	bne _0811F0A0
	movs r0, #0
	bl GetNationalPokedexCount
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _0811F0B6
_0811F0A0:
	bl sub_0811F044
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811F0AE
	movs r0, #0
	b _0811F0B6
_0811F0AE:
	ldr r0, _0811F0BC
	lsls r1, r4, #3
	adds r1, r1, r0
	ldrh r0, [r1, #6]
_0811F0B6:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0811F0BC: .4byte 0x08578D14
	thumb_func_end EasyChat_GetNumWordsInGroup

	thumb_func_start sub_0811F0C0
sub_0811F0C0: @ 0x0811F0C0
	push {r4, r5, lr}
	lsls r2, r0, #0x10
	lsrs r1, r2, #0x10
	ldr r0, _0811F0EC
	cmp r1, r0
	beq _0811F120
	lsrs r3, r2, #0x19
	ldr r5, _0811F0F0
	ands r5, r1
	cmp r3, #0x15
	bhi _0811F124
	ldr r0, _0811F0F4
	lsls r2, r3, #3
	adds r1, r2, r0
	ldrh r4, [r1, #4]
	cmp r3, #0x13
	bgt _0811F0F8
	cmp r3, #0x12
	bge _0811F0FC
	cmp r3, #0
	beq _0811F0FC
	b _0811F11C
	.align 2, 0
_0811F0EC: .4byte 0x0000FFFF
_0811F0F0: .4byte 0x000001FF
_0811F0F4: .4byte 0x08578D14
_0811F0F8:
	cmp r3, #0x15
	bne _0811F11C
_0811F0FC:
	adds r0, r2, r0
	ldr r2, [r0]
	movs r1, #0
	cmp r1, r4
	bhs _0811F124
_0811F106:
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811F120
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, r4
	blo _0811F106
	b _0811F124
_0811F11C:
	cmp r5, r4
	bhs _0811F124
_0811F120:
	movs r0, #0
	b _0811F126
_0811F124:
	movs r0, #1
_0811F126:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_0811F0C0

	thumb_func_start GetEasyChatWord
GetEasyChatWord: @ 0x0811F12C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	cmp r0, #0x13
	bgt _0811F144
	cmp r0, #0x12
	bge _0811F158
	cmp r0, #0
	beq _0811F148
	b _0811F164
_0811F144:
	cmp r0, #0x15
	bne _0811F164
_0811F148:
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #1
	ldr r1, _0811F154
	adds r0, r0, r1
	b _0811F176
	.align 2, 0
_0811F154: .4byte 0x082EA31C
_0811F158:
	lsls r0, r2, #3
	ldr r1, _0811F160
	adds r0, r0, r1
	b _0811F176
	.align 2, 0
_0811F160: .4byte 0x082EACC4
_0811F164:
	ldr r1, _0811F17C
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
_0811F176:
	pop {r1}
	bx r1
	.align 2, 0
_0811F17C: .4byte 0x08578D14
	thumb_func_end GetEasyChatWord

	thumb_func_start CopyEasyChatWord
CopyEasyChatWord: @ 0x0811F180
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r6, r1, #0x10
	lsrs r0, r6, #0x10
	adds r4, r0, #0
	bl sub_0811F0C0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F19C
	ldr r1, _0811F198
	b _0811F1AE
	.align 2, 0
_0811F198: .4byte 0x08579F30
_0811F19C:
	ldr r0, _0811F1B8
	cmp r4, r0
	beq _0811F1C0
	ldr r1, _0811F1BC
	ands r1, r4
	lsrs r0, r6, #0x19
	bl GetEasyChatWord
	adds r1, r0, #0
_0811F1AE:
	adds r0, r5, #0
	bl StringCopy
	b _0811F1C6
	.align 2, 0
_0811F1B8: .4byte 0x0000FFFF
_0811F1BC: .4byte 0x000001FF
_0811F1C0:
	movs r0, #0xff
	strb r0, [r5]
	adds r0, r5, #0
_0811F1C6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end CopyEasyChatWord

	thumb_func_start ConvertEasyChatWordsToString
ConvertEasyChatWordsToString: @ 0x0811F1CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sb, r3
	ldr r0, _0811F254
	adds r2, r2, r0
	lsrs r7, r2, #0x10
	movs r0, #0
	cmp r0, sb
	bhs _0811F23C
_0811F1EE:
	movs r6, #0
	adds r0, #1
	mov r8, r0
	cmp r6, r7
	bhs _0811F220
	ldr r2, _0811F258
_0811F1FA:
	ldrh r1, [r5]
	adds r0, r4, #0
	str r2, [sp]
	bl CopyEasyChatWord
	adds r4, r0, #0
	ldrh r0, [r5]
	ldr r2, [sp]
	cmp r0, r2
	beq _0811F214
	movs r0, #0
	strb r0, [r4]
	adds r4, #1
_0811F214:
	adds r5, #2
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, r7
	blo _0811F1FA
_0811F220:
	ldrh r1, [r5]
	adds r5, #2
	adds r0, r4, #0
	bl CopyEasyChatWord
	adds r4, r0, #0
	movs r0, #0xfe
	strb r0, [r4]
	adds r4, #1
	mov r1, r8
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, sb
	blo _0811F1EE
_0811F23C:
	subs r4, #1
	movs r0, #0xff
	strb r0, [r4]
	adds r0, r4, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0811F254: .4byte 0xFFFF0000
_0811F258: .4byte 0x0000FFFF
	thumb_func_end ConvertEasyChatWordsToString

	thumb_func_start GetEasyChatWordStringLength
GetEasyChatWordStringLength: @ 0x0811F25C
	push {r4, r5, lr}
	lsls r5, r0, #0x10
	lsrs r0, r5, #0x10
	adds r4, r0, #0
	ldr r0, _0811F270
	cmp r4, r0
	bne _0811F274
	movs r0, #0
	b _0811F29A
	.align 2, 0
_0811F270: .4byte 0x0000FFFF
_0811F274:
	adds r0, r4, #0
	bl sub_0811F0C0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811F290
	ldr r1, _0811F28C
	ands r1, r4
	lsrs r0, r5, #0x19
	bl GetEasyChatWord
	b _0811F292
	.align 2, 0
_0811F28C: .4byte 0x000001FF
_0811F290:
	ldr r0, _0811F2A0
_0811F292:
	bl StringLength
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_0811F29A:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0811F2A0: .4byte 0x08579F30
	thumb_func_end GetEasyChatWordStringLength

	thumb_func_start sub_0811F2A4
sub_0811F2A4: @ 0x0811F2A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	movs r7, #0
	cmp r7, r8
	bhs _0811F306
	subs r0, r1, #1
	lsls r0, r0, #0x10
	mov sb, r0
_0811F2CE:
	mov r0, sb
	lsrs r4, r0, #0x10
	movs r5, #0
	cmp r5, r1
	bhs _0811F2F4
_0811F2D8:
	ldrh r0, [r6]
	adds r6, #2
	str r1, [sp]
	bl GetEasyChatWordStringLength
	adds r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, [sp]
	cmp r5, r1
	blo _0811F2D8
_0811F2F4:
	cmp r4, sl
	bls _0811F2FC
	movs r0, #1
	b _0811F308
_0811F2FC:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, r8
	blo _0811F2CE
_0811F306:
	movs r0, #0
_0811F308:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_0811F2A4

	thumb_func_start sub_0811F318
	.globl GetRandomEasyChatWordFromGroup
	.set GetRandomEasyChatWordFromGroup, sub_0811F318
sub_0811F318: @ 0x0811F318
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl Random
	ldr r2, _0811F368
	lsls r1, r4, #3
	adds r1, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r1, #4]
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r4, #0
	beq _0811F346
	cmp r4, #0x15
	beq _0811F346
	cmp r4, #0x12
	beq _0811F346
	cmp r4, #0x13
	bne _0811F354
_0811F346:
	ldr r1, _0811F368
	lsls r0, r4, #3
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r1
	ldrh r2, [r0]
_0811F354:
	movs r0, #0x7f
	ands r0, r4
	lsls r0, r0, #9
	ldr r1, _0811F36C
	ands r2, r1
	orrs r0, r2
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0811F368: .4byte 0x08578D14
_0811F36C: .4byte 0x000001FF
	thumb_func_end sub_0811F318

	thumb_func_start sub_0811F370
sub_0811F370: @ 0x0811F370
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r0, #0
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_0811F044
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811F390
	ldr r0, _0811F38C
	b _0811F3A4
	.align 2, 0
_0811F38C: .4byte 0x0000FFFF
_0811F390:
	cmp r4, #0
	beq _0811F39C
	adds r0, r4, #0
	bl sub_0811F318
	b _0811F3A0
_0811F39C:
	bl sub_0811F5E8
_0811F3A0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_0811F3A4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811F370

	thumb_func_start sub_0811F3AC
sub_0811F3AC: @ 0x0811F3AC
	push {r4, r5, lr}
	ldr r0, _0811F3C0
	ldrh r0, [r0]
	cmp r0, #1
	beq _0811F3E4
	cmp r0, #1
	bgt _0811F3C4
	cmp r0, #0
	beq _0811F3CE
	b _0811F438
	.align 2, 0
_0811F3C0: .4byte 0x02037280
_0811F3C4:
	cmp r0, #2
	beq _0811F40C
	cmp r0, #3
	beq _0811F41C
	b _0811F438
_0811F3CE:
	ldr r0, _0811F3DC
	ldr r0, [r0]
	ldr r1, _0811F3E0
	adds r5, r0, r1
	movs r2, #2
	b _0811F426
	.align 2, 0
_0811F3DC: .4byte 0x03005AEC
_0811F3E0: .4byte 0x00002BB0
_0811F3E4:
	ldr r0, _0811F404
	ldr r0, [r0]
	ldr r1, _0811F408
	adds r5, r0, r1
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	movs r3, #0x12
	bl sub_0811F2A4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F424
	movs r2, #2
	movs r3, #3
	b _0811F428
	.align 2, 0
_0811F404: .4byte 0x03005AEC
_0811F408: .4byte 0x00002BBC
_0811F40C:
	ldr r0, _0811F414
	ldr r0, [r0]
	ldr r1, _0811F418
	b _0811F422
	.align 2, 0
_0811F414: .4byte 0x03005AEC
_0811F418: .4byte 0x00002BC8
_0811F41C:
	ldr r0, _0811F440
	ldr r0, [r0]
	ldr r1, _0811F444
_0811F422:
	adds r5, r0, r1
_0811F424:
	movs r2, #3
_0811F426:
	movs r3, #2
_0811F428:
	ldr r4, _0811F448
	adds r0, r4, #0
	adds r1, r5, #0
	bl ConvertEasyChatWordsToString
	adds r0, r4, #0
	bl ShowFieldAutoScrollMessage
_0811F438:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0811F440: .4byte 0x03005AEC
_0811F444: .4byte 0x00002BD4
_0811F448: .4byte 0x02021C7C
	thumb_func_end sub_0811F3AC

	thumb_func_start sub_0811F44C
sub_0811F44C: @ 0x0811F44C
	push {lr}
	bl Random
	movs r1, #1
	ands r1, r0
	movs r0, #0xc
	cmp r1, #0
	beq _0811F45E
	movs r0, #0xd
_0811F45E:
	bl sub_0811F370
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _0811F474
	bl CopyEasyChatWord
	pop {r0}
	bx r0
	.align 2, 0
_0811F474: .4byte 0x02021C54
	thumb_func_end sub_0811F44C

	thumb_func_start sub_0811F478
sub_0811F478: @ 0x0811F478
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x1b
	movs r1, #0xe0
	lsls r1, r1, #0x13
	ands r1, r0
	lsrs r1, r1, #0x18
	ldr r0, _0811F498
	ldr r0, [r0]
	ldr r3, _0811F49C
	adds r0, r0, r3
	adds r0, r0, r2
	ldrb r0, [r0]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	bx lr
	.align 2, 0
_0811F498: .4byte 0x03005AEC
_0811F49C: .4byte 0x00002E20
	thumb_func_end sub_0811F478

	thumb_func_start sub_0811F4A0
sub_0811F4A0: @ 0x0811F4A0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x20
	bhi _0811F4C4
	lsrs r3, r0, #0x1b
	movs r2, #7
	ands r2, r1
	ldr r0, _0811F4C8
	ldr r1, [r0]
	ldr r0, _0811F4CC
	adds r1, r1, r0
	adds r1, r1, r3
	movs r0, #1
	lsls r0, r2
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
_0811F4C4:
	pop {r0}
	bx r0
	.align 2, 0
_0811F4C8: .4byte 0x03005AEC
_0811F4CC: .4byte 0x00002E20
	thumb_func_end sub_0811F4A0

	thumb_func_start sub_0811F4D0
sub_0811F4D0: @ 0x0811F4D0
	push {r4, r5, lr}
	movs r4, #0
	movs r5, #0
_0811F4D6:
	adds r0, r4, #0
	bl sub_0811F478
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F4E8
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0811F4E8:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x20
	bls _0811F4D6
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811F4D0

	thumb_func_start sub_0811F4FC
sub_0811F4FC: @ 0x0811F4FC
	push {r4, r5, r6, lr}
	bl sub_0811F4D0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x21
	bne _0811F528
	b _0811F562
_0811F50C:
	adds r0, r5, #0
	bl sub_0811F4A0
	ldr r0, _0811F524
	ands r4, r0
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r0, r1, #0
	orrs r4, r0
	adds r0, r4, #0
	b _0811F564
	.align 2, 0
_0811F524: .4byte 0x000001FF
_0811F528:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x21
	subs r1, r1, r4
	bl __modsi3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r4, #0
_0811F53E:
	lsls r0, r4, #0x18
	lsrs r5, r0, #0x18
	adds r0, r5, #0
	bl sub_0811F478
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811F558
	cmp r6, #0
	beq _0811F50C
	subs r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
_0811F558:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x20
	bls _0811F53E
_0811F562:
	ldr r0, _0811F56C
_0811F564:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0811F56C: .4byte 0x0000FFFF
	thumb_func_end sub_0811F4FC

	thumb_func_start sub_0811F570
sub_0811F570: @ 0x0811F570
	push {r4, r5, lr}
	bl sub_0811F4D0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0811F594
	b _0811F5CA
_0811F580:
	ldr r0, _0811F590
	ands r4, r0
	movs r1, #0xa0
	lsls r1, r1, #6
	adds r0, r1, #0
	orrs r4, r0
	adds r0, r4, #0
	b _0811F5CC
	.align 2, 0
_0811F590: .4byte 0x000001FF
_0811F594:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r4, #0
_0811F5A8:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_0811F478
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F5C0
	cmp r5, #0
	beq _0811F580
	subs r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0811F5C0:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x20
	bls _0811F5A8
_0811F5CA:
	ldr r0, _0811F5D4
_0811F5CC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0811F5D4: .4byte 0x0000FFFF
	thumb_func_end sub_0811F570

	thumb_func_start sub_0811F5D8
sub_0811F5D8: @ 0x0811F5D8
	push {lr}
	bl IsNationalPokedexEnabled
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811F5D8

	thumb_func_start sub_0811F5E8
sub_0811F5E8: @ 0x0811F5E8
	push {r4, r5, r6, r7, lr}
	movs r0, #0
	bl EasyChat_GetNumWordsInGroup
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	bne _0811F608
	b _0811F652
_0811F5FA:
	ldrh r1, [r5]
	ldr r0, _0811F604
	ands r0, r1
	b _0811F654
	.align 2, 0
_0811F604: .4byte 0x000001FF
_0811F608:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _0811F65C
	ldr r5, [r0]
	ldrh r7, [r0, #4]
	movs r6, #0
	cmp r6, r7
	bhs _0811F652
_0811F626:
	ldrh r0, [r5]
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F646
	cmp r4, #0
	beq _0811F5FA
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0811F646:
	adds r5, #2
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, r7
	blo _0811F626
_0811F652:
	ldr r0, _0811F660
_0811F654:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0811F65C: .4byte 0x08578D14
_0811F660: .4byte 0x0000FFFF
	thumb_func_end sub_0811F5E8

	thumb_func_start InitEasyChatPhrases
InitEasyChatPhrases: @ 0x0811F664
	push {r4, r5, r6, r7, lr}
	ldr r4, _0811F770
	ldr r1, [r4]
	ldr r0, _0811F774
	adds r2, r1, r0
	ldr r0, _0811F778
	strh r0, [r2]
	ldr r5, _0811F77C
	adds r2, r1, r5
	ldr r0, _0811F780
	strh r0, [r2]
	ldr r0, _0811F784
	adds r2, r1, r0
	ldr r0, _0811F788
	strh r0, [r2]
	adds r5, #4
	adds r2, r1, r5
	ldr r0, _0811F78C
	strh r0, [r2]
	ldr r0, _0811F790
	adds r2, r1, r0
	ldr r0, _0811F794
	strh r0, [r2]
	adds r5, #8
	adds r2, r1, r5
	ldr r0, _0811F798
	strh r0, [r2]
	movs r0, #0xaf
	lsls r0, r0, #6
	adds r2, r1, r0
	ldr r0, _0811F79C
	strh r0, [r2]
	adds r5, #4
	adds r2, r1, r5
	ldr r0, _0811F7A0
	strh r0, [r2]
	ldr r0, _0811F7A4
	adds r2, r1, r0
	ldr r0, _0811F7A8
	strh r0, [r2]
	ldr r2, _0811F7AC
	adds r0, r1, r2
	ldr r3, _0811F7B0
	strh r3, [r0]
	adds r5, #6
	adds r2, r1, r5
	ldr r0, _0811F7B4
	strh r0, [r2]
	ldr r2, _0811F7B8
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #4
	adds r2, r1, r5
	ldr r0, _0811F7BC
	strh r0, [r2]
	ldr r2, _0811F7C0
	adds r0, r1, r2
	ldr r2, _0811F7C4
	strh r2, [r0]
	adds r5, #4
	adds r0, r1, r5
	strh r2, [r0]
	ldr r2, _0811F7C8
	adds r0, r1, r2
	strh r3, [r0]
	adds r5, #4
	adds r2, r1, r5
	ldr r0, _0811F7CC
	strh r0, [r2]
	ldr r2, _0811F7D0
	adds r0, r1, r2
	adds r3, #5
	strh r3, [r0]
	adds r5, #4
	adds r2, r1, r5
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r2]
	ldr r0, _0811F7D4
	adds r2, r1, r0
	movs r0, #0xc6
	lsls r0, r0, #3
	strh r0, [r2]
	adds r5, #4
	adds r2, r1, r5
	ldr r0, _0811F7D8
	strh r0, [r2]
	ldr r0, _0811F7DC
	adds r1, r1, r0
	strh r3, [r1]
	movs r3, #0
	adds r7, r4, #0
	ldr r6, _0811F7E0
	movs r2, #1
	rsbs r2, r2, #0
	adds r5, r2, #0
_0811F724:
	movs r2, #0
	lsls r0, r3, #3
	adds r0, r0, r3
	lsls r4, r0, #2
_0811F72C:
	ldr r1, [r7]
	lsls r0, r2, #1
	adds r0, r0, r4
	adds r1, r1, r6
	adds r1, r1, r0
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #8
	bls _0811F72C
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0xf
	bls _0811F724
	movs r3, #0
	ldr r4, _0811F770
	ldr r2, _0811F7E4
	movs r1, #0
_0811F758:
	ldr r0, [r4]
	adds r0, r0, r2
	adds r0, r0, r3
	strb r1, [r0]
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x3f
	bls _0811F758
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811F770: .4byte 0x03005AEC
_0811F774: .4byte 0x00002BB0
_0811F778: .4byte 0x0000020E
_0811F77C: .4byte 0x00002BB2
_0811F780: .4byte 0x00001228
_0811F784: .4byte 0x00002BB4
_0811F788: .4byte 0x0000020B
_0811F78C: .4byte 0x0000101F
_0811F790: .4byte 0x00002BBC
_0811F794: .4byte 0x00000603
_0811F798: .4byte 0x00001405
_0811F79C: .4byte 0x00000C02
_0811F7A0: .4byte 0x00000E0E
_0811F7A4: .4byte 0x00002BC4
_0811F7A8: .4byte 0x00000803
_0811F7AC: .4byte 0x00002BC6
_0811F7B0: .4byte 0x00000C01
_0811F7B4: .4byte 0x0000123C
_0811F7B8: .4byte 0x00002BCA
_0811F7BC: .4byte 0x0000FFFF
_0811F7C0: .4byte 0x00002BCE
_0811F7C4: .4byte 0x00000607
_0811F7C8: .4byte 0x00002BD2
_0811F7CC: .4byte 0x0000121B
_0811F7D0: .4byte 0x00002BD6
_0811F7D4: .4byte 0x00002BDA
_0811F7D8: .4byte 0x0000121F
_0811F7DC: .4byte 0x00002BDE
_0811F7E0: .4byte 0x00002BE0
_0811F7E4: .4byte 0x00002E20
	thumb_func_end InitEasyChatPhrases

	thumb_func_start sub_0811F7E8
sub_0811F7E8: @ 0x0811F7E8
	push {r4, lr}
	ldr r4, _0811F804
	ldr r0, _0811F808
	bl Alloc
	str r0, [r4]
	cmp r0, #0
	beq _0811F80C
	bl sub_0811F830
	bl sub_0811F9C8
	movs r0, #1
	b _0811F80E
	.align 2, 0
_0811F804: .4byte 0x02039DEC
_0811F808: .4byte 0x00002CE8
_0811F80C:
	movs r0, #0
_0811F80E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0811F7E8

	thumb_func_start sub_0811F814
sub_0811F814: @ 0x0811F814
	push {r4, lr}
	ldr r4, _0811F82C
	ldr r0, [r4]
	cmp r0, #0
	beq _0811F826
	bl Free
	movs r0, #0
	str r0, [r4]
_0811F826:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0811F82C: .4byte 0x02039DEC
	thumb_func_end sub_0811F814

	thumb_func_start sub_0811F830
sub_0811F830: @ 0x0811F830
	push {r4, r5, lr}
	ldr r4, _0811F8FC
	ldr r0, [r4]
	movs r5, #0
	strh r5, [r0]
	movs r0, #0
	bl GetNationalPokedexCount
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0811F858
	ldr r0, [r4]
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r0, #2
	adds r0, r0, r1
	strh r5, [r0]
_0811F858:
	movs r3, #1
_0811F85A:
	ldr r0, [r4]
	ldrh r2, [r0]
	adds r1, r2, #1
	strh r1, [r0]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0xf
	adds r0, #2
	adds r0, r0, r2
	strh r3, [r0]
	adds r3, #1
	cmp r3, #0x10
	ble _0811F85A
	ldr r0, _0811F900
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F8B4
	ldr r0, _0811F8FC
	ldr r2, [r0]
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r3, r2, #2
	adds r0, r3, r0
	movs r1, #0x11
	strh r1, [r0]
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r0, r3, r0
	movs r1, #0x12
	strh r1, [r0]
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xf
	adds r3, r3, r0
	movs r0, #0x13
	strh r0, [r3]
_0811F8B4:
	ldr r0, _0811F904
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811F8D6
	ldr r0, _0811F8FC
	ldr r0, [r0]
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r0, #2
	adds r0, r0, r1
	movs r1, #0x14
	strh r1, [r0]
_0811F8D6:
	bl IsNationalPokedexEnabled
	cmp r0, #0
	beq _0811F8F4
	ldr r0, _0811F8FC
	ldr r0, [r0]
	ldrh r1, [r0]
	adds r2, r1, #1
	strh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0xf
	adds r0, #2
	adds r0, r0, r1
	movs r1, #0x15
	strh r1, [r0]
_0811F8F4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0811F8FC: .4byte 0x02039DEC
_0811F900: .4byte 0x00000864
_0811F904: .4byte 0x00000866
	thumb_func_end sub_0811F830

	thumb_func_start sub_0811F908
sub_0811F908: @ 0x0811F908
	ldr r0, _0811F910
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0811F910: .4byte 0x02039DEC
	thumb_func_end sub_0811F908

	thumb_func_start sub_0811F914
sub_0811F914: @ 0x0811F914
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _0811F930
	ldr r1, [r0]
	ldrh r0, [r1]
	cmp r2, r0
	bhs _0811F934
	lsls r0, r2, #1
	adds r1, #2
	adds r1, r1, r0
	ldrb r0, [r1]
	b _0811F936
	.align 2, 0
_0811F930: .4byte 0x02039DEC
_0811F934:
	movs r0, #0x16
_0811F936:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0811F914

	thumb_func_start unref_sub_811F3E0
unref_sub_811F3E0: @ 0x0811F93C
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	ldr r0, _0811F97C
	lsrs r1, r1, #0x16
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl StringCopy
	adds r1, r0, #0
	subs r4, r1, r4
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	cmp r0, r5
	bhs _0811F970
	movs r2, #0
_0811F962:
	strb r2, [r1]
	adds r1, #1
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	blo _0811F962
_0811F970:
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0811F97C: .4byte 0x08579ED8
	thumb_func_end unref_sub_811F3E0

	thumb_func_start GetEasyChatWordGroupName
GetEasyChatWordGroupName: @ 0x0811F980
	lsls r0, r0, #0x18
	ldr r1, _0811F98C
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0811F98C: .4byte 0x08579ED8
	thumb_func_end GetEasyChatWordGroupName

	thumb_func_start CopyEasyChatWordPadded
CopyEasyChatWordPadded: @ 0x0811F990
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r5, r2, #0x10
	bl CopyEasyChatWord
	adds r1, r0, #0
	subs r4, r1, r4
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	cmp r0, r5
	bhs _0811F9BC
	movs r2, #0
_0811F9AE:
	strb r2, [r1]
	adds r1, #1
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r5
	blo _0811F9AE
_0811F9BC:
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r1, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end CopyEasyChatWordPadded

	thumb_func_start sub_0811F9C8
sub_0811F9C8: @ 0x0811F9C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	movs r3, #0
_0811F9D6:
	ldr r2, _0811FA18
	lsls r1, r3, #3
	adds r0, r2, #4
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp]
	adds r1, r1, r2
	ldr r7, [r1]
	ldr r0, _0811FA1C
	ldr r1, [r0]
	lsls r2, r3, #1
	adds r1, #0x2e
	adds r1, r1, r2
	movs r0, #0
	strh r0, [r1]
	mov sl, r0
	movs r1, #0
	str r2, [sp, #4]
	adds r0, r3, #1
	str r0, [sp, #8]
	ldr r2, [sp]
	cmp r1, r2
	bge _0811FA88
_0811FA04:
	ldrh r0, [r7]
	ldr r2, _0811FA20
	cmp r0, r2
	bne _0811FA54
	adds r7, #2
	ldrh r4, [r7]
	adds r7, #2
	adds r0, r1, #1
	adds r1, r0, r4
	b _0811FA56
	.align 2, 0
_0811FA18: .4byte 0x08579D04
_0811FA1C: .4byte 0x02039DEC
_0811FA20: .4byte 0x0000FFFF
_0811FA24:
	ldr r0, _0811FA50
	ldr r2, [r0]
	mov r0, sl
	lsls r1, r0, #1
	lsls r0, r3, #4
	subs r0, r0, r3
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x88
	adds r0, r0, r1
	ldrh r1, [r5]
	strh r1, [r0]
	movs r0, #1
	add sl, r0
	adds r2, #0x2e
	ldr r0, [sp, #4]
	adds r2, r2, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	b _0811FA7E
	.align 2, 0
_0811FA50: .4byte 0x02039DEC
_0811FA54:
	movs r4, #1
_0811FA56:
	movs r6, #0
	adds r1, #1
	mov sb, r1
	lsls r2, r4, #1
	mov r8, r2
	cmp r6, r4
	bge _0811FA7E
	adds r5, r7, #0
_0811FA66:
	ldrh r0, [r5]
	str r3, [sp, #0xc]
	bl sub_0811FDB4
	lsls r0, r0, #0x18
	ldr r3, [sp, #0xc]
	cmp r0, #0
	bne _0811FA24
	adds r5, #2
	adds r6, #1
	cmp r6, r4
	blt _0811FA66
_0811FA7E:
	add r7, r8
	mov r1, sb
	ldr r0, [sp]
	cmp r1, r0
	blt _0811FA04
_0811FA88:
	ldr r3, [sp, #8]
	cmp r3, #0x2c
	ble _0811F9D6
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0811F9C8

	thumb_func_start sub_0811FAA0
sub_0811FAA0: @ 0x0811FAA0
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r0, #0
	bne _0811FAB2
	adds r0, r1, #0
	bl sub_0811FB1C
	b _0811FAB8
_0811FAB2:
	adds r0, r1, #0
	bl sub_0811FC10
_0811FAB8:
	ldr r1, _0811FAC8
	ldr r1, [r1]
	ldr r2, _0811FACC
	adds r1, r1, r2
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0811FAC8: .4byte 0x02039DEC
_0811FACC: .4byte 0x00002CE4
	thumb_func_end sub_0811FAA0

	thumb_func_start sub_0811FAD0
sub_0811FAD0: @ 0x0811FAD0
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r0, _0811FAF0
	ldr r1, [r0]
	ldr r3, _0811FAF4
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r2, r0
	bhs _0811FAFC
	lsls r0, r2, #1
	ldr r2, _0811FAF8
	adds r1, r1, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	b _0811FAFE
	.align 2, 0
_0811FAF0: .4byte 0x02039DEC
_0811FAF4: .4byte 0x00002CE4
_0811FAF8: .4byte 0x00002AE4
_0811FAFC:
	ldr r0, _0811FB04
_0811FAFE:
	pop {r1}
	bx r1
	.align 2, 0
_0811FB04: .4byte 0x0000FFFF
	thumb_func_end sub_0811FAD0

	thumb_func_start sub_0811FB08
sub_0811FB08: @ 0x0811FB08
	ldr r0, _0811FB14
	ldr r0, [r0]
	ldr r1, _0811FB18
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_0811FB14: .4byte 0x02039DEC
_0811FB18: .4byte 0x00002CE4
	thumb_func_end sub_0811FB08

	thumb_func_start sub_0811FB1C
sub_0811FB1C: @ 0x0811FB1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldr r1, _0811FB94
	lsls r0, r2, #3
	adds r0, r0, r1
	ldrh r3, [r0, #4]
	mov r8, r3
	cmp r2, #0
	beq _0811FB44
	cmp r2, #0x15
	beq _0811FB44
	cmp r2, #0x12
	beq _0811FB44
	cmp r2, #0x13
	bne _0811FBA4
_0811FB44:
	lsls r0, r2, #3
	adds r0, r0, r1
	ldr r1, [r0]
	movs r7, #0
	movs r5, #0
	cmp r5, r8
	bhs _0811FBF0
	movs r0, #0x7f
	ands r0, r2
	lsls r0, r0, #9
	mov sb, r0
	adds r4, r1, #0
	lsls r6, r2, #0x18
_0811FB5E:
	ldrh r0, [r4]
	lsrs r1, r6, #0x18
	bl sub_0811FCB8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811FB88
	ldr r0, _0811FB98
	ldr r2, [r0]
	lsls r0, r5, #1
	ldr r1, _0811FB9C
	adds r2, r2, r1
	adds r2, r2, r0
	ldrh r0, [r4]
	ldr r3, _0811FBA0
	adds r1, r3, #0
	ands r0, r1
	mov r1, sb
	orrs r0, r1
	strh r0, [r2]
	adds r5, #1
_0811FB88:
	adds r4, #2
	adds r7, #1
	cmp r7, r8
	blo _0811FB5E
	b _0811FBF0
	.align 2, 0
_0811FB94: .4byte 0x08578D14
_0811FB98: .4byte 0x02039DEC
_0811FB9C: .4byte 0x00002AE4
_0811FBA0: .4byte 0x000001FF
_0811FBA4:
	ldr r1, [r0]
	movs r7, #0
	movs r5, #0
	cmp r5, r8
	bhs _0811FBF0
	movs r0, #0x7f
	ands r0, r2
	lsls r0, r0, #9
	mov sl, r0
	adds r6, r1, #0
	lsls r2, r2, #0x18
	mov sb, r2
_0811FBBC:
	ldrh r4, [r6, #4]
	adds r0, r4, #0
	mov r2, sb
	lsrs r1, r2, #0x18
	bl sub_0811FCB8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811FBE8
	ldr r0, _0811FC04
	ldr r1, [r0]
	lsls r0, r5, #1
	ldr r3, _0811FC08
	adds r1, r1, r3
	adds r1, r1, r0
	ldr r2, _0811FC0C
	adds r0, r2, #0
	ands r4, r0
	mov r3, sl
	orrs r4, r3
	strh r4, [r1]
	adds r5, #1
_0811FBE8:
	adds r6, #0xc
	adds r7, #1
	cmp r7, r8
	blo _0811FBBC
_0811FBF0:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0811FC04: .4byte 0x02039DEC
_0811FC08: .4byte 0x00002AE4
_0811FC0C: .4byte 0x000001FF
	thumb_func_end sub_0811FB1C

	thumb_func_start sub_0811FC10
sub_0811FC10: @ 0x0811FC10
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	movs r4, #0
	movs r6, #0
	ldr r3, _0811FC78
	ldr r0, [r3]
	lsls r5, r1, #1
	adds r0, #0x2e
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r6, r0
	bhs _0811FC6C
	mov r8, r3
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r7, r0, #4
	ldr r0, _0811FC7C
	mov ip, r0
_0811FC3A:
	mov r0, r8
	ldr r3, [r0]
	adds r1, r6, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #1
	mov r0, ip
	adds r2, r3, r0
	adds r2, r2, r1
	lsls r1, r4, #1
	adds r1, r1, r7
	adds r0, r3, #0
	adds r0, #0x88
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r3, #0x2e
	adds r3, r3, r5
	ldrh r3, [r3]
	cmp r4, r3
	blo _0811FC3A
_0811FC6C:
	adds r0, r6, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0811FC78: .4byte 0x02039DEC
_0811FC7C: .4byte 0x00002AE4
	thumb_func_end sub_0811FC10

	thumb_func_start sub_0811FC80
sub_0811FC80: @ 0x0811FC80
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r2, #0
	ldr r0, _0811FCA4
	ldr r0, [r0]
	ldrh r1, [r0]
	cmp r2, r1
	bge _0811FCB0
	adds r4, r3, #0
	adds r3, r1, #0
	adds r1, r0, #2
_0811FC98:
	ldrh r0, [r1]
	cmp r0, r4
	bne _0811FCA8
	movs r0, #1
	b _0811FCB2
	.align 2, 0
_0811FCA4: .4byte 0x02039DEC
_0811FCA8:
	adds r1, #2
	adds r2, #1
	cmp r2, r3
	blt _0811FC98
_0811FCB0:
	movs r0, #0
_0811FCB2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0811FC80

	thumb_func_start sub_0811FCB8
sub_0811FCB8: @ 0x0811FCB8
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r2, #0x15
	bhi _0811FD6E
	lsls r0, r2, #2
	ldr r1, _0811FCD0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0811FCD0: .4byte 0x0811FCD4
_0811FCD4: @ jump table
	.4byte _0811FD2C @ case 0
	.4byte _0811FD6E @ case 1
	.4byte _0811FD6E @ case 2
	.4byte _0811FD6E @ case 3
	.4byte _0811FD6E @ case 4
	.4byte _0811FD6E @ case 5
	.4byte _0811FD6E @ case 6
	.4byte _0811FD6E @ case 7
	.4byte _0811FD6E @ case 8
	.4byte _0811FD6E @ case 9
	.4byte _0811FD6E @ case 10
	.4byte _0811FD6E @ case 11
	.4byte _0811FD6E @ case 12
	.4byte _0811FD6E @ case 13
	.4byte _0811FD6E @ case 14
	.4byte _0811FD6E @ case 15
	.4byte _0811FD6E @ case 16
	.4byte _0811FD6E @ case 17
	.4byte _0811FD5C @ case 18
	.4byte _0811FD5C @ case 19
	.4byte _0811FD60 @ case 20
	.4byte _0811FD42 @ case 21
_0811FD2C:
	adds r0, r4, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811FD80
_0811FD42:
	adds r0, r4, #0
	bl GetFooterOptionXOffset
	cmp r0, #0
	beq _0811FD5C
	adds r0, r4, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl GetSetPokedexFlag
_0811FD5C:
	movs r0, #1
	b _0811FD80
_0811FD60:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_0811F478
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811FD80
_0811FD6E:
	ldr r1, _0811FD88
	lsls r0, r2, #3
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #8]
_0811FD80:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0811FD88: .4byte 0x08578D14
	thumb_func_end sub_0811FCB8

	thumb_func_start GetFooterOptionXOffset
GetFooterOptionXOffset: @ 0x0811FD8C
	push {lr}
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r2, #0
	ldr r1, _0811FDA0
_0811FD96:
	ldrh r0, [r1]
	cmp r0, r3
	bne _0811FDA4
	movs r0, #1
	b _0811FDAE
	.align 2, 0
_0811FDA0: .4byte 0x08579F34
_0811FDA4:
	adds r1, #2
	adds r2, #1
	cmp r2, #0
	beq _0811FD96
	movs r0, #0
_0811FDAE:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetFooterOptionXOffset

	thumb_func_start sub_0811FDB4
sub_0811FDB4: @ 0x0811FDB4
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x19
	lsls r0, r0, #7
	lsrs r4, r0, #0x17
	adds r0, r5, #0
	bl sub_0811FC80
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811FDD8
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_0811FCB8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0811FDDA
_0811FDD8:
	movs r0, #0
_0811FDDA:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_0811FDB4

	thumb_func_start InitializeEasyChatWordArray
InitializeEasyChatWordArray: @ 0x0811FDE0
	push {lr}
	adds r2, r0, #0
	lsls r1, r1, #0x10
	ldr r0, _0811FE08
	adds r1, r1, r0
	lsrs r0, r1, #0x10
	ldr r1, _0811FE0C
	cmp r0, r1
	beq _0811FE02
	adds r3, r1, #0
_0811FDF4:
	strh r3, [r2]
	adds r2, #2
	subs r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bne _0811FDF4
_0811FE02:
	pop {r0}
	bx r0
	.align 2, 0
_0811FE08: .4byte 0xFFFF0000
_0811FE0C: .4byte 0x0000FFFF
	thumb_func_end InitializeEasyChatWordArray

	thumb_func_start sub_0811FE10
sub_0811FE10: @ 0x0811FE10
	push {lr}
	bl GetQuestionnaireWordsPtr
	ldr r1, _0811FE28
	adds r2, r1, #0
	adds r1, r0, #6
_0811FE1C:
	strh r2, [r1]
	subs r1, #2
	cmp r1, r0
	bge _0811FE1C
	pop {r0}
	bx r0
	.align 2, 0
_0811FE28: .4byte 0x0000FFFF
	thumb_func_end sub_0811FE10
