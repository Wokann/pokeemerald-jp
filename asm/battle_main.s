.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified











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
