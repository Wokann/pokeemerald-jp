#define NUM_FORCED_MOVEMENTS 18
#define NUM_ACRO_BIKE_COLLISIONS 5

#ifndef FIELD_PLAYER_AVATAR_TAIL
#include "global.h"
#include "bike.h"
#include "event_data.h"
#include "field_effect_helpers.h"
#include "field_effect.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "overworld.h"
#include "random.h"
#include "rotating_gate.h"
#include "constants/field_effects.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/songs.h"

void DoPlayerAvatarTransition(void);

// The separately compiled tail retains the existing JP linker names.
void HideShowWarpArrow(struct ObjectEvent *objectEvent) asm("sub_0808BBE4");
void MovePlayerNotOnBike(u8 direction, u16 heldKeys);

// Shared C tables are emitted with the separately compiled JP tail.
extern bool8 (*const sForcedMovementTestFuncs[18])(u8 metatileBehavior);
extern bool8 (*const sForcedMovementFuncs[NUM_FORCED_MOVEMENTS + 1])(void);

// Global bindings preserve JP call sites across the main and tail objects.
u8 ObjectEventCB2_NoMovement2(void);
bool8 TryInterruptObjectEventSpecialAnim(struct ObjectEvent *playerObjEvent, u8 direction);
void npc_clear_strange_bits(struct ObjectEvent *objEvent);
void MovePlayerAvatarUsingKeypadInput(u8 direction, u16 newKeys, u16 heldKeys);
void PlayerAllowForcedMovementIfMovingSameDirection(void);
bool8 TryDoMetatileBehaviorForcedMovement(void);
u8 GetForcedMovementByMetatileBehavior(void);
bool8 CanStopSurfing(s16 x, s16 y, u8 direction);
bool8 ShouldJumpLedge(s16 x, s16 y, u8 direction);
void CheckAcroBikeCollision(s16 x, s16 y, u8 metatileBehavior, u8 *collision);
u8 CheckForObjectEventStaticCollision(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction, u8 metatileBehavior);
bool8 TryPushBoulder(s16 x, s16 y, u8 direction) asm("sub_0808AB9C");
void MovePlayerNotOnBike(u8 direction, u16 heldKeys);
u8 CheckMovementInputNotOnBike(u8 direction);
void PlayerNotOnBikeNotMoving(u8 direction, u16 heldKeys);
void PlayerNotOnBikeTurningInPlace(u8 direction, u16 heldKeys);
void PlayerNotOnBikeMoving(u8 direction, u16 heldKeys);
u8 CheckForPlayerAvatarCollision(u8 direction);
u8 CheckForPlayerAvatarStaticCollision(u8 direction);
u8 CheckForObjectEventCollision(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction, u8 metatileBehavior);
bool8 IsPlayerCollidingWithFarawayIslandMew(u8 direction);
bool8 PlayerIsAnimActive(void);
bool8 PlayerCheckIfAnimFinishedOrInactive(void);
bool8 PlayerAnimIsMultiFrameStationary(void);
bool8 PlayerAnimIsMultiFrameStationaryAndStateNotTurning(void);
void UpdatePlayerAvatarTransitionState(void);

void MovementType_Player(struct Sprite *sprite)
{
    UpdateObjectEventCurrentMovement(&gObjectEvents[sprite->data[0]], sprite, (bool8 (*)(struct ObjectEvent *, struct Sprite *))ObjectEventCB2_NoMovement2);
}

u8 ObjectEventCB2_NoMovement2(void)
{
    return 0;
}

void PlayerStep(u8 direction, u16 newKeys, u16 heldKeys)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    HideShowWarpArrow(playerObjEvent);
    if (gPlayerAvatar.preventStep == FALSE)
    {
        Bike_TryAcroBikeHistoryUpdate(newKeys, heldKeys);
        if (TryInterruptObjectEventSpecialAnim(playerObjEvent, direction) == 0)
        {
            npc_clear_strange_bits(playerObjEvent);
            DoPlayerAvatarTransition();
            if (TryDoMetatileBehaviorForcedMovement() == 0)
            {
                MovePlayerAvatarUsingKeypadInput(direction, newKeys, heldKeys);
                PlayerAllowForcedMovementIfMovingSameDirection();
            }
        }
    }
}

bool8 TryInterruptObjectEventSpecialAnim(struct ObjectEvent *playerObjEvent, u8 direction)
{
    if (ObjectEventIsMovementOverridden(playerObjEvent)
     && !ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        u8 heldMovementActionId = ObjectEventGetHeldMovementActionId(playerObjEvent);
        if (heldMovementActionId > MOVEMENT_ACTION_WALK_FAST_RIGHT && heldMovementActionId < MOVEMENT_ACTION_WALK_IN_PLACE_NORMAL_DOWN)
        {
            if (direction == DIR_NONE)
            {
                return TRUE;
            }

            if (playerObjEvent->movementDirection != direction)
            {
                ObjectEventClearHeldMovement(playerObjEvent);
                return FALSE;
            }

            if (CheckForPlayerAvatarStaticCollision(direction) == COLLISION_NONE)
            {
                ObjectEventClearHeldMovement(playerObjEvent);
                return FALSE;
            }
        }

        return TRUE;
    }

    return FALSE;
}

void npc_clear_strange_bits(struct ObjectEvent *objEvent)
{
    objEvent->inanimate = FALSE;
    objEvent->disableAnim = FALSE;
    objEvent->facingDirectionLocked = FALSE;
    gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_DASH;
}

void MovePlayerAvatarUsingKeypadInput(u8 direction, u16 newKeys, u16 heldKeys)
{
    if (gPlayerAvatar.flags & (PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
        MovePlayerOnBike(direction, newKeys, heldKeys);
    else
        MovePlayerNotOnBike(direction, heldKeys);
}

void PlayerAllowForcedMovementIfMovingSameDirection(void)
{
    if (gPlayerAvatar.runningState == MOVING)
        gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_CONTROLLABLE;
}

bool8 TryDoMetatileBehaviorForcedMovement(void)
{
    return sForcedMovementFuncs[GetForcedMovementByMetatileBehavior()]();
}

u8 GetForcedMovementByMetatileBehavior(void)
{
    u8 i;

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_CONTROLLABLE))
    {
        u8 metatileBehavior = gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior;

        for (i = 0; i < NUM_FORCED_MOVEMENTS; i++)
        {
            if (sForcedMovementTestFuncs[i](metatileBehavior))
                return i + 1;
        }
    }
    return 0;
}

// JP: forced-movement handlers (batch 2). JP names for the mat jump/spin
// handlers (0xBB/0xBC) and JP movement helpers PlayerGoSpeed1/2.
u8 CheckForPlayerAvatarCollision(u8 direction);
void PlayerJumpLedge(u8 direction);
void PlayerGoSpeed1(u8 direction);
void PlayerGoSpeed2(u8 direction);
void PlayerRideWaterCurrent(u8 direction);
void DoPlayerMatJump(void);
void DoPlayerMatSpin(void);

bool8 ForcedMovement_None(void)
{
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_FORCED_MOVE)
    {
        struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

        playerObjEvent->facingDirectionLocked = FALSE;
        playerObjEvent->enableAnim = TRUE;
        SetObjectEventDirection(playerObjEvent, playerObjEvent->facingDirection);
        gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_FORCED_MOVE;
    }
    return FALSE;
}

bool8 DoForcedMovement(u8 direction, void (*moveFunc)(u8))
{
    struct PlayerAvatar *playerAvatar = &gPlayerAvatar;
    u8 collision = CheckForPlayerAvatarCollision(direction);

    playerAvatar->flags |= PLAYER_AVATAR_FLAG_FORCED_MOVE;
    if (collision)
    {
        ForcedMovement_None();
        if (collision < COLLISION_STOP_SURFING)
        {
            return FALSE;
        }
        else
        {
            if (collision == COLLISION_LEDGE_JUMP)
                PlayerJumpLedge(direction);
            playerAvatar->flags |= PLAYER_AVATAR_FLAG_FORCED_MOVE;
            playerAvatar->runningState = MOVING;
            return TRUE;
        }
    }
    else
    {
        playerAvatar->runningState = MOVING;
        moveFunc(direction);
        return TRUE;
    }
}

bool8 DoForcedMovementInCurrentDirection(void (*moveFunc)(u8))
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    playerObjEvent->disableAnim = TRUE;
    return DoForcedMovement(playerObjEvent->movementDirection, moveFunc);
}

bool8 ForcedMovement_Slip(void)
{
    return DoForcedMovementInCurrentDirection(PlayerGoSpeed2);
}

bool8 ForcedMovement_WalkSouth(void)
{
    return DoForcedMovement(DIR_SOUTH, PlayerGoSpeed1);
}

bool8 ForcedMovement_WalkNorth(void)
{
    return DoForcedMovement(DIR_NORTH, PlayerGoSpeed1);
}

bool8 ForcedMovement_WalkWest(void)
{
    return DoForcedMovement(DIR_WEST, PlayerGoSpeed1);
}

bool8 ForcedMovement_WalkEast(void)
{
    return DoForcedMovement(DIR_EAST, PlayerGoSpeed1);
}

bool8 ForcedMovement_PushedSouthByCurrent(void)
{
    return DoForcedMovement(DIR_SOUTH, PlayerRideWaterCurrent);
}

bool8 ForcedMovement_PushedNorthByCurrent(void)
{
    return DoForcedMovement(DIR_NORTH, PlayerRideWaterCurrent);
}

bool8 ForcedMovement_PushedWestByCurrent(void)
{
    return DoForcedMovement(DIR_WEST, PlayerRideWaterCurrent);
}

bool8 ForcedMovement_PushedEastByCurrent(void)
{
    return DoForcedMovement(DIR_EAST, PlayerRideWaterCurrent);
}

bool8 ForcedMovement_Slide(u8 direction, void (*moveFunc)(u8))
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    playerObjEvent->disableAnim = TRUE;
    playerObjEvent->facingDirectionLocked = TRUE;
    return DoForcedMovement(direction, moveFunc);
}

