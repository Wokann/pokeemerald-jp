#include "global.h"
#include "evolution_graphics.h"
#include "sprite.h"
#include "trig.h"
#include "random.h"
#include "decompress.h"
#include "task.h"
#include "sound.h"
#include "constants/songs.h"
#include "palette.h"
#include "constants/rgb.h"

extern u16 gUnknown_20373F4[];
extern u16 gUnknown_20377F4[];
extern u16 gUnknown_20379B4[];

void EvoTask_BeginPreSet1_FadeAndPlaySE(u8 taskId);
void EvoTask_CreatePreEvoSparkleSet1(u8 taskId);
void EvoTask_WaitForPre1SparklesToGoUp(u8 taskId);
void EvoTask_BeginPreSparklesSet2(u8 taskId);
void EvoTask_CreatePreEvoSparklesSet2(u8 taskId);
void EvoTask_DestroyPreSet2Task(u8 taskId);
void EvoTask_BeginPostSparklesSet1(u8 taskId);
void EvoTask_CreatePostEvoSparklesSet1(u8 taskId);
void EvoTask_DestroyPostSet1Task(u8 taskId);
void EvoTask_BeginPostSparklesSet2_AndFlash(u8 taskId);
void EvoTask_CreatePostEvoSparklesSet2_AndFlash(u8 taskId);
void EvoTask_DestroyPostSet2AndFlashTask(u8 taskId);
void EvoTask_BeginPostSparklesSet2_AndFlash_Trade(u8 taskId);
void EvoTask_CreatePostEvoSparklesSet2_AndFlash_Trade(u8 taskId);

void sub_0817C3AC(u8 taskId);
void sub_0817C3D0(u8 taskId);
void sub_0817C420(u8 taskId);
void PreEvoInvisible_PostEvoVisible_KillTask(u8 taskId);
void PreEvoVisible_PostEvoInvisible_KillTask(u8 taskId);

#define TAG_SPARKLE 1001
#define EVO_SPARKLE_DATA __attribute__((section(".rodata.mid98_suffix_before_species_to_back_anim_set"), aligned(1)))

static void SpriteCB_Sparkle_Dummy(struct Sprite *sprite)
{
}

static const u16 sEvoSparkle_Pal[] EVO_SPARKLE_DATA = INCGFX_U16("graphics/misc/evo_sparkle.png", ".gbapal");
static const u32 sEvoSparkle_Gfx[] EVO_SPARKLE_DATA = INCGFX_U32("graphics/misc/evo_sparkle.png", ".4bpp.lz");

static const struct CompressedSpriteSheet sEvoSparkleSpriteSheets[] EVO_SPARKLE_DATA =
{
    {sEvoSparkle_Gfx, 0x20, TAG_SPARKLE},
    {NULL, 0, 0},
};

static const struct SpritePalette sEvoSparkleSpritePals[] EVO_SPARKLE_DATA =
{
    {sEvoSparkle_Pal, TAG_SPARKLE},
    {NULL, 0},
};

static const struct OamData sOamData_EvoSparkle EVO_SPARKLE_DATA =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(8x8),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(8x8),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sSpriteAnim_EvoSparkle[] EVO_SPARKLE_DATA =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_END,
};

static const union AnimCmd *const sSpriteAnimTable_EvoSparkle[] EVO_SPARKLE_DATA =
{
    sSpriteAnim_EvoSparkle,
};

static const struct SpriteTemplate sEvoSparkleSpriteTemplate EVO_SPARKLE_DATA =
{
    .tileTag = TAG_SPARKLE,
    .paletteTag = TAG_SPARKLE,
    .oam = &sOamData_EvoSparkle,
    .anims = sSpriteAnimTable_EvoSparkle,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Sparkle_Dummy,
};

static const u16 sEvoSparkleMatrices[] EVO_SPARKLE_DATA =
{
    0x3C0, 0x380, 0x340, 0x300, 0x2C0, 0x280,
    0x240, 0x200, 0x1C0, 0x180, 0x140, 0x100,
};

