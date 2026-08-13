.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleIntroPlayer1SendsOutMonAnimation
BattleIntroPlayer1SendsOutMonAnimation: @ 0x0803B10C
	push {r4, r5, r6, lr}
	ldr r0, _0803B130
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r0, r1
	cmp r0, #0
	beq _0803B144
	movs r0, #0x80
	lsls r0, r0, #0x12
	ands r0, r1
	cmp r0, #0
	beq _0803B144
	movs r6, #1
	cmp r1, #0
	bge _0803B146
	b _0803B144
	.align 2, 0
_0803B130: .4byte 0x02022C90
_0803B134:
	ldr r1, _0803B13C
	ldr r0, _0803B140
	b _0803B1B6
	.align 2, 0
_0803B13C: .4byte 0x03005A64
_0803B140: .4byte 0x0803B071
_0803B144:
	movs r6, #0
_0803B146:
	ldr r0, _0803B1C0
	ldr r2, [r0]
	cmp r2, #0
	bne _0803B1B8
	ldr r0, _0803B1C4
	strb r2, [r0]
	ldr r1, _0803B1C8
	adds r4, r0, #0
	ldrb r1, [r1]
	cmp r2, r1
	bhs _0803B198
	adds r5, r4, #0
_0803B15E:
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r6
	bne _0803B184
	movs r0, #0
	bl BtlController_EmitIntroTrainerBallThrow
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r0, _0803B1CC
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0803B134
_0803B184:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r1, _0803B1C8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r4, _0803B1C4
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803B15E
_0803B198:
	ldr r2, _0803B1D0
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
	ldr r1, _0803B1D4
	ldr r0, _0803B1D8
_0803B1B6:
	str r0, [r1]
_0803B1B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803B1C0: .4byte 0x02023D0C
_0803B1C4: .4byte 0x02023D08
_0803B1C8: .4byte 0x02023D10
_0803B1CC: .4byte 0x02022C90
_0803B1D0: .4byte 0x02024140
_0803B1D4: .4byte 0x03005A64
_0803B1D8: .4byte 0x0803B26D
	thumb_func_end BattleIntroPlayer1SendsOutMonAnimation
