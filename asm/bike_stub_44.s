.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start MovePlayerOnAcroBike
MovePlayerOnAcroBike: @ 0x08119C18
	push {r4, lr}
	sub sp, #4
	mov r3, sp
	strb r0, [r3]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r4, _08119C4C
	mov r0, sp
	bl CheckMovementInputAcroBike
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r4
	mov r1, sp
	ldrb r1, [r1]
	ldr r2, [r0]
	adds r0, r1, #0
	bl _call_via_r2
	add sp, #4
	thumb_func_end MovePlayerOnAcroBike

	thumb_func_start sub_08119C44
sub_08119C44: @ 0x08119C44
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08119C4C: .4byte 0x0857304C
	thumb_func_end sub_08119C44
