#include "global.h"

extern void DoSoftReset(void);

static void DoSoftReset_(void)
{
    DoSoftReset();
}
