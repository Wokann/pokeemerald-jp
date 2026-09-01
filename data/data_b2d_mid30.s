.include "sound/MPlayDef.s"
	.section .rodata.after_tilesets, "a", %progbits
	.include "asm/macros.inc"
	.include "constants/map_constants.inc"
	.include "constants/map_header.inc"
	.include "constants/trainers.inc"
	.include "constants/battle_string_ids.inc"
	.include "constants/species.inc"
	.include "constants/moves.inc"
	.include "constants/songs.inc"
	.include "constants/ribbon_constants.inc"
	.include "data/layouts/layouts.inc"
	.include "data/layouts/layouts_table.inc"
	.globl gMapHeaders
gMapHeaders: @ 0x0845A8D8
	@ Map headers and map groups are generated from data/maps/map_groups.json.
	.include "data/maps/headers.inc"
	.include "data/maps/groups.inc"
	.include "data/maps/LittlerootTown/connections.inc"
	.include "data/maps/OldaleTown/connections.inc"
	.include "data/maps/DewfordTown/connections.inc"
	.include "data/maps/LavaridgeTown/connections.inc"
	.include "data/maps/FallarborTown/connections.inc"
	.include "data/maps/VerdanturfTown/connections.inc"
	.include "data/maps/PacifidlogTown/connections.inc"
	.include "data/maps/PetalburgCity/connections.inc"
	.include "data/maps/SlateportCity/connections.inc"
	.include "data/maps/MauvilleCity/connections.inc"
	.include "data/maps/RustboroCity/connections.inc"
	.include "data/maps/FortreeCity/connections.inc"
	.include "data/maps/LilycoveCity/connections.inc"
	.include "data/maps/MossdeepCity/connections.inc"
	.include "data/maps/SootopolisCity/connections.inc"
	.include "data/maps/EverGrandeCity/connections.inc"
	.include "data/maps/Route101/connections.inc"
	.include "data/maps/Route102/connections.inc"
	.include "data/maps/Route103/connections.inc"
	.include "data/maps/Route104/connections.inc"
	.include "data/maps/Route105/connections.inc"
	.include "data/maps/Route106/connections.inc"
	.include "data/maps/Route107/connections.inc"
	.include "data/maps/Route108/connections.inc"
	.include "data/maps/Route109/connections.inc"
	.include "data/maps/Route110/connections.inc"
	.include "data/maps/Route111/connections.inc"
	.include "data/maps/Route112/connections.inc"
	.include "data/maps/Route113/connections.inc"
	.include "data/maps/Route114/connections.inc"
	.include "data/maps/Route115/connections.inc"
	.include "data/maps/Route116/connections.inc"
	.include "data/maps/Route117/connections.inc"
	.include "data/maps/Route118/connections.inc"
	.include "data/maps/Route119/connections.inc"
	.include "data/maps/Route120/connections.inc"
	.include "data/maps/Route121/connections.inc"
	.include "data/maps/Route122/connections.inc"
	.include "data/maps/Route123/connections.inc"
	.include "data/maps/Route124/connections.inc"
	.include "data/maps/Route125/connections.inc"
	.include "data/maps/Route126/connections.inc"
	.include "data/maps/Route127/connections.inc"
	.include "data/maps/Route128/connections.inc"
	.include "data/maps/Route129/connections.inc"
	.include "data/maps/Route130/connections.inc"
	.include "data/maps/Route131/connections.inc"
	.include "data/maps/Route132/connections.inc"
	.include "data/maps/Route133/connections.inc"
	.include "data/maps/Route134/connections.inc"
	@ 0x0845F144: Underwater_Route105 connection list and header.
	.include "data/maps/Underwater_Route105/connections.inc"
	@ 0x0845F158: Underwater_Route124 connection list and header.
	.include "data/maps/Underwater_Route124/connections.inc"
	@ 0x0845F178: Underwater_Route125 connection list and header.
	.include "data/maps/Underwater_Route125/connections.inc"
	@ 0x0845F18C: Underwater_Route126 connection list and header.
	.include "data/maps/Underwater_Route126/connections.inc"
	@ 0x0845F1B8: Underwater_Route127 connection list and header.
	.include "data/maps/Underwater_Route127/connections.inc"
	@ 0x0845F1E4: Underwater_Route128 connection list and header.
	.include "data/maps/Underwater_Route128/connections.inc"
	@ 0x0845F204: Underwater_Route129 connection list and header.
	.include "data/maps/Underwater_Route129/connections.inc"
	@ 0x0845F218: Safari Zone Northwest connection list and header.
	.include "data/maps/SafariZone_Northwest/connections.inc"
	@ 0x0845F238: Safari Zone North connection list and header.
	.include "data/maps/SafariZone_North/connections.inc"
	@ 0x0845F264: Safari Zone Southwest connection list and header.
	.include "data/maps/SafariZone_Southwest/connections.inc"
	@ 0x0845F284: Safari Zone South connection list and header.
	.include "data/maps/SafariZone_South/connections.inc"
	.include "data/maps/SafariZone_Northeast/connections.inc"
	.include "data/maps/SafariZone_Southeast/connections.inc"
	.include "data/maps/BattleFrontier_OutsideWest/connections.inc"
	.include "data/maps/BattleFrontier_OutsideEast/connections.inc"

	.globl sDummyConnectionFlags
