.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0802B954
sub_0802B954: @ 0x0802B954
	push {r4, lr}
	sub sp, #4
	ldr r1, _0802B970
	ldr r0, [r1]
	ldrh r0, [r0, #0xa]
	adds r4, r1, #0
	cmp r0, #5
	bhi _0802BA18
	lsls r0, r0, #2
	ldr r1, _0802B974
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802B970: .4byte 0x020229B0
_0802B974: .4byte 0x0802B978
_0802B978: @ jump table
	.4byte _0802B990 @ case 0
	.4byte _0802B996 @ case 1
	.4byte _0802B9A6 @ case 2
	.4byte _0802B9BC @ case 3
	.4byte _0802B9E2 @ case 4
	.4byte _0802BA08 @ case 5
_0802B990:
	bl sub_0802D704
	b _0802B9F2
_0802B996:
	bl sub_0802D734
	cmp r0, #0
	bne _0802BA18
	movs r0, #7
	bl sub_0802CDBC
	b _0802B9F2
_0802B9A6:
	bl sub_0802CDE4
	adds r2, r0, #0
	cmp r2, #0
	bne _0802BA18
	ldr r0, _0802B9B8
	ldr r1, [r0]
	strh r2, [r1, #0x3c]
	b _0802B9F6
	.align 2, 0
_0802B9B8: .4byte 0x020229B0
_0802B9BC:
	ldr r1, [r4]
	ldrh r0, [r1, #0x3c]
	adds r0, #1
	strh r0, [r1, #0x3c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x78
	bls _0802BA18
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r1, #0
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r1, [r4]
	b _0802B9F6
_0802B9E2:
	ldr r0, _0802BA00
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0802BA18
	bl SetCloseLinkCallback
_0802B9F2:
	ldr r0, _0802BA04
	ldr r1, [r0]
_0802B9F6:
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	b _0802BA18
	.align 2, 0
_0802BA00: .4byte 0x02037C74
_0802BA04: .4byte 0x020229B0
_0802BA08:
	ldr r0, _0802BA14
	ldrb r0, [r0]
	cmp r0, #0
	bne _0802BA18
	movs r0, #0
	b _0802BA1A
	.align 2, 0
_0802BA14: .4byte 0x030031C4
_0802BA18:
	movs r0, #1
_0802BA1A:
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802B954

	thumb_func_start sub_0802BA24
sub_0802BA24: @ 0x0802BA24
	push {r4, lr}
	ldr r4, _0802BA3C
	ldr r0, [r4]
	ldrh r0, [r0, #0xa]
	cmp r0, #1
	beq _0802BA5A
	cmp r0, #1
	bgt _0802BA40
	cmp r0, #0
	beq _0802BA46
	b _0802BA6E
	.align 2, 0
_0802BA3C: .4byte 0x020229B0
_0802BA40:
	cmp r0, #2
	beq _0802BA6A
	b _0802BA6E
_0802BA46:
	bl sub_0802D704
	movs r0, #0
	bl sub_0802DA5C
	ldr r1, [r4]
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
	b _0802BA6E
_0802BA5A:
	bl sub_0802D734
	cmp r0, #0
	bne _0802BA6E
	ldr r1, [r4]
	ldrh r0, [r1, #0xa]
	adds r0, #1
	strh r0, [r1, #0xa]
_0802BA6A:
	movs r0, #0
	b _0802BA70
_0802BA6E:
	movs r0, #1
_0802BA70:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802BA24

	thumb_func_start sub_0802BA78
sub_0802BA78: @ 0x0802BA78
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	lsls r0, r0, #2
	add r0, sl
	lsls r0, r0, #3
	ldr r1, _0802BAAC
	adds r6, r0, r1
	mov r0, sl
	movs r1, #0xe
	bl GetWordTaskArg
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _0802BABC
	cmp r0, #1
	beq _0802BAD0
	b _0802BB3C
	.align 2, 0
_0802BAAC: .4byte 0x03005B68
_0802BAB0:
	bl sub_0802A814
	mov r0, sl
	bl DestroyTask
	b _0802BB3C
_0802BABC:
	movs r1, #0
	adds r0, r6, #0
	adds r0, #8
_0802BAC2:
	strh r1, [r0, #4]
	subs r0, #2
	cmp r0, r6
	bge _0802BAC2
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
_0802BAD0:
	mov r3, r8
	ldrb r1, [r3, #6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0802BB4C
	adds r0, r0, r4
	add r0, r8
	bl sub_0802DDA4
	movs r2, #0
	adds r5, r6, #4
	mov sb, r2
	movs r7, #0x83
	lsls r7, r7, #8
	add r7, r8
	add r4, r8
_0802BAF2:
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _0802BB2C
	adds r0, r2, #0
	adds r1, r4, #0
	str r2, [sp]
	bl sub_0802DDC8
	ldr r2, [sp]
	cmp r0, #0
	beq _0802BB2C
	ldr r1, _0802BB50
	add r1, sb
	adds r0, r7, #0
	bl StringCopy
	movs r0, #1
	strh r0, [r5]
	ldrh r0, [r6, #2]
	adds r0, #1
	strh r0, [r6, #2]
	movs r3, #2
	ldrsh r0, [r6, r3]
	ldr r2, [sp]
	mov r1, r8
	ldrb r1, [r1, #5]
	cmp r0, r1
	beq _0802BAB0
_0802BB2C:
	adds r5, #2
	movs r3, #0x1c
	add sb, r3
	adds r7, #0x24
	adds r4, #0xc
	adds r2, #1
	cmp r2, #4
	ble _0802BAF2
_0802BB3C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802BB4C: .4byte 0x000082A8
_0802BB50: .4byte 0x020226A8
	thumb_func_end sub_0802BA78

	thumb_func_start sub_0802BB54
sub_0802BB54: @ 0x0802BB54
	push {lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0802BB70
	ldr r2, [r1]
	movs r1, #0xe
	bl SetWordTaskArg
	pop {r0}
	bx r0
	.align 2, 0
_0802BB70: .4byte 0x020229B0
	thumb_func_end sub_0802BB54

	thumb_func_start sub_0802BB74
sub_0802BB74: @ 0x0802BB74
	ldr r0, _0802BB90
	ldr r2, [r0]
	adds r0, r2, #0
	adds r0, #0x4a
	movs r1, #0
	strh r1, [r0]
	movs r0, #6
	str r0, [r2, #0x14]
	strh r1, [r2, #0x34]
	str r1, [r2, #0x1c]
	strh r1, [r2, #0x36]
	str r1, [r2, #0x10]
	bx lr
	.align 2, 0
_0802BB90: .4byte 0x020229B0
	thumb_func_end sub_0802BB74

	thumb_func_start sub_0802BB94
sub_0802BB94: @ 0x0802BB94
	push {r4, lr}
	ldr r3, _0802BBD0
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x4a
	movs r4, #0
	movs r2, #0
	strh r2, [r1]
	ldr r1, _0802BBD4
	strh r1, [r0, #0x34]
	movs r1, #7
	str r1, [r0, #0x14]
	strh r2, [r0, #0x36]
	str r2, [r0, #0x10]
	adds r0, #0x51
	strb r4, [r0]
	ldr r0, [r3]
	adds r0, #0x50
	strb r4, [r0]
	ldr r0, [r3]
	str r2, [r0, #0x20]
	adds r1, r0, #0
	adds r1, #0x4e
	strh r2, [r1]
	str r2, [r0, #0x6c]
	bl sub_0802BC70
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802BBD0: .4byte 0x020229B0
_0802BBD4: .4byte 0x000006FF
	thumb_func_end sub_0802BB94

	thumb_func_start sub_0802BBD8
sub_0802BBD8: @ 0x0802BBD8
	push {r4, lr}
	ldr r4, _0802BC30
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x46
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802BC28
	adds r1, #0x4a
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	bl sub_0802BC3C
	ldr r3, [r4]
	ldrh r1, [r3, #0x34]
	adds r2, r1, r0
	strh r2, [r3, #0x34]
	lsls r1, r2, #0x10
	ldr r0, _0802BC34
	cmp r1, r0
	bls _0802BC0A
	ldr r1, _0802BC38
	adds r0, r2, r1
	strh r0, [r3, #0x34]
_0802BC0A:
	ldr r1, [r4]
	ldr r2, [r1, #0x14]
	str r2, [r1, #0x18]
	ldrh r0, [r1, #0x34]
	lsrs r0, r0, #8
	str r0, [r1, #0x14]
	cmp r0, #6
	bls _0802BC28
	cmp r2, #6
	bhi _0802BC28
	ldrh r0, [r1, #0x36]
	adds r0, #1
	strh r0, [r1, #0x36]
	bl sub_0802BC70
_0802BC28:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802BC30: .4byte 0x020229B0
_0802BC34: .4byte 0x09FE0000
_0802BC38: .4byte 0xFFFFF601
	thumb_func_end sub_0802BBD8

	thumb_func_start sub_0802BC3C
sub_0802BC3C: @ 0x0802BC3C
	push {lr}
	ldr r0, _0802BC4C
	ldr r2, [r0]
	ldr r0, [r2, #0x10]
	cmp r0, #0
	beq _0802BC50
	movs r0, #0
	b _0802BC66
	.align 2, 0
_0802BC4C: .4byte 0x020229B0
_0802BC50:
	ldr r3, [r2, #0x1c]
	ldrh r1, [r2, #0x34]
	ldr r0, _0802BC6C
	cmp r1, r0
	bhi _0802BC64
	ldr r0, [r2, #0x20]
	adds r0, #0x50
	str r0, [r2, #0x20]
	lsrs r0, r0, #8
	adds r3, r3, r0
_0802BC64:
	adds r0, r3, #0
_0802BC66:
	pop {r1}
	bx r1
	.align 2, 0
_0802BC6C: .4byte 0x000005FF
	thumb_func_end sub_0802BC3C

	thumb_func_start sub_0802BC70
sub_0802BC70: @ 0x0802BC70
	push {r4, lr}
	ldr r4, _0802BCA0
	ldr r3, [r4]
	movs r0, #0
	str r0, [r3, #0x20]
	adds r1, r3, #0
	adds r1, #0x4e
	ldrh r0, [r1]
	cmp r0, #0
	beq _0802BCB4
	subs r0, #1
	strh r0, [r1]
	ldr r0, [r3, #0x6c]
	cmp r0, #0
	beq _0802BD7E
	bl sub_0802BD8C
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	beq _0802BCA4
	ldr r1, [r4]
	b _0802BD7A
	.align 2, 0
_0802BCA0: .4byte 0x020229B0
_0802BCA4:
	ldr r1, [r4]
	ldr r0, [r1, #0x28]
	cmp r0, #0x36
	bls _0802BCB0
	movs r0, #0x1e
	b _0802BD7C
_0802BCB0:
	movs r0, #0x52
	b _0802BD7C
_0802BCB4:
	adds r2, r3, #0
	adds r2, #0x50
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0802BD08
	ldr r0, _0802BD00
	ldrb r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	adds r0, r3, #0
	adds r0, #0x51
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	str r0, [r3, #0x28]
	bl sub_0802BD8C
	ldr r2, [r4]
	ldr r3, _0802BD04
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r0, [r1]
	adds r0, #2
	adds r1, r2, #0
	adds r1, #0x4e
	strh r0, [r1]
	adds r2, #0x50
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _0802BD76
	.align 2, 0
_0802BD00: .4byte 0x082CEEC8
_0802BD04: .4byte 0x082CEED8
_0802BD08:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bne _0802BD24
	adds r1, r3, #0
	adds r1, #0x51
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0802BD20
	adds r0, #1
	strb r0, [r1]
	b _0802BD24
_0802BD20:
	movs r0, #1
	str r0, [r3, #0x6c]
_0802BD24:
	ldr r2, _0802BD84
	ldr r4, _0802BD88
	ldr r0, [r4]
	mov ip, r0
	mov r3, ip
	adds r3, #0x50
	ldrb r0, [r3]
	movs r1, #0xf
	subs r1, r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	mov r0, ip
	adds r0, #0x51
	ldrb r2, [r0]
	lsls r0, r2, #3
	subs r0, r0, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x28]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xf
	bls _0802BD76
	bl sub_0802BD8C
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	bne _0802BD6E
	ldr r1, [r4]
	ldr r0, [r1, #0x28]
	subs r0, #5
	str r0, [r1, #0x28]
_0802BD6E:
	ldr r0, [r4]
	adds r0, #0x50
	movs r1, #0
	strb r1, [r0]
_0802BD76:
	ldr r0, _0802BD88
	ldr r1, [r0]
_0802BD7A:
	ldr r0, [r1, #0x28]
_0802BD7C:
	str r0, [r1, #0x1c]
_0802BD7E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802BD84: .4byte 0x082CEEC8
_0802BD88: .4byte 0x020229B0
	thumb_func_end sub_0802BC70

	thumb_func_start sub_0802BD8C
sub_0802BD8C: @ 0x0802BD8C
	ldr r0, _0802BDA0
	ldr r2, [r0]
	ldr r1, [r2, #0x24]
	ldr r0, _0802BDA4
	muls r0, r1, r0
	ldr r1, _0802BDA8
	adds r0, r0, r1
	str r0, [r2, #0x24]
	lsrs r0, r0, #0x10
	bx lr
	.align 2, 0
_0802BDA0: .4byte 0x020229B0
_0802BDA4: .4byte 0x41C64E6D
_0802BDA8: .4byte 0x00006073
	thumb_func_end sub_0802BD8C

	thumb_func_start sub_0802BDAC
sub_0802BDAC: @ 0x0802BDAC
	push {lr}
	ldr r0, _0802BDC8
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x10]
	movs r0, #6
	str r0, [r1, #0x14]
	ldr r0, _0802BDCC
	strh r0, [r1, #0x34]
	bl sub_0802BF64
	pop {r0}
	bx r0
	.align 2, 0
_0802BDC8: .4byte 0x020229B0
_0802BDCC: .4byte 0x000005FF
	thumb_func_end sub_0802BDAC

	thumb_func_start sub_0802BDD0
sub_0802BDD0: @ 0x0802BDD0
	ldr r0, _0802BDD8
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	bx lr
	.align 2, 0
_0802BDD8: .4byte 0x020229B0
	thumb_func_end sub_0802BDD0
