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

	.section .text,"ax",%progbits
	thumb_func_start sub_080A8290
sub_080A8290: @ 0x080A8290
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
	thumb_func_end sub_080A8290

	thumb_func_start sub_080A8334
sub_080A8334: @ 0x080A8334
	push {r4, lr}
	adds r4, r0, #0
	bl SetSpriteCoordsToAnimAttackerCoords
	ldr r0, _080A836C
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A8374
	ldr r2, _080A8370
	ldrh r0, [r4, #0x20]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r2, #6]
	rsbs r0, r0, #0
	strh r0, [r2, #6]
	adds r3, r4, #0
	adds r3, #0x3f
	ldrb r0, [r3]
	movs r1, #1
	orrs r0, r1
	strb r0, [r3]
	adds r1, r2, #0
	b _080A837E
	.align 2, 0
_080A836C: .4byte 0x020380D6
_080A8370: .4byte 0x020380BE
_080A8374:
	ldr r1, _080A83A8
	ldrh r0, [r1]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
_080A837E:
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #0x22]
	adds r0, r0, r2
	strh r0, [r4, #0x22]
	ldrh r0, [r1, #4]
	strh r0, [r4, #0x2e]
	ldrh r0, [r1, #6]
	strh r0, [r4, #0x30]
	ldrh r0, [r1, #8]
	strh r0, [r4, #0x34]
	ldrh r0, [r1, #0xa]
	strh r0, [r4, #0x38]
	ldr r1, _080A83AC
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _080A83B0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A83A8: .4byte 0x020380BE
_080A83AC: .4byte 0x080A6015
_080A83B0: .4byte 0x080A5FA5
	thumb_func_end sub_080A8334

	thumb_func_start sub_080A83B4
sub_080A83B4: @ 0x080A83B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A83DC
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A83E4
	ldr r2, _080A83E0
	ldrh r0, [r4, #0x20]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4, #0x20]
	movs r1, #6
	ldrsh r0, [r2, r1]
	rsbs r0, r0, #0
	strh r0, [r2, #6]
	adds r1, r2, #0
	b _080A83EE
	.align 2, 0
_080A83DC: .4byte 0x020380D6
_080A83E0: .4byte 0x020380BE
_080A83E4:
	ldr r1, _080A8420
	ldrh r0, [r1]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
_080A83EE:
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #0x22]
	adds r0, r0, r2
	strh r0, [r4, #0x22]
	ldrh r0, [r1, #4]
	strh r0, [r4, #0x2e]
	ldrh r0, [r1, #6]
	strh r0, [r4, #0x30]
	ldrh r0, [r1, #8]
	strh r0, [r4, #0x34]
	ldrh r0, [r1, #0xa]
	strh r0, [r4, #0x38]
	ldrb r1, [r1, #0xc]
	adds r0, r4, #0
	bl StartSpriteAnim
	ldr r1, _080A8424
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _080A8428
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A8420: .4byte 0x020380BE
_080A8424: .4byte 0x080A6015
_080A8428: .4byte 0x080A5FA5
	thumb_func_end sub_080A83B4

	thumb_func_start sub_080A842C
sub_080A842C: @ 0x080A842C
	push {r4, lr}
	adds r4, r0, #0
	bl SetSpriteCoordsToAnimAttackerCoords
	ldr r0, _080A8450
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A8458
	ldr r0, _080A8454
	ldrh r1, [r4, #0x20]
	ldrh r2, [r0]
	subs r1, r1, r2
	strh r1, [r4, #0x20]
	b _080A8464
	.align 2, 0
_080A8450: .4byte 0x020380D6
_080A8454: .4byte 0x020380BE
_080A8458:
	ldr r1, _080A8480
	ldrh r0, [r1]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
	adds r0, r1, #0
_080A8464:
	ldrh r0, [r0, #2]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x22]
	ldr r0, _080A8484
	str r0, [r4, #0x1c]
	ldr r1, _080A8488
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A8480: .4byte 0x020380BE
_080A8484: .4byte 0x080A60A1
_080A8488: .4byte 0x080A34C5
	thumb_func_end sub_080A842C

	thumb_func_start sub_080A848C
sub_080A848C: @ 0x080A848C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080A8520
	adds r5, r1, r0
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r6, #0
	strh r0, [r5, #8]
	ldr r7, _080A8524
	ldrb r0, [r7]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	movs r1, #8
	cmp r0, #0
	beq _080A84C0
	movs r0, #8
	rsbs r0, r0, #0
	adds r1, r0, #0
_080A84C0:
	strh r1, [r5, #0xa]
	strh r6, [r5, #0xc]
	strh r6, [r5, #0xe]
	ldr r4, _080A8528
	movs r0, #8
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r1, [r0, #0x24]
	ldrh r2, [r5, #8]
	subs r1, r1, r2
	strh r1, [r0, #0x24]
	ldr r0, _080A852C
	bl AllocSpritePalette
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x10]
	strh r6, [r5, #0x12]
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	adds r0, #0x10
	lsls r0, r0, #0x14
	lsrs r6, r0, #0x10
	movs r0, #8
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r0, [r0, #5]
	lsrs r0, r0, #4
	adds r0, #0x10
	lsls r4, r0, #4
	ldrb r0, [r7]
	bl GetBattlerSpriteSubpriority
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x14]
	cmp r0, #0x14
	beq _080A851C
	cmp r0, #0x28
	bne _080A8530
_080A851C:
	movs r0, #2
	b _080A8532
	.align 2, 0
_080A8520: .4byte 0x03005B60
_080A8524: .4byte 0x020380D6
_080A8528: .4byte 0x020205AC
_080A852C: .4byte 0x00002771
_080A8530:
	movs r0, #3
_080A8532:
	strh r0, [r5, #0x14]
	lsls r0, r4, #1
	ldr r1, _080A8560
	adds r0, r0, r1
	lsls r1, r6, #1
	ldr r2, _080A8564
	adds r1, r1, r2
	ldr r2, _080A8568
	bl CpuSet
	ldr r0, _080A856C
	ldrb r2, [r0, #2]
	ldrh r3, [r0]
	adds r0, r6, #0
	movs r1, #0x10
	bl BlendPalette
	ldr r0, _080A8570
	str r0, [r5]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8560: .4byte 0x020373B4
_080A8564: .4byte 0x020377B4
_080A8568: .4byte 0x04000008
_080A856C: .4byte 0x020380BE
_080A8570: .4byte 0x080A8575
	thumb_func_end sub_080A848C

	thumb_func_start sub_080A8574
sub_080A8574: @ 0x080A8574
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _080A8598
	adds r4, r0, r1
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq _080A85D8
	cmp r0, #1
	bgt _080A859C
	cmp r0, #0
	beq _080A85A2
	b _080A8634
	.align 2, 0
_080A8598: .4byte 0x03005B60
_080A859C:
	cmp r0, #2
	beq _080A8620
	b _080A8634
_080A85A2:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080A8640
	ldr r2, _080A85D4
	movs r0, #8
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r4, #0xa]
	ldrh r2, [r0, #0x24]
	adds r1, r1, r2
	strh r1, [r0, #0x24]
	ldrh r1, [r4, #0xe]
	adds r0, r1, #1
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bne _080A8634
	strh r1, [r4, #0xe]
	b _080A8612
	.align 2, 0
_080A85D4: .4byte 0x020205AC
_080A85D8:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080A8640
	ldr r3, _080A861C
	movs r0, #8
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r1, [r0, #0x24]
	ldrh r2, [r4, #0xa]
	subs r1, r1, r2
	strh r1, [r0, #0x24]
	ldrh r0, [r4, #0xe]
	subs r0, #1
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	bne _080A8634
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r3
	strh r2, [r1, #0x24]
_080A8612:
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	b _080A8634
	.align 2, 0
_080A861C: .4byte 0x020205AC
_080A8620:
	movs r2, #0x12
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _080A8634
	ldr r0, _080A863C
	bl FreeSpritePaletteByTag
	adds r0, r5, #0
	bl DestroyAnimVisualTask
_080A8634:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A863C: .4byte 0x00002771
	thumb_func_end sub_080A8574

	thumb_func_start sub_080A8640
sub_080A8640: @ 0x080A8640
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	movs r0, #0
	bl CloneBattlerSpriteWithBlend
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080A86B0
	ldr r5, _080A86BC
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	adds r3, r4, r5
	movs r0, #3
	ldrb r1, [r6, #0x14]
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrb r1, [r6, #0x10]
	lsls r1, r1, #4
	movs r2, #0xf
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	movs r0, #8
	strh r0, [r3, #0x2e]
	mov r0, r8
	strh r0, [r3, #0x30]
	strh r7, [r3, #0x32]
	movs r0, #8
	ldrsh r1, [r6, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrh r0, [r0, #0x24]
	strh r0, [r3, #0x24]
	adds r5, #0x1c
	adds r4, r4, r5
	ldr r0, _080A86C0
	str r0, [r4]
	ldrh r0, [r6, #0x12]
	adds r0, #1
	strh r0, [r6, #0x12]
_080A86B0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A86BC: .4byte 0x020205AC
_080A86C0: .4byte 0x080A86C5
	thumb_func_end sub_080A8640

	thumb_func_start sub_080A86C4
sub_080A86C4: @ 0x080A86C4
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2e]
	subs r0, #1
	strh r0, [r3, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A86EE
	ldr r2, _080A86F4
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0, #0x12]
	subs r1, #1
	strh r1, [r0, #0x12]
	adds r0, r3, #0
	bl DestroySpriteWithActiveSheet
_080A86EE:
	pop {r0}
	bx r0
	.align 2, 0
_080A86F4: .4byte 0x03005B60
	thumb_func_end sub_080A86C4

	thumb_func_start sub_080A86F8
sub_080A86F8: @ 0x080A86F8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _080A872C
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x22]
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A8730
	movs r0, #5
	b _080A8732
	.align 2, 0
_080A872C: .4byte 0x020380D6
_080A8730:
	ldr r0, _080A8744
_080A8732:
	strh r0, [r5, #0x2e]
	ldr r0, _080A8748
	strh r0, [r5, #0x30]
	ldr r0, _080A874C
	str r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A8744: .4byte 0x0000FFF6
_080A8748: .4byte 0x0000FFD8
_080A874C: .4byte 0x080A8751
	thumb_func_end sub_080A86F8

	thumb_func_start sub_080A8750
sub_080A8750: @ 0x080A8750
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x32]
	adds r0, r0, r1
	strh r0, [r4, #0x32]
	ldrh r5, [r4, #0x30]
	ldrh r2, [r4, #0x34]
	adds r0, r5, r2
	strh r0, [r4, #0x34]
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4, #0x24]
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4, #0x26]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x14
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080A878C
	adds r0, r5, #1
	strh r0, [r4, #0x30]
_080A878C:
	movs r1, #0x22
	ldrsh r0, [r4, r1]
	movs r2, #0x26
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	movs r1, #0x20
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080A87A4
	adds r0, r4, #0
	bl DestroyAnimSprite
_080A87A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080A8750

	thumb_func_start sub_080A87AC
sub_080A87AC: @ 0x080A87AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _080A87E4
	ldrh r0, [r5, #4]
	strh r0, [r4, #0x2e]
	ldrh r0, [r5, #8]
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x32]
	ldrh r0, [r5, #0xa]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x36]
	ldr r0, _080A87E8
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A87EC
	ldrh r0, [r5, #8]
	adds r0, #0x1e
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r5, #0xa]
	subs r0, #0x14
	b _080A87FA
	.align 2, 0
_080A87E4: .4byte 0x020380BE
_080A87E8: .4byte 0x020380D7
_080A87EC:
	ldrh r0, [r5, #8]
	subs r0, #0x1e
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r5, #0xa]
	subs r0, #0x50
_080A87FA:
	strh r0, [r4, #0x22]
	ldr r0, _080A8810
	str r0, [r4, #0x1c]
	ldr r1, _080A8814
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A8810: .4byte 0x080A67B5
_080A8814: .4byte 0x080A34C5
	thumb_func_end sub_080A87AC
