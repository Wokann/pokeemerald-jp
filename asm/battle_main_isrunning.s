.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start IsRunningFromBattleImpossible
IsRunningFromBattleImpossible: @ 0x0803B7CC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r1, _0803B7F0
	ldr r0, _0803B7F4
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, r0, r1
	ldrh r0, [r1, #0x2e]
	cmp r0, #0xaf
	bne _0803B7FC
	ldr r1, _0803B7F8
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r2, [r0, #7]
	b _0803B806
	.align 2, 0
_0803B7F0: .4byte 0x02023D28
_0803B7F4: .4byte 0x02023D08
_0803B7F8: .4byte 0x020240A8
_0803B7FC:
	ldrh r0, [r1, #0x2e]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_0803B806:
	ldr r1, _0803B91C
	ldr r3, _0803B920
	ldrb r0, [r3]
	strb r0, [r1]
	cmp r2, #0x25
	bne _0803B814
	b _0803B990
_0803B814:
	ldr r0, _0803B924
	ldr r0, [r0]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0803B822
	b _0803B990
_0803B822:
	ldr r1, _0803B928
	ldrb r2, [r3]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x32
	bne _0803B836
	b _0803B990
_0803B836:
	adds r0, r2, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	movs r5, #0
	ldr r0, _0803B92C
	ldrb r0, [r0]
	cmp r5, r0
	bge _0803B8CA
	movs r7, #0
_0803B84C:
	lsrs r4, r7, #0x18
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r0
	beq _0803B870
	ldr r1, _0803B928
	movs r0, #0x58
	muls r0, r5, r0
	adds r0, r0, r1
	adds r2, r0, #0
	adds r2, #0x20
	ldrb r0, [r2]
	cmp r0, #0x17
	bne _0803B870
	b _0803B998
_0803B870:
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r6, r0
	beq _0803B8BA
	ldr r3, _0803B928
	ldr r0, _0803B920
	ldrb r0, [r0]
	movs r2, #0x58
	muls r0, r2, r0
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x1a
	beq _0803B8BA
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803B8BA
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803B8BA
	adds r0, r5, #0
	muls r0, r2, r0
	adds r0, r0, r3
	adds r2, r0, #0
	adds r2, #0x20
	ldrb r0, [r2]
	cmp r0, #0x47
	bne _0803B8BA
	b _0803B9B4
_0803B8BA:
	movs r0, #0x80
	lsls r0, r0, #0x11
	adds r7, r7, r0
	adds r5, #1
	ldr r0, _0803B92C
	ldrb r0, [r0]
	cmp r5, r0
	blt _0803B84C
_0803B8CA:
	ldr r4, _0803B920
	ldrb r1, [r4]
	movs r0, #0
	str r0, [sp]
	movs r0, #0xf
	movs r2, #0x2a
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	beq _0803B93C
	ldr r6, _0803B928
	ldrb r0, [r4]
	movs r3, #0x58
	muls r0, r3, r0
	adds r1, r0, r6
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #8
	beq _0803B902
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #8
	bne _0803B93C
_0803B902:
	ldr r0, _0803B930
	subs r1, r5, #1
	strb r1, [r0, #0x17]
	ldr r2, _0803B934
	adds r0, r1, #0
	muls r0, r3, r0
	adds r0, r0, r6
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r2]
	ldr r1, _0803B938
	movs r0, #2
	b _0803B9D4
	.align 2, 0
_0803B91C: .4byte 0x02023EB3
_0803B920: .4byte 0x02023D08
_0803B924: .4byte 0x02022C90
_0803B928: .4byte 0x02023D28
_0803B92C: .4byte 0x02023D10
_0803B930: .4byte 0x02024118
_0803B934: .4byte 0x02023EAE
_0803B938: .4byte 0x02023FD6
_0803B93C:
	ldr r1, _0803B970
	ldr r0, _0803B974
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0803B978
	ands r0, r1
	cmp r0, #0
	bne _0803B966
	ldr r1, _0803B97C
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0803B984
_0803B966:
	ldr r1, _0803B980
	movs r0, #0
	strb r0, [r1, #5]
	movs r0, #1
	b _0803B9D6
	.align 2, 0
_0803B970: .4byte 0x02023D28
_0803B974: .4byte 0x02023D08
_0803B978: .4byte 0x0400E000
_0803B97C: .4byte 0x02023F50
_0803B980: .4byte 0x02023FD6
_0803B984:
	ldr r0, _0803B994
	ldr r0, [r0]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _0803B9D0
_0803B990:
	movs r0, #0
	b _0803B9D6
	.align 2, 0
_0803B994: .4byte 0x02022C90
_0803B998:
	ldr r0, _0803B9A8
	strb r5, [r0, #0x17]
	ldr r1, _0803B9AC
	ldrb r0, [r2]
	strb r0, [r1]
	ldr r1, _0803B9B0
	movs r0, #2
	b _0803B9D4
	.align 2, 0
_0803B9A8: .4byte 0x02024118
_0803B9AC: .4byte 0x02023EAE
_0803B9B0: .4byte 0x02023FD6
_0803B9B4:
	ldr r0, _0803B9C4
	strb r5, [r0, #0x17]
	ldr r1, _0803B9C8
	ldrb r0, [r2]
	strb r0, [r1]
	ldr r1, _0803B9CC
	movs r0, #2
	b _0803B9D4
	.align 2, 0
_0803B9C4: .4byte 0x02024118
_0803B9C8: .4byte 0x02023EAE
_0803B9CC: .4byte 0x02023FD6
_0803B9D0:
	ldr r1, _0803B9E0
	movs r0, #1
_0803B9D4:
	strb r0, [r1, #5]
_0803B9D6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0803B9E0: .4byte 0x02023FD6
	thumb_func_end IsRunningFromBattleImpossible
