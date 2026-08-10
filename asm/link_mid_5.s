.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0800AB5C
sub_0800AB5C: @ 0x0800AB5C
	push {r4, r5, lr}
	sub sp, #0xc
	ldr r1, _0800ABF8
	movs r0, #0
	movs r2, #0x20
	movs r3, #0
	bl LoadBgTiles
	ldr r1, _0800ABFC
	movs r5, #0
	str r5, [sp]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl DecompressAndLoadBgGfxUsingHeap
	ldr r1, _0800AC00
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	ldr r0, _0800AC04
	movs r1, #0
	movs r2, #0x20
	bl LoadPalette
	movs r0, #0
	movs r1, #0
	bl FillWindowPixelBuffer
	movs r0, #2
	movs r1, #0
	bl FillWindowPixelBuffer
	ldr r4, _0800AC08
	str r4, [sp]
	str r5, [sp, #4]
	ldr r0, _0800AC0C
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #3
	movs r2, #0x18
	movs r3, #5
	bl AddTextPrinterParameterized3
	str r4, [sp]
	str r5, [sp, #4]
	ldr r0, _0800AC10
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #3
	movs r2, #3
	movs r3, #2
	bl AddTextPrinterParameterized3
	movs r0, #0
	bl PutWindowTilemap
	movs r0, #2
	bl PutWindowTilemap
	movs r0, #0
	movs r1, #0
	bl CopyWindowToVram
	movs r0, #2
	movs r1, #3
	bl CopyWindowToVram
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800ABF8: .4byte 0x082BFEB8
_0800ABFC: .4byte 0x082BF4D8
_0800AC00: .4byte 0x082BF980
_0800AC04: .4byte 0x082BF4B8
_0800AC08: .4byte 0x082BFF74
_0800AC0C: .4byte 0x082BFE50
_0800AC10: .4byte 0x082BFE62
	thumb_func_end sub_0800AB5C


	thumb_func_start sub_0800AC14
sub_0800AC14: @ 0x0800AC14
	push {lr}
	sub sp, #0xc
	ldr r1, _0800AC70
	movs r0, #0
	movs r2, #0x20
	movs r3, #0
	bl LoadBgTiles
	movs r0, #1
	movs r1, #0
	bl FillWindowPixelBuffer
	movs r0, #2
	movs r1, #0
	bl FillWindowPixelBuffer
	ldr r0, _0800AC74
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _0800AC78
	str r0, [sp, #8]
	movs r0, #1
	movs r1, #3
	movs r2, #3
	movs r3, #0
	bl AddTextPrinterParameterized3
	movs r0, #1
	bl PutWindowTilemap
	movs r0, #2
	bl PutWindowTilemap
	movs r0, #1
	movs r1, #0
	bl CopyWindowToVram
	movs r0, #2
	movs r1, #3
	bl CopyWindowToVram
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_0800AC70: .4byte 0x082BFEB8
_0800AC74: .4byte 0x082BFF74
_0800AC78: .4byte 0x082BFE00
	thumb_func_end sub_0800AC14


	thumb_func_start CB2_PrintErrorMessage
CB2_PrintErrorMessage: @ 0x0800AC7C
	push {r4, lr}
	sub sp, #0xc
	ldr r0, _0800AC9C
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x1e
	beq _0800ACE8
	cmp r0, #0x1e
	bgt _0800ACA0
	cmp r0, #0
	beq _0800ACB4
	cmp r0, #2
	beq _0800ACCE
	b _0800AD3C
	.align 2, 0
_0800AC9C: .4byte 0x03002360
_0800ACA0:
	cmp r0, #0x5a
	beq _0800ACE8
	cmp r0, #0x5a
	bgt _0800ACAE
	cmp r0, #0x3c
	beq _0800ACE8
	b _0800AD3C
_0800ACAE:
	cmp r0, #0x82
	beq _0800ACF0
	b _0800AD3C
_0800ACB4:
	ldr r0, _0800ACC4
	ldrb r0, [r0, #6]
	cmp r0, #0
	beq _0800ACC8
	bl sub_0800AB5C
	b _0800AD3C
	.align 2, 0
_0800ACC4: .4byte 0x020227B8
_0800ACC8:
	bl sub_0800AC14
	b _0800AD3C
_0800ACCE:
	movs r0, #0
	bl ShowBg
	ldr r0, _0800ACE4
	ldrb r0, [r0, #6]
	cmp r0, #0
	beq _0800AD3C
	movs r0, #1
	bl ShowBg
	b _0800AD3C
	.align 2, 0
_0800ACE4: .4byte 0x020227B8
_0800ACE8:
	movs r0, #0x16
	bl PlaySE
	b _0800AD3C
_0800ACF0:
	ldr r0, _0800AD14
	ldrb r0, [r0]
	cmp r0, #2
	bne _0800AD20
	ldr r0, _0800AD18
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _0800AD1C
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #3
	movs r2, #0x18
	movs r3, #0x12
	bl AddTextPrinterParameterized3
	b _0800AD3C
	.align 2, 0
_0800AD14: .4byte 0x0300319C
_0800AD18: .4byte 0x082BFF74
_0800AD1C: .4byte 0x082BFE9F
_0800AD20:
	cmp r0, #1
	bne _0800AD3C
	ldr r0, _0800AD70
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _0800AD74
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #3
	movs r2, #0x18
	movs r3, #0x12
	bl AddTextPrinterParameterized3
_0800AD3C:
	ldr r0, _0800AD78
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrb r1, [r1]
	cmp r1, #0xa0
	bne _0800ADAC
	ldr r4, _0800AD7C
	ldrb r2, [r4]
	cmp r2, #1
	bne _0800AD84
	ldrh r0, [r0, #0x2e]
	ands r2, r0
	cmp r2, #0
	beq _0800AD9E
	movs r0, #0x15
	bl PlaySE
	movs r0, #0
	strb r0, [r4]
	ldr r1, _0800AD80
	movs r0, #0
	strb r0, [r1, #6]
	bl sub_0816FEF0
	b _0800AD9E
	.align 2, 0
_0800AD70: .4byte 0x082BFF74
_0800AD74: .4byte 0x082BFE8D
_0800AD78: .4byte 0x03002360
_0800AD7C: .4byte 0x0300319C
_0800AD80: .4byte 0x020227B8
_0800AD84:
	cmp r2, #2
	bne _0800AD9E
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0800AD9E
	bl rfu_REQ_stopMode
	bl rfu_waitREQComplete
	bl DoSoftReset
_0800AD9E:
	ldr r0, _0800ADC0
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrb r1, [r1]
	cmp r1, #0xa0
	beq _0800ADB8
_0800ADAC:
	movs r2, #0x87
	lsls r2, r2, #3
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0800ADB8:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0800ADC0: .4byte 0x03002360
	thumb_func_end CB2_PrintErrorMessage


