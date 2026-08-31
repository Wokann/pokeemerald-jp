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

extern const u16 sGrass_Pal[16];
extern const u16 sGrassSunset_Pal[16];
extern const u16 sGrassNight_Pal[16];
extern const u32 sGrass_Gfx[];
extern const u32 sGrass_Tilemap[];
extern const u16 sCloudsBg_Pal[48];
extern const u16 sCloudsBgSunset_Pal[48];
extern const u32 sCloudsBg_Gfx[];
extern const u32 sCloudsBg_Tilemap[];
extern const u16 sClouds_Pal[16];
extern const u16 sCloudsSunset_Pal[16];
extern const u32 sClouds_Gfx[];
extern const u16 sTrees_Pal[16];
extern const u16 sTreesSunset_Pal[16];
extern const u32 sTrees_Gfx[];
extern const u32 sTrees_Tilemap[];
extern const u16 sTreesSmall_Pal[16];
extern const u32 sTreesSmall_Gfx[];
extern const u16 sHouses_Pal[32];
extern const u32 sHouses_Gfx[];
extern const u16 sHouseSilhouette_Pal[16];
extern const u32 sHouses_Tilemap[];
extern const struct SpriteTemplate sSpriteTemplate_MovingScenery;
extern const struct CompressedSpriteSheet sSpriteSheet_Clouds[];
extern const union AnimCmd *const sAnims_Clouds[];
extern const struct IntroCreditsSpriteMetadata sSpriteMetadata_Clouds[];
extern const struct CompressedSpriteSheet sSpriteSheet_TreesSmall[];
extern const union AnimCmd *const sAnims_Trees[];
extern const struct IntroCreditsSpriteMetadata sSpriteMetadata_Trees[];
extern const struct CompressedSpriteSheet sSpriteSheet_HouseSilhouette[];
extern const union AnimCmd *const sAnims_HouseSilhouette[];
extern const struct IntroCreditsSpriteMetadata sSpriteMetadata_HouseSilhouette[];
extern const struct SpriteTemplate sSpriteTemplate_Brendan;
extern const struct SpriteTemplate sSpriteTemplate_May;
extern const struct SpriteTemplate sSpriteTemplate_BrendanBicycle;
extern const struct SpriteTemplate sSpriteTemplate_MayBicycle;
extern const struct SpriteTemplate sSpriteTemplate_FlygonLatios;
extern const struct SpriteTemplate sSpriteTemplate_FlygonLatias;

static void CreateCloudSprites(void);
static void CreateTreeSprites(void);
static void CreateHouseSprites(void);
static void Task_BicycleBgAnimation(u8 taskId);
static void SpriteCB_MovingScenery(struct Sprite *sprite);
static void SpriteCB_Player(struct Sprite *sprite);
static void SpriteCB_Bicycle(struct Sprite *sprite);
static void SpriteCB_FlygonLeftHalf(struct Sprite *sprite);
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
