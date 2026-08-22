#include "global.h"

#define OBJECT_EVENT_GRAPHICS_CUT_GRASS __attribute__((section(".rodata.object_event_graphics_cut_grass"), aligned(1)))
#include "data/object_events/object_event_graphics.h"
#undef OBJECT_EVENT_GRAPHICS_CUT_GRASS
#include "event_object_movement.h"
#include "field_effect.h"
#include "overworld.h"
#include "field_camera.h"
#include "metatile_behavior.h"
#include "palette.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"

extern void MovementType_Hidden(struct Sprite *sprite);

#define EVENT_OBJECT_MOVEMENT_CORE_DATA __attribute__((section(".rodata.event_object_movement_core_data"), aligned(1)))

// This table is emitted at 0x084DD88C.  The JP build keeps its original
// MovementType_Hidden entry rather than substituting the US Buried symbol.
EVENT_OBJECT_MOVEMENT_CORE_DATA static void (*const sMovementTypeCallbacks[NUM_MOVEMENT_TYPES])(struct Sprite *) =
{
    [MOVEMENT_TYPE_NONE] = MovementType_None,
    [MOVEMENT_TYPE_LOOK_AROUND] = MovementType_LookAround,
    [MOVEMENT_TYPE_WANDER_AROUND] = MovementType_WanderAround,
    [MOVEMENT_TYPE_WANDER_UP_AND_DOWN] = MovementType_WanderUpAndDown,
    [MOVEMENT_TYPE_WANDER_DOWN_AND_UP] = MovementType_WanderUpAndDown,
    [MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT] = MovementType_WanderLeftAndRight,
    [MOVEMENT_TYPE_WANDER_RIGHT_AND_LEFT] = MovementType_WanderLeftAndRight,
    [MOVEMENT_TYPE_FACE_UP] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_FACE_DOWN] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_FACE_LEFT] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_FACE_RIGHT] = MovementType_FaceDirection,
    [MOVEMENT_TYPE_PLAYER] = MovementType_Player,
    [MOVEMENT_TYPE_BERRY_TREE_GROWTH] = MovementType_BerryTreeGrowth,
    [MOVEMENT_TYPE_FACE_DOWN_AND_UP] = MovementType_FaceDownAndUp,
    [MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT] = MovementType_FaceLeftAndRight,
    [MOVEMENT_TYPE_FACE_UP_AND_LEFT] = MovementType_FaceUpAndLeft,
    [MOVEMENT_TYPE_FACE_UP_AND_RIGHT] = MovementType_FaceUpAndRight,
    [MOVEMENT_TYPE_FACE_DOWN_AND_LEFT] = MovementType_FaceDownAndLeft,
    [MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT] = MovementType_FaceDownAndRight,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT] = MovementType_FaceDownUpAndLeft,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT] = MovementType_FaceDownUpAndRight,
    [MOVEMENT_TYPE_FACE_UP_LEFT_AND_RIGHT] = MovementType_FaceUpRightAndLeft,
    [MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT] = MovementType_FaceDownRightAndLeft,
    [MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE] = MovementType_RotateCounterclockwise,
    [MOVEMENT_TYPE_ROTATE_CLOCKWISE] = MovementType_RotateClockwise,
    [MOVEMENT_TYPE_WALK_UP_AND_DOWN] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_DOWN_AND_UP] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT] = MovementType_WalkBackAndForth,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_LEFT_DOWN] = MovementType_WalkSequenceUpRightLeftDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP] = MovementType_WalkSequenceRightLeftDownUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_RIGHT_LEFT] = MovementType_WalkSequenceDownUpRightLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_UP_RIGHT] = MovementType_WalkSequenceLeftDownUpRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_RIGHT_DOWN] = MovementType_WalkSequenceUpLeftRightDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_DOWN_UP] = MovementType_WalkSequenceLeftRightDownUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_LEFT_RIGHT] = MovementType_WalkSequenceDownUpLeftRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_UP_LEFT] = MovementType_WalkSequenceRightDownUpLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_DOWN_RIGHT] = MovementType_WalkSequenceLeftUpDownRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_RIGHT_LEFT] = MovementType_WalkSequenceUpDownRightLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_UP_DOWN] = MovementType_WalkSequenceRightLeftUpDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_LEFT_UP] = MovementType_WalkSequenceDownRightLeftUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_DOWN_LEFT] = MovementType_WalkSequenceRightUpDownLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_LEFT_RIGHT] = MovementType_WalkSequenceUpDownLeftRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_UP_DOWN] = MovementType_WalkSequenceLeftRightUpDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_RIGHT_UP] = MovementType_WalkSequenceDownLeftRightUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT] = MovementType_WalkSequenceUpLeftDownRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT] = MovementType_WalkSequenceDownRightUpLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_RIGHT_UP] = MovementType_WalkSequenceLeftDownRightUp,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_LEFT_DOWN] = MovementType_WalkSequenceRightUpLeftDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_DOWN_LEFT] = MovementType_WalkSequenceUpRightDownLeft,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT] = MovementType_WalkSequenceDownLeftUpRight,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN] = MovementType_WalkSequenceLeftUpRightDown,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_LEFT_UP] = MovementType_WalkSequenceRightDownLeftUp,
    [MOVEMENT_TYPE_COPY_PLAYER] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE] = MovementType_CopyPlayer,
    [MOVEMENT_TYPE_TREE_DISGUISE] = MovementType_TreeDisguise,
    [MOVEMENT_TYPE_MOUNTAIN_DISGUISE] = MovementType_MountainDisguise,
    [MOVEMENT_TYPE_COPY_PLAYER_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE_IN_GRASS] = MovementType_CopyPlayerInGrass,
    [MOVEMENT_TYPE_BURIED] = MovementType_Hidden,
    [MOVEMENT_TYPE_WALK_IN_PLACE_DOWN] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_WALK_IN_PLACE_UP] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_WALK_IN_PLACE_LEFT] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT] = MovementType_WalkInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_DOWN] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_UP] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_LEFT] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT] = MovementType_JogInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_DOWN] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_UP] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_LEFT] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT] = MovementType_RunInPlace,
    [MOVEMENT_TYPE_INVISIBLE] = MovementType_Invisible,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN] = MovementType_WalkSlowlyInPlace,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP] = MovementType_WalkSlowlyInPlace,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_LEFT] = MovementType_WalkSlowlyInPlace,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT] = MovementType_WalkSlowlyInPlace,
};

EVENT_OBJECT_MOVEMENT_CORE_DATA static const bool8 sMovementTypeHasRange[NUM_MOVEMENT_TYPES] = {
    [MOVEMENT_TYPE_WANDER_AROUND] = TRUE,
    [MOVEMENT_TYPE_WANDER_UP_AND_DOWN] = TRUE,
    [MOVEMENT_TYPE_WANDER_DOWN_AND_UP] = TRUE,
    [MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT] = TRUE,
    [MOVEMENT_TYPE_WANDER_RIGHT_AND_LEFT] = TRUE,
    [MOVEMENT_TYPE_WALK_UP_AND_DOWN] = TRUE,
    [MOVEMENT_TYPE_WALK_DOWN_AND_UP] = TRUE,
    [MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT] = TRUE,
    [MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_LEFT_DOWN] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_RIGHT_LEFT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_UP_RIGHT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_RIGHT_DOWN] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_DOWN_UP] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_LEFT_RIGHT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_UP_LEFT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_DOWN_RIGHT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_RIGHT_LEFT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_UP_DOWN] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_LEFT_UP] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_DOWN_LEFT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_LEFT_RIGHT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_UP_DOWN] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_RIGHT_UP] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_RIGHT_UP] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_LEFT_DOWN] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_DOWN_LEFT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN] = TRUE,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_LEFT_UP] = TRUE,
    [MOVEMENT_TYPE_COPY_PLAYER] = TRUE,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE] = TRUE,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE] = TRUE,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE] = TRUE,
    [MOVEMENT_TYPE_COPY_PLAYER_IN_GRASS] = TRUE,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS] = TRUE,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE_IN_GRASS] = TRUE,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE_IN_GRASS] = TRUE,
};

EVENT_OBJECT_MOVEMENT_CORE_DATA const u8 gInitialMovementTypeFacingDirections[NUM_MOVEMENT_TYPES] = {
    [MOVEMENT_TYPE_NONE] = DIR_SOUTH,
    [MOVEMENT_TYPE_LOOK_AROUND] = DIR_SOUTH,
    [MOVEMENT_TYPE_WANDER_AROUND] = DIR_SOUTH,
    [MOVEMENT_TYPE_WANDER_UP_AND_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WANDER_DOWN_AND_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WANDER_RIGHT_AND_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_FACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_FACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_PLAYER] = DIR_SOUTH,
    [MOVEMENT_TYPE_BERRY_TREE_GROWTH] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_AND_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_LEFT_AND_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_FACE_UP_AND_LEFT] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_UP_AND_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_DOWN_AND_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_FACE_UP_LEFT_AND_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_FACE_DOWN_LEFT_AND_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_ROTATE_COUNTERCLOCKWISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_ROTATE_CLOCKWISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_UP_AND_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_DOWN_AND_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_LEFT_AND_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_RIGHT_AND_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_LEFT_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_RIGHT_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_UP_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_RIGHT_DOWN] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_DOWN_UP] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_UP_LEFT_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_UP_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_DOWN_RIGHT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_RIGHT_LEFT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_UP_DOWN] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_LEFT_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_DOWN_LEFT] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_DOWN_LEFT_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_RIGHT_UP_DOWN] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_RIGHT_UP] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_LEFT_DOWN_RIGHT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_RIGHT_UP_LEFT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_DOWN_RIGHT_UP] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_UP_LEFT_DOWN] = DIR_EAST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_UP_RIGHT_DOWN_LEFT] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_DOWN_LEFT_UP_RIGHT] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SEQUENCE_LEFT_UP_RIGHT_DOWN] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_DOWN_LEFT_UP] = DIR_EAST,
    [MOVEMENT_TYPE_COPY_PLAYER] = DIR_NORTH,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE] = DIR_SOUTH,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE] = DIR_WEST,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE] = DIR_EAST,
    [MOVEMENT_TYPE_TREE_DISGUISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_MOUNTAIN_DISGUISE] = DIR_SOUTH,
    [MOVEMENT_TYPE_COPY_PLAYER_IN_GRASS] = DIR_NORTH,
    [MOVEMENT_TYPE_COPY_PLAYER_OPPOSITE_IN_GRASS] = DIR_SOUTH,
    [MOVEMENT_TYPE_COPY_PLAYER_COUNTERCLOCKWISE_IN_GRASS] = DIR_WEST,
    [MOVEMENT_TYPE_COPY_PLAYER_CLOCKWISE_IN_GRASS] = DIR_EAST,
    [MOVEMENT_TYPE_BURIED] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_JOG_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_JOG_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_JOG_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_JOG_IN_PLACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_RUN_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_RUN_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_RUN_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_RUN_IN_PLACE_RIGHT] = DIR_EAST,
    [MOVEMENT_TYPE_INVISIBLE] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_DOWN] = DIR_SOUTH,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_UP] = DIR_NORTH,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_LEFT] = DIR_WEST,
    [MOVEMENT_TYPE_WALK_SLOWLY_IN_PLACE_RIGHT] = DIR_EAST,
};

EVENT_OBJECT_MOVEMENT_CORE_DATA static const u8 sMovementTypeCoreDataPadding[] = {0, 0};

#undef EVENT_OBJECT_MOVEMENT_CORE_DATA

#define EVENT_OBJECT_MOVEMENT_FUNCTION_TABLES __attribute__((section(".rodata.event_object_movement_function_tables"), aligned(1)))

// JP names retained by the function-pointer tables below.  The US header uses
// later semantic names for several of these handlers.
extern bool8 MovementType_BerryTreeGrowth_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementType_BerryTreeGrowth_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementType_BerryTreeGrowth_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementType_BerryTreeGrowth_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementType_Hidden_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 CopyablePlayerMovement_GoSpeed0(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
extern bool8 CopyablePlayerMovement_GoSpeed1(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
extern bool8 CopyablePlayerMovement_GoSpeed2(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
extern bool8 cph_IM_DIFFERENT(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));
extern bool8 CopyablePlayerMovement_GoSpeed4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8));

#include "data/object_events/movement_type_func_tables.h"
#undef EVENT_OBJECT_MOVEMENT_FUNCTION_TABLES

#include "constants/field_effects.h"
#include "constants/union_room.h"

// These JP lookup tables contain one sprite animation index for every direction,
// including the four diagonal directions. Their exported names are retained for
// the existing movement-action callers.
#define EVENT_OBJECT_MOVEMENT_ACTION_TABLES __attribute__((section(".rodata.event_object_movement_action_tables"), aligned(1)))

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gJumpInPlaceMovementActions[] =
{
    [DIR_NONE] = ANIM_STD_FACE_SOUTH,
    [DIR_SOUTH] = ANIM_STD_FACE_SOUTH,
    [DIR_NORTH] = ANIM_STD_FACE_NORTH,
    [DIR_WEST] = ANIM_STD_FACE_WEST,
    [DIR_EAST] = ANIM_STD_FACE_EAST,
    [DIR_SOUTHWEST] = ANIM_STD_FACE_SOUTH,
    [DIR_SOUTHEAST] = ANIM_STD_FACE_SOUTH,
    [DIR_NORTHWEST] = ANIM_STD_FACE_NORTH,
    [DIR_NORTHEAST] = ANIM_STD_FACE_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gJumpInPlaceTurnAroundMovementActions[] =
{
    [DIR_NONE] = ANIM_STD_GO_SOUTH,
    [DIR_SOUTH] = ANIM_STD_GO_SOUTH,
    [DIR_NORTH] = ANIM_STD_GO_NORTH,
    [DIR_WEST] = ANIM_STD_GO_WEST,
    [DIR_EAST] = ANIM_STD_GO_EAST,
    [DIR_SOUTHWEST] = ANIM_STD_GO_SOUTH,
    [DIR_SOUTHEAST] = ANIM_STD_GO_SOUTH,
    [DIR_NORTHWEST] = ANIM_STD_GO_NORTH,
    [DIR_NORTHEAST] = ANIM_STD_GO_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gJumpMovementActions[] =
{
    [DIR_NONE] = ANIM_STD_GO_FAST_SOUTH,
    [DIR_SOUTH] = ANIM_STD_GO_FAST_SOUTH,
    [DIR_NORTH] = ANIM_STD_GO_FAST_NORTH,
    [DIR_WEST] = ANIM_STD_GO_FAST_WEST,
    [DIR_EAST] = ANIM_STD_GO_FAST_EAST,
    [DIR_SOUTHWEST] = ANIM_STD_GO_FAST_SOUTH,
    [DIR_SOUTHEAST] = ANIM_STD_GO_FAST_SOUTH,
    [DIR_NORTHWEST] = ANIM_STD_GO_FAST_NORTH,
    [DIR_NORTHEAST] = ANIM_STD_GO_FAST_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gJumpSpecialMovementActions[] =
{
    [DIR_NONE] = ANIM_STD_GO_FASTER_SOUTH,
    [DIR_SOUTH] = ANIM_STD_GO_FASTER_SOUTH,
    [DIR_NORTH] = ANIM_STD_GO_FASTER_NORTH,
    [DIR_WEST] = ANIM_STD_GO_FASTER_WEST,
    [DIR_EAST] = ANIM_STD_GO_FASTER_EAST,
    [DIR_SOUTHWEST] = ANIM_STD_GO_FASTER_SOUTH,
    [DIR_SOUTHEAST] = ANIM_STD_GO_FASTER_SOUTH,
    [DIR_NORTHWEST] = ANIM_STD_GO_FASTER_NORTH,
    [DIR_NORTHEAST] = ANIM_STD_GO_FASTER_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gPlayerRunMovementActions[] =
{
    [DIR_NONE] = ANIM_STD_GO_FASTEST_SOUTH,
    [DIR_SOUTH] = ANIM_STD_GO_FASTEST_SOUTH,
    [DIR_NORTH] = ANIM_STD_GO_FASTEST_NORTH,
    [DIR_WEST] = ANIM_STD_GO_FASTEST_WEST,
    [DIR_EAST] = ANIM_STD_GO_FASTEST_EAST,
    [DIR_SOUTHWEST] = ANIM_STD_GO_FASTEST_SOUTH,
    [DIR_SOUTHEAST] = ANIM_STD_GO_FASTEST_SOUTH,
    [DIR_NORTHWEST] = ANIM_STD_GO_FASTEST_NORTH,
    [DIR_NORTHEAST] = ANIM_STD_GO_FASTEST_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gRideWaterCurrentMovementActions[] =
{
    [DIR_NONE] = ANIM_GET_ON_OFF_POKEMON_SOUTH,
    [DIR_SOUTH] = ANIM_GET_ON_OFF_POKEMON_SOUTH,
    [DIR_NORTH] = ANIM_GET_ON_OFF_POKEMON_NORTH,
    [DIR_WEST] = ANIM_GET_ON_OFF_POKEMON_WEST,
    [DIR_EAST] = ANIM_GET_ON_OFF_POKEMON_EAST,
    [DIR_SOUTHWEST] = ANIM_GET_ON_OFF_POKEMON_SOUTH,
    [DIR_SOUTHEAST] = ANIM_GET_ON_OFF_POKEMON_SOUTH,
    [DIR_NORTHWEST] = ANIM_GET_ON_OFF_POKEMON_NORTH,
    [DIR_NORTHEAST] = ANIM_GET_ON_OFF_POKEMON_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gSlideMovementActions[] =
{
    [DIR_NONE] = ANIM_BUNNY_HOP_BACK_WHEEL_SOUTH,
    [DIR_SOUTH] = ANIM_BUNNY_HOP_BACK_WHEEL_SOUTH,
    [DIR_NORTH] = ANIM_BUNNY_HOP_BACK_WHEEL_NORTH,
    [DIR_WEST] = ANIM_BUNNY_HOP_BACK_WHEEL_WEST,
    [DIR_EAST] = ANIM_BUNNY_HOP_BACK_WHEEL_EAST,
    [DIR_SOUTHWEST] = ANIM_BUNNY_HOP_BACK_WHEEL_SOUTH,
    [DIR_SOUTHEAST] = ANIM_BUNNY_HOP_BACK_WHEEL_SOUTH,
    [DIR_NORTHWEST] = ANIM_BUNNY_HOP_BACK_WHEEL_NORTH,
    [DIR_NORTHEAST] = ANIM_BUNNY_HOP_BACK_WHEEL_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gWalkFastMovementActions[] =
{
    [DIR_NONE] = ANIM_BUNNY_HOP_FRONT_WHEEL_SOUTH,
    [DIR_SOUTH] = ANIM_BUNNY_HOP_FRONT_WHEEL_SOUTH,
    [DIR_NORTH] = ANIM_BUNNY_HOP_FRONT_WHEEL_NORTH,
    [DIR_WEST] = ANIM_BUNNY_HOP_FRONT_WHEEL_WEST,
    [DIR_EAST] = ANIM_BUNNY_HOP_FRONT_WHEEL_EAST,
    [DIR_SOUTHWEST] = ANIM_BUNNY_HOP_FRONT_WHEEL_SOUTH,
    [DIR_SOUTHEAST] = ANIM_BUNNY_HOP_FRONT_WHEEL_SOUTH,
    [DIR_NORTHWEST] = ANIM_BUNNY_HOP_FRONT_WHEEL_NORTH,
    [DIR_NORTHEAST] = ANIM_BUNNY_HOP_FRONT_WHEEL_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gWalkFasterMovementActions[] =
{
    [DIR_NONE] = ANIM_STANDING_WHEELIE_BACK_WHEEL_SOUTH,
    [DIR_SOUTH] = ANIM_STANDING_WHEELIE_BACK_WHEEL_SOUTH,
    [DIR_NORTH] = ANIM_STANDING_WHEELIE_BACK_WHEEL_NORTH,
    [DIR_WEST] = ANIM_STANDING_WHEELIE_BACK_WHEEL_WEST,
    [DIR_EAST] = ANIM_STANDING_WHEELIE_BACK_WHEEL_EAST,
    [DIR_SOUTHWEST] = ANIM_STANDING_WHEELIE_BACK_WHEEL_SOUTH,
    [DIR_SOUTHEAST] = ANIM_STANDING_WHEELIE_BACK_WHEEL_SOUTH,
    [DIR_NORTHWEST] = ANIM_STANDING_WHEELIE_BACK_WHEEL_NORTH,
    [DIR_NORTHEAST] = ANIM_STANDING_WHEELIE_BACK_WHEEL_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gWalkInPlaceFastMovementActions[] =
{
    [DIR_NONE] = ANIM_STANDING_WHEELIE_FRONT_WHEEL_SOUTH,
    [DIR_SOUTH] = ANIM_STANDING_WHEELIE_FRONT_WHEEL_SOUTH,
    [DIR_NORTH] = ANIM_STANDING_WHEELIE_FRONT_WHEEL_NORTH,
    [DIR_WEST] = ANIM_STANDING_WHEELIE_FRONT_WHEEL_WEST,
    [DIR_EAST] = ANIM_STANDING_WHEELIE_FRONT_WHEEL_EAST,
    [DIR_SOUTHWEST] = ANIM_STANDING_WHEELIE_FRONT_WHEEL_SOUTH,
    [DIR_SOUTHEAST] = ANIM_STANDING_WHEELIE_FRONT_WHEEL_SOUTH,
    [DIR_NORTHWEST] = ANIM_STANDING_WHEELIE_FRONT_WHEEL_NORTH,
    [DIR_NORTHEAST] = ANIM_STANDING_WHEELIE_FRONT_WHEEL_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gWalkInPlaceFasterMovementActions[] =
{
    [DIR_NONE] = ANIM_MOVING_WHEELIE_SOUTH,
    [DIR_SOUTH] = ANIM_MOVING_WHEELIE_SOUTH,
    [DIR_NORTH] = ANIM_MOVING_WHEELIE_NORTH,
    [DIR_WEST] = ANIM_MOVING_WHEELIE_WEST,
    [DIR_EAST] = ANIM_MOVING_WHEELIE_EAST,
    [DIR_SOUTHWEST] = ANIM_MOVING_WHEELIE_SOUTH,
    [DIR_SOUTHEAST] = ANIM_MOVING_WHEELIE_SOUTH,
    [DIR_NORTHWEST] = ANIM_MOVING_WHEELIE_NORTH,
    [DIR_NORTHEAST] = ANIM_MOVING_WHEELIE_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gWalkInPlaceNormalMovementActions[] =
{
    [DIR_NONE] = ANIM_STD_FACE_SOUTH,
    [DIR_SOUTH] = ANIM_STD_FACE_SOUTH,
    [DIR_NORTH] = ANIM_STD_FACE_NORTH,
    [DIR_WEST] = ANIM_STD_FACE_WEST,
    [DIR_EAST] = ANIM_STD_FACE_EAST,
    [DIR_SOUTHWEST] = ANIM_STD_FACE_SOUTH,
    [DIR_SOUTHEAST] = ANIM_STD_FACE_SOUTH,
    [DIR_NORTHWEST] = ANIM_STD_FACE_NORTH,
    [DIR_NORTHEAST] = ANIM_STD_FACE_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gWalkInPlaceSlowMovementActions[] =
{
    [DIR_NONE] = ANIM_STD_GO_SOUTH,
    [DIR_SOUTH] = ANIM_STD_GO_SOUTH,
    [DIR_NORTH] = ANIM_STD_GO_NORTH,
    [DIR_WEST] = ANIM_STD_GO_WEST,
    [DIR_EAST] = ANIM_STD_GO_EAST,
    [DIR_SOUTHWEST] = ANIM_STD_GO_SOUTH,
    [DIR_SOUTHEAST] = ANIM_STD_GO_SOUTH,
    [DIR_NORTHWEST] = ANIM_STD_GO_NORTH,
    [DIR_NORTHEAST] = ANIM_STD_GO_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gWalkNormalMovementActions[] =
{
    [DIR_NONE] = ANIM_STD_GO_FAST_SOUTH,
    [DIR_SOUTH] = ANIM_STD_GO_FAST_SOUTH,
    [DIR_NORTH] = ANIM_STD_GO_FAST_NORTH,
    [DIR_WEST] = ANIM_STD_GO_FAST_WEST,
    [DIR_EAST] = ANIM_STD_GO_FAST_EAST,
    [DIR_SOUTHWEST] = ANIM_STD_GO_FAST_SOUTH,
    [DIR_SOUTHEAST] = ANIM_STD_GO_FAST_SOUTH,
    [DIR_NORTHWEST] = ANIM_STD_GO_FAST_NORTH,
    [DIR_NORTHEAST] = ANIM_STD_GO_FAST_NORTH,
};

EVENT_OBJECT_MOVEMENT_ACTION_TABLES const u8 gWalkSlowMovementActions[] =
{
    [DIR_NONE] = ANIM_RUN_SOUTH,
    [DIR_SOUTH] = ANIM_RUN_SOUTH,
    [DIR_NORTH] = ANIM_RUN_NORTH,
    [DIR_WEST] = ANIM_RUN_WEST,
    [DIR_EAST] = ANIM_RUN_EAST,
    [DIR_SOUTHWEST] = ANIM_RUN_SOUTH,
    [DIR_SOUTHEAST] = ANIM_RUN_SOUTH,
    [DIR_NORTHWEST] = ANIM_RUN_NORTH,
    [DIR_NORTHEAST] = ANIM_RUN_NORTH,
};

#undef EVENT_OBJECT_MOVEMENT_ACTION_TABLES

#define EVENT_OBJECT_MOVEMENT_DIRECTION_DATA __attribute__((section(".rodata.event_object_movement_direction_data"), aligned(1)))

// Keep this packed: the original ROM places a 9-byte lookup directly before
// two function-pointer tables, without the normal C alignment padding.
struct EventObjectMovementDirectionData
{
    u8 trainerFacingDirectionMovementTypes[9];
    bool8 (*directionBlockedMetatileFuncs[4])(u8);
    bool8 (*oppositeDirectionBlockedMetatileFuncs[4])(u8);
    struct Coords16 directionToVectors[9];
} __attribute__((packed));

// The JP collision implementation uses these names in the opposite order from
// the current US source, so retain the actual JP pointer sequences.
EVENT_OBJECT_MOVEMENT_DIRECTION_DATA static const struct EventObjectMovementDirectionData sEventObjectMovementDirectionData =
{
    .trainerFacingDirectionMovementTypes =
    {
        [DIR_NONE] = MOVEMENT_TYPE_FACE_DOWN,
        [DIR_SOUTH] = MOVEMENT_TYPE_FACE_DOWN,
        [DIR_NORTH] = MOVEMENT_TYPE_FACE_UP,
        [DIR_WEST] = MOVEMENT_TYPE_FACE_LEFT,
        [DIR_EAST] = MOVEMENT_TYPE_FACE_RIGHT,
        [DIR_SOUTHWEST] = MOVEMENT_TYPE_FACE_DOWN,
        [DIR_SOUTHEAST] = MOVEMENT_TYPE_FACE_DOWN,
        [DIR_NORTHWEST] = MOVEMENT_TYPE_FACE_UP,
        [DIR_NORTHEAST] = MOVEMENT_TYPE_FACE_UP,
    },
    .directionBlockedMetatileFuncs =
    {
        MetatileBehavior_IsSouthBlocked,
        MetatileBehavior_IsNorthBlocked,
        MetatileBehavior_IsWestBlocked,
        MetatileBehavior_IsEastBlocked,
    },
    .oppositeDirectionBlockedMetatileFuncs =
    {
        MetatileBehavior_IsNorthBlocked,
        MetatileBehavior_IsSouthBlocked,
        MetatileBehavior_IsEastBlocked,
        MetatileBehavior_IsWestBlocked,
    },
    .directionToVectors =
    {
        [DIR_NONE] = {  0,  0 },
        [DIR_SOUTH] = {  0,  1 },
        [DIR_NORTH] = {  0, -1 },
        [DIR_WEST] = { -1,  0 },
        [DIR_EAST] = {  1,  0 },
        [DIR_SOUTHWEST] = { -1,  1 },
        [DIR_SOUTHEAST] = {  1,  1 },
        [DIR_NORTHWEST] = { -1, -1 },
        [DIR_NORTHEAST] = {  1, -1 },
    },
};

#undef EVENT_OBJECT_MOVEMENT_DIRECTION_DATA

// These five-direction movement-action tables are distinct from the preceding
// JP nine-direction sprite-animation lookup tables. Keep their names local
// until the legacy animation accessors can be renamed without ambiguity.
#define EVENT_OBJECT_MOVEMENT_MOVEMENT_ACTION_DATA __attribute__((section(".rodata.event_object_movement_movement_action_data"), aligned(1)))

#define MOVEMENT_ACTION_DIRECTION_TABLE(name, south, north, west, east) \
    EVENT_OBJECT_MOVEMENT_MOVEMENT_ACTION_DATA static const u8 name[] = \
    { \
        [DIR_NONE] = south, \
        [DIR_SOUTH] = south, \
        [DIR_NORTH] = north, \
        [DIR_WEST] = west, \
        [DIR_EAST] = east, \
    }

MOVEMENT_ACTION_DIRECTION_TABLE(sFaceDirectionMovementActions, MOVEMENT_ACTION_FACE_DOWN, MOVEMENT_ACTION_FACE_UP, MOVEMENT_ACTION_FACE_LEFT, MOVEMENT_ACTION_FACE_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sWalkSlowMovementActions, MOVEMENT_ACTION_WALK_SLOW_DOWN, MOVEMENT_ACTION_WALK_SLOW_UP, MOVEMENT_ACTION_WALK_SLOW_LEFT, MOVEMENT_ACTION_WALK_SLOW_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sWalkNormalMovementActions, MOVEMENT_ACTION_WALK_NORMAL_DOWN, MOVEMENT_ACTION_WALK_NORMAL_UP, MOVEMENT_ACTION_WALK_NORMAL_LEFT, MOVEMENT_ACTION_WALK_NORMAL_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sWalkFastMovementActions, MOVEMENT_ACTION_WALK_FAST_DOWN, MOVEMENT_ACTION_WALK_FAST_UP, MOVEMENT_ACTION_WALK_FAST_LEFT, MOVEMENT_ACTION_WALK_FAST_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sRideWaterCurrentMovementActions, MOVEMENT_ACTION_RIDE_WATER_CURRENT_DOWN, MOVEMENT_ACTION_RIDE_WATER_CURRENT_UP, MOVEMENT_ACTION_RIDE_WATER_CURRENT_LEFT, MOVEMENT_ACTION_RIDE_WATER_CURRENT_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sWalkFasterMovementActions, MOVEMENT_ACTION_WALK_FASTER_DOWN, MOVEMENT_ACTION_WALK_FASTER_UP, MOVEMENT_ACTION_WALK_FASTER_LEFT, MOVEMENT_ACTION_WALK_FASTER_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sSlideMovementActions, MOVEMENT_ACTION_SLIDE_DOWN, MOVEMENT_ACTION_SLIDE_UP, MOVEMENT_ACTION_SLIDE_LEFT, MOVEMENT_ACTION_SLIDE_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sPlayerRunMovementActions, MOVEMENT_ACTION_PLAYER_RUN_DOWN, MOVEMENT_ACTION_PLAYER_RUN_UP, MOVEMENT_ACTION_PLAYER_RUN_LEFT, MOVEMENT_ACTION_PLAYER_RUN_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sJump2MovementActions, MOVEMENT_ACTION_JUMP_2_DOWN, MOVEMENT_ACTION_JUMP_2_UP, MOVEMENT_ACTION_JUMP_2_LEFT, MOVEMENT_ACTION_JUMP_2_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sJumpInPlaceMovementActions, MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN, MOVEMENT_ACTION_JUMP_IN_PLACE_UP, MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT, MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sJumpInPlaceTurnAroundMovementActions, MOVEMENT_ACTION_JUMP_IN_PLACE_UP_DOWN, MOVEMENT_ACTION_JUMP_IN_PLACE_DOWN_UP, MOVEMENT_ACTION_JUMP_IN_PLACE_RIGHT_LEFT, MOVEMENT_ACTION_JUMP_IN_PLACE_LEFT_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sJumpMovementActions, MOVEMENT_ACTION_JUMP_DOWN, MOVEMENT_ACTION_JUMP_UP, MOVEMENT_ACTION_JUMP_LEFT, MOVEMENT_ACTION_JUMP_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sJumpSpecialMovementActions, MOVEMENT_ACTION_JUMP_SPECIAL_DOWN, MOVEMENT_ACTION_JUMP_SPECIAL_UP, MOVEMENT_ACTION_JUMP_SPECIAL_LEFT, MOVEMENT_ACTION_JUMP_SPECIAL_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sWalkInPlaceSlowMovementActions, MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN, MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_UP, MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_LEFT, MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sWalkInPlaceNormalMovementActions, MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN, MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_UP, MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_LEFT, MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sWalkInPlaceFastMovementActions, MOVEMENT_ACTION_WALK_IN_PLACE_FAST_DOWN, MOVEMENT_ACTION_WALK_IN_PLACE_FAST_UP, MOVEMENT_ACTION_WALK_IN_PLACE_FAST_LEFT, MOVEMENT_ACTION_WALK_IN_PLACE_FAST_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sWalkInPlaceFasterMovementActions, MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_DOWN, MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_UP, MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_LEFT, MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sAcroWheelieFaceDirectionMovementActions, MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN, MOVEMENT_ACTION_ACRO_WHEELIE_FACE_UP, MOVEMENT_ACTION_ACRO_WHEELIE_FACE_LEFT, MOVEMENT_ACTION_ACRO_WHEELIE_FACE_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sAcroPopWheelieFaceDirectionMovementActions, MOVEMENT_ACTION_ACRO_POP_WHEELIE_DOWN, MOVEMENT_ACTION_ACRO_POP_WHEELIE_UP, MOVEMENT_ACTION_ACRO_POP_WHEELIE_LEFT, MOVEMENT_ACTION_ACRO_POP_WHEELIE_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sAcroEndWheelieFaceDirectionMovementActions, MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_DOWN, MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_UP, MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_LEFT, MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sAcroWheelieHopFaceDirectionMovementActions, MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_DOWN, MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_UP, MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_LEFT, MOVEMENT_ACTION_ACRO_WHEELIE_HOP_FACE_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sAcroWheelieHopDirectionMovementActions, MOVEMENT_ACTION_ACRO_WHEELIE_HOP_DOWN, MOVEMENT_ACTION_ACRO_WHEELIE_HOP_UP, MOVEMENT_ACTION_ACRO_WHEELIE_HOP_LEFT, MOVEMENT_ACTION_ACRO_WHEELIE_HOP_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sAcroWheelieJumpDirectionMovementActions, MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_DOWN, MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_UP, MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_LEFT, MOVEMENT_ACTION_ACRO_WHEELIE_JUMP_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sAcroWheelieInPlaceDirectionMovementActions, MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN, MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_UP, MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_LEFT, MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sAcroPopWheelieMoveDirectionMovementActions, MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_DOWN, MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_UP, MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_LEFT, MOVEMENT_ACTION_ACRO_POP_WHEELIE_MOVE_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sAcroWheelieMoveDirectionMovementActions, MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_DOWN, MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_UP, MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_LEFT, MOVEMENT_ACTION_ACRO_WHEELIE_MOVE_RIGHT);
MOVEMENT_ACTION_DIRECTION_TABLE(sAcroEndWheelieMoveDirectionMovementActions, MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_DOWN, MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_UP, MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_LEFT, MOVEMENT_ACTION_ACRO_END_WHEELIE_MOVE_RIGHT);

#undef MOVEMENT_ACTION_DIRECTION_TABLE

EVENT_OBJECT_MOVEMENT_MOVEMENT_ACTION_DATA const u8 sOppositeDirections[] =
{
    DIR_NORTH,
    DIR_SOUTH,
    DIR_EAST,
    DIR_WEST,
    DIR_NORTHEAST,
    DIR_NORTHWEST,
    DIR_SOUTHEAST,
    DIR_SOUTHWEST,
};

#undef EVENT_OBJECT_MOVEMENT_MOVEMENT_ACTION_DATA

#define EVENT_OBJECT_MOVEMENT_DIRECTION_COMPOSITION_DATA __attribute__((section(".rodata.event_object_movement_direction_composition_data"), aligned(1)))

// These two 4x4 tables compose the initial movement direction with the
// direction sequence used by state_to_direction. The final byte is ROM padding.
EVENT_OBJECT_MOVEMENT_DIRECTION_COMPOSITION_DATA static const u8 sDirectionCompositionOffsets[4][4] =
{
    { DIR_NORTH, DIR_SOUTH, DIR_EAST, DIR_WEST },
    { DIR_SOUTH, DIR_NORTH, DIR_WEST, DIR_EAST },
    { DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH },
    { DIR_EAST, DIR_WEST, DIR_SOUTH, DIR_NORTH },
};

EVENT_OBJECT_MOVEMENT_DIRECTION_COMPOSITION_DATA static const u8 sDirectionCompositionResults[4][4] =
{
    { DIR_NORTH, DIR_SOUTH, DIR_EAST, DIR_WEST },
    { DIR_SOUTH, DIR_NORTH, DIR_WEST, DIR_EAST },
    { DIR_EAST, DIR_WEST, DIR_SOUTH, DIR_NORTH },
    { DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH },
};

EVENT_OBJECT_MOVEMENT_DIRECTION_COMPOSITION_DATA static const u8 sDirectionCompositionPadding[] = {0};

#undef EVENT_OBJECT_MOVEMENT_DIRECTION_COMPOSITION_DATA

#define EVENT_OBJECT_MOVEMENT_ACTION_FUNCTION_TABLES __attribute__((section(".rodata.event_object_movement_action_function_tables"), aligned(1)))
#define EVENT_OBJECT_MOVEMENT_ACTION_FUNCTION_TABLES_TAIL __attribute__((section(".rodata.event_object_movement_action_function_tables_tail"), aligned(1)))

#include "data/object_events/movement_action_func_tables.h"

#undef EVENT_OBJECT_MOVEMENT_ACTION_FUNCTION_TABLES_TAIL
#undef EVENT_OBJECT_MOVEMENT_ACTION_FUNCTION_TABLES

extern const struct Coords16 sDirectionToVectors[];
extern u8 gUnknown_2037254; // sCurrentReflectionType
extern u16 gUnknown_2037256; // sCurrentSpecialObjectPaletteTag
static u8 GetCollisionInDirection(struct ObjectEvent *, u8);
extern u32 state_to_direction(u8, u8, u8);
extern const struct SpriteTemplate gUnknown_846FA28;
extern void (*const gUnknown_846FA40[])(struct Sprite *);

// Figure-8 animation offsets (defined in field_effect_helpers_rest.c).
extern const s8 sFigure8XOffsets[];
extern const s8 sFigure8YOffsets[];
struct ObjectEvent;
struct Sprite;

// Sprite data used throughout
#define sObjEventId   data[0]
#define sTypeFuncId   data[1] // Index into corresponding gMovementTypeFuncs_* table
#define sActionFuncId data[2] // Index into corresponding gMovementActionFuncs_* table
#define sDirection    data[3]
#define sCamera_FollowSpriteId data[0]
#define sCamera_State         data[1]
#define sCamera_MoveX         data[2]
#define sCamera_MoveY         data[3]
#define sInvisible     data[2]
#define sAnimNum       data[3]
#define sAnimState     data[4]
#define sVirtualObjId   data[0]
#define sVirtualObjElev data[1]
#define sTimer          data[2]
#define sBerryTreeFlags data[7]
#define BERRY_FLAG_SPARKLING   (1 << 1)
#define BERRY_FLAG_JUST_PICKED (1 << 2)
#define OBJ_EVENT_PAL_TAG_NONE 0x11FF

#define EVENT_OBJECT_MOVEMENT_PALETTE_DATA __attribute__((section(".rodata.event_object_movement_palette_data"), aligned(1)))
#include "data/object_events/movement_palette_data.h"
#undef EVENT_OBJECT_MOVEMENT_PALETTE_DATA

enum {
    CAMERA_STATE_INIT,
    CAMERA_STATE_MOVE,
    CAMERA_STATE_FROZEN,
};

enum {
    BERRYTREEFUNC_NORMAL,
    BERRYTREEFUNC_MOVE,
    BERRYTREEFUNC_SPARKLE_START,
    BERRYTREEFUNC_SPARKLE,
    BERRYTREEFUNC_SPARKLE_END,
};

#define GROUND_EFFECT_FLAG_PUDDLE (1 << 10)

enum {
    MOVE_SPEED_NORMAL, // walking
    MOVE_SPEED_FAST_1, // running / surfing / sliding (ice tile)
    MOVE_SPEED_FAST_2, // water current / acro bike
    MOVE_SPEED_FASTER, // mach bike's max speed
    MOVE_SPEED_FASTEST,
};

#define JUMP_HALFWAY  1
#define JUMP_FINISHED ((u8)-1)

enum
{
    JUMP_TYPE_HIGH,
    JUMP_TYPE_LOW,
    JUMP_TYPE_NORMAL,
};

enum
{
    JUMP_DISTANCE_IN_PLACE,
    JUMP_DISTANCE_NORMAL,
    JUMP_DISTANCE_FAR,
};

#define EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA __attribute__((section(".rodata.event_object_movement_ground_effect_data"), aligned(1)))
#define EVENT_OBJECT_MOVEMENT_JUMP_DATA __attribute__((section(".rodata.event_object_movement_jump_data"), aligned(1)))
#include "data/object_events/movement_ground_effect_data.h"
#undef EVENT_OBJECT_MOVEMENT_JUMP_DATA
#undef EVENT_OBJECT_MOVEMENT_GROUND_EFFECT_DATA

#define FIGURE_8_LENGTH 72

extern bool8 MovementAction_AcroWheelieMoveDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_AcroWheelieMoveLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_AcroWheelieMoveRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_AcroWheelieMoveUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_AcroEndWheelieMoveDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_AcroEndWheelieMoveUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_AcroEndWheelieMoveLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_AcroEndWheelieMoveRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_Delay_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_JumpSpecialDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_JumpSpecialLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_JumpSpecialRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_JumpSpecialUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_PlayerRunDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_PlayerRunLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_PlayerRunRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_PlayerRunUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_RideWaterCurrentDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_RideWaterCurrentLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_RideWaterCurrentRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_RideWaterCurrentUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_SlideDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_SlideLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_SlideRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_SlideUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern void SetUpReflection(struct ObjectEvent *objEvent, struct Sprite *sprite, u8 mode);
extern u32 StartFieldEffectForObjectEvent(u8 fieldEffectId, struct ObjectEvent *objectEvent);
extern bool8 ClearEventObjectMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_None_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern void RemoveEventObjectInternal(struct ObjectEvent *objectEvent);
extern void UpdateObjectEventOffscreen(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern void UpdateEventObjSpriteVisibility(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern void CreateLevitateMovementTask(struct ObjectEvent *objectEvent);
extern void DestroyExtraMovementTask(u8 taskId);
extern void StartSpriteAnimInDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 animNum);
extern void SetAndStartSpriteAnim(struct Sprite *sprite, u8 animNum, u8 a);
extern void EventObjectClearHeldMovement(struct ObjectEvent *objectEvent);
extern bool8 ObjectEventSetHeldMovement(struct ObjectEvent *objectEvent, u8 specialAnimId);
extern void ObjectEventClearHeldMovementIfActive(struct ObjectEvent *objectEvent);
extern void ObjectEventSetSingleMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 movementActionId);
extern bool8 SpriteAnimEnded(struct Sprite *sprite);
extern bool8 WaitForMovementDelay(struct Sprite *sprite);
extern bool8 EventObjectIsTrainerAndCloseToPlayer(struct ObjectEvent *objectEvent);
extern void SetMovementDelay(struct Sprite *sprite, s16 timer);
extern bool8 UpdateRevealDisguise(struct ObjectEvent *objectEvent);
extern u8 ObjectEventExecSingleMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkFastDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkFastLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkFastRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkFastUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkFasterDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkFasterLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkFasterRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkFasterUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkNormalDiagonalDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkNormalDiagonalDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkNormalDiagonalUpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkNormalDiagonalUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkNormalDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkNormalLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkNormalRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkNormalUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkSlowDiagonalDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkSlowDiagonalDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkSlowDiagonalUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkSlowDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkSlowLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkSlowRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_WalkSlowUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 GetFaceDirectionMovementAction(u32 direction);
extern bool8 MovementType_Disguise_Callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 EventObjectCB2_BerryTree(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 GetAcroPopWheelieFaceDirectionMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 GetAcroWheelieFaceDirectionMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 GetAcroWheelieHopFaceDirectionMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 GetAcroWheelieJumpDirectionMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 GetGroundEffectFlags_TallGrassOnBeginStep(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementAction_AcroPopWheelieMoveRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_Hidden_Callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 StartFieldEffectForEventObject(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 sub_080915BC(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 sub_08091648(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 sub_08091760(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_CopyPlayerInGrass_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_CopyPlayer_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceDirection_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceDownAndLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceDownAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceDownAndUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceDownRightAndLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceDownUpAndLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceDownUpAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceLeftAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceUpAndLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceUpAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceUpLeftAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_FaceUpRightAndLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_Invisible_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_JogInPlace_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_LookAround_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_None_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_RotateClockwise_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_RotateCounterclockwise_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_RunInPlace_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkBackAndForth_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkInPlace_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceDownLeftRightUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceDownLeftUpRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceDownRightLeftUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceDownRightUpLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceDownUpLeftRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceLeftDownRightUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceLeftRightDownUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceLeftUpDownRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceRightDownLeftUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceRightLeftDownUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceRightUpDownLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceUpDownLeftRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceUpLeftDownRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSequenceUpRightDownLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WalkSlowlyInPlace_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 MovementType_WanderLeftAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern u8 sub_08092CF8(u8 direction);
extern u8 sub_08092F34(u8 direction);
extern u8 sub_08092F08(u8 direction);
extern u8 sub_08092EDC(u8 direction);
extern u8 sub_08092F60(u8 direction);
extern bool8 sub_08093EC4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 animNum, u16 delay);
extern void sub_080B3CD0(struct ObjectEvent *objectEvent);
extern bool8 MovementAction_AcroPopWheelieMoveDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_AcroPopWheelieMoveUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 MovementAction_AcroPopWheelieMoveLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 sub_080954D4(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern bool8 sub_08093554(struct ObjectEvent *objectEvent, struct Sprite *sprite);
extern struct ObjectEventTemplate *GetEventObjectTemplateByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup);

void ClearEventObject(struct ObjectEvent *objectEvent)
{
    *objectEvent = (struct ObjectEvent){};
    objectEvent->localId = LOCALID_PLAYER;
    objectEvent->mapNum = MAP_NUM(MAP_UNDEFINED);
    objectEvent->mapGroup = MAP_GROUP(MAP_UNDEFINED);
    objectEvent->movementActionId = MOVEMENT_ACTION_NONE;
}

void ClearAllEventObjects(void)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        ClearEventObject(&gObjectEvents[i]);
}

void ResetEventObjects(void)
{
    ClearLinkPlayerEventObjects();
    ClearAllEventObjects();
    ClearPlayerAvatarInfo();
    CreateReflectionEffectSprites();
}

__attribute__((naked)) void CreateReflectionEffectSprites(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, sl\n\t"
        "	mov r5, sb\n\t"
        "	mov r4, r8\n\t"
        "	push {r4, r5, r6}\n\t"
        "	ldr r0, _0808CE5C\n\t"
        "	ldr r0, [r0, #0x54]\n\t"
        "	mov sb, r0\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0x1f\n\t"
        "	bl CreateSpriteAtEnd\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _0808CE60\n\t"
        "	mov sl, r1\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	add r4, sl\n\t"
        "	ldrb r1, [r4, #1]\n\t"
        "	movs r5, #4\n\t"
        "	rsbs r5, r5, #0\n\t"
        "	adds r0, r5, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #1\n\t"
        "	mov r8, r1\n\t"
        "	mov r1, r8\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl InitSpriteAffineAnim\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl StartSpriteAffineAnim\n\t"
        "	adds r4, #0x3e\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r6, #4\n\t"
        "	orrs r0, r6\n\t"
        "	strb r0, [r4]\n\t"
        "	mov r0, sb\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0x1f\n\t"
        "	bl CreateSpriteAtEnd\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	add r4, sl\n\t"
        "	ldrb r0, [r4, #1]\n\t"
        "	ands r5, r0\n\t"
        "	mov r0, r8\n\t"
        "	orrs r5, r0\n\t"
        "	strb r5, [r4, #1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl InitSpriteAffineAnim\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl StartSpriteAffineAnim\n\t"
        "	adds r4, #0x3e\n\t"
        "	ldrb r0, [r4]\n\t"
        "	orrs r0, r6\n\t"
        "	strb r0, [r4]\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808CE5C: .4byte gFieldEffectObjectTemplatePointers\n\t"
        "_0808CE60: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

u8 GetFirstInactiveEventObjectId(void)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (!gObjectEvents[i].active)
            break;
    }
    return i;
}

u8 GetObjectEventIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroupId)
{
    if (localId < LOCALID_PLAYER)
        return GetEventObjectIdByLocalIdAndMapInternal(localId, mapNum, mapGroupId);

    return GetEventObjectIdByLocalId(localId);
}

bool8 TryGetObjectEventIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroupId, u8 *objectEventId)
{
    *objectEventId = GetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroupId);
    if (*objectEventId == OBJECT_EVENTS_COUNT)
        return TRUE;
    else
        return FALSE;
}

u8 GetEventObjectIdByXY(s16 x, s16 y)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].currentCoords.x == x && gObjectEvents[i].currentCoords.y == y)
            break;
    }

    return i;
}

u8 GetEventObjectIdByLocalIdAndMapInternal(u8 localId, u8 mapNum, u8 mapGroupId)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].localId == localId && gObjectEvents[i].mapNum == mapNum && gObjectEvents[i].mapGroup == mapGroupId)
            return i;
    }

    return OBJECT_EVENTS_COUNT;
}

u8 GetEventObjectIdByLocalId(u8 localId)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].localId == localId)
            return i;
    }

    return OBJECT_EVENTS_COUNT;
}

__attribute__((naked)) void InitEventObjectStateFromTemplate(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r6, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r7, r2, #0x18\n\t"
        "	ldrb r0, [r5]\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r2, r7, #0\n\t"
        "	mov r3, sp\n\t"
        "	bl GetAvailableEventObjectId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808CFDE\n\t"
        "	movs r0, #0x10\n\t"
        "	b _0808D0D2\n\t"
        "_0808CFDE:\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808D0E0\n\t"
        "	adds r4, r0, r1\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ClearEventObject\n\t"
        "	ldrh r3, [r5, #4]\n\t"
        "	adds r3, #7\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r3, r3, #0x10\n\t"
        "	ldrh r2, [r5, #6]\n\t"
        "	adds r2, #7\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #1\n\t"
        "	orrs r0, r1\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	ldrb r0, [r5, #1]\n\t"
        "	strb r0, [r4, #5]\n\t"
        "	ldrb r0, [r5, #9]\n\t"
        "	strb r0, [r4, #6]\n\t"
        "	ldrb r0, [r5]\n\t"
        "	strb r0, [r4, #8]\n\t"
        "	strb r6, [r4, #9]\n\t"
        "	strb r7, [r4, #0xa]\n\t"
        "	strh r3, [r4, #0xc]\n\t"
        "	strh r2, [r4, #0xe]\n\t"
        "	strh r3, [r4, #0x10]\n\t"
        "	strh r2, [r4, #0x12]\n\t"
        "	strh r3, [r4, #0x14]\n\t"
        "	strh r2, [r4, #0x16]\n\t"
        "	ldrb r0, [r5, #8]\n\t"
        "	movs r7, #0xf\n\t"
        "	adds r1, r7, #0\n\t"
        "	ands r1, r0\n\t"
        "	ldrb r2, [r4, #0xb]\n\t"
        "	movs r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	mov r8, r0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #0xb]\n\t"
        "	ldrb r1, [r5, #8]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	ands r0, r7\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #0xb]\n\t"
        "	ldrb r1, [r5, #0xa]\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	movs r0, #0xf\n\t"
        "	mov sb, r0\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	ldrb r2, [r4, #0x19]\n\t"
        "	mov r0, r8\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #0x19]\n\t"
        "	ldrb r1, [r5, #0xa]\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	lsls r1, r1, #4\n\t"
        "	ands r0, r7\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #0x19]\n\t"
        "	ldrh r0, [r5, #0xc]\n\t"
        "	strb r0, [r4, #7]\n\t"
        "	ldrh r0, [r5, #0xe]\n\t"
        "	strb r0, [r4, #0x1d]\n\t"
        "	ldr r1, _0808D0E4\n\t"
        "	ldrb r0, [r5, #9]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x20\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl SetEventObjectDirection\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl SetEventObjectDynamicGraphicsId\n\t"
        "	ldr r1, _0808D0E8\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808D0CE\n\t"
        "	ldrb r2, [r4, #0x19]\n\t"
        "	adds r0, r7, #0\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808D0B6\n\t"
        "	lsls r0, r2, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	adds r0, #1\n\t"
        "	mov r1, sb\n\t"
        "	ands r0, r1\n\t"
        "	mov r1, r8\n\t"
        "	ands r1, r2\n\t"
        "	orrs r1, r0\n\t"
        "	strb r1, [r4, #0x19]\n\t"
        "_0808D0B6:\n\t"
        "	ldrb r2, [r4, #0x19]\n\t"
        "	movs r0, #0xf0\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808D0CE\n\t"
        "	lsrs r1, r2, #4\n\t"
        "	adds r1, #1\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r0, r7, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #0x19]\n\t"
        "_0808D0CE:\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0]\n\t"
        "_0808D0D2:\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808D0E0: .4byte gObjectEvents\n\t"
        "_0808D0E4: .4byte gUnknown_84DDA21\n\t"
        "_0808D0E8: .4byte gUnknown_84DD9D0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Unref_TryInitLocalEventObject(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	ldr r4, _0808D114\n\t"
        "	ldr r0, [r4, #4]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808D16E\n\t"
        "	bl CurrentBattlePyramidLocation\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808D118\n\t"
        "	bl GetNumBattlePyramidEventObjects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	b _0808D13A\n\t"
        "	.align 2, 0\n\t"
        "_0808D114: .4byte gMapHeader\n\t"
        "_0808D118:\n\t"
        "	bl InTrainerHill\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808D136\n\t"
        "	movs r6, #2\n\t"
        "	b _0808D13A\n\t"
        "_0808D124:\n\t"
        "	ldr r0, [r7]\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	ldrb r2, [r0, #4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl InitEventObjectStateFromTemplate\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	b _0808D170\n\t"
        "_0808D136:\n\t"
        "	ldr r0, [r4, #4]\n\t"
        "	ldrb r6, [r0]\n\t"
        "_0808D13A:\n\t"
        "	movs r5, #0\n\t"
        "	cmp r5, r6\n\t"
        "	bhs _0808D16E\n\t"
        "	ldr r7, _0808D17C\n\t"
        "_0808D142:\n\t"
        "	lsls r0, r5, #1\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	movs r1, #0xc7\n\t"
        "	lsls r1, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r7]\n\t"
        "	adds r4, r1, r0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	cmp r0, r8\n\t"
        "	bne _0808D164\n\t"
        "	ldrh r0, [r4, #0x14]\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808D124\n\t"
        "_0808D164:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, r6\n\t"
        "	blo _0808D142\n\t"
        "_0808D16E:\n\t"
        "	movs r0, #0x10\n\t"
        "_0808D170:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808D17C: .4byte gSaveBlock1Ptr\n\t"
        ".syntax divided\n\t"
    );
}

