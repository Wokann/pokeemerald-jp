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


	thumb_func_start TryRunFromBattle
TryRunFromBattle: @ 0x0803E860
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r7, #0
	ldr r1, _0803E88C
	movs r0, #0x58
	muls r0, r5, r0
	adds r1, r0, r1
	ldrh r0, [r1, #0x2e]
	cmp r0, #0xaf
	bne _0803E894
	ldr r1, _0803E890
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #7]
	b _0803E89E
	.align 2, 0
_0803E88C: .4byte 0x02023D28
_0803E890: .4byte 0x020240A8
_0803E894:
	ldrh r0, [r1, #0x2e]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0803E89E:
	ldr r0, _0803E8CC
	strb r5, [r0]
	cmp r1, #0x25
	bne _0803E8DC
	ldr r2, _0803E8D0
	ldr r1, _0803E8D4
	movs r0, #0x58
	muls r0, r5, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x2e]
	strh r0, [r2]
	ldr r0, _0803E8D8
	lsls r2, r5, #4
	adds r2, r2, r0
	ldrb r1, [r2, #1]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #1]
	b _0803E9B0
	.align 2, 0
_0803E8CC: .4byte 0x02023EB3
_0803E8D0: .4byte 0x02023EAC
_0803E8D4: .4byte 0x02023D28
_0803E8D8: .4byte 0x02023FE0
_0803E8DC:
	ldr r0, _0803E968
	mov sl, r0
	movs r2, #0x58
	mov sb, r2
	mov r0, sb
	muls r0, r5, r0
	add r0, sl
	mov r8, r0
	adds r0, #0x20
	ldrb r6, [r0]
	cmp r6, #0x32
	bne _0803E99C
	bl CurrentBattlePyramidLocation
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803E978
	ldr r4, _0803E96C
	ldr r1, [r4]
	adds r1, #0x6c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	bl GetPyramidRunMultiplier
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	mov r2, r8
	ldrh r0, [r2, #6]
	muls r0, r1, r0
	movs r2, #1
	adds r1, r5, #0
	eors r1, r2
	mov r2, sb
	muls r2, r1, r2
	adds r1, r2, #0
	add r1, sl
	ldrh r1, [r1, #6]
	bl __divsi3
	ldr r1, [r4]
	adds r1, #0x6c
	ldrb r2, [r1]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl Random
	movs r1, #0xff
	ands r1, r0
	cmp r4, r1
	bhi _0803E94C
	b _0803EA52
_0803E94C:
	ldr r0, _0803E970
	strb r6, [r0]
	ldr r0, _0803E974
	lsls r2, r5, #4
	adds r2, r2, r0
	ldrb r1, [r2, #1]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	b _0803E9B0
	.align 2, 0
_0803E968: .4byte 0x02023D28
_0803E96C: .4byte 0x02024140
_0803E970: .4byte 0x02023EAE
_0803E974: .4byte 0x02023FE0
_0803E978:
	ldr r0, _0803E994
	strb r6, [r0]
	ldr r0, _0803E998
	lsls r2, r5, #4
	adds r2, r2, r0
	ldrb r1, [r2, #1]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	b _0803E9B0
	.align 2, 0
_0803E994: .4byte 0x02023EAE
_0803E998: .4byte 0x02023FE0
_0803E99C:
	ldr r1, _0803E9B8
	ldr r2, [r1]
	ldr r0, _0803E9BC
	ands r0, r2
	cmp r0, #0
	beq _0803E9C0
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _0803E9C0
_0803E9B0:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	b _0803EA52
	.align 2, 0
_0803E9B8: .4byte 0x02022C90
_0803E9BC: .4byte 0x043F0100
_0803E9C0:
	ldr r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0803EA46
	bl CurrentBattlePyramidLocation
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803E9FC
	bl GetPyramidRunMultiplier
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r4, _0803E9F8
	movs r3, #0x58
	adds r0, r5, #0
	muls r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0, #6]
	muls r0, r1, r0
	movs r2, #1
	adds r1, r5, #0
	eors r1, r2
	muls r1, r3, r1
	adds r1, r1, r4
	b _0803EA1A
	.align 2, 0
_0803E9F8: .4byte 0x02023D28
_0803E9FC:
	ldr r3, _0803EA74
	movs r2, #0x58
	adds r0, r5, #0
	muls r0, r2, r0
	adds r4, r0, r3
	movs r1, #1
	adds r0, r5, #0
	eors r0, r1
	muls r0, r2, r0
	adds r1, r0, r3
	ldrh r0, [r4, #6]
	ldrh r2, [r1, #6]
	cmp r0, r2
	bhs _0803EA40
	lsls r0, r0, #7
_0803EA1A:
	ldrh r1, [r1, #6]
	bl __divsi3
	ldr r1, _0803EA78
	ldr r1, [r1]
	adds r1, #0x6c
	ldrb r2, [r1]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl Random
	movs r1, #0xff
	ands r1, r0
	cmp r4, r1
	bls _0803EA46
_0803EA40:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
_0803EA46:
	ldr r0, _0803EA78
	ldr r1, [r0]
	adds r1, #0x6c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803EA52:
	cmp r7, #0
	beq _0803EA64
	ldr r1, _0803EA7C
	ldr r0, _0803EA80
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0803EA84
	movs r0, #4
	strb r0, [r1]
_0803EA64:
	adds r0, r7, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803EA74: .4byte 0x02023D28
_0803EA78: .4byte 0x02024140
_0803EA7C: .4byte 0x02023D26
_0803EA80: .4byte 0x02023D10
_0803EA84: .4byte 0x02023FDE
	thumb_func_end TryRunFromBattle

	thumb_func_start HandleAction_Run
HandleAction_Run: @ 0x0803EA88
	push {r4, r5, r6, lr}
	ldr r4, _0803EAD8
	ldr r1, _0803EADC
	ldr r5, _0803EAE0
	ldrb r0, [r5]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r0, _0803EAE4
	ldr r0, [r0]
	ldr r1, _0803EAE8
	ands r0, r1
	cmp r0, #0
	beq _0803EB4C
	ldr r0, _0803EAEC
	ldrb r1, [r0]
	strb r1, [r5]
	ldr r2, _0803EAF0
	movs r0, #0
	strb r0, [r2]
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _0803EB20
	adds r4, r2, #0
	ldr r6, _0803EAF4
	ldr r5, _0803EAF8
_0803EABC:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EAFC
	ldrb r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803EB0E
	ldrb r0, [r5]
	movs r1, #2
	b _0803EB0A
	.align 2, 0
_0803EAD8: .4byte 0x02023EAF
_0803EADC: .4byte 0x02023D22
_0803EAE0: .4byte 0x02023D26
_0803EAE4: .4byte 0x02022C90
_0803EAE8: .4byte 0x02000002
_0803EAEC: .4byte 0x02023D10
_0803EAF0: .4byte 0x02023D08
_0803EAF4: .4byte 0x02023EC0
_0803EAF8: .4byte 0x02023FDE
_0803EAFC:
	ldrb r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803EB0E
	ldrb r0, [r5]
	movs r1, #1
_0803EB0A:
	orrs r0, r1
	strb r0, [r5]
_0803EB0E:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _0803EB3C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803EABC
_0803EB20:
	ldr r2, _0803EB40
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0803EB44
	ldr r1, [r0]
	ldr r0, _0803EB48
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #8
	orrs r0, r2
	b _0803EBD6
	.align 2, 0
_0803EB3C: .4byte 0x02023D10
_0803EB40: .4byte 0x02023FDE
_0803EB44: .4byte 0x03005AF0
_0803EB48: .4byte 0x00000CA9
_0803EB4C:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EB8C
	ldrb r0, [r4]
	bl TryRunFromBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EBD8
	ldrb r0, [r4]
	bl ClearFuryCutterDestinyBondGrudge
	ldr r1, _0803EB7C
	movs r0, #3
	strb r0, [r1, #5]
	ldr r1, _0803EB80
	ldr r0, _0803EB84
	str r0, [r1]
	ldr r1, _0803EB88
	movs r0, #0xa
	b _0803EBD6
	.align 2, 0
_0803EB7C: .4byte 0x02023FD6
_0803EB80: .4byte 0x02023EB8
_0803EB84: .4byte 0x0828908A
_0803EB88: .4byte 0x02023D27
_0803EB8C:
	ldr r1, _0803EBB4
	ldrb r2, [r4]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0803EBB8
	ands r0, r1
	cmp r0, #0
	beq _0803EBCC
	ldr r1, _0803EBBC
	movs r0, #4
	strb r0, [r1, #5]
	ldr r1, _0803EBC0
	ldr r0, _0803EBC4
	str r0, [r1]
	ldr r1, _0803EBC8
	movs r0, #0xa
	b _0803EBD6
	.align 2, 0
_0803EBB4: .4byte 0x02023D28
_0803EBB8: .4byte 0x0400E000
_0803EBBC: .4byte 0x02023FD6
_0803EBC0: .4byte 0x02023EB8
_0803EBC4: .4byte 0x0828908A
_0803EBC8: .4byte 0x02023D27
_0803EBCC:
	ldr r0, _0803EBE0
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r1, _0803EBE4
	movs r0, #6
_0803EBD6:
	strb r0, [r1]
_0803EBD8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803EBE0: .4byte 0x02023D10
_0803EBE4: .4byte 0x02023FDE
	thumb_func_end HandleAction_Run

	thumb_func_start HandleAction_WatchesCarefully
HandleAction_WatchesCarefully: @ 0x0803EBE8
	ldr r2, _0803EC10
	ldr r1, _0803EC14
	ldr r0, _0803EC18
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, _0803EC1C
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EC20
	strh r1, [r0]
	ldr r1, _0803EC24
	ldr r0, _0803EC28
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0803EC2C
	movs r0, #0xa
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803EC10: .4byte 0x02023EAF
_0803EC14: .4byte 0x02023D22
_0803EC18: .4byte 0x02023D26
_0803EC1C: .4byte 0x02022AC8
_0803EC20: .4byte 0x02022ACA
_0803EC24: .4byte 0x02023EB8
_0803EC28: .4byte 0x0828A2E0
_0803EC2C: .4byte 0x02023D27
	thumb_func_end HandleAction_WatchesCarefully

	thumb_func_start HandleAction_SafariZoneBallThrow
HandleAction_SafariZoneBallThrow: @ 0x0803EC30
	ldr r2, _0803EC68
	ldr r1, _0803EC6C
	ldr r0, _0803EC70
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, _0803EC74
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EC78
	strh r1, [r0]
	ldr r1, _0803EC7C
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r1, _0803EC80
	movs r0, #5
	strh r0, [r1]
	ldr r1, _0803EC84
	ldr r0, _0803EC88
	ldr r0, [r0, #0x14]
	str r0, [r1]
	ldr r1, _0803EC8C
	movs r0, #0xa
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803EC68: .4byte 0x02023EAF
_0803EC6C: .4byte 0x02023D22
_0803EC70: .4byte 0x02023D26
_0803EC74: .4byte 0x02022AC8
_0803EC78: .4byte 0x02022ACA
_0803EC7C: .4byte 0x02039D18
_0803EC80: .4byte 0x02023EAC
_0803EC84: .4byte 0x02023EB8
_0803EC88: .4byte 0x0828A290
_0803EC8C: .4byte 0x02023D27
	thumb_func_end HandleAction_SafariZoneBallThrow

	thumb_func_start HandleAction_ThrowPokeblock
HandleAction_ThrowPokeblock: @ 0x0803EC90
	push {r4, r5, r6, lr}
	ldr r3, _0803ED10
	ldr r1, _0803ED14
	ldr r0, _0803ED18
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r0, _0803ED1C
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803ED20
	strh r1, [r0]
	ldr r6, _0803ED24
	ldr r2, _0803ED28
	ldrb r0, [r3]
	lsls r0, r0, #9
	adds r1, r2, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #1
	strb r0, [r6, #5]
	ldr r1, _0803ED2C
	ldrb r0, [r3]
	lsls r0, r0, #9
	adds r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	strh r0, [r1]
	ldr r1, _0803ED30
	ldrb r0, [r1, #0x1f]
	cmp r0, #0xfe
	bhi _0803ECD6
	adds r0, #1
	strb r0, [r1, #0x1f]
_0803ECD6:
	ldr r2, _0803ED34
	ldr r0, [r2]
	adds r1, r0, #0
	adds r1, #0x7a
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0803ECE8
	adds r0, #1
	strb r0, [r1]
_0803ECE8:
	ldr r0, [r2]
	adds r3, r0, #0
	adds r3, #0x7b
	ldrb r5, [r3]
	adds r4, r5, #0
	cmp r4, #1
	bls _0803ED40
	ldr r2, _0803ED38
	adds r0, #0x7a
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r6, [r6, #5]
	adds r0, r0, r6
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r4, r0
	bhs _0803ED3C
	movs r0, #1
	b _0803ED3E
	.align 2, 0
_0803ED10: .4byte 0x02023EAF
_0803ED14: .4byte 0x02023D22
_0803ED18: .4byte 0x02023D26
_0803ED1C: .4byte 0x02022AC8
_0803ED20: .4byte 0x02022ACA
_0803ED24: .4byte 0x02023FD6
_0803ED28: .4byte 0x02023508
_0803ED2C: .4byte 0x02023EAC
_0803ED30: .4byte 0x03005A70
_0803ED34: .4byte 0x02024140
_0803ED38: .4byte 0x082EC664
_0803ED3C:
	subs r0, r5, r0
_0803ED3E:
	strb r0, [r3]
_0803ED40:
	ldr r1, _0803ED54
	ldr r0, _0803ED58
	ldr r0, [r0, #8]
	str r0, [r1]
	ldr r1, _0803ED5C
	movs r0, #0xa
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803ED54: .4byte 0x02023EB8
_0803ED58: .4byte 0x0828A2E0
_0803ED5C: .4byte 0x02023D27
	thumb_func_end HandleAction_ThrowPokeblock

	thumb_func_start HandleAction_GoNear
HandleAction_GoNear: @ 0x0803ED60
	push {r4, lr}
	ldr r2, _0803EDE0
	ldr r1, _0803EDE4
	ldr r0, _0803EDE8
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, _0803EDEC
	movs r4, #0
	strh r4, [r0]
	ldr r0, _0803EDF0
	strh r4, [r0]
	ldr r3, _0803EDF4
	ldr r0, [r3]
	adds r2, r0, #0
	adds r2, #0x7c
	ldr r1, _0803EDF8
	adds r0, #0x79
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	cmp r0, #0x14
	bls _0803EDA2
	movs r0, #0x14
	strb r0, [r1]
_0803EDA2:
	ldr r0, [r3]
	adds r2, r0, #0
	adds r2, #0x7b
	ldr r1, _0803EDFC
	adds r0, #0x79
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x7b
	ldrb r0, [r1]
	cmp r0, #0x14
	bls _0803EDC8
	movs r0, #0x14
	strb r0, [r1]
_0803EDC8:
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x79
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0803EE04
	adds r0, #1
	strb r0, [r1]
	ldr r0, _0803EE00
	strb r4, [r0, #5]
	b _0803EE0A
	.align 2, 0
_0803EDE0: .4byte 0x02023EAF
_0803EDE4: .4byte 0x02023D22
_0803EDE8: .4byte 0x02023D26
_0803EDEC: .4byte 0x02022AC8
_0803EDF0: .4byte 0x02022ACA
_0803EDF4: .4byte 0x02024140
_0803EDF8: .4byte 0x082EC673
_0803EDFC: .4byte 0x082EC677
_0803EE00: .4byte 0x02023FD6
_0803EE04:
	ldr r1, _0803EE20
	movs r0, #1
	strb r0, [r1, #5]
_0803EE0A:
	ldr r1, _0803EE24
	ldr r0, _0803EE28
	ldr r0, [r0, #4]
	str r0, [r1]
	ldr r1, _0803EE2C
	movs r0, #0xa
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EE20: .4byte 0x02023FD6
_0803EE24: .4byte 0x02023EB8
_0803EE28: .4byte 0x0828A2E0
_0803EE2C: .4byte 0x02023D27
	thumb_func_end HandleAction_GoNear

	thumb_func_start HandleAction_SafariZoneRun
HandleAction_SafariZoneRun: @ 0x0803EE30
	push {r4, lr}
	ldr r2, _0803EE58
	ldr r1, _0803EE5C
	ldr r4, _0803EE60
	ldrb r0, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, #0x11
	bl PlaySE
	ldr r0, _0803EE64
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r1, _0803EE68
	movs r0, #4
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EE58: .4byte 0x02023EAF
_0803EE5C: .4byte 0x02023D22
_0803EE60: .4byte 0x02023D26
_0803EE64: .4byte 0x02023D10
_0803EE68: .4byte 0x02023FDE
	thumb_func_end HandleAction_SafariZoneRun

	thumb_func_start HandleAction_WallyBallThrow
HandleAction_WallyBallThrow: @ 0x0803EE6C
	ldr r3, _0803EEB8
	ldr r1, _0803EEBC
	ldr r0, _0803EEC0
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r2, [r0]
	strb r2, [r3]
	ldr r0, _0803EEC4
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EEC8
	strh r1, [r0]
	ldr r1, _0803EECC
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #7
	strb r0, [r1, #1]
	strb r2, [r1, #2]
	ldr r2, _0803EED0
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _0803EED4
	ldr r0, _0803EED8
	ldr r0, [r0, #0xc]
	str r0, [r1]
	ldr r1, _0803EEDC
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, _0803EEE0
	movs r0, #0xc
	strb r0, [r1, #1]
	bx lr
	.align 2, 0
_0803EEB8: .4byte 0x02023EAF
_0803EEBC: .4byte 0x02023D22
_0803EEC0: .4byte 0x02023D26
_0803EEC4: .4byte 0x02022AC8
_0803EEC8: .4byte 0x02022ACA
_0803EECC: .4byte 0x02022C0C
_0803EED0: .4byte 0x02023D12
_0803EED4: .4byte 0x02023EB8
_0803EED8: .4byte 0x0828A2E0
_0803EEDC: .4byte 0x02023D27
_0803EEE0: .4byte 0x02023D1E
	thumb_func_end HandleAction_WallyBallThrow

	thumb_func_start sub_0803EEE4
sub_0803EEE4: @ 0x0803EEE4
	push {lr}
	bl HandleFaintedMonActions
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0803EF00
	ldr r0, _0803EF04
	ldr r0, [r0]
	adds r0, #0x4d
	strb r1, [r0]
	ldr r1, _0803EF08
	movs r0, #0xc
	strb r0, [r1]
_0803EF00:
	pop {r0}
	bx r0
	.align 2, 0
_0803EF04: .4byte 0x02024140
_0803EF08: .4byte 0x02023D27
	thumb_func_end sub_0803EEE4

	thumb_func_start HandleAction_NothingIsFainted
HandleAction_NothingIsFainted: @ 0x0803EF0C
	ldr r1, _0803EF2C
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r3, _0803EF30
	ldr r2, _0803EF34
	ldrb r0, [r1]
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r2, _0803EF38
	ldr r0, [r2]
	ldr r1, _0803EF3C
	ands r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0803EF2C: .4byte 0x02023D26
_0803EF30: .4byte 0x02023D27
_0803EF34: .4byte 0x02023D1E
_0803EF38: .4byte 0x02023F24
_0803EF3C: .4byte 0xF1E892AF
	thumb_func_end HandleAction_NothingIsFainted

	thumb_func_start HandleAction_ActionFinished
HandleAction_ActionFinished: @ 0x0803EF40
	push {r4, r5, r6, lr}
	ldr r1, _0803EFC8
	ldr r2, _0803EFCC
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r6, _0803EFD0
	ldr r1, [r6]
	adds r0, r0, r1
	adds r0, #0x5c
	movs r1, #6
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r3, _0803EFD4
	ldr r1, _0803EFD8
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	bl SpecialStatusesClear
	ldr r2, _0803EFDC
	ldr r0, [r2]
	ldr r1, _0803EFE0
	ands r0, r1
	str r0, [r2]
	ldr r0, _0803EFE4
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EFE8
	movs r4, #0
	str r4, [r0]
	ldr r0, _0803EFEC
	strb r1, [r0]
	ldr r5, _0803EFF0
	strb r1, [r5, #0x18]
	strb r1, [r5, #0x19]
	ldr r2, _0803EFF4
	ldr r3, _0803EFF8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	strh r4, [r0]
	ldr r2, _0803EFFC
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	strh r4, [r0]
	ldr r0, [r6]
	strb r1, [r0, #0x13]
	ldr r0, _0803F000
	strh r4, [r0]
	strb r1, [r5, #0x14]
	ldr r0, _0803F004
	strb r1, [r0, #3]
	strb r1, [r0, #4]
	strb r1, [r5, #0x16]
	ldr r0, _0803F008
	ldr r0, [r0]
	ldr r0, [r0, #8]
	adds r0, #0x20
	strb r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803EFC8: .4byte 0x02023D22
_0803EFCC: .4byte 0x02023D26
_0803EFD0: .4byte 0x02024140
_0803EFD4: .4byte 0x02023D27
_0803EFD8: .4byte 0x02023D1E
_0803EFDC: .4byte 0x02023F24
_0803EFE0: .4byte 0xF1E892AF
_0803EFE4: .4byte 0x02023E8E
_0803EFE8: .4byte 0x02023E94
_0803EFEC: .4byte 0x02023F20
_0803EFF0: .4byte 0x02024118
_0803EFF4: .4byte 0x02023EF4
_0803EFF8: .4byte 0x02023EAF
_0803EFFC: .4byte 0x02023EFC
_0803F000: .4byte 0x020240A4
_0803F004: .4byte 0x02023FD6
_0803F008: .4byte 0x0202414C
	thumb_func_end HandleAction_ActionFinished
