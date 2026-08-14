#include "global.h"
#include "battle_anim.h"
#include "trig.h"

// JP: the poison anim sprite templates and anim/affine data stay embedded
// in ROM data (see the ABSOLUTE aliases in ld_script_jp.txt); only the
// sprite callbacks are decompiled here, matching US pokeemerald.

static void AnimSludgeProjectile(struct Sprite *sprite);
static void AnimSludgeProjectile_Step(struct Sprite *sprite);
static void AnimAcidPoisonBubble(struct Sprite *sprite);
static void AnimAcidPoisonBubble_Step(struct Sprite *sprite);
static void AnimSludgeBombHitParticle(struct Sprite *sprite);
static void AnimSludgeBombHitParticle_Step(struct Sprite *sprite);
static void AnimAcidPoisonDroplet(struct Sprite *sprite);
static void AnimBubbleEffect(struct Sprite *sprite);
static void AnimBubbleEffect_Step(struct Sprite *sprite);

static void AnimSludgeProjectile(struct Sprite *sprite)
{
    if (!gBattleAnimArgs[3])
        StartSpriteAnim(sprite, 2);

    InitSpritePosToAnimAttacker(sprite, TRUE);

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_X_2);
    sprite->data[4] = GetBattlerSpriteCoord(gBattleAnimTarget, BATTLER_COORD_Y_PIC_OFFSET);
    sprite->data[5] = -30;

    InitAnimArcTranslation(sprite);

    sprite->callback = AnimSludgeProjectile_Step;
}

static void AnimSludgeProjectile_Step(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

static void AnimAcidPoisonBubble(struct Sprite *sprite)
{
    s16 l1, l2;
    if (!gBattleAnimArgs[3])
        StartSpriteAnim(sprite, 2);

    InitSpritePosToAnimAttacker(sprite, TRUE);
    SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &l1, &l2);

    if (GetBattlerSide(gBattleAnimAttacker))
        gBattleAnimArgs[4] = -gBattleAnimArgs[4];

    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[2] = l1 + gBattleAnimArgs[4];
    sprite->data[4] = l2 + gBattleAnimArgs[5];
    sprite->data[5] = -30;

    InitAnimArcTranslation(sprite);

    sprite->callback = AnimAcidPoisonBubble_Step;
}

static void AnimAcidPoisonBubble_Step(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
        DestroyAnimSprite(sprite);
}

static void AnimSludgeBombHitParticle(struct Sprite *sprite)
{
    sprite->data[0] = gBattleAnimArgs[2];
    sprite->data[1] = sprite->x;
    sprite->data[2] = sprite->x + gBattleAnimArgs[0];
    sprite->data[3] = sprite->y;
    sprite->data[4] = sprite->y + gBattleAnimArgs[1];

    InitSpriteDataForLinearTranslation(sprite);

    sprite->data[5] = sprite->data[1] / gBattleAnimArgs[2];
    sprite->data[6] = sprite->data[2] / gBattleAnimArgs[2];

    sprite->callback = AnimSludgeBombHitParticle_Step;
}

static void AnimSludgeBombHitParticle_Step(struct Sprite *sprite)
{
    TranslateSpriteLinearFixedPoint(sprite);

    sprite->data[1] -= sprite->data[5];
    sprite->data[2] -= sprite->data[6];

    if (!sprite->data[0])
        DestroyAnimSprite(sprite);
}

static void AnimAcidPoisonDroplet(struct Sprite *sprite)
{
    SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->x, &sprite->y);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[0] = -gBattleAnimArgs[0];

    sprite->x += gBattleAnimArgs[0];
    sprite->y += gBattleAnimArgs[1];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = sprite->x + gBattleAnimArgs[2];
    sprite->data[4] = sprite->y + sprite->data[0];

    // JP: 0x080A67B4 is the JP symbol InitAndRunAnimFastLinearTranslation,
    // which behaves as US pokeemerald's StartAnimLinearTranslation.
    sprite->callback = InitAndRunAnimFastLinearTranslation;
    StoreSpriteCallbackInData6(sprite, DestroyAnimSprite);
}

// Animates a bubble by rising upward, swaying side to side, and
// enlarging the sprite. This is used as an after-effect by poison-type
// moves, along with MOVE_BUBBLE, and MOVE_BUBBLEBEAM.
// arg 0: initial x pixel offset
// arg 1: initial y pixel offset
// arg 2: 0 = single-target, 1 = multi-target
static void AnimBubbleEffect(struct Sprite *sprite)
{
    if (!gBattleAnimArgs[2])
    {
        InitSpritePosToAnimTarget(sprite, TRUE);
    }
    else
    {
        SetAverageBattlerPositions(gBattleAnimTarget, TRUE, &sprite->x, &sprite->y);

        if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
            gBattleAnimArgs[0] = -gBattleAnimArgs[0];

        sprite->x += gBattleAnimArgs[0];
        sprite->y += gBattleAnimArgs[1];
    }

    sprite->callback = AnimBubbleEffect_Step;
}

static void AnimBubbleEffect_Step(struct Sprite *sprite)
{
    sprite->data[0] = (sprite->data[0] + 0xB) & 0xFF;
    sprite->x2 = Sin(sprite->data[0], 4);
    sprite->data[1] += 0x30;
    sprite->y2 = -(sprite->data[1] >> 8);

    if (sprite->affineAnimEnded)
        DestroyAnimSprite(sprite);
}
