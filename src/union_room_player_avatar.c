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
extern const u8 sOppositeFacingDirection[];
extern const u8 sUnionRoomLocalIds[];
extern const u8 sMovement_UnionPlayerExit[];
extern const u8 sMovement_UnionPlayerEnter[];
extern const char gAssertFile_rfu_union_tool[];
extern const char gAssertCond_UnionObjWork[];
extern const char gAssertCond_UnionObjWork2[];
extern struct UnionRoomObject *sUnionObjWork;
extern u32 sUnionObjRefreshTimer;
extern void DestroyTask_AnimateUnionRoomPlayers(void);
u8 CreateTask_AnimateUnionRoomPlayers(void);
bool32 IsUnionRoomPlayerInvisible(u32 leaderId, u32 memberId);
void SetUnionRoomObjectFacingDirection(s32 memberId, s32 leaderId, u8 newDirection);
extern bool32 SpawnGroupLeader(u32 leaderId, u32 gender, u32 id);
extern bool32 DespawnGroupLeader(u32 leaderId);

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

static void Task_AnimateUnionRoomPlayers(u8 taskId)
{
    s32 i;

    if (sUnionObjWork == NULL)
        AGBAssert(gAssertFile_rfu_union_tool, 0x282, gAssertCond_UnionObjWork2, TRUE);
    for (i = 0; i < MAX_UNION_ROOM_LEADERS; i++)
        AnimateUnionRoomPlayer(i, &sUnionObjWork[i]);
}

u8 CreateTask_AnimateUnionRoomPlayers(void)
{
    u8 taskId;

    if (FuncIsActiveTask(Task_AnimateUnionRoomPlayers) == TRUE)
    {
        AGBAssert(gAssertFile_rfu_union_tool, 0x28E, gAssertCond_UnionObjWork, TRUE);
        return 16;
    }
    taskId = CreateTask(Task_AnimateUnionRoomPlayers, 5);
    return taskId;
}

void DestroyTask_AnimateUnionRoomPlayers(void)
{
    u8 taskId = FindTaskIdByFunc(Task_AnimateUnionRoomPlayers);

    if (taskId <= 0xF)
        DestroyTask(taskId);
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

void AssembleGroup(u32 leaderId, struct RfuGameData *gameData)
{
    s16 x, y, x2, y2;
    s32 i;

    PlayerGetDestCoords(&x, &y);
    player_get_pos_including_state_based_drift(&x2, &y2);
    if (IsVirtualObjectInvisible(UR_PLAYER_SPRITE_ID(leaderId, 0) - UR_SPRITE_START_ID) == TRUE)
    {
        if (IsUnionRoomPlayerAt(leaderId, 0, x, y) == TRUE || IsUnionRoomPlayerAt(leaderId, 0, x2, y2) == TRUE)
            return;
        SpawnGroupMember(leaderId, 0, GetUnionRoomPlayerGraphicsId(gameData->playerGender, gameData->compatibility.playerTrainerId[0]), gameData);
    }
    for (i = 1; i < MAX_RFU_PLAYERS; i++)
    {
        if (gameData->partnerInfo[i - 1] == 0)
        {
            DespawnGroupMember(leaderId, i);
        }
        else if (IsUnionRoomPlayerAt(leaderId, i, x, y) == FALSE && IsUnionRoomPlayerAt(leaderId, i, x2, y2) == FALSE)
        {
            SpawnGroupMember(leaderId, i, GetUnionRoomPlayerGraphicsId((gameData->partnerInfo[i - 1] >> PINFO_GENDER_SHIFT) & 1,
                                                                        gameData->partnerInfo[i - 1] & PINFO_TID_MASK),
                                                                        gameData);
        }
    }
}

void SpawnGroupLeaderAndMembers(u32 leaderId, struct RfuGameData *gameData)
{
    u32 i;
    switch (gameData->activity)
    {
    case ACTIVITY_NONE | IN_UNION_ROOM:
    case ACTIVITY_PLYRTALK | IN_UNION_ROOM:
        SpawnGroupLeader(leaderId, gameData->playerGender, gameData->compatibility.playerTrainerId[0]);
        for (i = 0; i < MAX_RFU_PLAYERS; i++)
            DespawnGroupMember(leaderId, i);
        break;
    case ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM:
    case ACTIVITY_TRADE | IN_UNION_ROOM:
    case ACTIVITY_CHAT | IN_UNION_ROOM:
    case ACTIVITY_CARD | IN_UNION_ROOM:
    case ACTIVITY_ACCEPT | IN_UNION_ROOM:
    case ACTIVITY_DECLINE | IN_UNION_ROOM:
    case ACTIVITY_NPCTALK | IN_UNION_ROOM:
        DespawnGroupLeader(leaderId);
        AssembleGroup(leaderId, gameData);
        break;
    default:
        AGBAssert(gAssertFile_rfu_union_tool, 0x3D3, gAssertCond_UnionObjWork, TRUE);
        break;
    }
}

void DespawnGroupLeaderAndMembers(u32 leaderId, struct RfuGameData *gameData)
{
    s32 i;
    DespawnGroupLeader(leaderId);
    for (i = 0; i < MAX_RFU_PLAYERS; i++)
        DespawnGroupMember(leaderId, i);
}

void UpdateUnionRoomPlayerSprites(struct WirelessLink_URoom *uroom)
{
    s32 i;
    struct RfuPlayer *leaders;
    sUnionObjRefreshTimer = 0;
    for (i = 0, leaders = uroom->playerList->players; i < MAX_UNION_ROOM_LEADERS; i++)
    {
        if (leaders[i].groupScheduledAnim == UNION_ROOM_SPAWN_IN)
            SpawnGroupLeaderAndMembers(i, &leaders[i].rfu.data);
        else if (leaders[i].groupScheduledAnim == UNION_ROOM_SPAWN_OUT)
            DespawnGroupLeaderAndMembers(i, &leaders[i].rfu.data);
    }
}

void ScheduleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom)
{
    sUnionObjRefreshTimer = 300;
}

