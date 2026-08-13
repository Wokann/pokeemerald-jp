.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified





	thumb_func_start BufferMoveToLearnIntoBattleTextBuff2
BufferMoveToLearnIntoBattleTextBuff2: @ 0x0804F180
	ldr r2, _0804F1A0
	movs r0, #0xfd
	strb r0, [r2]
	movs r0, #2
	strb r0, [r2, #1]
	ldr r0, _0804F1A4
	ldrh r1, [r0]
	strb r1, [r2, #2]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	lsrs r0, r0, #8
	strb r0, [r2, #3]
	movs r0, #0xff
	strb r0, [r2, #4]
	bx lr
	.align 2, 0
_0804F1A0: .4byte 0x02022C1C
_0804F1A4: .4byte 0x02024186
	thumb_func_end BufferMoveToLearnIntoBattleTextBuff2

	thumb_func_start atk71_buffermovetolearn
atk71_buffermovetolearn: @ 0x0804F1A8
	push {lr}
	bl BufferMoveToLearnIntoBattleTextBuff2
	ldr r1, _0804F1BC
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804F1BC: .4byte 0x02023EB8
	thumb_func_end atk71_buffermovetolearn

	thumb_func_start atk72_jumpifplayerran
atk72_jumpifplayerran: @ 0x0804F1C0
	push {lr}
	ldr r0, _0804F1EC
	ldrb r0, [r0]
	bl TryRunFromBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804F1F4
	ldr r3, _0804F1F0
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0804F1FC
	.align 2, 0
_0804F1EC: .4byte 0x02023EB1
_0804F1F0: .4byte 0x02023EB8
_0804F1F4:
	ldr r1, _0804F200
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0804F1FC:
	pop {r0}
	bx r0
	.align 2, 0
_0804F200: .4byte 0x02023EB8
	thumb_func_end atk72_jumpifplayerran

	thumb_func_start atk73_hpthresholds
atk73_hpthresholds: @ 0x0804F204
	push {r4, r5, r6, lr}
	ldr r0, _0804F254
	ldr r4, [r0]
	movs r6, #1
	ands r4, r6
	cmp r4, #0
	bne _0804F29A
	ldr r0, _0804F258
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	bl GetBattlerForBattleScript
	ldr r1, _0804F25C
	strb r0, [r1]
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0804F260
	movs r1, #0x58
	muls r1, r0, r1
	adds r1, r1, r2
	ldrh r5, [r1, #0x28]
	movs r0, #0x64
	muls r0, r5, r0
	ldrh r1, [r1, #0x2c]
	bl __divsi3
	cmp r0, #0
	bne _0804F242
	movs r0, #1
_0804F242:
	cmp r0, #0x45
	bgt _0804F24A
	cmp r5, #0
	bne _0804F268
_0804F24A:
	ldr r0, _0804F264
	ldr r0, [r0]
	adds r0, #0xb1
	strb r4, [r0]
	b _0804F29A
	.align 2, 0
_0804F254: .4byte 0x02022C90
_0804F258: .4byte 0x02023EB8
_0804F25C: .4byte 0x02023D08
_0804F260: .4byte 0x02023D28
_0804F264: .4byte 0x02024140
_0804F268:
	cmp r0, #0x27
	ble _0804F27C
	ldr r0, _0804F278
	ldr r0, [r0]
	adds r0, #0xb1
	strb r6, [r0]
	b _0804F29A
	.align 2, 0
_0804F278: .4byte 0x02024140
_0804F27C:
	cmp r0, #9
	ble _0804F290
	ldr r0, _0804F28C
	ldr r0, [r0]
	adds r0, #0xb1
	movs r1, #2
	b _0804F298
	.align 2, 0
_0804F28C: .4byte 0x02024140
_0804F290:
	ldr r0, _0804F2A8
	ldr r0, [r0]
	adds r0, #0xb1
	movs r1, #3
_0804F298:
	strb r1, [r0]
_0804F29A:
	ldr r1, _0804F2AC
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804F2A8: .4byte 0x02024140
_0804F2AC: .4byte 0x02023EB8
	thumb_func_end atk73_hpthresholds

	thumb_func_start atk74_hpthresholds2
atk74_hpthresholds2: @ 0x0804F2B0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0804F314
	ldr r7, [r0]
	movs r0, #1
	mov r8, r0
	ands r7, r0
	cmp r7, #0
	bne _0804F34A
	ldr r0, _0804F318
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	bl GetBattlerForBattleScript
	adds r4, r0, #0
	ldr r0, _0804F31C
	strb r4, [r0]
	movs r0, #1
	eors r4, r0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	ldr r1, _0804F320
	ldr r6, [r1]
	lsrs r0, r0, #0x17
	adds r0, r0, r6
	adds r0, #0xa8
	ldrb r5, [r0]
	ldr r1, _0804F324
	movs r0, #0x58
	muls r0, r4, r0
	adds r0, r0, r1
	ldrh r4, [r0, #0x28]
	subs r1, r5, r4
	movs r0, #0x64
	muls r0, r1, r0
	adds r1, r5, #0
	bl __divsi3
	adds r1, r0, #0
	cmp r4, r5
	blo _0804F328
	adds r0, r6, #0
	adds r0, #0xb1
	strb r7, [r0]
	b _0804F34A
	.align 2, 0
_0804F314: .4byte 0x02022C90
_0804F318: .4byte 0x02023EB8
_0804F31C: .4byte 0x02023D08
_0804F320: .4byte 0x02024140
_0804F324: .4byte 0x02023D28
_0804F328:
	cmp r0, #0x1d
	bgt _0804F336
	adds r0, r6, #0
	adds r0, #0xb1
	mov r1, r8
	strb r1, [r0]
	b _0804F34A
_0804F336:
	cmp r1, #0x45
	bgt _0804F342
	adds r1, r6, #0
	adds r1, #0xb1
	movs r0, #2
	b _0804F348
_0804F342:
	adds r1, r6, #0
	adds r1, #0xb1
	movs r0, #3
_0804F348:
	strb r0, [r1]
_0804F34A:
	ldr r1, _0804F35C
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804F35C: .4byte 0x02023EB8
	thumb_func_end atk74_hpthresholds2

	thumb_func_start atk75_useitemonopponent
atk75_useitemonopponent: @ 0x0804F360
	push {lr}
	sub sp, #4
	ldr r2, _0804F3A0
	ldr r1, _0804F3A4
	ldrb r0, [r1]
	strb r0, [r2]
	ldr r2, _0804F3A8
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0x64
	muls r0, r2, r0
	ldr r1, _0804F3AC
	adds r0, r0, r1
	ldr r1, _0804F3B0
	ldrh r1, [r1]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #1
	str r3, [sp]
	movs r3, #0
	bl sub_0806B7EC
	ldr r1, _0804F3B4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_0804F3A0: .4byte 0x0202415C
_0804F3A4: .4byte 0x02023EAF
_0804F3A8: .4byte 0x02023D12
_0804F3AC: .4byte 0x020243E8
_0804F3B0: .4byte 0x02023EAC
_0804F3B4: .4byte 0x02023EB8
	thumb_func_end atk75_useitemonopponent

	thumb_func_start atk76_various
atk76_various: @ 0x0804F3B8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r4, _0804F3E0
	ldr r0, [r4]
	ldrb r0, [r0, #1]
	bl GetBattlerForBattleScript
	ldr r1, _0804F3E4
	strb r0, [r1]
	ldr r0, [r4]
	ldrb r0, [r0, #2]
	cmp r0, #0x1a
	bls _0804F3D6
	b _0804F97C
_0804F3D6:
	lsls r0, r0, #2
	ldr r1, _0804F3E8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804F3E0: .4byte 0x02023EB8
_0804F3E4: .4byte 0x02023D08
_0804F3E8: .4byte 0x0804F3EC
_0804F3EC: @ jump table
	.4byte _0804F458 @ case 0
	.4byte _0804F468 @ case 1
	.4byte _0804F4C8 @ case 2
	.4byte _0804F4D8 @ case 3
	.4byte _0804F4F0 @ case 4
	.4byte _0804F52C @ case 5
	.4byte _0804F564 @ case 6
	.4byte _0804F5EC @ case 7
	.4byte _0804F62C @ case 8
	.4byte _0804F6D8 @ case 9
	.4byte _0804F6F4 @ case 10
	.4byte _0804F748 @ case 11
	.4byte _0804F7A0 @ case 12
	.4byte _0804F824 @ case 13
	.4byte _0804F838 @ case 14
	.4byte _0804F83E @ case 15
	.4byte _0804F844 @ case 16
	.4byte _0804F86C @ case 17
	.4byte _0804F876 @ case 18
	.4byte _0804F884 @ case 19
	.4byte _0804F898 @ case 20
	.4byte _0804F8D0 @ case 21
	.4byte _0804F8E4 @ case 22
	.4byte _0804F8FC @ case 23
	.4byte _0804F928 @ case 24
	.4byte _0804F93C @ case 25
	.4byte _0804F968 @ case 26
_0804F458:
	ldr r0, _0804F464
	ldrb r0, [r0]
	bl CancelMultiTurnMoves
	b _0804F97C
	.align 2, 0
_0804F464: .4byte 0x02023D08
_0804F468:
	ldr r1, _0804F4A4
	ldr r4, _0804F4A8
	ldrb r0, [r4]
	strb r0, [r1]
	ldrb r0, [r1]
	bl GetBattlerSide
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _0804F4AC
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r2, r1, r2
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _0804F4B4
	ldr r1, _0804F4B0
	ldrb r2, [r2, #9]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _0804F4B4
	strb r2, [r4]
	b _0804F97C
	.align 2, 0
_0804F4A4: .4byte 0x02023EAF
_0804F4A8: .4byte 0x02023EB0
_0804F4AC: .4byte 0x02023F38
_0804F4B0: .4byte 0x02023D28
_0804F4B4:
	ldr r0, _0804F4C0
	ldr r1, _0804F4C4
	ldrb r1, [r1]
	strb r1, [r0]
	b _0804F97C
	.align 2, 0
_0804F4C0: .4byte 0x02023EB0
_0804F4C4: .4byte 0x02023D08
_0804F4C8:
	bl IsRunningFromBattleImpossible
	ldr r1, _0804F4D4
	strb r0, [r1]
	b _0804F97C
	.align 2, 0
_0804F4D4: .4byte 0x02023FD6
_0804F4D8:
	ldr r0, _0804F4E8
	ldrh r0, [r0]
	movs r1, #0
	bl GetMoveTarget
	ldr r1, _0804F4EC
	strb r0, [r1]
	b _0804F97C
	.align 2, 0
_0804F4E8: .4byte 0x02023E8E
_0804F4EC: .4byte 0x02023EB0
_0804F4F0:
	ldr r2, _0804F510
	ldr r1, _0804F514
	ldr r0, _0804F518
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r0, r0, #0x1c
	ldr r2, [r2]
	ands r2, r0
	cmp r2, #0
	beq _0804F520
	ldr r1, _0804F51C
	movs r0, #1
	strb r0, [r1]
	b _0804F97C
	.align 2, 0
_0804F510: .4byte 0x02023F24
_0804F514: .4byte 0x082FACB4
_0804F518: .4byte 0x02023D08
_0804F51C: .4byte 0x02023FD6
_0804F520:
	ldr r0, _0804F528
	strb r2, [r0]
	b _0804F97C
	.align 2, 0
_0804F528: .4byte 0x02023FD6
_0804F52C:
	ldr r4, _0804F55C
	ldr r3, _0804F560
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r2, [r1]
	movs r0, #9
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r2, [r1]
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1]
	b _0804F97C
	.align 2, 0
_0804F55C: .4byte 0x02024020
_0804F560: .4byte 0x02023D08
_0804F564:
	ldr r4, _0804F588
	ldr r1, _0804F58C
	ldr r0, [r1]
	ldrh r3, [r4]
	ldrb r2, [r0, #0x10]
	adds r6, r1, #0
	cmp r3, r2
	beq _0804F580
	ldrh r0, [r4, #4]
	cmp r0, r2
	beq _0804F57C
	b _0804F97C
_0804F57C:
	cmp r3, r0
	bne _0804F594
_0804F580:
	ldr r1, _0804F590
	movs r0, #0
	b _0804F598
	.align 2, 0
_0804F588: .4byte 0x02023D12
_0804F58C: .4byte 0x02024140
_0804F590: .4byte 0x02023D08
_0804F594:
	ldr r1, _0804F5E4
	movs r0, #2
_0804F598:
	strb r0, [r1]
	adds r5, r1, #0
	ldrb r2, [r5]
	lsls r0, r2, #1
	adds r0, #0xc8
	ldr r1, [r6]
	adds r4, r1, r0
	movs r3, #0
	ldr r1, _0804F5E8
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0xc
	adds r0, r0, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	beq _0804F5D8
	adds r6, r5, #0
	movs r5, #0x58
	adds r2, r1, #0
_0804F5C0:
	adds r3, #1
	cmp r3, #3
	bgt _0804F5D8
	lsls r1, r3, #1
	ldrb r0, [r6]
	muls r0, r5, r0
	adds r1, r1, r0
	adds r1, r1, r2
	ldrh r0, [r1]
	ldrh r1, [r4]
	cmp r0, r1
	bne _0804F5C0
_0804F5D8:
	cmp r3, #4
	beq _0804F5DE
	b _0804F97C
_0804F5DE:
	movs r0, #0
	strh r0, [r4]
	b _0804F97C
	.align 2, 0
_0804F5E4: .4byte 0x02023D08
_0804F5E8: .4byte 0x02023D28
_0804F5EC:
	ldr r0, _0804F61C
	ldr r0, [r0]
	movs r1, #0xb
	ands r0, r1
	cmp r0, #8
	beq _0804F5FA
	b _0804F97C
_0804F5FA:
	ldr r1, _0804F620
	ldrh r0, [r1, #0x28]
	cmp r0, #0
	bne _0804F604
	b _0804F97C
_0804F604:
	adds r0, r1, #0
	adds r0, #0x80
	ldrh r0, [r0]
	cmp r0, #0
	bne _0804F610
	b _0804F97C
_0804F610:
	ldr r0, _0804F624
	ldr r1, [r0]
	ldr r2, _0804F628
	ands r1, r2
	str r1, [r0]
	b _0804F97C
	.align 2, 0
_0804F61C: .4byte 0x02022C90
_0804F620: .4byte 0x02023D28
_0804F624: .4byte 0x02023F24
_0804F628: .4byte 0xFFBFFFFF
_0804F62C:
	ldr r2, _0804F6BC
	mov r8, r2
	movs r0, #0
	strb r0, [r2]
	ldr r1, _0804F6C0
	ldr r6, _0804F6C4
	ldrb r0, [r2, #1]
	strb r0, [r6]
	strb r0, [r1, #0x17]
	ldr r0, _0804F6C8
	ldr r0, [r0]
	adds r7, r0, #0
	adds r7, #0x92
	ldrb r3, [r7]
	ldr r1, _0804F6CC
	ldrb r2, [r6]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r3, #0
	ands r0, r5
	cmp r0, #0
	beq _0804F65C
	b _0804F97C
_0804F65C:
	ldr r4, _0804F6D0
	movs r0, #0x58
	mov ip, r0
	mov r1, ip
	muls r1, r2, r1
	adds r2, r1, #0
	adds r1, r2, r4
	ldrh r0, [r1, #0x2c]
	lsrs r0, r0, #1
	ldrh r1, [r1, #0x28]
	cmp r0, r1
	bhs _0804F676
	b _0804F97C
_0804F676:
	cmp r1, #0
	bne _0804F67C
	b _0804F97C
_0804F67C:
	adds r0, r4, #0
	adds r0, #0x4c
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0804F68E
	b _0804F97C
_0804F68E:
	orrs r3, r5
	strb r3, [r7]
	movs r0, #1
	mov r2, r8
	strb r0, [r2]
	ldrb r0, [r6]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r4, #0
	adds r1, #0x48
	adds r0, r0, r1
	ldr r0, [r0]
	bl GetNatureFromPersonality
	ldr r1, _0804F6D4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r2, r8
	strb r0, [r2, #5]
	b _0804F97C
	.align 2, 0
_0804F6BC: .4byte 0x02023FD6
_0804F6C0: .4byte 0x02024118
_0804F6C4: .4byte 0x02023D08
_0804F6C8: .4byte 0x02024140
_0804F6CC: .4byte 0x082FACB4
_0804F6D0: .4byte 0x02023D28
_0804F6D4: .4byte 0x082ECE7C
_0804F6D8:
	ldr r4, _0804F6F0
	adds r0, r4, #0
	bl BattleArena_ShowJudgmentWindow
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0804F6EA
	b _0804F984
_0804F6EA:
	strb r3, [r4, #1]
	b _0804F97C
	.align 2, 0
_0804F6F0: .4byte 0x02023FD6
_0804F6F4:
	ldr r0, _0804F72C
	adds r0, #0x80
	movs r1, #0
	strh r1, [r0]
	ldr r2, _0804F730
	ldr r3, _0804F734
	ldr r1, [r3, #4]
	lsls r1, r1, #0x1c
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0804F738
	ldr r2, [r0]
	ldr r0, _0804F73C
	adds r2, r2, r0
	ldr r0, _0804F740
	ldrh r0, [r0, #2]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _0804F744
	adds r1, #0x34
	ldrb r0, [r1]
	movs r2, #2
	b _0804F800
	.align 2, 0
_0804F72C: .4byte 0x02023D28
_0804F730: .4byte 0x02023F24
_0804F734: .4byte 0x082FACB4
_0804F738: .4byte 0x02024140
_0804F73C: .4byte 0x000002A1
_0804F740: .4byte 0x02023D12
_0804F744: .4byte 0x02023F60
_0804F748:
	ldr r1, _0804F788
	movs r0, #0
	strh r0, [r1, #0x28]
	ldr r2, _0804F78C
	ldr r3, _0804F790
	ldr r1, [r3]
	lsls r1, r1, #0x1c
	ldr r0, [r2]
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [r2]
	ldr r0, _0804F794
	ldr r2, [r0]
	movs r1, #0xa8
	lsls r1, r1, #2
	adds r2, r2, r1
	ldr r0, _0804F798
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, _0804F79C
	ldrb r0, [r2, #0x18]
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x18]
	b _0804F97C
	.align 2, 0
_0804F788: .4byte 0x02023D28
_0804F78C: .4byte 0x02023F24
_0804F790: .4byte 0x082FACB4
_0804F794: .4byte 0x02024140
_0804F798: .4byte 0x02023D12
_0804F79C: .4byte 0x02023F60
_0804F7A0:
	ldr r0, _0804F808
	movs r1, #0
	strh r1, [r0, #0x28]
	adds r0, #0x80
	strh r1, [r0]
	ldr r2, _0804F80C
	ldr r3, _0804F810
	ldr r0, [r3]
	lsls r0, r0, #0x1c
	ldr r1, [r2]
	orrs r1, r0
	ldr r0, [r3, #4]
	lsls r0, r0, #0x1c
	orrs r1, r0
	movs r0, #0x80
	lsls r0, r0, #0xf
	orrs r1, r0
	str r1, [r2]
	ldr r5, _0804F814
	ldr r2, [r5]
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r4, _0804F818
	ldrh r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r2, [r5]
	ldr r1, _0804F81C
	adds r2, r2, r1
	ldrh r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _0804F820
	ldrb r0, [r1, #0x18]
	movs r2, #2
	orrs r0, r2
	strb r0, [r1, #0x18]
	adds r1, #0x34
	ldrb r0, [r1]
_0804F800:
	orrs r0, r2
	strb r0, [r1]
	b _0804F97C
	.align 2, 0
_0804F808: .4byte 0x02023D28
_0804F80C: .4byte 0x02023F24
_0804F810: .4byte 0x082FACB4
_0804F814: .4byte 0x02024140
_0804F818: .4byte 0x02023D12
_0804F81C: .4byte 0x000002A1
_0804F820: .4byte 0x02023F60
_0804F824:
	movs r0, #0
	bl BtlController_EmitUnknownYesNoBox
	ldr r0, _0804F834
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	b _0804F97C
	.align 2, 0
_0804F834: .4byte 0x02023D08
_0804F838:
	bl DrawArenaRefereeTextBox
	b _0804F97C
_0804F83E:
	bl RemoveArenaRefereeTextBox
	b _0804F97C
_0804F844:
	ldr r1, _0804F860
	ldr r0, _0804F864
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl TryGetStatusString
	ldr r0, _0804F868
	movs r1, #0x16
	bl sub_0814FA04
	b _0804F97C
	.align 2, 0
_0804F860: .4byte 0x085AC04C
_0804F864: .4byte 0x02023EB8
_0804F868: .4byte 0x02022AE0
_0804F86C:
	movs r0, #0x16
	bl IsTextPrinterActive
	lsls r0, r0, #0x10
	b _0804F930
_0804F876:
	bl IsCryFinished
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F882
	b _0804F984
_0804F882:
	b _0804F97C
_0804F884:
	ldr r4, _0804F890
	movs r0, #1
	strb r0, [r4]
	ldr r0, _0804F894
	adds r0, #0x58
	b _0804F8AE
	.align 2, 0
_0804F890: .4byte 0x02023D08
_0804F894: .4byte 0x02023D28
_0804F898:
	ldr r0, _0804F8C4
	ldrb r0, [r0]
	cmp r0, #3
	bls _0804F97C
	ldr r4, _0804F8C8
	movs r0, #3
	strb r0, [r4]
	ldr r0, _0804F8CC
	movs r2, #0x84
	lsls r2, r2, #1
	adds r0, r0, r2
_0804F8AE:
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _0804F97C
	movs r0, #0
	movs r1, #0
	bl BtlController_EmitReturnMonToBall
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	b _0804F97C
	.align 2, 0
_0804F8C4: .4byte 0x02023D10
_0804F8C8: .4byte 0x02023D08
_0804F8CC: .4byte 0x02023D28
_0804F8D0:
	ldr r0, _0804F8DC
	ldr r1, _0804F8E0
	movs r2, #0x55
	bl m4aMPlayVolumeControl
	b _0804F97C
	.align 2, 0
_0804F8DC: .4byte 0x030074D0
_0804F8E0: .4byte 0x0000FFFF
_0804F8E4:
	ldr r0, _0804F8F4
	ldr r1, _0804F8F8
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
	b _0804F97C
	.align 2, 0
_0804F8F4: .4byte 0x030074D0
_0804F8F8: .4byte 0x0000FFFF
_0804F8FC:
	ldr r0, _0804F918
	ldr r2, [r0]
	ldr r0, _0804F91C
	adds r2, r2, r0
	ldr r1, _0804F920
	ldr r0, _0804F924
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	b _0804F97C
	.align 2, 0
_0804F918: .4byte 0x02024140
_0804F91C: .4byte 0x000002A2
_0804F920: .4byte 0x082FACB4
_0804F924: .4byte 0x02023D08
_0804F928:
	ldr r0, _0804F938
	ldrb r0, [r0]
	bl BattlePalace_TryEscapeStatus
_0804F930:
	cmp r0, #0
	bne _0804F984
	b _0804F97C
	.align 2, 0
_0804F938: .4byte 0x02023D08
_0804F93C:
	ldr r0, _0804F954
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804F95C
	ldr r1, _0804F958
	movs r0, #5
	strb r0, [r1]
	b _0804F97C
	.align 2, 0
_0804F954: .4byte 0x02023D08
_0804F958: .4byte 0x02023FDE
_0804F95C:
	ldr r1, _0804F964
	movs r0, #0xa
	strb r0, [r1]
	b _0804F97C
	.align 2, 0
_0804F964: .4byte 0x02023FDE
_0804F968:
	movs r1, #0xce
	lsls r1, r1, #1
	movs r0, #0
	movs r2, #1
	bl BtlController_EmitPlayFanfareOrBGM
	ldr r0, _0804F990
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
_0804F97C:
	ldr r1, _0804F994
	ldr r0, [r1]
	adds r0, #3
	str r0, [r1]
_0804F984:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804F990: .4byte 0x02023D08
_0804F994: .4byte 0x02023EB8
	thumb_func_end atk76_various

	thumb_func_start atk77_setprotectlike
atk77_setprotectlike: @ 0x0804F998
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r6, #1
	ldr r2, _0804FA64
	ldr r1, _0804FA68
	ldrb r3, [r1]
	lsls r0, r3, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r8, r1
	ldr r7, _0804FA6C
	cmp r0, #0xb6
	beq _0804F9C8
	cmp r0, #0xc5
	beq _0804F9C8
	cmp r0, #0xcb
	beq _0804F9C8
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r7
	movs r1, #0
	strb r1, [r0, #8]
_0804F9C8:
	ldr r0, _0804FA70
	ldrb r1, [r0]
	ldr r0, _0804FA74
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _0804F9D8
	movs r6, #0
_0804F9D8:
	ldr r2, _0804FA78
	mov r5, r8
	ldrb r1, [r5]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrb r4, [r0, #8]
	lsls r4, r4, #1
	adds r4, r4, r2
	bl Random
	ldrh r1, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	blo _0804FA8C
	cmp r6, #0
	beq _0804FA8C
	ldr r4, _0804FA7C
	ldr r3, _0804FA80
	ldrh r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r0, [r1]
	cmp r0, #0x6f
	bne _0804FA28
	ldr r0, _0804FA84
	ldrb r1, [r5]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #1
	orrs r0, r2
	strb r0, [r1]
	ldr r1, _0804FA88
	movs r0, #0
	strb r0, [r1, #5]
_0804FA28:
	ldrh r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r0, [r1]
	cmp r0, #0x74
	bne _0804FA4E
	ldr r0, _0804FA84
	ldrb r1, [r5]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #2
	orrs r0, r2
	strb r0, [r1]
	ldr r1, _0804FA88
	movs r0, #1
	strb r0, [r1, #5]
_0804FA4E:
	mov r1, r8
	ldrb r0, [r1]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r0, [r1, #8]
	adds r0, #1
	strb r0, [r1, #8]
	b _0804FAAE
	.align 2, 0
_0804FA64: .4byte 0x02023F04
_0804FA68: .4byte 0x02023EAF
_0804FA6C: .4byte 0x02023F60
_0804FA70: .4byte 0x02023D26
_0804FA74: .4byte 0x02023D10
_0804FA78: .4byte 0x082ECD5C
_0804FA7C: .4byte 0x082ED220
_0804FA80: .4byte 0x02023E8E
_0804FA84: .4byte 0x02023FE0
_0804FA88: .4byte 0x02023FD6
_0804FA8C:
	ldr r2, _0804FAC0
	ldr r0, _0804FAC4
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #0
	strb r1, [r0, #8]
	ldr r1, _0804FAC8
	movs r0, #2
	strb r0, [r1, #5]
	ldr r2, _0804FACC
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
_0804FAAE:
	ldr r1, _0804FAD0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FAC0: .4byte 0x02023F60
_0804FAC4: .4byte 0x02023EAF
_0804FAC8: .4byte 0x02023FD6
_0804FACC: .4byte 0x02023F20
_0804FAD0: .4byte 0x02023EB8
	thumb_func_end atk77_setprotectlike

	thumb_func_start atk78_faintifabilitynotdamp
atk78_faintifabilitynotdamp: @ 0x0804FAD4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0804FB90
	ldr r2, [r0]
	cmp r2, #0
	bne _0804FBD8
	ldr r1, _0804FB94
	strb r2, [r1]
	ldr r0, _0804FB98
	ldrb r3, [r0]
	adds r5, r1, #0
	mov r8, r0
	ldr r6, _0804FB9C
	cmp r2, r3
	bhs _0804FB20
	adds r0, r6, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #6
	beq _0804FB20
	adds r2, r3, #0
	adds r4, r6, #0
	movs r3, #0x58
_0804FB04:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r2
	bhs _0804FB20
	ldrb r0, [r5]
	muls r0, r3, r0
	adds r0, r0, r4
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #6
	bne _0804FB04
_0804FB20:
	ldrb r0, [r5]
	mov r1, r8
	ldrb r1, [r1]
	cmp r0, r1
	bne _0804FBBC
	ldr r4, _0804FBA0
	ldr r7, _0804FBA4
	ldrb r0, [r7]
	strb r0, [r4]
	ldr r2, _0804FBA8
	ldrb r1, [r4]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x28]
	str r0, [r2]
	ldr r1, _0804FBAC
	movs r0, #0
	bl BtlController_EmitHealthBarUpdate
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r1, _0804FBB0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	movs r0, #0
	strb r0, [r5]
	mov r2, r8
	ldrb r0, [r2]
	cmp r0, #0
	beq _0804FBD8
	adds r3, r5, #0
	ldrb r5, [r7]
	ldr r7, _0804FBB4
	adds r4, r0, #0
	ldr r6, _0804FBB8
_0804FB6C:
	ldrb r2, [r3]
	cmp r2, r5
	beq _0804FB82
	ldrb r0, [r6]
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r7
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _0804FBD8
_0804FB82:
	adds r0, r2, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r4
	blo _0804FB6C
	b _0804FBD8
	.align 2, 0
_0804FB90: .4byte 0x02023D0C
_0804FB94: .4byte 0x02023EB0
_0804FB98: .4byte 0x02023D10
_0804FB9C: .4byte 0x02023D28
_0804FBA0: .4byte 0x02023D08
_0804FBA4: .4byte 0x02023EAF
_0804FBA8: .4byte 0x02023E94
_0804FBAC: .4byte 0x00007FFF
_0804FBB0: .4byte 0x02023EB8
_0804FBB4: .4byte 0x082FACB4
_0804FBB8: .4byte 0x02023EB4
_0804FBBC:
	ldr r1, _0804FBE4
	movs r0, #6
	strb r0, [r1]
	ldrb r0, [r5]
	movs r1, #0x58
	muls r1, r0, r1
	adds r1, r1, r6
	adds r1, #0x20
	ldrb r1, [r1]
	bl RecordAbilityBattle
	ldr r1, _0804FBE8
	ldr r0, _0804FBEC
	str r0, [r1]
_0804FBD8:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FBE4: .4byte 0x02023EAE
_0804FBE8: .4byte 0x02023EB8
_0804FBEC: .4byte 0x08289AE8
	thumb_func_end atk78_faintifabilitynotdamp

	thumb_func_start atk79_setatkhptozero
atk79_setatkhptozero: @ 0x0804FBF0
	push {r4, lr}
	sub sp, #4
	ldr r0, _0804FC3C
	ldr r3, [r0]
	cmp r3, #0
	bne _0804FC34
	ldr r4, _0804FC40
	ldr r0, _0804FC44
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r1, _0804FC48
	ldrb r0, [r4]
	movs r2, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	strh r3, [r0, #0x28]
	ldrb r0, [r4]
	muls r0, r2, r0
	adds r1, #0x28
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #0x2a
	movs r2, #0
	movs r3, #2
	bl BtlController_EmitSetMonData
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r1, _0804FC4C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0804FC34:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804FC3C: .4byte 0x02023D0C
_0804FC40: .4byte 0x02023D08
_0804FC44: .4byte 0x02023EAF
_0804FC48: .4byte 0x02023D28
_0804FC4C: .4byte 0x02023EB8
	thumb_func_end atk79_setatkhptozero

	thumb_func_start atk7A_jumpifnexttargetvalid
atk7A_jumpifnexttargetvalid: @ 0x0804FC50
	push {r4, r5, r6, r7, lr}
	ldr r3, _0804FCC8
	ldr r2, [r3]
	ldrb r4, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r4, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r4, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r4, r0
	ldr r0, _0804FCCC
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r7, r3, #0
	cmp r0, #0
	beq _0804FCE8
	ldr r0, _0804FCD0
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r2, _0804FCD4
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r3, r0, #0
	ldr r6, _0804FCD8
	ldr r5, _0804FCDC
	ldr r0, _0804FCE0
	mov ip, r0
	ldrb r0, [r2]
	cmp r1, r0
	bne _0804FCA6
_0804FC96:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r2]
	cmp r0, r1
	beq _0804FC96
_0804FCA6:
	ldrb r0, [r6]
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r5
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0804FC96
	ldrb r0, [r3]
	mov r2, ip
	ldrb r2, [r2]
	cmp r0, r2
	blo _0804FCE4
	ldr r0, [r7]
	adds r0, #5
	str r0, [r7]
	b _0804FCEC
	.align 2, 0
_0804FCC8: .4byte 0x02023EB8
_0804FCCC: .4byte 0x02022C90
_0804FCD0: .4byte 0x02023EB0
_0804FCD4: .4byte 0x02023EAF
_0804FCD8: .4byte 0x02023EB4
_0804FCDC: .4byte 0x082FACB4
_0804FCE0: .4byte 0x02023D10
_0804FCE4:
	str r4, [r7]
	b _0804FCEC
_0804FCE8:
	adds r0, r2, #5
	str r0, [r3]
_0804FCEC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end atk7A_jumpifnexttargetvalid

	thumb_func_start atk7B_tryhealhalfhealth
atk7B_tryhealhalfhealth: @ 0x0804FCF4
	push {r4, r5, r6, lr}
	ldr r4, _0804FD50
	ldr r1, [r4]
	ldrb r2, [r1, #1]
	ldrb r0, [r1, #2]
	lsls r0, r0, #8
	orrs r2, r0
	ldrb r0, [r1, #3]
	lsls r0, r0, #0x10
	orrs r2, r0
	ldrb r0, [r1, #4]
	lsls r0, r0, #0x18
	orrs r2, r0
	ldrb r0, [r1, #5]
	ldr r3, _0804FD54
	cmp r0, #1
	bne _0804FD1C
	ldr r0, _0804FD58
	ldrb r0, [r0]
	strb r0, [r3]
_0804FD1C:
	ldr r1, _0804FD5C
	ldr r6, _0804FD60
	ldrb r0, [r3]
	movs r5, #0x58
	muls r0, r5, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x2c]
	lsrs r0, r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _0804FD36
	movs r0, #1
	str r0, [r1]
_0804FD36:
	ldr r0, [r1]
	rsbs r0, r0, #0
	str r0, [r1]
	ldrb r0, [r3]
	muls r0, r5, r0
	adds r0, r0, r6
	ldrh r1, [r0, #0x28]
	ldrh r0, [r0, #0x2c]
	cmp r1, r0
	bne _0804FD64
	str r2, [r4]
	b _0804FD6A
	.align 2, 0
_0804FD50: .4byte 0x02023EB8
_0804FD54: .4byte 0x02023EB0
_0804FD58: .4byte 0x02023EAF
_0804FD5C: .4byte 0x02023E94
_0804FD60: .4byte 0x02023D28
_0804FD64:
	ldr r0, [r4]
	adds r0, #6
	str r0, [r4]
_0804FD6A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end atk7B_tryhealhalfhealth

	thumb_func_start atk7C_trymirrormove
atk7C_trymirrormove: @ 0x0804FD70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r2, _0804FE10
	ldr r0, _0804FE14
	mov sl, r0
	movs r1, #0
	add r0, sp, #4
_0804FD86:
	strh r1, [r0]
	subs r0, #2
	cmp r0, sp
	bge _0804FD86
	movs r1, #0
	mov r8, r1
	movs r5, #0
	ldrb r1, [r2]
	cmp r5, r1
	bge _0804FDDC
	ldr r0, _0804FE18
	ldrb r6, [r0]
	ldr r2, _0804FE1C
	mov sb, r2
	lsls r4, r6, #3
	mov r2, sp
	ldr r0, _0804FE14
	mov ip, r0
	adds r7, r1, #0
_0804FDAC:
	cmp r5, r6
	beq _0804FDD4
	mov r1, ip
	ldr r0, [r1]
	adds r0, r4, r0
	adds r1, r0, #0
	adds r1, #0xe0
	ldrb r3, [r1]
	adds r0, #0xe1
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r3, r0
	cmp r3, #0
	beq _0804FDD4
	cmp r3, sb
	beq _0804FDD4
	strh r3, [r2]
	adds r2, #2
	movs r0, #1
	add r8, r0
_0804FDD4:
	adds r4, #2
	adds r5, #1
	cmp r5, r7
	blt _0804FDAC
_0804FDDC:
	ldr r1, _0804FE18
	ldrb r0, [r1]
	mov r2, sl
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x98
	ldrb r3, [r1]
	adds r0, #0x99
	ldrb r0, [r0]
	lsls r0, r0, #8
	orrs r3, r0
	cmp r3, #0
	beq _0804FE2C
	ldr r0, _0804FE1C
	cmp r3, r0
	beq _0804FE2C
	ldr r2, _0804FE20
	ldr r0, [r2]
	ldr r1, _0804FE24
	ands r0, r1
	str r0, [r2]
	ldr r4, _0804FE28
	strh r3, [r4]
	b _0804FE56
	.align 2, 0
_0804FE10: .4byte 0x02023D10
_0804FE14: .4byte 0x02024140
_0804FE18: .4byte 0x02023EAF
_0804FE1C: .4byte 0x0000FFFF
_0804FE20: .4byte 0x02023F24
_0804FE24: .4byte 0xFFFFFBFF
_0804FE28: .4byte 0x02023E8E
_0804FE2C:
	mov r0, r8
	cmp r0, #0
	beq _0804FE9C
	ldr r2, _0804FE80
	ldr r0, [r2]
	ldr r1, _0804FE84
	ands r0, r1
	str r0, [r2]
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, r8
	bl __modsi3
	adds r5, r0, #0
	ldr r4, _0804FE88
	lsls r0, r5, #1
	add r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
_0804FE56:
	ldrh r0, [r4]
	movs r1, #0
	bl GetMoveTarget
	ldr r1, _0804FE8C
	strb r0, [r1]
	ldr r5, _0804FE90
	ldr r3, _0804FE94
	ldr r2, _0804FE98
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r5]
	b _0804FEBA
	.align 2, 0
_0804FE80: .4byte 0x02023F24
_0804FE84: .4byte 0xFFFFFBFF
_0804FE88: .4byte 0x02023E8E
_0804FE8C: .4byte 0x02023EB0
_0804FE90: .4byte 0x02023EB8
_0804FE94: .4byte 0x08286C30
_0804FE98: .4byte 0x082ED220
_0804FE9C:
	ldr r2, _0804FECC
	ldr r0, _0804FED0
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r1, _0804FED4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0804FEBA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804FECC: .4byte 0x02024020
_0804FED0: .4byte 0x02023EAF
_0804FED4: .4byte 0x02023EB8
	thumb_func_end atk7C_trymirrormove

	thumb_func_start atk7D_setrain
atk7D_setrain: @ 0x0804FED8
	push {lr}
	ldr r2, _0804FEF8
	ldrh r0, [r2]
	movs r1, #7
	ands r1, r0
	cmp r1, #0
	beq _0804FF04
	ldr r2, _0804FEFC
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _0804FF00
	movs r0, #2
	strb r0, [r1, #5]
	b _0804FF14
	.align 2, 0
_0804FEF8: .4byte 0x02024070
_0804FEFC: .4byte 0x02023F20
_0804FF00: .4byte 0x02023FD6
_0804FF04:
	movs r0, #1
	strh r0, [r2]
	ldr r0, _0804FF20
	strb r1, [r0, #5]
	ldr r0, _0804FF24
	adds r0, #0x28
	movs r1, #5
	strb r1, [r0]
_0804FF14:
	ldr r1, _0804FF28
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0804FF20: .4byte 0x02023FD6
_0804FF24: .4byte 0x02024074
_0804FF28: .4byte 0x02023EB8
	thumb_func_end atk7D_setrain

	thumb_func_start atk7E_setreflect
atk7E_setreflect: @ 0x0804FF2C
	push {r4, r5, r6, lr}
	ldr r6, _0804FF5C
	ldrb r0, [r6]
	bl GetBattlerPosition
	ldr r4, _0804FF60
	movs r5, #1
	adds r1, r5, #0
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _0804FF6C
	ldr r2, _0804FF64
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _0804FF68
	movs r0, #0
	b _0804FFE0
	.align 2, 0
_0804FF5C: .4byte 0x02023EAF
_0804FF60: .4byte 0x02023F32
_0804FF64: .4byte 0x02023F20
_0804FF68: .4byte 0x02023FD6
_0804FF6C:
	ldrb r0, [r6]
	bl GetBattlerPosition
	adds r1, r5, #0
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	movs r2, #1
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r6]
	bl GetBattlerPosition
	ldr r4, _0804FFD0
	adds r1, r5, #0
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #5
	strb r1, [r0]
	ldrb r0, [r6]
	bl GetBattlerPosition
	adds r1, r5, #0
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r1, [r6]
	strb r1, [r0, #1]
	ldr r0, _0804FFD4
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	beq _0804FFDC
	movs r0, #1
	bl CountAliveMonsInBattle
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #2
	bne _0804FFDC
	ldr r0, _0804FFD8
	strb r1, [r0, #5]
	b _0804FFE2
	.align 2, 0
_0804FFD0: .4byte 0x02023F38
_0804FFD4: .4byte 0x02022C90
_0804FFD8: .4byte 0x02023FD6
_0804FFDC:
	ldr r1, _0804FFF0
	movs r0, #1
_0804FFE0:
	strb r0, [r1, #5]
_0804FFE2:
	ldr r1, _0804FFF4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0804FFF0: .4byte 0x02023FD6
_0804FFF4: .4byte 0x02023EB8
	thumb_func_end atk7E_setreflect

	thumb_func_start atk7F_setseeded
atk7F_setseeded: @ 0x0804FFF8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r7, _08050038
	ldrb r5, [r7]
	movs r0, #0x29
	ands r0, r5
	cmp r0, #0
	bne _0805002A
	ldr r0, _0805003C
	mov sb, r0
	ldr r1, _08050040
	mov r8, r1
	ldrb r4, [r1]
	lsls r0, r4, #2
	mov r2, sb
	adds r6, r0, r2
	ldr r2, [r6]
	movs r0, #4
	mov ip, r0
	adds r3, r2, #0
	ands r3, r0
	cmp r3, #0
	beq _08050048
_0805002A:
	movs r0, #1
	orrs r0, r5
	strb r0, [r7]
	ldr r1, _08050044
	movs r0, #1
	strb r0, [r1, #5]
	b _08050098
	.align 2, 0
_08050038: .4byte 0x02023F20
_0805003C: .4byte 0x02023F50
_08050040: .4byte 0x02023EB0
_08050044: .4byte 0x02023FD6
_08050048:
	ldr r1, _08050074
	movs r0, #0x58
	muls r0, r4, r0
	adds r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #0xc
	beq _08050064
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xc
	bne _0805007C
_08050064:
	movs r0, #1
	orrs r0, r5
	strb r0, [r7]
	ldr r1, _08050078
	movs r0, #2
	strb r0, [r1, #5]
	b _08050098
	.align 2, 0
_08050074: .4byte 0x02023D28
_08050078: .4byte 0x02023FD6
_0805007C:
	ldr r0, _080500AC
	ldrb r0, [r0]
	orrs r2, r0
	str r2, [r6]
	mov r2, r8
	ldrb r1, [r2]
	lsls r1, r1, #2
	add r1, sb
	ldr r0, [r1]
	mov r2, ip
	orrs r0, r2
	str r0, [r1]
	ldr r0, _080500B0
	strb r3, [r0, #5]
_08050098:
	ldr r1, _080500B4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080500AC: .4byte 0x02023EAF
_080500B0: .4byte 0x02023FD6
_080500B4: .4byte 0x02023EB8
	thumb_func_end atk7F_setseeded

	thumb_func_start atk80_manipulatedamage
atk80_manipulatedamage: @ 0x080500B8
	push {r4, lr}
	ldr r1, _080500D0
	ldr r0, [r1]
	ldrb r2, [r0, #1]
	adds r4, r1, #0
	cmp r2, #1
	beq _080500E8
	cmp r2, #1
	bgt _080500D4
	cmp r2, #0
	beq _080500DA
	b _08050128
	.align 2, 0
_080500D0: .4byte 0x02023EB8
_080500D4:
	cmp r2, #2
	beq _08050120
	b _08050128
_080500DA:
	ldr r1, _080500E4
	ldr r0, [r1]
	rsbs r0, r0, #0
	b _08050126
	.align 2, 0
_080500E4: .4byte 0x02023E94
_080500E8:
	ldr r3, _08050114
	ldr r0, [r3]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	str r0, [r3]
	cmp r0, #0
	bne _080500FA
	str r2, [r3]
_080500FA:
	ldr r2, _08050118
	ldr r0, _0805011C
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r0, [r0, #0x2c]
	lsrs r1, r0, #1
	ldr r0, [r3]
	cmp r1, r0
	bge _08050128
	str r1, [r3]
	b _08050128
	.align 2, 0
_08050114: .4byte 0x02023E94
_08050118: .4byte 0x02023D28
_0805011C: .4byte 0x02023EB0
_08050120:
	ldr r1, _08050134
	ldr r0, [r1]
	lsls r0, r0, #1
_08050126:
	str r0, [r1]
_08050128:
	ldr r0, [r4]
	adds r0, #2
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08050134: .4byte 0x02023E94
	thumb_func_end atk80_manipulatedamage

	thumb_func_start atk81_trysetrest
atk81_trysetrest: @ 0x08050138
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r0, _08050190
	mov ip, r0
	ldr r1, [r0]
	ldrb r6, [r1, #1]
	ldrb r0, [r1, #2]
	lsls r0, r0, #8
	orrs r6, r0
	ldrb r0, [r1, #3]
	lsls r0, r0, #0x10
	orrs r6, r0
	ldrb r0, [r1, #4]
	lsls r0, r0, #0x18
	orrs r6, r0
	ldr r5, _08050194
	ldr r2, _08050198
	ldr r0, _0805019C
	ldrb r0, [r0]
	strb r0, [r2]
	strb r0, [r5]
	ldr r4, _080501A0
	ldr r1, _080501A4
	ldrb r0, [r2]
	movs r3, #0x58
	muls r0, r3, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x2c]
	rsbs r0, r0, #0
	str r0, [r4]
	ldrb r0, [r2]
	adds r4, r0, #0
	muls r4, r3, r4
	adds r0, r4, r1
	ldrh r3, [r0, #0x28]
	adds r7, r5, #0
	adds r5, r2, #0
	adds r2, r1, #0
	ldrh r0, [r0, #0x2c]
	cmp r3, r0
	bne _080501A8
	mov r0, ip
	str r6, [r0]
	b _080501F8
	.align 2, 0
_08050190: .4byte 0x02023EB8
_08050194: .4byte 0x02023D08
_08050198: .4byte 0x02023EB0
_0805019C: .4byte 0x02023EAF
_080501A0: .4byte 0x02023E94
_080501A4: .4byte 0x02023D28
_080501A8:
	adds r0, r2, #0
	adds r0, #0x4c
	adds r0, r4, r0
	ldr r1, [r0]
	movs r0, #0xf8
	ands r1, r0
	cmp r1, #0
	beq _080501C4
	ldr r1, _080501C0
	movs r0, #1
	strb r0, [r1, #5]
	b _080501C8
	.align 2, 0
_080501C0: .4byte 0x02023FD6
_080501C4:
	ldr r0, _08050200
	strb r1, [r0, #5]
_080501C8:
	ldrb r0, [r5]
	movs r3, #0x58
	muls r0, r3, r0
	adds r2, #0x4c
	adds r0, r0, r2
	movs r1, #3
	str r1, [r0]
	ldrb r0, [r7]
	muls r0, r3, r0
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #0
	movs r1, #0x28
	movs r2, #0
	movs r3, #4
	bl BtlController_EmitSetMonData
	ldrb r0, [r7]
	bl MarkBattlerForControllerExec
	ldr r1, _08050204
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_080501F8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08050200: .4byte 0x02023FD6
_08050204: .4byte 0x02023EB8
	thumb_func_end atk81_trysetrest

	thumb_func_start atk82_jumpifnotfirstturn
atk82_jumpifnotfirstturn: @ 0x08050208
	push {r4, r5, lr}
	ldr r5, _0805023C
	ldr r4, [r5]
	ldrb r3, [r4, #1]
	ldrb r0, [r4, #2]
	lsls r0, r0, #8
	orrs r3, r0
	ldrb r0, [r4, #3]
	lsls r0, r0, #0x10
	orrs r3, r0
	ldrb r0, [r4, #4]
	lsls r0, r0, #0x18
	orrs r3, r0
	ldr r2, _08050240
	ldr r0, _08050244
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #0x16]
	cmp r0, #0
	beq _08050248
	adds r0, r4, #5
	str r0, [r5]
	b _0805024A
	.align 2, 0
_0805023C: .4byte 0x02023EB8
_08050240: .4byte 0x02023F60
_08050244: .4byte 0x02023EAF
_08050248:
	str r3, [r5]
_0805024A:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end atk82_jumpifnotfirstturn

	thumb_func_start atk83_nop
atk83_nop: @ 0x08050250
	ldr r1, _0805025C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_0805025C: .4byte 0x02023EB8
	thumb_func_end atk83_nop

	thumb_func_start UproarWakeUpCheck
UproarWakeUpCheck: @ 0x08050260
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	movs r2, #0
	ldr r0, _080502B8
	ldrb r1, [r0]
	mov r8, r0
	cmp r2, r1
	bge _080502D4
	ldr r0, _080502BC
	mov ip, r0
	movs r0, #0x58
	muls r0, r3, r0
	add r0, ip
	adds r5, r0, #0
	adds r5, #0x20
	adds r4, r1, #0
	movs r3, #0
	ldr r6, _080502C0
	ldr r7, _080502C4
_0805028C:
	mov r0, ip
	adds r0, #0x50
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, #0x70
	ands r0, r1
	cmp r0, #0
	beq _080502CC
	ldrb r0, [r5]
	cmp r0, #0x2b
	beq _080502CC
	movs r3, #0
	strb r2, [r6, #0x17]
	ldr r1, _080502C8
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _080502EC
	cmp r0, r2
	beq _080502E0
	movs r0, #1
	strb r0, [r7, #5]
	b _080502D4
	.align 2, 0
_080502B8: .4byte 0x02023D10
_080502BC: .4byte 0x02023D28
_080502C0: .4byte 0x02024118
_080502C4: .4byte 0x02023FD6
_080502C8: .4byte 0x02023EB0
_080502CC:
	adds r3, #0x58
	adds r2, #1
	cmp r2, r4
	blt _0805028C
_080502D4:
	mov r1, r8
	ldrb r1, [r1]
	cmp r2, r1
	beq _080502F0
	movs r0, #1
	b _080502F2
_080502E0:
	ldr r0, _080502E8
	strb r3, [r0, #5]
	b _080502D4
	.align 2, 0
_080502E8: .4byte 0x02023FD6
_080502EC:
	strb r2, [r1]
	b _080502D4
_080502F0:
	movs r0, #0
_080502F2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end UproarWakeUpCheck

	thumb_func_start atk84_jumpifcantmakeasleep
atk84_jumpifcantmakeasleep: @ 0x080502FC
	push {r4, r5, r6, lr}
	ldr r5, _08050328
	ldr r1, [r5]
	ldrb r4, [r1, #1]
	ldrb r0, [r1, #2]
	lsls r0, r0, #8
	orrs r4, r0
	ldrb r0, [r1, #3]
	lsls r0, r0, #0x10
	orrs r4, r0
	ldrb r0, [r1, #4]
	lsls r0, r0, #0x18
	orrs r4, r0
	ldr r6, _0805032C
	ldrb r0, [r6]
	bl UproarWakeUpCheck
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08050330
	str r4, [r5]
	b _08050372
	.align 2, 0
_08050328: .4byte 0x02023EB8
_0805032C: .4byte 0x02023EB0
_08050330:
	ldr r1, _08050360
	ldrb r3, [r6]
	movs r0, #0x58
	muls r0, r3, r0
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r0, [r0]
	adds r1, r0, #0
	cmp r1, #0xf
	beq _08050348
	cmp r1, #0x48
	bne _0805036C
_08050348:
	ldr r2, _08050364
	strb r0, [r2]
	ldr r1, _08050368
	movs r0, #2
	strb r0, [r1, #5]
	str r4, [r5]
	ldrb r1, [r2]
	adds r0, r3, #0
	bl RecordAbilityBattle
	b _08050372
	.align 2, 0
_08050360: .4byte 0x02023D28
_08050364: .4byte 0x02023EAE
_08050368: .4byte 0x02023FD6
_0805036C:
	ldr r0, [r5]
	adds r0, #5
	str r0, [r5]
_08050372:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	thumb_func_end atk84_jumpifcantmakeasleep

	thumb_func_start atk85_stockpile
atk85_stockpile: @ 0x08050378
	push {r4, r5, lr}
	ldr r5, _080503A0
	ldr r4, _080503A4
	ldrb r1, [r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r5
	ldrb r0, [r1, #9]
	cmp r0, #3
	bne _080503B0
	ldr r2, _080503A8
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _080503AC
	movs r0, #1
	strb r0, [r1, #5]
	b _080503DA
	.align 2, 0
_080503A0: .4byte 0x02023F60
_080503A4: .4byte 0x02023EAF
_080503A8: .4byte 0x02023F20
_080503AC: .4byte 0x02023FD6
_080503B0:
	adds r0, #1
	movs r3, #0
	strb r0, [r1, #9]
	ldr r2, _080503E8
	movs r0, #0xfd
	strb r0, [r2]
	movs r0, #1
	strb r0, [r2, #1]
	strb r0, [r2, #2]
	strb r0, [r2, #3]
	ldrb r1, [r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrb r0, [r0, #9]
	strb r0, [r2, #4]
	movs r0, #0xff
	strb r0, [r2, #5]
	ldr r0, _080503EC
	strb r3, [r0, #5]
_080503DA:
	ldr r1, _080503F0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080503E8: .4byte 0x02022C0C
_080503EC: .4byte 0x02023FD6
_080503F0: .4byte 0x02023EB8
	thumb_func_end atk85_stockpile

	thumb_func_start atk86_stockpiletobasedamage
atk86_stockpiletobasedamage: @ 0x080503F4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	ldr r3, _0805042C
	ldr r1, [r3]
	ldrb r2, [r1, #1]
	ldrb r0, [r1, #2]
	lsls r0, r0, #8
	orrs r2, r0
	ldrb r0, [r1, #3]
	lsls r0, r0, #0x10
	orrs r2, r0
	ldrb r0, [r1, #4]
	lsls r0, r0, #0x18
	orrs r2, r0
	ldr r7, _08050430
	ldr r6, _08050434
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrb r0, [r0, #9]
	cmp r0, #0
	bne _08050438
	str r2, [r3]
	b _080504DA
	.align 2, 0
_0805042C: .4byte 0x02023EB8
_08050430: .4byte 0x02023F60
_08050434: .4byte 0x02023EAF
_08050438:
	ldr r0, _080504E8
	ldrb r0, [r0, #6]
	cmp r0, #1
	beq _080504C0
	ldr r0, _080504EC
	mov r8, r0
	ldr r4, _080504F0
	ldr r5, _080504F4
	ldrb r0, [r5]
	bl GetBattlerPosition
	movs r1, #1
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r3, [r1]
	ldrb r0, [r6]
	movs r4, #0x58
	muls r0, r4, r0
	ldr r2, _080504F8
	adds r0, r0, r2
	ldrb r1, [r5]
	muls r1, r4, r1
	adds r1, r1, r2
	ldr r2, _080504FC
	ldrh r2, [r2]
	movs r4, #0
	str r4, [sp]
	str r4, [sp, #4]
	ldrb r4, [r6]
	str r4, [sp, #8]
	ldrb r4, [r5]
	str r4, [sp, #0xc]
	bl CalculateBaseDamage
	ldrb r2, [r6]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r7
	ldrb r1, [r1, #9]
	adds r3, r0, #0
	muls r3, r1, r3
	mov r1, r8
	str r3, [r1]
	ldr r2, _08050500
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrb r0, [r0, #9]
	strb r0, [r2, #0x18]
	ldr r1, _08050504
	ldrb r0, [r6]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	cmp r0, #0
	bge _080504C0
	lsls r0, r3, #4
	subs r0, r0, r3
	movs r1, #0xa
	bl __divsi3
	mov r1, r8
	str r0, [r1]
_080504C0:
	ldr r2, _08050508
	ldr r0, _0805050C
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #0
	strb r1, [r0, #9]
	ldr r1, _08050510
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_080504DA:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080504E8: .4byte 0x02023FD6
_080504EC: .4byte 0x02023E94
_080504F0: .4byte 0x02023F32
_080504F4: .4byte 0x02023EB0
_080504F8: .4byte 0x02023D28
_080504FC: .4byte 0x02023E8E
_08050500: .4byte 0x02024118
_08050504: .4byte 0x02023FE0
_08050508: .4byte 0x02023F60
_0805050C: .4byte 0x02023EAF
_08050510: .4byte 0x02023EB8
	thumb_func_end atk86_stockpiletobasedamage

	thumb_func_start atk87_stockpiletohpheal
atk87_stockpiletohpheal: @ 0x08050514
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, _08050554
	ldr r1, [r7]
	ldrb r2, [r1, #1]
	ldrb r0, [r1, #2]
	lsls r0, r0, #8
	orrs r2, r0
	ldrb r0, [r1, #3]
	lsls r0, r0, #0x10
	orrs r2, r0
	ldrb r0, [r1, #4]
	lsls r0, r0, #0x18
	orrs r2, r0
	ldr r0, _08050558
	mov r8, r0
	ldr r6, _0805055C
	ldrb r3, [r6]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #2
	mov r1, r8
	adds r4, r0, r1
	ldrb r1, [r4, #9]
	cmp r1, #0
	bne _08050564
	str r2, [r7]
	ldr r0, _08050560
	strb r1, [r0, #5]
	b _080505E0
	.align 2, 0
_08050554: .4byte 0x02023EB8
_08050558: .4byte 0x02023F60
_0805055C: .4byte 0x02023EAF
_08050560: .4byte 0x02023FD6
_08050564:
	ldr r1, _08050588
	movs r0, #0x58
	muls r0, r3, r0
	adds r1, r0, r1
	ldrh r0, [r1, #0x2c]
	ldrh r3, [r1, #0x28]
	cmp r0, r3
	bne _08050594
	movs r0, #0
	strb r0, [r4, #9]
	str r2, [r7]
	ldr r1, _0805058C
	ldrb r0, [r6]
	strb r0, [r1]
	ldr r1, _08050590
	movs r0, #1
	strb r0, [r1, #5]
	b _080505E0
	.align 2, 0
_08050588: .4byte 0x02023D28
_0805058C: .4byte 0x02023EB0
_08050590: .4byte 0x02023FD6
_08050594:
	ldr r5, _080505EC
	ldrh r0, [r1, #0x2c]
	ldrb r1, [r4, #9]
	movs r2, #3
	subs r2, r2, r1
	movs r4, #1
	adds r1, r4, #0
	lsls r1, r2
	bl __divsi3
	str r0, [r5]
	cmp r0, #0
	bne _080505B0
	str r4, [r5]
_080505B0:
	ldr r0, [r5]
	rsbs r0, r0, #0
	str r0, [r5]
	ldr r3, _080505F0
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0, #9]
	movs r2, #0
	strb r0, [r3, #0x18]
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	strb r2, [r0, #9]
	ldr r0, [r7]
	adds r0, #5
	str r0, [r7]
	ldr r1, _080505F4
	ldrb r0, [r6]
	strb r0, [r1]
_080505E0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080505EC: .4byte 0x02023E94
_080505F0: .4byte 0x02024118
_080505F4: .4byte 0x02023EB0
	thumb_func_end atk87_stockpiletohpheal

	thumb_func_start atk88_negativedamage
atk88_negativedamage: @ 0x080505F8
	push {lr}
	ldr r2, _08050620
	ldr r0, _08050624
	ldr r0, [r0]
	lsrs r1, r0, #0x1f
	adds r0, r0, r1
	asrs r0, r0, #1
	rsbs r0, r0, #0
	str r0, [r2]
	cmp r0, #0
	bne _08050614
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r2]
_08050614:
	ldr r1, _08050628
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08050620: .4byte 0x02023E94
_08050624: .4byte 0x02023E98
_08050628: .4byte 0x02023EB8
	thumb_func_end atk88_negativedamage

	thumb_func_start ChangeStatBuffs
ChangeStatBuffs: @ 0x0805062C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r3
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	movs r0, #0
	mov sb, r0
	mov sl, r0
	movs r0, #0x40
	ands r0, r5
	cmp r0, #0
	beq _08050660
	ldr r0, _08050658
	ldr r1, _0805065C
	b _08050664
	.align 2, 0
_08050658: .4byte 0x02023D08
_0805065C: .4byte 0x02023EAF
_08050660:
	ldr r0, _08050704
	ldr r1, _08050708
_08050664:
	ldrb r1, [r1]
	strb r1, [r0]
	movs r0, #0xbf
	ands r5, r0
	movs r0, #0x80
	ands r0, r5
	cmp r0, #0
	beq _0805067E
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_0805067E:
	movs r0, #0x7f
	ands r5, r0
	movs r0, #0x20
	ands r0, r5
	cmp r0, #0
	beq _08050694
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
_08050694:
	movs r0, #0xdf
	ands r5, r0
	ldr r1, _0805070C
	movs r4, #0
	movs r2, #0xfd
	strb r2, [r1]
	movs r0, #5
	strb r0, [r1, #1]
	strb r7, [r1, #2]
	movs r3, #1
	rsbs r3, r3, #0
	mov ip, r3
	movs r0, #0xff
	strb r0, [r1, #3]
	lsls r0, r6, #0x18
	cmp r0, #0
	blt _080506B8
	b _0805099C
_080506B8:
	ldr r4, _08050710
	ldr r1, _08050704
	ldrb r0, [r1]
	bl GetBattlerPosition
	movs r1, #1
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _08050758
	mov r2, sb
	cmp r2, #0
	bne _08050758
	ldr r0, _08050714
	ldrh r0, [r0]
	cmp r0, #0xae
	beq _08050788
	cmp r5, #1
	bne _08050778
	ldr r4, _08050718
	ldr r3, _08050704
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r0, [r1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08050720
	ldr r0, _0805071C
	mov r4, r8
	str r4, [r0]
	b _08050778
	.align 2, 0
_08050704: .4byte 0x02023D08
_08050708: .4byte 0x02023EB0
_0805070C: .4byte 0x02022C0C
_08050710: .4byte 0x02023F38
_08050714: .4byte 0x02023E8E
_08050718: .4byte 0x02024020
_0805071C: .4byte 0x02023EB8
_08050720:
	mov r0, r8
	bl BattleScriptPush
	ldr r1, _08050748
	ldr r6, _0805074C
	ldrb r0, [r6]
	strb r0, [r1, #0x17]
	ldr r1, _08050750
	ldr r0, _08050754
	str r0, [r1]
	ldrb r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	strb r1, [r0]
	b _08050778
	.align 2, 0
_08050748: .4byte 0x02024118
_0805074C: .4byte 0x02023D08
_08050750: .4byte 0x02023EB8
_08050754: .4byte 0x0828938B
_08050758:
	ldr r0, _0805077C
	ldrh r0, [r0]
	cmp r0, #0xae
	beq _08050788
	mov r0, sl
	cmp r0, #1
	beq _08050788
	movs r0, #0
	bl JumpIfMoveAffectedByProtect
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08050788
	ldr r1, _08050780
	ldr r0, _08050784
	str r0, [r1]
_08050778:
	movs r0, #1
	b _08050A90
	.align 2, 0
_0805077C: .4byte 0x02023E8E
_08050780: .4byte 0x02023EB8
_08050784: .4byte 0x082884A4
_08050788:
	ldr r2, _080507D0
	ldr r1, _080507D4
	ldrb r3, [r1]
	movs r4, #0x58
	adds r0, r3, #0
	muls r0, r4, r0
	adds r0, r0, r2
	adds r0, #0x20
	ldrb r0, [r0]
	mov sl, r2
	cmp r0, #0x1d
	beq _080507A4
	cmp r0, #0x49
	bne _0805083C
_080507A4:
	mov r0, sb
	cmp r0, #0
	bne _0805083C
	ldr r0, _080507D8
	ldrh r0, [r0]
	cmp r0, #0xae
	beq _0805083C
	cmp r5, #1
	bne _08050778
	ldr r4, _080507DC
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _080507E4
	ldr r0, _080507E0
	mov r1, r8
	str r1, [r0]
	b _08050778
	.align 2, 0
_080507D0: .4byte 0x02023D28
_080507D4: .4byte 0x02023D08
_080507D8: .4byte 0x02023E8E
_080507DC: .4byte 0x02024020
_080507E0: .4byte 0x02023EB8
_080507E4:
	mov r0, r8
	bl BattleScriptPush
	ldr r1, _08050828
	ldr r2, _0805082C
	ldrb r0, [r2]
	strb r0, [r1, #0x17]
	ldr r1, _08050830
	ldr r0, _08050834
	str r0, [r1]
	ldr r1, _08050838
	ldrb r0, [r2]
	movs r3, #0x58
	muls r0, r3, r0
	add r0, sl
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2]
	ldrb r1, [r1]
	bl RecordAbilityBattle
	ldr r6, _0805082C
	ldrb r1, [r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	strb r1, [r0]
	b _08050778
	.align 2, 0
_08050828: .4byte 0x02024118
_0805082C: .4byte 0x02023D08
_08050830: .4byte 0x02023EB8
_08050834: .4byte 0x08289B4F
_08050838: .4byte 0x02023EAE
_0805083C:
	ldr r1, _08050888
	ldrb r0, [r1]
	movs r4, #0x58
	muls r0, r4, r0
	add r0, sl
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x33
	bne _0805089C
	mov r2, sb
	cmp r2, #0
	bne _0805089C
	cmp r7, #6
	bne _0805089C
	cmp r5, #1
	bne _08050778
	mov r0, r8
	bl BattleScriptPush
	ldr r1, _0805088C
	ldr r3, _08050888
	ldrb r0, [r3]
	strb r0, [r1, #0x17]
	ldr r1, _08050890
	ldr r0, _08050894
	str r0, [r1]
	ldr r1, _08050898
	ldrb r0, [r3]
	muls r0, r4, r0
	add r0, sl
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r3]
	ldrb r1, [r1]
	bl RecordAbilityBattle
	b _08050778
	.align 2, 0
_08050888: .4byte 0x02023D08
_0805088C: .4byte 0x02024118
_08050890: .4byte 0x02023EB8
_08050894: .4byte 0x08289BB7
_08050898: .4byte 0x02023EAE
_0805089C:
	ldr r4, _080508EC
	ldrb r0, [r4]
	movs r4, #0x58
	muls r0, r4, r0
	add r0, sl
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x34
	bne _08050900
	mov r0, sb
	cmp r0, #0
	bne _08050900
	cmp r7, #1
	bne _08050900
	cmp r5, #1
	beq _080508BE
	b _08050778
_080508BE:
	mov r0, r8
	bl BattleScriptPush
	ldr r1, _080508F0
	ldr r2, _080508EC
	ldrb r0, [r2]
	strb r0, [r1, #0x17]
	ldr r1, _080508F4
	ldr r0, _080508F8
	str r0, [r1]
	ldr r1, _080508FC
	ldrb r0, [r2]
	muls r0, r4, r0
	add r0, sl
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r2]
	ldrb r1, [r1]
	bl RecordAbilityBattle
	b _08050778
	.align 2, 0
_080508EC: .4byte 0x02023D08
_080508F0: .4byte 0x02024118
_080508F4: .4byte 0x02023EB8
_080508F8: .4byte 0x08289BB7
_080508FC: .4byte 0x02023EAE
_08050900:
	ldr r3, _0805098C
	ldrb r1, [r3]
	movs r0, #0x58
	muls r0, r1, r0
	add r0, sl
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x13
	bne _08050918
	cmp r5, #0
	bne _08050918
	b _08050778
_08050918:
	lsls r0, r6, #0x18
	asrs r0, r0, #0x1c
	movs r1, #7
	ands r0, r1
	rsbs r0, r0, #0
	lsls r0, r0, #0x18
	ldr r3, _08050990
	movs r4, #0
	movs r1, #0xfd
	strb r1, [r3]
	movs r2, #1
	lsrs r6, r0, #0x18
	asrs r0, r0, #0x18
	subs r1, #0xff
	cmp r0, r1
	bne _08050942
	strb r4, [r3, #1]
	movs r0, #0xd3
	strb r0, [r3, #2]
	strb r4, [r3, #3]
	movs r2, #4
_08050942:
	adds r0, r2, r3
	strb r4, [r0]
	adds r2, #1
	adds r1, r2, r3
	movs r0, #0xd4
	strb r0, [r1]
	adds r2, #1
	adds r0, r2, r3
	strb r4, [r0]
	adds r2, #1
	adds r1, r2, r3
	movs r0, #0xff
	strb r0, [r1]
	ldr r4, _0805098C
	ldrb r2, [r4]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r7, r0
	mov r1, sl
	adds r1, #0x18
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	beq _080509F2
	movs r1, #0
	ldr r0, _08050994
	ldrb r0, [r0]
	ldr r3, _08050998
	mov r8, r3
	cmp r0, r2
	bne _08050986
	movs r1, #1
_08050986:
	mov r4, r8
	strb r1, [r4, #5]
	b _08050A20
	.align 2, 0
_0805098C: .4byte 0x02023D08
_08050990: .4byte 0x02022C1C
_08050994: .4byte 0x02023EB0
_08050998: .4byte 0x02023FD6
_0805099C:
	asrs r6, r0, #0x1c
	movs r0, #7
	ands r6, r0
	ldr r3, _080509FC
	strb r2, [r3]
	movs r2, #1
	cmp r6, #2
	bne _080509B6
	strb r4, [r3, #1]
	movs r0, #0xd1
	strb r0, [r3, #2]
	strb r4, [r3, #3]
	movs r2, #4
_080509B6:
	adds r0, r2, r3
	strb r4, [r0]
	adds r2, #1
	adds r1, r2, r3
	movs r0, #0xd2
	strb r0, [r1]
	adds r2, #1
	adds r0, r2, r3
	strb r4, [r0]
	adds r2, #1
	adds r1, r2, r3
	ldrb r0, [r1]
	mov r2, ip
	orrs r0, r2
	strb r0, [r1]
	ldr r2, _08050A00
	ldr r4, _08050A04
	ldrb r3, [r4]
	movs r0, #0x58
	muls r0, r3, r0
	adds r0, r7, r0
	adds r1, r2, #0
	adds r1, #0x18
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov sl, r2
	cmp r0, #0xc
	bne _08050A0C
_080509F2:
	ldr r1, _08050A08
	movs r0, #2
	strb r0, [r1, #5]
	mov r8, r1
	b _08050A20
	.align 2, 0
_080509FC: .4byte 0x02022C1C
_08050A00: .4byte 0x02023D28
_08050A04: .4byte 0x02023D08
_08050A08: .4byte 0x02023FD6
_08050A0C:
	movs r1, #0
	ldr r0, _08050AA0
	ldrb r0, [r0]
	ldr r2, _08050AA4
	mov r8, r2
	cmp r0, r3
	bne _08050A1C
	movs r1, #1
_08050A1C:
	mov r3, r8
	strb r1, [r3, #5]
_08050A20:
	ldr r2, _08050AA8
	ldrb r0, [r2]
	movs r4, #0x58
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r7, r1
	mov r3, sl
	adds r3, #0x18
	adds r1, r1, r3
	lsls r0, r6, #0x18
	asrs r0, r0, #0x18
	ldrb r6, [r1]
	adds r0, r0, r6
	strb r0, [r1]
	ldrb r0, [r2]
	muls r0, r4, r0
	adds r0, r7, r0
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _08050A50
	movs r0, #0
	strb r0, [r1]
_08050A50:
	ldr r1, _08050AA8
	ldrb r0, [r1]
	muls r0, r4, r0
	adds r0, r7, r0
	adds r1, r0, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xc
	ble _08050A66
	movs r0, #0xc
	strb r0, [r1]
_08050A66:
	mov r2, r8
	ldrb r0, [r2, #5]
	cmp r0, #2
	bne _08050A8E
	movs r3, #1
	ands r3, r5
	cmp r3, #0
	beq _08050A80
	ldr r0, _08050AAC
	ldrb r1, [r0]
	movs r2, #1
	orrs r1, r2
	strb r1, [r0]
_08050A80:
	mov r4, r8
	ldrb r0, [r4, #5]
	cmp r0, #2
	bne _08050A8E
	cmp r3, #0
	bne _08050A8E
	b _08050778
_08050A8E:
	movs r0, #0
_08050A90:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08050AA0: .4byte 0x02023EB0
_08050AA4: .4byte 0x02023FD6
_08050AA8: .4byte 0x02023D08
_08050AAC: .4byte 0x02023F20
	thumb_func_end ChangeStatBuffs

	thumb_func_start atk89_statbuffchange
atk89_statbuffchange: @ 0x08050AB0
	push {r4, r5, lr}
	ldr r5, _08050AF4
	ldr r2, [r5]
	ldrb r3, [r2, #2]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	orrs r3, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x10
	orrs r3, r0
	ldrb r0, [r2, #5]
	lsls r0, r0, #0x18
	orrs r3, r0
	ldr r0, _08050AF8
	ldrb r4, [r0, #0x1a]
	movs r0, #0xf0
	ands r0, r4
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	movs r1, #0xf
	ands r1, r4
	ldrb r2, [r2, #1]
	bl ChangeStatBuffs
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08050AEC
	ldr r0, [r5]
	adds r0, #6
	str r0, [r5]
_08050AEC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08050AF4: .4byte 0x02023EB8
_08050AF8: .4byte 0x02024118
	thumb_func_end atk89_statbuffchange

	thumb_func_start atk8A_normalisebuffs
atk8A_normalisebuffs: @ 0x08050AFC
	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r0, _08050B44
	ldrb r1, [r0]
	ldr r0, _08050B48
	mov ip, r0
	cmp r2, r1
	bge _08050B34
	ldr r0, _08050B4C
	movs r4, #6
	adds r5, r1, #0
	movs r7, #0x58
	adds r6, r0, #0
	adds r6, #0x18
_08050B18:
	adds r3, r2, #1
	movs r1, #7
	adds r0, r2, #0
	muls r0, r7, r0
	adds r0, r0, r6
	adds r0, #7
_08050B24:
	strb r4, [r0]
	subs r0, #1
	subs r1, #1
	cmp r1, #0
	bge _08050B24
	adds r2, r3, #0
	cmp r2, r5
	blt _08050B18
_08050B34:
	mov r1, ip
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08050B44: .4byte 0x02023D10
_08050B48: .4byte 0x02023EB8
_08050B4C: .4byte 0x02023D28
	thumb_func_end atk8A_normalisebuffs

	thumb_func_start atk8B_setbide
atk8B_setbide: @ 0x08050B50
	push {r4, r5, lr}
	ldr r4, _08050BA8
	ldr r3, _08050BAC
	ldrb r0, [r3]
	movs r5, #0x58
	adds r2, r0, #0
	muls r2, r5, r2
	adds r4, #0x50
	adds r2, r2, r4
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #5
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08050BB0
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldr r1, _08050BB4
	ldrh r1, [r1]
	movs r2, #0
	strh r1, [r0]
	ldr r1, _08050BB8
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	str r2, [r0]
	ldrb r0, [r3]
	adds r1, r0, #0
	muls r1, r5, r1
	adds r1, r1, r4
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08050BBC
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08050BA8: .4byte 0x02023D28
_08050BAC: .4byte 0x02023EAF
_08050BB0: .4byte 0x02023F0C
_08050BB4: .4byte 0x02023E8E
_08050BB8: .4byte 0x02023E9C
_08050BBC: .4byte 0x02023EB8
	thumb_func_end atk8B_setbide

	thumb_func_start atk8C_confuseifrepeatingattackends
atk8C_confuseifrepeatingattackends: @ 0x08050BC0
	push {lr}
	ldr r1, _08050BF0
	ldr r0, _08050BF4
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _08050BE2
	ldr r1, _08050BF8
	movs r0, #0x75
	strb r0, [r1, #3]
_08050BE2:
	ldr r1, _08050BFC
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08050BF0: .4byte 0x02023D28
_08050BF4: .4byte 0x02023EAF
_08050BF8: .4byte 0x02023FD6
_08050BFC: .4byte 0x02023EB8
	thumb_func_end atk8C_confuseifrepeatingattackends

	thumb_func_start atk8D_setmultihitcounter
atk8D_setmultihitcounter: @ 0x08050C00
	push {r4, r5, lr}
	ldr r0, _08050C14
	ldr r0, [r0]
	ldrb r1, [r0, #1]
	cmp r1, #0
	beq _08050C1C
	ldr r0, _08050C18
	strb r1, [r0]
	b _08050C36
	.align 2, 0
_08050C14: .4byte 0x02023EB8
_08050C18: .4byte 0x02023EB6
_08050C1C:
	ldr r4, _08050C44
	bl Random
	movs r5, #3
	ands r0, r5
	strb r0, [r4]
	cmp r0, #1
	bls _08050C32
	bl Random
	ands r0, r5
_08050C32:
	adds r0, #2
	strb r0, [r4]
_08050C36:
	ldr r1, _08050C48
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08050C44: .4byte 0x02023EB6
_08050C48: .4byte 0x02023EB8
	thumb_func_end atk8D_setmultihitcounter

	thumb_func_start atk8E_initmultihitstring
atk8E_initmultihitstring: @ 0x08050C4C
	ldr r1, _08050C6C
	movs r2, #0
	movs r0, #0xfd
	strb r0, [r1, #8]
	movs r0, #1
	strb r0, [r1, #9]
	strb r0, [r1, #0xa]
	strb r0, [r1, #0xb]
	strb r2, [r1, #0xc]
	movs r0, #0xff
	strb r0, [r1, #0xd]
	ldr r1, _08050C70
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_08050C6C: .4byte 0x02024118
_08050C70: .4byte 0x02023EB8
	thumb_func_end atk8E_initmultihitstring

	thumb_func_start TryDoForceSwitchOut
TryDoForceSwitchOut: @ 0x08050C74
	push {r4, r5, r6, r7, lr}
	ldr r6, _08050CA8
	ldr r7, _08050CAC
	ldrb r0, [r7]
	movs r5, #0x58
	adds r1, r0, #0
	muls r1, r5, r1
	adds r1, r1, r6
	adds r1, #0x2a
	ldr r4, _08050CB0
	ldrb r3, [r4]
	adds r0, r3, #0
	muls r0, r5, r0
	adds r0, r0, r6
	adds r0, #0x2a
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	blo _08050CBC
	ldr r0, _08050CB4
	ldr r1, [r0]
	adds r1, r3, r1
	adds r1, #0x58
	ldr r2, _08050CB8
	lsls r0, r3, #1
	b _08050D18
	.align 2, 0
_08050CA8: .4byte 0x02023D28
_08050CAC: .4byte 0x02023EAF
_08050CB0: .4byte 0x02023EB0
_08050CB4: .4byte 0x02024140
_08050CB8: .4byte 0x02023D12
_08050CBC:
	bl Random
	movs r3, #0xff
	ands r3, r0
	ldrb r0, [r7]
	muls r0, r5, r0
	adds r0, r0, r6
	adds r0, #0x2a
	ldrb r2, [r0]
	ldrb r4, [r4]
	adds r0, r4, #0
	muls r0, r5, r0
	adds r0, r0, r6
	adds r0, #0x2a
	ldrb r1, [r0]
	adds r2, r2, r1
	adds r0, r3, #0
	muls r0, r2, r0
	asrs r0, r0, #8
	adds r0, #1
	lsrs r1, r1, #2
	cmp r0, r1
	bhi _08050D0C
	ldr r3, _08050D08
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	movs r0, #0
	b _08050D26
	.align 2, 0
_08050D08: .4byte 0x02023EB8
_08050D0C:
	ldr r0, _08050D2C
	ldr r1, [r0]
	adds r1, r4, r1
	adds r1, #0x58
	ldr r2, _08050D30
	lsls r0, r4, #1
_08050D18:
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r1, _08050D34
	ldr r0, _08050D38
	str r0, [r1]
	movs r0, #1
_08050D26:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08050D2C: .4byte 0x02024140
_08050D30: .4byte 0x02023D12
_08050D34: .4byte 0x02023EB8
_08050D38: .4byte 0x08289360
	thumb_func_end TryDoForceSwitchOut

	thumb_func_start atk8F_forcerandomswitch
atk8F_forcerandomswitch: @ 0x08050D3C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r0, #0
	str r0, [sp, #4]
	ldr r5, _08050DA8
	ldr r0, [r5]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	bne _08050D5A
	b _08051020
_08050D5A:
	ldr r4, _08050DAC
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	ldr r1, _08050DB0
	str r1, [sp]
	cmp r0, #0
	bne _08050D70
	ldr r0, _08050DB4
	str r0, [sp]
_08050D70:
	ldr r2, [r5]
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, r1
	beq _08050D92
	ldr r1, _08050DB8
	adds r0, r2, #0
	ands r0, r1
	cmp r0, r1
	beq _08050D92
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r0, r2
	cmp r0, #0
	beq _08050DD8
_08050D92:
	ldr r2, _08050DAC
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	adds r1, r2, #0
	cmp r0, #0
	beq _08050DBC
	movs r0, #3
	mov sb, r0
	movs r0, #6
	b _08050DC2
	.align 2, 0
_08050DA8: .4byte 0x02022C90
_08050DAC: .4byte 0x02023EB0
_08050DB0: .4byte 0x020243E8
_08050DB4: .4byte 0x02024190
_08050DB8: .4byte 0x02000100
_08050DBC:
	movs r0, #0
	mov sb, r0
	movs r0, #3
_08050DC2:
	mov r8, r0
	movs r0, #3
	mov sl, r0
	movs r0, #1
	str r0, [sp, #8]
	ldr r2, _08050DD4
	ldrb r1, [r1]
	b _08050E9E
	.align 2, 0
_08050DD4: .4byte 0x02023D12
_08050DD8:
	movs r0, #0x42
	ands r0, r2
	cmp r0, #0x42
	beq _08050DEA
	ldr r1, _08050E08
	adds r0, r2, #0
	ands r0, r1
	cmp r0, r1
	bne _08050E2C
_08050DEA:
	ldrb r0, [r4]
	bl GetBattlerMultiplayerId
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetLinkTrainerFlankId
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _08050E0C
	movs r1, #3
	mov sb, r1
	movs r0, #6
	b _08050E12
	.align 2, 0
_08050E08: .4byte 0x02000040
_08050E0C:
	movs r1, #0
	mov sb, r1
	movs r0, #3
_08050E12:
	mov r8, r0
	movs r1, #3
	mov sl, r1
	movs r0, #1
	str r0, [sp, #8]
	ldr r2, _08050E24
	ldr r0, _08050E28
	ldrb r1, [r0]
	b _08050E9E
	.align 2, 0
_08050E24: .4byte 0x02023D12
_08050E28: .4byte 0x02023EB0
_08050E2C:
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08050E84
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08050E50
	movs r1, #0
	mov sb, r1
	movs r0, #6
	mov r8, r0
	mov sl, r0
	movs r1, #2
	b _08050E70
_08050E50:
	ldrb r1, [r4]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08050E62
	movs r0, #3
	mov sb, r0
	movs r1, #6
	b _08050E68
_08050E62:
	movs r0, #0
	mov sb, r0
	movs r1, #3
_08050E68:
	mov r8, r1
	movs r0, #3
	mov sl, r0
	movs r1, #1
_08050E70:
	str r1, [sp, #8]
	ldr r2, _08050E7C
	ldr r0, _08050E80
	ldrb r1, [r0]
	b _08050E9E
	.align 2, 0
_08050E7C: .4byte 0x02023D12
_08050E80: .4byte 0x02023EB0
_08050E84:
	movs r0, #1
	ands r2, r0
	cmp r2, #0
	beq _08050EB4
	movs r0, #0
	mov sb, r0
	movs r1, #6
	mov r8, r1
	mov sl, r1
	movs r0, #2
	str r0, [sp, #8]
	ldr r2, _08050EB0
	ldrb r1, [r4]
_08050E9E:
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r7, [r0]
	movs r0, #2
	eors r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r5, [r1]
	b _08050ECE
	.align 2, 0
_08050EB0: .4byte 0x02023D12
_08050EB4:
	movs r1, #0
	mov sb, r1
	movs r0, #6
	mov r8, r0
	mov sl, r0
	movs r1, #1
	str r1, [sp, #8]
	ldr r1, _08050F30
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r5, [r0]
	adds r7, r5, #0
_08050ECE:
	mov r6, sb
	cmp r6, r8
	bge _08050F0C
_08050ED4:
	movs r0, #0x64
	muls r0, r6, r0
	ldr r1, [sp]
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _08050F06
	adds r0, r4, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #0
	bne _08050F06
	adds r0, r4, #0
	movs r1, #0x39
	bl GetMonData3
	cmp r0, #0
	beq _08050F06
	ldr r0, [sp, #4]
	adds r0, #1
	str r0, [sp, #4]
_08050F06:
	adds r6, #1
	cmp r6, r8
	blt _08050ED4
_08050F0C:
	ldr r1, [sp, #4]
	ldr r0, [sp, #8]
	cmp r1, r0
	bgt _08050F38
	ldr r3, _08050F34
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08051024
	.align 2, 0
_08050F30: .4byte 0x02023D12
_08050F34: .4byte 0x02023EB8
_08050F38:
	bl TryDoForceSwitchOut
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08050F88
_08050F42:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sl
	bl __modsi3
	adds r6, r0, #0
	add r6, sb
	cmp r6, r7
	beq _08050F42
	cmp r6, r5
	beq _08050F42
	movs r0, #0x64
	muls r0, r6, r0
	ldr r1, [sp]
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #0xb
	bl GetMonData3
	cmp r0, #0
	beq _08050F42
	adds r0, r4, #0
	movs r1, #0x2d
	bl GetMonData3
	cmp r0, #1
	beq _08050F42
	adds r0, r4, #0
	movs r1, #0x39
	bl GetMonData3
	cmp r0, #0
	beq _08050F42
_08050F88:
	ldr r4, _0805100C
	ldrb r0, [r4]
	ldr r1, _08051010
	ldr r1, [r1]
	adds r0, r0, r1
	adds r0, #0x5c
	strb r6, [r0]
	bl IsMultiBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08050FA6
	ldrb r0, [r4]
	bl SwitchPartyOrder
_08050FA6:
	ldr r0, _08051014
	ldr r2, [r0]
	movs r1, #0x81
	lsls r1, r1, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, r1
	beq _08050FD0
	movs r0, #0x42
	ands r0, r2
	cmp r0, #0x42
	beq _08050FD0
	ldr r1, _08051018
	adds r0, r2, #0
	ands r0, r1
	cmp r0, r1
	beq _08050FD0
	ldr r0, _0805101C
	ands r2, r0
	cmp r2, r0
	bne _08050FEE
_08050FD0:
	ldr r5, _0805100C
	ldrb r0, [r5]
	lsls r4, r6, #0x18
	lsrs r4, r4, #0x18
	adds r1, r4, #0
	movs r2, #0
	bl sub_081B8B20
	ldrb r1, [r5]
	movs r0, #2
	eors r0, r1
	adds r1, r4, #0
	movs r2, #1
	bl sub_081B8B20
_08050FEE:
	ldr r0, _08051014
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08051024
	ldr r0, _0805100C
	ldrb r0, [r0]
	lsls r1, r6, #0x18
	lsrs r1, r1, #0x18
	bl SwitchPartyOrderInGameMulti
	b _08051024
	.align 2, 0
_0805100C: .4byte 0x02023EB0
_08051010: .4byte 0x02024140
_08051014: .4byte 0x02022C90
_08051018: .4byte 0x02000100
_0805101C: .4byte 0x02000040
_08051020:
	bl TryDoForceSwitchOut
_08051024:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end atk8F_forcerandomswitch

	thumb_func_start atk90_tryconversiontypechange
atk90_tryconversiontypechange: @ 0x08051034
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r6, #0
	ldr r2, _080510C8
	ldr r3, _080510CC
	ldrb r1, [r3]
	movs r0, #0x58
	muls r0, r1, r0
	adds r1, r2, #0
	adds r1, #0xc
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r8, r2
	cmp r0, #0
	beq _08051076
	movs r5, #0x58
	adds r2, r1, #0
_0805105C:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bhi _08051076
	lsls r1, r6, #1
	ldrb r0, [r3]
	muls r0, r5, r0
	adds r1, r1, r0
	adds r1, r1, r2
	ldrh r0, [r1]
	cmp r0, #0
	bne _0805105C
_08051076:
	movs r3, #0
	cmp r3, r6
	bhs _080510F8
	ldr r0, _080510D0
	mov sl, r0
	ldr r5, _080510C8
	mov ip, r5
	ldr r7, _080510CC
	ldrb r0, [r7]
	movs r4, #0x58
	adds r5, r0, #0
	muls r5, r4, r5
	movs r0, #0xc
	add r0, ip
	mov sb, r0
_08051094:
	lsls r0, r3, #1
	adds r0, r0, r5
	add r0, sb
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, sl
	ldrb r2, [r0, #2]
	cmp r2, #9
	bne _080510D6
	mov r0, r8
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #7
	beq _080510C2
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #7
	bne _080510D4
_080510C2:
	movs r2, #7
	b _080510D6
	.align 2, 0
_080510C8: .4byte 0x02023D28
_080510CC: .4byte 0x02023EAF
_080510D0: .4byte 0x082ED220
_080510D4:
	movs r2, #0
_080510D6:
	ldrb r0, [r7]
	muls r0, r4, r0
	add r0, ip
	adds r1, r0, #0
	adds r1, #0x21
	ldrb r1, [r1]
	cmp r2, r1
	beq _080510EE
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r2, r0
	bne _080510F8
_080510EE:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r6
	blo _08051094
_080510F8:
	cmp r3, r6
	bne _0805111C
	ldr r3, _08051118
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _080511C0
	.align 2, 0
_08051118: .4byte 0x02023EB8
_0805111C:
	movs r7, #3
	ldr r5, _08051174
	mov sb, r5
_08051122:
	bl Random
	adds r3, r0, #0
	ands r3, r7
	cmp r3, r6
	bhs _08051122
	ldr r4, _08051178
	lsls r1, r3, #1
	ldr r3, _0805117C
	ldrb r2, [r3]
	movs r0, #0x58
	adds r5, r2, #0
	muls r5, r0, r5
	adds r1, r1, r5
	adds r0, r4, #0
	adds r0, #0xc
	adds r1, r1, r0
	ldrh r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	add r0, sb
	ldrb r2, [r0, #2]
	mov r8, r4
	adds r4, r3, #0
	cmp r2, #9
	bne _08051182
	mov r0, r8
	adds r2, r5, r0
	adds r0, r2, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #7
	beq _08051170
	adds r0, r2, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #7
	bne _08051180
_08051170:
	movs r2, #7
	b _08051182
	.align 2, 0
_08051174: .4byte 0x082ED220
_08051178: .4byte 0x02023D28
_0805117C: .4byte 0x02023EAF
_08051180:
	movs r2, #0
_08051182:
	ldrb r0, [r4]
	movs r3, #0x58
	muls r0, r3, r0
	add r0, r8
	adds r1, r0, #0
	adds r1, #0x21
	ldrb r5, [r1]
	cmp r2, r5
	beq _08051122
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r2, r0
	beq _08051122
	strb r2, [r1]
	ldrb r0, [r4]
	muls r0, r3, r0
	add r0, r8
	adds r0, #0x22
	strb r2, [r0]
	ldr r1, _080511D0
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #3
	strb r0, [r1, #1]
	strb r2, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r1, _080511D4
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_080511C0:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080511D0: .4byte 0x02022C0C
_080511D4: .4byte 0x02023EB8
	thumb_func_end atk90_tryconversiontypechange

	thumb_func_start atk91_givepaydaymoney
atk91_givepaydaymoney: @ 0x080511D8
	push {r4, lr}
	ldr r0, _08051240
	ldr r0, [r0]
	ldr r1, _08051244
	ands r0, r1
	cmp r0, #0
	bne _08051260
	ldr r1, _08051248
	ldrh r0, [r1]
	cmp r0, #0
	beq _08051260
	adds r1, r0, #0
	ldr r0, _0805124C
	ldr r0, [r0]
	adds r0, #0x4a
	ldrb r0, [r0]
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _08051250
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r1, r4, #0
	bl AddMoney
	ldr r1, _08051254
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #1
	strb r0, [r1, #1]
	movs r0, #2
	strb r0, [r1, #2]
	movs r0, #5
	strb r0, [r1, #3]
	strb r4, [r1, #4]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r4, r0
	lsrs r4, r4, #8
	strb r4, [r1, #5]
	movs r0, #0xff
	strb r0, [r1, #6]
	ldr r4, _08051258
	ldr r0, [r4]
	adds r0, #1
	bl BattleScriptPush
	ldr r0, _0805125C
	str r0, [r4]
	b _08051268
	.align 2, 0
_08051240: .4byte 0x02022C90
_08051244: .4byte 0x02000002
_08051248: .4byte 0x02023FD2
_0805124C: .4byte 0x02024140
_08051250: .4byte 0x03005AEC
_08051254: .4byte 0x02022C0C
_08051258: .4byte 0x02023EB8
_0805125C: .4byte 0x0828988F
_08051260:
	ldr r1, _08051270
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08051268:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08051270: .4byte 0x02023EB8
	thumb_func_end atk91_givepaydaymoney

	thumb_func_start atk92_setlightscreen
atk92_setlightscreen: @ 0x08051274
	push {r4, r5, r6, lr}
	ldr r5, _080512A4
	ldrb r0, [r5]
	bl GetBattlerPosition
	ldr r4, _080512A8
	movs r6, #1
	adds r1, r6, #0
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080512B4
	ldr r2, _080512AC
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _080512B0
	movs r0, #0
	b _08051328
	.align 2, 0
_080512A4: .4byte 0x02023EAF
_080512A8: .4byte 0x02023F32
_080512AC: .4byte 0x02023F20
_080512B0: .4byte 0x02023FD6
_080512B4:
	ldrb r0, [r5]
	bl GetBattlerPosition
	adds r1, r6, #0
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	movs r2, #2
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r5]
	bl GetBattlerPosition
	ldr r4, _08051318
	adds r1, r6, #0
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	movs r1, #5
	strb r1, [r0, #2]
	ldrb r0, [r5]
	bl GetBattlerPosition
	adds r1, r6, #0
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r1, [r5]
	strb r1, [r0, #3]
	ldr r0, _0805131C
	ldr r0, [r0]
	ands r0, r6
	cmp r0, #0
	beq _08051324
	movs r0, #1
	bl CountAliveMonsInBattle
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bne _08051324
	ldr r1, _08051320
	movs r0, #4
	b _08051328
	.align 2, 0
_08051318: .4byte 0x02023F38
_0805131C: .4byte 0x02022C90
_08051320: .4byte 0x02023FD6
_08051324:
	ldr r1, _08051338
	movs r0, #3
_08051328:
	strb r0, [r1, #5]
	ldr r1, _0805133C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08051338: .4byte 0x02023FD6
_0805133C: .4byte 0x02023EB8
	thumb_func_end atk92_setlightscreen

	thumb_func_start atk93_tryKO
atk93_tryKO: @ 0x08051340
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r7, _0805136C
	ldr r6, _08051370
	ldrb r2, [r6]
	movs r5, #0x58
	adds r0, r2, #0
	muls r0, r5, r0
	adds r1, r0, r7
	ldrh r0, [r1, #0x2e]
	cmp r0, #0xaf
	bne _08051378
	ldr r1, _08051374
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r4, [r0, #7]
	ldrb r6, [r0, #0x1a]
	b _08051392
	.align 2, 0
_0805136C: .4byte 0x02023D28
_08051370: .4byte 0x02023EB0
_08051374: .4byte 0x020240A8
_08051378:
	ldrh r0, [r1, #0x2e]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldrb r0, [r6]
	muls r0, r5, r0
	adds r0, r0, r7
	ldrh r0, [r0, #0x2e]
	bl sub_080D6D1C
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_08051392:
	ldr r1, _0805140C
	ldr r5, _08051410
	ldrb r0, [r5]
	strb r0, [r1]
	cmp r4, #0x27
	bne _080513D0
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	bhs _080513D0
	ldrb r0, [r5]
	movs r1, #0x27
	bl RecordItemEffectBattle
	ldr r2, _08051414
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strb r1, [r0]
_080513D0:
	ldr r1, _08051418
	ldr r2, _08051410
	ldrb r3, [r2]
	movs r6, #0x58
	adds r0, r3, #0
	muls r0, r6, r0
	adds r5, r0, r1
	adds r0, r5, #0
	adds r0, #0x20
	ldrb r4, [r0]
	mov r8, r1
	mov sb, r2
	cmp r4, #5
	bne _0805142C
	ldr r2, _0805141C
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08051420
	strb r4, [r0]
	ldr r1, _08051424
	ldr r0, _08051428
	str r0, [r1]
	mov r1, sb
	ldrb r0, [r1]
	movs r1, #5
	bl RecordAbilityBattle
	b _08051680
	.align 2, 0
_0805140C: .4byte 0x02023EB3
_08051410: .4byte 0x02023EB0
_08051414: .4byte 0x02024020
_08051418: .4byte 0x02023D28
_0805141C: .4byte 0x02023F20
_08051420: .4byte 0x02023EAE
_08051424: .4byte 0x02023EB8
_08051428: .4byte 0x08289ADA
_0805142C:
	ldr r1, _080514A0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x18
	ands r0, r1
	cmp r0, #0
	bne _080514B0
	ldr r1, _080514A4
	ldr r0, _080514A8
	ldrh r0, [r0]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r1
	ldr r7, _080514AC
	ldrb r0, [r7]
	muls r0, r6, r0
	add r0, r8
	adds r0, #0x2a
	ldrb r0, [r0]
	adds r1, r5, #0
	adds r1, #0x2a
	ldrb r1, [r1]
	subs r0, r0, r1
	ldrb r2, [r2, #3]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #1
	cmp r0, r4
	blt _08051480
	b _08051618
_08051480:
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r6, r1
	add r1, r8
	adds r1, #0x2a
	mov r2, sb
	ldrb r0, [r2]
	muls r0, r6, r0
	add r0, r8
	adds r0, #0x2a
	ldrb r1, [r1]
	movs r4, #1
	ldrb r0, [r0]
	cmp r1, r0
	bhs _08051546
	b _08051618
	.align 2, 0
_080514A0: .4byte 0x02023F50
_080514A4: .4byte 0x082ED220
_080514A8: .4byte 0x02023E8E
_080514AC: .4byte 0x02023EAF
_080514B0:
	ldr r1, _0805157C
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, _08051580
	ldrb r0, [r0, #0x15]
	adds r7, r1, #0
	ldrb r3, [r7]
	cmp r0, r3
	bne _080514DA
	ldrb r0, [r7]
	muls r0, r6, r0
	add r0, r8
	adds r0, #0x2a
	adds r1, r5, #0
	adds r1, #0x2a
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08051552
_080514DA:
	ldr r1, _08051584
	ldr r0, _08051588
	ldrh r0, [r0]
	lsls r2, r0, #1
	adds r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r1
	ldr r6, _0805158C
	ldrb r0, [r7]
	movs r5, #0x58
	muls r0, r5, r0
	adds r0, r0, r6
	adds r0, #0x2a
	ldrb r1, [r0]
	ldr r0, _08051590
	mov r8, r0
	ldrb r0, [r0]
	muls r0, r5, r0
	adds r0, r0, r6
	adds r0, #0x2a
	ldrb r0, [r0]
	subs r1, r1, r0
	ldrb r2, [r2, #3]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #1
	cmp r0, r4
	bge _08051544
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r5, r1
	adds r1, r1, r6
	adds r1, #0x2a
	mov r2, r8
	ldrb r0, [r2]
	muls r0, r5, r0
	adds r0, r0, r6
	adds r0, #0x2a
	ldrb r1, [r1]
	movs r4, #1
	ldrb r0, [r0]
	cmp r1, r0
	bhs _08051546
_08051544:
	movs r4, #0
_08051546:
	ldr r3, _0805158C
	mov r8, r3
	ldr r0, _08051590
	mov sb, r0
	cmp r4, #0
	beq _08051618
_08051552:
	ldr r0, _08051594
	mov r1, sb
	ldrb r2, [r1]
	lsls r1, r2, #4
	adds r1, r1, r0
	ldrb r0, [r1]
	lsls r0, r0, #0x1e
	cmp r0, #0
	bge _080515A0
	ldr r1, _08051598
	movs r0, #0x58
	muls r0, r2, r0
	add r0, r8
	ldrh r0, [r0, #0x28]
	subs r0, #1
	str r0, [r1]
	ldr r2, _0805159C
	ldrb r0, [r2]
	movs r1, #0x40
	b _080515FE
	.align 2, 0
_0805157C: .4byte 0x02023F60
_08051580: .4byte 0x02023EAF
_08051584: .4byte 0x082ED220
_08051588: .4byte 0x02023E8E
_0805158C: .4byte 0x02023D28
_08051590: .4byte 0x02023EB0
_08051594: .4byte 0x02023FE0
_08051598: .4byte 0x02023E94
_0805159C: .4byte 0x02023F20
_080515A0:
	ldr r0, _080515DC
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1]
	lsrs r0, r0, #7
	cmp r0, #0
	beq _080515EC
	ldr r1, _080515E0
	movs r3, #0x58
	adds r0, r2, #0
	muls r0, r3, r0
	add r0, r8
	ldrh r0, [r0, #0x28]
	subs r0, #1
	str r0, [r1]
	ldr r2, _080515E4
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _080515E8
	mov r2, sb
	ldrb r0, [r2]
	muls r0, r3, r0
	add r0, r8
	ldrh r0, [r0, #0x2e]
	strh r0, [r1]
	b _08051602
	.align 2, 0
_080515DC: .4byte 0x02024020
_080515E0: .4byte 0x02023E94
_080515E4: .4byte 0x02023F20
_080515E8: .4byte 0x02023EAC
_080515EC:
	ldr r1, _0805160C
	movs r0, #0x58
	muls r0, r2, r0
	add r0, r8
	ldrh r0, [r0, #0x28]
	str r0, [r1]
	ldr r2, _08051610
	ldrb r0, [r2]
	movs r1, #0x10
_080515FE:
	orrs r0, r1
	strb r0, [r2]
_08051602:
	ldr r1, _08051614
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08051680
	.align 2, 0
_0805160C: .4byte 0x02023E94
_08051610: .4byte 0x02023F20
_08051614: .4byte 0x02023EB8
_08051618:
	ldr r2, _0805164C
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r3, _08051650
	ldr r0, _08051654
	ldrb r0, [r0]
	movs r2, #0x58
	adds r1, r0, #0
	muls r1, r2, r1
	adds r1, r1, r3
	adds r1, #0x2a
	ldr r0, _08051658
	ldrb r0, [r0]
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x2a
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	blo _08051660
	ldr r1, _0805165C
	movs r0, #0
	b _08051664
	.align 2, 0
_0805164C: .4byte 0x02023F20
_08051650: .4byte 0x02023D28
_08051654: .4byte 0x02023EAF
_08051658: .4byte 0x02023EB0
_0805165C: .4byte 0x02023FD6
_08051660:
	ldr r1, _0805168C
	movs r0, #1
_08051664:
	strb r0, [r1, #5]
	ldr r3, _08051690
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08051680:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805168C: .4byte 0x02023FD6
_08051690: .4byte 0x02023EB8
	thumb_func_end atk93_tryKO

	thumb_func_start atk94_damagetohalftargethp
atk94_damagetohalftargethp: @ 0x08051694
	push {lr}
	ldr r3, _080516C0
	ldr r2, _080516C4
	ldr r0, _080516C8
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r0, [r0, #0x28]
	lsrs r0, r0, #1
	str r0, [r3]
	cmp r0, #0
	bne _080516B2
	movs r0, #1
	str r0, [r3]
_080516B2:
	ldr r1, _080516CC
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080516C0: .4byte 0x02023E94
_080516C4: .4byte 0x02023D28
_080516C8: .4byte 0x02023EB0
_080516CC: .4byte 0x02023EB8
	thumb_func_end atk94_damagetohalftargethp

	thumb_func_start atk95_setsandstorm
atk95_setsandstorm: @ 0x080516D0
	push {lr}
	ldr r2, _080516F0
	ldrh r1, [r2]
	movs r0, #0x18
	ands r0, r1
	cmp r0, #0
	beq _080516FC
	ldr r2, _080516F4
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _080516F8
	movs r0, #2
	strb r0, [r1, #5]
	b _0805170E
	.align 2, 0
_080516F0: .4byte 0x02024070
_080516F4: .4byte 0x02023F20
_080516F8: .4byte 0x02023FD6
_080516FC:
	movs r0, #8
	strh r0, [r2]
	ldr r1, _0805171C
	movs r0, #3
	strb r0, [r1, #5]
	ldr r0, _08051720
	adds r0, #0x28
	movs r1, #5
	strb r1, [r0]
_0805170E:
	ldr r1, _08051724
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0805171C: .4byte 0x02023FD6
_08051720: .4byte 0x02024074
_08051724: .4byte 0x02023EB8
	thumb_func_end atk95_setsandstorm

	thumb_func_start atk96_weatherdamage
atk96_weatherdamage: @ 0x08051728
	push {r4, r5, lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _08051746
	b _08051858
_08051746:
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0x4d
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805175C
	b _08051858
_0805175C:
	ldr r2, _080517D0
	ldrh r1, [r2]
	movs r0, #0x18
	ands r0, r1
	adds r4, r2, #0
	ldr r5, _080517D4
	cmp r0, #0
	beq _080517EA
	ldr r0, _080517D8
	ldrb r2, [r5]
	movs r1, #0x58
	muls r1, r2, r1
	adds r3, r1, r0
	adds r0, r3, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #5
	beq _080517E4
	cmp r0, #8
	beq _080517E4
	cmp r0, #4
	beq _080517E4
	adds r0, r3, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #5
	beq _080517E4
	cmp r0, #8
	beq _080517E4
	cmp r0, #4
	beq _080517E4
	adds r0, r3, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #8
	beq _080517E4
	ldr r0, _080517DC
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _080517E4
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	bne _080517E4
	ldr r1, _080517E0
	ldrh r0, [r3, #0x2c]
	lsrs r0, r0, #4
	str r0, [r1]
	cmp r0, #0
	bne _080517EA
	movs r0, #1
	b _080517E8
	.align 2, 0
_080517D0: .4byte 0x02024070
_080517D4: .4byte 0x02023EAF
_080517D8: .4byte 0x02023D28
_080517DC: .4byte 0x02023F50
_080517E0: .4byte 0x02023E94
_080517E4:
	ldr r1, _08051840
	movs r0, #0
_080517E8:
	str r0, [r1]
_080517EA:
	ldrh r1, [r4]
	movs r4, #0x80
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08051860
	ldr r1, _08051844
	ldrb r3, [r5]
	movs r0, #0x58
	muls r0, r3, r0
	adds r2, r0, r1
	adds r0, r2, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #0xf
	beq _0805184C
	adds r0, r2, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xf
	beq _0805184C
	ldr r0, _08051848
	lsls r1, r3, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r1, #0
	ands r0, r4
	cmp r0, #0
	bne _0805184C
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	bne _0805184C
	ldr r1, _08051840
	ldrh r0, [r2, #0x2c]
	lsrs r0, r0, #4
	str r0, [r1]
	cmp r0, #0
	bne _08051860
	movs r0, #1
	str r0, [r1]
	b _08051860
	.align 2, 0
_08051840: .4byte 0x02023E94
_08051844: .4byte 0x02023D28
_08051848: .4byte 0x02023F50
_0805184C:
	ldr r1, _08051854
	movs r0, #0
	str r0, [r1]
	b _08051860
	.align 2, 0
_08051854: .4byte 0x02023E94
_08051858:
	ldr r1, _0805188C
	movs r0, #0
	str r0, [r1]
	ldr r5, _08051890
_08051860:
	ldr r0, _08051894
	ldrb r1, [r0]
	ldr r2, _08051898
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0805187A
	ldr r1, _0805188C
	movs r0, #0
	str r0, [r1]
_0805187A:
	ldr r1, _0805189C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805188C: .4byte 0x02023E94
_08051890: .4byte 0x02023EAF
_08051894: .4byte 0x02023EB4
_08051898: .4byte 0x082FACB4
_0805189C: .4byte 0x02023EB8
	thumb_func_end atk96_weatherdamage

	thumb_func_start atk97_tryinfatuating
atk97_tryinfatuating: @ 0x080518A0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r4, _080518CC
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080518D8
	ldr r1, _080518D0
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _080518D4
	b _080518E8
	.align 2, 0
_080518CC: .4byte 0x02023EAF
_080518D0: .4byte 0x02023D12
_080518D4: .4byte 0x02024190
_080518D8:
	ldr r1, _0805190C
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _08051910
_080518E8:
	adds r5, r1, r0
	ldr r4, _08051914
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805191C
	ldr r1, _0805190C
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _08051918
	b _0805192C
	.align 2, 0
_0805190C: .4byte 0x02023D12
_08051910: .4byte 0x020243E8
_08051914: .4byte 0x02023EB0
_08051918: .4byte 0x02024190
_0805191C:
	ldr r1, _08051988
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _0805198C
_0805192C:
	adds r4, r1, r0
	adds r0, r5, #0
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	adds r0, r5, #0
	movs r1, #0
	bl GetMonData3
	mov sb, r0
	adds r0, r4, #0
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	adds r0, r4, #0
	movs r1, #0
	bl GetMonData3
	adds r7, r0, #0
	ldr r5, _08051990
	ldrb r0, [r5]
	movs r6, #0x58
	muls r0, r6, r0
	ldr r1, _08051994
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r2, [r0]
	cmp r2, #0xc
	bne _080519A4
	ldr r1, _08051998
	ldr r0, _0805199C
	str r0, [r1]
	ldr r0, _080519A0
	strb r2, [r0]
	ldrb r0, [r5]
	movs r1, #0xc
	bl RecordAbilityBattle
	b _08051A3C
	.align 2, 0
_08051988: .4byte 0x02023D12
_0805198C: .4byte 0x020243E8
_08051990: .4byte 0x02023EB0
_08051994: .4byte 0x02023D28
_08051998: .4byte 0x02023EB8
_0805199C: .4byte 0x08289B7D
_080519A0: .4byte 0x02023EAE
_080519A4:
	mov r0, sl
	mov r1, sb
	bl GetGenderFromSpeciesAndPersonality
	adds r4, r0, #0
	mov r0, r8
	adds r1, r7, #0
	bl GetGenderFromSpeciesAndPersonality
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _080519F4
	ldrb r0, [r5]
	muls r0, r6, r0
	ldr r4, _08051A10
	adds r4, #0x50
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	bne _080519F4
	mov r0, sl
	mov r1, sb
	bl GetGenderFromSpeciesAndPersonality
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	beq _080519F4
	mov r0, r8
	adds r1, r7, #0
	bl GetGenderFromSpeciesAndPersonality
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _08051A18
_080519F4:
	ldr r3, _08051A14
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08051A3C
	.align 2, 0
_08051A10: .4byte 0x02023D28
_08051A14: .4byte 0x02023EB8
_08051A18:
	ldrb r0, [r5]
	adds r2, r0, #0
	muls r2, r6, r2
	adds r2, r2, r4
	ldr r1, _08051A4C
	ldr r0, _08051A50
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08051A54
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08051A3C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08051A4C: .4byte 0x082FACB4
_08051A50: .4byte 0x02023EAF
_08051A54: .4byte 0x02023EB8
	thumb_func_end atk97_tryinfatuating

	thumb_func_start atk98_updatestatusicon
atk98_updatestatusicon: @ 0x08051A58
	push {r4, r5, r6, r7, lr}
	ldr r0, _08051AA0
	ldr r0, [r0]
	cmp r0, #0
	bne _08051B44
	ldr r5, _08051AA4
	ldr r1, [r5]
	ldrb r0, [r1, #1]
	cmp r0, #4
	beq _08051AB0
	bl GetBattlerForBattleScript
	ldr r4, _08051AA8
	strb r0, [r4]
	ldr r3, _08051AAC
	ldrb r1, [r4]
	movs r0, #0x58
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r3, #0
	adds r0, #0x4c
	adds r0, r2, r0
	ldr r1, [r0]
	adds r3, #0x50
	adds r2, r2, r3
	ldr r2, [r2]
	movs r0, #0
	bl BtlController_EmitStatusIconUpdate
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r0, [r5]
	adds r0, #2
	str r0, [r5]
	b _08051B44
	.align 2, 0
_08051AA0: .4byte 0x02023D0C
_08051AA4: .4byte 0x02023EB8
_08051AA8: .4byte 0x02023D08
_08051AAC: .4byte 0x02023D28
_08051AB0:
	ldr r4, _08051B4C
	ldr r5, _08051B50
	ldrb r0, [r5]
	strb r0, [r4]
	ldr r6, _08051B54
	ldrb r1, [r6]
	ldr r7, _08051B58
	ldrb r2, [r4]
	lsls r0, r2, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08051AEC
	ldr r3, _08051B5C
	movs r0, #0x58
	muls r2, r0, r2
	adds r0, r3, #0
	adds r0, #0x4c
	adds r0, r2, r0
	ldr r1, [r0]
	adds r3, #0x50
	adds r2, r2, r3
	ldr r2, [r2]
	movs r0, #0
	bl BtlController_EmitStatusIconUpdate
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_08051AEC:
	ldr r0, _08051B60
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08051B3C
	ldrb r0, [r5]
	bl GetBattlerPosition
	movs r1, #2
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	strb r0, [r4]
	ldrb r1, [r6]
	ldrb r2, [r4]
	lsls r0, r2, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08051B3C
	ldr r3, _08051B5C
	movs r0, #0x58
	muls r2, r0, r2
	adds r0, r3, #0
	adds r0, #0x4c
	adds r0, r2, r0
	ldr r1, [r0]
	adds r3, #0x50
	adds r2, r2, r3
	ldr r2, [r2]
	movs r0, #0
	bl BtlController_EmitStatusIconUpdate
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_08051B3C:
	ldr r1, _08051B64
	ldr r0, [r1]
	adds r0, #2
	str r0, [r1]
_08051B44:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08051B4C: .4byte 0x02023D08
_08051B50: .4byte 0x02023EAF
_08051B54: .4byte 0x02023EB4
_08051B58: .4byte 0x082FACB4
_08051B5C: .4byte 0x02023D28
_08051B60: .4byte 0x02022C90
_08051B64: .4byte 0x02023EB8
	thumb_func_end atk98_updatestatusicon

	thumb_func_start atk99_setmist
atk99_setmist: @ 0x08051B68
	push {r4, r5, r6, lr}
	ldr r6, _08051B98
	ldr r4, _08051B9C
	ldrb r0, [r4]
	bl GetBattlerPosition
	movs r5, #1
	adds r1, r5, #0
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #4]
	cmp r0, #0
	beq _08051BA8
	ldr r2, _08051BA0
	ldrb r0, [r2]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08051BA4
	strb r5, [r0, #5]
	b _08051BF6
	.align 2, 0
_08051B98: .4byte 0x02023F38
_08051B9C: .4byte 0x02023EAF
_08051BA0: .4byte 0x02023F20
_08051BA4: .4byte 0x02023FD6
_08051BA8:
	ldrb r0, [r4]
	bl GetBattlerPosition
	adds r1, r5, #0
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	movs r1, #5
	strb r1, [r0, #4]
	ldrb r0, [r4]
	bl GetBattlerPosition
	adds r1, r5, #0
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r1, [r4]
	strb r1, [r0, #5]
	ldrb r0, [r4]
	bl GetBattlerPosition
	ldr r2, _08051C04
	adds r1, r5, #0
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	movs r3, #0
	orrs r0, r2
	strh r0, [r1]
	ldr r0, _08051C08
	strb r3, [r0, #5]
_08051BF6:
	ldr r1, _08051C0C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08051C04: .4byte 0x02023F32
_08051C08: .4byte 0x02023FD6
_08051C0C: .4byte 0x02023EB8
	thumb_func_end atk99_setmist

	thumb_func_start atk9A_setfocusenergy
atk9A_setfocusenergy: @ 0x08051C10
	push {lr}
	ldr r1, _08051C40
	ldr r0, _08051C44
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #0xd
	adds r2, r1, #0
	ands r2, r3
	cmp r2, #0
	beq _08051C50
	ldr r2, _08051C48
	ldrb r0, [r2]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08051C4C
	movs r0, #1
	strb r0, [r1, #5]
	b _08051C58
	.align 2, 0
_08051C40: .4byte 0x02023D28
_08051C44: .4byte 0x02023EAF
_08051C48: .4byte 0x02023F20
_08051C4C: .4byte 0x02023FD6
_08051C50:
	orrs r1, r3
	str r1, [r0]
	ldr r0, _08051C64
	strb r2, [r0, #5]
_08051C58:
	ldr r1, _08051C68
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08051C64: .4byte 0x02023FD6
_08051C68: .4byte 0x02023EB8
	thumb_func_end atk9A_setfocusenergy

	thumb_func_start atk9B_transformdataexecution
atk9B_transformdataexecution: @ 0x08051C6C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _08051CC4
	ldr r2, _08051CC8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _08051CCC
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r7, _08051CD0
	ldr r0, _08051CD4
	mov ip, r0
	ldrb r1, [r0]
	movs r6, #0x58
	adds r0, r1, #0
	muls r0, r6, r0
	adds r5, r7, #0
	adds r5, #0x50
	adds r0, r0, r5
	ldr r0, [r0]
	movs r4, #0x80
	lsls r4, r4, #0xe
	ands r0, r4
	cmp r0, #0
	bne _08051CB2
	ldr r0, _08051CD8
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r2, [r1]
	ldr r0, _08051CDC
	ands r2, r0
	cmp r2, #0
	beq _08051CE8
_08051CB2:
	ldr r2, _08051CE0
	ldrb r0, [r2]
	movs r1, #0x20
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08051CE4
	movs r0, #1
	b _08051DFC
	.align 2, 0
_08051CC4: .4byte 0x02023E90
_08051CC8: .4byte 0x0000FFFF
_08051CCC: .4byte 0x02023EB8
_08051CD0: .4byte 0x02023D28
_08051CD4: .4byte 0x02023EB0
_08051CD8: .4byte 0x02023F50
_08051CDC: .4byte 0x000400C0
_08051CE0: .4byte 0x02023F20
_08051CE4: .4byte 0x02023FD6
_08051CE8:
	ldr r3, _08051DBC
	ldrb r0, [r3]
	adds r1, r0, #0
	muls r1, r6, r1
	adds r1, r1, r5
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r4, _08051DC0
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	strh r2, [r0, #4]
	ldrb r0, [r3]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r2, [r1, #0xb]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #0xb]
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	mov r2, ip
	ldrb r1, [r2]
	muls r1, r6, r1
	adds r2, r7, #0
	adds r2, #0x48
	adds r1, r1, r2
	ldr r1, [r1]
	str r1, [r0]
	ldrb r0, [r3]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrb r2, [r1, #0x18]
	movs r0, #0xf
	ands r0, r2
	strb r0, [r1, #0x18]
	ldr r1, _08051DC4
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #6
	strb r0, [r1, #1]
	mov r2, ip
	ldrb r0, [r2]
	muls r0, r6, r0
	adds r0, r0, r7
	ldrh r0, [r0]
	strb r0, [r1, #2]
	ldrb r0, [r2]
	muls r0, r6, r0
	adds r0, r0, r7
	ldrh r0, [r0]
	lsrs r0, r0, #8
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldrb r0, [r3]
	muls r0, r6, r0
	adds r5, r0, r7
	ldrb r0, [r2]
	muls r0, r6, r0
	adds r2, r0, r7
	movs r4, #0
	adds r6, r3, #0
	ldr r0, _08051DC8
	mov r8, r0
_08051D80:
	adds r0, r5, r4
	adds r1, r2, r4
	ldrb r1, [r1]
	strb r1, [r0]
	adds r4, #1
	cmp r4, #0x23
	bls _08051D80
	movs r4, #0
	ldr r7, _08051DCC
	ldr r3, _08051DD0
	adds r5, r3, #0
	adds r5, #0x18
_08051D98:
	lsls r1, r4, #1
	ldrb r2, [r6]
	movs r0, #0x58
	muls r2, r0, r2
	adds r1, r1, r2
	adds r1, r1, r3
	ldrh r1, [r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r7
	ldrb r1, [r0, #4]
	cmp r1, #4
	bhi _08051DD4
	adds r0, r4, r2
	adds r0, r0, r5
	b _08051DDA
	.align 2, 0
_08051DBC: .4byte 0x02023EAF
_08051DC0: .4byte 0x02023F60
_08051DC4: .4byte 0x02022C0C
_08051DC8: .4byte 0x02023D08
_08051DCC: .4byte 0x082ED220
_08051DD0: .4byte 0x02023D34
_08051DD4:
	adds r0, r4, r2
	adds r0, r0, r5
	movs r1, #5
_08051DDA:
	strb r1, [r0]
	adds r4, #1
	cmp r4, #3
	ble _08051D98
	ldrb r0, [r6]
	mov r1, r8
	strb r0, [r1]
	movs r0, #0
	movs r1, #2
	bl BtlController_EmitResetActionMoveSelection
	mov r2, r8
	ldrb r0, [r2]
	bl MarkBattlerForControllerExec
	ldr r1, _08051E08
	movs r0, #0
_08051DFC:
	strb r0, [r1, #5]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08051E08: .4byte 0x02023FD6
	thumb_func_end atk9B_transformdataexecution

	thumb_func_start atk9C_setsubstitute
atk9C_setsubstitute: @ 0x08051E0C
	push {r4, r5, r6, r7, lr}
	ldr r7, _08051E3C
	ldr r6, _08051E40
	ldrb r0, [r6]
	movs r5, #0x58
	muls r0, r5, r0
	adds r3, r0, r7
	ldrh r0, [r3, #0x2c]
	lsrs r1, r0, #2
	adds r2, r1, #0
	cmp r1, #0
	bne _08051E26
	movs r2, #1
_08051E26:
	ldrh r0, [r3, #0x28]
	cmp r0, r2
	bhi _08051E4C
	ldr r1, _08051E44
	movs r0, #0
	str r0, [r1]
	ldr r1, _08051E48
	movs r0, #1
	strb r0, [r1, #5]
	b _08051EA0
	.align 2, 0
_08051E3C: .4byte 0x02023D28
_08051E40: .4byte 0x02023EAF
_08051E44: .4byte 0x02023E94
_08051E48: .4byte 0x02023FD6
_08051E4C:
	ldr r4, _08051EB0
	str r1, [r4]
	cmp r1, #0
	bne _08051E58
	movs r0, #1
	str r0, [r4]
_08051E58:
	ldrb r0, [r6]
	adds r2, r0, #0
	muls r2, r5, r2
	adds r3, r7, #0
	adds r3, #0x50
	adds r2, r2, r3
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [r2]
	ldrb r0, [r6]
	adds r1, r0, #0
	muls r1, r5, r1
	adds r1, r1, r3
	ldr r0, [r1]
	ldr r2, _08051EB4
	ands r0, r2
	str r0, [r1]
	ldr r2, _08051EB8
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, [r4]
	movs r2, #0
	strb r1, [r0, #0xa]
	ldr r0, _08051EBC
	strb r2, [r0, #5]
	ldr r2, _08051EC0
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [r2]
_08051EA0:
	ldr r1, _08051EC4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08051EB0: .4byte 0x02023E94
_08051EB4: .4byte 0xFFFF1FFF
_08051EB8: .4byte 0x02023F60
_08051EBC: .4byte 0x02023FD6
_08051EC0: .4byte 0x02023F24
_08051EC4: .4byte 0x02023EB8
	thumb_func_end atk9C_setsubstitute

	thumb_func_start IsMoveUncopyableByMimic
IsMoveUncopyableByMimic: @ 0x08051EC8
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r3, #0
	ldr r0, _08051F08
	ldrh r1, [r0]
	ldr r4, _08051F0C
	adds r5, r0, #0
	cmp r1, r4
	beq _08051EF0
	cmp r1, r2
	beq _08051EF0
	adds r1, r5, #0
_08051EE2:
	adds r1, #2
	adds r3, #1
	ldrh r0, [r1]
	cmp r0, r4
	beq _08051EF0
	cmp r0, r2
	bne _08051EE2
_08051EF0:
	lsls r0, r3, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ldr r0, _08051F0C
	eors r1, r0
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08051F08: .4byte 0x082ECD64
_08051F0C: .4byte 0x0000FFFE
	thumb_func_end IsMoveUncopyableByMimic

	thumb_func_start atk9D_mimicattackcopy
atk9D_mimicattackcopy: @ 0x08051F10
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08051F88
	ldr r1, _08051F8C
	adds r7, r1, #0
	strh r7, [r0]
	ldr r5, _08051F90
	ldr r6, _08051F94
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	bl IsMoveUncopyableByMimic
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08051F6A
	ldr r3, _08051F98
	ldr r2, _08051F9C
	ldrb r1, [r2]
	movs r0, #0x58
	adds r4, r1, #0
	muls r4, r0, r4
	adds r0, r3, #0
	adds r0, #0x50
	adds r0, r4, r0
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r1, r0
	mov ip, r3
	mov sb, r2
	cmp r1, #0
	bne _08051F6A
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	cmp r1, #0
	beq _08051F6A
	cmp r1, r7
	bne _08051FA4
_08051F6A:
	ldr r3, _08051FA0
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _080520DC
	.align 2, 0
_08051F88: .4byte 0x02023E90
_08051F8C: .4byte 0x0000FFFF
_08051F90: .4byte 0x02023EEC
_08051F94: .4byte 0x02023EB0
_08051F98: .4byte 0x02023D28
_08051F9C: .4byte 0x02023EAF
_08051FA0: .4byte 0x02023EB8
_08051FA4:
	movs r2, #0
	mov r3, ip
	adds r3, #0xc
	adds r0, r4, r3
	ldrh r0, [r0]
	ldr r4, _08052034
	mov sl, r4
	cmp r0, r1
	beq _08051FDE
	mov r8, r3
	adds r7, r5, #0
	adds r5, r6, #0
	mov r4, sb
	movs r3, #0x58
_08051FC0:
	adds r2, #1
	cmp r2, #3
	bgt _08051FDE
	lsls r1, r2, #1
	ldrb r0, [r4]
	muls r0, r3, r0
	adds r1, r1, r0
	add r1, r8
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	bne _08051FC0
_08051FDE:
	cmp r2, #4
	bne _080520C0
	ldr r5, _08052038
	ldrb r1, [r5]
	lsls r1, r1, #1
	mov r2, sb
	ldrb r0, [r2]
	movs r6, #0x58
	muls r0, r6, r0
	adds r1, r1, r0
	mov r0, ip
	adds r0, #0xc
	adds r1, r1, r0
	ldr r2, _0805203C
	ldr r3, _08052040
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	ldr r4, _08052044
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r4, [r0, #4]
	cmp r4, #4
	bhi _08052048
	mov r1, sb
	ldrb r0, [r1]
	muls r0, r6, r0
	ldrb r1, [r5]
	adds r0, r0, r1
	mov r1, ip
	adds r1, #0x24
	adds r0, r0, r1
	strb r4, [r0]
	b _0805205C
	.align 2, 0
_08052034: .4byte 0x02023EB8
_08052038: .4byte 0x02023E8C
_0805203C: .4byte 0x02023EEC
_08052040: .4byte 0x02023EB0
_08052044: .4byte 0x082ED220
_08052048:
	mov r4, sb
	ldrb r0, [r4]
	muls r0, r6, r0
	ldrb r1, [r5]
	adds r0, r0, r1
	mov r1, ip
	adds r1, #0x24
	adds r0, r0, r1
	movs r1, #5
	strb r1, [r0]
_0805205C:
	ldr r1, _080520B4
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #2
	strb r0, [r1, #1]
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1, #2]
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r0, r0, #8
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _080520B8
	mov r2, sb
	ldrb r0, [r2]
	lsls r2, r0, #3
	subs r2, r2, r0
	lsls r2, r2, #2
	adds r2, r2, r1
	ldrb r4, [r2, #0x18]
	lsrs r3, r4, #4
	ldr r1, _080520BC
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	orrs r1, r3
	lsls r1, r1, #4
	movs r0, #0xf
	ands r0, r4
	orrs r0, r1
	strb r0, [r2, #0x18]
	mov r4, sl
	ldr r0, [r4]
	adds r0, #5
	str r0, [r4]
	b _080520DC
	.align 2, 0
_080520B4: .4byte 0x02022C0C
_080520B8: .4byte 0x02023F60
_080520BC: .4byte 0x082FACB4
_080520C0:
	mov r0, sl
	ldr r2, [r0]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	mov r2, sl
	str r1, [r2]
_080520DC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end atk9D_mimicattackcopy

	thumb_func_start atk9E_metronome
atk9E_metronome: @ 0x080520EC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r7, _0805216C
	movs r6, #0xb1
	lsls r6, r6, #1
	ldr r5, _08052170
	ldr r0, _08052174
	mov r8, r0
_080520FE:
	bl Random
	ldr r2, _08052178
	adds r1, r2, #0
	ands r0, r1
	adds r0, #1
	strh r0, [r7]
	cmp r0, r6
	bhi _080520FE
	movs r0, #3
_08052112:
	subs r0, #1
	cmp r0, #0
	bge _08052112
	ldr r4, _0805216C
	ldrh r2, [r4]
	ldr r3, _0805217C
	subs r0, r5, #2
_08052120:
	adds r0, #2
	ldrh r1, [r0]
	cmp r1, r2
	beq _0805212C
	cmp r1, r3
	bne _08052120
_0805212C:
	ldr r0, _0805217C
	cmp r1, r0
	bne _080520FE
	ldr r2, _08052180
	ldr r0, [r2]
	ldr r1, _08052184
	ands r0, r1
	str r0, [r2]
	ldr r3, _08052188
	ldr r2, _0805218C
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	mov r1, r8
	str r0, [r1]
	ldrh r0, [r4]
	movs r1, #0
	bl GetMoveTarget
	ldr r1, _08052190
	strb r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805216C: .4byte 0x02023E8E
_08052170: .4byte 0x082ECD64
_08052174: .4byte 0x02023EB8
_08052178: .4byte 0x000001FF
_0805217C: .4byte 0x0000FFFF
_08052180: .4byte 0x02023F24
_08052184: .4byte 0xFFFFFBFF
_08052188: .4byte 0x08286C30
_0805218C: .4byte 0x082ED220
_08052190: .4byte 0x02023EB0
	thumb_func_end atk9E_metronome

	thumb_func_start atk9F_dmgtolevel
atk9F_dmgtolevel: @ 0x08052194
	ldr r3, _080521B4
	ldr r2, _080521B8
	ldr r0, _080521BC
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0x2a
	ldrb r0, [r0]
	str r0, [r3]
	ldr r1, _080521C0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_080521B4: .4byte 0x02023E94
_080521B8: .4byte 0x02023D28
_080521BC: .4byte 0x02023EAF
_080521C0: .4byte 0x02023EB8
	thumb_func_end atk9F_dmgtolevel

	thumb_func_start atkA0_psywavedamageeffect
atkA0_psywavedamageeffect: @ 0x080521C4
	push {r4, lr}
	movs r4, #0xf
_080521C8:
	bl Random
	adds r3, r4, #0
	ands r3, r0
	cmp r3, #0xa
	bgt _080521C8
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r3, r0, #1
	ldr r4, _08052208
	ldr r2, _0805220C
	ldr r0, _08052210
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0x2a
	ldrb r1, [r0]
	adds r0, r3, #0
	adds r0, #0x32
	muls r0, r1, r0
	movs r1, #0x64
	bl __divsi3
	str r0, [r4]
	ldr r1, _08052214
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08052208: .4byte 0x02023E94
_0805220C: .4byte 0x02023D28
_08052210: .4byte 0x02023EAF
_08052214: .4byte 0x02023EB8
	thumb_func_end atkA0_psywavedamageeffect

	thumb_func_start atkA1_counterdamagecalculator
atkA1_counterdamagecalculator: @ 0x08052218
	push {r4, r5, r6, lr}
	ldr r4, _08052288
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r5, _0805228C
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r0, r0, r5
	ldrb r0, [r0, #0xc]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldrb r0, [r4]
	lsls r1, r0, #4
	adds r0, r5, #4
	adds r0, r1, r0
	ldr r3, [r0]
	cmp r3, #0
	beq _080522CC
	cmp r6, r2
	beq _080522CC
	ldr r6, _08052290
	adds r0, r1, r5
	ldrb r0, [r0, #0xc]
	movs r4, #0x58
	muls r0, r4, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _080522CC
	ldr r1, _08052294
	lsls r0, r3, #1
	str r0, [r1]
	ldr r1, _08052298
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r0, r1
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _080522A0
	ldrb r1, [r1, #9]
	adds r0, r1, #0
	muls r0, r4, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _080522A0
	ldr r0, _0805229C
	strb r1, [r0]
	b _080522B0
	.align 2, 0
_08052288: .4byte 0x02023EAF
_0805228C: .4byte 0x02023FE0
_08052290: .4byte 0x02023D28
_08052294: .4byte 0x02023E94
_08052298: .4byte 0x02023F38
_0805229C: .4byte 0x02023EB0
_080522A0:
	ldr r2, _080522BC
	ldr r1, _080522C0
	ldr r0, _080522C4
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0, #0xc]
	strb r0, [r2]
_080522B0:
	ldr r1, _080522C8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _080522FC
	.align 2, 0
_080522BC: .4byte 0x02023EB0
_080522C0: .4byte 0x02023FE0
_080522C4: .4byte 0x02023EAF
_080522C8: .4byte 0x02023EB8
_080522CC:
	ldr r2, _08052304
	ldr r0, _08052308
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r3, _0805230C
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_080522FC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08052304: .4byte 0x02024020
_08052308: .4byte 0x02023EAF
_0805230C: .4byte 0x02023EB8
	thumb_func_end atkA1_counterdamagecalculator

	thumb_func_start atkA2_mirrorcoatdamagecalculator
atkA2_mirrorcoatdamagecalculator: @ 0x08052310
	push {r4, r5, r6, lr}
	ldr r4, _08052380
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r5, _08052384
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r0, r0, r5
	ldrb r0, [r0, #0xd]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	ldrb r0, [r4]
	lsls r1, r0, #4
	adds r0, r5, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r3, [r0]
	cmp r3, #0
	beq _080523C4
	cmp r6, r2
	beq _080523C4
	ldr r6, _08052388
	adds r0, r1, r5
	ldrb r0, [r0, #0xd]
	movs r4, #0x58
	muls r0, r4, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _080523C4
	ldr r1, _0805238C
	lsls r0, r3, #1
	str r0, [r1]
	ldr r1, _08052390
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r1, r0, r1
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08052398
	ldrb r1, [r1, #9]
	adds r0, r1, #0
	muls r0, r4, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _08052398
	ldr r0, _08052394
	strb r1, [r0]
	b _080523A8
	.align 2, 0
_08052380: .4byte 0x02023EAF
_08052384: .4byte 0x02023FE0
_08052388: .4byte 0x02023D28
_0805238C: .4byte 0x02023E94
_08052390: .4byte 0x02023F38
_08052394: .4byte 0x02023EB0
_08052398:
	ldr r2, _080523B4
	ldr r1, _080523B8
	ldr r0, _080523BC
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0, #0xd]
	strb r0, [r2]
_080523A8:
	ldr r1, _080523C0
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _080523F4
	.align 2, 0
_080523B4: .4byte 0x02023EB0
_080523B8: .4byte 0x02023FE0
_080523BC: .4byte 0x02023EAF
_080523C0: .4byte 0x02023EB8
_080523C4:
	ldr r2, _080523FC
	ldr r0, _08052400
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r3, _08052404
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_080523F4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080523FC: .4byte 0x02024020
_08052400: .4byte 0x02023EAF
_08052404: .4byte 0x02023EB8
	thumb_func_end atkA2_mirrorcoatdamagecalculator

	thumb_func_start atkA3_disablelastusedattack
atkA3_disablelastusedattack: @ 0x08052408
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r4, #0
	ldr r2, _08052508
	ldr r3, _0805250C
	ldrb r1, [r3]
	movs r0, #0x58
	muls r0, r1, r0
	adds r7, r2, #0
	adds r7, #0xc
	adds r0, r0, r7
	ldr r5, _08052510
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r0]
	mov sb, r2
	adds r6, r3, #0
	ldr r2, _08052514
	mov r8, r2
	ldrh r1, [r1]
	cmp r0, r1
	beq _0805245C
	mov ip, r6
	movs r3, #0x58
_0805243C:
	adds r4, #1
	cmp r4, #3
	bgt _0805245C
	lsls r2, r4, #1
	mov r0, ip
	ldrb r1, [r0]
	adds r0, r1, #0
	muls r0, r3, r0
	adds r2, r2, r0
	adds r2, r2, r7
	lsls r1, r1, #1
	adds r1, r1, r5
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0805243C
_0805245C:
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	ldrh r0, [r0, #4]
	cmp r0, #0
	bne _08052520
	cmp r4, #4
	beq _08052520
	movs r5, #0x58
	adds r0, r1, #0
	muls r0, r5, r0
	adds r0, r4, r0
	mov r1, sb
	adds r1, #0x24
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08052520
	ldr r1, _08052518
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #2
	strb r0, [r1, #1]
	lsls r2, r4, #1
	ldrb r0, [r6]
	muls r0, r5, r0
	adds r0, r2, r0
	mov r3, sb
	adds r3, #0xc
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r1, #2]
	ldrb r0, [r6]
	muls r0, r5, r0
	adds r0, r2, r0
	adds r0, r0, r3
	ldrh r0, [r0]
	lsrs r0, r0, #8
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, r8
	muls r1, r5, r1
	adds r2, r2, r1
	adds r2, r2, r3
	ldrh r1, [r2]
	strh r1, [r0, #4]
	bl Random
	ldrb r2, [r6]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	add r1, r8
	movs r2, #3
	ands r2, r0
	adds r2, #2
	ldrb r3, [r1, #0xb]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #0xb]
	ldrb r0, [r6]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, r8
	ldrb r3, [r1, #0xb]
	lsls r2, r3, #0x1c
	lsrs r2, r2, #0x18
	movs r0, #0xf
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #0xb]
	ldr r1, _0805251C
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _0805253A
	.align 2, 0
_08052508: .4byte 0x02023D28
_0805250C: .4byte 0x02023EB0
_08052510: .4byte 0x02023EEC
_08052514: .4byte 0x02023F60
_08052518: .4byte 0x02022C0C
_0805251C: .4byte 0x02023EB8
_08052520:
	ldr r3, _08052548
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_0805253A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052548: .4byte 0x02023EB8
	thumb_func_end atkA3_disablelastusedattack

	thumb_func_start atkA4_trysetencore
atkA4_trysetencore: @ 0x0805254C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r5, #0
	ldr r3, _08052640
	ldr r4, _08052644
	ldrb r1, [r4]
	movs r0, #0x58
	muls r0, r1, r0
	adds r6, r3, #0
	adds r6, #0xc
	adds r0, r0, r6
	ldr r2, _08052648
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r0, [r0]
	mov sl, r3
	mov r8, r2
	ldr r2, _0805264C
	mov sb, r2
	ldrh r1, [r1]
	cmp r0, r1
	beq _080525A6
	mov ip, r4
	adds r7, r6, #0
	mov r6, r8
	movs r3, #0x58
_08052586:
	adds r5, #1
	cmp r5, #3
	bgt _080525A6
	lsls r2, r5, #1
	mov r0, ip
	ldrb r1, [r0]
	adds r0, r1, #0
	muls r0, r3, r0
	adds r2, r2, r0
	adds r2, r2, r7
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08052586
_080525A6:
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r2, [r0]
	cmp r2, #0xa5
	beq _080525BA
	cmp r2, #0xe3
	beq _080525BA
	cmp r2, #0x77
	bne _080525BC
_080525BA:
	movs r5, #4
_080525BC:
	ldrb r1, [r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	mov r2, sb
	adds r3, r0, r2
	ldrh r0, [r3, #6]
	cmp r0, #0
	bne _08052654
	cmp r5, #4
	beq _08052654
	movs r0, #0x58
	adds r2, r1, #0
	muls r2, r0, r2
	adds r0, r5, r2
	mov r1, sl
	adds r1, #0x24
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08052654
	lsls r0, r5, #1
	adds r0, r0, r2
	subs r1, #0x18
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r3, #6]
	ldrb r1, [r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, sb
	strb r5, [r0, #0xc]
	bl Random
	ldrb r2, [r4]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	add r1, sb
	movs r2, #3
	ands r2, r0
	adds r2, #3
	ldrb r3, [r1, #0xe]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #0xe]
	ldrb r0, [r4]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, sb
	ldrb r3, [r1, #0xe]
	lsls r2, r3, #0x1c
	lsrs r2, r2, #0x18
	movs r0, #0xf
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #0xe]
	ldr r1, _08052650
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _0805266E
	.align 2, 0
_08052640: .4byte 0x02023D28
_08052644: .4byte 0x02023EB0
_08052648: .4byte 0x02023EEC
_0805264C: .4byte 0x02023F60
_08052650: .4byte 0x02023EB8
_08052654:
	ldr r3, _0805267C
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_0805266E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805267C: .4byte 0x02023EB8
	thumb_func_end atkA4_trysetencore

	thumb_func_start atkA5_painsplitdmgcalc
atkA5_painsplitdmgcalc: @ 0x08052680
	push {r4, r5, r6, r7, lr}
	ldr r6, _08052700
	ldr r0, _08052704
	mov ip, r0
	ldrb r0, [r0]
	movs r7, #0x58
	adds r2, r0, #0
	muls r2, r7, r2
	adds r0, r6, #0
	adds r0, #0x50
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x11
	ands r0, r1
	cmp r0, #0
	bne _08052720
	ldr r5, _08052708
	ldrb r0, [r5]
	muls r0, r7, r0
	adds r0, r0, r6
	ldrh r3, [r0, #0x28]
	adds r0, r2, r6
	ldrh r1, [r0, #0x28]
	adds r3, r3, r1
	asrs r3, r3, #1
	ldr r4, _0805270C
	subs r1, r1, r3
	str r1, [r4]
	ldr r2, _08052710
	strb r1, [r2]
	movs r0, #0xff
	lsls r0, r0, #8
	ands r0, r1
	asrs r0, r0, #8
	strb r0, [r2, #1]
	movs r0, #0xff
	lsls r0, r0, #0x10
	ands r0, r1
	asrs r0, r0, #0x10
	strb r0, [r2, #2]
	lsrs r1, r1, #0x18
	strb r1, [r2, #3]
	ldrb r0, [r5]
	muls r0, r7, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x28]
	subs r0, r0, r3
	str r0, [r4]
	ldr r2, _08052714
	mov r0, ip
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, #4
	adds r0, r0, r2
	ldr r1, _08052718
	str r1, [r0]
	ldr r1, _0805271C
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _0805273A
	.align 2, 0
_08052700: .4byte 0x02023D28
_08052704: .4byte 0x02023EB0
_08052708: .4byte 0x02023EAF
_0805270C: .4byte 0x02023E94
_08052710: .4byte 0x02024118
_08052714: .4byte 0x02024020
_08052718: .4byte 0x0000FFFF
_0805271C: .4byte 0x02023EB8
_08052720:
	ldr r3, _08052740
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_0805273A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052740: .4byte 0x02023EB8
	thumb_func_end atkA5_painsplitdmgcalc

	thumb_func_start atkA6_settypetorandomresistance
atkA6_settypetorandomresistance: @ 0x08052744
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r1, _080527AC
	ldr r4, _080527B0
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r2, r0, r1
	ldrh r1, [r2]
	cmp r1, #0
	beq _0805278E
	ldr r0, _080527B4
	cmp r1, r0
	beq _0805278E
	ldrh r0, [r2]
	bl IsTwoTurnsMove
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0805282C
	ldr r1, _080527B8
	ldr r2, _080527BC
	ldrb r0, [r4]
	adds r0, r0, r2
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _0805282C
_0805278E:
	ldr r3, _080527C0
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08052918
	.align 2, 0
_080527AC: .4byte 0x02023EF4
_080527B0: .4byte 0x02023EAF
_080527B4: .4byte 0x0000FFFF
_080527B8: .4byte 0x02023D28
_080527BC: .4byte 0x02023F14
_080527C0: .4byte 0x02023EB8
_080527C4:
	mov r0, ip
	strb r5, [r0]
	mov r1, sl
	ldrb r0, [r1]
	muls r0, r2, r0
	adds r0, r0, r7
	adds r0, #0x22
	strb r5, [r0]
	ldr r1, _080527E8
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #3
	strb r0, [r1, #1]
	strb r5, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r1, _080527EC
	b _0805281A
	.align 2, 0
_080527E8: .4byte 0x02022C0C
_080527EC: .4byte 0x02023EB8
_080527F0:
	mov r0, r8
	adds r0, #1
	adds r0, r0, r3
	ldrb r2, [r0]
	strb r2, [r4]
	mov r4, sl
	ldrb r0, [r4]
	muls r0, r6, r0
	ldr r7, _08052824
	adds r0, r0, r7
	adds r0, #0x22
	strb r2, [r0]
	ldr r1, _08052828
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #3
	strb r0, [r1, #1]
	strb r2, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	mov r1, ip
_0805281A:
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08052918
	.align 2, 0
_08052824: .4byte 0x02023D28
_08052828: .4byte 0x02022C0C
_0805282C:
	movs r4, #0
	mov r8, r4
	movs r7, #0x7f
	mov sb, r7
_08052834:
	bl Random
	mov r4, sb
	ands r4, r0
	cmp r4, #0x70
	bhi _08052834
	lsls r0, r4, #1
	adds r4, r0, r4
	ldr r6, _08052928
	adds r3, r4, r6
	ldr r1, _0805292C
	ldr r2, _08052930
	ldrb r5, [r2]
	lsls r0, r5, #1
	adds r0, r0, r1
	ldrb r1, [r3]
	mov sl, r2
	ldrh r0, [r0]
	cmp r1, r0
	bne _08052890
	adds r0, r4, #2
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #5
	bhi _08052890
	ldr r7, _08052934
	movs r2, #0x58
	adds r0, r5, #0
	muls r0, r2, r0
	adds r3, r0, r7
	movs r0, #0x21
	adds r0, r0, r3
	mov ip, r0
	adds r0, r4, #1
	adds r0, r0, r6
	ldrb r5, [r0]
	mov r1, ip
	ldrb r0, [r1]
	adds r1, r5, #0
	cmp r0, r1
	beq _08052890
	adds r0, r3, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, r1
	bne _080527C4
_08052890:
	movs r7, #1
	add r8, r7
	ldr r0, _08052938
	cmp r8, r0
	ble _08052834
	movs r0, #0
	mov r8, r0
	ldr r1, _0805293C
	mov ip, r1
	ldr r3, _08052928
	adds r0, r4, #1
	adds r0, r0, r3
	mov sb, r0
	adds r5, r3, #0
_080528AC:
	ldrb r1, [r5]
	cmp r1, #0xff
	bgt _080528B6
	cmp r1, #0xfe
	bge _080528F0
_080528B6:
	mov r4, sl
	ldrb r2, [r4]
	lsls r0, r2, #1
	ldr r7, _0805292C
	adds r0, r0, r7
	ldrh r0, [r0]
	cmp r1, r0
	bne _080528F0
	ldrb r0, [r5, #2]
	cmp r0, #5
	bhi _080528F0
	movs r6, #0x58
	adds r0, r2, #0
	muls r0, r6, r0
	ldr r1, _08052934
	adds r2, r0, r1
	adds r4, r2, #0
	adds r4, #0x21
	ldrb r0, [r4]
	mov r7, sb
	ldrb r1, [r7]
	cmp r0, r1
	beq _080528F0
	adds r0, r2, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, r1
	beq _080528F0
	b _080527F0
_080528F0:
	adds r5, #3
	movs r0, #3
	add r8, r0
	ldr r0, _08052940
	cmp r8, r0
	bls _080528AC
	mov r1, ip
	ldr r2, [r1]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	mov r4, ip
	str r1, [r4]
_08052918:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052928: .4byte 0x082EBB38
_0805292C: .4byte 0x02023EFC
_08052930: .4byte 0x02023EAF
_08052934: .4byte 0x02023D28
_08052938: .4byte 0x000003E7
_0805293C: .4byte 0x02023EB8
_08052940: .4byte 0x0000014F
	thumb_func_end atkA6_settypetorandomresistance

	thumb_func_start atkA7_setalwayshitflag
atkA7_setalwayshitflag: @ 0x08052944
	push {r4, lr}
	ldr r4, _08052988
	ldr r3, _0805298C
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r1]
	movs r2, #0x19
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r1]
	movs r2, #0x10
	orrs r0, r2
	str r0, [r1]
	ldr r2, _08052990
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r1, _08052994
	ldrb r1, [r1]
	strb r1, [r0, #0x15]
	ldr r1, _08052998
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08052988: .4byte 0x02023F50
_0805298C: .4byte 0x02023EB0
_08052990: .4byte 0x02023F60
_08052994: .4byte 0x02023EAF
_08052998: .4byte 0x02023EB8
	thumb_func_end atkA7_setalwayshitflag

	thumb_func_start atkA8_copymovepermanently
atkA8_copymovepermanently: @ 0x0805299C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	ldr r0, _08052AFC
	ldr r1, _08052B00
	adds r5, r1, #0
	strh r5, [r0]
	ldr r3, _08052B04
	ldr r2, _08052B08
	ldrb r1, [r2]
	movs r0, #0x58
	adds r4, r1, #0
	muls r4, r0, r4
	adds r0, r3, #0
	adds r0, #0x50
	adds r0, r4, r0
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xe
	ands r1, r0
	mov ip, r3
	mov sl, r2
	cmp r1, #0
	beq _080529D4
	b _08052B28
_080529D4:
	ldr r0, _08052B0C
	ldr r2, _08052B10
	ldrb r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	ldrh r1, [r1]
	mov sb, r0
	mov r8, r2
	cmp r1, #0xa5
	bne _080529EA
	b _08052B28
_080529EA:
	cmp r1, #0
	bne _080529F0
	b _08052B28
_080529F0:
	cmp r1, r5
	bne _080529F6
	b _08052B28
_080529F6:
	cmp r1, #0xa6
	bne _080529FC
	b _08052B28
_080529FC:
	movs r7, #0
	mov r5, sb
	mov r0, ip
	adds r0, #0xc
	adds r1, r4, r0
	mov r3, r8
_08052A08:
	ldrh r2, [r1]
	cmp r2, #0xa6
	beq _08052A1A
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	cmp r2, r0
	beq _08052A22
_08052A1A:
	adds r1, #2
	adds r7, #1
	cmp r7, #3
	ble _08052A08
_08052A22:
	cmp r7, #4
	beq _08052A28
	b _08052B28
_08052A28:
	ldr r4, _08052B14
	ldrb r1, [r4]
	lsls r1, r1, #1
	mov r2, sl
	ldrb r0, [r2]
	movs r3, #0x58
	muls r0, r3, r0
	adds r1, r1, r0
	mov r6, ip
	adds r6, #0xc
	adds r1, r1, r6
	mov r2, r8
	ldrb r0, [r2]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r1]
	mov r1, sl
	ldrb r0, [r1]
	adds r2, r0, #0
	muls r2, r3, r2
	ldrb r4, [r4]
	adds r2, r2, r4
	mov r5, ip
	adds r5, #0x24
	adds r2, r2, r5
	ldr r4, _08052B18
	mov r1, r8
	ldrb r0, [r1]
	lsls r0, r0, #1
	add r0, sb
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r0, [r0, #4]
	strb r0, [r2]
	ldr r1, _08052B1C
	mov r2, sl
	ldrb r0, [r2]
	strb r0, [r1]
	movs r7, #0
	ldrb r0, [r2]
	muls r0, r3, r0
	adds r4, r0, r5
	adds r3, r0, #0
	add r2, sp, #4
	add r5, sp, #0xc
_08052A8A:
	adds r0, r3, r6
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, r5, r7
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #1
	adds r3, #2
	adds r2, #2
	adds r7, #1
	cmp r7, #3
	ble _08052A8A
	add r2, sp, #4
	mov r0, sl
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	add r0, ip
	adds r0, #0x3b
	ldrb r0, [r0]
	strb r0, [r2, #0xc]
	str r2, [sp]
	movs r0, #0
	movs r1, #3
	movs r2, #0
	movs r3, #0x10
	bl BtlController_EmitSetMonData
	ldr r0, _08052B1C
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	ldr r1, _08052B20
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #2
	strb r0, [r1, #1]
	ldr r3, _08052B0C
	ldr r2, _08052B10
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r1, #2]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsrs r0, r0, #8
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _08052B24
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08052B42
	.align 2, 0
_08052AFC: .4byte 0x02023E90
_08052B00: .4byte 0x0000FFFF
_08052B04: .4byte 0x02023D28
_08052B08: .4byte 0x02023EAF
_08052B0C: .4byte 0x02023EE4
_08052B10: .4byte 0x02023EB0
_08052B14: .4byte 0x02023E8C
_08052B18: .4byte 0x082ED220
_08052B1C: .4byte 0x02023D08
_08052B20: .4byte 0x02022C0C
_08052B24: .4byte 0x02023EB8
_08052B28:
	ldr r3, _08052B54
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08052B42:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052B54: .4byte 0x02023EB8
	thumb_func_end atkA8_copymovepermanently

	thumb_func_start IsTwoTurnsMove
IsTwoTurnsMove: @ 0x08052B58
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _08052B88
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r0, [r1]
	cmp r0, #0x91
	beq _08052B82
	cmp r0, #0x27
	beq _08052B82
	cmp r0, #0x4b
	beq _08052B82
	cmp r0, #0x97
	beq _08052B82
	cmp r0, #0x9b
	beq _08052B82
	cmp r0, #0x1a
	bne _08052B8C
_08052B82:
	movs r0, #1
	b _08052B8E
	.align 2, 0
_08052B88: .4byte 0x082ED220
_08052B8C:
	movs r0, #0
_08052B8E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end IsTwoTurnsMove

	thumb_func_start IsInvalidForSleepTalkOrAssist
IsInvalidForSleepTalkOrAssist: @ 0x08052B94
	push {lr}
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08052BB2
	cmp r1, #0xd6
	beq _08052BB2
	movs r0, #0x89
	lsls r0, r0, #1
	cmp r1, r0
	beq _08052BB2
	cmp r1, #0x77
	beq _08052BB2
	cmp r1, #0x76
	bne _08052BB6
_08052BB2:
	movs r0, #1
	b _08052BB8
_08052BB6:
	movs r0, #0
_08052BB8:
	pop {r1}
	bx r1
	thumb_func_end IsInvalidForSleepTalkOrAssist

	thumb_func_start AttacksThisTurn
AttacksThisTurn: @ 0x08052BBC
	push {lr}
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	ldr r1, _08052C14
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r3, r1, #0
	cmp r0, #0x97
	bne _08052BE0
	ldr r0, _08052C18
	ldrh r1, [r0]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	bne _08052C20
_08052BE0:
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0x91
	beq _08052C02
	cmp r0, #0x27
	beq _08052C02
	cmp r0, #0x4b
	beq _08052C02
	cmp r0, #0x97
	beq _08052C02
	cmp r0, #0x9b
	beq _08052C02
	cmp r0, #0x1a
	bne _08052C20
_08052C02:
	ldr r0, _08052C1C
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ands r0, r1
	cmp r0, #0
	beq _08052C20
	movs r0, #1
	b _08052C22
	.align 2, 0
_08052C14: .4byte 0x082ED220
_08052C18: .4byte 0x02024070
_08052C1C: .4byte 0x02023F24
_08052C20:
	movs r0, #2
_08052C22:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end AttacksThisTurn

	thumb_func_start atkA9_trychoosesleeptalkmove
atkA9_trychoosesleeptalkmove: @ 0x08052C28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r6, #0
	movs r5, #0
	ldr r0, _08052CB8
	mov sb, r0
	movs r1, #0x58
	mov r8, r1
	ldr r7, _08052CBC
	movs r0, #0x84
	lsls r0, r0, #1
	mov sl, r0
_08052C46:
	lsls r4, r5, #1
	mov r1, sb
	ldrb r0, [r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r4, r0
	adds r0, r0, r7
	ldrh r0, [r0]
	bl IsInvalidForSleepTalkOrAssist
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08052C86
	mov r1, sb
	ldrb r0, [r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r4, r0
	adds r0, r0, r7
	ldrh r1, [r0]
	cmp r1, sl
	beq _08052C86
	cmp r1, #0xfd
	beq _08052C86
	adds r0, r1, #0
	bl IsTwoTurnsMove
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08052C94
_08052C86:
	ldr r1, _08052CC0
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	orrs r6, r0
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
_08052C94:
	adds r5, #1
	cmp r5, #3
	ble _08052C46
	ldr r0, _08052CB8
	ldrb r0, [r0]
	adds r1, r6, #0
	movs r2, #0xfd
	bl CheckMoveLimitations
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0xf
	bne _08052CC8
	ldr r1, _08052CC4
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08052D2C
	.align 2, 0
_08052CB8: .4byte 0x02023EAF
_08052CBC: .4byte 0x02023D34
_08052CC0: .4byte 0x082FACB4
_08052CC4: .4byte 0x02023EB8
_08052CC8:
	movs r7, #3
	ldr r4, _08052D3C
_08052CCC:
	bl Random
	adds r5, r7, #0
	ands r5, r0
	lsls r0, r5, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ands r0, r6
	cmp r0, #0
	bne _08052CCC
	ldr r4, _08052D40
	ldr r2, _08052D44
	lsls r1, r5, #1
	ldr r0, _08052D48
	ldrb r3, [r0]
	movs r0, #0x58
	muls r0, r3, r0
	adds r1, r1, r0
	adds r2, #0xc
	adds r1, r1, r2
	ldrh r0, [r1]
	strh r0, [r4]
	ldr r0, _08052D4C
	strb r5, [r0]
	ldr r2, _08052D50
	ldr r0, [r2]
	ldr r1, _08052D54
	ands r0, r1
	str r0, [r2]
	ldrh r0, [r4]
	movs r1, #0
	bl GetMoveTarget
	ldr r1, _08052D58
	strb r0, [r1]
	ldr r3, _08052D5C
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08052D2C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08052D3C: .4byte 0x082FACB4
_08052D40: .4byte 0x02023E92
_08052D44: .4byte 0x02023D28
_08052D48: .4byte 0x02023EAF
_08052D4C: .4byte 0x02023E8C
_08052D50: .4byte 0x02023F24
_08052D54: .4byte 0xFFFFFBFF
_08052D58: .4byte 0x02023EB0
_08052D5C: .4byte 0x02023EB8
	thumb_func_end atkA9_trychoosesleeptalkmove

	thumb_func_start atkAA_setdestinybond
atkAA_setdestinybond: @ 0x08052D60
	ldr r1, _08052D84
	ldr r0, _08052D88
	ldrb r2, [r0]
	movs r0, #0x58
	muls r2, r0, r2
	adds r1, #0x50
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x12
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08052D8C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_08052D84: .4byte 0x02023D28
_08052D88: .4byte 0x02023EAF
_08052D8C: .4byte 0x02023EB8
	thumb_func_end atkAA_setdestinybond

	thumb_func_start TrySetDestinyBondToHappen
TrySetDestinyBondToHappen: @ 0x08052D90
	push {r4, r5, lr}
	ldr r0, _08052DE0
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r4, _08052DE4
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r1, _08052DE8
	ldrb r2, [r4]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x12
	ands r0, r1
	cmp r0, #0
	beq _08052DDA
	cmp r5, r3
	beq _08052DDA
	ldr r2, _08052DEC
	ldr r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r0, r1
	cmp r0, #0
	bne _08052DDA
	movs r0, #0x40
	orrs r1, r0
	str r1, [r2]
_08052DDA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08052DE0: .4byte 0x02023EAF
_08052DE4: .4byte 0x02023EB0
_08052DE8: .4byte 0x02023D28
_08052DEC: .4byte 0x02023F24
	thumb_func_end TrySetDestinyBondToHappen

	thumb_func_start atkAB_trysetdestinybondtohappen
atkAB_trysetdestinybondtohappen: @ 0x08052DF0
	push {lr}
	bl TrySetDestinyBondToHappen
	ldr r1, _08052E04
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08052E04: .4byte 0x02023EB8
	thumb_func_end atkAB_trysetdestinybondtohappen

	thumb_func_start atkAC_remaininghptopower
atkAC_remaininghptopower: @ 0x08052E08
	push {lr}
	ldr r2, _08052E5C
	ldr r0, _08052E60
	ldrb r1, [r0]
	movs r0, #0x58
	muls r1, r0, r1
	adds r1, r1, r2
	movs r2, #0x28
	ldrsh r0, [r1, r2]
	movs r2, #0x2c
	ldrsh r1, [r1, r2]
	movs r2, #0x30
	bl GetScaledHPFraction
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	movs r3, #0
	ldr r0, _08052E64
	ldrb r2, [r0]
	cmp r1, r2
	ble _08052E42
	adds r2, r0, #0
_08052E34:
	adds r3, #2
	cmp r3, #0xb
	bgt _08052E42
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r1, r0
	bgt _08052E34
_08052E42:
	ldr r2, _08052E68
	ldr r1, _08052E64
	adds r0, r3, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r2]
	ldr r1, _08052E6C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08052E5C: .4byte 0x02023D28
_08052E60: .4byte 0x02023EAF
_08052E64: .4byte 0x082ECD8C
_08052E68: .4byte 0x020240A4
_08052E6C: .4byte 0x02023EB8
	thumb_func_end atkAC_remaininghptopower

	thumb_func_start atkAD_tryspiteppreduce
atkAD_tryspiteppreduce: @ 0x08052E70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, _08052FF0
	ldr r1, _08052FF4
	ldrb r3, [r1]
	lsls r0, r3, #1
	adds r0, r0, r4
	ldrh r2, [r0]
	mov r8, r1
	cmp r2, #0
	bne _08052E90
	b _08053018
_08052E90:
	ldr r0, _08052FF8
	cmp r2, r0
	bne _08052E98
	b _08053018
_08052E98:
	movs r7, #0
	ldr r0, _08052FFC
	movs r1, #0x58
	muls r1, r3, r1
	adds r3, r0, #0
	adds r3, #0xc
	adds r1, r1, r3
	ldrh r1, [r1]
	cmp r2, r1
	beq _08052ED0
	adds r6, r4, #0
	mov r5, r8
	adds r4, r3, #0
	movs r3, #0x58
_08052EB4:
	adds r7, #1
	cmp r7, #3
	bgt _08052ED0
	ldrb r0, [r5]
	lsls r2, r0, #1
	adds r2, r2, r6
	lsls r1, r7, #1
	muls r0, r3, r0
	adds r1, r1, r0
	adds r1, r1, r4
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08052EB4
_08052ED0:
	cmp r7, #4
	bne _08052ED6
	b _08053018
_08052ED6:
	mov r4, r8
	ldrb r0, [r4]
	movs r1, #0x58
	mov sb, r1
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, r7, r0
	ldr r1, _08052FFC
	adds r1, #0x24
	mov sl, r1
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #1
	bhi _08052EF6
	b _08053018
_08052EF6:
	bl Random
	movs r1, #3
	ands r1, r0
	adds r6, r1, #2
	ldrb r0, [r4]
	mov r3, sb
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, r7, r0
	add r0, sl
	ldrb r0, [r0]
	cmp r0, r6
	bge _08052F14
	adds r6, r0, #0
_08052F14:
	ldr r1, _08053000
	movs r5, #0xfd
	strb r5, [r1]
	movs r0, #2
	strb r0, [r1, #1]
	ldr r2, _08052FF0
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1, #2]
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r0, r0, #8
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r4, _08053004
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #1
	bl ConvertIntToDecimalStringN
	strb r5, [r4]
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	strb r6, [r4, #4]
	subs r0, #2
	strb r0, [r4, #5]
	mov r1, r8
	ldrb r0, [r1]
	mov r1, sb
	muls r1, r0, r1
	adds r1, r7, r1
	add r1, sl
	ldrb r0, [r1]
	subs r0, r0, r6
	strb r0, [r1]
	ldr r4, _08053008
	mov r3, r8
	ldrb r0, [r3]
	strb r0, [r4]
	ldr r1, _0805300C
	ldrb r3, [r4]
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0x18]
	lsrs r1, r1, #4
	ldr r2, _08053010
	lsls r0, r7, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08052FC8
	mov r2, sb
	muls r2, r3, r2
	ldr r0, _08052FFC
	adds r0, #0x50
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	bne _08052FC8
	adds r1, r7, #0
	adds r1, #9
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r3, sl
	adds r0, r2, r3
	adds r0, r0, r7
	str r0, [sp]
	movs r0, #0
	movs r2, #0
	movs r3, #1
	bl BtlController_EmitSetMonData
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_08052FC8:
	ldr r1, _08053014
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	ldr r1, _08052FFC
	ldr r0, _08052FF4
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r7, r0
	adds r1, #0x24
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08053032
	adds r0, r2, #0
	bl CancelMultiTurnMoves
	b _08053032
	.align 2, 0
_08052FF0: .4byte 0x02023EEC
_08052FF4: .4byte 0x02023EB0
_08052FF8: .4byte 0x0000FFFF
_08052FFC: .4byte 0x02023D28
_08053000: .4byte 0x02022C0C
_08053004: .4byte 0x02022C1C
_08053008: .4byte 0x02023D08
_0805300C: .4byte 0x02023F60
_08053010: .4byte 0x082FACB4
_08053014: .4byte 0x02023EB8
_08053018:
	ldr r3, _08053044
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08053032:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053044: .4byte 0x02023EB8
	thumb_func_end atkAD_tryspiteppreduce

	thumb_func_start atkAE_healpartystatus
atkAE_healpartystatus: @ 0x08053048
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	movs r4, #0
	str r4, [sp, #4]
	mov r8, r4
	ldr r0, _080530B8
	ldrh r0, [r0]
	cmp r0, #0xd7
	beq _08053064
	b _0805324E
_08053064:
	ldr r6, _080530BC
	mov r0, r8
	strb r0, [r6, #5]
	ldr r5, _080530C0
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	ldr r1, _080530C4
	mov sl, r1
	cmp r0, #0
	bne _08053080
	ldr r2, _080530C8
	mov sl, r2
_08053080:
	ldr r4, _080530CC
	ldrb r3, [r5]
	movs r7, #0x58
	adds r2, r3, #0
	muls r2, r7, r2
	adds r0, r2, r4
	adds r1, r0, #0
	adds r1, #0x20
	ldrb r0, [r1]
	cmp r0, #0x2b
	beq _080530D4
	adds r0, r4, #0
	adds r0, #0x4c
	adds r0, r2, r0
	mov r1, r8
	str r1, [r0]
	ldrb r0, [r5]
	adds r2, r0, #0
	muls r2, r7, r2
	adds r0, r4, #0
	adds r0, #0x50
	adds r2, r2, r0
	ldr r0, [r2]
	ldr r1, _080530D0
	ands r0, r1
	str r0, [r2]
	b _080530E4
	.align 2, 0
_080530B8: .4byte 0x02023E8E
_080530BC: .4byte 0x02023FD6
_080530C0: .4byte 0x02023EAF
_080530C4: .4byte 0x020243E8
_080530C8: .4byte 0x02024190
_080530CC: .4byte 0x02023D28
_080530D0: .4byte 0xF7FFFFFF
_080530D4:
	ldrb r1, [r1]
	adds r0, r3, #0
	bl RecordAbilityBattle
	ldrb r0, [r6, #5]
	movs r1, #1
	orrs r0, r1
	strb r0, [r6, #5]
_080530E4:
	ldr r7, _08053158
	ldr r0, _0805315C
	ldrb r0, [r0]
	bl GetBattlerPosition
	movs r2, #2
	mov sb, r2
	mov r1, sb
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	ldr r1, _08053160
	strb r0, [r1, #0x17]
	strb r0, [r7]
	ldr r0, _08053164
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805318A
	ldr r0, _08053168
	ldrb r2, [r0]
	ldr r1, _0805316C
	ldrb r3, [r7]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r2, r0
	cmp r2, #0
	bne _0805318A
	ldr r5, _08053170
	movs r6, #0x58
	adds r4, r3, #0
	muls r4, r6, r4
	adds r0, r4, r5
	adds r1, r0, #0
	adds r1, #0x20
	ldrb r0, [r1]
	cmp r0, #0x2b
	beq _08053178
	adds r0, r5, #0
	adds r0, #0x4c
	adds r0, r4, r0
	str r2, [r0]
	ldrb r0, [r7]
	adds r2, r0, #0
	muls r2, r6, r2
	adds r0, r5, #0
	adds r0, #0x50
	adds r2, r2, r0
	ldr r0, [r2]
	ldr r1, _08053174
	ands r0, r1
	str r0, [r2]
	b _0805318A
	.align 2, 0
_08053158: .4byte 0x02023D08
_0805315C: .4byte 0x02023EAF
_08053160: .4byte 0x02024118
_08053164: .4byte 0x02022C90
_08053168: .4byte 0x02023EB4
_0805316C: .4byte 0x082FACB4
_08053170: .4byte 0x02023D28
_08053174: .4byte 0xF7FFFFFF
_08053178:
	ldrb r1, [r1]
	adds r0, r3, #0
	bl RecordAbilityBattle
	ldr r1, _080531D0
	ldrb r0, [r1, #5]
	mov r2, sb
	orrs r0, r2
	strb r0, [r1, #5]
_0805318A:
	movs r6, #0
	ldr r7, _080531D4
_0805318E:
	movs r0, #0x64
	adds r4, r6, #0
	muls r4, r0, r4
	add r4, sl
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #0x2e
	bl GetMonData3
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r5, #0
	beq _08053246
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r5, r0
	beq _08053246
	ldr r2, _080531D8
	ldr r0, _080531DC
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r6
	bne _080531E0
	movs r0, #0x58
	muls r0, r1, r0
	b _08053210
	.align 2, 0
_080531D0: .4byte 0x02023FD6
_080531D4: .4byte 0x02023D28
_080531D8: .4byte 0x02023D12
_080531DC: .4byte 0x02023EAF
_080531E0:
	ldr r0, _08053218
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08053228
	ldr r0, _0805321C
	ldrb r3, [r0]
	lsls r0, r3, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r6
	bne _08053228
	ldr r0, _08053220
	ldrb r1, [r0]
	ldr r2, _08053224
	lsls r0, r3, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08053228
	movs r0, #0x58
	muls r0, r3, r0
_08053210:
	adds r0, r0, r7
	adds r0, #0x20
	ldrb r0, [r0]
	b _08053234
	.align 2, 0
_08053218: .4byte 0x02022C90
_0805321C: .4byte 0x02023D08
_08053220: .4byte 0x02023EB4
_08053224: .4byte 0x082FACB4
_08053228:
	adds r0, r5, #0
	adds r1, r4, #0
	bl GetAbilityBySpecies
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08053234:
	cmp r0, #0x2b
	beq _08053246
	movs r0, #1
	lsls r0, r6
	mov r1, r8
	orrs r1, r0
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
_08053246:
	adds r6, #1
	cmp r6, #5
	ble _0805318E
	b _080532CC
_0805324E:
	ldr r1, _08053308
	movs r0, #4
	strb r0, [r1, #5]
	movs r2, #0x3f
	mov r8, r2
	ldr r3, _0805330C
	ldr r2, _08053310
	ldrb r0, [r2]
	movs r5, #0x58
	muls r0, r5, r0
	movs r1, #0x4c
	adds r1, r1, r3
	mov sb, r1
	add r0, sb
	str r4, [r0]
	ldrb r0, [r2]
	adds r1, r0, #0
	muls r1, r5, r1
	adds r7, r3, #0
	adds r7, #0x50
	adds r1, r1, r7
	ldr r0, [r1]
	ldr r6, _08053314
	ands r0, r6
	str r0, [r1]
	ldrb r0, [r2]
	bl GetBattlerPosition
	movs r1, #2
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	ldr r4, _08053318
	strb r0, [r4]
	ldr r0, _0805331C
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080532CC
	ldr r0, _08053320
	ldrb r2, [r0]
	ldr r1, _08053324
	ldrb r3, [r4]
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r2, r0
	cmp r2, #0
	bne _080532CC
	adds r0, r3, #0
	muls r0, r5, r0
	add r0, sb
	str r2, [r0]
	ldrb r0, [r4]
	adds r1, r0, #0
	muls r1, r5, r1
	adds r1, r1, r7
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
_080532CC:
	mov r2, r8
	cmp r2, #0
	beq _080532EE
	ldr r4, _08053318
	ldr r0, _08053310
	ldrb r0, [r0]
	strb r0, [r4]
	add r0, sp, #4
	str r0, [sp]
	movs r0, #0
	movs r1, #0x28
	movs r3, #4
	bl BtlController_EmitSetMonData
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_080532EE:
	ldr r1, _08053328
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053308: .4byte 0x02023FD6
_0805330C: .4byte 0x02023D28
_08053310: .4byte 0x02023EAF
_08053314: .4byte 0xF7FFFFFF
_08053318: .4byte 0x02023D08
_0805331C: .4byte 0x02022C90
_08053320: .4byte 0x02023EB4
_08053324: .4byte 0x082FACB4
_08053328: .4byte 0x02023EB8
	thumb_func_end atkAE_healpartystatus

	thumb_func_start atkAF_cursetarget
atkAF_cursetarget: @ 0x0805332C
	push {r4, r5, lr}
	ldr r5, _0805336C
	ldr r0, _08053370
	ldrb r0, [r0]
	movs r4, #0x58
	adds r1, r0, #0
	muls r1, r4, r1
	adds r0, r5, #0
	adds r0, #0x50
	adds r1, r1, r0
	ldr r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #0x15
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq _08053378
	ldr r3, _08053374
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805339C
	.align 2, 0
_0805336C: .4byte 0x02023D28
_08053370: .4byte 0x02023EB0
_08053374: .4byte 0x02023EB8
_08053378:
	orrs r2, r3
	str r2, [r1]
	ldr r1, _080533A4
	ldr r0, _080533A8
	ldrb r0, [r0]
	muls r0, r4, r0
	adds r0, r0, r5
	ldrh r0, [r0, #0x2c]
	lsrs r0, r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _08053394
	movs r0, #1
	str r0, [r1]
_08053394:
	ldr r1, _080533AC
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805339C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080533A4: .4byte 0x02023E94
_080533A8: .4byte 0x02023EAF
_080533AC: .4byte 0x02023EB8
	thumb_func_end atkAF_cursetarget

	thumb_func_start atkB0_trysetspikes
atkB0_trysetspikes: @ 0x080533B0
	push {r4, lr}
	ldr r4, _08053404
	ldrb r0, [r4]
	bl GetBattlerSide
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08053408
	lsls r2, r0, #1
	adds r0, r2, r0
	lsls r0, r0, #2
	adds r3, r0, r1
	ldrb r0, [r3, #0xa]
	cmp r0, #3
	bne _08053414
	ldr r2, _0805340C
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r3, _08053410
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805342E
	.align 2, 0
_08053404: .4byte 0x02023EAF
_08053408: .4byte 0x02023F38
_0805340C: .4byte 0x02024020
_08053410: .4byte 0x02023EB8
_08053414:
	ldr r1, _08053434
	adds r1, r2, r1
	ldrh r2, [r1]
	movs r0, #0x10
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r3, #0xa]
	adds r0, #1
	strb r0, [r3, #0xa]
	ldr r1, _08053438
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805342E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053434: .4byte 0x02023F32
_08053438: .4byte 0x02023EB8
	thumb_func_end atkB0_trysetspikes

	thumb_func_start atkB1_setforesight
atkB1_setforesight: @ 0x0805343C
	ldr r1, _08053460
	ldr r0, _08053464
	ldrb r2, [r0]
	movs r0, #0x58
	muls r2, r0, r2
	adds r1, #0x50
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x16
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08053468
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_08053460: .4byte 0x02023D28
_08053464: .4byte 0x02023EB0
_08053468: .4byte 0x02023EB8
	thumb_func_end atkB1_setforesight

	thumb_func_start atkB2_trysetperishsong
atkB2_trysetperishsong: @ 0x0805346C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r6, #0
	movs r3, #0
	ldr r0, _080534B0
	adds r7, r0, #0
	ldr r0, _080534B4
	mov r8, r0
	ldrb r1, [r7]
	cmp r6, r1
	bge _080534D8
	movs r5, #0x20
	ldr r0, _080534B8
	mov ip, r0
	ldr r0, _080534BC
	adds r4, r0, #0
	adds r4, #0xf
	ldr r2, _080534C0
_08053494:
	ldr r1, [r2]
	adds r0, r1, #0
	ands r0, r5
	cmp r0, #0
	bne _080534AC
	movs r0, #0x58
	muls r0, r3, r0
	add r0, ip
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x2b
	bne _080534C4
_080534AC:
	adds r6, #1
	b _080534CC
	.align 2, 0
_080534B0: .4byte 0x02023D10
_080534B4: .4byte 0x02023EAF
_080534B8: .4byte 0x02023D28
_080534BC: .4byte 0x02023F60
_080534C0: .4byte 0x02023F50
_080534C4:
	orrs r1, r5
	str r1, [r2]
	movs r0, #0x33
	strb r0, [r4]
_080534CC:
	adds r4, #0x1c
	adds r2, #4
	adds r3, #1
	ldrb r0, [r7]
	cmp r3, r0
	blt _08053494
_080534D8:
	mov r1, r8
	ldrb r0, [r1]
	bl PressurePPLoseOnUsingPerishSong
	ldr r0, _08053504
	ldrb r0, [r0]
	cmp r6, r0
	bne _0805350C
	ldr r3, _08053508
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08053514
	.align 2, 0
_08053504: .4byte 0x02023D10
_08053508: .4byte 0x02023EB8
_0805350C:
	ldr r1, _08053520
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08053514:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053520: .4byte 0x02023EB8
	thumb_func_end atkB2_trysetperishsong

	thumb_func_start atkB3_rolloutdamagecalculation
atkB3_rolloutdamagecalculation: @ 0x08053524
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _08053548
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _08053558
	ldr r0, _0805354C
	ldrb r0, [r0]
	bl CancelMultiTurnMoves
	ldr r1, _08053550
	ldr r0, _08053554
	str r0, [r1]
	b _08053670
	.align 2, 0
_08053548: .4byte 0x02023F20
_0805354C: .4byte 0x02023EAF
_08053550: .4byte 0x02023EB8
_08053554: .4byte 0x08286FE8
_08053558:
	ldr r2, _0805367C
	ldr r1, _08053680
	ldrb r3, [r1]
	movs r5, #0x58
	adds r0, r3, #0
	muls r0, r5, r0
	adds r4, r2, #0
	adds r4, #0x50
	adds r0, r0, r4
	ldr r0, [r0]
	movs r7, #0x80
	lsls r7, r7, #5
	ands r0, r7
	adds r6, r1, #0
	mov sb, r2
	ldr r1, _08053684
	mov ip, r1
	ldr r2, _08053688
	mov r8, r2
	cmp r0, #0
	bne _080535CA
	lsls r0, r3, #3
	subs r0, r0, r3
	lsls r0, r0, #2
	add r0, ip
	ldrb r2, [r0, #0x11]
	movs r1, #0x10
	rsbs r1, r1, #0
	ands r1, r2
	movs r2, #5
	orrs r1, r2
	strb r1, [r0, #0x11]
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	ldrb r2, [r0, #0x11]
	movs r1, #0xf
	ands r1, r2
	movs r2, #0x50
	orrs r1, r2
	strb r1, [r0, #0x11]
	ldrb r0, [r6]
	adds r1, r0, #0
	muls r1, r5, r1
	adds r1, r1, r4
	ldr r0, [r1]
	orrs r0, r7
	str r0, [r1]
	ldr r1, _0805368C
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r1
	mov r2, r8
	ldrh r1, [r2]
	strh r1, [r0]
_080535CA:
	ldrb r0, [r6]
	lsls r2, r0, #3
	subs r2, r2, r0
	lsls r2, r2, #2
	add r2, ip
	ldrb r3, [r2, #0x11]
	lsls r1, r3, #0x1c
	lsrs r1, r1, #0x1c
	subs r1, #1
	movs r0, #0xf
	ands r1, r0
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, #0x11]
	cmp r1, #0
	bne _080535FE
	ldrb r0, [r6]
	adds r1, r0, #0
	muls r1, r5, r1
	adds r1, r1, r4
	ldr r0, [r1]
	ldr r2, _08053690
	ands r0, r2
	str r0, [r1]
_080535FE:
	ldr r3, _08053694
	ldr r2, _08053698
	mov r0, r8
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	strh r0, [r3]
	movs r2, #1
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	mov r1, ip
	adds r4, r0, r1
	ldrb r0, [r4, #0x11]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	movs r1, #5
	subs r1, r1, r0
	ldr r7, _0805369C
	adds r5, r3, #0
	cmp r2, r1
	bge _0805364C
	adds r1, r5, #0
	adds r3, r4, #0
	movs r4, #5
_08053638:
	ldrh r0, [r1]
	lsls r0, r0, #1
	strh r0, [r1]
	adds r2, #1
	ldrb r0, [r3, #0x11]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	subs r0, r4, r0
	cmp r2, r0
	blt _08053638
_0805364C:
	ldrb r1, [r6]
	movs r0, #0x58
	muls r0, r1, r0
	mov r1, sb
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x17
	ands r0, r1
	cmp r0, #0
	beq _0805366A
	ldrh r0, [r5]
	lsls r0, r0, #1
	strh r0, [r5]
_0805366A:
	ldr r0, [r7]
	adds r0, #1
	str r0, [r7]
_08053670:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805367C: .4byte 0x02023D28
_08053680: .4byte 0x02023EAF
_08053684: .4byte 0x02023F60
_08053688: .4byte 0x02023E8E
_0805368C: .4byte 0x02023F0C
_08053690: .4byte 0xFFFFEFFF
_08053694: .4byte 0x020240A4
_08053698: .4byte 0x082ED220
_0805369C: .4byte 0x02023EB8
	thumb_func_end atkB3_rolloutdamagecalculation

	thumb_func_start atkB4_jumpifconfusedandstatmaxed
atkB4_jumpifconfusedandstatmaxed: @ 0x080536A0
	push {r4, r5, lr}
	ldr r5, _080536F0
	ldr r0, _080536F4
	ldrb r1, [r0]
	movs r0, #0x58
	adds r3, r1, #0
	muls r3, r0, r3
	adds r0, r5, #0
	adds r0, #0x50
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	ldr r4, _080536F8
	cmp r0, #0
	beq _080536FC
	ldr r2, [r4]
	ldrb r0, [r2, #1]
	adds r0, r0, r3
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	bne _080536FC
	ldrb r1, [r2, #2]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #5]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r4]
	b _08053702
	.align 2, 0
_080536F0: .4byte 0x02023D28
_080536F4: .4byte 0x02023EB0
_080536F8: .4byte 0x02023EB8
_080536FC:
	ldr r0, [r4]
	adds r0, #6
	str r0, [r4]
_08053702:
	pop {r4, r5}
	pop {r0}
	bx r0
	thumb_func_end atkB4_jumpifconfusedandstatmaxed

	thumb_func_start atkB5_furycuttercalc
atkB5_furycuttercalc: @ 0x08053708
	push {r4, r5, lr}
	ldr r0, _08053730
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _08053744
	ldr r2, _08053734
	ldr r0, _08053738
	ldrb r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	movs r1, #0
	strb r1, [r0, #0x10]
	ldr r1, _0805373C
	ldr r0, _08053740
	str r0, [r1]
	b _0805379C
	.align 2, 0
_08053730: .4byte 0x02023F20
_08053734: .4byte 0x02023F60
_08053738: .4byte 0x02023EAF
_0805373C: .4byte 0x02023EB8
_08053740: .4byte 0x08286FE8
_08053744:
	ldr r5, _080537A4
	ldr r4, _080537A8
	ldrb r1, [r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r1, r0, r5
	ldrb r0, [r1, #0x10]
	cmp r0, #5
	beq _0805375C
	adds r0, #1
	strb r0, [r1, #0x10]
_0805375C:
	ldr r3, _080537AC
	ldr r2, _080537B0
	ldr r0, _080537B4
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	strh r0, [r3]
	movs r2, #1
	ldrb r1, [r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldr r4, _080537B8
	ldrb r1, [r0, #0x10]
	cmp r2, r1
	bge _08053796
	adds r1, r3, #0
	adds r3, r0, #0
_08053788:
	ldrh r0, [r1]
	lsls r0, r0, #1
	strh r0, [r1]
	adds r2, #1
	ldrb r0, [r3, #0x10]
	cmp r2, r0
	blt _08053788
_08053796:
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
_0805379C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080537A4: .4byte 0x02023F60
_080537A8: .4byte 0x02023EAF
_080537AC: .4byte 0x020240A4
_080537B0: .4byte 0x082ED220
_080537B4: .4byte 0x02023E8E
_080537B8: .4byte 0x02023EB8
	thumb_func_end atkB5_furycuttercalc

	thumb_func_start atkB6_happinesstodamagecalculation
atkB6_happinesstodamagecalculation: @ 0x080537BC
	push {r4, lr}
	ldr r2, _080537E8
	ldr r0, _080537EC
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x79
	bne _080537FC
	ldr r4, _080537F0
	ldr r2, _080537F4
	ldr r0, _080537F8
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0x2b
	ldrb r1, [r0]
	b _08053812
	.align 2, 0
_080537E8: .4byte 0x082ED220
_080537EC: .4byte 0x02023E8E
_080537F0: .4byte 0x020240A4
_080537F4: .4byte 0x02023D28
_080537F8: .4byte 0x02023EAF
_080537FC:
	ldr r4, _08053830
	ldr r2, _08053834
	ldr r0, _08053838
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0x2b
	ldrb r0, [r0]
	movs r1, #0xff
	subs r1, r1, r0
_08053812:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0x19
	bl __divsi3
	strh r0, [r4]
	ldr r1, _0805383C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053830: .4byte 0x020240A4
_08053834: .4byte 0x02023D28
_08053838: .4byte 0x02023EAF
_0805383C: .4byte 0x02023EB8
	thumb_func_end atkB6_happinesstodamagecalculation

	thumb_func_start atkB7_presentdamagecalculation
atkB7_presentdamagecalculation: @ 0x08053840
	push {r4, lr}
	bl Random
	movs r4, #0xff
	ands r4, r0
	cmp r4, #0x65
	bgt _0805385C
	ldr r1, _08053858
	movs r0, #0x28
	strh r0, [r1]
	b _0805389E
	.align 2, 0
_08053858: .4byte 0x020240A4
_0805385C:
	cmp r4, #0xb1
	bgt _0805386C
	ldr r1, _08053868
	movs r0, #0x50
	strh r0, [r1]
	b _0805389E
	.align 2, 0
_08053868: .4byte 0x020240A4
_0805386C:
	cmp r4, #0xcb
	bgt _0805387C
	ldr r1, _08053878
	movs r0, #0x78
	strh r0, [r1]
	b _0805389E
	.align 2, 0
_08053878: .4byte 0x020240A4
_0805387C:
	ldr r3, _080538A8
	ldr r2, _080538AC
	ldr r0, _080538B0
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r0, [r0, #0x2c]
	lsrs r0, r0, #2
	str r0, [r3]
	cmp r0, #0
	bne _08053898
	movs r0, #1
	str r0, [r3]
_08053898:
	ldr r0, [r3]
	rsbs r0, r0, #0
	str r0, [r3]
_0805389E:
	cmp r4, #0xcb
	bgt _080538BC
	ldr r1, _080538B4
	ldr r0, _080538B8
	b _080538F6
	.align 2, 0
_080538A8: .4byte 0x02023E94
_080538AC: .4byte 0x02023D28
_080538B0: .4byte 0x02023EB0
_080538B4: .4byte 0x02023EB8
_080538B8: .4byte 0x08286FB8
_080538BC:
	ldr r2, _080538D8
	ldr r0, _080538DC
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r1, [r0, #0x2c]
	ldrh r0, [r0, #0x28]
	cmp r1, r0
	bne _080538E8
	ldr r1, _080538E0
	ldr r0, _080538E4
	b _080538F6
	.align 2, 0
_080538D8: .4byte 0x02023D28
_080538DC: .4byte 0x02023EB0
_080538E0: .4byte 0x02023EB8
_080538E4: .4byte 0x08288483
_080538E8:
	ldr r2, _08053900
	ldrb r1, [r2]
	movs r0, #0xf7
	ands r0, r1
	strb r0, [r2]
	ldr r1, _08053904
	ldr r0, _08053908
_080538F6:
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08053900: .4byte 0x02023F20
_08053904: .4byte 0x02023EB8
_08053908: .4byte 0x08288469
	thumb_func_end atkB7_presentdamagecalculation

	thumb_func_start atkB8_setsafeguard
atkB8_setsafeguard: @ 0x0805390C
	push {r4, r5, r6, r7, lr}
	ldr r7, _08053940
	ldrb r0, [r7]
	bl GetBattlerPosition
	ldr r4, _08053944
	movs r6, #1
	adds r1, r6, #0
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r1, [r1]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08053950
	ldr r2, _08053948
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _0805394C
	movs r0, #0
	strb r0, [r1, #5]
	b _08053998
	.align 2, 0
_08053940: .4byte 0x02023EAF
_08053944: .4byte 0x02023F32
_08053948: .4byte 0x02023F20
_0805394C: .4byte 0x02023FD6
_08053950:
	ldrb r0, [r7]
	bl GetBattlerPosition
	adds r1, r6, #0
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	movs r2, #0x20
	orrs r0, r2
	strh r0, [r1]
	ldrb r0, [r7]
	bl GetBattlerPosition
	ldr r5, _080539A8
	adds r1, r6, #0
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	movs r4, #5
	strb r4, [r0, #6]
	ldrb r0, [r7]
	bl GetBattlerPosition
	adds r1, r6, #0
	ands r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r5
	ldrb r1, [r7]
	strb r1, [r0, #7]
	ldr r0, _080539AC
	strb r4, [r0, #5]
_08053998:
	ldr r1, _080539B0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080539A8: .4byte 0x02023F38
_080539AC: .4byte 0x02023FD6
_080539B0: .4byte 0x02023EB8
	thumb_func_end atkB8_setsafeguard

	thumb_func_start atkB9_magnitudedamagecalculation
atkB9_magnitudedamagecalculation: @ 0x080539B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #4
	bgt _080539E0
	ldr r1, _080539DC
	movs r0, #0xa
	strh r0, [r1]
	movs r3, #4
	b _08053A4C
	.align 2, 0
_080539DC: .4byte 0x020240A4
_080539E0:
	cmp r3, #0xe
	bgt _080539F4
	ldr r1, _080539F0
	movs r0, #0x1e
	strh r0, [r1]
	movs r3, #5
	b _08053A4C
	.align 2, 0
_080539F0: .4byte 0x020240A4
_080539F4:
	cmp r3, #0x22
	bgt _08053A08
	ldr r1, _08053A04
	movs r0, #0x32
	strh r0, [r1]
	movs r3, #6
	b _08053A4C
	.align 2, 0
_08053A04: .4byte 0x020240A4
_08053A08:
	cmp r3, #0x40
	bgt _08053A1C
	ldr r1, _08053A18
	movs r0, #0x46
	strh r0, [r1]
	movs r3, #7
	b _08053A4C
	.align 2, 0
_08053A18: .4byte 0x020240A4
_08053A1C:
	cmp r3, #0x54
	bgt _08053A30
	ldr r1, _08053A2C
	movs r0, #0x5a
	strh r0, [r1]
	movs r3, #8
	b _08053A4C
	.align 2, 0
_08053A2C: .4byte 0x020240A4
_08053A30:
	cmp r3, #0x5e
	bgt _08053A44
	ldr r1, _08053A40
	movs r0, #0x6e
	strh r0, [r1]
	movs r3, #9
	b _08053A4C
	.align 2, 0
_08053A40: .4byte 0x020240A4
_08053A44:
	ldr r1, _08053AB8
	movs r0, #0x96
	strh r0, [r1]
	movs r3, #0xa
_08053A4C:
	ldr r1, _08053ABC
	movs r2, #0
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #1
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	movs r0, #2
	strb r0, [r1, #3]
	strb r3, [r1, #4]
	movs r0, #0xff
	strb r0, [r1, #5]
	ldr r1, _08053AC0
	strb r2, [r1]
	ldr r0, _08053AC4
	ldrb r3, [r0]
	adds r6, r1, #0
	ldr r0, _08053AC8
	mov r8, r0
	cmp r2, r3
	bhs _08053AA4
	adds r4, r6, #0
	ldr r0, _08053ACC
	ldrb r5, [r0]
	ldr r1, _08053AD0
	mov ip, r1
	ldr r7, _08053AD4
_08053A82:
	ldrb r2, [r4]
	cmp r2, r5
	beq _08053A98
	ldrb r0, [r7]
	ldrb r1, [r6]
	lsls r1, r1, #2
	add r1, ip
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _08053AA4
_08053A98:
	adds r0, r2, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r3
	blo _08053A82
_08053AA4:
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053AB8: .4byte 0x020240A4
_08053ABC: .4byte 0x02022C0C
_08053AC0: .4byte 0x02023EB0
_08053AC4: .4byte 0x02023D10
_08053AC8: .4byte 0x02023EB8
_08053ACC: .4byte 0x02023EAF
_08053AD0: .4byte 0x082FACB4
_08053AD4: .4byte 0x02023EB4
	thumb_func_end atkB9_magnitudedamagecalculation

	thumb_func_start atkBA_jumpifnopursuitswitchdmg
atkBA_jumpifnopursuitswitchdmg: @ 0x08053AD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08053AFC
	ldrb r0, [r0]
	cmp r0, #1
	bne _08053B08
	ldr r0, _08053B00
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08053B04
	movs r0, #1
	b _08053B22
	.align 2, 0
_08053AFC: .4byte 0x02023EB6
_08053B00: .4byte 0x02023EAF
_08053B04:
	movs r0, #0
	b _08053B22
_08053B08:
	ldr r0, _08053B1C
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08053B20
	movs r0, #3
	b _08053B22
	.align 2, 0
_08053B1C: .4byte 0x02023EAF
_08053B20:
	movs r0, #2
_08053B22:
	bl GetBattlerAtPosition
	ldr r1, _08053BFC
	strb r0, [r1]
	ldr r0, _08053C00
	ldr r1, _08053BFC
	ldrb r3, [r1]
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _08053B3A
	b _08053C40
_08053B3A:
	ldr r5, _08053C04
	ldr r0, _08053C08
	ldr r1, [r0]
	adds r1, r3, r1
	ldrb r2, [r5]
	ldrb r1, [r1, #0xc]
	cmp r2, r1
	bne _08053C40
	ldr r4, _08053C0C
	movs r2, #0x58
	adds r0, r3, #0
	muls r0, r2, r0
	adds r1, r4, #0
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x27
	ands r0, r1
	cmp r0, #0
	bne _08053C40
	ldrb r0, [r5]
	muls r0, r2, r0
	adds r0, r0, r4
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _08053C40
	ldr r0, _08053C10
	lsls r1, r3, #3
	subs r1, r1, r3
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1, #0x18]
	lsls r0, r0, #0x1f
	cmp r0, #0
	bne _08053C40
	ldr r0, _08053C14
	lsls r1, r3, #1
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0xe4
	bne _08053C40
	movs r1, #0
	ldr r0, _08053C18
	ldr r2, _08053C1C
	mov r8, r2
	ldr r7, _08053C20
	mov sl, r7
	ldr r2, _08053C24
	mov sb, r2
	ldr r7, _08053C28
	mov ip, r7
	ldrb r2, [r0]
	cmp r1, r2
	bge _08053BC6
	ldr r6, _08053C2C
	ldr r5, _08053BFC
	ldr r4, _08053C30
	movs r3, #0xb
	adds r2, r0, #0
_08053BB0:
	adds r0, r1, r6
	ldrb r0, [r0]
	ldrb r7, [r5]
	cmp r0, r7
	bne _08053BBE
	adds r0, r1, r4
	strb r3, [r0]
_08053BBE:
	adds r1, #1
	ldrb r0, [r2]
	cmp r1, r0
	blt _08053BB0
_08053BC6:
	movs r0, #0xe4
	mov r1, r8
	strh r0, [r1]
	ldr r2, _08053BFC
	ldrb r0, [r2]
	ldr r7, _08053C08
	ldr r1, [r7]
	adds r0, r0, r1
	adds r0, #0x80
	ldrb r0, [r0]
	mov r1, sb
	strb r0, [r1]
	mov r2, sl
	strb r0, [r2]
	ldr r7, _08053C34
	ldr r0, [r7]
	adds r0, #5
	str r0, [r7]
	movs r0, #1
	ldr r1, _08053C38
	strb r0, [r1, #0x18]
	mov r2, ip
	ldr r0, [r2]
	ldr r1, _08053C3C
	ands r0, r1
	str r0, [r2]
	b _08053C5A
	.align 2, 0
_08053BFC: .4byte 0x02023EB0
_08053C00: .4byte 0x02023EC0
_08053C04: .4byte 0x02023EAF
_08053C08: .4byte 0x02024140
_08053C0C: .4byte 0x02023D28
_08053C10: .4byte 0x02023F60
_08053C14: .4byte 0x02023F18
_08053C18: .4byte 0x02023D10
_08053C1C: .4byte 0x02023E8E
_08053C20: .4byte 0x02023E8C
_08053C24: .4byte 0x02023E8D
_08053C28: .4byte 0x02023F24
_08053C2C: .4byte 0x02023D22
_08053C30: .4byte 0x02023D1E
_08053C34: .4byte 0x02023EB8
_08053C38: .4byte 0x02024118
_08053C3C: .4byte 0xFFFFFBFF
_08053C40:
	ldr r3, _08053C68
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08053C5A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053C68: .4byte 0x02023EB8
	thumb_func_end atkBA_jumpifnopursuitswitchdmg

	thumb_func_start atkBB_setsunny
atkBB_setsunny: @ 0x08053C6C
	push {lr}
	ldr r2, _08053C8C
	ldrh r1, [r2]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	beq _08053C98
	ldr r2, _08053C90
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08053C94
	movs r0, #2
	strb r0, [r1, #5]
	b _08053CAA
	.align 2, 0
_08053C8C: .4byte 0x02024070
_08053C90: .4byte 0x02023F20
_08053C94: .4byte 0x02023FD6
_08053C98:
	movs r0, #0x20
	strh r0, [r2]
	ldr r1, _08053CB8
	movs r0, #4
	strb r0, [r1, #5]
	ldr r0, _08053CBC
	adds r0, #0x28
	movs r1, #5
	strb r1, [r0]
_08053CAA:
	ldr r1, _08053CC0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08053CB8: .4byte 0x02023FD6
_08053CBC: .4byte 0x02024074
_08053CC0: .4byte 0x02023EB8
	thumb_func_end atkBB_setsunny

	thumb_func_start atkBC_maxattackhalvehp
atkBC_maxattackhalvehp: @ 0x08053CC4
	push {r4, r5, lr}
	ldr r5, _08053D10
	ldr r4, _08053D14
	ldrb r0, [r4]
	movs r3, #0x58
	muls r0, r3, r0
	adds r2, r0, r5
	ldrh r0, [r2, #0x2c]
	lsrs r1, r0, #1
	cmp r1, #0
	bne _08053CDC
	movs r1, #1
_08053CDC:
	movs r0, #0x19
	ldrsb r0, [r2, r0]
	cmp r0, #0xb
	bgt _08053D20
	ldrh r0, [r2, #0x28]
	cmp r0, r1
	bls _08053D20
	movs r0, #0xc
	strb r0, [r2, #0x19]
	ldr r1, _08053D18
	ldrb r0, [r4]
	muls r0, r3, r0
	adds r0, r0, r5
	ldrh r0, [r0, #0x2c]
	lsrs r0, r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _08053D04
	movs r0, #1
	str r0, [r1]
_08053D04:
	ldr r1, _08053D1C
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08053D3A
	.align 2, 0
_08053D10: .4byte 0x02023D28
_08053D14: .4byte 0x02023EAF
_08053D18: .4byte 0x02023E94
_08053D1C: .4byte 0x02023EB8
_08053D20:
	ldr r3, _08053D40
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08053D3A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08053D40: .4byte 0x02023EB8
	thumb_func_end atkBC_maxattackhalvehp

	thumb_func_start atkBD_copyfoestats
atkBD_copyfoestats: @ 0x08053D44
	push {r4, r5, r6, r7, lr}
	movs r2, #0
	ldr r7, _08053D7C
	ldr r6, _08053D80
	movs r4, #0x58
	ldr r3, _08053D84
	ldr r5, _08053D88
_08053D52:
	ldrb r0, [r6]
	adds r1, r0, #0
	muls r1, r4, r1
	adds r1, r2, r1
	adds r1, r1, r3
	ldrb r0, [r5]
	muls r0, r4, r0
	adds r0, r2, r0
	adds r0, r0, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, #1
	cmp r2, #7
	ble _08053D52
	ldr r0, [r7]
	adds r0, #5
	str r0, [r7]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08053D7C: .4byte 0x02023EB8
_08053D80: .4byte 0x02023EAF
_08053D84: .4byte 0x02023D40
_08053D88: .4byte 0x02023EB0
	thumb_func_end atkBD_copyfoestats

	thumb_func_start atkBE_rapidspinfree
atkBE_rapidspinfree: @ 0x08053D8C
	push {r4, r5, r6, lr}
	ldr r1, _08053DFC
	ldr r5, _08053E00
	ldrb r2, [r5]
	movs r6, #0x58
	adds r0, r2, #0
	muls r0, r6, r0
	adds r4, r1, #0
	adds r4, #0x50
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0xe0
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _08053E20
	ldr r1, _08053E04
	ldr r3, _08053E08
	ldrb r0, [r3]
	strb r0, [r1, #0x17]
	ldrb r0, [r5]
	adds r1, r0, #0
	muls r1, r6, r1
	adds r1, r1, r4
	ldr r0, [r1]
	ldr r2, _08053E0C
	ands r0, r2
	str r0, [r1]
	ldrb r0, [r5]
	ldr r1, _08053E10
	ldr r2, [r1]
	adds r0, r0, r2
	ldrb r0, [r0, #0x14]
	strb r0, [r3]
	ldr r1, _08053E14
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #2
	strb r0, [r1, #1]
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0, #4]
	strb r0, [r1, #2]
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrb r0, [r0, #5]
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	bl BattleScriptPushCursor
	ldr r1, _08053E18
	ldr r0, _08053E1C
	b _08053ECA
	.align 2, 0
_08053DFC: .4byte 0x02023D28
_08053E00: .4byte 0x02023EAF
_08053E04: .4byte 0x02024118
_08053E08: .4byte 0x02023EB0
_08053E0C: .4byte 0xFFFF1FFF
_08053E10: .4byte 0x02024140
_08053E14: .4byte 0x02022C0C
_08053E18: .4byte 0x02023EB8
_08053E1C: .4byte 0x0828954D
_08053E20:
	ldr r4, _08053E54
	lsls r0, r2, #2
	adds r3, r0, r4
	ldr r1, [r3]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08053E60
	movs r0, #5
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r3]
	ldrb r1, [r5]
	lsls r1, r1, #2
	adds r1, r1, r4
	ldr r0, [r1]
	movs r2, #4
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	bl BattleScriptPushCursor
	ldr r1, _08053E58
	ldr r0, _08053E5C
	b _08053ECA
	.align 2, 0
_08053E54: .4byte 0x02023F50
_08053E58: .4byte 0x02023EB8
_08053E5C: .4byte 0x0828955E
_08053E60:
	adds r0, r2, #0
	bl GetBattlerSide
	ldr r4, _08053EB0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08053EC4
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, r0, r4
	ldrh r2, [r0]
	ldr r1, _08053EB4
	ands r1, r2
	movs r4, #0
	strh r1, [r0]
	ldrb r0, [r5]
	bl GetBattlerSide
	ldr r2, _08053EB8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	strb r4, [r1, #0xa]
	bl BattleScriptPushCursor
	ldr r1, _08053EBC
	ldr r0, _08053EC0
	b _08053ECA
	.align 2, 0
_08053EB0: .4byte 0x02023F32
_08053EB4: .4byte 0x0000FFEF
_08053EB8: .4byte 0x02023F38
_08053EBC: .4byte 0x02023EB8
_08053EC0: .4byte 0x08289565
_08053EC4:
	ldr r1, _08053ED4
	ldr r0, [r1]
	adds r0, #1
_08053ECA:
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08053ED4: .4byte 0x02023EB8
	thumb_func_end atkBE_rapidspinfree

	thumb_func_start atkBF_setdefensecurlbit
atkBF_setdefensecurlbit: @ 0x08053ED8
	ldr r1, _08053EFC
	ldr r0, _08053F00
	ldrb r2, [r0]
	movs r0, #0x58
	muls r2, r0, r2
	adds r1, #0x50
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x17
	orrs r0, r1
	str r0, [r2]
	ldr r1, _08053F04
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_08053EFC: .4byte 0x02023D28
_08053F00: .4byte 0x02023EAF
_08053F04: .4byte 0x02023EB8
	thumb_func_end atkBF_setdefensecurlbit

	thumb_func_start atkC0_recoverbasedonsunlight
atkC0_recoverbasedonsunlight: @ 0x08053F08
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r1, _08053F74
	ldr r5, _08053F78
	ldrb r0, [r5]
	strb r0, [r1]
	ldr r7, _08053F7C
	ldrb r0, [r5]
	movs r6, #0x58
	muls r0, r6, r0
	adds r0, r0, r7
	ldrh r1, [r0, #0x28]
	ldrh r0, [r0, #0x2c]
	cmp r1, r0
	beq _08053FE8
	ldr r4, _08053F80
	ldrh r0, [r4]
	cmp r0, #0
	beq _08053F5A
	movs r0, #0
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08053F5A
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0x4d
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08053F88
_08053F5A:
	ldr r3, _08053F84
	ldr r2, _08053F7C
	ldr r0, _08053F78
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r0, [r0, #0x2c]
	lsrs r0, r0, #1
	str r0, [r3]
	adds r1, r3, #0
	b _08053FC2
	.align 2, 0
_08053F74: .4byte 0x02023EB0
_08053F78: .4byte 0x02023EAF
_08053F7C: .4byte 0x02023D28
_08053F80: .4byte 0x02024070
_08053F84: .4byte 0x02023E94
_08053F88:
	ldrh r1, [r4]
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	beq _08053FB4
	ldr r4, _08053FB0
	ldrb r0, [r5]
	muls r0, r6, r0
	adds r0, r0, r7
	ldrh r1, [r0, #0x2c]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x1e
	bl __divsi3
	str r0, [r4]
	adds r1, r4, #0
	b _08053FC2
	.align 2, 0
_08053FB0: .4byte 0x02023E94
_08053FB4:
	ldr r1, _08053FE0
	ldrb r0, [r5]
	muls r0, r6, r0
	adds r0, r0, r7
	ldrh r0, [r0, #0x2c]
	lsrs r0, r0, #2
	str r0, [r1]
_08053FC2:
	adds r2, r1, #0
	ldr r0, [r2]
	cmp r0, #0
	bne _08053FCE
	movs r0, #1
	str r0, [r2]
_08053FCE:
	ldr r0, [r1]
	rsbs r0, r0, #0
	str r0, [r1]
	ldr r1, _08053FE4
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08054002
	.align 2, 0
_08053FE0: .4byte 0x02023E94
_08053FE4: .4byte 0x02023EB8
_08053FE8:
	ldr r3, _0805400C
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08054002:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805400C: .4byte 0x02023EB8
	thumb_func_end atkC0_recoverbasedonsunlight

	thumb_func_start atkC1_hiddenpowercalc
atkC1_hiddenpowercalc: @ 0x08054010
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r2, _08054120
	ldr r0, _08054124
	ldrb r1, [r0]
	movs r0, #0x58
	adds r4, r1, #0
	muls r4, r0, r4
	adds r4, r4, r2
	ldrb r0, [r4, #0x14]
	mov sl, r0
	mov r7, sl
	lsls r7, r7, #0x1b
	adds r0, r7, #0
	lsrs r0, r0, #0x1b
	mov sl, r0
	movs r1, #2
	mov r2, sl
	ands r2, r1
	asrs r2, r2, #1
	ldrh r7, [r4, #0x14]
	mov sb, r7
	mov r0, sb
	lsls r0, r0, #0x16
	mov sb, r0
	lsrs r3, r0, #0x1b
	adds r0, r1, #0
	ands r0, r3
	orrs r2, r0
	ldrb r7, [r4, #0x15]
	mov r8, r7
	mov r0, r8
	lsls r0, r0, #0x19
	mov r8, r0
	lsrs r3, r0, #0x1b
	adds r0, r1, #0
	ands r0, r3
	lsls r0, r0, #1
	orrs r2, r0
	ldr r6, [r4, #0x14]
	lsls r6, r6, #0xc
	lsrs r3, r6, #0x1b
	adds r0, r1, #0
	ands r0, r3
	lsls r0, r0, #2
	orrs r2, r0
	ldrh r5, [r4, #0x16]
	lsls r5, r5, #0x17
	lsrs r3, r5, #0x1b
	adds r0, r1, #0
	ands r0, r3
	lsls r0, r0, #3
	orrs r2, r0
	ldrb r3, [r4, #0x17]
	lsls r3, r3, #0x1a
	lsrs r0, r3, #0x1b
	ands r1, r0
	lsls r1, r1, #4
	orrs r2, r1
	movs r1, #1
	adds r4, r1, #0
	mov r7, sl
	ands r4, r7
	mov r0, sb
	lsrs r0, r0, #0x1b
	mov sb, r0
	adds r0, r1, #0
	mov r7, sb
	ands r0, r7
	lsls r0, r0, #1
	orrs r4, r0
	mov r0, r8
	lsrs r0, r0, #0x1b
	mov r8, r0
	adds r0, r1, #0
	mov r7, r8
	ands r0, r7
	lsls r0, r0, #2
	orrs r4, r0
	lsrs r6, r6, #0x1b
	adds r0, r1, #0
	ands r0, r6
	lsls r0, r0, #3
	orrs r4, r0
	lsrs r5, r5, #0x1b
	adds r0, r1, #0
	ands r0, r5
	lsls r0, r0, #4
	orrs r4, r0
	lsrs r3, r3, #0x1b
	ands r1, r3
	lsls r1, r1, #5
	orrs r4, r1
	ldr r5, _08054128
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #3
	movs r1, #0x3f
	bl __divsi3
	adds r0, #0x1e
	strh r0, [r5]
	ldr r6, _0805412C
	ldr r5, [r6]
	lsls r0, r4, #4
	subs r0, r0, r4
	movs r1, #0x3f
	bl __divsi3
	adds r0, #1
	strb r0, [r5, #0x13]
	ldr r1, [r6]
	ldrb r0, [r1, #0x13]
	cmp r0, #8
	bls _08054100
	adds r0, #1
	strb r0, [r1, #0x13]
_08054100:
	ldr r2, [r6]
	ldrb r0, [r2, #0x13]
	movs r1, #0xc0
	orrs r0, r1
	strb r0, [r2, #0x13]
	ldr r1, _08054130
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08054120: .4byte 0x02023D28
_08054124: .4byte 0x02023EAF
_08054128: .4byte 0x020240A4
_0805412C: .4byte 0x02024140
_08054130: .4byte 0x02023EB8
	thumb_func_end atkC1_hiddenpowercalc

	thumb_func_start atkC2_selectfirstvalidtarget
atkC2_selectfirstvalidtarget: @ 0x08054134
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08054190
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08054194
	ldrb r1, [r1]
	adds r6, r0, #0
	ldr r0, _08054198
	mov r8, r0
	cmp r1, #0
	beq _0805417E
	adds r3, r6, #0
	ldr r0, _0805419C
	ldrb r5, [r0]
	ldr r0, _080541A0
	mov ip, r0
	adds r4, r1, #0
	ldr r7, _080541A4
_0805415C:
	ldrb r2, [r3]
	cmp r2, r5
	beq _08054172
	ldrb r0, [r7]
	ldrb r1, [r6]
	lsls r1, r1, #2
	add r1, ip
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	beq _0805417E
_08054172:
	adds r0, r2, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r4
	blo _0805415C
_0805417E:
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08054190: .4byte 0x02023EB0
_08054194: .4byte 0x02023D10
_08054198: .4byte 0x02023EB8
_0805419C: .4byte 0x02023EAF
_080541A0: .4byte 0x082FACB4
_080541A4: .4byte 0x02023EB4
	thumb_func_end atkC2_selectfirstvalidtarget

	thumb_func_start atkC3_trysetfutureattack
atkC3_trysetfutureattack: @ 0x080541A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	ldr r0, _080541E0
	mov r8, r0
	ldr r6, _080541E4
	ldrb r1, [r6]
	adds r0, r1, r0
	ldrb r7, [r0]
	cmp r7, #0
	beq _080541EC
	ldr r3, _080541E8
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _080542DC
	.align 2, 0
_080541E0: .4byte 0x02024074
_080541E4: .4byte 0x02023EB0
_080541E8: .4byte 0x02023EB8
_080541EC:
	adds r0, r1, #0
	bl GetBattlerPosition
	ldr r4, _080542B0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	mov sl, r1
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r2, [r0]
	movs r1, #0x40
	movs r5, #0
	mov r3, sp
	strh r5, [r3, #0x10]
	orrs r1, r2
	strh r1, [r0]
	ldrb r0, [r6]
	lsls r0, r0, #1
	mov r1, r8
	adds r1, #0x18
	adds r0, r0, r1
	ldr r1, _080542B4
	mov sb, r1
	ldrh r1, [r1]
	strh r1, [r0]
	mov r0, r8
	adds r0, #4
	ldrb r2, [r6]
	adds r0, r0, r2
	ldr r5, _080542B8
	ldrb r1, [r5]
	strb r1, [r0]
	ldrb r0, [r6]
	add r0, r8
	movs r1, #3
	strb r1, [r0]
	ldrb r0, [r6]
	bl GetBattlerPosition
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r3, [r1]
	ldrb r0, [r5]
	movs r4, #0x58
	muls r0, r4, r0
	ldr r2, _080542BC
	adds r0, r0, r2
	ldrb r1, [r6]
	muls r1, r4, r1
	adds r1, r1, r2
	mov r4, sb
	ldrh r2, [r4]
	str r7, [sp]
	str r7, [sp, #4]
	ldrb r4, [r5]
	str r4, [sp, #8]
	ldrb r4, [r6]
	str r4, [sp, #0xc]
	bl CalculateBaseDamage
	ldrb r1, [r6]
	lsls r1, r1, #2
	mov r2, r8
	adds r2, #8
	adds r1, r1, r2
	str r0, [r1]
	ldr r1, _080542C0
	ldrb r0, [r5]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	cmp r0, #0
	bge _0805429C
	ldrb r4, [r6]
	lsls r4, r4, #2
	adds r4, r4, r2
	ldr r1, [r4]
	lsls r0, r1, #4
	subs r0, r0, r1
	movs r1, #0xa
	bl __divsi3
	str r0, [r4]
_0805429C:
	mov r5, sb
	ldrh r1, [r5]
	ldr r0, _080542C4
	cmp r1, r0
	bne _080542CC
	ldr r0, _080542C8
	mov r1, sl
	strb r1, [r0, #5]
	b _080542D4
	.align 2, 0
_080542B0: .4byte 0x02023F32
_080542B4: .4byte 0x02023E8E
_080542B8: .4byte 0x02023EAF
_080542BC: .4byte 0x02023D28
_080542C0: .4byte 0x02023FE0
_080542C4: .4byte 0x00000161
_080542C8: .4byte 0x02023FD6
_080542CC:
	ldr r0, _080542EC
	mov r2, sp
	ldrb r2, [r2, #0x10]
	strb r2, [r0, #5]
_080542D4:
	ldr r1, _080542F0
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_080542DC:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080542EC: .4byte 0x02023FD6
_080542F0: .4byte 0x02023EB8
	thumb_func_end atkC3_trysetfutureattack

	thumb_func_start atkC4_trydobeatup
atkC4_trydobeatup: @ 0x080542F4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r0, _08054338
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	ldr r7, _0805433C
	cmp r0, #0
	bne _0805430E
	ldr r7, _08054340
_0805430E:
	ldr r2, _08054344
	ldr r0, _08054348
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _08054350
	ldr r3, _0805434C
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	b _080544EC
	.align 2, 0
_08054338: .4byte 0x02023EAF
_0805433C: .4byte 0x020243E8
_08054340: .4byte 0x02024190
_08054344: .4byte 0x02023D28
_08054348: .4byte 0x02023EB0
_0805434C: .4byte 0x02023EB8
_08054350:
	ldr r6, _0805448C
	ldrb r0, [r6]
	mov r8, r0
	cmp r0, #5
	bls _0805435C
	b _080544B8
_0805435C:
	adds r4, r6, #0
	movs r5, #0x64
_08054360:
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r7, r0
	movs r1, #0x39
	bl GetMonData3
	cmp r0, #0
	beq _080543A4
	ldrb r0, [r6]
	muls r0, r5, r0
	adds r0, r7, r0
	movs r1, #0x41
	bl GetMonData3
	cmp r0, #0
	beq _080543A4
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r7, r0
	movs r1, #0x41
	bl GetMonData3
	movs r1, #0xce
	lsls r1, r1, #1
	cmp r0, r1
	beq _080543A4
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r7, r0
	movs r1, #0x37
	bl GetMonData3
	cmp r0, #0
	beq _080543B4
_080543A4:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r6, r4, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _08054360
_080543B4:
	ldr r1, _0805448C
	mov sb, r1
	ldrb r2, [r1]
	cmp r2, #5
	bhi _080544B8
	ldr r1, _08054490
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #4
	strb r0, [r1, #1]
	ldr r6, _08054494
	ldrb r0, [r6]
	strb r0, [r1, #2]
	strb r2, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _08054498
	ldr r0, [r1]
	adds r0, #9
	str r0, [r1]
	ldr r2, _0805449C
	mov r8, r2
	ldr r5, _080544A0
	mov r1, sb
	ldrb r0, [r1]
	movs r4, #0x64
	muls r0, r4, r0
	adds r0, r7, r0
	movs r1, #0xb
	bl GetMonData3
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	ldrb r3, [r1, #1]
	mov r2, r8
	str r3, [r2]
	ldr r2, _080544A4
	ldr r0, _080544A8
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #1]
	muls r0, r3, r0
	mov r1, r8
	str r0, [r1]
	mov r2, sb
	ldrb r0, [r2]
	muls r0, r4, r0
	adds r0, r7, r0
	movs r1, #0x38
	bl GetMonData3
	lsls r0, r0, #1
	movs r1, #5
	bl __udivsi3
	adds r0, #2
	mov r2, r8
	ldr r1, [r2]
	muls r0, r1, r0
	str r0, [r2]
	ldr r3, _080544AC
	ldr r1, _080544B0
	ldrb r2, [r1]
	movs r1, #0x58
	muls r1, r2, r1
	adds r1, r1, r3
	ldrh r2, [r1]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r5
	ldrb r1, [r1, #2]
	bl __divsi3
	mov r1, r8
	str r0, [r1]
	movs r1, #0x32
	bl __divsi3
	adds r2, r0, #2
	mov r0, r8
	str r2, [r0]
	ldr r1, _080544B4
	ldrb r0, [r6]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	cmp r0, #0
	bge _08054480
	lsls r0, r2, #4
	subs r0, r0, r2
	movs r1, #0xa
	bl __divsi3
	mov r1, r8
	str r0, [r1]
_08054480:
	mov r2, sb
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	b _080544F2
	.align 2, 0
_0805448C: .4byte 0x02023FD6
_08054490: .4byte 0x02022C0C
_08054494: .4byte 0x02023EAF
_08054498: .4byte 0x02023EB8
_0805449C: .4byte 0x02023E94
_080544A0: .4byte 0x082F0D54
_080544A4: .4byte 0x082ED220
_080544A8: .4byte 0x02023E8E
_080544AC: .4byte 0x02023D28
_080544B0: .4byte 0x02023EB0
_080544B4: .4byte 0x02023FE0
_080544B8:
	mov r0, r8
	cmp r0, #0
	beq _080544D8
	ldr r3, _080544D4
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	b _080544EC
	.align 2, 0
_080544D4: .4byte 0x02023EB8
_080544D8:
	ldr r3, _08054500
	ldr r2, [r3]
	ldrb r1, [r2, #5]
	ldrb r0, [r2, #6]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #7]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #8]
_080544EC:
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_080544F2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08054500: .4byte 0x02023EB8
	thumb_func_end atkC4_trydobeatup

	thumb_func_start atkC5_setsemiinvulnerablebit
atkC5_setsemiinvulnerablebit: @ 0x08054504
	push {lr}
	ldr r0, _08054518
	ldrh r1, [r0]
	cmp r1, #0x5b
	beq _08054544
	cmp r1, #0x5b
	bgt _0805451C
	cmp r1, #0x13
	beq _08054528
	b _08054570
	.align 2, 0
_08054518: .4byte 0x02023E8E
_0805451C:
	ldr r0, _08054538
	cmp r1, r0
	beq _0805455C
	adds r0, #0x31
	cmp r1, r0
	bne _08054570
_08054528:
	ldr r2, _0805453C
	ldr r0, _08054540
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	movs r2, #0x40
	b _0805456C
	.align 2, 0
_08054538: .4byte 0x00000123
_0805453C: .4byte 0x02023F50
_08054540: .4byte 0x02023EAF
_08054544:
	ldr r2, _08054554
	ldr r0, _08054558
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	movs r2, #0x80
	b _0805456C
	.align 2, 0
_08054554: .4byte 0x02023F50
_08054558: .4byte 0x02023EAF
_0805455C:
	ldr r2, _0805457C
	ldr r0, _08054580
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0xb
_0805456C:
	orrs r0, r2
	str r0, [r1]
_08054570:
	ldr r1, _08054584
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0805457C: .4byte 0x02023F50
_08054580: .4byte 0x02023EAF
_08054584: .4byte 0x02023EB8
	thumb_func_end atkC5_setsemiinvulnerablebit

	thumb_func_start sub_08054588
sub_08054588: @ 0x08054588
	push {lr}
	ldr r0, _0805459C
	ldrh r1, [r0]
	cmp r1, #0x5b
	beq _080545CC
	cmp r1, #0x5b
	bgt _080545A0
	cmp r1, #0x13
	beq _080545AC
	b _080545FA
	.align 2, 0
_0805459C: .4byte 0x02023E8E
_080545A0:
	ldr r0, _080545C0
	cmp r1, r0
	beq _080545E8
	adds r0, #0x31
	cmp r1, r0
	bne _080545FA
_080545AC:
	ldr r2, _080545C4
	ldr r0, _080545C8
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	movs r2, #0x41
	rsbs r2, r2, #0
	b _080545F6
	.align 2, 0
_080545C0: .4byte 0x00000123
_080545C4: .4byte 0x02023F50
_080545C8: .4byte 0x02023EAF
_080545CC:
	ldr r2, _080545E0
	ldr r0, _080545E4
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	movs r2, #0x81
	rsbs r2, r2, #0
	b _080545F6
	.align 2, 0
_080545E0: .4byte 0x02023F50
_080545E4: .4byte 0x02023EAF
_080545E8:
	ldr r2, _08054608
	ldr r0, _0805460C
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	ldr r2, _08054610
_080545F6:
	ands r0, r2
	str r0, [r1]
_080545FA:
	ldr r1, _08054614
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08054608: .4byte 0x02023F50
_0805460C: .4byte 0x02023EAF
_08054610: .4byte 0xFFFBFFFF
_08054614: .4byte 0x02023EB8
	thumb_func_end sub_08054588

	thumb_func_start atkC7_setminimize
atkC7_setminimize: @ 0x08054618
	push {lr}
	ldr r0, _08054648
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x12
	ands r0, r1
	cmp r0, #0
	beq _0805463C
	ldr r2, _0805464C
	ldr r0, _08054650
	ldrb r1, [r0]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #1
	orrs r0, r2
	str r0, [r1]
_0805463C:
	ldr r1, _08054654
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08054648: .4byte 0x02023F24
_0805464C: .4byte 0x02023F50
_08054650: .4byte 0x02023EAF
_08054654: .4byte 0x02023EB8
	thumb_func_end atkC7_setminimize

	thumb_func_start atkC8_sethail
atkC8_sethail: @ 0x08054658
	push {lr}
	ldr r3, _0805467C
	ldrh r1, [r3]
	movs r2, #0x80
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08054688
	ldr r2, _08054680
	ldrb r0, [r2]
	movs r1, #1
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08054684
	movs r0, #2
	strb r0, [r1, #5]
	b _08054696
	.align 2, 0
_0805467C: .4byte 0x02024070
_08054680: .4byte 0x02023F20
_08054684: .4byte 0x02023FD6
_08054688:
	strh r2, [r3]
	ldr r0, _080546A4
	movs r1, #5
	strb r1, [r0, #5]
	ldr r0, _080546A8
	adds r0, #0x28
	strb r1, [r0]
_08054696:
	ldr r1, _080546AC
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080546A4: .4byte 0x02023FD6
_080546A8: .4byte 0x02024074
_080546AC: .4byte 0x02023EB8
	thumb_func_end atkC8_sethail

	thumb_func_start atkC9_jumpifattackandspecialattackcannotfall
atkC9_jumpifattackandspecialattackcannotfall: @ 0x080546B0
	push {r4, lr}
	ldr r2, _080546F4
	ldr r0, _080546F8
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r1, r0, r2
	movs r0, #0x19
	ldrsb r0, [r1, r0]
	adds r3, r2, #0
	cmp r0, #0
	bne _08054704
	movs r0, #0x1c
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bne _08054704
	ldr r0, _080546FC
	ldrb r0, [r0, #6]
	cmp r0, #1
	beq _08054704
	ldr r3, _08054700
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08054730
	.align 2, 0
_080546F4: .4byte 0x02023D28
_080546F8: .4byte 0x02023EB0
_080546FC: .4byte 0x02023FD6
_08054700: .4byte 0x02023EB8
_08054704:
	ldr r4, _08054738
	ldr r0, _0805473C
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r2, _08054740
	ldrb r1, [r4]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r3
	ldrh r0, [r0, #0x28]
	str r0, [r2]
	ldr r1, _08054744
	movs r0, #0
	bl BtlController_EmitHealthBarUpdate
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r1, _08054748
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08054730:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054738: .4byte 0x02023D08
_0805473C: .4byte 0x02023EAF
_08054740: .4byte 0x02023E94
_08054744: .4byte 0x00007FFF
_08054748: .4byte 0x02023EB8
	thumb_func_end atkC9_jumpifattackandspecialattackcannotfall

	thumb_func_start atkCA_setforcedtarget
atkCA_setforcedtarget: @ 0x0805474C
	push {r4, r5, lr}
	ldr r4, _0805478C
	ldrb r0, [r4]
	bl GetBattlerSide
	ldr r5, _08054790
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	movs r0, #1
	strb r0, [r1, #8]
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r5
	ldrb r0, [r4]
	strb r0, [r1, #9]
	ldr r1, _08054794
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0805478C: .4byte 0x02023EAF
_08054790: .4byte 0x02023F38
_08054794: .4byte 0x02023EB8
	thumb_func_end atkCA_setforcedtarget

	thumb_func_start atkCB_setcharge
atkCB_setcharge: @ 0x08054798
	push {r4, lr}
	ldr r0, _080547EC
	ldr r3, _080547F0
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r0, r2
	str r0, [r1]
	ldr r4, _080547F4
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r2, [r0, #0x12]
	movs r1, #0x10
	rsbs r1, r1, #0
	ands r1, r2
	movs r2, #2
	orrs r1, r2
	strb r1, [r0, #0x12]
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r2, [r0, #0x12]
	movs r1, #0xf
	ands r1, r2
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0, #0x12]
	ldr r1, _080547F8
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080547EC: .4byte 0x02023F50
_080547F0: .4byte 0x02023EAF
_080547F4: .4byte 0x02023F60
_080547F8: .4byte 0x02023EB8
	thumb_func_end atkCB_setcharge

	thumb_func_start atkCC_callterrainattack
atkCC_callterrainattack: @ 0x080547FC
	push {r4, lr}
	ldr r2, _0805484C
	ldr r0, [r2]
	ldr r1, _08054850
	ands r0, r1
	str r0, [r2]
	ldr r4, _08054854
	ldr r1, _08054858
	ldr r0, _0805485C
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, #0
	bl GetMoveTarget
	ldr r1, _08054860
	strb r0, [r1]
	ldr r3, _08054864
	ldr r2, _08054868
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	bl BattleScriptPush
	ldr r1, _0805486C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0805484C: .4byte 0x02023F24
_08054850: .4byte 0xFFFFFBFF
_08054854: .4byte 0x02023E8E
_08054858: .4byte 0x082ECD98
_0805485C: .4byte 0x02022C94
_08054860: .4byte 0x02023EB0
_08054864: .4byte 0x08286C30
_08054868: .4byte 0x082ED220
_0805486C: .4byte 0x02023EB8
	thumb_func_end atkCC_callterrainattack

	thumb_func_start atkCD_cureifburnedparalysedorpoisoned
atkCD_cureifburnedparalysedorpoisoned: @ 0x08054870
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r1, _080548BC
	ldr r3, _080548C0
	ldrb r0, [r3]
	movs r6, #0x58
	muls r0, r6, r0
	adds r5, r1, #0
	adds r5, #0x4c
	adds r2, r0, r5
	ldr r0, [r2]
	movs r1, #0xd8
	ands r0, r1
	cmp r0, #0
	beq _080548CC
	movs r0, #0
	str r0, [r2]
	ldr r1, _080548C4
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	ldr r4, _080548C8
	ldrb r0, [r3]
	strb r0, [r4]
	ldrb r0, [r4]
	muls r0, r6, r0
	adds r0, r0, r5
	str r0, [sp]
	movs r0, #0
	movs r1, #0x28
	movs r2, #0
	movs r3, #4
	bl BtlController_EmitSetMonData
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	b _080548E6
	.align 2, 0
_080548BC: .4byte 0x02023D28
_080548C0: .4byte 0x02023EAF
_080548C4: .4byte 0x02023EB8
_080548C8: .4byte 0x02023D08
_080548CC:
	ldr r3, _080548F0
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_080548E6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080548F0: .4byte 0x02023EB8
	thumb_func_end atkCD_cureifburnedparalysedorpoisoned

	thumb_func_start atkCE_settorment
atkCE_settorment: @ 0x080548F4
	push {lr}
	ldr r1, _0805492C
	ldr r0, _08054930
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #0x18
	cmp r1, #0
	bge _08054938
	ldr r3, _08054934
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08054944
	.align 2, 0
_0805492C: .4byte 0x02023D28
_08054930: .4byte 0x02023EB0
_08054934: .4byte 0x02023EB8
_08054938:
	orrs r1, r2
	str r1, [r0]
	ldr r1, _08054948
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08054944:
	pop {r0}
	bx r0
	.align 2, 0
_08054948: .4byte 0x02023EB8
	thumb_func_end atkCE_settorment

	thumb_func_start atkCF_jumpifnodamage
atkCF_jumpifnodamage: @ 0x0805494C
	push {lr}
	ldr r2, _08054978
	ldr r0, _0805497C
	ldrb r0, [r0]
	lsls r1, r0, #4
	adds r0, r2, #4
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _0805496C
	adds r0, r2, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	beq _08054984
_0805496C:
	ldr r1, _08054980
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _0805499E
	.align 2, 0
_08054978: .4byte 0x02023FE0
_0805497C: .4byte 0x02023EAF
_08054980: .4byte 0x02023EB8
_08054984:
	ldr r3, _080549A4
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_0805499E:
	pop {r0}
	bx r0
	.align 2, 0
_080549A4: .4byte 0x02023EB8
	thumb_func_end atkCF_jumpifnodamage

	thumb_func_start atkD0_settaunt
atkD0_settaunt: @ 0x080549A8
	push {r4, lr}
	ldr r4, _080549EC
	ldr r3, _080549F0
	ldrb r0, [r3]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r2, r1, r4
	ldrb r1, [r2, #0x13]
	lsls r0, r1, #0x1c
	cmp r0, #0
	bne _080549F8
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	strb r0, [r2, #0x13]
	ldrb r1, [r3]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r4
	ldrb r2, [r0, #0x13]
	movs r1, #0xf
	ands r1, r2
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0, #0x13]
	ldr r1, _080549F4
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08054A12
	.align 2, 0
_080549EC: .4byte 0x02023F60
_080549F0: .4byte 0x02023EB0
_080549F4: .4byte 0x02023EB8
_080549F8:
	ldr r3, _08054A18
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08054A12:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054A18: .4byte 0x02023EB8
	thumb_func_end atkD0_settaunt

	thumb_func_start atkD1_trysethelpinghand
atkD1_trysethelpinghand: @ 0x08054A1C
	push {r4, lr}
	ldr r4, _08054A84
	ldrb r0, [r4]
	bl GetBattlerPosition
	movs r1, #2
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	ldr r3, _08054A88
	strb r0, [r3]
	ldr r0, _08054A8C
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08054AA0
	ldr r0, _08054A90
	ldrb r1, [r0]
	ldr r2, _08054A94
	ldrb r3, [r3]
	lsls r0, r3, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08054AA0
	ldr r1, _08054A98
	ldrb r0, [r4]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x1c
	cmp r0, #0
	blt _08054AA0
	lsls r0, r3, #4
	adds r2, r0, r1
	ldrb r1, [r2]
	lsls r0, r1, #0x1c
	cmp r0, #0
	blt _08054AA0
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
	ldr r1, _08054A9C
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08054ABA
	.align 2, 0
_08054A84: .4byte 0x02023EAF
_08054A88: .4byte 0x02023EB0
_08054A8C: .4byte 0x02022C90
_08054A90: .4byte 0x02023EB4
_08054A94: .4byte 0x082FACB4
_08054A98: .4byte 0x02023FE0
_08054A9C: .4byte 0x02023EB8
_08054AA0:
	ldr r3, _08054AC0
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08054ABA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054AC0: .4byte 0x02023EB8
	thumb_func_end atkD1_trysethelpinghand

	thumb_func_start atkD2_tryswapitems
atkD2_tryswapitems: @ 0x08054AC4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r4, _08054BC8
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ands r0, r1
	cmp r0, #0
	bne _08054BAA
	ldr r0, _08054BCC
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08054AF8
	ldr r0, [r4]
	ldr r1, _08054BD0
	ands r0, r1
	cmp r0, #0
	beq _08054BAA
_08054AF8:
	ldr r6, _08054BCC
	ldrb r0, [r6]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r7, _08054BD4
	ldrb r0, [r7]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _08054BC8
	ldr r0, [r0]
	ldr r1, _08054BD0
	ands r0, r1
	cmp r0, #0
	bne _08054B56
	ldr r0, _08054BD8
	adds r2, r0, #0
	adds r2, #0x29
	adds r0, r4, r2
	ldrb r1, [r0]
	ldr r4, _08054BDC
	ldr r3, _08054BE0
	ldrb r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08054BAA
	adds r0, r5, r2
	ldrb r1, [r0]
	ldrb r0, [r7]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08054BAA
_08054B56:
	ldr r0, _08054BE4
	mov r8, r0
	ldr r1, _08054BCC
	ldrb r4, [r1]
	movs r5, #0x58
	adds r0, r4, #0
	muls r0, r5, r0
	add r0, r8
	mov sb, r0
	ldrh r3, [r0, #0x2e]
	adds r1, r3, #0
	cmp r1, #0
	bne _08054B7E
	ldr r0, _08054BD4
	ldrb r0, [r0]
	muls r0, r5, r0
	add r0, r8
	ldrh r0, [r0, #0x2e]
	cmp r0, #0
	beq _08054BAA
_08054B7E:
	cmp r1, #0xaf
	beq _08054BAA
	ldr r7, _08054BD4
	ldrb r0, [r7]
	muls r0, r5, r0
	mov r2, r8
	adds r1, r0, r2
	ldrh r2, [r1, #0x2e]
	cmp r2, #0xaf
	beq _08054BAA
	adds r0, r3, #0
	subs r0, #0x79
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _08054BAA
	adds r0, r2, #0
	subs r0, #0x79
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _08054BEC
_08054BAA:
	ldr r3, _08054BE8
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08054D42
	.align 2, 0
_08054BC8: .4byte 0x02022C90
_08054BCC: .4byte 0x02023EAF
_08054BD0: .4byte 0x0A3F0902
_08054BD4: .4byte 0x02023EB0
_08054BD8: .4byte 0x02024074
_08054BDC: .4byte 0x082FACB4
_08054BE0: .4byte 0x02023D12
_08054BE4: .4byte 0x02023D28
_08054BE8: .4byte 0x02023EB8
_08054BEC:
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x3c
	bne _08054C20
	ldr r1, _08054C14
	ldr r0, _08054C18
	str r0, [r1]
	ldr r1, _08054C1C
	ldrb r0, [r7]
	muls r0, r5, r0
	add r0, r8
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r7]
	ldrb r1, [r1]
	bl RecordAbilityBattle
	b _08054D42
	.align 2, 0
_08054C14: .4byte 0x02023EB8
_08054C18: .4byte 0x08289BC7
_08054C1C: .4byte 0x02023EAE
_08054C20:
	ldr r3, _08054D0C
	mov sl, r3
	lsls r0, r4, #1
	adds r0, #0xd0
	ldr r1, [r3]
	adds r6, r1, r0
	mov r0, sb
	ldrh r0, [r0, #0x2e]
	mov sb, r0
	strh r2, [r6]
	ldr r1, _08054D10
	ldrb r0, [r1]
	muls r0, r5, r0
	add r0, r8
	movs r1, #0
	strh r1, [r0, #0x2e]
	ldrb r0, [r7]
	muls r0, r5, r0
	add r0, r8
	mov r2, sb
	strh r2, [r0, #0x2e]
	ldr r4, _08054D14
	ldr r3, _08054D10
	ldrb r0, [r3]
	strb r0, [r4]
	str r6, [sp]
	movs r0, #0
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl BtlController_EmitSetMonData
	ldr r1, _08054D10
	ldrb r0, [r1]
	bl MarkBattlerForControllerExec
	ldrb r0, [r7]
	strb r0, [r4]
	ldrb r0, [r7]
	muls r0, r5, r0
	mov r1, r8
	adds r1, #0x2e
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl BtlController_EmitSetMonData
	ldrb r0, [r7]
	bl MarkBattlerForControllerExec
	ldrb r0, [r7]
	mov r2, sl
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc8
	movs r3, #0
	strb r3, [r0]
	ldrb r0, [r7]
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc9
	strb r3, [r0]
	ldr r1, _08054D10
	ldrb r0, [r1]
	ldr r1, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc8
	strb r3, [r0]
	ldr r2, _08054D10
	ldrb r0, [r2]
	mov r3, sl
	ldr r1, [r3]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r0, #0xc9
	movs r1, #0
	strb r1, [r0]
	ldr r1, _08054D18
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	ldr r1, _08054D1C
	movs r3, #0xfd
	strb r3, [r1]
	movs r2, #0xa
	strb r2, [r1, #1]
	ldrh r0, [r6]
	strb r0, [r1, #2]
	ldrh r0, [r6]
	lsrs r0, r0, #8
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _08054D20
	strb r3, [r1]
	strb r2, [r1, #1]
	mov r2, sb
	strb r2, [r1, #2]
	mov r3, sb
	lsrs r0, r3, #8
	strb r0, [r1, #3]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1, #4]
	cmp r3, #0
	beq _08054D28
	ldrh r0, [r6]
	cmp r0, #0
	beq _08054D3C
	ldr r1, _08054D24
	movs r0, #2
	b _08054D40
	.align 2, 0
_08054D0C: .4byte 0x02024140
_08054D10: .4byte 0x02023EAF
_08054D14: .4byte 0x02023D08
_08054D18: .4byte 0x02023EB8
_08054D1C: .4byte 0x02022C0C
_08054D20: .4byte 0x02022C1C
_08054D24: .4byte 0x02023FD6
_08054D28:
	ldrh r0, [r6]
	cmp r0, #0
	beq _08054D3C
	ldr r0, _08054D38
	movs r1, #0
	strb r1, [r0, #5]
	b _08054D42
	.align 2, 0
_08054D38: .4byte 0x02023FD6
_08054D3C:
	ldr r1, _08054D54
	movs r0, #1
_08054D40:
	strb r0, [r1, #5]
_08054D42:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08054D54: .4byte 0x02023FD6
	thumb_func_end atkD2_tryswapitems

	thumb_func_start atkD3_trycopyability
atkD3_trycopyability: @ 0x08054D58
	push {r4, lr}
	ldr r3, _08054D98
	ldr r4, _08054D9C
	ldrb r0, [r4]
	movs r2, #0x58
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r1, [r0]
	adds r0, r1, #0
	cmp r0, #0
	beq _08054DAC
	cmp r0, #0x19
	beq _08054DAC
	ldr r0, _08054DA0
	ldrb r0, [r0]
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x20
	strb r1, [r0]
	ldr r1, _08054DA4
	ldrb r0, [r4]
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _08054DA8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08054DC6
	.align 2, 0
_08054D98: .4byte 0x02023D28
_08054D9C: .4byte 0x02023EB0
_08054DA0: .4byte 0x02023EAF
_08054DA4: .4byte 0x02023EAE
_08054DA8: .4byte 0x02023EB8
_08054DAC:
	ldr r3, _08054DCC
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08054DC6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054DCC: .4byte 0x02023EB8
	thumb_func_end atkD3_trycopyability

	thumb_func_start atkD4_trywish
atkD4_trywish: @ 0x08054DD0
	push {r4, r5, r6, r7, lr}
	ldr r7, _08054DE4
	ldr r2, [r7]
	ldrb r3, [r2, #1]
	cmp r3, #0
	beq _08054DE8
	cmp r3, #1
	beq _08054E20
	b _08054E9C
	.align 2, 0
_08054DE4: .4byte 0x02023EB8
_08054DE8:
	ldr r1, _08054E14
	ldr r4, _08054E18
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r5, [r4]
	adds r3, r0, r5
	ldrb r0, [r3]
	cmp r0, #0
	bne _08054E6C
	movs r0, #2
	strb r0, [r3]
	ldrb r0, [r4]
	adds r1, #0x24
	adds r1, r0, r1
	ldr r2, _08054E1C
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r0, [r7]
	adds r0, #6
	b _08054E9A
	.align 2, 0
_08054E14: .4byte 0x02024074
_08054E18: .4byte 0x02023EAF
_08054E1C: .4byte 0x02023D12
_08054E20:
	ldr r1, _08054E84
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #4
	strb r0, [r1, #1]
	ldr r4, _08054E88
	ldrb r0, [r4]
	strb r0, [r1, #2]
	ldr r0, _08054E8C
	adds r0, #0x24
	ldrb r5, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _08054E90
	ldr r6, _08054E94
	ldrb r0, [r4]
	movs r5, #0x58
	muls r0, r5, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x2c]
	lsrs r0, r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _08054E58
	str r3, [r1]
_08054E58:
	ldr r0, [r1]
	rsbs r0, r0, #0
	str r0, [r1]
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r0, r6
	ldrh r1, [r0, #0x28]
	ldrh r0, [r0, #0x2c]
	cmp r1, r0
	bne _08054E98
_08054E6C:
	ldrb r1, [r2, #2]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #5]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r7]
	b _08054E9C
	.align 2, 0
_08054E84: .4byte 0x02022C0C
_08054E88: .4byte 0x02023EB0
_08054E8C: .4byte 0x02024074
_08054E90: .4byte 0x02023E94
_08054E94: .4byte 0x02023D28
_08054E98:
	adds r0, r2, #6
_08054E9A:
	str r0, [r7]
_08054E9C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end atkD4_trywish

	thumb_func_start atkD5_trysetroots
atkD5_trysetroots: @ 0x08054EA4
	push {lr}
	ldr r1, _08054EDC
	ldr r0, _08054EE0
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _08054EE8
	ldr r3, _08054EE4
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08054EF4
	.align 2, 0
_08054EDC: .4byte 0x02023F50
_08054EE0: .4byte 0x02023EAF
_08054EE4: .4byte 0x02023EB8
_08054EE8:
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08054EF8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08054EF4:
	pop {r0}
	bx r0
	.align 2, 0
_08054EF8: .4byte 0x02023EB8
	thumb_func_end atkD5_trysetroots

	thumb_func_start atkD6_doubledamagedealtifdamaged
atkD6_doubledamagedealtifdamaged: @ 0x08054EFC
	push {lr}
	ldr r3, _08054F48
	ldr r0, _08054F4C
	ldrb r0, [r0]
	lsls r2, r0, #4
	adds r0, r3, #4
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, #0
	beq _08054F1C
	adds r0, r2, r3
	ldr r1, _08054F50
	ldrb r0, [r0, #0xc]
	ldrb r1, [r1]
	cmp r0, r1
	beq _08054F34
_08054F1C:
	adds r0, r3, #0
	adds r0, #8
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, #0
	beq _08054F3A
	adds r0, r2, r3
	ldr r1, _08054F50
	ldrb r0, [r0, #0xd]
	ldrb r1, [r1]
	cmp r0, r1
	bne _08054F3A
_08054F34:
	ldr r1, _08054F54
	movs r0, #2
	strb r0, [r1, #0xe]
_08054F3A:
	ldr r1, _08054F58
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08054F48: .4byte 0x02023FE0
_08054F4C: .4byte 0x02023EAF
_08054F50: .4byte 0x02023EB0
_08054F54: .4byte 0x02024118
_08054F58: .4byte 0x02023EB8
	thumb_func_end atkD6_doubledamagedealtifdamaged

	thumb_func_start atkD7_setyawn
atkD7_setyawn: @ 0x08054F5C
	push {r4, lr}
	ldr r1, _08054FA0
	ldr r0, _08054FA4
	ldrb r3, [r0]
	lsls r0, r3, #2
	adds r4, r0, r1
	ldr r2, [r4]
	movs r0, #0xc0
	lsls r0, r0, #5
	ands r0, r2
	cmp r0, #0
	bne _08054F84
	ldr r1, _08054FA8
	movs r0, #0x58
	muls r0, r3, r0
	adds r1, #0x4c
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08054FB0
_08054F84:
	ldr r3, _08054FAC
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08054FC0
	.align 2, 0
_08054FA0: .4byte 0x02023F50
_08054FA4: .4byte 0x02023EB0
_08054FA8: .4byte 0x02023D28
_08054FAC: .4byte 0x02023EB8
_08054FB0:
	movs r0, #0x80
	lsls r0, r0, #5
	orrs r2, r0
	str r2, [r4]
	ldr r1, _08054FC8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08054FC0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08054FC8: .4byte 0x02023EB8
	thumb_func_end atkD7_setyawn

	thumb_func_start atkD8_setdamagetohealthdifference
atkD8_setdamagetohealthdifference: @ 0x08054FCC
	push {lr}
	ldr r2, _08055008
	ldr r0, _0805500C
	ldrb r0, [r0]
	movs r1, #0x58
	muls r0, r1, r0
	adds r3, r0, r2
	ldr r0, _08055010
	ldrb r0, [r0]
	muls r0, r1, r0
	adds r1, r0, r2
	ldrh r0, [r3, #0x28]
	ldrh r2, [r1, #0x28]
	cmp r0, r2
	bhi _08055018
	ldr r3, _08055014
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805502A
	.align 2, 0
_08055008: .4byte 0x02023D28
_0805500C: .4byte 0x02023EB0
_08055010: .4byte 0x02023EAF
_08055014: .4byte 0x02023EB8
_08055018:
	ldr r2, _08055030
	ldrh r0, [r3, #0x28]
	ldrh r1, [r1, #0x28]
	subs r0, r0, r1
	str r0, [r2]
	ldr r1, _08055034
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805502A:
	pop {r0}
	bx r0
	.align 2, 0
_08055030: .4byte 0x02023E94
_08055034: .4byte 0x02023EB8
	thumb_func_end atkD8_setdamagetohealthdifference

	thumb_func_start atkD9_scaledamagebyhealthratio
atkD9_scaledamagebyhealthratio: @ 0x08055038
	push {r4, lr}
	ldr r4, _08055084
	ldrh r0, [r4]
	cmp r0, #0
	bne _08055074
	ldr r2, _08055088
	ldr r0, _0805508C
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r3, [r0, #1]
	ldr r2, _08055090
	ldr r0, _08055094
	ldrb r1, [r0]
	movs r0, #0x58
	muls r1, r0, r1
	adds r1, r1, r2
	ldrh r0, [r1, #0x28]
	muls r0, r3, r0
	ldrh r1, [r1, #0x2c]
	bl __divsi3
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08055074
	movs r0, #1
	strh r0, [r4]
_08055074:
	ldr r1, _08055098
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055084: .4byte 0x020240A4
_08055088: .4byte 0x082ED220
_0805508C: .4byte 0x02023E8E
_08055090: .4byte 0x02023D28
_08055094: .4byte 0x02023EAF
_08055098: .4byte 0x02023EB8
	thumb_func_end atkD9_scaledamagebyhealthratio

	thumb_func_start atkDA_tryswapabilities
atkDA_tryswapabilities: @ 0x0805509C
	push {r4, r5, r6, lr}
	ldr r5, _08055100
	ldr r0, _08055104
	ldrb r0, [r0]
	movs r4, #0x58
	muls r0, r4, r0
	adds r0, r0, r5
	adds r2, r0, #0
	adds r2, #0x20
	ldrb r1, [r2]
	cmp r1, #0
	bne _080550C4
	ldr r0, _08055108
	ldrb r0, [r0]
	muls r0, r4, r0
	adds r0, r0, r5
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _080550E4
_080550C4:
	cmp r1, #0x19
	beq _080550E4
	ldr r6, _08055108
	ldrb r0, [r6]
	muls r0, r4, r0
	adds r0, r0, r5
	adds r0, #0x20
	ldrb r3, [r0]
	cmp r3, #0x19
	beq _080550E4
	ldr r0, _0805510C
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _08055114
_080550E4:
	ldr r3, _08055110
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805512A
	.align 2, 0
_08055100: .4byte 0x02023D28
_08055104: .4byte 0x02023EAF
_08055108: .4byte 0x02023EB0
_0805510C: .4byte 0x02023F20
_08055110: .4byte 0x02023EB8
_08055114:
	ldrb r1, [r2]
	strb r3, [r2]
	ldrb r0, [r6]
	muls r0, r4, r0
	adds r0, r0, r5
	adds r0, #0x20
	strb r1, [r0]
	ldr r1, _08055130
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805512A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08055130: .4byte 0x02023EB8
	thumb_func_end atkDA_tryswapabilities

	thumb_func_start atkDB_tryimprison
atkDB_tryimprison: @ 0x08055134
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r1, _08055154
	ldr r4, _08055158
	ldrb r2, [r4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #6
	ands r0, r1
	cmp r0, #0
	beq _08055184
	b _08055206
	.align 2, 0
_08055154: .4byte 0x02023F50
_08055158: .4byte 0x02023EAF
_0805515C:
	ldr r0, _0805517C
	mov r2, sb
	ldrb r1, [r2]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	orrs r0, r2
	str r0, [r1]
	ldr r1, _08055180
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _080551FE
	.align 2, 0
_0805517C: .4byte 0x02023F50
_08055180: .4byte 0x02023EB8
_08055184:
	adds r0, r2, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldrb r0, [r4]
	bl PressurePPLoseOnUsingImprison
	movs r6, #0
	b _080551F6
_0805519A:
	adds r0, r6, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r8, r0
	beq _080551F0
	movs r4, #0
	ldr r7, _0805522C
	mov sb, r7
	ldr r0, _08055230
	mov ip, r0
	mov r1, sb
	ldrb r0, [r1]
	mov r2, ip
	adds r2, #0xc
	movs r1, #0x58
	muls r0, r1, r0
	adds r3, r0, r2
	adds r5, r6, #0
	muls r5, r1, r5
_080551C4:
	movs r2, #0
	ldrh r1, [r3]
	mov r0, ip
	adds r0, #0xc
	adds r0, r5, r0
_080551CE:
	ldrh r7, [r0]
	cmp r1, r7
	bne _080551D8
	cmp r1, #0
	bne _080551E0
_080551D8:
	adds r0, #2
	adds r2, #1
	cmp r2, #3
	ble _080551CE
_080551E0:
	cmp r2, #4
	bne _080551EC
	adds r3, #2
	adds r4, #1
	cmp r4, #3
	ble _080551C4
_080551EC:
	cmp r4, #4
	bne _0805515C
_080551F0:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
_080551F6:
	ldr r0, _08055234
	ldrb r0, [r0]
	cmp r6, r0
	blo _0805519A
_080551FE:
	ldr r0, _08055234
	ldrb r0, [r0]
	cmp r6, r0
	bne _08055220
_08055206:
	ldr r3, _08055238
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055220:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0805522C: .4byte 0x02023EAF
_08055230: .4byte 0x02023D28
_08055234: .4byte 0x02023D10
_08055238: .4byte 0x02023EB8
	thumb_func_end atkDB_tryimprison

	thumb_func_start atkDC_trysetgrudge
atkDC_trysetgrudge: @ 0x0805523C
	push {lr}
	ldr r1, _08055274
	ldr r0, _08055278
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _08055280
	ldr r3, _0805527C
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805528C
	.align 2, 0
_08055274: .4byte 0x02023F50
_08055278: .4byte 0x02023EAF
_0805527C: .4byte 0x02023EB8
_08055280:
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08055290
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805528C:
	pop {r0}
	bx r0
	.align 2, 0
_08055290: .4byte 0x02023EB8
	thumb_func_end atkDC_trysetgrudge

	thumb_func_start atkDD_weightdamagecalculation
atkDD_weightdamagecalculation: @ 0x08055294
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	movs r5, #0
	ldr r2, _080552F8
	ldrh r0, [r2]
	ldr r1, _080552FC
	cmp r0, r1
	beq _0805530C
	adds r6, r2, #0
	ldr r0, _08055300
	mov r8, r0
	adds r7, r1, #0
	adds r4, r6, #0
_080552B0:
	ldr r0, _08055304
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	add r0, r8
	ldrh r0, [r0]
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl GetPokedexHeightWeight
	ldrh r1, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bhi _080552DE
	adds r4, #4
	adds r5, #2
	ldrh r0, [r4]
	cmp r0, r7
	bne _080552B0
_080552DE:
	lsls r0, r5, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	ldr r0, _080552FC
	cmp r1, r0
	beq _0805530C
	ldr r0, _08055308
	adds r1, r5, #1
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	strh r1, [r0]
	b _08055312
	.align 2, 0
_080552F8: .4byte 0x082ECDAC
_080552FC: .4byte 0x0000FFFF
_08055300: .4byte 0x02023D28
_08055304: .4byte 0x02023EB0
_08055308: .4byte 0x020240A4
_0805530C:
	ldr r1, _08055324
	movs r0, #0x78
	strh r0, [r1]
_08055312:
	ldr r1, _08055328
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08055324: .4byte 0x020240A4
_08055328: .4byte 0x02023EB8
	thumb_func_end atkDD_weightdamagecalculation

	thumb_func_start atkDE_assistattackselect
atkDE_assistattackselect: @ 0x0805532C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	movs r0, #0
	mov sl, r0
	ldr r0, _0805544C
	ldr r0, [r0]
	adds r0, #0x18
	str r0, [sp, #4]
	ldr r0, _08055450
	ldrb r0, [r0]
	bl GetBattlerPosition
	movs r1, #1
	ands r1, r0
	ldr r0, _08055454
	str r0, [sp]
	cmp r1, #0
	beq _0805535C
	ldr r1, _08055458
	str r1, [sp]
_0805535C:
	movs r2, #0
_0805535E:
	ldr r1, _0805545C
	ldr r0, _08055450
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	adds r1, r2, #1
	str r1, [sp, #8]
	ldrh r0, [r0]
	cmp r2, r0
	beq _08055404
	movs r0, #0x64
	adds r6, r2, #0
	muls r6, r0, r6
	ldr r0, [sp]
	adds r4, r0, r6
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	cmp r0, #0
	beq _08055404
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	movs r1, #0xce
	lsls r1, r1, #1
	cmp r0, r1
	beq _08055404
	movs r5, #0
	ldr r1, _08055460
	mov r8, r1
	mov sb, r6
	mov r1, sl
	lsls r0, r1, #1
	ldr r1, [sp, #4]
	adds r6, r0, r1
_080553A8:
	movs r7, #0
	adds r1, r5, #0
	adds r1, #0xd
	ldr r0, [sp]
	add r0, sb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	bl IsInvalidForSleepTalkOrAssist
	lsls r0, r0, #0x18
	adds r1, r5, #1
	cmp r0, #0
	bne _080553FE
	ldr r0, _08055464
	ldrh r2, [r0]
	adds r3, r0, #0
	cmp r2, r8
	beq _080553F2
	cmp r4, r2
	beq _080553E8
	ldr r5, _08055460
	adds r2, r3, #0
_080553DA:
	adds r2, #2
	adds r7, #1
	ldrh r0, [r2]
	cmp r0, r5
	beq _080553F2
	cmp r4, r0
	bne _080553DA
_080553E8:
	lsls r0, r7, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	cmp r0, r8
	bne _080553FE
_080553F2:
	cmp r4, #0
	beq _080553FE
	strh r4, [r6]
	adds r6, #2
	movs r0, #1
	add sl, r0
_080553FE:
	adds r5, r1, #0
	cmp r5, #3
	ble _080553A8
_08055404:
	ldr r2, [sp, #8]
	cmp r2, #5
	ble _0805535E
	mov r1, sl
	cmp r1, #0
	beq _0805547C
	ldr r2, _08055468
	ldr r0, [r2]
	ldr r1, _0805546C
	ands r0, r1
	str r0, [r2]
	ldr r4, _08055470
	bl Random
	movs r1, #0xff
	ands r1, r0
	mov r0, sl
	muls r0, r1, r0
	asrs r0, r0, #8
	lsls r0, r0, #1
	ldr r1, [sp, #4]
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r4]
	ldrh r0, [r4]
	movs r1, #0
	bl GetMoveTarget
	ldr r1, _08055474
	strb r0, [r1]
	ldr r1, _08055478
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08055496
	.align 2, 0
_0805544C: .4byte 0x02024140
_08055450: .4byte 0x02023EAF
_08055454: .4byte 0x02024190
_08055458: .4byte 0x020243E8
_0805545C: .4byte 0x02023D12
_08055460: .4byte 0x0000FFFF
_08055464: .4byte 0x082ECD64
_08055468: .4byte 0x02023F24
_0805546C: .4byte 0xFFFFFBFF
_08055470: .4byte 0x02023E92
_08055474: .4byte 0x02023EB0
_08055478: .4byte 0x02023EB8
_0805547C:
	ldr r3, _080554A8
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055496:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080554A8: .4byte 0x02023EB8
	thumb_func_end atkDE_assistattackselect

	thumb_func_start atkDF_trysetmagiccoat
atkDF_trysetmagiccoat: @ 0x080554AC
	push {lr}
	ldr r1, _080554F4
	ldr r3, _080554F8
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r2, _080554FC
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r0, _08055500
	ldrb r1, [r0]
	ldr r0, _08055504
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _0805550C
	ldr r3, _08055508
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _08055524
	.align 2, 0
_080554F4: .4byte 0x02023EB0
_080554F8: .4byte 0x02023EAF
_080554FC: .4byte 0x02024020
_08055500: .4byte 0x02023D26
_08055504: .4byte 0x02023D10
_08055508: .4byte 0x02023EB8
_0805550C:
	ldr r0, _08055528
	ldrb r1, [r3]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #0x10
	orrs r0, r2
	strb r0, [r1]
	ldr r1, _0805552C
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_08055524:
	pop {r0}
	bx r0
	.align 2, 0
_08055528: .4byte 0x02023FE0
_0805552C: .4byte 0x02023EB8
	thumb_func_end atkDF_trysetmagiccoat

	thumb_func_start atkE0_trysetsnatch
atkE0_trysetsnatch: @ 0x08055530
	push {lr}
	ldr r2, _08055574
	ldr r3, _08055578
	ldrb r1, [r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #0x20
	orrs r1, r2
	strb r1, [r0]
	ldr r0, _0805557C
	ldrb r1, [r0]
	ldr r0, _08055580
	ldrb r0, [r0]
	subs r0, #1
	cmp r1, r0
	bne _08055588
	ldr r3, _08055584
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805559E
	.align 2, 0
_08055574: .4byte 0x02024020
_08055578: .4byte 0x02023EAF
_0805557C: .4byte 0x02023D26
_08055580: .4byte 0x02023D10
_08055584: .4byte 0x02023EB8
_08055588:
	ldr r0, _080555A4
	ldrb r1, [r3]
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldr r1, _080555A8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805559E:
	pop {r0}
	bx r0
	.align 2, 0
_080555A4: .4byte 0x02023FE0
_080555A8: .4byte 0x02023EB8
	thumb_func_end atkE0_trysetsnatch

	thumb_func_start atkE1_trygetintimidatetarget
atkE1_trygetintimidatetarget: @ 0x080555AC
	push {r4, r5, r6, lr}
	ldr r4, _08055650
	ldr r0, _08055654
	ldr r0, [r0]
	adds r0, #0xd8
	ldrb r0, [r0]
	strb r0, [r4, #0x17]
	ldrb r0, [r4, #0x17]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r2, _08055658
	movs r0, #0xfd
	strb r0, [r2]
	movs r0, #9
	strb r0, [r2, #1]
	ldr r3, _0805565C
	ldrb r1, [r4, #0x17]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r2, #2]
	movs r0, #0xff
	strb r0, [r2, #3]
	ldr r2, _08055660
	ldr r1, _08055664
	ldrb r0, [r2]
	ldrb r1, [r1]
	cmp r0, r1
	bhs _08055632
	adds r4, r2, #0
	ldr r6, _08055668
_080555F2:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	beq _08055614
	ldr r0, _0805566C
	ldrb r1, [r0]
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ands r1, r0
	ldr r2, _08055664
	cmp r1, #0
	beq _08055628
_08055614:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _08055664
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r2, r1, #0
	ldrb r1, [r2]
	cmp r0, r1
	blo _080555F2
_08055628:
	ldr r0, _08055660
	ldrb r0, [r0]
	ldrb r2, [r2]
	cmp r0, r2
	blo _08055674
_08055632:
	ldr r3, _08055670
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _0805567C
	.align 2, 0
_08055650: .4byte 0x02024118
_08055654: .4byte 0x02024140
_08055658: .4byte 0x02022C0C
_0805565C: .4byte 0x02023D28
_08055660: .4byte 0x02023EB0
_08055664: .4byte 0x02023D10
_08055668: .4byte 0x082FACB4
_0805566C: .4byte 0x02023EB4
_08055670: .4byte 0x02023EB8
_08055674:
	ldr r1, _08055684
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_0805567C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08055684: .4byte 0x02023EB8
	thumb_func_end atkE1_trygetintimidatetarget

	thumb_func_start atkE2_switchoutabilities
atkE2_switchoutabilities: @ 0x08055688
	push {r4, r5, r6, lr}
	sub sp, #4
	ldr r5, _080556F0
	ldr r0, [r5]
	ldrb r0, [r0, #1]
	bl GetBattlerForBattleScript
	ldr r4, _080556F4
	strb r0, [r4]
	ldr r3, _080556F8
	ldrb r0, [r4]
	movs r6, #0x58
	adds r1, r0, #0
	muls r1, r6, r1
	adds r0, r1, r3
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x1e
	bne _080556E2
	adds r3, #0x4c
	adds r1, r1, r3
	movs r0, #0
	str r0, [r1]
	ldr r2, _080556FC
	ldrb r1, [r4]
	ldr r0, _08055700
	ldr r0, [r0]
	adds r0, r1, r0
	adds r0, #0x58
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r2, [r0]
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r0, r3
	str r0, [sp]
	movs r0, #0
	movs r1, #0x28
	movs r3, #4
	bl BtlController_EmitSetMonData
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_080556E2:
	ldr r0, [r5]
	adds r0, #2
	str r0, [r5]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080556F0: .4byte 0x02023EB8
_080556F4: .4byte 0x02023D08
_080556F8: .4byte 0x02023D28
_080556FC: .4byte 0x082FACB4
_08055700: .4byte 0x02024140
	thumb_func_end atkE2_switchoutabilities

	thumb_func_start atkE3_jumpifhasnohp
atkE3_jumpifhasnohp: @ 0x08055704
	push {r4, lr}
	ldr r4, _08055740
	ldr r0, [r4]
	ldrb r0, [r0, #1]
	bl GetBattlerForBattleScript
	ldr r1, _08055744
	strb r0, [r1]
	ldr r2, _08055748
	ldrb r1, [r1]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _0805574C
	ldr r2, [r4]
	ldrb r1, [r2, #2]
	ldrb r0, [r2, #3]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #5]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r4]
	b _08055752
	.align 2, 0
_08055740: .4byte 0x02023EB8
_08055744: .4byte 0x02023D08
_08055748: .4byte 0x02023D28
_0805574C:
	ldr r0, [r4]
	adds r0, #6
	str r0, [r4]
_08055752:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end atkE3_jumpifhasnohp

	thumb_func_start atkE4_getsecretpowereffect
atkE4_getsecretpowereffect: @ 0x08055758
	push {lr}
	ldr r0, _0805576C
	ldrb r0, [r0]
	cmp r0, #7
	bhi _080557F4
	lsls r0, r0, #2
	ldr r1, _08055770
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0805576C: .4byte 0x02022C94
_08055770: .4byte 0x08055774
_08055774: @ jump table
	.4byte _08055794 @ case 0
	.4byte _080557A0 @ case 1
	.4byte _080557AC @ case 2
	.4byte _080557B8 @ case 3
	.4byte _080557C4 @ case 4
	.4byte _080557D0 @ case 5
	.4byte _080557DC @ case 6
	.4byte _080557E8 @ case 7
_08055794:
	ldr r1, _0805579C
	movs r0, #2
	b _080557F8
	.align 2, 0
_0805579C: .4byte 0x02023FD6
_080557A0:
	ldr r1, _080557A8
	movs r0, #1
	b _080557F8
	.align 2, 0
_080557A8: .4byte 0x02023FD6
_080557AC:
	ldr r1, _080557B4
	movs r0, #0x1b
	b _080557F8
	.align 2, 0
_080557B4: .4byte 0x02023FD6
_080557B8:
	ldr r1, _080557C0
	movs r0, #0x17
	b _080557F8
	.align 2, 0
_080557C0: .4byte 0x02023FD6
_080557C4:
	ldr r1, _080557CC
	movs r0, #0x16
	b _080557F8
	.align 2, 0
_080557CC: .4byte 0x02023FD6
_080557D0:
	ldr r1, _080557D8
	movs r0, #0x18
	b _080557F8
	.align 2, 0
_080557D8: .4byte 0x02023FD6
_080557DC:
	ldr r1, _080557E4
	movs r0, #7
	b _080557F8
	.align 2, 0
_080557E4: .4byte 0x02023FD6
_080557E8:
	ldr r1, _080557F0
	movs r0, #8
	b _080557F8
	.align 2, 0
_080557F0: .4byte 0x02023FD6
_080557F4:
	ldr r1, _08055808
	movs r0, #5
_080557F8:
	strb r0, [r1, #3]
	ldr r1, _0805580C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_08055808: .4byte 0x02023FD6
_0805580C: .4byte 0x02023EB8
	thumb_func_end atkE4_getsecretpowereffect

	thumb_func_start atkE5_pickup
atkE5_pickup: @ 0x08055810
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	bl InBattlePike
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08055828
	b _080559E8
_08055828:
	bl CurrentBattlePyramidLocation
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080558D4
	movs r6, #0
	mov r7, sp
	ldr r0, _08055874
	mov r8, r0
_0805583A:
	movs r0, #0x64
	adds r4, r6, #0
	muls r4, r0, r4
	ldr r0, _08055878
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #0xc
	bl GetMonData3
	strh r0, [r7]
	adds r0, r4, #0
	movs r1, #0x2e
	bl GetMonData3
	cmp r0, #0
	beq _0805587C
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0, #0x17]
	b _08055886
	.align 2, 0
_08055874: .4byte 0x082F0D54
_08055878: .4byte 0x02024190
_0805587C:
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	add r0, r8
	ldrb r0, [r0, #0x16]
_08055886:
	cmp r0, #0x35
	bne _080558C6
	cmp r5, #0
	beq _080558C6
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r5, r0
	beq _080558C6
	ldrh r0, [r7]
	cmp r0, #0
	bne _080558C6
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080558C6
	bl GetBattlePyramidPickupItemId
	strh r0, [r7]
	movs r0, #0x64
	muls r0, r6, r0
	ldr r1, _080558D0
	adds r0, r0, r1
	movs r1, #0xc
	mov r2, sp
	bl SetMonData
_080558C6:
	adds r6, #1
	cmp r6, #5
	ble _0805583A
	b _080559E8
	.align 2, 0
_080558D0: .4byte 0x02024190
_080558D4:
	movs r6, #0
	movs r1, #0x64
	mov r8, r1
	ldr r7, _08055918
	mov sl, sp
_080558DE:
	mov r4, r8
	muls r4, r6, r4
	adds r4, r4, r7
	adds r0, r4, #0
	movs r1, #0x41
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #0xc
	bl GetMonData3
	mov r1, sl
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x2e
	bl GetMonData3
	cmp r0, #0
	beq _08055940
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	ldr r1, _0805591C
	adds r0, r0, r1
	ldrb r0, [r0, #0x17]
	b _0805594C
	.align 2, 0
_08055918: .4byte 0x02024190
_0805591C: .4byte 0x082F0D54
_08055920:
	mov r0, r8
	muls r0, r6, r0
	adds r0, r0, r7
	adds r2, r1, #0
	adds r2, #0x63
	subs r2, r2, r4
	lsls r2, r2, #1
	ldr r1, _0805593C
	adds r2, r2, r1
	movs r1, #0xc
	bl SetMonData
	b _080559E0
	.align 2, 0
_0805593C: .4byte 0x082ECDE8
_08055940:
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	ldr r1, _080559B0
	adds r0, r0, r1
	ldrb r0, [r0, #0x16]
_0805594C:
	adds r1, r6, #1
	mov sb, r1
	cmp r0, #0x35
	bne _080559E0
	cmp r5, #0
	beq _080559E0
	movs r0, #0xce
	lsls r0, r0, #1
	cmp r5, r0
	beq _080559E0
	mov r1, sl
	ldrh r0, [r1]
	cmp r0, #0
	bne _080559E0
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080559E0
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r0, r8
	muls r0, r6, r0
	adds r0, r0, r7
	movs r1, #0x38
	bl GetMonData3
	subs r0, #1
	movs r1, #0xa
	bl __udivsi3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #9
	bls _080559AC
	movs r1, #9
_080559AC:
	movs r2, #0
	b _080559BE
	.align 2, 0
_080559B0: .4byte 0x082F0D54
_080559B4:
	adds r0, r4, #0
	subs r0, #0x62
	cmp r0, #1
	bls _08055920
	adds r2, #1
_080559BE:
	cmp r2, #8
	bgt _080559E0
	ldr r0, _08055A00
	adds r0, r2, r0
	ldrb r0, [r0]
	cmp r0, r4
	ble _080559B4
	mov r0, r8
	muls r0, r6, r0
	adds r0, r0, r7
	adds r2, r1, r2
	lsls r2, r2, #1
	ldr r1, _08055A04
	adds r2, r2, r1
	movs r1, #0xc
	bl SetMonData
_080559E0:
	mov r6, sb
	cmp r6, #5
	bgt _080559E8
	b _080558DE
_080559E8:
	ldr r1, _08055A08
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08055A00: .4byte 0x082ECDFE
_08055A04: .4byte 0x082ECDC4
_08055A08: .4byte 0x02023EB8
	thumb_func_end atkE5_pickup

	thumb_func_start atkE6_docastformchangeanimation
atkE6_docastformchangeanimation: @ 0x08055A0C
	push {r4, lr}
	ldr r4, _08055A60
	ldr r0, _08055A64
	ldrb r0, [r0, #0x17]
	strb r0, [r4]
	ldr r1, _08055A68
	ldrb r2, [r4]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x11
	ands r0, r1
	ldr r3, _08055A6C
	cmp r0, #0
	beq _08055A3C
	ldr r0, [r3]
	adds r0, #0x7f
	ldrb r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strb r1, [r0]
_08055A3C:
	ldr r0, [r3]
	adds r0, #0x7f
	ldrb r2, [r0]
	movs r0, #0
	movs r1, #0
	bl BtlController_EmitBattleAnimation
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r1, _08055A70
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055A60: .4byte 0x02023D08
_08055A64: .4byte 0x02024118
_08055A68: .4byte 0x02023D28
_08055A6C: .4byte 0x02024140
_08055A70: .4byte 0x02023EB8
	thumb_func_end atkE6_docastformchangeanimation

	thumb_func_start atkE7_trycastformdatachange
atkE7_trycastformdatachange: @ 0x08055A74
	push {r4, lr}
	ldr r1, _08055AA4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, _08055AA8
	ldrb r0, [r0, #0x17]
	bl CastformDataTypeChange
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _08055A9E
	ldr r0, _08055AAC
	bl BattleScriptPushCursorAndCallback
	ldr r0, _08055AB0
	ldr r0, [r0]
	adds r0, #0x7f
	subs r1, r4, #1
	strb r1, [r0]
_08055A9E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055AA4: .4byte 0x02023EB8
_08055AA8: .4byte 0x02024118
_08055AAC: .4byte 0x08289A31
_08055AB0: .4byte 0x02024140
	thumb_func_end atkE7_trycastformdatachange

	thumb_func_start atkE8_settypebasedhalvers
atkE8_settypebasedhalvers: @ 0x08055AB4
	push {r4, lr}
	movs r4, #0
	ldr r2, _08055AF0
	ldr r0, _08055AF4
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0xc9
	bne _08055B04
	ldr r1, _08055AF8
	ldr r0, _08055AFC
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #9
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	bne _08055B28
	orrs r1, r3
	str r1, [r2]
	ldr r0, _08055B00
	strb r4, [r0, #5]
	b _08055B2C
	.align 2, 0
_08055AF0: .4byte 0x082ED220
_08055AF4: .4byte 0x02023E8E
_08055AF8: .4byte 0x02023F50
_08055AFC: .4byte 0x02023EAF
_08055B00: .4byte 0x02023FD6
_08055B04:
	ldr r1, _08055B38
	ldr r0, _08055B3C
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r2, r0, r1
	ldr r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #0xa
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	bne _08055B28
	orrs r1, r3
	str r1, [r2]
	ldr r1, _08055B40
	movs r0, #1
	strb r0, [r1, #5]
	movs r4, #1
_08055B28:
	cmp r4, #0
	beq _08055B48
_08055B2C:
	ldr r1, _08055B44
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08055B62
	.align 2, 0
_08055B38: .4byte 0x02023F50
_08055B3C: .4byte 0x02023EAF
_08055B40: .4byte 0x02023FD6
_08055B44: .4byte 0x02023EB8
_08055B48:
	ldr r3, _08055B68
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055B62:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055B68: .4byte 0x02023EB8
	thumb_func_end atkE8_settypebasedhalvers

	thumb_func_start atkE9_setweatherballtype
atkE9_setweatherballtype: @ 0x08055B6C
	push {lr}
	sub sp, #4
	movs r0, #0
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	bne _08055C0C
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0x4d
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08055C0C
	ldr r2, _08055BBC
	ldrb r0, [r2]
	cmp r0, #0
	beq _08055BAA
	ldr r1, _08055BC0
	movs r0, #2
	strb r0, [r1, #0xe]
_08055BAA:
	ldrh r1, [r2]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _08055BC8
	ldr r0, _08055BC4
	ldr r1, [r0]
	movs r0, #0x8b
	b _08055C0A
	.align 2, 0
_08055BBC: .4byte 0x02024070
_08055BC0: .4byte 0x02024118
_08055BC4: .4byte 0x02024140
_08055BC8:
	movs r0, #0x18
	ands r0, r1
	cmp r0, #0
	beq _08055BDC
	ldr r0, _08055BD8
	ldr r1, [r0]
	movs r0, #0x85
	b _08055C0A
	.align 2, 0
_08055BD8: .4byte 0x02024140
_08055BDC:
	movs r0, #0x60
	ands r0, r1
	cmp r0, #0
	beq _08055BF0
	ldr r0, _08055BEC
	ldr r1, [r0]
	movs r0, #0x8a
	b _08055C0A
	.align 2, 0
_08055BEC: .4byte 0x02024140
_08055BF0:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08055C04
	ldr r0, _08055C00
	ldr r1, [r0]
	movs r0, #0x8f
	b _08055C0A
	.align 2, 0
_08055C00: .4byte 0x02024140
_08055C04:
	ldr r0, _08055C1C
	ldr r1, [r0]
	movs r0, #0x80
_08055C0A:
	strb r0, [r1, #0x13]
_08055C0C:
	ldr r1, _08055C20
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r0}
	bx r0
	.align 2, 0
_08055C1C: .4byte 0x02024140
_08055C20: .4byte 0x02023EB8
	thumb_func_end atkE9_setweatherballtype

	thumb_func_start atkEA_tryrecycleitem
atkEA_tryrecycleitem: @ 0x08055C24
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r7, _08055C8C
	ldr r0, _08055C90
	ldrb r0, [r0]
	strb r0, [r7]
	ldr r1, _08055C94
	ldrb r2, [r7]
	lsls r0, r2, #1
	adds r0, #0xb8
	ldr r1, [r1]
	adds r6, r1, r0
	ldrh r5, [r6]
	cmp r5, #0
	beq _08055CA4
	ldr r4, _08055C98
	movs r3, #0x58
	adds r0, r2, #0
	muls r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0, #0x2e]
	cmp r0, #0
	bne _08055CA4
	ldr r1, _08055C9C
	strh r5, [r1]
	strh r0, [r6]
	ldrb r0, [r7]
	muls r0, r3, r0
	adds r0, r0, r4
	ldrh r1, [r1]
	strh r1, [r0, #0x2e]
	ldrb r0, [r7]
	muls r0, r3, r0
	adds r1, r4, #0
	adds r1, #0x2e
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #2
	movs r2, #0
	movs r3, #2
	bl BtlController_EmitSetMonData
	ldrb r0, [r7]
	bl MarkBattlerForControllerExec
	ldr r1, _08055CA0
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08055CBE
	.align 2, 0
_08055C8C: .4byte 0x02023D08
_08055C90: .4byte 0x02023EAF
_08055C94: .4byte 0x02024140
_08055C98: .4byte 0x02023D28
_08055C9C: .4byte 0x02023EAC
_08055CA0: .4byte 0x02023EB8
_08055CA4:
	ldr r3, _08055CC8
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055CBE:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08055CC8: .4byte 0x02023EB8
	thumb_func_end atkEA_tryrecycleitem

	thumb_func_start atkEB_settypetoterrain
atkEB_settypetoterrain: @ 0x08055CCC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _08055D3C
	mov r8, r0
	ldr r7, _08055D40
	ldrb r0, [r7]
	movs r6, #0x58
	muls r0, r6, r0
	mov r1, r8
	adds r3, r0, r1
	movs r0, #0x21
	adds r0, r0, r3
	mov ip, r0
	ldr r5, _08055D44
	ldr r4, _08055D48
	ldrb r0, [r4]
	adds r0, r0, r5
	ldrb r2, [r0]
	mov r1, ip
	ldrb r0, [r1]
	adds r1, r2, #0
	cmp r0, r1
	beq _08055D54
	adds r0, r3, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, r1
	beq _08055D54
	mov r0, ip
	strb r2, [r0]
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r6, r1
	add r1, r8
	ldrb r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r1, #0x22
	strb r0, [r1]
	ldr r1, _08055D4C
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #3
	strb r0, [r1, #1]
	ldrb r0, [r4]
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r1, _08055D50
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08055D6E
	.align 2, 0
_08055D3C: .4byte 0x02023D28
_08055D40: .4byte 0x02023EAF
_08055D44: .4byte 0x082ECE07
_08055D48: .4byte 0x02022C94
_08055D4C: .4byte 0x02022C0C
_08055D50: .4byte 0x02023EB8
_08055D54:
	ldr r3, _08055D78
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055D6E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08055D78: .4byte 0x02023EB8
	thumb_func_end atkEB_settypetoterrain

	thumb_func_start atkEC_pursuitrelated
atkEC_pursuitrelated: @ 0x08055D7C
	push {r4, r5, r6, lr}
	ldr r5, _08055DF0
	ldrb r0, [r5]
	bl GetBattlerPosition
	movs r1, #2
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	ldr r4, _08055DF4
	strb r0, [r4]
	ldr r0, _08055DF8
	ldr r0, [r0]
	movs r6, #1
	ands r0, r6
	cmp r0, #0
	beq _08055E1C
	ldr r0, _08055DFC
	ldrb r1, [r0]
	ldr r2, _08055E00
	ldrb r3, [r4]
	lsls r0, r3, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _08055E1C
	ldr r0, _08055E04
	adds r0, r3, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _08055E1C
	ldr r1, _08055E08
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	cmp r2, #0xe4
	bne _08055E1C
	ldr r0, _08055E0C
	adds r0, r3, r0
	movs r1, #0xb
	strb r1, [r0]
	ldr r0, _08055E10
	strh r2, [r0]
	ldr r1, _08055E14
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	ldr r0, _08055E18
	strb r6, [r0, #0x18]
	ldrb r1, [r5]
	adds r0, #0x20
	strb r1, [r0]
	ldrb r0, [r4]
	strb r0, [r5]
	b _08055E36
	.align 2, 0
_08055DF0: .4byte 0x02023EAF
_08055DF4: .4byte 0x02023D08
_08055DF8: .4byte 0x02022C90
_08055DFC: .4byte 0x02023EB4
_08055E00: .4byte 0x082FACB4
_08055E04: .4byte 0x02023EC0
_08055E08: .4byte 0x02023F18
_08055E0C: .4byte 0x02023D1E
_08055E10: .4byte 0x02023E8E
_08055E14: .4byte 0x02023EB8
_08055E18: .4byte 0x02024118
_08055E1C:
	ldr r3, _08055E3C
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08055E36:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08055E3C: .4byte 0x02023EB8
	thumb_func_end atkEC_pursuitrelated

	thumb_func_start atkEF_snatchsetbattlers
atkEF_snatchsetbattlers: @ 0x08055E40
	push {r4, lr}
	ldr r1, _08055E64
	ldr r3, _08055E68
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r2, _08055E6C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r1, #0
	ldrb r1, [r2]
	cmp r0, r1
	bne _08055E74
	ldr r1, _08055E70
	ldrb r0, [r1, #0x17]
	strb r0, [r2]
	strb r0, [r3]
	b _08055E7A
	.align 2, 0
_08055E64: .4byte 0x02023EB2
_08055E68: .4byte 0x02023EAF
_08055E6C: .4byte 0x02023EB0
_08055E70: .4byte 0x02024118
_08055E74:
	ldr r1, _08055E8C
	ldrb r0, [r1, #0x17]
	strb r0, [r2]
_08055E7A:
	ldrb r0, [r4]
	strb r0, [r1, #0x17]
	ldr r1, _08055E90
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055E8C: .4byte 0x02024118
_08055E90: .4byte 0x02023EB8
	thumb_func_end atkEF_snatchsetbattlers

	thumb_func_start atkEE_removelightscreenreflect
atkEE_removelightscreenreflect: @ 0x08055E94
	push {r4, lr}
	ldr r0, _08055EDC
	ldrb r0, [r0]
	bl GetBattlerSide
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08055EE0
	lsls r3, r0, #1
	adds r0, r3, r0
	lsls r0, r0, #2
	adds r4, r0, r1
	ldrb r0, [r4]
	cmp r0, #0
	bne _08055EBC
	ldrb r1, [r4, #2]
	cmp r1, #0
	beq _08055EF4
_08055EBC:
	ldr r2, _08055EE4
	adds r2, r3, r2
	ldrh r1, [r2]
	ldr r0, _08055EE8
	ands r0, r1
	movs r3, #0
	ldr r1, _08055EEC
	ands r0, r1
	strh r0, [r2]
	strb r3, [r4]
	strb r3, [r4, #2]
	ldr r1, _08055EF0
	movs r0, #1
	strb r0, [r1, #0x18]
	strb r0, [r1, #0x19]
	b _08055EFA
	.align 2, 0
_08055EDC: .4byte 0x02023EAF
_08055EE0: .4byte 0x02023F38
_08055EE4: .4byte 0x02023F32
_08055EE8: .4byte 0x0000FFFE
_08055EEC: .4byte 0x0000FFFD
_08055EF0: .4byte 0x02024118
_08055EF4:
	ldr r0, _08055F08
	strb r1, [r0, #0x18]
	strb r1, [r0, #0x19]
_08055EFA:
	ldr r1, _08055F0C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08055F08: .4byte 0x02024118
_08055F0C: .4byte 0x02023EB8
	thumb_func_end atkEE_removelightscreenreflect

	thumb_func_start atkEF_handleballthrow
atkEF_handleballthrow: @ 0x08055F10
	push {r4, r5, r6, lr}
	movs r4, #0
	ldr r0, _08055F50
	ldr r0, [r0]
	cmp r0, #0
	beq _08055F1E
	b _080562A6
_08055F1E:
	ldr r5, _08055F54
	ldr r0, _08055F58
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r6, _08055F5C
	movs r1, #1
	eors r0, r1
	strb r0, [r6]
	ldr r0, _08055F60
	ldr r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08055F6C
	movs r0, #0
	movs r1, #5
	bl BtlController_EmitBallThrowAnim
	ldrb r0, [r5]
	bl MarkBattlerForControllerExec
	ldr r1, _08055F64
	ldr r0, _08055F68
	b _080562A4
	.align 2, 0
_08055F50: .4byte 0x02023D0C
_08055F54: .4byte 0x02023D08
_08055F58: .4byte 0x02023EAF
_08055F5C: .4byte 0x02023EB0
_08055F60: .4byte 0x02022C90
_08055F64: .4byte 0x02023EB8
_08055F68: .4byte 0x0828A38A
_08055F6C:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r1, r0
	cmp r1, #0
	beq _08055F94
	movs r0, #0
	movs r1, #4
	bl BtlController_EmitBallThrowAnim
	ldrb r0, [r5]
	bl MarkBattlerForControllerExec
	ldr r1, _08055F8C
	ldr r0, _08055F90
	b _080562A4
	.align 2, 0
_08055F8C: .4byte 0x02023EB8
_08055F90: .4byte 0x0828A352
_08055F94:
	ldr r0, _08055FB8
	ldrh r0, [r0]
	cmp r0, #5
	bne _08055FC0
	ldr r0, _08055FBC
	ldr r0, [r0]
	adds r0, #0x7c
	ldrb r0, [r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r0, r1, #8
	subs r0, r0, r1
	movs r1, #0x64
	bl __divsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08055FD8
	.align 2, 0
_08055FB8: .4byte 0x02023EAC
_08055FBC: .4byte 0x02024140
_08055FC0:
	ldr r3, _08055FF4
	ldr r2, _08055FF8
	ldrb r1, [r6]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r1, [r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r5, [r0, #8]
_08055FD8:
	ldr r2, _08055FFC
	ldrh r0, [r2]
	cmp r0, #5
	bhi _08055FE2
	b _080560D8
_08055FE2:
	subs r0, #6
	cmp r0, #6
	bls _08055FEA
	b _080560E2
_08055FEA:
	lsls r0, r0, #2
	ldr r1, _08056000
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08055FF4: .4byte 0x082F0D54
_08055FF8: .4byte 0x02023D28
_08055FFC: .4byte 0x02023EAC
_08056000: .4byte 0x08056004
_08056004: @ jump table
	.4byte _08056020 @ case 0
	.4byte _08056050 @ case 1
	.4byte _08056062 @ case 2
	.4byte _08056090 @ case 3
	.4byte _080560C0 @ case 4
	.4byte _08056082 @ case 5
	.4byte _08056082 @ case 6
_08056020:
	ldr r2, _08056048
	ldr r0, _0805604C
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	adds r1, r0, #0
	adds r1, #0x21
	ldrb r1, [r1]
	cmp r1, #0xb
	beq _080560B4
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _080560B4
	cmp r1, #6
	beq _080560B4
	cmp r0, #6
	beq _080560B4
	b _08056082
	.align 2, 0
_08056048: .4byte 0x02023D28
_0805604C: .4byte 0x02023EB0
_08056050:
	bl GetCurrentMapType
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r4, #0xa
	cmp r0, #5
	bne _080560E2
	movs r4, #0x23
	b _080560E2
_08056062:
	ldr r2, _08056088
	ldr r0, _0805608C
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0x2a
	ldrb r1, [r0]
	cmp r1, #0x27
	bhi _08056082
	movs r0, #0x28
	subs r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #9
	bhi _080560E2
_08056082:
	movs r4, #0xa
	b _080560E2
	.align 2, 0
_08056088: .4byte 0x02023D28
_0805608C: .4byte 0x02023EB0
_08056090:
	ldr r2, _080560B8
	ldr r0, _080560BC
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r0, [r0]
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	movs r4, #0xa
	cmp r0, #0
	beq _080560E2
_080560B4:
	movs r4, #0x1e
	b _080560E2
	.align 2, 0
_080560B8: .4byte 0x02023D28
_080560BC: .4byte 0x02023EB0
_080560C0:
	ldr r0, _080560D4
	ldrb r0, [r0, #0x13]
	adds r0, #0xa
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0x28
	bls _080560E2
	movs r4, #0x28
	b _080560E2
	.align 2, 0
_080560D4: .4byte 0x03005A70
_080560D8:
	ldr r1, _0805614C
	ldrh r0, [r2]
	subs r0, #2
	adds r0, r0, r1
	ldrb r4, [r0]
_080560E2:
	adds r0, r5, #0
	muls r0, r4, r0
	movs r1, #0xa
	bl __divsi3
	ldr r5, _08056150
	ldr r1, _08056154
	ldrb r2, [r1]
	movs r1, #0x58
	adds r4, r2, #0
	muls r4, r1, r4
	adds r3, r4, r5
	ldrh r2, [r3, #0x2c]
	lsls r1, r2, #1
	adds r1, r1, r2
	ldrh r2, [r3, #0x28]
	lsls r2, r2, #1
	subs r2, r1, r2
	muls r0, r2, r0
	bl __divsi3
	adds r6, r0, #0
	adds r5, #0x4c
	adds r4, r4, r5
	ldr r4, [r4]
	movs r0, #0x27
	ands r0, r4
	cmp r0, #0
	beq _0805611E
	lsls r6, r6, #1
_0805611E:
	movs r0, #0xd8
	ands r4, r0
	cmp r4, #0
	beq _08056132
	lsls r0, r6, #4
	subs r0, r0, r6
	movs r1, #0xa
	bl __udivsi3
	adds r6, r0, #0
_08056132:
	ldr r1, _08056158
	ldrh r0, [r1]
	cmp r0, #5
	beq _08056174
	cmp r0, #1
	bne _08056160
	ldr r0, _0805615C
	ldrb r1, [r0, #5]
	movs r2, #2
	orrs r1, r2
	strb r1, [r0, #5]
	b _08056174
	.align 2, 0
_0805614C: .4byte 0x082ECE11
_08056150: .4byte 0x02023D28
_08056154: .4byte 0x02023EB0
_08056158: .4byte 0x02023EAC
_0805615C: .4byte 0x03005A70
_08056160:
	ldr r0, _080561B8
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r0, #0
	adds r1, #0x34
	ldrb r0, [r1]
	cmp r0, #0xfe
	bhi _08056174
	adds r0, #1
	strb r0, [r1]
_08056174:
	cmp r6, #0xfe
	bls _080561D8
	movs r0, #0
	movs r1, #4
	bl BtlController_EmitBallThrowAnim
	ldr r0, _080561BC
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	ldr r1, _080561C0
	ldr r0, _080561C4
	str r0, [r1]
	ldr r1, _080561C8
	ldr r0, _080561CC
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _080561D0
	adds r0, r0, r1
	ldr r2, _080561D4
	movs r1, #0x26
	bl SetMonData
	bl CalculatePlayerPartyCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	beq _08056266
	b _08056290
	.align 2, 0
_080561B8: .4byte 0x03005A70
_080561BC: .4byte 0x02023D08
_080561C0: .4byte 0x02023EB8
_080561C4: .4byte 0x0828A30C
_080561C8: .4byte 0x02023D12
_080561CC: .4byte 0x02023EB0
_080561D0: .4byte 0x020243E8
_080561D4: .4byte 0x02023EAC
_080561D8:
	movs r0, #0xff
	lsls r0, r0, #0x10
	adds r1, r6, #0
	bl __udivsi3
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _08056200
	adds r1, r6, #0
	bl __udivsi3
	adds r6, r0, #0
	movs r4, #0
	b _0805620A
	.align 2, 0
_08056200: .4byte 0x000FFFF0
_08056204:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0805620A:
	cmp r4, #3
	bhi _0805621A
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r6
	blo _08056204
_0805621A:
	ldr r5, _08056270
	ldrh r0, [r5]
	cmp r0, #1
	bne _08056224
	movs r4, #4
_08056224:
	movs r0, #0
	adds r1, r4, #0
	bl BtlController_EmitBallThrowAnim
	ldr r0, _08056274
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	cmp r4, #4
	bne _0805629C
	ldr r1, _08056278
	ldr r0, _0805627C
	str r0, [r1]
	ldr r1, _08056280
	ldr r0, _08056284
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _08056288
	adds r0, r0, r1
	movs r1, #0x26
	adds r2, r5, #0
	bl SetMonData
	bl CalculatePlayerPartyCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08056290
_08056266:
	ldr r1, _0805628C
	movs r0, #0
	strb r0, [r1, #5]
	b _080562A6
	.align 2, 0
_08056270: .4byte 0x02023EAC
_08056274: .4byte 0x02023D08
_08056278: .4byte 0x02023EB8
_0805627C: .4byte 0x0828A30C
_08056280: .4byte 0x02023D12
_08056284: .4byte 0x02023EB0
_08056288: .4byte 0x020243E8
_0805628C: .4byte 0x02023FD6
_08056290:
	ldr r1, _08056298
	movs r0, #1
	strb r0, [r1, #5]
	b _080562A6
	.align 2, 0
_08056298: .4byte 0x02023FD6
_0805629C:
	ldr r0, _080562AC
	strb r4, [r0, #5]
	ldr r1, _080562B0
	ldr r0, _080562B4
_080562A4:
	str r0, [r1]
_080562A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080562AC: .4byte 0x02023FD6
_080562B0: .4byte 0x02023EB8
_080562B4: .4byte 0x0828A35C
	thumb_func_end atkEF_handleballthrow

	thumb_func_start atkF0_givecaughtmon
atkF0_givecaughtmon: @ 0x080562B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _08056328
	mov sb, r0
	ldr r5, _0805632C
	ldrb r0, [r5]
	movs r6, #1
	eors r0, r6
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	movs r7, #0x64
	muls r0, r7, r0
	ldr r1, _08056330
	mov r8, r1
	add r0, r8
	bl GiveMonToPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080563A2
	bl sub_0813B254
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _08056344
	ldr r0, _08056334
	strb r1, [r0, #5]
	ldr r4, _08056338
	ldr r0, _0805633C
	bl VarGet
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBoxNamePtr
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldrb r0, [r5]
	eors r0, r6
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	muls r0, r7, r0
	add r0, r8
	ldr r2, _08056340
	movs r1, #2
	bl GetMonData3
	b _0805638E
	.align 2, 0
_08056328: .4byte 0x02023D12
_0805632C: .4byte 0x02023EAF
_08056330: .4byte 0x020243E8
_08056334: .4byte 0x02023FD6
_08056338: .4byte 0x02021C40
_0805633C: .4byte 0x00004036
_08056340: .4byte 0x02021C54
_08056344:
	ldr r4, _08056434
	ldr r0, _08056438
	bl VarGet
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBoxNamePtr
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldrb r0, [r5]
	eors r0, r6
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	muls r0, r7, r0
	add r0, r8
	ldr r2, _0805643C
	movs r1, #2
	bl GetMonData3
	ldr r4, _08056440
	bl get_unknown_box_id
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBoxNamePtr
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldr r1, _08056444
	movs r0, #2
	strb r0, [r1, #5]
_0805638E:
	ldr r0, _08056448
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080563A2
	ldr r1, _08056444
	ldrb r0, [r1, #5]
	adds r0, #1
	strb r0, [r1, #5]
_080563A2:
	ldr r0, _0805644C
	mov sl, r0
	ldr r1, _08056450
	mov sb, r1
	ldrb r0, [r1]
	movs r4, #1
	eors r0, r4
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	movs r1, #0x64
	mov r8, r1
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	ldr r6, _08056454
	adds r0, r0, r6
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	ldr r5, _08056458
	strh r0, [r5, #0x28]
	mov r1, sb
	ldrb r0, [r1]
	eors r0, r4
	lsls r0, r0, #1
	add r0, sl
	ldrh r0, [r0]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	adds r2, r5, #0
	adds r2, #0x2a
	movs r1, #2
	bl GetMonData3
	mov r1, sb
	ldrb r0, [r1]
	eors r4, r0
	lsls r4, r4, #1
	add r4, sl
	ldrh r0, [r4]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r0, r6
	movs r1, #0x26
	movs r2, #0
	bl GetMonData3
	movs r1, #0xf
	ands r0, r1
	lsls r0, r0, #2
	ldrb r2, [r5, #5]
	movs r1, #0x3d
	rsbs r1, r1, #0
	ands r1, r2
	orrs r1, r0
	strb r1, [r5, #5]
	ldr r1, _0805645C
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08056434: .4byte 0x02021C40
_08056438: .4byte 0x00004036
_0805643C: .4byte 0x02021C54
_08056440: .4byte 0x02021C68
_08056444: .4byte 0x02023FD6
_08056448: .4byte 0x000008AB
_0805644C: .4byte 0x02023D12
_08056450: .4byte 0x02023EAF
_08056454: .4byte 0x020243E8
_08056458: .4byte 0x03005A70
_0805645C: .4byte 0x02023EB8
	thumb_func_end atkF0_givecaughtmon

	thumb_func_start atkF1_trysetcaughtmondexflags
atkF1_trysetcaughtmondexflags: @ 0x08056460
	push {r4, r5, lr}
	ldr r4, _080564B0
	adds r0, r4, #0
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl GetMonData3
	adds r4, r0, #0
	adds r0, r5, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080564B8
	ldr r3, _080564B4
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
	b _080564D2
	.align 2, 0
_080564B0: .4byte 0x020243E8
_080564B4: .4byte 0x02023EB8
_080564B8:
	adds r0, r5, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	adds r2, r4, #0
	bl HandleSetPokedexFlag
	ldr r1, _080564D8
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
_080564D2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080564D8: .4byte 0x02023EB8
	thumb_func_end atkF1_trysetcaughtmondexflags

	thumb_func_start atkF2_displaydexinfo
atkF2_displaydexinfo: @ 0x080564DC
	push {r4, lr}
	sub sp, #4
	ldr r0, _08056504
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _08056508
	ldrb r0, [r0]
	cmp r0, #5
	bls _080564F8
	b _0805663C
_080564F8:
	lsls r0, r0, #2
	ldr r1, _0805650C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08056504: .4byte 0x020243E8
_08056508: .4byte 0x02023FD6
_0805650C: .4byte 0x08056510
_08056510: @ jump table
	.4byte _08056528 @ case 0
	.4byte _0805653A @ case 1
	.4byte _08056588 @ case 2
	.4byte _080565D8 @ case 3
	.4byte _080565F0 @ case 4
	.4byte _08056628 @ case 5
_08056528:
	movs r0, #1
	rsbs r0, r0, #0
	movs r1, #0
	str r1, [sp]
	movs r2, #0
	movs r3, #0x10
	bl BeginNormalPaletteFade
	b _08056616
_0805653A:
	ldr r0, _08056578
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08056548
	b _0805663C
_08056548:
	bl FreeAllWindowBuffers
	adds r0, r4, #0
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _0805657C
	ldr r1, _08056580
	ldrb r2, [r1]
	movs r1, #0x58
	muls r2, r1, r2
	adds r1, r3, #0
	adds r1, #0x54
	adds r1, r2, r1
	ldr r1, [r1]
	adds r3, #0x48
	adds r2, r2, r3
	ldr r2, [r2]
	bl CreateDexDisplayMonDataTask
	ldr r1, _08056584
	strb r0, [r1, #1]
	b _08056618
	.align 2, 0
_08056578: .4byte 0x02037C74
_0805657C: .4byte 0x02023D28
_08056580: .4byte 0x02023EB0
_08056584: .4byte 0x02023FD6
_08056588:
	ldr r0, _080565C0
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0805663C
	ldr r0, _080565C4
	ldr r1, [r0, #4]
	ldr r0, _080565C8
	cmp r1, r0
	bne _0805663C
	ldr r2, _080565CC
	ldr r4, _080565D0
	ldrb r1, [r4, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r2
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0805663C
	ldr r0, _080565D4
	bl SetVBlankCallback
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	b _0805663C
	.align 2, 0
_080565C0: .4byte 0x02037C74
_080565C4: .4byte 0x03002360
_080565C8: .4byte 0x080380FD
_080565CC: .4byte 0x03005B60
_080565D0: .4byte 0x02023FD6
_080565D4: .4byte 0x080386DD
_080565D8:
	bl InitBattleBgsVideo
	bl LoadBattleTextboxAndBackground
	ldr r1, _080565EC
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	b _08056616
	.align 2, 0
_080565EC: .4byte 0x02022AD4
_080565F0:
	bl IsDma3ManagerBusyWithBgCopy
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0805663C
	ldr r0, _08056620
	str r1, [sp]
	movs r1, #0
	movs r2, #0x10
	movs r3, #0
	bl BeginNormalPaletteFade
	movs r0, #0
	bl ShowBg
	movs r0, #3
	bl ShowBg
_08056616:
	ldr r1, _08056624
_08056618:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0805663C
	.align 2, 0
_08056620: .4byte 0x0000FFFF
_08056624: .4byte 0x02023FD6
_08056628:
	ldr r0, _08056644
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0805663C
	ldr r1, _08056648
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0805663C:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08056644: .4byte 0x02037C74
_08056648: .4byte 0x02023EB8
	thumb_func_end atkF2_displaydexinfo

	thumb_func_start HandleBattleWindow
HandleBattleWindow: @ 0x0805664C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	ldr r4, [sp, #0x40]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #0x10]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp, #0x1c]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp, #0x14]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	mov sl, r4
	movs r1, #0
	add r0, sp, #0xc
	strh r1, [r0]
	ldr r6, [sp, #0x10]
	cmp r6, r3
	ble _08056686
	b _08056772
_08056686:
	mov r4, r8
	adds r0, r6, #1
	str r0, [sp, #0x18]
	ldr r2, [sp, #0x1c]
	cmp r4, r2
	bgt _08056768
	add r5, sp, #0xc
	lsls r7, r6, #0x18
	mov sb, r7
_08056698:
	ldr r0, [sp, #0x10]
	cmp r6, r0
	bne _080566C4
	cmp r4, r8
	bne _080566AC
	ldr r0, _080566A8
	b _0805670E
	.align 2, 0
_080566A8: .4byte 0x00001022
_080566AC:
	ldr r2, [sp, #0x1c]
	cmp r4, r2
	bne _080566BC
	ldr r0, _080566B8
	b _0805670E
	.align 2, 0
_080566B8: .4byte 0x00001024
_080566BC:
	ldr r0, _080566C0
	b _0805670E
	.align 2, 0
_080566C0: .4byte 0x00001023
_080566C4:
	ldr r7, [sp, #0x14]
	cmp r6, r7
	bne _080566F0
	cmp r4, r8
	bne _080566D8
	ldr r0, _080566D4
	b _0805670E
	.align 2, 0
_080566D4: .4byte 0x00001028
_080566D8:
	ldr r0, [sp, #0x1c]
	cmp r4, r0
	bne _080566E8
	ldr r0, _080566E4
	b _0805670E
	.align 2, 0
_080566E4: .4byte 0x0000102A
_080566E8:
	ldr r0, _080566EC
	b _0805670E
	.align 2, 0
_080566EC: .4byte 0x00001029
_080566F0:
	cmp r4, r8
	bne _080566FC
	ldr r0, _080566F8
	b _0805670E
	.align 2, 0
_080566F8: .4byte 0x00001025
_080566FC:
	ldr r2, [sp, #0x1c]
	cmp r4, r2
	bne _0805670C
	ldr r0, _08056708
	b _0805670E
	.align 2, 0
_08056708: .4byte 0x00001027
_0805670C:
	ldr r0, _08056744
_0805670E:
	strh r0, [r5]
	movs r1, #1
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _0805671E
	movs r0, #0
	strh r0, [r5]
_0805671E:
	movs r0, #0x80
	mov r7, sl
	ands r0, r7
	cmp r0, #0
	beq _08056748
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #1
	add r1, sp, #0xc
	mov r7, sb
	lsrs r3, r7, #0x18
	bl CopyToBgTilemapBufferRect_ChangePalette
	b _08056760
	.align 2, 0
_08056744: .4byte 0x00001026
_08056748:
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	str r1, [sp]
	str r1, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	add r1, sp, #0xc
	mov r7, sb
	lsrs r3, r7, #0x18
	bl CopyToBgTilemapBufferRect_ChangePalette
_08056760:
	adds r4, #1
	ldr r0, [sp, #0x1c]
	cmp r4, r0
	ble _08056698
_08056768:
	ldr r6, [sp, #0x18]
	ldr r2, [sp, #0x14]
	cmp r6, r2
	bgt _08056772
	b _08056686
_08056772:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end HandleBattleWindow

	thumb_func_start BattleCreateYesNoCursorAt
BattleCreateYesNoCursorAt: @ 0x08056784
	push {lr}
	sub sp, #0x10
	adds r3, r0, #0
	add r0, sp, #0xc
	movs r2, #1
	strh r2, [r0]
	movs r1, #2
	strh r1, [r0, #2]
	lsls r3, r3, #0x19
	movs r0, #0x90
	lsls r0, r0, #0x14
	adds r3, r3, r0
	lsrs r3, r3, #0x18
	str r2, [sp]
	str r1, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	add r1, sp, #0xc
	movs r2, #0x19
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	add sp, #0x10
	pop {r0}
	bx r0
	thumb_func_end BattleCreateYesNoCursorAt

	thumb_func_start BattleDestroyYesNoCursorAt
BattleDestroyYesNoCursorAt: @ 0x080567BC
	push {lr}
	sub sp, #0x10
	adds r3, r0, #0
	add r0, sp, #0xc
	ldr r1, _080567F8
	strh r1, [r0]
	strh r1, [r0, #2]
	lsls r3, r3, #0x19
	movs r0, #0x90
	lsls r0, r0, #0x14
	adds r3, r3, r0
	lsrs r3, r3, #0x18
	movs r0, #1
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #0
	add r1, sp, #0xc
	movs r2, #0x19
	bl CopyToBgTilemapBufferRect_ChangePalette
	movs r0, #0
	bl CopyBgTilemapBufferToVram
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_080567F8: .4byte 0x00001016
	thumb_func_end BattleDestroyYesNoCursorAt

	thumb_func_start atkF3_trygivecaughtmonnick
atkF3_trygivecaughtmonnick: @ 0x080567FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	ldr r0, _08056820
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #4
	bls _08056814
	b _08056A72
_08056814:
	lsls r0, r1, #2
	ldr r1, _08056824
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08056820: .4byte 0x02023FD6
_08056824: .4byte 0x08056828
_08056828: @ jump table
	.4byte _0805683C @ case 0
	.4byte _08056870 @ case 1
	.4byte _0805690C @ case 2
	.4byte _080569E4 @ case 3
	.4byte _08056A3C @ case 4
_0805683C:
	movs r4, #0
	str r4, [sp]
	movs r0, #0x18
	movs r1, #8
	movs r2, #0x1d
	movs r3, #0xd
	bl HandleBattleWindow
	ldr r0, _08056868
	movs r1, #0xc
	bl sub_0814FA04
	ldr r1, _0805686C
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	strb r4, [r1, #1]
	movs r0, #0
	bl BattleCreateYesNoCursorAt
	b _08056A72
	.align 2, 0
_08056868: .4byte 0x085ABBC9
_0805686C: .4byte 0x02023FD6
_08056870:
	ldr r0, _080568E8
	ldrh r1, [r0, #0x2e]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08056896
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08056896
	movs r0, #5
	bl PlaySE
	ldrb r0, [r4, #1]
	bl BattleDestroyYesNoCursorAt
	movs r0, #0
	strb r0, [r4, #1]
	bl BattleCreateYesNoCursorAt
_08056896:
	ldr r0, _080568E8
	ldrh r1, [r0, #0x2e]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _080568BE
	ldr r4, _080568EC
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _080568BE
	movs r0, #5
	bl PlaySE
	ldrb r0, [r4, #1]
	bl BattleDestroyYesNoCursorAt
	movs r0, #1
	strb r0, [r4, #1]
	bl BattleCreateYesNoCursorAt
_080568BE:
	ldr r0, _080568E8
	ldrh r1, [r0, #0x2e]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080568F0
	movs r0, #5
	bl PlaySE
	ldr r1, _080568EC
	ldrb r0, [r1, #1]
	cmp r0, #0
	bne _08056902
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r0, #3
	bl BeginFastPaletteFade
	b _08056A72
	.align 2, 0
_080568E8: .4byte 0x03002360
_080568EC: .4byte 0x02023FD6
_080568F0:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080568FA
	b _08056A72
_080568FA:
	movs r0, #5
	bl PlaySE
	ldr r1, _08056908
_08056902:
	movs r0, #4
	strb r0, [r1]
	b _08056A72
	.align 2, 0
_08056908: .4byte 0x02023FD6
_0805690C:
	ldr r0, _080569C8
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0805691A
	b _08056A72
_0805691A:
	ldr r7, _080569CC
	ldr r0, _080569D0
	mov sl, r0
	ldrb r0, [r0]
	movs r4, #1
	eors r0, r4
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	movs r1, #0x64
	mov sb, r1
	mov r2, sb
	muls r2, r0, r2
	adds r0, r2, #0
	ldr r1, _080569D4
	mov r8, r1
	add r0, r8
	ldr r1, _080569D8
	ldr r2, [r1]
	adds r2, #0x6d
	movs r1, #2
	bl GetMonData3
	bl FreeAllWindowBuffers
	mov r2, sl
	ldrb r0, [r2]
	eors r0, r4
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, r8
	movs r1, #0xb
	bl GetMonData3
	adds r6, r0, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r2, sl
	ldrb r0, [r2]
	eors r0, r4
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, r8
	bl GetMonGender
	adds r5, r0, #0
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	mov r2, sl
	ldrb r0, [r2]
	eors r4, r0
	lsls r4, r4, #1
	adds r4, r4, r7
	ldrh r0, [r4]
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	add r0, r8
	movs r1, #0
	movs r2, #0
	bl GetMonData3
	ldr r2, _080569D8
	ldr r1, [r2]
	adds r1, #0x6d
	str r0, [sp]
	ldr r0, _080569DC
	str r0, [sp, #4]
	movs r0, #2
	adds r2, r6, #0
	adds r3, r5, #0
	bl DoNamingScreen
	ldr r1, _080569E0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08056A72
	.align 2, 0
_080569C8: .4byte 0x02037C74
_080569CC: .4byte 0x02023D12
_080569D0: .4byte 0x02023EAF
_080569D4: .4byte 0x020243E8
_080569D8: .4byte 0x02024140
_080569DC: .4byte 0x080380FD
_080569E0: .4byte 0x02023FD6
_080569E4:
	ldr r0, _08056A20
	ldr r1, [r0, #4]
	ldr r0, _08056A24
	cmp r1, r0
	bne _08056A72
	ldr r0, _08056A28
	ldrb r1, [r0, #7]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08056A72
	ldr r2, _08056A2C
	ldr r0, _08056A30
	ldrb r1, [r0]
	movs r0, #1
	eors r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _08056A34
	adds r0, r0, r1
	ldr r1, _08056A38
	ldr r2, [r1]
	adds r2, #0x6d
	movs r1, #2
	bl SetMonData
	b _08056A58
	.align 2, 0
_08056A20: .4byte 0x03002360
_08056A24: .4byte 0x080380FD
_08056A28: .4byte 0x02037C74
_08056A2C: .4byte 0x02023D12
_08056A30: .4byte 0x02023EAF
_08056A34: .4byte 0x020243E8
_08056A38: .4byte 0x02024140
_08056A3C:
	bl CalculatePlayerPartyCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08056A58
	ldr r1, _08056A54
	ldr r0, [r1]
	adds r0, #5
	str r0, [r1]
	b _08056A72
	.align 2, 0
_08056A54: .4byte 0x02023EB8
_08056A58:
	ldr r3, _08056A84
	ldr r2, [r3]
	ldrb r1, [r2, #1]
	ldrb r0, [r2, #2]
	lsls r0, r0, #8
	orrs r1, r0
	ldrb r0, [r2, #3]
	lsls r0, r0, #0x10
	orrs r1, r0
	ldrb r0, [r2, #4]
	lsls r0, r0, #0x18
	orrs r1, r0
	str r1, [r3]
_08056A72:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08056A84: .4byte 0x02023EB8
	thumb_func_end atkF3_trygivecaughtmonnick

	thumb_func_start atkF4_subattackerhpbydmg
atkF4_subattackerhpbydmg: @ 0x08056A88
	ldr r2, _08056AA8
	ldr r0, _08056AAC
	ldrb r1, [r0]
	movs r0, #0x58
	muls r1, r0, r1
	adds r1, r1, r2
	ldr r0, _08056AB0
	ldr r2, [r0]
	ldrh r0, [r1, #0x28]
	subs r0, r0, r2
	strh r0, [r1, #0x28]
	ldr r1, _08056AB4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_08056AA8: .4byte 0x02023D28
_08056AAC: .4byte 0x02023EAF
_08056AB0: .4byte 0x02023E94
_08056AB4: .4byte 0x02023EB8
	thumb_func_end atkF4_subattackerhpbydmg

	thumb_func_start atkF5_removeattackerstatus1
atkF5_removeattackerstatus1: @ 0x08056AB8
	ldr r1, _08056AD4
	ldr r0, _08056AD8
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x4c
	adds r0, r0, r1
	movs r1, #0
	str r1, [r0]
	ldr r1, _08056ADC
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	bx lr
	.align 2, 0
_08056AD4: .4byte 0x02023D28
_08056AD8: .4byte 0x02023EAF
_08056ADC: .4byte 0x02023EB8
	thumb_func_end atkF5_removeattackerstatus1

	thumb_func_start atkF6_finishaction
atkF6_finishaction: @ 0x08056AE0
	ldr r1, _08056AE8
	movs r0, #0xc
	strb r0, [r1]
	bx lr
	.align 2, 0
_08056AE8: .4byte 0x02023D27
	thumb_func_end atkF6_finishaction

	thumb_func_start atkF7_finishturn
atkF7_finishturn: @ 0x08056AEC
	ldr r1, _08056AFC
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _08056B00
	ldr r0, _08056B04
	ldrb r0, [r0]
	strb r0, [r1]
	bx lr
	.align 2, 0
_08056AFC: .4byte 0x02023D27
_08056B00: .4byte 0x02023D26
_08056B04: .4byte 0x02023D10
	thumb_func_end atkF7_finishturn

	thumb_func_start atkF8_trainerslideout
atkF8_trainerslideout: @ 0x08056B08
	push {r4, r5, lr}
	ldr r5, _08056B30
	ldr r0, [r5]
	ldrb r0, [r0, #1]
	bl GetBattlerAtPosition
	ldr r4, _08056B34
	strb r0, [r4]
	movs r0, #0
	bl BtlController_EmitTrainerSlideBack
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r0, [r5]
	adds r0, #2
	str r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08056B30: .4byte 0x02023EB8
_08056B34: .4byte 0x02023D08
	thumb_func_end atkF8_trainerslideout
