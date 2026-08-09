#include "global.h"
#include "event_data.h"
#include "landmark.h"
#include "constants/region_map_sections.h"

struct Landmark
{
    const u8 *name;
    u16 flag;
};

struct LandmarkList
{
    mapsec_u8_t mapSection;
    u8 id;
    const struct Landmark *const *landmarks;
};

extern const struct LandmarkList sLandmarkLists[];  // ROM @ 0x08598C68

const u8 *GetLandmarkName(mapsec_u8_t mapSection, u8 id, u8 count)
{
    const struct Landmark *const *landmarks = GetLandmarks(mapSection, id);

    if (!landmarks)
        return NULL;

    while (1)
    {
        const struct Landmark *landmark = *landmarks;

        if (landmark->flag == 0xFFFF || FlagGet(landmark->flag) == TRUE)
        {
            if (count == 0)
                break;
            else
                count--;
        }

        landmarks++;
        if (!*landmarks)
            return NULL;
    }

    return (*landmarks)->name;
}

const struct Landmark *const *GetLandmarks(mapsec_u8_t mapSection, u8 id)
{
    u16 i = 0;

    for (; sLandmarkLists[i].mapSection != MAPSEC_NONE; i++)
    {
        if (sLandmarkLists[i].mapSection > mapSection)
            return NULL;
        if (sLandmarkLists[i].mapSection == mapSection)
            break;
    }

    if (sLandmarkLists[i].mapSection == MAPSEC_NONE)
        return NULL;

    for (; sLandmarkLists[i].mapSection == mapSection; i++)
    {
        if (sLandmarkLists[i].id == id)
            return sLandmarkLists[i].landmarks;
    }

    return NULL;
}
