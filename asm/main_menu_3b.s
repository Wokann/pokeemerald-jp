
.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


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
