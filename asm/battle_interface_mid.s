.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start UpdateNickInHealthbox
UpdateNickInHealthbox: @ 0x08073AE4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	movs r0, #0
	str r0, [sp, #0xc]
	ldr r5, _08073B64
	ldr r1, _08073B68
	adds r0, r5, #0
	bl StringCopy
	adds r0, r4, #0
	movs r1, #2
	mov r2, sp
	bl GetMonData3
	mov r0, sp
	bl StringGet_Nickname
	adds r0, r5, #0
	mov r1, sp
	bl StringAppend
	adds r7, r0, #0
	adds r0, r4, #0
	bl GetMonGender
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r4, #0
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r2, r0, #0
	cmp r0, #0x1d
	beq _08073B40
	cmp r0, #0x20
	bne _08073B56
_08073B40:
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r0, _08073B6C
	adds r1, r1, r0
	mov r0, sp
	bl StringCompare
	cmp r0, #0
	bne _08073B56
	movs r5, #0x64
_08073B56:
	cmp r5, #0
	beq _08073B74
	cmp r5, #0xfe
	beq _08073B7C
	ldr r1, _08073B70
	b _08073B7E
	.align 2, 0
_08073B64: .4byte 0x02022AE0
_08073B68: .4byte 0x085CC4EA
_08073B6C: .4byte 0x082EA31C
_08073B70: .4byte 0x085CC4FA
_08073B74:
	ldr r1, _08073B78
	b _08073B7E
	.align 2, 0
_08073B78: .4byte 0x085CC4F0
_08073B7C:
	ldr r1, _08073C20
_08073B7E:
	adds r0, r7, #0
	bl StringCopy
	ldr r1, _08073C24
	mov r2, sl
	lsls r5, r2, #4
	adds r0, r5, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerPosition
	ldr r1, _08073C28
	ldr r2, [r1]
	movs r1, #0xba
	lsls r1, r1, #1
	adds r2, r2, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #7
	movs r0, #0xa4
	lsls r0, r0, #3
	adds r1, r1, r0
	ldr r0, [r2]
	adds r7, r0, r1
	ldr r4, _08073C2C
	adds r0, r4, #0
	bl StringLength
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r6, r8
	subs r6, #6
	movs r1, #0
	mov sb, r1
	mov r2, r8
	adds r0, r2, r4
	movs r2, #6
	subs r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl StringFill
	adds r0, r4, #0
	bl StringLength
	lsls r0, r0, #0x10
	ldr r1, _08073C30
	adds r0, r0, r1
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r0, r7, #0
	movs r1, #7
	adds r2, r4, #0
	bl RenderTextFont9
	movs r6, #3
	cmp sb, r8
	bhs _08073C72
_08073BFE:
	ldr r0, _08073C2C
	adds r0, r6, r0
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0x37
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _08073C1C
	adds r0, r1, #0
	adds r0, #0x79
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bhi _08073C34
_08073C1C:
	movs r0, #0x2c
	b _08073C52
	.align 2, 0
_08073C20: .4byte 0x085CC4F5
_08073C24: .4byte 0x020205AC
_08073C28: .4byte 0x02024178
_08073C2C: .4byte 0x02022AE0
_08073C30: .4byte 0xFFFA0000
_08073C34:
	adds r0, r1, #0
	subs r0, #0x4b
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _08073C4C
	adds r0, r1, #0
	adds r0, #0x65
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08073C50
_08073C4C:
	movs r0, #0x2d
	b _08073C52
_08073C50:
	movs r0, #0x2b
_08073C52:
	bl GetHealthboxElementGfxPtr
	mov r2, sb
	lsls r1, r2, #6
	adds r1, r7, r1
	ldr r2, _08073CE8
	bl CpuSet
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	adds r6, #1
	cmp sb, r8
	blo _08073BFE
_08073C72:
	ldr r1, _08073CEC
	mov r2, sl
	adds r0, r5, r2
	lsls r0, r0, #2
	adds r4, r0, r1
	ldrh r0, [r4, #0x3a]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08073CF4
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08073CF4
	movs r6, #0
	cmp r6, r8
	bge _08073D64
	ldr r0, _08073CF0
	mov sb, r0
	ldr r5, _08073CE8
_08073CA2:
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	adds r1, r6, #2
	adds r0, r0, r1
	ldr r1, [sp, #0xc]
	adds r0, r0, r1
	lsls r0, r0, #5
	mov r2, sb
	adds r1, r0, r2
	adds r0, r7, #0
	adds r2, r5, #0
	bl CpuSet
	adds r7, #0x20
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	adds r1, r6, #0
	adds r1, #0xa
	adds r0, r0, r1
	ldr r1, [sp, #0xc]
	adds r0, r0, r1
	lsls r0, r0, #5
	mov r2, sb
	adds r1, r0, r2
	adds r0, r7, #0
	adds r2, r5, #0
	bl CpuSet
	adds r7, #0x20
	adds r6, #1
	cmp r6, r8
	blt _08073CA2
	b _08073D64
	.align 2, 0
_08073CE8: .4byte 0x04000008
_08073CEC: .4byte 0x020205AC
_08073CF0: .4byte 0x06010000
_08073CF4:
	ldr r1, _08073D74
	mov r2, sl
	adds r0, r5, r2
	lsls r0, r0, #2
	adds r5, r0, r1
	ldrh r0, [r5, #0x3a]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08073D12
	movs r0, #1
	str r0, [sp, #0xc]
_08073D12:
	movs r6, #0
	cmp r6, r8
	bge _08073D64
	ldr r1, _08073D78
	mov sl, r1
	ldr r2, _08073D7C
	mov sb, r2
_08073D20:
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	adds r4, r6, #1
	adds r0, r0, r4
	ldr r1, [sp, #0xc]
	adds r0, r0, r1
	lsls r0, r0, #5
	mov r2, sl
	adds r1, r0, r2
	adds r0, r7, #0
	mov r2, sb
	bl CpuSet
	adds r7, #0x20
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	adds r1, r6, #0
	adds r1, #9
	adds r0, r0, r1
	ldr r1, [sp, #0xc]
	adds r0, r0, r1
	lsls r0, r0, #5
	mov r2, sl
	adds r1, r0, r2
	adds r0, r7, #0
	mov r2, sb
	bl CpuSet
	adds r7, #0x20
	adds r6, r4, #0
	cmp r6, r8
	blt _08073D20
_08073D64:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08073D74: .4byte 0x020205AC
_08073D78: .4byte 0x06010000
_08073D7C: .4byte 0x04000008
	thumb_func_end UpdateNickInHealthbox
