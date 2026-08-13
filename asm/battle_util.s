.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified








	thumb_func_start AbilityBattleEffects
AbilityBattleEffects: @ 0x08042468
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	ldr r4, [sp, #0x48]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #4]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r8, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0
	mov sb, r0
	ldr r5, _080424C4
	ldr r1, _080424C8
	ldrb r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	blo _080424A4
	mov r1, sl
	strb r1, [r5]
_080424A4:
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080424D4
	ldr r1, _080424CC
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _080424D0
	b _080424E4
	.align 2, 0
_080424C4: .4byte 0x02023EAF
_080424C8: .4byte 0x02023D10
_080424CC: .4byte 0x02023D12
_080424D0: .4byte 0x02024190
_080424D4:
	ldr r1, _08042514
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _08042518
_080424E4:
	adds r7, r1, r0
	ldr r5, _0804251C
	ldr r1, _08042520
	ldrb r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	blo _080424F6
	mov r2, sl
	strb r2, [r5]
_080424F6:
	ldrb r0, [r5]
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08042528
	ldr r1, _08042514
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _08042524
	b _08042538
	.align 2, 0
_08042514: .4byte 0x02023D12
_08042518: .4byte 0x020243E8
_0804251C: .4byte 0x02023EB0
_08042520: .4byte 0x02023D10
_08042524: .4byte 0x02024190
_08042528:
	ldr r1, _08042588
	ldrb r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _0804258C
_08042538:
	adds r5, r1, r0
	adds r0, r7, #0
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	bl GetMonData3
	str r0, [sp, #0x10]
	adds r0, r5, #0
	movs r1, #0xb
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	movs r1, #0
	bl GetMonData3
	str r0, [sp, #0x14]
	ldr r0, _08042590
	ldr r0, [r0]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0804257A
	bl _0804407A
_0804257A:
	mov r3, r8
	cmp r3, #0
	beq _08042598
	ldr r0, _08042594
	strb r3, [r0]
	adds r7, r0, #0
	b _080425AE
	.align 2, 0
_08042588: .4byte 0x02023D12
_0804258C: .4byte 0x020243E8
_08042590: .4byte 0x02022C90
_08042594: .4byte 0x02023EAE
_08042598:
	ldr r2, _080425B8
	ldr r1, _080425BC
	movs r0, #0x58
	mov r5, sl
	muls r5, r0, r5
	adds r0, r5, #0
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r0, [r0]
	strb r0, [r2]
	adds r7, r2, #0
_080425AE:
	cmp r4, #0
	beq _080425C0
	adds r5, r4, #0
	b _080425C4
	.align 2, 0
_080425B8: .4byte 0x02023EAE
_080425BC: .4byte 0x02023D28
_080425C0:
	ldr r0, _080425D8
	ldrh r5, [r0]
_080425C4:
	ldr r1, _080425DC
	ldr r0, [r1]
	ldrb r0, [r0, #0x13]
	mov r8, r1
	cmp r0, #0
	beq _080425E0
	movs r3, #0x3f
	ands r3, r0
	b _080425EC
	.align 2, 0
_080425D8: .4byte 0x02023E8E
_080425DC: .4byte 0x02024140
_080425E0:
	ldr r1, _08042600
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r3, [r0, #2]
_080425EC:
	ldr r0, [sp, #4]
	cmp r0, #0x13
	bls _080425F6
	bl _0804405E
_080425F6:
	lsls r0, r0, #2
	ldr r1, _08042604
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08042600: .4byte 0x082ED220
_08042604: .4byte 0x08042608
_08042608: @ jump table
	.4byte _08042658 @ case 0
	.4byte _0804291C @ case 1
	.4byte _08042B38 @ case 2
	.4byte _08042BCC @ case 3
	.4byte _08042DEC @ case 4
	.4byte _08043548 @ case 5
	.4byte _080438AC @ case 6
	.4byte _080438FC @ case 7
	.4byte _08043980 @ case 8
	.4byte _08043A04 @ case 9
	.4byte _08043C24 @ case 10
	.4byte _08043A48 @ case 11
	.4byte _08043C68 @ case 12
	.4byte _08043CC4 @ case 13
	.4byte _08043D20 @ case 14
	.4byte _08043E1C @ case 15
	.4byte _08043E60 @ case 16
	.4byte _08043EBC @ case 17
	.4byte _0804402C @ case 18
	.4byte _08043DD6 @ case 19
_08042658:
	ldr r2, _0804268C
	ldr r0, _08042690
	ldrb r1, [r2]
	adds r5, r0, #0
	ldrb r3, [r5]
	cmp r1, r3
	blo _0804266A
	mov r0, sl
	strb r0, [r2]
_0804266A:
	ldrb r0, [r7]
	cmp r0, #0x2d
	bne _08042672
	b _080427E8
_08042672:
	cmp r0, #0x2d
	bgt _080426A4
	cmp r0, #0xd
	bne _0804267C
	b _080428E4
_0804267C:
	cmp r0, #0xd
	bgt _08042694
	cmp r0, #2
	bne _08042686
	b _080427B8
_08042686:
	bl _0804405E
	.align 2, 0
_0804268C: .4byte 0x02023EAF
_08042690: .4byte 0x02023D10
_08042694:
	cmp r0, #0x16
	bne _0804269A
	b _08042848
_0804269A:
	cmp r0, #0x24
	bne _080426A0
	b _080428A8
_080426A0:
	bl _0804405E
_080426A4:
	cmp r0, #0x46
	bne _080426AA
	b _08042818
_080426AA:
	cmp r0, #0x46
	bgt _080426B8
	cmp r0, #0x3b
	bne _080426B4
	b _0804287C
_080426B4:
	bl _0804405E
_080426B8:
	cmp r0, #0x4d
	bne _080426BE
	b _080428E4
_080426BE:
	cmp r0, #0xff
	beq _080426C6
	bl _0804405E
_080426C6:
	ldr r0, _080426EC
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x11
	ands r0, r1
	cmp r0, #0
	bne _0804278C
	bl GetCurrentWeather
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #3
	cmp r0, #0xa
	bhi _0804278C
	lsls r0, r0, #2
	ldr r1, _080426F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080426EC: .4byte 0x02022C90
_080426F0: .4byte 0x080426F4
_080426F4: @ jump table
	.4byte _08042720 @ case 0
	.4byte _0804278C @ case 1
	.4byte _08042720 @ case 2
	.4byte _0804278C @ case 3
	.4byte _0804278C @ case 4
	.4byte _08042744 @ case 5
	.4byte _0804278C @ case 6
	.4byte _0804278C @ case 7
	.4byte _0804278C @ case 8
	.4byte _08042768 @ case 9
	.4byte _08042720 @ case 10
_08042720:
	ldr r2, _0804273C
	ldrh r1, [r2]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0804278C
	movs r0, #5
	strh r0, [r2]
	ldr r1, _08042740
	movs r0, #0xa
	strb r0, [r1, #0x10]
	mov r2, sl
	strb r2, [r1, #0x17]
	b _08042782
	.align 2, 0
_0804273C: .4byte 0x02024070
_08042740: .4byte 0x02024118
_08042744:
	ldr r3, _08042760
	ldrh r1, [r3]
	movs r2, #0x18
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _0804278C
	strh r2, [r3]
	ldr r1, _08042764
	movs r0, #0xc
	strb r0, [r1, #0x10]
	mov r3, sl
	strb r3, [r1, #0x17]
	b _08042782
	.align 2, 0
_08042760: .4byte 0x02024070
_08042764: .4byte 0x02024118
_08042768:
	ldr r3, _080427A8
	ldrh r1, [r3]
	movs r2, #0x60
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _0804278C
	strh r2, [r3]
	ldr r1, _080427AC
	movs r0, #0xb
	strb r0, [r1, #0x10]
	mov r5, sl
	strb r5, [r1, #0x17]
_08042782:
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_0804278C:
	mov r0, sb
	cmp r0, #0
	bne _08042796
	bl _0804407A
_08042796:
	bl GetCurrentWeather
	ldr r1, _080427B0
	strb r0, [r1, #5]
	ldr r0, _080427B4
	bl BattleScriptPushCursorAndCallback
	bl _0804405E
	.align 2, 0
_080427A8: .4byte 0x02024070
_080427AC: .4byte 0x02024118
_080427B0: .4byte 0x02023FD6
_080427B4: .4byte 0x0828926F
_080427B8:
	ldr r2, _080427DC
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080427C8
	bl _0804405E
_080427C8:
	movs r0, #5
	strh r0, [r2]
	ldr r0, _080427E0
	bl BattleScriptPushCursorAndCallback
	ldr r0, _080427E4
	mov r1, sl
	strb r1, [r0, #0x17]
	bl _08044010
	.align 2, 0
_080427DC: .4byte 0x02024070
_080427E0: .4byte 0x082899B8
_080427E4: .4byte 0x02024118
_080427E8:
	ldr r2, _0804280C
	ldrh r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080427F8
	bl _0804405E
_080427F8:
	movs r0, #0x18
	strh r0, [r2]
	ldr r0, _08042810
	bl BattleScriptPushCursorAndCallback
	ldr r0, _08042814
	mov r2, sl
	strb r2, [r0, #0x17]
	bl _08044010
	.align 2, 0
_0804280C: .4byte 0x02024070
_08042810: .4byte 0x082899F8
_08042814: .4byte 0x02024118
_08042818:
	ldr r2, _0804283C
	ldrh r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08042828
	bl _0804405E
_08042828:
	movs r0, #0x60
	strh r0, [r2]
	ldr r0, _08042840
	bl BattleScriptPushCursorAndCallback
	ldr r0, _08042844
	mov r3, sl
	strb r3, [r0, #0x17]
	bl _08044010
	.align 2, 0
_0804283C: .4byte 0x02024070
_08042840: .4byte 0x08289AB2
_08042844: .4byte 0x02024118
_08042848:
	ldr r0, _08042874
	mov r5, sl
	lsls r2, r5, #2
	adds r1, r2, r5
	lsls r1, r1, #2
	adds r3, r1, r0
	ldrb r0, [r3]
	lsls r0, r0, #0x1c
	cmp r0, #0
	bge _08042860
	bl _0804405E
_08042860:
	ldr r1, _08042878
	adds r1, r2, r1
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0xc
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r3]
	movs r1, #8
	b _080428D2
	.align 2, 0
_08042874: .4byte 0x02024020
_08042878: .4byte 0x02023F50
_0804287C:
	mov r0, sl
	bl CastformDataTypeChange
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #0
	bne _08042890
	bl _0804407A
_08042890:
	ldr r0, _080428A0
	bl BattleScriptPushCursorAndCallback
	ldr r0, _080428A4
	mov r1, sl
	strb r1, [r0, #0x17]
	bl _08043F22
	.align 2, 0
_080428A0: .4byte 0x08289A31
_080428A4: .4byte 0x02024118
_080428A8:
	ldr r0, _080428DC
	mov r3, sl
	lsls r2, r3, #2
	adds r1, r2, r3
	lsls r1, r1, #2
	adds r3, r1, r0
	ldrb r0, [r3]
	lsls r0, r0, #0x1b
	cmp r0, #0
	bge _080428C0
	bl _0804405E
_080428C0:
	ldr r1, _080428E0
	adds r1, r2, r1
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0xd
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r3]
	movs r1, #0x10
_080428D2:
	orrs r0, r1
	strb r0, [r3]
	bl _0804405E
	.align 2, 0
_080428DC: .4byte 0x02024020
_080428E0: .4byte 0x02023F50
_080428E4:
	movs r6, #0
	ldrb r5, [r5]
	cmp r6, r5
	blo _080428F0
	bl _0804405E
_080428F0:
	adds r0, r6, #0
	bl CastformDataTypeChange
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #0
	beq _08042904
	bl sub_08043F18
_08042904:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	ldr r0, _08042918
	ldrb r0, [r0]
	cmp r6, r0
	blo _080428F0
	bl _0804405E
	.align 2, 0
_08042918: .4byte 0x02023D10
_0804291C:
	ldr r5, _0804294C
	mov r8, r5
	movs r0, #0x58
	mov r6, sl
	muls r6, r0, r6
	adds r4, r6, r5
	ldrh r0, [r4, #0x28]
	cmp r0, #0
	bne _08042932
	bl _0804405E
_08042932:
	ldr r0, _08042950
	mov r1, sl
	strb r1, [r0]
	ldrb r5, [r7]
	cmp r5, #0x2c
	beq _08042962
	cmp r5, #0x2c
	bgt _08042954
	cmp r5, #3
	bne _08042948
	b _08042AC4
_08042948:
	bl _0804405E
	.align 2, 0
_0804294C: .4byte 0x02023D28
_08042950: .4byte 0x02023EAF
_08042954:
	cmp r5, #0x36
	bne _0804295A
	b _08042B10
_0804295A:
	cmp r5, #0x3d
	beq _080429E0
	bl _0804405E
_08042962:
	movs r0, #0
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0xd
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0
	beq _0804297E
	bl _0804405E
_0804297E:
	str r0, [sp]
	movs r0, #0x13
	movs r1, #0
	movs r2, #0x4d
	movs r3, #0
	bl AbilityBattleEffects
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08042996
	bl _0804405E
_08042996:
	ldr r0, _080429D4
	ldrh r1, [r0]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080429A6
	bl _0804405E
_080429A6:
	ldrh r0, [r4, #0x2c]
	ldrh r2, [r4, #0x28]
	cmp r0, r2
	bhi _080429B2
	bl _0804405E
_080429B2:
	strb r5, [r7]
	ldr r0, _080429D8
	bl BattleScriptPushCursorAndCallback
	ldr r1, _080429DC
	ldrh r0, [r4, #0x2c]
	lsrs r0, r0, #4
	str r0, [r1]
	cmp r0, #0
	bne _080429CA
	movs r0, #1
	str r0, [r1]
_080429CA:
	ldr r0, [r1]
	rsbs r0, r0, #0
	str r0, [r1]
	bl _08044010
	.align 2, 0
_080429D4: .4byte 0x02024070
_080429D8: .4byte 0x082899E4
_080429DC: .4byte 0x02023E94
_080429E0:
	mov r0, r8
	adds r0, #0x4c
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _080429F0
	bl _0804405E
_080429F0:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08042A0A
	bl _0804405E
_08042A0A:
	ldr r0, [r5]
	movs r1, #0x88
	ands r0, r1
	cmp r0, #0
	beq _08042A1C
	ldr r0, _08042A9C
	ldr r1, _08042AA0
	bl StringCopy
_08042A1C:
	ldr r0, [r5]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08042A2E
	ldr r0, _08042A9C
	ldr r1, _08042AA4
	bl StringCopy
_08042A2E:
	ldr r0, [r5]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08042A40
	ldr r0, _08042A9C
	ldr r1, _08042AA8
	bl StringCopy
_08042A40:
	ldr r0, [r5]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08042A52
	ldr r0, _08042A9C
	ldr r1, _08042AAC
	bl StringCopy
_08042A52:
	ldr r0, [r5]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08042A64
	ldr r0, _08042A9C
	ldr r1, _08042AB0
	bl StringCopy
_08042A64:
	str r4, [r5]
	mov r1, r8
	adds r1, #0x50
	adds r1, r6, r1
	ldr r0, [r1]
	ldr r2, _08042AB4
	ands r0, r2
	str r0, [r1]
	ldr r0, _08042AB8
	ldr r4, _08042ABC
	mov r3, sl
	strb r3, [r4]
	strb r3, [r0, #0x17]
	ldr r0, _08042AC0
	bl BattleScriptPushCursorAndCallback
	str r5, [sp]
	movs r0, #0
	movs r1, #0x28
	movs r2, #0
	movs r3, #4
	bl BtlController_EmitSetMonData
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	bl _08044010
	.align 2, 0
_08042A9C: .4byte 0x02022C0C
_08042AA0: .4byte 0x085ABC54
_08042AA4: .4byte 0x085ABC50
_08042AA8: .4byte 0x085ABC5B
_08042AAC: .4byte 0x085ABC57
_08042AB0: .4byte 0x085ABC5E
_08042AB4: .4byte 0xF7FFFFFF
_08042AB8: .4byte 0x02024118
_08042ABC: .4byte 0x02023D08
_08042AC0: .4byte 0x08289A0C
_08042AC4:
	ldrb r2, [r4, #0x1b]
	movs r0, #0x1b
	ldrsb r0, [r4, r0]
	cmp r0, #0xb
	ble _08042AD2
	bl _0804405E
_08042AD2:
	ldr r0, _08042B04
	mov r5, sl
	lsls r1, r5, #3
	subs r1, r1, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1, #0x16]
	cmp r0, #2
	bne _08042AE8
	bl _0804405E
_08042AE8:
	adds r0, r2, #1
	movs r1, #0
	strb r0, [r4, #0x1b]
	ldr r4, _08042B08
	movs r0, #0x11
	strb r0, [r4, #0x10]
	strb r1, [r4, #0x11]
	ldr r0, _08042B0C
	bl BattleScriptPushCursorAndCallback
	strb r5, [r4, #0x17]
	bl _08044010
	.align 2, 0
_08042B04: .4byte 0x02023F60
_08042B08: .4byte 0x02024118
_08042B0C: .4byte 0x082899CC
_08042B10:
	ldr r2, _08042B34
	ldrb r0, [r0]
	lsls r1, r0, #3
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrb r3, [r1, #0x18]
	lsls r0, r3, #0x1f
	lsrs r0, r0, #0x1f
	movs r2, #1
	eors r2, r0
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r3
	orrs r0, r2
	strb r0, [r1, #0x18]
	bl _0804405E
	.align 2, 0
_08042B34: .4byte 0x02023F60
_08042B38:
	ldrb r0, [r7]
	cmp r0, #0x2b
	beq _08042B42
	bl _0804405E
_08042B42:
	movs r4, #0
	ldr r0, _08042BB0
	ldrh r2, [r0]
	ldr r3, _08042BB4
	adds r1, r0, #0
	cmp r2, r3
	bne _08042B54
	bl _0804405E
_08042B54:
	cmp r2, r5
	beq _08042B6C
	adds r2, r1, #0
_08042B5A:
	adds r2, #2
	adds r4, #1
	ldrh r0, [r2]
	cmp r0, r3
	bne _08042B68
	bl _0804405E
_08042B68:
	cmp r0, r5
	bne _08042B5A
_08042B6C:
	lsls r0, r4, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r0, _08042BB4
	cmp r1, r0
	bne _08042B7C
	bl _0804405E
_08042B7C:
	ldr r1, _08042BB8
	ldr r0, _08042BBC
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	beq _08042BA2
	ldr r0, _08042BC0
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #4
	orrs r1, r2
	str r1, [r0]
_08042BA2:
	ldr r1, _08042BC4
	ldr r0, _08042BC8
	str r0, [r1]
	movs r0, #1
	mov sb, r0
	bl _08044064
	.align 2, 0
_08042BB0: .4byte 0x082EC67C
_08042BB4: .4byte 0x0000FFFF
_08042BB8: .4byte 0x02023D28
_08042BBC: .4byte 0x02023EAF
_08042BC0: .4byte 0x02023F24
_08042BC4: .4byte 0x02023EB8
_08042BC8: .4byte 0x08289BA7
_08042BCC:
	cmp r5, #0
	bne _08042BD4
	bl _0804405E
_08042BD4:
	ldrb r0, [r7]
	cmp r0, #0xb
	beq _08042C44
	cmp r0, #0xb
	bgt _08042BE4
	cmp r0, #0xa
	beq _08042BEA
	b _08042D66
_08042BE4:
	cmp r0, #0x12
	beq _08042C9C
	b _08042D66
_08042BEA:
	cmp r3, #0xd
	beq _08042BF0
	b _08042D66
_08042BF0:
	ldr r0, _08042C1C
	lsls r1, r5, #1
	adds r1, r1, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1, #1]
	cmp r0, #0
	bne _08042C02
	b _08042D66
_08042C02:
	ldr r1, _08042C20
	ldr r0, _08042C24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x1c
	cmp r0, #0
	bge _08042C30
	ldr r1, _08042C28
	ldr r0, _08042C2C
	b _08042C34
	.align 2, 0
_08042C1C: .4byte 0x082ED220
_08042C20: .4byte 0x02023FE0
_08042C24: .4byte 0x02023EAF
_08042C28: .4byte 0x02023EB8
_08042C2C: .4byte 0x08289AF7
_08042C30:
	ldr r1, _08042C3C
	ldr r0, _08042C40
_08042C34:
	str r0, [r1]
	movs r1, #1
	b _08042D64
	.align 2, 0
_08042C3C: .4byte 0x02023EB8
_08042C40: .4byte 0x08289AF6
_08042C44:
	cmp r3, #0xb
	beq _08042C4A
	b _08042D66
_08042C4A:
	ldr r0, _08042C74
	lsls r1, r5, #1
	adds r1, r1, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1, #1]
	cmp r0, #0
	bne _08042C5C
	b _08042D66
_08042C5C:
	ldr r1, _08042C78
	ldr r0, _08042C7C
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x1c
	cmp r0, #0
	bge _08042C88
	ldr r1, _08042C80
	ldr r0, _08042C84
	b _08042C8C
	.align 2, 0
_08042C74: .4byte 0x082ED220
_08042C78: .4byte 0x02023FE0
_08042C7C: .4byte 0x02023EAF
_08042C80: .4byte 0x02023EB8
_08042C84: .4byte 0x08289AF7
_08042C88:
	ldr r1, _08042C94
	ldr r0, _08042C98
_08042C8C:
	str r0, [r1]
	movs r2, #1
	mov sb, r2
	b _08042D66
	.align 2, 0
_08042C94: .4byte 0x02023EB8
_08042C98: .4byte 0x08289AF6
_08042C9C:
	cmp r3, #0xa
	bne _08042D66
	ldr r1, _08042CEC
	movs r0, #0x58
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	bne _08042D66
	ldr r2, _08042CF0
	ldr r0, [r2]
	ldr r0, [r0, #4]
	mov r5, sl
	lsls r1, r5, #2
	adds r0, r0, r1
	ldr r3, [r0]
	movs r4, #1
	ands r3, r4
	adds r5, r1, #0
	cmp r3, #0
	bne _08042D2C
	ldr r0, _08042CF4
	strb r3, [r0, #5]
	ldr r1, _08042CF8
	ldr r0, _08042CFC
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x1c
	cmp r0, #0
	bge _08042D08
	ldr r1, _08042D00
	ldr r0, _08042D04
	b _08042D0C
	.align 2, 0
_08042CEC: .4byte 0x02023D28
_08042CF0: .4byte 0x0202414C
_08042CF4: .4byte 0x02023FD6
_08042CF8: .4byte 0x02023FE0
_08042CFC: .4byte 0x02023EAF
_08042D00: .4byte 0x02023EB8
_08042D04: .4byte 0x08289B30
_08042D08:
	ldr r1, _08042D24
	ldr r0, _08042D28
_08042D0C:
	str r0, [r1]
	ldr r0, [r2]
	ldr r1, [r0, #4]
	adds r1, r1, r5
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	movs r0, #2
	mov sb, r0
	b _08042D66
	.align 2, 0
_08042D24: .4byte 0x02023EB8
_08042D28: .4byte 0x08289B2F
_08042D2C:
	ldr r0, _08042D48
	strb r4, [r0, #5]
	ldr r1, _08042D4C
	ldr r0, _08042D50
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x1c
	cmp r0, #0
	bge _08042D5C
	ldr r1, _08042D54
	ldr r0, _08042D58
	b _08042D60
	.align 2, 0
_08042D48: .4byte 0x02023FD6
_08042D4C: .4byte 0x02023FE0
_08042D50: .4byte 0x02023EAF
_08042D54: .4byte 0x02023EB8
_08042D58: .4byte 0x08289B30
_08042D5C:
	ldr r1, _08042DA0
	ldr r0, _08042DA4
_08042D60:
	str r0, [r1]
	movs r1, #2
_08042D64:
	mov sb, r1
_08042D66:
	mov r2, sb
	cmp r2, #1
	beq _08042D70
	bl _0804405E
_08042D70:
	ldr r1, _08042DA8
	movs r0, #0x58
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r0, r1
	ldrh r0, [r1, #0x2c]
	ldrh r5, [r1, #0x28]
	cmp r0, r5
	bne _08042DCC
	ldr r1, _08042DAC
	ldr r0, _08042DB0
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrb r0, [r0, #2]
	lsls r0, r0, #0x1c
	cmp r0, #0
	bge _08042DB8
	ldr r1, _08042DA0
	ldr r0, _08042DB4
	str r0, [r1]
	bl _0804405E
	.align 2, 0
_08042DA0: .4byte 0x02023EB8
_08042DA4: .4byte 0x08289B2F
_08042DA8: .4byte 0x02023D28
_08042DAC: .4byte 0x02023FE0
_08042DB0: .4byte 0x02023EAF
_08042DB4: .4byte 0x08289B1A
_08042DB8:
	ldr r1, _08042DC4
	ldr r0, _08042DC8
	str r0, [r1]
	bl _0804405E
	.align 2, 0
_08042DC4: .4byte 0x02023EB8
_08042DC8: .4byte 0x08289B19
_08042DCC:
	ldr r2, _08042DE8
	ldrh r0, [r1, #0x2c]
	lsrs r0, r0, #2
	str r0, [r2]
	cmp r0, #0
	bne _08042DDC
	mov r0, sb
	str r0, [r2]
_08042DDC:
	ldr r0, [r2]
	rsbs r0, r0, #0
	str r0, [r2]
	bl _0804405E
	.align 2, 0
_08042DE8: .4byte 0x02023E94
_08042DEC:
	ldrb r0, [r7]
	subs r0, #9
	cmp r0, #0x2f
	bls _08042DF8
	bl _0804405E
_08042DF8:
	lsls r0, r0, #2
	ldr r1, _08042E04
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08042E04: .4byte 0x08042E08
_08042E08: @ jump table
	.4byte _08043224 @ case 0
	.4byte _0804405E @ case 1
	.4byte _0804405E @ case 2
	.4byte _0804405E @ case 3
	.4byte _0804405E @ case 4
	.4byte _0804405E @ case 5
	.4byte _0804405E @ case 6
	.4byte _08042EC8 @ case 7
	.4byte _0804405E @ case 8
	.4byte _0804405E @ case 9
	.4byte _0804405E @ case 10
	.4byte _0804405E @ case 11
	.4byte _0804405E @ case 12
	.4byte _0804405E @ case 13
	.4byte _0804405E @ case 14
	.4byte _08042F90 @ case 15
	.4byte _0804405E @ case 16
	.4byte _0804405E @ case 17
	.4byte _08043050 @ case 18
	.4byte _0804405E @ case 19
	.4byte _0804405E @ case 20
	.4byte _0804405E @ case 21
	.4byte _0804405E @ case 22
	.4byte _0804405E @ case 23
	.4byte _0804405E @ case 24
	.4byte _0804405E @ case 25
	.4byte _0804405E @ case 26
	.4byte _0804405E @ case 27
	.4byte _0804405E @ case 28
	.4byte _08043148 @ case 29
	.4byte _0804405E @ case 30
	.4byte _0804405E @ case 31
	.4byte _0804405E @ case 32
	.4byte _0804405E @ case 33
	.4byte _0804405E @ case 34
	.4byte _0804405E @ case 35
	.4byte _0804405E @ case 36
	.4byte _0804405E @ case 37
	.4byte _0804405E @ case 38
	.4byte _0804405E @ case 39
	.4byte _08043300 @ case 40
	.4byte _0804405E @ case 41
	.4byte _0804405E @ case 42
	.4byte _0804405E @ case 43
	.4byte _0804405E @ case 44
	.4byte _0804405E @ case 45
	.4byte _0804405E @ case 46
	.4byte _080433DC @ case 47
_08042EC8:
	ldr r0, _08042F70
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _08042ED8
	bl _0804405E
_08042ED8:
	cmp r5, #0xa5
	bne _08042EE0
	bl _0804405E
_08042EE0:
	ldr r0, _08042F74
	lsls r1, r5, #1
	adds r1, r1, r5
	lsls r1, r1, #2
	adds r1, r1, r0
	ldrb r0, [r1, #1]
	cmp r0, #0
	bne _08042EF4
	bl _0804405E
_08042EF4:
	ldr r2, _08042F78
	ldr r0, _08042F7C
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #2
	adds r0, r2, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08042F1C
	adds r0, r2, #0
	adds r0, #0xc
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08042F1C
	bl _0804405E
_08042F1C:
	ldr r1, _08042F80
	movs r0, #0x58
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r0, r1
	adds r4, r1, #0
	adds r4, #0x21
	ldrb r0, [r4]
	cmp r0, r3
	bne _08042F36
	bl _0804405E
_08042F36:
	adds r2, r1, #0
	adds r2, #0x22
	ldrb r0, [r2]
	cmp r0, r3
	bne _08042F44
	bl _0804405E
_08042F44:
	ldrh r0, [r1, #0x28]
	cmp r0, #0
	bne _08042F4E
	bl _0804405E
_08042F4E:
	strb r3, [r4]
	strb r3, [r2]
	ldr r1, _08042F84
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #3
	strb r0, [r1, #1]
	strb r3, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	bl BattleScriptPushCursor
	ldr r1, _08042F88
	ldr r0, _08042F8C
	str r0, [r1]
	bl _08044010
	.align 2, 0
_08042F70: .4byte 0x02023F20
_08042F74: .4byte 0x082ED220
_08042F78: .4byte 0x02024020
_08042F7C: .4byte 0x02023EB0
_08042F80: .4byte 0x02023D28
_08042F84: .4byte 0x02022C0C
_08042F88: .4byte 0x02023EB8
_08042F8C: .4byte 0x08289BD5
_08042F90:
	ldr r0, _08043028
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _08042FA0
	bl _0804405E
_08042FA0:
	ldr r1, _0804302C
	ldr r0, _08043030
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r3, r0, r1
	ldrh r0, [r3, #0x28]
	cmp r0, #0
	bne _08042FB6
	bl _0804405E
_08042FB6:
	ldr r0, _08043034
	lsls r1, r2, #4
	adds r1, r1, r0
	ldrb r0, [r1, #1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08042FC8
	bl _0804405E
_08042FC8:
	ldr r2, _08043038
	ldr r0, _0804303C
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #2
	adds r0, r2, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08042FF0
	adds r0, r2, #0
	adds r0, #0xc
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08042FF0
	bl _0804405E
_08042FF0:
	ldr r1, _08043040
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #8]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _0804300A
	bl _0804405E
_0804300A:
	ldr r1, _08043044
	ldrh r0, [r3, #0x2c]
	lsrs r0, r0, #4
	str r0, [r1]
	cmp r0, #0
	bne _08043018
	str r2, [r1]
_08043018:
	bl BattleScriptPushCursor
	ldr r1, _08043048
	ldr r0, _0804304C
	str r0, [r1]
	bl _08044010
	.align 2, 0
_08043028: .4byte 0x02023F20
_0804302C: .4byte 0x02023D28
_08043030: .4byte 0x02023EAF
_08043034: .4byte 0x02023FE0
_08043038: .4byte 0x02024020
_0804303C: .4byte 0x02023EB0
_08043040: .4byte 0x082ED220
_08043044: .4byte 0x02023E94
_08043048: .4byte 0x02023EB8
_0804304C: .4byte 0x08289BDC
_08043050:
	ldr r0, _0804311C
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _08043060
	bl _0804405E
_08043060:
	ldr r1, _08043120
	ldr r0, _08043124
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _08043076
	bl _0804405E
_08043076:
	ldr r0, _08043128
	lsls r1, r2, #4
	adds r1, r1, r0
	ldrb r0, [r1, #1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08043088
	bl _0804405E
_08043088:
	ldr r2, _0804312C
	ldr r0, _08043130
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #2
	adds r0, r2, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _080430B0
	adds r0, r2, #0
	adds r0, #0xc
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _080430B0
	bl _0804405E
_080430B0:
	ldr r1, _08043134
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080430C8
	bl _0804405E
_080430C8:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xa
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080430E0
	bl _0804405E
_080430E0:
	ldr r5, _08043138
	movs r4, #3
_080430E4:
	bl Random
	ands r0, r4
	strb r0, [r5, #3]
	cmp r0, #0
	beq _080430E4
	ldr r1, _08043138
	ldrb r0, [r1, #3]
	cmp r0, #3
	bne _080430FC
	adds r0, #2
	strb r0, [r1, #3]
_080430FC:
	ldrb r0, [r1, #3]
	adds r0, #0x40
	strb r0, [r1, #3]
	bl BattleScriptPushCursor
	ldr r1, _0804313C
	ldr r0, _08043140
	str r0, [r1]
	ldr r2, _08043144
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r0, r1
	str r0, [r2]
	bl _08044010
	.align 2, 0
_0804311C: .4byte 0x02023F20
_08043120: .4byte 0x02023D28
_08043124: .4byte 0x02023EAF
_08043128: .4byte 0x02023FE0
_0804312C: .4byte 0x02024020
_08043130: .4byte 0x02023EB0
_08043134: .4byte 0x082ED220
_08043138: .4byte 0x02023FD6
_0804313C: .4byte 0x02023EB8
_08043140: .4byte 0x08289C04
_08043144: .4byte 0x02023F24
_08043148:
	ldr r0, _080431F8
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _08043158
	bl _0804405E
_08043158:
	ldr r1, _080431FC
	ldr r0, _08043200
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _0804316E
	bl _0804405E
_0804316E:
	ldr r0, _08043204
	lsls r1, r2, #4
	adds r1, r1, r0
	ldrb r0, [r1, #1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08043180
	bl _0804405E
_08043180:
	ldr r2, _08043208
	ldr r0, _0804320C
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #2
	adds r0, r2, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _080431A8
	adds r0, r2, #0
	adds r0, #0xc
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _080431A8
	bl _0804405E
_080431A8:
	ldr r1, _08043210
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080431C0
	bl _0804405E
_080431C0:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080431D8
	bl _0804405E
_080431D8:
	ldr r1, _08043214
	movs r0, #0x42
	strb r0, [r1, #3]
	bl BattleScriptPushCursor
	ldr r1, _08043218
	ldr r0, _0804321C
	str r0, [r1]
	ldr r2, _08043220
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r0, r1
	str r0, [r2]
	bl _08044010
	.align 2, 0
_080431F8: .4byte 0x02023F20
_080431FC: .4byte 0x02023D28
_08043200: .4byte 0x02023EAF
_08043204: .4byte 0x02023FE0
_08043208: .4byte 0x02024020
_0804320C: .4byte 0x02023EB0
_08043210: .4byte 0x082ED220
_08043214: .4byte 0x02023FD6
_08043218: .4byte 0x02023EB8
_0804321C: .4byte 0x08289C04
_08043220: .4byte 0x02023F24
_08043224:
	ldr r0, _080432D4
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _08043234
	bl _0804405E
_08043234:
	ldr r1, _080432D8
	ldr r0, _080432DC
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _0804324A
	bl _0804405E
_0804324A:
	ldr r0, _080432E0
	lsls r1, r2, #4
	adds r1, r1, r0
	ldrb r0, [r1, #1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _0804325C
	bl _0804405E
_0804325C:
	ldr r2, _080432E4
	ldr r0, _080432E8
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #2
	adds r0, r2, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08043284
	adds r0, r2, #0
	adds r0, #0xc
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08043284
	bl _0804405E
_08043284:
	ldr r1, _080432EC
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0804329C
	bl _0804405E
_0804329C:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _080432B4
	bl _0804405E
_080432B4:
	ldr r1, _080432F0
	movs r0, #0x45
	strb r0, [r1, #3]
	bl BattleScriptPushCursor
	ldr r1, _080432F4
	ldr r0, _080432F8
	str r0, [r1]
	ldr r2, _080432FC
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r0, r1
	str r0, [r2]
	bl _08044010
	.align 2, 0
_080432D4: .4byte 0x02023F20
_080432D8: .4byte 0x02023D28
_080432DC: .4byte 0x02023EAF
_080432E0: .4byte 0x02023FE0
_080432E4: .4byte 0x02024020
_080432E8: .4byte 0x02023EB0
_080432EC: .4byte 0x082ED220
_080432F0: .4byte 0x02023FD6
_080432F4: .4byte 0x02023EB8
_080432F8: .4byte 0x08289C04
_080432FC: .4byte 0x02023F24
_08043300:
	ldr r0, _080433B0
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _08043310
	bl _0804405E
_08043310:
	ldr r1, _080433B4
	ldr r0, _080433B8
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _08043326
	bl _0804405E
_08043326:
	ldr r0, _080433BC
	lsls r1, r2, #4
	adds r1, r1, r0
	ldrb r0, [r1, #1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08043338
	bl _0804405E
_08043338:
	ldr r1, _080433C0
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08043350
	bl _0804405E
_08043350:
	ldr r2, _080433C4
	ldr r0, _080433C8
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #2
	adds r0, r2, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08043378
	adds r0, r2, #0
	adds r0, #0xc
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08043378
	bl _0804405E
_08043378:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08043390
	bl _0804405E
_08043390:
	ldr r1, _080433CC
	movs r0, #0x43
	strb r0, [r1, #3]
	bl BattleScriptPushCursor
	ldr r1, _080433D0
	ldr r0, _080433D4
	str r0, [r1]
	ldr r2, _080433D8
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r0, r1
	str r0, [r2]
	bl _08044010
	.align 2, 0
_080433B0: .4byte 0x02023F20
_080433B4: .4byte 0x02023D28
_080433B8: .4byte 0x02023EAF
_080433BC: .4byte 0x02023FE0
_080433C0: .4byte 0x082ED220
_080433C4: .4byte 0x02024020
_080433C8: .4byte 0x02023EB0
_080433CC: .4byte 0x02023FD6
_080433D0: .4byte 0x02023EB8
_080433D4: .4byte 0x08289C04
_080433D8: .4byte 0x02023F24
_080433DC:
	ldr r0, _08043520
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _080433EC
	bl _0804405E
_080433EC:
	ldr r6, _08043524
	ldr r3, _08043528
	mov r8, r3
	ldrb r1, [r3]
	movs r7, #0x58
	adds r0, r1, #0
	muls r0, r7, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _08043406
	bl _0804405E
_08043406:
	ldr r0, _0804352C
	lsls r1, r1, #4
	adds r1, r1, r0
	ldrb r0, [r1, #1]
	lsls r0, r0, #0x1f
	cmp r0, #0
	beq _08043418
	bl _0804405E
_08043418:
	ldr r1, _08043530
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #8]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08043430
	bl _0804405E
_08043430:
	ldr r3, _08043534
	ldr r5, _08043538
	ldrb r1, [r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r2, r0, #2
	adds r0, r3, #0
	adds r0, #8
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08043458
	adds r0, r3, #0
	adds r0, #0xc
	adds r0, r2, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08043458
	bl _0804405E
_08043458:
	adds r0, r1, #0
	muls r0, r7, r0
	adds r0, r0, r6
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	bne _08043468
	bl _0804405E
_08043468:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08043480
	bl _0804405E
_08043480:
	mov r1, r8
	ldrb r0, [r1]
	muls r0, r7, r0
	adds r0, r0, r6
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0xc
	bne _08043494
	bl _0804405E
_08043494:
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x10]
	bl GetGenderFromSpeciesAndPersonality
	adds r4, r0, #0
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x14]
	bl GetGenderFromSpeciesAndPersonality
	lsls r4, r4, #0x18
	lsls r0, r0, #0x18
	cmp r4, r0
	bne _080434B2
	bl _0804405E
_080434B2:
	mov r2, r8
	ldrb r0, [r2]
	muls r0, r7, r0
	adds r4, r6, #0
	adds r4, #0x50
	adds r0, r0, r4
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _080434CE
	bl _0804405E
_080434CE:
	ldr r0, [sp, #8]
	ldr r1, [sp, #0x10]
	bl GetGenderFromSpeciesAndPersonality
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080434E2
	bl _0804405E
_080434E2:
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x14]
	bl GetGenderFromSpeciesAndPersonality
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xff
	bne _080434F6
	bl _0804405E
_080434F6:
	mov r3, r8
	ldrb r0, [r3]
	adds r2, r0, #0
	muls r2, r7, r2
	adds r2, r2, r4
	ldr r1, _0804353C
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	bl BattleScriptPushCursor
	ldr r1, _08043540
	ldr r0, _08043544
	str r0, [r1]
	bl _08044010
	.align 2, 0
_08043520: .4byte 0x02023F20
_08043524: .4byte 0x02023D28
_08043528: .4byte 0x02023EAF
_0804352C: .4byte 0x02023FE0
_08043530: .4byte 0x082ED220
_08043534: .4byte 0x02024020
_08043538: .4byte 0x02023EB0
_0804353C: .4byte 0x082FACB4
_08043540: .4byte 0x02023EB8
_08043544: .4byte 0x08289BF7
_08043548:
	movs r5, #0
	mov sl, r5
	ldr r0, _0804357C
	ldrb r0, [r0]
	cmp sl, r0
	blo _08043558
	bl _0804405E
_08043558:
	ldr r1, _08043580
	movs r0, #0x58
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	adds r0, r0, r1
	adds r0, #0x20
	ldrb r0, [r0]
	subs r0, #7
	adds r2, r1, #0
	cmp r0, #0x41
	bls _08043572
	b _080437D6
_08043572:
	lsls r0, r0, #2
	ldr r1, _08043584
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0804357C: .4byte 0x02023D10
_08043580: .4byte 0x02023D28
_08043584: .4byte 0x08043588
_08043588: @ jump table
	.4byte _080436EC @ case 0
	.4byte _080437D6 @ case 1
	.4byte _080437D6 @ case 2
	.4byte _080437D6 @ case 3
	.4byte _080437D6 @ case 4
	.4byte _080437B0 @ case 5
	.4byte _080437D6 @ case 6
	.4byte _080437D6 @ case 7
	.4byte _08043714 @ case 8
	.4byte _080437D6 @ case 9
	.4byte _08043690 @ case 10
	.4byte _080437D6 @ case 11
	.4byte _080437D6 @ case 12
	.4byte _080436BC @ case 13
	.4byte _080437D6 @ case 14
	.4byte _080437D6 @ case 15
	.4byte _080437D6 @ case 16
	.4byte _080437D6 @ case 17
	.4byte _080437D6 @ case 18
	.4byte _080437D6 @ case 19
	.4byte _080437D6 @ case 20
	.4byte _080437D6 @ case 21
	.4byte _080437D6 @ case 22
	.4byte _080437D6 @ case 23
	.4byte _080437D6 @ case 24
	.4byte _080437D6 @ case 25
	.4byte _080437D6 @ case 26
	.4byte _080437D6 @ case 27
	.4byte _080437D6 @ case 28
	.4byte _080437D6 @ case 29
	.4byte _080437D6 @ case 30
	.4byte _080437D6 @ case 31
	.4byte _080437D6 @ case 32
	.4byte _08043780 @ case 33
	.4byte _08043750 @ case 34
	.4byte _080437D6 @ case 35
	.4byte _080437D6 @ case 36
	.4byte _080437D6 @ case 37
	.4byte _080437D6 @ case 38
	.4byte _080437D6 @ case 39
	.4byte _080437D6 @ case 40
	.4byte _080437D6 @ case 41
	.4byte _080437D6 @ case 42
	.4byte _080437D6 @ case 43
	.4byte _080437D6 @ case 44
	.4byte _080437D6 @ case 45
	.4byte _080437D6 @ case 46
	.4byte _080437D6 @ case 47
	.4byte _080437D6 @ case 48
	.4byte _080437D6 @ case 49
	.4byte _080437D6 @ case 50
	.4byte _080437D6 @ case 51
	.4byte _080437D6 @ case 52
	.4byte _080437D6 @ case 53
	.4byte _080437D6 @ case 54
	.4byte _080437D6 @ case 55
	.4byte _080437D6 @ case 56
	.4byte _080437D6 @ case 57
	.4byte _080437D6 @ case 58
	.4byte _080437D6 @ case 59
	.4byte _080437D6 @ case 60
	.4byte _080437D6 @ case 61
	.4byte _080437D6 @ case 62
	.4byte _080437D6 @ case 63
	.4byte _080437D6 @ case 64
	.4byte _08043714 @ case 65
_08043690:
	movs r0, #0x58
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _080436B0
	ands r0, r1
	cmp r0, #0
	bne _080436AA
	b _080437D6
_080436AA:
	ldr r0, _080436B4
	ldr r1, _080436B8
	b _0804379C
	.align 2, 0
_080436B0: .4byte 0x00000F88
_080436B4: .4byte 0x02022C0C
_080436B8: .4byte 0x085ABC54
_080436BC:
	movs r0, #0x58
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080436D6
	b _080437D6
_080436D6:
	ldr r0, _080436E4
	ldr r1, _080436E8
	bl StringCopy
	movs r2, #2
	mov sb, r2
	b _080437DC
	.align 2, 0
_080436E4: .4byte 0x02022C0C
_080436E8: .4byte 0x085ABC62
_080436EC:
	movs r0, #0x58
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080437D6
	ldr r0, _0804370C
	ldr r1, _08043710
	b _0804379C
	.align 2, 0
_0804370C: .4byte 0x02022C0C
_08043710: .4byte 0x085ABC5B
_08043714:
	movs r0, #0x58
	mov r3, sl
	muls r3, r0, r3
	adds r0, r2, #0
	adds r0, #0x4c
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	beq _080437D6
	adds r2, #0x50
	adds r2, r3, r2
	ldr r0, [r2]
	ldr r1, _08043744
	ands r0, r1
	str r0, [r2]
	ldr r0, _08043748
	ldr r1, _0804374C
	bl StringCopy
	movs r0, #1
	mov sb, r0
	b _080437DC
	.align 2, 0
_08043744: .4byte 0xF7FFFFFF
_08043748: .4byte 0x02022C0C
_0804374C: .4byte 0x085ABC50
_08043750:
	movs r0, #0x58
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080437D6
	ldr r0, _08043778
	ldr r1, _0804377C
	bl StringCopy
	movs r2, #1
	mov sb, r2
	b _080437DC
	.align 2, 0
_08043778: .4byte 0x02022C0C
_0804377C: .4byte 0x085ABC57
_08043780:
	movs r0, #0x58
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	adds r1, #0x4c
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080437D6
	ldr r0, _080437A8
	ldr r1, _080437AC
_0804379C:
	bl StringCopy
	movs r5, #1
	mov sb, r5
	b _080437DC
	.align 2, 0
_080437A8: .4byte 0x02022C0C
_080437AC: .4byte 0x085ABC5E
_080437B0:
	movs r0, #0x58
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	adds r1, #0x50
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0xf0
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	beq _080437D6
	ldr r0, _080437EC
	ldr r1, _080437F0
	bl StringCopy
	movs r2, #3
	mov sb, r2
_080437D6:
	mov r3, sb
	cmp r3, #0
	beq _08043890
_080437DC:
	mov r5, sb
	cmp r5, #2
	beq _08043810
	cmp r5, #2
	bgt _080437F4
	cmp r5, #1
	beq _080437FC
	b _0804383C
	.align 2, 0
_080437EC: .4byte 0x02022C0C
_080437F0: .4byte 0x085ABC67
_080437F4:
	mov r0, sb
	cmp r0, #3
	beq _08043828
	b _0804383C
_080437FC:
	ldr r1, _0804380C
	movs r0, #0x58
	mov r2, sl
	muls r2, r0, r2
	adds r1, #0x4c
	adds r2, r2, r1
	movs r0, #0
	b _0804383A
	.align 2, 0
_0804380C: .4byte 0x02023D28
_08043810:
	ldr r1, _08043824
	movs r0, #0x58
	mov r2, sl
	muls r2, r0, r2
	adds r1, #0x50
	adds r2, r2, r1
	ldr r0, [r2]
	movs r1, #8
	rsbs r1, r1, #0
	b _08043838
	.align 2, 0
_08043824: .4byte 0x02023D28
_08043828:
	ldr r1, _08043874
	movs r0, #0x58
	mov r2, sl
	muls r2, r0, r2
	adds r1, #0x50
	adds r2, r2, r1
	ldr r0, [r2]
	ldr r1, _08043878
_08043838:
	ands r0, r1
_0804383A:
	str r0, [r2]
_0804383C:
	bl BattleScriptPushCursor
	ldr r1, _0804387C
	ldr r0, _08043880
	str r0, [r1]
	ldr r0, _08043884
	mov r1, sl
	strb r1, [r0, #0x17]
	ldr r4, _08043888
	strb r1, [r4]
	ldrb r1, [r4]
	movs r0, #0x58
	muls r0, r1, r0
	ldr r1, _0804388C
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #0x28
	movs r2, #0
	movs r3, #4
	bl BtlController_EmitSetMonData
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	bl _0804407A
	.align 2, 0
_08043874: .4byte 0x02023D28
_08043878: .4byte 0xFFF0FFFF
_0804387C: .4byte 0x02023EB8
_08043880: .4byte 0x08289C14
_08043884: .4byte 0x02024118
_08043888: .4byte 0x02023D08
_0804388C: .4byte 0x02023D74
_08043890:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r0, _080438A8
	ldrb r0, [r0]
	cmp sl, r0
	bhs _080438A4
	b _08043558
_080438A4:
	bl _0804405E
	.align 2, 0
_080438A8: .4byte 0x02023D10
_080438AC:
	movs r2, #0
	mov sl, r2
	ldr r0, _080438F4
	ldrb r0, [r0]
	cmp sl, r0
	blo _080438BA
	b _0804405E
_080438BA:
	ldr r4, _080438F8
_080438BC:
	movs r0, #0x58
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	adds r0, r0, r4
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0x3b
	bne _080438E0
	mov r0, sl
	bl CastformDataTypeChange
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	cmp r0, #0
	beq _080438E0
	b _08043F3C
_080438E0:
	mov r0, sl
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r0, _080438F4
	ldrb r0, [r0]
	cmp sl, r0
	blo _080438BC
	b _0804405E
	.align 2, 0
_080438F4: .4byte 0x02023D10
_080438F8: .4byte 0x02023D28
_080438FC:
	ldrb r0, [r7]
	cmp r0, #0x1c
	beq _08043904
	b _0804405E
_08043904:
	ldr r4, _08043964
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08043914
	b _0804405E
_08043914:
	ldr r0, _08043968
	ands r1, r0
	str r1, [r4]
	mov r5, r8
	ldr r1, [r5]
	adds r1, #0xb2
	ldrb r2, [r1]
	movs r0, #0x3f
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r5]
	adds r1, r0, #0
	adds r1, #0xb2
	ldrb r0, [r1]
	cmp r0, #6
	bne _08043938
	movs r0, #2
	strb r0, [r1]
_08043938:
	ldr r1, _0804396C
	mov r2, r8
	ldr r0, [r2]
	adds r0, #0xb2
	ldrb r0, [r0]
	adds r0, #0x40
	strb r0, [r1, #3]
	ldr r1, _08043970
	ldr r0, _08043974
	ldrb r0, [r0]
	strb r0, [r1, #0x17]
	bl BattleScriptPushCursor
	ldr r1, _08043978
	ldr r0, _0804397C
	str r0, [r1]
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r0, r1
	str r0, [r4]
	b _08044010
	.align 2, 0
_08043964: .4byte 0x02023F24
_08043968: .4byte 0xFFFFBFFF
_0804396C: .4byte 0x02023FD6
_08043970: .4byte 0x02024118
_08043974: .4byte 0x02023EB0
_08043978: .4byte 0x02023EB8
_0804397C: .4byte 0x08289C07
_08043980:
	ldrb r0, [r7]
	cmp r0, #0x1c
	beq _08043988
	b _0804405E
_08043988:
	ldr r4, _080439E8
	ldr r1, [r4]
	movs r0, #0x80
	lsls r0, r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08043998
	b _0804405E
_08043998:
	ldr r0, _080439EC
	ands r1, r0
	str r1, [r4]
	mov r3, r8
	ldr r1, [r3]
	adds r1, #0xb2
	ldrb r2, [r1]
	movs r0, #0x3f
	ands r0, r2
	strb r0, [r1]
	ldr r0, [r3]
	adds r1, r0, #0
	adds r1, #0xb2
	ldrb r0, [r1]
	cmp r0, #6
	bne _080439BC
	movs r0, #2
	strb r0, [r1]
_080439BC:
	ldr r1, _080439F0
	mov r3, r8
	ldr r0, [r3]
	adds r0, #0xb2
	ldrb r0, [r0]
	strb r0, [r1, #3]
	ldr r1, _080439F4
	ldr r0, _080439F8
	ldrb r0, [r0]
	strb r0, [r1, #0x17]
	bl BattleScriptPushCursor
	ldr r1, _080439FC
	ldr r0, _08043A00
	str r0, [r1]
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #6
	orrs r0, r1
	str r0, [r4]
	b _08044010
	.align 2, 0
_080439E8: .4byte 0x02023F24
_080439EC: .4byte 0xFFFFBFFF
_080439F0: .4byte 0x02023FD6
_080439F4: .4byte 0x02024118
_080439F8: .4byte 0x02023EAF
_080439FC: .4byte 0x02023EB8
_08043A00: .4byte 0x08289C07
_08043A04:
	movs r4, #0
	ldr r0, _08043A3C
	ldrb r1, [r0]
	cmp r4, r1
	blt _08043A10
	b _0804405E
_08043A10:
	ldr r0, _08043A40
	adds r5, r1, #0
	ldr r2, _08043A44
	adds r3, r0, #0
	adds r3, #0x20
	movs r6, #0x80
	lsls r6, r6, #0xc
_08043A1E:
	ldrb r1, [r3]
	cmp r1, #0x16
	bne _08043A2E
	ldr r0, [r2]
	ands r0, r6
	cmp r0, #0
	beq _08043A2E
	b _08043F64
_08043A2E:
	adds r2, #4
	adds r3, #0x58
	adds r4, #1
	cmp r4, r5
	blt _08043A1E
	b _0804405E
	.align 2, 0
_08043A3C: .4byte 0x02023D10
_08043A40: .4byte 0x02023D28
_08043A44: .4byte 0x02023F50
_08043A48:
	movs r4, #0
	ldr r0, _08043B24
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043A54
	b _0804405E
_08043A54:
	ldr r5, _08043B28
	mov r8, r5
	ldr r0, _08043B2C
	adds r0, #0x20
	str r0, [sp, #0x1c]
	movs r1, #0
	str r1, [sp, #0x20]
_08043A62:
	ldr r2, [sp, #0x1c]
	ldrb r0, [r2]
	cmp r0, #0x24
	beq _08043A6C
	b _08043BFE
_08043A6C:
	ldr r0, _08043B30
	ldr r3, [sp, #0x20]
	adds r0, r3, r0
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xd
	ands r1, r0
	str r3, [sp, #0x18]
	cmp r1, #0
	bne _08043A82
	b _08043BFE
_08043A82:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerPosition
	movs r1, #1
	adds r5, r0, #0
	eors r5, r1
	ands r5, r1
	adds r0, r5, #0
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r0, r5, #2
	bl GetBattlerAtPosition
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _08043B34
	ldr r0, [r0]
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	bne _08043AB4
	b _08043BC4
_08043AB4:
	movs r1, #0x58
	adds r0, r6, #0
	muls r0, r1, r0
	ldr r3, _08043B2C
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043B80
	ldrh r0, [r1, #0x28]
	cmp r0, #0
	beq _08043B3C
	movs r1, #0x58
	adds r0, r7, #0
	muls r0, r1, r0
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043B3C
	ldrh r0, [r1, #0x28]
	cmp r0, #0
	beq _08043B3C
	str r2, [sp, #0x24]
	bl Random
	ldr r2, [sp, #0x24]
	adds r1, r2, #0
	ands r1, r0
	lsls r1, r1, #1
	orrs r5, r1
	adds r0, r5, #0
	bl GetBattlerAtPosition
	mov r2, r8
	strb r0, [r2]
	ldrb r0, [r2]
	movs r3, #0x58
	muls r0, r3, r0
	ldr r5, _08043B2C
	adds r0, r0, r5
	adds r0, #0x20
	ldrb r0, [r0]
	ldr r1, [sp, #0x1c]
	strb r0, [r1]
	ldrb r0, [r2]
	muls r0, r3, r0
	adds r0, r0, r5
	adds r0, #0x20
	ldrb r0, [r0]
	ldr r2, _08043B38
	strb r0, [r2]
	b _08043BEC
	.align 2, 0
_08043B24: .4byte 0x02023D10
_08043B28: .4byte 0x02023D08
_08043B2C: .4byte 0x02023D28
_08043B30: .4byte 0x02023F50
_08043B34: .4byte 0x02022C90
_08043B38: .4byte 0x02023EAE
_08043B3C:
	ldr r3, _08043B7C
	movs r2, #0x58
	adds r0, r6, #0
	muls r0, r2, r0
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043B80
	ldrh r0, [r1, #0x28]
	cmp r0, #0
	beq _08043B80
	mov r5, r8
	strb r6, [r5]
	adds r1, r4, #0
	muls r1, r2, r1
	adds r1, r1, r3
	ldrb r0, [r5]
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r0, [r0]
	adds r1, #0x20
	strb r0, [r1]
	ldrb r0, [r5]
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r0, [r0]
	b _08043BE8
	.align 2, 0
_08043B7C: .4byte 0x02023D28
_08043B80:
	ldr r3, _08043BC0
	movs r2, #0x58
	adds r0, r7, #0
	muls r0, r2, r0
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, #0
	beq _08043BF6
	ldrh r0, [r1, #0x28]
	cmp r0, #0
	beq _08043BF6
	mov r5, r8
	strb r7, [r5]
	adds r1, r4, #0
	muls r1, r2, r1
	adds r1, r1, r3
	ldrb r0, [r5]
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r0, [r0]
	adds r1, #0x20
	strb r0, [r1]
	ldrb r0, [r5]
	muls r0, r2, r0
	adds r0, r0, r3
	adds r0, #0x20
	ldrb r0, [r0]
	b _08043BE8
	.align 2, 0
_08043BC0: .4byte 0x02023D28
_08043BC4:
	mov r2, r8
	strb r6, [r2]
	movs r3, #0x58
	adds r0, r6, #0
	muls r0, r3, r0
	ldr r5, _08043C18
	adds r0, r0, r5
	adds r2, r0, #0
	adds r2, #0x20
	ldrb r1, [r2]
	cmp r1, #0
	beq _08043BF6
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _08043BF6
	ldr r0, [sp, #0x1c]
	strb r1, [r0]
	ldrb r0, [r2]
_08043BE8:
	ldr r1, _08043C1C
	strb r0, [r1]
_08043BEC:
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08043BF6:
	mov r2, sb
	cmp r2, #0
	beq _08043BFE
	b _08043F80
_08043BFE:
	ldr r3, [sp, #0x1c]
	adds r3, #0x58
	str r3, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	adds r5, #4
	str r5, [sp, #0x20]
	adds r4, #1
	ldr r0, _08043C20
	ldrb r0, [r0]
	cmp r4, r0
	bge _08043C16
	b _08043A62
_08043C16:
	b _0804405E
	.align 2, 0
_08043C18: .4byte 0x02023D28
_08043C1C: .4byte 0x02023EAE
_08043C20: .4byte 0x02023D10
_08043C24:
	movs r4, #0
	ldr r0, _08043C5C
	ldrb r1, [r0]
	cmp r4, r1
	blt _08043C30
	b _0804405E
_08043C30:
	ldr r0, _08043C60
	adds r5, r1, #0
	ldr r2, _08043C64
	adds r3, r0, #0
	adds r3, #0x20
	movs r6, #0x80
	lsls r6, r6, #0xc
_08043C3E:
	ldrb r1, [r3]
	cmp r1, #0x16
	bne _08043C4E
	ldr r0, [r2]
	ands r0, r6
	cmp r0, #0
	beq _08043C4E
	b _08043FF4
_08043C4E:
	adds r2, #4
	adds r3, #0x58
	adds r4, #1
	cmp r4, r5
	blt _08043C3E
	b _0804405E
	.align 2, 0
_08043C5C: .4byte 0x02023D10
_08043C60: .4byte 0x02023D28
_08043C64: .4byte 0x02023F50
_08043C68:
	mov r0, sl
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #0
	ldr r0, _08043CB8
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043C7E
	b _0804405E
_08043C7E:
	ldr r7, _08043CBC
_08043C80:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r4, #1
	cmp r0, r5
	beq _08043CAA
	movs r0, #0x58
	muls r0, r4, r0
	adds r0, r0, r7
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, r6
	bne _08043CAA
	ldr r0, _08043CC0
	strb r6, [r0]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08043CAA:
	adds r4, r3, #0
	ldr r0, _08043CB8
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043C80
	b _0804405E
	.align 2, 0
_08043CB8: .4byte 0x02023D10
_08043CBC: .4byte 0x02023D28
_08043CC0: .4byte 0x02023EAE
_08043CC4:
	mov r0, sl
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #0
	ldr r0, _08043D14
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043CDA
	b _0804405E
_08043CDA:
	ldr r7, _08043D18
_08043CDC:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r4, #1
	cmp r0, r5
	bne _08043D06
	movs r0, #0x58
	muls r0, r4, r0
	adds r0, r0, r7
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, r6
	bne _08043D06
	ldr r0, _08043D1C
	strb r6, [r0]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08043D06:
	adds r4, r3, #0
	ldr r0, _08043D14
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043CDC
	b _0804405E
	.align 2, 0
_08043D14: .4byte 0x02023D10
_08043D18: .4byte 0x02023D28
_08043D1C: .4byte 0x02023EAE
_08043D20:
	ldrb r0, [r7]
	cmp r0, #0xfd
	beq _08043D44
	cmp r0, #0xfe
	beq _08043D7C
	movs r4, #0
	ldr r0, _08043D3C
	adds r5, r0, #0
	ldrb r0, [r5]
	cmp r4, r0
	blt _08043D38
	b _0804405E
_08043D38:
	ldr r2, _08043D40
	b _08043DB4
	.align 2, 0
_08043D3C: .4byte 0x02023D10
_08043D40: .4byte 0x02023D28
_08043D44:
	movs r4, #0
	ldr r0, _08043D74
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043D50
	b _0804405E
_08043D50:
	ldr r5, _08043D78
	movs r2, #0x80
	lsls r2, r2, #9
	adds r1, r0, #0
_08043D58:
	lsls r0, r4, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ands r0, r2
	adds r3, r4, #1
	cmp r0, #0
	beq _08043D6C
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08043D6C:
	adds r4, r3, #0
	cmp r4, r1
	blt _08043D58
	b _0804405E
	.align 2, 0
_08043D74: .4byte 0x02023D10
_08043D78: .4byte 0x02023F50
_08043D7C:
	movs r4, #0
	ldr r0, _08043DAC
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043D88
	b _0804405E
_08043D88:
	ldr r5, _08043DB0
	movs r2, #0x80
	lsls r2, r2, #0xa
	adds r1, r0, #0
_08043D90:
	lsls r0, r4, #2
	adds r0, r0, r5
	ldr r0, [r0]
	ands r0, r2
	adds r3, r4, #1
	cmp r0, #0
	beq _08043DA4
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08043DA4:
	adds r4, r3, #0
	cmp r4, r1
	blt _08043D90
	b _0804405E
	.align 2, 0
_08043DAC: .4byte 0x02023D10
_08043DB0: .4byte 0x02023F50
_08043DB4:
	movs r0, #0x58
	muls r0, r4, r0
	adds r0, r0, r2
	adds r0, #0x20
	ldrb r0, [r0]
	adds r3, r4, #1
	cmp r0, r6
	bne _08043DCC
	strb r6, [r7]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08043DCC:
	adds r4, r3, #0
	ldrb r1, [r5]
	cmp r4, r1
	blt _08043DB4
	b _0804405E
_08043DD6:
	movs r4, #0
	ldr r0, _08043E14
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043DE2
	b _0804405E
_08043DE2:
	ldr r2, _08043E18
	mov r8, r2
	adds r2, r0, #0
	movs r5, #0x58
_08043DEA:
	adds r0, r4, #0
	muls r0, r5, r0
	mov r3, r8
	adds r1, r0, r3
	adds r0, r1, #0
	adds r0, #0x20
	ldrb r0, [r0]
	adds r3, r4, #1
	cmp r0, r6
	bne _08043E0C
	ldrh r0, [r1, #0x28]
	cmp r0, #0
	beq _08043E0C
	strb r6, [r7]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08043E0C:
	adds r4, r3, #0
	cmp r4, r2
	blt _08043DEA
	b _0804405E
	.align 2, 0
_08043E14: .4byte 0x02023D10
_08043E18: .4byte 0x02023D28
_08043E1C:
	movs r4, #0
	ldr r0, _08043E54
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043E28
	b _0804405E
_08043E28:
	ldr r7, _08043E58
	adds r1, r0, #0
	movs r5, #0x58
	ldr r2, _08043E5C
_08043E30:
	adds r0, r4, #0
	muls r0, r5, r0
	adds r0, r0, r7
	adds r0, #0x20
	ldrb r0, [r0]
	adds r3, r4, #1
	cmp r0, r6
	bne _08043E4C
	cmp r4, sl
	beq _08043E4C
	strb r6, [r2]
	lsls r0, r3, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08043E4C:
	adds r4, r3, #0
	cmp r4, r1
	blt _08043E30
	b _0804405E
	.align 2, 0
_08043E54: .4byte 0x02023D10
_08043E58: .4byte 0x02023D28
_08043E5C: .4byte 0x02023EAE
_08043E60:
	mov r0, sl
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #0
	ldr r0, _08043EB0
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043E76
	b _0804405E
_08043E76:
	ldr r7, _08043EB4
_08043E78:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	beq _08043EA4
	movs r0, #0x58
	muls r0, r4, r0
	adds r0, r0, r7
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, r6
	bne _08043EA4
	ldr r0, _08043EB8
	strb r6, [r0]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08043EA4:
	adds r4, #1
	ldr r0, _08043EB0
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043E78
	b _0804405E
	.align 2, 0
_08043EB0: .4byte 0x02023D10
_08043EB4: .4byte 0x02023D28
_08043EB8: .4byte 0x02023EAE
_08043EBC:
	mov r0, sl
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	movs r4, #0
	ldr r0, _08043F0C
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043ED2
	b _0804405E
_08043ED2:
	ldr r7, _08043F10
_08043ED4:
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	bl GetBattlerSide
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, r5
	bne _08043F00
	movs r0, #0x58
	muls r0, r4, r0
	adds r0, r0, r7
	adds r0, #0x20
	ldrb r0, [r0]
	cmp r0, r6
	bne _08043F00
	ldr r0, _08043F14
	strb r6, [r0]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08043F00:
	adds r4, #1
	ldr r0, _08043F0C
	ldrb r0, [r0]
	cmp r4, r0
	blt _08043ED4
	b _0804405E
	.align 2, 0
_08043F0C: .4byte 0x02023D10
_08043F10: .4byte 0x02023D28
_08043F14: .4byte 0x02023EAE
	thumb_func_end AbilityBattleEffects

	thumb_func_start sub_08043F18
sub_08043F18: @ 0x08043F18
	ldr r0, _08043F30
	bl BattleScriptPushCursorAndCallback
	ldr r0, _08043F34
	strb r6, [r0, #0x17]
_08043F22:
	ldr r0, _08043F38
	ldr r0, [r0]
	adds r0, #0x7f
	mov r1, sb
	subs r1, #1
	strb r1, [r0]
	b _0804405E
	.align 2, 0
_08043F30: .4byte 0x08289A31
_08043F34: .4byte 0x02024118
_08043F38: .4byte 0x02024140
_08043F3C:
	ldr r0, _08043F58
	bl BattleScriptPushCursorAndCallback
	ldr r0, _08043F5C
	mov r5, sl
	strb r5, [r0, #0x17]
	ldr r0, _08043F60
	ldr r0, [r0]
	adds r0, #0x7f
	mov r1, sb
	subs r1, #1
	strb r1, [r0]
	b _0804407A
	.align 2, 0
_08043F58: .4byte 0x08289A31
_08043F5C: .4byte 0x02024118
_08043F60: .4byte 0x02024140
_08043F64:
	strb r1, [r7]
	ldr r0, [r2]
	ldr r1, _08043F78
	ands r0, r1
	str r0, [r2]
	ldr r0, _08043F7C
	bl BattleScriptPushCursorAndCallback
	b _08044008
	.align 2, 0
_08043F78: .4byte 0xFFF7FFFF
_08043F7C: .4byte 0x08289A40
_08043F80:
	ldr r0, _08043FD0
	bl BattleScriptPushCursorAndCallback
	ldr r1, _08043FD4
	ldr r0, [sp, #0x18]
	adds r1, r0, r1
	ldr r0, [r1]
	ldr r2, _08043FD8
	ands r0, r2
	str r0, [r1]
	ldr r0, _08043FDC
	strb r4, [r0, #0x17]
	ldr r1, _08043FE0
	movs r4, #0xfd
	strb r4, [r1]
	movs r0, #4
	strb r0, [r1, #1]
	ldr r2, _08043FE4
	ldrb r0, [r2]
	strb r0, [r1, #2]
	ldr r3, _08043FE8
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r1, _08043FEC
	strb r4, [r1]
	movs r0, #9
	strb r0, [r1, #1]
	ldr r0, _08043FF0
	ldrb r0, [r0]
	strb r0, [r1, #2]
	movs r0, #1
	rsbs r0, r0, #0
	strb r0, [r1, #3]
	b _0804405E
	.align 2, 0
_08043FD0: .4byte 0x082899DA
_08043FD4: .4byte 0x02023F50
_08043FD8: .4byte 0xFFEFFFFF
_08043FDC: .4byte 0x02024118
_08043FE0: .4byte 0x02022C0C
_08043FE4: .4byte 0x02023D08
_08043FE8: .4byte 0x02023D12
_08043FEC: .4byte 0x02022C1C
_08043FF0: .4byte 0x02023EAE
_08043FF4:
	strb r1, [r7]
	ldr r0, [r2]
	ldr r1, _0804401C
	ands r0, r1
	str r0, [r2]
	bl BattleScriptPushCursor
	ldr r1, _08044020
	ldr r0, _08044024
	str r0, [r1]
_08044008:
	ldr r0, _08044028
	ldr r0, [r0]
	adds r0, #0xd8
	strb r4, [r0]
_08044010:
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	b _0804405E
	.align 2, 0
_0804401C: .4byte 0xFFF7FFFF
_08044020: .4byte 0x02023EB8
_08044024: .4byte 0x08289A49
_08044028: .4byte 0x02024140
_0804402C:
	movs r4, #0
	ldr r0, _0804408C
	ldrb r1, [r0]
	cmp r4, r1
	bge _0804405E
	ldr r0, _08044090
	adds r2, r1, #0
	adds r1, r0, #0
	adds r1, #0x20
	ldr r3, _08044094
_08044040:
	ldrb r0, [r1]
	cmp r0, r6
	bne _08044056
	cmp r4, sl
	beq _08044056
	strb r6, [r3]
	mov r0, sb
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
_08044056:
	adds r1, #0x58
	adds r4, #1
	cmp r4, r2
	blt _08044040
_0804405E:
	mov r1, sb
	cmp r1, #0
	beq _0804407A
_08044064:
	ldr r2, [sp, #4]
	cmp r2, #0xb
	bhi _0804407A
	ldr r1, _08044094
	ldrb r0, [r1]
	cmp r0, #0xff
	beq _0804407A
	adds r1, r0, #0
	mov r0, sl
	bl RecordAbilityBattle
_0804407A:
	mov r0, sb
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804408C: .4byte 0x02023D10
_08044090: .4byte 0x02023D28
_08044094: .4byte 0x02023EAE
	thumb_func_end sub_08043F18

	thumb_func_start BattleScriptExecute
BattleScriptExecute: @ 0x08044098
	ldr r1, _080440C4
	str r0, [r1]
	ldr r0, _080440C8
	ldr r0, [r0]
	ldr r2, [r0, #0xc]
	adds r3, r2, #0
	adds r3, #0x20
	ldrb r0, [r3]
	adds r1, r0, #1
	strb r1, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r2, r2, r0
	ldr r1, _080440CC
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, _080440D0
	str r0, [r1]
	ldr r1, _080440D4
	movs r0, #0
	strb r0, [r1]
	bx lr
	.align 2, 0
_080440C4: .4byte 0x02023EB8
_080440C8: .4byte 0x0202414C
_080440CC: .4byte 0x03005A64
_080440D0: .4byte 0x0803DC59
_080440D4: .4byte 0x02023D27
	thumb_func_end BattleScriptExecute

	thumb_func_start BattleScriptPushCursorAndCallback
BattleScriptPushCursorAndCallback: @ 0x080440D8
	push {r4, lr}
	adds r4, r0, #0
	bl BattleScriptPushCursor
	ldr r0, _0804410C
	str r4, [r0]
	ldr r0, _08044110
	ldr r0, [r0]
	ldr r2, [r0, #0xc]
	adds r3, r2, #0
	adds r3, #0x20
	ldrb r0, [r3]
	adds r1, r0, #1
	strb r1, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x16
	adds r2, r2, r0
	ldr r1, _08044114
	ldr r0, [r1]
	str r0, [r2]
	ldr r0, _08044118
	str r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804410C: .4byte 0x02023EB8
_08044110: .4byte 0x0202414C
_08044114: .4byte 0x03005A64
_08044118: .4byte 0x0803DCCD
	thumb_func_end BattleScriptPushCursorAndCallback

	thumb_func_start ItemBattleEffects
ItemBattleEffects: @ 0x0804411C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	movs r0, #0
	mov sl, r0
	movs r1, #0
	str r1, [sp, #0xc]
	add r0, sp, #4
	strb r1, [r0]
	ldr r4, _08044168
	ldr r1, _0804416C
	movs r0, #0x58
	muls r0, r7, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x2e]
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xaf
	bne _08044174
	ldr r1, _08044170
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r5, [r0, #7]
	ldrb r0, [r0, #0x1a]
	b _08044188
	.align 2, 0
_08044168: .4byte 0x02023EAC
_0804416C: .4byte 0x02023D28
_08044170: .4byte 0x020240A8
_08044174:
	ldrh r0, [r4]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrh r0, [r4]
	bl sub_080D6D1C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_08044188:
	mov sb, r0
	ldr r1, _080441B0
	ldr r0, _080441B4
	ldrb r2, [r0]
	movs r0, #0x58
	muls r0, r2, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x2e]
	str r0, [sp, #0x14]
	cmp r0, #0xaf
	bne _080441BC
	ldr r1, _080441B8
	lsls r0, r2, #3
	subs r0, r0, r2
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r3, [r0, #7]
	mov r8, r3
	ldrb r0, [r0, #0x1a]
	b _080441D2
	.align 2, 0
_080441B0: .4byte 0x02023D28
_080441B4: .4byte 0x02023EAF
_080441B8: .4byte 0x020240A8
_080441BC:
	ldr r0, [sp, #0x14]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r0, [sp, #0x14]
	bl sub_080D6D1C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080441D2:
	str r0, [sp, #0x10]
	ldr r2, _08044208
	ldr r0, _0804420C
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r4, [r0, #0x2e]
	cmp r4, #0xaf
	beq _080441F2
	adds r0, r4, #0
	bl sub_080D6CF8
	adds r0, r4, #0
	bl sub_080D6D1C
_080441F2:
	ldr r0, [sp, #8]
	cmp r0, #4
	bls _080441FC
	bl _0804546A
_080441FC:
	lsls r0, r0, #2
	ldr r1, _08044210
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08044208: .4byte 0x02023D28
_0804420C: .4byte 0x02023EB0
_08044210: .4byte 0x08044214
_08044214: @ jump table
	.4byte _08044228 @ case 0
	.4byte _080442C8 @ case 1
	.4byte _0804546A @ case 2
	.4byte _08044EC0 @ case 3
	.4byte _08045310 @ case 4
_08044228:
	cmp r5, #0x17
	beq _08044258
	cmp r5, #0x20
	beq _08044234
	bl _0804546A
_08044234:
	adds r0, r7, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08044244
	bl _0804546A
_08044244:
	ldr r0, _08044254
	ldr r0, [r0]
	adds r0, #0x4a
	movs r1, #2
	strb r1, [r0]
	bl _0804546A
	.align 2, 0
_08044254: .4byte 0x02024140
_08044258:
	ldr r1, _080442B0
	mov r8, r1
	movs r0, #0x58
	adds r1, r7, #0
	muls r1, r0, r1
	mov r0, r8
	adds r0, #0x18
	adds r1, r1, r0
	movs r2, #6
	movs r3, #7
	mov sl, r3
_0804426E:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _0804427C
	strb r2, [r1]
	movs r5, #5
	str r5, [sp, #0xc]
_0804427C:
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r3, sl
	cmp r3, #0
	bge _0804426E
	ldr r5, [sp, #0xc]
	cmp r5, #0
	bne _08044294
	bl _0804546A
_08044294:
	ldr r0, _080442B4
	strb r7, [r0, #0x17]
	ldr r0, _080442B8
	strb r7, [r0]
	ldr r1, _080442BC
	ldr r0, _080442C0
	strb r7, [r0]
	strb r7, [r1]
	ldr r0, _080442C4
	bl BattleScriptExecute
	bl _0804546A
	.align 2, 0
_080442B0: .4byte 0x02023D28
_080442B4: .4byte 0x02024118
_080442B8: .4byte 0x02023EB3
_080442BC: .4byte 0x02023D08
_080442C0: .4byte 0x02023EAF
_080442C4: .4byte 0x08289D36
_080442C8:
	ldr r1, _080442F0
	movs r0, #0x58
	muls r0, r7, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x28]
	mov r8, r1
	cmp r0, #0
	bne _080442DC
	bl _0804546A
_080442DC:
	subs r0, r5, #1
	cmp r0, #0x2a
	bls _080442E6
	bl _08044E16
_080442E6:
	lsls r0, r0, #2
	ldr r1, _080442F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080442F0: .4byte 0x02023D28
_080442F4: .4byte 0x080442F8
_080442F8: @ jump table
	.4byte _080443A4 @ case 0
	.4byte _08044B84 @ case 1
	.4byte _08044C48 @ case 2
	.4byte _08044BB4 @ case 3
	.4byte _08044BE8 @ case 4
	.4byte _08044C18 @ case 5
	.4byte _080443F0 @ case 6
	.4byte _08044C84 @ case 7
	.4byte _08044CB4 @ case 8
	.4byte _080445BC @ case 9
	.4byte _0804463C @ case 10
	.4byte _080446B8 @ case 11
	.4byte _0804474C @ case 12
	.4byte _080447E0 @ case 13
	.4byte _08044874 @ case 14
	.4byte _080448DC @ case 15
	.4byte _08044930 @ case 16
	.4byte _08044984 @ case 17
	.4byte _080449EC @ case 18
	.4byte _08044A50 @ case 19
	.4byte _08044A9C @ case 20
	.4byte _08044E16 @ case 21
	.4byte _080444F0 @ case 22
	.4byte _08044E16 @ case 23
	.4byte _08044E16 @ case 24
	.4byte _08044E16 @ case 25
	.4byte _08044E16 @ case 26
	.4byte _08044DE0 @ case 27
	.4byte _08044E16 @ case 28
	.4byte _08044E16 @ case 29
	.4byte _08044E16 @ case 30
	.4byte _08044E16 @ case 31
	.4byte _08044E16 @ case 32
	.4byte _08044E16 @ case 33
	.4byte _08044E16 @ case 34
	.4byte _08044E16 @ case 35
	.4byte _08044E16 @ case 36
	.4byte _08044E16 @ case 37
	.4byte _08044E16 @ case 38
	.4byte _08044E16 @ case 39
	.4byte _08044E16 @ case 40
	.4byte _08044E16 @ case 41
	.4byte _0804455C @ case 42
_080443A4:
	movs r0, #0x58
	muls r0, r7, r0
	mov r1, r8
	adds r2, r0, r1
	ldrh r0, [r2, #0x2c]
	ldrh r1, [r2, #0x28]
	lsrs r0, r0, #1
	cmp r1, r0
	bls _080443BA
	bl _08044E16
_080443BA:
	cmp r6, #0
	beq _080443C2
	bl _08044E16
_080443C2:
	ldr r4, _080443E8
	mov r3, sb
	str r3, [r4]
	ldrh r3, [r2, #0x28]
	mov r5, sb
	adds r0, r3, r5
	ldrh r1, [r2, #0x2c]
	cmp r0, r1
	ble _080443D8
	subs r0, r1, r3
	str r0, [r4]
_080443D8:
	ldr r0, [r4]
	rsbs r0, r0, #0
	str r0, [r4]
	ldr r0, _080443EC
	bl BattleScriptExecute
	b _08044742
	.align 2, 0
_080443E8: .4byte 0x02023E94
_080443EC: .4byte 0x08289D4C
_080443F0:
	cmp r6, #0
	beq _080443F8
	bl _08044E16
_080443F8:
	adds r0, r7, #0
	bl GetBattlerSide
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0804441C
	ldr r1, _08044414
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _08044418
	b _0804442A
	.align 2, 0
_08044414: .4byte 0x02023D12
_08044418: .4byte 0x02024190
_0804441C:
	ldr r1, _08044498
	lsls r0, r7, #1
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #0x64
	muls r1, r0, r1
	ldr r0, _0804449C
_0804442A:
	adds r4, r1, r0
	movs r1, #0
	mov sl, r1
	add r5, sp, #4
_08044432:
	mov r1, sl
	adds r1, #0xd
	adds r0, r4, #0
	bl GetMonData3
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r1, sl
	adds r1, #0x11
	adds r0, r4, #0
	bl GetMonData3
	strb r0, [r5]
	adds r0, r4, #0
	movs r1, #0x15
	bl GetMonData3
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r6, #0
	beq _08044462
	ldrb r0, [r5]
	cmp r0, #0
	beq _0804446C
_08044462:
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	ble _08044432
_0804446C:
	mov r5, sl
	cmp r5, #4
	bne _08044476
	bl _08044E16
_08044476:
	lsls r2, r5, #0x18
	lsrs r2, r2, #0x18
	adds r0, r6, #0
	bl CalculatePPWithBonus
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	add r0, sp, #4
	ldrb r0, [r0]
	mov r3, sb
	adds r1, r0, r3
	cmp r1, r2
	ble _080444A0
	add r0, sp, #4
	strb r2, [r0]
	b _080444A4
	.align 2, 0
_08044498: .4byte 0x02023D12
_0804449C: .4byte 0x020243E8
_080444A0:
	add r0, sp, #4
	strb r1, [r0]
_080444A4:
	ldr r1, _080444E4
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #2
	strb r0, [r1, #1]
	strb r6, [r1, #2]
	lsrs r0, r6, #8
	strb r0, [r1, #3]
	movs r0, #0xff
	strb r0, [r1, #4]
	ldr r0, _080444E8
	bl BattleScriptExecute
	mov r1, sl
	adds r1, #9
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	add r5, sp, #4
	str r5, [sp]
	movs r0, #0
	movs r2, #0
	movs r3, #1
	bl BtlController_EmitSetMonData
	ldr r0, _080444EC
	ldrb r0, [r0]
	bl MarkBattlerForControllerExec
	movs r0, #3
	str r0, [sp, #0xc]
	bl _08044E1E
	.align 2, 0
_080444E4: .4byte 0x02022C0C
_080444E8: .4byte 0x08289D69
_080444EC: .4byte 0x02023D08
_080444F0:
	ldr r0, _08044544
	movs r1, #0x58
	muls r1, r7, r1
	adds r0, #0x18
	adds r1, r1, r0
	movs r2, #6
	movs r3, #7
	mov sl, r3
_08044500:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _0804450E
	strb r2, [r1]
	movs r5, #5
	str r5, [sp, #0xc]
_0804450E:
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r3, sl
	cmp r3, #0
	bge _08044500
	movs r5, #8
	mov sl, r5
	ldr r0, [sp, #0xc]
	cmp r0, #0
	bne _0804452A
	bl _0804546A
_0804452A:
	ldr r0, _08044548
	strb r7, [r0, #0x17]
	ldr r0, _0804454C
	strb r7, [r0]
	ldr r1, _08044550
	ldr r0, _08044554
	strb r7, [r0]
	strb r7, [r1]
	ldr r0, _08044558
	bl BattleScriptExecute
	bl _08044E16
	.align 2, 0
_08044544: .4byte 0x02023D28
_08044548: .4byte 0x02024118
_0804454C: .4byte 0x02023EB3
_08044550: .4byte 0x02023D08
_08044554: .4byte 0x02023EAF
_08044558: .4byte 0x08289D36
_0804455C:
	movs r0, #0x58
	muls r0, r7, r0
	mov r2, r8
	adds r1, r0, r2
	ldrh r0, [r1, #0x28]
	ldrh r3, [r1, #0x2c]
	cmp r0, r3
	blo _08044570
	bl _08044E16
_08044570:
	cmp r6, #0
	beq _08044578
	bl _08044E16
_08044578:
	ldr r3, _080445B4
	ldrh r0, [r1, #0x2c]
	lsrs r0, r0, #4
	str r0, [r3]
	cmp r0, #0
	bne _08044588
	movs r0, #1
	str r0, [r3]
_08044588:
	ldrh r2, [r1, #0x28]
	ldr r0, [r3]
	adds r0, r2, r0
	ldrh r1, [r1, #0x2c]
	cmp r0, r1
	ble _08044598
	subs r0, r1, r2
	str r0, [r3]
_08044598:
	ldr r0, [r3]
	rsbs r0, r0, #0
	str r0, [r3]
	ldr r0, _080445B8
	bl BattleScriptExecute
	movs r0, #4
	str r0, [sp, #0xc]
	adds r0, r7, #0
	adds r1, r5, #0
	bl RecordItemEffectBattle
	bl _08044E16
	.align 2, 0
_080445B4: .4byte 0x02023E94
_080445B8: .4byte 0x08289D79
_080445BC:
	movs r0, #0x58
	adds r1, r7, #0
	muls r1, r0, r1
	str r1, [sp, #0x18]
	adds r4, r1, #0
	add r4, r8
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x28]
	lsrs r0, r0, #1
	cmp r1, r0
	bls _080445D6
	bl _08044E16
_080445D6:
	cmp r6, #0
	beq _080445DE
	bl _08044E16
_080445DE:
	ldr r1, _08044634
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #8
	strb r0, [r1, #1]
	strb r6, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r5, _08044638
	ldrh r0, [r4, #0x2c]
	mov r1, sb
	bl __divsi3
	str r0, [r5]
	cmp r0, #0
	bne _08044602
	movs r0, #1
	str r0, [r5]
_08044602:
	ldrh r2, [r4, #0x28]
	ldr r0, [r5]
	adds r0, r2, r0
	ldrh r1, [r4, #0x2c]
	cmp r0, r1
	ble _08044612
	subs r0, r1, r2
	str r0, [r5]
_08044612:
	ldr r0, [r5]
	rsbs r0, r0, #0
	str r0, [r5]
	mov r0, r8
	adds r0, #0x48
	ldr r2, [sp, #0x18]
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, #0
	bl sub_0806E30C
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _08044630
	b _080447BC
_08044630:
	b _080447D0
	.align 2, 0
_08044634: .4byte 0x02022C0C
_08044638: .4byte 0x02023E94
_0804463C:
	movs r0, #0x58
	adds r5, r7, #0
	muls r5, r0, r5
	str r5, [sp, #0x1c]
	add r5, r8
	ldrh r0, [r5, #0x2c]
	ldrh r1, [r5, #0x28]
	lsrs r0, r0, #1
	cmp r1, r0
	bls _08044654
	bl _08044E16
_08044654:
	cmp r6, #0
	beq _0804465C
	bl _08044E16
_0804465C:
	ldr r1, _080446B0
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #8
	strb r0, [r1, #1]
	movs r6, #1
	strb r6, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r4, _080446B4
	ldrh r0, [r5, #0x2c]
	mov r1, sb
	bl __divsi3
	str r0, [r4]
	cmp r0, #0
	bne _08044680
	str r6, [r4]
_08044680:
	ldrh r2, [r5, #0x28]
	ldr r0, [r4]
	adds r0, r2, r0
	ldrh r1, [r5, #0x2c]
	cmp r0, r1
	ble _08044690
	subs r0, r1, r2
	str r0, [r4]
_08044690:
	ldr r0, [r4]
	rsbs r0, r0, #0
	str r0, [r4]
	mov r0, r8
	adds r0, #0x48
	ldr r1, [sp, #0x1c]
	adds r0, r1, r0
	ldr r0, [r0]
	movs r1, #1
	bl sub_0806E30C
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080446AE
	b _0804484E
_080446AE:
	b _08044864
	.align 2, 0
_080446B0: .4byte 0x02022C0C
_080446B4: .4byte 0x02023E94
_080446B8:
	movs r0, #0x58
	adds r3, r7, #0
	muls r3, r0, r3
	str r3, [sp, #0x20]
	adds r5, r3, #0
	add r5, r8
	ldrh r0, [r5, #0x2c]
	ldrh r1, [r5, #0x28]
	lsrs r0, r0, #1
	cmp r1, r0
	bls _080446D0
	b _08044E16
_080446D0:
	cmp r6, #0
	beq _080446D6
	b _08044E16
_080446D6:
	ldr r1, _08044730
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #8
	strb r0, [r1, #1]
	movs r0, #2
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r4, _08044734
	ldrh r0, [r5, #0x2c]
	mov r1, sb
	bl __divsi3
	str r0, [r4]
	cmp r0, #0
	bne _080446FC
	movs r0, #1
	str r0, [r4]
_080446FC:
	ldrh r2, [r5, #0x28]
	ldr r0, [r4]
	adds r0, r2, r0
	ldrh r1, [r5, #0x2c]
	cmp r0, r1
	ble _0804470C
	subs r0, r1, r2
	str r0, [r4]
_0804470C:
	ldr r0, [r4]
	rsbs r0, r0, #0
	str r0, [r4]
	mov r0, r8
	adds r0, #0x48
	ldr r5, [sp, #0x20]
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, #2
	bl sub_0806E30C
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _0804473C
	ldr r0, _08044738
	bl BattleScriptExecute
	b _08044742
	.align 2, 0
_08044730: .4byte 0x02022C0C
_08044734: .4byte 0x02023E94
_08044738: .4byte 0x08289DAC
_0804473C:
	ldr r0, _08044748
	bl BattleScriptExecute
_08044742:
	movs r0, #4
	str r0, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044748: .4byte 0x08289D4C
_0804474C:
	movs r0, #0x58
	adds r1, r7, #0
	muls r1, r0, r1
	str r1, [sp, #0x24]
	adds r5, r1, #0
	add r5, r8
	ldrh r0, [r5, #0x2c]
	ldrh r1, [r5, #0x28]
	lsrs r0, r0, #1
	cmp r1, r0
	bls _08044764
	b _08044E16
_08044764:
	cmp r6, #0
	beq _0804476A
	b _08044E16
_0804476A:
	ldr r1, _080447C4
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #8
	strb r0, [r1, #1]
	movs r0, #3
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r4, _080447C8
	ldrh r0, [r5, #0x2c]
	mov r1, sb
	bl __divsi3
	str r0, [r4]
	cmp r0, #0
	bne _08044790
	movs r0, #1
	str r0, [r4]
_08044790:
	ldrh r2, [r5, #0x28]
	ldr r0, [r4]
	adds r0, r2, r0
	ldrh r1, [r5, #0x2c]
	cmp r0, r1
	ble _080447A0
	subs r0, r1, r2
	str r0, [r4]
_080447A0:
	ldr r0, [r4]
	rsbs r0, r0, #0
	str r0, [r4]
	mov r0, r8
	adds r0, #0x48
	ldr r2, [sp, #0x24]
	adds r0, r2, r0
	ldr r0, [r0]
	movs r1, #3
	bl sub_0806E30C
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080447D0
_080447BC:
	ldr r0, _080447CC
	bl BattleScriptExecute
	b _080447D6
	.align 2, 0
_080447C4: .4byte 0x02022C0C
_080447C8: .4byte 0x02023E94
_080447CC: .4byte 0x08289DAC
_080447D0:
	ldr r0, _080447DC
	bl BattleScriptExecute
_080447D6:
	movs r3, #4
	str r3, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_080447DC: .4byte 0x08289D4C
_080447E0:
	movs r0, #0x58
	adds r5, r7, #0
	muls r5, r0, r5
	str r5, [sp, #0x28]
	add r5, r8
	ldrh r0, [r5, #0x2c]
	ldrh r1, [r5, #0x28]
	lsrs r0, r0, #1
	cmp r1, r0
	bls _080447F6
	b _08044E16
_080447F6:
	cmp r6, #0
	beq _080447FC
	b _08044E16
_080447FC:
	ldr r1, _08044858
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #8
	strb r0, [r1, #1]
	movs r0, #4
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r4, _0804485C
	ldrh r0, [r5, #0x2c]
	mov r1, sb
	bl __divsi3
	str r0, [r4]
	cmp r0, #0
	bne _08044822
	movs r0, #1
	str r0, [r4]
_08044822:
	ldrh r2, [r5, #0x28]
	ldr r0, [r4]
	adds r0, r2, r0
	ldrh r1, [r5, #0x2c]
	cmp r0, r1
	ble _08044832
	subs r0, r1, r2
	str r0, [r4]
_08044832:
	ldr r0, [r4]
	rsbs r0, r0, #0
	str r0, [r4]
	mov r0, r8
	adds r0, #0x48
	ldr r1, [sp, #0x28]
	adds r0, r1, r0
	ldr r0, [r0]
	movs r1, #4
	bl sub_0806E30C
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _08044864
_0804484E:
	ldr r0, _08044860
	bl BattleScriptExecute
	b _0804486A
	.align 2, 0
_08044858: .4byte 0x02022C0C
_0804485C: .4byte 0x02023E94
_08044860: .4byte 0x08289DAC
_08044864:
	ldr r0, _08044870
	bl BattleScriptExecute
_0804486A:
	movs r2, #4
	str r2, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044870: .4byte 0x08289D4C
_08044874:
	movs r0, #0x58
	muls r0, r7, r0
	mov r3, r8
	adds r5, r0, r3
	ldrh r4, [r5, #0x28]
	ldrh r0, [r5, #0x2c]
	mov r1, sb
	bl __divsi3
	cmp r4, r0
	ble _0804488C
	b _08044E16
_0804488C:
	cmp r6, #0
	beq _08044892
	b _08044E16
_08044892:
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	cmp r0, #0xb
	ble _0804489C
	b _08044E16
_0804489C:
	ldr r1, _080448CC
	movs r2, #0xfd
	strb r2, [r1]
	movs r0, #5
	strb r0, [r1, #1]
	movs r0, #1
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r1, _080448D0
	strb r2, [r1]
	strb r6, [r1, #1]
	movs r0, #0xd2
	strb r0, [r1, #2]
	strb r6, [r1, #3]
	subs r0, #0xd3
	strb r0, [r1, #4]
	ldr r0, _080448D4
	strb r7, [r0]
	ldr r1, _080448D8
	movs r0, #0x11
	strb r0, [r1, #0x1a]
	movs r0, #0xf
	b _08044A30
	.align 2, 0
_080448CC: .4byte 0x02022C0C
_080448D0: .4byte 0x02022C1C
_080448D4: .4byte 0x02023EB2
_080448D8: .4byte 0x02024118
_080448DC:
	movs r0, #0x58
	muls r0, r7, r0
	mov r1, r8
	adds r5, r0, r1
	ldrh r4, [r5, #0x28]
	ldrh r0, [r5, #0x2c]
	mov r1, sb
	bl __divsi3
	cmp r4, r0
	ble _080448F4
	b _08044E16
_080448F4:
	cmp r6, #0
	beq _080448FA
	b _08044E16
_080448FA:
	movs r0, #0x1a
	ldrsb r0, [r5, r0]
	cmp r0, #0xb
	ble _08044904
	b _08044E16
_08044904:
	ldr r1, _08044924
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #5
	strb r0, [r1, #1]
	movs r0, #2
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r0, _08044928
	strb r7, [r0]
	ldr r1, _0804492C
	movs r0, #0x12
	strb r0, [r1, #0x1a]
	movs r0, #0x10
	b _080449CA
	.align 2, 0
_08044924: .4byte 0x02022C0C
_08044928: .4byte 0x02023EB2
_0804492C: .4byte 0x02024118
_08044930:
	movs r0, #0x58
	muls r0, r7, r0
	mov r3, r8
	adds r5, r0, r3
	ldrh r4, [r5, #0x28]
	ldrh r0, [r5, #0x2c]
	mov r1, sb
	bl __divsi3
	cmp r4, r0
	ble _08044948
	b _08044E16
_08044948:
	cmp r6, #0
	beq _0804494E
	b _08044E16
_0804494E:
	movs r0, #0x1b
	ldrsb r0, [r5, r0]
	cmp r0, #0xb
	ble _08044958
	b _08044E16
_08044958:
	ldr r1, _08044978
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #5
	strb r0, [r1, #1]
	movs r0, #3
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r0, _0804497C
	strb r7, [r0]
	ldr r1, _08044980
	movs r0, #0x13
	strb r0, [r1, #0x1a]
	movs r0, #0x11
	b _08044A30
	.align 2, 0
_08044978: .4byte 0x02022C0C
_0804497C: .4byte 0x02023EB2
_08044980: .4byte 0x02024118
_08044984:
	movs r0, #0x58
	muls r0, r7, r0
	mov r1, r8
	adds r5, r0, r1
	ldrh r4, [r5, #0x28]
	ldrh r0, [r5, #0x2c]
	mov r1, sb
	bl __divsi3
	cmp r4, r0
	ble _0804499C
	b _08044E16
_0804499C:
	cmp r6, #0
	beq _080449A2
	b _08044E16
_080449A2:
	movs r0, #0x1c
	ldrsb r0, [r5, r0]
	cmp r0, #0xb
	ble _080449AC
	b _08044E16
_080449AC:
	ldr r1, _080449DC
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #5
	strb r0, [r1, #1]
	movs r0, #4
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r0, _080449E0
	strb r7, [r0]
	ldr r1, _080449E4
	movs r0, #0x14
	strb r0, [r1, #0x1a]
	movs r0, #0x12
_080449CA:
	strb r0, [r1, #0x10]
	strb r6, [r1, #0x11]
	ldr r0, _080449E8
	bl BattleScriptExecute
	movs r2, #5
	str r2, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_080449DC: .4byte 0x02022C0C
_080449E0: .4byte 0x02023EB2
_080449E4: .4byte 0x02024118
_080449E8: .4byte 0x08289DD6
_080449EC:
	movs r0, #0x58
	muls r0, r7, r0
	mov r3, r8
	adds r5, r0, r3
	ldrh r4, [r5, #0x28]
	ldrh r0, [r5, #0x2c]
	mov r1, sb
	bl __divsi3
	cmp r4, r0
	ble _08044A04
	b _08044E16
_08044A04:
	cmp r6, #0
	beq _08044A0A
	b _08044E16
_08044A0A:
	movs r0, #0x1d
	ldrsb r0, [r5, r0]
	cmp r0, #0xb
	ble _08044A14
	b _08044E16
_08044A14:
	ldr r1, _08044A40
	movs r0, #0xfd
	strb r0, [r1]
	movs r0, #5
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r0, _08044A44
	strb r7, [r0]
	ldr r1, _08044A48
	movs r0, #0x15
	strb r0, [r1, #0x1a]
	movs r0, #0x13
_08044A30:
	strb r0, [r1, #0x10]
	strb r6, [r1, #0x11]
	ldr r0, _08044A4C
	bl BattleScriptExecute
	movs r5, #5
	str r5, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044A40: .4byte 0x02022C0C
_08044A44: .4byte 0x02023EB2
_08044A48: .4byte 0x02024118
_08044A4C: .4byte 0x08289DD6
_08044A50:
	movs r0, #0x58
	adds r5, r7, #0
	muls r5, r0, r5
	mov r1, r8
	adds r0, r5, r1
	ldrh r4, [r0, #0x28]
	ldrh r0, [r0, #0x2c]
	mov r1, sb
	bl __divsi3
	cmp r4, r0
	ble _08044A6A
	b _08044E16
_08044A6A:
	cmp r6, #0
	beq _08044A70
	b _08044E16
_08044A70:
	mov r0, r8
	adds r0, #0x50
	adds r1, r5, r0
	ldr r2, [r1]
	movs r3, #0x80
	lsls r3, r3, #0xd
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq _08044A86
	b _08044E16
_08044A86:
	orrs r2, r3
	str r2, [r1]
	ldr r0, _08044A98
	bl BattleScriptExecute
	movs r2, #2
	str r2, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044A98: .4byte 0x08289DF1
_08044A9C:
	cmp r6, #0
	beq _08044AA2
	b _08044E16
_08044AA2:
	movs r0, #0x58
	adds r5, r7, #0
	muls r5, r0, r5
	mov r3, r8
	adds r0, r5, r3
	ldrh r4, [r0, #0x28]
	ldrh r0, [r0, #0x2c]
	mov r1, sb
	bl __divsi3
	cmp r4, r0
	ble _08044ABC
	b _08044E16
_08044ABC:
	movs r0, #0
	mov sl, r0
	adds r0, r5, #1
	mov r1, r8
	adds r1, #0x18
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xb
	ble _08044AEC
	mov r0, r8
	adds r0, #0x19
	adds r1, r5, r0
_08044AD8:
	adds r1, #1
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #4
	bgt _08044AEC
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0xb
	bgt _08044AD8
_08044AEC:
	mov r5, sl
	cmp r5, #5
	bne _08044AF4
	b _08044E16
_08044AF4:
	movs r0, #0x58
	muls r0, r7, r0
	adds r4, r0, #1
	ldr r5, _08044B6C
_08044AFC:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #5
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	adds r0, r0, r4
	adds r0, r0, r5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0xc
	beq _08044AFC
	ldr r1, _08044B70
	movs r2, #0
	movs r3, #0xfd
	strb r3, [r1]
	movs r0, #5
	strb r0, [r1, #1]
	mov r0, sl
	adds r0, #1
	strb r0, [r1, #2]
	movs r0, #0xff
	strb r0, [r1, #3]
	ldr r0, _08044B74
	strb r3, [r0]
	strb r2, [r0, #1]
	movs r1, #0xd1
	strb r1, [r0, #2]
	strb r2, [r0, #3]
	strb r2, [r0, #4]
	movs r1, #0xd2
	strb r1, [r0, #5]
	strb r2, [r0, #6]
	subs r1, #0xd3
	strb r1, [r0, #7]
	ldr r0, _08044B78
	strb r7, [r0]
	ldr r1, _08044B7C
	mov r0, sl
	adds r0, #0x21
	strb r0, [r1, #0x1a]
	adds r0, #6
	strb r0, [r1, #0x10]
	strb r2, [r1, #0x11]
	ldr r0, _08044B80
	bl BattleScriptExecute
	movs r0, #5
	str r0, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044B6C: .4byte 0x02023D40
_08044B70: .4byte 0x02022C0C
_08044B74: .4byte 0x02022C1C
_08044B78: .4byte 0x02023EB2
_08044B7C: .4byte 0x02024118
_08044B80: .4byte 0x08289DD6
_08044B84:
	movs r0, #0x58
	adds r1, r7, #0
	muls r1, r0, r1
	mov r0, r8
	adds r0, #0x4c
	adds r1, r1, r0
	ldr r2, [r1]
	movs r0, #0x40
	ands r0, r2
	cmp r0, #0
	bne _08044B9C
	b _08044E16
_08044B9C:
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r1]
	ldr r0, _08044BB0
	bl BattleScriptExecute
	movs r1, #1
	str r1, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044BB0: .4byte 0x08289C8E
_08044BB4:
	movs r0, #0x58
	adds r1, r7, #0
	muls r1, r0, r1
	mov r0, r8
	adds r0, #0x4c
	adds r1, r1, r0
	ldr r2, [r1]
	movs r0, #0x88
	ands r0, r2
	cmp r0, #0
	bne _08044BCC
	b _08044E16
_08044BCC:
	ldr r0, _08044BE0
	ands r2, r0
	str r2, [r1]
	ldr r0, _08044BE4
	bl BattleScriptExecute
	movs r2, #1
	str r2, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044BE0: .4byte 0xFFFFF077
_08044BE4: .4byte 0x08289CA6
_08044BE8:
	movs r0, #0x58
	adds r1, r7, #0
	muls r1, r0, r1
	mov r0, r8
	adds r0, #0x4c
	adds r1, r1, r0
	ldr r2, [r1]
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	bne _08044C00
	b _08044E16
_08044C00:
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r1]
	ldr r0, _08044C14
	bl BattleScriptExecute
	movs r3, #1
	str r3, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044C14: .4byte 0x08289CBE
_08044C18:
	movs r0, #0x58
	adds r1, r7, #0
	muls r1, r0, r1
	mov r0, r8
	adds r0, #0x4c
	adds r1, r1, r0
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _08044C30
	b _08044E16
_08044C30:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r1]
	ldr r0, _08044C44
	bl BattleScriptExecute
	movs r5, #1
	str r5, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044C44: .4byte 0x08289CD6
_08044C48:
	movs r0, #0x58
	adds r3, r7, #0
	muls r3, r0, r3
	mov r0, r8
	adds r0, #0x4c
	adds r2, r3, r0
	ldr r1, [r2]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _08044C60
	b _08044E16
_08044C60:
	movs r0, #8
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	mov r1, r8
	adds r1, #0x50
	adds r1, r3, r1
	ldr r0, [r1]
	ldr r2, _08044C7C
	ands r0, r2
	str r0, [r1]
	ldr r0, _08044C80
	b _08044DCA
	.align 2, 0
_08044C7C: .4byte 0xF7FFFFFF
_08044C80: .4byte 0x08289CEE
_08044C84:
	movs r0, #0x58
	adds r1, r7, #0
	muls r1, r0, r1
	mov r0, r8
	adds r0, #0x50
	adds r1, r1, r0
	ldr r2, [r1]
	movs r0, #7
	ands r0, r2
	cmp r0, #0
	bne _08044C9C
	b _08044E16
_08044C9C:
	movs r0, #8
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r1]
	ldr r0, _08044CB0
	bl BattleScriptExecute
	movs r1, #2
	str r1, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044CB0: .4byte 0x08289D06
_08044CB4:
	movs r0, #0x58
	adds r5, r7, #0
	muls r5, r0, r5
	mov r0, r8
	adds r0, #0x4c
	adds r4, r5, r0
	ldr r2, [r4]
	ldrb r0, [r4]
	cmp r0, #0
	bne _08044CDA
	mov r0, r8
	adds r0, #0x50
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08044CDA
	b _08044E16
_08044CDA:
	movs r3, #0
	mov sl, r3
	movs r0, #0x88
	ands r2, r0
	cmp r2, #0
	beq _08044CF2
	ldr r0, _08044D80
	ldr r1, _08044D84
	bl StringCopy
	movs r0, #1
	mov sl, r0
_08044CF2:
	ldr r0, [r4]
	movs r1, #7
	mov sb, r1
	ands r0, r1
	mov r6, r8
	adds r6, #0x50
	cmp r0, #0
	beq _08044D18
	adds r2, r5, r6
	ldr r0, [r2]
	ldr r1, _08044D88
	ands r0, r1
	str r0, [r2]
	ldr r0, _08044D80
	ldr r1, _08044D8C
	bl StringCopy
	movs r2, #1
	add sl, r2
_08044D18:
	ldr r0, [r4]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _08044D2E
	ldr r0, _08044D80
	ldr r1, _08044D90
	bl StringCopy
	movs r3, #1
	add sl, r3
_08044D2E:
	ldr r0, [r4]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08044D44
	ldr r0, _08044D80
	ldr r1, _08044D94
	bl StringCopy
	movs r0, #1
	add sl, r0
_08044D44:
	ldr r0, [r4]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08044D5A
	ldr r0, _08044D80
	ldr r1, _08044D98
	bl StringCopy
	movs r1, #1
	add sl, r1
_08044D5A:
	adds r0, r5, r6
	ldr r0, [r0]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _08044D72
	ldr r0, _08044D80
	ldr r1, _08044D9C
	bl StringCopy
	movs r3, #1
	add sl, r3
_08044D72:
	mov r5, sl
	cmp r5, #1
	bgt _08044DA4
	ldr r1, _08044DA0
	movs r0, #0
	b _08044DA8
	.align 2, 0
_08044D80: .4byte 0x02022C0C
_08044D84: .4byte 0x085ABC54
_08044D88: .4byte 0xF7FFFFFF
_08044D8C: .4byte 0x085ABC50
_08044D90: .4byte 0x085ABC5B
_08044D94: .4byte 0x085ABC57
_08044D98: .4byte 0x085ABC5E
_08044D9C: .4byte 0x085ABC62
_08044DA0: .4byte 0x02023FD6
_08044DA4:
	ldr r1, _08044DD4
	movs r0, #1
_08044DA8:
	strb r0, [r1, #5]
	ldr r2, _08044DD8
	movs r0, #0x58
	adds r3, r7, #0
	muls r3, r0, r3
	adds r0, r2, #0
	adds r0, #0x4c
	adds r0, r3, r0
	movs r1, #0
	str r1, [r0]
	adds r2, #0x50
	adds r3, r3, r2
	ldr r0, [r3]
	subs r1, #8
	ands r0, r1
	str r0, [r3]
	ldr r0, _08044DDC
_08044DCA:
	bl BattleScriptExecute
	movs r0, #1
	str r0, [sp, #0xc]
	b _08044E1E
	.align 2, 0
_08044DD4: .4byte 0x02023FD6
_08044DD8: .4byte 0x02023D28
_08044DDC: .4byte 0x08289D1C
_08044DE0:
	movs r0, #0x58
	adds r1, r7, #0
	muls r1, r0, r1
	mov r0, r8
	adds r0, #0x50
	adds r1, r1, r0
	ldr r2, [r1]
	movs r0, #0xf0
	lsls r0, r0, #0xc
	ands r0, r2
	cmp r0, #0
	beq _08044E16
	ldr r0, _08044E3C
	ands r2, r0
	str r2, [r1]
	ldr r0, _08044E40
	ldr r1, _08044E44
	bl StringCopy
	ldr r0, _08044E48
	bl BattleScriptExecute
	ldr r1, _08044E4C
	movs r0, #0
	strb r0, [r1, #5]
	movs r1, #2
	str r1, [sp, #0xc]
_08044E16:
	ldr r2, [sp, #0xc]
	cmp r2, #0
	bne _08044E1E
	b _0804546A
_08044E1E:
	ldr r0, _08044E50
	strb r7, [r0, #0x17]
	ldr r0, _08044E54
	strb r7, [r0]
	ldr r4, _08044E58
	ldr r0, _08044E5C
	strb r7, [r0]
	strb r7, [r4]
	ldr r3, [sp, #0xc]
	cmp r3, #1
	beq _08044E60
	cmp r3, #3
	beq _08044E66
	b _0804546A
	.align 2, 0
_08044E3C: .4byte 0xFFF0FFFF
_08044E40: .4byte 0x02022C0C
_08044E44: .4byte 0x085ABC67
_08044E48: .4byte 0x08289D1C
_08044E4C: .4byte 0x02023FD6
_08044E50: .4byte 0x02024118
_08044E54: .4byte 0x02023EB3
_08044E58: .4byte 0x02023D08
_08044E5C: .4byte 0x02023EAF
_08044E60:
	movs r0, #0x58
	muls r0, r7, r0
	b _080452CC
_08044E66:
	ldr r4, _08044EB4
	movs r0, #0x58
	adds r3, r7, #0
	muls r3, r0, r3
	adds r0, r4, #0
	adds r0, #0x50
	adds r0, r3, r0
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xe
	ands r0, r1
	cmp r0, #0
	beq _08044E82
	b _0804546A
_08044E82:
	ldr r1, _08044EB8
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r1, [r0, #0x18]
	lsrs r1, r1, #4
	ldr r2, _08044EBC
	mov r5, sl
	lsls r0, r5, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r1, r0
	cmp r1, #0
	beq _08044EA2
	b _0804546A
_08044EA2:
	adds r1, r5, r3
	adds r0, r4, #0
	adds r0, #0x24
	adds r1, r1, r0
	add r0, sp, #4
	ldrb r0, [r0]
	strb r0, [r1]
	b _0804546A
	.align 2, 0
_08044EB4: .4byte 0x02023D28
_08044EB8: .4byte 0x02023F60
_08044EBC: .4byte 0x082FACB4
_08044EC0:
	movs r7, #0
	ldr r0, _08044EF0
	ldrb r0, [r0]
	cmp r7, r0
	blo _08044ECC
	b _0804546A
_08044ECC:
	ldr r4, _08044EF4
	ldr r1, _08044EF8
	movs r0, #0x58
	muls r0, r7, r0
	adds r0, r0, r1
	ldrh r0, [r0, #0x2e]
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xaf
	bne _08044F00
	ldr r1, _08044EFC
	lsls r0, r7, #3
	subs r0, r0, r7
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r5, [r0, #7]
	b _08044F10
	.align 2, 0
_08044EF0: .4byte 0x02023D10
_08044EF4: .4byte 0x02023EAC
_08044EF8: .4byte 0x02023D28
_08044EFC: .4byte 0x020240A8
_08044F00:
	ldrh r0, [r4]
	bl sub_080D6CF8
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrh r0, [r4]
	bl sub_080D6D1C
_08044F10:
	subs r0, r5, #2
	cmp r0, #0x1a
	bls _08044F18
	b _080452B4
_08044F18:
	lsls r0, r0, #2
	ldr r1, _08044F24
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08044F24: .4byte 0x08044F28
_08044F28: @ jump table
	.4byte _08044F94 @ case 0
	.4byte _08045084 @ case 1
	.4byte _08044FD0 @ case 2
	.4byte _0804500C @ case 3
	.4byte _08045048 @ case 4
	.4byte _080452B4 @ case 5
	.4byte _080450CC @ case 6
	.4byte _08045160 @ case 7
	.4byte _080452B4 @ case 8
	.4byte _080452B4 @ case 9
	.4byte _080452B4 @ case 10
	.4byte _080452B4 @ case 11
	.4byte _080452B4 @ case 12
	.4byte _080452B4 @ case 13
	.4byte _080452B4 @ case 14
	.4byte _080452B4 @ case 15
	.4byte _080452B4 @ case 16
	.4byte _080452B4 @ case 17
	.4byte _080452B4 @ case 18
	.4byte _080452B4 @ case 19
	.4byte _080452B4 @ case 20
	.4byte _08045254 @ case 21
	.4byte _080452B4 @ case 22
	.4byte _080452B4 @ case 23
	.4byte _080452B4 @ case 24
	.4byte _080452B4 @ case 25
	.4byte _08045108 @ case 26
_08044F94:
	ldr r1, _08044FC4
	movs r0, #0x58
	muls r0, r7, r0
	adds r1, #0x4c
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	bne _08044FAA
	b _080452B4
_08044FAA:
	movs r0, #0x41
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	bl BattleScriptPushCursor
	ldr r1, _08044FC8
	ldr r0, _08044FCC
	str r0, [r1]
	movs r0, #1
	str r0, [sp, #0xc]
	b _080452BA
	.align 2, 0
_08044FC4: .4byte 0x02023D28
_08044FC8: .4byte 0x02023EB8
_08044FCC: .4byte 0x08289C94
_08044FD0:
	ldr r1, _08044FFC
	movs r0, #0x58
	muls r0, r7, r0
	adds r1, #0x4c
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #0x88
	ands r0, r1
	cmp r0, #0
	bne _08044FE6
	b _080452B4
_08044FE6:
	ldr r0, _08045000
	ands r1, r0
	str r1, [r2]
	bl BattleScriptPushCursor
	ldr r1, _08045004
	ldr r0, _08045008
	str r0, [r1]
	movs r1, #1
	str r1, [sp, #0xc]
	b _080452BA
	.align 2, 0
_08044FFC: .4byte 0x02023D28
_08045000: .4byte 0xFFFFF077
_08045004: .4byte 0x02023EB8
_08045008: .4byte 0x08289CAC
_0804500C:
	ldr r1, _0804503C
	movs r0, #0x58
	muls r0, r7, r0
	adds r1, #0x4c
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	bne _08045022
	b _080452B4
_08045022:
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	bl BattleScriptPushCursor
	ldr r1, _08045040
	ldr r0, _08045044
	str r0, [r1]
	movs r2, #1
	str r2, [sp, #0xc]
	b _080452BA
	.align 2, 0
_0804503C: .4byte 0x02023D28
_08045040: .4byte 0x02023EB8
_08045044: .4byte 0x08289CC4
_08045048:
	ldr r1, _08045078
	movs r0, #0x58
	muls r0, r7, r0
	adds r1, #0x4c
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _0804505E
	b _080452B4
_0804505E:
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	bl BattleScriptPushCursor
	ldr r1, _0804507C
	ldr r0, _08045080
	str r0, [r1]
	movs r3, #1
	str r3, [sp, #0xc]
	b _080452BA
	.align 2, 0
_08045078: .4byte 0x02023D28
_0804507C: .4byte 0x02023EB8
_08045080: .4byte 0x08289CDC
_08045084:
	ldr r2, _080450BC
	movs r0, #0x58
	adds r4, r7, #0
	muls r4, r0, r4
	adds r0, r2, #0
	adds r0, #0x4c
	adds r3, r4, r0
	ldr r1, [r3]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _0804509E
	b _080452B4
_0804509E:
	movs r0, #8
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r3]
	adds r2, #0x50
	adds r2, r4, r2
	ldr r0, [r2]
	ldr r1, _080450C0
	ands r0, r1
	str r0, [r2]
	bl BattleScriptPushCursor
	ldr r1, _080450C4
	ldr r0, _080450C8
	b _0804521C
	.align 2, 0
_080450BC: .4byte 0x02023D28
_080450C0: .4byte 0xF7FFFFFF
_080450C4: .4byte 0x02023EB8
_080450C8: .4byte 0x08289CF4
_080450CC:
	ldr r1, _080450FC
	movs r0, #0x58
	muls r0, r7, r0
	adds r1, #0x50
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080450E2
	b _080452B4
_080450E2:
	movs r0, #8
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r2]
	bl BattleScriptPushCursor
	ldr r1, _08045100
	ldr r0, _08045104
	str r0, [r1]
	movs r0, #2
	str r0, [sp, #0xc]
	b _080452BA
	.align 2, 0
_080450FC: .4byte 0x02023D28
_08045100: .4byte 0x02023EB8
_08045104: .4byte 0x08289D0C
_08045108:
	ldr r1, _08045144
	movs r0, #0x58
	muls r0, r7, r0
	adds r1, #0x50
	adds r2, r0, r1
	ldr r1, [r2]
	movs r0, #0xf0
	lsls r0, r0, #0xc
	ands r0, r1
	cmp r0, #0
	bne _08045120
	b _080452B4
_08045120:
	ldr r0, _08045148
	ands r1, r0
	str r1, [r2]
	ldr r0, _0804514C
	ldr r1, _08045150
	bl StringCopy
	bl BattleScriptPushCursor
	ldr r1, _08045154
	movs r0, #0
	strb r0, [r1, #5]
	ldr r1, _08045158
	ldr r0, _0804515C
	str r0, [r1]
	movs r1, #2
	str r1, [sp, #0xc]
	b _080452BA
	.align 2, 0
_08045144: .4byte 0x02023D28
_08045148: .4byte 0xFFF0FFFF
_0804514C: .4byte 0x02022C0C
_08045150: .4byte 0x085ABC67
_08045154: .4byte 0x02023FD6
_08045158: .4byte 0x02023EB8
_0804515C: .4byte 0x08289D22
_08045160:
	ldr r4, _08045224
	movs r0, #0x58
	adds r5, r7, #0
	muls r5, r0, r5
	adds r0, r4, #0
	adds r0, #0x4c
	adds r6, r5, r0
	ldr r2, [r6]
	ldrb r0, [r6]
	cmp r0, #0
	bne _08045188
	adds r0, r4, #0
	adds r0, #0x50
	adds r0, r5, r0
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _08045188
	b _080452B4
_08045188:
	movs r0, #0x88
	ands r2, r0
	cmp r2, #0
	beq _08045198
	ldr r0, _08045228
	ldr r1, _0804522C
	bl StringCopy
_08045198:
	ldr r0, [r6]
	movs r2, #7
	mov r8, r2
	ands r0, r2
	adds r4, #0x50
	cmp r0, #0
	beq _080451B8
	adds r2, r5, r4
	ldr r0, [r2]
	ldr r1, _08045230
	ands r0, r1
	str r0, [r2]
	ldr r0, _08045228
	ldr r1, _08045234
	bl StringCopy
_080451B8:
	ldr r0, [r6]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080451CA
	ldr r0, _08045228
	ldr r1, _08045238
	bl StringCopy
_080451CA:
	ldr r0, [r6]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080451DC
	ldr r0, _08045228
	ldr r1, _0804523C
	bl StringCopy
_080451DC:
	ldr r0, [r6]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080451EE
	ldr r0, _08045228
	ldr r1, _08045240
	bl StringCopy
_080451EE:
	adds r5, r5, r4
	ldr r0, [r5]
	mov r3, r8
	ands r0, r3
	cmp r0, #0
	beq _08045202
	ldr r0, _08045228
	ldr r1, _08045244
	bl StringCopy
_08045202:
	movs r4, #0
	str r4, [r6]
	ldr r0, [r5]
	movs r1, #8
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	bl BattleScriptPushCursor
	ldr r0, _08045248
	strb r4, [r0, #5]
	ldr r1, _0804524C
	ldr r0, _08045250
_0804521C:
	str r0, [r1]
	movs r5, #1
	str r5, [sp, #0xc]
	b _080452BA
	.align 2, 0
_08045224: .4byte 0x02023D28
_08045228: .4byte 0x02022C0C
_0804522C: .4byte 0x085ABC54
_08045230: .4byte 0xF7FFFFFF
_08045234: .4byte 0x085ABC50
_08045238: .4byte 0x085ABC5B
_0804523C: .4byte 0x085ABC57
_08045240: .4byte 0x085ABC5E
_08045244: .4byte 0x085ABC62
_08045248: .4byte 0x02023FD6
_0804524C: .4byte 0x02023EB8
_08045250: .4byte 0x08289D22
_08045254:
	ldr r0, _080452A0
	mov r8, r0
	movs r0, #0x58
	adds r1, r7, #0
	muls r1, r0, r1
	mov r0, r8
	adds r0, #0x18
	adds r1, r1, r0
	movs r2, #6
	movs r3, #7
	mov sl, r3
_0804526A:
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #5
	bgt _08045278
	strb r2, [r1]
	movs r5, #5
	str r5, [sp, #0xc]
_08045278:
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	add sl, r0
	mov r3, sl
	cmp r3, #0
	bge _0804526A
	ldr r5, [sp, #0xc]
	cmp r5, #0
	beq _080452F8
	ldr r0, _080452A4
	strb r7, [r0, #0x17]
	ldr r0, _080452A8
	strb r7, [r0]
	bl BattleScriptPushCursor
	ldr r1, _080452AC
	ldr r0, _080452B0
	str r0, [r1]
	b _0804546A
	.align 2, 0
_080452A0: .4byte 0x02023D28
_080452A4: .4byte 0x02024118
_080452A8: .4byte 0x02023EB3
_080452AC: .4byte 0x02023EB8
_080452B0: .4byte 0x08289D3C
_080452B4:
	ldr r0, [sp, #0xc]
	cmp r0, #0
	beq _080452F8
_080452BA:
	ldr r0, _080452E8
	strb r7, [r0, #0x17]
	ldr r0, _080452EC
	strb r7, [r0]
	ldr r4, _080452F0
	strb r7, [r4]
	ldrb r1, [r4]
	movs r0, #0x58
	muls r0, r1, r0
_080452CC:
	ldr r1, _080452F4
	adds r0, r0, r1
	str r0, [sp]
	movs r0, #0
	movs r1, #0x28
	movs r2, #0
	movs r3, #4
	bl BtlController_EmitSetMonData
	ldrb r0, [r4]
	bl MarkBattlerForControllerExec
	b _0804546A
	.align 2, 0
_080452E8: .4byte 0x02024118
_080452EC: .4byte 0x02023EB3
_080452F0: .4byte 0x02023D08
_080452F4: .4byte 0x02023D74
_080452F8:
	adds r0, r7, #1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r0, _0804530C
	ldrb r0, [r0]
	cmp r7, r0
	bhs _08045308
	b _08044ECC
_08045308:
	b _0804546A
	.align 2, 0
_0804530C: .4byte 0x02023D10
_08045310:
	ldr r7, _08045328
	ldr r0, [r7]
	cmp r0, #0
	bne _0804531A
	b _0804546A
_0804531A:
	mov r1, r8
	cmp r1, #0x1e
	beq _0804532C
	cmp r1, #0x3e
	beq _080453D4
	b _0804546A
	.align 2, 0
_08045328: .4byte 0x02023E94
_0804532C:
	ldr r0, _080453B8
	ldrb r1, [r0]
	movs r0, #0x29
	ands r0, r1
	cmp r0, #0
	beq _0804533A
	b _0804546A
_0804533A:
	ldr r2, _080453BC
	ldr r4, _080453C0
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r1, r0, #2
	adds r0, r2, #0
	adds r0, #8
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08045360
	adds r0, r2, #0
	adds r0, #0xc
	adds r0, r1, r0
	ldr r0, [r0]
	cmp r0, #0
	bne _08045360
	b _0804546A
_08045360:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [sp, #0x10]
	cmp r0, r2
	bhs _0804546A
	ldr r2, _080453C4
	ldr r0, _080453C8
	ldrh r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldrb r1, [r0, #8]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0804546A
	ldr r2, _080453CC
	ldrb r1, [r4]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r0, [r0, #0x28]
	cmp r0, #0
	beq _0804546A
	ldr r1, _080453D0
	movs r0, #8
	strb r0, [r1, #3]
	bl BattleScriptPushCursor
	movs r0, #0
	movs r1, #0
	bl SetMoveEffect
	bl HandleAction_RunBattleScript
	b _0804546A
	.align 2, 0
_080453B8: .4byte 0x02023F20
_080453BC: .4byte 0x02024020
_080453C0: .4byte 0x02023EB0
_080453C4: .4byte 0x082ED220
_080453C8: .4byte 0x02023E8E
_080453CC: .4byte 0x02023D28
_080453D0: .4byte 0x02023FD6
_080453D4:
	ldr r0, _0804547C
	ldrb r0, [r0]
	movs r5, #0x29
	ands r5, r0
	cmp r5, #0
	bne _0804546A
	ldr r1, _08045480
	ldr r4, _08045484
	ldrb r2, [r4]
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #2
	adds r6, r1, #4
	adds r0, r0, r6
	ldr r1, [r0]
	cmp r1, #0
	beq _0804546A
	ldr r0, _08045488
	cmp r1, r0
	beq _0804546A
	ldr r0, _0804548C
	ldrb r3, [r0]
	cmp r3, r2
	beq _0804546A
	ldr r2, _08045490
	ldrb r1, [r0]
	movs r0, #0x58
	muls r0, r1, r0
	adds r0, r0, r2
	ldrh r1, [r0, #0x28]
	ldrh r0, [r0, #0x2c]
	cmp r1, r0
	beq _0804546A
	cmp r1, #0
	beq _0804546A
	ldr r0, _08045494
	mov r1, sp
	ldrh r1, [r1, #0x14]
	strh r1, [r0]
	ldr r0, _08045498
	strb r3, [r0]
	ldr r0, _0804549C
	strb r3, [r0, #0x17]
	ldrb r1, [r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r0, [r0]
	ldr r1, [sp, #0x10]
	bl __divsi3
	rsbs r0, r0, #0
	str r0, [r7]
	ldrb r1, [r4]
	cmp r0, #0
	bne _0804544C
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r7]
_0804544C:
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r6
	str r5, [r0]
	bl BattleScriptPushCursor
	ldr r1, _080454A0
	ldr r0, _080454A4
	str r0, [r1]
	ldr r0, [sp, #0xc]
	adds r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
_0804546A:
	ldr r0, [sp, #0xc]
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804547C: .4byte 0x02023F20
_08045480: .4byte 0x02024020
_08045484: .4byte 0x02023EB0
_08045488: .4byte 0x0000FFFF
_0804548C: .4byte 0x02023EAF
_08045490: .4byte 0x02023D28
_08045494: .4byte 0x02023EAC
_08045498: .4byte 0x02023EB3
_0804549C: .4byte 0x02024118
_080454A0: .4byte 0x02023EB8
_080454A4: .4byte 0x08289D7F
	thumb_func_end ItemBattleEffects

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