static const s16 sUnused[] EVO_SPARKLE_DATA =
{
    -4, 0x10,
    -3, 0x30,
    -2, 0x50,
    -1, 0x70,
     1, 0x70,
     2, 0x50,
     3, 0x30,
     4, 0x10,
};

void SetEvoSparklesMatrices(void)
{
    u16 i;

    for (i = 0; i < ARRAY_COUNT(sEvoSparkleMatrices); i++)
        SetOamMatrix(20 + i, sEvoSparkleMatrices[i], 0, 0, sEvoSparkleMatrices[i]);
}

void SpriteCB_PreEvoSparkleSet1(struct Sprite* sprite)
{
    if (sprite->y > 8)
    {
        u8 matrixNum;

        sprite->y = 88 - (sprite->data[7] * sprite->data[7]) / 80;
        sprite->y2 = Sin((u8)(sprite->data[6]), sprite->data[5]) / 4;
        sprite->x2 = Cos((u8)(sprite->data[6]), sprite->data[5]);
        sprite->data[6] += 4;
        if (sprite->data[7] & 1)
            sprite->data[5]--;
        sprite->data[7]++;
        if (sprite->y2 > 0)
            sprite->subpriority = 1;
        else
            sprite->subpriority = 20;
        matrixNum = sprite->data[5] / 4 + 20;
        if (matrixNum > 31)
            matrixNum = 31;
        sprite->oam.matrixNum = matrixNum;
    }
    else
        DestroySprite(sprite);
}

void CreatePreEvoSparkleSet1(u8 arg0)
{
    u8 spriteID = CreateSprite(&sEvoSparkleSpriteTemplate, 120, 88, 0);
    if (spriteID != MAX_SPRITES)
    {
        gSprites[spriteID].data[5] = 48;
        gSprites[spriteID].data[6] = arg0;
        gSprites[spriteID].data[7] = 0;
        gSprites[spriteID].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteID].oam.matrixNum = 31;
        gSprites[spriteID].callback = SpriteCB_PreEvoSparkleSet1;
    }
}

void SpriteCB_PreEvoSparkleSet2(struct Sprite* sprite)
{
    if (sprite->y < 88)
    {
        sprite->y = 8 + (sprite->data[7] * sprite->data[7]) / 5;
        sprite->y2 = Sin((u8)(sprite->data[6]), sprite->data[5]) / 4;
        sprite->x2 = Cos((u8)(sprite->data[6]), sprite->data[5]);
        sprite->data[5] = 8 + Sin((u8)(sprite->data[7] * 4), 40);
        sprite->data[7]++;
    }
    else
        DestroySprite(sprite);
}

void CreatePreEvoSparkleSet2(u8 arg0)
{
    u8 spriteID = CreateSprite(&sEvoSparkleSpriteTemplate, 120, 8, 0);
    if (spriteID != MAX_SPRITES)
    {
        gSprites[spriteID].data[5] = 8;
        gSprites[spriteID].data[6] = arg0;
        gSprites[spriteID].data[7] = 0;
        gSprites[spriteID].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteID].oam.matrixNum = 25;
        gSprites[spriteID].subpriority = 1;
        gSprites[spriteID].callback = SpriteCB_PreEvoSparkleSet2;
    }
}

void SpriteCB_PostEvoSparkleSet1(struct Sprite* sprite)
{
    if (sprite->data[5] > 8)
    {
        sprite->y2 = Sin((u8)(sprite->data[6]), sprite->data[5]);
        sprite->x2 = Cos((u8)(sprite->data[6]), sprite->data[5]);
        sprite->data[5] -= sprite->data[3];
        sprite->data[6] += 4;
    }
    else
        DestroySprite(sprite);
}