bool8 GetAvailableEventObjectId(u16 localId, u8 mapNum, u8 mapGroup, u8 *objectEventId)
{
    u8 i = 0;

    for (i = 0; i < OBJECT_EVENTS_COUNT && gObjectEvents[i].active; i++)
    {
        if (gObjectEvents[i].localId == localId && gObjectEvents[i].mapNum == mapNum && gObjectEvents[i].mapGroup == mapGroup)
            return TRUE;
    }
    if (i >= OBJECT_EVENTS_COUNT)
        return TRUE;
    *objectEventId = i;
    for (; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].localId == localId && gObjectEvents[i].mapNum == mapNum && gObjectEvents[i].mapGroup == mapGroup)
            return TRUE;
    }
    return FALSE;
}
void RemoveObjectEvent(struct ObjectEvent *objectEvent)
{
    objectEvent->active = FALSE;
    RemoveEventObjectInternal(objectEvent);
}



__attribute__((naked)) void RemoveObjectEventByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808D272\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetEventObjectFlagIdByEventObjectId\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	bl FlagSet\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808D278\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl RemoveObjectEvent\n\t"
        "_0808D272:\n\t"
        "	add sp, #4\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808D278: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void RemoveEventObjectInternal(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrb r0, [r4, #5]\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	ldrh r2, [r0, #6]\n\t"
        "	ldr r1, _0808D2C0\n\t"
        "	ldr r0, [sp, #4]\n\t"
        "	ands r0, r1\n\t"
        "	orrs r0, r2\n\t"
        "	str r0, [sp, #4]\n\t"
        "	ldr r2, _0808D2C4\n\t"
        "	ldrb r1, [r4, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r1, #0xc\n\t"
        "	adds r0, r0, r1\n\t"
        "	mov r1, sp\n\t"
        "	str r1, [r0]\n\t"
        "	ldrb r1, [r4, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	bl DestroySprite\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808D2C0: .4byte 0xFFFF0000\n\t"
        "_0808D2C4: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

void RemoveAllEventObjectsExceptPlayer(void)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (i != gPlayerAvatar.objectEventId)
            RemoveObjectEvent(&gObjectEvents[i]);
    }
}

__attribute__((naked)) void TrySetupEventObjectSprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	mov r8, r1\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r2, r3, #0\n\t"
        "	ldr r3, [sp, #0x24]\n\t"
        "	ldr r4, [sp, #0x28]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r3, r3, #0x10\n\t"
        "	mov sl, r3\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	str r4, [sp]\n\t"
        "	bl InitEventObjectStateFromTemplate\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	cmp r0, #0x10\n\t"
        "	bne _0808D338\n\t"
        "	movs r0, #0x10\n\t"
        "	b _0808D49C\n\t"
        "_0808D338:\n\t"
        "	mov r0, sb\n\t"
        "	lsls r4, r0, #3\n\t"
        "	adds r0, r4, r0\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808D360\n\t"
        "	adds r6, r0, r1\n\t"
        "	ldrb r0, [r6, #5]\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	adds r7, r0, #0\n\t"
        "	ldrb r0, [r7, #0xc]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r5, r0, #0x1c\n\t"
        "	cmp r5, #0\n\t"
        "	bne _0808D364\n\t"
        "	ldrh r0, [r7, #2]\n\t"
        "	movs r1, #0\n\t"
        "	bl LoadPlayerObjectReflectionPalette\n\t"
        "	b _0808D386\n\t"
        "	.align 2, 0\n\t"
        "_0808D360: .4byte gObjectEvents\n\t"
        "_0808D364:\n\t"
        "	cmp r5, #0xa\n\t"
        "	bne _0808D372\n\t"
        "	ldrh r0, [r7, #2]\n\t"
        "	movs r1, #0xa\n\t"
        "	bl LoadSpecialObjectReflectionPalette\n\t"
        "	b _0808D386\n\t"
        "_0808D372:\n\t"
        "	cmp r5, #0xf\n\t"
        "	bls _0808D386\n\t"
        "	adds r0, r5, #0\n\t"
        "	subs r0, #0x10\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldrh r0, [r7, #2]\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl _PatchObjectPalette\n\t"
        "_0808D386:\n\t"
        "	ldrb r0, [r6, #6]\n\t"
        "	cmp r0, #0x4c\n\t"
        "	bne _0808D394\n\t"
        "	ldrb r0, [r6, #1]\n\t"
        "	movs r1, #0x20\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r6, #1]\n\t"
        "_0808D394:\n\t"
        "	ldr r1, _0808D3CC\n\t"
        "	adds r0, r1, #0\n\t"
        "	mov r2, r8\n\t"
        "	strh r0, [r2, #2]\n\t"
        "	mov r0, r8\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	cmp r0, #0x40\n\t"
        "	bne _0808D3D4\n\t"
        "	ldr r0, _0808D3D0\n\t"
        "	mov r2, sb\n\t"
        "	adds r1, r4, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r0, #2\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #0x10\n\t"
        "	b _0808D49C\n\t"
        "	.align 2, 0\n\t"
        "_0808D3CC: .4byte 0x0000FFFF\n\t"
        "_0808D3D0: .4byte gObjectEvents\n\t"
        "_0808D3D4:\n\t"
        "	mov r1, r8\n\t"
        "	lsls r0, r1, #4\n\t"
        "	add r0, r8\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808D4AC\n\t"
        "	adds r4, r0, r1\n\t"
        "	mov r2, sl\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	ldrh r1, [r6, #0x10]\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	ldr r2, [sp]\n\t"
        "	lsls r1, r2, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrh r2, [r6, #0x12]\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x20\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x22\n\t"
        "	bl GetMapCoordsFromSpritePos\n\t"
        "	ldrh r0, [r7, #8]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x28\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrh r0, [r7, #0xa]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x29\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r4, #0x20]\n\t"
        "	adds r0, #8\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	ldrh r1, [r4, #0x22]\n\t"
        "	adds r1, #0x10\n\t"
        "	movs r0, #0\n\t"
        "	ldrsb r0, [r2, r0]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r4, #0x22]\n\t"
        "	lsls r2, r5, #4\n\t"
        "	ldrb r1, [r4, #5]\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r4, #5]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	mov r0, sb\n\t"
        "	strh r0, [r4, #0x2e]\n\t"
        "	mov r1, r8\n\t"
        "	strb r1, [r6, #4]\n\t"
        "	ldrb r1, [r7, #0xc]\n\t"
        "	lsls r1, r1, #0x19\n\t"
        "	lsrs r1, r1, #0x1f\n\t"
        "	lsls r1, r1, #4\n\t"
        "	ldrb r2, [r6, #1]\n\t"
        "	movs r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r6, #1]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	cmp r0, #0\n\t"
        "	blt _0808D486\n\t"
        "	ldrb r0, [r6, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl GetJumpInPlaceMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "_0808D486:\n\t"
        "	ldrb r0, [r6, #0xb]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl SetObjectSubpriorityByElevation\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl UpdateObjectEventVisibility\n\t"
        "	mov r0, sb\n\t"
        "_0808D49C:\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808D4AC: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void TrySpawnObjectEventTemplate(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #0x2c\n\t"
        "	mov sb, r0\n\t"
        "	adds r6, r1, #0\n\t"
        "	mov r8, r2\n\t"
        "	adds r4, r3, #0\n\t"
        "	ldr r5, [sp, #0x48]\n\t"
        "	lsls r6, r6, #0x18\n\t"
        "	lsrs r6, r6, #0x18\n\t"
        "	mov r0, r8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #0x20]\n\t"
        "	mov r1, sb\n\t"
        "	ldrb r0, [r1, #1]\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	adds r7, r0, #0\n\t"
        "	add r2, sp, #0x20\n\t"
        "	mov r0, sb\n\t"
        "	add r1, sp, #8\n\t"
        "	bl sub_0808D6C0\n\t"
        "	ldrh r3, [r7, #6]\n\t"
        "	ldr r2, _0808D528\n\t"
        "	add r1, sp, #0x24\n\t"
        "	ldr r0, [r1, #4]\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r3\n\t"
        "	str r0, [r1, #4]\n\t"
        "	str r1, [sp, #0x14]\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	asrs r4, r4, #0x10\n\t"
        "	str r4, [sp]\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	asrs r5, r5, #0x10\n\t"
        "	str r5, [sp, #4]\n\t"
        "	mov r0, sb\n\t"
        "	add r1, sp, #8\n\t"
        "	adds r2, r6, #0\n\t"
        "	mov r3, r8\n\t"
        "	bl TrySetupEventObjectSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	adds r5, r2, #0\n\t"
        "	cmp r2, #0x10\n\t"
        "	bne _0808D52C\n\t"
        "	movs r0, #0x10\n\t"
        "	b _0808D562\n\t"
        "	.align 2, 0\n\t"
        "_0808D528: .4byte 0xFFFF0000\n\t"
        "_0808D52C:\n\t"
        "	ldr r4, _0808D570\n\t"
        "	ldr r1, _0808D574\n\t"
        "	lsls r0, r2, #3\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r3, r0, r1\n\t"
        "	ldrb r1, [r3, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0xc\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r7, #0x1c]\n\t"
        "	str r1, [r0]\n\t"
        "	ldr r2, [sp, #0x20]\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0808D560\n\t"
        "	ldrb r1, [r3, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl SetSubspriteTables\n\t"
        "_0808D560:\n\t"
        "	adds r0, r5, #0\n\t"
        "_0808D562:\n\t"
        "	add sp, #0x2c\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808D570: .4byte gSprites\n\t"
        "_0808D574: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SpawnSpecialEventObject(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r5, r0, #0\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #6\n\t"
        "	add r0, sp, #4\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GetEventObjectMovingCameraOffset\n\t"
        "	ldr r0, _0808D5B0\n\t"
        "	ldr r0, [r0]\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	ldrb r2, [r0, #4]\n\t"
        "	add r0, sp, #4\n\t"
        "	movs r6, #0\n\t"
        "	ldrsh r3, [r0, r6]\n\t"
        "	movs r6, #0\n\t"
        "	ldrsh r0, [r4, r6]\n\t"
        "	str r0, [sp]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl TrySpawnObjectEventTemplate\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808D5B0: .4byte gSaveBlock1Ptr\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) u8 SpawnSpecialObjectEventParameterized(u8 graphicsId, u8 movementBehavior, u8 localId, s16 x, s16 y, u8 elevation)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	sub sp, #0x18\n\t"
        "	ldr r4, [sp, #0x2c]\n\t"
        "	ldr r5, [sp, #0x30]\n\t"
        "	mov r8, r5\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	ldr r5, _0808D618\n\t"
        "	adds r3, r3, r5\n\t"
        "	lsrs r3, r3, #0x10\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	adds r4, r4, r5\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	mov r5, sp\n\t"
        "	movs r6, #0\n\t"
        "	strb r2, [r5]\n\t"
        "	mov r2, sp\n\t"
        "	strb r0, [r2, #1]\n\t"
        "	mov r0, sp\n\t"
        "	strb r6, [r0, #2]\n\t"
        "	movs r5, #0\n\t"
        "	strh r3, [r0, #4]\n\t"
        "	strh r4, [r0, #6]\n\t"
        "	mov r2, r8\n\t"
        "	strb r2, [r0, #8]\n\t"
        "	strb r1, [r0, #9]\n\t"
        "	mov r2, sp\n\t"
        "	ldrb r1, [r2, #0xa]\n\t"
        "	movs r0, #0x10\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #0xa]\n\t"
        "	mov r0, sp\n\t"
        "	strb r5, [r0, #0xa]\n\t"
        "	strh r6, [r0, #0xc]\n\t"
        "	strh r6, [r0, #0xe]\n\t"
        "	bl SpawnSpecialEventObject\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	add sp, #0x18\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808D618: .4byte 0xFFF90000\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 TrySpawnObjectEvent(u8 localId, u8 mapNum, u8 mapGroup)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r7, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r6, r2, #0x18\n\t"
        "	adds r1, r7, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl GetEventObjectTemplateByLocalIdAndMap\n\t"
        "	adds r5, r0, #0\n\t"
        "	cmp r5, #0\n\t"
        "	beq _0808D662\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #6\n\t"
        "	add r0, sp, #4\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GetEventObjectMovingCameraOffset\n\t"
        "	add r0, sp, #4\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r3, [r0, r1]\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	str r0, [sp]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl TrySpawnObjectEventTemplate\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	b _0808D664\n\t"
        "_0808D662:\n\t"
        "	movs r0, #0x10\n\t"
        "_0808D664:\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

void CopyObjectGraphicsInfoToSpriteTemplate(u16 graphicsId, void (*callback)(struct Sprite *), struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(graphicsId);

    spriteTemplate->tileTag = graphicsInfo->tileTag;
    spriteTemplate->paletteTag = graphicsInfo->paletteTag;
    spriteTemplate->oam = graphicsInfo->oam;
    spriteTemplate->anims = graphicsInfo->anims;
    spriteTemplate->images = graphicsInfo->images;
    spriteTemplate->affineAnims = graphicsInfo->affineAnims;
    spriteTemplate->callback = callback;
    *subspriteTables = graphicsInfo->subspriteTables;
}

void MakeObjectTemplateFromEventObjectGraphicsInfoWithCallbackIndex(u16 graphicsId, u16 callbackIndex, struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    CopyObjectGraphicsInfoToSpriteTemplate(graphicsId, sMovementTypeCallbacks[callbackIndex], spriteTemplate, subspriteTables);
}

void sub_0808D6C0(struct ObjectEventTemplate *template, struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables)
{
    MakeObjectTemplateFromEventObjectGraphicsInfoWithCallbackIndex(template->graphicsId, template->movementType, spriteTemplate, subspriteTables);
}

__attribute__((naked)) void AddPseudoEventObject(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldr r0, [sp, #0x20]\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	mov r8, r2\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r7, r3, #0x10\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	movs r0, #0x18\n\t"
        "	bl Alloc\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	mov r3, sp\n\t"
        "	bl CopyObjectGraphicsInfoToSpriteTemplate\n\t"
        "	ldrh r1, [r6, #2]\n\t"
        "	ldr r0, _0808D774\n\t"
        "	cmp r1, r0\n\t"
        "	beq _0808D71E\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl LoadEventObjectPalette\n\t"
        "_0808D71E:\n\t"
        "	mov r0, r8\n\t"
        "	lsls r1, r0, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	lsls r2, r7, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	adds r0, r6, #0\n\t"
        "	mov r3, sb\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl Free\n\t"
        "	cmp r5, #0x40\n\t"
        "	beq _0808D762\n\t"
        "	ldr r1, [sp]\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0808D762\n\t"
        "	lsls r4, r5, #4\n\t"
        "	adds r4, r4, r5\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808D778\n\t"
        "	adds r4, r4, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl SetSubspriteTables\n\t"
        "	adds r4, #0x42\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #0x3f\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x80\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "_0808D762:\n\t"
        "	adds r0, r5, #0\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808D774: .4byte 0x0000FFFF\n\t"
        "_0808D778: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sprite_new(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x20\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldr r0, [sp, #0x40]\n\t"
        "	ldr r4, [sp, #0x44]\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	mov sb, r1\n\t"
        "	add r1, sp, #0x18\n\t"
        "	mov r8, r1\n\t"
        "	strh r2, [r1]\n\t"
        "	mov r6, sp\n\t"
        "	adds r6, #0x1a\n\t"
        "	strh r3, [r6]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	mov sl, r4\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _0808D87C\n\t"
        "	add r3, sp, #0x1c\n\t"
        "	adds r0, r5, #0\n\t"
        "	mov r2, sp\n\t"
        "	bl CopyObjectGraphicsInfoToSpriteTemplate\n\t"
        "	mov r1, sp\n\t"
        "	ldr r2, _0808D880\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	mov r1, r8\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r1, r2]\n\t"
        "	adds r0, #7\n\t"
        "	strh r0, [r1]\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	adds r0, #7\n\t"
        "	strh r0, [r6]\n\t"
        "	mov r0, r8\n\t"
        "	adds r1, r6, #0\n\t"
        "	movs r2, #8\n\t"
        "	movs r3, #0x10\n\t"
        "	bl SetSpritePosToOffsetMapCoords\n\t"
        "	mov r2, r8\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r2, r0]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r6, r0]\n\t"
        "	mov r0, sp\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSpriteAtEnd\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #0x40\n\t"
        "	beq _0808D8DC\n\t"
        "	lsls r0, r6, #4\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808D884\n\t"
        "	adds r5, r0, r1\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r1, #0x28\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	adds r1, #1\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsb r0, [r1, r0]\n\t"
        "	ldrh r1, [r5, #0x22]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r5, #0x22]\n\t"
        "	ldrb r0, [r4, #0xc]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldrb r1, [r5, #5]\n\t"
        "	movs r3, #0xf\n\t"
        "	adds r2, r3, #0\n\t"
        "	ands r2, r1\n\t"
        "	orrs r2, r0\n\t"
        "	strb r2, [r5, #5]\n\t"
        "	lsls r1, r2, #0x18\n\t"
        "	lsrs r0, r1, #0x1c\n\t"
        "	cmp r0, #0xf\n\t"
        "	bls _0808D854\n\t"
        "	subs r0, #0x10\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ands r2, r3\n\t"
        "	orrs r2, r0\n\t"
        "	strb r2, [r5, #5]\n\t"
        "_0808D854:\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	mov r2, sb\n\t"
        "	strh r2, [r5, #0x2e]\n\t"
        "	strh r7, [r5, #0x30]\n\t"
        "	ldrb r1, [r4, #0xc]\n\t"
        "	adds r0, r3, #0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0xa\n\t"
        "	bne _0808D888\n\t"
        "	ldrh r0, [r4, #2]\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	bl LoadSpecialObjectReflectionPalette\n\t"
        "	b _0808D89C\n\t"
        "	.align 2, 0\n\t"
        "_0808D87C: .4byte SpriteCB_VirtualObject + 1\n\t"
        "_0808D880: .4byte 0x0000FFFF\n\t"
        "_0808D884: .4byte gSprites\n\t"
        "_0808D888:\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r0, r1, #0x1c\n\t"
        "	cmp r0, #0xf\n\t"
        "	bls _0808D89C\n\t"
        "	ldrh r0, [r4, #2]\n\t"
        "	lsrs r2, r1, #0x1c\n\t"
        "	movs r1, #0xf0\n\t"
        "	orrs r1, r2\n\t"
        "	bl _PatchObjectPalette\n\t"
        "_0808D89C:\n\t"
        "	ldr r1, [sp, #0x1c]\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0808D8B8\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl SetSubspriteTables\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0x42\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #0x3f\n\t"
        "	ands r1, r0\n\t"
        "	movs r0, #0x80\n\t"
        "	orrs r1, r0\n\t"
        "	strb r1, [r2]\n\t"
        "_0808D8B8:\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl InitObjectPriorityByZCoord\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl SetObjectSubpriorityByElevation\n\t"
        "	mov r0, sl\n\t"
        "	bl GetJumpInPlaceMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "_0808D8DC:\n\t"
        "	adds r0, r6, #0\n\t"
        "	add sp, #0x20\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void TrySpawnObjectEvents(s16 cameraX, s16 cameraY)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x10\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	str r0, [sp, #4]\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	str r1, [sp, #8]\n\t"
        "	ldr r5, _0808D948\n\t"
        "	ldr r0, [r5, #4]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808D9E8\n\t"
        "	ldr r0, _0808D94C\n\t"
        "	ldr r2, [r0]\n\t"
        "	ldrh r1, [r2]\n\t"
        "	subs r0, r1, #2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "	adds r1, #0x11\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	str r1, [sp, #0xc]\n\t"
        "	ldrh r4, [r2, #2]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x10\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	mov sl, r0\n\t"
        "	bl CurrentBattlePyramidLocation\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808D950\n\t"
        "	bl GetNumBattlePyramidEventObjects\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	b _0808D960\n\t"
        "	.align 2, 0\n\t"
        "_0808D948: .4byte gMapHeader\n\t"
        "_0808D94C: .4byte gSaveBlock1Ptr\n\t"
        "_0808D950:\n\t"
        "	bl InTrainerHill\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808D95C\n\t"
        "	movs r6, #2\n\t"
        "	b _0808D960\n\t"
        "_0808D95C:\n\t"
        "	ldr r0, [r5, #4]\n\t"
        "	ldrb r6, [r0]\n\t"
        "_0808D960:\n\t"
        "	movs r5, #0\n\t"
        "	cmp r5, r6\n\t"
        "	bhs _0808D9E8\n\t"
        "	lsls r0, r4, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	mov sb, r0\n\t"
        "	mov r1, r8\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "_0808D974:\n\t"
        "	lsls r0, r5, #1\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #3\n\t"
        "	movs r2, #0xc7\n\t"
        "	lsls r2, r2, #4\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldr r3, _0808D9F8\n\t"
        "	ldr r1, [r3]\n\t"
        "	adds r4, r1, r0\n\t"
        "	ldrh r0, [r4, #4]\n\t"
        "	adds r0, #7\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r2, r0, #0x10\n\t"
        "	ldrh r0, [r4, #6]\n\t"
        "	adds r0, #7\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r1, r0, #0x10\n\t"
        "	cmp sb, r1\n\t"
        "	bgt _0808D9DE\n\t"
        "	mov r7, sl\n\t"
        "	lsls r0, r7, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, r1\n\t"
        "	blt _0808D9DE\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	asrs r1, r0, #0x10\n\t"
        "	cmp r8, r1\n\t"
        "	bgt _0808D9DE\n\t"
        "	ldr r2, [sp, #0xc]\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, r1\n\t"
        "	blt _0808D9DE\n\t"
        "	ldrh r0, [r4, #0x14]\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808D9DE\n\t"
        "	ldr r3, _0808D9F8\n\t"
        "	ldr r0, [r3]\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	ldrb r2, [r0, #4]\n\t"
        "	ldr r7, [sp, #4]\n\t"
        "	lsls r3, r7, #0x10\n\t"
        "	ldr r7, [sp, #8]\n\t"
        "	lsls r0, r7, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	str r0, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	asrs r3, r3, #0x10\n\t"
        "	bl TrySpawnObjectEventTemplate\n\t"
        "_0808D9DE:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, r6\n\t"
        "	blo _0808D974\n\t"
        "_0808D9E8:\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808D9F8: .4byte gSaveBlock1Ptr\n\t"
        ".syntax divided\n\t"
    );
}

