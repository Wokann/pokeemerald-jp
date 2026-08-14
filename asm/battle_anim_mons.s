.include "asm/macros.inc"
.include "constants/constants.inc"
	.section .text.battle_anim_mons_arc,"ax",%progbits
.syntax unified

	thumb_func_start TranslateAnimHorizontalArc
TranslateAnimHorizontalArc: @ 0x080A61C8
	push {r4, lr}
	adds r4, r0, #0
	bl AnimTranslateLinear
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A61F4
	ldrh r0, [r4, #0x3a]
	ldrh r1, [r4, #0x3c]
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, #0x26]
	adds r0, r0, r1
	strh r0, [r4, #0x26]
	movs r0, #0
	b _080A61F6
_080A61F4:
	movs r0, #1
_080A61F6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end TranslateAnimHorizontalArc

	thumb_func_start TranslateAnimVerticalArc
TranslateAnimVerticalArc: @ 0x080A61FC
	push {r4, lr}
	adds r4, r0, #0
	bl AnimTranslateLinear
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6228
	ldrh r0, [r4, #0x3a]
	ldrh r1, [r4, #0x3c]
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	movs r0, #0
	b _080A622A
_080A6228:
	movs r0, #1
_080A622A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end TranslateAnimVerticalArc

	.section .text.battle_anim_mons_cisc,"ax",%progbits
.syntax unified

	thumb_func_start CreateInvisibleSpriteCopy
CreateInvisibleSpriteCopy: @ 0x080A8290
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	lsls r6, r1, #0x18
	lsrs r6, r6, #0x18
	ldr r0, _080A8328
	mov sl, r0
	bl CreateInvisibleSpriteWithCallback
	mov r8, r0
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _080A832C
	mov sb, r0
	mov r0, r8
	lsls r3, r0, #4
	add r3, r8
	lsls r3, r3, #2
	mov r0, sb
	adds r5, r3, r0
	lsls r4, r6, #4
	adds r4, r4, r6
	lsls r4, r4, #2
	add r4, sb
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x44
	str r3, [sp]
	bl memcpy
	adds r2, r5, #0
	adds r2, #0x3f
	ldrb r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldrb r2, [r5, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r5, #5]
	ldrb r0, [r5, #1]
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	strb r1, [r5, #1]
	ldrh r1, [r4, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r5, #4]
	ldr r0, _080A8330
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #4]
	movs r0, #0x1c
	add sb, r0
	ldr r3, [sp]
	add r3, sb
	mov r0, sl
	str r0, [r3]
	mov r0, r8
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A8328: .4byte 0x08007141
_080A832C: .4byte 0x020205AC
_080A8330: .4byte 0xFFFFFC00
	thumb_func_end CreateInvisibleSpriteCopy
