@ Player avatar state tables referenced by the remaining JP naked routines.
@ Keep this physical order so their literal pools retain the original ROM layout.

	.globl sForcedMovementTestFuncs
sForcedMovementTestFuncs: @ 0x846F81C
	.4byte MetatileBehavior_IsTrickHouseSlipperyFloor + 1, MetatileBehavior_IsIce + 1
	.4byte MetatileBehavior_IsWalkSouth + 1, MetatileBehavior_IsWalkNorth + 1
	.4byte MetatileBehavior_IsWalkWest + 1, MetatileBehavior_IsWalkEast + 1
	.4byte MetatileBehavior_IsSouthwardCurrent + 1, MetatileBehavior_IsNorthwardCurrent + 1
	.4byte MetatileBehavior_IsWestwardCurrent + 1, MetatileBehavior_IsEastwardCurrent + 1
	.4byte MetatileBehavior_IsSlideSouth + 1, MetatileBehavior_IsSlideNorth + 1
	.4byte MetatileBehavior_IsSlideWest + 1, MetatileBehavior_IsSlideEast + 1
	.4byte MetatileBehavior_IsWaterfall + 1, MetatileBehavior_IsSecretBaseJumpMat + 1
	.4byte MetatileBehavior_IsSecretBaseSpinMat + 1, MetatileBehavior_IsMuddySlope + 1

	.globl sForcedMovementFuncs
sForcedMovementFuncs: @ 0x846F864
	.4byte ForcedMovement_None + 1, ForcedMovement_Slip + 1, ForcedMovement_Slip + 1
	.4byte ForcedMovement_WalkSouth + 1, ForcedMovement_WalkNorth + 1, ForcedMovement_WalkWest + 1
	.4byte ForcedMovement_WalkEast + 1, ForcedMovement_PushedSouthByCurrent + 1
	.4byte ForcedMovement_PushedNorthByCurrent + 1, ForcedMovement_PushedWestByCurrent + 1
	.4byte ForcedMovement_PushedEastByCurrent + 1, ForcedMovement_SlideSouth + 1
	.4byte ForcedMovement_SlideNorth + 1, ForcedMovement_SlideWest + 1, ForcedMovement_SlideEast + 1
	.4byte ForcedMovement_PushedSouthByCurrent + 1, ForcedMovement_MatJump + 1
	.4byte ForcedMovement_MatSpin + 1, ForcedMovement_MuddySlope + 1

	.globl sPlayerNotOnBikeFuncs
sPlayerNotOnBikeFuncs: @ 0x846F8B0
	.4byte PlayerNotOnBikeNotMoving + 1, PlayerNotOnBikeTurningInPlace + 1
	.4byte PlayerNotOnBikeMoving + 1

	.globl sAcroBikeTrickMetatiles
sAcroBikeTrickMetatiles: @ 0x846F8BC
	.4byte MetatileBehavior_IsBumpySlope + 1, MetatileBehavior_IsIsolatedVerticalRail + 1
	.4byte MetatileBehavior_IsIsolatedHorizontalRail + 1, MetatileBehavior_IsVerticalRail + 1
	.4byte MetatileBehavior_IsHorizontalRail + 1

	.globl sAcroBikeTrickCollisionTypes
sAcroBikeTrickCollisionTypes: @ 0x846F8D0
	.byte 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x00, 0x00, 0x00

	.globl sPlayerAvatarTransitionFuncs
sPlayerAvatarTransitionFuncs: @ 0x846F8D8
	.4byte PlayerAvatarTransition_Normal + 1, PlayerAvatarTransition_MachBike + 1
	.4byte PlayerAvatarTransition_AcroBike + 1, PlayerAvatarTransition_Surfing + 1
	.4byte PlayerAvatarTransition_Underwater + 1, PlayerAvatarTransition_ReturnToField + 1
	.4byte PlayerAvatarTransition_Dummy + 1, PlayerAvatarTransition_Dummy + 1

	.globl sArrowWarpMetatileBehaviorChecks
sArrowWarpMetatileBehaviorChecks: @ 0x846F8F8
	.4byte MetatileBehavior_IsSouthArrowWarp + 1, MetatileBehavior_IsNorthArrowWarp + 1
	.4byte MetatileBehavior_IsWestArrowWarp + 1, MetatileBehavior_IsEastArrowWarp + 1

	.globl sRivalAvatarGfxIds
