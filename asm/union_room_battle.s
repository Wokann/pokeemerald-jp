.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start sub_0801A5A8
sub_0801A5A8: @ 0x0801A5A8
	push {r4, r5, r6, r7, lr}
	movs r0, #0xa
	bl StartUnionRoomBattle
	movs r4, #0
	movs r7, #0x64
	ldr r6, _0801A628
	ldr r5, _0801A62C
_0801A5B8:
	ldr r0, _0801A630
	adds r0, r4, r0
	ldrb r0, [r0]
	subs r0, #1
	adds r1, r0, #0
	muls r1, r7, r1
	adds r1, r1, r6
	adds r0, r5, #0
	movs r2, #0x64
	bl memcpy
	adds r5, #0x64
	adds r4, #1
	cmp r4, #1
	ble _0801A5B8
	ldr r4, _0801A628
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r5, r4, r0
_0801A5DE:
	adds r0, r4, #0
	bl ZeroMonData
	adds r4, #0x64
	cmp r4, r5
	ble _0801A5DE
	ldr r4, _0801A628
	movs r5, #0
	adds r6, r4, #0
	adds r6, #0x64
_0801A5F2:
	ldr r1, _0801A62C
	adds r1, r5, r1
	adds r0, r4, #0
	movs r2, #0x64
	bl memcpy
	adds r4, #0x64
	adds r5, #0x64
	cmp r4, r6
	ble _0801A5F2
	movs r0, #0x32
	bl IncrementGameStat
	bl CalculatePlayerPartyCount
	ldr r0, _0801A634
	movs r2, #0xc0
	lsls r2, r2, #4
	adds r1, r2, #0
	strh r1, [r0]
	ldr r0, _0801A638
	bl SetMainCallback2
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A628: .4byte 0x02024190
_0801A62C: .4byte 0x020243E8
_0801A630: .4byte 0x0203CBC4
_0801A634: .4byte 0x0203886A
_0801A638: .4byte 0x080365B5
	thumb_func_end sub_0801A5A8

	thumb_func_start sub_0801A63C
