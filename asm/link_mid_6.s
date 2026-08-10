.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_0800AE24
sub_0800AE24: @ 0x0800AE24
	push {r4, r5, r6, lr}
	bl InitLocalLinkPlayer
	ldr r1, _0800AE70
	adds r2, r1, #0
	adds r2, #0x10
	ldr r0, _0800AE74
	ldm r0!, {r3, r4, r5}
	stm r2!, {r3, r4, r5}
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldr r0, [r0]
	str r0, [r2]
	ldr r3, _0800AE78
	adds r2, r1, #0
	adds r0, r3, #0
	ldm r0!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldrh r4, [r0]
	strh r4, [r2]
	ldrb r0, [r0, #2]
	strb r0, [r2, #2]
	adds r0, r1, #0
	adds r0, #0x2c
	ldm r3!, {r2, r5, r6}
	stm r0!, {r2, r5, r6}
	ldrh r2, [r3]
	strh r2, [r0]
	ldrb r2, [r3, #2]
	strb r2, [r0, #2]
	ldr r0, _0800AE7C
	movs r2, #0x3c
	bl memcpy
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800AE70: .4byte 0x030030D0
_0800AE74: .4byte 0x02022684
_0800AE78: .4byte 0x082BFF24
_0800AE7C: .4byte 0x0202257C
	thumb_func_end sub_0800AE24

	thumb_func_start sub_0800AE80
sub_0800AE80: @ 0x0800AE80
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r0, #8
	ldr r1, _0800AED0
	adds r4, r2, r1
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	ldr r0, _0800AED4
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0x10
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldr r0, [r0]
	str r0, [r1]
	ldr r5, _0800AED8
	adds r0, r4, #0
	adds r1, r5, #0
	bl strcmp
	cmp r0, #0
	bne _0800AEC2
	adds r0, r4, #0
	adds r0, #0x2c
	adds r1, r5, #0
	bl strcmp
	cmp r0, #0
	beq _0800AEC8
_0800AEC2:
	ldr r0, _0800AEDC
	bl SetMainCallback2
_0800AEC8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800AED0: .4byte 0x0202207C
_0800AED4: .4byte 0x020226A0
_0800AED8: .4byte 0x082BFF24
_0800AEDC: .4byte 0x0800AA0D
	thumb_func_end sub_0800AE80


