#ifndef GUARD_DATA_FIELD_PLAYER_AVATAR_H
#define GUARD_DATA_FIELD_PLAYER_AVATAR_H

// Shared by the JP main and tail code objects; keep native data order.
#define PLAYER_AVATAR_TABLES __attribute__((section(".rodata.field_player_avatar_tables"), aligned(1)))
#define PLAYER_AVATAR_POINTERS __attribute__((section(".rodata.field_player_avatar_tables"), aligned(4)))
#define PLAYER_AVATAR_FISHING __attribute__((section(".rodata.field_player_avatar_fishing"), aligned(2)))
#define PLAYER_AVATAR_SPIN __attribute__((section(".rodata.field_player_avatar_spin_directions"), aligned(1)))

bool8 ForcedMovement_None(void);
bool8 ForcedMovement_Slip(void);
bool8 ForcedMovement_WalkSouth(void);
bool8 ForcedMovement_WalkNorth(void);
bool8 ForcedMovement_WalkWest(void);
bool8 ForcedMovement_WalkEast(void);
bool8 ForcedMovement_PushedSouthByCurrent(void);
bool8 ForcedMovement_PushedNorthByCurrent(void);
bool8 ForcedMovement_PushedWestByCurrent(void);
bool8 ForcedMovement_PushedEastByCurrent(void);
bool8 ForcedMovement_SlideSouth(void);
bool8 ForcedMovement_SlideNorth(void);
bool8 ForcedMovement_SlideWest(void);
bool8 ForcedMovement_SlideEast(void);
bool8 ForcedMovement_MatJump(void);
bool8 ForcedMovement_MatSpin(void);
bool8 ForcedMovement_MuddySlope(void);
void PlayerNotOnBikeNotMoving(u8 direction, u16 heldKeys);
void PlayerNotOnBikeTurningInPlace(u8 direction, u16 heldKeys);
void PlayerNotOnBikeMoving(u8 direction, u16 heldKeys);
void PlayerAvatarTransition_Normal(struct ObjectEvent *objEvent);
void PlayerAvatarTransition_MachBike(struct ObjectEvent *objEvent);
void PlayerAvatarTransition_AcroBike(struct ObjectEvent *objEvent);
void PlayerAvatarTransition_Surfing(struct ObjectEvent *objEvent);
void PlayerAvatarTransition_Underwater(struct ObjectEvent *objEvent);
void PlayerAvatarTransition_ReturnToField(struct ObjectEvent *objEvent);
void PlayerAvatarTransition_Dummy(struct ObjectEvent *objEvent);
bool8 PushBoulder_Start(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder);
bool8 PushBoulder_Move(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder);
bool8 PushBoulder_End(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder);
u8 PlayerAvatar_DoSecretBaseMatJump(struct Task *task, struct ObjectEvent *objectEvent);
bool8 PlayerAvatar_SecretBaseMatSpinStep0(struct Task *task, struct ObjectEvent *objectEvent);
bool8 PlayerAvatar_SecretBaseMatSpinStep1(struct Task *task, struct ObjectEvent *objectEvent);
bool8 PlayerAvatar_SecretBaseMatSpinStep2(struct Task *task, struct ObjectEvent *objectEvent);
bool8 PlayerAvatar_SecretBaseMatSpinStep3(struct Task *task, struct ObjectEvent *objectEvent);
bool8 Fishing_Init(struct Task *task);
bool8 Fishing_GetRodOut(struct Task *task);
bool8 Fishing_WaitBeforeDots(struct Task *task);
bool8 Fishing_InitDots(struct Task *task);
bool8 Fishing_ShowDots(struct Task *task);
bool8 Fishing_CheckForBite(struct Task *task);
bool8 Fishing_GotBite(struct Task *task);
bool8 Fishing_WaitForA(struct Task *task);
bool8 Fishing_CheckMoreDots(struct Task *task);
bool8 Fishing_MonOnHook(struct Task *task);
bool8 Fishing_StartEncounter(struct Task *task);
bool8 Fishing_NotEvenNibble(struct Task *task);
bool8 Fishing_GotAway(struct Task *task);
bool8 Fishing_NoMon(struct Task *task);
bool8 Fishing_PutRodAway(struct Task *task);
bool8 Fishing_EndNoMon(struct Task *task);

