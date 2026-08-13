.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start HandleEndTurn_BattleLost
HandleEndTurn_BattleLost: @ 0x0803D700
	push {r4, lr}
	ldr r1, _0803D748
	movs r0, #0
	strb r0, [r1]
	ldr r0, _0803D74C
	ldr r1, [r0]
	ldr r0, _0803D750
	ands r0, r1
	cmp r0, #0
	beq _0803D7BC
	ldr r0, _0803D754
	ands r1, r0
	cmp r1, #0
	beq _0803D784
	ldr r3, _0803D758
	ldrb r2, [r3]
	movs r0, #0x80
	ands r0, r2
	cmp r0, #0
	beq _0803D76C
	ldr r1, _0803D75C
	ldr r0, _0803D760
	str r0, [r1]
	movs r0, #0x7f
	ands r0, r2
	strb r0, [r3]
	ldr r0, _0803D764
	ldr r1, [r0]
	ldr r0, _0803D768
	adds r1, r1, r0
	ldrb r0, [r1]
	movs r2, #8
	orrs r0, r2
	strb r0, [r1]
	b _0803D7C2
	.align 2, 0
_0803D748: .4byte 0x02023D27
_0803D74C: .4byte 0x02022C90
_0803D750: .4byte 0x02000002
_0803D754: .4byte 0x003F0100
_0803D758: .4byte 0x02023FDE
_0803D75C: .4byte 0x02023EB8
_0803D760: .4byte 0x08289F50
_0803D764: .4byte 0x03005AF0
_0803D768: .4byte 0x00000CA9
_0803D76C:
	ldr r1, _0803D77C
	ldr r0, _0803D780
	str r0, [r1]
	movs r0, #0x7f
	ands r0, r2
	strb r0, [r3]
	b _0803D7C2
	.align 2, 0
_0803D77C: .4byte 0x02023EB8
_0803D780: .4byte 0x08288F93
_0803D784:
	ldr r1, _0803D7A8
	ldr r4, _0803D7AC
	ldrb r0, [r4]
	strb r0, [r1]
	movs r0, #0
	bl GetBattlerAtPosition
	ldr r1, _0803D7B0
	strb r0, [r1]
	ldr r1, _0803D7B4
	ldr r0, _0803D7B8
	str r0, [r1]
	ldrb r1, [r4]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r4]
	b _0803D7C2
	.align 2, 0
_0803D7A8: .4byte 0x02022C0C
_0803D7AC: .4byte 0x02023FDE
_0803D7B0: .4byte 0x02023EAF
_0803D7B4: .4byte 0x02023EB8
_0803D7B8: .4byte 0x08288FBD
_0803D7BC:
	ldr r1, _0803D7D0
	ldr r0, _0803D7D4
	str r0, [r1]
_0803D7C2:
	ldr r1, _0803D7D8
	ldr r0, _0803D7DC
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0803D7D0: .4byte 0x02023EB8
_0803D7D4: .4byte 0x08288EF5
_0803D7D8: .4byte 0x03005A64
_0803D7DC: .4byte 0x0803D919
	thumb_func_end HandleEndTurn_BattleLost
