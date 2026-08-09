#include "global.h"
#include "pokemon.h"

void CopyMon(void *dest, void *src, size_t size)
{
    memcpy(dest, src, size);
}

extern const u8 gFacilityClassToPicIndex[];

u16 FacilityClassToPicIndex(u16 facilityClass)
{
    return gFacilityClassToPicIndex[facilityClass];
}
