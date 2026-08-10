.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	@ JP-only script special with no pokeemerald counterpart.  Kept in asm
	@ because agbcc appends a trailing bx lr to naked asm that ends in a
	@ literal pool word, which would shift the following module bytes.
	thumb_func_start ScrSpecial_TraderMenuGiveDecoration
ScrSpecial_TraderMenuGiveDecoration: @ 0x081339EC
	push {lr}
	ldr r3, _08133A04
	ldr r0, [r3]
	ldr r0, [r0, #0x1c]
	adds r1, r0, #0
	adds r1, #0x20
	ldrb r0, [r1]
	cmp r0, #0
	bne _08133A08
	movs r0, #0
	b _08133A22
	.align 2, 0
_08133A04: .4byte 0x0202414C
_08133A08:
	subs r0, #1
	strb r0, [r1]
	ldr r2, _08133A28
	ldr r0, [r3]
	ldr r1, [r0, #0x1c]
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	movs r0, #1
_08133A22:
	pop {r1}
	bx r1
	.align 2, 0
_08133A28: .4byte 0x0203A804
	thumb_func_end ScrSpecial_TraderMenuGiveDecoration
