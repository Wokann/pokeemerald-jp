#include "global.h"

// Wireless response and short menu texts
ALIGNED(4) const u8 sText_AwaitingResponseFromWirelessSystem[] = _(
    "ジョイスポットからの\n"
    "へんじを　まっています");

ALIGNED(4) const u8 sText_PleaseWaitForOtherTrainersToGather[] = _(
    "ほかの　さんかしゃが　そろうまで\n"
    "しょうしょう　おまちください");

ALIGNED(4) const u8 sText_NoCardsSharedRightNow[] = _(
    "ただいま　カードの　はいふは\n"
    "おこなわれて　いないようです⋯");

ALIGNED(4) const u8 sText_NoNewsSharedRightNow[] = _(
    "ただいま　ニュースの　はいふは\n"
    "おこなわれて　いないようです⋯");

const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow,
};

ALIGNED(4) const u8 sText_Battle[] = _("たいせん");

ALIGNED(4) const u8 sText_Chat2[] = _("チャット");

ALIGNED(4) const u8 sText_Greetings[] = _("あいさつ");

ALIGNED(4) const u8 sText_Exit[] = _("やめる");

ALIGNED(4) const u8 sText_Exit2[] = _("とじる");

ALIGNED(4) const u8 sText_Info[] = _("せつめいをきく");

