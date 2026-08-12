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
