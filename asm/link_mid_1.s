.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_08009BD4
sub_08009BD4: @ 0x08009BD4
	push {r4, r5, lr}
	movs r5, #0
	ldr r4, _08009BDC
	b _08009BEE
	.align 2, 0
_08009BDC: .4byte 0x020226A0
_08009BE0:
	ldrh r0, [r4, #0x1a]
	cmp r0, #1
	beq _08009BEA
	movs r0, #1
	b _08009BFC
_08009BEA:
	adds r4, #0x1c
	adds r5, #1
_08009BEE:
	bl GetLinkPlayerCount
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r5, r0
	blt _08009BE0
	movs r0, #0
_08009BFC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08009BD4


