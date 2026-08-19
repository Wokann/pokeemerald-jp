#include "global.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "malloc.h"
#include "rotating_tile_puzzle.h"
#include "script_movement.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/metatile_labels.h"

#define ROTATE_COUNTERCLOCKWISE 0
#define ROTATE_CLOCKWISE        1
#define ROTATE_NONE             2

#define ROTATING_TILE_DATA __attribute__((section(".rodata.rotating_tile_data")))

struct RotatingTileObject
{
    u8 prevPuzzleTileNum;
    u8 eventTemplateId;
    // JP ROM uses a 4-byte stride per object (two padding bytes).
    u8 padding[2];
};

struct RotatingTilePuzzle
{
    struct RotatingTileObject objects[OBJECT_EVENTS_COUNT];
    u8 numObjects;      /*0x40*/
    bool8 isTrickHouse; /*0x41*/
};

ROTATING_TILE_DATA const u8 sMovement_ShiftRight[] = {0x94, 0x0B, 0x95, 0xFE};
ROTATING_TILE_DATA const u8 sMovement_ShiftDown[] = {0x94, 0x08, 0x95, 0xFE};
ROTATING_TILE_DATA const u8 sMovement_ShiftLeft[] = {0x94, 0x0A, 0x95, 0xFE};
ROTATING_TILE_DATA const u8 sMovement_ShiftUp[] = {0x94, 0x09, 0x95, 0xFE};
ROTATING_TILE_DATA const u8 sMovement_FaceRight[] = {0x03, 0xFE};
ROTATING_TILE_DATA const u8 sMovement_FaceDown[] = {0x00, 0xFE};
ROTATING_TILE_DATA const u8 sMovement_FaceLeft[] = {0x02, 0xFE};
ROTATING_TILE_DATA const u8 sMovement_FaceUp[] = {0x01, 0xFE};

static void SaveRotatingTileObject(u8, u8);
static void TurnUnsavedRotatingTileObject(u8, u8);

// EWRAM pointer at 0x0203CB1C, bound via ld alias.
extern struct RotatingTilePuzzle *sRotatingTilePuzzle;

void InitRotatingTilePuzzle(bool8 isTrickHouse)
{
    if (sRotatingTilePuzzle == NULL)
        sRotatingTilePuzzle = AllocZeroed(sizeof(*sRotatingTilePuzzle));

    sRotatingTilePuzzle->isTrickHouse = isTrickHouse;
}

void FreeRotatingTilePuzzle(void)
{
    u8 id;

    TRY_FREE_AND_SET_NULL(sRotatingTilePuzzle);

    id = GetObjectEventIdByLocalIdAndMap(LOCALID_PLAYER, 0, 0);
    ObjectEventClearHeldMovementIfFinished(&gObjectEvents[id]);
    ScriptMovement_UnfreezeObjectEvents();
}

