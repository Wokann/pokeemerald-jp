#include "global.h"
#include "battle_anim.h"
#include "gpu_regs.h"
#include "random.h"
#include "task.h"
#include "trig.h"
#include "constants/rgb.h"

// JP: the fight anim sprite templates and anim/affine data stay embedded
// in ROM data (see the ABSOLUTE aliases in ld_script_jp.txt); only the
// sprite callbacks are decompiled here, matching US pokeemerald.

static void AnimUnusedHumanoidFoot(struct Sprite *);
static void AnimSlideHandOrFootToTarget(struct Sprite *);
static void AnimJumpKick(struct Sprite *);
static void AnimBasicFistOrFoot(struct Sprite *);
static void AnimFistOrFootRandomPos(struct Sprite *);
static void AnimFistOrFootRandomPos_Step(struct Sprite *);
static void AnimCrossChopHand(struct Sprite *);
static void AnimCrossChopHand_Step(struct Sprite *);
static void AnimSlidingKick(struct Sprite *);
static void AnimSlidingKick_Step(struct Sprite *);
static void AnimSpinningKickOrPunch(struct Sprite *);
static void AnimSpinningKickOrPunchFinish(struct Sprite *);
static void AnimStompFoot(struct Sprite *);
static void AnimStompFoot_Step(struct Sprite *);
static void AnimStompFoot_End(struct Sprite *);
static void AnimDizzyPunchDuck(struct Sprite *);
static void AnimBrickBreakWall(struct Sprite *);
static void AnimBrickBreakWall_Step(struct Sprite *);
static void AnimBrickBreakWallShard(struct Sprite *);
static void AnimBrickBreakWallShard_Step(struct Sprite *);
static void AnimSuperpowerOrb(struct Sprite *);
static void AnimSuperpowerOrb_Step(struct Sprite *);
static void AnimSuperpowerRock(struct Sprite *);
static void AnimSuperpowerRock_Step1(struct Sprite *);
static void AnimSuperpowerRock_Step2(struct Sprite *);
static void AnimSuperpowerFireball(struct Sprite *);
static void AnimArmThrustHit_Step(struct Sprite *);
static void AnimArmThrustHit(struct Sprite *);
static void AnimRevengeScratch(struct Sprite *);
static void AnimFocusPunchFist(struct Sprite *);

extern const struct SpriteTemplate gBasicHitSplatSpriteTemplate;

