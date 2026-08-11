.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_08017484
sub_08017484: @ 0x08017484
	push {r4, r5, r6, lr}
	adds r6, r3, #0
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x13
	adds r5, r0, r2
	ldrb r1, [r5, #0xa]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08017500
	cmp r4, #0
	bne _08017500
	ldr r4, _080174E0
	adds r1, r5, #0
	adds r1, #0x10
	adds r0, r4, #0
	bl StringCopy
	adds r0, r5, #2
	bl ReadAsU16
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r4, #0
	bl PlayerHasMetTrainerBefore
	adds r2, r0, #0
	ldrb r1, [r5, #0xa]
	movs r0, #0x7f
	ands r0, r1
	cmp r0, #0x45
	bne _080174EC
	ldr r0, _080174E4
	ldr r3, _080174E8
	lsls r1, r6, #2
	lsls r2, r2, #3
	adds r1, r1, r2
	adds r1, r1, r3
	ldr r1, [r1]
	bl StringExpandPlaceholders
	movs r0, #2
	b _080175DE
	.align 2, 0
_080174E0: .4byte 0x02021C40
_080174E4: .4byte 0x02021C7C
_080174E8: .4byte 0x082C0FD0
_080174EC:
	ldr r0, _080174FC
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl UR_PrintFieldMessage
	movs r0, #1
	b _080175DE
	.align 2, 0
_080174FC: .4byte 0x082C0CD8
_08017500:
	ldr r0, _08017530
	adds r1, r5, #0
	adds r1, #0x10
	bl StringCopy
	cmp r4, #0
	beq _08017518
	adds r0, r5, r4
	ldrb r0, [r0, #3]
	lsrs r6, r0, #3
	movs r0, #1
	ands r6, r0
_08017518:
	ldrb r0, [r5, #0xa]
	lsls r0, r0, #0x19
	lsrs r0, r0, #0x19
	movs r1, #0x3f
	ands r1, r0
	cmp r1, #4
	beq _08017564
	cmp r1, #4
	bgt _08017534
	cmp r1, #1
	beq _0801753E
	b _080175D4
	.align 2, 0
_08017530: .4byte 0x02021C40
_08017534:
	cmp r1, #5
	beq _08017584
	cmp r1, #8
	beq _080175A8
	b _080175D4
_0801753E:
	ldr r5, _0801755C
	ldr r4, _08017560
	bl Random
	lsls r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0xa
	ands r1, r0
	lsrs r1, r1, #0xe
	lsls r0, r6, #4
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r1, [r1]
	b _080175C2
	.align 2, 0
_0801755C: .4byte 0x02021C7C
_08017560: .4byte 0x082C1498
_08017564:
	ldr r5, _0801757C
	ldr r4, _08017580
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	lsls r1, r6, #4
	b _080175BC
	.align 2, 0
_0801757C: .4byte 0x02021C7C
_08017580: .4byte 0x082C1668
_08017584:
	ldr r5, _080175A0
	ldr r4, _080175A4
	bl Random
	lsls r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0xa
	ands r1, r0
	lsrs r1, r1, #0xe
	lsls r0, r6, #4
	adds r1, r1, r0
	adds r1, r1, r4
	ldr r1, [r1]
	b _080175C2
	.align 2, 0
_080175A0: .4byte 0x02021C7C
_080175A4: .4byte 0x082C1564
_080175A8:
	ldr r5, _080175CC
	ldr r4, _080175D0
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	lsls r1, r6, #3
_080175BC:
	adds r0, r0, r1
	adds r0, r0, r4
	ldr r1, [r0]
_080175C2:
	adds r0, r5, #0
	bl StringExpandPlaceholders
	b _080175DC
	.align 2, 0
_080175CC: .4byte 0x02021C7C
_080175D0: .4byte 0x082C15E8
_080175D4:
	ldr r0, _080175E4
	ldr r1, _080175E8
	bl StringExpandPlaceholders
_080175DC:
	movs r0, #0
_080175DE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080175E4: .4byte 0x02021C7C
_080175E8: .4byte 0x082C0FE0
	thumb_func_end sub_08017484

