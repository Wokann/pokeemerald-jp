#include "global.h"

extern void ShowContestPainting(void);

void CB2_ContestPainting(void)
{
    ShowContestPainting();
}

extern void HoldContestPainting(void);
extern void RunTextPrinters(void);
extern void UpdatePaletteFade(void);

static void CB2_HoldContestPainting(void)
{
    HoldContestPainting();
    RunTextPrinters();
    UpdatePaletteFade();
}
