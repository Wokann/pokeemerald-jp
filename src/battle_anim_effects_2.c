#include "global.h"
#include "malloc.h"
#include "battle_anim.h"
#include "battle_interface.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "main.h"
#include "math_util.h"
#include "palette.h"
#include "random.h"
#include "scanline_effect.h"
#include "sound.h"
#include "trig.h"
#include "util.h"
#include "constants/rgb.h"
#include "constants/songs.h"

void TranslateSpriteInEllipseOverDuration(struct Sprite *sprite);
void SetSpriteNextToMonHead(u8 battler, struct Sprite *sprite);

static void AnimTask_Withdraw_Step(u8 taskId);
static void AnimKinesisZapEnergy(struct Sprite *sprite);
static void AnimSwordsDanceBlade(struct Sprite *sprite);
static void AnimSwordsDanceBlade_Step(struct Sprite *sprite);
static void AnimSonicBoomProjectile(struct Sprite *sprite);
static void AnimCirclingFinger(struct Sprite *sprite);
static void AnimBouncingMusicNote(struct Sprite *sprite);
static void AnimBouncingMusicNote_Step(struct Sprite *sprite);
static void AnimVibrateBattlerBack_Step(struct Sprite *sprite);
static void AnimVibrateBattlerBack(struct Sprite *sprite);
static void AnimMovingClamp(struct Sprite *sprite);
static void AnimMovingClamp_Step(struct Sprite *sprite);
static void AnimMovingClamp_End(struct Sprite *sprite);

// Rotates the attacking mon sprite downwards and then back upwards to its original position.
// No args.
void AnimTask_Withdraw(u8 taskId)
{
    PrepareBattlerSpriteForRotScale(gBattlerSpriteIds[gBattleAnimAttacker], ST_OAM_OBJ_NORMAL);
    gTasks[taskId].func = AnimTask_Withdraw_Step;
}

static void AnimTask_Withdraw_Step(u8 taskId)
{
    u8 spriteId = gBattlerSpriteIds[gBattleAnimAttacker];
    s16 rotation;
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        rotation = -gTasks[taskId].data[0];
    else
        rotation = gTasks[taskId].data[0];

    SetSpriteRotScale(spriteId, 0x100, 0x100, rotation);
    if (gTasks[taskId].data[1] == 0)
    {
        gTasks[taskId].data[0] += 0xB0;
        // this y position update gets overwritten by SetBattlerSpriteYOffsetFromRotation()
        gSprites[spriteId].y2++;
    }
    else if (gTasks[taskId].data[1] == 1)
    {
        if (++gTasks[taskId].data[3] == 30)
            gTasks[taskId].data[1] = 2;

        return;
    }
    else
    {
        gTasks[taskId].data[0] -= 0xB0;
        // this y position update gets overwritten by SetBattlerSpriteYOffsetFromRotation()
        gSprites[spriteId].y2--;
    }

    SetBattlerSpriteYOffsetFromRotation(spriteId);
    if (gTasks[taskId].data[0] == 0xF20 || gTasks[taskId].data[0] == 0)
    {
        if (gTasks[taskId].data[1] == 2)
        {
            ResetSpriteRotScale(spriteId);
            DestroyAnimVisualTask(taskId);
        }
        else
        {
            gTasks[taskId].data[1]++;
        }
    }
}

// Animates a "zap of energy" used in KINESIS.
// arg 0: x pixel offset
// arg 1: y pixel offset
// arg 2: vertical flip
static void AnimKinesisZapEnergy(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    sprite->y += gBattleAnimArgs[1];
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->hFlip = 1;
        if (gBattleAnimArgs[2])
            sprite->vFlip = 1;
    }
    else
    {
        if (gBattleAnimArgs[2])
            sprite->vFlip = 1;
    }

    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Animates a sword that rises into the air after a brief pause.
// arg 0: x pixel offset
// arg 1: y pixel offset
static void AnimSwordsDanceBlade(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
    StoreSpriteCallbackInData6(sprite, AnimSwordsDanceBlade_Step);
}