void CreatePostEvoSparkleSet1(u8 arg0, u8 arg1)
{
    u8 spriteID = CreateSprite(&sEvoSparkleSpriteTemplate, 120, 56, 0);
    if (spriteID != MAX_SPRITES)
    {
        gSprites[spriteID].data[3] = arg1;
        gSprites[spriteID].data[5] = 120;
        gSprites[spriteID].data[6] = arg0;
        gSprites[spriteID].data[7] = 0;
        gSprites[spriteID].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteID].oam.matrixNum = 31;
        gSprites[spriteID].subpriority = 1;
        gSprites[spriteID].callback = SpriteCB_PostEvoSparkleSet1;
    }
}

void SpriteCB_PostEvoSparkleSet2(struct Sprite* sprite)
{
    if (!(sprite->data[7] & 3))
        sprite->y++;
    if (sprite->data[6] < 128)
    {
        u8 matrixNum;

        sprite->y2 = -Sin((u8)(sprite->data[6]), sprite->data[5]);
        sprite->x = 120 + (sprite->data[3] * sprite->data[7]) / 3;
        sprite->data[6]++;
        matrixNum = 31 - (sprite->data[6] * 12 / 128);
        if (sprite->data[6] > 64)
            sprite->subpriority = 1;
        else
        {
            sprite->invisible = FALSE;
            sprite->subpriority = 20;
            if (sprite->data[6] > 112 && sprite->data[6] & 1)
                sprite->invisible = TRUE;
        }
        if (matrixNum < 20)
            matrixNum = 20;
        sprite->oam.matrixNum = matrixNum;
        sprite->data[7]++;
    }
    else
        DestroySprite(sprite);
}

void CreatePostEvoSparkleSet2(u8 id)
{
    u8 spriteID = CreateSprite(&sEvoSparkleSpriteTemplate, 120, 56, 0);
    if (spriteID != MAX_SPRITES)
    {
        gSprites[spriteID].data[3] = 3 - (Random() % 7);
        gSprites[spriteID].data[5] = 48 + (Random() & 0x3F);
        gSprites[spriteID].data[7] = 0;
        gSprites[spriteID].oam.affineMode = ST_OAM_AFFINE_NORMAL;
        gSprites[spriteID].oam.matrixNum = 31;
        gSprites[spriteID].subpriority = 20;
        gSprites[spriteID].callback = SpriteCB_PostEvoSparkleSet2;
    }
}

void LoadEvoSparkleSpriteAndPal(void)
{
    LoadCompressedSpriteSheetUsingHeap(&sEvoSparkleSpriteSheets[0]);
    LoadSpritePalettes(sEvoSparkleSpritePals);
}

u8 LaunchTask_PreEvoSparklesSet1(u16 palNum)
{
    u8 taskId = CreateTask(EvoTask_BeginPreSet1_FadeAndPlaySE, 0);
    gTasks[taskId].data[1] = palNum;
    return taskId;
}

void EvoTask_BeginPreSet1_FadeAndPlaySE(u8 taskId)
{
    SetEvoSparklesMatrices();
    gTasks[taskId].data[15] = 0;
    BeginNormalPaletteFade(3 << gTasks[taskId].data[1], 0xA, 0, 0x10, RGB_WHITE);
    gTasks[taskId].func = EvoTask_CreatePreEvoSparkleSet1;
    PlaySE(SE_M_MEGA_KICK); // 'Charging up' sound for the sparkles as they spiral upwards
}

void EvoTask_CreatePreEvoSparkleSet1(u8 taskId)
{
    if (gTasks[taskId].data[15] < 64)
    {
        if (!(gTasks[taskId].data[15] & 7))
        {
            u8 i;
            for (i = 0; i < 4; i++)
                CreatePreEvoSparkleSet1((0x78 & gTasks[taskId].data[15]) * 2 + i * 64);
        }
        gTasks[taskId].data[15]++;
    }
    else
    {
        gTasks[taskId].data[15] = 96;
        gTasks[taskId].func = EvoTask_WaitForPre1SparklesToGoUp;
    }
}

