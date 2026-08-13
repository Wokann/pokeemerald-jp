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