void RemoveEventObjectsOutsideView(void)
{
    u8 i, j;
    bool8 isActiveLinkPlayer;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        for (j = 0, isActiveLinkPlayer = FALSE; j < ARRAY_COUNT(gLinkPlayerObjectEvents); j++)
        {
            if (gLinkPlayerObjectEvents[j].active && i == gLinkPlayerObjectEvents[j].objEventId)
                isActiveLinkPlayer = TRUE;
        }
        if (!isActiveLinkPlayer)
        {
            struct ObjectEvent *objectEvent = &gObjectEvents[i];

            if (objectEvent->active && !objectEvent->isPlayer)
                RemoveEventObjectIfOutsideView(objectEvent);
        }
    }
}

void RemoveEventObjectIfOutsideView(struct ObjectEvent *objectEvent)
{
    s16 left =   gSaveBlock1Ptr->pos.x - 2;
    s16 right =  gSaveBlock1Ptr->pos.x + 17;
    s16 top =    gSaveBlock1Ptr->pos.y;
    s16 bottom = gSaveBlock1Ptr->pos.y + 16;

    if (objectEvent->currentCoords.x >= left && objectEvent->currentCoords.x <= right
     && objectEvent->currentCoords.y >= top && objectEvent->currentCoords.y <= bottom)
        return;
    if (objectEvent->initialCoords.x >= left && objectEvent->initialCoords.x <= right
     && objectEvent->initialCoords.y >= top && objectEvent->initialCoords.y <= bottom)
        return;
    RemoveObjectEvent(objectEvent);
}

__attribute__((naked)) void sub_0808DADC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	bl ClearPlayerAvatarInfo\n\t"
        "	movs r6, #0\n\t"
        "	ldr r7, _0808DB24\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "_0808DAF6:\n\t"
        "	lsls r0, r6, #3\n\t"
        "	adds r0, r0, r6\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808DB10\n\t"
        "	adds r0, r6, #0\n\t"
        "	asrs r1, r4, #0x10\n\t"
        "	asrs r2, r5, #0x10\n\t"
        "	bl sub_0808DB28\n\t"
        "_0808DB10:\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #0xf\n\t"
        "	bls _0808DAF6\n\t"
        "	bl CreateReflectionEffectSprites\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808DB24: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808DB28(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x28\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	mov sl, r1\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	str r2, [sp, #0x24]\n\t"
        "	movs r7, #0\n\t"
        "	ldr r2, _0808DBB8\n\t"
        "_0808DB4A:\n\t"
        "	lsls r0, r7, #2\n\t"
        "	adds r1, r0, r2\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808DB5C\n\t"
        "	ldrb r1, [r1, #2]\n\t"
        "	cmp sb, r1\n\t"
        "	bne _0808DB5C\n\t"
        "	b _0808DCE4\n\t"
        "_0808DB5C:\n\t"
        "	adds r0, r7, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	cmp r7, #3\n\t"
        "	bls _0808DB4A\n\t"
        "	mov r1, sb\n\t"
        "	lsls r0, r1, #3\n\t"
        "	add r0, sb\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808DBBC\n\t"
        "	adds r6, r0, r1\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp, #0x20]\n\t"
        "	ldrb r0, [r6, #5]\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldrh r2, [r5, #6]\n\t"
        "	ldr r1, _0808DBC0\n\t"
        "	add r4, sp, #0x18\n\t"
        "	ldr r0, [r4, #4]\n\t"
        "	ands r0, r1\n\t"
        "	orrs r0, r2\n\t"
        "	str r0, [r4, #4]\n\t"
        "	ldrb r0, [r6, #5]\n\t"
        "	ldrb r1, [r6, #6]\n\t"
        "	add r3, sp, #0x20\n\t"
        "	mov r2, sp\n\t"
        "	bl MakeObjectTemplateFromEventObjectGraphicsInfoWithCallbackIndex\n\t"
        "	str r4, [sp, #0xc]\n\t"
        "	mov r1, sp\n\t"
        "	ldr r2, _0808DBC4\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	ldrb r0, [r5, #0xc]\n\t"
        "	lsls r1, r0, #0x1c\n\t"
        "	lsrs r0, r1, #0x1c\n\t"
        "	mov r8, r0\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808DBC8\n\t"
        "	ldrh r0, [r5, #2]\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	bl LoadPlayerObjectReflectionPalette\n\t"
        "	b _0808DBEE\n\t"
        "	.align 2, 0\n\t"
        "_0808DBB8: .4byte gLinkPlayerObjectEvents\n\t"
        "_0808DBBC: .4byte gObjectEvents\n\t"
        "_0808DBC0: .4byte 0xFFFF0000\n\t"
        "_0808DBC4: .4byte 0x0000FFFF\n\t"
        "_0808DBC8:\n\t"
        "	mov r2, r8\n\t"
        "	cmp r2, #0xa\n\t"
        "	bne _0808DBD8\n\t"
        "	ldrh r0, [r5, #2]\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	bl LoadSpecialObjectReflectionPalette\n\t"
        "	b _0808DBEE\n\t"
        "_0808DBD8:\n\t"
        "	mov r0, r8\n\t"
        "	cmp r0, #0xf\n\t"
        "	bls _0808DBEE\n\t"
        "	subs r0, #0x10\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	ldrh r0, [r5, #2]\n\t"
        "	mov r1, r8\n\t"
        "	bl _PatchObjectPalette\n\t"
        "_0808DBEE:\n\t"
        "	mov r1, sp\n\t"
        "	ldr r2, _0808DCF4\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1, #2]\n\t"
        "	mov r0, sp\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl CreateSprite\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r7, r0, #0x18\n\t"
        "	cmp r7, #0x40\n\t"
        "	beq _0808DCE4\n\t"
        "	lsls r0, r7, #4\n\t"
        "	adds r0, r0, r7\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808DCF8\n\t"
        "	adds r4, r0, r1\n\t"
        "	mov r1, sl\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	ldrh r2, [r6, #0x10]\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	ldr r2, [sp, #0x24]\n\t"
        "	lsls r1, r2, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrh r2, [r6, #0x12]\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x20\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x22\n\t"
        "	bl GetMapCoordsFromSpritePos\n\t"
        "	ldrh r0, [r5, #8]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x28\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrh r0, [r5, #0xa]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x29\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r4, #0x20]\n\t"
        "	adds r0, #8\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	ldrh r1, [r4, #0x22]\n\t"
        "	adds r1, #0x10\n\t"
        "	movs r0, #0\n\t"
        "	ldrsb r0, [r2, r0]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r4, #0x22]\n\t"
        "	ldr r0, [r5, #0x1c]\n\t"
        "	str r0, [r4, #0xc]\n\t"
        "	ldrb r0, [r6, #6]\n\t"
        "	cmp r0, #0xb\n\t"
        "	bne _0808DC82\n\t"
        "	mov r0, sb\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl SetPlayerAvatarEventObjectIdAndObjectId\n\t"
        "	bl CreateWarpArrowSprite\n\t"
        "	strb r0, [r6, #0x1b]\n\t"
        "_0808DC82:\n\t"
        "	ldr r1, [sp, #0x20]\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0808DC8E\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl SetSubspriteTables\n\t"
        "_0808DC8E:\n\t"
        "	mov r0, r8\n\t"
        "	lsls r2, r0, #4\n\t"
        "	ldrb r1, [r4, #5]\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r4, #5]\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	mov r1, sb\n\t"
        "	strh r1, [r4, #0x2e]\n\t"
        "	strb r7, [r6, #4]\n\t"
        "	ldrb r0, [r6, #1]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	cmp r0, #0\n\t"
        "	blt _0808DCD2\n\t"
        "	ldrb r0, [r6, #6]\n\t"
        "	cmp r0, #0xb\n\t"
        "	beq _0808DCD2\n\t"
        "	ldrb r0, [r6, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl GetJumpInPlaceMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "_0808DCD2:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_0808DCFC\n\t"
        "	ldrb r0, [r6, #0xb]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	adds r1, r4, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl SetObjectSubpriorityByElevation\n\t"
        "_0808DCE4:\n\t"
        "	add sp, #0x28\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808DCF4: .4byte 0x0000FFFF\n\t"
        "_0808DCF8: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808DCFC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r3, #3\n\t"
        "	rsbs r3, r3, #0\n\t"
        "	adds r1, r3, #0\n\t"
        "	ands r1, r2\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r2, [r0, #2]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r2\n\t"
        "	ands r1, r3\n\t"
        "	movs r2, #5\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	ands r1, r2\n\t"
        "	subs r2, #4\n\t"
        "	ands r1, r2\n\t"
        "	subs r2, #8\n\t"
        "	ands r1, r2\n\t"
        "	subs r2, #0x10\n\t"
        "	ands r1, r2\n\t"
        "	strb r1, [r0, #2]\n\t"
        "	bl EventObjectClearHeldMovement\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

void SetPlayerAvatarEventObjectIdAndObjectId(u8 objectEventId, u8 spriteId)
{
    gPlayerAvatar.objectEventId = objectEventId;
    gPlayerAvatar.spriteId = spriteId;
    gPlayerAvatar.gender = GetPlayerAvatarGenderByGraphicsId(gObjectEvents[objectEventId].graphicsId);
    SetPlayerAvatarExtraStateTransition(gObjectEvents[objectEventId].graphicsId, PLAYER_AVATAR_FLAG_CONTROLLABLE);
}

void ObjectEventSetGraphicsId(struct ObjectEvent *objectEvent, u8 graphicsId)
{
    const struct ObjectEventGraphicsInfo *graphicsInfo;
    struct Sprite *sprite;
    u8 paletteSlot;

    graphicsInfo = GetObjectEventGraphicsInfo(graphicsId);
    sprite = &gSprites[objectEvent->spriteId];
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == PALSLOT_PLAYER)
    {
        PatchObjectPalette(graphicsInfo->paletteTag, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot == PALSLOT_NPC_SPECIAL)
    {
        LoadSpecialObjectReflectionPalette(graphicsInfo->paletteTag, graphicsInfo->paletteSlot);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        _PatchObjectPalette(graphicsInfo->paletteTag, paletteSlot);
    }
    sprite->oam.shape = graphicsInfo->oam->shape;
    sprite->oam.size = graphicsInfo->oam->size;
    sprite->images = graphicsInfo->images;
    sprite->anims = graphicsInfo->anims;
    sprite->subspriteTables = graphicsInfo->subspriteTables;
    sprite->oam.paletteNum = paletteSlot;
    objectEvent->inanimate = graphicsInfo->inanimate;
    objectEvent->graphicsId = graphicsId;
    SetSpritePosToMapCoords(objectEvent->currentCoords.x, objectEvent->currentCoords.y, &sprite->x, &sprite->y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->x += 8;
    sprite->y += 16 + sprite->centerToCornerVecY;
    if (objectEvent->trackedByCamera)
        CameraObjectReset();
}

void EventObjectSetGraphicsIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 graphicsId)
{
    u8 objectEventId;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
        ObjectEventSetGraphicsId(&gObjectEvents[objectEventId], graphicsId);
}

void EventObjectTurn(struct ObjectEvent *objectEvent, u8 direction)
{
    SetEventObjectDirection(objectEvent, direction);
    if (!objectEvent->inanimate)
    {
        StartSpriteAnim(&gSprites[objectEvent->spriteId], GetJumpInPlaceMovementAction(objectEvent->facingDirection));
        SeekSpriteAnim(&gSprites[objectEvent->spriteId], 0);
    }
}

void EventObjectTurnByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup, u8 direction)
{
    u8 objectEventId;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
        EventObjectTurn(&gObjectEvents[objectEventId], direction);
}

void PlayerObjectTurn(struct PlayerAvatar *playerAvatar, u8 direction)
{
    EventObjectTurn(&gObjectEvents[playerAvatar->objectEventId], direction);
}

__attribute__((naked)) void get_berry_tree_graphics(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	ldrb r0, [r5, #1]\n\t"
        "	movs r1, #0x20\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r5, #1]\n\t"
        "	adds r4, r7, #0\n\t"
        "	adds r4, #0x3e\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	ldrb r0, [r5, #0x1d]\n\t"
        "	bl GetStageByBerryTreeId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #0\n\t"
        "	beq _0808DFF0\n\t"
        "	ldrb r1, [r5, #1]\n\t"
        "	movs r0, #0x21\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r5, #1]\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	ldrb r0, [r5, #0x1d]\n\t"
        "	bl GetBerryTypeByBerryTreeId\n\t"
        "	subs r0, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	subs r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r4, #0x2b\n\t"
        "	bls _0808DFB8\n\t"
        "	movs r4, #0\n\t"
        "_0808DFB8:\n\t"
        "	ldr r0, _0808DFF8\n\t"
        "	lsls r4, r4, #2\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventSetGraphicsId\n\t"
        "	ldr r0, _0808DFFC\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [r7, #0xc]\n\t"
        "	ldr r0, _0808E000\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldr r0, [r4]\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r1, r1, #4\n\t"
        "	ldrb r2, [r7, #5]\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r7, #5]\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "_0808DFF0:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808DFF8: .4byte gUnknown_84E4D5C\n\t"
        "_0808DFFC: .4byte gUnknown_84E4C04\n\t"
        "_0808E000: .4byte gUnknown_84E4CB0\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) const struct ObjectEventGraphicsInfo *GetObjectEventGraphicsInfo(u8 graphicsId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #0xef\n\t"
        "	bls _0808E01C\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x10\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl VarGetObjectEventGraphicsId\n\t"
        "	adds r1, r0, #0\n\t"
        "_0808E01C:\n\t"
        "	cmp r1, #0x45\n\t"
        "	bne _0808E034\n\t"
        "	bl GetCurrentMauvilleOldMan\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r1, _0808E030\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	b _0808E042\n\t"
        "	.align 2, 0\n\t"
        "_0808E030: .4byte gUnknown_84DDE30\n\t"
        "_0808E034:\n\t"
        "	cmp r1, #0xee\n\t"
        "	bls _0808E03A\n\t"
        "	movs r1, #5\n\t"
        "_0808E03A:\n\t"
        "	ldr r0, _0808E048\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, [r1]\n\t"
        "_0808E042:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808E048: .4byte gUnknown_84DDA74\n\t"
        ".syntax divided\n\t"
    );
}

void SetEventObjectDynamicGraphicsId(struct ObjectEvent *objectEvent)
{
    if (objectEvent->graphicsId >= OBJ_EVENT_GFX_VARS)
        // JP 原版用 u8 回绕的 +0x10 计算 var 索引（等价于 - OBJ_EVENT_GFX_VARS 模 256）。
        objectEvent->graphicsId = VarGetObjectEventGraphicsId((u8)(objectEvent->graphicsId + 0x10));
}

__attribute__((naked)) void npc_by_local_id_and_map_set_field_1_bit_x20(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r4, r3, #0x18\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808E0AA\n\t"
        "	ldr r2, _0808E0B4\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r0, #1\n\t"
        "	adds r2, r4, #0\n\t"
        "	ands r2, r0\n\t"
        "	lsls r2, r2, #5\n\t"
        "	ldrb r3, [r1, #1]\n\t"
        "	movs r0, #0x21\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r3\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1, #1]\n\t"
        "_0808E0AA:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808E0B4: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}


void ObjectEventGetLocalIdAndMap(struct ObjectEvent *objectEvent, void *localId, void *mapNum, void *mapGroup)
{
    *(u8 *)(localId) = objectEvent->localId;
    *(u8 *)(mapNum) = objectEvent->mapNum;
    *(u8 *)(mapGroup) = objectEvent->mapGroup;
}


void AllowObjectAtPosTriggerGroundEffects(s16 x, s16 y)
{
    u8 objectEventId;
    struct ObjectEvent *objectEvent;

    objectEventId = GetEventObjectIdByXY(x, y);
    if (objectEventId != OBJECT_EVENTS_COUNT)
    {
        objectEvent = &gObjectEvents[objectEventId];
        objectEvent->triggerGroundEffectsOnMove = TRUE;
    }
}

void SetObjectSubpriority(u8 localId, u8 mapNum, u8 mapGroup, u8 subpriority)
{
    u8 objectEventId;
    struct ObjectEvent *objectEvent;
    struct Sprite *sprite;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        objectEvent = &gObjectEvents[objectEventId];
        sprite = &gSprites[objectEvent->spriteId];
        objectEvent->fixedPriority = TRUE;
        sprite->subpriority = subpriority;
    }
}

void ResetObjectSubpriority(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;
    struct ObjectEvent *objectEvent;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        objectEvent = &gObjectEvents[objectEventId];
        objectEvent->fixedPriority = FALSE;
        objectEvent->triggerGroundEffectsOnMove = TRUE;
    }
}

__attribute__((naked)) void sub_0808E19C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r4, [sp, #0x10]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r5, r3, #0x10\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808E1E0\n\t"
        "	ldr r2, _0808E1E8\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r0, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808E1EC\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r5, [r0, #0x24]\n\t"
        "	strh r4, [r0, #0x26]\n\t"
        "_0808E1E0:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808E1E8: .4byte gObjectEvents\n\t"
        "_0808E1EC: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

void FreeAndReserveObjectSpritePalettes(void)
{
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 12; // OBJ_PALSLOT_COUNT
}

__attribute__((naked)) void LoadEventObjectPalette(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	bl FindEventObjectPaletteIndexByTag\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	ldr r0, _0808E228\n\t"
        "	cmp r1, r0\n\t"
        "	beq _0808E222\n\t"
        "	lsls r0, r1, #3\n\t"
        "	ldr r1, _0808E22C\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl sub_0808E264\n\t"
        "_0808E222:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808E228: .4byte 0x000011FF\n\t"
        "_0808E22C: .4byte sObjectEventSpritePalettes\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void LoadObjectEventPaletteSet(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	movs r4, #0\n\t"
        "	ldrh r0, [r5]\n\t"
        "	ldr r1, _0808E260\n\t"
        "	cmp r0, r1\n\t"
        "	beq _0808E25A\n\t"
        "	adds r6, r1, #0\n\t"
        "_0808E240:\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrh r0, [r0]\n\t"
        "	bl LoadEventObjectPalette\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r0, r4, #1\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r6\n\t"
        "	bne _0808E240\n\t"
        "_0808E25A:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808E260: .4byte 0x000011FF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_0808E264(const struct SpritePalette *palette)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrh r0, [r4, #4]\n\t"
        "	bl IndexOfSpritePaletteTag\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0xff\n\t"
        "	bne _0808E282\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl LoadSpritePalette\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	b _0808E284\n\t"
        "_0808E282:\n\t"
        "	movs r0, #0xff\n\t"
        "_0808E284:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void PatchObjectPalette(u16 paletteTag, u8 paletteSlot)
{
    u8 paletteIndex = FindEventObjectPaletteIndexByTag(paletteTag);
    LoadPalette(sObjectEventSpritePalettes[paletteIndex].data, OBJ_PLTT_ID(paletteSlot), PLTT_SIZE_4BPP);
}

void PatchObjectPaletteRange(const u16 *paletteTags, u8 minSlot, u8 maxSlot)
{
    while (minSlot < maxSlot)
    {
        PatchObjectPalette(*paletteTags, minSlot);
        paletteTags++;
        minSlot++;
    }
}

u8 FindEventObjectPaletteIndexByTag(u16 tag)
{
    u8 i;

    for (i = 0; sObjectEventSpritePalettes[i].tag != OBJ_EVENT_PAL_TAG_NONE; i++)
    {
        if (sObjectEventSpritePalettes[i].tag == tag)
            return i;
    }
    return 0xFF;
}

void LoadPlayerObjectReflectionPalette(u16 tag, u8 slot)
{
    u8 i;

    PatchObjectPalette(tag, slot);
    for (i = 0; sPlayerReflectionPaletteSets[i].tag != OBJ_EVENT_PAL_TAG_NONE; i++)
    {
        if (sPlayerReflectionPaletteSets[i].tag == tag)
        {
            PatchObjectPalette(sPlayerReflectionPaletteSets[i].data[gUnknown_2037254], gReflectionEffectPaletteMap[slot]);
            return;
        }
    }
}

void LoadSpecialObjectReflectionPalette(u16 tag, u8 slot)
{
    u8 i;

    gUnknown_2037256 = tag;
    PatchObjectPalette(tag, slot);
    for (i = 0; sSpecialObjectReflectionPaletteSets[i].tag != OBJ_EVENT_PAL_TAG_NONE; i++)
    {
        if (sSpecialObjectReflectionPaletteSets[i].tag == tag)
        {
            PatchObjectPalette(sSpecialObjectReflectionPaletteSets[i].data[gUnknown_2037254], gReflectionEffectPaletteMap[slot]);
            return;
        }
    }
}

void _PatchObjectPalette(u16 tag, u8 slot)
{
    PatchObjectPalette(tag, slot);
}


void IncrementObjectEventCoords(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    objectEvent->previousCoords.x = objectEvent->currentCoords.x;
    objectEvent->previousCoords.y = objectEvent->currentCoords.y;
    objectEvent->currentCoords.x += x;
    objectEvent->currentCoords.y += y;
}

void ShiftEventObjectCoords(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    objectEvent->previousCoords.x = objectEvent->currentCoords.x;
    objectEvent->previousCoords.y = objectEvent->currentCoords.y;
    objectEvent->currentCoords.x = x;
    objectEvent->currentCoords.y = y;
}


void SetEventObjectCoords(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    objectEvent->previousCoords.x = x;
    objectEvent->previousCoords.y = y;
    objectEvent->currentCoords.x = x;
    objectEvent->currentCoords.y = y;
}

__attribute__((naked)) void MoveEventObjectToMapCoords(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r5, r2, #0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	ldrb r1, [r6, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808E514\n\t"
        "	adds r7, r0, r1\n\t"
        "	ldrb r0, [r6, #5]\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	mov r8, r0\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	asrs r4, r4, #0x10\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	asrs r5, r5, #0x10\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl SetEventObjectCoords\n\t"
        "	movs r1, #0x10\n\t"
        "	ldrsh r0, [r6, r1]\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r6, r2]\n\t"
        "	adds r2, r7, #0\n\t"
        "	adds r2, #0x20\n\t"
        "	adds r3, r7, #0\n\t"
        "	adds r3, #0x22\n\t"
        "	bl SetSpritePosToMapCoords\n\t"
        "	mov r1, r8\n\t"
        "	ldrh r0, [r1, #8]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	adds r1, #0x28\n\t"
        "	strb r0, [r1]\n\t"
        "	mov r2, r8\n\t"
        "	ldrh r0, [r2, #0xa]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	adds r2, r7, #0\n\t"
        "	adds r2, #0x29\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r7, #0x20]\n\t"
        "	adds r0, #8\n\t"
        "	strh r0, [r7, #0x20]\n\t"
        "	ldrh r1, [r7, #0x22]\n\t"
        "	adds r1, #0x10\n\t"
        "	movs r0, #0\n\t"
        "	ldrsb r0, [r2, r0]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r7, #0x22]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_0808DCFC\n\t"
        "	ldrb r0, [r6, #1]\n\t"
        "	lsrs r0, r0, #7\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808E50A\n\t"
        "	bl CameraObjectReset\n\t"
        "_0808E50A:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808E514: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void TryMoveEventObjectToMapCoords(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r4, [sp, #0x10]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r5, r3, #0x10\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808E560\n\t"
        "	lsls r1, r5, #0x10\n\t"
        "	lsls r2, r4, #0x10\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r3, [r0]\n\t"
        "	lsls r0, r3, #3\n\t"
        "	adds r0, r0, r3\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r3, _0808E568\n\t"
        "	adds r0, r0, r3\n\t"
        "	movs r3, #0xe0\n\t"
        "	lsls r3, r3, #0xb\n\t"
        "	adds r1, r1, r3\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	adds r2, r2, r3\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	bl MoveEventObjectToMapCoords\n\t"
        "_0808E560:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808E568: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}

void ShiftStillEventObjectCoords(struct ObjectEvent *objectEvent)
{
    ShiftEventObjectCoords(objectEvent, objectEvent->currentCoords.x, objectEvent->currentCoords.y);
}

__attribute__((naked)) void UpdateEventObjectCoordsForCameraUpdate(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r2, _0808E5E0\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808E5D8\n\t"
        "	movs r3, #0\n\t"
        "	ldr r5, _0808E5E4\n\t"
        "	movs r0, #4\n\t"
        "	ldrsh r4, [r2, r0]\n\t"
        "	movs r0, #8\n\t"
        "	ldrsh r1, [r2, r0]\n\t"
        "_0808E59A:\n\t"
        "	lsls r0, r3, #3\n\t"
        "	adds r0, r0, r3\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r2, r0, r5\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808E5CE\n\t"
        "	ldrh r0, [r2, #0xc]\n\t"
        "	subs r0, r0, r4\n\t"
        "	strh r0, [r2, #0xc]\n\t"
        "	ldrh r0, [r2, #0xe]\n\t"
        "	subs r0, r0, r1\n\t"
        "	strh r0, [r2, #0xe]\n\t"
        "	ldrh r0, [r2, #0x10]\n\t"
        "	subs r0, r0, r4\n\t"
        "	strh r0, [r2, #0x10]\n\t"
        "	ldrh r0, [r2, #0x12]\n\t"
        "	subs r0, r0, r1\n\t"
        "	strh r0, [r2, #0x12]\n\t"
        "	ldrh r0, [r2, #0x14]\n\t"
        "	subs r0, r0, r4\n\t"
        "	strh r0, [r2, #0x14]\n\t"
        "	ldrh r0, [r2, #0x16]\n\t"
        "	subs r0, r0, r1\n\t"
        "	strh r0, [r2, #0x16]\n\t"
        "_0808E5CE:\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	cmp r3, #0xf\n\t"
        "	bls _0808E59A\n\t"
        "_0808E5D8:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808E5E0: .4byte gCamera\n\t"
        "_0808E5E4: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}

u8 GetObjectEventIdByPosition(u16 x, u16 y, u8 elevation)
{
    u8 i;
    u8 zCoordMatch;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].currentCoords.x == x && gObjectEvents[i].currentCoords.y == y)
        {
            zCoordMatch = EventObjectDoesZCoordMatch(&gObjectEvents[i], elevation);
            if (zCoordMatch)
                return i;
        }
    }
    return OBJECT_EVENTS_COUNT;
}

bool8 EventObjectDoesZCoordMatch(struct ObjectEvent *objectEvent, u8 elevation)
{
    if (objectEvent->currentElevation != ELEVATION_TRANSITION && elevation != ELEVATION_TRANSITION && objectEvent->currentElevation != elevation)
        return FALSE;

    return TRUE;
}

void UpdateObjectEventsForCameraUpdate(s16 x, s16 y)
{
    UpdateEventObjectCoordsForCameraUpdate();
    TrySpawnObjectEvents(x, y);
    RemoveEventObjectsOutsideView();
}

u8 AddCameraObject(u8 followSpriteId)
{
    u8 spriteId;

    spriteId = CreateSprite(&gUnknown_846FA28, 0, 0, 4);
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].sCamera_FollowSpriteId = followSpriteId;
    return spriteId;
}

void ObjectCB_CameraObject(struct Sprite *sprite)
{
    void (*callbacks[3])(struct Sprite *);

    memcpy(callbacks, gUnknown_846FA40, sizeof callbacks);
    callbacks[sprite->sCamera_State](sprite);
}

void CameraObject_0(struct Sprite *sprite)
{
    sprite->x = gSprites[sprite->sCamera_FollowSpriteId].x;
    sprite->y = gSprites[sprite->sCamera_FollowSpriteId].y;
    sprite->invisible = TRUE;
    sprite->sCamera_State = CAMERA_STATE_MOVE;
    CameraObject_1(sprite);
}

void CameraObject_1(struct Sprite *sprite)
{
    s16 x = gSprites[sprite->sCamera_FollowSpriteId].x;
    s16 y = gSprites[sprite->sCamera_FollowSpriteId].y;

    sprite->sCamera_MoveX = x - sprite->x;
    sprite->sCamera_MoveY = y - sprite->y;
    sprite->x = x;
    sprite->y = y;
}

void CameraObject_2(struct Sprite *sprite)
{
    sprite->x = gSprites[sprite->sCamera_FollowSpriteId].x;
    sprite->y = gSprites[sprite->sCamera_FollowSpriteId].y;
    sprite->sCamera_MoveX = 0;
    sprite->sCamera_MoveY = 0;
}

__attribute__((naked)) struct Sprite *FindCameraObject(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	movs r3, #0\n\t"
        "	ldr r4, _0808E7E0\n\t"
        "	adds r5, r4, #0\n\t"
        "	adds r5, #0x1c\n\t"
        "_0808E7BE:\n\t"
        "	lsls r0, r3, #4\n\t"
        "	adds r0, r0, r3\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r2, r1, r4\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808E7E8\n\t"
        "	adds r0, r1, r5\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldr r0, _0808E7E4\n\t"
        "	cmp r1, r0\n\t"
        "	bne _0808E7E8\n\t"
        "	adds r0, r2, #0\n\t"
        "	b _0808E7F4\n\t"
        "	.align 2, 0\n\t"
        "_0808E7E0: .4byte gSprites\n\t"
        "_0808E7E4: .4byte ObjectCB_CameraObject + 1\n\t"
        "_0808E7E8:\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	cmp r3, #0x3f\n\t"
        "	bls _0808E7BE\n\t"
        "	movs r0, #0\n\t"
        "_0808E7F4:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void CameraObjectReset(void)
{
    struct Sprite *camera = FindCameraObject();
    if (camera != NULL)
    {
        camera->data[1] = 0; // CAMERA_STATE_INIT
        camera->callback(camera);
    }
}

void CameraObjectSetFollowedSpriteId(u8 spriteId)
{
    struct Sprite *camera = FindCameraObject();
    if (camera != NULL)
    {
        camera->sCamera_FollowSpriteId = spriteId;
        CameraObjectReset();
    }
}

u8 CameraObjectGetFollowedSpriteId(void)
{
    struct Sprite *camera = FindCameraObject();
    if (camera == NULL)
        return MAX_SPRITES;

    return camera->sCamera_FollowSpriteId;
}

void CameraObjectReset2(void)
{
    FindCameraObject()->sTypeFuncId = 2;
}

__attribute__((naked)) void CopySprite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	mov ip, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	mov r8, r1\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r6, r2, #0x10\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r7, r3, #0x18\n\t"
        "	movs r5, #0\n\t"
        "	ldr r1, _0808E8A4\n\t"
        "_0808E876:\n\t"
        "	lsls r0, r5, #4\n\t"
        "	adds r0, r0, r5\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r4, r0, r1\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808E8A8\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, ip\n\t"
        "	movs r2, #0x44\n\t"
        "	bl memcpy\n\t"
        "	mov r0, r8\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	strh r6, [r4, #0x22]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x43\n\t"
        "	strb r7, [r0]\n\t"
        "	b _0808E8B2\n\t"
        "	.align 2, 0\n\t"
        "_0808E8A4: .4byte gSprites\n\t"
        "_0808E8A8:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #0x3f\n\t"
        "	bls _0808E876\n\t"
        "_0808E8B2:\n\t"
        "	adds r0, r5, #0\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 CreateCopySpriteAt(struct Sprite *sprite, s16 x, s16 y, u8 subpriority)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	mov ip, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	mov r8, r1\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r6, r2, #0x10\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r7, r3, #0x18\n\t"
        "	movs r5, #0x3f\n\t"
        "	ldr r3, _0808E914\n\t"
        "	movs r2, #1\n\t"
        "	rsbs r2, r2, #0\n\t"
        "_0808E8DE:\n\t"
        "	lsls r0, r5, #0x10\n\t"
        "	asrs r1, r0, #0x10\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r4, r0, r3\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808E918\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, ip\n\t"
        "	movs r2, #0x44\n\t"
        "	bl memcpy\n\t"
        "	mov r0, r8\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	strh r6, [r4, #0x22]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x43\n\t"
        "	strb r7, [r0]\n\t"
        "	lsls r0, r5, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	b _0808E926\n\t"
        "	.align 2, 0\n\t"
        "_0808E914: .4byte gSprites\n\t"
        "_0808E918:\n\t"
        "	subs r0, r1, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, r2\n\t"
        "	bgt _0808E8DE\n\t"
        "	movs r0, #0x40\n\t"
        "_0808E926:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}


void SetEventObjectDirection(struct ObjectEvent *objectEvent, u8 direction)
{
    s8 d2;
    objectEvent->previousMovementDirection = objectEvent->facingDirection;
    if (!objectEvent->facingDirectionLocked)
    {
        d2 = direction;
        objectEvent->facingDirection = d2;
    }
    objectEvent->movementDirection = direction;
}

const u8 *GetObjectEventScriptPointerByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    return GetEventObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup)->script;
}

__attribute__((naked)) void GetEventObjectScriptPointerByEventObjectId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _0808E9AC\n\t"
        "	lsls r2, r0, #3\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r1\n\t"
        "	ldrb r0, [r2, #8]\n\t"
        "	ldrb r1, [r2, #9]\n\t"
        "	ldrb r2, [r2, #0xa]\n\t"
        "	bl GetObjectEventScriptPointerByLocalIdAndMap\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808E9AC: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}

u16 GetObjectEventFlagIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    return GetEventObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup)->flagId;
}

__attribute__((naked)) void GetEventObjectFlagIdByEventObjectId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _0808E9EC\n\t"
        "	lsls r2, r0, #3\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r1\n\t"
        "	ldrb r0, [r2, #8]\n\t"
        "	ldrb r1, [r2, #9]\n\t"
        "	ldrb r2, [r2, #0xa]\n\t"
        "	bl GetObjectEventFlagIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808E9EC: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808E9F0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808EA24\n\t"
        "	ldr r2, _0808EA20\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #7]\n\t"
        "	b _0808EA26\n\t"
        "	.align 2, 0\n\t"
        "_0808EA20: .4byte gObjectEvents\n\t"
        "_0808EA24:\n\t"
        "	movs r0, #0xff\n\t"
        "_0808EA26:\n\t"
        "	add sp, #4\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

u8 GetObjectTrainerTypeByObjectEventId(u8 objectEventId)
{
    return gObjectEvents[objectEventId].trainerType;
}

__attribute__((naked)) void sub_0808EA44(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808EA78\n\t"
        "	ldr r2, _0808EA74\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #0x1d]\n\t"
        "	b _0808EA7A\n\t"
        "	.align 2, 0\n\t"
        "_0808EA74: .4byte gObjectEvents\n\t"
        "_0808EA78:\n\t"
        "	movs r0, #0xff\n\t"
        "_0808EA7A:\n\t"
        "	add sp, #4\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

u8 GetObjectEventBerryTreeId(u8 objectEventId)
{
    return gObjectEvents[objectEventId].trainerRange_berryTreeId;
}

__attribute__((naked)) struct ObjectEventTemplate *GetEventObjectTemplateByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r3, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r0, _0808EAC8\n\t"
        "	ldr r1, [r0]\n\t"
        "	movs r0, #5\n\t"
        "	ldrsb r0, [r1, r0]\n\t"
        "	cmp r0, r3\n\t"
        "	bne _0808EAD0\n\t"
        "	movs r0, #4\n\t"
        "	ldrsb r0, [r1, r0]\n\t"
        "	cmp r0, r2\n\t"
        "	bne _0808EAD0\n\t"
        "	movs r0, #0xc7\n\t"
        "	lsls r0, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, _0808EACC\n\t"
        "	ldr r0, [r0, #4]\n\t"
        "	b _0808EADC\n\t"
        "	.align 2, 0\n\t"
        "_0808EAC8: .4byte gSaveBlock1Ptr\n\t"
        "_0808EACC: .4byte gMapHeader\n\t"
        "_0808EAD0:\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r1, r3, #0\n\t"
        "	bl Overworld_GetMapHeaderByGroupAndId\n\t"
        "	ldr r0, [r0, #4]\n\t"
        "	ldr r1, [r0, #4]\n\t"
        "_0808EADC:\n\t"
        "	ldrb r2, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl FindEventObjectTemplateByLocalId\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void FindEventObjectTemplateByLocalId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	cmp r1, r2\n\t"
        "	bhs _0808EB1A\n\t"
        "_0808EAFE:\n\t"
        "	lsls r0, r1, #1\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #3\n\t"
        "	adds r3, r0, r5\n\t"
        "	ldrb r0, [r3]\n\t"
        "	cmp r0, r4\n\t"
        "	bne _0808EB10\n\t"
        "	adds r0, r3, #0\n\t"
        "	b _0808EB1C\n\t"
        "_0808EB10:\n\t"
        "	adds r0, r1, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, r2\n\t"
        "	blo _0808EAFE\n\t"
        "_0808EB1A:\n\t"
        "	movs r0, #0\n\t"
        "_0808EB1C:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

struct ObjectEventTemplate *GetBaseTemplateForObjectEvent(const struct ObjectEvent *objectEvent)
{
    int i;

    if (objectEvent->mapNum != gSaveBlock1Ptr->location.mapNum
     || objectEvent->mapGroup != gSaveBlock1Ptr->location.mapGroup)
        return NULL;

    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        if (objectEvent->localId == gSaveBlock1Ptr->objectEventTemplates[i].localId)
            return &gSaveBlock1Ptr->objectEventTemplates[i];
    }
    return NULL;
}


