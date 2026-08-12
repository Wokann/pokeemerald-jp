.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified




	thumb_func_start sub_0802A148
sub_0802A148: @ 0x0802A148
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r1, _0802A168
	ldr r2, [r1]
	ldr r6, _0802A16C
	adds r0, r2, r6
	ldrb r0, [r0]
	adds r5, r1, #0
	cmp r0, #1
	beq _0802A1A0
	cmp r0, #1
	bgt _0802A170
	cmp r0, #0
	beq _0802A176
	b _0802A214
	.align 2, 0
_0802A168: .4byte 0x020229AC
_0802A16C: .4byte 0x00003014
_0802A170:
	cmp r0, #2
	beq _0802A1E8
	b _0802A214
_0802A176:
	ldr r4, _0802A198
	adds r0, r4, #0
	bl AddWindow
	ldr r1, [r5]
	ldr r2, _0802A19C
	adds r1, r1, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, #0
	bl sub_08028EA0
	b _0802A204
	.align 2, 0
_0802A198: .4byte 0x082CB478
_0802A19C: .4byte 0x00003008
_0802A1A0:
	ldr r4, _0802A1DC
	adds r0, r2, r4
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r2, _0802A1E0
	movs r1, #6
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #4
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, _0802A1E4
	adds r1, r1, r0
	b _0802A208
	.align 2, 0
_0802A1DC: .4byte 0x00003008
_0802A1E0: .4byte 0x085CCDEA
_0802A1E4: .4byte 0x00003014
_0802A1E8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A1FE
	ldr r0, [r5]
	ldr r1, _0802A210
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A1FE:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
_0802A204:
	ldr r1, [r5]
	adds r1, r1, r6
_0802A208:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A220
	.align 2, 0
_0802A210: .4byte 0x00003008
_0802A214:
	ldr r0, [r5]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
_0802A220:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_0802A148

	thumb_func_start sub_0802A228
sub_0802A228: @ 0x0802A228
	push {r4, r5, lr}
	sub sp, #8
	ldr r5, _0802A274
	ldr r0, [r5]
	ldr r4, _0802A278
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r5]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802A274: .4byte 0x020229AC
_0802A278: .4byte 0x00003008
	thumb_func_end sub_0802A228

	thumb_func_start sub_0802A27C
sub_0802A27C: @ 0x0802A27C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r0, _0802A29C
	ldr r1, [r0]
	ldr r7, _0802A2A0
	adds r2, r1, r7
	ldrb r5, [r2]
	adds r6, r0, #0
	cmp r5, #1
	beq _0802A304
	cmp r5, #1
	bgt _0802A2A4
	cmp r5, #0
	beq _0802A2AE
	b _0802A398
	.align 2, 0
_0802A29C: .4byte 0x020229AC
_0802A2A0: .4byte 0x00003014
_0802A2A4:
	cmp r5, #2
	beq _0802A34C
	cmp r5, #3
	beq _0802A378
	b _0802A398
_0802A2AE:
	ldr r4, _0802A2F4
	adds r0, r4, #0
	bl AddWindow
	ldr r1, [r6]
	ldr r2, _0802A2F8
	adds r1, r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, #0
	bl sub_08028EA0
	ldr r1, [r6]
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	ldr r2, _0802A2FC
	adds r1, r0, r2
	movs r2, #0
	strh r5, [r1]
	ldr r1, _0802A300
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	adds r1, #4
	adds r0, r0, r1
	strb r2, [r0]
	b _0802A3DE
	.align 2, 0
_0802A2F4: .4byte 0x082CB470
_0802A2F8: .4byte 0x00003008
_0802A2FC: .4byte 0x0000301C
_0802A300: .4byte 0x00003020
_0802A304:
	ldr r4, _0802A340
	adds r0, r1, r4
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r2, _0802A344
	movs r1, #6
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #2
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r6]
	ldr r2, _0802A348
	adds r1, r1, r2
	b _0802A36C
	.align 2, 0
_0802A340: .4byte 0x00003008
_0802A344: .4byte 0x085CCDCB
_0802A348: .4byte 0x00003014
_0802A34C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A362
	ldr r0, [r6]
	ldr r1, _0802A374
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A362:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r6]
	adds r1, r1, r7
_0802A36C:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A3DE
	.align 2, 0
_0802A374: .4byte 0x00003008
_0802A378:
	ldr r0, _0802A394
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _0802A3DE
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _0802A3DE
	.align 2, 0
_0802A394: .4byte 0x0000301C
_0802A398:
	ldr r0, [r6]
	ldr r1, _0802A3E8
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r6]
	ldr r4, _0802A3EC
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r0, r0, r2
	movs r1, #1
	str r1, [r0]
_0802A3DE:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A3E8: .4byte 0x00003024
_0802A3EC: .4byte 0x00003008
	thumb_func_end sub_0802A27C

	thumb_func_start sub_0802A3F0
sub_0802A3F0: @ 0x0802A3F0
	push {r4, lr}
	ldr r4, _0802A414
	ldr r0, [r4]
	ldr r1, _0802A418
	adds r0, r0, r1
	ldrb r0, [r0]
	bl DestroyTask
	ldr r0, [r4]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A414: .4byte 0x020229AC
_0802A418: .4byte 0x00003004
	thumb_func_end sub_0802A3F0

	thumb_func_start sub_0802A41C
sub_0802A41C: @ 0x0802A41C
	bx lr
	.align 2, 0
	thumb_func_end sub_0802A41C

	thumb_func_start sub_0802A420
