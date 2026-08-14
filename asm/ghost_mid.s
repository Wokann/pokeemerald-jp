.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start AnimTask_SpiteTargetShadow
AnimTask_SpiteTargetShadow: @ 0x081126A0
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r2, _081126C0
	adds r1, r1, r2
	movs r2, #0
	strh r2, [r1, #0x26]
	ldr r2, _081126C4
	str r2, [r1]
	bl _call_via_r2
	thumb_func_end AnimTask_SpiteTargetShadow

	thumb_func_start sub_081126BC
sub_081126BC: @ 0x081126BC
	pop {r0}
	bx r0
	.align 2, 0
_081126C0: .4byte 0x03005B60
_081126C4: .4byte 0x081126C9
	thumb_func_end sub_081126BC
