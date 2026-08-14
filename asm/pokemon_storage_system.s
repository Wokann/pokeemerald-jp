.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start IsCursorInBox
IsCursorInBox: @ 0x080CE3A0
	push {lr}
	movs r1, #0
	ldr r0, _080CE3B8
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080CE3B2
	movs r1, #1
_080CE3B2:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_080CE3B8: .4byte 0x02039A18
	thumb_func_end IsCursorInBox

	thumb_func_start sub_080CE3BC
sub_080CE3BC: @ 0x080CE3BC
	push {r4, lr}
	ldr r0, _080CE3F0
	ldr r1, [r0]
	movs r2, #0
	ldr r3, _080CE3F4
	ldrb r0, [r3]
	cmp r0, #0
	bne _080CE3CE
	movs r2, #1
_080CE3CE:
	ldr r4, _080CE3F8
	adds r0, r1, r4
	strb r2, [r0]
	ldrb r0, [r3]
	cmp r0, #0
	bne _080CE44C
	ldr r0, _080CE3FC
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	beq _080CE406
	cmp r0, #1
	bgt _080CE400
	cmp r0, #0
	beq _080CE436
	b _080CE44C
	.align 2, 0
_080CE3F0: .4byte 0x020399A8
_080CE3F4: .4byte 0x02039A1A
_080CE3F8: .4byte 0x00000CEA
_080CE3FC: .4byte 0x02039A18
_080CE400:
	cmp r0, #3
	bgt _080CE44C
	b _080CE42C
_080CE406:
	ldr r1, _080CE424
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _080CE42C
	adds r1, r0, #0
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _080CE428
	adds r0, r0, r1
	movs r1, #0
	bl SetCursorMonData
	b _080CE44C
	.align 2, 0
_080CE424: .4byte 0x02039A19
_080CE428: .4byte 0x02024190
_080CE42C:
	movs r0, #0
	movs r1, #2
	bl SetCursorMonData
	b _080CE44C
_080CE436:
	bl StorageGetCurrentBox
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080CE454
	ldrb r1, [r1]
	bl GetBoxedMonPtr
	movs r1, #1
	bl SetCursorMonData
_080CE44C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CE454: .4byte 0x02039A19
	thumb_func_end sub_080CE3BC

	thumb_func_start sub_080CE458
sub_080CE458: @ 0x080CE458
	push {lr}
	ldr r0, _080CE46C
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CE474
	ldr r0, _080CE470
	movs r1, #0
	bl SetCursorMonData
	b _080CE478
	.align 2, 0
_080CE46C: .4byte 0x02039A1A
_080CE470: .4byte 0x020399B4
_080CE474:
	bl sub_080CE3BC
_080CE478:
	pop {r0}
	bx r0
	thumb_func_end sub_080CE458

	thumb_func_start SetCursorMonData
SetCursorMonData: @ 0x080CE47C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r5, r1, #0
	ldr r0, _080CE4E0
	mov r8, r0
	ldr r1, [r0]
	ldr r3, _080CE4E4
	adds r2, r1, r3
	movs r0, #0
	strh r0, [r2]
	mov sb, r0
	mov sl, r0
	cmp r5, #0
	bne _080CE594
	adds r6, r4, #0
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	mov r2, r8
	ldr r1, [r2]
	ldr r3, _080CE4E8
	adds r1, r1, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CE4C0
	b _080CE6B0
_080CE4C0:
	adds r0, r4, #0
	movs r1, #4
	bl GetMonData3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	cmp r0, #0
	beq _080CE4F0
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _080CE4EC
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	b _080CE502
	.align 2, 0
_080CE4E0: .4byte 0x020399A8
_080CE4E4: .4byte 0x00000CE6
_080CE4E8: .4byte 0x00000CE4
_080CE4EC: .4byte 0x00000CED
_080CE4F0:
	adds r0, r4, #0
	movs r1, #0x2d
	bl GetMonData3
	mov r3, r8
	ldr r1, [r3]
	ldr r2, _080CE578
	adds r1, r1, r2
	strb r0, [r1]
_080CE502:
	ldr r4, _080CE57C
	ldr r2, [r4]
	ldr r5, _080CE580
	adds r2, r2, r5
	adds r0, r6, #0
	movs r1, #2
	bl GetMonData3
	ldr r0, [r4]
	adds r0, r0, r5
	bl StringGet_Nickname
	adds r0, r6, #0
	movs r1, #0x38
	bl GetMonData3
	ldr r1, [r4]
	ldr r3, _080CE584
	adds r1, r1, r3
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #8
	bl GetMonData3
	ldr r1, [r4]
	ldr r2, _080CE588
	adds r1, r1, r2
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	bl GetMonData3
	ldr r1, [r4]
	movs r3, #0xce
	lsls r3, r3, #4
	adds r1, r1, r3
	str r0, [r1]
	adds r0, r6, #0
	bl GetMonFrontSpritePal
	ldr r1, [r4]
	ldr r2, _080CE58C
	adds r1, r1, r2
	str r0, [r1]
	adds r0, r6, #0
	bl GetMonGender
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	adds r0, r6, #0
	movs r1, #0xc
	bl GetMonData3
	ldr r1, [r4]
	ldr r3, _080CE590
	adds r1, r1, r3
	strh r0, [r1]
	b _080CE6A2
	.align 2, 0
_080CE578: .4byte 0x00000CED
_080CE57C: .4byte 0x020399A8
_080CE580: .4byte 0x00000CEE
_080CE584: .4byte 0x00000CEC
_080CE588: .4byte 0x00000CEB
_080CE58C: .4byte 0x00000CDC
_080CE590: .4byte 0x00000CE6
_080CE594:
	cmp r5, #1
	beq _080CE59A
	b _080CE698
_080CE59A:
	adds r7, r4, #0
	adds r0, r7, #0
	movs r1, #0x41
	bl GetBoxMonData
	mov r2, r8
	ldr r1, [r2]
	ldr r3, _080CE5E0
	adds r1, r1, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CE5B6
	b _080CE6B0
_080CE5B6:
	adds r0, r7, #0
	movs r1, #1
	bl GetBoxMonData
	mov sb, r0
	adds r0, r7, #0
	movs r1, #4
	bl GetBoxMonData
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	cmp r0, #0
	beq _080CE5E8
	mov r1, r8
	ldr r0, [r1]
	ldr r2, _080CE5E4
	adds r0, r0, r2
	strb r5, [r0]
	b _080CE5FA
	.align 2, 0
_080CE5E0: .4byte 0x00000CE4
_080CE5E4: .4byte 0x00000CED
_080CE5E8:
	adds r0, r7, #0
	movs r1, #0x2d
	bl GetBoxMonData
	mov r3, r8
	ldr r1, [r3]
	ldr r2, _080CE67C
	adds r1, r1, r2
	strb r0, [r1]
_080CE5FA:
	ldr r5, _080CE680
	ldr r2, [r5]
	ldr r4, _080CE684
	adds r2, r2, r4
	adds r0, r7, #0
	movs r1, #2
	bl GetBoxMonData
	ldr r0, [r5]
	adds r0, r0, r4
	bl StringGet_Nickname
	adds r0, r7, #0
	bl GetLevelFromBoxMonExp
	ldr r1, [r5]
	ldr r3, _080CE688
	adds r1, r1, r3
	strb r0, [r1]
	adds r0, r7, #0
	movs r1, #8
	bl GetBoxMonData
	ldr r1, [r5]
	ldr r2, _080CE68C
	adds r1, r1, r2
	strb r0, [r1]
	adds r0, r7, #0
	movs r1, #0
	bl GetBoxMonData
	adds r2, r0, #0
	ldr r1, [r5]
	movs r6, #0xce
	lsls r6, r6, #4
	adds r0, r1, r6
	str r2, [r0]
	subs r4, #0xa
	adds r1, r1, r4
	ldrh r0, [r1]
	mov r1, sb
	bl GetMonSpritePalFromSpeciesAndPersonality
	ldr r1, [r5]
	ldr r3, _080CE690
	adds r2, r1, r3
	str r0, [r2]
	adds r4, r1, r4
	ldrh r0, [r4]
	adds r1, r1, r6
	ldr r1, [r1]
	bl GetGenderFromSpeciesAndPersonality
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	adds r0, r7, #0
	movs r1, #0xc
	bl GetBoxMonData
	ldr r1, [r5]
	ldr r2, _080CE694
	adds r1, r1, r2
	strh r0, [r1]
	b _080CE6A2
	.align 2, 0
_080CE67C: .4byte 0x00000CED
_080CE680: .4byte 0x020399A8
_080CE684: .4byte 0x00000CEE
_080CE688: .4byte 0x00000CEC
_080CE68C: .4byte 0x00000CEB
_080CE690: .4byte 0x00000CDC
_080CE694: .4byte 0x00000CE6
_080CE698:
	ldr r3, _080CE6F4
	adds r0, r1, r3
	mov r1, sb
	strh r1, [r0]
	strh r1, [r2]
_080CE6A2:
	ldr r0, _080CE6F8
	ldr r1, [r0]
	ldr r2, _080CE6F4
	adds r0, r1, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _080CE710
_080CE6B0:
	ldr r4, _080CE6F8
	ldr r0, [r4]
	ldr r3, _080CE6FC
	adds r0, r0, r3
	movs r1, #0
	movs r2, #5
	bl StringFill
	ldr r0, [r4]
	ldr r1, _080CE700
	adds r0, r0, r1
	movs r1, #0
	movs r2, #8
	bl StringFill
	ldr r0, [r4]
	ldr r2, _080CE704
	adds r0, r0, r2
	movs r1, #0
	movs r2, #8
	bl StringFill
	ldr r0, [r4]
	ldr r3, _080CE708
	adds r0, r0, r3
	movs r1, #0
	movs r2, #8
	bl StringFill
	ldr r0, [r4]
	ldr r1, _080CE70C
	adds r0, r0, r1
	b _080CE76E
	.align 2, 0
_080CE6F4: .4byte 0x00000CE4
_080CE6F8: .4byte 0x020399A8
_080CE6FC: .4byte 0x00000CEE
_080CE700: .4byte 0x00000CF9
_080CE704: .4byte 0x00000D1D
_080CE708: .4byte 0x00000D41
_080CE70C: .4byte 0x00000D65
_080CE710:
	ldr r3, _080CE734
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CE790
	mov r0, sl
	cmp r0, #0
	beq _080CE73C
	ldr r2, _080CE738
	adds r0, r1, r2
	adds r3, #1
	adds r1, r1, r3
	movs r2, #0
	movs r3, #5
	bl StringCopyPadded
	b _080CE74A
	.align 2, 0
_080CE734: .4byte 0x00000CED
_080CE738: .4byte 0x00000CF9
_080CE73C:
	ldr r2, _080CE778
	adds r0, r1, r2
	ldr r1, _080CE77C
	movs r2, #0
	movs r3, #8
	bl StringCopyPadded
_080CE74A:
	ldr r4, _080CE780
	ldr r0, [r4]
	ldr r3, _080CE784
	adds r0, r0, r3
	movs r1, #0
	movs r2, #8
	bl StringFill
	ldr r0, [r4]
	ldr r1, _080CE788
	adds r0, r0, r1
	movs r1, #0
	movs r2, #8
	bl StringFill
	ldr r0, [r4]
	ldr r2, _080CE78C
	adds r0, r0, r2
_080CE76E:
	movs r1, #0
	movs r2, #8
	bl StringFill
	b _080CE934
	.align 2, 0
_080CE778: .4byte 0x00000CF9
_080CE77C: .4byte 0x085C8C62
_080CE780: .4byte 0x020399A8
_080CE784: .4byte 0x00000D1D
_080CE788: .4byte 0x00000D41
_080CE78C: .4byte 0x00000D65
_080CE790:
	cmp r2, #0x1d
	beq _080CE798
	cmp r2, #0x20
	bne _080CE79C
_080CE798:
	movs r3, #0xff
	mov sb, r3
_080CE79C:
	ldr r4, _080CE81C
	ldr r1, [r4]
	ldr r2, _080CE820
	adds r0, r1, r2
	ldr r3, _080CE824
	adds r1, r1, r3
	movs r2, #0
	movs r3, #5
	bl StringCopyPadded
	ldr r1, [r4]
	ldr r0, _080CE828
	adds r2, r1, r0
	movs r0, #0xba
	strb r0, [r2]
	ldr r3, _080CE82C
	adds r2, r1, r3
	ldr r0, [r4]
	ldr r1, _080CE830
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, _080CE834
	adds r1, r1, r0
	adds r0, r2, #0
	movs r2, #0
	movs r3, #5
	bl StringCopyPadded
	ldr r4, [r4]
	ldr r3, _080CE838
	adds r2, r4, r3
	movs r0, #0xfc
	strb r0, [r2]
	ldr r0, _080CE83C
	adds r2, r4, r0
	movs r0, #4
	strb r0, [r2]
	ldr r1, _080CE840
	adds r2, r4, r1
	mov r3, sb
	cmp r3, #0
	beq _080CE850
	cmp r3, #0xfe
	beq _080CE87C
	movs r0, #2
	strb r0, [r2]
	ldr r0, _080CE844
	adds r2, r4, r0
	movs r0, #1
	strb r0, [r2]
	adds r1, #2
	adds r2, r4, r1
	movs r0, #3
	strb r0, [r2]
	ldr r3, _080CE848
	adds r2, r4, r3
	movs r0, #0
	strb r0, [r2]
	ldr r0, _080CE84C
	adds r2, r4, r0
	b _080CE89C
	.align 2, 0
_080CE81C: .4byte 0x020399A8
_080CE820: .4byte 0x00000CF9
_080CE824: .4byte 0x00000CEE
_080CE828: .4byte 0x00000D1D
_080CE82C: .4byte 0x00000D1E
_080CE830: .4byte 0x00000CE4
_080CE834: .4byte 0x082EA31C
_080CE838: .4byte 0x00000D41
_080CE83C: .4byte 0x00000D42
_080CE840: .4byte 0x00000D43
_080CE844: .4byte 0x00000D44
_080CE848: .4byte 0x00000D46
_080CE84C: .4byte 0x00000D47
_080CE850:
	strb r0, [r2]
	ldr r1, _080CE870
	adds r2, r4, r1
	movs r0, #1
	strb r0, [r2]
	ldr r3, _080CE874
	adds r2, r4, r3
	movs r0, #5
	strb r0, [r2]
	ldr r0, _080CE878
	adds r2, r4, r0
	movs r0, #0xb5
	strb r0, [r2]
	adds r1, #3
	adds r2, r4, r1
	b _080CE89C
	.align 2, 0
_080CE870: .4byte 0x00000D44
_080CE874: .4byte 0x00000D45
_080CE878: .4byte 0x00000D46
_080CE87C:
	movs r0, #6
	strb r0, [r2]
	ldr r3, _080CE90C
	adds r2, r4, r3
	movs r0, #1
	strb r0, [r2]
	ldr r0, _080CE910
	adds r2, r4, r0
	movs r0, #7
	strb r0, [r2]
	ldr r1, _080CE914
	adds r2, r4, r1
	movs r0, #0xb6
	strb r0, [r2]
	adds r3, #3
	adds r2, r4, r3
