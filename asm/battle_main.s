.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified























	thumb_func_start HandleEndTurn_ContinueBattle
HandleEndTurn_ContinueBattle: @ 0x0803B548
	push {r4, r5, r6, lr}
	ldr r0, _0803B5E0
	ldr r0, [r0]
	cmp r0, #0
	bne _0803B5D8
	ldr r1, _0803B5E4
	ldr r0, _0803B5E8
	str r0, [r1]
	ldr r3, _0803B5EC
	ldr r1, _0803B5F0
	movs r2, #0
	adds r0, r1, #7
_0803B560:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _0803B560
	movs r4, #0
	ldrb r3, [r3]
	cmp r4, r3
	bge _0803B5B2
	ldr r5, _0803B5F4
	adds r6, r5, #0
	adds r6, #0x4c
_0803B576:
	movs r0, #0x58
	adds r2, r4, #0
	muls r2, r0, r2
	adds r1, r5, #0
	adds r1, #0x50
	adds r1, r2, r1
	ldr r3, [r1]
	subs r0, #0x61
	ands r3, r0
	str r3, [r1]
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0803B5A8
	movs r0, #0x80
	lsls r0, r0, #5
	ands r3, r0
	cmp r3, #0
	beq _0803B5A8
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl CancelMultiTurnMoves
_0803B5A8:
	adds r4, #1
	ldr r0, _0803B5EC
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803B576
_0803B5B2:
	ldr r2, _0803B5F8
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
	ldr r0, [r2]
	strb r1, [r0, #3]
	ldr r0, _0803B5FC
	strb r1, [r0]
_0803B5D8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803B5E0: .4byte 0x02023D0C
_0803B5E4: .4byte 0x03005A64
_0803B5E8: .4byte 0x0803B601
_0803B5EC: .4byte 0x02023D10
_0803B5F0: .4byte 0x02023FD6
_0803B5F4: .4byte 0x02023D28
_0803B5F8: .4byte 0x02024140
_0803B5FC: .4byte 0x02023F20
	thumb_func_end HandleEndTurn_ContinueBattle

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

	thumb_func_start IsRunningFromBattleImpossible
IsRunningFromBattleImpossible: @ 0x0803B7CC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r1, _0803B7F0
	ldr r0, _0803B7F4
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, r0, r1
	ldrh r0, [r1, #0x2e]
	cmp r0, #0xaf
	bne _0803B7FC
	ldr r1, _0803B7F8
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0, #7]
	b _0803B806
	.align 2, 0
_0803B7F0: .4byte 0x02023D28
_0803B7F4: .4byte 0x02023D08
_0803B7F8: .4byte 0x020240A8
_0803B7FC:
	ldrh r0, [r1, #0x2e]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_0803B806:
	ldr r1, _0803B91C
	ldr r3, _0803B920
	ldrb r0, [r3]
	strb r0, [r1]
	cmp r2, #0x25
	bne _0803B814
	b _0803B990
_0803B814:
	ldr r0, _0803B924
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0803B822
	b _0803B990
_0803B822:
	ldr r1, _0803B928
	ldrb r2, [r3]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x32
	bne _0803B836
	b _0803B990
_0803B836:
	adds r0, r2, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r5, #0
	ldr r0, _0803B92C
	ldrb r0, [r0]
	cmp r5, r0
	bge _0803B8CA
	movs r7, #0
_0803B84C:
	lsrs r4, r7, #0x18
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r0
	beq _0803B870
	ldr r1, _0803B928
	movs r0, #0x58
	muls r0, r5, r0
	adds r0, r0, r1
	adds r2, r0, #0
	adds r2, #0x20
	ldrb r0, [r2]
	cmp r0, #0x17
	bne _0803B870
	b _0803B998
_0803B870:
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r0
	beq _0803B8BA
	ldr r3, _0803B928
	ldr r0, _0803B920
	ldrb r0, [r0]
	movs r2, #0x58
	muls r0, r2, r0
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x1a
	beq _0803B8BA
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803B8BA
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803B8BA
	adds r0, r5, #0
	muls r0, r2, r0
	adds r0, r0, r3
	adds r2, r0, #0
	adds r2, #0x20
	ldrb r0, [r2]
	cmp r0, #0x47
	bne _0803B8BA
	b _0803B9B4
_0803B8BA:
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r7, r7, r0
	adds r5, #1
	ldr r0, _0803B92C
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803B84C
_0803B8CA:
	ldr r4, _0803B920
	ldrb r1, [r4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0xf
	movs r2, #0x2a
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _0803B93C
	ldr r6, _0803B928
	ldrb r0, [r4]
	movs r3, #0x58
	muls r0, r3, r0
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #8
	beq _0803B902
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #8
	bne _0803B93C
_0803B902:
	ldr r0, _0803B930
	subs r1, r5, #1
	strb r1, [r0, #0x17]
	ldr r2, _0803B934
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r0, r6
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r1, _0803B938
	movs r0, #2
	b _0803B9D4
	.align 2, 0
_0803B91C: .4byte 0x02023EB3
_0803B920: .4byte 0x02023D08
_0803B924: .4byte 0x02022C90
_0803B928: .4byte 0x02023D28
_0803B92C: .4byte 0x02023D10
_0803B930: .4byte 0x02024118
_0803B934: .4byte 0x02023EAE
_0803B938: .4byte 0x02023FD6
_0803B93C:
	ldr r1, _0803B970
	ldr r0, _0803B974
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0803B978
	ands r0, r1
	cmp r0, #0
	bne _0803B966
	ldr r1, _0803B97C
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0803B984
_0803B966:
	ldr r1, _0803B980
	movs r0, #0
	strb r0, [r1, #5]
	movs r0, #1
	b _0803B9D6
	.align 2, 0
_0803B970: .4byte 0x02023D28
_0803B974: .4byte 0x02023D08
_0803B978: .4byte 0x0400E000
_0803B97C: .4byte 0x02023F50
_0803B980: .4byte 0x02023FD6
_0803B984:
	ldr r0, _0803B994
	ldr r0, [r0]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0803B9D0
_0803B990:
	movs r0, #0
	b _0803B9D6
	.align 2, 0
_0803B994: .4byte 0x02022C90
_0803B998:
	ldr r0, _0803B9A8
	strb r5, [r0, #0x17]
	ldr r1, _0803B9AC
	ldrb r0, [r2]
	strb r0, [r1]
	ldr r1, _0803B9B0
	movs r0, #2
	b _0803B9D4
	.align 2, 0
_0803B9A8: .4byte 0x02024118
_0803B9AC: .4byte 0x02023EAE
_0803B9B0: .4byte 0x02023FD6
_0803B9B4:
	ldr r0, _0803B9C4
	strb r5, [r0, #0x17]
	ldr r1, _0803B9C8
	ldrb r0, [r2]
	strb r0, [r1]
	ldr r1, _0803B9CC
	movs r0, #2
	b _0803B9D4
	.align 2, 0
_0803B9C4: .4byte 0x02024118
_0803B9C8: .4byte 0x02023EAE
_0803B9CC: .4byte 0x02023FD6
_0803B9D0:
	ldr r1, _0803B9E0
	movs r0, #1
_0803B9D4:
	strb r0, [r1, #5]
_0803B9D6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803B9E0: .4byte 0x02023FD6
	thumb_func_end IsRunningFromBattleImpossible

	thumb_func_start sub_0803B9E4
sub_0803B9E4: @ 0x0803B9E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r3, #0
	ldr r0, _0803BA80
	mov r8, r0
	ldr r1, _0803BA84
	mov ip, r1
	ldr r7, _0803BA88
	lsls r0, r5, #1
	adds r4, r0, r5
	adds r6, r0, #0
_0803BA00:
	mov r0, ip
	adds r2, r3, r0
	ldr r1, [r7]
	adds r0, r4, r3
	adds r0, r0, r1
	adds r0, #0x60
	ldrb r0, [r0]
	strb r0, [r2]
	adds r3, #1
	cmp r3, #2
	ble _0803BA00
	mov r1, r8
	adds r0, r6, r1
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r7, _0803BA88
	ldr r0, [r7]
	adds r0, r5, r0
	adds r0, #0x5c
	ldrb r0, [r0]
	bl pokemon_order_func
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r0, r4, #0
	bl sub_081B8C50
	ldr r0, _0803BA8C
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0803BA90
	movs r3, #0
	adds r4, r7, #0
	adds r6, r6, r5
	movs r0, #2
	adds r1, r5, #0
	eors r1, r0
	ldr r7, _0803BA84
	lsls r0, r1, #1
	adds r5, r0, r1
_0803BA5E:
	ldr r0, [r4]
	adds r1, r6, r3
	adds r1, r1, r0
	adds r1, #0x60
	adds r2, r3, r7
	ldrb r0, [r2]
	strb r0, [r1]
	ldr r1, [r4]
	adds r0, r5, r3
	adds r0, r0, r1
	adds r0, #0x60
	ldrb r1, [r2]
	strb r1, [r0]
	adds r3, #1
	cmp r3, #2
	ble _0803BA5E
	b _0803BAAA
	.align 2, 0
_0803BA80: .4byte 0x02023D12
_0803BA84: .4byte 0x0203CBCC
_0803BA88: .4byte 0x02024140
_0803BA8C: .4byte 0x02022C90
_0803BA90:
	movs r3, #0
	adds r2, r6, r5
	ldr r4, _0803BAB4
_0803BA96:
	ldr r0, [r7]
	adds r1, r2, r3
	adds r1, r1, r0
	adds r1, #0x60
	adds r0, r3, r4
	ldrb r0, [r0]
	strb r0, [r1]
	adds r3, #1
	cmp r3, #2
	ble _0803BA96
_0803BAAA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803BAB4: .4byte 0x0203CBCC
	thumb_func_end sub_0803B9E4

	thumb_func_start HandleAction_TryFinish
HandleAction_TryFinish: @ 0x0803BAB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _0803BAD4
	movs r1, #0
	strb r1, [r0, #4]
	ldr r0, _0803BAD8
	strb r1, [r0]
	ldr r0, _0803BADC
	bl _0803C956
	.align 2, 0
_0803BAD4: .4byte 0x02023FD6
_0803BAD8: .4byte 0x02023D08
_0803BADC: .4byte 0x02023D10
	thumb_func_end HandleAction_TryFinish

	thumb_func_start HandleTurnActionSelectionState
HandleTurnActionSelectionState: @ 0x0803BAE0
	ldr r4, _0803BB08
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _0803BB0C
	ldrb r0, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #8
	bls _0803BAFC
	bl _0803C948
_0803BAFC:
	lsls r0, r0, #2
	ldr r1, _0803BB10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803BB08: .4byte 0x02023D08
_0803BB0C: .4byte 0x02023FD6
_0803BB10: .4byte 0x0803BB14
_0803BB14: @ jump table
	.4byte _0803BB38 @ case 0
	.4byte _0803BB50 @ case 1
	.4byte _0803BC70 @ case 2
	.4byte _0803C41C @ case 3
	.4byte _0803C714 @ case 4
	.4byte _0803C7C8 @ case 5
	.4byte _0803C80C @ case 6
	.4byte _0803C838 @ case 7
	.4byte _0803C87C @ case 8
_0803BB38:
	bl RecordedBattle_CopyBattlerMoves
	ldr r1, _0803BB48
	ldr r0, _0803BB4C
	ldrb r0, [r0]
	adds r0, r0, r1
	bl _0803C864
	.align 2, 0
_0803BB48: .4byte 0x02023FD6
_0803BB4C: .4byte 0x02023D08
_0803BB50:
	ldr r0, _0803BBE8
	ldrb r1, [r0]
	ldr r4, _0803BBEC
	ldr r0, [r4]
	adds r1, r1, r0
	adds r1, #0x5c
	movs r0, #6
	strb r0, [r1]
	ldr r0, _0803BBF0
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0803BBAC
	movs r1, #2
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq _0803BBAC
	eors r5, r1
	adds r0, r5, #0
	bl GetBattlerAtPosition
	ldr r1, [r4]
	adds r1, #0x91
	ldrb r1, [r1]
	ldr r2, _0803BBF4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _0803BBAC
	ldr r4, _0803BBF8
	adds r0, r5, #0
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	beq _0803BBAC
	bl _0803C948
_0803BBAC:
	ldr r0, _0803BBEC
	ldr r0, [r0]
	adds r0, #0x91
	ldrb r3, [r0]
	ldr r1, _0803BBF4
	ldr r4, _0803BBE8
	ldrb r2, [r4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r3, r0
	cmp r3, #0
	beq _0803BC14
	ldr r0, _0803BBFC
	adds r0, r2, r0
	movs r1, #0xd
	strb r1, [r0]
	ldr r0, _0803BBF0
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0803BC00
	ldr r0, _0803BBF8
	ldrb r1, [r4]
	adds r1, r1, r0
	movs r0, #5
	strb r0, [r1]
	bl _0803C948
	.align 2, 0
_0803BBE8: .4byte 0x02023D08
_0803BBEC: .4byte 0x02024140
_0803BBF0: .4byte 0x02022C90
_0803BBF4: .4byte 0x082FACB4
_0803BBF8: .4byte 0x02023FD6
_0803BBFC: .4byte 0x02023EC0
_0803BC00:
	ldr r0, _0803BC10
	ldrb r1, [r4]
	adds r1, r1, r0
	movs r0, #4
	strb r0, [r1]
	bl _0803C948
	.align 2, 0
_0803BC10: .4byte 0x02023FD6
_0803BC14:
	ldr r1, _0803BC44
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	bne _0803BC34
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r1, r0
	cmp r1, #0
	beq _0803BC50
_0803BC34:
	ldr r0, _0803BC48
	adds r0, r2, r0
	strb r3, [r0]
	ldr r1, _0803BC4C
	ldrb r0, [r4]
	bl _0803C8B6
	.align 2, 0
_0803BC44: .4byte 0x02023D28
_0803BC48: .4byte 0x02023EC0
_0803BC4C: .4byte 0x02023FD6
_0803BC50:
	ldr r0, _0803BC68
	ldrb r1, [r0]
	ldr r0, _0803BC6C
	ldrb r2, [r0, #1]
	ldrb r0, [r0, #2]
	lsls r0, r0, #8
	orrs r2, r0
	movs r0, #0
	bl BtlController_EmitChooseAction
	bl _0803C7AC
	.align 2, 0
_0803BC68: .4byte 0x02023EC0
_0803BC6C: .4byte 0x02023508
_0803BC70:
	ldr r3, _0803BCD4
	ldr r1, _0803BCD8
	ldr r6, _0803BCDC
	ldrb r5, [r6]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r1, r2, #4
	movs r0, #0xf0
	lsls r0, r0, #0x18
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, #8
	orrs r1, r0
	lsls r2, r2, #0xc
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0803BC9C
	bl _0803C948
_0803BC9C:
	ldr r4, _0803BCE0
	lsls r0, r5, #9
	adds r4, #1
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r0, r5, #0
	bl RecordedBattle_SetBattlerAction
	ldr r1, _0803BCE4
	ldrb r0, [r6]
	adds r1, r0, r1
	lsls r0, r0, #9
	adds r0, r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r6]
	lsls r0, r0, #9
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0xc
	bls _0803BCC8
	b _0803C308
_0803BCC8:
	lsls r0, r0, #2
	ldr r1, _0803BCE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803BCD4: .4byte 0x02023D0C
_0803BCD8: .4byte 0x082FACB4
_0803BCDC: .4byte 0x02023D08
_0803BCE0: .4byte 0x02023508
_0803BCE4: .4byte 0x02023EC0
_0803BCE8: .4byte 0x0803BCEC
_0803BCEC: @ jump table
	.4byte _0803BD20 @ case 0
	.4byte _0803BE74 @ case 1
	.4byte _0803BEAC @ case 2
	.4byte _0803C308 @ case 3
	.4byte _0803C308 @ case 4
	.4byte _0803C084 @ case 5
	.4byte _0803C0D0 @ case 6
	.4byte _0803C308 @ case 7
	.4byte _0803C308 @ case 8
	.4byte _0803C308 @ case 9
	.4byte _0803C308 @ case 10
	.4byte _0803C308 @ case 11
	.4byte _0803C0F8 @ case 12
_0803BD20:
	bl AreAllMovesUnusable
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803BD78
	ldr r0, _0803BD68
	ldr r3, _0803BD6C
	ldrb r1, [r3]
	adds r1, r1, r0
	movs r4, #0
	movs r0, #6
	strb r0, [r1]
	ldrb r1, [r3]
	ldr r2, _0803BD70
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x54
	strb r4, [r1]
	ldrb r1, [r3]
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x84
	movs r0, #4
	strb r0, [r1]
	ldrb r1, [r3]
	ldr r2, [r2]
	adds r2, r1, r2
	ldr r0, _0803BD74
	lsls r1, r1, #9
	adds r0, #3
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r2, #0xc]
	bl _0803C9B4
	.align 2, 0
_0803BD68: .4byte 0x02023FD6
_0803BD6C: .4byte 0x02023D08
_0803BD70: .4byte 0x02024140
_0803BD74: .4byte 0x02023508
_0803BD78:
	ldr r3, _0803BDB8
	ldr r5, _0803BDBC
	ldrb r4, [r5]
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r2, [r0, #6]
	cmp r2, #0
	beq _0803BDCC
	ldr r1, _0803BDC0
	lsls r0, r4, #1
	adds r0, r0, r1
	strh r2, [r0]
	ldrb r2, [r5]
	ldr r0, _0803BDC4
	ldr r1, [r0]
	adds r1, r2, r1
	adds r1, #0x80
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0, #0xc]
	strb r0, [r1]
	ldr r1, _0803BDC8
	ldrb r0, [r5]
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	bl _0803C9B4
	.align 2, 0
_0803BDB8: .4byte 0x02023F60
_0803BDBC: .4byte 0x02023D08
_0803BDC0: .4byte 0x02023F18
_0803BDC4: .4byte 0x02024140
_0803BDC8: .4byte 0x02023FD6
_0803BDCC:
	add r2, sp, #4
	ldr r3, _0803BE6C
	movs r1, #0x58
	adds r0, r4, #0
	muls r0, r1, r0
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r2, #0x10]
	ldrb r0, [r5]
	muls r0, r1, r0
	adds r0, r0, r3
	adds r0, #0x21
	ldrb r0, [r0]
	strb r0, [r2, #0x12]
	ldrb r0, [r5]
	muls r0, r1, r0
	adds r0, r0, r3
	adds r0, #0x22
	ldrb r0, [r0]
	strb r0, [r2, #0x13]
	movs r4, #0
	mov r1, sp
	adds r1, #0xc
	str r1, [sp, #0x18]
	add r2, sp, #0x10
	mov sl, r2
	mov r8, r3
	adds r7, r5, #0
	movs r6, #0x58
	movs r0, #0xc
	add r0, r8
	mov sb, r0
	add r5, sp, #4
_0803BE0E:
	lsls r2, r4, #1
	ldrb r0, [r7]
	muls r0, r6, r0
	adds r0, r2, r0
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r5]
	ldr r1, [sp, #0x18]
	adds r3, r1, r4
	ldrb r0, [r7]
	muls r0, r6, r0
	adds r0, r4, r0
	mov r1, r8
	adds r1, #0x24
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r6, r1
	adds r2, r2, r1
	add r2, sb
	ldrh r0, [r2]
	add r1, r8
	adds r1, #0x3b
	ldrb r1, [r1]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	bl CalculatePPWithBonus
	mov r2, sl
	adds r1, r2, r4
	strb r0, [r1]
	adds r5, #2
	adds r4, #1
	cmp r4, #3
	ble _0803BE0E
	ldr r0, _0803BE70
	ldr r1, [r0]
	movs r0, #1
	ands r1, r0
	movs r0, #0
	movs r2, #0
	add r3, sp, #4
	bl BtlController_EmitChooseMove
	b _0803C072
	.align 2, 0
_0803BE6C: .4byte 0x02023D28
_0803BE70: .4byte 0x02022C90
_0803BE74:
	ldr r0, _0803BE98
	ldr r0, [r0]
	ldr r1, _0803BE9C
	ands r0, r1
	cmp r0, #0
	bne _0803BE82
	b _0803C0D0
_0803BE82:
	ldr r4, _0803BEA0
	ldrb r0, [r4]
	movs r1, #1
	bl RecordedBattle_ClearBattlerAction
	ldr r1, _0803BEA4
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, _0803BEA8
	b _0803C3C8
	.align 2, 0
_0803BE98: .4byte 0x02022C90
_0803BE9C: .4byte 0x021F0902
_0803BEA0: .4byte 0x02023D08
_0803BEA4: .4byte 0x02023EC4
_0803BEA8: .4byte 0x08289E01
_0803BEAC:
	ldr r5, _0803BF14
	ldrb r0, [r5]
	ldr r3, _0803BF18
	ldr r1, [r3]
	adds r1, r0, r1
	adds r1, #0x58
	ldr r2, _0803BF1C
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r7, _0803BF20
	ldrb r2, [r5]
	movs r6, #0x58
	adds r0, r2, #0
	muls r0, r6, r0
	adds r1, r7, #0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _0803BF24
	ands r1, r0
	cmp r1, #0
	bne _0803BEFC
	ldr r0, _0803BF28
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	bne _0803BEFC
	ldr r0, _0803BF2C
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r1, r0
	cmp r1, #0
	beq _0803BF30
_0803BEFC:
	ldr r0, _0803BF14
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #0x60
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #2
	movs r2, #6
	b _0803C044
	.align 2, 0
_0803BF14: .4byte 0x02023D08
_0803BF18: .4byte 0x02024140
_0803BF1C: .4byte 0x02023D12
_0803BF20: .4byte 0x02023D28
_0803BF24: .4byte 0x0400E000
_0803BF28: .4byte 0x02022C90
_0803BF2C: .4byte 0x02023F50
_0803BF30:
	str r1, [sp]
	movs r0, #0xc
	adds r1, r2, #0
	movs r2, #0x17
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0803BFB8
	ldrb r1, [r5]
	str r4, [sp]
	movs r0, #0xc
	movs r2, #0x47
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0803BF80
	ldrb r0, [r5]
	muls r0, r6, r0
	adds r1, r0, r7
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803BF80
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803BF80
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x1a
	bne _0803BFB8
_0803BF80:
	ldr r5, _0803BFE4
	ldrb r1, [r5]
	movs r0, #0
	str r0, [sp]
	movs r0, #0xf
	movs r2, #0x2a
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0803BFF4
	ldr r2, _0803BFE8
	ldrb r1, [r5]
	movs r0, #0x58
	muls r0, r1, r0
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #8
	beq _0803BFB8
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #8
	bne _0803BFF4
_0803BFB8:
	subs r1, r4, #1
	lsls r1, r1, #4
	movs r0, #4
	orrs r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _0803BFEC
	ldrb r3, [r0]
	ldr r4, _0803BFF0
	ldr r0, _0803BFE4
	ldrb r0, [r0]
	lsls r2, r0, #1
	adds r2, r2, r0
	adds r2, #0x60
	ldr r0, [r4]
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #0
	movs r2, #6
	bl BtlController_EmitChoosePokemon
	b _0803C072
	.align 2, 0
_0803BFE4: .4byte 0x02023D08
_0803BFE8: .4byte 0x02023D28
_0803BFEC: .4byte 0x02023EAE
_0803BFF0: .4byte 0x02024140
_0803BFF4:
	ldr r0, _0803C010
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #2
	bne _0803C01C
	ldr r0, _0803C014
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803C01C
	ldr r0, _0803C018
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x5c
	b _0803C032
	.align 2, 0
_0803C010: .4byte 0x02023D08
_0803C014: .4byte 0x02023EC0
_0803C018: .4byte 0x02024140
_0803C01C:
	ldrb r0, [r4]
	cmp r0, #3
	bne _0803C054
	ldr r0, _0803C04C
	ldrb r0, [r0, #1]
	cmp r0, #2
	bne _0803C054
	ldr r0, _0803C050
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x5d
_0803C032:
	ldrb r2, [r0]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x60
	adds r3, r3, r0
	str r3, [sp]
	movs r0, #0
	movs r1, #0
_0803C044:
	movs r3, #0
	bl BtlController_EmitChoosePokemon
	b _0803C072
	.align 2, 0
_0803C04C: .4byte 0x02023EC0
_0803C050: .4byte 0x02024140
_0803C054:
	ldr r2, _0803C07C
	ldr r0, _0803C080
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #0x60
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #6
	movs r3, #0
	bl BtlController_EmitChoosePokemon
_0803C072:
	ldr r0, _0803C080
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	b _0803C308
	.align 2, 0
_0803C07C: .4byte 0x02024140
_0803C080: .4byte 0x02023D08
_0803C084:
	bl IsPlayerPartyAndPokemonStorageFull
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803C090
	b _0803C308
_0803C090:
	ldr r1, _0803C0BC
	ldr r3, _0803C0C0
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, _0803C0C4
	str r1, [r0]
	ldr r0, _0803C0C8
	ldrb r1, [r3]
	adds r1, r1, r0
	movs r4, #0
	movs r0, #6
	strb r0, [r1]
	ldrb r1, [r3]
	ldr r2, _0803C0CC
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x54
	strb r4, [r1]
	ldrb r1, [r3]
	b _0803C3E4
	.align 2, 0
_0803C0BC: .4byte 0x02023EC4
_0803C0C0: .4byte 0x02023D08
_0803C0C4: .4byte 0x08289099
_0803C0C8: .4byte 0x02023FD6
_0803C0CC: .4byte 0x02024140
_0803C0D0:
	ldr r2, _0803C0F0
	ldr r4, _0803C0F4
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x60
	ldr r1, [r2]
	adds r1, r1, r0
	movs r0, #0
	bl BtlController_EmitChooseItem
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	b _0803C308
	.align 2, 0
_0803C0F0: .4byte 0x02024140
_0803C0F4: .4byte 0x02023D08
_0803C0F8:
	ldr r4, _0803C188
	ldr r5, _0803C18C
	ldrb r0, [r5]
	adds r0, r0, r4
	movs r1, #7
	strb r1, [r0]
	ldrb r0, [r5]
	bl GetBattlerPosition
	movs r6, #2
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	bl RecordedBattle_ClearBattlerAction
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	ldr r1, _0803C190
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r7, #0x58
	muls r0, r7, r0
	adds r4, r1, #0
	adds r4, #0x50
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0803C176
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r0, r7, r0
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803C194
_0803C176:
	movs r0, #0
	bl BtlController_EmitEndBounceEffect
	ldrb r0, [r5]
	bl MarkBattlerForControllerExec
	bl _0803C9B4
	.align 2, 0
_0803C188: .4byte 0x02023FD6
_0803C18C: .4byte 0x02023D08
_0803C190: .4byte 0x02023D28
_0803C194:
	ldr r4, _0803C1D0
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803C1D4
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #2
	bl RecordedBattle_ClearBattlerAction
	b _0803C2F2
	.align 2, 0
_0803C1D0: .4byte 0x02023EC0
_0803C1D4:
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803C1FA
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	b _0803C2AC
_0803C1FA:
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803C26C
	ldr r4, _0803C264
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	cmp r0, #0
	blt _0803C25A
	ldr r4, _0803C268
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrh r0, [r1, #6]
	cmp r0, #0
	beq _0803C26C
_0803C25A:
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	b _0803C2AC
	.align 2, 0
_0803C264: .4byte 0x02023FE0
_0803C268: .4byte 0x02023F60
_0803C26C:
	ldr r0, _0803C2C0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0803C2D4
	ldr r4, _0803C2C4
	ldr r6, _0803C2C8
	ldrb r0, [r6]
	bl GetBattlerPosition
	movs r5, #2
	eors r0, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803C2D4
	ldr r1, _0803C2CC
	ldr r0, _0803C2D0
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6]
	bl GetBattlerPosition
	eors r0, r5
_0803C2AC:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl RecordedBattle_ClearBattlerAction
	b _0803C2F2
	.align 2, 0
_0803C2C0: .4byte 0x02022C90
_0803C2C4: .4byte 0x02023EC0
_0803C2C8: .4byte 0x02023D08
_0803C2CC: .4byte 0x03005AE0
_0803C2D0: .4byte 0x0203B9FC
_0803C2D4:
	ldr r0, _0803C304
	ldrb r0, [r0]
	bl GetBattlerPosition
	movs r1, #2
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #3
	bl RecordedBattle_ClearBattlerAction
_0803C2F2:
	movs r0, #0
	bl BtlController_EmitEndBounceEffect
	ldr r0, _0803C304
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	b _0803C9B4
	.align 2, 0
_0803C304: .4byte 0x02023D08
_0803C308:
	ldr r1, _0803C348
	ldr r2, [r1]
	movs r5, #8
	adds r0, r2, #0
	ands r0, r5
	adds r3, r1, #0
	cmp r0, #0
	beq _0803C364
	ldr r0, _0803C34C
	ands r2, r0
	cmp r2, #0
	beq _0803C364
	ldr r0, _0803C350
	ldr r4, _0803C354
	ldrb r2, [r4]
	lsls r1, r2, #9
	adds r0, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #3
	bne _0803C364
	ldr r1, _0803C358
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, _0803C35C
	str r1, [r0]
	ldr r1, _0803C360
	ldrb r0, [r4]
	adds r0, r0, r1
	movs r3, #0
	strb r5, [r0]
	b _0803C3D6
	.align 2, 0
_0803C348: .4byte 0x02022C90
_0803C34C: .4byte 0x043F0100
_0803C350: .4byte 0x02023508
_0803C354: .4byte 0x02023D08
_0803C358: .4byte 0x02023EC4
_0803C35C: .4byte 0x08289F42
_0803C360: .4byte 0x02023FD6
_0803C364:
	ldr r0, [r3]
	ldr r1, _0803C390
	ands r0, r1
	cmp r0, #8
	bne _0803C3A4
	ldr r0, _0803C394
	ldr r4, _0803C398
	ldrb r1, [r4]
	lsls r1, r1, #9
	adds r0, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #3
	bne _0803C3A4
	ldr r0, _0803C39C
	bl BattleScriptExecute
	ldr r1, _0803C3A0
	ldrb r0, [r4]
	adds r0, r0, r1
	b _0803C864
	.align 2, 0
_0803C390: .4byte 0x0200000A
_0803C394: .4byte 0x02023508
_0803C398: .4byte 0x02023D08
_0803C39C: .4byte 0x08289086
_0803C3A0: .4byte 0x02023FD6
_0803C3A4:
	bl IsRunningFromBattleImpossible
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803C408
	ldr r0, _0803C3F0
	ldr r4, _0803C3F4
	ldrb r2, [r4]
	lsls r1, r2, #9
	adds r0, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #3
	bne _0803C408
	ldr r1, _0803C3F8
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, _0803C3FC
_0803C3C8:
	str r1, [r0]
	ldr r0, _0803C400
	ldrb r1, [r4]
	adds r1, r1, r0
	movs r3, #0
	movs r0, #6
	strb r0, [r1]
_0803C3D6:
	ldrb r1, [r4]
	ldr r2, _0803C404
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x54
	strb r3, [r1]
	ldrb r1, [r4]
_0803C3E4:
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x84
	movs r0, #1
	strb r0, [r1]
	b _0803C9B4
	.align 2, 0
_0803C3F0: .4byte 0x02023508
_0803C3F4: .4byte 0x02023D08
_0803C3F8: .4byte 0x02023EC4
_0803C3FC: .4byte 0x08289093
_0803C400: .4byte 0x02023FD6
_0803C404: .4byte 0x02024140
_0803C408:
	ldr r2, _0803C414
	ldr r0, _0803C418
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C414: .4byte 0x02023FD6
_0803C418: .4byte 0x02023D08
_0803C41C:
	ldr r4, _0803C460
	ldr r1, _0803C464
	ldr r3, _0803C468
	ldrb r5, [r3]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r0, r2, #4
	movs r1, #0xf0
	lsls r1, r1, #0x18
	orrs r0, r1
	orrs r0, r2
	lsls r1, r2, #8
	orrs r0, r1
	lsls r2, r2, #0xc
	orrs r0, r2
	ldr r1, [r4]
	ands r1, r0
	adds r4, r3, #0
	cmp r1, #0
	beq _0803C448
	b _0803C948
_0803C448:
	ldr r1, _0803C46C
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #9
	bls _0803C456
	b _0803C948
_0803C456:
	lsls r0, r0, #2
	ldr r1, _0803C470
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803C460: .4byte 0x02023D0C
_0803C464: .4byte 0x082FACB4
_0803C468: .4byte 0x02023D08
_0803C46C: .4byte 0x02023EC0
_0803C470: .4byte 0x0803C474
_0803C474: @ jump table
	.4byte _0803C49C @ case 0
	.4byte _0803C5E0 @ case 1
	.4byte _0803C618 @ case 2
	.4byte _0803C64E @ case 3
	.4byte _0803C670 @ case 4
	.4byte _0803C684 @ case 5
	.4byte _0803C698 @ case 6
	.4byte _0803C6C8 @ case 7
	.4byte _0803C6DC @ case 8
	.4byte _0803C700 @ case 9
_0803C49C:
	ldr r1, _0803C4B8
	ldrb r3, [r4]
	lsls r0, r3, #9
	adds r1, #1
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #3
	blt _0803C4CE
	cmp r1, #9
	ble _0803C4BC
	cmp r1, #0xf
	beq _0803C4C2
	b _0803C4CE
	.align 2, 0
_0803C4B8: .4byte 0x02023508
_0803C4BC:
	adds r0, r3, r2
	strb r1, [r0]
	b _0803C9B4
_0803C4C2:
	adds r1, r3, r2
	movs r0, #2
	strb r0, [r1]
	bl sub_0803CA3C
	b _0803C9B4
_0803C4CE:
	movs r0, #2
	bl sub_08185D94
	ldr r4, _0803C504
	ldr r6, _0803C508
	ldrb r3, [r6]
	lsls r1, r3, #9
	adds r5, r4, #2
	adds r0, r1, r5
	ldrb r2, [r0]
	adds r7, r4, #3
	adds r1, r1, r7
	ldrb r0, [r1]
	lsls r0, r0, #8
	orrs r2, r0
	ldr r0, _0803C50C
	cmp r2, r0
	bne _0803C514
	ldr r0, _0803C510
	adds r0, r3, r0
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r6]
	bl RecordedBattle_ClearBattlerAction
	b _0803C948
	.align 2, 0
_0803C504: .4byte 0x02023508
_0803C508: .4byte 0x02023D08
_0803C50C: .4byte 0x0000FFFF
_0803C510: .4byte 0x02023FD6
_0803C514:
	bl TrySetCantSelectMoveBattleScript
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803C560
	ldrb r0, [r6]
	movs r1, #1
	bl RecordedBattle_ClearBattlerAction
	ldr r0, _0803C558
	ldrb r1, [r6]
	adds r1, r1, r0
	movs r3, #0
	movs r0, #6
	strb r0, [r1]
	ldrb r1, [r6]
	ldr r2, _0803C55C
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x54
	strb r3, [r1]
	ldrb r0, [r6]
	lsls r0, r0, #9
	adds r1, r4, #1
	adds r0, r0, r1
	strb r3, [r0]
	ldrb r1, [r6]
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x84
	movs r0, #2
	strb r0, [r1]
	b _0803C9B4
	.align 2, 0
_0803C558: .4byte 0x02023FD6
_0803C55C: .4byte 0x02024140
_0803C560:
	ldr r0, _0803C5CC
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	bne _0803C586
	ldrb r0, [r6]
	lsls r1, r0, #9
	adds r1, r1, r5
	ldrb r1, [r1]
	bl RecordedBattle_SetBattlerAction
	ldrb r0, [r6]
	lsls r1, r0, #9
	adds r1, r1, r7
	ldrb r1, [r1]
	bl RecordedBattle_SetBattlerAction
_0803C586:
	ldrb r0, [r6]
	ldr r4, _0803C5D0
	ldr r1, [r4]
	adds r1, r0, r1
	adds r1, #0x80
	lsls r0, r0, #9
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, _0803C5D4
	ldrb r2, [r6]
	lsls r5, r2, #1
	adds r5, r5, r0
	ldr r3, _0803C5D8
	ldr r4, [r4]
	adds r0, r2, r4
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r1, #0x58
	muls r1, r2, r1
	adds r0, r0, r1
	adds r3, #0xc
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r5]
	ldrb r0, [r6]
	adds r4, r0, r4
	lsls r0, r0, #9
	adds r0, r0, r7
	ldrb r0, [r0]
	strb r0, [r4, #0xc]
	ldr r0, _0803C5DC
	ldrb r1, [r6]
	b _0803C7B6
	.align 2, 0
_0803C5CC: .4byte 0x02022C90
_0803C5D0: .4byte 0x02024140
_0803C5D4: .4byte 0x02023F18
_0803C5D8: .4byte 0x02023D28
_0803C5DC: .4byte 0x02023FD6
_0803C5E0:
	ldr r2, _0803C608
	ldr r5, _0803C60C
	ldrb r4, [r5]
	lsls r1, r4, #9
	adds r0, r2, #1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r2, #2
	adds r1, r1, r2
	ldrb r0, [r1]
	lsls r0, r0, #8
	orrs r3, r0
	cmp r3, #0
	bne _0803C5FE
	b _0803C860
_0803C5FE:
	ldr r0, _0803C610
	strh r3, [r0]
	ldr r0, _0803C614
	ldrb r1, [r5]
	b _0803C7B6
	.align 2, 0
_0803C608: .4byte 0x02023508
_0803C60C: .4byte 0x02023D08
_0803C610: .4byte 0x02023EAC
_0803C614: .4byte 0x02023FD6
_0803C618:
	ldr r0, _0803C63C
	ldr r4, _0803C640
	ldrb r2, [r4]
	lsls r1, r2, #9
	adds r0, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #6
	bne _0803C648
	ldr r0, _0803C644
	adds r0, r2, r0
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r4]
	bl RecordedBattle_ClearBattlerAction
	b _0803C948
	.align 2, 0
_0803C63C: .4byte 0x02023508
_0803C640: .4byte 0x02023D08
_0803C644: .4byte 0x02023FD6
_0803C648:
	bl sub_0803CA3C
	b _0803C7B2
_0803C64E:
	ldr r2, _0803C664
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0803C668
	ldr r0, _0803C66C
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C664: .4byte 0x02023F24
_0803C668: .4byte 0x02023FD6
_0803C66C: .4byte 0x02023D08
_0803C670:
	ldr r2, _0803C67C
	ldr r0, _0803C680
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C67C: .4byte 0x02023FD6
_0803C680: .4byte 0x02023D08
_0803C684:
	ldr r2, _0803C690
	ldr r0, _0803C694
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C690: .4byte 0x02023FD6
_0803C694: .4byte 0x02023D08
_0803C698:
	ldr r3, _0803C6BC
	ldr r0, _0803C6C0
	ldrb r4, [r0]
	lsls r1, r4, #9
	adds r0, r3, #1
	adds r0, r1, r0
	ldrb r2, [r0]
	adds r3, #2
	adds r1, r1, r3
	ldrb r0, [r1]
	lsls r0, r0, #8
	orrs r2, r0
	cmp r2, #0
	bne _0803C6B6
	b _0803C860
_0803C6B6:
	ldr r1, _0803C6C4
	adds r1, r4, r1
	b _0803C7B8
	.align 2, 0
_0803C6BC: .4byte 0x02023508
_0803C6C0: .4byte 0x02023D08
_0803C6C4: .4byte 0x02023FD6
_0803C6C8:
	ldr r2, _0803C6D4
	ldr r0, _0803C6D8
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C6D4: .4byte 0x02023FD6
_0803C6D8: .4byte 0x02023D08
_0803C6DC:
	ldr r2, _0803C6F4
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0803C6F8
	ldr r0, _0803C6FC
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C6F4: .4byte 0x02023F24
_0803C6F8: .4byte 0x02023FD6
_0803C6FC: .4byte 0x02023D08
_0803C700:
	ldr r2, _0803C70C
	ldr r0, _0803C710
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C70C: .4byte 0x02023FD6
_0803C710: .4byte 0x02023D08
_0803C714:
	ldr r3, _0803C78C
	ldr r6, _0803C790
	ldr r0, _0803C794
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	lsls r1, r2, #4
	movs r0, #0xf0
	lsls r0, r0, #0x18
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, #8
	orrs r1, r0
	lsls r2, r2, #0xc
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0803C73E
	b _0803C948
_0803C73E:
	bl AllAtActionConfirmed
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r4, r1, #0x1f
	ldr r0, _0803C798
	ldr r0, [r0]
	movs r1, #0x41
	ands r0, r1
	cmp r0, #1
	bne _0803C780
	movs r1, #2
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	bne _0803C780
	adds r0, r5, #0
	eors r0, r1
	bl GetBattlerAtPosition
	ldr r1, _0803C79C
	ldr r1, [r1]
	adds r1, #0x91
	ldrb r1, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r6
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0803C7A0
_0803C780:
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl BtlController_EmitLinkStandbyMsg
	b _0803C7AA
	.align 2, 0
_0803C78C: .4byte 0x02023D0C
_0803C790: .4byte 0x082FACB4
_0803C794: .4byte 0x02023D08
_0803C798: .4byte 0x02022C90
_0803C79C: .4byte 0x02024140
_0803C7A0:
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl BtlController_EmitLinkStandbyMsg
_0803C7AA:
	ldr r4, _0803C7C0
_0803C7AC:
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_0803C7B2:
	ldr r0, _0803C7C4
	ldrb r1, [r4]
_0803C7B6:
	adds r1, r1, r0
_0803C7B8:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803C948
	.align 2, 0
_0803C7C0: .4byte 0x02023D08
_0803C7C4: .4byte 0x02023FD6
_0803C7C8:
	ldr r3, _0803C7FC
	ldr r1, _0803C800
	ldr r0, _0803C804
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r1, r2, #4
	movs r0, #0xf0
	lsls r0, r0, #0x18
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, #8
	orrs r1, r0
	lsls r2, r2, #0xc
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0803C7F2
	b _0803C948
_0803C7F2:
	ldr r1, _0803C808
	ldrb r0, [r1, #4]
	adds r0, #1
	strb r0, [r1, #4]
	b _0803C948
	.align 2, 0
_0803C7FC: .4byte 0x02023D0C
_0803C800: .4byte 0x082FACB4
_0803C804: .4byte 0x02023D08
_0803C808: .4byte 0x02023FD6
_0803C80C:
	ldr r5, _0803C82C
	ldrb r2, [r5]
	ldr r0, _0803C830
	ldr r0, [r0]
	adds r1, r2, r0
	adds r0, r1, #0
	adds r0, #0x54
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C8F8
	ldr r0, _0803C834
	adds r0, r2, r0
	adds r1, #0x84
	ldrb r1, [r1]
	strb r1, [r0]
	b _0803C948
	.align 2, 0
_0803C82C: .4byte 0x02023D08
_0803C830: .4byte 0x02024140
_0803C834: .4byte 0x02023FD6
_0803C838:
	ldr r3, _0803C86C
	ldr r1, _0803C870
	ldr r0, _0803C874
	ldrb r4, [r0]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r1, r2, #4
	movs r0, #0xf0
	lsls r0, r0, #0x18
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, #8
	orrs r1, r0
	lsls r2, r2, #0xc
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0803C948
_0803C860:
	ldr r0, _0803C878
	adds r0, r4, r0
_0803C864:
	movs r1, #1
	strb r1, [r0]
	b _0803C948
	.align 2, 0
_0803C86C: .4byte 0x02023D0C
_0803C870: .4byte 0x082FACB4
_0803C874: .4byte 0x02023D08
_0803C878: .4byte 0x02023FD6
_0803C87C:
	ldr r5, _0803C8C0
	ldrb r2, [r5]
	ldr r4, _0803C8C4
	ldr r0, [r4]
	adds r0, r2, r0
	adds r0, #0x54
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C8F8
	ldr r0, _0803C8C8
	lsls r1, r2, #9
	adds r0, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0xd
	bne _0803C8D8
	ldr r2, _0803C8CC
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0803C8D0
	ldrb r0, [r5]
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r1, _0803C8D4
	ldrb r0, [r5]
_0803C8B6:
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	b _0803C948
	.align 2, 0
_0803C8C0: .4byte 0x02023D08
_0803C8C4: .4byte 0x02024140
_0803C8C8: .4byte 0x02023508
_0803C8CC: .4byte 0x02023F24
_0803C8D0: .4byte 0x02023EC0
_0803C8D4: .4byte 0x02023FD6
_0803C8D8:
	adds r0, r2, #0
	movs r1, #1
	bl RecordedBattle_ClearBattlerAction
	ldr r2, _0803C8F4
	ldrb r0, [r5]
	adds r2, r0, r2
	ldr r1, [r4]
	adds r0, r0, r1
	adds r0, #0x84
	ldrb r0, [r0]
	strb r0, [r2]
	b _0803C948
	.align 2, 0
_0803C8F4: .4byte 0x02023FD6
_0803C8F8:
	ldr r0, _0803C9C4
	strb r2, [r0]
	ldr r7, _0803C9C8
	ldr r6, _0803C9CC
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r4, [r0]
	str r4, [r7]
	ldr r3, _0803C9D0
	ldr r1, _0803C9D4
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r1, r2, #4
	movs r0, #0xf0
	lsls r0, r0, #0x18
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, #8
	orrs r1, r0
	lsls r2, r2, #0xc
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0803C93E
	ldr r0, _0803C9D8
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl _call_via_r0
_0803C93E:
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r1, [r7]
	str r1, [r0]
_0803C948:
	ldr r0, _0803C9DC
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r0, _0803C9E0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
_0803C956:
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r1, r0
	bhs _0803C962
	bl HandleTurnActionSelectionState
_0803C962:
	ldr r0, _0803C9E4
	ldrb r0, [r0, #4]
	ldrb r1, [r5]
	cmp r0, r1
	bne _0803C9B4
	movs r0, #1
	bl sub_08185D94
	ldr r1, _0803C9E8
	ldr r0, _0803C9EC
	str r0, [r1]
	ldr r0, _0803C9F0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803C9B4
	movs r4, #0
	ldrb r5, [r5]
	cmp r4, r5
	bge _0803C9B4
_0803C98E:
	ldr r0, _0803C9F4
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803C9AA
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0803C9F8
	ldr r1, [r1]
	adds r1, r4, r1
	adds r1, #0x5c
	ldrb r1, [r1]
	bl SwitchPartyOrderInGameMulti
_0803C9AA:
	adds r4, #1
	ldr r0, _0803C9E0
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803C98E
_0803C9B4:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C9C4: .4byte 0x02023EAF
_0803C9C8: .4byte 0x02023EB8
_0803C9CC: .4byte 0x02023EC4
_0803C9D0: .4byte 0x02023D0C
_0803C9D4: .4byte 0x082FACB4
_0803C9D8: .4byte 0x082EC694
_0803C9DC: .4byte 0x02023D08
_0803C9E0: .4byte 0x02023D10
_0803C9E4: .4byte 0x02023FD6
_0803C9E8: .4byte 0x03005A64
_0803C9EC: .4byte 0x0803CF2D
_0803C9F0: .4byte 0x02022C90
_0803C9F4: .4byte 0x02023EC0
_0803C9F8: .4byte 0x02024140
	thumb_func_end HandleTurnActionSelectionState

	thumb_func_start AllAtActionConfirmed
AllAtActionConfirmed: @ 0x0803C9FC
	push {r4, r5, lr}
	movs r3, #0
	movs r1, #0
	ldr r0, _0803CA2C
	ldrb r2, [r0]
	adds r5, r0, #0
	cmp r3, r2
	bge _0803CA1E
	ldr r4, _0803CA30
_0803CA0E:
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #5
	bne _0803CA18
	adds r3, #1
_0803CA18:
	adds r1, #1
	cmp r1, r2
	blt _0803CA0E
_0803CA1E:
	adds r0, r3, #1
	ldrb r5, [r5]
	cmp r0, r5
	beq _0803CA34
	movs r0, #0
	b _0803CA36
	.align 2, 0
_0803CA2C: .4byte 0x02023D10
_0803CA30: .4byte 0x02023FD6
_0803CA34:
	movs r0, #1
_0803CA36:
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end AllAtActionConfirmed

	thumb_func_start sub_0803CA3C
sub_0803CA3C: @ 0x0803CA3C
	push {r4, r5, r6, r7, lr}
	ldr r7, _0803CB10
	ldrb r0, [r7]
	ldr r6, _0803CB14
	ldr r1, [r6]
	adds r1, r0, r1
	adds r1, #0x5c
	ldr r4, _0803CB18
	lsls r0, r0, #9
	adds r2, r4, #1
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	lsls r1, r0, #9
	adds r1, r1, r2
	ldrb r1, [r1]
	bl RecordedBattle_SetBattlerAction
	ldr r0, _0803CB1C
	ldr r0, [r0]
	movs r1, #0x42
	ands r0, r1
	cmp r0, #0x42
	bne _0803CB0A
	ldrb r0, [r7]
	ldr r2, [r6]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, r1, r2
	adds r1, #0x60
	ldrb r2, [r1]
	movs r0, #0xf
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r7]
	ldr r2, [r6]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, r1, r2
	adds r1, #0x60
	lsls r0, r0, #9
	adds r5, r4, #2
	adds r0, r0, r5
	ldrb r2, [r0]
	movs r3, #0xf0
	adds r0, r3, #0
	ands r0, r2
	ldrb r2, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldrb r1, [r7]
	ldr r2, [r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, r0, r2
	adds r0, #0x61
	lsls r1, r1, #9
	adds r4, #3
	mov ip, r4
	add r1, ip
	ldrb r1, [r1]
	strb r1, [r0]
	ldrb r0, [r7]
	movs r4, #2
	eors r0, r4
	ldr r2, [r6]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, r1, r2
	adds r1, #0x60
	ldrb r2, [r1]
	adds r0, r3, #0
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r7]
	eors r0, r4
	ldr r2, [r6]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, r1, r2
	adds r1, #0x60
	ldrb r0, [r7]
	lsls r0, r0, #9
	adds r0, r0, r5
	ldrb r0, [r0]
	ands r3, r0
	lsrs r3, r3, #4
	ldrb r0, [r1]
	orrs r3, r0
	strb r3, [r1]
	ldrb r0, [r7]
	eors r4, r0
	ldr r0, [r6]
	lsls r1, r4, #1
	adds r1, r1, r4
	adds r1, r1, r0
	adds r1, #0x62
	ldrb r0, [r7]
	lsls r0, r0, #9
	add r0, ip
	ldrb r0, [r0]
	strb r0, [r1]
_0803CB0A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803CB10: .4byte 0x02023D08
_0803CB14: .4byte 0x02024140
_0803CB18: .4byte 0x02023508
_0803CB1C: .4byte 0x02022C90
	thumb_func_end sub_0803CA3C

	thumb_func_start SwapTurnOrder
SwapTurnOrder: @ 0x0803CB20
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r2, _0803CB4C
	adds r4, r0, r2
	ldrb r5, [r4]
	adds r2, r1, r2
	ldrb r3, [r2]
	strb r3, [r4]
	strb r5, [r2]
	ldr r2, _0803CB50
	adds r0, r0, r2
	ldrb r5, [r0]
	adds r1, r1, r2
	ldrb r2, [r1]
	strb r2, [r0]
	strb r5, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803CB4C: .4byte 0x02023D1E
_0803CB50: .4byte 0x02023D22
	thumb_func_end SwapTurnOrder

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

	thumb_func_start SetActionsAndBattlersTurnOrder
SetActionsAndBattlersTurnOrder: @ 0x0803CF2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r3, #0
	ldr r0, _0803CF80
	ldr r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0803CF98
	ldr r0, _0803CF84
	strb r3, [r0]
	ldr r4, _0803CF88
	mov r8, r0
	ldrb r0, [r4]
	cmp r3, r0
	blo _0803CF54
	b _0803D18E
_0803CF54:
	ldr r7, _0803CF8C
	ldr r6, _0803CF90
	mov r2, r8
	ldr r5, _0803CF94
_0803CF5C:
	adds r1, r3, r7
	ldrb r0, [r2]
	adds r0, r0, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r1, r3, r5
	ldrb r0, [r2]
	strb r0, [r1]
	adds r3, #1
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4]
	cmp r0, r1
	blo _0803CF5C
	b _0803D18E
	.align 2, 0
_0803CF80: .4byte 0x02022C90
_0803CF84: .4byte 0x02023D08
_0803CF88: .4byte 0x02023D10
_0803CF8C: .4byte 0x02023D1E
_0803CF90: .4byte 0x02023EC0
_0803CF94: .4byte 0x02023D22
_0803CF98:
	movs r2, #2
	ands r1, r2
	cmp r1, #0
	beq _0803CFE8
	ldr r0, _0803CFDC
	strb r3, [r0]
	ldr r1, _0803CFE0
	mov r8, r0
	adds r2, r1, #0
	ldrb r2, [r2]
	cmp r3, r2
	bhs _0803D004
	ldr r0, _0803CFE4
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #3
	beq _0803D002
_0803CFBA:
	mov r7, r8
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0803CFE0
	ldrb r1, [r1]
	cmp r0, r1
	bhs _0803D004
	ldrb r0, [r7]
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803CFBA
	b _0803D002
	.align 2, 0
_0803CFDC: .4byte 0x02023D08
_0803CFE0: .4byte 0x02023D10
_0803CFE4: .4byte 0x02023EC0
_0803CFE8:
	ldr r1, _0803D06C
	ldrb r0, [r1]
	ldr r4, _0803D070
	mov r8, r4
	cmp r0, #3
	bne _0803CFF8
	strb r3, [r4]
	movs r3, #5
_0803CFF8:
	ldrb r0, [r1, #2]
	cmp r0, #3
	bne _0803D004
	mov r7, r8
	strb r2, [r7]
_0803D002:
	movs r3, #5
_0803D004:
	cmp r3, #5
	bne _0803D08C
	ldr r6, _0803D074
	ldr r1, _0803D06C
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6]
	ldr r2, _0803D078
	mov r3, r8
	ldrb r0, [r3]
	strb r0, [r2]
	movs r3, #1
	movs r5, #0
	adds r4, r1, #0
	ldr r7, _0803D07C
	mov sl, r7
	ldr r0, _0803D080
	mov ip, r0
	ldr r1, _0803D084
	mov sb, r1
	ldr r7, _0803D088
	ldrb r7, [r7]
	cmp r5, r7
	bge _0803D05E
	adds r7, r6, #0
	adds r6, r4, #0
	adds r4, r2, #0
	ldr r2, _0803D088
_0803D040:
	mov r0, r8
	ldrb r0, [r0]
	cmp r5, r0
	beq _0803D056
	adds r1, r3, r7
	adds r0, r5, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, r4
	strb r5, [r0]
	adds r3, #1
_0803D056:
	adds r5, #1
	ldrb r1, [r2]
	cmp r5, r1
	blt _0803D040
_0803D05E:
	mov r2, ip
	mov r3, sl
	str r2, [r3]
	mov r4, sb
	ldr r0, [r4]
	b _0803D198
	.align 2, 0
_0803D06C: .4byte 0x02023EC0
_0803D070: .4byte 0x02023D08
_0803D074: .4byte 0x02023D1E
_0803D078: .4byte 0x02023D22
_0803D07C: .4byte 0x03005A64
_0803D080: .4byte 0x0803D335
_0803D084: .4byte 0x02024140
_0803D088: .4byte 0x02023D10
_0803D08C:
	movs r0, #0
	mov r7, r8
	strb r0, [r7]
	ldr r1, _0803D11C
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803D0D2
	ldr r6, _0803D120
	mov r2, r8
	ldr r5, _0803D124
	ldr r4, _0803D128
_0803D0A2:
	ldrb r0, [r2]
	adds r0, r0, r6
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0803D0C0
	adds r0, r3, r5
	strb r1, [r0]
	adds r1, r3, r4
	mov r7, r8
	ldrb r0, [r7]
	strb r0, [r1]
	adds r3, #1
_0803D0C0:
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0803D11C
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803D0A2
_0803D0D2:
	movs r0, #0
	mov r2, r8
	strb r0, [r2]
	ldr r4, _0803D11C
	ldrb r0, [r4]
	cmp r0, #0
	beq _0803D116
	ldr r6, _0803D120
	ldr r5, _0803D124
	ldr r4, _0803D128
_0803D0E6:
	ldrb r0, [r2]
	adds r0, r0, r6
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0803D104
	adds r0, r3, r5
	strb r1, [r0]
	adds r1, r3, r4
	mov r7, r8
	ldrb r0, [r7]
	strb r0, [r1]
	adds r3, #1
_0803D104:
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0803D11C
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803D0E6
_0803D116:
	movs r5, #0
	b _0803D184
	.align 2, 0
_0803D11C: .4byte 0x02023D10
_0803D120: .4byte 0x02023EC0
_0803D124: .4byte 0x02023D1E
_0803D128: .4byte 0x02023D22
_0803D12C:
	adds r4, r5, #1
	adds r7, r4, #0
	ldrb r1, [r1]
	cmp r7, r1
	bge _0803D182
	ldr r6, _0803D1AC
	lsls r2, r5, #0x18
	mov r8, r2
_0803D13C:
	ldr r0, _0803D1B0
	adds r1, r5, r0
	ldrb r3, [r1]
	adds r0, r4, r0
	ldrb r1, [r0]
	adds r0, r5, r6
	ldrb r2, [r0]
	cmp r2, #1
	beq _0803D178
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #1
	beq _0803D178
	cmp r2, #2
	beq _0803D178
	cmp r0, #2
	beq _0803D178
	adds r0, r3, #0
	movs r2, #0
	bl GetWhoStrikesFirst
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803D178
	lsls r1, r4, #0x18
	lsrs r1, r1, #0x18
	mov r3, r8
	lsrs r0, r3, #0x18
	bl SwapTurnOrder
_0803D178:
	adds r4, #1
	ldr r0, _0803D1B4
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803D13C
_0803D182:
	adds r5, r7, #0
_0803D184:
	ldr r1, _0803D1B4
	ldrb r0, [r1]
	subs r0, #1
	cmp r5, r0
	blt _0803D12C
_0803D18E:
	ldr r1, _0803D1B8
	ldr r0, _0803D1BC
	str r0, [r1]
	ldr r0, _0803D1C0
	ldr r0, [r0]
_0803D198:
	adds r0, #0x48
	movs r1, #0
	strb r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D1AC: .4byte 0x02023D1E
_0803D1B0: .4byte 0x02023D22
_0803D1B4: .4byte 0x02023D10
_0803D1B8: .4byte 0x03005A64
_0803D1BC: .4byte 0x0803D335
_0803D1C0: .4byte 0x02024140
	thumb_func_end SetActionsAndBattlersTurnOrder

	thumb_func_start TurnValuesCleanUp
TurnValuesCleanUp: @ 0x0803D1C4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	ldr r1, _0803D21C
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0803D220
	ldrb r2, [r0]
	adds r5, r1, #0
	cmp r2, #0
	beq _0803D2BC
	ldr r7, _0803D224
	adds r6, r5, #0
	ldr r0, _0803D228
	mov ip, r0
	ldr r1, _0803D22C
	mov r8, r1
	mov sl, r8
_0803D1F2:
	mov r2, sb
	cmp r2, #0
	beq _0803D230
	ldrb r1, [r6]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1]
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r6]
	lsls r1, r1, #4
	adds r1, r1, r7
	ldrb r2, [r1]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	b _0803D28C
	.align 2, 0
_0803D21C: .4byte 0x02023D08
_0803D220: .4byte 0x02023D10
_0803D224: .4byte 0x02023FE0
_0803D228: .4byte 0x02023D78
_0803D22C: .4byte 0x02023F60
_0803D230:
	ldrb r0, [r6]
	lsls r0, r0, #4
	adds r2, r0, r7
	movs r1, #0
	mov r4, sl
	movs r3, #0
_0803D23C:
	adds r0, r2, r1
	strb r3, [r0]
	adds r1, #1
	cmp r1, #0xf
	bls _0803D23C
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r4
	ldrb r0, [r1, #0x16]
	cmp r0, #0
	beq _0803D25A
	subs r0, #1
	strb r0, [r1, #0x16]
_0803D25A:
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r4
	ldrb r0, [r1, #0x19]
	cmp r0, #0
	beq _0803D28C
	subs r0, #1
	strb r0, [r1, #0x19]
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r0, [r0, #0x19]
	cmp r0, #0
	bne _0803D28C
	movs r0, #0x58
	muls r2, r0, r2
	add r2, ip
	ldr r0, [r2]
	ldr r1, _0803D2D4
	ands r0, r1
	str r0, [r2]
_0803D28C:
	ldrb r2, [r5]
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0, #0xa]
	cmp r0, #0
	bne _0803D2AA
	movs r0, #0x58
	muls r2, r0, r2
	add r2, ip
	ldr r0, [r2]
	ldr r1, _0803D2D8
	ands r0, r1
	str r0, [r2]
_0803D2AA:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0803D2DC
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803D1F2
_0803D2BC:
	movs r0, #0
	ldr r2, _0803D2E0
	strb r0, [r2, #8]
	strb r0, [r2, #0x14]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D2D4: .4byte 0xFFBFFFFF
_0803D2D8: .4byte 0xFEFFFFFF
_0803D2DC: .4byte 0x02023D10
_0803D2E0: .4byte 0x02023F38
	thumb_func_end TurnValuesCleanUp

	thumb_func_start SpecialStatusesClear
SpecialStatusesClear: @ 0x0803D2E4
	push {r4, r5, r6, lr}
	ldr r2, _0803D328
	movs r0, #0
	strb r0, [r2]
	ldr r0, _0803D32C
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _0803D322
	adds r3, r2, #0
	movs r4, #0
	ldr r5, _0803D330
_0803D2FC:
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r0, r5
	movs r1, #0
_0803D308:
	adds r0, r2, r1
	strb r4, [r0]
	adds r1, #1
	cmp r1, #0x13
	bls _0803D308
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r6]
	cmp r0, r1
	blo _0803D2FC
_0803D322:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803D328: .4byte 0x02023D08
_0803D32C: .4byte 0x02023D10
_0803D330: .4byte 0x02024020
	thumb_func_end SpecialStatusesClear

	thumb_func_start CheckFocusPunch_ClearVarsBeforeTurnStarts
CheckFocusPunch_ClearVarsBeforeTurnStarts: @ 0x0803D334
	push {r4, r5, r6, r7, lr}
	ldr r0, _0803D3BC
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	bne _0803D3F2
	ldr r2, _0803D3C0
	ldr r0, [r2]
	adds r0, #0x48
	ldr r1, _0803D3C4
	ldrb r0, [r0]
	mov ip, r2
	adds r6, r1, #0
	ldrb r1, [r6]
	cmp r0, r1
	bhs _0803D3F2
	ldr r5, _0803D3C8
	ldr r4, _0803D3CC
	movs r7, #0x84
	lsls r7, r7, #1
_0803D360:
	ldr r1, [r2]
	adds r1, #0x48
	ldrb r0, [r1]
	strb r0, [r4]
	strb r0, [r5]
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _0803D3D0
	ldrb r3, [r5]
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r0, r7
	bne _0803D3E4
	ldr r1, _0803D3D4
	movs r0, #0x58
	muls r0, r3, r0
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0803D3E4
	ldr r2, _0803D3D8
	ldrb r1, [r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #0x18]
	lsls r0, r0, #0x1f
	cmp r0, #0
	bne _0803D3E4
	ldr r0, _0803D3DC
	lsls r1, r3, #4
	adds r1, r1, r0
	ldrb r0, [r1]
	lsls r0, r0, #0x1d
	cmp r0, #0
	blt _0803D3E4
	ldr r0, _0803D3E0
	bl BattleScriptExecute
	b _0803D42C
	.align 2, 0
_0803D3BC: .4byte 0x02023F24
_0803D3C0: .4byte 0x02024140
_0803D3C4: .4byte 0x02023D10
_0803D3C8: .4byte 0x02023D08
_0803D3CC: .4byte 0x02023EAF
_0803D3D0: .4byte 0x02023F18
_0803D3D4: .4byte 0x02023D28
_0803D3D8: .4byte 0x02023F60
_0803D3DC: .4byte 0x02023FE0
_0803D3E0: .4byte 0x08289787
_0803D3E4:
	mov r2, ip
	ldr r0, [r2]
	adds r0, #0x48
	ldrb r0, [r0]
	ldrb r1, [r6]
	cmp r0, r1
	blo _0803D360
_0803D3F2:
	bl TryClearRageStatuses
	ldr r1, _0803D434
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0803D438
	ldr r0, _0803D43C
	movs r3, #0
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, _0803D440
	movs r2, #0
	strh r3, [r0]
	ldr r0, _0803D444
	ldr r0, [r0]
	strb r2, [r0, #0x13]
	ldr r1, _0803D448
	ldr r0, _0803D44C
	str r0, [r1]
	ldr r0, _0803D450
	strb r2, [r0, #3]
	strb r2, [r0, #4]
	ldr r0, _0803D454
	strb r2, [r0, #0x16]
	ldr r0, _0803D458
	ldr r0, [r0]
	ldr r0, [r0, #8]
	adds r0, #0x20
	strb r2, [r0]
_0803D42C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803D434: .4byte 0x02023D26
_0803D438: .4byte 0x02023D27
_0803D43C: .4byte 0x02023D1E
_0803D440: .4byte 0x020240A4
_0803D444: .4byte 0x02024140
_0803D448: .4byte 0x03005A64
_0803D44C: .4byte 0x0803D45D
_0803D450: .4byte 0x02023FD6
_0803D454: .4byte 0x02024118
_0803D458: .4byte 0x0202414C
	thumb_func_end CheckFocusPunch_ClearVarsBeforeTurnStarts

	thumb_func_start RunBattleScriptCommands
RunBattleScriptCommands: @ 0x0803D45C
	push {r4, r5, r6, lr}
	ldr r6, _0803D4B0
	ldrb r0, [r6]
	ldr r2, _0803D4B4
	cmp r0, #0
	beq _0803D46C
	movs r0, #0xc
	strb r0, [r2]
_0803D46C:
	ldr r5, _0803D4B8
	ldr r0, [r5]
	adds r0, #0x4b
	ldr r4, _0803D4BC
	ldrb r1, [r4]
	strb r1, [r0]
	ldr r1, _0803D4C0
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _0803D4C4
	thumb_func_end RunBattleScriptCommands

	thumb_func_start RunTurnActionsFunctions
RunTurnActionsFunctions: @ 0x0803D488
	ldrb r1, [r4]
	ldrb r0, [r0]
	cmp r1, r0
	blo _0803D4D8
	ldr r2, _0803D4C8
	ldr r0, [r2]
	ldr r1, _0803D4CC
	ands r0, r1
	str r0, [r2]
	ldr r3, _0803D4D0
	ldr r2, _0803D4D4
	ldrb r1, [r6]
	movs r0, #0x7f
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
	b _0803D4F0
	.align 2, 0
_0803D4B0: .4byte 0x02023FDE
_0803D4B4: .4byte 0x02023D27
_0803D4B8: .4byte 0x02024140
_0803D4BC: .4byte 0x02023D26
_0803D4C0: .4byte 0x082EC600
_0803D4C4: .4byte 0x02023D10
_0803D4C8: .4byte 0x02023F24
_0803D4CC: .4byte 0xFFEFFFFF
_0803D4D0: .4byte 0x03005A64
_0803D4D4: .4byte 0x082EC638
_0803D4D8:
	ldr r0, [r5]
	adds r0, #0x4b
	ldrb r0, [r0]
	cmp r0, r1
	beq _0803D4F0
	ldr r2, _0803D4F8
	ldr r0, [r2]
	ldr r1, _0803D4FC
	ands r0, r1
	ldr r1, _0803D500
	ands r0, r1
	str r0, [r2]
_0803D4F0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803D4F8: .4byte 0x02023F24
_0803D4FC: .4byte 0xFFFFFDFF
_0803D500: .4byte 0xFFF7FFFF
	thumb_func_end RunTurnActionsFunctions

	thumb_func_start HandleEndTurn_BattleWon
HandleEndTurn_BattleWon: @ 0x0803D504
	push {r4, lr}
	ldr r1, _0803D540
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0803D544
	ldr r2, [r1]
	ldr r0, _0803D548
	ands r0, r2
	cmp r0, #0
	beq _0803D564
	ldr r1, _0803D54C
	ldr r4, _0803D550
	ldrb r0, [r4]
	strh r0, [r1]
	ldr r1, _0803D554
	ldrb r0, [r4]
	strb r0, [r1]
	movs r0, #0
	bl GetBattlerAtPosition
	ldr r1, _0803D558
	strb r0, [r1]
	ldr r1, _0803D55C
	ldr r0, _0803D560
	str r0, [r1]
	ldrb r1, [r4]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r4]
	b _0803D6E4
	.align 2, 0
_0803D540: .4byte 0x02023D27
_0803D544: .4byte 0x02022C90
_0803D548: .4byte 0x02000002
_0803D54C: .4byte 0x02037290
_0803D550: .4byte 0x02023FDE
_0803D554: .4byte 0x02022C0C
_0803D558: .4byte 0x02023EAF
_0803D55C: .4byte 0x02023EB8
_0803D560: .4byte 0x08288FBD
_0803D564:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0803D5A0
	ldr r0, _0803D58C
	ands r2, r0
	cmp r2, #0
	beq _0803D5A0
	bl BattleStopLowHpSound
	ldr r1, _0803D590
	ldr r0, _0803D594
	str r0, [r1]
	ldr r0, _0803D598
	ldrh r1, [r0]
	ldr r0, _0803D59C
	cmp r1, r0
	bne _0803D58A
	b _0803D6CA
_0803D58A:
	b _0803D6D4
	.align 2, 0
_0803D58C: .4byte 0x043F0900
_0803D590: .4byte 0x02023EB8
_0803D594: .4byte 0x0828900F
_0803D598: .4byte 0x0203886A
_0803D59C: .4byte 0x000003FE
_0803D5A0:
	ldr r0, [r1]
	movs r1, #0xa
	ands r0, r1
	cmp r0, #8
	beq _0803D5AC
	b _0803D6DE
_0803D5AC:
	bl BattleStopLowHpSound
	ldr r1, _0803D5D4
	ldr r0, _0803D5D8
	str r0, [r1]
	ldr r1, _0803D5DC
	ldr r0, _0803D5E0
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	subs r0, #3
	cmp r0, #0x32
	bls _0803D5CA
	b _0803D6D4
_0803D5CA:
	lsls r0, r0, #2
	ldr r1, _0803D5E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803D5D4: .4byte 0x02023EB8
_0803D5D8: .4byte 0x08288EB5
_0803D5DC: .4byte 0x082E383C
_0803D5E0: .4byte 0x0203886A
_0803D5E4: .4byte 0x0803D5E8
_0803D5E8: @ jump table
	.4byte _0803D6C0 @ case 0
	.4byte _0803D6D4 @ case 1
	.4byte _0803D6D4 @ case 2
	.4byte _0803D6D4 @ case 3
	.4byte _0803D6D4 @ case 4
	.4byte _0803D6D4 @ case 5
	.4byte _0803D6C0 @ case 6
	.4byte _0803D6D4 @ case 7
	.4byte _0803D6C0 @ case 8
	.4byte _0803D6D4 @ case 9
	.4byte _0803D6C0 @ case 10
	.4byte _0803D6D4 @ case 11
	.4byte _0803D6D4 @ case 12
	.4byte _0803D6D4 @ case 13
	.4byte _0803D6D4 @ case 14
	.4byte _0803D6D4 @ case 15
	.4byte _0803D6D4 @ case 16
	.4byte _0803D6D4 @ case 17
	.4byte _0803D6D4 @ case 18
	.4byte _0803D6D4 @ case 19
	.4byte _0803D6D4 @ case 20
	.4byte _0803D6D4 @ case 21
	.4byte _0803D6D4 @ case 22
	.4byte _0803D6D4 @ case 23
	.4byte _0803D6D4 @ case 24
	.4byte _0803D6D4 @ case 25
	.4byte _0803D6D4 @ case 26
	.4byte _0803D6D4 @ case 27
	.4byte _0803D6B4 @ case 28
	.4byte _0803D6CA @ case 29
	.4byte _0803D6D4 @ case 30
	.4byte _0803D6D4 @ case 31
	.4byte _0803D6D4 @ case 32
	.4byte _0803D6D4 @ case 33
	.4byte _0803D6D4 @ case 34
	.4byte _0803D6B4 @ case 35
	.4byte _0803D6D4 @ case 36
	.4byte _0803D6D4 @ case 37
	.4byte _0803D6D4 @ case 38
	.4byte _0803D6D4 @ case 39
	.4byte _0803D6D4 @ case 40
	.4byte _0803D6D4 @ case 41
	.4byte _0803D6D4 @ case 42
	.4byte _0803D6D4 @ case 43
	.4byte _0803D6D4 @ case 44
	.4byte _0803D6D4 @ case 45
	.4byte _0803D6C0 @ case 46
	.4byte _0803D6D4 @ case 47
	.4byte _0803D6D4 @ case 48
	.4byte _0803D6D4 @ case 49
	.4byte _0803D6C0 @ case 50
_0803D6B4:
	ldr r0, _0803D6BC
	bl PlayBGM
	b _0803D6E4
	.align 2, 0
_0803D6BC: .4byte 0x00000163
_0803D6C0:
	movs r0, #0xd4
	lsls r0, r0, #1
	bl PlayBGM
	b _0803D6E4
_0803D6CA:
	movs r0, #0xb1
	lsls r0, r0, #1
	bl PlayBGM
	b _0803D6E4
_0803D6D4:
	movs r0, #0xce
	lsls r0, r0, #1
	bl PlayBGM
	b _0803D6E4
_0803D6DE:
	ldr r1, _0803D6F0
	ldr r0, _0803D6F4
	str r0, [r1]
_0803D6E4:
	ldr r1, _0803D6F8
	ldr r0, _0803D6FC
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D6F0: .4byte 0x02023EB8
_0803D6F4: .4byte 0x08288EF2
_0803D6F8: .4byte 0x03005A64
_0803D6FC: .4byte 0x0803D919
	thumb_func_end HandleEndTurn_BattleWon

	thumb_func_start HandleEndTurn_BattleLost
HandleEndTurn_BattleLost: @ 0x0803D700
	push {r4, lr}
	ldr r1, _0803D748
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0803D74C
	ldr r1, [r0]
	ldr r0, _0803D750
	ands r0, r1
	cmp r0, #0
	beq _0803D7BC
	ldr r0, _0803D754
	ands r1, r0
	cmp r1, #0
	beq _0803D784
	ldr r3, _0803D758
	ldrb r2, [r3]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _0803D76C
	ldr r1, _0803D75C
	ldr r0, _0803D760
	str r0, [r1]
	movs r0, #0x7f
	ands r0, r2
	strb r0, [r3]
	ldr r0, _0803D764
	ldr r1, [r0]
	ldr r0, _0803D768
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #8
	orrs r0, r2
	strb r0, [r1]
	b _0803D7C2
	.align 2, 0
_0803D748: .4byte 0x02023D27
_0803D74C: .4byte 0x02022C90
_0803D750: .4byte 0x02000002
_0803D754: .4byte 0x003F0100
_0803D758: .4byte 0x02023FDE
_0803D75C: .4byte 0x02023EB8
_0803D760: .4byte 0x08289F50
_0803D764: .4byte 0x03005AF0
_0803D768: .4byte 0x00000CA9
_0803D76C:
	ldr r1, _0803D77C
	ldr r0, _0803D780
	str r0, [r1]
	movs r0, #0x7f
	ands r0, r2
	strb r0, [r3]
	b _0803D7C2
	.align 2, 0
_0803D77C: .4byte 0x02023EB8
_0803D780: .4byte 0x08288F93
_0803D784:
	ldr r1, _0803D7A8
	ldr r4, _0803D7AC
	ldrb r0, [r4]
	strb r0, [r1]
	movs r0, #0
	bl GetBattlerAtPosition
	ldr r1, _0803D7B0
	strb r0, [r1]
	ldr r1, _0803D7B4
	ldr r0, _0803D7B8
	str r0, [r1]
	ldrb r1, [r4]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r4]
	b _0803D7C2
	.align 2, 0
_0803D7A8: .4byte 0x02022C0C
_0803D7AC: .4byte 0x02023FDE
_0803D7B0: .4byte 0x02023EAF
_0803D7B4: .4byte 0x02023EB8
_0803D7B8: .4byte 0x08288FBD
_0803D7BC:
	ldr r1, _0803D7D0
	ldr r0, _0803D7D4
	str r0, [r1]
_0803D7C2:
	ldr r1, _0803D7D8
	ldr r0, _0803D7DC
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D7D0: .4byte 0x02023EB8
_0803D7D4: .4byte 0x08288EF5
_0803D7D8: .4byte 0x03005A64
_0803D7DC: .4byte 0x0803D919
	thumb_func_end HandleEndTurn_BattleLost

	thumb_func_start HandleEndTurn_RanFromBattle
HandleEndTurn_RanFromBattle: @ 0x0803D7E0
	push {lr}
	ldr r1, _0803D81C
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0803D820
	ldr r2, [r1]
	ldr r0, _0803D824
	ands r0, r2
	cmp r0, #0
	beq _0803D83C
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _0803D83C
	ldr r1, _0803D828
	ldr r0, _0803D82C
	str r0, [r1]
	ldr r1, _0803D830
	movs r0, #9
	strb r0, [r1]
	ldr r0, _0803D834
	ldr r1, [r0]
	ldr r0, _0803D838
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #8
	orrs r0, r2
	strb r0, [r1]
	b _0803D8AA
	.align 2, 0
_0803D81C: .4byte 0x02023D27
_0803D820: .4byte 0x02022C90
_0803D824: .4byte 0x003F0100
_0803D828: .4byte 0x02023EB8
_0803D82C: .4byte 0x08289F49
_0803D830: .4byte 0x02023FDE
_0803D834: .4byte 0x03005AF0
_0803D838: .4byte 0x00000CA9
_0803D83C:
	ldr r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ands r0, r1
	cmp r0, #0
	beq _0803D864
	ldr r1, _0803D858
	ldr r0, _0803D85C
	str r0, [r1]
	ldr r1, _0803D860
	movs r0, #9
	strb r0, [r1]
	b _0803D8AA
	.align 2, 0
_0803D858: .4byte 0x02023EB8
_0803D85C: .4byte 0x08289F49
_0803D860: .4byte 0x02023FDE
_0803D864:
	ldr r1, _0803D884
	ldr r0, _0803D888
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0, #1]
	lsls r0, r0, #0x1b
	lsrs r0, r0, #0x1e
	cmp r0, #1
	beq _0803D894
	cmp r0, #2
	beq _0803D8A4
	ldr r1, _0803D88C
	ldr r0, _0803D890
	b _0803D8A8
	.align 2, 0
_0803D884: .4byte 0x02023FE0
_0803D888: .4byte 0x02023EAF
_0803D88C: .4byte 0x02023EB8
_0803D890: .4byte 0x08289078
_0803D894:
	ldr r1, _0803D89C
	ldr r0, _0803D8A0
	b _0803D8A8
	.align 2, 0
_0803D89C: .4byte 0x02023EB8
_0803D8A0: .4byte 0x08289063
_0803D8A4:
	ldr r1, _0803D8B4
	ldr r0, _0803D8B8
_0803D8A8:
	str r0, [r1]
_0803D8AA:
	ldr r1, _0803D8BC
	ldr r0, _0803D8C0
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0803D8B4: .4byte 0x02023EB8
_0803D8B8: .4byte 0x08289071
_0803D8BC: .4byte 0x03005A64
_0803D8C0: .4byte 0x0803D919
	thumb_func_end HandleEndTurn_RanFromBattle

	thumb_func_start HandleEndTurn_MonFled
HandleEndTurn_MonFled: @ 0x0803D8C4
	ldr r1, _0803D8F8
	movs r0, #0
	strb r0, [r1]
	ldr r1, _0803D8FC
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #7
	strb r0, [r1, #1]
	ldr r2, _0803D900
	ldrb r0, [r2]
	strb r0, [r1, #2]
	ldr r3, _0803D904
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _0803D908
	ldr r0, _0803D90C
	str r0, [r1]
	ldr r1, _0803D910
	ldr r0, _0803D914
	str r0, [r1]
	bx lr
	.align 2, 0
_0803D8F8: .4byte 0x02023D27
_0803D8FC: .4byte 0x02022C0C
_0803D900: .4byte 0x02023EAF
_0803D904: .4byte 0x02023D12
_0803D908: .4byte 0x02023EB8
_0803D90C: .4byte 0x0828907F
_0803D910: .4byte 0x03005A64
_0803D914: .4byte 0x0803D919
	thumb_func_end HandleEndTurn_MonFled

	thumb_func_start HandleEndTurn_FinishBattle
HandleEndTurn_FinishBattle: @ 0x0803D918
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0803D994
	ldrb r0, [r0]
	subs r0, #0xb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0803D92E
	b _0803DA50
_0803D92E:
	ldr r0, _0803D998
	ldr r1, [r0]
	ldr r0, _0803D99C
	ands r1, r0
	cmp r1, #0
	bne _0803D9F6
	ldr r2, _0803D9A0
	strb r1, [r2]
	ldr r0, _0803D9A4
	ldrb r0, [r0]
	cmp r1, r0
	bhs _0803D9F2
	adds r5, r2, #0
	ldr r0, _0803D9A8
	mov r8, r0
	movs r7, #0x64
	ldr r6, _0803D9AC
_0803D950:
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803D9E0
	ldr r4, _0803D9B0
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne _0803D9B4
	ldrb r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7, r0
	adds r0, r0, r6
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	strh r0, [r4, #6]
	ldrb r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7, r0
	adds r0, r0, r6
	movs r1, #2
	adds r2, r4, #0
	adds r2, #8
	bl GetMonData3
	b _0803D9E0
	.align 2, 0
_0803D994: .4byte 0x02023D27
_0803D998: .4byte 0x02022C90
_0803D99C: .4byte 0x023F0B92
_0803D9A0: .4byte 0x02023D08
_0803D9A4: .4byte 0x02023D10
_0803D9A8: .4byte 0x02023D12
_0803D9AC: .4byte 0x02024190
_0803D9B0: .4byte 0x03005A70
_0803D9B4:
	ldrb r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7, r0
	adds r0, r0, r6
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	strh r0, [r4, #0x26]
	ldrb r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7, r0
	adds r0, r0, r6
	movs r1, #2
	adds r2, r4, #0
	adds r2, #0x14
	bl GetMonData3
_0803D9E0:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r1, _0803DA30
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803D950
_0803D9F2:
	bl PutPokemonTodayCaughtOnAir
_0803D9F6:
	ldr r0, _0803DA34
	ldr r0, [r0]
	ldr r1, _0803DA38
	ands r0, r1
	cmp r0, #0
	bne _0803DA12
	ldr r0, _0803DA3C
	ldrb r1, [r0, #5]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803DA12
	bl sub_080EECA4
_0803DA12:
	bl sub_0818619C
	movs r0, #3
	bl BeginFastPaletteFade
	movs r0, #5
	bl FadeOutMapMusic
	ldr r1, _0803DA40
	ldr r0, _0803DA44
	str r0, [r1]
	ldr r1, _0803DA48
	ldr r0, _0803DA4C
	str r0, [r1]
	b _0803DA6A
	.align 2, 0
_0803DA30: .4byte 0x02023D10
_0803DA34: .4byte 0x02022C90
_0803DA38: .4byte 0x023F0B9A
_0803DA3C: .4byte 0x03005A70
_0803DA40: .4byte 0x03005A64
_0803DA44: .4byte 0x0803DA81
_0803DA48: .4byte 0x03005F28
_0803DA4C: .4byte 0x080380FD
_0803DA50:
	ldr r0, _0803DA74
	ldr r0, [r0]
	cmp r0, #0
	bne _0803DA6A
	ldr r1, _0803DA78
	ldr r0, _0803DA7C
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0803DA6A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803DA74: .4byte 0x02023D0C
_0803DA78: .4byte 0x082EC694
_0803DA7C: .4byte 0x02023EB8
	thumb_func_end HandleEndTurn_FinishBattle

	thumb_func_start FreeResetData_ReturnToOvOrDoEvolutions
FreeResetData_ReturnToOvOrDoEvolutions: @ 0x0803DA80
	push {lr}
	ldr r0, _0803DAAC
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0803DAC6
	bl ResetSpriteData
	ldr r0, _0803DAB0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803DAA2
	ldr r0, _0803DAB4
	ldrb r0, [r0]
	cmp r0, #1
	beq _0803DAC0
_0803DAA2:
	ldr r1, _0803DAB8
	ldr r0, _0803DABC
	str r0, [r1]
	b _0803DAE2
	.align 2, 0
_0803DAAC: .4byte 0x02037C74
_0803DAB0: .4byte 0x03005AB4
_0803DAB4: .4byte 0x02023FDE
_0803DAB8: .4byte 0x03005A64
_0803DABC: .4byte 0x0803DBB1
_0803DAC0:
	ldr r1, _0803DAE8
	ldr r0, _0803DAEC
	str r0, [r1]
_0803DAC6:
	bl FreeAllWindowBuffers
	ldr r0, _0803DAF0
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _0803DAE2
	bl FreeMonSpritesGfx
	bl FreeBattleResources
	bl FreeBattleSpritesData
_0803DAE2:
	pop {r0}
	bx r0
	.align 2, 0
_0803DAE8: .4byte 0x03005A64
_0803DAEC: .4byte 0x0803DAF5
_0803DAF0: .4byte 0x02022C90
	thumb_func_end FreeResetData_ReturnToOvOrDoEvolutions

	thumb_func_start TryEvolvePokemon
TryEvolvePokemon: @ 0x0803DAF4
	push {r4, r5, r6, lr}
	ldr r0, _0803DB4C
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _0803DB6E
_0803DB00:
	movs r6, #0
_0803DB02:
	ldrb r2, [r3]
	ldr r0, _0803DB50
	lsls r1, r6, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0803DB60
	bics r2, r1
	strb r2, [r3]
	movs r0, #0x64
	adds r1, r6, #0
	muls r1, r0, r1
	ldr r0, _0803DB54
	adds r5, r1, r0
	adds r0, r5, #0
	movs r1, #0
	bl GetEvolutionTargetSpecies
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0803DB60
	bl FreeAllWindowBuffers
	ldr r0, _0803DB58
	ldr r1, _0803DB5C
	str r1, [r0]
	lsls r3, r6, #0x18
	lsrs r3, r3, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl EvolutionScene
	b _0803DB74
	.align 2, 0
_0803DB4C: .4byte 0x03005AB4
_0803DB50: .4byte 0x082FACB4
_0803DB54: .4byte 0x02024190
_0803DB58: .4byte 0x03005A64
_0803DB5C: .4byte 0x0803DB89
_0803DB60:
	adds r6, #1
	ldr r3, _0803DB7C
	cmp r6, #5
	ble _0803DB02
	ldrb r0, [r3]
	cmp r0, #0
	bne _0803DB00
_0803DB6E:
	ldr r1, _0803DB80
	ldr r0, _0803DB84
	str r0, [r1]
_0803DB74:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803DB7C: .4byte 0x03005AB4
_0803DB80: .4byte 0x03005A64
_0803DB84: .4byte 0x0803DBB1
	thumb_func_end TryEvolvePokemon

	thumb_func_start WaitForEvoSceneToFinish
WaitForEvoSceneToFinish: @ 0x0803DB88
	push {lr}
	ldr r0, _0803DBA0
	ldr r1, [r0, #4]
	ldr r0, _0803DBA4
	cmp r1, r0
	bne _0803DB9A
	ldr r1, _0803DBA8
	ldr r0, _0803DBAC
	str r0, [r1]
_0803DB9A:
	pop {r0}
	bx r0
	.align 2, 0
_0803DBA0: .4byte 0x03002360
_0803DBA4: .4byte 0x080380FD
_0803DBA8: .4byte 0x03005A64
_0803DBAC: .4byte 0x0803DAF5
	thumb_func_end WaitForEvoSceneToFinish

	thumb_func_start ReturnFromBattleToOverworld
ReturnFromBattleToOverworld: @ 0x0803DBB0
	push {r4, r5, r6, lr}
	ldr r6, _0803DC34
	ldr r0, [r6]
	movs r5, #2
	ands r0, r5
	cmp r0, #0
	bne _0803DBCC
	ldr r4, _0803DC38
	adds r0, r4, #0
	bl RandomlyGivePartyPokerus
	adds r0, r4, #0
	bl PartySpreadPokerus
_0803DBCC:
	ldr r4, [r6]
	adds r0, r4, #0
	ands r0, r5
	cmp r0, #0
	beq _0803DBDE
	ldr r0, _0803DC3C
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803DC2C
_0803DBDE:
	ldr r1, _0803DC40
	ldr r5, _0803DC44
	ldrb r0, [r5]
	strh r0, [r1]
	ldr r3, _0803DC48
	ldr r0, _0803DC4C
	adds r2, r3, r0
	ldrb r1, [r2]
	movs r0, #3
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r2]
	ldr r0, _0803DC50
	ldr r0, [r0]
	str r0, [r3]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r4, r0
	cmp r4, #0
	beq _0803DC1E
	ldr r0, _0803DC54
	bl UpdateRoamerHPStatus
	ldrb r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0803DC1A
	cmp r1, #7
	bne _0803DC1E
_0803DC1A:
	bl SetRoamerInactive
_0803DC1E:
	movs r0, #0x5a
	bl m4aSongNumStop
	ldr r0, _0803DC48
	ldr r0, [r0, #8]
	bl SetMainCallback2
_0803DC2C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803DC34: .4byte 0x02022C90
_0803DC38: .4byte 0x02024190
_0803DC3C: .4byte 0x030031C4
_0803DC40: .4byte 0x02037290
_0803DC44: .4byte 0x02023FDE
_0803DC48: .4byte 0x03002360
_0803DC4C: .4byte 0x00000439
_0803DC50: .4byte 0x03005A60
_0803DC54: .4byte 0x020243E8
	thumb_func_end ReturnFromBattleToOverworld

	thumb_func_start RunBattleScriptCommands_PopCallbacksStack
RunBattleScriptCommands_PopCallbacksStack: @ 0x0803DC58
	push {lr}
	ldr r0, _0803DC94
	ldrb r0, [r0]
	subs r0, #0xb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _0803DCA0
	ldr r3, _0803DC98
	ldr r0, [r3]
	ldr r0, [r0, #0xc]
	adds r1, r0, #0
	adds r1, #0x20
	ldrb r0, [r1]
	cmp r0, #0
	beq _0803DC7C
	subs r0, #1
	strb r0, [r1]
_0803DC7C:
	ldr r2, _0803DC9C
	ldr r0, [r3]
	ldr r1, [r0, #0xc]
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	b _0803DCBA
	.align 2, 0
_0803DC94: .4byte 0x02023D27
_0803DC98: .4byte 0x0202414C
_0803DC9C: .4byte 0x03005A64
_0803DCA0:
	ldr r0, _0803DCC0
	ldr r0, [r0]
	cmp r0, #0
	bne _0803DCBA
	ldr r1, _0803DCC4
	ldr r0, _0803DCC8
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0803DCBA:
	pop {r0}
	bx r0
	.align 2, 0
_0803DCC0: .4byte 0x02023D0C
_0803DCC4: .4byte 0x082EC694
_0803DCC8: .4byte 0x02023EB8
	thumb_func_end RunBattleScriptCommands_PopCallbacksStack

	thumb_func_start sub_0803DCCC
sub_0803DCCC: @ 0x0803DCCC
	push {lr}
	ldr r0, _0803DCEC
	ldr r0, [r0]
	cmp r0, #0
	bne _0803DCE8
	ldr r1, _0803DCF0
	ldr r0, _0803DCF4
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0803DCE8:
	pop {r0}
	bx r0
	.align 2, 0
_0803DCEC: .4byte 0x02023D0C
_0803DCF0: .4byte 0x082EC694
_0803DCF4: .4byte 0x02023EB8
	thumb_func_end sub_0803DCCC

	thumb_func_start HandleAction_UseMove
HandleAction_UseMove: @ 0x0803DCF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #4
	str r0, [sp]
	ldr r6, _0803DD38
	ldr r1, _0803DD3C
	ldr r0, _0803DD40
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6]
	ldr r1, _0803DD44
	ldr r3, [r1]
	adds r0, r3, #0
	adds r0, #0x91
	ldrb r2, [r0]
	ldr r1, _0803DD48
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r2, r0
	cmp r2, #0
	beq _0803DD50
	ldr r1, _0803DD4C
	movs r0, #0xc
	b _0803E47C
	.align 2, 0
_0803DD38: .4byte 0x02023EAF
_0803DD3C: .4byte 0x02023D22
_0803DD40: .4byte 0x02023D26
_0803DD44: .4byte 0x02024140
_0803DD48: .4byte 0x082FACB4
_0803DD4C: .4byte 0x02023D27
_0803DD50:
	ldr r1, _0803DDC8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803DDCC
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r5, _0803DDD0
	adds r0, r3, r5
	strb r2, [r0]
	ldr r0, _0803DDD4
	strb r2, [r0]
	ldr r0, _0803DDD8
	strb r2, [r0]
	ldr r0, _0803DDDC
	strb r2, [r0, #6]
	ldr r2, _0803DDE0
	ldr r0, _0803DDE4
	mov sb, r0
	ldrb r0, [r6]
	ldr r3, _0803DDE8
	ldr r1, [r3]
	adds r0, r0, r1
	adds r0, #0x80
	ldrb r0, [r0]
	mov r5, sb
	strb r0, [r5]
	strb r0, [r2]
	ldr r1, _0803DDEC
	ldrb r4, [r6]
	lsls r0, r4, #4
	adds r3, r0, r1
	ldrb r1, [r3]
	lsls r0, r1, #0x1d
	mov r8, r2
	cmp r0, #0
	bge _0803DDFC
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r2, _0803DDF0
	ldr r1, _0803DDF4
	movs r0, #0xa5
	strh r0, [r1]
	strh r0, [r2]
	ldr r2, _0803DDF8
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xa5
	movs r1, #0
	bl GetMoveTarget
	ldrb r1, [r6]
	ldr r3, _0803DDE8
	ldr r2, [r3]
	b _0803DF56
	.align 2, 0
_0803DDC8: .4byte 0x02023EB5
_0803DDCC: .4byte 0x02024118
_0803DDD0: .4byte 0x000001A3
_0803DDD4: .4byte 0x02023F20
_0803DDD8: .4byte 0x02023EB6
_0803DDDC: .4byte 0x02023FD6
_0803DDE0: .4byte 0x02023E8C
_0803DDE4: .4byte 0x02023E8D
_0803DDE8: .4byte 0x02024140
_0803DDEC: .4byte 0x02023FE0
_0803DDF0: .4byte 0x02023E8E
_0803DDF4: .4byte 0x02023E90
_0803DDF8: .4byte 0x02023F24
_0803DDFC:
	ldr r5, _0803DE34
	mov sl, r5
	movs r0, #0x58
	adds r5, r4, #0
	muls r5, r0, r5
	mov r0, sl
	adds r0, #0x50
	adds r0, r5, r0
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	bne _0803DE22
	movs r7, #0x80
	lsls r7, r7, #0xf
	ands r7, r1
	cmp r7, #0
	beq _0803DE44
_0803DE22:
	ldr r3, _0803DE38
	ldr r2, _0803DE3C
	ldr r1, _0803DE40
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	strh r0, [r3]
	b _0803DF7C
	.align 2, 0
_0803DE34: .4byte 0x02023D28
_0803DE38: .4byte 0x02023E8E
_0803DE3C: .4byte 0x02023E90
_0803DE40: .4byte 0x02023F0C
_0803DE44:
	ldr r1, _0803DE98
	mov ip, r1
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	add r0, ip
	ldrh r3, [r0, #6]
	adds r1, r3, #0
	cmp r1, #0
	beq _0803DF1C
	ldrb r2, [r0, #0xc]
	lsls r0, r2, #1
	adds r0, r0, r5
	mov r4, sl
	adds r4, #0xc
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r1, r0
	bne _0803DEA8
	ldr r2, _0803DE9C
	ldr r0, _0803DEA0
	strh r3, [r0]
	strh r3, [r2]
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0, #0xc]
	mov r3, sb
	strb r0, [r3]
	mov r5, r8
	strb r0, [r5]
	ldrh r0, [r2]
	movs r1, #0
	bl GetMoveTarget
	ldrb r1, [r6]
	ldr r3, _0803DEA4
	ldr r2, [r3]
	b _0803DF56
	.align 2, 0
_0803DE98: .4byte 0x02023F60
_0803DE9C: .4byte 0x02023E8E
_0803DEA0: .4byte 0x02023E90
_0803DEA4: .4byte 0x02024140
_0803DEA8:
	cmp r1, #0
	beq _0803DF1C
	cmp r1, r0
	beq _0803DF1C
	mov r5, sb
	strb r2, [r5]
	mov r0, r8
	strb r2, [r0]
	ldr r3, _0803DF10
	ldr r2, _0803DF14
	ldrb r0, [r0]
	lsls r0, r0, #1
	ldrb r1, [r6]
	movs r5, #0x58
	muls r1, r5, r1
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r2]
	strh r0, [r3]
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	strh r7, [r0, #6]
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	strb r2, [r0, #0xc]
	ldrb r0, [r6]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, ip
	ldrb r2, [r1, #0xe]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #0xe]
	ldrh r0, [r3]
	movs r1, #0
	bl GetMoveTarget
	ldrb r1, [r6]
	ldr r3, _0803DF18
	ldr r2, [r3]
	b _0803DF56
	.align 2, 0
_0803DF10: .4byte 0x02023E8E
_0803DF14: .4byte 0x02023E90
_0803DF18: .4byte 0x02024140
_0803DF1C:
	ldr r3, _0803DF5C
	mov r5, r8
	ldrb r0, [r5]
	lsls r0, r0, #1
	ldr r4, _0803DF60
	ldrb r2, [r4]
	movs r1, #0x58
	muls r1, r2, r1
	adds r0, r0, r1
	adds r3, #0xc
	adds r0, r0, r3
	ldr r1, _0803DF64
	lsls r2, r2, #1
	adds r2, r2, r1
	ldrh r3, [r0]
	ldrh r2, [r2]
	cmp r3, r2
	beq _0803DF74
	ldr r1, _0803DF68
	ldr r0, _0803DF6C
	strh r3, [r0]
	strh r3, [r1]
	ldrh r0, [r1]
	movs r1, #0
	bl GetMoveTarget
	ldrb r1, [r4]
	ldr r2, _0803DF70
	ldr r2, [r2]
_0803DF56:
	adds r1, r1, r2
	strb r0, [r1, #0xc]
	b _0803DF7C
	.align 2, 0
_0803DF5C: .4byte 0x02023D28
_0803DF60: .4byte 0x02023EAF
_0803DF64: .4byte 0x02023F18
_0803DF68: .4byte 0x02023E8E
_0803DF6C: .4byte 0x02023E90
_0803DF70: .4byte 0x02024140
_0803DF74:
	ldr r1, _0803DFA8
	ldr r0, _0803DFAC
	strh r3, [r0]
	strh r3, [r1]
_0803DF7C:
	ldr r2, _0803DFB0
	ldr r1, _0803DFB4
	ldrb r3, [r1]
	movs r0, #0x58
	muls r0, r3, r0
	adds r0, r0, r2
	ldrh r0, [r0, #0x28]
	mov r8, r1
	cmp r0, #0
	beq _0803DFC4
	adds r0, r3, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803DFBC
	ldr r0, _0803DFB8
	ldr r1, _0803DFA8
	ldrh r1, [r1]
	strh r1, [r0, #0x22]
	b _0803DFC4
	.align 2, 0
_0803DFA8: .4byte 0x02023E8E
_0803DFAC: .4byte 0x02023E90
_0803DFB0: .4byte 0x02023D28
_0803DFB4: .4byte 0x02023EAF
_0803DFB8: .4byte 0x03005A70
_0803DFBC:
	ldr r0, _0803E028
	ldr r1, _0803E02C
	ldrh r1, [r1]
	strh r1, [r0, #0x24]
_0803DFC4:
	mov r1, r8
	ldrb r0, [r1]
	bl GetBattlerSide
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _0803E030
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r5, r0, r1
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _0803E040
	ldr r2, _0803E034
	ldr r0, _0803E02C
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #6]
	cmp r0, #0
	bne _0803E040
	mov r3, r8
	ldrb r0, [r3]
	bl GetBattlerSide
	adds r4, r0, #0
	ldrb r0, [r5, #9]
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0803E040
	ldr r1, _0803E038
	ldrb r2, [r5, #9]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _0803E040
	ldr r0, _0803E03C
	strb r2, [r0]
	b _0803E3AA
	.align 2, 0
_0803E028: .4byte 0x03005A70
_0803E02C: .4byte 0x02023E8E
_0803E030: .4byte 0x02023F38
_0803E034: .4byte 0x082ED220
_0803E038: .4byte 0x02023D28
_0803E03C: .4byte 0x02023EB0
_0803E040:
	ldr r0, _0803E15C
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r5, _0803E160
	mov r8, r5
	cmp r0, #0
	bne _0803E052
	b _0803E320
_0803E052:
	ldr r1, _0803E164
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r5, [r0, #8]
	cmp r5, #0
	beq _0803E064
	b _0803E270
_0803E064:
	ldr r2, _0803E168
	ldr r0, _0803E16C
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r4, r0, r2
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _0803E080
	ldrb r0, [r4, #6]
	cmp r0, #0x10
	bne _0803E080
	b _0803E270
_0803E080:
	ldr r3, _0803E170
	ldr r2, _0803E160
	ldrb r6, [r2]
	ldr r0, _0803E174
	ldr r0, [r0]
	adds r0, r6, r0
	ldrb r1, [r0, #0xc]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r0, [r0]
	mov r8, r2
	cmp r0, #0x1f
	bne _0803E0A0
	b _0803E270
_0803E0A0:
	ldrb r0, [r4, #2]
	cmp r0, #0xd
	beq _0803E0A8
	b _0803E270
_0803E0A8:
	adds r0, r6, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _0803E178
	strb r5, [r1]
	ldr r0, _0803E17C
	ldrb r0, [r0]
	cmp r5, r0
	bhs _0803E120
	adds r4, r1, #0
_0803E0C0:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r0
	beq _0803E10E
	ldr r0, _0803E160
	ldrb r1, [r0]
	ldr r0, _0803E174
	ldr r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1, #0xc]
	ldrb r1, [r4]
	cmp r0, r1
	beq _0803E10E
	ldr r1, _0803E170
	ldrb r2, [r4]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x1f
	bne _0803E10E
	adds r0, r2, #0
	bl GetBattlerTurnOrderNum
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [sp]
	cmp r0, r3
	bhs _0803E10E
	ldrb r0, [r4]
	bl GetBattlerTurnOrderNum
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
_0803E10E:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _0803E17C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803E0C0
_0803E120:
	ldr r5, [sp]
	cmp r5, #4
	beq _0803E128
	b _0803E222
_0803E128:
	ldr r2, _0803E168
	ldr r0, _0803E180
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #6]
	ands r5, r0
	cmp r5, #0
	beq _0803E1A8
	ldr r0, _0803E160
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E188
	bl Random
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0803E184
	movs r0, #1
	b _0803E19A
	.align 2, 0
_0803E15C: .4byte 0x02022C90
_0803E160: .4byte 0x02023EAF
_0803E164: .4byte 0x02023F38
_0803E168: .4byte 0x082ED220
_0803E16C: .4byte 0x02023E8E
_0803E170: .4byte 0x02023D28
_0803E174: .4byte 0x02024140
_0803E178: .4byte 0x02023D08
_0803E17C: .4byte 0x02023D10
_0803E180: .4byte 0x02023E90
_0803E184:
	movs r0, #3
	b _0803E19A
_0803E188:
	bl Random
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0803E198
	movs r0, #0
	b _0803E19A
_0803E198:
	movs r0, #2
_0803E19A:
	bl GetBattlerAtPosition
	ldr r1, _0803E1A4
	strb r0, [r1]
	b _0803E1B8
	.align 2, 0
_0803E1A4: .4byte 0x02023EB0
_0803E1A8:
	ldr r2, _0803E1F0
	ldr r0, _0803E1F4
	ldrb r0, [r0]
	ldr r1, _0803E1F8
	ldr r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0, #0xc]
	strb r0, [r2]
_0803E1B8:
	ldr r7, _0803E1FC
	ldrb r0, [r7]
	ldr r1, _0803E200
	mov r8, r1
	ldr r5, _0803E1F0
	ldrb r1, [r5]
	lsls r1, r1, #2
	add r1, r8
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0803E1D2
	b _0803E3AA
_0803E1D2:
	ldr r6, _0803E1F4
	ldrb r0, [r6]
	bl GetBattlerSide
	adds r4, r0, #0
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0803E204
	ldrb r0, [r5]
	b _0803E398
	.align 2, 0
_0803E1F0: .4byte 0x02023EB0
_0803E1F4: .4byte 0x02023EAF
_0803E1F8: .4byte 0x02024140
_0803E1FC: .4byte 0x02023EB4
_0803E200: .4byte 0x082FACB4
_0803E204:
	ldrb r0, [r6]
	bl GetBattlerPosition
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	strb r0, [r5]
	ldrb r1, [r7]
	ldrb r2, [r5]
	lsls r0, r2, #2
	add r0, r8
	b _0803E38E
_0803E222:
	ldr r4, _0803E25C
	ldr r0, _0803E260
	ldr r3, [sp]
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r4]
	ldrb r0, [r4]
	ldr r2, _0803E264
	movs r1, #0x58
	muls r1, r0, r1
	adds r1, r1, r2
	adds r1, #0x20
	ldrb r1, [r1]
	bl RecordAbilityBattle
	ldr r2, _0803E268
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	strb r1, [r0]
	ldr r1, _0803E26C
	ldrb r0, [r4]
	strb r0, [r1]
	b _0803E3AA
	.align 2, 0
_0803E25C: .4byte 0x02023D08
_0803E260: .4byte 0x02023D22
_0803E264: .4byte 0x02023D28
_0803E268: .4byte 0x02024020
_0803E26C: .4byte 0x02023EB0
_0803E270:
	ldr r0, _0803E2B4
	ldr r0, [r0]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _0803E320
	ldr r2, _0803E2B8
	ldr r0, _0803E2BC
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0, #6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0803E320
	mov r5, r8
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E2C4
	bl Random
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _0803E2C0
	movs r0, #1
	b _0803E2D6
	.align 2, 0
_0803E2B4: .4byte 0x02022C90
_0803E2B8: .4byte 0x082ED220
_0803E2BC: .4byte 0x02023E90
_0803E2C0:
	movs r0, #3
	b _0803E2D6
_0803E2C4:
	bl Random
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _0803E2D4
	movs r0, #0
	b _0803E2D6
_0803E2D4:
	movs r0, #2
_0803E2D6:
	bl GetBattlerAtPosition
	ldr r1, _0803E310
	strb r0, [r1]
	ldr r0, _0803E314
	ldrb r1, [r0]
	ldr r2, _0803E318
	ldr r5, _0803E310
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0803E3AA
	ldr r0, _0803E31C
	ldrb r0, [r0]
	bl GetBattlerSide
	adds r4, r0, #0
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0803E3AA
	ldrb r0, [r5]
	b _0803E398
	.align 2, 0
_0803E310: .4byte 0x02023EB0
_0803E314: .4byte 0x02023EB4
_0803E318: .4byte 0x082FACB4
_0803E31C: .4byte 0x02023EAF
_0803E320:
	ldr r5, _0803E360
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, _0803E364
	ldr r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0, #0xc]
	strb r0, [r5]
	ldr r6, _0803E368
	ldrb r1, [r6]
	ldr r7, _0803E36C
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0803E3AA
	ldrb r0, [r2]
	bl GetBattlerSide
	adds r4, r0, #0
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0803E370
	ldrb r0, [r5]
	b _0803E398
	.align 2, 0
_0803E360: .4byte 0x02023EB0
_0803E364: .4byte 0x02024140
_0803E368: .4byte 0x02023EB4
_0803E36C: .4byte 0x082FACB4
_0803E370:
	mov r1, r8
	ldrb r0, [r1]
	bl GetBattlerPosition
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	strb r0, [r5]
	ldrb r1, [r6]
	ldrb r2, [r5]
	lsls r0, r2, #2
	adds r0, r0, r7
_0803E38E:
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0803E3AA
	adds r0, r2, #0
_0803E398:
	bl GetBattlerPosition
	movs r1, #2
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	strb r0, [r5]
_0803E3AA:
	ldr r0, _0803E3E0
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xa
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _0803E448
	ldr r0, _0803E3E4
	ldr r4, _0803E3E8
	ldrb r2, [r4]
	lsls r1, r2, #4
	adds r1, r1, r0
	ldrb r0, [r1, #2]
	lsls r0, r0, #0x1b
	cmp r0, #0
	bge _0803E448
	ldr r1, _0803E3EC
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _0803E3F4
	ldr r1, _0803E3F0
	movs r0, #0xc
	b _0803E47C
	.align 2, 0
_0803E3E0: .4byte 0x02022C90
_0803E3E4: .4byte 0x02023FE0
_0803E3E8: .4byte 0x02023EAF
_0803E3EC: .4byte 0x02023D28
_0803E3F0: .4byte 0x02023D27
_0803E3F4:
	ldr r3, _0803E420
	lsls r0, r2, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _0803E42C
	ldr r1, _0803E424
	movs r2, #0
	movs r0, #4
	strb r0, [r1, #5]
	ldr r1, _0803E428
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	str r2, [r0]
	b _0803E464
	.align 2, 0
_0803E420: .4byte 0x02023ED4
_0803E424: .4byte 0x02023FD6
_0803E428: .4byte 0x02023EB8
_0803E42C:
	ldr r1, _0803E43C
	movs r0, #4
	strb r0, [r1, #5]
	ldr r1, _0803E440
	ldr r0, _0803E444
	str r0, [r1]
	b _0803E464
	.align 2, 0
_0803E43C: .4byte 0x02023FD6
_0803E440: .4byte 0x02023EB8
_0803E444: .4byte 0x08289C35
_0803E448:
	ldr r4, _0803E490
	ldr r3, _0803E494
	ldr r2, _0803E498
	ldr r0, _0803E49C
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r4]
_0803E464:
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0803E478
	ldr r0, _0803E4A0
	ldrb r0, [r0]
	bl BattleArena_AddMindPoints
_0803E478:
	ldr r1, _0803E4A4
	movs r0, #0xa
_0803E47C:
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E490: .4byte 0x02023EB8
_0803E494: .4byte 0x08286C30
_0803E498: .4byte 0x082ED220
_0803E49C: .4byte 0x02023E8E
_0803E4A0: .4byte 0x02023EAF
_0803E4A4: .4byte 0x02023D27
	thumb_func_end HandleAction_UseMove

	thumb_func_start HandleAction_Switch
HandleAction_Switch: @ 0x0803E4A8
	push {r4, lr}
	ldr r3, _0803E514
	ldr r1, _0803E518
	ldr r0, _0803E51C
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r0, _0803E520
	movs r2, #0
	strh r2, [r0]
	ldr r0, _0803E524
	strh r2, [r0]
	ldr r1, _0803E528
	ldrb r0, [r3]
	adds r0, r0, r1
	strb r2, [r0]
	ldr r1, _0803E52C
	ldrb r0, [r3]
	adds r0, r0, r1
	strb r2, [r0]
	ldr r2, _0803E530
	movs r0, #0xfd
	strb r0, [r2]
	movs r0, #7
	strb r0, [r2, #1]
	ldrb r4, [r3]
	strb r4, [r2, #2]
	ldrb r0, [r3]
	ldr r1, _0803E534
	ldr r1, [r1]
	adds r0, r0, r1
	adds r0, #0x58
	ldrb r0, [r0]
	strb r0, [r2, #3]
	movs r0, #0xff
	strb r0, [r2, #4]
	ldr r0, _0803E538
	strb r4, [r0, #0x17]
	ldr r1, _0803E53C
	ldr r0, _0803E540
	str r0, [r1]
	ldr r1, _0803E544
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, _0803E548
	ldrb r0, [r1, #2]
	cmp r0, #0xfe
	bhi _0803E50E
	adds r0, #1
	strb r0, [r1, #2]
_0803E50E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803E514: .4byte 0x02023EAF
_0803E518: .4byte 0x02023D22
_0803E51C: .4byte 0x02023D26
_0803E520: .4byte 0x02022AC8
_0803E524: .4byte 0x02022ACA
_0803E528: .4byte 0x02024150
_0803E52C: .4byte 0x02024154
_0803E530: .4byte 0x02022C0C
_0803E534: .4byte 0x02024140
_0803E538: .4byte 0x02024118
_0803E53C: .4byte 0x02023EB8
_0803E540: .4byte 0x0828909D
_0803E544: .4byte 0x02023D27
_0803E548: .4byte 0x03005A70
	thumb_func_end HandleAction_Switch

	thumb_func_start HandleAction_UseItem
HandleAction_UseItem: @ 0x0803E54C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _0803E5AC
	ldr r2, _0803E5B0
	ldr r1, _0803E5B4
	ldr r0, _0803E5B8
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	strb r0, [r4]
	ldr r0, _0803E5BC
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803E5C0
	strh r1, [r0]
	ldrb r0, [r4]
	bl ClearFuryCutterDestinyBondGrudge
	ldr r5, _0803E5C4
	ldr r2, _0803E5C8
	ldrb r1, [r4]
	lsls r1, r1, #9
	adds r0, r2, #1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r2, #2
	adds r1, r1, r2
	ldrb r0, [r1]
	lsls r0, r0, #8
	orrs r3, r0
	strh r3, [r5]
	cmp r3, #0xc
	bhi _0803E5D8
	ldr r2, _0803E5CC
	ldr r1, _0803E5D0
	ldrh r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _0803E5D4
	mov sl, r0
	b _0803E836
	.align 2, 0
_0803E5AC: .4byte 0x02023EAF
_0803E5B0: .4byte 0x02023EB0
_0803E5B4: .4byte 0x02023D22
_0803E5B8: .4byte 0x02023D26
_0803E5BC: .4byte 0x02022AC8
_0803E5C0: .4byte 0x02022ACA
_0803E5C4: .4byte 0x02023EAC
_0803E5C8: .4byte 0x02023508
_0803E5CC: .4byte 0x02023EB8
_0803E5D0: .4byte 0x0828A290
_0803E5D4: .4byte 0x02023D27
_0803E5D8:
	adds r0, r3, #0
	subs r0, #0x50
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0803E600
	ldr r0, _0803E5F4
	ldr r1, _0803E5F8
	ldr r1, [r1]
	str r1, [r0]
	ldr r1, _0803E5FC
	mov sl, r1
	b _0803E836
	.align 2, 0
_0803E5F4: .4byte 0x02023EB8
_0803E5F8: .4byte 0x0828A2DC
_0803E5FC: .4byte 0x02023D27
_0803E600:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E628
	ldr r0, _0803E61C
	ldr r1, _0803E620
	ldr r1, [r1]
	str r1, [r0]
	ldr r2, _0803E624
	mov sl, r2
	b _0803E836
	.align 2, 0
_0803E61C: .4byte 0x02023EB8
_0803E620: .4byte 0x0828A2C4
_0803E624: .4byte 0x02023D27
_0803E628:
	ldr r3, _0803E660
	ldrb r0, [r4]
	strb r0, [r3, #0x17]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x19
	ldr r2, _0803E664
	ldr r1, [r2]
	adds r0, r0, r1
	adds r0, #0xc4
	ldrb r0, [r0]
	subs r0, #1
	mov r8, r4
	ldr r1, _0803E668
	mov sb, r1
	ldr r6, _0803E66C
	mov ip, r3
	adds r7, r2, #0
	ldr r2, _0803E670
	mov sl, r2
	cmp r0, #4
	bls _0803E654
	b _0803E81E
_0803E654:
	lsls r0, r0, #2
	ldr r1, _0803E674
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803E660: .4byte 0x02024118
_0803E664: .4byte 0x02024140
_0803E668: .4byte 0x02023EB8
_0803E66C: .4byte 0x0828A2C4
_0803E670: .4byte 0x02023D27
_0803E674: .4byte 0x0803E678
_0803E678: @ jump table
	.4byte _0803E81E @ case 0
	.4byte _0803E81E @ case 1
	.4byte _0803E68C @ case 2
	.4byte _0803E720 @ case 3
	.4byte _0803E7F0 @ case 4
_0803E68C:
	ldr r5, _0803E6C4
	movs r0, #0
	strb r0, [r5, #5]
	ldr r2, _0803E6C8
	ldrb r0, [r2]
	lsrs r0, r0, #1
	ldr r1, [r7]
	adds r0, r0, r1
	adds r0, #0xc6
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	mov r8, r2
	cmp r0, #0
	beq _0803E6D8
	movs r0, #0x3e
	ands r0, r1
	ldr r1, _0803E6CC
	mov sb, r1
	ldr r6, _0803E6D0
	ldr r2, _0803E6D4
	mov sl, r2
	cmp r0, #0
	bne _0803E6BE
	b _0803E81E
_0803E6BE:
	movs r0, #5
	strb r0, [r5, #5]
	b _0803E81E
	.align 2, 0
_0803E6C4: .4byte 0x02023FD6
_0803E6C8: .4byte 0x02023EAF
_0803E6CC: .4byte 0x02023EB8
_0803E6D0: .4byte 0x0828A2C4
_0803E6D4: .4byte 0x02023D27
_0803E6D8:
	ldr r0, _0803E714
	mov sb, r0
	ldr r6, _0803E718
	ldr r1, _0803E71C
	mov sl, r1
	mov r4, r8
	adds r3, r7, #0
	adds r2, r5, #0
_0803E6E8:
	ldrb r1, [r4]
	lsrs r1, r1, #1
	ldr r0, [r3]
	adds r1, r1, r0
	adds r1, #0xc6
	ldrb r0, [r1]
	lsrs r0, r0, #1
	strb r0, [r1]
	ldrb r0, [r2, #5]
	adds r0, #1
	strb r0, [r2, #5]
	ldrb r0, [r4]
	lsrs r0, r0, #1
	ldr r1, [r3]
	adds r0, r0, r1
	adds r0, #0xc6
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803E6E8
	b _0803E81E
	.align 2, 0
_0803E714: .4byte 0x02023EB8
_0803E718: .4byte 0x0828A2C4
_0803E71C: .4byte 0x02023D27
_0803E720:
	ldr r3, _0803E754
	movs r0, #4
	strb r0, [r3, #5]
	ldr r2, _0803E758
	ldrb r0, [r2]
	lsrs r0, r0, #1
	ldr r1, [r7]
	adds r0, r0, r1
	adds r6, r0, #0
	adds r6, #0xc6
	ldrb r1, [r6]
	movs r0, #0x80
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	mov r8, r2
	cmp r5, #0
	beq _0803E768
	movs r0, #5
	strb r0, [r3, #5]
	ldr r2, _0803E75C
	mov sb, r2
	ldr r6, _0803E760
	ldr r0, _0803E764
	mov sl, r0
	b _0803E81E
	.align 2, 0
_0803E754: .4byte 0x02023FD6
_0803E758: .4byte 0x02023EAF
_0803E75C: .4byte 0x02023EB8
_0803E760: .4byte 0x0828A2C4
_0803E764: .4byte 0x02023D27
_0803E768:
	ldr r3, _0803E7DC
	movs r4, #0xfd
	strb r4, [r3]
	movs r0, #5
	strb r0, [r3, #1]
	movs r2, #1
	strb r2, [r3, #2]
	movs r0, #0xff
	strb r0, [r3, #3]
	ldr r1, _0803E7E0
	strb r4, [r1]
	strb r5, [r1, #1]
	movs r0, #0xd2
	strb r0, [r1, #2]
	strb r5, [r1, #3]
	subs r0, #0xd3
	strb r0, [r1, #4]
	ldrb r0, [r6]
	ands r2, r0
	ldr r1, _0803E7E4
	mov sb, r1
	ldr r6, _0803E7E8
	ldr r0, _0803E7EC
	mov sl, r0
	cmp r2, #0
	bne _0803E7CC
	mov r5, r8
	adds r4, r7, #0
	adds r2, r3, #0
_0803E7A2:
	ldrb r1, [r5]
	lsrs r1, r1, #1
	ldr r0, [r4]
	adds r1, r1, r0
	adds r1, #0xc6
	ldrb r0, [r1]
	lsrs r0, r0, #1
	strb r0, [r1]
	ldrb r0, [r2, #2]
	adds r0, #1
	strb r0, [r2, #2]
	ldrb r0, [r5]
	lsrs r0, r0, #1
	ldr r1, [r4]
	adds r0, r0, r1
	adds r0, #0xc6
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0803E7A2
_0803E7CC:
	ldrb r0, [r3, #2]
	adds r0, #0xe
	movs r1, #0
	mov r2, ip
	strb r0, [r2, #0x10]
	strb r1, [r2, #0x11]
	b _0803E81E
	.align 2, 0
_0803E7DC: .4byte 0x02022C0C
_0803E7E0: .4byte 0x02022C1C
_0803E7E4: .4byte 0x02023EB8
_0803E7E8: .4byte 0x0828A2C4
_0803E7EC: .4byte 0x02023D27
_0803E7F0:
	ldr r0, _0803E804
	ldr r1, [r0]
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0803E80C
	ldr r1, _0803E808
	movs r0, #2
	strb r0, [r1, #5]
	b _0803E810
	.align 2, 0
_0803E804: .4byte 0x02022C90
_0803E808: .4byte 0x02023FD6
_0803E80C:
	ldr r0, _0803E84C
	strb r1, [r0, #5]
_0803E810:
	ldr r0, _0803E850
	mov r8, r0
	ldr r1, _0803E854
	mov sb, r1
	ldr r6, _0803E858
	ldr r2, _0803E85C
	mov sl, r2
_0803E81E:
	mov r1, r8
	ldrb r0, [r1]
	lsrs r0, r0, #1
	ldr r1, [r7]
	adds r0, r0, r1
	adds r0, #0xc4
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	mov r2, sb
	str r0, [r2]
_0803E836:
	movs r0, #0xa
	mov r1, sl
	strb r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E84C: .4byte 0x02023FD6
_0803E850: .4byte 0x02023EAF
_0803E854: .4byte 0x02023EB8
_0803E858: .4byte 0x0828A2C4
_0803E85C: .4byte 0x02023D27
	thumb_func_end HandleAction_UseItem

	thumb_func_start TryRunFromBattle
TryRunFromBattle: @ 0x0803E860
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r7, #0
	ldr r1, _0803E88C
	movs r0, #0x58
	muls r0, r5, r0
	adds r1, r0, r1
	ldrh r0, [r1, #0x2e]
	cmp r0, #0xaf
	bne _0803E894
	ldr r1, _0803E890
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #7]
	b _0803E89E
	.align 2, 0
_0803E88C: .4byte 0x02023D28
_0803E890: .4byte 0x020240A8
_0803E894:
	ldrh r0, [r1, #0x2e]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0803E89E:
	ldr r0, _0803E8CC
	strb r5, [r0]
	cmp r1, #0x25
	bne _0803E8DC
	ldr r2, _0803E8D0
	ldr r1, _0803E8D4
	movs r0, #0x58
	muls r0, r5, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x2e]
	strh r0, [r2]
	ldr r0, _0803E8D8
	lsls r2, r5, #4
	adds r2, r2, r0
	ldrb r1, [r2, #1]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #1]
	b _0803E9B0
	.align 2, 0
_0803E8CC: .4byte 0x02023EB3
_0803E8D0: .4byte 0x02023EAC
_0803E8D4: .4byte 0x02023D28
_0803E8D8: .4byte 0x02023FE0
_0803E8DC:
	ldr r0, _0803E968
	mov sl, r0
	movs r2, #0x58
	mov sb, r2
	mov r0, sb
	muls r0, r5, r0
	add r0, sl
	mov r8, r0
	adds r0, #0x20
	ldrb r6, [r0]
	cmp r6, #0x32
	bne _0803E99C
	bl CurrentBattlePyramidLocation
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803E978
	ldr r4, _0803E96C
	ldr r1, [r4]
	adds r1, #0x6c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	bl GetPyramidRunMultiplier
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	mov r2, r8
	ldrh r0, [r2, #6]
	muls r0, r1, r0
	movs r2, #1
	adds r1, r5, #0
	eors r1, r2
	mov r2, sb
	muls r2, r1, r2
	adds r1, r2, #0
	add r1, sl
	ldrh r1, [r1, #6]
	bl __divsi3
	ldr r1, [r4]
	adds r1, #0x6c
	ldrb r2, [r1]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl Random
	movs r1, #0xff
	ands r1, r0
	cmp r4, r1
	bhi _0803E94C
	b _0803EA52
_0803E94C:
	ldr r0, _0803E970
	strb r6, [r0]
	ldr r0, _0803E974
	lsls r2, r5, #4
	adds r2, r2, r0
	ldrb r1, [r2, #1]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	b _0803E9B0
	.align 2, 0
_0803E968: .4byte 0x02023D28
_0803E96C: .4byte 0x02024140
_0803E970: .4byte 0x02023EAE
_0803E974: .4byte 0x02023FE0
_0803E978:
	ldr r0, _0803E994
	strb r6, [r0]
	ldr r0, _0803E998
	lsls r2, r5, #4
	adds r2, r2, r0
	ldrb r1, [r2, #1]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	b _0803E9B0
	.align 2, 0
_0803E994: .4byte 0x02023EAE
_0803E998: .4byte 0x02023FE0
_0803E99C:
	ldr r1, _0803E9B8
	ldr r2, [r1]
	ldr r0, _0803E9BC
	ands r0, r2
	cmp r0, #0
	beq _0803E9C0
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _0803E9C0
_0803E9B0:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	b _0803EA52
	.align 2, 0
_0803E9B8: .4byte 0x02022C90
_0803E9BC: .4byte 0x043F0100
_0803E9C0:
	ldr r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0803EA46
	bl CurrentBattlePyramidLocation
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803E9FC
	bl GetPyramidRunMultiplier
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r4, _0803E9F8
	movs r3, #0x58
	adds r0, r5, #0
	muls r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0, #6]
	muls r0, r1, r0
	movs r2, #1
	adds r1, r5, #0
	eors r1, r2
	muls r1, r3, r1
	adds r1, r1, r4
	b _0803EA1A
	.align 2, 0
_0803E9F8: .4byte 0x02023D28
_0803E9FC:
	ldr r3, _0803EA74
	movs r2, #0x58
	adds r0, r5, #0
	muls r0, r2, r0
	adds r4, r0, r3
	movs r1, #1
	adds r0, r5, #0
	eors r0, r1
	muls r0, r2, r0
	adds r1, r0, r3
	ldrh r0, [r4, #6]
	ldrh r2, [r1, #6]
	cmp r0, r2
	bhs _0803EA40
	lsls r0, r0, #7
_0803EA1A:
	ldrh r1, [r1, #6]
	bl __divsi3
	ldr r1, _0803EA78
	ldr r1, [r1]
	adds r1, #0x6c
	ldrb r2, [r1]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl Random
	movs r1, #0xff
	ands r1, r0
	cmp r4, r1
	bls _0803EA46
_0803EA40:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
_0803EA46:
	ldr r0, _0803EA78
	ldr r1, [r0]
	adds r1, #0x6c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803EA52:
	cmp r7, #0
	beq _0803EA64
	ldr r1, _0803EA7C
	ldr r0, _0803EA80
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0803EA84
	movs r0, #4
	strb r0, [r1]
_0803EA64:
	adds r0, r7, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803EA74: .4byte 0x02023D28
_0803EA78: .4byte 0x02024140
_0803EA7C: .4byte 0x02023D26
_0803EA80: .4byte 0x02023D10
_0803EA84: .4byte 0x02023FDE
	thumb_func_end TryRunFromBattle

	thumb_func_start HandleAction_Run
HandleAction_Run: @ 0x0803EA88
	push {r4, r5, r6, lr}
	ldr r4, _0803EAD8
	ldr r1, _0803EADC
	ldr r5, _0803EAE0
	ldrb r0, [r5]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r0, _0803EAE4
	ldr r0, [r0]
	ldr r1, _0803EAE8
	ands r0, r1
	cmp r0, #0
	beq _0803EB4C
	ldr r0, _0803EAEC
	ldrb r1, [r0]
	strb r1, [r5]
	ldr r2, _0803EAF0
	movs r0, #0
	strb r0, [r2]
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _0803EB20
	adds r4, r2, #0
	ldr r6, _0803EAF4
	ldr r5, _0803EAF8
_0803EABC:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EAFC
	ldrb r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803EB0E
	ldrb r0, [r5]
	movs r1, #2
	b _0803EB0A
	.align 2, 0
_0803EAD8: .4byte 0x02023EAF
_0803EADC: .4byte 0x02023D22
_0803EAE0: .4byte 0x02023D26
_0803EAE4: .4byte 0x02022C90
_0803EAE8: .4byte 0x02000002
_0803EAEC: .4byte 0x02023D10
_0803EAF0: .4byte 0x02023D08
_0803EAF4: .4byte 0x02023EC0
_0803EAF8: .4byte 0x02023FDE
_0803EAFC:
	ldrb r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803EB0E
	ldrb r0, [r5]
	movs r1, #1
_0803EB0A:
	orrs r0, r1
	strb r0, [r5]
_0803EB0E:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _0803EB3C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803EABC
_0803EB20:
	ldr r2, _0803EB40
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0803EB44
	ldr r1, [r0]
	ldr r0, _0803EB48
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #8
	orrs r0, r2
	b _0803EBD6
	.align 2, 0
_0803EB3C: .4byte 0x02023D10
_0803EB40: .4byte 0x02023FDE
_0803EB44: .4byte 0x03005AF0
_0803EB48: .4byte 0x00000CA9
_0803EB4C:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EB8C
	ldrb r0, [r4]
	bl TryRunFromBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EBD8
	ldrb r0, [r4]
	bl ClearFuryCutterDestinyBondGrudge
	ldr r1, _0803EB7C
	movs r0, #3
	strb r0, [r1, #5]
	ldr r1, _0803EB80
	ldr r0, _0803EB84
	str r0, [r1]
	ldr r1, _0803EB88
	movs r0, #0xa
	b _0803EBD6
	.align 2, 0
_0803EB7C: .4byte 0x02023FD6
_0803EB80: .4byte 0x02023EB8
_0803EB84: .4byte 0x0828908A
_0803EB88: .4byte 0x02023D27
_0803EB8C:
	ldr r1, _0803EBB4
	ldrb r2, [r4]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0803EBB8
	ands r0, r1
	cmp r0, #0
	beq _0803EBCC
	ldr r1, _0803EBBC
	movs r0, #4
	strb r0, [r1, #5]
	ldr r1, _0803EBC0
	ldr r0, _0803EBC4
	str r0, [r1]
	ldr r1, _0803EBC8
	movs r0, #0xa
	b _0803EBD6
	.align 2, 0
_0803EBB4: .4byte 0x02023D28
_0803EBB8: .4byte 0x0400E000
_0803EBBC: .4byte 0x02023FD6
_0803EBC0: .4byte 0x02023EB8
_0803EBC4: .4byte 0x0828908A
_0803EBC8: .4byte 0x02023D27
_0803EBCC:
	ldr r0, _0803EBE0
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r1, _0803EBE4
	movs r0, #6
_0803EBD6:
	strb r0, [r1]
_0803EBD8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803EBE0: .4byte 0x02023D10
_0803EBE4: .4byte 0x02023FDE
	thumb_func_end HandleAction_Run

	thumb_func_start HandleAction_WatchesCarefully
HandleAction_WatchesCarefully: @ 0x0803EBE8
	ldr r2, _0803EC10
	ldr r1, _0803EC14
	ldr r0, _0803EC18
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, _0803EC1C
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EC20
	strh r1, [r0]
	ldr r1, _0803EC24
	ldr r0, _0803EC28
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0803EC2C
	movs r0, #0xa
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803EC10: .4byte 0x02023EAF
_0803EC14: .4byte 0x02023D22
_0803EC18: .4byte 0x02023D26
_0803EC1C: .4byte 0x02022AC8
_0803EC20: .4byte 0x02022ACA
_0803EC24: .4byte 0x02023EB8
_0803EC28: .4byte 0x0828A2E0
_0803EC2C: .4byte 0x02023D27
	thumb_func_end HandleAction_WatchesCarefully

	thumb_func_start HandleAction_SafariZoneBallThrow
HandleAction_SafariZoneBallThrow: @ 0x0803EC30
	ldr r2, _0803EC68
	ldr r1, _0803EC6C
	ldr r0, _0803EC70
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, _0803EC74
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EC78
	strh r1, [r0]
	ldr r1, _0803EC7C
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r1, _0803EC80
	movs r0, #5
	strh r0, [r1]
	ldr r1, _0803EC84
	ldr r0, _0803EC88
	ldr r0, [r0, #0x14]
	str r0, [r1]
	ldr r1, _0803EC8C
	movs r0, #0xa
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803EC68: .4byte 0x02023EAF
_0803EC6C: .4byte 0x02023D22
_0803EC70: .4byte 0x02023D26
_0803EC74: .4byte 0x02022AC8
_0803EC78: .4byte 0x02022ACA
_0803EC7C: .4byte 0x02039D18
_0803EC80: .4byte 0x02023EAC
_0803EC84: .4byte 0x02023EB8
_0803EC88: .4byte 0x0828A290
_0803EC8C: .4byte 0x02023D27
	thumb_func_end HandleAction_SafariZoneBallThrow

	thumb_func_start HandleAction_ThrowPokeblock
HandleAction_ThrowPokeblock: @ 0x0803EC90
	push {r4, r5, r6, lr}
	ldr r3, _0803ED10
	ldr r1, _0803ED14
	ldr r0, _0803ED18
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r0, _0803ED1C
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803ED20
	strh r1, [r0]
	ldr r6, _0803ED24
	ldr r2, _0803ED28
	ldrb r0, [r3]
	lsls r0, r0, #9
	adds r1, r2, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #1
	strb r0, [r6, #5]
	ldr r1, _0803ED2C
	ldrb r0, [r3]
	lsls r0, r0, #9
	adds r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	strh r0, [r1]
	ldr r1, _0803ED30
	ldrb r0, [r1, #0x1f]
	cmp r0, #0xfe
	bhi _0803ECD6
	adds r0, #1
	strb r0, [r1, #0x1f]
_0803ECD6:
	ldr r2, _0803ED34
	ldr r0, [r2]
	adds r1, r0, #0
	adds r1, #0x7a
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0803ECE8
	adds r0, #1
	strb r0, [r1]
_0803ECE8:
	ldr r0, [r2]
	adds r3, r0, #0
	adds r3, #0x7b
	ldrb r5, [r3]
	adds r4, r5, #0
	cmp r4, #1
	bls _0803ED40
	ldr r2, _0803ED38
	adds r0, #0x7a
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r6, [r6, #5]
	adds r0, r0, r6
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r4, r0
	bhs _0803ED3C
	movs r0, #1
	b _0803ED3E
	.align 2, 0
_0803ED10: .4byte 0x02023EAF
_0803ED14: .4byte 0x02023D22
_0803ED18: .4byte 0x02023D26
_0803ED1C: .4byte 0x02022AC8
_0803ED20: .4byte 0x02022ACA
_0803ED24: .4byte 0x02023FD6
_0803ED28: .4byte 0x02023508
_0803ED2C: .4byte 0x02023EAC
_0803ED30: .4byte 0x03005A70
_0803ED34: .4byte 0x02024140
_0803ED38: .4byte 0x082EC664
_0803ED3C:
	subs r0, r5, r0
_0803ED3E:
	strb r0, [r3]
_0803ED40:
	ldr r1, _0803ED54
	ldr r0, _0803ED58
	ldr r0, [r0, #8]
	str r0, [r1]
	ldr r1, _0803ED5C
	movs r0, #0xa
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803ED54: .4byte 0x02023EB8
_0803ED58: .4byte 0x0828A2E0
_0803ED5C: .4byte 0x02023D27
	thumb_func_end HandleAction_ThrowPokeblock

	thumb_func_start HandleAction_GoNear
HandleAction_GoNear: @ 0x0803ED60
	push {r4, lr}
	ldr r2, _0803EDE0
	ldr r1, _0803EDE4
	ldr r0, _0803EDE8
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, _0803EDEC
	movs r4, #0
	strh r4, [r0]
	ldr r0, _0803EDF0
	strh r4, [r0]
	ldr r3, _0803EDF4
	ldr r0, [r3]
	adds r2, r0, #0
	adds r2, #0x7c
	ldr r1, _0803EDF8
	adds r0, #0x79
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	cmp r0, #0x14
	bls _0803EDA2
	movs r0, #0x14
	strb r0, [r1]
_0803EDA2:
	ldr r0, [r3]
	adds r2, r0, #0
	adds r2, #0x7b
	ldr r1, _0803EDFC
	adds r0, #0x79
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x7b
	ldrb r0, [r1]
	cmp r0, #0x14
	bls _0803EDC8
	movs r0, #0x14
	strb r0, [r1]
_0803EDC8:
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x79
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0803EE04
	adds r0, #1
	strb r0, [r1]
	ldr r0, _0803EE00
	strb r4, [r0, #5]
	b _0803EE0A
	.align 2, 0
_0803EDE0: .4byte 0x02023EAF
_0803EDE4: .4byte 0x02023D22
_0803EDE8: .4byte 0x02023D26
_0803EDEC: .4byte 0x02022AC8
_0803EDF0: .4byte 0x02022ACA
_0803EDF4: .4byte 0x02024140
_0803EDF8: .4byte 0x082EC673
_0803EDFC: .4byte 0x082EC677
_0803EE00: .4byte 0x02023FD6
_0803EE04:
	ldr r1, _0803EE20
	movs r0, #1
	strb r0, [r1, #5]
_0803EE0A:
	ldr r1, _0803EE24
	ldr r0, _0803EE28
	ldr r0, [r0, #4]
	str r0, [r1]
	ldr r1, _0803EE2C
	movs r0, #0xa
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EE20: .4byte 0x02023FD6
_0803EE24: .4byte 0x02023EB8
_0803EE28: .4byte 0x0828A2E0
_0803EE2C: .4byte 0x02023D27
	thumb_func_end HandleAction_GoNear

	thumb_func_start HandleAction_SafariZoneRun
HandleAction_SafariZoneRun: @ 0x0803EE30
	push {r4, lr}
	ldr r2, _0803EE58
	ldr r1, _0803EE5C
	ldr r4, _0803EE60
	ldrb r0, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, #0x11
	bl PlaySE
	ldr r0, _0803EE64
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r1, _0803EE68
	movs r0, #4
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EE58: .4byte 0x02023EAF
_0803EE5C: .4byte 0x02023D22
_0803EE60: .4byte 0x02023D26
_0803EE64: .4byte 0x02023D10
_0803EE68: .4byte 0x02023FDE
	thumb_func_end HandleAction_SafariZoneRun

	thumb_func_start HandleAction_WallyBallThrow
HandleAction_WallyBallThrow: @ 0x0803EE6C
	ldr r3, _0803EEB8
	ldr r1, _0803EEBC
	ldr r0, _0803EEC0
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r2, [r0]
	strb r2, [r3]
	ldr r0, _0803EEC4
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EEC8
	strh r1, [r0]
	ldr r1, _0803EECC
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #7
	strb r0, [r1, #1]
	strb r2, [r1, #2]
	ldr r2, _0803EED0
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _0803EED4
	ldr r0, _0803EED8
	ldr r0, [r0, #0xc]
	str r0, [r1]
	ldr r1, _0803EEDC
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, _0803EEE0
	movs r0, #0xc
	strb r0, [r1, #1]
	bx lr
	.align 2, 0
_0803EEB8: .4byte 0x02023EAF
_0803EEBC: .4byte 0x02023D22
_0803EEC0: .4byte 0x02023D26
_0803EEC4: .4byte 0x02022AC8
_0803EEC8: .4byte 0x02022ACA
_0803EECC: .4byte 0x02022C0C
_0803EED0: .4byte 0x02023D12
_0803EED4: .4byte 0x02023EB8
_0803EED8: .4byte 0x0828A2E0
_0803EEDC: .4byte 0x02023D27
_0803EEE0: .4byte 0x02023D1E
	thumb_func_end HandleAction_WallyBallThrow

	thumb_func_start sub_0803EEE4
sub_0803EEE4: @ 0x0803EEE4
	push {lr}
	bl HandleFaintedMonActions
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0803EF00
	ldr r0, _0803EF04
	ldr r0, [r0]
	adds r0, #0x4d
	strb r1, [r0]
	ldr r1, _0803EF08
	movs r0, #0xc
	strb r0, [r1]
_0803EF00:
	pop {r0}
	bx r0
	.align 2, 0
_0803EF04: .4byte 0x02024140
_0803EF08: .4byte 0x02023D27
	thumb_func_end sub_0803EEE4

	thumb_func_start HandleAction_NothingIsFainted
HandleAction_NothingIsFainted: @ 0x0803EF0C
	ldr r1, _0803EF2C
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r3, _0803EF30
	ldr r2, _0803EF34
	ldrb r0, [r1]
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r2, _0803EF38
	ldr r0, [r2]
	ldr r1, _0803EF3C
	ands r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0803EF2C: .4byte 0x02023D26
_0803EF30: .4byte 0x02023D27
_0803EF34: .4byte 0x02023D1E
_0803EF38: .4byte 0x02023F24
_0803EF3C: .4byte 0xF1E892AF
	thumb_func_end HandleAction_NothingIsFainted

	thumb_func_start HandleAction_ActionFinished
HandleAction_ActionFinished: @ 0x0803EF40
	push {r4, r5, r6, lr}
	ldr r1, _0803EFC8
	ldr r2, _0803EFCC
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r6, _0803EFD0
	ldr r1, [r6]
	adds r0, r0, r1
	adds r0, #0x5c
	movs r1, #6
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r3, _0803EFD4
	ldr r1, _0803EFD8
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	bl SpecialStatusesClear
	ldr r2, _0803EFDC
	ldr r0, [r2]
	ldr r1, _0803EFE0
	ands r0, r1
	str r0, [r2]
	ldr r0, _0803EFE4
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EFE8
	movs r4, #0
	str r4, [r0]
	ldr r0, _0803EFEC
	strb r1, [r0]
	ldr r5, _0803EFF0
	strb r1, [r5, #0x18]
	strb r1, [r5, #0x19]
	ldr r2, _0803EFF4
	ldr r3, _0803EFF8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	strh r4, [r0]
	ldr r2, _0803EFFC
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	strh r4, [r0]
	ldr r0, [r6]
	strb r1, [r0, #0x13]
	ldr r0, _0803F000
	strh r4, [r0]
	strb r1, [r5, #0x14]
	ldr r0, _0803F004
	strb r1, [r0, #3]
	strb r1, [r0, #4]
	strb r1, [r5, #0x16]
	ldr r0, _0803F008
	ldr r0, [r0]
	ldr r0, [r0, #8]
	adds r0, #0x20
	strb r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803EFC8: .4byte 0x02023D22
_0803EFCC: .4byte 0x02023D26
_0803EFD0: .4byte 0x02024140
_0803EFD4: .4byte 0x02023D27
_0803EFD8: .4byte 0x02023D1E
_0803EFDC: .4byte 0x02023F24
_0803EFE0: .4byte 0xF1E892AF
_0803EFE4: .4byte 0x02023E8E
_0803EFE8: .4byte 0x02023E94
_0803EFEC: .4byte 0x02023F20
_0803EFF0: .4byte 0x02024118
_0803EFF4: .4byte 0x02023EF4
_0803EFF8: .4byte 0x02023EAF
_0803EFFC: .4byte 0x02023EFC
_0803F000: .4byte 0x020240A4
_0803F004: .4byte 0x02023FD6
_0803F008: .4byte 0x0202414C
	thumb_func_end HandleAction_ActionFinished
