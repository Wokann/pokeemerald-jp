.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

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
