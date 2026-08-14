.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start AnimUnusedBagSteal_Step
AnimUnusedBagSteal_Step: @ 0x081141A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldrh r5, [r4, #0x30]
	ldrh r0, [r4, #0x34]
	adds r2, r5, r0
	strh r2, [r4, #0x34]
	ldrh r3, [r4, #0x32]
	ldrh r6, [r4, #0x36]
	adds r1, r3, r6
	strh r1, [r4, #0x36]
	lsls r0, r2, #0x10
	asrs r0, r0, #0x18
	strh r0, [r4, #0x24]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x18
	strh r0, [r4, #0x26]
	movs r6, #0x3c
	ldrsh r0, [r4, r6]
	cmp r0, #0
	bne _081141E2
	adds r0, r2, r5
	strh r0, [r4, #0x34]
	adds r1, r1, r3
	strh r1, [r4, #0x36]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	strh r0, [r4, #0x24]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	strh r1, [r4, #0x26]
	ldrh r0, [r4, #0x2e]
	subs r0, #1
	strh r0, [r4, #0x2e]
_081141E2:
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	movs r2, #0x3a
	ldrsh r1, [r4, r2]
	bl Sin
	ldrh r6, [r4, #0x26]
	adds r0, r0, r6
	strh r0, [r4, #0x26]
	ldrh r0, [r4, #0x38]
	adds r0, #3
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x38]
	cmp r0, #0x7f
	ble _08114212
	movs r0, #0
	strh r0, [r4, #0x38]
	ldrh r0, [r4, #0x3a]
	adds r0, #20
	strh r0, [r4, #0x3a]
	ldrh r0, [r4, #0x3c]
	adds r0, #1
	strh r0, [r4, #0x3c]
_08114212:
	ldrh r0, [r4, #0x2e]
	subs r0, #1
	strh r0, [r4, #0x2e]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08114224
	adds r0, r4, #0
	bl DestroyAnimSprite
_08114224:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end AnimUnusedBagSteal_Step
