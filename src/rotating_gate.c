#include "global.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "rotating_gate.h"
#include "sound.h"
#include "sprite.h"
#include "constants/songs.h"

#define ROTATING_GATE_TILE_TAG 0x1300
#define ROTATING_GATE_PUZZLE_MAX 12
#define GATE_ARM_MAX_LENGTH 2

#define GATE_ROT(rotationDirection, arm, longArm)                                             \
    ((rotationDirection & 15) << 4) | ((arm & 7) << 1) | (longArm & 1)
#define GATE_ROT_CW(arm, longArm) GATE_ROT(ROTATE_CLOCKWISE, arm, longArm)
#define GATE_ROT_ACW(arm, longArm) GATE_ROT(ROTATE_ANTICLOCKWISE, arm, longArm)
#define GATE_ROT_NONE 255

static void SpriteCallback_RotatingGate(struct Sprite *sprite);
static u8 RotatingGate_CreateGate(u8 gateId, s16 deltaX, s16 deltaY);
static void RotatingGate_HideGatesOutsideViewport(struct Sprite *sprite);

enum
{
    GATE_SHAPE_L1,
    GATE_SHAPE_L2,
    GATE_SHAPE_L3,
    GATE_SHAPE_L4,
    GATE_SHAPE_T1,
    GATE_SHAPE_T2,
    GATE_SHAPE_T3,
    GATE_SHAPE_T4,
    GATE_SHAPE_UNUSED_T1,
    GATE_SHAPE_UNUSED_T2,
    GATE_SHAPE_UNUSED_T3,
    GATE_SHAPE_UNUSED_T4,
};

enum
{
    GATE_ORIENTATION_0,
    GATE_ORIENTATION_90,
    GATE_ORIENTATION_180,
    GATE_ORIENTATION_270,
    GATE_ORIENTATION_MAX,
};

enum
{
    GATE_ARM_NORTH,
    GATE_ARM_EAST,
    GATE_ARM_SOUTH,
    GATE_ARM_WEST,
};

enum
{
    ROTATE_NONE,
    ROTATE_ANTICLOCKWISE,
    ROTATE_CLOCKWISE,
};

enum
{
    PUZZLE_NONE,
    PUZZLE_FORTREE_CITY_GYM,
    PUZZLE_ROUTE110_TRICK_HOUSE_PUZZLE6,
};

struct RotatingGatePuzzle
{
    s16 x;
    s16 y;
    u8 shape;
    u8 orientation;
};

// JP ROM data (the puzzle configs, graphics table, sprite templates,
// rotation-info/arm tables stay in the ROM data region)
extern const struct RotatingGatePuzzle sRotatingGate_FortreePuzzleConfig[8];
extern const struct RotatingGatePuzzle sRotatingGate_TrickHousePuzzleConfig[11];
extern const struct SpriteSheet sRotatingGatesGraphicsTable[];
extern const struct SpriteTemplate sSpriteTemplate_RotatingGateLarge;
extern const struct SpriteTemplate sSpriteTemplate_RotatingGateRegular;
extern const u8 sRotatingGate_RotationInfoNorth[4 * 4];
extern const u8 sRotatingGate_RotationInfoSouth[4 * 4];
extern const u8 sRotatingGate_RotationInfoWest[4 * 4];
extern const u8 sRotatingGate_RotationInfoEast[4 * 4];
extern const struct Coords8 sRotatingGate_ArmPositionsClockwiseRotation[];
extern const struct Coords8 sRotatingGate_ArmPositionsAntiClockwiseRotation[];
extern const u8 sRotatingGate_ArmLayout[][4 * 2];

extern EWRAM_DATA u8 sRotatingGate_GateSpriteIds[ROTATING_GATE_PUZZLE_MAX];
extern EWRAM_DATA const struct RotatingGatePuzzle *sRotatingGate_PuzzleConfig;
extern EWRAM_DATA u8 sRotatingGate_PuzzleCount;

static s32 GetCurrentMapRotatingGatePuzzleType(void)
{
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_FORTREE_CITY_GYM) &&
        gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_FORTREE_CITY_GYM))
    {
        return PUZZLE_FORTREE_CITY_GYM;
    }

    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_ROUTE110_TRICK_HOUSE_PUZZLE6) &&
        gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_ROUTE110_TRICK_HOUSE_PUZZLE6))
    {
        return PUZZLE_ROUTE110_TRICK_HOUSE_PUZZLE6;
    }

    return PUZZLE_NONE;
}

static void RotatingGate_ResetAllGateOrientations(void)
{
    s32 i;
    u8 *ptr = (u8 *)GetVarPointer(VAR_TEMP_0);

    for (i = 0; i < sRotatingGate_PuzzleCount; i++)
        ptr[i] = sRotatingGate_PuzzleConfig[i].orientation;
}