sRivalAvatarGfxIds: @ 0x846F908
	.byte 0x64, 0x69 @ normal
	.byte 0x65, 0x6A @ Mach Bike
	.byte 0x66, 0x6B @ Acro Bike
	.byte 0x67, 0x6C @ surfing
	.byte 0x6F, 0x70 @ underwater
	.byte 0x68, 0x6D @ field move
	.byte 0x89, 0x8A @ fishing
	.byte 0xBF, 0xC0 @ watering

	.globl sPlayerAvatarGfxIds
sPlayerAvatarGfxIds: @ 0x846F918
	.byte 0x00, 0x59 @ normal
	.byte 0x01, 0x5A @ Mach Bike
	.byte 0x3F, 0x5B @ Acro Bike
	.byte 0x02, 0x5C @ surfing
	.byte 0x6F, 0x70 @ underwater
	.byte 0x03, 0x5D @ field move
	.byte 0x89, 0x8A @ fishing
	.byte 0xBF, 0xC0 @ watering

	.globl sFRLGAvatarGfxIds
sFRLGAvatarGfxIds: @ 0x846F928
	.byte 0xE6, 0xE7

	.globl sRSAvatarGfxIds
sRSAvatarGfxIds: @ 0x846F92A
	.byte 0xEB, 0xEC

	.globl sPlayerAvatarGfxToStateFlag
sPlayerAvatarGfxToStateFlag: @ 0x846F92C
	@ Brendan
	.byte 0x00, 0x01 @ normal, on foot
	.byte 0x01, 0x02 @ Mach Bike
	.byte 0x3F, 0x04 @ Acro Bike
	.byte 0x02, 0x08 @ surfing
	.byte 0x6F, 0x10 @ underwater
	@ May
	.byte 0x59, 0x01 @ normal, on foot
	.byte 0x5A, 0x02 @ Mach Bike
	.byte 0x5B, 0x04 @ Acro Bike
	.byte 0x5C, 0x08 @ surfing
	.byte 0x70, 0x10 @ underwater

	.globl sArrowWarpMetatileBehaviorChecks2
sArrowWarpMetatileBehaviorChecks2: @ 0x846F940
	.4byte MetatileBehavior_IsSouthArrowWarp + 1, MetatileBehavior_IsNorthArrowWarp + 1
	.4byte MetatileBehavior_IsWestArrowWarp + 1, MetatileBehavior_IsEastArrowWarp + 1

	.globl sPushBoulderFuncs
sPushBoulderFuncs: @ 0x846F950
	.4byte PushBoulder_Start + 1, PushBoulder_Move + 1, PushBoulder_End + 1

	.globl sPlayerAvatarSecretBaseMatJump
sPlayerAvatarSecretBaseMatJump: @ 0x846F95C
	.4byte PlayerAvatar_DoSecretBaseMatJump + 1

	.globl sPlayerAvatarSecretBaseMatSpin
sPlayerAvatarSecretBaseMatSpin: @ 0x846F960
	.4byte PlayerAvatar_SecretBaseMatSpinStep0 + 1, PlayerAvatar_SecretBaseMatSpinStep1 + 1
	.4byte PlayerAvatar_SecretBaseMatSpinStep2 + 1, PlayerAvatar_SecretBaseMatSpinStep3 + 1

	.globl sSecretBaseMatSpinDirections
sSecretBaseMatSpinDirections: @ 0x846F970
	.byte 0x03, 0x04, 0x02, 0x01 @ west, east, north, south

	.globl sSecretBaseMatSpinActions
sSecretBaseMatSpinActions: @ 0x846F974
	.byte 0x10, 0x10, 0x11, 0x12, 0x13 @ delay 1, 1, 2, 4, 8
	.byte 0x00, 0x00, 0x00 @ padding

	.globl sFishingStateFuncs
sFishingStateFuncs: @ 0x846F97C
	.4byte Fishing_Init + 1, Fishing_GetRodOut + 1, Fishing_WaitBeforeDots + 1, Fishing_InitDots + 1
	.4byte Fishing_ShowDots + 1, Fishing_CheckForBite + 1, Fishing_GotBite + 1, Fishing_WaitForA + 1
	.4byte Fishing_CheckMoreDots + 1, Fishing_MonOnHook + 1, Fishing_StartEncounter + 1, Fishing_NotEvenNibble + 1
	.4byte Fishing_GotAway + 1, Fishing_NoMon + 1, Fishing_PutRodAway + 1, Fishing_EndNoMon + 1

	.globl sFishingMinRounds1
sFishingMinRounds1: @ 0x846F9BC
	.2byte 1, 1, 1

	.globl sFishingMinRounds2
sFishingMinRounds2: @ 0x846F9C2
	.2byte 1, 3, 6
