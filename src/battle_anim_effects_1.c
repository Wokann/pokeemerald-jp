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
extern const s8 gTrickBagCoordinates[][3];
extern const struct SpriteTemplate gLeafBladeSpriteTemplate;
extern const u16 gMagicalLeafBlendColors[];
struct {
    s16 startX;
    s16 startY;
    s16 targetX;
    s16 targetY;
} extern sFrenzyPlantRootData;

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
static void AnimLeechSeed(struct Sprite *sprite);
static void AnimLeechSeed_Step(struct Sprite *sprite);
static void AnimLeechSeedSprouts(struct Sprite *sprite);
static void AnimSporeParticle(struct Sprite *sprite);
static void AnimSporeParticle_Step(struct Sprite *sprite);
void AnimTask_SporeDoubleBattle(u8 taskId);
static void AnimPetalDanceBigFlower(struct Sprite *sprite);
static void AnimPetalDanceBigFlower_Step(struct Sprite *sprite);
static void AnimPetalDanceSmallFlower(struct Sprite *sprite);
static void AnimPetalDanceSmallFlower_Step(struct Sprite *sprite);
static void AnimRazorLeafParticle(struct Sprite *sprite);
static void AnimRazorLeafParticle_Step1(struct Sprite *sprite);
static void AnimRazorLeafParticle_Step2(struct Sprite *sprite);
static void AnimTranslateLinearSingleSineWave(struct Sprite *sprite);
static void AnimTranslateLinearSingleSineWave_Step(struct Sprite *sprite);
void AnimMoveTwisterParticle(struct Sprite *sprite);
static void AnimMoveTwisterParticle_Step(struct Sprite *sprite);
static void AnimConstrictBinding(struct Sprite *sprite);
static void AnimConstrictBinding_Step1(struct Sprite *sprite);
static void AnimConstrictBinding_Step2(struct Sprite *sprite);
void AnimTask_ShrinkTargetCopy(u8 taskId);
static void AnimTask_DuplicateAndShrinkToPos_Step1(u8 taskId);
static void AnimTask_DuplicateAndShrinkToPos_Step2(u8 taskId);
static void AnimMimicOrb(struct Sprite *sprite);
static void AnimIngrainRoot(struct Sprite *sprite);
static void AnimFrenzyPlantRoot(struct Sprite *sprite);
static void AnimRootFlickerOut(struct Sprite *sprite);
static void AnimIngrainOrb(struct Sprite *sprite);
static void InitItemBagData(struct Sprite *sprite, s16 c);
bool8 moveAlongLinearPath(struct Sprite *sprite);
static void AnimItemSteal_Step2(struct Sprite *sprite);
static void AnimItemSteal_Step1(struct Sprite *sprite);
static void AnimPresent(struct Sprite *sprite);
static void AnimKnockOffOpponentsItem(struct Sprite *sprite);
static void AnimKnockOffItem(struct Sprite *sprite);
static void AnimPresentHealParticle(struct Sprite *sprite);
static void AnimItemSteal(struct Sprite *sprite);
static void AnimItemSteal_Step3(struct Sprite *sprite);
static void AnimTrickBag(struct Sprite *sprite);
static void AnimTrickBag_Step1(struct Sprite *sprite);
static void AnimTrickBag_Step2(struct Sprite *sprite);
static void AnimTrickBag_Step3(struct Sprite *sprite);
void AnimTask_LeafBlade(u8 taskId);
static void AnimTask_LeafBlade_Step(u8 taskId);
static s16 LeafBladeGetPosFactor(struct Sprite *sprite);
static void AnimTask_LeafBlade_Step2(struct Task *task, u8 taskId);
static void AnimTask_LeafBlade_Step2_Callback(struct Sprite *sprite);
static void AnimFlyingParticle(struct Sprite *sprite);
static void AnimFlyingParticle_Step(struct Sprite *sprite);
void AnimTask_CycleMagicalLeafPal(u8 taskId);
static void AnimNeedleArmSpike(struct Sprite *sprite);
static void AnimNeedleArmSpike_Step(struct Sprite *sprite);
static void AnimWhipHit_WaitEnd(struct Sprite *sprite);
static void AnimSlidingHit(struct Sprite *sprite);
static void AnimWhipHit(struct Sprite *sprite);
static void AnimFlickeringPunch(struct Sprite *sprite);
static void AnimCuttingSlice(struct Sprite *sprite);
static void AnimAirCutterSlice(struct Sprite *sprite);
static void AnimSlice_Step(struct Sprite *sprite);
static void UNUSED UnusedFlickerAnim(struct Sprite *sprite);
static void AnimCirclingMusicNote(struct Sprite *sprite);
static void AnimCirclingMusicNote_Step(struct Sprite *sprite);
static void AnimProtect(struct Sprite *sprite);
static void AnimProtect_Step(struct Sprite *sprite);
static void AnimMilkBottle(struct Sprite *sprite);
static void AnimMilkBottle_Step1(struct Sprite *sprite);
static void AnimMilkBottle_Step2(struct Sprite *sprite, int unk1, int unk2);
static void AnimGrantingStars(struct Sprite *sprite);
static void AnimSparklingStars(struct Sprite *sprite);
static void AnimBubbleBurst(struct Sprite *sprite);
static void AnimBubbleBurst_Step(struct Sprite *sprite);
static void AnimSleepLetterZ(struct Sprite *sprite);
static void AnimSleepLetterZ_Step(struct Sprite *sprite);

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

static void AnimLeechSeed(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY, targetX, targetY, duration, waveAmplitude);

    InitSpritePosToAnimAttacker(sprite, TRUE);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        cmd->targetX = -cmd->targetX;

    sprite->data[0] = cmd->duration;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) + cmd->targetX;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + cmd->targetY;
    sprite->data[5] = cmd->waveAmplitude;
    InitAnimArcTranslation(sprite);
    sprite->callback = AnimLeechSeed_Step;
}

static void AnimLeechSeed_Step(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->invisible = TRUE;
        sprite->data[0] = 10;
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, AnimLeechSeedSprouts);
    }
}

