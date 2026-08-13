.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start TryDoEventsBeforeFirstTurn
TryDoEventsBeforeFirstTurn: @ 0x0803B26C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #0
	mov sb, r0
	ldr r0, _0803B2B0
	ldr r0, [r0]
	cmp r0, #0
	beq _0803B286
	b _0803B4F6
_0803B286:
	ldr r0, _0803B2B4
	ldr r0, [r0]
	adds r0, #0x4c
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803B306
	movs r5, #0
	ldr r1, _0803B2B8
	mov sl, r1
	ldrb r3, [r1]
	cmp r5, r3
	bge _0803B2AC
	ldr r2, _0803B2BC
_0803B2A0:
	adds r0, r5, r2
	strb r5, [r0]
	adds r5, #1
	ldrb r0, [r1]
	cmp r5, r0
	blt _0803B2A0
_0803B2AC:
	movs r5, #0
	b _0803B2FC
	.align 2, 0
_0803B2B0: .4byte 0x02023D0C
_0803B2B4: .4byte 0x02024140
_0803B2B8: .4byte 0x02023D10
_0803B2BC: .4byte 0x02023D22
_0803B2C0:
	adds r4, r5, #1
	mov r8, r4
	ldrb r1, [r1]
	cmp r8, r1
	bge _0803B2FA
	ldr r6, _0803B334
	ldr r1, _0803B338
	mov sl, r1
	lsls r7, r5, #0x18
_0803B2D2:
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r1, r4, r6
	ldrb r1, [r1]
	movs r2, #1
	bl GetWhoStrikesFirst
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B2F0
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	lsrs r0, r7, #0x18
	bl SwapTurnOrder
_0803B2F0:
	adds r4, #1
	ldr r0, _0803B338
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803B2D2
_0803B2FA:
	mov r5, r8
_0803B2FC:
	mov r1, sl
	ldrb r0, [r1]
	subs r0, #1
	cmp r5, r0
	blt _0803B2C0
_0803B306:
	ldr r5, _0803B33C
	ldr r0, [r5]
	movs r4, #0xd1
	lsls r4, r4, #1
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803B340
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0xff
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B340
	ldr r0, [r5]
	adds r0, r0, r4
	movs r1, #1
	strb r1, [r0]
	b _0803B4F6
	.align 2, 0
_0803B334: .4byte 0x02023D22
_0803B338: .4byte 0x02023D10
_0803B33C: .4byte 0x02024140
_0803B340:
	ldr r2, _0803B508
	ldr r0, [r2]
	adds r0, #0x4c
	ldr r1, _0803B50C
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _0803B39A
	ldr r5, _0803B510
	adds r4, r2, #0
_0803B354:
	ldr r0, [r4]
	adds r0, #0x4c
	ldrb r0, [r0]
	adds r0, r0, r5
	ldrb r1, [r0]
	movs r0, #0
	str r0, [sp]
	movs r2, #0
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B37A
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_0803B37A:
	ldr r1, [r4]
	adds r1, #0x4c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r3, sb
	cmp r3, #0
	beq _0803B38C
	b _0803B4F6
_0803B38C:
	ldr r0, [r4]
	adds r0, #0x4c
	ldr r1, _0803B50C
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803B354
_0803B39A:
	movs r0, #0
	str r0, [sp]
	movs r0, #9
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _0803B3B4
	b _0803B4F6
_0803B3B4:
	str r0, [sp]
	movs r0, #0xb
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B3CA
	b _0803B4F6
_0803B3CA:
	ldr r2, _0803B508
	ldr r0, [r2]
	adds r0, #0xd9
	ldr r1, _0803B50C
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _0803B41E
	ldr r5, _0803B510
	adds r4, r2, #0
_0803B3DE:
	ldr r0, [r4]
	adds r0, #0xd9
	ldrb r0, [r0]
	adds r0, r0, r5
	ldrb r1, [r0]
	movs r0, #0
	movs r2, #0
	bl ItemBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803B400
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_0803B400:
	ldr r1, [r4]
	adds r1, #0xd9
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r0, sb
	cmp r0, #0
	bne _0803B4F6
	ldr r0, [r4]
	adds r0, #0xd9
	ldr r1, _0803B50C
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803B3DE
_0803B41E:
	movs r5, #0
	ldr r1, _0803B508
	mov r8, r1
	movs r7, #6
	ldr r6, _0803B514
	ldr r2, _0803B518
	movs r4, #0xff
	movs r3, #0
_0803B42E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, r5, r0
	adds r0, #0x5c
	strb r7, [r0]
	adds r1, r5, r6
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	strh r3, [r2]
	adds r2, #2
	adds r5, #1
	cmp r5, #3
	ble _0803B42E
	movs r0, #0
	bl TurnValuesCleanUp
	bl SpecialStatusesClear
	ldr r0, _0803B508
	ldr r0, [r0]
	adds r0, #0x91
	ldr r1, _0803B51C
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r0, _0803B520
	movs r1, #0
	bl sub_0814FA04
	ldr r1, _0803B524
	ldr r0, _0803B528
	str r0, [r1]
	bl ResetSentPokesToOpponentValue
	ldr r1, _0803B52C
	movs r2, #0
	adds r0, r1, #7
_0803B478:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _0803B478
	movs r5, #0
	ldr r3, _0803B50C
	ldr r2, _0803B508
	ldr r6, _0803B530
	ldr r7, _0803B534
	ldrb r0, [r3]
	cmp r5, r0
	bge _0803B4AA
	ldr r0, _0803B538
	movs r4, #9
	rsbs r4, r4, #0
	adds r1, r0, #0
	adds r1, #0x50
_0803B49A:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, #0x58
	adds r5, #1
	ldrb r0, [r3]
	cmp r5, r0
	blt _0803B49A
_0803B4AA:
	ldr r0, [r2]
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	strb r1, [r0, #1]
	ldr r0, [r2]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	ldr r0, [r2]
	adds r3, #1
	adds r0, r0, r3
	strb r1, [r0]
	movs r1, #0
	strb r1, [r6, #0x14]
	ldr r0, [r2]
	adds r0, #0x4d
	strb r1, [r0]
	ldr r0, [r2]
	strb r1, [r0, #3]
	strb r1, [r7]
	bl Random
	ldr r1, _0803B53C
	strh r0, [r1]
	ldr r0, _0803B540
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0803B4F6
	bl StopCryAndClearCrySongs
	ldr r0, _0803B544
	bl BattleScriptExecute
_0803B4F6:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803B508: .4byte 0x02024140
_0803B50C: .4byte 0x02023D10
_0803B510: .4byte 0x02023D22
_0803B514: .4byte 0x02023EC0
_0803B518: .4byte 0x02023F18
_0803B51C: .4byte 0x02023EB4
_0803B520: .4byte 0x085AB3BD
_0803B524: .4byte 0x03005A64
_0803B528: .4byte 0x0803BAB9
_0803B52C: .4byte 0x02023FD6
_0803B530: .4byte 0x02024118
_0803B534: .4byte 0x02023F20
_0803B538: .4byte 0x02023D28
_0803B53C: .4byte 0x02023FD4
_0803B540: .4byte 0x02022C90
_0803B544: .4byte 0x08289E46
	thumb_func_end TryDoEventsBeforeFirstTurn
