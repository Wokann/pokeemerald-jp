#include "global.h"
#include "bg.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gba/defines.h"
#include "gpu_regs.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/weather.h"

#define GOING_DOWN gSpecialVar_0x8004

#define STATE_END 0xFF

struct CableCarData
{
    u8 bgTaskId;
    u8 state;
    u8 weather;
    u16 weatherDelay;
    u16 timer;
    u8 bg0HorizontalOffset;
    u8 bg0VerticalOffset;
    u8 unused0[2];
    u8 bg1HorizontalOffset;
    u8 bg1VerticalOffset;
    u8 unused1[6];
    u8 bg3HorizontalOffset;
    u8 bg3VerticalOffset;
    u8 unused2[2];
    u8 groundTileIdx;
    u8 groundSegmentXStart;
    u8 groundSegmentYStart;
    u8 groundTilemapOffset;
    u8 groundTimer; // Incremented, but does nothing
    u8 groundXOffset;
    u8 groundYOffset;
    u8 groundXBase;
    u8 groundYBase;
    u16 groundTileBuffer[9][12];
    u8 unused3[2];
    u16 bgTilemapBuffers[4][BG_SCREEN_SIZE];
    u16 *groundTilemap;
    u16 *treesTilemap;
    u16 *bgMountainsTilemap;
    u16 *pylonTopTilemap;
    u16 *pylonPoleTilemap;
};

// JP: no EWRAM_DATA attribute (breaks agbcc struct tag parsing); ld alias
// sCableCar = gUnknown_203A878 places the pointer at the JP ROM address.
extern struct CableCarData *sCableCar;

extern void CB2_LoadCableCar(void);




extern const struct BgTemplate sCableCarBgTemplates[];
extern const u16 sCableCarGround_Tilemap[];
extern const u16 sCableCarTrees_Tilemap[];
extern const u16 sCableCarBgMountains_Tilemap[];
extern const u16 sCableCarPylonTop_Tilemap[];
extern const u16 sCableCarPylonPole_Tilemap[];
extern const struct CompressedSpriteSheet sCableCarSpriteSheets[];
extern const struct SpritePalette sCableCarSpritePalettes[];
extern const u32 gCableCarBg_Gfx[];
extern const u16 gCableCarBg_Pal[];

extern const u8 sCableCarPlayerGraphicsIds[2];
extern const u8 sCableCarHikerGraphicsIds[4];
extern const s16 sCableCarHikerCoords[2][2];
extern const u8 sCableCarHikerMovementDelayTable[4];
extern void (*sCableCarHikerCallbacks[2])(struct Sprite *);
extern const struct SpriteTemplate sSpriteTemplates_CableCar[2];
extern const struct SpriteTemplate sSpriteTemplate_Cable;
extern u8 AddPseudoEventObject(u16 graphicsId, void (*callback)(struct Sprite *), s16 x, s16 y, u8 subpriority);
extern u8 sGroundX_Up;
extern u8 sGroundY_Up;
extern u8 sGroundSegmentY_Up;
extern u8 sGroundX_Down;
extern u8 sGroundY_Down;
extern u8 sGroundSegmentY_Down;

void CB2_CableCar(void);
void Task_CableCar(u8 taskId);
void Task_AnimateBgGoingUp(u8 taskId);
void Task_AnimateBgGoingDown(u8 taskId);
void VBlankCB_CableCar(void);
extern void CreateCableCarSprites(void);
extern void SetBgRegs(bool8 value);
extern void InitGroundTilemapData(u8 mode);
extern void DrawNextGroundSegmentGoingUp(void);
extern void DrawNextGroundSegmentGoingDown(void);

