.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start HandleAction_UseItem
HandleAction_UseItem: @ 0x0803E54C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0803E5AC
	ldr r2, _0803E5B0
	ldr r1, _0803E5B4
	ldr r0, _0803E5B8
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	strb r0, [r4]
	ldr r0, _0803E5BC
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803E5C0
	strh r1, [r0]
	ldrb r0, [r4]
	bl ClearFuryCutterDestinyBondGrudge
	ldr r5, _0803E5C4
	ldr r2, _0803E5C8
	ldrb r1, [r4]
	lsls r1, r1, #9
	adds r0, r2, #1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r2, #2
	adds r1, r1, r2
	ldrb r0, [r1]
	lsls r0, r0, #8
	orrs r3, r0
	strh r3, [r5]
	cmp r3, #0xc
	bhi _0803E5D8
	ldr r2, _0803E5CC
	ldr r1, _0803E5D0
	ldrh r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _0803E5D4
	mov sl, r0
	b _0803E836
	.align 2, 0
_0803E5AC: .4byte 0x02023EAF
_0803E5B0: .4byte 0x02023EB0
_0803E5B4: .4byte 0x02023D22
_0803E5B8: .4byte 0x02023D26
_0803E5BC: .4byte 0x02022AC8
_0803E5C0: .4byte 0x02022ACA
_0803E5C4: .4byte 0x02023EAC
_0803E5C8: .4byte 0x02023508
_0803E5CC: .4byte 0x02023EB8
_0803E5D0: .4byte 0x0828A290
_0803E5D4: .4byte 0x02023D27
_0803E5D8:
	adds r0, r3, #0
	subs r0, #0x50
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0803E600
	ldr r0, _0803E5F4
	ldr r1, _0803E5F8
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, _0803E5FC
	mov sl, r1
	b _0803E836
	.align 2, 0
_0803E5F4: .4byte 0x02023EB8
_0803E5F8: .4byte 0x0828A2DC
_0803E5FC: .4byte 0x02023D27
_0803E600:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E628
	ldr r0, _0803E61C
	ldr r1, _0803E620
	ldr r1, [r1]
	str r1, [r0]
	ldr r2, _0803E624
	mov sl, r2
	b _0803E836
	.align 2, 0
