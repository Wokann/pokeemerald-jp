.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start BattleIntroOpponent1SendsOutMonAnimation
BattleIntroOpponent1SendsOutMonAnimation: @ 0x0803AEA0
	push {r4, r5, r6, lr}
	ldr r0, _0803AEC8
	ldr r2, [r0]
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r0, r2
	cmp r0, #0
	beq _0803AEDC
	movs r0, #0x80
	lsls r0, r0, #0x12
	ands r0, r2
	cmp r0, #0
	beq _0803AEDC
	movs r1, #0x80
	lsls r1, r1, #0x18
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r5, r0, #0x1f
	b _0803AEDE
	.align 2, 0
_0803AEC8: .4byte 0x02022C90
_0803AECC:
	ldr r1, _0803AED4
	ldr r0, _0803AED8
	b _0803AF34
	.align 2, 0
_0803AED4: .4byte 0x03005A64
_0803AED8: .4byte 0x0803AE21
_0803AEDC:
	movs r5, #1
_0803AEDE:
	ldr r0, _0803AF3C
	ldr r2, [r0]
	cmp r2, #0
	bne _0803AF36
	ldr r0, _0803AF40
	strb r2, [r0]
	ldr r1, _0803AF44
	adds r4, r0, #0
	ldrb r1, [r1]
	cmp r2, r1
	bhs _0803AF30
	adds r6, r4, #0
_0803AEF6:
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	bne _0803AF1C
	movs r0, #0
	bl BtlController_EmitIntroTrainerBallThrow
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r0, _0803AF48
	ldr r0, [r0]
	ldr r1, _0803AF4C
	ands r0, r1
	cmp r0, #0
	bne _0803AECC
_0803AF1C:
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	ldr r1, _0803AF44
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r4, _0803AF40
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803AEF6
_0803AF30:
	ldr r1, _0803AF50
	ldr r0, _0803AF54
_0803AF34:
	str r0, [r1]
_0803AF36:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803AF3C: .4byte 0x02023D0C
_0803AF40: .4byte 0x02023D08
_0803AF44: .4byte 0x02023D10
_0803AF48: .4byte 0x02022C90
_0803AF4C: .4byte 0x00008040
_0803AF50: .4byte 0x03005A64
_0803AF54: .4byte 0x0803AF59
	thumb_func_end BattleIntroOpponent1SendsOutMonAnimation