void CB2_LoadCableCar(void)
{
    u8 i = 0;
    u32 sizeOut = 0;

    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        SetBgRegs(FALSE);
        ScanlineEffect_Stop();
        DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
        DmaFill32Defvars(3, 0, (void *)OAM, OAM_SIZE);
        DmaFill16Defvars(3, 0, (void *)PLTT, PLTT_SIZE);
        sCableCar = AllocZeroed(sizeof(*sCableCar));
        gMain.state++;
        break;
    case 1:
        ResetSpriteData();
        ResetTasks();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetTempTileDataBuffers();
        StartWeather();
        for (i = 0; i < NUM_ASH_SPRITES; i++)
            gWeatherPtr->sprites.s2.ashSprites[i] = NULL;

        InitMapMusic();
        ResetMapMusic();
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sCableCarBgTemplates, 4);
        SetBgTilemapBuffer(0, sCableCar->bgTilemapBuffers[0]);
        SetBgTilemapBuffer(1, sCableCar->bgTilemapBuffers[1]);
        SetBgTilemapBuffer(2, sCableCar->bgTilemapBuffers[2]);
        SetBgTilemapBuffer(3, sCableCar->bgTilemapBuffers[3]);
        gSpriteCoordOffsetX = gSpriteCoordOffsetY = 0;
        gMain.state++;
        break;
    case 2:
        for (i = 0; i < 3; i++)
            LoadCompressedSpriteSheet(&sCableCarSpriteSheets[i]);

        LoadSpritePalettes(sCableCarSpritePalettes);
        sCableCar->groundTilemap = malloc_and_decompress(sCableCarGround_Tilemap, &sizeOut);
        sCableCar->treesTilemap = malloc_and_decompress(sCableCarTrees_Tilemap, &sizeOut);
        sCableCar->bgMountainsTilemap = malloc_and_decompress(sCableCarBgMountains_Tilemap, &sizeOut);
        sCableCar->pylonPoleTilemap = malloc_and_decompress(sCableCarPylonPole_Tilemap, &sizeOut);
        sCableCar->pylonTopTilemap = sCableCarPylonTop_Tilemap;
        DecompressAndCopyTileDataToVram(0, gCableCarBg_Gfx, 0, 0, 0);
        gMain.state++;
        break;
    case 3:
        if (!FreeTempTileDataBuffersIfPossible())
        {
            LoadPalette(gCableCarBg_Pal, BG_PLTT_ID(0), 4 * PLTT_SIZE_4BPP);
            gMain.state++;
        }
        break;
    case 4:
        CreateCableCarSprites();
        RunTasks();
        gMain.state++;
        break;
    case 5:
        if (sCableCar->weather == WEATHER_VOLCANIC_ASH)
        {
            gMain.state++;
        }
        else if (gWeatherPtr->sprites.s2.ashSprites[0])
        {
            for (i = 0; i < NUM_ASH_SPRITES; i++)
            {
                if (gWeatherPtr->sprites.s2.ashSprites[i])
                    gWeatherPtr->sprites.s2.ashSprites[i]->oam.priority = 0;
            }

            gMain.state++;
        }
        break;
    case 6:
        CopyToBgTilemapBufferRect_ChangePalette(1, sCableCar->treesTilemap, 0, 17, 32, 15, 17);
        CopyToBgTilemapBufferRect_ChangePalette(2, sCableCar->bgMountainsTilemap, 0, 0, 30, 20, 17);
        CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonTopTilemap, 0, 0, 5, 2, 17);
        CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonPoleTilemap, 0, 2, 2, 20, 17);
        gMain.state++;
        break;
    case 7:
        InitGroundTilemapData(GOING_DOWN);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +  0x48,  0, 14, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +  0x6C, 12, 17, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +  0x90, 24, 20, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +   0x0,  0, 17, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +  0x24,  0, 20, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +   0x0, 12, 20, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +  0x24, 12, 23, 12, 3, 17);
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap +   0x0, 24, 23, 12, 3, 17);
        gMain.state++;
        break;
    case 8:
        BeginNormalPaletteFade(PALETTES_ALL, 3, 16, 0, RGB_BLACK);
        FadeInNewBGM(MUS_CABLE_CAR, 1);
        SetBgRegs(TRUE);
        gMain.state++;
        break;
    case 9:
        IntrEnable(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_CableCar);
        SetMainCallback2(CB2_CableCar);
        CreateTask(Task_CableCar, 0);
        if (!GOING_DOWN)
            sCableCar->bgTaskId = CreateTask(Task_AnimateBgGoingUp, 1);
        else
            sCableCar->bgTaskId = CreateTask(Task_AnimateBgGoingDown, 1);
        break;
    }
}

static void Task_LoadCableCar(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(CB2_LoadCableCar);
        DestroyTask(taskId);
    }
}
void CableCar(void)
{
    LockPlayerFieldControls();
    CreateTask(Task_LoadCableCar, 1);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
}