void EvoTask_WaitForPre1SparklesToGoUp(u8 taskId)
{
    if (gTasks[taskId].data[15] != 0)
        gTasks[taskId].data[15]--;
    else
        DestroyTask(taskId);
}

u8 LaunchTask_PostEvoSparklesSet1(void)
{
    return CreateTask(EvoTask_BeginPreSparklesSet2, 0);
}

void EvoTask_BeginPreSparklesSet2(u8 taskId)
{
    SetEvoSparklesMatrices();
    gTasks[taskId].data[15] = 0;
    gTasks[taskId].func = EvoTask_CreatePreEvoSparklesSet2;
    PlaySE(SE_M_BUBBLE_BEAM2);
}

void EvoTask_CreatePreEvoSparklesSet2(u8 taskId)
{
    if (gTasks[taskId].data[15] < 96)
    {
        if (gTasks[taskId].data[15] < 6)
        {
            u8 i;
            for (i = 0; i < 9; i++)
                CreatePreEvoSparkleSet2(i * 16);
        }
        gTasks[taskId].data[15]++;
    }
    else
        gTasks[taskId].func = EvoTask_DestroyPreSet2Task;
}

void EvoTask_DestroyPreSet2Task(u8 taskId)
{
    DestroyTask(taskId);
}

u8 LaunchTask_PreEvoSparklesSet2(void)
{
    return CreateTask(EvoTask_BeginPostSparklesSet1, 0);
}

void EvoTask_BeginPostSparklesSet1(u8 taskId)
{
    SetEvoSparklesMatrices();
    gTasks[taskId].data[15] = 0;
    gTasks[taskId].func = EvoTask_CreatePostEvoSparklesSet1;
    PlaySE(SE_SHINY);
}

void EvoTask_CreatePostEvoSparklesSet1(u8 taskId)
{
    if (gTasks[taskId].data[15] < 48)
    {
        if (gTasks[taskId].data[15] == 0)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                CreatePostEvoSparkleSet1(i * 16, 4);
        }
        if (gTasks[taskId].data[15] == 32)
        {
            u8 i;
            for (i = 0; i < 16; i++)
                CreatePostEvoSparkleSet1(i * 16, 8);
        }
        gTasks[taskId].data[15]++;
    }
    else
        gTasks[taskId].func = EvoTask_DestroyPostSet1Task;
}

void EvoTask_DestroyPostSet1Task(u8 taskId)
{
    DestroyTask(taskId);
}

u8 LaunchTask_PostEvoSparklesSet2AndFlash(u16 species)
{
    u8 taskId = CreateTask(EvoTask_BeginPostSparklesSet2_AndFlash, 0);
    gTasks[taskId].data[2] = species;
    return taskId;
}

void EvoTask_BeginPostSparklesSet2_AndFlash(u8 taskId)
{
    SetEvoSparklesMatrices();
    gTasks[taskId].data[15] = 0;
    CpuSet(gUnknown_20377F4, gUnknown_20373F4, 0x30);
    BeginNormalPaletteFade(0xFFF9041C, 0, 0, 0x10, RGB_WHITE); // was 0xFFF9001C in R/S
    gTasks[taskId].func = EvoTask_CreatePostEvoSparklesSet2_AndFlash;
    PlaySE(SE_M_PETAL_DANCE);
}

void EvoTask_CreatePostEvoSparklesSet2_AndFlash(u8 taskId)
{
    if (gTasks[taskId].data[15] < 128)
    {
        u8 i;
        switch (gTasks[taskId].data[15])
        {
        default:
            if (gTasks[taskId].data[15] < 50)
                CreatePostEvoSparkleSet2(Random() & 7);
            break;
        case 0:
            for (i = 0; i < 8; i++)
                CreatePostEvoSparkleSet2(i);
            break;
        case 32:
            BeginNormalPaletteFade(0xFFFF041C, 0x10, 0x10, 0, RGB_WHITE); // was 0xFFF9001C in R/S
            break;
        }
        gTasks[taskId].data[15]++;
    }
    else
        gTasks[taskId].func = EvoTask_DestroyPostSet2AndFlashTask;
}