bool8 ForcedMovement_SlideSouth(void)
{
    return ForcedMovement_Slide(DIR_SOUTH, PlayerGoSpeed2);
}

bool8 ForcedMovement_SlideNorth(void)
{
    return ForcedMovement_Slide(DIR_NORTH, PlayerGoSpeed2);
}

bool8 ForcedMovement_SlideWest(void)
{
    return ForcedMovement_Slide(DIR_WEST, PlayerGoSpeed2);
}

bool8 ForcedMovement_SlideEast(void)
{
    return ForcedMovement_Slide(DIR_EAST, PlayerGoSpeed2);
}

bool8 ForcedMovement_MatJump(void) // JP: mat jump
{
    DoPlayerMatJump();
    return TRUE;
}

bool8 ForcedMovement_MatSpin(void) // JP: mat spin
{
    DoPlayerMatSpin();
    return TRUE;
}

bool8 ForcedMovement_MuddySlope(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (playerObjEvent->movementDirection != DIR_NORTH || GetPlayerSpeed() < PLAYER_SPEED_FASTEST)
    {
        Bike_UpdateBikeCounterSpeed(0);
        playerObjEvent->facingDirectionLocked = TRUE;
        return DoForcedMovement(DIR_SOUTH, PlayerGoSpeed2);
    }
    return FALSE;
}

// JP: movement input + collision handling (batch 3)
void PlayerFaceDirection(u8 direction);
void PlayerTurnInPlace(u8 direction);
void PlayerRun(u8 direction);
u8 GetPlayerMovementDirection(void);
u8 GetPlayerFacingDirection(void);
void PlayerNotOnBikeCollide(u8 direction);
void PlayerNotOnBikeCollideWithFarawayIslandMew(u8 direction);
void StartStrengthAnim(u8 objectEventId, u8 direction);
void CreateStopSurfingTask(u8 direction);
u8 GetEventObjectIdByXY(s16 x, s16 y);

// JP ROM tables: sPlayerNotOnBikeFuncs @ 0x0846F8B0,
// sAcroBikeTrickMetatiles @ 0x0846F8BC, sAcroBikeTrickCollisionTypes @ 0x0846F8D0
extern void (*const sPlayerNotOnBikeFuncs[3])(u8 direction, u16 heldKeys);
extern bool8 (*const sAcroBikeTrickMetatiles[5])(u8 metatileBehavior);
extern const u8 sAcroBikeTrickCollisionTypes[5];

void MovePlayerNotOnBike(u8 direction, u16 heldKeys)
{
    sPlayerNotOnBikeFuncs[CheckMovementInputNotOnBike(direction)](direction, heldKeys);
}

u8 CheckMovementInputNotOnBike(u8 direction)
{
    if (direction == DIR_NONE)
        return gPlayerAvatar.runningState = NOT_MOVING;
    else if (direction != GetPlayerMovementDirection() && gPlayerAvatar.runningState != MOVING)
        return gPlayerAvatar.runningState = TURN_DIRECTION;
    else
        return gPlayerAvatar.runningState = MOVING;
}

void PlayerNotOnBikeNotMoving(u8 direction, u16 heldKeys)
{
    PlayerFaceDirection(GetPlayerFacingDirection());
}

void PlayerNotOnBikeTurningInPlace(u8 direction, u16 heldKeys)
{
    PlayerTurnInPlace(direction);
}

void PlayerNotOnBikeMoving(u8 direction, u16 heldKeys)
{
    u8 collision = CheckForPlayerAvatarCollision(direction);

    if (collision)
    {
        if (collision == COLLISION_LEDGE_JUMP)
        {
            PlayerJumpLedge(direction);
            return;
        }
        else if (collision == COLLISION_OBJECT_EVENT && IsPlayerCollidingWithFarawayIslandMew(direction))
        {
            PlayerNotOnBikeCollideWithFarawayIslandMew(direction);
            return;
        }
        else
        {
            // JP matches the US non-BUGFIX build: collisions 5-8 skip the normal
            // collision effect (STOP_SURFING, LEDGE_JUMP, PUSHED_BOULDER, ROTATING_GATE)
            if (collision < COLLISION_STOP_SURFING || collision > COLLISION_ROTATING_GATE)
            {
                PlayerNotOnBikeCollide(direction);
            }
            return;
        }
    }

    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
    {
        // same speed as running
        PlayerGoSpeed2(direction); // JP: PlayerWalkFast
        return;
    }

    if (!(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_UNDERWATER) && (heldKeys & B_BUTTON) && FlagGet(FLAG_SYS_B_DASH)
     && IsRunningDisallowed(gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior) == 0)
    {
        PlayerRun(direction);
        gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_DASH;
        return;
    }
    else
    {
        PlayerGoSpeed1(direction); // JP: PlayerWalkNormal
    }
}

u8 CheckForPlayerAvatarCollision(u8 direction)
{
    s16 x, y;
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    x = playerObjEvent->currentCoords.x;
    y = playerObjEvent->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return CheckForObjectEventCollision(playerObjEvent, x, y, direction, (u8)MapGridGetMetatileBehaviorAt(x, y));
}

u8 CheckForPlayerAvatarStaticCollision(u8 direction)
{
    s16 x, y;
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    x = playerObjEvent->currentCoords.x;
    y = playerObjEvent->currentCoords.y;
    MoveCoords(direction, &x, &y);
    return CheckForObjectEventStaticCollision(playerObjEvent, x, y, direction, (u8)MapGridGetMetatileBehaviorAt(x, y));
}

u8 CheckForObjectEventCollision(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction, u8 metatileBehavior)
{
    u8 collision = GetCollisionAtCoords(objectEvent, x, y, direction);
    if (collision == COLLISION_ELEVATION_MISMATCH && CanStopSurfing(x, y, direction))
        return COLLISION_STOP_SURFING;

    if (ShouldJumpLedge(x, y, direction))
    {
        IncrementGameStat(GAME_STAT_JUMPED_DOWN_LEDGES);
        return COLLISION_LEDGE_JUMP;
    }
    if (collision == COLLISION_OBJECT_EVENT && TryPushBoulder(x, y, direction))
        return COLLISION_PUSHED_BOULDER;

    if (collision == COLLISION_NONE)
    {
        if (CheckForRotatingGatePuzzleCollision(direction, x, y))
            return COLLISION_ROTATING_GATE;
        CheckAcroBikeCollision(x, y, metatileBehavior, &collision);
    }
    return collision;
}

u8 CheckForObjectEventStaticCollision(struct ObjectEvent *objectEvent, s16 x, s16 y, u8 direction, u8 metatileBehavior)
{
    u8 collision = GetCollisionAtCoords(objectEvent, x, y, direction);

    if (collision == COLLISION_NONE)
    {
        if (CheckForRotatingGatePuzzleCollisionWithoutAnimation(direction, x, y))
            return COLLISION_ROTATING_GATE;
        CheckAcroBikeCollision(x, y, metatileBehavior, &collision);
    }
    return collision;
}

bool8 CanStopSurfing(s16 x, s16 y, u8 direction)
{
    if ((gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
     && MapGridGetElevationAt(x, y) == ELEVATION_DEFAULT
     && GetObjectEventIdByPosition(x, y, ELEVATION_DEFAULT) == OBJECT_EVENTS_COUNT)
    {
        CreateStopSurfingTask(direction);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

bool8 ShouldJumpLedge(s16 x, s16 y, u8 direction)
{
    if (GetLedgeJumpDirection(x, y, direction) != DIR_NONE)
        return TRUE;
    else
        return FALSE;
}

void CheckAcroBikeCollision(s16 x, s16 y, u8 metatileBehavior, u8 *collision)
{
    u8 i;

    for (i = 0; i < NUM_ACRO_BIKE_COLLISIONS; i++)
    {
        if (sAcroBikeTrickMetatiles[i](metatileBehavior))
        {
            *collision = sAcroBikeTrickCollisionTypes[i];
            return;
        }
    }
}

bool8 IsPlayerCollidingWithFarawayIslandMew(u8 direction)
{
    u8 mewObjectId;
    struct ObjectEvent *object;
    s16 playerX;
    s16 playerY;
    s16 mewPrevX;

    object = &gObjectEvents[gPlayerAvatar.objectEventId];
    playerX = object->currentCoords.x;
    playerY = object->currentCoords.y;

    MoveCoords(direction, &playerX, &playerY);
    mewObjectId = GetObjectEventIdByLocalIdAndMap(LOCALID_FARAWAY_ISLAND_MEW, MAP_NUM(MAP_FARAWAY_ISLAND_INTERIOR), MAP_GROUP(MAP_FARAWAY_ISLAND_INTERIOR));
    if (mewObjectId == OBJECT_EVENTS_COUNT)
        return FALSE;

    object = &gObjectEvents[mewObjectId];
    mewPrevX = object->previousCoords.x;

    if (mewPrevX == playerX)
    {
        if (object->previousCoords.y != playerY
            || object->currentCoords.x != mewPrevX
            || object->currentCoords.y != object->previousCoords.y)
        {
            if (object->previousCoords.x == playerX &&
                object->previousCoords.y == playerY)
                return TRUE;
        }
    }
    return FALSE;
}

// JP: avatar state transitions (batch 4)
u8 GetPlayerAvatarGraphicsIdByStateId(u8 state);
void SetPlayerAvatarStateMask(u8 flags);
void SetSurfBlob_BobState(u8 spriteId, u8 state);
u8 StartUnderwaterSurfBlobBobbing(u8 spriteId);

// JP ROM table: sPlayerAvatarTransitionFuncs @ 0x0846F8D8
extern void (*const sPlayerAvatarTransitionFuncs[8])(struct ObjectEvent *objEvent); // JP table has 8 entries

void SetPlayerAvatarTransitionFlags(u16 transitionFlags)
{
    gPlayerAvatar.transitionFlags |= transitionFlags;
    DoPlayerAvatarTransition();
}

void DoPlayerAvatarTransition(void)
{
    u8 i;
    u8 flags = gPlayerAvatar.transitionFlags;

    if (flags != 0)
    {
        for (i = 0; i < ARRAY_COUNT(sPlayerAvatarTransitionFuncs); i++, flags >>= 1)
        {
            if (flags & 1)
                sPlayerAvatarTransitionFuncs[i](&gObjectEvents[gPlayerAvatar.objectEventId]);
        }
        gPlayerAvatar.transitionFlags = 0;
    }
}

void PlayerAvatarTransition_Dummy(struct ObjectEvent *objEvent)
{

}

void PlayerAvatarTransition_Normal(struct ObjectEvent *objEvent)
{
    ObjectEventSetGraphicsId(objEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
    ObjectEventTurn(objEvent, objEvent->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_ON_FOOT);
}

void PlayerAvatarTransition_MachBike(struct ObjectEvent *objEvent)
{
    ObjectEventSetGraphicsId(objEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_MACH_BIKE));
    ObjectEventTurn(objEvent, objEvent->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_MACH_BIKE);
    BikeClearState(0, 0);
}

void PlayerAvatarTransition_AcroBike(struct ObjectEvent *objEvent)
{
    ObjectEventSetGraphicsId(objEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_ACRO_BIKE));
    ObjectEventTurn(objEvent, objEvent->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_ACRO_BIKE);
    BikeClearState(0, 0);
    Bike_HandleBumpySlopeJump();
}

void PlayerAvatarTransition_Surfing(struct ObjectEvent *objEvent)
{
    u8 spriteId;

    ObjectEventSetGraphicsId(objEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_SURFING));
    ObjectEventTurn(objEvent, objEvent->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_SURFING);
    gFieldEffectArguments[0] = objEvent->currentCoords.x;
    gFieldEffectArguments[1] = objEvent->currentCoords.y;
    gFieldEffectArguments[2] = gPlayerAvatar.objectEventId;
    spriteId = FieldEffectStart(FLDEFF_SURF_BLOB);
    objEvent->fieldEffectSpriteId = spriteId;
    SetSurfBlob_BobState(spriteId, BOB_PLAYER_AND_MON);
}

void PlayerAvatarTransition_Underwater(struct ObjectEvent *objEvent)
{
    ObjectEventSetGraphicsId(objEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_UNDERWATER));
    ObjectEventTurn(objEvent, objEvent->movementDirection);
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_UNDERWATER);
    objEvent->fieldEffectSpriteId = StartUnderwaterSurfBlobBobbing(objEvent->spriteId);
}

