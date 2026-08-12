.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start sub_08023EFC
sub_08023EFC: @ 0x08023EFC
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r5, #0xc]
	cmp r0, #4
	bhi _08023FE0
	lsls r0, r0, #2
	ldr r1, _08023F14
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08023F14: .4byte 0x08023F18
_08023F18: @ jump table
	.4byte _08023F2C @ case 0
	.4byte _08023F68 @ case 1
	.4byte _08023F6E @ case 2
	.4byte _08023FB8 @ case 3
	.4byte _08023FCC @ case 4
_08023F2C:
	ldrh r1, [r5, #0x28]
	ldr r0, _08023F64
	cmp r1, r0
	bls _08023F3E
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r5, r1
	bl sub_080222B4
_08023F3E:
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl sub_08024410
	movs r4, #0
	movs r0, #0x13
	strb r0, [r5, #0xe]
	movs r0, #3
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _08023FE6
	.align 2, 0
_08023F64: .4byte 0x00008C9F
_08023F68:
	bl Rfu_SetLinkStandbyCallback
	b _08023FE0
_08023F6E:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08023FE6
	movs r0, #0
	movs r1, #0
	bl DrawDialogueFrame
	ldr r2, _08023FB0
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r0, #0
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized2
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	ldr r0, _08023FB4
	movs r1, #0
	bl CreateTask
	b _08023FE0
	.align 2, 0
_08023FB0: .4byte 0x08277071
_08023FB4: .4byte 0x081535C5
_08023FB8:
	ldr r0, _08023FC8
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08023FE0
	b _08023FE6
	.align 2, 0
_08023FC8: .4byte 0x081535C5
_08023FCC:
	movs r0, #0x14
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	movs r1, #0
	movs r0, #0xf
	strh r0, [r5, #0x12]
	strb r1, [r5, #0xc]
	b _08023FE6
_08023FE0:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_08023FE6:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08023EFC

	thumb_func_start sub_08023FF0
sub_08023FF0: @ 0x08023FF0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r6, r1, #0
	ldrb r0, [r5, #0xc]
	cmp r0, #1
	beq _08024032
	cmp r0, #1
	bgt _08024008
	cmp r0, #0
	beq _0802400E
	b _08024098
_08024008:
	cmp r0, #2
	beq _08024038
	b _08024098
_0802400E:
	movs r0, #1
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #4
	movs r2, #0
	movs r3, #0
	bl sub_08024410
	movs r0, #0x14
	strb r0, [r5, #0xe]
	movs r0, #3
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	movs r0, #0
	strb r0, [r5, #0xc]
	b _080240A0
_08024032:
	bl DisplayYesNoMenuDefaultYes
	b _08024098
_08024038:
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, r0, #0x18
	asrs r4, r0, #0x18
	movs r0, #2
	rsbs r0, r0, #0
	cmp r4, r0
	beq _0802409E
	adds r0, r5, #0
	adds r0, #0x42
	movs r1, #0
	movs r2, #0xc
	bl memset
	cmp r4, #0
	bne _0802406A
	bl HasAtLeastOneBerry
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08024066
	strh r4, [r5, #0x14]
	b _0802406E
_08024066:
	movs r0, #3
	b _0802406C
_0802406A:
	movs r0, #1
_0802406C:
	strh r0, [r5, #0x14]
_0802406E:
	movs r0, #0
	movs r1, #1
	bl ClearDialogWindowAndFrame
	movs r4, #0
	str r4, [sp]
	adds r0, r6, #0
	movs r1, #8
	movs r2, #0
	movs r3, #0
	bl sub_08024410
	movs r0, #0x15
	strb r0, [r5, #0xe]
	movs r0, #3
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _0802409E
_08024098:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_0802409E:
	movs r0, #0
_080240A0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_08023FF0

	thumb_func_start sub_080240A8
sub_080240A8: @ 0x080240A8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r5, #0
	ldrb r0, [r4, #0xc]
	cmp r0, #1
	beq _080240CE
	cmp r0, #1
	bgt _080240BE
	cmp r0, #0
	beq _080240C8
	b _08024174
_080240BE:
	cmp r0, #2
	beq _080240F0
	cmp r0, #3
	beq _080240FE
	b _08024174
_080240C8:
	bl Rfu_SetLinkStandbyCallback
	b _08024174
_080240CE:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802417A
	ldrh r0, [r4, #0x14]
	adds r1, r4, #0
	adds r1, #0x42
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0x4e
	strh r5, [r0]
	movs r0, #0
	movs r2, #2
	bl SendBlock
	b _08024174
_080240F0:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802417A
	strh r5, [r4, #0x10]
	b _08024174
_080240FE:
	bl GetBlockReceivedStatus
	ldr r2, _08024150
	ldrb r3, [r4, #9]
	subs r1, r3, #2
	adds r1, r1, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bne _0802417A
	adds r7, r4, #0
	adds r7, #0x42
	adds r6, r4, #0
	adds r6, #0x4e
	cmp r5, r3
	bhs _0802413C
	adds r1, r6, #0
	ldr r2, _08024154
_08024124:
	lsls r0, r5, #8
	adds r0, r0, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r0, [r4, #9]
	cmp r5, r0
	blo _08024124
_0802413C:
	ldrh r0, [r6]
	cmp r0, #0
	beq _08024158
	movs r0, #0x17
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	b _08024162
	.align 2, 0
_08024150: .4byte 0x082C7CD4
_08024154: .4byte 0x0202207C
_08024158:
	movs r0, #0x16
	movs r1, #1
	movs r2, #0
	bl sub_08022950
_08024162:
	bl ResetBlockReceivedFlags
	movs r1, #0
	movs r0, #0
	strh r0, [r7]
	strh r0, [r6]
	strh r0, [r4, #0x10]
	strb r1, [r4, #0xc]
	b _0802417C
_08024174:
	ldrb r0, [r4, #0xc]
	adds r0, #1
	strb r0, [r4, #0xc]
_0802417A:
	movs r0, #0
_0802417C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080240A8

	thumb_func_start sub_08024184
sub_08024184: @ 0x08024184
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldrb r4, [r5, #0xc]
	cmp r4, #1
	beq _080241B2
	cmp r4, #1
	bgt _0802419A
	cmp r4, #0
	beq _080241A4
	b _080241FC
_0802419A:
	cmp r4, #2
	beq _080241BE
	cmp r4, #3
	beq _080241E2
	b _080241FC
_080241A4:
	movs r0, #1
	rsbs r0, r0, #0
	str r4, [sp]
	movs r1, #1
	movs r2, #0
	movs r3, #0x10
	b _080241D8
_080241B2:
	bl UpdatePaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080241FC
	b _08024202
_080241BE:
	movs r0, #0
	movs r1, #1
	bl ClearDialogWindowAndFrame
	adds r0, r5, #0
	bl sub_080211B4
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0x10
	movs r3, #0
_080241D8:
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _080241FC
_080241E2:
	bl UpdatePaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08024202
	movs r0, #7
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	movs r0, #0
	strh r4, [r5, #0x12]
	b _08024200
_080241FC:
	ldrb r0, [r5, #0xc]
	adds r0, #1
_08024200:
	strb r0, [r5, #0xc]
_08024202:
	movs r0, #0
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08024184

	thumb_func_start sub_0802420C
sub_0802420C: @ 0x0802420C
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldrb r4, [r5, #0xc]
	cmp r4, #1
	beq _08024284
	cmp r4, #1
	bgt _08024222
	cmp r4, #0
	beq _08024228
	b _080242BE
_08024222:
	cmp r4, #2
	beq _0802429C
	b _080242BE
_08024228:
	movs r0, #0
	movs r1, #0
	bl DrawDialogueFrame
	ldrh r1, [r5, #0x14]
	cmp r1, #3
	bne _08024258
	ldr r0, _08024254
	ldr r2, [r0, #0x14]
	ldrb r3, [r5, #0xb]
	str r4, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0
	movs r1, #1
	bl AddTextPrinterParameterized2
	b _08024274
	.align 2, 0
_08024254: .4byte 0x082C5EBC
_08024258:
	ldr r0, _08024280
	ldr r2, [r0, #0x18]
	ldrb r3, [r5, #0xb]
	str r4, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r0, #0
	movs r1, #1
	bl AddTextPrinterParameterized2
_08024274:
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	b _080242BE
	.align 2, 0
_08024280: .4byte 0x082C5EBC
_08024284:
	movs r0, #0
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080242C4
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x78
	strb r0, [r1]
	b _080242BE
_0802429C:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r4, r0, #0
	cmp r4, #0
	beq _080242B0
	subs r0, #1
	strb r0, [r1]
	b _080242C4
_080242B0:
	movs r0, #0x18
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _080242C4
_080242BE:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_080242C4:
	movs r0, #0
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802420C

	thumb_func_start sub_080242D0
sub_080242D0: @ 0x080242D0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrb r4, [r5, #0xc]
	cmp r4, #1
	beq _080242F0
	cmp r4, #1
	bgt _080242E4
	cmp r4, #0
	beq _080242EA
	b _08024320
_080242E4:
	cmp r4, #2
	beq _08024300
	b _08024320
_080242EA:
	bl Rfu_SetLinkStandbyCallback
	b _08024320
_080242F0:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08024326
	bl SetCloseLinkCallback
	b _08024320
_08024300:
	ldr r0, _0802431C
	ldrb r0, [r0]
	cmp r0, #0
	bne _08024326
	movs r0, #0x19
	strb r0, [r5, #0xe]
	movs r0, #5
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	strb r4, [r5, #0xc]
	b _08024326
	.align 2, 0
_0802431C: .4byte 0x030031C4
_08024320:
	ldrb r0, [r5, #0xc]
	adds r0, #1
	strb r0, [r5, #0xc]
_08024326:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080242D0

	thumb_func_start sub_08024330
sub_08024330: @ 0x08024330
	push {lr}
	movs r0, #0
	bl sub_08020924
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08024330

	thumb_func_start sub_08024340
sub_08024340: @ 0x08024340
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r0, #0x33
	bl IncrementGameStat
	strb r5, [r4, #0xd]
	movs r1, #0
	strh r5, [r4, #0x10]
	movs r0, #2
	strh r0, [r4, #0x12]
	strh r5, [r4, #0x14]
	str r5, [r4, #0x1c]
	strh r5, [r4, #0x18]
	strh r5, [r4, #0x1a]
	str r5, [r4, #0x20]
	adds r0, r4, #0
	adds r0, #0x24
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x25
	movs r0, #0
	strb r0, [r1]
	strh r5, [r4, #0x26]
	strh r5, [r4, #0x28]
	strh r5, [r4, #0x2e]
	ldr r0, _080243CC
	strh r0, [r4, #0x32]
	strh r5, [r4, #0x30]
	strh r5, [r4, #0x34]
	movs r6, #0
	movs r3, #0
_08024380:
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	adds r2, r4, r0
	adds r1, r2, #0
	adds r1, #0xa0
	ldr r0, _080243CC
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xa2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r1, #6
	movs r0, #1
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0xa8
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	adds r0, #2
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #4
	bls _08024380
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080243CC: .4byte 0x0000FFFF
	thumb_func_end sub_08024340

	thumb_func_start sub_080243D0
sub_080243D0: @ 0x080243D0
	push {r4, r5, r6, lr}
	sub sp, #8
	str r2, [sp, #4]
	ldr r5, [sp, #0x18]
	ldr r6, [sp, #0x1c]
	ldr r4, [sp, #0x20]
	mov r2, sp
	strh r4, [r2]
	add r4, sp, #4
	ldrb r2, [r4]
	strb r2, [r0]
	ldrb r2, [r4, #1]
	strb r2, [r0, #1]
	ldrb r2, [r4, #2]
	strb r2, [r0, #2]
	ldrb r2, [r4, #3]
	strb r2, [r0, #3]
	strb r3, [r0, #4]
	strb r5, [r0, #5]
	strb r6, [r0, #6]
	mov r2, sp
	ldrb r2, [r2]
	strb r2, [r0, #7]
	mov r2, sp
	ldrb r2, [r2, #1]
	strb r2, [r0, #8]
	strb r1, [r0, #9]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080243D0

	thumb_func_start sub_08024410
sub_08024410: @ 0x08024410
	push {r4, r5, lr}
	sub sp, #4
	ldr r5, [sp, #0x10]
	mov r4, sp
	strh r3, [r4]
	strb r1, [r0]
	strb r2, [r0, #1]
	mov r1, sp
	ldrb r1, [r1]
	strb r1, [r0, #2]
	mov r1, sp
	ldrb r1, [r1, #1]
	strb r1, [r0, #3]
	strb r5, [r0, #4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08024410
