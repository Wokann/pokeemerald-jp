.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	.section .text.sub_08151638,"ax",%progbits
	thumb_func_start sub_08151638
sub_08151638: @ 0x08151638
	push {lr}
	adds r2, r0, #0
	ldr r1, _08151650
	ldr r0, _0815164C
	asrs r3, r2, #0x1f
	bl __divdi3
	pop {r1}
	bx r1
	.align 2, 0
_0815164C: .4byte 0x00010000
_08151650: .4byte 0x00000000
	thumb_func_end sub_08151638

