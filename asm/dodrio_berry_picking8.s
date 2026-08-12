.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



	thumb_func_start sub_080295A4
sub_080295A4: @ 0x080295A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	bl sub_08027410
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r6, _080295D4
	ldr r1, [r6]
	ldr r2, _080295D8
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0xb
	bls _080295CA
	b _08029CC0
_080295CA:
	lsls r0, r0, #2
	ldr r1, _080295DC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080295D4: .4byte 0x020229AC
_080295D8: .4byte 0x00003014
_080295DC: .4byte 0x080295E0
_080295E0: @ jump table
	.4byte _08029610 @ case 0
	.4byte _0802962C @ case 1
	.4byte _08029684 @ case 2
	.4byte _08029888 @ case 3
	.4byte _080298D4 @ case 4
	.4byte _08029918 @ case 5
	.4byte _0802997C @ case 6
	.4byte _080299B8 @ case 7
	.4byte _080299FC @ case 8
	.4byte _08029ABC @ case 9
	.4byte _08029C20 @ case 10
	.4byte _08029C74 @ case 11
_08029610:
	bl sub_0802760C
	ldr r0, _08029624
	ldr r1, [r0]
	ldr r0, _08029628
	adds r2, r1, r0
	movs r0, #0
	strh r0, [r2]
	b _08029CA2
	.align 2, 0
_08029624: .4byte 0x020229AC
_08029628: .4byte 0x0000301C
_0802962C:
	ldr r6, _08029674
	adds r0, r6, #0
	bl AddWindow
	ldr r4, _08029678
	ldr r1, [r4]
	ldr r2, _0802967C
	mov r8, r2
	add r1, r8
	strb r0, [r1]
	movs r0, #8
	adds r0, r0, r6
	mov sb, r0
	bl AddWindow
	ldr r1, [r4]
	ldr r5, _08029680
	adds r1, r1, r5
	strb r0, [r1]
	ldr r0, [r4]
	add r0, r8
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r6, #0
	bl sub_08028EA0
	mov r0, sb
	bl sub_08028EA0
	b _08029CA0
	.align 2, 0
