.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_08037770
sub_08037770: @ 0x08037770
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	movs r7, #0
	ldr r6, _08037820
	mov sb, r6
_08037786:
	mov r0, sl
	adds r1, r7, r0
	movs r0, #0x64
	adds r4, r1, #0
	muls r4, r0, r4
	ldr r0, _08037824
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xb
	bl GetMonData3
	lsls r5, r7, #5
	strh r0, [r6]
	adds r0, r4, #0
	movs r1, #0xc
	bl GetMonData3
	strh r0, [r6, #2]
	movs r0, #4
	add r0, sb
	mov r8, r0
	adds r2, r5, r0
	adds r0, r4, #0
	movs r1, #2
	bl GetMonData3
	adds r0, r4, #0
	movs r1, #0x38
	bl GetMonData3
	strb r0, [r6, #0xf]
	adds r0, r4, #0
	movs r1, #0x39
	bl GetMonData3
	strh r0, [r6, #0x10]
	adds r0, r4, #0
	movs r1, #0x3a
	bl GetMonData3
	strh r0, [r6, #0x12]
	adds r0, r4, #0
	movs r1, #0x37
	bl GetMonData3
	mov r1, sb
	adds r1, #0x14
	adds r5, r5, r1
	str r0, [r5]
	adds r0, r4, #0
	movs r1, #0
	bl GetMonData3
	str r0, [r6, #0x18]
	adds r0, r4, #0
	bl GetMonGender
	strb r0, [r6, #0x1c]
	adds r6, #0x20
	adds r7, #1
	cmp r7, #2
	ble _08037786
	ldr r0, _08037828
	ldr r0, [r0]
	mov r1, r8
	subs r1, #4
	movs r2, #0x60
	bl memcpy
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08037820: .4byte 0x02022C9C
_08037824: .4byte 0x02024190
_08037828: .4byte 0x02022CFC
	thumb_func_end sub_08037770