void CB2_CableCar(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    MapMusicMain();
}

// JP asm name (US: CB2_EndCableCar)
void CleanupCableCar(void)
{
    u8 i = 0;

    HideBg(0);
    HideBg(1);
    HideBg(2);
    HideBg(3);
    SetBgRegs(FALSE);
    gSpriteCoordOffsetX = 0;
    SetCurrentAndNextWeatherNoDelay(WEATHER_NONE);
    for (i = 0; i < NUM_ASH_SPRITES; i++)
        gWeatherPtr->sprites.s2.ashSprites[i] = NULL;

    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    UnsetBgTilemapBuffer(0);
    UnsetBgTilemapBuffer(1);
    UnsetBgTilemapBuffer(2);
    UnsetBgTilemapBuffer(3);
    ResetBgsAndClearDma3BusyFlags(0);
    sCableCar->pylonTopTilemap = NULL;
    FREE_AND_SET_NULL(sCableCar->pylonPoleTilemap);
    FREE_AND_SET_NULL(sCableCar->bgMountainsTilemap);
    FREE_AND_SET_NULL(sCableCar->treesTilemap);
    FREE_AND_SET_NULL(sCableCar->groundTilemap);
    FREE_AND_SET_NULL(sCableCar);
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    DmaFill32Defvars(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16Defvars(3, 0, (void *)PLTT, PLTT_SIZE);
    WarpIntoMap();
    gFieldCallback = NULL;
    SetMainCallback2(CB2_LoadMap);
}

void Task_CableCar(u8 taskId)
{
    u8 i = 0;

    sCableCar->timer++;
    switch (sCableCar->state)
    {
    case 0:
        // Wait to change weather
        if (sCableCar->timer == sCableCar->weatherDelay)
        {
            SetNextWeather(sCableCar->weather);
            sCableCar->state = 1;
        }
        break;
    case 1:
        // Update ash sprites
        switch (sCableCar->weather)
        {
        case WEATHER_VOLCANIC_ASH:
            if (gWeatherPtr->sprites.s2.ashSprites[0] != NULL && gWeatherPtr->sprites.s2.ashSprites[0]->oam.priority != 0)
            {
                for (; i < NUM_ASH_SPRITES; i++)
                {
                    if (gWeatherPtr->sprites.s2.ashSprites[i])
                        gWeatherPtr->sprites.s2.ashSprites[i]->oam.priority = 0;
                }

                sCableCar->state = 2;
            }
            break;
        case WEATHER_SUNNY:
            if (gWeatherPtr->currWeather == WEATHER_SUNNY)
            {
                sCableCar->state = 2;
            }
            else if (sCableCar->timer >= sCableCar->weatherDelay + 8)
            {
                for (; i < NUM_ASH_SPRITES; i++)
                {
                    if (gWeatherPtr->sprites.s2.ashSprites[i])
                        gWeatherPtr->sprites.s2.ashSprites[i]->invisible ^= 1;
                }
            }
            break;
        }
        break;
    case 2:
        // Wait to fade out
        if (sCableCar->timer == 570)
        {
            sCableCar->state = 3;
            BeginNormalPaletteFade(PALETTES_ALL, 3, 0, 16, RGB_BLACK);
            FadeOutBGMTemporarily(4);
        }
        break;
    case 3:
        // Wait for fade out
        if (!gPaletteFade.active)
            sCableCar->state = STATE_END;
        break;
    case STATE_END:
        SetVBlankCallback(NULL);
        DestroyTask(taskId);
        DestroyTask(sCableCar->bgTaskId);
        SetMainCallback2(CleanupCableCar);
        break;
    }
}


void Task_AnimateBgGoingUp(u8 taskId)
{
    if (sCableCar->state != STATE_END)
    {
        sCableCar->bg3HorizontalOffset--;
        if ((sCableCar->timer % 2) == 0)
            sCableCar->bg3VerticalOffset--;

        if ((sCableCar->timer % 8) == 0)
        {
            sCableCar->bg1HorizontalOffset--;
            sCableCar->bg1VerticalOffset--;
        }

        switch (sCableCar->bg3HorizontalOffset)
        {
        case 175:
            FillBgTilemapBufferRect(3, 0, 0, 22, 2, 10, 17);
            break;
        case 40:
            FillBgTilemapBufferRect(3, 0, 3, 0, 2, 2, 17);
            break;
        case 32:
            FillBgTilemapBufferRect(3, 0, 2, 0, 1, 2, 17);
            break;
        case 16:
            CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonTopTilemap, 0, 0, 5,  2, 17);
            CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonPoleTilemap, 0, 2, 2, 30, 17);
            sCableCar->bg3VerticalOffset = 64;
            break;
        }
    }

    AnimateGroundGoingUp();
    gSpriteCoordOffsetX = (gSpriteCoordOffsetX + 1) % 128;
}

