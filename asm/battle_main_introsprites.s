.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start BattleIntroDrawTrainersOrMonsSprites
BattleIntroDrawTrainersOrMonsSprites: @ 0x0803A8C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	ldr r0, _0803A92C
	ldr r1, [r0]
	cmp r1, #0
	beq _0803A8DC
	b _0803AB92
_0803A8DC:
	ldr r2, _0803A930
	strb r1, [r2]
	ldr r0, _0803A934
	ldrb r0, [r0]
	cmp r1, r0
	blo _0803A8EA
	b _0803AB8C
_0803A8EA:
	movs r7, #0x58
	ldr r0, _0803A938
	mov r8, r0
	mov sb, r2
	movs r1, #0x48
	add r1, r8
	mov sl, r1
_0803A8F8:
	ldr r0, _0803A93C
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0803A940
	ldr r4, _0803A930
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803A940
	ldrb r0, [r4]
	muls r0, r7, r0
	mov r2, r8
	adds r3, r0, r2
	movs r2, #0
	movs r1, #0
_0803A91E:
	adds r0, r3, r2
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0x57
	bls _0803A91E
	b _0803AA0E
	.align 2, 0
_0803A92C: .4byte 0x02023D0C
_0803A930: .4byte 0x02023D08
_0803A934: .4byte 0x02023D10
_0803A938: .4byte 0x02023D28
_0803A93C: .4byte 0x02022C90
_0803A940:
	mov r1, sb
	ldrb r0, [r1]
	muls r0, r7, r0
	mov r2, r8
	adds r3, r0, r2
	movs r2, #0
	ldr r6, _0803AA88
	ldr r5, _0803AA8C
	ldr r4, _0803AA90
_0803A952:
	adds r0, r3, r2
	ldrb r1, [r4]
	lsls r1, r1, #9
	adds r1, #4
	adds r1, r2, r1
	adds r1, r1, r5
	ldrb r1, [r1]
	strb r1, [r0]
	adds r2, #1
	cmp r2, #0x57
	bls _0803A952
	mov r1, sb
	ldrb r0, [r1]
	adds r2, r0, #0
	muls r2, r7, r2
	add r2, r8
	ldrh r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #6]
	adds r2, #0x21
	strb r0, [r2]
	mov r2, sb
	ldrb r0, [r2]
	adds r2, r0, #0
	muls r2, r7, r2
	add r2, r8
	ldrh r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldrb r0, [r0, #7]
	adds r2, #0x22
	strb r0, [r2]
	mov r1, sb
	ldrb r0, [r1]
	adds r1, r0, #0
	muls r1, r7, r1
	add r1, r8
	ldrh r0, [r1]
	ldrb r1, [r1, #0x17]
	lsrs r1, r1, #7
	bl GetAbilityBySpecies
	mov r2, sb
	ldrb r1, [r2]
	muls r1, r7, r1
	add r1, r8
	adds r1, #0x20
	strb r0, [r1]
	ldrb r0, [r2]
	bl GetBattlerSide
	ldr r1, _0803AA94
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x17
	adds r0, #0xa8
	ldr r1, [r1]
	adds r1, r1, r0
	mov r2, sb
	ldrb r0, [r2]
	muls r0, r7, r0
	add r0, r8
	ldrh r0, [r0, #0x28]
	strh r0, [r1]
	movs r2, #0
	ldr r4, _0803AA90
	movs r5, #0x58
	ldr r1, _0803AA98
	adds r6, r4, #0
	movs r0, #0x18
	rsbs r0, r0, #0
	adds r0, r0, r1
	mov ip, r0
	movs r3, #6
_0803A9EE:
	ldrb r0, [r4]
	muls r0, r5, r0
	adds r0, r2, r0
	adds r0, r0, r1
	strb r3, [r0]
	adds r2, #1
	cmp r2, #7
	ble _0803A9EE
	ldrb r0, [r6]
	adds r1, r0, #0
	muls r1, r7, r1
	mov r0, ip
	adds r0, #0x50
	adds r1, r1, r0
	movs r0, #0
	str r0, [r1]
_0803AA0E:
	ldr r4, _0803AA90
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803AA28
	movs r0, #0
	bl BtlController_EmitDrawTrainerPic
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_0803AA28:
	ldr r5, _0803AA9C
	ldr r0, [r5]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0803AAA4
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0803AA4E
	movs r0, #0
	bl BtlController_EmitDrawTrainerPic
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_0803AA4E:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0803AB04
	ldr r0, [r5]
	ldr r1, _0803AAA0
	ands r0, r1
	cmp r0, #0
	bne _0803AB04
	ldrb r0, [r4]
	muls r0, r7, r0
	add r0, r8
	ldrh r0, [r0]
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4]
	muls r1, r7, r1
	add r1, sl
	ldr r2, [r1]
	movs r1, #2
	bl HandleSetPokedexFlag
	b _0803AB04
	.align 2, 0
_0803AA88: .4byte 0x082F0D54
_0803AA8C: .4byte 0x02023508
_0803AA90: .4byte 0x02023D08
_0803AA94: .4byte 0x02024140
_0803AA98: .4byte 0x02023D40
_0803AA9C: .4byte 0x02022C90
_0803AAA0: .4byte 0x063F0902
_0803AAA4:
	ldrb r0, [r4]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0803AB04
	ldr r0, [r5]
	ldr r1, _0803ABA0
	ands r0, r1
	cmp r0, #0
	bne _0803AADA
	ldrb r0, [r4]
	muls r0, r7, r0
	add r0, r8
	ldrh r0, [r0]
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4]
	muls r1, r7, r1
	add r1, sl
	ldr r2, [r1]
	movs r1, #2
	bl HandleSetPokedexFlag
_0803AADA:
	movs r0, #0
	bl BtlController_EmitLoadMonSprite
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	ldr r1, _0803ABA4
	ldrb r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r0, r1, r0
	ldr r1, _0803ABA8
	adds r0, r0, r1
	movs r1, #0xb
	movs r2, #0
	bl GetMonData3
	ldr r1, _0803ABAC
	strh r0, [r1, #0x20]
_0803AB04:
	ldr r0, _0803ABB0
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0803AB3A
	ldr r4, _0803ABB4
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	beq _0803AB2E
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0803AB3A
_0803AB2E:
	movs r0, #0
	bl BtlController_EmitDrawTrainerPic
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_0803AB3A:
	ldr r0, _0803ABB0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0803AB64
	ldr r4, _0803ABB4
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bne _0803AB64
	movs r0, #0
	bl BtlController_EmitDrawTrainerPic
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_0803AB64:
	ldr r0, _0803ABB0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	beq _0803AB76
	bl BattleArena_InitPoints
_0803AB76:
	mov r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r1, _0803ABB8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bhs _0803AB8C
	b _0803A8F8
_0803AB8C:
	ldr r1, _0803ABBC
	ldr r0, _0803ABC0
	str r0, [r1]
_0803AB92:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803ABA0: .4byte 0x063F0902
_0803ABA4: .4byte 0x02023D12
_0803ABA8: .4byte 0x020243E8
_0803ABAC: .4byte 0x03005A70
_0803ABB0: .4byte 0x02022C90
_0803ABB4: .4byte 0x02023D08
_0803ABB8: .4byte 0x02023D10
_0803ABBC: .4byte 0x03005A64
_0803ABC0: .4byte 0x0803ABC5
	thumb_func_end BattleIntroDrawTrainersOrMonsSprites
