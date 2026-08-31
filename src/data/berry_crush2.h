#ifndef POKEEMERALD_JP_BERRY_CRUSH2_H
#define POKEEMERALD_JP_BERRY_CRUSH2_H

#include "global.h"
#include "berry_crush.h"
#include "digit_obj_util.h"
#include "link.h"
#include "sprite.h"

// Berry-crush sprite/table data (0x82C7A08..0x82C7C40)

extern const u8 gBerryCrush_Crusher_Gfx[]; // packed LZ streams, 0x82C6104 (src/graphics.c)
extern const u16 gBerryCrush_Crusher_Pal[]; // packed palettes, 0x82C5F84 (src/graphics.c)
extern const struct OamData gOamData_AffineOff_ObjNormal_16x16;
extern const struct OamData gOamData_AffineOff_ObjNormal_32x32;
extern const struct OamData gOamData_AffineOff_ObjNormal_64x64;
extern const struct OamData gUnknown_84FD040[]; // 0x84FD040 OamData table (asm)
extern void SpriteCB_Impact(struct Sprite *sprite); // src/berry_crush.c

// 0x82C7A08 - index into sPlayerCoords by (playerCount - 2) and player slot.
const u8 sPlayerIdToPosId[MAX_RFU_PLAYERS - 1][MAX_RFU_PLAYERS] =
{
    { 1, 3, 0, 0, 0 },
    { 0, 1, 3, 0, 0 },
    { 1, 3, 2, 4, 0 },
    { 0, 1, 3, 2, 4 },
};

// 0x82C7A1C
const struct BerryCrushPlayerCoords sPlayerCoords[MAX_RFU_PLAYERS] =
{
    {
        .playerId = 0,
        .windowGfxX = 0,
        .windowGfxY = 0,
        .impactXOffset = 0,
        .impactYOffset = -16,
        .berryXOffset = 0,
        .berryXDest = 0,
    },
    {
        .playerId = 1,
        .windowGfxX = 0,
        .windowGfxY = 3,
        .impactXOffset = -28,
        .impactYOffset = -4,
        .berryXOffset = -24,
        .berryXDest = 16,
    },
    {
        .playerId = 2,
        .windowGfxX = 0,
        .windowGfxY = 6,
        .impactXOffset = -16,
        .impactYOffset = 20,
        .berryXOffset = -8,
        .berryXDest = 16,
    },
    {
        .playerId = 3,
        .windowGfxX = 20,
        .windowGfxY = 3,
        .impactXOffset = 28,
        .impactYOffset = -4,
        .berryXOffset = 32,
        .berryXDest = -8,
    },
    {
        .playerId = 4,
        .windowGfxX = 20,
        .windowGfxY = 6,
        .impactXOffset = 16,
        .impactYOffset = 20,
        .berryXOffset = 16,
        .berryXDest = -8,
    },
};

// 0x82C7A58
const s8 sImpactCoords[3][2] =
{
    {  0,  0 },
    { -1,  0 },
    {  1,  1 },
};

// 0x82C7A5E
const s8 sSparkleCoords[11][2] =
{
    {   0,   0 },
    { -16,  -4 },
    {  16,  -4 },
    {  -8,  -2 },
    {   8,  -2 },
    { -24,  -8 },
    {  24,  -8 },
    { -32, -12 },
    {  32, -12 },
    { -40, -16 },
    {  40, -16 },
};

// 0x82C7A74 - JP pads the five berry tags with a 0 terminator.
const u16 sPlayerBerrySpriteTags[6] =
{
    5, 6, 7, 8, 9, 0
};

// 0x82C7A80 - the four sheets point into the packed gBerryCrush_Crusher_Gfx.
const struct CompressedSpriteSheet sSpriteSheets[] =
{
    { .data = (const u32 *)((const u8 *)gBerryCrush_Crusher_Gfx + 0xB10), .size = 0x800, .tag = 1 }, // TAG_CRUSHER_BASE
    { .data = (const u32 *)((const u8 *)gBerryCrush_Crusher_Gfx + 0xE3C), .size = 0xE00, .tag = 2 }, // GFXTAG_IMPACT
    { .data = (const u32 *)((const u8 *)gBerryCrush_Crusher_Gfx + 0x11B8), .size = 0x700, .tag = 3 }, // GFXTAG_SPARKLE
    { .data = (const u32 *)((const u8 *)gBerryCrush_Crusher_Gfx + 0x1304), .size = 0x2C0, .tag = 4 }, // TAG_TIMER_DIGITS
    {},
};

// 0x82C7AA8 - the three palettes point into the packed gBerryCrush_Crusher_Pal.
const struct SpritePalette sSpritePals[] =
{
    { .data = (const u16 *)((const u8 *)gBerryCrush_Crusher_Pal + 0x120), .tag = 1 }, // TAG_CRUSHER_BASE
    { .data = (const u16 *)((const u8 *)gBerryCrush_Crusher_Pal + 0x140), .tag = 2 }, // PALTAG_EFFECT
    { .data = (const u16 *)((const u8 *)gBerryCrush_Crusher_Pal + 0x160), .tag = 4 }, // TAG_TIMER_DIGITS
    {},
};

