.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

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