void EvoTask_DestroyPostSet2AndFlashTask(u8 taskId)
{
    if (!gPaletteFade.active)
        DestroyTask(taskId);
}

u8 LaunchTask_PostEvoSparklesSet2AndFlash_Trade(u16 species)
{
    u8 taskId = CreateTask(EvoTask_BeginPostSparklesSet2_AndFlash_Trade, 0);
    gTasks[taskId].data[2] = species;
    return taskId;
}

void EvoTask_BeginPostSparklesSet2_AndFlash_Trade(u8 taskId)
{
    SetEvoSparklesMatrices();
    gTasks[taskId].data[15] = 0;
    CpuSet(gUnknown_20377F4, gUnknown_20373F4, 0x30);
    BeginNormalPaletteFade(0xFFF90400, 0, 0, 0x10, RGB_WHITE); // was 0xFFFF0001 in R/S
    gTasks[taskId].func = EvoTask_CreatePostEvoSparklesSet2_AndFlash_Trade;
    PlaySE(SE_M_PETAL_DANCE);
}

void EvoTask_CreatePostEvoSparklesSet2_AndFlash_Trade(u8 taskId)
{
    if (gTasks[taskId].data[15] < 128)
    {
        u8 i;
        switch (gTasks[taskId].data[15])
        {
        default:
            if (gTasks[taskId].data[15] < 50)
                CreatePostEvoSparkleSet2(Random() & 7);
            break;
        case 0:
            for (i = 0; i < 8; i++)
                CreatePostEvoSparkleSet2(i);
            break;
        case 32:
            BeginNormalPaletteFade(0xFFFF0400, 0x10, 0x10, 0, RGB_WHITE); // was 0xFFFF0001 in R/S
            break;
        }
        gTasks[taskId].data[15]++;
    }
    else
        gTasks[taskId].func = EvoTask_DestroyPostSet2AndFlashTask;
}

