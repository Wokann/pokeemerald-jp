.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


thumb_func_start sub_081537AC
sub_081537AC: @ 0x081537AC
	push {lr}
	adds r1, r0, #0
	ldr r0, _081537BC
	bl InitMysteryEventScript
	pop {r0}
	bx r0
	.align 2, 0
_081537BC: .4byte 0x0203B88C
	thumb_func_end sub_081537AC

thumb_func_start sub_081537C0
sub_081537C0: @ 0x081537C0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, _081537D8
	adds r0, r4, #0
	bl RunMysteryEventScriptCommand
	ldr r1, [r4, #0x6c]
	str r1, [r5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081537D8: .4byte 0x0203B88C
	thumb_func_end sub_081537C0