static void AnimLeechSeedSprouts(struct Sprite *sprite)
{
    sprite->invisible = FALSE;
    StartSpriteAnim(sprite, 1);
    sprite->data[0] = 60;
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Moves a spore particle in a halo around the target mon.
static void AnimSporeParticle(struct Sprite *sprite)
{
    CMD_ARGS(x, y, waveOffset, duration, blend);

    InitSpritePosToAnimTarget(sprite, TRUE);
    StartSpriteAnim(sprite, cmd->blend);
    if (cmd->blend == TRUE)
        sprite->oam.objMode = ST_OAM_OBJ_BLEND;

    sprite->data[0] = cmd->duration;
    sprite->data[1] = cmd->waveOffset;
    sprite->callback = AnimSporeParticle_Step;
    sprite->callback(sprite);
}

static void AnimSporeParticle_Step(struct Sprite *sprite)
{
    sprite->x2 = Sin(sprite->data[1], 32);
    sprite->y2 = Cos(sprite->data[1], -3) + ((sprite->data[2] += 24) >> 8);
    if ((u16)(sprite->data[1] - 0x40) < 0x80)
    {
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
    }
    else
    {
        u8 priority = GetBattlerSpriteBGPriority(gBattleAnimTarget) + 1;
        if (priority > 3)
            priority = 3;

        sprite->oam.priority = priority;
    }

    sprite->data[1] += 2;
    sprite->data[1] &= 0xFF;
    if (--sprite->data[0] == -1)
        DestroyAnimSprite(sprite);
}

// In a double battle, Updates the mon sprite background priorities to allow
// the circling effect controlled by AnimSporeParticle.
void AnimTask_SporeDoubleBattle(u8 taskId)
{
    if (IsContest() || !IsDoubleBattle())
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        if (GetBattlerSpriteBGPriorityRank(gBattleAnimTarget) == 1)
            SetAnimBgAttribute(2, BG_ANIM_PRIORITY, 3);
        else
            SetAnimBgAttribute(1, BG_ANIM_PRIORITY, 1);

        DestroyAnimVisualTask(taskId);
    }
}

// Rotates a big flower around the attacking mon, and slowly floats downward.
static void AnimPetalDanceBigFlower(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY, targetY, duration);

    InitSpritePosToAnimAttacker(sprite, FALSE);
    sprite->data[0] = cmd->duration;
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x;
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + cmd->targetY;
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = 0x40;
    sprite->callback = AnimPetalDanceBigFlower_Step;
    sprite->callback(sprite);
}

static void AnimPetalDanceBigFlower_Step(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->x2 += Sin(sprite->data[5], 32);
        sprite->y2 += Cos(sprite->data[5], -5);
        if ((u16)(sprite->data[5] - 0x40) < 0x80)
            sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) - 1;
        else
            sprite->subpriority = GetBattlerSpriteSubpriority(gBattleAnimAttacker) + 1;

        sprite->data[5] = (sprite->data[5] + 5) & 0xFF;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

// Slowly floats a small flower downward, while swaying from right to left.
static void AnimPetalDanceSmallFlower(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY, targetY, duration);

    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = cmd->duration;
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x;
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + cmd->targetY;
    InitAnimLinearTranslation(sprite);
    sprite->data[5] = 0x40;
    sprite->callback = AnimPetalDanceSmallFlower_Step;
    sprite->callback(sprite);
}

static void AnimPetalDanceSmallFlower_Step(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->x2 += Sin(sprite->data[5], 8);
        if ((u16)(sprite->data[5] - 59) < 5 || (u16)(sprite->data[5] - 187) < 5)
            sprite->oam.matrixNum ^= ST_OAM_HFLIP;

        sprite->data[5] += 5;
        sprite->data[5] &= 0xFF;
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

// Shoots a leaf upward, then floats it downward while swaying back and forth.
static void AnimRazorLeafParticle(struct Sprite *sprite)
{
    CMD_ARGS(upwardDeltaX, upwardDeltaY, upwardDuration);

    sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[0] = cmd->upwardDeltaX;
    sprite->data[1] = cmd->upwardDeltaY;
    sprite->data[2] = cmd->upwardDuration;
    sprite->callback = AnimRazorLeafParticle_Step1;
}

static void AnimRazorLeafParticle_Step1(struct Sprite *sprite)
{
    if (!sprite->data[2])
    {
        if (sprite->data[1] & 1)
        {
            sprite->data[0] = 0x80;
            sprite->data[1] = 0;
            sprite->data[2] = 0;
        }
        else
        {
            sprite->data[0] = 0;
            sprite->data[1] = 0;
            sprite->data[2] = 0;
        }
        sprite->callback = AnimRazorLeafParticle_Step2;
    }
    else
    {
        sprite->data[2]--;
        sprite->x += sprite->data[0];
        sprite->y += sprite->data[1];
    }
}

static void AnimRazorLeafParticle_Step2(struct Sprite *sprite)
{
    if (GetBattlerSide(gBattleAnimAttacker))
        sprite->x2 = -Sin(sprite->data[0], 25);
    else
        sprite->x2 = Sin(sprite->data[0], 25);

    sprite->data[0] += 2;
    sprite->data[0] &= 0xFF;
    sprite->data[1]++;
    if (!(sprite->data[1] & 1))
        // JP increments y2 instead of toggling between 2/-2.
        sprite->y2++;

    // JP destroys the sprite at y > 80 (US uses 64).
    if (sprite->data[1] > 80)
        DestroyAnimSprite(sprite);
}

// Animates a sprite that moves linearly from one location to another, with a
// single-cycle sine wave added to the y position along the way.
static void AnimTranslateLinearSingleSineWave(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY, targetX, targetY, duration, waveAmplitude, targetBoth);

    InitSpritePosToAnimAttacker(sprite, TRUE);
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        cmd->targetX = -cmd->targetX;

    sprite->data[0] = cmd->duration;
    if (!cmd->targetBoth)
    {
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + cmd->targetX;
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + cmd->targetY;
    }
    else
    {
        SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->data[2], &sprite->data[4]);
        sprite->data[2] += cmd->targetX;
        sprite->data[4] += cmd->targetY;
    }

    sprite->data[5] = cmd->waveAmplitude;
    InitAnimArcTranslation(sprite);
    if (GetBattlerSide(gBattleAnimAttacker) == GetBattlerSide(gBattleAnimTarget))
        sprite->data[0] = 1;
    else
        sprite->data[0] = 0;

    sprite->callback = AnimTranslateLinearSingleSineWave_Step;
}

static void AnimTranslateLinearSingleSineWave_Step(struct Sprite *sprite)
{
    bool8 destroy = FALSE;
    s16 a = sprite->data[0];
    s16 b = sprite->data[7];
    s16 r0;

    sprite->data[0] = 1;
    TranslateAnimHorizontalArc(sprite);
    r0 = sprite->data[7];
    sprite->data[0] = a;
    if (b > 200 && r0 < 56 && sprite->oam.affineParam == 0)
        sprite->oam.affineParam++;

    if (sprite->oam.affineParam && sprite->data[0])
    {
        sprite->invisible ^= 1;
        sprite->oam.affineParam++;
        if (sprite->oam.affineParam == 30)
            destroy = TRUE;
    }

    if (sprite->x + sprite->x2 > DISPLAY_WIDTH + 16
     || sprite->x + sprite->x2 < -16
     || sprite->y + sprite->y2 > DISPLAY_HEIGHT
     || sprite->y + sprite->y2 < -16)
        destroy = TRUE;

    if (destroy)
        DestroyAnimSprite(sprite);
}

// Animates particles in the Twister move animation.
void AnimMoveTwisterParticle(struct Sprite *sprite)
{
    CMD_ARGS(duration, distanceY, wavePeriod, waveAmplitude, speedUpOnFrame);

    if (IsDoubleBattle() == TRUE)
        SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->x, &sprite->y);

    sprite->y += 32;
    sprite->data[0] = cmd->duration;
    sprite->data[1] = cmd->distanceY;
    sprite->data[2] = cmd->wavePeriod;
    sprite->data[3] = cmd->waveAmplitude;
    sprite->data[4] = cmd->speedUpOnFrame;
    sprite->callback = AnimMoveTwisterParticle_Step;
}

