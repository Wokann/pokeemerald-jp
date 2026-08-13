.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start FaintClearSetData
FaintClearSetData: @ 0x0803A3A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r5, #0
	ldr r6, _0803A764
	ldr r0, _0803A768
	mov r8, r0
	ldr r1, _0803A76C
	mov ip, r1
	ldr r2, _0803A770
	mov sb, r2
	ldr r3, _0803A774
	mov sl, r3
	ldr r7, _0803A778
	ldr r4, _0803A77C
	movs r3, #0x58
	adds r2, r6, #0
	adds r2, #0x18
	movs r1, #6
_0803A3CC:
	ldrb r0, [r4]
	muls r0, r3, r0
	adds r0, r5, r0
	adds r0, r0, r2
	strb r1, [r0]
	adds r5, #1
	cmp r5, #7
	ble _0803A3CC
	ldr r0, _0803A77C
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r2, r6, #0
	adds r2, #0x50
	adds r0, r0, r2
	movs r1, #0
	str r1, [r0]
	ldr r3, _0803A77C
	ldrb r0, [r3]
	lsls r0, r0, #2
	add r0, r8
	str r1, [r0]
	movs r5, #0
	ldr r6, _0803A780
	ldrb r6, [r6]
	cmp r5, r6
	bge _0803A474
	adds r3, r2, #0
	movs r4, #0
	ldr r0, _0803A784
	mov r8, r0
