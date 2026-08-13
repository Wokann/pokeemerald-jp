.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleIntroPrepareBackgroundSlide
BattleIntroPrepareBackgroundSlide: @ 0x0803A878
	push {r4, r5, lr}
	ldr r0, _0803A8B0
	ldr r5, [r0]
	cmp r5, #0
	bne _0803A8A8
	movs r0, #0
	bl GetBattlerAtPosition
	ldr r4, _0803A8B4
	strb r0, [r4]
	ldr r0, _0803A8B8
	ldrb r1, [r0]
	movs r0, #0
	bl BtlController_EmitIntroSlide
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r1, _0803A8BC
	ldr r0, _0803A8C0
	str r0, [r1]
	ldr r0, _0803A8C4
	strb r5, [r0]
	strb r5, [r0, #1]
_0803A8A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803A8B0: .4byte 0x02023D0C
_0803A8B4: .4byte 0x02023D08
_0803A8B8: .4byte 0x02022C94
_0803A8BC: .4byte 0x03005A64
_0803A8C0: .4byte 0x0803A8C9
_0803A8C4: .4byte 0x02023FD6
	thumb_func_end BattleIntroPrepareBackgroundSlide
