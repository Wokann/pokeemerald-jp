// Event Object movement-function tables.
//
// This follows pret's table ownership and order, while preserving the JP ROM
// targets where they differ from the US release.  The includer supplies
// EVENT_OBJECT_MOVEMENT_FUNCTION_TABLES so all definitions remain one exact
// linker-placed data block.

#define MOVEMENT_TYPE_FUNC_TABLE(name, ...) \
    u8 (*const name[])(struct ObjectEvent *, struct Sprite *) EVENT_OBJECT_MOVEMENT_FUNCTION_TABLES = { __VA_ARGS__ }

#define VECTOR_DIRECTION_FUNC_TABLE(name, ...) \
    u8 (*const name[])(s16, s16, s16, s16) EVENT_OBJECT_MOVEMENT_FUNCTION_TABLES = { __VA_ARGS__ }

#define COPY_PLAYER_MOVEMENT_FUNC_TABLE(name, ...) \
    bool8 (*const name[])(struct ObjectEvent *, struct Sprite *, u8, bool8(u8)) EVENT_OBJECT_MOVEMENT_FUNCTION_TABLES = { __VA_ARGS__ }

#define MOVEMENT_DELAY_TABLE(name, ...) \
    const s16 name[] EVENT_OBJECT_MOVEMENT_FUNCTION_TABLES = { __VA_ARGS__ }

#define MOVEMENT_DIRECTION_TABLE(name, ...) \
    const u8 name[] EVENT_OBJECT_MOVEMENT_FUNCTION_TABLES = { __VA_ARGS__ }

#define MOVEMENT_TABLE_PADDING(name, ...) \
    static const u8 name[] EVENT_OBJECT_MOVEMENT_FUNCTION_TABLES = { __VA_ARGS__ }

MOVEMENT_DELAY_TABLE(sMovementDelaysMedium, 32, 64, 96, 128);
MOVEMENT_DELAY_TABLE(sMovementDelaysLong, 32, 64, 128, 192);
MOVEMENT_DELAY_TABLE(sMovementDelaysShort, 32, 48, 64, 80);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WanderAround,
    MovementType_WanderAround_Step0,
    MovementType_WanderAround_Step1,
    MovementType_WanderAround_Step2,
    MovementType_WanderAround_Step3,
    MovementType_WanderAround_Step4,
    MovementType_WanderAround_Step5,
    MovementType_WanderAround_Step6);

MOVEMENT_DIRECTION_TABLE(gStandardDirections, DIR_SOUTH, DIR_NORTH, DIR_WEST, DIR_EAST);

VECTOR_DIRECTION_FUNC_TABLE(gGetVectorDirectionFuncs,
    GetVectorDirection,
    GetLimitedVectorDirection_SouthNorth,
    GetLimitedVectorDirection_WestEast,
    GetLimitedVectorDirection_WestNorth,
    GetLimitedVectorDirection_EastNorth,
    GetLimitedVectorDirection_WestSouth,
    GetLimitedVectorDirection_EastSouth,
    GetLimitedVectorDirection_SouthNorthWest,
    GetLimitedVectorDirection_SouthNorthEast,
    GetLimitedVectorDirection_NorthWestEast,
    GetLimitedVectorDirection_SouthWestEast);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_LookAround,
    MovementType_LookAround_Step0,
    MovementType_LookAround_Step1,
    MovementType_LookAround_Step2,
    MovementType_LookAround_Step3,
    MovementType_LookAround_Step4);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WanderUpAndDown,
    MovementType_WanderUpAndDown_Step0,
    MovementType_WanderUpAndDown_Step1,
    MovementType_WanderUpAndDown_Step2,
    MovementType_WanderUpAndDown_Step3,
    MovementType_WanderUpAndDown_Step4,
    MovementType_WanderUpAndDown_Step5,
    MovementType_WanderUpAndDown_Step6);

MOVEMENT_DIRECTION_TABLE(gUpAndDownDirections, DIR_SOUTH, DIR_NORTH);
MOVEMENT_TABLE_PADDING(sMovementTypeFuncTablesPadding_5BC6, 0, 0);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WanderLeftAndRight,
    MovementType_WanderLeftAndRight_Step0,
    MovementType_WanderLeftAndRight_Step1,
    MovementType_WanderLeftAndRight_Step2,
    MovementType_WanderLeftAndRight_Step3,
    MovementType_WanderLeftAndRight_Step4,
    MovementType_WanderLeftAndRight_Step5,
    MovementType_WanderLeftAndRight_Step6);

