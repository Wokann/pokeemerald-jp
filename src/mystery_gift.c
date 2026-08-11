#include "global.h"

// JP: still in asm/mevent2.s and asm/easy_chat.s; bound via ld_script_jp.txt.
extern void ClearSavedWonderNewsMetadata(void);
extern void InitQuestionnaireWords(void);

void ClearMysteryGift(void)
{
    u32 fill = 0;
    CpuSet(&fill, &gSaveBlock1Ptr->mysteryGift, 0x0500007A);
    ClearSavedWonderNewsMetadata();
    InitQuestionnaireWords();
}
