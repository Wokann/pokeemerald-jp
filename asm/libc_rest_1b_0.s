.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified





thumb_func_start _Balloc
_Balloc: @ 0x0829AD84
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, [r4, #0x4c]
	cmp r0, #0
	bne _0829ADA0
	adds r0, r4, #0
	movs r1, #4
	movs r2, #0x10
	bl _calloc_r
	str r0, [r4, #0x4c]
	cmp r0, #0
	beq _0829ADC8
_0829ADA0:
	ldr r1, [r4, #0x4c]
	lsls r0, r6, #2
	adds r2, r0, r1
	ldr r1, [r2]
	cmp r1, #0
	beq _0829ADB2
	ldr r0, [r1]
	str r0, [r2]
	b _0829ADD0
_0829ADB2:
	movs r5, #1
	lsls r5, r6
	lsls r2, r5, #2
	adds r2, #0x14
	adds r0, r4, #0
	movs r1, #1
	bl _calloc_r
	adds r1, r0, #0
	cmp r1, #0
	bne _0829ADCC
_0829ADC8:
	movs r0, #0
	b _0829ADD8
_0829ADCC:
	str r6, [r1, #4]
	str r5, [r1, #8]
_0829ADD0:
	movs r0, #0
	str r0, [r1, #0x10]
	str r0, [r1, #0xc]
	adds r0, r1, #0
_0829ADD8:
	pop {r4, r5, r6, pc}
	.align 2, 0
	thumb_func_end _Balloc

