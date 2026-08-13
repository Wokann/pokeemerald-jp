.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleIntroPlayer2SendsOutMonAnimation
BattleIntroPlayer2SendsOutMonAnimation: @ 0x0803B070
	push {r4, r5, lr}
	ldr r0, _0803B0F4
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r0, r1
	cmp r0, #0
	beq _0803B090
	movs r0, #0x80
	lsls r0, r0, #0x12
	ands r0, r1
	cmp r0, #0
	beq _0803B090
	movs r5, #3
	cmp r1, #0
	bge _0803B092
_0803B090:
	movs r5, #2
_0803B092:
	ldr r1, _0803B0F8
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0803B0FC
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803B0CE
	adds r4, r1, #0
_0803B0A2:
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	bne _0803B0BC
	movs r0, #0
	bl BtlController_EmitIntroTrainerBallThrow
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_0803B0BC:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _0803B0FC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803B0A2
_0803B0CE:
	ldr r2, _0803B100
	ldr r0, [r2]
	adds r0, #0x4c
	movs r1, #0
	strb r1, [r0]
	ldr r0, [r2]
	adds r0, #0xd9
	strb r1, [r0]
	ldr r0, [r2]
	movs r2, #0xd1
	lsls r2, r2, #1
	adds r0, r0, r2
	strb r1, [r0]
	ldr r1, _0803B104
	ldr r0, _0803B108
	str r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803B0F4: .4byte 0x02022C90
_0803B0F8: .4byte 0x02023D08
_0803B0FC: .4byte 0x02023D10
_0803B100: .4byte 0x02024140
_0803B104: .4byte 0x03005A64
_0803B108: .4byte 0x0803B26D
	thumb_func_end BattleIntroPlayer2SendsOutMonAnimation