void EvoSparkle_DummySpriteCb(struct Sprite *sprite) {}
u8 sub_0817C260(u8 preEvoSpriteId, u8 postEvoSpriteId)
{
    u16 i;
    u16 monPalette[16];
    u8 taskId;
    s32 toDiv;

    for (i = 0; i < ARRAY_COUNT(monPalette); i++)
        monPalette[i] = RGB_WHITE;

    taskId = CreateTask(sub_0817C3AC, 0);
    gTasks[taskId].data[1] = preEvoSpriteId;
    gTasks[taskId].data[2] = postEvoSpriteId;
    gTasks[taskId].data[3] = 256;
    gTasks[taskId].data[4] = 16;

    toDiv = 65536;
    SetOamMatrix(30, 256, 0, 0, 256);
    SetOamMatrix(31, toDiv / gTasks[taskId].data[4], 0, 0, toDiv / gTasks[taskId].data[4]);

    gSprites[preEvoSpriteId].callback = EvoSparkle_DummySpriteCb;
    gSprites[preEvoSpriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[preEvoSpriteId].oam.matrixNum = 30;
    gSprites[preEvoSpriteId].invisible = FALSE;
    CpuSet(monPalette, &gUnknown_20379B4[gSprites[preEvoSpriteId].oam.paletteNum * 16], 16);

    gSprites[postEvoSpriteId].callback = EvoSparkle_DummySpriteCb;
    gSprites[postEvoSpriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
    gSprites[postEvoSpriteId].oam.matrixNum = 31;
    gSprites[postEvoSpriteId].invisible = FALSE;
    CpuSet(monPalette, &gUnknown_20379B4[gSprites[postEvoSpriteId].oam.paletteNum * 16], 16);

    gTasks[taskId].data[8] = FALSE;
    return taskId;
}

void sub_0817C3AC(u8 taskId)
{
    gTasks[taskId].data[5] = FALSE;
    gTasks[taskId].data[6] = 8;
    gTasks[taskId].func = sub_0817C3D0;
}

void sub_0817C3D0(u8 taskId)
{
    if (gTasks[taskId].data[8])
        PreEvoVisible_PostEvoInvisible_KillTask(taskId);
    else if (gTasks[taskId].data[6] == 128)
        PreEvoInvisible_PostEvoVisible_KillTask(taskId);
    else
    {
        gTasks[taskId].data[6] += 2;
        gTasks[taskId].data[5] ^= 1;
        gTasks[taskId].func = sub_0817C420;
    }
}

void sub_0817C420(u8 taskId)
{
    if (gTasks[taskId].data[8])
        gTasks[taskId].func = PreEvoVisible_PostEvoInvisible_KillTask;
    else
    {
        u16 oamMatrixArg;
        u8 numSpritesFinished = 0;
        if (!gTasks[taskId].data[5])
        {
            // Set pre-evo sprite growth
            if (gTasks[taskId].data[3] < 256 - gTasks[taskId].data[6])
                gTasks[taskId].data[3] += gTasks[taskId].data[6];
            else
            {
                gTasks[taskId].data[3] = 256;
                numSpritesFinished++;
            }

            // Set post-evo sprite shrink
            if (gTasks[taskId].data[4] > 16 + gTasks[taskId].data[6])
                gTasks[taskId].data[4]  -= gTasks[taskId].data[6];
            else
            {
                gTasks[taskId].data[4] = 16;
                numSpritesFinished++;
            }
        }
        else
        {
            // Set post-evo sprite growth
            if (gTasks[taskId].data[4] < 256 - gTasks[taskId].data[6])
                gTasks[taskId].data[4] += gTasks[taskId].data[6];
            else
            {
                gTasks[taskId].data[4] = 256;
                numSpritesFinished++;
            }

            // Set pre-evo sprite shrink
            if (gTasks[taskId].data[3] > 16 + gTasks[taskId].data[6])
                gTasks[taskId].data[3]  -= gTasks[taskId].data[6];
            else
            {
                gTasks[taskId].data[3] = 16;
                numSpritesFinished++;
            }
        }

        // Grow/shrink pre-evo sprite
        oamMatrixArg = 65536 / gTasks[taskId].data[3];
        SetOamMatrix(30, oamMatrixArg, 0, 0, oamMatrixArg);

        // Grow/shrink post-evo sprite
        oamMatrixArg = 65536 / gTasks[taskId].data[4];
        SetOamMatrix(31, oamMatrixArg, 0, 0, oamMatrixArg);

        // Both sprites have reached their size extreme
        if (numSpritesFinished == 2)
            gTasks[taskId].func = sub_0817C3D0;
    }
}

void PreEvoInvisible_PostEvoVisible_KillTask(u8 taskId)
{
    gSprites[gTasks[taskId].data[1]].oam.affineMode = ST_OAM_AFFINE_OFF;
    gSprites[gTasks[taskId].data[1]].oam.matrixNum = 0;
    gSprites[gTasks[taskId].data[1]].invisible = TRUE;

    gSprites[gTasks[taskId].data[2]].oam.affineMode = ST_OAM_AFFINE_OFF;
    gSprites[gTasks[taskId].data[2]].oam.matrixNum = 0;
    gSprites[gTasks[taskId].data[2]].invisible = FALSE;

    DestroyTask(taskId);
}

void PreEvoVisible_PostEvoInvisible_KillTask(u8 taskId)
{
    gSprites[gTasks[taskId].data[1]].oam.affineMode = ST_OAM_AFFINE_OFF;
    gSprites[gTasks[taskId].data[1]].oam.matrixNum = 0;
    gSprites[gTasks[taskId].data[1]].invisible = FALSE;

    gSprites[gTasks[taskId].data[2]].oam.affineMode = ST_OAM_AFFINE_OFF;
    gSprites[gTasks[taskId].data[2]].oam.matrixNum = 0;
    gSprites[gTasks[taskId].data[2]].invisible = TRUE;

    DestroyTask(taskId);
}
