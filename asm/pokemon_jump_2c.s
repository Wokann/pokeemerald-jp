.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_0802E788
sub_0802E788: @ 0x0802E788
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, [sp, #0x18]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _0802E7E0
	movs r1, #0x50
	str r3, [sp]
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0802E7E4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	strh r4, [r1, #0xc]
	strh r5, [r1, #0xe]
	strh r6, [r1, #0x10]
	ldr r3, [sp]
	strh r3, [r1, #0x12]
	mov r0, r8
	strh r0, [r1, #0x14]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E7E0: .4byte 0x0802E7FD
_0802E7E4: .4byte 0x03005B60
	thumb_func_end sub_0802E788

	thumb_func_start sub_0802E7E8
sub_0802E7E8: @ 0x0802E7E8
	push {lr}
	ldr r0, _0802E7F8
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0802E7F8: .4byte 0x0802E7FD
	thumb_func_end sub_0802E7E8

	thumb_func_start sub_0802E7FC
sub_0802E7FC: @ 0x0802E7FC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r1, _0802E820
	adds r5, r0, r1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _0802E86C
	cmp r0, #1
	bgt _0802E824
	cmp r0, #0
	beq _0802E82A
	b _0802E8EE
	.align 2, 0
_0802E820: .4byte 0x03005B68
_0802E824:
	cmp r0, #2
	beq _0802E8B0
	b _0802E8EE
_0802E82A:
	ldrh r0, [r5, #4]
	ldrh r1, [r5, #6]
	bl sub_0802EBB4
	ldrh r0, [r5, #4]
	ldrh r1, [r5, #6]
	movs r3, #8
	ldrsh r2, [r5, r3]
	movs r4, #0xa
	ldrsh r3, [r5, r4]
	ldrb r4, [r5, #0xc]
	str r4, [sp]
	bl sub_0802EC0C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0xe]
	ldrh r0, [r5, #4]
	ldrh r1, [r5, #6]
	movs r3, #8
	ldrsh r2, [r5, r3]
	movs r4, #0xa
	ldrsh r3, [r5, r4]
	ldrb r4, [r5, #0xc]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0x10
	str r4, [sp, #4]
	adds r4, #2
	str r4, [sp, #8]
	bl sub_0802EC60
	b _0802E8A2
_0802E86C:
	ldrb r0, [r5, #0xe]
	bl sub_0802E8FC
	cmp r0, #0
	bne _0802E8EE
	ldrb r0, [r5, #0xe]
	ldrb r1, [r5, #0x10]
	ldrb r2, [r5, #0x12]
	bl sub_0802EA30
	movs r0, #0xe
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0802E8AC
	adds r0, r0, r4
	bl FreeSpriteOamMatrix
	movs r3, #0xe
	ldrsh r1, [r5, r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
_0802E8A2:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b _0802E8EE
	.align 2, 0
_0802E8AC: .4byte 0x020205AC
_0802E8B0:
	ldrb r0, [r5, #0x10]
	bl sub_0802EA94
	cmp r0, #0
	bne _0802E8EE
	movs r4, #0x10
	ldrsh r1, [r5, r4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0802E8F8
	adds r0, r0, r4
	bl DestroySprite
	movs r0, #0x12
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	ldrh r0, [r5, #4]
	bl FreeSpriteTilesByTag
	ldrh r0, [r5, #6]
	bl FreeSpritePaletteByTag
	adds r0, r6, #0
	bl DestroyTask
_0802E8EE:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E8F8: .4byte 0x020205AC
	thumb_func_end sub_0802E7FC

	thumb_func_start sub_0802E8FC
sub_0802E8FC: @ 0x0802E8FC
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0802E920
	adds r4, r1, r0
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #7
	bls _0802E916
	b _0802EA28
_0802E916:
	lsls r0, r0, #2
	ldr r1, _0802E924
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E920: .4byte 0x020205AC
_0802E924: .4byte 0x0802E928
_0802E928: @ jump table
	.4byte _0802E948 @ case 0
	.4byte _0802E95A @ case 1
	.4byte _0802E980 @ case 2
	.4byte _0802E990 @ case 3
	.4byte _0802E9B2 @ case 4
	.4byte _0802E9EA @ case 5
	.4byte _0802EA10 @ case 6
	.4byte _0802E9E6 @ case 7
_0802E948:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r4, #0
	movs r2, #0x1a
	bl SetSpriteMatrixAnchor
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
_0802E95A:
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _0802E968
	movs r0, #0x39
	bl PlaySE
_0802E968:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	ble _0802EA28
	movs r0, #0
	strh r0, [r4, #0x32]
	adds r0, r4, #0
	movs r1, #1
	b _0802EA06
_0802E980:
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802EA28
	b _0802EA0A
_0802E990:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0802EA28
	movs r0, #0
	strh r0, [r4, #0x32]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	movs r1, #2
	bl StartSpriteAffineAnim
	b _0802EA28
_0802E9B2:
	ldrh r0, [r4, #0x22]
	subs r0, #4
	strh r0, [r4, #0x22]
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0802EA28
	ldrh r1, [r4, #0x36]
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	cmp r0, #1
	bgt _0802E9E2
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
	movs r0, #0
	strh r0, [r4, #0x32]
	b _0802EA0A
_0802E9E2:
	movs r0, #7
	strh r0, [r4, #0x2e]
_0802E9E6:
	movs r0, #0
	b _0802EA2A
_0802E9EA:
	ldrh r0, [r4, #0x22]
	adds r0, #4
	strh r0, [r4, #0x22]
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0802EA28
	movs r0, #0
	strh r0, [r4, #0x32]
	adds r0, r4, #0
	movs r1, #3
_0802EA06:
	bl StartSpriteAffineAnim
_0802EA0A:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	b _0802EA26
_0802EA10:
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802EA28
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	movs r0, #1
_0802EA26:
	strh r0, [r4, #0x2e]
_0802EA28:
	movs r0, #1
_0802EA2A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802E8FC

	thumb_func_start sub_0802EA30
sub_0802EA30: @ 0x0802EA30
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r0, _0802EA88
	mov r8, r0
	lsls r4, r1, #4
	adds r4, r4, r1
	lsls r4, r4, #2
	adds r5, r4, r0
	ldr r0, _0802EA8C
	strh r0, [r5, #0x26]
	lsls r3, r2, #4
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r1, r8
	adds r2, r3, r1
	strh r0, [r2, #0x26]
	adds r5, #0x3e
	ldrb r6, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r6
	strb r0, [r5]
	adds r2, #0x3e
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	movs r0, #0x1c
	add r8, r0
	add r4, r8
	ldr r0, _0802EA90
	str r0, [r4]
	add r3, r8
	str r0, [r3]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802EA88: .4byte 0x020205AC
_0802EA8C: .4byte 0x0000FFD8
_0802EA90: .4byte 0x0802EAC1
	thumb_func_end sub_0802EA30

	thumb_func_start sub_0802EA94
sub_0802EA94: @ 0x0802EA94
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r3, #0
	ldr r2, _0802EAB8
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r2, #0x1c
	adds r1, r1, r2
	ldr r1, [r1]
	ldr r0, _0802EABC
	cmp r1, r0
	bne _0802EAB2
	movs r3, #1
_0802EAB2:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0
_0802EAB8: .4byte 0x020205AC
_0802EABC: .4byte 0x0802EAC1
	thumb_func_end sub_0802EA94

	thumb_func_start sub_0802EAC0
sub_0802EAC0: @ 0x0802EAC0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x2e
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	cmp r0, #4
	bhi _0802EBAA
	lsls r0, r0, #2
	ldr r1, _0802EADC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802EADC: .4byte 0x0802EAE0
_0802EAE0: @ jump table
	.4byte _0802EAF4 @ case 0
	.4byte _0802EB04 @ case 1
	.4byte _0802EB2C @ case 2
	.4byte _0802EB60 @ case 3
	.4byte _0802EB98 @ case 4
_0802EAF4:
	movs r0, #0x40
	strh r0, [r4, #8]
	ldrh r0, [r5, #0x26]
	lsls r0, r0, #4
	strh r0, [r4, #0xa]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0802EB04:
	ldrh r1, [r4, #8]
	ldrh r2, [r4, #0xa]
	adds r0, r1, r2
	strh r0, [r4, #0xa]
	adds r1, #1
	strh r1, [r4, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r5, #0x26]
	cmp r0, #0
	blt _0802EBAA
	movs r0, #0x39
	bl PlaySE
	movs r0, #0
	strh r0, [r5, #0x26]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0802EBAA
_0802EB2C:
	ldrh r0, [r4, #2]
	adds r0, #0xc
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7f
	ble _0802EB4A
	movs r0, #0x39
	bl PlaySE
	movs r0, #0
	strh r0, [r4, #2]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0802EB4A:
	ldr r0, _0802EB5C
	movs r2, #2
	ldrsh r1, [r4, r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	asrs r0, r0, #4
	b _0802EB8E
	.align 2, 0
_0802EB5C: .4byte 0x082FA8CC
_0802EB60:
	ldrh r0, [r4, #2]
	adds r0, #0x10
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7f
	ble _0802EB7E
	movs r0, #0x39
	bl PlaySE
	movs r0, #0
	strh r0, [r4, #2]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0802EB7E:
	ldr r1, _0802EB94
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x15
_0802EB8E:
	rsbs r0, r0, #0
	strh r0, [r5, #0x26]
	b _0802EBAA
	.align 2, 0
_0802EB94: .4byte 0x082FA8CC
_0802EB98:
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	ble _0802EBAA
	ldr r0, _0802EBB0
	str r0, [r5, #0x1c]
_0802EBAA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802EBB0: .4byte 0x08007141
	thumb_func_end sub_0802EAC0

	thumb_func_start sub_0802EBB4
sub_0802EBB4: @ 0x0802EBB4
	push {r4, lr}
	sub sp, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0802EBFC
	ldr r3, [r2, #4]
	ldr r2, [r2]
	str r2, [sp]
	str r3, [sp, #4]
	ldr r2, _0802EC00
	ldr r3, [r2, #4]
	ldr r2, [r2]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	lsls r0, r0, #0x10
	ldr r3, _0802EC04
	ldr r2, [sp, #4]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #4]
	ldr r2, _0802EC08
	add r4, sp, #8
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r4, #4]
	mov r0, sp
	bl LoadCompressedSpriteSheet
	adds r0, r4, #0
	bl LoadSpritePalette
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802EBFC: .4byte 0x082D2458
_0802EC00: .4byte 0x082D2460
_0802EC04: .4byte 0x0000FFFF
_0802EC08: .4byte 0xFFFF0000
	thumb_func_end sub_0802EBB4

	thumb_func_start sub_0802EC0C
sub_0802EC0C: @ 0x0802EC0C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	mov ip, r3
	ldr r3, [sp, #0x30]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r8, r3
	mov r5, sp
	ldr r4, _0802EC5C
	ldm r4!, {r3, r6, r7}
	stm r5!, {r3, r6, r7}
	ldm r4!, {r3, r6, r7}
	stm r5!, {r3, r6, r7}
	mov r4, sp
	strh r0, [r4]
	mov r0, sp
	strh r1, [r0, #2]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	mov r0, ip
	lsls r6, r0, #0x10
	asrs r6, r6, #0x10
	mov r0, sp
	adds r1, r2, #0
	adds r2, r6, #0
	mov r3, r8
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802EC5C: .4byte 0x082D251C
	thumb_func_end sub_0802EC0C

	thumb_func_start sub_0802EC60
sub_0802EC60: @ 0x0802EC60
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov ip, r3
	ldr r6, [sp, #0x38]
	ldr r3, [sp, #0x3c]
	mov sb, r3
	ldr r4, [sp, #0x40]
	mov r8, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov sl, r6
	mov r4, sp
	ldr r3, _0802ED24
	ldm r3!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	ldm r3!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	mov r3, sp
	strh r0, [r3]
	mov r0, sp
	strh r1, [r0, #2]
	lsls r2, r2, #0x10
	asrs r4, r2, #0x10
	ldr r0, _0802ED28
	adds r2, r2, r0
	asrs r2, r2, #0x10
	mov r1, ip
	lsls r5, r1, #0x10
	asrs r5, r5, #0x10
	mov r0, sp
	adds r1, r2, #0
	adds r2, r5, #0
	mov r3, sl
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r3, sb
	strh r0, [r3]
	adds r4, #0x20
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	mov r3, sl
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r4, r8
	strh r0, [r4]
	ldr r2, _0802ED2C
	mov r5, sb
	movs r6, #0
	ldrsh r1, [r5, r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r3, #4
	orrs r1, r3
	strb r1, [r0]
	movs r7, #0
	ldrsh r1, [r4, r7]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #1
	bl StartSpriteAnim
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802ED24: .4byte 0x082D2534
_0802ED28: .4byte 0xFFE00000
_0802ED2C: .4byte 0x020205AC
	thumb_func_end sub_0802EC60
