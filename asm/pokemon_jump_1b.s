.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_0802C574
sub_0802C574: @ 0x0802C574
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	b _0802C586
_0802C580:
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0802C586:
	cmp r4, #0
	beq _0802C598
	adds r0, r5, #0
	adds r1, r4, #0
	bl CheckBagHasSpace
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802C580
_0802C598:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_0802C574

	thumb_func_start sub_0802C5A0
sub_0802C5A0: @ 0x0802C5A0
	push {lr}
	bl GetLinkPlayerCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802C5A0

	thumb_func_start sub_0802C5B0
sub_0802C5B0: @ 0x0802C5B0
	ldr r0, _0802C5B8
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	bx lr
	.align 2, 0
_0802C5B8: .4byte 0x020229B0
	thumb_func_end sub_0802C5B0

	thumb_func_start sub_0802C5BC
sub_0802C5BC: @ 0x0802C5BC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0802C5D4
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0802C5D8
	adds r1, r1, r0
	ldr r0, [r2]
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0802C5D4: .4byte 0x020229B0
_0802C5D8: .4byte 0x000082A8
	thumb_func_end sub_0802C5BC

	thumb_func_start sub_0802C5DC
sub_0802C5DC: @ 0x0802C5DC
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0802C5F8
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r2]
	adds r0, r0, r1
	movs r1, #0x83
	lsls r1, r1, #8
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0802C5F8: .4byte 0x020229B0
	thumb_func_end sub_0802C5DC

	thumb_func_start sub_0802C5FC
sub_0802C5FC: @ 0x0802C5FC
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0802A8F4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mvns r0, r0
	lsrs r0, r0, #0x1f
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802C5FC

	thumb_func_start sub_0802C614
sub_0802C614: @ 0x0802C614
	push {r4, r5, lr}
	movs r5, #0
_0802C618:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _0802C648
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #5
	bl GetMonData3
	cmp r0, #0
	beq _0802C650
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl sub_0802C5FC
	cmp r0, #0
	beq _0802C650
	ldr r1, _0802C64C
	movs r0, #1
	b _0802C65A
	.align 2, 0
_0802C648: .4byte 0x02024190
_0802C64C: .4byte 0x02037290
_0802C650:
	adds r5, #1
	cmp r5, #5
	ble _0802C618
	ldr r1, _0802C664
	movs r0, #0
_0802C65A:
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802C664: .4byte 0x02037290
	thumb_func_end sub_0802C614

	thumb_func_start sub_0802C668
sub_0802C668: @ 0x0802C668
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r4, #0
	ldr r5, _0802C6A8
_0802C670:
	adds r0, r5, #0
	bl LoadCompressedSpriteSheet
	adds r5, #8
	adds r4, #1
	cmp r4, #4
	bls _0802C670
	movs r4, #0
	ldr r5, _0802C6AC
