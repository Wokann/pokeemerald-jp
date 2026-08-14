.include "asm/macros.inc"
.include "constants/constants.inc"
	.section .text.battle_anim_effects_1_rest,"ax",%progbits
.syntax unified





	thumb_func_start sub_08102790
sub_08102790: @ 0x08102790
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, _081027A4
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _081027AC
	ldr r4, _081027A8
	b _081027AE
	.align 2, 0
_081027A4: .4byte 0x020380BE
_081027A8: .4byte 0x020380D6
_081027AC:
	ldr r4, _081027EC
_081027AE:
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r6, [r6, #4]
	adds r0, r0, r6
	strh r0, [r5, #0x22]
	movs r0, #0
	strh r0, [r5, #0x2e]
	strh r0, [r5, #0x30]
	ldr r1, _081027F0
	adds r0, r5, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _081027F4
	str r0, [r5, #0x1c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081027EC: .4byte 0x020380D7
_081027F0: .4byte 0x081028DD
_081027F4: .4byte 0x080A60A1
	thumb_func_end sub_08102790

	thumb_func_start sub_081027F8
sub_081027F8: @ 0x081027F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08102830
	ldrb r0, [r5]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08102834
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrb r0, [r5]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x22]
	ldr r1, _08102838
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _0810283C
	str r0, [r4, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08102830: .4byte 0x020380D7
_08102834: .4byte 0x0000FFD0
_08102838: .4byte 0x08102895
_0810283C: .4byte 0x080A60A1
	thumb_func_end sub_081027F8

	thumb_func_start sub_08102840
sub_08102840: @ 0x08102840
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, _08102884
	ldrb r0, [r5]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08102888
	ldr r2, _0810288C
	adds r0, r0, r2
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r6, #0
	strh r0, [r4, #0x20]
	ldrb r0, [r5]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x22]
	adds r0, r4, #0
	movs r1, #1
	bl StartSpriteAnim
	strh r6, [r4, #0x2e]
	strh r6, [r4, #0x30]
	ldr r0, _08102890
	str r0, [r4, #0x1c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08102884: .4byte 0x020380D7
_08102888: .4byte 0x020380BE
_0810288C: .4byte 0x0000FFD0
_08102890: .4byte 0x081028DD
	thumb_func_end sub_08102840

	thumb_func_start sub_08102894
sub_08102894: @ 0x08102894
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _081028BE
	movs r0, #0xc
	strh r0, [r4, #0x2e]
	movs r0, #8
	strh r0, [r4, #0x30]
	movs r0, #0
	strh r0, [r4, #0x32]
	ldr r1, _081028C4
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _081028C8
	str r0, [r4, #0x1c]
_081028BE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081028C4: .4byte 0x081028CD
_081028C8: .4byte 0x080A5E05
	thumb_func_end sub_08102894

	thumb_func_start sub_081028CC
sub_081028CC: @ 0x081028CC
	movs r1, #0
	strh r1, [r0, #0x2e]
	strh r1, [r0, #0x30]
	ldr r1, _081028D8
	str r1, [r0, #0x1c]
	bx lr
	.align 2, 0
_081028D8: .4byte 0x081028DD
	thumb_func_end sub_081028CC

	thumb_func_start sub_081028DC
sub_081028DC: @ 0x081028DC
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2e]
	adds r0, #1
	strh r0, [r3, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08102924
	movs r0, #0
	strh r0, [r3, #0x2e]
	movs r0, #0x3e
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	lsrs r1, r2, #2
	movs r0, #1
	eors r1, r0
	ands r1, r0
	lsls r1, r1, #2
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r3, #0x30]
	adds r0, #1
	strh r0, [r3, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _08102924
	adds r0, r3, #0
	bl DestroyAnimSprite
_08102924:
	pop {r0}
	bx r0
	thumb_func_end sub_081028DC

	thumb_func_start sub_08102928
sub_08102928: @ 0x08102928
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, _0810293C
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _08102944
	ldr r4, _08102940
	b _08102946
	.align 2, 0
_0810293C: .4byte 0x020380BE
_08102940: .4byte 0x020380D6
_08102944:
	ldr r4, _08102980
_08102946:
	ldrb r0, [r4]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r6, [r6, #4]
	adds r0, r0, r6
	strh r0, [r5, #0x22]
	movs r0, #0
	strh r0, [r5, #0x2e]
	ldr r0, _08102984
	ldrh r0, [r0, #6]
	strh r0, [r5, #0x30]
	ldr r0, _08102988
	str r0, [r5, #0x1c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08102980: .4byte 0x020380D7
_08102984: .4byte 0x020380BE
_08102988: .4byte 0x0810298D
	thumb_func_end sub_08102928

	thumb_func_start sub_0810298C
sub_0810298C: @ 0x0810298C
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2e]
	adds r0, #1
	strh r0, [r2, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	cmp r0, r1
	ble _081029AC
	movs r0, #0
	strh r0, [r2, #0x2e]
	ldrh r0, [r2, #0x22]
	subs r0, #1
	strh r0, [r2, #0x22]
_081029AC:
	ldrh r0, [r2, #0x22]
	ldrh r1, [r2, #0x2e]
	subs r0, r0, r1
	strh r0, [r2, #0x22]
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081029C8
	adds r0, r2, #0
	bl DestroyAnimSprite
_081029C8:
	pop {r0}
	bx r0
	thumb_func_end sub_0810298C

	thumb_func_start sub_081029CC
sub_081029CC: @ 0x081029CC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r6, _08102A14
	ldrb r0, [r6]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r5, #0
	strh r0, [r4, #0x20]
	ldrb r0, [r6]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #0xc
	strh r0, [r4, #0x22]
	strh r5, [r4, #0x2e]
	movs r0, #2
	strh r0, [r4, #0x30]
	strh r5, [r4, #0x32]
	strh r5, [r4, #0x34]
	strh r5, [r4, #0x36]
	subs r0, #0x42
	bl BattleAnimAdjustPanning
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	strh r0, [r4, #0x38]
	ldr r0, _08102A18
	str r0, [r4, #0x1c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08102A14: .4byte 0x020380D6
_08102A18: .4byte 0x08102A1D
	thumb_func_end sub_081029CC

	thumb_func_start sub_08102A1C
sub_08102A1C: @ 0x08102A1C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _08102A88
	adds r3, r4, #0
	adds r3, #0x3e
	ldrb r2, [r3]
	lsrs r1, r2, #2
	movs r0, #1
	eors r1, r0
	ands r1, r0
	lsls r1, r1, #2
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08102A6E
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08102A6E
	ldrh r1, [r4, #0x38]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0xc2
	bl PlaySE12WithPanning
_08102A6E:
	movs r1, #0
	strh r1, [r4, #0x2e]
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08102A88
	strh r1, [r4, #0x32]
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
_08102A88:
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08102AB2
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	cmp r0, #0x10
	ble _08102AB2
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08102AB2
	adds r0, r4, #0
	bl DestroyAnimSprite
_08102AB2:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_08102A1C

	thumb_func_start sub_08102AB8
sub_08102AB8: @ 0x08102AB8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _08102B02
	ldr r4, _08102B18
	ldrb r0, [r4]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	ldr r5, _08102B1C
	lsrs r0, r0, #0x18
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r6, #0x20]
	ldrb r0, [r4]
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r5, [r5, #2]
	adds r0, r0, r5
	strh r0, [r6, #0x22]
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08102AFC
	ldrh r0, [r6, #0x22]
	adds r0, #0xa
	strh r0, [r6, #0x22]
_08102AFC:
	ldrh r0, [r6, #0x2e]
	adds r0, #1
	strh r0, [r6, #0x2e]
_08102B02:
	ldr r0, _08102B1C
	ldrh r1, [r0, #0xe]
	ldr r0, _08102B20
	cmp r1, r0
	bne _08102B12
	adds r0, r6, #0
	bl DestroyAnimSprite
_08102B12:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08102B18: .4byte 0x020380D6
_08102B1C: .4byte 0x020380BE
_08102B20: .4byte 0x0000FFFF
	thumb_func_end sub_08102AB8

	thumb_func_start sub_08102B24
sub_08102B24: @ 0x08102B24
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _08102B44
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r4, r0, r1
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	cmp r0, #1
	bne _08102B50
	ldr r1, _08102B48
	ldr r0, _08102B4C
	strh r0, [r1, #0xe]
	b _08102B8E
	.align 2, 0
_08102B44: .4byte 0x03005B60
_08102B48: .4byte 0x020380BE
_08102B4C: .4byte 0x0000FFFF
_08102B50:
	cmp r0, #2
	bne _08102B5C
	adds r0, r2, #0
	bl DestroyAnimVisualTask
	b _08102B94
_08102B5C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _08102B94
	movs r0, #0
	strh r0, [r4, #8]
	ldrh r2, [r4, #0xa]
	adds r2, #1
	strh r2, [r4, #0xa]
	lsls r1, r2, #8
	movs r0, #0x10
	subs r0, r0, r2
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0x10
	bne _08102B94
_08102B8E:
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
_08102B94:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08102B24

	thumb_func_start sub_08102B9C
sub_08102B9C: @ 0x08102B9C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	bl InitSpritePosToAnimTarget
	adds r2, r4, #0
	adds r2, #0x2c
	ldrb r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08102BC4
	ldrh r0, [r0, #4]
	strh r0, [r4, #0x2e]
	ldr r0, _08102BC8
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08102BC4: .4byte 0x020380BE
_08102BC8: .4byte 0x08102BCD
	thumb_func_end sub_08102B9C

	thumb_func_start sub_08102BCC
sub_08102BCC: @ 0x08102BCC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r1, [r5, #0x2e]
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	cmp r0, #0
	beq _08102BE0
	subs r0, r1, #1
	strh r0, [r5, #0x2e]
	b _08102C1C
_08102BE0:
	adds r2, r5, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	movs r0, #0x1e
	strh r0, [r5, #0x2e]
	ldr r4, _08102C24
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x32]
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x36]
	ldr r0, _08102C28
	str r0, [r5, #0x1c]
	ldr r1, _08102C2C
	adds r0, r5, #0
	bl StoreSpriteCallbackInData6
_08102C1C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08102C24: .4byte 0x020380D6
_08102C28: .4byte 0x080A67B5
_08102C2C: .4byte 0x080A34C5
	thumb_func_end sub_08102BCC

	thumb_func_start sub_08102C30
sub_08102C30: @ 0x08102C30
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _08102C80
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _08102C78
	movs r0, #0
	strh r0, [r4, #8]
	ldrh r1, [r4, #0xa]
	adds r1, #1
	strh r1, [r4, #0xa]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0x10
	bne _08102C78
	adds r0, r5, #0
	bl DestroyAnimVisualTask
_08102C78:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08102C80: .4byte 0x03005B60
	thumb_func_end sub_08102C30

	thumb_func_start unref_sub_8102434
unref_sub_8102434: @ 0x08102C84
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r4, #0
	ldr r0, _08102CEC
	ldrb r0, [r0]
	cmp r4, r0
	bhs _08102CE0
	ldr r6, _08102CF0
	ldr r5, _08102CF4
_08102C98:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #1
	bne _08102CB4
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08102CB4
	adds r0, r4, r5
	ldrb r0, [r0]
	bl SetHealthboxSpriteInvisible
_08102CB4:
	movs r1, #2
	ldrsh r0, [r6, r1]
	cmp r0, #1
	bne _08102CD2
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08102CD2
	adds r0, r4, r5
	ldrb r0, [r0]
	bl SetHealthboxSpriteInvisible
_08102CD2:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _08102CEC
	ldrb r0, [r0]
	cmp r4, r0
	blo _08102C98
_08102CE0:
	adds r0, r7, #0
	bl DestroyAnimVisualTask
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08102CEC: .4byte 0x02023D10
_08102CF0: .4byte 0x020380BE
_08102CF4: .4byte 0x03005AD0
	thumb_func_end unref_sub_8102434

	thumb_func_start unref_sub_81024A8
unref_sub_81024A8: @ 0x08102CF8
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #0
	b _08102D12
_08102D02:
	ldr r0, _08102D28
	adds r0, r4, r0
	ldrb r0, [r0]
	bl SetHealthboxSpriteVisible
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_08102D12:
	ldr r0, _08102D2C
	ldrb r0, [r0]
	cmp r4, r0
	blo _08102D02
	adds r0, r5, #0
	bl DestroyAnimVisualTask
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08102D28: .4byte 0x03005AD0
_08102D2C: .4byte 0x02023D10
	thumb_func_end unref_sub_81024A8

	thumb_func_start sub_08102D30
sub_08102D30: @ 0x08102D30
	push {r4, lr}
	adds r4, r0, #0
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08102D46
	movs r0, #0x30
	strh r0, [r4, #0x20]
	movs r0, #0x28
	b _08102D4E
_08102D46:
	ldr r0, _08102D70
	ldrh r1, [r0]
	strh r1, [r4, #0x20]
	ldrh r0, [r0, #2]
_08102D4E:
	strh r0, [r4, #0x22]
	ldrb r1, [r4, #1]
	movs r0, #0x3f
	ands r0, r1
	strb r0, [r4, #1]
	ldrb r0, [r4, #3]
	movs r1, #0xc0
	orrs r0, r1
	strb r0, [r4, #3]
	movs r0, #0
	strh r0, [r4, #0x2e]
	ldr r0, _08102D74
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08102D70: .4byte 0x020380BE
_08102D74: .4byte 0x08102D79
	thumb_func_end sub_08102D30

	thumb_func_start sub_08102D78
sub_08102D78: @ 0x08102D78
	push {lr}
	adds r1, r0, #0
	movs r2, #0x2e
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _08102D8A
	adds r0, r1, #0
	bl DestroyAnimSprite
_08102D8A:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08102D78

	thumb_func_start sub_08102D90
sub_08102D90: @ 0x08102D90
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08102DC8
	ldrb r0, [r0]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	ldr r2, _08102DCC
	lsrs r0, r0, #0x18
	ldrh r1, [r2]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r4, #0x20]
	ldrh r0, [r2, #2]
	strh r0, [r4, #0x22]
	strh r1, [r4, #0x2e]
	strh r1, [r4, #0x30]
	strh r1, [r4, #0x32]
	strh r1, [r4, #0x34]
	movs r0, #1
	strh r0, [r4, #0x36]
	ldr r0, _08102DD0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08102DC8: .4byte 0x020380D6
_08102DCC: .4byte 0x020380BE
_08102DD0: .4byte 0x08102DD5
	thumb_func_end sub_08102D90

	thumb_func_start sub_08102DD4
sub_08102DD4: @ 0x08102DD4
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x30]
	adds r0, #1
	strh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08102DFE
	movs r0, #0
	strh r0, [r1, #0x30]
	ldrh r2, [r1, #0x32]
	movs r3, #0x32
	ldrsh r0, [r1, r3]
	cmp r0, #0x77
	bgt _08102DFE
	ldrh r0, [r1, #0x22]
	adds r0, #1
	strh r0, [r1, #0x22]
	adds r0, r2, #1
	strh r0, [r1, #0x32]
_08102DFE:
	movs r2, #0x2e
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _08102E0C
	adds r0, r1, #0
	bl DestroyAnimSprite
_08102E0C:
	pop {r0}
	bx r0
	thumb_func_end sub_08102DD4

	thumb_func_start sub_08102E10
sub_08102E10: @ 0x08102E10
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl sub_080A6E74
	mov r8, r0
	ldr r0, _08102EE0
	mov r1, r8
	ands r1, r0
	mov r8, r1
	ldr r0, _08102EE4
	mov sb, r0
	lsls r5, r7, #2
	adds r5, r5, r7
	lsls r5, r5, #3
	adds r6, r5, r0
	strh r4, [r6, #8]
	strh r4, [r6, #0xa]
	strh r4, [r6, #0xc]
	strh r1, [r6, #0xe]
	strh r4, [r6, #0x10]
	strh r4, [r6, #0x12]
	strh r4, [r6, #0x14]
	movs r0, #0xd
	strh r0, [r6, #0x16]
	movs r0, #0xe
	strh r0, [r6, #0x18]
	movs r0, #0xf
	strh r0, [r6, #0x1a]
	movs r0, #1
	movs r1, #1
	movs r2, #1
	movs r3, #1
	bl sub_080A6F8C
	mov sl, r0
	mov r1, r8
	orrs r1, r0
	mov r8, r1
	movs r0, #8
	add sb, r0
	add r5, sb
	adds r0, r5, #0
	adds r0, #0x1c
	adds r5, #0x1e
	adds r1, r5, #0
	mov r2, r8
	bl StorePointerInVars
	ldr r0, _08102EE8
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0x80
	lsls r4, r4, #9
	adds r1, r4, #0
	lsls r1, r0
	mov r0, sl
	orrs r0, r1
	mov sl, r0
	ldr r0, _08102EEC
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0
	mov r1, sl
	orrs r4, r1
	ldr r0, _08102EF0
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r1, _08102EF4
	str r1, [r6]
	adds r0, r7, #0
	bl _call_via_r1
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08102EE0: .4byte 0x0000FFFF
_08102EE4: .4byte 0x03005B60
_08102EE8: .4byte 0x000027D2
_08102EEC: .4byte 0x000027D3
_08102EF0: .4byte 0x00007FBB
_08102EF4: .4byte 0x08102EF9
	thumb_func_end sub_08102E10

	thumb_func_start sub_08102EF8
sub_08102EF8: @ 0x08102EF8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _08102F20
	adds r4, r0, r1
	movs r0, #8
	ldrsh r1, [r4, r0]
	cmp r1, #1
	beq _08102FE4
	cmp r1, #1
	bgt _08102F24
	cmp r1, #0
	beq _08102F32
	b _08103082
	.align 2, 0
_08102F20: .4byte 0x03005B60
_08102F24:
	cmp r1, #2
	bne _08102F2A
	b _0810303C
_08102F2A:
	cmp r1, #3
	bne _08102F30
	b _08103070
_08102F30:
	b _08103082
_08102F32:
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _08102F40
	b _08103082
_08102F40:
	strh r1, [r4, #0xa]
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bgt _08102F8C
	ldrh r0, [r4, #0x16]
	ldrh r1, [r4, #0x10]
	adds r0, r0, r1
	strh r0, [r4, #0x10]
	ldrh r2, [r4, #0x18]
	ldrh r3, [r4, #0x12]
	adds r2, r2, r3
	strh r2, [r4, #0x12]
	ldrh r1, [r4, #0x1a]
	ldrh r5, [r4, #0x14]
	adds r1, r1, r5
	strh r1, [r4, #0x14]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x13
	lsls r2, r2, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x13
	lsls r1, r1, #0x10
	lsrs r2, r2, #0xb
	orrs r0, r2
	lsrs r1, r1, #6
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov ip, r0
	b _08102F96
_08102F8C:
	ldr r7, _08102FDC
	mov ip, r7
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
_08102F96:
	movs r2, #1
	movs r3, #0
	movs r1, #0
_08102F9C:
	movs r5, #0xe
	ldrsh r0, [r4, r5]
	ands r0, r2
	lsls r5, r2, #0x11
	adds r6, r3, #0
	adds r6, #0x10
	adds r1, #1
	mov r8, r1
	cmp r0, #0
	beq _08102FC8
	movs r1, #1
	ldr r2, _08102FE0
_08102FB4:
	adds r0, r3, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	mov r7, ip
	strh r7, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xf
	bls _08102FB4
_08102FC8:
	lsrs r2, r5, #0x10
	lsls r0, r6, #0x10
	lsrs r3, r0, #0x10
	mov r1, r8
	lsls r0, r1, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xf
	bls _08102F9C
	b _08103082
	.align 2, 0
_08102FDC: .4byte 0x00007FBB
_08102FE0: .4byte 0x020377B4
_08102FE4:
	ldr r0, _0810302C
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08103082
	movs r2, #0
	ldr r3, _08103030
	movs r5, #0x14
	adds r5, r5, r3
	mov ip, r5
	ldr r7, _08103034
	mov r8, r7
	ldr r6, _08103038
	movs r5, #1
_08103002:
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r1, r0, #2
	mov r7, ip
	adds r0, r1, r7
	ldr r0, [r0]
	cmp r0, r8
	beq _08103016
	cmp r0, r6
	bne _0810301A
_08103016:
	adds r0, r1, r3
	strh r5, [r0, #0x2e]
_0810301A:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x3f
	bls _08103002
	movs r0, #0
	strh r0, [r4, #0xa]
	b _08103064
	.align 2, 0
_0810302C: .4byte 0x02037C74
_08103030: .4byte 0x020205AC
_08103034: .4byte 0x0856EAA0
_08103038: .4byte 0x0856EAD0
_0810303C:
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x1e
	ble _08103082
	movs r1, #0x24
	ldrsh r0, [r4, r1]
	movs r2, #0x26
	ldrsh r1, [r4, r2]
	bl LoadPointerFromVars
	ldr r1, _0810306C
	str r1, [sp]
	movs r1, #0
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
_08103064:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _08103082
	.align 2, 0
_0810306C: .4byte 0x00007FBB
_08103070:
	ldr r0, _08103090
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08103082
	adds r0, r2, #0
	bl DestroyAnimVisualTask
_08103082:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08103090: .4byte 0x02037C74
	thumb_func_end sub_08102EF8

	thumb_func_start sub_08103094
sub_08103094: @ 0x08103094
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, _08103118
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, #1
	bgt _081030A6
	movs r0, #2
	strh r0, [r6, #4]
_081030A6:
	movs r1, #4
	ldrsh r0, [r6, r1]
	cmp r0, #0x7f
	ble _081030B2
	movs r0, #0x7f
	strh r0, [r6, #4]
_081030B2:
	movs r0, #0
	strh r0, [r5, #0x2e]
	ldrh r0, [r6, #4]
	strh r0, [r5, #0x30]
	ldr r4, _0810311C
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r6, [r6, #2]
	adds r0, r0, r6
	strh r0, [r5, #0x22]
	ldrh r1, [r5, #0x20]
	strh r1, [r5, #0x3a]
	strh r0, [r5, #0x3c]
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08103124
	ldrb r1, [r5, #3]
	movs r0, #0x3f
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r5, #3]
	ldrh r0, [r5, #0x20]
	adds r0, #0x28
	strh r0, [r5, #0x20]
	ldrh r4, [r5, #0x22]
	adds r4, #0x14
	strh r4, [r5, #0x22]
	lsls r0, r0, #7
	strh r0, [r5, #0x32]
	movs r0, #0x30
	ldrsh r1, [r5, r0]
	ldr r0, _08103120
	b _0810314A
	.align 2, 0
_08103118: .4byte 0x020380BE
_0810311C: .4byte 0x020380D7
_08103120: .4byte 0xFFFFEC00
_08103124:
	ldr r0, _08103164
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0810316C
	ldrh r0, [r5, #0x20]
	subs r0, #0x28
	strh r0, [r5, #0x20]
	ldrh r4, [r5, #0x22]
	adds r4, #0x14
	strh r4, [r5, #0x22]
	lsls r0, r0, #7
	strh r0, [r5, #0x32]
	movs r0, #0x30
	ldrsh r1, [r5, r0]
	movs r0, #0xa0
	lsls r0, r0, #5
_0810314A:
	bl __divsi3
	strh r0, [r5, #0x34]
	lsls r4, r4, #7
	strh r4, [r5, #0x36]
	movs r0, #0x30
	ldrsh r1, [r5, r0]
	ldr r0, _08103168
	bl __divsi3
	strh r0, [r5, #0x38]
	b _081031A8
	.align 2, 0
_08103164: .4byte 0x020380D6
_08103168: .4byte 0xFFFFF600
_0810316C:
	ldrh r0, [r5, #0x20]
	adds r0, #0x28
	strh r0, [r5, #0x20]
	ldrh r4, [r5, #0x22]
	subs r4, #0x14
	strh r4, [r5, #0x22]
	lsls r0, r0, #7
	strh r0, [r5, #0x32]
	movs r0, #0x30
	ldrsh r1, [r5, r0]
	ldr r0, _081031B4
	bl __divsi3
	strh r0, [r5, #0x34]
	lsls r4, r4, #7
	strh r4, [r5, #0x36]
	movs r0, #0x30
	ldrsh r1, [r5, r0]
	movs r0, #0xa0
	lsls r0, r0, #4
	bl __divsi3
	strh r0, [r5, #0x38]
	ldrb r1, [r5, #3]
	movs r0, #0x3f
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	strb r0, [r5, #3]
_081031A8:
	ldr r0, _081031B8
	str r0, [r5, #0x1c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081031B4: .4byte 0xFFFFEC00
_081031B8: .4byte 0x081031BD
	thumb_func_end sub_08103094

	thumb_func_start sub_081031BC
sub_081031BC: @ 0x081031BC
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x34]
	ldrh r1, [r2, #0x32]
	adds r0, r0, r1
	strh r0, [r2, #0x32]
	ldrh r1, [r2, #0x38]
	ldrh r3, [r2, #0x36]
	adds r1, r1, r3
	strh r1, [r2, #0x36]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x17
	strh r0, [r2, #0x20]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x17
	strh r1, [r2, #0x22]
	ldrh r0, [r2, #0x30]
	subs r0, #1
	strh r0, [r2, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _081031F2
	ldrh r0, [r2, #0x3a]
	strh r0, [r2, #0x20]
	ldrh r0, [r2, #0x3c]
	strh r0, [r2, #0x22]
_081031F2:
	movs r1, #0x30
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne _08103200
	adds r0, r2, #0
	bl DestroyAnimSprite
_08103200:
	pop {r0}
	bx r0
	thumb_func_end sub_081031BC

	thumb_func_start sub_08103204
sub_08103204: @ 0x08103204
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r0, r0, #2
	add r0, r8
	lsls r0, r0, #3
	ldr r1, _08103294
	adds r6, r0, r1
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r6, #8]
	ldr r0, _08103298
	bl AllocSpritePalette
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r6, #0xa]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	lsls r0, r0, #0x14
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r3, r0, #0x10
	ldr r2, _0810329C
	movs r0, #8
	ldrsh r1, [r6, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #5]
	lsrs r0, r0, #4
	adds r0, #0x10
	lsls r4, r0, #4
	movs r5, #1
	ldr r2, _081032A0
_0810325C:
	adds r1, r3, r5
	lsls r1, r1, #1
	adds r1, r1, r2
	adds r0, r4, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xf
	bls _0810325C
	adds r0, r3, #0
	movs r1, #0x10
	movs r2, #0xb
	movs r3, #0
	bl BlendPalette
	movs r0, #0
	strh r0, [r6, #0xe]
	movs r5, #0
	ldr r7, _0810329C
	movs r1, #0x1c
	adds r1, r1, r7
	mov sb, r1
	b _081032D8
	.align 2, 0
_08103294: .4byte 0x03005B60
_08103298: .4byte 0x00002771
_0810329C: .4byte 0x020205AC
_081032A0: .4byte 0x020373B4
_081032A4:
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r4, r2, r7
	ldrb r1, [r6, #0xa]
	lsls r1, r1, #4
	ldrb r3, [r4, #5]
	movs r0, #0xf
	ands r0, r3
	orrs r0, r1
	strb r0, [r4, #5]
	movs r0, #0
	strh r0, [r4, #0x2e]
	lsls r0, r5, #7
	strh r0, [r4, #0x30]
	mov r0, r8
	strh r0, [r4, #0x32]
	add r2, sb
	ldr r0, _0810330C
	str r0, [r2]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_081032D8:
	cmp r5, #1
	bhi _081032EA
	movs r0, #0
	bl CloneBattlerSpriteWithBlend
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _081032A4
_081032EA:
	ldr r0, _08103310
	str r0, [r6]
	ldr r0, _08103314
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08103318
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #0
	bl ClearGpuRegBits
	b _08103322
	.align 2, 0
_0810330C: .4byte 0x0810338D
_08103310: .4byte 0x08103331
_08103314: .4byte 0x020380D6
_08103318:
	movs r1, #0x80
	lsls r1, r1, #3
	movs r0, #0
	bl ClearGpuRegBits
_08103322:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08103204

	thumb_func_start sub_08103330
sub_08103330: @ 0x08103330
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r1, _08103364
	adds r0, r0, r1
	movs r1, #0xe
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08103382
	ldr r0, _08103368
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0810336C
	movs r1, #0x80
	lsls r1, r1, #2
	movs r0, #0
	bl SetGpuRegBits
	b _08103376
	.align 2, 0
_08103364: .4byte 0x03005B60
_08103368: .4byte 0x020380D6
_0810336C:
	movs r1, #0x80
	lsls r1, r1, #3
	movs r0, #0
	bl SetGpuRegBits
_08103376:
	ldr r0, _08103388
	bl FreeSpritePaletteByTag
	adds r0, r4, #0
	bl DestroyAnimVisualTask
_08103382:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08103388: .4byte 0x00002771
	thumb_func_end sub_08103330

	thumb_func_start sub_0810338C
sub_0810338C: @ 0x0810338C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0x34]
	adds r0, #1
	strh r0, [r5, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _081033A8
	movs r0, #0
	strh r0, [r5, #0x34]
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
_081033A8:
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	cmp r0, #0x40
	ble _081033D0
	ldr r2, _081033CC
	movs r0, #0x32
	ldrsh r1, [r5, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0, #0xe]
	subs r1, #1
	strh r1, [r0, #0xe]
	adds r0, r5, #0
	bl DestroySpriteWithActiveSheet
	b _08103412
	.align 2, 0
_081033CC: .4byte 0x03005B60
_081033D0:
	ldr r4, _08103418
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #6
	bl __divsi3
	strh r0, [r5, #0x36]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r1, #0xd
	bl __divsi3
	strh r0, [r5, #0x38]
	ldrh r1, [r5, #0x30]
	adds r1, r1, r0
	movs r0, #0xff
	ands r1, r0
	strh r1, [r5, #0x30]
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	movs r2, #0x36
	ldrsh r1, [r5, r2]
	bl Sin
	strh r0, [r5, #0x24]
_08103412:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08103418: .4byte 0x082FA8CC
	thumb_func_end sub_0810338C

	thumb_func_start sub_0810341C
sub_0810341C: @ 0x0810341C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08103430
	bl StoreSpriteCallbackInData6
	ldr r0, _08103434
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08103430: .4byte 0x080A34C5
_08103434: .4byte 0x080A60A1
	thumb_func_end sub_0810341C

	thumb_func_start sub_08103438
sub_08103438: @ 0x08103438
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r4, _081034E8
	ldrh r0, [r4]
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xff
	beq _0810347C
	lsls r0, r3, #0x14
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r3, r0, #0x10
	movs r2, #1
	ldr r5, _081034EC
_08103464:
	adds r1, r3, r2
	lsls r1, r1, #1
	adds r1, r1, r5
	lsls r0, r2, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #5
	bls _08103464
_0810347C:
	movs r4, #1
	ldr r0, _081034E8
	mov r8, r0
_08103482:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r5, r0, #2
	mov r1, r8
	adds r0, r5, r1
	ldrh r0, [r0]
	bl AllocSpritePalette
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r4, #1
	mov ip, r4
	cmp r3, #0xff
	beq _081034CA
	lsls r0, r3, #0x14
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r3, r0, #0x10
	movs r2, #1
	ldr r7, _081034EC
	ldr r6, _081034E8
	adds r4, r5, #0
_081034B0:
	adds r1, r3, r2
	lsls r1, r1, #1
	adds r1, r1, r7
	lsls r0, r2, #1
	adds r0, r0, r4
	adds r0, r0, r6
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #5
	bls _081034B0
_081034CA:
	mov r1, ip
	lsls r0, r1, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #3
	bls _08103482
	mov r0, sb
	bl DestroyAnimVisualTask
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081034E8: .4byte 0x0856EC04
_081034EC: .4byte 0x020377B4
	thumb_func_end sub_08103438

	thumb_func_start sub_081034F0
sub_081034F0: @ 0x081034F0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #1
	ldr r6, _08103520
_081034FA:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrh r0, [r0]
	bl FreeSpritePaletteByTag
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #3
	bls _081034FA
	adds r0, r5, #0
	bl DestroyAnimVisualTask
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08103520: .4byte 0x0856EC04
	thumb_func_end sub_081034F0

	thumb_func_start sub_08103524
sub_08103524: @ 0x08103524
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	bl SetSpriteCoordsToAnimAttackerCoords
	ldr r4, _0810357C
	ldrb r1, [r4]
	adds r0, r5, #0
	bl StartSpriteAnim
	ldr r2, _08103580
	movs r0, #2
	ldrsh r1, [r4, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _08103560
	lsls r2, r0, #4
	ldrb r1, [r5, #5]
	movs r0, #0xf
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, #5]
_08103560:
	ldrh r0, [r4, #2]
	movs r1, #0
	strh r0, [r5, #0x30]
	strh r1, [r5, #0x32]
	ldrh r0, [r4, #4]
	strh r0, [r5, #0x34]
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08103584
	movs r6, #0x30
	movs r3, #0x28
	b _0810359E
	.align 2, 0
_0810357C: .4byte 0x020380BE
_08103580: .4byte 0x0856EC04
_08103584:
	ldr r4, _081035D4
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_0810359E:
	ldrh r0, [r5, #0x20]
	lsls r1, r0, #4
	strh r1, [r5, #0x36]
	ldrh r1, [r5, #0x22]
	lsls r2, r1, #4
	strh r2, [r5, #0x38]
	subs r0, r6, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	subs r1, r3, r1
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, r5, #0
	adds r2, #0x3a
	adds r3, r5, #0
	adds r3, #0x3c
	movs r4, #0x28
	str r4, [sp]
	bl sub_081035DC
	ldr r0, _081035D8
	str r0, [r5, #0x1c]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081035D4: .4byte 0x020380D7
_081035D8: .4byte 0x08103635
	thumb_func_end sub_08103524

	thumb_func_start sub_081035DC
sub_081035DC: @ 0x081035DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r2, #0
	mov r8, r3
	ldr r2, [sp, #0x18]
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r1, r2, #0x18
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	bge _081035FE
	lsls r0, r1, #0x18
	rsbs r0, r0, #0
	lsrs r1, r0, #0x18
_081035FE:
	lsls r5, r2, #8
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	adds r0, r5, #0
	bl __divsi3
	adds r4, r0, #0
	cmp r4, #0
	bne _08103612
	movs r4, #1
_08103612:
	adds r0, r5, #0
	adds r1, r4, #0
	bl __divsi3
	strh r0, [r7]
	lsls r0, r6, #0x10
	asrs r0, r0, #8
	adds r1, r4, #0
	bl __divsi3
	mov r1, r8
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_081035DC

	thumb_func_start sub_08103634
sub_08103634: @ 0x08103634
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	movs r5, #0
	strh r0, [r4, #0x2e]
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	lsls r0, r1, #2
	adds r1, r0, r1
	adds r0, r1, #0
	cmp r1, #0
	bge _08103650
	adds r0, #0xff
_08103650:
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	ldrh r1, [r4, #0x3a]
	ldrh r2, [r4, #0x36]
	adds r1, r1, r2
	strh r1, [r4, #0x36]
	ldrh r2, [r4, #0x3c]
	ldrh r3, [r4, #0x38]
	adds r2, r2, r3
	strh r2, [r4, #0x38]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	strh r1, [r4, #0x20]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x14
	strh r2, [r4, #0x22]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xf
	bl Sin
	strh r0, [r4, #0x26]
	ldrh r2, [r4, #0x22]
	ldrh r0, [r4, #0x20]
	adds r0, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0810369E
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	blt _0810369E
	cmp r1, #0x80
	ble _081036A6
_0810369E:
	adds r0, r4, #0
	bl DestroySpriteAndMatrix
	b _081036F6
_081036A6:
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	cmp r1, #0
	beq _081036F6
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r1
	ble _081036F6
	strh r5, [r4, #0x32]
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _081036CE
	strh r5, [r4, #0x30]
_081036CE:
	ldr r2, _081036FC
	movs r3, #0x30
	ldrsh r1, [r4, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _081036F6
	lsls r2, r0, #4
	ldrb r1, [r4, #5]
	movs r0, #0xf
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, #5]
_081036F6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081036FC: .4byte 0x0856EC04
	thumb_func_end sub_08103634

	thumb_func_start sub_08103700
sub_08103700: @ 0x08103700
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, _08103784
	ldrb r0, [r7]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0810371E
	ldr r1, _08103788
	movs r2, #2
	ldrsh r0, [r1, r2]
	rsbs r0, r0, #0
	strh r0, [r1, #2]
_0810371E:
	ldrb r0, [r7]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	ldr r4, _08103788
	lsrs r0, r0, #0x18
	ldrh r1, [r4, #2]
	adds r0, r0, r1
	movs r5, #0
	strh r0, [r6, #0x20]
	ldrb r0, [r7]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r2, [r4, #4]
	adds r0, r0, r2
	strh r0, [r6, #0x22]
	ldrb r1, [r4]
	adds r0, r6, #0
	bl StartSpriteAnim
	strh r5, [r6, #0x32]
	strh r5, [r6, #0x34]
	ldrh r0, [r6, #0x20]
	lsls r0, r0, #4
	strh r0, [r6, #0x36]
	ldrh r0, [r6, #0x22]
	lsls r0, r0, #4
	strh r0, [r6, #0x38]
	movs r1, #2
	ldrsh r0, [r4, r1]
	lsls r0, r0, #4
	movs r1, #5
	bl __divsi3
	strh r0, [r6, #0x3a]
	movs r2, #4
	ldrsh r0, [r4, r2]
	lsls r0, r0, #7
	movs r1, #5
	bl __divsi3
	strh r0, [r6, #0x3c]
	ldr r0, _0810378C
	str r0, [r6, #0x1c]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08103784: .4byte 0x020380D6
_08103788: .4byte 0x020380BE
_0810378C: .4byte 0x08103791
	thumb_func_end sub_08103700

	thumb_func_start sub_08103790
sub_08103790: @ 0x08103790
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x3a]
	ldrh r1, [r4, #0x36]
	adds r0, r0, r1
	strh r0, [r4, #0x36]
	ldrh r1, [r4, #0x3c]
	ldrh r2, [r4, #0x38]
	adds r1, r1, r2
	strh r1, [r4, #0x38]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r4, #0x20]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	strh r1, [r4, #0x22]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #5
	ble _081037EE
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _081037EE
	ldrh r0, [r4, #0x32]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x32]
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	movs r1, #0x12
	bl Cos
	strh r0, [r4, #0x24]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	movs r1, #0x12
	bl Sin
	strh r0, [r4, #0x26]
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _081037EE
	movs r0, #1
	strh r0, [r4, #0x34]
_081037EE:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x30
	bne _08103802
	adds r0, r4, #0
	bl DestroySpriteAndMatrix
_08103802:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_08103790

	thumb_func_start sub_08103808
sub_08103808: @ 0x08103808
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08103828
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne _0810382C
	ldrb r0, [r5, #3]
	movs r1, #0x3f
	rsbs r1, r1, #0
	ands r1, r0
	movs r0, #0x10
	orrs r1, r0
	strb r1, [r5, #3]
	movs r6, #0x10
	b _0810382E
	.align 2, 0
_08103828: .4byte 0x020380BE
_0810382C:
	ldr r6, _08103868
_0810382E:
	ldr r4, _0810386C
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r6
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #8
	strh r0, [r5, #0x22]
	movs r0, #8
	strh r0, [r5, #0x2e]
	ldr r0, _08103870
	str r0, [r5, #0x1c]
	ldr r1, _08103874
	adds r0, r5, #0
	bl StoreSpriteCallbackInData6
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08103868: .4byte 0x0000FFF0
_0810386C: .4byte 0x020380D6
_08103870: .4byte 0x080A5D79
_08103874: .4byte 0x080A34C5
	thumb_func_end sub_08103808

	thumb_func_start sub_08103878
sub_08103878: @ 0x08103878
	push {r4, r5, lr}
	adds r4, r0, #0
	bl SetSpriteCoordsToAnimAttackerCoords
	ldrh r0, [r4, #0x22]
	adds r0, #8
	strh r0, [r4, #0x22]
	ldr r5, _081038F0
	ldrb r1, [r5, #2]
	adds r0, r4, #0
	bl StartSpriteAnim
	ldr r2, _081038F4
	movs r0, #4
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _081038B8
	lsls r2, r0, #4
	ldrb r1, [r4, #5]
	movs r0, #0xf
	ands r0, r1
	orrs r0, r2
	strb r0, [r4, #5]
_081038B8:
	movs r1, #0
	ldrsh r0, [r5, r1]
	movs r2, #0x20
	cmp r0, #0
	bne _081038C4
	ldr r2, _081038F8
_081038C4:
	movs r0, #0x28
	strh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x20]
	strh r1, [r4, #0x30]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r1
	strh r0, [r4, #0x32]
	ldrh r0, [r4, #0x22]
	strh r0, [r4, #0x34]
	subs r0, #0x28
	strh r0, [r4, #0x36]
	adds r0, r4, #0
	bl InitAnimLinearTranslation
	ldrh r0, [r5, #6]
	strh r0, [r4, #0x38]
	ldr r0, _081038FC
	str r0, [r4, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081038F0: .4byte 0x020380BE
_081038F4: .4byte 0x0856EC04
_081038F8: .4byte 0x0000FFE0
_081038FC: .4byte 0x08103901
	thumb_func_end sub_08103878

	thumb_func_start sub_08103900
sub_08103900: @ 0x08103900
	push {r4, lr}
	adds r4, r0, #0
	bl AnimTranslateLinear
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08103950
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	movs r1, #8
	bl Sin
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldrh r2, [r4, #0x24]
	movs r3, #0x24
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bge _0810392C
	lsls r0, r1, #0x10
	rsbs r0, r0, #0
	lsrs r1, r0, #0x10
_0810392C:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	adds r0, r0, r2
	strh r0, [r4, #0x24]
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	movs r1, #4
	bl Sin
	ldrh r3, [r4, #0x26]
	adds r0, r0, r3
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x38]
	adds r0, #8
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x38]
	b _08103956
_08103950:
	adds r0, r4, #0
	bl DestroyAnimSprite
_08103956:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_08103900

	thumb_func_start SetSpriteNextToMonHead
SetSpriteNextToMonHead: @ 0x0810395C
	push {r4, r5, r6, lr}
	adds r6, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r5, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0810397C
	adds r0, r5, #0
	movs r1, #5
	bl GetBattlerSpriteCoordAttr
	adds r0, #8
	b _08103986
_0810397C:
	adds r0, r5, #0
	movs r1, #4
	bl GetBattlerSpriteCoordAttr
	subs r0, #8
_08103986:
	strh r0, [r6, #0x20]
	adds r0, r5, #0
	movs r1, #3
	bl GetBattlerSpriteCoord
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl GetBattlerSpriteCoordAttr
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _081039A8
	adds r0, #3
_081039A8:
	asrs r0, r0, #2
	subs r0, r4, r0
	strh r0, [r6, #0x22]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end SetSpriteNextToMonHead

	thumb_func_start sub_081039B4
sub_081039B4: @ 0x081039B4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081039C8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081039D0
	ldr r0, _081039CC
	b _081039D2
	.align 2, 0
_081039C8: .4byte 0x020380BE
_081039CC: .4byte 0x020380D6
_081039D0:
	ldr r0, _08103A10
_081039D2:
	ldrb r4, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetSpriteNextToMonHead
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r1, r1, #0x1f
	ldr r0, _08103A14
	ldrh r0, [r0, #2]
	strh r0, [r5, #0x2e]
	adds r0, r1, #2
	strh r0, [r5, #0x30]
	adds r0, r5, #0
	bl StartSpriteAnim
	ldr r1, _08103A18
	adds r0, r5, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _08103A1C
	str r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08103A10: .4byte 0x020380D7
_08103A14: .4byte 0x020380BE
_08103A18: .4byte 0x08103A21
_08103A1C: .4byte 0x080A60A1
	thumb_func_end sub_081039B4

	thumb_func_start sub_08103A20
sub_08103A20: @ 0x08103A20
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	subs r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08103A48
	ldr r1, _08103A50
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldrh r1, [r4, #0x30]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
	ldr r0, _08103A54
	str r0, [r4, #0x1c]
_08103A48:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08103A50: .4byte 0x080A34C5
_08103A54: .4byte 0x080A60A1
	thumb_func_end sub_08103A20

	thumb_func_start sub_08103A58
sub_08103A58: @ 0x08103A58
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08103A6C
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08103A74
	ldr r0, _08103A70
	b _08103A76
	.align 2, 0
_08103A6C: .4byte 0x020380BE
_08103A70: .4byte 0x020380D6
_08103A74:
	ldr r0, _08103A94
_08103A76:
	ldrb r0, [r0]
	adds r1, r4, #0
	bl SetSpriteNextToMonHead
	movs r0, #0
	strh r0, [r4, #0x2e]
	ldr r1, _08103A98
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _08103A9C
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08103A94: .4byte 0x020380D7
_08103A98: .4byte 0x08103AA1
_08103A9C: .4byte 0x080A6085
	thumb_func_end sub_08103A58

	thumb_func_start sub_08103AA0
sub_08103AA0: @ 0x08103AA0
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x10
	ble _08103AC6
	adds r0, r4, #0
	movs r1, #1
	bl StartSpriteAffineAnim
	ldr r1, _08103ACC
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _08103AD0
	str r0, [r4, #0x1c]
_08103AC6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08103ACC: .4byte 0x080A6015
_08103AD0: .4byte 0x080A6085
	thumb_func_end sub_08103AA0

	thumb_func_start sub_08103AD4
sub_08103AD4: @ 0x08103AD4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08103AE8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08103AF0
	ldr r0, _08103AEC
	b _08103AF2
	.align 2, 0
_08103AE8: .4byte 0x020380BE
_08103AEC: .4byte 0x020380D6
_08103AF0:
	ldr r0, _08103B44
_08103AF2:
	ldrb r5, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r6, #0
	strh r0, [r4, #0x20]
	adds r0, r5, #0
	movs r1, #2
	bl GetBattlerSpriteCoordAttr
	strh r0, [r4, #0x22]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bgt _08103B1A
	movs r0, #0xa
	strh r0, [r4, #0x22]
_08103B1A:
	movs r0, #1
	strh r0, [r4, #0x2e]
	strh r6, [r4, #0x30]
	adds r1, r4, #0
	adds r1, #0x43
	ldrb r0, [r1]
	strh r0, [r4, #0x32]
	ldrb r0, [r1]
	adds r0, #4
	strh r0, [r4, #0x34]
	strh r6, [r4, #0x36]
	ldr r1, _08103B48
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _08103B4C
	str r0, [r4, #0x1c]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08103B44: .4byte 0x020380D7
_08103B48: .4byte 0x08103B51
_08103B4C: .4byte 0x080A6085
	thumb_func_end sub_08103AD4

	thumb_func_start sub_08103B50
sub_08103B50: @ 0x08103B50
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x36]
	adds r0, #1
	strh r0, [r1, #0x36]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble _08103B66
	ldr r0, _08103B6C
	str r0, [r1, #0x1c]
_08103B66:
	pop {r0}
	bx r0
	.align 2, 0
_08103B6C: .4byte 0x08103B71
	thumb_func_end sub_08103B50

	thumb_func_start sub_08103B70
sub_08103B70: @ 0x08103B70
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x30]
	adds r1, r0, #4
	strh r1, [r2, #0x30]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xfe
	ble _08103BA2
	ldrh r0, [r2, #0x2e]
	subs r0, #1
	strh r0, [r2, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08103B9C
	strh r0, [r2, #0x24]
	ldr r0, _08103B98
	str r0, [r2, #0x1c]
	b _08103BD8
	.align 2, 0
_08103B98: .4byte 0x08103AA1
_08103B9C:
	movs r0, #0xff
	ands r1, r0
	strh r1, [r2, #0x30]
_08103BA2:
	movs r1, #0x30
	ldrsh r0, [r2, r1]
	cmp r0, #0x4f
	ble _08103BB2
	ldrh r0, [r2, #0x34]
	adds r1, r2, #0
	adds r1, #0x43
	strb r0, [r1]
_08103BB2:
	movs r3, #0x30
	ldrsh r0, [r2, r3]
	cmp r0, #0x9f
	ble _08103BC2
	ldrh r0, [r2, #0x32]
	adds r1, r2, #0
	adds r1, #0x43
	strb r0, [r1]
_08103BC2:
	ldr r1, _08103BDC
	movs r3, #0x30
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	asrs r1, r0, #1
	adds r0, r0, r1
	strh r0, [r2, #0x24]
_08103BD8:
	pop {r0}
	bx r0
	.align 2, 0
_08103BDC: .4byte 0x082FA8CC
	thumb_func_end sub_08103B70

	thumb_func_start sub_08103BE0
sub_08103BE0: @ 0x08103BE0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08103BF4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _08103BFC
	ldr r0, _08103BF8
	b _08103BFE
	.align 2, 0
_08103BF4: .4byte 0x020380BE
_08103BF8: .4byte 0x020380D6
_08103BFC:
	ldr r0, _08103C20
_08103BFE:
	ldrb r4, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl SetSpriteNextToMonHead
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08103C24
	adds r0, r5, #0
	movs r1, #0
	bl StartSpriteAnim
	movs r0, #2
	b _08103C2E
	.align 2, 0
_08103C20: .4byte 0x020380D7
_08103C24:
	adds r0, r5, #0
	movs r1, #1
	bl StartSpriteAnim
	movs r0, #3
_08103C2E:
	strh r0, [r5, #0x2e]
	ldr r0, _08103C3C
	str r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08103C3C: .4byte 0x08103C41
	thumb_func_end sub_08103BE0

	thumb_func_start sub_08103C40
sub_08103C40: @ 0x08103C40
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	ble _08103C6E
	movs r0, #0
	strh r0, [r4, #0x30]
	ldrh r1, [r4, #0x2e]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
	ldr r1, _08103C74
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _08103C78
	str r0, [r4, #0x1c]
_08103C6E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08103C74: .4byte 0x08103C7D
_08103C78: .4byte 0x080A60A1
	thumb_func_end sub_08103C40

	thumb_func_start sub_08103C7C
sub_08103C7C: @ 0x08103C7C
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x30]
	adds r0, #1
	strh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _08103C94
	adds r0, r1, #0
	bl DestroyAnimSprite
_08103C94:
	pop {r0}
	bx r0
	thumb_func_end sub_08103C7C
