.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



	thumb_func_start sub_080229BC
sub_080229BC: @ 0x080229BC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	ldrb r2, [r1]
	ldrb r3, [r1, #1]
	lsls r3, r3, #8
	orrs r2, r3
	ldrb r3, [r1, #2]
	lsls r3, r3, #0x10
	orrs r2, r3
	ldrb r3, [r1, #3]
	lsls r3, r3, #0x18
	adds r0, r2, #0
	orrs r0, r3
	ldrb r2, [r1, #9]
	strb r2, [r1]
	ldrb r4, [r1, #8]
	lsls r4, r4, #8
	ldrb r2, [r1, #7]
	orrs r4, r2
	ldr r5, _08022A10
	ldrb r3, [r5, #8]
	movs r2, #0x7f
	ands r2, r3
	strb r2, [r5, #8]
	movs r5, #4
	ldrsb r5, [r1, r5]
	ldrb r2, [r1, #5]
	ldrb r3, [r1, #6]
	str r4, [sp]
	adds r1, r5, #0
	bl BeginNormalPaletteFade
	bl UpdatePaletteFade
	movs r0, #2
	strb r0, [r6, #0xe]
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08022A10: .4byte 0x02037C74
	thumb_func_end sub_080229BC
