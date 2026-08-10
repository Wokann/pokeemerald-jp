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

	thumb_func_start TryAddPokeballIconToHealthbox
TryAddPokeballIconToHealthbox: @ 0x08073D80
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	ldr r0, _08073E1C
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08073E56
	movs r0, #8
	ands r1, r0
	cmp r1, #0
	bne _08073E56
	ldr r6, _08073E20
	lsls r0, r2, #4
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r5, r0, r6
	ldrh r0, [r5, #0x3a]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08073E56
	ldr r1, _08073E24
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _08073E28
	adds r0, r0, r1
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08073E56
	ldrh r0, [r5, #0x38]
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r7, #0
	beq _08073E34
	movs r0, #0x46
	bl GetHealthboxElementGfxPtr
	lsls r1, r4, #4
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r1, r1, r6
	ldrh r1, [r1, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x11
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
	ldr r2, _08073E2C
	adds r1, r1, r2
	ldr r2, _08073E30
	bl CpuSet
	b _08073E56
	.align 2, 0
_08073E1C: .4byte 0x02022C90
_08073E20: .4byte 0x020205AC
_08073E24: .4byte 0x02023D12
_08073E28: .4byte 0x020243E8
_08073E2C: .4byte 0x06010000
_08073E30: .4byte 0x04000008
_08073E34:
	str r7, [sp]
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x11
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	ldr r0, _08073E60
	adds r1, r1, r0
	ldr r2, _08073E64
	mov r0, sp
	bl CpuSet
_08073E56:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08073E60: .4byte 0x06010000
_08073E64: .4byte 0x05000008
	thumb_func_end TryAddPokeballIconToHealthbox

	thumb_func_start UpdateStatusIconInHealthbox
UpdateStatusIconInHealthbox: @ 0x08073E68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r0, _08073ECC
	mov r2, sb
	lsls r1, r2, #4
	add r1, sb
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrh r0, [r1, #0x3a]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldrh r0, [r1, #0x38]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	adds r0, r7, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08073ED8
	ldr r1, _08073ED0
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _08073ED4
	adds r0, r0, r1
	movs r1, #0x37
	bl GetMonData3
	adds r4, r0, #0
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	movs r3, #0x12
	mov r8, r3
	cmp r0, #0
	bne _08073EF4
	movs r0, #0x1a
	mov r8, r0
	b _08073EF4
	.align 2, 0
_08073ECC: .4byte 0x020205AC
_08073ED0: .4byte 0x02023D12
_08073ED4: .4byte 0x02024190
_08073ED8:
	ldr r1, _08073F14
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _08073F18
	adds r0, r0, r1
	movs r1, #0x37
	bl GetMonData3
	adds r4, r0, #0
	movs r1, #0x11
	mov r8, r1
_08073EF4:
	movs r0, #7
	ands r0, r4
	cmp r0, #0
	beq _08073F1C
	movs r0, #0x1b
	adds r1, r7, #0
	bl GetStatusIconForBattlerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetHealthboxElementGfxPtr
	adds r6, r0, #0
	movs r0, #2
	b _08074028
	.align 2, 0
_08073F14: .4byte 0x02023D12
_08073F18: .4byte 0x020243E8
_08073F1C:
	movs r0, #0x88
	ands r0, r4
	cmp r0, #0
	beq _08073F3A
	movs r0, #0x15
	adds r1, r7, #0
	bl GetStatusIconForBattlerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetHealthboxElementGfxPtr
	adds r6, r0, #0
	movs r0, #0
	b _08074028
_08073F3A:
	movs r0, #0x10
	ands r0, r4
	cmp r0, #0
	beq _08073F58
	movs r0, #0x21
	adds r1, r7, #0
	bl GetStatusIconForBattlerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetHealthboxElementGfxPtr
	adds r6, r0, #0
	movs r0, #4
	b _08074028
_08073F58:
	movs r0, #0x20
	ands r0, r4
	cmp r0, #0
	beq _08073F76
	movs r0, #0x1e
	adds r1, r7, #0
	bl GetStatusIconForBattlerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetHealthboxElementGfxPtr
	adds r6, r0, #0
	movs r0, #3
	b _08074028
_08073F76:
	movs r0, #0x40
	ands r0, r4
	cmp r0, #0
	beq _08073F94
	movs r0, #0x18
	adds r1, r7, #0
	bl GetStatusIconForBattlerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetHealthboxElementGfxPtr
	adds r6, r0, #0
	movs r0, #1
	b _08074028
_08073F94:
	movs r0, #0x27
	bl GetHealthboxElementGfxPtr
	adds r6, r0, #0
	movs r4, #0
	mov r2, sb
	lsls r0, r2, #4
	mov r3, r8
	lsls r3, r3, #0x10
	mov r8, r3
	lsls r7, r7, #2
	ldr r1, _08074014
	add r0, sb
	lsls r0, r0, #2
	adds r5, r0, r1
_08073FB2:
	ldrh r1, [r5, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	mov r2, r8
	asrs r0, r2, #0x10
	adds r1, r1, r0
	adds r1, r1, r4
	lsls r1, r1, #5
	ldr r3, _08074018
	adds r1, r1, r3
	adds r0, r6, #0
	ldr r2, _0807401C
	bl CpuSet
	adds r4, #1
	cmp r4, #2
	ble _08073FB2
	ldr r0, _08074020
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, r7, r0
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08074008
	movs r0, #1
	bl GetHealthboxElementGfxPtr
	ldr r2, _08074014
	mov r3, sl
	lsls r1, r3, #4
	add r1, sl
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x11
	ldr r2, _08074018
	adds r1, r1, r2
	ldr r2, _08074024
	bl CpuSet
_08074008:
	mov r0, sb
	movs r1, #1
	bl TryAddPokeballIconToHealthbox
	b _080740EA
	.align 2, 0
_08074014: .4byte 0x020205AC
_08074018: .4byte 0x06010000
_0807401C: .4byte 0x04000008
_08074020: .4byte 0x02024174
_08074024: .4byte 0x04000010
_08074028:
	mov r1, sb
	lsls r5, r1, #4
	add r5, sb
	lsls r5, r5, #2
	ldr r2, _080740F8
	adds r5, r5, r2
	ldrb r4, [r5, #5]
	lsrs r4, r4, #4
	lsls r4, r4, #4
	adds r4, #0xc
	adds r4, r4, r7
	ldr r1, _080740FC
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r2, #2
	bl FillPalette
	lsls r4, r4, #1
	ldr r0, _08074100
	adds r0, r4, r0
	ldr r1, _08074104
	adds r4, r4, r1
	adds r1, r4, #0
	movs r2, #1
	bl CpuSet
	ldrh r1, [r5, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	add r1, r8
	lsls r1, r1, #5
	ldr r2, _08074108
	mov r8, r2
	add r1, r8
	ldr r2, _0807410C
	adds r0, r6, #0
	bl CpuSet
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08074096
	adds r0, r7, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080740E2
_08074096:
	ldr r0, _08074110
	ldr r0, [r0]
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080740E2
	movs r0, #0
	bl GetHealthboxElementGfxPtr
	mov r3, sl
	lsls r4, r3, #4
	add r4, sl
	lsls r4, r4, #2
	ldr r1, _080740F8
	adds r4, r4, r1
	ldrh r1, [r4, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x11
	add r1, r8
	ldr r5, _08074114
	adds r2, r5, #0
	bl CpuSet
	movs r0, #0x41
	bl GetHealthboxElementGfxPtr
	ldrh r1, [r4, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x11
	adds r1, #0x20
	add r1, r8
	adds r2, r5, #0
	bl CpuSet
_080740E2:
	mov r0, sb
	movs r1, #0
	bl TryAddPokeballIconToHealthbox
_080740EA:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080740F8: .4byte 0x020205AC
_080740FC: .4byte 0x082FCE02
_08074100: .4byte 0x020375B4
_08074104: .4byte 0x05000200
_08074108: .4byte 0x06010000
_0807410C: .4byte 0x04000018
_08074110: .4byte 0x02024174
_08074114: .4byte 0x04000008
	thumb_func_end UpdateStatusIconInHealthbox

	thumb_func_start GetStatusIconForBattlerId
GetStatusIconForBattlerId: @ 0x08074118
	push {lr}
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	lsrs r2, r0, #0x18
	adds r0, r2, #0
	subs r0, #0x15
	cmp r0, #0xc
	bhi _080741D8
	lsls r0, r0, #2
	ldr r1, _08074134
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08074134: .4byte 0x08074138
_08074138: @ jump table
	.4byte _0807416C @ case 0
	.4byte _080741D8 @ case 1
	.4byte _080741D8 @ case 2
	.4byte _08074182 @ case 3
	.4byte _080741D8 @ case 4
	.4byte _080741D8 @ case 5
	.4byte _08074198 @ case 6
	.4byte _080741D8 @ case 7
	.4byte _080741D8 @ case 8
	.4byte _080741AE @ case 9
	.4byte _080741D8 @ case 10
	.4byte _080741D8 @ case 11
	.4byte _080741C4 @ case 12
_0807416C:
	movs r2, #0x15
	cmp r3, #0
	beq _080741D8
	movs r2, #0x47
	cmp r3, #1
	beq _080741D8
	movs r2, #0x65
	cmp r3, #2
	bne _080741D8
	movs r2, #0x56
	b _080741D8
_08074182:
	movs r2, #0x18
	cmp r3, #0
	beq _080741D8
	movs r2, #0x4a
	cmp r3, #1
	beq _080741D8
	movs r2, #0x68
	cmp r3, #2
	bne _080741D8
	movs r2, #0x59
	b _080741D8
_08074198:
	movs r2, #0x1b
	cmp r3, #0
	beq _080741D8
	movs r2, #0x4d
	cmp r3, #1
	beq _080741D8
	movs r2, #0x6b
	cmp r3, #2
	bne _080741D8
	movs r2, #0x5c
	b _080741D8
_080741AE:
	movs r2, #0x1e
	cmp r3, #0
	beq _080741D8
	movs r2, #0x50
	cmp r3, #1
	beq _080741D8
	movs r2, #0x6e
	cmp r3, #2
	bne _080741D8
	movs r2, #0x5f
	b _080741D8
_080741C4:
	movs r2, #0x21
	cmp r3, #0
	beq _080741D8
	movs r2, #0x53
	cmp r3, #1
	beq _080741D8
	movs r2, #0x71
	cmp r3, #2
	bne _080741D8
	movs r2, #0x62
_080741D8:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetStatusIconForBattlerId

	thumb_func_start AddTextPrinterAndCreateWindowOnHealthbox
AddTextPrinterAndCreateWindowOnHealthbox: @ 0x080741E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _08074254
	lsls r0, r5, #4
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r0, [r0, #0x3a]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerPosition
	ldr r1, _08074258
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
	adds r6, r0, r1
	movs r1, #7
	mov r8, r1
	ldr r2, _0807425C
	adds r0, r6, #0
	bl RenderTextFont9
	movs r7, #3
	movs r4, #0
_08074230:
	ldr r0, _0807425C
	adds r0, r7, r0
	ldrb r1, [r0]
	adds r0, r1, #0
	subs r0, #0x37
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _0807424E
	adds r0, r1, #0
	adds r0, #0x79
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bhi _08074260
_0807424E:
	movs r0, #0x2c
	b _0807427E
	.align 2, 0
_08074254: .4byte 0x020205AC
_08074258: .4byte 0x02024178
_0807425C: .4byte 0x085ABC38
_08074260:
	adds r0, r1, #0
	subs r0, #0x4b
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _08074278
	adds r0, r1, #0
	adds r0, #0x65
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _0807427C
_08074278:
	movs r0, #0x2d
	b _0807427E
_0807427C:
	movs r0, #0x2b
_0807427E:
	bl GetHealthboxElementGfxPtr
	lsls r1, r4, #6
	adds r1, r6, r1
	ldr r2, _08074314
	bl CpuSet
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r7, #1
	cmp r4, r8
	blo _08074230
	movs r7, #3
	movs r2, #3
	add r2, r8
	mov sb, r2
	cmp r7, sb
	bge _08074304
	ldr r1, _08074318
	ldr r0, _08074314
	mov sl, r0
	lsls r0, r5, #4
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	mov r8, r0
_080742B4:
	mov r1, r8
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	adds r5, r7, #0
	cmp r7, #0
	bge _080742C4
	adds r5, r7, #7
_080742C4:
	asrs r5, r5, #3
	lsls r4, r5, #3
	subs r4, r7, r4
	adds r0, r0, r4
	lsls r5, r5, #6
	adds r0, r0, r5
	lsls r0, r0, #5
	ldr r2, _0807431C
	adds r1, r0, r2
	adds r0, r6, #0
	mov r2, sl
	bl CpuSet
	adds r6, #0x20
	mov r1, r8
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x16
	lsrs r0, r0, #0x16
	adds r4, #8
	adds r0, r0, r4
	adds r0, r0, r5
	lsls r0, r0, #5
	ldr r2, _0807431C
	adds r1, r0, r2
	adds r0, r6, #0
	mov r2, sl
	bl CpuSet
	adds r6, #0x20
	adds r7, #1
	cmp r7, sb
	blt _080742B4
_08074304:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08074314: .4byte 0x04000008
_08074318: .4byte 0x020205AC
_0807431C: .4byte 0x06010000
	thumb_func_end AddTextPrinterAndCreateWindowOnHealthbox

	thumb_func_start UpdateLeftNoOfBallsTextOnHealthbox
UpdateLeftNoOfBallsTextOnHealthbox: @ 0x08074320
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	ldr r0, _080743D0
	mov r8, r0
	ldr r1, _080743D4
	bl StringCopy
	adds r7, r0, #0
	ldr r0, _080743D8
	ldrb r1, [r0]
	adds r0, r7, #0
	movs r2, #1
	movs r3, #2
	bl ConvertIntToDecimalStringN
	adds r7, r0, #0
	ldr r1, _080743DC
	bl StringAppend
	ldr r0, _080743E0
	lsls r4, r5, #4
	adds r4, r4, r5
	lsls r4, r4, #2
	adds r4, r4, r0
	ldrh r0, [r4, #0x3a]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerPosition
	ldr r1, _080743E4
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
	movs r6, #7
	adds r0, r7, #0
	movs r1, #7
	mov r2, r8
	bl RenderTextFont9
	adds r7, #0x20
	movs r5, #4
_08074390:
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x16
	lsrs r2, r0, #0x16
	adds r0, r5, #0
	cmp r5, #0
	bge _0807439E
	adds r0, r5, #7
_0807439E:
	asrs r0, r0, #3
	lsls r1, r0, #3
	subs r1, r5, r1
	adds r1, #0x18
	adds r1, r2, r1
	lsls r0, r0, #6
	adds r1, r1, r0
	lsls r1, r1, #5
	ldr r0, _080743E8
	adds r1, r1, r0
	adds r0, r7, #0
	ldr r2, _080743EC
	bl CpuSet
	adds r7, #0x40
	adds r5, #1
	adds r0, r6, #4
	cmp r5, r0
	blt _08074390
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080743D0: .4byte 0x02022AE0
_080743D4: .4byte 0x085ABC43
_080743D8: .4byte 0x02039D18
_080743DC: .4byte 0x085ABC4B
_080743E0: .4byte 0x020205AC
_080743E4: .4byte 0x02024178
_080743E8: .4byte 0x06010000
_080743EC: .4byte 0x04000008
	thumb_func_end UpdateLeftNoOfBallsTextOnHealthbox