static void AnimMoveTwisterParticle_Step(struct Sprite *sprite)
{
    if (sprite->data[1] == 0xFF)
    {
        sprite->y -= 2;
    }
    else if (sprite->data[1] > 0)
    {
        sprite->y -= 2;
        sprite->data[1] -= 2;
    }

    sprite->data[5] += sprite->data[2];
    if (sprite->data[0] < sprite->data[4])
        sprite->data[5] += sprite->data[2];

    sprite->data[5] &= 0xFF;
    sprite->x2 = Cos(sprite->data[5], sprite->data[3]);
    sprite->y2 = Sin(sprite->data[5], 5);
    if (sprite->data[5] < 0x80)
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget) - 1;
    else
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget) + 1;

    if (--sprite->data[0] == 0)
        DestroyAnimSprite(sprite);
}

// Squeezes a constricting "rope" several times via affine animations.
static void AnimConstrictBinding(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY, affineAnimation, squeezes);

    InitSpritePosToAnimTarget(sprite, FALSE);
    sprite->affineAnimPaused = 1;
    StartSpriteAffineAnim(sprite, cmd->affineAnimation);
    sprite->data[6] = cmd->affineAnimation;
    sprite->data[7] = cmd->squeezes;
    sprite->callback = AnimConstrictBinding_Step1;
}

static void AnimConstrictBinding_Step1(struct Sprite *sprite)
{
    u8 UNUSED spriteId;

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
    {
        sprite->affineAnimPaused = 0;
        spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
        sprite->data[0] = 0x100;
        sprite->callback = AnimConstrictBinding_Step2;
    }
}

static void AnimConstrictBinding_Step2(struct Sprite *sprite)
{
    u8 UNUSED spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    if (!sprite->data[2])
        sprite->data[0] += 11;
    else
        sprite->data[0] -= 11;

    if (++sprite->data[1] == 6)
    {
        sprite->data[1] = 0;
        sprite->data[2] ^= 1;
    }

    if (sprite->affineAnimEnded)
    {
        if (--sprite->data[7] > 0)
            StartSpriteAffineAnim(sprite, sprite->data[6]);
        else
            DestroyAnimSprite(sprite);
    }
}

// unk1 may be some sort of duration?
void AnimTask_ShrinkTargetCopy(u8 taskId)
{
    CMD_ARGS(unk0, unk1);

    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    if (gSprites[spriteId].invisible)
    {
        DestroyAnimVisualTask(taskId);
    }
    else
    {
        PrepareBattlerSpriteForRotScale(spriteId, ST_OAM_OBJ_BLEND);
        gTasks[taskId].data[14] = gSprites[spriteId].oam.priority;
        gSprites[spriteId].oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
        spriteId = GetAnimBattlerSpriteId(ANIM_DEF_PARTNER);
        gTasks[taskId].data[15] = gSprites[spriteId].oam.priority;
        gSprites[spriteId].oam.priority = GetBattlerSpriteBGPriority(BATTLE_PARTNER(gBattleAnimTarget));
        gTasks[taskId].data[0] = cmd->unk0;
        gTasks[taskId].data[1] = cmd->unk1;
        gTasks[taskId].data[11] = 0x100;
        gTasks[taskId].func = AnimTask_DuplicateAndShrinkToPos_Step1;
    }
}

static void AnimTask_DuplicateAndShrinkToPos_Step1(u8 taskId)
{
    u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
    gTasks[taskId].data[10] += gTasks[taskId].data[0];
    gSprites[spriteId].x2 = gTasks[taskId].data[10] >> 8;
    if (GetBattlerSide(gBattleAnimTarget) != B_SIDE_PLAYER)
        gSprites[spriteId].x2 = -gSprites[spriteId].x2;

    gTasks[taskId].data[11] += 16;
    SetSpriteRotScale(spriteId, gTasks[taskId].data[11], gTasks[taskId].data[11], 0);
    SetBattlerSpriteYOffsetFromYScale(spriteId);
    if (--gTasks[taskId].data[1] == 0)
    {
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].func = AnimTask_DuplicateAndShrinkToPos_Step2;
    }
}

static void AnimTask_DuplicateAndShrinkToPos_Step2(u8 taskId)
{
    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
    {
        if (gTasks[taskId].data[0] == 0)
        {
            u8 spriteId = GetAnimBattlerSpriteId(ANIM_TARGET);
            ResetSpriteRotScale(spriteId);
            gSprites[spriteId].x2 = 0;
            gSprites[spriteId].y2 = 0;
            gSprites[spriteId].oam.priority = gTasks[taskId].data[14];
            spriteId = GetAnimBattlerSpriteId(ANIM_DEF_PARTNER);
            gSprites[spriteId].oam.priority = gTasks[taskId].data[15];
            gTasks[taskId].data[0]++;
            return;
        }
    }
    else
    {
        if (gTasks[taskId].data[0] == 0)
            return;
    }

    gTasks[taskId].data[0]++;
    if (gTasks[taskId].data[0] == 3)
        DestroyAnimVisualTask(taskId);
}

// Moves an orb from the target mon to the attacking mon.
static void AnimMimicOrb(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY);

    switch (sprite->data[0])
    {
    case 0:
        if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
            cmd->initialX *= -1;

        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) + cmd->initialX;
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + cmd->initialY;
        sprite->invisible = TRUE;
        sprite->data[0]++;
        break;
    case 1:
        sprite->invisible = FALSE;
        if (sprite->affineAnimEnded)
        {
            ChangeSpriteAffineAnim(sprite, 1);
            sprite->data[0] = 25;
            sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
            sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
            // JP calls StartAnimLinearTranslation (0x080A6989) here.
            sprite->callback = StartAnimLinearTranslation;
            StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
            break;
        }
    }
}

// Animates a root that flickers away after some time.
static void AnimIngrainRoot(struct Sprite *sprite)
{
    CMD_ARGS(offsetX, offsetY, subpriorityM30, animation, duration);

    if (!sprite->data[0])
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
        sprite->x2 = cmd->offsetX;
        sprite->y2 = cmd->offsetY;
        sprite->subpriority = cmd->subpriorityM30 + 30;
        StartSpriteAnim(sprite, cmd->animation);
        sprite->data[2] = cmd->duration;
        sprite->data[0]++;
        if (sprite->y + sprite->y2 > 120)
            sprite->y += sprite->y2 + sprite->y - 120;
    }
    sprite->callback = AnimRootFlickerOut;
}

