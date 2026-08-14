.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
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
