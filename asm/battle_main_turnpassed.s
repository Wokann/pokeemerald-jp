.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleTurnPassed
BattleTurnPassed: @ 0x0803B600
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r0, #1
	bl TurnValuesCleanUp
	ldr r0, _0803B6A4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803B62E
	bl DoFieldEndTurnEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B622
	b _0803B7BC
_0803B622:
	bl BattleScriptPop
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B62E
	b _0803B7BC
_0803B62E:
	bl HandleFaintedMonActions
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0803B63C
	b _0803B7BC
_0803B63C:
	ldr r0, _0803B6A8
	ldr r0, [r0]
	adds r0, #0x4d
	strb r1, [r0]
	bl HandleWishPerishSongOnTurnEnd
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0803B652
	b _0803B7BC
_0803B652:
	movs r0, #0
	bl TurnValuesCleanUp
	ldr r2, _0803B6AC
	ldr r0, [r2]
	ldr r1, _0803B6B0
	ands r0, r1
	ldr r1, _0803B6B4
	ands r0, r1
	ldr r1, _0803B6B8
	ands r0, r1
	ldr r1, _0803B6BC
	ands r0, r1
	str r0, [r2]
	ldr r0, _0803B6C0
	strb r4, [r0, #0x18]
	strb r4, [r0, #0x19]
	strb r4, [r0, #0x14]
	ldr r0, _0803B6C4
	str r4, [r0]
	ldr r0, _0803B6C8
	strb r4, [r0]
	ldr r1, _0803B6CC
	movs r2, #0
	adds r0, r1, #4
_0803B684:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _0803B684
	ldr r0, _0803B6A4
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B6DC
	ldr r1, _0803B6D0
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _0803B6D4
	ldr r0, _0803B6D8
	str r0, [r1]
	b _0803B7BC
	.align 2, 0
_0803B6A4: .4byte 0x02023FDE
_0803B6A8: .4byte 0x02024140
_0803B6AC: .4byte 0x02023F24
_0803B6B0: .4byte 0xFFFFFDFF
_0803B6B4: .4byte 0xFFF7FFFF
_0803B6B8: .4byte 0xFFBFFFFF
_0803B6BC: .4byte 0xFFEFFFFF
_0803B6C0: .4byte 0x02024118
_0803B6C4: .4byte 0x02023E94
_0803B6C8: .4byte 0x02023F20
_0803B6CC: .4byte 0x02023FD6
_0803B6D0: .4byte 0x02023D27
_0803B6D4: .4byte 0x03005A64
_0803B6D8: .4byte 0x0803D45D
_0803B6DC:
	ldr r1, _0803B770
	ldrb r0, [r1, #0x13]
	ldr r2, _0803B774
	mov r8, r2
	cmp r0, #0xfe
	bhi _0803B6F6
	adds r0, #1
	strb r0, [r1, #0x13]
	ldr r1, [r2]
	adds r1, #0xda
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803B6F6:
	movs r2, #0
	ldr r4, _0803B778
	ldr r0, _0803B77C
	mov ip, r0
	ldr r1, _0803B780
	mov sb, r1
	ldrb r0, [r4]
	cmp r2, r0
	bge _0803B724
	ldr r7, _0803B784
	movs r6, #0xff
	movs r5, #0
	ldr r3, _0803B788
_0803B710:
	adds r1, r2, r7
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	strh r5, [r3]
	adds r3, #2
	adds r2, #1
	ldrb r1, [r4]
	cmp r2, r1
	blt _0803B710
_0803B724:
	movs r2, #0
	ldr r3, _0803B774
	movs r1, #6
_0803B72A:
	ldr r0, [r3]
	adds r0, r2, r0
	adds r0, #0x5c
	strb r1, [r0]
	adds r2, #1
	cmp r2, #3
	ble _0803B72A
	mov r2, r8
	ldr r0, [r2]
	adds r0, #0x91
	mov r2, ip
	ldrb r1, [r2]
	strb r1, [r0]
	mov r0, sb
	movs r1, #0
	bl sub_0814FA04
	ldr r1, _0803B78C
	ldr r0, _0803B790
	str r0, [r1]
	bl Random
	ldr r1, _0803B794
	strh r0, [r1]
	ldr r0, _0803B798
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0803B7A0
	ldr r0, _0803B79C
	bl BattleScriptExecute
	b _0803B7BC
	.align 2, 0
_0803B770: .4byte 0x03005A70
_0803B774: .4byte 0x02024140
_0803B778: .4byte 0x02023D10
_0803B77C: .4byte 0x02023EB4
_0803B780: .4byte 0x085AB3BD
_0803B784: .4byte 0x02023EC0
_0803B788: .4byte 0x02023F18
_0803B78C: .4byte 0x03005A64
_0803B790: .4byte 0x0803BAB9
_0803B794: .4byte 0x02023FD4
_0803B798: .4byte 0x02022C90
_0803B79C: .4byte 0x08289E09
_0803B7A0:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	beq _0803B7BC
	mov r1, r8
	ldr r0, [r1]
	adds r0, #0xda
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803B7BC
	ldr r0, _0803B7C8
	bl BattleScriptExecute
_0803B7BC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B7C8: .4byte 0x08289E46
	thumb_func_end BattleTurnPassed
