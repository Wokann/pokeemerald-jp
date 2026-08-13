#include "global.h"
#include "battle_anim.h"
#include "bg.h"
#include "palette.h"
#include "task.h"
#include "constants/battle_anim.h"

extern u8 gAnimVisualTaskCount;

static void FadeScreenToWhite_Step(u8 taskId);

void AnimTask_SetPsychicBackground(u8 taskId)
{
    gTasks[taskId].func = FadeScreenToWhite_Step;
    gAnimVisualTaskCount--;
}

static void FadeScreenToWhite_Step(u8 taskId)
{
    int i;
    u16 lastColor;
    u8 paletteIndex = GetBattleBgPaletteNum();

    if (++gTasks[taskId].data[5] == 4)
    {
        lastColor = gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + 11];
        for (i = 10; i > 0; i--)
            gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + i + 1] = gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + i];

        gPlttBufferFaded[BG_PLTT_ID(paletteIndex) + 1] = lastColor;

        lastColor = gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + 11];
        for (i = 10; i > 0; i--)
            gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + i + 1] = gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + i];
        gPlttBufferUnfaded[BG_PLTT_ID(paletteIndex) + 1] = lastColor;

        gTasks[taskId].data[5] = 0;
    }

    if ((u16)gBattleAnimArgs[7] == 0xFFFF)
        DestroyTask(taskId);
}

static void AnimSpikes_Step1(struct Sprite *sprite);
static void AnimSpikes_Step2(struct Sprite *sprite);

static void AnimSpikes(struct Sprite *sprite)
{
    s16 x, y;

    InitSpritePosToAnimAttacker(sprite, TRUE);
    SetAverageBattlerPositions(gBattleAnimTarget, FALSE, &x, &y);

    if (GetBattlerSide(gBattleAnimAttacker) != B_SIDE_PLAYER)
        gBattleAnimArgs[2] = -gBattleAnimArgs[2];

    sprite->data[0] = gBattleAnimArgs[4];
    sprite->data[2] = x + gBattleAnimArgs[2];
    sprite->data[4] = y + gBattleAnimArgs[3];
    sprite->data[5] = -50;

    InitAnimArcTranslation(sprite);
    sprite->callback = AnimSpikes_Step1;
}

static void AnimSpikes_Step1(struct Sprite *sprite)
{
    if (TranslateAnimHorizontalArc(sprite))
    {
        sprite->data[0] = 30;
        sprite->data[1] = 0;
        sprite->callback = WaitAnimForDuration;
        StoreSpriteCallbackInData6(sprite, AnimSpikes_Step2);
    }
}

static void AnimSpikes_Step2(struct Sprite *sprite)
{
    if (sprite->data[1] & 1)
        sprite->invisible ^= 1;

    if (++sprite->data[1] == 16)
        DestroyAnimSprite(sprite);
}
