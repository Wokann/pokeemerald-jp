.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified








	thumb_func_start FadeToWonderNewsMenu
FadeToWonderNewsMenu: @ 0x0801C2AC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	ldr r4, _0801C2C8
	ldr r0, [r4]
	cmp r0, #0
	bne _0801C2CC
	movs r0, #1
	rsbs r0, r0, #0
	b _0801C572
	.align 2, 0
_0801C2C8: .4byte 0x0202292C
_0801C2CC:
	adds r0, #0xe4
	ldrb r0, [r0]
	lsrs r0, r0, #1
	cmp r0, #6
	bls _0801C2D8
	b _0801C540
_0801C2D8:
	lsls r0, r0, #2
	ldr r1, _0801C2E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801C2E4: .4byte 0x0801C2E8
_0801C2E8: @ jump table
	.4byte _0801C304 @ case 0
	.4byte _0801C316 @ case 1
	.4byte _0801C37C @ case 2
	.4byte _0801C418 @ case 3
	.4byte _0801C4D4 @ case 4
	.4byte _0801C4DA @ case 5
	.4byte _0801C4EC @ case 6
_0801C304:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	b _0801C55A
_0801C316:
	bl UpdatePaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0801C322
	b _0801C570
_0801C322:
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #0x40
	movs r1, #0xf0
	bl SetGpuReg
	ldr r1, _0801C378
	movs r0, #0x44
	bl SetGpuReg
	movs r0, #0x48
	movs r1, #0x1f
	bl SetGpuReg
	movs r0, #0x4a
	movs r1, #0x1b
	bl SetGpuReg
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0
	bl SetGpuRegBits
	b _0801C55A
	.align 2, 0
