#include "global.h"

extern void ApplyNewEncryptionKeyToBagItems(u32 newKey);

void ApplyNewEncryptionKeyToBagItems_(u32 newKey)
{
    ApplyNewEncryptionKeyToBagItems(newKey);
}
