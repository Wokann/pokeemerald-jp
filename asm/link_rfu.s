.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_0800F20C
sub_0800F20C: @ 0x0800F20C
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, _0800F220
	ldrb r1, [r0, #0xc]
	adds r5, r0, #0
	cmp r1, #1
	bne _0800F224
	movs r0, #0
	b _0800F246
	.align 2, 0
_0800F220: .4byte 0x030050A0
_0800F224:
	movs r2, #0
	ldr r0, _0800F24C
	adds r4, r5, r0
_0800F22A:
	adds r1, r2, r4
	adds r0, r3, r2
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _0800F22A
	ldr r1, _0800F250
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r0, r3
	ldrb r0, [r0]
_0800F246:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800F24C: .4byte 0x00000996
_0800F250: .4byte 0x000008F6
	thumb_func_end sub_0800F20C

	thumb_func_start rfu_func_080F97B8
rfu_func_080F97B8: @ 0x0800F254
	push {lr}
	ldr r0, _0800F28C
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800F286
	ldr r3, _0800F290
	ldrh r2, [r3]
	cmp r2, #0
	beq _0800F286
	ldr r0, _0800F294
	ldrb r0, [r0]
	cmp r0, #1
	beq _0800F286
	ldr r1, _0800F298
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrb r0, [r1]
	lsls r0, r0, #8
	orrs r0, r2
	strh r0, [r3]
	movs r0, #0xbe
	lsls r0, r0, #8
	bl sub_0800F7F8
_0800F286:
	pop {r0}
	bx r0
	.align 2, 0
_0800F28C: .4byte 0x030031C4
_0800F290: .4byte 0x03005B08
_0800F294: .4byte 0x03002354
_0800F298: .4byte 0x03000D78
	thumb_func_end rfu_func_080F97B8

	thumb_func_start sub_0800F29C
sub_0800F29C: @ 0x0800F29C
	ldr r0, _0800F2A0
	bx lr
	.align 2, 0
_0800F2A0: .4byte 0x020227CC
	thumb_func_end sub_0800F29C

	thumb_func_start IsSendingKeysToRfu
IsSendingKeysToRfu: @ 0x0800F2A4
	push {lr}
	movs r2, #0
	ldr r0, _0800F2BC
	ldr r1, [r0]
	ldr r0, _0800F2C0
	cmp r1, r0
	bne _0800F2B4
	movs r2, #1
_0800F2B4:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_0800F2BC: .4byte 0x030050A0
_0800F2C0: .4byte 0x0800F255
	thumb_func_end IsSendingKeysToRfu

	thumb_func_start StartSendingKeysToRfu
StartSendingKeysToRfu: @ 0x0800F2C4
	push {r4, lr}
	ldr r4, _0800F2E4
	ldr r0, [r4]
	cmp r0, #0
	beq _0800F2DA
	ldr r0, _0800F2E8
	ldr r1, _0800F2EC
	ldr r2, _0800F2F0
	movs r3, #1
	bl AGBAssert
_0800F2DA:
	ldr r0, _0800F2F4
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F2E4: .4byte 0x030050A0
_0800F2E8: .4byte 0x082C053C
_0800F2EC: .4byte 0x000005E6
_0800F2F0: .4byte 0x082C0544
_0800F2F4: .4byte 0x0800F255
	thumb_func_end StartSendingKeysToRfu

	thumb_func_start ClearLinkRfuCallback
ClearLinkRfuCallback: @ 0x0800F2F8
	ldr r1, _0800F300
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0800F300: .4byte 0x030050A0
	thumb_func_end ClearLinkRfuCallback

	thumb_func_start sub_0800F304
sub_0800F304: @ 0x0800F304
	push {lr}
	movs r0, #0x88
	lsls r0, r0, #7
	bl sub_0800F7F8
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800F320
	bl GetBlenderArrowPosition
	ldr r1, _0800F32C
	strh r0, [r1, #0xc]
_0800F320:
	ldr r1, _0800F330
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0800F32C: .4byte 0x030031B0
_0800F330: .4byte 0x02022078
	thumb_func_end sub_0800F304

	thumb_func_start Rfu_SetBerryBlenderLinkCallback
Rfu_SetBerryBlenderLinkCallback: @ 0x0800F334
	push {lr}
	ldr r1, _0800F348
	ldr r0, [r1]
	cmp r0, #0
	bne _0800F342
	ldr r0, _0800F34C
	str r0, [r1]
_0800F342:
	pop {r0}
	bx r0
	.align 2, 0
_0800F348: .4byte 0x030050A0
_0800F34C: .4byte 0x0800F305
	thumb_func_end Rfu_SetBerryBlenderLinkCallback

	thumb_func_start sub_0800F350
sub_0800F350: @ 0x0800F350
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r0, #0
	mov r8, r0
_0800F35E:
	mov r1, r8
	lsls r0, r1, #4
	ldr r2, _0800F3A4
	adds r1, r0, r2
	ldrh r7, [r1]
	movs r3, #0xff
	lsls r3, r3, #8
	adds r1, r3, #0
	ands r1, r7
	movs r2, #0x88
	lsls r2, r2, #8
	adds r5, r0, #0
	cmp r1, r2
	beq _0800F444
	cmp r1, r2
	bgt _0800F3BA
	movs r0, #0xcc
	lsls r0, r0, #7
	cmp r1, r0
	bne _0800F388
	b _0800F5C4
_0800F388:
	cmp r1, r0
	bgt _0800F3A8
	movs r0, #0x88
	lsls r0, r0, #7
	cmp r1, r0
	bne _0800F396
	b _0800F6D8
_0800F396:
	movs r0, #0xbe
	lsls r0, r0, #7
	cmp r1, r0
	bne _0800F3A0
	b _0800F5B4
_0800F3A0:
	b _0800F6E8
	.align 2, 0
_0800F3A4: .4byte 0x03003130
_0800F3A8:
	movs r0, #0xee
	lsls r0, r0, #7
	cmp r1, r0
	beq _0800F404
	movs r0, #0xf0
	lsls r0, r0, #7
	cmp r1, r0
	beq _0800F3F2
	b _0800F6E8
_0800F3BA:
	movs r0, #0xbe
	lsls r0, r0, #8
	cmp r1, r0
	bne _0800F3C4
	b _0800F6D8
_0800F3C4:
	cmp r1, r0
	bgt _0800F3DC
	movs r0, #0x89
	lsls r0, r0, #8
	cmp r1, r0
	beq _0800F4AC
	movs r0, #0xa1
	lsls r0, r0, #8
	cmp r1, r0
	bne _0800F3DA
	b _0800F590
_0800F3DA:
	b _0800F6E8
_0800F3DC:
	movs r0, #0xed
	lsls r0, r0, #8
	cmp r1, r0
	bne _0800F3E6
	b _0800F5F4
_0800F3E6:
	movs r0, #0xee
	lsls r0, r0, #8
	cmp r1, r0
	bne _0800F3F0
	b _0800F694
_0800F3F0:
	b _0800F6E8
_0800F3F2:
	ldr r4, _0800F42C
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne _0800F404
	ldr r0, _0800F430
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800F404
	b _0800F734
_0800F404:
	ldr r0, _0800F434
	ldr r0, [r0]
	ldrb r0, [r0]
	mov r6, r8
	adds r6, #1
	cmp r0, #0
	beq _0800F414
	b _0800F6EC
_0800F414:
	ldr r1, _0800F438
	adds r0, r5, r1
	ldrh r0, [r0]
	ldr r2, _0800F42C
	strb r0, [r2, #0xd]
	ldr r3, _0800F43C
	adds r0, r5, r3
	bl sub_0800F20C
	ldr r4, _0800F440
	strb r0, [r4]
	b _0800F6EC
	.align 2, 0
_0800F42C: .4byte 0x030050A0
_0800F430: .4byte 0x030031C4
_0800F434: .4byte 0x03007630
_0800F438: .4byte 0x03003132
_0800F43C: .4byte 0x03003134
_0800F440: .4byte 0x03005A26
_0800F444:
	ldr r0, _0800F4A0
	mov sb, r0
	mov r1, r8
	lsls r0, r1, #2
	add r0, r8
	lsls r7, r0, #2
	mov r2, sb
	adds r3, r7, r2
	movs r4, #0x92
	adds r4, r4, r3
	mov ip, r4
	ldrb r4, [r4]
	mov r6, r8
	adds r6, #1
	cmp r4, #0
	beq _0800F466
	b _0800F6EC
_0800F466:
	adds r0, r3, #0
	adds r0, #0x80
	movs r2, #0
	strh r4, [r0]
	ldr r1, _0800F4A4
	adds r0, r5, r1
	ldrh r0, [r0]
	adds r1, r3, #0
	adds r1, #0x82
	strh r0, [r1]
	ldr r1, _0800F4A8
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r0, r3, #0
	adds r0, #0x91
	strb r1, [r0]
	mov r0, sb
	adds r0, #0x88
	adds r0, r7, r0
	str r4, [r0]
	movs r0, #1
	mov r3, ip
	strb r0, [r3]
	mov r0, sb
	adds r0, #0x5c
	add r0, r8
	strb r2, [r0]
	b _0800F6EC
	.align 2, 0
_0800F4A0: .4byte 0x030050A0
_0800F4A4: .4byte 0x03003132
_0800F4A8: .4byte 0x03003134
_0800F4AC:
	ldr r4, _0800F57C
	mov sb, r4
	mov r0, r8
	lsls r1, r0, #2
	adds r0, r1, r0
	lsls r4, r0, #2
	mov r3, sb
	adds r2, r4, r3
	adds r0, r2, #0
	adds r0, #0x92
	ldrb r3, [r0]
	mov sl, r1
	mov r6, r8
	adds r6, #1
	cmp r3, #1
	beq _0800F4CE
	b _0800F6EC
_0800F4CE:
	movs r0, #0xff
	ands r0, r7
	adds r2, #0x80
	strh r0, [r2]
	mov r1, sb
	adds r1, #0x88
	adds r1, r4, r1
	lsls r3, r0
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	movs r4, #0
	ldr r0, _0800F580
	mov sb, r0
	mov ip, r2
	mov r1, r8
	lsls r7, r1, #8
	adds r3, r5, #0
_0800F4F2:
	mov r2, ip
	ldrh r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	lsls r1, r1, #1
	adds r1, r1, r7
	add r1, sb
	adds r2, r4, #1
	lsls r0, r2, #1
	adds r0, r0, r3
	ldr r4, _0800F584
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	cmp r4, #5
	bls _0800F4F2
	ldr r4, _0800F57C
	mov r0, sl
	add r0, r8
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x88
	adds r1, r0, r1
	adds r2, r0, r4
	adds r0, r2, #0
	adds r0, #0x82
	ldrh r0, [r0]
	lsls r0, r0, #2
	ldr r3, _0800F588
	adds r0, r0, r3
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	beq _0800F540
	b _0800F6EC
_0800F540:
	adds r1, r2, #0
	adds r1, #0x92
	movs r0, #2
	strb r0, [r1]
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl Rfu_SetBlockReceivedFlag
	bl sub_0800F29C
	ldrb r1, [r0, #0xa]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x45
	beq _0800F562
	b _0800F6EC
_0800F562:
	ldr r0, _0800F58C
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800F56C
	b _0800F6EC
_0800F56C:
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	beq _0800F574
	b _0800F6EC
_0800F574:
	ldr r0, _0800F580
	bl sub_08010568
	b _0800F6EC
	.align 2, 0
_0800F57C: .4byte 0x030050A0
_0800F580: .4byte 0x0202207C
_0800F584: .4byte 0x03003130
_0800F588: .4byte 0x082C0378
_0800F58C: .4byte 0x030031C4
_0800F590:
	ldr r2, _0800F5AC
	ldr r3, _0800F5B0
	adds r0, r5, r3
	ldrh r1, [r0]
	lsls r1, r1, #3
	adds r0, r1, r2
	ldr r0, [r0]
	adds r2, #4
	adds r1, r1, r2
	ldrh r1, [r1]
	bl Rfu_InitBlockSend
	b _0800F6E8
	.align 2, 0
_0800F5AC: .4byte 0x082C0408
_0800F5B0: .4byte 0x03003132
_0800F5B4:
	ldr r1, _0800F5C0
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	b _0800F6E8
	.align 2, 0
_0800F5C0: .4byte 0x03005184
_0800F5C4:
	ldr r2, _0800F5EC
	movs r4, #0x80
	lsls r4, r4, #1
	adds r0, r2, r4
	ldr r3, _0800F5F0
	adds r1, r5, r3
	ldrh r0, [r0]
	mov r6, r8
	adds r6, #1
	ldrh r1, [r1]
	cmp r0, r1
	beq _0800F5DE
	b _0800F6EC
_0800F5DE:
	adds r0, r2, #0
	adds r0, #0xe9
	add r0, r8
	movs r1, #1
	strb r1, [r0]
	b _0800F6EC
	.align 2, 0
_0800F5EC: .4byte 0x030050A0
_0800F5F0: .4byte 0x03003132
_0800F5F4:
	ldr r7, _0800F640
	ldrb r2, [r7, #0xc]
	cmp r2, #0
	bne _0800F65C
	ldr r3, _0800F644
	ldrb r0, [r3]
	mov r6, r8
	adds r6, #1
	cmp r0, #0
	beq _0800F6EC
	ldr r0, _0800F648
	adds r4, r5, r0
	ldrh r1, [r4]
	ldr r0, _0800F64C
	ldr r0, [r0]
	ldrb r0, [r0, #2]
	ands r1, r0
	cmp r1, #0
	beq _0800F62C
	strb r2, [r3]
	bl rfu_LMAN_requestChangeAgbClockMaster
	ldr r1, _0800F650
	adds r0, r5, r1
	ldrh r1, [r0]
	ldr r2, _0800F654
	adds r0, r7, r2
	strb r1, [r0]
_0800F62C:
	ldr r0, _0800F658
	adds r0, #6
	adds r0, r5, r0
	ldrh r0, [r0]
	strb r0, [r7, #0xd]
	ldrh r0, [r4]
	bl sub_080104E8
	b _0800F6EC
	.align 2, 0
_0800F640: .4byte 0x030050A0
_0800F644: .4byte 0x030031C4
_0800F648: .4byte 0x03003132
_0800F64C: .4byte 0x03007630
_0800F650: .4byte 0x03003134
_0800F654: .4byte 0x0000099C
_0800F658: .4byte 0x03003130
_0800F65C:
	movs r0, #0xee
	lsls r0, r0, #8
	bl sub_0800F7F8
	ldr r1, _0800F684
	ldr r3, _0800F688
	adds r0, r5, r3
	ldrh r0, [r0]
	strh r0, [r1, #2]
	ldr r4, _0800F68C
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r1, #4]
	ldr r0, _0800F690
	adds r0, #6
	adds r0, r5, r0
	ldrh r0, [r0]
	strh r0, [r1, #6]
	b _0800F6E8
	.align 2, 0
_0800F684: .4byte 0x030031B0
_0800F688: .4byte 0x03003132
_0800F68C: .4byte 0x03003134
_0800F690: .4byte 0x03003130
_0800F694:
	ldr r4, _0800F6C4
	ldrb r0, [r4, #0xc]
	mov r6, r8
	adds r6, #1
	cmp r0, #1
	bne _0800F728
	ldr r0, _0800F6C8
	adds r2, r4, r0
	ldr r1, _0800F6CC
	adds r3, r5, r1
	ldrb r1, [r3]
	ldrb r0, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _0800F6D0
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r2, _0800F6D4
	adds r0, r4, r2
	strb r1, [r0]
	ldrh r0, [r3]
	bl sub_080104E8
	b _0800F6EC
	.align 2, 0
_0800F6C4: .4byte 0x030050A0
_0800F6C8: .4byte 0x0000099B
_0800F6CC: .4byte 0x03003132
_0800F6D0: .4byte 0x03003134
_0800F6D4: .4byte 0x0000099C
_0800F6D8:
	ldr r0, _0800F718
	mov r3, r8
	lsls r1, r3, #1
	adds r1, r1, r0
	ldr r4, _0800F71C
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r1]
_0800F6E8:
	mov r6, r8
	adds r6, #1
_0800F6EC:
	ldr r3, _0800F720
	ldrb r4, [r3, #0xc]
	cmp r4, #1
	bne _0800F728
	adds r0, r3, #0
	adds r0, #0x61
	mov r1, r8
	adds r2, r1, r0
	ldrb r0, [r2]
	adds r1, r0, #0
	cmp r1, #0
	beq _0800F728
	cmp r1, #4
	bne _0800F724
	adds r0, r3, #0
	adds r0, #0x5c
	add r0, r8
	movs r1, #0
	strb r4, [r0]
	strb r1, [r2]
	b _0800F728
	.align 2, 0
_0800F718: .4byte 0x030030C0
_0800F71C: .4byte 0x03003132
_0800F720: .4byte 0x030050A0
_0800F724:
	adds r0, #1
	strb r0, [r2]
_0800F728:
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	cmp r0, #4
	bhi _0800F734
	b _0800F35E
_0800F734:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0800F350

	thumb_func_start sub_0800F744
sub_0800F744: @ 0x0800F744
	push {lr}
	movs r2, #0
	ldr r0, _0800F758
	adds r1, r0, #0
	adds r1, #0x92
_0800F74E:
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800F75C
	movs r0, #0
	b _0800F766
	.align 2, 0
_0800F758: .4byte 0x030050A0
_0800F75C:
	adds r1, #0x14
	adds r2, #1
	cmp r2, #4
	ble _0800F74E
	movs r0, #1
_0800F766:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0800F744

	thumb_func_start sub_0800F76C
sub_0800F76C: @ 0x0800F76C
	push {r4, lr}
	movs r1, #0
	ldr r2, _0800F794
	ldrb r0, [r2, #0xd]
	cmp r1, r0
	bge _0800F7A0
	adds r4, r0, #0
	adds r3, r2, #0
	adds r3, #0x92
	adds r2, #0x5c
_0800F780:
	ldrb r0, [r3]
	cmp r0, #2
	bne _0800F78E
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _0800F798
_0800F78E:
	movs r0, #0
	b _0800F7A2
	.align 2, 0
_0800F794: .4byte 0x030050A0
_0800F798:
	adds r3, #0x14
	adds r1, #1
	cmp r1, r4
	blt _0800F780
_0800F7A0:
	movs r0, #1
_0800F7A2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0800F76C

	thumb_func_start sub_0800F7A8
sub_0800F7A8: @ 0x0800F7A8
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strh r1, [r0, #2]
	str r1, [r0, #4]
	str r1, [r0, #8]
	strb r2, [r0, #0x10]
	strb r2, [r0, #0x11]
	strb r2, [r0, #0x12]
	bx lr
	thumb_func_end sub_0800F7A8

	thumb_func_start Rfu_GetBlockReceivedStatus
Rfu_GetBlockReceivedStatus: @ 0x0800F7BC
	push {r4, lr}
	movs r2, #0
	movs r1, #0
	ldr r0, _0800F7F4
	adds r3, r0, #0
	adds r3, #0x92
	adds r4, r0, #0
	adds r4, #0x5c
_0800F7CC:
	ldrb r0, [r3]
	cmp r0, #2
	bne _0800F7E2
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #1
	bne _0800F7E2
	lsls r0, r1
	orrs r2, r0
	lsls r0, r2, #0x18
	lsrs r2, r0, #0x18
_0800F7E2:
	adds r3, #0x14
	adds r1, #1
	cmp r1, #4
	ble _0800F7CC
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800F7F4: .4byte 0x030050A0
	thumb_func_end Rfu_GetBlockReceivedStatus

	thumb_func_start sub_0800F7F8
sub_0800F7F8: @ 0x0800F7F8
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r5, _0800F830
	strh r1, [r5]
	movs r0, #0xf0
	lsls r0, r0, #7
	adds r4, r5, #0
	cmp r1, r0
	beq _0800F894
	cmp r1, r0
	bgt _0800F846
	movs r0, #0xbe
	lsls r0, r0, #7
	cmp r1, r0
	beq _0800F8E4
	cmp r1, r0
	bgt _0800F834
	movs r0, #0xbc
	lsls r0, r0, #6
	cmp r1, r0
	beq _0800F904
	movs r0, #0x88
	lsls r0, r0, #7
	cmp r1, r0
	beq _0800F8F8
	b _0800F92A
	.align 2, 0
_0800F830: .4byte 0x030031B0
_0800F834:
	movs r0, #0xcc
	lsls r0, r0, #7
	cmp r1, r0
	beq _0800F8E4
	movs r0, #0xee
	lsls r0, r0, #7
	cmp r1, r0
	beq _0800F894
	b _0800F92A
_0800F846:
	movs r0, #0xbe
	lsls r0, r0, #8
	cmp r1, r0
	beq _0800F924
	cmp r1, r0
	bgt _0800F92A
	movs r0, #0x88
	lsls r0, r0, #8
	cmp r1, r0
	beq _0800F864
	movs r0, #0xa1
	lsls r0, r0, #8
	cmp r1, r0
	beq _0800F87C
	b _0800F92A
_0800F864:
	ldr r0, _0800F878
	adds r1, r0, #0
	adds r1, #0x6e
	ldrh r1, [r1]
	strh r1, [r5, #2]
	adds r0, #0x7d
	ldrb r0, [r0]
	adds r0, #0x80
	strh r0, [r5, #4]
	b _0800F92A
	.align 2, 0
_0800F878: .4byte 0x030050A0
_0800F87C:
	bl sub_0800F744
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0800F92A
	ldr r0, _0800F890
	adds r0, #0x5a
	ldrb r0, [r0]
	b _0800F928
	.align 2, 0
_0800F890: .4byte 0x030050A0
_0800F894:
	ldr r3, _0800F8D0
	ldr r1, _0800F8D4
	adds r0, r3, r1
	ldr r2, _0800F8D8
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	eors r0, r2
	ldr r1, _0800F8DC
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r0, #1
	strb r0, [r3, #0xd]
	ldrb r0, [r3, #0xd]
	strh r0, [r4, #2]
	adds r2, r4, #4
	movs r4, #0
	ldr r0, _0800F8E0
	adds r3, r3, r0
_0800F8BA:
	adds r1, r2, r4
	adds r0, r4, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0800F8BA
	b _0800F92A
	.align 2, 0
_0800F8D0: .4byte 0x030050A0
_0800F8D4: .4byte 0x0000099A
_0800F8D8: .4byte 0x0000099B
_0800F8DC: .4byte 0x082C03E5
_0800F8E0: .4byte 0x00000996
_0800F8E4:
	ldr r0, _0800F8F4
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4, #2]
	b _0800F92A
	.align 2, 0
_0800F8F4: .4byte 0x030050A0
_0800F8F8:
	strh r1, [r5]
	ldr r0, _0800F900
	ldrh r0, [r0, #0x2c]
	b _0800F928
	.align 2, 0
_0800F900: .4byte 0x03002360
_0800F904:
	movs r4, #0
	ldr r3, _0800F920
_0800F908:
	adds r2, r4, #1
	lsls r1, r2, #1
	adds r1, r1, r5
	lsls r0, r4, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	cmp r4, #5
	bls _0800F908
	b _0800F92A
	.align 2, 0
_0800F920: .4byte 0x03005192
_0800F924:
	ldr r0, _0800F930
	ldrh r0, [r0]
_0800F928:
	strh r0, [r5, #2]
_0800F92A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800F930: .4byte 0x03005B08
	thumb_func_end sub_0800F7F8

	thumb_func_start sub_0800F934
sub_0800F934: @ 0x0800F934
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0800F960
	ldrh r0, [r0]
	cmp r0, #0
	bne _0800F95A
	bl sub_08011570
	cmp r0, #0
	bne _0800F95A
	ldr r0, _0800F964
	adds r1, r4, #0
	movs r2, #0xc
	bl memcpy
	movs r0, #0xbc
	lsls r0, r0, #6
	bl sub_0800F7F8
_0800F95A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800F960: .4byte 0x030031B0
_0800F964: .4byte 0x03005192
	thumb_func_end sub_0800F934

	thumb_func_start Rfu_InitBlockSend
Rfu_InitBlockSend: @ 0x0800F968
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r6, r1, #0
	cmp r6, #0xfc
	bls _0800F984
	ldr r0, _0800F9B0
	ldr r1, _0800F9B4
	ldr r2, _0800F9B8
	movs r3, #1
	bl AGBAssert
_0800F984:
	ldr r5, _0800F9BC
	ldr r0, [r5]
	cmp r0, #0
	bne _0800F9AC
	ldr r0, _0800F9C0
	ldrh r0, [r0]
	cmp r0, #0
	bne _0800F9AC
	movs r0, #0x7c
	adds r0, r0, r5
	mov sb, r0
	ldrb r1, [r0]
	mov r8, r1
	cmp r1, #0
	beq _0800F9C8
	ldr r1, _0800F9C4
	adds r1, #0x83
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800F9AC:
	movs r0, #0
	b _0800FA32
	.align 2, 0
_0800F9B0: .4byte 0x082C053C
_0800F9B4: .4byte 0x00000755
_0800F9B8: .4byte 0x082C0558
_0800F9BC: .4byte 0x030050A0
_0800F9C0: .4byte 0x030031B0
_0800F9C4: .4byte 0x020227FC
_0800F9C8:
	adds r0, r6, #0
	movs r1, #0xc
	bl __umodsi3
	rsbs r4, r0, #0
	orrs r4, r0
	lsrs r4, r4, #0x1f
	bl GetMultiplayerId
	adds r1, r5, #0
	adds r1, #0x7d
	strb r0, [r1]
	movs r0, #1
	mov r1, sb
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0xc
	bl __udivsi3
	adds r0, r0, r4
	adds r1, r5, #0
	adds r1, #0x6e
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x6c
	mov r1, r8
	strh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r6, r0
	bls _0800FA0A
	str r7, [r5, #0x70]
	b _0800FA1C
_0800FA0A:
	ldr r4, _0800FA40
	cmp r7, r4
	beq _0800FA1A
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl memcpy
_0800FA1A:
	str r4, [r5, #0x70]
_0800FA1C:
	movs r0, #0x88
	lsls r0, r0, #8
	bl sub_0800F7F8
	ldr r0, _0800FA44
	ldr r1, _0800FA48
	str r1, [r0]
	adds r0, #0x5b
	movs r1, #0
	strb r1, [r0]
	movs r0, #1
_0800FA32:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800FA40: .4byte 0x0202257C
_0800FA44: .4byte 0x030050A0
_0800FA48: .4byte 0x0800FA4D
	thumb_func_end Rfu_InitBlockSend

	thumb_func_start rfufunc_80F9F44
rfufunc_80F9F44: @ 0x0800FA4C
	push {r4, r5, lr}
	ldr r0, _0800FA7C
	ldrh r0, [r0]
	cmp r0, #0
	bne _0800FAA0
	movs r5, #0x88
	lsls r5, r5, #8
	adds r0, r5, #0
	bl sub_0800F7F8
	ldr r4, _0800FA80
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	bne _0800FA84
	adds r1, r4, #0
	adds r1, #0x5b
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0800FAA0
	b _0800FA9C
	.align 2, 0
_0800FA7C: .4byte 0x030031B0
_0800FA80: .4byte 0x030050A0
_0800FA84:
	bl GetMultiplayerId
	ldr r1, _0800FAA8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, r5
	bne _0800FAA0
_0800FA9C:
	ldr r0, _0800FAAC
	str r0, [r4]
_0800FAA0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800FAA8: .4byte 0x03003130
_0800FAAC: .4byte 0x0800FAB1
	thumb_func_end rfufunc_80F9F44

	thumb_func_start sub_0800FAB0
sub_0800FAB0: @ 0x0800FAB0
	push {r4, r5, r6, lr}
	ldr r0, _0800FB1C
	mov ip, r0
	ldr r5, [r0, #0x70]
	ldr r3, _0800FB20
	mov r2, ip
	adds r2, #0x6c
	ldrh r1, [r2]
	movs r4, #0x89
	lsls r4, r4, #8
	adds r0, r4, #0
	orrs r0, r1
	strh r0, [r3]
	movs r4, #0
	adds r6, r2, #0
	adds r3, #2
_0800FAD0:
	lsls r2, r4, #1
	ldrh r1, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, r0, r5
	ldrb r1, [r0, #1]
	lsls r1, r1, #8
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r3]
	adds r3, #2
	adds r4, #1
	cmp r4, #6
	ble _0800FAD0
	mov r0, ip
	adds r0, #0x6c
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r0, #2
	ldrh r0, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r0, r1
	bhi _0800FB14
	mov r0, ip
	adds r0, #0x7c
	movs r1, #0
	strb r1, [r0]
	ldr r0, _0800FB24
	mov r1, ip
	str r0, [r1]
_0800FB14:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800FB1C: .4byte 0x030050A0
_0800FB20: .4byte 0x030031B0
_0800FB24: .4byte 0x0800FB29
	thumb_func_end sub_0800FAB0

	thumb_func_start rfufunc_80FA020
rfufunc_80FA020: @ 0x0800FB28
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r5, _0800FBD0
	ldr r0, [r5, #0x70]
	mov r8, r0
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrb r0, [r5, #0xc]
	cmp r0, #0
	bne _0800FBF0
	ldr r3, _0800FBD4
	adds r2, r5, #0
	adds r2, #0x6e
	ldrh r0, [r2]
	subs r0, #1
	ldr r4, _0800FBD8
	adds r1, r4, #0
	orrs r0, r1
	strh r0, [r3]
	movs r4, #0
	mov sb, r5
	ldr r0, _0800FBDC
	mov ip, r0
	lsls r5, r6, #4
	adds r7, r2, #0
	adds r3, #2
_0800FB64:
	lsls r2, r4, #1
	ldrh r1, [r7]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	add r0, r8
	adds r1, r0, #0
	subs r1, #0xb
	ldrb r1, [r1]
	lsls r1, r1, #8
	subs r0, #0xc
	ldrb r0, [r0]
	orrs r0, r1
	strh r0, [r3]
	adds r3, #2
	adds r4, #1
	cmp r4, #6
	ble _0800FB64
	mov r1, ip
	adds r0, r5, r1
	ldrb r1, [r0]
	mov r3, sb
	adds r0, r3, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _0800FBF4
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r1, r3, #0
	adds r1, #0x88
	adds r1, r0, r1
	ldr r2, _0800FBE0
	adds r0, r0, r3
	adds r0, #0x82
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r1]
	ldr r0, [r0]
	cmp r1, r0
	beq _0800FBE8
	adds r0, r6, #0
	bl HandleSendFailure
	ldr r1, _0800FBE4
	adds r1, #0x64
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _0800FBF4
	.align 2, 0
_0800FBD0: .4byte 0x030050A0
_0800FBD4: .4byte 0x030031B0
_0800FBD8: .4byte 0xFFFF8900
_0800FBDC: .4byte 0x03003130
_0800FBE0: .4byte 0x082C0378
_0800FBE4: .4byte 0x020227FC
_0800FBE8:
	movs r0, #0
	mov r4, sb
	str r0, [r4]
	b _0800FBF4
_0800FBF0:
	movs r0, #0
	str r0, [r5]
_0800FBF4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end rfufunc_80FA020

	thumb_func_start Rfu_SendBlockRequest
Rfu_SendBlockRequest: @ 0x0800FC00
	push {lr}
	ldr r1, _0800FC18
	adds r1, #0x5a
	strb r0, [r1]
	movs r0, #0xa1
	lsls r0, r0, #8
	bl sub_0800F7F8
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_0800FC18: .4byte 0x030050A0
	thumb_func_end Rfu_SendBlockRequest

	thumb_func_start sub_0800FC1C
sub_0800FC1C: @ 0x0800FC1C
	push {lr}
	bl rfu_clearAllSlot
	bl rfu_LMAN_powerDownRFU
	ldr r1, _0800FC40
	movs r0, #0
	strb r0, [r1]
	ldr r2, _0800FC44
	adds r3, r2, #0
	adds r3, #0xef
	movs r1, #0
	movs r0, #1
	strb r0, [r3]
	str r1, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0800FC40: .4byte 0x030031C4
_0800FC44: .4byte 0x030050A0
	thumb_func_end sub_0800FC1C

	thumb_func_start sub_0800FC48
sub_0800FC48: @ 0x0800FC48
	push {lr}
	ldr r0, _0800FC64
	ldr r0, [r0]
	ldrb r1, [r0, #2]
	ldrb r0, [r0, #3]
	orrs r0, r1
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	bl sub_0800FC1C
	pop {r0}
	bx r0
	.align 2, 0
_0800FC64: .4byte 0x03007630
	thumb_func_end sub_0800FC48

	thumb_func_start sub_0800FC68
sub_0800FC68: @ 0x0800FC68
	push {r4, lr}
	ldr r4, _0800FC80
	ldrb r0, [r4, #0xc]
	cmp r0, #0
	bne _0800FC88
	bl rfu_LMAN_requestChangeAgbClockMaster
	ldr r0, _0800FC84
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	b _0800FC8C
	.align 2, 0
_0800FC80: .4byte 0x030050A0
_0800FC84: .4byte 0x0000099C
_0800FC88:
	ldr r0, _0800FC94
	str r0, [r4]
_0800FC8C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800FC94: .4byte 0x0800FC49
	thumb_func_end sub_0800FC68

	thumb_func_start LinkRfu_FatalError
LinkRfu_FatalError: @ 0x0800FC98
	push {lr}
	bl rfu_LMAN_requestChangeAgbClockMaster
	ldr r2, _0800FCBC
	ldr r0, _0800FCC0
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _0800FCC4
	ldr r1, [r0]
	ldrb r0, [r1, #2]
	ldrb r1, [r1, #3]
	orrs r0, r1
	ldr r1, _0800FCC8
	adds r2, r2, r1
	strb r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0800FCBC: .4byte 0x030050A0
_0800FCC0: .4byte 0x0000099C
_0800FCC4: .4byte 0x03007630
_0800FCC8: .4byte 0x0000099B
	thumb_func_end LinkRfu_FatalError

	thumb_func_start sub_0800FCCC
sub_0800FCCC: @ 0x0800FCCC
	push {r4, r5, lr}
	ldr r0, _0800FD14
	ldrb r5, [r0, #0xd]
	movs r2, #0
	movs r1, #0
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0xe4
_0800FCDC:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800FCE6
	adds r2, #1
_0800FCE6:
	adds r1, #1
	cmp r1, #4
	ble _0800FCDC
	cmp r2, r5
	bne _0800FD20
	ldr r2, _0800FD18
	ldr r0, [r2]
	movs r1, #0x21
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldrb r0, [r3, #0xc]
	cmp r0, #0
	bne _0800FD1C
	adds r0, r3, #0
	adds r0, #0xee
	ldrb r1, [r0]
	movs r1, #3
	strb r1, [r0]
	bl sub_0800FC68
	b _0800FD20
	.align 2, 0
_0800FD14: .4byte 0x030050A0
_0800FD18: .4byte 0x02022C90
_0800FD1C:
	ldr r0, _0800FD28
	str r0, [r3]
_0800FD20:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800FD28: .4byte 0x0800FC69
	thumb_func_end sub_0800FCCC

	thumb_func_start sub_0800FD2C
sub_0800FD2C: @ 0x0800FD2C
	push {r4, lr}
	ldr r0, _0800FD58
	ldrh r0, [r0]
	cmp r0, #0
	bne _0800FD50
	ldr r4, _0800FD5C
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800FD50
	movs r0, #0xbe
	lsls r0, r0, #7
	bl sub_0800F7F8
	ldr r0, _0800FD60
	str r0, [r4]
_0800FD50:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800FD58: .4byte 0x030031B0
_0800FD5C: .4byte 0x030050A0
_0800FD60: .4byte 0x0800FCCD
	thumb_func_end sub_0800FD2C

	thumb_func_start sub_0800FD64
sub_0800FD64: @ 0x0800FD64
	push {lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r2, _0800FD88
	ldr r0, [r2]
	cmp r0, #0
	bne _0800FD84
	ldr r1, _0800FD8C
	adds r0, r2, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _0800FD90
	str r0, [r2]
	adds r0, r3, #0
	bl DestroyTask
_0800FD84:
	pop {r0}
	bx r0
	.align 2, 0
_0800FD88: .4byte 0x030050A0
_0800FD8C: .4byte 0x00000991
_0800FD90: .4byte 0x0800FD2D
	thumb_func_end sub_0800FD64

	thumb_func_start Rfu_SetCloseLinkCallback
Rfu_SetCloseLinkCallback: @ 0x0800FD94
	push {r4, lr}
	ldr r4, _0800FDB4
	adds r0, r4, #0
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800FDAC
	adds r0, r4, #0
	movs r1, #5
	bl CreateTask
_0800FDAC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800FDB4: .4byte 0x0800FD65
	thumb_func_end Rfu_SetCloseLinkCallback

	thumb_func_start sub_0800FDB8
sub_0800FDB8: @ 0x0800FDB8
	push {r4, r5, lr}
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0800FDE6
	ldr r1, _0800FE50
	ldr r2, _0800FE54
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r4, r0, #0
	cmp r4, #0
	bne _0800FDE6
	adds r5, r1, #0
	adds r5, #0xfe
	ldrh r0, [r5]
	cmp r0, #0x3c
	bls _0800FDE6
	movs r0, #0xcc
	lsls r0, r0, #7
	bl sub_0800F7F8
	strh r4, [r5]
_0800FDE6:
	bl GetLinkPlayerCount
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #0
	cmp r1, r2
	bhs _0800FE12
	ldr r0, _0800FE50
	adds r3, r0, #0
	adds r3, #0xe9
	ldrb r0, [r3]
	cmp r0, #0
	beq _0800FE12
_0800FE00:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, r2
	bhs _0800FE12
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800FE00
_0800FE12:
	ldr r4, _0800FE50
	cmp r1, r2
	bne _0800FE3E
	movs r1, #0
	adds r3, r4, #0
	adds r3, #0xe9
	movs r2, #0
_0800FE20:
	adds r0, r1, r3
	strb r2, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #4
	bls _0800FE20
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r1, #1
	movs r2, #0
	strh r1, [r0]
	str r2, [r4]
_0800FE3E:
	adds r1, r4, #0
	adds r1, #0xfe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800FE50: .4byte 0x030050A0
_0800FE54: .4byte 0x0000069E
	thumb_func_end sub_0800FDB8

	thumb_func_start sub_0800FE58
sub_0800FE58: @ 0x0800FE58
	push {r4, lr}
	ldr r4, _0800FE80
	ldr r1, _0800FE84
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800FE7A
	ldr r0, _0800FE88
	ldrh r0, [r0]
	cmp r0, #0
	bne _0800FE7A
	movs r0, #0xcc
	lsls r0, r0, #7
	bl sub_0800F7F8
	ldr r0, _0800FE8C
	str r0, [r4]
_0800FE7A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800FE80: .4byte 0x030050A0
_0800FE84: .4byte 0x0000069E
_0800FE88: .4byte 0x030031B0
_0800FE8C: .4byte 0x0800FDB9
	thumb_func_end sub_0800FE58

	thumb_func_start sub_0800FE90
sub_0800FE90: @ 0x0800FE90
	push {r4, lr}
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0800FECC
	ldr r4, _0800FEBC
	ldr r1, _0800FEC0
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800FF1E
	ldr r0, _0800FEC4
	ldrh r0, [r0]
	cmp r0, #0
	bne _0800FF1E
	movs r0, #0xcc
	lsls r0, r0, #7
	bl sub_0800F7F8
	ldr r0, _0800FEC8
	b _0800FF1C
	.align 2, 0
_0800FEBC: .4byte 0x030050A0
_0800FEC0: .4byte 0x0000069E
_0800FEC4: .4byte 0x030031B0
_0800FEC8: .4byte 0x0800FDB9
_0800FECC:
	bl GetLinkPlayerCount
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r1, #1
	cmp r1, r2
	bhs _0800FEFA
	ldr r3, _0800FF24
	adds r0, r3, #0
	adds r0, #0xea
	ldrb r0, [r0]
	cmp r0, #0
	beq _0800FEFA
	adds r3, #0xe9
_0800FEE8:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, r2
	bhs _0800FEFA
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800FEE8
_0800FEFA:
	cmp r1, r2
	bne _0800FF1E
	ldr r4, _0800FF24
	ldr r1, _0800FF28
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0800FF1E
	ldr r0, _0800FF2C
	ldrh r0, [r0]
	cmp r0, #0
	bne _0800FF1E
	movs r0, #0xcc
	lsls r0, r0, #7
	bl sub_0800F7F8
	ldr r0, _0800FF30
_0800FF1C:
	str r0, [r4]
_0800FF1E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800FF24: .4byte 0x030050A0
_0800FF28: .4byte 0x0000069E
_0800FF2C: .4byte 0x030031B0
_0800FF30: .4byte 0x0800FE59
	thumb_func_end sub_0800FE90

	thumb_func_start Rfu_SetLinkStandbyCallback
Rfu_SetLinkStandbyCallback: @ 0x0800FF34
	push {lr}
	ldr r1, _0800FF4C
	ldr r2, [r1]
	cmp r2, #0
	bne _0800FF48
	ldr r0, _0800FF50
	str r0, [r1]
	adds r0, r1, #0
	adds r0, #0xfe
	strh r2, [r0]
_0800FF48:
	pop {r0}
	bx r0
	.align 2, 0
_0800FF4C: .4byte 0x030050A0
_0800FF50: .4byte 0x0800FE91
	thumb_func_end Rfu_SetLinkStandbyCallback

	thumb_func_start IsRfuSerialNumberValid
IsRfuSerialNumberValid: @ 0x0800FF54
	push {r4, lr}
	adds r3, r0, #0
	ldr r1, _0800FF70
	ldrh r0, [r1]
	cmp r0, r3
	beq _0800FF82
	ldr r4, _0800FF74
	adds r2, r1, #0
_0800FF64:
	ldrh r0, [r2]
	cmp r0, r4
	bne _0800FF78
	movs r0, #0
	b _0800FF84
	.align 2, 0
_0800FF70: .4byte 0x082C0430
_0800FF74: .4byte 0x0000FFFF
_0800FF78:
	adds r1, #2
	adds r2, #2
	ldrh r0, [r1]
	cmp r0, r3
	bne _0800FF64
_0800FF82:
	movs r0, #1
_0800FF84:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsRfuSerialNumberValid

	thumb_func_start sub_0800FF8C
sub_0800FF8C: @ 0x0800FF8C
	push {lr}
	cmp r0, #0
	beq _0800FFA0
	movs r1, #0x96
	lsls r1, r1, #2
	movs r0, #1
	bl rfu_LMAN_setLinkRecovery
	movs r0, #0
	b _0800FFAC
_0800FFA0:
	movs r0, #0
	movs r1, #0
	bl rfu_LMAN_setLinkRecovery
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0800FFAC:
	pop {r1}
	bx r1
	thumb_func_end sub_0800FF8C

	thumb_func_start sub_0800FFB0
sub_0800FFB0: @ 0x0800FFB0
	push {lr}
	ldr r0, _0800FFC8
	ldr r1, _0800FFCC
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #0
	bl rfu_LMAN_stopManager
	pop {r0}
	bx r0
	.align 2, 0
_0800FFC8: .4byte 0x030050A0
_0800FFCC: .4byte 0x00000991
	thumb_func_end sub_0800FFB0

	thumb_func_start Rfu_GetMultiplayerId
Rfu_GetMultiplayerId: @ 0x0800FFD0
	push {lr}
	ldr r1, _0800FFE4
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	beq _0800FFEC
	ldr r2, _0800FFE8
	adds r0, r1, r2
	ldrb r0, [r0]
	b _0800FFEE
	.align 2, 0
_0800FFE4: .4byte 0x030050A0
_0800FFE8: .4byte 0x00000986
_0800FFEC:
	movs r0, #0
_0800FFEE:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end Rfu_GetMultiplayerId

	thumb_func_start Rfu_GetLinkPlayerCount
Rfu_GetLinkPlayerCount: @ 0x0800FFF4
	ldr r0, _0800FFFC
	ldrb r0, [r0, #0xd]
	bx lr
	.align 2, 0
_0800FFFC: .4byte 0x030050A0
	thumb_func_end Rfu_GetLinkPlayerCount

	thumb_func_start IsLinkRfuTaskFinished
IsLinkRfuTaskFinished: @ 0x08010000
	push {lr}
	ldr r2, _08010014
	adds r0, r2, #0
	adds r0, #0xf1
	ldrb r0, [r0]
	cmp r0, #2
	bne _08010018
	movs r0, #0
	b _08010024
	.align 2, 0
_08010014: .4byte 0x030050A0
_08010018:
	movs r1, #0
	ldr r0, [r2]
	cmp r0, #0
	bne _08010022
	movs r1, #1
_08010022:
	adds r0, r1, #0
_08010024:
	pop {r1}
	bx r1
	thumb_func_end IsLinkRfuTaskFinished

	thumb_func_start sub_08010028
sub_08010028: @ 0x08010028
	push {lr}
	ldr r0, _0801003C
	ldr r0, [r0]
	cmp r0, #0
	beq _08010036
	bl _call_via_r0
_08010036:
	pop {r0}
	bx r0
	.align 2, 0
_0801003C: .4byte 0x030050A0
	thumb_func_end sub_08010028

	thumb_func_start sub_08010040
sub_08010040: @ 0x08010040
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r7, #0
	movs r5, #0
	ldr r6, _080100AC
	ldr r0, _080100B0
	adds r0, r0, r6
	mov r8, r0
_08010052:
	ldr r1, _080100B4
	adds r0, r6, r1
	adds r4, r5, r0
	ldrb r0, [r4]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080100DA
	ldr r1, _080100B8
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, #0x34]
	cmp r0, #0x46
	beq _08010076
	cmp r0, #0x48
	bne _080100C0
_08010076:
	ldr r2, _080100BC
	adds r0, r6, r2
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #8
	bne _080100DA
	movs r0, #9
	strb r0, [r4]
	movs r0, #0xa
	strb r0, [r1]
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	movs r0, #8
	bl rfu_clearSlot
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r5
	lsrs r0, r0, #0x18
	movs r1, #8
	adds r2, r4, #0
	movs r3, #1
	bl rfu_NI_setSendData
	movs r7, #1
	b _080100DA
	.align 2, 0
_080100AC: .4byte 0x030050A0
_080100B0: .4byte 0x000008F6
_080100B4: .4byte 0x00000989
_080100B8: .4byte 0x03007620
_080100BC: .4byte 0x0000098D
_080100C0:
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0, #0x34]
	cmp r0, #0x47
	bne _080100DA
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x18
	movs r0, #8
	bl rfu_clearSlot
_080100DA:
	adds r5, #1
	cmp r5, #3
	ble _08010052
	adds r0, r7, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_08010040

	thumb_func_start sub_080100EC
sub_080100EC: @ 0x080100EC
	push {r4, r5, r6, lr}
	movs r3, #0
	movs r1, #0
	ldr r5, _08010138
	movs r6, #1
	movs r4, #0
_080100F8:
	adds r2, r1, r5
	ldrb r0, [r2]
	cmp r0, #0xb
	bne _0801010C
	adds r0, r6, #0
	lsls r0, r1
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
	strb r4, [r2]
_0801010C:
	adds r1, #1
	cmp r1, #3
	ble _080100F8
	cmp r3, #0
	beq _08010120
	adds r0, r3, #0
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_08010120:
	movs r1, #0
	ldr r2, _08010138
_08010124:
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, #0xa
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801013C
	movs r0, #1
	b _08010144
	.align 2, 0
_08010138: .4byte 0x03005A2D
_0801013C:
	adds r1, #1
	cmp r1, #3
	ble _08010124
	movs r0, #0
_08010144:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080100EC

	thumb_func_start sub_0801014C
sub_0801014C: @ 0x0801014C
	push {lr}
	adds r2, r0, #0
	adds r0, r1, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r2, #0
	bl sub_080117D0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xff
	beq _08010180
	ldr r0, _08010178
	ldr r2, _0801017C
	adds r0, r0, r2
	adds r0, r1, r0
	ldrb r0, [r0]
	cmp r0, #9
	beq _08010180
	movs r0, #0
	b _08010182
	.align 2, 0
_08010178: .4byte 0x030050A0
_0801017C: .4byte 0x00000989
_08010180:
	movs r0, #1
_08010182:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801014C

	thumb_func_start sub_08010188
sub_08010188: @ 0x08010188
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, r2, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080117D0
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r5, _080101CC
	ldr r0, _080101D0
	adds r5, r5, r0
	adds r5, r4, r5
	strb r6, [r5]
	movs r0, #4
	adds r1, r4, #0
	bl rfu_clearSlot
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r4
	lsrs r0, r0, #0x18
	movs r1, #8
	adds r2, r5, #0
	movs r3, #1
	bl rfu_NI_setSendData
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080101CC: .4byte 0x030050A0
_080101D0: .4byte 0x00000989
	thumb_func_end sub_08010188

	thumb_func_start sub_080101D4
sub_080101D4: @ 0x080101D4
	push {r4, r5, lr}
	ldr r4, _08010208
	ldr r0, _0801020C
	adds r5, r4, r0
	movs r0, #8
	strb r0, [r5]
	ldr r0, _08010210
	adds r4, r4, r0
	ldrb r1, [r4]
	movs r0, #4
	bl rfu_clearSlot
	ldrb r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r1
	lsrs r0, r0, #0x18
	movs r1, #8
	adds r2, r5, #0
	movs r3, #1
	bl rfu_NI_setSendData
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010208: .4byte 0x030050A0
_0801020C: .4byte 0x0000093D
_08010210: .4byte 0x000008F6
	thumb_func_end sub_080101D4

	thumb_func_start sub_08010214
sub_08010214: @ 0x08010214
	push {lr}
	adds r2, r0, #0
	adds r0, r1, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r2, #0
	bl sub_080117D0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08010230
	movs r0, #2
	b _0801024A
_08010230:
	ldr r1, _08010244
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0
	beq _08010248
	movs r0, #0
	b _0801024A
	.align 2, 0
_08010244: .4byte 0x03007620
_08010248:
	movs r0, #1
_0801024A:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08010214

	thumb_func_start sub_08010250
sub_08010250: @ 0x08010250
	push {r4, r5, lr}
	bl sub_08010040
	movs r4, #0
	ldr r0, _08010294
	ldr r1, _08010298
	adds r5, r0, r1
_0801025E:
	ldr r1, _0801029C
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrh r0, [r0]
	subs r0, #0x26
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _08010288
	adds r1, r4, r5
	ldrb r0, [r1]
	cmp r0, #0xa
	bne _0801027E
	movs r0, #0xb
	strb r0, [r1]
_0801027E:
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	movs r0, #4
	bl rfu_clearSlot
_08010288:
	adds r4, #1
	cmp r4, #3
	ble _0801025E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010294: .4byte 0x030050A0
_08010298: .4byte 0x0000098D
_0801029C: .4byte 0x03007620
	thumb_func_end sub_08010250

	thumb_func_start sub_080102A0
sub_080102A0: @ 0x080102A0
	push {r4, r5, lr}
	movs r4, #0
	ldr r1, _08010318
	ldr r2, _0801031C
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #8
	bne _080102DA
	ldr r2, _08010320
	ldr r0, _08010324
	adds r1, r1, r0
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0x26
	beq _080102D2
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, #0x27
	bne _080102DA
_080102D2:
	ldrb r1, [r1]
	movs r0, #4
	bl rfu_clearSlot
_080102DA:
	ldr r2, _08010320
	ldr r5, _08010318
	ldr r0, _08010324
	adds r1, r5, r0
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r0, [r0, #0x34]
	cmp r0, #0x46
	beq _080102FE
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r0, [r0, #0x34]
	cmp r0, #0x48
	bne _0801032C
_080102FE:
	ldrb r1, [r1]
	movs r0, #8
	bl rfu_clearSlot
	ldr r2, _08010328
	adds r4, r5, r2
	ldrb r0, [r4]
	movs r1, #0
	bl sub_08011554
	ldrb r4, [r4]
	b _08010344
	.align 2, 0
_08010318: .4byte 0x030050A0
_0801031C: .4byte 0x0000093D
_08010320: .4byte 0x03007620
_08010324: .4byte 0x000008F6
_08010328: .4byte 0x0000093E
_0801032C:
	ldrb r0, [r1]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r0, [r0, #0x34]
	cmp r0, #0x47
	bne _08010344
	ldrb r1, [r1]
	movs r0, #8
	bl rfu_clearSlot
	movs r4, #6
_08010344:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_080102A0

	thumb_func_start sub_0801034C
sub_0801034C: @ 0x0801034C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r5, _0801039C
	adds r0, r5, #0
	adds r0, #0xf1
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08010374
	movs r0, #0x9a
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	bl DestroyTask
_08010374:
	ldr r2, _080103A0
	lsls r1, r6, #2
	adds r0, r1, r6
	lsls r0, r0, #3
	adds r4, r0, r2
	movs r2, #8
	ldrsh r0, [r4, r2]
	adds r7, r1, #0
	cmp r0, #3
	beq _0801041C
	cmp r0, #3
	bgt _080103A4
	cmp r0, #1
	beq _080103CC
	cmp r0, #1
	bgt _08010418
	cmp r0, #0
	beq _080103B6
	b _080104D4
	.align 2, 0
_0801039C: .4byte 0x030050A0
_080103A0: .4byte 0x03005B60
_080103A4:
	cmp r0, #5
	beq _08010450
	cmp r0, #5
	blt _0801043E
	cmp r0, #6
	beq _08010484
	cmp r0, #0x65
	beq _08010404
	b _080104D4
_080103B6:
	bl sub_0800F744
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080103C2
	b _080104D4
_080103C2:
	bl ResetBlockReceivedFlags
	bl LocalLinkPlayerToBlock
	b _08010448
_080103CC:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bne _0801040C
	ldr r0, _080103E4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080103E8
	movs r0, #0xf0
	lsls r0, r0, #7
	bl sub_0800F7F8
	b _080103F0
	.align 2, 0
_080103E4: .4byte 0x030031C4
_080103E8:
	movs r0, #0xee
	lsls r0, r0, #7
	bl sub_0800F7F8
_080103F0:
	ldr r0, _08010400
	adds r1, r7, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r0, #0x65
	strh r0, [r1, #8]
	b _080104D4
	.align 2, 0
_08010400: .4byte 0x03005B60
_08010404:
	ldr r0, _08010414
	ldrh r0, [r0]
	cmp r0, #0
	bne _080104D4
_0801040C:
	movs r0, #2
	strh r0, [r4, #8]
	b _080104D4
	.align 2, 0
_08010414: .4byte 0x030031B0
_08010418:
	ldrb r0, [r5, #0xd]
	b _08010444
_0801041C:
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	bne _08010448
	bl sub_0800F744
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080104D4
	adds r1, r5, #0
	adds r1, #0x5a
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa1
	lsls r0, r0, #8
	bl sub_0800F7F8
	b _08010448
_0801043E:
	bl sub_0800F76C
	lsls r0, r0, #0x18
_08010444:
	cmp r0, #0
	beq _080104D4
_08010448:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _080104D4
_08010450:
	movs r4, #0
	ldrb r0, [r5, #0xd]
	cmp r4, r0
	bge _0801046E
_08010458:
	adds r0, r4, #0
	bl LinkPlayerFromBlock
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl Rfu_ResetBlockReceivedFlag
	adds r4, #1
	ldrb r2, [r5, #0xd]
	cmp r4, r2
	blt _08010458
_0801046E:
	ldr r0, _08010480
	adds r1, r7, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _080104D4
	.align 2, 0
_08010480: .4byte 0x03005B60
_08010484:
	adds r0, r6, #0
	bl DestroyTask
	ldr r1, _080104DC
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x9a
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x96
	lsls r1, r1, #2
	movs r0, #1
	bl rfu_LMAN_setLinkRecovery
	ldr r2, _080104E0
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080104D4
	movs r4, #0
	adds r2, r1, #0
	movs r3, #1
	ldr r0, _080104E4
	adds r5, r5, r0
_080104B8:
	ldrb r0, [r2]
	asrs r0, r4
	ands r0, r3
	cmp r0, #0
	beq _080104CE
	adds r0, r3, #0
	lsls r0, r4
	strb r0, [r5]
	ldrb r1, [r2]
	eors r0, r1
	strb r0, [r2]
_080104CE:
	adds r4, #1
	cmp r4, #3
	ble _080104B8
_080104D4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080104DC: .4byte 0x030031C4
_080104E0: .4byte 0x0000099E
_080104E4: .4byte 0x0000099D
	thumb_func_end sub_0801034C

	thumb_func_start sub_080104E8
sub_080104E8: @ 0x080104E8
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0
	movs r5, #1
	ldr r4, _08010510
	movs r3, #0
_080104F6:
	adds r0, r2, #0
	asrs r0, r1
	ands r0, r5
	cmp r0, #0
	beq _08010504
	adds r0, r1, r4
	strb r3, [r0]
_08010504:
	adds r1, #1
	cmp r1, #3
	ble _080104F6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010510: .4byte 0x03005A36
	thumb_func_end sub_080104E8

	thumb_func_start sub_08010514
sub_08010514: @ 0x08010514
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	ldr r1, _0801055C
	ldrb r0, [r3, #0xf]
	strb r0, [r1, #0xd]
	movs r2, #0
	ldr r0, _08010560
	adds r5, r1, r0
	adds r4, r3, #0
	adds r4, #0x10
_08010528:
	adds r0, r2, r5
	adds r1, r4, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #3
	ble _08010528
	ldr r4, _08010564
	movs r2, #4
_0801053A:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r1, #0x14
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldm r1!, {r5, r6, r7}
	stm r0!, {r5, r6, r7}
	ldr r1, [r1]
	str r1, [r0]
	adds r3, #0x1c
	adds r4, #0x1c
	subs r2, #1
	cmp r2, #0
	bge _0801053A
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801055C: .4byte 0x030050A0
_08010560: .4byte 0x00000996
_08010564: .4byte 0x020226A0
	thumb_func_end sub_08010514

	thumb_func_start sub_08010568
sub_08010568: @ 0x08010568
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _0801059C
	adds r1, r4, #0
	bl strcmp
	adds r5, r0, #0
	cmp r5, #0
	bne _08010594
	adds r0, r4, #0
	bl sub_08010514
	mov r0, sp
	strh r5, [r0]
	ldr r2, _080105A0
	adds r1, r4, #0
	bl CpuSet
	movs r0, #0
	bl ResetBlockReceivedFlag
_08010594:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801059C: .4byte 0x082C0564
_080105A0: .4byte 0x0100007E
	thumb_func_end sub_08010568

	thumb_func_start sub_080105A4
sub_080105A4: @ 0x080105A4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r3, _08010604
	ldr r2, _08010608
	ldr r1, _0801060C
	adds r0, r3, r1
	ldrb r1, [r0]
	adds r1, r1, r2
	ldr r2, _08010610
	adds r0, r3, r2
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r4, [r0]
	adds r0, r3, #0
	adds r0, #0xf1
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080105E2
	movs r0, #0x9a
	lsls r0, r0, #4
	adds r1, r3, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	bl DestroyTask
_080105E2:
	ldr r0, _08010614
	lsls r2, r6, #2
	adds r1, r2, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r3, #8
	ldrsh r1, [r1, r3]
	adds r3, r0, #0
	adds r7, r2, #0
	cmp r1, #5
	bls _080105FA
	b _080107E2
_080105FA:
	lsls r0, r1, #2
	ldr r1, _08010618
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08010604: .4byte 0x030050A0
_08010608: .4byte 0x082C03DC
_0801060C: .4byte 0x000009A1
_08010610: .4byte 0x00000996
_08010614: .4byte 0x03005B60
_08010618: .4byte 0x0801061C
_0801061C: @ jump table
	.4byte _08010634 @ case 0
	.4byte _08010654 @ case 1
	.4byte _0801066C @ case 2
	.4byte _080106B0 @ case 3
	.4byte _080106FA @ case 4
	.4byte _08010784 @ case 5
_08010634:
	ldr r0, _08010650
	ldrh r0, [r0]
	cmp r0, #0
	beq _0801063E
	b _080107E2
_0801063E:
	adds r0, r4, #0
	bl ResetBlockReceivedFlag
	movs r0, #0xf0
	lsls r0, r0, #7
	bl sub_0800F7F8
	b _0801073A
	.align 2, 0
_08010650: .4byte 0x030031B0
_08010654:
	ldr r0, _08010668
	ldrh r0, [r0]
	cmp r0, #0
	beq _0801065E
	b _080107E2
_0801065E:
	adds r1, r7, r6
	lsls r1, r1, #3
	adds r1, r1, r3
	b _08010742
	.align 2, 0
_08010668: .4byte 0x030031B0
_0801066C:
	bl GetBlockReceivedStatus
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08010680
	b _080107E2
_08010680:
	adds r0, r4, #0
	bl ResetBlockReceivedFlag
	lsls r1, r4, #8
	ldr r0, _080106A8
	adds r1, r1, r0
	ldr r2, _080106AC
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r1, #0x10
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldm r1!, {r2, r3, r4}
	stm r0!, {r2, r3, r4}
	ldr r1, [r1]
	str r1, [r0]
	b _0801073A
	.align 2, 0
_080106A8: .4byte 0x0202207C
_080106AC: .4byte 0x020226A0
_080106B0:
	ldr r5, _0801074C
	adds r1, r5, #0
	ldr r0, _08010750
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldrh r2, [r0]
	strh r2, [r1]
	ldrb r0, [r0, #2]
	strb r0, [r1, #2]
	ldr r1, _08010754
	ldrb r0, [r1, #0xd]
	strb r0, [r5, #0xf]
	movs r2, #0
	adds r4, r5, #0
	adds r4, #0x10
	ldr r0, _08010758
	adds r3, r1, r0
_080106D2:
	adds r0, r4, r2
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #3
	ble _080106D2
	ldr r1, _0801075C
	adds r0, r5, #0
	adds r0, #0x14
	movs r2, #0x8c
	bl memcpy
	ldr r0, _08010760
	adds r1, r7, r6
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
_080106FA:
	ldr r5, _0801074C
	ldr r1, _08010754
	ldrb r0, [r1, #0xd]
	strb r0, [r5, #0xf]
	movs r2, #0
	ldr r3, _0801075C
	mov ip, r3
	adds r4, r5, #0
	adds r4, #0x10
	ldr r0, _08010758
	adds r3, r1, r0
_08010710:
	adds r0, r4, r2
	adds r1, r2, r3
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #3
	ble _08010710
	adds r0, r5, #0
	adds r0, #0x14
	mov r1, ip
	movs r2, #0x8c
	bl memcpy
	ldr r1, _0801074C
	movs r0, #0
	movs r2, #0xa0
	bl SendBlock
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080107E2
_0801073A:
	ldr r0, _08010760
	adds r1, r7, r6
	lsls r1, r1, #3
	adds r1, r1, r0
_08010742:
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _080107E2
	.align 2, 0
_0801074C: .4byte 0x0202257C
_08010750: .4byte 0x082C0564
_08010754: .4byte 0x030050A0
_08010758: .4byte 0x00000996
_0801075C: .4byte 0x020226A0
_08010760: .4byte 0x03005B60
_08010764:
	adds r0, r3, #0
	lsls r0, r2
	ldr r2, _08010780
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r4]
	eors r0, r1
	strb r0, [r4]
	movs r4, #0x9a
	lsls r4, r4, #4
	adds r0, r5, r4
	strb r3, [r0]
	b _080107DC
	.align 2, 0
_08010780: .4byte 0x0000099D
_08010784:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080107E2
	bl GetBlockReceivedStatus
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _080107E2
	mov r0, sp
	movs r4, #0
	strh r4, [r0]
	ldr r1, _080107EC
	ldr r2, _080107F0
	bl CpuSet
	movs r0, #0
	bl ResetBlockReceivedFlag
	ldr r1, _080107F4
	movs r2, #0x9a
	lsls r2, r2, #4
	adds r0, r1, r2
	strb r4, [r0]
	ldr r4, _080107F8
	adds r3, r1, r4
	ldrb r0, [r3]
	cmp r0, #0
	beq _080107DC
	movs r2, #0
	adds r5, r1, #0
	adds r4, r3, #0
	ldrb r1, [r4]
	movs r3, #1
_080107CC:
	adds r0, r1, #0
	asrs r0, r2
	ands r0, r3
	cmp r0, #0
	bne _08010764
	adds r2, #1
	cmp r2, #3
	ble _080107CC
_080107DC:
	adds r0, r6, #0
	bl DestroyTask
_080107E2:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080107EC: .4byte 0x0202207C
_080107F0: .4byte 0x0100007E
_080107F4: .4byte 0x030050A0
_080107F8: .4byte 0x0000099E
	thumb_func_end sub_080105A4

	thumb_func_start sub_080107FC
sub_080107FC: @ 0x080107FC
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r6, _08010838
	adds r0, r6, #0
	adds r0, #0xf1
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0801081A
	adds r0, r5, #0
	bl DestroyTask
_0801081A:
	ldr r1, _0801083C
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq _08010860
	cmp r0, #1
	bgt _08010840
	cmp r0, #0
	beq _08010846
	b _08010896
	.align 2, 0
_08010838: .4byte 0x030050A0
_0801083C: .4byte 0x03005B60
_08010840:
	cmp r0, #2
	beq _08010872
	b _08010896
_08010846:
	ldrb r0, [r6, #0xd]
	cmp r0, #0
	beq _08010896
	bl LocalLinkPlayerToBlock
	ldr r1, _0801085C
	movs r0, #0
	movs r2, #0x3c
	bl SendBlock
	b _0801086A
	.align 2, 0
_0801085C: .4byte 0x0202257C
_08010860:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08010896
_0801086A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	b _08010896
_08010872:
	bl GetBlockReceivedStatus
	movs r4, #1
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _08010896
	ldr r0, _0801089C
	bl sub_08010514
	movs r0, #0
	bl ResetBlockReceivedFlag
	ldr r0, _080108A0
	strb r4, [r0]
	adds r0, r5, #0
	bl DestroyTask
_08010896:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801089C: .4byte 0x0202207C
_080108A0: .4byte 0x030031C4
	thumb_func_end sub_080107FC

	thumb_func_start sub_080108A4
sub_080108A4: @ 0x080108A4
	push {r4, r5, r6, r7, lr}
	ldr r0, _0801092C
	adds r1, r0, #0
	adds r1, #0xee
	ldrb r1, [r1]
	adds r3, r0, #0
	cmp r1, #1
	bne _0801094C
	ldr r2, _08010930
	ldrb r0, [r2, #2]
	cmp r0, #0
	bne _0801094C
	ldr r0, _08010934
	ldr r1, [r0, #4]
	ldr r0, _08010938
	cmp r1, r0
	beq _080108CE
	ldr r0, [r2, #0x3c]
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _080108D4
_080108CE:
	ldr r1, _0801093C
	movs r0, #2
	strb r0, [r1]
_080108D4:
	ldr r4, _08010940
	adds r0, r4, #0
	bl SetMainCallback2
	ldr r0, _08010934
	str r4, [r0, #8]
	ldr r5, _0801092C
	ldrh r0, [r5, #0xa]
	lsls r4, r0, #0x10
	ldrh r0, [r5, #0x10]
	lsls r0, r0, #8
	orrs r4, r0
	ldrh r0, [r5, #0x12]
	orrs r4, r0
	ldr r1, _08010944
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r7, r0, #0
	ldr r1, _08010948
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r6, r0, #0
	bl RfuGetStatus
	movs r3, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _08010910
	movs r3, #1
_08010910:
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl sub_0800A9F4
	adds r0, r5, #0
	adds r0, #0xee
	ldrb r1, [r0]
	movs r1, #2
	strb r1, [r0]
	bl CloseLink
	b _0801097E
	.align 2, 0
_0801092C: .4byte 0x030050A0
_08010930: .4byte 0x030041E0
_08010934: .4byte 0x03002360
_08010938: .4byte 0x08017ED1
_0801093C: .4byte 0x0300319C
_08010940: .4byte 0x0800AA0D
_08010944: .4byte 0x0000069E
_08010948: .4byte 0x000008D2
_0801094C:
	ldr r1, _08010984
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08010960
	ldr r1, _08010988
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0801097E
_08010960:
	ldr r0, _0801098C
	ldrb r0, [r0, #2]
	cmp r0, #0
	beq _0801096C
	bl rfu_LMAN_requestChangeAgbClockMaster
_0801096C:
	movs r4, #0xe0
	lsls r4, r4, #7
	movs r0, #1
	adds r1, r4, #0
	bl sub_08011554
	adds r0, r4, #0
	bl RfuSetErrorParams
_0801097E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010984: .4byte 0x000008D3
_08010988: .4byte 0x0000069F
_0801098C: .4byte 0x030041E0
	thumb_func_end sub_080108A4

	thumb_func_start rfu_REQ_recvData_then_sendData
rfu_REQ_recvData_then_sendData: @ 0x08010990
	push {lr}
	ldr r0, _080109AC
	ldrb r0, [r0, #6]
	cmp r0, #1
	bne _080109A8
	bl rfu_REQ_recvData
	bl rfu_waitREQComplete
	movs r0, #0
	bl rfu_LMAN_REQ_sendData
_080109A8:
	pop {r0}
	bx r0
	.align 2, 0
_080109AC: .4byte 0x030041E0
	thumb_func_end rfu_REQ_recvData_then_sendData

	thumb_func_start RfuMain1
RfuMain1: @ 0x080109B0
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _080109E4
	ldr r1, _080109E8
	adds r0, r4, r1
	strb r5, [r0]
	bl Random2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl rfu_LMAN_manager_entity
	adds r0, r4, #0
	adds r0, #0xef
	ldrb r0, [r0]
	cmp r0, #0
	bne _08010A04
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	beq _080109F2
	cmp r0, #1
	bgt _080109EC
	cmp r0, #0
	beq _080109F8
	b _08010A04
	.align 2, 0
_080109E4: .4byte 0x030050A0
_080109E8: .4byte 0x00000985
_080109EC:
	cmp r0, #2
	beq _08010A00
	b _08010A04
_080109F2:
	bl RfuMain1_Parent
	b _08010A04
_080109F8:
	bl RfuMain1_Child
	adds r5, r0, #0
	b _08010A04
_08010A00:
	bl rfu_REQ_recvData_then_sendData
_08010A04:
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end RfuMain1

	thumb_func_start RfuMain2
RfuMain2: @ 0x08010A0C
	push {r4, lr}
	movs r4, #0
	ldr r1, _08010A34
	adds r0, r1, #0
	adds r0, #0xef
	ldrb r0, [r0]
	cmp r0, #0
	bne _08010A2C
	ldrb r0, [r1, #0xc]
	cmp r0, #1
	bne _08010A28
	bl RfuMain2_Parent
	adds r4, r0, #0
_08010A28:
	bl sub_080108A4
_08010A2C:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08010A34: .4byte 0x030050A0
	thumb_func_end RfuMain2

	thumb_func_start sub_08010A38
sub_08010A38: @ 0x08010A38
	push {lr}
	ldr r0, _08010A48
	ldr r1, _08010A4C
	ldr r1, [r1]
	bl StringCopy
	pop {r0}
	bx r0
	.align 2, 0
_08010A48: .4byte 0x020227DA
_08010A4C: .4byte 0x03005AF0
	thumb_func_end sub_08010A38

	thumb_func_start sub_08010A50
sub_08010A50: @ 0x08010A50
	push {r4, lr}
	ldr r4, _08010A70
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xd
	bl memset
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InitHostRfuGameData
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010A70: .4byte 0x020227CC
	thumb_func_end sub_08010A50

	thumb_func_start sub_08010A74
sub_08010A74: @ 0x08010A74
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _08010A8C
	adds r1, r4, #0
	bl InitHostRfuGameData
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010A8C: .4byte 0x020227CC
	thumb_func_end sub_08010A74

	thumb_func_start sub_08010A90
sub_08010A90: @ 0x08010A90
	push {r4, r5, lr}
	ldr r5, _08010AB8
	movs r4, #1
	ands r0, r4
	lsls r0, r0, #4
	ldrb r3, [r5]
	movs r2, #0x11
	rsbs r2, r2, #0
	ands r2, r3
	orrs r2, r0
	ands r1, r4
	lsls r1, r1, #5
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r2, r0
	orrs r2, r1
	strb r2, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010AB8: .4byte 0x020227CC
	thumb_func_end sub_08010A90

	thumb_func_start sub_08010ABC
sub_08010ABC: @ 0x08010ABC
	push {r4, r5, lr}
	ldr r5, _08010AF0
	lsls r0, r0, #2
	ldrb r4, [r5, #9]
	movs r3, #3
	ands r3, r4
	orrs r3, r0
	strb r3, [r5, #9]
	ldr r3, _08010AF4
	adds r0, r3, #0
	ands r1, r0
	ldrh r3, [r5, #8]
	ldr r0, _08010AF8
	ands r0, r3
	orrs r0, r1
	strh r0, [r5, #8]
	lsls r2, r2, #1
	ldrb r1, [r5, #0xb]
	movs r0, #1
	ands r0, r1
	orrs r0, r2
	strb r0, [r5, #0xb]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08010AF0: .4byte 0x020227CC
_08010AF4: .4byte 0x000003FF
_08010AF8: .4byte 0xFFFFFC00
	thumb_func_end sub_08010ABC

	thumb_func_start sub_08010AFC
sub_08010AFC: @ 0x08010AFC
	push {r4, lr}
	movs r4, #0x80
	ldr r3, _08010B28
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r0, r1, r3
	ldrb r2, [r0, #0x13]
	lsls r2, r2, #3
	orrs r2, r4
	adds r3, #4
	adds r1, r1, r3
	ldr r0, [r1]
	movs r1, #7
	ands r0, r1
	orrs r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08010B28: .4byte 0x020226A0
	thumb_func_end sub_08010AFC

	thumb_func_start sub_08010B2C
sub_08010B2C: @ 0x08010B2C
	push {r4, r5, lr}
	ldr r5, _08010B34
	movs r4, #1
	b _08010B44
	.align 2, 0
_08010B34: .4byte 0x020227CC
_08010B38:
	adds r0, r4, #0
	bl sub_08010AFC
	adds r1, r5, r4
	strb r0, [r1, #3]
	adds r4, #1
_08010B44:
	bl GetLinkPlayerCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	blt _08010B38
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08010B2C

	thumb_func_start sub_08010B58
sub_08010B58: @ 0x08010B58
	push {lr}
	lsls r0, r0, #0x18
	ldr r2, _08010B78
	lsrs r0, r0, #0x11
	ldrb r3, [r2, #0xa]
	movs r1, #0x7f
	ands r1, r3
	orrs r1, r0
	strb r1, [r2, #0xa]
	ldr r3, _08010B7C
	movs r0, #0
	movs r1, #2
	bl rfu_REQ_configGameData
	pop {r0}
	bx r0
	.align 2, 0
_08010B78: .4byte 0x020227CC
_08010B7C: .4byte 0x020227DA
	thumb_func_end sub_08010B58

	thumb_func_start sub_08010B80
sub_08010B80: @ 0x08010B80
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08010B8E
	bl sub_08010A74
_08010B8E:
	ldr r2, _08010BA0
	ldr r3, _08010BA4
	movs r0, #0
	movs r1, #2
	bl rfu_REQ_configGameData
	pop {r0}
	bx r0
	.align 2, 0
_08010BA0: .4byte 0x020227CC
_08010BA4: .4byte 0x020227DA
	thumb_func_end sub_08010B80

	thumb_func_start sub_08010BA8
sub_08010BA8: @ 0x08010BA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	bl sub_0800F29C
	ldrb r1, [r0, #0xa]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x45
	bne _08010C3C
	movs r5, #0
	movs r7, #0
	ldr r3, _08010C4C
	ldr r1, _08010C50
	adds r0, r3, r1
	ldr r2, _08010C54
	adds r1, r3, r2
	ldrb r2, [r0]
	ldrb r0, [r1]
	adds r1, r0, #0
	eors r1, r2
	mov r8, r1
	movs r4, #0
	movs r6, #1
	ldr r2, _08010C58
	mov ip, r2
	ldr r0, _08010C5C
	adds r0, r0, r3
	mov sl, r0
	mov r3, ip
	adds r3, #4
_08010BEC:
	mov r0, r8
	asrs r0, r4
	ands r0, r6
	cmp r0, #0
	beq _08010C2C
	mov r1, sl
	adds r0, r4, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	mov r2, ip
	adds r1, r0, r2
	ldrb r1, [r1, #0x13]
	adds r2, r6, #0
	ands r2, r1
	lsls r2, r2, #3
	adds r0, r0, r3
	ldr r1, [r0]
	movs r0, #7
	ands r1, r0
	movs r0, #0x80
	orrs r1, r0
	orrs r2, r1
	lsls r0, r5, #3
	lsls r2, r0
	orrs r7, r2
	adds r5, #1
	mov r0, sb
	subs r0, #1
	cmp r5, r0
	beq _08010C32
_08010C2C:
	adds r4, #1
	cmp r4, #3
	ble _08010BEC
_08010C32:
	movs r0, #0x45
	adds r1, r7, #0
	movs r2, #0
	bl sub_08010B80
_08010C3C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010C4C: .4byte 0x030050A0
_08010C50: .4byte 0x0000099A
_08010C54: .4byte 0x0000099B
_08010C58: .4byte 0x020226A0
_08010C5C: .4byte 0x00000996
	thumb_func_end sub_08010BA8

	thumb_func_start RfuSetErrorParams
RfuSetErrorParams: @ 0x08010C60
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _08010C88
	adds r3, r2, #0
	adds r3, #0xee
	ldrb r0, [r3]
	cmp r0, #0
	bne _08010C82
	ldr r1, _08010C8C
	ldrh r0, [r1, #0x14]
	strh r0, [r2, #0x10]
	ldrh r0, [r1, #0x16]
	strh r0, [r2, #0x12]
	strh r4, [r2, #0xa]
	ldrb r0, [r3]
	movs r0, #1
	strb r0, [r3]
_08010C82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08010C88: .4byte 0x030050A0
_08010C8C: .4byte 0x030041E0
	thumb_func_end RfuSetErrorParams

	thumb_func_start sub_08010C90
sub_08010C90: @ 0x08010C90
	ldr r0, _08010C9C
	adds r0, #0xee
	ldrb r1, [r0]
	movs r1, #0
	strb r1, [r0]
	bx lr
	.align 2, 0
_08010C9C: .4byte 0x030050A0
	thumb_func_end sub_08010C90

	thumb_func_start sub_08010CA0
sub_08010CA0: @ 0x08010CA0
	push {lr}
	adds r2, r0, #0
	cmp r2, #0
	bne _08010CB8
	ldr r0, _08010CB4
	adds r0, #0xee
	ldrb r1, [r0]
	strb r2, [r0]
	b _08010CC2
	.align 2, 0
_08010CB4: .4byte 0x030050A0
_08010CB8:
	ldr r0, _08010CC8
	adds r0, #0xee
	ldrb r1, [r0]
	movs r1, #4
	strb r1, [r0]
_08010CC2:
	pop {r0}
	bx r0
	.align 2, 0
_08010CC8: .4byte 0x030050A0
	thumb_func_end sub_08010CA0

	thumb_func_start sub_08010CCC
sub_08010CCC: @ 0x08010CCC
	push {lr}
	ldr r0, _08010CE4
	ldrb r0, [r0]
	movs r1, #1
	bl sub_08011980
	ldr r1, _08010CE8
	movs r0, #0
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08010CE4: .4byte 0x030041E0
_08010CE8: .4byte 0x030050A0
	thumb_func_end sub_08010CCC

	thumb_func_start sub_08010CEC
sub_08010CEC: @ 0x08010CEC
	ldr r1, _08010CF4
	ldr r0, _08010CF8
	str r0, [r1]
	bx lr
	.align 2, 0
_08010CF4: .4byte 0x030050A0
_08010CF8: .4byte 0x08010CCD
	thumb_func_end sub_08010CEC

	thumb_func_start sub_08010CFC
sub_08010CFC: @ 0x08010CFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r6, #0
	cmp r4, #0x32
	bne _08010D12
	b _08010E50
_08010D12:
	cmp r4, #0x32
	bgt _08010D42
	cmp r4, #0x13
	bgt _08010D30
	cmp r4, #0x12
	blt _08010D20
	b _08010EDE
_08010D20:
	cmp r4, #0x10
	bne _08010D26
	b _08010EDE
_08010D26:
	cmp r4, #0x10
	bgt _08010D7C
	cmp r4, #0
	beq _08010D6E
	b _08010EDE
_08010D30:
	cmp r4, #0x30
	bne _08010D36
	b _08010E5C
_08010D36:
	cmp r4, #0x30
	ble _08010D3C
	b _08010E44
_08010D3C:
	cmp r4, #0x14
	beq _08010E18
	b _08010EDE
_08010D42:
	cmp r4, #0x44
	bgt _08010D54
	cmp r4, #0x42
	blt _08010D4C
	b _08010EDE
_08010D4C:
	cmp r4, #0x33
	bne _08010D52
	b _08010E5C
_08010D52:
	b _08010EDE
_08010D54:
	cmp r4, #0xf3
	bne _08010D5A
	b _08010EAA
_08010D5A:
	cmp r4, #0xf3
	bgt _08010D66
	cmp r4, #0xf0
	bge _08010D64
	b _08010EDE
_08010D64:
	b _08010EC4
_08010D66:
	cmp r4, #0xff
	bne _08010D6C
	b _08010EC4
_08010D6C:
	b _08010EDE
_08010D6E:
	ldr r1, _08010D78
	movs r0, #2
	strh r0, [r1, #4]
	b _08010EDE
	.align 2, 0
_08010D78: .4byte 0x030050A0
_08010D7C:
	ldr r0, _08010DE0
	ldrh r0, [r0, #0x14]
	bl sub_080110DC
	movs r5, #0
	movs r0, #1
	mov r8, r0
	ldr r1, _08010DE4
	mov sb, r1
	ldr r3, _08010DE8
	add r3, sb
	mov sl, r3
	movs r7, #0x7f
_08010D96:
	ldr r0, _08010DE0
	ldrh r0, [r0, #0x14]
	asrs r0, r5
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08010DFE
	ldr r0, _08010DEC
	lsls r1, r5, #5
	adds r1, #0x14
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0, #0x10]
	adds r4, r7, #0
	ands r4, r0
	bl sub_0800F29C
	ldrb r1, [r0, #0xa]
	adds r0, r7, #0
	ands r0, r1
	cmp r4, r0
	bne _08010DF4
	ldr r0, _08010DF0
	add r0, sb
	adds r0, r5, r0
	movs r1, #0
	strb r1, [r0]
	mov r3, sl
	adds r2, r5, r3
	strb r1, [r2]
	movs r0, #0x20
	adds r1, r5, #0
	movs r3, #1
	bl rfu_setRecvBuffer
	b _08010DFE
	.align 2, 0
_08010DE0: .4byte 0x030041E0
_08010DE4: .4byte 0x030050A0
_08010DE8: .4byte 0x0000098D
_08010DEC: .4byte 0x03007630
_08010DF0: .4byte 0x00000989
_08010DF4:
	mov r0, r8
	lsls r0, r5
	orrs r6, r0
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
_08010DFE:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _08010D96
	cmp r6, #0
	beq _08010EDE
	adds r0, r6, #0
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	b _08010EDE
_08010E18:
	ldr r4, _08010E38
	ldr r1, _08010E3C
	adds r0, r4, r1
	ldr r1, _08010E40
	ldrb r2, [r0]
	ldrb r0, [r1]
	cmp r2, r0
	beq _08010E32
	eors r0, r2
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_08010E32:
	movs r0, #0x11
	strh r0, [r4, #4]
	b _08010EDE
	.align 2, 0
_08010E38: .4byte 0x030050A0
_08010E3C: .4byte 0x0000099F
_08010E40: .4byte 0x030041E0
_08010E44:
	ldr r0, _08010E4C
	adds r0, #0xf0
	b _08010EDA
	.align 2, 0
_08010E4C: .4byte 0x030050A0
_08010E50:
	ldr r0, _08010E58
	adds r0, #0xf0
	movs r1, #3
	b _08010EDC
	.align 2, 0
_08010E58: .4byte 0x030050A0
_08010E5C:
	ldr r1, _08010E8C
	adds r2, r1, #0
	adds r2, #0xf0
	movs r0, #4
	strb r0, [r2]
	ldr r3, _08010E90
	adds r1, r1, r3
	ldr r0, _08010E94
	ldrb r2, [r0, #0x14]
	ldrb r0, [r1]
	adds r3, r0, #0
	bics r3, r2
	adds r2, r3, #0
	strb r2, [r1]
	ldr r0, _08010E98
	ldrb r0, [r0]
	cmp r0, #1
	bne _08010EA0
	cmp r2, #0
	bne _08010E9C
	adds r0, r4, #0
	bl RfuSetErrorParams
	b _08010EA0
	.align 2, 0
_08010E8C: .4byte 0x030050A0
_08010E90: .4byte 0x0000099A
_08010E94: .4byte 0x030041E0
_08010E98: .4byte 0x030031C4
_08010E9C:
	bl sub_08010CEC
_08010EA0:
	movs r0, #2
	adds r1, r4, #0
	bl sub_08011554
	b _08010EDE
_08010EAA:
	movs r0, #1
	movs r1, #0xf3
	bl sub_08011554
	movs r0, #0xf3
	bl RfuSetErrorParams
	ldr r0, _08010EC0
	adds r0, #0xef
	b _08010EDA
	.align 2, 0
_08010EC0: .4byte 0x030050A0
_08010EC4:
	adds r0, r4, #0
	bl RfuSetErrorParams
	movs r0, #1
	adds r1, r4, #0
	bl sub_08011554
	ldr r0, _08010EEC
	ldr r1, _08010EF0
	adds r0, r0, r1
	ldrb r1, [r0]
_08010EDA:
	movs r1, #1
_08010EDC:
	strb r1, [r0]
_08010EDE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08010EEC: .4byte 0x030050A0
_08010EF0: .4byte 0x00000993
	thumb_func_end sub_08010CFC

	thumb_func_start sub_08010EF4
sub_08010EF4: @ 0x08010EF4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x31
	bne _08010F00
	b _08011060
_08010F00:
	cmp r4, #0x31
	bgt _08010F2E
	cmp r4, #0x22
	beq _08010F84
	cmp r4, #0x22
	bgt _08010F1C
	cmp r4, #0x20
	beq _08010F6C
	cmp r4, #0x20
	ble _08010F16
	b _080110CE
_08010F16:
	cmp r4, #0
	beq _08010F5E
	b _080110CE
_08010F1C:
	cmp r4, #0x24
	beq _08010FAA
	cmp r4, #0x24
	blt _08010FA0
	cmp r4, #0x25
	beq _08010FF4
	cmp r4, #0x30
	beq _08010FFE
	b _080110CE
_08010F2E:
	cmp r4, #0x44
	bgt _08010F44
	cmp r4, #0x42
	blt _08010F38
	b _080110CE
_08010F38:
	cmp r4, #0x33
	beq _08011012
	cmp r4, #0x33
	bge _08010F42
	b _0801107C
_08010F42:
	b _080110CE
_08010F44:
	cmp r4, #0xf3
	bne _08010F4A
	b _0801109C
_08010F4A:
	cmp r4, #0xf3
	bgt _08010F56
	cmp r4, #0xf0
	bge _08010F54
	b _080110CE
_08010F54:
	b _080110B4
_08010F56:
	cmp r4, #0xff
	bne _08010F5C
	b _080110B4
_08010F5C:
	b _080110CE
_08010F5E:
	ldr r1, _08010F68
	movs r0, #6
	strh r0, [r1, #4]
	b _080110CE
	.align 2, 0
_08010F68: .4byte 0x030050A0
_08010F6C:
	ldr r0, _08010F78
	ldr r1, _08010F7C
	ldrh r1, [r1, #0x14]
	ldr r2, _08010F80
	adds r0, r0, r2
	b _080110CC
	.align 2, 0
_08010F78: .4byte 0x030050A0
_08010F7C: .4byte 0x030041E0
_08010F80: .4byte 0x00000985
_08010F84:
	ldr r0, _08010F94
	ldr r1, _08010F98
	ldrh r1, [r1, #0x14]
	ldr r2, _08010F9C
	adds r0, r0, r2
	ldrb r2, [r0]
	b _080110CC
	.align 2, 0
_08010F94: .4byte 0x030050A0
_08010F98: .4byte 0x030041E0
_08010F9C: .4byte 0x000008F6
_08010FA0:
	movs r0, #2
	adds r1, r4, #0
	bl sub_08011554
	b _080110CE
_08010FAA:
	ldr r4, _08010FE0
	movs r1, #0
	movs r0, #0xb
	strh r0, [r4, #4]
	ldr r2, _08010FE4
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08010FE8
	adds r2, r4, r0
	strb r1, [r2]
	ldr r1, _08010FEC
	adds r5, r4, r1
	ldrb r1, [r5]
	movs r0, #0x20
	movs r3, #1
	bl rfu_setRecvBuffer
	ldrb r1, [r5]
	ldr r2, _08010FF0
	adds r4, r4, r2
	movs r0, #0x10
	adds r2, r4, #0
	movs r3, #0x46
	bl rfu_setRecvBuffer
	b _080110CE
	.align 2, 0
_08010FE0: .4byte 0x030050A0
_08010FE4: .4byte 0x0000093D
_08010FE8: .4byte 0x0000093E
_08010FEC: .4byte 0x000008F6
_08010FF0: .4byte 0x000008F7
_08010FF4:
	movs r0, #2
	movs r1, #0x25
	bl sub_08011554
	b _080110CE
_08010FFE:
	ldr r0, _08011050
	adds r2, r0, #0
	adds r2, #0xf0
	movs r1, #2
	strb r1, [r2]
	ldr r1, _08011054
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #6
	beq _080110CE
_08011012:
	ldr r2, _08011050
	adds r1, r2, #0
	adds r1, #0xf0
	ldrb r0, [r1]
	cmp r0, #2
	beq _08011022
	movs r0, #4
	strb r0, [r1]
_08011022:
	ldr r1, _08011054
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _08011034
	movs r0, #2
	adds r1, r4, #0
	bl sub_08011554
_08011034:
	ldr r0, _08011058
	movs r1, #5
	movs r2, #5
	bl nullsub_13
	ldr r0, _0801105C
	ldrb r0, [r0]
	cmp r0, #1
	bne _080110CE
	adds r0, r4, #0
	bl RfuSetErrorParams
	b _080110CE
	.align 2, 0
_08011050: .4byte 0x030050A0
_08011054: .4byte 0x0000093E
_08011058: .4byte 0x082C0578
_0801105C: .4byte 0x030031C4
_08011060:
	ldr r0, _08011074
	adds r0, #0xf0
	movs r1, #1
	strb r1, [r0]
	ldr r0, _08011078
	movs r1, #5
	movs r2, #5
	bl nullsub_13
	b _080110CE
	.align 2, 0
_08011074: .4byte 0x030050A0
_08011078: .4byte 0x082C0590
_0801107C:
	ldr r1, _08011094
	adds r2, r1, #0
	adds r2, #0xf0
	movs r0, #3
	strb r0, [r2]
	ldr r2, _08011098
	adds r1, r1, r2
	ldrb r0, [r1]
	movs r0, #1
	strb r0, [r1]
	b _080110CE
	.align 2, 0
_08011094: .4byte 0x030050A0
_08011098: .4byte 0x000008F4
_0801109C:
	movs r0, #1
	movs r1, #0xf3
	bl sub_08011554
	movs r0, #0xf3
	bl RfuSetErrorParams
	ldr r0, _080110B0
	adds r0, #0xef
	b _080110CA
	.align 2, 0
_080110B0: .4byte 0x030050A0
_080110B4:
	movs r0, #1
	adds r1, r4, #0
	bl sub_08011554
	adds r0, r4, #0
	bl RfuSetErrorParams
	ldr r0, _080110D4
	ldr r1, _080110D8
	adds r0, r0, r1
	ldrb r1, [r0]
_080110CA:
	movs r1, #1
_080110CC:
	strb r1, [r0]
_080110CE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080110D4: .4byte 0x030050A0
_080110D8: .4byte 0x00000993
	thumb_func_end sub_08010EF4

	thumb_func_start sub_080110DC
sub_080110DC: @ 0x080110DC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r6, #1
	ldr r0, _08011110
	ldr r4, _08011114
	adds r1, r0, r4
	movs r5, #0
	movs r4, #0xff
_080110EE:
	adds r0, r3, #0
	asrs r0, r2
	ands r0, r6
	cmp r0, #0
	beq _08011100
	strb r5, [r1]
	ldrb r0, [r1, #4]
	orrs r0, r4
	strb r0, [r1, #4]
_08011100:
	adds r1, #1
	adds r2, #1
	cmp r2, #3
	ble _080110EE
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08011110: .4byte 0x030050A0
_08011114: .4byte 0x000009A2
	thumb_func_end sub_080110DC

	thumb_func_start sub_08011118
sub_08011118: @ 0x08011118
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r3, #0
	movs r2, #0
	movs r4, #1
	ldr r6, _08011160
	movs r7, #0x7f
_08011126:
	adds r0, r5, #0
	asrs r0, r2
	ands r0, r4
	cmp r0, #0
	beq _0801114C
	lsls r1, r2, #5
	adds r1, #0x14
	ldr r0, [r6]
	adds r0, r0, r1
	ldrb r1, [r0, #0x10]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0x45
	bne _0801114C
	adds r0, r4, #0
	lsls r0, r2
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
_0801114C:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08011126
	adds r0, r3, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011160: .4byte 0x03007630
	thumb_func_end sub_08011118

	thumb_func_start sub_08011164
sub_08011164: @ 0x08011164
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x25
	bne _08011170
	b _080113DC
_08011170:
	cmp r4, #0x25
	bgt _080111B2
	cmp r4, #0x14
	bne _0801117A
	b _080112F4
_0801117A:
	cmp r4, #0x14
	bgt _08011192
	cmp r4, #0x11
	beq _08011212
	cmp r4, #0x11
	ble _08011188
	b _08011532
_08011188:
	cmp r4, #0
	beq _080111FC
	cmp r4, #0x10
	beq _08011208
	b _08011532
_08011192:
	cmp r4, #0x22
	bne _08011198
	b _08011358
_08011198:
	cmp r4, #0x22
	bgt _080111A4
	cmp r4, #0x20
	bne _080111A2
	b _08011340
_080111A2:
	b _08011532
_080111A4:
	cmp r4, #0x23
	bne _080111AA
	b _08011374
_080111AA:
	cmp r4, #0x24
	bne _080111B0
	b _080113AA
_080111B0:
	b _08011532
_080111B2:
	cmp r4, #0x44
	bgt _080111E2
	cmp r4, #0x42
	blt _080111BC
	b _08011532
_080111BC:
	cmp r4, #0x32
	bne _080111C2
	b _08011404
_080111C2:
	cmp r4, #0x32
	bgt _080111D4
	cmp r4, #0x30
	bne _080111CC
	b _08011430
_080111CC:
	cmp r4, #0x31
	bne _080111D2
	b _080113E6
_080111D2:
	b _08011532
_080111D4:
	cmp r4, #0x33
	bne _080111DA
	b _08011438
_080111DA:
	cmp r4, #0x40
	bne _080111E0
	b _080114EC
_080111E0:
	b _08011532
_080111E2:
	cmp r4, #0xf3
	bne _080111E8
	b _080114FC
_080111E8:
	cmp r4, #0xf3
	bgt _080111F4
	cmp r4, #0xf0
	bge _080111F2
	b _08011532
_080111F2:
	b _08011518
_080111F4:
	cmp r4, #0xff
	bne _080111FA
	b _08011518
_080111FA:
	b _08011532
_080111FC:
	ldr r1, _08011204
	movs r0, #0x11
	strh r0, [r1, #4]
	b _08011532
	.align 2, 0
_08011204: .4byte 0x030050A0
_08011208:
	movs r0, #4
	movs r1, #0
	bl sub_08011554
	b _08011532
_08011212:
	bl sub_0800F29C
	ldrb r1, [r0, #0xa]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x45
	bne _080112CC
	ldr r5, _08011278
	ldr r1, _0801127C
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080112CC
	ldr r0, _08011280
	ldrh r0, [r0, #0x14]
	bl sub_08011118
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _08011296
	adds r0, r4, #0
	bl Rfu_GetIndexOfNewestChild
	movs r2, #1
	mov ip, r2
	mov r1, ip
	lsls r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r7, _08011284
	adds r6, r5, r7
	ldrb r2, [r6]
	cmp r2, #0
	bne _08011288
	movs r0, #0x9a
	lsls r0, r0, #4
	adds r3, r5, r0
	ldrb r0, [r3]
	cmp r0, #0
	bne _08011288
	subs r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	eors r1, r4
	orrs r1, r2
	strb r1, [r6]
	mov r0, ip
	strb r0, [r3]
	b _08011296
	.align 2, 0
_08011278: .4byte 0x030050A0
_0801127C: .4byte 0x00000991
_08011280: .4byte 0x030041E0
_08011284: .4byte 0x0000099E
_08011288:
	ldr r0, _080112B8
	ldr r1, _080112BC
	adds r0, r0, r1
	ldrb r2, [r0]
	adds r1, r4, #0
	orrs r1, r2
	strb r1, [r0]
_08011296:
	ldr r0, _080112C0
	ldrh r1, [r0, #0x14]
	cmp r4, r1
	beq _080112E6
	ldr r2, _080112B8
	ldr r7, _080112C4
	adds r3, r2, r7
	adds r0, r4, #0
	eors r0, r1
	ldrb r1, [r3]
	orrs r0, r1
	strb r0, [r3]
	ldr r0, _080112C8
	adds r2, r2, r0
	movs r0, #2
	strb r0, [r2]
	b _080112E6
	.align 2, 0
_080112B8: .4byte 0x030050A0
_080112BC: .4byte 0x0000099E
_080112C0: .4byte 0x030041E0
_080112C4: .4byte 0x0000099B
_080112C8: .4byte 0x0000099C
_080112CC:
	bl sub_0800F29C
	ldrb r1, [r0, #0xa]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x54
	bne _080112E6
	ldr r0, _080112F0
	ldrb r0, [r0]
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_080112E6:
	ldr r0, _080112F0
	ldrh r0, [r0, #0x14]
	bl sub_080110DC
	b _08011532
	.align 2, 0
_080112F0: .4byte 0x030041E0
_080112F4:
	bl sub_0800F29C
	ldrb r1, [r0, #0xa]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x45
	beq _08011326
	ldr r4, _08011338
	ldrb r0, [r4, #1]
	cmp r0, #1
	bls _08011326
	ldrb r0, [r4, #0x14]
	bl Rfu_GetIndexOfNewestChild
	movs r1, #0x80
	lsls r1, r1, #0x11
	lsls r1, r0
	lsrs r1, r1, #0x18
	ldrb r0, [r4]
	eors r1, r0
	adds r0, r1, #0
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
_08011326:
	ldr r1, _0801133C
	ldrh r0, [r1, #4]
	cmp r0, #0xf
	beq _08011330
	b _08011532
_08011330:
	movs r0, #0x10
	strh r0, [r1, #4]
	b _08011532
	.align 2, 0
_08011338: .4byte 0x030041E0
_0801133C: .4byte 0x030050A0
_08011340:
	ldr r0, _0801134C
	ldr r1, _08011350
	ldrh r1, [r1, #0x14]
	ldr r2, _08011354
	adds r0, r0, r2
	b _08011530
	.align 2, 0
_0801134C: .4byte 0x030050A0
_08011350: .4byte 0x030041E0
_08011354: .4byte 0x00000985
_08011358:
	ldr r0, _08011368
	ldr r1, _0801136C
	ldrh r1, [r1, #0x14]
	ldr r7, _08011370
	adds r0, r0, r7
	ldrb r2, [r0]
	b _08011530
	.align 2, 0
_08011368: .4byte 0x030050A0
_0801136C: .4byte 0x030041E0
_08011370: .4byte 0x000008F6
_08011374:
	ldr r1, _08011394
	movs r0, #0x12
	strh r0, [r1, #4]
	ldr r0, _08011398
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #1
	bhi _080113A0
	adds r0, #1
	strb r0, [r1]
	ldr r0, _0801139C
	movs r1, #2
	bl CreateTask
	b _08011532
	.align 2, 0
_08011394: .4byte 0x030050A0
_08011398: .4byte 0x00000987
_0801139C: .4byte 0x08011B89
_080113A0:
	movs r0, #2
	movs r1, #0x23
	bl sub_08011554
	b _08011532
_080113AA:
	ldr r4, _080113D0
	movs r0, #0xd
	strh r0, [r4, #4]
	movs r0, #3
	movs r1, #0
	bl sub_08011554
	ldr r1, _080113D4
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _080113D8
	adds r4, r4, r2
	movs r0, #0x10
	adds r2, r4, #0
	movs r3, #0x46
	bl rfu_setRecvBuffer
	b _08011532
	.align 2, 0
_080113D0: .4byte 0x030050A0
_080113D4: .4byte 0x000008F6
_080113D8: .4byte 0x000008F7
_080113DC:
	movs r0, #2
	movs r1, #0x25
	bl sub_08011554
	b _08011532
_080113E6:
	ldr r0, _080113FC
	ldrb r1, [r0]
	ldrh r0, [r0, #0x14]
	ands r1, r0
	cmp r1, #0
	bne _080113F4
	b _08011532
_080113F4:
	ldr r0, _08011400
	adds r0, #0xf0
	movs r1, #1
	b _08011530
	.align 2, 0
_080113FC: .4byte 0x030041E0
_08011400: .4byte 0x030050A0
_08011404:
	ldr r2, _08011424
	adds r1, r2, #0
	adds r1, #0xf0
	movs r0, #3
	strb r0, [r1]
	ldr r0, _08011428
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801141A
	b _08011532
_0801141A:
	ldr r7, _0801142C
	adds r0, r2, r7
	ldrb r1, [r0]
	movs r1, #1
	b _08011530
	.align 2, 0
_08011424: .4byte 0x030050A0
_08011428: .4byte 0x03007630
_0801142C: .4byte 0x000008F4
_08011430:
	ldr r0, _08011470
	adds r0, #0xf0
	movs r1, #2
	strb r1, [r0]
_08011438:
	ldr r2, _08011470
	adds r1, r2, #0
	adds r1, #0xf0
	ldrb r0, [r1]
	cmp r0, #2
	beq _08011448
	movs r0, #4
	strb r0, [r1]
_08011448:
	ldrb r0, [r2, #0xc]
	cmp r0, #1
	bne _08011486
	ldr r0, _08011474
	ldrb r0, [r0]
	cmp r0, #1
	bne _080114A4
	ldr r0, _08011478
	adds r2, r2, r0
	ldr r0, _0801147C
	ldrb r1, [r0, #0x14]
	ldrb r0, [r2]
	bics r0, r1
	strb r0, [r2]
	cmp r0, #0
	bne _08011480
	adds r0, r4, #0
	bl RfuSetErrorParams
	b _080114A4
	.align 2, 0
_08011470: .4byte 0x030050A0
_08011474: .4byte 0x030031C4
_08011478: .4byte 0x0000099A
_0801147C: .4byte 0x030041E0
_08011480:
	bl sub_08010CEC
	b _080114A4
_08011486:
	ldr r1, _080114D4
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080114A4
	ldr r0, _080114D8
	ldrb r0, [r0]
	cmp r0, #1
	bne _080114A4
	adds r0, r4, #0
	bl RfuSetErrorParams
	movs r0, #0
	bl rfu_LMAN_stopManager
_080114A4:
	ldr r0, _080114DC
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080114CA
	ldr r0, _080114E0
	ldrb r0, [r0, #7]
	cmp r0, #0
	bne _080114CA
	ldr r0, _080114E4
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080114CA
	ldr r1, _080114E8
	movs r0, #0x11
	strh r0, [r1, #4]
_080114CA:
	movs r0, #2
	adds r1, r4, #0
	bl sub_08011554
	b _08011532
	.align 2, 0
_080114D4: .4byte 0x0000099C
_080114D8: .4byte 0x030031C4
_080114DC: .4byte 0x03007630
_080114E0: .4byte 0x030041E0
_080114E4: .4byte 0x0800E609
_080114E8: .4byte 0x030050A0
_080114EC:
	ldr r0, _080114F4
	ldr r2, _080114F8
	adds r0, r0, r2
	b _0801152E
	.align 2, 0
_080114F4: .4byte 0x030050A0
_080114F8: .4byte 0x0000099B
_080114FC:
	movs r0, #1
	movs r1, #0xf3
	bl sub_08011554
	movs r0, #0xf3
	bl RfuSetErrorParams
	ldr r0, _08011514
	adds r0, #0xef
	movs r1, #1
	b _08011530
	.align 2, 0
_08011514: .4byte 0x030050A0
_08011518:
	adds r0, r4, #0
	bl RfuSetErrorParams
	movs r0, #1
	adds r1, r4, #0
	bl sub_08011554
	ldr r0, _08011538
	ldr r7, _0801153C
	adds r0, r0, r7
	ldrb r1, [r0]
_0801152E:
	movs r1, #0
_08011530:
	strb r1, [r0]
_08011532:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011538: .4byte 0x030050A0
_0801153C: .4byte 0x00000993
	thumb_func_end sub_08011164

	thumb_func_start sub_08011540
sub_08011540: @ 0x08011540
	ldr r0, _0801154C
	ldr r1, _08011550
	adds r0, r0, r1
	movs r1, #2
	strb r1, [r0]
	bx lr
	.align 2, 0
_0801154C: .4byte 0x030050A0
_08011550: .4byte 0x0000099C
	thumb_func_end sub_08011540

	thumb_func_start sub_08011554
sub_08011554: @ 0x08011554
	ldr r2, _08011560
	adds r3, r2, #0
	adds r3, #0xf1
	strb r0, [r3]
	strh r1, [r2, #0xa]
	bx lr
	.align 2, 0
_08011560: .4byte 0x030050A0
	thumb_func_end sub_08011554

	thumb_func_start RfuGetStatus
RfuGetStatus: @ 0x08011564
	ldr r0, _0801156C
	adds r0, #0xf1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0801156C: .4byte 0x030050A0
	thumb_func_end RfuGetStatus

	thumb_func_start sub_08011570
sub_08011570: @ 0x08011570
	push {lr}
	bl RfuGetStatus
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #1
	cmp r0, #1
	bls _08011584
	movs r0, #0
	b _08011586
_08011584:
	movs r0, #1
_08011586:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08011570

	thumb_func_start GetRfuRecvQueueLength
GetRfuRecvQueueLength: @ 0x0801158C
	ldr r0, _08011598
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08011598: .4byte 0x030050A0
	thumb_func_end GetRfuRecvQueueLength

	thumb_func_start Rfu_IsMaster
Rfu_IsMaster: @ 0x0801159C
	ldr r0, _080115A4
	ldrb r0, [r0, #0xc]
	bx lr
	.align 2, 0
_080115A4: .4byte 0x030050A0
	thumb_func_end Rfu_IsMaster

	thumb_func_start RfuVSync
RfuVSync: @ 0x080115A8
	push {lr}
	bl rfu_LMAN_syncVBlank
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end RfuVSync

	thumb_func_start sub_080115B4
sub_080115B4: @ 0x080115B4
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r1, _080115CC
	ldr r2, _080115D0
	mov r0, sp
	bl CpuSet
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_080115CC: .4byte 0x03003130
_080115D0: .4byte 0x05000014
	thumb_func_end sub_080115B4

	thumb_func_start sub_080115D4
sub_080115D4: @ 0x080115D4
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080115D4

	thumb_func_start sub_080115E8
sub_080115E8: @ 0x080115E8
	push {r4, lr}
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	bl ResetPaletteFade
	ldr r0, _08011664
	bl SetVBlankCallback
	bl IsWirelessAdapterConnected
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0801165C
	ldr r1, _08011668
	ldr r2, _0801166C
	adds r0, r2, #0
	strh r0, [r1]
	bl sub_0800AF5C
	bl OpenLink
	ldr r0, _08011670
	ldrh r0, [r0, #0x24]
	bl SeedRng
	movs r4, #0
_08011624:
	bl Random
	ldr r1, _08011674
	ldr r1, [r1]
	adds r1, #0xa
	adds r1, r1, r4
	strb r0, [r1]
	adds r4, #1
	cmp r4, #3
	ble _08011624
	movs r1, #0xaa
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	bl sub_08011690
	ldr r0, _08011678
	bl SetMainCallback2
_0801165C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08011664: .4byte 0x080115D5
_08011668: .4byte 0x0202267E
_0801166C: .4byte 0x00001111
_08011670: .4byte 0x03002360
_08011674: .4byte 0x03005AF0
_08011678: .4byte 0x080116E5
	thumb_func_end sub_080115E8

	thumb_func_start sub_0801167C
sub_0801167C: @ 0x0801167C
	push {lr}
	ldr r0, _0801168C
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0801168C: .4byte 0x0800E609
	thumb_func_end sub_0801167C

	thumb_func_start sub_08011690
sub_08011690: @ 0x08011690
	push {r4, lr}
	ldr r4, _080116B4
	adds r0, r4, #0
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080116AE
	adds r0, r4, #0
	movs r1, #0
	bl CreateTask
	ldr r1, _080116B8
	adds r1, #0x66
	strb r0, [r1]
_080116AE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080116B4: .4byte 0x08011FD5
_080116B8: .4byte 0x030050A0
	thumb_func_end sub_08011690

	thumb_func_start sub_080116BC
sub_080116BC: @ 0x080116BC
	push {lr}
	ldr r0, _080116DC
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080116D6
	ldr r0, _080116E0
	adds r0, #0x66
	ldrb r0, [r0]
	bl DestroyTask
_080116D6:
	pop {r0}
	bx r0
	.align 2, 0
_080116DC: .4byte 0x08011FD5
_080116E0: .4byte 0x030050A0
	thumb_func_end sub_080116BC

	thumb_func_start sub_080116E4
sub_080116E4: @ 0x080116E4
	push {lr}
	bl RunTasks
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080116E4

	thumb_func_start sub_080116FC
sub_080116FC: @ 0x080116FC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _08011734
	movs r0, #1
	strb r0, [r1, #0xc]
	bl sub_08010A38
	ldr r0, _08011738
	movs r1, #0
	bl rfu_LMAN_initializeManager
	ldr r2, _0801173C
	adds r1, r2, #0
	ldr r0, _08011740
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldr r0, _08011744
	subs r4, #1
	adds r4, r4, r0
	ldrb r0, [r4]
	strh r0, [r2, #2]
	bl CreateTask_ParentSearchForChildren
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08011734: .4byte 0x030050A0
_08011738: .4byte 0x08010CFD
_0801173C: .4byte 0x020227E4
_08011740: .4byte 0x082C0358
_08011744: .4byte 0x082C0370
	thumb_func_end sub_080116FC

	thumb_func_start sub_08011748
sub_08011748: @ 0x08011748
	push {lr}
	ldr r1, _08011764
	movs r0, #0
	strb r0, [r1, #0xc]
	bl sub_08010A38
	ldr r0, _08011768
	ldr r1, _0801176C
	bl rfu_LMAN_initializeManager
	bl CreateTask_ChildSearchForParent
	pop {r0}
	bx r0
	.align 2, 0
_08011764: .4byte 0x030050A0
_08011768: .4byte 0x08010EF5
_0801176C: .4byte 0x0800E7F5
	thumb_func_end sub_08011748

	thumb_func_start sub_08011770
sub_08011770: @ 0x08011770
	push {r4, r5, r6, r7, lr}
	ldr r4, _080117B0
	movs r5, #0
	movs r0, #2
	strb r0, [r4, #0xc]
	bl sub_08010A38
	ldr r0, _080117B4
	movs r1, #0
	bl rfu_LMAN_initializeManager
	ldr r2, _080117B8
	adds r1, r2, #0
	ldr r0, _080117BC
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	strb r5, [r2, #0x11]
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r2, #0x12]
	ldr r0, _080117C0
	movs r1, #1
	bl CreateTask
	adds r4, #0x67
	strb r0, [r4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080117B0: .4byte 0x030050A0
_080117B4: .4byte 0x08011165
_080117B8: .4byte 0x020227E4
_080117BC: .4byte 0x082C0358
_080117C0: .4byte 0x0800E609
	thumb_func_end sub_08011770

	thumb_func_start sub_080117C4
sub_080117C4: @ 0x080117C4
	ldrb r1, [r0, #1]
	lsls r1, r1, #8
	ldrb r0, [r0]
	orrs r0, r1
	bx lr
	.align 2, 0
	thumb_func_end sub_080117C4

	thumb_func_start sub_080117D0
sub_080117D0: @ 0x080117D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sl, r1
	movs r0, #0xff
	mov sb, r0
	movs r7, #0
	ldr r1, _08011854
	mov r8, r1
_080117EE:
	lsls r4, r7, #5
	adds r5, r4, #0
	adds r5, #0x14
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r5
	adds r0, #8
	bl sub_080117C4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r4
	ldrh r0, [r0, #0x18]
	bl IsRfuSerialNumberValid
	cmp r0, #0
	beq _08011838
	mov r0, r8
	ldr r1, [r0]
	adds r1, r1, r5
	adds r1, #0x15
	ldr r0, [sp]
	bl StringCompare
	cmp r0, #0
	bne _08011838
	cmp sl, r6
	bne _08011838
	mov sb, r7
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r4
	ldrb r0, [r0, #0x16]
	cmp r0, #0xff
	bne _08011842
_08011838:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _080117EE
_08011842:
	mov r0, sb
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08011854: .4byte 0x03007630
	thumb_func_end sub_080117D0

	thumb_func_start sub_08011858
sub_08011858: @ 0x08011858
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r0, r6, #0x18
	lsrs r0, r0, #0x18
	bl rfu_REQ_disconnect
	bl rfu_waitREQComplete
	ldr r4, _0801189C
	ldr r0, _080118A0
	adds r5, r4, r0
	ldrb r0, [r5]
	bics r0, r6
	strb r0, [r5]
	ldr r1, _080118A4
	adds r6, r4, r1
	ldrb r1, [r6]
	movs r0, #1
	bl rfu_clearSlot
	ldrb r0, [r5]
	ldr r1, _080118A8
	adds r4, r4, r1
	adds r1, r4, #0
	movs r2, #0x46
	bl rfu_UNI_setSendData
	ldrb r0, [r5]
	bl Rfu_GetIndexOfNewestChild
	strb r0, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801189C: .4byte 0x030050A0
_080118A0: .4byte 0x0000099A
_080118A4: .4byte 0x00000992
_080118A8: .4byte 0x0000093F
	thumb_func_end sub_08011858

	thumb_func_start sub_080118AC
sub_080118AC: @ 0x080118AC
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	bl sub_080117D0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xff
	beq _080118C6
	movs r0, #1
	lsls r0, r1
	bl sub_08011858
_080118C6:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080118AC

	thumb_func_start sub_080118CC
sub_080118CC: @ 0x080118CC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	cmp r4, #0
	beq _0801190C
	movs r3, #0
	movs r2, #0
	ldr r5, _08011914
	adds r6, r5, #4
_080118DC:
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, r4
	bne _080118FA
	ldrb r0, [r6]
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080118FA
	adds r0, r1, #0
	lsls r0, r2
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
_080118FA:
	adds r2, #1
	cmp r2, #3
	ble _080118DC
	cmp r3, #0
	beq _0801190C
	adds r0, r3, #0
	movs r1, #2
	bl sub_08011980
_0801190C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08011914: .4byte 0x03005A36
	thumb_func_end sub_080118CC

	thumb_func_start sub_08011918
sub_08011918: @ 0x08011918
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r6, _08011970
	ldrh r0, [r6]
	cmp r0, #0
	bne _08011968
	ldr r5, _08011974
	movs r1, #0x9a
	lsls r1, r1, #4
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08011968
	movs r0, #0xed
	lsls r0, r0, #8
	bl sub_0800F7F8
	ldr r1, _08011978
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0, #8]
	strh r1, [r6, #2]
	ldrh r1, [r0, #0xa]
	strh r1, [r6, #4]
	ldr r1, _0801197C
	movs r2, #8
	ldrsh r0, [r0, r2]
	adds r0, r0, r1
	ldrb r1, [r5, #0xd]
	ldrb r0, [r0]
	subs r1, r1, r0
	strb r1, [r5, #0xd]
	ldrb r0, [r5, #0xd]
	strh r0, [r6, #6]
	adds r0, r4, #0
	bl DestroyTask
_08011968:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08011970: .4byte 0x030031B0
_08011974: .4byte 0x030050A0
_08011978: .4byte 0x03005B60
_0801197C: .4byte 0x082C03E5
	thumb_func_end sub_08011918

	thumb_func_start sub_08011980
sub_08011980: @ 0x08011980
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r5, _080119B0
	adds r0, r5, #0
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	bne _080119B8
	adds r0, r5, #0
	movs r1, #5
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r1, _080119B4
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	strh r4, [r0, #8]
	b _080119C8
	.align 2, 0
_080119B0: .4byte 0x08011919
_080119B4: .4byte 0x03005B60
_080119B8:
	ldr r0, _080119DC
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrh r0, [r1, #8]
	orrs r4, r0
	strh r4, [r1, #8]
_080119C8:
	ldr r1, _080119DC
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	strh r6, [r0, #0xa]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080119DC: .4byte 0x03005B60
	thumb_func_end sub_08011980

	thumb_func_start sub_080119E0
sub_080119E0: @ 0x080119E0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r1, _08011A38
	adds r4, r0, r1
	bl CanTryReconnectParent
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08011A90
	adds r0, r4, #0
	adds r0, #0x10
	bl sub_080117C4
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_080117D0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	beq _08011A78
	ldr r0, _08011A3C
	ldr r0, [r0]
	lsls r1, r2, #5
	adds r0, r0, r1
	ldrb r0, [r0, #0x16]
	cmp r0, #0xff
	beq _08011A48
	ldr r0, _08011A40
	ldr r1, _08011A44
	adds r0, r0, r1
	strb r2, [r0]
	bl TryReconnectParent
	cmp r0, #0
	beq _08011A96
	b _08011A70
	.align 2, 0
_08011A38: .4byte 0x03005B68
_08011A3C: .4byte 0x03007630
_08011A40: .4byte 0x030050A0
_08011A44: .4byte 0x000008F5
_08011A48:
	bl sub_0800F29C
	ldrb r1, [r0, #0xa]
	movs r5, #0x7f
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #6
	beq _08011A90
	bl sub_0800F29C
	ldrb r1, [r0, #0xa]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #7
	beq _08011A90
	movs r1, #0xe0
	lsls r1, r1, #7
	movs r0, #2
	bl sub_08011554
_08011A70:
	adds r0, r6, #0
	bl DestroyTask
	b _08011A96
_08011A78:
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
	ldr r0, _08011A88
	ldr r1, _08011A8C
	adds r0, r0, r1
	strb r2, [r0]
	b _08011A96
	.align 2, 0
_08011A88: .4byte 0x030050A0
_08011A8C: .4byte 0x000008F5
_08011A90:
	ldrh r0, [r4, #0x1e]
	adds r0, #1
	strh r0, [r4, #0x1e]
_08011A96:
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	cmp r0, #0xf0
	ble _08011AAE
	movs r1, #0xe0
	lsls r1, r1, #7
	movs r0, #2
	bl sub_08011554
	adds r0, r6, #0
	bl DestroyTask
_08011AAE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_080119E0

	thumb_func_start sub_08011AB4
sub_08011AB4: @ 0x08011AB4
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r5, r1, #0x10
	lsrs r5, r5, #0x10
	ldr r0, _08011AEC
	adds r0, #0xf1
	movs r1, #0
	strb r1, [r0]
	ldr r0, _08011AF0
	movs r1, #3
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #3
	ldr r0, _08011AF4
	adds r4, r4, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl StringCopy
	strh r5, [r4, #0x10]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08011AEC: .4byte 0x030050A0
_08011AF0: .4byte 0x080119E1
_08011AF4: .4byte 0x03005B68
	thumb_func_end sub_08011AB4

	thumb_func_start sub_08011AF8
sub_08011AF8: @ 0x08011AF8
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	bl sub_0800F29C
	ldrb r1, [r0, #0xa]
	movs r2, #0x7f
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0x45
	bne _08011B1E
	ldrb r1, [r4, #0xa]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0x45
	beq _08011B7E
_08011B1A:
	movs r0, #1
	b _08011B80
_08011B1E:
	ldrb r1, [r4, #0xa]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0x40
	bne _08011B1A
	cmp r5, #0x44
	bne _08011B7E
	ldr r5, _08011B4C
	ldrh r0, [r5, #8]
	ldr r3, _08011B50
	adds r2, r3, #0
	ands r2, r0
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r2, r0
	bne _08011B54
	ldrh r1, [r4, #8]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, r2
	beq _08011B7E
	b _08011B1A
	.align 2, 0
_08011B4C: .4byte 0x030051AA
_08011B50: .4byte 0x000003FF
_08011B54:
	ldrh r1, [r4, #8]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, r2
	bne _08011B1A
	ldrb r2, [r4, #0xb]
	movs r0, #0xfe
	ldrb r3, [r5, #0xb]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bne _08011B1A
	ldrb r2, [r4, #9]
	movs r0, #0xfc
	ldrb r3, [r5, #9]
	adds r1, r0, #0
	ands r1, r2
	ands r0, r3
	cmp r1, r0
	bne _08011B1A
_08011B7E:
	movs r0, #0
_08011B80:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08011AF8

	thumb_func_start sub_08011B88
sub_08011B88: @ 0x08011B88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r8, r5
	ldr r6, _08011C40
	adds r0, r6, #0
	adds r0, #0xf1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08011BA6
	adds r0, r5, #0
	bl DestroyTask
_08011BA6:
	ldr r1, _08011C44
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r4, r0, r1
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	lsls r0, r0, #0x10
	movs r1, #0x96
	lsls r1, r1, #0x11
	cmp r0, r1
	ble _08011BD0
	movs r1, #0xe0
	lsls r1, r1, #7
	movs r0, #2
	bl sub_08011554
	adds r0, r5, #0
	bl DestroyTask
_08011BD0:
	ldr r1, _08011C48
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08011C68
	ldr r0, _08011C4C
	ldrb r0, [r0, #6]
	cmp r0, #0
	bne _08011C68
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r6, r2
	bl sub_080117C4
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08011C50
	adds r0, r6, r2
	bl sub_080117D0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	beq _08011C68
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	ldr r7, _08011C54
	lsls r4, r2, #5
	adds r2, r4, #0
	adds r2, #0x14
	ldr r1, [r7]
	adds r1, r1, r2
	adds r1, #6
	bl sub_08011AF8
	cmp r0, #0
	bne _08011C58
	ldr r0, [r7]
	adds r1, r0, r4
	ldrb r0, [r1, #0x16]
	cmp r0, #0xff
	beq _08011C68
	ldrh r0, [r1, #0x14]
	movs r1, #0x5a
	bl rfu_LMAN_CHILD_connectParent
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08011C68
	movs r0, #0xa
	strh r0, [r6, #4]
	adds r0, r5, #0
	bl DestroyTask
	b _08011C68
	.align 2, 0
_08011C40: .4byte 0x030050A0
_08011C44: .4byte 0x03005B60
_08011C48: .4byte 0x00000985
_08011C4C: .4byte 0x030041E0
_08011C50: .4byte 0x00000119
_08011C54: .4byte 0x03007630
_08011C58:
	movs r1, #0xe0
	lsls r1, r1, #7
	movs r0, #2
	bl sub_08011554
	mov r0, r8
	bl DestroyTask
_08011C68:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08011B88

	thumb_func_start sub_08011C74
sub_08011C74: @ 0x08011C74
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	lsls r4, r2, #0x18
	lsrs r4, r4, #0x18
	ldr r6, _08011CE4
	ldr r1, _08011CE8
	adds r0, r6, r1
	movs r7, #0
	strb r7, [r0]
	adds r0, r6, #0
	adds r0, #0xf1
	strb r7, [r0]
	ldr r1, _08011CEC
	adds r0, r6, r1
	adds r1, r3, #0
	bl StringCopy
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r1, r5, #0
	movs r2, #0xd
	bl memcpy
	bl rfu_LMAN_forceChangeSP
	ldr r0, _08011CF0
	movs r1, #2
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _08011CF4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r5
	strh r4, [r1, #0xa]
	ldr r0, _08011CF8
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	adds r2, r1, #0
	cmp r4, #0x45
	bne _08011CFC
	cmp r1, #0xff
	beq _08011D0A
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r5
	movs r1, #1
	strh r1, [r0, #0x16]
	b _08011D0A
	.align 2, 0
_08011CE4: .4byte 0x030050A0
_08011CE8: .4byte 0x00000987
_08011CEC: .4byte 0x00000119
_08011CF0: .4byte 0x08011B89
_08011CF4: .4byte 0x03005B60
_08011CF8: .4byte 0x0800E609
_08011CFC:
	cmp r2, #0xff
	beq _08011D0A
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r5
	strh r7, [r0, #0x16]
_08011D0A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_08011C74

	thumb_func_start IsRfuRecoveringFromLinkLoss
IsRfuRecoveringFromLinkLoss: @ 0x08011D10
	push {lr}
	ldr r0, _08011D20
	adds r0, #0xf0
	ldrb r0, [r0]
	cmp r0, #1
	beq _08011D24
	movs r0, #0
	b _08011D26
	.align 2, 0
_08011D20: .4byte 0x030050A0
_08011D24:
	movs r0, #1
_08011D26:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsRfuRecoveringFromLinkLoss

	thumb_func_start sub_08011D2C
sub_08011D2C: @ 0x08011D2C
	push {r4, lr}
	movs r1, #0
	ldr r0, _08011D50
	ldrb r2, [r0]
	ldr r4, _08011D54
	movs r3, #1
_08011D38:
	adds r0, r2, #0
	asrs r0, r1
	ands r0, r3
	cmp r0, #0
	beq _08011D58
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08011D58
	movs r0, #0
	b _08011D60
	.align 2, 0
_08011D50: .4byte 0x030041E0
_08011D54: .4byte 0x03005A29
_08011D58:
	adds r1, #1
	cmp r1, #3
	ble _08011D38
	movs r0, #1
_08011D60:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08011D2C

	thumb_func_start sub_08011D68
sub_08011D68: @ 0x08011D68
	push {r4, lr}
	movs r4, #0
_08011D6C:
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	ldr r0, _08011D84
	movs r1, #0
	bl nullsub_13
	adds r4, #1
	cmp r4, #0x13
	ble _08011D6C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08011D84: .4byte 0x082C05A8
	thumb_func_end sub_08011D68

	thumb_func_start sub_08011D88
sub_08011D88: @ 0x08011D88
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	bl GetBlockReceivedStatus
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x1c
	movs r2, #0x13
	movs r3, #2
	bl nullsub_5
	ldr r4, _08011E58
	ldr r0, [r4]
	ldrb r0, [r0, #2]
	movs r1, #0x14
	movs r2, #1
	movs r3, #1
	bl nullsub_5
	ldr r0, [r4]
	ldrb r0, [r0, #3]
	movs r1, #0x17
	movs r2, #1
	movs r3, #1
	bl nullsub_5
	ldr r0, _08011E5C
	ldrb r0, [r0, #0xc]
	cmp r0, #1
	bne _08011E64
	movs r6, #0
	adds r7, r4, #0
	movs r5, #0x14
_08011DCC:
	ldr r2, [r7]
	ldrb r0, [r2, #7]
	asrs r0, r6
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08011E0A
	lsls r0, r6, #5
	adds r0, r2, r0
	ldrh r0, [r0, #0x18]
	adds r4, r6, #3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r2, r4, #0
	movs r3, #4
	bl nullsub_5
	ldr r0, [r7]
	adds r0, r0, r5
	adds r0, #6
	movs r1, #6
	adds r2, r4, #0
	bl nullsub_13
	ldr r0, [r7]
	adds r0, r0, r5
	adds r0, #0x15
	movs r1, #0x16
	adds r2, r4, #0
	bl nullsub_13
_08011E0A:
	adds r5, #0x20
	adds r6, #1
	cmp r6, #3
	ble _08011DCC
	movs r6, #0
	ldr r0, _08011E5C
	mov r8, r0
_08011E18:
	movs r5, #0
	adds r7, r6, #1
	lsls r0, r6, #3
	adds r2, r6, #0
	adds r2, #0xb
	subs r0, r0, r6
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #0x14
	adds r4, r0, r1
	lsls r6, r2, #0x18
_08011E2E:
	ldrb r0, [r4]
	lsls r1, r5, #0x19
	lsrs r1, r1, #0x18
	lsrs r2, r6, #0x18
	movs r3, #2
	bl nullsub_5
	adds r4, #1
	adds r5, #1
	cmp r5, #0xd
	ble _08011E2E
	adds r6, r7, #0
	cmp r6, #3
	ble _08011E18
	ldr r0, _08011E60
	movs r1, #1
	movs r2, #0xf
	bl nullsub_13
	b _08011F96
	.align 2, 0
_08011E58: .4byte 0x03007630
_08011E5C: .4byte 0x030050A0
_08011E60: .4byte 0x082C05E4
_08011E64:
	ldr r1, [r4]
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _08011F00
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08011F00
	movs r6, #0
	movs r5, #0xc0
	lsls r5, r5, #0x12
_08011E78:
	lsrs r4, r5, #0x18
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	movs r3, #4
	bl nullsub_5
	ldr r0, _08011EEC
	movs r1, #6
	adds r2, r4, #0
	bl nullsub_13
	ldr r0, _08011EF0
	movs r1, #0x16
	adds r2, r4, #0
	bl nullsub_13
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r5, r5, r1
	adds r6, #1
	cmp r6, #3
	ble _08011E78
	ldr r5, _08011EF4
	ldr r1, [r5]
	ldr r4, _08011EF8
	ldr r0, _08011EFC
	adds r4, r4, r0
	ldrb r0, [r4]
	lsls r0, r0, #5
	adds r1, r1, r0
	ldrh r0, [r1, #0x18]
	movs r1, #1
	movs r2, #3
	movs r3, #4
	bl nullsub_5
	ldrb r1, [r4]
	lsls r1, r1, #5
	adds r1, #0x14
	ldr r0, [r5]
	adds r0, r0, r1
	adds r0, #6
	movs r1, #6
	movs r2, #3
	bl nullsub_13
	ldrb r1, [r4]
	lsls r1, r1, #5
	adds r1, #0x14
	ldr r0, [r5]
	adds r0, r0, r1
	adds r0, #0x15
	movs r1, #0x16
	movs r2, #3
	bl nullsub_13
	b _08011F96
	.align 2, 0
_08011EEC: .4byte 0x082C05C7
_08011EF0: .4byte 0x082C05D7
_08011EF4: .4byte 0x03007630
_08011EF8: .4byte 0x030050A0
_08011EFC: .4byte 0x000008F6
_08011F00:
	movs r6, #0
	ldr r1, _08011FA0
	ldr r0, [r1]
	ldrb r0, [r0, #8]
	cmp r6, r0
	bge _08011F5C
	adds r7, r1, #0
	movs r1, #0x14
	mov r8, r1
_08011F12:
	ldr r0, [r7]
	lsls r5, r6, #5
	adds r1, r0, r5
	ldrb r0, [r1, #0x16]
	cmp r0, #0xff
	beq _08011F4E
	ldrh r0, [r1, #0x18]
	adds r4, r6, #3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r1, #1
	adds r2, r4, #0
	movs r3, #4
	bl nullsub_5
	ldr r0, [r7]
	adds r0, r0, r5
	ldrh r0, [r0, #0x14]
	movs r1, #6
	adds r2, r4, #0
	movs r3, #4
	bl nullsub_5
	ldr r0, [r7]
	add r0, r8
	adds r0, #0x15
	movs r1, #0x16
	adds r2, r4, #0
	bl nullsub_13
_08011F4E:
	movs r0, #0x20
	add r8, r0
	adds r6, #1
	ldr r0, [r7]
	ldrb r0, [r0, #8]
	cmp r6, r0
	blt _08011F12
_08011F5C:
	cmp r6, #3
	bgt _08011F96
	lsls r0, r6, #0x18
	movs r1, #0xc0
	lsls r1, r1, #0x12
	adds r5, r0, r1
_08011F68:
	lsrs r4, r5, #0x18
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	movs r3, #4
	bl nullsub_5
	ldr r0, _08011FA4
	movs r1, #6
	adds r2, r4, #0
	bl nullsub_13
	ldr r0, _08011FA8
	movs r1, #0x16
	adds r2, r4, #0
	bl nullsub_13
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r5, r5, r0
	adds r6, #1
	cmp r6, #3
	ble _08011F68
_08011F96:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08011FA0: .4byte 0x03007630
_08011FA4: .4byte 0x082C05C7
_08011FA8: .4byte 0x082C05D7
	thumb_func_end sub_08011D88

	thumb_func_start sub_08011FAC
sub_08011FAC: @ 0x08011FAC
	ldr r0, _08011FB8
	ldr r1, _08011FBC
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08011FB8: .4byte 0x030050A0
_08011FBC: .4byte 0x000008D2
	thumb_func_end sub_08011FAC

	thumb_func_start sub_08011FC0
sub_08011FC0: @ 0x08011FC0
	ldr r0, _08011FCC
	ldr r1, _08011FD0
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_08011FCC: .4byte 0x030050A0
_08011FD0: .4byte 0x0000069E
	thumb_func_end sub_08011FC0

	.globl Rfu_set_zero
	.set Rfu_set_zero, ClearLinkRfuCallback
	.globl sub_0800FF34
	.set sub_0800FF34, Rfu_SetLinkStandbyCallback
	.globl task_add_05_task_del_08FA224_when_no_RfuFunc
	.set task_add_05_task_del_08FA224_when_no_RfuFunc, Rfu_SetCloseLinkCallback
	.globl sub_08010000
	.set sub_08010000, IsLinkRfuTaskFinished