void PlayerAvatarTransition_ReturnToField(struct ObjectEvent *objEvent)
{
    gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_CONTROLLABLE;
}

void UpdatePlayerAvatarTransitionState(void) // JP: sub_0808AEDC
{
    gPlayerAvatar.tileTransitionState = T_NOT_MOVING;
    if (PlayerCheckIfAnimFinishedOrInactive()) // JP: 0x0808AFA0 (IsMovementOverridden)
    {
        if (!PlayerIsAnimActive())
        {
            if (!PlayerAnimIsMultiFrameStationary())
                gPlayerAvatar.tileTransitionState = T_TILE_TRANSITION;
        }
        else
        {
            if (!PlayerAnimIsMultiFrameStationaryAndStateNotTurning())
                gPlayerAvatar.tileTransitionState = T_TILE_CENTER;
        }
    }
}

bool8 PlayerAnimIsMultiFrameStationary(void) // JP: player_is_anim_in_certain_ranges
{
    u8 movementActionId = gObjectEvents[gPlayerAvatar.objectEventId].movementActionId;

    if (movementActionId <= MOVEMENT_ACTION_FACE_RIGHT
     || (movementActionId >= MOVEMENT_ACTION_DELAY_1 && movementActionId <= MOVEMENT_ACTION_DELAY_16)
     || (movementActionId >= MOVEMENT_ACTION_WALK_IN_PLACE_SLOW_DOWN && movementActionId <= MOVEMENT_ACTION_WALK_IN_PLACE_FASTER_RIGHT)
     || (movementActionId >= MOVEMENT_ACTION_ACRO_WHEELIE_FACE_DOWN && movementActionId <= MOVEMENT_ACTION_ACRO_END_WHEELIE_FACE_RIGHT)
     || (movementActionId >= MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_DOWN && movementActionId <= MOVEMENT_ACTION_ACRO_WHEELIE_IN_PLACE_RIGHT))
        return TRUE;
    else
        return FALSE;
}

bool8 PlayerAnimIsMultiFrameStationaryAndStateNotTurning(void) // JP: sub_0808AF7C
{
    if (PlayerAnimIsMultiFrameStationary() && gPlayerAvatar.runningState != TURN_DIRECTION)
        return TRUE;
    else
        return FALSE;
}

bool8 PlayerCheckIfAnimFinishedOrInactive(void)
{
    return ObjectEventIsMovementOverridden(&gObjectEvents[gPlayerAvatar.objectEventId]); // JP: swapped
}

bool8 PlayerIsAnimActive(void)
{
    return ObjectEventCheckHeldMovementStatus(&gObjectEvents[gPlayerAvatar.objectEventId]); // JP: swapped
}

// JP: movement animation helpers (batch 5). JP names for the speed helpers;
// US names aliased in ld_script_jp.txt.
u8 sub_08092CF8(u32 direction); // JP: GetWalkNormalMovementAction
u8 sub_08092D24(u32 direction); // JP: GetWalkFastMovementAction
u8 sub_08092D50(u32 direction); // JP: GetRideWaterCurrentMovementAction
u8 sub_08092D7C(u32 direction); // JP: GetWalkFasterMovementAction
u8 sub_08092DD4(u32 direction); // JP: GetPlayerRunMovementAction
u8 sub_08092F08(u32 direction); // JP: GetWalkInPlaceNormalMovementAction
u8 sub_08092EDC(u32 direction); // JP: GetWalkInPlaceSlowMovementAction
u8 GetFaceDirectionMovementAction(u32 direction); // JP: GetFaceDirectionMovementAction
u8 sub_08092F34(u32 direction); // JP: GetWalkInPlaceFastMovementAction
u8 sub_08092E00(u32 direction); // JP: GetJump2MovementAction
bool8 player_should_look_direction_be_enforced_upon_movement(void);
void ObjectEventForceSetHeldMovement(struct ObjectEvent *objectEvent, u8 movementActionId);
void PlayCollisionSoundIfNotFacingWarp(u8 direction);
void PlayerSetCopyableMovement(u8 movement);

void PlayerSetCopyableMovement(u8 movement)
{
    gObjectEvents[gPlayerAvatar.objectEventId].playerCopyableMovement = movement;
}

u8 PlayerGetCopyableMovement(void)
{
    return gObjectEvents[gPlayerAvatar.objectEventId].playerCopyableMovement;
}

void PlayerForceSetHeldMovement(u8 movementActionId) // JP: sub_0808B020
{
    ObjectEventForceSetHeldMovement(&gObjectEvents[gPlayerAvatar.objectEventId], movementActionId);
}

void PlayerSetAnimId(u8 movementActionId, u8 copyableMovement)
{
    if (!PlayerCheckIfAnimFinishedOrInactive())
    {
        PlayerSetCopyableMovement(copyableMovement);
        ObjectEventSetHeldMovement(&gObjectEvents[gPlayerAvatar.objectEventId], movementActionId);
    }
}

void PlayerGoSpeed1(u8 direction) // JP: US PlayerWalkNormal
{
    PlayerSetAnimId(sub_08092CF8(direction), COPY_MOVE_WALK);
}

void PlayerGoSpeed2(u8 direction) // JP: US PlayerWalkFast
{
    PlayerSetAnimId(sub_08092D24(direction), COPY_MOVE_WALK);
}

void PlayerRideWaterCurrent(u8 direction)
{
    PlayerSetAnimId(sub_08092D50(direction), COPY_MOVE_WALK);
}

void PlayerGoSpeed4(u8 direction) // JP: US PlayerWalkFaster
{
    PlayerSetAnimId(sub_08092D7C(direction), COPY_MOVE_WALK);
}

void PlayerRun(u8 direction)
{
    PlayerSetAnimId(sub_08092DD4(direction), COPY_MOVE_WALK);
}

void PlayerOnBikeCollide(u8 direction)
{
    PlayCollisionSoundIfNotFacingWarp(direction);
    PlayerSetAnimId(sub_08092F08(direction), COPY_MOVE_WALK);
}

void PlayerOnBikeCollideWithFarawayIslandMew(u8 direction)
{
    PlayerSetAnimId(sub_08092F08(direction), COPY_MOVE_WALK);
}

void PlayerNotOnBikeCollide(u8 direction)
{
    PlayCollisionSoundIfNotFacingWarp(direction);
    PlayerSetAnimId(sub_08092EDC(direction), COPY_MOVE_WALK);
}

void PlayerNotOnBikeCollideWithFarawayIslandMew(u8 direction)
{
    PlayerSetAnimId(sub_08092EDC(direction), COPY_MOVE_WALK);
}

void PlayerFaceDirection(u8 direction)
{
    PlayerSetAnimId(GetFaceDirectionMovementAction(direction), COPY_MOVE_FACE);
}

void PlayerTurnInPlace(u8 direction)
{
    PlayerSetAnimId(sub_08092F34(direction), COPY_MOVE_FACE);
}

void PlayerJumpLedge(u8 direction)
{
    PlaySE(SE_LEDGE);
    PlayerSetAnimId(sub_08092E00(direction), COPY_MOVE_JUMP2);
}

void sub_0808B1C8(void) // JP: US PlayerFreeze
{
    if (gPlayerAvatar.tileTransitionState == T_TILE_CENTER || gPlayerAvatar.tileTransitionState == T_NOT_MOVING)
    {
        if (player_should_look_direction_be_enforced_upon_movement())
            PlayerForceSetHeldMovement(GetFaceDirectionMovementAction(gObjectEvents[gPlayerAvatar.objectEventId].facingDirection));
    }
}

