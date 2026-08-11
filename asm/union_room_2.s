.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start InUnionRoom
InUnionRoom: @ 0x08017AC0
	push {lr}
	movs r2, #0
	ldr r0, _08017AD8
	ldr r0, [r0]
	ldrh r1, [r0, #4]
	ldr r0, _08017ADC
	cmp r1, r0
	bne _08017AD2
	movs r2, #1
_08017AD2:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_08017AD8: .4byte 0x03005AEC
_08017ADC: .4byte 0x00003C19
	thumb_func_end InUnionRoom

	thumb_func_start sub_08017AE0
sub_08017AE0: @ 0x08017AE0
	push {r4, r5, r6, lr}
	movs r6, #0
	movs r5, #0
	ldr r0, _08017B28
	ldrb r0, [r0]
	cmp r6, r0
	bge _08017B20
_08017AEE:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _08017B2C
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0x38
	bl GetMonData3
	cmp r0, #0x1e
	bhi _08017B16
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	movs r1, #0xce
	lsls r1, r1, #1
	cmp r0, r1
	beq _08017B16
	adds r6, #1
_08017B16:
	adds r5, #1
	ldr r0, _08017B28
	ldrb r0, [r0]
	cmp r5, r0
	blt _08017AEE
_08017B20:
	cmp r6, #1
	bgt _08017B30
	movs r0, #0
	b _08017B32
	.align 2, 0
_08017B28: .4byte 0x0202418D
_08017B2C: .4byte 0x02024190
_08017B30:
	movs r0, #1
_08017B32:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end sub_08017AE0

	thumb_func_start sub_08017B38
sub_08017B38: @ 0x08017B38
	movs r1, #0
	strh r1, [r0]
	strh r1, [r0, #2]
	str r1, [r0, #4]
	strh r1, [r0, #0xa]
	strh r1, [r0, #0xc]
	strh r1, [r0, #0xe]
	strh r1, [r0, #0x10]
	str r1, [r0, #0x14]
	bx lr
	thumb_func_end sub_08017B38

	thumb_func_start sub_08017B4C
sub_08017B4C: @ 0x08017B4C
	push {lr}
	ldr r0, _08017B58
	bl sub_08017B38
	pop {r0}
	bx r0
	.align 2, 0
_08017B58: .4byte 0x020228F4
	thumb_func_end sub_08017B4C

	thumb_func_start sub_08017B5C
sub_08017B5C: @ 0x08017B5C
	push {r4, r5, lr}
	adds r5, r1, #0
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	ldr r0, _08017B98
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	strh r0, [r5, #0xa]
	adds r0, r4, #0
	movs r1, #0x38
	bl GetMonData3
	strh r0, [r5, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl GetMonData3
	str r0, [r5, #4]
	ldrh r1, [r5, #0xa]
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r1, r0
	beq _08017B9C
	movs r0, #0
	b _08017B9E
	.align 2, 0
_08017B98: .4byte 0x02024190
_08017B9C:
	movs r0, #1
_08017B9E:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end sub_08017B5C

	thumb_func_start sub_08017BA4
sub_08017BA4: @ 0x08017BA4
	push {r4, r5, lr}
	adds r5, r1, #0
	movs r1, #0x64
	adds r4, r0, #0
	muls r4, r1, r4
	ldr r0, _08017BD8
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	strh r0, [r5, #0xe]
	adds r0, r4, #0
	movs r1, #0x38
	bl GetMonData3
	strh r0, [r5, #0x10]
	adds r0, r4, #0
	movs r1, #0
	bl GetMonData3
	str r0, [r5, #0x14]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08017BD8: .4byte 0x02024190
	thumb_func_end sub_08017BA4

	thumb_func_start sub_08017BDC
sub_08017BDC: @ 0x08017BDC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r1, r1, #0x18
	movs r2, #0
	mov r8, r2
	cmp r1, #0
	bne _08017BFA
	ldrh r7, [r0, #0xa]
	ldr r6, [r0, #4]
	b _08017BFE
_08017BF2:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	b _08017C32
_08017BFA:
	ldrh r7, [r0, #0xe]
	ldr r6, [r0, #0x14]
_08017BFE:
	movs r5, #0
	b _08017C2A
_08017C02:
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	ldr r0, _08017C40
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0
	bl GetMonData3
	cmp r0, r6
	bne _08017C28
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r7
	beq _08017BF2
_08017C28:
	adds r5, #1
_08017C2A:
	ldr r0, _08017C44
	ldrb r0, [r0]
	cmp r5, r0
	blt _08017C02
_08017C32:
	mov r0, r8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08017C40: .4byte 0x02024190
_08017C44: .4byte 0x0202418D
	thumb_func_end sub_08017BDC

	thumb_func_start sub_08017C48
sub_08017C48: @ 0x08017C48
	push {r4, lr}
	adds r4, r0, #0
	bl UR_ClearBg0
	bl UnlockPlayerFieldControls
	bl sub_08097EAC
	ldr r1, _08017C80
	movs r0, #0
	strb r0, [r1]
	cmp r4, #0
	beq _08017C78
	ldr r2, _08017C84
	ldrh r0, [r2, #2]
	ldrh r1, [r2, #0xa]
	ldrh r2, [r2, #0xc]
	bl SetTradeBoardRegisteredMonInfo
	movs r0, #0x40
	movs r1, #0
	movs r2, #0
	bl UpdateGameData_SetActivity
_08017C78:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08017C80: .4byte 0x020228E0
_08017C84: .4byte 0x020228F4
	thumb_func_end sub_08017C48

	thumb_func_start sub_08017C88
sub_08017C88: @ 0x08017C88
	push {lr}
	bl LockPlayerFieldControls
	bl ScriptFreezeEventObjects
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08017C88

	thumb_func_start sub_08017C98
sub_08017C98: @ 0x08017C98
	push {r4, lr}
	movs r3, #0x80
	movs r2, #0
	ldr r4, [r0, #0xc]
_08017CA0:
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1, #0x18]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08017CC8
	ldrb r0, [r1, #0xb]
	lsls r0, r0, #0x1f
	lsrs r0, r0, #0x1f
	lsls r0, r0, #3
	orrs r3, r0
	ldrb r1, [r1, #2]
	movs r0, #7
	ands r0, r1
	orrs r3, r0
	lsls r0, r3, #0x18
	lsrs r3, r0, #0x18
	b _08017CD2
_08017CC8:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08017CA0
_08017CD2:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08017C98

	thumb_func_start sub_08017CDC
sub_08017CDC: @ 0x08017CDC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sb, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	bl GetMultiplayerId
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0x64
	muls r1, r0, r1
	ldr r0, _08017E68
	adds r1, r1, r0
	mov r8, r1
	bl DynamicPlaceholderTextUtil_Reset
	mov r7, sb
	adds r7, #0xa8
	bl sub_080686F0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xb
	muls r1, r0, r1
	ldr r0, _08017E6C
	adds r1, r1, r0
	adds r0, r7, #0
	bl StringCopy
	movs r0, #0
	adds r1, r7, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r1, r8
	adds r1, #0x30
	movs r0, #1
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r6, sb
	adds r6, #0xb7
	ldr r1, _08017E70
	mov r2, r8
	ldrb r0, [r2, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl StringCopy
	movs r0, #2
	adds r1, r6, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r5, sb
	adds r5, #0xc6
	mov r0, r8
	ldrh r1, [r0, #0xc]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	movs r0, #3
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r2, #0xd5
	add r2, sb
	mov sl, r2
	mov r0, r8
	ldrh r1, [r0, #0x10]
	mov r0, sl
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	mov r4, sb
	adds r4, #0xe4
	mov r2, r8
	ldrh r1, [r2, #0x12]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #2
	bl ConvertIntToDecimalStringN
	movs r0, #4
	mov r1, sl
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r0, #5
	adds r1, r4, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, sb
	ldr r1, _08017E74
	adds r0, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r0, _08017E78
	adds r1, r4, #0
	bl StringCopy
	mov r0, r8
	ldrh r1, [r0, #0x14]
	ldr r4, _08017E7C
	cmp r1, r4
	ble _08017DC6
	adds r1, r4, #0
_08017DC6:
	adds r0, r7, #0
	movs r2, #0
	movs r3, #4
	bl ConvertIntToDecimalStringN
	movs r0, #0
	adds r1, r7, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r2, r8
	ldrh r1, [r2, #0x16]
	cmp r1, r4
	ble _08017DE2
	adds r1, r4, #0
_08017DE2:
	adds r0, r6, #0
	movs r2, #0
	movs r3, #4
	bl ConvertIntToDecimalStringN
	movs r0, #2
	adds r1, r6, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	mov r0, r8
	ldrh r1, [r0, #0x20]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #5
	bl ConvertIntToDecimalStringN
	movs r0, #3
	adds r1, r5, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r7, #0
	movs r6, #0x80
	lsls r6, r6, #0x13
	mov r5, r8
	adds r5, #0x28
	mov r4, sl
_08017E16:
	ldrh r1, [r5]
	adds r0, r4, #0
	bl CopyEasyChatWord
	lsrs r0, r6, #0x18
	adds r1, r4, #0
	bl DynamicPlaceholderTextUtil_SetPlaceholderPtr
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r6, r6, r2
	adds r5, #2
	adds r4, #0xf
	adds r7, #1
	cmp r7, #3
	ble _08017E16
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, sb
	ldr r1, _08017E80
	adds r0, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	ldr r5, _08017E78
	adds r0, r5, #0
	adds r1, r4, #0
	bl StringAppend
	ldr r0, [sp]
	cmp r0, #1
	bne _08017E88
	ldr r1, _08017E84
	adds r0, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	adds r0, r5, #0
	adds r1, r4, #0
	bl StringAppend
	b _08017EA8
	.align 2, 0
_08017E68: .4byte 0x020397F8
_08017E6C: .4byte 0x082E3564
_08017E70: .4byte 0x082C1F08
_08017E74: .4byte 0x082C1F1C
_08017E78: .4byte 0x02021C7C
_08017E7C: .4byte 0x0000270F
_08017E80: .4byte 0x082C1F54
_08017E84: .4byte 0x082C1FAC
_08017E88:
	ldr r2, [sp]
	cmp r2, #0
	bne _08017EA8
	ldr r0, _08017EB8
	mov r2, r8
	ldrb r1, [r2]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r4, #0
	bl DynamicPlaceholderTextUtil_ExpandPlaceholders
	adds r0, r5, #0
	adds r1, r4, #0
	bl StringAppend
_08017EA8:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08017EB8: .4byte 0x082C1FA4
	thumb_func_end sub_08017CDC
