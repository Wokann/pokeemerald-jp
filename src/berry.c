#include "global.h"

extern void SetMainCallback2(void (*callback)(void));
extern void CB2_ChooseBerry(void);

void Bag_ChooseBerry(void)
{
    SetMainCallback2(CB2_ChooseBerry);
}