// JP: acro bike wheelie helpers + coord getters (batch 6)
u8 sub_08092FB8(u32 direction); // JP: GetAcroWheelieFaceDirectionMovementAction
u8 sub_08092FE4(u32 direction); // JP: GetAcroPopWheelieFaceDirectionMovementAction
u8 sub_0809303C(u32 direction); // JP: GetAcroWheelieHopFaceDirectionMovementAction
u8 sub_08093094(u32 direction); // JP: GetAcroWheelieJumpDirectionMovementAction
u8 sub_08092E58(u32 direction); // JP: GetJumpInPlaceTurnAroundMovementAction
u8 sub_080930C0(u32 direction); // JP: GetAcroWheelieInPlaceDirectionMovementAction
u8 sub_080930EC(u32 direction); // JP: GetAcroPopWheelieMoveDirectionMovementAction
u8 sub_08093118(u32 direction); // JP: GetAcroWheelieMoveDirectionMovementAction
u8 sub_08093144(u32 direction); // JP: GetAcroEndWheelieMoveDirectionMovementAction
u8 EventObjectExecSingleMovementAction(u32 direction);
u8 GetAcroEndWheelieFaceDirectionMovementAction(u32 direction);

// JP ROM table: sArrowWarpMetatileBehaviorChecks @ 0x0846F8F8
extern bool8 (*const sArrowWarpMetatileBehaviorChecks[4])(u8 metatileBehavior);

void PlayerIdleWheelie(u8 direction)
{
    PlayerSetAnimId(sub_08092FB8(direction), COPY_MOVE_FACE);
}

void PlayerStartWheelie(u8 direction)
{
    PlayerSetAnimId(sub_08092FE4(direction), COPY_MOVE_FACE);
}

void PlayerEndWheelie(u8 direction)
{
    PlayerSetAnimId(EventObjectExecSingleMovementAction(direction), COPY_MOVE_FACE); // JP: uses this instead of GetAcroEndWheelieFaceDirectionMovementAction
}

void PlayerStandingHoppingWheelie(u8 direction)
{
    PlaySE(SE_BIKE_HOP);
    PlayerSetAnimId(sub_0809303C(direction), COPY_MOVE_FACE);
}

void PlayerMovingHoppingWheelie(u8 direction)
{
    PlaySE(SE_BIKE_HOP);
    PlayerSetAnimId(GetAcroEndWheelieFaceDirectionMovementAction(direction), COPY_MOVE_WALK);
}

void PlayerLedgeHoppingWheelie(u8 direction)
{
    PlaySE(SE_BIKE_HOP);
    PlayerSetAnimId(sub_08093094(direction), COPY_MOVE_JUMP2);
}

void PlayerAcroTurnJump(u8 direction)
{
    PlaySE(SE_BIKE_HOP);
    PlayerSetAnimId(sub_08092E58(direction), COPY_MOVE_FACE);
}

void sub_0808B2E4(u8 direction) // JP: US PlayerWheelieInPlace
{
    PlaySE(SE_WALL_HIT);
    PlayerSetAnimId(sub_080930C0(direction), COPY_MOVE_WALK);
}

void sub_0808B308(u8 direction) // JP: US PlayerPopWheelieWhileMoving
{
    PlayerSetAnimId(sub_080930EC(direction), COPY_MOVE_WALK);
}

void sub_0808B320(u8 direction) // JP: US PlayerWheelieMove
{
    PlayerSetAnimId(sub_08093118(direction), COPY_MOVE_WALK);
}

void sub_0808B338(u8 direction) // JP: US PlayerEndWheelieWhileMoving
{
    PlayerSetAnimId(sub_08093144(direction), COPY_MOVE_WALK);
}

void PlayCollisionSoundIfNotFacingWarp(u8 direction)
{
    s16 x, y;
    u8 metatileBehavior = gObjectEvents[gPlayerAvatar.objectEventId].currentMetatileBehavior;

    if (!sArrowWarpMetatileBehaviorChecks[direction - 1](metatileBehavior))
    {
        if (direction == DIR_NORTH)
        {
            PlayerGetDestCoords(&x, &y);
            MoveCoords(DIR_NORTH, &x, &y);
            if ((u8)MetatileBehavior_IsWarpDoor((u8)MapGridGetMetatileBehaviorAt(x, y)))
                return; // JP: skips the shared collision sound
        }
        PlaySE(SE_WALL_HIT);
    }
}

void GetXYCoordsOneStepInFrontOfPlayer(s16 *x, s16 *y)
{
    *x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    *y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
    MoveCoords(GetPlayerFacingDirection(), x, y);
}

void PlayerGetDestCoords(s16 *x, s16 *y)
{
    *x = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x;
    *y = gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y;
}
#else
#include "global.h"
#include "main.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "window.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "party_menu.h"
#include "random.h"
#include "rotating_gate.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "task.h"
#include "tv.h"
#include "wild_encounter.h"
#include "constants/abilities.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_effects.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/trainer_types.h"

// The tail is compiled separately to preserve the JP contiguous text layout.
// Shared state and tables remain at their existing JP RAM/ROM owners.
extern u8 sSpinStartFacingDir asm("gUnknown_2036FEC");
extern const u8 sRivalAvatarGfxIds[8][2];
extern const u8 sPlayerAvatarGfxIds[8][2];
extern const u8 sFRLGAvatarGfxIds[2];
extern const u8 sRSAvatarGfxIds[2];
extern const u8 sPlayerAvatarGfxToStateFlag[2][5][2];
extern bool8 (*const sArrowWarpMetatileBehaviorChecks2[4])(u8);
extern bool8 (*const sPushBoulderFuncs[3])(struct Task *, struct ObjectEvent *, struct ObjectEvent *);
extern u8 (*const sPlayerAvatarSecretBaseMatJump[1])(struct Task *, struct ObjectEvent *);
extern bool8 (*const sPlayerAvatarSecretBaseMatSpin[4])(struct Task *, struct ObjectEvent *);
extern const u8 sSecretBaseMatSpinDirections[4];
extern const u8 sSecretBaseMatSpinActions[5];
extern bool8 (*const sFishingStateFuncs[16])(struct Task *);
extern const s16 sFishingMinRounds1[3], sFishingMinRounds2[3];
extern const s16 sFishingReelTimeouts[3], sFishingMoreDotsChance[3][2];
extern const u8 sSpinDirections[5];
bool8 ForcedMovement_None(void);
void DoPlayerAvatarTransition(void);
void npc_clear_strange_bits(struct ObjectEvent *);
void MoveEventObjectToMapCoords(struct ObjectEvent *, s16, s16);
void SetEventObjectDirection(struct ObjectEvent *, u8);
u8 GetEventObjectIdByXY(s16, s16);
u8 SpawnSpecialEventObject(struct ObjectEventTemplate *);
void EventObjectTurn(struct ObjectEvent *, u8);
// JP animation lookup call targets differ from the current US helper labels.
u8 GetFishingDirectionAnimNumJP(u32) asm("GetWalkInPlaceNormalMovementAction");
u8 GetAcroWheelieDirectionAnimNumJP(u32) asm("GetSlideMovementAction");
u8 GetFaceDirectionAnimNumJP(u32) asm("GetJumpInPlaceMovementAction");
u8 GetFishingBiteDirectionAnimNumJP(u32) asm("GetWalkNormalMovementAction");
u8 GetFishingNoCatchDirectionAnimNumJP(u32) asm("GetWalkInPlaceSlowMovementAction");
u8 GetWalkInPlaceNormalMovementActionJP(u32) asm("sub_08092F08");
u8 GetWalkSlowMovementActionJP(u32) asm("sub_08092CCC");
u8 GetJumpInPlaceMovementActionJP(u32) asm("sub_08092E2C");
u8 GetJumpSpecialMovementActionJP(u32) asm("sub_08092EB0");
void CameraObjectFreezeJP(void) asm("CameraObjectReset2");
void LoadMessageBoxAndFrameGfxJP(u8, bool8) asm("sub_08197650");
void RecordFishingAttemptForTVJP(bool8) asm("sub_080EE470");

#define tState             data[0]
#define tBoulderObjId      data[1]
#define tDirection         data[2]
#define tStep              data[0]
#define tFrameCounter      data[1]
#define tNumDots           data[2]
#define tDotsRequired      data[3]
#define tRoundsPlayed      data[12]
#define tMinRoundsRequired data[13]
#define tPlayerGfxId       data[14]
#define tFishingRod        data[15]
#define FISHING_START_ROUND 3
#define FISHING_GOT_BITE    6
#define FISHING_ON_HOOK     9
#define FISHING_NO_BITE     11
#define FISHING_GOT_AWAY    12
#define FISHING_SHOW_RESULT 13
#define tSpinDelayTimer    data[1]
#define tSpeed             data[2]
#define tCurY              data[3]
#define tDestY             data[4]
#define tStartDir          data[5]
#define tPriority          data[6]
#define tSubpriority       data[7]
#define tGroundTimer       data[8]

