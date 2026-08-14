.include "asm/macros.inc"
.include "constants/constants.inc"
	.section .text.battle_anim_mons_arc,"ax",%progbits
.syntax unified

	thumb_func_start TranslateAnimHorizontalArc
TranslateAnimHorizontalArc: @ 0x080A61C8
	push {r4, lr}
	adds r4, r0, #0
	bl AnimTranslateLinear
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A61F4
	ldrh r0, [r4, #0x3a]
	ldrh r1, [r4, #0x3c]
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, #0x26]
	adds r0, r0, r1
	strh r0, [r4, #0x26]
	movs r0, #0
	b _080A61F6
_080A61F4:
	movs r0, #1
_080A61F6:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end TranslateAnimHorizontalArc

	thumb_func_start TranslateAnimVerticalArc
TranslateAnimVerticalArc: @ 0x080A61FC
	push {r4, lr}
	adds r4, r0, #0
	bl AnimTranslateLinear
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A6228
	ldrh r0, [r4, #0x3a]
	ldrh r1, [r4, #0x3c]
	adds r0, r0, r1
	strh r0, [r4, #0x3c]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x18
	movs r2, #0x38
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	movs r0, #0
	b _080A622A
_080A6228:
	movs r0, #1
_080A622A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end TranslateAnimVerticalArc

	.section .text,"ax",%progbits
	thumb_func_start CreateAdditionalMonSpriteForMoveAnim
CreateAdditionalMonSpriteForMoveAnim: @ 0x080A7C5C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r4, [sp, #0x30]
	ldr r5, [sp, #0x34]
	ldr r6, [sp, #0x38]
	mov r8, r6
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov sl, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #4]
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	str r5, [sp, #8]
	lsls r0, r7, #3
	ldr r1, _080A7D3C
	adds r0, r0, r1
	bl LoadSpriteSheet
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	ldr r1, _080A7D40
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	bl AllocSpritePalette
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r4, _080A7D44
	ldr r0, [r4]
	cmp r0, #0
	beq _080A7CDA
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080A7CDA
	movs r0, #0x80
	lsls r0, r0, #6
	bl AllocZeroed
	ldr r1, [r4]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r1, r2
	str r0, [r1]
_080A7CDA:
	mov r3, sb
	cmp r3, #0
	bne _080A7D78
	adds r0, r6, #0
	ldr r1, [sp, #0x3c]
	mov r2, r8
	bl GetMonSpritePalFromSpeciesAndPersonality
	lsls r1, r5, #0x14
	movs r2, #0x80
	lsls r2, r2, #0x11
	adds r1, r1, r2
	lsrs r1, r1, #0x10
	movs r2, #0x20
	bl LoadCompressedPalette
	ldr r3, [sp, #0x44]
	cmp r3, #1
	beq _080A7D26
	ldr r0, [sp, #0x40]
	lsls r1, r0, #0x18
	lsrs r1, r1, #0x18
	movs r0, #5
	bl sub_08068438
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080A7D26
	ldr r0, _080A7D48
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r2, [sp, #0x40]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	cmp r0, #0
	beq _080A7D50
_080A7D26:
	lsls r0, r6, #3
	ldr r1, _080A7D4C
	adds r0, r0, r1
	ldr r1, _080A7D44
	ldr r1, [r1]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r1, r3
	ldr r1, [r1]
	movs r2, #1
	b _080A7DD2
	.align 2, 0
_080A7D3C: .4byte 0x084FE6CC
_080A7D40: .4byte 0x084FE69C
_080A7D44: .4byte 0x02024178
_080A7D48: .4byte 0x02024174
_080A7D4C: .4byte 0x082DDA1C
_080A7D50:
	lsls r0, r6, #3
	ldr r1, _080A7D70
	adds r0, r0, r1
	ldr r1, _080A7D74
	ldr r1, [r1]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #1
	str r2, [sp]
	adds r2, r6, #0
	mov r3, r8
	bl LoadSpecialPokePic_2
	b _080A7E08
	.align 2, 0
_080A7D70: .4byte 0x082DDA1C
_080A7D74: .4byte 0x02024178
_080A7D78:
	adds r0, r6, #0
	ldr r1, [sp, #0x3c]
	mov r2, r8
	bl GetMonSpritePalFromSpeciesAndPersonality
	lsls r1, r5, #0x14
	movs r3, #0x80
	lsls r3, r3, #0x11
	adds r1, r1, r3
	lsrs r1, r1, #0x10
	movs r2, #0x20
	bl LoadCompressedPalette
	ldr r0, [sp, #0x44]
	cmp r0, #1
	beq _080A7DBE
	ldr r2, [sp, #0x40]
	lsls r1, r2, #0x18
	lsrs r1, r1, #0x18
	movs r0, #5
	bl sub_08068438
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080A7DBE
	ldr r0, _080A7DE0
	ldr r0, [r0]
	ldr r1, [r0]
	ldr r3, [sp, #0x40]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldrh r2, [r0, #2]
	cmp r2, #0
	beq _080A7DEC
_080A7DBE:
	lsls r0, r6, #3
	ldr r1, _080A7DE4
	adds r0, r0, r1
	ldr r1, _080A7DE8
	ldr r1, [r1]
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r1, r1, r2
	ldr r1, [r1]
	movs r2, #0
_080A7DD2:
	str r2, [sp]
	adds r2, r6, #0
	mov r3, r8
	bl LoadSpecialPokePic_DontHandleDeoxys
	b _080A7E08
	.align 2, 0
_080A7DE0: .4byte 0x02024174
_080A7DE4: .4byte 0x082D6148
_080A7DE8: .4byte 0x02024178
_080A7DEC:
	lsls r0, r6, #3
	ldr r1, _080A7E54
	adds r0, r0, r1
	ldr r1, _080A7E58
	ldr r1, [r1]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r1, r3
	ldr r1, [r1]
	str r2, [sp]
	adds r2, r6, #0
	mov r3, r8
	bl LoadSpecialPokePic_2
_080A7E08:
	ldr r5, _080A7E58
	ldr r0, [r5]
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r2, [sp, #0xc]
	lsls r1, r2, #5
	ldr r3, _080A7E5C
	adds r1, r1, r3
	movs r2, #0x80
	lsls r2, r2, #4
	movs r3, #1
	bl RequestDma3Copy
	ldr r0, [r5]
	adds r0, r0, r4
	ldr r0, [r0]
	bl Free
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #0
	str r1, [r0]
	mov r0, sb
	cmp r0, #0
	bne _080A7E68
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #3
	ldr r1, _080A7E60
	adds r0, r0, r1
	mov r2, sl
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	ldr r3, _080A7E64
	b _080A7E7A
	.align 2, 0
_080A7E54: .4byte 0x082D6148
_080A7E58: .4byte 0x02024178
_080A7E5C: .4byte 0x06010000
_080A7E60: .4byte 0x084FE69C
_080A7E64: .4byte 0x082D45C8
_080A7E68:
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #3
	ldr r1, _080A7EC8
	adds r0, r0, r1
	mov r2, sl
	lsls r1, r2, #0x10
	asrs r1, r1, #0x10
	ldr r3, _080A7ECC
_080A7E7A:
	lsls r2, r6, #2
	adds r2, r2, r3
	ldrb r2, [r2, #1]
	ldr r3, [sp, #4]
	adds r2, r2, r3
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	ldr r3, [sp, #8]
	bl CreateSprite
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A7EB6
	ldr r3, _080A7ED0
	lsls r0, r4, #4
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r1, r3, #0
	adds r1, #0x10
	adds r1, r0, r1
	ldr r2, _080A7ED4
	str r2, [r1]
	adds r0, r0, r3
	movs r1, #0
	bl StartSpriteAffineAnim
_080A7EB6:
	adds r0, r4, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A7EC8: .4byte 0x084FE69C
_080A7ECC: .4byte 0x082D5A68
_080A7ED0: .4byte 0x020205AC
_080A7ED4: .4byte 0x082D2F50
	thumb_func_end CreateAdditionalMonSpriteForMoveAnim

	thumb_func_start DestroySpriteAndFreeResources_
DestroySpriteAndFreeResources_: @ 0x080A7ED8
	@ From src/battle_anim_mons.c
	push {lr}
	bl DestroySpriteAndFreeResources
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end DestroySpriteAndFreeResources_

	thumb_func_start GetBattlerSpriteCoordAttr
GetBattlerSpriteCoordAttr: @ 0x080A7EE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sb, r1
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A7F8C
	ldr r0, _080A7F18
	ldr r0, [r0]
	ldr r2, [r0, #0x18]
	ldrb r1, [r2, #4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080A7F1C
	ldrh r7, [r2, #2]
	ldr r2, [r2, #0x10]
	b _080A7F20
	.align 2, 0
_080A7F18: .4byte 0x02039BD4
_080A7F1C:
	ldrh r7, [r2]
	ldr r2, [r2, #8]
_080A7F20:
	cmp r7, #0xc9
	bne _080A7F6C
	movs r0, #0xc0
	lsls r0, r0, #0x12
	ands r0, r2
	lsrs r0, r0, #0x12
	movs r1, #0xc0
	lsls r1, r1, #0xa
	ands r1, r2
	lsrs r1, r1, #0xc
	orrs r0, r1
	movs r1, #0xc0
	lsls r1, r1, #2
	ands r1, r2
	lsrs r1, r1, #6
	orrs r0, r1
	movs r1, #3
	ands r1, r2
	orrs r0, r1
	movs r1, #0x1c
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _080A7F58
	movs r0, #0xc9
	b _080A7F62
_080A7F58:
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_080A7F62:
	lsls r1, r0, #2
	ldr r0, _080A7F68
	b _080A812C
	.align 2, 0
_080A7F68: .4byte 0x082D5A68
_080A7F6C:
	ldr r0, _080A7F84
	cmp r7, r0
	bne _080A7F74
	b _080A80FC
_080A7F74:
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r7, r0
	bhi _080A8044
	lsls r1, r7, #2
	ldr r0, _080A7F88
	b _080A812C
	.align 2, 0
_080A7F84: .4byte 0x00000181
_080A7F88: .4byte 0x082D5A68
_080A7F8C:
	mov r0, r8
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A8058
	ldr r0, _080A7FD8
	ldr r0, [r0]
	ldr r0, [r0]
	mov r1, r8
	lsls r2, r1, #2
	adds r1, r2, r0
	ldrh r0, [r1, #2]
	cmp r0, #0
	bne _080A7FE4
	ldr r0, _080A7FDC
	mov r1, r8
	lsls r4, r1, #1
	adds r4, r4, r0
	ldrh r0, [r4]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _080A7FE0
	adds r0, r0, r5
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrh r0, [r4]
	muls r0, r6, r0
	adds r0, r0, r5
	movs r1, #0
	bl GetMonData3
	adds r2, r0, #0
	b _080A7FEC
	.align 2, 0
_080A7FD8: .4byte 0x02024174
_080A7FDC: .4byte 0x02023D12
_080A7FE0: .4byte 0x02024190
_080A7FE4:
	ldrh r7, [r1, #2]
	ldr r0, _080A8024
	adds r0, r2, r0
	ldr r2, [r0]
_080A7FEC:
	cmp r7, #0xc9
	bne _080A803C
	movs r0, #0xc0
	lsls r0, r0, #0x12
	ands r0, r2
	lsrs r0, r0, #0x12
	movs r1, #0xc0
	lsls r1, r1, #0xa
	ands r1, r2
	lsrs r1, r1, #0xc
	orrs r0, r1
	movs r1, #0xc0
	lsls r1, r1, #2
	ands r1, r2
	lsrs r1, r1, #6
	orrs r0, r1
	movs r1, #3
	ands r1, r2
	orrs r0, r1
	movs r1, #0x1c
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _080A8028
	movs r0, #0xc9
	b _080A8032
	.align 2, 0
_080A8024: .4byte 0x02024160
_080A8028:
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_080A8032:
	lsls r1, r0, #2
	ldr r0, _080A8038
	b _080A812C
	.align 2, 0
_080A8038: .4byte 0x082D5A68
_080A803C:
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r7, r0
	bls _080A804C
_080A8044:
	ldr r4, _080A8048
	b _080A812E
	.align 2, 0
_080A8048: .4byte 0x082D5A68
_080A804C:
	lsls r1, r7, #2
	ldr r0, _080A8054
	b _080A812C
	.align 2, 0
_080A8054: .4byte 0x082D5A68
_080A8058:
	ldr r0, _080A8098
	ldr r0, [r0]
	ldr r0, [r0]
	mov r1, r8
	lsls r2, r1, #2
	adds r1, r2, r0
	ldrh r0, [r1, #2]
	cmp r0, #0
	bne _080A80A4
	ldr r0, _080A809C
	mov r1, r8
	lsls r4, r1, #1
	adds r4, r4, r0
	ldrh r0, [r4]
	movs r6, #0x64
	muls r0, r6, r0
	ldr r5, _080A80A0
	adds r0, r0, r5
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldrh r0, [r4]
	muls r0, r6, r0
	adds r0, r0, r5
	movs r1, #0
	bl GetMonData3
	adds r2, r0, #0
	b _080A80AC
	.align 2, 0
_080A8098: .4byte 0x02024174
_080A809C: .4byte 0x02023D12
_080A80A0: .4byte 0x020243E8
_080A80A4:
	ldrh r7, [r1, #2]
	ldr r0, _080A80E4
	adds r0, r2, r0
	ldr r2, [r0]
_080A80AC:
	cmp r7, #0xc9
	bne _080A80F6
	movs r0, #0xc0
	lsls r0, r0, #0x12
	ands r0, r2
	lsrs r0, r0, #0x12
	movs r1, #0xc0
	lsls r1, r1, #0xa
	ands r1, r2
	lsrs r1, r1, #0xc
	orrs r0, r1
	movs r1, #0xc0
	lsls r1, r1, #2
	ands r1, r2
	lsrs r1, r1, #6
	orrs r0, r1
	movs r1, #3
	ands r1, r2
	orrs r0, r1
	movs r1, #0x1c
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	bne _080A80E8
	movs r0, #0xc9
	b _080A80F2
	.align 2, 0
_080A80E4: .4byte 0x02024160
_080A80E8:
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_080A80F2:
	lsls r1, r0, #2
	b _080A812A
_080A80F6:
	ldr r0, _080A810C
	cmp r7, r0
	bne _080A8118
_080A80FC:
	ldr r0, _080A8110
	add r0, r8
	ldrb r0, [r0]
	lsls r0, r0, #2
	ldr r1, _080A8114
	adds r4, r0, r1
	b _080A812E
	.align 2, 0
_080A810C: .4byte 0x00000181
_080A8110: .4byte 0x02024188
_080A8114: .4byte 0x084FE684
_080A8118:
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r7, r0
	bls _080A8128
	ldr r4, _080A8124
	b _080A812E
	.align 2, 0
_080A8124: .4byte 0x082D45C8
_080A8128:
	lsls r1, r7, #2
_080A812A:
	ldr r0, _080A8140
_080A812C:
	adds r4, r1, r0
_080A812E:
	mov r0, sb
	cmp r0, #6
	bhi _080A81DE
	lsls r0, r0, #2
	ldr r1, _080A8144
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080A8140: .4byte 0x082D45C8
_080A8144: .4byte 0x080A8148
_080A8148: @ jump table
	.4byte _080A8164 @ case 0
	.4byte _080A816E @ case 1
	.4byte _080A819A @ case 2
	.4byte _080A81B2 @ case 3
	.4byte _080A8176 @ case 4
	.4byte _080A8188 @ case 5
	.4byte _080A81CA @ case 6
_080A8164:
	ldrb r1, [r4]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #3
	b _080A81E0
_080A816E:
	ldrb r0, [r4]
	lsrs r0, r0, #4
	lsls r0, r0, #3
	b _080A81E0
_080A8176:
	mov r0, r8
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4]
	lsrs r1, r1, #4
	b _080A81AC
_080A8188:
	mov r0, r8
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4]
	lsrs r1, r1, #4
	b _080A81C4
_080A819A:
	mov r0, r8
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r4]
	movs r1, #0xf
	ands r1, r2
_080A81AC:
	lsls r1, r1, #2
	subs r0, r0, r1
	b _080A81E0
_080A81B2:
	mov r0, r8
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r2, [r4]
	movs r1, #0xf
	ands r1, r2
_080A81C4:
	lsls r1, r1, #2
	adds r0, r0, r1
	b _080A81E0
_080A81CA:
	mov r0, r8
	movs r1, #1
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, #0x1f
	ldrb r1, [r4, #1]
	subs r0, r0, r1
	b _080A81E0
_080A81DE:
	movs r0, #0
_080A81E0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end GetBattlerSpriteCoordAttr

	thumb_func_start SetAverageBattlerPositions
SetAverageBattlerPositions: @ 0x080A81EC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r2
	mov sl, r3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	cmp r1, #0
	bne _080A820A
	movs r5, #0
	movs r6, #1
	b _080A820E
_080A820A:
	movs r5, #2
	movs r6, #3
_080A820E:
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	adds r0, r4, #0
	adds r1, r6, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	bl IsDoubleBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A8260
	bl IsContest
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A8260
	movs r0, #2
	eors r4, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r4, #0
	adds r1, r6, #0
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	mov r0, r8
	lsls r1, r0, #0x10
	lsls r2, r7, #0x10
	b _080A826C
_080A8260:
	mov r0, r8
	lsls r1, r0, #0x10
	lsrs r5, r1, #0x10
	lsls r0, r7, #0x10
	lsrs r3, r0, #0x10
	adds r2, r0, #0
_080A826C:
	asrs r0, r1, #0x10
	adds r0, r0, r5
	asrs r0, r0, #1
	mov r1, sb
	strh r0, [r1]
	asrs r0, r2, #0x10
	adds r0, r0, r3
	asrs r0, r0, #1
	mov r1, sl
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end SetAverageBattlerPositions

	thumb_func_start sub_080A8290
sub_080A8290: @ 0x080A8290
	push {r4, r5, r6, lr}
	mov r6, sl
	mov r5, sb
	mov r4, r8
	push {r4, r5, r6}
	sub sp, #4
	lsls r6, r1, #0x18
	lsrs r6, r6, #0x18
	ldr r0, _080A8328
	mov sl, r0
	bl CreateInvisibleSpriteWithCallback
	mov r8, r0
	mov r0, r8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, _080A832C
	mov sb, r0
	mov r0, r8
	lsls r3, r0, #4
	add r3, r8
	lsls r3, r3, #2
	mov r0, sb
	adds r5, r3, r0
	lsls r4, r6, #4
	adds r4, r4, r6
	lsls r4, r4, #2
	add r4, sb
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x44
	str r3, [sp]
	bl memcpy
	adds r2, r5, #0
	adds r2, #0x3f
	ldrb r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strb r0, [r2]
	ldrb r2, [r5, #5]
	movs r1, #0xd
	rsbs r1, r1, #0
	adds r0, r1, #0
	ands r0, r2
	strb r0, [r5, #5]
	ldrb r0, [r5, #1]
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	strb r1, [r5, #1]
	ldrh r1, [r4, #4]
	lsls r1, r1, #0x16
	lsrs r1, r1, #0x16
	ldrh r2, [r5, #4]
	ldr r0, _080A8330
	ands r0, r2
	orrs r0, r1
	strh r0, [r5, #4]
	movs r0, #0x1c
	add sb, r0
	ldr r3, [sp]
	add r3, sb
	mov r0, sl
	str r0, [r3]
	mov r0, r8
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A8328: .4byte 0x08007141
_080A832C: .4byte 0x020205AC
_080A8330: .4byte 0xFFFFFC00
	thumb_func_end sub_080A8290

	thumb_func_start sub_080A8334
sub_080A8334: @ 0x080A8334
	push {r4, lr}
	adds r4, r0, #0
	bl SetSpriteCoordsToAnimAttackerCoords
	ldr r0, _080A836C
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A8374
	ldr r2, _080A8370
	ldrh r0, [r4, #0x20]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r2, #6]
	rsbs r0, r0, #0
	strh r0, [r2, #6]
	adds r3, r4, #0
	adds r3, #0x3f
	ldrb r0, [r3]
	movs r1, #1
	orrs r0, r1
	strb r0, [r3]
	adds r1, r2, #0
	b _080A837E
	.align 2, 0
_080A836C: .4byte 0x020380D6
_080A8370: .4byte 0x020380BE
_080A8374:
	ldr r1, _080A83A8
	ldrh r0, [r1]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
_080A837E:
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #0x22]
	adds r0, r0, r2
	strh r0, [r4, #0x22]
	ldrh r0, [r1, #4]
	strh r0, [r4, #0x2e]
	ldrh r0, [r1, #6]
	strh r0, [r4, #0x30]
	ldrh r0, [r1, #8]
	strh r0, [r4, #0x34]
	ldrh r0, [r1, #0xa]
	strh r0, [r4, #0x38]
	ldr r1, _080A83AC
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _080A83B0
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A83A8: .4byte 0x020380BE
_080A83AC: .4byte 0x080A6015
_080A83B0: .4byte 0x080A5FA5
	thumb_func_end sub_080A8334

	thumb_func_start sub_080A83B4
sub_080A83B4: @ 0x080A83B4
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080A83DC
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A83E4
	ldr r2, _080A83E0
	ldrh r0, [r4, #0x20]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4, #0x20]
	movs r1, #6
	ldrsh r0, [r2, r1]
	rsbs r0, r0, #0
	strh r0, [r2, #6]
	adds r1, r2, #0
	b _080A83EE
	.align 2, 0
_080A83DC: .4byte 0x020380D6
_080A83E0: .4byte 0x020380BE
_080A83E4:
	ldr r1, _080A8420
	ldrh r0, [r1]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
_080A83EE:
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #0x22]
	adds r0, r0, r2
	strh r0, [r4, #0x22]
	ldrh r0, [r1, #4]
	strh r0, [r4, #0x2e]
	ldrh r0, [r1, #6]
	strh r0, [r4, #0x30]
	ldrh r0, [r1, #8]
	strh r0, [r4, #0x34]
	ldrh r0, [r1, #0xa]
	strh r0, [r4, #0x38]
	ldrb r1, [r1, #0xc]
	adds r0, r4, #0
	bl StartSpriteAnim
	ldr r1, _080A8424
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	ldr r0, _080A8428
	str r0, [r4, #0x1c]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A8420: .4byte 0x020380BE
_080A8424: .4byte 0x080A6015
_080A8428: .4byte 0x080A5FA5
	thumb_func_end sub_080A83B4

	thumb_func_start sub_080A842C
sub_080A842C: @ 0x080A842C
	push {r4, lr}
	adds r4, r0, #0
	bl SetSpriteCoordsToAnimAttackerCoords
	ldr r0, _080A8450
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A8458
	ldr r0, _080A8454
	ldrh r1, [r4, #0x20]
	ldrh r2, [r0]
	subs r1, r1, r2
	strh r1, [r4, #0x20]
	b _080A8464
	.align 2, 0
_080A8450: .4byte 0x020380D6
_080A8454: .4byte 0x020380BE
_080A8458:
	ldr r1, _080A8480
	ldrh r0, [r1]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
	adds r0, r1, #0
_080A8464:
	ldrh r0, [r0, #2]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x22]
	ldr r0, _080A8484
	str r0, [r4, #0x1c]
	ldr r1, _080A8488
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A8480: .4byte 0x020380BE
_080A8484: .4byte 0x080A60A1
_080A8488: .4byte 0x080A34C5
	thumb_func_end sub_080A842C

	thumb_func_start sub_080A848C
sub_080A848C: @ 0x080A848C
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _080A8520
	adds r5, r1, r0
	movs r0, #0
	bl GetAnimBattlerSpriteId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r6, #0
	strh r0, [r5, #8]
	ldr r7, _080A8524
	ldrb r0, [r7]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	movs r1, #8
	cmp r0, #0
	beq _080A84C0
	movs r0, #8
	rsbs r0, r0, #0
	adds r1, r0, #0
_080A84C0:
	strh r1, [r5, #0xa]
	strh r6, [r5, #0xc]
	strh r6, [r5, #0xe]
	ldr r4, _080A8528
	movs r0, #8
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrh r1, [r0, #0x24]
	ldrh r2, [r5, #8]
	subs r1, r1, r2
	strh r1, [r0, #0x24]
	ldr r0, _080A852C
	bl AllocSpritePalette
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x10]
	strh r6, [r5, #0x12]
	movs r1, #0x10
	ldrsh r0, [r5, r1]
	adds r0, #0x10
	lsls r0, r0, #0x14
	lsrs r6, r0, #0x10
	movs r0, #8
	ldrsh r1, [r5, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r0, [r0, #5]
	lsrs r0, r0, #4
	adds r0, #0x10
	lsls r4, r0, #4
	ldrb r0, [r7]
	bl GetBattlerSpriteSubpriority
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x14]
	cmp r0, #0x14
	beq _080A851C
	cmp r0, #0x28
	bne _080A8530
_080A851C:
	movs r0, #2
	b _080A8532
	.align 2, 0
_080A8520: .4byte 0x03005B60
_080A8524: .4byte 0x020380D6
_080A8528: .4byte 0x020205AC
_080A852C: .4byte 0x00002771
_080A8530:
	movs r0, #3
_080A8532:
	strh r0, [r5, #0x14]
	lsls r0, r4, #1
	ldr r1, _080A8560
	adds r0, r0, r1
	lsls r1, r6, #1
	ldr r2, _080A8564
	adds r1, r1, r2
	ldr r2, _080A8568
	bl CpuSet
	ldr r0, _080A856C
	ldrb r2, [r0, #2]
	ldrh r3, [r0]
	adds r0, r6, #0
	movs r1, #0x10
	bl BlendPalette
	ldr r0, _080A8570
	str r0, [r5]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8560: .4byte 0x020373B4
_080A8564: .4byte 0x020377B4
_080A8568: .4byte 0x04000008
_080A856C: .4byte 0x020380BE
_080A8570: .4byte 0x080A8575
	thumb_func_end sub_080A848C

	thumb_func_start sub_080A8574
sub_080A8574: @ 0x080A8574
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #3
	ldr r1, _080A8598
	adds r4, r0, r1
	movs r1, #0xc
	ldrsh r0, [r4, r1]
	cmp r0, #1
	beq _080A85D8
	cmp r0, #1
	bgt _080A859C
	cmp r0, #0
	beq _080A85A2
	b _080A8634
	.align 2, 0
_080A8598: .4byte 0x03005B60
_080A859C:
	cmp r0, #2
	beq _080A8620
	b _080A8634
_080A85A2:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080A8640
	ldr r2, _080A85D4
	movs r0, #8
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrh r1, [r4, #0xa]
	ldrh r2, [r0, #0x24]
	adds r1, r1, r2
	strh r1, [r0, #0x24]
	ldrh r1, [r4, #0xe]
	adds r0, r1, #1
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #5
	bne _080A8634
	strh r1, [r4, #0xe]
	b _080A8612
	.align 2, 0
_080A85D4: .4byte 0x020205AC
_080A85D8:
	adds r0, r4, #0
	adds r1, r5, #0
	bl sub_080A8640
	ldr r3, _080A861C
	movs r0, #8
	ldrsh r1, [r4, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r1, [r0, #0x24]
	ldrh r2, [r4, #0xa]
	subs r1, r1, r2
	strh r1, [r0, #0x24]
	ldrh r0, [r4, #0xe]
	subs r0, #1
	strh r0, [r4, #0xe]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	cmp r2, #0
	bne _080A8634
	movs r1, #8
	ldrsh r0, [r4, r1]
	lsls r1, r0, #4
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r3
	strh r2, [r1, #0x24]
_080A8612:
	ldrh r0, [r4, #0xc]
	adds r0, #1
	strh r0, [r4, #0xc]
	b _080A8634
	.align 2, 0
_080A861C: .4byte 0x020205AC
_080A8620:
	movs r2, #0x12
	ldrsh r0, [r4, r2]
	cmp r0, #0
	bne _080A8634
	ldr r0, _080A863C
	bl FreeSpritePaletteByTag
	adds r0, r5, #0
	bl DestroyAnimVisualTask
_080A8634:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A863C: .4byte 0x00002771
	thumb_func_end sub_080A8574

	thumb_func_start sub_080A8640
sub_080A8640: @ 0x080A8640
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	movs r0, #0
	bl CloneBattlerSpriteWithBlend
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	blt _080A86B0
	ldr r5, _080A86BC
	lsls r4, r0, #4
	adds r4, r4, r0
	lsls r4, r4, #2
	adds r3, r4, r5
	movs r0, #3
	ldrb r1, [r6, #0x14]
	ands r1, r0
	lsls r1, r1, #2
	ldrb r2, [r3, #5]
	movs r0, #0xd
	rsbs r0, r0, #0
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	ldrb r1, [r6, #0x10]
	lsls r1, r1, #4
	movs r2, #0xf
	ands r0, r2
	orrs r0, r1
	strb r0, [r3, #5]
	movs r0, #8
	strh r0, [r3, #0x2e]
	mov r0, r8
	strh r0, [r3, #0x30]
	strh r7, [r3, #0x32]
	movs r0, #8
	ldrsh r1, [r6, r0]
	lsls r0, r1, #4
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrh r0, [r0, #0x24]
	strh r0, [r3, #0x24]
	adds r5, #0x1c
	adds r4, r4, r5
	ldr r0, _080A86C0
	str r0, [r4]
	ldrh r0, [r6, #0x12]
	adds r0, #1
	strh r0, [r6, #0x12]
_080A86B0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A86BC: .4byte 0x020205AC
_080A86C0: .4byte 0x080A86C5
	thumb_func_end sub_080A8640

	thumb_func_start sub_080A86C4
sub_080A86C4: @ 0x080A86C4
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2e]
	subs r0, #1
	strh r0, [r3, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A86EE
	ldr r2, _080A86F4
	movs r0, #0x30
	ldrsh r1, [r3, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrh r1, [r0, #0x12]
	subs r1, #1
	strh r1, [r0, #0x12]
	adds r0, r3, #0
	bl DestroySpriteWithActiveSheet
_080A86EE:
	pop {r0}
	bx r0
	.align 2, 0
_080A86F4: .4byte 0x03005B60
	thumb_func_end sub_080A86C4

	thumb_func_start sub_080A86F8
sub_080A86F8: @ 0x080A86F8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _080A872C
	ldrb r0, [r4]
	movs r1, #2
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x20]
	ldrb r0, [r4]
	movs r1, #3
	bl GetBattlerSpriteCoord
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	strh r0, [r5, #0x22]
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A8730
	movs r0, #5
	b _080A8732
	.align 2, 0
_080A872C: .4byte 0x020380D6
_080A8730:
	ldr r0, _080A8744
_080A8732:
	strh r0, [r5, #0x2e]
	ldr r0, _080A8748
	strh r0, [r5, #0x30]
	ldr r0, _080A874C
	str r0, [r5, #0x1c]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A8744: .4byte 0x0000FFF6
_080A8748: .4byte 0x0000FFD8
_080A874C: .4byte 0x080A8751
	thumb_func_end sub_080A86F8

	thumb_func_start sub_080A8750
sub_080A8750: @ 0x080A8750
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x32]
	adds r0, r0, r1
	strh r0, [r4, #0x32]
	ldrh r5, [r4, #0x30]
	ldrh r2, [r4, #0x34]
	adds r0, r5, r2
	strh r0, [r4, #0x34]
	movs r1, #0x32
	ldrsh r0, [r4, r1]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4, #0x24]
	movs r2, #0x34
	ldrsh r0, [r4, r2]
	movs r1, #0xa
	bl __divsi3
	strh r0, [r4, #0x26]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x14
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080A878C
	adds r0, r5, #1
	strh r0, [r4, #0x30]
_080A878C:
	movs r1, #0x22
	ldrsh r0, [r4, r1]
	movs r2, #0x26
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	movs r1, #0x20
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080A87A4
	adds r0, r4, #0
	bl DestroyAnimSprite
_080A87A4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_080A8750

	thumb_func_start sub_080A87AC
sub_080A87AC: @ 0x080A87AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _080A87E4
	ldrh r0, [r5, #4]
	strh r0, [r4, #0x2e]
	ldrh r0, [r5, #8]
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x32]
	ldrh r0, [r5, #0xa]
	ldrh r1, [r4, #0x22]
	adds r0, r0, r1
	strh r0, [r4, #0x36]
	ldr r0, _080A87E8
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080A87EC
	ldrh r0, [r5, #8]
	adds r0, #0x1e
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r5, #0xa]
	subs r0, #0x14
	b _080A87FA
	.align 2, 0
_080A87E4: .4byte 0x020380BE
_080A87E8: .4byte 0x020380D7
_080A87EC:
	ldrh r0, [r5, #8]
	subs r0, #0x1e
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldrh r0, [r5, #0xa]
	subs r0, #0x50
_080A87FA:
	strh r0, [r4, #0x22]
	ldr r0, _080A8810
	str r0, [r4, #0x1c]
	ldr r1, _080A8814
	adds r0, r4, #0
	bl StoreSpriteCallbackInData6
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A8810: .4byte 0x080A67B5
_080A8814: .4byte 0x080A34C5
	thumb_func_end sub_080A87AC