MOVEMENT_DIRECTION_TABLE(gLeftAndRightDirections, DIR_WEST, DIR_EAST);
MOVEMENT_TABLE_PADDING(sMovementTypeFuncTablesPadding_5BE6, 0, 0);

// JP points this third step at the Invisible handler; the US release does not.
MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceDirection,
    MovementType_FaceDirection_Step0,
    MovementType_FaceDirection_Step1,
    MovementType_Invisible_Step2);

// JP retains the original Step names for this five-entry dispatch table.
MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_BerryTreeGrowth,
    MovementType_BerryTreeGrowth_Step0,
    MovementType_BerryTreeGrowth_Step1,
    MovementType_BerryTreeGrowth_Step2,
    MovementType_BerryTreeGrowth_Sparkle,
    MovementType_BerryTreeGrowth_Step4);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceDownAndUp,
    MovementType_FaceDownAndUp_Step0,
    MovementType_FaceDownAndUp_Step1,
    MovementType_FaceDownAndUp_Step2,
    MovementType_FaceDownAndUp_Step3,
    MovementType_FaceDownAndUp_Step4);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceLeftAndRight,
    MovementType_FaceLeftAndRight_Step0,
    MovementType_FaceLeftAndRight_Step1,
    MovementType_FaceLeftAndRight_Step2,
    MovementType_FaceLeftAndRight_Step3,
    MovementType_FaceLeftAndRight_Step4);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceUpAndLeft,
    MovementType_FaceUpAndLeft_Step0,
    MovementType_FaceUpAndLeft_Step1,
    MovementType_FaceUpAndLeft_Step2,
    MovementType_FaceUpAndLeft_Step3,
    MovementType_FaceUpAndLeft_Step4);

MOVEMENT_DIRECTION_TABLE(gUpAndLeftDirections, DIR_NORTH, DIR_WEST);
MOVEMENT_TABLE_PADDING(sMovementTypeFuncTablesPadding_5C46, 0, 0);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceUpAndRight,
    MovementType_FaceUpAndRight_Step0,
    MovementType_FaceUpAndRight_Step1,
    MovementType_FaceUpAndRight_Step2,
    MovementType_FaceUpAndRight_Step3,
    MovementType_FaceUpAndRight_Step4);

MOVEMENT_DIRECTION_TABLE(gUpAndRightDirections, DIR_NORTH, DIR_EAST);
MOVEMENT_TABLE_PADDING(sMovementTypeFuncTablesPadding_5C5E, 0, 0);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceDownAndLeft,
    MovementType_FaceDownAndLeft_Step0,
    MovementType_FaceDownAndLeft_Step1,
    MovementType_FaceDownAndLeft_Step2,
    MovementType_FaceDownAndLeft_Step3,
    MovementType_FaceDownAndLeft_Step4);

MOVEMENT_DIRECTION_TABLE(gDownAndLeftDirections, DIR_SOUTH, DIR_WEST);
MOVEMENT_TABLE_PADDING(sMovementTypeFuncTablesPadding_5C76, 0, 0);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceDownAndRight,
    MovementType_FaceDownAndRight_Step0,
    MovementType_FaceDownAndRight_Step1,
    MovementType_FaceDownAndRight_Step2,
    MovementType_FaceDownAndRight_Step3,
    MovementType_FaceDownAndRight_Step4);

MOVEMENT_DIRECTION_TABLE(gDownAndRightDirections, DIR_SOUTH, DIR_EAST);
MOVEMENT_TABLE_PADDING(sMovementTypeFuncTablesPadding_5C8E, 0, 0);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceDownUpAndLeft,
    MovementType_FaceDownUpAndLeft_Step0,
    MovementType_FaceDownUpAndLeft_Step1,
    MovementType_FaceDownUpAndLeft_Step2,
    MovementType_FaceDownUpAndLeft_Step3,
    MovementType_FaceDownUpAndLeft_Step4);

MOVEMENT_DIRECTION_TABLE(gDownUpAndLeftDirections, DIR_NORTH, DIR_SOUTH, DIR_WEST, DIR_SOUTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceDownUpAndRight,
    MovementType_FaceDownUpAndRight_Step0,
    MovementType_FaceDownUpAndRight_Step1,
    MovementType_FaceDownUpAndRight_Step2,
    MovementType_FaceDownUpAndRight_Step3,
    MovementType_FaceDownUpAndRight_Step4);

