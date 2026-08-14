.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_080970C8
sub_080970C8: @ 0x080970C8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _080970FE
	cmp r0, #1
	bgt _080970E0
	cmp r0, #0
	beq _080970EA
	b _08097162
_080970E0:
	cmp r0, #2
	beq _08097126
	cmp r0, #3
	beq _0809713A
	b _08097162
_080970EA:
	movs r2, #0x3a
	ldrsh r0, [r5, r2]
	bl GetFigure8XOffset
	ldrh r1, [r5, #0x24]
	adds r0, r0, r1
	strh r0, [r5, #0x24]
	movs r2, #0x3a
	ldrsh r0, [r5, r2]
	b _08097158
_080970FE:
	ldrh r0, [r5, #0x3a]
	movs r4, #0x47
	subs r0, r4, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl GetFigure8XOffset
	ldrh r1, [r5, #0x24]
	subs r1, r1, r0
	strh r1, [r5, #0x24]
	ldrh r0, [r5, #0x3a]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	bl GetFigure8YOffset
	ldrh r2, [r5, #0x26]
	adds r0, r0, r2
	b _08097160
_08097126:
	movs r1, #0x3a
	ldrsh r0, [r5, r1]
	bl GetFigure8XOffset
	ldrh r1, [r5, #0x24]
	subs r1, r1, r0
	strh r1, [r5, #0x24]
	movs r2, #0x3a
	ldrsh r0, [r5, r2]
	b _08097158
_0809713A:
	ldrh r0, [r5, #0x3a]
	movs r4, #0x47
	subs r0, r4, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl GetFigure8XOffset
	ldrh r2, [r5, #0x24]
	adds r0, r0, r2
	strh r0, [r5, #0x24]
	ldrh r0, [r5, #0x3a]
	subs r4, r4, r0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
_08097158:
	bl GetFigure8YOffset
	ldrh r1, [r5, #0x26]
	adds r0, r0, r1
_08097160:
	strh r0, [r5, #0x26]
_08097162:
	ldrh r0, [r5, #0x3a]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #0x3a]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x48
	bne _0809717A
	strh r1, [r5, #0x3a]
	ldrh r0, [r5, #0x3c]
	adds r0, #1
	strh r0, [r5, #0x3c]
_0809717A:
	movs r2, #0x3c
	ldrsh r0, [r5, r2]
	cmp r0, #4
	bne _08097188
	strh r1, [r5, #0x26]
	strh r1, [r5, #0x24]
	movs r6, #1
_08097188:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_080970C8

	thumb_func_start sub_08097190
sub_08097190: @ 0x08097190
	lsls r1, r1, #0x18
	ldr r2, _080971A8
	lsrs r1, r1, #0x16
	adds r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldr r1, [r1]
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	bx lr
	.align 2, 0
_080971A8: .4byte 0x084E6C88
	thumb_func_end sub_08097190

	thumb_func_start sub_080971AC
sub_080971AC: @ 0x080971AC
	push {r4, lr}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r4, #0
	strh r1, [r0, #0x34]
	strh r2, [r0, #0x36]
	strh r3, [r0, #0x38]
	strh r4, [r0, #0x3a]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080971AC

	thumb_func_start sub_080971CC
sub_080971CC: @ 0x080971CC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _0809724C
	mov r0, sp
	movs r2, #6
	bl memcpy
	add r5, sp, #8
	ldr r1, _08097250
	adds r0, r5, #0
	movs r2, #3
	bl memcpy
	movs r6, #0
	movs r1, #0x36
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _080971FE
	ldrh r1, [r4, #0x34]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl Step1
_080971FE:
	movs r2, #0x3a
	ldrsh r0, [r4, r2]
	movs r2, #0x36
	ldrsh r1, [r4, r2]
	adds r1, r5, r1
	ldrb r1, [r1]
	asrs r0, r1
	ldrh r1, [r4, #0x38]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_08097190
	strh r0, [r4, #0x26]
	ldrh r1, [r4, #0x3a]
	adds r1, #1
	strh r1, [r4, #0x3a]
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	asrs r0, r0, #0x11
	cmp r1, r0
	bne _08097238
	movs r6, #1
_08097238:
	cmp r1, r2
	blt _08097242
	movs r0, #0
	strh r0, [r4, #0x26]
	movs r6, #0xff
_08097242:
	adds r0, r6, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809724C: .4byte 0x084E6C94
_08097250: .4byte 0x084E6C9A
	thumb_func_end sub_080971CC

	thumb_func_start sub_08097254
sub_08097254: @ 0x08097254
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r1, _080972E0
	mov r0, sp
	movs r2, #6
	bl memcpy
	add r4, sp, #8
	ldr r1, _080972E4
	adds r0, r4, #0
	movs r2, #3
	bl memcpy
	movs r6, #0
	movs r1, #0x36
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq _08097290
	ldrh r1, [r5, #0x3a]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08097290
	ldrh r1, [r5, #0x34]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	bl Step1
_08097290:
	movs r2, #0x3a
	ldrsh r0, [r5, r2]
	movs r2, #0x36
	ldrsh r1, [r5, r2]
	adds r1, r4, r1
	ldrb r1, [r1]
	asrs r0, r1
	ldrh r1, [r5, #0x38]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl sub_08097190
	strh r0, [r5, #0x26]
	ldrh r1, [r5, #0x3a]
	adds r1, #1
	strh r1, [r5, #0x3a]
	movs r2, #0x36
	ldrsh r0, [r5, r2]
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	asrs r0, r0, #0x11
	cmp r1, r0
	bne _080972CA
	movs r6, #1
_080972CA:
	cmp r1, r2
	blt _080972D4
	movs r0, #0
	strh r0, [r5, #0x26]
	movs r6, #0xff
_080972D4:
	adds r0, r6, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080972E0: .4byte 0x084E6C9E
_080972E4: .4byte 0x084E6CA4
	thumb_func_end sub_08097254

	thumb_func_start SetMovementDelay
SetMovementDelay: @ 0x080972E8
	strh r1, [r0, #0x34]
	bx lr
	thumb_func_end SetMovementDelay

	thumb_func_start WaitForMovementDelay
WaitForMovementDelay: @ 0x080972EC
	push {lr}
	ldrh r1, [r0, #0x34]
	subs r1, #1
	strh r1, [r0, #0x34]
	lsls r1, r1, #0x10
	cmp r1, #0
	beq _080972FE
	movs r0, #0
	b _08097300
_080972FE:
	movs r0, #1
_08097300:
	pop {r1}
	bx r1
	thumb_func_end WaitForMovementDelay

	thumb_func_start SetAndStartSpriteAnim
SetAndStartSpriteAnim: @ 0x08097304
	push {r4, lr}
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r3, r0, #0
	adds r3, #0x2a
	strb r1, [r3]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrb r3, [r4]
	movs r1, #0x41
	rsbs r1, r1, #0
	ands r1, r3
	strb r1, [r4]
	adds r1, r2, #0
	bl SeekSpriteAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end SetAndStartSpriteAnim

	thumb_func_start SpriteAnimEnded
SpriteAnimEnded: @ 0x0809732C
	push {lr}
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0809733E
	movs r0, #0
	b _08097340
_0809733E:
	movs r0, #1
_08097340:
	pop {r1}
	bx r1
	thumb_func_end SpriteAnimEnded

	thumb_func_start UpdateObjectEventSpriteInvisibility
UpdateObjectEventSpriteInvisibility: @ 0x08097344
	push {r4, r5, r6, lr}
	mov ip, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r3, ip
	adds r3, #0x3e
	movs r0, #1
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _080973AC
	mov r0, ip
	ldrh r1, [r0, #0x24]
	ldrh r2, [r0, #0x20]
	adds r1, r1, r2
	mov r4, ip
	adds r4, #0x28
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldr r2, _080973A4
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, ip
	ldrh r1, [r0, #0x26]
	ldrh r2, [r0, #0x22]
	adds r1, r1, r2
	subs r3, #0x15
	movs r0, #0
	ldrsb r0, [r3, r0]
	ldr r2, _080973A8
	adds r0, r0, r1
	ldrh r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r2, r3, #0
	b _080973DA
	.align 2, 0
_080973A4: .4byte 0x02021B38
_080973A8: .4byte 0x02021B3A
_080973AC:
	mov r0, ip
	ldrh r1, [r0, #0x24]
	ldrh r2, [r0, #0x20]
	adds r1, r1, r2
	mov r3, ip
	adds r3, #0x28
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, ip
	ldrh r1, [r0, #0x26]
	ldrh r2, [r0, #0x22]
	adds r1, r1, r2
	mov r2, ip
	adds r2, #0x29
	movs r0, #0
	ldrsb r0, [r2, r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r4, r3, #0
_080973DA:
	ldrb r0, [r4]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x19
	subs r0, r6, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldrb r0, [r2]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x19
	subs r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	bgt _08097406
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x10
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08097412
_08097406:
	mov r4, ip
	adds r4, #0x3e
	ldrb r0, [r4]
	movs r1, #4
	orrs r0, r1
	strb r0, [r4]
_08097412:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xaf
	bgt _08097426
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x10
	rsbs r1, r1, #0
	cmp r0, r1
	bge _08097432
_08097426:
	mov r0, ip
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
_08097432:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end UpdateObjectEventSpriteInvisibility

	thumb_func_start UpdateEventObjectSpriteSubpriorityAndVisibility
UpdateEventObjectSpriteSubpriorityAndVisibility: @ 0x08097438
	push {r4, lr}
	adds r4, r0, #0
	bl sub_080976D8
	ldrh r0, [r4, #0x30]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r4, #0
	movs r2, #1
	bl SetObjectSubpriorityByElevation
	ldrh r1, [r4, #0x32]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl UpdateObjectEventSpriteInvisibility
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end UpdateEventObjectSpriteSubpriorityAndVisibility

	thumb_func_start sub_08097460
sub_08097460: @ 0x08097460
	push {r4, r5, lr}
	movs r5, #0
	movs r4, #0x3f
_08097466:
	ldr r0, _08097494
	adds r2, r5, r0
	adds r0, r2, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08097486
	ldr r1, [r2, #0x1c]
	ldr r0, _08097498
	cmp r1, r0
	bne _08097486
	adds r0, r2, #0
	bl DestroySprite
_08097486:
	adds r5, #0x44
	subs r4, #1
	cmp r4, #0
	bge _08097466
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08097494: .4byte 0x020205AC
_08097498: .4byte 0x08097439
	thumb_func_end sub_08097460

	thumb_func_start sub_0809749C
sub_0809749C: @ 0x0809749C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r3, #0
	ldr r6, _080974D0
	movs r4, #0
_080974A8:
	adds r2, r4, r6
	adds r0, r2, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080974D8
	ldr r1, [r2, #0x1c]
	ldr r0, _080974D4
	cmp r1, r0
	bne _080974D8
	ldrh r0, [r2, #0x2e]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	bne _080974D8
	adds r0, r3, #0
	b _080974E2
	.align 2, 0
_080974D0: .4byte 0x020205AC
_080974D4: .4byte 0x08097439
_080974D8:
	adds r4, #0x44
	adds r3, #1
	cmp r3, #0x3f
	ble _080974A8
	movs r0, #0x40
_080974E2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_0809749C

	thumb_func_start sub_080974E8
sub_080974E8: @ 0x080974E8
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	bl sub_0809749C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	beq _0809751A
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	ldr r0, _08097520
	adds r4, r4, r0
	adds r0, r5, #0
	bl GetJumpInPlaceMovementAction
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
_0809751A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08097520: .4byte 0x020205AC
	thumb_func_end sub_080974E8

	thumb_func_start sub_08097524
sub_08097524: @ 0x08097524
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	bl sub_0809749C
	adds r1, r0, #0
	cmp r1, #0x40
	beq _080975AE
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _08097588
	adds r4, r0, r1
	adds r0, r5, #0
	bl GetObjectEventGraphicsInfo
	ldrh r3, [r4, #4]
	lsls r3, r3, #0x16
	ldr r1, [r0, #0x10]
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [r4]
	str r2, [r4, #4]
	lsrs r3, r3, #0x16
	ldrh r2, [r4, #4]
	ldr r1, _0809758C
	ands r1, r2
	orrs r1, r3
	strh r1, [r4, #4]
	ldrb r2, [r0, #0xc]
	lsls r2, r2, #0x1c
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #5]
	movs r1, #0xf
	ands r1, r3
	orrs r1, r2
	strb r1, [r4, #5]
	ldr r1, [r0, #0x1c]
	str r1, [r4, #0xc]
	ldr r1, [r0, #0x14]
	cmp r1, #0
	bne _08097590
	str r1, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0x42
	strb r1, [r0]
	b _080975A6
	.align 2, 0
_08097588: .4byte 0x020205AC
_0809758C: .4byte 0xFFFFFC00
_08097590:
	adds r0, r4, #0
	bl SetSubspriteTables
	adds r2, r4, #0
	adds r2, #0x42
	ldrb r0, [r2]
	movs r1, #0x3f
	ands r1, r0
	movs r0, #0x80
	orrs r1, r0
	strb r1, [r2]
_080975A6:
	adds r0, r4, #0
	movs r1, #0
	bl StartSpriteAnim
_080975AE:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08097524

	thumb_func_start sub_080975B4
sub_080975B4: @ 0x080975B4
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0809749C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, r2, #0
	cmp r2, #0x40
	beq _080975F0
	cmp r4, #0
	beq _080975E4
	ldr r0, _080975E0
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #1
	strh r0, [r1, #0x32]
	b _080975F0
	.align 2, 0
_080975E0: .4byte 0x020205AC
_080975E4:
	ldr r1, _080975F8
	lsls r0, r3, #4
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r1
	strh r4, [r0, #0x32]
_080975F0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080975F8: .4byte 0x020205AC
	thumb_func_end sub_080975B4

	thumb_func_start sub_080975FC
sub_080975FC: @ 0x080975FC
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0809749C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	bne _08097612
	movs r0, #0
	b _0809762A
_08097612:
	movs r3, #0
	ldr r0, _08097630
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r2, #0x32
	ldrsh r0, [r1, r2]
	cmp r0, #1
	bne _08097628
	movs r3, #1
_08097628:
	adds r0, r3, #0
_0809762A:
	pop {r1}
	bx r1
	.align 2, 0
_08097630: .4byte 0x020205AC
	thumb_func_end sub_080975FC

	thumb_func_start sub_08097634
sub_08097634: @ 0x08097634
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	bl sub_0809749C
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x40
	beq _0809765A
	ldr r0, _08097660
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	movs r0, #0
	strh r4, [r1, #0x34]
	strh r0, [r1, #0x36]
_0809765A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08097660: .4byte 0x020205AC
	thumb_func_end sub_08097634

	thumb_func_start sub_08097664
sub_08097664: @ 0x08097664
	push {lr}
	adds r2, r0, #0
	movs r1, #0x36
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _08097676
	cmp r0, #1
	beq _0809767E
	b _0809769C
_08097676:
	strh r0, [r2, #0x26]
	ldrh r0, [r2, #0x36]
	adds r0, #1
	strh r0, [r2, #0x36]
_0809767E:
	ldrh r0, [r2, #0x26]
	subs r0, #8
	movs r3, #0
	strh r0, [r2, #0x26]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xa0
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0809769C
	strh r3, [r2, #0x26]
	movs r0, #1
	strh r0, [r2, #0x32]
	strh r3, [r2, #0x34]
	strh r3, [r2, #0x36]
_0809769C:
	pop {r0}
	bx r0
	thumb_func_end sub_08097664

	thumb_func_start sub_080976A0
sub_080976A0: @ 0x080976A0
	push {lr}
	adds r1, r0, #0
	movs r2, #0x36
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080976B2
	cmp r0, #1
	beq _080976BC
	b _080976CE
_080976B2:
	ldr r0, _080976D4
	strh r0, [r1, #0x26]
	ldrh r0, [r1, #0x36]
	adds r0, #1
	strh r0, [r1, #0x36]
_080976BC:
	ldrh r0, [r1, #0x26]
	adds r0, #8
	strh r0, [r1, #0x26]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _080976CE
	strh r0, [r1, #0x34]
	strh r0, [r1, #0x36]
_080976CE:
	pop {r0}
	bx r0
	.align 2, 0
_080976D4: .4byte 0x0000FF60
	thumb_func_end sub_080976A0

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
