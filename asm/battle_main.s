.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified







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
