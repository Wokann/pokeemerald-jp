.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_08019EAC
sub_08019EAC: @ 0x08019EAC
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08019ECC
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
_08019ECC:
	pop {r0}
	bx r0
	thumb_func_end sub_08019EAC

	thumb_func_start sub_08019ED0
sub_08019ED0: @ 0x08019ED0
	push {lr}
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08019ED0

	thumb_func_start sub_08019EE4
sub_08019EE4: @ 0x08019EE4
	push {lr}
	ldr r0, _08019EF0
	bl SetMainCallback2
	pop {r0}
	bx r0
	.align 2, 0
_08019EF0: .4byte 0x08019EF5
	thumb_func_end sub_08019EE4

	thumb_func_start sub_08019EF4
sub_08019EF4: @ 0x08019EF4
	push {r4, r5, lr}
	sub sp, #0xc
	movs r0, #0
	movs r1, #0
	bl SetGpuReg
	ldr r5, _0801A018
	movs r0, #0x6c
	bl AllocZeroed
	str r0, [r5]
	movs r0, #0
	bl SetVBlankCallback
	movs r0, #0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, _0801A01C
	movs r0, #0
	movs r2, #2
	bl InitBgsFromTemplates
	movs r4, #0x80
	lsls r4, r4, #4
	adds r0, r4, #0
	bl Alloc
	adds r1, r0, #0
	movs r0, #1
	bl SetBgTilemapBuffer
	adds r0, r4, #0
	bl Alloc
	adds r1, r0, #0
	movs r0, #0
	bl SetBgTilemapBuffer
	ldr r1, _0801A020
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl DecompressAndLoadBgGfxUsingHeap
	ldr r1, _0801A024
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	ldr r0, _0801A028
	bl InitWindows
	bl DeactivateAllTextPrinters
	bl ResetPaletteFade
	bl ResetSpriteData
	bl ResetTasks
	bl ScanlineEffect_Stop
	bl m4aSoundVSyncOn
	ldr r0, _0801A02C
	bl SetVBlankCallback
	ldr r0, _0801A030
	movs r1, #0
	bl CreateTask
	ldr r1, [r5]
	adds r1, #0x60
	strb r0, [r1]
	bl CreateTask_ListenToWireless
	ldr r1, [r5]
	adds r1, #0x61
	strb r0, [r1]
	ldr r1, [r5]
	movs r0, #1
	str r0, [r1, #0x1c]
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
	ldr r0, _0801A034
	movs r1, #0
	movs r2, #0x20
	bl LoadPalette
	movs r0, #0xf0
	bl Menu_LoadStdPalAt
	bl DynamicPlaceholderTextUtil_Reset
	movs r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	ldr r0, _0801A038
	bl SetMainCallback2
	bl RunTasks
	bl RunTextPrinters
	bl AnimateSprites
	bl BuildOamBuffer
	bl UpdatePaletteFade
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A018: .4byte 0x03000DAC
_0801A01C: .4byte 0x082C31B4
_0801A020: .4byte 0x082C2E10
_0801A024: .4byte 0x082C3020
_0801A028: .4byte 0x082C31BC
_0801A02C: .4byte 0x08019ED1
_0801A030: .4byte 0x0801A169
_0801A034: .4byte 0x082C2C10
_0801A038: .4byte 0x08019EAD
	thumb_func_end sub_08019EF4

	thumb_func_start sub_0801A03C
sub_0801A03C: @ 0x0801A03C
	push {r4, lr}
	bl FreeAllWindowBuffers
	movs r4, #0
_0801A044:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl GetBgTilemapBuffer
	bl Free
	adds r4, #1
	cmp r4, #1
	ble _0801A044
	ldr r0, _0801A06C
	ldr r0, [r0]
	bl Free
	ldr r0, _0801A070
	bl SetMainCallback2
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801A06C: .4byte 0x03000DAC
_0801A070: .4byte 0x08085B35
	thumb_func_end sub_0801A03C

	thumb_func_start sub_0801A074
sub_0801A074: @ 0x0801A074
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	ble _0801A09C
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xe
	bne _0801A098
	movs r0, #0
	strh r0, [r1]
_0801A098:
	movs r0, #0
	strh r0, [r2]
_0801A09C:
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r0, #2
	lsls r0, r0, #5
	ldr r1, _0801A0B4
	adds r0, r0, r1
	movs r1, #0
	movs r2, #0x10
	bl LoadPalette
	pop {r0}
	bx r0
	.align 2, 0
_0801A0B4: .4byte 0x082C2C10
	thumb_func_end sub_0801A074

	thumb_func_start sub_0801A0B8
sub_0801A0B8: @ 0x0801A0B8
	push {r4, r5, lr}
	sub sp, #8
	movs r0, #0
	movs r1, #0
	bl FillWindowPixelBuffer
	movs r0, #1
	movs r1, #0
	bl FillWindowPixelBuffer
	movs r0, #2
	movs r1, #0
	bl FillWindowPixelBuffer
	ldr r4, _0801A164
	ldr r2, [r4]
	movs r0, #6
	str r0, [sp]
	movs r0, #3
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #1
	movs r3, #2
	bl sub_0801A384
	movs r1, #0
	adds r5, r4, #0
_0801A0EE:
	adds r4, r1, #1
	lsls r0, r4, #2
	adds r0, r0, r5
	ldr r2, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #0x19
	movs r1, #0xa0
	lsls r1, r1, #0x14
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r1, #1
	movs r3, #0
	bl sub_0801A384
	adds r1, r4, #0
	cmp r4, #2
	ble _0801A0EE
	ldr r1, _0801A164
	adds r0, r4, #1
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r0, r4, #4
	subs r0, r0, r4
	lsls r0, r0, #0x19
	movs r1, #0xa0
	lsls r1, r1, #0x14
	adds r0, r0, r1
	lsrs r0, r0, #0x18
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #1
	movs r3, #0
	bl sub_0801A384
	movs r0, #0
	bl PutWindowTilemap
	movs r0, #0
	movs r1, #2
	bl CopyWindowToVram
	movs r0, #1
	bl PutWindowTilemap
	movs r0, #1
	movs r1, #2
	bl CopyWindowToVram
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0801A164: .4byte 0x082C3238
	thumb_func_end sub_0801A0B8

	thumb_func_start sub_0801A168
sub_0801A168: @ 0x0801A168
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _0801A198
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
	movs r2, #8
	ldrsh r0, [r0, r2]
	adds r2, r1, #0
	cmp r0, #5
	bls _0801A18C
	b _0801A36C
_0801A18C:
	lsls r0, r0, #2
	ldr r1, _0801A19C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801A198: .4byte 0x03005B60
_0801A19C: .4byte 0x0801A1A0
_0801A1A0: @ jump table
	.4byte _0801A1B8 @ case 0
	.4byte _0801A1D4 @ case 1
	.4byte _0801A1F8 @ case 2
	.4byte _0801A214 @ case 3
	.4byte _0801A32C @ case 4
	.4byte _0801A354 @ case 5
_0801A1B8:
	bl sub_0801A0B8
	ldr r0, _0801A1D0
	lsls r1, r5, #2
	adds r1, r1, r5
	lsls r1, r1, #3
	adds r1, r1, r0
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
	b _0801A36C
	.align 2, 0
_0801A1D0: .4byte 0x03005B60
_0801A1D4:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	movs r0, #1
	bl ShowBg
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #0
	bl ShowBg
	b _0801A33C
_0801A1F8:
	ldr r0, _0801A210
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0801A206
	b _0801A36C
_0801A206:
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r2
	b _0801A346
	.align 2, 0
_0801A210: .4byte 0x02037C74
_0801A214:
	ldr r0, _0801A28C
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x10
	adds r2, r0, #0
	adds r2, #0x20
	adds r3, r0, #0
	adds r3, #0x61
	ldrb r3, [r3]
	bl sub_0801A504
	lsls r1, r5, #2
	mov sb, r1
	cmp r0, #0
	beq _0801A2C6
	movs r0, #2
	movs r1, #0
	bl FillWindowPixelBuffer
	movs r4, #0
	ldr r7, _0801A290
	movs r2, #0xa0
	lsls r2, r2, #0x14
	mov r8, r2
	movs r6, #0
_0801A246:
	ldr r0, _0801A28C
	ldr r0, [r0]
	lsls r1, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	add r0, sp, #8
	movs r2, #1
	movs r3, #2
	bl ConvertIntToDecimalStringN
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	add r1, sp, #8
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r1, _0801A294
	adds r1, r6, r1
	adds r0, r7, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	cmp r4, #3
	beq _0801A298
	mov r1, r8
	lsrs r0, r1, #0x18
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	adds r2, r7, #0
	movs r3, #0
	bl sub_0801A384
	b _0801A2AA
	.align 2, 0
_0801A28C: .4byte 0x03000DAC
_0801A290: .4byte 0x02021C7C
_0801A294: .4byte 0x082C3220
_0801A298:
	movs r0, #0x64
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r1, #1
	adds r2, r7, #0
	movs r3, #0
	bl sub_0801A384
_0801A2AA:
	movs r2, #0xf0
	lsls r2, r2, #0x15
	add r8, r2
	adds r6, #6
	adds r4, #1
	cmp r4, #3
	ble _0801A246
	movs r0, #2
	bl PutWindowTilemap
	movs r0, #2
	movs r1, #3
	bl CopyWindowToVram
_0801A2C6:
	ldr r0, _0801A31C
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0801A2DA
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0801A304
_0801A2DA:
	movs r0, #5
	bl PlaySE
	ldr r2, _0801A320
	ldr r0, _0801A324
	ldr r0, [r0]
	adds r0, #0x61
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r1, #0xff
	strh r1, [r0, #0x26]
	mov r0, sb
	adds r1, r0, r5
	lsls r1, r1, #3
	adds r1, r1, r2
	ldrh r0, [r1, #8]
	adds r0, #1
	strh r0, [r1, #8]
_0801A304:
	mov r2, sb
	adds r1, r2, r5
	lsls r1, r1, #3
	ldr r0, _0801A328
	adds r1, r1, r0
	adds r0, r1, #0
	adds r0, #0xe
	adds r1, #0x10
	bl sub_0801A074
	b _0801A36C
	.align 2, 0
_0801A31C: .4byte 0x03002360
_0801A320: .4byte 0x03005B60
_0801A324: .4byte 0x03000DAC
_0801A328: .4byte 0x03005B68
_0801A32C:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
_0801A33C:
	ldr r1, _0801A350
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	adds r0, r0, r1
_0801A346:
	ldrh r1, [r0, #8]
	adds r1, #1
	strh r1, [r0, #8]
	b _0801A36C
	.align 2, 0
_0801A350: .4byte 0x03005B60
_0801A354:
	ldr r0, _0801A37C
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0801A36C
	ldr r0, _0801A380
	bl SetMainCallback2
	adds r0, r5, #0
	bl DestroyTask
_0801A36C:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A37C: .4byte 0x02037C74
_0801A380: .4byte 0x0801A03D
	thumb_func_end sub_0801A168

	thumb_func_start sub_0801A384
sub_0801A384: @ 0x0801A384
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	mov ip, r2
	ldr r2, [sp, #0x2c]
	ldr r4, [sp, #0x30]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r3, r3, #0x18
	lsrs r5, r3, #0x18
	lsls r2, r2, #0x18
	lsrs r3, r2, #0x18
	lsls r4, r4, #0x18
	lsrs r0, r4, #0x18
	cmp r0, #4
	bhi _0801A40E
	lsls r0, r0, #2
	ldr r1, _0801A3B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801A3B0: .4byte 0x0801A3B4
_0801A3B4: @ jump table
	.4byte _0801A3C8 @ case 0
	.4byte _0801A3D6 @ case 1
	.4byte _0801A3E4 @ case 2
	.4byte _0801A3F2 @ case 3
	.4byte _0801A400 @ case 4
_0801A3C8:
	add r1, sp, #0x14
	movs r0, #0
	strb r0, [r1]
	movs r0, #2
	strb r0, [r1, #1]
	movs r0, #3
	b _0801A40C
_0801A3D6:
	add r1, sp, #0x14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r1, #1]
	movs r0, #3
	b _0801A40C
_0801A3E4:
	add r1, sp, #0x14
	movs r0, #0
	strb r0, [r1]
	movs r0, #4
	strb r0, [r1, #1]
	movs r0, #5
	b _0801A40C
_0801A3F2:
	add r1, sp, #0x14
	movs r0, #0
	strb r0, [r1]
	movs r0, #7
	strb r0, [r1, #1]
	movs r0, #6
	b _0801A40C
_0801A400:
	add r1, sp, #0x14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	strb r0, [r1, #1]
	movs r0, #2
_0801A40C:
	strb r0, [r1, #2]
_0801A40E:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	add r0, sp, #0x14
	str r0, [sp, #8]
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [sp, #0xc]
	mov r0, ip
	str r0, [sp, #0x10]
	adds r0, r7, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl AddTextPrinterParameterized4
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_0801A384

	thumb_func_start sub_0801A434
sub_0801A434: @ 0x0801A434
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov ip, r0
	adds r7, r1, #0
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x19
	mov r8, r0
	movs r4, #0
	ldr r0, _0801A4AC
	mov sb, r0
	movs r1, #1
	add r1, sb
	mov sl, r1
	mov r3, ip
	adds r3, #4
	str r3, [sp]
_0801A45E:
	lsls r0, r4, #1
	adds r2, r0, r4
	mov r3, sb
	adds r1, r2, r3
	adds r5, r0, #0
	adds r6, r4, #1
	ldrb r1, [r1]
	cmp r8, r1
	bne _0801A4C2
	mov r0, ip
	ldrb r1, [r0, #0x1a]
	movs r0, #3
	ands r0, r1
	cmp r0, #1
	bne _0801A4C2
	mov r0, sb
	adds r0, #2
	adds r3, r2, r0
	ldrb r0, [r3]
	cmp r0, #0
	bne _0801A4B0
	movs r2, #0
	movs r1, #0
	ldr r3, [sp]
_0801A48E:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0801A498
	adds r2, #1
_0801A498:
	adds r1, #1
	cmp r1, #3
	ble _0801A48E
	adds r2, #1
	adds r0, r5, r4
	add r0, sl
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r7
	b _0801A4BC
	.align 2, 0
_0801A4AC: .4byte 0x082C324C
_0801A4B0:
	mov r1, sl
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r2, [r3]
_0801A4BC:
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
_0801A4C2:
	adds r4, r6, #0
	cmp r4, #0x1e
	bls _0801A45E
	mov r0, r8
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801A434

	thumb_func_start sub_0801A4DC
sub_0801A4DC: @ 0x0801A4DC
	push {r4, lr}
	movs r4, #0
	adds r3, r1, #0
	adds r2, r0, #0
_0801A4E4:
	ldr r1, [r2]
	ldr r0, [r3]
	cmp r1, r0
	beq _0801A4F0
	movs r0, #1
	b _0801A4FC
_0801A4F0:
	adds r3, #4
	adds r2, #4
	adds r4, #1
	cmp r4, #3
	ble _0801A4E4
	movs r0, #0
_0801A4FC:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0801A4DC

	thumb_func_start sub_0801A504
sub_0801A504: @ 0x0801A504
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov sb, r1
	adds r5, r2, #0
	lsls r4, r3, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0
	mov r8, r0
	mov r0, sp
	movs r1, #0
	movs r2, #0x10
	bl memset
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r1, _0801A56C
	adds r7, r0, r1
	movs r4, #0
_0801A532:
	lsls r1, r4, #5
	ldr r0, [r7]
	adds r0, r0, r1
	mov r1, sp
	bl sub_0801A434
	adds r1, r0, #0
	ldr r0, [r5]
	cmp r1, r0
	beq _0801A54C
	str r1, [r5]
	movs r2, #1
	mov r8, r2
_0801A54C:
	adds r5, #4
	adds r4, #1
	cmp r4, #0xf
	ble _0801A532
	mov r0, sp
	mov r1, sb
	bl sub_0801A4DC
	cmp r0, #0
	bne _0801A570
	mov r3, r8
	cmp r3, #1
	beq _0801A598
	movs r0, #0
	b _0801A59A
	.align 2, 0
_0801A56C: .4byte 0x03005B68
_0801A570:
	adds r1, r6, #0
	mov r0, sp
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	mov r1, sb
	mov r0, sp
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	adds r0, r0, r1
	ldr r1, [r6, #8]
	adds r0, r0, r1
	ldr r1, [r6, #0xc]
	adds r0, r0, r1
	str r0, [r6, #0xc]
_0801A598:
	movs r0, #1
_0801A59A:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_0801A504

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
