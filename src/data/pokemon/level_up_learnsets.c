#include "global.h"
#include "pokemon.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/species.h"

#include "level_up_learnsets.h"

#define gLevelUpLearnsets __attribute__((section(".rodata.level_up_learnset_pointers"))) gLevelUpLearnsets
#include "level_up_learnset_pointers.h"
#undef gLevelUpLearnsets
