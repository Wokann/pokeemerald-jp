.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

















	thumb_func_start sub_08023A40
sub_08023A40: @ 0x08023A40
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	ldrb r0, [r0, #0xc]
	cmp r0, #7
	bls _08023A56
	b _08023DF4
_08023A56:
	lsls r0, r0, #2
	ldr r1, _08023A60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08023A60: .4byte 0x08023A64
_08023A64: @ jump table
	.4byte _08023A84 @ case 0
	.4byte _08023ACA @ case 1
	.4byte _08023ADE @ case 2
	.4byte _08023B52 @ case 3
	.4byte _08023CE2 @ case 4
	.4byte _08023D8E @ case 5
	.4byte _08023DA0 @ case 6
	.4byte _08023DD4 @ case 7
_08023A84:
	mov r4, r8
	adds r4, #0x42
	adds r0, r4, #0
	movs r1, #0
	movs r2, #4
	bl memset
	mov r1, r8
	ldrb r0, [r1, #8]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, r8
	adds r1, #0xae
	mov r3, r8
	ldrh r2, [r3, #0x28]
	ldrh r0, [r1]
	cmp r0, r2
	bls _08023AAC
	strh r2, [r1]
_08023AAC:
	mov r5, r8
	ldrb r0, [r5, #8]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, r8
	adds r1, #0xae
	ldrh r0, [r1]
	strh r0, [r4]
	movs r0, #0
	adds r1, r4, #0
	movs r2, #2
	bl SendBlock
	b _08023DF4
_08023ACA:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08023AD6
	b _08023DFC
_08023AD6:
	movs r0, #0
	mov r6, r8
	strh r0, [r6, #0x10]
	b _08023DF4
_08023ADE:
	bl GetBlockReceivedStatus
	ldr r2, _08023B44
	mov r1, r8
	ldrb r3, [r1, #9]
	subs r1, r3, #2
	adds r1, r1, r2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	beq _08023AF8
	b _08023DFC
_08023AF8:
	movs r2, #0
	mov sb, r2
	mov r4, r8
	adds r4, #0x42
	cmp sb, r3
	bhs _08023B2C
	ldr r2, _08023B48
_08023B06:
	mov r3, sb
	lsls r1, r3, #3
	subs r1, r1, r3
	lsls r1, r1, #2
	add r1, r8
	lsls r0, r3, #8
	adds r0, r0, r2
	ldrh r0, [r0]
	adds r1, #0xae
	strh r0, [r1]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	mov r5, r8
	ldrb r5, [r5, #9]
	cmp sb, r5
	blo _08023B06
_08023B2C:
	movs r0, #0
	mov r6, r8
	strh r0, [r6, #0x10]
	strh r0, [r4]
	bl ResetBlockReceivedFlags
	ldrb r0, [r6, #8]
	cmp r0, #0
	bne _08023B4C
	movs r0, #3
	strb r0, [r6, #0xc]
	b _08023DFC
	.align 2, 0
_08023B44: .4byte 0x082C7CD4
_08023B48: .4byte 0x0202207C
_08023B4C:
	movs r0, #6
	mov r1, r8
	b _08023DFA
_08023B52:
	mov r0, r8
	adds r0, #0x68
	movs r1, #0
	movs r2, #0x30
	bl memset
	mov r2, r8
	ldrh r1, [r2, #0x28]
	mov r0, r8
	adds r0, #0x6c
	strh r1, [r0]
	movs r3, #0x18
	ldrsh r4, [r2, r3]
	ldrh r0, [r2, #0x28]
	movs r1, #0x3c
	bl __udivsi3
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl __divsi3
	mov r1, r8
	adds r1, #0x6e
	strh r0, [r1]
	mov r5, r8
	movs r6, #0x30
	ldrsh r0, [r5, r6]
	lsls r0, r0, #8
	movs r4, #0xc8
	lsls r4, r4, #6
	adds r1, r4, #0
	bl MathUtil_Mul32
	adds r2, r0, #0
	movs r0, #0x32
	ldrsh r1, [r5, r0]
	lsls r1, r1, #8
	adds r0, r2, #0
	bl MathUtil_Div32
	adds r2, r0, r4
	asrs r2, r2, #8
	movs r1, #0x7f
	adds r0, r2, #0
	ands r0, r1
	mov r1, r8
	adds r1, #0x70
	strh r0, [r1]
	lsls r2, r2, #8
	movs r1, #0xc8
	lsls r1, r1, #7
	adds r0, r2, #0
	bl MathUtil_Div32
	adds r2, r0, #0
	ldrb r1, [r5, #9]
	ldr r0, [r5, #0x1c]
	muls r0, r1, r0
	lsls r4, r0, #8
	adds r0, r4, #0
	adds r1, r2, #0
	bl MathUtil_Mul32
	adds r4, r0, #0
	asrs r0, r4, #8
	str r0, [r5, #0x68]
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	mov r1, r8
	adds r1, #0x8f
	strb r0, [r1]
	movs r2, #0
	mov sb, r2
	adds r7, r1, #0
	ldrb r3, [r5, #9]
	cmp sb, r3
	blo _08023BFC
	b _08023DF4
_08023BFC:
	mov r0, r8
	adds r0, #0x88
	add r0, sb
	mov r5, sb
	strb r5, [r0]
	mov r0, r8
	adds r0, #0x90
	add r0, sb
	strb r5, [r0]
	mov r6, sb
	lsls r2, r6, #1
	mov r1, r8
	adds r1, #0x74
	adds r1, r1, r2
	lsls r0, r6, #3
	subs r0, r0, r6
	lsls r0, r0, #2
	mov r5, r8
	adds r3, r5, r0
	adds r5, r3, #0
	adds r5, #0xaa
	ldrh r0, [r5]
	strh r0, [r1]
	mov r1, r8
	adds r1, #0x72
	ldrh r6, [r1]
	adds r0, r0, r6
	strh r0, [r1]
	ldrb r0, [r7]
	adds r6, r2, #0
	cmp r0, #1
	beq _08023C6A
	cmp r0, #1
	bgt _08023C46
	cmp r0, #0
	beq _08023C4C
	b _08023CC4
_08023C46:
	cmp r0, #2
	beq _08023C88
	b _08023CC4
_08023C4C:
	ldrh r0, [r5]
	cmp r0, #0
	beq _08023C8E
	adds r0, r3, #0
	adds r0, #0xa8
	ldrh r2, [r0]
	lsls r2, r2, #8
	adds r0, r2, #0
	movs r1, #0xc8
	lsls r1, r1, #7
	bl MathUtil_Mul32
	adds r2, r0, #0
	ldrh r4, [r5]
	b _08023CBA
_08023C6A:
	ldrh r0, [r5]
	cmp r0, #0
	beq _08023C8E
	adds r0, r3, #0
	adds r0, #0xac
	ldrh r2, [r0]
	lsls r2, r2, #8
	adds r0, r2, #0
	movs r1, #0xc8
	lsls r1, r1, #7
	bl MathUtil_Mul32
	adds r2, r0, #0
	ldrh r4, [r5]
	b _08023CBA
_08023C88:
	ldrh r0, [r5]
	cmp r0, #0
	bne _08023C92
_08023C8E:
	movs r4, #0
	b _08023CC4
_08023C92:
	adds r1, r3, #0
	adds r1, #0xae
	ldrh r0, [r1]
	mov r2, r8
	ldrh r2, [r2, #0x28]
	cmp r0, r2
	blo _08023CA6
	movs r4, #0xc8
	lsls r4, r4, #7
	b _08023CC4
_08023CA6:
	ldrh r2, [r1]
	lsls r2, r2, #8
	adds r0, r2, #0
	movs r1, #0xc8
	lsls r1, r1, #7
	bl MathUtil_Mul32
	adds r2, r0, #0
	mov r3, r8
	ldrh r4, [r3, #0x28]
_08023CBA:
	lsls r4, r4, #8
	adds r1, r4, #0
	bl MathUtil_Div32
	adds r4, r0, #0
_08023CC4:
	asrs r4, r4, #4
	mov r0, r8
	adds r0, #0x7e
	adds r0, r0, r6
	strh r4, [r0]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	mov r5, r8
	ldrb r5, [r5, #9]
	cmp sb, r5
	blo _08023BFC
	b _08023DF4
_08023CE2:
	movs r6, #0
	mov sb, r6
	mov r1, r8
	ldrb r0, [r1, #9]
	subs r0, #1
	adds r1, #0x68
	str r1, [sp, #0xc]
	cmp sb, r0
	bge _08023D82
_08023CF4:
	mov r2, r8
	ldrb r0, [r2, #9]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	mov r3, sb
	adds r3, #1
	str r3, [sp, #8]
	cmp r4, sb
	bls _08023D70
	adds r2, #0x74
	str r2, [sp]
	mov r5, r8
	adds r5, #0x88
	str r5, [sp, #4]
	movs r6, #0x90
	add r6, r8
	mov sl, r6
	movs r0, #0x7e
	add r0, r8
	mov ip, r0
_08023D1E:
	subs r7, r4, #1
	lsls r6, r7, #1
	ldr r1, [sp]
	adds r3, r1, r6
	lsls r5, r4, #1
	adds r1, r1, r5
	ldrh r2, [r3]
	ldrh r0, [r1]
	cmp r2, r0
	bhs _08023D46
	ldrh r0, [r1]
	strh r2, [r1]
	strh r0, [r3]
	ldr r1, [sp, #4]
	adds r2, r1, r4
	ldrb r3, [r2]
	adds r1, r1, r7
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
_08023D46:
	mov r2, ip
	adds r3, r2, r6
	adds r1, r2, r5
	ldrh r2, [r3]
	ldrh r5, [r1]
	cmp r2, r5
	bhs _08023D68
	ldrh r0, [r1]
	strh r2, [r1]
	strh r0, [r3]
	mov r6, sl
	adds r2, r6, r4
	ldrb r3, [r2]
	adds r1, r6, r7
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
_08023D68:
	lsls r0, r7, #0x18
	lsrs r4, r0, #0x18
	cmp r4, sb
	bhi _08023D1E
_08023D70:
	ldr r1, [sp, #8]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	mov r2, r8
	ldrb r0, [r2, #9]
	subs r0, #1
	cmp sb, r0
	blt _08023CF4
_08023D82:
	movs r0, #0
	ldr r1, [sp, #0xc]
	movs r2, #0x30
	bl SendBlock
	b _08023DF4
_08023D8E:
	bl IsLinkTaskFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08023DFC
	movs r0, #0
	mov r3, r8
	strh r0, [r3, #0x10]
	b _08023DF4
_08023DA0:
	bl GetBlockReceivedStatus
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08023DFC
	mov r4, r8
	adds r4, #0x68
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x30
	bl memset
	ldr r1, _08023DD0
	adds r0, r4, #0
	movs r2, #0x30
	bl memcpy
	bl ResetBlockReceivedFlags
	movs r0, #0
	mov r5, r8
	strh r0, [r5, #0x10]
	b _08023DF4
	.align 2, 0
_08023DD0: .4byte 0x0202207C
_08023DD4:
	bl sub_08020B74
	movs r0, #0x12
	movs r1, #1
	movs r2, #0
	bl sub_08022950
	movs r0, #0
	movs r1, #0xb
	mov r6, r8
	strh r1, [r6, #0x12]
	strb r0, [r6, #0xc]
	mov r1, r8
	adds r1, #0x24
	strb r0, [r1]
	b _08023DFC
_08023DF4:
	mov r1, r8
	ldrb r0, [r1, #0xc]
	adds r0, #1
_08023DFA:
	strb r0, [r1, #0xc]
_08023DFC:
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08023A40
