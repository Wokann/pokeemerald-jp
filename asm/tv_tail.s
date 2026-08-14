.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified
	thumb_func_start DoTVShowPokemonAngler
DoTVShowPokemonAngler: @ 0x080F40A4
	push {r4, r5, lr}
	ldr r2, _080F40D0
	ldr r0, _080F40D4
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F40D8
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r0, _080F40DC
	movs r1, #0
	strh r1, [r0]
	ldrb r0, [r4, #2]
	ldrb r2, [r4, #3]
	cmp r0, r2
	bhs _080F40E4
	ldr r0, _080F40E0
	strb r1, [r0]
	b _080F40EC
	.align 2, 0
_080F40D0: .4byte 0x03005AEC
_080F40D4: .4byte 0x02037280
_080F40D8: .4byte 0x000027CC
_080F40DC: .4byte 0x02037290
_080F40E0: .4byte 0x02039CFC
_080F40E4:
	ldr r1, _080F40F8
	movs r0, #1
	strb r0, [r1]
	adds r0, r1, #0
_080F40EC:
	ldrb r5, [r0]
	cmp r5, #0
	beq _080F40FC
	cmp r5, #1
	beq _080F4134
	b _080F415C
	.align 2, 0
_080F40F8: .4byte 0x02039CFC
_080F40FC:
	ldr r0, _080F4128
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F412C
	ldrh r2, [r4, #4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F4130
	adds r1, r1, r2
	bl StringCopy
	ldrb r1, [r4, #3]
	movs r0, #2
	bl TV_PrintIntToStringVar
	bl TVShowDone
	b _080F415C
	.align 2, 0
_080F4128: .4byte 0x02021C40
_080F412C: .4byte 0x02021C54
_080F4130: .4byte 0x082EA31C
_080F4134:
	ldr r0, _080F4170
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4174
	ldrh r2, [r4, #4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F4178
	adds r1, r1, r2
	bl StringCopy
	ldrb r1, [r4, #2]
	movs r0, #2
	bl TV_PrintIntToStringVar
	bl TVShowDone
_080F415C:
	ldr r0, _080F417C
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F4170: .4byte 0x02021C40
_080F4174: .4byte 0x02021C54
_080F4178: .4byte 0x082EA31C
_080F417C: .4byte 0x08568E5C
	thumb_func_end DoTVShowPokemonAngler

	thumb_func_start DoTVShowTheWorldOfMasters
DoTVShowTheWorldOfMasters: @ 0x080F4180
	push {r4, r5, r6, lr}
	ldr r2, _080F41B0
	ldr r0, _080F41B4
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F41B8
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, _080F41BC
	movs r0, #0
	strh r0, [r1]
	ldr r6, _080F41C0
	ldrb r5, [r6]
	cmp r5, #1
	beq _080F41F0
	cmp r5, #1
	bgt _080F41C4
	cmp r5, #0
	beq _080F41CA
	b _080F423A
	.align 2, 0
_080F41B0: .4byte 0x03005AEC
_080F41B4: .4byte 0x02037280
_080F41B8: .4byte 0x000027CC
_080F41BC: .4byte 0x02037290
_080F41C0: .4byte 0x02039CFC
_080F41C4:
	cmp r5, #2
	beq _080F4210
	b _080F423A
_080F41CA:
	ldr r0, _080F41EC
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrh r1, [r4, #6]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldrh r1, [r4, #2]
	movs r0, #2
	bl TV_PrintIntToStringVar
	movs r0, #1
	strb r0, [r6]
	b _080F423A
	.align 2, 0
_080F41EC: .4byte 0x02021C40
_080F41F0:
	ldr r0, _080F4208
	ldrh r2, [r4, #8]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F420C
	adds r1, r1, r2
	bl StringCopy
	movs r0, #2
	strb r0, [r6]
	b _080F423A
	.align 2, 0
_080F4208: .4byte 0x02021C40
_080F420C: .4byte 0x082EA31C
_080F4210:
	ldr r0, _080F424C
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4250
	ldrb r1, [r4, #0xa]
	movs r2, #0
	bl GetMapName
	ldr r0, _080F4254
	ldrh r2, [r4, #4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F4258
	adds r1, r1, r2
	bl StringCopy
	bl TVShowDone
_080F423A:
	ldr r0, _080F425C
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F424C: .4byte 0x02021C40
_080F4250: .4byte 0x02021C54
_080F4254: .4byte 0x02021C68
_080F4258: .4byte 0x082EA31C
_080F425C: .4byte 0x08568E64
	thumb_func_end DoTVShowTheWorldOfMasters

	thumb_func_start DoTVShowTodaysRivalTrainer
DoTVShowTodaysRivalTrainer: @ 0x080F4260
	push {r4, r5, lr}
	ldr r2, _080F4294
	ldr r0, _080F4298
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F429C
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, _080F42A0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F42A4
	ldrb r5, [r0]
	adds r2, r0, #0
	cmp r5, #0xa
	bls _080F4288
	b _080F4456
_080F4288:
	lsls r0, r5, #2
	ldr r1, _080F42A8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F4294: .4byte 0x03005AEC
_080F4298: .4byte 0x02037280
_080F429C: .4byte 0x000027CC
_080F42A0: .4byte 0x02037290
_080F42A4: .4byte 0x02039CFC
_080F42A8: .4byte 0x080F42AC
_080F42AC: @ jump table
	.4byte _080F42D8 @ case 0
	.4byte _080F43A0 @ case 1
	.4byte _080F43C8 @ case 2
	.4byte _080F4400 @ case 3
	.4byte _080F4412 @ case 4
	.4byte _080F4434 @ case 5
	.4byte _080F4448 @ case 6
	.4byte _080F430E @ case 7
	.4byte _080F433C @ case 8
	.4byte _080F4354 @ case 9
	.4byte _080F436C @ case 10
_080F42D8:
	ldrb r0, [r4, #7]
	cmp r0, #0x56
	beq _080F42E8
	cmp r0, #0x57
	beq _080F42EE
	movs r0, #7
	strb r0, [r2]
	b _080F4456
_080F42E8:
	movs r0, #8
	strb r0, [r2]
	b _080F4456
_080F42EE:
	ldrh r1, [r4, #0xa]
	ldr r0, _080F4304
	cmp r1, r0
	bgt _080F4308
	subs r0, #2
	cmp r1, r0
	blt _080F4308
	movs r0, #0xa
	strb r0, [r2]
	b _080F4456
	.align 2, 0
_080F4304: .4byte 0x00000117
_080F4308:
	movs r0, #9
	strb r0, [r2]
	b _080F4456
_080F430E:
	ldr r0, _080F4334
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrh r1, [r4, #2]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldr r0, _080F4338
	ldrb r1, [r4, #7]
	movs r2, #0
	bl GetMapName
_080F432A:
	ldrb r0, [r4, #4]
	cmp r0, #0
	bne _080F4384
	b _080F4394
	.align 2, 0
_080F4334: .4byte 0x02021C40
_080F4338: .4byte 0x02021C68
_080F433C:
	ldr r0, _080F4350
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrh r1, [r4, #2]
	movs r0, #1
	bl TV_PrintIntToStringVar
	b _080F432A
	.align 2, 0
_080F4350: .4byte 0x02021C40
_080F4354:
	ldr r0, _080F4368
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrh r1, [r4, #2]
	movs r0, #1
	bl TV_PrintIntToStringVar
	b _080F432A
	.align 2, 0
_080F4368: .4byte 0x02021C40
_080F436C:
	ldr r0, _080F438C
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrh r1, [r4, #2]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _080F4394
_080F4384:
	ldr r1, _080F4390
	movs r0, #1
	strb r0, [r1]
	b _080F4456
	.align 2, 0
_080F438C: .4byte 0x02021C40
_080F4390: .4byte 0x02039CFC
_080F4394:
	ldr r1, _080F439C
	movs r0, #2
	strb r0, [r1]
	b _080F4456
	.align 2, 0
_080F439C: .4byte 0x02039CFC
_080F43A0:
	ldrb r1, [r4, #4]
	movs r0, #0
	bl TV_PrintIntToStringVar
	ldr r0, _080F43C0
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F443C
	ldr r0, [r4, #4]
	ldr r1, _080F43C4
	ands r0, r1
	cmp r0, #0
	bne _080F43DE
	b _080F43F4
	.align 2, 0
_080F43C0: .4byte 0x000008A8
_080F43C4: .4byte 0x00FFFF00
_080F43C8:
	ldr r0, _080F43E8
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F443C
	ldr r0, [r4, #4]
	ldr r1, _080F43EC
	ands r0, r1
	cmp r0, #0
	beq _080F43F4
_080F43DE:
	ldr r1, _080F43F0
	movs r0, #4
	strb r0, [r1]
	b _080F4456
	.align 2, 0
_080F43E8: .4byte 0x000008A8
_080F43EC: .4byte 0x00FFFF00
_080F43F0: .4byte 0x02039CFC
_080F43F4:
	ldr r1, _080F43FC
	movs r0, #3
	strb r0, [r1]
	b _080F4456
	.align 2, 0
_080F43FC: .4byte 0x02039CFC
_080F4400:
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080F440C
	movs r0, #6
	strb r0, [r2]
	b _080F4456
_080F440C:
	movs r0, #5
	strb r0, [r2]
	b _080F4456
_080F4412:
	ldrb r1, [r4, #6]
	movs r0, #0
	bl TV_PrintIntToStringVar
	ldrb r1, [r4, #5]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldrh r0, [r4, #8]
	cmp r0, #0
	beq _080F443C
	ldr r1, _080F4430
	movs r0, #5
	strb r0, [r1]
	b _080F4456
	.align 2, 0
_080F4430: .4byte 0x02039CFC
_080F4434:
	ldrh r1, [r4, #8]
	movs r0, #0
	bl TV_PrintIntToStringVar
_080F443C:
	ldr r1, _080F4444
	movs r0, #6
	strb r0, [r1]
	b _080F4456
	.align 2, 0
_080F4444: .4byte 0x02039CFC
_080F4448:
	ldr r0, _080F4468
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	bl TVShowDone
_080F4456:
	ldr r0, _080F446C
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F4468: .4byte 0x02021C40
_080F446C: .4byte 0x08568E70
	thumb_func_end DoTVShowTodaysRivalTrainer

	thumb_func_start DoTVShowDewfordTrendWatcherNetwork
DoTVShowDewfordTrendWatcherNetwork: @ 0x080F4470
	push {r4, r5, lr}
	ldr r2, _080F44A0
	ldr r0, _080F44A4
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F44A8
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, _080F44AC
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F44B0
	ldrb r5, [r0]
	cmp r5, #6
	bls _080F4496
	b _080F45C0
_080F4496:
	lsls r0, r5, #2
	ldr r1, _080F44B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F44A0: .4byte 0x03005AEC
_080F44A4: .4byte 0x02037280
_080F44A8: .4byte 0x000027CC
_080F44AC: .4byte 0x02037290
_080F44B0: .4byte 0x02039CFC
_080F44B4: .4byte 0x080F44B8
_080F44B8: @ jump table
	.4byte _080F44D4 @ case 0
	.4byte _080F450C @ case 1
	.4byte _080F450C @ case 2
	.4byte _080F4540 @ case 3
	.4byte _080F4578 @ case 4
	.4byte _080F4578 @ case 5
	.4byte _080F45AC @ case 6
_080F44D4:
	ldr r0, _080F44F4
	ldrh r1, [r4, #4]
	bl CopyEasyChatWord
	ldr r0, _080F44F8
	ldrh r1, [r4, #6]
	bl CopyEasyChatWord
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _080F4500
	ldr r1, _080F44FC
	movs r0, #1
	strb r0, [r1]
	b _080F45C0
	.align 2, 0
_080F44F4: .4byte 0x02021C40
_080F44F8: .4byte 0x02021C54
_080F44FC: .4byte 0x02039CFC
_080F4500:
	ldr r1, _080F4508
	movs r0, #2
	strb r0, [r1]
	b _080F45C0
	.align 2, 0
_080F4508: .4byte 0x02039CFC
_080F450C:
	ldr r0, _080F4530
	ldrh r1, [r4, #4]
	bl CopyEasyChatWord
	ldr r0, _080F4534
	ldrh r1, [r4, #6]
	bl CopyEasyChatWord
	ldr r0, _080F4538
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldr r1, _080F453C
	movs r0, #3
	strb r0, [r1]
	b _080F45C0
	.align 2, 0
_080F4530: .4byte 0x02021C40
_080F4534: .4byte 0x02021C54
_080F4538: .4byte 0x02021C68
_080F453C: .4byte 0x02039CFC
_080F4540:
	ldr r0, _080F4560
	ldrh r1, [r4, #4]
	bl CopyEasyChatWord
	ldr r0, _080F4564
	ldrh r1, [r4, #6]
	bl CopyEasyChatWord
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _080F456C
	ldr r1, _080F4568
	movs r0, #4
	strb r0, [r1]
	b _080F45C0
	.align 2, 0
_080F4560: .4byte 0x02021C40
_080F4564: .4byte 0x02021C54
_080F4568: .4byte 0x02039CFC
_080F456C:
	ldr r1, _080F4574
	movs r0, #5
	strb r0, [r1]
	b _080F45C0
	.align 2, 0
_080F4574: .4byte 0x02039CFC
_080F4578:
	ldr r0, _080F459C
	ldrh r1, [r4, #4]
	bl CopyEasyChatWord
	ldr r0, _080F45A0
	ldrh r1, [r4, #6]
	bl CopyEasyChatWord
	ldr r0, _080F45A4
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldr r1, _080F45A8
	movs r0, #6
	strb r0, [r1]
	b _080F45C0
	.align 2, 0
_080F459C: .4byte 0x02021C40
_080F45A0: .4byte 0x02021C54
_080F45A4: .4byte 0x02021C68
_080F45A8: .4byte 0x02039CFC
_080F45AC:
	ldr r0, _080F45D4
	ldrh r1, [r4, #4]
	bl CopyEasyChatWord
	ldr r0, _080F45D8
	ldrh r1, [r4, #6]
	bl CopyEasyChatWord
	bl TVShowDone
_080F45C0:
	ldr r0, _080F45DC
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F45D4: .4byte 0x02021C40
_080F45D8: .4byte 0x02021C54
_080F45DC: .4byte 0x08568E9C
	thumb_func_end DoTVShowDewfordTrendWatcherNetwork

	thumb_func_start DoTVShowHoennTreasureInvestigators
DoTVShowHoennTreasureInvestigators: @ 0x080F45E0
	push {r4, r5, r6, r7, lr}
	ldr r2, _080F4610
	ldr r0, _080F4614
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F4618
	adds r0, r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, _080F461C
	movs r0, #0
	strh r0, [r1]
	ldr r7, _080F4620
	ldrb r6, [r7]
	cmp r6, #1
	beq _080F466E
	cmp r6, #1
	bgt _080F4624
	cmp r6, #0
	beq _080F462A
	b _080F46C2
	.align 2, 0
_080F4610: .4byte 0x03005AEC
_080F4614: .4byte 0x02037280
_080F4618: .4byte 0x000027CC
_080F461C: .4byte 0x02037290
_080F4620: .4byte 0x02039CFC
_080F4624:
	cmp r6, #2
	beq _080F46A4
	b _080F46C2
_080F462A:
	ldr r4, _080F4654
	ldrh r0, [r5, #2]
	bl ItemId_GetName
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldrb r0, [r5, #4]
	cmp r0, #0x57
	bne _080F4668
	ldrh r1, [r5, #6]
	ldr r0, _080F4658
	cmp r1, r0
	bgt _080F465C
	subs r0, #2
	cmp r1, r0
	blt _080F465C
	movs r0, #2
	strb r0, [r7]
	b _080F46C2
	.align 2, 0
_080F4654: .4byte 0x02021C40
_080F4658: .4byte 0x00000117
_080F465C:
	ldr r1, _080F4664
	movs r0, #1
	strb r0, [r1]
	b _080F46C2
	.align 2, 0
_080F4664: .4byte 0x02039CFC
_080F4668:
	movs r0, #1
	strb r0, [r7]
	b _080F46C2
_080F466E:
	ldr r4, _080F4698
	ldrh r0, [r5, #2]
	bl ItemId_GetName
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldr r0, _080F469C
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F46A0
	ldrb r1, [r5, #4]
	movs r2, #0
	bl GetMapName
	bl TVShowDone
	b _080F46C2
	.align 2, 0
_080F4698: .4byte 0x02021C40
_080F469C: .4byte 0x02021C54
_080F46A0: .4byte 0x02021C68
_080F46A4:
	ldr r4, _080F46D4
	ldrh r0, [r5, #2]
	bl ItemId_GetName
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldr r0, _080F46D8
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	bl TVShowDone
_080F46C2:
	ldr r0, _080F46DC
	lsls r1, r6, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F46D4: .4byte 0x02021C40
_080F46D8: .4byte 0x02021C54
_080F46DC: .4byte 0x08568EB8
	thumb_func_end DoTVShowHoennTreasureInvestigators

	thumb_func_start DoTVShowFindThatGamer
DoTVShowFindThatGamer: @ 0x080F46E0
	push {r4, r5, lr}
	ldr r2, _080F4710
	ldr r0, _080F4714
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F4718
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, _080F471C
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F4720
	ldrb r5, [r0]
	cmp r5, #1
	beq _080F478C
	cmp r5, #1
	bgt _080F4724
	cmp r5, #0
	beq _080F4730
	b _080F486C
	.align 2, 0
_080F4710: .4byte 0x03005AEC
_080F4714: .4byte 0x02037280
_080F4718: .4byte 0x000027CC
_080F471C: .4byte 0x02037290
_080F4720: .4byte 0x02039CFC
_080F4724:
	cmp r5, #2
	beq _080F47DC
	cmp r5, #3
	bne _080F472E
	b _080F4830
_080F472E:
	b _080F486C
_080F4730:
	ldr r0, _080F4748
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _080F474C
	cmp r0, #1
	beq _080F4760
	b _080F4768
	.align 2, 0
_080F4748: .4byte 0x02021C40
_080F474C:
	ldr r0, _080F4758
	ldr r1, _080F475C
	bl StringCopy
	b _080F4768
	.align 2, 0
_080F4758: .4byte 0x02021C54
_080F475C: .4byte 0x085CBFAD
_080F4760:
	ldr r0, _080F4774
	ldr r1, _080F4778
	bl StringCopy
_080F4768:
	ldrb r1, [r4, #2]
	cmp r1, #1
	bne _080F4780
	ldr r0, _080F477C
	strb r1, [r0]
	b _080F486C
	.align 2, 0
_080F4774: .4byte 0x02021C54
_080F4778: .4byte 0x085CBFB2
_080F477C: .4byte 0x02039CFC
_080F4780:
	ldr r1, _080F4788
	movs r0, #2
	strb r0, [r1]
	b _080F486C
	.align 2, 0
_080F4788: .4byte 0x02039CFC
_080F478C:
	ldr r0, _080F47A4
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _080F47A8
	cmp r0, #1
	beq _080F47BC
	b _080F47C4
	.align 2, 0
_080F47A4: .4byte 0x02021C40
_080F47A8:
	ldr r0, _080F47B4
	ldr r1, _080F47B8
	bl StringCopy
	b _080F47C4
	.align 2, 0
_080F47B4: .4byte 0x02021C54
_080F47B8: .4byte 0x085CBFAD
_080F47BC:
	ldr r0, _080F47D4
	ldr r1, _080F47D8
	bl StringCopy
_080F47C4:
	ldrh r1, [r4, #4]
	movs r0, #2
	bl TV_PrintIntToStringVar
	bl TVShowDone
	b _080F486C
	.align 2, 0
_080F47D4: .4byte 0x02021C54
_080F47D8: .4byte 0x085CBFB2
_080F47DC:
	ldr r0, _080F47F4
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _080F47F8
	cmp r0, #1
	beq _080F480C
	b _080F4814
	.align 2, 0
_080F47F4: .4byte 0x02021C40
_080F47F8:
	ldr r0, _080F4804
	ldr r1, _080F4808
	bl StringCopy
	b _080F4814
	.align 2, 0
_080F4804: .4byte 0x02021C54
_080F4808: .4byte 0x085CBFAD
_080F480C:
	ldr r0, _080F4824
	ldr r1, _080F4828
	bl StringCopy
_080F4814:
	ldrh r1, [r4, #4]
	movs r0, #2
	bl TV_PrintIntToStringVar
	ldr r1, _080F482C
	movs r0, #3
	strb r0, [r1]
	b _080F486C
	.align 2, 0
_080F4824: .4byte 0x02021C54
_080F4828: .4byte 0x085CBFB2
_080F482C: .4byte 0x02039CFC
_080F4830:
	ldr r0, _080F4848
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r1, [r4, #3]
	cmp r1, #0
	beq _080F484C
	cmp r1, #1
	beq _080F4860
	b _080F4868
	.align 2, 0
_080F4848: .4byte 0x02021C40
_080F484C:
	ldr r0, _080F4858
	ldr r1, _080F485C
	bl StringCopy
	b _080F4868
	.align 2, 0
_080F4858: .4byte 0x02021C54
_080F485C: .4byte 0x085CBFB2
_080F4860:
	ldr r0, _080F4880
	ldr r1, _080F4884
	bl StringCopy
_080F4868:
	bl TVShowDone
_080F486C:
	ldr r0, _080F4888
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F4880: .4byte 0x02021C54
_080F4884: .4byte 0x085CBFAD
_080F4888: .4byte 0x08568EC4
	thumb_func_end DoTVShowFindThatGamer

	thumb_func_start DoTVShowBreakingNewsTV
DoTVShowBreakingNewsTV: @ 0x080F488C
	push {r4, r5, r6, lr}
	ldr r2, _080F48C0
	ldr r0, _080F48C4
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F48C8
	adds r0, r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, _080F48CC
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F48D0
	ldrb r6, [r0]
	adds r2, r0, #0
	cmp r6, #0xc
	bls _080F48B4
	b _080F4BA2
_080F48B4:
	lsls r0, r6, #2
	ldr r1, _080F48D4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F48C0: .4byte 0x03005AEC
_080F48C4: .4byte 0x02037280
_080F48C8: .4byte 0x000027CC
_080F48CC: .4byte 0x02037290
_080F48D0: .4byte 0x02039CFC
_080F48D4: .4byte 0x080F48D8
_080F48D8: @ jump table
	.4byte _080F490C @ case 0
	.4byte _080F491E @ case 1
	.4byte _080F4960 @ case 2
	.4byte _080F49A8 @ case 3
	.4byte _080F49D0 @ case 4
	.4byte _080F49F4 @ case 5
	.4byte _080F4A38 @ case 6
	.4byte _080F4AC0 @ case 7
	.4byte _080F4B38 @ case 8
	.4byte _080F4B50 @ case 9
	.4byte _080F4B50 @ case 10
	.4byte _080F4B94 @ case 11
	.4byte _080F4AF0 @ case 12
_080F490C:
	ldrb r0, [r5, #5]
	cmp r0, #0
	bne _080F4918
	movs r0, #1
	strb r0, [r2]
	b _080F4BA2
_080F4918:
	movs r0, #5
	strb r0, [r2]
	b _080F4BA2
_080F491E:
	ldr r0, _080F494C
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4950
	ldrh r2, [r5, #2]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F4954
	adds r1, r1, r2
	bl StringCopy
	ldr r0, _080F4958
	ldrb r1, [r5, #4]
	movs r2, #0
	bl GetMapName
	ldr r1, _080F495C
	movs r0, #2
	strb r0, [r1]
	b _080F4BA2
	.align 2, 0
_080F494C: .4byte 0x02021C40
_080F4950: .4byte 0x02021C54
_080F4954: .4byte 0x082EA31C
_080F4958: .4byte 0x02021C68
_080F495C: .4byte 0x02039CFC
_080F4960:
	ldr r0, _080F4994
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4998
	ldrh r2, [r5, #2]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r4, _080F499C
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F49A0
	ldrh r2, [r5, #0xa]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	bl StringCopy
	ldr r1, _080F49A4
	movs r0, #3
	strb r0, [r1]
	b _080F4BA2
	.align 2, 0
_080F4994: .4byte 0x02021C40
_080F4998: .4byte 0x02021C54
_080F499C: .4byte 0x082EA31C
_080F49A0: .4byte 0x02021C68
_080F49A4: .4byte 0x02039CFC
_080F49A8:
	ldrh r1, [r5, #8]
	movs r0, #0
	bl TV_PrintIntToStringVar
	ldr r4, _080F49C8
	ldrh r0, [r5, #6]
	bl ItemId_GetName
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldr r1, _080F49CC
	movs r0, #4
	strb r0, [r1]
	b _080F4BA2
	.align 2, 0
_080F49C8: .4byte 0x02021C54
_080F49CC: .4byte 0x02039CFC
_080F49D0:
	ldr r0, _080F49EC
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F49F0
	ldrb r1, [r5, #4]
	movs r2, #0
	bl GetMapName
	bl TVShowDone
	b _080F4BA2
	.align 2, 0
_080F49EC: .4byte 0x02021C40
_080F49F0: .4byte 0x02021C54
_080F49F4:
	ldr r0, _080F4A24
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4A28
	ldrh r2, [r5, #2]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F4A2C
	adds r1, r1, r2
	bl StringCopy
	ldr r0, _080F4A30
	ldrb r1, [r5, #4]
	movs r2, #0
	bl GetMapName
	ldr r1, _080F4A34
	movs r0, #6
	strb r0, [r1]
	b _080F4BA2
	.align 2, 0
_080F4A24: .4byte 0x02021C40
_080F4A28: .4byte 0x02021C54
_080F4A2C: .4byte 0x082EA31C
_080F4A30: .4byte 0x02021C68
_080F4A34: .4byte 0x02039CFC
_080F4A38:
	ldr r0, _080F4A74
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4A78
	ldrh r2, [r5, #2]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r4, _080F4A7C
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F4A80
	ldrh r2, [r5, #0xa]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	bl StringCopy
	ldrb r0, [r5, #5]
	cmp r0, #2
	beq _080F4AA8
	cmp r0, #2
	bgt _080F4A84
	cmp r0, #1
	beq _080F4A8A
	b _080F4BA2
	.align 2, 0
_080F4A74: .4byte 0x02021C40
_080F4A78: .4byte 0x02021C54
_080F4A7C: .4byte 0x082EA31C
_080F4A80: .4byte 0x02021C68
_080F4A84:
	cmp r0, #3
	beq _080F4AB4
	b _080F4BA2
_080F4A8A:
	ldrh r0, [r5, #0xc]
	cmp r0, #0
	bne _080F4A9C
	ldr r1, _080F4A98
	movs r0, #0xc
	strb r0, [r1]
	b _080F4BA2
	.align 2, 0
_080F4A98: .4byte 0x02039CFC
_080F4A9C:
	ldr r1, _080F4AA4
	movs r0, #7
	strb r0, [r1]
	b _080F4BA2
	.align 2, 0
_080F4AA4: .4byte 0x02039CFC
_080F4AA8:
	ldr r1, _080F4AB0
	movs r0, #9
	strb r0, [r1]
	b _080F4BA2
	.align 2, 0
_080F4AB0: .4byte 0x02039CFC
_080F4AB4:
	ldr r1, _080F4ABC
	movs r0, #0xa
	strb r0, [r1]
	b _080F4BA2
	.align 2, 0
_080F4ABC: .4byte 0x02039CFC
_080F4AC0:
	ldr r0, _080F4AE0
	ldrh r1, [r5, #0xc]
	lsls r1, r1, #3
	ldr r2, _080F4AE4
	adds r1, r1, r2
	bl StringCopy
	ldr r0, _080F4AE8
	ldrh r2, [r5, #0xa]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F4AEC
	adds r1, r1, r2
	b _080F4B18
	.align 2, 0
_080F4AE0: .4byte 0x02021C40
_080F4AE4: .4byte 0x082EACC4
_080F4AE8: .4byte 0x02021C54
_080F4AEC: .4byte 0x082EA31C
_080F4AF0:
	ldr r0, _080F4B24
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4B28
	ldrh r2, [r5, #2]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r4, _080F4B2C
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F4B30
	ldrh r2, [r5, #0xa]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
_080F4B18:
	bl StringCopy
	ldr r1, _080F4B34
	movs r0, #8
	strb r0, [r1]
	b _080F4BA2
	.align 2, 0
_080F4B24: .4byte 0x02021C40
_080F4B28: .4byte 0x02021C54
_080F4B2C: .4byte 0x082EA31C
_080F4B30: .4byte 0x02021C68
_080F4B34: .4byte 0x02039CFC
_080F4B38:
	ldr r0, _080F4B48
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4B4C
	b _080F4B6E
	.align 2, 0
_080F4B48: .4byte 0x02021C40
_080F4B4C: .4byte 0x02021C54
_080F4B50:
	ldr r0, _080F4B80
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4B84
	ldrh r2, [r5, #2]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F4B88
	adds r1, r1, r2
	bl StringCopy
	ldr r0, _080F4B8C
_080F4B6E:
	ldrb r1, [r5, #4]
	movs r2, #0
	bl GetMapName
	ldr r1, _080F4B90
	movs r0, #0xb
	strb r0, [r1]
	b _080F4BA2
	.align 2, 0
_080F4B80: .4byte 0x02021C40
_080F4B84: .4byte 0x02021C54
_080F4B88: .4byte 0x082EA31C
_080F4B8C: .4byte 0x02021C68
_080F4B90: .4byte 0x02039CFC
_080F4B94:
	ldr r0, _080F4BB4
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	bl TVShowDone
_080F4BA2:
	ldr r0, _080F4BB8
	lsls r1, r6, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F4BB4: .4byte 0x02021C40
_080F4BB8: .4byte 0x08568ED4
	thumb_func_end DoTVShowBreakingNewsTV

	thumb_func_start DoTVShowSecretBaseVisit
DoTVShowSecretBaseVisit: @ 0x080F4BBC
	push {r4, r5, r6, lr}
	ldr r2, _080F4BF0
	ldr r0, _080F4BF4
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F4BF8
	adds r0, r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, _080F4BFC
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F4C00
	ldrb r6, [r0]
	adds r2, r0, #0
	cmp r6, #0xd
	bls _080F4BE4
	b _080F4DF4
_080F4BE4:
	lsls r0, r6, #2
	ldr r1, _080F4C04
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F4BF0: .4byte 0x03005AEC
_080F4BF4: .4byte 0x02037280
_080F4BF8: .4byte 0x000027CC
_080F4BFC: .4byte 0x02037290
_080F4C00: .4byte 0x02039CFC
_080F4C04: .4byte 0x080F4C08
_080F4C08: @ jump table
	.4byte _080F4C40 @ case 0
	.4byte _080F4C6C @ case 1
	.4byte _080F4D50 @ case 2
	.4byte _080F4CA4 @ case 3
	.4byte _080F4D50 @ case 4
	.4byte _080F4CFC @ case 5
	.4byte _080F4D28 @ case 6
	.4byte _080F4D50 @ case 7
	.4byte _080F4D56 @ case 8
	.4byte _080F4DA4 @ case 9
	.4byte _080F4DA4 @ case 10
	.4byte _080F4DA4 @ case 11
	.4byte _080F4DA4 @ case 12
	.4byte _080F4DF0 @ case 13
_080F4C40:
	ldr r0, _080F4C58
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r0, [r5, #3]
	cmp r0, #0
	bne _080F4C60
	ldr r1, _080F4C5C
	movs r0, #2
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4C58: .4byte 0x02021C40
_080F4C5C: .4byte 0x02039CFC
_080F4C60:
	ldr r1, _080F4C68
	movs r0, #1
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4C68: .4byte 0x02039CFC
_080F4C6C:
	ldr r0, _080F4C8C
	ldrb r2, [r5, #4]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	ldr r2, _080F4C90
	adds r1, r1, r2
	bl StringCopy
	ldrb r0, [r5, #3]
	cmp r0, #1
	bne _080F4C98
	ldr r1, _080F4C94
	movs r0, #4
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4C8C: .4byte 0x02021C54
_080F4C90: .4byte 0x08580CD1
_080F4C94: .4byte 0x02039CFC
_080F4C98:
	ldr r1, _080F4CA0
	movs r0, #3
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4CA0: .4byte 0x02039CFC
_080F4CA4:
	ldr r0, _080F4CC8
	ldrb r2, [r5, #5]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	ldr r2, _080F4CCC
	adds r1, r1, r2
	bl StringCopy
	ldrb r1, [r5, #3]
	cmp r1, #3
	beq _080F4CE4
	cmp r1, #3
	bgt _080F4CD0
	cmp r1, #2
	beq _080F4CD6
	b _080F4DF4
	.align 2, 0
_080F4CC8: .4byte 0x02021C54
_080F4CCC: .4byte 0x08580CD1
_080F4CD0:
	cmp r1, #4
	beq _080F4CF0
	b _080F4DF4
_080F4CD6:
	ldr r1, _080F4CE0
	movs r0, #7
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4CE0: .4byte 0x02039CFC
_080F4CE4:
	ldr r1, _080F4CEC
	movs r0, #6
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4CEC: .4byte 0x02039CFC
_080F4CF0:
	ldr r1, _080F4CF8
	movs r0, #5
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4CF8: .4byte 0x02039CFC
_080F4CFC:
	ldr r0, _080F4D1C
	ldrb r2, [r5, #6]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	ldr r4, _080F4D20
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F4D24
	ldrb r2, [r5, #7]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r4
	b _080F4D36
	.align 2, 0
_080F4D1C: .4byte 0x02021C54
_080F4D20: .4byte 0x08580CD1
_080F4D24: .4byte 0x02021C68
_080F4D28:
	ldr r0, _080F4D44
	ldrb r2, [r5, #6]
	lsls r1, r2, #3
	subs r1, r1, r2
	lsls r1, r1, #2
	ldr r2, _080F4D48
	adds r1, r1, r2
_080F4D36:
	bl StringCopy
	ldr r1, _080F4D4C
	movs r0, #8
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4D44: .4byte 0x02021C54
_080F4D48: .4byte 0x08580CD1
_080F4D4C: .4byte 0x02039CFC
_080F4D50:
	movs r0, #8
	strb r0, [r2]
	b _080F4DF4
_080F4D56:
	ldr r0, _080F4D70
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r1, [r5, #2]
	cmp r1, #0x18
	bhi _080F4D78
	ldr r1, _080F4D74
	movs r0, #0xc
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4D70: .4byte 0x02021C40
_080F4D74: .4byte 0x02039CFC
_080F4D78:
	cmp r1, #0x31
	bhi _080F4D88
	ldr r1, _080F4D84
	movs r0, #0xb
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4D84: .4byte 0x02039CFC
_080F4D88:
	cmp r1, #0x45
	bhi _080F4D98
	ldr r1, _080F4D94
	movs r0, #0xa
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4D94: .4byte 0x02039CFC
_080F4D98:
	ldr r1, _080F4DA0
	movs r0, #9
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4DA0: .4byte 0x02039CFC
_080F4DA4:
	ldr r0, _080F4DD8
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4DDC
	ldrh r2, [r5, #8]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F4DE0
	adds r1, r1, r2
	bl StringCopy
	ldr r0, _080F4DE4
	ldrh r1, [r5, #0xa]
	lsls r1, r1, #3
	ldr r2, _080F4DE8
	adds r1, r1, r2
	bl StringCopy
	ldr r1, _080F4DEC
	movs r0, #0xd
	strb r0, [r1]
	b _080F4DF4
	.align 2, 0
_080F4DD8: .4byte 0x02021C40
_080F4DDC: .4byte 0x02021C54
_080F4DE0: .4byte 0x082EA31C
_080F4DE4: .4byte 0x02021C68
_080F4DE8: .4byte 0x082EACC4
_080F4DEC: .4byte 0x02039CFC
_080F4DF0:
	bl TVShowDone
_080F4DF4:
	ldr r0, _080F4E08
	lsls r1, r6, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F4E08: .4byte 0x08568F08
	thumb_func_end DoTVShowSecretBaseVisit

	thumb_func_start DoTVShowPokemonLotteryWinnerFlashReport
DoTVShowPokemonLotteryWinnerFlashReport: @ 0x080F4E0C
	push {r4, r5, r6, lr}
	ldr r2, _080F4E48
	ldr r0, _080F4E4C
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F4E50
	adds r0, r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, _080F4E54
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F4E58
	ldrb r6, [r0]
	ldr r0, _080F4E5C
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r0, [r5, #4]
	cmp r0, #0
	bne _080F4E68
	ldr r0, _080F4E60
	ldr r1, _080F4E64
	bl StringCopy
	b _080F4E70
	.align 2, 0
_080F4E48: .4byte 0x03005AEC
_080F4E4C: .4byte 0x02037280
_080F4E50: .4byte 0x000027CC
_080F4E54: .4byte 0x02037290
_080F4E58: .4byte 0x02039CFC
_080F4E5C: .4byte 0x02021C40
_080F4E60: .4byte 0x02021C54
_080F4E64: .4byte 0x085CBFEC
_080F4E68:
	ldrb r1, [r5, #4]
	movs r0, #1
	bl TV_PrintIntToStringVar
_080F4E70:
	ldr r4, _080F4E98
	ldrh r0, [r5, #2]
	bl ItemId_GetName
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	bl TVShowDone
	ldr r1, _080F4E9C
	lsls r0, r6, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bl ShowFieldMessage
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F4E98: .4byte 0x02021C68
_080F4E9C: .4byte 0x08568F40
	thumb_func_end DoTVShowPokemonLotteryWinnerFlashReport

	thumb_func_start DoTVShowThePokemonBattleSeminar
DoTVShowThePokemonBattleSeminar: @ 0x080F4EA0
	push {r4, r5, r6, lr}
	ldr r2, _080F4ED0
	ldr r0, _080F4ED4
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F4ED8
	adds r0, r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, _080F4EDC
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F4EE0
	ldrb r6, [r0]
	cmp r6, #6
	bls _080F4EC6
	b _080F508A
_080F4EC6:
	lsls r0, r6, #2
	ldr r1, _080F4EE4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F4ED0: .4byte 0x03005AEC
_080F4ED4: .4byte 0x02037280
_080F4ED8: .4byte 0x000027CC
_080F4EDC: .4byte 0x02037290
_080F4EE0: .4byte 0x02039CFC
_080F4EE4: .4byte 0x080F4EE8
_080F4EE8: @ jump table
	.4byte _080F4F04 @ case 0
	.4byte _080F4F4C @ case 1
	.4byte _080F4F98 @ case 2
	.4byte _080F4FF0 @ case 3
	.4byte _080F5024 @ case 4
	.4byte _080F5048 @ case 5
	.4byte _080F506C @ case 6
_080F4F04:
	ldr r0, _080F4F38
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4F3C
	ldrh r2, [r5, #6]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r4, _080F4F40
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F4F44
	ldrh r2, [r5, #4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	bl StringCopy
	ldr r1, _080F4F48
	movs r0, #1
	strb r0, [r1]
	b _080F508A
	.align 2, 0
_080F4F38: .4byte 0x02021C40
_080F4F3C: .4byte 0x02021C54
_080F4F40: .4byte 0x082EA31C
_080F4F44: .4byte 0x02021C68
_080F4F48: .4byte 0x02039CFC
_080F4F4C:
	ldr r0, _080F4F80
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F4F84
	ldrh r2, [r5, #4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F4F88
	adds r1, r1, r2
	bl StringCopy
	ldr r0, _080F4F8C
	ldrh r1, [r5, #2]
	lsls r1, r1, #3
	ldr r2, _080F4F90
	adds r1, r1, r2
	bl StringCopy
	ldr r1, _080F4F94
	movs r0, #2
	strb r0, [r1]
	b _080F508A
	.align 2, 0
_080F4F80: .4byte 0x02021C40
_080F4F84: .4byte 0x02021C54
_080F4F88: .4byte 0x082EA31C
_080F4F8C: .4byte 0x02021C68
_080F4F90: .4byte 0x082EACC4
_080F4F94: .4byte 0x02039CFC
_080F4F98:
	ldr r0, _080F4FBC
	ldrh r2, [r5, #6]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F4FC0
	adds r1, r1, r2
	bl StringCopy
	ldrb r1, [r5, #0x10]
	cmp r1, #2
	beq _080F4FD8
	cmp r1, #2
	bgt _080F4FC4
	cmp r1, #1
	beq _080F4FCA
	b _080F5056
	.align 2, 0
_080F4FBC: .4byte 0x02021C40
_080F4FC0: .4byte 0x082EA31C
_080F4FC4:
	cmp r1, #3
	beq _080F4FE4
	b _080F5056
_080F4FCA:
	ldr r1, _080F4FD4
	movs r0, #5
	strb r0, [r1]
	b _080F508A
	.align 2, 0
_080F4FD4: .4byte 0x02039CFC
_080F4FD8:
	ldr r1, _080F4FE0
	movs r0, #4
	strb r0, [r1]
	b _080F508A
	.align 2, 0
_080F4FE0: .4byte 0x02039CFC
_080F4FE4:
	ldr r0, _080F4FEC
	strb r1, [r0]
	b _080F508A
	.align 2, 0
_080F4FEC: .4byte 0x02039CFC
_080F4FF0:
	ldr r0, _080F5014
	ldrh r1, [r5, #8]
	lsls r1, r1, #3
	ldr r4, _080F5018
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F501C
	ldrh r1, [r5, #0xa]
	lsls r1, r1, #3
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F5020
	ldrh r1, [r5, #0xc]
	lsls r1, r1, #3
	adds r1, r1, r4
	b _080F5052
	.align 2, 0
_080F5014: .4byte 0x02021C40
_080F5018: .4byte 0x082EACC4
_080F501C: .4byte 0x02021C54
_080F5020: .4byte 0x02021C68
_080F5024:
	ldr r0, _080F503C
	ldrh r1, [r5, #8]
	lsls r1, r1, #3
	ldr r4, _080F5040
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F5044
	ldrh r1, [r5, #0xa]
	lsls r1, r1, #3
	adds r1, r1, r4
	b _080F5052
	.align 2, 0
_080F503C: .4byte 0x02021C40
_080F5040: .4byte 0x082EACC4
_080F5044: .4byte 0x02021C54
_080F5048:
	ldr r0, _080F5060
	ldrh r1, [r5, #8]
	lsls r1, r1, #3
	ldr r2, _080F5064
	adds r1, r1, r2
_080F5052:
	bl StringCopy
_080F5056:
	ldr r1, _080F5068
	movs r0, #6
	strb r0, [r1]
	b _080F508A
	.align 2, 0
_080F5060: .4byte 0x02021C54
_080F5064: .4byte 0x082EACC4
_080F5068: .4byte 0x02039CFC
_080F506C:
	ldr r0, _080F509C
	ldrh r1, [r5, #0xe]
	lsls r1, r1, #3
	ldr r4, _080F50A0
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F50A4
	ldrh r1, [r5, #2]
	lsls r1, r1, #3
	adds r1, r1, r4
	bl StringCopy
	bl TVShowDone
_080F508A:
	ldr r0, _080F50A8
	lsls r1, r6, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F509C: .4byte 0x02021C40
_080F50A0: .4byte 0x082EACC4
_080F50A4: .4byte 0x02021C54
_080F50A8: .4byte 0x08568F44
	thumb_func_end DoTVShowThePokemonBattleSeminar

	thumb_func_start DoTVShowTrainerFanClubSpecial
DoTVShowTrainerFanClubSpecial: @ 0x080F50AC
	push {r4, r5, lr}
	ldr r2, _080F50DC
	ldr r0, _080F50E0
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F50E4
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, _080F50E8
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F50EC
	ldrb r5, [r0]
	cmp r5, #5
	bls _080F50D2
	b _080F51BE
_080F50D2:
	lsls r0, r5, #2
	ldr r1, _080F50F0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F50DC: .4byte 0x03005AEC
_080F50E0: .4byte 0x02037280
_080F50E4: .4byte 0x000027CC
_080F50E8: .4byte 0x02037290
_080F50EC: .4byte 0x02039CFC
_080F50F0: .4byte 0x080F50F4
_080F50F4: @ jump table
	.4byte _080F510C @ case 0
	.4byte _080F5170 @ case 1
	.4byte _080F5170 @ case 2
	.4byte _080F5170 @ case 3
	.4byte _080F5170 @ case 4
	.4byte _080F51A0 @ case 5
_080F510C:
	ldr r0, _080F5134
	adds r1, r4, #0
	adds r1, #0xc
	bl StringCopy
	ldr r0, _080F5138
	adds r1, r4, #2
	bl StringCopy
	ldr r0, _080F513C
	ldrh r1, [r4, #0x14]
	bl CopyEasyChatWord
	ldrb r1, [r4, #0x16]
	cmp r1, #0x59
	bls _080F5144
	ldr r1, _080F5140
	movs r0, #1
	strb r0, [r1]
	b _080F51BE
	.align 2, 0
_080F5134: .4byte 0x02021C40
_080F5138: .4byte 0x02021C54
_080F513C: .4byte 0x02021C68
_080F5140: .4byte 0x02039CFC
_080F5144:
	cmp r1, #0x45
	bls _080F5154
	ldr r1, _080F5150
	movs r0, #2
	strb r0, [r1]
	b _080F51BE
	.align 2, 0
_080F5150: .4byte 0x02039CFC
_080F5154:
	cmp r1, #0x1d
	bls _080F5164
	ldr r1, _080F5160
	movs r0, #3
	strb r0, [r1]
	b _080F51BE
	.align 2, 0
_080F5160: .4byte 0x02039CFC
_080F5164:
	ldr r1, _080F516C
	movs r0, #4
	strb r0, [r1]
	b _080F51BE
	.align 2, 0
_080F516C: .4byte 0x02039CFC
_080F5170:
	ldr r0, _080F5194
	adds r1, r4, #0
	adds r1, #0xc
	bl StringCopy
	ldr r0, _080F5198
	adds r1, r4, #2
	bl StringCopy
	ldrb r1, [r4, #0x16]
	movs r0, #2
	bl TV_PrintIntToStringVar
	ldr r1, _080F519C
	movs r0, #5
	strb r0, [r1]
	b _080F51BE
	.align 2, 0
_080F5194: .4byte 0x02021C40
_080F5198: .4byte 0x02021C54
_080F519C: .4byte 0x02039CFC
_080F51A0:
	ldr r0, _080F51D0
	adds r1, r4, #0
	adds r1, #0xc
	bl StringCopy
	ldr r0, _080F51D4
	adds r1, r4, #2
	bl StringCopy
	ldr r0, _080F51D8
	ldrh r1, [r4, #0x14]
	bl CopyEasyChatWord
	bl TVShowDone
_080F51BE:
	ldr r0, _080F51DC
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F51D0: .4byte 0x02021C40
_080F51D4: .4byte 0x02021C54
_080F51D8: .4byte 0x02021C68
_080F51DC: .4byte 0x08568DCC
	thumb_func_end DoTVShowTrainerFanClubSpecial

	thumb_func_start DoTVShowTrainerFanClub
DoTVShowTrainerFanClub: @ 0x080F51E0
	push {r4, r5, lr}
	ldr r2, _080F5214
	ldr r0, _080F5218
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F521C
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, _080F5220
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F5224
	ldrb r5, [r0]
	adds r2, r0, #0
	cmp r5, #0xb
	bls _080F5208
	b _080F5358
_080F5208:
	lsls r0, r5, #2
	ldr r1, _080F5228
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F5214: .4byte 0x03005AEC
_080F5218: .4byte 0x02037280
_080F521C: .4byte 0x000027CC
_080F5220: .4byte 0x02037290
_080F5224: .4byte 0x02039CFC
_080F5228: .4byte 0x080F522C
_080F522C: @ jump table
	.4byte _080F525C @ case 0
	.4byte _080F5334 @ case 1
	.4byte _080F5334 @ case 2
	.4byte _080F5334 @ case 3
	.4byte _080F5334 @ case 4
	.4byte _080F5334 @ case 5
	.4byte _080F5334 @ case 6
	.4byte _080F5334 @ case 7
	.4byte _080F5334 @ case 8
	.4byte _080F5334 @ case 9
	.4byte _080F5334 @ case 10
	.4byte _080F533A @ case 11
_080F525C:
	ldr r0, _080F528C
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	adds r0, r4, #0
	adds r0, #0x23
	ldrb r0, [r0]
	lsls r0, r0, #8
	adds r1, r4, #0
	adds r1, #0x22
	ldrb r1, [r1]
	adds r0, r0, r1
	movs r1, #0xa
	bl __umodsi3
	cmp r0, #9
	bls _080F5282
	b _080F5358
_080F5282:
	lsls r0, r0, #2
	ldr r1, _080F5290
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F528C: .4byte 0x02021C40
_080F5290: .4byte 0x080F5294
_080F5294: @ jump table
	.4byte _080F52BC @ case 0
	.4byte _080F52C8 @ case 1
	.4byte _080F52D4 @ case 2
	.4byte _080F52E0 @ case 3
	.4byte _080F52EC @ case 4
	.4byte _080F52F8 @ case 5
	.4byte _080F5304 @ case 6
	.4byte _080F5310 @ case 7
	.4byte _080F531C @ case 8
	.4byte _080F5328 @ case 9
_080F52BC:
	ldr r1, _080F52C4
	movs r0, #1
	strb r0, [r1]
	b _080F5358
	.align 2, 0
_080F52C4: .4byte 0x02039CFC
_080F52C8:
	ldr r1, _080F52D0
	movs r0, #2
	strb r0, [r1]
	b _080F5358
	.align 2, 0
_080F52D0: .4byte 0x02039CFC
_080F52D4:
	ldr r1, _080F52DC
	movs r0, #3
	strb r0, [r1]
	b _080F5358
	.align 2, 0
_080F52DC: .4byte 0x02039CFC
_080F52E0:
	ldr r1, _080F52E8
	movs r0, #4
	strb r0, [r1]
	b _080F5358
	.align 2, 0
_080F52E8: .4byte 0x02039CFC
_080F52EC:
	ldr r1, _080F52F4
	movs r0, #5
	strb r0, [r1]
	b _080F5358
	.align 2, 0
_080F52F4: .4byte 0x02039CFC
_080F52F8:
	ldr r1, _080F5300
	movs r0, #6
	strb r0, [r1]
	b _080F5358
	.align 2, 0
_080F5300: .4byte 0x02039CFC
_080F5304:
	ldr r1, _080F530C
	movs r0, #7
	strb r0, [r1]
	b _080F5358
	.align 2, 0
_080F530C: .4byte 0x02039CFC
_080F5310:
	ldr r1, _080F5318
	movs r0, #8
	strb r0, [r1]
	b _080F5358
	.align 2, 0
_080F5318: .4byte 0x02039CFC
_080F531C:
	ldr r1, _080F5324
	movs r0, #9
	strb r0, [r1]
	b _080F5358
	.align 2, 0
_080F5324: .4byte 0x02039CFC
_080F5328:
	ldr r1, _080F5330
	movs r0, #0xa
	strb r0, [r1]
	b _080F5358
	.align 2, 0
_080F5330: .4byte 0x02039CFC
_080F5334:
	movs r0, #0xb
	strb r0, [r2]
	b _080F5358
_080F533A:
	ldr r0, _080F536C
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F5370
	ldrh r1, [r4, #4]
	bl CopyEasyChatWord
	ldr r0, _080F5374
	ldrh r1, [r4, #6]
	bl CopyEasyChatWord
	bl TVShowDone
_080F5358:
	ldr r0, _080F5378
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F536C: .4byte 0x02021C40
_080F5370: .4byte 0x02021C54
_080F5374: .4byte 0x02021C68
_080F5378: .4byte 0x08568F60
	thumb_func_end DoTVShowTrainerFanClub

	thumb_func_start DoTVShowSpotTheCuties
DoTVShowSpotTheCuties: @ 0x080F537C
	push {r4, r5, lr}
	ldr r2, _080F53AC
	ldr r0, _080F53B0
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F53B4
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, _080F53B8
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F53BC
	ldrb r5, [r0]
	cmp r5, #0xf
	bls _080F53A2
	b _080F5598
_080F53A2:
	lsls r0, r5, #2
	ldr r1, _080F53C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F53AC: .4byte 0x03005AEC
_080F53B0: .4byte 0x02037280
_080F53B4: .4byte 0x000027CC
_080F53B8: .4byte 0x02037290
_080F53BC: .4byte 0x02039CFC
_080F53C0: .4byte 0x080F53C4
_080F53C4: @ jump table
	.4byte _080F5404 @ case 0
	.4byte _080F544C @ case 1
	.4byte _080F544C @ case 2
	.4byte _080F544C @ case 3
	.4byte _080F547C @ case 4
	.4byte _080F557C @ case 5
	.4byte _080F557C @ case 6
	.4byte _080F557C @ case 7
	.4byte _080F557C @ case 8
	.4byte _080F557C @ case 9
	.4byte _080F557C @ case 10
	.4byte _080F557C @ case 11
	.4byte _080F557C @ case 12
	.4byte _080F557C @ case 13
	.4byte _080F557C @ case 14
	.4byte _080F5594 @ case 15
_080F5404:
	ldr r0, _080F5424
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F5428
	adds r1, r4, #4
	bl StringCopy
	ldrb r1, [r4, #2]
	cmp r1, #9
	bhi _080F5430
	ldr r1, _080F542C
	movs r0, #1
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F5424: .4byte 0x02021C40
_080F5428: .4byte 0x02021C54
_080F542C: .4byte 0x02039CFC
_080F5430:
	cmp r1, #0x13
	bhi _080F5440
	ldr r1, _080F543C
	movs r0, #2
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F543C: .4byte 0x02039CFC
_080F5440:
	ldr r1, _080F5448
	movs r0, #3
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F5448: .4byte 0x02039CFC
_080F544C:
	ldr r0, _080F5470
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldr r0, _080F5474
	adds r1, r4, #4
	bl StringCopy
	ldrb r1, [r4, #2]
	movs r0, #2
	bl TV_PrintIntToStringVar
	ldr r1, _080F5478
	movs r0, #4
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F5470: .4byte 0x02021C40
_080F5474: .4byte 0x02021C54
_080F5478: .4byte 0x02039CFC
_080F547C:
	ldr r0, _080F5498
	adds r1, r4, #4
	bl StringCopy
	ldrb r0, [r4, #3]
	cmp r0, #0x18
	bls _080F548C
	b _080F5598
_080F548C:
	lsls r0, r0, #2
	ldr r1, _080F549C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F5498: .4byte 0x02021C54
_080F549C: .4byte 0x080F54A0
_080F54A0: @ jump table
	.4byte _080F5504 @ case 0
	.4byte _080F5510 @ case 1
	.4byte _080F5510 @ case 2
	.4byte _080F5510 @ case 3
	.4byte _080F5510 @ case 4
	.4byte _080F551C @ case 5
	.4byte _080F551C @ case 6
	.4byte _080F551C @ case 7
	.4byte _080F551C @ case 8
	.4byte _080F5528 @ case 9
	.4byte _080F5528 @ case 10
	.4byte _080F5528 @ case 11
	.4byte _080F5528 @ case 12
	.4byte _080F5534 @ case 13
	.4byte _080F5534 @ case 14
	.4byte _080F5534 @ case 15
	.4byte _080F5534 @ case 16
	.4byte _080F5540 @ case 17
	.4byte _080F5540 @ case 18
	.4byte _080F5540 @ case 19
	.4byte _080F5540 @ case 20
	.4byte _080F554C @ case 21
	.4byte _080F5558 @ case 22
	.4byte _080F5564 @ case 23
	.4byte _080F5570 @ case 24
_080F5504:
	ldr r1, _080F550C
	movs r0, #5
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F550C: .4byte 0x02039CFC
_080F5510:
	ldr r1, _080F5518
	movs r0, #6
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F5518: .4byte 0x02039CFC
_080F551C:
	ldr r1, _080F5524
	movs r0, #7
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F5524: .4byte 0x02039CFC
_080F5528:
	ldr r1, _080F5530
	movs r0, #8
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F5530: .4byte 0x02039CFC
_080F5534:
	ldr r1, _080F553C
	movs r0, #9
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F553C: .4byte 0x02039CFC
_080F5540:
	ldr r1, _080F5548
	movs r0, #0xa
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F5548: .4byte 0x02039CFC
_080F554C:
	ldr r1, _080F5554
	movs r0, #0xb
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F5554: .4byte 0x02039CFC
_080F5558:
	ldr r1, _080F5560
	movs r0, #0xc
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F5560: .4byte 0x02039CFC
_080F5564:
	ldr r1, _080F556C
	movs r0, #0xd
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F556C: .4byte 0x02039CFC
_080F5570:
	ldr r1, _080F5578
	movs r0, #0xe
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F5578: .4byte 0x02039CFC
_080F557C:
	ldr r0, _080F558C
	adds r1, r4, #4
	bl StringCopy
	ldr r1, _080F5590
	movs r0, #0xf
	strb r0, [r1]
	b _080F5598
	.align 2, 0
_080F558C: .4byte 0x02021C54
_080F5590: .4byte 0x02039CFC
_080F5594:
	bl TVShowDone
_080F5598:
	ldr r0, _080F55AC
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F55AC: .4byte 0x08568F90
	thumb_func_end DoTVShowSpotTheCuties

	thumb_func_start DoTVShowPokemonNewsBattleFrontier
DoTVShowPokemonNewsBattleFrontier: @ 0x080F55B0
	push {r4, r5, r6, lr}
	ldr r2, _080F55E4
	ldr r0, _080F55E8
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F55EC
	adds r0, r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, _080F55F0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F55F4
	ldrb r6, [r0]
	adds r2, r0, #0
	cmp r6, #0x12
	bls _080F55D8
	b _080F583E
_080F55D8:
	lsls r0, r6, #2
	ldr r1, _080F55F8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F55E4: .4byte 0x03005AEC
_080F55E8: .4byte 0x02037280
_080F55EC: .4byte 0x000027CC
_080F55F0: .4byte 0x02037290
_080F55F4: .4byte 0x02039CFC
_080F55F8: .4byte 0x080F55FC
_080F55FC: @ jump table
	.4byte _080F5648 @ case 0
	.4byte _080F5728 @ case 1
	.4byte _080F56E2 @ case 2
	.4byte _080F5704 @ case 3
	.4byte _080F5704 @ case 4
	.4byte _080F5728 @ case 5
	.4byte _080F5728 @ case 6
	.4byte _080F5728 @ case 7
	.4byte _080F5728 @ case 8
	.4byte _080F5728 @ case 9
	.4byte _080F5728 @ case 10
	.4byte _080F5728 @ case 11
	.4byte _080F5728 @ case 12
	.4byte _080F5728 @ case 13
	.4byte _080F574C @ case 14
	.4byte _080F578C @ case 15
	.4byte _080F57B8 @ case 16
	.4byte _080F5808 @ case 17
	.4byte _080F5830 @ case 18
_080F5648:
	ldrb r0, [r5, #0xd]
	subs r0, #1
	cmp r0, #0xc
	bls _080F5652
	b _080F583E
_080F5652:
	lsls r0, r0, #2
	ldr r1, _080F565C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F565C: .4byte 0x080F5660
_080F5660: @ jump table
	.4byte _080F5694 @ case 0
	.4byte _080F569A @ case 1
	.4byte _080F56A0 @ case 2
	.4byte _080F56A6 @ case 3
	.4byte _080F56AC @ case 4
	.4byte _080F56B2 @ case 5
	.4byte _080F56B8 @ case 6
	.4byte _080F56BE @ case 7
	.4byte _080F56C4 @ case 8
	.4byte _080F56CA @ case 9
	.4byte _080F56D0 @ case 10
	.4byte _080F56D6 @ case 11
	.4byte _080F56DC @ case 12
_080F5694:
	movs r0, #1
	strb r0, [r2]
	b _080F583E
_080F569A:
	movs r0, #2
	strb r0, [r2]
	b _080F583E
_080F56A0:
	movs r0, #3
	strb r0, [r2]
	b _080F583E
_080F56A6:
	movs r0, #4
	strb r0, [r2]
	b _080F583E
_080F56AC:
	movs r0, #5
	strb r0, [r2]
	b _080F583E
_080F56B2:
	movs r0, #6
	strb r0, [r2]
	b _080F583E
_080F56B8:
	movs r0, #7
	strb r0, [r2]
	b _080F583E
_080F56BE:
	movs r0, #8
	strb r0, [r2]
	b _080F583E
_080F56C4:
	movs r0, #9
	strb r0, [r2]
	b _080F583E
_080F56CA:
	movs r0, #0xa
	strb r0, [r2]
	b _080F583E
_080F56D0:
	movs r0, #0xb
	strb r0, [r2]
	b _080F583E
_080F56D6:
	movs r0, #0xc
	strb r0, [r2]
	b _080F583E
_080F56DC:
	movs r0, #0xd
	strb r0, [r2]
	b _080F583E
_080F56E2:
	ldr r0, _080F56FC
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldrh r1, [r5, #2]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldr r1, _080F5700
	movs r0, #0x10
	strb r0, [r1]
	b _080F583E
	.align 2, 0
_080F56FC: .4byte 0x02021C40
_080F5700: .4byte 0x02039CFC
_080F5704:
	ldr r0, _080F5720
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldrh r1, [r5, #2]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldr r1, _080F5724
	movs r0, #0xf
	strb r0, [r1]
	b _080F583E
	.align 2, 0
_080F5720: .4byte 0x02021C40
_080F5724: .4byte 0x02039CFC
_080F5728:
	ldr r0, _080F5744
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldrh r1, [r5, #2]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldr r1, _080F5748
	movs r0, #0xe
	strb r0, [r1]
	b _080F583E
	.align 2, 0
_080F5744: .4byte 0x02021C40
_080F5748: .4byte 0x02039CFC
_080F574C:
	ldr r0, _080F577C
	ldrh r2, [r5, #4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r4, _080F5780
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F5784
	ldrh r2, [r5, #6]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F5788
	ldrh r2, [r5, #8]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	b _080F5816
	.align 2, 0
_080F577C: .4byte 0x02021C40
_080F5780: .4byte 0x082EA31C
_080F5784: .4byte 0x02021C54
_080F5788: .4byte 0x02021C68
_080F578C:
	ldr r0, _080F57AC
	ldrh r2, [r5, #4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r4, _080F57B0
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F57B4
	ldrh r2, [r5, #6]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	b _080F5816
	.align 2, 0
_080F57AC: .4byte 0x02021C40
_080F57B0: .4byte 0x082EA31C
_080F57B4: .4byte 0x02021C54
_080F57B8:
	ldr r0, _080F57F4
	ldrh r2, [r5, #4]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r4, _080F57F8
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F57FC
	ldrh r2, [r5, #6]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	bl StringCopy
	ldr r0, _080F5800
	ldrh r2, [r5, #8]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	adds r1, r1, r4
	bl StringCopy
	ldr r1, _080F5804
	movs r0, #0x11
	strb r0, [r1]
	b _080F583E
	.align 2, 0
_080F57F4: .4byte 0x02021C40
_080F57F8: .4byte 0x082EA31C
_080F57FC: .4byte 0x02021C54
_080F5800: .4byte 0x02021C68
_080F5804: .4byte 0x02039CFC
_080F5808:
	ldr r0, _080F5824
	ldrh r2, [r5, #0xa]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r2, _080F5828
	adds r1, r1, r2
_080F5816:
	bl StringCopy
	ldr r1, _080F582C
	movs r0, #0x12
	strb r0, [r1]
	b _080F583E
	.align 2, 0
_080F5824: .4byte 0x02021C40
_080F5828: .4byte 0x082EA31C
_080F582C: .4byte 0x02039CFC
_080F5830:
	ldr r0, _080F5850
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	bl TVShowDone
_080F583E:
	ldr r0, _080F5854
	lsls r1, r6, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F5850: .4byte 0x02021C40
_080F5854: .4byte 0x08568FD0
	thumb_func_end DoTVShowPokemonNewsBattleFrontier

	thumb_func_start DoTVShowWhatsNo1InHoennToday
DoTVShowWhatsNo1InHoennToday: @ 0x080F5858
	push {r4, r5, lr}
	ldr r2, _080F5888
	ldr r0, _080F588C
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F5890
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, _080F5894
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F5898
	ldrb r5, [r0]
	cmp r5, #8
	bls _080F587E
	b _080F598A
_080F587E:
	lsls r0, r5, #2
	ldr r1, _080F589C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F5888: .4byte 0x03005AEC
_080F588C: .4byte 0x02037280
_080F5890: .4byte 0x000027CC
_080F5894: .4byte 0x02037290
_080F5898: .4byte 0x02039CFC
_080F589C: .4byte 0x080F58A0
_080F58A0: @ jump table
	.4byte _080F58C4 @ case 0
	.4byte _080F5958 @ case 1
	.4byte _080F5958 @ case 2
	.4byte _080F5958 @ case 3
	.4byte _080F5958 @ case 4
	.4byte _080F5958 @ case 5
	.4byte _080F5958 @ case 6
	.4byte _080F5958 @ case 7
	.4byte _080F597C @ case 8
_080F58C4:
	ldr r0, _080F58E0
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r0, [r4, #4]
	cmp r0, #6
	bhi _080F598A
	lsls r0, r0, #2
	ldr r1, _080F58E4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F58E0: .4byte 0x02021C40
_080F58E4: .4byte 0x080F58E8
_080F58E8: @ jump table
	.4byte _080F5904 @ case 0
	.4byte _080F5910 @ case 1
	.4byte _080F591C @ case 2
	.4byte _080F5928 @ case 3
	.4byte _080F5934 @ case 4
	.4byte _080F5940 @ case 5
	.4byte _080F594C @ case 6
_080F5904:
	ldr r1, _080F590C
	movs r0, #1
	strb r0, [r1]
	b _080F598A
	.align 2, 0
_080F590C: .4byte 0x02039CFC
_080F5910:
	ldr r1, _080F5918
	movs r0, #2
	strb r0, [r1]
	b _080F598A
	.align 2, 0
_080F5918: .4byte 0x02039CFC
_080F591C:
	ldr r1, _080F5924
	movs r0, #3
	strb r0, [r1]
	b _080F598A
	.align 2, 0
_080F5924: .4byte 0x02039CFC
_080F5928:
	ldr r1, _080F5930
	movs r0, #4
	strb r0, [r1]
	b _080F598A
	.align 2, 0
_080F5930: .4byte 0x02039CFC
_080F5934:
	ldr r1, _080F593C
	movs r0, #5
	strb r0, [r1]
	b _080F598A
	.align 2, 0
_080F593C: .4byte 0x02039CFC
_080F5940:
	ldr r1, _080F5948
	movs r0, #6
	strb r0, [r1]
	b _080F598A
	.align 2, 0
_080F5948: .4byte 0x02039CFC
_080F594C:
	ldr r1, _080F5954
	movs r0, #7
	strb r0, [r1]
	b _080F598A
	.align 2, 0
_080F5954: .4byte 0x02039CFC
_080F5958:
	ldr r0, _080F5974
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrh r1, [r4, #2]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldr r1, _080F5978
	movs r0, #8
	strb r0, [r1]
	b _080F598A
	.align 2, 0
_080F5974: .4byte 0x02021C40
_080F5978: .4byte 0x02039CFC
_080F597C:
	ldr r0, _080F599C
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	bl TVShowDone
_080F598A:
	ldr r0, _080F59A0
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F599C: .4byte 0x02021C40
_080F59A0: .4byte 0x0856901C
	thumb_func_end DoTVShowWhatsNo1InHoennToday

	thumb_func_start sub_080F59A4
sub_080F59A4: @ 0x080F59A4
	push {r4, lr}
	movs r1, #0
	movs r2, #0
	ldr r3, [r0, #0xc]
	movs r4, #1
_080F59AE:
	adds r0, r3, #0
	lsrs r0, r1
	ands r0, r4
	cmp r0, #0
	beq _080F59BE
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
_080F59BE:
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x1f
	bls _080F59AE
	adds r0, r2, #0
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_080F59A4

	thumb_func_start SecretBaseSecrets_GetStateForFlagNumber
SecretBaseSecrets_GetStateForFlagNumber: @ 0x080F59D0
	push {r4, r5, r6, lr}
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r2, #0
	movs r3, #0
	ldr r1, [r0, #0xc]
	movs r5, #1
	ldr r6, _080F59F4
_080F59E0:
	adds r0, r1, #0
	lsrs r0, r2
	ands r0, r5
	cmp r0, #0
	beq _080F59FE
	cmp r3, r4
	bne _080F59F8
	adds r0, r2, r6
	ldrb r0, [r0]
	b _080F5A0A
	.align 2, 0
_080F59F4: .4byte 0x0856913C
_080F59F8:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_080F59FE:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0x1f
	bls _080F59E0
	movs r0, #0
_080F5A0A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	thumb_func_end SecretBaseSecrets_GetStateForFlagNumber

	thumb_func_start DoTVShowSecretBaseSecrets
DoTVShowSecretBaseSecrets: @ 0x080F5A10
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	ldr r2, _080F5A4C
	ldr r0, _080F5A50
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F5A54
	adds r0, r0, r1
	ldr r1, [r2]
	adds r5, r1, r0
	ldr r1, _080F5A58
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F5A5C
	ldrb r2, [r0]
	mov sb, r2
	adds r2, r0, #0
	mov r0, sb
	cmp r0, #0x2b
	bls _080F5A42
	b _080F5D36
_080F5A42:
	lsls r0, r0, #2
	ldr r1, _080F5A60
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F5A4C: .4byte 0x03005AEC
_080F5A50: .4byte 0x02037280
_080F5A54: .4byte 0x000027CC
_080F5A58: .4byte 0x02037290
_080F5A5C: .4byte 0x02039CFC
_080F5A60: .4byte 0x080F5A64
_080F5A64: @ jump table
	.4byte _080F5B14 @ case 0
	.4byte _080F5B68 @ case 1
	.4byte _080F5BE0 @ case 2
	.4byte _080F5C5C @ case 3
	.4byte _080F5CAC @ case 4
	.4byte _080F5CAC @ case 5
	.4byte _080F5CAC @ case 6
	.4byte _080F5CD4 @ case 7
	.4byte _080F5CF4 @ case 8
	.4byte _080F5CF8 @ case 9
	.4byte _080F5D32 @ case 10
	.4byte _080F5D32 @ case 11
	.4byte _080F5D32 @ case 12
	.4byte _080F5D32 @ case 13
	.4byte _080F5D32 @ case 14
	.4byte _080F5D32 @ case 15
	.4byte _080F5D32 @ case 16
	.4byte _080F5D32 @ case 17
	.4byte _080F5D32 @ case 18
	.4byte _080F5CFC @ case 19
	.4byte _080F5D1C @ case 20
	.4byte _080F5D32 @ case 21
	.4byte _080F5D32 @ case 22
	.4byte _080F5D32 @ case 23
	.4byte _080F5D32 @ case 24
	.4byte _080F5D32 @ case 25
	.4byte _080F5D32 @ case 26
	.4byte _080F5D32 @ case 27
	.4byte _080F5D32 @ case 28
	.4byte _080F5D32 @ case 29
	.4byte _080F5D32 @ case 30
	.4byte _080F5D32 @ case 31
	.4byte _080F5D32 @ case 32
	.4byte _080F5D32 @ case 33
	.4byte _080F5D32 @ case 34
	.4byte _080F5D32 @ case 35
	.4byte _080F5D32 @ case 36
	.4byte _080F5D32 @ case 37
	.4byte _080F5D32 @ case 38
	.4byte _080F5D32 @ case 39
	.4byte _080F5D32 @ case 40
	.4byte _080F5D32 @ case 41
	.4byte _080F5D32 @ case 42
	.4byte _080F5D32 @ case 43
_080F5B14:
	ldr r0, _080F5B3C
	adds r1, r5, #4
	bl StringCopy
	ldr r0, _080F5B40
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	adds r0, r5, #0
	bl sub_080F59A4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _080F5B48
	ldr r1, _080F5B44
	movs r0, #8
	strb r0, [r1]
	b _080F5D36
	.align 2, 0
_080F5B3C: .4byte 0x02021C40
_080F5B40: .4byte 0x02021C54
_080F5B44: .4byte 0x02039CFC
_080F5B48:
	movs r0, #1
	strb r0, [r5, #0x12]
	bl Random
	ldr r4, _080F5B64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl __modsi3
	strb r0, [r4]
	ldrb r1, [r4]
	b _080F5C42
	.align 2, 0
_080F5B64: .4byte 0x02039CFD
_080F5B68:
	ldr r0, _080F5B88
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	adds r0, r5, #0
	bl sub_080F59A4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #1
	beq _080F5BF8
	cmp r6, #2
	beq _080F5B8C
	movs r4, #0
	b _080F5BA6
	.align 2, 0
_080F5B88: .4byte 0x02021C54
_080F5B8C:
	strb r6, [r5, #0x12]
	ldr r0, _080F5B9C
	ldrb r0, [r0]
	cmp r0, #0
	bne _080F5BA0
	adds r0, r5, #0
	movs r1, #1
	b _080F5C44
	.align 2, 0
_080F5B9C: .4byte 0x02039CFD
_080F5BA0:
	adds r0, r5, #0
	movs r1, #0
	b _080F5C44
_080F5BA6:
	bl Random
	ldr r7, _080F5BD8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl __modsi3
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r7]
	cmp r0, r1
	bne _080F5BCE
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	ldr r0, _080F5BDC
	cmp r4, r0
	bls _080F5BA6
_080F5BCE:
	movs r0, #2
	strb r0, [r5, #0x12]
	ldrb r1, [r7, #1]
	b _080F5C42
	.align 2, 0
_080F5BD8: .4byte 0x02039CFD
_080F5BDC: .4byte 0x0000FFFE
_080F5BE0:
	ldr r0, _080F5C00
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	adds r0, r5, #0
	bl sub_080F59A4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #2
	bne _080F5C08
_080F5BF8:
	ldr r1, _080F5C04
	movs r0, #9
	strb r0, [r1]
	b _080F5D36
	.align 2, 0
_080F5C00: .4byte 0x02021C54
_080F5C04: .4byte 0x02039CFC
_080F5C08:
	movs r4, #0
	ldr r7, _080F5C50
	ldr r2, _080F5C54
	mov r8, r2
_080F5C10:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl __modsi3
	strb r0, [r7, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r7]
	cmp r0, r1
	beq _080F5C30
	ldrb r2, [r7, #1]
	cmp r0, r2
	bne _080F5C3A
_080F5C30:
	adds r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, r8
	bls _080F5C10
_080F5C3A:
	movs r0, #3
	strb r0, [r5, #0x12]
	ldr r0, _080F5C50
	ldrb r1, [r0, #2]
_080F5C42:
	adds r0, r5, #0
_080F5C44:
	bl SecretBaseSecrets_GetStateForFlagNumber
	ldr r1, _080F5C58
	strb r0, [r1]
	b _080F5D36
	.align 2, 0
_080F5C50: .4byte 0x02039CFD
_080F5C54: .4byte 0x0000FFFE
_080F5C58: .4byte 0x02039CFC
_080F5C5C:
	ldr r0, _080F5C84
	adds r1, r5, #4
	bl StringCopy
	ldr r0, _080F5C88
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldrh r1, [r5, #2]
	movs r0, #2
	bl TV_PrintIntToStringVar
	ldrh r0, [r5, #2]
	cmp r0, #0x1e
	bhi _080F5C90
	ldr r1, _080F5C8C
	movs r0, #4
	strb r0, [r1]
	b _080F5D36
	.align 2, 0
_080F5C84: .4byte 0x02021C40
_080F5C88: .4byte 0x02021C54
_080F5C8C: .4byte 0x02039CFC
_080F5C90:
	cmp r0, #0x64
	bhi _080F5CA0
	ldr r1, _080F5C9C
	movs r0, #5
	strb r0, [r1]
	b _080F5D36
	.align 2, 0
_080F5C9C: .4byte 0x02039CFC
_080F5CA0:
	ldr r1, _080F5CA8
	movs r0, #6
	strb r0, [r1]
	b _080F5D36
	.align 2, 0
_080F5CA8: .4byte 0x02039CFC
_080F5CAC:
	ldr r0, _080F5CC8
	adds r1, r5, #4
	bl StringCopy
	ldr r0, _080F5CCC
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	ldr r1, _080F5CD0
	movs r0, #7
	strb r0, [r1]
	b _080F5D36
	.align 2, 0
_080F5CC8: .4byte 0x02021C40
_080F5CCC: .4byte 0x02021C54
_080F5CD0: .4byte 0x02039CFC
_080F5CD4:
	ldr r0, _080F5CEC
	adds r1, r5, #4
	bl StringCopy
	ldr r0, _080F5CF0
	adds r1, r5, #0
	adds r1, #0x13
	bl StringCopy
	bl TVShowDone
	b _080F5D36
	.align 2, 0
_080F5CEC: .4byte 0x02021C40
_080F5CF0: .4byte 0x02021C54
_080F5CF4:
	movs r0, #3
	b _080F5D34
_080F5CF8:
	movs r0, #3
	b _080F5D34
_080F5CFC:
	ldr r4, _080F5D14
	ldrh r0, [r5, #0x10]
	bl ItemId_GetName
	adds r1, r0, #0
	adds r0, r4, #0
	bl StringCopy
	ldr r1, _080F5D18
	ldrb r0, [r5, #0x12]
	strb r0, [r1]
	b _080F5D36
	.align 2, 0
_080F5D14: .4byte 0x02021C54
_080F5D18: .4byte 0x02039CFC
_080F5D1C:
	adds r0, r5, #0
	adds r0, #0x22
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080F5D2E
	movs r0, #0x16
	b _080F5D34
_080F5D2E:
	movs r0, #0x15
	b _080F5D34
_080F5D32:
	ldrb r0, [r5, #0x12]
_080F5D34:
	strb r0, [r2]
_080F5D36:
	ldr r0, _080F5D50
	mov r2, sb
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080F5D50: .4byte 0x08569040
	thumb_func_end DoTVShowSecretBaseSecrets

	thumb_func_start DoTVShowSafariFanClub
DoTVShowSafariFanClub: @ 0x080F5D54
	push {r4, r5, lr}
	ldr r2, _080F5D88
	ldr r0, _080F5D8C
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F5D90
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, _080F5D94
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080F5D98
	ldrb r5, [r0]
	adds r2, r0, #0
	cmp r5, #0xa
	bls _080F5D7C
	b _080F5EB8
_080F5D7C:
	lsls r0, r5, #2
	ldr r1, _080F5D9C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080F5D88: .4byte 0x03005AEC
_080F5D8C: .4byte 0x02037280
_080F5D90: .4byte 0x000027CC
_080F5D94: .4byte 0x02037290
_080F5D98: .4byte 0x02039CFC
_080F5D9C: .4byte 0x080F5DA0
_080F5DA0: @ jump table
	.4byte _080F5DCC @ case 0
	.4byte _080F5DE8 @ case 1
	.4byte _080F5E1C @ case 2
	.4byte _080F5E30 @ case 3
	.4byte _080F5E9A @ case 4
	.4byte _080F5E36 @ case 5
	.4byte _080F5E54 @ case 6
	.4byte _080F5E80 @ case 7
	.4byte _080F5E94 @ case 8
	.4byte _080F5E9A @ case 9
	.4byte _080F5EB4 @ case 10
_080F5DCC:
	ldrb r1, [r4, #2]
	cmp r1, #0
	bne _080F5DD8
	movs r0, #6
	strb r0, [r2]
	b _080F5EB8
_080F5DD8:
	cmp r1, #3
	bhi _080F5DE2
	movs r0, #5
	strb r0, [r2]
	b _080F5EB8
_080F5DE2:
	movs r0, #1
	strb r0, [r2]
	b _080F5EB8
_080F5DE8:
	ldr r0, _080F5E08
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r1, [r4, #2]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldrb r0, [r4, #3]
	cmp r0, #0
	bne _080F5E10
	ldr r1, _080F5E0C
	movs r0, #3
	strb r0, [r1]
	b _080F5EB8
	.align 2, 0
_080F5E08: .4byte 0x02021C40
_080F5E0C: .4byte 0x02039CFC
_080F5E10:
	ldr r1, _080F5E18
	movs r0, #2
	strb r0, [r1]
	b _080F5EB8
	.align 2, 0
_080F5E18: .4byte 0x02039CFC
_080F5E1C:
	ldrb r1, [r4, #3]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldr r1, _080F5E2C
	movs r0, #4
	strb r0, [r1]
	b _080F5EB8
	.align 2, 0
_080F5E2C: .4byte 0x02039CFC
_080F5E30:
	movs r0, #4
	strb r0, [r2]
	b _080F5EB8
_080F5E36:
	ldr r0, _080F5E50
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r1, [r4, #2]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _080F5E64
	b _080F5E74
	.align 2, 0
_080F5E50: .4byte 0x02021C40
_080F5E54:
	ldr r0, _080F5E6C
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldrb r0, [r4, #3]
	cmp r0, #0
	bne _080F5E74
_080F5E64:
	ldr r1, _080F5E70
	movs r0, #8
	strb r0, [r1]
	b _080F5EB8
	.align 2, 0
_080F5E6C: .4byte 0x02021C40
_080F5E70: .4byte 0x02039CFC
_080F5E74:
	ldr r1, _080F5E7C
	movs r0, #7
	strb r0, [r1]
	b _080F5EB8
	.align 2, 0
_080F5E7C: .4byte 0x02039CFC
_080F5E80:
	ldrb r1, [r4, #3]
	movs r0, #1
	bl TV_PrintIntToStringVar
	ldr r1, _080F5E90
	movs r0, #9
	strb r0, [r1]
	b _080F5EB8
	.align 2, 0
_080F5E90: .4byte 0x02039CFC
_080F5E94:
	movs r0, #9
	strb r0, [r2]
	b _080F5EB8
_080F5E9A:
	ldr r0, _080F5EAC
	adds r1, r4, #0
	adds r1, #0x13
	bl StringCopy
	ldr r1, _080F5EB0
	movs r0, #0xa
	strb r0, [r1]
	b _080F5EB8
	.align 2, 0
_080F5EAC: .4byte 0x02021C40
_080F5EB0: .4byte 0x02039CFC
_080F5EB4:
	bl TVShowDone
_080F5EB8:
	ldr r0, _080F5ECC
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080F5ECC: .4byte 0x085690EC
	thumb_func_end DoTVShowSafariFanClub

	thumb_func_start DoTVShowPokemonContestLiveUpdates2
DoTVShowPokemonContestLiveUpdates2: @ 0x080F5ED0
	push {r4, r5, r6, lr}
	ldr r2, _080F5F00
	ldr r0, _080F5F04
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r1, _080F5F08
	adds r0, r0, r1
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r1, _080F5F0C
	movs r0, #0
	strh r0, [r1]
	ldr r6, _080F5F10
	ldrb r5, [r6]
	cmp r5, #2
	bgt _080F5F14
	cmp r5, #1
	bge _080F5F40
	cmp r5, #0
	beq _080F5F1A
	b _080F5F56
	.align 2, 0
_080F5F00: .4byte 0x03005AEC
_080F5F04: .4byte 0x02037280
_080F5F08: .4byte 0x000027CC
_080F5F0C: .4byte 0x02037290
_080F5F10: .4byte 0x02039CFC
_080F5F14:
	cmp r5, #3
	beq _080F5F48
	b _080F5F56
_080F5F1A:
	ldr r0, _080F5F2C
	ldrb r1, [r4, #0xa]
	bl sub_0818E4C4
	ldrb r1, [r4, #0x16]
	cmp r1, #1
	bne _080F5F30
	strb r1, [r6]
	b _080F5F56
	.align 2, 0
_080F5F2C: .4byte 0x02021C40
_080F5F30:
	cmp r1, #0
	bne _080F5F3A
	movs r0, #2
	strb r0, [r6]
	b _080F5F56
_080F5F3A:
	movs r0, #3
	strb r0, [r6]
	b _080F5F56
_080F5F40:
	ldr r0, _080F5F68
	adds r1, r4, #2
	bl StringCopy7
_080F5F48:
	ldr r0, _080F5F6C
	adds r1, r4, #0
	adds r1, #0xb
	bl StringCopy10
	bl TVShowDone
_080F5F56:
	ldr r0, _080F5F70
	lsls r1, r5, #2
	adds r1, r1, r0
	ldr r0, [r1]
	bl ShowFieldMessage
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080F5F68: .4byte 0x02021C68
_080F5F6C: .4byte 0x02021C54
_080F5F70: .4byte 0x08568E30
	thumb_func_end DoTVShowPokemonContestLiveUpdates2

	thumb_func_start TVShowDone
TVShowDone: @ 0x080F5F74
	ldr r1, _080F5F9C
	movs r0, #1
	strh r0, [r1]
	ldr r1, _080F5FA0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080F5FA4
	ldr r2, [r0]
	ldr r0, _080F5FA8
	ldrh r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r0, _080F5FAC
	adds r2, r2, r0
	movs r0, #0
	strb r0, [r2]
	bx lr
	.align 2, 0
_080F5F9C: .4byte 0x02037290
_080F5FA0: .4byte 0x02039CFC
_080F5FA4: .4byte 0x03005AEC
_080F5FA8: .4byte 0x02037280
_080F5FAC: .4byte 0x000027CD
	thumb_func_end TVShowDone

	thumb_func_start ResetTVShowState
ResetTVShowState: @ 0x080F5FB0
	ldr r1, _080F5FB8
	movs r0, #0
	strb r0, [r1]
	bx lr
	.align 2, 0
_080F5FB8: .4byte 0x02039CFC
	thumb_func_end ResetTVShowState
