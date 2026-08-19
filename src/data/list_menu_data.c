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

#define LIST_MENU_EXTRA __attribute__((section(".rodata.list_menu_extra")))

LIST_MENU_EXTRA const u8 gUnknown_85DFB60[] = {
    0x8E, 0x62, 0x5F, 0x01, 0x90, 0x00, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
    0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C, 0x1F, 0x7C,
};
LIST_MENU_EXTRA const u8 gUnknown_85DFB80[] = {
    0x10, 0x00, 0x01, 0x00, 0x2A, 0x00, 0x00, 0x60, 0x01, 0x20, 0x00, 0x03, 0x12, 0x00, 0x06, 0x11,
    0xAC, 0x00, 0x06, 0x11, 0x00, 0x06, 0x11, 0x00, 0x06, 0x00, 0x0B, 0x00, 0x00, 0x4B, 0x22, 0x00,
    0x03, 0x11, 0x02, 0x30, 0x03, 0x21, 0x00, 0x0B, 0x10, 0x03, 0xFF, 0x00, 0x0A, 0x20, 0x03, 0x20,
    0x23, 0x10, 0x2B, 0x10, 0x33, 0x20, 0x3B, 0x10, 0x43, 0x20, 0x4B, 0xFF, 0x20, 0x01, 0x50, 0x27,
    0x50, 0x37, 0x50, 0x47, 0x10, 0x53, 0xC0, 0x01, 0xF0, 0x7F, 0x40, 0x7F, 0xEB, 0x50, 0x47, 0x60,
    0x3F, 0x00, 0x08, 0x11, 0x00, 0x08, 0x11, 0x00, 0x08, 0x00, 0x26, 0x1D, 0x22, 0x20, 0x11, 0x00,
    0x4D, 0xF0, 0x50, 0x20, 0x01, 0x22, 0x10, 0x28, 0x60, 0x22, 0xF0, 0x71, 0x50, 0x01, 0x00, 0x00,
};
LIST_MENU_EXTRA const u8 gUnknown_85DFBF0[] = {
    0x10, 0x00, 0x01, 0x00, 0x00, 0x10, 0x11, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x7D, 0x01, 0xF0,
    0x03, 0x20, 0x03, 0x00, 0x1D, 0x20, 0x06, 0x00, 0x03, 0x10, 0xF0, 0x03, 0x7F, 0x00, 0x50, 0x3E,
    0xF0, 0x01, 0x40, 0x01, 0xF0, 0x53, 0xB0, 0x03, 0xF0, 0x53, 0xE0, 0x03, 0xFF, 0xF0, 0x01, 0x40,
    0x01, 0x10, 0x7B, 0xF0, 0x53, 0x40, 0xB7, 0x40, 0x9C, 0xF0, 0x4F, 0x60, 0x03, 0x80, 0x20, 0x3E,
};
LIST_MENU_EXTRA const u8 gUnknown_85DFC30[] = {
    0x10, 0x80, 0x00, 0x00, 0x00, 0x20, 0x22, 0x00, 0x00, 0x12, 0x11, 0x22, 0x02, 0x09, 0x20, 0x11,
    0x11, 0x21, 0x00, 0x08, 0x11, 0x00, 0x00, 0x08, 0xF9, 0x10, 0x11, 0x20, 0x03, 0x20, 0x0B, 0x30,
    0x01, 0x00, 0x26, 0x00, 0x11, 0x00, 0x04, 0x43, 0x11, 0x00, 0x04, 0x11, 0x11, 0x11, 0x02, 0x30,
    0x03, 0x20, 0x3C, 0x7F, 0x11, 0x10, 0x3B, 0x20, 0x43, 0x10, 0x24, 0xC0, 0x01, 0x10, 0x22, 0xF0,
    0x16, 0x70, 0x01, 0x00,
};
