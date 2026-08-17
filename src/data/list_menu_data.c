#include "global.h"
#include "gba/types.h"
#include "sprite.h"

void SpriteCallback_ScrollIndicatorArrow(struct Sprite *sprite);
extern const union AffineAnimCmd *const gDummySpriteAffineAnimTable[];

const struct
{
    u8 animNum:4;
    u8 bounceDir:4;
    u8 multiplier;
    u16 frequency;
} sScrollIndicatorTemplates[] =
{
    {0, 0, 2, 8},
    {1, 0, 2, -8},
    {2, 1, 2, 8},
    {3, 1, 2, -8},
};

const struct OamData sOamData_ScrollArrowIndicator =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x16),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0
};

const union AnimCmd sSpriteAnim_ScrollArrowIndicator0[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

const union AnimCmd sSpriteAnim_ScrollArrowIndicator1[] =
{
    ANIMCMD_FRAME(0, 30, 1, 0),
    ANIMCMD_END
};

const union AnimCmd sSpriteAnim_ScrollArrowIndicator2[] =
{
    ANIMCMD_FRAME(4, 30),
    ANIMCMD_END
};

const union AnimCmd sSpriteAnim_ScrollArrowIndicator3[] =
{
    ANIMCMD_FRAME(4, 30, 0, 1),
    ANIMCMD_END
};

const union AnimCmd *const sSpriteAnimTable_ScrollArrowIndicator[] =
{
    sSpriteAnim_ScrollArrowIndicator0,
    sSpriteAnim_ScrollArrowIndicator1,
    sSpriteAnim_ScrollArrowIndicator2,
    sSpriteAnim_ScrollArrowIndicator3
};

const struct SpriteTemplate sSpriteTemplate_ScrollArrowIndicator =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOamData_ScrollArrowIndicator,
    .anims = sSpriteAnimTable_ScrollArrowIndicator,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_ScrollIndicatorArrow,
};
