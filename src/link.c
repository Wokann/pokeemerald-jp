#include "global.h"

extern u8 gLinkErrorOccurred;

u8 HasLinkErrorOccurred(void)
{
    return gLinkErrorOccurred;
}
