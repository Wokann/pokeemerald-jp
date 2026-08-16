#ifndef GUARD_DODRIO_BERRY_PICKING_H
#define GUARD_DODRIO_BERRY_PICKING_H

#include "main.h"

enum {
    FUNC_INTRO,
    FUNC_INIT_COUNTDOWN,
    FUNC_COUNTDOWN,
    FUNC_WAIT_START,
    FUNC_PLAY_GAME,
    FUNC_INIT_RESULTS,
    FUNC_RESULTS,
    FUNC_ASK_PLAY_AGAIN,
    FUNC_END_LINK,
    FUNC_EXIT,
    FUNC_RESET_GAME,
    FUNC_WAIT_END_GAME,
};

void StartDodrioBerryPicking(u16 partyId, MainCallback exitCallback);
void IsDodrioInParty(void);
void ShowDodrioBerryPickingRecords(void);

#endif // GUARD_DODRIO_BERRY_PICKING_H
