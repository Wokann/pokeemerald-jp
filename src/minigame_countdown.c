#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "data.h"
#include "digit_obj_util.h"
#include "item.h"
#include "link.h"
#include "link_rfu.h"
#include "main.h"
#include "menu.h"
#include "minigame_countdown.h"
#include "event_data.h"
#include "palette.h"
#include "pokemon.h"
#include "pokemon_jump.h"
#include "random.h"
#include "save.h"
#include "sound.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trig.h"
// ---- Static '3-2-1 Start' countdown (unused by the game) ----
#define TAG_STATIC_COUNTDOWN 0x2000

enum {
    STATE_IDLE = 1,
    STATE_START,
    STATE_RUN,
    STATE_END,
};

enum {
    FUNC_INIT,
    FUNC_FREE,
    FUNC_START,
    FUNC_RUN,
};

enum {
    ANIM_THREE,
    ANIM_TWO,
    ANIM_ONE,
    ANIM_START_LEFT,
    ANIM_START_MID,
    ANIM_START_RIGHT,
};

void Task_StaticCountdown(u8 taskId);
void Task_StaticCountdown_Init(u8 taskId);
void Task_StaticCountdown_Free(u8 taskId);
void Task_StaticCountdown_Start(u8 taskId);
void Task_StaticCountdown_Run(u8 taskId);
void StaticCountdown_CreateSprites(u8 taskId, s16 *data);
void SpriteCB_StaticCountdown(struct Sprite *sprite);

static const struct CompressedSpriteSheet sSpriteSheet_321Start_Static[];
static const struct SpritePalette sSpritePalette_321Start_Static[];
static const struct SpriteTemplate sSpriteTemplate_StaticCountdown[];
static const TaskFunc sStaticCountdownFuncs[][4];

#define tState            data[0]
#define tFuncSetId        data[1]
#define tSpriteTemplateId data[2]
#define tSpriteSheetId    data[3]
#define tSpritePalId      data[4]
#define tInterval         data[5]
#define tPriority         data[6]
#define tSubpriority      data[7]
#define tNumSprites       data[8]
#define tX                data[9]
#define tY                data[10]
#define tPrevTime         data[10]
#define tTimer            data[11]
#define tLinkTimer        data[12]
#define tSpriteIds(i)     data[13 + i]

#define sInterval       data[1]
#define sAnimNum        data[2]
#define sTaskId         data[3]
#define sId             data[4]
#define sNumberSpriteId data[5]

u32 CreateStaticCountdownTask(u8 funcSetId, u8 taskPriority)
{
    u8 taskId = CreateTask(Task_StaticCountdown, taskPriority);
    struct Task *task = &gTasks[taskId];

    task->tState = STATE_IDLE;
    task->tFuncSetId = funcSetId;
    sStaticCountdownFuncs[funcSetId][FUNC_INIT](taskId);
    return taskId;
}

bool32 StartStaticCountdown(void)
{
    u8 taskId = FindTaskIdByFunc(Task_StaticCountdown);
    if (taskId == TASK_NONE)
        return FALSE;

    gTasks[taskId].tState = STATE_START;
    return TRUE;
}

bool32 IsStaticCountdownRunning(void)
{
    return FuncIsActiveTask(Task_StaticCountdown);
}

void Task_StaticCountdown(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    // STATE_IDLE does nothing; wait until started
    case STATE_START:
        sStaticCountdownFuncs[tFuncSetId][FUNC_START](taskId);
        tState = STATE_RUN;
        break;
    case STATE_RUN:
        sStaticCountdownFuncs[tFuncSetId][FUNC_RUN](taskId);
        break;
    case STATE_END:
        sStaticCountdownFuncs[tFuncSetId][FUNC_FREE](taskId);
        DestroyTask(taskId);
        break;
    }
}

void StaticCountdown_CreateSprites(u8 taskId, s16 *data)
{
    u8 i;
    struct Sprite *sprite;

    LoadCompressedSpriteSheet(&sSpriteSheet_321Start_Static[tSpriteSheetId]);
    LoadSpritePalette(&sSpritePalette_321Start_Static[tSpritePalId]);
    for (i = 0; i < tNumSprites; i++)
        tSpriteIds(i) = CreateSprite(&sSpriteTemplate_StaticCountdown[tSpriteTemplateId], tX, tY, tSubpriority);
    for (i = 0; i < tNumSprites; i++)
    {
        sprite = &gSprites[tSpriteIds(i)];
        sprite->oam.priority = tPriority;
        sprite->invisible = TRUE;
        sprite->sInterval = tInterval;
        sprite->sTaskId = taskId;
        sprite->sId = i;
        sprite->sNumberSpriteId = tSpriteIds(0);
    }
}

