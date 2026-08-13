.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start HandleEndTurn_FinishBattle
HandleEndTurn_FinishBattle: @ 0x0803D918
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r0, _0803D994
	ldrb r0, [r0]
	subs r0, #0xb
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0803D92E
	b _0803DA50
_0803D92E:
	ldr r0, _0803D998
	ldr r1, [r0]
	ldr r0, _0803D99C
	ands r1, r0
	cmp r1, #0
	bne _0803D9F6
	ldr r2, _0803D9A0
	strb r1, [r2]
	ldr r0, _0803D9A4
	ldrb r0, [r0]
	cmp r1, r0
	bhs _0803D9F2
	adds r5, r2, #0
	ldr r0, _0803D9A8
	mov r8, r0
	movs r7, #0x64
	ldr r6, _0803D9AC
_0803D950:
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803D9E0
	ldr r4, _0803D9B0
	ldrh r0, [r4, #6]
	cmp r0, #0
	bne _0803D9B4
	ldrb r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7, r0
	adds r0, r0, r6
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	strh r0, [r4, #6]
	ldrb r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7, r0
	adds r0, r0, r6
	movs r1, #2
	adds r2, r4, #0
	adds r2, #8
	bl GetMonData3
	b _0803D9E0
	.align 2, 0
_0803D994: .4byte 0x02023D27
_0803D998: .4byte 0x02022C90
_0803D99C: .4byte 0x023F0B92
_0803D9A0: .4byte 0x02023D08
_0803D9A4: .4byte 0x02023D10
_0803D9A8: .4byte 0x02023D12
_0803D9AC: .4byte 0x02024190
_0803D9B0: .4byte 0x03005A70
_0803D9B4:
	ldrb r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7, r0
	adds r0, r0, r6
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	strh r0, [r4, #0x26]
	ldrb r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	muls r0, r7, r0
	adds r0, r0, r6
	movs r1, #2
	adds r2, r4, #0
	adds r2, #0x14
	bl GetMonData3
_0803D9E0:
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	ldr r1, _0803DA30
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _0803D950
_0803D9F2:
	bl PutPokemonTodayCaughtOnAir
_0803D9F6:
	ldr r0, _0803DA34
	ldr r0, [r0]
	ldr r1, _0803DA38
	ands r0, r1
	cmp r0, #0
	bne _0803DA12
	ldr r0, _0803DA3C
	ldrb r1, [r0, #5]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803DA12
	bl sub_080EECA4
_0803DA12:
	bl sub_0818619C
	movs r0, #3
	bl BeginFastPaletteFade
	movs r0, #5
	bl FadeOutMapMusic
	ldr r1, _0803DA40
	ldr r0, _0803DA44
	str r0, [r1]
	ldr r1, _0803DA48
	ldr r0, _0803DA4C
	str r0, [r1]
	b _0803DA6A
	.align 2, 0
_0803DA30: .4byte 0x02023D10
_0803DA34: .4byte 0x02022C90
_0803DA38: .4byte 0x023F0B9A
_0803DA3C: .4byte 0x03005A70
_0803DA40: .4byte 0x03005A64
_0803DA44: .4byte 0x0803DA81
_0803DA48: .4byte 0x03005F28
_0803DA4C: .4byte 0x080380FD
_0803DA50:
	ldr r0, _0803DA74
	ldr r0, [r0]
	cmp r0, #0
	bne _0803DA6A
	ldr r1, _0803DA78
	ldr r0, _0803DA7C
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_0803DA6A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803DA74: .4byte 0x02023D0C
_0803DA78: .4byte 0x082EC694
_0803DA7C: .4byte 0x02023EB8
	thumb_func_end HandleEndTurn_FinishBattle
