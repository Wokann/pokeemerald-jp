
.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



	thumb_func_start sub_08031FD8
sub_08031FD8: @ 0x08031FD8
	push {r4, r5, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _0803200C
	adds r0, r5, #0
	bl CallWindowFunction
	adds r0, r5, #0
	movs r1, #0x11
	bl FillWindowPixelBuffer
	adds r0, r5, #0
	bl ClearWindowTilemap
	cmp r4, #1
	bne _08032006
	adds r0, r5, #0
	movs r1, #3
	bl CopyWindowToVram
_08032006:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0803200C: .4byte 0x08031F91
	thumb_func_end sub_08031FD8

