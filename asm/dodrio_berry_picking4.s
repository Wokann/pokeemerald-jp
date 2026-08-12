.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


























	thumb_func_start sub_0802792C
sub_0802792C: @ 0x0802792C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _08027A28
	ldr r1, [r0]
	movs r2, #0x84
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	subs r2, #4
	adds r0, r1, r2
	ldr r0, [r0]
	str r0, [sp, #0x10]
	ldr r0, _08027A2C
	adds r1, r1, r0
	ldrh r0, [r1]
	str r0, [sp, #0x14]
	ldr r4, _08027A30
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0xd0
	bl LoadUserWindowBorderGfx_
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0xd
	bl DrawTextBorderOuter
	adds r0, r7, #0
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r2, _08027A34
	movs r0, #2
	str r0, [sp]
	movs r0, #0xff
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	movs r6, #0
	ldr r2, _08027A38
	mov r8, r2
	movs r0, #0xff
	mov sl, r0
	mov sb, r6
	mov r2, sp
	adds r2, #0xc
	str r2, [sp, #0x18]
_080279A2:
	lsls r4, r6, #2
	ldr r0, [sp, #0x18]
	ldm r0!, {r1}
	str r0, [sp, #0x18]
	ldr r0, _08027A3C
	adds r0, r6, r0
	ldrb r3, [r0]
	mov r0, r8
	movs r2, #0
	bl ConvertIntToDecimalStringN
	movs r0, #1
	mov r1, r8
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	adds r5, r0, #0
	ldr r0, _08027A40
	adds r4, r4, r0
	ldr r2, [r4]
	ldr r0, _08027A44
	lsls r4, r6, #1
	adds r0, r4, r0
	ldrb r0, [r0]
	str r0, [sp]
	mov r0, sl
	str r0, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	movs r3, #0xa0
	subs r3, r3, r5
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, _08027A48
	adds r4, r4, r0
	ldrb r0, [r4]
	str r0, [sp]
	mov r2, sl
	str r2, [sp, #4]
	mov r0, sb
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	mov r2, r8
	bl AddTextPrinterParameterized
	adds r6, #1
	cmp r6, #2
	ble _080279A2
	adds r0, r7, #0
	bl PutWindowTilemap
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08027A28: .4byte 0x03005AF0
_08027A2C: .4byte 0x00000212
_08027A30: .4byte 0x0000021D
_08027A34: .4byte 0x085CCCF5
_08027A38: .4byte 0x02021C40
_08027A3C: .4byte 0x082CB3CC
_08027A40: .4byte 0x082CB3C0
_08027A44: .4byte 0x082CB3D0
_08027A48: .4byte 0x082CB3D6
	thumb_func_end sub_0802792C