_0801C378: .4byte 0x00001C98
_0801C37C:
	movs r5, #0x1e
	str r5, [sp]
	movs r4, #0x14
	str r4, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	movs r0, #2
	bl CopyBgTilemapBufferToVram
	movs r0, #3
	bl CopyBgTilemapBufferToVram
	ldr r5, _0801C410
	ldr r0, [r5]
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r1, [r0, #4]
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	movs r2, #0
	movs r3, #8
	bl DecompressAndCopyTileDataToVram
	ldr r4, _0801C414
	adds r0, r4, #0
	bl AddWindow
	ldr r1, [r5]
	adds r1, #0xec
	strh r0, [r1]
	adds r4, #8
	adds r0, r4, #0
	bl AddWindow
	ldr r1, [r5]
	adds r1, #0xee
	strh r0, [r1]
	b _0801C55A
	.align 2, 0
_0801C410: .4byte 0x0202292C
_0801C414: .4byte 0x082C4314
_0801C418:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _0801C426
	b _0801C570
_0801C426:
	movs r0, #1
	bl GetTextWindowPalette
	movs r1, #0x20
	movs r2, #0x20
	bl LoadPalette
	ldr r2, _0801C4CC
	ldrb r0, [r2, #8]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2, #8]
	ldr r0, _0801C4D0
	mov r8, r0
	ldr r0, [r0]
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r0, [r0, #0xc]
	movs r1, #0x10
	movs r2, #0x20
	bl LoadPalette
	mov r2, r8
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #0xe0
	ldr r0, [r0]
	ldr r0, [r0, #8]
	movs r6, #0xf6
	lsls r6, r6, #1
	adds r1, r1, r6
	bl LZ77UnCompWram
	mov r0, r8
	ldr r1, [r0]
	adds r1, r1, r6
	movs r4, #0x1e
	str r4, [sp]
	movs r5, #3
	str r5, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r4, [sp, #0x10]
	str r5, [sp, #0x14]
	movs r2, #1
	mov sl, r2
	str r2, [sp, #0x18]
	movs r0, #8
	mov sb, r0
	str r0, [sp, #0x1c]
	str r7, [sp, #0x20]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl CopyRectToBgTilemapBufferRect
	mov r2, r8
	ldr r1, [r2]
	adds r1, r1, r6
	str r4, [sp]
	movs r0, #0x17
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r5, [sp, #0xc]
	str r4, [sp, #0x10]
	str r0, [sp, #0x14]
	mov r0, sl
	str r0, [sp, #0x18]
	mov r2, sb
	str r2, [sp, #0x1c]
	str r7, [sp, #0x20]
	movs r0, #3
	movs r2, #0
	movs r3, #3
	bl CopyRectToBgTilemapBufferRect
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	movs r0, #3
	bl CopyBgTilemapBufferToVram
	b _0801C55A
	.align 2, 0
_0801C4CC: .4byte 0x02037C74
_0801C4D0: .4byte 0x0202292C
_0801C4D4:
	bl sub_0801C8B4
	b _0801C55A
_0801C4DA:
	bl sub_0801C95C
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #2
	bl CopyBgTilemapBufferToVram
	b _0801C55A
_0801C4EC:
	movs r0, #1
	bl ShowBg
	movs r0, #2
	bl ShowBg
	movs r0, #3
	bl ShowBg
	ldr r2, _0801C538
	ldrb r1, [r2, #8]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2, #8]
	ldr r4, _0801C53C
	ldr r1, [r4]
	movs r2, #0xee
	lsls r2, r2, #1
	adds r0, r1, r2
	adds r1, #0xea
	bl AddScrollIndicatorArrowPair
	ldr r1, [r4]
	adds r1, #0xe5
	movs r2, #0
	strb r0, [r1]
	movs r0, #1
	rsbs r0, r0, #0
	str r2, [sp]
	movs r1, #0
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	b _0801C55A
	.align 2, 0
_0801C538: .4byte 0x02037C74
_0801C53C: .4byte 0x0202292C
_0801C540:
	bl UpdatePaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801C570
	ldr r0, [r4]
	adds r0, #0xe4
	ldrb r2, [r0]
	movs r1, #1
	ands r1, r2
	strb r1, [r0]
	movs r0, #1
	b _0801C572
_0801C55A:
	ldr r0, _0801C584
	ldr r2, [r0]
	adds r2, #0xe4
	ldrb r3, [r2]
	lsrs r1, r3, #1
	adds r1, #1
	lsls r1, r1, #1
	movs r0, #1
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_0801C570:
	movs r0, #0
_0801C572:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801C584: .4byte 0x0202292C
	thumb_func_end FadeToWonderNewsMenu

	thumb_func_start FadeOutFromWonderNews
FadeOutFromWonderNews: @ 0x0801C588
	push {r4, r5, lr}
	sub sp, #8
	ldr r4, _0801C59C
	ldr r0, [r4]
	cmp r0, #0
	bne _0801C5A0
	movs r0, #1
	rsbs r0, r0, #0
	b _0801C746
	.align 2, 0
_0801C59C: .4byte 0x0202292C
_0801C5A0:
	adds r0, #0xe4
	ldrb r0, [r0]
	lsrs r0, r0, #1
	cmp r0, #5
	bls _0801C5AC
	b _0801C714
_0801C5AC:
	lsls r0, r0, #2
	ldr r1, _0801C5B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0801C5B8: .4byte 0x0801C5BC
_0801C5BC: @ jump table
	.4byte _0801C5D4 @ case 0
	.4byte _0801C5E6 @ case 1
	.4byte _0801C628 @ case 2
	.4byte _0801C688 @ case 3
	.4byte _0801C6B0 @ case 4
	.4byte _0801C6E4 @ case 5
_0801C5D4:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	b _0801C72E
_0801C5E6:
	bl UpdatePaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0801C5F2
	b _0801C744
_0801C5F2:
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #0x40
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x44
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x48
	movs r1, #0
	bl SetGpuReg
	movs r0, #0x4a
	movs r1, #0
	bl SetGpuReg
	movs r1, #0x80
	lsls r1, r1, #6
	movs r0, #0
	bl ClearGpuRegBits
	b _0801C72E
_0801C628:
	movs r4, #0x1e
	str r4, [sp]
	movs r5, #0x14
	str r5, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	movs r5, #0x18
	str r5, [sp, #4]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	str r4, [sp]
	str r5, [sp, #4]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	movs r0, #2
	bl CopyBgTilemapBufferToVram
	movs r0, #3
	bl CopyBgTilemapBufferToVram
	b _0801C72E
_0801C688:
	movs r0, #1
	bl HideBg
	movs r0, #2
	bl HideBg
	ldr r4, _0801C6AC
	ldr r0, [r4]
	adds r0, #0xee
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r4]
	adds r0, #0xec
	ldrb r0, [r0]
	bl RemoveWindow
	b _0801C72E
	.align 2, 0
_0801C6AC: .4byte 0x0202292C
_0801C6B0:
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	ldr r4, _0801C6E0
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xe5
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _0801C72E
	bl RemoveScrollIndicatorArrowPair
	ldr r0, [r4]
	adds r0, #0xe5
	movs r1, #0xff
	strb r1, [r0]
	b _0801C72E
	.align 2, 0
_0801C6E0: .4byte 0x0202292C
_0801C6E4:
	ldr r0, _0801C710
	ldrb r0, [r0]
	bl PrintMysteryGiftOrEReaderTopMenu
	movs r0, #3
	bl MG_DrawCheckerboardPattern
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #3
	bl CopyBgTilemapBufferToVram
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	b _0801C72E
	.align 2, 0
_0801C710: .4byte 0x02022914
_0801C714:
	bl UpdatePaletteFade
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0801C744
	ldr r0, [r4]
	adds r0, #0xe4
	ldrb r2, [r0]
	movs r1, #1
	ands r1, r2
	strb r1, [r0]
	movs r0, #1
	b _0801C746
_0801C72E:
	ldr r0, _0801C750
	ldr r2, [r0]
	adds r2, #0xe4
	ldrb r3, [r2]
	lsrs r1, r3, #1
	adds r1, #1
	lsls r1, r1, #1
	movs r0, #1
	ands r0, r3
	orrs r0, r1
	strb r0, [r2]
_0801C744:
	movs r0, #0
_0801C746:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0801C750: .4byte 0x0202292C
	thumb_func_end FadeOutFromWonderNews

