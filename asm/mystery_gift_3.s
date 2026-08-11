.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start mevent_message_was_thrown_away
mevent_message_was_thrown_away: @ 0x080188DC
	push {lr}
	cmp r1, #0
	beq _080188EC
	ldr r1, _080188E8
	b _080188EE
	.align 2, 0
_080188E8: .4byte 0x082C2B38
_080188EC:
	ldr r1, _080188F8
_080188EE:
	bl MG_PrintTextOnWindow1AndWaitButton
	pop {r1}
	bx r1
	.align 2, 0
_080188F8: .4byte 0x082C2B28
	thumb_func_end mevent_message_was_thrown_away
