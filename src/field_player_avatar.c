#include "global.h"
#include "bike.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "overworld.h"
#include "random.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"

#define NUM_FORCED_MOVEMENTS 18

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
