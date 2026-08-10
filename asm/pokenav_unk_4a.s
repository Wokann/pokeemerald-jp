.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_081CAA04
sub_081CAA04: @ 0x081CAA04
	push {r4, lr}
	ldr r1, _081CAA2C
	movs r0, #6
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CAA38
	movs r0, #0
	strb r0, [r4, #0x19]
	ldr r0, _081CAA30
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r4, #4]
	ldr r0, _081CAA34
	str r0, [r4]
	movs r0, #1
	b _081CAA3A
	.align 2, 0
_081CAA2C: .4byte 0x00002048
_081CAA30: .4byte 0x081CAAC9
_081CAA34: .4byte 0x081CAAB5
_081CAA38:
	movs r0, #0
_081CAA3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_081CAA04

	thumb_func_start sub_081CAA40
sub_081CAA40: @ 0x081CAA40
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	ldr r0, _081CAA68
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r0, [r4]
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r5, #4]
	ldr r0, _081CAA6C
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CAA68: .4byte 0x085F4138
_081CAA6C: .4byte 0x081CAAB5
	thumb_func_end sub_081CAA40

	thumb_func_start sub_081CAA70
sub_081CAA70: @ 0x081CAA70
	push {lr}
	movs r0, #6
	bl GetSubstructPtr
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	thumb_func_end sub_081CAA70

	thumb_func_start sub_081CAA80
sub_081CAA80: @ 0x081CAA80
	bx r1
	.align 2, 0
	thumb_func_end sub_081CAA80

	thumb_func_start sub_081CAA84
sub_081CAA84: @ 0x081CAA84
	push {r4, lr}
	movs r0, #6
	bl GetSubstructPtr
	adds r4, r0, #0
	bl sub_081CBA08
	bl sub_081CB38C
	ldrb r0, [r4, #0x12]
	bl RemoveWindow
	ldrb r0, [r4, #0x10]
	bl RemoveWindow
	ldrb r0, [r4, #0x14]
	bl RemoveWindow
	movs r0, #6
	bl FreePokenavSubstruct
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081CAA84

	thumb_func_start sub_081CAAB4
sub_081CAAB4: @ 0x081CAAB4
	push {lr}
	movs r0, #6
	bl GetSubstructPtr
	ldr r0, [r0, #4]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CAAB4

	thumb_func_start sub_081CAAC8
sub_081CAAC8: @ 0x081CAAC8
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #7
	bls _081CAADC
	b _081CACA8
_081CAADC:
	lsls r0, r4, #2
	ldr r1, _081CAAE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CAAE8: .4byte 0x081CAAEC
_081CAAEC: @ jump table
	.4byte _081CAB0C @ case 0
	.4byte _081CAB78 @ case 1
	.4byte _081CABC8 @ case 2
	.4byte _081CAC0C @ case 3
	.4byte _081CAC26 @ case 4
	.4byte _081CAC38 @ case 5
	.4byte _081CAC4A @ case 6
	.4byte _081CAC8E @ case 7
_081CAB0C:
	ldr r0, _081CAB64
	movs r1, #3
	bl InitBgTemplates
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	ldr r1, _081CAB68
	movs r0, #0
	str r0, [sp]
	movs r0, #2
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	ldr r0, _081CAB6C
	adds r1, r5, r0
	movs r0, #2
	bl SetBgTilemapBuffer
	ldr r1, _081CAB70
	movs r0, #2
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	movs r0, #2
	bl CopyBgTilemapBufferToVram
	ldr r0, _081CAB74
	movs r1, #0x20
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, #2
	b _081CABBC
	.align 2, 0
_081CAB64: .4byte 0x085F412C
_081CAB68: .4byte 0x085F3ED0
_081CAB6C: .4byte 0x00001024
_081CAB70: .4byte 0x085F3F74
_081CAB74: .4byte 0x085F3EB0
_081CAB78:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CAB84
	b _081CAC9E
_081CAB84:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl BgDmaFill
	adds r1, r5, #0
	adds r1, #0x24
	movs r0, #1
	bl SetBgTilemapBuffer
	movs r1, #0x80
	lsls r1, r1, #5
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	ldr r0, _081CABC4
	movs r1, #0x10
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, #1
_081CABBC:
	bl CopyBgTilemapBufferToVram
	movs r0, #0
	b _081CACAA
	.align 2, 0
_081CABC4: .4byte 0x085F4080
_081CABC8:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _081CAC9E
	adds r0, r5, #0
	bl sub_081CB780
	ldr r1, _081CAC00
	str r4, [sp]
	movs r0, #3
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	ldr r0, _081CAC04
	movs r1, #0x30
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	ldr r0, _081CAC08
	movs r1, #0x50
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, #0
	b _081CACAA
	.align 2, 0
_081CAC00: .4byte 0x085F4100
_081CAC04: .4byte 0x085F40A0
_081CAC08: .4byte 0x085F40C0
_081CAC0C:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CAC9E
	bl IsMatchCallListInitFinished
	cmp r0, #0
	beq _081CAC9E
	bl sub_081CB32C
	movs r0, #0
	b _081CACAA
_081CAC26:
	bl IsCreatePokenavListTaskActive
	cmp r0, #0
	bne _081CAC9E
	adds r0, r5, #0
	bl sub_081CB4E8
	movs r0, #0
	b _081CACAA
_081CAC38:
	adds r0, r5, #0
	bl sub_081CB530
	adds r0, r5, #0
	movs r1, #0
	bl sub_081CB640
	movs r0, #0
	b _081CACAA
_081CAC4A:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #2
	bl ShowBg
	movs r0, #3
	bl ShowBg
	movs r0, #1
	bl ShowBg
	bl sub_081CB968
	movs r0, #3
	bl LoadLeftHeaderGfxForIndex
	movs r0, #3
	movs r1, #1
	movs r2, #0
	bl ShowLeftHeaderGfx
	movs r0, #1
	bl PokenavFadeScreen
	movs r0, #0
	b _081CACAA
_081CAC8E:
	bl IsPaletteFadeActive
	cmp r0, #0
	bne _081CAC9E
	bl AreLeftHeaderSpritesMoving
	cmp r0, #0
	beq _081CACA2
_081CAC9E:
	movs r0, #2
	b _081CACAA
_081CACA2:
	movs r0, #1
	bl sub_081CB3A8
_081CACA8:
	movs r0, #4
_081CACAA:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CAAC8

	thumb_func_start sub_081CACB4
sub_081CACB4: @ 0x081CACB4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CACF4
	cmp r4, #1
	bgt _081CACCE
	cmp r4, #0
	beq _081CACD8
	b _081CAD16
_081CACCE:
	cmp r4, #2
	beq _081CACFC
	cmp r4, #3
	beq _081CAD08
	b _081CAD16
_081CACD8:
	movs r0, #5
	bl PlaySE
	bl PokenavList_MoveCursorDown
	cmp r0, #1
	beq _081CACF0
	cmp r0, #1
	bgt _081CAD04
	cmp r0, #0
	bne _081CAD04
	b _081CAD16
_081CACF0:
	movs r0, #7
	b _081CAD18
_081CACF4:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CAD12
_081CACFC:
	adds r0, r5, #0
	movs r1, #0
	bl sub_081CB640
_081CAD04:
	movs r0, #0
	b _081CAD18
_081CAD08:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CAD16
_081CAD12:
	movs r0, #2
	b _081CAD18
_081CAD16:
	movs r0, #4
_081CAD18:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CACB4

	thumb_func_start sub_081CAD20
sub_081CAD20: @ 0x081CAD20
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CAD60
	cmp r4, #1
	bgt _081CAD3A
	cmp r4, #0
	beq _081CAD44
	b _081CAD82
_081CAD3A:
	cmp r4, #2
	beq _081CAD68
	cmp r4, #3
	beq _081CAD74
	b _081CAD82
_081CAD44:
	movs r0, #5
	bl PlaySE
	bl PokenavList_MoveCursorUp
	cmp r0, #1
	beq _081CAD5C
	cmp r0, #1
	bgt _081CAD70
	cmp r0, #0
	bne _081CAD70
	b _081CAD82
_081CAD5C:
	movs r0, #7
	b _081CAD84
_081CAD60:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CAD7E
_081CAD68:
	adds r0, r5, #0
	movs r1, #0
	bl sub_081CB640
_081CAD70:
	movs r0, #0
	b _081CAD84
_081CAD74:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CAD82
_081CAD7E:
	movs r0, #2
	b _081CAD84
_081CAD82:
	movs r0, #4
_081CAD84:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CAD20

	thumb_func_start sub_081CAD8C
sub_081CAD8C: @ 0x081CAD8C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CADCC
	cmp r4, #1
	bgt _081CADA6
	cmp r4, #0
	beq _081CADB0
	b _081CADEE
_081CADA6:
	cmp r4, #2
	beq _081CADD4
	cmp r4, #3
	beq _081CADE0
	b _081CADEE
_081CADB0:
	movs r0, #5
	bl PlaySE
	bl PokenavList_PageDown
	cmp r0, #1
	beq _081CADC8
	cmp r0, #1
	bgt _081CADDC
	cmp r0, #0
	bne _081CADDC
	b _081CADEE
_081CADC8:
	movs r0, #7
	b _081CADF0
_081CADCC:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CADEA
_081CADD4:
	adds r0, r5, #0
	movs r1, #0
	bl sub_081CB640
_081CADDC:
	movs r0, #0
	b _081CADF0
_081CADE0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CADEE
_081CADEA:
	movs r0, #2
	b _081CADF0
_081CADEE:
	movs r0, #4
_081CADF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CAD8C

	thumb_func_start sub_081CADF8
sub_081CADF8: @ 0x081CADF8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CAE38
	cmp r4, #1
	bgt _081CAE12
	cmp r4, #0
	beq _081CAE1C
	b _081CAE5A
_081CAE12:
	cmp r4, #2
	beq _081CAE40
	cmp r4, #3
	beq _081CAE4C
	b _081CAE5A
_081CAE1C:
	movs r0, #5
	bl PlaySE
	bl PokenavList_PageUp
	cmp r0, #1
	beq _081CAE34
	cmp r0, #1
	bgt _081CAE48
	cmp r0, #0
	bne _081CAE48
	b _081CAE5A
_081CAE34:
	movs r0, #7
	b _081CAE5C
_081CAE38:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CAE56
_081CAE40:
	adds r0, r5, #0
	movs r1, #0
	bl sub_081CB640
_081CAE48:
	movs r0, #0
	b _081CAE5C
_081CAE4C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CAE5A
_081CAE56:
	movs r0, #2
	b _081CAE5C
_081CAE5A:
	movs r0, #4
_081CAE5C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CADF8

	thumb_func_start sub_081CAE64
sub_081CAE64: @ 0x081CAE64
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #0
	beq _081CAE7A
	cmp r4, #1
	beq _081CAE90
	b _081CAE9E
_081CAE7A:
	movs r0, #5
	bl PlaySE
	adds r0, r5, #0
	bl sub_081CB6AC
	movs r0, #7
	bl PrintHelpBarText
	movs r0, #0
	b _081CAEA0
_081CAE90:
	adds r0, r5, #0
	bl sub_081CB710
	cmp r0, #0
	beq _081CAE9E
	movs r0, #2
	b _081CAEA0
_081CAE9E:
	movs r0, #4
_081CAEA0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CAE64

	thumb_func_start sub_081CAEA8
sub_081CAEA8: @ 0x081CAEA8
	push {r4, lr}
	movs r0, #5
	bl PlaySE
	movs r0, #6
	bl GetSubstructPtr
	adds r4, r0, #0
	bl GetMatchCallOptionCursorPos
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_081CBA98
	movs r0, #4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_081CAEA8

	thumb_func_start sub_081CAED0
sub_081CAED0: @ 0x081CAED0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #0
	beq _081CAEE6
	cmp r4, #1
	beq _081CAEFC
	b _081CAF0A
_081CAEE6:
	movs r0, #5
	bl PlaySE
	adds r0, r5, #0
	bl sub_081CB73C
	movs r0, #6
	bl PrintHelpBarText
	movs r0, #0
	b _081CAF0C
_081CAEFC:
	adds r0, r5, #0
	bl sub_081CB750
	cmp r0, #0
	beq _081CAF0A
	movs r0, #2
	b _081CAF0C
_081CAF0A:
	movs r0, #4
_081CAF0C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CAED0

	thumb_func_start sub_081CAF14
sub_081CAF14: @ 0x081CAF14
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CAF48
	cmp r4, #1
	bgt _081CAF2E
	cmp r4, #0
	beq _081CAF38
	b _081CAF8E
_081CAF2E:
	cmp r4, #2
	beq _081CAF6C
	cmp r4, #3
	beq _081CAF80
	b _081CAF8E
_081CAF38:
	movs r0, #1
	bl PokenavList_ToggleVerticalArrows
	adds r0, r5, #0
	bl sub_081CB7A4
	movs r0, #0
	b _081CAF90
_081CAF48:
	adds r0, r5, #0
	bl sub_081CB81C
	adds r4, r0, #0
	cmp r4, #0
	bne _081CAF8A
	adds r0, r5, #0
	bl sub_081CB82C
	ldr r0, _081CAF68
	bl PlaySE
	strb r4, [r5, #0xe]
	movs r0, #0
	b _081CAF90
	.align 2, 0
_081CAF68: .4byte 0x00000107
_081CAF6C:
	adds r0, r5, #0
	bl sub_081CB854
	cmp r0, #0
	bne _081CAF8A
	adds r0, r5, #0
	bl sub_081CB8AC
	movs r0, #0
	b _081CAF90
_081CAF80:
	adds r0, r5, #0
	bl sub_081CB8E8
	cmp r0, #0
	beq _081CAF8E
_081CAF8A:
	movs r0, #2
	b _081CAF90
_081CAF8E:
	movs r0, #4
_081CAF90:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CAF14

	thumb_func_start sub_081CAF98
sub_081CAF98: @ 0x081CAF98
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CAFD2
	cmp r4, #1
	bgt _081CAFB2
	cmp r4, #0
	beq _081CAFB8
	b _081CAFF4
_081CAFB2:
	cmp r4, #2
	beq _081CAFE6
	b _081CAFF4
_081CAFB8:
	movs r0, #5
	bl PlaySE
	adds r0, r5, #0
	bl sub_081CB7E8
	movs r0, #1
	bl PokenavList_ToggleVerticalArrows
	movs r0, #1
	strb r0, [r5, #0xe]
	movs r0, #0
	b _081CAFF6
_081CAFD2:
	adds r0, r5, #0
	bl sub_081CB81C
	cmp r0, #0
	bne _081CAFF0
	adds r0, r5, #0
	bl sub_081CB86C
	movs r0, #0
	b _081CAFF6
_081CAFE6:
	adds r0, r5, #0
	bl sub_081CB894
	cmp r0, #0
	beq _081CAFF4
_081CAFF0:
	movs r0, #2
	b _081CAFF6
_081CAFF4:
	movs r0, #4
_081CAFF6:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CAF98

	thumb_func_start sub_081CAFFC
sub_081CAFFC: @ 0x081CAFFC
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r4, r0, #0
	movs r6, #0
	cmp r5, #6
	bhi _081CB0A8
	lsls r0, r5, #2
	ldr r1, _081CB018
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CB018: .4byte 0x081CB01C
_081CB01C: @ jump table
	.4byte _081CB038 @ case 0
	.4byte _081CB04E @ case 1
	.4byte _081CB056 @ case 2
	.4byte _081CB064 @ case 3
	.4byte _081CB06C @ case 4
	.4byte _081CB080 @ case 5
	.4byte _081CB096 @ case 6
_081CB038:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	bne _081CB046
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySE
_081CB046:
	movs r0, #5
	bl PlaySE
	b _081CB0A8
_081CB04E:
	adds r0, r4, #0
	bl sub_081CB930
	b _081CB0A8
_081CB056:
	adds r0, r4, #0
	bl sub_081CB958
	cmp r0, #0
	beq _081CB0A8
_081CB060:
	movs r6, #2
	b _081CB0A8
_081CB064:
	adds r0, r4, #0
	bl sub_081CB73C
	b _081CB0A8
_081CB06C:
	adds r0, r4, #0
	bl sub_081CB750
	cmp r0, #0
	beq _081CB078
	movs r6, #2
_081CB078:
	movs r0, #6
	bl PrintHelpBarText
	b _081CB0A8
_081CB080:
	bl WaitForHelpBar
	cmp r0, #0
	bne _081CB060
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _081CB0A0
	bl PokenavList_DrawCurrentItemIcon
	movs r6, #1
	b _081CB0A8
_081CB096:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CB060
_081CB0A0:
	movs r0, #0
	bl PokenavList_ToggleVerticalArrows
	movs r6, #4
_081CB0A8:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_081CAFFC

	thumb_func_start sub_081CB0B0
sub_081CB0B0: @ 0x081CB0B0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CB0E8
	cmp r4, #1
	bgt _081CB0CA
	cmp r4, #0
	beq _081CB0D4
	b _081CB132
_081CB0CA:
	cmp r4, #2
	beq _081CB104
	cmp r4, #3
	beq _081CB114
	b _081CB132
_081CB0D4:
	movs r0, #5
	bl PlaySE
	bl PokenavList_EraseListForCheckPage
	adds r0, r5, #0
	bl sub_081CB760
	movs r0, #0
	b _081CB134
_081CB0E8:
	bl PokenavList_IsTaskActive
	cmp r0, #0
	bne _081CB12E
	adds r0, r5, #0
	bl sub_081CB750
	cmp r0, #0
	bne _081CB12E
	movs r0, #8
	bl PrintHelpBarText
	movs r0, #0
	b _081CB134
_081CB104:
	movs r0, #0
	bl PrintCheckPageInfo
	adds r0, r5, #0
	bl sub_081CBAF0
	movs r0, #0
	b _081CB134
_081CB114:
	bl PokenavList_IsTaskActive
	cmp r0, #0
	bne _081CB12E
	adds r0, r5, #0
	bl sub_081CBB80
	cmp r0, #0
	bne _081CB12E
	bl WaitForHelpBar
	cmp r0, #0
	beq _081CB132
_081CB12E:
	movs r0, #2
	b _081CB134
_081CB132:
	movs r0, #4
_081CB134:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CB0B0

	thumb_func_start sub_081CB13C
sub_081CB13C: @ 0x081CB13C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r4, r0, #0
	cmp r5, #4
	bhi _081CB1D4
	lsls r0, r5, #2
	ldr r1, _081CB158
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CB158: .4byte 0x081CB15C
_081CB15C: @ jump table
	.4byte _081CB170 @ case 0
	.4byte _081CB190 @ case 1
	.4byte _081CB1A8 @ case 2
	.4byte _081CB1B4 @ case 3
	.4byte _081CB1BE @ case 4
_081CB170:
	bl PokenavList_GetTopIndex
	bl GetIndexDeltaOfNextCheckPageDown
	adds r5, r0, #0
	cmp r5, #0
	beq _081CB1D4
	movs r0, #5
	bl PlaySE
	strh r5, [r4, #0x16]
	adds r0, r4, #0
	bl sub_081CBB74
	movs r0, #0
	b _081CB1D6
_081CB190:
	adds r0, r4, #0
	bl sub_081CBB80
	cmp r0, #0
	bne _081CB1D0
	movs r0, #0x16
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	bl sub_081CB640
	movs r0, #0
	b _081CB1D6
_081CB1A8:
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	bl PrintCheckPageInfo
	movs r0, #0
	b _081CB1D6
_081CB1B4:
	adds r0, r4, #0
	bl sub_081CBAF0
	movs r0, #0
	b _081CB1D6
_081CB1BE:
	bl PokenavList_IsTaskActive
	cmp r0, #0
	bne _081CB1D0
	adds r0, r4, #0
	bl sub_081CBB80
	cmp r0, #0
	beq _081CB1D4
_081CB1D0:
	movs r0, #2
	b _081CB1D6
_081CB1D4:
	movs r0, #4
_081CB1D6:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CB13C

	thumb_func_start sub_081CB1DC
sub_081CB1DC: @ 0x081CB1DC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CB210
	cmp r4, #1
	bgt _081CB1F6
	cmp r4, #0
	beq _081CB1FC
	b _081CB240
_081CB1F6:
	cmp r4, #2
	beq _081CB232
	b _081CB240
_081CB1FC:
	movs r0, #5
	bl PlaySE
	adds r0, r5, #0
	bl sub_081CBB74
	bl PokenavList_ReshowListFromCheckPage
	movs r0, #0
	b _081CB242
_081CB210:
	bl PokenavList_IsTaskActive
	cmp r0, #0
	bne _081CB23C
	adds r0, r5, #0
	bl sub_081CBB80
	cmp r0, #0
	bne _081CB23C
	movs r0, #6
	bl PrintHelpBarText
	adds r0, r5, #0
	bl sub_081CB530
	movs r0, #0
	b _081CB242
_081CB232:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CB240
_081CB23C:
	movs r0, #2
	b _081CB242
_081CB240:
	movs r0, #4
_081CB242:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CB1DC

	thumb_func_start sub_081CB248
sub_081CB248: @ 0x081CB248
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #6
	bl GetSubstructPtr
	adds r4, r0, #0
	cmp r5, #4
	bhi _081CB2E0
	lsls r0, r5, #2
	ldr r1, _081CB264
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CB264: .4byte 0x081CB268
_081CB268: @ jump table
	.4byte _081CB27C @ case 0
	.4byte _081CB29C @ case 1
	.4byte _081CB2B4 @ case 2
	.4byte _081CB2C0 @ case 3
	.4byte _081CB2CA @ case 4
_081CB27C:
	bl PokenavList_GetTopIndex
	bl GetIndexDeltaOfNextCheckPageUp
	adds r5, r0, #0
	cmp r5, #0
	beq _081CB2E0
	movs r0, #5
	bl PlaySE
	strh r5, [r4, #0x16]
	adds r0, r4, #0
	bl sub_081CBB74
	movs r0, #0
	b _081CB2E2
_081CB29C:
	adds r0, r4, #0
	bl sub_081CBB80
	cmp r0, #0
	bne _081CB2DC
	movs r0, #0x16
	ldrsh r1, [r4, r0]
	adds r0, r4, #0
	bl sub_081CB640
	movs r0, #0
	b _081CB2E2
_081CB2B4:
	movs r1, #0x16
	ldrsh r0, [r4, r1]
	bl PrintCheckPageInfo
	movs r0, #0
	b _081CB2E2
_081CB2C0:
	adds r0, r4, #0
	bl sub_081CBAF0
	movs r0, #0
	b _081CB2E2
_081CB2CA:
	bl PokenavList_IsTaskActive
	cmp r0, #0
	bne _081CB2DC
	adds r0, r4, #0
	bl sub_081CBB80
	cmp r0, #0
	beq _081CB2E0
_081CB2DC:
	movs r0, #2
	b _081CB2E2
_081CB2E0:
	movs r0, #4
_081CB2E2:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CB248

	thumb_func_start sub_081CB2E8
sub_081CB2E8: @ 0x081CB2E8
	push {lr}
	cmp r0, #0
	beq _081CB2F4
	cmp r0, #1
	beq _081CB30E
	b _081CB326
_081CB2F4:
	movs r0, #5
	bl PlaySE
	movs r0, #0
	bl sub_081CB3A8
	movs r0, #0
	bl PokenavFadeScreen
	bl SlideMenuHeaderDown
	movs r0, #0
	b _081CB328
_081CB30E:
	bl IsPaletteFadeActive
	cmp r0, #0
	bne _081CB31E
	bl MainMenuLoopedTaskIsBusy
	cmp r0, #0
	beq _081CB322
_081CB31E:
	movs r0, #2
	b _081CB328
_081CB322:
	bl SetLeftHeaderSpritesInvisibility
_081CB326:
	movs r0, #4
_081CB328:
	pop {r1}
	bx r1
	thumb_func_end sub_081CB2E8

	thumb_func_start sub_081CB32C
sub_081CB32C: @ 0x081CB32C
	push {lr}
	sub sp, #0x18
	bl GetMatchCallList
	str r0, [sp]
	bl GetNumberRegistered
	mov r1, sp
	movs r2, #0
	strh r0, [r1, #4]
	movs r0, #4
	strb r0, [r1, #8]
	mov r0, sp
	strh r2, [r0, #6]
	movs r0, #0xe
	strb r0, [r1, #9]
	movs r0, #0xf
	strb r0, [r1, #0xa]
	movs r0, #1
	strb r0, [r1, #0xb]
	movs r0, #8
	strb r0, [r1, #0xc]
	movs r0, #3
	strb r0, [r1, #0xd]
	ldr r0, _081CB37C
	str r0, [sp, #0x10]
	ldr r0, _081CB380
	str r0, [sp, #0x14]
	ldr r0, _081CB384
	movs r2, #2
	bl CreatePokenavList
	ldr r0, _081CB388
	movs r1, #7
	bl CreateTask
	add sp, #0x18
	pop {r0}
	bx r0
	.align 2, 0
_081CB37C: .4byte 0x081CA7F5
_081CB380: .4byte 0x081CB45D
_081CB384: .4byte 0x085F4134
_081CB388: .4byte 0x081CB3D5
	thumb_func_end sub_081CB32C

	thumb_func_start sub_081CB38C
sub_081CB38C: @ 0x081CB38C
	push {lr}
	bl DestroyPokenavList
	ldr r0, _081CB3A4
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl DestroyTask
	pop {r0}
	bx r0
	.align 2, 0
_081CB3A4: .4byte 0x081CB3D5
	thumb_func_end sub_081CB38C

	thumb_func_start sub_081CB3A8
sub_081CB3A8: @ 0x081CB3A8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081CB3CC
	bl FindTaskIdByFunc
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xff
	beq _081CB3C6
	ldr r1, _081CB3D0
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	adds r0, r0, r1
	strh r4, [r0, #0x26]
_081CB3C6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CB3CC: .4byte 0x081CB3D5
_081CB3D0: .4byte 0x03005B60
	thumb_func_end sub_081CB3A8

	thumb_func_start sub_081CB3D4
sub_081CB3D4: @ 0x081CB3D4
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _081CB440
	adds r2, r1, r0
	movs r1, #0x1e
	ldrsh r0, [r2, r1]
	cmp r0, #0
	beq _081CB438
	ldrh r0, [r2]
	adds r0, #4
	movs r1, #0x7f
	ands r0, r1
	strh r0, [r2]
	ldr r1, _081CB444
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r2, #2]
	ldr r0, _081CB448
	adds r1, r0, #0
	adds r1, #0x20
	movs r3, #2
	ldrsh r2, [r2, r3]
	str r2, [sp]
	ldr r4, _081CB44C
	str r4, [sp, #4]
	movs r2, #0x10
	movs r3, #0x10
	bl PokenavCopyPalette
	ldr r0, _081CB450
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _081CB438
	ldr r1, _081CB454
	ldr r2, _081CB458
	adds r0, r4, #0
	bl CpuSet
_081CB438:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CB440: .4byte 0x03005B68
_081CB444: .4byte 0x082FA8CC
_081CB448: .4byte 0x085F40C0
_081CB44C: .4byte 0x02037454
_081CB450: .4byte 0x02037C74
_081CB454: .4byte 0x02037854
_081CB458: .4byte 0x04000008
	thumb_func_end sub_081CB3D4

	thumb_func_start sub_081CB45C
sub_081CB45C: @ 0x081CB45C
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl GetWindowAttribute
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBgTilemapBuffer
	adds r6, r0, #0
	lsls r4, r4, #7
	adds r4, #0x3a
	adds r6, r6, r4
	adds r0, r5, #0
	bl ShouldDrawRematchPokeballIcon
	cmp r0, #0
	beq _081CB4A0
	movs r1, #0xa0
	lsls r1, r1, #7
	adds r0, r1, #0
	strh r0, [r6]
	adds r1, r6, #0
	adds r1, #0x40
	ldr r2, _081CB49C
	adds r0, r2, #0
	strh r0, [r1]
	b _081CB4AC
	.align 2, 0
_081CB49C: .4byte 0x00005001
_081CB4A0:
	ldr r0, _081CB4B4
	adds r1, r0, #0
	strh r1, [r6]
	adds r0, r6, #0
	adds r0, #0x40
	strh r1, [r0]
_081CB4AC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081CB4B4: .4byte 0x00005002
	thumb_func_end sub_081CB45C

	thumb_func_start sub_081CB4B8
sub_081CB4B8: @ 0x081CB4B8
	push {r4, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl GetWindowAttribute
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBgTilemapBuffer
	lsls r4, r4, #7
	adds r4, #0x3a
	adds r0, r0, r4
	ldr r2, _081CB4E4
	adds r1, r2, #0
	strh r1, [r0]
	adds r0, #0x40
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CB4E4: .4byte 0x00005002
	thumb_func_end sub_081CB4B8

	thumb_func_start sub_081CB4E8
sub_081CB4E8: @ 0x081CB4E8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081CB528
	bl AddWindow
	strh r0, [r4, #0x10]
	ldr r0, _081CB52C
	bl AddWindow
	strh r0, [r4, #0x12]
	ldrb r0, [r4, #0x10]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, #0x10]
	bl PutWindowTilemap
	ldrb r0, [r4, #0x12]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, #0x12]
	bl PutWindowTilemap
	ldrb r0, [r4, #0x10]
	movs r1, #1
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CB528: .4byte 0x085F4178
_081CB52C: .4byte 0x085F4180
	thumb_func_end sub_081CB4E8

	thumb_func_start sub_081CB530
sub_081CB530: @ 0x081CB530
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x12]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldrh r0, [r4, #0x12]
	bl sub_081CB564
	ldrh r0, [r4, #0x12]
	bl sub_081CB57C
	ldrh r0, [r4, #0x12]
	bl sub_081CB5A8
	ldrh r0, [r4, #0x12]
	bl sub_081CB5C0
	ldrb r0, [r4, #0x12]
	movs r1, #2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081CB530

	thumb_func_start sub_081CB564
sub_081CB564: @ 0x081CB564
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081CB578
	movs r2, #0
	bl sub_081CB5F8
	pop {r0}
	bx r0
	.align 2, 0
_081CB578: .4byte 0x085CB6AE
	thumb_func_end sub_081CB564

	thumb_func_start sub_081CB57C
sub_081CB57C: @ 0x081CB57C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl GetNumberRegistered
	adds r1, r0, #0
	mov r0, sp
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	adds r0, r4, #0
	mov r1, sp
	movs r2, #1
	bl sub_081CB5F8
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081CB57C

	thumb_func_start sub_081CB5A8
sub_081CB5A8: @ 0x081CB5A8
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081CB5BC
	movs r2, #2
	bl sub_081CB5F8
	pop {r0}
	bx r0
	.align 2, 0
_081CB5BC: .4byte 0x085CB6B8
	thumb_func_end sub_081CB5A8

	thumb_func_start sub_081CB5C0
sub_081CB5C0: @ 0x081CB5C0
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #9
	bl GetGameStat
	adds r1, r0, #0
	ldr r0, _081CB5F4
	cmp r1, r0
	ble _081CB5D8
	adds r1, r0, #0
_081CB5D8:
	mov r0, sp
	movs r2, #0
	movs r3, #5
	bl ConvertIntToDecimalStringN
	adds r0, r4, #0
	mov r1, sp
	movs r2, #3
	bl sub_081CB5F8
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CB5F4: .4byte 0x0001869F
	thumb_func_end sub_081CB5C0

	thumb_func_start sub_081CB5F8
sub_081CB5F8: @ 0x081CB5F8
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #1
	bl GetStringWidth
	movs r3, #0x54
	subs r3, r3, r0
	lsls r4, r4, #4
	adds r4, #2
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r1, #1
	adds r2, r6, #0
	bl AddTextPrinterParameterized
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_081CB5F8

	thumb_func_start sub_081CB640
sub_081CB640: @ 0x081CB640
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r4, r1, #0
	bl PokenavList_GetSelectedIndex
	adds r0, r0, r4
	bl GetMatchCallMapSec
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xd5
	beq _081CB664
	add r0, sp, #0xc
	movs r2, #0
	bl GetMapName
	b _081CB66C
_081CB664:
	ldr r1, _081CB6A8
	add r0, sp, #0xc
	bl StringCopy
_081CB66C:
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #1
	add r1, sp, #0xc
	bl GetStringWidth
	movs r4, #0x54
	subs r4, r4, r0
	ldrb r0, [r5, #0x10]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r5, #0x10]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #1
	add r2, sp, #0xc
	adds r3, r4, #0
	bl AddTextPrinterParameterized
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CB6A8: .4byte 0x085CB808
	thumb_func_end sub_081CB640

	thumb_func_start sub_081CB6AC
sub_081CB6AC: @ 0x081CB6AC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldrb r0, [r5, #0x12]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	movs r4, #0
	movs r6, #0x80
	lsls r6, r6, #0x12
	b _081CB6E8
_081CB6C2:
	ldrb r0, [r5, #0x12]
	ldr r2, _081CB70C
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r2, [r1]
	lsrs r1, r6, #0x18
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #0x14
	bl AddTextPrinterParameterized
	movs r0, #0x80
	lsls r0, r0, #0x15
	adds r6, r6, r0
	adds r4, #1
_081CB6E8:
	cmp r4, #2
	bhi _081CB6FA
	adds r0, r4, #0
	bl GetMatchCallOptionId
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #3
	bne _081CB6C2
_081CB6FA:
	ldrb r0, [r5, #0x12]
	movs r1, #2
	bl CopyWindowToVram
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081CB70C: .4byte 0x085F4188
	thumb_func_end sub_081CB6AC

	thumb_func_start sub_081CB710
sub_081CB710: @ 0x081CB710
	push {r4, lr}
	adds r4, r0, #0
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CB722
	movs r0, #1
	b _081CB734
_081CB722:
	bl GetMatchCallOptionCursorPos
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_081CBA44
	movs r0, #0
_081CB734:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CB710

	thumb_func_start sub_081CB73C
sub_081CB73C: @ 0x081CB73C
	push {r4, lr}
	adds r4, r0, #0
	bl sub_081CBA84
	adds r0, r4, #0
	bl sub_081CB530
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081CB73C

	thumb_func_start sub_081CB750
sub_081CB750: @ 0x081CB750
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CB750

	thumb_func_start sub_081CB760
sub_081CB760: @ 0x081CB760
	push {r4, lr}
	adds r4, r0, #0
	bl sub_081CBA84
	ldrb r0, [r4, #0x12]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, #0x12]
	movs r1, #2
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081CB760

	thumb_func_start sub_081CB780
sub_081CB780: @ 0x081CB780
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081CB7A0
	bl AddWindow
	strh r0, [r4, #0x14]
	ldrh r0, [r4, #0x14]
	movs r1, #1
	movs r2, #4
	bl sub_08196D78
	bl FadeToBlackExceptPrimary
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CB7A0: .4byte 0x085F41A8
	thumb_func_end sub_081CB780

	thumb_func_start sub_081CB7A4
sub_081CB7A4: @ 0x081CB7A4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x14]
	movs r1, #1
	movs r2, #4
	bl sub_08196D78
	ldrh r0, [r4, #0x14]
	movs r1, #1
	movs r2, #4
	bl sub_08196DB8
	ldrb r0, [r4, #0x14]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, #0x14]
	bl PutWindowTilemap
	ldrb r0, [r4, #0x14]
	movs r1, #3
	bl CopyWindowToVram
	bl GetSpinningPokenavSprite
	movs r2, #0
	movs r1, #0x18
	strh r1, [r0, #0x20]
	movs r1, #0x70
	strh r1, [r0, #0x22]
	strh r2, [r0, #0x26]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081CB7A4

	thumb_func_start sub_081CB7E8
sub_081CB7E8: @ 0x081CB7E8
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x14]
	movs r1, #1
	movs r2, #0x40
	bl LoadUserWindowBorderGfx
	ldrb r0, [r4, #0x14]
	movs r1, #1
	movs r2, #4
	bl DrawTextBorderOuter
	ldrb r0, [r4, #0x14]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldrb r0, [r4, #0x14]
	bl PutWindowTilemap
	ldrb r0, [r4, #0x14]
	movs r1, #3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081CB7E8

	thumb_func_start sub_081CB81C
sub_081CB81C: @ 0x081CB81C
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CB81C

	thumb_func_start sub_081CB82C
sub_081CB82C: @ 0x081CB82C
	push {lr}
	sub sp, #0xc
	ldrb r0, [r0, #0x14]
	ldr r2, _081CB850
	movs r1, #2
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #0x20
	bl AddTextPrinterParameterized
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081CB850: .4byte 0x085F4194
	thumb_func_end sub_081CB82C

	thumb_func_start sub_081CB854
sub_081CB854: @ 0x081CB854
	push {r4, lr}
	adds r4, r0, #0
	bl RunTextPrinters
	ldrb r0, [r4, #0x14]
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_081CB854

	thumb_func_start sub_081CB86C
sub_081CB86C: @ 0x081CB86C
	push {lr}
	sub sp, #0xc
	ldrb r0, [r0, #0x14]
	ldr r2, _081CB890
	movs r1, #2
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #0x20
	bl AddTextPrinterParameterized
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_081CB890: .4byte 0x085CB7A8
	thumb_func_end sub_081CB86C

	thumb_func_start sub_081CB894
sub_081CB894: @ 0x081CB894
	push {r4, lr}
	adds r4, r0, #0
	bl RunTextPrinters
	ldrb r0, [r4, #0x14]
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_081CB894

	thumb_func_start sub_081CB8AC
sub_081CB8AC: @ 0x081CB8AC
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	bl PokenavList_GetSelectedIndex
	adds r1, r4, #0
	adds r1, #0xf
	bl GetMatchCallMessageText
	adds r5, r0, #0
	bl GetPlayerTextSpeedDelay
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r4, #0x14]
	movs r1, #2
	str r1, [sp]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	adds r0, r2, #0
	movs r1, #1
	adds r2, r5, #0
	movs r3, #0x20
	bl AddTextPrinterParameterized
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_081CB8AC

	thumb_func_start sub_081CB8E8
sub_081CB8E8: @ 0x081CB8E8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081CB904
	ldrh r1, [r0, #0x2c]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081CB90C
	ldr r0, _081CB908
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	strb r1, [r0]
	b _081CB918
	.align 2, 0
_081CB904: .4byte 0x03002360
_081CB908: .4byte 0x030030B4
_081CB90C:
	ldr r2, _081CB92C
	ldrb r1, [r2]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
_081CB918:
	bl RunTextPrinters
	ldrb r0, [r4, #0x14]
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081CB92C: .4byte 0x030030B4
	thumb_func_end sub_081CB8E8

	thumb_func_start sub_081CB930
sub_081CB930: @ 0x081CB930
	push {lr}
	sub sp, #8
	bl HideSpinningPokenavSprite
	movs r0, #0x20
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	add sp, #8
	pop {r0}
	bx r0
	thumb_func_end sub_081CB930

	thumb_func_start sub_081CB958
sub_081CB958: @ 0x081CB958
	push {lr}
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CB958

	thumb_func_start sub_081CB968
sub_081CB968: @ 0x081CB968
	push {r4, r5, r6, lr}
	sub sp, #8
	movs r0, #6
	bl GetSubstructPtr
	adds r6, r0, #0
	movs r5, #0
	ldr r4, _081CB9EC
_081CB978:
	adds r0, r4, #0
	bl LoadCompressedSpriteSheet
	adds r4, #8
	adds r5, #1
	cmp r5, #0
	beq _081CB978
	ldr r0, _081CB9F0
	bl Pokenav_AllocAndLoadPalettes
	movs r0, #0
	str r0, [r6, #0x1c]
	ldr r1, _081CB9F4
	adds r0, r6, r1
	str r0, [sp]
	ldr r1, _081CB9F8
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	ldr r1, _081CB9FC
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	bl LoadSpriteSheet
	ldr r2, _081CBA00
	adds r1, r6, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xb
	ldr r2, _081CBA04
	adds r0, r0, r2
	str r0, [r1]
	movs r0, #0xd
	bl AllocSpritePalette
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r0, [r6, #0x1a]
	bl sub_081CBAC4
	str r0, [r6, #0x20]
	adds r0, #0x3e
	ldrb r1, [r0]
	movs r2, #4
	orrs r1, r2
	strb r1, [r0]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081CB9EC: .4byte 0x085F41B0
_081CB9F0: .4byte 0x085F41B8
_081CB9F4: .4byte 0x00001828
_081CB9F8: .4byte 0xFFFF0000
_081CB9FC: .4byte 0x0000FFFF
_081CBA00: .4byte 0x00001824
_081CBA04: .4byte 0x06010000
	thumb_func_end sub_081CB968

	thumb_func_start sub_081CBA08
sub_081CBA08: @ 0x081CBA08
	push {r4, lr}
	movs r0, #6
	bl GetSubstructPtr
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _081CBA1C
	bl DestroySprite
_081CBA1C:
	ldr r0, [r4, #0x20]
	cmp r0, #0
	beq _081CBA26
	bl DestroySprite
_081CBA26:
	movs r0, #8
	bl FreeSpriteTilesByTag
	movs r0, #7
	bl FreeSpriteTilesByTag
	movs r0, #0xc
	bl FreeSpritePaletteByTag
	movs r0, #0xd
	bl FreeSpritePaletteByTag
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081CBA08

	thumb_func_start sub_081CBA44
sub_081CBA44: @ 0x081CBA44
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	bne _081CBA74
	ldr r0, _081CBA7C
	movs r1, #8
	movs r2, #0x50
	movs r3, #5
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _081CBA80
	adds r1, r1, r0
	str r1, [r4, #0x1c]
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_081CBA98
_081CBA74:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CBA7C: .4byte 0x085F41D0
_081CBA80: .4byte 0x020205AC
	thumb_func_end sub_081CBA44

	thumb_func_start sub_081CBA84
sub_081CBA84: @ 0x081CBA84
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	bl DestroySprite
	movs r0, #0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081CBA84

	thumb_func_start sub_081CBA98
sub_081CBA98: @ 0x081CBA98
	ldr r0, [r0, #0x1c]
	lsls r1, r1, #4
	strh r1, [r0, #0x26]
	bx lr
	thumb_func_end sub_081CBA98

	thumb_func_start sub_081CBAA0
sub_081CBAA0: @ 0x081CBAA0
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x2e]
	adds r0, #1
	strh r0, [r2, #0x2e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	ble _081CBAC0
	movs r0, #0
	strh r0, [r2, #0x2e]
	ldrh r0, [r2, #0x24]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	strh r0, [r2, #0x24]
_081CBAC0:
	pop {r0}
	bx r0
	thumb_func_end sub_081CBAA0

	thumb_func_start sub_081CBAC4
sub_081CBAC4: @ 0x081CBAC4
	push {lr}
	ldr r0, _081CBAE8
	movs r1, #0x2c
	movs r2, #0x68
	movs r3, #6
	bl CreateSprite
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _081CBAEC
	adds r0, r0, r1
	pop {r1}
	bx r1
	.align 2, 0
_081CBAE8: .4byte 0x085F41F0
_081CBAEC: .4byte 0x020205AC
	thumb_func_end sub_081CBAC4

	thumb_func_start sub_081CBAF0
sub_081CBAF0: @ 0x081CBAF0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	bl PokenavList_GetSelectedIndex
	bl GetMatchCallTrainerPic
	cmp r0, #0
	blt _081CBB54
	lsls r4, r0, #3
	ldr r0, _081CBB5C
	adds r0, r4, r0
	ldr r1, _081CBB60
	adds r5, r7, r1
	adds r1, r5, #0
	movs r2, #0
	bl DecompressPicFromTable
	ldr r0, _081CBB64
	adds r4, r4, r0
	ldr r0, [r4]
	ldr r1, _081CBB68
	adds r6, r7, r1
	adds r1, r6, #0
	bl LZ77UnCompWram
	ldr r1, _081CBB6C
	adds r0, r7, r1
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r0, r5, #0
	movs r3, #1
	bl RequestDma3Copy
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrh r1, [r7, #0x1a]
	adds r0, r6, #0
	movs r2, #0x20
	bl LoadPalette
	ldr r1, [r7, #0x20]
	movs r0, #0
	strh r0, [r1, #0x2e]
	ldr r0, [r7, #0x20]
	strh r4, [r0, #0x3c]
	ldr r1, [r7, #0x20]
	ldr r0, _081CBB70
	str r0, [r1, #0x1c]
_081CBB54:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CBB5C: .4byte 0x082D8EE4
_081CBB60: .4byte 0x00001828
_081CBB64: .4byte 0x082D91CC
_081CBB68: .4byte 0x00002028
_081CBB6C: .4byte 0x00001824
_081CBB70: .4byte 0x081CBB95
	thumb_func_end sub_081CBAF0

	thumb_func_start sub_081CBB74
sub_081CBB74: @ 0x081CBB74
	ldr r1, [r0, #0x20]
	ldr r0, _081CBB7C
	str r0, [r1, #0x1c]
	bx lr
	.align 2, 0
_081CBB7C: .4byte 0x081CBBF9
	thumb_func_end sub_081CBB74

	thumb_func_start sub_081CBB80
sub_081CBB80: @ 0x081CBB80
	ldr r0, [r0, #0x20]
	ldr r1, [r0, #0x1c]
	ldr r0, _081CBB90
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	bx lr
	.align 2, 0
_081CBB90: .4byte 0x08007141
	thumb_func_end sub_081CBB80

	thumb_func_start sub_081CBB94
sub_081CBB94: @ 0x081CBB94
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
	cmp r0, #0
	beq _081CBBA6
	cmp r0, #1
	beq _081CBBD8
	b _081CBBEC
_081CBBA6:
	movs r1, #0x3c
	ldrsh r0, [r4, r1]
	bl CheckForSpaceForDma3Request
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	beq _081CBBEC
	ldr r0, _081CBBD4
	strh r0, [r4, #0x24]
	adds r2, r4, #0
	adds r2, #0x3e
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
	b _081CBBEC
	.align 2, 0
_081CBBD4: .4byte 0x0000FFB0
_081CBBD8:
	ldrh r0, [r4, #0x24]
	adds r0, #8
	strh r0, [r4, #0x24]
	lsls r0, r0, #0x10
	cmp r0, #0
	blt _081CBBEC
	movs r0, #0
	strh r0, [r4, #0x24]
	ldr r0, _081CBBF4
	str r0, [r4, #0x1c]
_081CBBEC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CBBF4: .4byte 0x08007141
	thumb_func_end sub_081CBB94

	thumb_func_start sub_081CBBF8
sub_081CBBF8: @ 0x081CBBF8
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x24]
	subs r0, #8
	strh r0, [r3, #0x24]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x50
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _081CBC1E
	adds r2, r3, #0
	adds r2, #0x3e
	ldrb r0, [r2]
	movs r1, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _081CBC24
	str r0, [r3, #0x1c]
_081CBC1E:
	pop {r0}
	bx r0
	.align 2, 0
_081CBC24: .4byte 0x08007141
	thumb_func_end sub_081CBBF8
