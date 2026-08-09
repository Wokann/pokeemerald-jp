.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified











	thumb_func_start BlendPalette
BlendPalette: @ 0x0806F410
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov ip, r1
	lsls r2, r2, #0x18
	lsrs r7, r2, #0x18
	mov r0, sp
	strh r3, [r0]
	movs r6, #0
	cmp r6, ip
	bhs _0806F496
	ldr r0, _0806F4A8
	mov sl, r0
	ldr r1, _0806F4AC
	mov sb, r1
_0806F43E:
	mov r0, r8
	adds r5, r6, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0xf
	mov r1, sl
	adds r0, r5, r1
	ldr r3, [r0]
	lsls r4, r3, #0x1b
	lsls r2, r3, #0x16
	lsls r3, r3, #0x11
	add r5, sb
	lsrs r4, r4, #0x1b
	ldr r1, [sp]
	lsls r0, r1, #0x1b
	lsrs r0, r0, #0x1b
	subs r0, r0, r4
	muls r0, r7, r0
	asrs r0, r0, #4
	adds r4, r4, r0
	lsrs r2, r2, #0x1b
	lsls r0, r1, #0x16
	lsrs r0, r0, #0x1b
	subs r0, r0, r2
	muls r0, r7, r0
	asrs r0, r0, #4
	adds r2, r2, r0
	lsls r2, r2, #5
	orrs r4, r2
	lsrs r3, r3, #0x1b
	lsls r1, r1, #0x11
	lsrs r1, r1, #0x1b
	subs r1, r1, r3
	adds r0, r1, #0
	muls r0, r7, r0
	asrs r0, r0, #4
	adds r3, r3, r0
	lsls r3, r3, #0xa
	orrs r4, r3
	strh r4, [r5]
	adds r0, r6, #1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, ip
	blo _0806F43E
_0806F496:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0806F4A8: .4byte 0x020373B4
_0806F4AC: .4byte 0x020377B4
	thumb_func_end BlendPalette
