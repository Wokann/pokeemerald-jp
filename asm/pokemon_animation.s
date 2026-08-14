.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start pokemonanimfunc_5A
pokemonanimfunc_5A: @ 0x08183294
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x32
	ldrsh r6, [r5, r0]
	cmp r6, #0
	bne _081832B6
	movs r4, #1
	strh r4, [r5, #0x32]
	adds r0, r5, #0
	bl HandleStartAffineAnim
	strh r4, [r5, #0x36]
	movs r0, #0x28
	strh r0, [r5, #0x3a]
	strh r0, [r5, #0x34]
	strh r6, [r5, #0x38]
	strh r6, [r5, #0x3c]
_081832B6:
	adds r0, r5, #0
	bl sub_08183174
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_5A

	thumb_func_start sub_081832C4
sub_081832C4: @ 0x081832C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0
	mov r8, r0
	movs r2, #0x38
	ldrsh r1, [r6, r2]
	movs r2, #0x3a
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _08183316
	mov r0, r8
	strh r0, [r6, #0x38]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, #0
	adds r1, r2, #0
	movs r3, #0
	bl HandleSetAffineData
	ldrh r1, [r6, #0x36]
	movs r2, #0x36
	ldrsh r0, [r6, r2]
	cmp r0, #1
	bgt _0818330C
	adds r0, r6, #0
	bl sub_0817F628
	ldr r0, _08183308
	str r0, [r6, #0x1c]
	b _081833E4
	.align 2, 0
_08183308: .4byte 0x08184C35
_0818330C:
	subs r0, r1, #1
	strh r0, [r6, #0x36]
	mov r0, r8
	strh r0, [r6, #0x3c]
	b _081833E4
_08183316:
	movs r1, #0x38
	ldrsh r5, [r6, r1]
	lsls r0, r5, #7
	movs r2, #0x3a
	ldrsh r4, [r6, r2]
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sb, r0
	cmp r4, #0
	bge _08183332
	adds r4, #3
_08183332:
	asrs r1, r4, #2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r5, r1
	blt _08183358
	cmp r5, r0
	bge _08183358
	ldrh r0, [r6, #0x3c]
	adds r0, #0x33
	strh r0, [r6, #0x3c]
	movs r1, #0xff
	mov r8, r1
	mov r2, r8
	ands r2, r0
	mov r8, r2
_08183358:
	ldrh r0, [r6, #0x34]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r1, #0x30
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _0818339C
	mov r2, sb
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r7, #0
	bl Sin
	adds r4, r0, #0
	mov r5, r8
	adds r0, r7, #0
	movs r1, #5
	bl __udivsi3
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r0, r5, #0
	bl Sin
	ldr r1, _08183398
	adds r0, r0, r1
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r1, r4, #0x10
	b _081833CE
	.align 2, 0
_08183398: .4byte 0xFFFFFF00
_0818339C:
	mov r4, r8
	adds r0, r7, #0
	movs r1, #5
	bl __udivsi3
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r0, r4, #0
	bl Sin
	adds r4, r0, #0
	mov r2, sb
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	adds r1, r7, #0
	bl Sin
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	subs r1, r1, r4
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
_081833CE:
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, #0
	movs r3, #0
	bl SetAffineData
	ldrh r0, [r6, #0x38]
	adds r0, #1
	strh r0, [r6, #0x38]
_081833E4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_081832C4

	thumb_func_start pokemonanimfunc_5B
pokemonanimfunc_5B: @ 0x081833F0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x32
	ldrsh r6, [r5, r0]
	cmp r6, #0
	bne _08183412
	movs r4, #1
	strh r4, [r5, #0x32]
	adds r0, r5, #0
	bl HandleStartAffineAnim
	strh r4, [r5, #0x36]
	movs r0, #0x28
	strh r0, [r5, #0x3a]
	strh r0, [r5, #0x34]
	strh r6, [r5, #0x38]
	strh r6, [r5, #0x3c]
_08183412:
	adds r0, r5, #0
	bl sub_081832C4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_5B

	thumb_func_start sub_08183420
sub_08183420: @ 0x08183420
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	ldrh r0, [r4, #0x32]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldrh r0, [r4, #0x3a]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r3, _0818347C
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	lsls r1, r0, #1
	adds r0, r1, r3
	ldrb r5, [r0]
	adds r2, r5, #0
	cmp r5, #0xff
	beq _08183452
	ldrh r0, [r4, #0x3c]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_08183452:
	adds r0, r3, #1
	adds r0, r1, r0
	ldrb r6, [r0]
	movs r7, #0
	cmp r2, #0xfe
	beq _0818346E
	mov r1, sb
	subs r0, r6, r1
	muls r0, r5, r0
	adds r1, r6, #0
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
_0818346E:
	cmp r5, #0xff
	bne _08183484
	ldr r0, _08183480
	str r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x26]
	b _081834B6
	.align 2, 0
_0818347C: .4byte 0x085D34E0
_08183480: .4byte 0x08184C35
_08183484:
	mov r1, r8
	adds r1, #0xc0
	adds r0, r1, #0
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	adds r1, r7, #0
	bl Sin
	adds r0, r0, r7
	strh r0, [r4, #0x26]
	cmp sb, r6
	bne _081834A8
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
	movs r0, #0
	b _081834B4
_081834A8:
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x32]
	adds r0, r0, r1
	strh r0, [r4, #0x32]
	ldrh r0, [r4, #0x3a]
	adds r0, #1
_081834B4:
	strh r0, [r4, #0x3a]
_081834B6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08183420

	thumb_func_start pokemonanimfunc_5C
pokemonanimfunc_5C: @ 0x081834C4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x28
	strh r0, [r4, #0x2e]
	movs r0, #6
	strh r0, [r4, #0x3c]
	adds r0, r4, #0
	bl sub_08183420
	ldr r0, _081834E0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081834E0: .4byte 0x08183421
	thumb_func_end pokemonanimfunc_5C

	thumb_func_start pokemonanimfunc_5D
pokemonanimfunc_5D: @ 0x081834E4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x46
	strh r0, [r4, #0x2e]
	movs r0, #6
	strh r0, [r4, #0x3c]
	adds r0, r4, #0
	bl sub_0817FB88
	ldr r0, _08183500
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08183500: .4byte 0x0817FB89
	thumb_func_end pokemonanimfunc_5D

	thumb_func_start pokemonanimfunc_5E
pokemonanimfunc_5E: @ 0x08183504
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x14
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	bl sub_0817F7A8
	ldr r0, _0818351C
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0818351C: .4byte 0x0817F7A9
	thumb_func_end pokemonanimfunc_5E

	thumb_func_start pokemonanimfunc_5F
pokemonanimfunc_5F: @ 0x08183520
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x32]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	cmp r0, #0x28
	ble _0818353C
	ldr r0, _08183538
	str r0, [r4, #0x1c]
	movs r0, #0
	b _08183576
	.align 2, 0
_08183538: .4byte 0x08184C35
_0818353C:
	movs r0, #1
	ands r0, r1
	movs r5, #0xff
	cmp r0, #0
	bne _08183548
	movs r5, #1
_08183548:
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	lsls r0, r0, #7
	movs r1, #0x28
	bl __divsi3
	adds r1, r0, #0
	cmp r1, #0
	bge _0818355C
	adds r0, #0xff
_0818355C:
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #9
	bl Sin
	lsls r1, r5, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, #0
	muls r2, r1, r2
	adds r0, r2, #0
_08183576:
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_5F

	thumb_func_start pokemonanimfunc_60
pokemonanimfunc_60: @ 0x08183584
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x32]
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	cmp r0, #0x28
	ble _081835A0
	ldr r0, _0818359C
	str r0, [r4, #0x1c]
	movs r0, #0
	b _081835DA
	.align 2, 0
_0818359C: .4byte 0x08184C35
_081835A0:
	movs r0, #1
	ands r0, r1
	movs r5, #0xff
	cmp r0, #0
	bne _081835AC
	movs r5, #1
_081835AC:
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	lsls r0, r0, #7
	movs r1, #0x28
	bl __divsi3
	adds r1, r0, #0
	cmp r1, #0
	bge _081835C0
	adds r0, #0xff
_081835C0:
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0xc
	bl Sin
	lsls r1, r5, #0x18
	asrs r1, r1, #0x18
	adds r2, r0, #0
	muls r2, r1, r2
	adds r0, r2, #0
_081835DA:
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_60

	thumb_func_start pokemonanimfunc_61
pokemonanimfunc_61: @ 0x081835E8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x46
	strh r0, [r4, #0x2e]
	movs r0, #6
	strh r0, [r4, #0x3c]
	adds r0, r4, #0
	bl sub_08182FEC
	ldr r0, _08183604
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08183604: .4byte 0x08182FED
	thumb_func_end pokemonanimfunc_61

	thumb_func_start pokemonanimfunc_62
pokemonanimfunc_62: @ 0x08183608
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x18
	strh r0, [r4, #0x2e]
	movs r0, #6
	strh r0, [r4, #0x3c]
	adds r0, r4, #0
	bl sub_08183420
	ldr r0, _08183624
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08183624: .4byte 0x08183421
	thumb_func_end pokemonanimfunc_62

	thumb_func_start pokemonanimfunc_63
pokemonanimfunc_63: @ 0x08183628
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x38
	strh r0, [r4, #0x2e]
	movs r0, #9
	strh r0, [r4, #0x3c]
	adds r0, r4, #0
	bl sub_08183420
	ldr r0, _08183644
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08183644: .4byte 0x08183421
	thumb_func_end pokemonanimfunc_63

	thumb_func_start pokemonanimfunc_64
pokemonanimfunc_64: @ 0x08183648
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0817F604
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #0x2e]
	ldr r2, _08183680
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r0, #0x80
	lsls r0, r0, #3
	strh r0, [r1, #6]
	movs r0, #6
	strh r0, [r1, #8]
	movs r0, #0x18
	strh r0, [r1, #2]
	adds r0, r4, #0
	bl sub_0817FE9C
	ldr r0, _08183684
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08183680: .4byte 0x03001240
_08183684: .4byte 0x0817FE9D
	thumb_func_end pokemonanimfunc_64

	thumb_func_start sub_08183688
sub_08183688: @ 0x08183688
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r5, #0
	movs r0, #0x38
	ldrsh r1, [r7, r0]
	movs r2, #0x3a
	ldrsh r0, [r7, r2]
	cmp r1, r0
	ble _081836D8
	strh r5, [r7, #0x26]
	strh r5, [r7, #0x38]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r7, #0
	adds r1, r2, #0
	movs r3, #0
	bl HandleSetAffineData
	ldrh r1, [r7, #0x36]
	movs r2, #0x36
	ldrsh r0, [r7, r2]
	cmp r0, #1
	bgt _081836D0
	adds r0, r7, #0
	bl sub_0817F628
	ldr r0, _081836CC
	str r0, [r7, #0x1c]
	b _081837D8
	.align 2, 0
_081836CC: .4byte 0x08184C35
_081836D0:
	subs r0, r1, #1
	strh r0, [r7, #0x36]
	strh r5, [r7, #0x3c]
	b _081837D8
_081836D8:
	movs r0, #0x38
	ldrsh r6, [r7, r0]
	lsls r0, r6, #7
	movs r1, #0x3a
	ldrsh r4, [r7, r1]
	adds r1, r4, #0
	bl __divsi3
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r4, #0
	bge _081836F2
	adds r4, #3
_081836F2:
	asrs r1, r4, #2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r1
	blt _08183712
	cmp r6, r0
	bge _08183712
	ldrh r0, [r7, #0x3c]
	adds r0, #0x33
	strh r0, [r7, #0x3c]
	movs r5, #0xff
	ands r5, r0
_08183712:
	ldrh r0, [r7, #0x34]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r1, #0x30
	ldrsh r0, [r7, r1]
	cmp r0, #0
	bne _0818375C
	lsls r2, r2, #0x10
	mov r8, r2
	asrs r0, r2, #0x10
	mov r1, sb
	bl Sin
	adds r4, r0, #0
	lsls r6, r5, #0x10
	asrs r5, r6, #0x10
	mov r0, sb
	movs r1, #5
	bl __udivsi3
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r0, r5, #0
	bl Sin
	ldr r2, _08183758
	adds r4, r4, r2
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	mov r0, r8
	b _08183796
	.align 2, 0
_08183758: .4byte 0xFFFFFF00
_0818375C:
	lsls r2, r2, #0x10
	mov r8, r2
	asrs r0, r2, #0x10
	mov r1, sb
	bl Sin
	adds r6, r0, #0
	lsls r5, r5, #0x10
	asrs r4, r5, #0x10
	mov r0, sb
	movs r1, #5
	bl __udivsi3
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x17
	adds r0, r4, #0
	bl Sin
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	subs r1, r1, r6
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	mov r0, r8
	adds r6, r5, #0
_08183796:
	asrs r0, r0, #0x10
	mov r1, sb
	bl Sin
	adds r5, r0, #0
	asrs r4, r6, #0x10
	mov r0, sb
	movs r1, #5
	bl __udivsi3
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl Sin
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r1, #0
	subs r2, r2, r5
	subs r2, r2, r0
	mov r0, sl
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r0, r7, #0
	movs r3, #0
	bl SetAffineData
	ldrh r0, [r7, #0x38]
	adds r0, #1
	strh r0, [r7, #0x38]
_081837D8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08183688

	thumb_func_start pokemonanimfunc_65
pokemonanimfunc_65: @ 0x081837E8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x32
	ldrsh r6, [r5, r0]
	cmp r6, #0
	bne _0818380A
	movs r4, #1
	strh r4, [r5, #0x32]
	adds r0, r5, #0
	bl HandleStartAffineAnim
	strh r4, [r5, #0x36]
	movs r0, #0x28
	strh r0, [r5, #0x3a]
	strh r0, [r5, #0x34]
	strh r6, [r5, #0x38]
	strh r6, [r5, #0x3c]
_0818380A:
	adds r0, r5, #0
	bl sub_08183688
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_65

	thumb_func_start pokemonanimfunc_66
pokemonanimfunc_66: @ 0x08183818
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0817F5B8
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _0818383C
	ldr r0, _08183838
	str r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x3a]
	b _08183900
	.align 2, 0
_08183838: .4byte 0x08184C35
_0818383C:
	movs r1, #0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, #0
	cmp r2, #0
	bge _0818384A
	ldr r1, _08183870
	adds r0, r2, r1
_0818384A:
	asrs r3, r0, #9
	adds r1, r3, #0
	adds r0, r1, #0
	cmp r1, #0
	bge _08183856
	adds r0, r1, #3
_08183856:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq _081838AC
	cmp r0, #1
	bgt _08183874
	cmp r0, #0
	beq _0818387E
	b _081838DC
	.align 2, 0
_08183870: .4byte 0x000001FF
_08183874:
	cmp r0, #2
	beq _08183890
	cmp r0, #3
	beq _081838C8
	b _081838DC
_0818387E:
	lsls r0, r3, #9
	subs r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _0818388C
	adds r0, #0x1f
_0818388C:
	asrs r0, r0, #5
	b _081838DA
_08183890:
	lsls r0, r3, #9
	subs r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
	cmp r0, #0
	bge _081838A2
	ldr r1, _081838A8
	adds r0, r0, r1
_081838A2:
	asrs r0, r0, #9
	b _081838DA
	.align 2, 0
_081838A8: .4byte 0x000001FF
_081838AC:
	lsls r0, r3, #9
	subs r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
	cmp r0, #0
	bge _081838BE
	ldr r1, _081838C4
	adds r0, r0, r1
_081838BE:
	asrs r0, r0, #9
	adds r0, #0x10
	b _081838DA
	.align 2, 0
_081838C4: .4byte 0x000001FF
_081838C8:
	lsls r0, r3, #9
	subs r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _081838D6
	adds r0, #0x1f
_081838D6:
	asrs r0, r0, #5
	subs r0, #0x10
_081838DA:
	strh r0, [r4, #0x24]
_081838DC:
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	adds r0, r1, #0
	cmp r1, #0
	bge _081838E8
	adds r0, #0x7f
_081838E8:
	asrs r0, r0, #7
	lsls r0, r0, #7
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #4
	bl Sin
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x32]
	adds r0, #0x30
	strh r0, [r4, #0x32]
_08183900:
	adds r0, r4, #0
	bl sub_0817F5B8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_66

	thumb_func_start pokemonanimfunc_67
pokemonanimfunc_67: @ 0x0818390C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0817F5B8
	movs r0, #0x32
	ldrsh r1, [r4, r0]
	movs r0, #0x80
	lsls r0, r0, #4
	cmp r1, r0
	ble _08183930
	ldr r0, _0818392C
	str r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x3a]
	b _081839EC
	.align 2, 0
_0818392C: .4byte 0x08184C35
_08183930:
	movs r1, #0x32
	ldrsh r2, [r4, r1]
	adds r0, r2, #0
	cmp r2, #0
	bge _0818393E
	ldr r1, _08183964
	adds r0, r2, r1
_0818393E:
	asrs r3, r0, #9
	adds r1, r3, #0
	adds r0, r1, #0
	cmp r1, #0
	bge _0818394A
	adds r0, r1, #3
_0818394A:
	asrs r0, r0, #2
	lsls r0, r0, #2
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	beq _081839A0
	cmp r0, #1
	bgt _08183968
	cmp r0, #0
	beq _08183972
	b _081839D0
	.align 2, 0
_08183964: .4byte 0x000001FF
_08183968:
	cmp r0, #2
	beq _08183984
	cmp r0, #3
	beq _081839BC
	b _081839D0
_08183972:
	lsls r0, r3, #9
	subs r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _08183980
	adds r0, #0x1f
_08183980:
	asrs r0, r0, #5
	b _081839CE
_08183984:
	lsls r0, r3, #9
	subs r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
	cmp r0, #0
	bge _08183996
	ldr r1, _0818399C
	adds r0, r0, r1
_08183996:
	asrs r0, r0, #9
	b _081839CE
	.align 2, 0
_0818399C: .4byte 0x000001FF
_081839A0:
	lsls r0, r3, #9
	subs r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
	cmp r0, #0
	bge _081839B2
	ldr r1, _081839B8
	adds r0, r0, r1
_081839B2:
	asrs r0, r0, #9
	adds r0, #0x10
	b _081839CE
	.align 2, 0
_081839B8: .4byte 0x000001FF
_081839BC:
	lsls r0, r3, #9
	subs r0, r2, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bge _081839CA
	adds r0, #0x1f
_081839CA:
	asrs r0, r0, #5
	subs r0, #0x10
_081839CE:
	strh r0, [r4, #0x24]
_081839D0:
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	movs r1, #0x60
	bl __modsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #4
	bl Sin
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x32]
	adds r0, #0x40
	strh r0, [r4, #0x32]
_081839EC:
	adds r0, r4, #0
	bl sub_0817F5B8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_67

	thumb_func_start sub_081839F8
sub_081839F8: @ 0x081839F8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl sub_0817F5B8
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08183A0A
	strh r0, [r4, #0x34]
_08183A0A:
	ldr r7, _08183A6C
	movs r2, #0x34
	ldrsh r1, [r4, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r5, r7, #2
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	bl __divsi3
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	cmp r0, r1
	bne _08183A38
	ldrh r0, [r4, #0x34]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0x34]
	strh r1, [r4, #0x32]
_08183A38:
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, #1
	adds r6, r0, r1
	adds r0, r6, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0x38
	ldrsh r5, [r4, r1]
	adds r1, r5, #0
	bl __divsi3
	adds r1, r0, #0
	cmp r1, #0
	bne _08183A78
	ldrh r0, [r4, #0x3a]
	subs r0, #1
	strh r0, [r4, #0x3a]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08183A74
	ldr r0, _08183A70
	str r0, [r4, #0x1c]
	b _08183AB2
	.align 2, 0
_08183A6C: .4byte 0x085D381E
_08183A70: .4byte 0x08184C35
_08183A74:
	strh r1, [r4, #0x32]
	b _08183AB2
_08183A78:
	adds r0, r6, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r5, r0
	ldrh r2, [r4, #0x24]
	adds r0, r0, r2
	strh r0, [r4, #0x24]
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r1, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldrh r0, [r4, #0x38]
	adds r2, r0, #0
	muls r2, r1, r2
	adds r0, r2, #0
	ldrh r1, [r4, #0x26]
	adds r0, r0, r1
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	adds r0, r4, #0
	bl sub_0817F5B8
_08183AB2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_081839F8

	thumb_func_start pokemonanimfunc_68
pokemonanimfunc_68: @ 0x08183AB8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	strh r0, [r4, #0x38]
	strh r0, [r4, #0x3a]
	adds r0, r4, #0
	bl sub_081839F8
	ldr r0, _08183AD4
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08183AD4: .4byte 0x081839F9
	thumb_func_end pokemonanimfunc_68

	thumb_func_start pokemonanimfunc_69
pokemonanimfunc_69: @ 0x08183AD8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #2
	strh r0, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x3a]
	adds r0, r4, #0
	bl sub_081839F8
	ldr r0, _08183AF4
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08183AF4: .4byte 0x081839F9
	thumb_func_end pokemonanimfunc_69

	thumb_func_start pokemonanimfunc_6A
pokemonanimfunc_6A: @ 0x08183AF8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #2
	strh r0, [r4, #0x38]
	strh r0, [r4, #0x3a]
	adds r0, r4, #0
	bl sub_081839F8
	ldr r0, _08183B14
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08183B14: .4byte 0x081839F9
	thumb_func_end pokemonanimfunc_6A

	thumb_func_start sub_08183B18
sub_08183B18: @ 0x08183B18
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #0x3c]
	movs r2, #0x3c
	ldrsh r0, [r4, r2]
	cmp r0, #0xff
	ble _08183B5A
	ldrh r1, [r4, #0x38]
	movs r2, #0x38
	ldrsh r0, [r4, r2]
	cmp r0, #1
	bgt _08183B50
	adds r0, r4, #0
	bl sub_0817F628
	ldr r0, _08183B4C
	str r0, [r4, #0x1c]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r1, r2, #0
	movs r3, #0
	bl HandleSetAffineData
	b _08183B94
	.align 2, 0
_08183B4C: .4byte 0x08184C35
_08183B50:
	subs r0, r1, #1
	movs r1, #0
	strh r0, [r4, #0x38]
	strh r1, [r4, #0x3c]
	b _08183B94
_08183B5A:
	ldrh r0, [r4, #0x3a]
	adds r0, r1, r0
	strh r0, [r4, #0x3c]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r5, #0x80
	lsls r5, r5, #1
	cmp r0, r5
	ble _08183B6E
	strh r5, [r4, #0x3c]
_08183B6E:
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	movs r1, #0x40
	bl Sin
	adds r2, r0, #0
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	subs r2, r5, r2
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r2, #0
	movs r3, #0
	bl HandleSetAffineData
_08183B94:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08183B18

	thumb_func_start pokemonanimfunc_6B
pokemonanimfunc_6B: @ 0x08183B9C
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_0817F5B8
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _08183BC2
	adds r0, r4, #0
	bl HandleStartAffineAnim
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	strh r5, [r4, #0x3c]
	movs r0, #4
	strh r0, [r4, #0x3a]
	movs r0, #1
	strh r0, [r4, #0x38]
_08183BC2:
	adds r0, r4, #0
	bl sub_08183B18
	adds r0, r4, #0
	bl sub_0817F5B8
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6B

	thumb_func_start pokemonanimfunc_6C
pokemonanimfunc_6C: @ 0x08183BD4
	push {r4, r5, lr}
	adds r4, r0, #0
	bl sub_0817F5B8
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _08183BFA
	adds r0, r4, #0
	bl HandleStartAffineAnim
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	strh r5, [r4, #0x3c]
	movs r0, #8
	strh r0, [r4, #0x3a]
	movs r0, #2
	strh r0, [r4, #0x38]
_08183BFA:
	adds r0, r4, #0
	bl sub_08183B18
	adds r0, r4, #0
	bl sub_0817F5B8
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6C

	thumb_func_start pokemonanimfunc_6D
pokemonanimfunc_6D: @ 0x08183C0C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _08183C34
	adds r0, r4, #0
	bl HandleStartAffineAnim
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	strh r5, [r4, #0x3c]
	movs r0, #8
	strh r0, [r4, #0x3a]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r4, #0x38]
	movs r0, #0x10
	strh r0, [r4, #0x36]
_08183C34:
	adds r0, r4, #0
	bl sub_08182610
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6D

	thumb_func_start pokemonanimfunc_6E
pokemonanimfunc_6E: @ 0x08183C40
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _08183C66
	adds r0, r4, #0
	bl HandleStartAffineAnim
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	strh r5, [r4, #0x3c]
	movs r0, #4
	strh r0, [r4, #0x3a]
	adds r0, #0xfc
	strh r0, [r4, #0x38]
	movs r0, #0x10
	strh r0, [r4, #0x36]
_08183C66:
	adds r0, r4, #0
	bl sub_08182610
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_6E

	thumb_func_start pokemonanimfunc_6F
pokemonanimfunc_6F: @ 0x08183C74
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _08183C9C
	adds r0, r4, #0
	bl HandleStartAffineAnim
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	strh r5, [r4, #0x3c]
	movs r0, #8
	strh r0, [r4, #0x3a]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r4, #0x38]
	movs r0, #0x10
	strh r0, [r4, #0x36]
_08183C9C:
	adds r0, r4, #0
	bl sub_081826DC
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_6F

	thumb_func_start pokemonanimfunc_70
pokemonanimfunc_70: @ 0x08183CA8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _08183CCE
	adds r0, r4, #0
	bl HandleStartAffineAnim
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	strh r5, [r4, #0x3c]
	movs r1, #8
	strh r1, [r4, #0x3a]
	movs r0, #0x80
	lsls r0, r0, #2
	strh r0, [r4, #0x38]
	strh r1, [r4, #0x36]
_08183CCE:
	adds r0, r4, #0
	bl sub_081826DC
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_70

	thumb_func_start pokemonanimfunc_71
pokemonanimfunc_71: @ 0x08183CDC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08183CF6
	adds r0, r4, #0
	bl HandleStartAffineAnim
	movs r0, #5
	strh r0, [r4, #0x3c]
	movs r0, #8
	strh r0, [r4, #0x3a]
_08183CF6:
	adds r0, r4, #0
	bl sub_081806D4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_71

	thumb_func_start pokemonanimfunc_72
pokemonanimfunc_72: @ 0x08183D04
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08183D1E
	adds r0, r4, #0
	bl HandleStartAffineAnim
	movs r0, #3
	strh r0, [r4, #0x3c]
	movs r0, #4
	strh r0, [r4, #0x3a]
_08183D1E:
	adds r0, r4, #0
	bl sub_081806D4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_72

	thumb_func_start pokemonanimfunc_73
pokemonanimfunc_73: @ 0x08183D2C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x32
	ldrsh r6, [r5, r0]
	cmp r6, #0
	bne _08183D4E
	movs r4, #1
	strh r4, [r5, #0x32]
	adds r0, r5, #0
	bl HandleStartAffineAnim
	strh r4, [r5, #0x36]
	movs r0, #0x1e
	strh r0, [r5, #0x3a]
	movs r0, #0x3c
	strh r0, [r5, #0x34]
	strh r6, [r5, #0x3c]
_08183D4E:
	adds r0, r5, #0
	bl sub_08183174
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_73

	thumb_func_start pokemonanimfunc_74
pokemonanimfunc_74: @ 0x08183D5C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _08183D80
	movs r0, #1
	strh r0, [r4, #0x32]
	adds r0, r4, #0
	bl HandleStartAffineAnim
	movs r0, #2
	strh r0, [r4, #0x36]
	movs r0, #0x14
	strh r0, [r4, #0x3a]
	movs r0, #0x46
	strh r0, [r4, #0x34]
	strh r5, [r4, #0x3c]
_08183D80:
	adds r0, r4, #0
	bl sub_08183174
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_74

	thumb_func_start pokemonanimfunc_75
pokemonanimfunc_75: @ 0x08183D8C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _08183DB2
	movs r0, #1
	strh r0, [r4, #0x32]
	adds r0, r4, #0
	bl HandleStartAffineAnim
	movs r0, #2
	strh r0, [r4, #0x36]
	movs r0, #0x14
	strh r0, [r4, #0x3a]
	movs r0, #0x46
	strh r0, [r4, #0x34]
	strh r5, [r4, #0x38]
	strh r5, [r4, #0x3c]
_08183DB2:
	adds r0, r4, #0
	bl sub_081832C4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_75

	thumb_func_start pokemonanimfunc_76
pokemonanimfunc_76: @ 0x08183DC0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x32
	ldrsh r6, [r5, r0]
	cmp r6, #0
	bne _08183DE4
	movs r4, #1
	strh r4, [r5, #0x32]
	adds r0, r5, #0
	bl HandleStartAffineAnim
	strh r4, [r5, #0x36]
	movs r0, #0x1e
	strh r0, [r5, #0x3a]
	movs r0, #0x3c
	strh r0, [r5, #0x34]
	strh r6, [r5, #0x38]
	strh r6, [r5, #0x3c]
_08183DE4:
	adds r0, r5, #0
	bl sub_081832C4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_76

	thumb_func_start pokemonanimfunc_77
pokemonanimfunc_77: @ 0x08183DF0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _08183E16
	movs r0, #1
	strh r0, [r4, #0x32]
	adds r0, r4, #0
	bl HandleStartAffineAnim
	movs r0, #2
	strh r0, [r4, #0x36]
	movs r0, #0x14
	strh r0, [r4, #0x3a]
	movs r0, #0x46
	strh r0, [r4, #0x34]
	strh r5, [r4, #0x38]
	strh r5, [r4, #0x3c]
_08183E16:
	adds r0, r4, #0
	bl sub_08183688
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_77

	thumb_func_start pokemonanimfunc_78
pokemonanimfunc_78: @ 0x08183E24
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0x32
	ldrsh r6, [r5, r0]
	cmp r6, #0
	bne _08183E48
	movs r4, #1
	strh r4, [r5, #0x32]
	adds r0, r5, #0
	bl HandleStartAffineAnim
	strh r4, [r5, #0x36]
	movs r0, #0x1e
	strh r0, [r5, #0x3a]
	movs r0, #0x3c
	strh r0, [r5, #0x34]
	strh r6, [r5, #0x38]
	strh r6, [r5, #0x3c]
_08183E48:
	adds r0, r5, #0
	bl sub_08183688
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_78

	thumb_func_start sub_08183E54
sub_08183E54: @ 0x08183E54
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	cmp r0, #0xff
	ble _08183E96
	ldrh r2, [r4, #0x3a]
	movs r3, #0x3a
	ldrsh r0, [r4, r3]
	cmp r0, #1
	bgt _08183E7C
	ldr r0, _08183E78
	str r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x24]
	strh r0, [r4, #0x26]
	b _08183EEA
	.align 2, 0
_08183E78: .4byte 0x08184C35
_08183E7C:
	movs r0, #0x3c
	ldrsh r1, [r4, r0]
	adds r0, r1, #0
	cmp r1, #0
	bge _08183E88
	adds r0, #0xff
_08183E88:
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	strh r0, [r4, #0x3c]
	subs r0, r2, #1
	strh r0, [r4, #0x3a]
	b _08183EEA
_08183E96:
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	bl Sin
	rsbs r0, r0, #0
	strh r0, [r4, #0x24]
	movs r3, #0x3c
	ldrsh r2, [r4, r3]
	adds r1, r2, #0
	adds r1, #0xc0
	adds r0, r1, #0
	cmp r1, #0
	bge _08183EB8
	ldr r3, _08183EF0
	adds r0, r2, r3
_08183EB8:
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x36
	ldrsh r1, [r4, r2]
	bl Sin
	strh r0, [r4, #0x26]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _08183EDA
	movs r3, #0x26
	ldrsh r0, [r4, r3]
	rsbs r0, r0, #0
	strh r0, [r4, #0x26]
_08183EDA:
	ldrh r0, [r4, #0x36]
	ldrh r1, [r4, #0x26]
	adds r0, r0, r1
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x34]
	ldrh r2, [r4, #0x3c]
	adds r0, r0, r2
	strh r0, [r4, #0x3c]
_08183EEA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08183EF0: .4byte 0x000001BF
	thumb_func_end sub_08183E54

	thumb_func_start pokemonanimfunc_79
pokemonanimfunc_79: @ 0x08183EF4
	push {lr}
	adds r1, r0, #0
	movs r0, #0x32
	ldrsh r2, [r1, r0]
	cmp r2, #0
	bne _08183F12
	movs r0, #1
	strh r0, [r1, #0x32]
	strh r0, [r1, #0x3a]
	strh r2, [r1, #0x3c]
	movs r0, #0xc
	strh r0, [r1, #0x38]
	strh r0, [r1, #0x36]
	movs r0, #4
	strh r0, [r1, #0x34]
_08183F12:
	adds r0, r1, #0
	bl sub_08183E54
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_79

	thumb_func_start pokemonanimfunc_7A
pokemonanimfunc_7A: @ 0x08183F1C
	push {lr}
	adds r1, r0, #0
	movs r0, #0x32
	ldrsh r2, [r1, r0]
	cmp r2, #0
	bne _08183F3A
	movs r0, #1
	strh r0, [r1, #0x32]
	strh r0, [r1, #0x3a]
	strh r2, [r1, #0x3c]
	movs r0, #0xc
	strh r0, [r1, #0x38]
	strh r0, [r1, #0x36]
	movs r0, #6
	strh r0, [r1, #0x34]
_08183F3A:
	adds r0, r1, #0
	bl sub_08183E54
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7A

	thumb_func_start pokemonanimfunc_7B
pokemonanimfunc_7B: @ 0x08183F44
	push {lr}
	adds r1, r0, #0
	movs r0, #0x32
	ldrsh r2, [r1, r0]
	cmp r2, #0
	bne _08183F64
	movs r0, #1
	strh r0, [r1, #0x32]
	movs r0, #2
	strh r0, [r1, #0x3a]
	strh r2, [r1, #0x3c]
	movs r0, #0xc
	strh r0, [r1, #0x38]
	strh r0, [r1, #0x36]
	movs r0, #8
	strh r0, [r1, #0x34]
_08183F64:
	adds r0, r1, #0
	bl sub_08183E54
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_7B

	thumb_func_start sub_08183F70
sub_08183F70: @ 0x08183F70
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	ble _08183FA8
	movs r2, #0x3a
	ldrsh r1, [r5, r2]
	ldrh r2, [r5, #0x36]
	movs r3, #0x36
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bgt _08183F98
	ldr r0, _08183F94
	str r0, [r5, #0x1c]
	b _08183FA0
	.align 2, 0
_08183F94: .4byte 0x08184C35
_08183F98:
	adds r0, r2, #1
	movs r1, #0
	strh r0, [r5, #0x36]
	strh r1, [r5, #0x3c]
_08183FA0:
	movs r0, #0
	strh r0, [r5, #0x24]
	strh r0, [r5, #0x26]
	b _08184034
_08183FA8:
	cmp r0, #0x9f
	ble _08183FD2
	cmp r0, r1
	ble _08183FB2
	strh r1, [r5, #0x3c]
_08183FB2:
	movs r0, #0x3c
	ldrsh r1, [r5, r0]
	adds r0, r1, #0
	cmp r1, #0
	bge _08183FBE
	adds r0, #0xff
_08183FBE:
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #8
	bl Sin
	rsbs r0, r0, #0
	b _08184000
_08183FD2:
	cmp r0, #0x5f
	ble _08183FF6
	movs r0, #0x60
	movs r1, #6
	bl Sin
	adds r4, r0, #0
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	subs r0, #0x60
	lsls r0, r0, #0x11
	asrs r0, r0, #0x10
	movs r1, #4
	bl Sin
	subs r4, r4, r0
	strh r4, [r5, #0x26]
	b _08184002
_08183FF6:
	movs r2, #0x3c
	ldrsh r0, [r5, r2]
	movs r1, #6
	bl Sin
_08184000:
	strh r0, [r5, #0x26]
_08184002:
	movs r3, #0x3c
	ldrsh r0, [r5, r3]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	movs r2, #0x38
	ldrsh r1, [r5, r2]
	bl Sin
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r5, #0x36]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0818402A
	lsls r0, r2, #0x10
	rsbs r0, r0, #0
	lsrs r2, r0, #0x10
_0818402A:
	strh r2, [r5, #0x24]
	ldrh r0, [r5, #0x34]
	ldrh r3, [r5, #0x3c]
	adds r0, r0, r3
	strh r0, [r5, #0x3c]
_08184034:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08183F70

	thumb_func_start pokemonanimfunc_7C
pokemonanimfunc_7C: @ 0x0818403C
	push {lr}
	adds r2, r0, #0
	movs r0, #0x32
	ldrsh r3, [r2, r0]
	cmp r3, #0
	bne _0818405C
	movs r1, #1
	strh r1, [r2, #0x32]
	movs r0, #2
	strh r0, [r2, #0x3a]
	strh r3, [r2, #0x3c]
	movs r0, #0x10
	strh r0, [r2, #0x38]
	strh r1, [r2, #0x36]
	movs r0, #4
	strh r0, [r2, #0x34]
_0818405C:
	adds r0, r2, #0
	bl sub_08183F70
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_7C

	thumb_func_start pokemonanimfunc_7D
pokemonanimfunc_7D: @ 0x08184068
	push {lr}
	adds r2, r0, #0
	movs r0, #0x32
	ldrsh r3, [r2, r0]
	cmp r3, #0
	bne _08184088
	movs r1, #1
	strh r1, [r2, #0x32]
	movs r0, #2
	strh r0, [r2, #0x3a]
	strh r3, [r2, #0x3c]
	movs r0, #0x10
	strh r0, [r2, #0x38]
	strh r1, [r2, #0x36]
	movs r0, #6
	strh r0, [r2, #0x34]
_08184088:
	adds r0, r2, #0
	bl sub_08183F70
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_7D

	thumb_func_start pokemonanimfunc_7E
pokemonanimfunc_7E: @ 0x08184094
	push {lr}
	adds r2, r0, #0
	movs r0, #0x32
	ldrsh r3, [r2, r0]
	cmp r3, #0
	bne _081840B4
	movs r1, #1
	strh r1, [r2, #0x32]
	movs r0, #3
	strh r0, [r2, #0x3a]
	strh r3, [r2, #0x3c]
	movs r0, #0x10
	strh r0, [r2, #0x38]
	strh r1, [r2, #0x36]
	movs r0, #8
	strh r0, [r2, #0x34]
_081840B4:
	adds r0, r2, #0
	bl sub_08183F70
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_7E

	thumb_func_start pokemonanimfunc_7F
pokemonanimfunc_7F: @ 0x081840C0
	push {lr}
	adds r2, r0, #0
	movs r0, #0x32
	ldrsh r1, [r2, r0]
	cmp r1, #0
	bne _081840DE
	movs r0, #1
	strh r0, [r2, #0x32]
	strh r0, [r2, #0x3a]
	strh r1, [r2, #0x3c]
	movs r1, #4
	strh r1, [r2, #0x38]
	movs r0, #6
	strh r0, [r2, #0x36]
	strh r1, [r2, #0x34]
_081840DE:
	adds r0, r2, #0
	bl sub_08183E54
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_7F

	thumb_func_start pokemonanimfunc_80
pokemonanimfunc_80: @ 0x081840E8
	push {lr}
	adds r1, r0, #0
	movs r0, #0x32
	ldrsh r2, [r1, r0]
	cmp r2, #0
	bne _08184106
	movs r0, #1
	strh r0, [r1, #0x32]
	strh r0, [r1, #0x3a]
	strh r2, [r1, #0x3c]
	movs r0, #4
	strh r0, [r1, #0x38]
	movs r0, #6
	strh r0, [r1, #0x36]
	strh r0, [r1, #0x34]
_08184106:
	adds r0, r1, #0
	bl sub_08183E54
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_80

	thumb_func_start pokemonanimfunc_81
pokemonanimfunc_81: @ 0x08184110
	push {lr}
	adds r1, r0, #0
	movs r0, #0x32
	ldrsh r2, [r1, r0]
	cmp r2, #0
	bne _08184132
	movs r0, #1
	strh r0, [r1, #0x32]
	movs r0, #2
	strh r0, [r1, #0x3a]
	strh r2, [r1, #0x3c]
	movs r0, #4
	strh r0, [r1, #0x38]
	movs r0, #6
	strh r0, [r1, #0x36]
	movs r0, #8
	strh r0, [r1, #0x34]
_08184132:
	adds r0, r1, #0
	bl sub_08183E54
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_81

	thumb_func_start sub_0818413C
sub_0818413C: @ 0x0818413C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	lsls r0, r0, #7
	movs r2, #0x3c
	ldrsh r1, [r4, r2]
	bl __divsi3
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	bl Sin
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r0, r1, #8
	rsbs r0, r0, #0
	strh r0, [r4, #0x3a]
	movs r0, #0x36
	ldrsh r2, [r4, r0]
	adds r0, r4, #0
	movs r3, #0
	bl sub_0817F29C
	movs r2, #0x80
	lsls r2, r2, #1
	ldrh r3, [r4, #0x3a]
	adds r0, r4, #0
	adds r1, r2, #0
	bl HandleSetAffineData
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0818413C

	thumb_func_start pokemonanimfunc_82
pokemonanimfunc_82: @ 0x08184188
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _081841AC
	adds r0, r4, #0
	bl HandleStartAffineAnim
	movs r0, #0x3c
	strh r0, [r4, #0x3c]
	movs r0, #8
	strh r0, [r4, #0x38]
	ldr r0, _081841EC
	strh r0, [r4, #0x36]
	movs r0, #1
	strh r0, [r4, #0x34]
	strh r5, [r4, #0x2e]
_081841AC:
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	movs r3, #0x3c
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _081841F8
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r1, r2, #0
	movs r3, #0
	bl HandleSetAffineData
	movs r2, #0
	strh r2, [r4, #0x24]
	strh r2, [r4, #0x26]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	movs r3, #0x34
	ldrsh r1, [r4, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _081841F4
	adds r0, r4, #0
	bl sub_0817F628
	ldr r0, _081841F0
	str r0, [r4, #0x1c]
	b _08184204
	.align 2, 0
_081841EC: .4byte 0x0000FFE0
_081841F0: .4byte 0x08184C35
_081841F4:
	strh r2, [r4, #0x32]
	b _081841FE
_081841F8:
	adds r0, r4, #0
	bl sub_0818413C
_081841FE:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
_08184204:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_82

	thumb_func_start pokemonanimfunc_83
pokemonanimfunc_83: @ 0x0818420C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _08184230
	adds r0, r4, #0
	bl HandleStartAffineAnim
	movs r0, #0x5a
	strh r0, [r4, #0x3c]
	movs r0, #8
	strh r0, [r4, #0x38]
	ldr r0, _08184270
	strh r0, [r4, #0x36]
	movs r0, #1
	strh r0, [r4, #0x34]
	strh r5, [r4, #0x2e]
_08184230:
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	movs r3, #0x3c
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _0818427C
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r1, r2, #0
	movs r3, #0
	bl HandleSetAffineData
	movs r2, #0
	strh r2, [r4, #0x24]
	strh r2, [r4, #0x26]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	movs r3, #0x34
	ldrsh r1, [r4, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _08184278
	adds r0, r4, #0
	bl sub_0817F628
	ldr r0, _08184274
	str r0, [r4, #0x1c]
	b _08184288
	.align 2, 0
_08184270: .4byte 0x0000FFE0
_08184274: .4byte 0x08184C35
_08184278:
	strh r2, [r4, #0x32]
	b _08184282
_0818427C:
	adds r0, r4, #0
	bl sub_0818413C
_08184282:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
_08184288:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_83

	thumb_func_start pokemonanimfunc_84
pokemonanimfunc_84: @ 0x08184290
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r5, [r4, r0]
	cmp r5, #0
	bne _081842B4
	adds r0, r4, #0
	bl HandleStartAffineAnim
	movs r0, #0x1e
	strh r0, [r4, #0x3c]
	movs r0, #8
	strh r0, [r4, #0x38]
	ldr r0, _081842F4
	strh r0, [r4, #0x36]
	movs r0, #2
	strh r0, [r4, #0x34]
	strh r5, [r4, #0x2e]
_081842B4:
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	movs r3, #0x3c
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _08184300
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r1, r2, #0
	movs r3, #0
	bl HandleSetAffineData
	movs r2, #0
	strh r2, [r4, #0x24]
	strh r2, [r4, #0x26]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	movs r3, #0x34
	ldrsh r1, [r4, r3]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _081842FC
	adds r0, r4, #0
	bl sub_0817F628
	ldr r0, _081842F8
	str r0, [r4, #0x1c]
	b _0818430C
	.align 2, 0
_081842F4: .4byte 0x0000FFE0
_081842F8: .4byte 0x08184C35
_081842FC:
	strh r2, [r4, #0x32]
	b _08184306
_08184300:
	adds r0, r4, #0
	bl sub_0818413C
_08184306:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
_0818430C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_84

	thumb_func_start sub_08184314
sub_08184314: @ 0x08184314
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0x32
	ldrsh r1, [r6, r0]
	movs r2, #0x3c
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _08184348
	movs r0, #0
	strh r0, [r6, #0x26]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r6, #0
	adds r1, r2, #0
	movs r3, #0
	bl HandleSetAffineData
	adds r0, r6, #0
	bl sub_0817F628
	ldr r0, _08184344
	str r0, [r6, #0x1c]
	b _081843F0
	.align 2, 0
_08184344: .4byte 0x08184C35
_08184348:
	movs r1, #0x32
	ldrsh r0, [r6, r1]
	movs r2, #0x3a
	ldrsh r4, [r6, r2]
	adds r1, r4, #0
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl __divsi3
	adds r1, r0, #0
	cmp r1, #0
	bge _08184368
	adds r0, #0xff
_08184368:
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldrh r0, [r6, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _081843A4
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #0x20
	bl Sin
	movs r1, #0x80
	lsls r1, r1, #1
	adds r5, r1, #0
	adds r0, r0, r5
	strh r0, [r6, #0x36]
	adds r0, r4, #0
	movs r1, #0x20
	bl Sin
	adds r0, r0, r5
	strh r0, [r6, #0x38]
	adds r0, r4, #0
	movs r1, #0x20
	b _081843CA
_081843A4:
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	adds r0, r4, #0
	movs r1, #8
	bl Sin
	movs r2, #0x80
	lsls r2, r2, #1
	adds r5, r2, #0
	adds r0, r0, r5
	strh r0, [r6, #0x36]
	adds r0, r4, #0
	movs r1, #8
	bl Sin
	adds r0, r0, r5
	strh r0, [r6, #0x38]
	adds r0, r4, #0
	movs r1, #8
_081843CA:
	bl Sin
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _081843DC
	adds r0, #7
_081843DC:
	lsrs r0, r0, #3
	strh r0, [r6, #0x26]
	movs r0, #0x36
	ldrsh r1, [r6, r0]
	movs r0, #0x38
	ldrsh r2, [r6, r0]
	adds r0, r6, #0
	movs r3, #0
	bl HandleSetAffineData
_081843F0:
	ldrh r0, [r6, #0x32]
	adds r0, #1
	strh r0, [r6, #0x32]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_08184314

	thumb_func_start pokemonanimfunc_85
pokemonanimfunc_85: @ 0x081843FC
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _0818441C
	adds r0, r4, #0
	bl HandleStartAffineAnim
	ldrh r0, [r4, #0x26]
	adds r0, #2
	strh r0, [r4, #0x26]
	movs r0, #0x28
	strh r0, [r4, #0x3a]
	movs r0, #0x50
	strh r0, [r4, #0x3c]
_0818441C:
	adds r0, r4, #0
	bl sub_08184314
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_85

	thumb_func_start pokemonanimfunc_86
pokemonanimfunc_86: @ 0x08184428
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08184446
	adds r0, r4, #0
	bl HandleStartAffineAnim
	ldrh r0, [r4, #0x26]
	adds r0, #2
	strh r0, [r4, #0x26]
	movs r0, #0x28
	strh r0, [r4, #0x3a]
	strh r0, [r4, #0x3c]
_08184446:
	adds r0, r4, #0
	bl sub_08184314
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_86

	thumb_func_start pokemonanimfunc_87
pokemonanimfunc_87: @ 0x08184454
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0
	bne _08184472
	adds r0, r4, #0
	bl HandleStartAffineAnim
	ldrh r0, [r4, #0x26]
	adds r0, #2
	strh r0, [r4, #0x26]
	movs r0, #0x50
	strh r0, [r4, #0x3a]
	strh r0, [r4, #0x3c]
_08184472:
	adds r0, r4, #0
	bl sub_08184314
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_87

	thumb_func_start sub_08184480
sub_08184480: @ 0x08184480
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0817F5B8
	ldrh r0, [r4, #0x24]
	ldrh r1, [r4, #0x32]
	subs r0, r0, r1
	strh r0, [r4, #0x24]
	movs r0, #0x24
	ldrsh r1, [r4, r0]
	movs r2, #0x3a
	ldrsh r0, [r4, r2]
	cmn r1, r0
	bgt _081844AA
	ldrh r0, [r4, #0x3a]
	rsbs r0, r0, #0
	strh r0, [r4, #0x24]
	movs r0, #2
	strh r0, [r4, #0x3c]
	ldr r0, _081844B8
	str r0, [r4, #0x1c]
_081844AA:
	adds r0, r4, #0
	bl sub_0817F5B8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081844B8: .4byte 0x081844BD
	thumb_func_end sub_08184480

	thumb_func_start sub_081844BC
sub_081844BC: @ 0x081844BC
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0817F5B8
	ldrh r0, [r4, #0x3c]
	ldrh r2, [r4, #0x24]
	adds r1, r0, r2
	strh r1, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x3c]
	lsls r1, r1, #0x10
	cmp r1, #0
	blt _081844DA
	ldr r0, _081844E8
	str r0, [r4, #0x1c]
_081844DA:
	adds r0, r4, #0
	bl sub_0817F5B8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081844E8: .4byte 0x081844ED
	thumb_func_end sub_081844BC

	thumb_func_start sub_081844EC
sub_081844EC: @ 0x081844EC
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0817F5B8
	ldrh r0, [r4, #0x3c]
	ldrh r2, [r4, #0x24]
	adds r1, r0, r2
	strh r1, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x3c]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r4, #0x3a]
	movs r3, #0x3a
	ldrsh r0, [r4, r3]
	cmp r1, r0
	ble _08184514
	strh r2, [r4, #0x24]
	ldr r0, _08184520
	str r0, [r4, #0x1c]
_08184514:
	adds r0, r4, #0
	bl sub_0817F5B8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08184520: .4byte 0x08184525
	thumb_func_end sub_081844EC

	thumb_func_start sub_08184524
sub_08184524: @ 0x08184524
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0817F5B8
	ldrh r2, [r4, #0x34]
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	movs r3, #0x38
	ldrsh r0, [r4, r3]
	cmp r1, r0
	blt _08184544
	ldr r0, _08184540
	str r0, [r4, #0x1c]
	b _08184558
	.align 2, 0
_08184540: .4byte 0x08184565
_08184544:
	ldrh r0, [r4, #0x36]
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	rsbs r0, r0, #0
	strh r0, [r4, #0x36]
	adds r0, r2, #1
	strh r0, [r4, #0x34]
_08184558:
	adds r0, r4, #0
	bl sub_0817F5B8
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_08184524

	thumb_func_start sub_08184564
sub_08184564: @ 0x08184564
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0817F5B8
	ldrh r0, [r4, #0x24]
	subs r0, #2
	strh r0, [r4, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _08184586
	movs r0, #0
	strh r0, [r4, #0x24]
	adds r0, r4, #0
	bl sub_0817F628
	ldr r0, _08184594
	str r0, [r4, #0x1c]
_08184586:
	adds r0, r4, #0
	bl sub_0817F5B8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08184594: .4byte 0x08184C35
	thumb_func_end sub_08184564

	thumb_func_start pokemonanimfunc_88
pokemonanimfunc_88: @ 0x08184598
	push {r4, lr}
	adds r4, r0, #0
	bl HandleStartAffineAnim
	movs r2, #0
	movs r1, #4
	strh r1, [r4, #0x3c]
	movs r0, #0xc
	strh r0, [r4, #0x3a]
	movs r0, #0x10
	strh r0, [r4, #0x38]
	strh r1, [r4, #0x36]
	strh r2, [r4, #0x34]
	movs r0, #2
	strh r0, [r4, #0x32]
	ldr r0, _081845C0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081845C0: .4byte 0x08184481
	thumb_func_end pokemonanimfunc_88

	thumb_func_start pokemonanimfunc_89
pokemonanimfunc_89: @ 0x081845C4
	push {r4, lr}
	adds r4, r0, #0
	bl HandleStartAffineAnim
	movs r2, #0
	movs r1, #2
	strh r1, [r4, #0x3c]
	movs r0, #8
	strh r0, [r4, #0x3a]
	movs r0, #0xc
	strh r0, [r4, #0x38]
	strh r1, [r4, #0x36]
	strh r2, [r4, #0x34]
	movs r0, #1
	strh r0, [r4, #0x32]
	ldr r0, _081845EC
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081845EC: .4byte 0x08184481
	thumb_func_end pokemonanimfunc_89

	thumb_func_start pokemonanimfunc_8A
pokemonanimfunc_8A: @ 0x081845F0
	push {r4, lr}
	adds r4, r0, #0
	bl HandleStartAffineAnim
	movs r1, #0
	strh r1, [r4, #0x3c]
	movs r0, #6
	strh r0, [r4, #0x3a]
	strh r0, [r4, #0x38]
	movs r0, #2
	strh r0, [r4, #0x36]
	strh r1, [r4, #0x34]
	movs r0, #1
	strh r0, [r4, #0x32]
	ldr r0, _08184618
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08184618: .4byte 0x08184481
	thumb_func_end pokemonanimfunc_8A

	thumb_func_start sub_0818461C
sub_0818461C: @ 0x0818461C
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x30]
	strh r0, [r1, #0x24]
	ldrh r2, [r1, #0x2e]
	movs r3, #0x2e
	ldrsh r0, [r1, r3]
	cmp r0, #1
	ble _0818463A
	movs r2, #0x30
	ldrsh r0, [r1, r2]
	rsbs r0, r0, #0
	strh r0, [r1, #0x30]
	movs r0, #0
	b _0818463C
_0818463A:
	adds r0, r2, #1
_0818463C:
	strh r0, [r1, #0x2e]
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0818461C

	thumb_func_start BackAnimBlendYellow
BackAnimBlendYellow: @ 0x08184644
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08184674
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl sub_0818461C
	movs r1, #0x3a
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r1, r0, r5
	ldrb r0, [r1, #1]
	cmp r0, #0xff
	bne _0818467C
	movs r0, #0
	strh r0, [r4, #0x24]
	ldr r0, _08184678
	str r0, [r4, #0x1c]
	b _081846DA
	.align 2, 0
_08184674: .4byte 0x085D38DC
_08184678: .4byte 0x08184C35
_0818467C:
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	cmp r0, #1
	bne _081846AC
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818469C
	ldrh r0, [r4, #0x3c]
	ldr r3, _08184698
	movs r1, #0x10
	movs r2, #0x10
	bl BlendPalette
	b _081846A8
	.align 2, 0
_08184698: .4byte 0x000003FF
_0818469C:
	ldrh r0, [r4, #0x3c]
	ldr r3, _081846D0
	movs r1, #0x10
	movs r2, #0
	bl BlendPalette
_081846A8:
	movs r0, #0
	strh r0, [r4, #0x36]
_081846AC:
	movs r1, #0x3a
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrb r1, [r0, #1]
	movs r2, #0x38
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _081846D4
	movs r1, #0
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r1, [r4, #0x38]
	ldrh r0, [r4, #0x3a]
	adds r0, #1
	strh r0, [r4, #0x3a]
	b _081846DA
	.align 2, 0
_081846D0: .4byte 0x000003FF
_081846D4:
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
_081846DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end BackAnimBlendYellow

	thumb_func_start pokemonanimfunc_8B
pokemonanimfunc_8B: @ 0x081846E0
	push {r4, lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x32]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _0818470C
	ldrb r0, [r2, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	adds r0, r0, r1
	strh r0, [r2, #0x3c]
	strh r3, [r2, #0x3a]
	strh r3, [r2, #0x38]
	strh r3, [r2, #0x36]
	strh r3, [r2, #0x34]
_0818470C:
	adds r0, r2, #0
	bl BackAnimBlendYellow
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8B

	thumb_func_start pokemonanimfunc_8C
pokemonanimfunc_8C: @ 0x08184718
	push {r4, r5, lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x32]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #0x32]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	cmp r4, #1
	bne _08184744
	ldrb r0, [r2, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r5, #0
	adds r0, r0, r1
	strh r0, [r2, #0x3c]
	strh r3, [r2, #0x3a]
	strh r3, [r2, #0x38]
	strh r3, [r2, #0x36]
	strh r4, [r2, #0x34]
_08184744:
	adds r0, r2, #0
	bl BackAnimBlendYellow
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8C

	thumb_func_start pokemonanimfunc_8D
pokemonanimfunc_8D: @ 0x08184750
	push {r4, lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x32]
	adds r0, #1
	movs r3, #0
	strh r0, [r2, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #1
	bne _0818477E
	ldrb r0, [r2, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r4, #0
	adds r0, r0, r1
	strh r0, [r2, #0x3c]
	strh r3, [r2, #0x3a]
	strh r3, [r2, #0x38]
	strh r3, [r2, #0x36]
	movs r0, #2
	strh r0, [r2, #0x34]
_0818477E:
	adds r0, r2, #0
	bl BackAnimBlendYellow
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_8D

	thumb_func_start BackAnimBlend
BackAnimBlend: @ 0x0818478C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	cmp r0, #0x7f
	ble _081847B0
	ldrh r0, [r4, #0x3c]
	movs r1, #0x10
	movs r2, #0
	movs r3, #0x1f
	bl BlendPalette
	ldr r0, _081847AC
	str r0, [r4, #0x1c]
	b _081847D6
	.align 2, 0
_081847AC: .4byte 0x08184C35
_081847B0:
	movs r5, #0x32
	ldrsh r0, [r4, r5]
	movs r1, #0xc
	bl Sin
	adds r2, r0, #0
	strh r2, [r4, #0x3a]
	ldrh r0, [r4, #0x3c]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r3, _081847DC
	movs r5, #0x30
	ldrsh r1, [r4, r5]
	lsls r1, r1, #1
	adds r1, r1, r3
	ldrh r3, [r1]
	movs r1, #0x10
	bl BlendPalette
_081847D6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081847DC: .4byte 0x085D38E8
	thumb_func_end BackAnimBlend

	thumb_func_start sub_081847E0
sub_081847E0: @ 0x081847E0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bge _08184878
	adds r0, r4, #0
	bl sub_0817F5B8
	movs r3, #0x38
	ldrsh r1, [r4, r3]
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	cmp r1, r0
	ble _0818481C
	ldrh r0, [r4, #0x34]
	adds r0, #1
	movs r2, #0
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r3, #0x36
	ldrsh r1, [r4, r3]
	cmp r0, r1
	bge _08184818
	strh r2, [r4, #0x38]
_08184818:
	strh r2, [r4, #0x24]
	b _08184872
_0818481C:
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	lsrs r0, r1, #0x1f
	adds r0, r1, r0
	asrs r0, r0, #1
	lsls r0, r0, #1
	subs r1, r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0xf
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #7
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	bl __divsi3
	adds r1, r0, #0
	cmp r1, #0
	bge _08184850
	adds r0, #0xff
_08184850:
	asrs r0, r0, #8
	lsls r0, r0, #8
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #6
	bl Sin
	lsls r1, r5, #0x18
	asrs r1, r1, #0x18
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r2, #0
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
_08184872:
	adds r0, r4, #0
	bl sub_0817F5B8
_08184878:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081847E0

	thumb_func_start pokemonanimfunc_8E
pokemonanimfunc_8E: @ 0x08184880
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _081848AA
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0xa
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #2
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r2, [r4, #0x30]
_081848AA:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _081848BA
	adds r0, r4, #0
	bl BackAnimBlend
_081848BA:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _081848DC
	adds r0, r4, #0
	bl sub_081847E0
_081848DC:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8E

	thumb_func_start pokemonanimfunc_8F
pokemonanimfunc_8F: @ 0x081848E8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184912
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x14
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r2, [r4, #0x30]
_08184912:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184922
	adds r0, r4, #0
	bl BackAnimBlend
_08184922:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184944
	adds r0, r4, #0
	bl sub_081847E0
_08184944:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_8F

	thumb_func_start pokemonanimfunc_90
pokemonanimfunc_90: @ 0x08184950
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _0818497A
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x50
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r2, [r4, #0x30]
_0818497A:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0818498A
	adds r0, r4, #0
	bl BackAnimBlend
_0818498A:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _081849AC
	adds r0, r4, #0
	bl sub_081847E0
_081849AC:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_90

	thumb_func_start pokemonanimfunc_91
pokemonanimfunc_91: @ 0x081849B8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _081849E4
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0xa
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #2
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	movs r0, #1
	strh r0, [r4, #0x30]
_081849E4:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _081849F4
	adds r0, r4, #0
	bl BackAnimBlend
_081849F4:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184A16
	adds r0, r4, #0
	bl sub_081847E0
_08184A16:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_91

	thumb_func_start pokemonanimfunc_92
pokemonanimfunc_92: @ 0x08184A24
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184A4E
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x14
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r0, [r4, #0x30]
_08184A4E:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184A5E
	adds r0, r4, #0
	bl BackAnimBlend
_08184A5E:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184A80
	adds r0, r4, #0
	bl sub_081847E0
_08184A80:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_92

	thumb_func_start pokemonanimfunc_93
pokemonanimfunc_93: @ 0x08184A8C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184AB6
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x50
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r0, [r4, #0x30]
_08184AB6:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184AC6
	adds r0, r4, #0
	bl BackAnimBlend
_08184AC6:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184AE8
	adds r0, r4, #0
	bl sub_081847E0
_08184AE8:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_93

	thumb_func_start pokemonanimfunc_94
pokemonanimfunc_94: @ 0x08184AF4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184B1E
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0xa
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #2
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	strh r0, [r4, #0x30]
_08184B1E:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184B2E
	adds r0, r4, #0
	bl BackAnimBlend
_08184B2E:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184B50
	adds r0, r4, #0
	bl sub_081847E0
_08184B50:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end pokemonanimfunc_94

	thumb_func_start pokemonanimfunc_95
pokemonanimfunc_95: @ 0x08184B5C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184B88
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x14
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	movs r0, #2
	strh r0, [r4, #0x30]
_08184B88:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184B98
	adds r0, r4, #0
	bl BackAnimBlend
_08184B98:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184BBA
	adds r0, r4, #0
	bl sub_081847E0
_08184BBA:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_95

	thumb_func_start pokemonanimfunc_96
pokemonanimfunc_96: @ 0x08184BC8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	cmp r2, #0
	bne _08184BF4
	ldrb r0, [r4, #5]
	lsrs r0, r0, #4
	lsls r0, r0, #4
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r3, #0
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	movs r0, #0x50
	strh r0, [r4, #0x2e]
	strh r2, [r4, #0x38]
	movs r0, #1
	strh r0, [r4, #0x36]
	strh r2, [r4, #0x34]
	movs r0, #2
	strh r0, [r4, #0x30]
_08184BF4:
	ldrh r0, [r4, #0x32]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08184C04
	adds r0, r4, #0
	bl BackAnimBlend
_08184C04:
	movs r0, #0x32
	ldrsh r2, [r4, r0]
	movs r3, #0x2e
	ldrsh r1, [r4, r3]
	movs r3, #0x36
	ldrsh r0, [r4, r3]
	muls r1, r0, r1
	movs r0, #0x80
	subs r0, r0, r1
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	cmp r2, r0
	blt _08184C26
	adds r0, r4, #0
	bl sub_081847E0
_08184C26:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end pokemonanimfunc_96

	thumb_func_start SpriteCB_SetDummyOnAnimEnd
SpriteCB_SetDummyOnAnimEnd: @ 0x08184C34
	push {lr}
	adds r2, r0, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08184C48
	ldr r0, _08184C4C
	str r0, [r2, #0x1c]
_08184C48:
	pop {r0}
	bx r0
	.align 2, 0
_08184C4C: .4byte 0x08007141
	thumb_func_end SpriteCB_SetDummyOnAnimEnd