u16 MoveRotatingTileObjects(u8 puzzleNumber)
{
    u8 i;
    struct ObjectEventTemplate *objectEvents = gSaveBlock1Ptr->objectEventTemplates;
    u16 localId = LOCALID_NONE;

    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        s32 puzzleTileStart;
        u8 puzzleTileNum;
        s16 x = objectEvents[i].x + MAP_OFFSET;
        s16 y = objectEvents[i].y + MAP_OFFSET;
        u16 metatile = MapGridGetMetatileIdAt(x, y);

        if (!sRotatingTilePuzzle->isTrickHouse)
            puzzleTileStart = METATILE_MossdeepGym_YellowArrow_Right;
        else
            puzzleTileStart = METATILE_TrickHousePuzzle_Arrow_YellowOnWhite_Right;

        // Object is on a metatile before the puzzle tile section
        if (metatile < METATILE_MossdeepGym_YellowArrow_Right)
            continue;

        // Object is on a metatile after the puzzle tile section (never occurs)
        if ((u8)((metatile - puzzleTileStart) / METATILE_ROW_WIDTH) >= 5)
            continue;

        // Object is on a metatile in puzzle tile section, but not one of the currently rotating color
        if ((u8)((metatile - puzzleTileStart) / METATILE_ROW_WIDTH) != puzzleNumber)
            continue;

        puzzleTileNum = (u8)((metatile - puzzleTileStart) % METATILE_ROW_WIDTH);

        // First 4 puzzle tiles are the colored arrows
        if (puzzleTileNum < 4)
        {
            s8 x = 0;
            s8 y = 0;
            const u8 *movementScript;

            switch (puzzleTileNum)
            {
            case 0: // Right Arrow
                movementScript = sMovement_ShiftRight;
                x = 1;
                break;
            case 1: // Down Arrow
                movementScript = sMovement_ShiftDown;
                y = 1;
                break;
            case 2: // Left Arrow
                movementScript = sMovement_ShiftLeft;
                x = -1;
                break;
            case 3: // Up Arrow
                movementScript = sMovement_ShiftUp;
                y = -1;
                break;
            default:
                continue;
            }

            objectEvents[i].x += x;
            objectEvents[i].y += y;
            if (GetObjectEventIdByLocalIdAndMap(objectEvents[i].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup) != OBJECT_EVENTS_COUNT)
            {
                SaveRotatingTileObject(i, puzzleTileNum);
                localId = objectEvents[i].localId;
                ScriptMovement_StartObjectMovementScript(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, movementScript);
            }
            // Never reached in normal gameplay
            else
            {
                TurnUnsavedRotatingTileObject(i, puzzleTileNum);
            }
        }
    }

    return localId;
}

void TurnRotatingTileObjects(void)
{
    u8 i;
    s32 puzzleTileStart;
    struct ObjectEventTemplate *objectEvents;

    if (sRotatingTilePuzzle == NULL)
        return;

    if (!sRotatingTilePuzzle->isTrickHouse)
        puzzleTileStart = METATILE_MossdeepGym_YellowArrow_Right;
    else
        puzzleTileStart = METATILE_TrickHousePuzzle_Arrow_YellowOnWhite_Right;

    objectEvents = gSaveBlock1Ptr->objectEventTemplates;
    for (i = 0; i < sRotatingTilePuzzle->numObjects; i++)
    {
        s32 rotation;
        s8 tileDifference;
        u8 objectEventId;
        s16 x = objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].x + MAP_OFFSET;
        s16 y = objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].y + MAP_OFFSET;
        u16 metatile = MapGridGetMetatileIdAt(x, y);

        tileDifference = (u8)((metatile - puzzleTileStart) % METATILE_ROW_WIDTH);
        tileDifference -= (sRotatingTilePuzzle->objects[i].prevPuzzleTileNum);

        if (tileDifference < 0 || tileDifference == 3)
        {
            if (tileDifference == -3)
                rotation = ROTATE_CLOCKWISE;
            else
                rotation = ROTATE_COUNTERCLOCKWISE;
        }
        else
        {
            if (tileDifference > 0)
                rotation = ROTATE_CLOCKWISE;
            else
                rotation = ROTATE_NONE;
        }

        objectEventId = GetObjectEventIdByLocalIdAndMap(objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
        if (objectEventId != OBJECT_EVENTS_COUNT)
        {
            const u8 *movementScript;
            u8 direction = gObjectEvents[objectEventId].facingDirection;
            if (rotation == ROTATE_COUNTERCLOCKWISE)
            {
                switch (direction)
                {
                case DIR_EAST:
                    movementScript = sMovement_FaceUp;
                    objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
                    break;
                case DIR_SOUTH:
                    movementScript = sMovement_FaceRight;
                    objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
                    break;
                case DIR_WEST:
                    movementScript = sMovement_FaceDown;
                    objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
                    break;
                case DIR_NORTH:
                    movementScript = sMovement_FaceLeft;
                    objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
                    break;
                default:
                    continue;
                }
                ScriptMovement_StartObjectMovementScript(objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].localId,
                                                         gSaveBlock1Ptr->location.mapNum,
                                                         gSaveBlock1Ptr->location.mapGroup,
                                                         movementScript);
            }
            else if (rotation == ROTATE_CLOCKWISE)
            {
                switch (direction)
                {
                case DIR_EAST:
                    movementScript = sMovement_FaceDown;
                    objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
                    break;
                case DIR_SOUTH:
                    movementScript = sMovement_FaceLeft;
                    objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
                    break;
                case DIR_WEST:
                    movementScript = sMovement_FaceUp;
                    objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
                    break;
                case DIR_NORTH:
                    movementScript = sMovement_FaceRight;
                    objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
                    break;
                default:
                    continue;
                }
                ScriptMovement_StartObjectMovementScript(objectEvents[sRotatingTilePuzzle->objects[i].eventTemplateId].localId,
                                                         gSaveBlock1Ptr->location.mapNum,
                                                         gSaveBlock1Ptr->location.mapGroup,
                                                         movementScript);
            }
        }
    }
}

