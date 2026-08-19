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

#define NUM_FORCED_MOVEMENTS 18
#define NUM_ACRO_BIKE_COLLISIONS 5

void DoPlayerAvatarTransition(void);

// JP-only helpers still in asm (field_player_avatar.s / event_object_movement.s)
void sub_0808BBE4(struct ObjectEvent *objectEvent);   // JP: HideShowWarpArrow
u8 sub_0808A98C(u8 direction);                        // JP: CheckForPlayerAvatarStaticCollision
void MovePlayerNotOnBike(u8 direction, u16 heldKeys);

// JP ROM tables: 18 forced-movement test funcs @ 0x0846F81C,
// forced-movement funcs @ 0x0846F864; wired via ld_script_jp.txt
extern bool8 (*const sForcedMovementTestFuncs[18])(u16 metatileBehavior);
extern bool8 (*const sForcedMovementFuncs[18])(void);

// JP: these are global because the remaining asm in field_player_avatar.s
// still calls them by their JP names (aliased in ld_script_jp.txt)
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
bool8 sub_0808AB9C(s16 x, s16 y, u8 direction); // JP: TryPushBoulder
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

    sub_0808BBE4(playerObjEvent); // JP: HideShowWarpArrow
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

            if (sub_0808A98C(direction) == COLLISION_NONE) // JP: CheckForPlayerAvatarStaticCollision
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
extern bool8 (*const sAcroBikeTrickMetatiles[5])(u16 metatileBehavior);
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
    if (collision == COLLISION_OBJECT_EVENT && sub_0808AB9C(x, y, direction)) // JP: TryPushBoulder
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
extern bool8 (*const sArrowWarpMetatileBehaviorChecks[4])(u16 metatileBehavior);

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

__attribute__((naked, section(".text.sub_0808AB9C"))) void sub_0808AB9C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	sub sp, #4\n\t"
        "	mov r3, sp\n\t"
        "	strh r0, [r3]\n\t"
        "	mov r5, sp\n\t"
        "	adds r5, #2\n\t"
        "	strh r1, [r5]\n\t"
        "	lsls r2, r2, #0x18\n\t"
        "	lsrs r7, r2, #0x18\n\t"
        "	ldr r0, _0808AC34\n\t"
        "	bl FlagGet\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808AC3C\n\t"
        "	mov r0, sp\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	bl GetEventObjectIdByXY\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	cmp r6, #0x10\n\t"
        "	beq _0808AC3C\n\t"
        "	ldr r0, _0808AC38\n\t"
        "	lsls r1, r6, #3\n\t"
        "	adds r1, r1, r6\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r4, r1, r0\n\t"
        "	ldrb r0, [r4, #5]\n\t"
        "	cmp r0, #0x57\n\t"
        "	bne _0808AC3C\n\t"
        "	ldrh r1, [r4, #0x10]\n\t"
        "	mov r0, sp\n\t"
        "	strh r1, [r0]\n\t"
        "	ldrh r0, [r4, #0x12]\n\t"
        "	strh r0, [r5]\n\t"
        "	adds r0, r7, #0\n\t"
        "	mov r1, sp\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl MoveCoords\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r5, r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r3, r7, #0\n\t"
        "	bl GetCollisionAtCoords\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808AC3C\n\t"
        "	mov r0, sp\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl MetatileBehavior_IsNonAnimDoor\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808AC3C\n\t"
        "	adds r0, r6, #0\n\t"
        "	adds r1, r7, #0\n\t"
        "	bl StartStrengthAnim\n\t"
        "	movs r0, #1\n\t"
        "	b _0808AC3E\n\t"
        "	.align 2, 0\n\t"
        "_0808AC34: .4byte 0x00000889\n\t"
        "_0808AC38: .4byte 0x02036FF0\n\t"
        "_0808AC3C:\n\t"
        "	movs r0, #0\n\t"
        "_0808AC3E:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked, section(".text.player_get_pos_including_state_based_drift"))) void player_get_pos_including_state_based_drift(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldr r0, _0808B494\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808B498\n\t"
        "	adds r3, r0, r1\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r0, #0xc0\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0x40\n\t"
        "	beq _0808B460\n\t"
        "	b _0808B588\n\t"
        "_0808B460:\n\t"
        "	ldr r2, _0808B49C\n\t"
        "	ldrb r1, [r3, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	movs r1, #0x32\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808B476\n\t"
        "	b _0808B588\n\t"
        "_0808B476:\n\t"
        "	ldrh r0, [r3, #0x10]\n\t"
        "	strh r0, [r4]\n\t"
        "	ldrh r0, [r3, #0x12]\n\t"
        "	strh r0, [r5]\n\t"
        "	ldrb r0, [r3, #0x1c]\n\t"
        "	subs r0, #8\n\t"
        "	cmp r0, #0x30\n\t"
        "	bls _0808B488\n\t"
        "	b _0808B588\n\t"
        "_0808B488:\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808B4A0\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	mov pc, r0\n\t"
        "	.align 2, 0\n\t"
        "_0808B494: .4byte 0x02037230\n\t"
        "_0808B498: .4byte 0x02036FF0\n\t"
        "_0808B49C: .4byte 0x020205AC\n\t"
        "_0808B4A0: .4byte 0x0808B4A4\n\t"
        "_0808B4A4:\n\t"
        "	.4byte _0808B568\n\t"
        "	.4byte _0808B56E\n\t"
        "	.4byte _0808B578\n\t"
        "	.4byte _0808B57E\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B588\n\t"
        "	.4byte _0808B568\n\t"
        "	.4byte _0808B56E\n\t"
        "	.4byte _0808B578\n\t"
        "	.4byte _0808B57E\n\t"
        "_0808B568:\n\t"
        "	ldrh r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	b _0808B572\n\t"
        "_0808B56E:\n\t"
        "	ldrh r0, [r5]\n\t"
        "	subs r0, #1\n\t"
        "_0808B572:\n\t"
        "	strh r0, [r5]\n\t"
        "	movs r0, #1\n\t"
        "	b _0808B594\n\t"
        "_0808B578:\n\t"
        "	ldrh r0, [r4]\n\t"
        "	subs r0, #1\n\t"
        "	b _0808B582\n\t"
        "_0808B57E:\n\t"
        "	ldrh r0, [r4]\n\t"
        "	adds r0, #1\n\t"
        "_0808B582:\n\t"
        "	strh r0, [r4]\n\t"
        "	movs r0, #1\n\t"
        "	b _0808B594\n\t"
        "_0808B588:\n\t"
        "	movs r1, #1\n\t"
        "	rsbs r1, r1, #0\n\t"
        "	adds r0, r1, #0\n\t"
        "	strh r0, [r4]\n\t"
        "	strh r0, [r5]\n\t"
        "	movs r0, #0\n\t"
        "_0808B594:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetPlayerFacingDirection(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r2, _0808B5B4\n\t"
        "	ldr r0, _0808B5B8\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B5B4: .4byte 0x02036FF0\n\t"
        "_0808B5B8: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetPlayerMovementDirection(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r2, _0808B5D0\n\t"
        "	ldr r0, _0808B5D4\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #0x18]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B5D0: .4byte 0x02036FF0\n\t"
        "_0808B5D4: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlayerGetElevation(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r2, _0808B5EC\n\t"
        "	ldr r0, _0808B5F0\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #0xb]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B5EC: .4byte 0x02036FF0\n\t"
        "_0808B5F0: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808B5F4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	adds r3, r0, #0\n\t"
        "	adds r2, r1, #0\n\t"
        "	ldr r0, _0808B61C\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808B620\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r3, r3, #0x10\n\t"
        "	asrs r3, r3, #0x10\n\t"
        "	lsls r2, r2, #0x10\n\t"
        "	asrs r2, r2, #0x10\n\t"
        "	adds r1, r3, #0\n\t"
        "	bl MoveEventObjectToMapCoords\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808B61C: .4byte 0x02037230\n\t"
        "_0808B620: .4byte 0x02036FF0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void TestPlayerAvatarFlags(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r1, _0808B630\n\t"
        "	ldrb r1, [r1]\n\t"
        "	ands r1, r0\n\t"
        "	adds r0, r1, #0\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B630: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808B634(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, _0808B63C\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B63C: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetPlayerAvatarSpriteId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r0, _0808B648\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B648: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

void CancelPlayerForcedMovement(void)
{
    ForcedMovement_None();
}