void Task_StaticCountdown_Init(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    tSpriteTemplateId = 0;
    tSpriteSheetId = 0;
    tSpritePalId = 0;
    tInterval = 60;
    tPriority = 0;
    tSubpriority = 0;
    tNumSprites = 3;
    tX = 120;
    tY = 88;
    StaticCountdown_CreateSprites(taskId, data);

    StartSpriteAnim(&gSprites[tSpriteIds(1)], ANIM_START_MID);
    gSprites[tSpriteIds(1)].x2 = -32;

    StartSpriteAnim(&gSprites[tSpriteIds(2)], ANIM_START_RIGHT);
    gSprites[tSpriteIds(2)].x2 = 32;
}

void Task_StaticCountdown_Free(u8 taskId)
{
    u8 i = 0;
    s16 *data = gTasks[taskId].data;

    for (i = 0; i < tNumSprites; i++)
        DestroySprite(&gSprites[tSpriteIds(i)]);
    FreeSpriteTilesByTag(sSpriteSheet_321Start_Static[tSpriteSheetId].tag);
    FreeSpritePaletteByTag(sSpritePalette_321Start_Static[tSpritePalId].tag);
}

void SpriteCB_StaticCountdown(struct Sprite *sprite)
{
    s16 *data = gTasks[sprite->sTaskId].data;

    if (tTimer % tInterval != 0)
        return;
    if (tTimer == tPrevTime)
        return;

    tPrevTime = tTimer;
    switch (sprite->sAnimNum)
    {
    case ANIM_THREE:
        sprite->invisible = FALSE;
    case ANIM_TWO:
    case ANIM_ONE:
        PlaySE(SE_BALL_BOUNCE_1);
        StartSpriteAnim(sprite, sprite->sAnimNum);
        break;
    case ANIM_START_LEFT:
        PlaySE(SE_PIN);
        StartSpriteAnim(sprite, sprite->sAnimNum);
        gSprites[tSpriteIds(1)].invisible = FALSE;
        gSprites[tSpriteIds(2)].invisible = FALSE;
        break;
    case ANIM_START_LEFT + 1:
        sprite->invisible = TRUE;
        gSprites[tSpriteIds(1)].invisible = TRUE;
        gSprites[tSpriteIds(2)].invisible = TRUE;
        tState = STATE_END;
        return;
    }
    sprite->sAnimNum++;
}

void Task_StaticCountdown_Start(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    PlaySE(SE_BALL_BOUNCE_1);
    gSprites[tSpriteIds(0)].callback = SpriteCB_StaticCountdown;
    gSprites[tSpriteIds(0)].invisible = FALSE;
    gTasks[taskId].tState = STATE_RUN;
}

void Task_StaticCountdown_Run(u8 taskId)
{
    u16 packet[RFU_PACKET_SIZE];
    s16 *data = gTasks[taskId].data;

    if (gReceivedRemoteLinkPlayers)
    {
        // Read link timer
        if (gRecvCmds[0][1] == LINKCMD_COUNTDOWN)
            tTimer = gRecvCmds[0][2];

        if (GetMultiplayerId() == 0)
        {
            // Player is link leader. Send timer to group members.
            tLinkTimer++;
            memset(packet, 0, sizeof(packet));
            packet[0] = LINKCMD_COUNTDOWN;
            packet[1] = tLinkTimer;
            Rfu_SendPacket(packet);
        }
    }
    else
    {
        // Local, just increment own timer
        tTimer++;
    }
}

#undef tState
#undef tFuncSetId
#undef tSpriteTemplateId
#undef tSpriteSheetId
#undef tSpritePalId
#undef tInterval
#undef tPriority
#undef tSubpriority
#undef tNumSprites
#undef tX
#undef tY
#undef tPrevTime
#undef tTimer
#undef tLinkTimer
#undef tSpriteIds
#undef sInterval
#undef sAnimNum
#undef sTaskId
#undef sId
#undef sNumberSpriteId

