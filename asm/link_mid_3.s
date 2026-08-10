.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0800A618
sub_0800A618: @ 0x0800A618
	ldr r0, _0800A620
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0800A620: .4byte 0x030031C0
	thumb_func_end sub_0800A618


