.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	.section .text.sub_08151638,"ax",%progbits
	thumb_func_start sub_08151638
sub_08151638: @ 0x08151638
	push {lr}
	adds r2, r0, #0
	ldr r1, _08151650
	ldr r0, _0815164C
	asrs r3, r2, #0x1f
	bl __divdi3
	pop {r1}
	bx r1
	.align 2, 0
_0815164C: .4byte 0x00010000
_08151650: .4byte 0x00000000
	thumb_func_end sub_08151638

	.section .text.roulette_util_rest,"ax",%progbits
	thumb_func_start sub_08151A78
sub_08151A78: @ 0x08151A78
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	movs r5, #0
	movs r3, #1
_08151A86:
	ldrh r0, [r6, #2]
	asrs r0, r5
	ands r0, r3
	cmp r0, #0
	beq _08151AEE
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r4, r6, r0
	ldrb r0, [r4, #4]
	lsrs r0, r0, #7
	cmp r0, #0
	beq _08151AEE
	adds r0, r7, #0
	asrs r0, r5
	ands r0, r3
	cmp r0, #0
	beq _08151AEE
	ldrh r1, [r4, #0xa]
	lsls r1, r1, #1
	ldr r0, _08151AE4
	adds r0, r1, r0
	ldr r2, _08151AE8
	adds r1, r1, r2
	ldrb r2, [r4, #0xc]
	lsls r2, r2, #1
	str r3, [sp]
	bl memcpy
	ldrb r0, [r4, #4]
	movs r2, #0x80
	rsbs r2, r2, #0
	adds r1, r2, #0
	ands r0, r1
	strb r0, [r4, #4]
	movs r0, #0
	strb r0, [r4, #6]
	strb r0, [r4, #5]
	ldrb r0, [r4, #0xf]
	lsls r0, r0, #0x18
	ldr r3, [sp]
	cmp r0, #0
	bge _08151AEC
	movs r0, #0xff
	strb r0, [r4, #7]
	b _08151AEE
	.align 2, 0
_08151AE4: .4byte 0x020377B4
_08151AE8: .4byte 0x020373B4
_08151AEC:
	strb r3, [r4, #7]
_08151AEE:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xf
	bls _08151A86
	ldr r0, _08151B04
	cmp r7, r0
	bne _08151B08
	movs r0, #0
	strb r0, [r6]
	b _08151B0C
	.align 2, 0
_08151B04: .4byte 0x0000FFFF
_08151B08:
	ldrh r0, [r6, #2]
	bics r0, r7
_08151B0C:
	strh r0, [r6, #2]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08151A78

	thumb_func_start InitPulseBlend
InitPulseBlend: @ 0x08151B18
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
	strh r4, [r5]
	adds r0, r5, #4
	movs r1, #0
	movs r2, #0xc0
	bl memset
_08151B2A:
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r5, r0
	strb r4, [r0, #4]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bls _08151B2A
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end InitPulseBlend

	thumb_func_start InitPulseBlendPaletteSettings
InitPulseBlendPaletteSettings: @ 0x08151B44
	push {r4, r5, lr}
	adds r2, r0, #0
	adds r5, r1, #0
	movs r3, #0
	movs r4, #0
	ldrb r0, [r2, #5]
	lsrs r0, r0, #7
	cmp r0, #0
	bne _08151B5A
	adds r4, r2, #4
	b _08151B78
_08151B5A:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xf
	bhi _08151B78
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r1, r0, #2
	adds r0, r2, r1
	ldrb r0, [r0, #5]
	lsrs r0, r0, #7
	cmp r0, #0
	bne _08151B5A
	adds r0, r1, #4
	adds r4, r2, r0
_08151B78:
	cmp r4, #0
	beq _08151BA6
	ldrb r1, [r4, #1]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r4, #1]
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	adds r1, r4, #4
	adds r0, r5, #0
	ldm r0!, {r2, r4}
	stm r1!, {r2, r4}
	adds r0, r3, #0
	b _08151BA8
_08151BA6:
	movs r0, #0xff
_08151BA8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end InitPulseBlendPaletteSettings

	thumb_func_start ClearPulseBlendPalettesSettings
ClearPulseBlendPalettesSettings: @ 0x08151BB0
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r1, [r4, #1]
	movs r2, #0x40
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08151BF2
	ldrb r1, [r4, #0xb]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08151BF2
	ldrh r2, [r4, #6]
	ldrb r0, [r4, #8]
	adds r0, r2, r0
	cmp r2, r0
	bge _08151BF2
	ldr r5, _08151C24
	ldr r3, _08151C28
_08151BD8:
	lsls r0, r2, #1
	adds r1, r0, r5
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r4, #6]
	ldrb r1, [r4, #8]
	adds r0, r0, r1
	cmp r2, r0
	blt _08151BD8
_08151BF2:
	adds r0, r4, #4
	movs r1, #0
	movs r2, #8
	bl memset
	ldrb r1, [r4, #1]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x11
	rsbs r1, r1, #0
	ands r0, r1
	subs r1, #0x10
	ands r0, r1
	movs r1, #0x40
	orrs r0, r1
	movs r1, #0x7f
	ands r0, r1
	strb r0, [r4, #1]
	movs r0, #0
	strb r0, [r4, #3]
	strb r0, [r4, #2]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08151C24: .4byte 0x020377B4
_08151C28: .4byte 0x020373B4
	thumb_func_end ClearPulseBlendPalettesSettings

	thumb_func_start UnloadUsedPulseBlendPalettes
UnloadUsedPulseBlendPalettes: @ 0x08151C2C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x18
	movs r5, #0
	cmp r2, #0
	bne _08151C50
	movs r1, #0xf
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #4
	adds r0, r6, r0
	bl ClearPulseBlendPalettesSettings
	b _08151C7C
_08151C50:
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	beq _08151C70
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r1, r0, #2
	adds r0, r6, r1
	ldrb r0, [r0, #5]
	lsrs r0, r0, #7
	cmp r0, #0
	beq _08151C70
	adds r0, r1, #4
	adds r0, r6, r0
	bl ClearPulseBlendPalettesSettings
_08151C70:
	lsrs r4, r4, #1
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0xf
	bls _08151C50
_08151C7C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end UnloadUsedPulseBlendPalettes

	thumb_func_start MarkUsedPulseBlendPalettes
MarkUsedPulseBlendPalettes: @ 0x08151C84
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x18
	movs r3, #0
	cmp r2, #0
	bne _08151CB8
	movs r0, #0xf
	adds r3, r0, #0
	ands r3, r4
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #2
	adds r1, r5, r1
	ldrb r2, [r1, #5]
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #5]
	movs r0, #1
	lsls r0, r3
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	b _08151CFC
_08151CB8:
	movs r6, #1
	movs r7, #0x41
	rsbs r7, r7, #0
_08151CBE:
	adds r0, r4, #0
	ands r0, r6
	cmp r0, #0
	beq _08151CDC
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r2, r5, r0
	ldrb r1, [r2, #5]
	lsrs r0, r1, #7
	cmp r0, #0
	beq _08151CDC
	lsls r0, r1, #0x19
	cmp r0, #0
	blt _08151CE2
_08151CDC:
	lsls r0, r4, #0x11
	lsrs r4, r0, #0x10
	b _08151CF2
_08151CE2:
	adds r0, r7, #0
	ands r0, r1
	strb r0, [r2, #5]
	adds r0, r6, #0
	lsls r0, r3
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_08151CF2:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xf
	bls _08151CBE
_08151CFC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end MarkUsedPulseBlendPalettes

	thumb_func_start UnmarkUsedPulseBlendPalettes
UnmarkUsedPulseBlendPalettes: @ 0x08151D04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x18
	movs r0, #0
	mov ip, r0
	cmp r2, #0
	bne _08151D8C
	movs r1, #0xf
	ands r1, r7
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #4
	mov r1, r8
	adds r3, r1, r0
	ldrb r1, [r3, #1]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0x80
	bne _08151E16
	ldrb r1, [r3, #0xb]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08151D6A
	ldrh r2, [r3, #6]
	ldrb r0, [r3, #8]
	adds r0, r2, r0
	cmp r2, r0
	bge _08151D6A
	ldr r5, _08151D84
	ldr r4, _08151D88
_08151D50:
	lsls r0, r2, #1
	adds r1, r0, r5
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r3, #6]
	ldrb r1, [r3, #8]
	adds r0, r0, r1
	cmp r2, r0
	blt _08151D50
_08151D6A:
	ldrb r0, [r3, #1]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r3, #1]
	movs r1, #1
	mov r2, ip
	lsls r1, r2
	mov r2, r8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	b _08151E16
	.align 2, 0
_08151D84: .4byte 0x020377B4
_08151D88: .4byte 0x020373B4
_08151D8C:
	movs r0, #1
	mov sb, r0
	movs r1, #0x40
	mov sl, r1
_08151D94:
	mov r2, ip
	lsls r0, r2, #1
	add r0, ip
	lsls r0, r0, #2
	adds r0, #4
	mov r1, r8
	adds r3, r1, r0
	adds r0, r7, #0
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _08151DB6
	ldrb r1, [r3, #1]
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0x80
	beq _08151DC0
_08151DB6:
	lsls r0, r7, #0x11
	lsrs r7, r0, #0x10
	mov r5, ip
	adds r5, #1
	b _08151E0C
_08151DC0:
	ldrb r1, [r3, #0xb]
	mov r0, sl
	ands r0, r1
	mov r5, ip
	adds r5, #1
	cmp r0, #0
	beq _08151DF6
	ldrh r2, [r3, #6]
	ldrb r0, [r3, #8]
	adds r0, r2, r0
	cmp r2, r0
	bge _08151DF6
	ldr r6, _08151E24
	ldr r4, _08151E28
_08151DDC:
	lsls r0, r2, #1
	adds r1, r0, r6
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r3, #6]
	ldrb r1, [r3, #8]
	adds r0, r0, r1
	cmp r2, r0
	blt _08151DDC
_08151DF6:
	ldrb r1, [r3, #1]
	mov r0, sl
	orrs r0, r1
	strb r0, [r3, #1]
	mov r1, sb
	mov r0, ip
	lsls r1, r0
	mov r2, r8
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
_08151E0C:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	cmp r0, #0xf
	bls _08151D94
_08151E16:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08151E24: .4byte 0x020377B4
_08151E28: .4byte 0x020373B4
	thumb_func_end UnmarkUsedPulseBlendPalettes

	thumb_func_start UpdatePulseBlend
UpdatePulseBlend: @ 0x08151E2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	str r0, [sp]
	movs r0, #0
	mov sl, r0
	ldr r1, [sp]
	ldrh r0, [r1]
	cmp r0, #0
	bne _08151E48
	b _08151FD2
_08151E48:
	movs r2, #0xf
	mov sb, r2
	movs r3, #0x10
	rsbs r3, r3, #0
	mov r8, r3
	movs r7, #1
_08151E54:
	mov r5, sl
	lsls r0, r5, #1
	add r0, sl
	lsls r0, r0, #2
	adds r0, #4
	ldr r1, [sp]
	adds r4, r1, r0
	ldrb r2, [r4, #1]
	movs r3, #0xc0
	ands r3, r2
	cmp r3, #0x80
	beq _08151E6E
	b _08151FC2
_08151E6E:
	ldr r0, _08151EBC
	ldrb r1, [r0, #7]
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08151E84
	ldrb r0, [r4, #0xb]
	ands r3, r0
	cmp r3, #0
	beq _08151E84
	b _08151FC2
_08151E84:
	ldrb r0, [r4, #2]
	subs r0, #1
	strb r0, [r4, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _08151E94
	b _08151FC2
_08151E94:
	ldrb r0, [r4, #9]
	strb r0, [r4, #2]
	ldrh r0, [r4, #6]
	ldrb r1, [r4, #8]
	lsls r2, r2, #0x1c
	lsrs r2, r2, #0x1c
	ldrh r3, [r4, #4]
	bl BlendPalette
	ldrb r5, [r4, #0xb]
	lsls r0, r5, #0x1a
	asrs r0, r0, #0x1e
	cmp r0, #1
	beq _08151EF2
	cmp r0, #1
	bgt _08151EC0
	cmp r0, #0
	beq _08151EC6
	b _08151FAC
	.align 2, 0
_08151EBC: .4byte 0x02037C74
_08151EC0:
	cmp r0, #2
	beq _08151F6E
	b _08151FAC
_08151EC6:
	ldrb r2, [r4, #1]
	lsls r1, r2, #0x1c
	lsrs r0, r1, #0x1c
	adds r0, #1
	mov r3, sb
	ands r0, r3
	mov r6, r8
	adds r3, r6, #0
	ands r3, r2
	orrs r3, r0
	strb r3, [r4, #1]
	lsrs r1, r1, #0x1c
	lsls r0, r5, #0x1c
	asrs r0, r0, #0x1c
	cmp r1, r0
	bne _08151FAC
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	ands r3, r6
	strb r3, [r4, #1]
	b _08151FAC
_08151EF2:
	ldrb r3, [r4, #1]
	movs r0, #0x10
	ands r0, r3
	cmp r0, #0
	beq _08151F30
	lsls r0, r3, #0x1c
	lsrs r0, r0, #0x1c
	subs r0, #1
	mov r5, sb
	ands r0, r5
	mov r2, r8
	ands r2, r3
	orrs r2, r0
	strb r2, [r4, #1]
	cmp r0, #0
	bne _08151FAC
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	lsls r0, r2, #0x1b
	lsrs r0, r0, #0x1f
	eors r0, r7
	ands r0, r7
	lsls r0, r0, #4
	movs r3, #0x11
	rsbs r3, r3, #0
	adds r1, r3, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, #1]
	b _08151FAC
_08151F30:
	lsls r0, r5, #0x1c
	asrs r0, r0, #0x1c
	subs r0, #1
	mov r5, sb
	ands r0, r5
	lsls r2, r3, #0x1c
	lsrs r1, r2, #0x1c
	adds r1, #1
	ands r1, r5
	mov r5, r8
	ands r3, r5
	orrs r3, r1
	strb r3, [r4, #1]
	lsrs r2, r2, #0x1c
	cmp r2, r0
	bne _08151FAC
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
	lsls r0, r3, #0x1b
	lsrs r0, r0, #0x1f
	eors r0, r7
	ands r0, r7
	lsls r0, r0, #4
	movs r2, #0x11
	rsbs r2, r2, #0
	adds r1, r2, #0
	ands r3, r1
	orrs r3, r0
	strb r3, [r4, #1]
	b _08151FAC
_08151F6E:
	ldrb r2, [r4, #1]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08151F7E
	mov r0, r8
	ands r0, r2
	b _08151F8C
_08151F7E:
	lsls r1, r5, #0x1c
	asrs r1, r1, #0x1c
	mov r3, sb
	ands r1, r3
	mov r0, r8
	ands r0, r2
	orrs r0, r1
_08151F8C:
	strb r0, [r4, #1]
	ldrb r2, [r4, #1]
	lsls r0, r2, #0x1b
	lsrs r0, r0, #0x1f
	eors r0, r7
	ands r0, r7
	lsls r0, r0, #4
	movs r5, #0x11
	rsbs r5, r5, #0
	adds r1, r5, #0
	ands r2, r1
	orrs r2, r0
	strb r2, [r4, #1]
	ldrb r0, [r4, #3]
	adds r0, #1
	strb r0, [r4, #3]
_08151FAC:
	ldrb r1, [r4, #0xa]
	cmp r1, #0xff
	beq _08151FC2
	ldrb r0, [r4, #3]
	cmp r0, r1
	bne _08151FC2
	ldrb r1, [r4]
	ldr r0, [sp]
	movs r2, #0
	bl UnmarkUsedPulseBlendPalettes
_08151FC2:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	cmp r0, #0xf
	bhi _08151FD2
	b _08151E54
_08151FD2:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end UpdatePulseBlend

	thumb_func_start sub_08151FE4
sub_08151FE4: @ 0x08151FE4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [sp, #0x14]
	ldr r4, [sp, #0x18]
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r1, #0
	lsrs r3, r3, #0x13
	adds r3, r3, r2
	lsls r3, r3, #1
	adds r6, r6, r3
	cmp r1, r4
	bhs _0815202E
_0815200C:
	lsls r0, r1, #6
	adds r2, r6, r0
	movs r0, #0
	adds r3, r1, #1
	cmp r0, r5
	bhs _08152026
_08152018:
	strh r7, [r2]
	adds r2, #2
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	blo _08152018
_08152026:
	lsls r0, r3, #0x18
	lsrs r1, r0, #0x18
	cmp r1, r4
	blo _0815200C
_0815202E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_08151FE4

	thumb_func_start sub_08152034
sub_08152034: @ 0x08152034
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, [sp, #0x14]
	ldr r4, [sp, #0x18]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r6, r4, #0x18
	movs r4, #0
	lsrs r3, r3, #0x13
	adds r3, r3, r2
	lsls r3, r3, #1
	adds r7, r7, r3
	cmp r4, r6
	bhs _0815207E
_08152058:
	lsls r0, r4, #6
	adds r2, r7, r0
	movs r3, #0
	adds r4, #1
	cmp r3, r5
	bhs _08152076
_08152064:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r5
	blo _08152064
_08152076:
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r6
	blo _08152058
_0815207E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_08152034
