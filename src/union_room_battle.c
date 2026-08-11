#include "global.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "gba/isagbprint.h"
#include "overworld.h"
#include "script.h"
#include "task.h"
#include "union_room.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"

// JP: ROM/RAM data bound via ld_script_jp.txt / sym_ewram_jp.txt.
extern const u8 sUnionRoomLocalIds[];
extern const u8 sMovement_UnionPlayerExit[];
extern const u8 sMovement_UnionPlayerEnter[];
extern u32 sUnionObjRefreshTimer;
extern struct UnionRoomObject *sUnionObjWork;
// JP: still in asm/union_room_battle.s.
extern u8 CreateTask_AnimateUnionRoomPlayers(void);
extern bool32 SetUnionRoomPlayerEnterExitMovement(u32 leaderId, const u8 *movement);
extern void HideUnionRoomPlayer(u32 player_idx);
extern void RemoveUnionRoomPlayerObjectEvent(u32 leaderId);
extern bool32 IsUnionRoomPlayerInvisible(u32 leaderId, u32 memberId);
extern u8 GetUnionRoomPlayerGraphicsId(u32 gender, u32 id);
extern const char gAssertFile_rfu_union_tool[];
extern const char gAssertCond_UnionObjWork2[];

bool32 TryReleaseUnionRoomPlayerObjectEvent(u32 leaderId)
{
    u8 objectId;
    struct ObjectEvent *object;

    if (TryGetObjectEventIdByLocalIdAndMap(sUnionRoomLocalIds[leaderId], gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, &objectId))
        return TRUE;

    object = &gObjectEvents[objectId];
    if (!ObjectEventClearHeldMovementIfFinished(object))
        return FALSE;

    if (!ArePlayerFieldControlsLocked())
        UnfreezeEventObject(object);
    else
        FreezeEventObject(object);
    return TRUE;
}

u8 InitUnionRoomPlayerObjects(struct UnionRoomObject *players)
{
    s32 i;

    sUnionObjRefreshTimer = 0;
    sUnionObjWork = players;
    if (players == NULL)
        AGBAssert(gAssertFile_rfu_union_tool, 0x1B9, gAssertCond_UnionObjWork2, TRUE);
    for (i = 0; i < MAX_UNION_ROOM_LEADERS; i++)
    {
        players[i].state = 0;
        players[i].gfxId = 0;
        players[i].animState = 0;
        players[i].schedAnim = UNION_ROOM_SPAWN_NONE;
    }
    return CreateTask_AnimateUnionRoomPlayers();
}

bool32 AnimateUnionRoomPlayerDespawn(s8 *state, u32 leaderId, struct UnionRoomObject *object)
{
    switch (*state)
    {
    case 0:
        if (SetUnionRoomPlayerEnterExitMovement(leaderId, sMovement_UnionPlayerExit) == TRUE)
        {
            HideUnionRoomPlayer(leaderId);
            (*state)++;
        }
        break;
    case 1:
        if (TryReleaseUnionRoomPlayerObjectEvent(leaderId))
        {
            RemoveUnionRoomPlayerObjectEvent(leaderId);
            HideUnionRoomPlayer(leaderId);
            *state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

bool32 AnimateUnionRoomPlayerSpawn(s8 *state, u32 leaderId, struct UnionRoomObject *object)
{
    s16 x, y;

    switch (*state)
    {
    case 0:
        if (!is_walking_or_running())
            break;
        PlayerGetDestCoords(&x, &y);
        if (IsUnionRoomPlayerAt(leaderId, 0, x, y) == TRUE)
            break;
        player_get_pos_including_state_based_drift(&x, &y);
        if (IsUnionRoomPlayerAt(leaderId, 0, x, y) == TRUE)
            break;
        SetUnionRoomPlayerGfx(leaderId, object->gfxId);
        CreateUnionRoomPlayerObjectEvent(leaderId);
        ShowUnionRoomPlayer(leaderId);
        (*state)++;
        // fallthrough
    case 3:
        if (SetUnionRoomPlayerEnterExitMovement(leaderId, sMovement_UnionPlayerEnter) == TRUE)
            (*state)++;
        break;
    case 2:
        if (TryReleaseUnionRoomPlayerObjectEvent(leaderId))
        {
            *state = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

bool32 SpawnGroupLeader(u32 leaderId, u32 gender, u32 id)
{
    struct UnionRoomObject *object = &sUnionObjWork[leaderId];

    if (sUnionObjWork == NULL)
        AGBAssert(gAssertFile_rfu_union_tool, 0x230, gAssertCond_UnionObjWork2, TRUE);
    object->schedAnim = 1;
    object->gfxId = GetUnionRoomPlayerGraphicsId(gender, id);
    if (object->state == 0)
        return TRUE;
    else
        return FALSE;
}

bool32 DespawnGroupLeader(u32 leaderId)
{
    struct UnionRoomObject *object = &sUnionObjWork[leaderId];

    if (sUnionObjWork == NULL)
        AGBAssert(gAssertFile_rfu_union_tool, 0x240, gAssertCond_UnionObjWork2, TRUE);
    object->schedAnim = 2;
    if (object->state == 1)
        return TRUE;
    else
        return FALSE;
}

void AnimateUnionRoomPlayer(u32 leaderId, struct UnionRoomObject *object)
{
    switch (object->state)
    {
    case 0:
        if (object->schedAnim == 1)
        {
            object->state = 2;
            object->animState = 0;
        }
        else
        {
            break;
        }
        // fallthrough
    case 2:
        if (!IsUnionRoomPlayerInvisible(leaderId, 0) && object->schedAnim == 2)
        {
            object->state = 0;
            object->animState = 0;
            RemoveUnionRoomPlayerObjectEvent(leaderId);
            HideUnionRoomPlayer(leaderId);
        }
        else if (AnimateUnionRoomPlayerSpawn(&object->animState, leaderId, object) == TRUE)
        {
            object->state = 1;
        }
        break;
    case 1:
        if (object->schedAnim == 2)
        {
            object->state = 3;
            object->animState = 0;
        }
        else
        {
            break;
        }
        // fallthrough
    case 3:
        if (AnimateUnionRoomPlayerDespawn(&object->animState, leaderId, object) == TRUE)
            object->state = 0;
        break;
    }
    object->schedAnim = 0;
}