_080CE89C:
	movs r0, #0xfc
	strb r0, [r2]
	adds r2, #1
	movs r0, #4
	strb r0, [r2]
	adds r2, #1
	movs r0, #2
	strb r0, [r2]
	adds r2, #1
	movs r0, #1
	strb r0, [r2]
	adds r2, #1
	movs r0, #3
	strb r0, [r2]
	adds r2, #1
	movs r5, #0
	strb r5, [r2]
	adds r2, #1
	movs r0, #0xf9
	strb r0, [r2]
	adds r2, #1
	movs r0, #5
	strb r0, [r2]
	adds r2, #1
	ldr r4, _080CE918
	ldr r0, [r4]
	ldr r1, _080CE91C
	adds r0, r0, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	adds r2, r0, #0
	strb r5, [r2]
	movs r0, #0xff
	strb r0, [r2, #1]
	ldr r4, [r4]
	ldr r2, _080CE920
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080CE928
	ldr r3, _080CE924
	adds r4, r4, r3
	bl ItemId_GetName
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0
	movs r3, #8
	bl StringCopyPadded
	b _080CE934
	.align 2, 0
_080CE90C: .4byte 0x00000D44
_080CE910: .4byte 0x00000D45
_080CE914: .4byte 0x00000D46
_080CE918: .4byte 0x020399A8
_080CE91C: .4byte 0x00000CEC
_080CE920: .4byte 0x00000CE6
_080CE924: .4byte 0x00000D65
_080CE928:
	ldr r1, _080CE944
	adds r0, r4, r1
	movs r1, #0
	movs r2, #8
	bl StringFill
_080CE934:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CE944: .4byte 0x00000D65
	thumb_func_end SetCursorMonData

	thumb_func_start HandleInput_InBox
HandleInput_InBox: @ 0x080CE948
	push {lr}
	ldr r0, _080CE968
	ldr r0, [r0]
	ldr r1, _080CE96C
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080CE970
	cmp r0, #1
	ble _080CE960
	cmp r0, #2
	beq _080CE976
_080CE960:
	bl InBoxInput_Normal
	b _080CE97A
	.align 2, 0
_080CE968: .4byte 0x020399A8
_080CE96C: .4byte 0x000021FF
_080CE970:
	bl InBoxInput_GrabbingMultiple
	b _080CE97A
_080CE976:
	bl InBoxInput_MovingMultiple
_080CE97A:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end HandleInput_InBox

	thumb_func_start InBoxInput_Normal
InBoxInput_Normal: @ 0x080CE984
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _080CEA08
	ldrb r0, [r0]
	mov r8, r0
	ldr r2, _080CEA0C
	ldrb r4, [r2]
	ldr r5, _080CEA10
	ldr r0, [r5]
	ldr r1, _080CEA14
	mov sl, r1
	add r0, sl
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r5]
	ldr r7, _080CEA18
	adds r0, r0, r7
	strb r1, [r0]
	ldr r0, [r5]
	ldr r3, _080CEA1C
	mov sb, r3
	add r0, sb
	strb r1, [r0]
	ldr r6, _080CEA20
	ldrh r1, [r6, #0x30]
	movs r0, #0x40
	ands r0, r1
	adds r3, r2, #0
	cmp r0, #0
	beq _080CE9C8
	b _080CEBB8
_080CE9C8:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080CEA24
	movs r6, #1
	lsls r0, r4, #0x18
	movs r1, #0xc0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1d
	bgt _080CE9E4
	b _080CEBD4
_080CE9E4:
	movs r2, #3
	mov r8, r2
	subs r0, #0x1e
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #3
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, [r5]
	add r0, sl
	strb r6, [r0]
	ldr r0, [r5]
	add r0, sb
	strb r6, [r0]
	b _080CEBD4
	.align 2, 0
_080CEA08: .4byte 0x02039A18
_080CEA0C: .4byte 0x02039A19
_080CEA10: .4byte 0x020399A8
_080CEA14: .4byte 0x00000CD2
_080CEA18: .4byte 0x00000CD3
_080CEA1C: .4byte 0x00000CD7
_080CEA20: .4byte 0x03002360
_080CEA24:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080CEA5A
	movs r6, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	movs r1, #6
	bl __modsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CEA46
	lsls r0, r4, #0x18
	movs r3, #0xff
	lsls r3, r3, #0x18
	b _080CEBC8
_080CEA46:
	ldr r0, [r5]
	adds r0, r0, r7
	movs r1, #0xff
	strb r1, [r0]
	lsls r0, r4, #0x18
	movs r1, #0xa0
	lsls r1, r1, #0x13
	adds r0, r0, r1
	lsrs r4, r0, #0x18
	b _080CEBD4
_080CEA5A:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CEA8E
	movs r6, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r0, #1
	movs r1, #6
	bl __modsi3
	cmp r0, #0
	beq _080CEA80
	lsls r0, r4, #0x18
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r0, r0, r2
	lsrs r4, r0, #0x18
	b _080CEBD4
_080CEA80:
	ldr r0, [r5]
	adds r0, r0, r7
	strb r6, [r0]
	lsls r0, r4, #0x18
	movs r3, #0xfb
	lsls r3, r3, #0x18
	b _080CEBC8
_080CEA8E:
	ldrh r1, [r6, #0x2e]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080CEA9C
	movs r6, #1
	b _080CEBCE
_080CEA9C:
	movs r4, #1
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CEB60
	bl sub_080CF2D8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CEB60
	ldr r0, _080CEABC
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CEAC0
	movs r0, #8
	b _080CEBE2
	.align 2, 0
_080CEABC: .4byte 0x02039A1D
_080CEAC0:
	ldr r1, [r5]
	ldrb r0, [r1, #1]
	cmp r0, #2
	bne _080CEAD0
	ldr r0, _080CEAEC
	ldrb r0, [r0]
	cmp r0, #1
	bne _080CEB50
_080CEAD0:
	movs r0, #0
	bl sub_080CF814
	subs r0, #1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xe
	bhi _080CEB60
	lsls r0, r0, #2
	ldr r1, _080CEAF0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CEAEC: .4byte 0x02039A1A
_080CEAF0: .4byte 0x080CEAF4
_080CEAF4: @ jump table
	.4byte _080CEB30 @ case 0
	.4byte _080CEB34 @ case 1
	.4byte _080CEB38 @ case 2
	.4byte _080CEB3C @ case 3
	.4byte _080CEB40 @ case 4
	.4byte _080CEB60 @ case 5
	.4byte _080CEB60 @ case 6
	.4byte _080CEB60 @ case 7
	.4byte _080CEB60 @ case 8
	.4byte _080CEB60 @ case 9
	.4byte _080CEB60 @ case 10
	.4byte _080CEB44 @ case 11
	.4byte _080CEB48 @ case 12
	.4byte _080CEB60 @ case 13
	.4byte _080CEB4C @ case 14
_080CEB30:
	movs r0, #0xb
	b _080CEBE2
_080CEB34:
	movs r0, #0xc
	b _080CEBE2
_080CEB38:
	movs r0, #0xd
	b _080CEBE2
_080CEB3C:
	movs r0, #0xe
	b _080CEBE2
_080CEB40:
	movs r0, #0xf
	b _080CEBE2
_080CEB44:
	movs r0, #0x10
	b _080CEBE2
_080CEB48:
	movs r0, #0x11
	b _080CEBE2
_080CEB4C:
	movs r0, #0x12
	b _080CEBE2
_080CEB50:
	ldr r2, _080CEB5C
	adds r0, r1, r2
	strb r4, [r0]
	movs r0, #0x14
	b _080CEBE2
	.align 2, 0
_080CEB5C: .4byte 0x000021FF
_080CEB60:
	ldr r2, _080CEB70
	ldrh r1, [r2, #0x2e]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CEB74
	movs r0, #0x13
	b _080CEBE2
	.align 2, 0
_080CEB70: .4byte 0x03002360
_080CEB74:
	ldr r0, _080CEB90
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	cmp r0, #1
	bne _080CEBA2
	ldrh r1, [r2, #0x2c]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CEB94
	movs r0, #0xa
	b _080CEBE2
	.align 2, 0
_080CEB90: .4byte 0x03005AF0
_080CEB94:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CEBA2
	movs r0, #9
	b _080CEBE2
_080CEBA2:
	ldrh r1, [r2, #0x2e]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080CEBB4
	bl sub_080CF640
	movs r0, #0
	b _080CEBE2
_080CEBB4:
	movs r6, #0
	b _080CEBE0
_080CEBB8:
	movs r6, #1
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #5
	ble _080CEBCE
	lsls r0, r4, #0x18
	movs r3, #0xfa
	lsls r3, r3, #0x18
_080CEBC8:
	adds r0, r0, r3
	lsrs r4, r0, #0x18
	b _080CEBD4
_080CEBCE:
	movs r0, #2
	mov r8, r0
	movs r4, #0
_080CEBD4:
	cmp r6, #0
	beq _080CEBE0
	mov r0, r8
	adds r1, r4, #0
	bl sub_080CD110
_080CEBE0:
	adds r0, r6, #0
_080CEBE2:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end InBoxInput_Normal

	thumb_func_start InBoxInput_GrabbingMultiple
InBoxInput_GrabbingMultiple: @ 0x080CEBF0
	push {r4, lr}
	ldr r1, _080CEC20
	ldrh r0, [r1, #0x2c]
	movs r4, #1
	ands r4, r0
	cmp r4, #0
	beq _080CECA4
	ldrh r1, [r1, #0x30]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080CEC28
	ldr r4, _080CEC24
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #6
	bl __divsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CEC9C
	ldrb r1, [r4]
	subs r1, #6
	b _080CEC8A
	.align 2, 0
_080CEC20: .4byte 0x03002360
_080CEC24: .4byte 0x02039A19
_080CEC28:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080CEC48
	ldr r1, _080CEC44
	movs r0, #0
	ldrsb r0, [r1, r0]
	adds r0, #6
	cmp r0, #0x1d
	bgt _080CEC9C
	ldrb r1, [r1]
	adds r1, #6
	b _080CEC8A
	.align 2, 0
_080CEC44: .4byte 0x02039A19
_080CEC48:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080CEC6C
	ldr r4, _080CEC68
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #6
	bl __modsi3
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CEC9C
	ldrb r1, [r4]
	subs r1, #1
	b _080CEC8A
	.align 2, 0
_080CEC68: .4byte 0x02039A19
_080CEC6C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CECA0
	ldr r4, _080CEC98
	movs r0, #0
	ldrsb r0, [r4, r0]
	adds r0, #1
	movs r1, #6
	bl __modsi3
	cmp r0, #0
	beq _080CEC9C
	ldrb r1, [r4]
	adds r1, #1
_080CEC8A:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0
	bl sub_080CD110
	movs r0, #0x15
	b _080CED18
	.align 2, 0
_080CEC98: .4byte 0x02039A19
_080CEC9C:
	movs r0, #0x18
	b _080CED18
_080CECA0:
	movs r0, #0
	b _080CED18
_080CECA4:
	bl sub_080D0444
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080CECE0
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	cmp r0, r1
	beq _080CECF8
	ldr r2, _080CECE4
	ldr r0, _080CECE8
	ldr r1, [r0]
	ldr r3, _080CECEC
	adds r0, r1, r3
	ldrh r0, [r0]
	rsbs r0, r0, #0
	lsrs r0, r0, #0x1f
	strb r0, [r2]
	ldr r0, _080CECF0
	adds r1, r1, r0
	movs r0, #2
	strb r0, [r1]
	bl StorageGetCurrentBox
	ldr r1, _080CECF4
	strb r0, [r1]
	movs r0, #0x17
	b _080CED18
	.align 2, 0
_080CECE0: .4byte 0x02039A19
_080CECE4: .4byte 0x02039A1A
_080CECE8: .4byte 0x020399A8
_080CECEC: .4byte 0x00000CE4
_080CECF0: .4byte 0x000021FF
_080CECF4: .4byte 0x02039A1B
_080CECF8:
	ldr r1, _080CED20
	ldr r0, [r1]
	ldr r2, _080CED24
	adds r0, r0, r2
	strb r4, [r0]
	ldr r0, [r1]
	ldr r3, _080CED28
	adds r0, r0, r3
	ldr r1, [r0]
	adds r1, #0x3e
	ldrb r2, [r1]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	movs r0, #0x16
_080CED18:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080CED20: .4byte 0x020399A8
_080CED24: .4byte 0x000021FF
_080CED28: .4byte 0x00000CB8
	thumb_func_end InBoxInput_GrabbingMultiple

	thumb_func_start InBoxInput_MovingMultiple
InBoxInput_MovingMultiple: @ 0x080CED2C
	push {r4, lr}
	ldr r2, _080CED50
	ldrh r1, [r2, #0x30]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080CED58
	movs r0, #0
	bl sub_080CFE20
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CEE04
	ldr r0, _080CED54
	ldrb r1, [r0]
	subs r1, #6
	b _080CEDB6
	.align 2, 0
_080CED50: .4byte 0x03002360
_080CED54: .4byte 0x02039A19
_080CED58:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080CED78
	movs r0, #1
	bl sub_080CFE20
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CEE04
	ldr r0, _080CED74
	ldrb r1, [r0]
	adds r1, #6
	b _080CEDB6
	.align 2, 0
_080CED74: .4byte 0x02039A19
_080CED78:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080CED98
	movs r0, #2
	bl sub_080CFE20
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CEE1E
	ldr r0, _080CED94
	ldrb r1, [r0]
	subs r1, #1
	b _080CEDB6
	.align 2, 0
_080CED94: .4byte 0x02039A19
_080CED98:
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080CEDC8
	movs r0, #3
	bl sub_080CFE20
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CEE32
	ldr r0, _080CEDC4
	ldrb r1, [r0]
	adds r1, #1
_080CEDB6:
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r0, #0
	bl sub_080CD110
	movs r0, #0x19
	b _080CEE38
	.align 2, 0
_080CEDC4: .4byte 0x02039A19
_080CEDC8:
	ldrh r1, [r2, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CEDFC
	bl sub_080D0460
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CEE04
	ldr r0, _080CEDF0
	strb r4, [r0]
	ldr r0, _080CEDF4
	ldr r0, [r0]
	ldr r1, _080CEDF8
	adds r0, r0, r1
	strb r4, [r0]
	movs r0, #0x1a
	b _080CEE38
	.align 2, 0
_080CEDF0: .4byte 0x02039A1A
_080CEDF4: .4byte 0x020399A8
_080CEDF8: .4byte 0x000021FF
_080CEDFC:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CEE08
_080CEE04:
	movs r0, #0x18
	b _080CEE38
_080CEE08:
	ldr r0, _080CEE24
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	cmp r0, #1
	bne _080CEE36
	ldrh r1, [r2, #0x2c]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CEE28
_080CEE1E:
	movs r0, #0xa
	b _080CEE38
	.align 2, 0
_080CEE24: .4byte 0x03005AF0
_080CEE28:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CEE36
_080CEE32:
	movs r0, #9
	b _080CEE38
_080CEE36:
	movs r0, #0
_080CEE38:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end InBoxInput_MovingMultiple

	thumb_func_start HandleInput_InParty
HandleInput_InParty: @ 0x080CEE40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _080CEEB0
	ldrb r0, [r0]
	mov sb, r0
	ldr r6, _080CEEB4
	ldrb r4, [r6]
	ldr r2, _080CEEB8
	ldr r0, [r2]
	ldr r1, _080CEEBC
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _080CEEC0
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, #5
	adds r0, r0, r3
	strb r1, [r0]
	mov r8, r1
	movs r7, #0
	ldr r1, _080CEEC4
	ldrh r3, [r1, #0x30]
	movs r0, #0x40
	ands r0, r3
	adds r5, r6, #0
	mov ip, r1
	cmp r0, #0
	beq _080CEE84
	b _080CF024
_080CEE84:
	movs r0, #0x80
	ands r0, r3
	cmp r0, #0
	beq _080CEEC8
	lsls r0, r4, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r4, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #6
	ble _080CEE9E
	movs r4, #0
_080CEE9E:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r5, r1]
	cmp r0, r1
	bne _080CEEAC
	b _080CF042
_080CEEAC:
	movs r7, #1
	b _080CF046
	.align 2, 0
_080CEEB0: .4byte 0x02039A18
_080CEEB4: .4byte 0x02039A19
_080CEEB8: .4byte 0x020399A8
_080CEEBC: .4byte 0x00000CD3
_080CEEC0: .4byte 0x00000CD2
_080CEEC4: .4byte 0x03002360
_080CEEC8:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _080CEEEC
	ldrb r1, [r5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	beq _080CEEEC
	movs r7, #1
	ldr r0, [r2]
	ldr r2, _080CEEE8
	adds r0, r0, r2
	strb r1, [r0]
	movs r4, #0
	b _080CF042
	.align 2, 0
_080CEEE8: .4byte 0x00000CD6
_080CEEEC:
	mov r3, ip
	ldrh r1, [r3, #0x30]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CEF1A
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	bne _080CEF10
	movs r7, #1
	ldr r0, [r2]
	ldr r1, _080CEF0C
	adds r0, r0, r1
	ldrb r4, [r0]
	b _080CF042
	.align 2, 0
_080CEF0C: .4byte 0x00000CD6
_080CEF10:
	movs r7, #6
	movs r2, #0
	mov sb, r2
	movs r4, #0
	b _080CF042
_080CEF1A:
	mov r3, ip
	ldrh r1, [r3, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CEFD8
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #6
	bne _080CEF40
	ldr r0, [r2]
	ldrb r0, [r0, #1]
	cmp r0, #1
	bne _080CEF3A
	movs r0, #4
	b _080CF054
_080CEF3A:
	movs r0, #1
	mov r8, r0
	b _080CEFD8
_080CEF40:
	bl sub_080CF2D8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080CEFD8
	ldr r0, _080CEF58
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CEF5C
	movs r0, #8
	b _080CF054
	.align 2, 0
_080CEF58: .4byte 0x02039A1D
_080CEF5C:
	movs r0, #0
	bl sub_080CF814
	subs r0, #1
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xe
	bhi _080CEFD8
	lsls r0, r0, #2
	ldr r1, _080CEF78
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CEF78: .4byte 0x080CEF7C
_080CEF7C: @ jump table
	.4byte _080CEFB8 @ case 0
	.4byte _080CEFBC @ case 1
	.4byte _080CEFC0 @ case 2
	.4byte _080CEFC4 @ case 3
	.4byte _080CEFC8 @ case 4
	.4byte _080CEFD8 @ case 5
	.4byte _080CEFD8 @ case 6
	.4byte _080CEFD8 @ case 7
	.4byte _080CEFD8 @ case 8
	.4byte _080CEFD8 @ case 9
	.4byte _080CEFD8 @ case 10
	.4byte _080CEFCC @ case 11
	.4byte _080CEFD0 @ case 12
	.4byte _080CEFD8 @ case 13
	.4byte _080CEFD4 @ case 14
_080CEFB8:
	movs r0, #0xb
	b _080CF054
_080CEFBC:
	movs r0, #0xc
	b _080CF054
_080CEFC0:
	movs r0, #0xd
	b _080CF054
_080CEFC4:
	movs r0, #0xe
	b _080CF054
_080CEFC8:
	movs r0, #0xf
	b _080CF054
_080CEFCC:
	movs r0, #0x10
	b _080CF054
_080CEFD0:
	movs r0, #0x11
	b _080CF054
_080CEFD4:
	movs r0, #0x12
	b _080CF054
_080CEFD8:
	ldr r2, _080CEFF4
	ldrh r1, [r2, #0x2e]
	movs r0, #2
	ands r0, r1
	mov ip, r2
	cmp r0, #0
	beq _080CF000
	ldr r0, _080CEFF8
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #1
	bne _080CEFFC
	movs r0, #0x13
	b _080CF054
	.align 2, 0
_080CEFF4: .4byte 0x03002360
_080CEFF8: .4byte 0x020399A8
_080CEFFC:
	movs r1, #1
	mov r8, r1
_080CF000:
	mov r2, r8
	cmp r2, #0
	beq _080CF010
	movs r7, #6
	movs r3, #0
	mov sb, r3
	movs r4, #0
	b _080CF042
_080CF010:
	mov r0, ip
	ldrh r1, [r0, #0x2e]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080CF042
	bl sub_080CF640
	movs r0, #0
	b _080CF054
_080CF024:
	lsls r0, r4, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r4, r0, #0x18
	cmp r0, #0
	bge _080CF034
	movs r4, #6
_080CF034:
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	movs r1, #0
	ldrsb r1, [r6, r1]
	cmp r0, r1
	beq _080CF042
	movs r7, #1
_080CF042:
	cmp r7, #0
	beq _080CF052
_080CF046:
	cmp r7, #6
	beq _080CF052
	mov r0, sb
	adds r1, r4, #0
	bl sub_080CD110
_080CF052:
	adds r0, r7, #0
_080CF054:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end HandleInput_InParty

	thumb_func_start HandleInput_OnBox
HandleInput_OnBox: @ 0x080CF060
	push {r4, r5, r6, lr}
	ldr r3, _080CF09C
	ldr r0, [r3]
	ldr r1, _080CF0A0
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r3]
	ldr r2, _080CF0A4
	adds r0, r0, r2
	strb r1, [r0]
	ldr r0, [r3]
	ldr r5, _080CF0A8
	adds r0, r0, r5
	strb r1, [r0]
	ldr r1, _080CF0AC
	ldrh r2, [r1, #0x30]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	bne _080CF126
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _080CF0B0
	movs r4, #1
	movs r1, #0
	movs r6, #2
	b _080CF132
	.align 2, 0
_080CF09C: .4byte 0x020399A8
_080CF0A0: .4byte 0x00000CD3
_080CF0A4: .4byte 0x00000CD2
_080CF0A8: .4byte 0x00000CD7
_080CF0AC: .4byte 0x03002360
_080CF0B0:
	ldrh r2, [r1, #0x2c]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _080CF0D6
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _080CF0EA
	ldr r0, _080CF0DC
	ldr r0, [r0]
	ldrb r0, [r0, #0x13]
	cmp r0, #1
	bne _080CF0EE
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080CF0E0
_080CF0D6:
	movs r0, #0xa
	b _080CF14E
	.align 2, 0
_080CF0DC: .4byte 0x03005AF0
_080CF0E0:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080CF0EE
_080CF0EA:
	movs r0, #9
	b _080CF14E
_080CF0EE:
	ldrh r1, [r1, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CF106
	movs r0, #0
	bl sub_080CCA24
	bl AddBoxMenu
	movs r0, #7
	b _080CF14E
_080CF106:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CF112
	movs r0, #0x13
	b _080CF14E
_080CF112:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080CF122
	bl sub_080CF640
	movs r0, #0
	b _080CF14E
_080CF122:
	movs r4, #0
	b _080CF14C
_080CF126:
	movs r4, #1
	movs r1, #3
	movs r6, #0
	ldr r0, [r3]
	adds r0, r0, r5
	strb r4, [r0]
_080CF132:
	cmp r4, #0
	beq _080CF14C
	lsls r5, r1, #0x18
	cmp r1, #2
	beq _080CF142
	movs r0, #0
	bl sub_080CCA24
_080CF142:
	lsrs r0, r5, #0x18
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl sub_080CD110
_080CF14C:
	adds r0, r4, #0
_080CF14E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end HandleInput_OnBox

	thumb_func_start HandleInput_OnButtons
HandleInput_OnButtons: @ 0x080CF154
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _080CF1A4
	ldrb r0, [r0]
	mov r8, r0
	ldr r0, _080CF1A8
	mov ip, r0
	ldrb r2, [r0]
	ldr r3, _080CF1AC
	ldr r0, [r3]
	ldr r1, _080CF1B0
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r3]
	ldr r6, _080CF1B4
	adds r0, r0, r6
	strb r1, [r0]
	ldr r0, [r3]
	ldr r5, _080CF1B8
	adds r0, r0, r5
	strb r1, [r0]
	ldr r7, _080CF1BC
	ldrh r1, [r7, #0x30]
	movs r0, #0x40
	ands r0, r1
	adds r4, r3, #0
	cmp r0, #0
	bne _080CF22E
	movs r0, #0x88
	ands r0, r1
	cmp r0, #0
	beq _080CF1C0
	movs r7, #1
	movs r0, #2
	mov r8, r0
	movs r2, #0
	ldr r0, [r4]
	b _080CF24C
	.align 2, 0
_080CF1A4: .4byte 0x02039A18
_080CF1A8: .4byte 0x02039A19
_080CF1AC: .4byte 0x020399A8
_080CF1B0: .4byte 0x00000CD3
_080CF1B4: .4byte 0x00000CD2
_080CF1B8: .4byte 0x00000CD7
_080CF1BC: .4byte 0x03002360
_080CF1C0:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080CF1DC
	movs r7, #1
	lsls r0, r2, #0x18
	movs r1, #0xff
	lsls r1, r1, #0x18
	adds r0, r0, r1
	lsrs r2, r0, #0x18
	cmp r0, #0
	bge _080CF250
	movs r2, #1
	b _080CF250
_080CF1DC:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CF1FA
	movs r7, #1
	lsls r0, r2, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	adds r0, r0, r1
	lsrs r2, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	ble _080CF250
	movs r2, #0
	b _080CF250
_080CF1FA:
	ldrh r1, [r7, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CF20E
	movs r0, #4
	cmp r2, #0
	bne _080CF25E
	movs r0, #5
	b _080CF25E
_080CF20E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CF21A
	movs r0, #0x13
	b _080CF25E
_080CF21A:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080CF22A
	bl sub_080CF640
	movs r0, #0
	b _080CF25E
_080CF22A:
	movs r7, #0
	b _080CF25C
_080CF22E:
	movs r7, #1
	movs r0, #0
	mov r8, r0
	ldr r0, [r3]
	adds r0, r0, r6
	movs r1, #0xff
	strb r1, [r0]
	mov r1, ip
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r2, #0x1d
	cmp r0, #0
	bne _080CF24A
	movs r2, #0x18
_080CF24A:
	ldr r0, [r3]
_080CF24C:
	adds r0, r0, r5
	strb r7, [r0]
_080CF250:
	cmp r7, #0
	beq _080CF25C
	mov r0, r8
	adds r1, r2, #0
	bl sub_080CD110
_080CF25C:
	adds r0, r7, #0
_080CF25E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end HandleInput_OnButtons

	thumb_func_start sub_080CF268
sub_080CF268: @ 0x080CF268
	push {r4, r5, lr}
	movs r3, #0
	ldr r0, _080CF294
	ldr r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	beq _080CF2AC
	ldr r5, _080CF298
_080CF278:
	lsls r0, r3, #3
	adds r2, r0, r4
	movs r1, #4
	ldrsb r1, [r2, r1]
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r1, r0
	bne _080CF29C
	ldr r0, [r2]
	bl _call_via_r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080CF2AE
	.align 2, 0
_080CF294: .4byte 0x085564B8
_080CF298: .4byte 0x02039A18
_080CF29C:
	adds r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	lsls r0, r3, #3
	adds r0, r0, r4
	ldr r0, [r0]
	cmp r0, #0
	bne _080CF278
_080CF2AC:
	movs r0, #0
_080CF2AE:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_080CF268

	thumb_func_start AddBoxMenu
AddBoxMenu: @ 0x080CF2B4
	push {lr}
	bl InitMenu
	movs r0, #9
	bl SetMenuText
	movs r0, #0xa
	bl SetMenuText
	movs r0, #0xb
	bl SetMenuText
	movs r0, #0
	bl SetMenuText
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end AddBoxMenu

	thumb_func_start sub_080CF2D8
sub_080CF2D8: @ 0x080CF2D8
	push {lr}
	bl InitMenu
	ldr r0, _080CF2F0
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #3
	bne _080CF2F4
	bl sub_080CF3C0
	b _080CF2F8
	.align 2, 0
_080CF2F0: .4byte 0x020399A8
_080CF2F4:
	bl sub_080CF300
_080CF2F8:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	thumb_func_end sub_080CF2D8

	thumb_func_start sub_080CF300
sub_080CF300: @ 0x080CF300
	push {lr}
	bl sub_080CCD80
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	ldr r0, _080CF320
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _080CF32A
	cmp r0, #1
	bgt _080CF324
	cmp r0, #0
	beq _080CF336
	b _080CF370
	.align 2, 0
_080CF320: .4byte 0x020399A8
_080CF324:
	cmp r0, #2
	beq _080CF342
	b _080CF370
_080CF32A:
	cmp r1, #0
	beq _080CF370
	movs r0, #1
	bl SetMenuText
	b _080CF374
_080CF336:
	cmp r1, #0
	beq _080CF370
	movs r0, #2
	bl SetMenuText
	b _080CF374
_080CF342:
	ldr r0, _080CF358
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CF364
	cmp r1, #0
	beq _080CF35C
	movs r0, #4
	bl SetMenuText
	b _080CF374
	.align 2, 0
_080CF358: .4byte 0x02039A1A
_080CF35C:
	movs r0, #5
	bl SetMenuText
	b _080CF374
_080CF364:
	cmp r1, #0
	beq _080CF370
	movs r0, #3
	bl SetMenuText
	b _080CF374
_080CF370:
	movs r0, #0
	b _080CF3BA
_080CF374:
	movs r0, #6
	bl SetMenuText
	ldr r0, _080CF398
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #2
	bne _080CF3A6
	ldr r0, _080CF39C
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080CF3A0
	movs r0, #2
	bl SetMenuText
	b _080CF3A6
	.align 2, 0
_080CF398: .4byte 0x020399A8
_080CF39C: .4byte 0x02039A18
_080CF3A0:
	movs r0, #1
	bl SetMenuText
_080CF3A6:
	movs r0, #8
	bl SetMenuText
	movs r0, #7
	bl SetMenuText
	movs r0, #0
	bl SetMenuText
	movs r0, #1
_080CF3BA:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080CF300

	thumb_func_start sub_080CF3C0
sub_080CF3C0: @ 0x080CF3C0
	push {r4, r5, lr}
	ldr r4, _080CF3FC
	ldr r0, [r4]
	ldr r5, _080CF400
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r1, r0
	beq _080CF456
	bl IsActiveItemMoving
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CF428
	ldr r2, [r4]
	ldr r0, _080CF404
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _080CF408
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _080CF456
	movs r0, #0xe
	bl SetMenuText
	b _080CF460
	.align 2, 0
_080CF3FC: .4byte 0x020399A8
_080CF400: .4byte 0x00000CE4
_080CF404: .4byte 0x00000CE6
_080CF408:
	ldrh r0, [r1]
	bl ItemIsMail
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CF420
	movs r0, #0xc
	bl SetMenuText
	movs r0, #0x10
	bl SetMenuText
_080CF420:
	movs r0, #0x11
	bl SetMenuText
	b _080CF460
_080CF428:
	ldr r2, [r4]
	ldr r0, _080CF444
	adds r1, r2, r0
	ldrh r0, [r1]
	cmp r0, #0
	bne _080CF448
	adds r0, r2, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _080CF456
	movs r0, #0xd
	bl SetMenuText
	b _080CF460
	.align 2, 0
_080CF444: .4byte 0x00000CE6
_080CF448:
	ldrh r0, [r1]
	bl ItemIsMail
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080CF45A
_080CF456:
	movs r0, #0
	b _080CF468
_080CF45A:
	movs r0, #0xf
	bl SetMenuText
_080CF460:
	movs r0, #0
	bl SetMenuText
	movs r0, #1
_080CF468:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080CF3C0

	thumb_func_start sub_080CF470
sub_080CF470: @ 0x080CF470
	ldr r1, _080CF488
	ldr r1, [r1]
	ldr r2, _080CF48C
	adds r1, r1, r2
	ldr r2, [r1]
	ldrh r2, [r2, #0x20]
	strh r2, [r0, #0x20]
	ldr r1, [r1]
	ldrh r1, [r1, #0x22]
	adds r1, #0x14
	strh r1, [r0, #0x22]
	bx lr
	.align 2, 0
_080CF488: .4byte 0x020399A8
_080CF48C: .4byte 0x00000CB4
	thumb_func_end sub_080CF470

	thumb_func_start sub_080CF490
sub_080CF490: @ 0x080CF490
	push {r4, r5, r6, lr}
	sub sp, #0x2c
	mov r1, sp
	ldr r0, _080CF55C
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	add r4, sp, #0x18
	adds r1, r4, #0
	ldr r0, _080CF560
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r0]
	str r0, [r1]
	mov r0, sp
	bl LoadSpriteSheets
	adds r0, r4, #0
	bl LoadSpritePalettes
	ldr r0, _080CF564
	bl IndexOfSpritePaletteTag
	ldr r6, _080CF568
	ldr r1, [r6]
	ldr r4, _080CF56C
	adds r1, r1, r4
	strb r0, [r1]
	ldr r0, _080CF570
	bl IndexOfSpritePaletteTag
	ldr r1, [r6]
	ldr r5, _080CF574
	adds r1, r1, r5
	strb r0, [r1]
	ldr r0, _080CF578
	ldrb r0, [r0]
	ldr r1, _080CF57C
	ldrb r1, [r1]
	add r4, sp, #0x28
	mov r5, sp
	adds r5, #0x2a
	adds r2, r4, #0
	adds r3, r5, #0
	bl sub_080CCCC0
	ldr r0, _080CF580
	movs r2, #0
	ldrsh r1, [r4, r2]
	movs r3, #0
	ldrsh r2, [r5, r3]
	movs r3, #6
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	beq _080CF594
	ldr r2, [r6]
	ldr r4, _080CF584
	adds r3, r2, r4
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _080CF588
	adds r1, r1, r0
	str r1, [r3]
	ldr r0, _080CF58C
	ldr r5, _080CF56C
	adds r2, r2, r5
	ldrb r0, [r0]
	adds r2, r2, r0
	ldrb r2, [r2]
	lsls r2, r2, #4
	ldrb r3, [r1, #5]
	movs r0, #0xf
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #5]
	ldr r0, [r6]
	adds r0, r0, r4
	ldr r2, [r0]
	ldrb r1, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	ldr r0, _080CF590
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CF59E
	ldr r0, [r6]
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #3
	bl StartSpriteAnim
	b _080CF59E
	.align 2, 0
_080CF55C: .4byte 0x085564E0
_080CF560: .4byte 0x085564F8
_080CF564: .4byte 0x0000DACA
_080CF568: .4byte 0x020399A8
_080CF56C: .4byte 0x00000CD8
_080CF570: .4byte 0x0000DAC7
_080CF574: .4byte 0x00000CD9
_080CF578: .4byte 0x02039A18
_080CF57C: .4byte 0x02039A19
_080CF580: .4byte 0x0855654C
_080CF584: .4byte 0x00000CB4
_080CF588: .4byte 0x020205AC
_080CF58C: .4byte 0x02039A1D
_080CF590: .4byte 0x02039A1A
_080CF594:
	ldr r0, [r6]
	ldr r1, _080CF5B0
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
_080CF59E:
	ldr r0, _080CF5B4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080CF5B8
	movs r3, #0xd
	movs r4, #1
	b _080CF5BC
	.align 2, 0
_080CF5B0: .4byte 0x00000CB4
_080CF5B4: .4byte 0x02039A18
_080CF5B8:
	movs r3, #0x15
	movs r4, #2
_080CF5BC:
	ldr r0, _080CF610
	movs r1, #0
	movs r2, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x40
	beq _080CF624
	ldr r5, _080CF614
	ldr r2, [r5]
	ldr r3, _080CF618
	adds r2, r2, r3
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _080CF61C
	adds r1, r1, r0
	str r1, [r2]
	lsls r3, r4, #2
	ldrb r2, [r1, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r3
	strb r0, [r1, #5]
	ldr r0, _080CF620
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080CF630
	ldr r0, [r5]
	ldr r4, _080CF618
	adds r0, r0, r4
	ldr r1, [r0]
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	b _080CF630
	.align 2, 0
_080CF610: .4byte 0x08556564
_080CF614: .4byte 0x020399A8
_080CF618: .4byte 0x00000CB8
_080CF61C: .4byte 0x020205AC
_080CF620: .4byte 0x02039A18
_080CF624:
	ldr r0, _080CF638
	ldr r0, [r0]
	ldr r5, _080CF63C
	adds r0, r0, r5
	movs r1, #0
	str r1, [r0]
_080CF630:
	add sp, #0x2c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF638: .4byte 0x020399A8
_080CF63C: .4byte 0x00000CB8
	thumb_func_end sub_080CF490

	thumb_func_start sub_080CF640
sub_080CF640: @ 0x080CF640
	push {lr}
	ldr r2, _080CF674
	movs r1, #0
	ldrb r0, [r2]
	cmp r0, #0
	bne _080CF64E
	movs r1, #1
_080CF64E:
	strb r1, [r2]
	ldr r0, _080CF678
	ldr r0, [r0]
	ldr r3, _080CF67C
	adds r1, r0, r3
	ldr r3, [r1]
	ldr r1, _080CF680
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	ldrb r1, [r0]
	lsls r1, r1, #4
	ldrb r2, [r3, #5]
	movs r0, #0xf
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	pop {r0}
	bx r0
	.align 2, 0
_080CF674: .4byte 0x02039A1D
_080CF678: .4byte 0x020399A8
_080CF67C: .4byte 0x00000CB4
_080CF680: .4byte 0x00000CD8
	thumb_func_end sub_080CF640

	thumb_func_start sub_080CF684
sub_080CF684: @ 0x080CF684
	ldr r0, _080CF68C
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080CF68C: .4byte 0x02039A19
	thumb_func_end sub_080CF684

	thumb_func_start sub_080CF690
sub_080CF690: @ 0x080CF690
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080CF6BC
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080CF6C4
	ldr r4, _080CF6C0
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #6
	bl __modsi3
	strb r0, [r5]
	movs r0, #0
	ldrsb r0, [r4, r0]
	movs r1, #6
	bl __divsi3
	b _080CF6C8
	.align 2, 0
_080CF6BC: .4byte 0x02039A18
_080CF6C0: .4byte 0x02039A19
_080CF6C4:
	movs r0, #0
	strb r0, [r5]
_080CF6C8:
	strb r0, [r6]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end sub_080CF690

	thumb_func_start sub_080CF6D0
sub_080CF6D0: @ 0x080CF6D0
	push {lr}
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _080CF6EC
	ldr r0, [r0]
	ldr r2, _080CF6F0
	adds r0, r0, r2
	ldr r0, [r0]
	bl StartSpriteAnim
	pop {r0}
	bx r0
	.align 2, 0
_080CF6EC: .4byte 0x020399A8
_080CF6F0: .4byte 0x00000CB4
	thumb_func_end sub_080CF6D0

	thumb_func_start sub_080CF6F4
sub_080CF6F4: @ 0x080CF6F4
	ldr r0, _080CF6FC
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080CF6FC: .4byte 0x02039A1B
	thumb_func_end sub_080CF6F4

	thumb_func_start sub_080CF700
sub_080CF700: @ 0x080CF700
	ldr r0, _080CF71C
	ldr r0, [r0]
	ldr r1, _080CF720
	adds r0, r0, r1
	ldr r2, [r0]
	ldrb r1, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
	bx lr
	.align 2, 0
_080CF71C: .4byte 0x020399A8
_080CF720: .4byte 0x00000CB4
	thumb_func_end sub_080CF700

	thumb_func_start sub_080CF724
sub_080CF724: @ 0x080CF724
	push {lr}
	ldr r0, _080CF740
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080CF73C
	ldr r0, _080CF744
	ldrb r1, [r0]
	movs r0, #0
	bl sub_080D06F0
_080CF73C:
	pop {r0}
	bx r0
	.align 2, 0
_080CF740: .4byte 0x02039A18
_080CF744: .4byte 0x02039A19
	thumb_func_end sub_080CF724

	thumb_func_start sub_080CF748
sub_080CF748: @ 0x080CF748
	push {lr}
	ldr r0, _080CF764
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bne _080CF760
	ldr r0, _080CF768
	ldrb r1, [r0]
	movs r0, #0
	bl sub_080D062C
_080CF760:
	pop {r0}
	bx r0
	.align 2, 0
_080CF764: .4byte 0x02039A18
_080CF768: .4byte 0x02039A19
	thumb_func_end sub_080CF748

	thumb_func_start InitMenu
InitMenu: @ 0x080CF76C
	ldr r2, _080CF7A0
	ldr r0, [r2]
	ldr r1, _080CF7A4
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _080CF7A8
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	subs r3, #0x41
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	ldr r1, _080CF7AC
	adds r0, r0, r1
	movs r1, #0xf
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, #6
	adds r0, r0, r3
	movs r1, #0x5c
	strh r1, [r0]
	bx lr
	.align 2, 0
_080CF7A0: .4byte 0x020399A8
_080CF7A4: .4byte 0x00000CAC
_080CF7A8: .4byte 0x00000CAD
_080CF7AC: .4byte 0x00000C71
	thumb_func_end InitMenu

	thumb_func_start SetMenuText
SetMenuText: @ 0x080CF7B0
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r4, _080CF800
	ldr r2, [r4]
	ldr r5, _080CF804
	adds r1, r2, r5
	ldrb r0, [r1]
	cmp r0, #6
	bhi _080CF7FA
	adds r1, r0, #0
	lsls r1, r1, #3
	ldr r0, _080CF808
	adds r1, r1, r0
	adds r1, r2, r1
	ldr r2, _080CF80C
	lsls r0, r3, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r1]
	str r3, [r1, #4]
	bl StringLength
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r0, [r4]
	ldr r2, _080CF810
	adds r0, r0, r2
	ldrb r2, [r0]
	cmp r1, r2
	bls _080CF7F0
	strb r1, [r0]
_080CF7F0:
	ldr r1, [r4]
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080CF7FA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF800: .4byte 0x020399A8
_080CF804: .4byte 0x00000CAC
_080CF808: .4byte 0x00000C74
_080CF80C: .4byte 0x0855657C
_080CF810: .4byte 0x00000CAD
	thumb_func_end SetMenuText

	thumb_func_start sub_080CF814
sub_080CF814: @ 0x080CF814
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _080CF838
	ldr r1, [r0]
	ldr r3, _080CF83C
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r2, r0
	bhs _080CF844
	lsls r0, r2, #3
	ldr r2, _080CF840
	adds r1, r1, r2
	adds r1, r1, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	b _080CF848
	.align 2, 0
_080CF838: .4byte 0x020399A8
_080CF83C: .4byte 0x00000CAC
_080CF840: .4byte 0x00000C78
_080CF844:
	movs r0, #1
	rsbs r0, r0, #0
_080CF848:
	pop {r1}
	bx r1
	thumb_func_end sub_080CF814

	thumb_func_start AddMenu
AddMenu: @ 0x080CF84C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0xc
	ldr r5, _080CF928
	ldr r1, [r5]
	ldr r2, _080CF92C
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r0, #2
	subs r2, #0x3e
	adds r1, r1, r2
	movs r3, #0
	mov sb, r3
	strb r0, [r1]
	ldr r1, [r5]
	ldr r6, _080CF930
	adds r0, r1, r6
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r3, #0xc7
	lsls r3, r3, #4
	adds r1, r1, r3
	strb r0, [r1]
	ldr r1, [r5]
	adds r2, r1, r2
	ldrb r2, [r2]
	movs r0, #0x1d
	subs r0, r0, r2
	ldr r2, _080CF934
	adds r1, r1, r2
	strb r0, [r1]
	ldr r1, [r5]
	adds r3, r1, r3
	ldrb r2, [r3]
	movs r0, #0xf
	subs r0, r0, r2
	ldr r3, _080CF938
	adds r1, r1, r3
	strb r0, [r1]
	ldr r0, [r5]
	ldr r1, _080CF93C
	adds r0, r0, r1
	bl AddWindow
	ldr r1, [r5]
	movs r4, #0xcb
	lsls r4, r4, #4
	adds r1, r1, r4
	movs r2, #0
	mov r8, r2
	strh r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl ClearWindowTilemap
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #0
	movs r2, #0xb
	movs r3, #0xe
	bl DrawStdFrameWithCustomTileAndPalette
	ldr r2, [r5]
	adds r0, r2, r4
	ldrb r0, [r0]
	movs r1, #0x10
	str r1, [sp]
	adds r1, r2, r6
	ldrb r1, [r1]
	str r1, [sp, #4]
	ldr r3, _080CF940
	adds r2, r2, r3
	str r2, [sp, #8]
	movs r1, #1
	movs r2, #8
	movs r3, #2
	bl PrintTextArray
	ldr r1, [r5]
	adds r4, r1, r4
	ldrb r0, [r4]
	adds r1, r1, r6
	ldrb r1, [r1]
	str r1, [sp]
	mov r1, sb
	str r1, [sp, #4]
	movs r1, #1
	movs r2, #0
	movs r3, #2
	bl sub_081984F0
	movs r0, #0
	bl ScheduleBgCopyTilemapToVram
	ldr r0, [r5]
	ldr r2, _080CF944
	adds r0, r0, r2
	mov r3, r8
	strb r3, [r0]
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF928: .4byte 0x020399A8
_080CF92C: .4byte 0x00000CAD
_080CF930: .4byte 0x00000CAC
_080CF934: .4byte 0x00000C6D
_080CF938: .4byte 0x00000C6E
_080CF93C: .4byte 0x00000C6C
_080CF940: .4byte 0x00000C74
_080CF944: .4byte 0x00000CAE
	thumb_func_end AddMenu

	thumb_func_start sub_080CF948
sub_080CF948: @ 0x080CF948
	movs r0, #0
	bx lr
	thumb_func_end sub_080CF948

	thumb_func_start sub_080CF94C
sub_080CF94C: @ 0x080CF94C
	push {r4, r5, lr}
	movs r5, #2
	rsbs r5, r5, #0
	ldr r4, _080CF988
	ldrh r1, [r4, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080CF9A2
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080CF96E
	movs r0, #5
	bl PlaySE
	adds r5, #1
_080CF96E:
	ldrh r1, [r4, #0x2e]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080CF98C
	movs r0, #5
	bl PlaySE
	movs r0, #1
	rsbs r0, r0, #0
	bl Menu_MoveCursor
	b _080CF9AA
	.align 2, 0
_080CF988: .4byte 0x03002360
_080CF98C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080CF9AA
	movs r0, #5
	bl PlaySE
	movs r0, #1
	bl Menu_MoveCursor
	b _080CF9AA
_080CF9A2:
	bl Menu_GetCursorPos
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_080CF9AA:
	movs r0, #2
	rsbs r0, r0, #0
	cmp r5, r0
	beq _080CF9B6
	bl sub_080CF9DC
_080CF9B6:
	cmp r5, #0
	blt _080CF9C8
	ldr r0, _080CF9D4
	ldr r0, [r0]
	lsls r1, r5, #3
	ldr r2, _080CF9D8
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r5, [r0]
_080CF9C8:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080CF9D4: .4byte 0x020399A8
_080CF9D8: .4byte 0x00000C78
	thumb_func_end sub_080CF94C

	thumb_func_start sub_080CF9DC
sub_080CF9DC: @ 0x080CF9DC
	push {r4, r5, lr}
	ldr r5, _080CFA00
	ldr r0, [r5]
	movs r4, #0xcb
	lsls r4, r4, #4
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #1
	bl ClearStdWindowAndFrameToTransparent
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl RemoveWindow
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CFA00: .4byte 0x020399A8
	thumb_func_end sub_080CF9DC

	thumb_func_start sub_080CFA04
sub_080CFA04: @ 0x080CFA04
	push {r4, lr}
	ldr r4, _080CFA40
	ldr r0, _080CFA44
	bl Alloc
	str r0, [r4]
	cmp r0, #0
	beq _080CFA50
	ldr r0, _080CFA48
	bl AddWindow8Bit
	adds r1, r0, #0
	ldr r0, _080CFA4C
	ldr r0, [r0]
	movs r2, #0x88
	lsls r2, r2, #6
	adds r0, r0, r2
	strh r1, [r0]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xff
	beq _080CFA50
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl FillWindowPixelBuffer
	movs r0, #1
	b _080CFA52
	.align 2, 0
_080CFA40: .4byte 0x02039A20
_080CFA44: .4byte 0x00000974
_080CFA48: .4byte 0x08556618
_080CFA4C: .4byte 0x020399A8
_080CFA50:
	movs r0, #0
_080CFA52:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_080CFA04

	thumb_func_start sub_080CFA58
sub_080CFA58: @ 0x080CFA58
	push {lr}
	ldr r0, _080CFA6C
	ldr r0, [r0]
	cmp r0, #0
	beq _080CFA66
	bl Free
_080CFA66:
	pop {r0}
	bx r0
	.align 2, 0
_080CFA6C: .4byte 0x02039A20
	thumb_func_end sub_080CFA58

	thumb_func_start sub_080CFA70
sub_080CFA70: @ 0x080CFA70
	ldr r2, _080CFA80
	ldr r1, [r2]
	movs r3, #0
	strb r0, [r1]
	ldr r0, [r2]
	strb r3, [r0, #1]
	bx lr
	.align 2, 0
_080CFA80: .4byte 0x02039A20
	thumb_func_end sub_080CFA70

	thumb_func_start sub_080CFA84
sub_080CFA84: @ 0x080CFA84
	push {lr}
	ldr r0, _080CFA9C
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080CFAE4
	lsls r0, r0, #2
	ldr r1, _080CFAA0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CFA9C: .4byte 0x02039A20
_080CFAA0: .4byte 0x080CFAA4
_080CFAA4: @ jump table
	.4byte _080CFABC @ case 0
	.4byte _080CFAC2 @ case 1
	.4byte _080CFAC8 @ case 2
	.4byte _080CFACE @ case 3
	.4byte _080CFAD4 @ case 4
	.4byte _080CFADA @ case 5
_080CFABC:
	bl sub_080CFAEC
	b _080CFADE
_080CFAC2:
	bl sub_080CFBE4
	b _080CFADE
_080CFAC8:
	bl sub_080CFC50
	b _080CFADE
_080CFACE:
	bl sub_080CFCC0
	b _080CFADE
_080CFAD4:
	bl sub_080CFD40
	b _080CFADE
_080CFADA:
	bl sub_080CFD68
_080CFADE:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080CFAE6
_080CFAE4:
	movs r0, #0
_080CFAE6:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080CFA84

	thumb_func_start sub_080CFAEC
sub_080CFAEC: @ 0x080CFAEC
	push {r4, r5, r6, lr}
	sub sp, #8
	ldr r6, _080CFB04
	ldr r1, [r6]
	ldrb r0, [r1, #1]
	cmp r0, #1
	beq _080CFB1C
	cmp r0, #1
	bgt _080CFB08
	cmp r0, #0
	beq _080CFB0E
	b _080CFBD8
	.align 2, 0
_080CFB04: .4byte 0x02039A20
_080CFB08:
	cmp r0, #2
	beq _080CFBC4
	b _080CFBD8
_080CFB0E:
	movs r0, #0
	bl HideBg
	movs r0, #0x80
	bl TryLoadAllMonIconPalettesAtOffset
	b _080CFBAE
_080CFB1C:
	adds r0, r1, #2
	adds r1, #3
	bl sub_080CF690
	ldr r1, [r6]
	ldrb r0, [r1, #2]
	strb r0, [r1, #4]
	ldr r1, [r6]
	ldrb r0, [r1, #3]
	strb r0, [r1, #5]
	ldr r4, _080CFBB8
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #0
	adds r1, r4, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	ldr r5, _080CFBBC
	ldr r0, [r5]
	movs r4, #0x88
	lsls r4, r4, #6
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #0
	bl FillWindowPixelBuffer8Bit
	ldr r1, [r6]
	ldrb r0, [r1, #2]
	ldrb r1, [r1, #3]
	bl sub_080D0050
	movs r0, #0
	movs r1, #4
	movs r2, #1
	bl SetBgAttribute
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r0, [r5]
	adds r0, r0, r4
	ldrb r0, [r0]
	movs r1, #3
	bl CopyWindowToVram8Bit
	movs r0, #0xfc
	lsls r0, r0, #6
	ldr r2, _080CFBC0
	movs r1, #8
	bl BlendPalettes
	movs r0, #2
	bl sub_080CF6D0
	movs r0, #8
	movs r1, #0x80
	bl SetGpuRegBits
_080CFBAE:
	ldr r1, [r6]
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	b _080CFBD8
	.align 2, 0
_080CFBB8: .4byte 0xFFFFFC00
_080CFBBC: .4byte 0x020399A8
_080CFBC0: .4byte 0x00007FFF
_080CFBC4:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CFBD8
	movs r0, #0
	bl ShowBg
	movs r0, #0
	b _080CFBDA
_080CFBD8:
	movs r0, #1
_080CFBDA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080CFAEC

	thumb_func_start sub_080CFBE4
sub_080CFBE4: @ 0x080CFBE4
	push {r4, lr}
	ldr r4, _080CFBFC
	ldr r0, [r4]
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _080CFC0E
	cmp r0, #1
	bgt _080CFC00
	cmp r0, #0
	beq _080CFC06
	b _080CFC48
	.align 2, 0
_080CFBFC: .4byte 0x02039A20
_080CFC00:
	cmp r0, #2
	beq _080CFC22
	b _080CFC48
_080CFC06:
	movs r0, #0
	bl HideBg
	b _080CFC18
_080CFC0E:
	bl sub_080D03FC
	movs r0, #0
	bl sub_080CF6D0
_080CFC18:
	ldr r1, [r4]
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	b _080CFC48
_080CFC22:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CFC48
	bl sub_080CF700
	movs r0, #3
	bl GetTextWindowPalette
	movs r1, #0xd0
	movs r2, #0x20
	bl LoadPalette
	movs r0, #0
	bl ShowBg
	movs r0, #0
	b _080CFC4A
_080CFC48:
	movs r0, #1
_080CFC4A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_080CFBE4

	thumb_func_start sub_080CFC50
sub_080CFC50: @ 0x080CFC50
	push {r4, lr}
	ldr r4, _080CFC64
	ldr r0, [r4]
	ldrb r0, [r0, #1]
	cmp r0, #0
	beq _080CFC68
	cmp r0, #1
	beq _080CFCAC
	b _080CFCB6
	.align 2, 0
_080CFC64: .4byte 0x02039A20
_080CFC68:
	bl sub_080CCDD0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CFCB6
	ldr r1, [r4]
	adds r0, r1, #6
	adds r1, #7
	bl sub_080CF690
	bl sub_080CFECC
	ldr r1, [r4]
	ldrb r0, [r1, #6]
	strb r0, [r1, #4]
	ldr r1, [r4]
	ldrb r0, [r1, #7]
	strb r0, [r1, #5]
	ldr r0, _080CFCA8
	ldr r0, [r0]
	movs r1, #0x88
	lsls r1, r1, #6
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram8Bit
	ldr r1, [r4]
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	b _080CFCB6
	.align 2, 0
_080CFCA8: .4byte 0x020399A8
_080CFCAC:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080CFCB8
_080CFCB6:
	movs r0, #1
_080CFCB8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080CFC50

	thumb_func_start sub_080CFCC0
sub_080CFCC0: @ 0x080CFCC0
	push {r4, lr}
	ldr r4, _080CFCD8
	ldr r0, [r4]
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _080CFCEE
	cmp r0, #1
	bgt _080CFCDC
	cmp r0, #0
	beq _080CFCE2
	b _080CFD38
	.align 2, 0
_080CFCD8: .4byte 0x02039A20
_080CFCDC:
	cmp r0, #2
	beq _080CFD1A
	b _080CFD38
_080CFCE2:
	bl sub_080D016C
	bl sub_080D0244
	movs r0, #0
	b _080CFD0C
_080CFCEE:
	bl DoMonPlaceChange
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CFD38
	movs r0, #3
	bl sub_080CF6D0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r0, #0
	movs r2, #8
	bl sub_080D0124
	movs r0, #1
_080CFD0C:
	bl sub_080CD4E0
	ldr r1, [r4]
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	b _080CFD38
_080CFD1A:
	bl sub_080D0134
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl DoMonPlaceChange
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, #0
	bne _080CFD38
	cmp r0, #0
	bne _080CFD38
	movs r0, #0
	b _080CFD3A
_080CFD38:
	movs r0, #1
_080CFD3A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_080CFCC0

	thumb_func_start sub_080CFD40
sub_080CFD40: @ 0x080CFD40
	push {r4, lr}
	bl sub_080CCDD0
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl sub_080D0134
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, #0
	bne _080CFD60
	cmp r0, #0
	bne _080CFD60
	movs r0, #0
	b _080CFD62
_080CFD60:
	movs r0, #1
_080CFD62:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_080CFD40

	thumb_func_start sub_080CFD68
sub_080CFD68: @ 0x080CFD68
	push {r4, lr}
	ldr r4, _080CFD80
	ldr r0, [r4]
	ldrb r0, [r0, #1]
	cmp r0, #1
	beq _080CFDA6
	cmp r0, #1
	bgt _080CFD84
	cmp r0, #0
	beq _080CFD8E
	b _080CFE16
	.align 2, 0
_080CFD80: .4byte 0x02039A20
_080CFD84:
	cmp r0, #2
	beq _080CFDD2
	cmp r0, #3
	beq _080CFDF0
	b _080CFE16
_080CFD8E:
	bl sub_080D034C
	movs r1, #0xff
	lsls r1, r1, #8
	movs r0, #0
	movs r2, #8
	bl sub_080D0124
	movs r0, #0
	bl sub_080CD4E0
	b _080CFDE6
_080CFDA6:
	bl DoMonPlaceChange
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CFE16
	bl sub_080D0134
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CFE16
	bl sub_080D02BC
	movs r0, #2
	bl sub_080CF6D0
	movs r0, #1
	bl sub_080CD4E0
	movs r0, #0
	bl HideBg
	b _080CFDE6
_080CFDD2:
	bl DoMonPlaceChange
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CFE16
	movs r0, #0
	bl sub_080CF6D0
	bl sub_080D03FC
_080CFDE6:
	ldr r1, [r4]
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	b _080CFE16
_080CFDF0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080CFE16
	movs r0, #3
	bl GetTextWindowPalette
	movs r1, #0xd0
	movs r2, #0x20
	bl LoadPalette
	bl sub_080CF700
	movs r0, #0
	bl ShowBg
	movs r0, #0
	b _080CFE18
_080CFE16:
	movs r0, #1
_080CFE18:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080CFD68

	thumb_func_start sub_080CFE20
sub_080CFE20: @ 0x080CFE20
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #1
	beq _080CFE5C
	cmp r0, #1
	bgt _080CFE36
	cmp r0, #0
	beq _080CFE40
	b _080CFEC4
_080CFE36:
	cmp r1, #2
	beq _080CFE7C
	cmp r1, #3
	beq _080CFE9C
	b _080CFEC4
_080CFE40:
	ldr r0, _080CFE58
	ldr r1, [r0]
	ldrb r0, [r1, #9]
	cmp r0, #0
	beq _080CFEAA
	subs r0, #1
	strb r0, [r1, #9]
	movs r1, #0x80
	lsls r1, r1, #3
	movs r0, #0
	b _080CFE90
	.align 2, 0
_080CFE58: .4byte 0x02039A20
_080CFE5C:
	ldr r0, _080CFE78
	ldr r1, [r0]
	ldrb r2, [r1, #9]
	ldrb r0, [r1, #0xb]
	adds r0, r2, r0
	cmp r0, #4
	bgt _080CFEAA
	adds r0, r2, #1
	strb r0, [r1, #9]
	movs r1, #0xfc
	lsls r1, r1, #8
	movs r0, #0
	b _080CFE90
	.align 2, 0
_080CFE78: .4byte 0x02039A20
_080CFE7C:
	ldr r0, _080CFE98
	ldr r1, [r0]
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _080CFEAA
	subs r0, #1
	strb r0, [r1, #8]
	movs r0, #0x80
	lsls r0, r0, #3
	movs r1, #0
_080CFE90:
	movs r2, #6
	bl sub_080D0124
	b _080CFEC4
	.align 2, 0
_080CFE98: .4byte 0x02039A20
_080CFE9C:
	ldr r0, _080CFEB0
	ldr r1, [r0]
	ldrb r2, [r1, #8]
	ldrb r0, [r1, #0xa]
	adds r0, r2, r0
	cmp r0, #5
	ble _080CFEB4
_080CFEAA:
	movs r0, #0
	b _080CFEC6
	.align 2, 0
_080CFEB0: .4byte 0x02039A20
_080CFEB4:
	adds r0, r2, #1
	strb r0, [r1, #8]
	movs r0, #0xfc
	lsls r0, r0, #8
	movs r1, #0
	movs r2, #6
	bl sub_080D0124
_080CFEC4:
	movs r0, #1
_080CFEC6:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080CFE20

	thumb_func_start sub_080CFECC
sub_080CFECC: @ 0x080CFECC
	push {r4, r5, r6, r7, lr}
	ldr r6, _080CFF6C
	ldr r2, [r6]
	ldrb r3, [r2, #2]
	ldrb r5, [r2, #6]
	subs r1, r3, r5
	cmp r1, #0
	bge _080CFEDE
	rsbs r1, r1, #0
_080CFEDE:
	ldrb r0, [r2, #4]
	subs r0, r3, r0
	cmp r0, #0
	bge _080CFEE8
	rsbs r0, r0, #0
_080CFEE8:
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldrb r1, [r2, #3]
	ldrb r0, [r2, #7]
	subs r3, r1, r0
	cmp r3, #0
	bge _080CFEFA
	rsbs r3, r3, #0
_080CFEFA:
	ldrb r2, [r2, #5]
	subs r0, r1, r2
	cmp r0, #0
	bge _080CFF04
	rsbs r0, r0, #0
_080CFF04:
	subs r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	ble _080CFF18
	adds r0, r5, #0
	bl sub_080CFF70
_080CFF18:
	cmp r4, #0
	bge _080CFF34
	ldr r2, [r6]
	ldrb r0, [r2, #4]
	ldrb r1, [r2, #3]
	ldrb r2, [r2, #5]
	bl sub_080CFFE0
	ldr r2, [r6]
	ldrb r0, [r2, #6]
	ldrb r1, [r2, #3]
	ldrb r2, [r2, #5]
	bl sub_080CFF70
_080CFF34:
	lsls r0, r7, #0x10
	asrs r4, r0, #0x10
	cmp r4, #0
	ble _080CFF48
	ldr r2, [r6]
	ldrb r0, [r2, #7]
	ldrb r1, [r2, #2]
	ldrb r2, [r2, #4]
	bl sub_080CFFA8
_080CFF48:
	cmp r4, #0
	bge _080CFF64
	ldr r2, [r6]
	ldrb r0, [r2, #5]
	ldrb r1, [r2, #2]
	ldrb r2, [r2, #4]
	bl sub_080D0018
	ldr r2, [r6]
	ldrb r0, [r2, #7]
	ldrb r1, [r2, #2]
	ldrb r2, [r2, #4]
	bl sub_080CFFA8
_080CFF64:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CFF6C: .4byte 0x02039A20
	thumb_func_end sub_080CFECC

	thumb_func_start sub_080CFF70
sub_080CFF70: @ 0x080CFF70
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r1, r4, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	adds r0, r5, #0
	cmp r4, r5
	bls _080CFF8E
	adds r4, r5, #0
	adds r5, r1, #0
	cmp r0, r5
	bhi _080CFFA0
_080CFF8E:
	adds r1, r4, #0
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r6, #0
	bl sub_080D0050
	cmp r4, r5
	bls _080CFF8E
_080CFFA0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080CFF70

	thumb_func_start sub_080CFFA8
sub_080CFFA8: @ 0x080CFFA8
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r1, r4, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	adds r0, r5, #0
	cmp r4, r5
	bls _080CFFC6
	adds r4, r5, #0
	adds r5, r1, #0
	cmp r0, r5
	bhi _080CFFD8
_080CFFC6:
	adds r0, r4, #0
	adds r1, r0, #1
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r1, r6, #0
	bl sub_080D0050
	cmp r4, r5
	bls _080CFFC6
_080CFFD8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080CFFA8

	thumb_func_start sub_080CFFE0
sub_080CFFE0: @ 0x080CFFE0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r1, r4, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	adds r0, r5, #0
	cmp r4, r5
	bls _080CFFFE
	adds r4, r5, #0
	adds r5, r1, #0
	cmp r0, r5
	bhi _080D0010
_080CFFFE:
	adds r1, r4, #0
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r6, #0
	bl sub_080D00D4
	cmp r4, r5
	bls _080CFFFE
_080D0010:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080CFFE0

	thumb_func_start sub_080D0018
sub_080D0018: @ 0x080D0018
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r1, r4, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	adds r0, r5, #0
	cmp r4, r5
	bls _080D0036
	adds r4, r5, #0
	adds r5, r1, #0
	cmp r0, r5
	bhi _080D0048
_080D0036:
	adds r0, r4, #0
	adds r1, r0, #1
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	adds r1, r6, #0
	bl sub_080D00D4
	cmp r4, r5
	bls _080D0036
_080D0048:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080D0018

	thumb_func_start sub_080D0050
sub_080D0050: @ 0x080D0050
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r1, #1
	adds r7, r0, r1
	lsls r4, r7, #1
	adds r4, r6, r4
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #0x41
	bl GetCurrentBoxMonData
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #0
	bl GetCurrentBoxMonData
	adds r1, r0, #0
	cmp r5, #0
	beq _080D00C8
	adds r0, r5, #0
	movs r2, #1
	bl GetMonIconPtr
	adds r4, r0, #0
	adds r0, r5, #0
	bl GetValidMonIconPalIndex
	adds r0, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _080D00D0
	ldr r1, [r1]
	movs r2, #0x88
	lsls r2, r2, #6
	adds r1, r1, r2
	ldrb r3, [r1]
	movs r2, #0x20
	str r2, [sp]
	str r2, [sp, #4]
	lsls r1, r6, #1
	adds r1, r1, r6
	lsls r1, r1, #3
	str r1, [sp, #8]
	lsls r1, r7, #3
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	str r2, [sp, #0x14]
	str r0, [sp, #0x18]
	adds r0, r3, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl BlitBitmapRectToWindow4BitTo8Bit
_080D00C8:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D00D0: .4byte 0x020399A8
	thumb_func_end sub_080D0050

	thumb_func_start sub_080D00D4
sub_080D00D4: @ 0x080D00D4
	push {r4, r5, lr}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r1, #1
	adds r5, r0, r1
	lsls r0, r5, #1
	adds r0, r4, r0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x41
	bl GetCurrentBoxMonData
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080D0118
	ldr r0, _080D0120
	ldr r0, [r0]
	movs r1, #0x88
	lsls r1, r1, #6
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r2, r4, #1
	adds r2, r2, r4
	lsls r2, r2, #3
	lsls r3, r5, #3
	movs r1, #0x20
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0
	bl FillWindowPixelRect8Bit
_080D0118:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D0120: .4byte 0x020399A8
	thumb_func_end sub_080D00D4

	thumb_func_start sub_080D0124
sub_080D0124: @ 0x080D0124
	ldr r3, _080D0130
	ldr r3, [r3]
	strh r0, [r3, #0xc]
	strh r1, [r3, #0xe]
	strh r2, [r3, #0x10]
	bx lr
	.align 2, 0
_080D0130: .4byte 0x02039A20
	thumb_func_end sub_080D0124

	thumb_func_start sub_080D0134
sub_080D0134: @ 0x080D0134
	push {r4, lr}
	ldr r4, _080D0168
	ldr r1, [r4]
	ldrh r0, [r1, #0x10]
	cmp r0, #0
	beq _080D015E
	ldrh r1, [r1, #0xc]
	movs r0, #0
	movs r2, #1
	bl ChangeBgX
	ldr r0, [r4]
	ldrh r1, [r0, #0xe]
	movs r0, #0
	movs r2, #1
	bl ChangeBgY
	ldr r1, [r4]
	ldrh r0, [r1, #0x10]
	subs r0, #1
	strh r0, [r1, #0x10]
_080D015E:
	ldr r0, [r4]
	ldrb r0, [r0, #0x10]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080D0168: .4byte 0x02039A20
	thumb_func_end sub_080D0134

	thumb_func_start sub_080D016C
sub_080D016C: @ 0x080D016C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _080D0240
	ldr r1, [r4]
	ldrb r0, [r1, #4]
	ldrb r2, [r1, #2]
	cmp r0, r2
	bls _080D0184
	adds r0, r2, #0
_080D0184:
	strb r0, [r1, #8]
	ldr r1, [r4]
	ldrb r0, [r1, #5]
	ldrb r2, [r1, #3]
	cmp r0, r2
	bls _080D0192
	adds r0, r2, #0
_080D0192:
	strb r0, [r1, #9]
	ldr r2, [r4]
	ldrb r1, [r2, #2]
	ldrb r0, [r2, #4]
	subs r0, r1, r0
	cmp r0, #0
	bge _080D01A2
	rsbs r0, r0, #0
_080D01A2:
	adds r0, #1
	strb r0, [r2, #0xa]
	ldr r2, [r4]
	ldrb r1, [r2, #3]
	ldrb r0, [r2, #5]
	subs r0, r1, r0
	cmp r0, #0
	bge _080D01B4
	rsbs r0, r0, #0
_080D01B4:
	adds r0, #1
	strb r0, [r2, #0xb]
	bl StorageGetCurrentBox
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	movs r6, #0
	ldr r0, [r4]
	ldrb r2, [r0, #8]
	ldrb r1, [r0, #0xa]
	adds r2, r2, r1
	mov r8, r2
	ldrb r1, [r0, #9]
	ldrb r0, [r0, #0xb]
	adds r0, r0, r1
	mov sb, r0
	adds r2, r1, #0
	cmp r2, sb
	bge _080D0230
_080D01DC:
	lsls r0, r2, #1
	adds r0, r0, r2
	ldr r3, _080D0240
	ldr r1, [r3]
	lsls r0, r0, #1
	ldrb r3, [r1, #8]
	adds r0, r0, r3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r4, [r1, #8]
	adds r7, r2, #1
	cmp r4, r8
	bge _080D022A
	mov r0, r8
	subs r4, r0, r4
_080D01FA:
	mov r0, sl
	adds r1, r5, #0
	bl GetBoxedMonPtr
	adds r1, r0, #0
	ldr r2, _080D0240
	ldr r0, [r2]
	lsls r2, r6, #2
	adds r2, r2, r6
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r0, #0x14
	movs r2, #0x50
	bl memcpy
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	subs r4, #1
	cmp r4, #0
	bne _080D01FA
_080D022A:
	adds r2, r7, #0
	cmp r2, sb
	blt _080D01DC
_080D0230:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D0240: .4byte 0x02039A20
	thumb_func_end sub_080D016C

	thumb_func_start sub_080D0244
sub_080D0244: @ 0x080D0244
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r4, _080D02B8
	ldr r0, [r4]
	ldrb r2, [r0, #8]
	ldrb r1, [r0, #0xa]
	adds r7, r2, r1
	ldrb r1, [r0, #9]
	ldrb r0, [r0, #0xb]
	adds r1, r1, r0
	mov sb, r1
	bl StorageGetCurrentBox
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, [r4]
	ldrb r2, [r0, #9]
	cmp r2, sb
	bge _080D02AC
_080D0270:
	lsls r0, r2, #1
	adds r0, r0, r2
	ldr r1, _080D02B8
	ldr r1, [r1]
	lsls r0, r0, #1
	ldrb r3, [r1, #8]
	adds r0, r0, r3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r4, [r1, #8]
	adds r6, r2, #1
	cmp r4, r7
	bge _080D02A6
	subs r4, r7, r4
_080D028C:
	adds r0, r5, #0
	bl DestroyBoxMonIconAtPosition
	mov r0, r8
	adds r1, r5, #0
	bl ZeroBoxMonAt
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	subs r4, #1
	cmp r4, #0
	bne _080D028C
_080D02A6:
	adds r2, r6, #0
	cmp r2, sb
	blt _080D0270
_080D02AC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D02B8: .4byte 0x02039A20
	thumb_func_end sub_080D0244

	thumb_func_start sub_080D02BC
sub_080D02BC: @ 0x080D02BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _080D0348
	ldr r0, [r0]
	ldrb r2, [r0, #8]
	ldrb r1, [r0, #0xa]
	adds r2, r2, r1
	mov r8, r2
	ldrb r1, [r0, #9]
	ldrb r0, [r0, #0xb]
	adds r0, r0, r1
	mov sl, r0
	movs r6, #0
	adds r2, r1, #0
	cmp r2, sl
	bge _080D0338
_080D02E2:
	lsls r0, r2, #1
	adds r0, r0, r2
	ldr r3, _080D0348
	ldr r1, [r3]
	lsls r0, r0, #1
	ldrb r4, [r1, #8]
	adds r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r4, [r1, #8]
	adds r7, r2, #1
	cmp r4, r8
	bge _080D0332
	mov sb, r3
	mov r0, r8
	subs r4, r0, r4
_080D0302:
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #4
	adds r1, #0x14
	mov r2, sb
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	beq _080D0320
	adds r0, r5, #0
	bl sub_080CA9B4
_080D0320:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	subs r4, #1
	cmp r4, #0
	bne _080D0302
_080D0332:
	adds r2, r7, #0
	cmp r2, sl
	blt _080D02E2
_080D0338:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D0348: .4byte 0x02039A20
	thumb_func_end sub_080D02BC

	thumb_func_start sub_080D034C
sub_080D034C: @ 0x080D034C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r4, _080D03F8
	ldr r0, [r4]
	ldrb r2, [r0, #8]
	ldrb r1, [r0, #0xa]
	adds r2, r2, r1
	mov sl, r2
	ldrb r1, [r0, #9]
	ldrb r0, [r0, #0xb]
	adds r1, r1, r0
	str r1, [sp]
	bl StorageGetCurrentBox
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	movs r7, #0
	ldr r0, [r4]
	ldrb r3, [r0, #9]
	ldr r0, [sp]
	cmp r3, r0
	bge _080D03E6
_080D0382:
	lsls r0, r3, #1
	adds r0, r0, r3
	ldr r2, _080D03F8
	ldr r1, [r2]
	lsls r0, r0, #1
	ldrb r4, [r1, #8]
	adds r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrb r5, [r1, #8]
	adds r3, #1
	mov sb, r3
	cmp r5, sl
	bge _080D03DE
	mov r8, r2
	mov r0, sl
	subs r5, r0, r5
_080D03A4:
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #4
	adds r4, r0, #0
	adds r4, #0x14
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r4
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	beq _080D03CC
	mov r0, r8
	ldr r2, [r0]
	adds r2, r2, r4
	ldr r0, [sp, #4]
	adds r1, r6, #0
	bl SetBoxMonAt
_080D03CC:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	subs r5, #1
	cmp r5, #0
	bne _080D03A4
_080D03DE:
	mov r3, sb
	ldr r1, [sp]
	cmp r3, r1
	blt _080D0382
_080D03E6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D03F8: .4byte 0x02039A20
	thumb_func_end sub_080D034C

	thumb_func_start sub_080D03FC
sub_080D03FC: @ 0x080D03FC
	push {lr}
	sub sp, #8
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #0
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #0
	movs r1, #4
	movs r2, #0
	bl SetBgAttribute
	movs r0, #8
	movs r1, #0x80
	bl ClearGpuRegBits
	movs r0, #0x20
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FillBgTilemapBufferRect_Palette0
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	add sp, #8
	pop {r0}
	bx r0
	thumb_func_end sub_080D03FC

	thumb_func_start sub_080D0444
sub_080D0444: @ 0x080D0444
	ldr r0, _080D045C
	ldr r2, [r0]
	ldrb r1, [r2, #3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	ldrb r2, [r2, #2]
	adds r0, r0, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bx lr
	.align 2, 0
_080D045C: .4byte 0x02039A20
	thumb_func_end sub_080D0444

	thumb_func_start sub_080D0460
sub_080D0460: @ 0x080D0460
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _080D04CC
	ldr r0, [r0]
	ldrb r2, [r0, #8]
	ldrb r1, [r0, #0xa]
	adds r2, r2, r1
	mov sb, r2
	ldrb r1, [r0, #9]
	ldrb r0, [r0, #0xb]
	adds r0, r1, r0
	str r0, [sp]
	movs r7, #0
	adds r6, r1, #0
	cmp r6, r0
	bge _080D04EE
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #1
	mov r8, r0
_080D0490:
	ldr r2, _080D04CC
	ldr r1, [r2]
	ldrb r0, [r1, #8]
	add r0, r8
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrb r4, [r1, #8]
	cmp r4, sb
	bge _080D04E2
	mov sl, r2
_080D04A4:
	lsls r1, r7, #2
	adds r1, r1, r7
	lsls r1, r1, #4
	adds r1, #0x14
	mov r2, sl
	ldr r0, [r2]
	adds r0, r0, r1
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	beq _080D04D0
	adds r0, r5, #0
	movs r1, #5
	bl GetCurrentBoxMonData
	cmp r0, #0
	beq _080D04D0
	movs r0, #0
	b _080D04F0
	.align 2, 0
_080D04CC: .4byte 0x02039A20
_080D04D0:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r4, #1
	cmp r4, sb
	blt _080D04A4
_080D04E2:
	movs r0, #6
	add r8, r0
	adds r6, #1
	ldr r2, [sp]
	cmp r6, r2
	blt _080D0490
_080D04EE:
	movs r0, #1
_080D04F0:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_080D0460

	thumb_func_start sub_080D0500
sub_080D0500: @ 0x080D0500
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r3, _080D05FC
	ldr r0, [r3]
	ldrb r0, [r0, #1]
	cmp r0, #3
	bne _080D05DE
	ldr r0, _080D0600
	str r0, [sp, #0x18]
	ldr r1, _080D0604
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	str r0, [r2, #4]
	mov r1, sp
	ldr r0, _080D0608
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	ldm r0!, {r4, r5, r6}
	stm r1!, {r4, r5, r6}
	movs r7, #0
	mov sb, r2
	mov r8, r3
	movs r0, #0
	mov sl, r0
_080D0540:
	adds r6, r7, #7
	lsls r1, r6, #0x10
	mov r2, sb
	ldrh r0, [r2, #4]
	orrs r0, r1
	str r0, [r2, #4]
	mov r0, sb
	bl LoadCompressedSpriteSheet
	mov r4, sb
	ldrh r0, [r4, #6]
	bl GetSpriteTileStartByTag
	mov r5, r8
	ldr r1, [r5]
	lsls r5, r7, #4
	ldr r2, _080D060C
	adds r1, r1, r2
	adds r1, r1, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0xb
	ldr r4, _080D0610
	adds r0, r0, r4
	str r0, [r1]
	ldr r0, _080D0614
	adds r4, r7, r0
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl AllocSpritePalette
	mov r2, r8
	ldr r1, [r2]
	adds r1, r1, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080D0618
	adds r1, r1, r2
	strh r0, [r1]
	ldrh r0, [r1]
	lsls r0, r0, #4
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r0, [r1]
	mov r0, sp
	strh r6, [r0]
	strh r4, [r0, #2]
	movs r1, #0
	movs r2, #0
	movs r3, #0xb
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r4, r8
	ldr r2, [r4]
	ldr r6, _080D061C
	adds r2, r2, r6
	adds r2, r2, r5
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _080D0620
	adds r1, r1, r0
	str r1, [r2]
	adds r1, #0x3e
	ldrb r0, [r1]
	movs r2, #4
	orrs r0, r2
	strb r0, [r1]
	ldr r0, [r4]
	adds r0, r0, r5
	ldr r1, _080D0624
	adds r0, r0, r1
	mov r2, sl
	strb r2, [r0]
	adds r7, #1
	cmp r7, #2
	ble _080D0540
_080D05DE:
	ldr r0, _080D05FC
	ldr r0, [r0]
	ldr r4, _080D0628
	adds r0, r0, r4
	movs r1, #0
	strh r1, [r0]
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D05FC: .4byte 0x020399A8
_080D0600: .4byte 0x03000F78
_080D0604: .4byte 0xFFFF0000
_080D0608: .4byte 0x0855676C
_080D060C: .4byte 0x00002208
_080D0610: .4byte 0x06010000
_080D0614: .4byte 0xFFFFDACB
_080D0618: .4byte 0x0000220C
_080D061C: .4byte 0x00002204
_080D0620: .4byte 0x020205AC
_080D0624: .4byte 0x00002210
_080D0628: .4byte 0x00002234
	thumb_func_end sub_080D0500

	thumb_func_start sub_080D062C
sub_080D062C: @ 0x080D062C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	ldr r0, _080D0660
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #3
	bne _080D06E2
	mov r0, r8
	adds r1, r7, #0
	bl sub_080D0BC4
	cmp r0, #0
	bne _080D06E2
	mov r0, r8
	cmp r0, #0
	beq _080D0664
	cmp r0, #1
	beq _080D067A
	b _080D06E2
	.align 2, 0
_080D0660: .4byte 0x020399A8
_080D0664:
	adds r0, r7, #0
	movs r1, #5
	bl GetCurrentBoxMonData
	cmp r0, #0
	beq _080D06E2
	adds r0, r7, #0
	movs r1, #0xc
	bl GetCurrentBoxMonData
	b _080D069C
_080D067A:
	cmp r7, #5
	bhi _080D06E2
	movs r0, #0x64
	adds r1, r7, #0
	muls r1, r0, r1
	ldr r0, _080D06EC
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #5
	bl GetMonData3
	cmp r0, #0
	beq _080D06E2
	adds r0, r4, #0
	movs r1, #0xc
	bl GetMonData3
_080D069C:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _080D06E2
	adds r0, r4, #0
	bl GetItemIconPic
	adds r6, r0, #0
	adds r0, r4, #0
	bl GetItemIconPalette
	adds r5, r0, #0
	bl sub_080D0B88
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	mov r1, r8
	adds r2, r7, #0
	bl sub_080D0CAC
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r5, #0
	bl sub_080D0DC4
	adds r0, r4, #0
	movs r1, #1
	bl sub_080D0E74
	adds r0, r4, #0
	movs r1, #1
	bl sub_080D0FE0
_080D06E2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D06EC: .4byte 0x02024190
	thumb_func_end sub_080D062C

	thumb_func_start sub_080D06F0
sub_080D06F0: @ 0x080D06F0
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	ldr r0, _080D072C
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #3
	bne _080D0726
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_080D0C10
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #2
	bl sub_080D0E74
	adds r0, r4, #0
	movs r1, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl sub_080D0EA4
_080D0726:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D072C: .4byte 0x020399A8
	thumb_func_end sub_080D06F0

	thumb_func_start Item_FromMonToMoving
Item_FromMonToMoving: @ 0x080D0730
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r7, r5, #0
	ldr r0, _080D0794
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #3
	bne _080D07C0
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_080D0C10
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r1, #0
	mov r0, sp
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #3
	bl sub_080D0E74
	adds r0, r4, #0
	movs r1, #1
	adds r2, r6, #0
	adds r3, r5, #0
	bl sub_080D0EA4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl sub_080D0CAC
	cmp r6, #0
	bne _080D0798
	adds r0, r5, #0
	movs r1, #0xc
	mov r2, sp
	bl SetCurrentBoxMonData
	adds r0, r5, #0
	movs r1, #1
	bl SetBoxMonIconObjMode
	b _080D07B0
	.align 2, 0
_080D0794: .4byte 0x020399A8
_080D0798:
	movs r0, #0x64
	muls r0, r7, r0
	ldr r1, _080D07C8
	adds r0, r0, r1
	movs r1, #0xc
	mov r2, sp
	bl SetMonData
	adds r0, r7, #0
	movs r1, #1
	bl SetPartyMonIconObjMode
_080D07B0:
	ldr r0, _080D07CC
	ldr r0, [r0]
	ldr r2, _080D07D0
	adds r1, r0, r2
	ldrh r1, [r1]
	ldr r2, _080D07D4
	adds r0, r0, r2
	strh r1, [r0]
_080D07C0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D07C8: .4byte 0x02024190
_080D07CC: .4byte 0x020399A8
_080D07D0: .4byte 0x00000CE6
_080D07D4: .4byte 0x00002234
	thumb_func_end Item_FromMonToMoving

	thumb_func_start sub_080D07D8
sub_080D07D8: @ 0x080D07D8
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r5, #0
	bl GetItemIconPic
	mov r8, r0
	adds r0, r5, #0
	bl GetItemIconPalette
	adds r6, r0, #0
	bl sub_080D0B88
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	mov r1, r8
	adds r2, r6, #0
	bl sub_080D0DC4
	adds r0, r4, #0
	movs r1, #6
	bl sub_080D0E74
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl sub_080D0EA4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl sub_080D0CAC
	adds r0, r4, #0
	movs r1, #1
	bl sub_080D0FE0
	ldr r0, _080D0844
	ldr r0, [r0]
	ldr r1, _080D0848
	adds r0, r0, r1
	strh r5, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D0844: .4byte 0x020399A8
_080D0848: .4byte 0x00002234
	thumb_func_end sub_080D07D8

	thumb_func_start Item_SwitchMonsWithMoving
Item_SwitchMonsWithMoving: @ 0x080D084C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	ldr r0, _080D08B4
	mov r8, r0
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #3
	bne _080D090A
	mov r0, sb
	adds r1, r7, #0
	bl sub_080D0C10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #3
	bl sub_080D0E74
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	movs r3, #0
	bl sub_080D0EA4
	mov r1, sb
	cmp r1, #0
	bne _080D08BC
	adds r0, r7, #0
	movs r1, #0xc
	bl GetCurrentBoxMonData
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, r8
	ldr r2, [r0]
	ldr r4, _080D08B8
	adds r2, r2, r4
	adds r0, r7, #0
	movs r1, #0xc
	bl SetCurrentBoxMonData
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r4
	b _080D08E8
	.align 2, 0
_080D08B4: .4byte 0x020399A8
_080D08B8: .4byte 0x00002234
_080D08BC:
	movs r0, #0x64
	adds r4, r7, #0
	muls r4, r0, r4
	ldr r0, _080D0918
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xc
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, r8
	ldr r2, [r0]
	ldr r5, _080D091C
	adds r2, r2, r5
	adds r0, r4, #0
	movs r1, #0xc
	bl SetMonData
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r5
_080D08E8:
	strh r6, [r0]
	movs r0, #2
	movs r1, #0
	bl sub_080D0C10
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	movs r1, #4
	bl sub_080D0E74
	adds r0, r4, #0
	movs r1, #4
	mov r2, sb
	adds r3, r7, #0
	bl sub_080D0EA4
_080D090A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D0918: .4byte 0x02024190
_080D091C: .4byte 0x00002234
	thumb_func_end Item_SwitchMonsWithMoving

	thumb_func_start Item_GiveMovingToMon
Item_GiveMovingToMon: @ 0x080D0920
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	mov r8, r5
	ldr r6, _080D0978
	ldr r0, [r6]
	ldrb r0, [r0, #1]
	cmp r0, #3
	bne _080D09A0
	movs r0, #2
	movs r1, #0
	bl sub_080D0C10
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #4
	bl sub_080D0E74
	adds r0, r4, #0
	movs r1, #2
	adds r2, r7, #0
	adds r3, r5, #0
	bl sub_080D0EA4
	cmp r7, #0
	bne _080D0980
	ldr r2, [r6]
	ldr r0, _080D097C
	adds r2, r2, r0
	adds r0, r5, #0
	movs r1, #0xc
	bl SetCurrentBoxMonData
	adds r0, r5, #0
	movs r1, #0
	bl SetBoxMonIconObjMode
	b _080D09A0
	.align 2, 0
_080D0978: .4byte 0x020399A8
_080D097C: .4byte 0x00002234
_080D0980:
	movs r0, #0x64
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r1, _080D09AC
	adds r0, r0, r1
	ldr r2, [r6]
	ldr r1, _080D09B0
	adds r2, r2, r1
	movs r1, #0xc
	bl SetMonData
	mov r0, r8
	movs r1, #0
	bl SetPartyMonIconObjMode
_080D09A0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D09AC: .4byte 0x02024190
_080D09B0: .4byte 0x00002234
	thumb_func_end Item_GiveMovingToMon

	thumb_func_start Item_TakeMons
Item_TakeMons: @ 0x080D09B4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r7, r5, #0
	ldr r0, _080D0A0C
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #3
	bne _080D0A28
	movs r1, #0
	mov r0, sp
	strh r1, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl sub_080D0C10
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #2
	bl sub_080D0E74
	adds r0, r4, #0
	movs r1, #0
	adds r2, r6, #0
	adds r3, r5, #0
	bl sub_080D0EA4
	cmp r6, #0
	bne _080D0A10
	adds r0, r5, #0
	movs r1, #0xc
	mov r2, sp
	bl SetCurrentBoxMonData
	adds r0, r5, #0
	movs r1, #1
	bl SetBoxMonIconObjMode
	b _080D0A28
	.align 2, 0
_080D0A0C: .4byte 0x020399A8
_080D0A10:
	movs r0, #0x64
	muls r0, r7, r0
	ldr r1, _080D0A30
	adds r0, r0, r1
	movs r1, #0xc
	mov r2, sp
	bl SetMonData
	adds r0, r7, #0
	movs r1, #1
	bl SetPartyMonIconObjMode
_080D0A28:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D0A30: .4byte 0x02024190
	thumb_func_end Item_TakeMons

	thumb_func_start sub_080D0A34
sub_080D0A34: @ 0x080D0A34
	push {r4, lr}
	ldr r0, _080D0A68
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #3
	bne _080D0A62
	movs r0, #2
	movs r1, #0
	bl sub_080D0C10
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	movs r1, #5
	bl sub_080D0E74
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl sub_080D0EA4
_080D0A62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D0A68: .4byte 0x020399A8
	thumb_func_end sub_080D0A34

	thumb_func_start sub_080D0A6C
sub_080D0A6C: @ 0x080D0A6C
	push {r4, lr}
	ldr r0, _080D0AB0
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #3
	bne _080D0AAA
	movs r4, #0
_080D0A7A:
	ldr r0, _080D0AB0
	ldr r1, [r0]
	lsls r0, r4, #4
	adds r1, r1, r0
	ldr r2, _080D0AB4
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0AA4
	subs r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D0AA4
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	movs r1, #7
	movs r2, #2
	movs r3, #0
	bl sub_080D0EA4
_080D0AA4:
	adds r4, #1
	cmp r4, #2
	ble _080D0A7A
_080D0AAA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D0AB0: .4byte 0x020399A8
_080D0AB4: .4byte 0x00002210
	thumb_func_end sub_080D0A6C

	thumb_func_start sub_080D0AB8
sub_080D0AB8: @ 0x080D0AB8
	push {r4, r5, lr}
	movs r5, #0
	ldr r0, _080D0AF4
	ldr r0, [r0]
	ldr r1, _080D0AF8
	adds r4, r0, r1
	adds r3, r0, #0
_080D0AC6:
	ldr r1, _080D0AFC
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0B08
	ldr r2, [r4]
	adds r0, r2, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x28
	ands r0, r1
	cmp r0, #8
	beq _080D0AEE
	ldr r1, [r2, #0x1c]
	ldr r0, _080D0B00
	cmp r1, r0
	beq _080D0B08
	ldr r0, _080D0B04
	cmp r1, r0
	beq _080D0B08
_080D0AEE:
	movs r0, #1
	b _080D0B14
	.align 2, 0
_080D0AF4: .4byte 0x020399A8
_080D0AF8: .4byte 0x00002204
_080D0AFC: .4byte 0x00002210
_080D0B00: .4byte 0x08007141
_080D0B04: .4byte 0x080D1379
_080D0B08:
	adds r4, #0x10
	adds r3, #0x10
	adds r5, #1
	cmp r5, #2
	ble _080D0AC6
	movs r0, #0
_080D0B14:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080D0AB8

	thumb_func_start IsActiveItemMoving
IsActiveItemMoving: @ 0x080D0B1C
	push {lr}
	ldr r0, _080D0B40
	ldr r1, [r0]
	ldrb r0, [r1, #1]
	cmp r0, #3
	bne _080D0B50
	movs r2, #0
	ldr r0, _080D0B44
	adds r1, r1, r0
_080D0B2E:
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _080D0B48
	ldrb r0, [r1]
	cmp r0, #2
	bne _080D0B48
	movs r0, #1
	b _080D0B52
	.align 2, 0
_080D0B40: .4byte 0x020399A8
_080D0B44: .4byte 0x0000220E
_080D0B48:
	adds r1, #0x10
	adds r2, #1
	cmp r2, #2
	ble _080D0B2E
_080D0B50:
	movs r0, #0
_080D0B52:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsActiveItemMoving

	thumb_func_start GetMovingItemName
GetMovingItemName: @ 0x080D0B58
	push {lr}
	ldr r0, _080D0B6C
	ldr r0, [r0]
	ldr r1, _080D0B70
	adds r0, r0, r1
	ldrh r0, [r0]
	bl ItemId_GetName
	pop {r1}
	bx r1
	.align 2, 0
_080D0B6C: .4byte 0x020399A8
_080D0B70: .4byte 0x00002234
	thumb_func_end GetMovingItemName

	thumb_func_start GetMovingItem
GetMovingItem: @ 0x080D0B74
	ldr r0, _080D0B80
	ldr r0, [r0]
	ldr r1, _080D0B84
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_080D0B80: .4byte 0x020399A8
_080D0B84: .4byte 0x00002234
	thumb_func_end GetMovingItem

	thumb_func_start sub_080D0B88
sub_080D0B88: @ 0x080D0B88
	push {r4, r5, lr}
	movs r2, #0
	ldr r5, _080D0BA8
	ldr r3, _080D0BAC
	movs r4, #1
_080D0B92:
	ldr r0, [r5]
	lsls r1, r2, #4
	adds r0, r0, r1
	adds r1, r0, r3
	ldrb r0, [r1]
	cmp r0, #0
	bne _080D0BB0
	strb r4, [r1]
	adds r0, r2, #0
	b _080D0BBC
	.align 2, 0
_080D0BA8: .4byte 0x020399A8
_080D0BAC: .4byte 0x00002210
_080D0BB0:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #2
	bls _080D0B92
	movs r0, #3
_080D0BBC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080D0B88

	thumb_func_start sub_080D0BC4
sub_080D0BC4: @ 0x080D0BC4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	movs r3, #0
	ldr r0, _080D0BF8
	ldr r2, [r0]
_080D0BD4:
	ldr r5, _080D0BFC
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0C00
	subs r5, #2
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, r4
	bne _080D0C00
	adds r5, #1
	adds r0, r2, r5
	ldrb r0, [r0]
	cmp r0, r1
	bne _080D0C00
	movs r0, #1
	b _080D0C0A
	.align 2, 0
_080D0BF8: .4byte 0x020399A8
_080D0BFC: .4byte 0x00002210
_080D0C00:
	adds r2, #0x10
	adds r3, #1
	cmp r3, #2
	ble _080D0BD4
	movs r0, #0
_080D0C0A:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_080D0BC4

	thumb_func_start sub_080D0C10
sub_080D0C10: @ 0x080D0C10
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r3, #0
	ldr r0, _080D0C48
	ldr r1, [r0]
_080D0C20:
	lsls r0, r3, #4
	adds r2, r1, r0
	ldr r6, _080D0C4C
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0C50
	subs r6, #2
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, r5
	bne _080D0C50
	adds r6, #1
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, r4
	bne _080D0C50
	adds r0, r3, #0
	b _080D0C5C
	.align 2, 0
_080D0C48: .4byte 0x020399A8
_080D0C4C: .4byte 0x00002210
_080D0C50:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #2
	bls _080D0C20
	movs r0, #3
_080D0C5C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080D0C10

	thumb_func_start sub_080D0C64
sub_080D0C64: @ 0x080D0C64
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r2, #0
	ldr r0, _080D0C8C
	ldr r3, [r0]
	ldr r0, _080D0C90
	adds r4, r3, r0
	ldr r6, _080D0C94
_080D0C74:
	lsls r1, r2, #4
	adds r0, r3, r1
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0C98
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, r5
	bne _080D0C98
	adds r0, r2, #0
	b _080D0CA4
	.align 2, 0
_080D0C8C: .4byte 0x020399A8
_080D0C90: .4byte 0x00002204
_080D0C94: .4byte 0x00002210
_080D0C98:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #2
	bls _080D0C74
	movs r0, #3
_080D0CA4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080D0C64

	thumb_func_start sub_080D0CAC
sub_080D0CAC: @ 0x080D0CAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	cmp r5, #2
	bhi _080D0DAA
	cmp r1, #0
	beq _080D0CD8
	cmp r1, #1
	beq _080D0D34
	ldr r4, _080D0CD4
	lsls r3, r5, #4
	b _080D0D94
	.align 2, 0
_080D0CD4: .4byte 0x020399A8
_080D0CD8:
	adds r0, r7, #0
	movs r1, #6
	bl __umodsi3
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r7, #0
	movs r1, #6
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r6, _080D0D2C
	ldr r2, [r6]
	lsls r5, r5, #4
	ldr r1, _080D0D30
	adds r2, r2, r1
	adds r2, r2, r5
	ldr r3, [r2]
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #3
	adds r1, #0x70
	strh r1, [r3, #0x20]
	ldr r3, [r2]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, #0x38
	strh r1, [r3, #0x22]
	ldr r2, [r2]
	ldrb r1, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #5]
	adds r4, r6, #0
	adds r3, r5, #0
	b _080D0D94
	.align 2, 0
_080D0D2C: .4byte 0x020399A8
_080D0D30: .4byte 0x00002204
_080D0D34:
	cmp r7, #0
	bne _080D0D5C
	ldr r4, _080D0D54
	ldr r0, [r4]
	lsls r3, r5, #4
	ldr r1, _080D0D58
	adds r0, r0, r1
	adds r0, r0, r3
	ldr r2, [r0]
	movs r1, #0x74
	strh r1, [r2, #0x20]
	ldr r1, [r0]
	movs r0, #0x4c
	strh r0, [r1, #0x22]
	b _080D0D7C
	.align 2, 0
_080D0D54: .4byte 0x020399A8
_080D0D58: .4byte 0x00002204
_080D0D5C:
	ldr r4, _080D0DB4
	ldr r0, [r4]
	lsls r3, r5, #4
	ldr r1, _080D0DB8
	adds r0, r0, r1
	adds r0, r0, r3
	ldr r2, [r0]
	movs r1, #0xa4
	strh r1, [r2, #0x20]
	ldr r2, [r0]
	subs r1, r7, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x1c
	strh r0, [r2, #0x22]
_080D0D7C:
	ldr r0, [r4]
	ldr r1, _080D0DB8
	adds r0, r0, r1
	adds r0, r0, r3
	ldr r2, [r0]
	ldrb r1, [r2, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	strb r0, [r2, #5]
_080D0D94:
	ldr r0, [r4]
	adds r0, r0, r3
	ldr r1, _080D0DBC
	adds r0, r0, r1
	mov r1, r8
	strb r1, [r0]
	ldr r0, [r4]
	adds r0, r0, r3
	ldr r1, _080D0DC0
	adds r0, r0, r1
	strb r7, [r0]
_080D0DAA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D0DB4: .4byte 0x020399A8
_080D0DB8: .4byte 0x00002204
_080D0DBC: .4byte 0x0000220E
_080D0DC0: .4byte 0x0000220F
	thumb_func_end sub_080D0CAC

	thumb_func_start sub_080D0DC4
sub_080D0DC4: @ 0x080D0DC4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r1
	mov sb, r2
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #2
	bhi _080D0E4C
	movs r0, #0
	str r0, [sp]
	ldr r4, _080D0E5C
	ldr r1, [r4]
	ldr r6, _080D0E60
	adds r1, r1, r6
	ldr r2, _080D0E64
	mov r0, sp
	bl CpuFastSet
	ldr r1, [r4]
	ldr r5, _080D0E68
	adds r1, r1, r5
	mov r0, r8
	bl LZ77UnCompWram
	lsls r7, r7, #4
	mov r8, r7
	adds r7, r4, #0
	movs r4, #2
_080D0E02:
	ldr r1, [r7]
	adds r0, r1, r5
	adds r1, r1, r6
	movs r2, #0x18
	bl CpuFastSet
	adds r6, #0x80
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080D0E02
	ldr r5, _080D0E5C
	ldr r1, [r5]
	ldr r4, _080D0E60
	adds r0, r1, r4
	ldr r2, _080D0E6C
	adds r1, r1, r2
	add r1, r8
	ldr r1, [r1]
	movs r2, #0x80
	bl CpuFastSet
	ldr r1, [r5]
	adds r1, r1, r4
	mov r0, sb
	bl LZ77UnCompWram
	ldr r0, [r5]
	adds r4, r0, r4
	add r0, r8
	ldr r1, _080D0E70
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	movs r2, #0x20
	bl LoadPalette
_080D0E4C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D0E5C: .4byte 0x020399A8
_080D0E60: .4byte 0x000042C4
_080D0E64: .4byte 0x01000080
_080D0E68: .4byte 0x000022C4
_080D0E6C: .4byte 0x00002208
_080D0E70: .4byte 0x0000220C
	thumb_func_end sub_080D0DC4

	thumb_func_start sub_080D0E74
sub_080D0E74: @ 0x080D0E74
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	cmp r2, #2
	bhi _080D0E96
	ldr r0, _080D0E9C
	ldr r0, [r0]
	lsls r1, r2, #4
	ldr r2, _080D0EA0
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r1, r3, #0
	bl StartSpriteAffineAnim
_080D0E96:
	pop {r0}
	bx r0
	.align 2, 0
_080D0E9C: .4byte 0x020399A8
_080D0EA0: .4byte 0x00002204
	thumb_func_end sub_080D0E74

	thumb_func_start sub_080D0EA4
sub_080D0EA4: @ 0x080D0EA4
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	cmp r4, #2
	bls _080D0EBC
	b _080D0FCE
_080D0EBC:
	cmp r0, #7
	bls _080D0EC2
	b _080D0FCE
_080D0EC2:
	lsls r0, r0, #2
	ldr r1, _080D0ECC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D0ECC: .4byte 0x080D0ED0
_080D0ED0: @ jump table
	.4byte _080D0EF0 @ case 0
	.4byte _080D0F14 @ case 1
	.4byte _080D0F38 @ case 2
	.4byte _080D0F64 @ case 3
	.4byte _080D0F90 @ case 4
	.4byte _080D0FCE @ case 5
	.4byte _080D0FCE @ case 6
	.4byte _080D0FBC @ case 7
_080D0EF0:
	ldr r0, _080D0F08
	ldr r0, [r0]
	lsls r1, r4, #4
	ldr r2, _080D0F0C
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r1, [r0]
	strh r4, [r1, #0x2e]
	ldr r1, [r0]
	ldr r0, _080D0F10
	b _080D0FCC
	.align 2, 0
_080D0F08: .4byte 0x020399A8
_080D0F0C: .4byte 0x00002204
_080D0F10: .4byte 0x080D12E9
_080D0F14:
	ldr r0, _080D0F2C
	ldr r0, [r0]
	lsls r1, r4, #4
	ldr r2, _080D0F30
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0
	strh r1, [r2, #0x2e]
	ldr r1, [r0]
	ldr r0, _080D0F34
	b _080D0FCC
	.align 2, 0
_080D0F2C: .4byte 0x020399A8
_080D0F30: .4byte 0x00002204
_080D0F34: .4byte 0x080D1315
_080D0F38:
	ldr r0, _080D0F58
	ldr r0, [r0]
	lsls r1, r4, #4
	ldr r2, _080D0F5C
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0
	strh r1, [r2, #0x2e]
	ldr r1, [r0]
	strh r5, [r1, #0x3a]
	ldr r1, [r0]
	strh r3, [r1, #0x3c]
	ldr r1, [r0]
	ldr r0, _080D0F60
	b _080D0FCC
	.align 2, 0
_080D0F58: .4byte 0x020399A8
_080D0F5C: .4byte 0x00002204
_080D0F60: .4byte 0x080D13B5
_080D0F64:
	ldr r0, _080D0F84
	ldr r0, [r0]
	lsls r1, r4, #4
	ldr r2, _080D0F88
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0
	strh r1, [r2, #0x2e]
	ldr r2, [r0]
	ldr r1, _080D0F8C
	str r1, [r2, #0x1c]
	strh r5, [r2, #0x3a]
	ldr r0, [r0]
	strh r3, [r0, #0x3c]
	b _080D0FCE
	.align 2, 0
_080D0F84: .4byte 0x020399A8
_080D0F88: .4byte 0x00002204
_080D0F8C: .4byte 0x080D1435
_080D0F90:
	ldr r0, _080D0FB0
	ldr r0, [r0]
	lsls r1, r4, #4
	ldr r2, _080D0FB4
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0
	strh r1, [r2, #0x2e]
	ldr r1, [r0]
	strh r5, [r1, #0x3a]
	ldr r1, [r0]
	strh r3, [r1, #0x3c]
	ldr r1, [r0]
	ldr r0, _080D0FB8
	b _080D0FCC
	.align 2, 0
_080D0FB0: .4byte 0x020399A8
_080D0FB4: .4byte 0x00002204
_080D0FB8: .4byte 0x080D14D1
_080D0FBC:
	ldr r0, _080D0FD4
	ldr r0, [r0]
	lsls r1, r4, #4
	ldr r2, _080D0FD8
	adds r0, r0, r2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _080D0FDC
_080D0FCC:
	str r0, [r1, #0x1c]
_080D0FCE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D0FD4: .4byte 0x020399A8
_080D0FD8: .4byte 0x00002204
_080D0FDC: .4byte 0x080D156D
	thumb_func_end sub_080D0EA4

	thumb_func_start sub_080D0FE0
sub_080D0FE0: @ 0x080D0FE0
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r2, #2
	bhi _080D1020
	ldr r1, _080D1028
	ldr r0, [r1]
	lsls r2, r2, #4
	adds r0, r0, r2
	ldr r3, _080D102C
	adds r0, r0, r3
	strb r4, [r0]
	ldr r0, [r1]
	ldr r1, _080D1030
	adds r0, r0, r1
	adds r0, r0, r2
	ldr r0, [r0]
	movs r3, #0
	cmp r4, #0
	bne _080D100E
	movs r3, #1
_080D100E:
	adds r2, r0, #0
	adds r2, #0x3e
	lsls r3, r3, #2
	ldrb r1, [r2]
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r3
	strb r0, [r2]
_080D1020:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D1028: .4byte 0x020399A8
_080D102C: .4byte 0x00002210
_080D1030: .4byte 0x00002204
	thumb_func_end sub_080D0FE0

	thumb_func_start GetItemIconPic
GetItemIconPic: @ 0x080D1034
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0
	bl GetItemIconPicOrPalette
	pop {r1}
	bx r1
	thumb_func_end GetItemIconPic

	thumb_func_start GetItemIconPalette
GetItemIconPalette: @ 0x080D1044
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl GetItemIconPicOrPalette
	pop {r1}
	bx r1
	thumb_func_end GetItemIconPalette

	thumb_func_start Cb_HandleMovingMonFromParty
Cb_HandleMovingMonFromParty: @ 0x080D1054
	push {r4, lr}
	sub sp, #0x14
	bl IsActiveItemMoving
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080D1074
	ldr r0, _080D106C
	ldr r0, [r0]
	ldr r1, _080D1070
	b _080D107A
	.align 2, 0
_080D106C: .4byte 0x020399A8
_080D1070: .4byte 0x00002234
_080D1074:
	ldr r0, _080D10B0
	ldr r0, [r0]
	ldr r1, _080D10B4
_080D107A:
	adds r0, r0, r1
	ldrh r0, [r0]
	bl ItemId_GetHoldEffect
	adds r4, r0, #0
	movs r0, #2
	movs r1, #0x11
	bl FillWindowPixelBuffer
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	movs r0, #2
	movs r1, #1
	adds r2, r4, #0
	movs r3, #4
	bl AddTextPrinterParameterized5
	add sp, #0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D10B0: .4byte 0x020399A8
_080D10B4: .4byte 0x00000CE6
	thumb_func_end Cb_HandleMovingMonFromParty

	thumb_func_start sub_080D10B8
sub_080D10B8: @ 0x080D10B8
	push {lr}
	ldr r0, _080D10E0
	ldr r0, [r0]
	ldr r1, _080D10E4
	adds r0, r0, r1
	movs r1, #0x15
	strh r1, [r0]
	ldr r1, _080D10E8
	movs r3, #0x9d
	lsls r3, r3, #1
	movs r0, #0
	movs r2, #0x80
	bl LoadBgTiles
	movs r0, #0
	bl sub_080D1254
	pop {r0}
	bx r0
	.align 2, 0
_080D10E0: .4byte 0x020399A8
_080D10E4: .4byte 0x00002236
_080D10E8: .4byte 0x08556620
	thumb_func_end sub_080D10B8

	thumb_func_start sub_080D10EC
sub_080D10EC: @ 0x080D10EC
	push {r4, r5, lr}
	sub sp, #0x10
	ldr r0, _080D1104
	ldr r0, [r0]
	ldr r2, _080D1108
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _080D110C
	movs r0, #0
	b _080D1172
	.align 2, 0
_080D1104: .4byte 0x020399A8
_080D1108: .4byte 0x00002236
_080D110C:
	subs r0, #1
	strh r0, [r1]
	ldrh r1, [r1]
	movs r0, #0x15
	subs r5, r0, r1
	movs r4, #0
	cmp r4, r5
	bge _080D115C
_080D111C:
	movs r0, #0
	movs r1, #0xa
	bl GetBgAttribute
	adds r1, r0, #0
	ldr r0, _080D117C
	ldr r0, [r0]
	ldr r2, _080D1180
	adds r0, r0, r2
	adds r1, #0x14
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	movs r0, #1
	str r0, [sp]
	movs r0, #7
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0x15
	str r0, [sp, #0xc]
	movs r0, #0
	movs r3, #0xd
	bl WriteSequenceToBgTilemapBuffer
	adds r4, #1
	cmp r4, r5
	blt _080D111C
_080D115C:
	adds r0, r5, #0
	bl sub_080D1254
	ldr r0, _080D117C
	ldr r0, [r0]
	ldr r1, _080D1180
	adds r0, r0, r1
	ldrh r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
_080D1172:
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080D117C: .4byte 0x020399A8
_080D1180: .4byte 0x00002236
	thumb_func_end sub_080D10EC

	thumb_func_start sub_080D1184
sub_080D1184: @ 0x080D1184
	push {r4, r5, lr}
	sub sp, #0x10
	ldr r5, _080D119C
	ldr r0, [r5]
	ldr r4, _080D11A0
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r0, #0x16
	bne _080D11A4
	movs r0, #0
	b _080D1244
	.align 2, 0
_080D119C: .4byte 0x020399A8
_080D11A0: .4byte 0x00002236
_080D11A4:
	cmp r0, #0
	bne _080D11C0
	movs r0, #1
	str r0, [sp]
	movs r0, #9
	str r0, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r2, #0x15
	movs r3, #0xc
	bl FillBgTilemapBufferRect
_080D11C0:
	ldr r1, [r5]
	adds r1, r1, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldrh r1, [r1]
	movs r0, #0x15
	subs r5, r0, r1
	movs r4, #0
	cmp r4, r5
	bge _080D1216
_080D11D6:
	movs r0, #0
	movs r1, #0xa
	bl GetBgAttribute
	adds r1, r0, #0
	ldr r0, _080D124C
	ldr r0, [r0]
	ldr r2, _080D1250
	adds r0, r0, r2
	adds r1, #0x14
	ldrh r0, [r0]
	adds r1, r1, r0
	adds r1, r1, r4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	movs r0, #1
	str r0, [sp]
	movs r0, #7
	str r0, [sp, #4]
	movs r0, #0xf
	str r0, [sp, #8]
	movs r0, #0x15
	str r0, [sp, #0xc]
	movs r0, #0
	movs r3, #0xd
	bl WriteSequenceToBgTilemapBuffer
	adds r4, #1
	cmp r4, r5
	blt _080D11D6
_080D1216:
	cmp r5, #0
	blt _080D1220
	adds r0, r5, #0
	bl sub_080D1254
_080D1220:
	adds r2, r5, #1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #1
	str r0, [sp]
	movs r0, #9
	str r0, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0xc
	bl FillBgTilemapBufferRect
	movs r0, #0
	bl ScheduleBgCopyTilemapToVram
	movs r0, #1
_080D1244:
	add sp, #0x10
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080D124C: .4byte 0x020399A8
_080D1250: .4byte 0x00002236
	thumb_func_end sub_080D1184

	thumb_func_start sub_080D1254
sub_080D1254: @ 0x080D1254
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r7, r0, #0
	cmp r7, #0
	beq _080D128C
	movs r1, #0x9d
	lsls r1, r1, #1
	lsls r4, r7, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	movs r6, #1
	str r6, [sp, #4]
	movs r5, #0xf
	str r5, [sp, #8]
	movs r0, #0
	movs r2, #0
	movs r3, #0xc
	bl FillBgTilemapBufferRect
	ldr r1, _080D12DC
	str r4, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	movs r0, #0
	movs r2, #0
	movs r3, #0x14
	bl FillBgTilemapBufferRect
_080D128C:
	ldr r1, _080D12E0
	lsls r5, r7, #0x18
	lsrs r5, r5, #0x18
	movs r4, #1
	str r4, [sp]
	movs r0, #7
	str r0, [sp, #4]
	movs r6, #0xf
	str r6, [sp, #8]
	movs r0, #0
	adds r2, r5, #0
	movs r3, #0xd
	bl FillBgTilemapBufferRect
	movs r1, #0x9e
	lsls r1, r1, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	adds r2, r5, #0
	movs r3, #0xc
	bl FillBgTilemapBufferRect
	ldr r1, _080D12E4
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	movs r0, #0
	adds r2, r5, #0
	movs r3, #0x14
	bl FillBgTilemapBufferRect
	movs r0, #0
	bl ScheduleBgCopyTilemapToVram
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D12DC: .4byte 0x0000093A
_080D12E0: .4byte 0x0000013B
_080D12E4: .4byte 0x0000013D
	thumb_func_end sub_080D1254

	thumb_func_start sub_080D12E8
sub_080D12E8: @ 0x080D12E8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x3f
	ldrb r1, [r0]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080D1308
	ldrh r0, [r4, #0x2e]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl sub_080D0FE0
	ldr r0, _080D1310
	str r0, [r4, #0x1c]
_080D1308:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D1310: .4byte 0x08007141
	thumb_func_end sub_080D12E8

	thumb_func_start sub_080D1314
sub_080D1314: @ 0x080D1314
	push {lr}
	adds r3, r0, #0
	movs r0, #0x2e
	ldrsh r1, [r3, r0]
	cmp r1, #0
	beq _080D1326
	cmp r1, #1
	beq _080D1342
	b _080D1370
_080D1326:
	ldrh r0, [r3, #0x20]
	lsls r0, r0, #4
	strh r0, [r3, #0x30]
	ldrh r0, [r3, #0x22]
	lsls r0, r0, #4
	strh r0, [r3, #0x32]
	movs r0, #0xa
	strh r0, [r3, #0x34]
	movs r0, #0x15
	strh r0, [r3, #0x36]
	strh r1, [r3, #0x38]
	ldrh r0, [r3, #0x2e]
	adds r0, #1
	strh r0, [r3, #0x2e]
_080D1342:
	ldrh r1, [r3, #0x30]
	ldrh r0, [r3, #0x34]
	subs r1, r1, r0
	strh r1, [r3, #0x30]
	ldrh r0, [r3, #0x32]
	ldrh r2, [r3, #0x36]
	subs r0, r0, r2
	strh r0, [r3, #0x32]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	strh r1, [r3, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r3, #0x22]
	ldrh r0, [r3, #0x38]
	adds r0, #1
	strh r0, [r3, #0x38]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _080D1370
	ldr r0, _080D1374
	str r0, [r3, #0x1c]
_080D1370:
	pop {r0}
	bx r0
	.align 2, 0
_080D1374: .4byte 0x080D1379
	thumb_func_end sub_080D1314

	thumb_func_start sub_080D1378
sub_080D1378: @ 0x080D1378
	ldr r1, _080D13AC
	ldr r3, [r1]
	ldr r1, _080D13B0
	adds r3, r3, r1
	ldr r1, [r3]
	ldrh r1, [r1, #0x20]
	adds r1, #4
	strh r1, [r0, #0x20]
	ldr r2, [r3]
	ldrh r1, [r2, #0x26]
	ldrh r2, [r2, #0x22]
	adds r1, r1, r2
	adds r1, #8
	strh r1, [r0, #0x22]
	ldr r1, [r3]
	ldrb r1, [r1, #5]
	movs r2, #0xc
	ands r2, r1
	ldrb r3, [r0, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	ands r1, r3
	orrs r1, r2
	strb r1, [r0, #5]
	bx lr
	.align 2, 0
_080D13AC: .4byte 0x020399A8
_080D13B0: .4byte 0x00000CB4
	thumb_func_end sub_080D1378

	thumb_func_start sub_080D13B4
sub_080D13B4: @ 0x080D13B4
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	cmp r1, #0
	beq _080D13C6
	cmp r1, #1
	beq _080D13E2
	b _080D142A
_080D13C6:
	ldrh r0, [r4, #0x20]
	lsls r0, r0, #4
	strh r0, [r4, #0x30]
	ldrh r0, [r4, #0x22]
	lsls r0, r0, #4
	strh r0, [r4, #0x32]
	movs r0, #0xa
	strh r0, [r4, #0x34]
	movs r0, #0x15
	strh r0, [r4, #0x36]
	strh r1, [r4, #0x38]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
_080D13E2:
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x30]
	adds r0, r0, r1
	strh r0, [r4, #0x30]
	ldrh r1, [r4, #0x36]
	ldrh r2, [r4, #0x32]
	adds r1, r1, r2
	strh r1, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r4, #0x20]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	strh r1, [r4, #0x22]
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _080D142A
	adds r0, r4, #0
	bl sub_080D0C64
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r4, #0x3a]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4, #0x3c]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	bl sub_080D0CAC
	ldr r0, _080D1430
	str r0, [r4, #0x1c]
_080D142A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D1430: .4byte 0x08007141
	thumb_func_end sub_080D13B4

	thumb_func_start sub_080D1434
sub_080D1434: @ 0x080D1434
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	cmp r1, #0
	beq _080D1446
	cmp r1, #1
	beq _080D1462
	b _080D14C0
_080D1446:
	ldrh r0, [r4, #0x20]
	lsls r0, r0, #4
	strh r0, [r4, #0x30]
	ldrh r0, [r4, #0x22]
	lsls r0, r0, #4
	strh r0, [r4, #0x32]
	movs r0, #0xa
	strh r0, [r4, #0x34]
	movs r0, #0x15
	strh r0, [r4, #0x36]
	strh r1, [r4, #0x38]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
_080D1462:
	ldrh r1, [r4, #0x30]
	ldrh r0, [r4, #0x34]
	subs r1, r1, r0
	strh r1, [r4, #0x30]
	ldrh r0, [r4, #0x32]
	ldrh r2, [r4, #0x36]
	subs r0, r0, r2
	strh r0, [r4, #0x32]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	strh r1, [r4, #0x20]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r4, #0x22]
	ldr r1, _080D14C8
	movs r2, #0x38
	ldrsh r0, [r4, r2]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _080D14C0
	adds r0, r4, #0
	bl sub_080D0C64
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r4, #0x3a]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4, #0x3c]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	bl sub_080D0CAC
	movs r0, #0
	strh r0, [r4, #0x24]
	ldr r0, _080D14CC
	str r0, [r4, #0x1c]
_080D14C0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D14C8: .4byte 0x082FA8CC
_080D14CC: .4byte 0x080D1379
	thumb_func_end sub_080D1434

	thumb_func_start sub_080D14D0
sub_080D14D0: @ 0x080D14D0
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x2e
	ldrsh r1, [r4, r0]
	cmp r1, #0
	beq _080D14E2
	cmp r1, #1
	beq _080D14FE
	b _080D155E
_080D14E2:
	ldrh r0, [r4, #0x20]
	lsls r0, r0, #4
	strh r0, [r4, #0x30]
	ldrh r0, [r4, #0x22]
	lsls r0, r0, #4
	strh r0, [r4, #0x32]
	movs r0, #0xa
	strh r0, [r4, #0x34]
	movs r0, #0x15
	strh r0, [r4, #0x36]
	strh r1, [r4, #0x38]
	ldrh r0, [r4, #0x2e]
	adds r0, #1
	strh r0, [r4, #0x2e]
_080D14FE:
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x30]
	adds r0, r0, r1
	strh r0, [r4, #0x30]
	ldrh r1, [r4, #0x36]
	ldrh r2, [r4, #0x32]
	adds r1, r1, r2
	strh r1, [r4, #0x32]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	strh r0, [r4, #0x20]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x14
	strh r1, [r4, #0x22]
	ldr r1, _080D1564
	movs r2, #0x38
	ldrsh r0, [r4, r2]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x14
	rsbs r0, r0, #0
	strh r0, [r4, #0x24]
	ldrh r0, [r4, #0x38]
	adds r0, #1
	strh r0, [r4, #0x38]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xb
	ble _080D155E
	adds r0, r4, #0
	bl sub_080D0C64
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrh r1, [r4, #0x3a]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4, #0x3c]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	bl sub_080D0CAC
	ldr r0, _080D1568
	str r0, [r4, #0x1c]
	movs r0, #0
	strh r0, [r4, #0x24]
_080D155E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D1564: .4byte 0x082FA8CC
_080D1568: .4byte 0x08007141
	thumb_func_end sub_080D14D0

	thumb_func_start sub_080D156C
sub_080D156C: @ 0x080D156C
	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #0x22]
	subs r0, #8
	strh r0, [r2, #0x22]
	movs r1, #0x22
	ldrsh r0, [r2, r1]
	movs r3, #0x26
	ldrsh r1, [r2, r3]
	adds r0, r0, r1
	movs r1, #0x10
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080D159C
	ldr r0, _080D15A0
	str r0, [r2, #0x1c]
	adds r0, r2, #0
	bl sub_080D0C64
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl sub_080D0FE0
_080D159C:
	pop {r0}
	bx r0
	.align 2, 0
_080D15A0: .4byte 0x08007141
	thumb_func_end sub_080D156C

	thumb_func_start nullsub_98
nullsub_98: @ 0x080D15A4
	bx lr
	.align 2, 0
	thumb_func_end nullsub_98

	thumb_func_start nullsub_pss
nullsub_pss: @ 0x080D15A8
	bx lr
	.align 2, 0
	thumb_func_end nullsub_pss

	thumb_func_start StorageGetCurrentBox
StorageGetCurrentBox: @ 0x080D15AC
	ldr r0, _080D15B4
	ldr r0, [r0]
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080D15B4: .4byte 0x03005AF4
	thumb_func_end StorageGetCurrentBox

	thumb_func_start SetCurrentBox
SetCurrentBox: @ 0x080D15B8
	push {lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xd
	bhi _080D15C8
	ldr r0, _080D15CC
	ldr r0, [r0]
	strb r1, [r0]
_080D15C8:
	pop {r0}
	bx r0
	.align 2, 0
_080D15CC: .4byte 0x03005AF4
	thumb_func_end SetCurrentBox

	thumb_func_start GetBoxMonDataAt
GetBoxMonDataAt: @ 0x080D15D0
	push {r4, r5, lr}
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r3, #0xd
	bhi _080D160C
	cmp r4, #0x1d
	bhi _080D160C
	ldr r2, _080D1608
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, #4
	ldr r0, [r2]
	adds r0, r0, r1
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r1, r5, #0
	bl GetBoxMonData
	b _080D160E
	.align 2, 0
_080D1608: .4byte 0x03005AF4
_080D160C:
	movs r0, #0
_080D160E:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end GetBoxMonDataAt

	thumb_func_start SetBoxMonDataAt
SetBoxMonDataAt: @ 0x080D1614
	push {r4, r5, r6, lr}
	adds r5, r2, #0
	adds r6, r3, #0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r3, #0xd
	bhi _080D164C
	cmp r4, #0x1d
	bhi _080D164C
	ldr r2, _080D1654
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, #4
	ldr r0, [r2]
	adds r0, r0, r1
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r1, r5, #0
	adds r2, r6, #0
	bl SetBoxMonData
_080D164C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D1654: .4byte 0x03005AF4
	thumb_func_end SetBoxMonDataAt

	thumb_func_start GetCurrentBoxMonData
GetCurrentBoxMonData: @ 0x080D1658
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, _080D1674
	ldr r0, [r0]
	ldrb r0, [r0]
	adds r1, r3, #0
	bl GetBoxMonDataAt
	pop {r1}
	bx r1
	.align 2, 0
_080D1674: .4byte 0x03005AF4
	thumb_func_end GetCurrentBoxMonData

	thumb_func_start SetCurrentBoxMonData
SetCurrentBoxMonData: @ 0x080D1678
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r0, _080D1698
	ldr r0, [r0]
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r2, r5, #0
	bl SetBoxMonDataAt
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D1698: .4byte 0x03005AF4
	thumb_func_end SetCurrentBoxMonData

	thumb_func_start GetBoxMonNickAt
GetBoxMonNickAt: @ 0x080D169C
	push {r4, r5, lr}
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r3, #0xd
	bhi _080D16D8
	cmp r4, #0x1d
	bhi _080D16D8
	ldr r2, _080D16D4
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, #4
	ldr r0, [r2]
	adds r0, r0, r1
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #2
	adds r2, r5, #0
	bl GetBoxMonData
	b _080D16DC
	.align 2, 0
_080D16D4: .4byte 0x03005AF4
_080D16D8:
	movs r0, #0xff
	strb r0, [r5]
_080D16DC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end GetBoxMonNickAt

	thumb_func_start GetBoxMonLevelAt
GetBoxMonLevelAt: @ 0x080D16E4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r0, #0xd
	bhi _080D1724
	cmp r2, #0x1d
	bhi _080D1724
	ldr r6, _080D172C
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r5, r0, #4
	ldr r0, [r6]
	adds r0, r0, r5
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r4, r1, #4
	adds r0, r0, r4
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1724
	ldr r0, [r6]
	adds r0, r0, r5
	adds r0, r0, r4
	bl GetLevelFromBoxMonExp
_080D1724:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080D172C: .4byte 0x03005AF4
	thumb_func_end GetBoxMonLevelAt

	thumb_func_start SetBoxMonNickAt
SetBoxMonNickAt: @ 0x080D1730
	push {r4, r5, lr}
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r3, #0xd
	bhi _080D1766
	cmp r4, #0x1d
	bhi _080D1766
	ldr r2, _080D176C
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, #4
	ldr r0, [r2]
	adds r0, r0, r1
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #2
	adds r2, r5, #0
	bl SetBoxMonData
_080D1766:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D176C: .4byte 0x03005AF4
	thumb_func_end SetBoxMonNickAt

	thumb_func_start GetAndCopyBoxMonDataAt
GetAndCopyBoxMonDataAt: @ 0x080D1770
	push {r4, r5, r6, lr}
	adds r5, r2, #0
	adds r6, r3, #0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r3, #0xd
	bhi _080D17B0
	cmp r4, #0x1d
	bhi _080D17B0
	ldr r2, _080D17AC
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, #4
	ldr r0, [r2]
	adds r0, r0, r1
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r1, r5, #0
	adds r2, r6, #0
	bl GetBoxMonData
	b _080D17B2
	.align 2, 0
_080D17AC: .4byte 0x03005AF4
_080D17B0:
	movs r0, #0
_080D17B2:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end GetAndCopyBoxMonDataAt

	thumb_func_start SetBoxMonAt
SetBoxMonAt: @ 0x080D17B8
	push {r4, r5, lr}
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r4, #0xd
	bhi _080D17EE
	cmp r1, #0x1d
	bhi _080D17EE
	ldr r0, _080D17F4
	ldr r0, [r0]
	lsls r3, r1, #2
	adds r3, r3, r1
	lsls r3, r3, #4
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #5
	adds r3, r3, r1
	adds r0, r0, r3
	adds r0, #4
	adds r1, r5, #0
	movs r2, #0x50
	bl memcpy
_080D17EE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D17F4: .4byte 0x03005AF4
	thumb_func_end SetBoxMonAt

	thumb_func_start CopyBoxMonAt
CopyBoxMonAt: @ 0x080D17F8
	push {r4, r5, lr}
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r2, r1, #0x18
	cmp r4, #0xd
	bhi _080D182E
	cmp r2, #0x1d
	bhi _080D182E
	ldr r0, _080D1834
	ldr r1, [r0]
	lsls r3, r2, #2
	adds r3, r3, r2
	lsls r3, r3, #4
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r0, r2, #4
	subs r0, r0, r2
	lsls r0, r0, #5
	adds r3, r3, r0
	adds r1, r1, r3
	adds r1, #4
	adds r0, r5, #0
	movs r2, #0x50
	bl memcpy
_080D182E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D1834: .4byte 0x03005AF4
	thumb_func_end CopyBoxMonAt

	thumb_func_start CreateBoxMonAt
CreateBoxMonAt: @ 0x080D1838
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	ldr r4, [sp, #0x30]
	ldr r5, [sp, #0x34]
	ldr r6, [sp, #0x3c]
	mov ip, r6
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov sb, r2
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r8, r3
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	mov r0, ip
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r7, #0xd
	bhi _080D18A4
	cmp r6, #0x1d
	bhi _080D18A4
	ldr r2, _080D18B4
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, #4
	ldr r0, [r2]
	adds r0, r0, r1
	lsls r1, r6, #2
	adds r1, r1, r6
	lsls r1, r1, #4
	adds r0, r0, r1
	str r5, [sp]
	ldr r1, [sp, #0x38]
	str r1, [sp, #4]
	str r3, [sp, #8]
	ldr r1, [sp, #0x40]
	str r1, [sp, #0xc]
	mov r1, sb
	mov r2, r8
	adds r3, r4, #0
	bl CreateBoxMon
_080D18A4:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D18B4: .4byte 0x03005AF4
	thumb_func_end CreateBoxMonAt

	thumb_func_start ZeroBoxMonAt
ZeroBoxMonAt: @ 0x080D18B8
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r3, #0xd
	bhi _080D18E8
	cmp r4, #0x1d
	bhi _080D18E8
	ldr r2, _080D18F0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, #4
	ldr r0, [r2]
	adds r0, r0, r1
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #4
	adds r0, r0, r1
	bl ZeroBoxMonData
_080D18E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D18F0: .4byte 0x03005AF4
	thumb_func_end ZeroBoxMonAt

	thumb_func_start BoxMonAtToMon
BoxMonAtToMon: @ 0x080D18F4
	push {r4, r5, lr}
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r3, #0xd
	bhi _080D1928
	cmp r4, #0x1d
	bhi _080D1928
	ldr r2, _080D1930
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, #4
	ldr r0, [r2]
	adds r0, r0, r1
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #4
	adds r0, r0, r1
	adds r1, r5, #0
	bl BoxMonToMon
_080D1928:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D1930: .4byte 0x03005AF4
	thumb_func_end BoxMonAtToMon

	thumb_func_start GetBoxedMonPtr
GetBoxedMonPtr: @ 0x080D1934
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	cmp r3, #0xd
	bhi _080D1968
	cmp r4, #0x1d
	bhi _080D1968
	ldr r2, _080D1964
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r1, r0, #4
	subs r1, r1, r0
	lsls r1, r1, #5
	adds r1, #4
	ldr r0, [r2]
	adds r0, r0, r1
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #4
	adds r0, r0, r1
	b _080D196A
	.align 2, 0
_080D1964: .4byte 0x03005AF4
_080D1968:
	movs r0, #0
_080D196A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetBoxedMonPtr

	thumb_func_start GetBoxNamePtr
GetBoxNamePtr: @ 0x080D1970
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xd
	bls _080D197E
	movs r0, #0
	b _080D198C
_080D197E:
	ldr r0, _080D1990
	lsls r1, r2, #3
	adds r1, r1, r2
	ldr r2, _080D1994
	adds r1, r1, r2
	ldr r0, [r0]
	adds r0, r0, r1
_080D198C:
	pop {r1}
	bx r1
	.align 2, 0
_080D1990: .4byte 0x03005AF4
_080D1994: .4byte 0x00008344
	thumb_func_end GetBoxNamePtr

	thumb_func_start GetBoxWallpaper
GetBoxWallpaper: @ 0x080D1998
	push {lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xd
	bls _080D19A6
	movs r0, #0
	b _080D19B2
_080D19A6:
	ldr r0, _080D19B8
	ldr r0, [r0]
	ldr r2, _080D19BC
	adds r0, r0, r2
	adds r0, r0, r1
	ldrb r0, [r0]
_080D19B2:
	pop {r1}
	bx r1
	.align 2, 0
_080D19B8: .4byte 0x03005AF4
_080D19BC: .4byte 0x000083C2
	thumb_func_end GetBoxWallpaper

	thumb_func_start SetBoxWallpaper
SetBoxWallpaper: @ 0x080D19C0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r2, #0xd
	bhi _080D19DE
	cmp r1, #0x10
	bhi _080D19DE
	ldr r0, _080D19E4
	ldr r0, [r0]
	ldr r3, _080D19E8
	adds r0, r0, r3
	adds r0, r0, r2
	strb r1, [r0]
_080D19DE:
	pop {r0}
	bx r0
	.align 2, 0
_080D19E4: .4byte 0x03005AF4
_080D19E8: .4byte 0x000083C2
	thumb_func_end SetBoxWallpaper

	thumb_func_start sub_080D19EC
sub_080D19EC: @ 0x080D19EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r4, r3, #0
	ldr r2, _080D1A50
	cmp r3, #1
	bhi _080D1A0E
	movs r2, #1
	cmp r3, #1
	beq _080D1A12
_080D1A0E:
	cmp r4, #3
	bne _080D1A5C
_080D1A12:
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	adds r1, r1, r0
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r6, r2, #0
	cmp r1, #0
	blt _080D1AA8
	cmp r1, r7
	bgt _080D1AA8
_080D1A2A:
	asrs r4, r0, #0x10
	lsls r0, r4, #2
	adds r0, r0, r4
	lsls r0, r0, #4
	add r0, r8
	movs r1, #0xb
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1A54
	asrs r0, r6, #0x10
	adds r0, r4, r0
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt _080D1AA8
	cmp r2, r7
	ble _080D1A2A
	b _080D1AA8
	.align 2, 0
_080D1A50: .4byte 0x0000FFFF
_080D1A54:
	adds r0, r4, #0
	b _080D1AAC
_080D1A58:
	adds r0, r5, #0
	b _080D1AAC
_080D1A5C:
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r2, r2, #0x10
	asrs r1, r2, #0x10
	adds r1, r1, r0
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	adds r6, r2, #0
	cmp r1, #0
	blt _080D1AA8
	cmp r1, r7
	bgt _080D1AA8
_080D1A74:
	asrs r5, r0, #0x10
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #4
	mov r1, r8
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xb
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1A98
	adds r0, r4, #0
	movs r1, #0x2d
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1A58
_080D1A98:
	asrs r0, r6, #0x10
	adds r0, r5, r0
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	blt _080D1AA8
	cmp r2, r7
	ble _080D1A74
_080D1AA8:
	movs r0, #1
	rsbs r0, r0, #0
_080D1AAC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080D19EC

	thumb_func_start CheckFreePokemonStorageSpace
CheckFreePokemonStorageSpace: @ 0x080D1AB8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	movs r2, #0
	ldr r0, _080D1AE8
	mov r8, r0
	movs r7, #4
_080D1AC8:
	movs r5, #0
	adds r6, r7, #0
	movs r4, #0
_080D1ACE:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r0, r6
	adds r0, r0, r4
	movs r1, #5
	str r2, [sp]
	bl GetBoxMonData
	ldr r2, [sp]
	cmp r0, #0
	bne _080D1AEC
	movs r0, #1
	b _080D1B02
	.align 2, 0
_080D1AE8: .4byte 0x03005AF4
_080D1AEC:
	adds r4, #0x50
	adds r5, #1
	cmp r5, #0x1d
	ble _080D1ACE
	movs r0, #0x96
	lsls r0, r0, #4
	adds r7, r7, r0
	adds r2, #1
	cmp r2, #0xd
	ble _080D1AC8
	movs r0, #0
_080D1B02:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end CheckFreePokemonStorageSpace

	thumb_func_start CheckBoxMonSanityAt
CheckBoxMonSanityAt: @ 0x080D1B10
	push {r4, r5, r6, lr}
	adds r2, r1, #0
	cmp r0, #0xd
	bhi _080D1B68
	cmp r2, #0x1d
	bhi _080D1B68
	ldr r6, _080D1B64
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r5, r0, #4
	ldr r0, [r6]
	adds r0, r0, r5
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r4, r1, #4
	adds r0, r0, r4
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1B68
	ldr r0, [r6]
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #6
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1B68
	ldr r0, [r6]
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #4
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1B68
	movs r0, #1
	b _080D1B6A
	.align 2, 0
_080D1B64: .4byte 0x03005AF4
_080D1B68:
	movs r0, #0
_080D1B6A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end CheckBoxMonSanityAt

	thumb_func_start CountStorageNonEggMons
CountStorageNonEggMons: @ 0x080D1B70
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	movs r0, #0
	ldr r1, _080D1BD8
	mov sb, r1
_080D1B80:
	lsls r1, r0, #2
	adds r2, r0, #1
	mov r8, r2
	adds r1, r1, r0
	movs r5, #0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r4, r0, #4
	movs r6, #0x1d
_080D1B94:
	mov r1, sb
	ldr r0, [r1]
	adds r0, r0, r4
	adds r0, r0, r5
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1BBA
	mov r2, sb
	ldr r0, [r2]
	adds r0, r0, r4
	adds r0, r0, r5
	movs r1, #6
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1BBA
	adds r7, #1
_080D1BBA:
	adds r5, #0x50
	subs r6, #1
	cmp r6, #0
	bge _080D1B94
	mov r0, r8
	cmp r0, #0xd
	ble _080D1B80
	adds r0, r7, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D1BD8: .4byte 0x03005AF4
	thumb_func_end CountStorageNonEggMons

	thumb_func_start CountAllStorageMons
CountAllStorageMons: @ 0x080D1BDC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	movs r0, #0
	ldr r1, _080D1C44
	mov sb, r1
_080D1BEC:
	lsls r1, r0, #2
	adds r2, r0, #1
	mov r8, r2
	adds r1, r1, r0
	movs r5, #0
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #5
	adds r4, r0, #4
	movs r6, #0x1d
_080D1C00:
	mov r1, sb
	ldr r0, [r1]
	adds r0, r0, r4
	adds r0, r0, r5
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1C24
	mov r2, sb
	ldr r0, [r2]
	adds r0, r0, r4
	adds r0, r0, r5
	movs r1, #6
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1C26
_080D1C24:
	adds r7, #1
_080D1C26:
	adds r5, #0x50
	subs r6, #1
	cmp r6, #0
	bge _080D1C00
	mov r0, r8
	cmp r0, #0xd
	ble _080D1BEC
	adds r0, r7, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D1C44: .4byte 0x03005AF4
	thumb_func_end CountAllStorageMons

	thumb_func_start AnyStorageMonWithMove
AnyStorageMonWithMove: @ 0x080D1C48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r1, sp
	strh r0, [r1]
	ldr r0, _080D1C9C
	strh r0, [r1, #2]
	movs r0, #0
	mov r8, r0
	ldr r7, _080D1CA0
	movs r5, #4
_080D1C60:
	movs r6, #0
	movs r4, #0
_080D1C64:
	ldr r0, [r7]
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #5
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1CA4
	ldr r0, [r7]
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #6
	bl GetBoxMonData
	cmp r0, #0
	bne _080D1CA4
	ldr r0, [r7]
	adds r0, r0, r5
	adds r0, r0, r4
	movs r1, #0x51
	mov r2, sp
	bl GetBoxMonData
	cmp r0, #0
	beq _080D1CA4
	movs r0, #1
	b _080D1CBE
	.align 2, 0
_080D1C9C: .4byte 0x00000163
_080D1CA0: .4byte 0x03005AF4
_080D1CA4:
	adds r4, #0x50
	adds r6, #1
	cmp r6, #0x1d
	ble _080D1C64
	movs r0, #0x96
	lsls r0, r0, #4
	adds r5, r5, r0
	movs r0, #1
	add r8, r0
	mov r0, r8
	cmp r0, #0xd
	ble _080D1C60
	movs r0, #0
_080D1CBE:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end AnyStorageMonWithMove

	thumb_func_start ResetWaldaWallpaper
ResetWaldaWallpaper: @ 0x080D1CCC
	ldr r2, _080D1D04
	ldr r0, [r2]
	ldr r1, _080D1D08
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	ldr r3, _080D1D0C
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r1, [r2]
	ldr r0, _080D1D10
	adds r2, r1, r0
	ldr r0, _080D1D14
	strh r0, [r2]
	subs r3, #0x14
	adds r2, r1, r3
	ldr r0, _080D1D18
	strh r0, [r2]
	ldr r0, _080D1D1C
	adds r1, r1, r0
	movs r0, #0xff
	strb r0, [r1]
	bx lr
	.align 2, 0
_080D1D04: .4byte 0x03005AEC
_080D1D08: .4byte 0x00003D84
_080D1D0C: .4byte 0x00003D85
_080D1D10: .4byte 0x00003D70
_080D1D14: .4byte 0x00007B35
_080D1D18: .4byte 0x00006186
_080D1D1C: .4byte 0x00003D74
	thumb_func_end ResetWaldaWallpaper

	thumb_func_start SetWaldaWallpaperLockedOrUnlocked
SetWaldaWallpaperLockedOrUnlocked: @ 0x080D1D20
	ldr r1, _080D1D2C
	ldr r1, [r1]
	ldr r2, _080D1D30
	adds r1, r1, r2
	strb r0, [r1]
	bx lr
	.align 2, 0
_080D1D2C: .4byte 0x03005AEC
_080D1D30: .4byte 0x00003D86
	thumb_func_end SetWaldaWallpaperLockedOrUnlocked

	thumb_func_start IsWaldaWallpaperUnlocked
IsWaldaWallpaperUnlocked: @ 0x080D1D34
	ldr r0, _080D1D40
	ldr r0, [r0]
	ldr r1, _080D1D44
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080D1D40: .4byte 0x03005AEC
_080D1D44: .4byte 0x00003D86
	thumb_func_end IsWaldaWallpaperUnlocked

	thumb_func_start sub_080D1D48
sub_080D1D48: @ 0x080D1D48
	ldr r0, _080D1D54
	ldr r0, [r0]
	ldr r1, _080D1D58
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080D1D54: .4byte 0x03005AEC
_080D1D58: .4byte 0x00003D85
	thumb_func_end sub_080D1D48

	thumb_func_start SetWaldaWallpaperPatternId
SetWaldaWallpaperPatternId: @ 0x080D1D5C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0xf
	bhi _080D1D70
	ldr r0, _080D1D74
	ldr r0, [r0]
	ldr r2, _080D1D78
	adds r0, r0, r2
	strb r1, [r0]
_080D1D70:
	pop {r0}
	bx r0
	.align 2, 0
_080D1D74: .4byte 0x03005AEC
_080D1D78: .4byte 0x00003D85
	thumb_func_end SetWaldaWallpaperPatternId

	thumb_func_start GetWaldaWallpaperIconId
GetWaldaWallpaperIconId: @ 0x080D1D7C
	ldr r0, _080D1D88
	ldr r0, [r0]
	ldr r1, _080D1D8C
	adds r0, r0, r1
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_080D1D88: .4byte 0x03005AEC
_080D1D8C: .4byte 0x00003D84
	thumb_func_end GetWaldaWallpaperIconId

	thumb_func_start SetWaldaWallpaperIconId
SetWaldaWallpaperIconId: @ 0x080D1D90
	push {lr}
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x1d
	bhi _080D1DA4
	ldr r0, _080D1DA8
	ldr r0, [r0]
	ldr r2, _080D1DAC
	adds r0, r0, r2
	strb r1, [r0]
_080D1DA4:
	pop {r0}
	bx r0
	.align 2, 0
_080D1DA8: .4byte 0x03005AEC
_080D1DAC: .4byte 0x00003D84
	thumb_func_end SetWaldaWallpaperIconId

	thumb_func_start sub_080D1DB0
sub_080D1DB0: @ 0x080D1DB0
	ldr r0, _080D1DBC
	ldr r0, [r0]
	ldr r1, _080D1DC0
	adds r0, r0, r1
	bx lr
	.align 2, 0
_080D1DBC: .4byte 0x03005AEC
_080D1DC0: .4byte 0x00003D70
	thumb_func_end sub_080D1DB0

	thumb_func_start SetWaldaWallpaperColors
SetWaldaWallpaperColors: @ 0x080D1DC4
	push {r4, lr}
	ldr r2, _080D1DDC
	ldr r2, [r2]
	ldr r4, _080D1DE0
	adds r3, r2, r4
	strh r0, [r3]
	ldr r0, _080D1DE4
	adds r2, r2, r0
	strh r1, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D1DDC: .4byte 0x03005AEC
_080D1DE0: .4byte 0x00003D70
_080D1DE4: .4byte 0x00003D72
	thumb_func_end SetWaldaWallpaperColors

	thumb_func_start GetWaldaPhrasePtr
GetWaldaPhrasePtr: @ 0x080D1DE8
	ldr r0, _080D1DF4
	ldr r0, [r0]
	ldr r1, _080D1DF8
	adds r0, r0, r1
	bx lr
	.align 2, 0
_080D1DF4: .4byte 0x03005AEC
_080D1DF8: .4byte 0x00003D74
	thumb_func_end GetWaldaPhrasePtr

	thumb_func_start SetWaldaPhrase
SetWaldaPhrase: @ 0x080D1DFC
	push {lr}
	adds r1, r0, #0
	ldr r0, _080D1E10
	ldr r0, [r0]
	ldr r2, _080D1E14
	adds r0, r0, r2
	bl StringCopy
	pop {r0}
	bx r0
	.align 2, 0
_080D1E10: .4byte 0x03005AEC
_080D1E14: .4byte 0x00003D74
	thumb_func_end SetWaldaPhrase

	thumb_func_start IsWaldaPhraseEmpty
IsWaldaPhraseEmpty: @ 0x080D1E18
	push {lr}
	movs r1, #0
	ldr r0, _080D1E34
	ldr r0, [r0]
	ldr r2, _080D1E38
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _080D1E2C
	movs r1, #1
_080D1E2C:
	adds r0, r1, #0
	pop {r1}
	bx r1
	.align 2, 0
_080D1E34: .4byte 0x03005AEC
_080D1E38: .4byte 0x00003D74
	thumb_func_end IsWaldaPhraseEmpty

	thumb_func_start sub_080D1E3C
sub_080D1E3C: @ 0x080D1E3C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r6, _080D1E88
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #4
	bl Alloc
	str r0, [r6]
	ldr r5, _080D1E8C
	movs r1, #0
	cmp r0, #0
	beq _080D1E5A
	adds r1, r4, #0
_080D1E5A:
	strh r1, [r5]
	movs r2, #0
	cmp r2, r1
	bhs _080D1E82
	movs r3, #0
	adds r4, r5, #0
_080D1E66:
	ldr r0, [r6]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r1, r0
	str r3, [r1, #0x18]
	adds r1, #0x2c
	strb r3, [r1]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	ldrh r0, [r4]
	cmp r2, r0
	blo _080D1E66
_080D1E82:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D1E88: .4byte 0x02039A24
_080D1E8C: .4byte 0x02039A28
	thumb_func_end sub_080D1E3C

	thumb_func_start sub_080D1E90
sub_080D1E90: @ 0x080D1E90
	push {lr}
	ldr r0, _080D1EA0
	ldr r0, [r0]
	bl Free
	pop {r0}
	bx r0
	.align 2, 0
_080D1EA0: .4byte 0x02039A24
	thumb_func_end sub_080D1E90

	thumb_func_start sub_080D1EA4
sub_080D1EA4: @ 0x080D1EA4
	push {r4, r5, lr}
	movs r4, #0
	ldr r0, _080D1EDC
	ldrh r0, [r0]
	cmp r4, r0
	bge _080D1ED4
	movs r5, #0
_080D1EB2:
	ldr r0, _080D1EE0
	ldr r0, [r0]
	adds r0, r5, r0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1EC8
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl sub_080D21B8
_080D1EC8:
	adds r5, #0x30
	adds r4, #1
	ldr r0, _080D1EDC
	ldrh r0, [r0]
	cmp r4, r0
	blt _080D1EB2
_080D1ED4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D1EDC: .4byte 0x02039A28
_080D1EE0: .4byte 0x02039A24
	thumb_func_end sub_080D1EA4

	thumb_func_start sub_080D1EE4
sub_080D1EE4: @ 0x080D1EE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r4, r2, #0
	ldr r2, [sp, #0x24]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	ldr r0, _080D1F7C
	ldrh r0, [r0]
	cmp r6, r0
	bhs _080D1FCC
	ldr r0, _080D1F80
	mov sb, r0
	ldr r0, [r0]
	lsls r1, r6, #1
	mov r8, r1
	adds r5, r1, r6
	lsls r5, r5, #4
	adds r0, r5, r0
	movs r1, #0
	str r1, [r0, #0x18]
	str r4, [r0, #0x1c]
	adds r0, #0x2b
	strb r7, [r0]
	mov r2, sb
	ldr r0, [r2]
	adds r0, r5, r0
	mov r3, sl
	strh r3, [r0, #0x24]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r0, #0x26]
	adds r0, r7, #0
	movs r1, #3
	bl GetBgAttribute
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r7, #0
	movs r1, #9
	bl GetBgAttribute
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r2, sb
	ldr r1, [r2]
	adds r5, r5, r1
	ldr r2, _080D1F84
	lsls r4, r4, #2
	lsls r1, r0, #4
	adds r4, r4, r1
	adds r4, r4, r2
	ldrh r1, [r4]
	strh r1, [r5, #0x20]
	ldrh r1, [r4, #2]
	strh r1, [r5, #0x22]
	mov r2, r8
	cmp r0, #0
	beq _080D1F88
	adds r1, r5, #0
	adds r1, #0x2a
	movs r0, #1
	b _080D1F8E
	.align 2, 0
_080D1F7C: .4byte 0x02039A28
_080D1F80: .4byte 0x02039A24
_080D1F84: .4byte 0x08556784
_080D1F88:
	adds r1, r5, #0
	adds r1, #0x2a
	movs r0, #2
_080D1F8E:
	strb r0, [r1]
	ldr r4, _080D1FDC
	ldr r1, [r4]
	adds r2, r2, r6
	lsls r2, r2, #4
	adds r1, r2, r1
	adds r0, r1, #0
	adds r0, #0x2a
	ldrb r0, [r0]
	mov r3, sl
	muls r3, r0, r3
	movs r0, #0
	strh r3, [r1, #0x28]
	mov r3, sl
	strh r3, [r1, #0x10]
	mov r5, sp
	ldrh r5, [r5]
	strh r5, [r1, #0x12]
	strh r0, [r1, #0xc]
	strh r0, [r1, #0xe]
	strh r0, [r1, #0x14]
	strh r0, [r1, #0x16]
	adds r0, r1, #0
	adds r0, #0xc
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldr r0, [r4]
	adds r2, r2, r0
	adds r2, #0x2c
	movs r0, #1
	strb r0, [r2]
_080D1FCC:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1FDC: .4byte 0x02039A24
	thumb_func_end sub_080D1EE4

	thumb_func_start sub_080D1FE0
sub_080D1FE0: @ 0x080D1FE0
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldr r0, _080D2008
	ldrh r0, [r0]
	cmp r2, r0
	bhs _080D2004
	ldr r0, _080D200C
	ldr r1, [r0]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #4
	adds r0, r0, r1
	str r3, [r0, #0x18]
	adds r0, #0x2c
	movs r1, #1
	strb r1, [r0]
_080D2004:
	pop {r0}
	bx r0
	.align 2, 0
_080D2008: .4byte 0x02039A28
_080D200C: .4byte 0x02039A24
	thumb_func_end sub_080D1FE0

	thumb_func_start sub_080D2010
sub_080D2010: @ 0x080D2010
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, _080D2044
	ldrh r0, [r0]
	cmp r3, r0
	bhs _080D203C
	ldr r0, _080D2048
	ldr r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r0, r0, r1
	strh r4, [r0, #0x14]
	strh r2, [r0, #0x16]
	adds r0, #0x2c
	movs r1, #1
	strb r1, [r0]
_080D203C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D2044: .4byte 0x02039A28
_080D2048: .4byte 0x02039A24
	thumb_func_end sub_080D2010

	thumb_func_start sub_080D204C
sub_080D204C: @ 0x080D204C
	push {r4, r5, r6, lr}
	ldr r4, [sp, #0x10]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _080D208C
	ldrh r0, [r0]
	cmp r5, r0
	bhs _080D2086
	ldr r0, _080D2090
	ldr r1, [r0]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #4
	adds r0, r0, r1
	strh r6, [r0, #0xc]
	strh r2, [r0, #0xe]
	strh r3, [r0, #0x10]
	strh r4, [r0, #0x12]
	adds r0, #0x2c
	movs r1, #1
	strb r1, [r0]
_080D2086:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D208C: .4byte 0x02039A28
_080D2090: .4byte 0x02039A24
	thumb_func_end sub_080D204C

	thumb_func_start sub_080D2094
sub_080D2094: @ 0x080D2094
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _080D20C0
	ldrh r0, [r0]
	cmp r5, r0
	blo _080D20AC
	b _080D21AE
_080D20AC:
	ldr r4, _080D20C4
	lsls r2, r5, #1
	cmp r1, #5
	bls _080D20B6
	b _080D21A0
_080D20B6:
	lsls r0, r1, #2
	ldr r1, _080D20C8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D20C0: .4byte 0x02039A28
_080D20C4: .4byte 0x02039A24
_080D20C8: .4byte 0x080D20CC
_080D20CC: @ jump table
	.4byte _080D20E4 @ case 0
	.4byte _080D2104 @ case 1
	.4byte _080D2128 @ case 2
	.4byte _080D2148 @ case 3
	.4byte _080D216C @ case 4
	.4byte _080D2188 @ case 5
_080D20E4:
	ldr r4, _080D2100
	ldr r0, [r4]
	lsls r3, r5, #1
	adds r1, r3, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r2, r6, #0x18
	asrs r2, r2, #0x18
	ldrh r0, [r1, #0x14]
	adds r0, r0, r2
	strh r0, [r1, #0x14]
	ldrh r0, [r1, #0x10]
	subs r0, r0, r2
	b _080D211E
	.align 2, 0
_080D2100: .4byte 0x02039A24
_080D2104:
	ldr r4, _080D2124
	ldr r0, [r4]
	lsls r3, r5, #1
	adds r1, r3, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r2, r6, #0x18
	asrs r2, r2, #0x18
	ldrh r0, [r1, #0xc]
	adds r0, r0, r2
	strh r0, [r1, #0xc]
	ldrh r0, [r1, #0x10]
	adds r0, r0, r2
_080D211E:
	strh r0, [r1, #0x10]
	adds r2, r3, #0
	b _080D21A0
	.align 2, 0
_080D2124: .4byte 0x02039A24
_080D2128:
	ldr r4, _080D2144
	ldr r0, [r4]
	lsls r3, r5, #1
	adds r1, r3, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r2, r6, #0x18
	asrs r2, r2, #0x18
	ldrh r0, [r1, #0x16]
	adds r0, r0, r2
	strh r0, [r1, #0x16]
	ldrh r0, [r1, #0x12]
	subs r0, r0, r2
	b _080D2162
	.align 2, 0
_080D2144: .4byte 0x02039A24
_080D2148:
	ldr r4, _080D2168
	ldr r0, [r4]
	lsls r3, r5, #1
	adds r1, r3, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r2, r6, #0x18
	asrs r2, r2, #0x18
	ldrh r0, [r1, #0xe]
	subs r0, r0, r2
	strh r0, [r1, #0xe]
	ldrh r0, [r1, #0x12]
	adds r0, r0, r2
_080D2162:
	strh r0, [r1, #0x12]
	adds r2, r3, #0
	b _080D21A0
	.align 2, 0
_080D2168: .4byte 0x02039A24
_080D216C:
	ldr r3, _080D2184
	ldr r0, [r3]
	lsls r2, r5, #1
	adds r1, r2, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	ldrh r4, [r1, #0x14]
	adds r0, r0, r4
	strh r0, [r1, #0x14]
	b _080D219E
	.align 2, 0
_080D2184: .4byte 0x02039A24
_080D2188:
	ldr r3, _080D21B4
	ldr r0, [r3]
	lsls r2, r5, #1
	adds r1, r2, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	ldrh r4, [r1, #0x16]
	adds r0, r0, r4
	strh r0, [r1, #0x16]
_080D219E:
	adds r4, r3, #0
_080D21A0:
	ldr r0, [r4]
	adds r1, r2, r5
	lsls r1, r1, #4
	adds r1, r1, r0
	adds r1, #0x2c
	movs r0, #1
	strb r0, [r1]
_080D21AE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D21B4: .4byte 0x02039A24
	thumb_func_end sub_080D2094

	thumb_func_start sub_080D21B8
sub_080D21B8: @ 0x080D21B8
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r6, r2, #0
	ldr r0, _080D21F8
	ldrh r0, [r0]
	cmp r2, r0
	bhs _080D21F2
	ldr r5, _080D21FC
	ldr r0, [r5]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r4, r1, #4
	adds r0, r4, r0
	ldr r0, [r0, #0x18]
	cmp r0, #0
	beq _080D21E0
	adds r0, r2, #0
	bl sub_080D2200
_080D21E0:
	adds r0, r6, #0
	bl sub_080D2298
	ldr r1, [r5]
	adds r1, r4, r1
	adds r0, r1, #0
	adds r0, #0xc
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
_080D21F2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D21F8: .4byte 0x02039A28
_080D21FC: .4byte 0x02039A24
	thumb_func_end sub_080D21B8

	thumb_func_start sub_080D2200
sub_080D2200: @ 0x080D2200
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r4, _080D2294
	ldr r1, [r4]
	lsls r5, r0, #1
	adds r0, r5, r0
	lsls r0, r0, #4
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x2a
	ldrb r3, [r1]
	ldrh r1, [r0, #0x20]
	adds r2, r3, #0
	muls r2, r1, r2
	mov sb, r2
	movs r6, #0xa
	ldrsh r1, [r0, r6]
	mov r2, sb
	muls r2, r1, r2
	ldr r1, [r0, #0x18]
	adds r1, r1, r2
	movs r6, #8
	ldrsh r2, [r0, r6]
	muls r2, r3, r2
	adds r7, r1, r2
	movs r6, #0
	ldrh r0, [r0, #6]
	cmp r6, r0
	bge _080D2284
	mov sl, r4
_080D224A:
	mov r0, sl
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, r4, #4
	adds r1, r4, r1
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	ldrb r2, [r1, #8]
	ldrb r3, [r1, #0xa]
	adds r3, r3, r6
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r1, [r1, #4]
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r7, #0
	bl CopyToBgTilemapBufferRect
	add r7, sb
	adds r6, #1
	mov r1, sl
	ldr r0, [r1]
	adds r4, r4, r0
	ldrh r4, [r4, #6]
	cmp r6, r4
	blt _080D224A
_080D2284:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2294: .4byte 0x02039A24
	thumb_func_end sub_080D2200

	thumb_func_start sub_080D2298
sub_080D2298: @ 0x080D2298
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r4, _080D232C
	ldr r1, [r4]
	lsls r5, r0, #1
	adds r0, r5, r0
	lsls r0, r0, #4
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x2a
	ldrb r3, [r1]
	ldrh r1, [r0, #0x24]
	adds r2, r3, #0
	muls r2, r1, r2
	mov sb, r2
	movs r6, #0xe
	ldrsh r1, [r0, r6]
	mov r2, sb
	muls r2, r1, r2
	ldr r1, [r0, #0x1c]
	adds r1, r1, r2
	movs r6, #0xc
	ldrsh r2, [r0, r6]
	muls r2, r3, r2
	adds r7, r1, r2
	movs r6, #0
	ldrh r0, [r0, #0x12]
	cmp r6, r0
	bge _080D231C
	mov sl, r4
_080D22E2:
	mov r0, sl
	ldr r1, [r0]
	mov r2, r8
	adds r4, r5, r2
	lsls r4, r4, #4
	adds r1, r4, r1
	adds r0, r1, #0
	adds r0, #0x2b
	ldrb r0, [r0]
	ldrb r2, [r1, #0x14]
	ldrb r3, [r1, #0x16]
	adds r3, r3, r6
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldrb r1, [r1, #0x10]
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r7, #0
	bl CopyToBgTilemapBufferRect
	add r7, sb
	adds r6, #1
	mov r1, sl
	ldr r0, [r1]
	adds r4, r4, r0
	ldrh r4, [r4, #0x12]
	cmp r6, r4
	blt _080D22E2
_080D231C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D232C: .4byte 0x02039A24
	thumb_func_end sub_080D2298

	thumb_func_start sub_080D2330
sub_080D2330: @ 0x080D2330
	ldr r3, _080D2340
	str r0, [r3]
	str r1, [r0]
	movs r1, #0
	strb r2, [r0, #5]
	strb r1, [r0, #4]
	bx lr
	.align 2, 0
_080D2340: .4byte 0x02039A2C
	thumb_func_end sub_080D2330

	thumb_func_start sub_080D2344
sub_080D2344: @ 0x080D2344
	push {r4, r5, lr}
	ldr r2, _080D2388
	ldr r1, [r2]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _080D2382
	movs r4, #0
	ldrb r1, [r1, #4]
	cmp r4, r1
	bhs _080D237A
	adds r5, r2, #0
_080D235A:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #2
	ldr r0, [r0]
	adds r0, r0, r1
	ldr r1, [r0, #0x10]
	bl _call_via_r1
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, [r5]
	ldrb r0, [r0, #4]
	cmp r4, r0
	blo _080D235A
_080D237A:
	ldr r0, _080D2388
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1, #4]
_080D2382:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D2388: .4byte 0x02039A2C
	thumb_func_end sub_080D2344

	thumb_func_start sub_080D238C
sub_080D238C: @ 0x080D238C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r0
	mov sl, r3
	ldr r0, [sp, #0x24]
	ldr r3, [sp, #0x28]
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x34]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov ip, r1
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r0, _080D240C
	ldr r2, [r0]
	ldrb r0, [r2, #4]
	adds r1, r0, #0
	ldrb r7, [r2, #5]
	cmp r1, r7
	bhs _080D2414
	adds r0, #1
	strb r0, [r2, #4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r2]
	adds r1, r1, r0
	lsls r0, r4, #1
	strh r0, [r1, #8]
	ldr r2, [sp]
	lsls r0, r2, #5
	add r0, ip
	lsls r0, r0, #1
	add r0, sb
	str r0, [r1, #4]
	adds r0, r3, #0
	muls r0, r6, r0
	add r0, r8
	lsls r0, r0, #1
	add r0, sl
	str r0, [r1]
	strh r5, [r1, #0xc]
	strh r6, [r1, #0xa]
	ldr r0, _080D2410
	str r0, [r1, #0x10]
	movs r0, #1
	b _080D2416
	.align 2, 0
_080D240C: .4byte 0x02039A2C
_080D2410: .4byte 0x080D2429
_080D2414:
	movs r0, #0
_080D2416:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_080D238C

	thumb_func_start sub_080D2428
sub_080D2428: @ 0x080D2428
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _080D2452
_080D2430:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	ldrh r2, [r4, #8]
	lsrs r2, r2, #1
	bl CpuSet
	ldr r0, [r4, #4]
	adds r0, #0x40
	str r0, [r4, #4]
	ldrh r1, [r4, #0xa]
	lsls r1, r1, #1
	ldr r0, [r4]
	adds r0, r0, r1
	str r0, [r4]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_080D2452:
	ldrh r0, [r4, #0xc]
	cmp r5, r0
	blo _080D2430
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080D2428

	thumb_func_start sub_080D2460
sub_080D2460: @ 0x080D2460
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r0, [sp, #0x14]
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _080D24AC
	ldr r2, [r0]
	ldrb r0, [r2, #4]
	adds r1, r0, #0
	ldrb r7, [r2, #5]
	cmp r1, r7
	bhs _080D24B4
	adds r0, #1
	strb r0, [r2, #4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, [r2]
	adds r1, r1, r0
	lsls r0, r3, #1
	strh r0, [r1, #8]
	lsls r0, r4, #5
	adds r0, r0, r6
	lsls r0, r0, #1
	add r0, ip
	str r0, [r1, #4]
	strh r5, [r1, #0xc]
	ldr r0, _080D24B0
	str r0, [r1, #0x10]
	movs r0, #1
	b _080D24B6
	.align 2, 0
_080D24AC: .4byte 0x02039A2C
_080D24B0: .4byte 0x080D24BD
_080D24B4:
	movs r0, #0
_080D24B6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_080D2460

	thumb_func_start sub_080D24BC
sub_080D24BC: @ 0x080D24BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0
	ldrh r1, [r6, #0xc]
	cmp r0, r1
	bhs _080D254A
	movs r7, #0x80
	lsls r7, r7, #5
	mov r5, sp
	ldr r2, _080D2508
	mov r8, r2
	movs r1, #0x81
	lsls r1, r1, #0x18
	mov sl, r1
_080D24E2:
	ldr r2, [r6, #4]
	ldrh r3, [r6, #8]
	mov ip, r2
	adds r0, #1
	mov sb, r0
	cmp r3, r7
	bhi _080D250C
	movs r0, #0
	strh r0, [r5]
	mov r2, sp
	mov r0, r8
	str r2, [r0]
	mov r1, ip
	str r1, [r0, #4]
	lsrs r0, r3, #1
	mov r2, sl
	orrs r0, r2
	mov r1, r8
	b _080D2534
	.align 2, 0
_080D2508: .4byte 0x040000D4
_080D250C:
	movs r4, #0
	strh r4, [r5]
	ldr r1, _080D255C
	mov r0, sp
	str r0, [r1]
	str r2, [r1, #4]
	ldr r0, _080D2560
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r2, r2, r7
	subs r3, r3, r7
	cmp r3, r7
	bhi _080D250C
	strh r4, [r5]
	mov r0, sp
	str r0, [r1]
	str r2, [r1, #4]
	lsrs r0, r3, #1
	mov r2, sl
	orrs r0, r2
_080D2534:
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	mov r0, ip
	adds r0, #0x40
	str r0, [r6, #4]
	mov r1, sb
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	ldrh r2, [r6, #0xc]
	cmp r0, r2
	blo _080D24E2
_080D254A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D255C: .4byte 0x040000D4
_080D2560: .4byte 0x81000800
	thumb_func_end sub_080D24BC
