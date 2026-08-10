.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


thumb_func_start CalcRecordMixingGiftChecksum
CalcRecordMixingGiftChecksum: @ 0x0815380C
	push {lr}
	movs r2, #0
	ldr r0, _0815382C
	ldr r0, [r0]
	ldr r1, _08153830
	adds r3, r0, r1
	movs r1, #0
_0815381A:
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r2, r2, r0
	adds r1, #1
	cmp r1, #0xb
	bls _0815381A
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_0815382C: .4byte 0x03005AEC
_08153830: .4byte 0x00003B18
	thumb_func_end CalcRecordMixingGiftChecksum