void HandleUnionRoomPlayerRefresh(struct WirelessLink_URoom *uroom)
{
    if (++sUnionObjRefreshTimer > 300)
        UpdateUnionRoomPlayerSprites(uroom);
}

void SetUnionRoomObjectFacingDirection(s32 memberId, s32 leaderId, u8 newDirection)
{
    // should be UR_PLAYER_SPRITE_ID(leaderId, memberId) - UR_SPRITE_START_ID,
    // but the order is swapped in the base ROM
    TurnVirtualObject(MAX_RFU_PLAYERS * leaderId - UR_SPRITE_START_ID + memberId, newDirection);
}

void UpdateUnionRoomMemberFacing(u32 memberId, u32 leaderId, struct RfuPlayerList *list)
{
    return SetUnionRoomObjectFacingDirection(memberId, leaderId, GetNewFacingDirectionForUnionRoomPlayer(memberId, leaderId, &list->players[leaderId].rfu.data));
}

bool32 TryInteractWithUnionRoomMember(struct RfuPlayerList *list, s16 *memberIdPtr, s16 *leaderIdPtr, u8 *spriteIds)
{
    s16 x, y;
    s32 i, memberId;
    struct RfuPlayer *leaders;
    if (!is_walking_or_running())
        return FALSE;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    for (i = 0, leaders = list->players; i < MAX_UNION_ROOM_LEADERS; i++)
    {
        for (memberId = 0; memberId < MAX_RFU_PLAYERS; memberId++)
        {
            s32 id = UR_PLAYER_SPRITE_ID(i, memberId);

            // Is the player in front of a group member position?
            if (x != sUnionRoomPlayerCoords[i][0] + sUnionRoomGroupOffsets[memberId][0] + 7)
                continue;
            if (y != sUnionRoomPlayerCoords[i][1] + sUnionRoomGroupOffsets[memberId][1] + 7)
                continue;

            // Has a group member spawned at this position?
            if (IsVirtualObjectInvisible(id - UR_SPRITE_START_ID))
                continue;
            if (IsVirtualObjectAnimating(id - UR_SPRITE_START_ID))
                continue;
            if (leaders[i].groupScheduledAnim != UNION_ROOM_SPAWN_IN)
                continue;

            // Interaction attempt successful, face player
            SetUnionRoomObjectFacingDirection(memberId, i, sOppositeFacingDirection[GetPlayerFacingDirection()]);
            *memberIdPtr = memberId;
            *leaderIdPtr = i;
            return TRUE;
        }
    }
    return FALSE;
}