static s32 RotatingGate_GetGateOrientation(u8 gateId)
{
    return ((u8 *)GetVarPointer(VAR_TEMP_0))[gateId];
}

static void RotatingGate_SetGateOrientation(u8 gateId, u8 orientation)
{
    ((u8 *)GetVarPointer(VAR_TEMP_0))[gateId] = orientation;
}

static void RotatingGate_RotateInDirection(u8 gateId, u32 rotationDirection)
{
    u8 orientation = RotatingGate_GetGateOrientation(gateId);

    if (rotationDirection == ROTATE_ANTICLOCKWISE)
    {
        if (orientation)
            orientation--;
        else
            orientation = GATE_ORIENTATION_270;
    }
    else
    {
        orientation++;
        orientation = orientation % GATE_ORIENTATION_MAX;
    }
    RotatingGate_SetGateOrientation(gateId, orientation);
}

static void RotatingGate_LoadPuzzleConfig(void)
{
    s32 puzzleType = GetCurrentMapRotatingGatePuzzleType();
    u32 i;

    switch (puzzleType)
    {
    case PUZZLE_FORTREE_CITY_GYM:
        sRotatingGate_PuzzleConfig = sRotatingGate_FortreePuzzleConfig;
        sRotatingGate_PuzzleCount = ARRAY_COUNT(sRotatingGate_FortreePuzzleConfig);
        break;
    case PUZZLE_ROUTE110_TRICK_HOUSE_PUZZLE6:
        sRotatingGate_PuzzleConfig = sRotatingGate_TrickHousePuzzleConfig;
        sRotatingGate_PuzzleCount = ARRAY_COUNT(sRotatingGate_TrickHousePuzzleConfig);
        break;
    case PUZZLE_NONE:
    default:
        return;
    }

    for (i = 0; i < ROTATING_GATE_PUZZLE_MAX - 1; i++)
        sRotatingGate_GateSpriteIds[i] = MAX_SPRITES;
}

static void RotatingGate_CreateGatesWithinViewport(s16 deltaX, s16 deltaY)
{
    u8 i;

    s16 x = gSaveBlock1Ptr->pos.x - 2;
    s16 x2 = gSaveBlock1Ptr->pos.x + MAP_OFFSET_W + 2;
    s16 y = gSaveBlock1Ptr->pos.y - 2;
    s16 y2 = gSaveBlock1Ptr->pos.y + MAP_OFFSET_H;

    for (i = 0; i < sRotatingGate_PuzzleCount; i++)
    {
        s16 x3 = sRotatingGate_PuzzleConfig[i].x + MAP_OFFSET;
        s16 y3 = sRotatingGate_PuzzleConfig[i].y + MAP_OFFSET;

        if (y <= y3 && y2 >= y3 && x <= x3 && x2 >= x3 &&
            sRotatingGate_GateSpriteIds[i] == MAX_SPRITES)
        {
            sRotatingGate_GateSpriteIds[i] = RotatingGate_CreateGate(i, deltaX, deltaY);
        }
    }
}

static u8 RotatingGate_CreateGate(u8 gateId, s16 deltaX, s16 deltaY)
{
    struct Sprite *sprite;
    struct SpriteTemplate template;
    u8 spriteId;
    s16 x, y;

    const struct RotatingGatePuzzle *gate = &sRotatingGate_PuzzleConfig[gateId];

    if (gate->shape == GATE_SHAPE_L1 || gate->shape == GATE_SHAPE_T1)
        template = sSpriteTemplate_RotatingGateRegular;
    else
        template = sSpriteTemplate_RotatingGateLarge;

    template.tileTag = gate->shape + ROTATING_GATE_TILE_TAG;

    spriteId = CreateSprite(&template, 0, 0, 0x94);
    if (spriteId == MAX_SPRITES)
        return MAX_SPRITES;

    x = gate->x + MAP_OFFSET;
    y = gate->y + MAP_OFFSET;

    sprite = &gSprites[spriteId];
    sprite->data[0] = gateId;
    sprite->coordOffsetEnabled = 1;

    GetMapCoordsFromSpritePos(x + deltaX, y + deltaY, &sprite->x, &sprite->y);
    RotatingGate_HideGatesOutsideViewport(sprite);
    StartSpriteAffineAnim(sprite, RotatingGate_GetGateOrientation(gateId));

    return spriteId;
}

