.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0800AFEC
sub_0800AFEC: @ 0x0800AFEC
	ldr r0, _0800AFF4
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0800AFF4: .4byte 0x0300319C
	thumb_func_end sub_0800AFEC


