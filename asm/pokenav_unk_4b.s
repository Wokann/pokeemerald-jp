.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_081CC718
sub_081CC718: @ 0x081CC718
	push {r4, lr}
	ldr r1, _081CC748
	movs r0, #0xb
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CC75C
	ldr r1, _081CC74C
	adds r0, r4, r1
	bl sub_081D151C
	bl sub_081CD0D0
	ldr r1, _081CC750
	movs r0, #0x14
	strh r0, [r1]
	ldr r0, _081CC754
	adds r1, r4, r0
	ldr r0, _081CC758
	str r0, [r1]
	movs r0, #1
	b _081CC75E
	.align 2, 0
_081CC748: .4byte 0x0000678C
_081CC74C: .4byte 0x00006428
_081CC750: .4byte 0x03002350
_081CC754: .4byte 0x00006304
_081CC758: .4byte 0x081CC7CD
_081CC75C:
	movs r0, #0
_081CC75E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_081CC718

	thumb_func_start sub_081CC764
sub_081CC764: @ 0x081CC764
	push {r4, lr}
	ldr r1, _081CC794
	movs r0, #0xb
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CC7A8
	ldr r1, _081CC798
	adds r0, r4, r1
	bl sub_081D151C
	bl sub_081CD158
	ldr r1, _081CC79C
	movs r0, #0x14
	strh r0, [r1]
	ldr r0, _081CC7A0
	adds r1, r4, r0
	ldr r0, _081CC7A4
	str r0, [r1]
	movs r0, #1
	b _081CC7AA
	.align 2, 0
_081CC794: .4byte 0x0000678C
_081CC798: .4byte 0x00006428
_081CC79C: .4byte 0x03002350
_081CC7A0: .4byte 0x00006304
_081CC7A4: .4byte 0x081CC7CD
_081CC7A8:
	movs r0, #0
_081CC7AA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_081CC764

	thumb_func_start sub_081CC7B0
sub_081CC7B0: @ 0x081CC7B0
	push {lr}
	movs r0, #0xb
	bl GetSubstructPtr
	ldr r2, _081CC7C8
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
_081CC7C8: .4byte 0x00006304
	thumb_func_end sub_081CC7B0

	thumb_func_start sub_081CC7CC