__attribute__((naked)) void OverrideTemplateCoordsForObjectEvent(const struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl GetBaseTemplateForObjectEvent\n\t"
        "	adds r1, r0, #0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0808EB92\n\t"
        "	ldrh r0, [r4, #0x10]\n\t"
        "	subs r0, #7\n\t"
        "	strh r0, [r1, #4]\n\t"
        "	ldrh r0, [r4, #0x12]\n\t"
        "	subs r0, #7\n\t"
        "	strh r0, [r1, #6]\n\t"
        "_0808EB92:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}
void OverrideObjectEventTemplateScript(const struct ObjectEvent *objectEvent, const u8 *script)
{
    struct ObjectEventTemplate *objectEventTemplate;

    objectEventTemplate = GetBaseTemplateForObjectEvent(objectEvent);
    if (objectEventTemplate)
        objectEventTemplate->script = script;
}




void TryOverrideTemplateCoordsForObjectEvent(const struct ObjectEvent *objectEvent, u8 movementType)
{
    struct ObjectEventTemplate *objectEventTemplate;

    objectEventTemplate = GetBaseTemplateForObjectEvent(objectEvent);
    if (objectEventTemplate != NULL)
        objectEventTemplate->movementType = movementType;
}

__attribute__((naked)) void TryOverrideEventObjectTemplateCoords(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808EBF2\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808EBF8\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl OverrideTemplateCoordsForObjectEvent\n\t"
        "_0808EBF2:\n\t"
        "	add sp, #4\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808EBF8: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void OverrideSecretBaseDecorationSpriteScript(u8 localId, u8 mapNum, u8 mapGroup, u8 decorationCategory)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r4, r3, #0x18\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808EC58\n\t"
        "	cmp r4, #6\n\t"
        "	beq _0808EC26\n\t"
        "	cmp r4, #7\n\t"
        "	beq _0808EC44\n\t"
        "	b _0808EC58\n\t"
        "_0808EC26:\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808EC3C\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0808EC40\n\t"
        "	bl OverrideObjectEventTemplateScript\n\t"
        "	b _0808EC58\n\t"
        "	.align 2, 0\n\t"
        "_0808EC3C: .4byte gObjectEvents\n\t"
        "_0808EC40: .4byte SecretBase_EventScript_DollInteract\n\t"
        "_0808EC44:\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808EC60\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, _0808EC64\n\t"
        "	bl OverrideObjectEventTemplateScript\n\t"
        "_0808EC58:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808EC60: .4byte gObjectEvents\n\t"
        "_0808EC64: .4byte SecretBase_EventScript_CushionInteract\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void InitEventObjectPalettes(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl FreeAndReserveObjectSpritePalettes\n\t"
        "	ldr r1, _0808ECA0\n\t"
        "	ldr r2, _0808ECA4\n\t"
        "	adds r0, r2, #0\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r2, _0808ECA8\n\t"
        "	strb r4, [r2]\n\t"
        "	cmp r4, #1\n\t"
        "	bne _0808ECB4\n\t"
        "	ldr r1, _0808ECAC\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #6\n\t"
        "	bl PatchObjectPaletteRange\n\t"
        "	ldr r1, _0808ECB0\n\t"
        "	movs r0, #8\n\t"
        "	strb r0, [r1]\n\t"
        "	b _0808ECC6\n\t"
        "	.align 2, 0\n\t"
        "_0808ECA0: .4byte gUnknown_2037256\n\t"
        "_0808ECA4: .4byte 0x000011FF\n\t"
        "_0808ECA8: .4byte gUnknown_2037254\n\t"
        "_0808ECAC: .4byte gUnknown_84E428C\n\t"
        "_0808ECB0: .4byte gReservedSpritePaletteCount\n\t"
        "_0808ECB4:\n\t"
        "	ldr r0, _0808ECCC\n\t"
        "	ldrb r1, [r2]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r0, [r1]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0xa\n\t"
        "	bl PatchObjectPaletteRange\n\t"
        "_0808ECC6:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808ECCC: .4byte gUnknown_84E428C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u16 GetObjectPaletteTag(u8 palSlot)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #9\n\t"
        "	bhi _0808ED0C\n\t"
        "	ldr r1, _0808ECEC\n\t"
        "	ldr r0, _0808ECF0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	lsls r0, r2, #1\n\t"
        "	b _0808ED00\n\t"
        "	.align 2, 0\n\t"
        "_0808ECEC: .4byte gUnknown_84E428C\n\t"
        "_0808ECF0: .4byte gUnknown_2037254\n\t"
        "_0808ECF4:\n\t"
        "	adds r1, r4, #4\n\t"
        "	adds r1, r2, r1\n\t"
        "	ldr r0, _0808ED08\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, [r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "_0808ED00:\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r0, [r0]\n\t"
        "	b _0808ED3E\n\t"
        "	.align 2, 0\n\t"
        "_0808ED08: .4byte gUnknown_2037254\n\t"
        "_0808ED0C:\n\t"
        "	movs r3, #0\n\t"
        "	ldr r0, _0808ED44\n\t"
        "	ldrh r1, [r0]\n\t"
        "	ldr r2, _0808ED48\n\t"
        "	adds r4, r0, #0\n\t"
        "	cmp r1, r2\n\t"
        "	beq _0808ED3C\n\t"
        "	adds r6, r4, #0\n\t"
        "	ldr r0, _0808ED4C\n\t"
        "	ldrh r1, [r0]\n\t"
        "	adds r5, r2, #0\n\t"
        "_0808ED22:\n\t"
        "	lsls r2, r3, #3\n\t"
        "	adds r0, r2, r6\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r1\n\t"
        "	beq _0808ECF4\n\t"
        "	adds r0, r3, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r3, r0, #0x18\n\t"
        "	lsls r0, r3, #3\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrh r0, [r0]\n\t"
        "	cmp r0, r5\n\t"
        "	bne _0808ED22\n\t"
        "_0808ED3C:\n\t"
        "	ldr r0, _0808ED48\n\t"
        "_0808ED3E:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808ED44: .4byte sSpecialObjectReflectionPaletteSets\n\t"
        "_0808ED48: .4byte 0x000011FF\n\t"
        "_0808ED4C: .4byte gUnknown_2037256\n\t"
        ".syntax divided\n\t"
    );
}

void MovementType_None(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_None_callback);
}


u8 MovementType_None_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return FALSE;
}

void MovementType_WanderAround(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_CopyPlayerInGrass_callback);
}

u8 MovementType_CopyPlayerInGrass_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WanderAround[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_WanderAround_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_WanderAround_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_WanderAround_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808EE30\n\t"
        "	ldr r5, _0808EE2C\n\t"
        "	bl Random\n\t"
        "	movs r4, #3\n\t"
        "	adds r1, r4, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r5\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	strh r4, [r6, #0x30]\n\t"
        "	movs r0, #1\n\t"
        "	b _0808EE32\n\t"
        "	.align 2, 0\n\t"
        "_0808EE2C: .4byte gUnknown_84E5B30\n\t"
        "_0808EE30:\n\t"
        "	movs r0, #0\n\t"
        "_0808EE32:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_WanderAround_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 delayEnded = WaitForMovementDelay(sprite);

    if (delayEnded)
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_WanderAround_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    u8 chosenDirection;

    memcpy(directions, gStandardDirections, sizeof directions);
    chosenDirection = directions[Random() & 3];
    SetEventObjectDirection(objectEvent, chosenDirection);
    sprite->sTypeFuncId = 5;
    if (GetCollisionInDirection(objectEvent, chosenDirection))
        sprite->sTypeFuncId = 1;

    return TRUE;
}

bool8 MovementType_WanderAround_Step5(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, sub_08092CF8(objectEvent->movementDirection));
    objectEvent->singleMovementActive = TRUE;
    sprite->sTypeFuncId = 6;
    return TRUE;
}

bool8 MovementType_WanderAround_Step6(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 1;
    }
    return FALSE;
}

__attribute__((naked)) bool8 EventObjectIsTrainerAndCloseToPlayer(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r5, r0, #0\n\t"
        "	movs r0, #0x80\n\t"
        "	bl TestPlayerAvatarFlags\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808EF68\n\t"
        "	ldrb r0, [r5, #7]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _0808EF18\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0808EF68\n\t"
        "_0808EF18:\n\t"
        "	mov r7, sp\n\t"
        "	adds r7, #2\n\t"
        "	mov r0, sp\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl PlayerGetDestCoords\n\t"
        "	ldrh r2, [r5, #0x10]\n\t"
        "	ldrh r4, [r5, #0x12]\n\t"
        "	ldrb r1, [r5, #0x1d]\n\t"
        "	subs r3, r2, r1\n\t"
        "	subs r0, r4, r1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r5, r0, #0x10\n\t"
        "	adds r2, r1, r2\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r2, r2, #0x10\n\t"
        "	adds r1, r1, r4\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r6, r1, #0x10\n\t"
        "	mov r0, sp\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	asrs r3, r3, #0x10\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r4, [r0, r1]\n\t"
        "	cmp r3, r4\n\t"
        "	bgt _0808EF68\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, r4\n\t"
        "	blt _0808EF68\n\t"
        "	lsls r0, r5, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r7, r2]\n\t"
        "	cmp r0, r1\n\t"
        "	bgt _0808EF68\n\t"
        "	lsls r0, r6, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, r1\n\t"
        "	bge _0808EF6C\n\t"
        "_0808EF68:\n\t"
        "	movs r0, #0\n\t"
        "	b _0808EF6E\n\t"
        "_0808EF6C:\n\t"
        "	movs r0, #1\n\t"
        "_0808EF6E:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

u8 GetVectorDirection(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    if (absdx > absdy)
    {
        direction = DIR_EAST;
        if (dx < 0)
            direction = DIR_WEST;
    }
    else
    {
        direction = DIR_SOUTH;
        if (dy < 0)
            direction = DIR_NORTH;
    }
    return direction;
}


u8 GetLimitedVectorDirection_SouthNorth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = DIR_SOUTH;
    if (dy < 0)
        direction = DIR_NORTH;
    return direction;
}



u8 GetLimitedVectorDirection_WestEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = DIR_EAST;
    if (dx < 0)
        direction = DIR_WEST;
    return direction;
}


u8 GetLimitedVectorDirection_WestNorth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_EAST)
            direction = DIR_NORTH;
    }
    else if (direction == DIR_EAST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_SOUTH)
            direction = DIR_NORTH;
    }
    return direction;
}

u8 GetLimitedVectorDirection_EastNorth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_WEST)
            direction = DIR_NORTH;
    }
    else if (direction == DIR_WEST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_SOUTH)
            direction = DIR_NORTH;
    }
    return direction;
}

u8 GetLimitedVectorDirection_WestSouth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_EAST)
            direction = DIR_SOUTH;
    }
    else if (direction == DIR_EAST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_NORTH)
            direction = DIR_SOUTH;
    }
    return direction;
}

u8 GetLimitedVectorDirection_EastSouth(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
    {
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
        if (direction == DIR_WEST)
            direction = DIR_SOUTH;
    }
    else if (direction == DIR_WEST)
    {
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
        if (direction == DIR_NORTH)
            direction = DIR_SOUTH;
    }
    return direction;
}

u8 GetLimitedVectorDirection_SouthNorthWest(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_EAST)
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
    return direction;
}

u8 GetLimitedVectorDirection_SouthNorthEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_WEST)
        direction = GetLimitedVectorDirection_SouthNorth(dx, dy, absdx, absdy);
    return direction;
}

u8 GetLimitedVectorDirection_NorthWestEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_SOUTH)
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
    return direction;
}

u8 GetLimitedVectorDirection_SouthWestEast(s16 dx, s16 dy, s16 absdx, s16 absdy)
{
    u8 direction;

    direction = GetVectorDirection(dx, dy, absdx, absdy);
    if (direction == DIR_NORTH)
        direction = GetLimitedVectorDirection_WestEast(dx, dy, absdx, absdy);
    return direction;
}

u8 TryGetTrainerEncounterDirection(struct ObjectEvent *objectEvent, u8 movementType)
{
    s16 dx, dy;
    s16 absdx, absdy;

    if (!EventObjectIsTrainerAndCloseToPlayer(objectEvent))
        return DIR_NONE;

    PlayerGetDestCoords(&dx, &dy);
    dx -= objectEvent->currentCoords.x;
    dy -= objectEvent->currentCoords.y;
    absdx = dx;
    absdy = dy;

    if (absdx < 0)
        absdx = -absdx;
    if (absdy < 0)
        absdy = -absdy;

    return gGetVectorDirectionFuncs[movementType](dx, dy, absdx, absdy);
}

void MovementType_LookAround(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_CopyPlayer_callback);
}

u8 MovementType_CopyPlayer_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_LookAround[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_LookAround_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_LookAround_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_LookAround_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808F36E\n\t"
        "	ldr r4, _0808F378\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_0808F36E:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808F378: .4byte gUnknown_84E5B30\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_LookAround_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_LookAround_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gStandardDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_ANY);
    if (direction == DIR_NONE)
        direction = directions[Random() & 3];

    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_WanderUpAndDown(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceDirection_callback);
}

u8 MovementType_FaceDirection_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WanderUpAndDown[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_WanderUpAndDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_WanderUpAndDown_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808F4AC\n\t"
        "	ldr r5, _0808F4A8\n\t"
        "	bl Random\n\t"
        "	movs r4, #3\n\t"
        "	adds r1, r4, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r5\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	strh r4, [r6, #0x30]\n\t"
        "	movs r0, #1\n\t"
        "	b _0808F4AE\n\t"
        "	.align 2, 0\n\t"
        "_0808F4A8: .4byte gUnknown_84E5B30\n\t"
        "_0808F4AC:\n\t"
        "	movs r0, #0\n\t"
        "_0808F4AE:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_WanderUpAndDown_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 delayEnded = WaitForMovementDelay(sprite);

    if (delayEnded)
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

__attribute__((naked)) bool8 MovementType_WanderUpAndDown_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r6, r1, #0\n\t"
        "	ldr r1, _0808F51C\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #2\n\t"
        "	bl memcpy\n\t"
        "	bl Random\n\t"
        "	movs r7, #1\n\t"
        "	adds r1, r7, #0\n\t"
        "	ands r1, r0\n\t"
        "	mov r2, sp\n\t"
        "	adds r0, r2, r1\n\t"
        "	ldrb r4, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl SetEventObjectDirection\n\t"
        "	movs r0, #5\n\t"
        "	strh r0, [r6, #0x30]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GetCollisionInDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808F512\n\t"
        "	strh r7, [r6, #0x30]\n\t"
        "_0808F512:\n\t"
        "	movs r0, #1\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808F51C: .4byte gUnknown_84E5BC4\n\t"
        ".syntax divided\n\t"
    );
}


bool8 MovementType_WanderUpAndDown_Step5(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, sub_08092CF8(objectEvent->movementDirection));
    objectEvent->singleMovementActive = TRUE;
    sprite->sTypeFuncId = 6;
    return TRUE;
}

bool8 MovementType_WanderUpAndDown_Step6(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 1;
    }
    return FALSE;
}

void MovementType_WanderLeftAndRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceDownAndLeft_callback);
}

u8 MovementType_FaceDownAndLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WanderLeftAndRight[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_WanderLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_WanderLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808F630\n\t"
        "	ldr r5, _0808F62C\n\t"
        "	bl Random\n\t"
        "	movs r4, #3\n\t"
        "	adds r1, r4, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r5\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	strh r4, [r6, #0x30]\n\t"
        "	movs r0, #1\n\t"
        "	b _0808F632\n\t"
        "	.align 2, 0\n\t"
        "_0808F62C: .4byte gUnknown_84E5B30\n\t"
        "_0808F630:\n\t"
        "	movs r0, #0\n\t"
        "_0808F632:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_WanderLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 delayEnded = WaitForMovementDelay(sprite);

    if (delayEnded)
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

__attribute__((naked)) bool8 MovementType_WanderLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r6, r1, #0\n\t"
        "	ldr r1, _0808F6A0\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #2\n\t"
        "	bl memcpy\n\t"
        "	bl Random\n\t"
        "	movs r7, #1\n\t"
        "	adds r1, r7, #0\n\t"
        "	ands r1, r0\n\t"
        "	mov r2, sp\n\t"
        "	adds r0, r2, r1\n\t"
        "	ldrb r4, [r0]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl SetEventObjectDirection\n\t"
        "	movs r0, #5\n\t"
        "	strh r0, [r6, #0x30]\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GetCollisionInDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808F696\n\t"
        "	strh r7, [r6, #0x30]\n\t"
        "_0808F696:\n\t"
        "	movs r0, #1\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808F6A0: .4byte gUnknown_84E5BE4\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_WanderLeftAndRight_Step5(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, sub_08092CF8(objectEvent->movementDirection));
    objectEvent->singleMovementActive = TRUE;
    sprite->sTypeFuncId = 6;
    return TRUE;
}

bool8 MovementType_WanderLeftAndRight_Step6(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 1;
    }
    return FALSE;
}

void MovementType_FaceDirection(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceDownAndRight_callback);
}

u8 MovementType_FaceDownAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceDirection[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_FaceDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceDirection_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        sprite->sTypeFuncId = 2;
        return TRUE;
    }
    return FALSE;
}


bool8 MovementType_Invisible_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->singleMovementActive = FALSE;
    return FALSE;
}


__attribute__((naked)) void MovementType_BerryTreeGrowth(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r0, #0x2e\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808F7D8\n\t"
        "	adds r5, r0, r1\n\t"
        "	ldrh r1, [r4, #0x3c]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808F7C8\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl get_berry_tree_graphics\n\t"
        "	ldrh r1, [r4, #0x3c]\n\t"
        "	movs r0, #1\n\t"
        "	orrs r0, r1\n\t"
        "	strh r0, [r4, #0x3c]\n\t"
        "_0808F7C8:\n\t"
        "	ldr r2, _0808F7DC\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl UpdateEventObjectCurrentMovement\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808F7D8: .4byte gObjectEvents\n\t"
        "_0808F7DC: .4byte MovementType_FaceDownAndUp_callback + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 MovementType_FaceDownAndUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r3, _0808F7FC\n\t"
        "	movs r4, #0x30\n\t"
        "	ldrsh r2, [r1, r4]\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldr r2, [r2]\n\t"
        "	bl _call_via_r2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808F7FC: .4byte gUnknown_84E5BF4\n\t"
        ".syntax divided\n\t"
    );
}


bool8 MovementType_BerryTreeGrowth_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 berryStage;
    ClearEventObjectMovement(objectEvent, sprite);
    objectEvent->invisible = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(objectEvent->trainerRange_berryTreeId);
    if (berryStage == BERRY_STAGE_NO_BERRY)
    {
        if (!(sprite->sBerryTreeFlags & BERRY_FLAG_JUST_PICKED) && sprite->animNum == BERRY_STAGE_FLOWERING)
        {
            gFieldEffectArguments[0] = objectEvent->currentCoords.x;
            gFieldEffectArguments[1] = objectEvent->currentCoords.y;
            gFieldEffectArguments[2] = sprite->subpriority - 1;
            gFieldEffectArguments[3] = sprite->oam.priority;
            FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
            sprite->animNum = berryStage;
        }
        return FALSE;
    }
    objectEvent->invisible = FALSE;
    sprite->invisible = FALSE;
    berryStage--;
    if (sprite->animNum != berryStage)
    {
        sprite->sTypeFuncId = BERRYTREEFUNC_SPARKLE_START;
        return TRUE;
    }
    get_berry_tree_graphics(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, MOVEMENT_ACTION_START_ANIM_IN_DIRECTION);
    sprite->sTypeFuncId = BERRYTREEFUNC_MOVE;
    return TRUE;
}

bool8 MovementType_BerryTreeGrowth_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        sprite->sTypeFuncId = BERRYTREEFUNC_NORMAL;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_BerryTreeGrowth_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->singleMovementActive = TRUE;
    sprite->sTypeFuncId = BERRYTREEFUNC_SPARKLE;
    sprite->sTimer = 0;
    sprite->sBerryTreeFlags |= BERRY_FLAG_SPARKLING;
    gFieldEffectArguments[0] = objectEvent->currentCoords.x;
    gFieldEffectArguments[1] = objectEvent->currentCoords.y;
    gFieldEffectArguments[2] = sprite->subpriority - 1;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_BERRY_TREE_GROWTH_SPARKLE);
    return TRUE;
}

bool8 MovementType_BerryTreeGrowth_Sparkle(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->sTimer++;
    objectEvent->invisible = (sprite->sTimer & 2) >> 1;
    sprite->animPaused = TRUE;
    if (sprite->sTimer > 64)
    {
        get_berry_tree_graphics(objectEvent, sprite);
        sprite->sTypeFuncId = BERRYTREEFUNC_SPARKLE_END;
        sprite->sTimer = 0;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_BerryTreeGrowth_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->sTimer++;
    objectEvent->invisible = (sprite->sTimer & 2) >> 1;
    sprite->animPaused = TRUE;
    if (sprite->sTimer > 64)
    {
        sprite->sTypeFuncId = BERRYTREEFUNC_NORMAL;
        sprite->sBerryTreeFlags &= ~BERRY_FLAG_SPARKLING;
        return TRUE;
    }
    return FALSE;
}

#undef sTimer
#undef sBerryTreeFlags

void MovementType_FaceDownAndUp(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceDownRightAndLeft_callback);
}

u8 MovementType_FaceDownRightAndLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceDownAndUp[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_FaceDownAndUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceDownAndUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_FaceDownAndUp_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808FA7A\n\t"
        "	ldr r4, _0808FA84\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_0808FA7A:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808FA84: .4byte gUnknown_84E5B30\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_FaceDownAndUp_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndUp_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndDownDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_SOUTH);
    if (direction == DIR_NONE)
        direction = directions[Random() & 1];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_FaceLeftAndRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceDownUpAndLeft_callback);
}

u8 MovementType_FaceDownUpAndLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceLeftAndRight[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_FaceLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_FaceLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808FBBA\n\t"
        "	ldr r4, _0808FBC4\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_0808FBBA:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808FBC4: .4byte gUnknown_84E5B30\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_FaceLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}


bool8 MovementType_FaceLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gLeftAndRightDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_EAST_WEST);
    if (direction == DIR_NONE)
        direction = directions[Random() & 1];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_FaceUpAndLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceDownUpAndRight_callback);
}

u8 MovementType_FaceDownUpAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceUpAndLeft[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_FaceUpAndLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceUpAndLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_FaceUpAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808FCFA\n\t"
        "	ldr r4, _0808FD04\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_0808FCFA:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808FD04: .4byte gUnknown_84E5B40\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_FaceUpAndLeft_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceUpAndLeft_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndLeftDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_WEST);
    if (direction == DIR_NONE)
        direction = directions[Random() & 1];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_FaceUpAndRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceLeftAndRight_callback);
}

u8 MovementType_FaceLeftAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceUpAndRight[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_FaceUpAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceUpAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_FaceUpAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808FE3A\n\t"
        "	ldr r4, _0808FE44\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_0808FE3A:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808FE44: .4byte gUnknown_84E5B40\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_FaceUpAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceUpAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndRightDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_EAST);
    if (direction == DIR_NONE)
        direction = directions[Random() & 1];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_FaceDownAndLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceUpAndLeft_callback);
}

u8 MovementType_FaceUpAndLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceDownAndLeft[sprite->sTypeFuncId](objectEvent, sprite);
}


bool8 MovementType_FaceDownAndLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceDownAndLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_FaceDownAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808FF7A\n\t"
        "	ldr r4, _0808FF84\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_0808FF7A:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808FF84: .4byte gUnknown_84E5B40\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_FaceDownAndLeft_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndLeft_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gDownAndLeftDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_SOUTH_WEST);
    if (direction == DIR_NONE)
        direction = directions[Random() & 1];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_FaceDownAndRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceUpAndRight_callback);
}

u8 MovementType_FaceUpAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceDownAndRight[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_FaceDownAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceDownAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_FaceDownAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080900BA\n\t"
        "	ldr r4, _080900C4\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_080900BA:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080900C4: .4byte gUnknown_84E5B40\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_FaceDownAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gDownAndRightDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_SOUTH_EAST);
    if (direction == DIR_NONE)
        direction = directions[Random() & 1];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_FaceDownUpAndLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceUpRightAndLeft_callback);
}

u8 MovementType_FaceUpRightAndLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceDownUpAndLeft[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_FaceDownUpAndLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceDownUpAndLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_FaceDownUpAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080901FA\n\t"
        "	ldr r4, _08090204\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_080901FA:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08090204: .4byte gUnknown_84E5B40\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_FaceDownUpAndLeft_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}


bool8 MovementType_FaceDownUpAndLeft_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gDownUpAndLeftDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_SOUTH_WEST);
    if (direction == DIR_NONE)
        direction = directions[Random() & 3];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_FaceDownUpAndRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_Hidden_Callback);
}

u8 MovementType_Hidden_Callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceDownUpAndRight[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_FaceDownUpAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceDownUpAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_FaceDownUpAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809033A\n\t"
        "	ldr r4, _08090344\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_0809033A:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08090344: .4byte gUnknown_84E5B40\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_FaceDownUpAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownUpAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gDownUpAndRightDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_SOUTH_EAST);
    if (direction == DIR_NONE)
        direction = directions[Random() & 3];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_FaceUpRightAndLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_FaceUpLeftAndRight_callback);
}

u8 MovementType_FaceUpLeftAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceUpLeftAndRight[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_FaceUpLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceUpLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_FaceUpLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809047A\n\t"
        "	ldr r4, _08090484\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_0809047A:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08090484: .4byte gUnknown_84E5B40\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_FaceUpLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceUpLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gUpLeftAndRightDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_NORTH_EAST_WEST);
    if (direction == DIR_NONE)
        direction = directions[Random() & 3];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_FaceDownRightAndLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_JogInPlace_callback);
}

u8 MovementType_JogInPlace_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_FaceDownLeftAndRight[sprite->sTypeFuncId](objectEvent, sprite);
}


bool8 MovementType_FaceDownLeftAndRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_FaceDownLeftAndRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_FaceDownLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080905BA\n\t"
        "	ldr r4, _080905C4\n\t"
        "	bl Random\n\t"
        "	movs r5, #3\n\t"
        "	adds r1, r5, #0\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r4\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r1, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl SetMovementDelay\n\t"
        "	ldrb r1, [r6]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	strh r5, [r7, #0x30]\n\t"
        "_080905BA:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080905C4: .4byte gUnknown_84E5B40\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_FaceDownLeftAndRight_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
    {
        sprite->sTypeFuncId = 4;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementType_FaceDownLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[4];
    memcpy(directions, gDownLeftAndRightDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_SOUTH_EAST_WEST);
    if (direction == DIR_NONE)
        direction = directions[Random() & 3];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_RotateCounterclockwise(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_LookAround_callback);
}

u8 MovementType_LookAround_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_RotateCounterclockwise[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_RotateCounterclockwise_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_RotateCounterclockwise_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, 48);
        sprite->sTypeFuncId = 2;
    }
    return FALSE;
}

bool8 MovementType_RotateCounterclockwise_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
        sprite->sTypeFuncId = 3;
    return FALSE;
}

bool8 MovementType_RotateCounterclockwise_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[5];
    memcpy(directions, gCounterclockwiseDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_ANY);
    if (direction == DIR_NONE)
        direction = directions[objectEvent->facingDirection];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 0;
    return TRUE;
}

void MovementType_RotateClockwise(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_RotateClockwise_callback);
}

u8 MovementType_RotateClockwise_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_RotateClockwise[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_RotateClockwise_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_RotateClockwise_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, 48);
        sprite->sTypeFuncId = 2;
    }
    return FALSE;
}

bool8 MovementType_RotateClockwise_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (WaitForMovementDelay(sprite) || EventObjectIsTrainerAndCloseToPlayer(objectEvent))
        sprite->sTypeFuncId = 3;
    return FALSE;
}

bool8 MovementType_RotateClockwise_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[5];
    memcpy(directions, gClockwiseDirections, sizeof directions);
    direction = TryGetTrainerEncounterDirection(objectEvent, RUNFOLLOW_ANY);
    if (direction == DIR_NONE)
        direction = directions[objectEvent->facingDirection];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 0;
    return TRUE;
}

void MovementType_WalkBackAndForth(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_RotateCounterclockwise_callback);
}


u8 MovementType_RotateCounterclockwise_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkBackAndForth[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_WalkBackAndForth_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_WalkBackAndForth_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;

    direction = gInitialMovementTypeFacingDirections[objectEvent->movementType];
    if (objectEvent->directionSequenceIndex)
        direction = GetOppositeDirection(direction);
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 2;
    return TRUE;
}

bool8 MovementType_WalkBackAndForth_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 collision;
    u8 movementActionId;

    if (objectEvent->directionSequenceIndex && objectEvent->initialCoords.x == objectEvent->currentCoords.x && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
    {
        objectEvent->directionSequenceIndex = 0;
        SetEventObjectDirection(objectEvent, GetOppositeDirection(objectEvent->movementDirection));
    }
    collision = GetCollisionInDirection(objectEvent, objectEvent->movementDirection);
    movementActionId = sub_08092CF8(objectEvent->movementDirection);
    if (collision == COLLISION_OUTSIDE_RANGE)
    {
        objectEvent->directionSequenceIndex++;
        SetEventObjectDirection(objectEvent, GetOppositeDirection(objectEvent->movementDirection));
        movementActionId = sub_08092CF8(objectEvent->movementDirection);
        collision = GetCollisionInDirection(objectEvent, objectEvent->movementDirection);
    }
    if (collision)
        movementActionId = sub_08092F08(objectEvent->facingDirection);
    ObjectEventSetSingleMovement(objectEvent, sprite, movementActionId);
    objectEvent->singleMovementActive = TRUE;
    sprite->sTypeFuncId = 3;
    return TRUE;
}

bool8 MovementType_WalkBackAndForth_Step3(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 1;
    }
    return FALSE;
}
bool8 MovementType_WalkSequence_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    sprite->sTypeFuncId = 1;
    return TRUE;
}



bool8 MoveNextDirectionInSequence(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 *route)
{
    u8 collision;
    u8 movementActionId;

    if (objectEvent->directionSequenceIndex == 3 && objectEvent->initialCoords.x == objectEvent->currentCoords.x && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 0;

    SetEventObjectDirection(objectEvent, route[objectEvent->directionSequenceIndex]);
    movementActionId = sub_08092CF8(objectEvent->movementDirection);
    collision = GetCollisionInDirection(objectEvent, objectEvent->movementDirection);
    if (collision == COLLISION_OUTSIDE_RANGE)
    {
        objectEvent->directionSequenceIndex++;
        SetEventObjectDirection(objectEvent, route[objectEvent->directionSequenceIndex]);
        movementActionId = sub_08092CF8(objectEvent->movementDirection);
        collision = GetCollisionInDirection(objectEvent, objectEvent->movementDirection);
    }

    if (collision)
        movementActionId = sub_08092F08(objectEvent->facingDirection);

    ObjectEventSetSingleMovement(objectEvent, sprite, movementActionId);
    objectEvent->singleMovementActive = TRUE;
    sprite->sTypeFuncId = 2;
    return TRUE;
}

bool8 MovementType_WalkSequence_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 1;
    }
    return FALSE;
}

void MovementType_WalkSequenceUpRightLeftDown(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, EventObjectCB2_BerryTree);
}

u8 EventObjectCB2_BerryTree(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceUpRightLeftDown[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceUpRightLeftDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gUpRightLeftDownDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceRightLeftDownUp(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_RunInPlace_callback);
}

u8 MovementType_RunInPlace_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceRightLeftDownUp[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceRightLeftDownUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gRightLeftDownUpDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 2;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceDownUpRightLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkBackAndForth_callback);
}

u8 MovementType_WalkBackAndForth_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceDownUpRightLeft[sprite->sTypeFuncId](objectEvent, sprite);
}


u8 MovementType_WalkSequenceDownUpRightLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gDownUpRightLeftDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 2;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceLeftDownUpRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkInPlace_callback);
}

u8 MovementType_WalkInPlace_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceLeftDownUpRight[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceLeftDownUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gLeftDownUpRightDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceUpLeftRightDown(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceDownLeftRightUp_callback);
}

u8 MovementType_WalkSequenceDownLeftRightUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceUpLeftRightDown[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceUpLeftRightDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gUpLeftRightDownDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceLeftRightDownUp(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceDownLeftUpRight_callback);
}

u8 MovementType_WalkSequenceDownLeftUpRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceLeftRightDownUp[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceLeftRightDownUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gLeftRightDownUpDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 2;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceDownUpLeftRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceDownRightLeftUp_callback);
}

u8 MovementType_WalkSequenceDownRightLeftUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceDownUpLeftRight[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceDownUpLeftRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gStandardDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 2;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceRightDownUpLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceDownRightUpLeft_callback);
}

u8 MovementType_WalkSequenceDownRightUpLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceRightDownUpLeft[sprite->sTypeFuncId](objectEvent, sprite);
}


u8 MovementType_WalkSequenceRightDownUpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gRightDownUpLeftDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceLeftUpDownRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceDownUpLeftRight_callback);
}

u8 MovementType_WalkSequenceDownUpLeftRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceLeftUpDownRight[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceLeftUpDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gLeftUpDownRightDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceUpDownRightLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceLeftDownRightUp_callback);
}

u8 MovementType_WalkSequenceLeftDownRightUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceUpDownRightLeft[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceUpDownRightLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gUpDownRightLeftDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 2;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceRightLeftUpDown(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceLeftRightDownUp_callback);
}

u8 MovementType_WalkSequenceLeftRightDownUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceRightLeftUpDown[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceRightLeftUpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gRightLeftUpDownDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 2;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceDownRightLeftUp(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceLeftUpDownRight_callback);
}

u8 MovementType_WalkSequenceLeftUpDownRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceDownRightLeftUp[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceDownRightLeftUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gDownRightLeftUpDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceRightUpDownLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceRightDownLeftUp_callback);
}

u8 MovementType_WalkSequenceRightDownLeftUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceRightUpDownLeft[sprite->sTypeFuncId](objectEvent, sprite);
}


u8 MovementType_WalkSequenceRightUpDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gRightUpDownLeftDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceUpDownLeftRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceRightLeftDownUp_callback);
}

u8 MovementType_WalkSequenceRightLeftDownUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceUpDownLeftRight[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceUpDownLeftRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gUpDownLeftRightDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 2;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceLeftRightUpDown(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceRightUpDownLeft_callback);
}

u8 MovementType_WalkSequenceRightUpDownLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceLeftRightUpDown[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceLeftRightUpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gLeftRightUpDownDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 1 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 2;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceDownLeftRightUp(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceUpDownLeftRight_callback);
}

u8 MovementType_WalkSequenceUpDownLeftRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceDownLeftRightUp[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceDownLeftRightUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gDownLeftRightUpDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceUpLeftDownRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceUpLeftDownRight_callback);
}

u8 MovementType_WalkSequenceUpLeftDownRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceUpLeftDownRight[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceUpLeftDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gUpLeftDownRightDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceDownRightUpLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSequenceUpRightDownLeft_callback);
}

u8 MovementType_WalkSequenceUpRightDownLeft_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceDownRightUpLeft[sprite->sTypeFuncId](objectEvent, sprite);
}


u8 MovementType_WalkSequenceDownRightUpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gDownRightUpLeftDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceLeftDownRightUp(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WalkSlowlyInPlace_callback);
}

u8 MovementType_WalkSlowlyInPlace_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceLeftDownRightUp[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceLeftDownRightUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gLeftDownRightUpDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceRightUpLeftDown(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_WanderLeftAndRight_callback);
}

u8 MovementType_WanderLeftAndRight_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceRightUpLeftDown[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceRightUpLeftDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gRightUpLeftDownDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceUpRightDownLeft(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, sub_080915BC);
}

u8 sub_080915BC(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceUpRightDownLeft[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceUpRightDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gUpRightDownLeftDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceDownLeftUpRight(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, sub_08091648);
}

u8 sub_08091648(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceDownLeftUpRight[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceDownLeftUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gDownLeftUpRightDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.y == objectEvent->currentCoords.y)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceLeftUpRightDown(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, GetGroundEffectFlags_TallGrassOnBeginStep);
}

u8 GetGroundEffectFlags_TallGrassOnBeginStep(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceLeftUpRightDown[sprite->sTypeFuncId](objectEvent, sprite);
}


u8 MovementType_WalkSequenceLeftUpRightDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gLeftUpRightDownDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_WalkSequenceRightDownLeftUp(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, sub_08091760);
}

u8 sub_08091760(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSequenceRightDownLeftUp[sprite->sTypeFuncId](objectEvent, sprite);
}

u8 MovementType_WalkSequenceRightDownLeftUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 directions[4];
    memcpy(directions, gRightDownLeftUpDirections, sizeof directions);
    if (objectEvent->directionSequenceIndex == 2 && objectEvent->initialCoords.x == objectEvent->currentCoords.x)
        objectEvent->directionSequenceIndex = 3;

    return MoveNextDirectionInSequence(objectEvent, sprite, directions);
}

void MovementType_CopyPlayer(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementAction_AcroPopWheelieMoveRight_Step0);
}

u8 MovementAction_AcroPopWheelieMoveRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_CopyPlayer[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_CopyPlayer_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    if (objectEvent->directionSequenceIndex == 0)
        objectEvent->directionSequenceIndex = GetPlayerFacingDirection();
    sprite->sTypeFuncId = 1;
    return TRUE;
}

__attribute__((naked)) bool8 MovementType_CopyPlayer_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	ldr r2, _08091854\n\t"
        "	ldr r3, _08091858\n\t"
        "	ldrb r1, [r3, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #0x1c]\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _08091850\n\t"
        "	ldrb r0, [r3, #3]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _0809185C\n\t"
        "_08091850:\n\t"
        "	movs r0, #0\n\t"
        "	b _08091884\n\t"
        "	.align 2, 0\n\t"
        "_08091854: .4byte gObjectEvents\n\t"
        "_08091858: .4byte gPlayerAvatar\n\t"
        "_0809185C:\n\t"
        "	ldr r5, _0809188C\n\t"
        "	bl PlayerGetCopyableMovement\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x16\n\t"
        "	adds r4, r4, r5\n\t"
        "	bl GetPlayerMovementDirection\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r4, [r4]\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	movs r3, #0\n\t"
        "	bl _call_via_r4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "_08091884:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0809188C: .4byte gUnknown_84E5EB8\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 MovementType_CopyPlayer_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl ObjectEventExecSingleMovementAction\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080918AE\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #3\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r4]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r5, #0x30]\n\t"
        "_080918AE:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 CopyablePlayerMovement_None(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    return 0;
}
bool8 CopyablePlayerMovement_FaceDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(state_to_direction(gInitialMovementTypeFacingDirections[objectEvent->movementType], objectEvent->directionSequenceIndex, playerDirection)));
    objectEvent->singleMovementActive = TRUE;
    sprite->sTypeFuncId = 2;
    return TRUE;
}

