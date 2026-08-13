.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start SetPlayerBerryDataInBattleStruct
SetPlayerBerryDataInBattleStruct: @ 0x08036998
	push {r4, r5, r6, r7, lr}
	ldr r0, _08036A00
	ldr r5, [r0]
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r4, r5, r0
	bl IsEnigmaBerryValid
	cmp r0, #1
	bne _08036A14
	movs r2, #0
	ldr r7, _08036A04
	movs r1, #0xc6
	lsls r1, r1, #1
	adds r5, r5, r1
	adds r6, r7, #0
	ldr r3, _08036A08
_080369BA:
	adds r0, r4, r2
	ldr r1, [r6]
	adds r1, r1, r3
	adds r1, r1, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #5
	ble _080369BA
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	movs r2, #0
	adds r3, r5, #0
	ldr r6, _08036A04
	ldr r5, _08036A0C
_080369DA:
	adds r0, r3, r2
	ldr r1, [r6]
	adds r1, r1, r5
	adds r1, r1, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0x11
	ble _080369DA
	ldr r0, [r7]
	ldr r1, _08036A10
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r4, #7]
	ldr r0, [r7]
	adds r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	b _08036A54
	.align 2, 0
_08036A00: .4byte 0x02024140
_08036A04: .4byte 0x03005AEC
_08036A08: .4byte 0x000031F8
_08036A0C: .4byte 0x00003214
_08036A10: .4byte 0x00003226
_08036A14:
	movs r0, #0xaf
	bl ItemIdToBerryType
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBerryInfo
	adds r3, r0, #0
	movs r2, #0
	movs r0, #0xc6
	lsls r0, r0, #1
	adds r5, r5, r0
_08036A2C:
	adds r0, r4, r2
	adds r1, r3, r2
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #5
	ble _08036A2C
	adds r1, r4, r2
	movs r0, #0xff
	strb r0, [r1]
	adds r0, r5, #0
	movs r2, #0
	adds r1, r0, #0
	adds r1, #0x11
_08036A48:
	strb r2, [r1]
	subs r1, #1
	cmp r1, r0
	bge _08036A48
	movs r0, #0
	strb r0, [r4, #7]
_08036A54:
	strb r0, [r4, #0x1a]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	thumb_func_end SetPlayerBerryDataInBattleStruct

