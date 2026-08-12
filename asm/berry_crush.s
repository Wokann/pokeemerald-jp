.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified














	thumb_func_start sub_08021758
sub_08021758: @ 0x08021758
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	str r0, [sp, #0xc]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x10]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x14]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp, #0x18]
	movs r7, #0
	movs r0, #0
	str r0, [sp, #0x1c]
	movs r1, #0
	str r1, [sp, #0x20]
	ldr r2, [sp, #0xc]
	adds r2, #0x68
	str r2, [sp, #0x24]
	ldr r4, [sp, #0xc]
	ldrb r4, [r4, #9]
	cmp r7, r4
	blo _08021792
	b _08021A9A
_08021792:
	ldr r0, [sp, #0x10]
	lsls r0, r0, #2
	str r0, [sp, #0x28]
	movs r2, #0xd3
	lsls r2, r2, #1
	ldr r1, [sp, #0xc]
	adds r2, r1, r2
	str r2, [sp, #0x2c]
_080217A2:
	bl DynamicPlaceholderTextUtil_Reset
	ldr r4, [sp, #0x10]
	cmp r4, #1
	beq _0802188C
	cmp r4, #1
	bgt _080217B6
	cmp r4, #0
	beq _080217CE
	b _080217BE
_080217B6:
	ldr r4, [sp, #0x10]
	cmp r4, #2
	bne _080217BE
	b _08021990
_080217BE:
	ldr r0, [sp, #0x20]
	adds r0, #0xa2
	mov r8, r0
	ldr r1, [sp, #0x1c]
	lsls r5, r1, #3
	adds r2, r7, #1
	mov sb, r2
	b _08021A0A
_080217CE:
	ldr r0, [sp, #0x24]
	adds r0, #0x20
	adds r0, r0, r7
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
	lsls r3, r7, #1
	ldr r2, [sp, #0x24]
	adds r2, #0xc
	cmp r7, #0
	beq _080217F4
	adds r0, r2, r3
	subs r1, r7, #1
	lsls r1, r1, #1
	adds r1, r2, r1
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _080217F4
	str r7, [sp, #0x20]
_080217F4:
	ldr r4, [sp, #0x28]
	ldr r1, [sp, #0x10]
	adds r0, r4, r1
	lsls r0, r0, #1
	adds r0, r3, r0
	adds r0, r2, r0
	ldrh r1, [r0]
	ldr r0, _08021880
	movs r2, #1
	movs r3, #4
	bl ConvertIntToDecimalStringN
	ldr r0, _08021884
	adds r0, r4, r0
	ldr r5, [r0]
	movs r0, #1
	adds r1, r5, #0
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	ldr r2, [sp, #0x14]
	subs r0, r2, r0
	subs r0, #4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r4, [sp, #0x2c]
	ldrb r0, [r4]
	movs r1, #0xd
	adds r4, r7, #0
	muls r4, r1, r4
	ldr r1, [sp, #0x18]
	adds r4, r1, r4
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r2, _08021888
	str r2, [sp]
	movs r1, #0
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	adds r2, r6, #0
	adds r3, r4, #0
	bl AddTextPrinterParameterized3
	ldr r2, [sp, #0x2c]
	ldrb r0, [r2]
	adds r2, r6, #0
	subs r2, #0x21
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r1, _08021888
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	ldr r1, _08021880
	str r1, [sp, #8]
	movs r1, #0
	adds r3, r4, #0
	bl AddTextPrinterParameterized3
	ldr r2, [sp, #0x20]
	adds r2, #0xa2
	mov r8, r2
	ldr r4, [sp, #0x1c]
	lsls r5, r4, #3
	adds r0, r7, #1
	mov sb, r0
	b _08021A0A
	.align 2, 0
_08021880: .4byte 0x02021C40
_08021884: .4byte 0x082C7C40
_08021888: .4byte 0x082C5EF0
_0802188C:
	ldr r1, [sp, #0x24]
	adds r0, r1, r7
	adds r0, #0x28
	ldrb r0, [r0]
	str r0, [sp, #0x1c]
	lsls r3, r7, #1
	adds r2, r1, #0
	adds r2, #0xc
	cmp r7, #0
	beq _080218B6
	adds r0, r3, #0
	adds r0, #0xa
	adds r0, r2, r0
	adds r1, r3, #0
	adds r1, #8
	adds r1, r2, r1
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	beq _080218B6
	str r7, [sp, #0x20]
_080218B6:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x10]
	adds r4, r0, r1
	lsls r4, r4, #1
	adds r4, r3, r4
	adds r4, r2, r4
	ldrh r1, [r4]
	lsrs r1, r1, #4
	ldr r0, _08021974
	movs r2, #1
	movs r3, #3
	bl ConvertIntToDecimalStringN
	movs r3, #0
	ldrb r0, [r4]
	movs r6, #0xf
	ands r6, r0
	movs r2, #0
	ldr r4, [sp, #0x10]
	lsls r4, r4, #2
	str r4, [sp, #0x34]
	ldr r0, [sp, #0x14]
	subs r0, #0x34
	str r0, [sp, #0x30]
	ldr r1, [sp, #0x20]
	adds r1, #0xa2
	mov r8, r1
	ldr r4, [sp, #0x1c]
	lsls r5, r4, #3
	adds r0, r7, #1
	mov sb, r0
	movs r1, #3
	mov sl, r1
	movs r4, #1
	mov ip, r4
	ldr r4, _08021978
_080218FE:
	mov r0, sl
	subs r1, r0, r2
	adds r0, r6, #0
	asrs r0, r1
	mov r1, ip
	ands r0, r1
	cmp r0, #0
	beq _08021916
	lsls r0, r2, #2
	adds r0, r0, r4
	ldr r0, [r0]
	adds r3, r3, r0
_08021916:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _080218FE
	adds r0, r3, #0
	ldr r1, _0802197C
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _08021980
	adds r1, r6, #0
	movs r2, #2
	movs r3, #2
	bl ConvertIntToDecimalStringN
	ldr r0, _08021984
	ldr r2, [sp, #0x34]
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r0, _08021988
	bl StringExpandPlaceholders
	ldr r4, [sp, #0x2c]
	ldrb r0, [r4]
	ldr r1, [sp, #0x30]
	lsls r2, r1, #0x18
	lsrs r2, r2, #0x18
	movs r1, #0xd
	adds r3, r7, #0
	muls r3, r1, r3
	ldr r4, [sp, #0x18]
	adds r3, r4, r3
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r1, _0802198C
	str r1, [sp]
	movs r4, #0
	str r4, [sp, #4]
	ldr r1, _08021988
	str r1, [sp, #8]
	movs r1, #0
	bl AddTextPrinterParameterized3
	b _08021A0A
	.align 2, 0
_08021974: .4byte 0x02021C40
_08021978: .4byte 0x082C5F64
_0802197C: .4byte 0x000F4240
_08021980: .4byte 0x02021C54
_08021984: .4byte 0x082C7C40
_08021988: .4byte 0x02021C7C
_0802198C: .4byte 0x082C5EF0
_08021990:
	str r7, [sp, #0x1c]
	str r7, [sp, #0x20]
	lsls r4, r7, #3
	subs r0, r4, r7
	lsls r0, r0, #2
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	adds r0, #0xa0
	ldrb r2, [r0]
	cmp r2, #0x2b
	bls _080219A8
	movs r2, #0
_080219A8:
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	ldr r0, _08021A20
	adds r1, r1, r0
	ldr r0, _08021A24
	bl StringCopy
	ldr r0, _08021A28
	ldr r1, [r0, #8]
	ldr r0, _08021A2C
	bl StringExpandPlaceholders
	movs r0, #1
	ldr r1, _08021A2C
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	adds r2, r0, #0
	ldr r0, [sp, #0x14]
	subs r2, r0, r2
	subs r2, #4
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	movs r1, #0xd
	adds r3, r7, #0
	muls r3, r1, r3
	ldr r1, [sp, #0x18]
	adds r3, r1, r3
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r1, _08021A30
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	ldr r1, _08021A2C
	str r1, [sp, #8]
	movs r1, #1
	bl AddTextPrinterParameterized3
	movs r2, #0xa2
	adds r2, r2, r7
	mov r8, r2
	adds r5, r4, #0
	adds r4, r7, #1
	mov sb, r4
_08021A0A:
	ldr r1, [sp, #0x1c]
	ldr r0, [sp, #0xc]
	ldrb r0, [r0, #8]
	cmp r1, r0
	bne _08021A3C
	ldr r0, _08021A34
	ldr r1, _08021A38
	bl StringCopy
	b _08021A44
	.align 2, 0
_08021A20: .4byte 0x08563150
_08021A24: .4byte 0x02021C40
_08021A28: .4byte 0x082C7C40
_08021A2C: .4byte 0x02021C7C
_08021A30: .4byte 0x082C5EF0
_08021A34: .4byte 0x02021C68
_08021A38: .4byte 0x085CC9C8
_08021A3C:
	ldr r0, _08021AAC
	ldr r1, _08021AB0
	bl StringCopy
_08021A44:
	ldr r4, _08021AAC
	mov r1, r8
	strb r1, [r4]
	ldr r2, [sp, #0x1c]
	subs r1, r5, r2
	lsls r1, r1, #2
	adds r1, #0x98
	ldr r0, [sp, #0xc]
	adds r1, r0, r1
	movs r0, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r0, _08021AB4
	adds r1, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	movs r1, #0xd
	adds r3, r7, #0
	muls r3, r1, r3
	ldr r2, [sp, #0x18]
	adds r3, r2, r3
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r4, _08021AB8
	str r4, [sp]
	movs r1, #0
	str r1, [sp, #4]
	ldr r2, _08021AB4
	str r2, [sp, #8]
	movs r1, #1
	movs r2, #4
	bl AddTextPrinterParameterized3
	mov r4, sb
	lsls r0, r4, #0x18
	lsrs r7, r0, #0x18
	ldr r0, [sp, #0xc]
	ldrb r0, [r0, #9]
	cmp r7, r0
	bhs _08021A9A
	b _080217A2
_08021A9A:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021AAC: .4byte 0x02021C68
_08021AB0: .4byte 0x085CC9D4
_08021AB4: .4byte 0x02021C7C
_08021AB8: .4byte 0x082C5EF0
	thumb_func_end sub_08021758

	thumb_func_start sub_08021ABC
sub_08021ABC: @ 0x08021ABC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	movs r0, #0
	mov sl, r0
	movs r6, #0
	movs r1, #0
	str r1, [sp, #0xc]
	mov r2, r8
	adds r2, #0x68
	str r2, [sp, #0x10]
	movs r4, #0xd3
	lsls r4, r4, #1
	add r4, r8
	mov sb, r4
	ldrb r0, [r4]
	movs r1, #4
	bl GetWindowAttribute
	lsls r0, r0, #0x1b
	movs r1, #0xda
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r7, r0, #0x18
	movs r0, #0x92
	lsls r0, r0, #1
	add r0, r8
	ldr r2, [sp, #0x10]
	ldrh r1, [r2, #4]
	bl sub_08021674
	ldrb r0, [r4]
	ldr r4, _08021CF4
	str r4, [sp]
	str r6, [sp, #4]
	ldr r1, _08021CF8
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #2
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
	ldr r4, _08021CFC
	movs r0, #1
	adds r1, r4, #0
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	movs r1, #0xae
	subs r0, r1, r0
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	mov r2, sb
	ldrb r0, [r2]
	ldr r1, _08021CF4
	str r1, [sp]
	mov r2, sl
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	adds r2, r6, #0
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
	adds r0, r6, #0
	subs r0, #0x29
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #0x95
	lsls r0, r0, #1
	add r0, r8
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r0, _08021D00
	movs r2, #2
	movs r3, #2
	bl ConvertIntToDecimalStringN
	ldr r0, _08021D04
	movs r1, #0x96
	lsls r1, r1, #1
	add r1, r8
	movs r2, #0
	ldrsh r1, [r1, r2]
	movs r2, #2
	movs r3, #2
	bl ConvertIntToDecimalStringN
	ldr r5, _08021D08
	ldr r1, _08021D0C
	adds r0, r5, #0
	bl StringExpandPlaceholders
	mov r4, sb
	ldrb r0, [r4]
	ldr r1, _08021CF4
	str r1, [sp]
	mov r2, sl
	str r2, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
	ldr r4, _08021D10
	movs r0, #1
	adds r1, r4, #0
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	subs r1, r6, #1
	subs r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	mov r1, sb
	ldrb r0, [r1]
	ldr r2, _08021CF4
	str r2, [sp]
	mov r1, sl
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	adds r2, r6, #0
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
	adds r0, r6, #0
	subs r0, #9
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #0x94
	lsls r0, r0, #1
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08021D00
	movs r2, #2
	movs r3, #1
	bl ConvertIntToDecimalStringN
	ldr r1, _08021D14
	adds r0, r5, #0
	bl StringExpandPlaceholders
	mov r4, sb
	ldrb r0, [r4]
	ldr r1, _08021CF4
	str r1, [sp]
	mov r2, sl
	str r2, [sp, #4]
	str r5, [sp, #8]
	movs r1, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
	adds r0, r7, #0
	adds r0, #0xd
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrb r0, [r4]
	ldr r4, _08021CF4
	str r4, [sp]
	mov r1, sl
	str r1, [sp, #4]
	ldr r1, _08021D18
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #2
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
	ldr r4, _08021D1C
	movs r0, #1
	adds r1, r4, #0
	movs r2, #1
	rsbs r2, r2, #0
	bl GetStringWidth
	movs r2, #0xae
	subs r0, r2, r0
	lsls r0, r0, #0x18
	str r0, [sp, #0x18]
	lsrs r6, r0, #0x18
	mov r1, sb
	ldrb r0, [r1]
	ldr r2, _08021CF4
	str r2, [sp]
	mov r1, sl
	str r1, [sp, #4]
	str r4, [sp, #8]
	movs r1, #1
	adds r2, r6, #0
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
	mov r4, r8
	ldrb r2, [r4, #0x16]
	ldrh r0, [r4, #0x16]
	mov ip, r0
	movs r1, #7
	mov sb, r1
	movs r5, #1
	ldr r3, _08021D20
_08021C62:
	mov r4, sb
	mov r0, sl
	subs r1, r4, r0
	adds r0, r2, #0
	asrs r0, r1
	ands r0, r5
	cmp r0, #0
	beq _08021C80
	mov r1, sl
	lsls r0, r1, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0xc]
	adds r4, r4, r0
	str r4, [sp, #0xc]
_08021C80:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	cmp r0, #7
	bls _08021C62
	ldr r0, _08021D00
	mov r2, ip
	lsrs r1, r2, #8
	movs r2, #1
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r4, _08021D04
	ldr r1, _08021D24
	ldr r0, [sp, #0xc]
	bl __udivsi3
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #2
	movs r3, #2
	bl ConvertIntToDecimalStringN
	ldr r4, _08021D08
	ldr r1, _08021D28
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r6, #0
	subs r0, #0x31
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	mov r0, r8
	adds r0, #0x25
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	beq _08021D30
	movs r0, #0xd3
	lsls r0, r0, #1
	add r0, r8
	ldrb r0, [r0]
	ldr r1, _08021D2C
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	str r4, [sp, #8]
	adds r2, r6, #0
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
	b _08021D4A
	.align 2, 0
_08021CF4: .4byte 0x082C5EF0
_08021CF8: .4byte 0x085CC9F0
_08021CFC: .4byte 0x085CCA14
_08021D00: .4byte 0x02021C40
_08021D04: .4byte 0x02021C54
_08021D08: .4byte 0x02021C7C
_08021D0C: .4byte 0x085CCA0C
_08021D10: .4byte 0x085CCA08
_08021D14: .4byte 0x085CCA04
_08021D18: .4byte 0x085CC9F4
_08021D1C: .4byte 0x085CCA20
_08021D20: .4byte 0x082C5F64
_08021D24: .4byte 0x000F4240
_08021D28: .4byte 0x085CCA18
_08021D2C: .4byte 0x082C5EFF
_08021D30:
	movs r0, #0xd3
	lsls r0, r0, #1
	add r0, r8
	ldrb r0, [r0]
	ldr r1, _08021DC8
	str r1, [sp]
	str r2, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
_08021D4A:
	adds r0, r7, #0
	adds r0, #0xd
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	movs r4, #0xd3
	lsls r4, r4, #1
	add r8, r4
	mov r1, r8
	ldrb r0, [r1]
	ldr r2, _08021DC8
	mov sb, r2
	str r2, [sp]
	movs r5, #0
	str r5, [sp, #4]
	ldr r1, _08021DCC
	str r1, [sp, #8]
	movs r1, #1
	movs r2, #2
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
	ldr r0, _08021DD0
	ldr r4, [sp, #0x10]
	ldrh r1, [r4, #8]
	movs r2, #1
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r4, _08021DD4
	ldr r1, _08021DD8
	adds r0, r4, #0
	bl StringExpandPlaceholders
	adds r0, r4, #0
	bl StringLength
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xd
	movs r2, #0x52
	rsbs r2, r2, #0
	adds r1, r2, #0
	subs r1, r1, r0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	mov r1, r8
	ldrb r0, [r1]
	mov r2, sb
	str r2, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	movs r1, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl AddTextPrinterParameterized3
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08021DC8: .4byte 0x082C5EF0
_08021DCC: .4byte 0x085CC9FC
_08021DD0: .4byte 0x02021C40
_08021DD4: .4byte 0x02021C7C
_08021DD8: .4byte 0x085CCA28
	thumb_func_end sub_08021ABC

	thumb_func_start sub_08021DDC
sub_08021DDC: @ 0x08021DDC
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r1, #0
	adds r0, r6, #0
	adds r0, #0x80
	ldrb r0, [r0]
	cmp r0, #5
	bls _08021DF0
	b _08021F88
_08021DF0:
	lsls r0, r0, #2
	ldr r1, _08021DFC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08021DFC: .4byte 0x08021E00
_08021E00: @ jump table
	.4byte _08021E18 @ case 0
	.4byte _08021E64 @ case 1
	.4byte _08021E78 @ case 2
	.4byte _08021E9C @ case 3
	.4byte _08021F68 @ case 4
	.4byte _08021F70 @ case 5
_08021E18:
	ldrb r0, [r4, #9]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r6, #0
	bl sub_080222B4
	ldrh r0, [r4, #0x12]
	lsls r0, r0, #3
	ldr r2, _08021E40
	mov r1, sp
	adds r0, r0, r2
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	ldrh r0, [r4, #0x12]
	cmp r0, #0xd
	bne _08021E48
	ldr r0, _08021E44
	adds r0, #4
	b _08021E4A
	.align 2, 0
_08021E40: .4byte 0x082C5EE4
_08021E44: .4byte 0x082C5F5C
_08021E48:
	ldr r0, _08021E60
_08021E4A:
	adds r0, r5, r0
	ldrb r1, [r0]
	mov r0, sp
	strb r1, [r0, #4]
	mov r0, sp
	bl AddWindow
	adds r1, r6, #0
	adds r1, #0x82
	strb r0, [r1]
	b _08021F88
	.align 2, 0
_08021E60: .4byte 0x082C5F5C
_08021E64:
	adds r4, r6, #0
	adds r4, #0x82
	ldrb r0, [r4]
	bl PutWindowTilemap
	ldrb r0, [r4]
	movs r1, #0
	bl FillWindowPixelBuffer
	b _08021F88
_08021E78:
	adds r5, r6, #0
	adds r5, #0x82
	ldrb r0, [r5]
	ldr r4, _08021E98
	adds r1, r4, #0
	movs r2, #0xd0
	bl LoadUserWindowBorderGfx_
	ldrb r0, [r5]
	movs r1, #0
	adds r2, r4, #0
	movs r3, #0xd
	bl DrawStdFrameWithCustomTileAndPalette
	b _08021F88
	.align 2, 0
_08021E98: .4byte 0x0000021D
_08021E9C:
	ldrb r0, [r4, #9]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrh r0, [r4, #0x12]
	cmp r0, #0xc
	beq _08021EF8
	cmp r0, #0xc
	bgt _08021EB4
	cmp r0, #0xb
	beq _08021EBA
	b _08021F88
_08021EB4:
	cmp r0, #0xd
	beq _08021F44
	b _08021F88
_08021EBA:
	adds r0, r6, #0
	adds r0, #0x82
	ldrb r0, [r0]
	ldr r3, _08021EF0
	movs r1, #0x14
	movs r2, #3
	bl sub_080216F8
	ldr r0, _08021EF4
	adds r0, r5, r0
	ldrb r3, [r0]
	lsls r3, r3, #3
	ldrb r1, [r4, #9]
	movs r0, #0xd
	muls r0, r1, r0
	subs r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0xa0
	bl sub_08021758
	adds r1, r6, #0
	adds r1, #0x80
	movs r0, #5
	b _08021F90
	.align 2, 0
_08021EF0: .4byte 0x085CCA30
_08021EF4: .4byte 0x082C5F5C
_08021EF8:
	adds r0, r6, #0
	adds r0, #0x82
	ldrb r0, [r0]
	ldr r2, _08021F3C
	adds r1, r4, #0
	adds r1, #0x8f
	ldrb r1, [r1]
	adds r1, #3
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r3, [r1]
	movs r1, #0x14
	movs r2, #4
	bl sub_080216F8
	ldr r0, _08021F40
	adds r0, r5, r0
	ldrb r3, [r0]
	lsls r3, r3, #3
	ldrb r1, [r4, #9]
	movs r0, #0xd
	muls r0, r1, r0
	subs r3, r3, r0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0xa0
	bl sub_08021758
	adds r1, r6, #0
	adds r1, #0x80
	movs r0, #5
	b _08021F90
	.align 2, 0
_08021F3C: .4byte 0x082C7C40
_08021F40: .4byte 0x082C5F5C
_08021F44:
	adds r0, r6, #0
	adds r0, #0x82
	ldrb r0, [r0]
	ldr r3, _08021F64
	movs r1, #0x16
	movs r2, #3
	bl sub_080216F8
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0xb0
	movs r3, #0x12
	bl sub_08021758
	b _08021F88
	.align 2, 0
_08021F64: .4byte 0x085CCA40
_08021F68:
	adds r0, r4, #0
	bl sub_08021ABC
	b _08021F88
_08021F70:
	adds r0, r6, #0
	adds r0, #0x82
	ldrb r0, [r0]
	movs r1, #3
	bl CopyWindowToVram
	adds r1, r6, #0
	adds r1, #0x80
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08021F94
_08021F88:
	adds r1, r6, #0
	adds r1, #0x80
	ldrb r0, [r1]
	adds r0, #1
_08021F90:
	strb r0, [r1]
	movs r0, #0
_08021F94:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_08021DDC

	thumb_func_start sub_08021F9C
sub_08021F9C: @ 0x08021F9C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xd3
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrb r0, [r5]
	movs r1, #1
	bl ClearStdWindowAndFrameToTransparent
	ldrb r0, [r5]
	bl RemoveWindow
	adds r0, r4, #0
	bl sub_08022360
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end sub_08021F9C

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

	thumb_func_start sub_08022230
sub_08022230: @ 0x08022230
	push {lr}
	bl LockPlayerFieldControls
	ldr r0, _08022278
	movs r1, #0
	bl CreateTask
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0802227C
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r2
	ldr r0, _08022280
	ldr r2, [r0]
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, #0xc]
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, #0xe]
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, #0x10]
	adds r3, #2
	adds r0, r2, r3
	ldrh r0, [r0]
	strh r0, [r1, #0x12]
	pop {r0}
	bx r0
	.align 2, 0
_08022278: .4byte 0x08021FC1
_0802227C: .4byte 0x03005B60
_08022280: .4byte 0x03005AF0
	thumb_func_end sub_08022230

