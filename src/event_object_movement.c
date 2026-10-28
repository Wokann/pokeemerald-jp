#include "global.h"

#define OBJECT_EVENT_GRAPHICS_CUT_GRASS __attribute__((section(".rodata.object_event_graphics_cut_grass"), aligned(1)))
#define OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_OBJECT_DATA __attribute__((section(".rodata.object_event_graphics_field_effect_object_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_PALETTES __attribute__((section(".rodata.object_event_graphics_field_effect_palettes")))
#define OBJECT_EVENT_GRAPHICS_PLAYER_DATA __attribute__((section(".rodata.object_event_graphics_player_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA __attribute__((section(".rodata.object_event_graphics_player_extended_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_MAY_BASE_DATA __attribute__((section(".rodata.object_event_graphics_may_base_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA __attribute__((section(".rodata.object_event_graphics_may_action_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA __attribute__((section(".rodata.object_event_graphics_npc_people_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA __attribute__((section(".rodata.object_event_graphics_npc_people_extended_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA __attribute__((section(".rodata.object_event_graphics_special_object_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_DOLLS_DATA __attribute__((section(".rodata.object_event_graphics_dolls_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_MISC_DATA __attribute__((section(".rodata.object_event_graphics_misc_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_OPENING_DATA __attribute__((section(".rodata.object_event_graphics_opening_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_TRANSPORT_DATA __attribute__((section(".rodata.object_event_graphics_transport_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_SPARKLE_DATA __attribute__((section(".rodata.object_event_graphics_field_effect_sparkle_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_BERRY_TREE_GFX_DATA __attribute__((section(".rodata.object_event_graphics_berry_tree_gfx_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_SURF_BLOB_DATA __attribute__((section(".rodata.object_event_graphics_field_effect_surf_blob_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_QUINTY_PLUMP_DATA __attribute__((section(".rodata.object_event_graphics_quinty_plump_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_SHADOW_DATA __attribute__((section(".rodata.object_event_graphics_field_effect_shadow_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_EXTENDED_DATA __attribute__((section(".rodata.object_event_graphics_field_effect_extended_data"), aligned(4)))
#define OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_EXTENDED_DATA __attribute__((section(".rodata.object_event_graphics_special_object_extended_data"), aligned(4)))
#include "data/object_events/object_event_graphics.h"
#undef OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_EXTENDED_DATA
#undef OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_EXTENDED_DATA
#undef OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_SHADOW_DATA
#undef OBJECT_EVENT_GRAPHICS_QUINTY_PLUMP_DATA
#undef OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_SURF_BLOB_DATA
#undef OBJECT_EVENT_GRAPHICS_BERRY_TREE_GFX_DATA
#undef OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_SPARKLE_DATA
#undef OBJECT_EVENT_GRAPHICS_TRANSPORT_DATA
#undef OBJECT_EVENT_GRAPHICS_OPENING_DATA
#undef OBJECT_EVENT_GRAPHICS_MISC_DATA
#undef OBJECT_EVENT_GRAPHICS_DOLLS_DATA
#undef OBJECT_EVENT_GRAPHICS_SPECIAL_OBJECT_DATA
#undef OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_EXTENDED_DATA
#undef OBJECT_EVENT_GRAPHICS_NPC_PEOPLE_DATA
#undef OBJECT_EVENT_GRAPHICS_MAY_ACTION_DATA
#undef OBJECT_EVENT_GRAPHICS_MAY_BASE_DATA
#undef OBJECT_EVENT_GRAPHICS_PLAYER_EXTENDED_DATA
#undef OBJECT_EVENT_GRAPHICS_PLAYER_DATA
#undef OBJECT_EVENT_GRAPHICS_CUT_GRASS
#undef OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_OBJECT_DATA
#undef OBJECT_EVENT_GRAPHICS_FIELD_EFFECT_PALETTES
#include "event_object_movement.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "faraway_island.h"
#include "overworld.h"
#include "field_camera.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "metatile_behavior.h"
#include "palette.h"
#include "malloc.h"
#include "task.h"
#include "util.h"
#include "berry.h"
#include "battle_pyramid.h"
#include "trainer_hill.h"
#include "event_data.h"
#include "decoration.h"
#include "random.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/items.h"
#include "constants/mauville_old_man.h"
#include "constants/trainer_types.h"
#include "constants/decorations.h"

extern void MovementType_Hidden(struct Sprite *sprite);
void ObjectCB_CameraObject(struct Sprite *sprite);
void CameraObject_0(struct Sprite *sprite);
void CameraObject_1(struct Sprite *sprite);
void CameraObject_2(struct Sprite *sprite);

#define EVENT_OBJECT_MOVEMENT_REFLECTION_PALETTE_DATA __attribute__((section(".rodata.event_object_movement_reflection_palette_data"), aligned(1)))
#define EVENT_OBJECT_MOVEMENT_CAMERA_DATA __attribute__((section(".rodata.event_object_movement_camera_data"), aligned(4)))

EVENT_OBJECT_MOVEMENT_REFLECTION_PALETTE_DATA const u8 gReflectionEffectPaletteMap[16] =
{
    [PALSLOT_PLAYER]                 = PALSLOT_PLAYER_REFLECTION,
    [PALSLOT_PLAYER_REFLECTION]      = PALSLOT_PLAYER_REFLECTION,
    [PALSLOT_NPC_1]                  = PALSLOT_NPC_1_REFLECTION,
    [PALSLOT_NPC_2]                  = PALSLOT_NPC_2_REFLECTION,
    [PALSLOT_NPC_3]                  = PALSLOT_NPC_3_REFLECTION,
    [PALSLOT_NPC_4]                  = PALSLOT_NPC_4_REFLECTION,
    [PALSLOT_NPC_1_REFLECTION]       = PALSLOT_NPC_1_REFLECTION,
    [PALSLOT_NPC_2_REFLECTION]       = PALSLOT_NPC_2_REFLECTION,
    [PALSLOT_NPC_3_REFLECTION]       = PALSLOT_NPC_3_REFLECTION,
    [PALSLOT_NPC_4_REFLECTION]       = PALSLOT_NPC_4_REFLECTION,
    [PALSLOT_NPC_SPECIAL]            = PALSLOT_NPC_SPECIAL_REFLECTION,
    [PALSLOT_NPC_SPECIAL_REFLECTION] = PALSLOT_NPC_SPECIAL_REFLECTION,
};

EVENT_OBJECT_MOVEMENT_CAMERA_DATA static const struct SpriteTemplate sCameraSpriteTemplate =
{
    .tileTag = 0,
    .paletteTag = TAG_NONE,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = ObjectCB_CameraObject,
};

#undef EVENT_OBJECT_MOVEMENT_CAMERA_DATA
#undef EVENT_OBJECT_MOVEMENT_REFLECTION_PALETTE_DATA

extern const u32 gFieldEffectObjectPic_Arrow[];
extern const u32 gFieldEffectObjectPic_Ash[];
extern const u8 gFieldEffectObjectPic_AshLaunch[];
extern const u8 gFieldEffectObjectPic_AshPuff[];
extern const u8 gFieldEffectObjectPic_BikeTireTracks[];
extern const u8 gFieldEffectObjectPic_Bird[0x200];
extern const u8 gFieldEffectObjectPic_Bubbles[];
extern const u8 gFieldEffectObjectPic_DeepSandFootprints[];
extern const u8 gFieldEffectObjectPic_GroundImpactDust[];
extern const u8 gFieldEffectObjectPic_HotSpringsWater[0x80];
extern const u8 gFieldEffectObjectPic_JumpBigSplash[];
extern const u8 gFieldEffectObjectPic_JumpLongGrass[];
extern const u8 gFieldEffectObjectPic_JumpSmallSplash[];
extern const u8 gFieldEffectObjectPic_JumpTallGrass[];
extern const u8 gFieldEffectObjectPic_LongGrass[];
extern const u8 gFieldEffectObjectPic_MountainDisguise[];
extern const u32 gFieldEffectObjectPic_Ripple[];
extern const u8 gFieldEffectObjectPic_SandDisguisePlaceholder[];
extern const u8 gFieldEffectObjectPic_SandFootprints[];
extern const u8 gFieldEffectObjectPic_SandPile[];
extern const u8 gFieldEffectObjectPic_ShadowExtraLarge[0x400];
extern const u8 gFieldEffectObjectPic_ShadowLarge[0x80];
extern const u8 gFieldEffectObjectPic_ShadowMedium[0x40];
extern const u8 gFieldEffectObjectPic_ShadowSmall[0x20];
extern const u8 gFieldEffectObjectPic_ShortGrass[];
extern const u8 gFieldEffectObjectPic_SmallSparkle[];
extern const u8 gFieldEffectObjectPic_Sparkle[];
extern const u8 gFieldEffectObjectPic_Splash[];
extern const u8 gFieldEffectObjectPic_SurfBlob[];
extern const u8 gFieldEffectObjectPic_TallGrass[];
extern const u8 gFieldEffectObjectPic_TreeDisguise[];
extern const u8 gFieldEffectObjectPic_Unknown17[];
extern const u8 gFieldEffectObjectPic_UnusedGrass2[];
extern const u8 gFieldEffectObjectPic_UnusedSand[];
extern const u8 gFieldEffectObjectPic_WaterSurfacing[];
extern const u16 gFieldEffectPal_Ash[];
extern const u16 gFieldEffectPal_SmallSparkle[];
extern const struct OamData gObjectEventBaseOam_8x8;
extern const struct OamData gObjectEventBaseOam_16x8;
extern const struct OamData gObjectEventBaseOam_16x16;
extern const struct OamData gObjectEventBaseOam_32x8;
extern const struct OamData gObjectEventBaseOam_64x32;
extern const struct OamData gObjectEventBaseOam_16x32;
extern const struct OamData gObjectEventBaseOam_32x32;
extern const u32 gObjectEventPic_Rayquaza[];

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

// Keep this packed: the JP ROM places a 9-byte lookup directly before two
// unaligned function-pointer tables. The one source label below is used with
// field offsets by the retained naked functions, rather than linker aliases.
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

extern u8 gUnknown_2037254; // sCurrentReflectionType
extern u16 gUnknown_2037256; // sCurrentSpecialObjectPaletteTag
extern const struct Coords16 sDirectionToVectors[];
static u8 GetCollisionInDirection(struct ObjectEvent *, u8);
extern u32 state_to_direction(u8, u8, u8);
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

#define EVENT_OBJECT_MOVEMENT_BERRY_TREE_DATA __attribute__((section(".rodata.event_object_movement_berry_tree_graphics_data")))
#include "data/object_events/berry_tree_graphics_tables.h"
#undef EVENT_OBJECT_MOVEMENT_BERRY_TREE_DATA

#define EVENT_OBJECT_MOVEMENT_FIELD_EFFECT_OBJECT_TEMPLATE_POINTERS __attribute__((section(".rodata.event_object_movement_field_effect_object_template_pointers"), aligned(4)))
#include "data/field_effects/field_effect_object_template_pointers.h"
#undef EVENT_OBJECT_MOVEMENT_FIELD_EFFECT_OBJECT_TEMPLATE_POINTERS

#define EVENT_OBJECT_MOVEMENT_OBJECT_EVENT_PIC_TABLES __attribute__((section(".rodata.event_object_movement_object_event_pic_tables"), aligned(4), used))
#include "data/object_events/object_event_pic_tables.h"
#undef EVENT_OBJECT_MOVEMENT_OBJECT_EVENT_PIC_TABLES

#define EVENT_OBJECT_MOVEMENT_OBJECT_EVENT_ANIMS __attribute__((section(".rodata.event_object_movement_object_event_anims"), used))
#include "data/object_events/object_event_anims.h"
#undef EVENT_OBJECT_MOVEMENT_OBJECT_EVENT_ANIMS

#define EVENT_OBJECT_MOVEMENT_BASE_OAM_DATA __attribute__((section(".rodata.event_object_movement_base_oam_data"), aligned(4), used))
#include "data/object_events/base_oam.h"
#undef EVENT_OBJECT_MOVEMENT_BASE_OAM_DATA

#define EVENT_OBJECT_MOVEMENT_OBJECT_EVENT_SUBSPRITES __attribute__((section(".rodata.event_object_movement_object_event_subsprites"), used))
#include "data/object_events/object_event_subsprites.h"
#undef EVENT_OBJECT_MOVEMENT_OBJECT_EVENT_SUBSPRITES

#define EVENT_OBJECT_MOVEMENT_OBJECT_EVENT_GRAPHICS_INFO __attribute__((section(".rodata.event_object_movement_object_event_graphics_info"), aligned(4), used))
#include "data/object_events/object_event_graphics_info.h"
#undef EVENT_OBJECT_MOVEMENT_OBJECT_EVENT_GRAPHICS_INFO

#define EVENT_OBJECT_MOVEMENT_OBJECT_EVENT_GRAPHICS_INFO_POINTERS __attribute__((section(".rodata.event_object_movement_object_event_graphics_info_pointers"), aligned(4), used))
#include "data/object_events/object_event_graphics_info_pointers.h"
#undef EVENT_OBJECT_MOVEMENT_OBJECT_EVENT_GRAPHICS_INFO_POINTERS

#define EVENT_OBJECT_MOVEMENT_FIELD_EFFECT_OBJECT_DATA __attribute__((section(".rodata.event_object_movement_field_effect_objects_data")))
#include "data/field_effects/field_effect_objects.h"
#undef EVENT_OBJECT_MOVEMENT_FIELD_EFFECT_OBJECT_DATA

enum {
    CAMERA_STATE_INIT,
    CAMERA_STATE_MOVE,
    CAMERA_STATE_FROZEN,
};

#define EVENT_OBJECT_MOVEMENT_CAMERA_FUNCTION_DATA __attribute__((section(".rodata.event_object_movement_camera_function_data"), aligned(4)))

EVENT_OBJECT_MOVEMENT_CAMERA_FUNCTION_DATA static void (*const sCameraObjectFuncs[])(struct Sprite *) =
{
    [CAMERA_STATE_INIT] = CameraObject_0,
    [CAMERA_STATE_MOVE] = CameraObject_1,
    [CAMERA_STATE_FROZEN] = CameraObject_2,
};

#undef EVENT_OBJECT_MOVEMENT_CAMERA_FUNCTION_DATA

enum {
    BERRYTREEFUNC_NORMAL,
    BERRYTREEFUNC_MOVE,
    BERRYTREEFUNC_SPARKLE_START,
    BERRYTREEFUNC_SPARKLE,
    BERRYTREEFUNC_SPARKLE_END,
};

#define GROUND_EFFECT_FLAG_TALL_GRASS_ON_SPAWN   (1 << 0)
#define GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE    (1 << 1)
#define GROUND_EFFECT_FLAG_LONG_GRASS_ON_SPAWN   (1 << 2)
#define GROUND_EFFECT_FLAG_LONG_GRASS_ON_MOVE    (1 << 3)
#define GROUND_EFFECT_FLAG_WATER_REFLECTION      (1 << 4)
#define GROUND_EFFECT_FLAG_ICE_REFLECTION        (1 << 5)
#define GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER (1 << 6)
#define GROUND_EFFECT_FLAG_SAND                  (1 << 7)
#define GROUND_EFFECT_FLAG_DEEP_SAND             (1 << 8)
#define GROUND_EFFECT_FLAG_RIPPLES               (1 << 9)
#define GROUND_EFFECT_FLAG_PUDDLE                (1 << 10)
#define GROUND_EFFECT_FLAG_SAND_PILE             (1 << 11)
#define GROUND_EFFECT_FLAG_LAND_IN_TALL_GRASS    (1 << 12)
#define GROUND_EFFECT_FLAG_LAND_IN_LONG_GRASS    (1 << 13)
#define GROUND_EFFECT_FLAG_LAND_IN_SHALLOW_WATER (1 << 14)
#define GROUND_EFFECT_FLAG_LAND_IN_DEEP_WATER    (1 << 15)
#define GROUND_EFFECT_FLAG_LAND_ON_NORMAL_GROUND (1 << 16)
#define GROUND_EFFECT_FLAG_SHORT_GRASS           (1 << 17)
#define GROUND_EFFECT_FLAG_HOT_SPRINGS           (1 << 18)
#define GROUND_EFFECT_FLAG_SEAWEED               (1 << 19)

