.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified








	thumb_func_start sub_0802A49C
sub_0802A49C: @ 0x0802A49C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	movs r3, #0xc0
	lsls r3, r3, #0x13
	movs r4, #0xc0
	lsls r4, r4, #9
	add r0, sp, #4
	mov r8, r0
	mov r2, sp
	movs r6, #0
	ldr r1, _0802A5CC
	movs r5, #0x80
	lsls r5, r5, #5
	ldr r7, _0802A5D0
	movs r0, #0x81
	lsls r0, r0, #0x18
	mov ip, r0
_0802A4C2:
	strh r6, [r2]
	mov r0, sp
	str r0, [r1]
	str r3, [r1, #4]
	str r7, [r1, #8]
	ldr r0, [r1, #8]
	adds r3, r3, r5
	subs r4, r4, r5
	cmp r4, r5
	bhi _0802A4C2
	strh r6, [r2]
	mov r2, sp
	str r2, [r1]
	str r3, [r1, #4]
	lsrs r0, r4, #1
	mov r2, ip
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	movs r0, #0xe0
	lsls r0, r0, #0x13
	movs r3, #0x80
	lsls r3, r3, #3
	movs r4, #0
	str r4, [sp, #4]
	ldr r2, _0802A5CC
	mov r1, r8
	str r1, [r2]
	str r0, [r2, #4]
	lsrs r0, r3, #2
	movs r1, #0x85
	lsls r1, r1, #0x18
	orrs r0, r1
	str r0, [r2, #8]
	ldr r0, [r2, #8]
	movs r1, #0xa0
	lsls r1, r1, #0x13
	mov r0, sp
	strh r4, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	lsrs r3, r3, #1
	movs r0, #0x81
	lsls r0, r0, #0x18
	orrs r3, r0
	str r3, [r2, #8]
	ldr r0, [r2, #8]
	movs r0, #0
	movs r1, #0
	bl SetGpuReg
	movs r0, #0
	bl ResetBgsAndClearDma3BusyFlags
	ldr r1, _0802A5D4
	movs r0, #0
	movs r2, #4
	bl InitBgsFromTemplates
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
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #2
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #3
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	bl InitStandardTextBoxWindows
	bl sub_08196DF4
	movs r1, #0x82
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	ldr r4, _0802A5D8
	ldr r1, [r4]
	movs r0, #3
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r2, #0x80
	lsls r2, r2, #5
	adds r1, r1, r2
	movs r0, #1
	bl SetBgTilemapBuffer
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #6
	adds r1, r1, r0
	movs r0, #2
	bl SetBgTilemapBuffer
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A5CC: .4byte 0x040000D4
_0802A5D0: .4byte 0x81000800
_0802A5D4: .4byte 0x082CB430
_0802A5D8: .4byte 0x020229AC
	thumb_func_end sub_0802A49C

	thumb_func_start sub_0802A5DC
sub_0802A5DC: @ 0x0802A5DC
	push {lr}
	sub sp, #4
	ldr r0, _0802A5F8
	ldr r0, [r0]
	ldr r2, _0802A5FC
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #5
	bhi _0802A676
	lsls r0, r0, #2
	ldr r1, _0802A600
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0802A5F8: .4byte 0x020229AC
_0802A5FC: .4byte 0x00003018
_0802A600: .4byte 0x0802A604
_0802A604: @ jump table
	.4byte _0802A61C @ case 0
	.4byte _0802A62C @ case 1
	.4byte _0802A632 @ case 2
	.4byte _0802A640 @ case 3
	.4byte _0802A658 @ case 4
	.4byte _0802A666 @ case 5
_0802A61C:
	ldr r0, _0802A628
	movs r1, #0
	movs r2, #0x40
	bl LoadPalette
	b _0802A67E
	.align 2, 0
_0802A628: .4byte 0x082CB67C
_0802A62C:
	bl ResetTempTileDataBuffers
	b _0802A67E
_0802A632:
	ldr r1, _0802A63C
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	b _0802A648
	.align 2, 0
_0802A63C: .4byte 0x082CB910
_0802A640:
	ldr r1, _0802A654
	movs r0, #0
	str r0, [sp]
	movs r0, #1
_0802A648:
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	b _0802A67E
	.align 2, 0
_0802A654: .4byte 0x082CC1A0
_0802A658:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0802A67E
	b _0802A68C
_0802A666:
	movs r0, #3
	bl GetTextWindowPalette
	movs r1, #0xd0
	movs r2, #0x20
	bl LoadPalette
	b _0802A67E
_0802A676:
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0802A68E
_0802A67E:
	ldr r0, _0802A694
	ldr r1, [r0]
	ldr r0, _0802A698
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0802A68C:
	movs r0, #0
_0802A68E:
	add sp, #4
	pop {r1}
	bx r1
	.align 2, 0
_0802A694: .4byte 0x020229AC
_0802A698: .4byte 0x00003018
	thumb_func_end sub_0802A5DC
