.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0800A010
sub_0800A010: @ 0x0800A010
	ldr r0, _0800A018
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0800A018: .4byte 0x02022078
	thumb_func_end sub_0800A010


