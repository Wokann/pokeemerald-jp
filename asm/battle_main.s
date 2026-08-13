.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified


	thumb_func_start HandleAction_Run
HandleAction_Run: @ 0x0803EA88
	push {r4, r5, r6, lr}
	ldr r4, _0803EAD8
	ldr r1, _0803EADC
	ldr r5, _0803EAE0
	ldrb r0, [r5]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r0, _0803EAE4
	ldr r0, [r0]
	ldr r1, _0803EAE8
	ands r0, r1
	cmp r0, #0
	beq _0803EB4C
	ldr r0, _0803EAEC
	ldrb r1, [r0]
	strb r1, [r5]
	ldr r2, _0803EAF0
	movs r0, #0
	strb r0, [r2]
	lsls r1, r1, #0x18
	cmp r1, #0
	beq _0803EB20
	adds r4, r2, #0
	ldr r6, _0803EAF4
	ldr r5, _0803EAF8
_0803EABC:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EAFC
	ldrb r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803EB0E
	ldrb r0, [r5]
	movs r1, #2
	b _0803EB0A
	.align 2, 0
_0803EAD8: .4byte 0x02023EAF
_0803EADC: .4byte 0x02023D22
_0803EAE0: .4byte 0x02023D26
_0803EAE4: .4byte 0x02022C90
_0803EAE8: .4byte 0x02000002
_0803EAEC: .4byte 0x02023D10
_0803EAF0: .4byte 0x02023D08
_0803EAF4: .4byte 0x02023EC0
_0803EAF8: .4byte 0x02023FDE
_0803EAFC:
	ldrb r0, [r4]
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803EB0E
	ldrb r0, [r5]
	movs r1, #1
_0803EB0A:
	orrs r0, r1
	strb r0, [r5]
_0803EB0E:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _0803EB3C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803EABC
_0803EB20:
	ldr r2, _0803EB40
	ldrb r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _0803EB44
	ldr r1, [r0]
	ldr r0, _0803EB48
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #8
	orrs r0, r2
	b _0803EBD6
	.align 2, 0
