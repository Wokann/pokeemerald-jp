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

	.section .text.roulette_util_rest,"ax",%progbits







	thumb_func_start sub_08151FE4
sub_08151FE4: @ 0x08151FE4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, [sp, #0x14]
	ldr r4, [sp, #0x18]
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	movs r1, #0
	lsrs r3, r3, #0x13
	adds r3, r3, r2
	lsls r3, r3, #1
	adds r6, r6, r3
	cmp r1, r4
	bhs _0815202E
_0815200C:
	lsls r0, r1, #6
	adds r2, r6, r0
	movs r0, #0
	adds r3, r1, #1
	cmp r0, r5
	bhs _08152026
_08152018:
	strh r7, [r2]
	adds r2, #2
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	blo _08152018
_08152026:
	lsls r0, r3, #0x18
	lsrs r1, r0, #0x18
	cmp r1, r4
	blo _0815200C
_0815202E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_08151FE4

	thumb_func_start sub_08152034
sub_08152034: @ 0x08152034
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, [sp, #0x14]
	ldr r4, [sp, #0x18]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x18
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r4, r4, #0x18
	lsrs r6, r4, #0x18
	movs r4, #0
	lsrs r3, r3, #0x13
	adds r3, r3, r2
	lsls r3, r3, #1
	adds r7, r7, r3
	cmp r4, r6
	bhs _0815207E
_08152058:
	lsls r0, r4, #6
	adds r2, r7, r0
	movs r3, #0
	adds r4, #1
	cmp r3, r5
	bhs _08152076
_08152064:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r5
	blo _08152064
_08152076:
	lsls r0, r4, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r6
	blo _08152058
_0815207E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end sub_08152034
