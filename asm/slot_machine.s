.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_0812F3C4
sub_0812F3C4: @ 0x0812F3C4
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _0812F3D6
	cmp r0, #1
	beq _0812F426
	b _0812F478
_0812F3D6:
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r4, #0x30]
	adds r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x20
	ble _0812F478
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	movs r0, #5
	strh r0, [r4, #0x30]
	ldrb r0, [r4, #1]
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r4, #1]
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #1
	bl StartSpriteAnim
	ldrh r0, [r4, #0x30]
	lsls r1, r0, #4
	orrs r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x10
	movs r0, #0x4c
	bl SetGpuReg
	b _0812F478
_0812F426:
	ldrh r1, [r4, #0x32]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	ldrh r0, [r4, #0x30]
	subs r0, r0, r1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0812F43C
	movs r0, #0
	strh r0, [r4, #0x30]
_0812F43C:
	ldrh r0, [r4, #0x30]
	lsls r1, r0, #4
	orrs r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x10
	movs r0, #0x4c
	bl SetGpuReg
	ldrh r1, [r4, #0x32]
	movs r0, #0xff
	ands r0, r1
	adds r0, #0x80
	strh r0, [r4, #0x32]
	movs r0, #0x30
	ldrsh r1, [r4, r0]
	cmp r1, #0
	bne _0812F478
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	strh r1, [r4, #0x3c]
	ldrb r1, [r4, #1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r4, #1]
	adds r0, r4, #0
	movs r1, #0
	bl StartSpriteAnim
_0812F478:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0812F3C4

	thumb_func_start sub_0812F480
sub_0812F480: @ 0x0812F480
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	cmp r0, #2
	bgt _0812F4D0
	ldr r1, _0812F4CC
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #6
	bl IndexOfSpritePaletteTag
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #4
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r1, r1, r0
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #0x20
	bl LoadPalette
	ldrh r0, [r5, #0x32]
	adds r0, #1
	strh r0, [r5, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0812F50C
	ldrh r0, [r5, #0x30]
	adds r0, #1
	strh r0, [r5, #0x30]
	movs r0, #0
	strh r0, [r5, #0x32]
	b _0812F50C
	.align 2, 0
_0812F4CC: .4byte 0x08585614
_0812F4D0:
	ldr r1, _0812F520
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #6
	bl IndexOfSpritePaletteTag
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #4
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r1, r1, r0
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #0x20
	bl LoadPalette
	ldrh r0, [r5, #0x32]
	adds r0, #1
	movs r1, #0
	strh r0, [r5, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x18
	ble _0812F50C
	strh r1, [r5, #0x30]
	strh r1, [r5, #0x32]
_0812F50C:
	adds r0, r5, #0
	movs r1, #1
	bl StartSpriteAnimIfDifferent
	movs r0, #0
	strh r0, [r5, #0x3c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0812F520: .4byte 0x08585614
	thumb_func_end sub_0812F480

	thumb_func_start sub_0812F524
sub_0812F524: @ 0x0812F524
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r4, r0, #0
	ldr r1, _0812F560
	mov r0, sp
	movs r2, #0x10
	bl memcpy
	add r6, sp, #0x10
	ldr r1, _0812F564
	adds r0, r6, #0
	movs r2, #0x10
	bl memcpy
	add r5, sp, #0x20
	ldr r1, _0812F568
	adds r0, r5, #0
	movs r2, #0x10
	bl memcpy
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq _0812F59C
	cmp r0, #1
	bgt _0812F56C
	cmp r0, #0
	beq _0812F572
	b _0812F5E8
	.align 2, 0
_0812F560: .4byte 0x085845B2
_0812F564: .4byte 0x085845C2
_0812F568: .4byte 0x085845D2
_0812F56C:
	cmp r0, #2
	beq _0812F5B0
	b _0812F5E8
_0812F572:
	movs r2, #0x3a
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4, #0x24]
	movs r1, #0x3a
	ldrsh r0, [r4, r1]
	lsls r0, r0, #1
	adds r0, r6, r0
	ldrh r0, [r0]
	strh r0, [r4, #0x26]
	movs r2, #0x3a
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	adds r0, r5, r0
	ldrh r0, [r0]
	strh r0, [r4, #0x30]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
_0812F59C:
	ldrh r0, [r4, #0x30]
	subs r0, #1
	strh r0, [r4, #0x30]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0812F5E8
	b _0812F5E2
_0812F5B0:
	ldrh r0, [r4, #0x24]
	movs r2, #0x24
	ldrsh r1, [r4, r2]
	cmp r1, #0
	ble _0812F5BE
	subs r0, #4
	b _0812F5C4
_0812F5BE:
	cmp r1, #0
	bge _0812F5C6
	adds r0, #4
_0812F5C4:
	strh r0, [r4, #0x24]
_0812F5C6:
	ldrh r0, [r4, #0x26]
	movs r2, #0x26
	ldrsh r1, [r4, r2]
	cmp r1, #0
	ble _0812F5D4
	subs r0, #4
	b _0812F5DA
_0812F5D4:
	cmp r1, #0
	bge _0812F5DC
	adds r0, #4
_0812F5DA:
	strh r0, [r4, #0x26]
_0812F5DC:
	ldr r0, [r4, #0x24]
	cmp r0, #0
	bne _0812F5E8
_0812F5E2:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
_0812F5E8:
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_0812F524

	thumb_func_start sub_0812F5F0
sub_0812F5F0: @ 0x0812F5F0
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r1, _0812F654
	mov r0, sp
	movs r2, #0x10
	bl memcpy
	ldrh r1, [r4, #0x2e]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _0812F612
	adds r0, r1, #1
	strh r0, [r4, #0x2e]
	movs r0, #0xc
	strh r0, [r4, #0x30]
_0812F612:
	movs r1, #0x3a
	ldrsh r0, [r4, r1]
	lsls r0, r0, #1
	add r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	bl Cos
	strh r0, [r4, #0x24]
	movs r1, #0x3a
	ldrsh r0, [r4, r1]
	lsls r0, r0, #1
	add r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, #0x26]
	ldrh r1, [r4, #0x30]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	cmp r0, #0
	beq _0812F64C
	subs r0, r1, #1
	strh r0, [r4, #0x30]
_0812F64C:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812F654: .4byte 0x085845E2
	thumb_func_end sub_0812F5F0

	thumb_func_start sub_0812F658
sub_0812F658: @ 0x0812F658
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _0812F6A4
	cmp r0, #1
	bgt _0812F670
	cmp r0, #0
	beq _0812F67A
	b _0812F77C
_0812F670:
	cmp r0, #2
	beq _0812F6F0
	cmp r0, #3
	beq _0812F72C
	b _0812F77C
_0812F67A:
	ldr r0, _0812F6E8
	ldr r2, [r0]
	adds r1, r2, #0
	adds r1, #0x5c
	movs r0, #0x2f
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x3f
	strh r0, [r1]
	subs r1, #4
	ldr r0, _0812F6EC
	strh r0, [r1]
	adds r2, r5, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
_0812F6A4:
	ldrh r0, [r5, #0x30]
	adds r2, r0, #2
	strh r2, [r5, #0x30]
	adds r0, #0xb2
	strh r0, [r5, #0x32]
	movs r1, #0xf0
	subs r1, r1, r2
	strh r1, [r5, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xd0
	ble _0812F6C0
	movs r0, #0xd0
	strh r0, [r5, #0x32]
_0812F6C0:
	movs r1, #0x34
	ldrsh r0, [r5, r1]
	cmp r0, #0xcf
	bgt _0812F6CC
	movs r0, #0xd0
	strh r0, [r5, #0x34]
_0812F6CC:
	ldr r0, _0812F6E8
	ldr r2, [r0]
	ldrh r0, [r5, #0x32]
	lsls r0, r0, #8
	ldrh r1, [r5, #0x34]
	orrs r0, r1
	adds r1, r2, #0
	adds r1, #0x58
	strh r0, [r1]
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	cmp r0, #0x33
	ble _0812F77C
	b _0812F76E
	.align 2, 0
_0812F6E8: .4byte 0x0203A800
_0812F6EC: .4byte 0x00002088
_0812F6F0:
	ldr r6, _0812F784
	ldr r0, [r6]
	movs r1, #0x12
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _0812F77C
	ldr r1, _0812F788
	movs r4, #0
	str r4, [sp]
	movs r0, #5
	movs r2, #0xd0
	movs r3, #0x74
	bl sub_0812DF78
	ldr r2, [r6]
	adds r1, r2, #0
	adds r1, #0x58
	ldr r0, _0812F78C
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xd1
	lsls r0, r0, #7
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x2f
	strh r0, [r1]
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	strh r4, [r5, #0x30]
_0812F72C:
	ldrh r0, [r5, #0x30]
	adds r2, r0, #2
	strh r2, [r5, #0x30]
	adds r0, #0xc2
	strh r0, [r5, #0x32]
	movs r1, #0xe0
	subs r1, r1, r2
	strh r1, [r5, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xd0
	ble _0812F748
	movs r0, #0xd0
	strh r0, [r5, #0x32]
_0812F748:
	movs r1, #0x34
	ldrsh r0, [r5, r1]
	cmp r0, #0xcf
	bgt _0812F754
	movs r0, #0xd0
	strh r0, [r5, #0x34]
_0812F754:
	ldr r0, _0812F784
	ldr r2, [r0]
	ldrh r0, [r5, #0x32]
	lsls r0, r0, #8
	ldrh r1, [r5, #0x34]
	orrs r0, r1
	adds r1, r2, #0
	adds r1, #0x58
	strh r0, [r1]
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	cmp r0, #0xf
	ble _0812F77C
_0812F76E:
	ldrh r0, [r5, #0x2e]
	adds r0, #1
	strh r0, [r5, #0x2e]
	adds r1, r2, #0
	adds r1, #0x5c
	movs r0, #0x3f
	strh r0, [r1]
_0812F77C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812F784: .4byte 0x0203A800
_0812F788: .4byte 0x08007141
_0812F78C: .4byte 0x0000C0E0
	thumb_func_end sub_0812F658

	thumb_func_start sub_0812F790
sub_0812F790: @ 0x0812F790
	bx lr
	.align 2, 0
	thumb_func_end sub_0812F790

	thumb_func_start sub_0812F794
sub_0812F794: @ 0x0812F794
	push {lr}
	movs r0, #0x4c
	movs r1, #0
	bl SetGpuReg
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0812F794

	thumb_func_start sub_0812F7A4
sub_0812F7A4: @ 0x0812F7A4
	push {r4, lr}
	ldr r0, _0812F7CC
	ldr r4, [r0]
	movs r0, #6
	bl IndexOfSpritePaletteTag
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #4
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r1, r1, r0
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #0x20
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812F7CC: .4byte 0x08585624
	thumb_func_end sub_0812F7A4

	thumb_func_start sub_0812F7D0
sub_0812F7D0: @ 0x0812F7D0
	ldr r0, _0812F7F0
	ldr r2, [r0]
	adds r1, r2, #0
	adds r1, #0x58
	movs r0, #0xf0
	strh r0, [r1]
	adds r1, #2
	movs r0, #0xa0
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x5c
	movs r1, #0x3f
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	bx lr
	.align 2, 0
_0812F7F0: .4byte 0x0203A800
	thumb_func_end sub_0812F7D0

	thumb_func_start sub_0812F7F4
sub_0812F7F4: @ 0x0812F7F4
	push {r4, r5, r6, lr}
	bl sub_0812F8B0
	ldr r4, _0812F894
	movs r0, #0xc8
	lsls r0, r0, #6
	bl Alloc
	adds r1, r0, #0
	str r1, [r4]
	ldr r0, _0812F898
	bl LZDecompressVram
	ldr r4, _0812F89C
	movs r0, #0xd8
	lsls r0, r0, #6
	bl Alloc
	adds r1, r0, #0
	str r1, [r4]
	ldr r0, _0812F8A0
	bl LZDecompressVram
	ldr r4, _0812F8A4
	movs r0, #0xb0
	bl AllocZeroed
	str r0, [r4]
	movs r3, #0
	ldr r5, _0812F8A8
	adds r6, r4, #0
_0812F832:
	ldr r2, [r4]
	lsls r1, r3, #3
	adds r2, r1, r2
	adds r1, r1, r5
	ldr r0, [r1]
	str r0, [r2]
	ldrh r0, [r1, #4]
	strh r0, [r2, #4]
	ldrh r0, [r1, #6]
	strh r0, [r2, #6]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x15
	bls _0812F832
	ldr r3, [r6]
	adds r2, r3, #0
	adds r2, #0x88
	ldr r0, _0812F894
	ldr r1, [r0]
	movs r4, #0xa0
	lsls r4, r4, #4
	adds r0, r1, r4
	str r0, [r2]
	adds r2, #8
	movs r4, #0xa0
	lsls r4, r4, #5
	adds r0, r1, r4
	str r0, [r2]
	adds r2, #8
	movs r4, #0xb0
	lsls r4, r4, #5
	adds r0, r1, r4
	str r0, [r2]
	adds r0, r3, #0
	adds r0, #0xa0
	movs r2, #0xc8
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r0]
	adds r0, r3, #0
	bl LoadSpriteSheets
	ldr r0, _0812F8AC
	bl LoadSpritePalettes
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812F894: .4byte 0x0203A7A0
_0812F898: .4byte 0x08585690
_0812F89C: .4byte 0x0203A7A4
_0812F8A0: .4byte 0x08585DF8
_0812F8A4: .4byte 0x0203A7FC
_0812F8A8: .4byte 0x085852B8
_0812F8AC: .4byte 0x08585648
	thumb_func_end sub_0812F7F4

	thumb_func_start sub_0812F8B0
sub_0812F8B0: @ 0x0812F8B0
	push {r4, r5, r6, lr}
	ldr r5, _0812F90C
	movs r0, #8
	bl AllocZeroed
	str r0, [r5]
	ldr r4, _0812F910
	movs r0, #0x80
	lsls r0, r0, #6
	bl AllocZeroed
	str r0, [r4]
	adds r3, r0, #0
	movs r1, #0
	adds r6, r4, #0
	ldr r0, _0812F914
	ldr r4, [r0]
_0812F8D2:
	movs r2, #0
	adds r1, #1
_0812F8D6:
	adds r0, r4, r2
	ldrb r0, [r0]
	strb r0, [r3]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r3, #1
	cmp r2, #0x1f
	bls _0812F8D6
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x3f
	bls _0812F8D2
	ldr r0, [r5]
	ldr r1, [r6]
	str r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	strh r1, [r0, #4]
	movs r1, #0x11
	strh r1, [r0, #6]
	bl LoadSpriteSheet
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812F90C: .4byte 0x0203A7F8
_0812F910: .4byte 0x0203A7AC
_0812F914: .4byte 0x08585368
	thumb_func_end sub_0812F8B0

	thumb_func_start sub_0812F918
sub_0812F918: @ 0x0812F918
	push {r4, lr}
	ldr r4, _0812F958
	movs r0, #0x80
	lsls r0, r0, #6
	bl Alloc
	adds r1, r0, #0
	str r1, [r4]
	ldr r0, _0812F95C
	bl LZDecompressVram
	ldr r1, [r4]
	movs r2, #0xe9
	lsls r2, r2, #5
	movs r0, #2
	movs r3, #0
	bl LoadBgTiles
	ldr r0, _0812F960
	movs r1, #0
	movs r2, #0xa0
	bl LoadPalette
	ldr r0, _0812F964
	movs r1, #0xd0
	movs r2, #0x20
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812F958: .4byte 0x0203A794
_0812F95C: .4byte 0x08586F4C
_0812F960: .4byte 0x0858544C
_0812F964: .4byte 0x08585628
	thumb_func_end sub_0812F918

	thumb_func_start sub_0812F968
sub_0812F968: @ 0x0812F968
	push {lr}
	bl sub_0812F978
	bl LoadSlotMachineWheelOverlay
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0812F968

	thumb_func_start sub_0812F978
sub_0812F978: @ 0x0812F978
	push {r4, lr}
	movs r4, #0
_0812F97C:
	lsls r1, r4, #4
	subs r1, r1, r4
	lsls r1, r1, #2
	ldr r0, _0812F9A0
	adds r1, r1, r0
	lsls r3, r4, #5
	movs r0, #2
	movs r2, #0x3c
	bl LoadBgTilemap
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x13
	bls _0812F97C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812F9A0: .4byte 0x08587AEC
	thumb_func_end sub_0812F978

	thumb_func_start LoadSlotMachineWheelOverlay
LoadSlotMachineWheelOverlay: @ 0x0812F9A4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #4
	ldr r0, _0812FA98
	mov r8, r0
_0812F9B2:
	movs r0, #0
	lsls r1, r1, #0x10
	mov sb, r1
_0812F9B8:
	mov r2, r8
	ldr r1, [r2]
	mov r2, sb
	asrs r6, r2, #0x10
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	adds r5, r6, r4
	adds r3, r5, #0
	adds r3, #0xa0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #3
	movs r2, #2
	bl LoadBgTilemap
	mov r0, r8
	ldr r1, [r0]
	adds r1, #2
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r3, r5, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #3
	movs r2, #2
	bl LoadBgTilemap
	mov r0, r8
	ldr r1, [r0]
	adds r1, #4
	adds r3, r5, #0
	adds r3, #0xc0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #3
	movs r2, #2
	bl LoadBgTilemap
	mov r2, r8
	ldr r1, [r2]
	adds r1, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r7, r0, #0
	adds r3, r5, r7
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #3
	movs r2, #2
	bl LoadBgTilemap
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #3
	ble _0812F9B8
	mov r2, r8
	ldr r1, [r2]
	adds r1, #8
	adds r3, r6, #0
	adds r3, #0xc0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #3
	movs r2, #2
	bl LoadBgTilemap
	mov r0, r8
	ldr r1, [r0]
	adds r1, #0xa
	adds r3, r6, r7
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #3
	movs r2, #2
	bl LoadBgTilemap
	movs r0, #7
_0812FA56:
	mov r2, r8
	ldr r1, [r2]
	adds r1, #0xc
	lsls r4, r0, #0x10
	asrs r4, r4, #0x10
	lsls r3, r4, #5
	mov r0, sb
	asrs r5, r0, #0x10
	adds r3, r5, r3
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #3
	movs r2, #2
	bl LoadBgTilemap
	adds r4, #1
	lsls r4, r4, #0x10
	lsrs r0, r4, #0x10
	asrs r4, r4, #0x10
	cmp r4, #0xb
	ble _0812FA56
	adds r0, r5, #5
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x11
	ble _0812F9B2
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0812FA98: .4byte 0x0203A79C
	thumb_func_end LoadSlotMachineWheelOverlay

	thumb_func_start sub_0812FA9C
sub_0812FA9C: @ 0x0812FA9C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r5, [sp, #0x10]
	ldr r6, _0812FB0C
	ldr r0, [r6]
	strh r1, [r0]
	ldr r1, [r6]
	strh r2, [r1, #2]
	strh r3, [r1, #4]
	strh r5, [r1, #6]
	lsls r4, r4, #0x10
	asrs r5, r4, #0x10
	movs r0, #0xf0
	lsls r0, r0, #0x11
	adds r4, r4, r0
	lsrs r4, r4, #0x10
	movs r0, #2
	movs r2, #2
	adds r3, r4, #0
	bl LoadBgTilemap
	ldr r1, [r6]
	adds r1, #2
	ldr r0, _0812FB10
	adds r3, r5, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #2
	movs r2, #2
	bl LoadBgTilemap
	ldr r1, [r6]
	adds r1, #4
	movs r0, #0x80
	lsls r0, r0, #2
	adds r3, r5, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	movs r0, #2
	movs r2, #2
	bl LoadBgTilemap
	ldr r1, [r6]
	adds r1, #6
	ldr r0, _0812FB14
	adds r5, r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r0, #2
	movs r2, #2
	adds r3, r5, #0
	bl LoadBgTilemap
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812FB0C: .4byte 0x0203A7A8
_0812FB10: .4byte 0x000001E1
_0812FB14: .4byte 0x00000201
	thumb_func_end sub_0812FA9C

	thumb_func_start sub_0812FB18
sub_0812FB18: @ 0x0812FB18
	push {r4, lr}
	movs r4, #0
_0812FB1C:
	lsls r1, r4, #4
	subs r1, r1, r4
	lsls r1, r1, #2
	ldr r0, _0812FB48
	adds r1, r1, r0
	lsls r3, r4, #5
	movs r0, #2
	movs r2, #0x3c
	bl LoadBgTilemap
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x13
	bls _0812FB1C
	movs r0, #3
	bl HideBg
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0812FB48: .4byte 0x08588154
	thumb_func_end sub_0812FB18

	thumb_func_start SlotMachineSetup_9_0
SlotMachineSetup_9_0: @ 0x0812FB4C
	ldr r1, _0812FBC0
	ldr r0, _0812FBC4
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, _0812FBC8
	ldr r0, [r0]
	str r0, [r1, #4]
	ldr r0, _0812FBCC
	ldr r0, [r0]
	str r0, [r1, #8]
	ldr r0, _0812FBD0
	ldr r0, [r0]
	str r0, [r1, #0xc]
	ldr r0, _0812FBD4
	ldr r0, [r0]
	str r0, [r1, #0x10]
	ldr r0, _0812FBD8
	ldr r0, [r0]
	str r0, [r1, #0x14]
	ldr r0, _0812FBDC
	ldr r0, [r0]
	str r0, [r1, #0x18]
	ldr r0, _0812FBE0
	ldr r0, [r0]
	str r0, [r1, #0x1c]
	ldr r0, _0812FBE4
	ldr r0, [r0]
	str r0, [r1, #0x20]
	ldr r0, _0812FBE8
	ldr r0, [r0]
	str r0, [r1, #0x24]
	ldr r0, _0812FBEC
	ldr r0, [r0]
	str r0, [r1, #0x28]
	str r0, [r1, #0x2c]
	str r0, [r1, #0x30]
	str r0, [r1, #0x34]
	ldr r0, _0812FBF0
	ldr r0, [r0]
	str r0, [r1, #0x38]
	str r0, [r1, #0x3c]
	str r0, [r1, #0x40]
	str r0, [r1, #0x44]
	str r0, [r1, #0x48]
	ldr r0, _0812FBF4
	ldr r0, [r0]
	str r0, [r1, #0x4c]
	str r0, [r1, #0x50]
	str r0, [r1, #0x54]
	ldr r0, _0812FBF8
	ldr r0, [r0]
	str r0, [r1, #0x58]
	str r0, [r1, #0x5c]
	str r0, [r1, #0x60]
	movs r0, #0
	str r0, [r1, #0x64]
	bx lr
	.align 2, 0
_0812FBC0: .4byte 0x03001188
_0812FBC4: .4byte 0x0203A7C0
_0812FBC8: .4byte 0x0203A7C4
_0812FBCC: .4byte 0x0203A7C8
_0812FBD0: .4byte 0x0203A7D0
_0812FBD4: .4byte 0x0203A7D4
_0812FBD8: .4byte 0x0203A7E4
_0812FBDC: .4byte 0x0203A7E8
_0812FBE0: .4byte 0x0203A7EC
_0812FBE4: .4byte 0x0203A7F0
_0812FBE8: .4byte 0x0203A7F4
_0812FBEC: .4byte 0x0203A7CC
_0812FBF0: .4byte 0x0203A7D8
_0812FBF4: .4byte 0x0203A7DC
_0812FBF8: .4byte 0x0203A7E0
	thumb_func_end SlotMachineSetup_9_0

	thumb_func_start SlotMachineSetup_8_0
SlotMachineSetup_8_0: @ 0x0812FBFC
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	ldr r4, _0812FDA4
	movs r0, #8
	bl AllocZeroed
	str r0, [r4]
	ldr r6, _0812FDA8
	ldr r1, [r6]
	str r1, [r0]
	movs r5, #0xc0
	lsls r5, r5, #3
	strh r5, [r0, #4]
	ldr r4, _0812FDAC
	movs r0, #8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	adds r1, r1, r5
	str r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	mov r8, r1
	mov r2, r8
	strh r2, [r0, #4]
	ldr r4, _0812FDB0
	movs r0, #8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r3, #0x80
	lsls r3, r3, #4
	adds r1, r1, r3
	str r1, [r0]
	mov r4, r8
	strh r4, [r0, #4]
	ldr r4, _0812FDB4
	movs r0, #8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r2, #0xa0
	lsls r2, r2, #4
	adds r1, r1, r2
	str r1, [r0]
	mov r3, r8
	strh r3, [r0, #4]
	ldr r4, _0812FDB8
	movs r0, #8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r4, #0xc0
	lsls r4, r4, #4
	adds r1, r1, r4
	str r1, [r0]
	movs r5, #0xc0
	lsls r5, r5, #2
	strh r5, [r0, #4]
	ldr r4, _0812FDBC
	movs r0, #8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	strh r1, [r0, #4]
	ldr r4, _0812FDC0
	movs r0, #8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r3, #0xa0
	lsls r3, r3, #5
	adds r1, r1, r3
	str r1, [r0]
	mov r4, r8
	strh r4, [r0, #4]
	ldr r4, _0812FDC4
	movs r0, #8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r2, #0xb0
	lsls r2, r2, #5
	adds r1, r1, r2
	str r1, [r0]
	strh r5, [r0, #4]
	ldr r4, _0812FDC8
	movs r0, #8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r3, #0xc8
	lsls r3, r3, #5
	adds r1, r1, r3
	str r1, [r0]
	strh r5, [r0, #4]
	ldr r4, _0812FDCC
	movs r0, #0x10
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r4, #0xe0
	lsls r4, r4, #5
	adds r2, r1, r4
	str r2, [r0]
	mov r2, r8
	strh r2, [r0, #4]
	movs r3, #0xf0
	lsls r3, r3, #5
	adds r1, r1, r3
	str r1, [r0, #8]
	strh r2, [r0, #0xc]
	ldr r4, _0812FDD0
	movs r0, #8
	bl AllocZeroed
	str r0, [r4]
	ldr r1, [r6]
	movs r4, #0x80
	lsls r4, r4, #6
	adds r1, r1, r4
	str r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #2
	strh r1, [r0, #4]
	ldr r4, _0812FDD4
	movs r0, #0x28
	bl AllocZeroed
	str r0, [r4]
	ldr r2, [r6]
	movs r3, #0x8a
	lsls r3, r3, #6
	adds r1, r2, r3
	str r1, [r0]
	movs r3, #0x80
	strh r3, [r0, #4]
	movs r4, #0x8c
	lsls r4, r4, #6
	adds r1, r2, r4
	str r1, [r0, #8]
	strh r3, [r0, #0xc]
	adds r4, #0x80
	adds r1, r2, r4
	str r1, [r0, #0x10]
	strh r3, [r0, #0x14]
	adds r4, #0x80
	adds r1, r2, r4
	str r1, [r0, #0x18]
	strh r3, [r0, #0x1c]
	movs r1, #0x92
	lsls r1, r1, #6
	adds r2, r2, r1
	str r2, [r0, #0x20]
	strh r3, [r0, #0x24]
	ldr r4, _0812FDD8
	movs r0, #0x10
	bl AllocZeroed
	str r0, [r4]
	ldr r2, [r6]
	movs r3, #0x98
	lsls r3, r3, #6
	adds r1, r2, r3
	str r1, [r0]
	movs r1, #0x90
	lsls r1, r1, #3
	strh r1, [r0, #4]
	movs r4, #0xaa
	lsls r4, r4, #6
	adds r2, r2, r4
	str r2, [r0, #8]
	strh r1, [r0, #0xc]
	ldr r4, _0812FDDC
	movs r0, #0x10
	bl AllocZeroed
	str r0, [r4]
	ldr r2, [r6]
	movs r3, #0xbc
	lsls r3, r3, #6
	adds r1, r2, r3
	str r1, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	strh r1, [r0, #4]
	movs r4, #0xc2
	lsls r4, r4, #6
	adds r2, r2, r4
	str r2, [r0, #8]
	strh r1, [r0, #0xc]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0812FDA4: .4byte 0x0203A7C0
_0812FDA8: .4byte 0x0203A7A0
_0812FDAC: .4byte 0x0203A7C4
_0812FDB0: .4byte 0x0203A7C8
_0812FDB4: .4byte 0x0203A7CC
_0812FDB8: .4byte 0x0203A7D0
_0812FDBC: .4byte 0x0203A7D4
_0812FDC0: .4byte 0x0203A7D8
_0812FDC4: .4byte 0x0203A7DC
_0812FDC8: .4byte 0x0203A7E0
_0812FDCC: .4byte 0x0203A7E4
_0812FDD0: .4byte 0x0203A7E8
_0812FDD4: .4byte 0x0203A7EC
_0812FDD8: .4byte 0x0203A7F0
_0812FDDC: .4byte 0x0203A7F4
	thumb_func_end SlotMachineSetup_8_0

