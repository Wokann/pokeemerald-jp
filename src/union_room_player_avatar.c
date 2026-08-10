#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "gba/isagbprint.h"
#include "script.h"
#include "task.h"
#include "union_room.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"

#define UR_SPRITE_START_ID (MAX_SPRITES - MAX_UNION_ROOM_LEADERS)

#define UR_PLAYER_SPRITE_ID(leaderId, memberId) (MAX_RFU_PLAYERS * leaderId + memberId)

extern const u8 sUnionRoomObjGfxIds[][NUM_UNION_ROOM_CLASSES + 2];
extern const s16 sUnionRoomPlayerCoords[][2];
extern const s8 sUnionRoomGroupOffsets[][2];
extern const u8 sUnionRoomLocalIds[];
extern const char gAssertFile_rfu_union_tool[];
extern const char gAssertCond_UnionObjWork[];

bool32 is_walking_or_running(void)
{
    if (gPlayerAvatar.tileTransitionState == T_TILE_CENTER || gPlayerAvatar.tileTransitionState == T_NOT_MOVING)
        return TRUE;
    else
        return FALSE;
}

u8 GetUnionRoomPlayerGraphicsId(u32 gender, u32 id)
{
    return sUnionRoomObjGfxIds[gender][id % NUM_UNION_ROOM_CLASSES];
}

void GetUnionRoomPlayerCoords(u32 leaderId, u32 memberId, s32 *x, s32 *y)
{
    *x = sUnionRoomPlayerCoords[leaderId][0] + sUnionRoomGroupOffsets[memberId][0] + MAP_OFFSET;
    *y = sUnionRoomPlayerCoords[leaderId][1] + sUnionRoomGroupOffsets[memberId][1] + MAP_OFFSET;
}

bool32 IsUnionRoomPlayerAt(u32 leaderId, u32 memberId, s32 x, s32 y)
{
    if ((sUnionRoomPlayerCoords[leaderId][0] + sUnionRoomGroupOffsets[memberId][0] + MAP_OFFSET == x)
    &&  (sUnionRoomPlayerCoords[leaderId][1] + sUnionRoomGroupOffsets[memberId][1] + MAP_OFFSET == y))
        return TRUE;
    else
        return FALSE;
}

bool32 IsUnionRoomPlayerHidden(u32 player_idx)
{
    return FlagGet(FLAG_HIDE_UNION_ROOM_PLAYER_1 + player_idx);
}

void HideUnionRoomPlayer(u32 player_idx)
{
    FlagSet(FLAG_HIDE_UNION_ROOM_PLAYER_1 + player_idx);
}

void ShowUnionRoomPlayer(u32 player_idx)
{
    FlagClear(FLAG_HIDE_UNION_ROOM_PLAYER_1 + player_idx);
}

void SetUnionRoomPlayerGfx(u32 leaderId, u32 gfxId)
{
    VarSet(VAR_OBJ_GFX_ID_0 + leaderId, gfxId);
}

void CreateUnionRoomPlayerObjectEvent(u32 leaderId)
{
    TrySpawnObjectEvent(sUnionRoomLocalIds[leaderId], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

void RemoveUnionRoomPlayerObjectEvent(u32 leaderId)
{
    RemoveObjectEventByLocalIdAndMap(sUnionRoomLocalIds[leaderId], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

bool32 SetUnionRoomPlayerEnterExitMovement(u32 leaderId, const u8 *movement)
{
    u8 objectId;
    struct ObjectEvent *object;
    if (TryGetObjectEventIdByLocalIdAndMap(sUnionRoomLocalIds[leaderId], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectId))
        return FALSE;
    object = &gObjectEvents[objectId];
    if (ObjectEventIsMovementOverridden(object))
        return FALSE;
    if (ObjectEventSetHeldMovement(object, *movement))
    {
        AGBAssert(gAssertFile_rfu_union_tool, 0x182, gAssertCond_UnionObjWork, TRUE);
    }
    else
    {
        return TRUE;
    }
    return FALSE;
}