// ---- Animated '3-2-1 Start' countdown used by the wireless minigames ----
void Task_MinigameCountdown(u8 taskId);
bool32 RunMinigameCountdownDigitsAnim(u8 spriteId);
bool32 IsStartGraphicAnimRunning(u8 spriteId);
void Load321StartGfx(u16 tileTag, u16 palTag);
u8 CreateNumberSprite(u16 tileTag, u16 palTag, s16 x, s16 y, u8 subpriority);
void CreateStartSprite(u16 tileTag, u16 palTag, s16 x, s16 y, u8 subpriority, s16 *spriteId1, s16 *spriteId2);
void InitStartGraphic(u8 spriteId1, u8 spriteId2, u8 spriteId3);
void SpriteCB_Start(struct Sprite *sprite);

// JP keeps these template structures in ROM data; US builds them in C.
static const struct CompressedSpriteSheet s321StartGfxSheet;
static const struct SpritePalette s321StartPalette;
static const struct SpriteTemplate sSpriteTemplate_Number;
static const struct SpriteTemplate sSpriteTemplate_Start;

#define tState       data[0]
#define tTilesTag    data[2]
#define tPalTag      data[3]
#define tX           data[4]
#define tY           data[5]
#define tSubpriority data[6]
#define tSpriteId1   data[7]
#define tSpriteId2   data[8]
#define tSpriteId3   data[9]

void StartMinigameCountdown(u16 tilesTag, u16 palTag, s16 x, s16 y, u8 subpriority)
{
    u8 taskId = CreateTask(Task_MinigameCountdown, 80);
    gTasks[taskId].tTilesTag = tilesTag;
    gTasks[taskId].tPalTag = palTag;
    gTasks[taskId].tX = x;
    gTasks[taskId].tY = y;
    gTasks[taskId].tSubpriority = subpriority;
}

bool32 IsMinigameCountdownRunning(void)
{
    return FuncIsActiveTask(Task_MinigameCountdown);
}

void Task_MinigameCountdown(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        Load321StartGfx(tTilesTag, tPalTag);
        tSpriteId1 = CreateNumberSprite(tTilesTag, tPalTag, tX, tY, tSubpriority);
        CreateStartSprite(tTilesTag, tPalTag, tX, tY, tSubpriority, &tSpriteId2, &tSpriteId3);
        tState++;
        break;
    case 1:
        if (!RunMinigameCountdownDigitsAnim(tSpriteId1))
        {
            InitStartGraphic(tSpriteId1, tSpriteId2, tSpriteId3);
            FreeSpriteOamMatrix(&gSprites[tSpriteId1]);
            DestroySprite(&gSprites[tSpriteId1]);
            tState++;
        }
        break;
    case 2:
        if (!IsStartGraphicAnimRunning(tSpriteId2))
        {
            DestroySprite(&gSprites[tSpriteId2]);
            DestroySprite(&gSprites[tSpriteId3]);
            FreeSpriteTilesByTag(tTilesTag);
            FreeSpritePaletteByTag(tPalTag);
            DestroyTask(taskId);
        }
        break;
    }
}

#undef tState
#undef tTilesTag
#undef tPalTag
#undef tX
#undef tY
#undef tSubpriority
#undef tSpriteId1
#undef tSpriteId2
#undef tSpriteId3

#define sState   data[0]
#define sTimer   data[2]
#define sAnimNum data[4]