_0803E61C: .4byte 0x02023EB8
_0803E620: .4byte 0x0828A2C4
_0803E624: .4byte 0x02023D27
_0803E628:
	ldr r3, _0803E660
	ldrb r0, [r4]
	strb r0, [r3, #0x17]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x19
	ldr r2, _0803E664
	ldr r1, [r2]
	adds r0, r0, r1
	adds r0, #0xc4
	ldrb r0, [r0]
	subs r0, #1
	mov r8, r4
	ldr r1, _0803E668
	mov sb, r1
	ldr r6, _0803E66C
	mov ip, r3
	adds r7, r2, #0
	ldr r2, _0803E670
	mov sl, r2
	cmp r0, #4
	bls _0803E654
	b _0803E81E
_0803E654:
	lsls r0, r0, #2
	ldr r1, _0803E674
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803E660: .4byte 0x02024118
_0803E664: .4byte 0x02024140
_0803E668: .4byte 0x02023EB8
_0803E66C: .4byte 0x0828A2C4
_0803E670: .4byte 0x02023D27
_0803E674: .4byte 0x0803E678
_0803E678: @ jump table
	.4byte _0803E81E @ case 0
	.4byte _0803E81E @ case 1
	.4byte _0803E68C @ case 2
	.4byte _0803E720 @ case 3
	.4byte _0803E7F0 @ case 4
_0803E68C:
	ldr r5, _0803E6C4
	movs r0, #0
	strb r0, [r5, #5]
	ldr r2, _0803E6C8
	ldrb r0, [r2]
	lsrs r0, r0, #1
	ldr r1, [r7]
	adds r0, r0, r1
	adds r0, #0xc6
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _0803E6D8
	movs r0, #0x3e
	ands r0, r1
	ldr r1, _0803E6CC
	mov sb, r1
	ldr r6, _0803E6D0
	ldr r2, _0803E6D4
	mov sl, r2
	cmp r0, #0
	bne _0803E6BE
	b _0803E81E
_0803E6BE:
	movs r0, #5
	strb r0, [r5, #5]
	b _0803E81E
	.align 2, 0
_0803E6C4: .4byte 0x02023FD6
_0803E6C8: .4byte 0x02023EAF
_0803E6CC: .4byte 0x02023EB8
_0803E6D0: .4byte 0x0828A2C4
_0803E6D4: .4byte 0x02023D27
_0803E6D8:
	ldr r0, _0803E714
	mov sb, r0
	ldr r6, _0803E718
	ldr r1, _0803E71C
	mov sl, r1
	mov r4, r8
	adds r3, r7, #0
	adds r2, r5, #0
_0803E6E8:
	ldrb r1, [r4]
	lsrs r1, r1, #1
	ldr r0, [r3]
	adds r1, r1, r0
	adds r1, #0xc6
	ldrb r0, [r1]
	lsrs r0, r0, #1
	strb r0, [r1]
	ldrb r0, [r2, #5]
	adds r0, #1
	strb r0, [r2, #5]
	ldrb r0, [r4]
	lsrs r0, r0, #1
	ldr r1, [r3]
	adds r0, r0, r1
	adds r0, #0xc6
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803E6E8
	b _0803E81E
	.align 2, 0
_0803E714: .4byte 0x02023EB8
_0803E718: .4byte 0x0828A2C4
_0803E71C: .4byte 0x02023D27
_0803E720:
	ldr r3, _0803E754
	movs r0, #4
	strb r0, [r3, #5]
	ldr r2, _0803E758
	ldrb r0, [r2]
	lsrs r0, r0, #1
	ldr r1, [r7]
	adds r0, r0, r1
	adds r6, r0, #0
	adds r6, #0xc6
	ldrb r1, [r6]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r8, r2
	cmp r5, #0
	beq _0803E768
	movs r0, #5
	strb r0, [r3, #5]
	ldr r2, _0803E75C
	mov sb, r2
	ldr r6, _0803E760
	ldr r0, _0803E764
	mov sl, r0
	b _0803E81E
	.align 2, 0
_0803E754: .4byte 0x02023FD6
_0803E758: .4byte 0x02023EAF
_0803E75C: .4byte 0x02023EB8
_0803E760: .4byte 0x0828A2C4
_0803E764: .4byte 0x02023D27
_0803E768:
	ldr r3, _0803E7DC
	movs r4, #0xfd
	strb r4, [r3]
	movs r0, #5
	strb r0, [r3, #1]
	movs r2, #1
	strb r2, [r3, #2]
	movs r0, #0xff
	strb r0, [r3, #3]
	ldr r1, _0803E7E0
	strb r4, [r1]
	strb r5, [r1, #1]
	movs r0, #0xd2
	strb r0, [r1, #2]
	strb r5, [r1, #3]
	subs r0, #0xd3
	strb r0, [r1, #4]
	ldrb r0, [r6]
	ands r2, r0
	ldr r1, _0803E7E4
	mov sb, r1
	ldr r6, _0803E7E8
	ldr r0, _0803E7EC
	mov sl, r0
	cmp r2, #0
	bne _0803E7CC
	mov r5, r8
	adds r4, r7, #0
	adds r2, r3, #0
_0803E7A2:
	ldrb r1, [r5]
	lsrs r1, r1, #1
	ldr r0, [r4]
	adds r1, r1, r0
	adds r1, #0xc6
	ldrb r0, [r1]
	lsrs r0, r0, #1
	strb r0, [r1]
	ldrb r0, [r2, #2]
	adds r0, #1
	strb r0, [r2, #2]
	ldrb r0, [r5]
	lsrs r0, r0, #1
	ldr r1, [r4]
	adds r0, r0, r1
	adds r0, #0xc6
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803E7A2
_0803E7CC:
	ldrb r0, [r3, #2]
	adds r0, #0xe
	movs r1, #0
	mov r2, ip
	strb r0, [r2, #0x10]
	strb r1, [r2, #0x11]
	b _0803E81E
	.align 2, 0
_0803E7DC: .4byte 0x02022C0C
_0803E7E0: .4byte 0x02022C1C
_0803E7E4: .4byte 0x02023EB8
_0803E7E8: .4byte 0x0828A2C4
_0803E7EC: .4byte 0x02023D27
_0803E7F0:
	ldr r0, _0803E804
	ldr r1, [r0]
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0803E80C
	ldr r1, _0803E808
	movs r0, #2
	strb r0, [r1, #5]
	b _0803E810
	.align 2, 0
_0803E804: .4byte 0x02022C90
_0803E808: .4byte 0x02023FD6
_0803E80C:
	ldr r0, _0803E84C
	strb r1, [r0, #5]
_0803E810:
	ldr r0, _0803E850
	mov r8, r0
	ldr r1, _0803E854
	mov sb, r1
	ldr r6, _0803E858
	ldr r2, _0803E85C
	mov sl, r2
_0803E81E:
	mov r1, r8
	ldrb r0, [r1]
	lsrs r0, r0, #1
	ldr r1, [r7]
	adds r0, r0, r1
	adds r0, #0xc4
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	mov r2, sb
	str r0, [r2]
_0803E836:
	movs r0, #0xa
	mov r1, sl
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E84C: .4byte 0x02023FD6
_0803E850: .4byte 0x02023EAF
_0803E854: .4byte 0x02023EB8
_0803E858: .4byte 0x0828A2C4
_0803E85C: .4byte 0x02023D27
	thumb_func_end HandleAction_UseItem