static void SaveRotatingTileObject(u8 eventTemplateId, u8 puzzleTileNum)
{
    sRotatingTilePuzzle->objects[sRotatingTilePuzzle->numObjects].eventTemplateId = eventTemplateId;
    sRotatingTilePuzzle->objects[sRotatingTilePuzzle->numObjects].prevPuzzleTileNum = puzzleTileNum;
    sRotatingTilePuzzle->numObjects++;
}

// Functionally unused
static void TurnUnsavedRotatingTileObject(u8 eventTemplateId, u8 puzzleTileNum)
{
    s8 tileDifference;
    s32 rotation;
    s32 puzzleTileStart;
    u16 movementType;
    struct ObjectEventTemplate *objectEvents = gSaveBlock1Ptr->objectEventTemplates;
    s16 x = objectEvents[eventTemplateId].x + MAP_OFFSET;
    s16 y = objectEvents[eventTemplateId].y + MAP_OFFSET;
    u16 metatile = MapGridGetMetatileIdAt(x, y);

    if (!sRotatingTilePuzzle->isTrickHouse)
        puzzleTileStart = METATILE_MossdeepGym_YellowArrow_Right;
    else
        puzzleTileStart = METATILE_TrickHousePuzzle_Arrow_YellowOnWhite_Right;

    tileDifference = (u8)((metatile - puzzleTileStart) % METATILE_ROW_WIDTH);
    tileDifference -= puzzleTileNum;

    if (tileDifference < 0 || tileDifference == 3)
        rotation = ROTATE_COUNTERCLOCKWISE;
    else if (tileDifference > 0 || tileDifference == -3)
        rotation = ROTATE_CLOCKWISE;
    else
        rotation = ROTATE_NONE;

    movementType = objectEvents[eventTemplateId].movementType;
    if (rotation == ROTATE_COUNTERCLOCKWISE)
    {
        switch (movementType)
        {
        case MOVEMENT_TYPE_FACE_RIGHT:
            objectEvents[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
            break;
        case MOVEMENT_TYPE_FACE_DOWN:
            objectEvents[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
            break;
        case MOVEMENT_TYPE_FACE_LEFT:
            objectEvents[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
            break;
        case MOVEMENT_TYPE_FACE_UP:
            objectEvents[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
            break;
        default:
            break;
        }
    }
    else if (rotation == ROTATE_CLOCKWISE)
    {
        switch (movementType)
        {
        case MOVEMENT_TYPE_FACE_RIGHT:
            objectEvents[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_DOWN;
            break;
        case MOVEMENT_TYPE_FACE_DOWN:
            objectEvents[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_LEFT;
            break;
        case MOVEMENT_TYPE_FACE_LEFT:
            objectEvents[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_UP;
            break;
        case MOVEMENT_TYPE_FACE_UP:
            objectEvents[eventTemplateId].movementType = MOVEMENT_TYPE_FACE_RIGHT;
            break;
        default:
            break;
        }
    }
}
