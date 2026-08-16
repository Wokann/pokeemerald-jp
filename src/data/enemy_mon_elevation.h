#ifndef POKEEMERALD_JP_ENEMY_MON_ELEVATION_H
#define POKEEMERALD_JP_ENEMY_MON_ELEVATION_H

#include "global.h"

// Enemy-mon elevation (0x82D965C..0x82D97F9), 413 entries
// SPECIES_NONE..SPECIES_EGG.  Values match pokeemerald's
// enemy_mon_elevation.h for the first 412 entries; JP adds the EGG slot.

extern const u8 gEnemyMonElevation[NUM_SPECIES + 1];

#endif // POKEEMERALD_JP_ENEMY_MON_ELEVATION_H
