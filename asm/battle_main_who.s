.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start GetWhoStrikesFirst
GetWhoStrikesFirst: @ 0x0803CB54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803CC1C
	ldr r1, [sp, #8]
	str r1, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0x4d
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803CC1C
	ldr r1, _0803CBD4
	movs r0, #0x58
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r3, [r0]
	cmp r3, #0x21
	bne _0803CBC0
	ldr r0, _0803CBD8
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0803CBD0
_0803CBC0:
	cmp r3, #0x22
	bne _0803CBDC
	ldr r0, _0803CBD8
	ldrh r1, [r0]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	beq _0803CBDC
_0803CBD0:
	movs r3, #2
	b _0803CBDE
	.align 2, 0
_0803CBD4: .4byte 0x02023D28
_0803CBD8: .4byte 0x02024070
_0803CBDC:
	movs r3, #1
_0803CBDE:
	movs r0, #0x58
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r2, _0803CC14
	adds r0, r0, r2
	adds r0, #0x20
	ldrb r2, [r0]
	cmp r2, #0x21
	bne _0803CBFE
	ldr r0, _0803CC18
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0803CC0E
_0803CBFE:
	cmp r2, #0x22
	bne _0803CC1E
	ldr r0, _0803CC18
	ldrh r1, [r0]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	beq _0803CC1E
_0803CC0E:
	movs r7, #2
	b _0803CC20
	.align 2, 0
_0803CC14: .4byte 0x02023D28
_0803CC18: .4byte 0x02024070
_0803CC1C:
	movs r3, #1
_0803CC1E:
	movs r7, #1
_0803CC20:
	ldr r1, _0803CC64
	movs r0, #0x58
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	adds r4, r0, r1
	ldrh r0, [r4, #6]
	muls r3, r0, r3
	ldr r2, _0803CC68
	movs r1, #0x1b
	ldrsb r1, [r4, r1]
	lsls r1, r1, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	muls r0, r3, r0
	adds r2, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	bl __divsi3
	mov r8, r0
	ldrh r0, [r4, #0x2e]
	cmp r0, #0xaf
	bne _0803CC70
	ldr r1, _0803CC6C
	mov r3, sb
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r6, [r0, #7]
	ldrb r5, [r0, #0x1a]
	b _0803CC84
	.align 2, 0
_0803CC64: .4byte 0x02023D28
_0803CC68: .4byte 0x082FA6B6
_0803CC6C: .4byte 0x020240A8
_0803CC70:
	ldrh r0, [r4, #0x2e]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #0x2e]
	bl sub_080D6D1C
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0803CC84:
	ldr r0, _0803CD40
	ldr r0, [r0]
	ldr r1, _0803CD44
	ands r0, r1
	cmp r0, #0
	bne _0803CCB8
	ldr r0, _0803CD48
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803CCB8
	mov r0, sb
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803CCB8
	movs r0, #0x6e
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	movs r1, #0x64
	bl __udivsi3
	mov r8, r0
_0803CCB8:
	cmp r6, #0x18
	bne _0803CCC2
	mov r2, r8
	lsrs r2, r2, #1
	mov r8, r2
_0803CCC2:
	ldr r1, _0803CD4C
	movs r0, #0x58
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803CCE0
	mov r0, r8
	lsrs r0, r0, #2
	mov r8, r0
_0803CCE0:
	cmp r6, #0x1a
	bne _0803CCFC
	ldr r0, _0803CD50
	ldrh r4, [r0]
	lsls r0, r5, #0x10
	subs r0, r0, r5
	movs r1, #0x64
	bl __divsi3
	cmp r4, r0
	bge _0803CCFC
	movs r1, #1
	rsbs r1, r1, #0
	mov r8, r1
_0803CCFC:
	ldr r1, _0803CD4C
	movs r0, #0x58
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	adds r4, r0, r1
	ldrh r0, [r4, #6]
	adds r3, r0, #0
	muls r3, r7, r3
	ldr r2, _0803CD54
	movs r1, #0x1b
	ldrsb r1, [r4, r1]
	lsls r1, r1, #1
	adds r0, r1, r2
	ldrb r0, [r0]
	muls r0, r3, r0
	adds r2, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	bl __divsi3
	adds r7, r0, #0
	ldrh r0, [r4, #0x2e]
	cmp r0, #0xaf
	bne _0803CD5C
	ldr r1, _0803CD58
	mov r3, sl
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r6, [r0, #7]
	ldrb r5, [r0, #0x1a]
	b _0803CD70
	.align 2, 0
_0803CD40: .4byte 0x02022C90
_0803CD44: .4byte 0x023F0102
_0803CD48: .4byte 0x00000869
_0803CD4C: .4byte 0x02023D28
_0803CD50: .4byte 0x02023FD4
_0803CD54: .4byte 0x082FA6B6
_0803CD58: .4byte 0x020240A8
_0803CD5C:
	ldrh r0, [r4, #0x2e]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldrh r0, [r4, #0x2e]
	bl sub_080D6D1C
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0803CD70:
	ldr r0, _0803CDE8
	ldr r0, [r0]
	ldr r1, _0803CDEC
	ands r0, r1
	cmp r0, #0
	bne _0803CDA0
	ldr r0, _0803CDF0
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803CDA0
	mov r0, sl
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803CDA0
	movs r0, #0x6e
	muls r0, r7, r0
	movs r1, #0x64
	bl __udivsi3
	adds r7, r0, #0
_0803CDA0:
	cmp r6, #0x18
	bne _0803CDA6
	lsrs r7, r7, #1
_0803CDA6:
	ldr r2, _0803CDF4
	movs r0, #0x58
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803CDC2
	lsrs r7, r7, #2
_0803CDC2:
	cmp r6, #0x1a
	bne _0803CDDC
	ldr r0, _0803CDF8
	ldrh r4, [r0]
	lsls r0, r5, #0x10
	subs r0, r0, r5
	movs r1, #0x64
	bl __divsi3
	cmp r4, r0
	bge _0803CDDC
	movs r7, #1
	rsbs r7, r7, #0
_0803CDDC:
	ldr r2, [sp, #4]
	cmp r2, #0
	beq _0803CDFC
	movs r3, #0
	b _0803CE98
	.align 2, 0
_0803CDE8: .4byte 0x02022C90
_0803CDEC: .4byte 0x023F0102
_0803CDF0: .4byte 0x00000869
_0803CDF4: .4byte 0x02023D28
_0803CDF8: .4byte 0x02023FD4
_0803CDFC:
	ldr r0, _0803CE1C
	mov r3, sb
	adds r1, r3, r0
	ldrb r1, [r1]
	adds r2, r0, #0
	cmp r1, #0
	bne _0803CE4C
	ldr r0, _0803CE20
	lsls r1, r3, #4
	adds r1, r1, r0
	ldrb r0, [r1]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _0803CE24
	movs r3, #0xa5
	b _0803CE4E
	.align 2, 0
_0803CE1C: .4byte 0x02023EC0
_0803CE20: .4byte 0x02023FE0
_0803CE24:
	ldr r0, _0803CE44
	ldr r0, [r0]
	add r0, sb
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r1, #0x58
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	ldr r1, _0803CE48
	adds r1, #0xc
	adds r0, r0, r1
	ldrh r3, [r0]
	b _0803CE4E
	.align 2, 0
_0803CE44: .4byte 0x02024140
_0803CE48: .4byte 0x02023D28
_0803CE4C:
	movs r3, #0
_0803CE4E:
	mov r1, sl
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803CE98
	ldr r0, _0803CE6C
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1]
	lsls r0, r0, #0x1d
	cmp r0, #0
	bge _0803CE70
	movs r2, #0xa5
	b _0803CE9A
	.align 2, 0
_0803CE6C: .4byte 0x02023FE0
_0803CE70:
	ldr r0, _0803CE90
	ldr r0, [r0]
	add r0, sl
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r1, #0x58
	mov r2, sl
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	ldr r1, _0803CE94
	adds r1, #0xc
	adds r0, r0, r1
	ldrh r2, [r0]
	b _0803CE9A
	.align 2, 0
_0803CE90: .4byte 0x02024140
_0803CE94: .4byte 0x02023D28
_0803CE98:
	movs r2, #0
_0803CE9A:
	ldr r4, _0803CEE4
	lsls r0, r3, #1
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #7
	ldrsb r1, [r0, r1]
	lsls r3, r2, #1
	cmp r1, #0
	bne _0803CEBE
	adds r0, r3, r2
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r0, [r0, #7]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _0803CEFC
_0803CEBE:
	adds r0, r3, r2
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r0, [r0, #7]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _0803CEF2
	cmp r8, r7
	bne _0803CEE8
	bl Random
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0803CEE8
	movs r3, #2
	b _0803CF18
	.align 2, 0
_0803CEE4: .4byte 0x082ED220
_0803CEE8:
	cmp r8, r7
	bhs _0803CF1A
	movs r0, #1
	str r0, [sp, #8]
	b _0803CF1A
_0803CEF2:
	cmp r1, r0
	bge _0803CF1A
	movs r1, #1
	str r1, [sp, #8]
	b _0803CF1A
_0803CEFC:
	cmp r8, r7
	bne _0803CF12
	bl Random
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0803CF12
	movs r2, #2
	str r2, [sp, #8]
	b _0803CF1A
_0803CF12:
	cmp r8, r7
	bhs _0803CF1A
	movs r3, #1
_0803CF18:
	str r3, [sp, #8]
_0803CF1A:
	ldr r0, [sp, #8]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end GetWhoStrikesFirst