_0803EB3C: .4byte 0x02023D10
_0803EB40: .4byte 0x02023FDE
_0803EB44: .4byte 0x03005AF0
_0803EB48: .4byte 0x00000CA9
_0803EB4C:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EB8C
	ldrb r0, [r4]
	bl TryRunFromBattle
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803EBD8
	ldrb r0, [r4]
	bl ClearFuryCutterDestinyBondGrudge
	ldr r1, _0803EB7C
	movs r0, #3
	strb r0, [r1, #5]
	ldr r1, _0803EB80
	ldr r0, _0803EB84
	str r0, [r1]
	ldr r1, _0803EB88
	movs r0, #0xa
	b _0803EBD6
	.align 2, 0
_0803EB7C: .4byte 0x02023FD6
_0803EB80: .4byte 0x02023EB8
_0803EB84: .4byte 0x0828908A
_0803EB88: .4byte 0x02023D27
_0803EB8C:
	ldr r1, _0803EBB4
	ldrb r2, [r4]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0803EBB8
	ands r0, r1
	cmp r0, #0
	beq _0803EBCC
	ldr r1, _0803EBBC
	movs r0, #4
	strb r0, [r1, #5]
	ldr r1, _0803EBC0
	ldr r0, _0803EBC4
	str r0, [r1]
	ldr r1, _0803EBC8
	movs r0, #0xa
	b _0803EBD6
	.align 2, 0
_0803EBB4: .4byte 0x02023D28
_0803EBB8: .4byte 0x0400E000
_0803EBBC: .4byte 0x02023FD6
_0803EBC0: .4byte 0x02023EB8
_0803EBC4: .4byte 0x0828908A
_0803EBC8: .4byte 0x02023D27
_0803EBCC:
	ldr r0, _0803EBE0
	ldrb r0, [r0]
	strb r0, [r5]
	ldr r1, _0803EBE4
	movs r0, #6
_0803EBD6:
	strb r0, [r1]
_0803EBD8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803EBE0: .4byte 0x02023D10
_0803EBE4: .4byte 0x02023FDE
	thumb_func_end HandleAction_Run

	thumb_func_start HandleAction_WatchesCarefully
HandleAction_WatchesCarefully: @ 0x0803EBE8
	ldr r2, _0803EC10
	ldr r1, _0803EC14
	ldr r0, _0803EC18
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, _0803EC1C
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EC20
	strh r1, [r0]
	ldr r1, _0803EC24
	ldr r0, _0803EC28
	ldr r0, [r0]
	str r0, [r1]
	ldr r1, _0803EC2C
	movs r0, #0xa
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803EC10: .4byte 0x02023EAF
_0803EC14: .4byte 0x02023D22
_0803EC18: .4byte 0x02023D26
_0803EC1C: .4byte 0x02022AC8
_0803EC20: .4byte 0x02022ACA
_0803EC24: .4byte 0x02023EB8
_0803EC28: .4byte 0x0828A2E0
_0803EC2C: .4byte 0x02023D27
	thumb_func_end HandleAction_WatchesCarefully

	thumb_func_start HandleAction_SafariZoneBallThrow
HandleAction_SafariZoneBallThrow: @ 0x0803EC30
	ldr r2, _0803EC68
	ldr r1, _0803EC6C
	ldr r0, _0803EC70
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, _0803EC74
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EC78
	strh r1, [r0]
	ldr r1, _0803EC7C
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	ldr r1, _0803EC80
	movs r0, #5
	strh r0, [r1]
	ldr r1, _0803EC84
	ldr r0, _0803EC88
	ldr r0, [r0, #0x14]
	str r0, [r1]
	ldr r1, _0803EC8C
	movs r0, #0xa
	strb r0, [r1]
	bx lr
	.align 2, 0
_0803EC68: .4byte 0x02023EAF
_0803EC6C: .4byte 0x02023D22
_0803EC70: .4byte 0x02023D26
_0803EC74: .4byte 0x02022AC8
_0803EC78: .4byte 0x02022ACA
_0803EC7C: .4byte 0x02039D18
_0803EC80: .4byte 0x02023EAC
_0803EC84: .4byte 0x02023EB8
_0803EC88: .4byte 0x0828A290
_0803EC8C: .4byte 0x02023D27
	thumb_func_end HandleAction_SafariZoneBallThrow

	thumb_func_start HandleAction_ThrowPokeblock
HandleAction_ThrowPokeblock: @ 0x0803EC90
	push {r4, r5, r6, lr}
	ldr r3, _0803ED10
	ldr r1, _0803ED14
	ldr r0, _0803ED18
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r0, _0803ED1C
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803ED20
	strh r1, [r0]
	ldr r6, _0803ED24
	ldr r2, _0803ED28
	ldrb r0, [r3]
	lsls r0, r0, #9
	adds r1, r2, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	subs r0, #1
	strb r0, [r6, #5]
	ldr r1, _0803ED2C
	ldrb r0, [r3]
	lsls r0, r0, #9
	adds r2, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	strh r0, [r1]
	ldr r1, _0803ED30
	ldrb r0, [r1, #0x1f]
	cmp r0, #0xfe
	bhi _0803ECD6
	adds r0, #1
	strb r0, [r1, #0x1f]
_0803ECD6:
	ldr r2, _0803ED34
	ldr r0, [r2]
	adds r1, r0, #0
	adds r1, #0x7a
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0803ECE8
	adds r0, #1
	strb r0, [r1]
_0803ECE8:
	ldr r0, [r2]
	adds r3, r0, #0
	adds r3, #0x7b
	ldrb r5, [r3]
	adds r4, r5, #0
	cmp r4, #1
	bls _0803ED40
	ldr r2, _0803ED38
	adds r0, #0x7a
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	ldrb r6, [r6, #5]
	adds r0, r0, r6
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r4, r0
	bhs _0803ED3C
	movs r0, #1
	b _0803ED3E
	.align 2, 0
_0803ED10: .4byte 0x02023EAF
_0803ED14: .4byte 0x02023D22
_0803ED18: .4byte 0x02023D26
_0803ED1C: .4byte 0x02022AC8
_0803ED20: .4byte 0x02022ACA
_0803ED24: .4byte 0x02023FD6
_0803ED28: .4byte 0x02023508
_0803ED2C: .4byte 0x02023EAC
_0803ED30: .4byte 0x03005A70
_0803ED34: .4byte 0x02024140
_0803ED38: .4byte 0x082EC664
_0803ED3C:
	subs r0, r5, r0
_0803ED3E:
	strb r0, [r3]
_0803ED40:
	ldr r1, _0803ED54
	ldr r0, _0803ED58
	ldr r0, [r0, #8]
	str r0, [r1]
	ldr r1, _0803ED5C
	movs r0, #0xa
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803ED54: .4byte 0x02023EB8
_0803ED58: .4byte 0x0828A2E0
_0803ED5C: .4byte 0x02023D27
	thumb_func_end HandleAction_ThrowPokeblock

	thumb_func_start HandleAction_GoNear
HandleAction_GoNear: @ 0x0803ED60
	push {r4, lr}
	ldr r2, _0803EDE0
	ldr r1, _0803EDE4
	ldr r0, _0803EDE8
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r0, _0803EDEC
	movs r4, #0
	strh r4, [r0]
	ldr r0, _0803EDF0
	strh r4, [r0]
	ldr r3, _0803EDF4
	ldr r0, [r3]
	adds r2, r0, #0
	adds r2, #0x7c
	ldr r1, _0803EDF8
	adds r0, #0x79
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x7c
	ldrb r0, [r1]
	cmp r0, #0x14
	bls _0803EDA2
	movs r0, #0x14
	strb r0, [r1]
_0803EDA2:
	ldr r0, [r3]
	adds r2, r0, #0
	adds r2, #0x7b
	ldr r1, _0803EDFC
	adds r0, #0x79
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x7b
	ldrb r0, [r1]
	cmp r0, #0x14
	bls _0803EDC8
	movs r0, #0x14
	strb r0, [r1]
_0803EDC8:
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0x79
	ldrb r0, [r1]
	cmp r0, #2
	bhi _0803EE04
	adds r0, #1
	strb r0, [r1]
	ldr r0, _0803EE00
	strb r4, [r0, #5]
	b _0803EE0A
	.align 2, 0
_0803EDE0: .4byte 0x02023EAF
_0803EDE4: .4byte 0x02023D22
_0803EDE8: .4byte 0x02023D26
_0803EDEC: .4byte 0x02022AC8
_0803EDF0: .4byte 0x02022ACA
_0803EDF4: .4byte 0x02024140
_0803EDF8: .4byte 0x082EC673
_0803EDFC: .4byte 0x082EC677
_0803EE00: .4byte 0x02023FD6
_0803EE04:
	ldr r1, _0803EE20
	movs r0, #1
	strb r0, [r1, #5]
_0803EE0A:
	ldr r1, _0803EE24
	ldr r0, _0803EE28
	ldr r0, [r0, #4]
	str r0, [r1]
	ldr r1, _0803EE2C
	movs r0, #0xa
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EE20: .4byte 0x02023FD6
_0803EE24: .4byte 0x02023EB8
_0803EE28: .4byte 0x0828A2E0
_0803EE2C: .4byte 0x02023D27
	thumb_func_end HandleAction_GoNear

	thumb_func_start HandleAction_SafariZoneRun
HandleAction_SafariZoneRun: @ 0x0803EE30
	push {r4, lr}
	ldr r2, _0803EE58
	ldr r1, _0803EE5C
	ldr r4, _0803EE60
	ldrb r0, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r2]
	movs r0, #0x11
	bl PlaySE
	ldr r0, _0803EE64
	ldrb r0, [r0]
	strb r0, [r4]
	ldr r1, _0803EE68
	movs r0, #4
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803EE58: .4byte 0x02023EAF
_0803EE5C: .4byte 0x02023D22
_0803EE60: .4byte 0x02023D26
_0803EE64: .4byte 0x02023D10
_0803EE68: .4byte 0x02023FDE
	thumb_func_end HandleAction_SafariZoneRun

	thumb_func_start HandleAction_WallyBallThrow
HandleAction_WallyBallThrow: @ 0x0803EE6C
	ldr r3, _0803EEB8
	ldr r1, _0803EEBC
	ldr r0, _0803EEC0
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r2, [r0]
	strb r2, [r3]
	ldr r0, _0803EEC4
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EEC8
	strh r1, [r0]
	ldr r1, _0803EECC
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #7
	strb r0, [r1, #1]
	strb r2, [r1, #2]
	ldr r2, _0803EED0
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _0803EED4
	ldr r0, _0803EED8
	ldr r0, [r0, #0xc]
	str r0, [r1]
	ldr r1, _0803EEDC
	movs r0, #0xa
	strb r0, [r1]
	ldr r1, _0803EEE0
	movs r0, #0xc
	strb r0, [r1, #1]
	bx lr
	.align 2, 0
_0803EEB8: .4byte 0x02023EAF
_0803EEBC: .4byte 0x02023D22
_0803EEC0: .4byte 0x02023D26
_0803EEC4: .4byte 0x02022AC8
_0803EEC8: .4byte 0x02022ACA
_0803EECC: .4byte 0x02022C0C
_0803EED0: .4byte 0x02023D12
_0803EED4: .4byte 0x02023EB8
_0803EED8: .4byte 0x0828A2E0
_0803EEDC: .4byte 0x02023D27
_0803EEE0: .4byte 0x02023D1E
	thumb_func_end HandleAction_WallyBallThrow

	thumb_func_start sub_0803EEE4
sub_0803EEE4: @ 0x0803EEE4
	push {lr}
	bl HandleFaintedMonActions
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0803EF00
	ldr r0, _0803EF04
	ldr r0, [r0]
	adds r0, #0x4d
	strb r1, [r0]
	ldr r1, _0803EF08
	movs r0, #0xc
	strb r0, [r1]
_0803EF00:
	pop {r0}
	bx r0
	.align 2, 0
_0803EF04: .4byte 0x02024140
_0803EF08: .4byte 0x02023D27
	thumb_func_end sub_0803EEE4

	thumb_func_start HandleAction_NothingIsFainted
HandleAction_NothingIsFainted: @ 0x0803EF0C
	ldr r1, _0803EF2C
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r3, _0803EF30
	ldr r2, _0803EF34
	ldrb r0, [r1]
	adds r0, r0, r2
	ldrb r0, [r0]
	strb r0, [r3]
	ldr r2, _0803EF38
	ldr r0, [r2]
	ldr r1, _0803EF3C
	ands r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0803EF2C: .4byte 0x02023D26
_0803EF30: .4byte 0x02023D27
_0803EF34: .4byte 0x02023D1E
_0803EF38: .4byte 0x02023F24
_0803EF3C: .4byte 0xF1E892AF
	thumb_func_end HandleAction_NothingIsFainted

	thumb_func_start HandleAction_ActionFinished
HandleAction_ActionFinished: @ 0x0803EF40
	push {r4, r5, r6, lr}
	ldr r1, _0803EFC8
	ldr r2, _0803EFCC
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r6, _0803EFD0
	ldr r1, [r6]
	adds r0, r0, r1
	adds r0, #0x5c
	movs r1, #6
	strb r1, [r0]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldr r3, _0803EFD4
	ldr r1, _0803EFD8
	ldrb r0, [r2]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	bl SpecialStatusesClear
	ldr r2, _0803EFDC
	ldr r0, [r2]
	ldr r1, _0803EFE0
	ands r0, r1
	str r0, [r2]
	ldr r0, _0803EFE4
	movs r1, #0
	strh r1, [r0]
	ldr r0, _0803EFE8
	movs r4, #0
	str r4, [r0]
	ldr r0, _0803EFEC
	strb r1, [r0]
	ldr r5, _0803EFF0
	strb r1, [r5, #0x18]
	strb r1, [r5, #0x19]
	ldr r2, _0803EFF4
	ldr r3, _0803EFF8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	strh r4, [r0]
	ldr r2, _0803EFFC
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	strh r4, [r0]
	ldr r0, [r6]
	strb r1, [r0, #0x13]
	ldr r0, _0803F000
	strh r4, [r0]
	strb r1, [r5, #0x14]
	ldr r0, _0803F004
	strb r1, [r0, #3]
	strb r1, [r0, #4]
	strb r1, [r5, #0x16]
	ldr r0, _0803F008
	ldr r0, [r0]
	ldr r0, [r0, #8]
	adds r0, #0x20
	strb r1, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803EFC8: .4byte 0x02023D22
_0803EFCC: .4byte 0x02023D26
_0803EFD0: .4byte 0x02024140
_0803EFD4: .4byte 0x02023D27
_0803EFD8: .4byte 0x02023D1E
_0803EFDC: .4byte 0x02023F24
_0803EFE0: .4byte 0xF1E892AF
_0803EFE4: .4byte 0x02023E8E
_0803EFE8: .4byte 0x02023E94
_0803EFEC: .4byte 0x02023F20
_0803EFF0: .4byte 0x02024118
_0803EFF4: .4byte 0x02023EF4
_0803EFF8: .4byte 0x02023EAF
_0803EFFC: .4byte 0x02023EFC
_0803F000: .4byte 0x020240A4
_0803F004: .4byte 0x02023FD6
_0803F008: .4byte 0x0202414C
	thumb_func_end HandleAction_ActionFinished
