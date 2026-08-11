.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start PopulateSpeciesFromTrainerParty
PopulateSpeciesFromTrainerParty: @ 0x0819686C
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r2, _081968BC
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r0, [r1]
	bl GetLastBeatenRematchTrainerId
	adds r4, r0, #0
	lsls r4, r4, #0x10
	ldr r5, _081968C0
	lsrs r4, r4, #0xb
	adds r0, r5, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r6, [r0]
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r5
	ldrb r1, [r4, #0x18]
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4]
	cmp r1, #1
	beq _081968C8
	cmp r1, #1
	ble _081968B6
	cmp r1, #2
	beq _081968C4
	cmp r1, #3
	beq _081968C8
_081968B6:
	lsls r0, r0, #3
	b _081968CA
	.align 2, 0
_081968BC: .4byte 0x085D6934
_081968C0: .4byte 0x082E383C
_081968C4:
	lsls r0, r0, #3
	b _081968CA
_081968C8:
	lsls r0, r0, #4
_081968CA:
	adds r0, r0, r6
	ldrh r0, [r0, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, _081968E4
	adds r1, r1, r0
	adds r0, r7, #0
	bl StringCopy
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081968E4: .4byte 0x082EA31C
	thumb_func_end PopulateSpeciesFromTrainerParty
