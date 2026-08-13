.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start TryEvolvePokemon
TryEvolvePokemon: @ 0x0803DAF4
	push {r4, r5, r6, lr}
	ldr r0, _0803DB4C
	ldrb r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _0803DB6E
_0803DB00:
	movs r6, #0
_0803DB02:
	ldrb r2, [r3]
	ldr r0, _0803DB50
	lsls r1, r6, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0803DB60
	bics r2, r1
	strb r2, [r3]
	movs r0, #0x64
	adds r1, r6, #0
	muls r1, r0, r1
	ldr r0, _0803DB54
	adds r5, r1, r0
	adds r0, r5, #0
	movs r1, #0
	bl GetEvolutionTargetSpecies
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0803DB60
	bl FreeAllWindowBuffers
	ldr r0, _0803DB58
	ldr r1, _0803DB5C
	str r1, [r0]
	lsls r3, r6, #0x18
	lsrs r3, r3, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl EvolutionScene
	b _0803DB74
	.align 2, 0
_0803DB4C: .4byte 0x03005AB4
_0803DB50: .4byte 0x082FACB4
_0803DB54: .4byte 0x02024190
_0803DB58: .4byte 0x03005A64
_0803DB5C: .4byte 0x0803DB89
_0803DB60:
	adds r6, #1
	ldr r3, _0803DB7C
	cmp r6, #5
	ble _0803DB02
	ldrb r0, [r3]
	cmp r0, #0
	bne _0803DB00
_0803DB6E:
	ldr r1, _0803DB80
	ldr r0, _0803DB84
	str r0, [r1]
_0803DB74:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0803DB7C: .4byte 0x03005AB4
_0803DB80: .4byte 0x03005A64
_0803DB84: .4byte 0x0803DBB1
	thumb_func_end TryEvolvePokemon