__attribute__((naked)) void sub_0808B658(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r0, _0808B698\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	lsls r4, r0, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808B69C\n\t"
        "	adds r4, r4, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl npc_clear_strange_bits\n\t"
        "	ldrb r1, [r4, #0x18]\n\t"
        "	lsls r1, r1, #0x1c\n\t"
        "	lsrs r1, r1, #0x1c\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl SetEventObjectDirection\n\t"
        "	movs r0, #6\n\t"
        "	bl TestPlayerAvatarFlags\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808B690\n\t"
        "	bl Bike_HandleBumpySlopeJump\n\t"
        "	movs r0, #0\n\t"
        "	bl Bike_UpdateBikeCounterSpeed\n\t"
        "_0808B690:\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808B698: .4byte 0x02037230\n\t"
        "_0808B69C: .4byte 0x02036FF0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetPlayerAvatarGraphicsIdByStateIdAndGender(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldr r2, _0808B6B4\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B6B4: .4byte gUnknown_846F908\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808B6B8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	ldr r2, _0808B6CC\n\t"
        "	lsrs r0, r0, #0x17\n\t"
        "	adds r1, r1, r0\n\t"
        "	adds r1, r1, r2\n\t"
        "	ldrb r0, [r1]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B6CC: .4byte gUnknown_846F918\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808B6D0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _0808B6DC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B6DC: .4byte gUnknown_846F928\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetFRLGAvatarGraphicsIdByGender(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _0808B6EC\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B6EC: .4byte gUnknown_846F92A\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetPlayerAvatarGraphicsIdByStateId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r1, _0808B708\n\t"
        "	ldrb r1, [r1, #7]\n\t"
        "	bl sub_0808B6B8\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808B708: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void unref_GetRivalAvatarGenderByGraphicsId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r1, r0, #0\n\t"
        "	cmp r0, #0x70\n\t"
        "	beq _0808B72E\n\t"
        "	cmp r0, #0x70\n\t"
        "	bgt _0808B726\n\t"
        "	cmp r0, #0x6d\n\t"
        "	bgt _0808B732\n\t"
        "	cmp r0, #0x69\n\t"
        "	blt _0808B732\n\t"
        "	b _0808B72E\n\t"
        "_0808B726:\n\t"
        "	cmp r1, #0x8a\n\t"
        "	beq _0808B72E\n\t"
        "	cmp r1, #0xc0\n\t"
        "	bne _0808B732\n\t"
        "_0808B72E:\n\t"
        "	movs r0, #1\n\t"
        "	b _0808B734\n\t"
        "_0808B732:\n\t"
        "	movs r0, #0\n\t"
        "_0808B734:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetPlayerAvatarGenderByGraphicsId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r1, r0, #0\n\t"
        "	cmp r0, #0x70\n\t"
        "	beq _0808B75A\n\t"
        "	cmp r0, #0x70\n\t"
        "	bgt _0808B752\n\t"
        "	cmp r0, #0x5d\n\t"
        "	bgt _0808B75E\n\t"
        "	cmp r0, #0x59\n\t"
        "	blt _0808B75E\n\t"
        "	b _0808B75A\n\t"
        "_0808B752:\n\t"
        "	cmp r1, #0x8a\n\t"
        "	beq _0808B75A\n\t"
        "	cmp r1, #0xc0\n\t"
        "	bne _0808B75E\n\t"
        "_0808B75A:\n\t"
        "	movs r0, #1\n\t"
        "	b _0808B760\n\t"
        "_0808B75E:\n\t"
        "	movs r0, #0\n\t"
        "_0808B760:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PartyHasMonWithSurf(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	movs r0, #8\n\t"
        "	bl TestPlayerAvatarFlags\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808B7A8\n\t"
        "	movs r5, #0\n\t"
        "	b _0808B78E\n\t"
        "_0808B776:\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0x39\n\t"
        "	bl MonKnowsMove\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808B788\n\t"
        "	movs r0, #1\n\t"
        "	b _0808B7AA\n\t"
        "_0808B788:\n\t"
        "	adds r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "_0808B78E:\n\t"
        "	cmp r5, #5\n\t"
        "	bhi _0808B7A8\n\t"
        "	movs r0, #0x64\n\t"
        "	adds r1, r5, #0\n\t"
        "	muls r1, r0, r1\n\t"
        "	ldr r0, _0808B7B0\n\t"
        "	adds r4, r1, r0\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xb\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808B776\n\t"
        "_0808B7A8:\n\t"
        "	movs r0, #0\n\t"
        "_0808B7AA:\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808B7B0: .4byte 0x02024190\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void IsPlayerSurfingNorth(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl GetPlayerMovementDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #2\n\t"
        "	bne _0808B7D2\n\t"
        "	movs r0, #8\n\t"
        "	bl TestPlayerAvatarFlags\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808B7D2\n\t"
        "	movs r0, #1\n\t"
        "	b _0808B7D4\n\t"
        "_0808B7D2:\n\t"
        "	movs r0, #0\n\t"
        "_0808B7D4:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void IsPlayerFacingSurfableFishableWater(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #4\n\t"
        "	ldr r0, _0808B850\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	lsls r4, r0, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808B854\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrh r1, [r4, #0x10]\n\t"
        "	mov r0, sp\n\t"
        "	strh r1, [r0]\n\t"
        "	ldrh r0, [r4, #0x12]\n\t"
        "	mov r5, sp\n\t"
        "	adds r5, #2\n\t"
        "	strh r0, [r5]\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	mov r1, sp\n\t"
        "	adds r2, r5, #0\n\t"
        "	bl MoveCoords\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r0, r2]\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r2, [r5, r0]\n\t"
        "	ldrb r3, [r4, #0x18]\n\t"
        "	lsls r3, r3, #0x1c\n\t"
        "	lsrs r3, r3, #0x1c\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetCollisionAtCoords\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0808B858\n\t"
        "	bl PlayerGetElevation\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0808B858\n\t"
        "	mov r0, sp\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	bl MapGridGetMetatileBehaviorAt\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl MetatileBehavior_IsSurfableFishableWater\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808B858\n\t"
        "	movs r0, #1\n\t"
        "	b _0808B85A\n\t"
        "	.align 2, 0\n\t"
        "_0808B850: .4byte 0x02037230\n\t"
        "_0808B854: .4byte 0x02036FF0\n\t"
        "_0808B858:\n\t"
        "	movs r0, #0\n\t"
        "_0808B85A:\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void ClearPlayerAvatarInfo(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0808B874\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0x24\n\t"
        "	bl memset\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808B874: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetPlayerAvatarStateMask(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r3, _0808B88C\n\t"
        "	ldrb r2, [r3]\n\t"
        "	movs r1, #0xe0\n\t"
        "	ands r1, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808B88C: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetPlayerAvatarStateTransitionByGraphicsId(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	movs r2, #0\n\t"
        "	ldr r3, _0808B8B8\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r4, r0, #1\n\t"
        "	adds r6, r3, #1\n\t"
        "_0808B8A6:\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r1, r0, r4\n\t"
        "	adds r0, r1, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	cmp r0, r5\n\t"
        "	bne _0808B8BC\n\t"
        "	adds r0, r1, r6\n\t"
        "	ldrb r0, [r0]\n\t"
        "	b _0808B8C8\n\t"
        "	.align 2, 0\n\t"
        "_0808B8B8: .4byte gUnknown_846F92C\n\t"
        "_0808B8BC:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #4\n\t"
        "	bls _0808B8A6\n\t"
        "	movs r0, #1\n\t"
        "_0808B8C8:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void GetPlayerAvatarGraphicsIdByCurrentState(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	ldr r0, _0808B8F8\n\t"
        "	ldrb r5, [r0]\n\t"
        "	movs r2, #0\n\t"
        "	ldr r3, _0808B8FC\n\t"
        "	ldrb r1, [r0, #7]\n\t"
        "	lsls r0, r1, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r4, r0, #1\n\t"
        "	adds r6, r3, #1\n\t"
        "_0808B8E4:\n\t"
        "	lsls r0, r2, #1\n\t"
        "	adds r1, r0, r4\n\t"
        "	adds r0, r1, r6\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ands r0, r5\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808B900\n\t"
        "	adds r0, r1, r3\n\t"
        "	ldrb r0, [r0]\n\t"
        "	b _0808B90C\n\t"
        "	.align 2, 0\n\t"
        "_0808B8F8: .4byte 0x02037230\n\t"
        "_0808B8FC: .4byte gUnknown_846F92C\n\t"
        "_0808B900:\n\t"
        "	adds r0, r2, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r2, r0, #0x18\n\t"
        "	cmp r2, #4\n\t"
        "	bls _0808B8E4\n\t"
        "	movs r0, #0\n\t"
        "_0808B90C:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetPlayerAvatarExtraStateTransition(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r5, _0808B940\n\t"
        "	ldrb r1, [r5, #7]\n\t"
        "	bl GetPlayerAvatarStateTransitionByGraphicsId\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	orrs r0, r4\n\t"
        "	ldrb r1, [r5, #1]\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r5, #1]\n\t"
        "	bl DoPlayerAvatarTransition\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808B940: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void InitPlayerAvatar(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, sb\n\t"
        "	mov r5, r8\n\t"
        "	push {r5, r6}\n\t"
        "	sub sp, #0x18\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	mov sb, r2\n\t"
        "	mov r8, r3\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	lsrs r4, r4, #0x10\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	lsrs r5, r5, #0x10\n\t"
        "	mov r0, sb\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov sb, r0\n\t"
        "	mov r1, r8\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	mov r8, r1\n\t"
        "	mov r1, sp\n\t"
        "	movs r0, #0xff\n\t"
        "	strb r0, [r1]\n\t"
        "	movs r0, #0\n\t"
        "	mov r1, r8\n\t"
        "	bl sub_0808B6B8\n\t"
        "	mov r1, sp\n\t"
        "	movs r3, #0\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	mov r0, sp\n\t"
        "	lsls r4, r4, #0x10\n\t"
        "	asrs r4, r4, #0x10\n\t"
        "	subs r4, #7\n\t"
        "	movs r6, #0\n\t"
        "	strh r4, [r0, #4]\n\t"
        "	lsls r5, r5, #0x10\n\t"
        "	asrs r5, r5, #0x10\n\t"
        "	subs r5, #7\n\t"
        "	strh r5, [r0, #6]\n\t"
        "	strb r6, [r0, #8]\n\t"
        "	movs r0, #0xb\n\t"
        "	strb r0, [r1, #9]\n\t"
        "	mov r2, sp\n\t"
        "	ldrb r1, [r2, #0xa]\n\t"
        "	subs r0, #0x1b\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2, #0xa]\n\t"
        "	mov r0, sp\n\t"
        "	strb r6, [r0, #0xa]\n\t"
        "	strh r3, [r0, #0xc]\n\t"
        "	strh r3, [r0, #0xe]\n\t"
        "	str r3, [sp, #0x10]\n\t"
        "	strh r3, [r0, #0x14]\n\t"
        "	bl SpawnSpecialEventObject\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	lsls r4, r5, #3\n\t"
        "	adds r4, r4, r5\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808BA04\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrb r0, [r4, #2]\n\t"
        "	movs r1, #1\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #2]\n\t"
        "	bl CreateWarpArrowSprite\n\t"
        "	strb r0, [r4, #0x1b]\n\t"
        "	adds r0, r4, #0\n\t"
        "	mov r1, sb\n\t"
        "	bl EventObjectTurn\n\t"
        "	bl ClearPlayerAvatarInfo\n\t"
        "	ldr r0, _0808BA08\n\t"
        "	strb r6, [r0, #2]\n\t"
        "	strb r6, [r0, #3]\n\t"
        "	strb r5, [r0, #5]\n\t"
        "	ldrb r1, [r4, #4]\n\t"
        "	strb r1, [r0, #4]\n\t"
        "	mov r1, r8\n\t"
        "	strb r1, [r0, #7]\n\t"
        "	movs r0, #0x21\n\t"
        "	bl SetPlayerAvatarStateMask\n\t"
        "	add sp, #0x18\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BA04: .4byte 0x02036FF0\n\t"
        "_0808BA08: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetPlayerInvisibility(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r4, r0, #0x18\n\t"
        "	ldr r6, _0808BA6C\n\t"
        "	ldr r5, _0808BA70\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r6\n\t"
        "	movs r0, #1\n\t"
        "	ands r4, r0\n\t"
        "	lsls r3, r4, #5\n\t"
        "	ldrb r2, [r1, #1]\n\t"
        "	movs r0, #0x21\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r3\n\t"
        "	strb r0, [r1, #1]\n\t"
        "	movs r0, #8\n\t"
        "	bl TestPlayerAvatarFlags\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808BA64\n\t"
        "	ldr r2, _0808BA74\n\t"
        "	ldrb r1, [r5, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r6\n\t"
        "	ldrb r0, [r0, #0x1a]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r2\n\t"
        "	adds r1, #0x3e\n\t"
        "	lsls r3, r4, #2\n\t"
        "	ldrb r2, [r1]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r3\n\t"
        "	strb r0, [r1]\n\t"
        "_0808BA64:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BA6C: .4byte 0x02036FF0\n\t"
        "_0808BA70: .4byte 0x02037230\n\t"
        "_0808BA74: .4byte 0x020205AC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void SetPlayerAvatarFieldMove(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	ldr r5, _0808BAB4\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	lsls r4, r0, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808BAB8\n\t"
        "	adds r4, r4, r0\n\t"
        "	movs r0, #5\n\t"
        "	bl GetPlayerAvatarGraphicsIdByStateId\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetGraphicsId\n\t"
        "	ldrb r1, [r5, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808BABC\n\t"
        "	adds r0, r0, r1\n\t"
        "	movs r1, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BAB4: .4byte 0x02037230\n\t"
        "_0808BAB8: .4byte 0x02036FF0\n\t"
        "_0808BABC: .4byte 0x020205AC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808BAC0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r6, _0808BB0C\n\t"
        "	ldrb r0, [r6, #5]\n\t"
        "	lsls r4, r0, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808BB10\n\t"
        "	adds r4, r4, r0\n\t"
        "	movs r0, #6\n\t"
        "	bl GetPlayerAvatarGraphicsIdByStateId\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetGraphicsId\n\t"
        "	ldrb r0, [r6, #4]\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808BB14\n\t"
        "	adds r4, r4, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetWalkInPlaceNormalMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BB0C: .4byte 0x02037230\n\t"
        "_0808BB10: .4byte 0x02036FF0\n\t"
        "_0808BB14: .4byte 0x020205AC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808BB18(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	mov r6, r8\n\t"
        "	push {r6}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r6, _0808BB80\n\t"
        "	ldrb r0, [r6, #5]\n\t"
        "	lsls r4, r0, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808BB84\n\t"
        "	adds r4, r4, r0\n\t"
        "	movs r0, #2\n\t"
        "	bl GetPlayerAvatarGraphicsIdByStateId\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetGraphicsId\n\t"
        "	ldrb r0, [r6, #4]\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808BB88\n\t"
        "	mov r8, r0\n\t"
        "	add r4, r8\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetSlideMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	ldrb r1, [r6, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, r8\n\t"
        "	movs r1, #1\n\t"
        "	bl SeekSpriteAnim\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BB80: .4byte 0x02037230\n\t"
        "_0808BB84: .4byte 0x02036FF0\n\t"
        "_0808BB88: .4byte 0x020205AC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808BB8C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r6, _0808BBD8\n\t"
        "	ldrb r0, [r6, #5]\n\t"
        "	lsls r4, r0, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808BBDC\n\t"
        "	adds r4, r4, r0\n\t"
        "	movs r0, #7\n\t"
        "	bl GetPlayerAvatarGraphicsIdByStateId\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetGraphicsId\n\t"
        "	ldrb r0, [r6, #4]\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808BBE0\n\t"
        "	adds r4, r4, r0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl GetJumpInPlaceMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BBD8: .4byte 0x02037230\n\t"
        "_0808BBDC: .4byte 0x02036FF0\n\t"
        "_0808BBE0: .4byte 0x020205AC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808BBE4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	sub sp, #4\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldrb r0, [r5, #0x1e]\n\t"
        "	mov r8, r0\n\t"
        "	movs r1, #0\n\t"
        "	mov r0, sp\n\t"
        "	strh r1, [r0]\n\t"
        "	movs r6, #1\n\t"
        "	ldr r1, _0808BC48\n\t"
        "	mov sb, r1\n\t"
        "	mov r4, sp\n\t"
        "	mov r7, sp\n\t"
        "	adds r7, #2\n\t"
        "_0808BC06:\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	add r0, sb\n\t"
        "	ldr r1, [r0]\n\t"
        "	mov r0, r8\n\t"
        "	bl _call_via_r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808BC4C\n\t"
        "	ldrb r0, [r5, #0x18]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	cmp r6, r0\n\t"
        "	bne _0808BC4C\n\t"
        "	ldrh r0, [r5, #0x10]\n\t"
        "	strh r0, [r4]\n\t"
        "	ldrh r0, [r5, #0x12]\n\t"
        "	strh r0, [r7]\n\t"
        "	adds r0, r6, #0\n\t"
        "	mov r1, sp\n\t"
        "	adds r2, r7, #0\n\t"
        "	bl MoveCoords\n\t"
        "	ldrb r0, [r5, #0x1b]\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r2, [r4, r1]\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r3, [r7, r1]\n\t"
        "	adds r1, r6, #0\n\t"
        "	bl ShowWarpArrowSprite\n\t"
        "	b _0808BC66\n\t"
        "	.align 2, 0\n\t"
        "_0808BC48: .4byte sArrowWarpMetatileBehaviorChecks2\n\t"
        "_0808BC4C:\n\t"
        "	ldrh r1, [r4]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r4]\n\t"
        "	adds r0, r6, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	cmp r1, #3\n\t"
        "	ble _0808BC06\n\t"
        "	ldrb r0, [r5, #0x1b]\n\t"
        "	bl SetSpriteInvisible\n\t"
        "_0808BC66:\n\t"
        "	add sp, #4\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void StartStrengthAnim(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	lsls r5, r5, #0x18\n\t"
        "	lsrs r5, r5, #0x18\n\t"
        "	ldr r6, _0808BCA8\n\t"
        "	adds r0, r6, #0\n\t"
        "	movs r1, #0xff\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _0808BCAC\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	strh r4, [r1, #0xa]\n\t"
        "	strh r5, [r1, #0xc]\n\t"
        "	bl _call_via_r6\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BCA8: .4byte 0x0808BCB1\n\t"
        "_0808BCAC: .4byte 0x03005B60\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_BumpBoulder(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r6, _0808BCF8\n\t"
        "	ldr r2, _0808BCFC\n\t"
        "	ldr r5, _0808BD00\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r4, r1, r2\n\t"
        "_0808BCC4:\n\t"
        "	movs r0, #8\n\t"
        "	ldrsh r3, [r4, r0]\n\t"
        "	lsls r3, r3, #2\n\t"
        "	adds r3, r3, r6\n\t"
        "	ldr r0, _0808BD04\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r5\n\t"
        "	movs r2, #0xa\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	lsls r2, r0, #3\n\t"
        "	adds r2, r2, r0\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r5\n\t"
        "	ldr r3, [r3]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl _call_via_r3\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808BCC4\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BCF8: .4byte gUnknown_846F950\n\t"
        "_0808BCFC: .4byte 0x03005B60\n\t"
        "_0808BD00: .4byte 0x02036FF0\n\t"
        "_0808BD04: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808BD08(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl LockPlayerFieldControls\n\t"
        "	ldr r1, _0808BD24\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1, #6]\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808BD24: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void do_boulder_dust(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r4, r2, #0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventIsHeldMovementActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808BD42\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "_0808BD42:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventIsHeldMovementActive\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808BD54\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "_0808BD54:\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventIsMovementOverridden\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808BDD6\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventIsMovementOverridden\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808BDD6\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	ldrb r0, [r6, #0xc]\n\t"
        "	bl sub_08092F08\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventSetHeldMovement\n\t"
        "	ldrb r0, [r6, #0xc]\n\t"
        "	bl sub_08092CCC\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetHeldMovement\n\t"
        "	ldr r2, _0808BDE0\n\t"
        "	movs r1, #0x10\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	str r0, [r2]\n\t"
        "	movs r1, #0x12\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	str r0, [r2, #4]\n\t"
        "	ldrb r0, [r4, #0xb]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	str r0, [r2, #8]\n\t"
        "	ldr r3, _0808BDE4\n\t"
        "	ldrb r1, [r4, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1e\n\t"
        "	str r0, [r2, #0xc]\n\t"
        "	movs r0, #0xa\n\t"
        "	bl FieldEffectStart\n\t"
        "	movs r0, #0xd6\n\t"
        "	bl PlaySE\n\t"
        "	ldrh r0, [r6, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r6, #8]\n\t"
        "_0808BDD6:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808BDE0: .4byte 0x020388A8\n\t"
        "_0808BDE4: .4byte 0x020205AC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808BDE8(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r1, #0\n\t"
        "	adds r5, r2, #0\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventCheckHeldMovementStatus\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808BE2A\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventCheckHeldMovementStatus\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808BE2A\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	ldr r1, _0808BE34\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1, #6]\n\t"
        "	bl UnlockPlayerFieldControls\n\t"
        "	ldr r0, _0808BE38\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl DestroyTask\n\t"
        "_0808BE2A:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808BE34: .4byte 0x02037230\n\t"
        "_0808BE38: .4byte 0x0808BCB1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DoPlayerMatJump(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _0808BE58\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xff\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BE58: .4byte 0x0808BE5D\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DoPlayerAvatarSecretBaseMatJump(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r5, _0808BE98\n\t"
        "	ldr r2, _0808BE9C\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r4, r1, r2\n\t"
        "_0808BE6E:\n\t"
        "	movs r0, #8\n\t"
        "	ldrsh r2, [r4, r0]\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r5\n\t"
        "	ldr r0, _0808BEA0\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r0, _0808BEA4\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r2, [r2]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl _call_via_r2\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808BE8C(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808BE6E\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BE98: .4byte gUnknown_846F95C\n\t"
        "_0808BE9C: .4byte 0x03005B60\n\t"
        "_0808BEA0: .4byte 0x02037230\n\t"
        "_0808BEA4: .4byte 0x02036FF0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlayerAvatar_DoSecretBaseMatJump(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r6, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldr r5, _0808BF0C\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r5, #6]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808BF04\n\t"
        "	movs r0, #0xa\n\t"
        "	bl PlaySE\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl sub_08092E2C\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetHeldMovement\n\t"
        "	ldrh r0, [r6, #0xa]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r6, #0xa]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #1\n\t"
        "	ble _0808BF04\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r5, #6]\n\t"
        "	ldrb r0, [r5, #1]\n\t"
        "	movs r1, #0x20\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r5, #1]\n\t"
        "	ldr r0, _0808BF10\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl DestroyTask\n\t"
        "_0808BF04:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808BF0C: .4byte 0x02037230\n\t"
        "_0808BF10: .4byte 0x0808BE5D\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DoPlayerMatSpin(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _0808BF30\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0xff\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BF30: .4byte 0x0808BF35\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlayerAvatar_DoSecretBaseMatSpin(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r5, _0808BF70\n\t"
        "	ldr r2, _0808BF74\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r4, r1, r2\n\t"
        "_0808BF46:\n\t"
        "	movs r0, #8\n\t"
        "	ldrsh r2, [r4, r0]\n\t"
        "	lsls r2, r2, #2\n\t"
        "	adds r2, r2, r5\n\t"
        "	ldr r0, _0808BF78\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldr r0, _0808BF7C\n\t"
        "	adds r1, r1, r0\n\t"
        "	ldr r2, [r2]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl _call_via_r2\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808BF64(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808BF46\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808BF70: .4byte sPlayerAvatarSecretBaseMatSpin\n\t"
        "_0808BF74: .4byte 0x03005B60\n\t"
        "_0808BF78: .4byte 0x02037230\n\t"
        "_0808BF7C: .4byte 0x02036FF0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlayerAvatar_SecretBaseMatSpinStep0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldrh r2, [r0, #8]\n\t"
        "	adds r2, #1\n\t"
        "	strh r2, [r0, #8]\n\t"
        "	ldrb r1, [r1, #0x18]\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	strh r1, [r0, #0xa]\n\t"
        "	ldr r1, _0808BFA4\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1, #6]\n\t"
        "	bl LockPlayerFieldControls\n\t"
        "	movs r0, #0x2d\n\t"
        "	bl PlaySE\n\t"
        "	movs r0, #1\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808BFA4: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlayerAvatar_SecretBaseMatSpinStep1(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #4\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	ldr r1, _0808C01C\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #4\n\t"
        "	bl memcpy\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C010\n\t"
        "	ldrb r0, [r5, #0x18]\n\t"
        "	lsrs r0, r0, #4\n\t"
        "	subs r0, #1\n\t"
        "	add r0, sp\n\t"
        "	ldrb r6, [r0]\n\t"
        "	adds r0, r6, #0\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventSetHeldMovement\n\t"
        "	ldrb r0, [r4, #0xa]\n\t"
        "	cmp r6, r0\n\t"
        "	bne _0808BFEE\n\t"
        "	ldrh r0, [r4, #0xc]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0xc]\n\t"
        "_0808BFEE:\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	movs r1, #0xc\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #3\n\t"
        "	ble _0808C010\n\t"
        "	ldrb r0, [r4, #0xa]\n\t"
        "	bl GetOppositeDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r6, r0\n\t"
        "	bne _0808C010\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "_0808C010:\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #4\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C01C: .4byte gUnknown_846F970\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlayerAvatar_SecretBaseMatSpinStep2(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r4, r1, #0\n\t"
        "	ldr r1, _0808C05C\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #5\n\t"
        "	bl memcpy\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C050\n\t"
        "	movs r1, #0xc\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	add r0, sp\n\t"
        "	ldrb r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetHeldMovement\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r5, #8]\n\t"
        "_0808C050:\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #8\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C05C: .4byte gUnknown_846F974\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void PlayerAvatar_SecretBaseMatSpinStep3(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	adds r5, r1, #0\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C0A4\n\t"
        "	ldrb r0, [r4, #0xa]\n\t"
        "	bl GetOppositeDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl sub_08092CCC\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventSetHeldMovement\n\t"
        "	bl UnlockPlayerFieldControls\n\t"
        "	ldr r1, _0808C0AC\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1, #6]\n\t"
        "	ldr r0, _0808C0B0\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl DestroyTask\n\t"
        "_0808C0A4:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C0AC: .4byte 0x02037230\n\t"
        "_0808C0B0: .4byte 0x0808BF35\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808C0B4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	bl LockPlayerFieldControls\n\t"
        "	bl Overworld_ClearSavedMusic\n\t"
        "	bl Overworld_ChangeMusicToDefault\n\t"
        "	ldr r2, _0808C100\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0xf7\n\t"
        "	ands r0, r1\n\t"
        "	movs r1, #1\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r2, #6]\n\t"
        "	ldr r5, _0808C104\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xff\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _0808C108\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	strh r4, [r1, #8]\n\t"
        "	bl _call_via_r5\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808C100: .4byte 0x02037230\n\t"
        "_0808C104: .4byte 0x0808C10D\n\t"
        "_0808C108: .4byte 0x03005B60\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void taskFF_0805D1D4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r6, r0, #0x18\n\t"
        "	ldr r0, _0808C168\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808C16C\n\t"
        "	adds r5, r0, r1\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventIsMovementOverridden\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C138\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C160\n\t"
        "_0808C138:\n\t"
        "	ldrb r0, [r5, #0x1a]\n\t"
        "	movs r1, #2\n\t"
        "	bl SetSurfBlob_BobState\n\t"
        "	ldr r0, _0808C170\n\t"
        "	lsls r4, r6, #2\n\t"
        "	adds r4, r4, r6\n\t"
        "	lsls r4, r4, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	ldrb r0, [r4, #8]\n\t"
        "	bl sub_08092EB0\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventSetHeldMovement\n\t"
        "	ldr r0, _0808C174\n\t"
        "	str r0, [r4]\n\t"
        "_0808C160:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808C168: .4byte 0x02037230\n\t"
        "_0808C16C: .4byte 0x02036FF0\n\t"
        "_0808C170: .4byte 0x03005B60\n\t"
        "_0808C174: .4byte 0x0808C179\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808C178(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "	ldr r6, _0808C1E4\n\t"
        "	ldrb r1, [r6, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808C1E8\n\t"
        "	adds r4, r0, r1\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C1DE\n\t"
        "	movs r0, #0\n\t"
        "	bl GetPlayerAvatarGraphicsIdByStateId\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetGraphicsId\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetHeldMovement\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r6, #6]\n\t"
        "	bl UnlockPlayerFieldControls\n\t"
        "	ldrb r1, [r4, #0x1a]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808C1EC\n\t"
        "	adds r0, r0, r1\n\t"
        "	bl DestroySprite\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl DestroyTask\n\t"
        "_0808C1DE:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808C1E4: .4byte 0x02037230\n\t"
        "_0808C1E8: .4byte 0x02036FF0\n\t"
        "_0808C1EC: .4byte 0x020205AC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void StartFishing(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	lsls r4, r4, #0x18\n\t"
        "	lsrs r4, r4, #0x18\n\t"
        "	ldr r5, _0808C21C\n\t"
        "	adds r0, r5, #0\n\t"
        "	movs r1, #0xff\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r2, _0808C220\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r1, r1, r2\n\t"
        "	strh r4, [r1, #0x26]\n\t"
        "	bl _call_via_r5\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808C21C: .4byte 0x0808C225\n\t"
        "_0808C220: .4byte 0x03005B60\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_Fishing(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	ldr r5, _0808C254\n\t"
        "	ldr r2, _0808C258\n\t"
        "	lsls r1, r0, #2\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #3\n\t"
        "	adds r4, r1, r2\n\t"
        "_0808C236:\n\t"
        "	movs r1, #8\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r5\n\t"
        "	ldr r1, [r0]\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl _call_via_r1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808C236\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808C254: .4byte sFishingStateFuncs\n\t"
        "_0808C258: .4byte 0x03005B60\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_Init(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl LockPlayerFieldControls\n\t"
        "	ldr r1, _0808C278\n\t"
        "	movs r0, #1\n\t"
        "	strb r0, [r1, #6]\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C278: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_GetRodOut(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldr r1, _0808C304\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #6\n\t"
        "	bl memcpy\n\t"
        "	add r4, sp, #8\n\t"
        "	ldr r1, _0808C308\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r2, #6\n\t"
        "	bl memcpy\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5, #0x20]\n\t"
        "	bl Random\n\t"
        "	movs r2, #0x26\n\t"
        "	ldrsh r1, [r5, r2]\n\t"
        "	lsls r1, r1, #1\n\t"
        "	mov r2, sp\n\t"
        "	adds r6, r2, r1\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	adds r4, r4, r1\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r4, r2]\n\t"
        "	bl __modsi3\n\t"
        "	ldrh r1, [r6]\n\t"
        "	adds r1, r1, r0\n\t"
        "	strh r1, [r5, #0x22]\n\t"
        "	ldr r3, _0808C30C\n\t"
        "	ldr r2, _0808C310\n\t"
        "	ldrb r1, [r2, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r3\n\t"
        "	ldrb r0, [r0, #5]\n\t"
        "	strh r0, [r5, #0x24]\n\t"
        "	ldrb r0, [r2, #5]\n\t"
        "	lsls r4, r0, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	adds r4, r4, r3\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfActive\n\t"
        "	ldrb r0, [r4, #1]\n\t"
        "	movs r1, #8\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #1]\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl sub_0808BAC0\n\t"
        "	ldrh r0, [r5, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C304: .4byte gUnknown_846F9BC\n\t"
        "_0808C308: .4byte gUnknown_846F9C2\n\t"
        "_0808C30C: .4byte 0x02036FF0\n\t"
        "_0808C310: .4byte 0x02037230\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_WaitBeforeDots(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0xa]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x3b\n\t"
        "	ble _0808C330\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "_0808C330:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_InitDots(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl sub_08197650\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	movs r1, #0\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	strh r1, [r4, #0xa]\n\t"
        "	strh r1, [r4, #0xc]\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	movs r1, #0xa\n\t"
        "	bl __umodsi3\n\t"
        "	adds r1, r0, #0\n\t"
        "	adds r0, r1, #1\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "	movs r2, #0x20\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808C370\n\t"
        "	adds r0, r1, #4\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "_0808C370:\n\t"
        "	movs r1, #0xe\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #9\n\t"
        "	ble _0808C37C\n\t"
        "	movs r0, #0xa\n\t"
        "	strh r0, [r4, #0xe]\n\t"
        "_0808C37C:\n\t"
        "	movs r0, #1\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_ShowDots(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _0808C3C0\n\t"
        "	add r0, sp, #0xc\n\t"
        "	movs r2, #2\n\t"
        "	bl memcpy\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	ldrh r0, [r4, #0xa]\n\t"
        "	adds r1, r0, #1\n\t"
        "	strh r1, [r4, #0xa]\n\t"
        "	ldr r0, _0808C3C4\n\t"
        "	ldrh r0, [r0, #0x2e]\n\t"
        "	movs r2, #1\n\t"
        "	ands r2, r0\n\t"
        "	cmp r2, #0\n\t"
        "	beq _0808C3C8\n\t"
        "	movs r0, #0xb\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	movs r1, #0x20\n\t"
        "	ldrsh r0, [r4, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C3BA\n\t"
        "	movs r0, #0xc\n\t"
        "	strh r0, [r4, #8]\n\t"
        "_0808C3BA:\n\t"
        "	movs r0, #1\n\t"
        "	b _0808C41A\n\t"
        "	.align 2, 0\n\t"
        "_0808C3C0: .4byte gUnknown_846F9C2 + 0x6\n\t"
        "_0808C3C4: .4byte 0x03002360\n\t"
        "_0808C3C8:\n\t"
        "	lsls r0, r1, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #0x13\n\t"
        "	ble _0808C418\n\t"
        "	strh r2, [r4, #0xa]\n\t"
        "	movs r3, #0xc\n\t"
        "	ldrsh r1, [r4, r3]\n\t"
        "	movs r3, #0xe\n\t"
        "	ldrsh r0, [r4, r3]\n\t"
        "	cmp r1, r0\n\t"
        "	blt _0808C3F8\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r1, r0, #1\n\t"
        "	strh r1, [r4, #8]\n\t"
        "	ldrh r2, [r4, #0x20]\n\t"
        "	movs r3, #0x20\n\t"
        "	ldrsh r0, [r4, r3]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C3F2\n\t"
        "	adds r0, r1, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "_0808C3F2:\n\t"
        "	adds r0, r2, #1\n\t"
        "	strh r0, [r4, #0x20]\n\t"
        "	b _0808C418\n\t"
        "_0808C3F8:\n\t"
        "	movs r0, #0xc\n\t"
        "	ldrsh r3, [r4, r0]\n\t"
        "	lsls r3, r3, #0x1b\n\t"
        "	lsrs r3, r3, #0x18\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp]\n\t"
        "	str r2, [sp, #4]\n\t"
        "	str r2, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	add r2, sp, #0xc\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrh r0, [r4, #0xc]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #0xc]\n\t"
        "_0808C418:\n\t"
        "	movs r0, #0\n\t"
        "_0808C41A:\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_CheckForBite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	ldrh r0, [r5, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	movs r6, #0\n\t"
        "	bl DoesCurrentMapHaveFishingMons\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808C444\n\t"
        "	movs r0, #0xb\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	b _0808C4C4\n\t"
        "_0808C444:\n\t"
        "	ldr r4, _0808C494\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #6\n\t"
        "	bl GetMonData3\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808C47C\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl GetMonAbility\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #0x15\n\t"
        "	beq _0808C464\n\t"
        "	cmp r0, #0x3c\n\t"
        "	bne _0808C47C\n\t"
        "_0808C464:\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	movs r1, #0x64\n\t"
        "	bl __umodsi3\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	cmp r0, #0xe\n\t"
        "	bls _0808C47C\n\t"
        "	movs r6, #1\n\t"
        "_0808C47C:\n\t"
        "	cmp r6, #0\n\t"
        "	bne _0808C49A\n\t"
        "	bl Random\n\t"
        "	movs r1, #1\n\t"
        "	ands r1, r0\n\t"
        "	cmp r1, #0\n\t"
        "	beq _0808C498\n\t"
        "	movs r0, #0xb\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	b _0808C49A\n\t"
        "	.align 2, 0\n\t"
        "_0808C494: .4byte 0x02024190\n\t"
        "_0808C498:\n\t"
        "	movs r6, #1\n\t"
        "_0808C49A:\n\t"
        "	cmp r6, #1\n\t"
        "	bne _0808C4C4\n\t"
        "	ldr r0, _0808C4CC\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808C4D0\n\t"
        "	adds r4, r4, r0\n\t"
        "	bl GetPlayerFacingDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetWalkNormalMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "_0808C4C4:\n\t"
        "	movs r0, #1\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C4CC: .4byte 0x02037230\n\t"
        "_0808C4D0: .4byte 0x020205AC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_GotBite(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x18\n\t"
        "	adds r5, r0, #0\n\t"
        "	ldr r1, _0808C510\n\t"
        "	add r0, sp, #0xc\n\t"
        "	movs r2, #0xc\n\t"
        "	bl memcpy\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	movs r0, #0x12\n\t"
        "	str r0, [sp]\n\t"
        "	movs r4, #0\n\t"
        "	str r4, [sp, #4]\n\t"
        "	str r4, [sp, #8]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	add r2, sp, #0xc\n\t"
        "	movs r3, #0\n\t"
        "	bl AddTextPrinterParameterized\n\t"
        "	ldrh r0, [r5, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	strh r4, [r5, #0xa]\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #0x18\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C510: .4byte gUnknown_846F9C2 + 0x8\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_WaitForA(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #8\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _0808C548\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #6\n\t"
        "	bl memcpy\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	ldrh r1, [r4, #0xa]\n\t"
        "	adds r1, #1\n\t"
        "	strh r1, [r4, #0xa]\n\t"
        "	movs r2, #0x26\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	lsls r0, r0, #1\n\t"
        "	add r0, sp\n\t"
        "	lsls r1, r1, #0x10\n\t"
        "	asrs r1, r1, #0x10\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	cmp r1, r0\n\t"
        "	blt _0808C54C\n\t"
        "	movs r0, #0xc\n\t"
        "	b _0808C55C\n\t"
        "	.align 2, 0\n\t"
        "_0808C548: .4byte gUnknown_846F9D6\n\t"
        "_0808C54C:\n\t"
        "	ldr r0, _0808C568\n\t"
        "	ldrh r1, [r0, #0x2e]\n\t"
        "	movs r0, #1\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C55E\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "_0808C55C:\n\t"
        "	strh r0, [r4, #8]\n\t"
        "_0808C55E:\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #8\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C568: .4byte 0x03002360\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_CheckMoreDots(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	sub sp, #0xc\n\t"
        "	adds r4, r0, #0\n\t"
        "	ldr r1, _0808C5D0\n\t"
        "	mov r0, sp\n\t"
        "	movs r2, #0xc\n\t"
        "	bl memcpy\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	movs r0, #0x20\n\t"
        "	ldrsh r1, [r4, r0]\n\t"
        "	movs r2, #0x22\n\t"
        "	ldrsh r0, [r4, r2]\n\t"
        "	cmp r1, r0\n\t"
        "	blt _0808C5C2\n\t"
        "	cmp r1, #1\n\t"
        "	bgt _0808C5C6\n\t"
        "	bl Random\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r0, r0, #0x10\n\t"
        "	movs r1, #0x64\n\t"
        "	bl __umodsi3\n\t"
        "	movs r3, #0x20\n\t"
        "	ldrsh r2, [r4, r3]\n\t"
        "	lsls r2, r2, #1\n\t"
        "	movs r3, #0x26\n\t"
        "	ldrsh r1, [r4, r3]\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r2, r2, r1\n\t"
        "	mov r3, sp\n\t"
        "	adds r1, r3, r2\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r1, [r1, r2]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r1, r0\n\t"
        "	ble _0808C5C6\n\t"
        "_0808C5C2:\n\t"
        "	movs r0, #3\n\t"
        "	strh r0, [r4, #8]\n\t"
        "_0808C5C6:\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #0xc\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C5D0: .4byte gUnknown_846F9DC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_MonOnHook(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r2, _0808C614\n\t"
        "	movs r5, #0\n\t"
        "	str r5, [sp]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #1\n\t"
        "	bl AddTextPrinterParameterized2\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	strh r5, [r4, #0xa]\n\t"
        "	movs r0, #0\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C614: .4byte gUnknown_846F9DC + 0xC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_StartEncounter(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r5, r0, #0\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808C62C\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "_0808C62C:\n\t"
        "	bl RunTextPrinters\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808C6C8\n\t"
        "	movs r0, #0\n\t"
        "	bl IsTextPrinterActive\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r6, r0, #0x10\n\t"
        "	cmp r6, #0\n\t"
        "	bne _0808C6C0\n\t"
        "	ldr r7, _0808C6B4\n\t"
        "	ldrb r0, [r7, #5]\n\t"
        "	lsls r4, r0, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808C6B8\n\t"
        "	mov r8, r0\n\t"
        "	add r4, r8\n\t"
        "	ldrh r1, [r5, #0x24]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetGraphicsId\n\t"
        "	ldrb r1, [r4, #0x18]\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl EventObjectTurn\n\t"
        "	ldrb r1, [r7]\n\t"
        "	movs r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C68A\n\t"
        "	ldrb r0, [r7, #5]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, r8\n\t"
        "	ldrb r0, [r1, #0x1a]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl SetSurfBlob_PlayerOffset\n\t"
        "_0808C68A:\n\t"
        "	ldr r2, _0808C6BC\n\t"
        "	ldrb r1, [r7, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r6, [r0, #0x24]\n\t"
        "	ldrb r1, [r7, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	strh r6, [r0, #0x26]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl ClearDialogWindowAndFrame\n\t"
        "	ldrh r0, [r5, #0xa]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #0xa]\n\t"
        "	b _0808C6F0\n\t"
        "	.align 2, 0\n\t"
        "_0808C6B4: .4byte 0x02037230\n\t"
        "_0808C6B8: .4byte 0x02036FF0\n\t"
        "_0808C6BC: .4byte 0x020205AC\n\t"
        "_0808C6C0:\n\t"
        "	movs r1, #0xa\n\t"
        "	ldrsh r0, [r5, r1]\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C6F0\n\t"
        "_0808C6C8:\n\t"
        "	ldr r1, _0808C6FC\n\t"
        "	movs r0, #0\n\t"
        "	strb r0, [r1, #6]\n\t"
        "	bl UnlockPlayerFieldControls\n\t"
        "	ldrh r0, [r5, #0x26]\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl FishingWildEncounter\n\t"
        "	movs r0, #1\n\t"
        "	bl sub_080EE470\n\t"
        "	ldr r0, _0808C700\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl DestroyTask\n\t"
        "_0808C6F0:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C6FC: .4byte 0x02037230\n\t"
        "_0808C700: .4byte 0x0808C225\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_NotEvenNibble(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r5, r0, #0\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	ldr r0, _0808C768\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808C76C\n\t"
        "	adds r4, r4, r0\n\t"
        "	bl GetPlayerFacingDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetWalkInPlaceSlowMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r2, _0808C770\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #1\n\t"
        "	bl AddTextPrinterParameterized2\n\t"
        "	movs r0, #0xd\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	movs r0, #1\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C768: .4byte 0x02037230\n\t"
        "_0808C76C: .4byte 0x020205AC\n\t"
        "_0808C770: .4byte gUnknown_846F9DC + 0x1B\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_GotAway(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, lr}\n\t"
        "	sub sp, #0x10\n\t"
        "	adds r5, r0, #0\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	ldr r0, _0808C7D8\n\t"
        "	ldrb r0, [r0, #4]\n\t"
        "	lsls r4, r0, #4\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808C7DC\n\t"
        "	adds r4, r4, r0\n\t"
        "	bl GetPlayerFacingDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl GetWalkInPlaceSlowMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl StartSpriteAnim\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #0x11\n\t"
        "	bl FillWindowPixelBuffer\n\t"
        "	ldr r2, _0808C7E0\n\t"
        "	movs r0, #0\n\t"
        "	str r0, [sp]\n\t"
        "	movs r0, #2\n\t"
        "	str r0, [sp, #4]\n\t"
        "	movs r0, #1\n\t"
        "	str r0, [sp, #8]\n\t"
        "	movs r0, #3\n\t"
        "	str r0, [sp, #0xc]\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	movs r3, #1\n\t"
        "	bl AddTextPrinterParameterized2\n\t"
        "	ldrh r0, [r5, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	movs r0, #1\n\t"
        "	add sp, #0x10\n\t"
        "	pop {r4, r5}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C7D8: .4byte 0x02037230\n\t"
        "_0808C7DC: .4byte 0x020205AC\n\t"
        "_0808C7E0: .4byte gUnknown_846F9DC + 0x27\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_NoMon(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	adds r4, r0, #0\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	ldrh r0, [r4, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r4, #8]\n\t"
        "	movs r0, #0\n\t"
        "	pop {r4}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_PutRodAway(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	adds r6, r0, #0\n\t"
        "	bl AlignFishingAnimationFrames\n\t"
        "	ldr r7, _0808C890\n\t"
        "	ldr r5, _0808C894\n\t"
        "	ldrb r0, [r5, #4]\n\t"
        "	lsls r1, r0, #4\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	adds r1, r1, r7\n\t"
        "	adds r1, #0x3f\n\t"
        "	ldrb r0, [r1]\n\t"
        "	lsls r0, r0, #0x1b\n\t"
        "	cmp r0, #0\n\t"
        "	bge _0808C882\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	lsls r4, r0, #3\n\t"
        "	adds r4, r4, r0\n\t"
        "	lsls r4, r4, #2\n\t"
        "	ldr r0, _0808C898\n\t"
        "	mov r8, r0\n\t"
        "	add r4, r8\n\t"
        "	ldrh r1, [r6, #0x24]\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventSetGraphicsId\n\t"
        "	ldrb r1, [r4, #0x18]\n\t"
        "	lsrs r1, r1, #4\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl EventObjectTurn\n\t"
        "	ldrb r1, [r5]\n\t"
        "	movs r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C862\n\t"
        "	ldrb r0, [r5, #5]\n\t"
        "	lsls r1, r0, #3\n\t"
        "	adds r1, r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	add r1, r8\n\t"
        "	ldrb r0, [r1, #0x1a]\n\t"
        "	movs r1, #0\n\t"
        "	movs r2, #0\n\t"
        "	bl SetSurfBlob_PlayerOffset\n\t"
        "_0808C862:\n\t"
        "	ldrb r1, [r5, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	movs r2, #0\n\t"
        "	strh r2, [r0, #0x24]\n\t"
        "	ldrb r1, [r5, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r7\n\t"
        "	strh r2, [r0, #0x26]\n\t"
        "	ldrh r0, [r6, #8]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r6, #8]\n\t"
        "_0808C882:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C890: .4byte 0x020205AC\n\t"
        "_0808C894: .4byte 0x02037230\n\t"
        "_0808C898: .4byte 0x02036FF0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Fishing_EndNoMon(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	bl RunTextPrinters\n\t"
        "	movs r0, #0\n\t"
        "	bl IsTextPrinterActive\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	lsrs r1, r0, #0x10\n\t"
        "	cmp r1, #0\n\t"
        "	bne _0808C8D8\n\t"
        "	ldr r0, _0808C8E0\n\t"
        "	strb r1, [r0, #6]\n\t"
        "	bl UnlockPlayerFieldControls\n\t"
        "	bl UnfreezeObjectEvents\n\t"
        "	movs r0, #0\n\t"
        "	movs r1, #1\n\t"
        "	bl ClearDialogWindowAndFrame\n\t"
        "	movs r0, #0\n\t"
        "	bl sub_080EE470\n\t"
        "	ldr r0, _0808C8E4\n\t"
        "	bl FindTaskIdByFunc\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl DestroyTask\n\t"
        "_0808C8D8:\n\t"
        "	movs r0, #0\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808C8E0: .4byte 0x02037230\n\t"
        "_0808C8E4: .4byte 0x0808C225\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void AlignFishingAnimationFrames(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	ldr r0, _0808C9D4\n\t"
        "	ldrb r1, [r0, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808C9D8\n\t"
        "	adds r4, r0, r1\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl AnimateSprite\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r4, #0x24]\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x2b\n\t"
        "	ldrb r5, [r0]\n\t"
        "	movs r0, #0x2a\n\t"
        "	adds r0, r0, r4\n\t"
        "	mov ip, r0\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, [r4, #8]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	lsls r6, r5, #2\n\t"
        "	adds r0, r6, r0\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	movs r7, #1\n\t"
        "	rsbs r7, r7, #0\n\t"
        "	cmp r0, r7\n\t"
        "	beq _0808C95A\n\t"
        "	adds r3, r4, #0\n\t"
        "	adds r3, #0x2c\n\t"
        "	ldrb r2, [r3]\n\t"
        "	lsls r1, r2, #0x1a\n\t"
        "	lsrs r1, r1, #0x1a\n\t"
        "	adds r1, #1\n\t"
        "	movs r0, #0x3f\n\t"
        "	ands r1, r0\n\t"
        "	movs r0, #0x40\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r3]\n\t"
        "	mov r1, ip\n\t"
        "	ldrb r0, [r1]\n\t"
        "	ldr r1, [r4, #8]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r0, [r0]\n\t"
        "	adds r0, r6, r0\n\t"
        "	movs r1, #0\n\t"
        "	ldrsh r0, [r0, r1]\n\t"
        "	cmp r0, r7\n\t"
        "	bne _0808C960\n\t"
        "_0808C95A:\n\t"
        "	subs r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r5, r0, #0x18\n\t"
        "_0808C960:\n\t"
        "	adds r0, r4, #0\n\t"
        "	adds r0, #0x2a\n\t"
        "	ldrb r0, [r0]\n\t"
        "	ldr r1, [r4, #8]\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldr r1, [r0]\n\t"
        "	lsls r0, r5, #2\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r5, [r0]\n\t"
        "	subs r0, r5, #1\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #2\n\t"
        "	bhi _0808C992\n\t"
        "	movs r0, #8\n\t"
        "	strh r0, [r4, #0x24]\n\t"
        "	bl GetPlayerFacingDirection\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #3\n\t"
        "	bne _0808C992\n\t"
        "	ldr r0, _0808C9DC\n\t"
        "	strh r0, [r4, #0x24]\n\t"
        "_0808C992:\n\t"
        "	cmp r5, #5\n\t"
        "	bne _0808C99A\n\t"
        "	ldr r0, _0808C9DC\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "_0808C99A:\n\t"
        "	adds r0, r5, #0\n\t"
        "	subs r0, #0xa\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r0, #1\n\t"
        "	bhi _0808C9AA\n\t"
        "	movs r0, #8\n\t"
        "	strh r0, [r4, #0x26]\n\t"
        "_0808C9AA:\n\t"
        "	ldr r3, _0808C9D4\n\t"
        "	ldrb r1, [r3]\n\t"
        "	movs r0, #8\n\t"
        "	ands r0, r1\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808C9CE\n\t"
        "	ldr r2, _0808C9E0\n\t"
        "	ldrb r1, [r3, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	ldrb r0, [r0, #0x1a]\n\t"
        "	movs r1, #0x26\n\t"
        "	ldrsh r2, [r4, r1]\n\t"
        "	movs r1, #1\n\t"
        "	bl SetSurfBlob_PlayerOffset\n\t"
        "_0808C9CE:\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808C9D4: .4byte 0x02037230\n\t"
        "_0808C9D8: .4byte 0x020205AC\n\t"
        "_0808C9DC: .4byte 0x0000FFF8\n\t"
        "_0808C9E0: .4byte 0x02036FF0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808C9E4(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	ldr r1, _0808C9EC\n\t"
        "	strb r0, [r1]\n\t"
        "	bx lr\n\t"
        "	.align 2, 0\n\t"
        "_0808C9EC: .4byte 0x02036FEC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808C9F0(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r1, _0808CA00\n\t"
        "	ldrb r0, [r1]\n\t"
        "	cmp r0, #0\n\t"
        "	bne _0808C9FC\n\t"
        "	movs r0, #1\n\t"
        "_0808C9FC:\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808CA00: .4byte 0x02036FEC\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_DoPlayerSpinExit(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, r8\n\t"
        "	push {r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	adds r2, r0, #0\n\t"
        "	ldr r0, _0808CA48\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808CA4C\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrb r1, [r4, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808CA50\n\t"
        "	adds r7, r0, r1\n\t"
        "	lsls r0, r2, #2\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0808CA54\n\t"
        "	adds r5, r0, r1\n\t"
        "	movs r0, #0\n\t"
        "	ldrsh r6, [r5, r0]\n\t"
        "	cmp r6, #1\n\t"
        "	beq _0808CABA\n\t"
        "	cmp r6, #1\n\t"
        "	bgt _0808CA58\n\t"
        "	cmp r6, #0\n\t"
        "	beq _0808CA5E\n\t"
        "	b _0808CAFA\n\t"
        "	.align 2, 0\n\t"
        "_0808CA48: .4byte 0x02037230\n\t"
        "_0808CA4C: .4byte 0x02036FF0\n\t"
        "_0808CA50: .4byte 0x020205AC\n\t"
        "_0808CA54: .4byte 0x03005B68\n\t"
        "_0808CA58:\n\t"
        "	cmp r6, #2\n\t"
        "	beq _0808CAF4\n\t"
        "	b _0808CAFA\n\t"
        "_0808CA5E:\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventClearHeldMovementIfFinished\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808CAFA\n\t"
        "	ldrb r0, [r4, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	bl sub_0808C9E4\n\t"
        "	movs r1, #0\n\t"
        "	mov r8, r1\n\t"
        "	strh r6, [r5, #2]\n\t"
        "	movs r0, #1\n\t"
        "	strh r0, [r5, #4]\n\t"
        "	ldrh r0, [r7, #0x26]\n\t"
        "	ldrh r2, [r7, #0x22]\n\t"
        "	adds r0, r0, r2\n\t"
        "	lsls r0, r0, #4\n\t"
        "	strh r0, [r5, #6]\n\t"
        "	strh r6, [r7, #0x26]\n\t"
        "	bl CameraObjectReset2\n\t"
        "	ldrb r0, [r4, #3]\n\t"
        "	movs r1, #4\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r4, #3]\n\t"
        "	ldrb r1, [r7, #5]\n\t"
        "	movs r0, #0xd\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r7, #5]\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r0, #0x43\n\t"
        "	mov r1, r8\n\t"
        "	strb r1, [r0]\n\t"
        "	adds r2, r7, #0\n\t"
        "	adds r2, #0x42\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x3f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5]\n\t"
        "_0808CABA:\n\t"
        "	adds r1, r5, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_0808CCFC\n\t"
        "	ldrh r0, [r5, #6]\n\t"
        "	ldrh r1, [r5, #4]\n\t"
        "	subs r0, r0, r1\n\t"
        "	strh r0, [r5, #6]\n\t"
        "	adds r1, #3\n\t"
        "	strh r1, [r5, #4]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x14\n\t"
        "	strh r0, [r7, #0x22]\n\t"
        "	movs r2, #0x22\n\t"
        "	ldrsh r1, [r7, r2]\n\t"
        "	ldr r0, _0808CAF0\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r0, r2]\n\t"
        "	adds r1, r1, r0\n\t"
        "	movs r0, #0x20\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	cmp r1, r0\n\t"
        "	bge _0808CAFA\n\t"
        "	ldrh r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5]\n\t"
        "	b _0808CAFA\n\t"
        "	.align 2, 0\n\t"
        "_0808CAF0: .4byte 0x03005B48\n\t"
        "_0808CAF4:\n\t"
        "	adds r0, r2, #0\n\t"
        "	bl DestroyTask\n\t"
        "_0808CAFA:\n\t"
        "	pop {r3}\n\t"
        "	mov r8, r3\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DoPlayerSpinEntrance(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _0808CB20\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808CB20: .4byte 0x0808CB6D\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void IsPlayerSpinEntranceActive(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0808CB34\n\t"
        "	bl FuncIsActiveTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808CB34: .4byte 0x0808CB6D\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void DoPlayerSpinExit(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, lr}\n\t"
        "	ldr r4, _0808CB54\n\t"
        "	adds r0, r4, #0\n\t"
        "	movs r1, #0\n\t"
        "	bl CreateTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	bl _call_via_r4\n\t"
        "	pop {r4}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        "_0808CB54: .4byte 0x0808CA05\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void IsPlayerSpinExitActive(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {lr}\n\t"
        "	ldr r0, _0808CB68\n\t"
        "	bl FuncIsActiveTask\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        "	.align 2, 0\n\t"
        "_0808CB68: .4byte 0x0808CA05\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void Task_DoPlayerSpinEntrance(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, r7, lr}\n\t"
        "	mov r7, sb\n\t"
        "	mov r6, r8\n\t"
        "	push {r6, r7}\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	mov r8, r0\n\t"
        "	ldr r0, _0808CBB4\n\t"
        "	ldrb r1, [r0, #5]\n\t"
        "	lsls r0, r1, #3\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808CBB8\n\t"
        "	adds r4, r0, r1\n\t"
        "	ldrb r1, [r4, #4]\n\t"
        "	lsls r0, r1, #4\n\t"
        "	adds r0, r0, r1\n\t"
        "	lsls r0, r0, #2\n\t"
        "	ldr r1, _0808CBBC\n\t"
        "	adds r7, r0, r1\n\t"
        "	mov r1, r8\n\t"
        "	lsls r0, r1, #2\n\t"
        "	add r0, r8\n\t"
        "	lsls r0, r0, #3\n\t"
        "	ldr r1, _0808CBC0\n\t"
        "	adds r5, r0, r1\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r6, [r5, r2]\n\t"
        "	cmp r6, #1\n\t"
        "	beq _0808CC4E\n\t"
        "	cmp r6, #1\n\t"
        "	bgt _0808CBC4\n\t"
        "	cmp r6, #0\n\t"
        "	beq _0808CBCE\n\t"
        "	b _0808CCEE\n\t"
        "	.align 2, 0\n\t"
        "_0808CBB4: .4byte 0x02037230\n\t"
        "_0808CBB8: .4byte 0x02036FF0\n\t"
        "_0808CBBC: .4byte 0x020205AC\n\t"
        "_0808CBC0: .4byte 0x03005B68\n\t"
        "_0808CBC4:\n\t"
        "	cmp r6, #2\n\t"
        "	beq _0808CC8C\n\t"
        "	cmp r6, #3\n\t"
        "	beq _0808CCAA\n\t"
        "	b _0808CCEE\n\t"
        "_0808CBCE:\n\t"
        "	bl sub_0808C9F0\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	strh r0, [r5, #0xa]\n\t"
        "	ldr r1, _0808CC88\n\t"
        "	movs r3, #0xa\n\t"
        "	ldrsh r0, [r5, r3]\n\t"
        "	adds r0, r0, r1\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl ObjectEventForceSetHeldMovement\n\t"
        "	movs r0, #0\n\t"
        "	mov sb, r0\n\t"
        "	strh r6, [r5, #2]\n\t"
        "	movs r0, #0x74\n\t"
        "	strh r0, [r5, #4]\n\t"
        "	ldrh r0, [r7, #0x22]\n\t"
        "	strh r0, [r5, #8]\n\t"
        "	ldrb r0, [r7, #5]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1e\n\t"
        "	strh r0, [r5, #0xc]\n\t"
        "	movs r1, #0x43\n\t"
        "	adds r1, r1, r7\n\t"
        "	mov r8, r1\n\t"
        "	ldrb r0, [r1]\n\t"
        "	strh r0, [r5, #0xe]\n\t"
        "	ldrh r0, [r7, #0x26]\n\t"
        "	adds r0, #0x20\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	lsls r0, r0, #4\n\t"
        "	strh r0, [r5, #6]\n\t"
        "	strh r6, [r7, #0x26]\n\t"
        "	bl CameraObjectReset2\n\t"
        "	ldrb r0, [r4, #3]\n\t"
        "	movs r2, #4\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r4, #3]\n\t"
        "	ldrb r1, [r7, #5]\n\t"
        "	movs r0, #0xd\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	orrs r0, r2\n\t"
        "	strb r0, [r7, #5]\n\t"
        "	mov r3, sb\n\t"
        "	mov r2, r8\n\t"
        "	strb r3, [r2]\n\t"
        "	adds r2, r7, #0\n\t"
        "	adds r2, #0x42\n\t"
        "	ldrb r1, [r2]\n\t"
        "	movs r0, #0x3f\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r2]\n\t"
        "	ldrh r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5]\n\t"
        "_0808CC4E:\n\t"
        "	adds r1, r5, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_0808CCFC\n\t"
        "	ldrh r0, [r5, #4]\n\t"
        "	ldrh r2, [r5, #6]\n\t"
        "	adds r1, r0, r2\n\t"
        "	strh r1, [r5, #6]\n\t"
        "	subs r0, #3\n\t"
        "	strh r0, [r5, #4]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #3\n\t"
        "	bgt _0808CC6E\n\t"
        "	movs r0, #4\n\t"
        "	strh r0, [r5, #4]\n\t"
        "_0808CC6E:\n\t"
        "	ldrh r0, [r5, #6]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x14\n\t"
        "	strh r0, [r7, #0x22]\n\t"
        "	ldrh r2, [r5, #8]\n\t"
        "	movs r3, #8\n\t"
        "	ldrsh r1, [r5, r3]\n\t"
        "	cmp r0, r1\n\t"
        "	blt _0808CCEE\n\t"
        "	strh r2, [r7, #0x22]\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r5, #0x10]\n\t"
        "	b _0808CCA2\n\t"
        "	.align 2, 0\n\t"
        "_0808CC88: .4byte gUnknown_846FA13\n\t"
        "_0808CC8C:\n\t"
        "	adds r1, r5, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_0808CCFC\n\t"
        "	ldrh r0, [r5, #0x10]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5, #0x10]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #8\n\t"
        "	ble _0808CCEE\n\t"
        "_0808CCA2:\n\t"
        "	ldrh r0, [r5]\n\t"
        "	adds r0, #1\n\t"
        "	strh r0, [r5]\n\t"
        "	b _0808CCEE\n\t"
        "_0808CCAA:\n\t"
        "	movs r0, #0xa\n\t"
        "	ldrsh r6, [r5, r0]\n\t"
        "	adds r1, r5, #2\n\t"
        "	adds r0, r4, #0\n\t"
        "	bl sub_0808CCFC\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	lsrs r0, r0, #0x18\n\t"
        "	cmp r6, r0\n\t"
        "	bne _0808CCEE\n\t"
        "	ldrb r1, [r4, #3]\n\t"
        "	movs r0, #5\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r1\n\t"
        "	strb r0, [r4, #3]\n\t"
        "	movs r0, #3\n\t"
        "	ldrb r1, [r5, #0xc]\n\t"
        "	ands r1, r0\n\t"
        "	lsls r1, r1, #2\n\t"
        "	ldrb r2, [r7, #5]\n\t"
        "	movs r0, #0xd\n\t"
        "	rsbs r0, r0, #0\n\t"
        "	ands r0, r2\n\t"
        "	orrs r0, r1\n\t"
        "	strb r0, [r7, #5]\n\t"
        "	ldrh r1, [r5, #0xe]\n\t"
        "	adds r0, r7, #0\n\t"
        "	adds r0, #0x43\n\t"
        "	strb r1, [r0]\n\t"
        "	bl CameraObjectReset\n\t"
        "	mov r0, r8\n\t"
        "	bl DestroyTask\n\t"
        "_0808CCEE:\n\t"
        "	pop {r3, r4}\n\t"
        "	mov r8, r3\n\t"
        "	mov sb, r4\n\t"
        "	pop {r4, r5, r6, r7}\n\t"
        "	pop {r0}\n\t"
        "	bx r0\n\t"
        "	.align 2, 0\n\t"
        ".syntax divided\n\t"
    );
}

__attribute__((naked)) void sub_0808CCFC(void)
{
    __asm__(".syntax unified\n\t"
        ".code 16\n\t"
        "	push {r4, r5, r6, lr}\n\t"
        "	adds r5, r0, #0\n\t"
        "	adds r6, r1, #0\n\t"
        "	ldrh r1, [r6]\n\t"
        "	movs r2, #0\n\t"
        "	ldrsh r0, [r6, r2]\n\t"
        "	cmp r0, #7\n\t"
        "	bgt _0808CD18\n\t"
        "	adds r0, r1, #1\n\t"
        "	strh r0, [r6]\n\t"
        "	lsls r0, r0, #0x10\n\t"
        "	asrs r0, r0, #0x10\n\t"
        "	cmp r0, #7\n\t"
        "	ble _0808CD54\n\t"
        "_0808CD18:\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventCheckHeldMovementStatus\n\t"
        "	lsls r0, r0, #0x18\n\t"
        "	cmp r0, #0\n\t"
        "	beq _0808CD54\n\t"
        "	ldr r4, _0808CD50\n\t"
        "	ldrb r0, [r5, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	bl GetFaceDirectionMovementAction\n\t"
        "	adds r1, r0, #0\n\t"
        "	lsls r1, r1, #0x18\n\t"
        "	lsrs r1, r1, #0x18\n\t"
        "	adds r0, r5, #0\n\t"
        "	bl ObjectEventForceSetHeldMovement\n\t"
        "	movs r0, #0\n\t"
        "	strh r0, [r6]\n\t"
        "	ldrb r0, [r5, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "	adds r0, r0, r4\n\t"
        "	ldrb r0, [r0]\n\t"
        "	b _0808CD5A\n\t"
        "	.align 2, 0\n\t"
        "_0808CD50: .4byte gUnknown_846FA13\n\t"
        "_0808CD54:\n\t"
        "	ldrb r0, [r5, #0x18]\n\t"
        "	lsls r0, r0, #0x1c\n\t"
        "	lsrs r0, r0, #0x1c\n\t"
        "_0808CD5A:\n\t"
        "	pop {r4, r5, r6}\n\t"
        "	pop {r1}\n\t"
        "	bx r1\n\t"
        ".syntax divided\n\t"
    );
}
#endif