sDummyConnectionFlags: @ 0x845F318
	.incbin "baserom_jp.gba", 0x45f318, 0x4

	.globl sTileBitAttributes
sTileBitAttributes: @ 0x845F31C
	.incbin "graphics/misc/sTileBitAttributes.bin"

	.globl sDoorOpenAnimFrames
sDoorOpenAnimFrames: @ 0x846F3AC
	.incbin "graphics/misc/sDoorOpenAnimFrames.bin"

	.globl sDoorCloseAnimFrames
sDoorCloseAnimFrames: @ 0x846F3C0
	.incbin "graphics/misc/sDoorCloseAnimFrames.bin"

	.globl sBigDoorOpenAnimFrames
sBigDoorOpenAnimFrames: @ 0x846F3D4
	.incbin "graphics/misc/sBigDoorOpenAnimFrames.bin"

	.globl sDoorAnimGraphicsTable
sDoorAnimGraphicsTable: @ 0x846F594
	.hword 0x0021
	.byte 0x00, 0x01
	.4byte 0x084603AC, 0x0846F3FC
	.hword 0x0061
	.byte 0x01, 0x01
	.4byte 0x084606CC, 0x0846F404
	.hword 0x01CD
	.byte 0x01, 0x01
	.4byte 0x084609CC, 0x0846F40C
	.hword 0x0041
	.byte 0x01, 0x01
	.4byte 0x08460CCC, 0x0846F414
	.hword 0x0248
	.byte 0x00, 0x01
	.4byte 0x0845F40C, 0x0846F41C
	.hword 0x0249
	.byte 0x00, 0x01
	.4byte 0x0845F72C, 0x0846F424
	.hword 0x022F
	.byte 0x00, 0x01
	.4byte 0x08460FCC, 0x0846F42C
	.hword 0x021F
	.byte 0x00, 0x01
	.4byte 0x084612EC, 0x0846F434
	.hword 0x02A5
	.byte 0x00, 0x01
	.4byte 0x0845FA4C, 0x0846F43C
	.hword 0x0287
	.byte 0x00, 0x01
	.4byte 0x0846160C, 0x0846F44C
	.hword 0x02AC
	.byte 0x00, 0x01
	.4byte 0x084674EC, 0x0846F48C
	.hword 0x03A1
	.byte 0x00, 0x01
	.4byte 0x0846780C, 0x0846F494
	.hword 0x02DC
	.byte 0x00, 0x01
	.4byte 0x08467B2C, 0x0846F484
	.hword 0x0225
	.byte 0x00, 0x01
	.4byte 0x08467E4C, 0x0846F47C
	.hword 0x01DB
	.byte 0x01, 0x01
	.4byte 0x0846816C, 0x0846F4A4
	.hword 0x0246
	.byte 0x00, 0x01
	.4byte 0x0845FD6C, 0x0846F444
	.hword 0x028E
	.byte 0x00, 0x01
	.4byte 0x0846008C, 0x0846F49C
	.hword 0x02A1
	.byte 0x00, 0x01
	.4byte 0x0846848C, 0x0846F454
	.hword 0x021C
	.byte 0x00, 0x01
	.4byte 0x084687AC, 0x0846F46C
	.hword 0x021E
	.byte 0x00, 0x01
	.4byte 0x08468ACC, 0x0846F474
	.hword 0x021D
	.byte 0x01, 0x01
	.4byte 0x08468DEC, 0x0846F45C
	.hword 0x021A
	.byte 0x00, 0x01
	.4byte 0x0846910C, 0x0846F464
	.hword 0x0224
	.byte 0x00, 0x01
	.4byte 0x0846942C, 0x0846F4AC
	.hword 0x0289
	.byte 0x00, 0x01
	.4byte 0x0846974C, 0x0846F4B4
	.hword 0x030C
	.byte 0x01, 0x01
	.4byte 0x08469A6C, 0x0846F4BC
	.hword 0x032D
	.byte 0x01, 0x01
	.4byte 0x08469D8C, 0x0846F4C4
	.hword 0x02ED
	.byte 0x01, 0x01
	.4byte 0x0846A0AC, 0x0846F4CC
	.hword 0x0264
	.byte 0x01, 0x01
	.4byte 0x0846A3CC, 0x0846F4D4
	.hword 0x022B
	.byte 0x00, 0x01
	.4byte 0x0846A6EC, 0x0846F4DC
	.hword 0x02F7
	.byte 0x00, 0x01
	.4byte 0x0846AA0C, 0x0846F4E4
	.hword 0x0297
	.byte 0x00, 0x01
	.4byte 0x0846AD2C, 0x0846F4EC
	.hword 0x0285
	.byte 0x01, 0x01
	.4byte 0x0846B04C, 0x0846F4F4
	.hword 0x025D
	.byte 0x01, 0x01
	.4byte 0x0846B36C, 0x0846F4FC
	.hword 0x020E
	.byte 0x01, 0x01
	.4byte 0x0846B68C, 0x0846F504
	.hword 0x03B0
	.byte 0x01, 0x01
	.4byte 0x0846B9AC, 0x0846F50C
	.hword 0x028A
	.byte 0x01, 0x01
	.4byte 0x0846BCCC, 0x0846F514
	.hword 0x0263
	.byte 0x01, 0x01
	.4byte 0x0846BFEC, 0x0846F51C
	.hword 0x0329
	.byte 0x01, 0x01
	.4byte 0x0846C30C, 0x0846F524
	.hword 0x0291
	.byte 0x00, 0x01
	.4byte 0x0846C62C, 0x0846F52C
	.hword 0x021B
	.byte 0x02, 0x01
	.4byte 0x0846C94C, 0x0846F534
	.hword 0x0209
	.byte 0x01, 0x01
	.4byte 0x0846CC6C, 0x0846F53C
	.hword 0x0219
	.byte 0x00, 0x01
	.4byte 0x0846CF8C, 0x0846F544
	.hword 0x0393
	.byte 0x01, 0x01
	.4byte 0x0846D28C, 0x0846F54C
	.hword 0x03D4
	.byte 0x01, 0x01
	.4byte 0x0846D28C, 0x0846F54C
	.hword 0x036C
	.byte 0x01, 0x01
	.4byte 0x0846D28C, 0x0846F54C
	.hword 0x025E
	.byte 0x01, 0x01
	.4byte 0x0846D6AC, 0x0846F554
	.hword 0x02AD
	.byte 0x01, 0x02
	.4byte 0x0846D9CC, 0x0846F55C
	.hword 0x03FC
	.byte 0x00, 0x01
	.4byte 0x0846DFEC, 0x0846F56C
	.hword 0x0396
	.byte 0x01, 0x01
	.4byte 0x0846E30C, 0x0846F56C
	.hword 0x020A
	.byte 0x01, 0x01
	.4byte 0x0846E62C, 0x0846F574
	.hword 0x026B
	.byte 0x01, 0x01
	.4byte 0x0846E94C, 0x0846F57C
	.hword 0x032C
	.byte 0x01, 0x01
	.4byte 0x0846ED6C, 0x0846F584
	.hword 0x0383
	.byte 0x01, 0x01
	.4byte 0x0846F08C, 0x0846F58C
	.hword 0x0000
	.byte 0x00, 0x00
	.4byte 0x00000000, 0x00000000

	.globl sForcedMovementTestFuncs