bool8 TryPushBoulder(s16 x, s16 y, u8 direction) asm("sub_0808AB9C");
u8 player_get_pos_including_state_based_drift(s16 *x, s16 *y);
u8 GetPlayerFacingDirection(void);
u8 GetPlayerMovementDirection(void);
u8 PlayerGetElevation(void);
void MovePlayerToMapCoords(s16 x, s16 y) asm("sub_0808B5F4");
u8 TestPlayerAvatarFlags(u8 flag);
u8 GetPlayerAvatarFlags(void) asm("sub_0808B634");
u8 GetPlayerAvatarSpriteId(void);
void StopPlayerAvatar(void) asm("sub_0808B658");
u8 GetRivalAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender);
u8 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender);
u8 GetFRLGAvatarGraphicsIdByGender(u8 gender);
u8 GetRSAvatarGraphicsIdByGender(u8 gender);
u8 GetPlayerAvatarGraphicsIdByStateId(u8 state);
u8 unref_GetRivalAvatarGenderByGraphicsId(u8 gfxId);
u8 GetPlayerAvatarGenderByGraphicsId(u8 gfxId);
bool8 PartyHasMonWithSurf(void);
bool8 IsPlayerSurfingNorth(void);
bool8 IsPlayerFacingSurfableFishableWater(void);
void ClearPlayerAvatarInfo(void);
void SetPlayerAvatarStateMask(u8 flags);
u8 GetPlayerAvatarStateTransitionByGraphicsId(u8 graphicsId, u8 gender);
u8 GetPlayerAvatarGraphicsIdByCurrentState(void);
void SetPlayerAvatarExtraStateTransition(u8 graphicsId, u8 transitionFlag);
void InitPlayerAvatar(s16 x, s16 y, u8 direction, u8 gender);
void SetPlayerInvisibility(bool8 invisible);
void SetPlayerAvatarFieldMove(void);
void SetPlayerAvatarFishing(u8 direction) asm("sub_0808BAC0");
void PlayerUseAcroBikeOnBumpySlope(u8 direction) asm("sub_0808BB18");
void SetPlayerAvatarWatering(u8 direction) asm("sub_0808BB8C");
void HideShowWarpArrow(struct ObjectEvent *objectEvent) asm("sub_0808BBE4");
void StartStrengthAnim(u8 objectEventId, u8 direction);
void Task_PushBoulder(u8 taskId);
bool8 PushBoulder_Start(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder);
bool8 PushBoulder_Move(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder);
bool8 PushBoulder_End(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder);
void DoPlayerMatJump(void);
void DoPlayerAvatarSecretBaseMatJump(u8 taskId);
u8 PlayerAvatar_DoSecretBaseMatJump(struct Task *task, struct ObjectEvent *objectEvent);
void DoPlayerMatSpin(void);
void PlayerAvatar_DoSecretBaseMatSpin(u8 taskId);
bool8 PlayerAvatar_SecretBaseMatSpinStep0(struct Task *task, struct ObjectEvent *objectEvent);
bool8 PlayerAvatar_SecretBaseMatSpinStep1(struct Task *task, struct ObjectEvent *objectEvent);
bool8 PlayerAvatar_SecretBaseMatSpinStep2(struct Task *task, struct ObjectEvent *objectEvent);
bool8 PlayerAvatar_SecretBaseMatSpinStep3(struct Task *task, struct ObjectEvent *objectEvent);
void CreateStopSurfingTask(u8 direction) asm("sub_0808C0B4");
void Task_StopSurfingInit(u8 taskId) asm("taskFF_0805D1D4");
void Task_WaitStopSurfing(u8 taskId) asm("sub_0808C178");
void StartFishing(u8 rod);
void Task_Fishing(u8 taskId);
bool8 Fishing_Init(struct Task *task);
bool8 Fishing_GetRodOut(struct Task *task);
bool8 Fishing_WaitBeforeDots(struct Task *task);
bool8 Fishing_InitDots(struct Task *task);
bool8 Fishing_ShowDots(struct Task *task);
bool8 Fishing_CheckForBite(struct Task *task);
bool8 Fishing_GotBite(struct Task *task);
bool8 Fishing_WaitForA(struct Task *task);
bool8 Fishing_CheckMoreDots(struct Task *task);
bool8 Fishing_MonOnHook(struct Task *task);
bool8 Fishing_StartEncounter(struct Task *task);
bool8 Fishing_NotEvenNibble(struct Task *task);
bool8 Fishing_GotAway(struct Task *task);
bool8 Fishing_NoMon(struct Task *task);
bool8 Fishing_PutRodAway(struct Task *task);
bool8 Fishing_EndNoMon(struct Task *task);
void AlignFishingAnimationFrames(void);
void SetSpinStartFacingDir(u8 direction) asm("sub_0808C9E4");
u8 GetSpinStartFacingDir(void) asm("sub_0808C9F0");
void Task_DoPlayerSpinExit(u8 taskId);
void DoPlayerSpinEntrance(void);
bool32 IsPlayerSpinEntranceActive(void);
void DoPlayerSpinExit(void);
bool32 IsPlayerSpinExitActive(void);
void Task_DoPlayerSpinEntrance(u8 taskId);
u8 TrySpinPlayerForWarp(struct ObjectEvent *object, s16 *delayTimer) asm("sub_0808CCFC");

__attribute__((section(".text.sub_0808AB9C"))) bool8 TryPushBoulder(s16 x, s16 y, u8 direction)
{
    if (FlagGet(FLAG_SYS_USE_STRENGTH))
    {
        u8 objectEventId = GetEventObjectIdByXY(x, y);

        if (objectEventId != OBJECT_EVENTS_COUNT && gObjectEvents[objectEventId].graphicsId == OBJ_EVENT_GFX_PUSHABLE_BOULDER)
        {
            x = gObjectEvents[objectEventId].currentCoords.x;
            y = gObjectEvents[objectEventId].currentCoords.y;
            MoveCoords(direction, &x, &y);
            if (GetCollisionAtCoords(&gObjectEvents[objectEventId], x, y, direction) == COLLISION_NONE
             && MetatileBehavior_IsNonAnimDoor(MapGridGetMetatileBehaviorAt(x, y)) == FALSE)
            {
                StartStrengthAnim(objectEventId, direction);
                return TRUE;
            }
        }
    }
    return FALSE;
}

__attribute__((section(".text.player_get_pos_including_state_based_drift"))) u8 player_get_pos_including_state_based_drift(s16 *x, s16 *y)
{
    struct ObjectEvent *object = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (object->heldMovementActive && !object->heldMovementFinished && !gSprites[object->spriteId].data[2])
    {
        *x = object->currentCoords.x;
        *y = object->currentCoords.y;

        switch (object->movementActionId)
        {
        case MOVEMENT_ACTION_WALK_NORMAL_DOWN:
        case MOVEMENT_ACTION_PLAYER_RUN_DOWN:
            (*y)++;
            return TRUE;
        case MOVEMENT_ACTION_WALK_NORMAL_UP:
        case MOVEMENT_ACTION_PLAYER_RUN_UP:
            (*y)--;
            return TRUE;
        case MOVEMENT_ACTION_WALK_NORMAL_LEFT:
        case MOVEMENT_ACTION_PLAYER_RUN_LEFT:
            (*x)--;
            return TRUE;
        case MOVEMENT_ACTION_WALK_NORMAL_RIGHT:
        case MOVEMENT_ACTION_PLAYER_RUN_RIGHT:
            (*x)++;
            return TRUE;
        }
    }

    *x = -1;
    *y = -1;
    return FALSE;
}

u8 GetPlayerFacingDirection(void)
{
    return gObjectEvents[gPlayerAvatar.objectEventId].facingDirection;
}

u8 GetPlayerMovementDirection(void)
{
    return gObjectEvents[gPlayerAvatar.objectEventId].movementDirection;
}

u8 PlayerGetElevation(void)
{
    return gObjectEvents[gPlayerAvatar.objectEventId].previousElevation;
}

void MovePlayerToMapCoords(s16 x, s16 y)
{
    MoveEventObjectToMapCoords(&gObjectEvents[gPlayerAvatar.objectEventId], x, y);
}

u8 TestPlayerAvatarFlags(u8 flag)
{
    return gPlayerAvatar.flags & flag;
}

u8 GetPlayerAvatarFlags(void)
{
    return gPlayerAvatar.flags;
}

u8 GetPlayerAvatarSpriteId(void)
{
    return gPlayerAvatar.spriteId;
}

void CancelPlayerForcedMovement(void)
{
    ForcedMovement_None();
}

void StopPlayerAvatar(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    npc_clear_strange_bits(playerObjEvent);
    SetEventObjectDirection(playerObjEvent, playerObjEvent->facingDirection);
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
    {
        Bike_HandleBumpySlopeJump();
        Bike_UpdateBikeCounterSpeed(0);
    }
}

u8 GetRivalAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender)
{
    return sRivalAvatarGfxIds[state][gender];
}

u8 GetPlayerAvatarGraphicsIdByStateIdAndGender(u8 state, u8 gender)
{
    return sPlayerAvatarGfxIds[state][gender];
}

u8 GetFRLGAvatarGraphicsIdByGender(u8 gender)
{
    return sFRLGAvatarGfxIds[gender];
}

u8 GetRSAvatarGraphicsIdByGender(u8 gender)
{
    return sRSAvatarGfxIds[gender];
}

u8 GetPlayerAvatarGraphicsIdByStateId(u8 state)
{
    return GetPlayerAvatarGraphicsIdByStateIdAndGender(state, gPlayerAvatar.gender);
}

u8 unref_GetRivalAvatarGenderByGraphicsId(u8 gfxId)
{
    switch (gfxId)
    {
    case OBJ_EVENT_GFX_RIVAL_MAY_NORMAL:
    case OBJ_EVENT_GFX_RIVAL_MAY_MACH_BIKE:
    case OBJ_EVENT_GFX_RIVAL_MAY_ACRO_BIKE:
    case OBJ_EVENT_GFX_RIVAL_MAY_SURFING:
    case OBJ_EVENT_GFX_RIVAL_MAY_FIELD_MOVE:
    case OBJ_EVENT_GFX_MAY_UNDERWATER:
    case OBJ_EVENT_GFX_MAY_FISHING:
    case OBJ_EVENT_GFX_MAY_WATERING:
        return FEMALE;
    default:
        return MALE;
    }
}

u8 GetPlayerAvatarGenderByGraphicsId(u8 gfxId)
{
    switch (gfxId)
    {
    case OBJ_EVENT_GFX_MAY_NORMAL:
    case OBJ_EVENT_GFX_MAY_MACH_BIKE:
    case OBJ_EVENT_GFX_MAY_ACRO_BIKE:
    case OBJ_EVENT_GFX_MAY_SURFING:
    case OBJ_EVENT_GFX_MAY_FIELD_MOVE:
    case OBJ_EVENT_GFX_MAY_UNDERWATER:
    case OBJ_EVENT_GFX_MAY_FISHING:
    case OBJ_EVENT_GFX_MAY_WATERING:
        return FEMALE;
    default:
        return MALE;
    }
}

