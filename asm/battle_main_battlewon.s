.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

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
