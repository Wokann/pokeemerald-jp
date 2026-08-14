.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start Task_TitleScreenPhase2
Task_TitleScreenPhase2: @ 0x080AA528
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _080AA578
	ldrh r1, [r0, #0x2e]
	movs r0, #0xf
	ands r0, r1
	ldr r2, _080AA57C
	cmp r0, #0
	bne _080AA54E
	lsls r0, r4, #2
	adds r1, r0, r4
	lsls r1, r1, #3
	adds r1, r1, r2
	movs r3, #0xa
	ldrsh r1, [r1, r3]
	adds r6, r0, #0
	cmp r1, #0
	beq _080AA560
_080AA54E:
	lsls r3, r4, #2
	adds r0, r3, r4
	lsls r0, r0, #3
	adds r0, r0, r2
	movs r2, #0
	movs r1, #1
	strh r1, [r0, #0xa]
	strh r2, [r0, #8]
	adds r6, r3, #0
_080AA560:
	ldr r1, _080AA57C
	adds r0, r6, r4
	lsls r0, r0, #3
	adds r5, r0, r1
	ldrh r0, [r5, #8]
	movs r1, #8
	ldrsh r7, [r5, r1]
	cmp r7, #0
	beq _080AA580
	subs r0, #1
	strh r0, [r5, #8]
	b _080AA5BA
	.align 2, 0
_080AA578: .4byte 0x03002360
_080AA57C: .4byte 0x03005B60
_080AA580:
	movs r0, #1
	strh r0, [r5, #0xa]
	ldr r1, _080AA63C
	movs r0, #0x50
	bl SetGpuReg
	ldr r1, _080AA640
	movs r0, #0x52
	bl SetGpuReg
	movs r0, #0x54
	movs r1, #0
	bl SetGpuReg
	ldr r1, _080AA644
	movs r0, #0
	bl SetGpuReg
	movs r0, #0x80
	movs r1, #0x6c
	bl CreatePressStartBanner
	movs r0, #0x80
	movs r1, #0x94
	bl CreateCopyrightBanner
	strh r7, [r5, #0x10]
	ldr r0, _080AA648
	str r0, [r5]
_080AA5BA:
	ldr r2, _080AA64C
	adds r0, r6, r4
	lsls r0, r0, #3
	adds r3, r0, r2
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080AA5DA
	ldrh r1, [r3, #0xc]
	movs r5, #0xc
	ldrsh r0, [r3, r5]
	cmp r0, #0
	beq _080AA5DA
	adds r0, r1, #1
	strh r0, [r3, #0xc]
_080AA5DA:
	adds r0, r6, r4
	lsls r0, r0, #3
	adds r3, r0, r2
	ldrh r1, [r3, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080AA5F8
	ldrh r1, [r3, #0xe]
	movs r5, #0xe
	ldrsh r0, [r3, r5]
	cmp r0, #0
	beq _080AA5F8
	adds r0, r1, #1
	strh r0, [r3, #0xe]
_080AA5F8:
	adds r4, r6, r4
	lsls r4, r4, #3
	adds r4, r4, r2
	movs r0, #0xc
	ldrsh r1, [r4, r0]
	lsls r5, r1, #8
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x10
	movs r0, #0x28
	bl SetGpuReg
	lsrs r1, r5, #0x10
	movs r0, #0x2a
	bl SetGpuReg
	movs r3, #0xe
	ldrsh r1, [r4, r3]
	lsls r5, r1, #8
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x10
	movs r0, #0x2c
	bl SetGpuReg
	lsrs r1, r5, #0x10
	movs r0, #0x2e
	bl SetGpuReg
	movs r0, #0xf
	strh r0, [r4, #0x12]
	movs r0, #6
	strh r0, [r4, #0x14]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AA63C: .4byte 0x00002142
_080AA640: .4byte 0x00000F06
_080AA644: .4byte 0x00001741
_080AA648: .4byte 0x080AA651
_080AA64C: .4byte 0x03005B60
	thumb_func_end Task_TitleScreenPhase2
