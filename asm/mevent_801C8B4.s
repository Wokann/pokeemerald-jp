.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start sub_0801C8B4
sub_0801C8B4: @ 0x0801C8B4
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r4, _0801C94C
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0xf2
	adds r1, #4
	movs r2, #0x14
	bl memcpy
	ldr r0, [r4]
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r0, #0xff
	strb r0, [r1]
	adds r6, r4, #0
_0801C8D6:
	ldr r2, [r6]
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #2
	adds r4, r1, r5
	adds r0, r4, r2
	ldr r3, _0801C950
	adds r0, r0, r3
	adds r1, r1, r2
	adds r1, #0x18
	movs r2, #0x14
	bl memcpy
	ldr r0, [r6]
	ldr r1, _0801C954
	adds r0, r0, r1
	adds r0, r0, r4
	movs r1, #0xff
	strb r1, [r0]
	cmp r5, #7
	bls _0801C916
	ldr r1, [r6]
	ldr r2, _0801C950
	adds r0, r1, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _0801C916
	adds r1, #0xe8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0801C916:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #9
	bls _0801C8D6
	ldr r2, _0801C94C
	ldr r1, [r2]
	movs r3, #0xee
	lsls r3, r3, #1
	adds r1, r1, r3
	ldr r0, _0801C958
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldr r0, [r0]
	str r0, [r1]
	ldr r2, [r2]
	adds r0, r2, #0
	adds r0, #0xe8
	ldrh r1, [r0]
	movs r4, #0xf2
	lsls r4, r4, #1
	adds r0, r2, r4
	strh r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801C94C: .4byte 0x0202292C
_0801C950: .4byte 0x00000107
_0801C954: .4byte 0x0000011B
_0801C958: .4byte 0x082C4324
	thumb_func_end sub_0801C8B4

	thumb_func_start sub_0801C95C
sub_0801C95C: @ 0x0801C95C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	movs r7, #0
	ldr r6, _0801CA60
	ldr r0, [r6]
	adds r0, #0xec
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r6]
	adds r0, #0xee
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r6]
	adds r0, #0xec
	ldrb r0, [r0]
	movs r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	adds r0, #0xee
	ldrb r0, [r0]
	movs r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	adds r0, #0xf2
	bl StringLength
	adds r5, r0, #0
	movs r0, #3
	movs r1, #2
	bl GetFontAttribute
	adds r4, r0, #0
	movs r0, #3
	movs r1, #0
	bl GetFontAttribute
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r4, r0
	adds r0, r5, #0
	muls r0, r4, r0
	asrs r0, r0, #1
	movs r2, #0x71
	subs r2, r2, r0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r4, [r6]
	adds r0, r4, #0
	adds r0, #0xec
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r1, [r1]
	ldrb r1, [r1]
	lsls r1, r1, #0x1c
	lsrs r1, r1, #0x1c
	lsls r3, r1, #1
	adds r3, r3, r1
	ldr r1, _0801CA64
	adds r3, r3, r1
	str r3, [sp]
	str r7, [sp, #4]
	adds r4, #0xf2
	str r4, [sp, #8]
	movs r1, #3
	movs r3, #6
	bl AddTextPrinterParameterized3
_0801C9F4:
	ldr r5, _0801CA60
	ldr r4, [r5]
	adds r0, r4, #0
	adds r0, #0xee
	ldrb r0, [r0]
	lsls r3, r7, #4
	adds r3, #4
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r1, r4, #0
	adds r1, #0xe0
	ldr r1, [r1]
	ldrb r1, [r1]
	lsrs r1, r1, #4
	lsls r2, r1, #1
	adds r2, r2, r1
	ldr r1, _0801CA64
	adds r2, r2, r1
	str r2, [sp]
	movs r1, #0
	str r1, [sp, #4]
	lsls r1, r7, #2
	adds r1, r1, r7
	lsls r1, r1, #2
	adds r1, r1, r7
	ldr r2, _0801CA68
	adds r1, r1, r2
	adds r4, r4, r1
	str r4, [sp, #8]
	movs r1, #3
	movs r2, #3
	bl AddTextPrinterParameterized3
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #9
	bls _0801C9F4
	ldr r0, [r5]
	adds r0, #0xec
	ldrb r0, [r0]
	movs r1, #3
	bl CopyWindowToVram
	ldr r0, [r5]
	adds r0, #0xee
	ldrb r0, [r0]
	movs r1, #3
	bl CopyWindowToVram
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801CA60: .4byte 0x0202292C
_0801CA64: .4byte 0x082C430C
_0801CA68: .4byte 0x00000107
	thumb_func_end sub_0801C95C

	thumb_func_start sub_0801CA6C
sub_0801CA6C: @ 0x0801CA6C
	push {r4, r5, lr}
	ldr r0, _0801CAA0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0xe6
	ldrb r0, [r0]
	lsrs r4, r0, #1
	lsls r4, r4, #8
	adds r1, #0xe7
	ldrb r1, [r1]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0801CAA4
	movs r0, #2
	adds r1, r4, #0
	movs r2, #1
	bl ChangeBgY
	movs r0, #3
	adds r1, r4, #0
	movs r2, #1
	bl ChangeBgY
	b _0801CAB8
	.align 2, 0
_0801CAA0: .4byte 0x0202292C
_0801CAA4:
	movs r0, #2
	adds r1, r4, #0
	movs r2, #2
	bl ChangeBgY
	movs r0, #3
	adds r1, r4, #0
	movs r2, #2
	bl ChangeBgY
_0801CAB8:
	ldr r2, _0801CAF8
	ldr r0, [r2]
	adds r4, r0, #0
	adds r4, #0xe7
	ldrb r3, [r4]
	lsrs r1, r3, #1
	adds r0, #0xe6
	ldrb r0, [r0]
	lsrs r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	movs r5, #1
	adds r0, r5, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r4]
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0xe7
	ldrb r3, [r0]
	lsrs r0, r3, #1
	adds r4, r2, #0
	cmp r0, #0xf
	bls _0801CB1E
	adds r0, r5, #0
	ands r0, r3
	cmp r0, #0
	beq _0801CAFC
	adds r1, #0xea
	ldrh r0, [r1]
	adds r0, #1
	b _0801CB02
	.align 2, 0
_0801CAF8: .4byte 0x0202292C
_0801CAFC:
	adds r1, #0xea
	ldrh r0, [r1]
	subs r0, #1
_0801CB02:
	strh r0, [r1]
	ldr r1, [r4]
	adds r1, #0xe6
	ldrb r2, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r4]
	adds r1, #0xe7
	ldrb r2, [r1]
	movs r0, #1
	ands r0, r2
	strb r0, [r1]
_0801CB1E:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_0801CA6C
