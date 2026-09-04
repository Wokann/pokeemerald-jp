#include "global.h"
#include "bg.h"
#include "graphics.h"
#include "menu.h"
#include "sprite.h"
#include "constants/characters.h"

extern void Task_DrawSelectionSummary(u8 taskId);
extern void Task_DrawSelectionTrade(u8 taskId);
extern const u8 gUnknown_85CA294[];
extern const u8 gUnknown_85CA2B4[];
extern const u8 gUnknown_85CA2CC[];

// This JP data owner is compiled separately from src/trade.c.
enum
{
    TEXT_CANCEL,
    TEXT_CHOOSE_MON,
    TEXT_SUMMARY,
    TEXT_TRADE,
    TEXT_CANCEL_TRADE,
    TEXT_JP_QUIT,
};

enum
{
    MSG_STANDBY,
    MSG_CANCELED,
    MSG_ONLY_MON1,
    MSG_ONLY_MON2,
    MSG_WAITING_FOR_FRIEND,
    MSG_FRIEND_WANTS_TO_TRADE,
    MSG_MON_CANT_BE_TRADED,
    MSG_EGG_CANT_BE_TRADED,
    MSG_FRIENDS_MON_CANT_BE_TRADED,
};

// Keep the large JP resource block out of src/trade.c: agbcc cannot compile
// that already-large translation unit once these INCBIN initializers are added.
#include "trade.h"

// The following later Trade-animation table remains a raw resource. Retain
// its existing typed entry point until its own owner is decompiled.
__asm__(
    ".global sTradeYesNoWindowTemplate\n"
    ".set sTradeYesNoWindowTemplate, gUnknown_8300CAC\n"
);