// 0x82C7AC8 - animation scripts.
static const union AnimCmd sAnim_CrusherBase[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Impact_Small[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Impact_Big[] =
{
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_FRAME(64, 2),
    ANIMCMD_FRAME(80, 2),
    ANIMCMD_FRAME(96, 2),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Sparkle_Small[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(4, 2),
    ANIMCMD_FRAME(8, 2),
    ANIMCMD_FRAME(12, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(20, 2),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_Sparkle_Big[] =
{
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_FRAME(28, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_FRAME(36, 4),
    ANIMCMD_FRAME(40, 4),
    ANIMCMD_FRAME(44, 4),
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(52, 4),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd sAnim_Timer[] =
{
    ANIMCMD_FRAME(20, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_PlayerBerry[] =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_PlayerBerry_0[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, 2, 1),
    AFFINEANIMCMD_JUMP(1)
};

static const union AffineAnimCmd sAffineAnim_PlayerBerry_1[] =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(0, 0, -2, 1),
    AFFINEANIMCMD_JUMP(1)
};

static const union AnimCmd *const sAnims_CrusherBase[] = { sAnim_CrusherBase };
static const union AnimCmd *const sAnims_Impact[] = { sAnim_Impact_Small, sAnim_Impact_Big };
static const union AnimCmd *const sAnims_Sparkle[] = { sAnim_Sparkle_Small, sAnim_Sparkle_Big };
static const union AnimCmd *const sAnims_Timer[] = { sAnim_Timer };
static const union AnimCmd *const sAnims_PlayerBerry[] = { sAnim_PlayerBerry };
static const union AffineAnimCmd *const sAffineAnims_PlayerBerry[] = { sAffineAnim_PlayerBerry_0, sAffineAnim_PlayerBerry_1 };

// 0x82C7B98
const struct SpriteTemplate sSpriteTemplate_CrusherBase =
{
    .tileTag = 1, // TAG_CRUSHER_BASE
    .paletteTag = 1, // TAG_CRUSHER_BASE
    .oam = &gOamData_AffineOff_ObjNormal_64x64,
    .anims = sAnims_CrusherBase,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// 0x82C7BB0
const struct SpriteTemplate sSpriteTemplate_Impact =
{
    .tileTag = 2, // GFXTAG_IMPACT
    .paletteTag = 2, // PALTAG_EFFECT
    .oam = &gOamData_AffineOff_ObjNormal_32x32,
    .anims = sAnims_Impact,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Impact,
};

// 0x82C7BC8
const struct SpriteTemplate sSpriteTemplate_Sparkle =
{
    .tileTag = 3, // GFXTAG_SPARKLE
    .paletteTag = 2, // PALTAG_EFFECT
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sAnims_Sparkle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// 0x82C7BE0
const struct SpriteTemplate sSpriteTemplate_Timer =
{
    .tileTag = 4, // TAG_TIMER_DIGITS
    .paletteTag = 4, // TAG_TIMER_DIGITS
    .oam = &gUnknown_84FD040[2],
    .anims = sAnims_Timer,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

// 0x82C7BF8
const struct SpriteTemplate sSpriteTemplate_PlayerBerry =
{
    .tileTag = 5, // TAG_PLAYER1_BERRY
    .paletteTag = 5, // TAG_PLAYER1_BERRY
    .oam = &gUnknown_84FD040[20],
    .anims = sAnims_PlayerBerry,
    .images = NULL,
    .affineAnims = sAffineAnims_PlayerBerry,
    .callback = SpriteCallbackDummy,
};

// 0x82C7C10 - timer digit printers; the JP first entry keeps strConvMode = 1.
const struct DigitObjUtilTemplate sDigitObjTemplates[] =
{
    { // Minutes
        .strConvMode = 1,
        .shape = 2,
        .size = 0,
        .priority = 0,
        .oamCount = 2,
        .xDelta = 8,
        .x = 156,
        .y = 0,
        .spriteSheet = (const struct SpriteSheet *)&sSpriteSheets[3],
        .spritePal = &sSpritePals[2],
    },
    { // Seconds
        .strConvMode = 0,
        .shape = 2,
        .size = 0,
        .priority = 0,
        .oamCount = 2,
        .xDelta = 8,
        .x = 180,
        .y = 0,
        .spriteSheet = (const struct SpriteSheet *)&sSpriteSheets[3],
        .spritePal = &sSpritePals[2],
    },
    { // 1/60ths of a second
        .strConvMode = 0,
        .shape = 2,
        .size = 0,
        .priority = 0,
        .oamCount = 2,
        .xDelta = 8,
        .x = 204,
        .y = 0,
        .spriteSheet = (const struct SpriteSheet *)&sSpriteSheets[3],
        .spritePal = &sSpritePals[2],
    },
};

#endif // POKEEMERALD_JP_BERRY_CRUSH2_H