static void SpriteCallback_RotatingGate(struct Sprite *sprite)
{
    u8 affineAnimation;
    u8 rotationDirection = sprite->data[1];
    u8 orientation = sprite->data[2];

    RotatingGate_HideGatesOutsideViewport(sprite);

    if (rotationDirection == ROTATE_ANTICLOCKWISE)
    {
        affineAnimation = orientation + 4;

        if (GetPlayerSpeed() != PLAYER_SPEED_NORMAL)
            affineAnimation += 8;

        PlaySE(SE_ROTATING_GATE);
        StartSpriteAffineAnim(sprite, affineAnimation);
    }
    else if (rotationDirection == ROTATE_CLOCKWISE)
    {
        affineAnimation = orientation + 8;

        if (GetPlayerSpeed() != PLAYER_SPEED_NORMAL)
            affineAnimation += 8;

        PlaySE(SE_ROTATING_GATE);
        StartSpriteAffineAnim(sprite, affineAnimation);
    }

    sprite->data[1] = ROTATE_NONE;
}

static void RotatingGate_HideGatesOutsideViewport(struct Sprite *sprite)
{
    u16 x, y;
    s16 x2, y2;

    sprite->invisible = FALSE;
    x = sprite->x + sprite->x2 + sprite->centerToCornerVecX + gSpriteCoordOffsetX;
    y = sprite->y + sprite->y2 + sprite->centerToCornerVecY + gSpriteCoordOffsetY;

    x2 = x + 64; // Dimensions of the rotating gate
    y2 = y + 64;

    if ((s16)x > DISPLAY_WIDTH + 16 - 1 || x2 < -16)
    {
        sprite->invisible = TRUE;
    }

    if ((s16)y > DISPLAY_HEIGHT + 16 - 1 || y2 < -16)
    {
        sprite->invisible = TRUE;
    }
}

static void LoadRotatingGatePics(void)
{
    LoadSpriteSheets(sRotatingGatesGraphicsTable);
}

static void RotatingGate_DestroyGatesOutsideViewport(void)
{
    s32 i;

    s16 x = gSaveBlock1Ptr->pos.x - 2;
    s16 x2 = gSaveBlock1Ptr->pos.x + MAP_OFFSET_W + 2;
    s16 y = gSaveBlock1Ptr->pos.y - 2;
    s16 y2 = gSaveBlock1Ptr->pos.y + MAP_OFFSET_H;

    for (i = 0; i < sRotatingGate_PuzzleCount; i++)
    {
        s16 xGate = sRotatingGate_PuzzleConfig[i].x + MAP_OFFSET;
        s16 yGate = sRotatingGate_PuzzleConfig[i].y + MAP_OFFSET;

        if (sRotatingGate_GateSpriteIds[i] == MAX_SPRITES)
            continue;

        if (xGate < x || xGate > x2 || yGate < y || yGate > y2)
        {
            struct Sprite *sprite = &gSprites[sRotatingGate_GateSpriteIds[i]];
            FreeSpriteOamMatrix(sprite);
            DestroySprite(sprite);
            sRotatingGate_GateSpriteIds[i] = MAX_SPRITES;
        }
    }
}

static s32 RotatingGate_CanRotate(u8 gateId, s32 rotationDirection)
{
    const struct Coords8 *armPos;
    u8 orientation;
    s16 x, y;
    u8 shape;
    s32 i, j;

    if (rotationDirection == ROTATE_ANTICLOCKWISE)
        armPos = sRotatingGate_ArmPositionsAntiClockwiseRotation;
    else if (rotationDirection == ROTATE_CLOCKWISE)
        armPos = sRotatingGate_ArmPositionsClockwiseRotation;
    else
        return FALSE;

    orientation = RotatingGate_GetGateOrientation(gateId);

    shape = sRotatingGate_PuzzleConfig[gateId].shape;
    x = sRotatingGate_PuzzleConfig[gateId].x + MAP_OFFSET;
    y = sRotatingGate_PuzzleConfig[gateId].y + MAP_OFFSET;

    // Loop through the gate's "arms" clockwise (north, south, east, west)
    for (i = GATE_ARM_NORTH; i <= GATE_ARM_WEST; i++)
    {
        // Ensure that no part of the arm collides with the map
        for (j = 0; j < GATE_ARM_MAX_LENGTH; j++)
        {
            u8 armIndex = 2 * ((orientation + i) % 4) + j;

            if (sRotatingGate_ArmLayout[shape][2 * i + j])
            {
                if (MapGridGetCollisionAt(x + armPos[armIndex].x, y + armPos[armIndex].y) == 1)
                    return FALSE;
            }
        }
    }

    return TRUE;
}

