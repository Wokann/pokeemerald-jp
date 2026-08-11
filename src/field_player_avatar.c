#include "global.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "overworld.h"
#include "random.h"
#include "rotating_gate.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"

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

bool8 ForcedMovement_0xBB(void) // JP: mat jump
{
    DoPlayerMatJump();
    return TRUE;
}

bool8 ForcedMovement_0xBC(void) // JP: mat spin
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