_0802C682:
	adds r0, r5, #0
	bl LoadSpritePalette
	adds r5, #8
	adds r4, #1
	cmp r4, #1
	bls _0802C682
	movs r0, #5
	bl IndexOfSpritePaletteTag
	strb r0, [r6, #0xe]
	movs r0, #6
	bl IndexOfSpritePaletteTag
	strb r0, [r6, #0xf]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802C6A8: .4byte 0x082CF694
_0802C6AC: .4byte 0x082CF6BC
	thumb_func_end sub_0802C668

	thumb_func_start sub_0802C6B0
sub_0802C6B0: @ 0x0802C6B0
	push {lr}
	movs r2, #0
	movs r1, #7
	adds r0, #0x3c
_0802C6B8:
	strh r2, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0802C6B8
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802C6B0

	thumb_func_start sub_0802C6C8
sub_0802C6C8: @ 0x0802C6C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	mov sb, r0
	adds r7, r1, #0
	ldr r0, [sp, #0x54]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x28]
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #0x2c]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	mov r1, sp
	ldr r0, _0802C71C
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	movs r0, #0x80
	lsls r0, r0, #6
	bl Alloc
	mov r8, r0
	movs r0, #0x80
	lsls r0, r0, #4
	bl Alloc
	mov sl, r0
	bl sub_0802C5B0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r6, r0
	bne _0802C720
	movs r0, #3
	b _0802C726
	.align 2, 0
_0802C71C: .4byte 0x082CF6CC
_0802C720:
	adds r0, r6, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0802C726:
	str r0, [sp, #0x30]
	mov r1, r8
	cmp r1, #0
	beq _0802C7E8
	mov r2, sl
	cmp r2, #0
	beq _0802C7E8
	ldrh r2, [r7]
	lsls r0, r2, #3
	ldr r1, _0802C7D4
	adds r0, r0, r1
	ldr r3, [r7, #8]
	mov r1, r8
	bl HandleLoadSpecialPokePic
	mov r3, r8
	str r3, [sp, #0x18]
	adds r4, r6, #0
	add r0, sp, #0x18
	ldr r5, _0802C7D8
	lsls r1, r4, #0x10
	movs r2, #0x80
	lsls r2, r2, #4
	orrs r1, r2
	str r1, [r0, #4]
	bl LoadSpriteSheet
	ldrh r0, [r7]
	ldr r1, [r7, #4]
	ldr r2, [r7, #8]
	bl GetMonSpritePalFromSpeciesAndPersonality
	str r0, [sp, #0x20]
	add r0, sp, #0x20
	ldr r1, [r0, #4]
	ands r1, r5
	orrs r1, r4
	str r1, [r0, #4]
	bl LoadCompressedSpritePalette
	mov r0, r8
	bl Free
	mov r0, sl
	bl Free
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	adds r0, r0, r6
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0, #2]
	adds r0, r0, r6
	strh r0, [r1, #2]
	ldr r4, [sp, #0x28]
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	ldr r0, [sp, #0x2c]
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	mov r0, sp
	ldr r3, [sp, #0x30]
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x40
	beq _0802C7E8
	lsls r0, r6, #2
	ldr r2, _0802C7DC
	add r2, sb
	adds r2, r2, r0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0802C7E0
	adds r0, r0, r1
	str r0, [r2]
	ldr r0, _0802C7E4
	add r0, sb
	adds r0, r0, r6
	add r1, sp, #0x30
	ldrb r1, [r1]
	strb r1, [r0]
	b _0802C7F4
	.align 2, 0
_0802C7D4: .4byte 0x082D4CA8
_0802C7D8: .4byte 0xFFFF0000
_0802C7DC: .4byte 0x000081A8
_0802C7E0: .4byte 0x020205AC
_0802C7E4: .4byte 0x000081FC
_0802C7E8:
	lsls r0, r6, #2
	ldr r1, _0802C804
	add r1, sb
	adds r1, r1, r0
	movs r0, #0
	str r0, [r1]
_0802C7F4:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C804: .4byte 0x000081A8
	thumb_func_end sub_0802C6C8

	thumb_func_start sub_0802C808
sub_0802C808: @ 0x0802C808
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r6, r1, #2
	ldr r0, _0802C860
	adds r5, r4, r0
	adds r5, r5, r6
	ldr r0, [r5]
	bl sub_0802C6B0
	ldr r2, [r5]
	ldr r0, _0802C864
	adds r4, r4, r0
	adds r4, r4, r6
	ldr r1, [r4]
	ldr r0, _0802C868
	subs r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r1, r0, #8
	adds r0, r0, r1
	lsls r1, r0, #0x10
	adds r0, r0, r1
	rsbs r0, r0, #0
	asrs r0, r0, #2
	strh r0, [r2, #0x3c]
	ldr r1, [r5]
	adds r1, #0x3e
	ldrb r2, [r1]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldr r1, [r5]
	movs r0, #0x60
	strh r0, [r1, #0x22]
	ldr r0, [r5]
	ldr r1, _0802C86C
	str r1, [r0, #0x1c]
	movs r1, #1
	bl StartSpriteAnim
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802C860: .4byte 0x000081BC
_0802C864: .4byte 0x000081A8
_0802C868: .4byte 0x020205AC
_0802C86C: .4byte 0x0802C871
	thumb_func_end sub_0802C808

	thumb_func_start sub_0802C870
sub_0802C870: @ 0x0802C870
	push {lr}
	adds r2, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r2, r1]
	cmp r0, #1
	beq _0802C89C
	cmp r0, #1
	bgt _0802C886
	cmp r0, #0
	beq _0802C88C
	b _0802C8DA
_0802C886:
	cmp r0, #2
	beq _0802C8BC
	b _0802C8DA
_0802C88C:
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0802C8DA
	b _0802C8CA
_0802C89C:
	ldrh r1, [r2, #0x22]
	subs r1, #1
	strh r1, [r2, #0x22]
	ldrh r0, [r2, #0x30]
	adds r0, #1
	strh r0, [r2, #0x30]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x48
	bgt _0802C8DA
	movs r0, #0x48
	strh r0, [r2, #0x22]
	ldrh r0, [r2, #0x2e]
	adds r0, #1
	strh r0, [r2, #0x2e]
	b _0802C8DA
_0802C8BC:
	ldrh r0, [r2, #0x30]
	adds r0, #1
	strh r0, [r2, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x2f
	ble _0802C8DA
_0802C8CA:
	adds r3, r2, #0
	adds r3, #0x3e
	ldrb r0, [r3]
	movs r1, #4
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _0802C8E0
	str r0, [r2, #0x1c]
_0802C8DA:
	pop {r0}
	bx r0
	.align 2, 0
_0802C8E0: .4byte 0x08007141
	thumb_func_end sub_0802C870

	thumb_func_start sub_0802C8E4
sub_0802C8E4: @ 0x0802C8E4
	push {lr}
	lsls r1, r1, #2
	ldr r2, _0802C904
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r1, _0802C908
	str r1, [r2, #0x1c]
	movs r1, #0
	strh r1, [r2, #0x26]
	ldr r0, [r0]
	bl sub_0802C6B0
	pop {r0}
	bx r0
	.align 2, 0
_0802C904: .4byte 0x000081A8
_0802C908: .4byte 0x0802C935
	thumb_func_end sub_0802C8E4

	thumb_func_start sub_0802C90C
sub_0802C90C: @ 0x0802C90C
	push {lr}
	movs r2, #0
	lsls r1, r1, #2
	ldr r3, _0802C92C
	adds r0, r0, r3
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	ldr r0, _0802C930
	cmp r1, r0
	bne _0802C924
	movs r2, #1
_0802C924:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_0802C92C: .4byte 0x000081A8
_0802C930: .4byte 0x0802C935
	thumb_func_end sub_0802C90C

	thumb_func_start sub_0802C934
sub_0802C934: @ 0x0802C934
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x30]
	adds r0, #1
	strh r0, [r2, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0802C960
	ldrh r0, [r2, #0x32]
	adds r0, #1
	strh r0, [r2, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0802C958
	movs r0, #2
	b _0802C95A
_0802C958:
	ldr r0, _0802C974
_0802C95A:
	strh r0, [r2, #0x26]
	movs r0, #0
	strh r0, [r2, #0x30]
_0802C960:
	movs r1, #0x32
	ldrsh r0, [r2, r1]
	cmp r0, #0xc
	ble _0802C970
	movs r0, #0
	strh r0, [r2, #0x26]
	ldr r0, _0802C978
	str r0, [r2, #0x1c]
_0802C970:
	pop {r0}
	bx r0
	.align 2, 0
_0802C974: .4byte 0x0000FFFE
_0802C978: .4byte 0x08007141
	thumb_func_end sub_0802C934

	thumb_func_start sub_0802C97C
sub_0802C97C: @ 0x0802C97C
	push {r4, lr}
	adds r4, r0, #0
	lsls r1, r1, #2
	ldr r0, _0802C99C
	adds r4, r4, r0
	adds r4, r4, r1
	ldr r0, [r4]
	bl sub_0802C6B0
	ldr r1, [r4]
	ldr r0, _0802C9A0
	str r0, [r1, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802C99C: .4byte 0x000081A8
_0802C9A0: .4byte 0x0802C9FD
	thumb_func_end sub_0802C97C

	thumb_func_start sub_0802C9A4
sub_0802C9A4: @ 0x0802C9A4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _0802C9E8
	movs r1, #5
	rsbs r1, r1, #0
	mov ip, r1
	ldr r1, _0802C9F0
	adds r3, r4, r1
	ldr r7, _0802C9F4
	ldr r6, _0802C9F8
	movs r5, #0xa
	adds r4, r0, #0
_0802C9C6:
	ldr r2, [r3]
	ldr r0, [r2, #0x1c]
	cmp r0, r7
	bne _0802C9E0
	adds r2, #0x3e
	ldrb r1, [r2]
	mov r0, ip
	ands r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	str r6, [r0, #0x1c]
	adds r0, #0x43
	strb r5, [r0]
_0802C9E0:
	adds r3, #4
	subs r4, #1
	cmp r4, #0
	bne _0802C9C6
_0802C9E8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802C9F0: .4byte 0x000081A8
_0802C9F4: .4byte 0x0802C9FD
_0802C9F8: .4byte 0x08007141
	thumb_func_end sub_0802C9A4

	thumb_func_start sub_0802C9FC
sub_0802C9FC: @ 0x0802C9FC
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2e]
	adds r0, #1
	strh r0, [r3, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0802CA2A
	movs r0, #0
	strh r0, [r3, #0x2e]
	adds r3, #0x3e
	ldrb r2, [r3]
	lsls r0, r2, #0x1d
	lsrs r0, r0, #0x1f
	movs r1, #1
	eors r1, r0
	lsls r1, r1, #2
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0802CA2A:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802C9FC

	thumb_func_start sub_0802CA30
sub_0802CA30: @ 0x0802CA30
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r2, #0
	cmp r2, r3
	bge _0802CA5A
	ldr r0, _0802CA60
	adds r5, r4, r0
	subs r0, #0x54
	adds r4, r4, r0
_0802CA4A:
	ldm r4!, {r0}
	adds r1, r5, r2
	ldrb r1, [r1]
	adds r0, #0x43
	strb r1, [r0]
	adds r2, #1
	cmp r2, r3
	blt _0802CA4A
_0802CA5A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CA60: .4byte 0x000081FC
	thumb_func_end sub_0802CA30

	thumb_func_start sub_0802CA64
sub_0802CA64: @ 0x0802CA64
	push {r4, lr}
	adds r4, r0, #0
	lsls r1, r1, #2
	ldr r0, _0802CA84
	adds r4, r4, r0
	adds r4, r4, r1
	ldr r0, [r4]
	bl sub_0802C6B0
	ldr r1, [r4]
	ldr r0, _0802CA88
	str r0, [r1, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802CA84: .4byte 0x000081A8
_0802CA88: .4byte 0x0802CAC9
	thumb_func_end sub_0802CA64

	thumb_func_start sub_0802CA8C
sub_0802CA8C: @ 0x0802CA8C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r2, #0
	cmp r2, r3
	bge _0802CAC0
	ldr r5, _0802CAB0
	ldr r0, _0802CAB4
	adds r1, r4, r0
_0802CAA4:
	ldr r0, [r1]
	ldr r0, [r0, #0x1c]
	cmp r0, r5
	bne _0802CAB8
	movs r0, #1
	b _0802CAC2
	.align 2, 0
_0802CAB0: .4byte 0x0802CAC9
_0802CAB4: .4byte 0x000081A8
_0802CAB8:
	adds r1, #4
	adds r2, #1
	cmp r2, r3
	blt _0802CAA4
_0802CAC0:
	movs r0, #0
_0802CAC2:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_0802CA8C

	thumb_func_start sub_0802CAC8
sub_0802CAC8: @ 0x0802CAC8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x2e
	ldrsh r4, [r5, r0]
	cmp r4, #0
	beq _0802CADA
	cmp r4, #1
	beq _0802CAE8
	b _0802CB30
_0802CADA:
	movs r0, #0x22
	bl PlaySE
	strh r4, [r5, #0x30]
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
_0802CAE8:
	ldrh r0, [r5, #0x30]
	adds r0, #4
	strh r0, [r5, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7f
	ble _0802CAFA
	movs r0, #0
	strh r0, [r5, #0x30]
_0802CAFA:
	ldr r1, _0802CB28
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	rsbs r0, r0, #0
	strh r0, [r5, #0x26]
	movs r0, #0x30
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bne _0802CB30
	ldrh r0, [r5, #0x32]
	adds r0, #1
	strh r0, [r5, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _0802CB2C
	strh r1, [r5, #0x2e]
	b _0802CB30
	.align 2, 0
_0802CB28: .4byte 0x082FA8CC
_0802CB2C:
	ldr r0, _0802CB38
	str r0, [r5, #0x1c]
_0802CB30:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CB38: .4byte 0x08007141
	thumb_func_end sub_0802CAC8

	thumb_func_start sub_0802CB3C
sub_0802CB3C: @ 0x0802CB3C
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r3, r3, #0x18
	lsrs r4, r3, #0x18
	ldr r0, _0802CB84
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	movs r3, #1
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	beq _0802CB7C
	ldr r0, _0802CB88
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	adds r3, r1, #0
	adds r3, #0x3e
	ldrb r0, [r3]
	movs r2, #4
	orrs r0, r2
	strb r0, [r3]
	lsls r2, r4, #2
	ldr r3, _0802CB8C
	adds r0, r5, r3
	adds r0, r0, r2
	str r1, [r0]
_0802CB7C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802CB84: .4byte 0x082CF898
_0802CB88: .4byte 0x020205AC
_0802CB8C: .4byte 0x000081BC
	thumb_func_end sub_0802CB3C

	thumb_func_start sub_0802CB90
sub_0802CB90: @ 0x0802CB90
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r5, #0
	movs r4, #0
	ldr r6, _0802CC30
_0802CB9A:
	ldr r1, _0802CC34
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _0802CC38
	lsls r1, r5, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r3, #0
	ldrsh r2, [r6, r3]
	movs r3, #2
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	lsls r0, r5, #2
	ldr r3, _0802CC3C
	adds r2, r7, r3
	adds r2, r2, r0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0802CC40
	adds r0, r0, r1
	str r0, [r2]
	adds r5, #1
	adds r6, #0x14
	adds r4, #1
	cmp r4, #3
	ble _0802CB9A
	movs r4, #3
	movs r6, #0x3c
_0802CBDC:
	ldr r1, _0802CC34
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r2, _0802CC38
	lsls r1, r5, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	ldr r2, _0802CC30
	adds r2, r6, r2
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r3, #2
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	lsls r0, r5, #2
	ldr r3, _0802CC3C
	adds r2, r7, r3
	adds r2, r2, r0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0802CC40
	adds r0, r0, r1
	str r0, [r2]
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	strb r1, [r0]
	adds r5, #1
	subs r6, #0x14
	subs r4, #1
	cmp r4, #0
	bge _0802CBDC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CC30: .4byte 0x082CF6E4
_0802CC34: .4byte 0x082CF744
_0802CC38: .4byte 0x082CF734
_0802CC3C: .4byte 0x000081D0
_0802CC40: .4byte 0x020205AC
	thumb_func_end sub_0802CB90

	thumb_func_start sub_0802CC44
sub_0802CC44: @ 0x0802CC44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	cmp r1, #5
	ble _0802CC64
	movs r0, #0xa
	subs r1, r0, r1
	movs r0, #3
	str r0, [sp]
	ldr r2, [sp, #8]
	ldrb r0, [r2, #0xf]
	b _0802CC6C
_0802CC64:
	movs r3, #2
	str r3, [sp]
	ldr r7, [sp, #8]
	ldrb r0, [r7, #0xe]
_0802CC6C:
	movs r6, #0
	lsls r2, r1, #1
	str r2, [sp, #4]
	lsls r0, r0, #4
	mov sb, r0
	lsls r1, r1, #0x18
	mov r8, r1
	ldr r0, _0802CD30
	adds r4, r2, r0
	ldr r3, [sp]
	lsls r3, r3, #2
	mov sl, r3
	movs r5, #3
_0802CC86:
	lsls r0, r6, #2
	ldr r7, [sp, #8]
	ldr r1, _0802CD34
	adds r2, r7, r1
	adds r2, r2, r0
	ldr r1, [r2]
	ldrh r0, [r4]
	strh r0, [r1, #0x22]
	ldr r3, [r2]
	ldrb r0, [r3, #5]
	movs r7, #0xd
	rsbs r7, r7, #0
	adds r1, r7, #0
	ands r0, r1
	mov r1, sl
	orrs r0, r1
	strb r0, [r3, #5]
	ldr r3, [r2]
	ldrb r1, [r3, #5]
	movs r0, #0xf
	ands r0, r1
	mov r7, sb
	orrs r0, r7
	strb r0, [r3, #5]
	ldr r0, [r2]
	mov r2, r8
	lsrs r1, r2, #0x18
	bl StartSpriteAnim
	adds r6, #1
	adds r4, #0x14
	subs r5, #1
	cmp r5, #0
	bge _0802CC86
	movs r5, #3
	ldr r0, _0802CD30
	ldr r3, [sp, #4]
	adds r0, r3, r0
	adds r4, r0, #0
	adds r4, #0x3c
	ldr r7, [sp]
	lsls r7, r7, #2
	mov sl, r7
_0802CCDC:
	lsls r0, r6, #2
	ldr r1, [sp, #8]
	ldr r3, _0802CD34
	adds r2, r1, r3
	adds r2, r2, r0
	ldr r1, [r2]
	ldrh r0, [r4]
	strh r0, [r1, #0x22]
	ldr r3, [r2]
	ldrb r0, [r3, #5]
	movs r7, #0xd
	rsbs r7, r7, #0
	adds r1, r7, #0
	ands r0, r1
	mov r1, sl
	orrs r0, r1
	strb r0, [r3, #5]
	ldr r3, [r2]
	ldrb r1, [r3, #5]
	movs r0, #0xf
	ands r0, r1
	mov r7, sb
	orrs r0, r7
	strb r0, [r3, #5]
	ldr r0, [r2]
	mov r2, r8
	lsrs r1, r2, #0x18
	bl StartSpriteAnim
	adds r6, #1
	subs r4, #0x14
	subs r5, #1
	cmp r5, #0
	bge _0802CCDC
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802CD30: .4byte 0x082CF6E4
_0802CD34: .4byte 0x000081D0
	thumb_func_end sub_0802CC44

	thumb_func_start sub_0802CD38
sub_0802CD38: @ 0x0802CD38
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0
	str r0, [sp]
	movs r0, #9
	movs r1, #7
	movs r2, #0x78
	movs r3, #0x50
	bl sub_0802E788
	adds r0, r4, #0
	bl sub_0802CA30
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0802CD38

	thumb_func_start sub_0802CD5C
sub_0802CD5C: @ 0x0802CD5C
	push {lr}
	bl sub_0802E7E8
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802CD5C

	thumb_func_start sub_0802CD68
sub_0802CD68: @ 0x0802CD68
	push {r4, lr}
	ldr r4, _0802CD94
	str r0, [r4]
	bl sub_0802CDB0
	ldr r0, _0802CD98
	movs r1, #3
	bl CreateTask
	ldr r1, [r4]
	strb r0, [r1, #6]
	ldr r2, [r4]
	ldrb r0, [r2, #6]
	movs r1, #2
	bl SetWordTaskArg
	ldr r0, _0802CD9C
	bl sub_0802CDFC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802CD94: .4byte 0x020229B4
_0802CD98: .4byte 0x0802CE21
_0802CD9C: .4byte 0x0802CE45
	thumb_func_end sub_0802CD68