static void AnimSwordsDanceBlade_Step(struct Sprite *sprite)
{
    sprite->data[0] = 6;
    sprite->data[2] = sprite->x;
    sprite->data[4] = sprite->y - 32;
    // JP calls InitAndRunAnimFastLinearTranslation (0x080A67B5) here.
    sprite->callback = InitAndRunAnimFastLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Animates a projectile that flies through the air in a straight line.
// arg 0: x pixel offset
// arg 1: y pixel offset
// arg 2: target x pixel offset
// arg 3: target y pixel offset
// arg 4: speed
static void AnimSonicBoomProjectile(struct Sprite *sprite)
{
    s16 targetXPos;
    s16 targetYPos;
    u16 rotation;

    if (IsContest())
    {
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
    }
    else if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
    }

    InitSpritePosToAnimAttacker(sprite, TRUE);
    targetXPos = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + gBattleAnimArgs[2];
    targetYPos = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + gBattleAnimArgs[3];
    rotation = ArcTan2Neg(targetXPos - sprite->x, targetYPos - sprite->y);
    rotation -= 0x1000;
    if (IsContest())
        rotation -= 0x6000;

    TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, rotation);
    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = targetXPos;
    sprite->data[4] = targetYPos;
    // JP calls InitAndRunAnimFastLinearTranslation (0x080A67B5) here.
    sprite->callback = InitAndRunAnimFastLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

#define sAmplitudeX  data[1]
#define sCircleSpeed data[2]
#define sMoveSteps   data[3]
#define sAmplitudeY  data[4]

// Animates a finger circling around the attacker.
// arg 0: x pixel offset
// arg 1: y pixel offset
// arg 2: x amplitude
// arg 3: y amplitude
// arg 4: speed
// arg 5: number of loops
static void AnimCirclingFinger(struct Sprite *sprite)
{
    SetSpriteCoordsToAnimAttackerCoords(sprite);
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
    sprite->sAmplitudeX = gBattleAnimArgs[2];
    sprite->sCircleSpeed = gBattleAnimArgs[4];
    sprite->sMoveSteps = gBattleAnimArgs[5];
    sprite->sAmplitudeY = gBattleAnimArgs[3];
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    // JP calls TranslateSpriteInEllipseOverDuration (0x080A5D18).
    sprite->callback = TranslateSpriteInEllipseOverDuration;
    sprite->callback(sprite);
}

#undef sAmplitudeX
#undef sCircleSpeed
#undef sMoveSteps
#undef sAmplitudeY

// Animates a music note bouncing up and down.
// arg 0: 0 = attacker, 1 = target
static void AnimBouncingMusicNote(struct Sprite *sprite)
{
    u8 battler;
    if (gBattleAnimArgs[0] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    SetSpriteNextToMonHead(battler, sprite);
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->callback = AnimBouncingMusicNote_Step;
}

static void AnimBouncingMusicNote_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        sprite->y2 -= 3;
        if (++sprite->data[1] == 6)
            sprite->data[0]++;
        break;
    case 1:
        sprite->y2 += 3;
        if (--sprite->data[1] == 0)
            sprite->data[0]++;
        break;
    case 2:
        if (++sprite->data[1] == 64)
            DestroyAnimSprite(sprite);
        break;
    }
}

static void AnimVibrateBattlerBack_Step(struct Sprite *sprite)
{
    s16 temp;
    gSprites[sprite->data[2]].x2 += sprite->data[1];
    temp = sprite->data[1];
    sprite->data[1] = -temp;
    if (sprite->data[0] == 0)
    {
        gSprites[sprite->data[2]].x2 = 0;
        DestroySpriteAndMatrix(sprite);
    }

    sprite->data[0]--;
}

// Animates the battler's back vibrating.
// arg 0: x pixel offset
// arg 1: y pixel offset
// arg 2: times to vibrate
// arg 3: amplitude of vibration
static void AnimVibrateBattlerBack(struct Sprite *sprite)
{
    u8 spriteId;
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    spriteId = gBattlerSpriteIds[gBattleAnimTarget];
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= gBattleAnimArgs[0];
    else
        sprite->x += gBattleAnimArgs[0];

    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = spriteId;
    sprite->callback = AnimVibrateBattlerBack_Step;
    sprite->invisible = TRUE;
}

// Animates a clamp on the target, that stays for a moment before disappearing.
// arg 0: x pixel offset
// arg 1: y pixel offset
// arg 2: x destination
// arg 3: y destination
// arg 4: duration
static void AnimMovingClamp(struct Sprite *sprite)
{
    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[5] = gBattleAnimArgs[4];
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, AnimMovingClamp_Step);
}

static void AnimMovingClamp_Step(struct Sprite *sprite)
{
    sprite->data[0] = sprite->data[1];
    sprite->data[2] = sprite->x;
    sprite->data[4] = sprite->y + 15;
    // JP calls InitAndRunAnimFastLinearTranslation (0x080A67B5) here.
    sprite->callback = InitAndRunAnimFastLinearTranslation;
    StoreSpriteCallbackInData6(sprite, AnimMovingClamp_End);
}

static void AnimMovingClamp_End(struct Sprite *sprite)
{
    if (sprite->data[5] == 0)
        DestroyAnimSprite(sprite);
    else
        sprite->data[5]--;
}
