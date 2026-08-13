.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_0803EEE4
sub_0803EEE4: @ 0x0803EEE4
	push {lr}
	bl HandleFaintedMonActions
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0803EF00
	ldr r0, _0803EF04
	ldr r0, [r0]
	adds r0, #0x4d
	strb r1, [r0]
	ldr r1, _0803EF08
	movs r0, #0xc
	strb r0, [r1]
_0803EF00:
	pop {r0}
	bx r0
	.align 2, 0
_0803EF04: .4byte 0x02024140
_0803EF08: .4byte 0x02023D27
	thumb_func_end sub_0803EEE4