bool32 RunMinigameCountdownDigitsAnim(u8 spriteId)
{
    struct Sprite *sprite = &gSprites[spriteId];

    switch (sprite->sState)
    {
    case 0:
        SetSpriteMatrixAnchor(sprite, NO_ANCHOR, 26);
        sprite->sState++;
        // fallthrough
    case 1:
        if (sprite->sTimer == 0)
            PlaySE(SE_BALL_BOUNCE_2);

        if (++sprite->sTimer >= 20)
        {
            // Ready for jump
            sprite->sTimer = 0;
            StartSpriteAffineAnim(sprite, 1);
            sprite->sState++;
        }
        break;
    case 2:
        if (sprite->affineAnimEnded)
            sprite->sState++;
        break;
    case 3:
        if (++sprite->sTimer >= 4)
        {
            // Start jump
            sprite->sTimer = 0;
            sprite->sState++;
            StartSpriteAffineAnim(sprite, 2);
        }
        break;
    case 4:
        // Moving up from jump
        sprite->y -= 4;
        if (++sprite->sTimer >= 8)
        {
            if (sprite->sAnimNum < 2)
            {
                // Swap to the next number
                StartSpriteAnim(sprite, sprite->sAnimNum + 1);
                sprite->sTimer = 0;
                sprite->sState++;
            }
            else
            {
                // End
                sprite->sState = 7;
                return FALSE;
            }
        }
        break;
    case 5:
        // Falling after jump
        sprite->y += 4;
        if (++sprite->sTimer >= 8)
        {
            // Land from jump
            sprite->sTimer = 0;
            StartSpriteAffineAnim(sprite, 3);
            sprite->sState++;
        }
        break;
    case 6:
        if (sprite->affineAnimEnded)
        {
            // Restart for next number
            sprite->sAnimNum++;
            sprite->sState = 1;
        }
        break;
    case 7:
        return FALSE;
    }

    return TRUE;
}

#undef sState
#undef sTimer
#undef sAnimNum

// First argument is unused.
void InitStartGraphic(u8 spriteId1, u8 spriteId2, u8 spriteId3)
{
    gSprites[spriteId2].y2 = -40;
    gSprites[spriteId3].y2 = -40;
    gSprites[spriteId2].invisible = FALSE;
    gSprites[spriteId3].invisible = FALSE;
    gSprites[spriteId2].callback = SpriteCB_Start;
    gSprites[spriteId3].callback = SpriteCB_Start;
}

bool32 IsStartGraphicAnimRunning(u8 spriteId)
{
    return gSprites[spriteId].callback == SpriteCB_Start;
}

#define sState   data[0]
#define sTimer   data[1]
#define sYSpeed data[4]
#define sY      data[5]

void SpriteCB_Start(struct Sprite *sprite)
{
    int y;
    s16 *data = sprite->data;

    switch (sState)
    {
    case 0:
        sYSpeed = 64;
        sY = sprite->y2 << 4;
        sState++;
    case 1:
        sY += sYSpeed;
        sYSpeed++;
        sprite->y2 = sY >> 4;
        if (sprite->y2 >= 0)
        {
            PlaySE(SE_BALL_BOUNCE_2);
            sprite->y2 = 0;
            sState++;
        }
        break;
    case 2:
        sTimer += 12;
        if (sTimer >= 128)
        {
            PlaySE(SE_BALL_BOUNCE_2);
            sTimer = 0;
            sState++;
        }
        y = gSineTable[sTimer];
        sprite->y2 = -(y >> 4);
        break;
    case 3:
        sTimer += 16;
        if (sTimer >= 128)
        {
            PlaySE(SE_BALL_BOUNCE_2);
            sTimer = 0;
            sState++;
        }
        sprite->y2 = -(gSineTable[sTimer] >> 5);
        break;
    case 4:
        if (++sTimer > 40)
            sprite->callback = SpriteCallbackDummy;
        break;
    }
}

#undef sState
#undef sTimer
#undef sYSpeed
#undef sY

void Load321StartGfx(u16 tileTag, u16 palTag)
{
    struct CompressedSpriteSheet spriteSheet = s321StartGfxSheet;
    struct SpritePalette spritePalette = s321StartPalette;

    spriteSheet.tag = tileTag;
    spritePalette.tag = palTag;

    LoadCompressedSpriteSheet(&spriteSheet);
    LoadSpritePalette(&spritePalette);
}

u8 CreateNumberSprite(u16 tileTag, u16 palTag, s16 x, s16 y, u8 subpriority)
{
    struct SpriteTemplate spriteTemplate = sSpriteTemplate_Number;

    spriteTemplate.tileTag = tileTag;
    spriteTemplate.paletteTag = palTag;
    return CreateSprite(&spriteTemplate, x, y, subpriority);
}

