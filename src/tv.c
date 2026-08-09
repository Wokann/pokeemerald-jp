#include "global.h"
#include "tv.h"

enum
{
    SLOT_MACHINE,
    ROULETTE,
};

// EWRAM @ 0x02039CF4 / 0x02039CF6 (see sym_ewram_jp.txt)
extern u16 sFindThatGamerCoinsSpent;
extern u8 sFindThatGamerWhichGame;

void AlertTVThatPlayerPlayedSlotMachine(u16 nCoinsSpent)
{
    sFindThatGamerWhichGame = SLOT_MACHINE;
    sFindThatGamerCoinsSpent = nCoinsSpent;
}

void AlertTVThatPlayerPlayedRoulette(u16 nCoinsSpent)
{
    sFindThatGamerWhichGame = ROULETTE;
    sFindThatGamerCoinsSpent = nCoinsSpent;
}
