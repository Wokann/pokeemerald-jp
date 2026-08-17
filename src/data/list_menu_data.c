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

void SpriteCallback_RedArrowCursor(struct Sprite *sprite);

const struct Subsprite sSubsprite_RedOutline1 =
{
    .x = 0,
    .y = 0,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .tileOffset = 0,
    .priority = 0,
};

const struct Subsprite sSubsprite_RedOutline2 =
{
    .x = 0,
    .y = 0,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .tileOffset = 1,
    .priority = 0,
};

const struct Subsprite sSubsprite_RedOutline3 =
{
    .x = 0,
    .y = 0,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .tileOffset = 2,
    .priority = 0,
};

const struct Subsprite sSubsprite_RedOutline4 =
{
    .x = 0,
    .y = 0,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .tileOffset = 3,
    .priority = 0,
};

const struct Subsprite sSubsprite_RedOutline5 =
{
    .x = 0,
    .y = 0,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .tileOffset = 4,
    .priority = 0,
};

const struct Subsprite sSubsprite_RedOutline6 =
{
    .x = 0,
    .y = 0,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .tileOffset = 5,
    .priority = 0,
};

const struct Subsprite sSubsprite_RedOutline7 =
{
    .x = 0,
    .y = 0,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .tileOffset = 6,
    .priority = 0,
};

const struct Subsprite sSubsprite_RedOutline8 =
{
    .x = 0,
    .y = 0,
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .tileOffset = 7,
    .priority = 0,
};

const struct OamData sOamData_RedArrowCursor =
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

const union AnimCmd sSpriteAnim_RedArrowCursor[] =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

const union AnimCmd *const sSpriteAnimTable_RedArrowCursor[] =
{
    sSpriteAnim_RedArrowCursor
};

const struct SpriteTemplate sSpriteTemplate_RedArrowCursor =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOamData_RedArrowCursor,
    .anims = sSpriteAnimTable_RedArrowCursor,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallback_RedArrowCursor,
};
