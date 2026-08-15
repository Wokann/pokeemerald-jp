#ifndef GUARD_BERRY_CRUSH_H
#define GUARD_BERRY_CRUSH_H

#include "main.h"

struct BerryCrushPlayerCoords
{
    u8 playerId;
    u8 windowGfxX;
    u8 windowGfxY;
    s16 impactXOffset;
    s16 impactYOffset;
    s16 berryXOffset;
    s16 berryXDest;
};

// IDs for the main berry crush game functions
enum {
    CMD_NONE,
    CMD_FADE,
    CMD_WAIT_FADE,
    CMD_PRINT_MSG,
    CMD_SHOW_GAME,
    CMD_HIDE_GAME,
    CMD_READY_BEGIN,
    CMD_ASK_PICK_BERRY,
    CMD_PICK_BERRY,
    CMD_WAIT_BERRIES,
    CMD_DROP_BERRIES,
    CMD_DROP_LID,
    CMD_COUNTDOWN,
    CMD_PLAY_GAME_LEADER,
    CMD_PLAY_GAME_MEMBER,
    CMD_FINISH_GAME,
    CMD_TIMES_UP,
    CMD_CALC_RESULTS,
    CMD_SHOW_RESULTS,
    CMD_SAVE,
    CMD_ASK_PLAY_AGAIN,
    CMD_COMM_PLAY_AGAIN,
    CMD_PLAY_AGAIN_YES,
    CMD_PLAY_AGAIN_NO,
    CMD_CLOSE_LINK,
    CMD_QUIT,
};

void StartBerryCrush(MainCallback exitCallback);

#endif // GUARD_BERRY_CRUSH_H