void CreateStartSprite(u16 tileTag, u16 palTag, s16 x, s16 y, u8 subpriority, s16 *spriteId1, s16 *spriteId2)
{
    struct SpriteTemplate spriteTemplate = sSpriteTemplate_Start;

    spriteTemplate.tileTag = tileTag;
    spriteTemplate.paletteTag = palTag;
    *spriteId1 = CreateSprite(&spriteTemplate, x - 32, y, subpriority);
    *spriteId2 = CreateSprite(&spriteTemplate, x + 32, y, subpriority);

    gSprites[*spriteId1].invisible = TRUE;
    gSprites[*spriteId2].invisible = TRUE;
    StartSpriteAnim(&gSprites[*spriteId2], 1);
}

#define STATIC_COUNTDOWN_DATA __attribute__((section(".rodata.minigame_countdown_static")))

// Static 321 countdown data (0x82D1B10..0x82D1F54).

// 0x82D1B10 - static 321-start countdown palette (16 colors).
static const u16 s321Start_Static_Pal[] STATIC_COUNTDOWN_DATA = INCGFX_U16("graphics/link/321start_static.png", ".gbapal");

// 0x82D1B30 - static 321-start countdown LZ graphics (decompresses to 0xC00).
static const u32 s321Start_Static_Gfx[] STATIC_COUNTDOWN_DATA = INCGFX_U32("graphics/link/321start_static.png", ".4bpp.lz");

#undef STATIC_COUNTDOWN_DATA

#define MINIGAME_COUNTDOWN_DATA __attribute__((section(".rodata.minigame_countdown_data")))

// 321 countdown data (0x82D1F54..0x82D254C).

#define TAG_STATIC_COUNTDOWN 0x2000

extern const struct OamData gOamData_AffineOff_ObjNormal_32x32; // 0x084FD020 (battle_anim data)
extern void Task_StaticCountdown_Init(u8 taskId); // src/minigame_countdown.c
extern void Task_StaticCountdown_Free(u8 taskId);
extern void Task_StaticCountdown_Start(u8 taskId);
extern void Task_StaticCountdown_Run(u8 taskId);

// 0x82D1F54
static const struct CompressedSpriteSheet sSpriteSheet_321Start_Static[] MINIGAME_COUNTDOWN_DATA =
{
    {s321Start_Static_Gfx, 0xC00, TAG_STATIC_COUNTDOWN},
    {},
};

// 0x82D1F64
static const struct SpritePalette sSpritePalette_321Start_Static[] MINIGAME_COUNTDOWN_DATA =
{
    {s321Start_Static_Pal, TAG_STATIC_COUNTDOWN},
    {},
};