// Places a root on the path to the target mon that flickers away after some time.
static void AnimFrenzyPlantRoot(struct Sprite *sprite)
{
    CMD_ARGS(interpolatePercent, offsetX, offsetY, subpriorityM30, animation, duration);

    s16 attackerX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
    s16 attackerY = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
    s16 targetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    s16 targetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

    targetX -= attackerX;
    targetY -= attackerY;
    sprite->x = attackerX + targetX * cmd->interpolatePercent / 100;
    sprite->y = attackerY + targetY * cmd->interpolatePercent / 100;
    sprite->x2 = cmd->offsetX;
    sprite->y2 = cmd->offsetY;
    sprite->subpriority = cmd->subpriorityM30 + 30;
    StartSpriteAnim(sprite, cmd->animation);
    sprite->data[2] = cmd->duration;
    sprite->callback = AnimRootFlickerOut;
    sFrenzyPlantRootData.startX = sprite->x;
    sFrenzyPlantRootData.startY = sprite->y;
    sFrenzyPlantRootData.targetX = targetX;
    sFrenzyPlantRootData.targetY = targetY;
}

static void AnimRootFlickerOut(struct Sprite *sprite)
{
    if (++sprite->data[0] > (sprite->data[2] - 10))
        sprite->invisible = sprite->data[0] % 2;

    // JP destroys the sprite when data[0] exceeds data[2] (US uses ==).
    if (sprite->data[0] > sprite->data[2])
        DestroyAnimSprite(sprite);
}

// Moves an orb in a fast wavy path.
static void AnimIngrainOrb(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY, velocityX, waveAmplitude, duration);

    if (!sprite->data[0])
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2) + cmd->initialX;
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + cmd->initialY;
        sprite->data[1] = cmd->velocityX;
        sprite->data[2] = cmd->waveAmplitude;
        sprite->data[3] = cmd->duration;
    }

    sprite->data[0]++;
    sprite->x2 = sprite->data[1] * sprite->data[0];
    sprite->y2 = Sin((sprite->data[0] * 20) & 0xFF, sprite->data[2]);
    if (sprite->data[0] > sprite->data[3])
        DestroyAnimSprite(sprite);
}

static void InitItemBagData(struct Sprite *sprite, s16 c)
{
    int a = (sprite->x << 8) | sprite->y;
    int b = (sprite->data[6] << 8) | sprite->data[7];
    c <<= 8;
    sprite->data[5] = a;
    sprite->data[6] = b;
    sprite->data[7] = c;
}

bool8 moveAlongLinearPath(struct Sprite *sprite)
{
    u16 xStartPos = (u8)(sprite->data[5] >> 8);
    u16 yStartPos = (u8)sprite->data[5];
    s32 xEndPos = (u8)(sprite->data[6] >> 8);
    s32 yEndPos = (u8)sprite->data[6];
    s16 totalTime = sprite->data[7] >> 8;
    s16 currentTime = sprite->data[7] & 0xFF;
    s16 yEndPos_2;
    s16 r0;
    s32 var1;
    s32 vaxEndPos;

    if (xEndPos == 0)
        xEndPos = -32;
    else if (xEndPos == 255)
        xEndPos = DISPLAY_WIDTH + 32;

    yEndPos_2 = yEndPos - yStartPos;
    r0 = xEndPos - xStartPos;
    var1 = r0 * currentTime / totalTime;
    vaxEndPos = yEndPos_2 * currentTime / totalTime;
    sprite->x = var1 + xStartPos;
    sprite->y = vaxEndPos + yStartPos;
    if (++currentTime == totalTime)
        return TRUE;

    sprite->data[7] = (totalTime << 8) | currentTime;
    return FALSE;
}

static void AnimItemSteal_Step2(struct Sprite *sprite)
{
    if (sprite->data[0] == 10)
        StartSpriteAffineAnim(sprite, 1);

    sprite->data[0]++;
    if (sprite->data[0] > 50)
        DestroyAnimSprite(sprite);
}

static void AnimItemSteal_Step1(struct Sprite *sprite)
{
    sprite->data[0] += sprite->data[3] * 128 / sprite->data[4];
    if (sprite->data[0] >= 128)
    {
        sprite->data[1]++;
        sprite->data[0] = 0;
    }

    sprite->y2 = Sin(sprite->data[0] + 128, 30 - sprite->data[1] * 8);
    if (moveAlongLinearPath(sprite))
    {
        sprite->y2 = 0;
        sprite->data[0] = 0;
        sprite->callback = AnimItemSteal_Step2;
    }
}

static void AnimPresent(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY, unk2, unk3, unk4);

    s16 targetX;
    s16 targetY;
    InitSpritePosToAnimAttacker(sprite, FALSE);
    targetX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    targetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    if (BATTLE_PARTNER(gBattleAnimAttacker) == gBattleAnimTarget)
    {
        sprite->data[6] = targetX;
        sprite->data[7] = targetY + 10;
        InitItemBagData(sprite, 60);
        sprite->data[3] = 1;
    }
    else
    {
        sprite->data[6] = targetX;
        sprite->data[7] = targetY + 10;
        InitItemBagData(sprite, 60);
        sprite->data[3] = 3;
    }

    sprite->data[4] = 60;
    sprite->callback = AnimItemSteal_Step1;
}

static void AnimKnockOffOpponentsItem(struct Sprite *sprite)
{
    sprite->data[0] += ((sprite->data[3] * 128) / sprite->data[4]);
    if (sprite->data[0] > 0x7F)
    {
        sprite->data[1]++;
        sprite->data[0] = 0;
    }

    sprite->y2 = Sin(sprite->data[0] + 0x80, 30 - sprite->data[1] * 8);
    if (moveAlongLinearPath(sprite))
    {
        sprite->y2 = 0;
        sprite->data[0] = 0;
        DestroyAnimSprite(sprite);
    }
}

static void AnimKnockOffItem(struct Sprite *sprite)
{
    s16 targetY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
    {
        sprite->data[6] = 0;
        sprite->data[7] = targetY + 10;
        InitItemBagData(sprite, 40);
        sprite->data[3] = 3;
        sprite->data[4] = 60;
        sprite->callback = AnimItemSteal_Step1;
    }
    else
    {
        sprite->data[6] = 255;
        sprite->data[7] = targetY + 10;
        if (IsContest())
            sprite->data[6] = 0;

        InitItemBagData(sprite, 40);
        sprite->data[3] = 3;
        sprite->data[4] = 60;
        sprite->callback = AnimKnockOffOpponentsItem;
    }
}

// Animates a heal particle upward.
static void AnimPresentHealParticle(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY, velocityY, unused3);

    if (!sprite->data[0])
    {
        InitSpritePosToAnimTarget(sprite, FALSE);
        sprite->data[1] = cmd->velocityY;
    }

    sprite->data[0]++;
    sprite->y2 = sprite->data[1] * sprite->data[0];
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void AnimItemSteal(struct Sprite *sprite)
{
    CMD_ARGS(initialX, initialY);

    s16 attackerX;
    s16 attackerY;
    InitSpritePosToAnimTarget(sprite, FALSE);
    attackerX = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
    attackerY = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    if (BATTLE_PARTNER(gBattleAnimTarget) == gBattleAnimAttacker)
    {
        sprite->data[6] = attackerX;
        sprite->data[7] = attackerY + 10;
        InitItemBagData(sprite, 60);
        sprite->data[3] = 1;
    }
    else
    {
        sprite->data[6] = attackerX;
        sprite->data[7] = attackerY + 10;
        InitItemBagData(sprite, 60);
        sprite->data[3] = 3;
    }

    sprite->data[4] = 60;
    sprite->callback = AnimItemSteal_Step3;
}