bool8 PartyHasMonWithSurf(void)
{
    u8 i;

    if (!TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
    {
        for (i = 0; i < PARTY_SIZE; i++)
        {
            if (GetMonData3(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_NONE)
                break;
            if (MonKnowsMove(&gPlayerParty[i], MOVE_SURF))
                return TRUE;
        }
    }
    return FALSE;
}

bool8 IsPlayerSurfingNorth(void)
{
    if (GetPlayerMovementDirection() == DIR_NORTH && TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        return TRUE;
    else
        return FALSE;
}

bool8 IsPlayerFacingSurfableFishableWater(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;

    MoveCoords(playerObjEvent->facingDirection, &x, &y);
    if (GetCollisionAtCoords(playerObjEvent, x, y, playerObjEvent->facingDirection) == COLLISION_ELEVATION_MISMATCH
     && PlayerGetElevation() == ELEVATION_DEFAULT
     && MetatileBehavior_IsSurfableFishableWater(MapGridGetMetatileBehaviorAt(x, y)))
        return TRUE;
    else
        return FALSE;
}

void ClearPlayerAvatarInfo(void)
{
    memset(&gPlayerAvatar, 0, sizeof(struct PlayerAvatar));
}

void SetPlayerAvatarStateMask(u8 flags)
{
    gPlayerAvatar.flags &= (PLAYER_AVATAR_FLAG_DASH | PLAYER_AVATAR_FLAG_FORCED_MOVE | PLAYER_AVATAR_FLAG_CONTROLLABLE);
    gPlayerAvatar.flags |= flags;
}

u8 GetPlayerAvatarStateTransitionByGraphicsId(u8 graphicsId, u8 gender)
{
    u8 i;

    for (i = 0; i < ARRAY_COUNT(sPlayerAvatarGfxToStateFlag[0]); i++)
    {
        if (sPlayerAvatarGfxToStateFlag[gender][i][0] == graphicsId)
            return sPlayerAvatarGfxToStateFlag[gender][i][1];
    }
    return PLAYER_AVATAR_FLAG_ON_FOOT;
}

u8 GetPlayerAvatarGraphicsIdByCurrentState(void)
{
    u8 i;
    u8 flags = gPlayerAvatar.flags;

    for (i = 0; i < ARRAY_COUNT(sPlayerAvatarGfxToStateFlag[0]); i++)
    {
        if (sPlayerAvatarGfxToStateFlag[gPlayerAvatar.gender][i][1] & flags)
            return sPlayerAvatarGfxToStateFlag[gPlayerAvatar.gender][i][0];
    }
    return 0;
}

void SetPlayerAvatarExtraStateTransition(u8 graphicsId, u8 transitionFlag)
{
    u8 stateFlag = GetPlayerAvatarStateTransitionByGraphicsId(graphicsId, gPlayerAvatar.gender);

    gPlayerAvatar.transitionFlags |= stateFlag | transitionFlag;
    DoPlayerAvatarTransition();
}

void InitPlayerAvatar(s16 x, s16 y, u8 direction, u8 gender)
{
    struct ObjectEventTemplate playerObjEventTemplate;
    u8 objectEventId;
    struct ObjectEvent *objectEvent;

    playerObjEventTemplate.localId = LOCALID_PLAYER;
    playerObjEventTemplate.graphicsId = GetPlayerAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, gender);
    playerObjEventTemplate.x = x - MAP_OFFSET;
    playerObjEventTemplate.y = y - MAP_OFFSET;
    playerObjEventTemplate.elevation = ELEVATION_TRANSITION;
    playerObjEventTemplate.movementType = MOVEMENT_TYPE_PLAYER;
    playerObjEventTemplate.movementRangeX = 0;
    playerObjEventTemplate.movementRangeY = 0;
    playerObjEventTemplate.trainerType = TRAINER_TYPE_NONE;
    playerObjEventTemplate.trainerRange_berryTreeId = 0;
    playerObjEventTemplate.script = NULL;
    playerObjEventTemplate.flagId = 0;
    objectEventId = SpawnSpecialEventObject(&playerObjEventTemplate);
    objectEvent = &gObjectEvents[objectEventId];
    objectEvent->isPlayer = TRUE;
    objectEvent->warpArrowSpriteId = CreateWarpArrowSprite();
    EventObjectTurn(objectEvent, direction);
    ClearPlayerAvatarInfo();
    gPlayerAvatar.runningState = NOT_MOVING;
    gPlayerAvatar.tileTransitionState = T_NOT_MOVING;
    gPlayerAvatar.objectEventId = objectEventId;
    gPlayerAvatar.spriteId = objectEvent->spriteId;
    gPlayerAvatar.gender = gender;
    SetPlayerAvatarStateMask(PLAYER_AVATAR_FLAG_CONTROLLABLE | PLAYER_AVATAR_FLAG_ON_FOOT);
}

void SetPlayerInvisibility(bool8 invisible)
{
    gObjectEvents[gPlayerAvatar.objectEventId].invisible = invisible;
    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        gSprites[gObjectEvents[gPlayerAvatar.objectEventId].fieldEffectSpriteId].invisible = invisible;
}

void SetPlayerAvatarFieldMove(void)
{
    ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_FIELD_MOVE));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], ANIM_FIELD_MOVE);
}

void SetPlayerAvatarFishing(u8 direction)
{
    ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_FISHING));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingDirectionAnimNumJP(direction));
}

void PlayerUseAcroBikeOnBumpySlope(u8 direction)
{
    ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_ACRO_BIKE));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetAcroWheelieDirectionAnimNumJP(direction));
    SeekSpriteAnim(&gSprites[gPlayerAvatar.spriteId], 1);
}

void SetPlayerAvatarWatering(u8 direction)
{
    ObjectEventSetGraphicsId(&gObjectEvents[gPlayerAvatar.objectEventId], GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_WATERING));
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFaceDirectionAnimNumJP(direction));
}

void HideShowWarpArrow(struct ObjectEvent *objectEvent)
{
    s16 x;
    s16 y;
    u8 direction;
    u8 metatileBehavior = objectEvent->currentMetatileBehavior;

    for (x = 0, direction = DIR_SOUTH; x < 4; x++, direction++)
    {
        if (sArrowWarpMetatileBehaviorChecks2[x](metatileBehavior) && direction == objectEvent->movementDirection)
        {
            // Show warp arrow if applicable
            x = objectEvent->currentCoords.x;
            y = objectEvent->currentCoords.y;
            MoveCoords(direction, &x, &y);
            ShowWarpArrowSprite(objectEvent->warpArrowSpriteId, direction, x, y);
            return;
        }
    }
    SetSpriteInvisible(objectEvent->warpArrowSpriteId);
}

void StartStrengthAnim(u8 objectEventId, u8 direction)
{
    TaskFunc taskFunc = Task_PushBoulder;
    u8 taskId = CreateTask(taskFunc, 0xFF);

    gTasks[taskId].tBoulderObjId = objectEventId;
    gTasks[taskId].tDirection = direction;
    taskFunc(taskId);
}

void Task_PushBoulder(u8 taskId)
{
    while (sPushBoulderFuncs[gTasks[taskId].tState](&gTasks[taskId],
                                                     &gObjectEvents[gPlayerAvatar.objectEventId],
                                                     &gObjectEvents[gTasks[taskId].tBoulderObjId]))
        ;
}

bool8 PushBoulder_Start(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder)
{
    LockPlayerFieldControls();
    gPlayerAvatar.preventStep = TRUE;
    task->tState++;
    return FALSE;
}

bool8 PushBoulder_Move(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder)
{
    if (ObjectEventIsHeldMovementActive(player))
        ObjectEventClearHeldMovementIfFinished(player);

    if (ObjectEventIsHeldMovementActive(boulder))
        ObjectEventClearHeldMovementIfFinished(boulder);

    if (!ObjectEventIsMovementOverridden(player)
     && !ObjectEventIsMovementOverridden(boulder))
    {
        ObjectEventClearHeldMovementIfFinished(player);
        ObjectEventClearHeldMovementIfFinished(boulder);
        ObjectEventSetHeldMovement(player, GetWalkInPlaceNormalMovementActionJP((u8)task->tDirection));
        ObjectEventSetHeldMovement(boulder, GetWalkSlowMovementActionJP((u8)task->tDirection));
        gFieldEffectArguments[0] = boulder->currentCoords.x;
        gFieldEffectArguments[1] = boulder->currentCoords.y;
        gFieldEffectArguments[2] = boulder->previousElevation;
        gFieldEffectArguments[3] = gSprites[boulder->spriteId].oam.priority;
        FieldEffectStart(FLDEFF_DUST);
        PlaySE(SE_M_STRENGTH);
        task->tState++;
    }
    return FALSE;
}

bool8 PushBoulder_End(struct Task *task, struct ObjectEvent *player, struct ObjectEvent *boulder)
{
    if (ObjectEventCheckHeldMovementStatus(player)
     && ObjectEventCheckHeldMovementStatus(boulder))
    {
        ObjectEventClearHeldMovementIfFinished(player);
        ObjectEventClearHeldMovementIfFinished(boulder);
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
        DestroyTask(FindTaskIdByFunc(Task_PushBoulder));
    }
    return FALSE;
}

void DoPlayerMatJump(void)
{
    TaskFunc taskFunc = DoPlayerAvatarSecretBaseMatJump;
    taskFunc(CreateTask(taskFunc, 0xFF));
}

void DoPlayerAvatarSecretBaseMatJump(u8 taskId)
{
    while (sPlayerAvatarSecretBaseMatJump[gTasks[taskId].data[0]](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId]))
        ;
}

u8 PlayerAvatar_DoSecretBaseMatJump(struct Task *task, struct ObjectEvent *objectEvent)
{
    gPlayerAvatar.preventStep = TRUE;
    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        PlaySE(SE_LEDGE);
        ObjectEventSetHeldMovement(objectEvent, GetJumpInPlaceMovementActionJP(objectEvent->facingDirection));
        task->data[1]++;
        if (task->data[1] > 1)
        {
            gPlayerAvatar.preventStep = FALSE;
            gPlayerAvatar.transitionFlags |= PLAYER_AVATAR_FLAG_CONTROLLABLE;
            DestroyTask(FindTaskIdByFunc(DoPlayerAvatarSecretBaseMatJump));
        }
    }
    return FALSE;
}