void Task_AnimateBgGoingDown(u8 taskId)
{
    if (sCableCar->state != STATE_END)
    {
        sCableCar->bg3HorizontalOffset++;
        if ((sCableCar->timer % 2) == 0)
            sCableCar->bg3VerticalOffset++;

        if ((sCableCar->timer % 8) == 0)
        {
            sCableCar->bg1HorizontalOffset++;
            sCableCar->bg1VerticalOffset++;
        }

        switch (sCableCar->bg3HorizontalOffset)
        {
        case 176:
            CopyToBgTilemapBufferRect_ChangePalette(3, sCableCar->pylonPoleTilemap, 0, 2, 2, 30, 17);
            break;
        case 16:
            FillBgTilemapBufferRect(3, 0, 2,  0, 3,  2, 17);
            FillBgTilemapBufferRect(3, 0, 0, 22, 2, 10, 17);
            sCableCar->bg3VerticalOffset = 192;
            break;
        case 32:
            FillBgTilemapBufferRect(3, sCableCar->pylonTopTilemap[2], 2, 0, 1, 1, 17);
            FillBgTilemapBufferRect(3, sCableCar->pylonTopTilemap[3], 3, 0, 1, 1, 17);
            FillBgTilemapBufferRect(3, sCableCar->pylonTopTilemap[7], 2, 1, 1, 1, 17);
            FillBgTilemapBufferRect(3, sCableCar->pylonTopTilemap[8], 3, 1, 1, 1, 17);
            break;
        case 40:
            FillBgTilemapBufferRect(3, sCableCar->pylonTopTilemap[4], 4, 0, 1, 1, 17);
            FillBgTilemapBufferRect(3, sCableCar->pylonTopTilemap[9], 4, 1, 1, 1, 17);
            break;
        }
    }

    AnimateGroundGoingDown();
    if (sCableCar->timer < sCableCar->weatherDelay)
        gSpriteCoordOffsetX = (gSpriteCoordOffsetX + 247) % 248;
    else
        gWeatherPtr->ashBaseSpritesX = (gWeatherPtr->ashBaseSpritesX + 247) % 248;
}

