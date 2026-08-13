.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleIntroPrintTrainerWantsToBattle
BattleIntroPrintTrainerWantsToBattle: @ 0x0803AD64
	push {lr}
	ldr r0, _0803AD8C
	ldr r0, [r0]
	cmp r0, #0
	bne _0803AD86
	movs r0, #1
	bl GetBattlerAtPosition
	ldr r1, _0803AD90
	strb r0, [r1]
	ldrb r1, [r1]
	movs r0, #0
	bl PrepareStringBattle
	ldr r1, _0803AD94
	ldr r0, _0803AD98
	str r0, [r1]
_0803AD86:
	pop {r0}
	bx r0
	.align 2, 0
_0803AD8C: .4byte 0x02023D0C
_0803AD90: .4byte 0x02023D08
_0803AD94: .4byte 0x03005A64
_0803AD98: .4byte 0x0803ADC5
	thumb_func_end BattleIntroPrintTrainerWantsToBattle