__attribute__((naked)) bool8 CopyablePlayerMovement_GoSpeed0(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	mov r8, r3\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r5, r2, #0x18\n\t"
        "	adds r6, r5, #0\n\t"
        "	bl ObjectEventIsFarawayIslandMew\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809196C\n\t"
        "	bl GetMewMoveDirection\n\t"
        "	adds r5, r0, #0\n\t"
        "	cmp r5, #0\n\t"
        "	bne _08091982\n\t"
        "	adds r5, r6, #0\n\t"
        "	ldr r1, _08091968\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x21\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl state_to_direction\n\t"
        "	adds r5, r0, #0\n\t"
        "	mov r3, sp\n\t"
        "	adds r3, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	mov r2, sp\n\t"
        "	bl ObjectEventMoveDestCoords\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "	b _080919F4\n\t"
        "	.align 2, 0\n\t"
        "_08091968: .4byte gUnknown_84DDA21\n\t"
        "_0809196C:\n\t"
        "	ldr r1, _08091A10\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x21\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl state_to_direction\n\t"
        "	adds r5, r0, #0\n\t"
        "_08091982:\n\t"
        "	mov r6, sp\n\t"
        "	adds r6, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	mov r2, sp\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl ObjectEventMoveDestCoords\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl sub_08092CF8\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r6, r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r3, r5, #0\n\t"
        "	bl GetCollisionAtCoords\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080919E0\n\t"
        "	mov r1, r8\n\t"
        "	cmp r1, #0\n\t"
        "	beq _080919F4\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r6, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080919F4\n\t"
        "_080919E0:\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "_080919F4:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r7, #0x30]\n\t"
        "	movs r0, #1\n\t"
        "	add sp, #4\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08091A10: .4byte gUnknown_84DDA21\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 CopyablePlayerMovement_GoSpeed1(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	mov r8, r3\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r6, r2, #0x18\n\t"
        "	ldr r1, _08091AC8\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x21\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl state_to_direction\n\t"
        "	adds r6, r0, #0\n\t"
        "	mov r5, sp\n\t"
        "	adds r5, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	mov r2, sp\n\t"
        "	adds r3, r5, #0\n\t"
        "	bl ObjectEventMoveDestCoords\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08092D24\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r5, r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl GetCollisionAtCoords\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091A9A\n\t"
        "	mov r1, r8\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08091AAE\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091AAE\n\t"
        "_08091A9A:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "_08091AAE:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r7, #0x30]\n\t"
        "	movs r0, #1\n\t"
        "	add sp, #4\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08091AC8: .4byte gUnknown_84DDA21\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 CopyablePlayerMovement_GoSpeed2(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	mov r8, r3\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r6, r2, #0x18\n\t"
        "	ldr r1, _08091B80\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x21\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl state_to_direction\n\t"
        "	adds r6, r0, #0\n\t"
        "	mov r5, sp\n\t"
        "	adds r5, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	mov r2, sp\n\t"
        "	adds r3, r5, #0\n\t"
        "	bl ObjectEventMoveDestCoords\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08092D7C\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r5, r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl GetCollisionAtCoords\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091B52\n\t"
        "	mov r1, r8\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08091B66\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091B66\n\t"
        "_08091B52:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "_08091B66:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r7, #0x30]\n\t"
        "	movs r0, #1\n\t"
        "	add sp, #4\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08091B80: .4byte gUnknown_84DDA21\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 CopyablePlayerMovement_Slide(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	mov r8, r3\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r6, r2, #0x18\n\t"
        "	ldr r1, _08091C38\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x21\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl state_to_direction\n\t"
        "	adds r6, r0, #0\n\t"
        "	mov r5, sp\n\t"
        "	adds r5, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	mov r2, sp\n\t"
        "	adds r3, r5, #0\n\t"
        "	bl ObjectEventMoveDestCoords\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08092DA8\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r5, r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl GetCollisionAtCoords\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091C0A\n\t"
        "	mov r1, r8\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08091C1E\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091C1E\n\t"
        "_08091C0A:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "_08091C1E:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r7, #0x30]\n\t"
        "	movs r0, #1\n\t"
        "	add sp, #4\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08091C38: .4byte gUnknown_84DDA21\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 cph_IM_DIFFERENT(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r1, _08091C80\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x21\n\t"
        "	ldrb r1, [r1]\n\t"
        "	bl state_to_direction\n\t"
        "	bl sub_08092E2C\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5, #0x30]\n\t"
        "	movs r0, #1\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08091C80: .4byte gUnknown_84DDA21\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 CopyablePlayerMovement_GoSpeed4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	mov r8, r3\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r6, r2, #0x18\n\t"
        "	ldr r1, _08091D38\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x21\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl state_to_direction\n\t"
        "	adds r6, r0, #0\n\t"
        "	mov r5, sp\n\t"
        "	adds r5, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	mov r2, sp\n\t"
        "	adds r3, r5, #0\n\t"
        "	bl ObjectEventMoveDestCoords\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08092E84\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r5, r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl GetCollisionAtCoords\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091D0A\n\t"
        "	mov r1, r8\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08091D1E\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091D1E\n\t"
        "_08091D0A:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "_08091D1E:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r7, #0x30]\n\t"
        "	movs r0, #1\n\t"
        "	add sp, #4\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08091D38: .4byte gUnknown_84DDA21\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 CopyablePlayerMovement_Jump(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 playerDirection, bool8 tileCallback(u8))
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #8\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	mov r8, r3\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r6, r2, #0x18\n\t"
        "	ldr r1, _08091E00\n\t"
        "	ldrb r0, [r4, #6]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x21\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl state_to_direction\n\t"
        "	adds r6, r0, #0\n\t"
        "	ldrh r1, [r4, #0x10]\n\t"
        "	add r0, sp, #4\n\t"
        "	strh r1, [r0]\n\t"
        "	ldrh r0, [r4, #0x12]\n\t"
        "	mov r5, sp\n\t"
        "	adds r5, #6\n\t"
        "	strh r0, [r5]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp]\n\t"
        "	adds r0, r6, #0\n\t"
        "	add r1, sp, #4\n\t"
        "	adds r2, r5, #0\n\t"
        "	movs r3, #2\n\t"
        "	bl MoveCoordsInDirection\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl sub_08092E00\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "	add r0, sp, #4\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r5, r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r3, r6, #0\n\t"
        "	bl GetCollisionAtCoords\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091DD0\n\t"
        "	mov r1, r8\n\t"
        "	cmp r1, #0\n\t"
        "	beq _08091DE4\n\t"
        "	add r0, sp, #4\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091DE4\n\t"
        "_08091DD0:\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl ObjectEventSetSingleMovement\n\t"
        "_08091DE4:\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r7, #0x30]\n\t"
        "	movs r0, #1\n\t"
        "	add sp, #8\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08091E00: .4byte gUnknown_84DDA21\n\t"
        ".syntax divided\n\t"
    );
}


void MovementType_CopyPlayerInGrass(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, StartFieldEffectForEventObject);
}

u8 StartFieldEffectForEventObject(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_CopyPlayerInGrass[sprite->sTypeFuncId](objectEvent, sprite);
}

__attribute__((naked)) bool8 MovementType_CopyPlayerInGrass_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	ldr r2, _08091E6C\n\t"
        "	ldr r3, _08091E70\n\t"
        "	ldrb r1, [r3, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #0x1c]\n\t"
        "	cmp r0, #0xff\n\t"
        "	beq _08091E68\n\t"
        "	ldrb r0, [r3, #3]\n\t"
        "	cmp r0, #2\n\t"
        "	bne _08091E74\n\t"
        "_08091E68:\n\t"
        "	movs r0, #0\n\t"
        "	b _08091E9C\n\t"
        "	.align 2, 0\n\t"
        "_08091E6C: .4byte gObjectEvents\n\t"
        "_08091E70: .4byte gPlayerAvatar\n\t"
        "_08091E74:\n\t"
        "	ldr r5, _08091EA4\n\t"
        "	bl PlayerGetCopyableMovement\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x16\n\t"
        "	adds r4, r4, r5\n\t"
        "	bl GetPlayerMovementDirection\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldr r3, _08091EA8\n\t"
        "	ldr r4, [r4]\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl _call_via_r4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "_08091E9C:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08091EA4: .4byte gUnknown_84E5EB8\n\t"
        "_08091EA8: .4byte MetatileBehavior_IsPokeGrass + 1\n\t"
        ".syntax divided\n\t"
    );
}

void MovementType_TreeDisguise(struct Sprite *sprite)
{
    struct ObjectEvent *objectEvent;

    objectEvent = &gObjectEvents[sprite->sObjEventId];
    if (objectEvent->directionSequenceIndex == 0 || (objectEvent->directionSequenceIndex == 1 && !sprite->data[7]))
    {
        ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
        objectEvent->fieldEffectSpriteId = FieldEffectStart(FLDEFF_TREE_DISGUISE);
        objectEvent->directionSequenceIndex = 1;
        sprite->data[7]++;
    }
    UpdateObjectEventCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_Disguise_Callback);
}
bool8 MovementType_Disguise_Callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    return FALSE;
}



void MovementType_MountainDisguise(struct Sprite *sprite)
{
    struct ObjectEvent *objectEvent;

    objectEvent = &gObjectEvents[sprite->sObjEventId];
    if (objectEvent->directionSequenceIndex == 0 || (objectEvent->directionSequenceIndex == 1 && !sprite->data[7]))
    {
        ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
        objectEvent->fieldEffectSpriteId = FieldEffectStart(FLDEFF_MOUNTAIN_DISGUISE);
        objectEvent->directionSequenceIndex = 1;
        sprite->data[7]++;
    }
    UpdateObjectEventCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_Disguise_Callback);
}

__attribute__((naked)) void MovementType_Hidden(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r3, r0, #0\n\t"
        "	movs r1, #0x3c\n\t"
        "	ldrsh r0, [r3, r1]\n\t"
        "	ldr r4, _08091FF4\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08091FD8\n\t"
        "	movs r0, #0x2e\n\t"
        "	ldrsh r1, [r3, r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r1, [r0, #3]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0, #3]\n\t"
        "	adds r2, r3, #0\n\t"
        "	adds r2, #0x42\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x3f\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x80\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrb r0, [r3, #5]\n\t"
        "	movs r1, #0xc\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r3, #5]\n\t"
        "	ldrh r0, [r3, #0x3c]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r3, #0x3c]\n\t"
        "_08091FD8:\n\t"
        "	movs r0, #0x2e\n\t"
        "	ldrsh r1, [r3, r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldr r2, _08091FF8\n\t"
        "	adds r1, r3, #0\n\t"
        "	bl UpdateEventObjectCurrentMovement\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08091FF4: .4byte gObjectEvents\n\t"
        "_08091FF8: .4byte sub_08091FFC + 1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08091FFC(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r3, _08092018\n\t"
        "	movs r4, #0x30\n\t"
        "	ldrsh r2, [r1, r4]\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r3\n\t"
        "	ldr r2, [r2]\n\t"
        "	bl _call_via_r2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092018: .4byte gUnknown_84E5EF0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementType_Hidden_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    return FALSE;
}

bool8 MovementType_MoveInPlace_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 result = ObjectEventExecSingleMovementAction(objectEvent, sprite);

    if (result)
        sprite->sTypeFuncId = 0;
    return FALSE;
}

void MovementType_WalkInPlace(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, GetAcroPopWheelieFaceDirectionMovementAction);
}

u8 GetAcroPopWheelieFaceDirectionMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkInPlace[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_WalkInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, sub_08092F08(objectEvent->facingDirection));
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_WalkSlowlyInPlace(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, GetAcroWheelieFaceDirectionMovementAction);
}

u8 GetAcroWheelieFaceDirectionMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_WalkSlowlyInPlace[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_WalkSlowlyInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, sub_08092EDC(objectEvent->facingDirection));
    sprite->sTypeFuncId = 1;
    return TRUE;
}


void MovementType_JogInPlace(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, GetAcroWheelieHopFaceDirectionMovementAction);
}

u8 GetAcroWheelieHopFaceDirectionMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_JogInPlace[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_JogInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, sub_08092F34(objectEvent->facingDirection));
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_RunInPlace(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, GetAcroWheelieJumpDirectionMovementAction);
}

u8 GetAcroWheelieJumpDirectionMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_RunInPlace[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_RunInPlace_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, sub_08092F60(objectEvent->facingDirection));
    sprite->sTypeFuncId = 1;
    return TRUE;
}

void MovementType_Invisible(struct Sprite *sprite)
{
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, MovementType_Invisible_callback);
}

u8 MovementType_Invisible_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_Invisible[sprite->sTypeFuncId](objectEvent, sprite);
}

bool8 MovementType_Invisible_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ClearEventObjectMovement(objectEvent, sprite);
    ObjectEventSetSingleMovement(objectEvent, sprite, GetFaceDirectionMovementAction(objectEvent->facingDirection));
    objectEvent->invisible = TRUE;
    sprite->sTypeFuncId = 1;
    return TRUE;
}

bool8 MovementType_Invisible_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        sprite->sTypeFuncId = 2;
        return TRUE;
    }
    return FALSE;
}


bool8 MovementType_FaceDirection_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->singleMovementActive = FALSE;
    return FALSE;
}


__attribute__((naked)) bool8 ClearEventObjectMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldrb r3, [r0]\n\t"
        "	movs r2, #3\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	ands r2, r3\n\t"
        "	movs r3, #0x41\n\t"
        "	rsbs r3, r3, #0\n\t"
        "	ands r2, r3\n\t"
        "	movs r3, #0x7f\n\t"
        "	ands r2, r3\n\t"
        "	strb r2, [r0]\n\t"
        "	movs r2, #0xff\n\t"
        "	strb r2, [r0, #0x1c]\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1, #0x30]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

u8 GetJumpInPlaceMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gJumpInPlaceMovementActions[dir];
}

u8 GetJumpInPlaceTurnAroundMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gJumpInPlaceTurnAroundMovementActions[dir];
}

u8 GetJumpMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gJumpMovementActions[dir];
}

u8 GetJumpSpecialMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gJumpSpecialMovementActions[dir];
}

u8 GetPlayerRunMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gPlayerRunMovementActions[dir];
}


u8 GetRideWaterCurrentMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gRideWaterCurrentMovementActions[dir];
}

u8 GetSlideMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gSlideMovementActions[dir];
}

u8 GetWalkFastMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gWalkFastMovementActions[dir];
}

u8 GetWalkFastestMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gWalkFasterMovementActions[dir];
}

u8 GetWalkInPlaceFastMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gWalkInPlaceFastMovementActions[dir];
}

u8 GetWalkInPlaceFastestMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gWalkInPlaceFasterMovementActions[dir];
}

u8 GetWalkInPlaceNormalMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gWalkInPlaceNormalMovementActions[dir];
}

u8 GetWalkInPlaceSlowMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gWalkInPlaceSlowMovementActions[dir];
}

u8 GetWalkNormalMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gWalkNormalMovementActions[dir];
}

u8 GetWalkSlowMovementAction(u32 direction)
{
    u8 dir = (u8)direction;
    return gWalkSlowMovementActions[dir];
}

__attribute__((naked)) void *sub_080923BC(u32 id)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldr r1, _080923C4\n\t"
        "	b _080923D4\n\t"
        "	.align 2, 0\n\t"
        "_080923C4: .4byte gUnknown_84E1900\n\t"
        "_080923C8:\n\t"
        "	ldr r0, [r1]\n\t"
        "	cmp r0, r2\n\t"
        "	bne _080923D2\n\t"
        "	adds r0, r1, #0\n\t"
        "	b _080923DC\n\t"
        "_080923D2:\n\t"
        "	adds r1, #8\n\t"
        "_080923D4:\n\t"
        "	ldr r0, [r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080923C8\n\t"
        "	movs r0, #0\n\t"
        "_080923DC:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void npc_apply_anim_looping(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animNum)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08092422\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x2a\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r0, [r4, #8]\n\t"
        "	bl sub_080923BC\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r1, #0x2b\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809241A\n\t"
        "	ldrb r2, [r1]\n\t"
        "	ldrb r3, [r0, #4]\n\t"
        "	cmp r2, r3\n\t"
        "	bne _08092410\n\t"
        "	ldrb r0, [r0, #7]\n\t"
        "	b _08092418\n\t"
        "_08092410:\n\t"
        "	ldrb r3, [r0, #5]\n\t"
        "	cmp r2, r3\n\t"
        "	bne _0809241A\n\t"
        "	ldrb r0, [r0, #6]\n\t"
        "_08092418:\n\t"
        "	strb r0, [r1]\n\t"
        "_0809241A:\n\t"
        "	ldrb r1, [r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl SeekSpriteAnim\n\t"
        "_08092422:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void obj_npc_animation_step(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animNum)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08092460\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x2a\n\t"
        "	strb r2, [r0]\n\t"
        "	ldr r0, [r4, #8]\n\t"
        "	bl sub_080923BC\n\t"
        "	adds r2, r0, #0\n\t"
        "	cmp r2, #0\n\t"
        "	beq _08092460\n\t"
        "	ldrb r1, [r2, #5]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x2b\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldrb r3, [r2, #4]\n\t"
        "	cmp r0, r3\n\t"
        "	bhi _0809245A\n\t"
        "	ldrb r1, [r2, #4]\n\t"
        "_0809245A:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl SeekSpriteAnim\n\t"
        "_08092460:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

u8 GetDirectionToFace(s16 x, s16 y, s16 targetX, s16 targetY)
{
    if (x > targetX)
        return DIR_WEST;

    if (x < targetX)
        return DIR_EAST;

    if (y > targetY)
        return DIR_NORTH;

    return DIR_SOUTH;
}

void SetTrainerMovementType(struct ObjectEvent *objectEvent, u8 movementType)
{
    objectEvent->movementType = movementType;
    objectEvent->directionSequenceIndex = 0;
    objectEvent->playerCopyableMovement = 0;
    gSprites[objectEvent->spriteId].callback = sMovementTypeCallbacks[movementType];
    gSprites[objectEvent->spriteId].sTypeFuncId = 0;
}

__attribute__((naked, section(".text.GroundEffect_DeepSandTracks"))) u8 GetTrainerFacingDirectionMovementType(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _080924F4\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080924F4: .4byte gTrainerFacingDirectionMovementTypes\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetCollisionInDirection(struct ObjectEvent *objectEvent, u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r6, r0, #0\n\t"
        "	lsls r5, r1, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldrh r1, [r6, #0x10]\n\t"
        "	mov r0, sp\n\t"
        "	strh r1, [r0]\n\t"
        "	ldrh r0, [r6, #0x12]\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #2\n\t"
        "	strh r0, [r4]\n\t"
        "	adds r0, r5, #0\n\t"
        "	mov r1, sp\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl MoveCoords\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r4, r0]\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r3, r5, #0\n\t"
        "	bl GetCollisionAtCoords\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetCollisionAtCoords(struct ObjectEvent *objectEvent, s16 x, s16 y, u32 dir)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r7, r3, #0x18\n\t"
        "	mov r8, r7\n\t"
        "	lsrs r0, r1, #0x10\n\t"
        "	mov sb, r0\n\t"
        "	asrs r5, r1, #0x10\n\t"
        "	lsrs r0, r2, #0x10\n\t"
        "	mov sl, r0\n\t"
        "	asrs r4, r2, #0x10\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl IsCoordOutsideObjectEventMovementRange\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809256E\n\t"
        "	movs r0, #1\n\t"
        "	b _080925EE\n\t"
        "_0809256E:\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl MapGridGetCollisionAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080925B0\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl GetMapBorderIdAt\n\t"
        "	movs r1, #1\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	cmp r0, r1\n\t"
        "	beq _080925B0\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl IsMetatileDirectionallyImpassable\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080925B0\n\t"
        "	ldrb r0, [r6, #1]\n\t"
        "	lsrs r0, r0, #7\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080925B4\n\t"
        "	mov r0, r8\n\t"
        "	bl CanCameraMoveInDirection\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080925B4\n\t"
        "_080925B0:\n\t"
        "	movs r0, #2\n\t"
        "	b _080925EE\n\t"
        "_080925B4:\n\t"
        "	ldrb r0, [r6, #0xb]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	mov r2, sb\n\t"
        "	lsls r1, r2, #0x10\n\t"
        "	asrs r5, r1, #0x10\n\t"
        "	mov r2, sl\n\t"
        "	lsls r1, r2, #0x10\n\t"
        "	asrs r4, r1, #0x10\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl IsZCoordMismatchAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080925D8\n\t"
        "	movs r0, #3\n\t"
        "	b _080925EE\n\t"
        "_080925D8:\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl DoesObjectCollideWithObjectAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080925EC\n\t"
        "	movs r0, #0\n\t"
        "	b _080925EE\n\t"
        "_080925EC:\n\t"
        "	movs r0, #4\n\t"
        "_080925EE:\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetCollisionFlagsAtCoords(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	adds r7, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	mov r8, r3\n\t"
        "	lsrs r0, r1, #0x10\n\t"
        "	mov sb, r0\n\t"
        "	asrs r6, r1, #0x10\n\t"
        "	lsrs r0, r2, #0x10\n\t"
        "	mov sl, r0\n\t"
        "	asrs r5, r2, #0x10\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl IsCoordOutsideObjectEventMovementRange\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	rsbs r1, r0, #0\n\t"
        "	orrs r1, r0\n\t"
        "	lsrs r4, r1, #0x1f\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl MapGridGetCollisionAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08092674\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetMapBorderIdAt\n\t"
        "	movs r1, #1\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	cmp r0, r1\n\t"
        "	beq _08092674\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	mov r3, r8\n\t"
        "	bl IsMetatileDirectionallyImpassable\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08092674\n\t"
        "	ldrb r0, [r7, #1]\n\t"
        "	lsrs r0, r0, #7\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08092678\n\t"
        "	mov r0, r8\n\t"
        "	bl CanCameraMoveInDirection\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08092678\n\t"
        "_08092674:\n\t"
        "	movs r0, #2\n\t"
        "	orrs r4, r0\n\t"
        "_08092678:\n\t"
        "	ldrb r0, [r7, #0xb]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	mov r2, sb\n\t"
        "	lsls r1, r2, #0x10\n\t"
        "	asrs r6, r1, #0x10\n\t"
        "	mov r2, sl\n\t"
        "	lsls r1, r2, #0x10\n\t"
        "	asrs r5, r1, #0x10\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl IsZCoordMismatchAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080926A0\n\t"
        "	movs r0, #4\n\t"
        "	orrs r4, r0\n\t"
        "	lsls r0, r4, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "_080926A0:\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl DoesObjectCollideWithObjectAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080926B8\n\t"
        "	movs r0, #8\n\t"
        "	orrs r4, r0\n\t"
        "	lsls r0, r4, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "_080926B8:\n\t"
        "	adds r0, r4, #0\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 IsCoordOutsideObjectEventMovementRange(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r3, r1, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r5, r2, #0x10\n\t"
        "	ldrb r1, [r4, #0x19]\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08092700\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r2, r1, #0x1c\n\t"
        "	ldrh r0, [r4, #0xc]\n\t"
        "	subs r2, r0, r2\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsls r0, r3, #0x10\n\t"
        "	asrs r3, r0, #0x10\n\t"
        "	cmp r2, r0\n\t"
        "	bgt _0809272C\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, r3\n\t"
        "	blt _0809272C\n\t"
        "_08092700:\n\t"
        "	ldrb r1, [r4, #0x19]\n\t"
        "	movs r0, #0xf0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08092730\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r2, r1, #0x1c\n\t"
        "	ldrh r0, [r4, #0xe]\n\t"
        "	subs r2, r0, r2\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsls r0, r5, #0x10\n\t"
        "	asrs r3, r0, #0x10\n\t"
        "	cmp r2, r0\n\t"
        "	bgt _0809272C\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, r3\n\t"
        "	bge _08092730\n\t"
        "_0809272C:\n\t"
        "	movs r0, #1\n\t"
        "	b _08092732\n\t"
        "_08092730:\n\t"
        "	movs r0, #0\n\t"
        "_08092732:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) bool8 IsMetatileDirectionallyImpassable(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r6, r1, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r7, r2, #0x10\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	ldr r1, _08092780\n\t"
        "	lsrs r3, r3, #0x16\n\t"
        "	subs r5, r3, #4\n\t"
        "	adds r1, r5, r1\n\t"
        "	ldrb r0, [r0, #0x1e]\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl _call_via_r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0809277A\n\t"
        "	ldr r4, _08092784\n\t"
        "	adds r4, r5, r4\n\t"
        "	lsls r0, r6, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	lsls r1, r7, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, [r4]\n\t"
        "	bl _call_via_r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08092788\n\t"
        "_0809277A:\n\t"
        "	movs r0, #1\n\t"
        "	b _0809278A\n\t"
        "	.align 2, 0\n\t"
        "_08092780: .4byte gDirectionBlockedMetatileFuncs\n\t"
        "_08092784: .4byte gOppositeDirectionBlockedMetatileFuncs\n\t"
        "_08092788:\n\t"
        "	movs r0, #0\n\t"
        "_0809278A:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 DoesObjectCollideWithObjectAt(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r7, r1, #0x10\n\t"
        "	movs r4, #0\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	asrs r5, r2, #0x10\n\t"
        "_0809279E:\n\t"
        "	lsls r0, r4, #3\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080927F4\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080927F8\n\t"
        "	cmp r2, r6\n\t"
        "	beq _080927F8\n\t"
        "	movs r0, #0x10\n\t"
        "	ldrsh r1, [r2, r0]\n\t"
        "	lsls r0, r7, #0x10\n\t"
        "	asrs r3, r0, #0x10\n\t"
        "	cmp r1, r3\n\t"
        "	bne _080927C8\n\t"
        "	movs r1, #0x12\n\t"
        "	ldrsh r0, [r2, r1]\n\t"
        "	cmp r0, r5\n\t"
        "	beq _080927D8\n\t"
        "_080927C8:\n\t"
        "	movs r1, #0x14\n\t"
        "	ldrsh r0, [r2, r1]\n\t"
        "	cmp r0, r3\n\t"
        "	bne _080927F8\n\t"
        "	movs r1, #0x16\n\t"
        "	ldrsh r0, [r2, r1]\n\t"
        "	cmp r0, r5\n\t"
        "	bne _080927F8\n\t"
        "_080927D8:\n\t"
        "	ldrb r0, [r6, #0xb]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	ldrb r1, [r2, #0xb]\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	bl AreElevationsCompatible\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080927F8\n\t"
        "	movs r0, #1\n\t"
        "	b _08092804\n\t"
        "	.align 2, 0\n\t"
        "_080927F4: .4byte gObjectEvents\n\t"
        "_080927F8:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0xf\n\t"
        "	bls _0809279E\n\t"
        "	movs r0, #0\n\t"
        "_08092804:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 IsBerryTreeSparkling(u8 localId, u8 mapNum, u8 mapGroup)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08092858\n\t"
        "	ldr r3, _08092850\n\t"
        "	ldr r2, _08092854\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r0, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r1, [r0, #0x3c]\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08092858\n\t"
        "	movs r0, #1\n\t"
        "	b _0809285A\n\t"
        "	.align 2, 0\n\t"
        "_08092850: .4byte gSprites\n\t"
        "_08092854: .4byte gObjectEvents\n\t"
        "_08092858:\n\t"
        "	movs r0, #0\n\t"
        "_0809285A:\n\t"
        "	add sp, #4\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08092860(u8 localId, u8 mapNum, u8 mapGroup)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	mov r3, sp\n\t"
        "	bl TryGetObjectEventIdByLocalIdAndMap\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0809289E\n\t"
        "	ldr r3, _080928A4\n\t"
        "	ldr r2, _080928A8\n\t"
        "	mov r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrh r2, [r1, #0x3c]\n\t"
        "	movs r0, #4\n\t"
        "	orrs r0, r2\n\t"
        "	strh r0, [r1, #0x3c]\n\t"
        "_0809289E:\n\t"
        "	add sp, #4\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080928A4: .4byte gSprites\n\t"
        "_080928A8: .4byte gObjectEvents\n\t"
        ".syntax divided\n\t"
    );
}

void MoveCoords(u8 direction, s16 *x, s16 *y)
{
    *x += sDirectionToVectors[direction].x;
    *y += sDirectionToVectors[direction].y;
}

__attribute__((naked)) void sub_080928D0(u8 direction, s16 *destX, s16 *destY)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	ldr r3, _080928F4\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrh r3, [r0]\n\t"
        "	lsls r3, r3, #4\n\t"
        "	ldrh r4, [r1]\n\t"
        "	adds r3, r3, r4\n\t"
        "	strh r3, [r1]\n\t"
        "	ldrh r0, [r0, #2]\n\t"
        "	lsls r0, r0, #4\n\t"
        "	ldrh r1, [r2]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r2]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080928F4: .4byte gUnknown_84E5FD0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void MoveCoordsInDirection(u32 direction, s16 *x, s16 *y, s16 deltaX, s16 deltaY)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldr r1, [sp, #0x14]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	lsrs r3, r3, #0x10\n\t"
        "	adds r7, r3, #0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r6, r1, #0x10\n\t"
        "	mov ip, r6\n\t"
        "	ldr r1, _0809295C\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	adds r5, r0, r1\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r1, [r5, r0]\n\t"
        "	cmp r1, #0\n\t"
        "	ble _08092924\n\t"
        "	lsls r0, r3, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	ldrh r3, [r4]\n\t"
        "	adds r0, r0, r3\n\t"
        "	strh r0, [r4]\n\t"
        "_08092924:\n\t"
        "	cmp r1, #0\n\t"
        "	bge _08092932\n\t"
        "	ldrh r1, [r4]\n\t"
        "	lsls r0, r7, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	subs r1, r1, r0\n\t"
        "	strh r1, [r4]\n\t"
        "_08092932:\n\t"
        "	movs r0, #2\n\t"
        "	ldrsh r1, [r5, r0]\n\t"
        "	cmp r1, #0\n\t"
        "	ble _08092944\n\t"
        "	lsls r0, r6, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	ldrh r3, [r2]\n\t"
        "	adds r0, r0, r3\n\t"
        "	strh r0, [r2]\n\t"
        "_08092944:\n\t"
        "	cmp r1, #0\n\t"
        "	bge _08092954\n\t"
        "	ldrh r1, [r2]\n\t"
        "	mov r3, ip\n\t"
        "	lsls r0, r3, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	subs r1, r1, r0\n\t"
        "	strh r1, [r2]\n\t"
        "_08092954:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0809295C: .4byte gUnknown_84E5FD0\n\t"
        ".syntax divided\n\t"
    );
}

void GetMapCoordsFromSpritePos(s16 x, s16 y, s16 *destX, s16 *destY)
{
    *destX = (x - gSaveBlock1Ptr->pos.x) << 4;
    *destY = (y - gSaveBlock1Ptr->pos.y) << 4;
    *destX -= gTotalCameraPixelOffsetX;
    *destY -= gTotalCameraPixelOffsetY;
}

void SetSpritePosToMapCoords(s16 mapX, s16 mapY, s16 *destX, s16 *destY)
{
    s16 dx = -gTotalCameraPixelOffsetX - gFieldCamera.x;
    s16 dy = -gTotalCameraPixelOffsetY - gFieldCamera.y;
    if (gFieldCamera.x > 0)
        dx += 16;

    if (gFieldCamera.x < 0)
        dx -= 16;

    if (gFieldCamera.y > 0)
        dy += 16;

    if (gFieldCamera.y < 0)
        dy -= 16;

    *destX = ((mapX - gSaveBlock1Ptr->pos.x) << 4) + dx;
    *destY = ((mapY - gSaveBlock1Ptr->pos.y) << 4) + dy;
}

void SetSpritePosToOffsetMapCoords(s16 *x, s16 *y, s16 dx, s16 dy)
{
    SetSpritePosToMapCoords(*x, *y, x, y);
    *x += dx;
    *y += dy;
}

__attribute__((naked)) void GetEventObjectMovingCameraOffset(s16 *x, s16 *y)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r2, r0, #0\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r2]\n\t"
        "	strh r0, [r1]\n\t"
        "	ldr r3, _08092AD8\n\t"
        "	ldr r0, [r3, #0x10]\n\t"
        "	cmp r0, #0\n\t"
        "	ble _08092AB2\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r2]\n\t"
        "_08092AB2:\n\t"
        "	ldr r0, [r3, #0x10]\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08092ABE\n\t"
        "	ldrh r0, [r2]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r2]\n\t"
        "_08092ABE:\n\t"
        "	ldr r2, [r3, #0x14]\n\t"
        "	cmp r2, #0\n\t"
        "	ble _08092ACA\n\t"
        "	ldrh r0, [r1]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "_08092ACA:\n\t"
        "	cmp r2, #0\n\t"
        "	bge _08092AD4\n\t"
        "	ldrh r0, [r1]\n\t"
        "	subs r0, #1\n\t"
        "	strh r0, [r1]\n\t"
        "_08092AD4:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08092AD8: .4byte gFieldCamera\n\t"
        ".syntax divided\n\t"
    );
}

void ObjectEventMoveDestCoords(struct ObjectEvent *objectEvent, u32 direction, s16 *x, s16 *y)
{
    u8 newDirn = direction;
    *x = objectEvent->currentCoords.x;
    *y = objectEvent->currentCoords.y;
    MoveCoords(newDirn, x, y);
}

bool8 ObjectEventIsMovementOverridden(struct ObjectEvent *objectEvent)
{
    if (objectEvent->singleMovementActive || objectEvent->heldMovementActive)
        return TRUE;

    return FALSE;
}

bool8 ObjectEventIsHeldMovementActive(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive && objectEvent->movementActionId != MOVEMENT_ACTION_NONE)
        return TRUE;

    return FALSE;
}

bool8 ObjectEventSetHeldMovement(struct ObjectEvent *objectEvent, u8 movementActionId)
{
    if (ObjectEventIsMovementOverridden(objectEvent))
        return TRUE;

    UnfreezeEventObject(objectEvent);
    objectEvent->movementActionId = movementActionId;
    objectEvent->heldMovementActive = TRUE;
    objectEvent->heldMovementFinished = FALSE;
    gSprites[objectEvent->spriteId].sActionFuncId = 0;
    return FALSE;
}

void ObjectEventForceSetHeldMovement(struct ObjectEvent *objectEvent, u8 movementActionId)
{
    ObjectEventClearHeldMovementIfActive(objectEvent);
    ObjectEventSetHeldMovement(objectEvent, movementActionId);
}

void ObjectEventClearHeldMovementIfActive(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive)
        EventObjectClearHeldMovement(objectEvent);
}

__attribute__((naked)) void EventObjectClearHeldMovement(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	movs r1, #0xff\n\t"
        "	strb r1, [r0, #0x1c]\n\t"
        "	ldrb r2, [r0]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r2\n\t"
        "	movs r2, #0x7f\n\t"
        "	ands r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r3, _08092BDC\n\t"
        "	ldrb r2, [r0, #4]\n\t"
        "	lsls r1, r2, #4\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r3\n\t"
        "	movs r2, #0\n\t"
        "	strh r2, [r1, #0x30]\n\t"
        "	ldrb r1, [r0, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	strh r2, [r0, #0x32]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_08092BDC: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

u8 ObjectEventCheckHeldMovementStatus(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive)
        return objectEvent->heldMovementFinished;

    return 16;
}

__attribute__((naked)) u8 ObjectEventClearHeldMovementIfFinished(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	bl ObjectEventCheckHeldMovementStatus\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	beq _08092C0E\n\t"
        "	cmp r4, #0x10\n\t"
        "	beq _08092C0E\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfActive\n\t"
        "_08092C0E:\n\t"
        "	adds r0, r4, #0\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}


u8 EventObjectGetHeldMovementActionId(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive)
        return objectEvent->movementActionId;
    return MOVEMENT_ACTION_NONE;
}

__attribute__((naked)) void UpdateEventObjectCurrentMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite, bool8 (*callback)(struct ObjectEvent *, struct Sprite *))
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r6, r2, #0\n\t"
        "	bl DoGroundEffects_OnSpawn\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl TryEnableEventObjectAnim\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventIsHeldMovementActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08092C5A\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl EventObjectExecHeldMovementAction\n\t"
        "	b _08092C70\n\t"
        "_08092C5A:\n\t"
        "	ldrb r0, [r4, #1]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08092C70\n\t"
        "_08092C62:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl _call_via_r6\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08092C62\n\t"
        "_08092C70:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl DoGroundEffects_OnBeginStep\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl DoGroundEffects_OnFinishStep\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl UpdateEventObjectSpriteAnimPause\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl UpdateObjectEventVisibility\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl ObjectEventUpdateSubpriority\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetFaceDirectionMovementAction(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092CC8\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092CB8\n\t"
        "	movs r4, #0\n\t"
        "_08092CB8:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092CC8: .4byte sFaceDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092CCC(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092CF4\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092CE4\n\t"
        "	movs r4, #0\n\t"
        "_08092CE4:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092CF4: .4byte sWalkSlowMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092CF8(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092D20\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092D10\n\t"
        "	movs r4, #0\n\t"
        "_08092D10:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092D20: .4byte sWalkNormalMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092D24(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092D4C\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092D3C\n\t"
        "	movs r4, #0\n\t"
        "_08092D3C:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092D4C: .4byte sWalkFastMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092D50(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092D78\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092D68\n\t"
        "	movs r4, #0\n\t"
        "_08092D68:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092D78: .4byte sRideWaterCurrentMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092D7C(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092DA4\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092D94\n\t"
        "	movs r4, #0\n\t"
        "_08092D94:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092DA4: .4byte sWalkFasterMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092DA8(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092DD0\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092DC0\n\t"
        "	movs r4, #0\n\t"
        "_08092DC0:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092DD0: .4byte sSlideMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092DD4(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092DFC\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092DEC\n\t"
        "	movs r4, #0\n\t"
        "_08092DEC:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092DFC: .4byte sPlayerRunMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092E00(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092E28\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092E18\n\t"
        "	movs r4, #0\n\t"
        "_08092E18:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092E28: .4byte sJump2MovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092E2C(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092E54\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092E44\n\t"
        "	movs r4, #0\n\t"
        "_08092E44:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092E54: .4byte sJumpInPlaceMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092E58(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092E80\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092E70\n\t"
        "	movs r4, #0\n\t"
        "_08092E70:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092E80: .4byte sJumpInPlaceTurnAroundMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092E84(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092EAC\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092E9C\n\t"
        "	movs r4, #0\n\t"
        "_08092E9C:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092EAC: .4byte sJumpMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092EB0(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092ED8\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092EC8\n\t"
        "	movs r4, #0\n\t"
        "_08092EC8:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092ED8: .4byte sJumpSpecialMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092EDC(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092F04\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092EF4\n\t"
        "	movs r4, #0\n\t"
        "_08092EF4:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092F04: .4byte sWalkInPlaceSlowMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092F08(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092F30\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092F20\n\t"
        "	movs r4, #0\n\t"
        "_08092F20:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092F30: .4byte sWalkInPlaceNormalMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092F34(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092F5C\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092F4C\n\t"
        "	movs r4, #0\n\t"
        "_08092F4C:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092F5C: .4byte sWalkInPlaceFastMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092F60(u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092F88\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092F78\n\t"
        "	movs r4, #0\n\t"
        "_08092F78:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092F88: .4byte sWalkInPlaceFasterMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