void EventObjectUpdateMetatileBehaviors(struct ObjectEvent *objectEvent);
bool8 EventObjectCheckForReflectiveSurface(struct ObjectEvent *objectEvent);
bool8 MovementType_CopyPlayer_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_CopyPlayer_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementType_CopyPlayerInGrass_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 GetTrainerFacingDirectionMovementType(u8 direction);
u8 GetCollisionInDirection(struct ObjectEvent *objectEvent, u8 direction);
u8 GetCollisionAtCoords(struct ObjectEvent *objectEvent, s16 x, s16 y, u32 dir);
u8 GetCollisionFlagsAtCoords(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction);
bool8 IsCoordOutsideObjectEventMovementRange(struct ObjectEvent *objectEvent, s16 x, s16 y);
bool8 IsMetatileDirectionallyImpassable(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction);
bool8 DoesObjectCollideWithObjectAt(struct ObjectEvent *objectEvent, s16 x, s16 y);
bool8 IsBerryTreeSparkling(u8 localId, u8 mapNum, u8 mapGroup);
void MoveCoordsInDirection(u8 direction, s16 *x, s16 *y, s16 deltaX, s16 deltaY);
u8 ObjectEventClearHeldMovementIfFinished(struct ObjectEvent *objectEvent);
// JP allocates 0x14 bytes; these handlers use the IDs and count, not the last three bytes.
struct EventObjectLockedAnimState
{
    u8 localIds[OBJECT_EVENTS_COUNT];
    u8 count;
    u8 reserved[3];
};
extern struct EventObjectLockedAnimState *gUnknown_2037258;
void EventObjectClearHeldMovement(struct ObjectEvent *objectEvent);
void UpdateEventObjectSpriteAnimPause(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void TryEnableEventObjectAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void UpdateEventObjSpriteVisibility(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 IsZCoordMismatchAt(u8 elevation, s16 x, s16 y);
void InitObjectPriorityByZCoord(struct Sprite *sprite, u8 elevation);
bool8 FreezeEventObject(struct ObjectEvent *objectEvent);
void FreezeEventObjectsExceptOne(u8 objectEventId);
void UnfreezeEventObject(struct ObjectEvent *objectEvent);
u8 MovementAction_StoreAndLockAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 MovementAction_FreeAndUnlockAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementAction_DestroyExtraTaskIfAtTop_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void ApplyLevitateMovement(u8 taskId);
void EventObjectExecHeldMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite);
u8 zffu_offset_calc(u8 a, u8 b);
u8 sub_08091FFC(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 AnimateSpriteInFigure8(struct Sprite *sprite);
void InitSpriteForFigure8Anim(struct Sprite *sprite);
bool8 sub_0809547C(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void maybe_shadow_1(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 distance, u8 type);
void InitAcroPopWheelieMove(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed);
s16 sub_08097190(s16 i, u8 type);
void sub_080976D8(struct Sprite *sprite);
extern const s8 *const sJumpYTable[3];
extern const s16 sJumpDistanceToTime[3];
extern const u8 sJumpDistanceToShift[3];
extern const s16 sJumpSpecialDistanceToTime[3];
extern const u8 sJumpSpecialDistanceToShift[3];
extern const char sEventObjectMovementSourceFile[];
extern const char sVirtualObjectAnimAssertExpression[];
void DoShadowFieldEffect(struct ObjectEvent *objectEvent);
void DoRippleFieldEffect(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void sub_08096A54(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void sub_0808DCFC(struct ObjectEvent *objectEvent);
extern const u8 SecretBase_EventScript_DollInteract[];
extern const u8 SecretBase_EventScript_CushionInteract[];
void RemoveObjectEventByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup);
void RemoveEventObjectInternal(struct ObjectEvent *objectEvent);
void get_berry_tree_graphics(struct ObjectEvent *objectEvent, struct Sprite *sprite);
const struct ObjectEventGraphicsInfo *GetObjectEventGraphicsInfo(u8 graphicsId);
void npc_by_local_id_and_map_set_field_1_bit_x20(u8 localId, u8 mapNum, u8 mapGroup, bool8 invisible);
void sub_0808E19C(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y);
void LoadEventObjectPalette(u16 paletteTag);
u8 FindEventObjectPaletteIndexByTag(u16 tag);
bool8 GetAvailableEventObjectId(u16 localId, u8 mapNum, u8 mapGroup, u8 *objectEventId);
void ClearEventObject(struct ObjectEvent *objectEvent);
void SetEventObjectDynamicGraphicsId(struct ObjectEvent *objectEvent);
u8 InitEventObjectStateFromTemplate(const struct ObjectEventTemplate *template, u8 mapNum, u8 mapGroup);
u8 TrySetupEventObjectSprite(const struct ObjectEventTemplate *objectEventTemplate, struct SpriteTemplate *spriteTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY);
u8 TrySpawnObjectEventTemplate(const struct ObjectEventTemplate *objectEventTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY);
u8 SpawnSpecialEventObject(struct ObjectEventTemplate *objectEventTemplate);
void sub_0808DB28(u8 objectEventId, s16 x, s16 y);
void sub_0808D6C0(struct ObjectEventTemplate *template, struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables);
void MakeObjectTemplateFromEventObjectGraphicsInfoWithCallbackIndex(u16 graphicsId, u16 callbackIndex, struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables);
void CopyObjectGraphicsInfoToSpriteTemplate(u16 graphicsId, void (*callback)(struct Sprite *), struct SpriteTemplate *spriteTemplate, const struct SubspriteTable **subspriteTables);
void SetPlayerAvatarEventObjectIdAndObjectId(u8 objectEventId, u8 spriteId);
u8 GetNumBattlePyramidEventObjects(void);
void SpriteCB_VirtualObject(struct Sprite *sprite);
extern const u8 gUnknown_84DDA21[NUM_MOVEMENT_TYPES];
extern const bool8 gUnknown_84DD9D0[NUM_MOVEMENT_TYPES];
void LoadObjectEventPaletteSet(u16 *paletteTags);
u8 sub_0808E264(const struct SpritePalette *spritePalette);
void MoveEventObjectToMapCoords(struct ObjectEvent *objectEvent, s16 x, s16 y);
void TryMoveEventObjectToMapCoords(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y);
void UpdateEventObjectCoordsForCameraUpdate(void);
struct Sprite *FindCameraObject(void);
u8 CopySprite(struct Sprite *sprite, s16 x, s16 y, u8 subpriority);
u8 CreateCopySpriteAt(struct Sprite *sprite, s16 x, s16 y, u8 subpriority);
const u8 *GetEventObjectScriptPointerByEventObjectId(u8 objectEventId);
u16 GetEventObjectFlagIdByEventObjectId(u8 objectEventId);
u8 sub_0808E9F0(u8 localId, u8 mapNum, u8 mapGroup);
u8 sub_0808EA44(u8 localId, u8 mapNum, u8 mapGroup);
struct ObjectEventTemplate *GetEventObjectTemplateByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup);
const struct ObjectEventTemplate *FindEventObjectTemplateByLocalId(u8 localId, const struct ObjectEventTemplate *templates, u8 count);
void OverrideTemplateCoordsForObjectEvent(const struct ObjectEvent *objectEvent);
void TryOverrideEventObjectTemplateCoords(u8 localId, u8 mapNum, u8 mapGroup);
void OverrideSecretBaseDecorationSpriteScript(u8 localId, u8 mapNum, u8 mapGroup, u8 decorationCategory);
void InitEventObjectPalettes(u8 reflectionType);
u16 GetObjectPaletteTag(u8 palSlot);
void GetEventObjectMovingCameraOffset(s16 *x, s16 *y);
void sub_08097460(void);
void sub_080928D0(u8 direction, s16 *destX, s16 *destY);
void sub_08092860(u8 localId, u8 mapNum, u8 mapGroup);
bool8 AreElevationsCompatible(u8 a, u8 b);
bool8 UpdateWalkSlowAnim(struct Sprite *sprite);
void oamt_npc_ministep_reset(struct Sprite *sprite, u8 direction, u8 speed);
void sub_0809704C(struct Sprite *sprite, u8 direction);
const struct StepAnimTable *sub_080923BC(const union AnimCmd *const *anims);
void npc_apply_anim_looping(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animNum);
void obj_npc_animation_step(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animNum);
bool8 ObjectEventExecSingleMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void FaceDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction);
void npc_apply_direction(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed);
void InitMovementNormal(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed);
void StartRunningAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction);
bool8 UpdateMovementNormal(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void sub_08093460(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction);
void InitWalkSlow(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction);
bool8 UpdateWalkSlow(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void sub_08093934(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 distance, u8 type);
void InitJumpSpecial(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction);
bool8 MovementAction_JumpInPlaceDownUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementAction_JumpInPlaceUpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementAction_JumpInPlaceLeftRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementAction_JumpInPlaceRightLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void InitFigure8Anim(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementAction_AcroWheelieJumpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementAction_AcroWheelieJumpUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementAction_AcroWheelieJumpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
bool8 MovementAction_AcroWheelieJumpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void InitAcroWheelieMove(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed);
void InitAcroEndWheelie(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed);
bool8 obj_npc_ministep(struct Sprite *sprite);
void sub_080971AC(struct Sprite *sprite, u8 direction, u8 distance, u8 type);
u8 FindLockedEventObjectIndex(struct ObjectEvent *objectEvent);
void UpdateObjectEventOffscreen(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void GetAllGroundEffectFlags_OnSpawn(struct ObjectEvent *objEvent, u32 *flags);
void GetAllGroundEffectFlags_OnBeginStep(struct ObjectEvent *objEvent, u32 *flags);
void GetAllGroundEffectFlags_OnFinishStep(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_Reflection(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_TallGrassOnSpawn(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_LongGrassOnSpawn(struct ObjectEvent *objEvent, u32 *flags);
void sub_0809615C(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_LongGrassOnBeginStep(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_Tracks(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_SandHeap(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_ShallowFlowingWater(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_Puddle(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_Ripple(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_ShortGrass(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_HotSprings(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_Seaweed(struct ObjectEvent *objEvent, u32 *flags);
void GetGroundEffectFlags_JumpLanding(struct ObjectEvent *objEvent, u32 *flags);
u8 GetReflectionTypeByMetatileBehavior(u32 metatileBehavior);
u8 GetLedgeJumpDirection(s16 x, s16 y, u8 direction);
void SetEventObjectSpriteOamTableForLongGrass(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void UpdateEventObjectZCoordAndPriority(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void EventObjectUpdateZCoord(struct ObjectEvent *objectEvent);
void SetObjectSubpriorityByElevation(u8 elevation, struct Sprite *sprite, u8 subpriority);
void GroundEffect_SpawnOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite);
void GroundEffect_StepOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite);
void GroundEffect_SpawnOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite);
void GroundEffect_StepOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite);
void GroundEffect_SandTracks(struct ObjectEvent *objEvent, struct Sprite *sprite);
void sub_08096984(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void DoTracksGroundEffect_Footprints(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a);
void DoTracksGroundEffect_BikeTireTracks(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a);
void GroundEffect_JumpOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite);
void GroundEffect_JumpOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite);
void GroundEffect_JumpOnShallowWater(struct ObjectEvent *objEvent, struct Sprite *sprite);
void GroundEffect_JumpOnWater(struct ObjectEvent *objEvent, struct Sprite *sprite);
void GroundEffect_JumpLandingDust(struct ObjectEvent *objEvent, struct Sprite *sprite);
void GroundEffect_Seaweed(struct ObjectEvent *objEvent, struct Sprite *sprite);
void DoFlaggedGroundEffects(struct ObjectEvent *objEvent, struct Sprite *sprite, u32 flags);
void filters_out_some_ground_effects(struct ObjectEvent *objEvent, u32 *flags);
void DoGroundEffects_OnSpawn(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void DoGroundEffects_OnBeginStep(struct ObjectEvent *objectEvent, struct Sprite *sprite);
void DoGroundEffects_OnFinishStep(struct ObjectEvent *objectEvent, struct Sprite *sprite);

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

#define EVENT_OBJECT_MOVEMENT_FIGURE8_DATA __attribute__((section(".rodata.event_object_movement_figure8_data"), aligned(1)))

static const s8 sFigure8XOffsets[FIGURE_8_LENGTH] EVENT_OBJECT_MOVEMENT_FIGURE8_DATA =
{
    1, 2, 2, 2, 2, 2, 2, 2,
    2, 2, 2, 1, 2, 2, 1, 2,
    2, 1, 2, 2, 1, 2, 1, 1,
    2, 1, 1, 2, 1, 1, 2, 1,
    1, 2, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 1, 0, 1, 1, 0,
    1, 0, 1, 0, 1, 0, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
};

static const s8 sFigure8YOffsets[FIGURE_8_LENGTH] EVENT_OBJECT_MOVEMENT_FIGURE8_DATA =
{
     0,  0,  1,  0,  0,  1,  0,  0,
     1,  0,  1,  1,  0,  1,  1,  0,
     1,  1,  0,  1,  1,  0,  1,  1,
     0,  0,  1,  0,  0,  1,  0,  0,
     1,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0, -1,  0,  0, -1,  0,  0,
    -1,  0, -1, -1,  0, -1, -1,  0,
    -1, -1, -1, -1, -1, -1, -1, -2,
};

#undef EVENT_OBJECT_MOVEMENT_FIGURE8_DATA

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
extern void ClearEventObjectMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite);
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
extern void sub_08093EC4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 animNum, u16 delay);
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

void CreateReflectionEffectSprites(void)
{
    u8 spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_REFLECTION_DISTORTION], 0, 0, 31);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    StartSpriteAffineAnim(&gSprites[spriteId], 0);
    gSprites[spriteId].invisible = TRUE;

    spriteId = CreateSpriteAtEnd(gFieldEffectObjectTemplatePointers[FLDEFFOBJ_REFLECTION_DISTORTION], 0, 0, 31);
    gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    InitSpriteAffineAnim(&gSprites[spriteId]);
    StartSpriteAffineAnim(&gSprites[spriteId], 1);
    gSprites[spriteId].invisible = TRUE;
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

u8 InitEventObjectStateFromTemplate(const struct ObjectEventTemplate *template, u8 mapNum, u8 mapGroup)
{
    struct ObjectEvent *objectEvent;
    u8 objectEventId;
    s16 x;
    s16 y;

    if (GetAvailableEventObjectId(template->localId, mapNum, mapGroup, &objectEventId))
        return OBJECT_EVENTS_COUNT;
    objectEvent = &gObjectEvents[objectEventId];
    ClearEventObject(objectEvent);
    x = template->x + MAP_OFFSET;
    y = template->y + MAP_OFFSET;
    objectEvent->active = TRUE;
    objectEvent->triggerGroundEffectsOnMove = TRUE;
    objectEvent->graphicsId = template->graphicsId;
    objectEvent->movementType = template->movementType;
    objectEvent->localId = template->localId;
    objectEvent->mapNum = mapNum;
    objectEvent->mapGroup = mapGroup;
    objectEvent->initialCoords.x = x;
    objectEvent->initialCoords.y = y;
    objectEvent->currentCoords.x = x;
    objectEvent->currentCoords.y = y;
    objectEvent->previousCoords.x = x;
    objectEvent->previousCoords.y = y;
    objectEvent->currentElevation = template->elevation;
    objectEvent->previousElevation = template->elevation;
    objectEvent->range.rangeX = template->movementRangeX;
    objectEvent->range.rangeY = template->movementRangeY;
    objectEvent->trainerType = template->trainerType;
    objectEvent->mapNum = mapNum;
    objectEvent->trainerRange_berryTreeId = template->trainerRange_berryTreeId;
    objectEvent->previousMovementDirection = gUnknown_84DDA21[template->movementType];
    SetEventObjectDirection(objectEvent, objectEvent->previousMovementDirection);
    SetEventObjectDynamicGraphicsId(objectEvent);
    if (gUnknown_84DD9D0[objectEvent->movementType])
    {
        if (objectEvent->range.rangeX == 0)
            objectEvent->range.rangeX++;
        if (objectEvent->range.rangeY == 0)
            objectEvent->range.rangeY++;
    }
    return objectEventId;
}

u8 Unref_TryInitLocalEventObject(u8 localId)
{
    u8 i;
    u8 objectEventCount;
    struct ObjectEventTemplate *template;

    if (gMapHeader.events != NULL)
    {
        if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
            objectEventCount = GetNumBattlePyramidEventObjects();
        else if (InTrainerHill())
            objectEventCount = HILL_TRAINERS_PER_FLOOR;
        else
            objectEventCount = gMapHeader.events->objectEventCount;

        for (i = 0; i < objectEventCount; i++)
        {
            template = &gSaveBlock1Ptr->objectEventTemplates[i];
            if (template->localId == localId && !FlagGet(template->flagId))
                return InitEventObjectStateFromTemplate(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
        }
    }
    return OBJECT_EVENTS_COUNT;
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



void RemoveObjectEventByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;
    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        FlagSet(GetEventObjectFlagIdByEventObjectId(objectEventId));
        RemoveObjectEvent(&gObjectEvents[objectEventId]);
    }
}

void RemoveEventObjectInternal(struct ObjectEvent *objectEvent)
{
    struct SpriteFrameImage image;
    image.size = GetObjectEventGraphicsInfo(objectEvent->graphicsId)->size;
    gSprites[objectEvent->spriteId].images = &image;
    DestroySprite(&gSprites[objectEvent->spriteId]);
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

u8 TrySetupEventObjectSprite(const struct ObjectEventTemplate *objectEventTemplate, struct SpriteTemplate *spriteTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    u8 spriteId;
    u8 paletteSlot;
    u8 objectEventId;
    struct Sprite *sprite;
    struct ObjectEvent *objectEvent;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    objectEventId = InitEventObjectStateFromTemplate(objectEventTemplate, mapNum, mapGroup);
    if (objectEventId == OBJECT_EVENTS_COUNT)
        return OBJECT_EVENTS_COUNT;

    objectEvent = &gObjectEvents[objectEventId];
    graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == PALSLOT_PLAYER)
    {
        LoadPlayerObjectReflectionPalette(graphicsInfo->paletteTag, paletteSlot);
    }
    else if (paletteSlot == PALSLOT_NPC_SPECIAL)
    {
        LoadSpecialObjectReflectionPalette(graphicsInfo->paletteTag, paletteSlot);
    }
    else if (paletteSlot >= 16)
    {
        paletteSlot -= 16;
        _PatchObjectPalette(graphicsInfo->paletteTag, paletteSlot);
    }

    if (objectEvent->movementType == MOVEMENT_TYPE_INVISIBLE)
        objectEvent->invisible = TRUE;

    *(u16 *)&spriteTemplate->paletteTag = TAG_NONE;
    spriteId = CreateSprite(spriteTemplate, 0, 0, 0);
    if (spriteId == MAX_SPRITES)
    {
        gObjectEvents[objectEventId].active = FALSE;
        return OBJECT_EVENTS_COUNT;
    }

    sprite = &gSprites[spriteId];
    GetMapCoordsFromSpritePos(objectEvent->currentCoords.x + cameraX, objectEvent->currentCoords.y + cameraY, &sprite->x, &sprite->y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->x += 8;
    sprite->y += 16 + sprite->centerToCornerVecY;
    sprite->oam.paletteNum = paletteSlot;
    sprite->coordOffsetEnabled = TRUE;
    sprite->data[0] = objectEventId;
    objectEvent->spriteId = spriteId;
    objectEvent->inanimate = graphicsInfo->inanimate;
    if (!objectEvent->inanimate)
        StartSpriteAnim(sprite, GetJumpInPlaceMovementAction(objectEvent->facingDirection));

    SetObjectSubpriorityByElevation(objectEvent->previousElevation, sprite, 1);
    UpdateObjectEventVisibility(objectEvent, sprite);
    return objectEventId;
}

u8 TrySpawnObjectEventTemplate(const struct ObjectEventTemplate *objectEventTemplate, u8 mapNum, u8 mapGroup, s16 cameraX, s16 cameraY)
{
    u8 objectEventId;
    struct SpriteTemplate spriteTemplate;
    struct SpriteFrameImage spriteFrameImage;
    const struct ObjectEventGraphicsInfo *graphicsInfo;
    const struct SubspriteTable *subspriteTables = NULL;

    graphicsInfo = GetObjectEventGraphicsInfo(objectEventTemplate->graphicsId);
    sub_0808D6C0(objectEventTemplate, &spriteTemplate, &subspriteTables);
    spriteFrameImage.size = graphicsInfo->size;
    spriteTemplate.images = &spriteFrameImage;
    objectEventId = TrySetupEventObjectSprite(objectEventTemplate, &spriteTemplate, mapNum, mapGroup, cameraX, cameraY);
    if (objectEventId == OBJECT_EVENTS_COUNT)
        return OBJECT_EVENTS_COUNT;

    gSprites[gObjectEvents[objectEventId].spriteId].images = graphicsInfo->images;
    if (subspriteTables)
        SetSubspriteTables(&gSprites[gObjectEvents[objectEventId].spriteId], subspriteTables);

    return objectEventId;
}

u8 SpawnSpecialEventObject(struct ObjectEventTemplate *objectEventTemplate)
{
    s16 cameraX;
    s16 cameraY;

    GetEventObjectMovingCameraOffset(&cameraX, &cameraY);
    return TrySpawnObjectEventTemplate(objectEventTemplate, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
}


u8 SpawnSpecialObjectEventParameterized(u8 graphicsId, u8 movementBehavior, u8 localId, s16 x, s16 y, u8 elevation)
{
    struct ObjectEventTemplate objectEventTemplate;

    x -= MAP_OFFSET;
    y -= MAP_OFFSET;
    objectEventTemplate.localId = localId;
    objectEventTemplate.graphicsId = graphicsId;
    objectEventTemplate.kind = OBJ_KIND_NORMAL;
    objectEventTemplate.x = x;
    objectEventTemplate.y = y;
    objectEventTemplate.elevation = elevation;
    objectEventTemplate.movementType = movementBehavior;
    objectEventTemplate.movementRangeX = 0;
    objectEventTemplate.movementRangeY = 0;
    objectEventTemplate.trainerType = TRAINER_TYPE_NONE;
    objectEventTemplate.trainerRange_berryTreeId = 0;
    return SpawnSpecialEventObject(&objectEventTemplate);
}

u8 TrySpawnObjectEvent(u8 localId, u8 mapNum, u8 mapGroup)
{
    const struct ObjectEventTemplate *objectEventTemplate;
    s16 cameraX, cameraY;

    objectEventTemplate = GetEventObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup);
    if (!objectEventTemplate)
        return OBJECT_EVENTS_COUNT;

    GetEventObjectMovingCameraOffset(&cameraX, &cameraY);
    return TrySpawnObjectEventTemplate(objectEventTemplate, mapNum, mapGroup, cameraX, cameraY);
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

u8 AddPseudoEventObject(u16 graphicsId, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority)
{
    struct SpriteTemplate *spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    struct Sprite *sprite;
    u8 spriteId;

    spriteTemplate = Alloc(sizeof(struct SpriteTemplate));
    CopyObjectGraphicsInfoToSpriteTemplate(graphicsId, callback, spriteTemplate, &subspriteTables);
    if (spriteTemplate->paletteTag != TAG_NONE)
        LoadEventObjectPalette(spriteTemplate->paletteTag);

    spriteId = CreateSprite(spriteTemplate, x, y, subpriority);
    Free(spriteTemplate);

    if (spriteId != MAX_SPRITES && subspriteTables != NULL)
    {
        sprite = &gSprites[spriteId];
        SetSubspriteTables(sprite, subspriteTables);
        sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
    }
    return spriteId;
}

u8 sprite_new(u8 graphicsId, u8 virtualObjId, s16 x, s16 y, u8 elevation, u8 direction)
{
    u8 spriteId;
    struct Sprite *sprite;
    struct SpriteTemplate spriteTemplate;
    const struct SubspriteTable *subspriteTables;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    graphicsInfo = GetObjectEventGraphicsInfo(graphicsId);
    CopyObjectGraphicsInfoToSpriteTemplate(graphicsId, SpriteCB_VirtualObject, &spriteTemplate, &subspriteTables);
    *(u16 *)&spriteTemplate.paletteTag = TAG_NONE;
    x += MAP_OFFSET;
    y += MAP_OFFSET;
    SetSpritePosToOffsetMapCoords(&x, &y, 8, 16);
    spriteId = CreateSpriteAtEnd(&spriteTemplate, x, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        sprite = &gSprites[spriteId];
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->y += sprite->centerToCornerVecY;
        sprite->oam.paletteNum = graphicsInfo->paletteSlot;
        if (sprite->oam.paletteNum >= 16)
            sprite->oam.paletteNum -= 16;

        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = virtualObjId;
        sprite->data[1] = elevation;
        if (graphicsInfo->paletteSlot == PALSLOT_NPC_SPECIAL)
            LoadSpecialObjectReflectionPalette(graphicsInfo->paletteTag, graphicsInfo->paletteSlot);
        else if (graphicsInfo->paletteSlot >= 16)
            _PatchObjectPalette(graphicsInfo->paletteTag, graphicsInfo->paletteSlot | 0xf0);

        if (subspriteTables != NULL)
        {
            SetSubspriteTables(sprite, subspriteTables);
            sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        }
        InitObjectPriorityByZCoord(sprite, elevation);
        SetObjectSubpriorityByElevation(elevation, sprite, 1);
        StartSpriteAnim(sprite, GetJumpInPlaceMovementAction(direction));
    }
    return spriteId;
}

void TrySpawnObjectEvents(s16 cameraX, s16 cameraY)
{
    u8 i;
    u8 objectCount;

    if (gMapHeader.events != NULL)
    {
        s16 left = gSaveBlock1Ptr->pos.x - 2;
        s16 right = gSaveBlock1Ptr->pos.x + MAP_OFFSET_W + 2;
        s16 top = gSaveBlock1Ptr->pos.y;
        s16 bottom = gSaveBlock1Ptr->pos.y + MAP_OFFSET_H + 2;

        if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
            objectCount = GetNumBattlePyramidEventObjects();
        else if (InTrainerHill())
            objectCount = HILL_TRAINERS_PER_FLOOR;
        else
            objectCount = gMapHeader.events->objectEventCount;

        for (i = 0; i < objectCount; i++)
        {
            struct ObjectEventTemplate *template = &gSaveBlock1Ptr->objectEventTemplates[i];
            s16 npcX = template->x + MAP_OFFSET;
            s16 npcY = template->y + MAP_OFFSET;

            if (top <= npcY && bottom >= npcY && left <= npcX && right >= npcX
                && !FlagGet(template->flagId))
                TrySpawnObjectEventTemplate(template, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, cameraX, cameraY);
        }
    }
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

void sub_0808DADC(s16 x, s16 y)
{
    u8 i;

    ClearPlayerAvatarInfo();
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active)
            sub_0808DB28(i, x, y);
    }
    CreateReflectionEffectSprites();
}

void sub_0808DB28(u8 objectEventId, s16 x, s16 y)
{
    u8 i;
    u8 paletteSlot;
    struct Sprite *sprite;
    struct ObjectEvent *objectEvent;
    struct SpriteTemplate spriteTemplate;
    struct SpriteFrameImage spriteFrameImage;
    const struct SubspriteTable *subspriteTables;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    for (i = 0; i < ARRAY_COUNT(gLinkPlayerObjectEvents); i++)
    {
        if (gLinkPlayerObjectEvents[i].active && objectEventId == gLinkPlayerObjectEvents[i].objEventId)
            return;
    }

    objectEvent = &gObjectEvents[objectEventId];
    subspriteTables = NULL;
    graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    spriteFrameImage.size = graphicsInfo->size;
    MakeObjectTemplateFromEventObjectGraphicsInfoWithCallbackIndex(objectEvent->graphicsId, objectEvent->movementType, &spriteTemplate, &subspriteTables);
    spriteTemplate.images = &spriteFrameImage;

    *(u16 *)&spriteTemplate.paletteTag = TAG_NONE;
    paletteSlot = graphicsInfo->paletteSlot;
    if (paletteSlot == PALSLOT_PLAYER)
    {
        LoadPlayerObjectReflectionPalette(graphicsInfo->paletteTag, graphicsInfo->paletteSlot);
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
    *(u16 *)&spriteTemplate.paletteTag = TAG_NONE;

    i = CreateSprite(&spriteTemplate, 0, 0, 0);
    if (i != MAX_SPRITES)
    {
        sprite = &gSprites[i];
        GetMapCoordsFromSpritePos(x + objectEvent->currentCoords.x, y + objectEvent->currentCoords.y, &sprite->x, &sprite->y);
        sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
        sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
        sprite->x += 8;
        sprite->y += 16 + sprite->centerToCornerVecY;
        sprite->images = graphicsInfo->images;
        if (objectEvent->movementType == MOVEMENT_TYPE_PLAYER)
        {
            SetPlayerAvatarEventObjectIdAndObjectId(objectEventId, i);
            objectEvent->warpArrowSpriteId = CreateWarpArrowSprite();
        }
        if (subspriteTables != NULL)
            SetSubspriteTables(sprite, subspriteTables);

        sprite->oam.paletteNum = paletteSlot;
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = objectEventId;
        objectEvent->spriteId = i;
        if (!objectEvent->inanimate && objectEvent->movementType != MOVEMENT_TYPE_PLAYER)
            StartSpriteAnim(sprite, GetJumpInPlaceMovementAction(objectEvent->facingDirection));

        sub_0808DCFC(objectEvent);
        SetObjectSubpriorityByElevation(objectEvent->previousElevation, sprite, 1);
    }
}

void sub_0808DCFC(struct ObjectEvent *objectEvent)
{
    objectEvent->singleMovementActive = FALSE;
    objectEvent->triggerGroundEffectsOnMove = TRUE;
    objectEvent->hasShadow = FALSE;
    objectEvent->hasReflection = FALSE;
    objectEvent->inShortGrass = FALSE;
    objectEvent->inShallowFlowingWater = FALSE;
    objectEvent->inSandPile = FALSE;
    objectEvent->inHotSprings = FALSE;
    EventObjectClearHeldMovement(objectEvent);
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

void get_berry_tree_graphics(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 berryStage;
    u8 berryId;

    objectEvent->invisible = TRUE;
    sprite->invisible = TRUE;
    berryStage = GetStageByBerryTreeId(objectEvent->trainerRange_berryTreeId);
    if (berryStage != BERRY_STAGE_NO_BERRY)
    {
        objectEvent->invisible = FALSE;
        sprite->invisible = FALSE;
        berryId = GetBerryTypeByBerryTreeId(objectEvent->trainerRange_berryTreeId) - 1;
        berryStage--;
        if (berryId > ITEM_TO_BERRY(LAST_BERRY_INDEX))
            berryId = 0;

        ObjectEventSetGraphicsId(objectEvent, gBerryTreeObjectEventGraphicsIdTablePointers[berryId][berryStage]);
        sprite->images = gBerryTreePicTablePointers[berryId];
        sprite->oam.paletteNum = gBerryTreePaletteSlotTablePointers[berryId][berryStage];
        StartSpriteAnim(sprite, berryStage);
    }
}


const struct ObjectEventGraphicsInfo *GetObjectEventGraphicsInfo(u8 graphicsId)
{
    u8 bard;

    if (graphicsId >= OBJ_EVENT_GFX_VARS)
        graphicsId = VarGetObjectEventGraphicsId(graphicsId - OBJ_EVENT_GFX_VARS);

    if (graphicsId == OBJ_EVENT_GFX_BARD)
    {
        bard = GetCurrentMauvilleOldMan();
        return gMauvilleOldManGraphicsInfoPointers[bard];
    }

    if (graphicsId >= NUM_OBJ_EVENT_GFX)
        graphicsId = OBJ_EVENT_GFX_NINJA_BOY;

    return gObjectEventGraphicsInfoPointers[graphicsId];
}

void SetEventObjectDynamicGraphicsId(struct ObjectEvent *objectEvent)
{
    if (objectEvent->graphicsId >= OBJ_EVENT_GFX_VARS)
        // JP 原版用 u8 回绕的 +0x10 计算 var 索引（等价于 - OBJ_EVENT_GFX_VARS 模 256）。
        objectEvent->graphicsId = VarGetObjectEventGraphicsId((u8)(objectEvent->graphicsId + 0x10));
}

void npc_by_local_id_and_map_set_field_1_bit_x20(u8 localId, u8 mapNum, u8 mapGroup, bool8 invisible)
{
    u8 objectEventId;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
        gObjectEvents[objectEventId].invisible = invisible;
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

void sub_0808E19C(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 objectEventId;
    struct Sprite *sprite;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        sprite = &gSprites[gObjectEvents[objectEventId].spriteId];
        sprite->x2 = x;
        sprite->y2 = y;
    }
}

void FreeAndReserveObjectSpritePalettes(void)
{
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 12; // OBJ_PALSLOT_COUNT
}

void LoadEventObjectPalette(u16 paletteTag)
{
    u16 i = FindEventObjectPaletteIndexByTag(paletteTag);

    // Preserve JP's 0x11FF sentinel check, although lookup failure returns 0xFF.
    if (i != OBJ_EVENT_PAL_TAG_NONE)
        sub_0808E264(&sObjectEventSpritePalettes[i]);
}

void LoadObjectEventPaletteSet(u16 *paletteTags)
{
    u8 i;

    for (i = 0; paletteTags[i] != OBJ_EVENT_PAL_TAG_NONE; i++)
        LoadEventObjectPalette(paletteTags[i]);
}

u8 sub_0808E264(const struct SpritePalette *spritePalette)
{
    if (IndexOfSpritePaletteTag(spritePalette->tag) != 0xFF)
        return 0xFF;

    return LoadSpritePalette(spritePalette);
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

void MoveEventObjectToMapCoords(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    struct Sprite *sprite;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    sprite = &gSprites[objectEvent->spriteId];
    graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    SetEventObjectCoords(objectEvent, x, y);
    SetSpritePosToMapCoords(objectEvent->currentCoords.x, objectEvent->currentCoords.y, &sprite->x, &sprite->y);
    sprite->centerToCornerVecX = -(graphicsInfo->width >> 1);
    sprite->centerToCornerVecY = -(graphicsInfo->height >> 1);
    sprite->x += 8;
    sprite->y += 16 + sprite->centerToCornerVecY;
    sub_0808DCFC(objectEvent);
    if (objectEvent->trackedByCamera)
        CameraObjectReset();
}

void TryMoveEventObjectToMapCoords(u8 localId, u8 mapNum, u8 mapGroup, s16 x, s16 y)
{
    u8 objectEventId;
    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        x += MAP_OFFSET;
        y += MAP_OFFSET;
        MoveEventObjectToMapCoords(&gObjectEvents[objectEventId], x, y);
    }
}

void ShiftStillEventObjectCoords(struct ObjectEvent *objectEvent)
{
    ShiftEventObjectCoords(objectEvent, objectEvent->currentCoords.x, objectEvent->currentCoords.y);
}

void UpdateEventObjectCoordsForCameraUpdate(void)
{
    u8 i;
    s16 dx;
    s16 dy;

    if (gCamera.active)
    {
        dx = gCamera.x;
        dy = gCamera.y;
        for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        {
            if (gObjectEvents[i].active)
            {
                gObjectEvents[i].initialCoords.x -= dx;
                gObjectEvents[i].initialCoords.y -= dy;
                gObjectEvents[i].currentCoords.x -= dx;
                gObjectEvents[i].currentCoords.y -= dy;
                gObjectEvents[i].previousCoords.x -= dx;
                gObjectEvents[i].previousCoords.y -= dy;
            }
        }
    }
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

    spriteId = CreateSprite(&sCameraSpriteTemplate, 0, 0, 4);
    gSprites[spriteId].invisible = TRUE;
    gSprites[spriteId].sCamera_FollowSpriteId = followSpriteId;
    return spriteId;
}

void ObjectCB_CameraObject(struct Sprite *sprite)
{
    void (*callbacks[3])(struct Sprite *);

    memcpy(callbacks, sCameraObjectFuncs, sizeof callbacks);
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

struct Sprite *FindCameraObject(void)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (gSprites[i].inUse && gSprites[i].callback == ObjectCB_CameraObject)
            return &gSprites[i];
    }
    return NULL;
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

u8 CopySprite(struct Sprite *sprite, s16 x, s16 y, u8 subpriority)
{
    u8 i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        if (!gSprites[i].inUse)
        {
            gSprites[i] = *sprite;
            gSprites[i].x = x;
            gSprites[i].y = y;
            gSprites[i].subpriority = subpriority;
            break;
        }
    }
    return i;
}

u8 CreateCopySpriteAt(struct Sprite *sprite, s16 x, s16 y, u8 subpriority)
{
    s16 i;

    for (i = MAX_SPRITES - 1; i > -1; i--)
    {
        if (!gSprites[i].inUse)
        {
            gSprites[i] = *sprite;
            gSprites[i].x = x;
            gSprites[i].y = y;
            gSprites[i].subpriority = subpriority;
            return i;
        }
    }
    return MAX_SPRITES;
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

const u8 *GetEventObjectScriptPointerByEventObjectId(u8 objectEventId)
{
    return GetObjectEventScriptPointerByLocalIdAndMap(gObjectEvents[objectEventId].localId, gObjectEvents[objectEventId].mapNum, gObjectEvents[objectEventId].mapGroup);
}

u16 GetObjectEventFlagIdByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    return GetEventObjectTemplateByLocalIdAndMap(localId, mapNum, mapGroup)->flagId;
}

u16 GetEventObjectFlagIdByEventObjectId(u8 objectEventId)
{
    return GetObjectEventFlagIdByLocalIdAndMap(gObjectEvents[objectEventId].localId, gObjectEvents[objectEventId].mapNum, gObjectEvents[objectEventId].mapGroup);
}

u8 sub_0808E9F0(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
        return 0xFF;

    return gObjectEvents[objectEventId].trainerType;
}

u8 GetObjectTrainerTypeByObjectEventId(u8 objectEventId)
{
    return gObjectEvents[objectEventId].trainerType;
}

u8 sub_0808EA44(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;

    if (TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
        return 0xFF;

    return gObjectEvents[objectEventId].trainerRange_berryTreeId;
}

u8 GetObjectEventBerryTreeId(u8 objectEventId)
{
    return gObjectEvents[objectEventId].trainerRange_berryTreeId;
}

struct ObjectEventTemplate *GetEventObjectTemplateByLocalIdAndMap(u8 localId, u8 mapNum, u8 mapGroup)
{
    const struct ObjectEventTemplate *templates;
    const struct MapHeader *mapHeader;
    u8 count;

    if (gSaveBlock1Ptr->location.mapNum == mapNum && gSaveBlock1Ptr->location.mapGroup == mapGroup)
    {
        templates = gSaveBlock1Ptr->objectEventTemplates;
        count = gMapHeader.events->objectEventCount;
    }
    else
    {
        mapHeader = Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum);
        templates = mapHeader->events->objectEvents;
        count = mapHeader->events->objectEventCount;
    }
    return FindEventObjectTemplateByLocalId(localId, templates, count);
}

const struct ObjectEventTemplate *FindEventObjectTemplateByLocalId(u8 localId, const struct ObjectEventTemplate *templates, u8 count)
{
    u8 i;

    for (i = 0; i < count; i++)
    {
        if (templates[i].localId == localId)
            return &templates[i];
    }
    return NULL;
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


void OverrideTemplateCoordsForObjectEvent(const struct ObjectEvent *objectEvent)
{
    struct ObjectEventTemplate *objectEventTemplate;

    objectEventTemplate = GetBaseTemplateForObjectEvent(objectEvent);
    if (objectEventTemplate != NULL)
    {
        objectEventTemplate->x = objectEvent->currentCoords.x - MAP_OFFSET;
        objectEventTemplate->y = objectEvent->currentCoords.y - MAP_OFFSET;
    }
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

void TryOverrideEventObjectTemplateCoords(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;
    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
        OverrideTemplateCoordsForObjectEvent(&gObjectEvents[objectEventId]);
}

void OverrideSecretBaseDecorationSpriteScript(u8 localId, u8 mapNum, u8 mapGroup, u8 decorationCategory)
{
    u8 objectEventId;
    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
    {
        switch (decorationCategory)
        {
        case DECORCAT_DOLL:
            OverrideObjectEventTemplateScript(&gObjectEvents[objectEventId], SecretBase_EventScript_DollInteract);
            break;
        case DECORCAT_CUSHION:
            OverrideObjectEventTemplateScript(&gObjectEvents[objectEventId], SecretBase_EventScript_CushionInteract);
            break;
        }
    }
}

void InitEventObjectPalettes(u8 reflectionType)
{
    FreeAndReserveObjectSpritePalettes();
    gUnknown_2037256 = OBJ_EVENT_PAL_TAG_NONE;
    gUnknown_2037254 = reflectionType;
    if (reflectionType == 1)
    {
        PatchObjectPaletteRange(sObjectPaletteTagSets[gUnknown_2037254], PALSLOT_PLAYER, PALSLOT_NPC_4 + 1);
        gReservedSpritePaletteCount = 8;
    }
    else
    {
        PatchObjectPaletteRange(sObjectPaletteTagSets[gUnknown_2037254], PALSLOT_PLAYER, PALSLOT_NPC_4_REFLECTION + 1);
    }
}

u16 GetObjectPaletteTag(u8 palSlot)
{
    u8 i;

    if (palSlot < PALSLOT_NPC_SPECIAL)
        return sObjectPaletteTagSets[gUnknown_2037254][palSlot];

    for (i = 0; sSpecialObjectReflectionPaletteSets[i].tag != OBJ_EVENT_PAL_TAG_NONE; i++)
    {
        if (sSpecialObjectReflectionPaletteSets[i].tag == gUnknown_2037256)
            return sSpecialObjectReflectionPaletteSets[i].data[gUnknown_2037254];
    }
    return OBJ_EVENT_PAL_TAG_NONE;
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

bool8 MovementType_WanderAround_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (!ObjectEventExecSingleMovementAction(objectEvent, sprite))
        return FALSE;
    SetMovementDelay(sprite, sMovementDelaysMedium[Random() % ARRAY_COUNT(sMovementDelaysMedium)]);
    sprite->sTypeFuncId = 3;
    return TRUE;
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

bool8 EventObjectIsTrainerAndCloseToPlayer(struct ObjectEvent *objectEvent)
{
    s16 playerX;
    s16 playerY;
    s16 objX;
    s16 objY;
    s16 minX;
    s16 maxX;
    s16 minY;
    s16 maxY;

    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_DASH))
        return FALSE;

    if (objectEvent->trainerType != TRAINER_TYPE_NORMAL && objectEvent->trainerType != TRAINER_TYPE_BURIED)
        return FALSE;

    PlayerGetDestCoords(&playerX, &playerY);
    objX = objectEvent->currentCoords.x;
    objY = objectEvent->currentCoords.y;
    minX = objX - objectEvent->trainerRange_berryTreeId;
    minY = objY - objectEvent->trainerRange_berryTreeId;
    maxX = objX + objectEvent->trainerRange_berryTreeId;
    maxY = objY + objectEvent->trainerRange_berryTreeId;
    if (minX > playerX || maxX < playerX
     || minY > playerY || maxY < playerY)
        return FALSE;

    return TRUE;
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

bool8 MovementType_LookAround_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysMedium[Random() % ARRAY_COUNT(sMovementDelaysMedium)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_WanderUpAndDown_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (!ObjectEventExecSingleMovementAction(objectEvent, sprite))
        return FALSE;

    SetMovementDelay(sprite, sMovementDelaysMedium[Random() % ARRAY_COUNT(sMovementDelaysMedium)]);
    sprite->sTypeFuncId = 3;
    return TRUE;
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

bool8 MovementType_WanderUpAndDown_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gUpAndDownDirections, sizeof directions);
    direction = directions[Random() & 1];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 5;
    if (GetCollisionInDirection(objectEvent, direction))
        sprite->sTypeFuncId = 1;

    return TRUE;
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

bool8 MovementType_WanderLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (!ObjectEventExecSingleMovementAction(objectEvent, sprite))
        return FALSE;

    SetMovementDelay(sprite, sMovementDelaysMedium[Random() % ARRAY_COUNT(sMovementDelaysMedium)]);
    sprite->sTypeFuncId = 3;
    return TRUE;
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

bool8 MovementType_WanderLeftAndRight_Step4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u8 direction;
    u8 directions[2];
    memcpy(directions, gLeftAndRightDirections, sizeof directions);
    direction = directions[Random() & 1];
    SetEventObjectDirection(objectEvent, direction);
    sprite->sTypeFuncId = 5;
    if (GetCollisionInDirection(objectEvent, direction))
        sprite->sTypeFuncId = 1;

    return TRUE;
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


void MovementType_BerryTreeGrowth(struct Sprite *sprite)
{
    struct ObjectEvent *objectEvent;

    objectEvent = &gObjectEvents[sprite->sObjEventId];
    if (!(sprite->data[7] & 1))
    {
        get_berry_tree_graphics(objectEvent, sprite);
        sprite->data[7] |= 1;
    }
    UpdateEventObjectCurrentMovement(objectEvent, sprite, MovementType_FaceDownAndUp_callback);
}

u8 MovementType_FaceDownAndUp_callback(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_BerryTreeGrowth[sprite->sTypeFuncId](objectEvent, sprite);
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

bool8 MovementType_FaceDownAndUp_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysMedium[Random() % ARRAY_COUNT(sMovementDelaysMedium)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_FaceLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysMedium[Random() % ARRAY_COUNT(sMovementDelaysMedium)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_FaceUpAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysShort[Random() % ARRAY_COUNT(sMovementDelaysShort)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_FaceUpAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysShort[Random() % ARRAY_COUNT(sMovementDelaysShort)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_FaceDownAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysShort[Random() % ARRAY_COUNT(sMovementDelaysShort)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_FaceDownAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysShort[Random() % ARRAY_COUNT(sMovementDelaysShort)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_FaceDownUpAndLeft_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysShort[Random() % ARRAY_COUNT(sMovementDelaysShort)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_FaceDownUpAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysShort[Random() % ARRAY_COUNT(sMovementDelaysShort)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_FaceUpLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysShort[Random() % ARRAY_COUNT(sMovementDelaysShort)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_FaceDownLeftAndRight_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        SetMovementDelay(sprite, sMovementDelaysShort[Random() % ARRAY_COUNT(sMovementDelaysShort)]);
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 3;
    }
    return FALSE;
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

bool8 MovementType_CopyPlayer_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (gObjectEvents[gPlayerAvatar.objectEventId].movementActionId == MOVEMENT_ACTION_NONE || gPlayerAvatar.tileTransitionState == T_TILE_CENTER)
        return FALSE;

    return gCopyPlayerMovementFuncs[PlayerGetCopyableMovement()](objectEvent, sprite, GetPlayerMovementDirection(), NULL);
}

bool8 MovementType_CopyPlayer_Step2(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (ObjectEventExecSingleMovementAction(objectEvent, sprite))
    {
        objectEvent->singleMovementActive = FALSE;
        sprite->sTypeFuncId = 1;
    }
    return FALSE;
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

// Keep the JP copy-movement handlers in asm: the narrow US result contract
// changes an existing C caller, and preserving the 32-bit JP contract changes
// agbcc input-mask/register scheduling even with size-matched wide locals.
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

bool8 MovementType_CopyPlayerInGrass_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (gObjectEvents[gPlayerAvatar.objectEventId].movementActionId == MOVEMENT_ACTION_NONE || gPlayerAvatar.tileTransitionState == T_TILE_CENTER)
        return FALSE;

    return gCopyPlayerMovementFuncs[PlayerGetCopyableMovement()](objectEvent, sprite, GetPlayerMovementDirection(), MetatileBehavior_IsPokeGrass);
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

void MovementType_Hidden(struct Sprite *sprite)
{
    if (!sprite->data[7])
    {
        gObjectEvents[sprite->sObjEventId].fixedPriority = TRUE;
        sprite->subspriteMode = SUBSPRITES_IGNORE_PRIORITY;
        sprite->oam.priority = 3;
        sprite->data[7]++;
    }
    UpdateEventObjectCurrentMovement(&gObjectEvents[sprite->sObjEventId], sprite, sub_08091FFC);
}

bool8 sub_08091FFC(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    return gMovementTypeFuncs_Buried[sprite->sTypeFuncId](objectEvent, sprite);
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


void ClearEventObjectMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    objectEvent->singleMovementActive = FALSE;
    objectEvent->heldMovementActive = FALSE;
    objectEvent->heldMovementFinished = FALSE;
    objectEvent->movementActionId = MOVEMENT_ACTION_NONE;
    sprite->sTypeFuncId = 0;
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

const struct StepAnimTable *sub_080923BC(const union AnimCmd *const *anims)
{
    const struct StepAnimTable *stepTable;

    for (stepTable = sStepAnimTables; stepTable->anims != NULL; stepTable++)
    {
        if (stepTable->anims == anims)
            return stepTable;
    }
    return NULL;
}

void npc_apply_anim_looping(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animNum)
{
    const struct StepAnimTable *stepTable;

    if (!objectEvent->inanimate)
    {
        sprite->animNum = animNum;
        stepTable = sub_080923BC(sprite->anims);
        if (stepTable != NULL)
        {
            if (sprite->animCmdIndex == stepTable->animPos[0])
                sprite->animCmdIndex  = stepTable->animPos[3];
            else if (sprite->animCmdIndex == stepTable->animPos[1])
                sprite->animCmdIndex = stepTable->animPos[2];
        }
        SeekSpriteAnim(sprite, sprite->animCmdIndex);
    }
}

void obj_npc_animation_step(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animNum)
{
    const struct StepAnimTable *stepTable;

    if (!objectEvent->inanimate)
    {
        u8 animPos;

        sprite->animNum = animNum;
        stepTable = sub_080923BC(sprite->anims);
        if (stepTable != NULL)
        {
            animPos = stepTable->animPos[1];
            if (sprite->animCmdIndex <= stepTable->animPos[0])
                animPos = stepTable->animPos[0];

            SeekSpriteAnim(sprite, animPos);
        }
    }
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

__attribute__((section(".text.GroundEffect_DeepSandTracks"))) u8 GetTrainerFacingDirectionMovementType(u8 direction)
{
    return sEventObjectMovementDirectionData.trainerFacingDirectionMovementTypes[direction];
}

u8 GetCollisionInDirection(struct ObjectEvent *objectEvent, u8 direction)
{
    s16 x = objectEvent->currentCoords.x;
    s16 y = objectEvent->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return GetCollisionAtCoords(objectEvent, x, y, direction);
}

u8 GetCollisionAtCoords(struct ObjectEvent *objectEvent, s16 x, s16 y, u32 dir)
{
    u8 direction = dir;

    if (IsCoordOutsideObjectEventMovementRange(objectEvent, x, y))
        return COLLISION_OUTSIDE_RANGE;
    else if (MapGridGetCollisionAt(x, y) || GetMapBorderIdAt(x, y) == CONNECTION_INVALID || IsMetatileDirectionallyImpassable(objectEvent, x, y, direction))
        return COLLISION_IMPASSABLE;
    else if (objectEvent->trackedByCamera && !CanCameraMoveInDirection(direction))
        return COLLISION_IMPASSABLE;
    else if (IsZCoordMismatchAt(objectEvent->currentElevation, x, y))
        return COLLISION_ELEVATION_MISMATCH;
    else if (DoesObjectCollideWithObjectAt(objectEvent, x, y))
        return COLLISION_OBJECT_EVENT;
    return COLLISION_NONE;
}

u8 GetCollisionFlagsAtCoords(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction)
{
    u8 flags = 0;

    if (IsCoordOutsideObjectEventMovementRange(objectEvent, x, y))
        flags |= 1 << (COLLISION_OUTSIDE_RANGE - 1);
    if (MapGridGetCollisionAt(x, y) || GetMapBorderIdAt(x, y) == CONNECTION_INVALID || IsMetatileDirectionallyImpassable(objectEvent, x, y, direction) || (objectEvent->trackedByCamera && !CanCameraMoveInDirection(direction)))
        flags |= 1 << (COLLISION_IMPASSABLE - 1);
    if (IsZCoordMismatchAt(objectEvent->currentElevation, x, y))
        flags |= 1 << (COLLISION_ELEVATION_MISMATCH - 1);
    if (DoesObjectCollideWithObjectAt(objectEvent, x, y))
        flags |= 1 << (COLLISION_OBJECT_EVENT - 1);
    return flags;
}

bool8 IsCoordOutsideObjectEventMovementRange(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    s16 left;
    s16 right;
    s16 top;
    s16 bottom;

    if (objectEvent->range.rangeX != 0)
    {
        left = objectEvent->initialCoords.x - objectEvent->range.rangeX;
        right = objectEvent->initialCoords.x + objectEvent->range.rangeX;

        if (left > x || right < x)
            return TRUE;
    }
    if (objectEvent->range.rangeY != 0)
    {
        top = objectEvent->initialCoords.y - objectEvent->range.rangeY;
        bottom = objectEvent->initialCoords.y + objectEvent->range.rangeY;

        if (top > y || bottom < y)
            return TRUE;
    }
    return FALSE;
}


// Keep the JP asm: agbcc either combines the two packed table bases or
// emits unaligned member loads, instead of the original two aligned literals.
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
        "_08092780: .4byte sEventObjectMovementDirectionData + 0x9\n\t"
        "_08092784: .4byte sEventObjectMovementDirectionData + 0x19\n\t"
        "_08092788:\n\t"
        "	movs r0, #0\n\t"
        "_0809278A:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

bool8 DoesObjectCollideWithObjectAt(struct ObjectEvent *objectEvent, s16 x, s16 y)
{
    u8 i;
    struct ObjectEvent *curObject;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        curObject = &gObjectEvents[i];
        if (curObject->active && curObject != objectEvent)
        {
            if ((curObject->currentCoords.x == x && curObject->currentCoords.y == y) || (curObject->previousCoords.x == x && curObject->previousCoords.y == y))
            {
                if (AreElevationsCompatible(objectEvent->currentElevation, curObject->currentElevation))
                    return TRUE;
            }
        }
    }
    return FALSE;
}

bool8 IsBerryTreeSparkling(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId)
        && gSprites[gObjectEvents[objectEventId].spriteId].data[7] & BERRY_FLAG_SPARKLING)
        return TRUE;

    return FALSE;
}

void sub_08092860(u8 localId, u8 mapNum, u8 mapGroup)
{
    u8 objectEventId;

    if (!TryGetObjectEventIdByLocalIdAndMap(localId, mapNum, mapGroup, &objectEventId))
        gSprites[gObjectEvents[objectEventId].spriteId].data[7] |= BERRY_FLAG_JUST_PICKED;
}

void MoveCoords(u8 direction, s16 *x, s16 *y)
{
    *x += sDirectionToVectors[direction].x;
    *y += sDirectionToVectors[direction].y;
}

void sub_080928D0(u8 direction, s16 *destX, s16 *destY)
{
    *destX += sDirectionToVectors[direction].x << 4;
    *destY += sDirectionToVectors[direction].y << 4;
}

void MoveCoordsInDirection(u8 direction, s16 *x, s16 *y, s16 deltaX, s16 deltaY)
{
    if (sDirectionToVectors[direction].x > 0)
        *x += deltaX;
    if (sDirectionToVectors[direction].x < 0)
        *x -= deltaX;
    if (sDirectionToVectors[direction].y > 0)
        *y += deltaY;
    if (sDirectionToVectors[direction].y < 0)
        *y -= deltaY;
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

void GetEventObjectMovingCameraOffset(s16 *x, s16 *y)
{
    *x = 0;
    *y = 0;

    if (gFieldCamera.x > 0)
        (*x)++;

    if (gFieldCamera.x < 0)
        (*x)--;

    if (gFieldCamera.y > 0)
        (*y)++;

    if (gFieldCamera.y < 0)
        (*y)--;
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

void EventObjectClearHeldMovement(struct ObjectEvent *objectEvent)
{
    objectEvent->movementActionId = MOVEMENT_ACTION_NONE;
    objectEvent->heldMovementActive = FALSE;
    objectEvent->heldMovementFinished = FALSE;
    gSprites[objectEvent->spriteId].sTypeFuncId = 0;
    gSprites[objectEvent->spriteId].sActionFuncId = 0;
}

u8 ObjectEventCheckHeldMovementStatus(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive)
        return objectEvent->heldMovementFinished;

    return 16;
}

u8 ObjectEventClearHeldMovementIfFinished(struct ObjectEvent *objectEvent)
{
    u8 heldMovementStatus = ObjectEventCheckHeldMovementStatus(objectEvent);
    if (heldMovementStatus != 0 && heldMovementStatus != 16)
        ObjectEventClearHeldMovementIfActive(objectEvent);

    return heldMovementStatus;
}


u8 EventObjectGetHeldMovementActionId(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive)
        return objectEvent->movementActionId;
    return MOVEMENT_ACTION_NONE;
}

void UpdateEventObjectCurrentMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite, bool8 (*callback)(struct ObjectEvent *, struct Sprite *))
{
    DoGroundEffects_OnSpawn(objectEvent, sprite);
    TryEnableEventObjectAnim(objectEvent, sprite);

    if (ObjectEventIsHeldMovementActive(objectEvent))
        EventObjectExecHeldMovementAction(objectEvent, sprite);
    else if (!objectEvent->frozen)
        while (callback(objectEvent, sprite));

    DoGroundEffects_OnBeginStep(objectEvent, sprite);
    DoGroundEffects_OnFinishStep(objectEvent, sprite);
    UpdateEventObjectSpriteAnimPause(objectEvent, sprite);
    UpdateObjectEventVisibility(objectEvent, sprite);
    ObjectEventUpdateSubpriority(objectEvent, sprite);
}

u8 GetFaceDirectionMovementAction(u32 direction)
{
    u8 actions[ARRAY_COUNT(sFaceDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sFaceDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 sub_08092CCC(u8 direction)
{
    u8 actions[ARRAY_COUNT(sWalkSlowMovementActions)];

    memcpy(actions, sWalkSlowMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092CF8(u8 direction)
{
    u8 actions[ARRAY_COUNT(sWalkNormalMovementActions)];

    memcpy(actions, sWalkNormalMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092D24(u8 direction)
{
    u8 actions[ARRAY_COUNT(sWalkFastMovementActions)];

    memcpy(actions, sWalkFastMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092D50(u8 direction)
{
    u8 actions[ARRAY_COUNT(sRideWaterCurrentMovementActions)];

    memcpy(actions, sRideWaterCurrentMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092D7C(u8 direction)
{
    u8 actions[ARRAY_COUNT(sWalkFasterMovementActions)];

    memcpy(actions, sWalkFasterMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092DA8(u8 direction)
{
    u8 actions[ARRAY_COUNT(sSlideMovementActions)];

    memcpy(actions, sSlideMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092DD4(u8 direction)
{
    u8 actions[ARRAY_COUNT(sPlayerRunMovementActions)];

    memcpy(actions, sPlayerRunMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092E00(u8 direction)
{
    u8 actions[ARRAY_COUNT(sJump2MovementActions)];

    memcpy(actions, sJump2MovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092E2C(u8 direction)
{
    u8 actions[ARRAY_COUNT(sJumpInPlaceMovementActions)];

    memcpy(actions, sJumpInPlaceMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092E58(u8 direction)
{
    u8 actions[ARRAY_COUNT(sJumpInPlaceTurnAroundMovementActions)];

    memcpy(actions, sJumpInPlaceTurnAroundMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092E84(u8 direction)
{
    u8 actions[ARRAY_COUNT(sJumpMovementActions)];

    memcpy(actions, sJumpMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092EB0(u8 direction)
{
    u8 actions[ARRAY_COUNT(sJumpSpecialMovementActions)];

    memcpy(actions, sJumpSpecialMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092EDC(u8 direction)
{
    u8 actions[ARRAY_COUNT(sWalkInPlaceSlowMovementActions)];

    memcpy(actions, sWalkInPlaceSlowMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092F08(u8 direction)
{
    u8 actions[ARRAY_COUNT(sWalkInPlaceNormalMovementActions)];

    memcpy(actions, sWalkInPlaceNormalMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092F34(u8 direction)
{
    u8 actions[ARRAY_COUNT(sWalkInPlaceFastMovementActions)];

    memcpy(actions, sWalkInPlaceFastMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

u8 sub_08092F60(u8 direction)
{
    u8 actions[ARRAY_COUNT(sWalkInPlaceFasterMovementActions)];

    memcpy(actions, sWalkInPlaceFasterMovementActions, sizeof(actions));
    if (direction > DIR_EAST)
        direction = DIR_NONE;

    return actions[direction];
}

bool8 ObjectEventFaceOppositeDirection(struct ObjectEvent *objectEvent, u8 direction)
{
    return ObjectEventSetHeldMovement(objectEvent, GetFaceDirectionMovementAction(GetOppositeDirection(direction)));
}


u8 sub_08092FB8(u32 direction)
{
    u8 actions[ARRAY_COUNT(sAcroWheelieFaceDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sAcroWheelieFaceDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 sub_08092FE4(u32 direction)
{
    u8 actions[ARRAY_COUNT(sAcroPopWheelieFaceDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sAcroPopWheelieFaceDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 EventObjectExecSingleMovementAction(u32 direction)
{
    u8 actions[ARRAY_COUNT(sAcroEndWheelieFaceDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sAcroEndWheelieFaceDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 sub_0809303C(u32 direction)
{
    u8 actions[ARRAY_COUNT(sAcroWheelieHopFaceDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sAcroWheelieHopFaceDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 GetAcroEndWheelieFaceDirectionMovementAction(u32 direction)
{
    u8 actions[ARRAY_COUNT(sAcroWheelieHopDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sAcroWheelieHopDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 sub_08093094(u32 direction)
{
    u8 actions[ARRAY_COUNT(sAcroWheelieJumpDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sAcroWheelieJumpDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 sub_080930C0(u32 direction)
{
    u8 actions[ARRAY_COUNT(sAcroWheelieInPlaceDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sAcroWheelieInPlaceDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 sub_080930EC(u32 direction)
{
    u8 actions[ARRAY_COUNT(sAcroPopWheelieMoveDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sAcroPopWheelieMoveDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 sub_08093118(u32 direction)
{
    u8 actions[ARRAY_COUNT(sAcroWheelieMoveDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sAcroWheelieMoveDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 sub_08093144(u32 direction)
{
    u8 actions[ARRAY_COUNT(sAcroEndWheelieMoveDirectionMovementActions)];
    u8 dir = direction;

    memcpy(actions, sAcroEndWheelieMoveDirectionMovementActions, sizeof(actions));
    if (dir > DIR_EAST)
        dir = DIR_NONE;

    return actions[dir];
}

u8 GetOppositeDirection(u8 direction)
{
    u8 directions[8];
    memcpy(directions, sOppositeDirections, sizeof directions);
    if (direction <= DIR_NONE || direction > 8)
        return direction;

    return directions[direction - 1];
}

u8 zffu_offset_calc(u8 a, u8 b)
{
    return sDirectionCompositionOffsets[a - 1][b - 1];
}

u32 state_to_direction(u8 a, u8 b, u8 c)
{
    if (b == DIR_NONE || c == DIR_NONE
      || b > DIR_EAST || c > DIR_EAST)
        return DIR_NONE;

    c = zffu_offset_calc(b, c);
    return sDirectionCompositionResults[a - 1][c - 1];
}

void EventObjectExecHeldMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (gMovementActionFuncs[objectEvent->movementActionId][sprite->sActionFuncId](objectEvent, sprite))
        objectEvent->heldMovementFinished = TRUE;
}

bool8 ObjectEventExecSingleMovementAction(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (gMovementActionFuncs[objectEvent->movementActionId][sprite->sActionFuncId](objectEvent, sprite))
    {
        objectEvent->movementActionId = MOVEMENT_ACTION_NONE;
        sprite->sActionFuncId = 0;
        return TRUE;
    }
    return FALSE;
}


void ObjectEventSetSingleMovement(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 animId)
{
    objectEvent->movementActionId = animId;
    sprite->sActionFuncId = 0;
}


void FaceDirection(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    SetEventObjectDirection(objectEvent, direction);
    ShiftStillEventObjectCoords(objectEvent);
    obj_npc_animation_step(objectEvent, sprite, GetJumpInPlaceTurnAroundMovementAction(objectEvent->facingDirection));
    sprite->animPaused = TRUE;
    sprite->sActionFuncId = 1;
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


void npc_apply_direction(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    s16 x;
    s16 y;

    x = objectEvent->currentCoords.x;
    y = objectEvent->currentCoords.y;
    SetEventObjectDirection(objectEvent, direction);
    MoveCoords(direction, &x, &y);
    ShiftEventObjectCoords(objectEvent, x, y);
    oamt_npc_ministep_reset(sprite, direction, speed);
    sprite->animPaused = FALSE;

    if (gUnknown_2037258 != NULL && FindLockedEventObjectIndex(objectEvent) != OBJECT_EVENTS_COUNT)
        sprite->animPaused = TRUE;

    objectEvent->triggerGroundEffectsOnMove = TRUE;
    sprite->sActionFuncId = 1;
}

void InitMovementNormal(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    u8 (*functions[ARRAY_COUNT(sDirectionAnimFuncsBySpeed)])(u8);

    memcpy(functions, sDirectionAnimFuncsBySpeed, sizeof sDirectionAnimFuncsBySpeed);
    npc_apply_direction(objectEvent, sprite, direction, speed);
    npc_apply_anim_looping(objectEvent, sprite, functions[speed](objectEvent->facingDirection));
}

void StartRunningAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    npc_apply_direction(objectEvent, sprite, direction, MOVE_SPEED_FAST_1);
    npc_apply_anim_looping(objectEvent, sprite, GetWalkSlowMovementAction(objectEvent->facingDirection));
}

bool8 UpdateMovementNormal(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (obj_npc_ministep(sprite))
    {
        ShiftStillEventObjectCoords(objectEvent);
        objectEvent->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

void sub_08093460(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    s16 x;
    s16 y;

    x = objectEvent->currentCoords.x;
    y = objectEvent->currentCoords.y;
    SetEventObjectDirection(objectEvent, direction);
    MoveCoords(direction, &x, &y);
    ShiftEventObjectCoords(objectEvent, x, y);
    sub_0809704C(sprite, direction);
    sprite->animPaused = FALSE;
    objectEvent->triggerGroundEffectsOnMove = TRUE;
    sprite->sActionFuncId = 1;
}

void InitWalkSlow(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    sub_08093460(objectEvent, sprite, direction);
    npc_apply_anim_looping(objectEvent, sprite, GetJumpInPlaceTurnAroundMovementAction(objectEvent->facingDirection));
}

bool8 UpdateWalkSlow(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlowAnim(sprite))
    {
        ShiftStillEventObjectCoords(objectEvent);
        objectEvent->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_WalkSlowDiagonalUpLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitWalkSlow(objectEvent, sprite, DIR_NORTHWEST);
    return sub_08093554(objectEvent, sprite);
}

bool8 sub_08093554(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (UpdateWalkSlow(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
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

void sub_08093934(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 distance, u8 type)
{
    s16 displacements[ARRAY_COUNT(sJumpInitDisplacements)];
    s16 x;
    s16 y;

    memcpy(displacements, sJumpInitDisplacements, sizeof sJumpInitDisplacements);
    x = 0;
    y = 0;
    SetEventObjectDirection(objectEvent, direction);
    MoveCoordsInDirection(direction, &x, &y, displacements[distance], displacements[distance]);
    ShiftEventObjectCoords(objectEvent, objectEvent->currentCoords.x + x, objectEvent->currentCoords.y + y);
    sub_080971AC(sprite, direction, distance, type);
    sprite->sActionFuncId = 1;
    sprite->animPaused = FALSE;
    objectEvent->triggerGroundEffectsOnMove = TRUE;
    objectEvent->disableCoveringGroundEffects = TRUE;
}

void maybe_shadow_1(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 distance, u8 type)
{
    sub_08093934(objectEvent, sprite, direction, distance, type);
    npc_apply_anim_looping(objectEvent, sprite, GetJumpInPlaceTurnAroundMovementAction(objectEvent->facingDirection));
    DoShadowFieldEffect(objectEvent);
}

u8 sub_08093A34(struct ObjectEvent *objectEvent, struct Sprite *sprite, u32 a)
{
    s16 displacements[ARRAY_COUNT(sJumpDisplacements)];
    s16 x;
    s16 y;
    u8 result;

    memcpy(displacements, sJumpDisplacements, sizeof sJumpDisplacements);
    result = ((u8 (*)(struct Sprite *))a)(sprite);
    if (result == JUMP_HALFWAY && displacements[sprite->data[4]] != 0)
    {
        x = 0;
        y = 0;
        MoveCoordsInDirection(objectEvent->movementDirection, &x, &y, displacements[sprite->data[4]], displacements[sprite->data[4]]);
        ShiftEventObjectCoords(objectEvent, objectEvent->currentCoords.x + x, objectEvent->currentCoords.y + y);
        objectEvent->triggerGroundEffectsOnMove = TRUE;
        objectEvent->disableCoveringGroundEffects = TRUE;
    }
    else if (result == JUMP_FINISHED)
    {
        ShiftStillEventObjectCoords(objectEvent);
        objectEvent->triggerGroundEffectsOnStop = TRUE;
        objectEvent->landingJump = TRUE;
        sprite->animPaused = TRUE;
    }
    return result;
}

u8 sub_080971CC(struct Sprite *sprite);
u8 sub_08097254(struct Sprite *sprite);

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

void sub_08093EC4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 animNum, u16 duration)
{
    SetEventObjectDirection(objectEvent, direction);
    npc_apply_anim_looping(objectEvent, sprite, animNum);
    sprite->animPaused = FALSE;
    sprite->sActionFuncId = 1;
    sprite->data[3] = duration;
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

void InitJumpSpecial(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction)
{
    sub_08093934(objectEvent, sprite, direction, JUMP_DISTANCE_NORMAL, JUMP_TYPE_HIGH);
    StartSpriteAnim(sprite, GetRideWaterCurrentMovementAction(direction));
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

bool8 MovementAction_JumpInPlaceDownUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpInPlaceAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceUpDown_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_NORTH, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_NORMAL);
    return MovementAction_JumpInPlaceUpDown_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceUpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpInPlaceAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}


bool8 MovementAction_JumpInPlaceLeftRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_WEST, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_NORMAL);
    return MovementAction_JumpInPlaceLeftRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceLeftRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpInPlaceAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_JumpInPlaceRightLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    maybe_shadow_1(objectEvent, sprite, DIR_EAST, JUMP_DISTANCE_IN_PLACE, JUMP_TYPE_NORMAL);
    return MovementAction_JumpInPlaceRightLeft_Step1(objectEvent, sprite);
}

bool8 MovementAction_JumpInPlaceRightLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpInPlaceAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = 0;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
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

bool8 sub_08095388(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    StartSpriteAnimInDirection(objectEvent, sprite, DIR_WEST, GetWalkFastestMovementAction(DIR_WEST));
    return FALSE;
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

void InitFigure8Anim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitSpriteForFigure8Anim(sprite);
    sprite->animPaused = FALSE;
}
bool8 sub_0809547C(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (AnimateSpriteInFigure8(sprite))
    {
        ShiftStillEventObjectCoords(objectEvent);
        objectEvent->triggerGroundEffectsOnStop = TRUE;
        sprite->animPaused = TRUE;
        return TRUE;
    }
    return FALSE;
}





bool8 MovementAction_Figure8_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitFigure8Anim(objectEvent, sprite);
    sprite->sActionFuncId = 1;
    return sub_080954D4(objectEvent, sprite);
}

bool8 sub_080954D4(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sub_0809547C(objectEvent, sprite))
    {
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

void sub_080954F4(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 distance, u8 type)
{
    sub_08093934(objectEvent, sprite, direction, distance, type);
    StartSpriteAnimIfDifferent(sprite, GetSlideMovementAction(direction));
    DoShadowFieldEffect(objectEvent);
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

bool8 MovementAction_AcroWheelieJumpDown_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpUp_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_NORTH, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_AcroWheelieJumpUp_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieJumpUp_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpLeft_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_WEST, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_AcroWheelieJumpLeft_Step1(objectEvent, sprite);
}


bool8 MovementAction_AcroWheelieJumpLeft_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
}

bool8 MovementAction_AcroWheelieJumpRight_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sub_080954F4(objectEvent, sprite, DIR_EAST, JUMP_DISTANCE_FAR, JUMP_TYPE_HIGH);
    return MovementAction_AcroWheelieJumpRight_Step1(objectEvent, sprite);
}

bool8 MovementAction_AcroWheelieJumpRight_Step1(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (DoJumpAnim(objectEvent, sprite))
    {
        objectEvent->hasShadow = FALSE;
        sprite->sActionFuncId = 2;
        return TRUE;
    }
    return FALSE;
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

void InitAcroPopWheelieMove(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(objectEvent, sprite, direction, speed);
    StartSpriteAnim(sprite, GetSlideMovementAction(objectEvent->facingDirection));
    SeekSpriteAnim(sprite, 0);
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


bool8 sub_08095B30(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    InitAcroPopWheelieMove(objectEvent, sprite, DIR_EAST,  1);
    return MovementAction_AcroPopWheelieMoveRight_Step1(objectEvent, sprite);
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

void InitAcroWheelieMove(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(objectEvent, sprite, direction, speed);
    npc_apply_anim_looping(objectEvent, sprite, GetWalkInPlaceFastestMovementAction(objectEvent->facingDirection));
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

void InitAcroEndWheelie(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 direction, u8 speed)
{
    npc_apply_direction(objectEvent, sprite, direction, speed);
    StartSpriteAnim(sprite, GetWalkFastestMovementAction(objectEvent->facingDirection));
    SeekSpriteAnim(sprite, 0);
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

bool8 MovementAction_DestroyExtraTaskIfAtTop_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (sprite->y2 == 0)
    {
        DestroyExtraMovementTask(objectEvent->warpArrowSpriteId);
        sprite->sActionFuncId = 1;
        return TRUE;
    }
    return FALSE;
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


void UpdateEventObjectSpriteAnimPause(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (objectEvent->disableAnim)
        sprite->animPaused = TRUE;
}


void TryEnableEventObjectAnim(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (objectEvent->enableAnim)
    {
        sprite->animPaused = FALSE;
        objectEvent->disableAnim = FALSE;
        objectEvent->enableAnim = FALSE;
    }
}

void UpdateObjectEventVisibility(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    UpdateObjectEventOffscreen(objectEvent, sprite);
    UpdateEventObjSpriteVisibility(objectEvent, sprite);
}

void UpdateObjectEventOffscreen(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    s16 x, y;
    s16 x2, y2;
    const struct ObjectEventGraphicsInfo *graphicsInfo;

    objectEvent->offScreen = FALSE;

    graphicsInfo = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
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
    x2 = (u16)x + (u16)graphicsInfo->width;
    y2 = (u16)y + (u16)graphicsInfo->height;

    if (x >= DISPLAY_WIDTH + 16 || x2 < -16)
        objectEvent->offScreen = TRUE;

    if (y >= DISPLAY_HEIGHT + 16 || y2 < -16)
        objectEvent->offScreen = TRUE;
}

void UpdateEventObjSpriteVisibility(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    sprite->invisible = FALSE;
    if (objectEvent->invisible || objectEvent->offScreen)
        sprite->invisible = TRUE;
}

void GetAllGroundEffectFlags_OnSpawn(struct ObjectEvent *objEvent, u32 *flags)
{
    EventObjectUpdateMetatileBehaviors(objEvent);
    GetGroundEffectFlags_Reflection(objEvent, flags);
    GetGroundEffectFlags_TallGrassOnSpawn(objEvent, flags);
    sub_0809615C(objEvent, flags);
    GetGroundEffectFlags_SandHeap(objEvent, flags);
    GetGroundEffectFlags_ShallowFlowingWater(objEvent, flags);
    GetGroundEffectFlags_ShortGrass(objEvent, flags);
    GetGroundEffectFlags_HotSprings(objEvent, flags);
}

void GetAllGroundEffectFlags_OnBeginStep(struct ObjectEvent *objEvent, u32 *flags)
{
    EventObjectUpdateMetatileBehaviors(objEvent);
    GetGroundEffectFlags_Reflection(objEvent, flags);
    GetGroundEffectFlags_LongGrassOnSpawn(objEvent, flags);
    GetGroundEffectFlags_LongGrassOnBeginStep(objEvent, flags);
    GetGroundEffectFlags_Tracks(objEvent, flags);
    GetGroundEffectFlags_SandHeap(objEvent, flags);
    GetGroundEffectFlags_ShallowFlowingWater(objEvent, flags);
    GetGroundEffectFlags_Puddle(objEvent, flags);
    GetGroundEffectFlags_ShortGrass(objEvent, flags);
    GetGroundEffectFlags_HotSprings(objEvent, flags);
}

void GetAllGroundEffectFlags_OnFinishStep(struct ObjectEvent *objEvent, u32 *flags)
{
    EventObjectUpdateMetatileBehaviors(objEvent);
    GetGroundEffectFlags_ShallowFlowingWater(objEvent, flags);
    GetGroundEffectFlags_SandHeap(objEvent, flags);
    GetGroundEffectFlags_Puddle(objEvent, flags);
    GetGroundEffectFlags_Ripple(objEvent, flags);
    GetGroundEffectFlags_ShortGrass(objEvent, flags);
    GetGroundEffectFlags_HotSprings(objEvent, flags);
    GetGroundEffectFlags_Seaweed(objEvent, flags);
    GetGroundEffectFlags_JumpLanding(objEvent, flags);
}

void EventObjectUpdateMetatileBehaviors(struct ObjectEvent *objectEvent)
{
    objectEvent->previousMetatileBehavior = MapGridGetMetatileBehaviorAt(objectEvent->previousCoords.x, objectEvent->previousCoords.y);
    objectEvent->currentMetatileBehavior = MapGridGetMetatileBehaviorAt(objectEvent->currentCoords.x, objectEvent->currentCoords.y);
}

void GetGroundEffectFlags_Reflection(struct ObjectEvent *objEvent, u32 *flags)
{
    u32 reflectionFlags[ARRAY_COUNT(sReflectionFlags)];
    u32 waterFlag = sReflectionFlags[1];
    u32 iceFlag = sReflectionFlags[0];
    u8 reflType;

    reflectionFlags[0] = iceFlag;
    reflectionFlags[1] = waterFlag;
    reflType = EventObjectCheckForReflectiveSurface(objEvent);

    if (reflType)
    {
        if (objEvent->hasReflection == 0)
        {
            objEvent->hasReflection++;
            *flags |= reflectionFlags[reflType - 1];
        }
    }
    else
    {
        objEvent->hasReflection = FALSE;
    }
}

void GetGroundEffectFlags_TallGrassOnSpawn(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsTallGrass(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_TALL_GRASS_ON_SPAWN;
}

void GetGroundEffectFlags_LongGrassOnSpawn(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsTallGrass(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE;
}

void sub_0809615C(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsLongGrass(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_LONG_GRASS_ON_SPAWN;
}

void GetGroundEffectFlags_LongGrassOnBeginStep(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsLongGrass(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_LONG_GRASS_ON_MOVE;
}

void GetGroundEffectFlags_Tracks(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsDeepSand(objEvent->previousMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_DEEP_SAND;
    else if (MetatileBehavior_IsSandOrDeepSand(objEvent->previousMetatileBehavior)
             || MetatileBehavior_IsFootprints(objEvent->previousMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_SAND;
}

void GetGroundEffectFlags_SandHeap(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsDeepSand(objEvent->currentMetatileBehavior)
        && MetatileBehavior_IsDeepSand(objEvent->previousMetatileBehavior))
    {
        if (!objEvent->inSandPile)
        {
            objEvent->inSandPile++;
            *flags |= GROUND_EFFECT_FLAG_SAND_PILE;
        }
    }
    else
    {
        objEvent->inSandPile = FALSE;
    }
}

void GetGroundEffectFlags_ShallowFlowingWater(struct ObjectEvent *objEvent, u32 *flags)
{
    if ((MetatileBehavior_IsShallowFlowingWater(objEvent->currentMetatileBehavior)
         && MetatileBehavior_IsShallowFlowingWater(objEvent->previousMetatileBehavior))
        || (MetatileBehavior_IsPacifidlogLog(objEvent->currentMetatileBehavior)
            && MetatileBehavior_IsPacifidlogLog(objEvent->previousMetatileBehavior)))
    {
        if (!objEvent->inShallowFlowingWater)
        {
            objEvent->inShallowFlowingWater++;
            *flags |= GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER;
        }
    }
    else
    {
        objEvent->inShallowFlowingWater = FALSE;
    }
}

void GetGroundEffectFlags_Puddle(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsPuddle(objEvent->currentMetatileBehavior)
        && MetatileBehavior_IsPuddle(objEvent->previousMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_PUDDLE;
}

void GetGroundEffectFlags_Ripple(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_HasRipples(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_RIPPLES;
}

void GetGroundEffectFlags_ShortGrass(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsShortGrass(objEvent->currentMetatileBehavior)
        && MetatileBehavior_IsShortGrass(objEvent->previousMetatileBehavior))
    {
        if (!objEvent->inShortGrass)
        {
            objEvent->inShortGrass++;
            *flags |= GROUND_EFFECT_FLAG_SHORT_GRASS;
        }
    }
    else
    {
        objEvent->inShortGrass = FALSE;
    }
}

void GetGroundEffectFlags_HotSprings(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsHotSprings(objEvent->currentMetatileBehavior)
        && MetatileBehavior_IsHotSprings(objEvent->previousMetatileBehavior))
    {
        if (!objEvent->inHotSprings)
        {
            objEvent->inHotSprings++;
            *flags |= GROUND_EFFECT_FLAG_HOT_SPRINGS;
        }
    }
    else
    {
        objEvent->inHotSprings = FALSE;
    }
}


void GetGroundEffectFlags_Seaweed(struct ObjectEvent *objEvent, u32 *flags)
{
    if (MetatileBehavior_IsSeaweed(objEvent->currentMetatileBehavior))
        *flags |= GROUND_EFFECT_FLAG_SEAWEED;
}

void GetGroundEffectFlags_JumpLanding(struct ObjectEvent *objEvent, u32 *flags)
{
    if (objEvent->landingJump && !objEvent->disableJumpLandingGroundEffect)
    {
        u8 i;

        for (i = 0; i < ARRAY_COUNT(sJumpLandingMetatileFuncs); i++)
        {
            if (sJumpLandingMetatileFuncs[i](objEvent->currentMetatileBehavior))
            {
                *flags |= sJumpLandingFlags[i];
                return;
            }
        }
    }
}

#define RETURN_REFLECTION_TYPE_AT(x, y)              \
    b = MapGridGetMetatileBehaviorAt(x, y);          \
    result = GetReflectionTypeByMetatileBehavior(b); \
    if (result != REFL_TYPE_NONE)                    \
        return result;

bool8 EventObjectCheckForReflectiveSurface(struct ObjectEvent *objectEvent)
{
    const struct ObjectEventGraphicsInfo *info = GetObjectEventGraphicsInfo(objectEvent->graphicsId);

    // Ceil div by tile width. Size / 16 + 1;
    s16 width = (info->width + 8) >> 4;
    s16 height = (info->height + 8) >> 4;
    s16 i, j;
    u8 result, b; // used by RETURN_REFLECTION_TYPE_AT
    s16 one = 1; // + 1

    for (i = 0; i < height; i++)
    {
        RETURN_REFLECTION_TYPE_AT(objectEvent->currentCoords.x, objectEvent->currentCoords.y + one + i)
        RETURN_REFLECTION_TYPE_AT(objectEvent->previousCoords.x, objectEvent->previousCoords.y + one + i)
        for (j = 1; j < width; j++)
        {
            RETURN_REFLECTION_TYPE_AT(objectEvent->currentCoords.x + j, objectEvent->currentCoords.y + one + i)
            RETURN_REFLECTION_TYPE_AT(objectEvent->currentCoords.x - j, objectEvent->currentCoords.y + one + i)
            RETURN_REFLECTION_TYPE_AT(objectEvent->previousCoords.x + j, objectEvent->previousCoords.y + one + i)
            RETURN_REFLECTION_TYPE_AT(objectEvent->previousCoords.x - j, objectEvent->previousCoords.y + one + i)
        }
    }

    return REFL_TYPE_NONE;
}

#undef RETURN_REFLECTION_TYPE_AT

u8 GetReflectionTypeByMetatileBehavior(u32 metatileBehavior)
{
    if (MetatileBehavior_IsIce_2(metatileBehavior))
        return REFL_TYPE_ICE;
    else if (MetatileBehavior_IsReflective(metatileBehavior))
        return REFL_TYPE_WATER;
    else
        return REFL_TYPE_NONE;
}

u8 GetLedgeJumpDirection(s16 x, s16 y, u8 direction)
{
    u8 behavior;

    if (direction == DIR_NONE)
        return DIR_NONE;
    else if (direction > DIR_EAST)
        direction -= DIR_EAST;

    direction--;
    behavior = MapGridGetMetatileBehaviorAt(x, y);

    if (sLedgeBehaviorFuncs[direction](behavior) == TRUE)
        return direction + 1;

    return DIR_NONE;
}

void SetEventObjectSpriteOamTableForLongGrass(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (objectEvent->disableCoveringGroundEffects)
        return;

    if (!MetatileBehavior_IsLongGrass(objectEvent->currentMetatileBehavior))
        return;

    if (!MetatileBehavior_IsLongGrass(objectEvent->previousMetatileBehavior))
        return;

    sprite->subspriteTableNum = 4;

    if (ElevationToPriority(objectEvent->previousElevation) == 1)
        sprite->subspriteTableNum = 5;
}

bool8 IsZCoordMismatchAt(u8 elevation, s16 x, s16 y)
{
    u8 mapElevation;

    if (elevation == ELEVATION_TRANSITION)
        return FALSE;

    mapElevation = MapGridGetElevationAt(x, y);

    if (mapElevation == ELEVATION_TRANSITION || mapElevation == ELEVATION_MULTI_LEVEL)
        return FALSE;

    if (mapElevation != elevation)
        return TRUE;

    return FALSE;
}

void UpdateEventObjectZCoordAndPriority(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    if (objectEvent->fixedPriority)
        return;

    EventObjectUpdateZCoord(objectEvent);

    sprite->subspriteTableNum = sElevationToSubspriteTableNum[objectEvent->previousElevation];
    sprite->oam.priority = sElevationToPriority[objectEvent->previousElevation];
}

void InitObjectPriorityByZCoord(struct Sprite *sprite, u8 elevation)
{
    sprite->subspriteTableNum = sElevationToSubspriteTableNum[elevation];
    sprite->oam.priority = sElevationToPriority[elevation];
}

u8 ElevationToPriority(u8 elevation)
{
    return sElevationToPriority[elevation];
}

void EventObjectUpdateZCoord(struct ObjectEvent *objectEvent)
{
    u8 curElevation = MapGridGetElevationAt(objectEvent->currentCoords.x, objectEvent->currentCoords.y);
    u8 prevElevation = MapGridGetElevationAt(objectEvent->previousCoords.x, objectEvent->previousCoords.y);

    if (curElevation == ELEVATION_MULTI_LEVEL || prevElevation == ELEVATION_MULTI_LEVEL)
        return;

    objectEvent->currentElevation = curElevation;

    if (curElevation != ELEVATION_TRANSITION && curElevation != ELEVATION_MULTI_LEVEL)
        objectEvent->previousElevation = curElevation;
}

void SetObjectSubpriorityByElevation(u8 elevation, struct Sprite *sprite, u8 subpriority)
{
    u16 y = (sprite->y - sprite->centerToCornerVecY + gSpriteCoordOffsetY + 8) & 0xFF;
    y = (16 - (y >> 4)) << 1;

    sprite->subpriority = sElevationToSubpriority[elevation] + y + subpriority;
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

void GroundEffect_SpawnOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2; // priority
    gFieldEffectArguments[4] = objEvent->localId << 8 | objEvent->mapNum;
    gFieldEffectArguments[5] = objEvent->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = TRUE; // skip to end of anim
    FieldEffectStart(FLDEFF_TALL_GRASS);
}

void GroundEffect_StepOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2; // priority
    gFieldEffectArguments[4] = objEvent->localId << 8 | objEvent->mapNum;
    gFieldEffectArguments[5] = objEvent->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = FALSE; // don't skip to end of anim
    FieldEffectStart(FLDEFF_TALL_GRASS);
}

void GroundEffect_SpawnOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = objEvent->localId << 8 | objEvent->mapNum;
    gFieldEffectArguments[5] = objEvent->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 1;
    FieldEffectStart(FLDEFF_LONG_GRASS);
}

void GroundEffect_StepOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = (objEvent->localId << 8) | objEvent->mapNum;
    gFieldEffectArguments[5] = objEvent->mapGroup;
    gFieldEffectArguments[6] = (u8)gSaveBlock1Ptr->location.mapNum << 8 | (u8)gSaveBlock1Ptr->location.mapGroup;
    gFieldEffectArguments[7] = 0;
    FieldEffectStart(FLDEFF_LONG_GRASS);
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

void GroundEffect_SandTracks(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    const struct ObjectEventGraphicsInfo *info = GetObjectEventGraphicsInfo(objEvent->graphicsId);
    sGroundEffectTracksFuncs[info->tracks](objEvent, sprite, FALSE);
}

void sub_08096984(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    const struct ObjectEventGraphicsInfo *info = GetObjectEventGraphicsInfo(objectEvent->graphicsId);
    sGroundEffectTracksFuncs[info->tracks](objectEvent, sprite, TRUE);
}

void DoTracksGroundEffect_None(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a) {}
void DoTracksGroundEffect_Footprints(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a)
{
    u16 sandFootprints_FieldEffectData[2];

    memcpy(sandFootprints_FieldEffectData, sSandFootprintsFieldEffectIds, sizeof(sandFootprints_FieldEffectData));

    gFieldEffectArguments[0] = objectEvent->previousCoords.x;
    gFieldEffectArguments[1] = objectEvent->previousCoords.y;
    gFieldEffectArguments[2] = 149;
    gFieldEffectArguments[3] = 2;
    gFieldEffectArguments[4] = objectEvent->facingDirection;
    FieldEffectStart(sandFootprints_FieldEffectData[a]);
}

void DoTracksGroundEffect_BikeTireTracks(struct ObjectEvent *objectEvent, struct Sprite *sprite, u8 a)
{
    if (objectEvent->currentCoords.x != objectEvent->previousCoords.x || objectEvent->currentCoords.y != objectEvent->previousCoords.y)
    {
        gFieldEffectArguments[0] = objectEvent->previousCoords.x;
        gFieldEffectArguments[1] = objectEvent->previousCoords.y;
        gFieldEffectArguments[2] = 149;
        gFieldEffectArguments[3] = 2;
        gFieldEffectArguments[4] =
            sBikeTireTracksTransitions[objectEvent->previousMovementDirection][objectEvent->facingDirection - 5];
        FieldEffectStart(FLDEFF_BIKE_TIRE_TRACKS);
    }
}

void sub_08096A54(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    DoRippleFieldEffect(objEvent, sprite);
}

void GroundEffect_StepOnPuddle(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_SPLASH, objEvent);
}

void GroundEffect_SandHeap(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_SAND_PILE, objEvent);
}

void GroundEffect_JumpOnTallGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    u8 spriteId;

    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2;
    FieldEffectStart(FLDEFF_JUMP_TALL_GRASS);

    spriteId = FindTallGrassFieldEffectSpriteId(
        objEvent->localId,
        objEvent->mapNum,
        objEvent->mapGroup,
        objEvent->currentCoords.x,
        objEvent->currentCoords.y);

    if (spriteId == MAX_SPRITES)
        GroundEffect_SpawnOnTallGrass(objEvent, sprite);
}

void GroundEffect_JumpOnLongGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = 2;
    FieldEffectStart(FLDEFF_JUMP_LONG_GRASS);
}

void GroundEffect_JumpOnShallowWater(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_JUMP_SMALL_SPLASH);
}

void GroundEffect_JumpOnWater(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_JUMP_BIG_SPLASH);
}

void GroundEffect_JumpLandingDust(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = objEvent->previousElevation;
    gFieldEffectArguments[3] = sprite->oam.priority;
    FieldEffectStart(FLDEFF_DUST);
}

void GroundEffect_ShortGrass(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_SHORT_GRASS, objEvent);
}

void GroundEffect_HotSprings(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    StartFieldEffectForObjectEvent(FLDEFF_HOT_SPRINGS_WATER, objEvent);
}

void GroundEffect_Seaweed(struct ObjectEvent *objEvent, struct Sprite *sprite)
{
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    FieldEffectStart(FLDEFF_BUBBLES);
}

void DoFlaggedGroundEffects(struct ObjectEvent *objEvent, struct Sprite *sprite, u32 flags)
{
    u8 i;

    if (ObjectEventIsFarawayIslandMew(objEvent) == TRUE && !ShouldMewShakeGrass(objEvent))
        return;

    for (i = 0; i < ARRAY_COUNT(sGroundEffectFuncs); i++, flags >>= 1)
        if (flags & 1)
            sGroundEffectFuncs[i](objEvent, sprite);
}

void filters_out_some_ground_effects(struct ObjectEvent *objEvent, u32 *flags)
{
    if (objEvent->disableCoveringGroundEffects)
    {
        objEvent->inShortGrass = 0;
        objEvent->inSandPile = 0;
        objEvent->inShallowFlowingWater = 0;
        objEvent->inHotSprings = 0;
        *flags &= ~(GROUND_EFFECT_FLAG_HOT_SPRINGS
                  | GROUND_EFFECT_FLAG_SHORT_GRASS
                  | GROUND_EFFECT_FLAG_SAND_PILE
                  | GROUND_EFFECT_FLAG_SHALLOW_FLOWING_WATER
                  | GROUND_EFFECT_FLAG_TALL_GRASS_ON_MOVE);
    }
}

void FilterOutStepOnPuddleGroundEffectIfJumping(struct ObjectEvent *objEvent, u32 *flags)
{
    if (objEvent->landingJump)
        *flags &= ~GROUND_EFFECT_FLAG_PUDDLE;
}


void DoGroundEffects_OnSpawn(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u32 flags;

    if (objectEvent->triggerGroundEffectsOnMove)
    {
        flags = 0;
        UpdateEventObjectZCoordAndPriority(objectEvent, sprite);
        GetAllGroundEffectFlags_OnSpawn(objectEvent, &flags);
        SetEventObjectSpriteOamTableForLongGrass(objectEvent, sprite);
        DoFlaggedGroundEffects(objectEvent, sprite, flags);
        objectEvent->triggerGroundEffectsOnMove = FALSE;
        objectEvent->disableCoveringGroundEffects = 0;
    }
}

void DoGroundEffects_OnBeginStep(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u32 flags;

    if (objectEvent->triggerGroundEffectsOnMove)
    {
        flags = 0;
        UpdateEventObjectZCoordAndPriority(objectEvent, sprite);
        GetAllGroundEffectFlags_OnBeginStep(objectEvent, &flags);
        SetEventObjectSpriteOamTableForLongGrass(objectEvent, sprite);
        filters_out_some_ground_effects(objectEvent, &flags);
        DoFlaggedGroundEffects(objectEvent, sprite, flags);
        objectEvent->triggerGroundEffectsOnMove = FALSE;
        objectEvent->disableCoveringGroundEffects = 0;
    }
}

void DoGroundEffects_OnFinishStep(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    u32 flags;

    if (objectEvent->triggerGroundEffectsOnStop)
    {
        flags = 0;
        UpdateEventObjectZCoordAndPriority(objectEvent, sprite);
        GetAllGroundEffectFlags_OnFinishStep(objectEvent, &flags);
        SetEventObjectSpriteOamTableForLongGrass(objectEvent, sprite);
        FilterOutStepOnPuddleGroundEffectIfJumping(objectEvent, &flags);
        DoFlaggedGroundEffects(objectEvent, sprite, flags);
        objectEvent->triggerGroundEffectsOnStop = 0;
        objectEvent->landingJump = 0;
    }
}

bool8 FreezeEventObject(struct ObjectEvent *objectEvent)
{
    if (objectEvent->heldMovementActive || objectEvent->frozen)
    {
        return TRUE;
    }
    else
    {
        objectEvent->frozen = TRUE;
        objectEvent->spriteAnimPausedBackup = gSprites[objectEvent->spriteId].animPaused;
        objectEvent->spriteAffineAnimPausedBackup = gSprites[objectEvent->spriteId].affineAnimPaused;
        gSprites[objectEvent->spriteId].animPaused = TRUE;
        gSprites[objectEvent->spriteId].affineAnimPaused = TRUE;
        return FALSE;
    }
}

void FreezeObjectEvents(void)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        if (gObjectEvents[i].active && i != gPlayerAvatar.objectEventId)
            FreezeEventObject(&gObjectEvents[i]);
}

void FreezeEventObjectsExceptOne(u8 objectEventId)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        if (i != objectEventId && gObjectEvents[i].active && i != gPlayerAvatar.objectEventId)
            FreezeEventObject(&gObjectEvents[i]);
}

void UnfreezeEventObject(struct ObjectEvent *objectEvent)
{
    if (objectEvent->active && objectEvent->frozen)
    {
        objectEvent->frozen = 0;
        gSprites[objectEvent->spriteId].animPaused = objectEvent->spriteAnimPausedBackup;
        gSprites[objectEvent->spriteId].affineAnimPaused = objectEvent->spriteAffineAnimPausedBackup;
    }
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

void Step8(struct Sprite *sprite, u8 direction)
{
    sprite->x += sDirectionToVectors[direction].x << 3;
    sprite->y += sDirectionToVectors[direction].y << 3;
}

void oamt_npc_ministep_reset(struct Sprite *sprite, u8 a, u8 b)
{
    sprite->data[3] = a;
    sprite->data[4] = b;
    sprite->data[5] = 0;
}

bool8 obj_npc_ministep(struct Sprite *sprite)
{
    if (sprite->data[5] >= sStepTimes[sprite->data[4]])
        return FALSE;

    sNpcStepFuncTables[sprite->data[4]][sprite->data[5]](sprite, sprite->sDirection);

    sprite->data[5]++;

    if (sprite->data[5] < sStepTimes[sprite->data[4]])
        return FALSE;

    return TRUE;
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


s16 sub_08097190(s16 i, u8 type)
{
    return sJumpYTable[type][i];
}

void sub_080971AC(struct Sprite *sprite, u8 direction, u8 distance, u8 type)
{
    sprite->sDirection = direction;
    sprite->data[4] = distance;
    sprite->data[5] = type;
    sprite->data[6] = 0;
}

u8 sub_080971CC(struct Sprite *sprite)
{
    s16 distanceToTime[3];
    u8 distanceToShift[3];
    u8 result;

    memcpy(distanceToTime, sJumpDistanceToTime, sizeof(distanceToTime));
    memcpy(distanceToShift, sJumpDistanceToShift, sizeof(distanceToShift));
    result = 0;

    if (sprite->data[4] != JUMP_DISTANCE_IN_PLACE)
        Step1(sprite, sprite->sDirection);

    sprite->y2 = sub_08097190(sprite->data[6] >> distanceToShift[sprite->data[4]], sprite->data[5]);

    sprite->data[6]++;

    if (sprite->data[6] == distanceToTime[sprite->data[4]] >> 1)
        result = JUMP_HALFWAY;

    if (sprite->data[6] >= distanceToTime[sprite->data[4]])
    {
        sprite->y2 = 0;
        result = JUMP_FINISHED;
    }

    return result;
}

u8 sub_08097254(struct Sprite *sprite)
{
    s16 distanceToTime[3];
    u8 distanceToShift[3];
    u8 result;

    memcpy(distanceToTime, sJumpSpecialDistanceToTime, sizeof(distanceToTime));
    memcpy(distanceToShift, sJumpSpecialDistanceToShift, sizeof(distanceToShift));
    result = 0;

    if (sprite->data[4] != JUMP_DISTANCE_IN_PLACE && !(sprite->data[6] & 1))
        Step1(sprite, sprite->sDirection);

    sprite->y2 = sub_08097190(sprite->data[6] >> distanceToShift[sprite->data[4]], sprite->data[5]);

    sprite->data[6]++;

    if (sprite->data[6] == distanceToTime[sprite->data[4]] >> 1)
        result = JUMP_HALFWAY;

    if (sprite->data[6] >= distanceToTime[sprite->data[4]])
    {
        sprite->y2 = 0;
        result = JUMP_FINISHED;
    }

    return result;
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

void sub_08097460(void)
{
    int i;

    for (i = 0; i < MAX_SPRITES; i++)
    {
        struct Sprite *sprite = &gSprites[i];
        if(sprite->inUse && sprite->callback == SpriteCB_VirtualObject)
            DestroySprite(sprite);
    }
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

bool32 IsVirtualObjectInvisible(u8 virtualObjId)
{
    u8 spriteId = GetVirtualObjectSpriteId(virtualObjId);

    if (spriteId == MAX_SPRITES)
        return FALSE;

    return (gSprites[spriteId].data[2] == TRUE);
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

void sub_080976D8(struct Sprite *sprite)
{
    switch (sprite->data[3])
    {
    case 0:
        break;
    case 1:
        sub_080976A0(sprite);
        break;
    case 2:
        sub_08097664(sprite);
        break;
    default:
        sprite->data[3] = 0;
        AGBAssert(sEventObjectMovementSourceFile, 0x3106, sVirtualObjectAnimAssertExpression, TRUE);
        break;
    }
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

u8 MovementAction_StoreAndLockAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    bool32 ableToStore = FALSE;
    if (gUnknown_2037258 == NULL)
    {
        gUnknown_2037258 = AllocZeroed(sizeof(struct EventObjectLockedAnimState));
        gUnknown_2037258->localIds[0] = objectEvent->localId;
        gUnknown_2037258->count = 1;
        ableToStore = TRUE;
    }
    else
    {
        u8 i;
        u8 firstFreeSlot = OBJECT_EVENTS_COUNT;
        bool32 found = FALSE;
        for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
        {
            if (firstFreeSlot == OBJECT_EVENTS_COUNT && gUnknown_2037258->localIds[i] == LOCALID_NONE)
                firstFreeSlot = i;

            if (gUnknown_2037258->localIds[i] == objectEvent->localId)
            {
                found = TRUE;
                break;
            }
        }

        if (!found && firstFreeSlot != OBJECT_EVENTS_COUNT)
        {
            gUnknown_2037258->localIds[firstFreeSlot] = objectEvent->localId;
            gUnknown_2037258->count++;
            ableToStore = TRUE;
        }
    }

    if (ableToStore == TRUE)
    {
        objectEvent->inanimate = TRUE;
        objectEvent->facingDirectionLocked = TRUE;
    }

    sprite->sActionFuncId = 1;
    return TRUE;
}

u8 MovementAction_FreeAndUnlockAnim_Step0(struct ObjectEvent *objectEvent, struct Sprite *sprite)
{
    bool32 ableToStore;
    u8 index;

    sprite->sActionFuncId = 1;
    if (gUnknown_2037258 != NULL)
    {
        ableToStore = FALSE;
        index = FindLockedEventObjectIndex(objectEvent);
        if (index != OBJECT_EVENTS_COUNT)
        {
            gUnknown_2037258->localIds[index] = LOCALID_NONE;
            gUnknown_2037258->count--;
            ableToStore = TRUE;
        }
        if (gUnknown_2037258->count == 0)
        {
            Free(gUnknown_2037258);
            gUnknown_2037258 = NULL;
        }
        if (ableToStore == TRUE)
        {
            objectEvent->inanimate = GetObjectEventGraphicsInfo(objectEvent->graphicsId)->inanimate;
            objectEvent->facingDirectionLocked = FALSE;
            sprite->animPaused = 0;
        }
    }

    return TRUE;
}

u8 FindLockedEventObjectIndex(struct ObjectEvent *objectEvent)
{
    u8 i;

    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gUnknown_2037258->localIds[i] == objectEvent->localId)
            return i;
    }
    return OBJECT_EVENTS_COUNT;
}

void CreateLevitateMovementTask(struct ObjectEvent *objectEvent)
{
    u8 taskId = CreateTask(ApplyLevitateMovement, 0xFF);
    struct Task *task = &gTasks[taskId];

    StoreWordInTwoHalfwords(&task->data[0], (u32)objectEvent);
    objectEvent->warpArrowSpriteId = taskId;
    task->data[3] = 0xFFFF;
}

void ApplyLevitateMovement(u8 taskId)
{
    struct ObjectEvent *objectEvent;
    struct Sprite *sprite;
    struct Task *task = &gTasks[taskId];

    LoadWordFromTwoHalfwords(&task->data[0], (u32 *)&objectEvent); // load the map object pointer.
    sprite = &gSprites[objectEvent->spriteId];

    if(!(task->data[2] & 3))
        sprite->y2 += task->data[3];

    if(!(task->data[2] & 15))
        task->data[3] = -task->data[3];

    task->data[2]++;
}

void DestroyExtraMovementTask(u8 taskId)
{
    struct ObjectEvent *objectEvent;
    struct Task *task = &gTasks[taskId];

    LoadWordFromTwoHalfwords(&task->data[0], (u32 *)&objectEvent); // unused objectEvent
    DestroyTask(taskId);
}

void sub_080979FC(u8 objectEventId1, u8 objectEventId2)
{
    u8 i;

    for(i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if(i != objectEventId1 && i != objectEventId2 &&
            gObjectEvents[i].active && i != gPlayerAvatar.objectEventId)
                FreezeEventObject(&gObjectEvents[i]);
    }
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
