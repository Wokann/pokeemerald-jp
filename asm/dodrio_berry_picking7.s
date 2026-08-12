.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified



	thumb_func_start sub_08028A20
sub_08028A20: @ 0x08028A20
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	beq _08028A62
	movs r3, #0
	ldr r7, _08028A68
	ldr r6, _08028A6C
	movs r5, #0
_08028A36:
	lsls r0, r3, #2
	adds r2, r0, r6
	ldr r1, [r2]
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	adds r1, r3, r7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1]
	cmp r0, r1
	bls _08028A58
	ldrh r0, [r4, #0x20]
	subs r0, #1
	strh r0, [r4, #0x20]
	ldr r0, [r2]
	strh r5, [r0, #2]
_08028A58:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #1
	bls _08028A36
_08028A62:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08028A68: .4byte 0x082CEBE0
_08028A6C: .4byte 0x02022964
	thumb_func_end sub_08028A20