static void AnimItemSteal_Step3(struct Sprite *sprite)
{
    sprite->data[0] += ((sprite->data[3] * 128) / sprite->data[4]);
    if (sprite->data[0] > 127)
    {
        sprite->data[1]++;
        sprite->data[0] = 0;
    }

    sprite->y2 = Sin(sprite->data[0] + 0x80, 30 - sprite->data[1] * 8);
    if (sprite->y2 == 0)
        PlaySE12WithPanning(SE_M_BUBBLE2, BattleAnimAdjustPanning(SOUND_PAN_TARGET));

    if (moveAlongLinearPath(sprite))
    {
        sprite->y2 = 0;
        sprite->data[0] = 0;
        sprite->callback = AnimItemSteal_Step2;
        PlaySE12WithPanning(SE_M_BUBBLE2, BattleAnimAdjustPanning(SOUND_PAN_ATTACKER));
    }
}

// Moves a bag in a circular motion.
static void AnimTrickBag(struct Sprite *sprite)
{
    CMD_ARGS(initialY, waveOffset);

    if (!sprite->data[0])
    {
        if (!IsContest())
        {
            sprite->data[1] = cmd->waveOffset;
            sprite->x = 120;
        }
        else
        {
            sprite->data[1] = (cmd->waveOffset - 32) % 256;
            sprite->x = 70;
        }

        sprite->y = cmd->initialY;
        sprite->data[2] = cmd->initialY;
        sprite->data[4] = 20;
        sprite->x2 = Cos(sprite->data[1], 60);
        sprite->y2 = Sin(sprite->data[1], 20);
        sprite->callback = AnimTrickBag_Step1;
        if (sprite->data[1] > 0 && sprite->data[1] < 192)
            sprite->subpriority = 31;
        else
            sprite->subpriority = 29;
    }
}

static void AnimTrickBag_Step1(struct Sprite *sprite)
{
    switch (sprite->data[3])
    {
    case 0:
        if (sprite->data[2] > 78)
        {
            sprite->data[3] = 1;
            StartSpriteAffineAnim(sprite, 1);
            break;
        }
        else
        {
            sprite->data[2] += sprite->data[4] / 10;
            sprite->data[4] += 3;
            sprite->y = sprite->data[2];
            break;
        }
        break;
    case 1:
        if (sprite->data[3] && sprite->affineAnimEnded)
        {
            sprite->data[0] = 0;
            sprite->data[2] = 0;
            sprite->callback = AnimTrickBag_Step2;
        }
        break;
    }
}

static void AnimTrickBag_Step2(struct Sprite *sprite)
{
    if (sprite->data[2] == gTrickBagCoordinates[sprite->data[0]][1])
    {
        if (gTrickBagCoordinates[sprite->data[0]][2] == 127)
        {
            sprite->data[0] = 0;
            sprite->callback = AnimTrickBag_Step3;
        }

        sprite->data[2] = 0;
        sprite->data[0]++;
    }
    else
    {
        sprite->data[2]++;
        sprite->data[1] = (gTrickBagCoordinates[sprite->data[0]][0] * gTrickBagCoordinates[sprite->data[0]][2] + sprite->data[1]) & 0xFF;
        if (!IsContest())
        {
            if ((u16)(sprite->data[1] - 1) < 191)
                sprite->subpriority = 31;
            else
                sprite->subpriority = 29;
        }

        sprite->x2 = Cos(sprite->data[1], 60);
        sprite->y2 = Sin(sprite->data[1], 20);
    }
}

static void AnimTrickBag_Step3(struct Sprite *sprite)
{
    if (sprite->data[0] > 20)
        DestroyAnimSprite(sprite);

    sprite->invisible = sprite->data[0] % 2;
    sprite->data[0]++;
}

void AnimTask_LeafBlade(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    task->data[4] = GetBattlerSpriteSubpriority(gBattleAnimTarget) - 1;
    task->data[6] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    task->data[7] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    task->data[10] = GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_WIDTH);
    task->data[11] = GetBattlerSpriteCoordAttr(gBattleAnimTarget, BATTLER_COORD_ATTR_HEIGHT);
    task->data[5] = (GetBattlerSide(gBattleAnimTarget) == B_SIDE_OPPONENT) ? 1 : -1;
    task->data[9] = 56 - (task->data[5] * 64);
    task->data[8] = task->data[7] - task->data[9] + task->data[6];
    task->data[2] = CreateSprite(&gLeafBladeSpriteTemplate, task->data[8], task->data[9], task->data[4]);
    if (task->data[2] == MAX_SPRITES)
        DestroyAnimVisualTask(taskId);

    gSprites[task->data[2]].data[0] = 10;
    gSprites[task->data[2]].data[1] = task->data[8];
    gSprites[task->data[2]].data[2] = task->data[6] - (task->data[10] / 2 + 10) * task->data[5];
    gSprites[task->data[2]].data[3] = task->data[9];
    gSprites[task->data[2]].data[4] = task->data[7] + (task->data[11] / 2 + 10) * task->data[5];
    gSprites[task->data[2]].data[5] = LeafBladeGetPosFactor(&gSprites[task->data[2]]);
    InitAnimArcTranslation(&gSprites[task->data[2]]);
    task->func = AnimTask_LeafBlade_Step;
}

static void AnimTask_LeafBlade_Step(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    struct Sprite *sprite = &gSprites[task->data[2]];
    int a = task->data[0];
    switch (a)
    {
    case 4:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 5;
            task->data[0] = 0xFF;
        }
        break;
    case 8:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 9;
            task->data[0] = 0xFF;
        }
        break;
    case 0:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 1;
            task->data[0] = 0xFF;
        }
        break;
    case 1:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[6];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[7];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[4] += 2;
        task->data[3] = a;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    case 2:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 3;
            task->data[0] = 0xFF;
        }
        break;
    case 3:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[6] - ((task->data[10] / 2) + 10) * task->data[5];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[7] - ((task->data[11] / 2) + 10) * task->data[5];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[3] = 2;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    case 5:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[6] + ((task->data[10] / 2) + 10) * task->data[5];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[7] + ((task->data[11] / 2) + 10) * task->data[5];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[4] -= 2;
        task->data[3] = 3;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    case 6:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 7;
            task->data[0] = 0xFF;
        }
        break;
    case 7:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[6];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[7];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[4] += 2;
        task->data[3] = 4;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    case 9:
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[6] - ((task->data[10] / 2) + 10) * task->data[5];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[7] + ((task->data[11] / 2) + 10) * task->data[5];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[3] = 5;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    case 10:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            task->data[15] = 11;
            task->data[0] = 0xFF;
        }
        break;
    case 11:
    {
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->x2 = 0;
        sprite->y2 = 0;
        sprite->data[0] = 10;
        sprite->data[1] = sprite->x;
        sprite->data[2] = task->data[8];
        sprite->data[3] = sprite->y;
        sprite->data[4] = task->data[9];
        sprite->data[5] = LeafBladeGetPosFactor(sprite);
        task->data[4] -= 2;
        task->data[3] = 6;
        sprite->subpriority = task->data[4];
        StartSpriteAnim(sprite, task->data[3]);
        InitAnimArcTranslation(sprite);
        task->data[0]++;
        break;
    }
    case 12:
        AnimTask_LeafBlade_Step2(task, taskId);
        if (TranslateAnimHorizontalArc(sprite))
        {
            DestroySprite(sprite);
            task->data[0]++;
        }
        break;
    case 13:
        if (task->data[12] == 0)
            DestroyAnimVisualTask(taskId);
        break;
    case 0xFF:
        if (++task->data[1] > 5)
        {
            task->data[1] = 0;
            task->data[0] = task->data[15];
        }
        break;
    }
}

