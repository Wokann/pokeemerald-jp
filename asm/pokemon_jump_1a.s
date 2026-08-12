.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start sub_0802BD8C
sub_0802BD8C: @ 0x0802BD8C
	ldr r0, _0802BDA0
	ldr r2, [r0]
	ldr r1, [r2, #0x24]
	ldr r0, _0802BDA4
	muls r0, r1, r0
	ldr r1, _0802BDA8
	adds r0, r0, r1
	str r0, [r2, #0x24]
	lsrs r0, r0, #0x10
	bx lr
	.align 2, 0
_0802BDA0: .4byte 0x020229B0
_0802BDA4: .4byte 0x41C64E6D
_0802BDA8: .4byte 0x00006073
	thumb_func_end sub_0802BD8C

	thumb_func_start sub_0802BDAC
sub_0802BDAC: @ 0x0802BDAC
	push {lr}
	ldr r0, _0802BDC8
	ldr r1, [r0]
	movs r0, #1
	str r0, [r1, #0x10]
	movs r0, #6
	str r0, [r1, #0x14]
	ldr r0, _0802BDCC
	strh r0, [r1, #0x34]
	bl sub_0802BF64
	pop {r0}
	bx r0
	.align 2, 0
_0802BDC8: .4byte 0x020229B0
_0802BDCC: .4byte 0x000005FF
	thumb_func_end sub_0802BDAC

	thumb_func_start sub_0802BDD0
sub_0802BDD0: @ 0x0802BDD0
	ldr r0, _0802BDD8
	ldr r0, [r0]
	ldr r0, [r0, #0x10]
	bx lr
	.align 2, 0
_0802BDD8: .4byte 0x020229B0
	thumb_func_end sub_0802BDD0
