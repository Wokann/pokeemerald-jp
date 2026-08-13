.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified










	thumb_func_start ClearFuryCutterDestinyBondGrudge
ClearFuryCutterDestinyBondGrudge: @ 0x080454A8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _080454E0
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	movs r2, #0
	strb r2, [r1, #0x10]
	ldr r1, _080454E4
	movs r2, #0x58
	adds r3, r0, #0
	muls r3, r2, r3
	adds r1, #0x50
	adds r3, r3, r1
	ldr r1, [r3]
	ldr r2, _080454E8
	ands r1, r2
	str r1, [r3]
	ldr r1, _080454EC
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, _080454F0
	ands r1, r2
	str r1, [r0]
	bx lr
	.align 2, 0
_080454E0: .4byte 0x02023F60
_080454E4: .4byte 0x02023D28
_080454E8: .4byte 0xFDFFFFFF
_080454EC: .4byte 0x02023F50
_080454F0: .4byte 0xFFFFBFFF
	thumb_func_end ClearFuryCutterDestinyBondGrudge

	thumb_func_start sub_080454F4
sub_080454F4: @ 0x080454F4
	push {lr}
	ldr r0, _08045514
	ldr r0, [r0]
	cmp r0, #0
	bne _08045510
	ldr r1, _08045518
	ldr r0, _0804551C
	ldr r0, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl _call_via_r0
_08045510:
	pop {r0}
	bx r0
	.align 2, 0
_08045514: .4byte 0x02023D0C
_08045518: .4byte 0x082EC694
_0804551C: .4byte 0x02023EB8
	thumb_func_end sub_080454F4

	thumb_func_start GetMoveTarget
GetMoveTarget: @ 0x08045520
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	movs r5, #0
	cmp r0, #0
	beq _0804553E
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	b _0804554A
_0804553E:
	ldr r1, _0804555C
	lsls r0, r7, #1
	adds r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r6, [r0, #6]
_0804554A:
	cmp r6, #0x40
	bls _08045550
	b _08045860
_08045550:
	lsls r0, r6, #2
	ldr r1, _08045560
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804555C: .4byte 0x082ED220
_08045560: .4byte 0x08045564
_08045564: @ jump table
	.4byte _08045668 @ case 0
	.4byte _08045768 @ case 1
	.4byte _0804585C @ case 2
	.4byte _08045860 @ case 3
	.4byte _08045780 @ case 4
	.4byte _08045860 @ case 5
	.4byte _08045860 @ case 6
	.4byte _08045860 @ case 7
	.4byte _08045768 @ case 8
	.4byte _08045860 @ case 9
	.4byte _08045860 @ case 10
	.4byte _08045860 @ case 11
	.4byte _08045860 @ case 12
	.4byte _08045860 @ case 13
	.4byte _08045860 @ case 14
	.4byte _08045860 @ case 15
	.4byte _0804585C @ case 16
	.4byte _08045860 @ case 17
	.4byte _08045860 @ case 18
	.4byte _08045860 @ case 19
	.4byte _08045860 @ case 20
	.4byte _08045860 @ case 21
	.4byte _08045860 @ case 22
	.4byte _08045860 @ case 23
	.4byte _08045860 @ case 24
	.4byte _08045860 @ case 25
	.4byte _08045860 @ case 26
	.4byte _08045860 @ case 27
	.4byte _08045860 @ case 28
	.4byte _08045860 @ case 29
	.4byte _08045860 @ case 30
	.4byte _08045860 @ case 31
	.4byte _08045768 @ case 32
	.4byte _08045860 @ case 33
	.4byte _08045860 @ case 34
	.4byte _08045860 @ case 35
	.4byte _08045860 @ case 36
	.4byte _08045860 @ case 37
	.4byte _08045860 @ case 38
	.4byte _08045860 @ case 39
	.4byte _08045860 @ case 40
	.4byte _08045860 @ case 41
	.4byte _08045860 @ case 42
	.4byte _08045860 @ case 43
	.4byte _08045860 @ case 44
	.4byte _08045860 @ case 45
	.4byte _08045860 @ case 46
	.4byte _08045860 @ case 47
	.4byte _08045860 @ case 48
	.4byte _08045860 @ case 49
	.4byte _08045860 @ case 50
	.4byte _08045860 @ case 51
	.4byte _08045860 @ case 52
	.4byte _08045860 @ case 53
	.4byte _08045860 @ case 54
	.4byte _08045860 @ case 55
	.4byte _08045860 @ case 56
	.4byte _08045860 @ case 57
	.4byte _08045860 @ case 58
	.4byte _08045860 @ case 59
	.4byte _08045860 @ case 60
	.4byte _08045860 @ case 61
	.4byte _08045860 @ case 62
	.4byte _08045860 @ case 63
	.4byte _08045768 @ case 64
_08045668:
	ldr r0, _08045748
	ldrb r0, [r0]
	bl GetBattlerSide
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _0804574C
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r2, r0, r1
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _0804569A
	ldr r1, _08045750
	ldrb r4, [r2, #9]
	movs r0, #0x58
	muls r0, r4, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _0804569A
	b _080457B0
_0804569A:
	ldr r0, _08045748
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r0, r7, #1
	mov r8, r0
_080456AA:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08045754
	ldrb r1, [r1]
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r6, _08045748
	ldrb r3, [r6]
	cmp r5, r3
	beq _080456AA
	adds r0, r5, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	beq _080456AA
	ldr r0, _08045758
	ldrb r2, [r0]
	ldr r1, _0804575C
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r2, r0
	cmp r2, #0
	bne _080456AA
	ldr r0, _08045760
	mov r3, r8
	adds r1, r3, r7
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1, #2]
	cmp r0, #0xd
	beq _080456F8
	b _08045860
_080456F8:
	ldrb r1, [r6]
	str r2, [sp]
	movs r0, #0x10
	movs r2, #0x1f
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804570E
	b _08045860
_0804570E:
	ldr r2, _08045750
	movs r1, #0x58
	adds r0, r5, #0
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x1f
	bne _08045722
	b _08045860
_08045722:
	movs r4, #2
	eors r5, r4
	adds r0, r5, #0
	muls r0, r1, r0
	adds r0, r0, r2
	adds r0, #0x20
	ldrb r1, [r0]
	adds r0, r5, #0
	bl RecordAbilityBattle
	ldr r1, _08045764
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	orrs r1, r4
	strb r1, [r0]
	b _08045860
	.align 2, 0
_08045748: .4byte 0x02023EAF
_0804574C: .4byte 0x02023F38
_08045750: .4byte 0x02023D28
_08045754: .4byte 0x02023D10
_08045758: .4byte 0x02023EB4
_0804575C: .4byte 0x082FACB4
_08045760: .4byte 0x082ED220
_08045764: .4byte 0x02024020
_08045768:
	ldr r0, _0804577C
	ldrb r0, [r0]
	bl GetBattlerPosition
	adds r1, r0, #0
	movs r2, #1
	movs r0, #1
	ands r0, r1
	eors r0, r2
	b _08045812
	.align 2, 0
_0804577C: .4byte 0x02023EAF
_08045780:
	ldr r0, _080457B4
	ldrb r0, [r0]
	bl GetBattlerSide
	movs r1, #1
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r1, _080457B8
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r2, r0, r1
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _080457C0
	ldr r1, _080457BC
	ldrb r4, [r2, #9]
	movs r0, #0x58
	muls r0, r4, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _080457C0
_080457B0:
	adds r5, r4, #0
	b _08045860
	.align 2, 0
_080457B4: .4byte 0x02023EAF
_080457B8: .4byte 0x02023F38
_080457BC: .4byte 0x02023D28
_080457C0:
	ldr r0, _080457F4
	ldr r0, [r0]
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _0804583C
	movs r0, #4
	ands r6, r0
	cmp r6, #0
	beq _0804583C
	ldr r0, _080457F8
	ldrb r0, [r0]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08045800
	bl Random
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _080457FC
	movs r0, #1
	b _08045812
	.align 2, 0
_080457F4: .4byte 0x02022C90
_080457F8: .4byte 0x02023EAF
_080457FC:
	movs r0, #3
	b _08045812
_08045800:
	bl Random
	adds r1, r4, #0
	ands r1, r0
	cmp r1, #0
	beq _08045810
	movs r0, #0
	b _08045812
_08045810:
	movs r0, #2
_08045812:
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _08045834
	ldrb r1, [r0]
	ldr r2, _08045838
	lsls r0, r5, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _08045860
	movs r0, #2
	eors r5, r0
	b _08045860
	.align 2, 0
_08045834: .4byte 0x02023EB4
_08045838: .4byte 0x082FACB4
_0804583C:
	ldr r0, _08045858
	ldrb r0, [r0]
	bl GetBattlerPosition
	adds r1, r0, #0
	movs r2, #1
	movs r0, #1
	ands r0, r1
	eors r0, r2
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _08045860
	.align 2, 0
_08045858: .4byte 0x02023EAF
_0804585C:
	ldr r0, _0804587C
	ldrb r5, [r0]
_08045860:
	ldr r0, _0804587C
	ldrb r0, [r0]
	ldr r1, _08045880
	ldr r1, [r1]
	adds r0, r0, r1
	strb r5, [r0, #0xc]
	adds r0, r5, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804587C: .4byte 0x02023EAF
_08045880: .4byte 0x02024140
	thumb_func_end GetMoveTarget

	thumb_func_start HasObedientBitSet
HasObedientBitSet: @ 0x08045884
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080458CA
	ldr r0, _080458D0
	lsls r4, r4, #1
	adds r5, r4, r0
	ldrh r0, [r5]
	movs r7, #0x64
	muls r0, r7, r0
	ldr r6, _080458D4
	adds r0, r0, r6
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	movs r1, #0xcd
	lsls r1, r1, #1
	cmp r0, r1
	beq _080458D8
	ldrh r0, [r5]
	muls r0, r7, r0
	adds r0, r0, r6
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	cmp r0, #0x97
	beq _080458D8
_080458CA:
	movs r0, #1
	b _080458EE
	.align 2, 0
_080458D0: .4byte 0x02023D12
_080458D4: .4byte 0x02024190
_080458D8:
	ldr r0, _080458F4
	adds r0, r4, r0
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _080458F8
	adds r0, r0, r1
	movs r1, #0x50
	movs r2, #0
	bl GetMonData3
_080458EE:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080458F4: .4byte 0x02023D12
_080458F8: .4byte 0x02024190
	thumb_func_end HasObedientBitSet

	thumb_func_start IsMonDisobedient
IsMonDisobedient: @ 0x080458FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	movs r6, #0
	ldr r5, _080459F0
	ldr r0, [r5]
	ldr r1, _080459F4
	ands r0, r1
	cmp r0, #0
	bne _080459EC
	ldr r4, _080459F8
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080459EC
	ldrb r0, [r4]
	bl HasObedientBitSet
	cmp r0, #0
	beq _080459B6
	ldr r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _08045948
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	beq _080459EC
_08045948:
	ldr r0, _080459F0
	ldr r1, [r0]
	ldr r0, _080459FC
	ands r0, r1
	cmp r0, #0
	bne _080459EC
	movs r0, #0x80
	lsls r0, r0, #0x11
	ands r1, r0
	cmp r1, #0
	bne _080459EC
	ldr r2, _08045A00
	ldr r0, _080459F8
	ldrb r1, [r0]
	movs r0, #0x58
	muls r1, r0, r1
	adds r0, r2, #0
	adds r0, #0x54
	adds r0, r1, r0
	ldr r0, [r0]
	adds r2, #0x3c
	adds r1, r1, r2
	bl IsOtherTrainer
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080459EC
	ldr r0, _08045A04
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080459EC
	movs r6, #0xa
	ldr r0, _08045A08
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0804599A
	movs r6, #0x1e
_0804599A:
	ldr r0, _08045A0C
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080459A8
	movs r6, #0x32
_080459A8:
	ldr r0, _08045A10
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080459B6
	movs r6, #0x46
_080459B6:
	ldr r5, _08045A00
	ldr r0, _080459F8
	mov r8, r0
	ldrb r0, [r0]
	movs r7, #0x58
	muls r0, r7, r0
	adds r0, r0, r5
	adds r0, #0x2a
	ldrb r0, [r0]
	cmp r0, r6
	bls _080459EC
	bl Random
	movs r1, #0xff
	ands r1, r0
	mov r2, r8
	ldrb r0, [r2]
	adds r2, r0, #0
	muls r2, r7, r2
	adds r0, r2, r5
	adds r0, #0x2a
	ldrb r0, [r0]
	adds r0, r0, r6
	muls r0, r1, r0
	asrs r4, r0, #8
	cmp r4, r6
	bge _08045A14
_080459EC:
	movs r0, #0
	b _08045C10
	.align 2, 0
_080459F0: .4byte 0x02022C90
_080459F4: .4byte 0x02000002
_080459F8: .4byte 0x02023EAF
_080459FC: .4byte 0x003F0100
_08045A00: .4byte 0x02023D28
_08045A04: .4byte 0x0000086E
_08045A08: .4byte 0x00000868
_08045A0C: .4byte 0x0000086A
_08045A10: .4byte 0x0000086C
_08045A14:
	ldr r3, _08045A50
	ldrh r0, [r3]
	cmp r0, #0x63
	bne _08045A2A
	adds r0, r5, #0
	adds r0, #0x50
	adds r0, r2, r0
	ldr r1, [r0]
	ldr r2, _08045A54
	ands r1, r2
	str r1, [r0]
_08045A2A:
	mov r1, r8
	ldrb r0, [r1]
	muls r0, r7, r0
	adds r1, r5, #0
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08045A60
	ldrh r0, [r3]
	cmp r0, #0xad
	beq _08045A4A
	cmp r0, #0xd6
	bne _08045A60
_08045A4A:
	ldr r1, _08045A58
	ldr r0, _08045A5C
	b _08045BBA
	.align 2, 0
_08045A50: .4byte 0x02023E8E
_08045A54: .4byte 0xFF7FFFFF
_08045A58: .4byte 0x02023EB8
_08045A5C: .4byte 0x08289C1D
_08045A60:
	bl Random
	movs r5, #0xff
	adds r1, r5, #0
	ands r1, r0
	ldr r7, _08045B00
	ldr r2, _08045B04
	mov sb, r2
	ldrb r3, [r2]
	movs r0, #0x58
	mov r8, r0
	mov r0, r8
	muls r0, r3, r0
	adds r0, r0, r7
	adds r0, #0x2a
	ldrb r2, [r0]
	adds r0, r2, r6
	muls r0, r1, r0
	asrs r4, r0, #8
	cmp r4, r6
	bge _08045B28
	ldr r6, _08045B08
	ldr r5, _08045B0C
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r1, [r0]
	adds r0, r3, #0
	movs r2, #0xff
	bl CheckMoveLimitations
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0xf
	bne _08045AA8
	b _08045BAA
_08045AA8:
	ldr r1, _08045B10
	mov r8, r1
	movs r7, #3
_08045AAE:
	bl Random
	ands r0, r7
	mov r2, r8
	strb r0, [r2]
	strb r0, [r5]
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ands r0, r4
	cmp r0, #0
	bne _08045AAE
	ldr r4, _08045B14
	ldr r3, _08045B00
	ldr r0, _08045B0C
	ldrb r0, [r0]
	lsls r0, r0, #1
	ldr r1, _08045B04
	ldrb r2, [r1]
	movs r1, #0x58
	muls r1, r2, r1
	adds r0, r0, r1
	adds r3, #0xc
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r4]
	ldr r1, _08045B18
	ldr r0, _08045B1C
	str r0, [r1]
	ldrh r0, [r4]
	movs r1, #0
	bl GetMoveTarget
	ldr r1, _08045B20
	strb r0, [r1]
	ldr r2, _08045B24
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xe
	b _08045C0A
	.align 2, 0
_08045B00: .4byte 0x02023D28
_08045B04: .4byte 0x02023EAF
_08045B08: .4byte 0x082FACB4
_08045B0C: .4byte 0x02023E8C
_08045B10: .4byte 0x02023E8D
_08045B14: .4byte 0x02023E92
_08045B18: .4byte 0x02023EB8
_08045B1C: .4byte 0x08289C2D
_08045B20: .4byte 0x02023EB0
_08045B24: .4byte 0x02023F24
_08045B28:
	subs r0, r2, r6
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	bl Random
	adds r4, r5, #0
	ands r4, r0
	cmp r4, r6
	bge _08045BA4
	mov r1, sb
	ldrb r0, [r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r7, #0
	adds r0, #0x4c
	adds r0, r1, r0
	ldr r0, [r0]
	ands r0, r5
	cmp r0, #0
	bne _08045BA4
	adds r0, r1, r7
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x48
	beq _08045BA4
	cmp r0, #0xf
	beq _08045BA4
	movs r2, #0
	ldr r0, _08045B98
	ldrb r3, [r0]
	mov r8, r0
	cmp r2, r3
	bge _08045B8A
	ldr r0, [r7, #0x50]
	movs r1, #0x70
	ands r0, r1
	cmp r0, #0
	bne _08045B8A
	adds r1, r7, #0
	adds r1, #0x50
	movs r5, #0x70
_08045B7A:
	adds r1, #0x58
	adds r2, #1
	cmp r2, r3
	bge _08045B8A
	ldr r0, [r1]
	ands r0, r5
	cmp r0, #0
	beq _08045B7A
_08045B8A:
	mov r0, r8
	ldrb r0, [r0]
	cmp r2, r0
	bne _08045BA4
	ldr r1, _08045B9C
	ldr r0, _08045BA0
	b _08045BBA
	.align 2, 0
_08045B98: .4byte 0x02023D10
_08045B9C: .4byte 0x02023EB8
_08045BA0: .4byte 0x08289C61
_08045BA4:
	subs r4, r4, r6
	cmp r4, r6
	blt _08045BCC
_08045BAA:
	bl Random
	ldr r2, _08045BC0
	movs r1, #3
	ands r1, r0
	strb r1, [r2, #5]
	ldr r1, _08045BC4
	ldr r0, _08045BC8
_08045BBA:
	str r0, [r1]
	movs r0, #1
	b _08045C10
	.align 2, 0
_08045BC0: .4byte 0x02023FD6
_08045BC4: .4byte 0x02023EB8
_08045BC8: .4byte 0x08289C35
_08045BCC:
	ldr r4, _08045C20
	ldrb r1, [r4]
	movs r0, #0x58
	muls r1, r0, r1
	ldr r0, _08045C24
	adds r1, r1, r0
	movs r0, #0x28
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldrb r0, [r4]
	str r0, [sp, #8]
	ldrb r0, [r4]
	str r0, [sp, #0xc]
	adds r0, r1, #0
	movs r2, #1
	movs r3, #0
	bl CalculateBaseDamage
	ldr r1, _08045C28
	str r0, [r1]
	ldr r1, _08045C2C
	ldrb r0, [r4]
	strb r0, [r1]
	ldr r1, _08045C30
	ldr r0, _08045C34
	str r0, [r1]
	ldr r2, _08045C38
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0xc
_08045C0A:
	orrs r0, r1
	str r0, [r2]
	movs r0, #2
_08045C10:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08045C20: .4byte 0x02023EAF
_08045C24: .4byte 0x02023D28
_08045C28: .4byte 0x02023E94
_08045C2C: .4byte 0x02023EB0
_08045C30: .4byte 0x02023EB8
_08045C34: .4byte 0x08289C78
_08045C38: .4byte 0x02023F24
	thumb_func_end IsMonDisobedient
