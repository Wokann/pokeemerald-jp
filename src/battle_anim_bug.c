#include "global.h"
#include "battle_anim.h"
#include "battle_anim_internal.h"
#include "trig.h"

// JP: the bug anim sprite templates and anim/affine data stay embedded
// in ROM data (see the ABSOLUTE aliases in ld_script_jp.txt); only the
// sprite callbacks are decompiled here, matching US pokeemerald.

static void AnimMegahornHorn(struct Sprite *sprite);
static void AnimLeechLifeNeedle(struct Sprite *sprite);
static void AnimTranslateWebThread(struct Sprite *sprite);
static void AnimTranslateWebThread_Step(struct Sprite *sprite);
static void AnimStringWrap(struct Sprite *sprite);
static void AnimStringWrap_Step(struct Sprite *sprite);
static void AnimSpiderWeb(struct Sprite *sprite);
static void AnimSpiderWeb_Step(struct Sprite *sprite);
static void AnimSpiderWeb_End(struct Sprite *sprite);
static void AnimTranslateStinger(struct Sprite *sprite);
static void AnimMissileArc(struct Sprite *sprite);
static void AnimMissileArc_Step(struct Sprite *sprite);
static void AnimTailGlowOrb(struct Sprite *sprite);

static void AnimMegahornHorn(struct Sprite *sprite)
{
    CMD_ARGS(x1, y1, x2, y2, duration);

    if (IsContest())
    {
        StartSpriteAffineAnim(sprite, 2);
        cmd->x2 = -cmd->x2;
        cmd->x1 = -cmd->x1;
    }
    else if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
    {
        StartSpriteAffineAnim(sprite, 1);
        cmd->y1 = -cmd->y1;
        cmd->x2 = -cmd->x2;
        cmd->y2 = -cmd->y2;
        cmd->x1 = -cmd->x1;
    }

    sprite->x = GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_X_2) + cmd->x1;
    sprite->y = GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + cmd->y1;
    sprite->data[0] = cmd->duration;

    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + cmd->x2;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + cmd->y2;

    // JP: 0x080A67B4 is the JP symbol InitAndRunAnimFastLinearTranslation,
    // which behaves as US pokeemerald's StartAnimLinearTranslation.
    sprite->callback = InitAndRunAnimFastLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

static void AnimLeechLifeNeedle(struct Sprite *sprite)
{
    CMD_ARGS(x, y, duration);

    if (IsContest())
    {
        cmd->x = -cmd->x;
        StartSpriteAffineAnim(sprite, 2);
    }
    else if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
    {
        cmd->y = -cmd->y;
        cmd->x = -cmd->x;
    }

    sprite->x = GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_X_2) + cmd->x;
    sprite->y = GetBattlerSpriteCoord2(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + cmd->y;
    sprite->data[0] = cmd->duration;

    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);

    sprite->callback = InitAndRunAnimFastLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Creates a single web thread that travels from attacker to target.
// Used by MOVE_STRING_SHOT and MOVE_SPIDER_WEB in their first move phase.
// arg 2: controls the left-to-right movement
static void AnimTranslateWebThread(struct Sprite *sprite)
{
    CMD_ARGS(x, y, unk2, amplitude, targetsBoth);

    if (IsContest())
        cmd->unk2 /= 2;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    sprite->data[0] = cmd->unk2;
    sprite->data[1] = sprite->x;
    sprite->data[3] = sprite->y;

    if (!cmd->targetsBoth)
    {
        sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    }
    else
    {
        SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->data[2], &sprite->data[4]);
    }

    InitAnimLinearTranslationWithSpeed(sprite);
    sprite->data[5] = cmd->amplitude;
    sprite->callback = AnimTranslateWebThread_Step;
}

static void AnimTranslateWebThread_Step(struct Sprite *sprite)
{
    if (AnimTranslateLinear(sprite))
    {
        DestroyAnimSprite(sprite);
        return;
    }

    sprite->x2 += Sin(sprite->data[6], sprite->data[5]);
    sprite->data[6] = (sprite->data[6] + 13) & 0xFF;
}

// Second stage of String Shot
static void AnimStringWrap(struct Sprite *sprite)
{
    CMD_ARGS(x, y);

    SetAverageBattlerPositions(gBattleAnimTarget, FALSE, &sprite->x, &sprite->y);
    if (GetBattlerSide(gBattleAnimAttacker))
        sprite->x -= cmd->x;
    else
        sprite->x += cmd->x;

    sprite->y += cmd->y;
    if (GetBattlerSide(gBattleAnimTarget) == B_SIDE_PLAYER)
        sprite->y += 8;

    sprite->callback = AnimStringWrap_Step;
}

