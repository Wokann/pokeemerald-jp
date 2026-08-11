.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start MovePlayerOnMachBike
MovePlayerOnMachBike: @ 0x081199EC
	push {r4, lr}
	sub sp, #4
	mov r1, sp
	strb r0, [r1]
	ldr r4, _08119A18
	mov r0, sp
	bl GetMachBikeTransition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r4
	mov r1, sp
	ldrb r1, [r1]
	ldr r2, [r0]
	adds r0, r1, #0
	bl _call_via_r2
	add sp, #4
	thumb_func_end MovePlayerOnMachBike

	thumb_func_start AcroBikeTransition_FaceDirection
AcroBikeTransition_FaceDirection: @ 0x08119A10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08119A18: .4byte 0x08573030
	thumb_func_end AcroBikeTransition_FaceDirection
