.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_080976D8
sub_080976D8: @ 0x080976D8
	push {lr}
	adds r1, r0, #0
	movs r2, #0x34
	ldrsh r0, [r1, r2]
	cmp r0, #1
	beq _080976F4
	cmp r0, #1
	bgt _080976EE
	cmp r0, #0
	beq _08097714
	b _08097704
_080976EE:
	cmp r0, #2
	beq _080976FC
	b _08097704
_080976F4:
	adds r0, r1, #0
	bl sub_080976A0
	b _08097714
_080976FC:
	adds r0, r1, #0
	bl sub_08097664
	b _08097714
_08097704:
	movs r0, #0
	strh r0, [r1, #0x34]
	ldr r0, _08097718
	ldr r1, _0809771C
	ldr r2, _08097720
	movs r3, #1
	bl AGBAssert
_08097714:
	pop {r0}
	bx r0
	.align 2, 0
_08097718: .4byte 0x084E6CA8
_0809771C: .4byte 0x00003106
_08097720: .4byte 0x084E6CB4
	thumb_func_end sub_080976D8

	thumb_func_start sub_08097724
sub_08097724: @ 0x08097724
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0809749C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	beq _08097748
	ldr r0, _0809774C
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r2, #0x34
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _08097750
_08097748:
	movs r0, #0
	b _08097752
	.align 2, 0
_0809774C: .4byte 0x020205AC
_08097750:
	movs r0, #1
_08097752:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08097724

	thumb_func_start sub_08097758
sub_08097758: @ 0x08097758
	push {r4, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _0809777C
	adds r2, r1, #4
	adds r3, r1, #0
	adds r3, #8
	bl EventObjectGetLocalIdAndMap
	adds r0, r4, #0
	bl FieldEffectStart
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0809777C: .4byte 0x020388A8
	thumb_func_end sub_08097758

	thumb_func_start DoShadowFieldEffect
DoShadowFieldEffect: @ 0x08097780
	push {lr}
	adds r1, r0, #0
	ldrb r2, [r1, #2]
	lsls r0, r2, #0x19
	cmp r0, #0
	blt _08097798
	movs r0, #0x40
	orrs r0, r2
	strb r0, [r1, #2]
	movs r0, #3
	bl sub_08097758
_08097798:
	pop {r0}
	bx r0
	thumb_func_end DoShadowFieldEffect

	thumb_func_start DoRippleFieldEffect
DoRippleFieldEffect: @ 0x0809779C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r0, #5]
	bl GetObjectEventGraphicsInfo
	ldr r2, _080977D4
	movs r3, #0x20
	ldrsh r1, [r4, r3]
	str r1, [r2]
	movs r3, #0x22
	ldrsh r1, [r4, r3]
	ldrh r0, [r0, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	adds r1, r1, r0
	subs r1, #2
	str r1, [r2, #4]
	movs r0, #0x97
	str r0, [r2, #8]
	movs r0, #3
	str r0, [r2, #0xc]
	movs r0, #5
	bl FieldEffectStart
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080977D4: .4byte 0x020388A8
	thumb_func_end DoRippleFieldEffect

	thumb_func_start MovementAction_StoreAndLockAnim_Step0
MovementAction_StoreAndLockAnim_Step0: @ 0x080977D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	mov r8, r1
	movs r0, #0
	mov ip, r0
	ldr r0, _08097804
	ldr r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	bne _08097808
	movs r0, #0x14
	bl AllocZeroed
	str r0, [r6]
	ldrb r1, [r4, #8]
	strb r1, [r0]
	ldr r1, [r6]
	movs r0, #1
	strb r0, [r1, #0x10]
	b _08097854
	.align 2, 0
_08097804: .4byte 0x02037258
_08097808:
	movs r2, #0x10
	movs r5, #0
	movs r1, #0
	adds r3, r6, #0
	b _08097818
_08097812:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_08097818:
	cmp r1, #0xf
	bhi _0809783A
	cmp r2, #0x10
	bne _0809782C
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809782C
	adds r2, r1, #0
_0809782C:
	ldr r0, [r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrb r7, [r4, #8]
	cmp r0, r7
	bne _08097812
	movs r5, #1
_0809783A:
	cmp r5, #0
	bne _08097856
	cmp r2, #0x10
	beq _08097856
	ldr r0, [r6]
	adds r0, r0, r2
	ldrb r1, [r4, #8]
	strb r1, [r0]
	ldr r1, [r6]
	ldrb r0, [r1, #0x10]
	adds r0, #1
	strb r0, [r1, #0x10]
	movs r0, #1
_08097854:
	mov ip, r0
_08097856:
	mov r1, ip
	cmp r1, #1
	bne _08097868
	ldrb r0, [r4, #1]
	movs r1, #0x10
	orrs r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r4, #1]
_08097868:
	movs r0, #1
	mov r7, r8
	strh r0, [r7, #0x32]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end MovementAction_StoreAndLockAnim_Step0

	thumb_func_start MovementAction_FreeAndUnlockAnim_Step0
MovementAction_FreeAndUnlockAnim_Step0: @ 0x08097878
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r1
	movs r0, #1
	strh r0, [r1, #0x32]
	ldr r5, _080978FC
	ldr r0, [r5]
	cmp r0, #0
	beq _080978F0
	movs r7, #0
	adds r0, r6, #0
	bl FindLockedEventObjectIndex
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x10
	beq _080978B0
	ldr r0, [r5]
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r1, [r5]
	ldrb r0, [r1, #0x10]
	subs r0, #1
	strb r0, [r1, #0x10]
	movs r7, #1
_080978B0:
	ldr r0, [r5]
	ldrb r4, [r0, #0x10]
	cmp r4, #0
	bne _080978BE
	bl Free
	str r4, [r5]
_080978BE:
	cmp r7, #1
	bne _080978F0
	ldrb r0, [r6, #5]
	bl GetObjectEventGraphicsInfo
	ldrb r1, [r0, #0xc]
	lsls r1, r1, #0x19
	lsrs r1, r1, #0x1f
	lsls r1, r1, #4
	ldrb r2, [r6, #1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r6, #1]
	mov r2, r8
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_080978F0:
	movs r0, #1
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080978FC: .4byte 0x02037258
	thumb_func_end MovementAction_FreeAndUnlockAnim_Step0

	thumb_func_start FindLockedEventObjectIndex
FindLockedEventObjectIndex: @ 0x08097900
	push {lr}
	movs r2, #0
	ldr r1, _08097918
	ldr r1, [r1]
	ldrb r3, [r0, #8]
_0809790A:
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, r3
	bne _0809791C
	adds r0, r2, #0
	b _08097928
	.align 2, 0
_08097918: .4byte 0x02037258
_0809791C:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xf
	bls _0809790A
	movs r0, #0x10
_08097928:
	pop {r1}
	bx r1
	thumb_func_end FindLockedEventObjectIndex

	thumb_func_start CreateLevitateMovementTask
CreateLevitateMovementTask: @ 0x0809792C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08097960
	movs r1, #0xff
	bl CreateTask
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #3
	ldr r0, _08097964
	adds r4, r4, r0
	adds r0, r4, #0
	adds r0, #8
	adds r1, r6, #0
	bl StoreWordInTwoHalfwords
	strb r5, [r6, #0x1b]
	ldr r0, _08097968
	strh r0, [r4, #0xe]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08097960: .4byte 0x0809796D
_08097964: .4byte 0x03005B60
_08097968: .4byte 0x0000FFFF
	thumb_func_end CreateLevitateMovementTask

	thumb_func_start ApplyLevitateMovement
ApplyLevitateMovement: @ 0x0809796C
	push {r4, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080979C4
	adds r4, r1, r0
	adds r0, r4, #0
	adds r0, #8
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	ldr r0, [sp]
	ldrb r1, [r0, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080979C8
	adds r2, r0, r1
	ldrh r1, [r4, #0xc]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080979A8
	ldrh r0, [r4, #0xe]
	ldrh r1, [r2, #0x26]
	adds r0, r0, r1
	strh r0, [r2, #0x26]
_080979A8:
	ldrh r1, [r4, #0xc]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080979B8
	ldrh r0, [r4, #0xe]
	rsbs r0, r0, #0
	strh r0, [r4, #0xe]
_080979B8:
	adds r0, r1, #1
	strh r0, [r4, #0xc]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080979C4: .4byte 0x03005B60
_080979C8: .4byte 0x020205AC
	thumb_func_end ApplyLevitateMovement

	thumb_func_start DestroyExtraMovementTask
DestroyExtraMovementTask: @ 0x080979CC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r1, _080979F8
	adds r0, r0, r1
	adds r0, #8
	mov r1, sp
	bl LoadWordFromTwoHalfwords
	adds r0, r4, #0
	bl DestroyTask
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080979F8: .4byte 0x03005B60
	thumb_func_end DestroyExtraMovementTask

	thumb_func_start sub_080979FC
sub_080979FC: @ 0x080979FC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	movs r4, #0
	ldr r7, _08097A40
_08097A0A:
	cmp r4, r6
	beq _08097A30
	cmp r4, r5
	beq _08097A30
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r1, r0, r7
	ldrb r0, [r1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08097A30
	ldr r0, _08097A44
	ldrb r0, [r0, #5]
	cmp r4, r0
	beq _08097A30
	adds r0, r1, #0
	bl FreezeEventObject
_08097A30:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bls _08097A0A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08097A40: .4byte 0x02036FF0
_08097A44: .4byte 0x02037230
	thumb_func_end sub_080979FC

	thumb_func_start MovementAction_FlyUp_Step0
MovementAction_FlyUp_Step0: @ 0x08097A48
	movs r0, #0
	strh r0, [r1, #0x26]
	ldrh r0, [r1, #0x32]
	adds r0, #1
	strh r0, [r1, #0x32]
	movs r0, #0
	bx lr
	.align 2, 0
	thumb_func_end MovementAction_FlyUp_Step0

	thumb_func_start MovementAction_FlyUp_Step1
MovementAction_FlyUp_Step1: @ 0x08097A58
	push {lr}
	adds r2, r1, #0
	ldrh r0, [r2, #0x26]
	subs r0, #8
	strh r0, [r2, #0x26]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	bne _08097A74
	ldrh r0, [r2, #0x32]
	adds r0, #1
	strh r0, [r2, #0x32]
_08097A74:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_FlyUp_Step1

	thumb_func_start MovementAction_FlyDown_Step0
MovementAction_FlyDown_Step0: @ 0x08097A7C
	ldr r0, _08097A8C
	strh r0, [r1, #0x26]
	ldrh r0, [r1, #0x32]
	adds r0, #1
	strh r0, [r1, #0x32]
	movs r0, #0
	bx lr
	.align 2, 0
_08097A8C: .4byte 0x0000FF60
	thumb_func_end MovementAction_FlyDown_Step0

	thumb_func_start MovementAction_FlyDown_Step1
MovementAction_FlyDown_Step1: @ 0x08097A90
	push {lr}
	ldrh r0, [r1, #0x26]
	adds r0, #8
	strh r0, [r1, #0x26]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08097AA4
	ldrh r0, [r1, #0x32]
	adds r0, #1
	strh r0, [r1, #0x32]
_08097AA4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end MovementAction_FlyDown_Step1

	thumb_func_start MovementAction_Finish
MovementAction_Finish: @ 0x08097AAC
	movs r0, #1
	bx lr
	thumb_func_end MovementAction_Finish


	.globl SetVirtualObjectInvisibility
	.set SetVirtualObjectInvisibility, sub_080975B4

	.globl SetVirtualObjectGraphics
	.set SetVirtualObjectGraphics, sub_08097524

	.globl IsVirtualObjectInvisible
	.set IsVirtualObjectInvisible, sub_080975FC

	.globl SetVirtualObjectSpriteAnim
	.set SetVirtualObjectSpriteAnim, sub_08097634

	.globl TurnVirtualObject
	.set TurnVirtualObject, sub_080974E8

	.globl IsVirtualObjectAnimating
	.set IsVirtualObjectAnimating, sub_08097724

	.globl ObjectEventFaceOppositeDirection
	.set ObjectEventFaceOppositeDirection, EventObjectFaceOppositeDirection


	.globl TryMoveObjectEventToMapCoords

	.globl TurnVirtualObject
	.set TurnVirtualObject, sub_080974E8
