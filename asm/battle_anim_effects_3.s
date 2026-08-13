.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	.section .text.battle_anim_effects_3_rest,"ax",%progbits
	thumb_func_start sub_0815A010
sub_0815A010: @ 0x0815A010
	push {lr}
	adds r2, r0, #0
	ldr r1, _0815A034
	ldrh r0, [r1]
	ldrh r3, [r2, #0x20]
	adds r0, r0, r3
	strh r0, [r2, #0x20]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #0x22]
	adds r0, r0, r3
	strh r0, [r2, #0x22]
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _0815A038
	ldrh r0, [r1, #4]
	b _0815A03C
	.align 2, 0
_0815A034: .4byte 0x020380BE
_0815A038:
	ldrh r0, [r1, #4]
	rsbs r0, r0, #0
_0815A03C:
	strh r0, [r2, #0x2e]
	ldrh r0, [r1, #8]
	strh r0, [r2, #0x30]
	ldr r0, _0815A04C
	str r0, [r2, #0x1c]
	pop {r0}
	bx r0
	.align 2, 0
_0815A04C: .4byte 0x0815A051
	thumb_func_end sub_0815A010

	thumb_func_start sub_0815A050
sub_0815A050: @ 0x0815A050
	push {lr}
	adds r3, r0, #0
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	cmp r0, #0
	ble _0815A090
	ldrh r1, [r3, #0x32]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	strh r0, [r3, #0x24]
	ldrh r0, [r3, #0x2e]
	adds r1, r1, r0
	strh r1, [r3, #0x32]
	movs r0, #0x3e
	adds r0, r0, r3
	mov ip, r0
	ldrb r2, [r0]
	lsls r0, r2, #0x1d
	lsrs r0, r0, #0x1f
	movs r1, #1
	eors r1, r0
	lsls r1, r1, #2
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldrh r0, [r3, #0x30]
	subs r0, #1
	strh r0, [r3, #0x30]
	b _0815A096
_0815A090:
	adds r0, r3, #0
	bl DestroyAnimSprite
_0815A096:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0815A050

	thumb_func_start sub_0815A09C
sub_0815A09C: @ 0x0815A09C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r6, _0815A0E8
	ldrb r0, [r6]
	movs r1, #2
	bl GetBattlerSpriteCoord
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #8
	movs r0, #0x80
	lsls r0, r0, #0xc
	adds r4, r4, r0
	asrs r4, r4, #0x10
	ldrb r0, [r6]
	movs r1, #3
	bl GetBattlerSpriteCoord
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #8
	movs r0, #0x80
	lsls r0, r0, #0xc
	adds r1, r1, r0
	asrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #0
	bl sub_08074C24
	adds r0, r5, #0
	bl DestroyAnimVisualTask
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0815A0E8: .4byte 0x020380D7
	thumb_func_end sub_0815A09C

	thumb_func_start sub_0815A0EC
sub_0815A0EC: @ 0x0815A0EC
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x5a
	strh r0, [r4, #0x2e]
	ldr r0, _0815A128
	str r0, [r4, #0x1c]
	movs r0, #7
	strh r0, [r4, #0x30]
	ldr r1, _0815A12C
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	movs r1, #0xfd
	lsls r1, r1, #6
	movs r0, #0x50
	bl SetGpuReg
	ldrh r0, [r4, #0x30]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r1, r1, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815A128: .4byte 0x080A5D79
_0815A12C: .4byte 0x0815A131
	thumb_func_end sub_0815A0EC

	thumb_func_start sub_0815A130
sub_0815A130: @ 0x0815A130
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x30]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r1, r1, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	ldrh r0, [r4, #0x30]
	subs r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0815A164
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0815A16C
	str r0, [r4, #0x1c]
_0815A164:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815A16C: .4byte 0x0815A171
	thumb_func_end sub_0815A130

	thumb_func_start sub_0815A170
sub_0815A170: @ 0x0815A170
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	adds r0, r4, #0
	bl DestroyAnimSprite
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0815A170

	thumb_func_start sub_0815A190
sub_0815A190: @ 0x0815A190
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r4, _0815A21C
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r0, #0
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r0, #0
	adds r0, r5, #0
	movs r1, #1
	bl InitSpritePosToAnimTarget
	ldrh r0, [r5, #0x20]
	subs r0, r0, r7
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r5, #0x22]
	subs r1, r1, r6
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl ArcTan2Neg
	lsls r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0x17
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815A1EE
	movs r1, #0x80
	lsls r1, r1, #7
	adds r0, r4, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_0815A1EE:
	movs r3, #0x80
	lsls r3, r3, #1
	str r4, [sp]
	adds r0, r5, #0
	movs r1, #0
	adds r2, r3, #0
	bl TrySetSpriteRotScale
	ldr r0, _0815A220
	ldrh r0, [r0, #4]
	strh r0, [r5, #0x2e]
	strh r7, [r5, #0x32]
	strh r6, [r5, #0x36]
	ldr r0, _0815A224
	str r0, [r5, #0x1c]
	ldr r1, _0815A228
	adds r0, r5, #0
	bl StoreSpriteCallbackInData6
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815A21C: .4byte 0x020380D7
_0815A220: .4byte 0x020380BE
_0815A224: .4byte 0x080A67B5
_0815A228: .4byte 0x080A34C5
	thumb_func_end sub_0815A190

	thumb_func_start sub_0815A22C
sub_0815A22C: @ 0x0815A22C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xfd
	lsls r1, r1, #6
	movs r0, #0x50
	bl SetGpuReg
	movs r1, #0x80
	lsls r1, r1, #5
	movs r0, #0x52
	bl SetGpuReg
	movs r0, #4
	strh r0, [r4, #0x2e]
	ldr r0, _0815A254
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815A254: .4byte 0x0815A259
	thumb_func_end sub_0815A22C

	thumb_func_start sub_0815A258
sub_0815A258: @ 0x0815A258
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r1, r1, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _0815A27E
	ldrh r0, [r4, #0x2e]
	subs r0, #1
	b _0815A282
_0815A27E:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
_0815A282:
	strh r0, [r4, #0x2e]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0xf
	beq _0815A290
	cmp r0, #4
	bne _0815A298
_0815A290:
	ldrh r0, [r4, #0x30]
	movs r1, #1
	eors r0, r1
	strh r0, [r4, #0x30]
_0815A298:
	ldrh r0, [r4, #0x32]
	adds r1, r0, #1
	strh r1, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x46
	ble _0815A2DC
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	adds r0, r4, #0
	movs r1, #1
	bl StartSpriteAffineAnim
	movs r0, #0
	strh r0, [r4, #0x32]
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	subs r2, #0x12
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0815A2E4
	str r0, [r4, #0x1c]
_0815A2DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815A2E4: .4byte 0x0815A2E9
	thumb_func_end sub_0815A258

	thumb_func_start sub_0815A2E8
sub_0815A2E8: @ 0x0815A2E8
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x32]
	adds r1, r0, #1
	strh r1, [r3, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	ble _0815A324
	adds r2, r3, #0
	adds r2, #0x3e
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	subs r2, #0x12
	ldrb r1, [r2]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2]
	adds r0, r3, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0815A324
	ldr r0, _0815A328
	str r0, [r3, #0x1c]
_0815A324:
	pop {r0}
	bx r0
	.align 2, 0
_0815A328: .4byte 0x0815A32D
	thumb_func_end sub_0815A2E8

	thumb_func_start sub_0815A32C
sub_0815A32C: @ 0x0815A32C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	cmp r0, #6
	bhi _0815A384
	lsls r0, r0, #2
	ldr r1, _0815A344
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815A344: .4byte 0x0815A348
_0815A348: @ jump table
	.4byte _0815A364 @ case 0
	.4byte _0815A364 @ case 1
	.4byte _0815A36E @ case 2
	.4byte _0815A36E @ case 3
	.4byte _0815A37C @ case 4
	.4byte _0815A37C @ case 5
	.4byte _0815A384 @ case 6
_0815A364:
	movs r1, #0
	movs r0, #1
	strh r0, [r4, #0x24]
	strh r1, [r4, #0x26]
	b _0815A38C
_0815A36E:
	ldr r0, _0815A378
	strh r0, [r4, #0x24]
	movs r0, #0
	b _0815A38A
	.align 2, 0
_0815A378: .4byte 0x0000FFFF
_0815A37C:
	movs r0, #0
	strh r0, [r4, #0x24]
	movs r0, #1
	b _0815A38A
_0815A384:
	movs r0, #0
	strh r0, [r4, #0x24]
	ldr r0, _0815A3D0
_0815A38A:
	strh r0, [r4, #0x26]
_0815A38C:
	ldrh r0, [r4, #0x34]
	adds r0, #1
	movs r2, #0
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0815A39E
	strh r2, [r4, #0x34]
_0815A39E:
	ldrh r0, [r4, #0x36]
	adds r1, r0, #1
	strh r1, [r4, #0x36]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	ble _0815A3C8
	movs r0, #0x10
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x30]
	movs r1, #0xfd
	lsls r1, r1, #6
	movs r0, #0x50
	bl SetGpuReg
	ldrh r1, [r4, #0x2e]
	movs r0, #0x52
	bl SetGpuReg
	ldr r0, _0815A3D4
	str r0, [r4, #0x1c]
_0815A3C8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815A3D0: .4byte 0x0000FFFF
_0815A3D4: .4byte 0x0815A3D9
	thumb_func_end sub_0815A32C

	thumb_func_start sub_0815A3D8
sub_0815A3D8: @ 0x0815A3D8
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r1, r1, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	ldrh r0, [r4, #0x30]
	adds r1, r0, #1
	strh r1, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0815A408
	ldrh r0, [r4, #0x2e]
	subs r0, #1
	movs r1, #0
	strh r0, [r4, #0x2e]
	strh r1, [r4, #0x30]
_0815A408:
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0815A41C
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
_0815A41C:
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bge _0815A43A
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	adds r0, r4, #0
	bl DestroyAnimSprite
_0815A43A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0815A3D8

	thumb_func_start sub_0815A440
sub_0815A440: @ 0x0815A440
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0815A45C
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldr r0, _0815A460
	str r0, [r1]
	ldr r1, _0815A464
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0
_0815A45C: .4byte 0x03005B60
_0815A460: .4byte 0x0815A469
_0815A464: .4byte 0x0203809E
	thumb_func_end sub_0815A440

	thumb_func_start sub_0815A468
sub_0815A468: @ 0x0815A468
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_080A665C
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r7, _0815A4F4
	lsls r5, r4, #2
	adds r1, r5, r4
	lsls r1, r1, #3
	adds r1, r1, r7
	ldrh r0, [r1, #0x12]
	adds r0, #1
	strh r0, [r1, #0x12]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _0815A4D8
	ldr r0, _0815A4F8
	lsls r2, r6, #4
	adds r1, r2, #0
	adds r1, #0xb
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r3, [r1]
	mov r8, r3
	movs r3, #0xa
	mov sb, r7
	adds r7, r5, #0
	mov ip, r0
	adds r5, r2, #0
	lsls r0, r6, #5
	add r0, ip
	adds r2, r0, #0
	adds r2, #0x14
_0815A4B6:
	ldrh r0, [r2]
	strh r0, [r1]
	subs r2, #2
	subs r1, #2
	subs r3, #1
	cmp r3, #0
	bgt _0815A4B6
	adds r0, r5, #1
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	mov r2, r8
	strh r2, [r0]
	adds r0, r7, r4
	lsls r0, r0, #3
	add r0, sb
	strh r1, [r0, #0x12]
_0815A4D8:
	ldr r0, _0815A4FC
	ldrh r1, [r0, #0xe]
	ldr r0, _0815A500
	cmp r1, r0
	bne _0815A4E8
	adds r0, r4, #0
	bl DestroyTask
_0815A4E8:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815A4F4: .4byte 0x03005B60
_0815A4F8: .4byte 0x020377B4
_0815A4FC: .4byte 0x020380BE
_0815A500: .4byte 0x0000FFFF
	thumb_func_end sub_0815A468


	.section .text.battle_anim_effects_3_rest2,"ax",%progbits




	thumb_func_start AnimTask_IsTargetPlayerSide
AnimTask_IsTargetPlayerSide: @ 0x0815A804
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _0815A820
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815A828
	ldr r1, _0815A824
	movs r0, #0
	b _0815A82C
	.align 2, 0
_0815A820: .4byte 0x020380D7
_0815A824: .4byte 0x020380BE
_0815A828:
	ldr r1, _0815A83C
	movs r0, #1
_0815A82C:
	strh r0, [r1, #0xe]
	adds r0, r4, #0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815A83C: .4byte 0x020380BE
	thumb_func_end AnimTask_IsTargetPlayerSide

	thumb_func_start AnimTask_IsHealingMove
AnimTask_IsHealingMove: @ 0x0815A840
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _0815A854
	ldr r0, [r0]
	cmp r0, #0
	ble _0815A85C
	ldr r1, _0815A858
	movs r0, #0
	b _0815A860
	.align 2, 0
_0815A854: .4byte 0x020380A4
_0815A858: .4byte 0x020380BE
_0815A85C:
	ldr r1, _0815A86C
	movs r0, #1
_0815A860:
	strh r0, [r1, #0xe]
	adds r0, r2, #0
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.align 2, 0
_0815A86C: .4byte 0x020380BE
	thumb_func_end AnimTask_IsHealingMove


	.section .text.battle_anim_effects_3_rest3,"ax",%progbits
	thumb_func_start sub_0815A9A8
sub_0815A9A8: @ 0x0815A9A8
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0815A9DC
	movs r0, #0x4a
	bl SetGpuReg
	movs r0, #0
	bl GetGpuReg
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	eors r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0
	bl SetGpuReg
	adds r0, r4, #0
	bl DestroyAnimSprite
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815A9DC: .4byte 0x00003F3F
	thumb_func_end sub_0815A9A8


	.section .text.battle_anim_effects_3_rest4,"ax",%progbits











	thumb_func_start sub_0815B648
sub_0815B648: @ 0x0815B648
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _0815B65A
	cmp r0, #1
	beq _0815B684
	b _0815B6AC
_0815B65A:
	adds r0, r4, #0
	movs r1, #0
	bl InitSpritePosToAnimAttacker
	movs r0, #0x90
	lsls r0, r0, #4
	strh r0, [r4, #0x30]
	ldr r0, _0815B680
	ldrb r0, [r0]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x32]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	b _0815B6AC
	.align 2, 0
_0815B680: .4byte 0x020380D6
_0815B684:
	ldrh r2, [r4, #0x30]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x18
	ldrh r0, [r4, #0x26]
	subs r0, r0, r1
	strh r0, [r4, #0x26]
	subs r2, #0x60
	strh r2, [r4, #0x30]
	movs r2, #0x22
	ldrsh r0, [r4, r2]
	movs r2, #0x26
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	cmp r0, r1
	ble _0815B6AC
	adds r0, r4, #0
	bl DestroyAnimSprite
_0815B6AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0815B648

	.section .text.battle_anim_effects_3_rest5,"ax",%progbits







	thumb_func_start sub_0815B70C
sub_0815B70C: @ 0x0815B70C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r1, _0815B73C
	lsls r0, r0, #2
	add r0, r8
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #8
	ldrsh r0, [r0, r2]
	adds r3, r1, #0
	cmp r0, #4
	bls _0815B732
	b _0815BA38
_0815B732:
	lsls r0, r0, #2
	ldr r1, _0815B740
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815B73C: .4byte 0x03005B60
_0815B740: .4byte 0x0815B744
_0815B744: @ jump table
	.4byte _0815B758 @ case 0
	.4byte _0815B7A8 @ case 1
	.4byte _0815B7E4 @ case 2
	.4byte _0815B980 @ case 3
	.4byte _0815B9BE @ case 4
_0815B758:
	movs r0, #0x4c
	movs r1, #0
	bl SetGpuReg
	ldr r0, _0815B77C
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815B780
	movs r0, #1
	movs r1, #2
	movs r2, #1
	bl SetAnimBgAttribute
	b _0815B78A
	.align 2, 0
_0815B77C: .4byte 0x020380D6
_0815B780:
	movs r0, #2
	movs r1, #2
	movs r2, #1
	bl SetAnimBgAttribute
_0815B78A:
	ldr r0, _0815B7A0
	mov r6, r8
	lsls r1, r6, #2
	add r1, r8
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _0815B7A4
	ldrh r0, [r0]
	strh r0, [r1, #0x1c]
	b _0815B962
	.align 2, 0
_0815B7A0: .4byte 0x03005B60
_0815B7A4: .4byte 0x020380BE
_0815B7A8:
	mov r1, r8
	lsls r0, r1, #2
	add r0, r8
	lsls r0, r0, #3
	adds r4, r0, r3
	ldrh r0, [r4, #0xc]
	adds r1, r0, #1
	strh r1, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bgt _0815B7C2
	b _0815BA38
_0815B7C2:
	movs r0, #0
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	ldrh r5, [r4, #0xa]
	lsls r1, r5, #4
	orrs r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x4c
	bl SetGpuReg
	cmp r5, #0xf
	beq _0815B7E2
	b _0815BA38
_0815B7E2:
	b _0815B9B6
_0815B7E4:
	ldr r5, _0815B814
	ldrb r0, [r5]
	ldr r1, _0815B818
	ldrb r1, [r1]
	mov r2, r8
	lsls r4, r2, #2
	adds r2, r4, r2
	lsls r2, r2, #3
	adds r2, r2, r3
	ldrb r2, [r2, #0x1c]
	bl HandleSpeciesGfxDataChange
	ldrb r1, [r5]
	mov r0, sp
	bl sub_080A64C4
	bl IsContest
	lsls r0, r0, #0x18
	mov sb, r4
	cmp r0, #0
	beq _0815B81C
	movs r1, #0
	b _0815B826
	.align 2, 0
_0815B814: .4byte 0x020380D6
_0815B818: .4byte 0x020380D7
_0815B81C:
	ldrb r0, [r5]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0815B826:
	ldr r0, _0815B908
	ldr r2, [r0]
	lsls r0, r1, #2
	adds r2, #4
	adds r2, r2, r0
	ldr r1, _0815B90C
	ldr r0, _0815B910
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	lsls r1, r1, #0xb
	ldr r0, [r2]
	adds r0, r0, r1
	ldr r1, [sp]
	ldr r2, _0815B914
	bl CpuSet
	ldr r1, [sp]
	movs r2, #0x80
	lsls r2, r2, #4
	mov r0, sp
	ldrh r3, [r0, #0xa]
	movs r0, #1
	bl LoadBgTiles
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815B958
	ldr r5, _0815B918
	ldr r0, [r5]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0]
	bl IsSpeciesNotUnown
	adds r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0, #2]
	bl IsSpeciesNotUnown
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0815B8D8
	ldr r6, [sp, #4]
	movs r5, #0
	movs r0, #7
	mov ip, r0
	movs r7, #0
_0815B88C:
	movs r4, #0
	adds r3, r7, r6
	mov r1, ip
	lsls r0, r1, #1
	adds r2, r0, r6
_0815B896:
	ldrh r1, [r3]
	ldrh r0, [r2]
	strh r0, [r3]
	strh r1, [r2]
	adds r3, #2
	subs r2, #2
	adds r4, #1
	cmp r4, #3
	ble _0815B896
	movs r2, #0x20
	add ip, r2
	adds r7, #0x40
	adds r5, #1
	cmp r5, #7
	ble _0815B88C
	movs r5, #0
	movs r0, #0x80
	lsls r0, r0, #3
	adds r3, r0, #0
_0815B8BC:
	adds r2, r5, #1
	lsls r0, r5, #6
	adds r1, r0, r6
	movs r4, #7
_0815B8C4:
	ldrh r0, [r1]
	eors r0, r3
	strh r0, [r1]
	adds r1, #2
	subs r4, #1
	cmp r4, #0
	bge _0815B8C4
	adds r5, r2, #0
	cmp r5, #7
	ble _0815B8BC
_0815B8D8:
	ldr r0, _0815B918
	ldr r0, [r0]
	ldr r0, [r0, #0x18]
	ldrh r0, [r0, #2]
	bl IsSpeciesNotUnown
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815B928
	ldr r3, _0815B91C
	ldr r4, _0815B920
	ldr r2, _0815B910
	ldrb r0, [r2]
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r3, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r1, _0815B924
	b _0815B942
	.align 2, 0
_0815B908: .4byte 0x02024178
_0815B90C: .4byte 0x02024188
_0815B910: .4byte 0x020380D6
_0815B914: .4byte 0x04000200
_0815B918: .4byte 0x02039BD4
_0815B91C: .4byte 0x020205AC
_0815B920: .4byte 0x02023E88
_0815B924: .4byte 0x082D2F50
_0815B928:
	ldr r3, _0815B96C
	ldr r4, _0815B970
	ldr r2, _0815B974
	ldrb r0, [r2]
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r3, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r1, _0815B978
_0815B942:
	str r1, [r0]
	ldrb r0, [r2]
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #0
	bl StartSpriteAffineAnim
_0815B958:
	ldr r0, _0815B97C
	mov r1, sb
	add r1, r8
	lsls r1, r1, #3
	adds r1, r1, r0
_0815B962:
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0815BA38
	.align 2, 0
_0815B96C: .4byte 0x020205AC
_0815B970: .4byte 0x02023E88
_0815B974: .4byte 0x020380D6
_0815B978: .4byte 0x082D2F24
_0815B97C: .4byte 0x03005B60
_0815B980:
	mov r1, r8
	lsls r0, r1, #2
	add r0, r8
	lsls r0, r0, #3
	adds r4, r0, r3
	ldrh r0, [r4, #0xc]
	adds r1, r0, #1
	strh r1, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0815BA38
	movs r0, #0
	strh r0, [r4, #0xc]
	ldrh r0, [r4, #0xa]
	subs r0, #1
	strh r0, [r4, #0xa]
	ldrh r5, [r4, #0xa]
	lsls r1, r5, #4
	orrs r1, r5
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x4c
	bl SetGpuReg
	cmp r5, #0
	bne _0815BA38
_0815B9B6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0815BA38
_0815B9BE:
	movs r0, #0x4c
	movs r1, #0
	bl SetGpuReg
	ldr r0, _0815B9E4
	ldrb r0, [r0]
	bl GetBattlerSpriteBGPriorityRank
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815B9E8
	movs r0, #1
	movs r1, #2
	movs r2, #0
	bl SetAnimBgAttribute
	b _0815B9F2
	.align 2, 0
_0815B9E4: .4byte 0x020380D6
_0815B9E8:
	movs r0, #2
	movs r1, #2
	movs r2, #0
	bl SetAnimBgAttribute
_0815B9F2:
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815BA32
	ldr r4, _0815BA48
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815BA32
	ldr r0, _0815BA4C
	mov r2, r8
	lsls r1, r2, #2
	add r1, r8
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r6, #0x1c
	ldrsh r0, [r1, r6]
	cmp r0, #0
	bne _0815BA32
	ldrb r0, [r4]
	ldr r1, _0815BA50
	ldr r1, [r1]
	ldr r2, [r1]
	lsls r1, r0, #2
	adds r1, r1, r2
	ldrh r1, [r1, #2]
	bl SetBattlerShadowSpriteCallback
_0815BA32:
	mov r0, r8
	bl DestroyAnimVisualTask
_0815BA38:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815BA48: .4byte 0x020380D6
_0815BA4C: .4byte 0x03005B60
_0815BA50: .4byte 0x02024174
	thumb_func_end sub_0815B70C

	thumb_func_start sub_0815BA54
sub_0815BA54: @ 0x0815BA54
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r4, _0815BA84
	ldr r3, _0815BA88
	ldr r2, _0815BA8C
	ldr r1, _0815BA90
	ldrb r1, [r1]
	adds r1, r1, r2
	ldrb r2, [r1]
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r3
	adds r1, #0x3e
	ldrb r1, [r1]
	lsls r1, r1, #0x1d
	lsrs r1, r1, #0x1f
	strh r1, [r4, #0xe]
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815BA84: .4byte 0x020380BE
_0815BA88: .4byte 0x020205AC
_0815BA8C: .4byte 0x02023E88
_0815BA90: .4byte 0x020380D6
	thumb_func_end sub_0815BA54

	thumb_func_start sub_0815BA94
sub_0815BA94: @ 0x0815BA94
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _0815BAB8
	ldrb r0, [r0]
	ldr r1, _0815BABC
	ldrb r1, [r1]
	movs r2, #1
	bl HandleSpeciesGfxDataChange
	adds r0, r4, #0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815BAB8: .4byte 0x020380D6
_0815BABC: .4byte 0x020380D7
	thumb_func_end sub_0815BA94

	thumb_func_start sub_0815BAC0
sub_0815BAC0: @ 0x0815BAC0
	push {r4, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _0815BAE8
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #8
	ldrsh r0, [r0, r2]
	adds r2, r1, #0
	cmp r0, #4
	bls _0815BADE
	b _0815BD2E
_0815BADE:
	lsls r0, r0, #2
	ldr r1, _0815BAEC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815BAE8: .4byte 0x03005B60
_0815BAEC: .4byte 0x0815BAF0
_0815BAF0: @ jump table
	.4byte _0815BB04 @ case 0
	.4byte _0815BBF4 @ case 1
	.4byte _0815BC44 @ case 2
	.4byte _0815BCAE @ case 3
	.4byte _0815BCE2 @ case 4
_0815BB04:
	ldr r1, _0815BB60
	movs r0, #0x50
	bl SetGpuReg
	movs r1, #0x80
	lsls r1, r1, #5
	movs r0, #0x52
	bl SetGpuReg
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetAnimBgAttribute
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815BB3E
	movs r0, #1
	movs r1, #3
	movs r2, #1
	bl SetAnimBgAttribute
_0815BB3E:
	mov r0, sp
	bl sub_080A63F8
	ldr r1, _0815BB64
	mov r0, sp
	movs r2, #0
	bl sub_080A6628
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815BB70
	ldr r1, _0815BB68
	ldr r3, _0815BB6C
	b _0815BB98
	.align 2, 0
_0815BB60: .4byte 0x00003F42
_0815BB64: .4byte 0x08C2A790
_0815BB68: .4byte 0x02022ACC
_0815BB6C: .4byte 0x0000FFC8
_0815BB70:
	ldr r0, _0815BB88
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815BB94
	ldr r1, _0815BB8C
	ldr r2, _0815BB90
	adds r0, r2, #0
	b _0815BB9A
	.align 2, 0
_0815BB88: .4byte 0x020380D6
_0815BB8C: .4byte 0x02022ACC
_0815BB90: .4byte 0x0000FF79
_0815BB94:
	ldr r1, _0815BBDC
	ldr r3, _0815BBE0
_0815BB98:
	adds r0, r3, #0
_0815BB9A:
	strh r0, [r1]
	ldr r1, _0815BBE4
	movs r0, #0
	strh r0, [r1]
	mov r0, sp
	ldrb r0, [r0, #9]
	ldr r1, _0815BBE8
	mov r2, sp
	ldrh r2, [r2, #0xa]
	bl AnimLoadCompressedBgGfx
	ldr r0, _0815BBEC
	mov r1, sp
	ldrb r1, [r1, #8]
	lsls r1, r1, #4
	movs r2, #0x20
	bl LoadCompressedPalette
	ldr r0, _0815BBF0
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _0815BBDC
	ldrh r0, [r0]
	strh r0, [r1, #0x1c]
	ldr r0, _0815BBE4
	ldrh r0, [r0]
	strh r0, [r1, #0x1e]
	ldrh r0, [r1, #8]
	adds r0, #1
	b _0815BCCA
	.align 2, 0
_0815BBDC: .4byte 0x02022ACC
_0815BBE0: .4byte 0x0000FFF6
_0815BBE4: .4byte 0x02022ACE
_0815BBE8: .4byte 0x08C2A6D8
_0815BBEC: .4byte 0x08C2A778
_0815BBF0: .4byte 0x03005B60
_0815BBF4:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r4, r0, r2
	ldrh r0, [r4, #0x10]
	adds r1, r0, #1
	strh r1, [r4, #0x10]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0815BC0A
	b _0815BD2E
_0815BC0A:
	movs r0, #0
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xc
	ble _0815BC20
	movs r0, #0xc
	strh r0, [r4, #0xa]
_0815BC20:
	ldrh r0, [r4, #0xa]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r1, r1, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0xc
	bne _0815BD2E
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0815BD2E
_0815BC44:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r4, r0, r2
	ldrh r0, [r4, #0xa]
	subs r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0815BC5C
	movs r0, #0
	strh r0, [r4, #0xa]
_0815BC5C:
	ldrh r0, [r4, #0xa]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r1, r1, #8
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _0815BD2E
	ldr r2, _0815BCA0
	ldr r1, _0815BCA4
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _0815BCA8
	strh r0, [r4, #8]
	b _0815BD2E
	.align 2, 0
_0815BCA0: .4byte 0x02022ACC
_0815BCA4: .4byte 0x085AD268
_0815BCA8:
	movs r0, #3
	strh r0, [r4, #8]
	b _0815BD2E
_0815BCAE:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r1, r0, r2
	ldrh r0, [r1, #0xe]
	adds r0, #1
	strh r0, [r1, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bne _0815BD2E
	movs r0, #0
	strh r0, [r1, #0xe]
	movs r0, #1
_0815BCCA:
	strh r0, [r1, #8]
	movs r0, #0x40
	rsbs r0, r0, #0
	bl BattleAnimAdjustPanning
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0xe4
	bl PlaySE12WithPanning
	b _0815BD2E
_0815BCE2:
	mov r0, sp
	bl sub_080A63F8
	mov r0, sp
	ldrb r0, [r0, #9]
	bl sub_080A6530
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815BD04
	movs r0, #1
	movs r1, #3
	movs r2, #0
	bl SetAnimBgAttribute
_0815BD04:
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	ldr r0, _0815BD38
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0815BD3C
	strh r1, [r0]
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	adds r0, r4, #0
	bl DestroyAnimVisualTask
_0815BD2E:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815BD38: .4byte 0x02022ACC
_0815BD3C: .4byte 0x02022ACE
	thumb_func_end sub_0815BAC0

	thumb_func_start sub_0815BD40
sub_0815BD40: @ 0x0815BD40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	bl Random2
	lsls r0, r0, #0x10
	movs r1, #0xfc
	lsls r1, r1, #0xe
	ands r1, r0
	lsrs r5, r1, #0x10
	adds r1, r5, #0
	cmp r1, #0x1f
	ble _0815BD6A
	movs r0, #0x20
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0815BD6A:
	ldr r4, _0815BE64
	ldrb r0, [r4]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r5
	strh r0, [r7, #0x20]
	ldrb r0, [r4]
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x20
	strh r0, [r7, #0x22]
	ldr r1, _0815BE68
	ldrh r0, [r1]
	strh r0, [r7, #0x30]
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x32]
	ldr r4, _0815BE6C
	movs r0, #0x20
	ldrsh r1, [r7, r0]
	movs r0, #0x22
	ldrsh r2, [r7, r0]
	adds r5, r7, #0
	adds r5, #0x43
	ldrb r3, [r5]
	adds r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	bl CreateSprite
	mov sb, r0
	mov r1, sb
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	movs r0, #0x20
	ldrsh r1, [r7, r0]
	movs r0, #0x22
	ldrsh r2, [r7, r0]
	ldrb r3, [r5]
	adds r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	bl CreateSprite
	mov r8, r0
	mov r1, r8
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	mov r0, sb
	lsls r2, r0, #4
	add r2, sb
	lsls r2, r2, #2
	ldr r1, _0815BE70
	mov sl, r1
	adds r5, r2, r1
	adds r0, r5, #0
	movs r1, #1
	str r2, [sp]
	bl StartSpriteAnim
	mov r0, r8
	lsls r6, r0, #4
	add r6, r8
	lsls r6, r6, #2
	mov r1, sl
	adds r4, r6, r1
	adds r0, r4, #0
	movs r1, #2
	bl StartSpriteAnim
	ldr r1, _0815BE68
	ldrh r0, [r1]
	strh r0, [r5, #0x30]
	ldrh r0, [r1, #2]
	strh r0, [r5, #0x32]
	ldrh r0, [r1]
	strh r0, [r4, #0x30]
	ldrh r0, [r1, #2]
	strh r0, [r4, #0x32]
	ldr r0, _0815BE74
	strh r0, [r5, #0x3c]
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r4, #0x3c]
	adds r5, #0x3e
	ldrb r0, [r5]
	movs r1, #4
	orrs r0, r1
	strb r0, [r5]
	adds r4, #0x3e
	ldrb r0, [r4]
	orrs r0, r1
	strb r0, [r4]
	movs r0, #0x1c
	add sl, r0
	ldr r2, [sp]
	add r2, sl
	ldr r0, _0815BE78
	str r0, [r2]
	add r6, sl
	str r0, [r6]
	mov r1, sb
	strh r1, [r7, #0x3a]
	mov r0, r8
	strh r0, [r7, #0x3c]
	ldr r0, _0815BE7C
	str r0, [r7, #0x1c]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815BE64: .4byte 0x020380D6
_0815BE68: .4byte 0x020380BE
_0815BE6C: .4byte 0x085AD294
_0815BE70: .4byte 0x020205AC
_0815BE74: .4byte 0x0000FFFF
_0815BE78: .4byte 0x0815BF8D
_0815BE7C: .4byte 0x0815BE81
	thumb_func_end sub_0815BD40

	thumb_func_start sub_0815BE80
sub_0815BE80: @ 0x0815BE80
	push {lr}
	adds r3, r0, #0
	ldrh r2, [r3, #0x32]
	ldrh r0, [r3, #0x34]
	adds r2, r2, r0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x18
	ldrh r1, [r3, #0x26]
	subs r1, r1, r0
	strh r1, [r3, #0x26]
	movs r0, #0xff
	ands r2, r0
	strh r2, [r3, #0x34]
	movs r2, #0x36
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bne _0815BECE
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	movs r1, #8
	rsbs r1, r1, #0
	cmp r0, r1
	bge _0815BECE
	ldr r2, _0815BF28
	movs r0, #0x3a
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
	ldrh r0, [r3, #0x36]
	adds r0, #1
	strh r0, [r3, #0x36]
_0815BECE:
	movs r1, #0x36
	ldrsh r0, [r3, r1]
	cmp r0, #1
	bne _0815BF02
	movs r2, #0x26
	ldrsh r1, [r3, r2]
	movs r0, #0x10
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0815BF02
	ldr r2, _0815BF28
	movs r0, #0x3c
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
	ldrh r0, [r3, #0x36]
	adds r0, #1
	strh r0, [r3, #0x36]
_0815BF02:
	ldrh r0, [r3, #0x30]
	subs r0, #1
	strh r0, [r3, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0815BF24
	adds r2, r3, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0815BF2C
	str r0, [r3, #0x1c]
_0815BF24:
	pop {r0}
	bx r0
	.align 2, 0
_0815BF28: .4byte 0x020205AC
_0815BF2C: .4byte 0x0815BF31
	thumb_func_end sub_0815BE80

	thumb_func_start sub_0815BF30
sub_0815BF30: @ 0x0815BF30
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, _0815BF84
	movs r0, #0x3a
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r3, r0, #2
	adds r6, r5, #0
	adds r6, #0x1c
	adds r0, r3, r6
	ldr r2, [r0]
	ldr r0, _0815BF88
	cmp r2, r0
	bne _0815BF7C
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r6
	ldr r0, [r1]
	cmp r0, r2
	bne _0815BF7C
	adds r0, r3, r5
	bl DestroySprite
	movs r0, #0x3c
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	bl DestroySprite
	adds r0, r4, #0
	bl DestroyAnimSprite
_0815BF7C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0815BF84: .4byte 0x020205AC
_0815BF88: .4byte 0x08007141
	thumb_func_end sub_0815BF30

	thumb_func_start sub_0815BF8C
sub_0815BF8C: @ 0x0815BF8C
	push {lr}
	adds r3, r0, #0
	movs r0, #0x3e
	adds r0, r0, r3
	mov ip, r0
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _0815BFD8
	ldrh r2, [r3, #0x32]
	ldrh r1, [r3, #0x34]
	adds r2, r2, r1
	lsls r1, r2, #0x10
	asrs r1, r1, #0x18
	ldrh r0, [r3, #0x26]
	subs r0, r0, r1
	strh r0, [r3, #0x26]
	movs r0, #0xff
	ands r2, r0
	strh r2, [r3, #0x34]
	ldrh r0, [r3, #0x30]
	subs r0, #1
	strh r0, [r3, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0815BFD8
	mov r1, ip
	ldrb r0, [r1]
	movs r1, #4
	orrs r0, r1
	mov r1, ip
	strb r0, [r1]
	ldr r0, _0815BFDC
	str r0, [r3, #0x1c]
_0815BFD8:
	pop {r0}
	bx r0
	.align 2, 0
_0815BFDC: .4byte 0x08007141
	thumb_func_end sub_0815BF8C

	thumb_func_start sub_0815BFE0
sub_0815BFE0: @ 0x0815BFE0
	push {r4, r5, r6, lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _0815C008
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #8
	ldrsh r0, [r0, r2]
	adds r4, r1, #0
	cmp r0, #5
	bls _0815BFFE
	b _0815C2D2
_0815BFFE:
	lsls r0, r0, #2
	ldr r1, _0815C00C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815C008: .4byte 0x03005B60
_0815C00C: .4byte 0x0815C010
_0815C010: @ jump table
	.4byte _0815C028 @ case 0
	.4byte _0815C160 @ case 1
	.4byte _0815C1E8 @ case 2
	.4byte _0815C21E @ case 3
	.4byte _0815C24C @ case 4
	.4byte _0815C286 @ case 5
_0815C028:
	ldr r1, _0815C084
	movs r0, #0x50
	bl SetGpuReg
	ldr r1, _0815C088
	movs r0, #0x52
	bl SetGpuReg
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl SetAnimBgAttribute
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815C060
	movs r0, #1
	movs r1, #3
	movs r2, #1
	bl SetAnimBgAttribute
_0815C060:
	mov r0, sp
	bl sub_080A63F8
	ldr r1, _0815C08C
	mov r0, sp
	movs r2, #0
	bl sub_080A6628
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815C098
	ldr r1, _0815C090
	ldr r3, _0815C094
	adds r0, r3, #0
	b _0815C106
	.align 2, 0
_0815C084: .4byte 0x00003F42
_0815C088: .4byte 0x00000D03
_0815C08C: .4byte 0x08C2A790
_0815C090: .4byte 0x02022ACC
_0815C094: .4byte 0x0000FFC8
_0815C098:
	ldr r0, _0815C0DC
	ldrb r0, [r0]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815C0F0
	cmp r4, #1
	bne _0815C0BC
	ldr r1, _0815C0E0
	ldr r2, _0815C0E4
	adds r0, r2, #0
	strh r0, [r1]
_0815C0BC:
	cmp r4, #3
	bne _0815C0C8
	ldr r1, _0815C0E0
	ldr r3, _0815C0E8
	adds r0, r3, #0
	strh r0, [r1]
_0815C0C8:
	cmp r4, #0
	bne _0815C0D2
	ldr r1, _0815C0E0
	movs r0, #0xe
	strh r0, [r1]
_0815C0D2:
	cmp r4, #2
	bne _0815C108
	ldr r1, _0815C0E0
	ldr r2, _0815C0EC
	b _0815C104
	.align 2, 0
_0815C0DC: .4byte 0x020380D7
_0815C0E0: .4byte 0x02022ACC
_0815C0E4: .4byte 0x0000FF65
_0815C0E8: .4byte 0x0000FF8D
_0815C0EC: .4byte 0x0000FFEC
_0815C0F0:
	cmp r4, #1
	bne _0815C0FC
	ldr r1, _0815C144
	ldr r3, _0815C148
	adds r0, r3, #0
	strh r0, [r1]
_0815C0FC:
	cmp r4, #0
	bne _0815C108
	ldr r1, _0815C144
	ldr r2, _0815C14C
_0815C104:
	adds r0, r2, #0
_0815C106:
	strh r0, [r1]
_0815C108:
	ldr r1, _0815C150
	movs r0, #0
	strh r0, [r1]
	mov r0, sp
	ldrb r0, [r0, #9]
	ldr r1, _0815C154
	mov r2, sp
	ldrh r2, [r2, #0xa]
	bl AnimLoadCompressedBgGfx
	ldr r0, _0815C158
	mov r1, sp
	ldrb r1, [r1, #8]
	lsls r1, r1, #4
	movs r2, #0x20
	bl LoadCompressedPalette
	ldr r0, _0815C15C
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldr r0, _0815C144
	ldrh r0, [r0]
	strh r0, [r1, #0x1c]
	ldr r0, _0815C150
	ldrh r0, [r0]
	strh r0, [r1, #0x1e]
	b _0815C1E0
	.align 2, 0
_0815C144: .4byte 0x02022ACC
_0815C148: .4byte 0x0000FF79
_0815C14C: .4byte 0x0000FFF6
_0815C150: .4byte 0x02022ACE
_0815C154: .4byte 0x08C2A6D8
_0815C158: .4byte 0x08C2A778
_0815C15C: .4byte 0x03005B60
_0815C160:
	ldr r1, _0815C194
	lsls r4, r6, #2
	adds r0, r4, r6
	lsls r0, r0, #3
	adds r5, r0, r1
	movs r0, #0
	strh r0, [r5, #0xe]
	ldr r0, _0815C198
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815C1A4
	ldr r2, _0815C19C
	ldr r1, _0815C1A0
	movs r3, #0xc
	ldrsh r0, [r5, r3]
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldrh r5, [r5, #0x1c]
	adds r0, r0, r5
	b _0815C1B6
	.align 2, 0
_0815C194: .4byte 0x03005B60
_0815C198: .4byte 0x020380D7
_0815C19C: .4byte 0x02022ACC
_0815C1A0: .4byte 0x085AD2AC
_0815C1A4:
	ldr r2, _0815C1D4
	ldr r1, _0815C1D8
	movs r3, #0xc
	ldrsh r0, [r5, r3]
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r5, #0x1c]
	subs r0, r0, r1
_0815C1B6:
	strh r0, [r2]
	ldr r0, _0815C1DC
	adds r1, r4, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrh r0, [r1, #0xc]
	adds r0, #1
	strh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bne _0815C1E0
	strh r0, [r1, #8]
	b _0815C2D2
	.align 2, 0
_0815C1D4: .4byte 0x02022ACC
_0815C1D8: .4byte 0x085AD2AC
_0815C1DC: .4byte 0x03005B60
_0815C1E0:
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0815C2D2
_0815C1E8:
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r4, r0, r4
	ldrh r0, [r4, #0xa]
	subs r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _0815C202
	movs r0, #5
	strh r0, [r4, #0xa]
_0815C202:
	ldrh r1, [r4, #0xa]
	lsls r1, r1, #8
	movs r0, #3
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #5
	bne _0815C2D2
	b _0815C23E
_0815C21E:
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r4, r0, r4
	ldrh r1, [r4, #0xe]
	adds r1, #1
	strh r1, [r4, #0xe]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, _0815C248
	movs r3, #0xc
	ldrsh r0, [r4, r3]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r1, r0
	ble _0815C2D2
_0815C23E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0815C2D2
	.align 2, 0
_0815C248: .4byte 0x085AD2B0
_0815C24C:
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r4, r0, r4
	ldrh r0, [r4, #0xa]
	adds r0, #1
	strh r0, [r4, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xd
	ble _0815C266
	movs r0, #0xd
	strh r0, [r4, #0xa]
_0815C266:
	ldrh r1, [r4, #0xa]
	lsls r1, r1, #8
	movs r0, #3
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	cmp r0, #0xd
	bne _0815C2D2
	movs r0, #1
	strh r0, [r4, #8]
	b _0815C2D2
_0815C286:
	mov r0, sp
	bl sub_080A63F8
	mov r0, sp
	ldrb r0, [r0, #9]
	bl sub_080A6530
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815C2A8
	movs r0, #1
	movs r1, #3
	movs r2, #0
	bl SetAnimBgAttribute
_0815C2A8:
	movs r0, #1
	movs r1, #4
	movs r2, #1
	bl SetAnimBgAttribute
	ldr r0, _0815C2DC
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0815C2E0
	strh r1, [r0]
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x52
	movs r1, #0
	bl SetGpuReg
	adds r0, r6, #0
	bl DestroyAnimVisualTask
_0815C2D2:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0815C2DC: .4byte 0x02022ACC
_0815C2E0: .4byte 0x02022ACE
	thumb_func_end sub_0815BFE0

	.section .text.battle_anim_effects_3_rest6,"ax",%progbits








	thumb_func_start AnimTask_MonToSubstitute
AnimTask_MonToSubstitute: @ 0x0815F144
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r2, r5, #0
	ldr r0, _0815F188
	mov sb, r0
	lsls r7, r6, #2
	adds r0, r7, r6
	lsls r0, r0, #3
	mov r8, r0
	mov r4, r8
	add r4, sb
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0815F18C
	adds r0, r5, #0
	movs r1, #0
	bl PrepareBattlerSpriteForRotScale
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0xa]
	strh r0, [r4, #0xc]
	b _0815F1D8
	.align 2, 0
_0815F188: .4byte 0x03005B60
_0815F18C:
	cmp r0, #1
	bne _0815F1E4
	ldrh r0, [r4, #0xa]
	adds r0, #0x60
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #0xc]
	subs r0, #0xd
	strh r0, [r4, #0xc]
	movs r2, #0xa
	ldrsh r1, [r4, r2]
	movs r0, #0xc
	ldrsh r2, [r4, r0]
	adds r0, r5, #0
	movs r3, #0
	bl SetSpriteRotScale
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #9
	bne _0815F248
	movs r0, #0
	strh r0, [r4, #0xe]
	adds r0, r5, #0
	bl ResetSpriteRotScale
	ldr r1, _0815F1E0
	lsls r0, r5, #4
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
_0815F1D8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0815F248
	.align 2, 0
_0815F1E0: .4byte 0x020205AC
_0815F1E4:
	ldr r4, _0815F254
	ldrb r0, [r4]
	movs r1, #0
	bl LoadBattleMonGfxAndAnimate
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815F226
	ldr r3, _0815F258
	ldr r2, _0815F25C
	ldrb r0, [r4]
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r3, #0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r1, _0815F260
	str r1, [r0]
	ldrb r0, [r4]
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	movs r1, #0
	bl StartSpriteAffineAnim
_0815F226:
	mov r4, sb
	adds r3, r7, #0
	ldr r5, _0815F264
	movs r1, #0xf
	mov r2, r8
	adds r0, r4, r2
	adds r0, #0x26
	movs r2, #0
_0815F236:
	strh r2, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _0815F236
	adds r0, r3, r6
	lsls r0, r0, #3
	adds r0, r0, r4
	str r5, [r0]
_0815F248:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815F254: .4byte 0x020380D6
_0815F258: .4byte 0x020205AC
_0815F25C: .4byte 0x02023E88
_0815F260: .4byte 0x082D2F50
_0815F264: .4byte 0x0815F269
	thumb_func_end AnimTask_MonToSubstitute

	thumb_func_start AnimTask_MonToSubstituteDoll
AnimTask_MonToSubstituteDoll: @ 0x0815F268
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r1, _0815F294
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	adds r4, r0, r1
	movs r0, #8
	ldrsh r5, [r4, r0]
	cmp r5, #1
	beq _0815F2CC
	cmp r5, #1
	bgt _0815F298
	cmp r5, #0
	beq _0815F2A2
	b _0815F3BA
	.align 2, 0
_0815F294: .4byte 0x03005B60
_0815F298:
	cmp r5, #2
	beq _0815F338
	cmp r5, #3
	beq _0815F374
	b _0815F3BA
_0815F2A2:
	ldr r0, _0815F2C4
	lsls r1, r3, #4
	adds r1, r1, r3
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, _0815F2C8
	strh r0, [r1, #0x26]
	movs r0, #0xc8
	strh r0, [r1, #0x24]
	adds r1, #0x3e
	ldrb r2, [r1]
	subs r0, #0xcd
	ands r0, r2
	strb r0, [r1]
	strh r5, [r4, #0x1c]
	b _0815F366
	.align 2, 0
_0815F2C4: .4byte 0x020205AC
_0815F2C8: .4byte 0x0000FF38
_0815F2CC:
	ldrh r1, [r4, #0x1c]
	adds r1, #0x70
	movs r5, #0
	strh r1, [r4, #0x1c]
	ldr r2, _0815F330
	lsls r0, r3, #4
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r2, r0, r2
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	ldrh r3, [r2, #0x26]
	adds r1, r1, r3
	strh r1, [r2, #0x26]
	movs r1, #0x22
	ldrsh r0, [r2, r1]
	movs r3, #0x26
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	movs r1, #0x20
	rsbs r1, r1, #0
	cmp r0, r1
	blt _0815F2FC
	strh r5, [r2, #0x24]
_0815F2FC:
	movs r1, #0x26
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _0815F306
	strh r5, [r2, #0x26]
_0815F306:
	movs r3, #0x26
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne _0815F3BA
	movs r0, #0x40
	rsbs r0, r0, #0
	bl BattleAnimAdjustPanning
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x7d
	bl PlaySE12WithPanning
	ldr r1, _0815F334
	adds r0, r1, #0
	ldrh r2, [r4, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	b _0815F366
	.align 2, 0
_0815F330: .4byte 0x020205AC
_0815F334: .4byte 0xFFFFF800
_0815F338:
	ldrh r0, [r4, #0x1c]
	subs r0, #0x70
	strh r0, [r4, #0x1c]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0815F348
	movs r0, #0
	strh r0, [r4, #0x1c]
_0815F348:
	ldr r0, _0815F370
	lsls r1, r3, #4
	adds r1, r1, r3
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r2, [r4, #0x1c]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	ldrh r0, [r1, #0x26]
	subs r0, r0, r2
	strh r0, [r1, #0x26]
	movs r3, #0x1c
	ldrsh r0, [r4, r3]
	cmp r0, #0
	bne _0815F3BA
_0815F366:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0815F3BA
	.align 2, 0
_0815F370: .4byte 0x020205AC
_0815F374:
	ldrh r0, [r4, #0x1c]
	adds r0, #0x70
	strh r0, [r4, #0x1c]
	ldr r2, _0815F3C0
	lsls r1, r3, #4
	adds r1, r1, r3
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldrh r2, [r1, #0x26]
	adds r0, r0, r2
	strh r0, [r1, #0x26]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0815F398
	movs r0, #0
	strh r0, [r1, #0x26]
_0815F398:
	movs r3, #0x26
	ldrsh r0, [r1, r3]
	cmp r0, #0
	bne _0815F3BA
	movs r0, #0x40
	rsbs r0, r0, #0
	bl BattleAnimAdjustPanning
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x7d
	bl PlaySE12WithPanning
	adds r0, r6, #0
	bl DestroyAnimVisualTask
_0815F3BA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0815F3C0: .4byte 0x020205AC
	thumb_func_end AnimTask_MonToSubstituteDoll

	thumb_func_start AnimBlockX
AnimBlockX: @ 0x0815F3C4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _0815F3E8
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815F3F0
	ldrb r0, [r4]
	bl GetBattlerSpriteSubpriority
	subs r0, #2
	adds r1, r5, #0
	adds r1, #0x43
	strb r0, [r1]
	ldr r4, _0815F3EC
	b _0815F400
	.align 2, 0
_0815F3E8: .4byte 0x020380D7
_0815F3EC: .4byte 0x0000FF70
_0815F3F0:
	ldrb r0, [r4]
	bl GetBattlerSpriteSubpriority
	adds r0, #2
	adds r1, r5, #0
	adds r1, #0x43
	strb r0, [r1]
	ldr r4, _0815F41C
_0815F400:
	ldr r0, _0815F420
	ldrb r0, [r0]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x22]
	strh r4, [r5, #0x26]
	ldr r0, _0815F424
	str r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0815F41C: .4byte 0x0000FFA0
_0815F420: .4byte 0x020380D7
_0815F424: .4byte 0x0815F429
	thumb_func_end AnimBlockX

	thumb_func_start AnimBlockXStep
AnimBlockXStep: @ 0x0815F428
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #4
	bls _0815F436
	b _0815F552
_0815F436:
	lsls r0, r0, #2
	ldr r1, _0815F440
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815F440: .4byte 0x0815F444
_0815F444: @ jump table
	.4byte _0815F458 @ case 0
	.4byte _0815F47C @ case 1
	.4byte _0815F4BC @ case 2
	.4byte _0815F4EC @ case 3
	.4byte _0815F518 @ case 4
_0815F458:
	ldrh r0, [r4, #0x26]
	adds r0, #0xa
	strh r0, [r4, #0x26]
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _0815F552
	movs r0, #0x3f
	bl BattleAnimAdjustPanning
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0xcd
	bl PlaySE12WithPanning
	movs r0, #0
	strh r0, [r4, #0x26]
	b _0815F510
_0815F47C:
	ldrh r1, [r4, #0x30]
	adds r1, #4
	movs r5, #0
	strh r1, [r4, #0x30]
	ldr r2, _0815F4B8
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	rsbs r0, r0, #0
	strh r0, [r4, #0x26]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x7f
	ble _0815F552
	movs r0, #0x3f
	bl BattleAnimAdjustPanning
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0xcd
	bl PlaySE12WithPanning
	strh r5, [r4, #0x30]
	strh r5, [r4, #0x26]
	b _0815F510
	.align 2, 0
_0815F4B8: .4byte 0x082FA8CC
_0815F4BC:
	ldrh r1, [r4, #0x30]
	adds r1, #6
	movs r3, #0
	strh r1, [r4, #0x30]
	ldr r2, _0815F4E8
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	rsbs r0, r0, #0
	strh r0, [r4, #0x26]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	cmp r1, #0x7f
	ble _0815F552
	strh r3, [r4, #0x30]
	strh r3, [r4, #0x26]
	b _0815F510
	.align 2, 0
_0815F4E8: .4byte 0x082FA8CC
_0815F4EC:
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0815F552
	movs r0, #0x3f
	bl BattleAnimAdjustPanning
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0xc0
	bl PlaySE12WithPanning
	movs r0, #0
	strh r0, [r4, #0x30]
_0815F510:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	b _0815F552
_0815F518:
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _0815F552
	movs r0, #0
	strh r0, [r4, #0x30]
	ldrh r1, [r4, #0x32]
	adds r1, #1
	strh r1, [r4, #0x32]
	movs r0, #1
	ands r1, r0
	adds r3, r4, #0
	adds r3, #0x3e
	lsls r1, r1, #2
	ldrb r2, [r3]
	subs r0, #6
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #7
	bne _0815F552
	adds r0, r4, #0
	bl DestroyAnimSprite
_0815F552:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end AnimBlockXStep

	thumb_func_start AnimTask_OdorSleuthMovement
AnimTask_OdorSleuthMovement: @ 0x0815F558
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	bl IsContest
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	bne _0815F5A6
	movs r0, #1
	bl CloneBattlerSpriteWithBlend
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov sl, r1
	asrs r6, r0, #0x10
	cmp r6, #0
	blt _0815F5A6
	movs r0, #1
	bl CloneBattlerSpriteWithBlend
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov sb, r1
	asrs r1, r0, #0x10
	cmp r1, #0
	bge _0815F5B4
	lsls r0, r6, #4
	adds r0, r0, r6
	lsls r0, r0, #2
	ldr r1, _0815F5B0
	adds r0, r0, r1
	bl obj_delete_but_dont_free_vram
_0815F5A6:
	mov r0, r8
	bl DestroyAnimVisualTask
	b _0815F6B8
	.align 2, 0
_0815F5B0: .4byte 0x020205AC
_0815F5B4:
	ldr r4, _0815F644
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r5, r0, r4
	ldrh r0, [r5, #0x24]
	adds r0, #0x18
	strh r0, [r5, #0x24]
	lsls r0, r6, #4
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r6, r0, r4
	ldrh r0, [r6, #0x24]
	subs r0, #0x18
	strh r0, [r6, #0x24]
	strh r7, [r5, #0x2e]
	strh r7, [r6, #0x2e]
	strh r7, [r5, #0x30]
	strh r7, [r6, #0x30]
	strh r7, [r5, #0x32]
	strh r7, [r6, #0x32]
	movs r0, #0x10
	strh r0, [r5, #0x34]
	ldr r0, _0815F648
	strh r0, [r6, #0x34]
	strh r7, [r5, #0x36]
	movs r0, #0x80
	strh r0, [r6, #0x36]
	movs r0, #0x18
	strh r0, [r5, #0x38]
	strh r0, [r6, #0x38]
	mov r0, r8
	strh r0, [r5, #0x3a]
	strh r0, [r6, #0x3a]
	strh r7, [r5, #0x3c]
	strh r7, [r6, #0x3c]
	ldr r2, _0815F64C
	mov r1, r8
	lsls r3, r1, #2
	adds r0, r3, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r1, #2
	strh r1, [r0, #8]
	ldr r0, _0815F650
	ldr r1, [r0]
	ldr r0, _0815F654
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	adds r7, r4, #0
	mov ip, r3
	cmp r0, #0
	bne _0815F658
	adds r2, r5, #0
	adds r2, #0x3e
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r2, r6, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	b _0815F66E
	.align 2, 0
_0815F644: .4byte 0x020205AC
_0815F648: .4byte 0x0000FFF0
_0815F64C: .4byte 0x03005B60
_0815F650: .4byte 0x02024174
_0815F654: .4byte 0x020380D7
_0815F658:
	adds r1, r5, #0
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	adds r1, r6, #0
	adds r1, #0x3e
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
_0815F66E:
	mov r1, sb
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r4, r2, r7
	ldrb r1, [r4, #1]
	movs r3, #0xd
	rsbs r3, r3, #0
	adds r0, r3, #0
	ands r0, r1
	strb r0, [r4, #1]
	mov r1, sl
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r4, r1, r7
	ldrb r0, [r4, #1]
	ands r3, r0
	strb r3, [r4, #1]
	adds r3, r7, #0
	adds r3, #0x1c
	adds r2, r2, r3
	ldr r0, _0815F6C8
	str r0, [r2]
	adds r1, r1, r3
	str r0, [r1]
	mov r0, ip
	add r0, r8
	lsls r0, r0, #3
	ldr r1, _0815F6CC
	adds r0, r0, r1
	ldr r1, _0815F6D0
	str r1, [r0]
_0815F6B8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815F6C8: .4byte 0x0815F6FD
_0815F6CC: .4byte 0x03005B60
_0815F6D0: .4byte 0x0815F6D5
	thumb_func_end AnimTask_OdorSleuthMovement

	thumb_func_start AnimTask_OdorSleuthMovementWaitFinish
AnimTask_OdorSleuthMovementWaitFinish: @ 0x0815F6D4
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _0815F6F8
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r1, #8
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0815F6F2
	adds r0, r2, #0
	bl DestroyAnimVisualTask
_0815F6F2:
	pop {r0}
	bx r0
	.align 2, 0
_0815F6F8: .4byte 0x03005B60
	thumb_func_end AnimTask_OdorSleuthMovementWaitFinish

	thumb_func_start MoveOdorSleuthClone
MoveOdorSleuthClone: @ 0x0815F6FC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _0815F746
	movs r0, #0
	strh r0, [r4, #0x30]
	ldr r0, _0815F770
	ldr r1, [r0]
	ldr r0, _0815F774
	ldrb r0, [r0]
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0815F746
	adds r3, r4, #0
	adds r3, #0x3e
	ldrb r2, [r3]
	lsls r1, r2, #0x1d
	lsrs r1, r1, #0x1f
	movs r0, #1
	eors r1, r0
	ands r1, r0
	lsls r1, r1, #2
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
_0815F746:
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x36]
	adds r0, r0, r1
	movs r5, #0
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x36]
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, #0x24]
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _0815F778
	cmp r0, #1
	beq _0815F790
	b _0815F7CE
	.align 2, 0
_0815F770: .4byte 0x02024174
_0815F774: .4byte 0x020380D7
_0815F778:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x3c
	bne _0815F7CE
	strh r5, [r4, #0x32]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	b _0815F7CE
_0815F790:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0815F7CE
	strh r5, [r4, #0x32]
	ldrh r0, [r4, #0x38]
	subs r0, #2
	strh r0, [r4, #0x38]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0815F7CE
	ldr r3, _0815F7D4
	movs r2, #0x3c
	ldrsh r1, [r4, r2]
	lsls r1, r1, #1
	movs r0, #0x3a
	ldrsh r2, [r4, r0]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r3, #8
	adds r1, r1, r3
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	bl obj_delete_but_dont_free_vram
_0815F7CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0815F7D4: .4byte 0x03005B60
	thumb_func_end MoveOdorSleuthClone

	thumb_func_start AnimTask_GetReturnPowerLevel
AnimTask_GetReturnPowerLevel: @ 0x0815F7D8
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r3, _0815F824
	movs r2, #0
	strh r2, [r3, #0xe]
	ldr r1, _0815F828
	ldrb r0, [r1]
	ldrb r1, [r1]
	adds r0, r1, #0
	subs r0, #0x3d
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r1, #0
	cmp r0, #0x1e
	bhi _0815F7FC
	movs r0, #1
	strh r0, [r3, #0xe]
_0815F7FC:
	adds r0, r2, #0
	subs r0, #0x5c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x6c
	bhi _0815F80C
	movs r0, #2
	strh r0, [r3, #0xe]
_0815F80C:
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xc8
	bls _0815F818
	movs r0, #3
	strh r0, [r3, #0xe]
_0815F818:
	adds r0, r4, #0
	bl DestroyAnimVisualTask
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0815F824: .4byte 0x020380BE
_0815F828: .4byte 0x020380BA
	thumb_func_end AnimTask_GetReturnPowerLevel

	thumb_func_start AnimTask_SnatchOpposingMonMove
AnimTask_SnatchOpposingMonMove: @ 0x0815F82C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r1, _0815F85C
	lsls r0, r0, #2
	add r0, r8
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r1, #8
	ldrsh r0, [r0, r1]
	cmp r0, #4
	bls _0815F852
	b _0815FDA0
_0815F852:
	lsls r0, r0, #2
	ldr r1, _0815F860
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815F85C: .4byte 0x03005B60
_0815F860: .4byte 0x0815F864
_0815F864: @ jump table
	.4byte _0815F878 @ case 0
	.4byte _0815F92C @ case 1
	.4byte _0815FB20 @ case 2
	.4byte _0815FC40 @ case 3
	.4byte _0815FCC4 @ case 4
_0815F878:
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _0815F8C4
	mov r2, r8
	lsls r4, r2, #2
	adds r0, r4, r2
	lsls r0, r0, #3
	adds r6, r0, r1
	movs r3, #0x80
	lsls r3, r3, #4
	adds r0, r3, #0
	ldrh r1, [r6, #0xa]
	adds r0, r0, r1
	strh r0, [r6, #0xa]
	ldr r0, _0815F8C8
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	mov sb, r4
	cmp r0, #0
	bne _0815F8D0
	ldr r2, _0815F8CC
	lsls r3, r7, #4
	adds r1, r3, r7
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r0, [r6, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldrh r4, [r1, #0x24]
	adds r0, r0, r4
	strh r0, [r1, #0x24]
	b _0815F8EA
	.align 2, 0
_0815F8C4: .4byte 0x03005B60
_0815F8C8: .4byte 0x020380D6
_0815F8CC: .4byte 0x020205AC
_0815F8D0:
	ldr r3, _0815F924
	lsls r4, r7, #4
	adds r2, r4, r7
	lsls r2, r2, #2
	adds r2, r2, r3
	ldrh r1, [r6, #0xa]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	ldrh r0, [r2, #0x24]
	subs r0, r0, r1
	strh r0, [r2, #0x24]
	adds r2, r3, #0
	adds r3, r4, #0
_0815F8EA:
	ldr r1, _0815F928
	mov r0, sb
	add r0, r8
	lsls r0, r0, #3
	adds r4, r0, r1
	ldrb r0, [r4, #0xa]
	strh r0, [r4, #0xa]
	adds r1, r3, r7
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r0, [r1, #0x24]
	ldrh r1, [r1, #0x20]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0xe
	adds r0, r0, r1
	movs r1, #0x98
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0815F916
	b _0815FDA0
_0815F916:
	movs r0, #0
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _0815FDA0
	.align 2, 0
_0815F924: .4byte 0x020205AC
_0815F928: .4byte 0x03005B60
_0815F92C:
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0815F960
	ldr r0, _0815F958
	ldr r0, [r0]
	ldr r0, [r0, #0x18]
	ldr r2, [r0, #8]
	mov sl, r2
	ldr r3, [r0, #0xc]
	mov sb, r3
	ldrh r6, [r0]
	ldr r0, _0815F95C
	ldrb r0, [r0]
	bl GetBattlerSpriteSubpriority
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r7, #0
	b _0815FA86
	.align 2, 0
_0815F958: .4byte 0x02039BD4
_0815F95C: .4byte 0x020380D6
_0815F960:
	ldr r4, _0815F9C4
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815FA00
	ldr r7, _0815F9C8
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _0815F9CC
	adds r0, r0, r5
	movs r1, #0
	bl GetMonData3
	mov sl, r0
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	muls r0, r6, r0
	adds r0, r0, r5
	movs r1, #1
	bl GetMonData3
	mov sb, r0
	ldr r0, _0815F9D0
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, #2
	adds r1, r0, r1
	ldrh r0, [r1, #2]
	cmp r0, #0
	bne _0815F9D4
	lsls r0, r2, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	muls r0, r6, r0
	adds r0, r0, r5
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	b _0815F9D6
	.align 2, 0
_0815F9C4: .4byte 0x020380D6
_0815F9C8: .4byte 0x02023D12
_0815F9CC: .4byte 0x02024190
_0815F9D0: .4byte 0x02024174
_0815F9D4:
	ldrh r6, [r1, #2]
_0815F9D6:
	movs r0, #1
	bl GetAnimBattlerSpriteId
	ldr r2, _0815F9FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	adds r1, #0x43
	ldrb r0, [r1]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r7, #0
	movs r5, #0x88
	lsls r5, r5, #1
	b _0815FA88
	.align 2, 0
_0815F9FC: .4byte 0x020205AC
_0815FA00:
	ldr r7, _0815FA58
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _0815FA5C
	adds r0, r0, r5
	movs r1, #0
	bl GetMonData3
	mov sl, r0
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	muls r0, r6, r0
	adds r0, r0, r5
	movs r1, #1
	bl GetMonData3
	mov sb, r0
	ldr r0, _0815FA60
	ldr r0, [r0]
	ldrb r2, [r4]
	ldr r1, [r0]
	lsls r0, r2, #2
	adds r1, r0, r1
	ldrh r0, [r1, #2]
	cmp r0, #0
	bne _0815FA64
	lsls r0, r2, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	muls r0, r6, r0
	adds r0, r0, r5
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	b _0815FA66
	.align 2, 0
_0815FA58: .4byte 0x02023D12
_0815FA5C: .4byte 0x020243E8
_0815FA60: .4byte 0x02024174
_0815FA64:
	ldrh r6, [r1, #2]
_0815FA66:
	movs r0, #1
	bl GetAnimBattlerSpriteId
	ldr r2, _0815FB04
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	adds r1, #0x43
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r7, #1
_0815FA86:
	ldr r5, _0815FB08
_0815FA88:
	ldr r0, _0815FB0C
	ldrb r0, [r0]
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r3, r5, #0x10
	asrs r3, r3, #0x10
	str r0, [sp]
	str r4, [sp, #4]
	mov r4, sl
	str r4, [sp, #8]
	mov r0, sb
	str r0, [sp, #0xc]
	ldr r4, _0815FB10
	ldrb r0, [r4]
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl CreateAdditionalMonSpriteForMoveAnim
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _0815FB14
	ldr r1, [r0]
	ldrb r0, [r4]
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _0815FAF2
	ldr r1, _0815FB04
	lsls r0, r5, #4
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	orrs r0, r1
	ldr r3, _0815FB18
	movs r1, #0x10
	movs r2, #6
	bl BlendPalette
_0815FAF2:
	ldr r0, _0815FB1C
	mov r3, r8
	lsls r1, r3, #2
	add r1, r8
	lsls r1, r1, #3
	adds r1, r1, r0
	strh r5, [r1, #0x26]
	b _0815FCB6
	.align 2, 0
_0815FB04: .4byte 0x020205AC
_0815FB08: .4byte 0x0000FFE0
_0815FB0C: .4byte 0x020380D7
_0815FB10: .4byte 0x020380D6
_0815FB14: .4byte 0x02024174
_0815FB18: .4byte 0x00007FFF
_0815FB1C: .4byte 0x03005B60
_0815FB20:
	ldr r1, _0815FB6C
	mov r0, r8
	lsls r4, r0, #2
	adds r0, r4, r0
	lsls r0, r0, #3
	adds r6, r0, r1
	ldrh r0, [r6, #0x26]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r1, #0
	ldrh r2, [r6, #0xa]
	adds r0, r0, r2
	strh r0, [r6, #0xa]
	ldr r0, _0815FB70
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	mov sb, r4
	cmp r0, #0
	bne _0815FB78
	ldr r3, _0815FB74
	lsls r4, r5, #4
	adds r2, r4, r5
	lsls r2, r2, #2
	adds r2, r2, r3
	ldrh r1, [r6, #0xa]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	ldrh r0, [r2, #0x24]
	subs r0, r0, r1
	strh r0, [r2, #0x24]
	adds r2, r3, #0
	adds r3, r4, #0
	b _0815FB8E
	.align 2, 0
_0815FB6C: .4byte 0x03005B60
_0815FB70: .4byte 0x020380D6
_0815FB74: .4byte 0x020205AC
_0815FB78:
	ldr r2, _0815FBDC
	lsls r3, r5, #4
	adds r1, r3, r5
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r0, [r6, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldrh r4, [r1, #0x24]
	adds r0, r0, r4
	strh r0, [r1, #0x24]
_0815FB8E:
	ldr r1, _0815FBE0
	mov r0, sb
	add r0, r8
	lsls r0, r0, #3
	adds r6, r0, r1
	ldrb r0, [r6, #0xa]
	strh r0, [r6, #0xa]
	adds r1, r3, r5
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r0, [r1, #0x24]
	ldrh r1, [r1, #0x20]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _0815FC0E
	ldr r0, _0815FBE4
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815FBEC
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	ldr r0, _0815FBE8
	ldrb r0, [r0]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	bge _0815FC0E
	b _0815FC02
	.align 2, 0
_0815FBDC: .4byte 0x020205AC
_0815FBE0: .4byte 0x03005B60
_0815FBE4: .4byte 0x020380D6
_0815FBE8: .4byte 0x020380D7
_0815FBEC:
	lsls r4, r5, #0x10
	asrs r4, r4, #0x10
	ldr r0, _0815FC30
	ldrb r0, [r0]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	ble _0815FC0E
_0815FC02:
	ldrh r0, [r6, #0x24]
	adds r0, #1
	strh r0, [r6, #0x24]
	ldr r1, _0815FC34
	ldr r0, _0815FC38
	strh r0, [r1, #0xe]
_0815FC0E:
	lsls r0, r5, #0x10
	movs r2, #0x80
	lsls r2, r2, #0xe
	adds r0, r0, r2
	movs r1, #0x98
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _0815FC20
	b _0815FDA0
_0815FC20:
	ldr r0, _0815FC3C
	mov r1, sb
	add r1, r8
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1, #0xa]
	b _0815FCB6
	.align 2, 0
_0815FC30: .4byte 0x020380D7
_0815FC34: .4byte 0x020380BE
_0815FC38: .4byte 0x0000FFFF
_0815FC3C: .4byte 0x03005B60
_0815FC40:
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _0815FC8C
	mov r3, r8
	lsls r4, r3, #2
	adds r0, r4, r3
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #0x26]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #4
	adds r0, r0, r5
	lsls r0, r0, #2
	ldr r5, _0815FC90
	adds r0, r0, r5
	bl DestroySpriteAndFreeResources_
	ldr r0, _0815FC94
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	mov sb, r4
	cmp r0, #0
	bne _0815FC98
	lsls r1, r7, #4
	adds r1, r1, r7
	lsls r1, r1, #2
	adds r1, r1, r5
	ldrh r0, [r1, #0x20]
	rsbs r0, r0, #0
	subs r0, #0x20
	strh r0, [r1, #0x24]
	b _0815FCAC
	.align 2, 0
_0815FC8C: .4byte 0x03005B60
_0815FC90: .4byte 0x020205AC
_0815FC94: .4byte 0x020380D6
_0815FC98:
	lsls r0, r7, #4
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrh r2, [r0, #0x20]
	movs r4, #0x88
	lsls r4, r4, #1
	adds r1, r4, #0
	subs r1, r1, r2
	strh r1, [r0, #0x24]
_0815FCAC:
	ldr r0, _0815FCC0
	mov r1, sb
	add r1, r8
	lsls r1, r1, #3
	adds r1, r1, r0
_0815FCB6:
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0815FDA0
	.align 2, 0
_0815FCC0: .4byte 0x03005B60
_0815FCC4:
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r1, _0815FD38
	mov r0, r8
	lsls r4, r0, #2
	adds r0, r4, r0
	lsls r0, r0, #3
	adds r2, r0, r1
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r1, #0
	ldrh r3, [r2, #0xa]
	adds r0, r0, r3
	strh r0, [r2, #0xa]
	ldr r0, _0815FD3C
	mov sl, r0
	ldrb r0, [r0]
	str r2, [sp, #0x18]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	mov sb, r4
	ldr r2, [sp, #0x18]
	cmp r0, #0
	bne _0815FD44
	ldr r1, _0815FD40
	lsls r5, r7, #4
	adds r0, r5, r7
	lsls r0, r0, #2
	adds r6, r0, r1
	ldrh r0, [r2, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	ldrh r1, [r6, #0x24]
	adds r0, r0, r1
	strh r0, [r6, #0x24]
	movs r2, #0x24
	ldrsh r4, [r6, r2]
	movs r3, #0x20
	ldrsh r0, [r6, r3]
	adds r4, r4, r0
	mov r1, sl
	ldrb r0, [r1]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r5, #0
	cmp r4, r0
	blt _0815FD7C
	movs r2, #0
	strh r2, [r6, #0x24]
	b _0815FD7C
	.align 2, 0
_0815FD38: .4byte 0x03005B60
_0815FD3C: .4byte 0x020380D6
_0815FD40: .4byte 0x020205AC
_0815FD44:
	ldr r1, _0815FDB0
	lsls r5, r7, #4
	adds r0, r5, r7
	lsls r0, r0, #2
	adds r6, r0, r1
	ldrh r1, [r2, #0xa]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	ldrh r0, [r6, #0x24]
	subs r0, r0, r1
	strh r0, [r6, #0x24]
	movs r3, #0x24
	ldrsh r4, [r6, r3]
	movs r1, #0x20
	ldrsh r0, [r6, r1]
	adds r4, r4, r0
	mov r2, sl
	ldrb r0, [r2]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r5, #0
	cmp r4, r0
	bgt _0815FD7C
	movs r4, #0
	strh r4, [r6, #0x24]
_0815FD7C:
	ldr r1, _0815FDB4
	mov r0, sb
	add r0, r8
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrb r1, [r0, #0xa]
	strh r1, [r0, #0xa]
	ldr r1, _0815FDB0
	adds r0, r3, r7
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0x24
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _0815FDA0
	mov r0, r8
	bl DestroyAnimVisualTask
_0815FDA0:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0815FDB0: .4byte 0x020205AC
_0815FDB4: .4byte 0x03005B60
	thumb_func_end AnimTask_SnatchOpposingMonMove

	thumb_func_start sub_0815FDB8
sub_0815FDB8: @ 0x0815FDB8
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _0815FDCA
	cmp r0, #1
	beq _0815FE72
	b _0815FEF4
_0815FDCA:
	ldr r0, _0815FE50
	movs r2, #0xe
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _0815FE64
	movs r0, #0x3f
	bl BattleAnimAdjustPanning
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	movs r0, #0x7a
	bl PlaySE12WithPanning
	ldr r0, _0815FE54
	ldrb r0, [r0]
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x10
	strh r0, [r4, #0x22]
	ldr r0, _0815FE58
	strh r0, [r4, #0x2e]
	ldrh r0, [r4, #0x3c]
	adds r0, #1
	strh r0, [r4, #0x3c]
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, _0815FE5C
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0815FEF4
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815FEF4
	movs r0, #1
	bl GetAnimBattlerSpriteId
	ldr r2, _0815FE60
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	adds r1, #0x43
	ldrb r0, [r1]
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0x43
	strb r0, [r1]
	b _0815FEF4
	.align 2, 0
_0815FE50: .4byte 0x020380BE
_0815FE54: .4byte 0x020380D7
_0815FE58: .4byte 0x0000FFE0
_0815FE5C: .4byte 0x020380D6
_0815FE60: .4byte 0x020205AC
_0815FE64:
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	b _0815FEF4
_0815FE72:
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	movs r2, #0x2e
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, #0x26]
	ldrh r2, [r4, #0x30]
	adds r0, r2, #5
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7f
	ble _0815FEA6
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	strh r0, [r4, #0x2e]
	ldrh r0, [r4, #0x34]
	adds r0, #1
	strh r0, [r4, #0x34]
	adds r0, r2, #0
	subs r0, #0x7a
	strh r0, [r4, #0x30]
_0815FEA6:
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r4, #0x32]
	adds r0, r0, r1
	strh r0, [r4, #0x32]
	ldr r0, _0815FED0
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0815FED4
	ldrh r2, [r4, #0x32]
	lsls r1, r2, #0x10
	asrs r1, r1, #0x18
	ldrh r0, [r4, #0x24]
	subs r0, r0, r1
	strh r0, [r4, #0x24]
	adds r1, r2, #0
	b _0815FEE0
	.align 2, 0
_0815FED0: .4byte 0x020380D6
_0815FED4:
	ldrh r1, [r4, #0x32]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	ldrh r2, [r4, #0x24]
	adds r0, r0, r2
	strh r0, [r4, #0x24]
_0815FEE0:
	movs r0, #0xff
	ands r0, r1
	strh r0, [r4, #0x32]
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	cmp r0, #2
	bne _0815FEF4
	adds r0, r4, #0
	bl DestroyAnimSprite
_0815FEF4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0815FDB8

	thumb_func_start AnimTask_SnatchPartnerMove
AnimTask_SnatchPartnerMove: @ 0x0815FEFC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _0815FF24
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #0x26
	ldrsh r0, [r0, r2]
	adds r3, r1, #0
	cmp r0, #4
	bls _0815FF18
	b _0816006A
_0815FF18:
	lsls r0, r0, #2
	ldr r1, _0815FF28
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0815FF24: .4byte 0x03005B60
_0815FF28: .4byte 0x0815FF2C
_0815FF2C: @ jump table
	.4byte _0815FF40 @ case 0
	.4byte _0815FF90 @ case 1
	.4byte _0815FFEC @ case 2
	.4byte _08160004 @ case 3
	.4byte _0816006A @ case 4
_0815FF40:
	ldr r0, _0815FF84
	ldrb r0, [r0]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r5, r0, #0
	ldr r0, _0815FF88
	ldrb r0, [r0]
	movs r1, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	ldr r1, _0815FF8C
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r1, r0, r1
	movs r0, #6
	strh r0, [r1, #8]
	cmp r5, r2
	ble _0815FF76
	rsbs r0, r0, #0
	strh r0, [r1, #8]
_0815FF76:
	strh r5, [r1, #0xa]
	strh r2, [r1, #0xc]
	ldrh r0, [r1, #0x26]
	adds r0, #1
	strh r0, [r1, #0x26]
	b _08160088
	.align 2, 0
_0815FF84: .4byte 0x020380D6
_0815FF88: .4byte 0x020380D7
_0815FF8C: .4byte 0x03005B60
_0815FF90:
	ldr r1, _0815FFCC
	ldr r0, _0815FFD0
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r1, _0815FFD4
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r0, r1
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r2, r0, r3
	ldrh r0, [r2, #8]
	ldrh r3, [r1, #0x24]
	adds r0, r0, r3
	strh r0, [r1, #0x24]
	movs r3, #8
	ldrsh r0, [r2, r3]
	cmp r0, #0
	ble _0815FFD8
	movs r3, #0x20
	ldrsh r0, [r1, r3]
	movs r3, #0x24
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	movs r3, #0xc
	ldrsh r1, [r2, r3]
	b _0816005E
	.align 2, 0
_0815FFCC: .4byte 0x02023E88
_0815FFD0: .4byte 0x020380D6
_0815FFD4: .4byte 0x020205AC
_0815FFD8:
	movs r3, #0x20
	ldrsh r0, [r1, r3]
	movs r3, #0x24
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	movs r3, #0xc
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _08160088
	b _08160062
_0815FFEC:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r3
	movs r2, #8
	ldrsh r1, [r0, r2]
	rsbs r1, r1, #0
	strh r1, [r0, #8]
	ldrh r1, [r0, #0x26]
	adds r1, #1
	strh r1, [r0, #0x26]
	b _08160088
_08160004:
	ldr r1, _08160044
	ldr r0, _08160048
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r1, _0816004C
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r0, r1
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r2, r0, r3
	ldrh r0, [r2, #8]
	ldrh r3, [r1, #0x24]
	adds r0, r0, r3
	strh r0, [r1, #0x24]
	movs r3, #8
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bge _08160050
	movs r3, #0x20
	ldrsh r0, [r1, r3]
	movs r3, #0x24
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	cmp r0, r1
	bgt _08160088
	b _08160062
	.align 2, 0
_08160044: .4byte 0x02023E88
_08160048: .4byte 0x020380D6
_0816004C: .4byte 0x020205AC
_08160050:
	movs r3, #0x20
	ldrsh r0, [r1, r3]
	movs r3, #0x24
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	movs r3, #0xa
	ldrsh r1, [r2, r3]
_0816005E:
	cmp r0, r1
	blt _08160088
_08160062:
	ldrh r0, [r2, #0x26]
	adds r0, #1
	strh r0, [r2, #0x26]
	b _08160088
_0816006A:
	ldr r1, _08160090
	ldr r0, _08160094
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r2, [r0]
	ldr r1, _08160098
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0, #0x24]
	adds r0, r4, #0
	bl DestroyAnimVisualTask
_08160088:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08160090: .4byte 0x02023E88
_08160094: .4byte 0x020380D6
_08160098: .4byte 0x020205AC
	thumb_func_end AnimTask_SnatchPartnerMove

	thumb_func_start AnimTask_TeeterDanceMovement
AnimTask_TeeterDanceMovement: @ 0x0816009C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _08160104
	adds r4, r1, r0
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r5, #0
	strh r0, [r4, #0xe]
	ldr r0, _08160108
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	cmp r0, #0
	bne _081600D0
	movs r1, #1
_081600D0:
	strh r1, [r4, #0x10]
	ldr r2, _0816010C
	movs r0, #0xe
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #0x22]
	strh r0, [r4, #0x14]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r0, [r0, #0x20]
	strh r0, [r4, #0x12]
	strh r5, [r4, #0x1a]
	strh r5, [r4, #0x1e]
	movs r0, #1
	strh r0, [r4, #0x1c]
	strh r5, [r4, #0x20]
	ldr r0, _08160110
	str r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08160104: .4byte 0x03005B60
_08160108: .4byte 0x020380D6
_0816010C: .4byte 0x020205AC
_08160110: .4byte 0x08160115
	thumb_func_end AnimTask_TeeterDanceMovement

	thumb_func_start AnimTask_TeeterDanceMovementStep
AnimTask_TeeterDanceMovementStep: @ 0x08160114
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	ldr r1, _08160138
	adds r4, r0, r1
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq _081601BC
	cmp r0, #1
	bgt _0816013C
	cmp r0, #0
	beq _08160142
	b _08160212
	.align 2, 0
_08160138: .4byte 0x03005B60
_0816013C:
	cmp r0, #2
	beq _0816020C
	b _08160212
_08160142:
	ldrh r0, [r4, #0x1e]
	adds r0, #8
	movs r2, #0xff
	ands r0, r2
	strh r0, [r4, #0x1e]
	ldr r5, _081601B4
	movs r6, #0xe
	ldrsh r0, [r4, r6]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	ldr r3, _081601B8
	movs r6, #0x1e
	ldrsh r0, [r4, r6]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x15
	strh r0, [r1, #0x24]
	ldrh r0, [r4, #0x1a]
	adds r0, #2
	ands r0, r2
	strh r0, [r4, #0x1a]
	movs r1, #0xe
	ldrsh r0, [r4, r1]
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r5
	movs r6, #0x1a
	ldrsh r0, [r4, r6]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x13
	ldrh r1, [r4, #0x10]
	muls r0, r1, r0
	ldrh r1, [r4, #0x12]
	adds r0, r0, r1
	strh r0, [r2, #0x20]
	movs r6, #0x1a
	ldrsh r0, [r4, r6]
	cmp r0, #0
	bne _08160212
	movs r0, #0xe
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrh r1, [r4, #0x12]
	strh r1, [r0, #0x20]
	b _081601FC
	.align 2, 0
_081601B4: .4byte 0x020205AC
_081601B8: .4byte 0x082FA8CC
_081601BC:
	ldrh r0, [r4, #0x1e]
	adds r0, #8
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x1e]
	ldr r3, _08160204
	movs r1, #0xe
	ldrsh r0, [r4, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r2, _08160208
	movs r5, #0x1e
	ldrsh r0, [r4, r5]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x15
	strh r0, [r1, #0x24]
	movs r6, #0x1e
	ldrsh r2, [r4, r6]
	cmp r2, #0
	bne _08160212
	movs r1, #0xe
	ldrsh r0, [r4, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r3
	strh r2, [r1, #0x24]
_081601FC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _08160212
	.align 2, 0
_08160204: .4byte 0x020205AC
_08160208: .4byte 0x082FA8CC
_0816020C:
	adds r0, r2, #0
	bl DestroyAnimVisualTask
_08160212:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end AnimTask_TeeterDanceMovementStep

	thumb_func_start AnimKnockOffStrikeStep
AnimKnockOffStrikeStep: @ 0x08160218
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0816026C
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x30]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x30]
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	movs r1, #0x14
	bl Cos
	strh r0, [r4, #0x24]
	movs r1, #0x30
	ldrsh r0, [r4, r1]
	movs r1, #0x14
	bl Sin
	strh r0, [r4, #0x26]
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0816025E
	adds r0, r4, #0
	bl DestroyAnimSprite
_0816025E:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0816026C: .4byte 0x020380D7
	thumb_func_end AnimKnockOffStrikeStep

	thumb_func_start AnimKnockOffStrike
AnimKnockOffStrike: @ 0x08160270
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081602A8
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081602B4
	ldr r2, _081602AC
	ldrh r0, [r4, #0x20]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x22]
	ldr r0, _081602B0
	strh r0, [r4, #0x2e]
	movs r0, #0xc0
	strh r0, [r4, #0x30]
	adds r0, r4, #0
	movs r1, #1
	bl StartSpriteAffineAnim
	b _081602CE
	.align 2, 0
_081602A8: .4byte 0x020380D7
_081602AC: .4byte 0x020380BE
_081602B0: .4byte 0x0000FFF5
_081602B4:
	movs r0, #0xb
	strh r0, [r4, #0x2e]
	movs r0, #0xc0
	strh r0, [r4, #0x30]
	ldr r1, _081602D8
	ldrh r0, [r1]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
	ldrh r0, [r1, #2]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x22]
_081602CE:
	ldr r0, _081602DC
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081602D8: .4byte 0x020380BE
_081602DC: .4byte 0x08160219
	thumb_func_end AnimKnockOffStrike

	thumb_func_start AnimRecycle
AnimRecycle: @ 0x081602E0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _08160324
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoordAttr
	strh r0, [r5, #0x22]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xf
	bgt _0816030A
	movs r0, #0x10
	strh r0, [r5, #0x22]
_0816030A:
	movs r0, #0
	strh r0, [r5, #0x3a]
	movs r1, #0x10
	strh r1, [r5, #0x3c]
	ldr r0, _08160328
	str r0, [r5, #0x1c]
	lsls r1, r1, #8
	movs r0, #0x52
	bl SetGpuReg
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08160324: .4byte 0x020380D6
_08160328: .4byte 0x0816032D
	thumb_func_end AnimRecycle

	thumb_func_start AnimRecycleStep
AnimRecycleStep: @ 0x0816032C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	cmp r1, #1
	beq _081603A4
	cmp r1, #1
	bgt _08160342
	cmp r1, #0
	beq _0816034C
	b _08160420
_08160342:
	cmp r1, #2
	beq _081603BA
	cmp r1, #3
	beq _0816041A
	b _08160420
_0816034C:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08160420
	strh r1, [r4, #0x2e]
	ldrh r1, [r4, #0x30]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08160376
	ldrh r2, [r4, #0x3a]
	movs r3, #0x3a
	ldrsh r0, [r4, r3]
	cmp r0, #0xf
	bgt _08160384
	adds r0, r2, #1
	strh r0, [r4, #0x3a]
	b _08160384
_08160376:
	ldrh r2, [r4, #0x3c]
	movs r3, #0x3c
	ldrsh r0, [r4, r3]
	cmp r0, #0
	beq _08160384
	subs r0, r2, #1
	strh r0, [r4, #0x3c]
_08160384:
	adds r0, r1, #1
	strh r0, [r4, #0x30]
	ldrh r1, [r4, #0x3c]
	lsls r1, r1, #8
	ldrh r0, [r4, #0x3a]
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08160420
	b _08160412
_081603A4:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xa
	bne _08160420
	strh r1, [r4, #0x2e]
	strh r1, [r4, #0x30]
	b _08160412
_081603BA:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	ble _08160420
	movs r0, #0
	strh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x30]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081603E6
	ldrh r2, [r4, #0x3a]
	movs r3, #0x3a
	ldrsh r0, [r4, r3]
	cmp r0, #0
	beq _081603F4
	subs r0, r2, #1
	strh r0, [r4, #0x3a]
	b _081603F4
_081603E6:
	ldrh r2, [r4, #0x3c]
	movs r3, #0x3c
	ldrsh r0, [r4, r3]
	cmp r0, #0xf
	bgt _081603F4
	adds r0, r2, #1
	strh r0, [r4, #0x3c]
_081603F4:
	adds r0, r1, #1
	strh r0, [r4, #0x30]
	ldrh r1, [r4, #0x3c]
	lsls r1, r1, #8
	ldrh r0, [r4, #0x3a]
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x52
	bl SetGpuReg
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	cmp r0, #0x10
	bne _08160420
_08160412:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	b _08160420
_0816041A:
	adds r0, r4, #0
	bl DestroySpriteAndMatrix
_08160420:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end AnimRecycleStep

	thumb_func_start AnimTask_GetWeather
AnimTask_GetWeather: @ 0x08160428
	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r2, _08160444
	movs r0, #0
	strh r0, [r2, #0xe]
	ldr r0, _08160448
	ldrh r1, [r0]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	beq _0816044C
	movs r0, #1
	b _0816046E
	.align 2, 0
_08160444: .4byte 0x020380BE
_08160448: .4byte 0x020380BC
_0816044C:
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _08160458
	movs r0, #2
	b _0816046E
_08160458:
	movs r0, #0x18
	ands r0, r1
	cmp r0, #0
	beq _08160464
	movs r0, #3
	b _0816046E
_08160464:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08160470
	movs r0, #4
_0816046E:
	strh r0, [r2, #0xe]
_08160470:
	adds r0, r3, #0
	bl DestroyAnimVisualTask
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end AnimTask_GetWeather

	thumb_func_start AnimTask_SlackOffSquish
AnimTask_SlackOffSquish: @ 0x0816047C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #3
	ldr r0, _081604B4
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4, #8]
	ldr r0, _081604B8
	ldrb r0, [r0]
	bl GetAnimBattlerSpriteId
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	strh r1, [r4, #0x26]
	ldr r2, _081604BC
	adds r0, r4, #0
	bl PrepareAffineAnimInTaskData
	ldr r0, _081604C0
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081604B4: .4byte 0x03005B60
_081604B8: .4byte 0x020380BE
_081604BC: .4byte 0x085AD7D0
_081604C0: .4byte 0x081604C5
	thumb_func_end AnimTask_SlackOffSquish

	thumb_func_start AnimTask_SlackOffSquishStep
AnimTask_SlackOffSquishStep: @ 0x081604C4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r2, _0816051C
	adds r3, r0, r2
	ldrh r0, [r3, #8]
	adds r1, r0, #1
	movs r5, #0
	strh r1, [r3, #8]
	subs r0, #0x10
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r6, r2, #0
	cmp r0, #0x16
	bhi _08160528
	ldrh r0, [r3, #0xa]
	adds r0, #1
	strh r0, [r3, #0xa]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #2
	ble _08160538
	strh r5, [r3, #0xa]
	ldrh r0, [r3, #0xc]
	adds r0, #1
	strh r0, [r3, #0xc]
	movs r5, #1
	ands r0, r5
	cmp r0, #0
	bne _08160528
	ldr r2, _08160520
	movs r0, #0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, _08160524
	strh r1, [r0, #0x24]
	b _08160538
	.align 2, 0
_0816051C: .4byte 0x03005B60
_08160520: .4byte 0x020205AC
_08160524: .4byte 0x0000FFFF
_08160528:
	ldr r2, _08160558
	movs r0, #0x26
	ldrsh r1, [r3, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	strh r5, [r0, #0x24]
_08160538:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r6
	bl RunAffineAnimFromTaskData
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08160550
	adds r0, r4, #0
	bl DestroyAnimVisualTask
_08160550:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08160558: .4byte 0x020205AC
	thumb_func_end AnimTask_SlackOffSquishStep