sub_081CC7CC: @ 0x081CC7CC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x12
	bl GetSubstructPtr
	adds r5, r0, #0
	adds r0, r4, #0
	bl sub_081CC924
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _081CC840
	ldr r0, _081CC824
	ldrh r1, [r0, #0x2e]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _081CC810
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081CC840
	movs r1, #0xc6
	lsls r1, r1, #7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CC830
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	subs r0, #1
	cmp r1, r0
	bne _081CC840
_081CC810:
	movs r0, #5
	bl PlaySE
	ldr r0, _081CC828
	adds r1, r4, r0
	ldr r0, _081CC82C
	str r0, [r1]
	movs r2, #2
	b _081CC840
	.align 2, 0
_081CC824: .4byte 0x03002360
_081CC828: .4byte 0x00006304
_081CC82C: .4byte 0x081CC8DD
_081CC830:
	movs r0, #5
	bl PlaySE
	movs r2, #5
	ldr r0, _081CC848
	adds r1, r4, r0
	ldr r0, _081CC84C
	str r0, [r1]
_081CC840:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081CC848: .4byte 0x00006304
_081CC84C: .4byte 0x081CC851
	thumb_func_end sub_081CC7CC

	thumb_func_start sub_081CC850
sub_081CC850: @ 0x081CC850
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r4, #0
	bl HandleMonMarkingsMenuInput
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CC8CA
	bl sub_081CE648
	ldr r1, _081CC8A8
	adds r5, r6, r1
	movs r1, #0
	ldrsb r1, [r5, r1]
	ldr r2, _081CC8AC
	adds r4, r6, r2
	adds r1, r4, r1
	strb r0, [r1]
	movs r0, #0x12
	bl GetSubstructPtr
	ldrh r1, [r0, #2]
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r2, [r0, #4]
	ldrb r3, [r0, #5]
	movs r0, #0
	ldrsb r0, [r5, r0]
	adds r4, r4, r0
	ldrb r1, [r4]
	mov r0, sp
	strb r1, [r0]
	cmp r2, #0xe
	bne _081CC8B4
	movs r0, #0x64
	muls r0, r3, r0
	ldr r1, _081CC8B0
	adds r0, r0, r1
	movs r1, #8
	mov r2, sp
	bl SetMonData
	b _081CC8C0
	.align 2, 0
_081CC8A8: .4byte 0x00006786
_081CC8AC: .4byte 0x00006783
_081CC8B0: .4byte 0x02024190
_081CC8B4:
	adds r0, r2, #0
	adds r1, r3, #0
	movs r2, #8
	mov r3, sp
	bl SetBoxMonDataAt
_081CC8C0:
	ldr r0, _081CC8D4
	adds r1, r6, r0
	ldr r0, _081CC8D8
	str r0, [r1]
	movs r4, #6
_081CC8CA:
	adds r0, r4, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081CC8D4: .4byte 0x00006304
_081CC8D8: .4byte 0x081CC7CD
	thumb_func_end sub_081CC850

	thumb_func_start sub_081CC8DC
sub_081CC8DC: @ 0x081CC8DC
	push {lr}
	movs r1, #0xc6
	lsls r1, r1, #7
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CC8F4
	ldr r0, _081CC8F0
	b _081CC8F6
	.align 2, 0
_081CC8F0: .4byte 0x000186AA
_081CC8F4:
	ldr r0, _081CC8FC
_081CC8F6:
	pop {r1}
	bx r1
	.align 2, 0
_081CC8FC: .4byte 0x000186A2
	thumb_func_end sub_081CC8DC

	thumb_func_start sub_081CC900
sub_081CC900: @ 0x081CC900
	push {lr}
	movs r0, #0xb
	bl GetSubstructPtr
	movs r1, #0xc6
	lsls r1, r1, #7
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081CC91A
	movs r0, #0x12
	bl FreePokenavSubstruct
_081CC91A:
	movs r0, #0xb
	bl FreePokenavSubstruct
	pop {r0}
	bx r0
	thumb_func_end sub_081CC900

	thumb_func_start sub_081CC924
sub_081CC924: @ 0x081CC924
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x12
	bl GetSubstructPtr
	adds r2, r0, #0
	movs r3, #0
	ldr r0, _081CC95C
	ldrh r1, [r0, #0x2c]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _081CC960
	movs r1, #0xc6
	lsls r1, r1, #7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CC950
	ldrh r0, [r2, #2]
	cmp r0, #0
	beq _081CC98E
_081CC950:
	movs r0, #5
	bl PlaySE
	movs r0, #1
	b _081CC986
	.align 2, 0
_081CC95C: .4byte 0x03002360
_081CC960:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _081CC98E
	movs r1, #0xc6
	lsls r1, r1, #7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081CC97E
	ldrh r1, [r2, #2]
	ldrh r0, [r2]
	subs r0, #1
	cmp r1, r0
	bge _081CC98E
_081CC97E:
	movs r0, #5
	bl PlaySE
	movs r0, #0
_081CC986:
	bl sub_081CC998
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_081CC98E:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CC924

	thumb_func_start sub_081CC998
sub_081CC998: @ 0x081CC998
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r0, #0xb
	bl GetSubstructPtr
	adds r4, r0, #0
	movs r0, #0x12
	bl GetSubstructPtr
	adds r5, r0, #0
	mov r0, r8
	cmp r0, #0
	beq _081CC9C4
	ldr r1, _081CC9C0
	adds r0, r4, r1
	b _081CC9C8
	.align 2, 0
_081CC9C0: .4byte 0x00006788
_081CC9C4:
	ldr r2, _081CCA08
	adds r0, r4, r2
_081CC9C8:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r7, r0, #0
	ldr r1, _081CCA0C
	adds r0, r4, r1
	ldr r2, _081CCA10
	adds r1, r4, r2
	movs r2, #0
	ldrsb r2, [r1, r2]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	ldr r3, _081CCA14
	adds r1, r1, r3
	adds r1, r4, r1
	lsls r2, r7, #2
	adds r2, r2, r7
	lsls r2, r2, #2
	adds r2, r2, r3
	adds r2, r4, r2
	bl sub_081D15CC
	ldrh r6, [r5, #2]
	bl sub_081CD4BC
	cmp r0, #0
	beq _081CCA18
	ldrh r1, [r5]
	b _081CCA1C
	.align 2, 0
_081CCA08: .4byte 0x00006787
_081CCA0C: .4byte 0x00006428
_081CCA10: .4byte 0x00006786
_081CCA14: .4byte 0x0000643C
_081CCA18:
	ldrh r1, [r5]
	subs r1, #1
_081CCA1C:
	eors r1, r6
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	adds r6, r0, #0
	mov r0, r8
	cmp r0, #0
	beq _081CCA72
	ldr r1, _081CCA60
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r1, #1
	adds r3, r4, r1
	strb r0, [r3]
	ldr r0, _081CCA64
	adds r1, r4, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r7, [r1]
	ldrb r1, [r3]
	ldr r2, _081CCA68
	adds r0, r4, r2
	strb r1, [r0]
	ldrh r0, [r5, #2]
	cmp r0, #0
	bne _081CCA52
	ldrh r0, [r5]
_081CCA52:
	subs r1, r0, #1
	strh r1, [r5, #2]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _081CCA6C
	subs r1, #1
	b _081CCAC4
	.align 2, 0
_081CCA60: .4byte 0x00006787
_081CCA64: .4byte 0x00006786
_081CCA68: .4byte 0x00006789
_081CCA6C:
	ldrh r0, [r5]
	subs r1, r0, #1
	b _081CCAC4
_081CCA72:
	ldr r0, _081CCAA0
	adds r2, r4, r0
	ldrb r0, [r2]
	ldr r1, _081CCAA4
	adds r3, r4, r1
	strb r0, [r3]
	ldr r0, _081CCAA8
	adds r1, r4, r0
	ldrb r0, [r1]
	strb r0, [r2]
	strb r7, [r1]
	ldrb r1, [r3]
	ldr r2, _081CCAAC
	adds r0, r4, r2
	strb r1, [r0]
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	subs r0, #1
	cmp r1, r0
	bge _081CCAB0
	adds r0, r1, #1
	b _081CCAB2
	.align 2, 0
_081CCAA0: .4byte 0x00006788
_081CCAA4: .4byte 0x00006787
_081CCAA8: .4byte 0x00006786
_081CCAAC: .4byte 0x00006789
_081CCAB0:
	movs r0, #0
_081CCAB2:
	strh r0, [r5, #2]
	ldrh r1, [r5, #2]
	ldrh r0, [r5]
	subs r0, #1
	cmp r1, r0
	bge _081CCAC2
	adds r1, #1
	b _081CCAC4
_081CCAC2:
	movs r1, #0
_081CCAC4:
	ldr r2, _081CCAD8
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r4, [r5, #2]
	bl sub_081CD4BC
	cmp r0, #0
	beq _081CCADC
	ldrh r1, [r5]
	b _081CCAE0
	.align 2, 0
_081CCAD8: .4byte 0x00006302
_081CCADC:
	ldrh r1, [r5]
	subs r1, #1
_081CCAE0:
	eors r1, r4
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	cmp r6, #0
	bne _081CCAF0
	movs r0, #3
	b _081CCAFA
_081CCAF0:
	cmp r0, #0
	beq _081CCAF8
	movs r0, #1
	b _081CCAFA
_081CCAF8:
	movs r0, #4
_081CCAFA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end sub_081CC998

	thumb_func_start sub_081CCB04
sub_081CCB04: @ 0x081CCB04
	push {r4, lr}
	movs r0, #0xb
	bl GetSubstructPtr
	adds r4, r0, #0
	movs r0, #0x12
	bl GetSubstructPtr
	adds r2, r0, #0
	ldr r1, _081CCB2C
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #9
	bls _081CCB22
	b _081CCC70
_081CCB22:
	lsls r0, r0, #2
	ldr r1, _081CCB30
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CCB2C: .4byte 0x0000678A
_081CCB30: .4byte 0x081CCB34
_081CCB34: @ jump table
	.4byte _081CCB5C @ case 0
	.4byte _081CCB68 @ case 1
	.4byte _081CCB74 @ case 2
	.4byte _081CCB80 @ case 3
	.4byte _081CCBD0 @ case 4
	.4byte _081CCBE8 @ case 5
	.4byte _081CCC00 @ case 6
	.4byte _081CCC18 @ case 7
	.4byte _081CCC30 @ case 8
	.4byte _081CCC48 @ case 9
_081CCB5C:
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r1, #0
	bl sub_081CCF84
	b _081CCC70
_081CCB68:
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r1, #0
	bl sub_081CD17C
	b _081CCC70
_081CCB74:
	movs r1, #2
	ldrsh r0, [r2, r1]
	movs r1, #0
	bl sub_081CD2F8
	b _081CCC70
_081CCB80:
	ldrh r0, [r2]
	cmp r0, #1
	bne _081CCBA8
	ldr r2, _081CCBA4
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	movs r0, #1
	b _081CCC7C
	.align 2, 0
_081CCBA4: .4byte 0x00006786
_081CCBA8:
	ldr r0, _081CCBC4
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _081CCBC8
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _081CCBCC
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	b _081CCC70
	.align 2, 0
_081CCBC4: .4byte 0x00006786
_081CCBC8: .4byte 0x00006787
_081CCBCC: .4byte 0x00006788
_081CCBD0:
	ldrh r0, [r2, #2]
	adds r0, #1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CCBDC
	movs r0, #0
_081CCBDC:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	bl sub_081CCF84
	b _081CCC70
_081CCBE8:
	ldrh r0, [r2, #2]
	adds r0, #1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CCBF4
	movs r0, #0
_081CCBF4:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	bl sub_081CD17C
	b _081CCC70
_081CCC00:
	ldrh r0, [r2, #2]
	adds r0, #1
	ldrh r2, [r2]
	cmp r0, r2
	blt _081CCC0C
	movs r0, #0
_081CCC0C:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #1
	bl sub_081CD2F8
	b _081CCC70
_081CCC18:
	ldrh r0, [r2, #2]
	subs r0, #1
	cmp r0, #0
	bge _081CCC24
	ldrh r0, [r2]
	subs r0, #1
_081CCC24:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #2
	bl sub_081CCF84
	b _081CCC70
_081CCC30:
	ldrh r0, [r2, #2]
	subs r0, #1
	cmp r0, #0
	bge _081CCC3C
	ldrh r0, [r2]
	subs r0, #1
_081CCC3C:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #2
	bl sub_081CD17C
	b _081CCC70
_081CCC48:
	ldrh r0, [r2, #2]
	subs r0, #1
	cmp r0, #0
	bge _081CCC54
	ldrh r0, [r2]
	subs r0, #1
_081CCC54:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #2
	bl sub_081CD2F8
	ldr r2, _081CCC6C
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CCC7C
	.align 2, 0
_081CCC6C: .4byte 0x0000678A
_081CCC70:
	ldr r0, _081CCC84
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #0
_081CCC7C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081CCC84: .4byte 0x0000678A
	thumb_func_end sub_081CCB04

	thumb_func_start sub_081CCC88
sub_081CCC88: @ 0x081CCC88
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r5, r4, #0
	movs r0, #0xb
	bl GetSubstructPtr
	adds r1, r0, #0
	cmp r4, #1
	beq _081CCCC8
	cmp r4, #1
	bgt _081CCCA6
	cmp r4, #0
	beq _081CCCAC
	b _081CCD04
_081CCCA6:
	cmp r5, #2
	beq _081CCCE4
	b _081CCD04
_081CCCAC:
	ldr r2, _081CCCC0
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r2, _081CCCC4
	adds r1, r1, r2
	ldrb r1, [r1]
	bl sub_081CCF84
	b _081CCD04
	.align 2, 0
_081CCCC0: .4byte 0x00006302
_081CCCC4: .4byte 0x00006789
_081CCCC8:
	ldr r2, _081CCCDC
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r2, _081CCCE0
	adds r1, r1, r2
	ldrb r1, [r1]
	bl sub_081CD17C
	b _081CCD04
	.align 2, 0
_081CCCDC: .4byte 0x00006302
_081CCCE0: .4byte 0x00006789
_081CCCE4:
	ldr r2, _081CCCFC
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r2, _081CCD00
	adds r1, r1, r2
	ldrb r1, [r1]
	bl sub_081CD2F8
	movs r0, #1
	b _081CCD06
	.align 2, 0
_081CCCFC: .4byte 0x00006302
_081CCD00: .4byte 0x00006789
_081CCD04:
	movs r0, #0
_081CCD06:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CCC88

	thumb_func_start sub_081CCD0C
sub_081CCD0C: @ 0x081CCD0C
	push {r4, lr}
	adds r4, r0, #0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	b _081CCD24
_081CCD16:
	strb r3, [r4]
	adds r1, #1
	adds r4, #1
	lsls r0, r2, #0x10
	ldr r2, _081CCD60
	adds r0, r0, r2
	lsrs r2, r0, #0x10
_081CCD24:
	ldrb r3, [r1]
	adds r0, r3, #0
	cmp r0, #0xff
	bne _081CCD16
	adds r1, r2, #0
	lsls r0, r1, #0x10
	ldr r2, _081CCD60
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	cmp r1, #0
	ble _081CCD52
	movs r3, #0
_081CCD3E:
	strb r3, [r4]
	adds r4, #1
	adds r1, r2, #0
	lsls r0, r1, #0x10
	ldr r2, _081CCD60
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	cmp r1, #0
	bgt _081CCD3E
_081CCD52:
	movs r0, #0xff
	strb r0, [r4]
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081CCD60: .4byte 0xFFFF0000
	thumb_func_end sub_081CCD0C

	thumb_func_start sub_081CCD64
sub_081CCD64: @ 0x081CCD64
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov sl, r2
	movs r0, #0x12
	bl GetSubstructPtr
	lsls r4, r4, #2
	adds r0, r0, r4
	ldrb r4, [r0, #4]
	mov r8, r4
	ldrb r6, [r0, #5]
	mov sb, r6
	movs r0, #0xfc
	strb r0, [r5]
	adds r5, #1
	movs r0, #4
	strb r0, [r5]
	adds r5, #1
	movs r0, #8
	strb r0, [r5]
	adds r5, #1
	movs r0, #0
	strb r0, [r5]
	adds r5, #1
	movs r0, #9
	strb r0, [r5]
	adds r5, #1
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x2d
	movs r3, #0
	bl GetBoxOrPartyMonData
	cmp r0, #0
	beq _081CCDD0
	ldr r1, _081CCDCC
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0xc
	bl StringCopyPadded
	b _081CCF6C
	.align 2, 0
_081CCDCC: .4byte 0x085C8C62
_081CCDD0:
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #2
	adds r3, r5, #0
	bl GetBoxOrPartyMonData
	adds r0, r5, #0
	bl StringGet_Nickname
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xb
	movs r3, #0
	bl GetBoxOrPartyMonData
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r4, #0xe
	bne _081CCE20
	movs r0, #0x64
	adds r4, r6, #0
	muls r4, r0, r4
	ldr r0, _081CCE1C
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x38
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r0, r4, #0
	bl GetMonGender
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	b _081CCE3E
	.align 2, 0
_081CCE1C: .4byte 0x02024190
_081CCE20:
	mov r0, r8
	mov r1, sb
	bl GetBoxedMonPtr
	adds r4, r0, #0
	bl GetBoxMonGender
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r4, #0
	bl GetLevelFromBoxMonExp
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_081CCE3E:
	cmp r7, #0x1d
	beq _081CCE46
	cmp r7, #0x20
	bne _081CCE5C
_081CCE46:
	lsls r1, r7, #1
	adds r1, r1, r7
	lsls r1, r1, #1
	ldr r0, _081CCE64
	adds r1, r1, r0
	adds r0, r5, #0
	bl StringCompare
	cmp r0, #0
	bne _081CCE5C
	movs r6, #0xff
_081CCE5C:
	adds r3, r5, #0
	movs r4, #0
	b _081CCE70
	.align 2, 0
_081CCE64: .4byte 0x082EA31C
_081CCE68:
	adds r3, #1
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_081CCE70:
	ldrb r0, [r3]
	cmp r0, #0xff
	bne _081CCE68
	adds r1, r4, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r1, #4
	bhi _081CCE94
	movs r2, #0
_081CCE84:
	strb r2, [r3]
	adds r3, #1
	adds r1, r4, #0
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r1, #4
	bls _081CCE84
_081CCE94:
	movs r0, #0
	strb r0, [r3]
	adds r3, #1
	cmp r6, #0
	beq _081CCEA4
	cmp r6, #0xfe
	beq _081CCECA
	b _081CCEEE
_081CCEA4:
	movs r1, #0xfc
	strb r1, [r3]
	adds r3, #1
	movs r0, #1
	strb r0, [r3]
	adds r3, #1
	movs r0, #4
	strb r0, [r3]
	adds r3, #1
	strb r1, [r3]
	adds r3, #1
	movs r0, #3
	strb r0, [r3]
	adds r3, #1
	movs r0, #5
	strb r0, [r3]
	adds r3, #1
	movs r0, #0xb5
	b _081CCEEE
_081CCECA:
	movs r1, #0xfc
	strb r1, [r3]
	adds r3, #1
	movs r0, #1
	strb r0, [r3]
	adds r3, #1
	movs r0, #6
	strb r0, [r3]
	adds r3, #1
	strb r1, [r3]
	adds r3, #1
	movs r0, #3
	strb r0, [r3]
	adds r3, #1
	movs r0, #7
	strb r0, [r3]
	adds r3, #1
	movs r0, #0xb6
_081CCEEE:
	strb r0, [r3]
	adds r3, #1
	movs r0, #0xfc
	strb r0, [r3]
	adds r3, #1
	movs r0, #4
	strb r0, [r3]
	adds r3, #1
	movs r0, #8
	strb r0, [r3]
	adds r3, #1
	movs r5, #0
	strb r5, [r3]
	adds r3, #1
	movs r0, #9
	strb r0, [r3]
	adds r3, #1
	movs r0, #0xba
	strb r0, [r3]
	adds r3, #1
	movs r0, #0xf9
	strb r0, [r3]
	adds r3, #1
	movs r0, #5
	strb r0, [r3]
	adds r3, #1
	adds r4, r3, #0
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	adds r3, r0, #0
	subs r4, r3, r4
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	strb r5, [r3]
	adds r3, #1
	mov r0, sl
	cmp r0, #0
	bne _081CCF66
	movs r0, #3
	subs r0, r0, r4
	lsls r0, r0, #0x10
	ldr r1, _081CCF7C
	adds r0, r0, r1
	lsrs r4, r0, #0x10
	ldr r0, _081CCF80
	cmp r4, r0
	beq _081CCF66
	movs r2, #0
	adds r1, r0, #0
_081CCF58:
	strb r2, [r3]
	adds r3, #1
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r1
	bne _081CCF58
_081CCF66:
	movs r0, #0xff
	strb r0, [r3]
	adds r0, r3, #0
_081CCF6C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081CCF7C: .4byte 0xFFFF0000
_081CCF80: .4byte 0x0000FFFF
	thumb_func_end sub_081CCD64

	thumb_func_start sub_081CCF84
sub_081CCF84: @ 0x081CCF84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	movs r0, #0xb
	bl GetSubstructPtr
	adds r5, r0, #0
	movs r0, #0x12
	bl GetSubstructPtr
	adds r7, r0, #0
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r4, r0, #0x10
	bl sub_081CD4BC
	cmp r0, #0
	beq _081CCFBA
	ldrh r2, [r7]
	cmp r4, r2
	bne _081CCFC2
	b _081CD060
_081CCFBA:
	ldrh r0, [r7]
	subs r0, #1
	cmp r4, r0
	beq _081CD060
_081CCFC2:
	lsls r0, r6, #6
	ldr r1, _081CD024
	adds r0, r0, r1
	adds r0, r5, r0
	mov r2, r8
	lsls r4, r2, #0x10
	lsrs r1, r4, #0x10
	movs r2, #0
	bl sub_081CCD64
	asrs r4, r4, #0xe
	adds r4, r7, r4
	ldrb r3, [r4, #4]
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r4, r0, #3
	ldr r1, _081CD028
	adds r0, r5, r1
	adds r0, r0, r4
	movs r2, #0
	movs r1, #0xfc
	strb r1, [r0]
	ldr r1, _081CD02C
	adds r0, r5, r1
	adds r0, r0, r4
	movs r1, #4
	strb r1, [r0]
	ldr r1, _081CD030
	adds r0, r5, r1
	adds r0, r0, r4
	movs r1, #8
	strb r1, [r0]
	ldr r1, _081CD034
	adds r0, r5, r1
	adds r0, r0, r4
	strb r2, [r0]
	ldr r2, _081CD038
	adds r0, r5, r2
	adds r0, r0, r4
	movs r1, #9
	strb r1, [r0]
	cmp r3, #0xe
	bne _081CD044
	adds r0, r4, r5
	ldr r1, _081CD03C
	adds r0, r0, r1
	ldr r1, _081CD040
	b _081CD054
	.align 2, 0
_081CD024: .4byte 0x00006368
_081CD028: .4byte 0x00006320
_081CD02C: .4byte 0x00006321
_081CD030: .4byte 0x00006322
_081CD034: .4byte 0x00006323
_081CD038: .4byte 0x00006324
_081CD03C: .4byte 0x00006325
_081CD040: .4byte 0x085CB7C6
_081CD044:
	adds r4, r4, r5
	ldr r2, _081CD05C
	adds r4, r4, r2
	adds r0, r3, #0
	bl GetBoxNamePtr
	adds r1, r0, #0
	adds r0, r4, #0
_081CD054:
	movs r2, #8
	bl sub_081CCD0C
	b _081CD0BC
	.align 2, 0
_081CD05C: .4byte 0x00006325
_081CD060:
	movs r1, #0
	lsls r4, r6, #6
	lsls r0, r6, #1
	mov r8, r0
	adds r3, r4, #0
	ldr r0, _081CD0C8
	adds r2, r5, r0
	movs r7, #0
_081CD070:
	adds r0, r1, r3
	adds r0, r2, r0
	strb r7, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0xb
	bls _081CD070
	adds r1, r1, r4
	ldr r2, _081CD0C8
	adds r0, r5, r2
	adds r0, r0, r1
	movs r1, #0xff
	strb r1, [r0]
	movs r1, #0
	mov r2, r8
	adds r0, r2, r6
	lsls r3, r0, #3
	ldr r0, _081CD0CC
	adds r2, r5, r0
	movs r4, #0
_081CD09A:
	adds r0, r1, r3
	adds r0, r2, r0
	strb r4, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #7
	bls _081CD09A
	mov r2, r8
	adds r0, r2, r6
	lsls r0, r0, #3
	adds r0, r1, r0
	ldr r2, _081CD0CC
	adds r1, r5, r2
	adds r1, r1, r0
	movs r0, #0xff
	strb r0, [r1]
_081CD0BC:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CD0C8: .4byte 0x00006368
_081CD0CC: .4byte 0x00006320
	thumb_func_end sub_081CCF84

	thumb_func_start sub_081CD0D0
sub_081CD0D0: @ 0x081CD0D0
	push {r4, r5, r6, r7, lr}
	movs r0, #0xb
	bl GetSubstructPtr
	adds r7, r0, #0
	ldr r1, _081CD0F4
	movs r0, #0x12
	bl AllocSubstruct
	adds r6, r0, #0
	movs r0, #0xc6
	lsls r0, r0, #7
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	movs r4, #0
	movs r5, #0
	b _081CD124
	.align 2, 0
_081CD0F4: .4byte 0x000006AC
_081CD0F8:
	movs r0, #0x64
	muls r0, r4, r0
	ldr r1, _081CD150
	adds r0, r0, r1
	movs r1, #0x2d
	bl GetMonData3
	adds r2, r0, #0
	cmp r2, #0
	bne _081CD11E
	lsls r1, r5, #2
	adds r1, r6, r1
	movs r0, #0xe
	strb r0, [r1, #4]
	strb r4, [r1, #5]
	strh r2, [r1, #6]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_081CD11E:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_081CD124:
	bl CalculatePlayerPartyCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	blo _081CD0F8
	lsls r0, r5, #2
	adds r0, r6, r0
	movs r1, #0
	strb r1, [r0, #4]
	strb r1, [r0, #5]
	movs r2, #0
	strh r1, [r0, #6]
	strh r1, [r6, #2]
	adds r0, r5, #1
	strh r0, [r6]
	ldr r1, _081CD154
	adds r0, r7, r1
	strb r2, [r0]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CD150: .4byte 0x02024190
_081CD154: .4byte 0x0000678A
	thumb_func_end sub_081CD0D0

	thumb_func_start sub_081CD158
sub_081CD158: @ 0x081CD158
	push {lr}
	movs r0, #0xb
	bl GetSubstructPtr
	movs r1, #0xc6
	lsls r1, r1, #7
	adds r2, r0, r1
	movs r3, #0
	movs r1, #1
	strb r1, [r2]
	ldr r1, _081CD178
	adds r0, r0, r1
	strb r3, [r0]
	pop {r0}
	bx r0
	.align 2, 0
_081CD178: .4byte 0x0000678A
	thumb_func_end sub_081CD158

	thumb_func_start sub_081CD17C
sub_081CD17C: @ 0x081CD17C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	movs r0, #0xb
	bl GetSubstructPtr
	mov r8, r0
	movs r0, #0x12
	bl GetSubstructPtr
	adds r4, r0, #0
	lsls r0, r6, #0x10
	asrs r5, r0, #0x10
	bl sub_081CD4BC
	cmp r0, #0
	beq _081CD1B2
	ldrh r0, [r4]
	cmp r5, r0
	bne _081CD1BA
	b _081CD2A8
_081CD1B2:
	ldrh r0, [r4]
	subs r0, #1
	cmp r5, r0
	beq _081CD2A8
_081CD1BA:
	lsls r0, r6, #0x10
	asrs r0, r0, #0xe
	adds r0, r4, r0
	ldrb r6, [r0, #4]
	ldrb r7, [r0, #5]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x16
	movs r3, #0
	bl GetBoxOrPartyMonData
	mov r1, sb
	lsls r5, r1, #2
	adds r4, r5, r1
	ldr r1, _081CD25C
	add r1, r8
	adds r1, r1, r4
	strb r0, [r1]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x2f
	movs r3, #0
	bl GetBoxOrPartyMonData
	ldr r1, _081CD260
	add r1, r8
	adds r1, r1, r4
	strb r0, [r1]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x21
	movs r3, #0
	bl GetBoxOrPartyMonData
	ldr r1, _081CD264
	add r1, r8
	adds r1, r1, r4
	strb r0, [r1]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x18
	movs r3, #0
	bl GetBoxOrPartyMonData
	ldr r1, _081CD268
	add r1, r8
	adds r1, r1, r4
	strb r0, [r1]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x17
	movs r3, #0
	bl GetBoxOrPartyMonData
	ldr r1, _081CD26C
	add r1, r8
	adds r1, r1, r4
	strb r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #7
	add r0, r8
	mov r2, sb
	adds r4, r0, r2
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x30
	movs r3, #0
	bl GetBoxOrPartyMonData
	cmp r0, #0xff
	beq _081CD270
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0x30
	movs r3, #0
	bl GetBoxOrPartyMonData
	movs r1, #0x1d
	bl __udivsi3
	b _081CD272
	.align 2, 0
_081CD25C: .4byte 0x00006428
_081CD260: .4byte 0x00006429
_081CD264: .4byte 0x0000642A
_081CD268: .4byte 0x0000642B
_081CD26C: .4byte 0x0000642C
_081CD270:
	movs r0, #9
_081CD272:
	strb r0, [r4]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #8
	movs r3, #0
	bl GetBoxOrPartyMonData
	ldr r1, _081CD2A0
	add r1, r8
	add r1, sb
	strb r0, [r1]
	mov r0, sb
	adds r1, r5, r0
	ldr r2, _081CD2A4
	adds r0, r1, r2
	add r0, r8
	lsls r1, r1, #2
	adds r2, #0x14
	adds r1, r1, r2
	add r1, r8
	bl sub_081D1D70
	b _081CD2E0
	.align 2, 0
_081CD2A0: .4byte 0x00006783
_081CD2A4: .4byte 0x00006428
_081CD2A8:
	movs r2, #0
	mov r0, sb
	lsls r5, r0, #2
	add r5, sb
	ldr r4, _081CD2EC
	add r4, r8
	lsls r3, r5, #2
	mov sb, r2
	ldr r7, _081CD2F0
	movs r6, #0x9b
_081CD2BC:
	adds r0, r2, r5
	adds r0, r4, r0
	mov r1, sb
	strb r1, [r0]
	lsls r0, r2, #2
	adds r0, r0, r3
	add r0, r8
	adds r1, r0, r7
	strh r6, [r1]
	ldr r1, _081CD2F4
	adds r0, r0, r1
	movs r1, #0x5b
	strh r1, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #4
	bls _081CD2BC
_081CD2E0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CD2EC: .4byte 0x00006428
_081CD2F0: .4byte 0x0000643C
_081CD2F4: .4byte 0x0000643E
	thumb_func_end sub_081CD17C

	thumb_func_start sub_081CD2F8
sub_081CD2F8: @ 0x081CD2F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	movs r0, #0xb
	bl GetSubstructPtr
	adds r7, r0, #0
	movs r0, #0x12
	bl GetSubstructPtr
	adds r4, r0, #0
	lsls r0, r6, #0x10
	asrs r5, r0, #0x10
	bl sub_081CD4BC
	cmp r0, #0
	beq _081CD32C
	ldrh r0, [r4]
	b _081CD330
_081CD32C:
	ldrh r0, [r4]
	subs r0, #1
_081CD330:
	cmp r5, r0
	beq _081CD39E
	lsls r0, r6, #0x10
	asrs r0, r0, #0xe
	adds r0, r4, r0
	ldrb r5, [r0, #4]
	ldrb r6, [r0, #5]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x41
	movs r3, #0
	bl GetBoxOrPartyMonData
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #1
	movs r3, #0
	bl GetBoxOrPartyMonData
	mov r8, r0
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0
	bl GetBoxOrPartyMonData
	adds r5, r0, #0
	lsls r0, r4, #3
	ldr r1, _081CD3AC
	adds r0, r0, r1
	mov r2, sb
	lsls r1, r2, #0xd
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r1, r1, r2
	adds r1, r7, r1
	movs r2, #1
	str r2, [sp]
	adds r2, r4, #0
	adds r3, r5, #0
	bl LoadSpecialPokePic
	adds r0, r4, #0
	mov r1, r8
	adds r2, r5, #0
	bl GetMonSpritePalFromSpeciesAndPersonality
	mov r2, sb
	lsls r1, r2, #7
	adds r1, r7, r1
	bl LZ77UnCompWram
_081CD39E:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081CD3AC: .4byte 0x082DDA1C
	thumb_func_end sub_081CD2F8

	thumb_func_start sub_081CD3B0
sub_081CD3B0: @ 0x081CD3B0
	push {lr}
	movs r0, #0x12
	bl GetSubstructPtr
	ldrh r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CD3B0

	thumb_func_start sub_081CD3C0
sub_081CD3C0: @ 0x081CD3C0
	push {lr}
	movs r0, #0x12
	bl GetSubstructPtr
	ldrh r0, [r0, #2]
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CD3C0

	thumb_func_start sub_081CD3D0
sub_081CD3D0: @ 0x081CD3D0
	push {lr}
	movs r0, #0xb
	bl GetSubstructPtr
	ldr r1, _081CD3E0
	adds r0, r0, r1
	pop {r1}
	bx r1
	.align 2, 0
_081CD3E0: .4byte 0x00006428
	thumb_func_end sub_081CD3D0

	thumb_func_start sub_081CD3E4
sub_081CD3E4: @ 0x081CD3E4
	push {lr}
	movs r0, #0xb
	bl GetSubstructPtr
	ldr r1, _081CD3F8
	adds r0, r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_081CD3F8: .4byte 0x00006786
	thumb_func_end sub_081CD3E4

	thumb_func_start sub_081CD3FC
sub_081CD3FC: @ 0x081CD3FC
	push {lr}
	movs r0, #0xb
	bl GetSubstructPtr
	ldr r1, _081CD410
	adds r0, r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_081CD410: .4byte 0x00006302
	thumb_func_end sub_081CD3FC

	thumb_func_start sub_081CD414
sub_081CD414: @ 0x081CD414
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0xb
	bl GetSubstructPtr
	lsls r4, r4, #0xd
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r4, r4, r1
	adds r0, r0, r4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CD414

	thumb_func_start sub_081CD434
sub_081CD434: @ 0x081CD434
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0xb
	bl GetSubstructPtr
	lsls r4, r4, #7
	adds r0, r0, r4
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_081CD434

	thumb_func_start sub_081CD44C
sub_081CD44C: @ 0x081CD44C
	push {lr}
	movs r0, #0xb
	bl GetSubstructPtr
	ldr r1, _081CD460
	adds r0, r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_081CD460: .4byte 0x00006789
	thumb_func_end sub_081CD44C

	thumb_func_start sub_081CD464
sub_081CD464: @ 0x081CD464
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0xb
	bl GetSubstructPtr
	lsls r4, r4, #6
	ldr r1, _081CD480
	adds r4, r4, r1
	adds r0, r0, r4
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081CD480: .4byte 0x00006368
	thumb_func_end sub_081CD464

	thumb_func_start sub_081CD484
sub_081CD484: @ 0x081CD484
	push {r4, lr}
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r0, #0xb
	bl GetSubstructPtr
	lsls r1, r4, #1
	adds r1, r1, r4
	lsls r1, r1, #3
	ldr r2, _081CD4A4
	adds r1, r1, r2
	adds r0, r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081CD4A4: .4byte 0x00006320
	thumb_func_end sub_081CD484

	thumb_func_start sub_081CD4A8
sub_081CD4A8: @ 0x081CD4A8
	push {lr}
	movs r0, #0x12
	bl GetSubstructPtr
	ldrh r1, [r0, #2]
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r0, [r0, #6]
	pop {r1}
	bx r1
	thumb_func_end sub_081CD4A8

	thumb_func_start sub_081CD4BC
sub_081CD4BC: @ 0x081CD4BC
	push {lr}
	movs r0, #0xb
	bl GetSubstructPtr
	movs r1, #0xc6
	lsls r1, r1, #7
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081CD4D4
	movs r0, #0
	b _081CD4D6
_081CD4D4:
	movs r0, #1
_081CD4D6:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CD4BC

	thumb_func_start sub_081CD4DC
sub_081CD4DC: @ 0x081CD4DC
	push {lr}
	movs r0, #0xb
	bl GetSubstructPtr
	adds r2, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #7
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _081CD4F6
	movs r0, #0
	b _081CD506
_081CD4F6:
	ldr r3, _081CD50C
	adds r0, r2, r3
	movs r1, #0
	ldrsb r1, [r0, r1]
	subs r3, #3
	adds r0, r2, r3
	adds r0, r0, r1
	ldrb r0, [r0]
_081CD506:
	pop {r1}
	bx r1
	.align 2, 0
_081CD50C: .4byte 0x00006786
	thumb_func_end sub_081CD4DC

	thumb_func_start sub_081CD510
sub_081CD510: @ 0x081CD510
	push {lr}
	movs r0, #0xb
	bl GetSubstructPtr
	ldr r2, _081CD530
	adds r1, r0, r2
	ldrb r1, [r1]
	lsls r1, r1, #0x18
	asrs r1, r1, #0x18
	subs r2, #6
	adds r0, r0, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	pop {r1}
	bx r1
	.align 2, 0
_081CD530: .4byte 0x00006786
	thumb_func_end sub_081CD510

	thumb_func_start sub_081CD534
sub_081CD534: @ 0x081CD534
	push {r4, lr}
	ldr r1, _081CD56C
	movs r0, #0xc
	bl AllocSubstruct
	adds r4, r0, #0
	cmp r4, #0
	beq _081CD584
	ldr r0, _081CD570
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r0, _081CD574
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r4]
	ldr r0, _081CD578
	adds r1, r4, r0
	ldr r0, _081CD57C
	str r0, [r1]
	ldr r0, _081CD580
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081CD586
	.align 2, 0
_081CD56C: .4byte 0x000038AC
_081CD570: .4byte 0x00001816
_081CD574: .4byte 0x081CD5F5
_081CD578: .4byte 0x00001810
_081CD57C: .4byte 0x081CD5E1
_081CD580: .4byte 0x00002908
_081CD584:
	movs r0, #0
_081CD586:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_081CD534

	thumb_func_start sub_081CD58C
sub_081CD58C: @ 0x081CD58C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xc
	bl GetSubstructPtr
	adds r5, r0, #0
	ldr r0, _081CD5B8
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r0, [r4]
	movs r1, #1
	bl CreateLoopedTask
	str r0, [r5]
	ldr r0, _081CD5BC
	adds r5, r5, r0
	ldr r0, _081CD5C0
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081CD5B8: .4byte 0x085F5990
_081CD5BC: .4byte 0x00001810
_081CD5C0: .4byte 0x081CD5E1
	thumb_func_end sub_081CD58C

	thumb_func_start sub_081CD5C4
sub_081CD5C4: @ 0x081CD5C4
	push {lr}
	movs r0, #0xc
	bl GetSubstructPtr
	ldr r1, _081CD5DC
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	thumb_func_end sub_081CD5C4

	thumb_func_start sub_081CD5D8
sub_081CD5D8: @ 0x081CD5D8
	bx r1
	.align 2, 0
_081CD5DC: .4byte 0x00001810
	thumb_func_end sub_081CD5D8

	thumb_func_start sub_081CD5E0
sub_081CD5E0: @ 0x081CD5E0
	push {lr}
	movs r0, #0xc
	bl GetSubstructPtr
	ldr r0, [r0]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CD5E0

	thumb_func_start sub_081CD5F4
sub_081CD5F4: @ 0x081CD5F4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r0, #0xc
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #0x14
	bls _081CD608
	b _081CDA24
_081CD608:
	lsls r0, r4, #2
	ldr r1, _081CD614
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081CD614: .4byte 0x081CD618
_081CD618: @ jump table
	.4byte _081CD66C @ case 0
	.4byte _081CD678 @ case 1
	.4byte _081CD6F4 @ case 2
	.4byte _081CD718 @ case 3
	.4byte _081CD790 @ case 4
	.4byte _081CD7D4 @ case 5
	.4byte _081CD810 @ case 6
	.4byte _081CD878 @ case 7
	.4byte _081CD880 @ case 8
	.4byte _081CD886 @ case 9
	.4byte _081CD896 @ case 10
	.4byte _081CD8A6 @ case 11
	.4byte _081CD8B6 @ case 12
	.4byte _081CD8CC @ case 13
	.4byte _081CD928 @ case 14
	.4byte _081CD94C @ case 15
	.4byte _081CD978 @ case 16
	.4byte _081CD99C @ case 17
	.4byte _081CD9AA @ case 18
	.4byte _081CD9BA @ case 19
	.4byte _081CD9C2 @ case 20
_081CD66C:
	bl sub_081CCB04
	cmp r0, #1
	beq _081CD676
	b _081CDA20
_081CD676:
	b _081CD710
_081CD678:
	ldr r0, _081CD6E0
	movs r1, #3
	bl InitBgTemplates
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
	ldr r1, _081CD6E4
	movs r0, #0
	bl SetGpuReg
	ldr r1, _081CD6E8
	movs r0, #0x50
	bl SetGpuReg
	ldr r1, _081CD6EC
	movs r0, #0x52
	bl SetGpuReg
	ldr r1, _081CD6F0
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	b _081CD708
	.align 2, 0
_081CD6E0: .4byte 0x085F5964
_081CD6E4: .4byte 0x00007940
_081CD6E8: .4byte 0x00000844
_081CD6EC: .4byte 0x0000040B
_081CD6F0: .4byte 0x085F4E6C
_081CD6F4:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _081CD702
	b _081CDA20
_081CD702:
	ldr r1, _081CD714
	str r0, [sp]
	movs r0, #2
_081CD708:
	movs r2, #0
	movs r3, #0
	bl DecompressAndCopyTileDataToVram
_081CD710:
	movs r0, #0
	b _081CDA26
	.align 2, 0
_081CD714: .4byte 0x085F57EC
_081CD718:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CD724
	b _081CDA20
_081CD724:
	ldr r0, _081CD778
	adds r4, r5, #4
	adds r1, r4, #0
	bl LZ77UnCompVram
	movs r0, #3
	adds r1, r4, #0
	bl SetBgTilemapBuffer
	bl sub_081CD4BC
	cmp r0, #1
	bne _081CD752
	ldr r1, _081CD77C
	movs r0, #9
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	movs r0, #3
	movs r2, #0
	movs r3, #5
	bl CopyToBgTilemapBufferRect
_081CD752:
	movs r0, #3
	bl CopyBgTilemapBufferToVram
	ldr r0, _081CD780
	movs r1, #0x10
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	ldr r0, _081CD784
	movs r1, #0xf0
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	ldr r0, _081CD788
	adds r1, r5, r0
	ldr r0, _081CD78C
	strh r0, [r1]
	b _081CD710
	.align 2, 0
_081CD778: .4byte 0x085F5600
_081CD77C: .4byte 0x085F58FC
_081CD780: .4byte 0x085F4E0C
_081CD784: .4byte 0x085F4E4C
_081CD788: .4byte 0x00001814
_081CD78C: .4byte 0x0000FFB0
_081CD790:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CD79C
	b _081CDA20
_081CD79C:
	ldr r0, _081CD7C8
	ldr r1, _081CD7CC
	adds r4, r5, r1
	adds r1, r4, #0
	bl LZ77UnCompVram
	movs r0, #2
	adds r1, r4, #0
	bl SetBgTilemapBuffer
	movs r0, #2
	bl CopyBgTilemapBufferToVram
	ldr r0, _081CD7D0
	movs r1, #0x30
	movs r2, #0x20
	bl CopyPaletteIntoBufferUnfaded
	movs r0, #2
	bl sub_081D1824
	b _081CD710
	.align 2, 0
_081CD7C8: .4byte 0x085F5800
_081CD7CC: .4byte 0x00001004
_081CD7D0: .4byte 0x085F4E2C
_081CD7D4:
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #1
	bl BgDmaFill
	movs r0, #1
	movs r1, #0x11
	movs r2, #1
	movs r3, #1
	bl BgDmaFill
	movs r0, #0
	str r0, [sp, #8]
	ldr r2, _081CD808
	adds r4, r5, r2
	ldr r2, _081CD80C
	add r0, sp, #8
	adds r1, r4, #0
	bl CpuSet
	movs r0, #1
	adds r1, r4, #0
	bl SetBgTilemapBuffer
	b _081CD710
	.align 2, 0
_081CD808: .4byte 0x00000804
_081CD80C: .4byte 0x05000200
_081CD810:
	bl FreeTempTileDataBuffersIfPossible
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CD81C
	b _081CDA20
_081CD81C:
	ldr r0, _081CD85C
	bl AddWindow
	movs r2, #0xc1
	lsls r2, r2, #5
	adds r1, r5, r2
	strb r0, [r1]
	bl sub_081CD4BC
	cmp r0, #1
	bne _081CD856
	ldr r0, _081CD860
	bl AddWindow
	ldr r2, _081CD864
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _081CD868
	bl AddWindow
	ldr r2, _081CD86C
	adds r1, r5, r2
	strb r0, [r1]
	ldr r0, _081CD870
	bl AddWindow
	ldr r2, _081CD874
	adds r1, r5, r2
	strb r0, [r1]
_081CD856:
	bl DeactivateAllTextPrinters
	b _081CD710
	.align 2, 0
_081CD85C: .4byte 0x085F5970
_081CD860: .4byte 0x085F5978
_081CD864: .4byte 0x00001821
_081CD868: .4byte 0x085F5980
_081CD86C: .4byte 0x00001822
_081CD870: .4byte 0x085F5988
_081CD874: .4byte 0x00001823
_081CD878:
	movs r0, #0
	bl sub_081CE464
	b _081CD710
_081CD880:
	bl sub_081CE118
	b _081CD710
_081CD886:
	bl sub_081CD4BC
	cmp r0, #1
	beq _081CD890
	b _081CD710
_081CD890:
	bl sub_081CE068
	b _081CD710
_081CD896:
	bl sub_081CD3E4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #0
	b _081CD8C4
_081CD8A6:
	bl sub_081CD3E4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #1
	b _081CD8C4
_081CD8B6:
	bl sub_081CD3E4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #2
_081CD8C4:
	movs r2, #1
	bl sub_081CDEB4
	b _081CD710
_081CD8CC:
	bl sub_081CD3E4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #3
	movs r2, #1
	bl sub_081CDEB4
	cmp r0, #1
	beq _081CD8E6
	b _081CDA20
_081CD8E6:
	movs r1, #0xc1
	lsls r1, r1, #5
	adds r0, r5, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	bl sub_081CD4BC
	cmp r0, #1
	beq _081CD8FC
	b _081CD710
_081CD8FC:
	ldr r2, _081CD91C
	adds r0, r5, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r1, _081CD920
	adds r0, r5, r1
	ldrb r0, [r0]
	bl PutWindowTilemap
	ldr r2, _081CD924
	adds r0, r5, r2
	ldrb r0, [r0]
	bl PutWindowTilemap
	b _081CD710
	.align 2, 0
_081CD91C: .4byte 0x00001821
_081CD920: .4byte 0x00001822
_081CD924: .4byte 0x00001823
_081CD928:
	movs r0, #1
	bl ShowBg
	movs r0, #2
	bl HideBg
	movs r0, #3
	bl ShowBg
	bl sub_081CD4BC
	cmp r0, #1
	beq _081CD944
	b _081CD710
_081CD944:
	movs r0, #4
	bl PrintHelpBarText
	b _081CD710
_081CD94C:
	movs r0, #1
	bl PokenavFadeScreen
	bl sub_081CD4BC
	cmp r0, #0
	beq _081CD95C
	b _081CD710
_081CD95C:
	movs r0, #6
	bl LoadLeftHeaderGfxForIndex
	movs r0, #1
	movs r1, #1
	movs r2, #0
	bl ShowLeftHeaderGfx
	movs r0, #6
	movs r1, #1
	movs r2, #0
	bl ShowLeftHeaderGfx
	b _081CD710
_081CD978:
	bl IsPaletteFadeActive
	cmp r0, #0
	bne _081CDA20
	bl sub_081CD4BC
	cmp r0, #0
	bne _081CD990
	bl AreLeftHeaderSpritesMoving
	cmp r0, #0
	bne _081CDA20
_081CD990:
	ldr r0, _081CD998
	bl SetVBlankCallback_
	b _081CD710
	.align 2, 0
_081CD998: .4byte 0x081CE579
_081CD99C:
	bl sub_081CE5C4
	bl sub_081CD3D0
	bl sub_081D16F4
	b _081CD710
_081CD9AA:
	bl sub_081CD3D0
	bl sub_081D1704
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDA20
	b _081CD710
_081CD9BA:
	movs r0, #1
	bl sub_081CE5A8
	b _081CD710
_081CD9C2:
	bl sub_081CD3D0
	ldr r2, _081CDA14
	adds r1, r5, r2
	bl sub_081D27A8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDA20
	ldr r0, _081CDA18
	adds r6, r5, r0
	adds r0, r6, #0
	bl sub_081D2A94
	bl sub_081CD4BC
	cmp r0, #1
	beq _081CD9F8
	bl sub_081CD3C0
	adds r4, r0, #0
	bl sub_081CD3B0
	lsls r4, r4, #0x10
	lsls r0, r0, #0x10
	cmp r4, r0
	beq _081CDA24
_081CD9F8:
	ldr r1, _081CDA1C
	adds r0, r5, r1
	ldrb r4, [r0]
	bl sub_081CD510
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r6, #0
	adds r1, r4, #0
	bl sub_081D2AB0
	b _081CDA24
	.align 2, 0
_081CDA14: .4byte 0x00001814
_081CDA18: .4byte 0x000028E0
_081CDA1C: .4byte 0x00001816
_081CDA20:
	movs r0, #2
	b _081CDA26
_081CDA24:
	movs r0, #4
_081CDA26:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CD5F4

	thumb_func_start sub_081CDA30
sub_081CDA30: @ 0x081CDA30
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xc
	bl GetSubstructPtr
	adds r5, r0, #0
	cmp r4, #1
	beq _081CDA68
	cmp r4, #1
	bgt _081CDA4A
	cmp r4, #0
	beq _081CDA54
	b _081CDAD4
_081CDA4A:
	cmp r4, #2
	beq _081CDA88
	cmp r4, #3
	beq _081CDA9E
	b _081CDAD4
_081CDA54:
	bl sub_081CE5FC
	ldr r1, _081CDA64
	adds r0, r5, r1
	bl sub_081D2B50
	movs r0, #1
	b _081CDAD6
	.align 2, 0
_081CDA64: .4byte 0x000028E0
_081CDA68:
	bl sub_081CD3D0
	ldr r2, _081CDA84
	adds r1, r5, r2
	bl sub_081D27D4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDAAE
	movs r0, #0
	bl sub_081CE5A8
	movs r0, #1
	b _081CDAD6
	.align 2, 0
_081CDA84: .4byte 0x00001814
_081CDA88:
	movs r0, #0
	bl PokenavFadeScreen
	bl sub_081CD4BC
	cmp r0, #0
	bne _081CDA9A
	bl SlideMenuHeaderDown
_081CDA9A:
	movs r0, #0
	b _081CDAD6
_081CDA9E:
	bl IsPaletteFadeActive
	cmp r0, #0
	bne _081CDAAE
	bl MainMenuLoopedTaskIsBusy
	cmp r0, #0
	beq _081CDAB2
_081CDAAE:
	movs r0, #2
	b _081CDAD6
_081CDAB2:
	ldr r1, _081CDAD0
	adds r0, r5, r1
	bl nullsub_79
	movs r0, #1
	bl HideBg
	movs r0, #2
	bl HideBg
	movs r0, #3
	bl HideBg
	movs r0, #1
	b _081CDAD6
	.align 2, 0
_081CDAD0: .4byte 0x000028E0
_081CDAD4:
	movs r0, #4
_081CDAD6:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_081CDA30

	thumb_func_start sub_081CDADC
sub_081CDADC: @ 0x081CDADC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0xc
	bl GetSubstructPtr
	adds r6, r0, #0
	bl sub_081CD3D0
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
	bl sub_081CCC88
_081CDB36:
	movs r0, #1
	b _081CDC32
_081CDB3A:
	movs r0, #2
	bl sub_081CCC88
	ldr r1, _081CDB4C
	adds r0, r6, r1
	bl sub_081D2B50
	b _081CDB36
	.align 2, 0
_081CDB4C: .4byte 0x000028E0
_081CDB50:
	adds r0, r2, #0
	bl sub_081D16BC
	b _081CDB36
_081CDB58:
	ldr r1, _081CDB74
	adds r0, r6, r1
	bl sub_081D2780
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDC2C
	bl sub_081CD3E4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_081CE464
	b _081CDB36
	.align 2, 0
_081CDB74: .4byte 0x00001814
_081CDB78:
	bl sub_081CD3E4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #0
	b _081CDBA6
_081CDB88:
	bl sub_081CD3E4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #1
	b _081CDBA6
_081CDB98:
	bl sub_081CD3E4
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
	bl sub_081CD3E4
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
	bl sub_081CD3D0
	adds r2, r0, #0
	ldr r0, _081CDC20
	adds r1, r6, r0
	adds r0, r2, #0
	bl sub_081D27A8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDC2C
	ldr r1, _081CDC24
	adds r0, r6, r1
	bl sub_081D2A94
	bl sub_081CD4BC
	cmp r0, #1
	beq _081CDC00
	bl sub_081CD3C0
	adds r4, r0, #0
	bl sub_081CD3B0
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
	bl sub_081CD510
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl sub_081D2AB0
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
	thumb_func_end sub_081CDADC

	thumb_func_start sub_081CDC38
sub_081CDC38: @ 0x081CDC38
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
	bl sub_081CCC88
	movs r0, #1
	b _081CDD3E
_081CDC8E:
	bl sub_081CD3E4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl sub_081CE464
	movs r0, #1
	b _081CDD3E
_081CDC9E:
	bl sub_081CD3E4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #0
	b _081CDCCC
_081CDCAE:
	bl sub_081CD3E4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #1
	b _081CDCCC
_081CDCBE:
	bl sub_081CD3E4
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
	bl sub_081CD3E4
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
	bl sub_081CD3D0
	ldr r2, _081CDD2C
	adds r1, r5, r2
	bl sub_081D27A8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081CDD38
	ldr r0, _081CDD30
	adds r4, r5, r0
	adds r0, r4, #0
	bl sub_081D2A94
	ldr r1, _081CDD34
	adds r0, r5, r1
	ldrb r5, [r0]
	bl sub_081CD510
	adds r2, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_081D2AB0
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
	thumb_func_end sub_081CDC38

	thumb_func_start sub_081CDD44
sub_081CDD44: @ 0x081CDD44
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
	bl sub_081CCC88
_081CDD8E:
	movs r0, #1
	b _081CDE14
_081CDD92:
	movs r0, #2
	bl sub_081CCC88
	ldr r1, _081CDDA4
	adds r0, r5, r1
	bl sub_081D2B50
	b _081CDD8E
	.align 2, 0
_081CDDA4: .4byte 0x000028E0
_081CDDA8:
	bl sub_081CD3D0
	ldr r2, _081CDDBC
	adds r1, r5, r2
	bl sub_081D27D4
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081CDD8E
	b _081CDE0E
	.align 2, 0
_081CDDBC: .4byte 0x00001814
_081CDDC0:
	bl sub_081CD3E4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #0
	b _081CDDEE
_081CDDD0:
	bl sub_081CD3E4
	adds r1, r0, #0
	lsls r1, r1, #0x18
	asrs r1, r1, #8
	lsrs r1, r1, #0x10
	movs r0, #1
	b _081CDDEE
_081CDDE0:
	bl sub_081CD3E4
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
	bl sub_081CD3E4
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
	thumb_func_end sub_081CDD44

	thumb_func_start sub_081CDE1C
sub_081CDE1C: @ 0x081CDE1C
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
	bl sub_081CD4DC
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
	thumb_func_end sub_081CDE1C

	thumb_func_start sub_081CDE60
sub_081CDE60: @ 0x081CDE60
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
	thumb_func_end sub_081CDE60

	thumb_func_start sub_081CDE98
sub_081CDE98: @ 0x081CDE98
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
	thumb_func_end sub_081CDE98

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
	bl sub_081CD4BC
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
	bl sub_081CD3C0
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_081CD3B0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r0, #1
	cmp r4, r0
	bne _081CDF32
	bl sub_081CD4BC
	cmp r0, #1
	beq _081CDF32
	b _081CE05C
_081CDF32:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl sub_081CD464
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
	bl sub_081CD4BC
	cmp r0, #1
	beq _081CDF5C
	b _081CE05C
_081CDF5C:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	bl sub_081CD484
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
	bl sub_081CD4A8
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl sub_081CDE98
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
	bl sub_081CD4BC
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

	thumb_func_start sub_081CE068
sub_081CE068: @ 0x081CE068
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
	thumb_func_end sub_081CE068

	thumb_func_start sub_081CE098
sub_081CE098: @ 0x081CE098
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x2e
	ldrsh r4, [r5, r0]
	bl sub_081CD3C0
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
	thumb_func_end sub_081CE098

	thumb_func_start sub_081CE0C4
sub_081CE0C4: @ 0x081CE0C4
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_081CD3C0
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_081CD3B0
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
	thumb_func_end sub_081CE0C4

	thumb_func_start sub_081CE0FC
sub_081CE0FC: @ 0x081CE0FC
	push {r4, lr}
	adds r4, r0, #0
	bl sub_081CD4DC
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl StartSpriteAnim
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081CE0FC

	thumb_func_start sub_081CE118
sub_081CE118: @ 0x081CE118
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
	bl sub_081D284C
	bl sub_081CD4BC
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
	bl sub_081CD3B0
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
	bl sub_081D28E0
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
	thumb_func_end sub_081CE118

	thumb_func_start sub_081CE328
sub_081CE328: @ 0x081CE328
	push {r4, r5, lr}
	adds r5, r0, #0
	bl sub_081CD4BC
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
	thumb_func_end sub_081CE328

	thumb_func_start sub_081CE3D4
sub_081CE3D4: @ 0x081CE3D4
	push {r4, lr}
	movs r0, #0xc
	bl GetSubstructPtr
	adds r4, r0, #0
	movs r1, #0xc1
	lsls r1, r1, #5
	adds r0, r4, r1
	ldrb r0, [r0]
	bl RemoveWindow
	bl sub_081CD4BC
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
	bl sub_081CE328
	bl sub_081CE59C
	movs r0, #0xc
	bl FreePokenavSubstruct
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081CE3D4

	thumb_func_start sub_081CE444
sub_081CE444: @ 0x081CE444
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
	thumb_func_end sub_081CE444

	thumb_func_start sub_081CE464
sub_081CE464: @ 0x081CE464
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
	bl sub_081D2800
	adds r0, r6, #0
	bl sub_081CD414
	str r0, [sp, #0x18]
	adds r0, r6, #0
	bl sub_081CD434
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
	bl sub_081CD414
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
	bl sub_081CD434
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
	thumb_func_end sub_081CE464

	thumb_func_start sub_081CE578
sub_081CE578: @ 0x081CE578
	push {r4, lr}
	bl sub_081CD3D0
	adds r4, r0, #0
	bl LoadOam
	bl ProcessSpriteCopyRequests
	bl TransferPlttBuffer
	adds r0, r4, #0
	bl sub_081D1750
	bl ScanlineEffect_InitHBlankDmaTransfer
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_081CE578

	thumb_func_start sub_081CE59C
sub_081CE59C: @ 0x081CE59C
	push {lr}
	bl SetPokenavVBlankCallback
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081CE59C

	thumb_func_start sub_081CE5A8
sub_081CE5A8: @ 0x081CE5A8
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
	thumb_func_end sub_081CE5A8

	thumb_func_start sub_081CE5C4
sub_081CE5C4: @ 0x081CE5C4
	push {r4, lr}
	bl sub_081CD3D0
	adds r4, r0, #0
	bl sub_081CD3E4
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
	bl sub_081D15CC
	adds r0, r4, #0
	bl sub_081D16BC
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081CE5F8: .4byte 0x030012B0
	thumb_func_end sub_081CE5C4

	thumb_func_start sub_081CE5FC
sub_081CE5FC: @ 0x081CE5FC
	push {r4, r5, lr}
	bl sub_081CD3D0
	adds r5, r0, #0
	bl sub_081CD4BC
	cmp r0, #0
	bne _081CE624
	bl sub_081CD3C0
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl sub_081CD3B0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	subs r0, #1
	cmp r4, r0
	beq _081CE640
_081CE624:
	bl sub_081CD3E4
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
	bl sub_081D15CC
_081CE640:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_081CE5FC

	thumb_func_start sub_081CE648
sub_081CE648: @ 0x081CE648
	push {r4, lr}
	movs r0, #0xc
	bl GetSubstructPtr
	adds r4, r0, #0
	bl sub_081CD4BC
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
	thumb_func_end sub_081CE648

	thumb_func_start sub_081CE670
sub_081CE670: @ 0x081CE670
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
	thumb_func_end sub_081CE670

	thumb_func_start sub_081CE6CC
sub_081CE6CC: @ 0x081CE6CC
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
	thumb_func_end sub_081CE6CC

	thumb_func_start sub_081CE710
sub_081CE710: @ 0x081CE710
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r1, [r0]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CE710

	thumb_func_start sub_081CE724
sub_081CE724: @ 0x081CE724
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
	thumb_func_end sub_081CE724

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

	thumb_func_start sub_081CE764
sub_081CE764: @ 0x081CE764
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
	thumb_func_end sub_081CE764

	thumb_func_start sub_081CE7E4
sub_081CE7E4: @ 0x081CE7E4
	ldr r0, _081CE7E8
	bx lr
	.align 2, 0
_081CE7E8: .4byte 0x000186A3
	thumb_func_end sub_081CE7E4

	thumb_func_start sub_081CE7EC
sub_081CE7EC: @ 0x081CE7EC
	ldr r0, _081CE7F0
	bx lr
	.align 2, 0
_081CE7F0: .4byte 0x000186A9
	thumb_func_end sub_081CE7EC

	thumb_func_start sub_081CE7F4
sub_081CE7F4: @ 0x081CE7F4
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r0, [r0, #0x18]
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CE7F4

	thumb_func_start sub_081CE804
sub_081CE804: @ 0x081CE804
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r0, [r0, #0x20]
	adds r0, #4
	pop {r1}
	bx r1
	thumb_func_end sub_081CE804

	thumb_func_start sub_081CE814
sub_081CE814: @ 0x081CE814
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r0, [r0, #0x20]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_081CE814

	thumb_func_start sub_081CE824
sub_081CE824: @ 0x081CE824
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
	thumb_func_end sub_081CE824

	thumb_func_start sub_081CE840
sub_081CE840: @ 0x081CE840
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	ldr r0, [r0, #0x20]
	ldrh r0, [r0, #2]
	pop {r1}
	bx r1
	thumb_func_end sub_081CE840

	thumb_func_start sub_081CE850
sub_081CE850: @ 0x081CE850
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
	thumb_func_end sub_081CE850

	thumb_func_start sub_081CE868
sub_081CE868: @ 0x081CE868
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
	bl sub_081CE9F8
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
	thumb_func_end sub_081CE868

	thumb_func_start sub_081CE8F8
sub_081CE8F8: @ 0x081CE8F8
	push {lr}
	movs r0, #7
	bl GetSubstructPtr
	movs r1, #0
	str r1, [r0, #0x10]
	str r1, [r0, #0xc]
	movs r0, #1
	pop {r1}
	bx r1
	thumb_func_end sub_081CE8F8

	thumb_func_start sub_081CE90C
sub_081CE90C: @ 0x081CE90C
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
	bl sub_081CE9F8
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
	thumb_func_end sub_081CE90C

	thumb_func_start sub_081CE9AC
sub_081CE9AC: @ 0x081CE9AC
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
	thumb_func_end sub_081CE9AC

	thumb_func_start sub_081CE9F8
sub_081CE9F8: @ 0x081CE9F8
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
	thumb_func_end sub_081CE9F8

	thumb_func_start sub_081CEA64
sub_081CEA64: @ 0x081CEA64
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
	thumb_func_end sub_081CEA64

	thumb_func_start sub_081CEA9C
sub_081CEA9C: @ 0x081CEA9C
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
	thumb_func_end sub_081CEA9C

	thumb_func_start sub_081CEAD4
sub_081CEAD4: @ 0x081CEAD4
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
	thumb_func_end sub_081CEAD4

	thumb_func_start sub_081CEB04
sub_081CEB04: @ 0x081CEB04
	push {lr}
	movs r0, #8
	bl GetSubstructPtr
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	thumb_func_end sub_081CEB04

	thumb_func_start sub_081CEB14
sub_081CEB14: @ 0x081CEB14
	bx r1
	.align 2, 0
	thumb_func_end sub_081CEB14

	thumb_func_start sub_081CEB18
sub_081CEB18: @ 0x081CEB18
	push {lr}
	movs r0, #8
	bl GetSubstructPtr
	ldr r0, [r0, #4]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CEB18

	thumb_func_start sub_081CEB2C
sub_081CEB2C: @ 0x081CEB2C
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
	thumb_func_end sub_081CEB2C

	thumb_func_start sub_081CEB4C
sub_081CEB4C: @ 0x081CEB4C
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
	bl sub_081CE7F4
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
	bl sub_081CEF4C
	b _081CEBCC
	.align 2, 0
_081CEC10: .4byte 0x085F5B7C
_081CEC14:
	bl IsCreatePokenavListTaskActive
	cmp r0, #0
	bne _081CEC9E
	adds r0, r5, #0
	bl sub_081CEEBC
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
	thumb_func_end sub_081CEB4C

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

	thumb_func_start sub_081CEE4C
sub_081CEE4C: @ 0x081CEE4C
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
	thumb_func_end sub_081CEE4C

	thumb_func_start sub_081CEE8C
sub_081CEE8C: @ 0x081CEE8C
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
	thumb_func_end sub_081CEE8C

	thumb_func_start sub_081CEEBC
sub_081CEEBC: @ 0x081CEEBC
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
	thumb_func_end sub_081CEEBC

	thumb_func_start sub_081CEEE8
sub_081CEEE8: @ 0x081CEEE8
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	bl sub_081CE824
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

	thumb_func_start sub_081CEF4C
sub_081CEF4C: @ 0x081CEF4C
	push {r4, lr}
	sub sp, #0x18
	bl sub_081CE804
	str r0, [sp]
	bl sub_081CE814
	mov r1, sp
	movs r4, #0
	strh r0, [r1, #4]
	movs r0, #4
	strb r0, [r1, #8]
	bl sub_081CE840
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
	thumb_func_end sub_081CEF4C

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

	thumb_func_start sub_081CF090
sub_081CF090: @ 0x081CF090
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
	thumb_func_end sub_081CF090

	thumb_func_start sub_081CF0D8
sub_081CF0D8: @ 0x081CF0D8
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
	thumb_func_end sub_081CF0D8

	thumb_func_start sub_081CF108
sub_081CF108: @ 0x081CF108
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r1, [r0]
	bl _call_via_r1
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CF108

	thumb_func_start sub_081CF11C
sub_081CF11C: @ 0x081CF11C
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
	thumb_func_end sub_081CF11C

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

	thumb_func_start sub_081CF15C
sub_081CF15C: @ 0x081CF15C
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
	thumb_func_end sub_081CF15C

	thumb_func_start sub_081CF1DC
sub_081CF1DC: @ 0x081CF1DC
	ldr r0, _081CF1E0
	bx lr
	.align 2, 0
_081CF1E0: .4byte 0x000186A5
	thumb_func_end sub_081CF1DC

	thumb_func_start sub_081CF1E4
sub_081CF1E4: @ 0x081CF1E4
	ldr r0, _081CF1E8
	bx lr
	.align 2, 0
_081CF1E8: .4byte 0x000186AD
	thumb_func_end sub_081CF1E4

	thumb_func_start sub_081CF1EC
sub_081CF1EC: @ 0x081CF1EC
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r0, [r0, #0x14]
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CF1EC

	thumb_func_start sub_081CF1FC
sub_081CF1FC: @ 0x081CF1FC
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r0, [r0, #0x1c]
	adds r0, #4
	pop {r1}
	bx r1
	thumb_func_end sub_081CF1FC

	thumb_func_start sub_081CF20C
sub_081CF20C: @ 0x081CF20C
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r0, [r0, #0x1c]
	ldrh r0, [r0]
	pop {r1}
	bx r1
	thumb_func_end sub_081CF20C

	thumb_func_start sub_081CF21C
sub_081CF21C: @ 0x081CF21C
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
	thumb_func_end sub_081CF21C

	thumb_func_start sub_081CF238
sub_081CF238: @ 0x081CF238
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	ldr r0, [r0, #0x1c]
	ldrh r0, [r0, #2]
	pop {r1}
	bx r1
	thumb_func_end sub_081CF238

	thumb_func_start sub_081CF248
sub_081CF248: @ 0x081CF248
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
	thumb_func_end sub_081CF248

	thumb_func_start sub_081CF260
sub_081CF260: @ 0x081CF260
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
	thumb_func_end sub_081CF260

	thumb_func_start sub_081CF300
sub_081CF300: @ 0x081CF300
	push {lr}
	movs r0, #9
	bl GetSubstructPtr
	movs r1, #0
	str r1, [r0, #0x10]
	str r1, [r0, #0xc]
	movs r0, #1
	pop {r1}
	bx r1
	thumb_func_end sub_081CF300

	thumb_func_start sub_081CF314
sub_081CF314: @ 0x081CF314
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
	thumb_func_end sub_081CF314

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

	thumb_func_start sub_081CF42C
sub_081CF42C: @ 0x081CF42C
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
	thumb_func_end sub_081CF42C

	thumb_func_start sub_081CF4A4
sub_081CF4A4: @ 0x081CF4A4
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
	thumb_func_end sub_081CF4A4

	thumb_func_start sub_081CF4DC
sub_081CF4DC: @ 0x081CF4DC
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
	thumb_func_end sub_081CF4DC

	thumb_func_start sub_081CF514
sub_081CF514: @ 0x081CF514
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
	thumb_func_end sub_081CF514

	thumb_func_start sub_081CF544
sub_081CF544: @ 0x081CF544
	push {lr}
	movs r0, #0xa
	bl GetSubstructPtr
	ldr r0, [r0]
	bl _call_via_r0
	pop {r1}
	thumb_func_end sub_081CF544

	thumb_func_start sub_081CF554
sub_081CF554: @ 0x081CF554
	bx r1
	.align 2, 0
	thumb_func_end sub_081CF554

	thumb_func_start sub_081CF558
sub_081CF558: @ 0x081CF558
	push {lr}
	movs r0, #0xa
	bl GetSubstructPtr
	ldr r0, [r0, #4]
	bl IsLoopedTaskActive
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_081CF558

	thumb_func_start sub_081CF56C
sub_081CF56C: @ 0x081CF56C
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
	thumb_func_end sub_081CF56C

	thumb_func_start sub_081CF58C
sub_081CF58C: @ 0x081CF58C
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
	bl sub_081CF1EC
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
	bl sub_081CF9A4
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
	thumb_func_end sub_081CF58C

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

	thumb_func_start sub_081CF870
sub_081CF870: @ 0x081CF870
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
	thumb_func_end sub_081CF870

	thumb_func_start sub_081CF8B0
sub_081CF8B0: @ 0x081CF8B0
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
	thumb_func_end sub_081CF8B0

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
	bl sub_081CF20C
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

	thumb_func_start sub_081CF9A4
sub_081CF9A4: @ 0x081CF9A4
	push {r4, lr}
	sub sp, #0x18
	bl sub_081CF1FC
	str r0, [sp]
	bl sub_081CF20C
	mov r1, sp
	movs r4, #0
	strh r0, [r1, #4]
	movs r0, #4
	strb r0, [r1, #8]
	bl sub_081CF238
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
	thumb_func_end sub_081CF9A4

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