sForcedMovementTestFuncs: @ 0x846F81C
	.4byte MetatileBehavior_IsTrickHouseSlipperyFloor + 1, MetatileBehavior_IsIce + 1, MetatileBehavior_IsWalkSouth + 1, MetatileBehavior_IsWalkNorth + 1
	.4byte MetatileBehavior_IsWalkWest + 1, MetatileBehavior_IsWalkEast + 1, MetatileBehavior_IsSouthwardCurrent + 1, MetatileBehavior_IsNorthwardCurrent + 1
	.4byte MetatileBehavior_IsWestwardCurrent + 1, MetatileBehavior_IsEastwardCurrent + 1, MetatileBehavior_IsSlideSouth + 1, MetatileBehavior_IsSlideNorth + 1
	.4byte MetatileBehavior_IsSlideWest + 1, MetatileBehavior_IsSlideEast + 1, MetatileBehavior_IsWaterfall + 1, MetatileBehavior_IsSecretBaseJumpMat + 1
	.4byte MetatileBehavior_IsSecretBaseSpinMat + 1, MetatileBehavior_IsMuddySlope + 1

	.globl sForcedMovementFuncs
sForcedMovementFuncs: @ 0x846F864
	.4byte ForcedMovement_None + 1, ForcedMovement_Slip + 1, ForcedMovement_Slip + 1, ForcedMovement_WalkSouth + 1
	.4byte ForcedMovement_WalkNorth + 1, ForcedMovement_WalkWest + 1, ForcedMovement_WalkEast + 1, ForcedMovement_PushedSouthByCurrent + 1
	.4byte ForcedMovement_PushedNorthByCurrent + 1, ForcedMovement_PushedWestByCurrent + 1, ForcedMovement_PushedEastByCurrent + 1, ForcedMovement_SlideSouth + 1
	.4byte ForcedMovement_SlideNorth + 1, ForcedMovement_SlideWest + 1, ForcedMovement_SlideEast + 1, ForcedMovement_PushedSouthByCurrent + 1
	.4byte ForcedMovement_MatJump + 1, ForcedMovement_MatSpin + 1, ForcedMovement_MuddySlope + 1

	.globl sPlayerNotOnBikeFuncs
