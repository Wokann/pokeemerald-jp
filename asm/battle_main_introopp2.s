.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleIntroOpponent2SendsOutMonAnimation
BattleIntroOpponent2SendsOutMonAnimation: @ 0x0803AE20
	push {r4, r5, lr}
	ldr r0, _0803AE8C
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r0, r1
	cmp r0, #0
	beq _0803AE40
	movs r0, #0x80
	lsls r0, r0, #0x12
	ands r0, r1
	cmp r0, #0
	beq _0803AE40
	movs r5, #2
	cmp r1, #0
	bge _0803AE42
_0803AE40:
	movs r5, #3
_0803AE42:
	ldr r1, _0803AE90
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0803AE94
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803AE7E
	adds r4, r1, #0
_0803AE52:
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	bne _0803AE6C
	movs r0, #0
	bl BtlController_EmitIntroTrainerBallThrow
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_0803AE6C:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _0803AE94
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803AE52
_0803AE7E:
	ldr r1, _0803AE98
	ldr r0, _0803AE9C
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803AE8C: .4byte 0x02022C90
_0803AE90: .4byte 0x02023D08
_0803AE94: .4byte 0x02023D10
_0803AE98: .4byte 0x03005A64
_0803AE9C: .4byte 0x0803AF59
	thumb_func_end BattleIntroOpponent2SendsOutMonAnimation
