#include "global.h"

// Trade-request and communicating texts
ALIGNED(4) const u8 sText_DoYouWantXMode[] = _("{B_COPY_VAR_2}を　したいのかい？");

ALIGNED(4) const u8 sText_DoYouWantXMode2[] = _("{B_COPY_VAR_2}で　いいかしら？");

const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2,
};

ALIGNED(4) const u8 sText_CommunicatingPleaseWait[] = _(
    "はなしかけています⋯\n"
    "しょうしょう　おまちください");

ALIGNED(4) const u8 sText_AwaitingPlayersResponseAboutTrade[] = _(
    "{B_COPY_VAR_1}からの　こうかんの\n"
    "へんじを　まっています⋯");

ALIGNED(4) const u8 sText_Communicating[] = _(
    "はなしかけています{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·\n"
    "{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·");

ALIGNED(4) const u8 sText_CommunicatingWithPlayer[] = _(
    "{B_COPY_VAR_1}に　はなしかけています{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·\n"
    "{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·");

ALIGNED(4) const u8 sText_PleaseWaitAWhile[] = _(
    "しょうしょうおまちください{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·\n"
    "{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·{PAUSE 15}·");

const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile,
};

