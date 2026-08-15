#include "global.h"
#include "sprite.h"
#include "gba/types.h"

// Union-room chat sprite sheets/structures (0x82C5D4C..0x82C5E74)

extern const u16 sKeyboardCursorPal[];
extern const union AnimCmd *const gDummySpriteAnimTable[];
extern const union AffineAnimCmd *const gDummySpriteAffineAnimTable[];
extern void SpriteCB_TextEntryCursor(struct Sprite *sprite);
extern void SpriteCB_TextEntryArrow(struct Sprite *sprite);

extern const u32 sKeyboardCursorTiles[], sTextEntryCursorTiles[], sTextEntryArrowTiles[], sRButtonGfxTiles[];
extern const u32 gUnionRoomChat_RButtonLabels[];

// 0x82C5D4C
const struct CompressedSpriteSheet sChatSpriteSheets[] = {
    { sKeyboardCursorTiles,          0x1000, 0 },
    { sTextEntryArrowTiles,          0x0040, 1 },
    { sTextEntryCursorTiles,         0x0040, 2 },
    { sRButtonGfxTiles,              0x0080, 3 },
    { gUnionRoomChat_RButtonLabels,  0x0400, 4 },
};

// 0x82C5D74
// 0x82C5D74
const struct SpritePalette sSpritePalette = { sKeyboardCursorPal, 0 };

// 0x82C5D7C
const struct OamData sOam_KeyboardCursor = { .shape = 1, .size = 3, .priority = 1 };

// 0x82C5D84..0x82C5DA0
const union AnimCmd sAnim_KeyboardCursor_Open[] = { ANIMCMD_FRAME(0x00, 30), ANIMCMD_END };
const union AnimCmd sAnim_KeyboardCursor_Closed[] = { ANIMCMD_FRAME(0x20, 30), ANIMCMD_END };
const union AnimCmd sAnim_KeyboardCursorWide_Open[] = { ANIMCMD_FRAME(0x40, 30), ANIMCMD_END };
const union AnimCmd sAnim_KeyboardCursorWide_Closed[] = { ANIMCMD_FRAME(0x60, 30), ANIMCMD_END };

// 0x82C5DA4
const union AnimCmd *const sAnims_KeyboardCursor[] = {
    sAnim_KeyboardCursor_Open,
    sAnim_KeyboardCursor_Closed,
    sAnim_KeyboardCursorWide_Open,
    sAnim_KeyboardCursorWide_Closed,
};

// 0x82C5DB4
const struct SpriteTemplate sSpriteTemplate_KeyboardCursor = {
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOam_KeyboardCursor,
    .anims = sAnims_KeyboardCursor,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// 0x82C5DCC
const struct OamData sOam_TextEntrySprite = { .shape = 2, .size = 0, .priority = 2 };

// 0x82C5DD4
const struct SpriteTemplate sSpriteTemplate_TextEntryCursor = {
    .tileTag = 2,
    .paletteTag = 0,
    .oam = &sOam_TextEntrySprite,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TextEntryCursor,
};

// 0x82C5DEC
const struct SpriteTemplate sSpriteTemplate_TextEntryArrow = {
    .tileTag = 1,
    .paletteTag = 0,
    .oam = &sOam_TextEntrySprite,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TextEntryArrow,
};

// 0x82C5E04..0x82C5E34
const struct OamData sOam_RButtonIcon = { .shape = 0, .size = 1, .priority = 2 };
const struct OamData sOam_RButtonLabel = { .shape = 1, .size = 2, .priority = 2 };
const union AnimCmd sAnim_ToggleCaseIcon[] = { ANIMCMD_FRAME(0x00, 2), ANIMCMD_END };
const union AnimCmd sAnim_ToggleCaseIcon_Duplicate1[] = { ANIMCMD_FRAME(0x08, 2), ANIMCMD_END };
const union AnimCmd sAnim_ToggleCaseIcon_Duplicate2[] = { ANIMCMD_FRAME(0x10, 2), ANIMCMD_END };
const union AnimCmd sAnim_RegisterIcon[] = { ANIMCMD_FRAME(0x18, 2), ANIMCMD_END };

// 0x82C5E34
const union AnimCmd *const sAnims_RButtonLabels[] = {
    sAnim_ToggleCaseIcon,
    sAnim_ToggleCaseIcon_Duplicate1,
    sAnim_ToggleCaseIcon_Duplicate2,
    sAnim_RegisterIcon,
};

// 0x82C5E44
const struct SpriteTemplate sSpriteTemplate_RButtonIcon = {
    .tileTag = 3,
    .paletteTag = 0,
    .oam = &sOam_RButtonIcon,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// 0x82C5E5C
const struct SpriteTemplate sSpriteTemplate_RButtonLabels = {
    .tileTag = 4,
    .paletteTag = 0,
    .oam = &sOam_RButtonLabel,
    .anims = sAnims_RButtonLabels,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