PLAYER_AVATAR_POINTERS bool8 (*const sForcedMovementTestFuncs[NUM_FORCED_MOVEMENTS])(u8) =
{
    MetatileBehavior_IsTrickHouseSlipperyFloor,
    MetatileBehavior_IsIce,
    MetatileBehavior_IsWalkSouth,
    MetatileBehavior_IsWalkNorth,
    MetatileBehavior_IsWalkWest,
    MetatileBehavior_IsWalkEast,
    MetatileBehavior_IsSouthwardCurrent,
    MetatileBehavior_IsNorthwardCurrent,
    MetatileBehavior_IsWestwardCurrent,
    MetatileBehavior_IsEastwardCurrent,
    MetatileBehavior_IsSlideSouth,
    MetatileBehavior_IsSlideNorth,
    MetatileBehavior_IsSlideWest,
    MetatileBehavior_IsSlideEast,
    MetatileBehavior_IsWaterfall,
    MetatileBehavior_IsSecretBaseJumpMat,
    MetatileBehavior_IsSecretBaseSpinMat,
    MetatileBehavior_IsMuddySlope,
};

// + 1 for ForcedMovement_None, which is excluded above
PLAYER_AVATAR_POINTERS bool8 (*const sForcedMovementFuncs[NUM_FORCED_MOVEMENTS + 1])(void) =
{
    ForcedMovement_None,
    ForcedMovement_Slip,
    ForcedMovement_Slip,
    ForcedMovement_WalkSouth,
    ForcedMovement_WalkNorth,
    ForcedMovement_WalkWest,
    ForcedMovement_WalkEast,
    ForcedMovement_PushedSouthByCurrent,
    ForcedMovement_PushedNorthByCurrent,
    ForcedMovement_PushedWestByCurrent,
    ForcedMovement_PushedEastByCurrent,
    ForcedMovement_SlideSouth,
    ForcedMovement_SlideNorth,
    ForcedMovement_SlideWest,
    ForcedMovement_SlideEast,
    ForcedMovement_PushedSouthByCurrent,
    ForcedMovement_MatJump,
    ForcedMovement_MatSpin,
    ForcedMovement_MuddySlope,
};

PLAYER_AVATAR_POINTERS void (*const sPlayerNotOnBikeFuncs[])(u8, u16) =
{
    [NOT_MOVING]     = PlayerNotOnBikeNotMoving,
    [TURN_DIRECTION] = PlayerNotOnBikeTurningInPlace,
    [MOVING]         = PlayerNotOnBikeMoving,
};

PLAYER_AVATAR_POINTERS bool8 (*const sAcroBikeTrickMetatiles[NUM_ACRO_BIKE_COLLISIONS])(u8) =
{
    MetatileBehavior_IsBumpySlope,
    MetatileBehavior_IsIsolatedVerticalRail,
    MetatileBehavior_IsIsolatedHorizontalRail,
    MetatileBehavior_IsVerticalRail,
    MetatileBehavior_IsHorizontalRail,
};

PLAYER_AVATAR_TABLES const u8 sAcroBikeTrickCollisionTypes[NUM_ACRO_BIKE_COLLISIONS] = {
    COLLISION_WHEELIE_HOP,
    COLLISION_ISOLATED_VERTICAL_RAIL,
    COLLISION_ISOLATED_HORIZONTAL_RAIL,
    COLLISION_VERTICAL_RAIL,
    COLLISION_HORIZONTAL_RAIL,
};

PLAYER_AVATAR_POINTERS void (*const sPlayerAvatarTransitionFuncs[])(struct ObjectEvent *) =
{
    [PLAYER_AVATAR_STATE_NORMAL]     = PlayerAvatarTransition_Normal,
    [PLAYER_AVATAR_STATE_MACH_BIKE]  = PlayerAvatarTransition_MachBike,
    [PLAYER_AVATAR_STATE_ACRO_BIKE]  = PlayerAvatarTransition_AcroBike,
    [PLAYER_AVATAR_STATE_SURFING]    = PlayerAvatarTransition_Surfing,
    [PLAYER_AVATAR_STATE_UNDERWATER] = PlayerAvatarTransition_Underwater,
    [PLAYER_AVATAR_STATE_FIELD_MOVE] = PlayerAvatarTransition_ReturnToField,
    [PLAYER_AVATAR_STATE_FISHING]    = PlayerAvatarTransition_Dummy,
    [PLAYER_AVATAR_STATE_WATERING]   = PlayerAvatarTransition_Dummy,
};

PLAYER_AVATAR_POINTERS bool8 (*const sArrowWarpMetatileBehaviorChecks[])(u8) =
{
    [DIR_SOUTH - 1] = MetatileBehavior_IsSouthArrowWarp,
    [DIR_NORTH - 1] = MetatileBehavior_IsNorthArrowWarp,
    [DIR_WEST - 1]  = MetatileBehavior_IsWestArrowWarp,
    [DIR_EAST - 1]  = MetatileBehavior_IsEastArrowWarp,
};