bool8 ObjectEventFaceOppositeDirection(struct ObjectEvent *objectEvent, u8 direction)
{
    return ObjectEventSetHeldMovement(objectEvent, GetFaceDirectionMovementAction(GetOppositeDirection(direction)));
}


__attribute__((naked)) u8 sub_08092FB8(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08092FE0\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092FD0\n\t"
        "	movs r4, #0\n\t"
        "_08092FD0:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08092FE0: .4byte sAcroWheelieFaceDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08092FE4(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _0809300C\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08092FFC\n\t"
        "	movs r4, #0\n\t"
        "_08092FFC:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0809300C: .4byte sAcroPopWheelieFaceDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 EventObjectExecSingleMovementAction(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08093038\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08093028\n\t"
        "	movs r4, #0\n\t"
        "_08093028:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08093038: .4byte sAcroEndWheelieFaceDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_0809303C(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08093064\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08093054\n\t"
        "	movs r4, #0\n\t"
        "_08093054:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08093064: .4byte sAcroWheelieHopFaceDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetAcroEndWheelieFaceDirectionMovementAction(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08093090\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08093080\n\t"
        "	movs r4, #0\n\t"
        "_08093080:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08093090: .4byte sAcroWheelieHopDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08093094(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _080930BC\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _080930AC\n\t"
        "	movs r4, #0\n\t"
        "_080930AC:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080930BC: .4byte sAcroWheelieJumpDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_080930C0(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _080930E8\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _080930D8\n\t"
        "	movs r4, #0\n\t"
        "_080930D8:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080930E8: .4byte sAcroWheelieInPlaceDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_080930EC(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08093114\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08093104\n\t"
        "	movs r4, #0\n\t"
        "_08093104:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08093114: .4byte sAcroPopWheelieMoveDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08093118(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _08093140\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08093130\n\t"
        "	movs r4, #0\n\t"
        "_08093130:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08093140: .4byte sAcroWheelieMoveDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08093144(u32 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r1, _0809316C\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	cmp r4, #4\n\t"
        "	bls _0809315C\n\t"
        "	movs r4, #0\n\t"
        "_0809315C:\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0809316C: .4byte sAcroEndWheelieMoveDirectionMovementActions\n\t"
        ".syntax divided\n\t"
    );
}

u8 GetOppositeDirection(u8 direction)
{
    u8 directions[8];
    memcpy(directions, sOppositeDirections, sizeof directions);
    if (direction <= DIR_NONE || direction > 8)
        return direction;

    return directions[direction - 1];
}

__attribute__((naked)) u8 zffu_offset_calc(u8 a, u8 b)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldr r2, _080931B8\n\t"
        "	lsrs r0, r0, #0x16\n\t"
        "	subs r0, #5\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080931B8: .4byte sDirectionCompositionOffsets\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u32 state_to_direction(u8 a, u8 b, u8 c)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r1, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	cmp r1, #0\n\t"
        "	beq _080931DC\n\t"
        "	cmp r2, #0\n\t"
        "	beq _080931DC\n\t"
        "	cmp r1, #4\n\t"
        "	bhi _080931DC\n\t"
        "	cmp r2, #4\n\t"
        "	bls _080931E0\n\t"
        "_080931DC:\n\t"
        "	movs r0, #0\n\t"
        "	b _080931F2\n\t"
        "_080931E0:\n\t"
        "	adds r1, r2, #0\n\t"
        "	bl zffu_offset_calc\n\t"
        "	ldr r2, _080931F8\n\t"
        "	lsls r1, r4, #2\n\t"
        "	subs r1, #5\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "_080931F2:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080931F8: .4byte sDirectionCompositionResults\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 EventObjectExecHeldMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r2, _08093230\n\t"
        "	ldrb r0, [r4, #0x1c]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r3, #0x32\n\t"
        "	ldrsh r2, [r1, r3]\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldr r2, [r2]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl _call_via_r2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08093228\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0x80\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "_08093228:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08093230: .4byte gMovementActionFuncs\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 ObjectEventExecSingleMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldr r1, _08093260\n\t"
        "	ldrb r0, [r4, #0x1c]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r2, #0x32\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r2, [r1]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl _call_via_r2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08093264\n\t"
        "	movs r0, #0\n\t"
        "	b _0809326E\n\t"
        "	.align 2, 0\n\t"
        "_08093260: .4byte gMovementActionFuncs\n\t"
        "_08093264:\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r4, #0x1c]\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_0809326E:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}


void ObjectEventSetSingleMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animId)
{
    objectEvent->movementActionId = animId;
    sprite->sActionFuncId = 0;
}


__attribute__((naked)) void FaceDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r1, r2, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	bl SetEventObjectDirection\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ShiftStillEventObjectCoords\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl GetJumpInPlaceTurnAroundMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl obj_npc_animation_step\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}


bool8 MovementAction_FaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FaceDirection(objectEvent, sprite, DIR_SOUTH);
    return TRUE;
}




bool8 MovementAction_FaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FaceDirection(objectEvent, sprite, DIR_NORTH);
    return TRUE;
}



bool8 MovementAction_FaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FaceDirection(objectEvent, sprite, DIR_WEST);
    return TRUE;
}



bool8 MovementAction_FaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FaceDirection(objectEvent, sprite, DIR_EAST);
    return TRUE;
}


__attribute__((naked)) void npc_apply_direction(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a, u8 b)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #4\n\t"
        "	adds r7, r0, #0\n\t"
        "	mov r8, r1\n\t"
        "	adds r4, r2, #0\n\t"
        "	adds r6, r3, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	lsls r6, r6, #0x18\n\t"
        "	lsrs r6, r6, #0x18\n\t"
        "	ldrh r1, [r7, #0x10]\n\t"
        "	mov r0, sp\n\t"
        "	strh r1, [r0]\n\t"
        "	ldrh r0, [r7, #0x12]\n\t"
        "	mov r5, sp\n\t"
        "	adds r5, #2\n\t"
        "	strh r0, [r5]\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl SetEventObjectDirection\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, sp\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl MoveCoords\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r5, r0]\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl ShiftEventObjectCoords\n\t"
        "	mov r0, r8\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl oamt_npc_ministep_reset\n\t"
        "	mov r4, r8\n\t"
        "	adds r4, #0x2c\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	ldr r0, _08093398\n\t"
        "	ldr r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809337E\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl FindLockedEventObjectIndex\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0x10\n\t"
        "	beq _0809337E\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "_0809337E:\n\t"
        "	ldrb r0, [r7]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r7]\n\t"
        "	movs r0, #1\n\t"
        "	mov r1, r8\n\t"
        "	strh r0, [r1, #0x32]\n\t"
        "	add sp, #4\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08093398: .4byte gUnknown_2037258\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void InitMovementNormal(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #0x14\n\t"
        "	adds r5, r0, #0\n\t"
        "	mov r8, r1\n\t"
        "	adds r4, r3, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	mov r1, sp\n\t"
        "	ldr r0, _080933F4\n\t"
        "	ldm r0!, {r3, r6, r7}\n\t"
        "	stm r1!, {r3, r6, r7}\n\t"
        "	ldm r0!, {r3, r6}\n\t"
        "	stm r1!, {r3, r6}\n\t"
        "	adds r0, r5, #0\n\t"
        "	mov r1, r8\n\t"
        "	adds r3, r4, #0\n\t"
        "	bl npc_apply_direction\n\t"
        "	lsls r4, r4, #2\n\t"
        "	mov r7, sp\n\t"
        "	adds r1, r7, r4\n\t"
        "	ldrb r0, [r5, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl _call_via_r1\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	mov r1, r8\n\t"
        "	bl npc_apply_anim_looping\n\t"
        "	add sp, #0x14\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080933F4: .4byte gUnknown_84E633C\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void StartRunningAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	movs r3, #1\n\t"
        "	bl npc_apply_direction\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl GetWalkSlowMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl npc_apply_anim_looping\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 UpdateMovementNormal(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl obj_npc_ministep\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0809343E\n\t"
        "	movs r0, #0\n\t"
        "	b _0809345A\n\t"
        "_0809343E:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ShiftStillEventObjectCoords\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r0, #1\n\t"
        "_0809345A:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 sub_08093460(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	sub sp, #4\n\t"
        "	adds r6, r0, #0\n\t"
        "	mov r8, r1\n\t"
        "	lsls r5, r2, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldrh r1, [r6, #0x10]\n\t"
        "	mov r0, sp\n\t"
        "	strh r1, [r0]\n\t"
        "	ldrh r0, [r6, #0x12]\n\t"
        "	mov r4, sp\n\t"
        "	adds r4, #2\n\t"
        "	strh r0, [r4]\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl SetEventObjectDirection\n\t"
        "	adds r0, r5, #0\n\t"
        "	mov r1, sp\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl MoveCoords\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r4, r0]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl ShiftEventObjectCoords\n\t"
        "	mov r0, r8\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl sub_0809704C\n\t"
        "	mov r2, r8\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrb r0, [r6]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	movs r0, #1\n\t"
        "	mov r1, r8\n\t"
        "	strh r0, [r1, #0x32]\n\t"
        "	add sp, #4\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 InitWalkSlow(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	bl sub_08093460\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl GetJumpInPlaceTurnAroundMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl npc_apply_anim_looping\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 UpdateWalkSlow(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl UpdateWalkSlowAnim\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08093512\n\t"
        "	movs r0, #0\n\t"
        "	b _0809352E\n\t"
        "_08093512:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ShiftStillEventObjectCoords\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r0, #1\n\t"
        "_0809352E:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_WalkSlowDiagonalUpLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_NORTHWEST);
    return sub_08093554(objectEvent, sprite);
}

__attribute__((naked)) bool8 sub_08093554(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	bl UpdateWalkSlow\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08093566\n\t"
        "	movs r0, #0\n\t"
        "	b _0809356C\n\t"
        "_08093566:\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r4, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_0809356C:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_WalkSlowDiagonalUpRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_NORTHEAST);
    return MovementAction_WalkSlowDiagonalUpRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowDiagonalUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlow(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalDownLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_SOUTHWEST);
    return MovementAction_WalkSlowDiagonalDownLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowDiagonalDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlow(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalDownRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_SOUTHEAST);
    return MovementAction_WalkSlowDiagonalDownRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowDiagonalDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlow(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_SOUTH);
    return MovementAction_WalkSlowDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlow(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}


bool8 MovementAction_WalkSlowUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_NORTH);
    return MovementAction_WalkSlowUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlow(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_WEST);
    return MovementAction_WalkSlowLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlow(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_EAST);
    return MovementAction_WalkSlowRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkSlowRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlow(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalUpLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_NORTHWEST, MOVE_SPEED_NORMAL);
    return MovementAction_WalkNormalDiagonalUpLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalDiagonalUpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalUpRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_NORTHEAST, MOVE_SPEED_NORMAL);
    return MovementAction_WalkNormalDiagonalUpRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalDiagonalUpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalDownLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_SOUTHWEST, MOVE_SPEED_NORMAL);
    return MovementAction_WalkNormalDiagonalDownLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalDiagonalDownLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDiagonalDownRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_SOUTHEAST, MOVE_SPEED_NORMAL);
    return MovementAction_WalkNormalDiagonalDownRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalDiagonalDownRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_SOUTH, MOVE_SPEED_NORMAL);
    return MovementAction_WalkNormalDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_NORTH, MOVE_SPEED_NORMAL);
    return MovementAction_WalkNormalUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkNormalLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_WEST, MOVE_SPEED_NORMAL);
    return MovementAction_WalkNormalLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}


bool8 MovementAction_WalkNormalRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_EAST, MOVE_SPEED_NORMAL);
    return MovementAction_WalkNormalRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkNormalRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

__attribute__((naked)) bool8 sub_08093934(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r7, r0, #0\n\t"
        "	mov sl, r1\n\t"
        "	adds r4, r2, #0\n\t"
        "	mov r8, r3\n\t"
        "	ldr r0, [sp, #0x30]\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	mov r1, r8\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	mov r8, r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	ldr r1, _080939EC\n\t"
        "	add r0, sp, #4\n\t"
        "	movs r2, #6\n\t"
        "	bl memcpy\n\t"
        "	add r5, sp, #0xc\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5]\n\t"
        "	mov r6, sp\n\t"
        "	adds r6, #0xe\n\t"
        "	strh r0, [r6]\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r1, r4, #0\n\t"
        "	bl SetEventObjectDirection\n\t"
        "	mov r1, r8\n\t"
        "	lsls r0, r1, #1\n\t"
        "	add r0, sp\n\t"
        "	adds r0, #4\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r3, [r0, r1]\n\t"
        "	str r3, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r6, #0\n\t"
        "	bl MoveCoordsInDirection\n\t"
        "	ldrh r1, [r5]\n\t"
        "	ldrh r0, [r7, #0x10]\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrh r2, [r6]\n\t"
        "	ldrh r0, [r7, #0x12]\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl ShiftEventObjectCoords\n\t"
        "	mov r0, sl\n\t"
        "	adds r1, r4, #0\n\t"
        "	mov r2, r8\n\t"
        "	mov r3, sb\n\t"
        "	bl sub_080971AC\n\t"
        "	movs r0, #1\n\t"
        "	mov r1, sl\n\t"
        "	strh r0, [r1, #0x32]\n\t"
        "	movs r0, #0x2c\n\t"
        "	add sl, r0\n\t"
        "	mov r0, sl\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	mov r1, sl\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r0, [r7]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	movs r1, #0x10\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r7]\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080939EC: .4byte gUnknown_84E6410\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 maybe_shadow_1(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 distance, u8 type)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldr r0, [sp, #0x10]\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_08093934\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl GetJumpInPlaceTurnAroundMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl npc_apply_anim_looping\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DoShadowFieldEffect\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 sub_08093A34(struct ObjectEvent *objectEvent, struct Sprite *sprite, u32 a)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	adds r4, r2, #0\n\t"
        "	ldr r1, _08093AC0\n\t"
        "	add r0, sp, #4\n\t"
        "	movs r2, #6\n\t"
        "	bl memcpy\n\t"
        "	adds r0, r7, #0\n\t"
        "	bl _call_via_r4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08093AC4\n\t"
        "	movs r1, #0x36\n\t"
        "	ldrsh r0, [r7, r1]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, sp\n\t"
        "	adds r0, #4\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08093AC4\n\t"
        "	add r4, sp, #0xc\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4]\n\t"
        "	mov r5, sp\n\t"
        "	adds r5, #0xe\n\t"
        "	strh r0, [r5]\n\t"
        "	ldrb r0, [r6, #0x18]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r1, [r7, r2]\n\t"
        "	lsls r1, r1, #1\n\t"
        "	add r1, sp\n\t"
        "	adds r1, #4\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r3, [r1, r2]\n\t"
        "	str r3, [sp]\n\t"
        "	adds r1, r4, #0\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl MoveCoordsInDirection\n\t"
        "	ldrh r1, [r4]\n\t"
        "	ldrh r0, [r6, #0x10]\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	ldrh r2, [r5]\n\t"
        "	ldrh r0, [r6, #0x12]\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl ShiftEventObjectCoords\n\t"
        "	ldrb r0, [r6]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	movs r1, #0x10\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	b _08093AE8\n\t"
        "	.align 2, 0\n\t"
        "_08093AC0: .4byte gUnknown_84E6416\n\t"
        "_08093AC4:\n\t"
        "	mov r1, r8\n\t"
        "	cmp r1, #0xff\n\t"
        "	bne _08093AE8\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl ShiftStillEventObjectCoords\n\t"
        "	ldrb r0, [r6]\n\t"
        "	movs r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	movs r1, #0x20\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r6]\n\t"
        "	adds r2, r7, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "_08093AE8:\n\t"
        "	mov r0, r8\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void sub_080971CC(struct ObjectEvent *objectEvent);
void sub_08097254(struct ObjectEvent *objectEvent);

static u8 DoJumpAnimStep(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return sub_08093A34(objectEvent, sprite, (u32)sub_080971CC + 1);
}

static u8 DoJumpSpecialAnimStep(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return sub_08093A34(objectEvent, sprite, (u32)sub_08097254 + 1);
}

static bool8 DoJumpAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnimStep(objectEvent, sprite) == JUMP_FINISHED)
        return TRUE;
    return FALSE;
}

static bool8 DoJumpSpecialAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpSpecialAnimStep(objectEvent, sprite) == JUMP_FINISHED)
        return TRUE;
    return FALSE;
}

static bool8 DoJumpInPlaceAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    switch (DoJumpAnimStep(objectEvent, sprite))
    {
    case JUMP_FINISHED:
        return TRUE;
    case JUMP_HALFWAY:
        SetEventObjectDirection(objectEvent, GetOppositeDirection(objectEvent->movementDirection));
        obj_npc_animation_step(objectEvent, sprite, GetJumpInPlaceTurnAroundMovementAction(objectEvent->facingDirection));
    default:
        return FALSE;
    }
}



bool8 MovementAction_Jump2Down_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_SOUTH, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_Jump2Down_Step1(objectEvent, sprite);
}

bool8 MovementAction_Jump2Down_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Jump2Up_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_NORTH, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_Jump2Up_Step1(objectEvent, sprite);
}

bool8 MovementAction_Jump2Up_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Jump2Left_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_WEST, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_Jump2Left_Step1(objectEvent, sprite);
}

bool8 MovementAction_Jump2Left_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Jump2Right_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_EAST, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_Jump2Right_Step1(objectEvent, sprite);
}

bool8 MovementAction_Jump2Right_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

void InitMovementDelay(struct Sprite *sprite, u16 delay)
{
    sprite->sActionFuncId = 1;
    sprite->data[3] = delay;
}

bool8 MovementAction_Delay_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (--sprite->data[3] == 0)
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}


bool8 MovementAction_Delay1_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementDelay(sprite, 1);
    return MovementAction_Delay_Step1(objectEvent, sprite);
}

bool8 MovementAction_Delay2_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementDelay(sprite, 2);
    return MovementAction_Delay_Step1(objectEvent, sprite);
}

bool8 MovementAction_Delay4_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementDelay(sprite, 4);
    return MovementAction_Delay_Step1(objectEvent, sprite);
}

bool8 MovementAction_Delay8_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementDelay(sprite, 8);
    return MovementAction_Delay_Step1(objectEvent, sprite);
}

bool8 MovementAction_Delay16_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementDelay(sprite, 0x10);
    return MovementAction_Delay_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_SOUTH, MOVE_SPEED_FAST_1);
    return MovementAction_WalkFastDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_NORTH, MOVE_SPEED_FAST_1);
    return MovementAction_WalkFastUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_WEST, MOVE_SPEED_FAST_1);
    return MovementAction_WalkFastLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFastRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_EAST, MOVE_SPEED_FAST_1);
    return MovementAction_WalkFastRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFastRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

__attribute__((naked)) bool8 sub_08093EC4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 animNum, u16 delay)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	mov r8, r0\n\t"
        "	adds r6, r1, #0\n\t"
        "	adds r1, r2, #0\n\t"
        "	adds r4, r3, #0\n\t"
        "	ldr r5, [sp, #0x14]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	bl SetEventObjectDirection\n\t"
        "	mov r0, r8\n\t"
        "	adds r1, r6, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl npc_apply_anim_looping\n\t"
        "	adds r2, r6, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r6, #0x32]\n\t"
        "	strh r5, [r6, #0x34]\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_WalkInPlace_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (--sprite->data[3] == 0)
    {
        sprite->sActionFuncId = 2;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkInPlaceSlow_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sprite->data[3] & 1)
        sprite->animDelayCounter++;
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceSlowDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_SOUTH, GetJumpInPlaceTurnAroundMovementAction(DIR_SOUTH), 32);
    return MovementAction_WalkInPlaceSlow_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceSlowUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_NORTH, GetJumpInPlaceTurnAroundMovementAction(DIR_NORTH), 32);
    return MovementAction_WalkInPlaceSlow_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceSlowLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_WEST, GetJumpInPlaceTurnAroundMovementAction(DIR_WEST), 32);
    return MovementAction_WalkInPlaceSlow_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceSlowRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_EAST, GetJumpInPlaceTurnAroundMovementAction(DIR_EAST), 32);
    return MovementAction_WalkInPlaceSlow_Step1(objectEvent, sprite);
}


bool8 MovementAction_WalkInPlaceNormalDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_SOUTH, GetJumpInPlaceTurnAroundMovementAction(DIR_SOUTH), 16);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceNormalUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_NORTH, GetJumpInPlaceTurnAroundMovementAction(DIR_NORTH), 16);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceNormalLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_WEST, GetJumpInPlaceTurnAroundMovementAction(DIR_WEST), 16);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceNormalRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_EAST, GetJumpInPlaceTurnAroundMovementAction(DIR_EAST), 16);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_SOUTH, GetJumpMovementAction(DIR_SOUTH), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_NORTH, GetJumpMovementAction(DIR_NORTH), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_WEST, GetJumpMovementAction(DIR_WEST), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFastRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_EAST, GetJumpMovementAction(DIR_EAST), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFasterDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_SOUTH, GetJumpSpecialMovementAction(DIR_SOUTH), 4);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFasterUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_NORTH, GetJumpSpecialMovementAction(DIR_NORTH), 4);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFasterLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_WEST, GetJumpSpecialMovementAction(DIR_WEST), 4);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkInPlaceFasterRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_EAST, GetJumpSpecialMovementAction(DIR_EAST), 4);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_RideWaterCurrentDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_SOUTH, MOVE_SPEED_FAST_2);
    return MovementAction_RideWaterCurrentDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_RideWaterCurrentDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RideWaterCurrentUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_NORTH, MOVE_SPEED_FAST_2);
    return MovementAction_RideWaterCurrentUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_RideWaterCurrentUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RideWaterCurrentLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_WEST, MOVE_SPEED_FAST_2);
    return MovementAction_RideWaterCurrentLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_RideWaterCurrentLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RideWaterCurrentRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_EAST, MOVE_SPEED_FAST_2);
    return MovementAction_RideWaterCurrentRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_RideWaterCurrentRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}


bool8 MovementAction_WalkFasterDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_SOUTH, MOVE_SPEED_FASTER);
    return MovementAction_WalkFasterDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFasterDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFasterUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_NORTH, MOVE_SPEED_FASTER);
    return MovementAction_WalkFasterUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFasterUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFasterLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_WEST, MOVE_SPEED_FASTER);
    return MovementAction_WalkFasterLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFasterLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkFasterRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_EAST, MOVE_SPEED_FASTER);
    return MovementAction_WalkFasterRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkFasterRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_SOUTH, MOVE_SPEED_FASTEST);
    return MovementAction_SlideDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_SlideDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_NORTH, MOVE_SPEED_FASTEST);
    return MovementAction_SlideUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_SlideUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_WEST, MOVE_SPEED_FASTEST);
    return MovementAction_SlideLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_SlideLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_SlideRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_EAST, MOVE_SPEED_FASTEST);
    return MovementAction_SlideRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_SlideRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartRunningAnim(objectEvent, sprite, DIR_SOUTH);
    return MovementAction_PlayerRunDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_PlayerRunDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartRunningAnim(objectEvent, sprite, DIR_NORTH);
    return MovementAction_PlayerRunUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_PlayerRunUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}


bool8 MovementAction_PlayerRunLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartRunningAnim(objectEvent, sprite, DIR_WEST);
    return MovementAction_PlayerRunLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_PlayerRunLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_PlayerRunRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartRunningAnim(objectEvent, sprite, DIR_EAST);
    return MovementAction_PlayerRunRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_PlayerRunRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

void StartSpriteAnimInDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 animNum)
{
    SetAndStartSpriteAnim(sprite, animNum, 0);
    SetEventObjectDirection(objectEvent, direction);
    sprite->sActionFuncId = 1;
}

bool8 MovementAction_StartAnimInDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, objectEvent->movementDirection, sprite->animNum);
    return FALSE;
}

bool8 MovementAction_WaitSpriteAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (SpriteAnimEnded(sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

__attribute__((naked)) bool8 InitJumpSpecial(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r4, r2, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	movs r1, #0\n\t"
        "	str r1, [sp]\n\t"
        "	adds r1, r5, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	movs r3, #1\n\t"
        "	bl sub_08093934\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetRideWaterCurrentMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_JumpSpecialDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitJumpSpecial(objectEvent, sprite, DIR_SOUTH);
    return MovementAction_JumpSpecialDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpSpecialDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 result = DoJumpSpecialAnim(objectEvent, sprite);

    if (result)
    {
        sprite->sActionFuncId = 2;
        objectEvent->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpSpecialUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitJumpSpecial(objectEvent, sprite, DIR_NORTH);
    return MovementAction_JumpSpecialUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpSpecialUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 result = DoJumpSpecialAnim(objectEvent, sprite);

    if (result)
    {
        sprite->sActionFuncId = 2;
        objectEvent->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpSpecialLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitJumpSpecial(objectEvent, sprite, DIR_WEST);
    return MovementAction_JumpSpecialLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpSpecialLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 result = DoJumpSpecialAnim(objectEvent, sprite);

    if (result)
    {
        sprite->sActionFuncId = 2;
        objectEvent->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpSpecialRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitJumpSpecial(objectEvent, sprite, DIR_EAST);
    return MovementAction_JumpSpecialRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpSpecialRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 result = DoJumpSpecialAnim(objectEvent, sprite);

    if (result)
    {
        sprite->sActionFuncId = 2;
        objectEvent->landingJump = FALSE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_FacePlayer_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 playerObjectId;

    if (!TryGetObjectEventIdByLocalIdAndMap(LOCALID_PLAYER, 0, 0, &playerObjectId))
        FaceDirection(objectEvent, sprite, GetDirectionToFace(objectEvent->currentCoords.x,
                                                             objectEvent->currentCoords.y,
                                                             gObjectEvents[playerObjectId].currentCoords.x,
                                                             gObjectEvents[playerObjectId].currentCoords.y));
    sprite->sActionFuncId = 1;
    return TRUE;
}

bool8 MovementAction_FaceAwayPlayer_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 playerObjectId;

    if (!TryGetObjectEventIdByLocalIdAndMap(LOCALID_PLAYER, 0, 0, &playerObjectId))
        FaceDirection(objectEvent, sprite, GetOppositeDirection(GetDirectionToFace(objectEvent->currentCoords.x,
                                                                                   objectEvent->currentCoords.y,
                                                                                   gObjectEvents[playerObjectId].currentCoords.x,
                                                                                   gObjectEvents[playerObjectId].currentCoords.y)));
    sprite->sActionFuncId = 1;
    return TRUE;
}


bool8 MovementAction_LockFacingDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->facingDirectionLocked = TRUE;
    sprite->sActionFuncId = 1;
    return TRUE;
}



bool8 MovementAction_UnlockFacingDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->facingDirectionLocked = FALSE;
    sprite->sActionFuncId = 1;
    return TRUE;
}



bool8 MovementAction_JumpDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_SOUTH, 1, JUMP_TYPE_NORMAL);
    return MovementAction_JumpDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_NORTH, JUMP_DISTANCE_NORMAL, JUMP_TYPE_NORMAL);
    return MovementAction_JumpUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_WEST, JUMP_DISTANCE_NORMAL, JUMP_TYPE_NORMAL);
    return MovementAction_JumpLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_EAST, JUMP_DISTANCE_NORMAL, JUMP_TYPE_NORMAL);
    return MovementAction_JumpRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_SOUTH, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_HIGH);
    return MovementAction_JumpInPlaceDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_NORTH, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_HIGH);
    return MovementAction_JumpInPlaceUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_WEST, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_HIGH);
    return MovementAction_JumpInPlaceLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_EAST, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_HIGH);
    return MovementAction_JumpInPlaceRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceDownUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_SOUTH, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_NORMAL);
    return MovementAction_JumpInPlaceDownUp_Step1(objectEvent, sprite);
}

__attribute__((naked)) bool8 MovementAction_JumpInPlaceDownUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl DoJumpInPlaceAnim\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08094C88\n\t"
        "	movs r0, #0\n\t"
        "	b _08094C98\n\t"
        "_08094C88:\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r4, #2]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_08094C98:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_JumpInPlaceUpDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_NORTH, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_NORMAL);
    return MovementAction_JumpInPlaceUpDown_Step1(objectEvent, sprite);
}

__attribute__((naked)) bool8 MovementAction_JumpInPlaceUpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl DoJumpInPlaceAnim\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08094CE0\n\t"
        "	movs r0, #0\n\t"
        "	b _08094CF0\n\t"
        "_08094CE0:\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r4, #2]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_08094CF0:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}


bool8 MovementAction_JumpInPlaceLeftRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_WEST, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_NORMAL);
    return MovementAction_JumpInPlaceLeftRight_Step1(objectEvent, sprite);
}

__attribute__((naked)) bool8 MovementAction_JumpInPlaceLeftRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl DoJumpInPlaceAnim\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08094D38\n\t"
        "	movs r0, #0\n\t"
        "	b _08094D48\n\t"
        "_08094D38:\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r4, #2]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_08094D48:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_JumpInPlaceRightLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_EAST, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_NORMAL);
    return MovementAction_JumpInPlaceRightLeft_Step1(objectEvent, sprite);
}

__attribute__((naked)) bool8 MovementAction_JumpInPlaceRightLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl DoJumpInPlaceAnim\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08094D90\n\t"
        "	movs r0, #0\n\t"
        "	b _08094DA0\n\t"
        "_08094D90:\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r4, #2]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_08094DA0:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_FaceOriginalDirection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FaceDirection(objectEvent, sprite, gInitialMovementTypeFacingDirections[objectEvent->movementType]);
    return TRUE;
}


bool8 MovementAction_NurseJoyBowDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_SOUTH, ANIM_NURSE_BOW);
    return FALSE;
}



bool8 MovementAction_EnableJumpLandingGroundEffect_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->disableJumpLandingGroundEffect = FALSE;
    sprite->sActionFuncId = 1;
    return TRUE;
}



bool8 MovementAction_DisableJumpLandingGroundEffect_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->disableJumpLandingGroundEffect = TRUE;
    sprite->sActionFuncId = 1;
    return TRUE;
}



bool8 MovementAction_DisableAnimation_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->inanimate = TRUE;
    sprite->sActionFuncId = 1;
    return TRUE;
}


bool8 MovementAction_RestoreAnimation_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->inanimate = GetObjectEventGraphicsInfo(objectEvent->graphicsId)->inanimate;
    sprite->sActionFuncId = 1;
    return TRUE;
}


bool8 MovementAction_SetInvisible_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->invisible = TRUE;
    sprite->sActionFuncId = 1;
    return TRUE;
}



bool8 MovementAction_SetVisible_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->invisible = FALSE;
    sprite->sActionFuncId = 1;
    return TRUE;
}


bool8 MovementAction_EmoteExclamationMark_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_EXCLAMATION_MARK_ICON);
    sprite->sActionFuncId = 1;
    return TRUE;
}

bool8 MovementAction_EmoteQuestionMark_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_QUESTION_MARK_ICON);
    sprite->sActionFuncId = 1;
    return TRUE;
}

bool8 MovementAction_EmoteHeart_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    FieldEffectStart(FLDEFF_HEART_ICON);
    sprite->sActionFuncId = 1;
    return TRUE;
}

bool8 MovementAction_RevealTrainer_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (objectEvent->movementType == MOVEMENT_TYPE_BURIED)
    {
        sub_080B3CD0(objectEvent);
        return FALSE;
    }
    if (objectEvent->movementType != MOVEMENT_TYPE_TREE_DISGUISE && objectEvent->movementType != MOVEMENT_TYPE_MOUNTAIN_DISGUISE)
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    StartRevealDisguise(objectEvent);
    sprite->sActionFuncId = 1;
    return MovementAction_RevealTrainer_Step1(objectEvent, sprite);
}

bool8 MovementAction_RevealTrainer_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 revealed = UpdateRevealDisguise(objectEvent);

    if (revealed)
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_RockSmashBreak_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    SetAndStartSpriteAnim(sprite, 1, 0);
    sprite->sActionFuncId = 1;
    return FALSE;
}

bool8 MovementAction_RockSmashBreak_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (SpriteAnimEnded(sprite))
    {
        SetMovementDelay(sprite, 32);
        sprite->sActionFuncId = 2;
    }
    return FALSE;
}

bool8 MovementAction_RockSmashBreak_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 delayEnded;

    objectEvent->invisible ^= TRUE;
    delayEnded = WaitForMovementDelay(sprite);
    if (delayEnded)
    {
        objectEvent->invisible = TRUE;
        sprite->sActionFuncId = 3;
    }
    return FALSE;
}


bool8 MovementAction_CutTree_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    SetAndStartSpriteAnim(sprite, 1, 0);
    sprite->sActionFuncId = 1;
    return FALSE;
}

bool8 MovementAction_CutTree_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 animEnded = SpriteAnimEnded(sprite);

    if (animEnded)
    {
        SetMovementDelay(sprite, 32);
        sprite->sActionFuncId = 2;
    }
    return FALSE;
}

bool8 MovementAction_CutTree_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 delayEnded;

    objectEvent->invisible ^= TRUE;
    delayEnded = WaitForMovementDelay(sprite);
    if (delayEnded)
    {
        objectEvent->invisible = TRUE;
        sprite->sActionFuncId = 3;
    }
    return FALSE;
}


bool8 MovementAction_SetFixedPriority_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->fixedPriority = TRUE;
    sprite->sActionFuncId = 1;
    return TRUE;
}



bool8 MovementAction_ClearFixedPriority_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->fixedPriority = FALSE;
    sprite->sActionFuncId = 1;
    return TRUE;
}


bool8 MovementAction_InitAffineAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
    InitSpriteAffineAnim(sprite);
    sprite->affineAnimPaused = TRUE;
    sprite->subspriteMode = SUBSPRITES_OFF;
    return TRUE;
}

bool8 MovementAction_ClearAffineAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    FreeOamMatrix(sprite->oam.matrixNum);
    sprite->oam.affineMode = ST_OAM_AFFINE_OFF;
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
    return TRUE;
}
bool8 MovementAction_HideReflection_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->hideReflection = TRUE;
    return TRUE;
}



bool8 MovementAction_Unknown2_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->hideReflection = FALSE;
    return TRUE;
}

bool8 MovementAction_WalkDownStartAffine_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_SOUTH);
    sprite->affineAnimPaused = FALSE;
    StartSpriteAffineAnimIfDifferent(sprite, 0);
    return MovementAction_WalkDownStartAffine_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkDownStartAffine_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlow(objectEvent, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkDownAffine_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_SOUTH);
    sprite->affineAnimPaused = FALSE;
    ChangeSpriteAffineAnimIfDifferent(sprite, 1);
    return MovementAction_WalkDownAffine_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkDownAffine_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlow(objectEvent, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkLeftAffine_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_WEST, MOVE_SPEED_FAST_1);
    sprite->affineAnimPaused = FALSE;
    ChangeSpriteAffineAnimIfDifferent(sprite, 2);
    return MovementAction_WalkLeftAffine_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkLeftAffine_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkRightAffine_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitMovementNormal(objectEvent, sprite, DIR_EAST, MOVE_SPEED_FAST_1);
    sprite->affineAnimPaused = FALSE;
    ChangeSpriteAffineAnimIfDifferent(sprite, 3);
    return MovementAction_WalkRightAffine_Step1(objectEvent, sprite);
}

bool8 MovementAction_WalkRightAffine_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->affineAnimPaused = TRUE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

void AcroWheelieFaceDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    SetEventObjectDirection(objectEvent, direction);
    ShiftStillEventObjectCoords(objectEvent);
    obj_npc_animation_step(objectEvent, sprite, GetWalkInPlaceFastestMovementAction(direction));
    sprite->animPaused = TRUE;
    sprite->sActionFuncId = 1;
}


bool8 MovementAction_AcroWheelieFaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    AcroWheelieFaceDirection(objectEvent, sprite, DIR_SOUTH);
    return TRUE;
}


bool8 MovementAction_AcroWheelieFaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    AcroWheelieFaceDirection(objectEvent, sprite, DIR_NORTH);
    return TRUE;
}


bool8 MovementAction_AcroWheelieFaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    AcroWheelieFaceDirection(objectEvent, sprite, DIR_WEST);
    return TRUE;
}


bool8 MovementAction_AcroWheelieFaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    AcroWheelieFaceDirection(objectEvent, sprite, DIR_EAST);
    return TRUE;
}




bool8 MovementAction_AcroPopWheelieDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_SOUTH, GetSlideMovementAction(DIR_SOUTH));
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_NORTH, GetSlideMovementAction(DIR_NORTH));
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_WEST, GetSlideMovementAction(DIR_WEST));
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_EAST, GetSlideMovementAction(DIR_EAST));
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieFaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_SOUTH, GetWalkFastestMovementAction(DIR_SOUTH));
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieFaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_NORTH, GetWalkFastestMovementAction(DIR_NORTH));
    return FALSE;
}

__attribute__((naked)) bool8 sub_08095388(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	movs r0, #3\n\t"
        "	bl GetWalkFastestMovementAction\n\t"
        "	adds r3, r0, #0\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	movs r2, #3\n\t"
        "	bl StartSpriteAnimInDirection\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_AcroEndWheelieFaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_EAST, GetWalkFastestMovementAction(DIR_EAST));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_SOUTH, GetWalkInPlaceFastMovementAction(DIR_SOUTH));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_NORTH, GetWalkInPlaceFastMovementAction(DIR_NORTH));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_WEST, GetWalkInPlaceFastMovementAction(DIR_WEST));
    return FALSE;
}

bool8 MovementAction_UnusedAcroActionRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_EAST, GetWalkInPlaceFastMovementAction(DIR_EAST));
    return FALSE;
}

__attribute__((naked)) bool8 InitFigure8Anim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl InitSpriteForFigure8Anim\n\t"
        "	adds r4, #0x2c\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}
