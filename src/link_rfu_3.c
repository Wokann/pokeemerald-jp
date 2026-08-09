#include "global.h"

extern u8 *StringCopy(u8 *dest, const u8 *src);

static void CopyTrainerRecord(struct TrainerNameRecord *dest, u32 trainerId, const u8 *name)
{
    dest->trainerId = trainerId;
    StringCopy(dest->trainerName, name);
}
