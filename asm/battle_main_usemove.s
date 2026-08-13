.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_0803DCCC
sub_0803DCCC: @ 0x0803DCCC
	push {lr}
	ldr r0, _0803DCEC
	ldr r0, [r0]
	cmp r0, #0
	bne _0803DCE8
	ldr r1, _0803DCF0
	ldr r0, _0803DCF4
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0803DCE8:
	pop {r0}
	bx r0
	.align 2, 0
_0803DCEC: .4byte 0x02023D0C
_0803DCF0: .4byte 0x082EC694
_0803DCF4: .4byte 0x02023EB8
	thumb_func_end sub_0803DCCC















































	thumb_func_start HandleAction_UseMove
HandleAction_UseMove: @ 0x0803DCF8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	movs r0, #4
	str r0, [sp]
	ldr r6, _0803DD38
	ldr r1, _0803DD3C
	ldr r0, _0803DD40
	ldrb r0, [r0]
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r6]
	ldr r1, _0803DD44
	ldr r3, [r1]
	adds r0, r3, #0
	adds r0, #0x91
	ldrb r2, [r0]
	ldr r1, _0803DD48
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r2, r0
	cmp r2, #0
	beq _0803DD50
	ldr r1, _0803DD4C
	movs r0, #0xc
	b _0803E47C
	.align 2, 0