static void AnimUnusedHumanoidFoot(struct Sprite *sprite)
{
    SetAnimSpriteInitialXOffset(sprite, gBattleAnimArgs[0]);
    sprite->y += gBattleAnimArgs[1];
    sprite->data[0] = 15;
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimSlideHandOrFootToTarget(struct Sprite *sprite)
{
    if (gBattleAnimArgs[7] == 1 && GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
    }

    StartSpriteAnim(sprite, gBattleAnimArgs[6]);
    gBattleAnimArgs[6] = 0;
    AnimTravelDiagonally(sprite);
}

static void AnimJumpKick(struct Sprite *sprite)
{
    if (IsContest())
    {
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        gBattleAnimArgs[3] = -gBattleAnimArgs[3];
    }

    AnimSlideHandOrFootToTarget(sprite);
}

// Displays a basic fist or foot sprite for a given duration.
// Used by many fighting moves (and elemental "punch" moves).
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: duration
// arg 3: ? (todo: related to initial pixel offsets)
// arg 4: anim num
static void AnimBasicFistOrFoot(struct Sprite *sprite)
{
    StartSpriteAnim(sprite, gBattleAnimArgs[4]);

    if (gBattleAnimArgs[3] == 0)
        InitSpritePosToAnimAttacker(sprite, TRUE);
    else
        InitSpritePosToAnimTarget(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimFistOrFootRandomPos(struct Sprite *sprite)
{
    u8 battler;
    s16 xMod, yMod;
    s16 x, y;

    if (gBattleAnimArgs[0] == 0)
        battler = gBattleAnimAttacker;
    else
        battler = gBattleAnimTarget;

    if (gBattleAnimArgs[2] < 0)
        gBattleAnimArgs[2] = Random2() % 5;

    StartSpriteAnim(sprite, gBattleAnimArgs[2]);
    sprite->x = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET);

    xMod = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_WIDTH) / 2;
    yMod = GetBattlerSpriteCoordAttr(battler, BATTLER_COORD_ATTR_HEIGHT) / 4;

    x = Random2() % xMod;
    y = Random2() % yMod;

    if (Random2() & 1)
        x *= -1;
    if (Random2() & 1)
        y *= -1;

    if (GET_BATTLER_SIDE2(battler) == B_SIDE_PLAYER)
        y -= 16;

    sprite->x += x;
    sprite->y += y;

    sprite->data[0] = gBattleAnimArgs[1];
    sprite->data[7] = CreateSprite(&gBasicHitSplatSpriteTemplate, sprite->x, sprite->y, sprite->subpriority + 1);
    if (sprite->data[7] != MAX_SPRITES)
    {
        StartSpriteAffineAnim(&gSprites[sprite->data[7]], 0);
        gSprites[sprite->data[7]].callback = SpriteCallbackDummy;
    }

    sprite->callback = AnimFistOrFootRandomPos_Step;
}

static void AnimFistOrFootRandomPos_Step(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        if (sprite->data[7] != MAX_SPRITES)
        {
            FreeOamMatrix(gSprites[sprite->data[7]].oam.matrixNum);
            DestroySprite(&gSprites[sprite->data[7]]);
        }

        DestroyAnimSprite(sprite);
    }
    else
    {
        sprite->data[0]--;
    }
}

static void AnimCrossChopHand(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = 30;

    if (gBattleAnimArgs[2] == 0)
    {
        sprite->data[2] = sprite->x - 20;
    }
    else
    {
        sprite->data[2] = sprite->x + 20;
        sprite->hFlip = 1;
    }

    sprite->data[4] = sprite->y - 20;
    // JP: 0x080A67B4 is the JP symbol InitAndRunAnimFastLinearTranslation,
    // which behaves as US pokeemerald's StartAnimLinearTranslation.
    sprite->callback = InitAndRunAnimFastLinearTranslation;
    StoreSpriteCallbackInData6(sprite, AnimCrossChopHand_Step);
}

static void AnimCrossChopHand_Step(struct Sprite *sprite)
{
    if (++sprite->data[5] == 11)
    {
        sprite->data[2] = sprite->x - sprite->x2;
        sprite->data[4] = sprite->y - sprite->y2;
        sprite->data[0] = 8;
        sprite->x += sprite->x2;
        sprite->y += sprite->y2;
        sprite->y2 = 0;
        sprite->x2 = 0;

        sprite->callback = InitAndRunAnimFastLinearTranslation;
        StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    }
}

// Rolling Kick / Low Kick
static void AnimSlidingKick(struct Sprite *sprite)
{
    if (BATTLE_PARTNER(gBattleAnimAttacker) == gBattleAnimTarget && GetBattlerPosition(gBattleAnimTarget) < B_POSITION_PLAYER_RIGHT)
        gBattleAnimArgs[0] *= -1;

    InitSpritePosToAnimTarget(sprite, TRUE);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[3];
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x + gBattleAnimArgs[2];
    sprite->data[3] = sprite->y;
    sprite->data[4] = sprite->y;

    InitAnimLinearTranslation(sprite);

    sprite->data[5] = gBattleAnimArgs[5];
    sprite->data[6] = gBattleAnimArgs[4];
    sprite->data[7] = 0;

    sprite->callback = AnimSlidingKick_Step;
}

static void AnimSlidingKick_Step(struct Sprite *sprite)
{
    if (!AnimTranslateLinear(sprite))
    {
        sprite->y2 += Sin(sprite->data[7] >> 8, sprite->data[5]);
        sprite->data[7] += sprite->data[6];
    }
    else
    {
        DestroyAnimSprite(sprite);
    }
}

