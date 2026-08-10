#include "global.h"
#include "sprite.h"

// Sprite data for FLDEFF_SURF_BLOB
#define sBitfield     data[0]

u8 GetSurfBlob_BobState(struct Sprite *sprite)
{
    return sprite->sBitfield & 0xF;
}

// Never TRUE
u8 GetSurfBlob_DontSyncAnim(struct Sprite *sprite)
{
    return (sprite->sBitfield & 0xF0) >> 4;
}

u8 GetSurfBlob_HasPlayerOffset(struct Sprite *sprite)
{
    return (sprite->sBitfield & 0xF00) >> 8;
}
