.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start sub_08021FC0
sub_08021FC0: @ 0x08021FC0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0
	mov sb, r0
	movs r1, #0
	str r1, [sp, #0xc]
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #3
	ldr r1, _08021FF4
	adds r6, r0, r1
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #1
	beq _08022040
	cmp r0, #1
	bgt _08021FF8
	cmp r0, #0
	beq _08022006
	b _0802221A
	.align 2, 0
_08021FF4: .4byte 0x03005B68
_08021FF8:
	cmp r0, #2
	bne _08021FFE
	b _080221E0
_08021FFE:
	cmp r0, #3
	bne _08022004
	b _080221F4
_08022004:
	b _0802221A
_08022006:
	ldr r0, _08022038
	bl AddWindow
	strh r0, [r6, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl PutWindowTilemap
	ldrb r0, [r6, #2]
	movs r1, #0
	bl FillWindowPixelBuffer
	ldrb r0, [r6, #2]
	ldr r4, _0802203C
	adds r1, r4, #0
	movs r2, #0xd0
	bl LoadUserWindowBorderGfx_
	ldrb r0, [r6, #2]
	movs r1, #0
	adds r2, r4, #0
	movs r3, #0xd
	bl DrawStdFrameWithCustomTileAndPalette
	b _0802221A
	.align 2, 0
_08022038: .4byte 0x082C5F04
_0802203C: .4byte 0x0000021D
_08022040:
	ldr r0, _080221B0
	mov sl, r0
	movs r1, #1
	rsbs r1, r1, #0
	mov r8, r1
	movs r0, #1
	mov r1, sl
	mov r2, r8
	bl GetStringWidth
	lsrs r0, r0, #1
	movs r4, #0x60
	subs r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r6, #2]
	ldr r5, _080221B4
	str r5, [sp]
	mov r1, sb
	str r1, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	movs r1, #1
	adds r2, r7, #0
	movs r3, #2
	bl AddTextPrinterParameterized3
	ldr r0, _080221B8
	mov sl, r0
	movs r0, #1
	mov r1, sl
	mov r2, r8
	bl GetStringWidth
	lsrs r0, r0, #1
	subs r4, r4, r0
	lsls r4, r4, #0x18
	lsrs r7, r4, #0x18
	ldrb r0, [r6, #2]
	str r5, [sp]
	mov r1, sb
	str r1, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	movs r1, #1
	adds r2, r7, #0
	movs r3, #0x12
	bl AddTextPrinterParameterized3
	movs r0, #0x2a
	mov sl, r0
_080220A6:
	mov r1, sb
	adds r1, #2
	ldr r0, _080221BC
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	ldr r0, _080221C0
	ldr r1, _080221C4
	bl StringExpandPlaceholders
	ldrb r0, [r6, #2]
	ldr r1, _080221C8
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	ldr r1, _080221C0
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #4
	mov r3, sl
	bl AddTextPrinterParameterized3
	movs r0, #1
	ldr r1, _080221CC
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	movs r1, #0xbc
	subs r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	ldrb r0, [r6, #2]
	ldr r1, _080221C8
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	ldr r1, _080221CC
	str r1, [sp, #8]
	movs r1, #1
	adds r2, r7, #0
	mov r3, sl
	bl AddTextPrinterParameterized3
	movs r2, #0
	mov r0, sb
	lsls r4, r0, #1
	mov r1, sl
	adds r1, #0xd
	str r1, [sp, #0x10]
	movs r0, #1
	add sb, r0
	adds r0, r4, r6
	ldrb r3, [r0, #4]
	movs r1, #1
	mov r8, r1
	ldr r5, _080221D0
_0802211A:
	movs r0, #7
	subs r1, r0, r2
	adds r0, r3, #0
	asrs r0, r1
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _08022136
	lsls r0, r2, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ldr r1, [sp, #0xc]
	adds r1, r1, r0
	str r1, [sp, #0xc]
_08022136:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls _0802211A
	adds r0, r4, r6
	ldrh r1, [r0, #4]
	lsrs r1, r1, #8
	ldr r0, _080221BC
	movs r2, #1
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r0, [sp, #0xc]
	ldr r1, _080221D4
	bl __udivsi3
	adds r1, r0, #0
	ldr r0, _080221D8
	movs r2, #2
	movs r3, #2
	bl ConvertIntToDecimalStringN
	ldr r0, _080221C0
	ldr r1, _080221DC
	bl StringExpandPlaceholders
	adds r0, r7, #0
	subs r0, #0x31
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r6, #2]
	ldr r1, _080221C8
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	ldr r1, _080221C0
	str r1, [sp, #8]
	movs r1, #0
	adds r2, r7, #0
	mov r3, sl
	bl AddTextPrinterParameterized3
	ldr r1, [sp, #0x10]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	movs r0, #0
	str r0, [sp, #0xc]
	mov r1, sb
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #3
	bls _080220A6
	ldrb r0, [r6, #2]
	movs r1, #3
	bl CopyWindowToVram
	b _0802221A
	.align 2, 0
_080221B0: .4byte 0x085CCA70
_080221B4: .4byte 0x082C5EF9
_080221B8: .4byte 0x085CCA7C
_080221BC: .4byte 0x02021C40
_080221C0: .4byte 0x02021C7C
_080221C4: .4byte 0x085CCA8C
_080221C8: .4byte 0x082C5EF0
_080221CC: .4byte 0x085CCA20
_080221D0: .4byte 0x082C5F64
_080221D4: .4byte 0x000F4240
_080221D8: .4byte 0x02021C54
_080221DC: .4byte 0x085CCA18
_080221E0:
	ldr r0, _080221F0
	ldrh r1, [r0, #0x2e]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _0802221A
	b _08022220
	.align 2, 0
_080221F0: .4byte 0x03002360
_080221F4:
	ldrb r0, [r6, #2]
	movs r1, #1
	bl ClearStdWindowAndFrameToTransparent
	ldrb r0, [r6, #2]
	bl ClearWindowTilemap
	ldrb r0, [r6, #2]
	bl RemoveWindow
	adds r0, r4, #0
	bl DestroyTask
	bl ScriptContext_Enable
	bl UnlockPlayerFieldControls
	mov r0, sb
	b _0802221E
_0802221A:
	ldrh r0, [r6]
	adds r0, #1
_0802221E:
	strh r0, [r6]
_08022220:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_08021FC0