PLAYER_AVATAR_TABLES const u8 sRivalAvatarGfxIds[][GENDER_COUNT] =
{
    [PLAYER_AVATAR_STATE_NORMAL]     = {OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL,     OBJ_EVENT_GFX_RIVAL_MAY_NORMAL},
    [PLAYER_AVATAR_STATE_MACH_BIKE]  = {OBJ_EVENT_GFX_RIVAL_BRENDAN_MACH_BIKE,  OBJ_EVENT_GFX_RIVAL_MAY_MACH_BIKE},
    [PLAYER_AVATAR_STATE_ACRO_BIKE]  = {OBJ_EVENT_GFX_RIVAL_BRENDAN_ACRO_BIKE,  OBJ_EVENT_GFX_RIVAL_MAY_ACRO_BIKE},
    [PLAYER_AVATAR_STATE_SURFING]    = {OBJ_EVENT_GFX_RIVAL_BRENDAN_SURFING,    OBJ_EVENT_GFX_RIVAL_MAY_SURFING},
    [PLAYER_AVATAR_STATE_UNDERWATER] = {OBJ_EVENT_GFX_BRENDAN_UNDERWATER,       OBJ_EVENT_GFX_MAY_UNDERWATER},
    [PLAYER_AVATAR_STATE_FIELD_MOVE] = {OBJ_EVENT_GFX_RIVAL_BRENDAN_FIELD_MOVE, OBJ_EVENT_GFX_RIVAL_MAY_FIELD_MOVE},
    [PLAYER_AVATAR_STATE_FISHING]    = {OBJ_EVENT_GFX_BRENDAN_FISHING,          OBJ_EVENT_GFX_MAY_FISHING},
    [PLAYER_AVATAR_STATE_WATERING]   = {OBJ_EVENT_GFX_BRENDAN_WATERING,         OBJ_EVENT_GFX_MAY_WATERING}
};

PLAYER_AVATAR_TABLES const u8 sPlayerAvatarGfxIds[][GENDER_COUNT] =
{
    [PLAYER_AVATAR_STATE_NORMAL]     = {OBJ_EVENT_GFX_BRENDAN_NORMAL,     OBJ_EVENT_GFX_MAY_NORMAL},
    [PLAYER_AVATAR_STATE_MACH_BIKE]  = {OBJ_EVENT_GFX_BRENDAN_MACH_BIKE,  OBJ_EVENT_GFX_MAY_MACH_BIKE},
    [PLAYER_AVATAR_STATE_ACRO_BIKE]  = {OBJ_EVENT_GFX_BRENDAN_ACRO_BIKE,  OBJ_EVENT_GFX_MAY_ACRO_BIKE},
    [PLAYER_AVATAR_STATE_SURFING]    = {OBJ_EVENT_GFX_BRENDAN_SURFING,    OBJ_EVENT_GFX_MAY_SURFING},
    [PLAYER_AVATAR_STATE_UNDERWATER] = {OBJ_EVENT_GFX_BRENDAN_UNDERWATER, OBJ_EVENT_GFX_MAY_UNDERWATER},
    [PLAYER_AVATAR_STATE_FIELD_MOVE] = {OBJ_EVENT_GFX_BRENDAN_FIELD_MOVE, OBJ_EVENT_GFX_MAY_FIELD_MOVE},
    [PLAYER_AVATAR_STATE_FISHING]    = {OBJ_EVENT_GFX_BRENDAN_FISHING,    OBJ_EVENT_GFX_MAY_FISHING},
    [PLAYER_AVATAR_STATE_WATERING]   = {OBJ_EVENT_GFX_BRENDAN_WATERING,   OBJ_EVENT_GFX_MAY_WATERING},
};

PLAYER_AVATAR_TABLES const u8 sFRLGAvatarGfxIds[GENDER_COUNT] =
{
    [MALE]   = OBJ_EVENT_GFX_RED,
    [FEMALE] = OBJ_EVENT_GFX_LEAF
};

PLAYER_AVATAR_TABLES const u8 sRSAvatarGfxIds[GENDER_COUNT] =
{
    [MALE]   = OBJ_EVENT_GFX_LINK_RS_BRENDAN,
    [FEMALE] = OBJ_EVENT_GFX_LINK_RS_MAY
};

