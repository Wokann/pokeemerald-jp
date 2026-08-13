.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start HandleAction_TryFinish
HandleAction_TryFinish: @ 0x0803BAB8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _0803BAD4
	movs r1, #0
	strb r1, [r0, #4]
	ldr r0, _0803BAD8
	strb r1, [r0]
	ldr r0, _0803BADC
	bl _0803C956
	.align 2, 0
_0803BAD4: .4byte 0x02023FD6
_0803BAD8: .4byte 0x02023D08
_0803BADC: .4byte 0x02023D10
	thumb_func_end HandleAction_TryFinish

	thumb_func_start HandleTurnActionSelectionState
HandleTurnActionSelectionState: @ 0x0803BAE0
	ldr r4, _0803BB08
	ldrb r0, [r4]
	bl GetBattlerPosition
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r1, _0803BB0C
	ldrb r0, [r4]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #8
	bls _0803BAFC
	bl _0803C948
_0803BAFC:
	lsls r0, r0, #2
	ldr r1, _0803BB10
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803BB08: .4byte 0x02023D08
_0803BB0C: .4byte 0x02023FD6
_0803BB10: .4byte 0x0803BB14
_0803BB14: @ jump table
	.4byte _0803BB38 @ case 0
	.4byte _0803BB50 @ case 1
	.4byte _0803BC70 @ case 2
	.4byte _0803C41C @ case 3
	.4byte _0803C714 @ case 4
	.4byte _0803C7C8 @ case 5
	.4byte _0803C80C @ case 6
	.4byte _0803C838 @ case 7
	.4byte _0803C87C @ case 8
_0803BB38:
	bl RecordedBattle_CopyBattlerMoves
	ldr r1, _0803BB48
	ldr r0, _0803BB4C
	ldrb r0, [r0]
	adds r0, r0, r1
	bl _0803C864
	.align 2, 0
_0803BB48: .4byte 0x02023FD6
_0803BB4C: .4byte 0x02023D08
_0803BB50:
	ldr r0, _0803BBE8
	ldrb r1, [r0]
	ldr r4, _0803BBEC
	ldr r0, [r4]
	adds r1, r1, r0
	adds r1, #0x5c
	movs r0, #6
	strb r0, [r1]
	ldr r0, _0803BBF0
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0803BBAC
	movs r1, #2
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	beq _0803BBAC
	eors r5, r1
	adds r0, r5, #0
	bl GetBattlerAtPosition
	ldr r1, [r4]
	adds r1, #0x91
	ldrb r1, [r1]
	ldr r2, _0803BBF4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	bne _0803BBAC
	ldr r4, _0803BBF8
	adds r0, r5, #0
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #5
	beq _0803BBAC
	bl _0803C948
_0803BBAC:
	ldr r0, _0803BBEC
	ldr r0, [r0]
	adds r0, #0x91
	ldrb r3, [r0]
	ldr r1, _0803BBF4
	ldr r4, _0803BBE8
	ldrb r2, [r4]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ands r3, r0
	cmp r3, #0
	beq _0803BC14
	ldr r0, _0803BBFC
	adds r0, r2, r0
	movs r1, #0xd
	strb r1, [r0]
	ldr r0, _0803BBF0
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	bne _0803BC00
	ldr r0, _0803BBF8
	ldrb r1, [r4]
	adds r1, r1, r0
	movs r0, #5
	strb r0, [r1]
	bl _0803C948
	.align 2, 0
_0803BBE8: .4byte 0x02023D08
_0803BBEC: .4byte 0x02024140
_0803BBF0: .4byte 0x02022C90
_0803BBF4: .4byte 0x082FACB4
_0803BBF8: .4byte 0x02023FD6
_0803BBFC: .4byte 0x02023EC0
_0803BC00:
	ldr r0, _0803BC10
	ldrb r1, [r4]
	adds r1, r1, r0
	movs r0, #4
	strb r0, [r1]
	bl _0803C948
	.align 2, 0
_0803BC10: .4byte 0x02023FD6
_0803BC14:
	ldr r1, _0803BC44
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #5
	ands r0, r1
	cmp r0, #0
	bne _0803BC34
	movs r0, #0x80
	lsls r0, r0, #0xf
	ands r1, r0
	cmp r1, #0
	beq _0803BC50
_0803BC34:
	ldr r0, _0803BC48
	adds r0, r2, r0
	strb r3, [r0]
	ldr r1, _0803BC4C
	ldrb r0, [r4]
	bl _0803C8B6
	.align 2, 0
_0803BC44: .4byte 0x02023D28
_0803BC48: .4byte 0x02023EC0
_0803BC4C: .4byte 0x02023FD6
_0803BC50:
	ldr r0, _0803BC68
	ldrb r1, [r0]
	ldr r0, _0803BC6C
	ldrb r2, [r0, #1]
	ldrb r0, [r0, #2]
	lsls r0, r0, #8
	orrs r2, r0
	movs r0, #0
	bl BtlController_EmitChooseAction
	bl _0803C7AC
	.align 2, 0
_0803BC68: .4byte 0x02023EC0
_0803BC6C: .4byte 0x02023508
_0803BC70:
	ldr r3, _0803BCD4
	ldr r1, _0803BCD8
	ldr r6, _0803BCDC
	ldrb r5, [r6]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r1, r2, #4
	movs r0, #0xf0
	lsls r0, r0, #0x18
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, #8
	orrs r1, r0
	lsls r2, r2, #0xc
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0803BC9C
	bl _0803C948
_0803BC9C:
	ldr r4, _0803BCE0
	lsls r0, r5, #9
	adds r4, #1
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r0, r5, #0
	bl RecordedBattle_SetBattlerAction
	ldr r1, _0803BCE4
	ldrb r0, [r6]
	adds r1, r0, r1
	lsls r0, r0, #9
	adds r0, r0, r4
	ldrb r0, [r0]
	strb r0, [r1]
	ldrb r0, [r6]
	lsls r0, r0, #9
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0xc
	bls _0803BCC8
	b _0803C308
_0803BCC8:
	lsls r0, r0, #2
	ldr r1, _0803BCE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803BCD4: .4byte 0x02023D0C
_0803BCD8: .4byte 0x082FACB4
_0803BCDC: .4byte 0x02023D08
_0803BCE0: .4byte 0x02023508
_0803BCE4: .4byte 0x02023EC0
_0803BCE8: .4byte 0x0803BCEC
_0803BCEC: @ jump table
	.4byte _0803BD20 @ case 0
	.4byte _0803BE74 @ case 1
	.4byte _0803BEAC @ case 2
	.4byte _0803C308 @ case 3
	.4byte _0803C308 @ case 4
	.4byte _0803C084 @ case 5
	.4byte _0803C0D0 @ case 6
	.4byte _0803C308 @ case 7
	.4byte _0803C308 @ case 8
	.4byte _0803C308 @ case 9
	.4byte _0803C308 @ case 10
	.4byte _0803C308 @ case 11
	.4byte _0803C0F8 @ case 12
_0803BD20:
	bl AreAllMovesUnusable
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803BD78
	ldr r0, _0803BD68
	ldr r3, _0803BD6C
	ldrb r1, [r3]
	adds r1, r1, r0
	movs r4, #0
	movs r0, #6
	strb r0, [r1]
	ldrb r1, [r3]
	ldr r2, _0803BD70
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x54
	strb r4, [r1]
	ldrb r1, [r3]
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x84
	movs r0, #4
	strb r0, [r1]
	ldrb r1, [r3]
	ldr r2, [r2]
	adds r2, r1, r2
	ldr r0, _0803BD74
	lsls r1, r1, #9
	adds r0, #3
	adds r1, r1, r0
	ldrb r0, [r1]
	strb r0, [r2, #0xc]
	bl _0803C9B4
	.align 2, 0
_0803BD68: .4byte 0x02023FD6
_0803BD6C: .4byte 0x02023D08
_0803BD70: .4byte 0x02024140
_0803BD74: .4byte 0x02023508
_0803BD78:
	ldr r3, _0803BDB8
	ldr r5, _0803BDBC
	ldrb r4, [r5]
	lsls r0, r4, #3
	subs r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrh r2, [r0, #6]
	cmp r2, #0
	beq _0803BDCC
	ldr r1, _0803BDC0
	lsls r0, r4, #1
	adds r0, r0, r1
	strh r2, [r0]
	ldrb r2, [r5]
	ldr r0, _0803BDC4
	ldr r1, [r0]
	adds r1, r2, r1
	adds r1, #0x80
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r3
	ldrb r0, [r0, #0xc]
	strb r0, [r1]
	ldr r1, _0803BDC8
	ldrb r0, [r5]
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	bl _0803C9B4
	.align 2, 0
_0803BDB8: .4byte 0x02023F60
_0803BDBC: .4byte 0x02023D08
_0803BDC0: .4byte 0x02023F18
_0803BDC4: .4byte 0x02024140
_0803BDC8: .4byte 0x02023FD6
_0803BDCC:
	add r2, sp, #4
	ldr r3, _0803BE6C
	movs r1, #0x58
	adds r0, r4, #0
	muls r0, r1, r0
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r2, #0x10]
	ldrb r0, [r5]
	muls r0, r1, r0
	adds r0, r0, r3
	adds r0, #0x21
	ldrb r0, [r0]
	strb r0, [r2, #0x12]
	ldrb r0, [r5]
	muls r0, r1, r0
	adds r0, r0, r3
	adds r0, #0x22
	ldrb r0, [r0]
	strb r0, [r2, #0x13]
	movs r4, #0
	mov r1, sp
	adds r1, #0xc
	str r1, [sp, #0x18]
	add r2, sp, #0x10
	mov sl, r2
	mov r8, r3
	adds r7, r5, #0
	movs r6, #0x58
	movs r0, #0xc
	add r0, r8
	mov sb, r0
	add r5, sp, #4
_0803BE0E:
	lsls r2, r4, #1
	ldrb r0, [r7]
	muls r0, r6, r0
	adds r0, r2, r0
	add r0, sb
	ldrh r0, [r0]
	strh r0, [r5]
	ldr r1, [sp, #0x18]
	adds r3, r1, r4
	ldrb r0, [r7]
	muls r0, r6, r0
	adds r0, r4, r0
	mov r1, r8
	adds r1, #0x24
	adds r0, r0, r1
	ldrb r0, [r0]
	strb r0, [r3]
	ldrb r0, [r7]
	adds r1, r0, #0
	muls r1, r6, r1
	adds r2, r2, r1
	add r2, sb
	ldrh r0, [r2]
	add r1, r8
	adds r1, #0x3b
	ldrb r1, [r1]
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x18
	bl CalculatePPWithBonus
	mov r2, sl
	adds r1, r2, r4
	strb r0, [r1]
	adds r5, #2
	adds r4, #1
	cmp r4, #3
	ble _0803BE0E
	ldr r0, _0803BE70
	ldr r1, [r0]
	movs r0, #1
	ands r1, r0
	movs r0, #0
	movs r2, #0
	add r3, sp, #4
	bl BtlController_EmitChooseMove
	b _0803C072
	.align 2, 0
_0803BE6C: .4byte 0x02023D28
_0803BE70: .4byte 0x02022C90
_0803BE74:
	ldr r0, _0803BE98
	ldr r0, [r0]
	ldr r1, _0803BE9C
	ands r0, r1
	cmp r0, #0
	bne _0803BE82
	b _0803C0D0
_0803BE82:
	ldr r4, _0803BEA0
	ldrb r0, [r4]
	movs r1, #1
	bl RecordedBattle_ClearBattlerAction
	ldr r1, _0803BEA4
	ldrb r0, [r4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, _0803BEA8
	b _0803C3C8
	.align 2, 0
_0803BE98: .4byte 0x02022C90
_0803BE9C: .4byte 0x021F0902
_0803BEA0: .4byte 0x02023D08
_0803BEA4: .4byte 0x02023EC4
_0803BEA8: .4byte 0x08289E01
_0803BEAC:
	ldr r5, _0803BF14
	ldrb r0, [r5]
	ldr r3, _0803BF18
	ldr r1, [r3]
	adds r1, r0, r1
	adds r1, #0x58
	ldr r2, _0803BF1C
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	strb r0, [r1]
	ldr r7, _0803BF20
	ldrb r2, [r5]
	movs r6, #0x58
	adds r0, r2, #0
	muls r0, r6, r0
	adds r1, r7, #0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r0, _0803BF24
	ands r1, r0
	cmp r1, #0
	bne _0803BEFC
	ldr r0, _0803BF28
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ands r0, r1
	cmp r0, #0
	bne _0803BEFC
	ldr r0, _0803BF2C
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r1, [r1]
	movs r0, #0x80
	lsls r0, r0, #3
	ands r1, r0
	cmp r1, #0
	beq _0803BF30
_0803BEFC:
	ldr r0, _0803BF14
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #0x60
	ldr r0, [r3]
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #2
	movs r2, #6
	b _0803C044
	.align 2, 0
_0803BF14: .4byte 0x02023D08
_0803BF18: .4byte 0x02024140
_0803BF1C: .4byte 0x02023D12
_0803BF20: .4byte 0x02023D28
_0803BF24: .4byte 0x0400E000
_0803BF28: .4byte 0x02022C90
_0803BF2C: .4byte 0x02023F50
_0803BF30:
	str r1, [sp]
	movs r0, #0xc
	adds r1, r2, #0
	movs r2, #0x17
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	bne _0803BFB8
	ldrb r1, [r5]
	str r4, [sp]
	movs r0, #0xc
	movs r2, #0x47
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0803BF80
	ldrb r0, [r5]
	muls r0, r6, r0
	adds r1, r0, r7
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803BF80
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #2
	beq _0803BF80
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x1a
	bne _0803BFB8
_0803BF80:
	ldr r5, _0803BFE4
	ldrb r1, [r5]
	movs r0, #0
	str r0, [sp]
	movs r0, #0xf
	movs r2, #0x2a
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #0
	beq _0803BFF4
	ldr r2, _0803BFE8
	ldrb r1, [r5]
	movs r0, #0x58
	muls r0, r1, r0
	adds r1, r0, r2
	adds r0, r1, #0
	adds r0, #0x21
	ldrb r0, [r0]
	cmp r0, #8
	beq _0803BFB8
	adds r0, r1, #0
	adds r0, #0x22
	ldrb r0, [r0]
	cmp r0, #8
	bne _0803BFF4
_0803BFB8:
	subs r1, r4, #1
	lsls r1, r1, #4
	movs r0, #4
	orrs r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _0803BFEC
	ldrb r3, [r0]
	ldr r4, _0803BFF0
	ldr r0, _0803BFE4
	ldrb r0, [r0]
	lsls r2, r0, #1
	adds r2, r2, r0
	adds r2, #0x60
	ldr r0, [r4]
	adds r0, r0, r2
	str r0, [sp]
	movs r0, #0
	movs r2, #6
	bl BtlController_EmitChoosePokemon
	b _0803C072
	.align 2, 0
_0803BFE4: .4byte 0x02023D08
_0803BFE8: .4byte 0x02023D28
_0803BFEC: .4byte 0x02023EAE
_0803BFF0: .4byte 0x02024140
_0803BFF4:
	ldr r0, _0803C010
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #2
	bne _0803C01C
	ldr r0, _0803C014
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803C01C
	ldr r0, _0803C018
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x5c
	b _0803C032
	.align 2, 0
_0803C010: .4byte 0x02023D08
_0803C014: .4byte 0x02023EC0
_0803C018: .4byte 0x02024140
_0803C01C:
	ldrb r0, [r4]
	cmp r0, #3
	bne _0803C054
	ldr r0, _0803C04C
	ldrb r0, [r0, #1]
	cmp r0, #2
	bne _0803C054
	ldr r0, _0803C050
	ldr r3, [r0]
	adds r0, r3, #0
	adds r0, #0x5d
_0803C032:
	ldrb r2, [r0]
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x60
	adds r3, r3, r0
	str r3, [sp]
	movs r0, #0
	movs r1, #0
_0803C044:
	movs r3, #0
	bl BtlController_EmitChoosePokemon
	b _0803C072
	.align 2, 0
_0803C04C: .4byte 0x02023EC0
_0803C050: .4byte 0x02024140
_0803C054:
	ldr r2, _0803C07C
	ldr r0, _0803C080
	ldrb r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	adds r1, #0x60
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #6
	movs r3, #0
	bl BtlController_EmitChoosePokemon
_0803C072:
	ldr r0, _0803C080
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	b _0803C308
	.align 2, 0
_0803C07C: .4byte 0x02024140
_0803C080: .4byte 0x02023D08
_0803C084:
	bl IsPlayerPartyAndPokemonStorageFull
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0803C090
	b _0803C308
_0803C090:
	ldr r1, _0803C0BC
	ldr r3, _0803C0C0
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, _0803C0C4
	str r1, [r0]
	ldr r0, _0803C0C8
	ldrb r1, [r3]
	adds r1, r1, r0
	movs r4, #0
	movs r0, #6
	strb r0, [r1]
	ldrb r1, [r3]
	ldr r2, _0803C0CC
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x54
	strb r4, [r1]
	ldrb r1, [r3]
	b _0803C3E4
	.align 2, 0
_0803C0BC: .4byte 0x02023EC4
_0803C0C0: .4byte 0x02023D08
_0803C0C4: .4byte 0x08289099
_0803C0C8: .4byte 0x02023FD6
_0803C0CC: .4byte 0x02024140
_0803C0D0:
	ldr r2, _0803C0F0
	ldr r4, _0803C0F4
	ldrb r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	adds r0, #0x60
	ldr r1, [r2]
	adds r1, r1, r0
	movs r0, #0
	bl BtlController_EmitChooseItem
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	b _0803C308
	.align 2, 0
_0803C0F0: .4byte 0x02024140
_0803C0F4: .4byte 0x02023D08
_0803C0F8:
	ldr r4, _0803C188
	ldr r5, _0803C18C
	ldrb r0, [r5]
	adds r0, r0, r4
	movs r1, #7
	strb r1, [r0]
	ldrb r0, [r5]
	bl GetBattlerPosition
	movs r6, #2
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r5]
	bl RecordedBattle_ClearBattlerAction
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	ldr r1, _0803C190
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r7, #0x58
	muls r0, r7, r0
	adds r4, r1, #0
	adds r4, #0x50
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0803C176
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	muls r0, r7, r0
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803C194
_0803C176:
	movs r0, #0
	bl BtlController_EmitEndBounceEffect
	ldrb r0, [r5]
	bl MarkBattlerForControllerExec
	bl _0803C9B4
	.align 2, 0
_0803C188: .4byte 0x02023FD6
_0803C18C: .4byte 0x02023D08
_0803C190: .4byte 0x02023D28
_0803C194:
	ldr r4, _0803C1D0
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803C1D4
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #2
	bl RecordedBattle_ClearBattlerAction
	b _0803C2F2
	.align 2, 0
_0803C1D0: .4byte 0x02023EC0
_0803C1D4:
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #3
	bne _0803C1FA
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	b _0803C2AC
_0803C1FA:
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803C26C
	ldr r4, _0803C264
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x14
	adds r0, r0, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x1d
	cmp r0, #0
	blt _0803C25A
	ldr r4, _0803C268
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r4
	ldrh r0, [r1, #6]
	cmp r0, #0
	beq _0803C26C
_0803C25A:
	ldrb r0, [r5]
	bl GetBattlerPosition
	eors r0, r6
	b _0803C2AC
	.align 2, 0
_0803C264: .4byte 0x02023FE0
_0803C268: .4byte 0x02023F60
_0803C26C:
	ldr r0, _0803C2C0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	beq _0803C2D4
	ldr r4, _0803C2C4
	ldr r6, _0803C2C8
	ldrb r0, [r6]
	bl GetBattlerPosition
	movs r5, #2
	eors r0, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r0, r0, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0803C2D4
	ldr r1, _0803C2CC
	ldr r0, _0803C2D0
	ldr r0, [r0]
	str r0, [r1]
	ldrb r0, [r6]
	bl GetBattlerPosition
	eors r0, r5
_0803C2AC:
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #1
	bl RecordedBattle_ClearBattlerAction
	b _0803C2F2
	.align 2, 0
_0803C2C0: .4byte 0x02022C90
_0803C2C4: .4byte 0x02023EC0
_0803C2C8: .4byte 0x02023D08
_0803C2CC: .4byte 0x03005AE0
_0803C2D0: .4byte 0x0203B9FC
_0803C2D4:
	ldr r0, _0803C304
	ldrb r0, [r0]
	bl GetBattlerPosition
	movs r1, #2
	eors r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #3
	bl RecordedBattle_ClearBattlerAction
_0803C2F2:
	movs r0, #0
	bl BtlController_EmitEndBounceEffect
	ldr r0, _0803C304
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	b _0803C9B4
	.align 2, 0
_0803C304: .4byte 0x02023D08
_0803C308:
	ldr r1, _0803C348
	ldr r2, [r1]
	movs r5, #8
	adds r0, r2, #0
	ands r0, r5
	adds r3, r1, #0
	cmp r0, #0
	beq _0803C364
	ldr r0, _0803C34C
	ands r2, r0
	cmp r2, #0
	beq _0803C364
	ldr r0, _0803C350
	ldr r4, _0803C354
	ldrb r2, [r4]
	lsls r1, r2, #9
	adds r0, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #3
	bne _0803C364
	ldr r1, _0803C358
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, _0803C35C
	str r1, [r0]
	ldr r1, _0803C360
	ldrb r0, [r4]
	adds r0, r0, r1
	movs r3, #0
	strb r5, [r0]
	b _0803C3D6
	.align 2, 0
_0803C348: .4byte 0x02022C90
_0803C34C: .4byte 0x043F0100
_0803C350: .4byte 0x02023508
_0803C354: .4byte 0x02023D08
_0803C358: .4byte 0x02023EC4
_0803C35C: .4byte 0x08289F42
_0803C360: .4byte 0x02023FD6
_0803C364:
	ldr r0, [r3]
	ldr r1, _0803C390
	ands r0, r1
	cmp r0, #8
	bne _0803C3A4
	ldr r0, _0803C394
	ldr r4, _0803C398
	ldrb r1, [r4]
	lsls r1, r1, #9
	adds r0, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #3
	bne _0803C3A4
	ldr r0, _0803C39C
	bl BattleScriptExecute
	ldr r1, _0803C3A0
	ldrb r0, [r4]
	adds r0, r0, r1
	b _0803C864
	.align 2, 0
_0803C390: .4byte 0x0200000A
_0803C394: .4byte 0x02023508
_0803C398: .4byte 0x02023D08
_0803C39C: .4byte 0x08289086
_0803C3A0: .4byte 0x02023FD6
_0803C3A4:
	bl IsRunningFromBattleImpossible
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803C408
	ldr r0, _0803C3F0
	ldr r4, _0803C3F4
	ldrb r2, [r4]
	lsls r1, r2, #9
	adds r0, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #3
	bne _0803C408
	ldr r1, _0803C3F8
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, _0803C3FC
_0803C3C8:
	str r1, [r0]
	ldr r0, _0803C400
	ldrb r1, [r4]
	adds r1, r1, r0
	movs r3, #0
	movs r0, #6
	strb r0, [r1]
_0803C3D6:
	ldrb r1, [r4]
	ldr r2, _0803C404
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x54
	strb r3, [r1]
	ldrb r1, [r4]
_0803C3E4:
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x84
	movs r0, #1
	strb r0, [r1]
	b _0803C9B4
	.align 2, 0
_0803C3F0: .4byte 0x02023508
_0803C3F4: .4byte 0x02023D08
_0803C3F8: .4byte 0x02023EC4
_0803C3FC: .4byte 0x08289093
_0803C400: .4byte 0x02023FD6
_0803C404: .4byte 0x02024140
_0803C408:
	ldr r2, _0803C414
	ldr r0, _0803C418
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C414: .4byte 0x02023FD6
_0803C418: .4byte 0x02023D08
_0803C41C:
	ldr r4, _0803C460
	ldr r1, _0803C464
	ldr r3, _0803C468
	ldrb r5, [r3]
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r0, r2, #4
	movs r1, #0xf0
	lsls r1, r1, #0x18
	orrs r0, r1
	orrs r0, r2
	lsls r1, r2, #8
	orrs r0, r1
	lsls r2, r2, #0xc
	orrs r0, r2
	ldr r1, [r4]
	ands r1, r0
	adds r4, r3, #0
	cmp r1, #0
	beq _0803C448
	b _0803C948
_0803C448:
	ldr r1, _0803C46C
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #9
	bls _0803C456
	b _0803C948
_0803C456:
	lsls r0, r0, #2
	ldr r1, _0803C470
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0803C460: .4byte 0x02023D0C
_0803C464: .4byte 0x082FACB4
_0803C468: .4byte 0x02023D08
_0803C46C: .4byte 0x02023EC0
_0803C470: .4byte 0x0803C474
_0803C474: @ jump table
	.4byte _0803C49C @ case 0
	.4byte _0803C5E0 @ case 1
	.4byte _0803C618 @ case 2
	.4byte _0803C64E @ case 3
	.4byte _0803C670 @ case 4
	.4byte _0803C684 @ case 5
	.4byte _0803C698 @ case 6
	.4byte _0803C6C8 @ case 7
	.4byte _0803C6DC @ case 8
	.4byte _0803C700 @ case 9
_0803C49C:
	ldr r1, _0803C4B8
	ldrb r3, [r4]
	lsls r0, r3, #9
	adds r1, #1
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #3
	blt _0803C4CE
	cmp r1, #9
	ble _0803C4BC
	cmp r1, #0xf
	beq _0803C4C2
	b _0803C4CE
	.align 2, 0
_0803C4B8: .4byte 0x02023508
_0803C4BC:
	adds r0, r3, r2
	strb r1, [r0]
	b _0803C9B4
_0803C4C2:
	adds r1, r3, r2
	movs r0, #2
	strb r0, [r1]
	bl UpdateBattlerPartyOrdersOnSwitch
	b _0803C9B4
_0803C4CE:
	movs r0, #2
	bl sub_08185D94
	ldr r4, _0803C504
	ldr r6, _0803C508
	ldrb r3, [r6]
	lsls r1, r3, #9
	adds r5, r4, #2
	adds r0, r1, r5
	ldrb r2, [r0]
	adds r7, r4, #3
	adds r1, r1, r7
	ldrb r0, [r1]
	lsls r0, r0, #8
	orrs r2, r0
	ldr r0, _0803C50C
	cmp r2, r0
	bne _0803C514
	ldr r0, _0803C510
	adds r0, r3, r0
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r6]
	bl RecordedBattle_ClearBattlerAction
	b _0803C948
	.align 2, 0
_0803C504: .4byte 0x02023508
_0803C508: .4byte 0x02023D08
_0803C50C: .4byte 0x0000FFFF
_0803C510: .4byte 0x02023FD6
_0803C514:
	bl TrySetCantSelectMoveBattleScript
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0803C560
	ldrb r0, [r6]
	movs r1, #1
	bl RecordedBattle_ClearBattlerAction
	ldr r0, _0803C558
	ldrb r1, [r6]
	adds r1, r1, r0
	movs r3, #0
	movs r0, #6
	strb r0, [r1]
	ldrb r1, [r6]
	ldr r2, _0803C55C
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x54
	strb r3, [r1]
	ldrb r0, [r6]
	lsls r0, r0, #9
	adds r1, r4, #1
	adds r0, r0, r1
	strb r3, [r0]
	ldrb r1, [r6]
	ldr r0, [r2]
	adds r1, r1, r0
	adds r1, #0x84
	movs r0, #2
	strb r0, [r1]
	b _0803C9B4
	.align 2, 0
_0803C558: .4byte 0x02023FD6
_0803C55C: .4byte 0x02024140
_0803C560:
	ldr r0, _0803C5CC
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ands r0, r1
	cmp r0, #0
	bne _0803C586
	ldrb r0, [r6]
	lsls r1, r0, #9
	adds r1, r1, r5
	ldrb r1, [r1]
	bl RecordedBattle_SetBattlerAction
	ldrb r0, [r6]
	lsls r1, r0, #9
	adds r1, r1, r7
	ldrb r1, [r1]
	bl RecordedBattle_SetBattlerAction
_0803C586:
	ldrb r0, [r6]
	ldr r4, _0803C5D0
	ldr r1, [r4]
	adds r1, r0, r1
	adds r1, #0x80
	lsls r0, r0, #9
	adds r0, r0, r5
	ldrb r0, [r0]
	strb r0, [r1]
	ldr r0, _0803C5D4
	ldrb r2, [r6]
	lsls r5, r2, #1
	adds r5, r5, r0
	ldr r3, _0803C5D8
	ldr r4, [r4]
	adds r0, r2, r4
	adds r0, #0x80
	ldrb r0, [r0]
	lsls r0, r0, #1
	movs r1, #0x58
	muls r1, r2, r1
	adds r0, r0, r1
	adds r3, #0xc
	adds r0, r0, r3
	ldrh r0, [r0]
	strh r0, [r5]
	ldrb r0, [r6]
	adds r4, r0, r4
	lsls r0, r0, #9
	adds r0, r0, r7
	ldrb r0, [r0]
	strb r0, [r4, #0xc]
	ldr r0, _0803C5DC
	ldrb r1, [r6]
	b _0803C7B6
	.align 2, 0
_0803C5CC: .4byte 0x02022C90
_0803C5D0: .4byte 0x02024140
_0803C5D4: .4byte 0x02023F18
_0803C5D8: .4byte 0x02023D28
_0803C5DC: .4byte 0x02023FD6
_0803C5E0:
	ldr r2, _0803C608
	ldr r5, _0803C60C
	ldrb r4, [r5]
	lsls r1, r4, #9
	adds r0, r2, #1
	adds r0, r1, r0
	ldrb r3, [r0]
	adds r2, #2
	adds r1, r1, r2
	ldrb r0, [r1]
	lsls r0, r0, #8
	orrs r3, r0
	cmp r3, #0
	bne _0803C5FE
	b _0803C860
_0803C5FE:
	ldr r0, _0803C610
	strh r3, [r0]
	ldr r0, _0803C614
	ldrb r1, [r5]
	b _0803C7B6
	.align 2, 0
_0803C608: .4byte 0x02023508
_0803C60C: .4byte 0x02023D08
_0803C610: .4byte 0x02023EAC
_0803C614: .4byte 0x02023FD6
_0803C618:
	ldr r0, _0803C63C
	ldr r4, _0803C640
	ldrb r2, [r4]
	lsls r1, r2, #9
	adds r0, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #6
	bne _0803C648
	ldr r0, _0803C644
	adds r0, r2, r0
	movs r1, #1
	strb r1, [r0]
	ldrb r0, [r4]
	bl RecordedBattle_ClearBattlerAction
	b _0803C948
	.align 2, 0
_0803C63C: .4byte 0x02023508
_0803C640: .4byte 0x02023D08
_0803C644: .4byte 0x02023FD6
_0803C648:
	bl UpdateBattlerPartyOrdersOnSwitch
	b _0803C7B2
_0803C64E:
	ldr r2, _0803C664
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0803C668
	ldr r0, _0803C66C
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C664: .4byte 0x02023F24
_0803C668: .4byte 0x02023FD6
_0803C66C: .4byte 0x02023D08
_0803C670:
	ldr r2, _0803C67C
	ldr r0, _0803C680
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C67C: .4byte 0x02023FD6
_0803C680: .4byte 0x02023D08
_0803C684:
	ldr r2, _0803C690
	ldr r0, _0803C694
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C690: .4byte 0x02023FD6
_0803C694: .4byte 0x02023D08
_0803C698:
	ldr r3, _0803C6BC
	ldr r0, _0803C6C0
	ldrb r4, [r0]
	lsls r1, r4, #9
	adds r0, r3, #1
	adds r0, r1, r0
	ldrb r2, [r0]
	adds r3, #2
	adds r1, r1, r3
	ldrb r0, [r1]
	lsls r0, r0, #8
	orrs r2, r0
	cmp r2, #0
	bne _0803C6B6
	b _0803C860
_0803C6B6:
	ldr r1, _0803C6C4
	adds r1, r4, r1
	b _0803C7B8
	.align 2, 0
_0803C6BC: .4byte 0x02023508
_0803C6C0: .4byte 0x02023D08
_0803C6C4: .4byte 0x02023FD6
_0803C6C8:
	ldr r2, _0803C6D4
	ldr r0, _0803C6D8
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C6D4: .4byte 0x02023FD6
_0803C6D8: .4byte 0x02023D08
_0803C6DC:
	ldr r2, _0803C6F4
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r2]
	ldr r2, _0803C6F8
	ldr r0, _0803C6FC
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C6F4: .4byte 0x02023F24
_0803C6F8: .4byte 0x02023FD6
_0803C6FC: .4byte 0x02023D08
_0803C700:
	ldr r2, _0803C70C
	ldr r0, _0803C710
	ldrb r1, [r0]
	adds r1, r1, r2
	b _0803C7B8
	.align 2, 0
_0803C70C: .4byte 0x02023FD6
_0803C710: .4byte 0x02023D08
_0803C714:
	ldr r3, _0803C78C
	ldr r6, _0803C790
	ldr r0, _0803C794
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	lsls r1, r2, #4
	movs r0, #0xf0
	lsls r0, r0, #0x18
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, #8
	orrs r1, r0
	lsls r2, r2, #0xc
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0803C73E
	b _0803C948
_0803C73E:
	bl AllAtActionConfirmed
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r4, r1, #0x1f
	ldr r0, _0803C798
	ldr r0, [r0]
	movs r1, #0x41
	ands r0, r1
	cmp r0, #1
	bne _0803C780
	movs r1, #2
	movs r0, #2
	ands r0, r5
	cmp r0, #0
	bne _0803C780
	adds r0, r5, #0
	eors r0, r1
	bl GetBattlerAtPosition
	ldr r1, _0803C79C
	ldr r1, [r1]
	adds r1, #0x91
	ldrb r1, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r0, r0, r6
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _0803C7A0
_0803C780:
	movs r0, #0
	movs r1, #0
	adds r2, r4, #0
	bl BtlController_EmitLinkStandbyMsg
	b _0803C7AA
	.align 2, 0
_0803C78C: .4byte 0x02023D0C
_0803C790: .4byte 0x082FACB4
_0803C794: .4byte 0x02023D08
_0803C798: .4byte 0x02022C90
_0803C79C: .4byte 0x02024140
_0803C7A0:
	movs r0, #0
	movs r1, #1
	adds r2, r4, #0
	bl BtlController_EmitLinkStandbyMsg
_0803C7AA:
	ldr r4, _0803C7C0
_0803C7AC:
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
_0803C7B2:
	ldr r0, _0803C7C4
	ldrb r1, [r4]
_0803C7B6:
	adds r1, r1, r0
_0803C7B8:
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _0803C948
	.align 2, 0
_0803C7C0: .4byte 0x02023D08
_0803C7C4: .4byte 0x02023FD6
_0803C7C8:
	ldr r3, _0803C7FC
	ldr r1, _0803C800
	ldr r0, _0803C804
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r1, r2, #4
	movs r0, #0xf0
	lsls r0, r0, #0x18
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, #8
	orrs r1, r0
	lsls r2, r2, #0xc
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _0803C7F2
	b _0803C948
_0803C7F2:
	ldr r1, _0803C808
	ldrb r0, [r1, #4]
	adds r0, #1
	strb r0, [r1, #4]
	b _0803C948
	.align 2, 0
_0803C7FC: .4byte 0x02023D0C
_0803C800: .4byte 0x082FACB4
_0803C804: .4byte 0x02023D08
_0803C808: .4byte 0x02023FD6
_0803C80C:
	ldr r5, _0803C82C
	ldrb r2, [r5]
	ldr r0, _0803C830
	ldr r0, [r0]
	adds r1, r2, r0
	adds r0, r1, #0
	adds r0, #0x54
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C8F8
	ldr r0, _0803C834
	adds r0, r2, r0
	adds r1, #0x84
	ldrb r1, [r1]
	strb r1, [r0]
	b _0803C948
	.align 2, 0
_0803C82C: .4byte 0x02023D08
_0803C830: .4byte 0x02024140
_0803C834: .4byte 0x02023FD6
_0803C838:
	ldr r3, _0803C86C
	ldr r1, _0803C870
	ldr r0, _0803C874
	ldrb r4, [r0]
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r1, r2, #4
	movs r0, #0xf0
	lsls r0, r0, #0x18
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, #8
	orrs r1, r0
	lsls r2, r2, #0xc
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0803C948
_0803C860:
	ldr r0, _0803C878
	adds r0, r4, r0
_0803C864:
	movs r1, #1
	strb r1, [r0]
	b _0803C948
	.align 2, 0
_0803C86C: .4byte 0x02023D0C
_0803C870: .4byte 0x082FACB4
_0803C874: .4byte 0x02023D08
_0803C878: .4byte 0x02023FD6
_0803C87C:
	ldr r5, _0803C8C0
	ldrb r2, [r5]
	ldr r4, _0803C8C4
	ldr r0, [r4]
	adds r0, r2, r0
	adds r0, #0x54
	ldrb r0, [r0]
	cmp r0, #0
	beq _0803C8F8
	ldr r0, _0803C8C8
	lsls r1, r2, #9
	adds r0, #1
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0xd
	bne _0803C8D8
	ldr r2, _0803C8CC
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #8
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0803C8D0
	ldrb r0, [r5]
	adds r0, r0, r1
	movs r1, #3
	strb r1, [r0]
	ldr r1, _0803C8D4
	ldrb r0, [r5]
_0803C8B6:
	adds r0, r0, r1
	movs r1, #4
	strb r1, [r0]
	b _0803C948
	.align 2, 0
_0803C8C0: .4byte 0x02023D08
_0803C8C4: .4byte 0x02024140
_0803C8C8: .4byte 0x02023508
_0803C8CC: .4byte 0x02023F24
_0803C8D0: .4byte 0x02023EC0
_0803C8D4: .4byte 0x02023FD6
_0803C8D8:
	adds r0, r2, #0
	movs r1, #1
	bl RecordedBattle_ClearBattlerAction
	ldr r2, _0803C8F4
	ldrb r0, [r5]
	adds r2, r0, r2
	ldr r1, [r4]
	adds r0, r0, r1
	adds r0, #0x84
	ldrb r0, [r0]
	strb r0, [r2]
	b _0803C948
	.align 2, 0
_0803C8F4: .4byte 0x02023FD6
_0803C8F8:
	ldr r0, _0803C9C4
	strb r2, [r0]
	ldr r7, _0803C9C8
	ldr r6, _0803C9CC
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r4, [r0]
	str r4, [r7]
	ldr r3, _0803C9D0
	ldr r1, _0803C9D4
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	lsls r1, r2, #4
	movs r0, #0xf0
	lsls r0, r0, #0x18
	orrs r1, r0
	orrs r1, r2
	lsls r0, r2, #8
	orrs r1, r0
	lsls r2, r2, #0xc
	orrs r1, r2
	ldr r0, [r3]
	ands r0, r1
	cmp r0, #0
	bne _0803C93E
	ldr r0, _0803C9D8
	ldrb r1, [r4]
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl _call_via_r0
_0803C93E:
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r1, [r7]
	str r1, [r0]
_0803C948:
	ldr r0, _0803C9DC
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	ldr r0, _0803C9E0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
_0803C956:
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r1, r0
	bhs _0803C962
	bl HandleTurnActionSelectionState
_0803C962:
	ldr r0, _0803C9E4
	ldrb r0, [r0, #4]
	ldrb r1, [r5]
	cmp r0, r1
	bne _0803C9B4
	movs r0, #1
	bl sub_08185D94
	ldr r1, _0803C9E8
	ldr r0, _0803C9EC
	str r0, [r1]
	ldr r0, _0803C9F0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0803C9B4
	movs r4, #0
	ldrb r5, [r5]
	cmp r4, r5
	bge _0803C9B4
_0803C98E:
	ldr r0, _0803C9F4
	adds r0, r4, r0
	ldrb r0, [r0]
	cmp r0, #2
	bne _0803C9AA
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _0803C9F8
	ldr r1, [r1]
	adds r1, r4, r1
	adds r1, #0x5c
	ldrb r1, [r1]
	bl SwitchPartyOrderInGameMulti
_0803C9AA:
	adds r4, #1
	ldr r0, _0803C9E0
	ldrb r0, [r0]
	cmp r4, r0
	blt _0803C98E
_0803C9B4:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0803C9C4: .4byte 0x02023EAF
_0803C9C8: .4byte 0x02023EB8
_0803C9CC: .4byte 0x02023EC4
_0803C9D0: .4byte 0x02023D0C
_0803C9D4: .4byte 0x082FACB4
_0803C9D8: .4byte 0x082EC694
_0803C9DC: .4byte 0x02023D08
_0803C9E0: .4byte 0x02023D10
_0803C9E4: .4byte 0x02023FD6
_0803C9E8: .4byte 0x03005A64
_0803C9EC: .4byte 0x0803CF2D
_0803C9F0: .4byte 0x02022C90
_0803C9F4: .4byte 0x02023EC0
_0803C9F8: .4byte 0x02024140
	thumb_func_end HandleTurnActionSelectionState
