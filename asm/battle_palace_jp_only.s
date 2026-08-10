.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	@ CallBattlePalaceFunction dispatches through the ROM jump table.
	@ Kept in asm together with the 2-byte sub_08195574 placeholder so the
	@ literal pool lands at 0x08195578 exactly as in the JP ROM; agbcc
	@ would place the literals inside the function and shift the module.
	thumb_func_start CallBattlePalaceFunction
CallBattlePalaceFunction: @ 0x08195560
	push {lr}
	ldr r1, _08195578
	ldr r0, _0819557C
	ldrh r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	pop {r0}
	thumb_func_end CallBattlePalaceFunction

	thumb_func_start sub_08195574
sub_08195574: @ 0x08195574
	bx r0
	.align 2, 0
_08195578: .4byte 0x085D68CC
_0819557C: .4byte 0x02037280
	thumb_func_end sub_08195574