static void AnimStringWrap_Step(struct Sprite *sprite)
{
    if (++sprite->data[0] == 3)
    {
        sprite->data[0] = 0;
        sprite->invisible ^= 1;
    }

    if (++sprite->data[1] == 51)
    {
        DestroyAnimSprite(sprite);
    }
}

static void AnimSpiderWeb(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));

    sprite->data[0] = 16;
    sprite->callback = AnimSpiderWeb_Step;
}

static void AnimSpiderWeb_Step(struct Sprite *sprite)
{
    if (sprite->data[2] < 20)
    {
        sprite->data[2]++;
    }
    else if (sprite->data[1]++ & 1)
    {
        u16 blend;
        sprite->data[0]--;
        blend = BLDALPHA_BLEND(sprite->data[0], 16 - sprite->data[0]);
        SetGpuReg(REG_OFFSET_BLDALPHA, blend);

        if (sprite->data[0] == 0)
        {
            sprite->invisible = TRUE;
            sprite->callback = AnimSpiderWeb_End;
        }
    }
}

static void AnimSpiderWeb_End(struct Sprite *sprite)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    DestroyAnimSprite(sprite);
}

// Translates a stinger sprite linearly to a destination location. The sprite is
// initially rotated so that it appears to be traveling in a straight line.
static void AnimTranslateStinger(struct Sprite *sprite)
{
    CMD_ARGS(initialX, intialY, targetX, targetY, duration);

    s16 lVarX, lVarY;
    u16 rot;

    if (IsContest())
    {
        cmd->targetX = -cmd->targetX;
    }
    else
    {
        if (GetBattlerSide(gBattleAnimAttacker))
        {
            cmd->targetX = -cmd->targetX;
            cmd->intialY = -cmd->intialY;
            cmd->targetY = -cmd->targetY;
        }
    }

    if (!IsContest() && GetBattlerSide(gBattleAnimAttacker) == GetBattlerSide(gBattleAnimTarget))
    {
        if (GetBattlerPosition(gBattleAnimTarget) == B_POSITION_PLAYER_LEFT
         || GetBattlerPosition(gBattleAnimTarget) == B_POSITION_OPPONENT_LEFT)
        {
            cmd->targetX *= -1;
            cmd->initialX *= -1;
        }
    }

    InitSpritePosToAnimAttacker(sprite, TRUE);

    lVarX = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + cmd->targetX;
    lVarY = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + cmd->targetY;
    rot = ArcTan2Neg(lVarX - sprite->x, lVarY - sprite->y);
    rot -= 0x4000;
    TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, rot);

    sprite->data[0] = cmd->duration;
    sprite->data[2] = lVarX;
    sprite->data[4] = lVarY;

    sprite->callback = InitAndRunAnimFastLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Rotates sprite and moves it in an arc, so that it appears like a missle or arrow traveling.
static void AnimMissileArc(struct Sprite *sprite)
{
    CMD_ARGS(initialX, intialY, targetX, targetY, duration, waveAmplitude);

    InitSpritePosToAnimAttacker(sprite, TRUE);

    if (GetBattlerSide(gBattleAnimAttacker))
        cmd->targetX = -cmd->targetX;

    sprite->data[0] = cmd->duration;
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2) + cmd->targetX;
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + cmd->targetY;
    sprite->data[5] = cmd->waveAmplitude;
    InitAnimArcTranslation(sprite);

    sprite->callback = AnimMissileArc_Step;
    sprite->invisible = TRUE;
}

static void AnimMissileArc_Step(struct Sprite *sprite)
{
    sprite->invisible = FALSE;

    if (TranslateAnimHorizontalArc(sprite))
    {
        DestroyAnimSprite(sprite);
    }
    else
    {
        s16 tempData[8];
        s16 x2, y2;
        int i;

        for (i = 0; i < 8; i++)
            tempData[i] = sprite->data[i];

        x2 = sprite->x + sprite->x2;
        y2 = sprite->y + sprite->y2;

        if (!TranslateAnimHorizontalArc(sprite))
        {
            u16 rotation = ArcTan2Neg(sprite->x + sprite->x2 - x2, sprite->y + sprite->y2 - y2);
            rotation -= 0x4000;
            TrySetSpriteRotScale(sprite, FALSE, 0x100, 0x100, rotation);

            for (i = 0; i < 8; i++)
                sprite->data[i] = tempData[i];
        }
    }
}

static void AnimTailGlowOrb(struct Sprite *sprite)
{
    CMD_ARGS(relativeTo);

    if (cmd->relativeTo == ANIM_ATTACKER)
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimAttacker, BATTLER_COORD_Y_PIC_OFFSET) + 18;
    }
    else
    {
        sprite->x = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
        sprite->y = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET) + 18;
    }

    StoreSpriteCallbackInData6(sprite, DestroySpriteAndMatrix);
    sprite->callback = RunStoredCallbackWhenAffineAnimEnds;
}
