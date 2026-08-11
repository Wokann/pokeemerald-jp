#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "gba/isagbprint.h"
#include "link_rfu.h"
#include "script.h"
#include "sprite.h"
#include "task.h"
#include "union_room.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"

#define UR_SPRITE_START_ID (MAX_SPRITES - MAX_UNION_ROOM_LEADERS)

#define UR_PLAYER_SPRITE_ID(leaderId, memberId) (MAX_RFU_PLAYERS * leaderId + memberId)

extern const u8 sUnionRoomObjGfxIds[][NUM_UNION_ROOM_CLASSES + 2];
extern const s16 sUnionRoomPlayerCoords[][2];
extern const s8 sUnionRoomGroupOffsets[][2];
extern const u8 sMemberFacingDirections[];
extern const u8 sUnionRoomLocalIds[];
extern const char gAssertFile_rfu_union_tool[];
extern const char gAssertCond_UnionObjWork[];
extern struct UnionRoomObject *sUnionObjWork;
extern void DestroyTask_AnimateUnionRoomPlayers(void);
extern void SetUnionRoomObjectFacingDirection(s32 memberId, s32 leaderId, u8 facingDirection);

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

void DestroyUnionRoomPlayerObjects(void)
{
    s32 i;
    for (i = 0; i < MAX_UNION_ROOM_LEADERS; i++)
    {
        if (!IsUnionRoomPlayerHidden(i))
        {
            RemoveUnionRoomPlayerObjectEvent(i);
            HideUnionRoomPlayer(i);
        }
    }
    sUnionObjWork = NULL;
    DestroyTask_AnimateUnionRoomPlayers();
}

void CreateUnionRoomPlayerSprites(u8 *spriteIds, s32 leaderId)
{
    s32 memberId;
    for (memberId = 0; memberId < MAX_RFU_PLAYERS; memberId++)
    {
        s32 id = UR_PLAYER_SPRITE_ID(leaderId, memberId);
        spriteIds[id] = CreateVirtualObject(OBJ_EVENT_GFX_MAN_4,
                                           id - UR_SPRITE_START_ID,
                                           sUnionRoomPlayerCoords[leaderId][0] + sUnionRoomGroupOffsets[memberId][0],
                                           sUnionRoomPlayerCoords[leaderId][1] + sUnionRoomGroupOffsets[memberId][1],
                                           3, 1);
        SetVirtualObjectInvisibility(id - UR_SPRITE_START_ID, TRUE);
    }
}

void DestroyUnionRoomPlayerSprites(u8 *spriteIds)
{
    s32 i;
    for (i = 0; i < NUM_UNION_ROOM_SPRITES; i++)
        DestroySprite(&gSprites[spriteIds[i]]);
}

void SetTilesAroundUnionRoomPlayersPassable(void)
{
    s32 i, memberId, x, y;
    for (i = 0; i < MAX_UNION_ROOM_LEADERS; i++)
    {
        for (memberId = 0; memberId < MAX_RFU_PLAYERS; memberId++)
        {
            GetUnionRoomPlayerCoords(i, memberId, &x, &y);
            MapGridSetMetatileImpassabilityAt(x, y, FALSE);
        }
    }
}

u8 GetNewFacingDirectionForUnionRoomPlayer(u32 memberId, u32 leaderId, struct RfuGameData *gameData)
{
    if (memberId) // If not leader
        return sMemberFacingDirections[memberId];
    else if (gameData->activity == (ACTIVITY_CHAT | IN_UNION_ROOM))
        return DIR_SOUTH;
    else
        return DIR_EAST;
}

bool32 IsUnionRoomPlayerInvisible(u32 leaderId, u32 memberId)
{
    return IsVirtualObjectInvisible(UR_PLAYER_SPRITE_ID(leaderId, memberId) - UR_SPRITE_START_ID);
}

void SpawnGroupMember(u32 leaderId, u32 memberId, u8 graphicsId, struct RfuGameData *gameData)
{
    s32 x, y;
    s32 id = UR_PLAYER_SPRITE_ID(leaderId, memberId);
    if (IsUnionRoomPlayerInvisible(leaderId, memberId) == TRUE)
    {
        SetVirtualObjectInvisibility(id - UR_SPRITE_START_ID, FALSE);
        SetVirtualObjectSpriteAnim(id - UR_SPRITE_START_ID, UNION_ROOM_SPAWN_IN);
    }
    SetVirtualObjectGraphics(id - UR_SPRITE_START_ID, graphicsId);
    SetUnionRoomObjectFacingDirection(memberId, leaderId, GetNewFacingDirectionForUnionRoomPlayer(memberId, leaderId, gameData));
    GetUnionRoomPlayerCoords(leaderId, memberId, &x, &y);
    MapGridSetMetatileImpassabilityAt(x, y, TRUE);
}

void DespawnGroupMember(u32 leaderId, u32 memberId)
{
    s32 x, y;
    SetVirtualObjectSpriteAnim(UR_PLAYER_SPRITE_ID(leaderId, memberId) - UR_SPRITE_START_ID, UNION_ROOM_SPAWN_OUT);
    GetUnionRoomPlayerCoords(leaderId, memberId, &x, &y);
    MapGridSetMetatileImpassabilityAt(x, y, FALSE);
}
