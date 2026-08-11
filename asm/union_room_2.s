.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

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