static s16 LeafBladeGetPosFactor(struct Sprite *sprite)
{
    s16 var = 8;
    if (sprite->data[4] < sprite->y)
        var = -var;

    return var;
}

static void AnimTask_LeafBlade_Step2(struct Task *task, u8 taskId)
{
    task->data[14]++;
    if (task->data[14] > 0)
    {
        u8 spriteId;
        s16 spriteX;
        s16 spriteY;
        task->data[14] = 0;
        spriteX = gSprites[task->data[2]].x + gSprites[task->data[2]].x2;
        spriteY = gSprites[task->data[2]].y + gSprites[task->data[2]].y2;
        spriteId = CreateSprite(&gLeafBladeSpriteTemplate, spriteX, spriteY, task->data[4]);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].data[6] = taskId;
            gSprites[spriteId].data[7] = 12;
            gTasks[taskId].data[12]++;
            gSprites[spriteId].data[0] = task->data[13] & 1;
            gTasks[taskId].data[13]++;
            StartSpriteAnim(&gSprites[spriteId], task->data[3]);
            gSprites[spriteId].subpriority = task->data[4];
            gSprites[spriteId].callback = AnimTask_LeafBlade_Step2_Callback;
        }
    }
}

static void AnimTask_LeafBlade_Step2_Callback(struct Sprite *sprite)
{
    sprite->data[0]++;
    if (sprite->data[0] > 1)
    {
        sprite->data[0] = 0;
        sprite->invisible ^= 1;
        sprite->data[1]++;
        if (sprite->data[1] > 8)
        {
            gTasks[sprite->data[6]].data[sprite->data[7]]--;
            DestroySprite(sprite);
        }
    }
}

static void AnimFlyingParticle(struct Sprite *sprite)
{
    // unk6 chooses an anchor?
    // unk3 is probably some sort of y offset relative to the center of
    // the screen?
    // unk5 is some kind of mode. it affects priority and y.
    CMD_ARGS(unk0, unk1, unk2, unk3, unk4, unk5, unk6);

    u8 battler;
    if (!cmd->unk6)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    if (GetBattlerSide(battler) != B_SIDE_PLAYER)
    {
        sprite->data[4] = 0;
        sprite->data[2] = cmd->unk3;
        sprite->x = -16;
    }
    else
    {
        sprite->data[4] = 1;
        sprite->data[2] = -cmd->unk3;
        sprite->x = DISPLAY_WIDTH + 16;
    }

    sprite->data[1] = cmd->unk1;
    sprite->data[0] = cmd->unk2;
    sprite->data[3] = cmd->unk4;
    switch (cmd->unk5)
    {
    case 0:
        sprite->y = cmd->unk0;
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler);
        break;
    case 1:
        sprite->y = cmd->unk0;
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler) + 1;
        break;
    case 2:
        sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET) + cmd->unk0;
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler);
        break;
    case 3:
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + cmd->unk0;
        GetAnimBattlerSpriteId(ANIM_TARGET);
        sprite->oam.priority = GetBattlerSpriteBGPriority(battler) + 1;
        break;
    }

    sprite->callback = AnimFlyingParticle_Step;
}

static void AnimFlyingParticle_Step(struct Sprite *sprite)
{
    int a = sprite->data[7];
    sprite->data[7]++;
    sprite->y2 = (sprite->data[1] * gSineTable[sprite->data[0]]) >> 8;
    sprite->x2 = sprite->data[2] * a;
    sprite->data[0] = (sprite->data[3] * a) & 0xFF;
    if (!sprite->data[4])
    {
        if (sprite->x2 + sprite->x < DISPLAY_WIDTH + 8)
            return;
    }
    else
    {
        if (sprite->x2 + sprite->x > -16)
            return;
    }

    DestroySpriteAndMatrix(sprite);
}

void AnimTask_CycleMagicalLeafPal(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    switch (task->data[0])
    {
    case 0:
        task->data[8] = OBJ_PLTT_ID(IndexOfSpritePaletteTag(ANIM_TAG_LEAF));
        task->data[12] = OBJ_PLTT_ID(IndexOfSpritePaletteTag(ANIM_TAG_RAZOR_LEAF));
        task->data[0]++;
        break;
    case 1:
        if (++task->data[9] >= 0)
        {
            task->data[9] = 0;
            BlendPalette(task->data[8], 16, task->data[10], gMagicalLeafBlendColors[task->data[11]]);
            BlendPalette(task->data[12], 16, task->data[10], gMagicalLeafBlendColors[task->data[11]]);
            if (++task->data[10] == 17)
            {
                task->data[10] = 0;
                if (++task->data[11] == 7)
                    task->data[11] = 0;
            }
        }
        break;
    }

    // TODO: gBattleAnimArgs[ARG_RET_ID]?
    if (gBattleAnimArgs[7] == -1)
        DestroyAnimVisualTask(taskId);
}

static void AnimNeedleArmSpike(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1, unk2, unk3, unk4);

    u8 a;
    u8 b;
    u16 c;
    u16 x;
    u16 y;

    if (cmd->unk4 == 0)
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        if (cmd->unk0 == 0)
        {
            a = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
            b = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        }
        else
        {
            a = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
            b = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
        }

        sprite->data[0] = cmd->unk4;
        if (cmd->unk1 == 0)
        {
            sprite->x = cmd->unk2 + a;
            sprite->y = cmd->unk3 + b;
            sprite->data[5] = a;
            sprite->data[6] = b;
        }
        else
        {
            sprite->x = a;
            sprite->y = b;
            sprite->data[5] = cmd->unk2 + a;
            sprite->data[6] = cmd->unk3 + b;
        }

        x = sprite->x;
        sprite->data[1] = x * 16;
        y = sprite->y;
        sprite->data[2] = y * 16;
        sprite->data[3] = (sprite->data[5] - sprite->x) * 16 / cmd->unk4;
        sprite->data[4] = (sprite->data[6] - sprite->y) * 16 / cmd->unk4;
        c = ArcTan2Neg(sprite->data[5] - x, sprite->data[6] - y);
        if (IsContest())
            c -= 0x8000;

        TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, c);
        sprite->callback = AnimNeedleArmSpike_Step;
    }
}

