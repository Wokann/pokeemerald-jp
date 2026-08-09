#include "global.h"

extern u32 gTrainerHillVBlankCounter;
extern u16 sTrainerId;

void ClearTrainerHillVBlankCounter(void)
{
    gTrainerHillVBlankCounter = 0;
}

u16 GetGeneratedTrainerIdLower(void)
{
    return sTrainerId;
}
