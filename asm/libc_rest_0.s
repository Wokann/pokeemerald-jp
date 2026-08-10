.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



thumb_func_start vsprintf
vsprintf: @ 0x08297E68
	push {r4, r5, lr}
	sub sp, #0x58
	mov r4, sp
	movs r5, #0
	movs r3, #0x82
	lsls r3, r3, #2
	strh r3, [r4, #0xc]
	str r0, [sp]
	str r0, [sp, #0x10]
	ldr r0, _08297E94
	str r0, [sp, #8]
	str r0, [sp, #0x14]
	ldr r0, _08297E98
	ldr r0, [r0]
	str r0, [sp, #0x54]
	mov r0, sp
	bl vfprintf
	ldr r1, [sp]
	strb r5, [r1]
	add sp, #0x58
	pop {r4, r5, pc}
	.align 2, 0
_08297E94: .4byte 0x7FFFFFFF
_08297E98: .4byte 0x0203CF1C
	thumb_func_end vsprintf

thumb_func_start sub_08297E9C
sub_08297E9C: @ 0x08297E9C
	push {r4, lr}
	adds r4, r1, #0
	ldr r1, [r4, #8]
	cmp r1, #0
	beq _08297EB4
	adds r1, r4, #0
	bl __sfvwrite
	movs r1, #0
	str r1, [r4, #8]
	str r1, [r4, #4]
	b _08297EB8
_08297EB4:
	str r1, [r4, #4]
	movs r0, #0
_08297EB8:
	pop {r4, pc}
	.align 2, 0
	thumb_func_end sub_08297E9C

thumb_func_start sub_08297EBC
sub_08297EBC: @ 0x08297EBC
	push {r4, r5, lr}
	ldr r4, _08297F2C
	add sp, r4
	adds r5, r0, #0
	ldr r0, [r5, #0x54]
	str r0, [sp, #0x54]
	mov r3, sp
	movs r0, #3
	rsbs r0, r0, #0
	ldrh r4, [r5, #0xc]
	ands r0, r4
	movs r4, #0
	strh r0, [r3, #0xc]
	ldrh r0, [r5, #0xe]
	strh r0, [r3, #0xe]
	ldr r0, [r5, #0x1c]
	str r0, [sp, #0x1c]
	ldr r0, [r5, #0x24]
	str r0, [sp, #0x24]
	add r0, sp, #0x58
	str r0, [sp]
	str r0, [sp, #0x10]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #8]
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	mov r0, sp
	bl vfprintf
	adds r4, r0, #0
	cmp r4, #0
	blt _08297F0C
	mov r0, sp
	bl fflush
	cmp r0, #0
	beq _08297F0C
	movs r4, #1
	rsbs r4, r4, #0
_08297F0C:
	mov r1, sp
	movs r0, #0x40
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _08297F20
	movs r0, #0x40
	ldrh r1, [r5, #0xc]
	orrs r0, r1
	strh r0, [r5, #0xc]
_08297F20:
	adds r0, r4, #0
	movs r3, #0x8b
	lsls r3, r3, #3
	add sp, r3
	pop {r4, r5, pc}
	.align 2, 0
_08297F2C: .4byte 0xFFFFFBA8
	thumb_func_end sub_08297EBC

thumb_func_start vfprintf
vfprintf: @ 0x08297F30
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	ldr r0, [r4, #0x54]
	adds r1, r4, #0
	adds r2, r5, #0
	bl _vfprintf_r
	pop {r4, r5, pc}
	thumb_func_end vfprintf

thumb_func_start _vfprintf_r
_vfprintf_r: @ 0x08297F44
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _08297FAC
	add sp, r4
	str r0, [sp, #0x1dc]
	str r1, [sp, #0x1e0]
	adds r4, r2, #0
	mov sl, r3
	bl localeconv
	ldr r0, [r0]
	str r0, [sp, #0x1f8]
	movs r1, #0
	add r0, sp, #0x1d0
	str r1, [r0]
	ldr r1, [sp, #0x1e0]
	ldr r0, [r1, #0x54]
	cmp r0, #0
	bne _08297F76
	ldr r0, _08297FB0
	ldr r0, [r0]
	str r0, [r1, #0x54]
_08297F76:
	ldr r2, [sp, #0x1e0]
	ldr r1, [r2, #0x54]
	ldr r0, [r1, #0x38]
	cmp r0, #0
	bne _08297F86
	adds r0, r1, #0
	bl __sinit
_08297F86:
	movs r0, #8
	ldr r1, [sp, #0x1e0]
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _08297F9A
	ldr r2, [sp, #0x1e0]
	ldr r0, [r2, #0x10]
	cmp r0, #0
	bne _08297FB4
_08297F9A:
	ldr r0, [sp, #0x1e0]
	bl __swsetup
	cmp r0, #0
	beq _08297FB4
	movs r0, #1
	rsbs r0, r0, #0
	bl _08298E94
	.align 2, 0
_08297FAC: .4byte 0xFFFFFDE0
_08297FB0: .4byte 0x0203CF1C
_08297FB4:
	movs r0, #0x1a
	ldr r1, [sp, #0x1e0]
	ldrh r1, [r1, #0xc]
	ands r0, r1
	cmp r0, #0xa
	bne _08297FD8
	ldr r2, [sp, #0x1e0]
	movs r1, #0xe
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _08297FD8
	adds r0, r2, #0
	adds r1, r4, #0
	mov r2, sl
	bl sub_08297EBC
	bl _08298E94
_08297FD8:
	str r4, [sp, #0x1e4]
	add r1, sp, #0x1c
	add r5, sp, #0x28
	str r5, [sp, #0x1c]
	movs r0, #0
	str r0, [r1, #8]
	str r0, [r1, #4]
	movs r2, #0
	str r2, [sp, #0x1f0]
	mov sb, r1
	movs r4, #0xe6
	lsls r4, r4, #1
	add r4, sp
	str r4, [sp, #0x214]
	movs r0, #0xe8
	lsls r0, r0, #1
	add r0, sp
	str r0, [sp, #0x218]
_08297FFC:
	ldr r1, [sp, #0x1e4]
	mov r8, r1
_08298000:
	ldr r0, _082980AC
	ldr r0, [r0]
	ldr r1, _082980B0
	ldr r3, [r1]
	ldr r2, [sp, #0x218]
	str r2, [sp]
	ldr r1, [sp, #0x214]
	ldr r2, [sp, #0x1e4]
	bl _mbtowc_r
	adds r4, r0, #0
	cmp r4, #0
	ble _0829802E
	ldr r0, [sp, #0x1e4]
	adds r0, r0, r4
	str r0, [sp, #0x1e4]
	add r0, sp, #0x1cc
	ldr r0, [r0]
	cmp r0, #0x25
	bne _08298000
	ldr r1, [sp, #0x1e4]
	subs r1, #1
	str r1, [sp, #0x1e4]
_0829802E:
	ldr r2, [sp, #0x1e4]
	mov r0, r8
	subs r6, r2, r0
	cmp r6, #0
	beq _08298066
	str r0, [r5]
	str r6, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, r0, r6
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	ble _08298060
	ldr r0, [sp, #0x1e0]
	bl sub_08297E9C
	cmp r0, #0
	beq _0829805E
	bl _08298E80
_0829805E:
	add r5, sp, #0x28
_08298060:
	ldr r2, [sp, #0x1f0]
	adds r2, r2, r6
	str r2, [sp, #0x1f0]
_08298066:
	cmp r4, #0
	bgt _0829806E
	bl _08298E68
_0829806E:
	ldr r4, [sp, #0x1e4]
	adds r4, #1
	str r4, [sp, #0x1e4]
	movs r0, #0
	str r0, [sp, #0x1ec]
	movs r1, #0
	str r1, [sp, #0x208]
	movs r2, #0
	str r2, [sp, #0x1f4]
	movs r6, #1
	rsbs r6, r6, #0
	ldr r0, _082980B4
	add r0, sp
	strb r2, [r0]
_0829808A:
	ldr r0, [sp, #0x1e4]
	ldrb r0, [r0]
	str r0, [sp, #0x1e8]
	ldr r1, [sp, #0x1e4]
	adds r1, #1
	str r1, [sp, #0x1e4]
_08298096:
	ldr r0, [sp, #0x1e8]
	subs r0, #0x20
	cmp r0, #0x58
	bls _082980A0
	b _08298752
_082980A0:
	lsls r0, r0, #2
	ldr r1, _082980B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082980AC: .4byte 0x0203CF1C
_082980B0: .4byte 0x0203CF20
_082980B4: .4byte 0x000001C9
_082980B8: .4byte 0x082980BC
_082980BC: @ jump table
	.4byte _08298220 @ case 0
	.4byte _08298752 @ case 1
	.4byte _08298752 @ case 2
	.4byte _08298238 @ case 3
	.4byte _08298752 @ case 4
	.4byte _08298752 @ case 5
	.4byte _08298752 @ case 6
	.4byte _08298752 @ case 7
	.4byte _08298752 @ case 8
	.4byte _08298752 @ case 9
	.4byte _0829823C @ case 10
	.4byte _08298256 @ case 11
	.4byte _08298752 @ case 12
	.4byte _08298252 @ case 13
	.4byte _08298264 @ case 14
	.4byte _08298752 @ case 15
	.4byte _082982C4 @ case 16
	.4byte _082982C8 @ case 17
	.4byte _082982C8 @ case 18
	.4byte _082982C8 @ case 19
	.4byte _082982C8 @ case 20
	.4byte _082982C8 @ case 21
	.4byte _082982C8 @ case 22
	.4byte _082982C8 @ case 23
	.4byte _082982C8 @ case 24
	.4byte _082982C8 @ case 25
	.4byte _08298752 @ case 26
	.4byte _08298752 @ case 27
	.4byte _08298752 @ case 28
	.4byte _08298752 @ case 29
	.4byte _08298752 @ case 30
	.4byte _08298752 @ case 31
	.4byte _08298752 @ case 32
	.4byte _08298752 @ case 33
	.4byte _08298752 @ case 34
	.4byte _08298752 @ case 35
	.4byte _08298332 @ case 36
	.4byte _08298384 @ case 37
	.4byte _08298752 @ case 38
	.4byte _08298384 @ case 39
	.4byte _08298752 @ case 40
	.4byte _08298752 @ case 41
	.4byte _08298752 @ case 42
	.4byte _08298752 @ case 43
	.4byte _082982EC @ case 44
	.4byte _08298752 @ case 45
	.4byte _08298752 @ case 46
	.4byte _0829853A @ case 47
	.4byte _08298752 @ case 48
	.4byte _08298752 @ case 49
	.4byte _08298752 @ case 50
	.4byte _08298752 @ case 51
	.4byte _08298752 @ case 52
	.4byte _082985D2 @ case 53
	.4byte _08298752 @ case 54
	.4byte _08298752 @ case 55
	.4byte _0829860E @ case 56
	.4byte _08298752 @ case 57
	.4byte _08298752 @ case 58
	.4byte _08298752 @ case 59
	.4byte _08298752 @ case 60
	.4byte _08298752 @ case 61
	.4byte _08298752 @ case 62
	.4byte _08298752 @ case 63
	.4byte _08298752 @ case 64
	.4byte _08298752 @ case 65
	.4byte _08298752 @ case 66
	.4byte _08298320 @ case 67
	.4byte _0829833A @ case 68
	.4byte _08298384 @ case 69
	.4byte _08298384 @ case 70
	.4byte _08298384 @ case 71
	.4byte _082982F0 @ case 72
	.4byte _0829833A @ case 73
	.4byte _08298752 @ case 74
	.4byte _08298752 @ case 75
	.4byte _082982F4 @ case 76
	.4byte _08298752 @ case 77
	.4byte _082984F4 @ case 78
	.4byte _08298542 @ case 79
	.4byte _08298570 @ case 80
	.4byte _08298316 @ case 81
	.4byte _08298752 @ case 82
	.4byte _08298590 @ case 83
	.4byte _08298752 @ case 84
	.4byte _082985DA @ case 85
	.4byte _08298752 @ case 86
	.4byte _08298752 @ case 87
	.4byte _08298618 @ case 88
_08298220:
	ldr r1, _08298234
	add r1, sp
	ldrb r0, [r1]
	cmp r0, #0
	beq _0829822C
	b _0829808A
_0829822C:
	movs r0, #0x20
	strb r0, [r1]
	b _0829808A
	.align 2, 0
_08298234: .4byte 0x000001C9
_08298238:
	movs r0, #1
	b _08298304
_0829823C:
	movs r4, #4
	add sl, r4
	mov r0, sl
	subs r0, #4
	ldr r0, [r0]
	str r0, [sp, #0x1f4]
	cmp r0, #0
	blt _0829824E
	b _0829808A
_0829824E:
	rsbs r0, r0, #0
	str r0, [sp, #0x1f4]
_08298252:
	movs r0, #4
	b _08298318
_08298256:
	ldr r1, _08298260
	add r1, sp
	movs r0, #0x2b
	strb r0, [r1]
	b _0829808A
	.align 2, 0
_08298260: .4byte 0x000001C9
_08298264:
	ldr r2, [sp, #0x1e4]
	ldrb r2, [r2]
	str r2, [sp, #0x1e8]
	ldr r4, [sp, #0x1e4]
	adds r4, #1
	str r4, [sp, #0x1e4]
	cmp r2, #0x2a
	bne _0829828E
	movs r0, #4
	add sl, r0
	mov r0, sl
	subs r0, #4
	ldr r4, [r0]
	adds r6, r4, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r6, r0
	blt _0829828A
	b _0829808A
_0829828A:
	adds r6, r0, #0
	b _0829808A
_0829828E:
	movs r4, #0
	ldr r0, [sp, #0x1e8]
	b _082982AE
_08298294:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #1
	subs r0, #0x30
	ldr r1, [sp, #0x1e8]
	adds r4, r0, r1
	ldr r2, [sp, #0x1e4]
	ldrb r2, [r2]
	str r2, [sp, #0x1e8]
	ldr r0, [sp, #0x1e4]
	adds r0, #1
	str r0, [sp, #0x1e4]
	adds r0, r2, #0
_082982AE:
	subs r0, #0x30
	cmp r0, #9
	bls _08298294
	adds r6, r4, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r6, r0
	blt _082982C0
	b _08298096
_082982C0:
	adds r6, r0, #0
	b _08298096
_082982C4:
	movs r0, #0x80
	b _08298318
_082982C8:
	movs r4, #0
_082982CA:
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #1
	subs r0, #0x30
	ldr r2, [sp, #0x1e8]
	adds r4, r0, r2
	ldr r0, [sp, #0x1e4]
	ldrb r0, [r0]
	str r0, [sp, #0x1e8]
	ldr r1, [sp, #0x1e4]
	adds r1, #1
	str r1, [sp, #0x1e4]
	subs r0, #0x30
	cmp r0, #9
	bls _082982CA
	str r4, [sp, #0x1f4]
	b _08298096
_082982EC:
	movs r0, #8
	b _08298304
_082982F0:
	movs r0, #0x40
	b _0829830E
_082982F4:
	ldr r0, [sp, #0x1e4]
	ldrb r0, [r0]
	cmp r0, #0x6c
	bne _0829830C
	ldr r1, [sp, #0x1e4]
	adds r1, #1
	str r1, [sp, #0x1e4]
	movs r0, #0x20
_08298304:
	ldr r2, [sp, #0x1ec]
	orrs r2, r0
	str r2, [sp, #0x1ec]
	b _0829808A
_0829830C:
	movs r0, #0x10
_0829830E:
	ldr r4, [sp, #0x1ec]
	orrs r4, r0
	str r4, [sp, #0x1ec]
	b _0829808A
_08298316:
	movs r0, #0x20
_08298318:
	ldr r1, [sp, #0x1ec]
	orrs r1, r0
	str r1, [sp, #0x1ec]
	b _0829808A
_08298320:
	add r2, sp, #0x68
	mov r8, r2
	movs r4, #4
	add sl, r4
	mov r0, sl
	subs r0, #4
	ldr r0, [r0]
	strb r0, [r2]
	b _08298760
_08298332:
	movs r0, #0x10
	ldr r1, [sp, #0x1ec]
	orrs r1, r0
	str r1, [sp, #0x1ec]
_0829833A:
	movs r0, #0x10
	ldr r2, [sp, #0x1ec]
	ands r0, r2
	cmp r0, #0
	beq _0829834A
	movs r4, #4
	add sl, r4
	b _08298366
_0829834A:
	movs r0, #0x40
	ldr r1, [sp, #0x1ec]
	ands r0, r1
	cmp r0, #0
	beq _08298362
	movs r2, #4
	add sl, r2
	mov r0, sl
	subs r0, #4
	movs r1, #0
	ldrsh r4, [r0, r1]
	b _0829836C
_08298362:
	movs r2, #4
	add sl, r2
_08298366:
	mov r0, sl
	subs r0, #4
	ldr r4, [r0]
_0829836C:
	cmp r4, #0
	bge _0829837A
	rsbs r4, r4, #0
	ldr r1, _08298380
	add r1, sp
	movs r0, #0x2d
	strb r0, [r1]
_0829837A:
	movs r2, #1
	b _08298666
	.align 2, 0
_08298380: .4byte 0x000001C9
_08298384:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r6, r0
	bne _08298390
	movs r6, #6
	b _082983A0
_08298390:
	ldr r4, [sp, #0x1e8]
	cmp r4, #0x67
	beq _0829839A
	cmp r4, #0x47
	bne _082983A0
_0829839A:
	cmp r6, #0
	bne _082983A0
	movs r6, #1
_082983A0:
	movs r0, #8
	ldr r1, [sp, #0x1ec]
	ands r0, r1
	movs r2, #8
	add sl, r2
	mov r0, sl
	subs r0, #8
	ldr r1, [r0]
	ldr r2, [r0, #4]
	str r1, [sp, #0x1fc]
	str r2, [sp, #0x200]
	ldr r0, [sp, #0x1fc]
	ldr r1, [sp, #0x200]
	bl isinf
	cmp r0, #0
	beq _082983F4
	ldr r3, _082983E8
	ldr r2, _082983E4
	ldr r0, [sp, #0x1fc]
	ldr r1, [sp, #0x200]
	bl __ltdf2
	cmp r0, #0
	bge _082983DA
	ldr r1, _082983EC
	add r1, sp
	movs r0, #0x2d
	strb r0, [r1]
_082983DA:
	ldr r2, _082983F0
	mov r8, r2
	movs r3, #3
	b _0829876A
	.align 2, 0
_082983E4: .4byte 0x00000000
_082983E8: .4byte 0x00000000
_082983EC: .4byte 0x000001C9
_082983F0: .4byte 0x0890F17C
_082983F4:
	ldr r0, [sp, #0x1fc]
	ldr r1, [sp, #0x200]
	bl isnan
	cmp r0, #0
	beq _0829840C
	ldr r4, _08298408
	mov r8, r4
	movs r3, #3
	b _0829876A
	.align 2, 0
_08298408: .4byte 0x0890F180
_0829840C:
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r1, [sp, #0x1ec]
	orrs r1, r0
	str r1, [sp, #0x1ec]
	str r1, [sp]
	add r0, sp, #0x1c8
	str r0, [sp, #4]
	add r0, sp, #0x1d4
	str r0, [sp, #8]
	ldr r2, [sp, #0x1e8]
	str r2, [sp, #0xc]
	add r0, sp, #0x1d8
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x1dc]
	ldr r1, [sp, #0x1fc]
	ldr r2, [sp, #0x200]
	adds r3, r6, #0
	bl sub_08298EA4
	mov r8, r0
	ldr r4, [sp, #0x1e8]
	cmp r4, #0x67
	beq _08298440
	cmp r4, #0x47
	bne _08298462
_08298440:
	add r0, sp, #0x1d4
	ldr r1, [r0]
	movs r0, #4
	rsbs r0, r0, #0
	cmp r1, r0
	ble _08298450
	cmp r1, r6
	ble _0829845E
_08298450:
	movs r0, #0x45
	ldr r1, [sp, #0x1e8]
	cmp r1, #0x67
	bne _0829845A
	movs r0, #0x65
_0829845A:
	str r0, [sp, #0x1e8]
	b _08298462
_0829845E:
	movs r2, #0x67
	str r2, [sp, #0x1e8]
_08298462:
	ldr r4, [sp, #0x1e8]
	cmp r4, #0x65
	bgt _08298488
	add r0, sp, #0x1d4
	ldr r1, [r0]
	subs r1, #1
	str r1, [r0]
	add r0, sp, #0x14
	ldr r2, [sp, #0x1e8]
	bl sub_08298F98
	str r0, [sp, #0x204]
	add r0, sp, #0x1d8
	ldr r0, [r0]
	ldr r1, [sp, #0x204]
	adds r3, r1, r0
	cmp r0, #1
	bgt _082984C8
	b _082984BE
_08298488:
	ldr r4, [sp, #0x1e8]
	cmp r4, #0x66
	bne _082984B0
	add r0, sp, #0x1d4
	ldr r0, [r0]
	cmp r0, #0
	ble _082984AC
	adds r3, r0, #0
	cmp r6, #0
	bne _082984A6
	movs r0, #1
	ldr r1, [sp, #0x1ec]
	ands r0, r1
	cmp r0, #0
	beq _082984D8
_082984A6:
	adds r0, r3, #1
	adds r3, r0, r6
	b _082984D8
_082984AC:
	adds r3, r6, #2
	b _082984D8
_082984B0:
	add r0, sp, #0x1d4
	ldr r1, [r0]
	add r0, sp, #0x1d8
	ldr r0, [r0]
	cmp r1, r0
	blt _082984CC
	adds r3, r1, #0
_082984BE:
	movs r0, #1
	ldr r2, [sp, #0x1ec]
	ands r0, r2
	cmp r0, #0
	beq _082984D8
_082984C8:
	adds r3, #1
	b _082984D8
_082984CC:
	cmp r1, #0
	bgt _082984D6
	adds r0, #2
	subs r3, r0, r1
	b _082984D8
_082984D6:
	adds r3, r0, #1
_082984D8:
	add r0, sp, #0x1c8
	ldrb r0, [r0]
	adds r7, r5, #0
	adds r7, #8
	cmp r0, #0
	bne _082984E6
	b _0829876E
_082984E6:
	ldr r1, _082984F0
	add r1, sp
	movs r0, #0x2d
	strb r0, [r1]
	b _0829876E
	.align 2, 0
_082984F0: .4byte 0x000001C9
_082984F4:
	movs r0, #0x10
	ldr r4, [sp, #0x1ec]
	ands r0, r4
	cmp r0, #0
	beq _0829850E
	movs r0, #4
	add sl, r0
	mov r0, sl
	subs r0, #4
	ldr r0, [r0]
	ldr r1, [sp, #0x1f0]
	str r1, [r0]
	b _08297FFC
_0829850E:
	movs r0, #0x40
	ldr r2, [sp, #0x1ec]
	ands r2, r0
	cmp r2, #0
	beq _0829852A
	movs r4, #4
	add sl, r4
	mov r0, sl
	subs r0, #4
	ldr r0, [r0]
	add r1, sp, #0x1f0
	ldrh r1, [r1]
	strh r1, [r0]
	b _08297FFC
_0829852A:
	movs r2, #4
	add sl, r2
	mov r0, sl
	subs r0, #4
	ldr r0, [r0]
	ldr r4, [sp, #0x1f0]
	str r4, [r0]
	b _08297FFC
_0829853A:
	movs r0, #0x10
	ldr r1, [sp, #0x1ec]
	orrs r1, r0
	str r1, [sp, #0x1ec]
_08298542:
	movs r0, #0x10
	ldr r2, [sp, #0x1ec]
	ands r0, r2
	cmp r0, #0
	bne _08298562
	movs r0, #0x40
	ldr r1, [sp, #0x1ec]
	ands r0, r1
	cmp r0, #0
	beq _08298562
	movs r2, #4
	add sl, r2
	mov r0, sl
	subs r0, #4
	ldrh r4, [r0]
	b _0829856C
_08298562:
	movs r4, #4
	add sl, r4
	mov r0, sl
	subs r0, #4
	ldr r4, [r0]
_0829856C:
	movs r2, #0
	b _0829865E
_08298570:
	movs r0, #4
	add sl, r0
	mov r0, sl
	subs r0, #4
	ldr r4, [r0]
	movs r2, #2
	ldr r1, _0829858C
	str r1, [sp, #0x210]
	ldr r0, [sp, #0x1ec]
	orrs r0, r2
	str r0, [sp, #0x1ec]
	movs r1, #0x78
	str r1, [sp, #0x1e8]
	b _0829865E
	.align 2, 0
_0829858C: .4byte 0x0890F184
_08298590:
	movs r2, #4
	add sl, r2
	mov r0, sl
	subs r0, #4
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _082985A4
	ldr r4, _082985C4
	mov r8, r4
_082985A4:
	cmp r6, #0
	blt _082985C8
	mov r0, r8
	movs r1, #0
	adds r2, r6, #0
	bl memchr
	cmp r0, #0
	beq _082985C0
	mov r1, r8
	subs r3, r0, r1
	cmp r3, r6
	bgt _082985C0
	b _08298762
_082985C0:
	adds r3, r6, #0
	b _08298762
	.align 2, 0
_082985C4: .4byte 0x0890F198
_082985C8:
	mov r0, r8
	bl strlen
	adds r3, r0, #0
	b _08298762
_082985D2:
	movs r0, #0x10
	ldr r2, [sp, #0x1ec]
	orrs r2, r0
	str r2, [sp, #0x1ec]
_082985DA:
	movs r0, #0x10
	ldr r4, [sp, #0x1ec]
	ands r0, r4
	cmp r0, #0
	beq _082985EA
	movs r0, #4
	add sl, r0
	b _08298604
_082985EA:
	movs r0, #0x40
	ldr r1, [sp, #0x1ec]
	ands r0, r1
	cmp r0, #0
	beq _08298600
	movs r2, #4
	add sl, r2
	mov r0, sl
	subs r0, #4
	ldrh r4, [r0]
	b _0829860A
_08298600:
	movs r4, #4
	add sl, r4
_08298604:
	mov r0, sl
	subs r0, #4
	ldr r4, [r0]
_0829860A:
	movs r2, #1
	b _0829865E
_0829860E:
	ldr r0, _08298614
	str r0, [sp, #0x210]
	b _0829861C
	.align 2, 0
_08298614: .4byte 0x0890F1A0
_08298618:
	ldr r1, _0829863C
	str r1, [sp, #0x210]
_0829861C:
	movs r0, #0x10
	ldr r2, [sp, #0x1ec]
	ands r0, r2
	cmp r0, #0
	bne _08298640
	movs r0, #0x40
	ldr r1, [sp, #0x1ec]
	ands r0, r1
	cmp r0, #0
	beq _08298640
	movs r2, #4
	add sl, r2
	mov r0, sl
	subs r0, #4
	ldrh r4, [r0]
	b _0829864A
	.align 2, 0
_0829863C: .4byte 0x0890F184
_08298640:
	movs r4, #4
	add sl, r4
	mov r0, sl
	subs r0, #4
	ldr r4, [r0]
_0829864A:
	movs r2, #2
	movs r0, #1
	ldr r1, [sp, #0x1ec]
	ands r0, r1
	cmp r0, #0
	beq _0829865E
	cmp r4, #0
	beq _0829865E
	orrs r1, r2
	str r1, [sp, #0x1ec]
_0829865E:
	ldr r1, _082986A8
	add r1, sp
	movs r0, #0
	strb r0, [r1]
_08298666:
	str r6, [sp, #0x208]
	cmp r6, #0
	blt _08298676
	movs r0, #0x81
	rsbs r0, r0, #0
	ldr r1, [sp, #0x1ec]
	ands r1, r0
	str r1, [sp, #0x1ec]
_08298676:
	movs r0, #0xe2
	lsls r0, r0, #1
	add r0, sp
	mov r8, r0
	cmp r4, #0
	bne _0829868C
	adds r7, r5, #0
	adds r7, #8
	ldr r1, [sp, #0x208]
	cmp r1, #0
	beq _08298744
_0829868C:
	cmp r2, #1
	beq _082986EA
	cmp r2, #1
	blo _082986B0
	cmp r2, #2
	beq _08298724
	ldr r2, _082986AC
	mov r8, r2
	mov r0, r8
	bl strlen
	adds r3, r0, #0
	b _0829876A
	.align 2, 0
_082986A8: .4byte 0x000001C9
_082986AC: .4byte 0x0890F1B4
_082986B0:
	adds r7, r5, #0
	adds r7, #8
	movs r2, #7
_082986B6:
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	adds r0, r4, #0
	ands r0, r2
	adds r1, r0, #0
	adds r1, #0x30
	mov r0, r8
	strb r1, [r0]
	lsrs r4, r4, #3
	cmp r4, #0
	bne _082986B6
	movs r0, #1
	ldr r2, [sp, #0x1ec]
	ands r0, r2
	cmp r0, #0
	beq _08298744
	cmp r1, #0x30
	beq _08298744
	movs r4, #1
	rsbs r4, r4, #0
	add r8, r4
	movs r0, #0x30
	mov r1, r8
	strb r0, [r1]
	b _08298744
_082986EA:
	adds r7, r5, #0
	adds r7, #8
	cmp r4, #9
	bls _08298714
_082986F2:
	movs r2, #1
	rsbs r2, r2, #0
	add r8, r2
	adds r0, r4, #0
	movs r1, #0xa
	bl __umodsi3
	adds r0, #0x30
	mov r1, r8
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0xa
	bl __udivsi3
	adds r4, r0, #0
	cmp r4, #9
	bhi _082986F2
_08298714:
	movs r2, #1
	rsbs r2, r2, #0
	add r8, r2
	adds r0, r4, #0
	adds r0, #0x30
	mov r4, r8
	strb r0, [r4]
	b _08298744
_08298724:
	adds r7, r5, #0
	adds r7, #8
	movs r1, #0xf
_0829872A:
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	adds r0, r4, #0
	ands r0, r1
	ldr r2, [sp, #0x210]
	adds r0, r2, r0
	ldrb r0, [r0]
	mov r2, r8
	strb r0, [r2]
	lsrs r4, r4, #4
	cmp r4, #0
	bne _0829872A
_08298744:
	add r4, sp, #0x14
	mov r1, r8
	subs r0, r4, r1
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r3, r0, r2
	b _0829876E
_08298752:
	ldr r4, [sp, #0x1e8]
	cmp r4, #0
	bne _0829875A
	b _08298E68
_0829875A:
	add r0, sp, #0x68
	mov r8, r0
	strb r4, [r0]
_08298760:
	movs r3, #1
_08298762:
	ldr r1, _0829878C
	add r1, sp
	movs r0, #0
	strb r0, [r1]
_0829876A:
	adds r7, r5, #0
	adds r7, #8
_0829876E:
	str r3, [sp, #0x20c]
	ldr r2, [sp, #0x208]
	cmp r3, r2
	bge _08298778
	str r2, [sp, #0x20c]
_08298778:
	ldr r0, _0829878C
	add r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	beq _08298790
	ldr r4, [sp, #0x20c]
	adds r4, #1
	str r4, [sp, #0x20c]
	b _082987A0
	.align 2, 0
_0829878C: .4byte 0x000001C9
_08298790:
	movs r0, #2
	ldr r1, [sp, #0x1ec]
	ands r0, r1
	cmp r0, #0
	beq _082987A0
	ldr r2, [sp, #0x20c]
	adds r2, #2
	str r2, [sp, #0x20c]
_082987A0:
	movs r0, #0x84
	ldr r4, [sp, #0x1ec]
	ands r0, r4
	cmp r0, #0
	bne _08298820
	ldr r0, [sp, #0x1f4]
	ldr r1, [sp, #0x20c]
	subs r4, r0, r1
	cmp r4, #0
	ble _08298820
	ldr r1, _0829884C
	cmp r4, #0x10
	ble _082987F4
	mov r6, sb
_082987BC:
	str r1, [r5]
	movs r0, #0x10
	str r0, [r5, #4]
	ldr r0, [r6, #8]
	adds r0, #0x10
	str r0, [r6, #8]
	adds r5, r7, #0
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #7
	ble _082987EA
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	str r3, [sp, #0x21c]
	bl sub_08297E9C
	ldr r3, [sp, #0x21c]
	cmp r0, #0
	beq _082987E6
	b _08298E80
_082987E6:
	add r5, sp, #0x28
	ldr r1, _0829884C
_082987EA:
	subs r4, #0x10
	adds r7, r5, #0
	adds r7, #8
	cmp r4, #0x10
	bgt _082987BC
_082987F4:
	str r1, [r5]
	str r4, [r5, #4]
	mov r2, sb
	ldr r0, [r2, #8]
	adds r0, r0, r4
	str r0, [r2, #8]
	adds r5, r7, #0
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	cmp r0, #7
	ble _08298820
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	str r3, [sp, #0x21c]
	bl sub_08297E9C
	ldr r3, [sp, #0x21c]
	cmp r0, #0
	beq _0829881E
	b _08298E80
_0829881E:
	add r5, sp, #0x28
_08298820:
	ldr r1, _08298850
	add r1, sp
	ldrb r0, [r1]
	cmp r0, #0
	beq _08298854
	str r1, [r5]
	movs r0, #1
	str r0, [r5, #4]
	mov r4, sb
	ldr r0, [r4, #8]
	adds r0, #1
	str r0, [r4, #8]
	adds r5, #8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #7
	ble _08298894
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	b _08298884
	.align 2, 0
_0829884C: .4byte 0x0890F15C
_08298850: .4byte 0x000001C9
_08298854:
	movs r2, #2
	ldr r0, [sp, #0x1ec]
	ands r0, r2
	cmp r0, #0
	beq _08298894
	add r1, sp, #0x1c4
	movs r0, #0x30
	strb r0, [r1]
	add r0, sp, #0x1e8
	ldrb r0, [r0]
	strb r0, [r1, #1]
	str r1, [r5]
	str r2, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, #2
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	ble _08298894
	ldr r0, [sp, #0x1e0]
_08298884:
	str r3, [sp, #0x21c]
	bl sub_08297E9C
	ldr r3, [sp, #0x21c]
	cmp r0, #0
	beq _08298892
	b _08298E80
_08298892:
	add r5, sp, #0x28
_08298894:
	movs r0, #0x84
	ldr r2, [sp, #0x1ec]
	ands r0, r2
	cmp r0, #0x80
	bne _08298910
	ldr r0, [sp, #0x1f4]
	ldr r1, [sp, #0x20c]
	subs r4, r0, r1
	cmp r4, #0
	ble _08298910
	ldr r1, _082989AC
	cmp r4, #0x10
	ble _082988E4
	mov r6, sb
_082988B0:
	str r1, [r5]
	movs r0, #0x10
	str r0, [r5, #4]
	ldr r0, [r6, #8]
	adds r0, #0x10
	str r0, [r6, #8]
	adds r5, #8
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #7
	ble _082988DE
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	str r3, [sp, #0x21c]
	bl sub_08297E9C
	ldr r3, [sp, #0x21c]
	cmp r0, #0
	beq _082988DA
	b _08298E80
_082988DA:
	add r5, sp, #0x28
	ldr r1, _082989AC
_082988DE:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _082988B0
_082988E4:
	str r1, [r5]
	str r4, [r5, #4]
	mov r2, sb
	ldr r0, [r2, #8]
	adds r0, r0, r4
	str r0, [r2, #8]
	adds r5, #8
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	cmp r0, #7
	ble _08298910
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	str r3, [sp, #0x21c]
	bl sub_08297E9C
	ldr r3, [sp, #0x21c]
	cmp r0, #0
	beq _0829890E
	b _08298E80
_0829890E:
	add r5, sp, #0x28
_08298910:
	ldr r0, [sp, #0x208]
	subs r4, r0, r3
	cmp r4, #0
	ble _0829897E
	ldr r1, _082989AC
	cmp r4, #0x10
	ble _08298954
	mov r6, sb
_08298920:
	str r1, [r5]
	movs r0, #0x10
	str r0, [r5, #4]
	ldr r0, [r6, #8]
	adds r0, #0x10
	str r0, [r6, #8]
	adds r5, #8
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #7
	ble _0829894E
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	str r3, [sp, #0x21c]
	bl sub_08297E9C
	ldr r3, [sp, #0x21c]
	cmp r0, #0
	beq _0829894A
	b _08298E80
_0829894A:
	add r5, sp, #0x28
	ldr r1, _082989AC
_0829894E:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _08298920
_08298954:
	str r1, [r5]
	str r4, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, r0, r4
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	ble _0829897E
	ldr r0, [sp, #0x1e0]
	str r3, [sp, #0x21c]
	bl sub_08297E9C
	ldr r3, [sp, #0x21c]
	cmp r0, #0
	beq _0829897C
	b _08298E80
_0829897C:
	add r5, sp, #0x28
_0829897E:
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r2, [sp, #0x1ec]
	ands r0, r2
	cmp r0, #0
	bne _082989B0
	mov r4, r8
	str r4, [r5]
	str r3, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, r0, r3
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	bgt _082989A6
	b _08298DC6
_082989A6:
	ldr r0, [sp, #0x1e0]
	b _08298DBC
	.align 2, 0
_082989AC: .4byte 0x0890F16C
_082989B0:
	ldr r2, [sp, #0x1e8]
	cmp r2, #0x65
	bgt _082989B8
	b _08298C9C
_082989B8:
	ldr r3, _08298A84
	ldr r2, _08298A80
	ldr r0, [sp, #0x1fc]
	ldr r1, [sp, #0x200]
	bl __eqdf2
	cmp r0, #0
	bne _08298A90
	ldr r0, _08298A88
	str r0, [r5]
	movs r6, #1
	str r6, [r5, #4]
	mov r4, sb
	ldr r0, [r4, #8]
	adds r0, #1
	str r0, [r4, #8]
	adds r5, #8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #7
	ble _082989F4
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	beq _082989F2
	b _08298E80
_082989F2:
	add r5, sp, #0x28
_082989F4:
	add r0, sp, #0x1d4
	ldr r1, [r0]
	add r4, sp, #0x1d8
	ldr r0, [r4]
	cmp r1, r0
	blt _08298A0A
	ldr r0, [sp, #0x1ec]
	ands r0, r6
	cmp r0, #0
	bne _08298A0A
	b _08298DC6
_08298A0A:
	ldr r0, [sp, #0x1f8]
	str r0, [r5]
	str r6, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	ble _08298A32
	ldr r0, [sp, #0x1e0]
	bl sub_08297E9C
	cmp r0, #0
	beq _08298A30
	b _08298E80
_08298A30:
	add r5, sp, #0x28
_08298A32:
	ldr r0, [r4]
	subs r4, r0, #1
	cmp r4, #0
	bgt _08298A3C
	b _08298DC6
_08298A3C:
	ldr r1, _08298A8C
	cmp r4, #0x10
	ble _08298A74
	mov r6, sb
_08298A44:
	str r1, [r5]
	movs r0, #0x10
	str r0, [r5, #4]
	ldr r0, [r6, #8]
	adds r0, #0x10
	str r0, [r6, #8]
	adds r5, #8
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #7
	ble _08298A6E
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	beq _08298A6A
	b _08298E80
_08298A6A:
	add r5, sp, #0x28
	ldr r1, _08298A8C
_08298A6E:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _08298A44
_08298A74:
	str r1, [r5]
	str r4, [r5, #4]
	mov r2, sb
	ldr r0, [r2, #8]
	adds r0, r0, r4
	b _08298DAA
	.align 2, 0
_08298A80: .4byte 0x00000000
_08298A84: .4byte 0x00000000
_08298A88: .4byte 0x0890F1D0
_08298A8C: .4byte 0x0890F16C
_08298A90:
	add r6, sp, #0x1d4
	ldr r2, [r6]
	cmp r2, #0
	bgt _08298B78
	ldr r0, _08298B70
	str r0, [r5]
	movs r4, #1
	str r4, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	ble _08298AC2
	ldr r0, [sp, #0x1e0]
	bl sub_08297E9C
	cmp r0, #0
	beq _08298AC0
	b _08298E80
_08298AC0:
	add r5, sp, #0x28
_08298AC2:
	ldr r2, [sp, #0x1f8]
	str r2, [r5]
	str r4, [r5, #4]
	mov r4, sb
	ldr r0, [r4, #8]
	adds r0, #1
	str r0, [r4, #8]
	adds r5, #8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #7
	ble _08298AEC
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	beq _08298AEA
	b _08298E80
_08298AEA:
	add r5, sp, #0x28
_08298AEC:
	ldr r0, [r6]
	rsbs r4, r0, #0
	cmp r4, #0
	ble _08298B52
	ldr r1, _08298B74
	cmp r4, #0x10
	ble _08298B2C
	mov r6, sb
_08298AFC:
	str r1, [r5]
	movs r0, #0x10
	str r0, [r5, #4]
	ldr r0, [r6, #8]
	adds r0, #0x10
	str r0, [r6, #8]
	adds r5, #8
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #7
	ble _08298B26
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	beq _08298B22
	b _08298E80
_08298B22:
	add r5, sp, #0x28
	ldr r1, _08298B74
_08298B26:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _08298AFC
_08298B2C:
	str r1, [r5]
	str r4, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, r0, r4
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	ble _08298B52
	ldr r0, [sp, #0x1e0]
	bl sub_08297E9C
	cmp r0, #0
	beq _08298B50
	b _08298E80
_08298B50:
	add r5, sp, #0x28
_08298B52:
	mov r2, r8
	str r2, [r5]
	add r0, sp, #0x1d8
	ldr r1, [r0]
	str r1, [r5, #4]
	mov r4, sb
	ldr r0, [r4, #8]
	adds r0, r0, r1
	str r0, [r4, #8]
	adds r5, #8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	b _08298DB4
	.align 2, 0
_08298B70: .4byte 0x0890F1D0
_08298B74: .4byte 0x0890F16C
_08298B78:
	add r4, sp, #0x1d8
	ldr r1, [r4]
	cmp r2, r1
	blt _08298C34
	mov r0, r8
	str r0, [r5]
	str r1, [r5, #4]
	mov r2, sb
	ldr r0, [r2, #8]
	adds r0, r0, r1
	str r0, [r2, #8]
	adds r5, #8
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	cmp r0, #7
	ble _08298BAA
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	beq _08298BA8
	b _08298E80
_08298BA8:
	add r5, sp, #0x28
_08298BAA:
	ldr r1, [r6]
	ldr r0, [r4]
	subs r4, r1, r0
	cmp r4, #0
	ble _08298C12
	ldr r1, _08298C2C
	cmp r4, #0x10
	ble _08298BEC
	mov r6, sb
_08298BBC:
	str r1, [r5]
	movs r0, #0x10
	str r0, [r5, #4]
	ldr r0, [r6, #8]
	adds r0, #0x10
	str r0, [r6, #8]
	adds r5, #8
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #7
	ble _08298BE6
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	beq _08298BE2
	b _08298E80
_08298BE2:
	add r5, sp, #0x28
	ldr r1, _08298C2C
_08298BE6:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _08298BBC
_08298BEC:
	str r1, [r5]
	str r4, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, r0, r4
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	ble _08298C12
	ldr r0, [sp, #0x1e0]
	bl sub_08297E9C
	cmp r0, #0
	beq _08298C10
	b _08298E80
_08298C10:
	add r5, sp, #0x28
_08298C12:
	movs r1, #1
	ldr r0, [sp, #0x1ec]
	ands r0, r1
	cmp r0, #0
	bne _08298C1E
	b _08298DC6
_08298C1E:
	ldr r0, _08298C30
	str r0, [r5]
	str r1, [r5, #4]
	mov r2, sb
	ldr r0, [r2, #8]
	adds r0, #1
	b _08298DAA
	.align 2, 0
_08298C2C: .4byte 0x0890F16C
_08298C30: .4byte 0x0890F1D4
_08298C34:
	mov r0, r8
	str r0, [r5]
	str r2, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, r0, r2
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	ble _08298C5C
	ldr r0, [sp, #0x1e0]
	bl sub_08297E9C
	cmp r0, #0
	beq _08298C5A
	b _08298E80
_08298C5A:
	add r5, sp, #0x28
_08298C5C:
	ldr r0, [r6]
	add r8, r0
	ldr r0, _08298C98
	str r0, [r5]
	movs r0, #1
	str r0, [r5, #4]
	mov r2, sb
	ldr r0, [r2, #8]
	adds r0, #1
	str r0, [r2, #8]
	adds r5, #8
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	cmp r0, #7
	ble _08298C8C
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	beq _08298C8A
	b _08298E80
_08298C8A:
	add r5, sp, #0x28
_08298C8C:
	mov r0, r8
	str r0, [r5]
	ldr r1, [r4]
	ldr r0, [r6]
	subs r1, r1, r0
	b _08298DA2
	.align 2, 0
_08298C98: .4byte 0x0890F1D4
_08298C9C:
	add r4, sp, #0x1d8
	ldr r0, [r4]
	cmp r0, #1
	bgt _08298CAE
	movs r1, #1
	ldr r0, [sp, #0x1ec]
	ands r0, r1
	cmp r0, #0
	beq _08298D74
_08298CAE:
	add r1, sp, #0x1c4
	mov r2, r8
	ldrb r0, [r2]
	strb r0, [r1]
	movs r0, #1
	add r8, r0
	movs r0, #0x2e
	strb r0, [r1, #1]
	str r1, [r5]
	movs r0, #2
	str r0, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, #2
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	ble _08298CE6
	ldr r0, [sp, #0x1e0]
	bl sub_08297E9C
	cmp r0, #0
	beq _08298CE4
	b _08298E80
_08298CE4:
	add r5, sp, #0x28
_08298CE6:
	ldr r3, _08298D10
	ldr r2, _08298D0C
	ldr r0, [sp, #0x1fc]
	ldr r1, [sp, #0x200]
	bl __nedf2
	cmp r0, #0
	beq _08298D14
	mov r2, r8
	str r2, [r5]
	ldr r1, [r4]
	subs r0, r1, #1
	str r0, [r5, #4]
	mov r4, sb
	ldr r0, [r4, #8]
	subs r0, #1
	adds r0, r0, r1
	b _08298D80
	.align 2, 0
_08298D0C: .4byte 0x00000000
_08298D10: .4byte 0x00000000
_08298D14:
	ldr r0, [r4]
	subs r4, r0, #1
	cmp r4, #0
	ble _08298D9C
	ldr r1, _08298D70
	cmp r4, #0x10
	ble _08298D54
	mov r6, sb
_08298D24:
	str r1, [r5]
	movs r0, #0x10
	str r0, [r5, #4]
	ldr r0, [r6, #8]
	adds r0, #0x10
	str r0, [r6, #8]
	adds r5, #8
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #7
	ble _08298D4E
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	beq _08298D4A
	b _08298E80
_08298D4A:
	add r5, sp, #0x28
	ldr r1, _08298D70
_08298D4E:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _08298D24
_08298D54:
	str r1, [r5]
	str r4, [r5, #4]
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, r0, r4
	str r0, [r1, #8]
	adds r5, #8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #7
	ble _08298D9C
	ldr r0, [sp, #0x1e0]
	b _08298D92
	.align 2, 0
_08298D70: .4byte 0x0890F16C
_08298D74:
	mov r2, r8
	str r2, [r5]
	str r1, [r5, #4]
	mov r4, sb
	ldr r0, [r4, #8]
	adds r0, #1
_08298D80:
	str r0, [r4, #8]
	adds r5, #8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #7
	ble _08298D9C
	ldr r0, [sp, #0x1e0]
	mov r1, sb
_08298D92:
	bl sub_08297E9C
	cmp r0, #0
	bne _08298E80
	add r5, sp, #0x28
_08298D9C:
	add r0, sp, #0x14
	str r0, [r5]
	ldr r1, [sp, #0x204]
_08298DA2:
	str r1, [r5, #4]
	mov r2, sb
	ldr r0, [r2, #8]
	adds r0, r0, r1
_08298DAA:
	str r0, [r2, #8]
	adds r5, #8
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
_08298DB4:
	cmp r0, #7
	ble _08298DC6
	ldr r0, [sp, #0x1e0]
	mov r1, sb
_08298DBC:
	bl sub_08297E9C
	cmp r0, #0
	bne _08298E80
	add r5, sp, #0x28
_08298DC6:
	movs r0, #4
	ldr r4, [sp, #0x1ec]
	ands r4, r0
	cmp r4, #0
	beq _08298E32
	ldr r0, [sp, #0x1f4]
	ldr r1, [sp, #0x20c]
	subs r4, r0, r1
	cmp r4, #0
	ble _08298E32
	ldr r1, _08298E64
	cmp r4, #0x10
	ble _08298E10
	mov r6, sb
_08298DE2:
	str r1, [r5]
	movs r0, #0x10
	str r0, [r5, #4]
	ldr r0, [r6, #8]
	adds r0, #0x10
	str r0, [r6, #8]
	adds r5, #8
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #7
	ble _08298E0A
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	bne _08298E80
	add r5, sp, #0x28
	ldr r1, _08298E64
_08298E0A:
	subs r4, #0x10
	cmp r4, #0x10
	bgt _08298DE2
_08298E10:
	str r1, [r5]
	str r4, [r5, #4]
	mov r2, sb
	ldr r0, [r2, #8]
	adds r0, r0, r4
	str r0, [r2, #8]
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	cmp r0, #7
	ble _08298E32
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	bne _08298E80
_08298E32:
	ldr r0, [sp, #0x20c]
	ldr r4, [sp, #0x1f4]
	cmp r0, r4
	bge _08298E3C
	adds r0, r4, #0
_08298E3C:
	ldr r1, [sp, #0x1f0]
	adds r1, r1, r0
	str r1, [sp, #0x1f0]
	mov r2, sb
	ldr r0, [r2, #8]
	cmp r0, #0
	beq _08298E56
	ldr r0, [sp, #0x1e0]
	mov r1, sb
	bl sub_08297E9C
	cmp r0, #0
	bne _08298E80
_08298E56:
	movs r0, #0
	mov r4, sb
	str r0, [r4, #4]
	add r5, sp, #0x28
	bl _08297FFC
	.align 2, 0
_08298E64: .4byte 0x0890F15C
_08298E68:
	mov r1, sb
	ldr r0, [r1, #8]
	cmp r0, #0
	beq _08298E7A
	ldr r0, [sp, #0x1e0]
	bl sub_08297E9C
	cmp r0, #0
	bne _08298E80
_08298E7A:
	movs r0, #0
	mov r1, sb
	str r0, [r1, #4]
_08298E80:
	movs r0, #0x40
	ldr r2, [sp, #0x1e0]
	ldrh r2, [r2, #0xc]
	ands r0, r2
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	bne _08298E92
	ldr r1, [sp, #0x1f0]
_08298E92:
	adds r0, r1, #0
_08298E94:
	movs r3, #0x88
	lsls r3, r3, #2
	add sp, r3
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	thumb_func_end _vfprintf_r

thumb_func_start sub_08298EA4
sub_08298EA4: @ 0x08298EA4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #0x18]
	adds r5, r2, #0
	adds r4, r1, #0
	mov r8, r3
	ldr r6, [sp, #0x3c]
	ldr r0, [sp, #0x44]
	mov sl, r0
	ldr r1, [sp, #0x48]
	mov sb, r1
	cmp r1, #0x66
	bne _08298ECA
	movs r7, #3
	b _08298EDA
_08298ECA:
	mov r0, sb
	cmp r0, #0x65
	beq _08298ED4
	cmp r0, #0x45
	bne _08298ED8
_08298ED4:
	movs r1, #1
	add r8, r1
_08298ED8:
	movs r7, #2
_08298EDA:
	lsls r0, r4, #0x1f
	lsrs r0, r0, #0x1f
	cmp r0, #0
	beq _08298EF0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __negdf2
	adds r5, r1, #0
	adds r4, r0, #0
	movs r0, #0x2d
_08298EF0:
	ldr r1, [sp, #0x40]
	strb r0, [r1]
	mov r0, r8
	str r0, [sp]
	mov r1, sl
	str r1, [sp, #4]
	add r0, sp, #0x10
	str r0, [sp, #8]
	add r0, sp, #0x14
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x18]
	adds r2, r5, #0
	adds r1, r4, #0
	adds r3, r7, #0
	bl _dtoa_r
	adds r7, r0, #0
	mov r1, sb
	cmp r1, #0x67
	beq _08298F1C
	cmp r1, #0x47
	bne _08298F24
_08298F1C:
	movs r0, #1
	ands r6, r0
	cmp r6, #0
	beq _08298F78
_08298F24:
	mov r0, r8
	adds r6, r7, r0
	mov r1, sb
	cmp r1, #0x66
	bne _08298F54
	ldrb r0, [r7]
	cmp r0, #0x30
	bne _08298F4E
	ldr r3, _08298F94
	ldr r2, _08298F90
	adds r1, r5, #0
	adds r0, r4, #0
	bl __nedf2
	cmp r0, #0
	beq _08298F4E
	mov r1, r8
	rsbs r0, r1, #0
	adds r0, #1
	mov r1, sl
	str r0, [r1]
_08298F4E:
	mov r1, sl
	ldr r0, [r1]
	adds r6, r6, r0
_08298F54:
	ldr r3, _08298F94
	ldr r2, _08298F90
	adds r1, r5, #0
	adds r0, r4, #0
	bl __eqdf2
	cmp r0, #0
	bne _08298F66
	str r6, [sp, #0x14]
_08298F66:
	ldr r0, [sp, #0x14]
	cmp r0, r6
	bhs _08298F78
	movs r1, #0x30
_08298F6E:
	strb r1, [r0]
	adds r0, #1
	str r0, [sp, #0x14]
	cmp r0, r6
	blo _08298F6E
_08298F78:
	ldr r0, [sp, #0x14]
	subs r0, r0, r7
	ldr r1, [sp, #0x4c]
	str r0, [r1]
	adds r0, r7, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_08298F90: .4byte 0x00000000
_08298F94: .4byte 0x00000000
	thumb_func_end sub_08298EA4

thumb_func_start sub_08298F98
sub_08298F98: @ 0x08298F98
	push {r4, r5, r6, r7, lr}
	sub sp, #0x134
	adds r7, r0, #0
	adds r6, r1, #0
	strb r2, [r7]
	adds r5, r7, #1
	cmp r6, #0
	bge _08298FAE
	rsbs r6, r6, #0
	movs r0, #0x2d
	b _08298FB0
_08298FAE:
	movs r0, #0x2b
_08298FB0:
	strb r0, [r7, #1]
	adds r5, #1
	add r4, sp, #0x134
	cmp r6, #9
	ble _08298FF2
_08298FBA:
	subs r4, #1
	adds r0, r6, #0
	movs r1, #0xa
	bl __modsi3
	adds r0, #0x30
	strb r0, [r4]
	adds r0, r6, #0
	movs r1, #0xa
	bl __divsi3
	adds r6, r0, #0
	cmp r6, #9
	bgt _08298FBA
	subs r4, #1
	adds r0, #0x30
	strb r0, [r4]
	add r0, sp, #0x134
	cmp r4, r0
	bhs _08299000
	adds r1, r0, #0
_08298FE4:
	ldrb r0, [r4]
	strb r0, [r5]
	adds r4, #1
	adds r5, #1
	cmp r4, r1
	blo _08298FE4
	b _08299000
_08298FF2:
	movs r0, #0x30
	strb r0, [r5]
	adds r5, #1
	adds r0, r6, #0
	adds r0, #0x30
	strb r0, [r5]
	adds r5, #1
_08299000:
	subs r0, r5, r7
	add sp, #0x134
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	thumb_func_end sub_08298F98

thumb_func_start __swsetup
__swsetup: @ 0x08299008
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x54]
	cmp r0, #0
	bne _08299018
	ldr r0, _08299044
	ldr r0, [r0]
	str r0, [r4, #0x54]
_08299018:
	ldr r1, [r4, #0x54]
	ldr r0, [r1, #0x38]
	cmp r0, #0
	bne _08299026
	adds r0, r1, #0
	bl __sinit
_08299026:
	ldrh r1, [r4, #0xc]
	movs r0, #8
	ands r0, r1
	lsls r0, r0, #0x10
	asrs r5, r0, #0x10
	cmp r5, #0
	bne _08299080
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08299048
	movs r0, #1
	rsbs r0, r0, #0
	b _082990B2
	.align 2, 0
_08299044: .4byte 0x0203CF1C
_08299048:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08299078
	ldr r1, [r4, #0x30]
	cmp r1, #0
	beq _08299066
	adds r0, r4, #0
	adds r0, #0x40
	cmp r1, r0
	beq _08299064
	ldr r0, [r4, #0x54]
	bl _free_r
_08299064:
	str r5, [r4, #0x30]
_08299066:
	movs r0, #0x25
	rsbs r0, r0, #0
	ldrh r1, [r4, #0xc]
	ands r0, r1
	movs r1, #0
	strh r0, [r4, #0xc]
	str r1, [r4, #4]
	ldr r0, [r4, #0x10]
	str r0, [r4]
_08299078:
	movs r0, #8
	ldrh r1, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
_08299080:
	ldr r0, [r4, #0x10]
	cmp r0, #0
	bne _0829908C
	adds r0, r4, #0
	bl __smakebuf
_0829908C:
	ldrh r1, [r4, #0xc]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _082990A2
	movs r0, #0
	str r0, [r4, #8]
	ldr r0, [r4, #0x14]
	rsbs r0, r0, #0
	str r0, [r4, #0x18]
	b _082990B0
_082990A2:
	movs r0, #2
	ands r0, r1
	movs r1, #0
	cmp r0, #0
	bne _082990AE
	ldr r1, [r4, #0x14]
_082990AE:
	str r1, [r4, #8]
_082990B0:
	movs r0, #0
_082990B2:
	pop {r4, r5, pc}
	thumb_func_end __swsetup

thumb_func_start sub_082990B4
sub_082990B4: @ 0x082990B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp]
	str r1, [sp, #4]
	ldr r7, [r1, #0x10]
	ldr r0, [r0, #0x10]
	cmp r0, r7
	bge _082990D0
	movs r0, #0
	b _08299204
_082990D0:
	ldr r0, [sp, #4]
	adds r0, #0x14
	mov r8, r0
	subs r7, #1
	lsls r0, r7, #2
	mov r1, r8
	adds r1, r1, r0
	str r1, [sp, #0xc]
	ldr r4, [sp]
	adds r4, #0x14
	adds r5, r4, r0
	ldr r1, [r1]
	adds r1, #1
	ldr r2, [r5]
	mov sl, r2
	mov r0, sl
	bl __udivsi3
	str r0, [sp, #8]
	mov r3, r8
	str r3, [sp, #0x14]
	str r4, [sp, #0x10]
	cmp r0, #0
	beq _0829917A
	movs r6, #0
	mov sb, r6
	ldr r0, _08299164
	mov ip, r0
_08299108:
	mov r2, r8
	adds r2, #4
	mov r8, r2
	subs r2, #4
	ldm r2!, {r1}
	adds r0, r1, #0
	mov r3, ip
	ands r0, r3
	ldr r2, [sp, #8]
	muls r0, r2, r0
	mov r3, sb
	adds r2, r0, r3
	lsrs r0, r1, #0x10
	ldr r3, [sp, #8]
	adds r1, r0, #0
	muls r1, r3, r1
	lsrs r0, r2, #0x10
	adds r3, r1, r0
	lsrs r0, r3, #0x10
	mov sb, r0
	ldr r0, [r4]
	mov r1, ip
	ands r0, r1
	ands r2, r1
	subs r0, r0, r2
	adds r2, r0, r6
	asrs r6, r2, #0x10
	ldr r0, [r4]
	lsrs r1, r0, #0x10
	mov r0, ip
	ands r3, r0
	subs r1, r1, r3
	adds r0, r1, r6
	asrs r6, r0, #0x10
	strh r0, [r4]
	strh r2, [r4, #2]
	adds r4, #4
	ldr r1, [sp, #0xc]
	cmp r8, r1
	bls _08299108
	mov r2, sl
	cmp r2, #0
	bne _0829917A
	ldr r4, [sp, #0x10]
	b _0829916A
	.align 2, 0
_08299164: .4byte 0x0000FFFF
_08299168:
	subs r7, #1
_0829916A:
	subs r5, #4
	cmp r5, r4
	bls _08299176
	ldr r0, [r5]
	cmp r0, #0
	beq _08299168
_08299176:
	ldr r3, [sp]
	str r7, [r3, #0x10]
_0829917A:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl __mcmp
	cmp r0, #0
	blt _08299202
	ldr r0, [sp, #8]
	adds r0, #1
	str r0, [sp, #8]
	movs r6, #0
	mov sb, r6
	ldr r4, [sp, #0x10]
	ldr r1, [sp, #0x14]
	mov r8, r1
	lsls r2, r7, #2
	mov sl, r2
	ldr r5, _082991EC
_0829919C:
	mov r3, r8
	adds r3, #4
	mov r8, r3
	subs r3, #4
	ldm r3!, {r1}
	adds r0, r1, #0
	ands r0, r5
	mov r3, sb
	adds r2, r0, r3
	lsrs r1, r1, #0x10
	lsrs r0, r2, #0x10
	adds r3, r1, r0
	lsrs r0, r3, #0x10
	mov sb, r0
	ldr r1, [r4]
	adds r0, r1, #0
	ands r0, r5
	ands r2, r5
	subs r0, r0, r2
	adds r2, r0, r6
	asrs r6, r2, #0x10
	lsrs r1, r1, #0x10
	ands r3, r5
	subs r1, r1, r3
	adds r0, r1, r6
	asrs r6, r0, #0x10
	strh r0, [r4]
	strh r2, [r4, #2]
	adds r4, #4
	ldr r1, [sp, #0xc]
	cmp r8, r1
	bls _0829919C
	ldr r4, [sp, #0x10]
	mov r2, sl
	adds r5, r4, r2
	ldr r0, [r5]
	cmp r0, #0
	bne _08299202
	b _082991F2
	.align 2, 0
_082991EC: .4byte 0x0000FFFF
_082991F0:
	subs r7, #1
_082991F2:
	subs r5, #4
	cmp r5, r4
	bls _082991FE
	ldr r0, [r5]
	cmp r0, #0
	beq _082991F0
_082991FE:
	ldr r3, [sp]
	str r7, [r3, #0x10]
_08299202:
	ldr r0, [sp, #8]
_08299204:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	thumb_func_end sub_082990B4

thumb_func_start _dtoa_r
_dtoa_r: @ 0x08299210
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x84
	mov sl, r0
	str r3, [sp, #0xc]
	ldr r4, [sp, #0xac]
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	ldr r2, [r0, #0x40]
	cmp r2, #0
	beq _08299248
	ldr r0, [r0, #0x44]
	str r0, [r2, #4]
	mov r0, sl
	ldr r1, [r0, #0x44]
	movs r0, #1
	lsls r0, r1
	str r0, [r2, #8]
	mov r0, sl
	adds r1, r2, #0
	bl _Bfree
	movs r0, #0
	mov r1, sl
	str r0, [r1, #0x40]
_08299248:
	movs r0, #0x80
	lsls r0, r0, #0x18
	ldr r1, [sp, #0x40]
	ands r0, r1
	cmp r0, #0
	beq _08299264
	movs r0, #1
	str r0, [r4]
	ldr r0, _08299260
	ands r1, r0
	str r1, [sp, #0x40]
	b _08299266
	.align 2, 0
_08299260: .4byte 0x7FFFFFFF
_08299264:
	str r0, [r4]
_08299266:
	ldr r1, _082992A8
	ldr r2, [sp, #0x40]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, r1
	bne _082992BC
	ldr r0, _082992AC
	ldr r3, [sp, #0xa8]
	str r0, [r3]
	ldr r0, _082992B0
	mov sb, r0
	ldr r1, [sp, #0x44]
	cmp r1, #0
	bne _0829928E
	ldr r0, _082992B4
	ands r2, r0
	cmp r2, #0
	bne _0829928E
	ldr r2, _082992B8
	mov sb, r2
_0829928E:
	ldr r3, [sp, #0xb0]
	cmp r3, #0
	beq _082992E0
	mov r1, sb
	ldrb r0, [r1, #3]
	adds r1, #3
	cmp r0, #0
	beq _082992A0
	adds r1, #5
_082992A0:
	ldr r2, [sp, #0xb0]
	str r1, [r2]
	b _082992E0
	.align 2, 0
_082992A8: .4byte 0x7FF00000
_082992AC: .4byte 0x0000270F
_082992B0: .4byte 0x0890F1E4
_082992B4: .4byte 0x000FFFFF
_082992B8: .4byte 0x0890F1D8
_082992BC:
	ldr r3, _082992EC
	ldr r2, _082992E8
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __eqdf2
	cmp r0, #0
	bne _082992F4
	movs r0, #1
	ldr r3, [sp, #0xa8]
	str r0, [r3]
	ldr r0, _082992F0
	mov sb, r0
	ldr r1, [sp, #0xb0]
	cmp r1, #0
	beq _082992E0
	adds r0, #1
	str r0, [r1]
_082992E0:
	mov r0, sb
	bl _08299EFA
	.align 2, 0
_082992E8: .4byte 0x00000000
_082992EC: .4byte 0x00000000
_082992F0: .4byte 0x0890F1E8
_082992F4:
	add r0, sp, #8
	str r0, [sp]
	mov r0, sl
	ldr r1, [sp, #0x40]
	ldr r2, [sp, #0x44]
	add r3, sp, #4
	bl _d2b
	str r0, [sp, #0x5c]
	ldr r2, [sp, #0x40]
	lsls r0, r2, #1
	lsrs r0, r0, #0x15
	mov r8, r0
	cmp r0, #0
	beq _08299344
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	str r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	ldr r0, _08299338
	ldr r1, [sp, #0x48]
	ands r1, r0
	str r1, [sp, #0x48]
	ldr r0, _0829933C
	adds r2, r1, #0
	orrs r2, r0
	str r2, [sp, #0x48]
	ldr r3, _08299340
	add r8, r3
	movs r0, #0
	str r0, [sp, #0x58]
	ldr r6, [sp, #8]
	b _082993A4
	.align 2, 0
_08299338: .4byte 0x000FFFFF
_0829933C: .4byte 0x3FF00000
_08299340: .4byte 0xFFFFFC01
_08299344:
	ldr r1, [sp, #8]
	ldr r0, [sp, #4]
	adds r2, r1, r0
	ldr r3, _0829936C
	adds r3, r3, r2
	mov r8, r3
	adds r6, r1, #0
	cmp r3, #0x20
	ble _08299374
	movs r0, #0x40
	subs r0, r0, r3
	ldr r4, [sp, #0x40]
	lsls r4, r0
	ldr r1, _08299370
	adds r0, r2, r1
	ldr r2, [sp, #0x44]
	lsrs r2, r0
	adds r0, r2, #0
	orrs r4, r0
	b _0829937E
	.align 2, 0
_0829936C: .4byte 0x00000432
_08299370: .4byte 0x00000412
_08299374:
	movs r0, #0x20
	mov r3, r8
	subs r0, r0, r3
	ldr r4, [sp, #0x44]
	lsls r4, r0
_0829937E:
	adds r0, r4, #0
	bl __floatsidf
	cmp r4, #0
	bge _08299390
	ldr r3, _08299454
	ldr r2, _08299450
	bl __adddf3
_08299390:
	str r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	ldr r1, _08299458
	ldr r0, [sp, #0x48]
	adds r1, r0, r1
	str r1, [sp, #0x48]
	ldr r2, _0829945C
	add r8, r2
	movs r3, #1
	str r3, [sp, #0x58]
_082993A4:
	ldr r2, _08299460
	ldr r3, _08299464
	ldr r0, [sp, #0x48]
	ldr r1, [sp, #0x4c]
	bl __subdf3
	ldr r2, _08299468
	ldr r3, _0829946C
	bl __muldf3
	ldr r2, _08299470
	ldr r3, _08299474
	bl __adddf3
	adds r5, r1, #0
	adds r4, r0, #0
	mov r0, r8
	bl __floatsidf
	ldr r2, _08299478
	ldr r3, _0829947C
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __adddf3
	str r0, [sp, #0x6c]
	str r1, [sp, #0x70]
	bl __fixdfsi
	str r0, [sp, #0x24]
	ldr r2, _08299480
	ldr r3, _08299484
	ldr r0, [sp, #0x6c]
	ldr r1, [sp, #0x70]
	bl __ltdf2
	cmp r0, #0
	bge _08299414
	ldr r0, [sp, #0x24]
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x6c]
	ldr r1, [sp, #0x70]
	bl __nedf2
	cmp r0, #0
	beq _08299414
	ldr r0, [sp, #0x24]
	subs r0, #1
	str r0, [sp, #0x24]
_08299414:
	movs r1, #1
	str r1, [sp, #0x2c]
	ldr r2, [sp, #0x24]
	cmp r2, #0x16
	bhi _0829943E
	ldr r1, _08299488
	lsls r0, r2, #3
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r3, [r0, #4]
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __ltdf2
	cmp r0, #0
	bge _0829943A
	ldr r3, [sp, #0x24]
	subs r3, #1
	str r3, [sp, #0x24]
_0829943A:
	movs r0, #0
	str r0, [sp, #0x2c]
_0829943E:
	mov r1, r8
	subs r0, r6, r1
	subs r4, r0, #1
	cmp r4, #0
	blt _0829948C
	movs r2, #0
	str r2, [sp, #0x10]
	str r4, [sp, #0x34]
	b _08299494
	.align 2, 0
_08299450: .4byte 0x41F00000
_08299454: .4byte 0x00000000
_08299458: .4byte 0xFE100000
_0829945C: .4byte 0xFFFFFBCD
_08299460: .4byte 0x3FF80000
_08299464: .4byte 0x00000000
_08299468: .4byte 0x3FD287A7
_0829946C: .4byte 0x636F4361
_08299470: .4byte 0x3FC68A28
_08299474: .4byte 0x8B60C8B3
_08299478: .4byte 0x3FD34413
_0829947C: .4byte 0x509F79FB
_08299480: .4byte 0x00000000
_08299484: .4byte 0x00000000
_08299488: .4byte 0x0890F234
_0829948C:
	rsbs r4, r4, #0
	str r4, [sp, #0x10]
	movs r3, #0
	str r3, [sp, #0x34]
_08299494:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	blt _082994A8
	movs r1, #0
	str r1, [sp, #0x14]
	str r0, [sp, #0x38]
	ldr r2, [sp, #0x34]
	adds r2, r2, r0
	str r2, [sp, #0x34]
	b _082994B8
_082994A8:
	ldr r3, [sp, #0x10]
	ldr r0, [sp, #0x24]
	subs r3, r3, r0
	str r3, [sp, #0x10]
	rsbs r1, r0, #0
	str r1, [sp, #0x14]
	movs r2, #0
	str r2, [sp, #0x38]
_082994B8:
	ldr r3, [sp, #0xc]
	cmp r3, #9
	bls _082994C2
	movs r0, #0
	str r0, [sp, #0xc]
_082994C2:
	movs r5, #1
	ldr r1, [sp, #0xc]
	cmp r1, #5
	ble _082994D0
	subs r1, #4
	str r1, [sp, #0xc]
	movs r5, #0
_082994D0:
	movs r2, #1
	str r2, [sp, #0x30]
	ldr r3, [sp, #0xc]
	cmp r3, #5
	bhi _0829954A
	lsls r0, r3, #2
	ldr r1, _082994E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082994E4: .4byte 0x082994E8
_082994E8: @ jump table
	.4byte _08299500 @ case 0
	.4byte _08299500 @ case 1
	.4byte _08299512 @ case 2
	.4byte _0829952E @ case 3
	.4byte _08299516 @ case 4
	.4byte _08299532 @ case 5
_08299500:
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0x18]
	str r0, [sp, #0x20]
	movs r1, #0x12
	mov r8, r1
	movs r2, #0
	str r2, [sp, #0xa4]
	b _0829954A
_08299512:
	movs r3, #0
	str r3, [sp, #0x30]
_08299516:
	ldr r0, [sp, #0xa4]
	cmp r0, #0
	bgt _08299520
	movs r1, #1
	str r1, [sp, #0xa4]
_08299520:
	ldr r2, [sp, #0xa4]
	mov r8, r2
	mov r3, r8
	str r3, [sp, #0x20]
	mov r0, r8
	str r0, [sp, #0x18]
	b _0829954A
_0829952E:
	movs r1, #0
	str r1, [sp, #0x30]
_08299532:
	ldr r2, [sp, #0xa4]
	ldr r3, [sp, #0x24]
	adds r0, r2, r3
	adds r1, r0, #1
	mov r8, r1
	mov r2, r8
	str r2, [sp, #0x18]
	str r0, [sp, #0x20]
	cmp r1, #0
	bgt _0829954A
	movs r3, #1
	mov r8, r3
_0829954A:
	movs r4, #4
	movs r0, #0
	mov r1, sl
	str r0, [r1, #0x44]
	mov r2, r8
	cmp r2, #0x17
	bls _0829956A
	movs r1, #0
_0829955A:
	adds r1, #1
	lsls r4, r4, #1
	adds r0, r4, #0
	adds r0, #0x14
	cmp r0, r8
	bls _0829955A
	mov r3, sl
	str r1, [r3, #0x44]
_0829956A:
	mov r0, sl
	ldr r1, [r0, #0x44]
	bl _Balloc
	mov r1, sl
	str r0, [r1, #0x40]
	str r0, [sp, #0x74]
	mov sb, r0
	ldr r2, [sp, #0x18]
	cmp r2, #0xe
	bls _08299582
	b _082998F4
_08299582:
	cmp r5, #0
	bne _08299588
	b _082998F4
_08299588:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	str r0, [sp, #0x78]
	str r1, [sp, #0x7c]
	str r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	ldr r1, [sp, #0x24]
	str r1, [sp, #0x28]
	str r2, [sp, #0x1c]
	movs r7, #2
	cmp r1, #0
	ble _08299618
	ldr r0, _08299610
	movs r2, #0xf
	ands r1, r2
	lsls r1, r1, #3
	adds r3, r1, r0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [sp, #0x6c]
	str r1, [sp, #0x70]
	ldr r1, [sp, #0x24]
	asrs r4, r1, #4
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0
	beq _082995D4
	ands r4, r2
	ldr r0, _08299614
	ldr r2, [r0, #0x20]
	ldr r3, [r0, #0x24]
	ldr r0, [sp, #0x78]
	ldr r1, [sp, #0x7c]
	bl __divdf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	movs r7, #3
_082995D4:
	cmp r4, #0
	beq _082995FC
	ldr r5, _08299614
_082995DA:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _082995F4
	adds r7, #1
	ldr r2, [r5]
	ldr r3, [r5, #4]
	ldr r0, [sp, #0x6c]
	ldr r1, [sp, #0x70]
	bl __muldf3
	str r0, [sp, #0x6c]
	str r1, [sp, #0x70]
_082995F4:
	asrs r4, r4, #1
	adds r5, #8
	cmp r4, #0
	bne _082995DA
_082995FC:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	ldr r2, [sp, #0x6c]
	ldr r3, [sp, #0x70]
	bl __divdf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	b _08299664
	.align 2, 0
_08299610: .4byte 0x0890F234
_08299614: .4byte 0x0890F2FC
_08299618:
	ldr r2, [sp, #0x24]
	rsbs r6, r2, #0
	cmp r6, #0
	beq _08299664
	ldr r1, _0829970C
	movs r0, #0xf
	ands r0, r6
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	ldr r2, [sp, #0x78]
	ldr r3, [sp, #0x7c]
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	asrs r4, r6, #4
	cmp r4, #0
	beq _08299664
	ldr r5, _08299710
_08299642:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _0829965C
	adds r7, #1
	ldr r0, [r5]
	ldr r1, [r5, #4]
	ldr r2, [sp, #0x40]
	ldr r3, [sp, #0x44]
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
_0829965C:
	asrs r4, r4, #1
	adds r5, #8
	cmp r4, #0
	bne _08299642
_08299664:
	ldr r3, [sp, #0x2c]
	cmp r3, #0
	beq _082996A2
	ldr r2, _08299714
	ldr r3, _08299718
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __ltdf2
	cmp r0, #0
	bge _082996A2
	ldr r0, [sp, #0x18]
	cmp r0, #0
	ble _082996A2
	ldr r1, [sp, #0x20]
	cmp r1, #0
	bgt _08299688
	b _082998E0
_08299688:
	str r1, [sp, #0x18]
	ldr r2, [sp, #0x24]
	subs r2, #1
	str r2, [sp, #0x24]
	ldr r0, _0829971C
	ldr r1, _08299720
	ldr r2, [sp, #0x40]
	ldr r3, [sp, #0x44]
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	adds r7, #1
_082996A2:
	adds r0, r7, #0
	bl __floatsidf
	ldr r2, [sp, #0x40]
	ldr r3, [sp, #0x44]
	bl __muldf3
	ldr r2, _08299724
	ldr r3, _08299728
	bl __adddf3
	str r0, [sp, #0x50]
	str r1, [sp, #0x54]
	ldr r0, _0829972C
	ldr r3, [sp, #0x50]
	adds r0, r3, r0
	str r0, [sp, #0x50]
	ldr r1, [sp, #0x18]
	cmp r1, #0
	bne _08299738
	movs r2, #0
	str r2, [sp, #0x64]
	movs r3, #0
	str r3, [sp, #0x68]
	ldr r2, _08299730
	ldr r3, _08299734
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __gtdf2
	cmp r0, #0
	ble _082996F0
	b _08299C6A
_082996F0:
	ldr r0, [sp, #0x50]
	ldr r1, [sp, #0x54]
	bl __negdf2
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __ltdf2
	cmp r0, #0
	bge _0829970A
	b _08299C62
_0829970A:
	b _082998E0
	.align 2, 0
_0829970C: .4byte 0x0890F234
_08299710: .4byte 0x0890F2FC
_08299714: .4byte 0x3FF00000
_08299718: .4byte 0x00000000
_0829971C: .4byte 0x40240000
_08299720: .4byte 0x00000000
_08299724: .4byte 0x401C0000
_08299728: .4byte 0x00000000
_0829972C: .4byte 0xFCC00000
_08299730: .4byte 0x40140000
_08299734: .4byte 0x00000000
_08299738:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _08299808
	ldr r1, _08299768
	ldr r0, [sp, #0x18]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r3, [r0, #4]
	ldr r0, _0829976C
	ldr r1, _08299770
	bl __divdf3
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __subdf3
	str r0, [sp, #0x50]
	str r1, [sp, #0x54]
	movs r1, #0
	mov r8, r1
	b _08299794
	.align 2, 0
_08299768: .4byte 0x0890F234
_0829976C: .4byte 0x3FE00000
_08299770: .4byte 0x00000000
_08299774:
	ldr r1, _082997FC
	ldr r0, _082997F8
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __muldf3
	str r0, [sp, #0x50]
	str r1, [sp, #0x54]
	ldr r1, _082997FC
	ldr r0, _082997F8
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
_08299794:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __fixdfsi
	adds r6, r0, #0
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	adds r0, r6, #0
	adds r0, #0x30
	mov r2, sb
	strb r0, [r2]
	movs r3, #1
	add sb, r3
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __ltdf2
	cmp r0, #0
	bge _082997D0
	b _08299EDA
_082997D0:
	ldr r0, _08299800
	ldr r1, _08299804
	adds r3, r5, #0
	adds r2, r4, #0
	bl __subdf3
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __ltdf2
	cmp r0, #0
	bge _082997EA
	b _082999F4
_082997EA:
	movs r0, #1
	add r8, r0
	ldr r1, [sp, #0x18]
	cmp r8, r1
	blt _08299774
	b _082998E0
	.align 2, 0
_082997F8: .4byte 0x40240000
_082997FC: .4byte 0x00000000
_08299800: .4byte 0x3FF00000
_08299804: .4byte 0x00000000
_08299808:
	ldr r1, _08299828
	ldr r0, [sp, #0x18]
	subs r0, #1
	lsls r0, r0, #3
	adds r0, r0, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __muldf3
	str r0, [sp, #0x50]
	str r1, [sp, #0x54]
	movs r2, #1
	mov r8, r2
	b _08299840
	.align 2, 0
_08299828: .4byte 0x0890F234
_0829982C:
	movs r3, #1
	add r8, r3
	ldr r1, _082998D4
	ldr r0, _082998D0
	adds r3, r5, #0
	adds r2, r4, #0
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
_08299840:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __fixdfsi
	adds r6, r0, #0
	bl __floatsidf
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __subdf3
	adds r5, r1, #0
	adds r4, r0, #0
	adds r0, r6, #0
	adds r0, #0x30
	mov r1, sb
	strb r0, [r1]
	movs r2, #1
	add sb, r2
	ldr r3, [sp, #0x18]
	cmp r8, r3
	bne _0829982C
	ldr r6, _082998D8
	ldr r7, _082998DC
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __adddf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __gtdf2
	cmp r0, #0
	ble _08299892
	b _082999F4
_08299892:
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl __ltdf2
	cmp r0, #0
	bge _082998E0
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	ldrb r1, [r1]
	cmp r1, #0x30
	beq _082998BE
	b _08299A1A
_082998BE:
	movs r2, #1
	rsbs r2, r2, #0
	add sb, r2
	mov r3, sb
	ldrb r3, [r3]
	cmp r3, #0x30
	beq _082998BE
	b _08299A1A
	.align 2, 0
_082998D0: .4byte 0x40240000
_082998D4: .4byte 0x00000000
_082998D8: .4byte 0x3FE00000
_082998DC: .4byte 0x00000000
_082998E0:
	ldr r1, [sp, #0x74]
	mov sb, r1
	ldr r2, [sp, #0x48]
	ldr r3, [sp, #0x4c]
	str r2, [sp, #0x40]
	str r3, [sp, #0x44]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x24]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x18]
_082998F4:
	ldr r0, [sp, #4]
	cmp r0, #0
	bge _082998FC
	b _08299A30
_082998FC:
	ldr r1, [sp, #0x24]
	cmp r1, #0xe
	ble _08299904
	b _08299A30
_08299904:
	ldr r1, _08299950
	ldr r2, [sp, #0x24]
	lsls r0, r2, #3
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, [r0, #4]
	str r1, [sp, #0x6c]
	str r2, [sp, #0x70]
	ldr r2, [sp, #0xa4]
	cmp r2, #0
	bge _0829995C
	ldr r3, [sp, #0x18]
	cmp r3, #0
	bgt _0829995C
	movs r0, #0
	str r0, [sp, #0x64]
	movs r1, #0
	str r1, [sp, #0x68]
	cmp r3, #0
	bge _0829992E
	b _08299C62
_0829992E:
	ldr r2, _08299954
	ldr r3, _08299958
	ldr r0, [sp, #0x6c]
	ldr r1, [sp, #0x70]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __ledf2
	cmp r0, #0
	bgt _0829994C
	b _08299C62
_0829994C:
	b _08299C6A
	.align 2, 0
_08299950: .4byte 0x0890F234
_08299954: .4byte 0x40140000
_08299958: .4byte 0x00000000
_0829995C:
	movs r2, #1
	mov r8, r2
	b _08299980
_08299962:
	ldr r1, _08299A24
	ldr r0, _08299A20
	bl __muldf3
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	ldr r2, _08299A28
	ldr r3, _08299A2C
	bl __eqdf2
	cmp r0, #0
	bne _0829997C
	b _08299EDA
_0829997C:
	movs r3, #1
	add r8, r3
_08299980:
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	ldr r2, [sp, #0x6c]
	ldr r3, [sp, #0x70]
	bl __divdf3
	bl __fixdfsi
	adds r6, r0, #0
	bl __floatsidf
	ldr r2, [sp, #0x6c]
	ldr r3, [sp, #0x70]
	bl __muldf3
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl __subdf3
	adds r3, r1, #0
	adds r2, r0, #0
	adds r0, r6, #0
	adds r0, #0x30
	mov r1, sb
	strb r0, [r1]
	movs r0, #1
	add sb, r0
	ldr r1, [sp, #0x18]
	cmp r8, r1
	bne _08299962
	adds r1, r3, #0
	adds r0, r2, #0
	bl __adddf3
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, [sp, #0x6c]
	ldr r3, [sp, #0x70]
	bl __gtdf2
	cmp r0, #0
	bgt _082999F4
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x6c]
	ldr r3, [sp, #0x70]
	bl __eqdf2
	cmp r0, #0
	beq _082999EA
	b _08299EDA
_082999EA:
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	bne _082999F4
	b _08299EDA
_082999F4:
	movs r0, #0x30
_082999F6:
	movs r2, #1
	rsbs r2, r2, #0
	add sb, r2
	mov r3, sb
	ldrb r3, [r3]
	cmp r3, #0x39
	bne _08299A12
	ldr r1, [sp, #0x74]
	cmp sb, r1
	bne _082999F6
	ldr r2, [sp, #0x24]
	adds r2, #1
	str r2, [sp, #0x24]
	strb r0, [r1]
_08299A12:
	mov r3, sb
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
_08299A1A:
	movs r0, #1
	add sb, r0
	b _08299EDA
	.align 2, 0
_08299A20: .4byte 0x40240000
_08299A24: .4byte 0x00000000
_08299A28: .4byte 0x00000000
_08299A2C: .4byte 0x00000000
_08299A30:
	ldr r5, [sp, #0x10]
	ldr r6, [sp, #0x14]
	movs r1, #0
	str r1, [sp, #0x60]
	movs r2, #0
	str r2, [sp, #0x64]
	ldr r3, [sp, #0x30]
	cmp r3, #0
	beq _08299AA6
	ldr r1, [sp, #0xc]
	cmp r1, #1
	bgt _08299A64
	ldr r2, [sp, #0x58]
	cmp r2, #0
	beq _08299A5C
	ldr r3, _08299A58
	adds r3, r3, r0
	mov r8, r3
	b _08299A90
	.align 2, 0
_08299A58: .4byte 0x00000433
_08299A5C:
	ldr r1, [sp, #8]
	movs r0, #0x36
	subs r0, r0, r1
	b _08299A8E
_08299A64:
	ldr r4, [sp, #0x18]
	subs r4, #1
	ldr r0, [sp, #0x14]
	cmp r0, r4
	blt _08299A72
	subs r6, r0, r4
	b _08299A82
_08299A72:
	ldr r1, [sp, #0x14]
	subs r4, r4, r1
	ldr r2, [sp, #0x38]
	adds r2, r2, r4
	str r2, [sp, #0x38]
	adds r1, r1, r4
	str r1, [sp, #0x14]
	movs r6, #0
_08299A82:
	ldr r3, [sp, #0x18]
	mov r8, r3
	cmp r3, #0
	bge _08299A90
	subs r5, r5, r3
	movs r0, #0
_08299A8E:
	mov r8, r0
_08299A90:
	ldr r1, [sp, #0x10]
	add r1, r8
	str r1, [sp, #0x10]
	ldr r2, [sp, #0x34]
	add r2, r8
	str r2, [sp, #0x34]
	mov r0, sl
	movs r1, #1
	bl _i2b
	str r0, [sp, #0x64]
_08299AA6:
	cmp r5, #0
	ble _08299AC8
	ldr r3, [sp, #0x34]
	cmp r3, #0
	ble _08299AC8
	mov r8, r3
	cmp r8, r5
	ble _08299AB8
	mov r8, r5
_08299AB8:
	ldr r0, [sp, #0x10]
	mov r1, r8
	subs r0, r0, r1
	str r0, [sp, #0x10]
	subs r5, r5, r1
	ldr r2, [sp, #0x34]
	subs r2, r2, r1
	str r2, [sp, #0x34]
_08299AC8:
	ldr r3, [sp, #0x14]
	cmp r3, #0
	ble _08299B16
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _08299B0A
	cmp r6, #0
	ble _08299AFA
	mov r0, sl
	ldr r1, [sp, #0x64]
	adds r2, r6, #0
	bl _pow5mult
	str r0, [sp, #0x64]
	mov r0, sl
	ldr r1, [sp, #0x64]
	ldr r2, [sp, #0x5c]
	bl _multiply
	adds r4, r0, #0
	mov r0, sl
	ldr r1, [sp, #0x5c]
	bl _Bfree
	str r4, [sp, #0x5c]
_08299AFA:
	ldr r1, [sp, #0x14]
	subs r4, r1, r6
	cmp r4, #0
	beq _08299B16
	mov r0, sl
	ldr r1, [sp, #0x5c]
	adds r2, r4, #0
	b _08299B10
_08299B0A:
	mov r0, sl
	ldr r1, [sp, #0x5c]
	ldr r2, [sp, #0x14]
_08299B10:
	bl _pow5mult
	str r0, [sp, #0x5c]
_08299B16:
	mov r0, sl
	movs r1, #1
	bl _i2b
	str r0, [sp, #0x68]
	ldr r2, [sp, #0x38]
	cmp r2, #0
	ble _08299B30
	mov r0, sl
	ldr r1, [sp, #0x68]
	bl _pow5mult
	str r0, [sp, #0x68]
_08299B30:
	ldr r3, [sp, #0xc]
	cmp r3, #1
	bgt _08299B6C
	ldr r0, [sp, #0x44]
	cmp r0, #0
	bne _08299B68
	ldr r0, _08299B60
	ldr r1, [sp, #0x40]
	ands r0, r1
	cmp r0, #0
	bne _08299B68
	ldr r0, _08299B64
	ands r1, r0
	cmp r1, #0
	beq _08299B68
	ldr r1, [sp, #0x10]
	adds r1, #1
	str r1, [sp, #0x10]
	ldr r2, [sp, #0x34]
	adds r2, #1
	str r2, [sp, #0x34]
	movs r3, #1
	str r3, [sp, #0x3c]
	b _08299B6C
	.align 2, 0
_08299B60: .4byte 0x000FFFFF
_08299B64: .4byte 0x7FF00000
_08299B68:
	movs r0, #0
	str r0, [sp, #0x3c]
_08299B6C:
	ldr r1, [sp, #0x38]
	cmp r1, #0
	beq _08299B98
	ldr r2, [sp, #0x68]
	ldr r1, [r2, #0x10]
	subs r1, #1
	lsls r1, r1, #2
	adds r0, r2, #0
	adds r0, #0x14
	adds r0, r0, r1
	ldr r0, [r0]
	bl _hi0bits
	ldr r1, [sp, #0x34]
	adds r1, #0x20
	subs r1, r1, r0
	mov r8, r1
	movs r0, #0x1f
	mov r3, r8
	ands r3, r0
	mov r8, r3
	b _08299BA6
_08299B98:
	ldr r0, [sp, #0x34]
	adds r0, #1
	mov r8, r0
	movs r0, #0x1f
	mov r1, r8
	ands r1, r0
	mov r8, r1
_08299BA6:
	mov r2, r8
	cmp r2, #0
	beq _08299BB2
	movs r0, #0x20
	subs r2, r0, r2
	mov r8, r2
_08299BB2:
	mov r3, r8
	cmp r3, #4
	ble _08299BBE
	movs r0, #4
	rsbs r0, r0, #0
	b _08299BC6
_08299BBE:
	mov r3, r8
	cmp r3, #3
	bgt _08299BD6
	movs r0, #0x1c
_08299BC6:
	add r8, r0
	ldr r1, [sp, #0x10]
	add r1, r8
	str r1, [sp, #0x10]
	add r5, r8
	ldr r2, [sp, #0x34]
	add r2, r8
	str r2, [sp, #0x34]
_08299BD6:
	ldr r3, [sp, #0x10]
	cmp r3, #0
	ble _08299BE8
	mov r0, sl
	ldr r1, [sp, #0x5c]
	adds r2, r3, #0
	bl _lshift
	str r0, [sp, #0x5c]
_08299BE8:
	ldr r0, [sp, #0x34]
	cmp r0, #0
	ble _08299BFA
	mov r0, sl
	ldr r1, [sp, #0x68]
	ldr r2, [sp, #0x34]
	bl _lshift
	str r0, [sp, #0x68]
_08299BFA:
	ldr r1, [sp, #0x2c]
	cmp r1, #0
	beq _08299C38
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl __mcmp
	cmp r0, #0
	bge _08299C38
	ldr r2, [sp, #0x24]
	subs r2, #1
	str r2, [sp, #0x24]
	mov r0, sl
	ldr r1, [sp, #0x5c]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x30]
	cmp r3, #0
	beq _08299C34
	mov r0, sl
	ldr r1, [sp, #0x64]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x64]
_08299C34:
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x18]
_08299C38:
	ldr r1, [sp, #0x18]
	cmp r1, #0
	bgt _08299C7C
	ldr r2, [sp, #0xc]
	cmp r2, #2
	ble _08299C7C
	cmp r1, #0
	blt _08299C62
	mov r0, sl
	ldr r1, [sp, #0x68]
	movs r2, #5
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x68]
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl __mcmp
	cmp r0, #0
	bgt _08299C6A
_08299C62:
	ldr r3, [sp, #0xa4]
	mvns r3, r3
	str r3, [sp, #0x24]
	b _08299EB2
_08299C6A:
	movs r0, #0x31
	mov r1, sb
	strb r0, [r1]
	movs r2, #1
	add sb, r2
	ldr r3, [sp, #0x24]
	adds r3, #1
	str r3, [sp, #0x24]
	b _08299EB2
_08299C7C:
	ldr r0, [sp, #0x30]
	cmp r0, #0
	bne _08299C84
	b _08299DFA
_08299C84:
	cmp r5, #0
	ble _08299C94
	mov r0, sl
	ldr r1, [sp, #0x64]
	adds r2, r5, #0
	bl _lshift
	str r0, [sp, #0x64]
_08299C94:
	ldr r1, [sp, #0x64]
	str r1, [sp, #0x60]
	ldr r2, [sp, #0x3c]
	cmp r2, #0
	beq _08299CC6
	ldr r1, [r1, #4]
	mov r0, sl
	bl _Balloc
	str r0, [sp, #0x64]
	adds r0, #0xc
	ldr r1, [sp, #0x60]
	adds r1, #0xc
	ldr r3, [sp, #0x60]
	ldr r2, [r3, #0x10]
	lsls r2, r2, #2
	adds r2, #8
	bl memcpy
	mov r0, sl
	ldr r1, [sp, #0x64]
	movs r2, #1
	bl _lshift
	str r0, [sp, #0x64]
_08299CC6:
	movs r0, #1
	mov r8, r0
	mov r1, r8
	ldr r2, [sp, #0x44]
	ands r2, r1
	str r2, [sp, #0x80]
	b _08299D1C
_08299CD4:
	mov r0, sl
	ldr r1, [sp, #0x5c]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x60]
	ldr r0, [sp, #0x64]
	cmp r3, r0
	bne _08299CFC
	mov r0, sl
	ldr r1, [sp, #0x64]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x64]
	str r0, [sp, #0x60]
	b _08299D18
_08299CFC:
	mov r0, sl
	ldr r1, [sp, #0x60]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x60]
	mov r0, sl
	ldr r1, [sp, #0x64]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x64]
_08299D18:
	movs r1, #1
	add r8, r1
_08299D1C:
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl sub_082990B4
	adds r7, r0, #0
	adds r7, #0x30
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x60]
	bl __mcmp
	adds r4, r0, #0
	mov r0, sl
	ldr r1, [sp, #0x68]
	ldr r2, [sp, #0x64]
	bl __mdiff
	adds r5, r0, #0
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne _08299D50
	ldr r0, [sp, #0x5c]
	adds r1, r5, #0
	bl __mcmp
	adds r6, r0, #0
	b _08299D52
_08299D50:
	movs r6, #1
_08299D52:
	mov r0, sl
	adds r1, r5, #0
	bl _Bfree
	cmp r6, #0
	bne _08299D7E
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _08299D7E
	ldr r3, [sp, #0x80]
	cmp r3, #0
	bne _08299D7E
	cmp r7, #0x39
	beq _08299DD0
	cmp r4, #0
	ble _08299D74
	adds r7, #1
_08299D74:
	mov r0, sb
	strb r7, [r0]
	movs r1, #1
	add sb, r1
	b _08299EB2
_08299D7E:
	cmp r4, #0
	blt _08299D92
	cmp r4, #0
	bne _08299DC8
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _08299DC8
	ldr r3, [sp, #0x80]
	cmp r3, #0
	bne _08299DC8
_08299D92:
	cmp r6, #0
	ble _08299DC2
	mov r0, sl
	ldr r1, [sp, #0x5c]
	movs r2, #1
	bl _lshift
	str r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl __mcmp
	adds r6, r0, #0
	cmp r6, #0
	bgt _08299DBC
	cmp r6, #0
	bne _08299DC2
	adds r0, r7, #0
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08299DC2
_08299DBC:
	adds r7, #1
	cmp r7, #0x3a
	beq _08299DD0
_08299DC2:
	mov r2, sb
	strb r7, [r2]
	b _08299E7A
_08299DC8:
	cmp r6, #0
	ble _08299DE8
	cmp r7, #0x39
	bne _08299DDC
_08299DD0:
	movs r0, #0x39
	mov r1, sb
	strb r0, [r1]
	movs r2, #1
	add sb, r2
	b _08299E50
_08299DDC:
	adds r0, r7, #1
	mov r3, sb
	strb r0, [r3]
	movs r0, #1
	add sb, r0
	b _08299EB2
_08299DE8:
	mov r1, sb
	strb r7, [r1]
	movs r2, #1
	add sb, r2
	ldr r3, [sp, #0x18]
	cmp r8, r3
	beq _08299DF8
	b _08299CD4
_08299DF8:
	b _08299E2C
_08299DFA:
	movs r0, #1
	mov r8, r0
	b _08299E12
_08299E00:
	mov r0, sl
	ldr r1, [sp, #0x5c]
	movs r2, #0xa
	movs r3, #0
	bl _multadd
	str r0, [sp, #0x5c]
	movs r1, #1
	add r8, r1
_08299E12:
	ldr r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl sub_082990B4
	adds r7, r0, #0
	adds r7, #0x30
	mov r2, sb
	strb r7, [r2]
	movs r3, #1
	add sb, r3
	ldr r0, [sp, #0x18]
	cmp r8, r0
	blt _08299E00
_08299E2C:
	mov r0, sl
	ldr r1, [sp, #0x5c]
	movs r2, #1
	bl _lshift
	str r0, [sp, #0x5c]
	ldr r1, [sp, #0x68]
	bl __mcmp
	adds r4, r0, #0
	cmp r4, #0
	bgt _08299E50
	cmp r4, #0
	bne _08299E92
	movs r0, #1
	ands r7, r0
	cmp r7, #0
	beq _08299E92
_08299E50:
	movs r1, #1
	rsbs r1, r1, #0
	add sb, r1
	mov r2, sb
	ldrb r2, [r2]
	cmp r2, #0x39
	bne _08299E72
_08299E5E:
	ldr r3, [sp, #0x74]
	cmp sb, r3
	beq _08299E80
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	ldrb r1, [r1]
	cmp r1, #0x39
	beq _08299E5E
_08299E72:
	mov r2, sb
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
_08299E7A:
	movs r3, #1
	add sb, r3
	b _08299EB2
_08299E80:
	ldr r0, [sp, #0x24]
	adds r0, #1
	str r0, [sp, #0x24]
	movs r0, #0x31
	ldr r1, [sp, #0x74]
	strb r0, [r1]
	adds r1, #1
	mov sb, r1
	b _08299EB2
_08299E92:
	movs r2, #1
	rsbs r2, r2, #0
	add sb, r2
	mov r3, sb
	ldrb r3, [r3]
	cmp r3, #0x30
	bne _08299EAE
_08299EA0:
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	ldrb r1, [r1]
	cmp r1, #0x30
	beq _08299EA0
_08299EAE:
	movs r2, #1
	add sb, r2
_08299EB2:
	mov r0, sl
	ldr r1, [sp, #0x68]
	bl _Bfree
	ldr r3, [sp, #0x64]
	cmp r3, #0
	beq _08299EDA
	ldr r0, [sp, #0x60]
	cmp r0, #0
	beq _08299ED2
	cmp r0, r3
	beq _08299ED2
	mov r0, sl
	ldr r1, [sp, #0x60]
	bl _Bfree
_08299ED2:
	mov r0, sl
	ldr r1, [sp, #0x64]
	bl _Bfree
_08299EDA:
	mov r0, sl
	ldr r1, [sp, #0x5c]
	bl _Bfree
	movs r0, #0
	mov r1, sb
	strb r0, [r1]
	ldr r0, [sp, #0x24]
	adds r0, #1
	ldr r2, [sp, #0xa8]
	str r0, [r2]
	ldr r3, [sp, #0xb0]
	cmp r3, #0
	beq _08299EF8
	str r1, [r3]
_08299EF8:
	ldr r0, [sp, #0x74]
_08299EFA:
	add sp, #0x84
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	thumb_func_end _dtoa_r

thumb_func_start fflush
fflush: @ 0x08299F08
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	cmp r4, #0
	bne _08299F24
	ldr r0, _08299F1C
	ldr r0, [r0]
	ldr r1, _08299F20
	bl _fwalk
	b _08299F9A
	.align 2, 0
_08299F1C: .4byte 0x0203CF1C
_08299F20: .4byte 0x08299F09
_08299F24:
	ldr r0, [r4, #0x54]
	cmp r0, #0
	bne _08299F30
	ldr r0, _08299F64
	ldr r0, [r0]
	str r0, [r4, #0x54]
_08299F30:
	ldr r1, [r4, #0x54]
	ldr r0, [r1, #0x38]
	cmp r0, #0
	bne _08299F3E
	adds r0, r1, #0
	bl __sinit
_08299F3E:
	movs r0, #0xc
	ldrsh r1, [r4, r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08299F98
	ldr r6, [r4, #0x10]
	cmp r6, #0
	beq _08299F98
	ldr r0, [r4]
	subs r5, r0, r6
	str r6, [r4]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _08299F76
	ldr r0, [r4, #0x14]
	b _08299F78
	.align 2, 0
_08299F64: .4byte 0x0203CF1C
_08299F68:
	movs r0, #0x40
	ldrh r1, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
	movs r0, #1
	rsbs r0, r0, #0
	b _08299F9A
_08299F76:
	movs r0, #0
_08299F78:
	str r0, [r4, #8]
	cmp r5, #0
	ble _08299F98
_08299F7E:
	ldr r0, [r4, #0x1c]
	ldr r3, [r4, #0x24]
	adds r1, r6, #0
	adds r2, r5, #0
	bl _call_via_r3
	adds r1, r0, #0
	cmp r1, #0
	ble _08299F68
	adds r6, r6, r1
	subs r5, r5, r1
	cmp r5, #0
	bgt _08299F7E
_08299F98:
	movs r0, #0
_08299F9A:
	pop {r4, r5, r6, pc}
	thumb_func_end fflush

thumb_func_start sub_08299F9C
sub_08299F9C: @ 0x08299F9C
	push {r4, lr}
	movs r4, #0
	str r4, [r0]
	str r4, [r0, #4]
	str r4, [r0, #8]
	strh r1, [r0, #0xc]
	strh r2, [r0, #0xe]
	str r4, [r0, #0x10]
	str r4, [r0, #0x18]
	str r0, [r0, #0x1c]
	ldr r1, _08299FC4
	str r1, [r0, #0x20]
	ldr r1, _08299FC8
	str r1, [r0, #0x24]
	ldr r1, _08299FCC
	str r1, [r0, #0x28]
	ldr r1, _08299FD0
	str r1, [r0, #0x2c]
	str r3, [r0, #0x54]
	pop {r4, pc}
	.align 2, 0
_08299FC4: .4byte 0x0829B6C5
_08299FC8: .4byte 0x0829B6F9
_08299FCC: .4byte 0x0829B739
_08299FD0: .4byte 0x0829B779
	thumb_func_end sub_08299F9C

thumb_func_start __sfmoreglue
__sfmoreglue: @ 0x08299FD4
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	movs r1, #0x58
	adds r6, r5, #0
	muls r6, r1, r6
	adds r1, r6, #0
	adds r1, #0xc
	bl _malloc_r
	adds r4, r0, #0
	cmp r4, #0
	beq _0829A000
	adds r0, #0xc
	movs r1, #0
	str r1, [r4]
	str r5, [r4, #4]
	str r0, [r4, #8]
	adds r2, r6, #0
	bl memset
	adds r0, r4, #0
	b _0829A002
_0829A000:
	movs r0, #0
_0829A002:
	pop {r4, r5, r6, pc}
	thumb_func_end __sfmoreglue

thumb_func_start __sfp
__sfp: @ 0x0829A004
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x38]
	cmp r0, #0
	bne _0829A014
	adds r0, r5, #0
	bl __sinit
_0829A014:
	movs r0, #0xec
	lsls r0, r0, #1
	adds r4, r5, r0
	b _0829A01E
_0829A01C:
	ldr r4, [r4]
_0829A01E:
	ldr r2, [r4, #8]
	ldr r0, [r4, #4]
	b _0829A02E
_0829A024:
	movs r3, #0xc
	ldrsh r1, [r2, r3]
	cmp r1, #0
	beq _0829A050
	adds r2, #0x58
_0829A02E:
	subs r0, #1
	cmp r0, #0
	bge _0829A024
	ldr r0, [r4]
	cmp r0, #0
	bne _0829A01C
	adds r0, r5, #0
	movs r1, #4
	bl __sfmoreglue
	str r0, [r4]
	cmp r0, #0
	bne _0829A01C
	movs r0, #0xc
	str r0, [r5]
	movs r0, #0
	b _0829A070
_0829A050:
	movs r0, #1
	strh r0, [r2, #0xc]
	str r1, [r2]
	str r1, [r2, #8]
	str r1, [r2, #4]
	str r1, [r2, #0x10]
	str r1, [r2, #0x14]
	str r1, [r2, #0x18]
	ldr r0, _0829A074
	strh r0, [r2, #0xe]
	str r1, [r2, #0x30]
	str r1, [r2, #0x34]
	str r1, [r2, #0x44]
	str r1, [r2, #0x48]
	str r5, [r2, #0x54]
	adds r0, r2, #0
_0829A070:
	pop {r4, r5, pc}
	.align 2, 0
_0829A074: .4byte 0x0000FFFF
	thumb_func_end __sfp

thumb_func_start _cleanup_r
_cleanup_r: @ 0x0829A078
	push {lr}
	ldr r1, _0829A084
	bl _fwalk
	pop {pc}
	.align 2, 0
_0829A084: .4byte 0x08299F09
	thumb_func_end _cleanup_r

thumb_func_start _cleanup
_cleanup: @ 0x0829A088
	push {lr}
	ldr r0, _0829A094
	ldr r0, [r0]
	bl _cleanup_r
	pop {pc}
	.align 2, 0
_0829A094: .4byte 0x0203CF1C
	thumb_func_end _cleanup

thumb_func_start __sinit
__sinit: @ 0x0829A098
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0829A0F4
	str r0, [r5, #0x3c]
	movs r0, #1
	str r0, [r5, #0x38]
	movs r0, #0xf2
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r0, r4, #0
	movs r1, #4
	movs r2, #0
	adds r3, r5, #0
	bl sub_08299F9C
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #9
	movs r2, #1
	adds r3, r5, #0
	bl sub_08299F9C
	movs r1, #0xa5
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r1, #0xa
	movs r2, #2
	adds r3, r5, #0
	bl sub_08299F9C
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	movs r0, #0xee
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #3
	str r0, [r1]
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r5, r1
	str r4, [r0]
	pop {r4, r5, pc}
	.align 2, 0
_0829A0F4: .4byte 0x0829A079
	thumb_func_end __sinit

thumb_func_start _free_r
_free_r: @ 0x0829A0F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r4, r1, #0
	cmp r4, #0
	bne _0829A10A
	b _0829A2AE
_0829A10A:
	bl __malloc_lock
	adds r5, r4, #0
	subs r5, #8
	ldr r1, [r5, #4]
	movs r6, #2
	rsbs r6, r6, #0
	ands r6, r1
	adds r7, r5, r6
	ldr r4, [r7, #4]
	movs r0, #4
	rsbs r0, r0, #0
	ands r4, r0
	ldr r0, _0829A16C
	mov ip, r0
	ldr r0, [r0, #8]
	cmp r7, r0
	bne _0829A178
	adds r6, r6, r4
	movs r4, #1
	ands r1, r4
	cmp r1, #0
	bne _0829A146
	ldr r0, [r5]
	subs r5, r5, r0
	adds r6, r6, r0
	ldr r3, [r5, #0xc]
	ldr r2, [r5, #8]
	str r3, [r2, #0xc]
	str r2, [r3, #8]
_0829A146:
	adds r0, r6, #0
	orrs r0, r4
	str r0, [r5, #4]
	mov r2, ip
	str r5, [r2, #8]
	ldr r0, _0829A170
	ldr r0, [r0]
	cmp r6, r0
	blo _0829A162
	ldr r0, _0829A174
	ldr r1, [r0]
	mov r0, sb
	bl _malloc_trim_r
_0829A162:
	mov r0, sb
	bl __malloc_unlock
	b _0829A2AE
	.align 2, 0
_0829A16C: .4byte 0x0203CF34
_0829A170: .4byte 0x0203D33C
_0829A174: .4byte 0x0203D340
_0829A178:
	str r4, [r7, #4]
	movs r0, #0
	mov r8, r0
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0829A1A4
	ldr r0, [r5]
	subs r5, r5, r0
	adds r6, r6, r0
	ldr r1, [r5, #8]
	mov r0, ip
	adds r0, #8
	cmp r1, r0
	bne _0829A19C
	movs r2, #1
	mov r8, r2
	b _0829A1A4
_0829A19C:
	ldr r3, [r5, #0xc]
	adds r2, r1, #0
	str r3, [r2, #0xc]
	str r2, [r3, #8]
_0829A1A4:
	adds r0, r7, r4
	ldr r0, [r0, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0829A1DC
	adds r6, r6, r4
	ldr r1, [r7, #8]
	mov r0, r8
	cmp r0, #0
	bne _0829A1D4
	ldr r0, _0829A1D0
	cmp r1, r0
	bne _0829A1D4
	movs r2, #1
	mov r8, r2
	str r5, [r1, #0xc]
	str r5, [r1, #8]
	str r1, [r5, #0xc]
	str r1, [r5, #8]
	b _0829A1DC
	.align 2, 0
_0829A1D0: .4byte 0x0203CF3C
_0829A1D4:
	ldr r3, [r7, #0xc]
	adds r2, r1, #0
	str r3, [r2, #0xc]
	str r2, [r3, #8]
_0829A1DC:
	movs r1, #1
	adds r0, r6, #0
	orrs r0, r1
	str r0, [r5, #4]
	adds r0, r5, r6
	str r6, [r0]
	mov r0, r8
	cmp r0, #0
	bne _0829A2A8
	ldr r0, _0829A20C
	cmp r6, r0
	bhi _0829A214
	lsrs r4, r6, #3
	ldr r2, _0829A210
	adds r0, r4, #0
	asrs r0, r0, #2
	lsls r1, r0
	ldr r0, [r2, #4]
	orrs r0, r1
	str r0, [r2, #4]
	lsls r0, r4, #3
	adds r3, r0, r2
	ldr r2, [r3, #8]
	b _0829A2A0
	.align 2, 0
_0829A20C: .4byte 0x000001FF
_0829A210: .4byte 0x0203CF34
_0829A214:
	lsrs r1, r6, #9
	cmp r1, #0
	bne _0829A21E
	lsrs r4, r6, #3
	b _0829A266
_0829A21E:
	cmp r1, #4
	bhi _0829A22A
	lsrs r0, r6, #6
	adds r4, r0, #0
	adds r4, #0x38
	b _0829A266
_0829A22A:
	cmp r1, #0x14
	bhi _0829A234
	adds r4, r1, #0
	adds r4, #0x5b
	b _0829A266
_0829A234:
	cmp r1, #0x54
	bhi _0829A240
	lsrs r0, r6, #0xc
	adds r4, r0, #0
	adds r4, #0x6e
	b _0829A266
_0829A240:
	movs r0, #0xaa
	lsls r0, r0, #1
	cmp r1, r0
	bhi _0829A250
	lsrs r0, r6, #0xf
	adds r4, r0, #0
	adds r4, #0x77
	b _0829A266
_0829A250:
	ldr r0, _0829A260
	cmp r1, r0
	bhi _0829A264
	lsrs r0, r6, #0x12
	adds r4, r0, #0
	adds r4, #0x7c
	b _0829A266
	.align 2, 0
_0829A260: .4byte 0x00000554
_0829A264:
	movs r4, #0x7e
_0829A266:
	lsls r0, r4, #3
	ldr r7, _0829A284
	adds r3, r0, r7
	ldr r2, [r3, #8]
	cmp r2, r3
	bne _0829A288
	adds r0, r4, #0
	asrs r0, r0, #2
	movs r1, #1
	lsls r1, r0
	ldr r0, [r7, #4]
	orrs r0, r1
	str r0, [r7, #4]
	b _0829A2A0
	.align 2, 0
_0829A284: .4byte 0x0203CF34
_0829A288:
	ldr r0, [r2, #4]
	movs r1, #4
	rsbs r1, r1, #0
	b _0829A298
_0829A290:
	ldr r2, [r2, #8]
	cmp r2, r3
	beq _0829A29E
	ldr r0, [r2, #4]
_0829A298:
	ands r0, r1
	cmp r6, r0
	blo _0829A290
_0829A29E:
	ldr r3, [r2, #0xc]
_0829A2A0:
	str r3, [r5, #0xc]
	str r2, [r5, #8]
	str r5, [r3, #8]
	str r5, [r2, #0xc]
_0829A2A8:
	mov r0, sb
	bl __malloc_unlock
_0829A2AE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	thumb_func_end _free_r

thumb_func_start _malloc_trim_r
_malloc_trim_r: @ 0x0829A2B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	bl __malloc_lock
	ldr r0, _0829A340
	mov r8, r0
	ldr r0, [r0, #8]
	ldr r6, [r0, #4]
	movs r0, #4
	rsbs r0, r0, #0
	ands r6, r0
	subs r4, r6, r4
	movs r5, #0x80
	lsls r5, r5, #5
	ldr r1, _0829A344
	adds r4, r4, r1
	adds r0, r4, #0
	adds r1, r5, #0
	bl __udivsi3
	subs r0, #1
	lsls r4, r0, #0xc
	cmp r4, r5
	blt _0829A336
	adds r0, r7, #0
	movs r1, #0
	bl _sbrk_r
	adds r2, r0, #0
	mov r1, r8
	ldr r0, [r1, #8]
	adds r0, r0, r6
	cmp r2, r0
	bne _0829A336
	rsbs r1, r4, #0
	adds r0, r7, #0
	bl _sbrk_r
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bne _0829A350
	adds r0, r7, #0
	movs r1, #0
	bl _sbrk_r
	adds r2, r0, #0
	mov r0, r8
	ldr r3, [r0, #8]
	subs r6, r2, r3
	cmp r6, #0xf
	ble _0829A336
	ldr r1, _0829A348
	ldr r0, _0829A34C
	ldr r0, [r0]
	subs r0, r2, r0
	str r0, [r1]
	movs r0, #1
	orrs r6, r0
	str r6, [r3, #4]
_0829A336:
	adds r0, r7, #0
	bl __malloc_unlock
	movs r0, #0
	b _0829A36C
	.align 2, 0
_0829A340: .4byte 0x0203CF34
_0829A344: .4byte 0x00000FEF
_0829A348: .4byte 0x0203D350
_0829A34C: .4byte 0x0203D344
_0829A350:
	mov r1, r8
	ldr r2, [r1, #8]
	subs r0, r6, r4
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #4]
	ldr r1, _0829A374
	ldr r0, [r1]
	subs r0, r0, r4
	str r0, [r1]
	adds r0, r7, #0
	bl __malloc_unlock
	movs r0, #1
_0829A36C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0829A374: .4byte 0x0203D350
	thumb_func_end _malloc_trim_r

thumb_func_start __sfvwrite
__sfvwrite: @ 0x0829A378
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov sl, r1
	ldr r6, [r1, #8]
	cmp r6, #0
	bne _0829A390
	b _0829A586
_0829A390:
	movs r0, #8
	ldrh r1, [r5, #0xc]
	ands r0, r1
	cmp r0, #0
	beq _0829A3A0
	ldr r0, [r5, #0x10]
	cmp r0, #0
	bne _0829A3AC
_0829A3A0:
	adds r0, r5, #0
	bl __swsetup
	cmp r0, #0
	beq _0829A3AC
	b _0829A592
_0829A3AC:
	mov r2, sl
	ldr r2, [r2]
	mov r8, r2
	movs r6, #0
	ldrh r1, [r5, #0xc]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0829A400
_0829A3BE:
	ldr r0, [r5, #0x1c]
	ldr r3, [r5, #0x24]
	cmp r6, #0
	bne _0829A3D4
_0829A3C6:
	mov r1, r8
	ldr r7, [r1]
	ldr r6, [r1, #4]
	movs r2, #8
	add r8, r2
	cmp r6, #0
	beq _0829A3C6
_0829A3D4:
	adds r2, r6, #0
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r6, r1
	bls _0829A3E0
	adds r2, r1, #0
_0829A3E0:
	adds r1, r7, #0
	bl _call_via_r3
	adds r4, r0, #0
	cmp r4, #0
	bgt _0829A3EE
	b _0829A58A
_0829A3EE:
	adds r7, r7, r4
	subs r6, r6, r4
	mov r1, sl
	ldr r0, [r1, #8]
	subs r0, r0, r4
	str r0, [r1, #8]
	cmp r0, #0
	bne _0829A3BE
	b _0829A586
_0829A400:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0829A4BA
_0829A408:
	ldrh r1, [r5, #0xc]
	ldr r0, [r5, #8]
	ldr r3, [r5]
	cmp r6, #0
	bne _0829A420
_0829A412:
	mov r2, r8
	ldr r7, [r2]
	ldr r6, [r2, #4]
	movs r2, #8
	add r8, r2
	cmp r6, #0
	beq _0829A412
_0829A420:
	adds r4, r0, #0
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0829A44E
	cmp r6, r4
	bhs _0829A434
	adds r4, r6, #0
_0829A434:
	adds r0, r3, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl memmove
	ldr r0, [r5, #8]
	subs r0, r0, r4
	str r0, [r5, #8]
	ldr r0, [r5]
	adds r0, r0, r4
	str r0, [r5]
	adds r4, r6, #0
	b _0829A4A8
_0829A44E:
	ldr r0, [r5, #0x10]
	cmp r3, r0
	bls _0829A476
	cmp r6, r4
	bls _0829A476
	adds r0, r3, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl memmove
	ldr r0, [r5]
	adds r0, r0, r4
	str r0, [r5]
	adds r0, r5, #0
	bl fflush
	cmp r0, #0
	beq _0829A474
	b _0829A58A
_0829A474:
	b _0829A4A8
_0829A476:
	ldr r4, [r5, #0x14]
	cmp r6, r4
	blo _0829A490
	ldr r0, [r5, #0x1c]
	ldr r3, [r5, #0x24]
	adds r1, r7, #0
	adds r2, r4, #0
	bl _call_via_r3
	adds r4, r0, #0
	cmp r4, #0
	ble _0829A58A
	b _0829A4A8
_0829A490:
	adds r4, r6, #0
	adds r0, r3, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl memmove
	ldr r0, [r5, #8]
	subs r0, r0, r4
	str r0, [r5, #8]
	ldr r0, [r5]
	adds r0, r0, r4
	str r0, [r5]
_0829A4A8:
	adds r7, r7, r4
	subs r6, r6, r4
	mov r1, sl
	ldr r0, [r1, #8]
	subs r0, r0, r4
	str r0, [r1, #8]
	cmp r0, #0
	bne _0829A408
	b _0829A586
_0829A4BA:
	movs r2, #0
	str r2, [sp]
_0829A4BE:
	cmp r6, #0
	bne _0829A4D4
	movs r0, #0
	str r0, [sp]
_0829A4C6:
	mov r1, r8
	ldr r7, [r1]
	ldr r6, [r1, #4]
	movs r2, #8
	add r8, r2
	cmp r6, #0
	beq _0829A4C6
_0829A4D4:
	ldr r0, [sp]
	cmp r0, #0
	bne _0829A4F8
	adds r0, r7, #0
	movs r1, #0xa
	adds r2, r6, #0
	bl memchr
	adds r1, r0, #0
	cmp r1, #0
	beq _0829A4F0
	subs r0, r7, #1
	subs r1, r1, r0
	b _0829A4F2
_0829A4F0:
	adds r1, r6, #1
_0829A4F2:
	mov sb, r1
	movs r2, #1
	str r2, [sp]
_0829A4F8:
	mov r2, sb
	cmp sb, r6
	bls _0829A500
	adds r2, r6, #0
_0829A500:
	ldr r0, [r5, #8]
	ldr r1, [r5, #0x14]
	adds r4, r0, r1
	ldr r0, [r5, #0x10]
	ldr r3, [r5]
	cmp r3, r0
	bls _0829A52E
	cmp r2, r4
	ble _0829A52E
	adds r0, r3, #0
	adds r1, r7, #0
	adds r2, r4, #0
	bl memmove
	ldr r0, [r5]
	adds r0, r0, r4
	str r0, [r5]
	adds r0, r5, #0
	bl fflush
	cmp r0, #0
	bne _0829A58A
	b _0829A55E
_0829A52E:
	adds r4, r1, #0
	cmp r2, r4
	blt _0829A548
	ldr r0, [r5, #0x1c]
	ldr r3, [r5, #0x24]
	adds r1, r7, #0
	adds r2, r4, #0
	bl _call_via_r3
	adds r4, r0, #0
	cmp r4, #0
	ble _0829A58A
	b _0829A55E
_0829A548:
	adds r4, r2, #0
	adds r0, r3, #0
	adds r1, r7, #0
	bl memmove
	ldr r0, [r5, #8]
	subs r0, r0, r4
	str r0, [r5, #8]
	ldr r0, [r5]
	adds r0, r0, r4
	str r0, [r5]
_0829A55E:
	mov r0, sb
	subs r0, r0, r4
	mov sb, r0
	cmp r0, #0
	bne _0829A576
	adds r0, r5, #0
	bl fflush
	cmp r0, #0
	bne _0829A58A
	movs r1, #0
	str r1, [sp]
_0829A576:
	adds r7, r7, r4
	subs r6, r6, r4
	mov r2, sl
	ldr r0, [r2, #8]
	subs r0, r0, r4
	str r0, [r2, #8]
	cmp r0, #0
	bne _0829A4BE
_0829A586:
	movs r0, #0
	b _0829A596
_0829A58A:
	movs r0, #0x40
	ldrh r1, [r5, #0xc]
	orrs r0, r1
	strh r0, [r5, #0xc]
_0829A592:
	movs r0, #1
	rsbs r0, r0, #0
_0829A596:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
	thumb_func_end __sfvwrite

thumb_func_start _fwalk
_fwalk: @ 0x0829A5A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	movs r7, #0
	movs r1, #0xec
	lsls r1, r1, #1
	adds r6, r0, r1
	cmp r6, #0
	beq _0829A5DC
_0829A5B8:
	ldr r5, [r6, #8]
	ldr r4, [r6, #4]
	b _0829A5D0
_0829A5BE:
	movs r1, #0xc
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq _0829A5CE
	adds r0, r5, #0
	bl _call_via_r8
	orrs r7, r0
_0829A5CE:
	adds r5, #0x58
_0829A5D0:
	subs r4, #1
	cmp r4, #0
	bge _0829A5BE
	ldr r6, [r6]
	cmp r6, #0
	bne _0829A5B8
_0829A5DC:
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7, pc}
	thumb_func_end _fwalk

thumb_func_start _setlocale_r
_setlocale_r: @ 0x0829A5E4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	cmp r4, #0
	beq _0829A618
	ldr r1, _0829A60C
	adds r0, r4, #0
	bl strcmp
	cmp r0, #0
	beq _0829A614
	ldr r1, _0829A610
	adds r0, r4, #0
	bl strcmp
	cmp r0, #0
	beq _0829A614
	movs r0, #0
	b _0829A61A
	.align 2, 0
_0829A60C: .4byte 0x0890F224
_0829A610: .4byte 0x0890F21C
_0829A614:
	str r6, [r5, #0x30]
	str r4, [r5, #0x34]
_0829A618:
	ldr r0, _0829A61C
_0829A61A:
	pop {r4, r5, r6, pc}
	.align 2, 0
_0829A61C: .4byte 0x0890F224
	thumb_func_end _setlocale_r

thumb_func_start _localeconv_r
_localeconv_r: @ 0x0829A620
	ldr r0, _0829A624
	bx lr
	.align 2, 0
_0829A624: .4byte 0x0890F1EC
	thumb_func_end _localeconv_r

thumb_func_start setlocale
setlocale: @ 0x0829A628
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _0829A63C
	ldr r0, [r0]
	adds r1, r3, #0
	bl _setlocale_r
	pop {pc}
	.align 2, 0
_0829A63C: .4byte 0x0203CF1C
	thumb_func_end setlocale

thumb_func_start localeconv
localeconv: @ 0x0829A640
	push {lr}
	ldr r0, _0829A64C
	ldr r0, [r0]
	bl _localeconv_r
	pop {pc}
	.align 2, 0
_0829A64C: .4byte 0x0203CF1C
	thumb_func_end localeconv

thumb_func_start __smakebuf
__smakebuf: @ 0x0829A650
	push {r4, r5, r6, r7, lr}
	sub sp, #0x3c
	adds r4, r0, #0
	movs r0, #2
	ldrh r1, [r4, #0xc]
	ands r0, r1
	cmp r0, #0
	bne _0829A6E6
	movs r2, #0xe
	ldrsh r0, [r4, r2]
	cmp r0, #0
	blt _0829A678
	ldr r0, [r4, #0x54]
	movs r2, #0xe
	ldrsh r1, [r4, r2]
	mov r2, sp
	bl _fstat_r
	cmp r0, #0
	bge _0829A68A
_0829A678:
	movs r7, #0
	movs r6, #0x80
	lsls r6, r6, #3
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r1, #0
	ldrh r2, [r4, #0xc]
	orrs r0, r2
	b _0829A6CE
_0829A68A:
	movs r7, #0
	ldr r1, [sp, #4]
	movs r0, #0xf0
	lsls r0, r0, #8
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #6
	cmp r1, r0
	bne _0829A69E
	movs r7, #1
_0829A69E:
	movs r6, #0x80
	lsls r6, r6, #3
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r1, r0
	bne _0829A6C4
	ldr r1, [r4, #0x28]
	ldr r0, _0829A6C0
	cmp r1, r0
	bne _0829A6C4
	adds r0, r6, #0
	ldrh r1, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
	str r6, [r4, #0x4c]
	b _0829A6D0
	.align 2, 0
_0829A6C0: .4byte 0x0829B739
_0829A6C4:
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r2, #0
	ldrh r1, [r4, #0xc]
	orrs r0, r1
_0829A6CE:
	strh r0, [r4, #0xc]
_0829A6D0:
	ldr r0, [r4, #0x54]
	adds r1, r6, #0
	bl _malloc_r
	adds r2, r0, #0
	cmp r2, #0
	bne _0829A6F4
	movs r0, #2
	ldrh r2, [r4, #0xc]
	orrs r0, r2
	strh r0, [r4, #0xc]
_0829A6E6:
	adds r0, r4, #0
	adds r0, #0x43
	str r0, [r4]
	str r0, [r4, #0x10]
	movs r0, #1
	str r0, [r4, #0x14]
	b _0829A722
_0829A6F4:
	ldr r1, [r4, #0x54]
	ldr r0, _0829A728
	str r0, [r1, #0x3c]
	movs r0, #0x80
	movs r5, #0
	ldrh r1, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
	str r2, [r4]
	str r2, [r4, #0x10]
	str r6, [r4, #0x14]
	cmp r7, #0
	beq _0829A722
	movs r2, #0xe
	ldrsh r0, [r4, r2]
	bl isatty
	cmp r0, #0
	beq _0829A722
	movs r0, #1
	ldrh r1, [r4, #0xc]
	orrs r0, r1
	strh r0, [r4, #0xc]
_0829A722:
	add sp, #0x3c
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0829A728: .4byte 0x0829A079
	thumb_func_end __smakebuf

thumb_func_start sub_0829A72C
sub_0829A72C: @ 0x0829A72C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	ldr r0, _0829A7A0
	ldr r0, [r0, #8]
	mov r8, r0
	ldr r7, [r0, #4]
	movs r0, #4
	rsbs r0, r0, #0
	ands r7, r0
	mov r2, r8
	adds r4, r2, r7
	ldr r0, _0829A7A4
	ldr r0, [r0]
	adds r1, r1, r0
	adds r6, r1, #0
	adds r6, #0x10
	ldr r3, _0829A7A8
	mov sl, r3
	ldr r0, [r3]
	movs r2, #1
	rsbs r2, r2, #0
	mov sb, r2
	cmp r0, sb
	beq _0829A76E
	ldr r3, _0829A7AC
	adds r6, r1, r3
	ldr r0, _0829A7B0
	ands r6, r0
_0829A76E:
	ldr r0, [sp]
	adds r1, r6, #0
	bl _sbrk_r
	adds r5, r0, #0
	cmp r5, sb
	beq _0829A870
	cmp r5, r4
	bhs _0829A786
	ldr r0, _0829A7A0
	cmp r8, r0
	bne _0829A870
_0829A786:
	ldr r1, _0829A7B4
	ldr r0, [r1]
	adds r2, r0, r6
	str r2, [r1]
	cmp r5, r4
	bne _0829A7B8
	adds r2, r6, r7
	ldr r3, _0829A7A0
	ldr r1, [r3, #8]
	movs r0, #1
	orrs r2, r0
	str r2, [r1, #4]
	b _0829A858
	.align 2, 0
_0829A7A0: .4byte 0x0203CF34
_0829A7A4: .4byte 0x0203D340
_0829A7A8: .4byte 0x0203D344
_0829A7AC: .4byte 0x0000100F
_0829A7B0: .4byte 0xFFFFF000
_0829A7B4: .4byte 0x0203D350
_0829A7B8:
	mov r3, sl
	ldr r0, [r3]
	cmp r0, sb
	bne _0829A7C4
	str r5, [r3]
	b _0829A7CA
_0829A7C4:
	subs r0, r5, r4
	adds r0, r2, r0
	str r0, [r1]
_0829A7CA:
	adds r1, r5, #0
	adds r1, #8
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	beq _0829A7DE
	movs r0, #8
	subs r4, r0, r1
	adds r5, r5, r4
	b _0829A7E0
_0829A7DE:
	movs r4, #0
_0829A7E0:
	adds r0, r5, r6
	movs r1, #0x80
	lsls r1, r1, #5
	subs r1, #1
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #5
	subs r0, r1, r0
	adds r4, r4, r0
	ldr r0, [sp]
	adds r1, r4, #0
	bl _sbrk_r
	adds r2, r0, #0
	movs r0, #1
	rsbs r0, r0, #0
	cmp r2, r0
	beq _0829A870
	ldr r1, _0829A828
	ldr r0, [r1]
	adds r0, r0, r4
	str r0, [r1]
	ldr r1, _0829A82C
	str r5, [r1, #8]
	subs r0, r2, r5
	adds r2, r0, r4
	movs r3, #1
	orrs r2, r3
	str r2, [r5, #4]
	cmp r8, r1
	beq _0829A858
	cmp r7, #0xf
	bhi _0829A830
	str r3, [r5, #4]
	b _0829A870
	.align 2, 0
_0829A828: .4byte 0x0203D350
_0829A82C: .4byte 0x0203CF34
_0829A830:
	subs r7, #0xc
	movs r0, #8
	rsbs r0, r0, #0
	ands r7, r0
	mov r2, r8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r7
	str r0, [r2, #4]
	adds r1, r2, r7
	movs r0, #5
	str r0, [r1, #4]
	str r0, [r1, #8]
	cmp r7, #0xf
	bls _0829A858
	mov r1, r8
	adds r1, #8
	ldr r0, [sp]
	bl _free_r
_0829A858:
	ldr r0, _0829A87C
	ldr r2, _0829A880
	ldr r1, [r0]
	ldr r0, [r2]
	cmp r1, r0
	bls _0829A866
	str r1, [r2]
_0829A866:
	ldr r2, _0829A884
	ldr r0, [r2]
	cmp r1, r0
	bls _0829A870
	str r1, [r2]
_0829A870:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0829A87C: .4byte 0x0203D350
_0829A880: .4byte 0x0203D348
_0829A884: .4byte 0x0203D34C
	thumb_func_end sub_0829A72C

thumb_func_start _malloc_r
_malloc_r: @ 0x0829A888
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp]
	adds r1, #0xb
	cmp r1, #0x16
	ble _0829A8AA
	movs r0, #8
	rsbs r0, r0, #0
	mov r8, r0
	mov r2, r8
	ands r2, r1
	mov r8, r2
	b _0829A8AE
_0829A8AA:
	movs r3, #0x10
	mov r8, r3
_0829A8AE:
	ldr r0, [sp]
	bl __malloc_lock
	ldr r0, _0829A8F4
	cmp r8, r0
	bhi _0829A902
	mov r4, r8
	lsrs r4, r4, #3
	mov ip, r4
	ldr r0, _0829A8F8
	mov r7, r8
	adds r2, r7, r0
	ldr r5, [r2, #0xc]
	cmp r5, r2
	bne _0829A8D6
	adds r2, r5, #0
	adds r2, #8
	ldr r5, [r2, #0xc]
	cmp r5, r2
	beq _0829A8FC
_0829A8D6:
	ldr r2, [r5, #4]
	movs r0, #4
	rsbs r0, r0, #0
	ands r2, r0
	ldr r6, [r5, #0xc]
	ldr r4, [r5, #8]
	str r6, [r4, #0xc]
	str r4, [r6, #8]
	adds r2, r5, r2
	ldr r0, [r2, #4]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #4]
	b _0829AC2E
	.align 2, 0
_0829A8F4: .4byte 0x000001F7
_0829A8F8: .4byte 0x0203CF34
_0829A8FC:
	movs r0, #2
	add ip, r0
	b _0829A9AE
_0829A902:
	mov r2, r8
	lsrs r1, r2, #9
	cmp r1, #0
	bne _0829A90E
	lsrs r2, r2, #3
	b _0829A95E
_0829A90E:
	cmp r1, #4
	bhi _0829A91C
	mov r3, r8
	lsrs r0, r3, #6
	adds r0, #0x38
	mov ip, r0
	b _0829A960
_0829A91C:
	cmp r1, #0x14
	bhi _0829A926
	adds r1, #0x5b
	mov ip, r1
	b _0829A960
_0829A926:
	cmp r1, #0x54
	bhi _0829A934
	mov r4, r8
	lsrs r0, r4, #0xc
	adds r0, #0x6e
	mov ip, r0
	b _0829A960
_0829A934:
	movs r0, #0xaa
	lsls r0, r0, #1
	cmp r1, r0
	bhi _0829A946
	mov r7, r8
	lsrs r0, r7, #0xf
	adds r0, #0x77
	mov ip, r0
	b _0829A960
_0829A946:
	ldr r0, _0829A958
	cmp r1, r0
	bhi _0829A95C
	mov r1, r8
	lsrs r0, r1, #0x12
	adds r0, #0x7c
	mov ip, r0
	b _0829A960
	.align 2, 0
_0829A958: .4byte 0x00000554
_0829A95C:
	movs r2, #0x7e
_0829A95E:
	mov ip, r2
_0829A960:
	mov r3, ip
	lsls r0, r3, #3
	ldr r1, _0829A984
	adds r4, r0, r1
	ldr r5, [r4, #0xc]
	cmp r5, r4
	beq _0829A9AA
	ldr r1, [r5, #4]
	movs r0, #4
	rsbs r0, r0, #0
	ands r1, r0
	mov r7, r8
	subs r3, r1, r7
	cmp r3, #0xf
	ble _0829A988
	adds r0, #3
	add ip, r0
	b _0829A9AA
	.align 2, 0
_0829A984: .4byte 0x0203CF34
_0829A988:
	cmp r3, #0
	blt _0829A98E
	b _0829ABC8
_0829A98E:
	ldr r5, [r5, #0xc]
	cmp r5, r4
	beq _0829A9AA
	ldr r1, [r5, #4]
	movs r0, #4
	rsbs r0, r0, #0
	ands r1, r0
	mov r2, r8
	subs r3, r1, r2
	cmp r3, #0xf
	ble _0829A988
	movs r3, #1
	rsbs r3, r3, #0
	add ip, r3
_0829A9AA:
	movs r4, #1
	add ip, r4
_0829A9AE:
	ldr r0, _0829A9EC
	ldr r5, [r0, #8]
	mov sl, r0
	cmp r5, sl
	bne _0829A9BA
	b _0829AABC
_0829A9BA:
	ldr r1, [r5, #4]
	movs r0, #4
	rsbs r0, r0, #0
	ands r1, r0
	mov r7, r8
	subs r3, r1, r7
	cmp r3, #0xf
	ble _0829A9F0
	adds r2, r5, r7
	movs r1, #1
	adds r0, r7, #0
	orrs r0, r1
	str r0, [r5, #4]
	mov r4, sl
	str r2, [r4, #0xc]
	str r2, [r4, #8]
	str r4, [r2, #0xc]
	str r4, [r2, #8]
	adds r0, r3, #0
	orrs r0, r1
	str r0, [r2, #4]
	adds r0, r2, r3
	str r3, [r0]
	b _0829AC2E
	.align 2, 0
_0829A9EC: .4byte 0x0203CF3C
_0829A9F0:
	mov r7, sl
	str r7, [r7, #0xc]
	str r7, [r7, #8]
	cmp r3, #0
	blt _0829AA06
	adds r2, r5, r1
	ldr r0, [r2, #4]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #4]
	b _0829AC2E
_0829AA06:
	ldr r0, _0829AA28
	cmp r1, r0
	bhi _0829AA2C
	lsrs r2, r1, #3
	mov r3, sl
	subs r3, #8
	adds r0, r2, #0
	asrs r0, r0, #2
	movs r1, #1
	lsls r1, r0
	ldr r0, [r3, #4]
	orrs r0, r1
	str r0, [r3, #4]
	lsls r0, r2, #3
	adds r6, r0, r3
	ldr r4, [r6, #8]
	b _0829AAB4
	.align 2, 0
_0829AA28: .4byte 0x000001FF
_0829AA2C:
	lsrs r2, r1, #9
	cmp r2, #0
	bne _0829AA36
	lsrs r2, r1, #3
	b _0829AA7A
_0829AA36:
	cmp r2, #4
	bhi _0829AA42
	lsrs r0, r1, #6
	adds r2, r0, #0
	adds r2, #0x38
	b _0829AA7A
_0829AA42:
	cmp r2, #0x14
	bhi _0829AA4A
	adds r2, #0x5b
	b _0829AA7A
_0829AA4A:
	cmp r2, #0x54
	bhi _0829AA56
	lsrs r0, r1, #0xc
	adds r2, r0, #0
	adds r2, #0x6e
	b _0829AA7A
_0829AA56:
	movs r0, #0xaa
	lsls r0, r0, #1
	cmp r2, r0
	bhi _0829AA66
	lsrs r0, r1, #0xf
	adds r2, r0, #0
	adds r2, #0x77
	b _0829AA7A
_0829AA66:
	ldr r0, _0829AA74
	cmp r2, r0
	bhi _0829AA78
	lsrs r0, r1, #0x12
	adds r2, r0, #0
	adds r2, #0x7c
	b _0829AA7A
	.align 2, 0
_0829AA74: .4byte 0x00000554
_0829AA78:
	movs r2, #0x7e
_0829AA7A:
	lsls r0, r2, #3
	ldr r3, _0829AA98
	adds r6, r0, r3
	ldr r4, [r6, #8]
	cmp r4, r6
	bne _0829AA9C
	adds r0, r2, #0
	asrs r0, r0, #2
	movs r1, #1
	lsls r1, r0
	ldr r7, _0829AA98
	ldr r0, [r7, #4]
	orrs r0, r1
	str r0, [r7, #4]
	b _0829AAB4
	.align 2, 0
_0829AA98: .4byte 0x0203CF34
_0829AA9C:
	ldr r0, [r4, #4]
	movs r2, #4
	rsbs r2, r2, #0
	b _0829AAAC
_0829AAA4:
	ldr r4, [r4, #8]
	cmp r4, r6
	beq _0829AAB2
	ldr r0, [r4, #4]
_0829AAAC:
	ands r0, r2
	cmp r1, r0
	blo _0829AAA4
_0829AAB2:
	ldr r6, [r4, #0xc]
_0829AAB4:
	str r6, [r5, #0xc]
	str r4, [r5, #8]
	str r5, [r6, #8]
	str r5, [r4, #0xc]
_0829AABC:
	mov r0, ip
	cmp r0, #0
	bge _0829AAC4
	adds r0, #3
_0829AAC4:
	asrs r0, r0, #2
	movs r6, #1
	lsls r6, r0
	ldr r0, _0829AAE8
	ldr r1, [r0, #4]
	cmp r6, r1
	bhi _0829AB86
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _0829AAFA
	movs r0, #4
	rsbs r0, r0, #0
	mov r2, ip
	ands r0, r2
	adds r0, #4
	mov ip, r0
	b _0829AAF0
	.align 2, 0
_0829AAE8: .4byte 0x0203CF34
_0829AAEC:
	movs r3, #4
	add ip, r3
_0829AAF0:
	lsls r6, r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0829AAEC
_0829AAFA:
	ldr r4, _0829AB78
	mov sb, r4
_0829AAFE:
	mov r7, ip
	str r7, [sp, #4]
	mov r1, ip
	lsls r0, r1, #3
	mov r3, sb
	adds r2, r0, r3
	adds r4, r2, #0
_0829AB0C:
	ldr r5, [r4, #0xc]
	cmp r5, r4
	beq _0829AB2C
	movs r0, #4
	rsbs r0, r0, #0
_0829AB16:
	ldr r1, [r5, #4]
	ands r1, r0
	mov r7, r8
	subs r3, r1, r7
	cmp r3, #0xf
	bgt _0829ABDC
	cmp r3, #0
	bge _0829AC04
	ldr r5, [r5, #0xc]
	cmp r5, r4
	bne _0829AB16
_0829AB2C:
	adds r4, #8
	movs r0, #1
	add ip, r0
	mov r0, ip
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0829AB0C
_0829AB3C:
	ldr r0, [sp, #4]
	ands r0, r1
	cmp r0, #0
	beq _0829AB7C
	ldr r3, [sp, #4]
	subs r3, #1
	str r3, [sp, #4]
	subs r2, #8
	ldr r0, [r2, #8]
	cmp r0, r2
	beq _0829AB3C
_0829AB52:
	lsls r6, r6, #1
	mov r4, sb
	ldr r1, [r4, #4]
	cmp r6, r1
	bhi _0829AB86
	cmp r6, #0
	beq _0829AB86
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _0829AAFE
_0829AB68:
	movs r7, #4
	add ip, r7
	lsls r6, r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0829AB68
	b _0829AAFE
	.align 2, 0
_0829AB78: .4byte 0x0203CF34
_0829AB7C:
	mov r1, sb
	ldr r0, [r1, #4]
	bics r0, r6
	str r0, [r1, #4]
	b _0829AB52
_0829AB86:
	ldr r2, _0829ABC4
	ldr r0, [r2, #8]
	ldr r0, [r0, #4]
	movs r4, #4
	rsbs r4, r4, #0
	ands r0, r4
	mov r7, r8
	subs r3, r0, r7
	cmp r0, r8
	blo _0829AB9E
	cmp r3, #0xf
	bgt _0829AC18
_0829AB9E:
	ldr r0, [sp]
	mov r1, r8
	bl sub_0829A72C
	ldr r1, _0829ABC4
	ldr r0, [r1, #8]
	ldr r0, [r0, #4]
	ands r0, r4
	mov r2, r8
	subs r3, r0, r2
	cmp r0, r8
	blo _0829ABBA
	cmp r3, #0xf
	bgt _0829AC18
_0829ABBA:
	ldr r0, [sp]
	bl __malloc_unlock
	movs r0, #0
	b _0829AC38
	.align 2, 0
_0829ABC4: .4byte 0x0203CF34
_0829ABC8:
	ldr r6, [r5, #0xc]
	ldr r4, [r5, #8]
	str r6, [r4, #0xc]
	str r4, [r6, #8]
	adds r2, r5, r1
	ldr r0, [r2, #4]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #4]
	b _0829AC2E
_0829ABDC:
	mov r4, r8
	adds r2, r5, r4
	movs r1, #1
	orrs r4, r1
	str r4, [r5, #4]
	ldr r6, [r5, #0xc]
	ldr r4, [r5, #8]
	str r6, [r4, #0xc]
	str r4, [r6, #8]
	mov r7, sl
	str r2, [r7, #0xc]
	str r2, [r7, #8]
	str r7, [r2, #0xc]
	str r7, [r2, #8]
	adds r0, r3, #0
	orrs r0, r1
	str r0, [r2, #4]
	adds r0, r2, r3
	str r3, [r0]
	b _0829AC2E
_0829AC04:
	adds r2, r5, r1
	ldr r0, [r2, #4]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #4]
	ldr r6, [r5, #0xc]
	ldr r4, [r5, #8]
	str r6, [r4, #0xc]
	str r4, [r6, #8]
	b _0829AC2E
_0829AC18:
	ldr r2, _0829AC44
	ldr r5, [r2, #8]
	movs r1, #1
	mov r0, r8
	orrs r0, r1
	str r0, [r5, #4]
	mov r4, r8
	adds r0, r5, r4
	str r0, [r2, #8]
	orrs r3, r1
	str r3, [r0, #4]
_0829AC2E:
	ldr r0, [sp]
	bl __malloc_unlock
	adds r0, r5, #0
	adds r0, #8
_0829AC38:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7, pc}
	.align 2, 0
_0829AC44: .4byte 0x0203CF34
	thumb_func_end _malloc_r

thumb_func_start _mbtowc_r
_mbtowc_r: @ 0x0829AC48
	sub sp, #4
	cmp r1, #0
	bne _0829AC50
	mov r1, sp
_0829AC50:
	cmp r2, #0
	beq _0829AC6C
	cmp r3, #0
	bne _0829AC5E
	movs r0, #1
	rsbs r0, r0, #0
	b _0829AC6E
_0829AC5E:
	ldrb r0, [r2]
	str r0, [r1]
	ldrb r0, [r2]
	cmp r0, #0
	beq _0829AC6C
	movs r0, #1
	b _0829AC6E
_0829AC6C:
	movs r0, #0
_0829AC6E:
	add sp, #4
	bx lr
	.align 2, 0
	thumb_func_end _mbtowc_r