void VBlankCB_CableCar(void)
{
    CopyBgTilemapBufferToVram(0);
    CopyBgTilemapBufferToVram(3);
    SetGpuReg(REG_OFFSET_BG3HOFS, sCableCar->bg3HorizontalOffset);
    SetGpuReg(REG_OFFSET_BG3VOFS, sCableCar->bg3VerticalOffset);
    SetGpuReg(REG_OFFSET_BG1HOFS, sCableCar->bg1HorizontalOffset);
    SetGpuReg(REG_OFFSET_BG1VOFS, sCableCar->bg1VerticalOffset);
    SetGpuReg(REG_OFFSET_BG0HOFS, sCableCar->bg0HorizontalOffset);
    SetGpuReg(REG_OFFSET_BG0VOFS, sCableCar->bg0VerticalOffset);
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void AnimateGroundGoingUp(void)
{
    sCableCar->groundTimer = (sCableCar->groundTimer + 1) % 96;
    sCableCar->bg0HorizontalOffset = sCableCar->groundXBase - sCableCar->groundXOffset;
    sCableCar->bg0VerticalOffset = sCableCar->groundYBase - sCableCar->groundYOffset;
    sCableCar->groundXOffset++;
    if ((sCableCar->groundXOffset % 4) == 0)
        sCableCar->groundYOffset++;

    if (sCableCar->groundXOffset > 16)
        DrawNextGroundSegmentGoingUp();
}

void AnimateGroundGoingDown(void)
{
    sCableCar->groundTimer = (sCableCar->groundTimer + 1) % 96;
    sCableCar->bg0HorizontalOffset = sCableCar->groundXBase + sCableCar->groundXOffset;
    sCableCar->bg0VerticalOffset = sCableCar->groundYBase + sCableCar->groundYOffset;
    sCableCar->groundXOffset++;
    if ((sCableCar->groundXOffset % 4) == 0)
        sCableCar->groundYOffset++;

    if (sCableCar->groundXOffset > 16)
        DrawNextGroundSegmentGoingDown();
}

void nullsub_58(void)
{
}

#define sXPos data[0]
#define sYPos data[1]

static void SpriteCB_CableCar(struct Sprite *sprite)
{
    if (sCableCar->state != STATE_END)
    {
        if (!GOING_DOWN)
        {
            sprite->x = sprite->sXPos - (u8)(0.14f * S16TOPOSFLOAT(sCableCar->timer));
            sprite->y = sprite->sYPos - (u8)(0.067f * S16TOPOSFLOAT(sCableCar->timer));
        }
        else
        {
            sprite->x = sprite->sXPos + (u8)(0.14f * S16TOPOSFLOAT(sCableCar->timer));
            sprite->y = sprite->sYPos + (u8)(0.067f * S16TOPOSFLOAT(sCableCar->timer));
        }
    }
}

#define sState data[2]
#define sTimer data[3]

static void SpriteCB_Player(struct Sprite *sprite)
{
    if (sCableCar->state != STATE_END)
    {
        // Move along with cable car
        if (!GOING_DOWN)
        {
            sprite->x = sprite->sXPos - (u8)(0.14f * S16TOPOSFLOAT(sCableCar->timer));
            sprite->y = sprite->sYPos - (u8)(0.067f * S16TOPOSFLOAT(sCableCar->timer));
        }
        else
        {
            sprite->x = sprite->sXPos + (u8)(0.14f * S16TOPOSFLOAT(sCableCar->timer));
            sprite->y = sprite->sYPos + (u8)(0.067f * S16TOPOSFLOAT(sCableCar->timer));
        }

        // Bounce up and down
        switch (sprite->sState)
        {
        case 0:
            sprite->y2 = 17;
            if (sprite->sTimer++ > 9)
            {
                sprite->sTimer = 0;
                sprite->sState++;
            }
            break;
        default:
            sprite->y2 = 16;
            if (sprite->sTimer++ > 9)
            {
                sprite->sTimer = 0;
                sprite->sState = 0;
            }
            break;
        }
    }
}

#undef sState
#undef sTimer

#define sTimer      data[0]
#define sSameDir    data[1]
#define sDelay      data[2]

static void SpriteCB_HikerGoingUp(struct Sprite *sprite)
{
    if (sprite->sTimer == 0)
    {
        sprite->x += 2 * sprite->centerToCornerVecX;
        sprite->y += 16 + sprite->centerToCornerVecY;
    }

    if (++sprite->sTimer >= sprite->sDelay)
    {
        switch (sprite->sSameDir)
        {
        case FALSE:
            sprite->x++;
            if ((sprite->sTimer % 4) == 0)
                sprite->y++;
            break;
        case TRUE:
            // Hiker moves slower if travelling with the Cable Car
            if ((sprite->sTimer % 2) != 0)
            {
                sprite->x++;
                if ((sprite->x % 4) == 0)
                    sprite->y++;
            }
            break;
        }

        if (sprite->y > DISPLAY_HEIGHT)
            DestroySprite(sprite);
    }
}

static void SpriteCB_HikerGoingDown(struct Sprite *sprite)
{
    if (sprite->sTimer == 0)
        sprite->y += 16 + sprite->centerToCornerVecY;

    if (++sprite->sTimer >= sprite->sDelay)
    {
        switch (sprite->sSameDir)
        {
        case FALSE:
            sprite->x--;
            if ((sprite->sTimer % 4) == 0)
                sprite->y--;
            break;
        case TRUE:
            // Hiker moves slower if travelling with the Cable Car
            if ((sprite->sTimer % 2) != 0)
            {
                sprite->x--;
                if ((sprite->x % 4) == 0)
                    sprite->y--;
            }
            break;
        }

        if (sprite->y < 80)
            DestroySprite(sprite);
    }
}

#undef sTimer
#undef sSameDir
#undef sDelay

void SetBgRegs(bool8 active)
{
    switch (active)
    {
    case FALSE:
    default:
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG3CNT, 0);
        SetGpuReg(REG_OFFSET_BG2CNT, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, 0);
        SetGpuReg(REG_OFFSET_BG0CNT, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        break;
    case TRUE:
        SetGpuReg(REG_OFFSET_WININ, 0);
        SetGpuReg(REG_OFFSET_WINOUT, 0);
        SetGpuReg(REG_OFFSET_WIN0H, 0);
        SetGpuReg(REG_OFFSET_WIN1H, 0);
        SetGpuReg(REG_OFFSET_WIN0V, 0);
        SetGpuReg(REG_OFFSET_WIN1V, 0);
        if (!GOING_DOWN)
        {
            sCableCar->bg3HorizontalOffset = 176;
            sCableCar->bg3VerticalOffset = 16;
            sCableCar->bg1HorizontalOffset = 0;
            sCableCar->bg1VerticalOffset = 80;
            sCableCar->bg0VerticalOffset = 0;
            sCableCar->bg0VerticalOffset = 0;
        }
        else
        {
            sCableCar->bg3HorizontalOffset = 96;
            sCableCar->bg3VerticalOffset = 232;
            sCableCar->bg1HorizontalOffset = 0;
            sCableCar->bg1VerticalOffset = 4;
            sCableCar->bg0VerticalOffset = 0;
            sCableCar->bg0VerticalOffset = 0;
        }

        SetGpuReg(REG_OFFSET_BG3HOFS, sCableCar->bg3HorizontalOffset);
        SetGpuReg(REG_OFFSET_BG3VOFS, sCableCar->bg3VerticalOffset);
        SetGpuReg(REG_OFFSET_BG2HOFS, 0);
        SetGpuReg(REG_OFFSET_BG2VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1HOFS, sCableCar->bg1HorizontalOffset);
        SetGpuReg(REG_OFFSET_BG1VOFS, sCableCar->bg1VerticalOffset);
        SetGpuReg(REG_OFFSET_BG0HOFS, sCableCar->bg0HorizontalOffset);
        SetGpuReg(REG_OFFSET_BG0VOFS, sCableCar->bg0VerticalOffset);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(2);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        ShowBg(3);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_ALL);
        break;
    }
}

