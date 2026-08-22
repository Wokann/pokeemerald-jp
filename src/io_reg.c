#include "global.h"
#include "io_reg.h"
#include "gba/io_reg.h"

#define IO_REG_DATA(name) __attribute__((section(".rodata.io_reg_data." #name)))

static const u32 sUnused[] IO_REG_DATA(sUnused) =
{
    0,
    0,
    (1 << 26) | (1 << 3),
    (1 << 26) | (1 << 3) | (1 << 1),
    (1 << 26) | (1 << 3) | (1 << 2),
    (1 << 26) | (1 << 3) | (1 << 2) | (1 << 1),
    (1 << 26) | (1 << 4),
    (1 << 26) | (1 << 4) | (1 << 2),
    (1 << 26) | (1 << 4) | (1 << 3),
    (1 << 26) | (1 << 4) | (1 << 3) | (1 << 2),
    (1 << 26) | (1 << 4) | (1 << 1),
    (1 << 26) | (1 << 4) | (1 << 2) | (1 << 1),
    (1 << 26) | (1 << 4) | (1 << 3) | (1 << 1),
    (1 << 26) | (1 << 4) | (1 << 3) | (1 << 2) | (1 << 1),
    (1 << 25) | (1 << 8),
    (1 << 27) | (1 << 10),
};

const u16 gOverworldBackgroundLayerFlags[] IO_REG_DATA(gOverworldBackgroundLayerFlags) =
{
    BLDCNT_TGT2_BG0,
    BLDCNT_TGT2_BG1,
    BLDCNT_TGT2_BG2,
    BLDCNT_TGT2_BG3,
};

const u16 gOrbEffectBackgroundLayerFlags[] IO_REG_DATA(gOrbEffectBackgroundLayerFlags) =
{
    BLDCNT_TGT1_BG0,
    BLDCNT_TGT1_BG1,
    BLDCNT_TGT1_BG2,
    BLDCNT_TGT1_BG3,
};

#undef IO_REG_DATA
