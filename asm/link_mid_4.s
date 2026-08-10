.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0800A7AC
sub_0800A7AC: @ 0x0800A7AC
	ldr r0, _0800A7B4
	ldrb r0, [r0]
	bx lr
	.align 2, 0
_0800A7B4: .4byte 0x03000D58
	thumb_func_end sub_0800A7AC