#define sSameDir data[1]
#define sDelay   data[2]

void LoadCableCarSprites(void)
{
    u8 spriteId;
    u8 i;
    u8 playerGraphicsIds[2];
    u8 hikerGraphicsIds[4];
    s16 hikerCoords[2][2];
    u8 hikerMovementDelayTable[4];
    void (*hikerCallbacks[2])(struct Sprite *);
    u16 rval;

    memcpy(playerGraphicsIds, sCableCarPlayerGraphicsIds, sizeof(playerGraphicsIds));
    rval = Random();
    memcpy(hikerGraphicsIds, sCableCarHikerGraphicsIds, sizeof(hikerGraphicsIds));
    memcpy(hikerCoords, sCableCarHikerCoords, sizeof(hikerCoords));
    memcpy(hikerMovementDelayTable, sCableCarHikerMovementDelayTable, sizeof(hikerMovementDelayTable));
    *(u64 *)hikerCallbacks = *(u64 *)sCableCarHikerCallbacks;

    switch (GOING_DOWN)
    {
    case FALSE:
    default:
        // Create player sprite
        spriteId = AddPseudoEventObject(playerGraphicsIds[gSaveBlock2Ptr->playerGender], SpriteCB_Player, 200, 73, 102);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].oam.priority = 2;
            gSprites[spriteId].x2 = 8;
            gSprites[spriteId].y2 = 16;
            gSprites[spriteId].sXPos = 200;
            gSprites[spriteId].sYPos = 73;
        }
        // Create car sprite
        spriteId = CreateSprite(&sSpriteTemplates_CableCar[0], 176, 43, 0x67);
        gSprites[spriteId].x2 = gSprites[spriteId].y2 = 32;
        gSprites[spriteId].sXPos = 176;
        gSprites[spriteId].sYPos = 43;
        // Create door sprite
        spriteId = CreateSprite(&sSpriteTemplates_CableCar[1], 200, 99, 0x65);
        gSprites[spriteId].x2 = 8;
        gSprites[spriteId].y2 = 4;
        gSprites[spriteId].sXPos = 200;
        gSprites[spriteId].sYPos = 99;
        // Init weather
        sCableCar->weather = WEATHER_VOLCANIC_ASH;
        sCableCar->weatherDelay = 350;
        SetCurrentAndNextWeatherNoDelay(WEATHER_SUNNY);
        break;
    case TRUE:
        CopyToBgTilemapBufferRect_ChangePalette(0, sCableCar->groundTilemap + 0x24, 24, 26, 12, 3, 17);
        // Create player sprite
        spriteId = AddPseudoEventObject(playerGraphicsIds[gSaveBlock2Ptr->playerGender], SpriteCB_Player, 128, 39, 102);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].oam.priority = 2;
            gSprites[spriteId].x2 = 8;
            gSprites[spriteId].y2 = 16;
            gSprites[spriteId].sXPos = 128;
            gSprites[spriteId].sYPos = 39;
        }
        // Create car sprite
        spriteId = CreateSprite(&sSpriteTemplates_CableCar[0], 104, 9, 0x67);
        gSprites[spriteId].x2 = gSprites[spriteId].y2 = 32;
        gSprites[spriteId].sXPos = 104;
        gSprites[spriteId].sYPos = 9;
        // Create door sprite
        spriteId = CreateSprite(&sSpriteTemplates_CableCar[1], 128, 65, 0x65);
        gSprites[spriteId].x2 = 8;
        gSprites[spriteId].y2 = 4;
        gSprites[spriteId].sXPos = 128;
        gSprites[spriteId].sYPos = 65;
        // Init weather
        sCableCar->weather = WEATHER_SUNNY;
        sCableCar->weatherDelay = 265;
        SetCurrentAndNextWeatherNoDelay(WEATHER_VOLCANIC_ASH);
        break;
    }

    for (i = 0; i < 9; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Cable, 16 * i + 96, 8 * i - 8, 0x68);
        gSprites[spriteId].x2 = 8;
        gSprites[spriteId].y2 = 8;
    }

    // 1/64 chance for an NPC to appear hiking on the ground below the Cable Car
    if ((rval % 64) == 0)
    {
        spriteId = AddPseudoEventObject(hikerGraphicsIds[rval % (ARRAY_COUNT(hikerGraphicsIds) - 1)], hikerCallbacks[GOING_DOWN], hikerCoords[GOING_DOWN][0], hikerCoords[GOING_DOWN][1], 106);
        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].oam.priority = 2;
            gSprites[spriteId].x2 = -gSprites[spriteId].centerToCornerVecX;
            gSprites[spriteId].y2 = -gSprites[spriteId].centerToCornerVecY;

            // Randomly choose which direction the NPC is going
            if (!GOING_DOWN)
            {
                if (rval % 2)
                {
                    StartSpriteAnim(&gSprites[spriteId], ANIM_STD_GO_WEST);
                    gSprites[spriteId].sSameDir = TRUE;
                    gSprites[spriteId].y += 2;
                }
                else
                {
                    StartSpriteAnim(&gSprites[spriteId], ANIM_STD_GO_EAST);
                    gSprites[spriteId].sSameDir = FALSE;
                }
            }
            else
            {
                if (rval % 2)
                {
                    StartSpriteAnim(&gSprites[spriteId], ANIM_STD_GO_EAST);
                    gSprites[spriteId].sSameDir = TRUE;
                    gSprites[spriteId].y += 2;
                }
                else
                {
                    StartSpriteAnim(&gSprites[spriteId], ANIM_STD_GO_WEST);
                    gSprites[spriteId].sSameDir = FALSE;
                }
            }
            gSprites[spriteId].sDelay = hikerMovementDelayTable[rval % ARRAY_COUNT(hikerMovementDelayTable)];
        }
    }
}

