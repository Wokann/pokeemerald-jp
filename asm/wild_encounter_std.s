.include "asm/macros.inc"
.include "constants/constants.inc"
.text
.syntax unified

	thumb_func_start StandardWildEncounter
StandardWildEncounter: @ 0x080B49E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	mov sb, r6
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	mov r8, r7
	ldr r0, _080B4A78
	ldrb r0, [r0]
	cmp r0, #1
	bne _080B49FE
	b _080B4C56
_080B49FE:
	bl GetCurrentMapWildMonHeaderId
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	ldr r0, _080B4A7C
	cmp r5, r0
	bne _080B4AF4
	ldr r0, _080B4A80
	ldrh r1, [r0, #0x12]
	movs r0, #0xb3
	lsls r0, r0, #1
	cmp r1, r0
	bne _080B4A88
	bl GetBattlePikeWildMonHeaderId
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r7, r6
	beq _080B4A30
	bl DoGlobalWildEncounterDiceRoll
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B4A30
	b _080B4C56
_080B4A30:
	ldr r1, _080B4A84
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r1, #4
	adds r4, r0, r1
	ldr r0, [r4]
	ldrb r0, [r0]
	movs r1, #0
	bl DoWildEncounterRateTest
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080B4A50
	b _080B4C56
_080B4A50:
	ldr r0, [r4]
	movs r1, #0
	movs r2, #2
	bl TryGenerateWildMon
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080B4A64
	b _080B4C56
_080B4A64:
	movs r0, #1
	bl TryGenerateBattlePikeWildMon
	cmp r0, #0
	bne _080B4A70
	b _080B4C56
_080B4A70:
	bl BattleSetup_StartBattlePikeWildBattle
	movs r0, #1
	b _080B4C58
	.align 2, 0
_080B4A78: .4byte 0x020388A0
_080B4A7C: .4byte 0x0000FFFF
_080B4A80: .4byte 0x02036FB8
_080B4A84: .4byte 0x0852E6C0
_080B4A88:
	ldr r0, _080B4AE4
	cmp r1, r0
	beq _080B4A90
	b _080B4C56
_080B4A90:
	ldr r0, _080B4AE8
	ldr r0, [r0]
	ldr r1, _080B4AEC
	adds r0, r0, r1
	ldrh r5, [r0]
	cmp r7, r6
	beq _080B4AAA
	bl DoGlobalWildEncounterDiceRoll
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B4AAA
	b _080B4C56
_080B4AAA:
	ldr r1, _080B4AF0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	adds r1, #4
	adds r4, r0, r1
	ldr r0, [r4]
	ldrb r0, [r0]
	movs r1, #0
	bl DoWildEncounterRateTest
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080B4ACA
	b _080B4C56
_080B4ACA:
	ldr r0, [r4]
	movs r1, #0
	movs r2, #2
	bl TryGenerateWildMon
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080B4ADE
	b _080B4C56
_080B4ADE:
	bl GenerateBattlePyramidWildMon
	b _080B4C4E
	.align 2, 0
_080B4AE4: .4byte 0x00000169
_080B4AE8: .4byte 0x03005AF0
_080B4AEC: .4byte 0x00000CB2
_080B4AF0: .4byte 0x0852E540
_080B4AF4:
	lsls r0, r6, #0x18
	lsrs r4, r0, #0x18
	adds r0, r4, #0
	bl MetatileBehavior_IsLandWildEncounter
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080B4B94
	ldr r1, _080B4B90
	lsls r2, r5, #2
	adds r0, r2, r5
	lsls r0, r0, #2
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, r2, #0
	cmp r0, #0
	bne _080B4B1C
	b _080B4C56
_080B4B1C:
	cmp r7, r6
	beq _080B4B2C
	bl DoGlobalWildEncounterDiceRoll
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080B4B2C
	b _080B4C56
_080B4B2C:
	ldr r1, _080B4B90
	adds r0, r4, r5
	lsls r0, r0, #2
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r0, [r0]
	movs r1, #0
	bl DoWildEncounterRateTest
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080B4B4A
	b _080B4C56
_080B4B4A:
	bl TryStartRoamerEncounter
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080B4C12
	bl DoMassOutbreakEncounterTest
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080B4B70
	movs r0, #3
	bl SetUpMassOutbreakEncounter
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080B4C4E
_080B4B70:
	ldr r1, _080B4B90
	adds r0, r4, r5
	lsls r0, r0, #2
	adds r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	movs r2, #3
	bl TryGenerateWildMon
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080B4C4E
	b _080B4C56
	.align 2, 0
_080B4B90: .4byte 0x0852D9F4
_080B4B94:
	adds r0, r4, #0
	bl MetatileBehavior_IsWaterWildEncounter
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080B4BBC
	movs r0, #8
	bl TestPlayerAvatarFlags
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B4C56
	adds r0, r4, #0
	bl MetatileBehavior_IsBridge
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080B4C56
_080B4BBC:
	bl AreLegendariesInSootopolisPreventingEncounters
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _080B4C56
	ldr r1, _080B4C30
	lsls r2, r5, #2
	adds r0, r2, r5
	lsls r0, r0, #2
	adds r1, #8
	adds r0, r0, r1
	ldr r0, [r0]
	adds r4, r2, #0
	cmp r0, #0
	beq _080B4C56
	cmp r8, sb
	beq _080B4BEA
	bl DoGlobalWildEncounterDiceRoll
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B4C56
_080B4BEA:
	ldr r1, _080B4C30
	adds r0, r4, r5
	lsls r0, r0, #2
	adds r1, #8
	adds r4, r0, r1
	ldr r0, [r4]
	ldrb r0, [r0]
	movs r1, #0
	bl DoWildEncounterRateTest
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080B4C56
	bl TryStartRoamerEncounter
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080B4C3C
_080B4C12:
	ldr r0, _080B4C34
	ldr r0, [r0]
	ldr r1, _080B4C38
	adds r0, r0, r1
	ldrb r0, [r0, #0xc]
	bl IsWildLevelAllowedByRepel
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080B4C56
	bl BattleSetup_StartRoamerBattle
	movs r0, #1
	b _080B4C58
	.align 2, 0
_080B4C30: .4byte 0x0852D9F4
_080B4C34: .4byte 0x03005AEC
_080B4C38: .4byte 0x000031DC
_080B4C3C:
	ldr r0, [r4]
	movs r1, #1
	movs r2, #3
	bl TryGenerateWildMon
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _080B4C56
_080B4C4E:
	bl BattleSetup_StartWildBattle
	movs r0, #1
	b _080B4C58
_080B4C56:
	movs r0, #0
_080B4C58:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	thumb_func_end StandardWildEncounter