static void AnimNeedleArmSpike_Step(struct Sprite *sprite)
{
    if (sprite->data[0])
    {
        sprite->data[1] += sprite->data[3];
        sprite->data[2] += sprite->data[4];
        sprite->x = sprite->data[1] >> 4 ;
        sprite->y = sprite->data[2] >> 4 ;
        sprite->data[0]--;
    }
    else
    {
        DestroySpriteAndMatrix(sprite);
    }
}

static void AnimWhipHit_WaitEnd(struct Sprite *sprite)
{
    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void AnimSlidingHit(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        sprite->x -= cmd->unk0;
        sprite->y += cmd->unk1;
    }
    else
    {
        sprite->x += cmd->unk0;
        sprite->y += cmd->unk1;
    }

    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimWhipHit(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1);

    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
        StartSpriteAnim(sprite, 1);

    sprite->callback = AnimWhipHit_WaitEnd;
    SetAnimSpriteInitialXOffset(sprite, cmd->unk0);
    sprite->y += cmd->unk1;
}

static void AnimFlickeringPunch(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1, unk2, unk3, unk4, unk5, unk6);

    sprite->x += cmd->unk0;
    sprite->y += cmd->unk1;
    sprite->data[0] = cmd->unk2;
    sprite->data[1] = cmd->unk3;
    sprite->data[3] = cmd->unk4;
    sprite->data[5] = cmd->unk5;
    StartSpriteAffineAnim(sprite, cmd->unk6);
    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = TranslateSpriteLinearAndFlicker;
}

// Moves the sprite in a diagonally slashing motion across the target mon.
// Used by moves such as MOVE_CUT and MOVE_AERIAL_ACE.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: slice direction; 0 = right-to-left, 1 = left-to-right
static void AnimCuttingSlice(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1, unk2);

    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        sprite->y += 8;

    sprite->callback = AnimSlice_Step;
    if (cmd->unk2 == 0)
    {
        sprite->x += cmd->unk0;
    }
    else
    {
        sprite->x -= cmd->unk0;
        sprite->hFlip = 1;
    }

    sprite->y += cmd->unk1;
    sprite->data[1] -= 0x400;
    sprite->data[2] += 0x400;
    sprite->data[5] = cmd->unk2;
    if (sprite->data[5] == 1)
        sprite->data[1] = -sprite->data[1];
}

static void AnimAirCutterSlice(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1, unk2, unk3);

    u8 x, y;
    switch (cmd->unk3)
    {
    case 1:
        x = GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_X);
        y = GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_Y);
        break;
    case 2:
        x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
        if (IsBattlerSpriteVisible(BATTLE_PARTNER(gBattleAnimTarget)))
        {
            x = (GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_X) + x) / 2;
            y = (GetBattlerSpriteCoord(BATTLE_PARTNER(gBattleAnimTarget), BATTLER_COORD_Y) + y) / 2;
        }
        break;
    case 0:
    default:
        x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
        break;
    }

    sprite->x = x;
    sprite->y = y;
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        sprite->y += 8;

    sprite->callback = AnimSlice_Step;
    if (cmd->unk2 == 0)
    {
        sprite->x += cmd->unk0;
    }
    else
    {
        sprite->x -= cmd->unk0;
        sprite->hFlip = 1;
    }

    sprite->y += cmd->unk1;
    sprite->data[1] -= 0x400;
    sprite->data[2] += 0x400;
    sprite->data[5] = cmd->unk2;
    if (sprite->data[5] == 1)
        sprite->data[1] = -sprite->data[1];
}

static void AnimSlice_Step(struct Sprite *sprite)
{
    sprite->data[3] += sprite->data[1];
    sprite->data[4] += sprite->data[2];
    if (sprite->data[5] == 0)
        sprite->data[1] += 0x18;
    else
        sprite->data[1] -= 0x18;

    sprite->data[2] -= 0x18;
    sprite->x2 = sprite->data[3] >> 8;
    sprite->y2 = sprite->data[4] >> 8;
    sprite->data[0]++;
    if (sprite->data[0] == 20)
    {
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
        sprite->data[0] = 3;
        sprite->callback = WaitAnimForDuration;
    }
}

static void UNUSED UnusedFlickerAnim(struct Sprite *sprite)
{
    if (sprite->data[2] > 1)
    {
        if (sprite->data[3] & 1)
        {
            sprite->invisible = FALSE;
            gSprites[sprite->data[0]].invisible = FALSE;
            gSprites[sprite->data[1]].invisible = FALSE;
        }
        else
        {
            sprite->invisible = TRUE;
            gSprites[sprite->data[0]].invisible = TRUE;
            gSprites[sprite->data[1]].invisible = TRUE;
        }

        sprite->data[2] = 0;
        sprite->data[3]++;
    }
    else
    {
        sprite->data[2]++;
    }

    if (sprite->data[3] == 10)
    {
        DestroySprite(&gSprites[sprite->data[0]]);
        DestroySprite(&gSprites[sprite->data[1]]);
        DestroyAnimSprite(sprite);
    }
}

static void AnimCirclingMusicNote(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1, unk2, unk3, unk4, unk5);

    sprite->data[0] = cmd->unk2;
    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        sprite->x -= cmd->unk0;
    else
        sprite->x += cmd->unk0;

    StartSpriteAnim(sprite, cmd->unk5);
    sprite->data[1] = -cmd->unk3;
    sprite->y += cmd->unk1;
    sprite->data[3] = cmd->unk4;
    sprite->callback = AnimCirclingMusicNote_Step;
    sprite->callback(sprite);
}

static void AnimCirclingMusicNote_Step(struct Sprite *sprite)
{
    sprite->x2 = Cos(sprite->data[0], 100);
    sprite->y2 = Sin(sprite->data[0], 20);
    if (sprite->data[0] < 128)
        sprite->subpriority = 0;
    else
        sprite->subpriority = 14;

    sprite->data[0] = (sprite->data[0] + sprite->data[1]) & 0xFF;
    sprite->data[5] += 130;
    sprite->y2 += sprite->data[5] >> 8;
    sprite->data[2]++;
    if (sprite->data[2] == sprite->data[3])
        DestroyAnimSprite(sprite);
}

static void AnimProtect(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1, unk2);

    if (IsContest())
        cmd->unk1 += 8;

    sprite->x = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_X) + cmd->unk0;
    sprite->y = GetBattlerSpriteCoord2(gBattleAnimAttacker, BATTLER_COORD_Y) + cmd->unk1;
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER || IsContest())
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker) + 1;
    else
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);

    sprite->data[0] = cmd->unk2;
    sprite->data[2] = OBJ_PLTT_ID(IndexOfSpritePaletteTag(ANIM_TAG_PROTECT));
    sprite->data[7] = 16;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - sprite->data[7], sprite->data[7]));
    sprite->callback = AnimProtect_Step;
}

