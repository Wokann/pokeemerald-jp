#include "global.h"
#include "constants/metatile_labels.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "tv.h"

enum
{
    SLOT_MACHINE,
    ROULETTE,
};

// EWRAM @ 0x02039CF4 / 0x02039CF6 (see sym_ewram_jp.txt)
extern u16 sFindThatGamerCoinsSpent;
extern u8 sFindThatGamerWhichGame;
extern void SetTVMetatilesOnMap(int width, int height, u16 metatileId);
extern void ClearPokemonNews(void);

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

void TurnOffTVScreen(void)
{
    SetTVMetatilesOnMap(gBackupMapLayout.width, gBackupMapLayout.height, METATILE_Building_TV_Off);
    DrawWholeMapView();
}

void TurnOnTVScreen(void)
{
    SetTVMetatilesOnMap(gBackupMapLayout.width, gBackupMapLayout.height, METATILE_Building_TV_On);
    DrawWholeMapView();
}

void ClearTVShowData(void)
{
    u8 i, j;

    for (i = 0; i < ARRAY_COUNT(gSaveBlock1Ptr->tvShows); i++)
    {
        gSaveBlock1Ptr->tvShows[i].commonInit.kind = 0;
        gSaveBlock1Ptr->tvShows[i].commonInit.active = 0;
        for (j = 0; j < ARRAY_COUNT(gSaveBlock1Ptr->tvShows[i].commonInit.data); j++)
            gSaveBlock1Ptr->tvShows[i].commonInit.data[j] = 0;
    }
    ClearPokemonNews();
}
