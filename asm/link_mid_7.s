.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0800AF94
sub_0800AF94: @ 0x0800AF94
	push {lr}
	ldr r0, _0800AFA8
	ldrb r1, [r0]
	cmp r1, #0
	bne _0800AFA2
	ldr r0, _0800AFAC
	strb r1, [r0]
_0800AFA2:
	pop {r0}
	bx r0
	.align 2, 0
_0800AFA8: .4byte 0x030031C4
_0800AFAC: .4byte 0x0300319C
	thumb_func_end sub_0800AF94