_0803DD38: .4byte 0x02023EAF
_0803DD3C: .4byte 0x02023D22
_0803DD40: .4byte 0x02023D26
_0803DD44: .4byte 0x02024140
_0803DD48: .4byte 0x082FACB4
_0803DD4C: .4byte 0x02023D27
_0803DD50:
	ldr r1, _0803DDC8
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0803DDCC
	movs r0, #1
	strb r0, [r1, #0xe]
	ldr r5, _0803DDD0
	adds r0, r3, r5
	strb r2, [r0]
	ldr r0, _0803DDD4
	strb r2, [r0]
	ldr r0, _0803DDD8
	strb r2, [r0]
	ldr r0, _0803DDDC
	strb r2, [r0, #6]
	ldr r2, _0803DDE0
	ldr r0, _0803DDE4
	mov sb, r0
	ldrb r0, [r6]
	ldr r3, _0803DDE8
	ldr r1, [r3]
	adds r0, r0, r1
	adds r0, #0x80
	ldrb r0, [r0]
	mov r5, sb
	strb r0, [r5]
	strb r0, [r2]
	ldr r1, _0803DDEC
	ldrb r4, [r6]
	lsls r0, r4, #4
	adds r3, r0, r1
	ldrb r1, [r3]
	lsls r0, r1, #0x1d
	mov r8, r2
	cmp r0, #0
	bge _0803DDFC
	movs r0, #5
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldr r2, _0803DDF0
	ldr r1, _0803DDF4
	movs r0, #0xa5
	strh r0, [r1]
	strh r0, [r2]
	ldr r2, _0803DDF8
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xa5
	movs r1, #0
	bl GetMoveTarget
	ldrb r1, [r6]
	ldr r3, _0803DDE8
	ldr r2, [r3]
	b _0803DF56
	.align 2, 0
_0803DDC8: .4byte 0x02023EB5
_0803DDCC: .4byte 0x02024118
_0803DDD0: .4byte 0x000001A3
_0803DDD4: .4byte 0x02023F20
_0803DDD8: .4byte 0x02023EB6
_0803DDDC: .4byte 0x02023FD6
_0803DDE0: .4byte 0x02023E8C
_0803DDE4: .4byte 0x02023E8D
_0803DDE8: .4byte 0x02024140
_0803DDEC: .4byte 0x02023FE0
_0803DDF0: .4byte 0x02023E8E
_0803DDF4: .4byte 0x02023E90
_0803DDF8: .4byte 0x02023F24
_0803DDFC:
	ldr r5, _0803DE34
	mov sl, r5
	movs r0, #0x58
	adds r5, r4, #0
	muls r5, r0, r5
	mov r0, sl
	adds r0, #0x50
	adds r0, r5, r0
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	bne _0803DE22
	movs r7, #0x80
	lsls r7, r7, #0xf
	ands r7, r1
	cmp r7, #0
	beq _0803DE44
_0803DE22:
	ldr r3, _0803DE38
	ldr r2, _0803DE3C
	ldr r1, _0803DE40
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	strh r0, [r2]
	strh r0, [r3]
	b _0803DF7C
	.align 2, 0
_0803DE34: .4byte 0x02023D28
_0803DE38: .4byte 0x02023E8E
_0803DE3C: .4byte 0x02023E90
_0803DE40: .4byte 0x02023F0C
_0803DE44:
	ldr r1, _0803DE98
	mov ip, r1
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	add r0, ip
	ldrh r3, [r0, #6]
	adds r1, r3, #0
	cmp r1, #0
	beq _0803DF1C
	ldrb r2, [r0, #0xc]
	lsls r0, r2, #1
	adds r0, r0, r5
	mov r4, sl
	adds r4, #0xc
	adds r0, r0, r4
	ldrh r0, [r0]
	cmp r1, r0
	bne _0803DEA8
	ldr r2, _0803DE9C
	ldr r0, _0803DEA0
	strh r3, [r0]
	strh r3, [r2]
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0, #0xc]
	mov r3, sb
	strb r0, [r3]
	mov r5, r8
	strb r0, [r5]
	ldrh r0, [r2]
	movs r1, #0
	bl GetMoveTarget
	ldrb r1, [r6]
	ldr r3, _0803DEA4
	ldr r2, [r3]
	b _0803DF56
	.align 2, 0
_0803DE98: .4byte 0x02023F60
_0803DE9C: .4byte 0x02023E8E
_0803DEA0: .4byte 0x02023E90
_0803DEA4: .4byte 0x02024140
_0803DEA8:
	cmp r1, #0
	beq _0803DF1C
	cmp r1, r0
	beq _0803DF1C
	mov r5, sb
	strb r2, [r5]
	mov r0, r8
	strb r2, [r0]
	ldr r3, _0803DF10
	ldr r2, _0803DF14
	ldrb r0, [r0]
	lsls r0, r0, #1
	ldrb r1, [r6]
	movs r5, #0x58
	muls r1, r5, r1
	adds r0, r0, r1
	adds r0, r0, r4
	ldrh r0, [r0]
	strh r0, [r2]
	strh r0, [r3]
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	movs r2, #0
	strh r7, [r0, #6]
	ldrb r1, [r6]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	add r0, ip
	strb r2, [r0, #0xc]
	ldrb r0, [r6]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	add r1, ip
	ldrb r2, [r1, #0xe]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r2
	strb r0, [r1, #0xe]
	ldrh r0, [r3]
	movs r1, #0
	bl GetMoveTarget
	ldrb r1, [r6]
	ldr r3, _0803DF18
	ldr r2, [r3]
	b _0803DF56
	.align 2, 0
_0803DF10: .4byte 0x02023E8E
_0803DF14: .4byte 0x02023E90
_0803DF18: .4byte 0x02024140
_0803DF1C:
	ldr r3, _0803DF5C
	mov r5, r8
	ldrb r0, [r5]
	lsls r0, r0, #1
	ldr r4, _0803DF60
	ldrb r2, [r4]
	movs r1, #0x58
	muls r1, r2, r1
	adds r0, r0, r1
	adds r3, #0xc
	adds r0, r0, r3
	ldr r1, _0803DF64
	lsls r2, r2, #1
	adds r2, r2, r1
	ldrh r3, [r0]
	ldrh r2, [r2]
	cmp r3, r2
	beq _0803DF74
	ldr r1, _0803DF68
	ldr r0, _0803DF6C
	strh r3, [r0]
	strh r3, [r1]
	ldrh r0, [r1]
	movs r1, #0
	bl GetMoveTarget
	ldrb r1, [r4]
	ldr r2, _0803DF70
	ldr r2, [r2]
_0803DF56:
	adds r1, r1, r2
	strb r0, [r1, #0xc]
	b _0803DF7C
	.align 2, 0
_0803DF5C: .4byte 0x02023D28
_0803DF60: .4byte 0x02023EAF
_0803DF64: .4byte 0x02023F18
_0803DF68: .4byte 0x02023E8E
_0803DF6C: .4byte 0x02023E90
_0803DF70: .4byte 0x02024140
_0803DF74:
	ldr r1, _0803DFA8
	ldr r0, _0803DFAC
	strh r3, [r0]
	strh r3, [r1]
_0803DF7C:
	ldr r2, _0803DFB0
	ldr r1, _0803DFB4
	ldrb r3, [r1]
	movs r0, #0x58
	muls r0, r3, r0
	adds r0, r0, r2
	ldrh r0, [r0, #0x28]
	mov r8, r1
	cmp r0, #0
	beq _0803DFC4
	adds r0, r3, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803DFBC
	ldr r0, _0803DFB8
	ldr r1, _0803DFA8
	ldrh r1, [r1]
	strh r1, [r0, #0x22]
	b _0803DFC4
	.align 2, 0
_0803DFA8: .4byte 0x02023E8E
_0803DFAC: .4byte 0x02023E90
_0803DFB0: .4byte 0x02023D28
_0803DFB4: .4byte 0x02023EAF
_0803DFB8: .4byte 0x03005A70
_0803DFBC:
	ldr r0, _0803E028
	ldr r1, _0803E02C
	ldrh r1, [r1]
	strh r1, [r0, #0x24]
_0803DFC4:
	mov r1, r8
	ldrb r0, [r1]
	bl GetBattlerSide
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _0803E030
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r5, r0, r1
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _0803E040
	ldr r2, _0803E034
	ldr r0, _0803E02C
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #6]
	cmp r0, #0
	bne _0803E040
	mov r3, r8
	ldrb r0, [r3]
	bl GetBattlerSide
	adds r4, r0, #0
	ldrb r0, [r5, #9]
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0803E040
	ldr r1, _0803E038
	ldrb r2, [r5, #9]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _0803E040
	ldr r0, _0803E03C
	strb r2, [r0]
	b _0803E3AA
	.align 2, 0
_0803E028: .4byte 0x03005A70
_0803E02C: .4byte 0x02023E8E
_0803E030: .4byte 0x02023F38
_0803E034: .4byte 0x082ED220
_0803E038: .4byte 0x02023D28
_0803E03C: .4byte 0x02023EB0
_0803E040:
	ldr r0, _0803E15C
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r5, _0803E160
	mov r8, r5
	cmp r0, #0
	bne _0803E052
	b _0803E320
_0803E052:
	ldr r1, _0803E164
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r5, [r0, #8]
	cmp r5, #0
	beq _0803E064
	b _0803E270
_0803E064:
	ldr r2, _0803E168
	ldr r0, _0803E16C
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r4, r0, r2
	ldrb r0, [r4, #1]
	cmp r0, #0
	bne _0803E080
	ldrb r0, [r4, #6]
	cmp r0, #0x10
	bne _0803E080
	b _0803E270
_0803E080:
	ldr r3, _0803E170
	ldr r2, _0803E160
	ldrb r6, [r2]
	ldr r0, _0803E174
	ldr r0, [r0]
	adds r0, r6, r0
	ldrb r1, [r0, #0xc]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r0, [r0]
	mov r8, r2
	cmp r0, #0x1f
	bne _0803E0A0
	b _0803E270
_0803E0A0:
	ldrb r0, [r4, #2]
	cmp r0, #0xd
	beq _0803E0A8
	b _0803E270
_0803E0A8:
	adds r0, r6, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r1, _0803E178
	strb r5, [r1]
	ldr r0, _0803E17C
	ldrb r0, [r0]
	cmp r5, r0
	bhs _0803E120
	adds r4, r1, #0
_0803E0C0:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r0
	beq _0803E10E
	ldr r0, _0803E160
	ldrb r1, [r0]
	ldr r0, _0803E174
	ldr r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r1, #0xc]
	ldrb r1, [r4]
	cmp r0, r1
	beq _0803E10E
	ldr r1, _0803E170
	ldrb r2, [r4]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x1f
	bne _0803E10E
	adds r0, r2, #0
	bl GetBattlerTurnOrderNum
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r3, [sp]
	cmp r0, r3
	bhs _0803E10E
	ldrb r0, [r4]
	bl GetBattlerTurnOrderNum
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
_0803E10E:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _0803E17C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803E0C0
_0803E120:
	ldr r5, [sp]
	cmp r5, #4
	beq _0803E128
	b _0803E222
_0803E128:
	ldr r2, _0803E168
	ldr r0, _0803E180
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0, #6]
	ands r5, r0
	cmp r5, #0
	beq _0803E1A8
	ldr r0, _0803E160
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E188
	bl Random
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0803E184
	movs r0, #1
	b _0803E19A
	.align 2, 0
_0803E15C: .4byte 0x02022C90
_0803E160: .4byte 0x02023EAF
_0803E164: .4byte 0x02023F38
_0803E168: .4byte 0x082ED220
_0803E16C: .4byte 0x02023E8E
_0803E170: .4byte 0x02023D28
_0803E174: .4byte 0x02024140
_0803E178: .4byte 0x02023D08
_0803E17C: .4byte 0x02023D10
_0803E180: .4byte 0x02023E90
_0803E184:
	movs r0, #3
	b _0803E19A
_0803E188:
	bl Random
	movs r1, #1
	ands r1, r0
	cmp r1, #0
	beq _0803E198
	movs r0, #0
	b _0803E19A
_0803E198:
	movs r0, #2
_0803E19A:
	bl GetBattlerAtPosition
	ldr r1, _0803E1A4
	strb r0, [r1]
	b _0803E1B8
	.align 2, 0
_0803E1A4: .4byte 0x02023EB0
_0803E1A8:
	ldr r2, _0803E1F0
	ldr r0, _0803E1F4
	ldrb r0, [r0]
	ldr r1, _0803E1F8
	ldr r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0, #0xc]
	strb r0, [r2]
_0803E1B8:
	ldr r7, _0803E1FC
	ldrb r0, [r7]
	ldr r1, _0803E200
	mov r8, r1
	ldr r5, _0803E1F0
	ldrb r1, [r5]
	lsls r1, r1, #2
	add r1, r8
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0803E1D2
	b _0803E3AA
_0803E1D2:
	ldr r6, _0803E1F4
	ldrb r0, [r6]
	bl GetBattlerSide
	adds r4, r0, #0
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0803E204
	ldrb r0, [r5]
	b _0803E398
	.align 2, 0
_0803E1F0: .4byte 0x02023EB0
_0803E1F4: .4byte 0x02023EAF
_0803E1F8: .4byte 0x02024140
_0803E1FC: .4byte 0x02023EB4
_0803E200: .4byte 0x082FACB4
_0803E204:
	ldrb r0, [r6]
	bl GetBattlerPosition
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	strb r0, [r5]
	ldrb r1, [r7]
	ldrb r2, [r5]
	lsls r0, r2, #2
	add r0, r8
	b _0803E38E
_0803E222:
	ldr r4, _0803E25C
	ldr r0, _0803E260
	ldr r3, [sp]
	adds r0, r3, r0
	ldrb r0, [r0]
	strb r0, [r4]
	ldrb r0, [r4]
	ldr r2, _0803E264
	movs r1, #0x58
	muls r1, r0, r1
	adds r1, r1, r2
	adds r1, #0x20
	ldrb r1, [r1]
	bl RecordAbilityBattle
	ldr r2, _0803E268
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0]
	movs r2, #2
	orrs r1, r2
	strb r1, [r0]
	ldr r1, _0803E26C
	ldrb r0, [r4]
	strb r0, [r1]
	b _0803E3AA
	.align 2, 0
_0803E25C: .4byte 0x02023D08
_0803E260: .4byte 0x02023D22
_0803E264: .4byte 0x02023D28
_0803E268: .4byte 0x02024020
_0803E26C: .4byte 0x02023EB0
_0803E270:
	ldr r0, _0803E2B4
	ldr r0, [r0]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _0803E320
	ldr r2, _0803E2B8
	ldr r0, _0803E2BC
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0, #6]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0803E320
	mov r5, r8
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803E2C4
	bl Random
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _0803E2C0
	movs r0, #1
	b _0803E2D6
	.align 2, 0
_0803E2B4: .4byte 0x02022C90
_0803E2B8: .4byte 0x082ED220
_0803E2BC: .4byte 0x02023E90
_0803E2C0:
	movs r0, #3
	b _0803E2D6
_0803E2C4:
	bl Random
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _0803E2D4
	movs r0, #0
	b _0803E2D6
_0803E2D4:
	movs r0, #2
_0803E2D6:
	bl GetBattlerAtPosition
	ldr r1, _0803E310
	strb r0, [r1]
	ldr r0, _0803E314
	ldrb r1, [r0]
	ldr r2, _0803E318
	ldr r5, _0803E310
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0803E3AA
	ldr r0, _0803E31C
	ldrb r0, [r0]
	bl GetBattlerSide
	adds r4, r0, #0
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0803E3AA
	ldrb r0, [r5]
	b _0803E398
	.align 2, 0
_0803E310: .4byte 0x02023EB0
_0803E314: .4byte 0x02023EB4
_0803E318: .4byte 0x082FACB4
_0803E31C: .4byte 0x02023EAF
_0803E320:
	ldr r5, _0803E360
	mov r2, r8
	ldrb r0, [r2]
	ldr r1, _0803E364
	ldr r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0, #0xc]
	strb r0, [r5]
	ldr r6, _0803E368
	ldrb r1, [r6]
	ldr r7, _0803E36C
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0803E3AA
	ldrb r0, [r2]
	bl GetBattlerSide
	adds r4, r0, #0
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	beq _0803E370
	ldrb r0, [r5]
	b _0803E398
	.align 2, 0
_0803E360: .4byte 0x02023EB0
_0803E364: .4byte 0x02024140
_0803E368: .4byte 0x02023EB4
_0803E36C: .4byte 0x082FACB4
_0803E370:
	mov r1, r8
	ldrb r0, [r1]
	bl GetBattlerPosition
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	strb r0, [r5]
	ldrb r1, [r6]
	ldrb r2, [r5]
	lsls r0, r2, #2
	adds r0, r0, r7
_0803E38E:
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0803E3AA
	adds r0, r2, #0
_0803E398:
	bl GetBattlerPosition
	movs r1, #2
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	strb r0, [r5]
_0803E3AA:
	ldr r0, _0803E3E0
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #0xa
	ands r1, r2
	adds r5, r0, #0
	cmp r1, #0
	beq _0803E448
	ldr r0, _0803E3E4
	ldr r4, _0803E3E8
	ldrb r2, [r4]
	lsls r1, r2, #4
	adds r1, r1, r0
	ldrb r0, [r1, #2]
	lsls r0, r0, #0x1b
	cmp r0, #0
	bge _0803E448
	ldr r1, _0803E3EC
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _0803E3F4
	ldr r1, _0803E3F0
	movs r0, #0xc
	b _0803E47C
	.align 2, 0
_0803E3E0: .4byte 0x02022C90
_0803E3E4: .4byte 0x02023FE0
_0803E3E8: .4byte 0x02023EAF
_0803E3EC: .4byte 0x02023D28
_0803E3F0: .4byte 0x02023D27
_0803E3F4:
	ldr r3, _0803E420
	lsls r0, r2, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _0803E42C
	ldr r1, _0803E424
	movs r2, #0
	movs r0, #4
	strb r0, [r1, #5]
	ldr r1, _0803E428
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r3
	str r2, [r0]
	b _0803E464
	.align 2, 0
_0803E420: .4byte 0x02023ED4
_0803E424: .4byte 0x02023FD6
_0803E428: .4byte 0x02023EB8
_0803E42C:
	ldr r1, _0803E43C
	movs r0, #4
	strb r0, [r1, #5]
	ldr r1, _0803E440
	ldr r0, _0803E444
	str r0, [r1]
	b _0803E464
	.align 2, 0
_0803E43C: .4byte 0x02023FD6
_0803E440: .4byte 0x02023EB8
_0803E444: .4byte 0x08289C35
_0803E448:
	ldr r4, _0803E490
	ldr r3, _0803E494
	ldr r2, _0803E498
	ldr r0, _0803E49C
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r3
	ldr r0, [r0]
	str r0, [r4]
_0803E464:
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0803E478
	ldr r0, _0803E4A0
	ldrb r0, [r0]
	bl BattleArena_AddMindPoints
_0803E478:
	ldr r1, _0803E4A4
	movs r0, #0xa
_0803E47C:
	strb r0, [r1]
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803E490: .4byte 0x02023EB8
_0803E494: .4byte 0x08286C30
_0803E498: .4byte 0x082ED220
_0803E49C: .4byte 0x02023E8E
_0803E4A0: .4byte 0x02023EAF
_0803E4A4: .4byte 0x02023D27
	thumb_func_end HandleAction_UseMove