__attribute__((naked)) bool8 sub_0809547C(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl AnimateSpriteInFigure8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08095492\n\t"
        "	movs r0, #0\n\t"
        "	b _080954AE\n\t"
        "_08095492:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ShiftStillEventObjectCoords\n\t"
        "	ldrb r0, [r4]\n\t"
        "	movs r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	adds r2, r5, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r0, [r2]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r0, #1\n\t"
        "_080954AE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}





bool8 MovementAction_Figure8_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitFigure8Anim(objectEvent, sprite);
    sprite->sActionFuncId = 1;
    return sub_080954D4(objectEvent, sprite);
}

__attribute__((naked)) bool8 sub_080954D4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	bl sub_0809547C\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080954E6\n\t"
        "	movs r0, #0\n\t"
        "	b _080954EC\n\t"
        "_080954E6:\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r4, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_080954EC:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 sub_080954F4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 distance, u8 type)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r4, r2, #0\n\t"
        "	ldr r0, [sp, #0x14]\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	str r0, [sp]\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r2, r4, #0\n\t"
        "	bl sub_08093934\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetSlideMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl StartSpriteAnimIfDifferent\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl DoShadowFieldEffect\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_AcroWheelieHopFaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_SOUTH, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_LOW);
    return MovementAction_AcroWheelieHopFaceDown_Step1(objectEvent, sprite);
}


bool8 MovementAction_AcroWheelieHopFaceDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopFaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_NORTH, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_LOW);
    return MovementAction_AcroWheelieHopFaceUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopFaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_WEST, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_LOW);
    return MovementAction_AcroWheelieHopFaceLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopFaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_EAST, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_LOW);
    return MovementAction_AcroWheelieHopFaceRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopFaceRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_SOUTH, JUMP_DISTANCE_NORMAL, JUMP_TYPE_LOW);
    return MovementAction_AcroWheelieHopDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_NORTH, JUMP_DISTANCE_NORMAL, JUMP_TYPE_LOW);
    return MovementAction_AcroWheelieHopUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_WEST, JUMP_DISTANCE_NORMAL, JUMP_TYPE_LOW);
    return MovementAction_AcroWheelieHopLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieHopRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_EAST, JUMP_DISTANCE_NORMAL, JUMP_TYPE_LOW);
    return MovementAction_AcroWheelieHopRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieHopRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_SOUTH, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_AcroWheelieJumpDown_Step1(objectEvent, sprite);
}

__attribute__((naked)) bool8 MovementAction_AcroWheelieJumpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl DoJumpAnim\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08095838\n\t"
        "	movs r0, #0\n\t"
        "	b _08095848\n\t"
        "_08095838:\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r4, #2]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_08095848:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_AcroWheelieJumpUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_NORTH, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_AcroWheelieJumpUp_Step1(objectEvent, sprite);
}

__attribute__((naked)) bool8 MovementAction_AcroWheelieJumpUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl DoJumpAnim\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08095890\n\t"
        "	movs r0, #0\n\t"
        "	b _080958A0\n\t"
        "_08095890:\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r4, #2]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_080958A0:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_AcroWheelieJumpLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_WEST, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_AcroWheelieJumpLeft_Step1(objectEvent, sprite);
}


__attribute__((naked)) bool8 MovementAction_AcroWheelieJumpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl DoJumpAnim\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080958E8\n\t"
        "	movs r0, #0\n\t"
        "	b _080958F8\n\t"
        "_080958E8:\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r4, #2]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_080958F8:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_AcroWheelieJumpRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_EAST, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_AcroWheelieJumpRight_Step1(objectEvent, sprite);
}

__attribute__((naked)) bool8 MovementAction_AcroWheelieJumpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl DoJumpAnim\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08095940\n\t"
        "	movs r0, #0\n\t"
        "	b _08095950\n\t"
        "_08095940:\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	movs r1, #0x41\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r0\n\t"
        "	strb r1, [r4, #2]\n\t"
        "	movs r0, #2\n\t"
        "	strh r0, [r5, #0x32]\n\t"
        "	movs r0, #1\n\t"
        "_08095950:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_AcroWheelieInPlaceDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_SOUTH, GetWalkInPlaceFastestMovementAction(DIR_SOUTH), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieInPlaceUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_NORTH, GetWalkInPlaceFastestMovementAction(DIR_NORTH), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieInPlaceLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_WEST, GetWalkInPlaceFastestMovementAction(DIR_WEST), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieInPlaceRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_08093EC4(objectEvent, sprite, DIR_EAST, GetWalkInPlaceFastestMovementAction(DIR_EAST), 8);
    return MovementAction_WalkInPlace_Step1(objectEvent, sprite);
}

__attribute__((naked)) bool8 InitAcroPopWheelieMove(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a, u8 b)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	bl npc_apply_direction\n\t"
        "	ldrb r0, [r5, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl GetSlideMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl SeekSpriteAnim\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_AcroPopWheelieMoveDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroPopWheelieMove(objectEvent, sprite, DIR_SOUTH, 1);
    return MovementAction_AcroPopWheelieMoveDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieMoveUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroPopWheelieMove(objectEvent, sprite, DIR_NORTH, 1);
    return MovementAction_AcroPopWheelieMoveUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroPopWheelieMoveLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroPopWheelieMove(objectEvent, sprite, DIR_WEST, 1);
    return MovementAction_AcroPopWheelieMoveLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroPopWheelieMoveLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}


__attribute__((naked)) bool8 sub_08095B30(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	movs r2, #4\n\t"
        "	movs r3, #1\n\t"
        "	bl InitAcroPopWheelieMove\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl MovementAction_AcroPopWheelieMoveRight_Step1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}



bool8 MovementAction_AcroPopWheelieMoveRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

__attribute__((naked)) bool8 InitAcroWheelieMove(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a, u8 b)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	bl npc_apply_direction\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl GetWalkInPlaceFastestMovementAction\n\t"
        "	adds r2, r0, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl npc_apply_anim_looping\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_AcroWheelieMoveDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroWheelieMove(objectEvent, sprite, DIR_SOUTH, 1);
    return MovementAction_AcroWheelieMoveDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieMoveDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieMoveUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroWheelieMove(objectEvent, sprite, DIR_NORTH, 1);
    return MovementAction_AcroWheelieMoveUp_Step1(objectEvent, sprite);
}


bool8 MovementAction_AcroWheelieMoveUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieMoveLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroWheelieMove(objectEvent, sprite, DIR_WEST, 1);
    return MovementAction_AcroWheelieMoveLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieMoveLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieMoveRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroWheelieMove(objectEvent, sprite, DIR_EAST, 1);
    return MovementAction_AcroWheelieMoveRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieMoveRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

__attribute__((naked)) bool8 InitAcroEndWheelie(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a, u8 b)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	bl npc_apply_direction\n\t"
        "	ldrb r0, [r5, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl GetWalkFastestMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl SeekSpriteAnim\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 MovementAction_AcroEndWheelieMoveDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroEndWheelie(objectEvent, sprite, DIR_SOUTH, 1);
    return MovementAction_AcroEndWheelieMoveDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieMoveUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroEndWheelie(objectEvent, sprite, DIR_NORTH, 1);
    return MovementAction_AcroEndWheelieMoveUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieMoveLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroEndWheelie(objectEvent, sprite, DIR_WEST, 1);
    return MovementAction_AcroEndWheelieMoveLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroEndWheelieMoveRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroEndWheelie(objectEvent, sprite, DIR_EAST, 1);
    return MovementAction_AcroEndWheelieMoveRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroEndWheelieMoveRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateMovementNormal(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_Levitate_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    CreateLevitateMovementTask(objectEvent);
    sprite->sActionFuncId = 1;
    return TRUE;
}

bool8 MovementAction_StopLevitate_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    DestroyExtraMovementTask(objectEvent->warpArrowSpriteId);
    sprite->y2 = 0;
    sprite->sActionFuncId = 1;
    return TRUE;
}

__attribute__((naked)) bool8 MovementAction_DestroyExtraTaskIfAtTop_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r2, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	movs r1, #0x26\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08095E16\n\t"
        "	movs r0, #0\n\t"
        "	b _08095E20\n\t"
        "_08095E16:\n\t"
        "	ldrb r0, [r2, #0x1b]\n\t"
        "	bl DestroyExtraMovementTask\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r4, #0x32]\n\t"
        "_08095E20:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

bool8 sub_08095E28(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return 1;
}

bool8 MovementAction_PauseSpriteAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->animPaused = TRUE;
    return TRUE;
}


__attribute__((naked)) void UpdateEventObjectSpriteAnimPause(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldrb r0, [r0, #1]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08095E52\n\t"
        "	adds r0, r1, #0\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "_08095E52:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void TryEnableEventObjectAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldrb r3, [r4, #1]\n\t"
        "	lsls r0, r3, #0x1c\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08095E80\n\t"
        "	adds r2, r1, #0\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r3\n\t"
        "	movs r1, #9\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4, #1]\n\t"
        "_08095E80:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void UpdateObjectEventVisibility(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    UpdateObjectEventOffscreen(objectEvent, sprite);
    UpdateEventObjSpriteVisibility(objectEvent, sprite);
}

__attribute__((naked)) void UpdateObjectEventOffscreen(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldrb r1, [r5, #1]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r5, #1]\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #2\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08095F04\n\t"
        "	ldrh r1, [r4, #0x24]\n\t"
        "	ldrh r0, [r4, #0x20]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x28\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	ldr r2, _08095EFC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r2, [r2]\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r3, r0, #0x10\n\t"
        "	ldrh r1, [r4, #0x26]\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x29\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	ldr r2, _08095F00\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrh r2, [r2]\n\t"
        "	adds r0, r0, r2\n\t"
        "	b _08095F2C\n\t"
        "	.align 2, 0\n\t"
        "_08095EFC: .4byte gSpriteCoordOffsetX\n\t"
        "_08095F00: .4byte gSpriteCoordOffsetY\n\t"
        "_08095F04:\n\t"
        "	ldrh r1, [r4, #0x24]\n\t"
        "	ldrh r0, [r4, #0x20]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x28\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r3, r0, #0x10\n\t"
        "	ldrh r1, [r4, #0x26]\n\t"
        "	ldrh r0, [r4, #0x22]\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x29\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	asrs r0, r0, #0x18\n\t"
        "	adds r0, r0, r1\n\t"
        "_08095F2C:\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r2, r0, #0x10\n\t"
        "	ldrh r0, [r6, #8]\n\t"
        "	adds r0, r0, r3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	ldrh r0, [r6, #0xa]\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r4, r0, #0x10\n\t"
        "	lsls r0, r3, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0xff\n\t"
        "	bgt _08095F54\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	movs r1, #0x10\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	cmp r0, r1\n\t"
        "	bge _08095F5C\n\t"
        "_08095F54:\n\t"
        "	ldrb r0, [r5, #1]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r5, #1]\n\t"
        "_08095F5C:\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0xaf\n\t"
        "	bgt _08095F70\n\t"
        "	lsls r0, r4, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	movs r1, #0x10\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	cmp r0, r1\n\t"
        "	bge _08095F78\n\t"
        "_08095F70:\n\t"
        "	ldrb r0, [r5, #1]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r5, #1]\n\t"
        "_08095F78:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void UpdateEventObjSpriteVisibility(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r2, r1, #0\n\t"
        "	adds r2, #0x3e\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r3, #5\n\t"
        "	rsbs r3, r3, #0\n\t"
        "	ands r3, r1\n\t"
        "	strb r3, [r2]\n\t"
        "	ldrb r1, [r0, #1]\n\t"
        "	movs r0, #0x60\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08095FA2\n\t"
        "	movs r1, #4\n\t"
        "	adds r0, r3, #0\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "_08095FA2:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetAllGroundEffectFlags_OnSpawn(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl EventObjectUpdateMetatileBehaviors\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_Reflection\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_TallGrassOnSpawn\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl sub_0809615C\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_SandHeap\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_ShallowFlowingWater\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_ShortGrass\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_HotSprings\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetAllGroundEffectFlags_OnBeginStep(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl EventObjectUpdateMetatileBehaviors\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_Reflection\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_LongGrassOnSpawn\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_LongGrassOnBeginStep\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_Tracks\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_SandHeap\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_ShallowFlowingWater\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_Puddle\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_ShortGrass\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_HotSprings\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetAllGroundEffectFlags_OnFinishStep(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	bl EventObjectUpdateMetatileBehaviors\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_ShallowFlowingWater\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_SandHeap\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_Puddle\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_Ripple\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_ShortGrass\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_HotSprings\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_Seaweed\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl GetGroundEffectFlags_JumpLanding\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void EventObjectUpdateMetatileBehaviors(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r1, #0x14\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r2, #0x16\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	strb r0, [r4, #0x1f]\n\t"
        "	movs r1, #0x10\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	strb r0, [r4, #0x1e]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_Reflection(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldr r0, _08096104\n\t"
        "	ldr r1, [r0, #4]\n\t"
        "	ldr r0, [r0]\n\t"
        "	str r0, [sp]\n\t"
        "	str r1, [sp, #4]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl EventObjectCheckForReflectiveSurface\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0\n\t"
        "	beq _08096108\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	lsls r0, r1, #0x1e\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08096112\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "	subs r0, r2, #1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, sp\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldr r0, [r0]\n\t"
        "	orrs r1, r0\n\t"
        "	str r1, [r5]\n\t"
        "	b _08096112\n\t"
        "	.align 2, 0\n\t"
        "_08096104: .4byte sReflectionFlags\n\t"
        "_08096108:\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	movs r0, #3\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "_08096112:\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_TallGrassOnSpawn(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldrb r0, [r0, #0x1e]\n\t"
        "	bl MetatileBehavior_IsTallGrass\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096134\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r1, #1\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r4]\n\t"
        "_08096134:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_LongGrassOnSpawn(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldrb r0, [r0, #0x1e]\n\t"
        "	bl MetatileBehavior_IsTallGrass\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096154\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r4]\n\t"
        "_08096154:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0809615C(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldrb r0, [r0, #0x1e]\n\t"
        "	bl MetatileBehavior_IsLongGrass\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096174\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r4]\n\t"
        "_08096174:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_LongGrassOnBeginStep(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldrb r0, [r0, #0x1e]\n\t"
        "	bl MetatileBehavior_IsLongGrass\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096194\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r4]\n\t"
        "_08096194:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_Tracks(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4, #0x1f]\n\t"
        "	bl MetatileBehavior_IsDeepSand\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080961B6\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #1\n\t"
        "	b _080961D2\n\t"
        "_080961B6:\n\t"
        "	ldrb r0, [r4, #0x1f]\n\t"
        "	bl MetatileBehavior_IsSandOrDeepSand\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080961CE\n\t"
        "	ldrb r0, [r4, #0x1f]\n\t"
        "	bl MetatileBehavior_IsFootprints\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080961D6\n\t"
        "_080961CE:\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r1, #0x80\n\t"
        "_080961D2:\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r5]\n\t"
        "_080961D6:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_SandHeap(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4, #0x1e]\n\t"
        "	bl MetatileBehavior_IsDeepSand\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809621A\n\t"
        "	ldrb r0, [r4, #0x1f]\n\t"
        "	bl MetatileBehavior_IsDeepSand\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809621A\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	lsls r0, r1, #0x1b\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08096224\n\t"
        "	movs r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x10\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r5]\n\t"
        "	b _08096224\n\t"
        "_0809621A:\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	movs r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "_08096224:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_ShallowFlowingWater(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4, #0x1e]\n\t"
        "	bl MetatileBehavior_IsShallowFlowingWater\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809624A\n\t"
        "	ldrb r0, [r4, #0x1f]\n\t"
        "	bl MetatileBehavior_IsShallowFlowingWater\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08096262\n\t"
        "_0809624A:\n\t"
        "	ldrb r0, [r4, #0x1e]\n\t"
        "	bl MetatileBehavior_IsPacifidlogLog\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096280\n\t"
        "	ldrb r0, [r4, #0x1f]\n\t"
        "	bl MetatileBehavior_IsPacifidlogLog\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096280\n\t"
        "_08096262:\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	lsls r0, r1, #0x1c\n\t"
        "	cmp r0, #0\n\t"
        "	blt _0809628A\n\t"
        "	movs r0, #9\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r1, #0x40\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r5]\n\t"
        "	b _0809628A\n\t"
        "_08096280:\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	movs r0, #9\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "_0809628A:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_Puddle(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4, #0x1e]\n\t"
        "	bl MetatileBehavior_IsPuddle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080962B8\n\t"
        "	ldrb r0, [r4, #0x1f]\n\t"
        "	bl MetatileBehavior_IsPuddle\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080962B8\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #3\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r5]\n\t"
        "_080962B8:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_Ripple(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldrb r0, [r0, #0x1e]\n\t"
        "	bl MetatileBehavior_HasRipples\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080962DA\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r4]\n\t"
        "_080962DA:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_ShortGrass(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4, #0x1e]\n\t"
        "	bl MetatileBehavior_IsShortGrass\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809631E\n\t"
        "	ldrb r0, [r4, #0x1f]\n\t"
        "	bl MetatileBehavior_IsShortGrass\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809631E\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	lsls r0, r1, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08096328\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xa\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r5]\n\t"
        "	b _08096328\n\t"
        "_0809631E:\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "_08096328:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_HotSprings(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4, #0x1e]\n\t"
        "	bl MetatileBehavior_IsHotSprings\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809636E\n\t"
        "	ldrb r0, [r4, #0x1f]\n\t"
        "	bl MetatileBehavior_IsHotSprings\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809636E\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	lsls r0, r1, #0x1a\n\t"
        "	cmp r0, #0\n\t"
        "	blt _08096378\n\t"
        "	movs r0, #0x21\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x20\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "	ldr r0, [r5]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xb\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r5]\n\t"
        "	b _08096378\n\t"
        "_0809636E:\n\t"
        "	ldrb r1, [r4, #2]\n\t"
        "	movs r0, #0x21\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "_08096378:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}


__attribute__((naked)) void GetGroundEffectFlags_Seaweed(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldrb r0, [r0, #0x1e]\n\t"
        "	bl MetatileBehavior_IsSeaweed\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809639A\n\t"
        "	ldr r0, [r4]\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #0xc\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r4]\n\t"
        "_0809639A:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetGroundEffectFlags_JumpLanding(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r7, r0, #0\n\t"
        "	adds r6, r1, #0\n\t"
        "	ldr r0, [r7]\n\t"
        "	ldr r1, _080963DC\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0x20\n\t"
        "	bne _080963F2\n\t"
        "	movs r5, #0\n\t"
        "	ldr r0, _080963E0\n\t"
        "	mov r8, r0\n\t"
        "_080963BA:\n\t"
        "	lsls r4, r5, #2\n\t"
        "	mov r0, r8\n\t"
        "	adds r1, r4, r0\n\t"
        "	ldrb r0, [r7, #0x1e]\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl _call_via_r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080963E8\n\t"
        "	ldr r0, _080963E4\n\t"
        "	adds r0, r4, r0\n\t"
        "	ldr r1, [r6]\n\t"
        "	ldr r0, [r0]\n\t"
        "	orrs r1, r0\n\t"
        "	str r1, [r6]\n\t"
        "	b _080963F2\n\t"
        "	.align 2, 0\n\t"
        "_080963DC: .4byte gUnknown_2000020\n\t"
        "_080963E0: .4byte sJumpLandingMetatileFuncs\n\t"
        "_080963E4: .4byte sJumpLandingFlags\n\t"
        "_080963E8:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	cmp r5, #5\n\t"
        "	bls _080963BA\n\t"
        "_080963F2:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 EventObjectCheckForReflectiveSurface(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sl\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6, r7}\n\t"
        "	sub sp, #8\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	movs r2, #8\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	adds r1, #8\n\t"
        "	lsls r1, r1, #0xc\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	str r1, [sp]\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	adds r0, #8\n\t"
        "	lsls r0, r0, #0xc\n\t"
        "	movs r4, #0\n\t"
        "	lsrs r2, r0, #0x10\n\t"
        "	str r2, [sp, #4]\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r4, r0\n\t"
        "	blt _08096432\n\t"
        "	b _08096538\n\t"
        "_08096432:\n\t"
        "	movs r0, #1\n\t"
        "	mov sl, r0\n\t"
        "_08096436:\n\t"
        "	movs r1, #0x10\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	add r1, sl\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	asrs r6, r4, #0x10\n\t"
        "	adds r1, r1, r6\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetReflectionTypeByMetatileBehavior\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r4\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0809653A\n\t"
        "	movs r1, #0x14\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	movs r2, #0x16\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	add r1, sl\n\t"
        "	adds r1, r1, r6\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetReflectionTypeByMetatileBehavior\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0809653A\n\t"
        "	movs r2, #1\n\t"
        "	ldr r1, [sp]\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r1, r0, #0x10\n\t"
        "	mov r8, r0\n\t"
        "	cmp r2, r1\n\t"
        "	bge _08096526\n\t"
        "	movs r0, #0x80\n\t"
        "	lsls r0, r0, #9\n\t"
        "	asrs r7, r0, #0x10\n\t"
        "_08096490:\n\t"
        "	movs r1, #0x10\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	lsls r1, r2, #0x10\n\t"
        "	asrs r4, r1, #0x10\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, r1, r6\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetReflectionTypeByMetatileBehavior\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0809653A\n\t"
        "	movs r1, #0x10\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	subs r0, r0, r4\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, r1, r6\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetReflectionTypeByMetatileBehavior\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0809653A\n\t"
        "	movs r1, #0x14\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	adds r0, r0, r4\n\t"
        "	movs r2, #0x16\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, r1, r6\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetReflectionTypeByMetatileBehavior\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0809653A\n\t"
        "	movs r1, #0x14\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	subs r0, r0, r4\n\t"
        "	movs r2, #0x16\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, r1, r6\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetReflectionTypeByMetatileBehavior\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0809653A\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r2, r0, #0x10\n\t"
        "	cmp r0, r8\n\t"
        "	blt _08096490\n\t"
        "_08096526:\n\t"
        "	movs r1, #0x80\n\t"
        "	lsls r1, r1, #9\n\t"
        "	add r1, sb\n\t"
        "	lsrs r4, r1, #0x10\n\t"
        "	ldr r2, [sp, #4]\n\t"
        "	lsls r0, r2, #0x10\n\t"
        "	cmp r1, r0\n\t"
        "	bge _08096538\n\t"
        "	b _08096436\n\t"
        "_08096538:\n\t"
        "	movs r0, #0\n\t"
        "_0809653A:\n\t"
        "	add sp, #8\n\t"
        "	pop {r3, r4, r5}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	mov sl, r5\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetReflectionTypeByMetatileBehavior(u32 metatileBehavior)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl MetatileBehavior_IsIce_2\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096562\n\t"
        "	movs r0, #1\n\t"
        "	b _08096574\n\t"
        "_08096562:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl MetatileBehavior_IsReflective\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08096572\n\t"
        "	movs r0, #0\n\t"
        "	b _08096574\n\t"
        "_08096572:\n\t"
        "	movs r0, #2\n\t"
        "_08096574:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) u8 GetLedgeJumpDirection(s16 x, s16 y, u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r3, r0, #0x10\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r1, r1, #0x10\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r4, r2, #0x18\n\t"
        "	cmp r4, #0\n\t"
        "	beq _080965C2\n\t"
        "	cmp r4, #4\n\t"
        "	bls _08096598\n\t"
        "	subs r0, r4, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "_08096598:\n\t"
        "	subs r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r0, r3, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _080965C8\n\t"
        "	lsls r1, r4, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldr r1, [r1]\n\t"
        "	bl _call_via_r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080965CC\n\t"
        "_080965C2:\n\t"
        "	movs r0, #0\n\t"
        "	b _080965D2\n\t"
        "	.align 2, 0\n\t"
        "_080965C8: .4byte sLedgeBehaviorFuncs\n\t"
        "_080965CC:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "_080965D2:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetEventObjectSpriteOamTableForLongGrass(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldrb r0, [r5]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	cmp r0, #0\n\t"
        "	blt _0809662C\n\t"
        "	ldrb r0, [r5, #0x1e]\n\t"
        "	bl MetatileBehavior_IsLongGrass\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809662C\n\t"
        "	ldrb r0, [r5, #0x1f]\n\t"
        "	bl MetatileBehavior_IsLongGrass\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0809662C\n\t"
        "	adds r4, #0x42\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r6, #0x40\n\t"
        "	rsbs r6, r6, #0\n\t"
        "	adds r0, r6, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	ldrb r0, [r5, #0xb]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	bl ElevationToPriority\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _0809662C\n\t"
        "	ldrb r0, [r4]\n\t"
        "	adds r1, r6, #0\n\t"
        "	ands r1, r0\n\t"
        "	movs r0, #5\n\t"
        "	orrs r1, r0\n\t"
        "	strb r1, [r4]\n\t"
        "_0809662C:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 IsZCoordMismatchAt(u8 elevation, s16 x, s16 y)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	lsrs r0, r1, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	lsrs r1, r2, #0x10\n\t"
        "	cmp r4, #0\n\t"
        "	beq _08096662\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	bl MapGridGetElevationAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096662\n\t"
        "	cmp r0, #0xf\n\t"
        "	beq _08096662\n\t"
        "	cmp r0, r4\n\t"
        "	bne _08096666\n\t"
        "_08096662:\n\t"
        "	movs r0, #0\n\t"
        "	b _08096668\n\t"
        "_08096666:\n\t"
        "	movs r0, #1\n\t"
        "_08096668:\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void UpdateEventObjectZCoordAndPriority(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4, #3]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	blt _080966BE\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl EventObjectUpdateZCoord\n\t"
        "	ldr r1, _080966C4\n\t"
        "	ldrb r2, [r4, #0xb]\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r0, r2, #0x1c\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r4, r5, #0\n\t"
        "	adds r4, #0x42\n\t"
        "	movs r1, #0x3f\n\t"
        "	ands r1, r0\n\t"
        "	ldrb r3, [r4]\n\t"
        "	movs r0, #0x40\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r3\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "	ldr r0, _080966C8\n\t"
        "	lsrs r2, r2, #0x1c\n\t"
        "	adds r2, r2, r0\n\t"
        "	movs r0, #3\n\t"
        "	ldrb r1, [r2]\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldrb r2, [r5, #5]\n\t"
        "	movs r0, #0xd\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r5, #5]\n\t"
        "_080966BE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080966C4: .4byte sElevationToSubspriteTableNum\n\t"
        "_080966C8: .4byte sElevationToPriority\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void InitObjectPriorityByZCoord(struct ObjectEvent *objectEvent, u8 elevation)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldr r2, _08096710\n\t"
        "	adds r2, r1, r2\n\t"
        "	ldrb r2, [r2]\n\t"
        "	movs r3, #0x42\n\t"
        "	adds r3, r3, r0\n\t"
        "	mov ip, r3\n\t"
        "	movs r3, #0x3f\n\t"
        "	ands r3, r2\n\t"
        "	mov r2, ip\n\t"
        "	ldrb r4, [r2]\n\t"
        "	movs r2, #0x40\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	ands r2, r4\n\t"
        "	orrs r2, r3\n\t"
        "	mov r3, ip\n\t"
        "	strb r2, [r3]\n\t"
        "	ldr r2, _08096714\n\t"
        "	adds r1, r1, r2\n\t"
        "	movs r3, #3\n\t"
        "	ldrb r2, [r1]\n\t"
        "	ands r2, r3\n\t"
        "	lsls r2, r2, #2\n\t"
        "	ldrb r3, [r0, #5]\n\t"
        "	movs r1, #0xd\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r1, r3\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0, #5]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096710: .4byte sElevationToSubspriteTableNum\n\t"
        "_08096714: .4byte sElevationToPriority\n\t"
        ".syntax divided\n\t"
    );
}

u8 ElevationToPriority(u8 elevation)
{
    return sElevationToPriority[elevation];
}

__attribute__((naked)) void EventObjectUpdateZCoord(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r1, #0x10\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	bl MapGridGetElevationAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	movs r1, #0x14\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	movs r2, #0x16\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	bl MapGridGetElevationAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r5, #0xf\n\t"
        "	beq _08096776\n\t"
        "	cmp r0, #0xf\n\t"
        "	beq _08096776\n\t"
        "	movs r3, #0xf\n\t"
        "	adds r0, r5, #0\n\t"
        "	ands r0, r3\n\t"
        "	ldrb r1, [r4, #0xb]\n\t"
        "	movs r2, #0x10\n\t"
        "	rsbs r2, r2, #0\n\t"
        "	ands r2, r1\n\t"
        "	orrs r2, r0\n\t"
        "	strb r2, [r4, #0xb]\n\t"
        "	cmp r5, #0\n\t"
        "	beq _08096776\n\t"
        "	cmp r5, #0xf\n\t"
        "	beq _08096776\n\t"
        "	lsls r0, r5, #4\n\t"
        "	ands r2, r3\n\t"
        "	orrs r2, r0\n\t"
        "	strb r2, [r4, #0xb]\n\t"
        "_08096776:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetObjectSubpriorityByElevation(u8 elevation, struct Sprite *sprite, u8 subpriority)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	adds r3, r1, #0\n\t"
        "	adds r3, #0x29\n\t"
        "	movs r5, #0\n\t"
        "	ldrsb r5, [r3, r5]\n\t"
        "	ldrh r4, [r1, #0x22]\n\t"
        "	ldr r3, _080967BC\n\t"
        "	subs r4, r4, r5\n\t"
        "	ldrh r3, [r3]\n\t"
        "	adds r4, r4, r3\n\t"
        "	adds r4, #8\n\t"
        "	movs r3, #0xff\n\t"
        "	ands r4, r3\n\t"
        "	lsrs r4, r4, #4\n\t"
        "	movs r3, #0x10\n\t"
        "	subs r3, r3, r4\n\t"
        "	lsls r3, r3, #0x11\n\t"
        "	ldr r4, _080967C0\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsrs r3, r3, #0x10\n\t"
        "	ldrb r0, [r0]\n\t"
        "	adds r3, r3, r0\n\t"
        "	adds r2, r2, r3\n\t"
        "	adds r1, #0x43\n\t"
        "	strb r2, [r1]\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080967BC: .4byte gSpriteCoordOffsetY\n\t"
        "_080967C0: .4byte sElevationToSubpriority\n\t"
        ".syntax divided\n\t"
    );
}

void ObjectEventUpdateSubpriority(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (objectEvent->fixedPriority)
        return;

    SetObjectSubpriorityByElevation(objectEvent->previousElevation, sprite, 1);
}

bool8 AreElevationsCompatible(u8 a, u8 b)
{
    if (a == ELEVATION_TRANSITION || b == ELEVATION_TRANSITION)
        return TRUE;

    if (a != b)
        return FALSE;

    return TRUE;
}

__attribute__((naked)) void GroundEffect_SpawnOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r3, _08096844\n\t"
        "	movs r2, #0x10\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	str r1, [r3]\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	str r1, [r3, #4]\n\t"
        "	ldrb r1, [r0, #0xb]\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	str r1, [r3, #8]\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [r3, #0xc]\n\t"
        "	ldrb r1, [r0, #8]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrb r2, [r0, #9]\n\t"
        "	orrs r1, r2\n\t"
        "	str r1, [r3, #0x10]\n\t"
        "	ldrb r0, [r0, #0xa]\n\t"
        "	str r0, [r3, #0x14]\n\t"
        "	ldr r0, _08096848\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrb r0, [r1, #5]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r3, #0x18]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [r3, #0x1c]\n\t"
        "	movs r0, #4\n\t"
        "	bl FieldEffectStart\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096844: .4byte gFieldEffectArguments\n\t"
        "_08096848: .4byte gSaveBlock1Ptr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GroundEffect_StepOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r3, _08096890\n\t"
        "	movs r2, #0x10\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	str r1, [r3]\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	str r1, [r3, #4]\n\t"
        "	ldrb r1, [r0, #0xb]\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	str r1, [r3, #8]\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [r3, #0xc]\n\t"
        "	ldrb r1, [r0, #8]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrb r2, [r0, #9]\n\t"
        "	orrs r1, r2\n\t"
        "	str r1, [r3, #0x10]\n\t"
        "	ldrb r0, [r0, #0xa]\n\t"
        "	str r0, [r3, #0x14]\n\t"
        "	ldr r0, _08096894\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrb r0, [r1, #5]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r3, #0x18]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r3, #0x1c]\n\t"
        "	movs r0, #4\n\t"
        "	bl FieldEffectStart\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096890: .4byte gFieldEffectArguments\n\t"
        "_08096894: .4byte gSaveBlock1Ptr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GroundEffect_SpawnOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r3, _080968DC\n\t"
        "	movs r2, #0x10\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	str r1, [r3]\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	str r1, [r3, #4]\n\t"
        "	ldrb r1, [r0, #0xb]\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	str r1, [r3, #8]\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [r3, #0xc]\n\t"
        "	ldrb r1, [r0, #8]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrb r2, [r0, #9]\n\t"
        "	orrs r1, r2\n\t"
        "	str r1, [r3, #0x10]\n\t"
        "	ldrb r0, [r0, #0xa]\n\t"
        "	str r0, [r3, #0x14]\n\t"
        "	ldr r0, _080968E0\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrb r0, [r1, #5]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r3, #0x18]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [r3, #0x1c]\n\t"
        "	movs r0, #0x11\n\t"
        "	bl FieldEffectStart\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080968DC: .4byte gFieldEffectArguments\n\t"
        "_080968E0: .4byte gSaveBlock1Ptr\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GroundEffect_StepOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r3, _08096928\n\t"
        "	movs r2, #0x10\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	str r1, [r3]\n\t"
        "	movs r2, #0x12\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	str r1, [r3, #4]\n\t"
        "	ldrb r1, [r0, #0xb]\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	str r1, [r3, #8]\n\t"
        "	movs r1, #2\n\t"
        "	str r1, [r3, #0xc]\n\t"
        "	ldrb r1, [r0, #8]\n\t"
        "	lsls r1, r1, #8\n\t"
        "	ldrb r2, [r0, #9]\n\t"
        "	orrs r1, r2\n\t"
        "	str r1, [r3, #0x10]\n\t"
        "	ldrb r0, [r0, #0xa]\n\t"
        "	str r0, [r3, #0x14]\n\t"
        "	ldr r0, _0809692C\n\t"
        "	ldr r1, [r0]\n\t"
        "	ldrb r0, [r1, #5]\n\t"
        "	lsls r0, r0, #8\n\t"
        "	ldrb r1, [r1, #4]\n\t"
        "	orrs r0, r1\n\t"
        "	str r0, [r3, #0x18]\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [r3, #0x1c]\n\t"
        "	movs r0, #0x11\n\t"
        "	bl FieldEffectStart\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096928: .4byte gFieldEffectArguments\n\t"
        "_0809692C: .4byte gSaveBlock1Ptr\n\t"
        ".syntax divided\n\t"
    );
}

void GroundEffect_WaterReflection(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    SetUpReflection(objEvent, sprite, FALSE);
}

void GroundEffect_IceReflection(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    SetUpReflection(objEvent, sprite, TRUE);
}


void GroundEffect_FlowingWater(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_FEET_IN_FLOWING_WATER, objEvent);
}

__attribute__((naked)) void GroundEffect_SandTracks(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4, #5]\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	ldr r1, _08096980\n\t"
        "	ldrb r0, [r0, #0xd]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r3, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl _call_via_r3\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096980: .4byte sGroundEffectTracksFuncs\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08096984(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4, #5]\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	ldr r1, _080969AC\n\t"
        "	ldrb r0, [r0, #0xd]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r3, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	movs r2, #1\n\t"
        "	bl _call_via_r3\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080969AC: .4byte sGroundEffectTracksFuncs\n\t"
        ".syntax divided\n\t"
    );
}

void DoTracksGroundEffect_None(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a) {}
__attribute__((naked)) void DoTracksGroundEffect_Footprints(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r4, r2, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r1, _080969FC\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #4\n\t"
        "	bl memcpy\n\t"
        "	ldr r1, _08096A00\n\t"
        "	movs r2, #0x14\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	str r0, [r1]\n\t"
        "	movs r2, #0x16\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	str r0, [r1, #4]\n\t"
        "	movs r0, #0x95\n\t"
        "	str r0, [r1, #8]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [r1, #0xc]\n\t"
        "	ldrb r0, [r5, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	str r0, [r1, #0x10]\n\t"
        "	lsls r4, r4, #1\n\t"
        "	mov r1, sp\n\t"
        "	adds r0, r1, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl FieldEffectStart\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080969FC: .4byte sSandFootprintsFieldEffectIds\n\t"
        "_08096A00: .4byte gFieldEffectArguments\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DoTracksGroundEffect_BikeTireTracks(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, [r4, #0x10]\n\t"
        "	ldr r0, [r4, #0x14]\n\t"
        "	cmp r1, r0\n\t"
        "	beq _08096A46\n\t"
        "	ldr r2, _08096A4C\n\t"
        "	movs r1, #0x14\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	str r0, [r2]\n\t"
        "	movs r1, #0x16\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	str r0, [r2, #4]\n\t"
        "	movs r0, #0x95\n\t"
        "	str r0, [r2, #8]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [r2, #0xc]\n\t"
        "	ldr r3, _08096A50\n\t"
        "	ldrb r1, [r4, #0x18]\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x20\n\t"
        "	ldrb r0, [r0]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	subs r0, #5\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r3\n\t"
        "	ldrb r0, [r1]\n\t"
        "	str r0, [r2, #0x10]\n\t"
        "	movs r0, #0x23\n\t"
        "	bl FieldEffectStart\n\t"
        "_08096A46:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096A4C: .4byte gFieldEffectArguments\n\t"
        "_08096A50: .4byte sBikeTireTracksTransitions\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08096A54(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl DoRippleFieldEffect\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

void GroundEffect_StepOnPuddle(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_SPLASH, objEvent);
}

void GroundEffect_SandHeap(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_SAND_PILE, objEvent);
}

__attribute__((naked)) void GroundEffect_JumpOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r6, r1, #0\n\t"
        "	ldr r1, _08096AD4\n\t"
        "	movs r2, #0x10\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	str r0, [r1]\n\t"
        "	movs r4, #0x12\n\t"
        "	ldrsh r0, [r5, r4]\n\t"
        "	str r0, [r1, #4]\n\t"
        "	ldrb r0, [r5, #0xb]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	str r0, [r1, #8]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [r1, #0xc]\n\t"
        "	movs r0, #0xc\n\t"
        "	bl FieldEffectStart\n\t"
        "	ldrb r0, [r5, #8]\n\t"
        "	ldrb r1, [r5, #9]\n\t"
        "	ldrb r2, [r5, #0xa]\n\t"
        "	movs r7, #0x10\n\t"
        "	ldrsh r3, [r5, r7]\n\t"
        "	movs r7, #0x12\n\t"
        "	ldrsh r4, [r5, r7]\n\t"
        "	str r4, [sp]\n\t"
        "	bl FindTallGrassFieldEffectSpriteId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0x40\n\t"
        "	bne _08096ACA\n\t"
        "	adds r0, r5, #0\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl GroundEffect_SpawnOnTallGrass\n\t"
        "_08096ACA:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096AD4: .4byte gFieldEffectArguments\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GroundEffect_JumpOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r2, _08096AFC\n\t"
        "	movs r3, #0x10\n\t"
        "	ldrsh r1, [r0, r3]\n\t"
        "	str r1, [r2]\n\t"
        "	movs r3, #0x12\n\t"
        "	ldrsh r1, [r0, r3]\n\t"
        "	str r1, [r2, #4]\n\t"
        "	ldrb r0, [r0, #0xb]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	str r0, [r2, #8]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [r2, #0xc]\n\t"
        "	movs r0, #0x12\n\t"
        "	bl FieldEffectStart\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096AFC: .4byte gFieldEffectArguments\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GroundEffect_JumpOnShallowWater(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r3, _08096B2C\n\t"
        "	movs r4, #0x10\n\t"
        "	ldrsh r2, [r0, r4]\n\t"
        "	str r2, [r3]\n\t"
        "	movs r4, #0x12\n\t"
        "	ldrsh r2, [r0, r4]\n\t"
        "	str r2, [r3, #4]\n\t"
        "	ldrb r0, [r0, #0xb]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	str r0, [r3, #8]\n\t"
        "	ldrb r0, [r1, #5]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1e\n\t"
        "	str r0, [r3, #0xc]\n\t"
        "	movs r0, #0x10\n\t"
        "	bl FieldEffectStart\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096B2C: .4byte gFieldEffectArguments\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GroundEffect_JumpOnWater(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r3, _08096B5C\n\t"
        "	movs r4, #0x10\n\t"
        "	ldrsh r2, [r0, r4]\n\t"
        "	str r2, [r3]\n\t"
        "	movs r4, #0x12\n\t"
        "	ldrsh r2, [r0, r4]\n\t"
        "	str r2, [r3, #4]\n\t"
        "	ldrb r0, [r0, #0xb]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	str r0, [r3, #8]\n\t"
        "	ldrb r0, [r1, #5]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1e\n\t"
        "	str r0, [r3, #0xc]\n\t"
        "	movs r0, #0xe\n\t"
        "	bl FieldEffectStart\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096B5C: .4byte gFieldEffectArguments\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GroundEffect_JumpLandingDust(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r3, _08096B8C\n\t"
        "	movs r4, #0x10\n\t"
        "	ldrsh r2, [r0, r4]\n\t"
        "	str r2, [r3]\n\t"
        "	movs r4, #0x12\n\t"
        "	ldrsh r2, [r0, r4]\n\t"
        "	str r2, [r3, #4]\n\t"
        "	ldrb r0, [r0, #0xb]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	str r0, [r3, #8]\n\t"
        "	ldrb r0, [r1, #5]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1e\n\t"
        "	str r0, [r3, #0xc]\n\t"
        "	movs r0, #0xa\n\t"
        "	bl FieldEffectStart\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096B8C: .4byte gFieldEffectArguments\n\t"
        ".syntax divided\n\t"
    );
}

void GroundEffect_ShortGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_SHORT_GRASS, objEvent);
}

void GroundEffect_HotSprings(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_HOT_SPRINGS_WATER, objEvent);
}

__attribute__((naked)) void GroundEffect_Seaweed(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r2, _08096BCC\n\t"
        "	movs r3, #0x10\n\t"
        "	ldrsh r1, [r0, r3]\n\t"
        "	str r1, [r2]\n\t"
        "	movs r1, #0x12\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	str r0, [r2, #4]\n\t"
        "	movs r0, #0x35\n\t"
        "	bl FieldEffectStart\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096BCC: .4byte gFieldEffectArguments\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DoFlaggedGroundEffects(struct ObjectEvent *objEvent, struct Sprite *sprite, u32 flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r7, r1, #0\n\t"
        "	adds r5, r2, #0\n\t"
        "	bl ObjectEventIsFarawayIslandMew\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08096BF4\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl ShouldMewShakeGrass\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096C1C\n\t"
        "_08096BF4:\n\t"
        "	movs r4, #0\n\t"
        "	ldr r0, _08096C28\n\t"
        "	mov r8, r0\n\t"
        "_08096BFA:\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r5\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096C10\n\t"
        "	lsls r0, r4, #2\n\t"
        "	add r0, r8\n\t"
        "	ldr r2, [r0]\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl _call_via_r2\n\t"
        "_08096C10:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	lsrs r5, r5, #1\n\t"
        "	cmp r4, #0x13\n\t"
        "	bls _08096BFA\n\t"
        "_08096C1C:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096C28: .4byte sGroundEffectFuncs\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void filters_out_some_ground_effects(struct ObjectEvent *objEvent, u32 *flags)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r2, r0, #0\n\t"
        "	adds r3, r1, #0\n\t"
        "	ldrb r0, [r2]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08096C5A\n\t"
        "	ldrb r1, [r2, #2]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x11\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	adds r1, #8\n\t"
        "	ands r0, r1\n\t"
        "	subs r1, #0x18\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #2]\n\t"
        "	ldr r0, [r3]\n\t"
        "	ldr r1, _08096C60\n\t"
        "	ands r0, r1\n\t"
        "	str r0, [r3]\n\t"
        "_08096C5A:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096C60: .4byte 0xFFF9F7BD\n\t"
        ".syntax divided\n\t"
    );
}

