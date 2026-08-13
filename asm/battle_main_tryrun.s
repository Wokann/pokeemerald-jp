.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start TryRunFromBattle
TryRunFromBattle: @ 0x0803E860
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r7, #0
	ldr r1, _0803E88C
	movs r0, #0x58
	muls r0, r5, r0
	adds r1, r0, r1
	ldrh r0, [r1, #0x2e]
	cmp r0, #0xaf
	bne _0803E894
	ldr r1, _0803E890
	lsls r0, r5, #3
	subs r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #7]
	b _0803E89E
	.align 2, 0
_0803E88C: .4byte 0x02023D28
_0803E890: .4byte 0x020240A8
_0803E894:
	ldrh r0, [r1, #0x2e]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0803E89E:
	ldr r0, _0803E8CC
	strb r5, [r0]
	cmp r1, #0x25
	bne _0803E8DC
	ldr r2, _0803E8D0
	ldr r1, _0803E8D4
	movs r0, #0x58
	muls r0, r5, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x2e]
	strh r0, [r2]
	ldr r0, _0803E8D8
	lsls r2, r5, #4
	adds r2, r2, r0
	ldrb r1, [r2, #1]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	strb r0, [r2, #1]
	b _0803E9B0
	.align 2, 0
_0803E8CC: .4byte 0x02023EB3
_0803E8D0: .4byte 0x02023EAC
_0803E8D4: .4byte 0x02023D28
_0803E8D8: .4byte 0x02023FE0
_0803E8DC:
	ldr r0, _0803E968
	mov sl, r0
	movs r2, #0x58
	mov sb, r2
	mov r0, sb
	muls r0, r5, r0
	add r0, sl
	mov r8, r0
	adds r0, #0x20
	ldrb r6, [r0]
	cmp r6, #0x32
	bne _0803E99C
	bl CurrentBattlePyramidLocation
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803E978
	ldr r4, _0803E96C
	ldr r1, [r4]
	adds r1, #0x6c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	bl GetPyramidRunMultiplier
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	mov r2, r8
	ldrh r0, [r2, #6]
	muls r0, r1, r0
	movs r2, #1
	adds r1, r5, #0
	eors r1, r2
	mov r2, sb
	muls r2, r1, r2
	adds r1, r2, #0
	add r1, sl
	ldrh r1, [r1, #6]
	bl __divsi3
	ldr r1, [r4]
	adds r1, #0x6c
	ldrb r2, [r1]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl Random
	movs r1, #0xff
	ands r1, r0
	cmp r4, r1
	bhi _0803E94C
	b _0803EA52
_0803E94C:
	ldr r0, _0803E970
	strb r6, [r0]
	ldr r0, _0803E974
	lsls r2, r5, #4
	adds r2, r2, r0
	ldrb r1, [r2, #1]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	b _0803E9B0
	.align 2, 0
_0803E968: .4byte 0x02023D28
_0803E96C: .4byte 0x02024140
_0803E970: .4byte 0x02023EAE
_0803E974: .4byte 0x02023FE0
_0803E978:
	ldr r0, _0803E994
	strb r6, [r0]
	ldr r0, _0803E998
	lsls r2, r5, #4
	adds r2, r2, r0
	ldrb r1, [r2, #1]
	movs r0, #0x19
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0x10
	orrs r0, r1
	strb r0, [r2, #1]
	b _0803E9B0
	.align 2, 0
_0803E994: .4byte 0x02023EAE
_0803E998: .4byte 0x02023FE0
_0803E99C:
	ldr r1, _0803E9B8
	ldr r2, [r1]
	ldr r0, _0803E9BC
	ands r0, r2
	cmp r0, #0
	beq _0803E9C0
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _0803E9C0
_0803E9B0:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	b _0803EA52
	.align 2, 0
_0803E9B8: .4byte 0x02022C90
_0803E9BC: .4byte 0x043F0100
_0803E9C0:
	ldr r0, [r1]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0803EA46
	bl CurrentBattlePyramidLocation
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803E9FC
	bl GetPyramidRunMultiplier
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldr r4, _0803E9F8
	movs r3, #0x58
	adds r0, r5, #0
	muls r0, r3, r0
	adds r0, r0, r4
	ldrh r0, [r0, #6]
	muls r0, r1, r0
	movs r2, #1
	adds r1, r5, #0
	eors r1, r2
	muls r1, r3, r1
	adds r1, r1, r4
	b _0803EA1A
	.align 2, 0
_0803E9F8: .4byte 0x02023D28
_0803E9FC:
	ldr r3, _0803EA74
	movs r2, #0x58
	adds r0, r5, #0
	muls r0, r2, r0
	adds r4, r0, r3
	movs r1, #1
	adds r0, r5, #0
	eors r0, r1
	muls r0, r2, r0
	adds r1, r0, r3
	ldrh r0, [r4, #6]
	ldrh r2, [r1, #6]
	cmp r0, r2
	bhs _0803EA40
	lsls r0, r0, #7
_0803EA1A:
	ldrh r1, [r1, #6]
	bl __divsi3
	ldr r1, _0803EA78
	ldr r1, [r1]
	adds r1, #0x6c
	ldrb r2, [r1]
	lsls r1, r2, #4
	subs r1, r1, r2
	lsls r1, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	bl Random
	movs r1, #0xff
	ands r1, r0
	cmp r4, r1
	bls _0803EA46
_0803EA40:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
_0803EA46:
	ldr r0, _0803EA78
	ldr r1, [r0]
	adds r1, #0x6c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0803EA52:
	cmp r7, #0
	beq _0803EA64
	ldr r1, _0803EA7C
	ldr r0, _0803EA80
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r1, _0803EA84
	movs r0, #4
	strb r0, [r1]
_0803EA64:
	adds r0, r7, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803EA74: .4byte 0x02023D28
_0803EA78: .4byte 0x02024140
_0803EA7C: .4byte 0x02023D26
_0803EA80: .4byte 0x02023D10
_0803EA84: .4byte 0x02023FDE
	thumb_func_end TryRunFromBattle
