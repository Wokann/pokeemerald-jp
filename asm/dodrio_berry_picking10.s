.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



	thumb_func_start sub_080264E4
sub_080264E4: @ 0x080264E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r2, _080265B8
	ldr r4, [r2]
	adds r0, r4, #0
	adds r0, #0x44
	ldrb r1, [r0]
	adds r0, #4
	ldrb r0, [r0]
	mov sb, r0
	movs r3, #0
	mov sl, r3
	movs r5, #0x90
	lsls r5, r5, #1
	adds r0, r4, r5
	str r3, [r0]
	adds r5, r1, #0
	mov r0, sb
	subs r0, #1
	cmp r5, r0
	blt _08026516
	b _08026734
_08026516:
	mov r8, r2
_08026518:
	mov r0, r8
	ldr r4, [r0]
	adds r0, r4, #0
	adds r0, #0xc4
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #1
	bls _0802652A
	b _08026634
_0802652A:
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #1
	str r2, [r0]
	ldr r1, _080265BC
	adds r0, r4, r1
	adds r6, r0, r5
	ldrb r0, [r6]
	cmp r0, #9
	bls _080265C4
	movs r7, #0
	movs r0, #0xa
	strb r0, [r6]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0xc4
	adds r0, r0, r5
	movs r1, #3
	strb r1, [r0]
	mov r1, r8
	ldr r0, [r1]
	movs r6, #0xa4
	lsls r6, r6, #1
	adds r0, r0, r6
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #0
	bne _08026574
	strb r2, [r1]
	ldr r2, _080265C0
	adds r0, r4, r2
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r0, #0x4a
	bl PlaySE
_08026574:
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _0802658A
	mov r2, sl
	cmp r2, #1
	beq _0802658A
	b _08026724
_0802658A:
	movs r0, #1
	mov sl, r0
	adds r0, r1, r6
	adds r0, r0, r5
	strb r7, [r0]
	mov r1, r8
	ldr r0, [r1]
	adds r1, r0, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #9
	bhi _080265A6
	adds r0, #1
	strb r0, [r1]
_080265A6:
	movs r0, #3
	adds r1, r5, #0
	movs r2, #0
	bl sub_08026CDC
	movs r0, #0
	bl sub_08026FF4
	b _08026724
	.align 2, 0
_080265B8: .4byte 0x0202294C
_080265BC: .4byte 0x000032EB
_080265C0: .4byte 0x000032E0
_080265C4:
	adds r0, r5, #0
	bl sub_08026B4C
	mov r2, r8
	ldr r7, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r7, #0
	adds r1, #0x90
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r1, #7
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _080265EA
	movs r3, #2
_080265EA:
	ldr r2, _0802662C
	ldr r0, _08026630
	adds r1, r4, r0
	adds r1, r1, r5
	lsls r0, r3, #1
	adds r0, r0, r3
	ldrb r1, [r1]
	adds r0, r0, r1
	adds r0, r0, r2
	ldrb r2, [r0]
	adds r1, r7, #0
	adds r1, #0xd0
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r2
	blo _08026624
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0xd0
	adds r0, r0, r5
	strb r3, [r0]
_08026624:
	bl sub_080260EC
	b _08026724
	.align 2, 0
_0802662C: .4byte 0x082CB314
_08026630: .4byte 0x000032E0
_08026634:
	cmp r0, #2
	bne _080266B4
	adds r1, r4, #0
	adds r1, #0xdc
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	movs r3, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _08026724
	mov r0, r8
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0xb8
	adds r0, r0, r5
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r1, _080266A8
	adds r2, r2, r1
	strb r3, [r2]
	mov r2, r8
	ldr r0, [r2]
	adds r0, #0xdc
	adds r0, r0, r5
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, #0xd0
	adds r0, r0, r5
	strb r3, [r0]
	ldr r0, [r2]
	adds r0, #0xc4
	adds r0, r0, r5
	strb r3, [r0]
	ldr r1, _080266AC
	adds r0, r4, r1
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
	adds r0, r5, #0
	bl sub_08026B4C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r5, #0
	bl sub_08026B70
	ldr r2, _080266B0
	adds r1, r4, r2
	adds r1, r1, r5
	strb r0, [r1]
	b _08026724
	.align 2, 0
_080266A8: .4byte 0x000031D0
_080266AC: .4byte 0x000032EB
_080266B0: .4byte 0x000032E0
_080266B4:
	cmp r0, #3
	bne _08026724
	adds r1, r4, #0
	adds r1, #0xdc
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _08026724
	mov r0, r8
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bhi _08026724
	adds r0, r1, #0
	adds r0, #0xdc
	adds r0, r0, r5
	strb r2, [r0]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0xd0
	adds r0, r0, r5
	strb r2, [r0]
	ldr r0, [r1]
	adds r0, #0xc4
	adds r0, r0, r5
	strb r2, [r0]
	ldr r2, _08026744
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #1
	strb r1, [r0]
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0xe8
	adds r1, r1, r5
	subs r2, #0xb
	adds r4, r4, r2
	adds r4, r4, r5
	ldrb r0, [r4]
	strb r0, [r1]
	adds r0, r5, #0
	bl sub_08026B4C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r5, #0
	bl sub_08026B70
	strb r0, [r4]
_08026724:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r0, sb
	subs r0, #1
	cmp r5, r0
	bge _08026734
	b _08026518
_08026734:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08026744: .4byte 0x000032EB
	thumb_func_end sub_080264E4

	thumb_func_start sub_08026748
sub_08026748: @ 0x08026748
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _080267B0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x44
	adds r0, #0x48
	ldrb r0, [r0]
	mov r8, r0
	ldrb r6, [r1]
	cmp r6, r8
	bhs _0802683A
	ldr r0, _080267B4
	mov sb, r0
