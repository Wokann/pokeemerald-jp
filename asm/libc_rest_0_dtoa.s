.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
thumb_func_start _dtoa_r
_dtoa_r: @ 0x08299210
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	mov sl, r0
	str r3, [sp, #0xc]
	ldr r4, [sp, #0xac]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	ldr r2, [r0, #0x40]
	cmp r2, #0
	beq _08299248
	ldr r0, [r0, #0x44]
	str r0, [r2, #4]
	mov r0, sl
	ldr r1, [r0, #0x44]
	movs r0, #1
	lsls r0, r1
	str r0, [r2, #8]
	mov r0, sl
	adds r1, r2, #0
	bl _Bfree
	movs r0, #0
	mov r1, sl
	str r0, [r1, #0x40]
_08299248:
	movs r0, #0x80
	lsls r0, r0, #0x18
	ldr r1, [sp, #0x40]
	ands r0, r1
	cmp r0, #0
	beq _08299264
	movs r0, #1
	str r0, [r4]
	ldr r0, _08299260
	ands r1, r0
	str r1, [sp, #0x40]
	b _08299266
	.align 2, 0
_08299260: .4byte 0x7FFFFFFF
_08299264:
	str r0, [r4]
_08299266:
	ldr r1, _082992A8
	ldr r2, [sp, #0x40]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, r1
	bne _082992BC
	ldr r0, _082992AC
	ldr r3, [sp, #0xa8]
	str r0, [r3]
	ldr r0, _082992B0
	mov sb, r0
	ldr r1, [sp, #0x44]
	cmp r1, #0
	bne _0829928E
	ldr r0, _082992B4
	ands r2, r0
	cmp r2, #0
	bne _0829928E
	ldr r2, _082992B8
	mov sb, r2
_0829928E:
	ldr r3, [sp, #0xb0]
	cmp r3, #0
	beq _082992E0
	mov r1, sb
	ldrb r0, [r1, #3]
	adds r1, #3
	cmp r0, #0
	beq _082992A0
	adds r1, #5
_082992A0:
	ldr r2, [sp, #0xb0]
	str r1, [r2]
	b _082992E0
	.align 2, 0
_082992A8: .4byte 0x7FF00000
_082992AC: .4byte 0x0000270F
_082992B0: .4byte 0x0890F1E4
_082992B4: .4byte 0x000FFFFF
_082992B8: .4byte 0x0890F1D8
_082992BC:
	ldr r3, _082992EC
	ldr r2, _082992E8
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __eqdf2
	cmp r0, #0
	bne _082992F4
	movs r0, #1
	ldr r3, [sp, #0xa8]
	str r0, [r3]
	ldr r0, _082992F0
	mov sb, r0
	ldr r1, [sp, #0xb0]
	cmp r1, #0
	beq _082992E0
	adds r0, #1
	str r0, [r1]
_082992E0:
	mov r0, sb
	bl _08299EFA
	.align 2, 0
_082992E8: .4byte 0x00000000
_082992EC: .4byte 0x00000000
_082992F0: .4byte 0x0890F1E8
_082992F4:
	add r0, sp, #8
	str r0, [sp]
	mov r0, sl
	ldr r1, [sp, #0x40]
	ldr r2, [sp, #0x44]
	add r3, sp, #4
	bl _d2b
	str r0, [sp, #0x5c]
	ldr r2, [sp, #0x40]
	lsls r0, r2, #1
	lsrs r0, r0, #0x15
	mov r8, r0
	cmp r0, #0
	beq _08299344
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	str r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	ldr r0, _08299338
	ldr r1, [sp, #0x48]
	ands r1, r0
	str r1, [sp, #0x48]
	ldr r0, _0829933C
	adds r2, r1, #0
	orrs r2, r0
	str r2, [sp, #0x48]
	ldr r3, _08299340
	add r8, r3
	movs r0, #0
	str r0, [sp, #0x58]
	ldr r6, [sp, #8]
	b _082993A4
	.align 2, 0
_08299338: .4byte 0x000FFFFF
_0829933C: .4byte 0x3FF00000
_08299340: .4byte 0xFFFFFC01
_08299344:
	ldr r1, [sp, #8]
	ldr r0, [sp, #4]
	adds r2, r1, r0
	ldr r3, _0829936C
	adds r3, r3, r2
	mov r8, r3
	adds r6, r1, #0
	cmp r3, #0x20
	ble _08299374
	movs r0, #0x40
	subs r0, r0, r3
	ldr r4, [sp, #0x40]
	lsls r4, r0
	ldr r1, _08299370
	adds r0, r2, r1
	ldr r2, [sp, #0x44]
	lsrs r2, r0
	adds r0, r2, #0
	orrs r4, r0
	b _0829937E
	.align 2, 0
_0829936C: .4byte 0x00000432
_08299370: .4byte 0x00000412
_08299374:
	movs r0, #0x20
	mov r3, r8
	subs r0, r0, r3
	ldr r4, [sp, #0x44]
	lsls r4, r0
_0829937E:
	adds r0, r4, #0
	bl __floatsidf
	cmp r4, #0
	bge _08299390
	ldr r3, _08299454
	ldr r2, _08299450
	bl __adddf3
_08299390:
	str r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	ldr r1, _08299458
	ldr r0, [sp, #0x48]
	adds r1, r0, r1
	str r1, [sp, #0x48]
	ldr r2, _0829945C
	add r8, r2
	movs r3, #1
	str r3, [sp, #0x58]
_082993A4:
	ldr r2, _08299460
	ldr r3, _08299464
	ldr r0, [sp, #0x48]
	ldr r1, [sp, #0x4c]
	bl __subdf3
	ldr r2, _08299468
	ldr r3, _0829946C
	bl __muldf3
	ldr r2, _08299470
	ldr r3, _08299474
	bl __adddf3
	adds r5, r1, #0
	adds r4, r0, #0
	mov r0, r8
	bl __floatsidf
	ldr r2, _08299478
	ldr r3, _0829947C
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __adddf3
	str r0, [sp, #0x6c]
	str r1, [sp, #0x70]
	bl __fixdfsi
	str r0, [sp, #0x24]
	ldr r2, _08299480
	ldr r3, _08299484
	ldr r0, [sp, #0x6c]
	ldr r1, [sp, #0x70]
	bl __ltdf2
	cmp r0, #0
	bge _08299414
	ldr r0, [sp, #0x24]
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x6c]
	ldr r1, [sp, #0x70]
	bl __nedf2
	cmp r0, #0
	beq _08299414
	ldr r0, [sp, #0x24]
	subs r0, #1
	str r0, [sp, #0x24]
_08299414:
	movs r1, #1
	str r1, [sp, #0x2c]
	ldr r2, [sp, #0x24]
	cmp r2, #0x16
	bhi _0829943E
	ldr r1, _08299488
	lsls r0, r2, #3
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r3, [r0, #4]
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __ltdf2
	cmp r0, #0
	bge _0829943A
	ldr r3, [sp, #0x24]
	subs r3, #1
	str r3, [sp, #0x24]
_0829943A:
	movs r0, #0
	str r0, [sp, #0x2c]
_0829943E:
	mov r1, r8
	subs r0, r6, r1
	subs r4, r0, #1
	cmp r4, #0
	blt _0829948C
	movs r2, #0
	str r2, [sp, #0x10]
	str r4, [sp, #0x34]
	b _08299494
	.align 2, 0
_08299450: .4byte 0x41F00000
_08299454: .4byte 0x00000000
_08299458: .4byte 0xFE100000
_0829945C: .4byte 0xFFFFFBCD
_08299460: .4byte 0x3FF80000
_08299464: .4byte 0x00000000
_08299468: .4byte 0x3FD287A7
_0829946C: .4byte 0x636F4361
_08299470: .4byte 0x3FC68A28
_08299474: .4byte 0x8B60C8B3
_08299478: .4byte 0x3FD34413
_0829947C: .4byte 0x509F79FB
_08299480: .4byte 0x00000000
_08299484: .4byte 0x00000000
_08299488: .4byte 0x0890F234
_0829948C:
	rsbs r4, r4, #0
	str r4, [sp, #0x10]
	movs r3, #0
	str r3, [sp, #0x34]
_08299494:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	blt _082994A8
	movs r1, #0
	str r1, [sp, #0x14]
	str r0, [sp, #0x38]
	ldr r2, [sp, #0x34]
	adds r2, r2, r0
	str r2, [sp, #0x34]
	b _082994B8
_082994A8:
	ldr r3, [sp, #0x10]
	ldr r0, [sp, #0x24]
	subs r3, r3, r0
	str r3, [sp, #0x10]
	rsbs r1, r0, #0
	str r1, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x38]
_082994B8:
	ldr r3, [sp, #0xc]
	cmp r3, #9
	bls _082994C2
	movs r0, #0
	str r0, [sp, #0xc]
_082994C2:
	movs r5, #1
	ldr r1, [sp, #0xc]
	cmp r1, #5
	ble _082994D0
	subs r1, #4
	str r1, [sp, #0xc]
	movs r5, #0
_082994D0:
	movs r2, #1
	str r2, [sp, #0x30]
	ldr r3, [sp, #0xc]
	cmp r3, #5
	bhi _0829954A
	lsls r0, r3, #2
	ldr r1, _082994E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082994E4: .4byte 0x082994E8
_082994E8: @ jump table
	.4byte _08299500 @ case 0
	.4byte _08299500 @ case 1
	.4byte _08299512 @ case 2
	.4byte _0829952E @ case 3
	.4byte _08299516 @ case 4
	.4byte _08299532 @ case 5
_08299500:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x18]
	str r0, [sp, #0x20]
	movs r1, #0x12
	mov r8, r1
	movs r2, #0
	str r2, [sp, #0xa4]
	b _0829954A
_08299512:
	movs r3, #0
	str r3, [sp, #0x30]
_08299516:
	ldr r0, [sp, #0xa4]
	cmp r0, #0
	bgt _08299520
	movs r1, #1
	str r1, [sp, #0xa4]
_08299520:
	ldr r2, [sp, #0xa4]
	mov r8, r2
	mov r3, r8
	str r3, [sp, #0x20]
	mov r0, r8
	str r0, [sp, #0x18]
	b _0829954A
_0829952E:
	movs r1, #0
	str r1, [sp, #0x30]
_08299532:
	ldr r2, [sp, #0xa4]
	ldr r3, [sp, #0x24]
	adds r0, r2, r3
	adds r1, r0, #1
	mov r8, r1
	mov r2, r8
	str r2, [sp, #0x18]
	str r0, [sp, #0x20]
	cmp r1, #0
	bgt _0829954A
	movs r3, #1
	mov r8, r3
_0829954A:
	movs r4, #4
	movs r0, #0
	mov r1, sl
	str r0, [r1, #0x44]
	mov r2, r8
	cmp r2, #0x17
	bls _0829956A
	movs r1, #0
_0829955A:
	adds r1, #1
	lsls r4, r4, #1
	adds r0, r4, #0
	adds r0, #0x14
	cmp r0, r8
	bls _0829955A
	mov r3, sl
	str r1, [r3, #0x44]
_0829956A:
	mov r0, sl
	ldr r1, [r0, #0x44]
	bl _Balloc
	mov r1, sl
	str r0, [r1, #0x40]
	str r0, [sp, #0x74]
	mov sb, r0
	ldr r2, [sp, #0x18]
	cmp r2, #0xe
	bls _08299582
	b _082998F4
_08299582:
	cmp r5, #0
	bne _08299588
	b _082998F4
_08299588:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	str r0, [sp, #0x78]
	str r1, [sp, #0x7c]
	str r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	ldr r1, [sp, #0x24]
	str r1, [sp, #0x28]
	str r2, [sp, #0x1c]
	movs r7, #2
	cmp r1, #0
	ble _08299618
	ldr r0, _08299610
	movs r2, #0xf
	ands r1, r2
	lsls r1, r1, #3
	adds r3, r1, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x6c]
	str r1, [sp, #0x70]
	ldr r1, [sp, #0x24]
	asrs r4, r1, #4
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0
	beq _082995D4
	ands r4, r2
	ldr r0, _08299614
	ldr r2, [r0, #0x20]
	ldr r3, [r0, #0x24]
	ldr r0, [sp, #0x78]
	ldr r1, [sp, #0x7c]
	bl __divdf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	movs r7, #3
_082995D4:
	cmp r4, #0
	beq _082995FC
	ldr r5, _08299614
_082995DA:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _082995F4
	adds r7, #1
	ldr r2, [r5]
	ldr r3, [r5, #4]
	ldr r0, [sp, #0x6c]
	ldr r1, [sp, #0x70]
	bl __muldf3
	str r0, [sp, #0x6c]
	str r1, [sp, #0x70]
_082995F4:
	asrs r4, r4, #1
	adds r5, #8
	cmp r4, #0
	bne _082995DA
_082995FC:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	ldr r2, [sp, #0x6c]
	ldr r3, [sp, #0x70]
	bl __divdf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	b _08299664
	.align 2, 0
_08299610: .4byte 0x0890F234
_08299614: .4byte 0x0890F2FC
_08299618:
	ldr r2, [sp, #0x24]
	rsbs r6, r2, #0
	cmp r6, #0
	beq _08299664
	ldr r1, _0829970C
	movs r0, #0xf
	ands r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	ldr r2, [sp, #0x78]
	ldr r3, [sp, #0x7c]
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	asrs r4, r6, #4
	cmp r4, #0
	beq _08299664
	ldr r5, _08299710
_08299642:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _0829965C
	adds r7, #1
	ldr r0, [r5]
	ldr r1, [r5, #4]
	ldr r2, [sp, #0x40]
	ldr r3, [sp, #0x44]
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
_0829965C:
	asrs r4, r4, #1
	adds r5, #8
	cmp r4, #0
	bne _08299642
_08299664:
	ldr r3, [sp, #0x2c]
	cmp r3, #0
	beq _082996A2
	ldr r2, _08299714
	ldr r3, _08299718
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __ltdf2
	cmp r0, #0
	bge _082996A2
	ldr r0, [sp, #0x18]
	cmp r0, #0
	ble _082996A2
	ldr r1, [sp, #0x20]
	cmp r1, #0
	bgt _08299688
	b _082998E0
_08299688:
	str r1, [sp, #0x18]
	ldr r2, [sp, #0x24]
	subs r2, #1
	str r2, [sp, #0x24]
	ldr r0, _0829971C
	ldr r1, _08299720
	ldr r2, [sp, #0x40]
	ldr r3, [sp, #0x44]
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	adds r7, #1
_082996A2:
	adds r0, r7, #0
	bl __floatsidf
	ldr r2, [sp, #0x40]
	ldr r3, [sp, #0x44]
	bl __muldf3
	ldr r2, _08299724
	ldr r3, _08299728
	bl __adddf3
	str r0, [sp, #0x50]
	str r1, [sp, #0x54]
	ldr r0, _0829972C
	ldr r3, [sp, #0x50]
	adds r0, r3, r0
	str r0, [sp, #0x50]
	ldr r1, [sp, #0x18]
	cmp r1, #0
	bne _08299738
	movs r2, #0
	str r2, [sp, #0x64]
	movs r3, #0
	str r3, [sp, #0x68]
	ldr r2, _08299730
	ldr r3, _08299734
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __gtdf2
	cmp r0, #0
	ble _082996F0
	b _08299C6A
_082996F0:
	ldr r0, [sp, #0x50]
	ldr r1, [sp, #0x54]
	bl __negdf2
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __ltdf2
	cmp r0, #0
	bge _0829970A
	b _08299C62
_0829970A:
	b _082998E0
	.align 2, 0
_0829970C: .4byte 0x0890F234
_08299710: .4byte 0x0890F2FC
_08299714: .4byte 0x3FF00000
_08299718: .4byte 0x00000000
_0829971C: .4byte 0x40240000
_08299720: .4byte 0x00000000
_08299724: .4byte 0x401C0000
_08299728: .4byte 0x00000000
_0829972C: .4byte 0xFCC00000
_08299730: .4byte 0x40140000
_08299734: .4byte 0x00000000
_08299738:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _08299808
	ldr r1, _08299768
	ldr r0, [sp, #0x18]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r3, [r0, #4]
	ldr r0, _0829976C
	ldr r1, _08299770
	bl __divdf3
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __subdf3
	str r0, [sp, #0x50]
	str r1, [sp, #0x54]
	movs r1, #0
	mov r8, r1
	b _08299794
	.align 2, 0
_08299768: .4byte 0x0890F234
_0829976C: .4byte 0x3FE00000
_08299770: .4byte 0x00000000
_08299774:
	ldr r1, _082997FC
	ldr r0, _082997F8
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __muldf3
	str r0, [sp, #0x50]
	str r1, [sp, #0x54]
	ldr r1, _082997FC
	ldr r0, _082997F8
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
_08299794:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __fixdfsi
	adds r6, r0, #0
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	adds r0, r6, #0
	adds r0, #0x30
	mov r2, sb
	strb r0, [r2]
	movs r3, #1
	add sb, r3
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __ltdf2
	cmp r0, #0
	bge _082997D0
	b _08299EDA
_082997D0:
	ldr r0, _08299800
	ldr r1, _08299804
	adds r3, r5, #0
	adds r2, r4, #0
	bl __subdf3
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __ltdf2
	cmp r0, #0
	bge _082997EA
	b _082999F4
_082997EA:
	movs r0, #1
	add r8, r0
	ldr r1, [sp, #0x18]
	cmp r8, r1
	blt _08299774
	b _082998E0
	.align 2, 0
_082997F8: .4byte 0x40240000
_082997FC: .4byte 0x00000000
_08299800: .4byte 0x3FF00000
_08299804: .4byte 0x00000000
_08299808:
	ldr r1, _08299828
	ldr r0, [sp, #0x18]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __muldf3
	str r0, [sp, #0x50]
	str r1, [sp, #0x54]
	movs r2, #1
	mov r8, r2
	b _08299840
	.align 2, 0
_08299828: .4byte 0x0890F234
_0829982C:
	movs r3, #1
	add r8, r3
	ldr r1, _082998D4
	ldr r0, _082998D0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
_08299840:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __fixdfsi
	adds r6, r0, #0
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	adds r0, r6, #0
	adds r0, #0x30
	mov r1, sb
	strb r0, [r1]
	movs r2, #1
	add sb, r2
	ldr r3, [sp, #0x18]
	cmp r8, r3
	bne _0829982C
	ldr r6, _082998D8
	ldr r7, _082998DC
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __gtdf2
	cmp r0, #0
	ble _08299892
	b _082999F4
_08299892:
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __ltdf2
	cmp r0, #0
	bge _082998E0
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	ldrb r1, [r1]
	cmp r1, #0x30
	beq _082998BE
	b _08299A1A
_082998BE:
	movs r2, #1
	rsbs r2, r2, #0
	add sb, r2
	mov r3, sb
	ldrb r3, [r3]
	cmp r3, #0x30
	beq _082998BE
	b _08299A1A
	.align 2, 0
_082998D0: .4byte 0x40240000
_082998D4: .4byte 0x00000000
_082998D8: .4byte 0x3FE00000
_082998DC: .4byte 0x00000000
_082998E0:
	ldr r1, [sp, #0x74]
	mov sb, r1
	ldr r2, [sp, #0x48]
	ldr r3, [sp, #0x4c]
	str r2, [sp, #0x40]
	str r3, [sp, #0x44]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x24]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x18]
_082998F4:
	ldr r0, [sp, #4]
	cmp r0, #0
	bge _082998FC
	b _08299A30
_082998FC:
	ldr r1, [sp, #0x24]
	cmp r1, #0xe
	ble _08299904
	b _08299A30
_08299904:
	ldr r1, _08299950
	ldr r2, [sp, #0x24]
	lsls r0, r2, #3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r0, #4]
	str r1, [sp, #0x6c]
	str r2, [sp, #0x70]
	ldr r2, [sp, #0xa4]
	cmp r2, #0
	bge _0829995C
	ldr r3, [sp, #0x18]
	cmp r3, #0
	bgt _0829995C
	movs r0, #0
	str r0, [sp, #0x64]
	movs r1, #0
	str r1, [sp, #0x68]
	cmp r3, #0
	bge _0829992E
	b _08299C62
_0829992E:
	ldr r2, _08299954
	ldr r3, _08299958
	ldr r0, [sp, #0x6c]
	ldr r1, [sp, #0x70]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __ledf2
	cmp r0, #0
	bgt _0829994C
	b _08299C62
_0829994C:
	b _08299C6A
	.align 2, 0
_08299950: .4byte 0x0890F234
_08299954: .4byte 0x40140000
_08299958: .4byte 0x00000000
_0829995C:
	movs r2, #1
	mov r8, r2
	b _08299980
_08299962:
	ldr r1, _08299A24
	ldr r0, _08299A20
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	ldr r2, _08299A28
	ldr r3, _08299A2C
	bl __eqdf2
	cmp r0, #0
	bne _0829997C
	b _08299EDA
_0829997C:
	movs r3, #1
	add r8, r3
_08299980:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	ldr r2, [sp, #0x6c]
	ldr r3, [sp, #0x70]
	bl __divdf3
	bl __fixdfsi
	adds r6, r0, #0
	bl __floatsidf
	ldr r2, [sp, #0x6c]
	ldr r3, [sp, #0x70]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r0, r6, #0
	adds r0, #0x30
	mov r1, sb
	strb r0, [r1]
	movs r0, #1
	add sb, r0
	ldr r1, [sp, #0x18]
	cmp r8, r1
	bne _08299962
	adds r1, r3, #0
	adds r0, r2, #0
	bl __adddf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, [sp, #0x6c]
	ldr r3, [sp, #0x70]
	bl __gtdf2
	cmp r0, #0
	bgt _082999F4
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x6c]
	ldr r3, [sp, #0x70]
	bl __eqdf2
	cmp r0, #0
	beq _082999EA
	b _08299EDA
_082999EA:
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	bne _082999F4
	b _08299EDA
_082999F4:
	movs r0, #0x30
_082999F6:
	movs r2, #1
	rsbs r2, r2, #0
	add sb, r2
	mov r3, sb
	ldrb r3, [r3]
	cmp r3, #0x39
	bne _08299A12
	ldr r1, [sp, #0x74]
	cmp sb, r1
	bne _082999F6
	ldr r2, [sp, #0x24]
	adds r2, #1
	str r2, [sp, #0x24]
	strb r0, [r1]
_08299A12:
	mov r3, sb
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_08299A1A:
	movs r0, #1
	add sb, r0
	b _08299EDA
	.align 2, 0
_08299A20: .4byte 0x40240000
_08299A24: .4byte 0x00000000
_08299A28: .4byte 0x00000000
_08299A2C: .4byte 0x00000000
_08299A30:
	ldr r5, [sp, #0x10]
	ldr r6, [sp, #0x14]
	movs r1, #0
	str r1, [sp, #0x60]
	movs r2, #0
	str r2, [sp, #0x64]
	ldr r3, [sp, #0x30]
	cmp r3, #0
	beq _08299AA6
	ldr r1, [sp, #0xc]
	cmp r1, #1
	bgt _08299A64
	ldr r2, [sp, #0x58]
	cmp r2, #0
	beq _08299A5C
	ldr r3, _08299A58
	adds r3, r3, r0
	mov r8, r3
	b _08299A90
	.align 2, 0
_08299A58: .4byte 0x00000433
_08299A5C:
	ldr r1, [sp, #8]
	movs r0, #0x36
	subs r0, r0, r1
	b _08299A8E
_08299A64:
	ldr r4, [sp, #0x18]
	subs r4, #1
	ldr r0, [sp, #0x14]
	cmp r0, r4
	blt _08299A72
	subs r6, r0, r4
	b _08299A82
_08299A72:
	ldr r1, [sp, #0x14]
	subs r4, r4, r1
	ldr r2, [sp, #0x38]
	adds r2, r2, r4
	str r2, [sp, #0x38]
	adds r1, r1, r4
	str r1, [sp, #0x14]
	movs r6, #0
_08299A82:
	ldr r3, [sp, #0x18]
	mov r8, r3
	cmp r3, #0
	bge _08299A90
	subs r5, r5, r3
	movs r0, #0
_08299A8E:
	mov r8, r0
_08299A90:
	ldr r1, [sp, #0x10]
	add r1, r8
	str r1, [sp, #0x10]
	ldr r2, [sp, #0x34]
	add r2, r8
	str r2, [sp, #0x34]
	mov r0, sl
	movs r1, #1
	bl _i2b
	str r0, [sp, #0x64]
_08299AA6:
	cmp r5, #0
	ble _08299AC8
	ldr r3, [sp, #0x34]
	cmp r3, #0
	ble _08299AC8
	mov r8, r3
	cmp r8, r5
	ble _08299AB8
	mov r8, r5
_08299AB8:
	ldr r0, [sp, #0x10]
	mov r1, r8
	subs r0, r0, r1
	str r0, [sp, #0x10]
	subs r5, r5, r1
	ldr r2, [sp, #0x34]
	subs r2, r2, r1
	str r2, [sp, #0x34]
_08299AC8:
	ldr r3, [sp, #0x14]
	cmp r3, #0
	ble _08299B16
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _08299B0A
	cmp r6, #0
	ble _08299AFA
	mov r0, sl
	ldr r1, [sp, #0x64]
	adds r2, r6, #0
	bl _pow5mult
	str r0, [sp, #0x64]
	mov r0, sl
	ldr r1, [sp, #0x64]
	ldr r2, [sp, #0x5c]
	bl _multiply
	adds r4, r0, #0
	mov r0, sl
	ldr r1, [sp, #0x5c]
	bl _Bfree
	str r4, [sp, #0x5c]
_08299AFA:
	ldr r1, [sp, #0x14]
	subs r4, r1, r6
	cmp r4, #0
	beq _08299B16
	mov r0, sl
	ldr r1, [sp, #0x5c]
	adds r2, r4, #0
	b _08299B10
_08299B0A:
	mov r0, sl
	ldr r1, [sp, #0x5c]
	ldr r2, [sp, #0x14]
_08299B10:
	bl _pow5mult
	str r0, [sp, #0x5c]
_08299B16:
	mov r0, sl
	movs r1, #1
	bl _i2b
	str r0, [sp, #0x68]
	ldr r2, [sp, #0x38]
	cmp r2, #0
	ble _08299B30
	mov r0, sl
	ldr r1, [sp, #0x68]
	bl _pow5mult
	str r0, [sp, #0x68]
_08299B30:
	ldr r3, [sp, #0xc]
	cmp r3, #1
	bgt _08299B6C
	ldr r0, [sp, #0x44]
	cmp r0, #0
	bne _08299B68
	ldr r0, _08299B60
	ldr r1, [sp, #0x40]
	ands r0, r1
	cmp r0, #0
	bne _08299B68
	ldr r0, _08299B64
	ands r1, r0
	cmp r1, #0
	beq _08299B68
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r2, [sp, #0x34]
	adds r2, #1
	str r2, [sp, #0x34]
	movs r3, #1
	str r3, [sp, #0x3c]
	b _08299B6C
	.align 2, 0
_08299B60: .4byte 0x000FFFFF
_08299B64: .4byte 0x7FF00000
_08299B68:
	movs r0, #0
	str r0, [sp, #0x3c]
_08299B6C:
	ldr r1, [sp, #0x38]
	cmp r1, #0
	beq _08299B98
	ldr r2, [sp, #0x68]
	ldr r1, [r2, #0x10]
	subs r1, #1
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x14
	adds r0, r0, r1
	ldr r0, [r0]
	bl _hi0bits
	ldr r1, [sp, #0x34]
	adds r1, #0x20
	subs r1, r1, r0
	mov r8, r1
	movs r0, #0x1f
	mov r3, r8
	ands r3, r0
	mov r8, r3
	b _08299BA6
_08299B98:
	ldr r0, [sp, #0x34]
	adds r0, #1
	mov r8, r0
	movs r0, #0x1f
	mov r1, r8
	ands r1, r0
	mov r8, r1
_08299BA6:
	mov r2, r8
	cmp r2, #0
	beq _08299BB2
	movs r0, #0x20
	subs r2, r0, r2
	mov r8, r2
_08299BB2:
	mov r3, r8
	cmp r3, #4
	ble _08299BBE
	movs r0, #4
	rsbs r0, r0, #0
	b _08299BC6
_08299BBE:
	mov r3, r8
	cmp r3, #3
	bgt _08299BD6
	movs r0, #0x1c
_08299BC6:
	add r8, r0
	ldr r1, [sp, #0x10]
	add r1, r8
	str r1, [sp, #0x10]
	add r5, r8
	ldr r2, [sp, #0x34]
	add r2, r8
	str r2, [sp, #0x34]
_08299BD6:
	ldr r3, [sp, #0x10]
	cmp r3, #0
	ble _08299BE8
	mov r0, sl
	ldr r1, [sp, #0x5c]
	adds r2, r3, #0
	bl _lshift
	str r0, [sp, #0x5c]
_08299BE8:
	ldr r0, [sp, #0x34]
	cmp r0, #0
	ble _08299BFA
	mov r0, sl
	ldr r1, [sp, #0x68]
	ldr r2, [sp, #0x34]
	bl _lshift
	str r0, [sp, #0x68]
_08299BFA:
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _08299C38
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl __mcmp
	cmp r0, #0
	bge _08299C38
	ldr r2, [sp, #0x24]
	subs r2, #1
	str r2, [sp, #0x24]
	mov r0, sl
	ldr r1, [sp, #0x5c]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x30]
	cmp r3, #0
	beq _08299C34
	mov r0, sl
	ldr r1, [sp, #0x64]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x64]
_08299C34:
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x18]
_08299C38:
	ldr r1, [sp, #0x18]
	cmp r1, #0
	bgt _08299C7C
	ldr r2, [sp, #0xc]
	cmp r2, #2
	ble _08299C7C
	cmp r1, #0
	blt _08299C62
	mov r0, sl
	ldr r1, [sp, #0x68]
	movs r2, #5
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x68]
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl __mcmp
	cmp r0, #0
	bgt _08299C6A
_08299C62:
	ldr r3, [sp, #0xa4]
	mvns r3, r3
	str r3, [sp, #0x24]
	b _08299EB2
_08299C6A:
	movs r0, #0x31
	mov r1, sb
	strb r0, [r1]
	movs r2, #1
	add sb, r2
	ldr r3, [sp, #0x24]
	adds r3, #1
	str r3, [sp, #0x24]
	b _08299EB2
_08299C7C:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	bne _08299C84
	b _08299DFA
_08299C84:
	cmp r5, #0
	ble _08299C94
	mov r0, sl
	ldr r1, [sp, #0x64]
	adds r2, r5, #0
	bl _lshift
	str r0, [sp, #0x64]
_08299C94:
	ldr r1, [sp, #0x64]
	str r1, [sp, #0x60]
	ldr r2, [sp, #0x3c]
	cmp r2, #0
	beq _08299CC6
	ldr r1, [r1, #4]
	mov r0, sl
	bl _Balloc
	str r0, [sp, #0x64]
	adds r0, #0xc
	ldr r1, [sp, #0x60]
	adds r1, #0xc
	ldr r3, [sp, #0x60]
	ldr r2, [r3, #0x10]
	lsls r2, r2, #2
	adds r2, #8
	bl memcpy
	mov r0, sl
	ldr r1, [sp, #0x64]
	movs r2, #1
	bl _lshift
	str r0, [sp, #0x64]
_08299CC6:
	movs r0, #1
	mov r8, r0
	mov r1, r8
	ldr r2, [sp, #0x44]
	ands r2, r1
	str r2, [sp, #0x80]
	b _08299D1C
_08299CD4:
	mov r0, sl
	ldr r1, [sp, #0x5c]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x60]
	ldr r0, [sp, #0x64]
	cmp r3, r0
	bne _08299CFC
	mov r0, sl
	ldr r1, [sp, #0x64]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x64]
	str r0, [sp, #0x60]
	b _08299D18
_08299CFC:
	mov r0, sl
	ldr r1, [sp, #0x60]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x60]
	mov r0, sl
	ldr r1, [sp, #0x64]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x64]
_08299D18:
	movs r1, #1
	add r8, r1
_08299D1C:
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl sub_082990B4
	adds r7, r0, #0
	adds r7, #0x30
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x60]
	bl __mcmp
	adds r4, r0, #0
	mov r0, sl
	ldr r1, [sp, #0x68]
	ldr r2, [sp, #0x64]
	bl __mdiff
	adds r5, r0, #0
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne _08299D50
	ldr r0, [sp, #0x5c]
	adds r1, r5, #0
	bl __mcmp
	adds r6, r0, #0
	b _08299D52
_08299D50:
	movs r6, #1
_08299D52:
	mov r0, sl
	adds r1, r5, #0
	bl _Bfree
	cmp r6, #0
	bne _08299D7E
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _08299D7E
	ldr r3, [sp, #0x80]
	cmp r3, #0
	bne _08299D7E
	cmp r7, #0x39
	beq _08299DD0
	cmp r4, #0
	ble _08299D74
	adds r7, #1
_08299D74:
	mov r0, sb
	strb r7, [r0]
	movs r1, #1
	add sb, r1
	b _08299EB2
_08299D7E:
	cmp r4, #0
	blt _08299D92
	cmp r4, #0
	bne _08299DC8
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _08299DC8
	ldr r3, [sp, #0x80]
	cmp r3, #0
	bne _08299DC8
_08299D92:
	cmp r6, #0
	ble _08299DC2
	mov r0, sl
	ldr r1, [sp, #0x5c]
	movs r2, #1
	bl _lshift
	str r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl __mcmp
	adds r6, r0, #0
	cmp r6, #0
	bgt _08299DBC
	cmp r6, #0
	bne _08299DC2
	adds r0, r7, #0
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08299DC2
_08299DBC:
	adds r7, #1
	cmp r7, #0x3a
	beq _08299DD0
_08299DC2:
	mov r2, sb
	strb r7, [r2]
	b _08299E7A
_08299DC8:
	cmp r6, #0
	ble _08299DE8
	cmp r7, #0x39
	bne _08299DDC
_08299DD0:
	movs r0, #0x39
	mov r1, sb
	strb r0, [r1]
	movs r2, #1
	add sb, r2
	b _08299E50
_08299DDC:
	adds r0, r7, #1
	mov r3, sb
	strb r0, [r3]
	movs r0, #1
	add sb, r0
	b _08299EB2
_08299DE8:
	mov r1, sb
	strb r7, [r1]
	movs r2, #1
	add sb, r2
	ldr r3, [sp, #0x18]
	cmp r8, r3
	beq _08299DF8
	b _08299CD4
_08299DF8:
	b _08299E2C
_08299DFA:
	movs r0, #1
	mov r8, r0
	b _08299E12
_08299E00:
	mov r0, sl
	ldr r1, [sp, #0x5c]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x5c]
	movs r1, #1
	add r8, r1
_08299E12:
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl sub_082990B4
	adds r7, r0, #0
	adds r7, #0x30
	mov r2, sb
	strb r7, [r2]
	movs r3, #1
	add sb, r3
	ldr r0, [sp, #0x18]
	cmp r8, r0
	blt _08299E00
_08299E2C:
	mov r0, sl
	ldr r1, [sp, #0x5c]
	movs r2, #1
	bl _lshift
	str r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl __mcmp
	adds r4, r0, #0
	cmp r4, #0
	bgt _08299E50
	cmp r4, #0
	bne _08299E92
	movs r0, #1
	ands r7, r0
	cmp r7, #0
	beq _08299E92
_08299E50:
	movs r1, #1
	rsbs r1, r1, #0
	add sb, r1
	mov r2, sb
	ldrb r2, [r2]
	cmp r2, #0x39
	bne _08299E72
_08299E5E:
	ldr r3, [sp, #0x74]
	cmp sb, r3
	beq _08299E80
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	ldrb r1, [r1]
	cmp r1, #0x39
	beq _08299E5E
_08299E72:
	mov r2, sb
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
_08299E7A:
	movs r3, #1
	add sb, r3
	b _08299EB2
_08299E80:
	ldr r0, [sp, #0x24]
	adds r0, #1
	str r0, [sp, #0x24]
	movs r0, #0x31
	ldr r1, [sp, #0x74]
	strb r0, [r1]
	adds r1, #1
	mov sb, r1
	b _08299EB2
_08299E92:
	movs r2, #1
	rsbs r2, r2, #0
	add sb, r2
	mov r3, sb
	ldrb r3, [r3]
	cmp r3, #0x30
	bne _08299EAE
_08299EA0:
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	ldrb r1, [r1]
	cmp r1, #0x30
	beq _08299EA0
_08299EAE:
	movs r2, #1
	add sb, r2
_08299EB2:
	mov r0, sl
	ldr r1, [sp, #0x68]
	bl _Bfree
	ldr r3, [sp, #0x64]
	cmp r3, #0
	beq _08299EDA
	ldr r0, [sp, #0x60]
	cmp r0, #0
	beq _08299ED2
	cmp r0, r3
	beq _08299ED2
	mov r0, sl
	ldr r1, [sp, #0x60]
	bl _Bfree
_08299ED2:
	mov r0, sl
	ldr r1, [sp, #0x64]
	bl _Bfree
_08299EDA:
	mov r0, sl
	ldr r1, [sp, #0x5c]
	bl _Bfree
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
	ldr r0, [sp, #0x24]
	adds r0, #1
	ldr r2, [sp, #0xa8]
	str r0, [r2]
	ldr r3, [sp, #0xb0]
	cmp r3, #0
	beq _08299EF8
	str r1, [r3]
_08299EF8:
	ldr r0, [sp, #0x74]
_08299EFA:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	thumb_func_end _dtoa_r
