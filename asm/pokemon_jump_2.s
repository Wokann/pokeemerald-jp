.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start sub_0802CDB0
sub_0802CDB0: @ 0x0802CDB0
	movs r1, #0
	strh r1, [r0, #4]
	str r1, [r0]
	movs r1, #0xff
	strh r1, [r0, #0x12]
	bx lr
	thumb_func_end sub_0802CDB0

	thumb_func_start sub_0802CDBC
sub_0802CDBC: @ 0x0802CDBC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldr r4, _0802CDE0
_0802CDC4:
	ldr r0, [r4]
	cmp r0, r6
	bne _0802CDD0
	ldr r0, [r4, #4]
	bl sub_0802CDFC
_0802CDD0:
	adds r4, #8
	adds r5, #1
	cmp r5, #9
	bls _0802CDC4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802CDE0: .4byte 0x082D1A18
	thumb_func_end sub_0802CDBC

	thumb_func_start sub_0802CDE4
sub_0802CDE4: @ 0x0802CDE4
	ldr r0, _0802CDF8
	ldr r0, [r0]
	ldr r1, [r0]
	movs r0, #1
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	bx lr
	.align 2, 0
_0802CDF8: .4byte 0x020229B4
	thumb_func_end sub_0802CDE4

	thumb_func_start sub_0802CDFC
sub_0802CDFC: @ 0x0802CDFC
	push {r4, lr}
	adds r2, r0, #0
	ldr r4, _0802CE1C
	ldr r0, [r4]
	ldrb r0, [r0, #6]
	movs r1, #0
	bl SetWordTaskArg
	ldr r1, [r4]
	movs r0, #0
	strh r0, [r1, #4]
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802CE1C: .4byte 0x020229B4
	thumb_func_end sub_0802CDFC

	thumb_func_start sub_0802CE20
sub_0802CE20: @ 0x0802CE20
	push {lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r0, _0802CE40
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, #0
	bne _0802CE3C
	adds r0, r1, #0
	movs r1, #0
	bl GetWordTaskArg
	bl _call_via_r0
_0802CE3C:
	pop {r0}
	bx r0
	.align 2, 0
_0802CE40: .4byte 0x020229B4
	thumb_func_end sub_0802CE20

	thumb_func_start sub_0802CE44
sub_0802CE44: @ 0x0802CE44
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r6, _0802CE60
	ldr r1, [r6]
	ldrh r5, [r1, #4]
	cmp r5, #1
	bne _0802CE54
	b _0802CF8C
_0802CE54:
	cmp r5, #1
	bgt _0802CE64
	cmp r5, #0
	beq _0802CE6C
	b _0802CFCE
	.align 2, 0
_0802CE60: .4byte 0x020229B4
_0802CE64:
	cmp r5, #2
	bne _0802CE6A
	b _0802CFCA
_0802CE6A:
	b _0802CFCE
_0802CE6C:
	movs r0, #0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, _0802CF5C
	movs r0, #0
	movs r2, #4
	bl InitBgsFromTemplates
	ldr r0, _0802CF60
	bl InitWindows
	bl ResetTempTileDataBuffers
	ldr r0, [r6]
	bl sub_0802C668
	bl sub_0802DA00
	ldr r0, _0802CF64
	movs r1, #0
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0802CF68
	str r5, [sp]
	movs r0, #3
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	ldr r1, _0802CF6C
	movs r4, #1
	str r4, [sp]
	movs r0, #3
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	ldr r0, _0802CF70
	movs r1, #0x30
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0802CF74
	str r5, [sp]
	movs r0, #2
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	ldr r1, _0802CF78
	str r4, [sp]
	movs r0, #2
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	ldr r0, _0802CF7C
	movs r1, #0x10
	movs r2, #0x20
	bl LoadPalette
	ldr r1, _0802CF80
	str r5, [sp]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	ldr r1, _0802CF84
	str r4, [sp]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	ldr r0, _0802CF88
	movs r1, #0x20
	movs r2, #0x20
	bl LoadPalette
	ldr r1, [r6]
	movs r0, #0xd3
	lsls r0, r0, #1
	adds r1, r1, r0
	movs r0, #0
	bl SetBgTilemapBuffer
	movs r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	bl sub_0802D884
	movs r0, #0
	bl sub_0802DA5C
	movs r0, #0
	movs r1, #1
	movs r2, #0xe0
	bl LoadUserWindowBorderGfxOnBg
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #2
	bl CopyBgTilemapBufferToVram
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	bl ResetBgPositions
	b _0802CFC0
	.align 2, 0
_0802CF5C: .4byte 0x082D19F0
_0802CF60: .4byte 0x082D1A00
_0802CF64: .4byte 0x082CF8D0
_0802CF68: .4byte 0x082CF8F0
_0802CF6C: .4byte 0x082CFB1C
_0802CF70: .4byte 0x082CFCCC
_0802CF74: .4byte 0x082CFCEC
_0802CF78: .4byte 0x082D063C
_0802CF7C: .4byte 0x082D09F4
_0802CF80: .4byte 0x082D0A14
_0802CF84: .4byte 0x082D14C4
_0802CF88: .4byte 0x082CF8B0
_0802CF8C:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802CFCE
	bl sub_0802D8F0
	ldr r0, [r6]
	bl sub_0802CB90
	ldr r0, [r6]
	movs r1, #6
	bl sub_0802CC44
	movs r0, #3
	bl ShowBg
	movs r0, #0
	bl ShowBg
	movs r0, #2
	bl ShowBg
	movs r0, #1
	bl HideBg
_0802CFC0:
	ldr r1, [r6]
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	b _0802CFCE
_0802CFCA:
	movs r0, #1
	str r0, [r1]
_0802CFCE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802CE44

	thumb_func_start sub_0802CFD8
sub_0802CFD8: @ 0x0802CFD8
	push {r4, lr}
	ldr r4, _0802CFF0
	ldr r0, [r4]
	ldrh r0, [r0, #4]
	cmp r0, #1
	beq _0802D004
	cmp r0, #1
	bgt _0802CFF4
	cmp r0, #0
	beq _0802CFFE
	b _0802D03E
	.align 2, 0
_0802CFF0: .4byte 0x020229B4
_0802CFF4:
	cmp r0, #2
	beq _0802D016
	cmp r0, #3
	beq _0802D02E
	b _0802D03E
_0802CFFE:
	bl sub_0802DB14
	b _0802D024
_0802D004:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D03E
	movs r0, #0
	bl sub_0802DC68
	b _0802D024
_0802D016:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D03E
	bl sub_0802DCCC
_0802D024:
	ldr r1, [r4]
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	b _0802D03E
_0802D02E:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D03E
	ldr r1, [r4]
	movs r0, #1
	str r0, [r1]
_0802D03E:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0802CFD8

	thumb_func_start sub_0802D044
sub_0802D044: @ 0x0802D044
	push {r4, lr}
	ldr r4, _0802D05C
	ldr r0, [r4]
	ldrh r0, [r0, #4]
	cmp r0, #1
	beq _0802D070
	cmp r0, #1
	bgt _0802D060
	cmp r0, #0
	beq _0802D06A
	b _0802D0AA
	.align 2, 0
_0802D05C: .4byte 0x020229B4
_0802D060:
	cmp r0, #2
	beq _0802D082
	cmp r0, #3
	beq _0802D09A
	b _0802D0AA
_0802D06A:
	bl sub_0802DB14
	b _0802D090
_0802D070:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D0AA
	movs r0, #1
	bl sub_0802DC68
	b _0802D090
_0802D082:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D0AA
	bl sub_0802DCCC
_0802D090:
	ldr r1, [r4]
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	b _0802D0AA
_0802D09A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D0AA
	ldr r1, [r4]
	movs r0, #1
	str r0, [r1]
_0802D0AA:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_0802D044

	thumb_func_start sub_0802D0B0
sub_0802D0B0: @ 0x0802D0B0
	push {r4, r5, lr}
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _0802D0CC
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	cmp r0, #0
	beq _0802D0D0
	cmp r0, #1
	beq _0802D104
	b _0802D132
	.align 2, 0
_0802D0CC: .4byte 0x020229B4
_0802D0D0:
	movs r4, #0
	cmp r4, r5
	bge _0802D0EC
_0802D0D6:
	ldr r0, _0802D100
	ldr r0, [r0]
	lsls r1, r4, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r4, #1
	cmp r4, r5
	blt _0802D0D6
_0802D0EC:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _0802D100
	ldr r1, [r0]
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	b _0802D132
	.align 2, 0
_0802D100: .4byte 0x020229B4
_0802D104:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D132
	movs r4, #0
	cmp r4, r5
	bge _0802D12A
_0802D114:
	ldr r0, _0802D138
	ldr r0, [r0]
	lsls r1, r4, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrb r0, [r0]
	bl RemoveWindow
	adds r4, #1
	cmp r4, r5
	blt _0802D114
_0802D12A:
	ldr r0, _0802D138
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1]
_0802D132:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D138: .4byte 0x020229B4
	thumb_func_end sub_0802D0B0

	thumb_func_start sub_0802D13C
sub_0802D13C: @ 0x0802D13C
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, _0802D154
	ldr r0, [r5]
	ldrh r4, [r0, #4]
	cmp r4, #1
	beq _0802D198
	cmp r4, #1
	bgt _0802D158
	cmp r4, #0
	beq _0802D15E
	b _0802D1E0
	.align 2, 0
_0802D154: .4byte 0x020229B4
_0802D158:
	cmp r4, #2
	beq _0802D1D0
	b _0802D1E0
_0802D15E:
	movs r0, #1
	movs r1, #8
	movs r2, #0x14
	movs r3, #2
	bl sub_0802D78C
	ldr r1, [r5]
	strh r0, [r1, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0802D194
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	movs r1, #2
	bl CopyWindowToVram
	b _0802D1C6
	.align 2, 0
_0802D194: .4byte 0x085CCE71
_0802D198:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D1E0
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	movs r1, #1
	movs r2, #0xe
	bl DrawTextBorderOuter
	movs r0, #0x17
	movs r1, #7
	movs r2, #0
	bl sub_0802D808
	movs r0, #0
	bl CopyBgTilemapBufferToVram
_0802D1C6:
	ldr r1, [r5]
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	b _0802D1E0
_0802D1D0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D1E0
	ldr r1, [r5]
	movs r0, #1
	str r0, [r1]
_0802D1E0:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_0802D13C

	thumb_func_start sub_0802D1E8
sub_0802D1E8: @ 0x0802D1E8
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, _0802D200
	ldr r0, [r5]
	ldrh r4, [r0, #4]
	cmp r4, #1
	beq _0802D244
	cmp r4, #1
	bgt _0802D204
	cmp r4, #0
	beq _0802D20A
	b _0802D282
	.align 2, 0
_0802D200: .4byte 0x020229B4
_0802D204:
	cmp r4, #2
	beq _0802D272
	b _0802D282
_0802D20A:
	movs r0, #2
	movs r1, #7
	movs r2, #0x1a
	movs r3, #4
	bl sub_0802D78C
	ldr r1, [r5]
	strh r0, [r1, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0802D240
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	movs r1, #2
	bl CopyWindowToVram
	b _0802D268
	.align 2, 0
_0802D240: .4byte 0x08277071
_0802D244:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D282
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	movs r1, #1
	movs r2, #0xe
	bl DrawTextBorderOuter
	movs r0, #0
	bl CopyBgTilemapBufferToVram
_0802D268:
	ldr r1, [r5]
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	b _0802D282
_0802D272:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D282
	ldr r1, [r5]
	movs r0, #1
	str r0, [r1]
_0802D282:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802D1E8

	thumb_func_start sub_0802D28C
sub_0802D28C: @ 0x0802D28C
	push {r4, r5, lr}
	ldr r5, _0802D2A0
	ldr r0, [r5]
	ldrh r4, [r0, #4]
	cmp r4, #0
	beq _0802D2A4
	cmp r4, #1
	beq _0802D2BC
	b _0802D2D2
	.align 2, 0
_0802D2A0: .4byte 0x020229B4
_0802D2A4:
	bl sub_0802D704
	bl sub_08198D88
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r5]
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	b _0802D2D2
_0802D2BC:
	bl sub_0802D734
	cmp r0, #0
	bne _0802D2D2
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D2D2
	ldr r0, [r5]
	str r4, [r0]
_0802D2D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_0802D28C

	thumb_func_start sub_0802D2D8
sub_0802D2D8: @ 0x0802D2D8
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, _0802D2F0
	ldr r0, [r5]
	ldrh r4, [r0, #4]
	cmp r4, #1
	beq _0802D334
	cmp r4, #1
	bgt _0802D2F4
	cmp r4, #0
	beq _0802D2FA
	b _0802D372
	.align 2, 0
_0802D2F0: .4byte 0x020229B4
_0802D2F4:
	cmp r4, #2
	beq _0802D362
	b _0802D372
_0802D2FA:
	movs r0, #2
	movs r1, #8
	movs r2, #0x16
	movs r3, #4
	bl sub_0802D78C
	ldr r1, [r5]
	strh r0, [r1, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0802D330
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	movs r1, #2
	bl CopyWindowToVram
	b _0802D358
	.align 2, 0
_0802D330: .4byte 0x085CCE7F
_0802D334:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D372
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	movs r1, #1
	movs r2, #0xe
	bl DrawTextBorderOuter
	movs r0, #0
	bl CopyBgTilemapBufferToVram
_0802D358:
	ldr r1, [r5]
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	b _0802D372
_0802D362:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D372
	ldr r1, [r5]
	movs r0, #1
	str r0, [r1]
_0802D372:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802D2D8

	thumb_func_start sub_0802D37C
sub_0802D37C: @ 0x0802D37C
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r5, _0802D394
	ldr r0, [r5]
	ldrh r4, [r0, #4]
	cmp r4, #1
	beq _0802D3D8
	cmp r4, #1
	bgt _0802D398
	cmp r4, #0
	beq _0802D39E
	b _0802D416
	.align 2, 0
_0802D394: .4byte 0x020229B4
_0802D398:
	cmp r4, #2
	beq _0802D406
	b _0802D416
_0802D39E:
	movs r0, #7
	movs r1, #0xa
	movs r2, #0x10
	movs r3, #2
	bl sub_0802D78C
	ldr r1, [r5]
	strh r0, [r1, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0802D3D4
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	movs r1, #2
	bl CopyWindowToVram
	b _0802D3FC
	.align 2, 0
_0802D3D4: .4byte 0x085CCE99
_0802D3D8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D416
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	bl PutWindowTilemap
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	movs r1, #1
	movs r2, #0xe
	bl DrawTextBorderOuter
	movs r0, #0
	bl CopyBgTilemapBufferToVram
_0802D3FC:
	ldr r1, [r5]
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	b _0802D416
_0802D406:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D416
	ldr r1, [r5]
	movs r0, #1
	str r0, [r1]
_0802D416:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802D37C

	thumb_func_start sub_0802D420
sub_0802D420: @ 0x0802D420
	push {r4, r5, lr}
	ldr r5, _0802D434
	ldr r0, [r5]
	ldrh r4, [r0, #4]
	cmp r4, #0
	beq _0802D438
	cmp r4, #1
	beq _0802D446
	b _0802D452
	.align 2, 0
_0802D434: .4byte 0x020229B4
_0802D438:
	bl sub_0802CD38
	ldr r1, [r5]
	ldrh r0, [r1, #4]
	adds r0, #1
	strh r0, [r1, #4]
	b _0802D452
_0802D446:
	bl sub_0802CD5C
	cmp r0, #0
	bne _0802D452
	ldr r0, [r5]
	str r4, [r0]
_0802D452:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_0802D420

	thumb_func_start sub_0802D458
sub_0802D458: @ 0x0802D458
	push {lr}
	ldr r1, _0802D478
	ldr r0, [r1]
	movs r2, #0
	strb r2, [r0, #0xa]
	ldr r0, [r1]
	strb r2, [r0, #0xb]
	ldr r2, [r1]
	movs r0, #6
	strb r0, [r2, #0xc]
	ldr r0, [r1]
	ldrb r0, [r0, #0xc]
	bl sub_0802D994
	pop {r0}
	bx r0
	.align 2, 0
_0802D478: .4byte 0x020229B4
	thumb_func_end sub_0802D458

	thumb_func_start sub_0802D47C
sub_0802D47C: @ 0x0802D47C
	push {r4, lr}
	ldr r0, _0802D490
	ldr r2, [r0]
	ldrb r3, [r2, #0xa]
	adds r4, r0, #0
	cmp r3, #0
	beq _0802D494
	cmp r3, #1
	beq _0802D4CE
	b _0802D4D2
	.align 2, 0
_0802D490: .4byte 0x020229B4
_0802D494:
	ldrb r0, [r2, #0xb]
	adds r0, #1
	strb r0, [r2, #0xb]
	ldr r1, [r4]
	ldrb r0, [r1, #0xb]
	cmp r0, #0xa
	bls _0802D4BE
	strb r3, [r1, #0xb]
	ldr r0, [r4]
	ldrb r1, [r0, #0xc]
	adds r1, #1
	strb r1, [r0, #0xc]
	ldr r1, [r4]
	ldrb r0, [r1, #0xc]
	cmp r0, #9
	bls _0802D4BE
	strb r3, [r1, #0xc]
	ldr r1, [r4]
	ldrb r0, [r1, #0xa]
	adds r0, #1
	strb r0, [r1, #0xa]
_0802D4BE:
	ldr r0, [r4]
	ldrb r0, [r0, #0xc]
	bl sub_0802D994
	ldr r0, [r4]
	ldrb r0, [r0, #0xc]
	cmp r0, #7
	bne _0802D4D2
_0802D4CE:
	movs r0, #0
	b _0802D4D4
_0802D4D2:
	movs r0, #1
_0802D4D4:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802D47C

	thumb_func_start sub_0802D4DC
sub_0802D4DC: @ 0x0802D4DC
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r5, _0802D568
	ldr r1, [r5]
	adds r1, #0x26
	bl CopyItemName
	ldr r0, [r5]
	adds r0, #0x66
	adds r1, r4, #0
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	bl DynamicPlaceholderTextUtil_Reset
	ldr r1, [r5]
	adds r1, #0x26
	movs r0, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r1, [r5]
	adds r1, #0x66
	movs r0, #1
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, [r5]
	adds r0, #0xa6
	ldr r1, _0802D56C
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, #4
	movs r1, #8
	movs r2, #0x16
	movs r3, #4
	bl sub_0802D78C
	ldr r2, [r5]
	movs r4, #0
	movs r3, #0
	strh r0, [r2, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, #0xa6
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r3, [sp, #8]
	movs r1, #1
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	ldrb r0, [r0, #0x12]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, _0802D570
	strh r0, [r1, #0x14]
	strb r4, [r1, #0xd]
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D568: .4byte 0x020229B4
_0802D56C: .4byte 0x085CCE36
_0802D570: .4byte 0x0000016F
	thumb_func_end sub_0802D4DC

	thumb_func_start sub_0802D574
sub_0802D574: @ 0x0802D574
	push {r4, r5, r6, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0802D5E4
	ldr r1, [r4]
	adds r1, #0x26
	bl CopyItemName
	bl DynamicPlaceholderTextUtil_Reset
	ldr r1, [r4]
	adds r1, #0x26
	movs r0, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, [r4]
	adds r0, #0xa6
	ldr r1, _0802D5E8
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, #4
	movs r1, #8
	movs r2, #0x16
	movs r3, #4
	bl sub_0802D78C
	ldr r2, [r4]
	movs r6, #0
	movs r5, #0
	strh r0, [r2, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, #0xa6
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	ldrb r0, [r0, #0x12]
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, [r4]
	strh r5, [r0, #0x14]
	strb r6, [r0, #0xd]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802D5E4: .4byte 0x020229B4
_0802D5E8: .4byte 0x085CCE52
	thumb_func_end sub_0802D574

	thumb_func_start sub_0802D5EC
sub_0802D5EC: @ 0x0802D5EC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0802D65C
	ldr r1, [r4]
	adds r1, #0x26
	bl CopyItemName
	bl DynamicPlaceholderTextUtil_Reset
	ldr r1, [r4]
	adds r1, #0x26
	movs r0, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, [r4]
	adds r0, #0xa6
	ldr r1, _0802D660
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	movs r0, #4
	movs r1, #9
	movs r2, #0x16
	movs r3, #2
	bl sub_0802D78C
	ldr r2, [r4]
	movs r6, #0
	movs r5, #0
	strh r0, [r2, #0x12]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, #0xa6
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	ldrb r0, [r0, #0x12]
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, [r4]
	strh r5, [r0, #0x14]
	strb r6, [r0, #0xd]
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802D65C: .4byte 0x020229B4
_0802D660: .4byte 0x085CCE65
	thumb_func_end sub_0802D5EC

	thumb_func_start sub_0802D664
sub_0802D664: @ 0x0802D664
	push {r4, lr}
	ldr r4, _0802D67C
	ldr r0, [r4]
	ldrb r0, [r0, #0xd]
	cmp r0, #1
	beq _0802D6B8
	cmp r0, #1
	bgt _0802D680
	cmp r0, #0
	beq _0802D68A
	b _0802D6FC
	.align 2, 0
_0802D67C: .4byte 0x020229B4
_0802D680:
	cmp r0, #2
	beq _0802D6DE
	cmp r0, #3
	beq _0802D6F2
	b _0802D6FC
_0802D68A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D6FC
	ldr r0, [r4]
	ldrb r0, [r0, #0x12]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldrb r0, [r0, #0x12]
	movs r1, #1
	movs r2, #0xe
	bl DrawTextBorderOuter
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r4]
	ldrb r0, [r1, #0xd]
	adds r0, #1
	strb r0, [r1, #0xd]
	b _0802D6FC
_0802D6B8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D6FC
	ldr r1, [r4]
	ldrh r0, [r1, #0x14]
	cmp r0, #0
	bne _0802D6D0
	ldrb r0, [r1, #0xd]
	adds r0, #2
	b _0802D6F0
_0802D6D0:
	ldrh r0, [r1, #0x14]
	bl PlayFanfare
	ldr r1, [r4]
	ldrb r0, [r1, #0xd]
	adds r0, #1
	strb r0, [r1, #0xd]
_0802D6DE:
	bl IsFanfareTaskInactive
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0802D6FC
	ldr r0, _0802D6F8
	ldr r1, [r0]
	ldrb r0, [r1, #0xd]
	adds r0, #1
_0802D6F0:
	strb r0, [r1, #0xd]
_0802D6F2:
	movs r0, #0
	b _0802D6FE
	.align 2, 0
_0802D6F8: .4byte 0x020229B4
_0802D6FC:
	movs r0, #1
_0802D6FE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802D664

	thumb_func_start sub_0802D704
sub_0802D704: @ 0x0802D704
	push {r4, lr}
	ldr r4, _0802D730
	ldr r0, [r4]
	ldrh r0, [r0, #0x12]
	cmp r0, #0xff
	beq _0802D728
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl rbox_fill_rectangle
	ldr r0, [r4]
	ldrb r0, [r0, #0x12]
	movs r1, #1
	bl CopyWindowToVram
	ldr r1, [r4]
	movs r0, #0
	strb r0, [r1, #0xd]
_0802D728:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802D730: .4byte 0x020229B4
	thumb_func_end sub_0802D704

	thumb_func_start sub_0802D734
sub_0802D734: @ 0x0802D734
	push {r4, lr}
	ldr r4, _0802D744
	ldr r1, [r4]
	ldrh r0, [r1, #0x12]
	cmp r0, #0xff
	bne _0802D748
_0802D740:
	movs r0, #0
	b _0802D774
	.align 2, 0
_0802D744: .4byte 0x020229B4
_0802D748:
	ldrb r0, [r1, #0xd]
	cmp r0, #0
	bne _0802D76E
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802D772
	ldr r0, [r4]
	ldrb r0, [r0, #0x12]
	bl RemoveWindow
	ldr r1, [r4]
	movs r0, #0xff
	strh r0, [r1, #0x12]
	ldrb r0, [r1, #0xd]
	adds r0, #1
	strb r0, [r1, #0xd]
	b _0802D740
_0802D76E:
	cmp r0, #1
	beq _0802D740
_0802D772:
	movs r0, #1
_0802D774:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802D734

	thumb_func_start sub_0802D77C
sub_0802D77C: @ 0x0802D77C
	push {lr}
	bl Menu_ProcessInputNoWrapClearOnChoose
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802D77C

	thumb_func_start sub_0802D78C
sub_0802D78C: @ 0x0802D78C
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r6, _0802D7F4
	ldr r4, [sp]
	ands r4, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x10
	ldr r5, _0802D7F8
	ands r4, r5
	orrs r4, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #8
	ldr r0, _0802D7FC
	ands r4, r0
	orrs r4, r1
	lsls r2, r2, #0x18
	ldr r0, _0802D800
	ands r4, r0
	orrs r4, r2
	str r4, [sp]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #4]
	ands r0, r6
	orrs r0, r3
	ands r0, r5
	movs r1, #0xf0
	lsls r1, r1, #4
	orrs r0, r1
	ldr r1, _0802D804
	ands r0, r1
	movs r1, #0xcc
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl AddWindow
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x11
	bl FillWindowPixelBuffer
	adds r0, r4, #0
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802D7F4: .4byte 0xFFFFFF00
_0802D7F8: .4byte 0xFFFF00FF
_0802D7FC: .4byte 0xFF00FFFF
_0802D800: .4byte 0x00FFFFFF
_0802D804: .4byte 0x0000FFFF
	thumb_func_end sub_0802D78C

	thumb_func_start sub_0802D808
sub_0802D808: @ 0x0802D808
	push {r4, r5, lr}
	sub sp, #0x14
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r5, _0802D870
	ldr r3, [sp, #0xc]
	ands r3, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x10
	ldr r4, _0802D874
	ands r3, r4
	orrs r3, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #8
	ldr r0, _0802D878
	ands r3, r0
	orrs r3, r1
	ldr r0, _0802D87C
	ands r3, r0
	movs r0, #0xc0
	lsls r0, r0, #0x13
	orrs r3, r0
	str r3, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r5
	movs r1, #4
	orrs r0, r1
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	ldr r1, _0802D880
	ands r0, r1
	movs r1, #0xd8
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp]
	movs r0, #0xd
	str r0, [sp, #4]
	str r2, [sp, #8]
	add r0, sp, #0xc
	movs r1, #1
	movs r2, #2
	movs r3, #2
	bl CreateYesNoMenuAtPos
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802D870: .4byte 0xFFFFFF00
_0802D874: .4byte 0xFFFF00FF
_0802D878: .4byte 0xFF00FFFF
_0802D87C: .4byte 0x00FFFFFF
_0802D880: .4byte 0x0000FFFF
	thumb_func_end sub_0802D808

	thumb_func_start sub_0802D884
sub_0802D884: @ 0x0802D884
	push {r4, lr}
	sub sp, #0x10
	ldr r1, _0802D8E4
	add r0, sp, #0xc
	movs r2, #3
	bl memcpy
	movs r0, #0
	bl PutWindowTilemap
	movs r0, #1
	bl PutWindowTilemap
	movs r0, #0
	movs r1, #0
	bl FillWindowPixelBuffer
	movs r0, #1
	movs r1, #0
	bl FillWindowPixelBuffer
	add r0, sp, #0xc
	str r0, [sp]
	movs r4, #0
	str r4, [sp, #4]
	ldr r0, _0802D8E8
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #2
	bl AddTextPrinterParameterized3
	add r0, sp, #0xc
	str r0, [sp]
	str r4, [sp, #4]
	ldr r0, _0802D8EC
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #2
	bl AddTextPrinterParameterized3
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802D8E4: .4byte 0x082D1A68
_0802D8E8: .4byte 0x085CCDF8
_0802D8EC: .4byte 0x085CCDFB
	thumb_func_end sub_0802D884

	thumb_func_start sub_0802D8F0
sub_0802D8F0: @ 0x0802D8F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	ldr r1, _0802D96C
	subs r0, #2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r5, [r0]
	movs r6, #0
	cmp r6, sl
	bge _0802D95A
	ldr r0, _0802D970
	mov sb, r0
	ldr r1, _0802D974
	mov r8, r1
_0802D91E:
	lsls r4, r6, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl sub_0802C5BC
	adds r1, r0, #0
	ldrh r0, [r1]
	lsls r0, r0, #2
	add r0, sb
	ldrb r3, [r0, #1]
	mov r2, r8
	ldr r0, [r2]
	movs r7, #0
	ldrsh r2, [r5, r7]
	adds r3, #0x70
	str r4, [sp]
	bl sub_0802C6C8
	mov r1, r8
	ldr r0, [r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	movs r2, #0x70
	adds r3, r4, #0
	bl sub_0802CB3C
	adds r5, #2
	adds r6, #1
	cmp r6, sl
	blt _0802D91E
_0802D95A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802D96C: .4byte 0x082D1AEC
_0802D970: .4byte 0x082D45C8
_0802D974: .4byte 0x020229B4
	thumb_func_end sub_0802D8F0

	thumb_func_start sub_0802D978
sub_0802D978: @ 0x0802D978
	ldr r2, _0802D98C
	ldr r2, [r2]
	lsls r0, r0, #2
	ldr r3, _0802D990
	adds r2, r2, r3
	adds r2, r2, r0
	ldr r0, [r2]
	strh r1, [r0, #0x26]
	bx lr
	.align 2, 0
_0802D98C: .4byte 0x020229B4
_0802D990: .4byte 0x000081A8
	thumb_func_end sub_0802D978

	thumb_func_start sub_0802D994
sub_0802D994: @ 0x0802D994
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0802D9BC
	ldr r0, [r0]
	adds r1, r4, #0
	bl sub_0802CC44
	ldr r0, _0802D9C0
	adds r4, r4, r0
	ldrb r0, [r4]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #0xd
	movs r0, #2
	movs r2, #0
	bl ChangeBgY
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802D9BC: .4byte 0x020229B4
_0802D9C0: .4byte 0x082D1A6B
	thumb_func_end sub_0802D994

	thumb_func_start sub_0802D9C4
sub_0802D9C4: @ 0x0802D9C4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r5, #0
	movs r6, #0
_0802D9CE:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _0802D9E2
	ldr r0, _0802D9FC
	ldr r0, [r0]
	adds r1, r5, #0
	bl sub_0802C808
	adds r6, #1
_0802D9E2:
	lsrs r4, r4, #1
	adds r5, #1
	cmp r5, #4
	ble _0802D9CE
	subs r0, r6, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_0802DD04
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802D9FC: .4byte 0x020229B4
	thumb_func_end sub_0802D9C4

	thumb_func_start sub_0802DA00
sub_0802DA00: @ 0x0802DA00
	push {r4, lr}
	sub sp, #0x10
	mov r1, sp
	movs r0, #0x40
	strb r0, [r1]
	movs r0, #5
	strb r0, [r1, #1]
	movs r0, #8
	strb r0, [r1, #2]
	movs r0, #0x6c
	strh r0, [r1, #4]
	movs r4, #6
	strh r4, [r1, #6]
	ldr r0, _0802DA54
	str r0, [sp, #8]
	ldr r0, _0802DA58
	str r0, [sp, #0xc]
	movs r0, #2
	bl sub_08034AAC
	movs r0, #0
	movs r1, #0
	mov r2, sp
	bl sub_08034B6C
	mov r1, sp
	movs r0, #4
	strb r0, [r1, #1]
	movs r0, #0x1e
	strh r0, [r1, #4]
	mov r0, sp
	strh r4, [r0, #6]
	movs r0, #1
	movs r1, #0
	mov r2, sp
	bl sub_08034B6C
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DA54: .4byte 0x082D1A78
_0802DA58: .4byte 0x082D1A80
	thumb_func_end sub_0802DA00

	thumb_func_start sub_0802DA5C
sub_0802DA5C: @ 0x0802DA5C
	push {lr}
	adds r1, r0, #0
	movs r0, #0
	bl sub_08034E9C
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DA5C

	thumb_func_start sub_0802DA6C
sub_0802DA6C: @ 0x0802DA6C
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #1
	bl sub_08034E9C
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DA6C

	thumb_func_start sub_0802DA80
sub_0802DA80: @ 0x0802DA80
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _0802DA94
	ldr r0, [r0]
	bl sub_0802C8E4
	pop {r0}
	bx r0
	.align 2, 0
_0802DA94: .4byte 0x020229B4
	thumb_func_end sub_0802DA80

	thumb_func_start sub_0802DA98
sub_0802DA98: @ 0x0802DA98
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _0802DAAC
	ldr r0, [r0]
	bl sub_0802C97C
	pop {r0}
	bx r0
	.align 2, 0
_0802DAAC: .4byte 0x020229B4
	thumb_func_end sub_0802DA98

	thumb_func_start sub_0802DAB0
sub_0802DAB0: @ 0x0802DAB0
	push {lr}
	adds r1, r0, #0
	ldr r0, _0802DAC0
	ldr r0, [r0]
	bl sub_0802C90C
	pop {r1}
	bx r1
	.align 2, 0
_0802DAC0: .4byte 0x020229B4
	thumb_func_end sub_0802DAB0

	thumb_func_start sub_0802DAC4
sub_0802DAC4: @ 0x0802DAC4
	push {lr}
	ldr r0, _0802DAD4
	ldr r0, [r0]
	bl sub_0802C9A4
	pop {r0}
	bx r0
	.align 2, 0
_0802DAD4: .4byte 0x020229B4
	thumb_func_end sub_0802DAC4

	thumb_func_start sub_0802DAD8
sub_0802DAD8: @ 0x0802DAD8
	push {lr}
	ldr r0, _0802DAE8
	ldr r0, [r0]
	bl sub_0802CA30
	pop {r0}
	bx r0
	.align 2, 0
_0802DAE8: .4byte 0x020229B4
	thumb_func_end sub_0802DAD8

	thumb_func_start sub_0802DAEC
sub_0802DAEC: @ 0x0802DAEC
	push {lr}
	adds r1, r0, #0
	ldr r0, _0802DAFC
	ldr r0, [r0]
	bl sub_0802CA64
	pop {r0}
	bx r0
	.align 2, 0
_0802DAFC: .4byte 0x020229B4
	thumb_func_end sub_0802DAEC

	thumb_func_start sub_0802DB00
sub_0802DB00: @ 0x0802DB00
	push {lr}
	ldr r0, _0802DB10
	ldr r0, [r0]
	bl sub_0802CA8C
	pop {r1}
	bx r1
	.align 2, 0
_0802DB10: .4byte 0x020229B4
	thumb_func_end sub_0802DB00

	thumb_func_start sub_0802DB14
sub_0802DB14: @ 0x0802DB14
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r1, _0802DBB4
	subs r0, r7, #2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	ldr r2, _0802DBB8
	ldr r0, [sp]
	ands r0, r2
	ldr r1, _0802DBBC
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x14
	orrs r0, r1
	str r0, [sp]
	ldr r0, [sp, #4]
	ands r0, r2
	movs r1, #2
	orrs r0, r1
	ldr r1, _0802DBC0
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	ldr r1, _0802DBC4
	ands r0, r1
	movs r1, #0xd8
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #4]
	movs r5, #0
	cmp r5, r7
	bge _0802DBA4
	mov r6, sp
_0802DB62:
	ldrb r0, [r4]
	lsls r0, r0, #8
	ldr r2, _0802DBC0
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	ldrb r2, [r4, #2]
	lsls r2, r2, #0x10
	ldr r0, _0802DBC8
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, sp
	bl AddWindow
	ldr r1, _0802DBCC
	ldr r1, [r1]
	lsls r2, r5, #1
	adds r1, #0x1c
	adds r1, r1, r2
	strh r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl ClearWindowTilemap
	ldrh r0, [r6, #6]
	adds r0, #0x10
	strh r0, [r6, #6]
	adds r4, #4
	adds r5, #1
	cmp r5, r7
	blt _0802DB62
_0802DBA4:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802DBB4: .4byte 0x082D1AC0
_0802DBB8: .4byte 0xFFFFFF00
_0802DBBC: .4byte 0x00FFFFFF
_0802DBC0: .4byte 0xFFFF00FF
_0802DBC4: .4byte 0x0000FFFF
_0802DBC8: .4byte 0xFF00FFFF
_0802DBCC: .4byte 0x020229B4
	thumb_func_end sub_0802DB14

	thumb_func_start sub_0802DBD0
sub_0802DBD0: @ 0x0802DBD0
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x10
	adds r5, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	add r0, sp, #0xc
	strb r1, [r0]
	strb r2, [r0, #1]
	strb r3, [r0, #2]
	ldr r6, _0802DC64
	ldr r0, [r6]
	lsls r1, r5, #1
	mov r8, r1
	adds r0, #0x1c
	add r0, r8
	ldrb r0, [r0]
	movs r1, #0
	bl FillWindowPixelBuffer
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	adds r0, r5, #0
	bl sub_0802C5DC
	adds r1, r0, #0
	movs r2, #1
	rsbs r2, r2, #0
	mov sb, r2
	movs r0, #0
	bl GetStringWidth
	movs r4, #0x40
	subs r4, r4, r0
	lsrs r4, r4, #1
	adds r0, r5, #0
	bl sub_0802C5DC
	adds r1, r0, #0
	ldr r0, [r6]
	adds r0, #0x1c
	add r0, r8
	ldrb r0, [r0]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	add r2, sp, #0xc
	str r2, [sp]
	mov r2, sb
	str r2, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	adds r2, r4, #0
	movs r3, #2
	bl AddTextPrinterParameterized3
	ldr r0, [r6]
	adds r0, #0x1c
	add r0, r8
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802DC64: .4byte 0x020229B4
	thumb_func_end sub_0802DBD0

	thumb_func_start sub_0802DC68
sub_0802DC68: @ 0x0802DC68
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r4, #0
	bne _0802DC92
	movs r4, #0
	cmp r4, r5
	bge _0802DCC4
_0802DC7E:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #3
	bl sub_0802DBD0
	adds r4, #1
	cmp r4, r5
	blt _0802DC7E
	b _0802DCC4
_0802DC92:
	bl sub_0802C5B0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	movs r4, #0
	cmp r4, r5
	bge _0802DCC4
_0802DCA0:
	cmp r6, r4
	beq _0802DCB2
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #3
	bl sub_0802DBD0
	b _0802DCBE
_0802DCB2:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	movs r3, #5
	bl sub_0802DBD0
_0802DCBE:
	adds r4, #1
	cmp r4, r5
	blt _0802DCA0
_0802DCC4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DC68

	thumb_func_start sub_0802DCCC
sub_0802DCCC: @ 0x0802DCCC
	push {r4, r5, lr}
	bl sub_0802C5A0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r4, #0
	cmp r4, r5
	bge _0802DCF2
_0802DCDC:
	ldr r0, _0802DD00
	ldr r0, [r0]
	lsls r1, r4, #1
	adds r0, #0x1c
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	adds r4, #1
	cmp r4, r5
	blt _0802DCDC
_0802DCF2:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802DD00: .4byte 0x020229B4
	thumb_func_end sub_0802DCCC

	thumb_func_start sub_0802DD04
sub_0802DD04: @ 0x0802DD04
	push {r4, lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	ldr r0, _0802DD48
	ldr r2, [r0]
	movs r0, #0
	str r0, [r2, #0x18]
	lsrs r1, r1, #0x19
	lsls r1, r1, #0x10
	movs r0, #1
	movs r2, #0
	bl ChangeBgX
	movs r0, #1
	ands r4, r0
	lsls r4, r4, #8
	subs r4, #0x28
	lsls r4, r4, #8
	adds r1, r4, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #1
	bl ShowBg
	ldr r0, _0802DD4C
	movs r1, #4
	bl CreateTask
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802DD48: .4byte 0x020229B4
_0802DD4C: .4byte 0x0802DD89
	thumb_func_end sub_0802DD04

	thumb_func_start sub_0802DD50
sub_0802DD50: @ 0x0802DD50
	push {r4, lr}
	ldr r4, _0802DD60
	ldr r0, [r4]
	ldr r0, [r0, #0x18]
	cmp r0, #0x1f
	bls _0802DD64
	movs r0, #0
	b _0802DD82
	.align 2, 0
_0802DD60: .4byte 0x020229B4
_0802DD64:
	movs r0, #1
	movs r1, #0x80
	movs r2, #1
	bl ChangeBgY
	ldr r1, [r4]
	ldr r0, [r1, #0x18]
	adds r0, #1
	str r0, [r1, #0x18]
	cmp r0, #0x1f
	bls _0802DD80
	movs r0, #1
	bl HideBg
_0802DD80:
	movs r0, #1
_0802DD82:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802DD50

	thumb_func_start sub_0802DD88
sub_0802DD88: @ 0x0802DD88
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl sub_0802DD50
	cmp r0, #0
	bne _0802DD9C
	adds r0, r4, #0
	bl DestroyTask
_0802DD9C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DD88

	thumb_func_start sub_0802DDA4
sub_0802DDA4: @ 0x0802DDA4
	push {lr}
	sub sp, #0xc
	mov r2, sp
	movs r1, #1
	strb r1, [r2]
	ldrh r1, [r0]
	strh r1, [r2, #2]
	ldr r1, [r0, #4]
	str r1, [sp, #8]
	ldr r0, [r0, #8]
	str r0, [sp, #4]
	mov r0, sp
	bl Rfu_SendPacket
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DDA4

	thumb_func_start sub_0802DDC8
sub_0802DDC8: @ 0x0802DDC8
	push {r4, lr}
	sub sp, #0xc
	adds r4, r1, #0
	ldr r3, _0802DDFC
	lsls r2, r0, #4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, r1
	bne _0802DDF8
	adds r1, r3, #2
	adds r1, r2, r1
	mov r0, sp
	movs r2, #0xc
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #1
	beq _0802DE00
_0802DDF8:
	movs r0, #0
	b _0802DE10
	.align 2, 0
_0802DDFC: .4byte 0x03003130
_0802DE00:
	mov r0, sp
	ldrh r0, [r0, #2]
	strh r0, [r4]
	ldr r0, [sp, #8]
	str r0, [r4, #4]
	ldr r0, [sp, #4]
	str r0, [r4, #8]
	movs r0, #1
_0802DE10:
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802DDC8

	thumb_func_start sub_0802DE18
sub_0802DE18: @ 0x0802DE18
	push {lr}
	sub sp, #0xc
	mov r2, sp
	movs r1, #2
	strb r1, [r2]
	str r0, [sp, #4]
	mov r0, sp
	bl Rfu_SendPacket
	add sp, #0xc
	pop {r0}
	bx r0
	thumb_func_end sub_0802DE18

	thumb_func_start sub_0802DE30
sub_0802DE30: @ 0x0802DE30
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0xc
	mov r3, sp
	movs r2, #3
	strb r2, [r3]
	ldr r3, [r1, #8]
	lsls r3, r3, #0xf
	ldr r2, [sp, #8]
	ldr r4, _0802DEAC
	mov r8, r4
	ands r2, r4
	orrs r2, r3
	str r2, [sp, #8]
	mov r6, sp
	ldrb r2, [r1, #1]
	movs r5, #0x1f
	adds r3, r5, #0
	ands r3, r2
	ldrb r4, [r6, #3]
	movs r2, #0x20
	rsbs r2, r2, #0
	ands r2, r4
	orrs r2, r3
	strb r2, [r6, #3]
	mov r3, sp
	ldrb r2, [r1]
	strb r2, [r3, #1]
	ldrh r2, [r1, #2]
	strh r2, [r3, #6]
	mov r4, sp
	ldrh r2, [r1, #4]
	mov r1, r8
	ands r2, r1
	ldrh r3, [r4, #8]
	ldr r1, _0802DEB0
	ands r1, r3
	orrs r1, r2
	strh r1, [r4, #8]
	mov r2, sp
	ldrh r1, [r0, #0x10]
	strb r1, [r2, #2]
	mov r3, sp
	ldr r1, [r0, #0x14]
	lsls r1, r1, #5
	ldrb r2, [r3, #3]
	ands r5, r2
	orrs r5, r1
	strb r5, [r3, #3]
	mov r1, sp
	ldrh r0, [r0, #0xe]
	strh r0, [r1, #4]
	mov r0, sp
	bl Rfu_SendPacket
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802DEAC: .4byte 0x00007FFF
_0802DEB0: .4byte 0xFFFF8000
	thumb_func_end sub_0802DE30

	thumb_func_start sub_0802DEB4
sub_0802DEB4: @ 0x0802DEB4
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r2, _0802DF1C
	ldrh r0, [r2]
	movs r1, #0xff
	lsls r1, r1, #8
	ands r1, r0
	movs r0, #0xbc
	lsls r0, r0, #6
	cmp r1, r0
	bne _0802DF20
	adds r1, r2, #2
	mov r0, sp
	movs r2, #0xc
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #3
	bne _0802DF20
	ldr r0, [sp, #8]
	lsrs r0, r0, #0xf
	str r0, [r4, #8]
	mov r0, sp
	ldrb r1, [r0, #3]
	lsls r0, r1, #0x1b
	lsrs r0, r0, #0x1b
	strb r0, [r4, #1]
	mov r0, sp
	ldrb r0, [r0, #1]
	strb r0, [r4]
	mov r0, sp
	ldrh r0, [r0, #6]
	strh r0, [r4, #2]
	mov r0, sp
	ldrh r0, [r0, #8]
	lsls r0, r0, #0x11
	lsrs r0, r0, #0x11
	strh r0, [r4, #4]
	mov r0, sp
	ldrb r0, [r0, #2]
	strh r0, [r5, #0x10]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x1d
	str r1, [r5, #0x14]
	mov r0, sp
	ldrh r0, [r0, #4]
	strh r0, [r5, #0xe]
	movs r0, #1
	b _0802DF22
	.align 2, 0
_0802DF1C: .4byte 0x03003130
_0802DF20:
	movs r0, #0
_0802DF22:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802DEB4

	thumb_func_start sub_0802DF2C
sub_0802DF2C: @ 0x0802DF2C
	push {r4, lr}
	sub sp, #0xc
	mov r4, sp
	movs r3, #4
	strb r3, [r4]
	ldrh r3, [r0, #0x10]
	strb r3, [r4, #1]
	ldr r3, [r0, #0x14]
	strb r3, [r4, #2]
	ldr r3, [r0, #0x18]
	strb r3, [r4, #3]
	mov r3, sp
	ldrh r0, [r0, #0xe]
	strh r0, [r3, #4]
	mov r0, sp
	strb r1, [r0, #6]
	strh r2, [r0, #8]
	bl Rfu_SendPacket
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802DF2C

	thumb_func_start sub_0802DF5C
sub_0802DF5C: @ 0x0802DF5C
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r3, _0802DFB8
	lsls r2, r1, #4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, r1
	bne _0802DFBC
	adds r1, r3, #2
	adds r1, r2, r1
	mov r0, sp
	movs r2, #0xc
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #4
	bne _0802DFBC
	mov r0, sp
	ldrb r0, [r0, #1]
	strh r0, [r4, #0x10]
	mov r0, sp
	ldrb r0, [r0, #2]
	str r0, [r4, #0x14]
	mov r0, sp
	ldrb r0, [r0, #3]
	str r0, [r4, #0x18]
	mov r0, sp
	ldrh r0, [r0, #4]
	strh r0, [r4, #0xe]
	mov r0, sp
	ldrb r0, [r0, #6]
	strb r0, [r5]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r6]
	movs r0, #1
	b _0802DFBE
	.align 2, 0
_0802DFB8: .4byte 0x03003130
_0802DFBC:
	movs r0, #0
_0802DFBE:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802DF5C

	thumb_func_start sub_0802DFC8
sub_0802DFC8: @ 0x0802DFC8
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r3, _0802E014
	lsls r2, r1, #4
	adds r0, r2, r3
	ldrh r1, [r0]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	movs r1, #0xbc
	lsls r1, r1, #6
	cmp r0, r1
	bne _0802E018
	adds r1, r3, #2
	adds r1, r2, r1
	mov r0, sp
	movs r2, #0xc
	bl memcpy
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #4
	bne _0802E018
	mov r0, sp
	ldrb r0, [r0, #1]
	strh r0, [r4, #0x10]
	mov r0, sp
	ldrb r0, [r0, #2]
	str r0, [r4, #0x14]
	mov r0, sp
	ldrb r0, [r0, #3]
	str r0, [r4, #0x18]
	mov r0, sp
	ldrh r0, [r0, #4]
	strh r0, [r4, #0xe]
	movs r0, #1
	b _0802E01A
	.align 2, 0
_0802E014: .4byte 0x03003130
_0802E018:
	movs r0, #0
_0802E01A:
	add sp, #0xc
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802DFC8

	thumb_func_start sub_0802E024
sub_0802E024: @ 0x0802E024
	ldr r0, _0802E030
	ldr r0, [r0]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r0, r1
	bx lr
	.align 2, 0
_0802E030: .4byte 0x03005AF0
	thumb_func_end sub_0802E024

	thumb_func_start ResetPokemonJumpRecords
ResetPokemonJumpRecords: @ 0x0802E034
	push {lr}
	bl sub_0802E024
	movs r1, #0
	strh r1, [r0]
	str r1, [r0, #0xc]
	strh r1, [r0, #4]
	strh r1, [r0, #6]
	str r1, [r0, #8]
	strh r1, [r0, #2]
	pop {r0}
	bx r0
	thumb_func_end ResetPokemonJumpRecords

	thumb_func_start sub_0802E04C
sub_0802E04C: @ 0x0802E04C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r6, r2, #0x10
	bl sub_0802E024
	adds r1, r0, #0
	movs r2, #0
	ldr r0, [r1, #0xc]
	cmp r0, r4
	bhs _0802E070
	ldr r0, _0802E098
	cmp r4, r0
	bhi _0802E070
	str r4, [r1, #0xc]
	movs r2, #1
_0802E070:
	ldrh r0, [r1]
	cmp r0, r5
	bhs _0802E080
	ldr r0, _0802E09C
	cmp r5, r0
	bhi _0802E080
	strh r5, [r1]
	movs r2, #1
_0802E080:
	ldrh r0, [r1, #4]
	cmp r0, r6
	bhs _0802E090
	ldr r0, _0802E09C
	cmp r6, r0
	bhi _0802E090
	strh r6, [r1, #4]
	movs r2, #1
_0802E090:
	adds r0, r2, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0802E098: .4byte 0x00018696
_0802E09C: .4byte 0x0000270F
	thumb_func_end sub_0802E04C

	thumb_func_start sub_0802E0A0
sub_0802E0A0: @ 0x0802E0A0
	push {lr}
	bl sub_0802E024
	adds r2, r0, #0
	ldrh r1, [r2, #6]
	ldr r0, _0802E0B8
	cmp r1, r0
	bhi _0802E0B4
	adds r0, r1, #1
	strh r0, [r2, #6]
_0802E0B4:
	pop {r0}
	bx r0
	.align 2, 0
_0802E0B8: .4byte 0x0000270E
	thumb_func_end sub_0802E0A0

	thumb_func_start sub_0802E0BC
sub_0802E0BC: @ 0x0802E0BC
	push {r4, lr}
	ldr r4, _0802E0D8
	adds r0, r4, #0
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl _call_via_r4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802E0D8: .4byte 0x0802E0DD
	thumb_func_end sub_0802E0BC

	thumb_func_start sub_0802E0DC
sub_0802E0DC: @ 0x0802E0DC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _0802E100
	adds r4, r0, r1
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq _0802E128
	cmp r0, #1
	bgt _0802E104
	cmp r0, #0
	beq _0802E10E
	b _0802E176
	.align 2, 0
_0802E100: .4byte 0x03005B68
_0802E104:
	cmp r0, #2
	beq _0802E134
	cmp r0, #3
	beq _0802E15C
	b _0802E176
_0802E10E:
	ldr r0, _0802E124
	bl AddWindow
	strh r0, [r4, #2]
	ldrh r0, [r4, #2]
	bl sub_0802E17C
	ldrb r0, [r4, #2]
	movs r1, #3
	b _0802E14A
	.align 2, 0
_0802E124: .4byte 0x082D1AFC
_0802E128:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802E176
	b _0802E14E
_0802E134:
	ldr r0, _0802E158
	ldrh r1, [r0, #0x2e]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0802E176
	ldrb r0, [r4, #2]
	bl rbox_fill_rectangle
	ldrb r0, [r4, #2]
	movs r1, #1
_0802E14A:
	bl CopyWindowToVram
_0802E14E:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0802E176
	.align 2, 0
_0802E158: .4byte 0x03002360
_0802E15C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802E176
	ldrb r0, [r4, #2]
	bl RemoveWindow
	adds r0, r5, #0
	bl DestroyTask
	bl ScriptContext_Enable
_0802E176:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_0802E0DC

	thumb_func_start sub_0802E17C
sub_0802E17C: @ 0x0802E17C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x18]
	bl sub_0802E024
	ldrh r1, [r0]
	str r1, [sp, #0xc]
	ldr r1, [r0, #0xc]
	str r1, [sp, #0x10]
	ldrh r0, [r0, #4]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x18]
	lsls r4, r0, #0x18
	lsrs r4, r4, #0x18
	ldr r5, _0802E274
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0xd0
	bl LoadUserWindowBorderGfx_
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0xd
	bl DrawTextBorderOuter
	adds r0, r4, #0
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r2, _0802E278
	movs r0, #2
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	movs r6, #0
	adds r7, r4, #0
	movs r1, #0xff
	mov sl, r1
	mov sb, r6
	mov r0, sp
	adds r0, #0xc
	str r0, [sp, #0x1c]
	movs r1, #0xd0
	lsls r1, r1, #0x15
	mov r8, r1
	ldr r5, _0802E27C
_0802E1F2:
	ldr r1, _0802E280
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r2, [r0]
	mov r0, r8
	lsrs r4, r0, #0x18
	str r4, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	ldr r0, [sp, #0x1c]
	ldm r0!, {r1}
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #5
	bl ConvertIntToDecimalStringN
	adds r0, r5, #0
	bl TruncateToFirstWordOnly
	movs r0, #1
	adds r1, r5, #0
	movs r2, #0
	bl GetStringWidth
	movs r3, #0xa0
	subs r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r4, [sp]
	mov r1, sl
	str r1, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	adds r2, r5, #0
	bl AddTextPrinterParameterized
	movs r1, #0x80
	lsls r1, r1, #0x15
	add r8, r1
	adds r6, #1
	ldr r1, [sp, #0x18]
	lsls r0, r1, #0x18
	cmp r6, #2
	bls _0802E1F2
	lsrs r0, r0, #0x18
	bl PutWindowTilemap
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E274: .4byte 0x0000021D
_0802E278: .4byte 0x085CCDFE
_0802E27C: .4byte 0x02021C40
_0802E280: .4byte 0x082D1B04
	thumb_func_end sub_0802E17C

	thumb_func_start TruncateToFirstWordOnly
TruncateToFirstWordOnly: @ 0x0802E284
	push {lr}
	adds r1, r0, #0
	b _0802E28C
_0802E28A:
	adds r1, #1
_0802E28C:
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _0802E29A
	cmp r0, #0
	bne _0802E28A
	movs r0, #0xff
	strb r0, [r1]
_0802E29A:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end TruncateToFirstWordOnly

	thumb_func_start sub_0802E2A0
sub_0802E2A0: @ 0x0802E2A0
	push {r4, r5, lr}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _0802E2E0
	bl CreateTask
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r1, _0802E2E4
	adds r0, r0, r1
	movs r1, #1
	strh r1, [r0, #8]
	strh r5, [r0, #0xa]
	ldr r0, _0802E2E8
	lsls r5, r5, #4
	adds r5, r5, r0
	ldr r1, [r5]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0802E2E0: .4byte 0x0802E335
_0802E2E4: .4byte 0x03005B60
_0802E2E8: .4byte 0x082D1FD4
	thumb_func_end sub_0802E2A0

	thumb_func_start sub_0802E2EC
sub_0802E2EC: @ 0x0802E2EC
	push {lr}
	ldr r0, _0802E310
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	beq _0802E318
	ldr r0, _0802E314
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r1, r1, r0
	movs r0, #2
	strh r0, [r1, #8]
	movs r0, #1
	b _0802E31A
	.align 2, 0
_0802E310: .4byte 0x0802E335
_0802E314: .4byte 0x03005B60
_0802E318:
	movs r0, #0
_0802E31A:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802E2EC

	thumb_func_start sub_0802E320
sub_0802E320: @ 0x0802E320
	push {lr}
	ldr r0, _0802E330
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0802E330: .4byte 0x0802E335
	thumb_func_end sub_0802E320

	thumb_func_start sub_0802E334
sub_0802E334: @ 0x0802E334
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _0802E358
	adds r4, r0, r1
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #3
	beq _0802E380
	cmp r0, #3
	bgt _0802E35C
	cmp r0, #2
	beq _0802E362
	b _0802E3B6
	.align 2, 0
_0802E358: .4byte 0x03005B68
_0802E35C:
	cmp r0, #4
	beq _0802E39C
	b _0802E3B6
_0802E362:
	ldr r1, _0802E37C
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #4
	adds r1, #8
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r0, #3
	strh r0, [r4]
	b _0802E3B6
	.align 2, 0
_0802E37C: .4byte 0x082D1FD4
_0802E380:
	ldr r0, _0802E398
	movs r2, #2
	ldrsh r1, [r4, r2]
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	b _0802E3B6
	.align 2, 0
_0802E398: .4byte 0x082D1FD4
_0802E39C:
	ldr r0, _0802E3BC
	movs r2, #2
	ldrsh r1, [r4, r2]
	lsls r1, r1, #4
	adds r0, #4
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl DestroyTask
_0802E3B6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802E3BC: .4byte 0x082D1FD4
	thumb_func_end sub_0802E334

	thumb_func_start sub_0802E3C0
sub_0802E3C0: @ 0x0802E3C0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r1, #6
	ldrsh r0, [r4, r1]
	lsls r0, r0, #3
	ldr r1, _0802E490
	adds r0, r0, r1
	bl LoadCompressedSpriteSheet
	movs r2, #8
	ldrsh r0, [r4, r2]
	lsls r0, r0, #3
	ldr r1, _0802E494
	adds r0, r0, r1
	bl LoadSpritePalette
	movs r5, #0
	movs r3, #0x10
	ldrsh r0, [r4, r3]
	cmp r5, r0
	bge _0802E428
_0802E3F4:
	movs r0, #4
	ldrsh r1, [r4, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _0802E498
	adds r0, r0, r1
	movs r2, #0x12
	ldrsh r1, [r4, r2]
	movs r3, #0x14
	ldrsh r2, [r4, r3]
	ldrb r3, [r4, #0xe]
	bl CreateSprite
	lsls r1, r5, #1
	adds r1, r1, r4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r1, #0x1a]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _0802E3F4
_0802E428:
	movs r5, #0
	movs r2, #0x10
	ldrsh r0, [r4, r2]
	cmp r5, r0
	bge _0802E484
	movs r7, #3
	movs r3, #0xd
	rsbs r3, r3, #0
	mov ip, r3
	ldr r6, _0802E49C
_0802E43C:
	lsls r0, r5, #1
	adds r0, r0, r4
	movs r1, #0x1a
	ldrsh r0, [r0, r1]
	lsls r2, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r6
	ldrb r1, [r4, #0xc]
	ands r1, r7
	lsls r1, r1, #2
	ldrb r3, [r2, #5]
	mov r0, ip
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #5]
	adds r3, r2, #0
	adds r3, #0x3e
	ldrb r0, [r3]
	movs r1, #4
	orrs r0, r1
	strb r0, [r3]
	ldrh r0, [r4, #0xa]
	strh r0, [r2, #0x30]
	mov r3, r8
	strh r3, [r2, #0x34]
	strh r5, [r2, #0x36]
	ldrh r0, [r4, #0x1a]
	strh r0, [r2, #0x38]
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _0802E43C
_0802E484:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802E490: .4byte 0x082D1F54
_0802E494: .4byte 0x082D1F64
_0802E498: .4byte 0x082D1FBC
_0802E49C: .4byte 0x020205AC
	thumb_func_end sub_0802E3C0

	thumb_func_start sub_0802E4A0
sub_0802E4A0: @ 0x0802E4A0
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #3
	ldr r1, _0802E520
	adds r4, r4, r1
	movs r5, #0
	strh r5, [r4, #4]
	strh r5, [r4, #6]
	strh r5, [r4, #8]
	movs r1, #0x3c
	strh r1, [r4, #0xa]
	strh r5, [r4, #0xc]
	strh r5, [r4, #0xe]
	movs r1, #3
	strh r1, [r4, #0x10]
	movs r1, #0x78
	strh r1, [r4, #0x12]
	movs r1, #0x58
	strh r1, [r4, #0x14]
	adds r1, r4, #0
	bl sub_0802E3C0
	movs r0, #0x1c
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r5, _0802E524
	adds r0, r0, r5
	movs r1, #4
	bl StartSpriteAnim
	movs r0, #0x1c
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r1, _0802E528
	strh r1, [r0, #0x24]
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #5
	bl StartSpriteAnim
	movs r0, #0x1e
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r1, #0x20
	strh r1, [r0, #0x24]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802E520: .4byte 0x03005B68
_0802E524: .4byte 0x020205AC
_0802E528: .4byte 0x0000FFE0
	thumb_func_end sub_0802E4A0

	thumb_func_start sub_0802E52C
sub_0802E52C: @ 0x0802E52C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r5, #0
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _0802E540
	adds r4, r1, r0
	b _0802E560
	.align 2, 0
_0802E540: .4byte 0x03005B68
_0802E544:
	lsls r0, r5, #1
	adds r0, r0, r4
	movs r2, #0x1a
	ldrsh r1, [r0, r2]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0802E590
	adds r0, r0, r1
	bl DestroySprite
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0802E560:
	movs r1, #0x10
	ldrsh r0, [r4, r1]
	cmp r5, r0
	blt _0802E544
	ldr r1, _0802E594
	movs r2, #6
	ldrsh r0, [r4, r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #6]
	bl FreeSpriteTilesByTag
	ldr r1, _0802E598
	movs r2, #8
	ldrsh r0, [r4, r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	bl FreeSpritePaletteByTag
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802E590: .4byte 0x020205AC
_0802E594: .4byte 0x082D1F54
_0802E598: .4byte 0x082D1F64
	thumb_func_end sub_0802E52C

	thumb_func_start sub_0802E59C
sub_0802E59C: @ 0x0802E59C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0x34
	ldrsh r1, [r6, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	ldr r1, _0802E5E0
	adds r5, r0, r1
	movs r1, #0x16
	ldrsh r0, [r5, r1]
	movs r2, #0xa
	ldrsh r1, [r5, r2]
	bl __modsi3
	cmp r0, #0
	bne _0802E6AE
	ldrh r2, [r5, #0x16]
	movs r3, #0x16
	ldrsh r1, [r5, r3]
	movs r3, #0x14
	ldrsh r0, [r5, r3]
	cmp r1, r0
	beq _0802E6AE
	strh r2, [r5, #0x14]
	movs r1, #0x32
	ldrsh r0, [r6, r1]
	cmp r0, #4
	bhi _0802E6A8
	lsls r0, r0, #2
	ldr r1, _0802E5E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E5E0: .4byte 0x03005B68
_0802E5E4: .4byte 0x0802E5E8
_0802E5E8: @ jump table
	.4byte _0802E5FC @ case 0
	.4byte _0802E60A @ case 1
	.4byte _0802E60A @ case 2
	.4byte _0802E61E @ case 3
	.4byte _0802E668 @ case 4
_0802E5FC:
	adds r2, r6, #0
	adds r2, #0x3e
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_0802E60A:
	movs r0, #0x38
	bl PlaySE
	ldrh r1, [r6, #0x32]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl StartSpriteAnim
	b _0802E6A8
_0802E61E:
	movs r0, #0x15
	bl PlaySE
	ldrh r1, [r6, #0x32]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r6, #0
	bl StartSpriteAnim
	ldr r4, _0802E664
	movs r2, #0x1c
	ldrsh r0, [r5, r2]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	adds r1, #0x3e
	ldrb r3, [r1]
	movs r2, #5
	rsbs r2, r2, #0
	adds r0, r2, #0
	ands r0, r3
	strb r0, [r1]
	movs r3, #0x1e
	ldrsh r1, [r5, r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	adds r0, #0x3e
	ldrb r1, [r0]
	ands r2, r1
	strb r2, [r0]
	b _0802E6A8
	.align 2, 0
_0802E664: .4byte 0x020205AC
_0802E668:
	adds r1, r6, #0
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	ldr r3, _0802E6A4
	movs r0, #0x1c
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x3e
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	movs r0, #0x1e
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	adds r0, #0x3e
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	movs r0, #4
	strh r0, [r5]
	b _0802E6AE
	.align 2, 0
_0802E6A4: .4byte 0x020205AC
_0802E6A8:
	ldrh r0, [r6, #0x32]
	adds r0, #1
	strh r0, [r6, #0x32]
_0802E6AE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_0802E59C

	thumb_func_start sub_0802E6B4
sub_0802E6B4: @ 0x0802E6B4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r0, #2
	adds r4, r4, r0
	lsls r4, r4, #3
	ldr r5, _0802E708
	adds r6, r4, r5
	movs r0, #0x38
	bl PlaySE
	ldr r2, _0802E70C
	movs r0, #0x1a
	ldrsh r1, [r6, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r1, r2, #0
	adds r1, #0x1c
	adds r0, r0, r1
	ldr r1, _0802E710
	str r1, [r0]
	movs r0, #0x1a
	ldrsh r1, [r6, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r2, [r0]
	movs r1, #5
	rsbs r1, r1, #0
	ands r1, r2
	strb r1, [r0]
	subs r5, #8
	adds r4, r4, r5
	movs r0, #3
	strh r0, [r4, #8]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E708: .4byte 0x03005B68
_0802E70C: .4byte 0x020205AC
_0802E710: .4byte 0x0802E59D
	thumb_func_end sub_0802E6B4

	thumb_func_start sub_0802E714
sub_0802E714: @ 0x0802E714
	push {r4, r5, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _0802E768
	adds r4, r1, r0
	ldr r0, _0802E76C
	ldrb r0, [r0]
	cmp r0, #0
	beq _0802E778
	ldr r1, _0802E770
	ldrh r0, [r1, #2]
	ldr r5, _0802E774
	cmp r0, r5
	bne _0802E73C
	ldrh r0, [r1, #4]
	strh r0, [r4, #0x16]
_0802E73C:
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802E77E
	ldrh r0, [r4, #0x18]
	adds r0, #1
	strh r0, [r4, #0x18]
	mov r0, sp
	movs r1, #0
	movs r2, #0xc
	bl memset
	mov r0, sp
	strh r5, [r0]
	mov r1, sp
	ldrh r0, [r4, #0x18]
	strh r0, [r1, #2]
	mov r0, sp
	bl Rfu_SendPacket
	b _0802E77E
	.align 2, 0
_0802E768: .4byte 0x03005B68
_0802E76C: .4byte 0x030031C4
_0802E770: .4byte 0x03003130
_0802E774: .4byte 0x00007FFF
_0802E778:
	ldrh r0, [r4, #0x16]
	adds r0, #1
	strh r0, [r4, #0x16]
_0802E77E:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_0802E714

	thumb_func_start sub_0802E788
sub_0802E788: @ 0x0802E788
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	ldr r0, [sp, #0x18]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _0802E7E0
	movs r1, #0x50
	str r3, [sp]
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0802E7E4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	strh r4, [r1, #0xc]
	strh r5, [r1, #0xe]
	strh r6, [r1, #0x10]
	ldr r3, [sp]
	strh r3, [r1, #0x12]
	mov r0, r8
	strh r0, [r1, #0x14]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E7E0: .4byte 0x0802E7FD
_0802E7E4: .4byte 0x03005B60
	thumb_func_end sub_0802E788

	thumb_func_start sub_0802E7E8
sub_0802E7E8: @ 0x0802E7E8
	push {lr}
	ldr r0, _0802E7F8
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0802E7F8: .4byte 0x0802E7FD
	thumb_func_end sub_0802E7E8

	thumb_func_start sub_0802E7FC
sub_0802E7FC: @ 0x0802E7FC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #3
	ldr r1, _0802E820
	adds r5, r0, r1
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #1
	beq _0802E86C
	cmp r0, #1
	bgt _0802E824
	cmp r0, #0
	beq _0802E82A
	b _0802E8EE
	.align 2, 0
_0802E820: .4byte 0x03005B68
_0802E824:
	cmp r0, #2
	beq _0802E8B0
	b _0802E8EE
_0802E82A:
	ldrh r0, [r5, #4]
	ldrh r1, [r5, #6]
	bl sub_0802EBB4
	ldrh r0, [r5, #4]
	ldrh r1, [r5, #6]
	movs r3, #8
	ldrsh r2, [r5, r3]
	movs r4, #0xa
	ldrsh r3, [r5, r4]
	ldrb r4, [r5, #0xc]
	str r4, [sp]
	bl sub_0802EC0C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0xe]
	ldrh r0, [r5, #4]
	ldrh r1, [r5, #6]
	movs r3, #8
	ldrsh r2, [r5, r3]
	movs r4, #0xa
	ldrsh r3, [r5, r4]
	ldrb r4, [r5, #0xc]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0x10
	str r4, [sp, #4]
	adds r4, #2
	str r4, [sp, #8]
	bl sub_0802EC60
	b _0802E8A2
_0802E86C:
	ldrb r0, [r5, #0xe]
	bl sub_0802E8FC
	cmp r0, #0
	bne _0802E8EE
	ldrb r0, [r5, #0xe]
	ldrb r1, [r5, #0x10]
	ldrb r2, [r5, #0x12]
	bl sub_0802EA30
	movs r0, #0xe
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0802E8AC
	adds r0, r0, r4
	bl FreeSpriteOamMatrix
	movs r3, #0xe
	ldrsh r1, [r5, r3]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
_0802E8A2:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b _0802E8EE
	.align 2, 0
_0802E8AC: .4byte 0x020205AC
_0802E8B0:
	ldrb r0, [r5, #0x10]
	bl sub_0802EA94
	cmp r0, #0
	bne _0802E8EE
	movs r4, #0x10
	ldrsh r1, [r5, r4]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r4, _0802E8F8
	adds r0, r0, r4
	bl DestroySprite
	movs r0, #0x12
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	bl DestroySprite
	ldrh r0, [r5, #4]
	bl FreeSpriteTilesByTag
	ldrh r0, [r5, #6]
	bl FreeSpritePaletteByTag
	adds r0, r6, #0
	bl DestroyTask
_0802E8EE:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802E8F8: .4byte 0x020205AC
	thumb_func_end sub_0802E7FC

	thumb_func_start sub_0802E8FC
sub_0802E8FC: @ 0x0802E8FC
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0802E920
	adds r4, r1, r0
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #7
	bls _0802E916
	b _0802EA28
_0802E916:
	lsls r0, r0, #2
	ldr r1, _0802E924
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802E920: .4byte 0x020205AC
_0802E924: .4byte 0x0802E928
_0802E928: @ jump table
	.4byte _0802E948 @ case 0
	.4byte _0802E95A @ case 1
	.4byte _0802E980 @ case 2
	.4byte _0802E990 @ case 3
	.4byte _0802E9B2 @ case 4
	.4byte _0802E9EA @ case 5
	.4byte _0802EA10 @ case 6
	.4byte _0802E9E6 @ case 7
_0802E948:
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r4, #0
	movs r2, #0x1a
	bl SetSpriteMatrixAnchor
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
_0802E95A:
	movs r2, #0x32
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _0802E968
	movs r0, #0x39
	bl PlaySE
_0802E968:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x13
	ble _0802EA28
	movs r0, #0
	strh r0, [r4, #0x32]
	adds r0, r4, #0
	movs r1, #1
	b _0802EA06
_0802E980:
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802EA28
	b _0802EA0A
_0802E990:
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _0802EA28
	movs r0, #0
	strh r0, [r4, #0x32]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	adds r0, r4, #0
	movs r1, #2
	bl StartSpriteAffineAnim
	b _0802EA28
_0802E9B2:
	ldrh r0, [r4, #0x22]
	subs r0, #4
	strh r0, [r4, #0x22]
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0802EA28
	ldrh r1, [r4, #0x36]
	movs r2, #0x36
	ldrsh r0, [r4, r2]
	cmp r0, #1
	bgt _0802E9E2
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
	movs r0, #0
	strh r0, [r4, #0x32]
	b _0802EA0A
_0802E9E2:
	movs r0, #7
	strh r0, [r4, #0x2e]
_0802E9E6:
	movs r0, #0
	b _0802EA2A
_0802E9EA:
	ldrh r0, [r4, #0x22]
	adds r0, #4
	strh r0, [r4, #0x22]
	ldrh r0, [r4, #0x32]
	adds r0, #1
	strh r0, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _0802EA28
	movs r0, #0
	strh r0, [r4, #0x32]
	adds r0, r4, #0
	movs r1, #3
_0802EA06:
	bl StartSpriteAffineAnim
_0802EA0A:
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	b _0802EA26
_0802EA10:
	adds r0, r4, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0802EA28
	ldrh r0, [r4, #0x36]
	adds r0, #1
	strh r0, [r4, #0x36]
	movs r0, #1
_0802EA26:
	strh r0, [r4, #0x2e]
_0802EA28:
	movs r0, #1
_0802EA2A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_0802E8FC

	thumb_func_start sub_0802EA30
sub_0802EA30: @ 0x0802EA30
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r0, _0802EA88
	mov r8, r0
	lsls r4, r1, #4
	adds r4, r4, r1
	lsls r4, r4, #2
	adds r5, r4, r0
	ldr r0, _0802EA8C
	strh r0, [r5, #0x26]
	lsls r3, r2, #4
	adds r3, r3, r2
	lsls r3, r3, #2
	mov r1, r8
	adds r2, r3, r1
	strh r0, [r2, #0x26]
	adds r5, #0x3e
	ldrb r6, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r6
	strb r0, [r5]
	adds r2, #0x3e
	ldrb r0, [r2]
	ands r1, r0
	strb r1, [r2]
	movs r0, #0x1c
	add r8, r0
	add r4, r8
	ldr r0, _0802EA90
	str r0, [r4]
	add r3, r8
	str r0, [r3]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802EA88: .4byte 0x020205AC
_0802EA8C: .4byte 0x0000FFD8
_0802EA90: .4byte 0x0802EAC1
	thumb_func_end sub_0802EA30

	thumb_func_start sub_0802EA94
sub_0802EA94: @ 0x0802EA94
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r3, #0
	ldr r2, _0802EAB8
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r2, #0x1c
	adds r1, r1, r2
	ldr r1, [r1]
	ldr r0, _0802EABC
	cmp r1, r0
	bne _0802EAB2
	movs r3, #1
_0802EAB2:
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0
_0802EAB8: .4byte 0x020205AC
_0802EABC: .4byte 0x0802EAC1
	thumb_func_end sub_0802EA94

	thumb_func_start sub_0802EAC0
sub_0802EAC0: @ 0x0802EAC0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x2e
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	cmp r0, #4
	bhi _0802EBAA
	lsls r0, r0, #2
	ldr r1, _0802EADC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802EADC: .4byte 0x0802EAE0
_0802EAE0: @ jump table
	.4byte _0802EAF4 @ case 0
	.4byte _0802EB04 @ case 1
	.4byte _0802EB2C @ case 2
	.4byte _0802EB60 @ case 3
	.4byte _0802EB98 @ case 4
_0802EAF4:
	movs r0, #0x40
	strh r0, [r4, #8]
	ldrh r0, [r5, #0x26]
	lsls r0, r0, #4
	strh r0, [r4, #0xa]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0802EB04:
	ldrh r1, [r4, #8]
	ldrh r2, [r4, #0xa]
	adds r0, r1, r2
	strh r0, [r4, #0xa]
	adds r1, #1
	strh r1, [r4, #8]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r5, #0x26]
	cmp r0, #0
	blt _0802EBAA
	movs r0, #0x39
	bl PlaySE
	movs r0, #0
	strh r0, [r5, #0x26]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _0802EBAA
_0802EB2C:
	ldrh r0, [r4, #2]
	adds r0, #0xc
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7f
	ble _0802EB4A
	movs r0, #0x39
	bl PlaySE
	movs r0, #0
	strh r0, [r4, #2]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0802EB4A:
	ldr r0, _0802EB5C
	movs r2, #2
	ldrsh r1, [r4, r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	asrs r0, r0, #4
	b _0802EB8E
	.align 2, 0
_0802EB5C: .4byte 0x082FA8CC
_0802EB60:
	ldrh r0, [r4, #2]
	adds r0, #0x10
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x7f
	ble _0802EB7E
	movs r0, #0x39
	bl PlaySE
	movs r0, #0
	strh r0, [r4, #2]
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_0802EB7E:
	ldr r1, _0802EB94
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x15
_0802EB8E:
	rsbs r0, r0, #0
	strh r0, [r5, #0x26]
	b _0802EBAA
	.align 2, 0
_0802EB94: .4byte 0x082FA8CC
_0802EB98:
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x28
	ble _0802EBAA
	ldr r0, _0802EBB0
	str r0, [r5, #0x1c]
_0802EBAA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802EBB0: .4byte 0x08007141
	thumb_func_end sub_0802EAC0

	thumb_func_start sub_0802EBB4
sub_0802EBB4: @ 0x0802EBB4
	push {r4, lr}
	sub sp, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0802EBFC
	ldr r3, [r2, #4]
	ldr r2, [r2]
	str r2, [sp]
	str r3, [sp, #4]
	ldr r2, _0802EC00
	ldr r3, [r2, #4]
	ldr r2, [r2]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	lsls r0, r0, #0x10
	ldr r3, _0802EC04
	ldr r2, [sp, #4]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #4]
	ldr r2, _0802EC08
	add r4, sp, #8
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r4, #4]
	mov r0, sp
	bl LoadCompressedSpriteSheet
	adds r0, r4, #0
	bl LoadSpritePalette
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802EBFC: .4byte 0x082D2458
_0802EC00: .4byte 0x082D2460
_0802EC04: .4byte 0x0000FFFF
_0802EC08: .4byte 0xFFFF0000
	thumb_func_end sub_0802EBB4

	thumb_func_start sub_0802EC0C
sub_0802EC0C: @ 0x0802EC0C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x18
	mov ip, r3
	ldr r3, [sp, #0x30]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r8, r3
	mov r5, sp
	ldr r4, _0802EC5C
	ldm r4!, {r3, r6, r7}
	stm r5!, {r3, r6, r7}
	ldm r4!, {r3, r6, r7}
	stm r5!, {r3, r6, r7}
	mov r4, sp
	strh r0, [r4]
	mov r0, sp
	strh r1, [r0, #2]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	mov r0, ip
	lsls r6, r0, #0x10
	asrs r6, r6, #0x10
	mov r0, sp
	adds r1, r2, #0
	adds r2, r6, #0
	mov r3, r8
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	add sp, #0x18
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0802EC5C: .4byte 0x082D251C
	thumb_func_end sub_0802EC0C

	thumb_func_start sub_0802EC60
sub_0802EC60: @ 0x0802EC60
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov ip, r3
	ldr r6, [sp, #0x38]
	ldr r3, [sp, #0x3c]
	mov sb, r3
	ldr r4, [sp, #0x40]
	mov r8, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	mov sl, r6
	mov r4, sp
	ldr r3, _0802ED24
	ldm r3!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	ldm r3!, {r5, r6, r7}
	stm r4!, {r5, r6, r7}
	mov r3, sp
	strh r0, [r3]
	mov r0, sp
	strh r1, [r0, #2]
	lsls r2, r2, #0x10
	asrs r4, r2, #0x10
	ldr r0, _0802ED28
	adds r2, r2, r0
	asrs r2, r2, #0x10
	mov r1, ip
	lsls r5, r1, #0x10
	asrs r5, r5, #0x10
	mov r0, sp
	adds r1, r2, #0
	adds r2, r5, #0
	mov r3, sl
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r3, sb
	strh r0, [r3]
	adds r4, #0x20
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	mov r3, sl
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r4, r8
	strh r0, [r4]
	ldr r2, _0802ED2C
	mov r5, sb
	movs r6, #0
	ldrsh r1, [r5, r6]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r3, #4
	orrs r1, r3
	strb r1, [r0]
	movs r7, #0
	ldrsh r1, [r4, r7]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	adds r0, #0x3e
	ldrb r1, [r0]
	orrs r1, r3
	strb r1, [r0]
	movs r0, #0
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #1
	bl StartSpriteAnim
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802ED24: .4byte 0x082D2534
_0802ED28: .4byte 0xFFE00000
_0802ED2C: .4byte 0x020205AC
	thumb_func_end sub_0802EC60
