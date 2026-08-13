.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start RunBattleScriptCommands
RunBattleScriptCommands: @ 0x0803D45C
	push {r4, r5, r6, lr}
	ldr r6, _0803D4B0
	ldrb r0, [r6]
	ldr r2, _0803D4B4
	cmp r0, #0
	beq _0803D46C
	movs r0, #0xc
	strb r0, [r2]
_0803D46C:
	ldr r5, _0803D4B8
	ldr r0, [r5]
	adds r0, #0x4b
	ldr r4, _0803D4BC
	ldrb r1, [r4]
	strb r1, [r0]
	ldr r1, _0803D4C0
	ldrb r0, [r2]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, _0803D4C4
	thumb_func_end RunBattleScriptCommands

	thumb_func_start RunTurnActionsFunctions
RunTurnActionsFunctions: @ 0x0803D488
	ldrb r1, [r4]
	ldrb r0, [r0]
	cmp r1, r0
	blo _0803D4D8
	ldr r2, _0803D4C8
	ldr r0, [r2]
	ldr r1, _0803D4CC
	ands r0, r1
	str r0, [r2]
	ldr r3, _0803D4D0
	ldr r2, _0803D4D4
	ldrb r1, [r6]
	movs r0, #0x7f
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	str r0, [r3]
	b _0803D4F0
	.align 2, 0
_0803D4B0: .4byte 0x02023FDE
_0803D4B4: .4byte 0x02023D27
_0803D4B8: .4byte 0x02024140
_0803D4BC: .4byte 0x02023D26
_0803D4C0: .4byte 0x082EC600
_0803D4C4: .4byte 0x02023D10
_0803D4C8: .4byte 0x02023F24
_0803D4CC: .4byte 0xFFEFFFFF
_0803D4D0: .4byte 0x03005A64
_0803D4D4: .4byte 0x082EC638
_0803D4D8:
	ldr r0, [r5]
	adds r0, #0x4b
	ldrb r0, [r0]
	cmp r0, r1
	beq _0803D4F0
	ldr r2, _0803D4F8
	ldr r0, [r2]
	ldr r1, _0803D4FC
	ands r0, r1
	ldr r1, _0803D500
	ands r0, r1
	str r0, [r2]
_0803D4F0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803D4F8: .4byte 0x02023F24
_0803D4FC: .4byte 0xFFFFFDFF
_0803D500: .4byte 0xFFF7FFFF
	thumb_func_end RunTurnActionsFunctions