void FilterOutStepOnPuddleGroundEffectIfJumping(struct ObjectEvent *objEvent, u32 *flags)
{
    if (objEvent->landingJump)
        *flags &= ~GROUND_EFFECT_FLAG_PUDDLE;
}


__attribute__((naked)) void DoGroundEffects_OnSpawn(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08096CC4\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl UpdateEventObjectZCoordAndPriority\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, sp\n\t"
        "	bl GetAllGroundEffectFlags_OnSpawn\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl SetEventObjectSpriteOamTableForLongGrass\n\t"
        "	ldr r2, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl DoFlaggedGroundEffects\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x11\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "_08096CC4:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DoGroundEffects_OnBeginStep(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r0, r0, #0x1d\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08096D18\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl UpdateEventObjectZCoordAndPriority\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, sp\n\t"
        "	bl GetAllGroundEffectFlags_OnBeginStep\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl SetEventObjectSpriteOamTableForLongGrass\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, sp\n\t"
        "	bl filters_out_some_ground_effects\n\t"
        "	ldr r2, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl DoFlaggedGroundEffects\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x11\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "_08096D18:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DoGroundEffects_OnFinishStep(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldrb r0, [r4]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	cmp r0, #0\n\t"
        "	bge _08096D6C\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl UpdateEventObjectZCoordAndPriority\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, sp\n\t"
        "	bl GetAllGroundEffectFlags_OnFinishStep\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl SetEventObjectSpriteOamTableForLongGrass\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, sp\n\t"
        "	bl FilterOutStepOnPuddleGroundEffectIfJumping\n\t"
        "	ldr r2, [sp]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r1, r5, #0\n\t"
        "	bl DoFlaggedGroundEffects\n\t"
        "	ldrb r1, [r4]\n\t"
        "	movs r0, #9\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #0x21\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4]\n\t"
        "_08096D6C:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void FreezeEventObject(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldrh r1, [r5]\n\t"
        "	movs r0, #0xa0\n\t"
        "	lsls r0, r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08096DFC\n\t"
        "	ldrb r0, [r5, #1]\n\t"
        "	movs r4, #1\n\t"
        "	orrs r0, r4\n\t"
        "	strb r0, [r5, #1]\n\t"
        "	ldr r3, _08096DF8\n\t"
        "	ldrb r1, [r5, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsls r1, r1, #0x19\n\t"
        "	lsrs r1, r1, #0x1f\n\t"
        "	lsls r1, r1, #7\n\t"
        "	ldrb r2, [r5, #2]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r5, #2]\n\t"
        "	ldrb r1, [r5, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	lsrs r1, r1, #7\n\t"
        "	ands r1, r4\n\t"
        "	ldrb r2, [r5, #3]\n\t"
        "	movs r0, #2\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r5, #3]\n\t"
        "	ldrb r1, [r5, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x40\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	ldrb r1, [r5, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	adds r0, #0x2c\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r2, #0x80\n\t"
        "	orrs r1, r2\n\t"
        "	strb r1, [r0]\n\t"
        "	movs r0, #0\n\t"
        "	b _08096DFE\n\t"
        "	.align 2, 0\n\t"
        "_08096DF8: .4byte gSprites\n\t"
        "_08096DFC:\n\t"
        "	movs r0, #1\n\t"
        "_08096DFE:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

void FreezeObjectEvents(void)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        if (gObjectEvents[i].active && i != gPlayerAvatar.objectEventId)
            FreezeEventObject(&gObjectEvents[i]);
}

__attribute__((naked)) void FreezeEventObjectsExceptOne(u8 objectEventId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	movs r4, #0\n\t"
        "	ldr r6, _08096E7C\n\t"
        "_08096E4A:\n\t"
        "	cmp r4, r5\n\t"
        "	beq _08096E6C\n\t"
        "	lsls r0, r4, #3\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r0, r6\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08096E6C\n\t"
        "	ldr r0, _08096E80\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _08096E6C\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl FreezeEventObject\n\t"
        "_08096E6C:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0xf\n\t"
        "	bls _08096E4A\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096E7C: .4byte gObjectEvents\n\t"
        "_08096E80: .4byte gPlayerAvatar\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void UnfreezeEventObject(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldrh r2, [r5]\n\t"
        "	ldr r1, _08096EE4\n\t"
        "	adds r0, r1, #0\n\t"
        "	ands r0, r2\n\t"
        "	cmp r0, r1\n\t"
        "	bne _08096EDC\n\t"
        "	ldrb r1, [r5, #1]\n\t"
        "	movs r0, #2\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r5, #1]\n\t"
        "	ldr r4, _08096EE8\n\t"
        "	ldrb r0, [r5, #4]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r4\n\t"
        "	ldrb r2, [r5, #2]\n\t"
        "	adds r1, #0x2c\n\t"
        "	lsrs r2, r2, #7\n\t"
        "	lsls r2, r2, #6\n\t"
        "	ldrb r3, [r1]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r3\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r1]\n\t"
        "	ldrb r0, [r5, #4]\n\t"
        "	lsls r2, r0, #4\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r4\n\t"
        "	ldrb r1, [r5, #3]\n\t"
        "	lsls r1, r1, #0x1f\n\t"
        "	lsrs r1, r1, #0x1f\n\t"
        "	adds r2, #0x2c\n\t"
        "	lsls r1, r1, #7\n\t"
        "	ldrb r3, [r2]\n\t"
        "	movs r0, #0x7f\n\t"
        "	ands r0, r3\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "_08096EDC:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08096EE4: .4byte SPECIAL_RetrieveLotteryNumber\n\t"
        "_08096EE8: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

void UnfreezeObjectEvents(void)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        if (gObjectEvents[i].active)
            UnfreezeEventObject(&gObjectEvents[i]);
}

static void Step1(struct Sprite *sprite, u8 dir)
{
    sprite->x += sDirectionToVectors[dir].x;
    sprite->y += sDirectionToVectors[dir].y;
}

static void Step2(struct Sprite *sprite, u8 dir)
{
    sprite->x += 2 * (u16) sDirectionToVectors[dir].x;
    sprite->y += 2 * (u16) sDirectionToVectors[dir].y;
}

static void Step3(struct Sprite *sprite, u8 dir)
{
    sprite->x += 2 * (u16) sDirectionToVectors[dir].x + (u16) sDirectionToVectors[dir].x;
    sprite->y += 2 * (u16) sDirectionToVectors[dir].y + (u16) sDirectionToVectors[dir].y;
}

static void Step4(struct Sprite *sprite, u8 dir)
{
    sprite->x += 4 * (u16) sDirectionToVectors[dir].x;
    sprite->y += 4 * (u16) sDirectionToVectors[dir].y;
}

__attribute__((naked)) void Step8(struct Sprite *sprite, u8 direction)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	ldr r2, _08096FCC\n\t"
        "	lsrs r1, r1, #0x16\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrh r2, [r1]\n\t"
        "	lsls r2, r2, #3\n\t"
        "	ldrh r3, [r0, #0x20]\n\t"
        "	adds r2, r2, r3\n\t"
        "	strh r2, [r0, #0x20]\n\t"
        "	ldrh r1, [r1, #2]\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldrh r2, [r0, #0x22]\n\t"
        "	adds r1, r1, r2\n\t"
        "	strh r1, [r0, #0x22]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_08096FCC: .4byte gUnknown_84E5FD0\n\t"
        ".syntax divided\n\t"
    );
}

void oamt_npc_ministep_reset(struct Sprite *sprite, u8 a, u8 b)
{
    sprite->data[3] = a;
    sprite->data[4] = b;
    sprite->data[5] = 0;
}

__attribute__((naked)) bool8 obj_npc_ministep(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r5, _0809703C\n\t"
        "	movs r0, #0x36\n\t"
        "	ldrsh r2, [r4, r0]\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r0, r0, r5\n\t"
        "	movs r3, #0x38\n\t"
        "	ldrsh r1, [r4, r3]\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r0, [r0, r3]\n\t"
        "	cmp r1, r0\n\t"
        "	bge _08097044\n\t"
        "	ldr r1, _08097040\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0x38\n\t"
        "	ldrsh r2, [r4, r1]\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r0\n\t"
        "	ldrh r1, [r4, #0x34]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldr r2, [r2]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl _call_via_r2\n\t"
        "	ldrh r0, [r4, #0x38]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0x38]\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	lsls r1, r1, #1\n\t"
        "	adds r1, r1, r5\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	movs r3, #0\n\t"
        "	ldrsh r1, [r1, r3]\n\t"
        "	cmp r0, r1\n\t"
        "	blt _08097044\n\t"
        "	movs r0, #1\n\t"
        "	b _08097046\n\t"
        "	.align 2, 0\n\t"
        "_0809703C: .4byte sStepTimes\n\t"
        "_08097040: .4byte sNpcStepFuncTables\n\t"
        "_08097044:\n\t"
        "	movs r0, #0\n\t"
        "_08097046:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

void sub_0809704C(struct Sprite *sprite, u8 a)
{
    sprite->data[3] = a;
    sprite->data[4] = 0;
    sprite->data[5] = 0;
}

#define sTimer     data[4]
#define sNumSteps  data[5]

bool8 UpdateWalkSlowAnim(struct Sprite *sprite)
{
    if (!(sprite->sTimer & 1))
    {
        Step1(sprite, sprite->sDirection);
        sprite->sNumSteps++;
    }

    sprite->sTimer++;

    if (sprite->sNumSteps > 15)
        return TRUE;
    else
        return FALSE;
}

#undef sTimer
#undef sNumSteps


s16 GetFigure8YOffset(s16 idx)
{
    return sFigure8YOffsets[idx];
}

s16 GetFigure8XOffset(s16 idx)
{
    return sFigure8XOffsets[idx];
}

void InitSpriteForFigure8Anim(struct Sprite *sprite)
{
    sprite->data[6] = 0;
    sprite->data[7] = 0;
}

bool8 AnimateSpriteInFigure8(struct Sprite *sprite)
{
    bool8 finished = FALSE;

    switch(sprite->data[7])
    {
    case 0:
        sprite->x2 += GetFigure8XOffset(sprite->data[6]);
        sprite->y2 += GetFigure8YOffset(sprite->data[6]);
        break;
    case 1:
        sprite->x2 -= GetFigure8XOffset((FIGURE_8_LENGTH - 1) - sprite->data[6]);
        sprite->y2 += GetFigure8YOffset((FIGURE_8_LENGTH - 1) - sprite->data[6]);
        break;
    case 2:
        sprite->x2 -= GetFigure8XOffset(sprite->data[6]);
        sprite->y2 += GetFigure8YOffset(sprite->data[6]);
        break;
    case 3:
        sprite->x2 += GetFigure8XOffset((FIGURE_8_LENGTH - 1) - sprite->data[6]);
        sprite->y2 += GetFigure8YOffset((FIGURE_8_LENGTH - 1) - sprite->data[6]);
        break;
    }
    if (++sprite->data[6] == FIGURE_8_LENGTH)
    {
        sprite->data[6] = 0;
        sprite->data[7]++;
    }
    if (sprite->data[7] == 4)
    {
        sprite->y2 = 0;
        sprite->x2 = 0;
        finished = TRUE;
    }
    return finished;
}


__attribute__((naked)) s16 sub_08097190(s16 a, u8 b)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	ldr r2, _080971A8\n\t"
        "	lsrs r1, r1, #0x16\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	ldr r1, [r1]\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #0\n\t"
        "	ldrsb r0, [r1, r0]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_080971A8: .4byte sJumpYTable\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 sub_080971AC(u8 a, u8 b, u8 c)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r2, r2, #0x18\n\t"
        "	lsls r3, r3, #0x18\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	movs r4, #0\n\t"
        "	strh r1, [r0, #0x34]\n\t"
        "	strh r2, [r0, #0x36]\n\t"
        "	strh r3, [r0, #0x38]\n\t"
        "	strh r4, [r0, #0x3a]\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_080971CC(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _0809724C\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #6\n\t"
        "	bl memcpy\n\t"
        "	add r5, sp, #8\n\t"
        "	ldr r1, _08097250\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r2, #3\n\t"
        "	bl memcpy\n\t"
        "	movs r6, #0\n\t"
        "	movs r1, #0x36\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080971FE\n\t"
        "	ldrh r1, [r4, #0x34]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl Step1\n\t"
        "_080971FE:\n\t"
        "	movs r2, #0x3a\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	adds r1, r5, r1\n\t"
        "	ldrb r1, [r1]\n\t"
        "	asrs r0, r1\n\t"
        "	ldrh r1, [r4, #0x38]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	bl sub_08097190\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	ldrh r1, [r4, #0x3a]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r4, #0x3a]\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, sp\n\t"
        "	ldrh r0, [r0]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r2, r0, #0x10\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	asrs r0, r0, #0x11\n\t"
        "	cmp r1, r0\n\t"
        "	bne _08097238\n\t"
        "	movs r6, #1\n\t"
        "_08097238:\n\t"
        "	cmp r1, r2\n\t"
        "	blt _08097242\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	movs r6, #0xff\n\t"
        "_08097242:\n\t"
        "	adds r0, r6, #0\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0809724C: .4byte sJumpDistanceToTime\n\t"
        "_08097250: .4byte sJumpDistanceToShift\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_08097254(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldr r1, _080972E0\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #6\n\t"
        "	bl memcpy\n\t"
        "	add r4, sp, #8\n\t"
        "	ldr r1, _080972E4\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #3\n\t"
        "	bl memcpy\n\t"
        "	movs r6, #0\n\t"
        "	movs r1, #0x36\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08097290\n\t"
        "	ldrh r1, [r5, #0x3a]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _08097290\n\t"
        "	ldrh r1, [r5, #0x34]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl Step1\n\t"
        "_08097290:\n\t"
        "	movs r2, #0x3a\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	adds r1, r4, r1\n\t"
        "	ldrb r1, [r1]\n\t"
        "	asrs r0, r1\n\t"
        "	ldrh r1, [r5, #0x38]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	bl sub_08097190\n\t"
        "	strh r0, [r5, #0x26]\n\t"
        "	ldrh r1, [r5, #0x3a]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r5, #0x3a]\n\t"
        "	movs r2, #0x36\n\t"
        "	ldrsh r0, [r5, r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, sp\n\t"
        "	ldrh r0, [r0]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r2, r0, #0x10\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	asrs r0, r0, #0x11\n\t"
        "	cmp r1, r0\n\t"
        "	bne _080972CA\n\t"
        "	movs r6, #1\n\t"
        "_080972CA:\n\t"
        "	cmp r1, r2\n\t"
        "	blt _080972D4\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5, #0x26]\n\t"
        "	movs r6, #0xff\n\t"
        "_080972D4:\n\t"
        "	adds r0, r6, #0\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080972E0: .4byte sJumpSpecialDistanceToTime\n\t"
        "_080972E4: .4byte sJumpSpecialDistanceToShift\n\t"
        ".syntax divided\n\t"
    );
}


void SetMovementDelay(struct Sprite *sprite, s16 timer)
{
    sprite->data[3] = timer;
}


bool8 WaitForMovementDelay(struct Sprite *sprite)
{
    if (--sprite->data[3] == 0)
        return TRUE;
    else
        return FALSE;
}

void SetAndStartSpriteAnim(struct Sprite *sprite, u8 animNum, u8 animCmdIndex)
{
    sprite->animNum = animNum;
    sprite->animPaused = FALSE;
    SeekSpriteAnim(sprite, animCmdIndex);
}

bool8 SpriteAnimEnded(struct Sprite *sprite)
{
    if (sprite->animEnded)
        return TRUE;
    else
        return FALSE;
}

void UpdateObjectEventSpriteInvisibility(struct Sprite *sprite, bool8 invisible)
{
    u16 x, y;
    s16 x2, y2;

    sprite->invisible = invisible;

    if (sprite->coordOffsetEnabled)
    {
        x = sprite->x + sprite->x2 + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
        y = sprite->y + sprite->y2 + sprite->centerToCornerVecY + gSpriteCoordOffsetY;
    }
    else
    {
        x = sprite->x + sprite->x2 + sprite->centerToCornerVecX;
        y = sprite->y + sprite->y2 + sprite->centerToCornerVecY;
    }

    x2 = x - (sprite->centerToCornerVecX >> 1);
    y2 = y - (sprite->centerToCornerVecY >> 1);

    if ((s16)x >= DISPLAY_WIDTH + 16 || x2 < -16)
        sprite->invisible = TRUE;
    if ((s16)y >= DISPLAY_HEIGHT + 16 || y2 < -16)
        sprite->invisible = TRUE;
}

void SpriteCB_VirtualObject(struct Sprite *sprite)
{
    sub_080976D8(sprite);
    SetObjectSubpriorityByElevation(sprite->sVirtualObjElev, sprite, 1);
    UpdateObjectEventSpriteInvisibility(sprite, sprite->sInvisible);
}

__attribute__((naked)) void sub_08097460(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	movs r5, #0\n\t"
        "	movs r4, #0x3f\n\t"
        "_08097466:\n\t"
        "	ldr r0, _08097494\n\t"
        "	adds r2, r5, r0\n\t"
        "	adds r0, r2, #0\n\t"
        "	adds r0, #0x3e\n\t"
        "	ldrb r1, [r0]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08097486\n\t"
        "	ldr r1, [r2, #0x1c]\n\t"
        "	ldr r0, _08097498\n\t"
        "	cmp r1, r0\n\t"
        "	bne _08097486\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl DestroySprite\n\t"
        "_08097486:\n\t"
        "	adds r5, #0x44\n\t"
        "	subs r4, #1\n\t"
        "	cmp r4, #0\n\t"
        "	bge _08097466\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08097494: .4byte gSprites\n\t"
        "_08097498: .4byte SpriteCB_VirtualObject + 1\n\t"
        ".syntax divided\n\t"
    );
}

int GetVirtualObjectSpriteId(u8 virtualObjId)
{
    int i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if (sprite->inUse && sprite->callback == SpriteCB_VirtualObject && (u8)sprite->sVirtualObjId == virtualObjId)
            return i;
    }
    return MAX_SPRITES;
}

void TurnVirtualObject(u8 virtualObjId, u8 direction)
{
    u8 spriteId = GetVirtualObjectSpriteId(virtualObjId);

    if (spriteId != MAX_SPRITES)
        StartSpriteAnim(&gSprites[spriteId], GetJumpInPlaceMovementAction(direction));
}

void SetVirtualObjectGraphics(u8 virtualObjId, u8 graphicsId)
{
    int spriteId = GetVirtualObjectSpriteId(virtualObjId);

    if (spriteId != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[spriteId];
        const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(graphicsId);
        u16 tileNum = sprite->oam.tileNum;

        sprite->oam = *graphicsInfo->oam;
        sprite->oam.tileNum = tileNum;
        sprite->oam.paletteNum = graphicsInfo->paletteSlot;
        sprite->images = graphicsInfo->images;

        if (graphicsInfo->subspriteTables == NULL)
        {
            sprite->subspriteTables = NULL;
            sprite->subspriteTableNum = 0;
            sprite->subspriteMode = SUBSPRITES_OFF;
        }
        else
        {
            SetSubspriteTables(sprite, graphicsInfo->subspriteTables);
            sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        }
        StartSpriteAnim(sprite, 0);
    }
}

void SetVirtualObjectInvisibility(u8 virtualObjId, bool32 invisible)
{
    u8 spriteId = GetVirtualObjectSpriteId(virtualObjId);

    if (spriteId == MAX_SPRITES)
        return;

    if (invisible)
        gSprites[spriteId].sInvisible = TRUE;
    else
        gSprites[spriteId].sInvisible = FALSE;
}

__attribute__((naked)) bool32 IsVirtualObjectInvisible(u8 virtualObjId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetVirtualObjectSpriteId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0x40\n\t"
        "	bne _08097612\n\t"
        "	movs r0, #0\n\t"
        "	b _0809762A\n\t"
        "_08097612:\n\t"
        "	movs r3, #0\n\t"
        "	ldr r0, _08097630\n\t"
        "	lsls r1, r2, #4\n\t"
        "	adds r1, r1, r2\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r2, #0x32\n\t"
        "	ldrsh r0, [r1, r2]\n\t"
        "	cmp r0, #1\n\t"
        "	bne _08097628\n\t"
        "	movs r3, #1\n\t"
        "_08097628:\n\t"
        "	adds r0, r3, #0\n\t"
        "_0809762A:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_08097630: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

void SetVirtualObjectSpriteAnim(u8 virtualObjId, u8 animNum)
{
    u8 spriteId = GetVirtualObjectSpriteId(virtualObjId);

    if (spriteId != MAX_SPRITES)
    {
        gSprites[spriteId].sAnimNum = animNum;
        gSprites[spriteId].sAnimState = 0;
    }
}

void MoveUnionRoomObjectUp(struct Sprite *sprite)
{
    switch (sprite->sAnimState)
    {
    case 0:
        sprite->y2 = 0;
        sprite->sAnimState++;
    case 1:
        sprite->y2 -= 8;
        if (sprite->y2 == -DISPLAY_HEIGHT)
        {
            sprite->y2 = 0;
            sprite->sInvisible = TRUE;
            sprite->sAnimNum = 0;
            sprite->sAnimState = 0;
        }
    }
}

void MoveUnionRoomObjectDown(struct Sprite *sprite)
{
    switch (sprite->sAnimState)
    {
    case 0:
        sprite->y2 = -DISPLAY_HEIGHT;
        sprite->sAnimState++;
    case 1:
        sprite->y2 += 8;
        if (sprite->y2 == 0)
        {
            sprite->sAnimNum = 0;
            sprite->sAnimState = 0;
        }
    }
}

__attribute__((naked)) bool8 sub_080976D8(struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r1, r0, #0\n\t"
        "	movs r2, #0x34\n\t"
        "	ldrsh r0, [r1, r2]\n\t"
        "	cmp r0, #1\n\t"
        "	beq _080976F4\n\t"
        "	cmp r0, #1\n\t"
        "	bgt _080976EE\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08097714\n\t"
        "	b _08097704\n\t"
        "_080976EE:\n\t"
        "	cmp r0, #2\n\t"
        "	beq _080976FC\n\t"
        "	b _08097704\n\t"
        "_080976F4:\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl sub_080976A0\n\t"
        "	b _08097714\n\t"
        "_080976FC:\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl sub_08097664\n\t"
        "	b _08097714\n\t"
        "_08097704:\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r1, #0x34]\n\t"
        "	ldr r0, _08097718\n\t"
        "	ldr r1, _0809771C\n\t"
        "	ldr r2, _08097720\n\t"
        "	movs r3, #1\n\t"
        "	bl AGBAssert\n\t"
        "_08097714:\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08097718: .4byte sEventObjectMovementSourceFile\n\t"
        "_0809771C: .4byte 0x00003106\n\t"
        "_08097720: .4byte sVirtualObjectAnimAssertExpression\n\t"
        ".syntax divided\n\t"
    );
}

bool32 IsVirtualObjectAnimating(u8 virtualObjId)
{
    u8 spriteId = GetVirtualObjectSpriteId(virtualObjId);

    if (spriteId == MAX_SPRITES)
        return FALSE;

    if (gSprites[spriteId].sAnimNum != 0)
        return TRUE;

    return FALSE;
}

u32 StartFieldEffectForObjectEvent(u8 fieldEffectId, struct ObjectEvent *objectEvent)
{
    ObjectEventGetLocalIdAndMap(objectEvent, &gFieldEffectArguments[0], &gFieldEffectArguments[1], &gFieldEffectArguments[2]);
    return FieldEffectStart(fieldEffectId);
}

void DoShadowFieldEffect(struct ObjectEvent *objectEvent)
{
    if (!objectEvent->hasShadow)
    {
        objectEvent->hasShadow = TRUE;
        StartFieldEffectForObjectEvent(FLDEFF_SHADOW, objectEvent);
    }
}

void DoRippleFieldEffect(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    const struct ObjectEventGraphicsInfo *graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    gFieldEffectArguments[0] = sprite->x;
    gFieldEffectArguments[1] = sprite->y + (graphicsInfo->height >> 1) - 2;
    gFieldEffectArguments[2] = 151;
    gFieldEffectArguments[3] = 3;
    FieldEffectStart(FLDEFF_RIPPLE);
}

__attribute__((naked)) bool8 MovementAction_StoreAndLockAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r4, r0, #0\n\t"
        "	mov r8, r1\n\t"
        "	movs r0, #0\n\t"
        "	mov ip, r0\n\t"
        "	ldr r0, _08097804\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r6, r0, #0\n\t"
        "	cmp r1, #0\n\t"
        "	bne _08097808\n\t"
        "	movs r0, #0x14\n\t"
        "	bl AllocZeroed\n\t"
        "	str r0, [r6]\n\t"
        "	ldrb r1, [r4, #8]\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, [r6]\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1, #0x10]\n\t"
        "	b _08097854\n\t"
        "	.align 2, 0\n\t"
        "_08097804: .4byte gUnknown_2037258\n\t"
        "_08097808:\n\t"
        "	movs r2, #0x10\n\t"
        "	movs r5, #0\n\t"
        "	movs r1, #0\n\t"
        "	adds r3, r6, #0\n\t"
        "	b _08097818\n\t"
        "_08097812:\n\t"
        "	adds r0, r1, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "_08097818:\n\t"
        "	cmp r1, #0xf\n\t"
        "	bhi _0809783A\n\t"
        "	cmp r2, #0x10\n\t"
        "	bne _0809782C\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0809782C\n\t"
        "	adds r2, r1, #0\n\t"
        "_0809782C:\n\t"
        "	ldr r0, [r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldrb r7, [r4, #8]\n\t"
        "	cmp r0, r7\n\t"
        "	bne _08097812\n\t"
        "	movs r5, #1\n\t"
        "_0809783A:\n\t"
        "	cmp r5, #0\n\t"
        "	bne _08097856\n\t"
        "	cmp r2, #0x10\n\t"
        "	beq _08097856\n\t"
        "	ldr r0, [r6]\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r1, [r4, #8]\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, [r6]\n\t"
        "	ldrb r0, [r1, #0x10]\n\t"
        "	adds r0, #1\n\t"
        "	strb r0, [r1, #0x10]\n\t"
        "	movs r0, #1\n\t"
        "_08097854:\n\t"
        "	mov ip, r0\n\t"
        "_08097856:\n\t"
        "	mov r1, ip\n\t"
        "	cmp r1, #1\n\t"
        "	bne _08097868\n\t"
        "	ldrb r0, [r4, #1]\n\t"
        "	movs r1, #0x10\n\t"
        "	orrs r0, r1\n\t"
        "	movs r1, #2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #1]\n\t"
        "_08097868:\n\t"
        "	movs r0, #1\n\t"
        "	mov r7, r8\n\t"
        "	strh r0, [r7, #0x32]\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 MovementAction_FreeAndUnlockAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	mov r8, r1\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r1, #0x32]\n\t"
        "	ldr r5, _080978FC\n\t"
        "	ldr r0, [r5]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _080978F0\n\t"
        "	movs r7, #0\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl FindLockedEventObjectIndex\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r1, r0, #0x18\n\t"
        "	cmp r1, #0x10\n\t"
        "	beq _080978B0\n\t"
        "	ldr r0, [r5]\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	strb r1, [r0]\n\t"
        "	ldr r1, [r5]\n\t"
        "	ldrb r0, [r1, #0x10]\n\t"
        "	subs r0, #1\n\t"
        "	strb r0, [r1, #0x10]\n\t"
        "	movs r7, #1\n\t"
        "_080978B0:\n\t"
        "	ldr r0, [r5]\n\t"
        "	ldrb r4, [r0, #0x10]\n\t"
        "	cmp r4, #0\n\t"
        "	bne _080978BE\n\t"
        "	bl Free\n\t"
        "	str r4, [r5]\n\t"
        "_080978BE:\n\t"
        "	cmp r7, #1\n\t"
        "	bne _080978F0\n\t"
        "	ldrb r0, [r6, #5]\n\t"
        "	bl GetObjectEventGraphicsInfo\n\t"
        "	ldrb r1, [r0, #0xc]\n\t"
        "	lsls r1, r1, #0x19\n\t"
        "	lsrs r1, r1, #0x1f\n\t"
        "	lsls r1, r1, #4\n\t"
        "	ldrb r2, [r6, #1]\n\t"
        "	movs r0, #0x11\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	movs r1, #3\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r6, #1]\n\t"
        "	mov r2, r8\n\t"
        "	adds r2, #0x2c\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x41\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "_080978F0:\n\t"
        "	movs r0, #1\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_080978FC: .4byte gUnknown_2037258\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) s8 FindLockedEventObjectIndex(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	movs r2, #0\n\t"
        "	ldr r1, _08097918\n\t"
        "	ldr r1, [r1]\n\t"
        "	ldrb r3, [r0, #8]\n\t"
        "_0809790A:\n\t"
        "	adds r0, r1, r2\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, r3\n\t"
        "	bne _0809791C\n\t"
        "	adds r0, r2, #0\n\t"
        "	b _08097928\n\t"
        "	.align 2, 0\n\t"
        "_08097918: .4byte gUnknown_2037258\n\t"
        "_0809791C:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #0xf\n\t"
        "	bls _0809790A\n\t"
        "	movs r0, #0x10\n\t"
        "_08097928:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void CreateLevitateMovementTask(struct ObjectEvent *objectEvent)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	ldr r0, _08097960\n\t"
        "	movs r1, #0xff\n\t"
        "	bl CreateTask\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	lsls r4, r5, #2\n\t"
        "	adds r4, r4, r5\n\t"
        "	lsls r4, r4, #3\n\t"
        "	ldr r0, _08097964\n\t"
        "	adds r4, r4, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #8\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl StoreWordInTwoHalfwords\n\t"
        "	strb r5, [r6, #0x1b]\n\t"
        "	ldr r0, _08097968\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08097960: .4byte ApplyLevitateMovement + 1\n\t"
        "_08097964: .4byte gTasks\n\t"
        "_08097968: .4byte 0x0000FFFF\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ApplyLevitateMovement(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	ldr r0, _080979C4\n\t"
        "	adds r4, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #8\n\t"
        "	mov r1, sp\n\t"
        "	bl LoadWordFromTwoHalfwords\n\t"
        "	ldr r0, [sp]\n\t"
        "	ldrb r1, [r0, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _080979C8\n\t"
        "	adds r2, r0, r1\n\t"
        "	ldrh r1, [r4, #0xc]\n\t"
        "	movs r0, #3\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080979A8\n\t"
        "	ldrh r0, [r4, #0xe]\n\t"
        "	ldrh r1, [r2, #0x26]\n\t"
        "	adds r0, r0, r1\n\t"
        "	strh r0, [r2, #0x26]\n\t"
        "_080979A8:\n\t"
        "	ldrh r1, [r4, #0xc]\n\t"
        "	movs r0, #0xf\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	bne _080979B8\n\t"
        "	ldrh r0, [r4, #0xe]\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "_080979B8:\n\t"
        "	adds r0, r1, #1\n\t"
        "	strh r0, [r4, #0xc]\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080979C4: .4byte gTasks\n\t"
        "_080979C8: .4byte gSprites\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DestroyExtraMovementTask(u8 taskId)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	lsls r0, r4, #2\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _080979F8\n\t"
        "	adds r0, r0, r1\n\t"
        "	adds r0, #8\n\t"
        "	mov r1, sp\n\t"
        "	bl LoadWordFromTwoHalfwords\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl DestroyTask\n\t"
        "	add sp, #4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_080979F8: .4byte gTasks\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) bool8 sub_080979FC(u8 a, u8 b)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r5, r1, #0x18\n\t"
        "	movs r4, #0\n\t"
        "	ldr r7, _08097A40\n\t"
        "_08097A0A:\n\t"
        "	cmp r4, r6\n\t"
        "	beq _08097A30\n\t"
        "	cmp r4, r5\n\t"
        "	beq _08097A30\n\t"
        "	lsls r0, r4, #3\n\t"
        "	adds r0, r0, r4\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r1, r0, r7\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #0x1f\n\t"
        "	cmp r0, #0\n\t"
        "	beq _08097A30\n\t"
        "	ldr r0, _08097A44\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	cmp r4, r0\n\t"
        "	beq _08097A30\n\t"
        "	adds r0, r1, #0\n\t"
        "	bl FreezeEventObject\n\t"
        "_08097A30:\n\t"
        "	adds r0, r4, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	cmp r4, #0xf\n\t"
        "	bls _08097A0A\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_08097A40: .4byte gObjectEvents\n\t"
        "_08097A44: .4byte gPlayerAvatar\n\t"
        ".syntax divided\n\t"
    );
}


u8 MovementAction_FlyUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->y2 = 0;
    sprite->sActionFuncId++;
    return FALSE;
}


u8 MovementAction_FlyUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->y2 -= 8;

    if (sprite->y2 == -DISPLAY_HEIGHT)
        sprite->sActionFuncId++;
    return FALSE;
}


u8 MovementAction_FlyDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->y2 = -DISPLAY_HEIGHT;
    sprite->sActionFuncId++;
    return FALSE;
}


u8 MovementAction_FlyDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->y2 += 8;

    if (!sprite->y2)
        sprite->sActionFuncId++;
    return FALSE;
}

u8 MovementAction_Finish(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return 1;
}
