.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start sub_08022434
sub_08022434: @ 0x08022434
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r5, #0
	ldr r0, _08022448
	ldr r4, _0802244C
	adds r1, r4, #0
	bl LZ77UnCompWram
	b _0802247E
	.align 2, 0
_08022448: .4byte 0x082C79C4
_0802244C: .4byte 0x0201C000
_08022450:
	lsls r1, r5, #2
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r6, r2
	adds r0, r0, r1
	ldr r3, [r0]
	ldrb r0, [r3]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r4, r1
	ldrb r2, [r3, #1]
	ldrb r3, [r3, #2]
	movs r0, #0xa
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #3
	bl CopyToBgTilemapBufferRect
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
_0802247E:
	ldrb r0, [r6, #9]
	cmp r5, r0
	blo _08022450
	movs r0, #3
	bl CopyBgTilemapBufferToVram
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end sub_08022434



