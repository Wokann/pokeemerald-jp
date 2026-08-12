.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified






	thumb_func_start sub_0801F0C4
sub_0801F0C4: @ 0x0801F0C4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _0801F0E8
	adds r4, r0, r1
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #7
	bls _0801F0DE
	b _0801F2D4
_0801F0DE:
	lsls r0, r0, #2
	ldr r1, _0801F0EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801F0E8: .4byte 0x03005B68
_0801F0EC: .4byte 0x0801F0F0
_0801F0F0: @ jump table
	.4byte _0801F110 @ case 0
	.4byte _0801F11E @ case 1
	.4byte _0801F2B8 @ case 2
	.4byte _0801F16C @ case 3
	.4byte _0801F258 @ case 4
	.4byte _0801F290 @ case 5
	.4byte _0801F2A4 @ case 6
	.4byte _0801F248 @ case 7
_0801F110:
	ldr r0, _0801F144
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801F11A
	b _0801F2AC
_0801F11A:
	movs r0, #1
	strh r0, [r4]
_0801F11E:
	bl GetLinkPlayerCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r0, #0
	strh r0, [r4, #8]
	ldr r3, _0801F148
	ldr r0, [r3]
	ldrb r1, [r0, #0xd]
	movs r5, #8
	ldrsh r0, [r4, r5]
	cmp r1, r0
	beq _0801F14C
	movs r0, #2
	strh r0, [r4]
	ldr r0, [r3]
	strb r2, [r0, #0xd]
	b _0801F2D4
	.align 2, 0
_0801F144: .4byte 0x030031C4
_0801F148: .4byte 0x02022938
_0801F14C:
	bl GetBlockReceivedStatus
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r4, #6]
	cmp r0, #0
	bne _0801F164
	bl Rfu_IsPlayerExchangeActive
	cmp r0, #0
	beq _0801F164
	b _0801F2D4
_0801F164:
	movs r0, #0
	strh r0, [r4, #2]
	movs r0, #3
	strh r0, [r4]
_0801F16C:
	movs r1, #2
	ldrsh r0, [r4, r1]
	cmp r0, #4
	bgt _0801F1A6
	movs r2, #6
	ldrsh r0, [r4, r2]
	movs r3, #2
	ldrsh r1, [r4, r3]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0801F1A6
	movs r2, #1
_0801F188:
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	bgt _0801F1A6
	movs r5, #6
	ldrsh r0, [r4, r5]
	movs r3, #2
	ldrsh r1, [r4, r3]
	asrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _0801F188
_0801F1A6:
	ldrh r1, [r4, #2]
	movs r5, #2
	ldrsh r0, [r4, r5]
	cmp r0, #5
	bne _0801F1B2
	b _0801F2D0
_0801F1B2:
	strh r1, [r4, #4]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl ResetBlockReceivedFlag
	movs r1, #2
	ldrsh r0, [r4, r1]
	lsls r0, r0, #8
	ldr r1, _0801F1D8
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #1
	cmp r0, #4
	bhi _0801F1F4
	lsls r0, r0, #2
	ldr r1, _0801F1DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801F1D8: .4byte 0x0202207C
_0801F1DC: .4byte 0x0801F1E0
_0801F1E0: @ jump table
	.4byte _0801F1F4 @ case 0
	.4byte _0801F1F8 @ case 1
	.4byte _0801F1FC @ case 2
	.4byte _0801F200 @ case 3
	.4byte _0801F204 @ case 4
_0801F1F4:
	movs r0, #3
	b _0801F206
_0801F1F8:
	movs r0, #3
	b _0801F206
_0801F1FC:
	movs r0, #4
	b _0801F206
_0801F200:
	movs r0, #5
	b _0801F206
_0801F204:
	movs r0, #6
_0801F206:
	strh r0, [r4, #0xa]
	ldr r5, _0801F234
	ldr r0, [r5]
	adds r0, #0x39
	movs r2, #2
	ldrsh r1, [r4, r2]
	lsls r1, r1, #8
	ldr r2, _0801F238
	adds r1, r1, r2
	bl sub_0801EE08
	cmp r0, #0
	beq _0801F23C
	ldr r0, [r5]
	ldrh r1, [r4, #2]
	strb r1, [r0, #0x16]
	movs r0, #0xc
	movs r1, #2
	bl sub_0801F3FC
	movs r0, #7
	b _0801F23E
	.align 2, 0
_0801F234: .4byte 0x02022938
_0801F238: .4byte 0x0202207C
_0801F23C:
	ldrh r0, [r4, #0xa]
_0801F23E:
	strh r0, [r4]
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	b _0801F2D4
_0801F248:
	movs r0, #2
	bl sub_0801F454
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801F2D4
	ldrh r0, [r4, #0xa]
	b _0801F2D2
_0801F258:
	ldr r6, _0801F280
	ldr r0, [r6]
	ldrb r0, [r0, #0x13]
	cmp r0, #0
	bne _0801F28C
	movs r3, #4
	ldrsh r0, [r4, r3]
	cmp r0, #0
	beq _0801F28C
	bl GetLinkPlayerCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _0801F284
	bl Rfu_StopPartnerSearch
	ldr r1, [r6]
	movs r0, #1
	b _0801F2AA
	.align 2, 0
_0801F280: .4byte 0x02022938
_0801F284:
	movs r5, #4
	ldrsh r0, [r4, r5]
	bl Rfu_DisconnectPlayerById
_0801F28C:
	movs r0, #3
	b _0801F2D2
_0801F290:
	ldr r0, _0801F2A0
	ldr r1, [r0]
	ldrb r0, [r1, #0x13]
	cmp r0, #0
	beq _0801F2AC
	movs r0, #2
	b _0801F2AA
	.align 2, 0
_0801F2A0: .4byte 0x02022938
_0801F2A4:
	ldr r0, _0801F2B4
	ldr r1, [r0]
	movs r0, #3
_0801F2AA:
	strb r0, [r1, #0x17]
_0801F2AC:
	adds r0, r5, #0
	bl DestroyTask
	b _0801F2D4
	.align 2, 0
_0801F2B4: .4byte 0x02022938
_0801F2B8:
	bl Rfu_IsPlayerExchangeActive
	cmp r0, #0
	bne _0801F2D4
	ldr r0, _0801F2DC
	ldr r1, [r0]
	ldrb r0, [r1, #0x13]
	cmp r0, #0
	bne _0801F2D0
	ldrb r0, [r1, #0xd]
	bl SetUnionRoomChatPlayerData
_0801F2D0:
	movs r0, #1
_0801F2D2:
	strh r0, [r4]
_0801F2D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801F2DC: .4byte 0x02022938
	thumb_func_end sub_0801F0C4

	thumb_func_start sub_0801F2E0
sub_0801F2E0: @ 0x0801F2E0
	push {r4, lr}
	ldr r4, _0801F32C
	ldr r0, _0801F330
	bl Alloc
	str r0, [r4]
	cmp r0, #0
	beq _0801F33C
	bl sub_080205AC
	cmp r0, #0
	beq _0801F33C
	movs r0, #0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, _0801F334
	movs r0, #0
	movs r2, #4
	bl InitBgsFromTemplates
	ldr r0, _0801F338
	bl InitWindows
	bl ResetTempTileDataBuffers
	bl sub_0802048C
	ldr r0, [r4]
	bl sub_0801F384
	bl sub_0801F390
	movs r0, #0
	movs r1, #0
	bl sub_0801F3FC
	movs r0, #1
	b _0801F33E
	.align 2, 0
_0801F32C: .4byte 0x0202293C
_0801F330: .4byte 0x00002168
_0801F334: .4byte 0x082C56F4
_0801F338: .4byte 0x082C5704
_0801F33C:
	movs r0, #0
_0801F33E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0801F2E0

	thumb_func_start sub_0801F344
sub_0801F344: @ 0x0801F344
	push {lr}
	movs r0, #0
	bl sub_0801F454
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	thumb_func_end sub_0801F344

	thumb_func_start sub_0801F354
sub_0801F354: @ 0x0801F354
	push {r4, lr}
	bl sub_080205EC
	ldr r4, _0801F37C
	ldr r0, [r4]
	cmp r0, #0
	beq _0801F36A
	bl Free
	movs r0, #0
	str r0, [r4]
_0801F36A:
	bl FreeAllWindowBuffers
	ldr r1, _0801F380
	movs r0, #3
	strb r0, [r1, #0x15]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801F37C: .4byte 0x0202293C
_0801F380: .4byte 0x020397C8
	thumb_func_end sub_0801F354

	thumb_func_start sub_0801F384
sub_0801F384: @ 0x0801F384
	movs r2, #0
	movs r1, #0xff
	strh r1, [r0, #0x18]
	strh r1, [r0, #0x1e]
	strh r2, [r0, #0x1a]
	bx lr
	thumb_func_end sub_0801F384

	thumb_func_start sub_0801F390
sub_0801F390: @ 0x0801F390
	push {r4, r5, lr}
	ldr r1, _0801F3C0
	ldr r0, [r1]
	cmp r0, #0
	beq _0801F3B8
	movs r2, #0
	adds r4, r1, #0
	ldr r5, _0801F3C4
	movs r3, #0
_0801F3A2:
	ldr r0, [r4]
	lsls r1, r2, #3
	adds r0, r0, r1
	str r5, [r0]
	strb r3, [r0, #4]
	ldr r0, [r4]
	adds r0, r0, r1
	strb r3, [r0, #5]
	adds r2, #1
	cmp r2, #2
	ble _0801F3A2
_0801F3B8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801F3C0: .4byte 0x0202293C
_0801F3C4: .4byte 0x0801FBE9
	thumb_func_end sub_0801F390

	thumb_func_start sub_0801F3C8
sub_0801F3C8: @ 0x0801F3C8
	push {r4, r5, r6, lr}
	ldr r1, _0801F3F8
	ldr r0, [r1]
	cmp r0, #0
	beq _0801F3F0
	movs r5, #0
	adds r6, r1, #0
_0801F3D6:
	ldr r1, [r6]
	lsls r4, r5, #3
	adds r1, r1, r4
	adds r0, r1, #5
	ldr r1, [r1]
	bl _call_via_r1
	ldr r1, [r6]
	adds r1, r1, r4
	strb r0, [r1, #4]
	adds r5, #1
	cmp r5, #2
	ble _0801F3D6
_0801F3F0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801F3F8: .4byte 0x0202293C
	thumb_func_end sub_0801F3C8

	thumb_func_start sub_0801F3FC
sub_0801F3FC: @ 0x0801F3FC
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x18
	ldr r3, _0801F438
	ldr r0, [r3]
	lsrs r1, r1, #0x15
	adds r0, r0, r1
	ldr r2, _0801F43C
	str r2, [r0]
	movs r4, #0
	adds r5, r3, #0
	adds r3, r1, #0
	mov ip, r4
	ldr r1, _0801F440
	movs r7, #1
	adds r2, r1, #4
_0801F41E:
	ldrh r0, [r1]
	cmp r0, r6
	bne _0801F444
	ldr r1, [r5]
	adds r1, r1, r3
	ldr r0, [r2]
	str r0, [r1]
	strb r7, [r1, #4]
	ldr r0, [r5]
	adds r0, r0, r3
	mov r1, ip
	strb r1, [r0, #5]
	b _0801F44E
	.align 2, 0
_0801F438: .4byte 0x0202293C
_0801F43C: .4byte 0x0801FBE9
_0801F440: .4byte 0x082C572C
_0801F444:
	adds r1, #8
	adds r2, #8
	adds r4, #1
	cmp r4, #0x14
	bls _0801F41E
_0801F44E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_0801F3FC

	thumb_func_start sub_0801F454
sub_0801F454: @ 0x0801F454
	lsls r0, r0, #0x18
	ldr r1, _0801F464
	ldr r1, [r1]
	lsrs r0, r0, #0x15
	adds r1, r1, r0
	ldrb r0, [r1, #4]
	bx lr
	.align 2, 0
_0801F464: .4byte 0x0202293C
	thumb_func_end sub_0801F454

	thumb_func_start sub_0801F468
sub_0801F468: @ 0x0801F468
	push {r4, lr}
	adds r4, r0, #0
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0801F4FE
	ldrb r0, [r4]
	cmp r0, #6
	bhi _0801F4F4
	lsls r0, r0, #2
	ldr r1, _0801F488
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801F488: .4byte 0x0801F48C
_0801F48C: @ jump table
	.4byte _0801F4A8 @ case 0
	.4byte _0801F4B2 @ case 1
	.4byte _0801F4B8 @ case 2
	.4byte _0801F4BE @ case 3
	.4byte _0801F4C4 @ case 4
	.4byte _0801F4CA @ case 5
	.4byte _0801F4DC @ case 6
_0801F4A8:
	bl sub_0802019C
	bl sub_08020254
	b _0801F4F8
_0801F4B2:
	bl sub_080202A0
	b _0801F4F8
_0801F4B8:
	bl sub_080202D0
	b _0801F4F8
_0801F4BE:
	bl sub_08020320
	b _0801F4F8
_0801F4C4:
	bl sub_0802039C
	b _0801F4F8
_0801F4CA:
	bl sub_080203C0
	bl sub_080203EC
	bl sub_0802045C
	bl sub_08020404
	b _0801F4F8
_0801F4DC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801F4F8
	bl sub_08020604
	bl sub_08020780
	bl sub_08020838
	b _0801F4F8
_0801F4F4:
	movs r0, #0
	b _0801F500
_0801F4F8:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0801F4FE:
	movs r0, #1
_0801F500:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F468

	thumb_func_start sub_0801F508
sub_0801F508: @ 0x0801F508
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801F518
	cmp r0, #1
	beq _0801F526
	b _0801F530
_0801F518:
	bl sub_080200D8
	movs r0, #3
	movs r1, #3
	bl CopyWindowToVram
	b _0801F530
_0801F526:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801F538
_0801F530:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r0, #1
_0801F538:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F508

	thumb_func_start sub_0801F540
sub_0801F540: @ 0x0801F540
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801F550
	cmp r0, #1
	beq _0801F55E
	b _0801F568
_0801F550:
	bl sub_0802012C
	movs r0, #3
	movs r1, #3
	bl CopyWindowToVram
	b _0801F568
_0801F55E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801F570
_0801F568:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r0, #1
_0801F570:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F540

	thumb_func_start sub_0801F578
sub_0801F578: @ 0x0801F578
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #1
	beq _0801F5AE
	cmp r0, #1
	bgt _0801F58C
	cmp r0, #0
	beq _0801F592
	b _0801F5D4
_0801F58C:
	cmp r0, #2
	beq _0801F5BA
	b _0801F5D4
_0801F592:
	movs r0, #1
	bl sub_08020638
	bl sub_08020048
	cmp r0, #0
	bne _0801F5DA
	bl sub_0801FF88
	movs r0, #2
	movs r1, #2
	bl CopyWindowToVram
	b _0801F5D4
_0801F5AE:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0801F5D4
	b _0801F5DA
_0801F5BA:
	bl sub_08020090
	cmp r0, #0
	bne _0801F5DA
	bl sub_08020658
	movs r0, #0
	bl sub_08020638
	bl sub_08020898
	movs r0, #0
	b _0801F5DC
_0801F5D4:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0801F5DA:
	movs r0, #1
_0801F5DC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F578

	thumb_func_start sub_0801F5E4
sub_0801F5E4: @ 0x0801F5E4
	push {lr}
	bl sub_08020658
	movs r0, #0
	pop {r1}
	bx r1
	thumb_func_end sub_0801F5E4

	thumb_func_start sub_0801F5F0
sub_0801F5F0: @ 0x0801F5F0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801F600
	cmp r0, #1
	beq _0801F624
	b _0801F62E
_0801F600:
	movs r0, #0
	movs r1, #0
	bl sub_0801FD40
	movs r0, #0x17
	movs r1, #0xb
	movs r2, #1
	bl sub_0801FBEC
	ldr r0, _0801F620
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	b _0801F62E
	.align 2, 0
_0801F620: .4byte 0x0202293C
_0801F624:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801F636
_0801F62E:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	movs r0, #1
_0801F636:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0801F5F0

	thumb_func_start sub_0801F63C
sub_0801F63C: @ 0x0801F63C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801F64C
	cmp r0, #1
	beq _0801F65C
	b _0801F672
_0801F64C:
	bl sub_0801FEBC
	bl sub_0801FCE4
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	b _0801F672
_0801F65C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801F678
	bl sub_0801FEF0
	bl sub_0801FD0C
	movs r0, #0
	b _0801F67A
_0801F672:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0801F678:
	movs r0, #1
_0801F67A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0801F63C

	thumb_func_start sub_0801F680
sub_0801F680: @ 0x0801F680
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801F692
	cmp r0, #1
	beq _0801F6CA
	b _0801F6DC
_0801F692:
	add r1, sp, #8
	add r0, sp, #4
	bl sub_0801EEEC
	ldr r0, [sp, #4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #0
	bl sub_0801FF14
	bl sub_0801EED0
	adds r1, r0, #0
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	movs r2, #3
	movs r3, #1
	bl sub_0801FF40
	movs r0, #1
	movs r1, #2
	bl CopyWindowToVram
	b _0801F6DC
_0801F6CA:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801F6E2
	bl sub_08020898
	movs r0, #0
	b _0801F6E4
_0801F6DC:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_0801F6E2:
	movs r0, #1
_0801F6E4:
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0801F680

	thumb_func_start sub_0801F6EC
sub_0801F6EC: @ 0x0801F6EC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r0, #1
	beq _0801F748
	cmp r0, #1
	bgt _0801F702
	cmp r0, #0
	beq _0801F70C
	b _0801F782
_0801F702:
	cmp r0, #2
	beq _0801F76C
	cmp r0, #3
	beq _0801F77E
	b _0801F782
_0801F70C:
	bl sub_0801EF44
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_0801EF14
	adds r5, r0, #0
	bl StringLength_Multibyte
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #0x66
	bl sub_0801FF14
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #4
	bl sub_0801FF40
	movs r0, #1
	movs r1, #2
	bl CopyWindowToVram
	b _0801F782
_0801F748:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801F788
	movs r0, #1
	movs r1, #0x10
	bl sub_0801FD40
	ldr r0, _0801F768
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	b _0801F782
	.align 2, 0
_0801F768: .4byte 0x0202293C
_0801F76C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801F788
	movs r0, #1
	bl sub_080206C4
	b _0801F782
_0801F77E:
	movs r0, #0
	b _0801F78A
_0801F782:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_0801F788:
	movs r0, #1
_0801F78A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F6EC

	thumb_func_start sub_0801F794
sub_0801F794: @ 0x0801F794
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r0, #1
	beq _0801F7F0
	cmp r0, #1
	bgt _0801F7AA
	cmp r0, #0
	beq _0801F7B4
	b _0801F82A
_0801F7AA:
	cmp r0, #2
	beq _0801F810
	cmp r0, #3
	beq _0801F826
	b _0801F82A
_0801F7B4:
	bl sub_0801EF44
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_0801EF14
	adds r5, r0, #0
	bl StringLength_Multibyte
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #0
	bl sub_0801FF14
	movs r0, #2
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	movs r3, #1
	bl sub_0801FF40
	movs r0, #1
	movs r1, #2
	bl CopyWindowToVram
	b _0801F82A
_0801F7F0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801F830
	bl sub_0801FEBC
	ldr r0, _0801F80C
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	b _0801F82A
	.align 2, 0
_0801F80C: .4byte 0x0202293C
_0801F810:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801F830
	movs r0, #0
	bl sub_080206C4
	bl sub_0801FEF0
	b _0801F82A
_0801F826:
	movs r0, #0
	b _0801F832
_0801F82A:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_0801F830:
	movs r0, #1
_0801F832:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F794

	thumb_func_start sub_0801F83C
sub_0801F83C: @ 0x0801F83C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801F84C
	cmp r0, #1
	beq _0801F860
	b _0801F86E
_0801F84C:
	bl sub_0801FF88
	movs r0, #2
	movs r1, #2
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801F86E
_0801F860:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801F86E
	movs r0, #0
	b _0801F870
_0801F86E:
	movs r0, #1
_0801F870:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F83C

	thumb_func_start sub_0801F878
sub_0801F878: @ 0x0801F878
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldrb r0, [r6]
	cmp r0, #4
	bhi _0801F94A
	lsls r0, r0, #2
	ldr r1, _0801F88C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801F88C: .4byte 0x0801F890
_0801F890: @ jump table
	.4byte _0801F8A4 @ case 0
	.4byte _0801F8D0 @ case 1
	.4byte _0801F900 @ case 2
	.4byte _0801F924 @ case 3
	.4byte _0801F8EE @ case 4
_0801F8A4:
	ldr r0, _0801F8CC
	ldr r0, [r0]
	ldrh r5, [r0, #0x1a]
	bl sub_0801EF80
	adds r4, r0, #0
	bl sub_0801EF8C
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_08020140
	movs r0, #0
	movs r1, #2
	bl CopyWindowToVram
	b _0801F944
	.align 2, 0
_0801F8CC: .4byte 0x0202293C
_0801F8D0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _0801F94A
	ldr r0, _0801F8F4
	ldr r1, [r0]
	ldrh r0, [r1, #0x1a]
	cmp r0, #0xa
	bhi _0801F8F8
	adds r0, #1
	strh r0, [r1, #0x1a]
	movs r0, #4
	strb r0, [r6]
_0801F8EE:
	movs r0, #0
	b _0801F94C
	.align 2, 0
_0801F8F4: .4byte 0x0202293C
_0801F8F8:
	strh r2, [r1, #0x1c]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_0801F900:
	movs r0, #0
	movs r1, #0
	movs r2, #4
	movs r3, #0x11
	bl ScrollWindow
	movs r0, #0
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, _0801F940
	ldr r1, [r0]
	ldrh r0, [r1, #0x1c]
	adds r0, #1
	strh r0, [r1, #0x1c]
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
_0801F924:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801F94A
	ldr r0, _0801F940
	ldr r0, [r0]
	ldrh r0, [r0, #0x1c]
	cmp r0, #2
	bhi _0801F944
	ldrb r0, [r6]
	subs r0, #1
	b _0801F948
	.align 2, 0
_0801F940: .4byte 0x0202293C
_0801F944:
	ldrb r0, [r6]
	adds r0, #1
_0801F948:
	strb r0, [r6]
_0801F94A:
	movs r0, #1
_0801F94C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F878

	thumb_func_start sub_0801F954
sub_0801F954: @ 0x0801F954
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801F964
	cmp r0, #1
	beq _0801F970
	b _0801F976
_0801F964:
	bl sub_080206F8
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801F976
_0801F970:
	bl sub_08020734
	b _0801F978
_0801F976:
	movs r0, #1
_0801F978:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F954

	thumb_func_start sub_0801F980
sub_0801F980: @ 0x0801F980
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801F990
	cmp r0, #1
	beq _0801F9B0
	b _0801F9BA
_0801F990:
	movs r0, #3
	movs r1, #0x10
	bl sub_0801FD40
	ldr r0, _0801F9AC
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801F9BA
	.align 2, 0
_0801F9AC: .4byte 0x0202293C
_0801F9B0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801F9BC
_0801F9BA:
	movs r0, #1
_0801F9BC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F980

	thumb_func_start sub_0801F9C4
sub_0801F9C4: @ 0x0801F9C4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801F9D4
	cmp r0, #1
	beq _0801F9F4
	b _0801F9FE
_0801F9D4:
	movs r0, #4
	movs r1, #0
	bl sub_0801FD40
	ldr r0, _0801F9F0
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801F9FE
	.align 2, 0
_0801F9F0: .4byte 0x0202293C
_0801F9F4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801FA00
_0801F9FE:
	movs r0, #1
_0801FA00:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801F9C4

	thumb_func_start sub_0801FA08
sub_0801FA08: @ 0x0801FA08
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801FA18
	cmp r0, #1
	beq _0801FA48
	b _0801FA52
_0801FA18:
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_0801EFE0
	adds r1, r0, #0
	movs r0, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, #5
	movs r1, #0
	bl sub_0801FD40
	ldr r0, _0801FA44
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801FA52
	.align 2, 0
_0801FA44: .4byte 0x0202293C
_0801FA48:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801FA54
_0801FA52:
	movs r0, #1
_0801FA54:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801FA08

	thumb_func_start sub_0801FA5C
sub_0801FA5C: @ 0x0801FA5C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801FA6C
	cmp r0, #1
	beq _0801FA98
	b _0801FAA2
_0801FA6C:
	movs r0, #6
	movs r1, #0
	bl sub_0801FD40
	movs r0, #0x17
	movs r1, #0xa
	movs r2, #1
	bl sub_0801FBEC
	ldr r0, _0801FA94
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801FAA2
	.align 2, 0
_0801FA94: .4byte 0x0202293C
_0801FA98:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801FAA4
_0801FAA2:
	movs r0, #1
_0801FAA4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801FA5C

	thumb_func_start sub_0801FAAC
sub_0801FAAC: @ 0x0801FAAC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801FABC
	cmp r0, #1
	beq _0801FAE8
	b _0801FAF2
_0801FABC:
	movs r0, #7
	movs r1, #0
	bl sub_0801FD40
	movs r0, #0x17
	movs r1, #0xa
	movs r2, #1
	bl sub_0801FBEC
	ldr r0, _0801FAE4
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801FAF2
	.align 2, 0
_0801FAE4: .4byte 0x0202293C
_0801FAE8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801FAF4
_0801FAF2:
	movs r0, #1
_0801FAF4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801FAAC

	thumb_func_start sub_0801FAFC
sub_0801FAFC: @ 0x0801FAFC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801FB0C
	cmp r0, #1
	beq _0801FB2C
	b _0801FB36
_0801FB0C:
	movs r0, #8
	movs r1, #0
	bl sub_0801FD40
	ldr r0, _0801FB28
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801FB36
	.align 2, 0
_0801FB28: .4byte 0x0202293C
_0801FB2C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801FB38
_0801FB36:
	movs r0, #1
_0801FB38:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801FAFC

	thumb_func_start sub_0801FB40
sub_0801FB40: @ 0x0801FB40
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801FB50
	cmp r0, #1
	beq _0801FB84
	b _0801FB8E
_0801FB50:
	bl DynamicPlaceholderTextUtil_Reset
	ldr r0, _0801FB7C
	ldr r1, [r0]
	movs r0, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, #9
	movs r1, #0
	bl sub_0801FD40
	ldr r0, _0801FB80
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801FB8E
	.align 2, 0
_0801FB7C: .4byte 0x03005AF0
_0801FB80: .4byte 0x0202293C
_0801FB84:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801FB90
_0801FB8E:
	movs r0, #1
_0801FB90:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801FB40

	thumb_func_start sub_0801FB98
sub_0801FB98: @ 0x0801FB98
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801FBA8
	cmp r0, #1
	beq _0801FBD4
	b _0801FBDE
_0801FBA8:
	movs r0, #0xa
	movs r1, #0
	bl sub_0801FD40
	movs r0, #0x17
	movs r1, #0xa
	movs r2, #1
	bl sub_0801FBEC
	ldr r0, _0801FBD0
	ldr r0, [r0]
	ldrb r0, [r0, #0x1e]
	movs r1, #3
	bl CopyWindowToVram
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0801FBDE
	.align 2, 0
_0801FBD0: .4byte 0x0202293C
_0801FBD4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0801FBE0
_0801FBDE:
	movs r0, #1
_0801FBE0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801FB98

	thumb_func_start sub_0801FBE8
sub_0801FBE8: @ 0x0801FBE8
	movs r0, #0
	bx lr
	thumb_func_end sub_0801FBE8

	thumb_func_start sub_0801FBEC
sub_0801FBEC: @ 0x0801FBEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	ldr r4, _0801FCC4
	ldr r2, [sp, #0xc]
	ands r2, r4
	lsrs r0, r0, #0x10
	ldr r3, _0801FCC8
	ands r2, r3
	orrs r2, r0
	lsrs r1, r1, #8
	ldr r0, _0801FCCC
	ands r2, r0
	orrs r2, r1
	ldr r0, _0801FCD0
	ands r2, r0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	orrs r2, r0
	str r2, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r1, #4
	orrs r0, r1
	ands r0, r3
	movs r1, #0xe0
	lsls r1, r1, #4
	orrs r0, r1
	ldr r1, _0801FCD4
	ands r0, r1
	movs r1, #0xb2
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0xc
	bl AddWindow
	adds r1, r0, #0
	ldr r6, _0801FCD8
	ldr r0, [r6]
	movs r7, #0
	strh r1, [r0, #0x18]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	beq _0801FCB8
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	ldrb r0, [r0, #0x18]
	bl PutWindowTilemap
	ldr r0, [r6]
	ldrb r0, [r0, #0x18]
	ldr r2, _0801FCDC
	movs r5, #2
	str r5, [sp]
	movs r4, #0xff
	str r4, [sp, #4]
	str r7, [sp, #8]
	movs r1, #1
	movs r3, #0xa
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	ldrb r0, [r0, #0x18]
	ldr r2, _0801FCE0
	movs r1, #0x10
	str r1, [sp]
	str r4, [sp, #4]
	str r7, [sp, #8]
	movs r1, #1
	movs r3, #0xa
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	ldrb r0, [r0, #0x18]
	movs r1, #1
	movs r2, #0xd
	bl DrawTextBorderOuter
	ldr r0, [r6]
	ldrb r0, [r0, #0x18]
	movs r1, #0xe
	str r1, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl sub_081984B0
_0801FCB8:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FCC4: .4byte 0xFFFFFF00
_0801FCC8: .4byte 0xFFFF00FF
_0801FCCC: .4byte 0xFF00FFFF
_0801FCD0: .4byte 0x00FFFFFF
_0801FCD4: .4byte 0x0000FFFF
_0801FCD8: .4byte 0x0202293C
_0801FCDC: .4byte 0x085CAAD8
_0801FCE0: .4byte 0x085CAADB
	thumb_func_end sub_0801FBEC

	thumb_func_start sub_0801FCE4
sub_0801FCE4: @ 0x0801FCE4
	push {r4, lr}
	ldr r4, _0801FD08
	ldr r0, [r4]
	ldrh r0, [r0, #0x18]
	cmp r0, #0xff
	beq _0801FD02
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl ClearStdWindowAndFrameToTransparent
	ldr r0, [r4]
	ldrb r0, [r0, #0x18]
	bl ClearWindowTilemap
_0801FD02:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801FD08: .4byte 0x0202293C
	thumb_func_end sub_0801FCE4

	thumb_func_start sub_0801FD0C
sub_0801FD0C: @ 0x0801FD0C
	push {r4, lr}
	ldr r4, _0801FD2C
	ldr r0, [r4]
	ldrh r0, [r0, #0x18]
	cmp r0, #0xff
	beq _0801FD26
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, #0xff
	strh r0, [r1, #0x18]
_0801FD26:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801FD2C: .4byte 0x0202293C
	thumb_func_end sub_0801FD0C

	thumb_func_start sub_0801FD30
sub_0801FD30: @ 0x0801FD30
	push {lr}
	bl Menu_ProcessInput
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801FD30

	thumb_func_start sub_0801FD40
sub_0801FD40: @ 0x0801FD40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov sb, r1
	ldr r1, _0801FDEC
	ldr r3, [sp, #0x14]
	ands r3, r1
	ldr r2, _0801FDF0
	ands r3, r2
	movs r0, #0x80
	lsls r0, r0, #4
	orrs r3, r0
	ldr r0, _0801FDF4
	ands r3, r0
	movs r0, #0x80
	lsls r0, r0, #0xd
	orrs r3, r0
	ldr r5, _0801FDF8
	ands r3, r5
	movs r0, #0xa8
	lsls r0, r0, #0x15
	orrs r3, r0
	str r3, [sp, #0x14]
	ldr r0, [sp, #0x18]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	ands r0, r2
	movs r1, #0xe0
	lsls r1, r1, #4
	orrs r0, r1
	ldr r1, _0801FDFC
	ands r0, r1
	movs r1, #0xe2
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r1, _0801FE00
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r4, r0, r1
	ldrb r0, [r4, #0xa]
	cmp r0, #0
	beq _0801FDC0
	lsls r0, r3, #0x10
	movs r1, #0xf9
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	ands r2, r3
	orrs r2, r0
	lsrs r1, r2, #0x18
	adds r1, #7
	lsls r1, r1, #0x18
	adds r0, r5, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
_0801FDC0:
	add r0, sp, #0x14
	bl AddWindow
	ldr r5, _0801FE04
	ldr r1, [r5]
	strh r0, [r1, #0x1e]
	ldrh r0, [r1, #0x1e]
	mov r8, r0
	cmp r0, #0xff
	beq _0801FEAA
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0801FE08
	adds r0, r1, #0
	adds r0, #0x22
	ldr r1, [r4]
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, [r5]
	adds r6, r0, #0
	adds r6, #0x22
	b _0801FE0A
	.align 2, 0
_0801FDEC: .4byte 0xFFFFFF00
_0801FDF0: .4byte 0xFFFF00FF
_0801FDF4: .4byte 0xFF00FFFF
_0801FDF8: .4byte 0x00FFFFFF
_0801FDFC: .4byte 0x0000FFFF
_0801FE00: .4byte 0x082C57D4
_0801FE04: .4byte 0x0202293C
_0801FE08:
	ldr r6, [r4]
_0801FE0A:
	mov r0, sb
	lsls r1, r0, #8
	movs r0, #0
	movs r2, #0
	bl ChangeBgY
	mov r1, r8
	lsls r0, r1, #0x18
	lsrs r5, r0, #0x18
	adds r0, r5, #0
	movs r1, #0x11
	bl FillWindowPixelBuffer
	adds r0, r5, #0
	bl PutWindowTilemap
	ldr r1, _0801FE74
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r4, r0, r1
	ldrb r0, [r4, #4]
	cmp r0, #1
	bne _0801FE78
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #2
	bl DrawTextBorderInner
	ldrb r3, [r4, #5]
	adds r3, #8
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r0, [r4, #6]
	adds r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldrb r0, [r4, #7]
	str r0, [sp, #0xc]
	ldrb r0, [r4, #8]
	str r0, [sp, #0x10]
	adds r0, r5, #0
	movs r1, #1
	adds r2, r6, #0
	bl AddTextPrinterParameterized5
	b _0801FEA2
	.align 2, 0
_0801FE74: .4byte 0x082C57D4
_0801FE78:
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #2
	bl DrawTextBorderOuter
	ldrb r3, [r4, #5]
	ldrb r0, [r4, #6]
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	ldrb r0, [r4, #7]
	str r0, [sp, #0xc]
	ldrb r0, [r4, #8]
	str r0, [sp, #0x10]
	adds r0, r5, #0
	movs r1, #1
	adds r2, r6, #0
	bl AddTextPrinterParameterized5
_0801FEA2:
	ldr r0, _0801FEB8
	ldr r0, [r0]
	mov r1, r8
	strh r1, [r0, #0x1e]
_0801FEAA:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801FEB8: .4byte 0x0202293C
	thumb_func_end sub_0801FD40

	thumb_func_start sub_0801FEBC
sub_0801FEBC: @ 0x0801FEBC
	push {r4, lr}
	ldr r4, _0801FEEC
	ldr r0, [r4]
	ldrh r0, [r0, #0x1e]
	cmp r0, #0xff
	beq _0801FEDA
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl ClearStdWindowAndFrameToTransparent
	ldr r0, [r4]
	ldrb r0, [r0, #0x1e]
	bl ClearWindowTilemap
_0801FEDA:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801FEEC: .4byte 0x0202293C
	thumb_func_end sub_0801FEBC

	thumb_func_start sub_0801FEF0
sub_0801FEF0: @ 0x0801FEF0
	push {r4, lr}
	ldr r4, _0801FF10
	ldr r0, [r4]
	ldrh r0, [r0, #0x1e]
	cmp r0, #0xff
	beq _0801FF0A
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, #0xff
	strh r0, [r1, #0x1e]
_0801FF0A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801FF10: .4byte 0x0202293C
	thumb_func_end sub_0801FEF0

	thumb_func_start sub_0801FF14
sub_0801FF14: @ 0x0801FF14
	push {lr}
	sub sp, #8
	adds r3, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x13
	lsrs r3, r3, #0x10
	lsls r1, r1, #0x13
	lsrs r1, r1, #0x10
	str r1, [sp]
	movs r0, #0xe
	str r0, [sp, #4]
	movs r0, #1
	adds r1, r2, #0
	adds r2, r3, #0
	movs r3, #1
	bl FillWindowPixelRect
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0801FF14

	thumb_func_start sub_0801FF40
sub_0801FF40: @ 0x0801FF40
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, [sp, #0x1c]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	add r0, sp, #0xc
	strb r2, [r0]
	strb r3, [r0, #1]
	strb r1, [r0, #2]
	adds r0, r5, #0
	bl StringLength_Multibyte
	lsls r4, r4, #0x1b
	lsrs r4, r4, #0x18
	add r0, sp, #0xc
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #1
	movs r1, #0
	adds r2, r4, #0
	movs r3, #1
	bl AddTextPrinterParameterized3
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_0801FF40

	thumb_func_start sub_0801FF88
sub_0801FF88: @ 0x0801FF88
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	movs r0, #2
	movs r1, #0xff
	bl FillWindowPixelBuffer
	bl sub_0801EEB0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	add r1, sp, #0xc
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xe
	strb r0, [r1, #1]
	movs r0, #0xd
	strb r0, [r1, #2]
	cmp r2, #4
	beq _0801FFF4
	movs r5, #0
	movs r6, #0
	lsls r0, r2, #2
	ldr r1, _0801FFF0
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r4, r0, r1
_0801FFBC:
	ldr r1, [r4]
	cmp r1, #0
	beq _0802003A
	lsls r3, r6, #0x18
	lsrs r3, r3, #0x18
	add r0, sp, #0xc
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r2, #6
	bl AddTextPrinterParameterized3
	adds r4, #4
	adds r5, #1
	adds r0, r6, #0
	adds r0, #0xb
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r5, #9
	ble _0801FFBC
	b _0802003A
	.align 2, 0
_0801FFF0: .4byte 0x082C5180
_0801FFF4:
	movs r5, #0
	movs r6, #0
	ldr r7, _08020044
_0801FFFA:
	ldr r4, [r7]
	adds r4, #0x22
	adds r0, r5, #0
	bl sub_0801EC7C
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #5
	bl StringCopyN_Multibyte
	lsls r3, r6, #0x18
	lsrs r3, r3, #0x18
	add r0, sp, #0xc
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	ldr r0, [r7]
	adds r0, #0x22
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r2, #6
	bl AddTextPrinterParameterized3
	adds r5, #1
	adds r0, r6, #0
	adds r0, #0xb
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r5, #9
	ble _0801FFFA
_0802003A:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08020044: .4byte 0x0202293C
	thumb_func_end sub_0801FF88

	thumb_func_start sub_08020048
sub_08020048: @ 0x08020048
	push {r4, lr}
	ldr r1, _0802006C
	ldr r2, [r1]
	ldrh r3, [r2, #0x20]
	movs r4, #0x20
	ldrsh r0, [r2, r4]
	cmp r0, #0x37
	bgt _0802007C
	adds r0, r3, #0
	adds r0, #0xc
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x37
	ble _08020070
	movs r0, #0x38
	strh r0, [r2, #0x20]
	b _0802007C
	.align 2, 0
_0802006C: .4byte 0x0202293C
_08020070:
	movs r1, #0x20
	ldrsh r0, [r2, r1]
	bl sub_080204DC
	movs r0, #1
	b _08020088
_0802007C:
	ldr r0, [r1]
	movs r4, #0x20
	ldrsh r0, [r0, r4]
	bl sub_08020534
	movs r0, #0
_08020088:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08020048

	thumb_func_start sub_08020090
sub_08020090: @ 0x08020090
	push {r4, lr}
	ldr r1, _080200B4
	ldr r2, [r1]
	ldrh r3, [r2, #0x20]
	movs r4, #0x20
	ldrsh r0, [r2, r4]
	cmp r0, #0
	ble _080200C4
	adds r0, r3, #0
	subs r0, #0xc
	strh r0, [r2, #0x20]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080200B8
	movs r0, #0
	strh r0, [r2, #0x20]
	b _080200C4
	.align 2, 0
_080200B4: .4byte 0x0202293C
_080200B8:
	movs r1, #0x20
	ldrsh r0, [r2, r1]
	bl sub_080204DC
	movs r0, #1
	b _080200D0
_080200C4:
	ldr r0, [r1]
	movs r4, #0x20
	ldrsh r0, [r0, r4]
	bl sub_08020534
	movs r0, #0
_080200D0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08020090

	thumb_func_start sub_080200D8
sub_080200D8: @ 0x080200D8
	push {lr}
	sub sp, #0xc
	movs r0, #3
	movs r1, #0x11
	bl FillWindowPixelBuffer
	movs r0, #3
	movs r1, #1
	movs r2, #0xd
	bl DrawTextBorderOuter
	ldr r0, _08020128
	str r0, [sp]
	movs r0, #3
	movs r1, #1
	movs r2, #0xd
	movs r3, #6
	bl sub_08198964
	bl sub_0801EEB0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xd
	str r1, [sp]
	movs r1, #6
	str r1, [sp, #4]
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_081984B0
	movs r0, #3
	bl PutWindowTilemap
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_08020128: .4byte 0x082C5858
	thumb_func_end sub_080200D8

	thumb_func_start sub_0802012C
sub_0802012C: @ 0x0802012C
	push {lr}
	movs r0, #3
	movs r1, #0
	bl ClearStdWindowAndFrameToTransparent
	movs r0, #3
	bl ClearWindowTilemap
	pop {r0}
	bx r0
	thumb_func_end sub_0802012C

	thumb_func_start sub_08020140
sub_08020140: @ 0x08020140
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r2, r2, #0x18
	add r3, sp, #0xc
	movs r1, #1
	strb r1, [r3]
	lsrs r2, r2, #0x17
	adds r1, r2, #2
	strb r1, [r3, #1]
	adds r1, r3, #0
	adds r2, #3
	strb r2, [r1, #2]
	lsls r4, r0, #1
	adds r4, r4, r0
	lsls r3, r4, #0x12
	lsrs r3, r3, #0x10
	movs r0, #0xa8
	str r0, [sp]
	movs r0, #0xc
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0x11
	movs r2, #0
	bl FillWindowPixelRect
	lsls r4, r4, #0x1a
	lsrs r4, r4, #0x18
	add r0, sp, #0xc
	str r0, [sp]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	adds r3, r4, #0
	bl AddTextPrinterParameterized3
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08020140

	thumb_func_start sub_0802019C
sub_0802019C: @ 0x0802019C
	push {lr}
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
	movs r0, #0
	bl ShowBg
	movs r0, #1
	bl ShowBg
	movs r0, #2
	bl ShowBg
	movs r0, #3
	bl ShowBg
	movs r1, #0x82
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuRegBits
	movs r0, #0x50
	movs r1, #0
	bl SetGpuReg
	movs r1, #0xe0
	lsls r1, r1, #8
	movs r0, #0
	bl ClearGpuRegBits
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0
	bl SetGpuRegBits
	ldr r1, _08020250
	movs r0, #0x40
	bl SetGpuReg
	movs r0, #0x44
	movs r1, #0x90
	bl SetGpuReg
	movs r0, #0x48
	movs r1, #0x3d
	bl SetGpuReg
	movs r0, #0x4a
	movs r1, #0x3f
	bl SetGpuReg
	pop {r0}
	bx r0
	.align 2, 0
_08020250: .4byte 0x000040F0
	thumb_func_end sub_0802019C

	thumb_func_start sub_08020254
sub_08020254: @ 0x08020254
	push {r4, lr}
	ldr r4, _08020290
	ldr r1, [r4]
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #0
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, _08020294
	adds r1, r1, r0
	movs r0, #1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, _08020298
	adds r1, r1, r0
	movs r0, #3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	ldr r0, _0802029C
	adds r1, r1, r0
	movs r0, #2
	bl SetBgTilemapBuffer
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020290: .4byte 0x0202293C
_08020294: .4byte 0x00000928
_08020298: .4byte 0x00001128
_0802029C: .4byte 0x00001928
	thumb_func_end sub_08020254

	thumb_func_start sub_080202A0
sub_080202A0: @ 0x080202A0
	push {lr}
	sub sp, #8
	movs r1, #0xc0
	lsls r1, r1, #0x13
	movs r0, #0
	movs r2, #0x20
	movs r3, #1
	bl RequestDma3Fill
	movs r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	add sp, #8
	pop {r0}
	bx r0
	thumb_func_end sub_080202A0

	thumb_func_start sub_080202D0
sub_080202D0: @ 0x080202D0
	push {lr}
	sub sp, #4
	ldr r0, _08020310
	movs r1, #0x70
	movs r2, #0x20
	bl LoadPalette
	ldr r0, _08020314
	movs r1, #0xc0
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _08020318
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	ldr r1, _0802031C
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08020310: .4byte 0x082C5220
_08020314: .4byte 0x082C5348
_08020318: .4byte 0x082C5240
_0802031C: .4byte 0x082C529C
	thumb_func_end sub_080202D0

	thumb_func_start sub_08020320
sub_08020320: @ 0x08020320
	push {r4, r5, lr}
	sub sp, #4
	ldr r0, _08020384
	movs r1, #0
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _08020388
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	adds r5, r0, #0
	cmp r5, #0
	beq _0802036A
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r4, _0802038C
	ldr r1, [r4]
	ldr r2, _08020390
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r4]
	ldr r2, _08020394
	adds r1, r1, r2
	movs r2, #8
	bl CpuFastSet
_0802036A:
	ldr r1, _08020398
	movs r0, #2
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	movs r0, #2
	bl CopyBgTilemapBufferToVram
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08020384: .4byte 0x082C5368
_08020388: .4byte 0x082C5388
_0802038C: .4byte 0x0202293C
_08020390: .4byte 0x00002128
_08020394: .4byte 0x00002148
_08020398: .4byte 0x082C55BC
	thumb_func_end sub_08020320

	thumb_func_start sub_0802039C
sub_0802039C: @ 0x0802039C
	push {lr}
	ldr r0, _080203B8
	movs r1, #0x80
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _080203BC
	movs r0, #0
	movs r2, #0x20
	movs r3, #1
	bl RequestDma3Fill
	pop {r0}
	bx r0
	.align 2, 0
_080203B8: .4byte 0x082C56B4
_080203BC: .4byte 0x06004020
	thumb_func_end sub_0802039C

	thumb_func_start sub_080203C0
sub_080203C0: @ 0x080203C0
	push {lr}
	ldr r0, _080203E8
	movs r1, #0xf0
	movs r2, #0x20
	bl LoadPalette
	movs r0, #0
	bl PutWindowTilemap
	movs r0, #0
	movs r1, #0x11
	bl FillWindowPixelBuffer
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	.align 2, 0
_080203E8: .4byte 0x082C56D4
	thumb_func_end sub_080203C0

	thumb_func_start sub_080203EC
sub_080203EC: @ 0x080203EC
	push {lr}
	movs r0, #2
	bl PutWindowTilemap
	bl sub_0801FF88
	movs r0, #2
	movs r1, #3
	bl CopyWindowToVram
	pop {r0}
	bx r0
	thumb_func_end sub_080203EC

	thumb_func_start sub_08020404
sub_08020404: @ 0x08020404
	push {r4, lr}
	sub sp, #0xc
	add r1, sp, #8
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xff
	strb r0, [r1, #1]
	movs r4, #0
_08020414:
	ldr r0, _08020454
	ldr r1, [r0]
	ldr r0, _08020458
	adds r1, r1, r0
	lsls r2, r4, #0x13
	lsrs r2, r2, #0x10
	movs r0, #8
	str r0, [sp]
	movs r0, #0x10
	str r0, [sp, #4]
	movs r0, #1
	movs r3, #0
	bl BlitBitmapToWindow
	adds r4, #1
	cmp r4, #0xe
	ble _08020414
	movs r0, #1
	movs r1, #0
	bl FillWindowPixelBuffer
	movs r0, #1
	bl PutWindowTilemap
	movs r0, #1
	movs r1, #3
	bl CopyWindowToVram
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020454: .4byte 0x0202293C
_08020458: .4byte 0x00002128
	thumb_func_end sub_08020404

	thumb_func_start sub_0802045C
sub_0802045C: @ 0x0802045C
	push {lr}
	movs r0, #3
	movs r1, #0x11
	bl FillWindowPixelBuffer
	movs r0, #3
	movs r1, #1
	movs r2, #0xd0
	bl LoadUserWindowBorderGfx
	movs r0, #3
	movs r1, #0xa
	movs r2, #0x20
	bl LoadUserWindowBorderGfx_
	ldr r0, _08020488
	movs r1, #0xe0
	movs r2, #0x20
	bl LoadPalette
	pop {r0}
	bx r0
	.align 2, 0
_08020488: .4byte 0x085D7B04
	thumb_func_end sub_0802045C

	thumb_func_start sub_0802048C
sub_0802048C: @ 0x0802048C
	push {lr}
	sub sp, #0x10
	ldr r0, _080204C8
	str r0, [sp, #4]
	ldr r0, _080204CC
	str r0, [sp]
	mov r2, sp
	movs r1, #0
	movs r0, #1
	strb r0, [r2, #8]
	mov r0, sp
	strb r1, [r0, #9]
	ldr r0, _080204D0
	ldr r0, [r0]
	strh r1, [r0, #0x20]
	str r1, [sp, #0xc]
	add r0, sp, #0xc
	ldr r1, _080204D4
	ldr r2, _080204D8
	bl CpuFastSet
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl ScanlineEffect_SetParams
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_080204C8: .4byte 0xA2600001
_080204CC: .4byte 0x04000014
_080204D0: .4byte 0x0202293C
_080204D4: .4byte 0x020388C8
_080204D8: .4byte 0x010003C0
	thumb_func_end sub_0802048C

	thumb_func_start sub_080204DC
sub_080204DC: @ 0x080204DC
	push {r4, r5, lr}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	strh r0, [r1]
	ldr r5, _08020524
	ldrb r0, [r5, #0x14]
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #7
	ldr r4, _08020528
	adds r1, r1, r4
	ldr r2, _0802052C
	mov r0, sp
	bl CpuSet
	mov r0, sp
	adds r0, #2
	movs r1, #0
	strh r1, [r0]
	ldrb r2, [r5, #0x14]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #7
	movs r2, #0x90
	lsls r2, r2, #1
	adds r4, r4, r2
	adds r1, r1, r4
	ldr r2, _08020530
	bl CpuSet
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08020524: .4byte 0x020397C8
_08020528: .4byte 0x020388C8
_0802052C: .4byte 0x01000090
_08020530: .4byte 0x01000010
	thumb_func_end sub_080204DC

	thumb_func_start sub_08020534
sub_08020534: @ 0x08020534
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r0, sp
	strh r4, [r0]
	ldr r5, _080205A0
	ldr r0, _080205A4
	mov sb, r0
	mov r0, sp
	adds r1, r5, #0
	mov r2, sb
	bl CpuSet
	mov r0, sp
	adds r0, #2
	movs r6, #0
	strh r6, [r0]
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r2, _080205A8
	mov r8, r2
	bl CpuSet
	add r0, sp, #4
	strh r4, [r0]
	movs r2, #0xf0
	lsls r2, r2, #3
	adds r1, r5, r2
	mov r2, sb
	bl CpuSet
	mov r0, sp
	adds r0, #6
	strh r6, [r0]
	movs r1, #0x8a
	lsls r1, r1, #4
	adds r5, r5, r1
	adds r1, r5, #0
	mov r2, r8
	bl CpuSet
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080205A0: .4byte 0x020388C8
_080205A4: .4byte 0x01000090
_080205A8: .4byte 0x01000010
	thumb_func_end sub_08020534

	thumb_func_start sub_080205AC
sub_080205AC: @ 0x080205AC
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _080205D8
_080205B2:
	adds r0, r4, #0
	bl LoadCompressedSpriteSheet
	adds r4, #8
	adds r5, #1
	cmp r5, #4
	bls _080205B2
	ldr r0, _080205DC
	bl LoadSpritePalette
	ldr r4, _080205E0
	movs r0, #0x18
	bl Alloc
	str r0, [r4]
	cmp r0, #0
	beq _080205E4
	movs r0, #1
	b _080205E6
	.align 2, 0
_080205D8: .4byte 0x082C5D4C
_080205DC: .4byte 0x082C5D74
_080205E0: .4byte 0x02022940
_080205E4:
	movs r0, #0
_080205E6:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_080205AC

	thumb_func_start sub_080205EC
sub_080205EC: @ 0x080205EC
	push {lr}
	ldr r0, _08020600
	ldr r0, [r0]
	cmp r0, #0
	beq _080205FA
	bl Free
_080205FA:
	pop {r0}
	bx r0
	.align 2, 0
_08020600: .4byte 0x02022940
	thumb_func_end sub_080205EC

	thumb_func_start sub_08020604
sub_08020604: @ 0x08020604
	push {lr}
	ldr r0, _0802062C
	movs r1, #0xa
	movs r2, #0x18
	movs r3, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08020630
	ldr r2, [r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _08020634
	adds r1, r1, r0
	str r1, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_0802062C: .4byte 0x082C5DB4
_08020630: .4byte 0x02022940
_08020634: .4byte 0x020205AC
	thumb_func_end sub_08020604

	thumb_func_start sub_08020638
sub_08020638: @ 0x08020638
	ldr r1, _08020654
	ldr r1, [r1]
	ldr r2, [r1]
	adds r2, #0x3e
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	ldrb r3, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r3
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.align 2, 0
_08020654: .4byte 0x02022940
	thumb_func_end sub_08020638

	thumb_func_start sub_08020658
sub_08020658: @ 0x08020658
	push {r4, r5, lr}
	sub sp, #4
	bl sub_0801EEB0
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov r5, sp
	adds r5, #1
	mov r0, sp
	adds r1, r5, #0
	bl sub_0801EEBC
	cmp r4, #4
	beq _08020698
	ldr r4, _08020694
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, #0
	bl StartSpriteAnim
	ldr r1, [r4]
	ldr r2, [r1]
	mov r0, sp
	ldrb r0, [r0]
	lsls r0, r0, #3
	adds r0, #0xa
	strh r0, [r2, #0x20]
	ldr r2, [r1]
	b _080206AE
	.align 2, 0
_08020694: .4byte 0x02022940
_08020698:
	ldr r4, _080206C0
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, #2
	bl StartSpriteAnim
	ldr r2, [r4]
	ldr r1, [r2]
	movs r0, #0x18
	strh r0, [r1, #0x20]
	ldr r2, [r2]
_080206AE:
	ldrb r1, [r5]
	movs r0, #0xb
	muls r0, r1, r0
	adds r0, #0x18
	strh r0, [r2, #0x22]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080206C0: .4byte 0x02022940
	thumb_func_end sub_08020658

	thumb_func_start sub_080206C4
sub_080206C4: @ 0x080206C4
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #2
	ldr r0, _080206F0
	adds r4, r4, r0
	movs r0, #0
	bl IndexOfSpritePaletteTag
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #4
	ldr r0, _080206F4
	adds r1, r1, r0
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #4
	bl LoadPalette
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080206F0: .4byte 0x082C588A
_080206F4: .4byte 0x01010000
	thumb_func_end sub_080206C4

	thumb_func_start sub_080206F8
sub_080206F8: @ 0x080206F8
	push {lr}
	bl sub_0801EEB0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _08020718
	ldr r0, _08020714
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #1
	bl StartSpriteAnim
	b _08020724
	.align 2, 0
_08020714: .4byte 0x02022940
_08020718:
	ldr r0, _08020730
	ldr r0, [r0]
	ldr r0, [r0]
	movs r1, #3
	bl StartSpriteAnim
_08020724:
	ldr r0, _08020730
	ldr r1, [r0]
	movs r0, #0
	strh r0, [r1, #0x14]
	pop {r0}
	bx r0
	.align 2, 0
_08020730: .4byte 0x02022940
	thumb_func_end sub_080206F8

	thumb_func_start sub_08020734
sub_08020734: @ 0x08020734
	push {r4, lr}
	ldr r4, _08020744
	ldr r1, [r4]
	ldrh r0, [r1, #0x14]
	cmp r0, #3
	bls _08020748
_08020740:
	movs r0, #0
	b _0802077A
	.align 2, 0
_08020744: .4byte 0x02022940
_08020748:
	adds r0, #1
	strh r0, [r1, #0x14]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _08020778
	bl sub_0801EEB0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	beq _0802076C
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, #0
	bl StartSpriteAnim
	b _08020740
_0802076C:
	ldr r0, [r4]
	ldr r0, [r0]
	movs r1, #2
	bl StartSpriteAnim
	b _08020740
_08020778:
	movs r0, #1
_0802077A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_08020734

	thumb_func_start sub_08020780
sub_08020780: @ 0x08020780
	push {r4, r5, lr}
	ldr r0, _080207C4
	movs r1, #0x4c
	movs r2, #0x98
	movs r3, #2
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _080207C8
	ldr r2, [r5]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _080207CC
	adds r1, r1, r4
	str r1, [r2, #8]
	ldr r0, _080207D0
	movs r1, #0x40
	movs r2, #0x98
	movs r3, #1
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, [r5]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	str r1, [r2, #4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080207C4: .4byte 0x082C5DD4
_080207C8: .4byte 0x02022940
_080207CC: .4byte 0x020205AC
_080207D0: .4byte 0x082C5DEC
	thumb_func_end sub_08020780

	thumb_func_start sub_080207D4
sub_080207D4: @ 0x080207D4
	push {r4, lr}
	adds r4, r0, #0
	bl sub_0801EF98
	adds r3, r0, #0
	cmp r3, #0xf
	bne _080207F0
	adds r0, r4, #0
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	b _08020804
_080207F0:
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r0
	strb r1, [r2]
	lsls r0, r3, #3
	adds r0, #0x4c
	strh r0, [r4, #0x20]
_08020804:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080207D4

	thumb_func_start sub_0802080C
sub_0802080C: @ 0x0802080C
	push {lr}
	adds r1, r0, #0
	ldrh r0, [r1, #0x2e]
	adds r0, #1
	movs r2, #0
	strh r0, [r1, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _08020832
	strh r2, [r1, #0x2e]
	ldrh r0, [r1, #0x24]
	adds r0, #1
	strh r0, [r1, #0x24]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #4
	ble _08020832
	strh r2, [r1, #0x24]
_08020832:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802080C

	thumb_func_start sub_08020838
sub_08020838: @ 0x08020838
	push {r4, r5, lr}
	ldr r0, _08020888
	movs r1, #8
	movs r2, #0x98
	movs r3, #3
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r5, _0802088C
	ldr r2, [r5]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r4, _08020890
	adds r1, r1, r4
	str r1, [r2, #0xc]
	ldr r0, _08020894
	movs r1, #0x20
	movs r2, #0x98
	movs r3, #4
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, [r5]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	str r1, [r2, #0x10]
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08020888: .4byte 0x082C5E44
_0802088C: .4byte 0x02022940
_08020890: .4byte 0x020205AC
_08020894: .4byte 0x082C5E5C
	thumb_func_end sub_08020838

	thumb_func_start sub_08020898
sub_08020898: @ 0x08020898
	push {r4, lr}
	bl sub_0801EEB0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _080208D0
	bl sub_0801EEDC
	cmp r0, #0
	beq _080208DA
	ldr r3, _080208CC
	ldr r0, [r3]
	ldr r1, [r0, #0x10]
	adds r1, #0x3e
	ldrb r2, [r1]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, #0x10]
	movs r1, #3
	bl StartSpriteAnim
	b _0802090E
	.align 2, 0
_080208CC: .4byte 0x02022940
_080208D0:
	bl sub_0801EFA4
	adds r4, r0, #0
	cmp r4, #3
	bne _080208F0
_080208DA:
	ldr r0, _080208EC
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	b _0802090E
	.align 2, 0
_080208EC: .4byte 0x02022940
_080208F0:
	ldr r3, _08020914
	ldr r0, [r3]
	ldr r1, [r0, #0x10]
	adds r1, #0x3e
	ldrb r2, [r1]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	ldr r0, [r0, #0x10]
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	bl StartSpriteAnim
_0802090E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08020914: .4byte 0x02022940
	thumb_func_end sub_08020898
