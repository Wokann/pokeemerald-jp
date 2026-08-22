// Static movement data reconstructed from the JP ROM.  The two section
// attributes are supplied by event_object_movement.c so the linker can retain
// the original split around the Figure-8 data owned by field_effect_helpers.

typedef bool8 (*GroundEffectMetatileFunc)(u8);
typedef void (*GroundEffectFunc)(struct ObjectEvent *, struct Sprite *);
typedef void (*GroundEffectTrackFunc)(struct ObjectEvent *, struct Sprite *, u8);
typedef void (*NpcStepFunc)(struct Sprite *, u8);

extern void GroundEffect_SpawnOnTallGrass(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_StepOnTallGrass(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_SpawnOnLongGrass(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_StepOnLongGrass(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_WaterReflection(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_IceReflection(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_FlowingWater(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_SandTracks(struct ObjectEvent *, struct Sprite *);
extern void sub_08096984(struct ObjectEvent *, struct Sprite *);
extern void sub_08096A54(void);
extern void GroundEffect_StepOnPuddle(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_SandHeap(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_JumpOnTallGrass(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_JumpOnLongGrass(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_JumpOnShallowWater(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_JumpOnWater(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_JumpLandingDust(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_ShortGrass(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_HotSprings(struct ObjectEvent *, struct Sprite *);
extern void GroundEffect_Seaweed(struct ObjectEvent *, struct Sprite *);

extern void DoTracksGroundEffect_None(struct ObjectEvent *, struct Sprite *, u8);
extern void DoTracksGroundEffect_Footprints(struct ObjectEvent *, struct Sprite *, u8);
extern void DoTracksGroundEffect_BikeTireTracks(struct ObjectEvent *, struct Sprite *, u8);

static void Step1(struct Sprite *, u8);
static void Step2(struct Sprite *, u8);
static void Step3(struct Sprite *, u8);
static void Step4(struct Sprite *, u8);
static void Step8(struct Sprite *, u8);

// 0x084E6A30: reflection flags, jump-landing lookup tables, elevations, and
// ground-effect dispatch.  Local names follow the pret owner where possible;
// the JP-only handlers retain their existing symbols.
EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const u32 sReflectionFlags[] =
{
    1 << 5, // REFL_TYPE_ICE
    1 << 4, // REFL_TYPE_WATER
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const GroundEffectMetatileFunc sJumpLandingMetatileFuncs[] =
{
    MetatileBehavior_IsTallGrass,
    MetatileBehavior_IsLongGrass,
    MetatileBehavior_IsPuddle,
    MetatileBehavior_IsSurfableWaterOrUnderwater,
    MetatileBehavior_IsShallowFlowingWater,
    MetatileBehavior_IsATile,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const u32 sJumpLandingFlags[] =
{
    1 << 12, // GROUND_EFFECT_FLAG_LAND_IN_TALL_GRASS
    1 << 13, // GROUND_EFFECT_FLAG_LAND_IN_LONG_GRASS
    1 << 14, // GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER
    1 << 15, // GROUND_EFFECT_FLAG_LAND_IN_DEEP_WATER
    1 << 14, // GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER
    1 << 16, // GROUND_EFFECT_FLAG_LAND_ON_NORMAL_GROUND
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const GroundEffectMetatileFunc sLedgeBehaviorFuncs[] =
{
    MetatileBehavior_IsJumpSouth,
    MetatileBehavior_IsJumpNorth,
    MetatileBehavior_IsJumpWest,
    MetatileBehavior_IsJumpEast,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const u8 sElevationToSubpriority[] =
{
    115, 115, 83, 115, 83, 115, 83, 115,
    83, 115, 83, 115, 83, 0, 0, 115,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const u8 sElevationToPriority[] =
{
    2, 2, 2, 2, 1, 2, 1, 2,
    1, 2, 1, 2, 1, 0, 0, 2,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const u8 sElevationToSubspriteTableNum[] =
{
    1, 1, 1, 1, 2, 1, 2, 1,
    2, 1, 2, 1, 2, 0, 0, 1,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const GroundEffectTrackFunc sGroundEffectTracksFuncs[] =
{
    DoTracksGroundEffect_None,
    DoTracksGroundEffect_Footprints,
    DoTracksGroundEffect_BikeTireTracks,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const u16 sSandFootprintsFieldEffectIds[] =
{
    FLDEFF_SAND_FOOTPRINTS,
    FLDEFF_DEEP_SAND_FOOTPRINTS,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const u8 sBikeTireTracksTransitions[4][4] =
{
    {1, 2, 7, 8},
    {1, 2, 6, 5},
    {5, 8, 3, 4},
    {6, 7, 3, 4},
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const GroundEffectFunc sGroundEffectFuncs[] =
{
    GroundEffect_SpawnOnTallGrass,
    GroundEffect_StepOnTallGrass,
    GroundEffect_SpawnOnLongGrass,
    GroundEffect_StepOnLongGrass,
    GroundEffect_WaterReflection,
    GroundEffect_IceReflection,
    GroundEffect_FlowingWater,
    GroundEffect_SandTracks,
    sub_08096984, // JP GroundEffect_DeepSandTracks
    (GroundEffectFunc)sub_08096A54, // JP GroundEffect_Ripple; arguments are unused
    GroundEffect_StepOnPuddle,
    GroundEffect_SandHeap,
    GroundEffect_JumpOnTallGrass,
    GroundEffect_JumpOnLongGrass,
    GroundEffect_JumpOnShallowWater,
    GroundEffect_JumpOnWater,
    GroundEffect_JumpLandingDust,
    GroundEffect_ShortGrass,
    GroundEffect_HotSprings,
    GroundEffect_Seaweed,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const NpcStepFunc sStep1Funcs[] =
{
    Step1, Step1, Step1, Step1, Step1, Step1, Step1, Step1,
    Step1, Step1, Step1, Step1, Step1, Step1, Step1, Step1,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const NpcStepFunc sStep2Funcs[] =
{
    Step2, Step2, Step2, Step2, Step2, Step2, Step2, Step2,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const NpcStepFunc sStep3Funcs[] =
{
    Step2, Step3, Step3, Step2, Step3, Step3,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const NpcStepFunc sStep4Funcs[] =
{
    Step4, Step4, Step4, Step4,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const NpcStepFunc sStep8Funcs[] =
{
    Step8, Step8,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const NpcStepFunc *const sNpcStepFuncTables[] =
{
    sStep1Funcs,
    sStep2Funcs,
    sStep3Funcs,
    sStep4Funcs,
    sStep8Funcs,
};

EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA static const s16 sStepTimes[] =
{
    16, 8, 6, 4, 2,
};

// 0x084E6C56: jump-height data. It follows the Figure-8 tables emitted by
// field_effect_helpers.c, so it intentionally lives in a second linker section.
// The pointer table starts at byte 0x32, which is not 4-byte aligned. Keeping
// the family as one packed object prevents the linker from inserting a section
// alignment gap before the first curve; linker aliases expose the named fields
// to the naked-asm consumers.
struct EventObjectMovementJumpData
{
    s8 jumpYHigh[16];
    s8 jumpYLow[16];
    s8 jumpYNormal[16];
    u8 jumpYTablePadding[2];
    const s8 *jumpYTable[3];
    s16 jumpDistanceToTime[3];
    u8 jumpDistanceToShift[4];
    s16 jumpSpecialDistanceToTime[3];
    u8 jumpSpecialDistanceToShift[4];
    char sourceFile[10];
    u8 sourceFilePadding[2];
    char assertExpression[2];
    u8 assertPadding[2];
} __attribute__((packed));

EVENT_OBJECT_MOVEMENT_JUMP_DATA static const struct EventObjectMovementJumpData sEventObjectMovementJumpData =
{
    .jumpYHigh =
    {
         -4,  -6,  -8, -10, -11, -12, -12, -12,
        -11, -10,  -9,  -8,  -6,  -4,   0,   0,
    },
    .jumpYLow =
    {
         0,  -2,  -3,  -4,  -5,  -6,  -6,  -6,
        -5,  -5,  -4,  -3,  -2,   0,   0,   0,
    },
    .jumpYNormal =
    {
        -2,  -4,  -6,  -8,  -9, -10, -10, -10,
        -9,  -8,  -6,  -5,  -3,  -2,   0,   0,
    },
    .jumpYTable =
    {
        sEventObjectMovementJumpData.jumpYHigh,
        sEventObjectMovementJumpData.jumpYLow,
        sEventObjectMovementJumpData.jumpYNormal,
    },
    .jumpDistanceToTime = {16, 16, 32},
    .jumpDistanceToShift = {0, 0, 1, 0},
    .jumpSpecialDistanceToTime = {32, 32, 64},
    .jumpSpecialDistanceToShift = {1, 1, 2, 0},
    .sourceFile = "evobjmv.c",
    .assertExpression = "0",
};