sub_0801A63C: @ 0x0801A63C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	adds r7, r1, #0
	adds r6, r2, #0
	ldr r4, [sp, #0x38]
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r0, #0
	mov sb, r0
	movs r1, #1
	mov sl, r1
	ldr r0, _0801A6AC
	mov r8, r0
	ldrb r0, [r0]
	lsls r1, r0, #4
	orrs r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r5, #0
	str r3, [sp, #0x14]
	bl FillWindowPixelBuffer
	mov r1, sb
	str r1, [sp]
	mov r0, sl
	str r0, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	str r4, [sp, #0xc]
	str r7, [sp, #0x10]
	adds r0, r5, #0
	movs r1, #1
	adds r2, r6, #0
	ldr r3, [sp, #0x14]
	bl AddTextPrinterParameterized4
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A6AC: .4byte 0x082C32C0
	thumb_func_end sub_0801A63C

	thumb_func_start sub_0801A6B0
sub_0801A6B0: @ 0x0801A6B0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _0801A6C8
	cmp r0, #1
	beq _0801A6F6
	b _0801A70A
_0801A6C8:
	movs r0, #0
	movs r1, #1
	movs r2, #0xd
	bl DrawTextBorderOuter
	str r5, [sp]
	movs r0, #0
	adds r1, r6, #0
	movs r2, #1
	movs r3, #1
	bl sub_0801A63C
	movs r0, #0
	bl PutWindowTilemap
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0801A70A
_0801A6F6:
	movs r0, #0
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _0801A70A
	strh r0, [r4]
	movs r0, #1
	b _0801A70C
_0801A70A:
	movs r0, #0
_0801A70C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_0801A6B0

	thumb_func_start sub_0801A714
sub_0801A714: @ 0x0801A714
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0801A714

	thumb_func_start sub_0801A728
sub_0801A728: @ 0x0801A728
	push {r4, lr}
	sub sp, #0xc
	ldr r1, _0801A748
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x33
	bls _0801A73E
	b _0801AA82
_0801A73E:
	lsls r0, r0, #2
	ldr r1, _0801A74C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801A748: .4byte 0x03002360
_0801A74C: .4byte 0x0801A750
_0801A750: @ jump table
	.4byte _0801A820 @ case 0
	.4byte _0801A8D0 @ case 1
	.4byte _0801A8F8 @ case 2
	.4byte _0801A91C @ case 3
	.4byte _0801A96C @ case 4
	.4byte _0801AA82 @ case 5
	.4byte _0801AA50 @ case 6
	.4byte _0801AA2C @ case 7
	.4byte _0801AA50 @ case 8
	.4byte _0801AA6C @ case 9
	.4byte _0801AA82 @ case 10
	.4byte _0801AA82 @ case 11
	.4byte _0801AA82 @ case 12
	.4byte _0801AA82 @ case 13
	.4byte _0801AA82 @ case 14
	.4byte _0801AA82 @ case 15
	.4byte _0801AA82 @ case 16
	.4byte _0801AA82 @ case 17
	.4byte _0801AA82 @ case 18
	.4byte _0801AA82 @ case 19
	.4byte _0801AA82 @ case 20
	.4byte _0801AA82 @ case 21
	.4byte _0801AA82 @ case 22
	.4byte _0801AA82 @ case 23
	.4byte _0801AA82 @ case 24
	.4byte _0801AA82 @ case 25
	.4byte _0801AA82 @ case 26
	.4byte _0801AA82 @ case 27
	.4byte _0801AA82 @ case 28
	.4byte _0801AA82 @ case 29
	.4byte _0801AA82 @ case 30
	.4byte _0801AA82 @ case 31
	.4byte _0801AA82 @ case 32
	.4byte _0801AA82 @ case 33
	.4byte _0801AA82 @ case 34
	.4byte _0801AA82 @ case 35
	.4byte _0801AA82 @ case 36
	.4byte _0801AA82 @ case 37
	.4byte _0801AA82 @ case 38
	.4byte _0801AA82 @ case 39
	.4byte _0801AA82 @ case 40
	.4byte _0801AA82 @ case 41
	.4byte _0801AA82 @ case 42
	.4byte _0801AA82 @ case 43
	.4byte _0801AA82 @ case 44
	.4byte _0801AA82 @ case 45
	.4byte _0801AA82 @ case 46
	.4byte _0801AA82 @ case 47
	.4byte _0801AA82 @ case 48
	.4byte _0801AA82 @ case 49
	.4byte _0801A9F8 @ case 50
	.4byte _0801AA14 @ case 51
_0801A820:
	movs r0, #0
	movs r1, #0
	bl SetGpuReg
	ldr r4, _0801A8BC
	movs r0, #4
	bl AllocZeroed
	str r0, [r4]
	bl ResetSpriteData
	bl FreeAllSpritePalettes
	bl ResetTasks
	movs r0, #0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, _0801A8C0
	movs r0, #0
	movs r2, #1
	bl InitBgsFromTemplates
	bl ResetTempTileDataBuffers
	ldr r0, _0801A8C4
	bl InitWindows
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0801A860
	b _0801AA96
_0801A860:
	bl DeactivateAllTextPrinters
	movs r0, #0
	bl ClearWindowTilemap
	movs r0, #0
	movs r1, #0
	bl FillWindowPixelBuffer
	movs r0, #0
	movs r1, #0x11
	bl FillWindowPixelBuffer
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect
	movs r0, #0
	movs r1, #1
	movs r2, #0xd0
	bl LoadUserWindowBorderGfx
	movs r0, #0
	movs r1, #1
	movs r2, #0xd0
	bl LoadUserWindowBorderGfx_
	bl sub_08197680
	ldr r0, _0801A8C8
	bl SetVBlankCallback
	ldr r1, _0801A8CC
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r1, r0
	b _0801AA5E
	.align 2, 0
_0801A8BC: .4byte 0x02022920
_0801A8C0: .4byte 0x082C32AC
_0801A8C4: .4byte 0x082C32B0
_0801A8C8: .4byte 0x0801A715
_0801A8CC: .4byte 0x03002360
_0801A8D0:
	ldr r0, _0801A8EC
	ldr r0, [r0]
	ldr r1, _0801A8F0
	movs r2, #0
	bl sub_0801A6B0
	cmp r0, #0
	bne _0801A8E2
	b _0801AA82
_0801A8E2:
	ldr r1, _0801A8F4
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	b _0801AA5E
	.align 2, 0
_0801A8EC: .4byte 0x02022920
_0801A8F0: .4byte 0x082C32C3
_0801A8F4: .4byte 0x03002360
_0801A8F8:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	movs r0, #0
	bl ShowBg
	ldr r1, _0801A918
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r1, r0
	b _0801AA5E
	.align 2, 0
_0801A918: .4byte 0x03002360
_0801A91C:
	bl UpdatePaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0801A928
	b _0801AA82
_0801A928:
	ldr r4, _0801A944
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x20
	bl memset
	ldr r0, _0801A948
	ldrb r1, [r0]
	ldrb r0, [r0, #1]
	cmn r1, r0
	bne _0801A94C
	movs r0, #0x52
	b _0801A94E
	.align 2, 0
_0801A944: .4byte 0x0202257C
_0801A948: .4byte 0x0203CBC4
_0801A94C:
	movs r0, #0x51
_0801A94E:
	strb r0, [r4]
	ldr r1, _0801A964
	movs r0, #0
	movs r2, #0x20
	bl SendBlock
	ldr r1, _0801A968
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	b _0801AA5E
	.align 2, 0
_0801A964: .4byte 0x0202257C
_0801A968: .4byte 0x03002360
_0801A96C:
	bl GetBlockReceivedStatus
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	beq _0801A97A
	b _0801AA82
_0801A97A:
	ldr r1, _0801A9AC
	ldrh r0, [r1]
	cmp r0, #0x51
	bne _0801A9B4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0x51
	bne _0801A9B4
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	ldr r0, _0801A9B0
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #0x32
	b _0801A9EA
	.align 2, 0
_0801A9AC: .4byte 0x0202207C
_0801A9B0: .4byte 0x03002360
_0801A9B4:
	bl SetCloseLinkCallback
	ldr r4, _0801A9D8
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x10
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x52
	bne _0801A9E0
	ldr r0, _0801A9DC
	movs r2, #0x87
	lsls r2, r2, #3
	adds r0, r0, r2
	movs r1, #6
	b _0801A9EA
	.align 2, 0
_0801A9D8: .4byte 0x0202207C
_0801A9DC: .4byte 0x03002360
_0801A9E0:
	ldr r0, _0801A9F4
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #8
_0801A9EA:
	strb r1, [r0]
	bl ResetBlockReceivedFlags
	b _0801AA82
	.align 2, 0
_0801A9F4: .4byte 0x03002360
_0801A9F8:
	bl UpdatePaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801AA82
	bl SetLinkStandbyCallback
	ldr r1, _0801AA10
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r1, r2
	b _0801AA5E
	.align 2, 0
_0801AA10: .4byte 0x03002360
_0801AA14:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0801AA82
	ldr r0, _0801AA28
	bl SetMainCallback2
	b _0801AA82
	.align 2, 0
_0801AA28: .4byte 0x0801A5A9
_0801AA2C:
	ldr r0, _0801AA44
	ldr r0, [r0]
	ldr r1, _0801AA48
	movs r2, #1
	bl sub_0801A6B0
	cmp r0, #0
	beq _0801AA82
	ldr r0, _0801AA4C
	bl SetMainCallback2
	b _0801AA82
	.align 2, 0
_0801AA44: .4byte 0x02022920
_0801AA48: .4byte 0x082C32F3
_0801AA4C: .4byte 0x08085A31
_0801AA50:
	ldr r0, _0801AA68
	ldrb r0, [r0]
	cmp r0, #0
	bne _0801AA82
	movs r0, #0x87
	lsls r0, r0, #3
	adds r1, r2, r0
_0801AA5E:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0801AA82
	.align 2, 0
_0801AA68: .4byte 0x030031C4
_0801AA6C:
	ldr r0, _0801AAA0
	ldr r0, [r0]
	ldr r1, _0801AAA4
	movs r2, #1
	bl sub_0801A6B0
	cmp r0, #0
	beq _0801AA82
	ldr r0, _0801AAA8
	bl SetMainCallback2
_0801AA82:
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
_0801AA96:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801AAA0: .4byte 0x02022920
_0801AAA4: .4byte 0x082C32E1
_0801AAA8: .4byte 0x08085A31
	thumb_func_end sub_0801A728

	thumb_func_start ClearMysteryGift
ClearMysteryGift: @ 0x0801AAAC
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	ldr r0, _0801AAD4
	ldr r1, [r0]
	ldr r0, _0801AAD8
	adds r1, r1, r0
	ldr r2, _0801AADC
	mov r0, sp
	bl CpuSet
	bl sub_0801AC50
	bl sub_0811FE10
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0801AAD4: .4byte 0x03005AEC
_0801AAD8: .4byte 0x0000322C
_0801AADC: .4byte 0x0500007A
	thumb_func_end ClearMysteryGift
