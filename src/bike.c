#include "global.h"
#include "global.fieldmap.h"
#include "bike.h"

static void Bike_SetBikeStill(void)
{
    gPlayerAvatar.bikeFrameCounter = 0;
    gPlayerAvatar.bikeSpeed = PLAYER_SPEED_STANDING;
}

extern void PlayerFaceDirection(u8 direction);

static void AcroBikeTransition_TurnJump(u8 direction)
{
    PlayerFaceDirection(direction);
}