_08029674: .4byte 0x082CB448
_08029678: .4byte 0x020229AC
_0802967C: .4byte 0x00003008
_08029680: .4byte 0x00003009
_08029684:
	ldr r4, _080297D0
	ldr r0, [r4]
	ldr r5, _080297D4
	adds r0, r0, r5
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, _080297D8
	mov sb, r1
	add r0, sb
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r2, _080297DC
	mov r8, r2
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #0
	mov r1, r8
	bl GetStringWidth
	adds r1, r0, #0
	movs r0, #0xe0
	subs r0, r0, r1
	lsrs r3, r0, #1
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r1, #2
	str r1, [sp]
	movs r6, #0xff
	str r6, [sp, #4]
	movs r5, #0
	str r5, [sp, #8]
	movs r1, #0
	mov r2, r8
	bl AddTextPrinterParameterized
	ldr r0, [r4]
	add r0, sb
	ldrb r0, [r0]
	ldr r2, _080297E0
	movs r1, #0x10
	str r1, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	movs r3, #0x44
	bl AddTextPrinterParameterized
	movs r0, #0
	mov sb, r0
	ldr r1, [sp, #0xc]
	cmp sb, r1
	blo _080296FE
	b _08029844
_080296FE:
	movs r4, #0
	bl GetMultiplayerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp sb, r0
	bne _0802970E
	movs r4, #2
_0802970E:
	mov r0, sb
	bl sub_08027420
	adds r6, r0, #0
	ldr r0, _080297D0
	ldr r0, [r0]
	ldr r2, _080297D8
	adds r0, r0, r2
	ldrb r0, [r0]
	mov r1, sb
	lsls r5, r1, #1
	ldr r2, _080297E4
	adds r1, r5, r2
	ldrb r3, [r1]
	lsls r1, r4, #1
	adds r1, r1, r4
	ldr r2, _080297E8
	adds r1, r1, r2
	str r1, [sp]
	movs r4, #1
	rsbs r4, r4, #0
	str r4, [sp, #4]
	str r6, [sp, #8]
	movs r1, #0
	movs r2, #2
	bl AddTextPrinterParameterized3
	movs r7, #0
	mov r8, r5
	mov r0, sb
	adds r0, #1
	str r0, [sp, #0x10]
	ldr r1, _080297EC
	mov sl, r1
_08029752:
	mov r0, sb
	adds r1, r7, #0
	bl sub_08027460
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080297F0
	bl Min
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r7, #0
	bl sub_0802754C
	ldr r1, _080297F0
	bl Min
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, sl
	adds r1, r4, #0
	movs r2, #0
	movs r3, #4
	bl ConvertIntToDecimalStringN
	movs r0, #0
	mov r1, sl
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	adds r5, r0, #0
	cmp r6, r4
	bne _080297FC
	cmp r6, #0
	beq _080297FC
	ldr r0, _080297D0
	ldr r0, [r0]
	ldr r2, _080297D8
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r1, r7, #1
	ldr r2, _080297F4
	adds r1, r1, r2
	ldrb r2, [r1]
	subs r2, r2, r5
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _080297E4
	add r1, r8
	ldrb r3, [r1]
	ldr r1, _080297F8
	str r1, [sp]
	movs r1, #1
	rsbs r1, r1, #0
	str r1, [sp, #4]
	mov r1, sl
	str r1, [sp, #8]
	movs r1, #0
	bl AddTextPrinterParameterized3
	b _0802982A
	.align 2, 0
_080297D0: .4byte 0x020229AC
_080297D4: .4byte 0x00003008
_080297D8: .4byte 0x00003009
_080297DC: .4byte 0x085CCD34
_080297E0: .4byte 0x085CCD45
_080297E4: .4byte 0x082CEC84
_080297E8: .4byte 0x082CEC0C
_080297EC: .4byte 0x02021C7C
_080297F0: .4byte 0x0000270F
_080297F4: .4byte 0x082CEC7C
_080297F8: .4byte 0x082CEC0F
_080297FC:
	ldr r0, _0802986C
	ldr r0, [r0]
	ldr r2, _08029870
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r1, r7, #1
	ldr r2, _08029874
	adds r1, r1, r2
	ldrb r3, [r1]
	subs r3, r3, r5
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r1, _08029878
	add r1, r8
	ldrb r1, [r1]
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	ldr r2, _0802987C
	bl AddTextPrinterParameterized
_0802982A:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #3
	bls _08029752
	ldr r1, [sp, #0x10]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r2, [sp, #0xc]
	cmp sb, r2
	bhs _08029844
	b _080296FE
_08029844:
	ldr r4, _0802986C
	ldr r0, [r4]
	ldr r1, _08029880
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, _08029870
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, _08029884
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_0802986C: .4byte 0x020229AC
_08029870: .4byte 0x00003009
_08029874: .4byte 0x082CEC7C
_08029878: .4byte 0x082CEC84
_0802987C: .4byte 0x02021C7C
_08029880: .4byte 0x00003008
_08029884: .4byte 0x00003014
_08029888:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080298AC
	ldr r4, _080298C4
	ldr r0, [r4]
	ldr r1, _080298C8
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, _080298CC
	adds r0, r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_080298AC:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	movs r0, #0
	bl sub_0802895C
	ldr r0, _080298C4
	ldr r1, [r0]
	ldr r0, _080298D0
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_080298C4: .4byte 0x020229AC
_080298C8: .4byte 0x00003008
_080298CC: .4byte 0x00003009
_080298D0: .4byte 0x00003014
_080298D4:
	ldr r4, _0802990C
	ldr r0, [r4]
	ldr r1, _08029910
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _080298EC
	b _08029D10
_080298EC:
	ldr r0, _08029914
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080298FA
	b _08029D10
_080298FA:
	movs r0, #0
	strh r0, [r2]
	movs r0, #5
	bl PlaySE
	movs r0, #1
	bl sub_0802895C
	b _08029CA0
	.align 2, 0
_0802990C: .4byte 0x020229AC
_08029910: .4byte 0x0000301C
_08029914: .4byte 0x03002360
_08029918:
	ldr r4, _0802996C
	ldr r0, [r4]
	ldr r5, _08029970
	adds r0, r0, r5
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, _08029974
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r6, _08029978
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #0
	adds r1, r6, #0
	bl GetStringWidth
	adds r1, r0, #0
	movs r0, #0xe0
	subs r0, r0, r1
	lsrs r3, r0, #1
	ldr r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	adds r2, r6, #0
	bl AddTextPrinterParameterized
	b _08029CA0
	.align 2, 0
_0802996C: .4byte 0x020229AC
_08029970: .4byte 0x00003008
_08029974: .4byte 0x00003009
_08029978: .4byte 0x085CCD5A
_0802997C:
	ldr r0, [sp, #0xc]
	bl sub_080293D4
	ldr r4, _080299A8
	ldr r0, [r4]
	ldr r1, _080299AC
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, _080299B0
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, _080299B4
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_080299A8: .4byte 0x020229AC
_080299AC: .4byte 0x00003008
_080299B0: .4byte 0x00003009
_080299B4: .4byte 0x00003014
_080299B8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080299DC
	ldr r4, _080299EC
	ldr r0, [r4]
	ldr r1, _080299F0
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, _080299F4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_080299DC:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _080299EC
	ldr r1, [r0]
	ldr r0, _080299F8
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_080299EC: .4byte 0x020229AC
_080299F0: .4byte 0x00003008
_080299F4: .4byte 0x00003009
_080299F8: .4byte 0x00003014
_080299FC:
	ldr r4, _08029A44
	ldr r0, [r4]
	ldr r1, _08029A48
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _08029A14
	b _08029D10
_08029A14:
	ldr r0, _08029A4C
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08029A22
	b _08029D10
_08029A22:
	movs r0, #0
	strh r0, [r2]
	movs r0, #5
	bl PlaySE
	bl sub_08027508
	ldr r1, _08029A50
	cmp r0, r1
	bhi _08029A58
	ldr r0, [r4]
	ldr r2, _08029A54
	adds r0, r0, r2
	movs r1, #0x7f
	strb r1, [r0]
	b _08029A68
	.align 2, 0
_08029A44: .4byte 0x020229AC
_08029A48: .4byte 0x0000301C
_08029A4C: .4byte 0x03002360
_08029A50: .4byte 0x00000BB7
_08029A54: .4byte 0x00003014
_08029A58:
	bl StopMapMusic
	ldr r1, [r4]
	ldr r0, _08029AAC
	adds r1, r1, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08029A68:
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0xf
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #5
	bl FillBgTilemapBufferRect_Palette0
	ldr r5, _08029AB0
	ldr r0, [r5]
	ldr r4, _08029AB4
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r6, _08029AB8
	adds r0, r6, #0
	bl AddWindow
	ldr r1, [r5]
	adds r1, r1, r4
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r6, #0
	bl sub_08028EA0
	b _08029D10
	.align 2, 0
_08029AAC: .4byte 0x00003014
_08029AB0: .4byte 0x020229AC
_08029AB4: .4byte 0x00003009
_08029AB8: .4byte 0x082CB458
_08029ABC:
	ldr r0, _08029B94
	bl PlayNewMapMusic
	ldr r4, _08029B98
	ldr r0, [r4]
	ldr r6, _08029B9C
	adds r0, r0, r6
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r4]
	ldr r1, _08029BA0
	mov sl, r1
	add r0, sl
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r5, _08029BA4
	movs r2, #1
	rsbs r2, r2, #0
	movs r0, #0
	adds r1, r5, #0
	bl GetStringWidth
	adds r1, r0, #0
	movs r0, #0xe0
	subs r0, r0, r1
	lsrs r3, r0, #1
	ldr r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	movs r2, #2
	mov sb, r2
	str r2, [sp]
	movs r1, #0xff
	mov r8, r1
	str r1, [sp, #4]
	movs r6, #0
	str r6, [sp, #8]
	movs r1, #0
	adds r2, r5, #0
	bl AddTextPrinterParameterized
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_080273EC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08029BA8
	adds r1, r5, #0
	bl CopyItemName
	movs r0, #0
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r7, _08029BAC
	ldr r1, _08029BB0
	adds r0, r7, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, [r4]
	add r0, sl
	ldrb r0, [r0]
	mov r2, sb
	str r2, [sp]
	mov r1, r8
	str r1, [sp, #4]
	str r6, [sp, #8]
	movs r1, #0
	adds r2, r7, #0
	movs r3, #8
	bl AddTextPrinterParameterized
	bl sub_08027788
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r6, r4, #0
	cmp r4, #0
	beq _08029BE2
	cmp r4, #3
	beq _08029BE2
	bl DynamicPlaceholderTextUtil_Reset
	bl sub_080273EC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl CopyItemName
	movs r0, #0
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	cmp r4, #2
	bne _08029BB8
	ldr r1, _08029BB4
	adds r0, r7, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	b _08029BC4
	.align 2, 0
_08029B94: .4byte 0x0000016F
_08029B98: .4byte 0x020229AC
_08029B9C: .4byte 0x00003008
_08029BA0: .4byte 0x00003009
_08029BA4: .4byte 0x085CCD68
_08029BA8: .4byte 0x02021C40
_08029BAC: .4byte 0x02021C7C
_08029BB0: .4byte 0x085CCD86
_08029BB4: .4byte 0x085CCD9F
_08029BB8:
	cmp r6, #1
	bne _08029BC4
	ldr r1, _08029C08
	adds r0, r7, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
_08029BC4:
	ldr r0, _08029C0C
	ldr r0, [r0]
	ldr r2, _08029C10
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r2, _08029C14
	movs r1, #0x28
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r3, #8
	bl AddTextPrinterParameterized
_08029BE2:
	ldr r4, _08029C0C
	ldr r0, [r4]
	ldr r1, _08029C18
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, [r4]
	ldr r2, _08029C10
	adds r0, r0, r2
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r4]
	ldr r0, _08029C1C
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_08029C08: .4byte 0x085CCDAB
_08029C0C: .4byte 0x020229AC
_08029C10: .4byte 0x00003009
_08029C14: .4byte 0x02021C7C
_08029C18: .4byte 0x00003008
_08029C1C: .4byte 0x00003014
_08029C20:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08029C44
	ldr r4, _08029C60
	ldr r0, [r4]
	ldr r1, _08029C64
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r4]
	ldr r2, _08029C68
	adds r0, r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029C44:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _08029C6C
	movs r1, #0x14
	movs r2, #0xa
	bl FadeOutAndFadeInNewMapMusic
	ldr r0, _08029C60
	ldr r1, [r0]
	ldr r0, _08029C70
	adds r1, r1, r0
	b _08029CA6
	.align 2, 0
_08029C60: .4byte 0x020229AC
_08029C64: .4byte 0x00003008
_08029C68: .4byte 0x00003009
_08029C6C: .4byte 0x0000020B
_08029C70: .4byte 0x00003014
_08029C74:
	ldr r4, _08029CB0
	ldr r0, [r4]
	ldr r1, _08029CB4
	adds r2, r0, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08029D10
	ldr r0, _08029CB8
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029D10
	movs r0, #0
	strh r0, [r2]
	movs r0, #5
	bl PlaySE
_08029CA0:
	ldr r1, [r4]
_08029CA2:
	ldr r2, _08029CBC
	adds r1, r1, r2
_08029CA6:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08029D10
	.align 2, 0
_08029CB0: .4byte 0x020229AC
_08029CB4: .4byte 0x0000301C
_08029CB8: .4byte 0x03002360
_08029CBC: .4byte 0x00003014
_08029CC0:
	ldr r5, _08029D20
	adds r0, r1, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	ldr r4, _08029D24
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r0, r5
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
_08029D10:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08029D20: .4byte 0x00003008
_08029D24: .4byte 0x00003009
	thumb_func_end sub_080295A4

	thumb_func_start sub_08029D28
sub_08029D28: @ 0x08029D28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r1, _08029D50
	ldr r2, [r1]
	ldr r3, _08029D54
	adds r0, r2, r3
	ldrb r7, [r0]
	adds r6, r1, #0
	cmp r7, #1
	beq _08029DDC
	cmp r7, #1
	bgt _08029D58
	cmp r7, #0
	beq _08029D66
	b _08029FF4
	.align 2, 0
_08029D50: .4byte 0x020229AC
_08029D54: .4byte 0x00003014
_08029D58:
	cmp r7, #2
	bne _08029D5E
	b _08029EA0
_08029D5E:
	cmp r7, #3
	bne _08029D64
	b _08029ED4
_08029D64:
	b _08029FF4
_08029D66:
	ldr r0, _08029DC4
	bl AddWindow
	ldr r1, [r6]
	ldr r5, _08029DC8
	adds r1, r1, r5
	strb r0, [r1]
	ldr r0, _08029DC4
	adds r0, #8
	mov r8, r0
	bl AddWindow
	ldr r1, [r6]
	ldr r4, _08029DCC
	adds r1, r1, r4
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r0, r5
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, _08029DC4
	bl sub_08028EA0
	mov r0, r8
	bl sub_08028DA0
	ldr r1, [r6]
	ldr r2, _08029DD0
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	ldr r3, _08029DD4
	adds r0, r0, r3
	strb r7, [r0]
	ldr r0, [r6]
	ldr r1, _08029DD8
	adds r0, r0, r1
	strb r7, [r0]
	b _0802A054
	.align 2, 0
_08029DC4: .4byte 0x082CB460
_08029DC8: .4byte 0x00003008
_08029DCC: .4byte 0x00003009
_08029DD0: .4byte 0x00003014
_08029DD4: .4byte 0x00003020
_08029DD8: .4byte 0x00003024
_08029DDC:
	ldr r3, _08029E84
	mov r8, r3
	adds r0, r2, r3
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	ldr r7, _08029E88
	adds r0, r0, r7
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, _08029E8C
	movs r1, #6
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #8
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	ldr r2, _08029E90
	movs r3, #2
	mov sb, r3
	str r3, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0xc
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	ldr r2, _08029E94
	movs r1, #0x12
	str r1, [sp]
	movs r3, #0xff
	str r3, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0xc
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	ldr r2, _08029E98
	mov r1, sb
	str r1, [sp]
	movs r3, #0xff
	str r3, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #2
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r6]
	ldr r0, _08029E9C
	adds r1, r1, r0
	b _08029FE8
	.align 2, 0
_08029E84: .4byte 0x00003008
_08029E88: .4byte 0x00003009
_08029E8C: .4byte 0x085CCDBD
_08029E90: .4byte 0x085CAAD8
_08029E94: .4byte 0x085CAADB
_08029E98: .4byte 0x085C9421
_08029E9C: .4byte 0x00003014
_08029EA0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08029EC2
	ldr r0, [r6]
	ldr r1, _08029ECC
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r6]
	ldr r2, _08029ED0
	adds r0, r0, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
_08029EC2:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	b _08029FE2
	.align 2, 0
_08029ECC: .4byte 0x00003008
_08029ED0: .4byte 0x00003009
_08029ED4:
	ldr r0, _08029F7C
	mov sl, r0
	adds r0, r2, r0
	ldrb r7, [r0]
	cmp r7, #0
	bne _08029EE2
	movs r7, #1
_08029EE2:
	ldr r1, _08029F80
	mov r8, r1
	adds r0, r2, r1
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, _08029F84
	movs r3, #2
	mov sb, r3
	str r3, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r4, #0
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0xc
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, _08029F88
	movs r1, #0x12
	str r1, [sp]
	movs r3, #0xff
	str r3, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #0xc
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	ldr r2, _08029F8C
	subs r1, r7, #1
	lsls r1, r1, #4
	adds r1, #2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	movs r3, #2
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	add r0, r8
	ldrb r0, [r0]
	movs r1, #3
	bl CopyWindowToVram
	ldr r0, _08029F90
	ldrh r1, [r0, #0x2e]
	movs r4, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08029F94
	movs r0, #5
	bl PlaySE
	ldr r0, [r6]
	mov r2, sl
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	bne _08029FE2
	strb r4, [r1]
	b _08029FE2
	.align 2, 0
_08029F7C: .4byte 0x00003020
_08029F80: .4byte 0x00003009
_08029F84: .4byte 0x085CAAD8
_08029F88: .4byte 0x085CAADB
_08029F8C: .4byte 0x085C9421
_08029F90: .4byte 0x03002360
_08029F94:
	movs r0, #0xc0
	ands r0, r1
	cmp r0, #0
	beq _08029FCC
	movs r0, #5
	bl PlaySE
	ldr r0, [r6]
	add r0, sl
	ldrb r2, [r0]
	cmp r2, #1
	beq _08029FC2
	cmp r2, #1
	bgt _08029FB6
	cmp r2, #0
	beq _08029FBC
	b _0802A054
_08029FB6:
	cmp r2, #2
	beq _08029FC8
	b _0802A054
_08029FBC:
	mov r1, sb
	strb r1, [r0]
	b _0802A054
_08029FC2:
	mov r2, sb
	strb r2, [r0]
	b _0802A054
_08029FC8:
	strb r4, [r0]
	b _0802A054
_08029FCC:
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _0802A054
	movs r0, #5
	bl PlaySE
	ldr r0, [r6]
	add r0, sl
	movs r1, #2
	strb r1, [r0]
_08029FE2:
	ldr r1, [r6]
	ldr r3, _08029FF0
	adds r1, r1, r3
_08029FE8:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A054
	.align 2, 0
_08029FF0: .4byte 0x00003014
_08029FF4:
	ldr r0, [r6]
	ldr r2, _0802A064
	adds r1, r0, r2
	ldrb r1, [r1]
	ldr r3, _0802A068
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r6]
	ldr r7, _0802A06C
	adds r0, r0, r7
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	ldr r4, _0802A070
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r0, r7
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
_0802A054:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A064: .4byte 0x00003020
_0802A068: .4byte 0x00003024
_0802A06C: .4byte 0x00003008
_0802A070: .4byte 0x00003009
	thumb_func_end sub_08029D28

	thumb_func_start sub_0802A074
sub_0802A074: @ 0x0802A074
	push {r4, r5, r6, lr}
	sub sp, #0x10
	ldr r5, _0802A090
	ldr r0, [r5]
	ldr r6, _0802A094
	adds r0, r0, r6
	ldrb r4, [r0]
	cmp r4, #1
	beq _0802A0CC
	cmp r4, #1
	bgt _0802A098
	cmp r4, #0
	beq _0802A0A2
	b _0802A114
	.align 2, 0
_0802A090: .4byte 0x020229AC
_0802A094: .4byte 0x00003014
_0802A098:
	cmp r4, #2
	beq _0802A0E0
	cmp r4, #3
	beq _0802A0F8
	b _0802A114
_0802A0A2:
	movs r0, #0
	movs r1, #0
	bl DrawDialogueFrame
	ldr r2, _0802A0C8
	str r4, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	movs r0, #0
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized2
	b _0802A104
	.align 2, 0
_0802A0C8: .4byte 0x08277071
_0802A0CC:
	movs r0, #0
	movs r1, #3
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, _0802A0DC
	adds r1, r1, r0
	b _0802A108
	.align 2, 0
_0802A0DC: .4byte 0x00003014
_0802A0E0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A13C
	ldr r0, _0802A0F4
	movs r1, #0
	bl CreateTask
	b _0802A104
	.align 2, 0
_0802A0F4: .4byte 0x081535C5
_0802A0F8:
	ldr r0, _0802A110
	bl FuncIsActiveTask
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A13C
_0802A104:
	ldr r1, [r5]
	adds r1, r1, r6
_0802A108:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A13C
	.align 2, 0
_0802A110: .4byte 0x081535C5
_0802A114:
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, _0802A144
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
_0802A13C:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0802A144: .4byte 0x020229AC
	thumb_func_end sub_0802A074

	thumb_func_start sub_0802A148
sub_0802A148: @ 0x0802A148
	push {r4, r5, r6, lr}
	sub sp, #0xc
	ldr r1, _0802A168
	ldr r2, [r1]
	ldr r6, _0802A16C
	adds r0, r2, r6
	ldrb r0, [r0]
	adds r5, r1, #0
	cmp r0, #1
	beq _0802A1A0
	cmp r0, #1
	bgt _0802A170
	cmp r0, #0
	beq _0802A176
	b _0802A214
	.align 2, 0
_0802A168: .4byte 0x020229AC
_0802A16C: .4byte 0x00003014
_0802A170:
	cmp r0, #2
	beq _0802A1E8
	b _0802A214
_0802A176:
	ldr r4, _0802A198
	adds r0, r4, #0
	bl AddWindow
	ldr r1, [r5]
	ldr r2, _0802A19C
	adds r1, r1, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, #0
	bl sub_08028EA0
	b _0802A204
	.align 2, 0
_0802A198: .4byte 0x082CB478
_0802A19C: .4byte 0x00003008
_0802A1A0:
	ldr r4, _0802A1DC
	adds r0, r2, r4
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r2, _0802A1E0
	movs r1, #6
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #4
	bl AddTextPrinterParameterized
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r5]
	ldr r0, _0802A1E4
	adds r1, r1, r0
	b _0802A208
	.align 2, 0
_0802A1DC: .4byte 0x00003008
_0802A1E0: .4byte 0x085CCDEA
_0802A1E4: .4byte 0x00003014
_0802A1E8:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A1FE
	ldr r0, [r5]
	ldr r1, _0802A210
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A1FE:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
_0802A204:
	ldr r1, [r5]
	adds r1, r1, r6
_0802A208:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A220
	.align 2, 0
_0802A210: .4byte 0x00003008
_0802A214:
	ldr r0, [r5]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
_0802A220:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_0802A148

	thumb_func_start sub_0802A228
sub_0802A228: @ 0x0802A228
	push {r4, r5, lr}
	sub sp, #8
	ldr r5, _0802A274
	ldr r0, [r5]
	ldr r4, _0802A278
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r5]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0802A274: .4byte 0x020229AC
_0802A278: .4byte 0x00003008
	thumb_func_end sub_0802A228

	thumb_func_start sub_0802A27C
sub_0802A27C: @ 0x0802A27C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldr r0, _0802A29C
	ldr r1, [r0]
	ldr r7, _0802A2A0
	adds r2, r1, r7
	ldrb r5, [r2]
	adds r6, r0, #0
	cmp r5, #1
	beq _0802A304
	cmp r5, #1
	bgt _0802A2A4
	cmp r5, #0
	beq _0802A2AE
	b _0802A398
	.align 2, 0
_0802A29C: .4byte 0x020229AC
_0802A2A0: .4byte 0x00003014
_0802A2A4:
	cmp r5, #2
	beq _0802A34C
	cmp r5, #3
	beq _0802A378
	b _0802A398
_0802A2AE:
	ldr r4, _0802A2F4
	adds r0, r4, #0
	bl AddWindow
	ldr r1, [r6]
	ldr r2, _0802A2F8
	adds r1, r1, r2
	strb r0, [r1]
	ldr r0, [r6]
	adds r0, r0, r2
	ldrb r0, [r0]
	bl ClearWindowTilemap
	adds r0, r4, #0
	bl sub_08028EA0
	ldr r1, [r6]
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r6]
	ldr r2, _0802A2FC
	adds r1, r0, r2
	movs r2, #0
	strh r5, [r1]
	ldr r1, _0802A300
	adds r0, r0, r1
	strb r2, [r0]
	ldr r0, [r6]
	adds r1, #4
	adds r0, r0, r1
	strb r2, [r0]
	b _0802A3DE
	.align 2, 0
_0802A2F4: .4byte 0x082CB470
_0802A2F8: .4byte 0x00003008
_0802A2FC: .4byte 0x0000301C
_0802A300: .4byte 0x00003020
_0802A304:
	ldr r4, _0802A340
	adds r0, r1, r4
	ldrb r0, [r0]
	movs r1, #0x11
	bl FillWindowPixelBuffer
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	ldr r2, _0802A344
	movs r1, #6
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	movs r3, #2
	bl AddTextPrinterParameterized
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
	ldr r1, [r6]
	ldr r2, _0802A348
	adds r1, r1, r2
	b _0802A36C
	.align 2, 0
_0802A340: .4byte 0x00003008
_0802A344: .4byte 0x085CCDCB
_0802A348: .4byte 0x00003014
_0802A34C:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0802A362
	ldr r0, [r6]
	ldr r1, _0802A374
	adds r0, r0, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
_0802A362:
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r1, [r6]
	adds r1, r1, r7
_0802A36C:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0802A3DE
	.align 2, 0
_0802A374: .4byte 0x00003008
_0802A378:
	ldr r0, _0802A394
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _0802A3DE
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _0802A3DE
	.align 2, 0
_0802A394: .4byte 0x0000301C
_0802A398:
	ldr r0, [r6]
	ldr r1, _0802A3E8
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
	ldr r0, [r6]
	ldr r4, _0802A3EC
	adds r0, r0, r4
	ldrb r0, [r0]
	bl ClearWindowTilemap
	ldr r0, [r6]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0x14
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	ldr r0, [r6]
	movs r2, #0xc0
	lsls r2, r2, #6
	adds r0, r0, r2
	movs r1, #1
	str r1, [r0]
_0802A3DE:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0802A3E8: .4byte 0x00003024
_0802A3EC: .4byte 0x00003008
	thumb_func_end sub_0802A27C

	thumb_func_start sub_0802A3F0
sub_0802A3F0: @ 0x0802A3F0
	push {r4, lr}
	ldr r4, _0802A414
	ldr r0, [r4]
	ldr r1, _0802A418
	adds r0, r0, r1
	ldrb r0, [r0]
	bl DestroyTask
	ldr r0, [r4]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r1, #1
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A414: .4byte 0x020229AC
_0802A418: .4byte 0x00003004
	thumb_func_end sub_0802A3F0

	thumb_func_start sub_0802A41C
sub_0802A41C: @ 0x0802A41C
	bx lr
	.align 2, 0
	thumb_func_end sub_0802A41C

	thumb_func_start sub_0802A420
sub_0802A420: @ 0x0802A420
	push {r4, lr}
	ldr r2, _0802A444
	ldr r1, [r2]
	ldr r3, _0802A448
	adds r1, r1, r3
	movs r3, #0
	strb r3, [r1]
	ldr r1, [r2]
	movs r4, #0xc0
	lsls r4, r4, #6
	adds r2, r1, r4
	str r3, [r2]
	ldr r2, _0802A44C
	adds r1, r1, r2
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0802A444: .4byte 0x020229AC
_0802A448: .4byte 0x00003014
_0802A44C: .4byte 0x00003028
	thumb_func_end sub_0802A420

	thumb_func_start sub_0802A450
sub_0802A450: @ 0x0802A450
	ldr r0, _0802A45C
	ldr r0, [r0]
	ldr r1, _0802A460
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0802A45C: .4byte 0x020229AC
_0802A460: .4byte 0x00003028
	thumb_func_end sub_0802A450

	thumb_func_start sub_0802A464
sub_0802A464: @ 0x0802A464
	push {lr}
	ldr r0, _0802A47C
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #6
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #1
	beq _0802A480
	movs r0, #1
	b _0802A482
	.align 2, 0
_0802A47C: .4byte 0x020229AC
_0802A480:
	movs r0, #0
_0802A482:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_0802A464

	thumb_func_start sub_0802A488
sub_0802A488: @ 0x0802A488
	ldr r0, _0802A494
	ldr r0, [r0]
	ldr r1, _0802A498
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0802A494: .4byte 0x020229AC
_0802A498: .4byte 0x00003024
	thumb_func_end sub_0802A488

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
