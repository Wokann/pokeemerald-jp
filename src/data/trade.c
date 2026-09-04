#include "global.h"
#include "graphics.h"
#include "sprite.h"

// Keep the large JP resource block out of src/trade.c: agbcc cannot compile
// that already-large translation unit once these INCBIN initializers are added.
#include "trade.h"

// The following later Trade-animation tables remain raw resources. Retain
// their existing typed entry points until their own owner is decompiled.
__asm__(
    ".global sActionTexts\n"
    ".set sActionTexts, gUnknown_8300AFC\n"
    ".global sSelectTradeMonActions\n"
    ".set sSelectTradeMonActions, gUnknown_8300B28\n"
    ".global sTradeYesNoWindowTemplate\n"
    ".set sTradeYesNoWindowTemplate, gUnknown_8300CAC\n"
);