void BufferNextGroundSegment(void)
{
    u8 i, j, k;
    u8 offset;

    for (i = 0, k = 0, offset = 0x24 * (sCableCar->groundTilemapOffset + 2); i < 3; i++)
    {
        for (j = 0; j < ARRAY_COUNT(sCableCar->groundTileBuffer[0]); j++)
        {
            sCableCar->groundTileBuffer[i][j] = sCableCar->groundTilemap[offset++];
            sCableCar->groundTileBuffer[i + 3][j] = sCableCar->groundTilemap[k];
            sCableCar->groundTileBuffer[i + 6][j] = (sCableCar->groundTilemap + 0x24)[k];
            k++;
        }
    }

    sCableCar->groundTilemapOffset = (sCableCar->groundTilemapOffset + 1) % 3;
}

void DrawNextGroundSegmentGoingUp(void)
{
    u8 i = 0;

    sCableCar->groundXOffset = sCableCar->groundYOffset = 0;
    sCableCar->groundXBase = sCableCar->bg0HorizontalOffset;
    sCableCar->groundYBase = sCableCar->bg0VerticalOffset;
    sCableCar->groundSegmentXStart = (sCableCar->groundSegmentXStart + 30) % 32;
    sCableCar->groundTileIdx -= 2;
    sGroundSegmentY_Up = (sCableCar->groundSegmentYStart + 23) % 32;

    // Draw next segment
    for (i = 0; i < ARRAY_COUNT(sCableCar->groundTileBuffer); i++)
    {
        sGroundX_Up = sCableCar->groundSegmentXStart;
        sGroundY_Up = (sGroundSegmentY_Up + i) % 32;
        FillBgTilemapBufferRect(0, sCableCar->groundTileBuffer[i][sCableCar->groundTileIdx], sGroundX_Up, sGroundY_Up, 1, 1, 17);
        sGroundX_Up = (sGroundX_Up + 1) % 32;
        FillBgTilemapBufferRect(0, sCableCar->groundTileBuffer[i][sCableCar->groundTileIdx + 1], sGroundX_Up, sGroundY_Up, 1, 1, 17);
    }

    // Erase old segment
    sGroundX_Up = (sCableCar->groundSegmentXStart + 30) % 32;
    FillBgTilemapBufferRect(0, 0, sGroundX_Up, 0, 2, 32, 17);
    if (sCableCar->groundTileIdx == 0)
    {
        sCableCar->groundSegmentYStart = (sCableCar->groundSegmentYStart + 29) % 32;
        sCableCar->groundTileIdx = 12;
        BufferNextGroundSegment();
        sGroundX_Up = (sCableCar->groundSegmentYStart + 1) % 32;
        FillBgTilemapBufferRect(0, 0, 0, sGroundX_Up, 32, 9, 17);
    }
}