void DoPlayerMatSpin(void)
{
    TaskFunc taskFunc = PlayerAvatar_DoSecretBaseMatSpin;
    u8 taskId = CreateTask(taskFunc, 0xFF);

    taskFunc(taskId);
}

void PlayerAvatar_DoSecretBaseMatSpin(u8 taskId)
{
    while (sPlayerAvatarSecretBaseMatSpin[gTasks[taskId].data[0]](&gTasks[taskId], &gObjectEvents[gPlayerAvatar.objectEventId]))
        ;
}

bool8 PlayerAvatar_SecretBaseMatSpinStep0(struct Task *task, struct ObjectEvent *objectEvent)
{
    task->data[0]++;
    task->data[1] = objectEvent->movementDirection;
    gPlayerAvatar.preventStep = TRUE;
    LockPlayerFieldControls();
    PlaySE(SE_WARP_IN);
    return TRUE;
}

bool8 PlayerAvatar_SecretBaseMatSpinStep1(struct Task *task, struct ObjectEvent *objectEvent)
{
    u8 directions[4];

    memcpy(directions, sSecretBaseMatSpinDirections, sizeof(directions));

    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        u8 direction;

        ObjectEventSetHeldMovement(objectEvent, GetFaceDirectionMovementAction(direction = directions[objectEvent->movementDirection - 1]));
        if (direction == (u8)task->data[1])
            task->data[2]++;
        task->data[0]++;
        if (task->data[2] > 3 && direction == GetOppositeDirection(task->data[1]))
            task->data[0]++;
    }
    return FALSE;
}

bool8 PlayerAvatar_SecretBaseMatSpinStep2(struct Task *task, struct ObjectEvent *objectEvent)
{
    u8 actions[5];

    memcpy(actions, sSecretBaseMatSpinActions, sizeof(actions));

    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        ObjectEventSetHeldMovement(objectEvent, actions[task->data[2]]);
        task->data[0] = 1;
    }
    return FALSE;
}

bool8 PlayerAvatar_SecretBaseMatSpinStep3(struct Task *task, struct ObjectEvent *objectEvent)
{
    if (ObjectEventClearHeldMovementIfFinished(objectEvent))
    {
        ObjectEventSetHeldMovement(objectEvent, GetWalkSlowMovementActionJP(GetOppositeDirection(task->data[1])));
        UnlockPlayerFieldControls();
        gPlayerAvatar.preventStep = FALSE;
        DestroyTask(FindTaskIdByFunc(PlayerAvatar_DoSecretBaseMatSpin));
    }
    return FALSE;
}

void CreateStopSurfingTask(u8 direction)
{
    TaskFunc taskFunc;
    u8 taskId;

    LockPlayerFieldControls();
    Overworld_ClearSavedMusic();
    Overworld_ChangeMusicToDefault();
    gPlayerAvatar.flags &= ~PLAYER_AVATAR_FLAG_SURFING;
    gPlayerAvatar.flags |= PLAYER_AVATAR_FLAG_ON_FOOT;
    gPlayerAvatar.preventStep = TRUE;
    taskFunc = Task_StopSurfingInit;
    taskId = CreateTask(taskFunc, 0xFF);
    gTasks[taskId].data[0] = direction;
    taskFunc(taskId);
}

void Task_StopSurfingInit(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventIsMovementOverridden(playerObjEvent))
    {
        if (!ObjectEventClearHeldMovementIfFinished(playerObjEvent))
            return;
    }
    SetSurfBlob_BobState(playerObjEvent->fieldEffectSpriteId, BOB_JUST_MON);
    ObjectEventSetHeldMovement(playerObjEvent, GetJumpSpecialMovementActionJP((u8)gTasks[taskId].data[0]));
    gTasks[taskId].func = Task_WaitStopSurfing;
}

void Task_WaitStopSurfing(u8 taskId)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

    if (ObjectEventClearHeldMovementIfFinished(playerObjEvent))
    {
        ObjectEventSetGraphicsId(playerObjEvent, GetPlayerAvatarGraphicsIdByStateId(PLAYER_AVATAR_STATE_NORMAL));
        ObjectEventSetHeldMovement(playerObjEvent, GetFaceDirectionMovementAction(playerObjEvent->facingDirection));
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
        DestroySprite(&gSprites[playerObjEvent->fieldEffectSpriteId]);
#ifdef BUGFIX
        // If this is not defined but the player steps into grass from surfing, they will appear over the grass instead of in the grass.
        playerObjEvent->triggerGroundEffectsOnMove = TRUE;
#endif
        DestroyTask(taskId);
    }
}

void StartFishing(u8 rod)
{
    TaskFunc taskFunc = Task_Fishing;
    u8 taskId = CreateTask(taskFunc, 0xFF);

    gTasks[taskId].tFishingRod = rod;
    taskFunc(taskId);
}

void Task_Fishing(u8 taskId)
{
    while (sFishingStateFuncs[gTasks[taskId].tStep](&gTasks[taskId]))
        ;
}

bool8 Fishing_Init(struct Task *task)
{
    LockPlayerFieldControls();
    gPlayerAvatar.preventStep = TRUE;
    task->tStep++;
    return FALSE;
}

bool8 Fishing_GetRodOut(struct Task *task)
{
    struct ObjectEvent *playerObjEvent;
    s16 minRounds1[3];
    s16 minRounds2[3];

    memcpy(minRounds1, sFishingMinRounds1, sizeof(minRounds1));
    memcpy(minRounds2, sFishingMinRounds2, sizeof(minRounds2));

    task->tRoundsPlayed = 0;
    task->tMinRoundsRequired = minRounds1[task->tFishingRod] + (Random() % minRounds2[task->tFishingRod]);
    task->tPlayerGfxId = gObjectEvents[gPlayerAvatar.objectEventId].graphicsId;
    playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    ObjectEventClearHeldMovementIfActive(playerObjEvent);
    playerObjEvent->enableAnim = TRUE;
    SetPlayerAvatarFishing(playerObjEvent->facingDirection);
    task->tStep++;
    return FALSE;
}

bool8 Fishing_WaitBeforeDots(struct Task *task)
{
    AlignFishingAnimationFrames();

    // Wait one second
    task->tFrameCounter++;
    if (task->tFrameCounter >= 60)
        task->tStep++;
    return FALSE;
}

bool8 Fishing_InitDots(struct Task *task)
{
    u32 randVal;

    LoadMessageBoxAndFrameGfxJP(0, TRUE);
    task->tStep++;
    task->tFrameCounter = 0;
    task->tNumDots = 0;
    randVal = Random();
    randVal %= 10;
    task->tDotsRequired = randVal + 1;
    if (task->tRoundsPlayed == 0)
        task->tDotsRequired = randVal + 4;
    if (task->tDotsRequired >= 10)
        task->tDotsRequired = 10;
    return TRUE;
}

bool8 Fishing_ShowDots(struct Task *task)
{
    const u8 dot[] = _("·");

    AlignFishingAnimationFrames();
    task->tFrameCounter++;
    if (JOY_NEW(A_BUTTON))
    {
        task->tStep = FISHING_NO_BITE;
        if (task->tRoundsPlayed != 0)
            task->tStep = FISHING_GOT_AWAY;
        return TRUE;
    }
    else
    {
        if (task->tFrameCounter >= 20)
        {
            task->tFrameCounter = 0;
            if (task->tNumDots >= task->tDotsRequired)
            {
                task->tStep++;
                if (task->tRoundsPlayed != 0)
                    task->tStep++;
                task->tRoundsPlayed++;
            }
            else
            {
                AddTextPrinterParameterized(0, FONT_NORMAL, dot, task->tNumDots * 8, 2, 0, NULL);
                task->tNumDots++;
            }
        }
        return FALSE;
    }
}

bool8 Fishing_CheckForBite(struct Task *task)
{
    bool8 bite;

    AlignFishingAnimationFrames();
    task->tStep++;
    bite = FALSE;

    if (!DoesCurrentMapHaveFishingMons())
    {
        task->tStep = FISHING_NO_BITE;
    }
    else
    {
        if (!GetMonData3(&gPlayerParty[0], MON_DATA_SANITY_IS_EGG))
        {
            u8 ability = GetMonAbility(&gPlayerParty[0]);
            if (ability == ABILITY_SUCTION_CUPS || ability  == ABILITY_STICKY_HOLD)
            {
                if (Random() % 100 > 14)
                    bite = TRUE;
            }
        }

        if (!bite)
        {
            if (Random() & 1)
                task->tStep = FISHING_NO_BITE;
            else
                bite = TRUE;
        }

        if (bite == TRUE)
            StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingBiteDirectionAnimNumJP(GetPlayerFacingDirection()));
    }
    return TRUE;
}

bool8 Fishing_GotBite(struct Task *task)
{
    u8 text[12];

    memcpy(text, gText_OhABite, sizeof(text));
    AlignFishingAnimationFrames();
    AddTextPrinterParameterized(0, FONT_NORMAL, text, 0, 18, 0, NULL);
    task->tStep++;
    task->tFrameCounter = 0;
    return FALSE;
}

bool8 Fishing_WaitForA(struct Task *task)
{
    s16 reelTimeouts[3];

    memcpy(reelTimeouts, sFishingReelTimeouts, sizeof(reelTimeouts));

    AlignFishingAnimationFrames();
    task->tFrameCounter++;
    if (task->tFrameCounter >= reelTimeouts[task->tFishingRod])
        task->tStep = FISHING_GOT_AWAY;
    else if (JOY_NEW(A_BUTTON))
        task->tStep++;
    return FALSE;
}

bool8 Fishing_CheckMoreDots(struct Task *task)
{
    s16 moreDotsChance[3][2];

    memcpy(moreDotsChance, sFishingMoreDotsChance, sizeof(moreDotsChance));

    AlignFishingAnimationFrames();
    task->tStep++;
    if (task->tRoundsPlayed < task->tMinRoundsRequired)
    {
        task->tStep = FISHING_START_ROUND;
    }
    else if (task->tRoundsPlayed < 2)
    {
        // probability of having to play another round
        s16 probability = Random() % 100;

        if (moreDotsChance[task->tFishingRod][task->tRoundsPlayed] > probability)
            task->tStep = FISHING_START_ROUND;
    }
    return FALSE;
}