static s32 RotatingGate_HasArm(u8 gateId, u8 armInfo)
{
    s32 arm = armInfo / 2;
    s32 isLongArm = armInfo % 2;

    s8 armOrientation = (arm - RotatingGate_GetGateOrientation(gateId) + 4) % 4;
    s32 shape = sRotatingGate_PuzzleConfig[gateId].shape;
    return sRotatingGate_ArmLayout[shape][armOrientation * 2 + isLongArm];
}

static void RotatingGate_TriggerRotationAnimation(u8 gateId, s32 rotationDirection)
{
    if (sRotatingGate_GateSpriteIds[gateId] != MAX_SPRITES)
    {
        struct Sprite *sprite = &gSprites[sRotatingGate_GateSpriteIds[gateId]];
        sprite->data[1] = rotationDirection;
        sprite->data[2] = RotatingGate_GetGateOrientation(gateId);
    }
}

static u8 RotatingGate_GetRotationInfo(u8 direction, s16 x, s16 y)
{
    const u8 *ptr;

    if (direction == DIR_NORTH)
        ptr = sRotatingGate_RotationInfoNorth;
    else if (direction == DIR_SOUTH)
        ptr = sRotatingGate_RotationInfoSouth;
    else if (direction == DIR_WEST)
        ptr = sRotatingGate_RotationInfoWest;
    else if (direction == DIR_EAST)
        ptr = sRotatingGate_RotationInfoEast;
    else
        return GATE_ROT_NONE;

    return ptr[y * 4 + x];
}

void RotatingGate_InitPuzzle(void)
{
    if (GetCurrentMapRotatingGatePuzzleType())
    {
        RotatingGate_LoadPuzzleConfig();
        RotatingGate_ResetAllGateOrientations();
    }
}

void RotatingGatePuzzleCameraUpdate(s16 deltaX, s16 deltaY)
{
    if (GetCurrentMapRotatingGatePuzzleType())
    {
        RotatingGate_CreateGatesWithinViewport(deltaX, deltaY);
        RotatingGate_DestroyGatesOutsideViewport();
    }
}

void RotatingGate_InitPuzzleAndGraphics(void)
{
    if (GetCurrentMapRotatingGatePuzzleType())
    {
        LoadRotatingGatePics();
        RotatingGate_LoadPuzzleConfig();
        RotatingGate_CreateGatesWithinViewport(0, 0);
    }
}

bool32 CheckForRotatingGatePuzzleCollision(u8 direction, s16 x, s16 y)
{
    s32 i;

    if (!GetCurrentMapRotatingGatePuzzleType())
        return FALSE;
    for (i = 0; i < sRotatingGate_PuzzleCount; i++)
    {
        s16 gateX = sRotatingGate_PuzzleConfig[i].x + MAP_OFFSET;
        s16 gateY = sRotatingGate_PuzzleConfig[i].y + MAP_OFFSET;

        if (gateX - 2 <= x && x <= gateX + 1 && gateY - 2 <= y && y <= gateY + 1)
        {
            s16 centerX = x - gateX + 2;
            s16 centerY = y - gateY + 2;
            u8 rotationInfo = RotatingGate_GetRotationInfo(direction, centerX, centerY);

            if (rotationInfo != GATE_ROT_NONE)
            {
                u8 rotationDirection = ((rotationInfo & 0xF0) >> 4);
                u8 armInfo = rotationInfo & 0xF;

                if (RotatingGate_HasArm(i, armInfo))
                {
                    if (RotatingGate_CanRotate(i, rotationDirection))
                    {
                        RotatingGate_TriggerRotationAnimation(i, rotationDirection);
                        RotatingGate_RotateInDirection(i, rotationDirection);
                        return FALSE;
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

bool32 CheckForRotatingGatePuzzleCollisionWithoutAnimation(u8 direction, s16 x, s16 y)
{
    s32 i;

    if (!GetCurrentMapRotatingGatePuzzleType())
        return FALSE;
    for (i = 0; i < sRotatingGate_PuzzleCount; i++)
    {
        s16 gateX = sRotatingGate_PuzzleConfig[i].x + MAP_OFFSET;
        s16 gateY = sRotatingGate_PuzzleConfig[i].y + MAP_OFFSET;

        if (gateX - 2 <= x && x <= gateX + 1 && gateY - 2 <= y && y <= gateY + 1)
        {
            s16 centerX = x - gateX + 2;
            s16 centerY = y - gateY + 2;
            u8 rotationInfo = RotatingGate_GetRotationInfo(direction, centerX, centerY);

            if (rotationInfo != GATE_ROT_NONE)
            {
                u8 rotationDirection = ((rotationInfo & 0xF0) >> 4);
                u8 armInfo = rotationInfo & 0xF;

                if (RotatingGate_HasArm(i, armInfo))
                {
                    if (!RotatingGate_CanRotate(i, rotationDirection))
                    {
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}
