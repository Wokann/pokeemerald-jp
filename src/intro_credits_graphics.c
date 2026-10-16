#include "global.h"
#include "intro_credits_graphics.h"
#include "palette.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "task.h"
#include "main.h"
#include "graphics.h"
#include "constants/rgb.h"

#define TAG_BICYCLE 1001
#define TAG_BRENDAN 1002
#define TAG_MAY 1003
#define TAG_FLYGON_LATIOS 1004
#define TAG_FLYGON_LATIAS 1005
#define TAG_MOVING_SCENERY 2000

struct IntroCreditsSpriteMetadata
{
    u8 animNum:4;
    u8 shape:2;
    u8 size:2;
    u8 x;
    u8 y;
    u8 subpriority;
    u16 xOff;
};

#define INTRO_CREDITS_DATA __attribute__((section(".rodata.intro_credits_graphics_data")))

static const u16 sGrass_Pal[] INTRO_CREDITS_DATA             = INCGFX_U16("graphics/intro/scene_2/grass.png", ".gbapal");
static const u16 sGrassSunset_Pal[] INTRO_CREDITS_DATA       = INCGFX_U16("graphics/intro/scene_2/grass_sunset.pal", ".gbapal");
static const u16 sGrassNight_Pal[] INTRO_CREDITS_DATA        = INCGFX_U16("graphics/intro/scene_2/grass_night.pal", ".gbapal");
static const u32 sGrass_Gfx[] INTRO_CREDITS_DATA             = INCGFX_U32("graphics/intro/scene_2/grass.png", ".4bpp.lz");
static const u32 sGrass_Tilemap[] INTRO_CREDITS_DATA         = INCGFX_U32("graphics/intro/scene_2/grass_map.bin", ".lz");
static const u16 sCloudsBg_Pal[] INTRO_CREDITS_DATA          = INCGFX_U16("graphics/intro/scene_2/clouds_bg.pal", ".gbapal");
static const u16 sCloudsBgSunset_Pal[] INTRO_CREDITS_DATA    = INCGFX_U16("graphics/intro/scene_2/clouds_bg_sunset.pal", ".gbapal");
static const u32 sCloudsBg_Gfx[] INTRO_CREDITS_DATA          = INCGFX_U32("graphics/intro/scene_2/clouds_bg.png", ".4bpp.lz");
static const u32 sCloudsBg_Tilemap[] INTRO_CREDITS_DATA      = INCGFX_U32("graphics/intro/scene_2/clouds_bg_map.bin", ".lz");
static const u16 sClouds_Pal[] INTRO_CREDITS_DATA            = INCGFX_U16("graphics/intro/scene_2/clouds.png", ".gbapal");
static const u16 sCloudsSunset_Pal[] INTRO_CREDITS_DATA      = INCGFX_U16("graphics/intro/scene_2/clouds_sunset.pal", ".gbapal");
static const u32 sClouds_Gfx[] INTRO_CREDITS_DATA            = INCGFX_U32("graphics/intro/scene_2/clouds.png", ".4bpp.lz");
static const u16 sTrees_Pal[] INTRO_CREDITS_DATA             = INCGFX_U16("graphics/intro/scene_2/trees.png", ".gbapal");
static const u16 sTreesSunset_Pal[] INTRO_CREDITS_DATA       = INCGFX_U16("graphics/intro/scene_2/trees_sunset.pal", ".gbapal");
static const u32 sTrees_Gfx[] INTRO_CREDITS_DATA             = INCGFX_U32("graphics/intro/scene_2/trees.png", ".4bpp.lz");
static const u32 sTrees_Tilemap[] INTRO_CREDITS_DATA         = INCGFX_U32("graphics/intro/scene_2/trees_map.bin", ".lz");
static const u16 sTreesSmall_Pal[] INTRO_CREDITS_DATA        = INCGFX_U16("graphics/intro/scene_2/trees_small.png", ".gbapal");
static const u32 sTreesSmall_Gfx[] INTRO_CREDITS_DATA        = INCGFX_U32("graphics/intro/scene_2/trees_small.png", ".4bpp.lz");
static const u16 sHouses_Pal[] INTRO_CREDITS_DATA            = INCGFX_U16("graphics/intro/scene_2/houses.pal", ".gbapal");
static const u32 sHouses_Gfx[] INTRO_CREDITS_DATA            = INCGFX_U32("graphics/intro/scene_2/houses.png", ".4bpp.lz");
static const u16 sHouseSilhouette_Pal[] INTRO_CREDITS_DATA   = INCGFX_U16("graphics/intro/scene_2/house_silhouette.png", ".gbapal");
static const u32 sHouses_Tilemap[] INTRO_CREDITS_DATA        = INCGFX_U32("graphics/intro/scene_2/houses_map.bin", ".lz");
static const u32 sHouseSilhouette_Gfx[] INTRO_CREDITS_DATA   = INCGFX_U32("graphics/intro/scene_2/house_silhouette.png", ".4bpp.lz");
static const u16 sBrendanCredits_Pal[] INTRO_CREDITS_DATA    = INCGFX_U16("graphics/intro/scene_2/brendan_credits.png", ".gbapal");
static const u32 sBrendanCredits_Gfx[] INTRO_CREDITS_DATA    = INCGFX_U32("graphics/intro/scene_2/brendan_credits.png", ".4bpp.lz");
static const u16 sMayCredits_Pal[] INTRO_CREDITS_DATA        = INCGFX_U16("graphics/intro/scene_2/may_credits.png", ".gbapal");
static const u16 sUnused[0xF0] INTRO_CREDITS_DATA            = {0};
static const u32 sMayCredits_Gfx[] INTRO_CREDITS_DATA        = INCGFX_U32("graphics/intro/scene_2/may_credits.png", ".4bpp.lz");
static const u32 sBicycle_Gfx[] INTRO_CREDITS_DATA           = INCGFX_U32("graphics/intro/scene_2/bicycle.png", ".4bpp.lz");
static const u16 sLatios_Pal[] INTRO_CREDITS_DATA            = INCGFX_U16("graphics/intro/scene_2/latios.png", ".gbapal");
static const u32 sLatios_Gfx[] INTRO_CREDITS_DATA            = INCGFX_U32("graphics/intro/scene_2/latios.png", ".4bpp.lz");
static const u16 sLatias_Pal[] INTRO_CREDITS_DATA            = INCGFX_U16("graphics/intro/scene_2/latias.png", ".gbapal");
static const u32 sLatias_Gfx[] INTRO_CREDITS_DATA            = INCGFX_U32("graphics/intro/scene_2/latias.png", ".4bpp.lz");