MOVEMENT_DIRECTION_TABLE(gDownUpAndRightDirections, DIR_SOUTH, DIR_NORTH, DIR_EAST, DIR_SOUTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceUpLeftAndRight,
    MovementType_FaceUpLeftAndRight_Step0,
    MovementType_FaceUpLeftAndRight_Step1,
    MovementType_FaceUpLeftAndRight_Step2,
    MovementType_FaceUpLeftAndRight_Step3,
    MovementType_FaceUpLeftAndRight_Step4);

MOVEMENT_DIRECTION_TABLE(gUpLeftAndRightDirections, DIR_NORTH, DIR_WEST, DIR_EAST, DIR_NORTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_FaceDownLeftAndRight,
    MovementType_FaceDownLeftAndRight_Step0,
    MovementType_FaceDownLeftAndRight_Step1,
    MovementType_FaceDownLeftAndRight_Step2,
    MovementType_FaceDownLeftAndRight_Step3,
    MovementType_FaceDownLeftAndRight_Step4);

MOVEMENT_DIRECTION_TABLE(gDownLeftAndRightDirections, DIR_WEST, DIR_EAST, DIR_SOUTH, DIR_SOUTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_RotateCounterclockwise,
    MovementType_RotateCounterclockwise_Step0,
    MovementType_RotateCounterclockwise_Step1,
    MovementType_RotateCounterclockwise_Step2,
    MovementType_RotateCounterclockwise_Step3);

MOVEMENT_DIRECTION_TABLE(gCounterclockwiseDirections, DIR_SOUTH, DIR_EAST, DIR_WEST, DIR_SOUTH, DIR_NORTH);
MOVEMENT_TABLE_PADDING(sMovementTypeFuncTablesPadding_5D05, 0, 0, 0);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_RotateClockwise,
    MovementType_RotateClockwise_Step0,
    MovementType_RotateClockwise_Step1,
    MovementType_RotateClockwise_Step2,
    MovementType_RotateClockwise_Step3);

MOVEMENT_DIRECTION_TABLE(gClockwiseDirections, DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH);
MOVEMENT_TABLE_PADDING(sMovementTypeFuncTablesPadding_5D1D, 0, 0, 0);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkBackAndForth,
    MovementType_WalkBackAndForth_Step0,
    MovementType_WalkBackAndForth_Step1,
    MovementType_WalkBackAndForth_Step2,
    MovementType_WalkBackAndForth_Step3);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceUpRightLeftDown,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpRightLeftDown_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gUpRightLeftDownDirections, DIR_NORTH, DIR_EAST, DIR_WEST, DIR_SOUTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceRightLeftDownUp,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightLeftDownUp_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gRightLeftDownUpDirections, DIR_EAST, DIR_WEST, DIR_SOUTH, DIR_NORTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceDownUpRightLeft,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownUpRightLeft_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gDownUpRightLeftDirections, DIR_SOUTH, DIR_NORTH, DIR_EAST, DIR_WEST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceLeftDownUpRight,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftDownUpRight_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gLeftDownUpRightDirections, DIR_WEST, DIR_SOUTH, DIR_NORTH, DIR_EAST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceUpLeftRightDown,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpLeftRightDown_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gUpLeftRightDownDirections, DIR_NORTH, DIR_WEST, DIR_EAST, DIR_SOUTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceLeftRightDownUp,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftRightDownUp_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gLeftRightDownUpDirections, DIR_WEST, DIR_EAST, DIR_SOUTH, DIR_NORTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceDownUpLeftRight,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownUpLeftRight_Step1,
    MovementType_WalkSequence_Step2);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceRightDownUpLeft,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightDownUpLeft_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gRightDownUpLeftDirections, DIR_EAST, DIR_SOUTH, DIR_NORTH, DIR_WEST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceLeftUpDownRight,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftUpDownRight_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gLeftUpDownRightDirections, DIR_WEST, DIR_NORTH, DIR_SOUTH, DIR_EAST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceUpDownRightLeft,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpDownRightLeft_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gUpDownRightLeftDirections, DIR_NORTH, DIR_SOUTH, DIR_EAST, DIR_WEST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceRightLeftUpDown,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightLeftUpDown_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gRightLeftUpDownDirections, DIR_EAST, DIR_WEST, DIR_NORTH, DIR_SOUTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceDownRightLeftUp,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownRightLeftUp_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gDownRightLeftUpDirections, DIR_SOUTH, DIR_EAST, DIR_WEST, DIR_NORTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceRightUpDownLeft,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightUpDownLeft_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gRightUpDownLeftDirections, DIR_EAST, DIR_NORTH, DIR_SOUTH, DIR_WEST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceUpDownLeftRight,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpDownLeftRight_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gUpDownLeftRightDirections, DIR_NORTH, DIR_SOUTH, DIR_WEST, DIR_EAST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceLeftRightUpDown,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftRightUpDown_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gLeftRightUpDownDirections, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceDownLeftRightUp,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownLeftRightUp_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gDownLeftRightUpDirections, DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceUpLeftDownRight,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpLeftDownRight_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gUpLeftDownRightDirections, DIR_NORTH, DIR_WEST, DIR_SOUTH, DIR_EAST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceDownRightUpLeft,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownRightUpLeft_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gDownRightUpLeftDirections, DIR_SOUTH, DIR_EAST, DIR_NORTH, DIR_WEST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceLeftDownRightUp,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftDownRightUp_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gLeftDownRightUpDirections, DIR_WEST, DIR_SOUTH, DIR_EAST, DIR_NORTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceRightUpLeftDown,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightUpLeftDown_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gRightUpLeftDownDirections, DIR_EAST, DIR_NORTH, DIR_WEST, DIR_SOUTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceUpRightDownLeft,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceUpRightDownLeft_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gUpRightDownLeftDirections, DIR_NORTH, DIR_EAST, DIR_SOUTH, DIR_WEST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceDownLeftUpRight,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceDownLeftUpRight_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gDownLeftUpRightDirections, DIR_SOUTH, DIR_WEST, DIR_NORTH, DIR_EAST);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceLeftUpRightDown,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceLeftUpRightDown_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gLeftUpRightDownDirections, DIR_WEST, DIR_NORTH, DIR_EAST, DIR_SOUTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSequenceRightDownLeftUp,
    MovementType_WalkSequence_Step0,
    MovementType_WalkSequenceRightDownLeftUp_Step1,
    MovementType_WalkSequence_Step2);
