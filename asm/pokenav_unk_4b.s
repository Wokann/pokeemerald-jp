.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start LoopedTask_TransitionMons
LoopedTask_TransitionMons: @ 0x081CDADC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0xc
	bl GetSubstructPtr
	adds r6, r0, #0
	bl GetConditionGraphPtr
	adds r2, r0, #0
	cmp r4, #9
	bls _081CDAF4
	b _081CDC30
_081CDAF4:
	lsls r0, r4, #2
	ldr r1, _081CDB00
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CDB00: .4byte 0x081CDB04
_081CDB04: @ jump table
	.4byte _081CDB2C @ case 0
	.4byte _081CDB30 @ case 1
	.4byte _081CDB3A @ case 2
	.4byte _081CDB50 @ case 3
	.4byte _081CDB58 @ case 4
	.4byte _081CDB78 @ case 5
	.4byte _081CDB88 @ case 6
	.4byte _081CDB98 @ case 7
	.4byte _081CDBAE @ case 8
	.4byte _081CDBC8 @ case 9
_081CDB2C:
	movs r0, #0
	b _081CDB32
_081CDB30:
	movs r0, #1
_081CDB32:
	bl LoadNextConditionMenuMonData
_081CDB36:
	movs r0, #1
	b _081CDC32
_081CDB3A:
	movs r0, #2
	bl LoadNextConditionMenuMonData
	ldr r1, _081CDB4C
	adds r0, r6, r1
	bl DestroyConditionSparkleSprites
	b _081CDB36
	.align 2, 0
_081CDB4C: .4byte 0x000028E0
_081CDB50:
	adds r0, r2, #0
	bl ConditionGraph_TryUpdate
	b _081CDB36
_081CDB58:
	ldr r1, _081CDB74
	adds r0, r6, r1
	bl MoveConditionMonOffscreen
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDC2C
	bl GetConditionGraphMenuCurrentLoadIndex
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl CreateConditionMonPic
	b _081CDB36
	.align 2, 0
_081CDB74: .4byte 0x00001814
_081CDB78:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #0
	b _081CDBA6
_081CDB88:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #1
	b _081CDBA6
_081CDB98:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #2
_081CDBA6:
	movs r2, #0
	bl sub_081CDEB4
	b _081CDB36
_081CDBAE:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #3
	movs r2, #0
	bl sub_081CDEB4
	cmp r0, #1
	beq _081CDB36
	b _081CDC2C
_081CDBC8:
	bl GetConditionGraphPtr
	adds r2, r0, #0
	ldr r0, _081CDC20
	adds r1, r6, r0
	adds r0, r2, #0
	bl ConditionMenu_UpdateMonEnter
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDC2C
	ldr r1, _081CDC24
	adds r0, r6, r1
	bl ResetConditionSparkleSprites
	bl IsConditionMenuSearchMode
	cmp r0, #1
	beq _081CDC00
	bl GetConditionGraphCurrentListIndex
	adds r4, r0, #0
	bl GetMonListCount
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	cmp r4, r0
	beq _081CDB36
_081CDC00:
	ldr r0, _081CDC24
	adds r5, r6, r0
	ldr r1, _081CDC28
	adds r0, r6, r1
	ldrb r4, [r0]
	bl GetNumConditionMonSparkles
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl CreateConditionSparkleSprites
	b _081CDB36
	.align 2, 0
_081CDC20: .4byte 0x00001814
_081CDC24: .4byte 0x000028E0
_081CDC28: .4byte 0x00001816
_081CDC2C:
	movs r0, #2
	b _081CDC32
_081CDC30:
	movs r0, #4
_081CDC32:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end LoopedTask_TransitionMons

	thumb_func_start LoopedTask_MoveCursorNoTransition
LoopedTask_MoveCursorNoTransition: @ 0x081CDC38
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xc
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #8
	bhi _081CDD3C
	lsls r0, r4, #2
	ldr r1, _081CDC54
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CDC54: .4byte 0x081CDC58
_081CDC58: @ jump table
	.4byte _081CDC7C @ case 0
	.4byte _081CDC80 @ case 1
	.4byte _081CDC84 @ case 2
	.4byte _081CDC8E @ case 3
	.4byte _081CDC9E @ case 4
	.4byte _081CDCAE @ case 5
	.4byte _081CDCBE @ case 6
	.4byte _081CDCD6 @ case 7
	.4byte _081CDCF2 @ case 8
_081CDC7C:
	movs r0, #0
	b _081CDC86
_081CDC80:
	movs r0, #1
	b _081CDC86
_081CDC84:
	movs r0, #2
_081CDC86:
	bl LoadNextConditionMenuMonData
	movs r0, #1
	b _081CDD3E
_081CDC8E:
	bl GetConditionGraphMenuCurrentLoadIndex
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl CreateConditionMonPic
	movs r0, #1
	b _081CDD3E
_081CDC9E:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #0
	b _081CDCCC
_081CDCAE:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #1
	b _081CDCCC
_081CDCBE:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #2
_081CDCCC:
	movs r2, #0
	bl sub_081CDEB4
	movs r0, #1
	b _081CDD3E
_081CDCD6:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #3
	movs r2, #0
	bl sub_081CDEB4
	cmp r0, #1
	bne _081CDD38
	movs r0, #1
	b _081CDD3E
_081CDCF2:
	bl GetConditionGraphPtr
	ldr r2, _081CDD2C
	adds r1, r5, r2
	bl ConditionMenu_UpdateMonEnter
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDD38
	ldr r0, _081CDD30
	adds r4, r5, r0
	adds r0, r4, #0
	bl ResetConditionSparkleSprites
	ldr r1, _081CDD34
	adds r0, r5, r1
	ldrb r5, [r0]
	bl GetNumConditionMonSparkles
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	bl CreateConditionSparkleSprites
	movs r0, #1
	b _081CDD3E
	.align 2, 0
_081CDD2C: .4byte 0x00001814
_081CDD30: .4byte 0x000028E0
_081CDD34: .4byte 0x00001816
_081CDD38:
	movs r0, #2
	b _081CDD3E
_081CDD3C:
	movs r0, #4
_081CDD3E:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end LoopedTask_MoveCursorNoTransition

	thumb_func_start LoopedTask_SlideMonOut
LoopedTask_SlideMonOut: @ 0x081CDD44
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xc
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #7
	bhi _081CDE12
	lsls r0, r4, #2
	ldr r1, _081CDD60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CDD60: .4byte 0x081CDD64
_081CDD64: @ jump table
	.4byte _081CDD84 @ case 0
	.4byte _081CDD88 @ case 1
	.4byte _081CDD92 @ case 2
	.4byte _081CDDA8 @ case 3
	.4byte _081CDDC0 @ case 4
	.4byte _081CDDD0 @ case 5
	.4byte _081CDDE0 @ case 6
	.4byte _081CDDF6 @ case 7
_081CDD84:
	movs r0, #0
	b _081CDD8A
_081CDD88:
	movs r0, #1
_081CDD8A:
	bl LoadNextConditionMenuMonData
_081CDD8E:
	movs r0, #1
	b _081CDE14
_081CDD92:
	movs r0, #2
	bl LoadNextConditionMenuMonData
	ldr r1, _081CDDA4
	adds r0, r5, r1
	bl DestroyConditionSparkleSprites
	b _081CDD8E
	.align 2, 0
_081CDDA4: .4byte 0x000028E0
_081CDDA8:
	bl GetConditionGraphPtr
	ldr r2, _081CDDBC
	adds r1, r5, r2
	bl ConditionMenu_UpdateMonExit
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CDD8E
	b _081CDE0E
	.align 2, 0
_081CDDBC: .4byte 0x00001814
_081CDDC0:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #0
	b _081CDDEE
_081CDDD0:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #1
	b _081CDDEE
_081CDDE0:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #2
_081CDDEE:
	movs r2, #0
	bl sub_081CDEB4
	b _081CDD8E
_081CDDF6:
	bl GetConditionGraphMenuCurrentLoadIndex
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #3
	movs r2, #0
	bl sub_081CDEB4
	cmp r0, #1
	beq _081CDD8E
_081CDE0E:
	movs r0, #2
	b _081CDE14
_081CDE12:
	movs r0, #4
_081CDE14:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end LoopedTask_SlideMonOut

	thumb_func_start LoopedTask_OpenMonMarkingsWindow
LoopedTask_OpenMonMarkingsWindow: @ 0x081CDE1C
	push {lr}
	cmp r0, #1
	beq _081CDE46
	cmp r0, #1
	bgt _081CDE2C
	cmp r0, #0
	beq _081CDE32
	b _081CDE5A
_081CDE2C:
	cmp r0, #2
	beq _081CDE4E
	b _081CDE5A
_081CDE32:
	bl TryGetMonMarkId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0xb0
	movs r2, #0x20
	bl OpenMonMarkingsMenu
_081CDE42:
	movs r0, #1
	b _081CDE5C
_081CDE46:
	movs r0, #5
	bl PrintHelpBarText
	b _081CDE42
_081CDE4E:
	bl WaitForHelpBar
	cmp r0, #1
	bne _081CDE42
	movs r0, #2
	b _081CDE5C
_081CDE5A:
	movs r0, #4
_081CDE5C:
	pop {r1}
	bx r1
	thumb_func_end LoopedTask_OpenMonMarkingsWindow

	thumb_func_start LoopedTask_CloseMonMarkingsWindow
LoopedTask_CloseMonMarkingsWindow: @ 0x081CDE60
	push {lr}
	cmp r0, #1
	beq _081CDE7E
	cmp r0, #1
	bgt _081CDE70
	cmp r0, #0
	beq _081CDE76
	b _081CDE92
_081CDE70:
	cmp r0, #2
	beq _081CDE86
	b _081CDE92
_081CDE76:
	bl FreeMonMarkingsMenu
_081CDE7A:
	movs r0, #1
	b _081CDE94
_081CDE7E:
	movs r0, #4
	bl PrintHelpBarText
	b _081CDE7A
_081CDE86:
	bl WaitForHelpBar
	cmp r0, #1
	bne _081CDE7A
	movs r0, #2
	b _081CDE94
_081CDE92:
	movs r0, #4
_081CDE94:
	pop {r1}
	bx r1
	thumb_func_end LoopedTask_CloseMonMarkingsWindow

	thumb_func_start UnusedPrintNumberString
UnusedPrintNumberString: @ 0x081CDE98
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r2, #1
	movs r3, #4
	bl ConvertIntToDecimalStringN
	ldr r1, _081CDEB0
	bl StringCopy
	pop {r1}
	bx r1
	.align 2, 0
_081CDEB0: .4byte 0x085CB7CE
	thumb_func_end UnusedPrintNumberString

	thumb_func_start sub_081CDEB4
sub_081CDEB4: @ 0x081CDEB4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	movs r0, #0xc
	bl GetSubstructPtr
	adds r6, r0, #0
	cmp r7, #1
	beq _081CDF10
	cmp r7, #1
	bgt _081CDEDA
	cmp r7, #0
	beq _081CDEE4
	b _081CE05C
_081CDEDA:
	cmp r7, #2
	beq _081CDF52
	cmp r7, #3
	beq _081CDFD4
	b _081CE05C
_081CDEE4:
	movs r1, #0xc1
	lsls r1, r1, #5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FillWindowPixelBuffer
	bl IsConditionMenuSearchMode
	cmp r0, #1
	beq _081CDEFC
	b _081CE05C
_081CDEFC:
	ldr r1, _081CDF0C
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FillWindowPixelBuffer
	b _081CE05C
	.align 2, 0
