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

extern const struct CompressedSpriteSheet sSpriteSheet_321Start_Static[];
extern const struct SpritePalette sSpritePalette_321Start_Static[];
extern const struct SpriteTemplate sSpriteTemplate_StaticCountdown[];
extern const TaskFunc sStaticCountdownFuncs[][4];

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
extern const struct CompressedSpriteSheet s321StartGfxSheet;
extern const struct SpritePalette s321StartPalette;
extern const struct SpriteTemplate sSpriteTemplate_Number;
extern const struct SpriteTemplate sSpriteTemplate_Start;

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
