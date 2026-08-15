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

void StartBerryCrush(MainCallback exitCallback);

#endif // GUARD_BERRY_CRUSH_H