sPlayerNotOnBikeFuncs: @ 0x846F8B0
	.4byte PlayerNotOnBikeNotMoving + 1, PlayerNotOnBikeTurningInPlace + 1, PlayerNotOnBikeMoving + 1

	.globl sAcroBikeTrickMetatiles
sAcroBikeTrickMetatiles: @ 0x846F8BC
	.4byte MetatileBehavior_IsBumpySlope + 1, MetatileBehavior_IsIsolatedVerticalRail + 1, MetatileBehavior_IsIsolatedHorizontalRail + 1, MetatileBehavior_IsVerticalRail + 1, MetatileBehavior_IsHorizontalRail + 1

	.globl sAcroBikeTrickCollisionTypes
sAcroBikeTrickCollisionTypes: @ 0x846F8D0
	.byte 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x00, 0x00, 0x00

	.globl sPlayerAvatarTransitionFuncs
sPlayerAvatarTransitionFuncs: @ 0x846F8D8
	.4byte PlayerAvatarTransition_Normal + 1, PlayerAvatarTransition_MachBike + 1, PlayerAvatarTransition_AcroBike + 1, PlayerAvatarTransition_Surfing + 1
	.4byte PlayerAvatarTransition_Underwater + 1, PlayerAvatarTransition_ReturnToField + 1, PlayerAvatarTransition_Dummy + 1, PlayerAvatarTransition_Dummy + 1

	.globl sArrowWarpMetatileBehaviorChecks
