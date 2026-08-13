.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleIntroRecordMonsToDex
BattleIntroRecordMonsToDex: @ 0x0803AF58
	push {r4, r5, r6, r7, lr}
	ldr r0, _0803AFD0
	ldr r1, [r0]
	cmp r1, #0
	bne _0803AFC8
	ldr r2, _0803AFD4
	strb r1, [r2]
	ldr r0, _0803AFD8
	ldrb r0, [r0]
	cmp r1, r0
	bhs _0803AFC2
	adds r4, r2, #0
	ldr r6, _0803AFDC
	movs r5, #0x58
	adds r7, r6, #0
	adds r7, #0x48
_0803AF78:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0803AFB0
	ldr r0, _0803AFE0
	ldr r0, [r0]
	ldr r1, _0803AFE4
	ands r0, r1
	cmp r0, #0
	bne _0803AFB0
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r0, r6
	ldrh r0, [r0]
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4]
	muls r1, r5, r1
	adds r1, r1, r7
	ldr r2, [r1]
	movs r1, #2
	bl HandleSetPokedexFlag
_0803AFB0:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	ldr r1, _0803AFD8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803AF78
_0803AFC2:
	ldr r1, _0803AFE8
	ldr r0, _0803AFEC
	str r0, [r1]
_0803AFC8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803AFD0: .4byte 0x02023D0C
_0803AFD4: .4byte 0x02023D08
_0803AFD8: .4byte 0x02023D10
_0803AFDC: .4byte 0x02023D28
_0803AFE0: .4byte 0x02022C90
_0803AFE4: .4byte 0x063F0902
_0803AFE8: .4byte 0x03005A64
_0803AFEC: .4byte 0x0803B011
	thumb_func_end BattleIntroRecordMonsToDex