sub_0802A420: @ 0x0802A420
	push {r4, lr}
	ldr r2, _0802A444
	ldr r1, [r2]
	ldr r3, _0802A448
	adds r1, r1, r3
	movs r3, #0
	strb r3, [r1]
	ldr r1, [r2]
	movs r4, #0xc0
	lsls r4, r4, #6
	adds r2, r1, r4
	str r3, [r2]
	ldr r2, _0802A44C
	adds r1, r1, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A444: .4byte 0x020229AC
_0802A448: .4byte 0x00003014
_0802A44C: .4byte 0x00003028
	thumb_func_end sub_0802A420

	thumb_func_start sub_0802A450
sub_0802A450: @ 0x0802A450
	ldr r0, _0802A45C
	ldr r0, [r0]
	ldr r1, _0802A460
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0802A45C: .4byte 0x020229AC
_0802A460: .4byte 0x00003028
	thumb_func_end sub_0802A450

	thumb_func_start sub_0802A464
sub_0802A464: @ 0x0802A464
	push {lr}
	ldr r0, _0802A47C
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #1
	beq _0802A480
	movs r0, #1
	b _0802A482
	.align 2, 0
_0802A47C: .4byte 0x020229AC
_0802A480:
	movs r0, #0
_0802A482:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802A464

	thumb_func_start sub_0802A488
sub_0802A488: @ 0x0802A488
	ldr r0, _0802A494
	ldr r0, [r0]
	ldr r1, _0802A498
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0802A494: .4byte 0x020229AC
_0802A498: .4byte 0x00003024
	thumb_func_end sub_0802A488

	thumb_func_start sub_0802A49C
sub_0802A49C: @ 0x0802A49C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	movs r3, #0xc0
	lsls r3, r3, #0x13
	movs r4, #0xc0
	lsls r4, r4, #9
	add r0, sp, #4
	mov r8, r0
	mov r2, sp
	movs r6, #0
	ldr r1, _0802A5CC
	movs r5, #0x80
	lsls r5, r5, #5
	ldr r7, _0802A5D0
	movs r0, #0x81
	lsls r0, r0, #0x18
	mov ip, r0
_0802A4C2:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, #4]
	str r7, [r1, #8]
	ldr r0, [r1, #8]
	adds r3, r3, r5
	subs r4, r4, r5
	cmp r4, r5
	bhi _0802A4C2
	strh r6, [r2]
	mov r2, sp
	str r2, [r1]
	str r3, [r1, #4]
	lsrs r0, r4, #1
	mov r2, ip
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	movs r3, #0x80
	lsls r3, r3, #3
	movs r4, #0
	str r4, [sp, #4]
	ldr r2, _0802A5CC
	mov r1, r8
	str r1, [r2]
	str r0, [r2, #4]
	lsrs r0, r3, #2
	movs r1, #0x85
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	mov r0, sp
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	lsrs r3, r3, #1
	movs r0, #0x81
	lsls r0, r0, #0x18
	orrs r3, r0
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	movs r1, #0
	bl SetGpuReg
	movs r0, #0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, _0802A5D4
	movs r0, #0
	movs r2, #4
	bl InitBgsFromTemplates
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	bl InitStandardTextBoxWindows
	bl sub_08196DF4
	movs r1, #0x82
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r4, _0802A5D8
	ldr r1, [r4]
	movs r0, #3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	movs r0, #1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	adds r1, r1, r0
	movs r0, #2
	bl SetBgTilemapBuffer
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A5CC: .4byte 0x040000D4
_0802A5D0: .4byte 0x81000800
_0802A5D4: .4byte 0x082CB430
_0802A5D8: .4byte 0x020229AC
	thumb_func_end sub_0802A49C

	thumb_func_start sub_0802A5DC
sub_0802A5DC: @ 0x0802A5DC
	push {lr}
	sub sp, #4
	ldr r0, _0802A5F8
	ldr r0, [r0]
	ldr r2, _0802A5FC
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #5
	bhi _0802A676
	lsls r0, r0, #2
	ldr r1, _0802A600
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802A5F8: .4byte 0x020229AC
_0802A5FC: .4byte 0x00003018
_0802A600: .4byte 0x0802A604
_0802A604: @ jump table
	.4byte _0802A61C @ case 0
	.4byte _0802A62C @ case 1
	.4byte _0802A632 @ case 2
	.4byte _0802A640 @ case 3
	.4byte _0802A658 @ case 4
	.4byte _0802A666 @ case 5
_0802A61C:
	ldr r0, _0802A628
	movs r1, #0
	movs r2, #0x40
	bl LoadPalette
	b _0802A67E
	.align 2, 0
_0802A628: .4byte 0x082CB67C
_0802A62C:
	bl ResetTempTileDataBuffers
	b _0802A67E
_0802A632:
	ldr r1, _0802A63C
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	b _0802A648
	.align 2, 0
_0802A63C: .4byte 0x082CB910
_0802A640:
	ldr r1, _0802A654
	movs r0, #0
	str r0, [sp]
	movs r0, #1
_0802A648:
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	b _0802A67E
	.align 2, 0
_0802A654: .4byte 0x082CC1A0
_0802A658:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0802A67E
	b _0802A68C
_0802A666:
	movs r0, #3
	bl GetTextWindowPalette
	movs r1, #0xd0
	movs r2, #0x20
	bl LoadPalette
	b _0802A67E
_0802A676:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0802A68E
_0802A67E:
	ldr r0, _0802A694
	ldr r1, [r0]
	ldr r0, _0802A698
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802A68C:
	movs r0, #0
_0802A68E:
	add sp, #4
	pop {r1}
	bx r1
	.align 2, 0
_0802A694: .4byte 0x020229AC
_0802A698: .4byte 0x00003018
	thumb_func_end sub_0802A5DC