sArrowWarpMetatileBehaviorChecks: @ 0x846F8F8
	.4byte MetatileBehavior_IsSouthArrowWarp + 1, MetatileBehavior_IsNorthArrowWarp + 1, MetatileBehavior_IsWestArrowWarp + 1, MetatileBehavior_IsEastArrowWarp + 1

	.globl gUnknown_846F908
gUnknown_846F908: @ 0x846F908
	.incbin "baserom_jp.gba", 0x46f908, 0x10

	.globl gUnknown_846F918
gUnknown_846F918: @ 0x846F918
	.incbin "baserom_jp.gba", 0x46f918, 0x10

	.globl gUnknown_846F928
gUnknown_846F928: @ 0x846F928
	.incbin "baserom_jp.gba", 0x46f928, 0x2

	.globl gUnknown_846F92A
gUnknown_846F92A: @ 0x846F92A
	.incbin "baserom_jp.gba", 0x46f92a, 0x2

	.globl gUnknown_846F92C
gUnknown_846F92C: @ 0x846F92C
	.incbin "baserom_jp.gba", 0x46f92c, 0x14

	.globl sArrowWarpMetatileBehaviorChecks2
sArrowWarpMetatileBehaviorChecks2: @ 0x846F940
	.4byte MetatileBehavior_IsSouthArrowWarp + 1, MetatileBehavior_IsNorthArrowWarp + 1, MetatileBehavior_IsWestArrowWarp + 1, MetatileBehavior_IsEastArrowWarp + 1

	.globl gUnknown_846F950
gUnknown_846F950: @ 0x846F950
	.incbin "baserom_jp.gba", 0x46f950, 0xc

	.globl gUnknown_846F95C
gUnknown_846F95C: @ 0x846F95C
	.incbin "baserom_jp.gba", 0x46f95c, 0x4

	.globl sPlayerAvatarSecretBaseMatSpin
sPlayerAvatarSecretBaseMatSpin: @ 0x846F960
	.4byte PlayerAvatar_SecretBaseMatSpinStep0 + 1, PlayerAvatar_SecretBaseMatSpinStep1 + 1, PlayerAvatar_SecretBaseMatSpinStep2 + 1, PlayerAvatar_SecretBaseMatSpinStep3 + 1

	.globl gUnknown_846F970
gUnknown_846F970: @ 0x846F970
	.incbin "baserom_jp.gba", 0x46f970, 0x4

	.globl gUnknown_846F974
gUnknown_846F974: @ 0x846F974
	.incbin "baserom_jp.gba", 0x46f974, 0x8

	.globl sFishingStateFuncs
sFishingStateFuncs: @ 0x846F97C
	.4byte Fishing_Init + 1, Fishing_GetRodOut + 1, Fishing_WaitBeforeDots + 1, Fishing_InitDots + 1, Fishing_ShowDots + 1, Fishing_CheckForBite + 1, Fishing_GotBite + 1, Fishing_WaitForA + 1
	.4byte Fishing_CheckMoreDots + 1, Fishing_MonOnHook + 1, Fishing_StartEncounter + 1, Fishing_NotEvenNibble + 1, Fishing_GotAway + 1, Fishing_NoMon + 1, Fishing_PutRodAway + 1, Fishing_EndNoMon + 1

	.globl gUnknown_846F9BC
gUnknown_846F9BC: @ 0x846F9BC
	.incbin "baserom_jp.gba", 0x46f9bc, 0x6

	.globl gUnknown_846F9C2
gUnknown_846F9C2: @ 0x846F9C2
	.incbin "baserom_jp.gba", 0x46f9c2, 0x6
