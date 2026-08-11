.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start sub_08196294
sub_08196294: @ 0x08196294
	push {lr}
	sub sp, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	ldr r0, _08196304
	adds r2, r1, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #8
	ble _081962FC
	movs r1, #0
	strh r1, [r2]
	ldrh r0, [r2, #2]
	adds r0, #1
	strh r0, [r2, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #7
	ble _081962C8
	strh r1, [r2, #2]
_081962C8:
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r1, r1, #4
	ldr r0, _08196308
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldr r2, _0819630C
	adds r0, r2, #0
	orrs r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #4
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x11
	str r0, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	movs r0, #0
	movs r2, #1
	movs r3, #0xf
	bl WriteSequenceToBgTilemapBuffer
	movs r0, #0
	bl CopyBgTilemapBufferToVram
_081962FC:
	add sp, #0x10
	pop {r0}
	bx r0
	.align 2, 0
_08196304: .4byte 0x03005B68
_08196308: .4byte 0x00000279
_0819630C: .4byte 0xFFFFF000
	thumb_func_end sub_08196294

	thumb_func_start TrainerIsEligibleForRematch
TrainerIsEligibleForRematch: @ 0x08196310
	ldr r1, _08196324
	ldr r1, [r1]
	ldr r2, _08196328
	adds r1, r1, r2
	adds r1, r1, r0
	ldrb r1, [r1]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	bx lr
	.align 2, 0
_08196324: .4byte 0x03005AEC
_08196328: .4byte 0x000009CA
	thumb_func_end TrainerIsEligibleForRematch

	thumb_func_start GetRematchTrainerLocation
GetRematchTrainerLocation: @ 0x0819632C
	push {lr}
	ldr r1, _08196344
	lsls r0, r0, #4
	adds r0, r0, r1
	ldrh r2, [r0, #0xa]
	ldrh r1, [r0, #0xc]
	adds r0, r2, #0
	bl Overworld_GetMapHeaderByGroupAndId
	ldrb r0, [r0, #0x14]
	pop {r1}
	bx r1
	.align 2, 0
_08196344: .4byte 0x0852AD40
	thumb_func_end GetRematchTrainerLocation

	thumb_func_start GetNumRematchTrainersFought
GetNumRematchTrainersFought: @ 0x08196348
	push {r4, r5, r6, lr}
	movs r5, #0
	movs r6, #0
	ldr r4, _08196370
_08196350:
	ldrh r0, [r4]
	bl HasTrainerBeenFought
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819635E
	adds r6, #1
_0819635E:
	adds r4, #0x10
	adds r5, #1
	cmp r5, #0x3f
	bls _08196350
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08196370: .4byte 0x0852AD40
	thumb_func_end GetNumRematchTrainersFought

	thumb_func_start sub_08196374
sub_08196374: @ 0x08196374
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r4, #0
	movs r6, #0
	ldr r5, _08196394
_0819637E:
	ldrh r0, [r5]
	bl HasTrainerBeenFought
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819639A
	cmp r6, r7
	bne _08196398
	adds r0, r4, #0
	b _081963A4
	.align 2, 0
_08196394: .4byte 0x0852AD40
_08196398:
	adds r6, #1
_0819639A:
	adds r5, #0x10
	adds r4, #1
	cmp r4, #0x4d
	bls _0819637E
	movs r0, #0x4e
_081963A4:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08196374

	thumb_func_start SelectMatchCallMessage
SelectMatchCallMessage: @ 0x081963AC
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	movs r7, #0
	bl GetTrainerMatchCallId
	adds r5, r0, #0
	ldr r0, _081963E4
	strh r7, [r0]
	adds r0, r5, #0
	bl TrainerIsEligibleForRematch
	cmp r0, #0
	beq _081963EC
	adds r0, r5, #0
	bl GetRematchTrainerLocation
	ldr r1, _081963E8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r1, #0x14]
	cmp r0, r1
	bne _081963EC
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetSameRouteMatchCallText
	b _08196430
	.align 2, 0
_081963E4: .4byte 0x0203CA54
_081963E8: .4byte 0x02036FB8
_081963EC:
	adds r0, r5, #0
	bl sub_08196968
	cmp r0, #0
	beq _0819640A
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetDifferentRouteMatchCallText
	adds r4, r0, #0
	movs r7, #1
	adds r0, r5, #0
	bl UpdateRematchIfDefeated
	b _08196432
_0819640A:
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08196428
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetBattleMatchCallText
	b _08196430
_08196428:
	adds r0, r5, #0
	adds r1, r6, #0
	bl GetGeneralMatchCallText
_08196430:
	adds r4, r0, #0
_08196432:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl BuildMatchCallString
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end SelectMatchCallMessage

	thumb_func_start GetTrainerMatchCallId
GetTrainerMatchCallId: @ 0x08196444
	push {lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r1, _08196458
_0819644C:
	ldrh r0, [r1]
	cmp r0, r3
	beq _0819645C
	adds r1, #0x14
	adds r2, #1
	b _0819644C
	.align 2, 0
_08196458: .4byte 0x085D6934
_0819645C:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetTrainerMatchCallId

	thumb_func_start GetSameRouteMatchCallText
GetSameRouteMatchCallText: @ 0x08196464
	ldr r2, _08196488
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1, #0xe]
	movs r2, #0xff
	lsrs r0, r1, #8
	subs r0, #1
	ands r1, r2
	subs r1, #1
	ldr r2, _0819648C
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r1, r1, #3
	ldr r0, [r0]
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08196488: .4byte 0x085D6934
_0819648C: .4byte 0x085D74A8
	thumb_func_end GetSameRouteMatchCallText

	thumb_func_start GetDifferentRouteMatchCallText
GetDifferentRouteMatchCallText: @ 0x08196490
	ldr r2, _081964B4
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r1, [r1, #0x10]
	movs r2, #0xff
	lsrs r0, r1, #8
	subs r0, #1
	ands r1, r2
	subs r1, #1
	ldr r2, _081964B8
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r1, r1, #3
	ldr r0, [r0]
	adds r0, r0, r1
	bx lr
	.align 2, 0
_081964B4: .4byte 0x085D6934
_081964B8: .4byte 0x085D74A8
	thumb_func_end GetDifferentRouteMatchCallText

	thumb_func_start GetBattleMatchCallText
GetBattleMatchCallText: @ 0x081964BC
	push {r4, lr}
	adds r4, r0, #0
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #3
	bl __umodsi3
	lsls r0, r0, #0x10
	ldr r2, _08196508
	lsrs r0, r0, #0xf
	lsls r1, r4, #2
	adds r1, r1, r4
	lsls r1, r1, #2
	adds r0, r0, r1
	adds r2, #4
	adds r0, r0, r2
	ldrh r4, [r0]
	cmp r4, #0
	bne _081964EC
	movs r0, #0
	bl SpriteCallbackDummy
_081964EC:
	movs r1, #0xff
	lsrs r0, r4, #8
	subs r0, #1
	ands r4, r1
	subs r1, r4, #1
	ldr r2, _0819650C
	lsls r0, r0, #2
	adds r0, r0, r2
	lsls r1, r1, #3
	ldr r0, [r0]
	adds r0, r0, r1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08196508: .4byte 0x085D6934
_0819650C: .4byte 0x085D749C
	thumb_func_end GetBattleMatchCallText

	thumb_func_start GetGeneralMatchCallText
GetGeneralMatchCallText: @ 0x08196510
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _081965AC
	movs r5, #0
	movs r4, #0
	lsls r7, r6, #2
_0819652C:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl GetFrontierStreakInfo
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _08196540
	adds r5, #1
_08196540:
	adds r4, #1
	cmp r4, #6
	ble _0819652C
	cmp r5, #0
	beq _081965AC
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r5, #0
	bl __modsi3
	adds r5, r0, #0
	movs r4, #0
	b _08196562
_0819655E:
	subs r5, #1
_08196560:
	adds r4, #1
_08196562:
	cmp r4, #6
	bgt _08196580
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	mov r1, sp
	bl GetFrontierStreakInfo
	ldr r1, _081965A0
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _08196560
	cmp r5, #0
	bne _0819655E
_08196580:
	ldr r0, _081965A0
	strh r4, [r0]
	ldr r1, _081965A4
	adds r0, r7, r6
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #0xc]
	subs r2, r0, #1
	ldr r1, _081965A8
	ldr r0, [sp]
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r1, r2, #3
	ldr r0, [r0]
	adds r0, r0, r1
	b _081965D0
	.align 2, 0
_081965A0: .4byte 0x0203CA54
_081965A4: .4byte 0x085D6934
_081965A8: .4byte 0x085D74B0
_081965AC:
	ldr r1, _081965D8
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrh r2, [r0, #0xa]
	lsrs r1, r2, #8
	subs r1, #1
	str r1, [sp]
	movs r0, #0xff
	ands r0, r2
	subs r2, r0, #1
	ldr r0, _081965DC
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r2, r2, #3
	ldr r0, [r1]
	adds r0, r0, r2
_081965D0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081965D8: .4byte 0x085D6934
_081965DC: .4byte 0x085D74B0
	thumb_func_end GetGeneralMatchCallText

	thumb_func_start BuildMatchCallString
BuildMatchCallString: @ 0x081965E0
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	adds r1, r4, #4
	bl PopulateMatchCallStringVars
	ldr r1, [r4]
	adds r0, r5, #0
	bl StringExpandPlaceholders
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end BuildMatchCallString

	thumb_func_start PopulateMatchCallStringVars
PopulateMatchCallStringVars: @ 0x081965FC
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	movs r4, #0
	ldr r5, _08196628
_08196606:
	adds r1, r6, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _0819661A
	adds r1, r0, #0
	ldr r2, [r5]
	adds r0, r7, #0
	bl PopulateMatchCallStringVar
_0819661A:
	adds r5, #4
	adds r4, #1
	cmp r4, #2
	ble _08196606
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196628: .4byte 0x085D7A1C
	thumb_func_end PopulateMatchCallStringVars

	thumb_func_start PopulateMatchCallStringVar
PopulateMatchCallStringVar: @ 0x0819662C
	push {lr}
	ldr r3, _08196640
	lsls r1, r1, #2
	adds r1, r1, r3
	ldr r3, [r1]
	adds r1, r2, #0
	bl _call_via_r3
	pop {r0}
	bx r0
	.align 2, 0
_08196640: .4byte 0x085D7A28
	thumb_func_end PopulateMatchCallStringVar

	thumb_func_start PopulateTrainerName
PopulateTrainerName: @ 0x08196644
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	ldr r2, _08196670
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r4, [r1]
	movs r3, #0
	ldr r1, _08196674
	adds r6, r1, #0
_0819665A:
	lsls r2, r3, #3
	ldrh r0, [r1]
	cmp r0, r4
	bne _08196678
	adds r0, r6, #4
	adds r0, r2, r0
	ldr r1, [r0]
	adds r0, r5, #0
	bl StringCopy
	b _0819668C
	.align 2, 0
_08196670: .4byte 0x085D6934
_08196674: .4byte 0x085D7A54
_08196678:
	adds r1, #8
	adds r3, #1
	cmp r3, #5
	bls _0819665A
	lsls r1, r4, #5
	ldr r0, _08196694
	adds r1, r1, r0
	adds r0, r5, #0
	bl StringCopy
_0819668C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08196694: .4byte 0x082E3840
	thumb_func_end PopulateTrainerName

	thumb_func_start PopulateMapName
PopulateMapName: @ 0x08196698
	push {r4, lr}
	adds r4, r1, #0
	bl GetRematchTrainerLocation
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	movs r2, #0
	bl GetMapName
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end PopulateMapName

	thumb_func_start GetLandEncounterSlot
GetLandEncounterSlot: @ 0x081966B4
	push {lr}
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x13
	bgt _081966D0
	movs r0, #0
	b _08196746
_081966D0:
	adds r0, r1, #0
	subs r0, #0x14
	cmp r0, #0x13
	bhi _081966DC
	movs r0, #1
	b _08196746
_081966DC:
	adds r0, r1, #0
	subs r0, #0x28
	cmp r0, #9
	bhi _081966E8
	movs r0, #2
	b _08196746
_081966E8:
	adds r0, r1, #0
	subs r0, #0x32
	cmp r0, #9
	bhi _081966F4
	movs r0, #3
	b _08196746
_081966F4:
	adds r0, r1, #0
	subs r0, #0x3c
	cmp r0, #9
	bhi _08196700
	movs r0, #4
	b _08196746
_08196700:
	adds r0, r1, #0
	subs r0, #0x46
	cmp r0, #9
	bhi _0819670C
	movs r0, #5
	b _08196746
_0819670C:
	adds r0, r1, #0
	subs r0, #0x50
	cmp r0, #4
	bhi _08196718
	movs r0, #6
	b _08196746
_08196718:
	adds r0, r1, #0
	subs r0, #0x55
	cmp r0, #4
	bhi _08196724
	movs r0, #7
	b _08196746
_08196724:
	adds r0, r1, #0
	subs r0, #0x5a
	cmp r0, #3
	bhi _08196730
	movs r0, #8
	b _08196746
_08196730:
	adds r0, r1, #0
	subs r0, #0x5e
	cmp r0, #3
	bhi _0819673C
	movs r0, #9
	b _08196746
_0819673C:
	cmp r1, #0x62
	beq _08196744
	movs r0, #0xb
	b _08196746
_08196744:
	movs r0, #0xa
_08196746:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetLandEncounterSlot

	thumb_func_start GetWaterEncounterSlot
GetWaterEncounterSlot: @ 0x0819674C
	push {lr}
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x64
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x3b
	bgt _08196768
	movs r0, #0
	b _0819678E
_08196768:
	adds r0, r1, #0
	subs r0, #0x3c
	cmp r0, #0x1d
	bhi _08196774
	movs r0, #1
	b _0819678E
_08196774:
	adds r0, r1, #0
	subs r0, #0x5a
	cmp r0, #4
	bhi _08196780
	movs r0, #2
	b _0819678E
_08196780:
	adds r0, r1, #0
	subs r0, #0x5f
	cmp r0, #3
	bls _0819678C
	movs r0, #4
	b _0819678E
_0819678C:
	movs r0, #3
_0819678E:
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end GetWaterEncounterSlot

	thumb_func_start PopulateSpeciesFromTrainerLocation
PopulateSpeciesFromTrainerLocation: @ 0x08196794
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r2, r0, #0
	mov r8, r1
	movs r3, #0
	ldr r0, _0819684C
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0xff
	beq _08196858
	ldr r1, _08196850
	lsls r0, r2, #4
	adds r2, r0, r1
	ldrh r4, [r2, #0xa]
	adds r1, r7, #0
_081967B6:
	ldrb r0, [r1]
	cmp r0, r4
	bne _081967C4
	ldrb r0, [r1, #1]
	ldrh r5, [r2, #0xc]
	cmp r0, r5
	beq _081967CE
_081967C4:
	adds r1, #0x14
	adds r3, #1
	ldrb r0, [r1]
	cmp r0, #0xff
	bne _081967B6
_081967CE:
	adds r1, r7, #0
	lsls r0, r3, #2
	adds r0, r0, r3
	lsls r5, r0, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08196858
	movs r6, #0
	adds r0, r1, #4
	adds r0, r5, r0
	ldr r4, [r0]
	cmp r4, #0
	beq _081967FE
	bl GetLandEncounterSlot
	lsls r0, r0, #0x18
	mov r2, sp
	ldr r1, [r4, #4]
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	strh r0, [r2]
	movs r6, #1
_081967FE:
	adds r0, r7, #0
	adds r0, #8
	adds r0, r5, r0
	ldr r4, [r0]
	cmp r4, #0
	beq _08196822
	bl GetWaterEncounterSlot
	lsls r0, r0, #0x18
	lsls r1, r6, #1
	mov r3, sp
	adds r2, r3, r1
	ldr r1, [r4, #4]
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldrh r0, [r0, #2]
	strh r0, [r2]
	adds r6, #1
_08196822:
	cmp r6, #0
	beq _08196858
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl __modsi3
	lsls r0, r0, #1
	add r0, sp
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, _08196854
	adds r1, r1, r0
	mov r0, r8
	bl StringCopy
	b _0819685E
	.align 2, 0
_0819684C: .4byte 0x0852D9F4
_08196850: .4byte 0x0852AD40
_08196854: .4byte 0x082EA31C
_08196858:
	movs r0, #0xff
	mov r5, r8
	strb r0, [r5]
_0819685E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end PopulateSpeciesFromTrainerLocation

	thumb_func_start PopulateSpeciesFromTrainerParty
PopulateSpeciesFromTrainerParty: @ 0x0819686C
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	ldr r2, _081968BC
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r2
	ldrh r0, [r1]
	bl GetLastBeatenRematchTrainerId
	adds r4, r0, #0
	lsls r4, r4, #0x10
	ldr r5, _081968C0
	lsrs r4, r4, #0xb
	adds r0, r5, #0
	adds r0, #0x1c
	adds r0, r4, r0
	ldr r6, [r0]
	bl Random
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r4, r4, r5
	ldrb r1, [r4, #0x18]
	bl __modsi3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r4]
	cmp r1, #1
	beq _081968C8
	cmp r1, #1
	ble _081968B6
	cmp r1, #2
	beq _081968C4
	cmp r1, #3
	beq _081968C8
_081968B6:
	lsls r0, r0, #3
	b _081968CA
	.align 2, 0
_081968BC: .4byte 0x085D6934
_081968C0: .4byte 0x082E383C
_081968C4:
	lsls r0, r0, #3
	b _081968CA
_081968C8:
	lsls r0, r0, #4
_081968CA:
	adds r0, r0, r6
	ldrh r0, [r0, #4]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #1
	ldr r0, _081968E4
	adds r1, r1, r0
	adds r0, r7, #0
	bl StringCopy
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081968E4: .4byte 0x082EA31C
	thumb_func_end PopulateSpeciesFromTrainerParty

	thumb_func_start PopulateBattleFrontierFacilityName
PopulateBattleFrontierFacilityName: @ 0x081968E8
	push {lr}
	adds r0, r1, #0
	ldr r2, _08196900
	ldr r1, _08196904
	ldrh r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl StringCopy
	pop {r0}
	bx r0
	.align 2, 0
_08196900: .4byte 0x085D7A84
_08196904: .4byte 0x0203CA54
	thumb_func_end PopulateBattleFrontierFacilityName

	thumb_func_start PopulateBattleFrontierStreak
PopulateBattleFrontierStreak: @ 0x08196908
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	movs r4, #0
	ldr r0, _0819693C
	ldrh r1, [r0, #2]
	adds r6, r0, #0
	cmp r1, #0
	beq _08196928
_08196918:
	adds r0, r1, #0
	movs r1, #0xa
	bl __divsi3
	adds r1, r0, #0
	adds r4, #1
	cmp r1, #0
	bne _08196918
_08196928:
	ldrh r1, [r6, #2]
	lsls r3, r4, #0x18
	lsrs r3, r3, #0x18
	adds r0, r5, #0
	movs r2, #0
	bl ConvertIntToDecimalStringN
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0819693C: .4byte 0x0203CA54
	thumb_func_end PopulateBattleFrontierStreak

	thumb_func_start GetNumOwnedBadges
GetNumOwnedBadges: @ 0x08196940
	push {r4, r5, lr}
	movs r4, #0
	ldr r5, _08196948
	b _08196950
	.align 2, 0
_08196948: .4byte 0x085D7AA0
_0819694C:
	adds r5, #2
	adds r4, #1
_08196950:
	cmp r4, #7
	bhi _08196960
	ldrh r0, [r5]
	bl FlagGet
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0819694C
_08196960:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	thumb_func_end GetNumOwnedBadges

	thumb_func_start sub_08196968
sub_08196968: @ 0x08196968
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	bl GetNumOwnedBadges
	cmp r0, #4
	ble _081969E8
	bl RtcGetLocalDayCount
	adds r4, r0, #0
	ldr r0, _081969D8
	ldr r0, [r0]
	adds r0, #0xa
	bl GetTrainerId
	adds r6, r0, #0
	ldr r0, _081969DC
	ands r6, r0
	ldr r0, _081969E0
	ldr r0, [r0]
	ldr r1, _081969E4
	adds r0, r0, r1
	ldrh r5, [r0]
	bl GetNumRematchTrainersFought
	mov sb, r0
	movs r0, #0xd
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	movs r1, #0xa
	bl __divsi3
	mov r8, r0
	movs r0, #9
	bl GetGameStat
	eors r4, r5
	eors r5, r0
	adds r4, r4, r5
	eors r4, r6
	adds r0, r4, #0
	mov r1, r8
	bl __modsi3
	cmp r0, sb
	bge _081969E8
	bl sub_08196374
	cmp r0, r7
	bne _081969E8
	movs r0, #1
	b _081969EA
	.align 2, 0
_081969D8: .4byte 0x03005AF0
_081969DC: .4byte 0x0000FFFF
_081969E0: .4byte 0x03005AEC
_081969E4: .4byte 0x00002E6A
_081969E8:
	movs r0, #0
_081969EA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
	thumb_func_end sub_08196968

	thumb_func_start GetFrontierStreakInfo
GetFrontierStreakInfo: @ 0x081969F8
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r4, #0
	cmp r0, #6
	bls _08196A08
	b _08196B72
_08196A08:
	lsls r0, r0, #2
	ldr r1, _08196A14
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08196A14: .4byte 0x08196A18
_08196A18: @ jump table
	.4byte _08196A90 @ case 0
	.4byte _08196A34 @ case 1
	.4byte _08196AC4 @ case 2
	.4byte _08196B2C @ case 3
	.4byte _08196A68 @ case 4
	.4byte _08196AF8 @ case 5
	.4byte _08196B54 @ case 6
_08196A34:
	movs r3, #0
	ldr r0, _08196A60
	ldr r0, [r0]
	ldr r1, _08196A64
	adds r0, r0, r1
_08196A3E:
	lsls r1, r3, #2
	adds r3, #1
	adds r1, r1, r0
	movs r2, #1
_08196A46:
	ldrh r6, [r1]
	cmp r4, r6
	bhs _08196A4E
	ldrh r4, [r1]
_08196A4E:
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08196A46
	cmp r3, #1
	ble _08196A3E
	movs r0, #3
	b _08196B70
	.align 2, 0
_08196A60: .4byte 0x03005AF0
_08196A64: .4byte 0x00000D14
_08196A68:
	ldr r0, _08196A88
	ldr r0, [r0]
	ldr r1, _08196A8C
	adds r0, r0, r1
	movs r3, #1
_08196A72:
	ldrh r6, [r0]
	cmp r4, r6
	bhs _08196A7A
	ldrh r4, [r0]
_08196A7A:
	adds r0, #2
	subs r3, #1
	cmp r3, #0
	bge _08196A72
	movs r0, #4
	b _08196B70
	.align 2, 0
_08196A88: .4byte 0x03005AF0
_08196A8C: .4byte 0x00000E08
_08196A90:
	movs r3, #0
	ldr r0, _08196AC0
	ldr r0, [r0]
	movs r1, #0xcf
	lsls r1, r1, #4
	adds r0, r0, r1
_08196A9C:
	lsls r1, r3, #2
	adds r3, #1
	adds r1, r1, r0
	movs r2, #1
_08196AA4:
	ldrh r6, [r1]
	cmp r4, r6
	bhs _08196AAC
	ldrh r4, [r1]
_08196AAC:
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08196AA4
	movs r2, #2
	cmp r3, #3
	ble _08196A9C
	str r2, [r5]
	b _08196B72
	.align 2, 0
_08196AC0: .4byte 0x03005AF0
_08196AC4:
	movs r3, #0
	ldr r0, _08196AF4
	ldr r0, [r0]
	movs r1, #0xdd
	lsls r1, r1, #4
	adds r0, r0, r1
_08196AD0:
	lsls r1, r3, #2
	adds r3, #1
	adds r1, r1, r0
	movs r2, #1
_08196AD8:
	ldrh r6, [r1]
	cmp r4, r6
	bhs _08196AE0
	ldrh r4, [r1]
_08196AE0:
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08196AD8
	movs r2, #2
	cmp r3, #1
	ble _08196AD0
	str r2, [r5]
	b _08196B72
	.align 2, 0
_08196AF4: .4byte 0x03005AF0
_08196AF8:
	movs r3, #0
	ldr r0, _08196B24
	ldr r0, [r0]
	ldr r1, _08196B28
	adds r0, r0, r1
_08196B02:
	lsls r1, r3, #2
	adds r3, #1
	adds r1, r1, r0
	movs r2, #1
_08196B0A:
	ldrh r6, [r1]
	cmp r4, r6
	bhs _08196B12
	ldrh r4, [r1]
_08196B12:
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _08196B0A
	movs r2, #2
	cmp r3, #1
	ble _08196B02
	str r2, [r5]
	b _08196B72
	.align 2, 0
_08196B24: .4byte 0x03005AF0
_08196B28: .4byte 0x00000DEA
_08196B2C:
	ldr r0, _08196B4C
	ldr r0, [r0]
	ldr r1, _08196B50
	adds r0, r0, r1
	movs r3, #1
_08196B36:
	ldrh r6, [r0]
	cmp r4, r6
	bhs _08196B3E
	ldrh r4, [r0]
_08196B3E:
	adds r0, #2
	subs r3, #1
	cmp r3, #0
	bge _08196B36
	movs r3, #2
	str r3, [r5]
	b _08196B72
	.align 2, 0
_08196B4C: .4byte 0x03005AF0
_08196B50: .4byte 0x00000DDE
_08196B54:
	ldr r0, _08196B7C
	ldr r0, [r0]
	ldr r1, _08196B80
	adds r0, r0, r1
	movs r3, #1
_08196B5E:
	ldrh r6, [r0]
	cmp r4, r6
	bhs _08196B66
	ldrh r4, [r0]
_08196B66:
	adds r0, #2
	subs r3, #1
	cmp r3, #0
	bge _08196B5E
	movs r0, #5
_08196B70:
	str r0, [r5]
_08196B72:
	adds r0, r4, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08196B7C: .4byte 0x03005AF0
_08196B80: .4byte 0x00000E1E
	thumb_func_end GetFrontierStreakInfo

	thumb_func_start GetPokedexRatingLevel
GetPokedexRatingLevel: @ 0x08196B84
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #9
	bhi _08196B92
	movs r0, #0
	b _08196C6E
_08196B92:
	cmp r4, #0x13
	bhi _08196B9A
	movs r0, #1
	b _08196C6E
_08196B9A:
	cmp r4, #0x1d
	bhi _08196BA2
	movs r0, #2
	b _08196C6E
_08196BA2:
	cmp r4, #0x27
	bhi _08196BAA
	movs r0, #3
	b _08196C6E
_08196BAA:
	cmp r4, #0x31
	bhi _08196BB2
	movs r0, #4
	b _08196C6E
_08196BB2:
	cmp r4, #0x3b
	bhi _08196BBA
	movs r0, #5
	b _08196C6E
_08196BBA:
	cmp r4, #0x45
	bhi _08196BC2
	movs r0, #6
	b _08196C6E
_08196BC2:
	cmp r4, #0x4f
	bhi _08196BCA
	movs r0, #7
	b _08196C6E
_08196BCA:
	cmp r4, #0x59
	bhi _08196BD2
	movs r0, #8
	b _08196C6E
_08196BD2:
	cmp r4, #0x63
	bhi _08196BDA
	movs r0, #9
	b _08196C6E
_08196BDA:
	cmp r4, #0x6d
	bhi _08196BE2
	movs r0, #0xa
	b _08196C6E
_08196BE2:
	cmp r4, #0x77
	bhi _08196BEA
	movs r0, #0xb
	b _08196C6E
_08196BEA:
	cmp r4, #0x81
	bhi _08196BF2
	movs r0, #0xc
	b _08196C6E
_08196BF2:
	cmp r4, #0x8b
	bhi _08196BFA
	movs r0, #0xd
	b _08196C6E
_08196BFA:
	cmp r4, #0x95
	bhi _08196C02
	movs r0, #0xe
	b _08196C6E
_08196C02:
	cmp r4, #0x9f
	bhi _08196C0A
	movs r0, #0xf
	b _08196C6E
_08196C0A:
	cmp r4, #0xa9
	bhi _08196C12
	movs r0, #0x10
	b _08196C6E
_08196C12:
	cmp r4, #0xb3
	bhi _08196C1A
	movs r0, #0x11
	b _08196C6E
_08196C1A:
	cmp r4, #0xbd
	bhi _08196C22
	movs r0, #0x12
	b _08196C6E
_08196C22:
	cmp r4, #0xc7
	bls _08196C6C
	movs r0, #0xcd
	lsls r0, r0, #1
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08196C44
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08196C44:
	ldr r0, _08196C68
	bl HoennToNationalOrder
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #1
	bl GetSetPokedexFlag
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08196C60
	subs r0, r4, #1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_08196C60:
	cmp r4, #0xc7
	bls _08196C6C
	movs r0, #0x14
	b _08196C6E
	.align 2, 0
_08196C68: .4byte 0x00000199
_08196C6C:
	movs r0, #0x13
_08196C6E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end GetPokedexRatingLevel

	thumb_func_start sub_08196C74
sub_08196C74: @ 0x08196C74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	movs r0, #0xfa
	lsls r0, r0, #2
	bl Alloc
	adds r7, r0, #0
	cmp r7, #0
	bne _08196C96
	movs r0, #0xff
	mov r1, r8
	strb r0, [r1]
	b _08196D50
_08196C96:
	movs r0, #0
	bl GetHoennPokedexCount
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #1
	bl GetHoennPokedexCount
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _08196D60
	mov sl, r0
	adds r1, r4, #0
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r1, _08196D64
	mov sb, r1
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	adds r0, r6, #0
	bl GetPokedexRatingLevel
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	ldr r1, _08196D68
	adds r0, r7, #0
	bl StringCopy
	adds r5, r0, #0
	movs r6, #0xfb
	strb r6, [r5]
	adds r5, #1
	ldr r1, _08196D6C
	adds r0, r5, #0
	bl StringCopy
	adds r5, r0, #0
	strb r6, [r5]
	adds r5, #1
	ldr r0, _08196D70
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl StringCopy
	mov r0, r8
	adds r1, r7, #0
	bl StringExpandPlaceholders
	adds r5, r0, #0
	bl IsNationalPokedexEnabled
	cmp r0, #0
	beq _08196D4A
	strb r6, [r5]
	adds r5, #1
	movs r0, #0
	bl GetNationalPokedexCount
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #1
	bl GetNationalPokedexCount
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov r0, sl
	adds r1, r4, #0
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	movs r3, #3
	bl ConvertIntToDecimalStringN
	ldr r1, _08196D74
	adds r0, r5, #0
	bl StringExpandPlaceholders
_08196D4A:
	adds r0, r7, #0
	bl Free
_08196D50:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196D60: .4byte 0x02021C40
_08196D64: .4byte 0x02021C54
_08196D68: .4byte 0x08262DF5
_08196D6C: .4byte 0x08262E39
_08196D70: .4byte 0x085D7AB0
_08196D74: .4byte 0x0826316A
	thumb_func_end sub_08196C74

	thumb_func_start LoadMatchCallWindowGfx
LoadMatchCallWindowGfx: @ 0x08196D78
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r1, #0
	bl GetWindowAttribute
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r1, _08196DB0
	movs r2, #0x80
	lsls r2, r2, #1
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r3, r4, #0
	bl LoadBgTiles
	ldr r0, _08196DB4
	lsls r5, r5, #0x14
	lsrs r5, r5, #0x10
	adds r1, r5, #0
	movs r2, #0x20
	bl LoadPalette
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08196DB0: .4byte 0x085D74E8
_08196DB4: .4byte 0x085D74C8
	thumb_func_end LoadMatchCallWindowGfx

	thumb_func_start DrawMatchCallTextBoxBorder
DrawMatchCallTextBoxBorder: @ 0x08196DB8
	push {lr}
	bl DrawMatchCallTextBoxBorder_Internal
	pop {r0}
	bx r0
	.align 2, 0
	thumb_func_end DrawMatchCallTextBoxBorder