// 0x82D1F74 - static countdown number/start anims (unused in JP, like US).
static const union AnimCmd sAnim_StaticCountdown_Three[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(0, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_StaticCountdown_Two[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(16, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_StaticCountdown_One[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(32, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_StaticCountdown_StartLeft[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(64, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_StaticCountdown_StartMid[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(48, 0),
    ANIMCMD_END
};

static const union AnimCmd sAnim_StaticCountdown_StartRight[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_END
};

// 0x82D1FA4
static const union AnimCmd *const sAnims_StaticCountdown[] MINIGAME_COUNTDOWN_DATA =
{
    sAnim_StaticCountdown_Three,
    sAnim_StaticCountdown_Two,
    sAnim_StaticCountdown_One,
    sAnim_StaticCountdown_StartLeft,
    sAnim_StaticCountdown_StartMid,
    sAnim_StaticCountdown_StartRight,
};

// 0x82D1FBC
static const struct SpriteTemplate sSpriteTemplate_StaticCountdown[] MINIGAME_COUNTDOWN_DATA =
{
    {
        .tileTag = TAG_STATIC_COUNTDOWN,
        .paletteTag = TAG_STATIC_COUNTDOWN,
        .oam = &gOamData_AffineOff_ObjNormal_32x32,
        .anims = sAnims_StaticCountdown,
        .images = NULL,
        .affineAnims = gDummySpriteAffineAnimTable,
        .callback = SpriteCallbackDummy,
    },
};

// 0x82D1FD4 - task funcs (Task_StaticCountdown_* in src/pokemon_jump.c).
static const TaskFunc sStaticCountdownFuncs[][4] MINIGAME_COUNTDOWN_DATA =
{
    {
        Task_StaticCountdown_Init,
        Task_StaticCountdown_Free,
        Task_StaticCountdown_Start,
        Task_StaticCountdown_Run,
    },
};

// 0x82D1FE4 - minigame countdown palette (s321StartPalette.data).
static const u16 s321Start_Pal[] MINIGAME_COUNTDOWN_DATA = INCGFX_U16("graphics/link/321start.png", ".gbapal");

// 0x82D2004 - minigame countdown LZ gfx (decompresses to 0xE00, s321StartGfxSheet.data).
static const u32 s321Start_Gfx[] MINIGAME_COUNTDOWN_DATA = INCGFX_U32("graphics/link/321start.png", ".4bpp.lz");

// 0x82D2458
static const struct CompressedSpriteSheet s321StartGfxSheet MINIGAME_COUNTDOWN_DATA =
{
    s321Start_Gfx, 0xE00, 0,
};

// 0x82D2460
static const struct SpritePalette s321StartPalette MINIGAME_COUNTDOWN_DATA =
{
    s321Start_Pal, 0,
};

// 0x82D2468 - number sprite oam (affine double, 32x32).
static const struct OamData sOamData_Numbers MINIGAME_COUNTDOWN_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

// 0x82D2470 - start sprite oam (affine off, 64x32).
static const struct OamData sOamData_Start MINIGAME_COUNTDOWN_DATA =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

// 0x82D2478 - minigame countdown number anims.
static const union AnimCmd sAnim_Numbers_Three[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Numbers_Two[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(16, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_Numbers_One[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(32, 1),
    ANIMCMD_END
};

// 0x82D2490
static const union AnimCmd *const sAnimTable_Numbers[] MINIGAME_COUNTDOWN_DATA =
{
    sAnim_Numbers_Three,
    sAnim_Numbers_Two,
    sAnim_Numbers_One,
};

// 0x82D249C - minigame countdown start anims.
static const union AnimCmd sAnim_StartLeft[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(48, 1),
    ANIMCMD_END
};

static const union AnimCmd sAnim_StartRight[] MINIGAME_COUNTDOWN_DATA =
{
    ANIMCMD_FRAME(80, 1),
    ANIMCMD_END
};

// 0x82D24AC
static const union AnimCmd *const sAnimTable_Start[] MINIGAME_COUNTDOWN_DATA =
{
    sAnim_StartLeft,
    sAnim_StartRight,
};

// 0x82D24B4 - number affine anims (values match pokeemerald).
static const union AffineAnimCmd sAffineAnim_Numbers_Normal[] MINIGAME_COUNTDOWN_DATA =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Numbers_Squash[] MINIGAME_COUNTDOWN_DATA =
{
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_FRAME(16, -16, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Numbers_Stretch[] MINIGAME_COUNTDOWN_DATA =
{
    AFFINEANIMCMD_FRAME(-18, 18, 0, 8),
    AFFINEANIMCMD_END
};

static const union AffineAnimCmd sAffineAnim_Numbers_Land[] MINIGAME_COUNTDOWN_DATA =
{
    AFFINEANIMCMD_FRAME(6, -6, 0, 8),
    AFFINEANIMCMD_FRAME(-4, 4, 0, 8),
    AFFINEANIMCMD_FRAME(256, 256, 0, 0),
    AFFINEANIMCMD_END
};

// 0x82D250C
static const union AffineAnimCmd *const sAffineAnimTable_Numbers[] MINIGAME_COUNTDOWN_DATA =
{
    sAffineAnim_Numbers_Normal,
    sAffineAnim_Numbers_Squash,
    sAffineAnim_Numbers_Stretch,
    sAffineAnim_Numbers_Land,
};

// 0x82D251C
static const struct SpriteTemplate sSpriteTemplate_Number MINIGAME_COUNTDOWN_DATA =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOamData_Numbers,
    .anims = sAnimTable_Numbers,
    .images = NULL,
    .affineAnims = sAffineAnimTable_Numbers,
    .callback = SpriteCallbackDummy,
};

// 0x82D2534
static const struct SpriteTemplate sSpriteTemplate_Start MINIGAME_COUNTDOWN_DATA =
{
    .tileTag = 0,
    .paletteTag = 0,
    .oam = &sOamData_Start,
    .anims = sAnimTable_Start,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

#undef MINIGAME_COUNTDOWN_DATA