static void SpriteCB_MovingScenery(struct Sprite *sprite);
static void SpriteCB_Player(struct Sprite *sprite);
static void SpriteCB_Bicycle(struct Sprite *sprite);
static void SpriteCB_FlygonLeftHalf(struct Sprite *sprite);

static const struct SpriteTemplate sSpriteTemplate_MovingScenery INTRO_CREDITS_DATA =
{
    .tileTag = TAG_MOVING_SCENERY,
    .paletteTag = TAG_NONE,
    .oam = &gDummyOamData,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_MovingScenery
};

static const struct CompressedSpriteSheet sSpriteSheet_Clouds[] INTRO_CREDITS_DATA =
{
    {
        .data = sClouds_Gfx,
        .size = 0x400,
        .tag = TAG_MOVING_SCENERY
    },
    {}
};

static const union AnimCmd sAnim_Cloud_Largest[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME( 0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cloud_Large[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cloud_Small[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME(20, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Cloud_Smallest[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME(22, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Clouds[] INTRO_CREDITS_DATA =
{
    sAnim_Cloud_Largest,
    sAnim_Cloud_Large,
    sAnim_Cloud_Small,
    sAnim_Cloud_Smallest
};

static const struct IntroCreditsSpriteMetadata sSpriteMetadata_Clouds[] INTRO_CREDITS_DATA =
{
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 72,
        .y = 32,
        .subpriority = 100,
        .xOff = 0xc00
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 158,
        .y = 32,
        .subpriority = 100,
        .xOff = 0xc00
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .x = 192,
        .y = 40,
        .subpriority = 101,
        .xOff = 0x800
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x16),
        .size = SPRITE_SIZE(16x16),
        .x = 56,
        .y = 40,
        .subpriority = 101,
        .xOff = 0x800
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .x = 100,
        .y = 44,
        .subpriority = 102,
        .xOff = 0x400
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .x = 152,
        .y = 44,
        .subpriority = 102,
        .xOff = 0x400
    },
    {
        .animNum = 3,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .x = 8,
        .y = 46,
        .subpriority = 103,
        .xOff = 0x100
    },
    {
        .animNum = 3,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .x = 56,
        .y = 46,
        .subpriority = 103,
        .xOff = 0x100
    },
    {
        .animNum = 3,
        .shape = SPRITE_SHAPE(16x8),
        .size = SPRITE_SIZE(16x8),
        .x = 240,
        .y = 46,
        .subpriority = 103,
        .xOff = 0x100
    },
};

static const struct CompressedSpriteSheet sSpriteSheet_TreesSmall[] INTRO_CREDITS_DATA =
{
    {
        .data = sTreesSmall_Gfx,
        .size = 0x400,
        .tag = TAG_MOVING_SCENERY
    },
    {}
};

static const union AnimCmd sAnim_Trees_0[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME( 0, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Trees_1[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME(16, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Trees_2[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME(24, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Trees[] INTRO_CREDITS_DATA =
{
    sAnim_Trees_0,
    sAnim_Trees_1,
    sAnim_Trees_2
};

static const struct IntroCreditsSpriteMetadata sSpriteMetadata_Trees[] INTRO_CREDITS_DATA =
{
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 16,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x2000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 80,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x2000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 144,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x2000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 208,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x2000,
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 40,
        .y = 88,
        .subpriority = 101,
        .xOff = 0x1000,
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 104,
        .y = 88,
        .subpriority = 101,
        .xOff = 0x1000,
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 168,
        .y = 88,
        .subpriority = 101,
        .xOff = 0x1000,
    },
    {
        .animNum = 1,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 232,
        .y = 88,
        .subpriority = 101,
        .xOff = 0x1000,
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 56,
        .y = 88,
        .subpriority = 102,
        .xOff = 0x800,
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 120,
        .y = 88,
        .subpriority = 102,
        .xOff = 0x800,
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 184,
        .y = 88,
        .subpriority = 102,
        .xOff = 0x800,
    },
    {
        .animNum = 2,
        .shape = SPRITE_SHAPE(16x32),
        .size = SPRITE_SIZE(16x32),
        .x = 248,
        .y = 88,
        .subpriority = 102,
        .xOff = 0x800,
    }
};

static const struct CompressedSpriteSheet sSpriteSheet_HouseSilhouette[] INTRO_CREDITS_DATA =
{
    {
        .data = sHouseSilhouette_Gfx,
        .size = 0x400,
        .tag = TAG_MOVING_SCENERY
    },
    {}
};

static const union AnimCmd sAnim_HouseSilhouette[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME(0, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_HouseSilhouette[] INTRO_CREDITS_DATA =
{
    sAnim_HouseSilhouette
};

static const struct IntroCreditsSpriteMetadata sSpriteMetadata_HouseSilhouette[] INTRO_CREDITS_DATA =
{
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 24,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 64,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 104,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 144,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 184,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    },
    {
        .animNum = 0,
        .shape = SPRITE_SHAPE(32x32),
        .size = SPRITE_SIZE(32x32),
        .x = 224,
        .y = 88,
        .subpriority = 100,
        .xOff = 0x1000,
    }
};

static const struct OamData sOamData_Player INTRO_CREDITS_DATA =
{
    .y = DISPLAY_HEIGHT,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1
};

static const union AnimCmd sAnim_Player[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME(  0, 8),
    ANIMCMD_FRAME( 64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_Player[] INTRO_CREDITS_DATA =
{
    sAnim_Player
};

static const struct SpriteTemplate sSpriteTemplate_Brendan INTRO_CREDITS_DATA =
{
    .tileTag = TAG_BRENDAN,
    .paletteTag = TAG_BRENDAN,
    .oam = &sOamData_Player,
    .anims = sAnims_Player,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Player
};

static const struct SpriteTemplate sSpriteTemplate_May INTRO_CREDITS_DATA =
{
    .tileTag = TAG_MAY,
    .paletteTag = TAG_MAY,
    .oam = &sOamData_Player,
    .anims = sAnims_Player,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Player
};

static const struct OamData sOamData_Bicycle INTRO_CREDITS_DATA =
{
    .y = DISPLAY_HEIGHT,
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1
};

static const union AnimCmd sAnim_Bicycle[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME(  0, 8),
    ANIMCMD_FRAME( 32, 8),
    ANIMCMD_FRAME( 64, 8),
    ANIMCMD_FRAME( 96, 8),
    ANIMCMD_JUMP(0)
};

static const union AnimCmd *const sAnims_Bicycle[] INTRO_CREDITS_DATA =
{
    sAnim_Bicycle
};

static const struct SpriteTemplate sSpriteTemplate_BrendanBicycle INTRO_CREDITS_DATA =
{
    .tileTag = TAG_BICYCLE,
    .paletteTag = TAG_BRENDAN,
    .oam = &sOamData_Bicycle,
    .anims = sAnims_Bicycle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Bicycle
};

static const struct SpriteTemplate sSpriteTemplate_MayBicycle INTRO_CREDITS_DATA =
{
    .tileTag = TAG_BICYCLE,
    .paletteTag = TAG_MAY,
    .oam = &sOamData_Bicycle,
    .anims = sAnims_Bicycle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Bicycle
};

static const struct OamData sOamData_Flygon INTRO_CREDITS_DATA =
{
    .y = DISPLAY_HEIGHT,
    .shape = SPRITE_SHAPE(64x64),
    .size = SPRITE_SIZE(64x64),
    .priority = 1
};

static const union AnimCmd sAnim_FlygonLeft[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME(0, 16),
    ANIMCMD_END
};

static const union AnimCmd sAnim_FlygonRight[] INTRO_CREDITS_DATA =
{
    ANIMCMD_FRAME(64, 16),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_Flygon[] INTRO_CREDITS_DATA =
{
    sAnim_FlygonLeft,
    sAnim_FlygonRight
};

static const struct SpriteTemplate sSpriteTemplate_FlygonLatios INTRO_CREDITS_DATA =
{
    .tileTag = TAG_FLYGON_LATIOS,
    .paletteTag = TAG_FLYGON_LATIOS,
    .oam = &sOamData_Flygon,
    .anims = sAnims_Flygon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FlygonLeftHalf
};

static const struct SpriteTemplate sSpriteTemplate_FlygonLatias INTRO_CREDITS_DATA =
{
    .tileTag = TAG_FLYGON_LATIAS,
    .paletteTag = TAG_FLYGON_LATIAS,
    .oam = &sOamData_Flygon,
    .anims = sAnims_Flygon,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_FlygonLeftHalf
};

const struct CompressedSpriteSheet gSpriteSheet_IntroBrendan[] INTRO_CREDITS_DATA =
{
    {
        .data = gIntroBrendan_Gfx,
        .size = 0x2000,
        .tag = TAG_BRENDAN
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_IntroMay[] INTRO_CREDITS_DATA =
{
    {
        .data = gIntroMay_Gfx,
        .size = 0x2000,
        .tag = TAG_MAY
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_IntroBicycle[] INTRO_CREDITS_DATA =
{
    {
        .data = sBicycle_Gfx,
        .size = 0x1000,
        .tag = TAG_BICYCLE
    },
    {}
};

// In RS these were Latios/Latias. In Emerald both are replaced with Flygon and now only 1 is used
static const struct CompressedSpriteSheet sSpriteSheet_IntroFlygon_Unused[] INTRO_CREDITS_DATA =
{
    {
        .data = gIntroFlygon_Gfx,
        .size = 0x1000,
        .tag = TAG_FLYGON_LATIOS
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_IntroFlygon[] INTRO_CREDITS_DATA =
{
    {
        .data = gIntroFlygon_Gfx,
        .size = 0x1000,
        .tag = TAG_FLYGON_LATIAS
    },
    {}
};

const struct SpritePalette gSpritePalettes_IntroPlayerFlygon[] INTRO_CREDITS_DATA =
{
    { .data = gIntroPlayer_Pal, .tag = TAG_BRENDAN },
    { .data = gIntroPlayer_Pal, .tag = TAG_MAY },
    { .data = gIntroFlygon_Pal, .tag = TAG_FLYGON_LATIOS },
    { .data = gIntroFlygon_Pal, .tag = TAG_FLYGON_LATIAS },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_CreditsBrendan[] INTRO_CREDITS_DATA =
{
    {
        .data = sBrendanCredits_Gfx,
        .size = 0x3800,
        .tag = TAG_BRENDAN
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_CreditsMay[] INTRO_CREDITS_DATA =
{
    {
        .data = sMayCredits_Gfx,
        .size = 0x3800,
        .tag = TAG_MAY
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_CreditsBicycle[] INTRO_CREDITS_DATA =
{
    {
        .data = sBicycle_Gfx,
        .size = 0x1000,
        .tag = TAG_BICYCLE
    },
    {}
};

// Unused
static const struct CompressedSpriteSheet sSpriteSheet_Latios[] INTRO_CREDITS_DATA =
{
    {
        .data = sLatios_Gfx,
        .size = 0x1000,
        .tag = TAG_FLYGON_LATIOS
    },
    {}
};

// Unused
static const struct CompressedSpriteSheet sSpriteSheet_Latias[] INTRO_CREDITS_DATA =
{
    {
        .data = sLatias_Gfx,
        .size = 0x1000,
        .tag = TAG_FLYGON_LATIAS
    },
    {}
};

const struct SpritePalette gSpritePalettes_Credits[] INTRO_CREDITS_DATA =
{
    { .data = sBrendanCredits_Pal, .tag = TAG_BRENDAN },
    { .data = sMayCredits_Pal,     .tag = TAG_MAY },
    { .data = sLatios_Pal,         .tag = TAG_FLYGON_LATIOS },
    { .data = sLatias_Pal,         .tag = TAG_FLYGON_LATIAS },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_CreditsRivalBrendan[] INTRO_CREDITS_DATA =
{
    {
        .data = sBrendanCredits_Gfx,
        .size = 0x2000,
        .tag = TAG_BRENDAN
    },
    {}
};

const struct CompressedSpriteSheet gSpriteSheet_CreditsRivalMay[] INTRO_CREDITS_DATA =
{
    {
        .data = sMayCredits_Gfx,
        .size = 0x2000,
        .tag = TAG_MAY
    },
    {}
};


#undef INTRO_CREDITS_DATA

static void CreateCloudSprites(void);
static void CreateTreeSprites(void);
static void CreateHouseSprites(void);
static void Task_BicycleBgAnimation(u8 taskId);
static void SpriteCB_FlygonRightHalf(struct Sprite *sprite);
static u8 UNUSED CreateIntroFlygonSprite_Unused(s16 x, s16 y);

void LoadIntroPart2Graphics(u8 scenery)
{
    LZ77UnCompVram(sGrass_Gfx, (void *)(BG_CHAR_ADDR(1)));
    LZ77UnCompVram(sGrass_Tilemap, (void *)(BG_SCREEN_ADDR(15)));
    LoadPalette(sGrass_Pal, BG_PLTT_ID(15), sizeof(sGrass_Pal));
    switch (scenery)
    {
    case 0:
    default:
        LZ77UnCompVram(sCloudsBg_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sCloudsBg_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(sCloudsBg_Pal, BG_PLTT_ID(0), sizeof(sCloudsBg_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_Clouds);
        LoadPalette(sClouds_Pal, OBJ_PLTT_ID(0), sizeof(sClouds_Pal));
        CreateCloudSprites();
        break;
    case 1:
        LZ77UnCompVram(sTrees_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sTrees_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(sTrees_Pal, BG_PLTT_ID(0), sizeof(sTrees_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_TreesSmall);
        LoadPalette(sTreesSmall_Pal, OBJ_PLTT_ID(0), sizeof(sTreesSmall_Pal));
        CreateTreeSprites();
        break;
    }
    gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_NORMAL;
    gReservedSpritePaletteCount = 8;
}

void SetIntroPart2BgCnt(u8 scenery)
{
    switch (scenery)
    {
    default:
    case 0:
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(6)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                   | BGCNT_CHARBASE(1)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(15)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG1_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);
        break;
    case 1:
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(6)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                   | BGCNT_CHARBASE(1)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(15)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG1_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(6)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(7)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                   | BGCNT_CHARBASE(1)
                                   | BGCNT_16COLOR
                                   | BGCNT_SCREENBASE(15)
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                    | DISPCNT_OBJ_1D_MAP
                                    | DISPCNT_BG1_ON
                                    | DISPCNT_BG2_ON
                                    | DISPCNT_BG3_ON
                                    | DISPCNT_OBJ_ON);
        break;
    }
}

void LoadCreditsSceneGraphics(u8 scene)
{
    LZ77UnCompVram(sGrass_Gfx, (void *)(BG_CHAR_ADDR(1)));
    LZ77UnCompVram(sGrass_Tilemap, (void *)(BG_SCREEN_ADDR(15)));
    switch (scene)
    {
    case SCENE_OCEAN_MORNING:
    default:
        LoadPalette(sGrass_Pal, BG_PLTT_ID(15), sizeof(sGrass_Pal));
        LZ77UnCompVram(sCloudsBg_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sCloudsBg_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(sCloudsBg_Pal, BG_PLTT_ID(0), sizeof(sCloudsBg_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_Clouds);
        LZ77UnCompVram(sClouds_Gfx, (void *)(OBJ_VRAM0));
        LoadPalette(sClouds_Pal, OBJ_PLTT_ID(0), sizeof(sClouds_Pal));
        CreateCloudSprites();
        break;
    case SCENE_OCEAN_SUNSET:
        LoadPalette(sGrassSunset_Pal, BG_PLTT_ID(15), sizeof(sGrassSunset_Pal));
        LZ77UnCompVram(sCloudsBg_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sCloudsBg_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(sCloudsBgSunset_Pal, BG_PLTT_ID(0), sizeof(sCloudsBgSunset_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_Clouds);
        LZ77UnCompVram(sClouds_Gfx, (void *)(OBJ_VRAM0));
        LoadPalette(sCloudsSunset_Pal, OBJ_PLTT_ID(0), sizeof(sCloudsSunset_Pal));
        CreateCloudSprites();
        break;
    case SCENE_FOREST_RIVAL_ARRIVE:
    case SCENE_FOREST_CATCH_RIVAL:
        LoadPalette(sGrassSunset_Pal, BG_PLTT_ID(15), sizeof(sGrassSunset_Pal));
        LZ77UnCompVram(sTrees_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sTrees_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(sTreesSunset_Pal, BG_PLTT_ID(0), sizeof(sTreesSunset_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_TreesSmall);
        LoadPalette(sTreesSunset_Pal, OBJ_PLTT_ID(0), sizeof(sTreesSunset_Pal));
        CreateTreeSprites();
        break;
    case SCENE_CITY_NIGHT:
        LoadPalette(sGrassNight_Pal, BG_PLTT_ID(15), sizeof(sGrassNight_Pal));
        LZ77UnCompVram(sHouses_Gfx, (void *)(VRAM));
        LZ77UnCompVram(sHouses_Tilemap, (void *)(BG_SCREEN_ADDR(6)));
        LoadPalette(sHouses_Pal, BG_PLTT_ID(0), sizeof(sHouses_Pal));
        LoadCompressedSpriteSheet(sSpriteSheet_HouseSilhouette);
        LoadPalette(sHouseSilhouette_Pal, OBJ_PLTT_ID(0), sizeof(sHouseSilhouette_Pal));
        CreateHouseSprites();
        break;
    }
    gReservedSpritePaletteCount = 8;
    gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_NORMAL;
}

void SetCreditsSceneBgCnt(u8 scene)
{
    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_16COLOR
                               | BGCNT_SCREENBASE(6)
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_16COLOR
                               | BGCNT_SCREENBASE(7)
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_16COLOR
                               | BGCNT_SCREENBASE(15)
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG_ALL_ON
                                | DISPCNT_OBJ_ON);
}

#define tMode data[0]
#define tBg1Speed data[1]
#define tBg1PosHi data[2]
#define tBg1PosLo data[3]
#define tBg2Speed data[4]
#define tBg2PosHi data[5]
#define tBg2PosLo data[6]
#define tBg3Speed data[7]
#define tBg3PosHi data[8]
#define tBg3PosLo data[9]

u8 CreateBicycleBgAnimationTask(u8 mode, u16 bg1Speed, u16 bg2Speed, u16 bg3Speed)
{
    u8 taskId = CreateTask(Task_BicycleBgAnimation, 0);

    gTasks[taskId].tMode = mode;
    gTasks[taskId].tBg1Speed = bg1Speed;
    gTasks[taskId].tBg1PosHi = 0;
    gTasks[taskId].tBg1PosLo = 0;
    gTasks[taskId].tBg2Speed = bg2Speed;
    gTasks[taskId].tBg2PosHi = 0;
    gTasks[taskId].tBg2PosLo = 0;
    gTasks[taskId].tBg3Speed = bg3Speed;
    gTasks[taskId].tBg3PosHi = 8;
    gTasks[taskId].tBg3PosLo = 0;
    Task_BicycleBgAnimation(taskId);
    return taskId;
}

static void Task_BicycleBgAnimation(u8 taskId)
{
    s16 bg1Speed;
    s16 bg2Speed;
    s16 bg3Speed;
    s32 offset;

    bg1Speed = gTasks[taskId].tBg1Speed;
    if (bg1Speed != 0)
    {
        offset = (gTasks[taskId].tBg1PosHi << 16) + (u16)gTasks[taskId].tBg1PosLo;
        offset -= (u16)bg1Speed << 4;
        gTasks[taskId].tBg1PosHi = offset >> 16;
        gTasks[taskId].tBg1PosLo = offset;
        SetGpuReg(REG_OFFSET_BG1HOFS, gTasks[taskId].tBg1PosHi);
        SetGpuReg(REG_OFFSET_BG1VOFS, gIntroCredits_MovingSceneryVBase + gIntroCredits_MovingSceneryVOffset);
    }

    bg2Speed = gTasks[taskId].tBg2Speed;
    if (bg2Speed != 0)
    {
        offset = (gTasks[taskId].tBg2PosHi << 16) + (u16)gTasks[taskId].tBg2PosLo;
        offset -= (u16)bg2Speed << 4;
        gTasks[taskId].tBg2PosHi = offset >> 16;
        gTasks[taskId].tBg2PosLo = offset;
        SetGpuReg(REG_OFFSET_BG2HOFS, gTasks[taskId].tBg2PosHi);
        if (gTasks[taskId].tMode != 0)
            SetGpuReg(REG_OFFSET_BG2VOFS, gIntroCredits_MovingSceneryVBase + gIntroCredits_MovingSceneryVOffset);
        else
            SetGpuReg(REG_OFFSET_BG2VOFS, gIntroCredits_MovingSceneryVBase);
    }

    bg3Speed = gTasks[taskId].tBg3Speed;
    if (bg3Speed != 0)
    {
        offset = (gTasks[taskId].tBg3PosHi << 16) + (u16)gTasks[taskId].tBg3PosLo;
        offset -= (u16)bg3Speed << 4;
        gTasks[taskId].tBg3PosHi = offset >> 16;
        gTasks[taskId].tBg3PosLo = offset;
        SetGpuReg(REG_OFFSET_BG3HOFS, gTasks[taskId].tBg3PosHi);
        SetGpuReg(REG_OFFSET_BG3VOFS, gIntroCredits_MovingSceneryVBase);
    }
}

void CycleSceneryPalette(u8 mode)
{
    u16 x;
    u16 y;

    switch (mode)
    {
    case 0:
    default:
        if (gMain.vblankCounter1 & 3 || gPaletteFade.active)
            break;
        if (gMain.vblankCounter1 & 4)
        {
            x = gPlttBufferUnfaded[BG_PLTT_ID(0) + 9];
            y = gPlttBufferUnfaded[BG_PLTT_ID(0) + 10];
        }
        else
        {
            x = gPlttBufferUnfaded[BG_PLTT_ID(0) + 10];
            y = gPlttBufferUnfaded[BG_PLTT_ID(0) + 9];
        }
        LoadPalette(&x, BG_PLTT_ID(0) + 9, sizeof(x));
        LoadPalette(&y, BG_PLTT_ID(0) + 10, sizeof(y));
        break;
    case 2:
        if (gMain.vblankCounter1 & 3 || gPaletteFade.active)
            break;
        if (gMain.vblankCounter1 & 4)
        {
            x = RGB(7, 9, 15);
            y = RGB(21, 20, 0);
        }
        else
        {
            x = RGB(28, 24, 0);
            y = RGB(7, 9, 15);
        }
        LoadPalette(&x, BG_PLTT_ID(0) + 12, sizeof(x));
        LoadPalette(&y, BG_PLTT_ID(0) + 13, sizeof(y));
        break;
    case 1:
        break;
    }
}

#define tHasVerticalMove data[0]
#define tXOffset data[1]
#define tXPos data[2]

static void SpriteCB_MovingScenery(struct Sprite *sprite)
{
    s32 x;
    s16 state = gIntroCredits_MovingSceneryState;

    if (state != INTROCRED_SCENERY_FROZEN)
    {
        switch (state)
        {
        default:
            DestroySprite(sprite);
            break;
        case INTROCRED_SCENERY_NORMAL:
            x = ((sprite->x << 16) | (u16)sprite->tXPos) + (u16)sprite->tXOffset;
            sprite->x = x >> 16;
            sprite->tXPos = x;
            if (sprite->x > 255)
                sprite->x = -32;
            if (sprite->tHasVerticalMove)
                sprite->y2 = -(gIntroCredits_MovingSceneryVBase + gIntroCredits_MovingSceneryVOffset);
            else
                sprite->y2 = -gIntroCredits_MovingSceneryVBase;
            break;
        }
    }
}

static void CreateMovingScenerySprites(bool8 hasVerticalMove, const struct IntroCreditsSpriteMetadata *metadata, const union AnimCmd *const *anims, u8 numSprites)
{
    u8 i;

    for (i = 0; i < numSprites; i++)
    {
        u8 sprite = CreateSprite(&sSpriteTemplate_MovingScenery, metadata[i].x, metadata[i].y, metadata[i].subpriority);
        CalcCenterToCornerVec(&gSprites[sprite], metadata[i].shape, metadata[i].size, ST_OAM_AFFINE_OFF);
        gSprites[sprite].oam.priority = 3;
        gSprites[sprite].oam.shape = metadata[i].shape;
        gSprites[sprite].oam.size = metadata[i].size;
        gSprites[sprite].oam.paletteNum = 0;
        gSprites[sprite].anims = anims;
        StartSpriteAnim(&gSprites[sprite], metadata[i].animNum);
        gSprites[sprite].tHasVerticalMove = hasVerticalMove;
        gSprites[sprite].tXOffset = metadata[i].xOff;
        gSprites[sprite].tXPos = 0;
    }
}

#undef tHasVerticalMove
#undef tXOffset
#undef tXPos

static void CreateCloudSprites(void)
{
    CreateMovingScenerySprites(FALSE, sSpriteMetadata_Clouds, sAnims_Clouds, 9);
}

static void CreateTreeSprites(void)
{
    CreateMovingScenerySprites(TRUE, sSpriteMetadata_Trees, sAnims_Trees, 12);
}

static void CreateHouseSprites(void)
{
    CreateMovingScenerySprites(TRUE, sSpriteMetadata_HouseSilhouette, sAnims_HouseSilhouette, 6);
}

static void SpriteCB_Player(struct Sprite *sprite)
{
}

#define sPlayerSpriteId data[0]

static void SpriteCB_Bicycle(struct Sprite *sprite)
{
    sprite->invisible = gSprites[sprite->sPlayerSpriteId].invisible;
    sprite->x = gSprites[sprite->sPlayerSpriteId].x;
    sprite->y = gSprites[sprite->sPlayerSpriteId].y + 8;
    sprite->x2 = gSprites[sprite->sPlayerSpriteId].x2;
    sprite->y2 = gSprites[sprite->sPlayerSpriteId].y2;
}

u8 CreateIntroBrendanSprite(s16 x, s16 y)
{
    u8 playerSpriteId = CreateSprite(&sSpriteTemplate_Brendan, x, y, 2);
    u8 bicycleSpriteId = CreateSprite(&sSpriteTemplate_BrendanBicycle, x, y + 8, 3);
    gSprites[bicycleSpriteId].sPlayerSpriteId = playerSpriteId;
    return playerSpriteId;
}

u8 CreateIntroMaySprite(s16 x, s16 y)
{
    u8 playerSpriteId = CreateSprite(&sSpriteTemplate_May, x, y, 2);
    u8 bicycleSpriteId = CreateSprite(&sSpriteTemplate_MayBicycle, x, y + 8, 3);
    gSprites[bicycleSpriteId].sPlayerSpriteId = playerSpriteId;
    return playerSpriteId;
}

#undef sPlayerSpriteId

static void SpriteCB_FlygonLeftHalf(struct Sprite *sprite)
{
}

#define sLeftSpriteId data[0]

static void SpriteCB_FlygonRightHalf(struct Sprite *sprite)
{
    sprite->invisible = gSprites[sprite->sLeftSpriteId].invisible;
    sprite->y = gSprites[sprite->sLeftSpriteId].y;
    sprite->x2 = gSprites[sprite->sLeftSpriteId].x2;
    sprite->y2 = gSprites[sprite->sLeftSpriteId].y2;
}

static u8 UNUSED CreateIntroFlygonSprite_Unused(s16 x, s16 y)
{
    u8 leftSpriteId = CreateSprite(&sSpriteTemplate_FlygonLatios, x - 32, y, 5);
    u8 rightSpriteId = CreateSprite(&sSpriteTemplate_FlygonLatios, x + 32, y, 6);
    gSprites[rightSpriteId].sLeftSpriteId = leftSpriteId;
    StartSpriteAnim(&gSprites[rightSpriteId], 1);
    gSprites[rightSpriteId].callback = SpriteCB_FlygonRightHalf;
    return leftSpriteId;
}

u8 CreateIntroFlygonSprite(s16 x, s16 y)
{
    u8 leftSpriteId = CreateSprite(&sSpriteTemplate_FlygonLatias, x - 32, y, 5);
    u8 rightSpriteId = CreateSprite(&sSpriteTemplate_FlygonLatias, x + 32, y, 6);
    gSprites[rightSpriteId].sLeftSpriteId = leftSpriteId;
    StartSpriteAnim(&gSprites[rightSpriteId], 1);
    gSprites[rightSpriteId].callback = SpriteCB_FlygonRightHalf;
    return leftSpriteId;
}

#undef sLeftSpriteId
#undef tMode
#undef tBg1Speed
#undef tBg1PosHi
#undef tBg1PosLo
#undef tBg2Speed
#undef tBg2PosHi
#undef tBg2PosLo
#undef tBg3Speed
#undef tBg3PosHi
#undef tBg3PosLo
