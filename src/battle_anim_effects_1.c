#include "global.h"
#include "malloc.h"
#include "battle_anim.h"
#include "battle_anim_internal.h"
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

extern const struct SpriteTemplate gSolarBeamSmallOrbSpriteTemplate;

static void AnimMovePowderParticle(struct Sprite *sprite);
static void AnimMovePowderParticle_Step(struct Sprite *sprite);
static void AnimPowerAbsorptionOrb(struct Sprite *sprite);
static void AnimSolarBeamBigOrb(struct Sprite *sprite);
static void AnimSolarBeamSmallOrb(struct Sprite *sprite);
static void AnimSolarBeamSmallOrb_Step(struct Sprite *sprite);
void AnimTask_CreateSmallSolarBeamOrbs(u8 taskId);
static void AnimAbsorptionOrb(struct Sprite *sprite);
static void AnimAbsorptionOrb_Step(struct Sprite *sprite);
static void AnimHyperBeamOrb(struct Sprite *sprite);
static void AnimHyperBeamOrb_Step(struct Sprite *sprite);

// Sprinkles powder over the target mon.
// arg 0: x pixel offset
// arg 1: y pixel offset
// arg 2: duration
// arg 3: y velocity
// arg 4: wave amplitude
// arg 5: wave speed
static void AnimMovePowderParticle(struct Sprite *sprite)
{
    CMD_ARGS(x, y, duration, yVelocity, waveAmplitude, waveSpeed);

    sprite->x += cmd->x;
    sprite->y += cmd->y;
    sprite->data[0] = cmd->duration;
    sprite->data[1] = cmd->yVelocity;

    if (GetBattlerSide(gBattleAnimAttacker))
        sprite->data[3] = -cmd->waveAmplitude;
    else
        sprite->data[3] = cmd->waveAmplitude;

    sprite->data[4] = cmd->waveSpeed;
    sprite->callback = AnimMovePowderParticle_Step;
}

static void AnimMovePowderParticle_Step(struct Sprite *sprite)
{
    if (sprite->data[0] > 0)
    {
        sprite->data[0]--;
        sprite->y2 = sprite->data[2] >> 8;
        sprite->data[2] += sprite->data[1];
        sprite->x2 = Sin(sprite->data[5], sprite->data[3]);
        sprite->data[5] = (sprite->data[5] + sprite->data[4]) & 0xFF;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

// Moves an energy orb towards the center of the mon.
static void AnimPowerAbsorptionOrb(struct Sprite *sprite)
{
    CMD_ARGS(x, y, duration);

    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = cmd->duration;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    // JP calls InitAndRunAnimFastLinearTranslation (0x080A67B5) here.
    sprite->callback = InitAndRunAnimFastLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
}

// Moves an orb in a straight line towards the target mon.
static void AnimSolarBeamBigOrb(struct Sprite *sprite)
{
    CMD_ARGS(x, y, duration, animation);

    InitSpritePosToAnimAttacker(sprite, TRUE);
    StartSpriteAnim(sprite, cmd->animation);
    sprite->data[0] = cmd->duration;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    // JP calls InitAndRunAnimFastLinearTranslation (0x080A67B5) here.
    sprite->callback = InitAndRunAnimFastLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Moves a small orb in a wavy pattern towards the target mon.
static void AnimSolarBeamSmallOrb(struct Sprite *sprite)
{
    CMD_ARGS(x, y, duration, waveOffset);

    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = cmd->duration;
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = cmd->waveOffset;
    sprite->callback = AnimSolarBeamSmallOrb_Step;
    sprite->callback(sprite);
}

static void AnimSolarBeamSmallOrb_Step(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
    {
        DestroySprite(sprite);
    }
    else
    {
        if (sprite->data[5] > 0x7F)
            sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) + 1;
        else
            sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimTarget) + 6;

        sprite->x2 += Sin(sprite->data[5], 5);
        sprite->y2 += Cos(sprite->data[5], 14);
        sprite->data[5] = (sprite->data[5] + 15) & 0xFF;
    }
}

// Creates 15 small secondary orbs used in the SolarBeam anim effect.
void AnimTask_CreateSmallSolarBeamOrbs(u8 taskId)
{
    if (--gTasks[taskId].data[0] == -1)
    {
        gTasks[taskId].data[1]++;
        gTasks[taskId].data[0] = 6;
        gBattleAnimArgs[0] = 15;
        gBattleAnimArgs[1] = 0;
        gBattleAnimArgs[2] = 80;
        gBattleAnimArgs[3] = 0;
        CreateSpriteAndAnimate(&gSolarBeamSmallOrbSpriteTemplate, 0, 0, GetBattlerSpriteSubpriority(gBattleAnimTarget) + 1);
    }

    if (gTasks[taskId].data[1] == 15)
        DestroyAnimVisualTask(taskId);
}

// Moves an orb from the target mon to the attacking mon in an arc-like fashion.
static void AnimAbsorptionOrb(struct Sprite *sprite)
{
    CMD_ARGS(x, y, waveAmplitude, wavePeriod);

    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = cmd->wavePeriod;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[5] = cmd->waveAmplitude;
    InitAnimArcTranslation(sprite);
    sprite->callback = AnimAbsorptionOrb_Step;
}

static void AnimAbsorptionOrb_Step(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

// Moves an orb in a wave-like fashion towards the target mon.
static void AnimHyperBeamOrb(struct Sprite *sprite)
{
    u16 speed;
    u16 animNum = Random2();

    StartSpriteAnim(sprite, animNum % 8);
    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= 20;
    else
        sprite->x += 20;

    speed = Random2();
    sprite->data[0] = (speed & 31) + 64;
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    InitAnimFastLinearTranslationWithSpeed(sprite);
    sprite->data[5] = Random2() & 0xFF;
    sprite->data[6] = sprite->subpriority;
    sprite->callback = AnimHyperBeamOrb_Step;
    sprite->callback(sprite);
}

static void AnimHyperBeamOrb_Step(struct Sprite *sprite)
{
    if (AnimFastTranslateLinear(sprite))
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        sprite->y2 += Cos(sprite->data[5], 12);
        if (sprite->data[5] < 0x7F)
            sprite->subpriority = sprite->data[6];
        else
            sprite->subpriority = sprite->data[6] + 1;

        sprite->data[5] += 24;
        sprite->data[5] &= 0xFF;
    }
}