_08026768:
	ldr r0, _080267B0
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x28
	ldrb r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r2, _080267B8
	adds r0, r0, r2
	adds r7, r3, r0
	movs r0, #0xb
	adds r2, r1, #0
	muls r2, r0, r2
	adds r2, r6, r2
	adds r3, #0x24
	ldrb r1, [r3]
	subs r1, #1
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	subs r0, r0, r1
	adds r2, r2, r0
	add r2, sb
	ldrb r4, [r2]
	adds r0, r7, #0
	adds r0, #0x1f
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080267BC
	adds r0, r6, #0
	movs r1, #0
	bl sub_08028924
	b _080267C4
	.align 2, 0
_080267B0: .4byte 0x0202294C
_080267B4: .4byte 0x082C7D28
_080267B8: .4byte 0x000031A0
_080267BC:
	adds r0, r6, #0
	movs r1, #1
	bl sub_08028924
_080267C4:
	adds r0, r7, #0
	adds r0, #0x1f
	adds r5, r0, r4
	ldrb r0, [r5]
	cmp r0, #9
	bls _080267F0
	adds r0, r7, #0
	adds r0, #0x14
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r1, #3
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl sub_080289D0
	ldrb r1, [r5]
	lsls r1, r1, #0x19
	movs r0, #0xff
	lsls r0, r0, #0x18
	adds r1, r1, r0
	b _08026812
_080267F0:
	adds r0, r7, #0
	adds r0, #0x14
	adds r3, r0, r4
	ldrb r0, [r3]
	cmp r0, #3
	bne _0802681C
	movs r0, #7
	strb r0, [r5]
	adds r0, r6, #0
	movs r1, #6
	bl sub_080289D0
	ldrb r1, [r5]
	lsls r1, r1, #0x19
	movs r2, #0xff
	lsls r2, r2, #0x18
	adds r1, r1, r2
_08026812:
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl sub_080289A8
	b _08026830
_0802681C:
	ldrb r1, [r3]
	adds r0, r6, #0
	bl sub_080289D0
	ldrb r1, [r5]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl sub_080289A8
_08026830:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, r8
	blo _08026768
_0802683A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08026748

	thumb_func_start sub_08026848
sub_08026848: @ 0x08026848
	push {r4, r5, r6, lr}
	ldr r1, _08026880
	ldr r0, [r1]
	adds r0, #0x24
	ldrb r5, [r0]
	movs r4, #0
	cmp r4, r5
	bhs _0802687A
	adds r6, r1, #0
_0802685A:
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #2
	ldr r1, [r6]
	adds r0, r0, r1
	ldr r1, _08026884
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl sub_080283E0
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r5
	blo _0802685A
_0802687A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08026880: .4byte 0x0202294C
_08026884: .4byte 0x000031CC
	thumb_func_end sub_08026848

	thumb_func_start sub_08026888
sub_08026888: @ 0x08026888
	push {r4, r5, lr}
	ldr r0, _080268B0
	ldr r0, [r0]
	adds r0, #0x24
	ldrb r5, [r0]
	movs r4, #0
	cmp r4, r5
	bhs _080268AA
_08026898:
	adds r0, r4, #0
	movs r1, #4
	bl sub_080283E0
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r5
	blo _08026898
_080268AA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080268B0: .4byte 0x0202294C
	thumb_func_end sub_08026888

	thumb_func_start sub_080268B4
sub_080268B4: @ 0x080268B4
	push {lr}
	bl sub_08026748
	ldr r0, _080268CC
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _080268D0
	bl sub_08026888
	b _080268D4
	.align 2, 0
_080268CC: .4byte 0x0202294C
_080268D0:
	bl sub_08026848
_080268D4:
	ldr r0, _080268E4
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	bl sub_08028600
	pop {r0}
	bx r0
	.align 2, 0
_080268E4: .4byte 0x0202294C
	thumb_func_end sub_080268B4

	thumb_func_start sub_080268E8
sub_080268E8: @ 0x080268E8
	push {lr}
	bl sub_08026748
	ldr r0, _08026900
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #9
	bls _08026904
	bl sub_08026888
	b _08026908
	.align 2, 0
_08026900: .4byte 0x0202294C
_08026904:
	bl sub_08026848
_08026908:
	ldr r0, _08026918
	ldr r0, [r0]
	adds r0, #0x40
	ldrb r0, [r0]
	bl sub_08028600
	pop {r0}
	bx r0
	.align 2, 0
_08026918: .4byte 0x0202294C
	thumb_func_end sub_080268E8

	thumb_func_start sub_0802691C
sub_0802691C: @ 0x0802691C
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #4
	bhi _08026974
	lsls r0, r0, #2
	ldr r1, _08026934
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08026934: .4byte 0x08026938
_08026938: @ jump table
	.4byte _0802694C @ case 0
	.4byte _08026954 @ case 1
	.4byte _0802695C @ case 2
	.4byte _08026964 @ case 3
	.4byte _0802696C @ case 4
_0802694C:
	movs r0, #4
	strb r0, [r3]
	movs r0, #7
	b _08026972
_08026954:
	movs r0, #3
	strb r0, [r3]
	movs r0, #8
	b _08026972
_0802695C:
	movs r0, #2
	strb r0, [r3]
	movs r0, #9
	b _08026972
_08026964:
	movs r0, #1
	strb r0, [r3]
	movs r0, #0xa
	b _08026972
_0802696C:
	movs r0, #0
	strb r0, [r3]
	movs r0, #0xb
_08026972:
	strb r0, [r2]
_08026974:
	pop {r0}
	bx r0
	thumb_func_end sub_0802691C