_081CDF0C: .4byte 0x00001821
_081CDF10:
	bl GetConditionGraphCurrentListIndex
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl GetMonListCount
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r0, #1
	cmp r4, r0
	bne _081CDF32
	bl IsConditionMenuSearchMode
	cmp r0, #1
	beq _081CDF32
	b _081CE05C
_081CDF32:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl GetConditionMonNameText
	adds r2, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #2
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #1
	b _081CDFC4
_081CDF52:
	bl IsConditionMenuSearchMode
	cmp r0, #1
	beq _081CDF5C
	b _081CE05C
_081CDF5C:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl GetConditionMonLocationText
	adds r2, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #0x12
	str r1, [sp]
	movs r5, #0
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	movs r3, #0
	bl AddTextPrinterParameterized
	add r1, sp, #0xc
	movs r0, #0xfc
	strb r0, [r1]
	movs r0, #4
	strb r0, [r1, #1]
	movs r0, #8
	strb r0, [r1, #2]
	adds r0, r1, #0
	strb r5, [r0, #3]
	movs r0, #9
	strb r0, [r1, #4]
	mov r4, sp
	adds r4, #0x11
	bl GetConditionMonDataBuffer
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl UnusedPrintNumberString
	ldr r4, _081CDFCC
	adds r0, r4, #0
	add r1, sp, #0xc
	bl StringExpandPlaceholders
	ldr r1, _081CDFD0
	adds r0, r6, r1
	ldrb r0, [r0]
	str r7, [sp]
	str r5, [sp, #4]
	str r5, [sp, #8]
	movs r1, #1
	adds r2, r4, #0
_081CDFC4:
	movs r3, #0
	bl AddTextPrinterParameterized
	b _081CE05C
	.align 2, 0
_081CDFCC: .4byte 0x02021C7C
_081CDFD0: .4byte 0x00001821
_081CDFD4:
	ldr r1, _081CDFE4
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CDFE8
	cmp r0, #1
	beq _081CE024
	b _081CE05C
	.align 2, 0
_081CDFE4: .4byte 0x00002908
_081CDFE8:
	cmp r4, #0
	beq _081CDFFC
	movs r1, #0xc1
	lsls r1, r1, #5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #3
	bl CopyWindowToVram
	b _081CE00A
_081CDFFC:
	movs r1, #0xc1
	lsls r1, r1, #5
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
_081CE00A:
	bl IsConditionMenuSearchMode
	cmp r0, #1
	bne _081CE048
	ldr r0, _081CE020
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _081CE05C
	.align 2, 0
_081CE020: .4byte 0x00002908
_081CE024:
	cmp r4, #0
	beq _081CE03C
	ldr r1, _081CE038
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #3
	bl CopyWindowToVram
	b _081CE048
	.align 2, 0
_081CE038: .4byte 0x00001821
_081CE03C:
	ldr r1, _081CE054
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r1, #2
	bl CopyWindowToVram
_081CE048:
	ldr r0, _081CE058
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CE05E
	.align 2, 0
_081CE054: .4byte 0x00001821
_081CE058: .4byte 0x00002908
_081CE05C:
	movs r0, #0
_081CE05E:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CDEB4

	thumb_func_start CopyUnusedConditionWindowsToVram
CopyUnusedConditionWindowsToVram: @ 0x081CE068
	push {r4, lr}
	movs r0, #0xc
	bl GetSubstructPtr
	adds r4, r0, #0
	ldr r1, _081CE090
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #3
	bl CopyWindowToVram
	ldr r0, _081CE094
	adds r4, r4, r0
	ldrb r0, [r4]
	movs r1, #3
	bl CopyWindowToVram
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CE090: .4byte 0x00001822
_081CE094: .4byte 0x00001823
	thumb_func_end CopyUnusedConditionWindowsToVram

	thumb_func_start SpriteCB_PartyPokeball
SpriteCB_PartyPokeball: @ 0x081CE098
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x2e
	ldrsh r4, [r5, r0]
	bl GetConditionGraphCurrentListIndex
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r4, r0
	bne _081CE0B6
	adds r0, r5, #0
	movs r1, #0
	bl StartSpriteAnim
	b _081CE0BE
_081CE0B6:
	adds r0, r5, #0
	movs r1, #1
	bl StartSpriteAnim
_081CE0BE:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end SpriteCB_PartyPokeball

	thumb_func_start HighlightCurrentPartyIndexPokeball
HighlightCurrentPartyIndexPokeball: @ 0x081CE0C4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl GetConditionGraphCurrentListIndex
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl GetMonListCount
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r0, #1
	cmp r4, r0
	bne _081CE0E4
	movs r0, #0x65
	b _081CE0E6
_081CE0E4:
	movs r0, #0x66
_081CE0E6:
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #4
	ldrb r2, [r5, #5]
	movs r1, #0xf
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, #5]
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end HighlightCurrentPartyIndexPokeball

	thumb_func_start MonMarkingsCallback
MonMarkingsCallback: @ 0x081CE0FC
	push {r4, lr}
	adds r4, r0, #0
	bl TryGetMonMarkId
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end MonMarkingsCallback

	thumb_func_start CreateMonMarkingsOrPokeballIndicators
CreateMonMarkingsOrPokeballIndicators: @ 0x081CE118
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x58
	movs r0, #0xc
	bl GetSubstructPtr
	adds r6, r0, #0
	add r4, sp, #0x20
	add r5, sp, #0x38
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl LoadConditionSelectionIcons
	bl IsConditionMenuSearchMode
	adds r7, r4, #0
	mov sl, r5
	cmp r0, #1
	bne _081CE1AC
	ldr r1, _081CE198
	adds r0, r6, r1
	movs r2, #0x6a
	strh r2, [r0]
	ldr r3, _081CE19C
	adds r1, r6, r3
	strh r2, [r1]
	bl unref_sub_811BBF4
	bl BufferMonMarkingsMenuTiles
	ldr r2, _081CE1A0
	movs r0, #0x69
	movs r1, #0x69
	bl CreateMonMarkingAllCombosSprite
	ldrb r1, [r0, #5]
	movs r2, #0xc
	orrs r1, r2
	strb r1, [r0, #5]
	movs r1, #0xc0
	strh r1, [r0, #0x20]
	movs r1, #0x20
	strh r1, [r0, #0x22]
	ldr r1, _081CE1A4
	str r1, [r0, #0x1c]
	ldr r2, _081CE1A8
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0x69
	bl IndexOfSpritePaletteTag
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl PokenavFillPalette
	add r3, sp, #0x50
	mov r8, r3
	b _081CE2FA
	.align 2, 0
_081CE198: .4byte 0x00001824
_081CE19C: .4byte 0x00001826
_081CE1A0: .4byte 0x085F5944
_081CE1A4: .4byte 0x081CE0FD
_081CE1A8: .4byte 0x000028DC
_081CE1AC:
	mov r0, sp
	bl LoadSpriteSheets
	mov r0, sl
	bl Pokenav_AllocAndLoadPalettes
	movs r4, #0
	add r0, sp, #0x50
	mov r8, r0
	b _081CE21C
_081CE1C0:
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r1, #0x80
	lsls r1, r1, #0xc
	adds r2, r2, r1
	asrs r2, r2, #0x10
	adds r0, r7, #0
	movs r1, #0xe2
	movs r3, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x40
	beq _081CE20C
	ldr r2, _081CE200
	adds r0, r6, r2
	adds r0, r0, r4
	strb r3, [r0]
	ldr r2, _081CE204
	lsls r0, r3, #4
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r1, r0, r2
	strh r4, [r1, #0x2e]
	adds r2, #0x1c
	adds r0, r0, r2
	ldr r1, _081CE208
	str r1, [r0]
	b _081CE216
	.align 2, 0
_081CE200: .4byte 0x00001806
_081CE204: .4byte 0x020205AC
_081CE208: .4byte 0x081CE099
_081CE20C:
	ldr r3, _081CE274
	adds r0, r6, r3
	adds r0, r0, r4
	movs r1, #0xff
	strb r1, [r0]
_081CE216:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_081CE21C:
	bl GetMonListCount
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r0, #1
	cmp r4, r0
	blt _081CE1C0
	movs r0, #0x67
	strh r0, [r7]
	ldr r0, _081CE278
	str r0, [r7, #0x14]
	cmp r4, #5
	bhi _081CE290
	ldr r0, _081CE274
	adds r5, r6, r0
	ldr r1, _081CE27C
	mov sb, r1
_081CE23E:
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r3, #0x80
	lsls r3, r3, #0xc
	adds r2, r2, r3
	asrs r2, r2, #0x10
	adds r0, r7, #0
	movs r1, #0xe6
	movs r3, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x40
	beq _081CE280
	adds r0, r5, r4
	strb r3, [r0]
	lsls r1, r3, #4
	adds r1, r1, r3
	lsls r1, r1, #2
	add r1, sb
	ldrb r2, [r1, #3]
	movs r0, #0x3f
	ands r0, r2
	strb r0, [r1, #3]
	b _081CE286
	.align 2, 0
_081CE274: .4byte 0x00001806
_081CE278: .4byte 0x08007141
_081CE27C: .4byte 0x020205AC
_081CE280:
	adds r1, r5, r4
	movs r0, #0xff
	strb r0, [r1]
_081CE286:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #5
	bls _081CE23E
_081CE290:
	movs r0, #0x66
	strh r0, [r7]
	ldr r0, _081CE2E4
	str r0, [r7, #0x14]
	lsls r2, r4, #2
	adds r2, r2, r4
	lsls r2, r2, #0x12
	movs r0, #0x80
	lsls r0, r0, #0xc
	adds r2, r2, r0
	asrs r2, r2, #0x10
	adds r0, r7, #0
	movs r1, #0xde
	movs r3, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0x40
	beq _081CE2F0
	ldr r1, _081CE2E8
	adds r0, r6, r1
	adds r0, r0, r4
	strb r3, [r0]
	ldr r0, _081CE2EC
	lsls r2, r3, #4
	adds r2, r2, r3
	lsls r2, r2, #2
	adds r2, r2, r0
	ldrb r3, [r2, #1]
	movs r1, #0x3f
	adds r0, r1, #0
	ands r0, r3
	movs r3, #0x40
	orrs r0, r3
	strb r0, [r2, #1]
	ldrb r0, [r2, #3]
	ands r1, r0
	movs r0, #0x80
	orrs r1, r0
	strb r1, [r2, #3]
	b _081CE2FA
	.align 2, 0
_081CE2E4: .4byte 0x081CE0C5
_081CE2E8: .4byte 0x00001806
_081CE2EC: .4byte 0x020205AC
_081CE2F0:
	ldr r2, _081CE324
	adds r0, r6, r2
	adds r0, r0, r4
	movs r1, #0xff
	strb r1, [r0]
_081CE2FA:
	mov r0, r8
	mov r1, sl
	bl LoadConditionSparkle
	mov r0, r8
	bl LoadSpriteSheet
	movs r0, #0
	mov r3, sl
	str r0, [r3, #8]
	mov r0, sl
	bl Pokenav_AllocAndLoadPalettes
	add sp, #0x58
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CE324: .4byte 0x00001806
	thumb_func_end CreateMonMarkingsOrPokeballIndicators

	thumb_func_start FreeConditionMenuGfx
FreeConditionMenuGfx: @ 0x081CE328
	push {r4, r5, lr}
	adds r5, r0, #0
	bl IsConditionMenuSearchMode
	cmp r0, #1
	bne _081CE35C
	ldr r1, _081CE358
	adds r0, r5, r1
	ldr r0, [r0]
	bl DestroySprite
	movs r0, #0x6a
	bl FreeSpriteTilesByTag
	movs r0, #0x69
	bl FreeSpriteTilesByTag
	movs r0, #0x6a
	bl FreeSpritePaletteByTag
	movs r0, #0x69
	bl FreeSpritePaletteByTag
	b _081CE39C
	.align 2, 0
_081CE358: .4byte 0x000028DC
_081CE35C:
	movs r4, #0
_081CE35E:
	ldr r1, _081CE3C8
	adds r0, r5, r1
	adds r0, r0, r4
	ldrb r1, [r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _081CE3CC
	adds r0, r0, r1
	bl DestroySprite
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #6
	bls _081CE35E
	movs r0, #0x65
	bl FreeSpriteTilesByTag
	movs r0, #0x66
	bl FreeSpriteTilesByTag
	movs r0, #0x67
	bl FreeSpriteTilesByTag
	movs r0, #0x65
	bl FreeSpritePaletteByTag
	movs r0, #0x66
	bl FreeSpritePaletteByTag
_081CE39C:
	ldr r0, _081CE3D0
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _081CE3C2
	adds r1, r0, #0
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _081CE3CC
	adds r0, r0, r1
	bl DestroySprite
	movs r0, #0x64
	bl FreeSpriteTilesByTag
	movs r0, #0x64
	bl FreeSpritePaletteByTag
_081CE3C2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CE3C8: .4byte 0x00001806
_081CE3CC: .4byte 0x020205AC
_081CE3D0: .4byte 0x00001816
	thumb_func_end FreeConditionMenuGfx

	thumb_func_start FreeConditionGraphMenuSubstruct2
FreeConditionGraphMenuSubstruct2: @ 0x081CE3D4
	push {r4, lr}
	movs r0, #0xc
	bl GetSubstructPtr
	adds r4, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #5
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	bl IsConditionMenuSearchMode
	cmp r0, #1
	bne _081CE420
	ldr r1, _081CE414
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r1, _081CE418
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	ldr r1, _081CE41C
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	b _081CE424
	.align 2, 0
_081CE414: .4byte 0x00001821
_081CE418: .4byte 0x00001822
_081CE41C: .4byte 0x00001823
_081CE420:
	bl SetLeftHeaderSpritesInvisibility
_081CE424:
	movs r1, #0x8a
	lsls r1, r1, #5
	movs r0, #0
	bl SetGpuReg
	adds r0, r4, #0
	bl FreeConditionMenuGfx
	bl SetExitVBlank
	movs r0, #0xc
	bl FreePokenavSubstruct
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end FreeConditionGraphMenuSubstruct2

	thumb_func_start MonPicGfxSpriteCallback
MonPicGfxSpriteCallback: @ 0x081CE444
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xc
	bl GetSubstructPtr
	ldr r1, _081CE460
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, #0x26
	strh r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CE460: .4byte 0x00001814
	thumb_func_end MonPicGfxSpriteCallback

	thumb_func_start CreateConditionMonPic
CreateConditionMonPic: @ 0x081CE464
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r0, #0xc
	bl GetSubstructPtr
	mov r8, r0
	ldr r7, _081CE4E4
	add r7, r8
	ldrb r0, [r7]
	cmp r0, #0xff
	bne _081CE530
	add r5, sp, #0x18
	add r4, sp, #0x20
	adds r0, r5, #0
	mov r1, sp
	adds r2, r4, #0
	bl LoadConditionMonPicTemplate
	adds r0, r6, #0
	bl GetConditionMonPicGfx
	str r0, [sp, #0x18]
	adds r0, r6, #0
	bl GetConditionMonPal
	str r0, [sp, #0x20]
	adds r0, r4, #0
	bl LoadSpritePalette
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r4, _081CE4E8
	add r4, r8
	strh r0, [r4]
	adds r0, r5, #0
	bl LoadSpriteSheet
	ldr r5, _081CE4EC
	add r5, r8
	strh r0, [r5]
	mov r0, sp
	movs r1, #0x26
	movs r2, #0x68
	movs r3, #0
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strb r0, [r7]
	cmp r0, #0x40
	bne _081CE4F0
	movs r0, #0x64
	bl FreeSpriteTilesByTag
	movs r0, #0x64
	bl FreeSpritePaletteByTag
	movs r0, #0xff
	strb r0, [r7]
	b _081CE55A
	.align 2, 0
_081CE4E4: .4byte 0x00001816
_081CE4E8: .4byte 0x00001818
_081CE4EC: .4byte 0x0000181A
_081CE4F0:
	strb r0, [r7]
	ldr r2, _081CE520
	ldrb r1, [r7]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #0x1c
	adds r0, r0, r2
	ldr r1, _081CE524
	str r1, [r0]
	ldr r1, _081CE528
	add r1, r8
	ldrh r0, [r5]
	lsls r0, r0, #5
	ldr r2, _081CE52C
	adds r0, r0, r2
	str r0, [r1]
	ldrh r0, [r4]
	lsls r0, r0, #4
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	strh r0, [r4]
	b _081CE55A
	.align 2, 0
_081CE520: .4byte 0x020205AC
_081CE524: .4byte 0x081CE445
_081CE528: .4byte 0x0000181C
_081CE52C: .4byte 0x06010000
_081CE530:
	adds r0, r6, #0
	bl GetConditionMonPicGfx
	ldr r1, _081CE568
	add r1, r8
	ldr r2, [r1]
	ldr r1, _081CE56C
	str r0, [r1]
	str r2, [r1, #4]
	ldr r0, _081CE570
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	adds r0, r6, #0
	bl GetConditionMonPal
	ldr r1, _081CE574
	add r1, r8
	ldrh r1, [r1]
	movs r2, #0x20
	bl LoadPalette
_081CE55A:
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CE568: .4byte 0x0000181C
_081CE56C: .4byte 0x040000D4
_081CE570: .4byte 0x80000400
_081CE574: .4byte 0x00001818
	thumb_func_end CreateConditionMonPic

	thumb_func_start VBlankCB_PokenavConditionGraph
VBlankCB_PokenavConditionGraph: @ 0x081CE578
	push {r4, lr}
	bl GetConditionGraphPtr
	adds r4, r0, #0
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	adds r0, r4, #0
	bl ConditionGraph_Draw
	bl ScanlineEffect_InitHBlankDmaTransfer
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end VBlankCB_PokenavConditionGraph

	thumb_func_start SetExitVBlank
SetExitVBlank: @ 0x081CE59C
	push {lr}
	bl SetPokenavVBlankCallback
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end SetExitVBlank

	thumb_func_start ToggleGraphData
ToggleGraphData: @ 0x081CE5A8
	push {lr}
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CE5B8
	movs r0, #2
	bl ShowBg
	b _081CE5BE
_081CE5B8:
	movs r0, #2
	bl HideBg
_081CE5BE:
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end ToggleGraphData

	thumb_func_start DoConditionGraphEnterTransition
DoConditionGraphEnterTransition: @ 0x081CE5C4
	push {r4, lr}
	bl GetConditionGraphPtr
	adds r4, r0, #0
	bl GetConditionGraphMenuCurrentLoadIndex
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _081CE5F8
	strb r0, [r1]
	adds r1, r4, #0
	adds r1, #0x50
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, #0x14
	adds r2, r4, r2
	adds r0, r4, #0
	bl ConditionGraph_SetNewPositions
	adds r0, r4, #0
	bl ConditionGraph_TryUpdate
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CE5F8: .4byte 0x030012B0
	thumb_func_end DoConditionGraphEnterTransition

	thumb_func_start DoConditionGraphExitTransition
DoConditionGraphExitTransition: @ 0x081CE5FC
	push {r4, r5, lr}
	bl GetConditionGraphPtr
	adds r5, r0, #0
	bl IsConditionMenuSearchMode
	cmp r0, #0
	bne _081CE624
	bl GetConditionGraphCurrentListIndex
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl GetMonListCount
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r0, #1
	cmp r4, r0
	beq _081CE640
_081CE624:
	bl GetConditionGraphMenuCurrentLoadIndex
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, #0x14
	adds r1, r5, r1
	adds r2, r5, #0
	adds r2, #0x50
	adds r0, r5, #0
	bl ConditionGraph_SetNewPositions
_081CE640:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end DoConditionGraphExitTransition

	thumb_func_start GetMonMarkingsData
GetMonMarkingsData: @ 0x081CE648
	push {r4, lr}
	movs r0, #0xc
	bl GetSubstructPtr
	adds r4, r0, #0
	bl IsConditionMenuSearchMode
	cmp r0, #1
	beq _081CE65E
	movs r0, #0
	b _081CE664
_081CE65E:
	ldr r1, _081CE66C
	adds r0, r4, r1
	ldrb r0, [r0]
_081CE664:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081CE66C: .4byte 0x00001828
	thumb_func_end GetMonMarkingsData

	thumb_func_start PokenavCallback_Init_ConditionSearch
PokenavCallback_Init_ConditionSearch: @ 0x081CE670
	push {r4, lr}
	movs r0, #7
	movs r1, #0x24
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CE6C4
	ldr r1, _081CE6B4
	movs r0, #0x12
	bl AllocSubstruct
	str r0, [r4, #0x20]
	cmp r0, #0
	beq _081CE6C4
	ldr r0, _081CE6B8
	str r0, [r4]
	ldr r0, _081CE6BC
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r4, #4]
	movs r0, #0
	str r0, [r4, #0x18]
	bl GetSelectedConditionSearch
	ldr r1, _081CE6C0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #1
	b _081CE6C6
	.align 2, 0
_081CE6B4: .4byte 0x000006AC
_081CE6B8: .4byte 0x081CE745
_081CE6BC: .4byte 0x081CE851
_081CE6C0: .4byte 0x085F59AC
_081CE6C4:
	movs r0, #0
_081CE6C6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end PokenavCallback_Init_ConditionSearch

	thumb_func_start PokenavCallback_Init_ReturnToMonSearchList
PokenavCallback_Init_ReturnToMonSearchList: @ 0x081CE6CC
	push {r4, lr}
	movs r0, #7
	movs r1, #0x24
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CE708
	movs r0, #0x12
	bl GetSubstructPtr
	str r0, [r4, #0x20]
	ldr r0, _081CE700
	str r0, [r4]
	movs r0, #1
	str r0, [r4, #0x18]
	bl GetSelectedConditionSearch
	ldr r1, _081CE704
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r4, #0x14]
	movs r0, #1
	b _081CE70A
	.align 2, 0
_081CE700: .4byte 0x081CE765
_081CE704: .4byte 0x085F59AC
_081CE708:
	movs r0, #0
_081CE70A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end PokenavCallback_Init_ReturnToMonSearchList

	thumb_func_start GetConditionSearchResultsCallback
GetConditionSearchResultsCallback: @ 0x081CE710
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r1, [r0]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetConditionSearchResultsCallback

	thumb_func_start FreeSearchResultSubstruct1
FreeSearchResultSubstruct1: @ 0x081CE724
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r0, [r0, #0x1c]
	cmp r0, #0
	bne _081CE738
	movs r0, #0x12
	bl FreePokenavSubstruct
_081CE738:
	movs r0, #7
	bl FreePokenavSubstruct
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end FreeSearchResultSubstruct1

	thumb_func_start sub_081CE744
sub_081CE744: @ 0x081CE744
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	bl IsLoopedTaskActive
	cmp r0, #0
	bne _081CE756
	ldr r0, _081CE760
	str r0, [r4]
_081CE756:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081CE760: .4byte 0x081CE765
	thumb_func_end sub_081CE744

	thumb_func_start HandleConditionSearchInput
HandleConditionSearchInput: @ 0x081CE764
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, _081CE778
	ldrh r1, [r2, #0x30]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081CE77C
	movs r0, #1
	b _081CE7DA
	.align 2, 0
_081CE778: .4byte 0x03002360
_081CE77C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081CE788
	movs r0, #2
	b _081CE7DA
_081CE788:
	ldrh r1, [r2, #0x2e]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081CE796
	movs r0, #3
	b _081CE7DA
_081CE796:
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081CE7A6
	movs r0, #4
	b _081CE7DA
_081CE7A6:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081CE7BC
	str r2, [r4, #0x1c]
	ldr r0, _081CE7B8
	str r0, [r4]
	movs r0, #5
	b _081CE7DA
	.align 2, 0
_081CE7B8: .4byte 0x081CE7E5
_081CE7BC:
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _081CE7CA
	movs r0, #0
	b _081CE7DA
_081CE7CA:
	bl PokenavList_GetSelectedIndex
	ldr r1, [r4, #0x20]
	strh r0, [r1, #2]
	str r5, [r4, #0x1c]
	ldr r0, _081CE7E0
	str r0, [r4]
	movs r0, #6
_081CE7DA:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081CE7E0: .4byte 0x081CE7ED
	thumb_func_end HandleConditionSearchInput

	thumb_func_start ReturnToConditionSearchList
ReturnToConditionSearchList: @ 0x081CE7E4
	ldr r0, _081CE7E8
	bx lr
	.align 2, 0
_081CE7E8: .4byte 0x000186A3
	thumb_func_end ReturnToConditionSearchList

	thumb_func_start OpenConditionGraphFromSearchList
OpenConditionGraphFromSearchList: @ 0x081CE7EC
	ldr r0, _081CE7F0
	bx lr
	.align 2, 0
_081CE7F0: .4byte 0x000186A9
	thumb_func_end OpenConditionGraphFromSearchList

	thumb_func_start GetReturningFromGraph
GetReturningFromGraph: @ 0x081CE7F4
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r0, [r0, #0x18]
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetReturningFromGraph

	thumb_func_start GetSearchResultsMonDataList
GetSearchResultsMonDataList: @ 0x081CE804
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r0, [r0, #0x20]
	adds r0, #4
	pop {r1}
	bx r1
	thumb_func_end GetSearchResultsMonDataList

	thumb_func_start GetSearchResultsMonListCount
GetSearchResultsMonListCount: @ 0x081CE814
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r0, [r0, #0x20]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end GetSearchResultsMonListCount

	thumb_func_start GetSearchResultsSelectedMonRank
GetSearchResultsSelectedMonRank: @ 0x081CE824
	push {r4, lr}
	movs r0, #7
	bl GetSubstructPtr
	adds r4, r0, #0
	bl PokenavList_GetSelectedIndex
	ldr r1, [r4, #0x20]
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1, #6]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetSearchResultsSelectedMonRank

	thumb_func_start GetSearchResultsCurrentListIndex
GetSearchResultsCurrentListIndex: @ 0x081CE840
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r0, [r0, #0x20]
	ldrh r0, [r0, #2]
	pop {r1}
	bx r1
	thumb_func_end GetSearchResultsCurrentListIndex

	thumb_func_start MysteryGiftServer_CallFunc
MysteryGiftServer_CallFunc: @ 0x081CE850
	push {lr}
	ldr r2, _081CE864
	lsls r1, r0, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
_081CE864: .4byte 0x085F59C0
	thumb_func_end MysteryGiftServer_CallFunc

	thumb_func_start BuildPartyMonSearchResults
BuildPartyMonSearchResults: @ 0x081CE868
	push {r4, r5, r6, lr}
	sub sp, #4
	movs r0, #7
	bl GetSubstructPtr
	adds r6, r0, #0
	ldr r0, [r6, #0x20]
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r6, #0x20]
	strh r1, [r0, #2]
	ldr r1, _081CE8E8
	ldr r0, [sp]
	ands r0, r1
	movs r1, #0xe
	orrs r0, r1
	str r0, [sp]
	movs r5, #0
_081CE88C:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _081CE8EC
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #5
	bl GetMonData3
	cmp r0, #0
	beq _081CE8DE
	adds r0, r4, #0
	movs r1, #6
	bl GetMonData3
	cmp r0, #0
	bne _081CE8D8
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x10
	ldr r2, _081CE8F0
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldr r1, [r6, #0x14]
	adds r0, r4, #0
	bl GetMonData3
	lsls r0, r0, #0x10
	ldr r2, _081CE8F4
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	adds r0, r6, #0
	mov r1, sp
	bl InsertMonListItem
_081CE8D8:
	adds r5, #1
	cmp r5, #5
	ble _081CE88C
_081CE8DE:
	movs r0, #1
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081CE8E8: .4byte 0xFFFFFF00
_081CE8EC: .4byte 0x02024190
_081CE8F0: .4byte 0xFFFF00FF
_081CE8F4: .4byte 0x0000FFFF
	thumb_func_end BuildPartyMonSearchResults

	thumb_func_start InitBoxMonSearchResults
InitBoxMonSearchResults: @ 0x081CE8F8
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	movs r1, #0
	str r1, [r0, #0x10]
	str r1, [r0, #0xc]
	movs r0, #1
	pop {r1}
	bx r1
	thumb_func_end InitBoxMonSearchResults

	thumb_func_start BuildBoxMonSearchResults
BuildBoxMonSearchResults: @ 0x081CE90C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	movs r0, #7
	bl GetSubstructPtr
	adds r6, r0, #0
	ldr r5, [r6, #0xc]
	ldr r4, [r6, #0x10]
	movs r0, #0
	mov r8, r0
	cmp r5, #0xd
	bgt _081CE99C
_081CE928:
	cmp r4, #0x1d
	bgt _081CE994
	lsls r0, r5, #0x18
	lsrs r7, r0, #0x18
_081CE930:
	adds r0, r5, #0
	adds r1, r4, #0
	bl CheckBoxMonSanityAt
	cmp r0, #0
	beq _081CE96E
	ldr r1, _081CE984
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r7
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	lsls r3, r1, #8
	ldr r2, _081CE988
	ands r0, r2
	orrs r0, r3
	str r0, [sp]
	ldr r2, [r6, #0x14]
	adds r0, r7, #0
	bl GetBoxMonDataAt
	lsls r0, r0, #0x10
	ldr r2, _081CE98C
	ldr r1, [sp]
	ands r1, r2
	orrs r1, r0
	str r1, [sp]
	adds r0, r6, #0
	mov r1, sp
	bl InsertMonListItem
_081CE96E:
	movs r0, #1
	add r8, r0
	adds r4, #1
	mov r0, r8
	cmp r0, #0xe
	ble _081CE990
	str r5, [r6, #0xc]
	str r4, [r6, #0x10]
	movs r0, #3
	b _081CE99E
	.align 2, 0
_081CE984: .4byte 0xFFFFFF00
_081CE988: .4byte 0xFFFF00FF
_081CE98C: .4byte 0x0000FFFF
_081CE990:
	cmp r4, #0x1d
	ble _081CE930
_081CE994:
	movs r4, #0
	adds r5, #1
	cmp r5, #0xd
	ble _081CE928
_081CE99C:
	movs r0, #1
_081CE99E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end BuildBoxMonSearchResults

	thumb_func_start ConvertConditionsToListRanks
ConvertConditionsToListRanks: @ 0x081CE9AC
	push {r4, r5, r6, lr}
	movs r0, #7
	bl GetSubstructPtr
	adds r5, r0, #0
	ldr r0, [r5, #0x20]
	ldrh r6, [r0]
	ldrh r4, [r0, #6]
	movs r1, #1
	strh r1, [r0, #6]
	movs r3, #1
	cmp r3, r6
	bge _081CE9EC
_081CE9C6:
	ldr r2, [r5, #0x20]
	lsls r0, r3, #2
	adds r1, r2, r0
	ldrh r0, [r1, #6]
	cmp r0, r4
	bne _081CE9E0
	subs r0, r3, #1
	lsls r0, r0, #2
	adds r0, r2, r0
	ldrh r0, [r0, #6]
	strh r0, [r1, #6]
	adds r0, r3, #1
	b _081CE9E6
_081CE9E0:
	adds r4, r0, #0
	adds r0, r3, #1
	strh r0, [r1, #6]
_081CE9E6:
	adds r3, r0, #0
	cmp r3, r6
	blt _081CE9C6
_081CE9EC:
	movs r0, #1
	str r0, [r5, #0x18]
	movs r0, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end ConvertConditionsToListRanks

	thumb_func_start InsertMonListItem
InsertMonListItem: @ 0x081CE9F8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0
	ldr r0, [r5, #0x20]
	ldrh r2, [r0]
	lsrs r3, r2, #1
	cmp r2, r3
	beq _081CEA28
	adds r6, r0, #0
	ldrh r4, [r7, #2]
_081CEA0E:
	lsls r0, r3, #2
	adds r0, r6, r0
	ldrh r0, [r0, #6]
	cmp r4, r0
	bls _081CEA1C
	adds r2, r3, #0
	b _081CEA1E
_081CEA1C:
	adds r1, r3, #1
_081CEA1E:
	subs r0, r2, r1
	lsrs r0, r0, #1
	adds r3, r1, r0
	cmp r2, r3
	bne _081CEA0E
_081CEA28:
	ldr r0, [r5, #0x20]
	ldrh r2, [r0]
	lsls r6, r3, #2
	cmp r2, r3
	bls _081CEA4C
	lsls r0, r2, #2
	subs r4, r0, #4
_081CEA36:
	ldr r0, [r5, #0x20]
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	adds r0, r0, r4
	ldr r0, [r0]
	str r0, [r1]
	subs r4, #4
	subs r2, #1
	cmp r2, r3
	bhi _081CEA36
_081CEA4C:
	ldr r0, [r5, #0x20]
	adds r0, #4
	adds r0, r0, r6
	ldr r1, [r7]
	str r1, [r0]
	ldr r1, [r5, #0x20]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end InsertMonListItem

	thumb_func_start OpenConditionSearchResults
OpenConditionSearchResults: @ 0x081CEA64
	push {r4, lr}
	movs r1, #0x81
	lsls r1, r1, #4
	movs r0, #8
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CEA94
	ldr r0, _081CEA8C
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r4, #4]
	ldr r0, _081CEA90
	str r0, [r4]
	movs r0, #0
	str r0, [r4, #0xc]
	movs r0, #1
	b _081CEA96
	.align 2, 0
_081CEA8C: .4byte 0x081CEB4D
_081CEA90: .4byte 0x081CEB19
_081CEA94:
	movs r0, #0
_081CEA96:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end OpenConditionSearchResults

	thumb_func_start OpenConditionSearchListFromGraph
OpenConditionSearchListFromGraph: @ 0x081CEA9C
	push {r4, lr}
	movs r1, #0x81
	lsls r1, r1, #4
	movs r0, #8
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CEACC
	ldr r0, _081CEAC4
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r4, #4]
	ldr r0, _081CEAC8
	str r0, [r4]
	movs r0, #1
	str r0, [r4, #0xc]
	b _081CEACE
	.align 2, 0
_081CEAC4: .4byte 0x081CEB4D
_081CEAC8: .4byte 0x081CEB19
_081CEACC:
	movs r0, #0
_081CEACE:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end OpenConditionSearchListFromGraph

	thumb_func_start CreateSearchResultsLoopedTask
CreateSearchResultsLoopedTask: @ 0x081CEAD4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #8
	bl GetSubstructPtr
	adds r5, r0, #0
	ldr r0, _081CEAFC
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r0, [r4]
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r5, #4]
	ldr r0, _081CEB00
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CEAFC: .4byte 0x085F5BA4
_081CEB00: .4byte 0x081CEB19
	thumb_func_end CreateSearchResultsLoopedTask

	thumb_func_start IsRibbonsMonListLoopedTaskActive
IsRibbonsMonListLoopedTaskActive: @ 0x081CEB04
	push {lr}
	movs r0, #8
	bl GetSubstructPtr
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	thumb_func_end IsRibbonsMonListLoopedTaskActive

	thumb_func_start sub_081CEB14
sub_081CEB14: @ 0x081CEB14
	bx r1
	.align 2, 0
	thumb_func_end sub_081CEB14

	thumb_func_start GetSearchResultCurrentLoopedTaskActive
GetSearchResultCurrentLoopedTaskActive: @ 0x081CEB18
	push {lr}
	movs r0, #8
	bl GetSubstructPtr
	ldr r0, [r0, #4]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetSearchResultCurrentLoopedTaskActive

	thumb_func_start FreeSearchResultSubstruct2
FreeSearchResultSubstruct2: @ 0x081CEB2C
	push {r4, lr}
	movs r0, #8
	bl GetSubstructPtr
	adds r4, r0, #0
	bl DestroyPokenavList
	ldrb r0, [r4, #8]
	bl RemoveWindow
	movs r0, #8
	bl FreePokenavSubstruct
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end FreeSearchResultSubstruct2

	thumb_func_start LoopedTask_OpenConditionSearchResults
LoopedTask_OpenConditionSearchResults: @ 0x081CEB4C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #8
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #5
	bls _081CEB60
	b _081CECA2
_081CEB60:
	lsls r0, r4, #2
	ldr r1, _081CEB6C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CEB6C: .4byte 0x081CEB70
_081CEB70: @ jump table
	.4byte _081CEB88 @ case 0
	.4byte _081CEBE0 @ case 1
	.4byte _081CEBF4 @ case 2
	.4byte _081CEC14 @ case 3
	.4byte _081CEC2A @ case 4
	.4byte _081CEC8E @ case 5
_081CEB88:
	ldr r0, _081CEBD0
	movs r1, #2
	bl InitBgTemplates
	ldr r1, _081CEBD4
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	adds r1, r5, #0
	adds r1, #0x10
	movs r0, #1
	bl SetBgTilemapBuffer
	ldr r1, _081CEBD8
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	movs r0, #1
	bl CopyBgTilemapBufferToVram
	ldr r0, _081CEBDC
	movs r1, #0x10
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, #1
	bl CopyBgTilemapBufferToVram
_081CEBCC:
	movs r0, #0
	b _081CECA4
	.align 2, 0
_081CEBD0: .4byte 0x085F5B9C
_081CEBD4: .4byte 0x085F59F0
_081CEBD8: .4byte 0x085F5AB8
_081CEBDC: .4byte 0x085F59D0
_081CEBE0:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CEC9E
	bl GetReturningFromGraph
	cmp r0, #0
	beq _081CEC9E
	b _081CEBCC
_081CEBF4:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CEC9E
	ldr r0, _081CEC10
	movs r1, #0x20
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	bl CreateSearchResultsList
	b _081CEBCC
	.align 2, 0
_081CEC10: .4byte 0x085F5B7C
_081CEC14:
	bl IsCreatePokenavListTaskActive
	cmp r0, #0
	bne _081CEC9E
	adds r0, r5, #0
	bl AddSearchResultListMenuWindow
	movs r0, #3
	bl PrintHelpBarText
	b _081CEBCC
_081CEC2A:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CEC9E
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #1
	bl ShowBg
	movs r0, #2
	bl ShowBg
	movs r0, #3
	bl HideBg
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne _081CEC86
	bl GetSelectedConditionSearch
	adds r4, r0, #0
	adds r4, #8
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl LoadLeftHeaderGfxForIndex
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl ShowLeftHeaderGfx
	movs r0, #1
	movs r1, #1
	movs r2, #0
	bl ShowLeftHeaderGfx
_081CEC86:
	movs r0, #1
	bl PokenavFadeScreen
	b _081CEBCC
_081CEC8E:
	bl IsPaletteFadeActive
	cmp r0, #0
	bne _081CEC9E
	bl AreLeftHeaderSpritesMoving
	cmp r0, #0
	beq _081CECA2
_081CEC9E:
	movs r0, #2
	b _081CECA4
_081CECA2:
	movs r0, #4
_081CECA4:
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end LoopedTask_OpenConditionSearchResults

	thumb_func_start sub_081CECAC
sub_081CECAC: @ 0x081CECAC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #8
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CECEC
	cmp r4, #1
	bgt _081CECC6
	cmp r4, #0
	beq _081CECD0
	b _081CED0C
_081CECC6:
	cmp r4, #2
	beq _081CECF4
	cmp r4, #3
	beq _081CECFE
	b _081CED0C
_081CECD0:
	movs r0, #5
	bl PlaySE
	bl PokenavList_MoveCursorUp
	cmp r0, #1
	beq _081CECE8
	cmp r0, #1
	bgt _081CECFA
	cmp r0, #0
	bne _081CECFA
	b _081CED0C
_081CECE8:
	movs r0, #7
	b _081CED0E
_081CECEC:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CED08
_081CECF4:
	adds r0, r5, #0
	bl sub_081CEEE8
_081CECFA:
	movs r0, #0
	b _081CED0E
_081CECFE:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CED0C
_081CED08:
	movs r0, #2
	b _081CED0E
_081CED0C:
	movs r0, #4
_081CED0E:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CECAC

	thumb_func_start sub_081CED14
sub_081CED14: @ 0x081CED14
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #8
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CED54
	cmp r4, #1
	bgt _081CED2E
	cmp r4, #0
	beq _081CED38
	b _081CED74
_081CED2E:
	cmp r4, #2
	beq _081CED5C
	cmp r4, #3
	beq _081CED66
	b _081CED74
_081CED38:
	movs r0, #5
	bl PlaySE
	bl PokenavList_MoveCursorDown
	cmp r0, #1
	beq _081CED50
	cmp r0, #1
	bgt _081CED62
	cmp r0, #0
	bne _081CED62
	b _081CED74
_081CED50:
	movs r0, #7
	b _081CED76
_081CED54:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CED70
_081CED5C:
	adds r0, r5, #0
	bl sub_081CEEE8
_081CED62:
	movs r0, #0
	b _081CED76
_081CED66:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CED74
_081CED70:
	movs r0, #2
	b _081CED76
_081CED74:
	movs r0, #4
_081CED76:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CED14

	thumb_func_start sub_081CED7C
sub_081CED7C: @ 0x081CED7C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #8
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CEDBC
	cmp r4, #1
	bgt _081CED96
	cmp r4, #0
	beq _081CEDA0
	b _081CEDDC
_081CED96:
	cmp r4, #2
	beq _081CEDC4
	cmp r4, #3
	beq _081CEDCE
	b _081CEDDC
_081CEDA0:
	movs r0, #5
	bl PlaySE
	bl PokenavList_PageUp
	cmp r0, #1
	beq _081CEDB8
	cmp r0, #1
	bgt _081CEDCA
	cmp r0, #0
	bne _081CEDCA
	b _081CEDDC
_081CEDB8:
	movs r0, #7
	b _081CEDDE
_081CEDBC:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CEDD8
_081CEDC4:
	adds r0, r5, #0
	bl sub_081CEEE8
_081CEDCA:
	movs r0, #0
	b _081CEDDE
_081CEDCE:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CEDDC
_081CEDD8:
	movs r0, #2
	b _081CEDDE
_081CEDDC:
	movs r0, #4
_081CEDDE:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CED7C

	thumb_func_start sub_081CEDE4
sub_081CEDE4: @ 0x081CEDE4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #8
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CEE24
	cmp r4, #1
	bgt _081CEDFE
	cmp r4, #0
	beq _081CEE08
	b _081CEE44
_081CEDFE:
	cmp r4, #2
	beq _081CEE2C
	cmp r4, #3
	beq _081CEE36
	b _081CEE44
_081CEE08:
	movs r0, #5
	bl PlaySE
	bl PokenavList_PageDown
	cmp r0, #1
	beq _081CEE20
	cmp r0, #1
	bgt _081CEE32
	cmp r0, #0
	bne _081CEE32
	b _081CEE44
_081CEE20:
	movs r0, #7
	b _081CEE46
_081CEE24:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CEE40
_081CEE2C:
	adds r0, r5, #0
	bl sub_081CEEE8
_081CEE32:
	movs r0, #0
	b _081CEE46
_081CEE36:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CEE44
_081CEE40:
	movs r0, #2
	b _081CEE46
_081CEE44:
	movs r0, #4
_081CEE46:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CEDE4

	thumb_func_start LoopedTask_ExitConditionSearchMenu
LoopedTask_ExitConditionSearchMenu: @ 0x081CEE4C
	push {lr}
	cmp r0, #0
	beq _081CEE58
	cmp r0, #1
	beq _081CEE6C
	b _081CEE84
_081CEE58:
	movs r0, #5
	bl PlaySE
	movs r0, #0
	bl PokenavFadeScreen
	bl SlideMenuHeaderDown
	movs r0, #0
	b _081CEE86
_081CEE6C:
	bl IsPaletteFadeActive
	cmp r0, #0
	bne _081CEE7C
	bl MainMenuLoopedTaskIsBusy
	cmp r0, #0
	beq _081CEE80
_081CEE7C:
	movs r0, #2
	b _081CEE86
_081CEE80:
	bl SetLeftHeaderSpritesInvisibility
_081CEE84:
	movs r0, #4
_081CEE86:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end LoopedTask_ExitConditionSearchMenu

	thumb_func_start LoopedTask_SelectSearchResult
LoopedTask_SelectSearchResult: @ 0x081CEE8C
	push {lr}
	cmp r0, #0
	beq _081CEE98
	cmp r0, #1
	beq _081CEEA8
	b _081CEEB4
_081CEE98:
	movs r0, #5
	bl PlaySE
	movs r0, #0
	bl PokenavFadeScreen
	movs r0, #0
	b _081CEEB6
_081CEEA8:
	bl IsPaletteFadeActive
	cmp r0, #0
	beq _081CEEB4
	movs r0, #2
	b _081CEEB6
_081CEEB4:
	movs r0, #4
_081CEEB6:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end LoopedTask_SelectSearchResult

	thumb_func_start AddSearchResultListMenuWindow
AddSearchResultListMenuWindow: @ 0x081CEEBC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081CEEE4
	bl AddWindow
	strh r0, [r4, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl PutWindowTilemap
	ldrb r0, [r4, #8]
	movs r1, #1
	bl CopyWindowToVram
	adds r0, r4, #0
	bl sub_081CEEE8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CEEE4: .4byte 0x085F5BC0
	thumb_func_end AddSearchResultListMenuWindow

	thumb_func_start sub_081CEEE8
sub_081CEEE8: @ 0x081CEEE8
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	bl GetSearchResultsSelectedMonRank
	adds r5, r0, #0
	bl DynamicPlaceholderTextUtil_Reset
	ldr r4, _081CEF40
	movs r0, #0
	adds r1, r4, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r4, _081CEF44
	ldr r1, _081CEF48
	adds r0, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldrb r0, [r6, #8]
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	adds r2, r4, #0
	movs r3, #0
	bl AddTextPrinterParameterized
	ldrb r0, [r6, #8]
	movs r1, #2
	bl CopyWindowToVram
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081CEF40: .4byte 0x02021C40
_081CEF44: .4byte 0x02021C54
_081CEF48: .4byte 0x085CB81B
	thumb_func_end sub_081CEEE8

	thumb_func_start CreateSearchResultsList
CreateSearchResultsList: @ 0x081CEF4C
	push {r4, lr}
	sub sp, #0x18
	bl GetSearchResultsMonDataList
	str r0, [sp]
	bl GetSearchResultsMonListCount
	mov r1, sp
	movs r4, #0
	strh r0, [r1, #4]
	movs r0, #4
	strb r0, [r1, #8]
	bl GetSearchResultsCurrentListIndex
	mov r1, sp
	strh r0, [r1, #6]
	movs r0, #0xe
	strb r0, [r1, #9]
	movs r0, #0xf
	strb r0, [r1, #0xa]
	movs r0, #1
	strb r0, [r1, #0xb]
	movs r0, #8
	strb r0, [r1, #0xc]
	movs r0, #2
	strb r0, [r1, #0xd]
	ldr r0, _081CEF98
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	ldr r0, _081CEF9C
	movs r2, #0
	bl CreatePokenavList
	add sp, #0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CEF98: .4byte 0x081CEFA1
_081CEF9C: .4byte 0x085F5BA0
	thumb_func_end CreateSearchResultsList

	thumb_func_start sub_081CEFA0
sub_081CEFA0: @ 0x081CEFA0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	mov r8, r1
	bl DynamicPlaceholderTextUtil_Reset
	ldrb r0, [r4]
	cmp r0, #0xe
	bne _081CEFE8
	ldrb r1, [r4, #1]
	movs r0, #0x64
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _081CEFE0
	adds r4, r4, r0
	adds r0, r4, #0
	bl GetMonGender
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	bl GetLevelFromMonExp
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _081CEFE4
	adds r0, r4, #0
	movs r1, #2
	bl GetMonData3
	b _081CF00E
	.align 2, 0
_081CEFE0: .4byte 0x02024190
_081CEFE4: .4byte 0x02021C68
_081CEFE8:
	ldrb r0, [r4]
	ldrb r1, [r4, #1]
	bl GetBoxedMonPtr
	adds r4, r0, #0
	bl GetBoxMonGender
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r0, r4, #0
	bl GetLevelFromBoxMonExp
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _081CF060
	adds r0, r4, #0
	movs r1, #2
	bl GetBoxMonData
_081CF00E:
	ldr r4, _081CF060
	adds r0, r4, #0
	bl StringGet_Nickname
	ldr r6, _081CF064
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #5
	bl StringCopyPadded
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r5, _081CF068
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #3
	bl StringCopyPadded
	movs r0, #0
	adds r1, r6, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, #1
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	cmp r7, #0xfe
	beq _081CF070
	cmp r7, #0xfe
	bgt _081CF078
	cmp r7, #0
	bne _081CF078
	ldr r1, _081CF06C
	b _081CF07A
	.align 2, 0
_081CF060: .4byte 0x02021C68
_081CF064: .4byte 0x02021C40
_081CF068: .4byte 0x02021C54
_081CF06C: .4byte 0x085CB7D6
_081CF070:
	ldr r1, _081CF074
	b _081CF07A
	.align 2, 0
_081CF074: .4byte 0x085CB7EA
_081CF078:
	ldr r1, _081CF08C
_081CF07A:
	mov r0, r8
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CF08C: .4byte 0x085CB7FE
	thumb_func_end sub_081CEFA0

	thumb_func_start PokenavCallback_Init_MonRibbonList
PokenavCallback_Init_MonRibbonList: @ 0x081CF090
	push {r4, lr}
	movs r0, #9
	movs r1, #0x20
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CF0D0
	ldr r1, _081CF0C4
	movs r0, #0x12
	bl AllocSubstruct
	str r0, [r4, #0x1c]
	cmp r0, #0
	beq _081CF0D0
	ldr r0, _081CF0C8
	str r0, [r4]
	ldr r0, _081CF0CC
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r4, #4]
	movs r0, #0
	str r0, [r4, #0x14]
	movs r0, #1
	b _081CF0D2
	.align 2, 0
_081CF0C4: .4byte 0x000006AC
_081CF0C8: .4byte 0x081CF13D
_081CF0CC: .4byte 0x081CF249
_081CF0D0:
	movs r0, #0
_081CF0D2:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end PokenavCallback_Init_MonRibbonList

	thumb_func_start PokenavCallback_Init_RibbonsMonListFromSummary
PokenavCallback_Init_RibbonsMonListFromSummary: @ 0x081CF0D8
	push {r4, lr}
	movs r0, #9
	movs r1, #0x20
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CF100
	movs r0, #0x12
	bl GetSubstructPtr
	str r0, [r4, #0x1c]
	ldr r0, _081CF0FC
	str r0, [r4]
	movs r0, #1
	str r0, [r4, #0x14]
	b _081CF102
	.align 2, 0
_081CF0FC: .4byte 0x081CF15D
_081CF100:
	movs r0, #0
_081CF102:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end PokenavCallback_Init_RibbonsMonListFromSummary

	thumb_func_start GetRibbonsMonListCallback
GetRibbonsMonListCallback: @ 0x081CF108
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r1, [r0]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetRibbonsMonListCallback

	thumb_func_start FreeRibbonsMonList
FreeRibbonsMonList: @ 0x081CF11C
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r0, [r0, #0x18]
	cmp r0, #0
	bne _081CF130
	movs r0, #0x12
	bl FreePokenavSubstruct
_081CF130:
	movs r0, #9
	bl FreePokenavSubstruct
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end FreeRibbonsMonList

	thumb_func_start sub_081CF13C
sub_081CF13C: @ 0x081CF13C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #4]
	bl IsLoopedTaskActive
	cmp r0, #0
	bne _081CF14E
	ldr r0, _081CF158
	str r0, [r4]
_081CF14E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081CF158: .4byte 0x081CF15D
	thumb_func_end sub_081CF13C

	thumb_func_start HandleRibbonsMonListInput
HandleRibbonsMonListInput: @ 0x081CF15C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, _081CF170
	ldrh r1, [r2, #0x30]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081CF174
	movs r0, #1
	b _081CF1D2
	.align 2, 0
_081CF170: .4byte 0x03002360
_081CF174:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081CF180
	movs r0, #2
	b _081CF1D2
_081CF180:
	ldrh r1, [r2, #0x2e]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _081CF18E
	movs r0, #3
	b _081CF1D2
_081CF18E:
	movs r0, #0x10
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _081CF19E
	movs r0, #4
	b _081CF1D2
_081CF19E:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081CF1B4
	str r2, [r4, #0x18]
	ldr r0, _081CF1B0
	str r0, [r4]
	movs r0, #5
	b _081CF1D2
	.align 2, 0
_081CF1B0: .4byte 0x081CF1DD
_081CF1B4:
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	bne _081CF1C2
	movs r0, #0
	b _081CF1D2
_081CF1C2:
	bl PokenavList_GetSelectedIndex
	ldr r1, [r4, #0x1c]
	strh r0, [r1, #2]
	str r5, [r4, #0x18]
	ldr r0, _081CF1D8
	str r0, [r4]
	movs r0, #6
_081CF1D2:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081CF1D8: .4byte 0x081CF1E5
	thumb_func_end HandleRibbonsMonListInput

	thumb_func_start RibbonsMonMenu_ReturnToMainMenu
RibbonsMonMenu_ReturnToMainMenu: @ 0x081CF1DC
	ldr r0, _081CF1E0
	bx lr
	.align 2, 0
_081CF1E0: .4byte 0x000186A5
	thumb_func_end RibbonsMonMenu_ReturnToMainMenu

	thumb_func_start RibbonsMonMenu_ToSummaryScreen
RibbonsMonMenu_ToSummaryScreen: @ 0x081CF1E4
	ldr r0, _081CF1E8
	bx lr
	.align 2, 0
_081CF1E8: .4byte 0x000186AD
	thumb_func_end RibbonsMonMenu_ToSummaryScreen

	thumb_func_start UpdateMonListBgs
UpdateMonListBgs: @ 0x081CF1EC
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r0, [r0, #0x14]
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end UpdateMonListBgs

	thumb_func_start GetMonRibbonMonListData
GetMonRibbonMonListData: @ 0x081CF1FC
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r0, [r0, #0x1c]
	adds r0, #4
	pop {r1}
	bx r1
	thumb_func_end GetMonRibbonMonListData

	thumb_func_start GetRibbonsMonListCount
GetRibbonsMonListCount: @ 0x081CF20C
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r0, [r0, #0x1c]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end GetRibbonsMonListCount

	thumb_func_start GetMonRibbonSelectedMonData
GetMonRibbonSelectedMonData: @ 0x081CF21C
	push {r4, lr}
	movs r0, #9
	bl GetSubstructPtr
	adds r4, r0, #0
	bl PokenavList_GetSelectedIndex
	ldr r1, [r4, #0x1c]
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1, #6]
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetMonRibbonSelectedMonData

	thumb_func_start GetRibbonListMenuCurrIndex
GetRibbonListMenuCurrIndex: @ 0x081CF238
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r0, [r0, #0x1c]
	ldrh r0, [r0, #2]
	pop {r1}
	bx r1
	thumb_func_end GetRibbonListMenuCurrIndex

	thumb_func_start GetConditionSearchLoopedTask
GetConditionSearchLoopedTask: @ 0x081CF248
	push {lr}
	ldr r2, _081CF25C
	lsls r1, r0, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
_081CF25C: .4byte 0x085F5BC8
	thumb_func_end GetConditionSearchLoopedTask

	thumb_func_start BuildPartyMonRibbonList
BuildPartyMonRibbonList: @ 0x081CF260
	push {r4, r5, r6, lr}
	sub sp, #4
	movs r0, #9
	bl GetSubstructPtr
	adds r6, r0, #0
	ldr r0, [r6, #0x1c]
	movs r1, #0
	strh r1, [r0]
	ldr r0, [r6, #0x1c]
	strh r1, [r0, #2]
	ldr r1, _081CF2F0
	ldr r0, [sp]
	ands r0, r1
	movs r1, #0xe
	orrs r0, r1
	str r0, [sp]
	movs r5, #0
_081CF284:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _081CF2F4
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #5
	bl GetMonData3
	cmp r0, #0
	beq _081CF2E4
	adds r0, r4, #0
	movs r1, #6
	bl GetMonData3
	cmp r0, #0
	bne _081CF2DE
	adds r0, r4, #0
	movs r1, #4
	bl GetMonData3
	cmp r0, #0
	bne _081CF2DE
	adds r0, r4, #0
	movs r1, #0x52
	bl GetMonData3
	adds r3, r0, #0
	cmp r3, #0
	beq _081CF2DE
	lsls r1, r5, #0x18
	lsrs r1, r1, #0x10
	ldr r2, _081CF2F8
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	lsls r2, r3, #0x10
	ldr r1, _081CF2FC
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	adds r0, r6, #0
	mov r1, sp
	bl sub_081CF3C0
_081CF2DE:
	adds r5, #1
	cmp r5, #5
	ble _081CF284
_081CF2E4:
	movs r0, #1
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081CF2F0: .4byte 0xFFFFFF00
_081CF2F4: .4byte 0x02024190
_081CF2F8: .4byte 0xFFFF00FF
_081CF2FC: .4byte 0x0000FFFF
	thumb_func_end BuildPartyMonRibbonList

	thumb_func_start InitBoxMonRibbonList
InitBoxMonRibbonList: @ 0x081CF300
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	movs r1, #0
	str r1, [r0, #0x10]
	str r1, [r0, #0xc]
	movs r0, #1
	pop {r1}
	bx r1
	thumb_func_end InitBoxMonRibbonList

	thumb_func_start BuildBoxMonRibbonList
BuildBoxMonRibbonList: @ 0x081CF314
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	movs r0, #9
	bl GetSubstructPtr
	mov r8, r0
	ldr r7, [r0, #0xc]
	ldr r6, [r0, #0x10]
	movs r0, #0
	mov sb, r0
	cmp r7, #0xd
	bgt _081CF3A8
	b _081CF39C
_081CF334:
	adds r0, r7, #0
	adds r1, r6, #0
	bl CheckBoxMonSanityAt
	cmp r0, #0
	beq _081CF37A
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r6, #0x18
	lsrs r4, r0, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x52
	bl GetBoxMonDataAt
	adds r3, r0, #0
	cmp r3, #0
	beq _081CF37A
	ldr r1, _081CF390
	ldr r0, [sp]
	ands r0, r1
	orrs r0, r5
	lsls r2, r4, #8
	ldr r1, _081CF394
	ands r0, r1
	orrs r0, r2
	lsls r2, r3, #0x10
	ldr r1, _081CF398
	ands r0, r1
	orrs r0, r2
	str r0, [sp]
	mov r0, r8
	mov r1, sp
	bl sub_081CF3C0
_081CF37A:
	movs r1, #1
	add sb, r1
	adds r6, #1
	mov r0, sb
	cmp r0, #0xe
	ble _081CF39C
	mov r1, r8
	str r7, [r1, #0xc]
	str r6, [r1, #0x10]
	movs r0, #3
	b _081CF3B0
	.align 2, 0
_081CF390: .4byte 0xFFFFFF00
_081CF394: .4byte 0xFFFF00FF
_081CF398: .4byte 0x0000FFFF
_081CF39C:
	cmp r6, #0x1d
	ble _081CF334
	movs r6, #0
	adds r7, #1
	cmp r7, #0xd
	ble _081CF39C
_081CF3A8:
	movs r0, #1
	mov r1, r8
	str r0, [r1, #0x14]
	movs r0, #4
_081CF3B0:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end BuildBoxMonRibbonList

	thumb_func_start sub_081CF3C0
sub_081CF3C0: @ 0x081CF3C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r7, r1, #0
	movs r1, #0
	ldr r0, [r5, #0x1c]
	ldrh r2, [r0]
	lsrs r3, r2, #1
	cmp r2, r3
	beq _081CF3F0
	adds r6, r0, #0
	ldrh r4, [r7, #2]
_081CF3D6:
	lsls r0, r3, #2
	adds r0, r6, r0
	ldrh r0, [r0, #6]
	cmp r4, r0
	bls _081CF3E4
	adds r2, r3, #0
	b _081CF3E6
_081CF3E4:
	adds r1, r3, #1
_081CF3E6:
	subs r0, r2, r1
	lsrs r0, r0, #1
	adds r3, r1, r0
	cmp r2, r3
	bne _081CF3D6
_081CF3F0:
	ldr r0, [r5, #0x1c]
	ldrh r2, [r0]
	lsls r6, r3, #2
	cmp r2, r3
	bls _081CF414
	lsls r0, r2, #2
	subs r4, r0, #4
_081CF3FE:
	ldr r0, [r5, #0x1c]
	lsls r1, r2, #2
	adds r0, #4
	adds r1, r0, r1
	adds r0, r0, r4
	ldr r0, [r0]
	str r0, [r1]
	subs r4, #4
	subs r2, #1
	cmp r2, r3
	bhi _081CF3FE
_081CF414:
	ldr r0, [r5, #0x1c]
	adds r0, #4
	adds r0, r0, r6
	ldr r1, [r7]
	str r1, [r0]
	ldr r1, [r5, #0x1c]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_081CF3C0

	thumb_func_start PlayerHasRibbonsMon
PlayerHasRibbonsMon: @ 0x081CF42C
	push {r4, r5, r6, lr}
	movs r5, #0
_081CF430:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _081CF48C
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #5
	bl GetMonData3
	cmp r0, #0
	beq _081CF45E
	adds r0, r4, #0
	movs r1, #6
	bl GetMonData3
	cmp r0, #0
	bne _081CF45E
	adds r0, r4, #0
	movs r1, #0x53
	bl GetMonData3
	cmp r0, #0
	bne _081CF486
_081CF45E:
	adds r5, #1
	cmp r5, #5
	ble _081CF430
	movs r5, #0
_081CF466:
	movs r4, #0
	lsls r6, r5, #0x18
_081CF46A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl CheckBoxMonSanityAt
	cmp r0, #0
	beq _081CF490
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	lsrs r0, r6, #0x18
	movs r2, #0x53
	bl GetBoxMonDataAt
	cmp r0, #0
	beq _081CF490
_081CF486:
	movs r0, #1
	b _081CF49E
	.align 2, 0
_081CF48C: .4byte 0x02024190
_081CF490:
	adds r4, #1
	cmp r4, #0x1d
	ble _081CF46A
	adds r5, #1
	cmp r5, #0xd
	ble _081CF466
	movs r0, #0
_081CF49E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end PlayerHasRibbonsMon

	thumb_func_start OpenRibbonsMonList
OpenRibbonsMonList: @ 0x081CF4A4
	push {r4, lr}
	movs r1, #0x81
	lsls r1, r1, #4
	movs r0, #0xa
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CF4D4
	ldr r0, _081CF4CC
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r4, #4]
	ldr r0, _081CF4D0
	str r0, [r4]
	movs r0, #0
	str r0, [r4, #0xc]
	movs r0, #1
	b _081CF4D6
	.align 2, 0
_081CF4CC: .4byte 0x081CF58D
_081CF4D0: .4byte 0x081CF559
_081CF4D4:
	movs r0, #0
_081CF4D6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end OpenRibbonsMonList

	thumb_func_start OpenRibbonsMonListFromRibbonsSummary
OpenRibbonsMonListFromRibbonsSummary: @ 0x081CF4DC
	push {r4, lr}
	movs r1, #0x81
	lsls r1, r1, #4
	movs r0, #0xa
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CF50C
	ldr r0, _081CF504
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r4, #4]
	ldr r0, _081CF508
	str r0, [r4]
	movs r0, #1
	str r0, [r4, #0xc]
	b _081CF50E
	.align 2, 0
_081CF504: .4byte 0x081CF58D
_081CF508: .4byte 0x081CF559
_081CF50C:
	movs r0, #0
_081CF50E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end OpenRibbonsMonListFromRibbonsSummary

	thumb_func_start CreateRibbonsMonListLoopedTask
CreateRibbonsMonListLoopedTask: @ 0x081CF514
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xa
	bl GetSubstructPtr
	adds r5, r0, #0
	ldr r0, _081CF53C
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r0, [r4]
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r5, #4]
	ldr r0, _081CF540
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CF53C: .4byte 0x085F5DA8
_081CF540: .4byte 0x081CF559
	thumb_func_end CreateRibbonsMonListLoopedTask

	thumb_func_start IsRibbonsSummaryLoopedTaskActive
IsRibbonsSummaryLoopedTaskActive: @ 0x081CF544
	push {lr}
	movs r0, #0xa
	bl GetSubstructPtr
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	thumb_func_end IsRibbonsSummaryLoopedTaskActive

	thumb_func_start sub_081CF554
sub_081CF554: @ 0x081CF554
	bx r1
	.align 2, 0
	thumb_func_end sub_081CF554

	thumb_func_start GetRibbonsMonCurrentLoopedTaskActive
GetRibbonsMonCurrentLoopedTaskActive: @ 0x081CF558
	push {lr}
	movs r0, #0xa
	bl GetSubstructPtr
	ldr r0, [r0, #4]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetRibbonsMonCurrentLoopedTaskActive

	thumb_func_start FreeRibbonsMonMenu
FreeRibbonsMonMenu: @ 0x081CF56C
	push {r4, lr}
	movs r0, #0xa
	bl GetSubstructPtr
	adds r4, r0, #0
	bl DestroyPokenavList
	ldrb r0, [r4, #8]
	bl RemoveWindow
	movs r0, #0xa
	bl FreePokenavSubstruct
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end FreeRibbonsMonMenu

	thumb_func_start LoopedTask_OpenRibbonsMonList
LoopedTask_OpenRibbonsMonList: @ 0x081CF58C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xa
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #5
	bls _081CF5A0
	b _081CF6C6
_081CF5A0:
	lsls r0, r4, #2
	ldr r1, _081CF5AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CF5AC: .4byte 0x081CF5B0
_081CF5B0: @ jump table
	.4byte _081CF5C8 @ case 0
	.4byte _081CF61C @ case 1
	.4byte _081CF64A @ case 2
	.4byte _081CF668 @ case 3
	.4byte _081CF678 @ case 4
	.4byte _081CF6B2 @ case 5
_081CF5C8:
	ldr r0, _081CF60C
	movs r1, #2
	bl InitBgTemplates
	ldr r1, _081CF610
	movs r0, #0
	str r0, [sp]
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
	adds r1, r5, #0
	adds r1, #0x10
	movs r0, #1
	bl SetBgTilemapBuffer
	ldr r1, _081CF614
	movs r0, #1
	movs r2, #0
	movs r3, #0
	bl CopyToBgTilemapBuffer
	ldr r0, _081CF618
	movs r1, #0x10
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, #1
	bl CopyBgTilemapBufferToVram
_081CF606:
	movs r0, #0
	b _081CF6C8
	.align 2, 0
_081CF60C: .4byte 0x085F5DA0
_081CF610: .4byte 0x085F5BF4
_081CF614: .4byte 0x085F5CBC
_081CF618: .4byte 0x085F5BD4
_081CF61C:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CF6C2
	bl UpdateMonListBgs
	cmp r0, #0
	beq _081CF6C2
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgX
	movs r0, #1
	movs r1, #0
	movs r2, #0
	bl ChangeBgY
	movs r0, #1
	bl ShowBg
	b _081CF606
_081CF64A:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CF6C2
	ldr r0, _081CF664
	movs r1, #0x20
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	bl CreateRibbonMonsList
	b _081CF606
	.align 2, 0
_081CF664: .4byte 0x085F5D80
_081CF668:
	bl IsCreatePokenavListTaskActive
	cmp r0, #0
	bne _081CF6C2
	adds r0, r5, #0
	bl sub_081CF8E0
	b _081CF606
_081CF678:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CF6C2
	movs r0, #2
	bl ShowBg
	movs r0, #3
	bl HideBg
	movs r0, #9
	bl PrintHelpBarText
	movs r0, #1
	bl PokenavFadeScreen
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne _081CF606
	movs r0, #2
	bl LoadLeftHeaderGfxForIndex
	movs r0, #2
	movs r1, #1
	movs r2, #0
	bl ShowLeftHeaderGfx
	b _081CF606
_081CF6B2:
	bl IsPaletteFadeActive
	cmp r0, #0
	bne _081CF6C2
	bl AreLeftHeaderSpritesMoving
	cmp r0, #0
	beq _081CF6C6
_081CF6C2:
	movs r0, #2
	b _081CF6C8
_081CF6C6:
	movs r0, #4
_081CF6C8:
	add sp, #4
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end LoopedTask_OpenRibbonsMonList

	thumb_func_start sub_081CF6D0
sub_081CF6D0: @ 0x081CF6D0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xa
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CF710
	cmp r4, #1
	bgt _081CF6EA
	cmp r4, #0
	beq _081CF6F4
	b _081CF730
_081CF6EA:
	cmp r4, #2
	beq _081CF718
	cmp r4, #3
	beq _081CF722
	b _081CF730
_081CF6F4:
	movs r0, #5
	bl PlaySE
	bl PokenavList_MoveCursorUp
	cmp r0, #1
	beq _081CF70C
	cmp r0, #1
	bgt _081CF71E
	cmp r0, #0
	bne _081CF71E
	b _081CF730
_081CF70C:
	movs r0, #7
	b _081CF732
_081CF710:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CF72C
_081CF718:
	adds r0, r5, #0
	bl sub_081CF95C
_081CF71E:
	movs r0, #0
	b _081CF732
_081CF722:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CF730
_081CF72C:
	movs r0, #2
	b _081CF732
_081CF730:
	movs r0, #4
_081CF732:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CF6D0

	thumb_func_start sub_081CF738
sub_081CF738: @ 0x081CF738
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xa
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CF778
	cmp r4, #1
	bgt _081CF752
	cmp r4, #0
	beq _081CF75C
	b _081CF798
_081CF752:
	cmp r4, #2
	beq _081CF780
	cmp r4, #3
	beq _081CF78A
	b _081CF798
_081CF75C:
	movs r0, #5
	bl PlaySE
	bl PokenavList_MoveCursorDown
	cmp r0, #1
	beq _081CF774
	cmp r0, #1
	bgt _081CF786
	cmp r0, #0
	bne _081CF786
	b _081CF798
_081CF774:
	movs r0, #7
	b _081CF79A
_081CF778:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CF794
_081CF780:
	adds r0, r5, #0
	bl sub_081CF95C
_081CF786:
	movs r0, #0
	b _081CF79A
_081CF78A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CF798
_081CF794:
	movs r0, #2
	b _081CF79A
_081CF798:
	movs r0, #4
_081CF79A:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CF738

	thumb_func_start sub_081CF7A0
sub_081CF7A0: @ 0x081CF7A0
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xa
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CF7E0
	cmp r4, #1
	bgt _081CF7BA
	cmp r4, #0
	beq _081CF7C4
	b _081CF800
_081CF7BA:
	cmp r4, #2
	beq _081CF7E8
	cmp r4, #3
	beq _081CF7F2
	b _081CF800
_081CF7C4:
	movs r0, #5
	bl PlaySE
	bl PokenavList_PageUp
	cmp r0, #1
	beq _081CF7DC
	cmp r0, #1
	bgt _081CF7EE
	cmp r0, #0
	bne _081CF7EE
	b _081CF800
_081CF7DC:
	movs r0, #7
	b _081CF802
_081CF7E0:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CF7FC
_081CF7E8:
	adds r0, r5, #0
	bl sub_081CF95C
_081CF7EE:
	movs r0, #0
	b _081CF802
_081CF7F2:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CF800
_081CF7FC:
	movs r0, #2
	b _081CF802
_081CF800:
	movs r0, #4
_081CF802:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CF7A0

	thumb_func_start sub_081CF808
sub_081CF808: @ 0x081CF808
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xa
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CF848
	cmp r4, #1
	bgt _081CF822
	cmp r4, #0
	beq _081CF82C
	b _081CF868
_081CF822:
	cmp r4, #2
	beq _081CF850
	cmp r4, #3
	beq _081CF85A
	b _081CF868
_081CF82C:
	movs r0, #5
	bl PlaySE
	bl PokenavList_PageDown
	cmp r0, #1
	beq _081CF844
	cmp r0, #1
	bgt _081CF856
	cmp r0, #0
	bne _081CF856
	b _081CF868
_081CF844:
	movs r0, #7
	b _081CF86A
_081CF848:
	bl PokenavList_IsMoveWindowTaskActive
	cmp r0, #0
	bne _081CF864
_081CF850:
	adds r0, r5, #0
	bl sub_081CF95C
_081CF856:
	movs r0, #0
	b _081CF86A
_081CF85A:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CF868
_081CF864:
	movs r0, #2
	b _081CF86A
_081CF868:
	movs r0, #4
_081CF86A:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CF808

	thumb_func_start LoopedTask_RibbonsListReturnToMainMenu
LoopedTask_RibbonsListReturnToMainMenu: @ 0x081CF870
	push {lr}
	cmp r0, #0
	beq _081CF87C
	cmp r0, #1
	beq _081CF890
	b _081CF8A8
_081CF87C:
	movs r0, #5
	bl PlaySE
	movs r0, #0
	bl PokenavFadeScreen
	bl SlideMenuHeaderDown
	movs r0, #0
	b _081CF8AA
_081CF890:
	bl IsPaletteFadeActive
	cmp r0, #0
	bne _081CF8A0
	bl MainMenuLoopedTaskIsBusy
	cmp r0, #0
	beq _081CF8A4
_081CF8A0:
	movs r0, #2
	b _081CF8AA
_081CF8A4:
	bl SetLeftHeaderSpritesInvisibility
_081CF8A8:
	movs r0, #4
_081CF8AA:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end LoopedTask_RibbonsListReturnToMainMenu

	thumb_func_start LoopedTask_RibbonsListOpenSummary
LoopedTask_RibbonsListOpenSummary: @ 0x081CF8B0
	push {lr}
	cmp r0, #0
	beq _081CF8BC
	cmp r0, #1
	beq _081CF8CC
	b _081CF8D8
_081CF8BC:
	movs r0, #5
	bl PlaySE
	movs r0, #0
	bl PokenavFadeScreen
	movs r0, #0
	b _081CF8DA
_081CF8CC:
	bl IsPaletteFadeActive
	cmp r0, #0
	beq _081CF8D8
	movs r0, #2
	b _081CF8DA
_081CF8D8:
	movs r0, #4
_081CF8DA:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end LoopedTask_RibbonsListOpenSummary

	thumb_func_start sub_081CF8E0
sub_081CF8E0: @ 0x081CF8E0
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081CF94C
	bl AddWindow
	movs r6, #0
	strh r0, [r5, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl PutWindowTilemap
	bl GetRibbonsMonListCount
	adds r1, r0, #0
	ldr r4, _081CF950
	adds r0, r4, #0
	movs r2, #1
	movs r3, #3
	bl ConvertIntToDecimalStringN
	bl DynamicPlaceholderTextUtil_Reset
	movs r0, #0
	adds r1, r4, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	ldr r4, _081CF954
	ldr r1, _081CF958
	adds r0, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldrb r0, [r5, #8]
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	str r6, [sp, #8]
	movs r1, #1
	adds r2, r4, #0
	movs r3, #0
	bl AddTextPrinterParameterized
	ldrb r0, [r5, #8]
	movs r1, #1
	bl CopyWindowToVram
	adds r0, r5, #0
	bl sub_081CF95C
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081CF94C: .4byte 0x085F5DC4
_081CF950: .4byte 0x02021C40
_081CF954: .4byte 0x02021C54
_081CF958: .4byte 0x085F5DCC
	thumb_func_end sub_081CF8E0

	thumb_func_start sub_081CF95C
sub_081CF95C: @ 0x081CF95C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	bl PokenavList_GetSelectedIndex
	adds r1, r0, #0
	ldr r4, _081CF9A0
	adds r1, #1
	adds r0, r4, #0
	movs r2, #1
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldrb r0, [r5, #8]
	movs r1, #2
	str r1, [sp]
	movs r1, #0xff
	str r1, [sp, #4]
	movs r1, #0
	str r1, [sp, #8]
	movs r1, #1
	adds r2, r4, #0
	movs r3, #0
	bl AddTextPrinterParameterized
	ldrb r0, [r5, #8]
	movs r1, #2
	bl CopyWindowToVram
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CF9A0: .4byte 0x02021C40
	thumb_func_end sub_081CF95C

	thumb_func_start CreateRibbonMonsList
CreateRibbonMonsList: @ 0x081CF9A4
	push {r4, lr}
	sub sp, #0x18
	bl GetMonRibbonMonListData
	str r0, [sp]
	bl GetRibbonsMonListCount
	mov r1, sp
	movs r4, #0
	strh r0, [r1, #4]
	movs r0, #4
	strb r0, [r1, #8]
	bl GetRibbonListMenuCurrIndex
	mov r1, sp
	strh r0, [r1, #6]
	movs r0, #0xe
	strb r0, [r1, #9]
	movs r0, #0x10
	strb r0, [r1, #0xa]
	movs r0, #1
	strb r0, [r1, #0xb]
	movs r0, #8
	strb r0, [r1, #0xc]
	movs r0, #2
	strb r0, [r1, #0xd]
	ldr r0, _081CF9F0
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	ldr r0, _081CF9F4
	movs r2, #0
	bl CreatePokenavList
	add sp, #0x18
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CF9F0: .4byte 0x081CF9F9
_081CF9F4: .4byte 0x085F5DA4
	thumb_func_end CreateRibbonMonsList

	thumb_func_start sub_081CF9F8
sub_081CF9F8: @ 0x081CF9F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r1
	adds r7, r0, #0
	bl DynamicPlaceholderTextUtil_Reset
	ldrb r0, [r7]
	cmp r0, #0xe
	bne _081CFA44
	ldrb r1, [r7, #1]
	movs r0, #0x64
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _081CFA3C
	adds r4, r4, r0
	adds r0, r4, #0
	bl GetMonGender
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r4, #0
	bl GetLevelFromMonExp
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _081CFA40
	adds r0, r4, #0
	movs r1, #2
	bl GetMonData3
	b _081CFA6A
	.align 2, 0
_081CFA3C: .4byte 0x02024190
_081CFA40: .4byte 0x02021C68
_081CFA44:
	ldrb r0, [r7]
	ldrb r1, [r7, #1]
	bl GetBoxedMonPtr
	adds r4, r0, #0
	bl GetBoxMonGender
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r4, #0
	bl GetLevelFromBoxMonExp
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _081CFAD0
	adds r0, r4, #0
	movs r1, #2
	bl GetBoxMonData
_081CFA6A:
	ldr r4, _081CFAD0
	adds r0, r4, #0
	bl StringGet_Nickname
	ldr r0, _081CFAD4
	mov r8, r0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #5
	bl StringCopyPadded
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r5, _081CFAD8
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #3
	bl StringCopyPadded
	ldrh r1, [r7, #2]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #2
	bl ConvertIntToDecimalStringN
	movs r0, #0
	mov r1, r8
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, #1
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, #2
	adds r1, r4, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	cmp r6, #0xfe
	beq _081CFAE0
	cmp r6, #0xfe
	bgt _081CFAE8
	cmp r6, #0
	bne _081CFAE8
	ldr r1, _081CFADC
	b _081CFAEA
	.align 2, 0
_081CFAD0: .4byte 0x02021C68
_081CFAD4: .4byte 0x02021C40
_081CFAD8: .4byte 0x02021C54
_081CFADC: .4byte 0x085F5DD3
_081CFAE0:
	ldr r1, _081CFAE4
	b _081CFAEA
	.align 2, 0
_081CFAE4: .4byte 0x085F5DEB
_081CFAE8:
	ldr r1, _081CFAFC
_081CFAEA:
	mov r0, sb
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CFAFC: .4byte 0x085F5E03
	thumb_func_end sub_081CF9F8
