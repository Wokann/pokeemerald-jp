.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified








	thumb_func_start sub_080FA058
sub_080FA058: @ 0x080FA058
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0
	bl GetMonData3
	lsls r0, r0, #0x10
	str r0, [sp, #4]
	lsrs r0, r0, #0x10
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0x27
	bl GetMonData3
	adds r7, r0, #0
	movs r6, #0xf
	ands r7, r6
	adds r0, r5, #0
	movs r1, #0x28
	bl GetMonData3
	mov r8, r0
	mov r1, r8
	ands r1, r6
	mov r8, r1
	adds r0, r5, #0
	movs r1, #0x29
	bl GetMonData3
	mov sb, r0
	mov r3, sb
	ands r3, r6
	mov sb, r3
	adds r0, r5, #0
	movs r1, #0x2a
	bl GetMonData3
	mov sl, r0
	ands r0, r6
	mov sl, r0
	adds r0, r5, #0
	movs r1, #0x2b
	bl GetMonData3
	adds r4, r0, #0
	ands r4, r6
	adds r0, r5, #0
	movs r1, #0x2c
	bl GetMonData3
	adds r2, r0, #0
	ands r2, r6
	mov r1, r8
	mov r3, sb
	eors r1, r3
	mov r8, r1
	mov r0, r8
	muls r0, r7, r0
	movs r1, #0xff
	ldr r3, [sp]
	ands r3, r1
	eors r0, r3
	eors r4, r2
	mov r1, sl
	muls r1, r4, r1
	ldr r3, [sp, #4]
	lsrs r2, r3, #0x18
	eors r1, r2
	lsls r0, r0, #8
	adds r0, r0, r1
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_080FA058

	thumb_func_start sub_080FA0FC
sub_080FA0FC: @ 0x080FA0FC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #1
	ldr r3, _080FA118
_080FA106:
	lsls r0, r1, #3
	adds r0, r0, r3
	ldrh r0, [r0, #4]
	cmp r2, r0
	bhs _080FA11C
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080FA128
	.align 2, 0
_080FA118: .4byte 0x085694D0
_080FA11C:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xe
	bls _080FA106
	adds r0, r1, #0
_080FA128:
	pop {r1}
	bx r1
	thumb_func_end sub_080FA0FC

	thumb_func_start sub_080FA12C
sub_080FA12C: @ 0x080FA12C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl GetPokedexHeightWeight
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	adds r0, r6, #0
	bl sub_080FA0FC
	lsls r0, r0, #0x18
	ldr r1, _080FA19C
	lsrs r0, r0, #0x15
	adds r0, r0, r1
	ldrh r1, [r0]
	str r1, [sp]
	movs r2, #0
	str r2, [sp, #4]
	ldrb r2, [r0, #2]
	movs r3, #0
	ldrh r4, [r0, #4]
	movs r5, #0
	adds r0, r6, #0
	movs r1, #0
	subs r0, r0, r4
	sbcs r1, r5
	bl __udivdi3
	ldr r2, [sp]
	ldr r3, [sp, #4]
	adds r2, r2, r0
	adcs r3, r1
	str r2, [sp]
	str r3, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl __muldi3
	movs r2, #0xa
	movs r3, #0
	bl __udivdi3
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080FA19C: .4byte 0x085694D0
	thumb_func_end sub_080FA12C

	thumb_func_start sub_080FA1A0
sub_080FA1A0: @ 0x080FA1A0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, _080FA1EC
	mov r0, sp
	movs r2, #2
	bl memcpy
	adds r0, r5, #0
	movs r1, #0xa
	bl __udivsi3
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	movs r3, #8
	bl ConvertIntToDecimalStringN
	mov r1, sp
	bl StringAppend
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0xa
	bl __umodsi3
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080FA1EC: .4byte 0x08569550
	thumb_func_end sub_080FA1A0

	thumb_func_start sub_080FA1F0
sub_080FA1F0: @ 0x080FA1F0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r1, _080FA208
	ldrh r0, [r1]
	cmp r0, #0xff
	bne _080FA20C
	movs r0, #0
	b _080FA276
	.align 2, 0
_080FA208: .4byte 0x02037290
_080FA20C:
	ldrh r1, [r1]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _080FA234
	adds r5, r1, r0
	adds r0, r5, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #1
	beq _080FA22E
	adds r0, r5, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, r6
	beq _080FA238
_080FA22E:
	movs r0, #1
	b _080FA276
	.align 2, 0
_080FA234: .4byte 0x02024190
_080FA238:
	mov r4, sp
	adds r0, r5, #0
	bl sub_080FA058
	strh r0, [r4]
	mov r0, sp
	ldrh r1, [r0]
	adds r0, r6, #0
	bl sub_080FA12C
	adds r5, r0, #0
	ldrh r1, [r7]
	adds r0, r6, #0
	bl sub_080FA12C
	adds r4, r0, #0
	ldr r0, _080FA270
	adds r1, r5, #0
	bl sub_080FA1A0
	cmp r5, r4
	bls _080FA274
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r7]
	movs r0, #3
	b _080FA276
	.align 2, 0
_080FA270: .4byte 0x02021C54
_080FA274:
	movs r0, #2
_080FA276:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080FA1F0

	thumb_func_start sub_080FA280
sub_080FA280: @ 0x080FA280
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrh r1, [r5]
	adds r0, r4, #0
	bl sub_080FA12C
	adds r1, r0, #0
	ldr r0, _080FA2C0
	bl sub_080FA1A0
	ldr r0, _080FA2C4
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	ldr r2, _080FA2C8
	adds r1, r1, r2
	bl StringCopy
	ldrh r1, [r5]
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	bne _080FA2D4
	ldr r0, _080FA2CC
	ldr r1, _080FA2D0
	bl StringCopy
	b _080FA2DE
	.align 2, 0
_080FA2C0: .4byte 0x02021C68
_080FA2C4: .4byte 0x02021C40
_080FA2C8: .4byte 0x082EA31C
_080FA2CC: .4byte 0x02021C54
_080FA2D0: .4byte 0x085CC31B
_080FA2D4:
	ldr r0, _080FA2E4
	ldr r1, _080FA2E8
	ldr r1, [r1]
	bl StringCopy
_080FA2DE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080FA2E4: .4byte 0x02021C54
_080FA2E8: .4byte 0x03005AF0
	thumb_func_end sub_080FA280

	thumb_func_start sub_080FA2EC
sub_080FA2EC: @ 0x080FA2EC
	push {lr}
	ldr r0, _080FA2FC
	movs r1, #0x80
	lsls r1, r1, #8
	bl VarSet
	pop {r0}
	bx r0
	.align 2, 0
_080FA2FC: .4byte 0x00004047
	thumb_func_end sub_080FA2EC

	thumb_func_start sub_080FA300
sub_080FA300: @ 0x080FA300
	push {lr}
	ldr r0, _080FA318
	bl GetVarPointer
	adds r1, r0, #0
	movs r0, #0x95
	lsls r0, r0, #1
	bl sub_080FA280
	pop {r0}
	bx r0
	.align 2, 0
_080FA318: .4byte 0x00004047
	thumb_func_end sub_080FA300

	thumb_func_start sub_080FA31C
sub_080FA31C: @ 0x080FA31C
	push {r4, lr}
	ldr r0, _080FA33C
	bl GetVarPointer
	adds r1, r0, #0
	ldr r4, _080FA340
	movs r0, #0x95
	lsls r0, r0, #1
	bl sub_080FA1F0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080FA33C: .4byte 0x00004047
_080FA340: .4byte 0x02037290
	thumb_func_end sub_080FA31C

	thumb_func_start sub_080FA344
sub_080FA344: @ 0x080FA344
	push {lr}
	ldr r0, _080FA354
	movs r1, #0x80
	lsls r1, r1, #8
	bl VarSet
	pop {r0}
	bx r0
	.align 2, 0
_080FA354: .4byte 0x0000404F
	thumb_func_end sub_080FA344

	thumb_func_start sub_080FA358
sub_080FA358: @ 0x080FA358
	push {lr}
	ldr r0, _080FA36C
	bl GetVarPointer
	adds r1, r0, #0
	ldr r0, _080FA370
	bl sub_080FA280
	pop {r0}
	bx r0
	.align 2, 0
_080FA36C: .4byte 0x0000404F
_080FA370: .4byte 0x00000127
	thumb_func_end sub_080FA358

	thumb_func_start sub_080FA374
sub_080FA374: @ 0x080FA374
	push {r4, lr}
	ldr r0, _080FA394
	bl GetVarPointer
	adds r1, r0, #0
	ldr r4, _080FA398
	ldr r0, _080FA39C
	bl sub_080FA1F0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080FA394: .4byte 0x0000404F
_080FA398: .4byte 0x02037290
_080FA39C: .4byte 0x00000127
	thumb_func_end sub_080FA374

	thumb_func_start sub_080FA3A0
sub_080FA3A0: @ 0x080FA3A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	movs r7, #0
	add r4, sp, #8
	movs r0, #1
	strb r0, [r4]
	ldr r1, _080FA428
	mov r0, sp
	movs r2, #7
	bl memcpy
	mov r8, r4
	cmp r6, #0xa
	bhi _080FA41C
	cmp r5, #0x40
	bhi _080FA41C
	ldr r0, _080FA42C
	ldr r0, [r0]
	ldr r1, _080FA430
	adds r0, r0, r1
	adds r0, r0, r6
	strb r5, [r0]
	movs r5, #0
_080FA3DA:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _080FA434
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _080FA40C
	adds r0, r4, #0
	movs r1, #6
	bl GetMonData3
	cmp r0, #0
	bne _080FA40C
	mov r1, sp
	adds r0, r1, r6
	ldrb r1, [r0]
	adds r0, r4, #0
	mov r2, r8
	bl SetMonData
	movs r7, #1
_080FA40C:
	adds r5, #1
	cmp r5, #5
	ble _080FA3DA
	cmp r7, #0
	beq _080FA41C
	ldr r0, _080FA438
	bl FlagSet
_080FA41C:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080FA428: .4byte 0x08569552
_080FA42C: .4byte 0x03005AEC
_080FA430: .4byte 0x000031A8
_080FA434: .4byte 0x02024190
_080FA438: .4byte 0x0000089B
	thumb_func_end sub_080FA3A0