_0803A40A:
	ldr r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #0x13
	ands r0, r1
	cmp r0, #0
	beq _0803A42A
	ldr r2, _0803A788
	adds r0, r4, r2
	ldrb r0, [r0, #0x14]
	ldr r6, _0803A77C
	ldrb r6, [r6]
	cmp r0, r6
	bne _0803A42A
	ldr r0, _0803A78C
	ands r1, r0
	str r1, [r3]
_0803A42A:
	ldr r1, _0803A77C
	ldrb r0, [r1]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	lsls r2, r0, #0x10
	ldr r1, [r3]
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _0803A444
	bics r1, r2
	str r1, [r3]
_0803A444:
	ldr r1, [r3]
	movs r0, #0xe0
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0803A466
	mov r2, ip
	ldr r0, [r2]
	adds r0, r5, r0
	ldrb r0, [r0, #0x14]
	ldr r6, _0803A77C
	ldrb r6, [r6]
	cmp r0, r6
	bne _0803A466
	ldr r0, _0803A790
	ands r1, r0
	str r1, [r3]
_0803A466:
	adds r3, #0x58
	adds r4, #0x1c
	adds r5, #1
	ldr r0, _0803A780
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803A40A
_0803A474:
	ldr r1, _0803A77C
	ldrb r0, [r1]
	add r0, sb
	movs r1, #0
	strb r1, [r0]
	ldr r2, _0803A77C
	ldrb r0, [r2]
	add r0, sl
	strb r1, [r0]
	ldrb r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r3, _0803A788
	adds r1, r0, r3
	movs r5, #0
	movs r2, #0
_0803A496:
	adds r0, r1, r5
	strb r2, [r0]
	adds r5, #1
	cmp r5, #0x1b
	bls _0803A496
	ldr r6, _0803A77C
	ldrb r1, [r6]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	mov sb, r0
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r6]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1]
	movs r3, #3
	rsbs r3, r3, #0
	mov r8, r3
	mov r0, r8
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r6]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1]
	movs r6, #5
	rsbs r6, r6, #0
	adds r0, r6, #0
	ands r0, r2
	strb r0, [r1]
	ldr r0, _0803A77C
	ldrb r1, [r0]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1]
	subs r3, #6
	mov sl, r3
	mov r0, sl
	ands r0, r2
	strb r0, [r1]
	ldr r0, _0803A77C
	ldrb r1, [r0]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldr r2, _0803A77C
	ldrb r1, [r2]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1]
	movs r5, #0x21
	rsbs r5, r5, #0
	adds r0, r5, #0
	ands r0, r2
	strb r0, [r1]
	ldr r3, _0803A77C
	ldrb r1, [r3]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1]
	movs r4, #0x41
	rsbs r4, r4, #0
	adds r0, r4, #0
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r3]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1]
	movs r3, #0x7f
	adds r0, r3, #0
	ands r0, r2
	strb r0, [r1]
	ldr r0, _0803A77C
	ldrb r1, [r0]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1, #1]
	mov r0, sb
	ands r0, r2
	strb r0, [r1, #1]
	ldr r2, _0803A77C
	ldrb r1, [r2]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1, #1]
	mov r0, r8
	ands r0, r2
	strb r0, [r1, #1]
	ldr r0, _0803A77C
	ldrb r1, [r0]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1, #1]
	adds r0, r6, #0
	ands r0, r2
	strb r0, [r1, #1]
	ldr r2, _0803A77C
	ldrb r1, [r2]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1, #1]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #1]
	ldr r1, _0803A77C
	ldrb r0, [r1]
	lsls r0, r0, #4
	adds r0, r0, r7
	ldrb r1, [r0, #1]
	ands r5, r1
	strb r5, [r0, #1]
	ldr r2, _0803A77C
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, r0, r7
	ldrb r1, [r0, #1]
	ands r4, r1
	strb r4, [r0, #1]
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, r0, r7
	ldrb r1, [r0, #1]
	ands r3, r1
	strb r3, [r0, #1]
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, r0, r7
	ldrb r1, [r0, #2]
	mov r3, sb
	ands r3, r1
	strb r3, [r0, #2]
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r0, r0, r7
	ldrb r1, [r0, #2]
	mov r2, r8
	ands r2, r1
	strb r2, [r0, #2]
	ldr r3, _0803A77C
	ldrb r0, [r3]
	lsls r0, r0, #4
	adds r0, r0, r7
	ldrb r1, [r0, #2]
	ands r6, r1
	strb r6, [r0, #2]
	ldrb r0, [r3]
	lsls r0, r0, #4
	adds r0, r0, r7
	ldrb r1, [r0, #2]
	mov r6, sl
	ands r6, r1
	strb r6, [r0, #2]
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _0803A788
	adds r0, r0, r1
	movs r2, #0
	movs r1, #2
	strb r1, [r0, #0x16]
	ldrb r0, [r3]
	lsls r0, r0, #1
	ldr r3, _0803A794
	adds r0, r0, r3
	movs r3, #0
	strh r2, [r0]
	ldr r6, _0803A77C
	ldrb r0, [r6]
	lsls r0, r0, #1
	ldr r1, _0803A798
	adds r0, r0, r1
	strh r2, [r0]
	ldrb r0, [r6]
	lsls r0, r0, #1
	ldr r6, _0803A79C
	adds r0, r0, r6
	strh r2, [r0]
	ldr r1, _0803A77C
	ldrb r0, [r1]
	lsls r0, r0, #1
	ldr r6, _0803A7A0
	adds r0, r0, r6
	strh r2, [r0]
	ldrb r0, [r1]
	lsls r0, r0, #1
	ldr r1, _0803A7A4
	adds r0, r0, r1
	strh r2, [r0]
	ldr r2, _0803A77C
	ldrb r0, [r2]
	ldr r6, _0803A7A8
	adds r0, r0, r6
	movs r1, #0xff
	strb r1, [r0]
	ldrb r0, [r2]
	mov r2, ip
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc8
	strb r3, [r0]
	ldr r6, _0803A77C
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc9
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x98
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0x99
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe0
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe1
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe2
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe3
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe4
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe5
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe6
	strb r3, [r0]
	ldrb r0, [r6]
	ldr r1, [r2]
	lsls r0, r0, #3
	adds r0, r0, r1
	adds r0, #0xe7
	strb r3, [r0]
	ldr r1, [r2]
	adds r1, #0x92
	ldrb r0, [r6]
	lsls r0, r0, #2
	ldr r2, _0803A784
	adds r0, r0, r2
	ldr r2, [r0]
	ldrb r0, [r1]
	bics r0, r2
	strb r0, [r1]
	movs r5, #0
	ldr r3, _0803A780
	ldrb r3, [r3]
	cmp r5, r3
	bge _0803A746
	adds r3, r6, #0
	mov r7, ip
	movs r6, #0
_0803A6E8:
	ldrb r0, [r3]
	cmp r5, r0
	beq _0803A71E
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	str r3, [sp]
	bl GetBattlerSide
	adds r4, r0, #0
	ldr r3, [sp]
	ldrb r0, [r3]
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	ldr r3, [sp]
	cmp r4, r0
	beq _0803A71E
	ldr r0, [r7]
	lsls r1, r5, #1
	adds r0, r1, r0
	adds r0, #0x98
	strb r6, [r0]
	ldr r0, [r7]
	adds r1, r1, r0
	adds r1, #0x99
	strb r6, [r1]
_0803A71E:
	ldrb r0, [r3]
	ldr r1, [r7]
	lsls r0, r0, #1
	lsls r2, r5, #3
	adds r0, r0, r2
	adds r0, r0, r1
	adds r0, #0xe0
	strb r6, [r0]
	ldrb r0, [r3]
	ldr r1, [r7]
	lsls r0, r0, #1
	adds r0, r0, r2
	adds r0, r0, r1
	adds r0, #0xe1
	strb r6, [r0]
	adds r5, #1
	ldr r0, _0803A780
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803A6E8
_0803A746:
	ldr r0, _0803A7AC
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r2, _0803A77C
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r1, r1, r0
	movs r0, #0
	str r0, [r1]
	ldr r4, _0803A764
	ldrb r0, [r2]
	movs r3, #0x58
	adds r2, r0, #0
	muls r2, r3, r2
	b _0803A7B0
	.align 2, 0
_0803A764: .4byte 0x02023D28
_0803A768: .4byte 0x02023F50
_0803A76C: .4byte 0x02024140
_0803A770: .4byte 0x02024150
_0803A774: .4byte 0x02024154
_0803A778: .4byte 0x02023FE0
_0803A77C: .4byte 0x02023D08
_0803A780: .4byte 0x02023D10
_0803A784: .4byte 0x082FACB4
_0803A788: .4byte 0x02023F60
_0803A78C: .4byte 0xFBFFFFFF
_0803A790: .4byte 0xFFFF1FFF
_0803A794: .4byte 0x02023EEC
_0803A798: .4byte 0x02023EF4
_0803A79C: .4byte 0x02023EFC
_0803A7A0: .4byte 0x02023F04
_0803A7A4: .4byte 0x02023EE4
_0803A7A8: .4byte 0x02023F14
_0803A7AC: .4byte 0x0202414C
_0803A7B0:
	adds r2, r2, r4
	ldr r5, _0803A7FC
	ldrh r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrb r0, [r0, #6]
	adds r2, #0x21
	strb r0, [r2]
	ldr r6, _0803A800
	ldrb r0, [r6]
	adds r1, r0, #0
	muls r1, r3, r1
	adds r1, r1, r4
	ldrh r2, [r1]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrb r0, [r0, #7]
	adds r1, #0x22
	strb r0, [r1]
	ldrb r0, [r6]
	bl ClearBattlerMoveHistory
	ldrb r0, [r6]
	bl ClearBattlerAbilityHistory
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803A7FC: .4byte 0x082F0D54
_0803A800: .4byte 0x02023D08
	thumb_func_end FaintClearSetData