// Animates the spinning, shrinking kick or punch, which then
// reappears at full size. Used by moves such as MOVE_MEGA_PUNCH and MOVE_MEGA_KICK.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: anim num
// arg 3: spin duration
static void AnimSpinningKickOrPunch(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    StartSpriteAnim(sprite, gBattleAnimArgs[2]);
    sprite->data[0] = gBattleAnimArgs[3];

    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, AnimSpinningKickOrPunchFinish);
}

static void AnimSpinningKickOrPunchFinish(struct Sprite *sprite)
{
    StartSpriteAffineAnim(sprite, 0);
    sprite->affineAnimPaused = 1;
    sprite->data[0] = 20;

    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Animates MOVE_STOMP's foot that slides downward.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: initial wait duration
static void AnimStompFoot(struct Sprite *sprite)
{
    InitSpritePosToAnimTarget(sprite, TRUE);
    sprite->data[0] = gBattleAnimArgs[2];

    sprite->callback = AnimStompFoot_Step;
}

static void AnimStompFoot_Step(struct Sprite *sprite)
{
    if (--sprite->data[0] == -1)
    {
        sprite->data[0] = 6;
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

        sprite->callback = InitAndRunAnimFastLinearTranslation;
        StoreSpriteCallbackInData6(sprite, AnimStompFoot_End);
    }
}

static void AnimStompFoot_End(struct Sprite *sprite)
{
    sprite->data[0] = 15;

    sprite->callback = WaitAnimForDuration;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimDizzyPunchDuck(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        InitSpritePosToAnimTarget(sprite, TRUE);
        sprite->data[1] = gBattleAnimArgs[2];
        sprite->data[2] = gBattleAnimArgs[3];
        sprite->data[0]++;
    }
    else
    {
        sprite->data[4] += sprite->data[1];
        sprite->x2 = sprite->data[4] >> 8;
        sprite->y2 = Sin(sprite->data[3], sprite->data[2]);
        sprite->data[3] = (sprite->data[3] + 3) & 0xFF;

        if (sprite->data[3] > 100)
            sprite->invisible = sprite->data[3] % 2;

        if (sprite->data[3] > 120)
            DestroyAnimSprite(sprite);
    }
}

// The wall that appears when Brick Break is going to shatter the target's defensive wall
static void AnimBrickBreakWall(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y);
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y);
    }

    sprite->x += gBattleAnimArgs[1];
    sprite->y += gBattleAnimArgs[2];

    sprite->data[0] = 0;
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = gBattleAnimArgs[4];
    sprite->data[3] = 0;
    sprite->callback = AnimBrickBreakWall_Step;
}

static void AnimBrickBreakWall_Step(struct Sprite *sprite)
{
    switch (sprite->data[0])
    {
    case 0:
        if (--sprite->data[1] == 0)
        {
            if (sprite->data[2] == 0)
                DestroyAnimSprite(sprite);
            else
                sprite->data[0]++;
        }
        break;
    case 1:
        if (++sprite->data[1] > 1)
        {
            sprite->data[1] = 0;
            sprite->data[3]++;
            if (sprite->data[3] & 1)
                sprite->x2 = 2;
            else
                sprite->x2 = -2;
        }

        if (--sprite->data[2] == 0)
            DestroyAnimSprite(sprite);
        break;
    }
}

// Piece of shattered defensive wall flies off. Used by Brick Break when the target has a defensive wall
static void AnimBrickBreakWallShard(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X) + gBattleAnimArgs[2];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y) + gBattleAnimArgs[3];
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X) + gBattleAnimArgs[2];
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y) + gBattleAnimArgs[3];
    }

    sprite->oam.tileNum += gBattleAnimArgs[1] * 16;
    sprite->data[0] = 0;

    switch (gBattleAnimArgs[1])
    {
    case 0:
        sprite->data[6] = -3;
        sprite->data[7] = -3;
        break;
    case 1:
        sprite->data[6] = 3;
        sprite->data[7] = -3;
        break;
    case 2:
        sprite->data[6] = -3;
        sprite->data[7] = 3;
        break;
    case 3:
        sprite->data[6] = 3;
        sprite->data[7] = 3;
        break;
    default:
        DestroyAnimSprite(sprite);
        return;
    }

    sprite->callback = AnimBrickBreakWallShard_Step;
}

