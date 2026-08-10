#include "global.h"
#include "save_location.h"

#define LIST_END 0xFFFF

extern const u16 sSaveLocationPokeCenterList[];
extern const u16 sSaveLocationReloadLocList[];
extern const u16 sEmptyMapList[];

static bool32 IsCurMapInLocationList(const u16 *list)
{
    s32 i;
    u16 map = (gSaveBlock1Ptr->location.mapGroup << 8) + gSaveBlock1Ptr->location.mapNum;

    for (i = 0; list[i] != LIST_END; i++)
    {
        if (list[i] == map)
            return TRUE;
    }

    return FALSE;
}

static bool32 IsCurMapPokeCenter(void)
{
    return IsCurMapInLocationList(sSaveLocationPokeCenterList);
}

static bool32 IsCurMapReloadLocation(void)
{
    return IsCurMapInLocationList(sSaveLocationReloadLocList);
}

// Nulled out list. Unknown what this would have been.
static bool32 IsCurMapInEmptyList(void)
{
    return IsCurMapInLocationList(sEmptyMapList);
}

static void TrySetPokeCenterWarpStatus(void)
{
    if (!IsCurMapPokeCenter())
        gSaveBlock2Ptr->specialSaveWarpFlags &= ~POKECENTER_SAVEWARP;
    else
        gSaveBlock2Ptr->specialSaveWarpFlags |= POKECENTER_SAVEWARP;
}

static void TrySetReloadWarpStatus(void)
{
    if (!IsCurMapReloadLocation())
        gSaveBlock2Ptr->specialSaveWarpFlags &= ~LOBBY_SAVEWARP;
    else
        gSaveBlock2Ptr->specialSaveWarpFlags |= LOBBY_SAVEWARP;
}

// Unknown save warp flag. Never set because map list is empty.
static void TrySetUnknownWarpStatus(void)
{
    if (!IsCurMapInEmptyList())
        gSaveBlock2Ptr->specialSaveWarpFlags &= ~UNK_SPECIAL_SAVE_WARP_FLAG_3;
    else
        gSaveBlock2Ptr->specialSaveWarpFlags |= UNK_SPECIAL_SAVE_WARP_FLAG_3;
}

void TrySetMapSaveWarpStatus(void)
{
    TrySetPokeCenterWarpStatus();
    TrySetReloadWarpStatus();
    TrySetUnknownWarpStatus();
}

void SetUnlockedPokedexFlags(void)
{
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 15);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 0);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 1);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 2);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 4);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 5);
    gSaveBlock2Ptr->gcnLinkFlags |= (1 << 3);
}

void SetChampionSaveWarp(void)
{
    gSaveBlock2Ptr->specialSaveWarpFlags |= CHAMPION_SAVEWARP;
}