PLAYER_AVATAR_TABLES const u8 sPlayerAvatarGfxToStateFlag[GENDER_COUNT][5][2] =
{
    [MALE] =
    {
        {OBJ_EVENT_GFX_BRENDAN_NORMAL,     PLAYER_AVATAR_FLAG_ON_FOOT},
        {OBJ_EVENT_GFX_BRENDAN_MACH_BIKE,  PLAYER_AVATAR_FLAG_MACH_BIKE},
        {OBJ_EVENT_GFX_BRENDAN_ACRO_BIKE,  PLAYER_AVATAR_FLAG_ACRO_BIKE},
        {OBJ_EVENT_GFX_BRENDAN_SURFING,    PLAYER_AVATAR_FLAG_SURFING},
        {OBJ_EVENT_GFX_BRENDAN_UNDERWATER, PLAYER_AVATAR_FLAG_UNDERWATER},
    },
    [FEMALE] =
    {
        {OBJ_EVENT_GFX_MAY_NORMAL,         PLAYER_AVATAR_FLAG_ON_FOOT},
        {OBJ_EVENT_GFX_MAY_MACH_BIKE,      PLAYER_AVATAR_FLAG_MACH_BIKE},
        {OBJ_EVENT_GFX_MAY_ACRO_BIKE,      PLAYER_AVATAR_FLAG_ACRO_BIKE},
        {OBJ_EVENT_GFX_MAY_SURFING,        PLAYER_AVATAR_FLAG_SURFING},
        {OBJ_EVENT_GFX_MAY_UNDERWATER,     PLAYER_AVATAR_FLAG_UNDERWATER},
    }
};

PLAYER_AVATAR_POINTERS bool8 (*const sArrowWarpMetatileBehaviorChecks2[])(u8) =  //Duplicate of sArrowWarpMetatileBehaviorChecks
{
    [DIR_SOUTH - 1] = MetatileBehavior_IsSouthArrowWarp,
    [DIR_NORTH - 1] = MetatileBehavior_IsNorthArrowWarp,
    [DIR_WEST - 1]  = MetatileBehavior_IsWestArrowWarp,
    [DIR_EAST - 1]  = MetatileBehavior_IsEastArrowWarp,
};

PLAYER_AVATAR_POINTERS bool8 (*const sPushBoulderFuncs[])(struct Task *, struct ObjectEvent *, struct ObjectEvent *) =
{
    PushBoulder_Start,
    PushBoulder_Move,
    PushBoulder_End,
};

PLAYER_AVATAR_POINTERS bool8 (*const sPlayerAvatarSecretBaseMatJump[])(struct Task *, struct ObjectEvent *) =
{
    PlayerAvatar_DoSecretBaseMatJump,
};

PLAYER_AVATAR_POINTERS bool8 (*const sPlayerAvatarSecretBaseMatSpin[])(struct Task *, struct ObjectEvent *) =
{
    PlayerAvatar_SecretBaseMatSpinStep0,
    PlayerAvatar_SecretBaseMatSpinStep1,
    PlayerAvatar_SecretBaseMatSpinStep2,
    PlayerAvatar_SecretBaseMatSpinStep3,
};

PLAYER_AVATAR_TABLES const u8 sSecretBaseMatSpinDirections[] = {DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};
PLAYER_AVATAR_TABLES const u8 sSecretBaseMatSpinActions[] =
{
    MOVEMENT_ACTION_DELAY_1,
    MOVEMENT_ACTION_DELAY_1,
    MOVEMENT_ACTION_DELAY_2,
    MOVEMENT_ACTION_DELAY_4,
    MOVEMENT_ACTION_DELAY_8,
};

PLAYER_AVATAR_POINTERS bool8 (*const sFishingStateFuncs[])(struct Task *) =
{
    Fishing_Init,
    Fishing_GetRodOut,
    Fishing_WaitBeforeDots,
    Fishing_InitDots,
    Fishing_ShowDots,
    Fishing_CheckForBite,
    Fishing_GotBite,
    Fishing_WaitForA,
    Fishing_CheckMoreDots,
    Fishing_MonOnHook,
    Fishing_StartEncounter,
    Fishing_NotEvenNibble,
    Fishing_GotAway,
    Fishing_NoMon,
    Fishing_PutRodAway,
    Fishing_EndNoMon,
};

PLAYER_AVATAR_TABLES const s16 sFishingMinRounds1[] __attribute__((aligned(2))) = {1, 1, 1};
PLAYER_AVATAR_TABLES const s16 sFishingMinRounds2[] __attribute__((aligned(2))) = {1, 3, 6};

PLAYER_AVATAR_FISHING const s16 sFishingReelTimeouts[] = {36, 33, 30};
PLAYER_AVATAR_FISHING const s16 sFishingMoreDotsChance[][2] =
{
    {0, 0},
    {40, 10},
    {70, 30},
};

PLAYER_AVATAR_SPIN const u8 sSpinDirections[] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};

#undef PLAYER_AVATAR_TABLES
#undef PLAYER_AVATAR_POINTERS
#undef PLAYER_AVATAR_FISHING
#undef PLAYER_AVATAR_SPIN

#endif // GUARD_DATA_FIELD_PLAYER_AVATAR_H