MOVEMENT_DIRECTION_TABLE(gRightDownLeftUpDirections, DIR_EAST, DIR_SOUTH, DIR_WEST, DIR_NORTH);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_CopyPlayer,
    MovementType_CopyPlayer_Step0,
    MovementType_CopyPlayer_Step1,
    MovementType_CopyPlayer_Step2);

// JP dispatches to its GoSpeed/cph symbols; do not substitute US aliases.
COPY_PLAYER_MOVEMENT_FUNC_TABLE(gCopyPlayerMovementFuncs,
    CopyablePlayerMovement_None,
    CopyablePlayerMovement_FaceDirection,
    CopyablePlayerMovement_GoSpeed0,
    CopyablePlayerMovement_GoSpeed1,
    CopyablePlayerMovement_GoSpeed2,
    CopyablePlayerMovement_Slide,
    cph_IM_DIFFERENT,
    CopyablePlayerMovement_GoSpeed4,
    CopyablePlayerMovement_Jump,
    CopyablePlayerMovement_None,
    CopyablePlayerMovement_None);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_CopyPlayerInGrass,
    MovementType_CopyPlayer_Step0,
    MovementType_CopyPlayerInGrass_Step1,
    MovementType_CopyPlayer_Step2);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_Buried, MovementType_Hidden_Step0);

MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkInPlace,
    MovementType_WalkInPlace_Step0,
    MovementType_MoveInPlace_Step1);
MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_WalkSlowlyInPlace,
    MovementType_WalkSlowlyInPlace_Step0,
    MovementType_MoveInPlace_Step1);
MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_JogInPlace,
    MovementType_JogInPlace_Step0,
    MovementType_MoveInPlace_Step1);
MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_RunInPlace,
    MovementType_RunInPlace_Step0,
    MovementType_MoveInPlace_Step1);

// JP uses the FaceDirection third step here, paired with the earlier swap.
MOVEMENT_TYPE_FUNC_TABLE(gMovementTypeFuncs_Invisible,
    MovementType_Invisible_Step0,
    MovementType_Invisible_Step1,
    MovementType_FaceDirection_Step2);

#undef MOVEMENT_TYPE_FUNC_TABLE
#undef VECTOR_DIRECTION_FUNC_TABLE
#undef COPY_PLAYER_MOVEMENT_FUNC_TABLE
#undef MOVEMENT_DELAY_TABLE
#undef MOVEMENT_DIRECTION_TABLE
#undef MOVEMENT_TABLE_PADDING