static void AnimBrickBreakWallShard_Step(struct Sprite *sprite)
{
    sprite->x += sprite->data[6];
    sprite->y += sprite->data[7];

    if (++sprite->data[0] > 40)
        DestroyAnimSprite(sprite);
}

static void AnimSuperpowerOrb(struct Sprite *sprite)
{
    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattlerAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattlerAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
        sprite->data[7] = gBattleAnimTarget;
    }
    else
    {
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
        sprite->data[7] = gBattleAnimAttacker;
    }

    sprite->data[0] = 0;
    sprite->data[1] = 12;
    sprite->data[2] = 8;
    sprite->callback = AnimSuperpowerOrb_Step;
}

static void AnimSuperpowerOrb_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] == 180)
    {
        SetGpuReg(REG_OFFSET_BLDCNT, 0);

        sprite->data[0] = 16;
        sprite->data[1] = sprite->x;
        sprite->data[2] = GetBattlerSpriteCoord(sprite->data[7], BATTLER_COORD_X_2);
        sprite->data[3] = sprite->y;
        sprite->data[4] = GetBattlerSpriteCoord(sprite->data[7], BATTLER_COORD_Y_PIC_OFFSET);

        InitAnimLinearTranslation(sprite);
        StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
        sprite->callback = AnimTranslateLinear_WithFollowup;
    }
}

// Floating rock that flies off to hit the target. Used by Superpower
static void AnimSuperpowerRock(struct Sprite *sprite)
{
    sprite->x = gBattleAnimArgs[0];
    sprite->y = 120;

    sprite->data[0] = gBattleAnimArgs[3];
    StorePointerInVars(&sprite->data[4], &sprite->data[5], (void *)(sprite->y << 8));

    sprite->data[6] = gBattleAnimArgs[1];
    sprite->oam.tileNum += gBattleAnimArgs[2] * 4;

    sprite->callback = AnimSuperpowerRock_Step1;
}

static void AnimSuperpowerRock_Step1(struct Sprite *sprite)
{
    void *var0;

    if (sprite->data[0] != 0)
    {
        var0 = LoadPointerFromVars(sprite->data[4], sprite->data[5]);
        var0 -= sprite->data[6];
        StorePointerInVars(&sprite->data[4], &sprite->data[5], var0);

        var0 = (void *)(((intptr_t)var0) >> 8);
        sprite->y = (intptr_t)var0;
        if (sprite->y < -8)
            DestroyAnimSprite(sprite);
        else
            sprite->data[0]--;
    }
    else
    {
        s16 pos0 = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        s16 pos1 = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        s16 pos2 = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        s16 pos3 = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

        sprite->data[0] = pos2 - pos0;
        sprite->data[1] = pos3 - pos1;
        sprite->data[2] = sprite->x << 4;
        sprite->data[3] = sprite->y << 4;

        sprite->callback = AnimSuperpowerRock_Step2;
    }
}

static void AnimSuperpowerRock_Step2(struct Sprite *sprite)
{
    u16 edgeX;

    sprite->data[2] += sprite->data[0];
    sprite->data[3] += sprite->data[1];
    sprite->x = sprite->data[2] >> 4;
    sprite->y = sprite->data[3] >> 4;

    edgeX = sprite->x + 8;
    if (edgeX > 256 || sprite->y < -8 || sprite->y > 120)
        DestroyAnimSprite(sprite);
}

