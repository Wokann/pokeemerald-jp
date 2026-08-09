#include "global.h"
#include "constants/flags.h"

extern void FlagSet(u16 flag);
extern void FlagClear(u16 flag);

void EnableMysteryEvent(void)
{
    FlagSet(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void DisableMysteryEvent(void)
{
    FlagClear(FLAG_SYS_MYSTERY_EVENT_ENABLE);
}

void EnableMysteryGift(void)
{
    FlagSet(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}

void DisableMysteryGift(void)
{
    FlagClear(FLAG_SYS_MYSTERY_GIFT_ENABLE);
}
