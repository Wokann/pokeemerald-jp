#include "global.h"
#include "heal_location.h"
#include "constants/heal_locations.h"

// JP layout: 23 entries at 0x0857B104, [0] is a placeholder, real
// locations are [1..22] (pokeemerald stores them 0-based without the
// placeholder).
extern const struct HealLocation sHealLocations[NUM_HEAL_LOCATIONS];

u32 GetHealLocationIndexByMap(u16 mapGroup, u16 mapNum)
{
    u32 i = 0;
    const struct HealLocation *loc = &sHealLocations[1];

    for (; i < NUM_HEAL_LOCATIONS - 1; i++)
    {
        if (loc->mapGroup == mapGroup && loc->mapNum == mapNum)
            return i + 1;
        loc++;
    }
    return 0;
}

const struct HealLocation *GetHealLocationByMap(u16 mapGroup, u16 mapNum)
{
    u32 index = GetHealLocationIndexByMap(mapGroup, mapNum);

    if (index == 0)
        return NULL;
    return &sHealLocations[index];
}

const struct HealLocation *GetHealLocation(u32 index)
{
    if (index == 0)
        return NULL;
    if (index > NUM_HEAL_LOCATIONS - 1)
        return NULL;
    return &sHealLocations[index];
}
