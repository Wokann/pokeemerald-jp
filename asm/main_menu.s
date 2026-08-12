
.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



	thumb_func_start LoadMainMenuWindowFrameTiles
LoadMainMenuWindowFrameTiles: @ 0x08031D9C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r6, _08031DE0
	ldr r0, [r6]
	ldrb r0, [r0, #0x14]
	lsrs r0, r0, #3
	bl GetWindowFrameTilesPal
	ldr r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r4, #0
	adds r3, r5, #0
	bl LoadBgTiles
	ldr r0, [r6]
	ldrb r0, [r0, #0x14]
	lsrs r0, r0, #3
	bl GetWindowFrameTilesPal
	ldr r0, [r0, #4]
	movs r1, #0x20
	movs r2, #0x20
	bl LoadPalette
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08031DE0: .4byte 0x03005AF0
	thumb_func_end LoadMainMenuWindowFrameTiles

	thumb_func_start DrawMainMenuWindowBorder
DrawMainMenuWindowBorder: @ 0x08031DE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	lsls r6, r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #9
	adds r0, r0, r6
	lsrs r0, r0, #0x10
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #0xa
	adds r1, r1, r6
	lsrs r1, r1, #0x10
	mov sl, r1
	movs r7, #0xc0
	lsls r7, r7, #0xa
	adds r1, r6, r7
	lsrs r1, r1, #0x10
	str r1, [sp, #0x18]
	movs r0, #0xa0
	lsls r0, r0, #0xb
	adds r1, r6, r0
	lsrs r1, r1, #0x10
	str r1, [sp, #0xc]
	movs r7, #0xc0
	lsls r7, r7, #0xb
	adds r1, r6, r7
	lsrs r1, r1, #0x10
	str r1, [sp, #0x10]
	movs r0, #0xe0
	lsls r0, r0, #0xb
	adds r1, r6, r0
	lsrs r1, r1, #0x10
	str r1, [sp, #0x14]
	lsrs r1, r6, #0x10
	movs r7, #0x80
	lsls r7, r7, #0xc
	adds r6, r6, r7
	lsrs r6, r6, #0x10
	ldrb r0, [r4]
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r5, #1
	str r5, [sp]
	str r5, [sp, #4]
	movs r7, #2
	mov r8, r7
	str r7, [sp, #8]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #1]
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r1, [r4, #3]
	str r1, [sp]
	str r5, [sp, #4]
	str r7, [sp, #8]
	mov r1, sb
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #3]
	ldrb r1, [r4, #1]
	adds r2, r2, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	subs r3, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	str r7, [sp, #8]
	mov r1, sl
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	str r5, [sp]
	ldrb r1, [r4, #4]
	str r1, [sp, #4]
	str r7, [sp, #8]
	ldr r1, [sp, #0x18]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #3]
	ldrb r7, [r4, #1]
	adds r2, r2, r7
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #2]
	str r5, [sp]
	ldrb r1, [r4, #4]
	str r1, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	ldr r1, [sp, #0xc]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #1]
	subs r2, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #4]
	ldrb r7, [r4, #2]
	adds r3, r3, r7
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	ldr r1, [sp, #0x10]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #1]
	ldrb r3, [r4, #4]
	ldrb r7, [r4, #2]
	adds r3, r3, r7
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r1, [r4, #3]
	str r1, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	ldr r1, [sp, #0x14]
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	ldrb r2, [r4, #3]
	ldrb r7, [r4, #1]
	adds r2, r2, r7
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r3, [r4, #4]
	ldrb r1, [r4, #2]
	adds r3, r3, r1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	str r5, [sp, #4]
	mov r7, r8
	str r7, [sp, #8]
	adds r1, r6, #0
	bl FillBgTilemapBufferRect
	ldrb r0, [r4]
	bl CopyBgTilemapBufferToVram
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end DrawMainMenuWindowBorder

	thumb_func_start ClearMainMenuWindowTilemap
ClearMainMenuWindowTilemap: @ 0x08031F48
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldrb r0, [r6]
	ldrb r1, [r6, #1]
	subs r2, r1, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldrb r4, [r6, #2]
	subs r3, r4, #1
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r5, [r6, #3]
	adds r1, r1, r5
	adds r1, #1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	ldrb r1, [r6, #4]
	adds r4, r4, r1
	adds r4, #1
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #0
	bl FillBgTilemapBufferRect
	ldrb r0, [r6]
	bl CopyBgTilemapBufferToVram
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end ClearMainMenuWindowTilemap

	thumb_func_start NewGameBirchSpeech_ClearGenderWindowTilemap
NewGameBirchSpeech_ClearGenderWindowTilemap: @ 0x08031F90
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, [sp, #0x18]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r4, r4, #0x18
	lsls r5, r5, #0x18
	lsls r3, r3, #0x18
	lsls r1, r1, #0x18
	movs r2, #0xff
	lsls r2, r2, #0x18
	adds r4, r4, r2
	lsrs r4, r4, #0x18
	adds r5, r5, r2
	lsrs r5, r5, #0x18
	movs r2, #0x80
	lsls r2, r2, #0x12
	adds r3, r3, r2
	lsrs r3, r3, #0x18
	str r3, [sp]
	adds r1, r1, r2
	lsrs r1, r1, #0x18
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r1, #0
	adds r2, r4, #0
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end NewGameBirchSpeech_ClearGenderWindowTilemap

	thumb_func_start sub_08031FD8
sub_08031FD8: @ 0x08031FD8
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _0803200C
	adds r0, r5, #0
	bl CallWindowFunction
	adds r0, r5, #0
	movs r1, #0x11
	bl FillWindowPixelBuffer
	adds r0, r5, #0
	bl ClearWindowTilemap
	cmp r4, #1
	bne _08032006
	adds r0, r5, #0
	movs r1, #3
	bl CopyWindowToVram
_08032006:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803200C: .4byte 0x08031F91
	thumb_func_end sub_08031FD8

	thumb_func_start NewGameBirchSpeech_ClearWindow
NewGameBirchSpeech_ClearWindow: @ 0x08032010
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #8
	adds r6, r0, #0
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	movs r0, #1
	movs r1, #6
	bl GetFontAttribute
	mov sb, r0
	mov r0, sb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r0, #1
	movs r1, #0
	bl GetFontAttribute
	mov r8, r0
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r0, #1
	movs r1, #1
	bl GetFontAttribute
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	adds r0, r6, #0
	movs r1, #3
	bl GetWindowAttribute
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r6, #0
	movs r1, #4
	bl GetWindowAttribute
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r1, r8
	muls r1, r4, r1
	str r1, [sp]
	muls r0, r5, r0
	str r0, [sp, #4]
	adds r0, r6, #0
	mov r1, sb
	movs r2, #0
	movs r3, #0
	bl FillWindowPixelRect
	adds r0, r6, #0
	movs r1, #2
	bl CopyWindowToVram
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end NewGameBirchSpeech_ClearWindow

	thumb_func_start NewGameBirchSpeech_ShowPokeBallPrinterCallback
NewGameBirchSpeech_ShowPokeBallPrinterCallback: @ 0x08032098
	push {lr}
	ldr r0, [r0]
	subs r0, #2
	ldrb r0, [r0]
	cmp r0, #8
	bne _080320B8
	ldr r1, _080320BC
	ldrb r0, [r1]
	cmp r0, #0
	bne _080320B8
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080320C0
	movs r1, #0
	bl CreateTask
_080320B8:
	pop {r0}
	bx r0
	.align 2, 0
_080320BC: .4byte 0x020229B8
_080320C0: .4byte 0x080307B1
	thumb_func_end NewGameBirchSpeech_ShowPokeBallPrinterCallback

	thumb_func_start CreateYesNoMenuParameterized
CreateYesNoMenuParameterized: @ 0x080320C4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x20
	adds r4, r0, #0
	adds r5, r1, #0
	mov r8, r2
	ldr r6, [sp, #0x34]
	ldr r1, [sp, #0x38]
	lsls r4, r4, #0x18
	lsls r5, r5, #0x18
	mov r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r4, r4, r0
	lsrs r4, r4, #0x18
	adds r5, r5, r0
	lsrs r5, r5, #0x18
	movs r0, #5
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r3, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	adds r2, r4, #0
	adds r3, r5, #0
	bl CreateWindowTemplate
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	add r0, sp, #0x18
	mov r1, r8
	str r1, [sp]
	str r6, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl CreateYesNoMenuAtPos
	add sp, #0x20
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end CreateYesNoMenuParameterized

	thumb_func_start sub_0803213C
sub_0803213C: @ 0x0803213C
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _08032170
	adds r0, r5, #0
	bl CallWindowFunction
	adds r0, r5, #0
	movs r1, #0x11
	bl FillWindowPixelBuffer
	adds r0, r5, #0
	bl PutWindowTilemap
	cmp r4, #1
	bne _0803216A
	adds r0, r5, #0
	movs r1, #3
	bl CopyWindowToVram
_0803216A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08032170: .4byte 0x08032175
	thumb_func_end sub_0803213C

	thumb_func_start sub_08032174
sub_08032174: @ 0x08032174
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	mov r8, r0
	adds r5, r2, #0
	ldr r2, [sp, #0x4c]
	ldr r6, [sp, #0x50]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsls r5, r5, #0x18
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x10]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x14]
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	lsrs r0, r1, #0x18
	str r0, [sp, #0xc]
	movs r0, #0xfd
	lsls r0, r0, #0x18
	adds r1, r1, r0
	lsrs r1, r1, #0x18
	str r1, [sp, #0x18]
	lsrs r1, r5, #0x18
	mov sl, r1
	movs r0, #0xff
	lsls r0, r0, #0x18
	adds r5, r5, r0
	lsrs r5, r5, #0x18
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe5
	ldr r2, [sp, #0x18]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r0, [sp, #0xc]
	subs r0, #2
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x1c]
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe6
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r0, [sp, #0xc]
	subs r0, #1
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x20]
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe7
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, [sp, #0x10]
	str r1, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe8
	ldr r2, [sp, #0xc]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	adds r7, r0, r1
	lsls r2, r7, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x24]
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe9
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	adds r0, r7, #1
	lsls r2, r0, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x28]
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xe6
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	adds r0, r7, #2
	lsls r2, r0, #0x18
	lsrs r7, r2, #0x18
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xea
	adds r2, r7, #0
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xeb
	ldr r2, [sp, #0x18]
	mov r3, sl
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xf1
	ldr r2, [sp, #0x1c]
	mov r3, sl
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xef
	ldr r2, [sp, #0x20]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r0, [sp, #0x10]
	str r0, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xed
	ldr r2, [sp, #0xc]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r1, _08032480
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x24]
	mov r3, sl
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xf1
	ldr r2, [sp, #0x28]
	mov r3, sl
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xee
	adds r2, r7, #0
	mov r3, sl
	bl FillBgTilemapBufferRect
	mov r5, sl
	adds r5, #1
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	str r4, [sp]
	movs r1, #2
	mov sb, r1
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xeb
	ldr r2, [sp, #0x18]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xec
	ldr r2, [sp, #0x1c]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r0, [sp, #0x10]
	adds r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	mov r1, sb
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xed
	ldr r2, [sp, #0x20]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xec
	ldr r2, [sp, #0x28]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	mov r1, sb
	str r1, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	movs r1, #0xee
	adds r2, r7, #0
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _08032484
	ldr r0, [sp, #0x14]
	add sl, r0
	mov r5, sl
	subs r5, #1
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x18]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _08032488
	mov sb, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x1c]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _0803248C
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x20]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _08032490
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0xc]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _08032494
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x24]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	mov r1, sb
	ldr r2, [sp, #0x28]
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _08032498
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	adds r2, r7, #0
	adds r3, r5, #0
	bl FillBgTilemapBufferRect
	ldr r1, _0803249C
	mov r0, sl
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x18]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r5, _080324A0
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	adds r1, r5, #0
	ldr r2, [sp, #0x1c]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r1, _080324A4
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x20]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r1, _080324A8
	ldr r0, [sp, #0x10]
	str r0, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0xc]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r1, _080324AC
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	ldr r2, [sp, #0x24]
	mov r3, sl
	bl FillBgTilemapBufferRect
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	adds r1, r5, #0
	ldr r2, [sp, #0x28]
	mov r3, sl
	bl FillBgTilemapBufferRect
	ldr r1, _080324B0
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	mov r0, r8
	adds r2, r7, #0
	mov r3, sl
	bl FillBgTilemapBufferRect
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08032480: .4byte 0x000004EF
_08032484: .4byte 0x000008EB
_08032488: .4byte 0x000008F1
_0803248C: .4byte 0x000008EF
_08032490: .4byte 0x000008ED
_08032494: .4byte 0x00000CEF
_08032498: .4byte 0x000008EE
_0803249C: .4byte 0x000008E5
_080324A0: .4byte 0x000008E6
_080324A4: .4byte 0x000008E7
_080324A8: .4byte 0x000008E8
_080324AC: .4byte 0x000008E9
_080324B0: .4byte 0x000008EA
	thumb_func_end sub_08032174

	thumb_func_start Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox
Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox: @ 0x080324B4
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080324E4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r4, r1, r2
	ldrh r0, [r4, #0x16]
	subs r1, r0, #1
	strh r1, [r4, #0x16]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080324DC
	movs r0, #0
	movs r1, #1
	bl sub_0803213C
	ldr r0, _080324E8
	str r0, [r4]
_080324DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080324E4: .4byte 0x03005B60
_080324E8: .4byte 0x08030E45
	thumb_func_end Task_NewGameBirchSpeech_ReturnFromNamingScreenShowTextbox