void DrawNextGroundSegmentGoingDown(void)
{
    u8 i = 0;

    sCableCar->groundXOffset = sCableCar->groundYOffset = 0;
    sCableCar->groundXBase = sCableCar->bg0HorizontalOffset;
    sCableCar->groundYBase = sCableCar->bg0VerticalOffset;
    sCableCar->groundSegmentXStart = (sCableCar->groundSegmentXStart + 2) % 32;
    sCableCar->groundTileIdx += 2;
    sGroundSegmentY_Down = sCableCar->groundSegmentYStart;

    // Draw next segment
    for (i = 0; i < ARRAY_COUNT(sCableCar->groundTileBuffer); i++)
    {
        sGroundX_Down = sCableCar->groundSegmentXStart;
        sGroundY_Down = (sGroundSegmentY_Down + i) % 32;
        FillBgTilemapBufferRect(0, sCableCar->groundTileBuffer[i][sCableCar->groundTileIdx], sGroundX_Down, sGroundY_Down, 1, 1, 17);
        sGroundX_Down = (sGroundX_Down + 1) % 32;
        FillBgTilemapBufferRect(0, sCableCar->groundTileBuffer[i][sCableCar->groundTileIdx + 1], sGroundX_Down, sGroundY_Down, 1, 1, 17);
    }

    // Erase old segment
    sGroundY_Down = (sCableCar->groundSegmentYStart + 23) % 32;
    FillBgTilemapBufferRect(0, 0, sCableCar->groundSegmentXStart, sGroundY_Down, 2, 9, 17);
    if (sCableCar->groundTileIdx == 10)
    {
        sCableCar->groundSegmentYStart = (sCableCar->groundSegmentYStart + 3) % 32;
        sCableCar->groundTileIdx = -2;
        BufferNextGroundSegment();
    }
}
