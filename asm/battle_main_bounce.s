.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start SpriteCB_BounceEffect
SpriteCB_BounceEffect: @ 0x08039A3C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x34]
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r1, #0x36
	ldrsh r0, [r4, r1]
	cmp r0, #1
	bne _08039A54
	movs r2, #0x2e
	ldrsh r0, [r4, r2]
	b _08039A58
_08039A54:
	movs r1, #0x2e
	ldrsh r0, [r4, r1]
_08039A58:
	movs r2, #0x32
	ldrsh r1, [r4, r2]
	bl Sin
	ldr r2, _08039A84
	lsls r1, r5, #4
	adds r1, r1, r5
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r2, [r4, #0x32]
	adds r0, r0, r2
	strh r0, [r1, #0x26]
	ldrh r0, [r4, #0x30]
	ldrh r1, [r4, #0x2e]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x2e]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08039A84: .4byte 0x020205AC
	thumb_func_end SpriteCB_BounceEffect
