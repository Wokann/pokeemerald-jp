.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


thumb_func_start memset
memset: @ 0x08297D6C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r5, #0
	cmp r2, #3
	bls _08297DB2
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	bne _08297DB2
	adds r1, r5, #0
	movs r0, #0xff
	ands r4, r0
	lsls r3, r4, #8
	orrs r3, r4
	lsls r0, r3, #0x10
	orrs r3, r0
	cmp r2, #0xf
	bls _08297DA6
_08297D92:
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	stm r1!, {r3}
	subs r2, #0x10
	cmp r2, #0xf
	bhi _08297D92
	b _08297DA6
_08297DA2:
	stm r1!, {r3}
	subs r2, #4
_08297DA6:
	cmp r2, #3
	bhi _08297DA2
	adds r3, r1, #0
	b _08297DB2
_08297DAE:
	strb r4, [r3]
	adds r3, #1
_08297DB2:
	adds r0, r2, #0
	subs r2, #1
	cmp r0, #0
	bne _08297DAE
	adds r0, r5, #0
	pop {r4, r5, pc}
	.align 2, 0
	thumb_func_end memset