static void AnimProtect_Step(struct Sprite *sprite)
{
    int i, id, savedPal;
    sprite->data[5] += 96;
    sprite->x2 = -(sprite->data[5] >> 8);
    if (++sprite->data[1] > 1)
    {
        sprite->data[1] = 0;
        savedPal = gPlttBufferFaded[sprite->data[2] + 1];
        i = 0;
        while (i < 6)
        {
            id = sprite->data[2] + ++i;
            gPlttBufferFaded[id] = gPlttBufferFaded[id + 1];
        }

        gPlttBufferFaded[sprite->data[2] + 7] = savedPal;
    }

    if (sprite->data[7] > 6 && sprite->data[0] >0 && ++sprite->data[6] > 1)
    {
        sprite->data[6] = 0;
        sprite->data[7] -= 1;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - sprite->data[7], sprite->data[7]));
    }

    if (sprite->data[0] > 0)
    {
        sprite->data[0] -= 1;
    }
    else if (++sprite->data[6] > 1)
    {
        sprite->data[6] = 0;
        sprite->data[7]++;
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16 - sprite->data[7], sprite->data[7]));
        if (sprite->data[7] == 16)
        {
            sprite->invisible = TRUE;
            sprite->callback = DestroyAnimSpriteAndDisableBlend;
        }
    }
}

static void AnimMilkBottle(struct Sprite *sprite)
{
    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + 0xFFE8;
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->data[2] = 0;
    sprite->data[3] = 0;
    sprite->data[4] = 0;
    sprite->data[6] = 0;
    sprite->data[7] = 16;
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[6], sprite->data[7]));
    sprite->callback = AnimMilkBottle_Step1;
}

static void AnimMilkBottle_Step1(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (++sprite->data[2] > 0)
        {
            sprite->data[2] = 0;
            if (((++sprite->data[1]) & 1) != 0)
            {
                if (sprite->data[6] <= 15)
                    sprite->data[6]++;
            }
            else if (sprite->data[7] > 0)
            {
                sprite->data[7]--;
            }

            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[6], sprite->data[7]));
            if (sprite->data[6] == 16 && sprite->data[7] == 0)
            {
                sprite->data[1] = 0;
                sprite->data[0]++;
            }
        }
        break;
    case 1:
        if (++sprite->data[1] > 8)
        {
            sprite->data[1] = 0;
            StartSpriteAffineAnim(sprite, 1);
            sprite->data[0]++;
        }
        break;
    case 2:
        AnimMilkBottle_Step2(sprite, 16, 4);
        if (++sprite->data[1] > 2)
        {
            sprite->data[1] = 0;
            sprite->y++;
        }

        if (++sprite->data[2] <= 29)
            break;

        if (sprite->data[2] & 1)
        {
            if (sprite->data[6] > 0)
                sprite->data[6]--;
        }
        else if (sprite->data[7] <= 15)
        {
            sprite->data[7]++;
        }

        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sprite->data[6], sprite->data[7]));
        if (sprite->data[6] == 0 && sprite->data[7] == 16)
        {
            sprite->data[1] = 0;
            sprite->data[2] = 0;
            sprite->data[0]++;
        }
        break;
    case 3:
        sprite->invisible = TRUE;
        sprite->data[0]++;
        break;
    case 4:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 0));
        DestroyAnimSprite(sprite);
        break;
    }
}

static void AnimMilkBottle_Step2(struct Sprite *sprite, int unk1, int unk2)
{
    if (sprite->data[3] <= 11)
        sprite->data[4] += 2;

    if ((u16)(sprite->data[3] - 0x12) <= 0x17)
        sprite->data[4] -= 2;

    if ((sprite->data[3]) > 0x2F)
        sprite->data[4] += 2;

    sprite->x2 = sprite->data[4] / 9;
    sprite->y2 = sprite->data[4] / 14;
    if (sprite->y2 < 0)
        sprite->y2 *= -1;

    sprite->data[3]++;
    if (sprite->data[3] > 0x3B)
        sprite->data[3] = 0;
}

static void AnimGrantingStars(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1, unk2, unk3, unk4, unk5);

    if (!cmd->unk2)
        SetSpriteCoordsToAnimAttackerCoords(sprite);

    SetAnimSpriteInitialXOffset(sprite, cmd->unk0);
    sprite->y += cmd->unk1;
    sprite->data[0] = cmd->unk5;
    sprite->data[1] = cmd->unk3;
    sprite->data[2] = cmd->unk4;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = TranslateSpriteLinearFixedPoint;
}

static void AnimSparklingStars(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1, unk2, unk3, unk4, unk5, unk6);

    u8 battler;
    if (!cmd->unk2)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    if (IsDoubleBattle() && IsBattlerSpriteVisible(BATTLE_PARTNER(battler)))
    {
        SetAverageBattlerPositions(battler, cmd->unk6, &sprite->x, &sprite->y);
        SetAnimSpriteInitialXOffset(sprite, cmd->unk0);
        sprite->y += cmd->unk1;
    }
    else
    {
        if (!cmd->unk6)
        {
            sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X);
            sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y) + cmd->unk1;
        }
        else
        {
            sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2);
            sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET) + cmd->unk1;
        }

        SetAnimSpriteInitialXOffset(sprite, cmd->unk0);
    }

    sprite->data[0] = cmd->unk5;
    sprite->data[1] = cmd->unk3;
    sprite->data[2] = cmd->unk4;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = TranslateSpriteLinearFixedPoint;
}

static void AnimBubbleBurst(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1);

    SetSpriteCoordsToAnimAttackerCoords(sprite);
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->x += cmd->unk0;
        sprite->y += cmd->unk1;
    }
    else
    {
        sprite->x -= cmd->unk0;
        sprite->y += cmd->unk1;
        StartSpriteAnim(sprite, 1);
    }

    sprite->callback = AnimBubbleBurst_Step;
}

static void AnimBubbleBurst_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] > 30)
    {
        sprite->y2 = (30 - sprite->data[0]) / 3;
        sprite->x2 = Sin(sprite->data[1] * 4, 3);
        sprite->data[1]++;
    }

    if (sprite->animEnded)
        DestroyAnimSprite(sprite);
}

static void AnimSleepLetterZ(struct Sprite *sprite)
{
    CMD_ARGS(unk0, unk1);

    SetSpriteCoordsToAnimAttackerCoords(sprite);
    if (GetBattlerSide(gBattleAnimAttacker) == B_SIDE_PLAYER)
    {
        sprite->x += cmd->unk0;
        sprite->y += cmd->unk1;
        sprite->data[3] = 1;
    }
    else
    {
        sprite->x -= cmd->unk0;
        sprite->y += cmd->unk1;
        sprite->data[3] = 0xFFFF;
        StartSpriteAffineAnim(sprite, 1);
    }

    sprite->callback = AnimSleepLetterZ_Step;
}

static void AnimSleepLetterZ_Step(struct Sprite *sprite)
{
    sprite->y2 = -(sprite->data[0] / 0x28);
    sprite->x2 = sprite->data[4] / 10;
    sprite->data[4] += sprite->data[3] * 2;
    sprite->data[0] += sprite->data[1];
    if (++sprite->data[1] > 60)
        DestroySpriteAndMatrix(sprite);
}
