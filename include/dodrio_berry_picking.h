#ifndef GUARD_DODRIO_BERRY_PICKING_H
#define GUARD_DODRIO_BERRY_PICKING_H

#include "main.h"

#define NUM_BERRY_TYPES 4 // Blue, Green, Gold, and 'missed'
#define NUM_CLOUDS      2

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

enum {
    GFXFUNC_LOAD,
    GFXFUNC_SHOW_NAMES,
    GFXFUNC_SHOW_RESULTS,
    GFXFUNC_MSG_PLAY_AGAIN,
    GFXFUNC_MSG_SAVING,
    GFXFUNC_MSG_COMM_STANDBY,
    GFXFUNC_ERASE_MSG,
    GFXFUNC_MSG_PLAYER_DROPPED,
    GFXFUNC_STOP,
    GFXFUNC_IDLE,
};

struct GfxFunc
{
    u8 id;
    void (*func)(void);
};

struct WinCoords
{
    u8 left;
    u8 top;
};

void StartDodrioBerryPicking(u16 partyId, MainCallback exitCallback);
void IsDodrioInParty(void);
void ShowDodrioBerryPickingRecords(void);

#endif // GUARD_DODRIO_BERRY_PICKING_H