bool8 Fishing_MonOnHook(struct Task *task)
{
    AlignFishingAnimationFrames();
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized2(0, FONT_NORMAL, gText_PokemonOnHook, 1, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    task->tStep++;
    task->tFrameCounter = 0;
    return FALSE;
}

bool8 Fishing_StartEncounter(struct Task *task)
{
    if (task->tFrameCounter == 0)
        AlignFishingAnimationFrames();

    RunTextPrinters();

    if (task->tFrameCounter == 0)
    {
        if (!IsTextPrinterActive(0))
        {
            struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

            ObjectEventSetGraphicsId(playerObjEvent, task->tPlayerGfxId);
            EventObjectTurn(playerObjEvent, playerObjEvent->movementDirection);
            if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
                SetSurfBlob_PlayerOffset(gObjectEvents[gPlayerAvatar.objectEventId].fieldEffectSpriteId, FALSE, 0);
            gSprites[gPlayerAvatar.spriteId].x2 = 0;
            gSprites[gPlayerAvatar.spriteId].y2 = 0;
            ClearDialogWindowAndFrame(0, TRUE);
            task->tFrameCounter++;
            return FALSE;
        }
    }

    if (task->tFrameCounter != 0)
    {
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
        FishingWildEncounter(task->tFishingRod);
        RecordFishingAttemptForTVJP(TRUE);
        DestroyTask(FindTaskIdByFunc(Task_Fishing));
    }
    return FALSE;
}

bool8 Fishing_NotEvenNibble(struct Task *task)
{
    AlignFishingAnimationFrames();
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingNoCatchDirectionAnimNumJP(GetPlayerFacingDirection()));
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized2(0, FONT_NORMAL, gText_NotEvenANibble, 1, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    task->tStep = FISHING_SHOW_RESULT;
    return TRUE;
}

bool8 Fishing_GotAway(struct Task *task)
{
    AlignFishingAnimationFrames();
    StartSpriteAnim(&gSprites[gPlayerAvatar.spriteId], GetFishingNoCatchDirectionAnimNumJP(GetPlayerFacingDirection()));
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    AddTextPrinterParameterized2(0, FONT_NORMAL, gText_ItGotAway, 1, 0, TEXT_COLOR_DARK_GRAY, TEXT_COLOR_WHITE, TEXT_COLOR_LIGHT_GRAY);
    task->tStep++;
    return TRUE;
}

bool8 Fishing_NoMon(struct Task *task)
{
    AlignFishingAnimationFrames();
    task->tStep++;
    return FALSE;
}

bool8 Fishing_PutRodAway(struct Task *task)
{
    AlignFishingAnimationFrames();
    if (gSprites[gPlayerAvatar.spriteId].animEnded)
    {
        struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];

        ObjectEventSetGraphicsId(playerObjEvent, task->tPlayerGfxId);
        EventObjectTurn(playerObjEvent, playerObjEvent->movementDirection);
        if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
            SetSurfBlob_PlayerOffset(gObjectEvents[gPlayerAvatar.objectEventId].fieldEffectSpriteId, FALSE, 0);
        gSprites[gPlayerAvatar.spriteId].x2 = 0;
        gSprites[gPlayerAvatar.spriteId].y2 = 0;
        task->tStep++;
    }
    return FALSE;
}

bool8 Fishing_EndNoMon(struct Task *task)
{
    RunTextPrinters();
    if (!IsTextPrinterActive(0))
    {
        gPlayerAvatar.preventStep = FALSE;
        UnlockPlayerFieldControls();
        UnfreezeObjectEvents();
        ClearDialogWindowAndFrame(0, TRUE);
        RecordFishingAttemptForTVJP(FALSE);
        DestroyTask(FindTaskIdByFunc(Task_Fishing));
    }
    return FALSE;
}

void AlignFishingAnimationFrames(void)
{
    struct Sprite *playerSprite = &gSprites[gPlayerAvatar.spriteId];
    u8 animCmdIndex;
    u8 animType;

    AnimateSprite(playerSprite);
    playerSprite->x2 = 0;
    playerSprite->y2 = 0;
    animCmdIndex = playerSprite->animCmdIndex;
    if (playerSprite->anims[playerSprite->animNum][animCmdIndex].type == -1)
    {
        animCmdIndex--;
    }
    else
    {
        playerSprite->animDelayCounter++;
        if (playerSprite->anims[playerSprite->animNum][animCmdIndex].type == -1)
            animCmdIndex--;
    }
    animType = playerSprite->anims[playerSprite->animNum][animCmdIndex].type;
    if (animType == 1 || animType == 2 || animType == 3)
    {
        playerSprite->x2 = 8;
        if (GetPlayerFacingDirection() == 3)
            playerSprite->x2 = -8;
    }
    if (animType == 5)
        playerSprite->y2 = -8;
    if (animType == 10 || animType == 11)
        playerSprite->y2 = 8;
    if (gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_SURFING)
        SetSurfBlob_PlayerOffset(gObjectEvents[gPlayerAvatar.objectEventId].fieldEffectSpriteId, TRUE, playerSprite->y2);
}

void SetSpinStartFacingDir(u8 direction)
{
    sSpinStartFacingDir = direction;
}

u8 GetSpinStartFacingDir(void)
{
    if (sSpinStartFacingDir == DIR_NONE)
        return DIR_SOUTH;

    return sSpinStartFacingDir;
}

void Task_DoPlayerSpinExit(u8 taskId)
{
    struct ObjectEvent *object = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[object->spriteId];
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
        case 0: // Init
            if (!ObjectEventClearHeldMovementIfFinished(object))
                return;

            SetSpinStartFacingDir(object->facingDirection);
            tSpinDelayTimer = 0;
            tSpeed = 1;
            tCurY = (u16)(sprite->y + sprite->y2) << 4;
            sprite->y2 = 0;
            CameraObjectFreezeJP();
            object->fixedPriority = TRUE;
            sprite->oam.priority = 0;
            sprite->subpriority = 0;
            sprite->subspriteMode = SUBSPRITES_OFF;
            tState++;
        case 1: // Spin while rising
            TrySpinPlayerForWarp(object, &tSpinDelayTimer);

            // Rise and accelerate
            tCurY -= tSpeed;
            tSpeed += 3;
            sprite->y = tCurY >> 4;

            // Check if offscreen
            if (sprite->y + (s16)gTotalCameraPixelOffsetY < -32)
                tState++;
            break;
        case 2:
            DestroyTask(taskId);
            break;
    }
}

void DoPlayerSpinEntrance(void)
{
    TaskFunc taskFunc = Task_DoPlayerSpinEntrance;
    taskFunc(CreateTask(taskFunc, 0));
}

bool32 IsPlayerSpinEntranceActive(void)
{
    return FuncIsActiveTask(Task_DoPlayerSpinEntrance);
}

void DoPlayerSpinExit(void)
{
    TaskFunc taskFunc = Task_DoPlayerSpinExit;
    taskFunc(CreateTask(taskFunc, 0));
}

bool32 IsPlayerSpinExitActive(void)
{
    return FuncIsActiveTask(Task_DoPlayerSpinExit);
}

void Task_DoPlayerSpinEntrance(u8 taskId)
{
    struct ObjectEvent *object = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct Sprite *sprite = &gSprites[object->spriteId];
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
        case 0:
            // Because the spin start facing direction is never set for this
            // warp type, the player will always exit the warp facing South.
            // This may have been intentional, unclear
            tStartDir = GetSpinStartFacingDir();
            ObjectEventForceSetHeldMovement(object, GetFaceDirectionMovementAction(sSpinDirections[tStartDir]));
            tSpinDelayTimer = 0;
            tSpeed = 116;
            tDestY = sprite->y;
            tPriority = sprite->oam.priority;
            tSubpriority = sprite->subpriority;
            tCurY = -((u16)sprite->y2 + 32) * 16;
            sprite->y2 = 0;
            CameraObjectFreezeJP();
            object->fixedPriority = TRUE;
            sprite->oam.priority = 1;
            sprite->subpriority = 0;
            sprite->subspriteMode = SUBSPRITES_OFF;
            tState++;
        case 1: // Spin while descending
            TrySpinPlayerForWarp(object, &tSpinDelayTimer);

            // Fall and decelerate
            tCurY += tSpeed;
            tSpeed -= 3;
            if (tSpeed < 4)
                tSpeed = 4;
            sprite->y = tCurY >> 4;

            // Check if reached dest
            if (sprite->y >= tDestY)
            {
                sprite->y = tDestY;
                tGroundTimer = 0;
                tState++;
            }
            break;
        case 2: // Spin on ground
            TrySpinPlayerForWarp(object, &tSpinDelayTimer);
            if (++tGroundTimer > 8)
                tState++;
            break;
        case 3: // Spin until facing original direction
            if (tStartDir == TrySpinPlayerForWarp(object, &tSpinDelayTimer))
            {
                object->fixedPriority = 0;
                sprite->oam.priority = tPriority;
                sprite->subpriority = tSubpriority;
                CameraObjectReset();
                DestroyTask(taskId);
            }
            break;
    }
}

u8 TrySpinPlayerForWarp(struct ObjectEvent *object, s16 *delayTimer)
{
    if (*delayTimer < 8 && ++(*delayTimer) < 8)
        return object->facingDirection;

    if (!ObjectEventCheckHeldMovementStatus(object))
        return object->facingDirection;

    ObjectEventForceSetHeldMovement(object, GetFaceDirectionMovementAction(sSpinDirections[object->facingDirection]));
    *delayTimer = 0;
    return sSpinDirections[object->facingDirection];
}

// Emit shared data after the code so table initializers do not change codegen.
#include "data/field_player_avatar.h"

#endif // FIELD_PLAYER_AVATAR_TAIL
