.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_080B8AE8
sub_080B8AE8: @ 0x080B8AE8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0xc]
	adds r0, #1
	strh r0, [r5, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _080B8B5E
	ldr r0, _080B8B64
	ldrb r1, [r0, #5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080B8B68
	adds r4, r0, r1
	movs r0, #3
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ObjectEventSetGraphicsId
	ldrb r1, [r4, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r6, _080B8B6C
	adds r0, r0, r6
	movs r1, #0x16
	bl StartSpriteAnim
	ldrb r0, [r4, #1]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #1]
	adds r0, r4, #0
	movs r1, #0x48
	bl ObjectEventSetHeldMovement
	ldrh r1, [r5, #0x26]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080B8B54
	ldrb r1, [r4, #0x1a]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	bl DestroySprite
_080B8B54:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	movs r0, #0
	strh r0, [r5, #0xc]
_080B8B5E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B8B64: .4byte 0x02037230
_080B8B68: .4byte 0x02036FF0
_080B8B6C: .4byte 0x020205AC
	thumb_func_end sub_080B8AE8

	thumb_func_start sub_080B8B70
sub_080B8B70: @ 0x080B8B70
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0xc]
	adds r0, #1
	strh r0, [r5, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _080B8BBC
	ldr r0, _080B8BC4
	ldrb r0, [r0, #5]
	lsls r4, r0, #3
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080B8BC8
	adds r4, r4, r0
	adds r0, r4, #0
	bl ObjectEventClearHeldMovementIfActive
	ldrb r1, [r4, #1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #1]
	ldrb r1, [r4, #2]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #2]
	ldrb r0, [r5, #0xa]
	ldrb r1, [r4, #4]
	bl sub_080B8CB8
	bl CameraObjectReset2
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
_080B8BBC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B8BC4: .4byte 0x02037230
_080B8BC8: .4byte 0x02036FF0
	thumb_func_end sub_080B8B70

	thumb_func_start sub_080B8BCC
sub_080B8BCC: @ 0x080B8BCC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xa]
	bl sub_080B8C60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B8BE6
	bl WarpFadeOutScreen
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
_080B8BE6:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_080B8BCC

	thumb_func_start sub_080B8BEC
sub_080B8BEC: @ 0x080B8BEC
	push {lr}
	ldr r0, _080B8C14
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _080B8C0E
	movs r0, #0x1f
	bl FieldEffectActiveListRemove
	ldr r0, _080B8C18
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl DestroyTask
_080B8C0E:
	pop {r0}
	bx r0
	.align 2, 0
_080B8C14: .4byte 0x02037C74
_080B8C18: .4byte 0x080B892D
	thumb_func_end sub_080B8BEC

	thumb_func_start sub_080B8C1C
sub_080B8C1C: @ 0x080B8C1C
	push {lr}
	ldr r0, _080B8C54
	ldr r0, [r0, #0x68]
	movs r1, #0xff
	movs r2, #0xb4
	movs r3, #1
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	ldr r1, _080B8C58
	adds r2, r2, r1
	ldrb r3, [r2, #5]
	movs r1, #0xf
	ands r1, r3
	movs r3, #0xd
	rsbs r3, r3, #0
	ands r1, r3
	movs r3, #4
	orrs r1, r3
	strb r1, [r2, #5]
	ldr r1, _080B8C5C
	str r1, [r2, #0x1c]
	pop {r1}
	bx r1
	.align 2, 0
_080B8C54: .4byte 0x084DDE4C
_080B8C58: .4byte 0x020205AC
_080B8C5C: .4byte 0x080B8CD5
	thumb_func_end sub_080B8C1C

	thumb_func_start sub_080B8C60
sub_080B8C60: @ 0x080B8C60
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080B8C78
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r0, [r1, #0x3c]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bx lr
	.align 2, 0
_080B8C78: .4byte 0x020205AC
	thumb_func_end sub_080B8C60

	thumb_func_start sub_080B8C7C
sub_080B8C7C: @ 0x080B8C7C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080B8CB0
	adds r4, r4, r0
	ldr r0, _080B8CB4
	str r0, [r4, #0x1c]
	movs r1, #0
	movs r0, #0x78
	strh r0, [r4, #0x20]
	strh r1, [r4, #0x22]
	strh r1, [r4, #0x24]
	strh r1, [r4, #0x26]
	adds r0, r4, #0
	adds r0, #0x2e
	movs r2, #0x10
	bl memset
	movs r0, #0x40
	strh r0, [r4, #0x3a]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8CB0: .4byte 0x020205AC
_080B8CB4: .4byte 0x080B8D95
	thumb_func_end sub_080B8C7C

	thumb_func_start sub_080B8CB8
sub_080B8CB8: @ 0x080B8CB8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _080B8CD0
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r3
	strh r1, [r2, #0x3a]
	bx lr
	.align 2, 0
_080B8CD0: .4byte 0x020205AC
	thumb_func_end sub_080B8CB8

	thumb_func_start sub_080B8CD4
sub_080B8CD4: @ 0x080B8CD4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _080B8D80
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _080B8D18
	ldrb r0, [r4, #1]
	movs r1, #3
	orrs r0, r1
	strb r0, [r4, #1]
	ldr r0, _080B8D88
	str r0, [r4, #0x10]
	adds r0, r4, #0
	bl InitSpriteAffineAnim
	adds r0, r4, #0
	movs r1, #0
	bl StartSpriteAffineAnim
	movs r0, #0x76
	strh r0, [r4, #0x20]
	ldr r0, _080B8D8C
	strh r0, [r4, #0x22]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	movs r0, #0x40
	strh r0, [r4, #0x30]
	adds r0, #0xc0
	strh r0, [r4, #0x32]
_080B8D18:
	ldrh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldrh r1, [r4, #0x30]
	adds r0, r0, r1
	strh r0, [r4, #0x30]
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	movs r1, #0x78
	bl Cos
	strh r0, [r4, #0x24]
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	movs r1, #0x78
	bl Sin
	strh r0, [r4, #0x26]
	ldrh r2, [r4, #0x32]
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	ldr r0, _080B8D90
	cmp r1, r0
	bgt _080B8D4E
	adds r0, r2, #0
	adds r0, #0x60
	strh r0, [r4, #0x32]
_080B8D4E:
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	cmp r0, #0x81
	ble _080B8D80
	ldrh r0, [r4, #0x3c]
	adds r0, #1
	strh r0, [r4, #0x3c]
	ldrb r1, [r4, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #1]
	ldrb r0, [r4, #3]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1b
	bl FreeOamMatrix
	ldrb r1, [r4, #1]
	lsrs r1, r1, #6
	ldrb r2, [r4, #3]
	lsrs r2, r2, #6
	adds r0, r4, #0
	movs r3, #0
	bl CalcCenterToCornerVec
_080B8D80:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8D88: .4byte 0x085371F4
_080B8D8C: .4byte 0x0000FFD0
_080B8D90: .4byte 0x000007FF
	thumb_func_end sub_080B8CD4

	thumb_func_start sub_080B8D94
sub_080B8D94: @ 0x080B8D94
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	movs r1, #0x8c
	bl Cos
	movs r5, #0
	strh r0, [r4, #0x24]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	movs r1, #0x48
	bl Sin
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x32]
	adds r0, #4
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x32]
	movs r1, #0x3a
	ldrsh r0, [r4, r1]
	cmp r0, #0x40
	beq _080B8DF2
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _080B8E04
	adds r1, r1, r0
	adds r3, r1, #0
	adds r3, #0x3e
	ldrb r2, [r3]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r3]
	ldrh r0, [r4, #0x24]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r1, #0x20]
	ldrh r0, [r4, #0x26]
	ldrh r2, [r4, #0x22]
	adds r0, r0, r2
	subs r0, #8
	strh r0, [r1, #0x22]
	strh r5, [r1, #0x24]
	strh r5, [r1, #0x26]
_080B8DF2:
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0x7f
	ble _080B8DFE
	movs r0, #1
	strh r0, [r4, #0x3c]
_080B8DFE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B8E04: .4byte 0x020205AC
	thumb_func_end sub_080B8D94

	thumb_func_start sub_080B8E08
sub_080B8E08: @ 0x080B8E08
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _080B8EDC
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _080B8E52
	ldrb r0, [r4, #1]
	movs r1, #3
	orrs r0, r1
	strb r0, [r4, #1]
	ldr r0, _080B8EE4
	str r0, [r4, #0x10]
	adds r0, r4, #0
	bl InitSpriteAffineAnim
	adds r0, r4, #0
	movs r1, #1
	bl StartSpriteAffineAnim
	movs r0, #0x5e
	strh r0, [r4, #0x20]
	ldr r0, _080B8EE8
	strh r0, [r4, #0x22]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	movs r0, #0xf0
	strh r0, [r4, #0x30]
	movs r0, #0x80
	lsls r0, r0, #4
	strh r0, [r4, #0x32]
	movs r0, #0x80
	strh r0, [r4, #0x36]
_080B8E52:
	ldrh r1, [r4, #0x32]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	ldrh r2, [r4, #0x30]
	adds r2, r2, r1
	ldrh r0, [r4, #0x34]
	adds r0, r0, r1
	strh r0, [r4, #0x34]
	movs r0, #0xff
	ands r2, r0
	strh r2, [r4, #0x30]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	movs r1, #0x20
	bl Cos
	strh r0, [r4, #0x24]
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	movs r1, #0x78
	bl Sin
	strh r0, [r4, #0x26]
	ldrh r1, [r4, #0x32]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r0, r2
	ble _080B8E94
	ldrh r0, [r4, #0x36]
	subs r0, r1, r0
	strh r0, [r4, #0x32]
_080B8E94:
	ldrh r1, [r4, #0x36]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	cmp r0, #0xff
	bgt _080B8EA4
	adds r0, r1, #0
	adds r0, #0x18
	strh r0, [r4, #0x36]
_080B8EA4:
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0xff
	bgt _080B8EAE
	strh r2, [r4, #0x32]
_080B8EAE:
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	cmp r0, #0x3b
	ble _080B8EDC
	ldrh r0, [r4, #0x3c]
	adds r0, #1
	strh r0, [r4, #0x3c]
	ldrb r1, [r4, #1]
	movs r0, #4
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #1]
	ldrb r0, [r4, #3]
	lsls r0, r0, #0x1a
	lsrs r0, r0, #0x1b
	bl FreeOamMatrix
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
_080B8EDC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8EE4: .4byte 0x085371F4
_080B8EE8: .4byte 0x0000FFE0
	thumb_func_end sub_080B8E08

	thumb_func_start sub_080B8EEC
sub_080B8EEC: @ 0x080B8EEC
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl sub_080B8C7C
	ldr r1, _080B8F10
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r1, _080B8F14
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B8F10: .4byte 0x020205AC
_080B8F14: .4byte 0x080B8E09
	thumb_func_end sub_080B8EEC

	thumb_func_start sub_080B8F18
sub_080B8F18: @ 0x080B8F18
	push {lr}
	ldr r0, _080B8F28
	movs r1, #0xfe
	bl CreateTask
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_080B8F28: .4byte 0x080B8F2D
	thumb_func_end sub_080B8F18

	thumb_func_start sub_080B8F2C
sub_080B8F2C: @ 0x080B8F2C
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r3, _080B8F54
	ldr r2, _080B8F58
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r2, #8
	ldrsh r1, [r0, r2]
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080B8F54: .4byte 0x085371FC
_080B8F58: .4byte 0x03005B60
	thumb_func_end sub_080B8F2C

	thumb_func_start sub_080B8F5C
sub_080B8F5C: @ 0x080B8F5C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r6, _080B9004
	ldrb r1, [r6, #5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080B9008
	adds r4, r0, r1
	adds r0, r4, #0
	bl ObjectEventIsMovementOverridden
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B8F86
	adds r0, r4, #0
	bl ObjectEventClearHeldMovementIfFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B8FFE
_080B8F86:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	movs r0, #0x11
	strh r0, [r5, #0xc]
	ldrb r0, [r6]
	strh r0, [r5, #0x26]
	movs r0, #1
	strb r0, [r6, #6]
	bl SetPlayerAvatarStateMask
	ldrh r1, [r5, #0x26]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080B8FAE
	ldrb r0, [r4, #0x1a]
	movs r1, #0
	bl SetSurfBlob_BobState
_080B8FAE:
	movs r0, #3
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ObjectEventSetGraphicsId
	bl CameraObjectReset2
	adds r0, r4, #0
	movs r1, #3
	bl EventObjectTurn
	ldrb r1, [r4, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080B900C
	adds r0, r0, r1
	movs r1, #0x16
	bl StartSpriteAnim
	ldrb r1, [r4, #1]
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #1]
	bl sub_080B8C1C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0xa]
	bl sub_080B8C7C
	ldrb r0, [r5, #0xa]
	ldrb r1, [r4, #4]
	bl sub_080B8CB8
_080B8FFE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B9004: .4byte 0x02037230
_080B9008: .4byte 0x02036FF0
_080B900C: .4byte 0x020205AC
	thumb_func_end sub_080B8F5C

	thumb_func_start sub_080B9010
sub_080B9010: @ 0x080B9010
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r1, [r5, #0xc]
	movs r2, #0xc
	ldrsh r0, [r5, r2]
	cmp r0, #0
	beq _080B9028
	subs r0, r1, #1
	strh r0, [r5, #0xc]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080B9068
_080B9028:
	ldr r0, _080B9070
	ldrb r1, [r0, #5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080B9074
	adds r0, r0, r1
	ldrb r0, [r0, #4]
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080B9078
	adds r4, r4, r0
	ldrb r0, [r5, #0xa]
	movs r1, #0x40
	bl sub_080B8CB8
	ldrh r0, [r4, #0x24]
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r4, #0x20]
	ldrh r0, [r4, #0x26]
	ldrh r2, [r4, #0x22]
	adds r0, r0, r2
	strh r0, [r4, #0x22]
	strh r1, [r4, #0x24]
	strh r1, [r4, #0x26]
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	strh r1, [r5, #0xc]
_080B9068:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B9070: .4byte 0x02037230
_080B9074: .4byte 0x02036FF0
_080B9078: .4byte 0x020205AC
	thumb_func_end sub_080B9010

	thumb_func_start sub_080B907C
sub_080B907C: @ 0x080B907C
	push {r4, lr}
	sub sp, #0x24
	adds r4, r0, #0
	ldr r1, _080B90C4
	mov r0, sp
	movs r2, #0x24
	bl memcpy
	ldr r0, _080B90C8
	ldrb r0, [r0, #4]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _080B90CC
	adds r1, r1, r0
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r1, #0x26]
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	ble _080B90BA
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
_080B90BA:
	add sp, #0x24
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B90C4: .4byte 0x08537218
_080B90C8: .4byte 0x02037230
_080B90CC: .4byte 0x020205AC
	thumb_func_end sub_080B907C

	thumb_func_start sub_080B90D0
sub_080B90D0: @ 0x080B90D0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6, #0xa]
	bl sub_080B8C60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B9134
	ldr r0, _080B913C
	ldrb r0, [r0, #5]
	lsls r5, r0, #3
	adds r5, r5, r0
	lsls r5, r5, #2
	ldr r0, _080B9140
	adds r5, r5, r0
	ldrb r0, [r5, #4]
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080B9144
	adds r4, r4, r0
	ldrb r1, [r5, #1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r5, #1]
	movs r0, #0x10
	ldrsh r1, [r5, r0]
	movs r0, #0x12
	ldrsh r2, [r5, r0]
	adds r0, r5, #0
	bl MoveEventObjectToMapCoords
	movs r0, #0
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x26]
	adds r4, #0x3e
	ldrb r0, [r4]
	movs r1, #2
	orrs r0, r1
	strb r0, [r4]
	bl SetPlayerAvatarFieldMove
	adds r0, r5, #0
	movs r1, #0x39
	bl ObjectEventSetHeldMovement
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
_080B9134:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B913C: .4byte 0x02037230
_080B9140: .4byte 0x02036FF0
_080B9144: .4byte 0x020205AC
	thumb_func_end sub_080B90D0

	thumb_func_start sub_080B9148
sub_080B9148: @ 0x080B9148
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B9178
	ldrb r1, [r0, #5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080B917C
	adds r0, r0, r1
	bl ObjectEventClearHeldMovementIfFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B9170
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ldrb r0, [r4, #0xa]
	bl sub_080B8EEC
_080B9170:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B9178: .4byte 0x02037230
_080B917C: .4byte 0x02036FF0
	thumb_func_end sub_080B9148

	thumb_func_start sub_080B9180
sub_080B9180: @ 0x080B9180
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0xa]
	bl sub_080B8C60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B91AC
	movs r0, #0xa
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080B91B4
	adds r0, r0, r1
	bl DestroySprite
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	movs r0, #0x10
	strh r0, [r4, #0xa]
_080B91AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B91B4: .4byte 0x020205AC
	thumb_func_end sub_080B9180

	thumb_func_start sub_080B91B8
sub_080B91B8: @ 0x080B91B8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldrh r0, [r5, #0xa]
	subs r0, #1
	strh r0, [r5, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080B9222
	ldr r6, _080B9228
	ldrb r1, [r6, #5]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080B922C
	adds r4, r0, r1
	movs r7, #0
	ldrh r1, [r5, #0x26]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080B91EC
	movs r7, #3
	ldrb r0, [r4, #0x1a]
	movs r1, #1
	bl SetSurfBlob_BobState
_080B91EC:
	adds r0, r7, #0
	bl GetPlayerAvatarGraphicsIdByStateId
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl ObjectEventSetGraphicsId
	adds r0, r4, #0
	movs r1, #1
	bl EventObjectTurn
	ldrh r0, [r5, #0x26]
	strb r0, [r6]
	movs r0, #0
	strb r0, [r6, #6]
	movs r0, #0x20
	bl FieldEffectActiveListRemove
	ldr r0, _080B9230
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl DestroyTask
_080B9222:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9228: .4byte 0x02037230
_080B922C: .4byte 0x02036FF0
_080B9230: .4byte 0x080B8F2D
	thumb_func_end sub_080B91B8

	thumb_func_start sub_080B9234
sub_080B9234: @ 0x080B9234
	push {r4, lr}
	sub sp, #4
	ldr r4, _080B9278
	ldrb r0, [r4]
	ldrb r1, [r4, #4]
	ldrb r2, [r4, #8]
	mov r3, sp
	bl TryGetObjectEventIdByLocalIdAndMap
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B9284
	ldr r0, _080B927C
	movs r1, #0x50
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080B9280
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r1, #0xc]
	ldr r0, [r4]
	strh r0, [r1, #0x14]
	ldr r0, [r4, #4]
	strh r0, [r1, #0x16]
	ldr r0, [r4, #8]
	strh r0, [r1, #0x18]
	b _080B928A
	.align 2, 0
_080B9278: .4byte 0x020388A8
_080B927C: .4byte 0x080B9341
_080B9280: .4byte 0x03005B60
_080B9284:
	movs r0, #0x41
	bl FieldEffectActiveListRemove
_080B928A:
	movs r0, #0
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_080B9234

	thumb_func_start sub_080B9294
sub_080B9294: @ 0x080B9294
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _080B92CC
	adds r4, r0, r1
	movs r1, #0xe
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _080B92D0
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x14
	ble _080B92D4
	movs r0, #0
	strh r0, [r4, #0xc]
	ldrh r1, [r4, #0xa]
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	cmp r0, #0
	beq _080B92D4
	subs r0, r1, #1
	b _080B92D2
	.align 2, 0
_080B92CC: .4byte 0x03005B68
_080B92D0:
	movs r0, #4
_080B92D2:
	strh r0, [r4, #0xa]
_080B92D4:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _080B930E
	movs r0, #0
	strh r0, [r4]
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080B9304
	ldrh r1, [r4, #0xa]
	rsbs r1, r1, #0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r0, #0
	bl SetCameraPanning
	b _080B930E
_080B9304:
	movs r0, #0xa
	ldrsh r1, [r4, r0]
	movs r0, #0
	bl SetCameraPanning
_080B930E:
	bl UpdateCameraPanning
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _080B9320
	adds r0, r5, #0
	bl DestroyTask
_080B9320:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080B9294

	thumb_func_start sub_080B9328
sub_080B9328: @ 0x080B9328
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080B933C
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	movs r0, #1
	strh r0, [r1, #0x16]
	bx lr
	.align 2, 0
_080B933C: .4byte 0x03005B60
	thumb_func_end sub_080B9328

	thumb_func_start sub_080B9340
sub_080B9340: @ 0x080B9340
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r4, r5, #2
	adds r4, r4, r5
	lsls r4, r4, #3
	ldr r0, _080B9378
	adds r4, r4, r0
	bl InstallCameraPanAheadCallback
	movs r0, #0
	bl SetCameraPanningCallback
	ldr r1, _080B937C
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
	thumb_func_end sub_080B9340

	thumb_func_start sub_080B9370
sub_080B9370: @ 0x080B9370
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B9378: .4byte 0x03005B68
_080B937C: .4byte 0x0853723C
	thumb_func_end sub_080B9370

	thumb_func_start sub_080B9380
sub_080B9380: @ 0x080B9380
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080B93A8
	movs r1, #0x5a
	bl CreateTask
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0x58
	bl PlaySE
	strh r4, [r5, #0xa]
	ldrh r0, [r5, #2]
	adds r0, #1
	strh r0, [r5, #2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B93A8: .4byte 0x080B9295
	thumb_func_end sub_080B9380

	thumb_func_start sub_080B93AC
sub_080B93AC: @ 0x080B93AC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	ldrh r0, [r7, #6]
	adds r0, #1
	strh r0, [r7, #6]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x78
	ble _080B941A
	ldr r2, _080B9424
	movs r1, #4
	ldrsh r0, [r7, r1]
	lsls r1, r0, #3
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r0, [r1, #4]
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080B9428
	adds r4, r4, r0
	ldrb r0, [r1, #1]
	movs r2, #0x20
	orrs r0, r2
	strb r0, [r1, #1]
	ldr r6, _080B942C
	ldr r5, _080B9430
	adds r0, r6, #0
	movs r1, #0x10
	adds r2, r5, #0
	bl BlendPalettes
	str r5, [sp]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	adds r0, r4, #0
	bl sub_080B947C
	movs r0, #0x57
	bl PlaySE
	ldrb r0, [r7, #0xa]
	bl sub_080B9328
	movs r0, #0
	strh r0, [r7, #6]
	ldrh r0, [r7, #2]
	adds r0, #1
	strh r0, [r7, #2]
_080B941A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9424: .4byte 0x02036FF0
_080B9428: .4byte 0x020205AC
_080B942C: .4byte 0x0000FFFF
_080B9430: .4byte 0x00007FFF
	thumb_func_end sub_080B93AC

	thumb_func_start sub_080B9434
sub_080B9434: @ 0x080B9434
	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080B9474
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _080B946E
	ldr r0, _080B9478
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B946E
	bl InstallCameraPanAheadCallback
	ldrb r0, [r4, #0xc]
	ldrb r1, [r4, #0xe]
	ldrb r2, [r4, #0x10]
	bl RemoveObjectEventByLocalIdAndMap
	movs r0, #0x41
	bl FieldEffectActiveListRemove
	adds r0, r5, #0
	bl DestroyTask
_080B946E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B9474: .4byte 0x02037C74
_080B9478: .4byte 0x080B9295
	thumb_func_end sub_080B9434

	thumb_func_start sub_080B947C
sub_080B947C: @ 0x080B947C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _080B9500
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x20
	ldrsh r0, [r6, r3]
	adds r2, r2, r0
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	adds r2, r2, r0
	ldr r0, _080B9504
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #0x22
	ldrsh r1, [r6, r3]
	adds r0, r0, r1
	movs r3, #0x26
	ldrsh r1, [r6, r3]
	adds r0, r0, r1
	subs r0, #4
	movs r5, #0
	lsls r2, r2, #0x10
	mov r8, r2
	lsls r7, r0, #0x10
_080B94B2:
	ldr r0, _080B9508
	mov r2, r8
	asrs r1, r2, #0x10
	asrs r2, r7, #0x10
	movs r3, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	beq _080B94EE
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080B950C
	adds r4, r4, r0
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
	strh r5, [r4, #0x2e]
	ldrb r1, [r6, #5]
	lsrs r1, r1, #4
	lsls r1, r1, #4
	ldrb r2, [r4, #5]
	movs r0, #0xf
	ands r0, r2
	orrs r0, r1
	strb r0, [r4, #5]
_080B94EE:
	adds r5, #1
	cmp r5, #3
	ble _080B94B2
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B9500: .4byte 0x03005B4C
_080B9504: .4byte 0x03005B48
_080B9508: .4byte 0x08537298
_080B950C: .4byte 0x020205AC
	thumb_func_end sub_080B947C

	thumb_func_start Fldeff_MoveDeoxysRock
Fldeff_MoveDeoxysRock: @ 0x080B9510
	push {lr}
	adds r1, r0, #0
	movs r2, #0x2e
	ldrsh r0, [r1, r2]
	cmp r0, #1
	beq _080B953C
	cmp r0, #1
	bgt _080B9526
	cmp r0, #0
	beq _080B9530
	b _080B955A
_080B9526:
	cmp r0, #2
	beq _080B9548
	cmp r0, #3
	beq _080B954E
	b _080B955A
_080B9530:
	ldrh r0, [r1, #0x20]
	subs r0, #0x10
	strh r0, [r1, #0x20]
	ldrh r0, [r1, #0x22]
	subs r0, #0xc
	b _080B9558
_080B953C:
	ldrh r0, [r1, #0x20]
	adds r0, #0x10
	strh r0, [r1, #0x20]
	ldrh r0, [r1, #0x22]
	subs r0, #0xc
	b _080B9558
_080B9548:
	ldrh r0, [r1, #0x20]
	subs r0, #0x10
	b _080B9552
_080B954E:
	ldrh r0, [r1, #0x20]
	adds r0, #0x10
_080B9552:
	strh r0, [r1, #0x20]
	ldrh r0, [r1, #0x22]
	adds r0, #0xc
_080B9558:
	strh r0, [r1, #0x22]
_080B955A:
	ldrh r0, [r1, #0x20]
	adds r0, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf8
	bhi _080B9576
	movs r0, #0x22
	ldrsh r2, [r1, r0]
	movs r0, #4
	rsbs r0, r0, #0
	cmp r2, r0
	blt _080B9576
	cmp r2, #0xa4
	ble _080B957C
_080B9576:
	adds r0, r1, #0
	bl DestroySprite
_080B957C:
	pop {r0}
	bx r0
	thumb_func_end Fldeff_MoveDeoxysRock

	thumb_func_start Fldeff_MoveDeoxysRock_Step
Fldeff_MoveDeoxysRock_Step: @ 0x080B9580
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r7, _080B9620
	ldrb r0, [r7]
	ldrb r1, [r7, #4]
	ldrb r2, [r7, #8]
	mov r3, sp
	bl TryGetObjectEventIdByLocalIdAndMap
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B9616
	mov r0, sp
	ldrb r0, [r0]
	lsls r4, r0, #3
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080B9624
	adds r4, r4, r0
	movs r0, #0x10
	ldrsh r5, [r4, r0]
	subs r5, #7
	movs r0, #0x12
	ldrsh r6, [r4, r0]
	subs r6, #7
	ldr r1, [r7, #0xc]
	subs r5, r1, r5
	lsls r5, r5, #4
	ldr r2, [r7, #0x10]
	subs r6, r2, r6
	lsls r6, r6, #4
	adds r1, #7
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	adds r2, #7
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, #0
	bl ShiftEventObjectCoords
	ldr r0, _080B9628
	movs r1, #0x50
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080B962C
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #3
	adds r2, r2, r1
	ldrb r0, [r4, #4]
	strh r0, [r2, #0xa]
	ldr r3, _080B9630
	ldrb r1, [r4, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r0, [r0, #0x20]
	adds r0, r0, r5
	strh r0, [r2, #0xc]
	ldrb r1, [r4, #4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r0, [r0, #0x22]
	adds r0, r0, r6
	strh r0, [r2, #0xe]
	ldr r0, [r7, #0x14]
	strh r0, [r2, #0x18]
	mov r0, sp
	ldrb r0, [r0]
	strh r0, [r2, #0x1a]
_080B9616:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080B9620: .4byte 0x020388A8
_080B9624: .4byte 0x02036FF0
_080B9628: .4byte 0x080B9635
_080B962C: .4byte 0x03005B60
_080B9630: .4byte 0x020205AC
	thumb_func_end Fldeff_MoveDeoxysRock_Step

	thumb_func_start sub_080B9634
sub_080B9634: @ 0x080B9634
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #3
	ldr r1, _080B9660
	adds r5, r0, r1
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080B9664
	adds r6, r0, r1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq _080B9668
	cmp r0, #1
	beq _080B96A6
	b _080B9704
	.align 2, 0
_080B9660: .4byte 0x03005B68
_080B9664: .4byte 0x020205AC
_080B9668:
	ldrh r0, [r6, #0x20]
	lsls r0, r0, #4
	strh r0, [r5, #8]
	ldrh r0, [r6, #0x22]
	lsls r0, r0, #4
	strh r0, [r5, #0xa]
	movs r2, #4
	ldrsh r0, [r5, r2]
	lsls r0, r0, #4
	movs r2, #8
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r2, #0x10
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r5, #0xc]
	movs r1, #6
	ldrsh r0, [r5, r1]
	lsls r0, r0, #4
	movs r2, #0xa
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r2, #0x10
	ldrsh r1, [r5, r2]
	bl __divsi3
	strh r0, [r5, #0xe]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080B96A6:
	ldrh r1, [r5, #0x10]
	movs r2, #0x10
	ldrsh r0, [r5, r2]
	cmp r0, #0
	beq _080B96D4
	subs r0, r1, #1
	strh r0, [r5, #0x10]
	ldrh r1, [r5, #0xc]
	ldrh r0, [r5, #8]
	adds r1, r1, r0
	strh r1, [r5, #8]
	ldrh r0, [r5, #0xe]
	ldrh r2, [r5, #0xa]
	adds r0, r0, r2
	strh r0, [r5, #0xa]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	strh r1, [r6, #0x20]
	ldrh r0, [r5, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r6, #0x22]
	b _080B9704
_080B96D4:
	movs r1, #0x12
	ldrsh r0, [r5, r1]
	lsls r4, r0, #3
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _080B970C
	adds r4, r4, r0
	ldrh r0, [r5, #4]
	strh r0, [r6, #0x20]
	ldrh r0, [r5, #6]
	strh r0, [r6, #0x22]
	adds r0, r4, #0
	bl ShiftStillEventObjectCoords
	ldrb r0, [r4]
	movs r1, #8
	orrs r0, r1
	strb r0, [r4]
	movs r0, #0x42
	bl FieldEffectActiveListRemove
	adds r0, r7, #0
	bl DestroyTask
_080B9704:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B970C: .4byte 0x02036FF0
	thumb_func_end sub_080B9634