static void AnimSuperpowerFireball(struct Sprite *sprite)
{
    u8 battler;

    if (gBattleAnimArgs[0] == ANIM_ATTACKER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattlerAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattlerAttacker, BATTLER_COORD_Y_PIC_OFFSET);
        battler = gBattleAnimTarget;
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimAttacker);
    }
    else
    {
        battler = gBattleAnimAttacker;
        sprite->oam.priority = GetBattlerSpriteBGPriority(gBattleAnimTarget);
    }

    if (IsContest())
        sprite->oam.matrixNum |= ST_OAM_HFLIP;
    else if (GetBattlerSide(battler) == B_SIDE_PLAYER)
        sprite->oam.matrixNum |= (ST_OAM_HFLIP | ST_OAM_VFLIP);

    sprite->data[0] = 16;
    sprite->data[1] = sprite->x;
    sprite->data[2] = GetBattlerSpriteCoord(battler, BATTLER_COORD_X_2);
    sprite->data[3] = sprite->y;
    sprite->data[4] = GetBattlerSpriteCoord(battler, BATTLER_COORD_Y_PIC_OFFSET);

    InitAnimLinearTranslation(sprite);
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
    sprite->callback = AnimTranslateLinear_WithFollowup;
}

static void AnimArmThrustHit_Step(struct Sprite *sprite)
{
    if (sprite->data[0] == sprite->data[4])
        DestroyAnimSprite(sprite);

    sprite->data[0]++;
}

static void AnimArmThrustHit(struct Sprite *sprite)
{
    u8 turn;

    sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[1] = gBattleAnimArgs[3];
    sprite->data[2] = gBattleAnimArgs[0];
    sprite->data[3] = gBattleAnimArgs[1];
    sprite->data[4] = gBattleAnimArgs[2];

    turn = gAnimMoveTurn;
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        turn++;

    if (turn & 1)
    {
        sprite->data[2] = -sprite->data[2];
        sprite->data[1]++;
    }

    StartSpriteAnim(sprite, sprite->data[1]);
    sprite->x2 = sprite->data[2];
    sprite->y2 = sprite->data[3];
    sprite->callback = AnimArmThrustHit_Step;
}

static void AnimRevengeScratch(struct Sprite *sprite)
{
    if (gBattleAnimArgs[2] == ANIM_ATTACKER)
        InitSpritePosToAnimAttacker(sprite, FALSE);
    else
        InitSpritePosToAnimTarget(sprite, FALSE);

    if (IsContest())
    {
        StartSpriteAnim(sprite, 2);
    }
    else if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
    {
        StartSpriteAnim(sprite, 1);
    }

    sprite->callback = RunStoredCallbackWhenAnimEnds;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Fist shrinks toward target and shakes
static void AnimFocusPunchFist(struct Sprite *sprite)
{
    if (sprite->affineAnimEnded)
    {
        sprite->data[1] = (sprite->data[1] + 40) & 0xFF;
        sprite->x2 = Sin(sprite->data[1], 2);
        if (++sprite->data[0] > 40)
            DestroyAnimSprite(sprite);
    }
}

void AnimTask_MoveSkyUppercutBg(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        UpdateAnimBg3ScreenSize(FALSE);
        task->data[8] = gBattleAnimArgs[0];
        task->data[0]++;
        break;
    case 1:
        if (--task->data[8] == -1)
            task->data[0]++;
        break;
    case 2:
    default:
        task->data[9] += 1280;
        break;
    }

    task->data[10] += 2816;

    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        gBattle_BG3_X += task->data[9] >> 8;
    else
        gBattle_BG3_X -= task->data[9] >> 8;

    gBattle_BG3_Y += task->data[10] >> 8;
    task->data[9] &= 0xFF;
    task->data[10] &= 0xFF;

    if (gBattleAnimArgs[7] == -1)
    {
        gBattle_BG3_X = 0;
        gBattle_BG3_Y = 0;
        UpdateAnimBg3ScreenSize(TRUE);
        DestroyAnimVisualTask(taskId);
    }
}
